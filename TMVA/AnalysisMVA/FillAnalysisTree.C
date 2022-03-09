R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so)
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so)

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "AnalysisBDTManager.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Nov21.h"

   // Fills the trees for the analysis MVA training

   void FillAnalysisTree(std::string Mode){

      BuildTunes();

      // POT to scale samples to
      double POT = 1.0e21;

      // Set the parameters you want to use
      SelectionParameters P = P_FHC_Tune_325;

      SelectionManager M(P);
      M.SetPOT(POT);
      M.ImportSelectorBDTWeights(P.p_SelectorBDT_WeightsDir);

      EventAssembler E;


      if(Mode == "Signal"){
         ImportSamples(sNuWroNoCosmicFHC);
      }
      else if(Mode == "Background"){  
         ImportSamples(sGENIEFullFHC_Train);
      }
      else { std::cout << "Select \"Signal\" or \"Background\" Modes" << std::endl; return; }


      // Setup Selector BDT Manager Object
      AnalysisBDTManager BDTManager("Train");
      BDTManager.SetPull(P.p_VertexPull);      

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

           // if(!M.ConnectednessTest(e)) continue;

            //if(e.EventIsSignal) std::cout << e.GoodReco << std::endl;
            BDTManager.FillTree(e);

         }

         E.Close();

      }

      BDTManager.WriteTrainingTrees();

      if(Mode == "Signal") gSystem->Exec("mv AnalysisMVA/Trees.root AnalysisMVA/Trees_Signal.root");
      else if(Mode == "Background") gSystem->Exec("mv AnalysisMVA/Trees.root AnalysisMVA/Trees_Background.root");


   }
