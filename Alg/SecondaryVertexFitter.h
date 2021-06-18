#ifndef _SecondaryVertexFitter_h_
#define _SecondaryVertexFitter_h_

#include "TVector3.h"
#include "Math/Minimizer.h"
#include "Math/Functor.h"
#include "Math/Factory.h"

#include "RecoParticle.h"

// Struct to hold info about V shape formed by two tracks and a vertex

struct SecondaryVertex {

   // position of vertex
   TVector3 Vertex;

   //vector normal to plane
   TVector3 Normal;

   //opening angle
   double Opening_Angle;

   //final direction vectors of proton and pion
   TVector3 ProtonStart;
   TVector3 PionStart;
   TVector3 ProtonDirection;
   TVector3 PionDirection;

   double ProtonLength;
   double PionLength;

   double d_proton=0,d_pion=0;

   double CrossingDist=0;

   bool fitStatus;

};


class SecondaryVertexFitter {

   public:

      SecondaryVertexFitter();
      SecondaryVertexFitter(double Pull);

      SecondaryVertex MakeVertex(RecoParticle P1,RecoParticle P2);

      void SetPull(double Pull);

      //Draw();
      
   private:
      double fPull;
      TVector3 PointOfClosestApproach(RecoParticle P1,RecoParticle P2);
      double DoFit(RecoParticle P1, RecoParticle P2, TVector3 Vertex, TVector3 FitDir1, TVector3 FitDir2);
     

};































/*
//generate a TGraph2D from the vertex

TGraph2D * MakeGraph(Decay_V V){

TGraph2D *g;

//generate 100 points over 20cm
std::vector<Double_t> X;
std::vector<Double_t> Y;
std::vector<Double_t> Z;

for(int i=0;i<100;i++){
TVector3 Pos = V.Vertex + i*V.ProtonDirection*0.2;
X.push_back(Pos.X());
Y.push_back(Pos.Y());
Z.push_back(Pos.Z());

}

for(int i=0;i<100;i++){
TVector3 Pos = V.Vertex + i*V.PionDirection*0.2;
X.push_back(Pos.X());
Y.push_back(Pos.Y());
Z.push_back(Pos.Z());
}

g = new TGraph2D( X.size() , &(X[0]) , &(Y[0]) , &(Z[0]) );

return g;

}

//////////////////////////////////////////////////////////////////////////
// Function to minimize
//
// Inputs: 
// TrackStart1, TrackStart2 = start points of the two tracks
// TrackDir1, TrackDir2 = direction vectors of the two tracks
// Vertex = candidate decay vertex
// FirDir1, FirDir2 = Fitted directions of the two legs of the V,
// to be compared with track 1 and track 2
//////////////////////////////////////////////////////////////////////////

//double DoFit(TVector3 TrackStart1, TVector3 TrackDir1, TVector3 TrackStart2, TVector3 TrackDir2, double TrackLength1, double TrackLength2, TVector3 Vertex, TVector3 FitDir1, TVector3 FitDir2){

double DoFit(RecoParticle P1, RecoParticle P2, TVector3 Vertex, TVector3 FitDir1, TVector3 FitDir2){

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

if(delta_1 < 0){ d_1 = (Vertex-TestPoint1).Mag()*5; std::cout << "d_1=" <<  d_1 << std::endl; }
if(delta_2 < 0){ d_2 = (Vertex-TestPoint2).Mag()*5; std::cout << "d_2=" <<  d_2 << std::endl; }


total_d_1 += d_1*d_1;
total_d_2 += d_2*d_2;

}




return total_d_1 + total_d_2;





}
*/


//fit a V to a pair of tracks
/*
   Decay_V V_Fit(RecoParticle P1, RecoParticle P2){

//std::cout << "Starting Fit" << std::endl;

//first make a secondary vertex
Vertex_Data V = SecondaryVertex(P1,P2);

Decay_V Fitted_V;
Fitted_V.Vertex = V.Vertex;

TVector3 ProtonDirection(P1.TrackDirectionX,P1.TrackDirectionY,P1.TrackDirectionZ);
TVector3 PionDirection(P2.TrackDirectionX,P2.TrackDirectionY,P2.TrackDirectionZ);

TVector3 ProtonStart(P1.TrackStartX,P1.TrackStartY,P1.TrackStartZ);
TVector3 PionStart(P2.TrackStartX,P2.TrackStartY,P2.TrackStartZ);

double ProtonLength = P1.TrackLength;
double PionLength = P2.TrackLength;

//generate an initial opening angle guess
double start_opening_angle = ProtonDirection.Angle(PionDirection);

//normal to decay plane = ProtonDir x PionDir
TVector3 Norm = ProtonDirection.Cross(PionDirection); 
Norm *= 1.0/Norm.Mag();

Fitted_V.Normal = Norm;

ROOT::Math::Functor min = ROOT::Math::Functor( [&] (const double *coeff ){

TVector3 Vertex( coeff[2] , coeff[3] , coeff[4] );
//TVector3 Vertex = V.Vertex;

//direction of proton track in fitted V
TVector3 FitProtonDir = ProtonDirection;
TVector3 FitPionDir = ProtonDirection;

//rotate by theta
FitProtonDir.Rotate(coeff[0],Norm);
FitPionDir.Rotate(coeff[0]+coeff[1],Norm);


//      double FitVal = DoFit(ProtonStart,ProtonDirection,PionStart,PionDirection,ProtonLength,PionLength,Vertex,FitProtonDir,FitPionDir);
double FitVal = DoFit(P1,P2,Vertex,FitProtonDir,FitPionDir);

//std::cout << FitVal << std::endl;

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
Fitted_V.fitStatus = fMinimizer->Minimize();

//std::cout << fMinimizer->MinValue() << std::endl;

Fitted_V.d_proton = fMinimizer->MinValue()/2;
Fitted_V.d_pion = fMinimizer->MinValue()/2;

//get final proton/pion direction vectors
double theta = fMinimizer->X()[0];
double opening_angle = fMinimizer->X()[1];

Fitted_V.ProtonDirection = ProtonDirection;
Fitted_V.ProtonDirection.Rotate( theta,Norm );

Fitted_V.PionDirection = ProtonDirection;
Fitted_V.PionDirection.Rotate( theta+opening_angle,Norm );

Fitted_V.Vertex = TVector3(fMinimizer->X()[2],fMinimizer->X()[3],fMinimizer->X()[4]);

//calculate the distance along the proton track and pion track of the vertex

double P_ClosestApproach_Proton = ((ProtonStart-Fitted_V.Vertex)*ProtonDirection);
double P_ClosestApproach_Pion = ((PionStart-Fitted_V.Vertex)*PionDirection);

if(abs(P_ClosestApproach_Proton) > abs(P_ClosestApproach_Pion)) Fitted_V.CrossingDist = P_ClosestApproach_Proton;
else Fitted_V.CrossingDist = P_ClosestApproach_Pion;


// point of closest approach is ((a-p).n)n 
// a = start of track
// p = reco decay vertex
// n = direction of track

return Fitted_V;

}
*/
#endif
