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

      std::vector<std::string> SampleFiles;
      SampleFiles.push_back("run3b_RHC/detvar/analysisOutputRHC_Overlay_GENIE_Neutron_Detvar_cthorpe_make_neutron_events_numi_rhc_run3b_detvar_reco2_CV_reco2.root"); 
      std::vector<std::pair<int,int>> RSList;
      std::string RSList_str = (std::string)getenv("HYP_TOP") + "/SampleSets/CommonRS/" + "Run3bNeutronDetvar.list";
      std::ifstream input(RSList_str);
      while(!input.eof()){
         int run,subrun;
         input >> run >> subrun;
         RSList.push_back({run,subrun});
      }

      if(SampleFiles.size() > 1){
         std::cout << "Sample vector size != 1, use only one sample with this script" << std::endl;
         return;
      }

      std::string label = "test";

      // Setup selection manager. Set POT to scale sample to, import the BDT weights
      EventAssembler E;

      E.SetFile(SampleFiles.at(0));

      std::cout << "Original POT = " << E.GetPOT() << std::endl;

      double total = 0;
      double useable = 0;

      // Event Loop
      for(int i=0;i<E.GetNEvents();i++){
         if(i % 5000 == 0) std::cout << i << "/" << E.GetNEvents() << std::endl;
         Event e = E.GetEvent(i);
         total++;                         
         if(RSList.size() && !(std::find(RSList.begin(),RSList.end(),std::make_pair(e.run,e.subrun)) != RSList.end())) continue;
         useable++;
      }

      std::cout << "Useable POT = " << E.GetPOT() << " x " << useable/total << " = " << E.GetPOT()*useable/total << std::endl;     

      E.Close();
   }
