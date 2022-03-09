R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so)
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so)

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "SampleSets_Example.h"
#include "Parameters.h"

#include <algorithm>

   // Check which runs/subruns are present in all the samples processed
   // Save in a text file for later use. Required for detector variations

   void MakeCommonRSList(){

      // Setup selection manager. Set POT to scale sample to
      EventAssembler E;
/*
      // CV
      SampleNames.push_back("CV");
      SampleFiles.push_back("run1_FHC/detvar/analysisOutputFHC_Overlay_GENIE_Neutron_Detvar_cthorpe_make_neutron_events_run1_detvar_CV_neutron_reco2_reco2.root"); 

      // LYDown
      SampleNames.push_back("LYDown");
      SampleFiles.push_back("run1_FHC/detvar/analysisOutputFHC_Overlay_GENIE_Neutron_Detvar_cthorpe_make_neutron_events_run1_detvar_LYDown_neutron_reco2_reco2.root"); 

      // LYRayleigh
      SampleNames.push_back("LYRayleigh");
      SampleFiles.push_back("run1_FHC/detvar/analysisOutputFHC_Overlay_GENIE_Neutron_Detvar_cthorpe_make_neutron_events_run1_detvar_LYRayleigh_neutron_reco2_reco2.root"); 

      // LYAttenuation
      SampleNames.push_back("LYAttenuation");
      SampleFiles.push_back("run1_FHC/detvar/analysisOutputFHC_Overlay_GENIE_Neutron_Detvar_cthorpe_make_neutron_events_run1_detvar_LYAttenuation_neutron_reco2_reco2.root"); 

      // SCE
      SampleNames.push_back("SCE");
      SampleFiles.push_back("run1_FHC/detvar/analysisOutputFHC_Overlay_GENIE_Neutron_Detvar_cthorpe_make_neutron_events_run1_detvar_SCE_neutron_reco2_reco2.root"); 

      // Recomb2
      SampleNames.push_back("Recomb2");
      SampleFiles.push_back("run1_FHC/detvar/analysisOutputFHC_Overlay_GENIE_Neutron_Detvar_cthorpe_make_neutron_events_run1_detvar_Recomb2_neutron_reco2_reco2.root"); 

      // WireModX
      SampleNames.push_back("WireModX");
      SampleFiles.push_back("run1_FHC/detvar/analysisOutputFHC_Overlay_GENIE_Neutron_Detvar_cthorpe_make_neutron_events_run1_detvar_WireModX_neutron_reco2_reco2.root"); 

      // WireModYZ
      SampleNames.push_back("WireModYZ");
      SampleFiles.push_back("run1_FHC/detvar/analysisOutputFHC_Overlay_GENIE_Neutron_Detvar_cthorpe_make_neutron_events_run1_detvar_WireModYZ_neutron_reco2_reco2.root"); 

      // WireModThetaXZ
      SampleNames.push_back("WireModThetaXZ");
      SampleFiles.push_back("run1_FHC/detvar/analysisOutputFHC_Overlay_GENIE_Neutron_Detvar_cthorpe_make_neutron_events_run1_detvar_WireModThetaXZ_neutron_reco2_reco2.root"); 

      // WireModThetaYZ
      SampleNames.push_back("WireModThetaYZ");
      SampleFiles.push_back("run1_FHC/detvar/analysisOutputFHC_Overlay_GENIE_Neutron_Detvar_cthorpe_make_neutron_events_run1_detvar_WireModThetaYZ_neutron_reco2_reco2.root"); 
*/

/*
      // CV
      SampleNames.push_back("CV");
      SampleFiles.push_back("run1_FHC/detvar/analysisOutputFHC_Overlay_GENIE_Hyperon_Detvar_cthorpe_make_hyperon_events_run1_detvar_CV_hyperon_reco2_reco2.root"); 

      // LYDown
      SampleNames.push_back("LYDown");
      SampleFiles.push_back("run1_FHC/detvar/analysisOutputFHC_Overlay_GENIE_Hyperon_Detvar_cthorpe_make_hyperon_events_run1_detvar_LYDown_hyperon_reco2_reco2.root"); 

      // LYRayleigh
      SampleNames.push_back("LYRayleigh");
      SampleFiles.push_back("run1_FHC/detvar/analysisOutputFHC_Overlay_GENIE_Hyperon_Detvar_cthorpe_make_hyperon_events_run1_detvar_LYRayleigh_hyperon_reco2_reco2.root"); 

      // LYAttenuation
      SampleNames.push_back("LYAttenuation");
      SampleFiles.push_back("run1_FHC/detvar/analysisOutputFHC_Overlay_GENIE_Hyperon_Detvar_cthorpe_make_hyperon_events_run1_detvar_LYAttenuation_hyperon_reco2_reco2.root"); 

      // SCE
      SampleNames.push_back("SCE");
      SampleFiles.push_back("run1_FHC/detvar/analysisOutputFHC_Overlay_GENIE_Hyperon_Detvar_cthorpe_make_hyperon_events_run1_detvar_SCE_hyperon_reco2_reco2.root"); 

      // Recomb2
      SampleNames.push_back("Recomb2");
      SampleFiles.push_back("run1_FHC/detvar/analysisOutputFHC_Overlay_GENIE_Hyperon_Detvar_cthorpe_make_hyperon_events_run1_detvar_Recomb2_hyperon_reco2_reco2.root"); 

      // WireModX
      SampleNames.push_back("WireModX");
      SampleFiles.push_back("run1_FHC/detvar/analysisOutputFHC_Overlay_GENIE_Hyperon_Detvar_cthorpe_make_hyperon_events_run1_detvar_WireModX_hyperon_reco2_reco2.root"); 

      // WireModYZ
      SampleNames.push_back("WireModYZ");
      SampleFiles.push_back("run1_FHC/detvar/analysisOutputFHC_Overlay_GENIE_Hyperon_Detvar_cthorpe_make_hyperon_events_run1_detvar_WireModYZ_hyperon_reco2_reco2.root"); 

      // WireModThetaXZ
      SampleNames.push_back("WireModThetaXZ");
      SampleFiles.push_back("run1_FHC/detvar/analysisOutputFHC_Overlay_GENIE_Hyperon_Detvar_cthorpe_make_hyperon_events_run1_detvar_WireModThetaXZ_hyperon_reco2_reco2.root"); 

      // WireModThetaYZ
      SampleNames.push_back("WireModThetaYZ");
      SampleFiles.push_back("run1_FHC/detvar/analysisOutputFHC_Overlay_GENIE_Hyperon_Detvar_cthorpe_make_hyperon_events_run1_detvar_WireModThetaYZ_hyperon_reco2_reco2.root"); 
*/


      SampleNames.push_back("GENIE BG CV");
      SampleTypes.push_back("Background");
      SampleFiles.push_back("run1_FHC/detvar/analysisOutputFHC_Overlay_GENIE_Background_Detvar_prodgenie_numi_nu_overlay_v08_00_00_53_CV_300k_reco2_run1_reco2.root");

      SampleNames.push_back("GENIE BG LYDown");
      SampleTypes.push_back("Background");
      SampleFiles.push_back("run1_FHC/detvar/analysisOutputFHC_Overlay_GENIE_Background_Detvar_prodgenie_numi_nu_overlay_detvar_LYDown_run1_reco2_run1_reco2.root");

      SampleNames.push_back("GENIE BG LYAttenuation");
      SampleTypes.push_back("Background");
      SampleFiles.push_back("run1_FHC/detvar/analysisOutputFHC_Overlay_GENIE_Background_Detvar_prodgenie_numi_nu_overlay_detvar_LY_suppression75attenuation8m_run1_reco2_run1_reco2.root");

      SampleNames.push_back("GENIE BG LYRayleigh");
      SampleTypes.push_back("Background");
      SampleFiles.push_back("run1_FHC/detvar/analysisOutputFHC_Overlay_GENIE_Background_Detvar_prodgenie_numi_nu_overlay_detvar_LY_Rayleigh_run1_reco2_run1_reco2.root");

      SampleNames.push_back("GENIE BG WireModX");
      SampleTypes.push_back("Background");
      SampleFiles.push_back("run1_FHC/detvar/analysisOutputFHC_Overlay_GENIE_Background_Detvar_prodgenie_numi_nu_overlay_detvar_WireModX_run1_reco2_fixed_run1_reco2.root");

      SampleNames.push_back("GENIE BG WireModYZ");
      SampleTypes.push_back("Background");
      SampleFiles.push_back("run1_FHC/detvar/analysisOutputFHC_Overlay_GENIE_Background_Detvar_prodgenie_numi_nu_overlay_detvar_WireModYZ_run1_reco2_run1_reco2.root");

      SampleNames.push_back("GENIE BG WireModThetaXZ");
      SampleTypes.push_back("Background");
      SampleFiles.push_back("run1_FHC/detvar/analysisOutputFHC_Overlay_GENIE_Background_Detvar_prodgenie_numi_nu_overlay_v08_00_00_53_WireModThetaXZ_300k_reco2_run1_reco2.root");

      SampleNames.push_back("GENIE BG WireModThetaYZ");
      SampleTypes.push_back("Background");
      SampleFiles.push_back("run1_FHC/detvar/analysisOutputFHC_Overlay_GENIE_Background_Detvar_prodgenie_numi_nu_overlay_detvar_WireModThetaYZ_withSplines_run1_reco2_run1_reco2.root");

      SampleNames.push_back("GENIE BG Recomb2");
      SampleTypes.push_back("Background");
      SampleFiles.push_back("run1_FHC/detvar/analysisOutputFHC_Overlay_GENIE_Background_Detvar_prodgenie_numi_nu_overlay_detvar_Recomb2_run1_reco2_run1_reco2.root");

      SampleNames.push_back("GENIE BG SCE");
      SampleTypes.push_back("Background");
      SampleFiles.push_back("run1_FHC/detvar/analysisOutputFHC_Overlay_GENIE_Background_Detvar_prodgenie_numi_nu_overlay_v08_00_00_53_SCE_300k_reco2_run1_reco2.root");

      std::vector<std::vector<std::pair<int,int>>> rs_list_v(SampleNames.size());

      // Sample Loop
      for(size_t i_s=0;i_s<SampleNames.size();i_s++){

         E.SetFile(SampleFiles.at(i_s));

         // Event Loop
         for(int i=0;i<E.GetNEvents();i++){
            if(i % 5000 == 0) std::cout << "Processing event " << i << "/" << E.GetNEvents() << std::endl;

            Event e = E.GetEvent(i);

            if (std::find(rs_list_v.at(i_s).begin(), rs_list_v.at(i_s).end(),std::make_pair(e.run,e.subrun)) == rs_list_v.at(i_s).end())
               rs_list_v.at(i_s).push_back(std::make_pair(e.run,e.subrun));

         }

         E.Close();

         std::cout << "Found " << rs_list_v.at(i_s).size() << " unique rs values in this sample" << std::endl;
      }


      // Check which rs are present in all the samples 
      std::vector<std::pair<int,int>> rs_list_good;
      std::ofstream output("Common_rs.list");
      for(size_t i_rs=0;i_rs<rs_list_v.at(0).size();i_rs++){
         bool notfound = false;        

         for(size_t i_s=1;i_s<SampleNames.size();i_s++)
            if (std::find(rs_list_v.at(i_s).begin(), rs_list_v.at(i_s).end(),rs_list_v.at(0).at(i_rs)) == rs_list_v.at(i_s).end()){
               notfound = true;
               break;
            }

         if(!notfound){
            rs_list_good.push_back(rs_list_v.at(0).at(i_rs));        
            output << rs_list_v.at(0).at(i_rs).first << "  " << rs_list_v.at(0).at(i_rs).second << std::endl;
         }
      }

      output.close();
      std::cout << "Found " << rs_list_good.size() << " rs values in all files" << std::endl;
   }
