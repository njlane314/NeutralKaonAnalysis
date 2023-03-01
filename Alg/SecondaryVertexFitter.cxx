#ifndef _SecondaryVertexFitter_cxx_
#define _SecondaryVertexFitter_cxx_

#include "SecondaryVertexFitter.h"

///////////////////////////////////////////////////////////////////////////////////////////////

SecondaryVertexFitter::SecondaryVertexFitter(){

   fPull = 5.0;

}

///////////////////////////////////////////////////////////////////////////////////////////////

SecondaryVertexFitter::SecondaryVertexFitter(double Pull){

   fPull = Pull;

}

///////////////////////////////////////////////////////////////////////////////////////////////

void SecondaryVertexFitter::SetPull(double Pull){

   fPull = Pull;

}

///////////////////////////////////////////////////////////////////////////////////////////////

SecondaryVertex SecondaryVertexFitter::MakeVertex(RecoParticle P1,RecoParticle P2,bool useclosestapproach){

   // Make an initial guess, point of closest approach of tracks
   TVector3 V_in = PointOfClosestApproach(P1,P2);

   SecondaryVertex V;
   V.Vertex = V_in;

   TVector3 ProtonDirection(P1.TrackDirectionX,P1.TrackDirectionY,P1.TrackDirectionZ);
   TVector3 PionDirection(P2.TrackDirectionX,P2.TrackDirectionY,P2.TrackDirectionZ);
   TVector3 ProtonStart(P1.TrackStartX,P1.TrackStartY,P1.TrackStartZ);
   TVector3 PionStart(P2.TrackStartX,P2.TrackStartY,P2.TrackStartZ);

   double ProtonLength = P1.TrackLength;
   double PionLength = P2.TrackLength;

   V.ProtonStart = ProtonStart;
   V.PionStart = PionStart;
   V.ProtonDirection = ProtonDirection;
   V.PionDirection = PionDirection;
   V.ProtonLength = ProtonLength;
   V.PionLength = PionLength;

   //generate an initial opening angle guess
   double start_opening_angle = ProtonDirection.Angle(PionDirection);

   //normal to decay plane = ProtonDir x PionDir
   TVector3 Norm = ProtonDirection.Cross(PionDirection); 
   Norm *= 1.0/Norm.Mag();

   V.Normal = Norm;

   ROOT::Math::Functor min = ROOT::Math::Functor( [&] (const double *coeff ){

         TVector3 FitVertex(coeff[2],coeff[3],coeff[4]);

         //direction of proton track in fitted V
         TVector3 FitProtonDir = ProtonDirection;
         TVector3 FitPionDir = ProtonDirection;

         //rotate by theta
         FitProtonDir.Rotate(coeff[0],Norm);
         FitPionDir.Rotate(coeff[0]+coeff[1],Norm);

         double FitVal = DoFit(P1,P2,FitVertex,FitProtonDir,FitPionDir);

         return FitVal;

         } , 5);

   std::unique_ptr< ROOT::Math::Minimizer > fMinimizer = std::unique_ptr<ROOT::Math::Minimizer>
      ( ROOT::Math::Factory::CreateMinimizer( "Minuit2", "Migrad" ) );

   fMinimizer->SetMaxFunctionCalls(100);
   fMinimizer->SetTolerance( 0.1 );

   fMinimizer->SetVariable(0,"theta",0.0,5);
   fMinimizer->SetVariable(1,"opening_angle",start_opening_angle,5);
   fMinimizer->SetVariable(2,"vx",V.Vertex.X(),0.1);
   fMinimizer->SetVariable(3,"vy",V.Vertex.Y(),0.1);
   fMinimizer->SetVariable(4,"vz",V.Vertex.Z(),0.1);

   fMinimizer->SetFunction(min);
   if(!useclosestapproach) V.fitStatus = fMinimizer->Minimize();

   //get final proton/pion direction vectors
   double theta = fMinimizer->X()[0];
   double opening_angle = fMinimizer->X()[1];

   V.ProtonDirection = ProtonDirection;
   V.ProtonDirection.Rotate( theta,Norm );
   V.PionDirection = ProtonDirection;
   V.PionDirection.Rotate( theta+opening_angle,Norm );

   if(V.fitStatus == 0)  V.Vertex = TVector3(fMinimizer->X()[2],fMinimizer->X()[3],fMinimizer->X()[4]);

   //calculate the distance along the proton track and pion track of the vertex
   double P_ClosestApproach_Proton = ((ProtonStart-V.Vertex)*ProtonDirection);
   double P_ClosestApproach_Pion = ((PionStart-V.Vertex)*PionDirection);

   if(abs(P_ClosestApproach_Proton) > abs(P_ClosestApproach_Pion)) V.CrossingDist = P_ClosestApproach_Proton;
   else V.CrossingDist = P_ClosestApproach_Pion;

   return V;

}


///////////////////////////////////////////////////////////////////////////////////////////////

double SecondaryVertexFitter::DoFit(RecoParticle P1, RecoParticle P2, TVector3 Vertex, TVector3 FitDir1, TVector3 FitDir2){

   //std::cout << "Calculating fit function" << std::endl;

   int npts = 50;
   double StepSize = 0.2; // Step size in cm
   double Res = 0.5; // Assumed position resolution

   TVector3 TrackDir1(P1.TrackDirectionX,P1.TrackDirectionY,P1.TrackDirectionZ);
   TVector3 TrackDir2(P2.TrackDirectionX,P2.TrackDirectionY,P2.TrackDirectionZ);

   TVector3 TrackStart1(P1.TrackStartX,P1.TrackStartY,P1.TrackStartZ);
   TVector3 TrackStart2(P2.TrackStartX,P2.TrackStartY,P2.TrackStartZ);

   double TrackLength1 = P1.TrackLength;
   double TrackLength2 = P2.TrackLength;

   double total_d_1 = 0.0;
   double total_d_2 = 0.0;

   //generate 10 points along the length of the track
   for(int i=0;i<=npts;i++){

      TVector3 TestPoint1 = TrackStart1 + (1.0/npts)*i*TrackLength1*TrackDir1;
      TVector3 TestPoint2 = TrackStart2 + (1.0/npts)*i*TrackLength2*TrackDir2;

      // use formulae from https://en.wikipedia.org/wiki/Distance_from_a_point_to_a_line
      // Notation:
      // a = Candidate vertex
      // p = test point
      // n = fit direction

      //Point of closest approach
      TVector3 ClosestApproach1 = ((Vertex-TestPoint1) - ( (Vertex-TestPoint1)*FitDir1 )*FitDir1);

      double delta_1 = (-1)*(Vertex-TestPoint1)*FitDir1;
      double delta_2 = (-1)*(Vertex-TestPoint2)*FitDir2;

      //calculate distance to corresponding arms of V
      double d_1 = ((Vertex-TestPoint1) - ( (Vertex-TestPoint1)*FitDir1 )*FitDir1).Mag();
      double d_2 = ((Vertex-TestPoint2) - ( (Vertex-TestPoint2)*FitDir2 )*FitDir2).Mag();

      if(delta_1 < 0){ d_1 = (Vertex-TestPoint1).Mag()*fPull; /*std::cout << "d_1=" <<  d_1 << std::endl;*/ }
      if(delta_2 < 0){ d_2 = (Vertex-TestPoint2).Mag()*fPull; /*std::cout << "d_2=" <<  d_2 << std::endl;*/ }

      total_d_1 += d_1*d_1;
      total_d_2 += d_2*d_2;

   }

   return total_d_1 + total_d_2;

}

///////////////////////////////////////////////////////////////////////////////////////////////

TVector3 SecondaryVertexFitter::PointOfClosestApproach(RecoParticle P1,RecoParticle P2){

   TVector3 Vertex;

   double walk_step = 0.01;

   //get start points
   TVector3 TrackStart1(P1.TrackStartX,P1.TrackStartY,P1.TrackStartZ);
   TVector3 TrackStart2(P2.TrackStartX,P2.TrackStartY,P2.TrackStartZ);

   //get track directions
   TVector3 TrackDirection1(P1.TrackDirectionX,P1.TrackDirectionY,P1.TrackDirectionZ);
   TVector3 TrackDirection2(P2.TrackDirectionX,P2.TrackDirectionY,P2.TrackDirectionZ);

   TrackDirection1 *= walk_step;
   TrackDirection2 *= walk_step;

   double min_sep = 10000;

   for(int i1=0;i1<200;i1++){
      for(int i2=0;i2<200;i2++){

         TVector3 Pos1 = TrackStart1 - TrackDirection1*i1;
         TVector3 Pos2 = TrackStart2 - TrackDirection2*i2;
         double Sep = (Pos1-Pos2).Mag();

         if(Sep < min_sep){
            Vertex = (Pos1 + Pos2)*0.5;
            min_sep = Sep;

         }

      }
   }

   return Vertex;

}

///////////////////////////////////////////////////////////////////////////////////////////////

#endif
