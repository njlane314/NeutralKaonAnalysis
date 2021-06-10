#ifndef _TrackLengthCutManager_h_
#define _TrackLengthCutManager_h_

#include "RecoParticle.h"
//#include <vector>

class TrackLengthCutManager {

   public:

      TrackLengthCutManager();
      TrackLengthCutManager(double SecondaryCut,double TertiaryCut);

      void SetTune(double SecondaryCut,double TertiaryCut);

      bool ApplyCut(std::vector<RecoParticle> P_v);

      std::vector<RecoParticle> SortTracks(std::vector<RecoParticle> &P_v);
      
   private:

      double fSecondaryCut;
      double fTertiaryCut;

};


#endif
