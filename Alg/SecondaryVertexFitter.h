#ifndef _SecondaryVertexFitter_h_
#define _SecondaryVertexFitter_h_

#include "TVector3.h"
#include "Math/Minimizer.h"
#include "Math/Functor.h"
#include "Math/Factory.h"
#include "RecoParticle.h"

// Struct to hold info about V shape formed by two tracks and a vertex

struct SecondaryVertex {
   
   TVector3 Vertex; // position of vertex   
   TVector3 Normal; //vector normal to plane  
   double Opening_Angle; //opening angle

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
      SecondaryVertex MakeVertex(RecoParticle P1,RecoParticle P2,bool useclosestapproach=false);
      void SetPull(double Pull);
      //Draw();
      
   private:

      double fPull;
      TVector3 PointOfClosestApproach(RecoParticle P1,RecoParticle P2);
      double DoFit(RecoParticle P1, RecoParticle P2, TVector3 Vertex, TVector3 FitDir1, TVector3 FitDir2);
     
};

#endif
