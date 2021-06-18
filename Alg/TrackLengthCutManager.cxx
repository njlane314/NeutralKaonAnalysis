#ifndef _TrackLengthCutManager_cxx_
#define _TrackLengthCutManager_cxx_

#include "TrackLengthCutManager.h"

TrackLengthCutManager::TrackLengthCutManager(){

   fSecondaryCut=0.0;
   fTertiaryCut=0.0;

}

TrackLengthCutManager::TrackLengthCutManager(double SecondaryCut,double TertiaryCut){

fSecondaryCut=SecondaryCut;
fTertiaryCut=TertiaryCut;

}

void TrackLengthCutManager::SetTune(double SecondaryCut,double TertiaryCut){

fSecondaryCut=SecondaryCut;
fTertiaryCut=TertiaryCut;

}

bool TrackLengthCutManager::ApplyCut(std::vector<RecoParticle> P_v){

if(P_v.size() < 2) return false;

// Sort the tracks into descending order of length
SortTracks(P_v);

//for(size_t i=0;i<P_v.size();i++) std::cout << P_v.at(i).TrackLength << "  ";

//std::cout << std::endl;

return P_v.at(P_v.size()-1).TrackLength < fSecondaryCut && P_v.at(P_v.size()-2).TrackLength < fTertiaryCut;


return false;

}
      
std::vector<RecoParticle> TrackLengthCutManager::SortTracks(std::vector<RecoParticle> &P_v){

   int swaps_this_pass = 1;

   while(swaps_this_pass > 0){

      swaps_this_pass = 0;

      std::vector<RecoParticle> P_v_tmp = P_v;

      for(size_t i=1;i<P_v.size();i++){

         // if track is longer than the previous one, swap them
         if(P_v.at(i).TrackLength > P_v.at(i-1).TrackLength){
            P_v_tmp[i-1] = P_v.at(i);
            P_v_tmp[i] = P_v.at(i-1);
            swaps_this_pass++;
         }

      }

      P_v = P_v_tmp;

   }


   return P_v;

}

#endif
