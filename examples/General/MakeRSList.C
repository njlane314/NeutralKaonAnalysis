R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so)
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so)

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "SampleSets_Example.h"
#include "Parameters.h"

   // Make list of runs and subruns in a sample of events
   // This is needed by the MicroBooNE POT/trigger counting
   // scripts for Data/EXT samples

   void MakeRSList(){

      double POT = 1.0e21; // POT to scale samples to

      EventAssembler E;

      E.SetFile("BNB/analysisOutputEXT_data_extbnb_mcc9.1_v08_00_00_25_reco2_G1_all_reco2.root");  

      int Mode = kFHC;
      std::string SampleType = "EXT";

      // Set FHC/RHC ranges if applicable
      fhc_run_range[0] = -1e5; fhc_run_range[1] = 1e5;
      rhc_run_range[0] = -1e5; rhc_run_range[1] = 1e5;

      // Load the good run list
      GoodRunList = (std::string)getenv("HYP_TOP") + "/SampleSets/GoodRuns/" + "run3.txt";
      std::ifstream input_GoodRunList(GoodRunList);
      while(!input_GoodRunList.eof()){
         int run;
         input_GoodRunList >> run;
         GoodRuns.push_back(run);
      }

      std::vector<std::pair<int,int>> rs_list;

      // Event Loop
      for(int i=0;i<E.GetNEvents();i++){

         if(i % 20000 == 0) std::cout << "Processing event " <<  i << "/" << E.GetNEvents() << std::endl;

         Event e = E.GetEvent(i);

         if(std::find(GoodRuns.begin(),GoodRuns.end(), e.run) == GoodRuns.end()) continue;

         if(SampleType == "Data" && Mode == kFHC && (e.run > fhc_run_range[1] || e.run < fhc_run_range[0])) continue;
         if(SampleType == "Data" && Mode == kRHC && (e.run > rhc_run_range[1] || e.run < rhc_run_range[0])) continue;

         if (std::find(rs_list.begin(), rs_list.end(), std::make_pair(e.run,e.subrun)) == rs_list.end()) rs_list.push_back(std::make_pair(e.run,e.subrun));
      }

      E.Close();

      // Print lists
      gSystem->Exec("mkdir -p RSLists");
      std::ofstream rs_file("RSLists/rs_list.txt");
      for(size_t i=0;i<rs_list.size();i++) rs_file << rs_list.at(i).first << " " << rs_list.at(i).second << std::endl;
   }
