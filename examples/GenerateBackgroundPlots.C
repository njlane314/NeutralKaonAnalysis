R__LOAD_LIBRARY($HYP_TOP/lib/libAlg.so)
R__LOAD_LIBRARY($HYP_TOP/lib/libCore.so)

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

   void GenerateBackgroundPlots(){

      double POT = 1.0e21; // POT to scale samples to

      BuildTunes();
      ImportSamples(sNuWroFullFHC);

      SelectionParameters P = P_RHC_Tune_397;
      P.p_AnalysisBDT_Cut = -0.1;

      std::string label = "NuWro_FHC_Tune";

      // Setup selection manager. Set POT to scale sample to, import the BDT weights
      EventAssembler E;
      SelectionManager M(P);
      M.SetPOT(POT);

      M.SetupHistograms(50,0.0,300,";Muon Candidate Length (cm);Events");

      // Sample Loop
      for(size_t i_s=0;i_s<SampleNames.size();i_s++){

         E.SetFile(SampleFiles.at(i_s));
         if(SampleTypes.at(i_s) != "EXT" && SampleTypes.at(i_s) != "Data") M.AddSample(SampleNames.at(i_s),SampleTypes.at(i_s),E.GetPOT());
         else if(SampleTypes.at(i_s) == "Data") M.AddSample(SampleNames.at(i_s),SampleTypes.at(i_s),Data_POT);
         else if(SampleTypes.at(i_s) == "EXT") M.AddSample(SampleNames.at(i_s),SampleTypes.at(i_s),EXT_POT);

         // Event Loop
         for(int i=0;i<E.GetNEvents();i++){

            Event e = E.GetEvent(i);

            M.SetSignal(e);                
            M.AddEvent(e);

            if(!M.FiducialVolumeCut(e)) continue;
            if(!M.TrackCut(e)) continue;
            if(!M.ShowerCut(e)) continue;
            if(!M.ChooseMuonCandidate(e)) continue;

            M.FillHistograms(e,e.MuonCandidate.TrackLength);                

         }

         E.Close();

      }

      M.DrawHistograms(label);

   }
