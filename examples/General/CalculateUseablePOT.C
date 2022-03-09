R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so)
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so)

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
//#include "SampleSets_Nov21.h"

   void CalculateUseablePOT(){

      double POT = 1.0e21; // POT to scale samples to

      BuildTunes();

      SelectionParameters P = P_FHC_Tune_325;

//      SampleFiles.push_back("run1_FHC/detvar/analysisOutputFHC_Overlay_GENIE_Neutron_Detvar_cthorpe_make_neutron_events_run1_detvar_CV_neutron_reco2_reco2.root"); 
//      SampleFiles.push_back("run1_FHC/detvar/analysisOutputFHC_Overlay_GENIE_Hyperon_Detvar_cthorpe_make_hyperon_events_run1_detvar_CV_hyperon_reco2_reco2.root"); 
//SampleFiles.push_back("run1_FHC/detvar/analysisOutputFHC_Overlay_GENIE_Background_Detvar_prodgenie_numi_nu_overlay_v08_00_00_53_CV_300k_reco2_run1_reco2.root");
      std::vector<std::string> SampleFiles = {"run1_FHC/analysisOutputFHC_Overlay_GENIE_Dirt_prodgenie_numi_uboone_overlay_dirt_fhc_mcc9_run1_v28_sample1.root"};

      if(SampleFiles.size() > 1){
         std::cout << "Sample vector size != 1, use only one sample with this script" << std::endl;
         return;
      }
/*
//      std::string in_CommonRSList = (std::string)getenv("HYP_TOP") + "/SampleSets/CommonRS/" + "Run1NeutronDetvar.list";
      std::string in_CommonRSList = (std::string)getenv("HYP_TOP") + "/SampleSets/CommonRS/" + "Run1HyperonDetvar.list";
//      std::string in_CommonRSList = (std::string)getenv("HYP_TOP") + "/SampleSets/CommonRS/" + "Run1BackgroundDetvar.list";

      std::ifstream input(in_CommonRSList);
      std::vector<std::pair<int,int>> CommonRSList;
      while(!input.eof()){
         int run,subrun;
         input >> run >> subrun;
         CommonRSList.push_back({run,subrun});
      }
      input.close();

      std::cout << "Got " << CommonRSList.size() << " runs/subruns to use" << std::endl;
*/
      std::string label = "test";

      // Setup selection manager. Set POT to scale sample to, import the BDT weights
      EventAssembler E;

      E.SetFile(SampleFiles.at(0));

     std::cout << E.GetPOT() << std::endl;

      double total = 0;
      double useable = 0;

      // Event Loop
      for(int i=0;i<E.GetNEvents();i++){

         if(i % 5000 == 0) std::cout << i << "/" << E.GetNEvents() << std::endl;
         Event e = E.GetEvent(i);

//         total++;
//         if(std::find(CommonRSList.begin(), CommonRSList.end(),std::make_pair(e.run,e.subrun)) != CommonRSList.end()) useable++; 
         
      }

      std::cout << "Useable POT = " << E.GetPOT() << " x " << useable/total << " = " << E.GetPOT()*useable/total << std::endl;
     

      E.Close();



   }
