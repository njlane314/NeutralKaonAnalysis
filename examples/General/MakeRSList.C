R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so)
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so)

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "SampleSets_Example.h"
#include "Parameters.h"


   void MakeRSList(){

      double POT = 1.0e21; // POT to scale samples to

      BuildTunes();
      //ImportSamples(sNuWroFullFHC);

      //SampleNames.push_back("EXT");
      //SampleTypes.push_back("EXT");
      //SampleFiles.push_back("analysisOutput_EXT_cthorpe_numi_uboone_run1_beamoff_offset1_mcc9_reco2_v08_00_00_28_sample2_sample3_all.root");

     // SampleNames.push_back("Data");
     // SampleTypes.push_back("Data");
      //SampleFiles.push_back("analysisOutputData_prod_mcc9_v08_00_00_45_numi_reco2_run1_beam_good_reco2.root");
        
      SampleNames.push_back("EXT");
      SampleTypes.push_back("EXT");
      SampleFiles.push_back("analysisOutputEXT_prod_mcc9_v08_00_00_45_extnumi_reco2_run1_all_reco2.root");

      SelectionParameters P = P_FHC_Tune_325;
      P.p_AnalysisBDT_Cut = 0.0;

      std::string Mode = "FHC";

      GoodRunList = (std::string)getenv("HYP_TOP") + "/SampleSets/GoodRuns/" + "run1.txt";         

      // Setup selection manager. Set POT to scale sample to
      EventAssembler E;
      SelectionManager M(P);
      M.SetPOT(POT);
      M.ImportSelectorBDTWeights(P.p_SelectorBDT_WeightsDir);
      M.ImportAnalysisBDTWeights(P.p_AnalysisBDT_WeightsDir);      

      int n_Signal=0;
      int n_GoodReco=0;

      // Setup some text files to store the run/sub/event numbers of the selected events
      gSystem->Exec("mkdir -p EventLists");

      std::ofstream out;
      std::ofstream out_Signal;      

      std::ifstream input_GoodRunList(GoodRunList);

      while(!input_GoodRunList.eof()){
         int run;
         input_GoodRunList >> run;
          //std::cout << run << std::endl;
         GoodRuns.push_back(run);
      }

      fhc_run_range[0] = 0; fhc_run_range[1] = 6748;

      std::vector<std::pair<int,int>> rs_list_data;
      std::vector<std::pair<int,int>> rs_list_EXT;

      // Sample Loop
      for(size_t i_s=0;i_s<SampleNames.size();i_s++){

         E.SetFile(SampleFiles.at(i_s));
         if(SampleTypes.at(i_s) != "EXT" && SampleTypes.at(i_s) != "Data") M.AddSample(SampleNames.at(i_s),SampleTypes.at(i_s),E.GetPOT());
         else if(SampleTypes.at(i_s) == "Data") M.AddSample(SampleNames.at(i_s),SampleTypes.at(i_s),Data_POT);
         else if(SampleTypes.at(i_s) == "EXT") M.AddSample(SampleNames.at(i_s),SampleTypes.at(i_s),EXT_POT);
      
         out.open("EventLists/" + SampleFiles.at(i_s) + "_Selected.txt");
         if(SampleTypes.at(i_s) == "Hyperon") out_Signal.open("EventLists/" + SampleFiles.at(i_s) + "_SignalSelected.txt");         

         // Event Loop
         for(int i=0;i<E.GetNEvents();i++){

            Event e = E.GetEvent(i);

            if(!(std::find(GoodRuns.begin(),GoodRuns.end(), e.run) != GoodRuns.end())) continue;

            if(SampleTypes.at(i_s) == "Data" && Mode == "FHC" && (e.run > fhc_run_range[1] || e.run < fhc_run_range[0])) continue;
            if(SampleTypes.at(i_s) == "Data" && Mode == "RHC" && (e.run > rhc_run_range[1] || e.run < rhc_run_range[0])) continue;

            if ( SampleTypes.at(i_s) == "Data" && !(std::find(rs_list_data.begin(), rs_list_data.end(), std::make_pair(e.run,e.subrun)) != rs_list_data.end()) ) rs_list_data.push_back(std::make_pair(e.run,e.subrun));
            if ( SampleTypes.at(i_s) == "EXT" && !(std::find(rs_list_EXT.begin(), rs_list_EXT.end(), std::make_pair(e.run,e.subrun)) != rs_list_EXT.end()) ) rs_list_EXT.push_back(std::make_pair(e.run,e.subrun));


        }

         E.Close();

      }

      std::ofstream rs_file_data("rs_list_data.txt");
      for(size_t i=0;i<rs_list_data.size();i++) rs_file_data << rs_list_data.at(i).first << " " << rs_list_data.at(i).second << std::endl;
      std::ofstream rs_file_EXT("rs_list_EXT.txt");
      for(size_t i=0;i<rs_list_EXT.size();i++) rs_file_EXT << rs_list_EXT.at(i).first << " " << rs_list_EXT.at(i).second << std::endl;

}
