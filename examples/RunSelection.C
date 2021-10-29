R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so)

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

   void RunSelection(){

      double POT = 1.0e21; // POT to scale samples to

      BuildTunes();
      ImportSamples(sNuWroFullFHC);

      SelectionParameters P = P_FHC_Tune_325;

      std::string label = "GENIE_FHC";

      // Setup selection manager. Set POT to scale sample to, import the BDT weights
      EventAssembler E;
      SelectionManager M(P);
      M.SetPOT(POT);
      M.ImportSelectorBDTWeights(P.p_SelectorBDT_WeightsDir);
      M.ImportAnalysisBDTWeights(P.p_AnalysisBDT_WeightsDir);

      // Sample Loop
      for(size_t i_s=0;i_s<SampleNames.size();i_s++){

         E.SetFile(SampleFiles.at(i_s));
         if(SampleTypes.at(i_s) != "EXT" && SampleTypes.at(i_s) != "Data") M.AddSample(SampleNames.at(i_s),SampleTypes.at(i_s),E.GetPOT(),EventLists.at(i_s));
         else if(SampleTypes.at(i_s) == "Data") M.AddSample(SampleNames.at(i_s),SampleTypes.at(i_s),Data_POT,EventLists.at(i_s));
         else if(SampleTypes.at(i_s) == "EXT") M.AddSample(SampleNames.at(i_s),SampleTypes.at(i_s),EXT_POT,EventLists.at(i_s));

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
            if(!M.EventListCut(e)) continue;

         }

         E.Close();

      }


      Cut C_DecayAnalyser = M.GetCut("Connectedness");

         std::cout << "Selected Signal = " << C_DecayAnalyser.PredictedSignal() << " +/- " << C_DecayAnalyser.PredictedSignalError() << "  Selected Background = " <<  C_DecayAnalyser.PredictedBackground() << " +/- " << C_DecayAnalyser.PredictedBackgroundError() << std::endl;

   }
