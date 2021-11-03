R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so)
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so)

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "SampleSets_Example.h"
#include "Parameters.h"

   // Generate a set of text files containing lists of events passing analysis BDT cut
   // If sample has type "Hyperon", split into Signal/Not Signal

   void MakeEventList(){

      double POT = 1.0e21; // POT to scale samples to

      BuildTunes();
      //ImportSamples(sNuWroFullFHC);

      SampleNames.push_back("GENIE Background");
      SampleTypes.push_back("Background");
      SampleFiles.push_back("HyperonTrees_Sys.root");

      SelectionParameters P = P_FHC_Tune_325;
      P.p_AnalysisBDT_Cut = 0.0;

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

            M.SetSignal(e);                
            M.AddEvent(e);

           // Insert Selection Here //

            if(!M.FiducialVolumeCut(e)) continue;
            if(!M.TrackCut(e)) continue;
            if(!M.ShowerCut(e)) continue;
            if(!M.ChooseMuonCandidate(e)) continue;
            if(!M.ChooseProtonPionCandidates(e)) continue;
            if(!M.AnalysisBDTCut(e)) continue; 
           
           ///////////////////////////
            

            if(SampleTypes.at(i_s) != "Hyperon") out << e.run << " " << e.subrun << " " << e.event << std::endl;
            else {

               if(e.IsSignal) out_Signal << e.run << " " << e.subrun << " " << e.event << std::endl;
               else out << e.run << " " << e.subrun << " " << e.event << std::endl;

            }



        }

         out.close();
         if(SampleTypes.at(i_s) == "Hyperon") out_Signal.close();

         E.Close();

      }

}
