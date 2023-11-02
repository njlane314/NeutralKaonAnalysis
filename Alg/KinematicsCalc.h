#ifndef _KinematicsCalc_h_
#define _KinematicsCalc_h_

#include "RecoParticle.h"
#include "TLorentzVector.h"

///////////////////////////////////////////////////////////////////////////////////////////////

inline double PionMomentum(double TrackLength){ return 0.25798 + 0.0024088*TrackLength - 0.18828*pow(TrackLength,-0.11687); }

///////////////////////////////////////////////////////////////////////////////////////////////

inline double ProtonMomentum(double TrackLength){ return 14.96 + 0.0043489*TrackLength - 14.688*pow(TrackLength,-0.0053518); }

///////////////////////////////////////////////////////////////////////////////////////////////

inline TLorentzVector ProtonPion4Momentum(RecoParticle Proton,RecoParticle Pion){

   double momentum_proton = Proton.ProtonMomentum;
   double momentum_pion = PionMomentum(Pion.TrackLength);

   double energy_proton = sqrt(momentum_proton*momentum_proton + 0.9383*0.9383);
   double energy_pion = sqrt(momentum_pion*momentum_pion + 0.1396*0.1396);

   TLorentzVector Proton4Momentum(Proton.TrackDirectionX*momentum_proton,Proton.TrackDirectionY*momentum_proton,Proton.TrackDirectionZ*momentum_proton,energy_proton);
   TLorentzVector Pion4Momentum(Pion.TrackDirectionX*momentum_pion,Pion.TrackDirectionY*momentum_pion,Pion.TrackDirectionZ*momentum_pion,energy_pion);

   return Proton4Momentum+Pion4Momentum;

}

///////////////////////////////////////////////////////////////////////////////////////////////

inline TLorentzVector KaonDecayPionPair4Momentum(RecoParticle PionPlus, RecoParticle PionMinus){
   
   double momentum_pionPlus = PionMomentum(PionPlus.TrackLength);
   double momentum_pionMinus = PionMomentum(PionMinus.TrackLength);

   double energy_pionPlus = sqrt(momentum_pionPlus*momentum_pionPlus + 0.1396*0.1396);
   double energy_pionMinus = sqrt(momentum_pionMinus*momentum_pionMinus + 0.1396*0.1396);

   TLorentzVector PionPlus4Momentum(PionPlus.TrackDirectionX*momentum_pionPlus, PionPlus.TrackDirectionY*momentum_pionPlus, PionPlus.TrackDirectionZ*momentum_pionPlus, energy_pionPlus);
   TLorentzVector PionMinus4Momentum(PionMinus.TrackDirectionX*momentum_pionMinus, PionMinus.TrackDirectionY*momentum_pionMinus, PionMinus.TrackDirectionZ*momentum_pionMinus, energy_pionMinus);

   return PionPlus4Momentum + PionMinus4Momentum;
}

///////////////////////////////////////////////////////////////////////////////////////////////

inline double KaonDecayPionPairInvariantMass(RecoParticle PionPlus, RecoParticle PionMinus){

   TLorentzVector P = KaonDecayPionPair4Momentum(PionPlus, PionMinus);

   return sqrt(P*P);
}

///////////////////////////////////////////////////////////////////////////////////////////////

inline double KaonDecayPionPairOpeningAngle(RecoParticle PionPlus, RecoParticle PionMinus){

   TVector3 PionPlusDir(PionPlus.TrackDirectionX, PionPlus.TrackDirectionY, PionPlus.TrackDirectionZ);
   TVector3 PionMinusDir(PionMinus.TrackDirectionX, PionMinus.TrackDirectionY, PionMinus.TrackDirectionZ);

   return (180/3.142)*PionPlusDir.Angle(PionMinusDir);
}

///////////////////////////////////////////////////////////////////////////////////////////////

inline double ProtonPionInvariantMass(RecoParticle Proton,RecoParticle Pion){

    TLorentzVector P = ProtonPion4Momentum(Proton,Pion); 

   return sqrt(P*P);

}

///////////////////////////////////////////////////////////////////////////////////////////////

inline double LambdaMomentum(RecoParticle Proton,RecoParticle Pion){

TLorentzVector P = ProtonPion4Momentum(Proton,Pion);

return sqrt(P.X()*P.X()+P.Y()*P.Y()+P.Z()*P.Z());

}

///////////////////////////////////////////////////////////////////////////////////////////////

inline double OpeningAngle(RecoParticle Proton,RecoParticle Pion){

   TVector3 ProtonDir(Proton.TrackDirectionX,Proton.TrackDirectionY,Proton.TrackDirectionZ);
   TVector3 PionDir(Pion.TrackDirectionX,Pion.TrackDirectionY,Pion.TrackDirectionZ);

   return (180/3.142)*ProtonDir.Angle(PionDir);
}

///////////////////////////////////////////////////////////////////////////////////////////////

#endif
