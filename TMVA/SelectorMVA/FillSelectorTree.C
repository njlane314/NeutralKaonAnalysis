R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so)
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so)

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "SelectorBDTManager.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

   void FillSelectorTree(){

      BuildTunes();

      // POT to scale samples to
      double POT = 1.2e21; 

      // Set the parameters you want to use
      SelectionParameters P = P_FHC_Tune_325;

      SelectionManager M(P);
      M.SetPOT(POT);
      M.UseFluxWeight(false);
      M.UseGenWeight(false);
      EventAssembler E(false);

      SampleNames.push_back("GENIE kaon");
      SampleTypes.push_back("Kaon");
      SampleFiles.push_back("analysisOutputFHC_GENIE_NoCosmic_Kaon_prodgenie_k0s_events_numi_fhc_nocosmic_pt1.root");

      // Setup Selector BDT Manager Object
      SelectorBDTManager BDTManager("Train");

      //BDTManager.SetCuts(P.p_Proton_PID_Cut,P.p_Pion_PID_Cut,P.p_Separation_Cut);

      // Sample Loop
      for(size_t i_s=0;i_s<SampleNames.size();i_s++){
         
         E.SetFile(SampleFiles.at(i_s), SampleTypes.at(i_s));
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

            BDTManager.FillTree(e);

         }

         E.Close();

      }

   BDTManager.WriteTrainingTrees();

   }
