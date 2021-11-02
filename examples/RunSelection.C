R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so)
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so)

#include "SelectionManager.h"
#include "EventAssembler2.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

   void RunSelection(){

      double POT = 1.0e21; // POT to scale samples to

      BuildTunes();

      SelectionParameters P = P_FHC_Tune_325;

      std::string label = "GENIE_FHC";

      SampleNames.push_back("GENIE Background");
      SampleTypes.push_back("Background");
      SampleFiles.push_back("HyperonTrees_Sys.root");
     
      // Setup selection manager. Set POT to scale sample to, import the BDT weights
      EventAssembler2 E;
      SelectionManager M(P);
      M.SetPOT(POT);
      M.ImportSelectorBDTWeights(P.p_SelectorBDT_WeightsDir);
      M.ImportAnalysisBDTWeights(P.p_AnalysisBDT_WeightsDir);
   
      std::cout << "Setup Done" << std::endl;
      GenG4WeightHandler G;  

      // Sample Loop
      for(size_t i_s=0;i_s<SampleNames.size();i_s++){

         E.SetFile(SampleFiles.at(i_s));
         if(SampleTypes.at(i_s) != "EXT" && SampleTypes.at(i_s) != "Data") M.AddSample(SampleNames.at(i_s),SampleTypes.at(i_s),E.GetPOT());
         else if(SampleTypes.at(i_s) == "Data") M.AddSample(SampleNames.at(i_s),SampleTypes.at(i_s),Data_POT);
         else if(SampleTypes.at(i_s) == "EXT") M.AddSample(SampleNames.at(i_s),SampleTypes.at(i_s),EXT_POT);

         // Event Loop
         for(int i=0;i<E.GetNEvents();i++){

            Event2 e = E.GetEvent(i);

            M.SetSignal(e);                
            M.AddEvent(e);       

            if(!M.FiducialVolumeCut(e)) continue;
            if(!M.TrackCut(e)) continue;
            if(!M.ShowerCut(e)) continue;
            if(!M.ChooseMuonCandidate(e)) continue;
            if(!M.ChooseProtonPionCandidates(e)) continue;
            //if(!M.AnalysisBDTCut(e)) continue;       
            //if(!M.EventListCut(e)) continue;

         }

         E.Close();

      }


      Cut C_DecayAnalyser = M.GetCut("FV");

         std::cout << "Selected Signal = " << C_DecayAnalyser.PredictedSignal() << " +/- " << C_DecayAnalyser.PredictedSignalError() << "  Selected Background = " <<  C_DecayAnalyser.PredictedBackground() << " +/- " << C_DecayAnalyser.PredictedBackgroundError() << std::endl;

   }
