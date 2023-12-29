R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so)
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so)

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

void BackgroundPlots(){

      std::string label = "test";
      double POT = 1.0e21; // POT to scale samples to

      BuildTunes();

      SampleNames.push_back("GENIE Background");
      SampleTypes.push_back("Background");
      SampleFiles.push_back("analysisOutputRHC_GENIE_Overlay_Kaon_TEST.root");

      SelectionParameters P = P_FHC_Tune_325_NoBDT;

      EventAssembler E;
      SelectionManager M(P);
      M.SetPOT(POT);
      M.UseFluxWeight(false);
      M.UseGenWeight(false);

      M.SetupHistograms(20,0,10.0,";Neutrino Energy (GeV);Events");

      for(size_t i_s=0;i_s<SampleNames.size();i_s++){

         E.SetFile(SampleFiles.at(i_s), SampleTypes.at(i_s));
         if(SampleTypes.at(i_s) != "EXT" && SampleTypes.at(i_s) != "Data") M.AddSample(SampleNames.at(i_s),SampleTypes.at(i_s),E.GetPOT());
         else if(SampleTypes.at(i_s) == "Data") M.AddSample(SampleNames.at(i_s),SampleTypes.at(i_s),Data_POT);
         else if(SampleTypes.at(i_s) == "EXT") M.AddSample(SampleNames.at(i_s),SampleTypes.at(i_s),EXT_POT);

         for(int i=0;i<E.GetNEvents();i++){
	    std::cout << "Starting event..." << i << std::endl;

            if(i % 10000 == 0) std::cout << i << "/" << E.GetNEvents() << std::endl;

            Event e = E.GetEvent(i);

	    std::cout << "Setting signal..." << std::endl;
            M.SetSignal(e);                
            M.AddEvent(e);

	    std::cout << "Beginning selection..." << std::endl;
            if(!M.FiducialVolumeCut(e)) continue;
	    std::cout << "Passed fiducial cut..." << std::endl;
            if(!M.TrackCut(e)) continue;
            if(!M.ShowerCut(e)) continue;
            if(!M.ChooseMuonCandidate(e)) continue;
	    std::cout << "Passed muon candidate selection..." << std::endl;
            if(!M.ChoosePionPairCandidates(e, true)) continue;
	    std::cout << "Pass pion pair candidate selection..." << std::endl;

            double E = e.Neutrino.at(0).E;
	
	    std::cout << "Filling histogram" << std::endl;
            M.FillHistograms(e,E);                
         }
         E.Close();
      }

      M.DrawHistograms(label);
   }
