R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so)
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so)

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"
#include "Parameters.h"

#include "CTTest.h"

   // Run the connectedness test as part of the selection 

   void CT_Test(){

      double POT = 1.0e21; // POT to scale samples to

      // setup selection 
      BuildTunes();
      SelectionParameters P = P_FHC_Tune_325;

      std::string label = "test";

      EventAssembler E;
      SelectionManager M(P);
      M.SetPOT(POT);
      M.ImportSelectorBDTWeights("/uboone/app/users/nlane/NeutralKaonAnalysis/TMVA/SelectorMVA/dataset/weights");

      E.SetFile("analysisOutputFHC_Overlay_GENIE_Kaon_cthorpe_make_k0s_events_numi_fhc_reco2_reco2_reco2.root", "Signal");
      M.AddSample("Hyperon","Hyperon",E.GetPOT());

      double Signal = 0.0;
      double Selected_Signal = 0.0;

      // Event Loop
      for(int i=0;i<E.GetNEvents();i++){

         if(i % 10000 == 0) std::cout << "Processing event " << i << "/" << E.GetNEvents() << std::endl;

         Event e = E.GetEvent(i);

         M.SetSignal(e);                
         M.AddEvent(e);

         if(e.EventIsSignal) Signal += e.Weight;

         if(!M.FiducialVolumeCut(e)) continue;
         if(!M.TrackCut(e)) continue;
         if(!M.ShowerCut(e)) continue;
         if(!M.ChooseMuonCandidate(e)) continue;
         if(!M.ChoosePionPairCandidates(e)) continue;     
         //if(!M.ConnectednessTest(e)) continue;           

         if(e.EventIsSignal) Selected_Signal += e.Weight;
      }

      E.Close();

      std::cout << "Signal = " << Signal << " Selected = " << Selected_Signal << std::endl;
   }
