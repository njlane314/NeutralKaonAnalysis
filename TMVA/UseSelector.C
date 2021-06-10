R__LOAD_LIBRARY($HYP_TOP/lib/libAlg.so)
R__LOAD_LIBRARY($HYP_TOP/lib/libCore.so)

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "SelectorBDTManager.h"
#include "Cut.h"
#include "SelectionParameters.h"


#include "Parameters.h"

   void UseSelector(){

      BuildTunes();

      double POT = 1e21; // POT to scale samples to

      SelectionManager M(P_FHC_v0);
      M.SetPOT(POT);
      EventAssembler E;

/*
      std::vector<std::string> SampleNames = { "NuWro Overlay Backgroud" , "NuWro Overlay Hyperon" , "GENIE Dirt" , "EXT" };
      std::vector<std::string> SampleTypes = { "Background" , "Hyperon" , "Dirt" , "EXT" };
      std::vector<std::string> SampleFiles = { "analysisOutputFHC_Overlay_NuWro_Background_kmistry_numi_run1_fhc_nuwro.root" , "analysisOutputFHC_Overlay_NuWro_Hyperon_prod_numi_uboone_overlay_fhc_mcc9_run1_v51_nuwro_hyperon_nuwro_reco2_reco2.root" , "analysisOutputFHC_Overlay_GENIE_Dirt_prodgenie_numi_uboone_overlay_dirt_fhc_mcc9_run1_v28_sample0.root" , "analysisOutput_EXT_cthorpe_numi_uboone_run1_beamoff_offset1_mcc9_reco2_v08_00_00_28_sample0_sample1_all.root" };
*/

std::vector<std::string> SampleNames = { "NuWro Overlay Hyperon" };
std::vector<std::string> SampleTypes = { "Hyperon" };
std::vector<std::string> SampleFiles = { "analysisOutputFHC_Overlay_NuWro_Hyperon_prod_numi_uboone_overlay_fhc_mcc9_run1_v51_nuwro_hyperon_nuwro_reco2_reco2.root"};


      double EXT_Scale = 9.5961;

     // Setup Selector BDT Manager Object
     SelectorBDTManager BDTManager("Test");
     BDTManager.SetupSelectorBDT();

      // Sample Loop
      for(size_t i_s=0;i_s<SampleNames.size();i_s++){

         E.SetFile(SampleFiles.at(i_s));
         M.AddSample(SampleNames.at(i_s),SampleTypes.at(i_s),E.GetPOT());

         // Event Loop
         for(int i=0;i<E.GetNEvents();i++){

            Event e = E.GetEvent(i);

            M.SetSignal(e);                
            M.AddEvent(e);

            if(!M.FiducialVolumeCut(e)) continue;
            if(!M.TrackCut(e)) continue;
            if(!M.ShowerCut(e)) continue;
            if(!M.ChooseMuonCandidate(e)) continue;

            BDTManager.NominateTracks(e);

         }

         E.Close();

      }

   }
