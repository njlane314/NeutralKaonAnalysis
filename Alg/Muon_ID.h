#ifndef _Muon_ID_h_
#define _Muon_ID_h_

#include "RecoParticle.h"

   class MuonID {

      public:

         MuonID();
         MuonID(double PIDCut,double MinLength,double MaxSeparation);

         bool SelectCandidate(std::vector<RecoParticle> P_v);

         void SetTune(double PIDCut,double MinLength,double MaxSeparation);

      private:

         // Minimum PID score for Muon Candidate
         double fPIDCut;
         // Minimum Length
         double fMinLength;
         // Maximum Separation from PV
         double fMaxSeparation;

   };


#endif

