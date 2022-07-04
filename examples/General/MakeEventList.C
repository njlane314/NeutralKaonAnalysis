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
      EventAssembler E;
      E.SetFile("run1_FHC/analysisOutputFHC_Overlay_GENIE_Hyperon_All.root");
      std::string SampleType = "Hyperon"; 

      SelectionParameters P = P_FHC_Tune_325_NoBDT;

      // Setup selection manager. Set POT to scale sample to
      SelectionManager M(P);
      M.SetPOT(POT);
      M.ImportSelectorBDTWeights(P.p_SelectorBDT_WeightsDir);
      M.ImportAnalysisBDTWeights(P.p_AnalysisBDT_WeightsDir);      
      M.AddSample(SampleType,SampleType,E.GetPOT());
      M.UseFluxWeight(false);
      M.UseGenWeight(false);

      // Setup some text files to store the run/sub/event numbers of the selected events
      gSystem->Exec("mkdir -p EventLists");
      std::ofstream out;
      std::ofstream out_Signal;      

      out.open("EventLists/Selected.txt");
      if(SampleType == "Hyperon") out_Signal.open("EventLists/SignalSelected.txt");         

      // Event Loop
      for(int i=0;i<E.GetNEvents();i++){

         if(i % 20000 == 0) std::cout << i << "/" << E.GetNEvents() << std::endl;

         Event e = E.GetEvent(i);

         M.SetSignal(e);                
         M.AddEvent(e);

         // Insert Selection Here //

         if(!M.FiducialVolumeCut(e)) continue;
         if(!M.TrackCut(e)) continue;
         if(!M.ShowerCut(e)) continue;
         if(!M.ChooseMuonCandidate(e)) continue;
         if(!M.ChooseProtonPionCandidates(e)) continue;
         //if(!M.AnalysisBDTCut(e)) continue; 
         //if(!M.AngleCut(e)) continue;
         //if(!M.WCut(e)) continue;
         if(!M.ConnectednessTest(e)) continue;

         ///////////////////////////

         if(e.Weight > 0){
            if(SampleType != "Hyperon") out << e.run << " " << e.subrun << " " << e.event << std::endl;
            else {
               if(e.EventIsSignal) out_Signal << e.run << " " << e.subrun << " " << e.event << std::endl;
               else out << e.run << " " << e.subrun << " " << e.event << std::endl;
            }
         }
      }

      out.close();
      if(SampleType == "Hyperon") out_Signal.close();

      E.Close();
   }
