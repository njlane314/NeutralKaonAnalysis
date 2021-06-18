R__LOAD_LIBRARY($HYP_TOP/lib/libAlg.so)
R__LOAD_LIBRARY($HYP_TOP/lib/libCore.so)

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "AnalysisBDTManager.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"

   void FillAnalysisTree(std::string Mode){

      EventAssembler E;

      BuildTunes();

      // Set the parameters you want to use
      SelectionParameters P = P_FHC_Tune_249;

      double POT = 1e21; // POT to scale samples to

      SelectionManager M(P);
      M.SetPOT(POT);
      M.ImportSelectorBDTWeights(P.p_SelectorBDT_WeightsDir);

      std::vector<std::string> SampleNames,SampleTypes,SampleFiles;

      if(Mode == "Signal"){
         // Signal dataset
         SampleNames = { "NuWro NoCosmic Hyperon" };
         SampleTypes = { "Hyperon" };
         SampleFiles = { "analysisOutputFHC_NuWro_Lambda_NoCosmic_cthorpe_prod_numi_uboone_nocosmic_Lambda_nuwro_reco2_reco2.root"};
      }
      else if(Mode == "Background"){  
         // Background dataset
         SampleNames = { "NuWro Overlay Backgroud" , "NuWro Overlay Hyperon" , "GENIE Dirt" , "EXT" };
         SampleTypes = { "Background" , "Hyperon" , "Dirt" , "EXT" };
         SampleFiles = { "analysisOutputFHC_Overlay_NuWro_Background_kmistry_numi_run1_fhc_nuwro.root" , "analysisOutputFHC_Overlay_NuWro_Hyperon_prod_numi_uboone_overlay_fhc_mcc9_run1_v51_nuwro_hyperon_nuwro_reco2_reco2.root" , "analysisOutputFHC_Overlay_GENIE_Dirt_prodgenie_numi_uboone_overlay_dirt_fhc_mcc9_run1_v28_sample0.root" , "analysisOutput_EXT_cthorpe_numi_uboone_run1_beamoff_offset1_mcc9_reco2_v08_00_00_28_sample0_sample1_all.root" };
      }
      else { std::cout << "Select \"Signal\" or \"Background\" Modes" << std::endl; return; }

      double EXT_Scale = 9.5961;

      // Setup Selector BDT Manager Object
      AnalysisBDTManager BDTManager("Train");
      BDTManager.SetPull(P.p_VertexPull);      

      // Sample Loop
      for(size_t i_s=0;i_s<SampleNames.size();i_s++){

         E.SetFile(SampleFiles.at(i_s));
         if(SampleTypes.at(i_s) != "EXT") M.AddSample(SampleNames.at(i_s),SampleTypes.at(i_s),E.GetPOT());
         else if(SampleTypes.at(i_s) == "EXT") M.AddSample(SampleNames.at(i_s),SampleTypes.at(i_s),POT/EXT_Scale);

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

            BDTManager.FillTree(e);

         }

         E.Close();

      }

      BDTManager.WriteTrainingTrees();

    if(Mode == "Signal") gSystem->Exec("mv AnalysisMVA/Trees.root AnalysisMVA/Trees_Signal.root");
    else if(Mode == "Background") gSystem->Exec("mv AnalysisMVA/Trees.root AnalysisMVA/Trees_Background.root");


   }
