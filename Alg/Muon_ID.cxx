#ifndef _Muon_ID_cxx_
#define _Muon_ID_cxx_

#include "Muon_ID.h"

///////////////////////////////////////////////////////////////////////////////////////////////

MuonID::MuonID(){

   fPIDCut = 0.0;
   fMinLength = 0.0;
   fMaxSeparation = 1000;

}

///////////////////////////////////////////////////////////////////////////////////////////////

MuonID::MuonID(double PIDCut,double MinLength,double MaxSeparation){

   fPIDCut = PIDCut;
   fMinLength = MinLength;
   fMaxSeparation = MaxSeparation;

}

///////////////////////////////////////////////////////////////////////////////////////////////

void MuonID::SetTune(double PIDCut,double MinLength,double MaxSeparation){

   fPIDCut = PIDCut;
   fMinLength = MinLength;
   fMaxSeparation = MaxSeparation;

}

///////////////////////////////////////////////////////////////////////////////////////////////

int MuonID::SelectCandidate(std::vector<RecoParticle> P_v){

   int i_longest=-1;
   int length=-1;

   for(size_t i=0;i<P_v.size();i++){

      // If particle fails PID, length or vertex proximity requirement, ignore
      if(P_v.at(i).Track_LLR_PID < fPIDCut || P_v.at(i).TrackLength < fMinLength || P_v.at(i).Displacement > fMaxSeparation) continue;

      if(P_v.at(i).TrackLength > length){
         i_longest = i;
         length = P_v.at(i).TrackLength;
      }
   }

   // Return -1 if no candidate was found
   return i_longest;
}

///////////////////////////////////////////////////////////////////////////////////////////////

#endif

