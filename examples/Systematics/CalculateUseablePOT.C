R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so)
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so)

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"

   // After getting the list of RS values in all detector variations
   // calculate the POT accross those runs/subruns

   void CalculateUseablePOT(){

      double POT = 1.0e21; // POT to scale samples to

      BuildTunes();
      SelectionParameters P = P_FHC_Tune_325_NoBDT;

      EventAssembler E;
      E.SetFile("run3b_RHC/detvar/analysisOutputRHC_Overlay_GENIE_Background_Detvar_numi_run3_standard_nu_overlay_cv_reco2_v08_00_00_54_run3_reco2.root");

      // Load the list of runs and subruns in all detector variations
      std::vector<std::pair<int,int>> RSList;
      std::string RSList_str = (std::string)getenv("HYP_TOP") + "/SampleSets/CommonRS/" + "Run3bBackgroundDetvar.list"; 

      std::ifstream input(RSList_str);
      while(!input.eof()){
         int run,subrun;
         input >> run >> subrun;
         RSList.push_back({run,subrun});
      }

      std::cout << "Original POT = " << E.GetPOT() << std::endl;

      double total = 0.0;
      double useable = 0.0;

      // Event Loop
      for(int i=0;i<E.GetNEvents();i++){
         if(i % 20000 == 0) std::cout << i << "/" << E.GetNEvents() << std::endl;
         Event e = E.GetEvent(i);
         total++;                         
         if(RSList.size() && !(std::find(RSList.begin(),RSList.end(),std::make_pair(e.run,e.subrun)) != RSList.end())) continue;
         useable++;
      }

      std::cout << "Useable POT = " << E.GetPOT() << " x " << useable/total << " = " << E.GetPOT()*useable/total << std::endl;     
      E.Close();
   }
