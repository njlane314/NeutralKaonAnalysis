R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so)
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so)

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

   void RunSelection(){

      double POT = 1.0e21; // POT to scale samples to

      BuildTunes();

      SelectionParameters P = P_FHC_Tune_325;

      std::string label = "test";

      SampleNames.push_back("GENIE Dirt");
      SampleTypes.push_back("Dirt");
      SampleFiles.push_back("analysisOutputFHC_Overlay_GENIE_Dirt_CV_prodgenie_numi_uboone_overlay_dirt_fhc_mcc9_run1_v28_sample1.root");

      // Setup selection manager. Set POT to scale sample to, import the BDT weights
      EventAssembler E;
      SelectionManager M(P);
      M.SetPOT(POT);
      M.ImportSelectorBDTWeights(P.p_SelectorBDT_WeightsDir);
      M.ImportAnalysisBDTWeights(P.p_AnalysisBDT_WeightsDir);

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
            if(!M.ChooseProtonPionCandidates(e)) continue;
            if(!M.AnalysisBDTCut(e)) continue;       
            if(!M.ConnectednessTest(e)) continue;

         }

         E.Close();

      }


      Cut C_CT = M.GetCut("Connectedness");

         std::cout << "Selected Signal = " << C_CT.PredictedSignal() << " +/- " << C_CT.PredictedSignalError() << "  Selected Background = " <<  C_CT.PredictedBackground() << " +/- " << C_CT.PredictedBackgroundError() << std::endl;

   }
