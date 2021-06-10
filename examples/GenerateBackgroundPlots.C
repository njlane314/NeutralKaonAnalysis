R__LOAD_LIBRARY($HYP_TOP/lib/libAlg.so)
R__LOAD_LIBRARY($HYP_TOP/lib/libCore.so)

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"

   void GenerateBackgroundPlots(){

      BuildTunes();

      double POT = 1e21; // POT to scale samples to

      SelectionManager M(P_FHC_v0);
      M.SetPOT(POT);
      M.ImportSelectorBDTWeights();
      M.ImportAnalysisBDTWeights();

      EventAssembler E;

      std::vector<std::string> SampleNames = { "NuWro Overlay Backgroud" , "NuWro Overlay Hyperon" , "GENIE Dirt" , "EXT" };
      std::vector<std::string> SampleTypes = { "Background" , "Hyperon" , "Dirt" , "EXT" };
      std::vector<std::string> SampleFiles = { "analysisOutputFHC_Overlay_NuWro_Background_kmistry_numi_run1_fhc_nuwro.root" , "analysisOutputFHC_Overlay_NuWro_Hyperon_prod_numi_uboone_overlay_fhc_mcc9_run1_v51_nuwro_hyperon_nuwro_reco2_reco2.root" , "analysisOutputFHC_Overlay_GENIE_Dirt_prodgenie_numi_uboone_overlay_dirt_fhc_mcc9_run1_v28_sample0.root" , "analysisOutput_EXT_cthorpe_numi_uboone_run1_beamoff_offset1_mcc9_reco2_v08_00_00_28_sample0_sample1_all.root" };


/*
std::vector<std::string> SampleNames = { "NuWro Overlay Hyperon" };
std::vector<std::string> SampleTypes = { "Hyperon" };
std::vector<std::string> SampleFiles = { "analysisOutputFHC_Overlay_NuWro_Hyperon_prod_numi_uboone_overlay_fhc_mcc9_run1_v51_nuwro_hyperon_nuwro_reco2_reco2.root"};
*/

      double EXT_Scale = 9.5961;

     M.SetupHistograms(20,-0.5,0.5,";BDT Response;Events");

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
            if(!M.AnalysisBDTCut(e)) continue; 

           M.FillHistograms(e,e.AnalysisBDTScore);                

         }

         E.Close();

      }

 
  Cut C_FV = M.GetCut("FV");
  Cut C_Tracks = M.GetCut("Tracks");
  Cut C_Showers = M.GetCut("Showers");
  Cut C_MuonID = M.GetCut("MuonID");
  Cut C_DecaySelector = M.GetCut("DecaySelector");
  Cut C_DecayAnalyser = M.GetCut("DecayAnalysis");

   std::cout << C_FV.SignalEfficiency() << std::endl;
   std::cout << C_Tracks.SignalEfficiency() << std::endl;
   std::cout << C_Showers.SignalEfficiency() << std::endl;
   std::cout << C_MuonID.SignalEfficiency() << std::endl;
   std::cout << C_DecaySelector.SignalEfficiency() << std::endl;
   std::cout << C_DecayAnalyser.SignalEfficiency() << std::endl;

 M.DrawHistograms();

   }
