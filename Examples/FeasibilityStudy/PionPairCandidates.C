R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so);
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so);

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

// Generic script that loads some data and prints a few variables

void PionPairCandidates(){

	double POT = 1.0e21; // POT to scale samples to

  	BuildTunes();
  	SelectionParameters P = P_FHC_Tune_325_NoBDT;

	std::string label = "test";

  	EventAssembler E(false);
  	SelectionManager M(P);

  	M.SetPOT(POT);
	M.UseFluxWeight(false);
	M.UseGenWeight(false);
	
 	E.SetFile("analysisOutputRHC_GENIE_Overlay_Kaon_TEST.root","Background");
	
	double sig = 0.0;
	double bkg = 0.0;
	double sel_sig = 0.0;
	double sel_bkg = 0.0;

  	for(int evt_itr = 0; evt_itr < E.GetNEvents(); evt_itr++){

  		if(evt_itr % 10000 == 0) std::cout << evt_itr << "/" << E.GetNEvents() << std::endl;
		std::cout << evt_itr << std::endl;
        	Event evt = E.GetEvent(evt_itr);
		
		M.SetSignal(evt);
		std::cout << "Set signal.." << std::endl;
		M.AddEvent(evt);
		std::cout << "Added event.." << std::endl;
		
		if(evt.EventIsSignal) sig += evt.Weight;
		else bkg += evt.Weight;

		if(!M.FiducialVolumeCut(evt)) continue;
		std::cout << "Passed fiducial cut..." << std::endl;
		if(!M.TrackCut(evt)) continue;
		std::cout << "Passed track cut.." << std::endl;
		if(!M.ShowerCut(evt)) continue;
		if(!M.ChooseMuonCandidate(evt)) continue;
		std::cout << "Passed muon candidate cut..." << std::endl;
		if(!M.ChoosePionPairCandidates(evt, true)) continue;
		std::cout << "Passed selection!" << std::endl;

		if(evt.EventIsSignal) sel_sig += evt.Weight;
		else sel_bkg += evt.Weight;
	}	

	E.Close();
	
	std::cout << "Signal = " << sig << "   Selected = " << sel_sig << std::endl;
	std::cout << "Background = " << bkg << "   Selected = " << sel_bkg << std::endl;
}

