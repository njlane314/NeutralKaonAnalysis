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

      SampleNames.push_back("CV");
      SampleTypes.push_back("Neutron");
      SampleFiles.push_back("run3b_RHC/detvar/analysisOutputRHC_Overlay_GENIE_Neutron_Detvar_cthorpe_make_neutron_events_numi_rhc_run3b_detvar_reco2_CV_reco2.root");

      SampleNames.push_back("LYAttenuation");
      SampleTypes.push_back("Neutron");
      SampleFiles.push_back("run3b_RHC/detvar/analysisOutputRHC_Overlay_GENIE_Neutron_Detvar_cthorpe_make_neutron_events_numi_rhc_run3b_detvar_reco2_LYAttenuation_reco2.root");

      SampleNames.push_back("LYRayleigh");
      SampleTypes.push_back("Neutron");
      SampleFiles.push_back("run3b_RHC/detvar/analysisOutputRHC_Overlay_GENIE_Neutron_Detvar_cthorpe_make_neutron_events_numi_rhc_run3b_detvar_reco2_LYRayleigh_reco2.root");

      SampleNames.push_back("LYDown");
      SampleTypes.push_back("Neutron");
      SampleFiles.push_back("run3b_RHC/detvar/analysisOutputRHC_Overlay_GENIE_Neutron_Detvar_cthorpe_make_neutron_events_numi_rhc_run3b_detvar_reco2_LYDown_reco2.root");

      SampleNames.push_back("SCE");
      SampleTypes.push_back("Neutron");
      SampleFiles.push_back("run3b_RHC/detvar/analysisOutputRHC_Overlay_GENIE_Neutron_Detvar_cthorpe_make_neutron_events_numi_rhc_run3b_detvar_reco2_SCE_reco2.root");

      SampleNames.push_back("Recomb2");
      SampleTypes.push_back("Neutron");
      SampleFiles.push_back("run3b_RHC/detvar/analysisOutputRHC_Overlay_GENIE_Neutron_Detvar_cthorpe_make_neutron_events_numi_rhc_run3b_detvar_reco2_Recomb2_reco2.root");

      SampleNames.push_back("WireModX");
      SampleTypes.push_back("Neutron");
      SampleFiles.push_back("run3b_RHC/detvar/analysisOutputRHC_Overlay_GENIE_Neutron_Detvar_cthorpe_make_neutron_events_numi_rhc_run3b_detvar_reco2_WireModX_reco2.root");

      SampleNames.push_back("WireModYZ");
      SampleTypes.push_back("Neutron");
      SampleFiles.push_back("run3b_RHC/detvar/analysisOutputRHC_Overlay_GENIE_Neutron_Detvar_cthorpe_make_neutron_events_numi_rhc_run3b_detvar_reco2_WireModYZ_reco2.root");

      SampleNames.push_back("WireModThetaXZ");
      SampleTypes.push_back("Neutron");
      SampleFiles.push_back("run3b_RHC/detvar/analysisOutputRHC_Overlay_GENIE_Neutron_Detvar_cthorpe_make_neutron_events_numi_rhc_run3b_detvar_reco2_WireModThetaXZ_reco2.root");

      SampleNames.push_back("WireModThetaYZ");
      SampleTypes.push_back("Neutron");
      SampleFiles.push_back("run3b_RHC/detvar/analysisOutputRHC_Overlay_GENIE_Neutron_Detvar_cthorpe_make_neutron_events_numi_rhc_run3b_detvar_reco2_WireModThetaYZ_reco2.root");

      // Setup selection manager. Set POT to scale sample to
      EventAssembler E;

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
