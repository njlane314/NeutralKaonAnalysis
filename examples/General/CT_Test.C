R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so)
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so)

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"
#include "Parameters.h"

#include "CTTest.h"

   // Run the 

   // WILL NOT WORK with pre-october 2021 versions of ntuples

   void CT_Test(){

      double POT = 1.0e21; // POT to scale samples to

      // setup selection 
      BuildTunes();
      SelectionParameters P = P_FHC_Tune_325;

      std::string label = "test";

      EventAssembler E;
      SelectionManager M(P);
      M.SetPOT(POT);
      M.ImportSelectorBDTWeights(P.p_SelectorBDT_WeightsDir);
      M.ImportAnalysisBDTWeights(P.p_AnalysisBDT_WeightsDir);

      E.SetFile("run1_FHC/analysisOutputFHC_Overlay_GENIE_Hyperon_All.root");
      M.AddSample("Hyperon","Hyperon",E.GetPOT());

      double Signal = 0.0;
      double Selected_Signal = 0.0;

      // Event Loop
      for(int i=0;i<E.GetNEvents();i++){

         if(i % 2000 == 0) std::cout << "Processing event " << i << "/" << E.GetNEvents() << std::endl;

         Event e = E.GetEvent(i);

         M.SetSignal(e);                
         M.AddEvent(e);

         if(e.EventIsSignal) Signal += e.Weight;

         if(!M.FiducialVolumeCut(e)) continue;
         if(!M.TrackCut(e)) continue;
         if(!M.ShowerCut(e)) continue;
         if(!M.ChooseMuonCandidate(e)) continue;
         if(!M.ChooseProtonPionCandidates(e)) continue;
         if(!M.AnalysisBDTCut(e)) continue;       
         if(!M.ConnectednessTest(e)) continue;           

         if(e.EventIsSignal) Selected_Signal += e.Weight;
      }

      E.Close();

      std::cout << "Signal = " << Signal << " Selected = " << Selected_Signal << std::endl;
   }
