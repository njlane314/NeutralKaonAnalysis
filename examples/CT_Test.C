R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so)
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so)

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

#include "TGraphAsymmErrors.h"
#include "CTTest.h"

  // WILL NOT WORK with pre-october 2021 versions of ntuples

   void CT_Test(){

      // Diables TEfficiency warnings
      gErrorIgnoreLevel = kWarning;

      double POT = 1.0e21; // POT to scale samples to

      BuildTunes();
      //ImportSamples(sNuWroFullFHC);

      SampleNames.push_back("GENIE Background");
      SampleTypes.push_back("Background");
      SampleFiles.push_back("HyperonTrees_Sys.root");

      SelectionParameters P = P_FHC_Tune_325;

      std::string label = "test";

      // Setup selection manager. Set POT to scale sample to
      EventAssembler E;
      SelectionManager M(P);
      M.SetPOT(POT);
      M.ImportSelectorBDTWeights(P.p_SelectorBDT_WeightsDir);
      M.ImportAnalysisBDTWeights(P.p_AnalysisBDT_WeightsDir);

      CTTest test(0);

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



   }
