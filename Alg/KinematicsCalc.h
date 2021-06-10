#ifndef _KinematicsCalc_h_
#define _KinematicsCalc_h_

#include "RecoParticle.h"
#include "TLorentzVector.h"

///////////////////////////////////////////////////////////////////////////////////////////////

double PionMomentum(double TrackLength){ return 0.25798 + 0.0024088*TrackLength - 0.18828*pow(TrackLength,-0.11687); }

///////////////////////////////////////////////////////////////////////////////////////////////

double ProtonMomentum(double TrackLength){ return 14.96 + 0.0043489*TrackLength - 14.688*pow(TrackLength,-0.0053518); }


///////////////////////////////////////////////////////////////////////////////////////////////

TLorentzVector ProtonPion4Momentum(RecoParticle Proton,RecoParticle Pion){

   double momentum_proton = Proton.ProtonMomentum;
   double momentum_pion = PionMomentum(Pion.TrackLength);

   double energy_proton = sqrt(momentum_proton*momentum_proton + 0.9383*0.9383);
   double energy_pion = sqrt(momentum_pion*momentum_pion + 0.1396*0.1396);

   TLorentzVector Proton4Momentum(Proton.TrackDirectionX*momentum_proton,Proton.TrackDirectionY*momentum_proton,Proton.TrackDirectionZ*momentum_proton,energy_proton);
   TLorentzVector Pion4Momentum(Pion.TrackDirectionX*momentum_pion,Pion.TrackDirectionY*momentum_pion,Pion.TrackDirectionZ*momentum_pion,energy_pion);

   return Proton4Momentum+Pion4Momentum;

}

///////////////////////////////////////////////////////////////////////////////////////////////

double ProtonPionInvariantMass(RecoParticle Proton,RecoParticle Pion){

    TLorentzVector P = ProtonPion4Momentum(Proton,Pion); 

   return sqrt(P*P);

}

///////////////////////////////////////////////////////////////////////////////////////////////

#endif
