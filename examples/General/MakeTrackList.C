R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so)
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so)

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "SampleSets_Example.h"
#include "Parameters.h"

#include <string>

   // Generate a set of text files containing lists of tracks indexes used 
   // for muon, decay proton and decay pion candidates.
   // Format is: muon_index proton_index pion_index
   // This is used by some tools in the standalone EventConnectedness repo

   void MakeTrackList(){

      double POT = 1e21; // POT to scale samples to

      BuildTunes();

      std::string SampleType = "Hyperon"; 
      std::string SampleFile = "run1_FHC/analysisOutputFHC_Overlay_GENIE_Hyperon_All.root"; 

      SelectionParameters P = P_FHC_Tune_325_NoBDT;

      // Setup selection manager. Set POT to scale sample to
      EventAssembler E;
      E.SetFile(SampleFile);
      SelectionManager M(P);
      M.SetPOT(POT);
      M.ImportSelectorBDTWeights(P.p_SelectorBDT_WeightsDir);
      M.AddSample(SampleType,SampleType,E.GetPOT());

      // Setup some text files to store the run/sub/event numbers of the selected events
      gSystem->Exec("mkdir -p TrackLists");
      std::ofstream out;
      std::ofstream out_Signal;      
      std::string name = SampleFile;

      // Remove / from name
      while(name.find('/') != std::string::npos) name = name.substr(name.find('/') + 1);        
      out.open("TrackLists/" + name + "_TrackList.txt");

      // Event Loop
      for(int i=0;i<E.GetNEvents();i++){

        if(i % 20000 == 0) std::cout << "Processing event " << i << "/" << E.GetNEvents() << std::endl;

         Event e = E.GetEvent(i);
         M.SetSignal(e);                
         M.AddEvent(e);

         if(!M.FiducialVolumeCut(e)) continue;
         if(!M.TrackCut(e)) continue;
         if(!M.ShowerCut(e)) continue;
         if(!M.ChooseMuonCandidate(e)) continue;
         if(!M.ChooseProtonPionCandidates(e)) continue;

         int MuonIndex = e.MuonCandidate.Index;
         int DecayProtonIndex = e.DecayProtonCandidate.Index;
         int DecayPionIndex = e.DecayPionCandidate.Index;

         out <<  MuonIndex  << " " << DecayProtonIndex << " " << DecayPionIndex  << std::endl;            
      }

      out.close();
      E.Close();
   }
