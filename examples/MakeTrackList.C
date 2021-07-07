R__LOAD_LIBRARY($HYP_TOP/lib/libAlg.so)
R__LOAD_LIBRARY($HYP_TOP/lib/libCore.so)

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "SampleSets_Example.h"
#include "Parameters.h"

#include <string>

   // Generate a set of text files containing lists of tracks indexes used 
   // for muon, decay proton and decay pion candidates.
   // Format is:
   // muon_index proton_index pion_index

   void MakeTrackList(){

      double POT = 1e21; // POT to scale samples to

      BuildTunes();
      ImportSamples(sEverythingRHCFiltered);

      SelectionParameters P = P_FHC_Tune_325;
      P.p_AnalysisBDT_Cut = 0.0;
     
      // Setup selection manager. Set POT to scale sample to
      EventAssembler E;
      SelectionManager M(P);
      M.SetPOT(POT);

      // Import the BDT weights
      M.ImportSelectorBDTWeights(P.p_SelectorBDT_WeightsDir);
      M.ImportAnalysisBDTWeights(P.p_AnalysisBDT_WeightsDir);


      // Setup some text files to store the run/sub/event numbers of the selected events
      gSystem->Exec("mkdir -p TrackLists");

      std::ofstream out;
      std::ofstream out_Signal;      

      // Sample Loop
      for(size_t i_s=0;i_s<SampleNames.size();i_s++){

         E.SetFile(SampleFiles.at(i_s));
         if(SampleTypes.at(i_s) != "EXT" && SampleTypes.at(i_s) != "Data") M.AddSample(SampleNames.at(i_s),SampleTypes.at(i_s),E.GetPOT());
         else if(SampleTypes.at(i_s) == "Data") M.AddSample(SampleNames.at(i_s),SampleTypes.at(i_s),Data_POT);
         else if(SampleTypes.at(i_s) == "EXT") M.AddSample(SampleNames.at(i_s),SampleTypes.at(i_s),EXT_POT);

         std::string name = SampleFiles.at(i_s);
         
        // Remove / from name

        while(name.find('/') != std::string::npos){

        name = name.substr(name.find('/') + 1); 
        
        }

         out.open("TrackLists/" + name + "_TrackList.txt");

         // Event Loop
         for(int i=0;i<E.GetNEvents();i++){

            Event e = E.GetEvent(i);

            if((SampleTypes.at(i_s) == "Background" || SampleTypes.at(i_s) == "Hyperon") && e.NMCTruths > 1) continue;
            if(SampleTypes.at(i_s) == "Background" && e.Mode == "HYP") continue;
            if(SampleTypes.at(i_s) == "Hyperon" && e.Mode != "HYP") continue;

            M.SetSignal(e);                
            M.AddEvent(e);


            // Apply all of the cuts in the selection
            if(!M.FiducialVolumeCut(e)) continue;
            if(!M.TrackCut(e)) continue;
            if(!M.ShowerCut(e)) continue;
            if(!M.ChooseMuonCandidate(e)) continue;
            if(!M.ChooseProtonPionCandidates(e)) continue;
            if(!M.AnalysisBDTCut(e)) continue; 
   
            int MuonIndex = e.MuonCandidate.Index;
            int DecayProtonIndex = e.DecayProtonCandidate.Index;
            int DecayPionIndex = e.DecayPionCandidate.Index;

            out <<  MuonIndex  << " " << DecayProtonIndex << " " << DecayPionIndex  << std::endl;

            
         }

         out.close();

         E.Close();

      }


   }
