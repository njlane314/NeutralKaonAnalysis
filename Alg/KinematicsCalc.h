#ifndef _KinematicsCalc_h_
#define _KinematicsCalc_h_

#include "RecoParticle.h"
#include "TLorentzVector.h"

///////////////////////////////////////////////////////////////////////////////////////////////

inline double PionMomentum(double TrackLength){ return 0.25798 + 0.0024088*TrackLength - 0.18828*pow(TrackLength,-0.11687); }

///////////////////////////////////////////////////////////////////////////////////////////////

inline TLorentzVector PionPair4Momentum(RecoParticle PionPlus, RecoParticle PionMinus){
   
   double momentum_pionPlus = PionMomentum(PionPlus.TrackLength);
   double momentum_pionMinus = PionMomentum(PionMinus.TrackLength);

   double energy_pionPlus = sqrt(momentum_pionPlus*momentum_pionPlus + 0.1396*0.1396);
   double energy_pionMinus = sqrt(momentum_pionMinus*momentum_pionMinus + 0.1396*0.1396);

   TLorentzVector PionPlus4Momentum(PionPlus.TrackDirectionX*momentum_pionPlus, PionPlus.TrackDirectionY*momentum_pionPlus, PionPlus.TrackDirectionZ*momentum_pionPlus, energy_pionPlus);
   TLorentzVector PionMinus4Momentum(PionMinus.TrackDirectionX*momentum_pionMinus, PionMinus.TrackDirectionY*momentum_pionMinus, PionMinus.TrackDirectionZ*momentum_pionMinus, energy_pionMinus);

   return PionPlus4Momentum + PionMinus4Momentum;
}

///////////////////////////////////////////////////////////////////////////////////////////////

inline double PionPairInvariantMass(RecoParticle PionPlus, RecoParticle PionMinus){

   TLorentzVector P = PionPair4Momentum(PionPlus, PionMinus);

   return sqrt(P*P);
}

///////////////////////////////////////////////////////////////////////////////////////////////

inline double PionPairOpeningAngle(RecoParticle PionPlus, RecoParticle PionMinus){

   TVector3 PionPlusDir(PionPlus.TrackDirectionX, PionPlus.TrackDirectionY, PionPlus.TrackDirectionZ);
   TVector3 PionMinusDir(PionMinus.TrackDirectionX, PionMinus.TrackDirectionY, PionMinus.TrackDirectionZ);

   return (180/3.142)*PionPlusDir.Angle(PionMinusDir);
}

///////////////////////////////////////////////////////////////////////////////////////////////

inline double OpeningAngle(RecoParticle Proton,RecoParticle Pion){

   TVector3 ProtonDir(Proton.TrackDirectionX,Proton.TrackDirectionY,Proton.TrackDirectionZ);
   TVector3 PionDir(Pion.TrackDirectionX,Pion.TrackDirectionY,Pion.TrackDirectionZ);

   return (180/3.142)*ProtonDir.Angle(PionDir);
}

///////////////////////////////////////////////////////////////////////////////////////////////

#endif
