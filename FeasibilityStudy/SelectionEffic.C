R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so);
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so);

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

void SelectionEffic(){

	double POT = 1.0e21;
	std::string label = "effic";

  	BuildTunes();
  	EventAssembler E;
	
	SampleNames.push_back("GENIE Background");
	SampleTypes.push_back("Background");
	SampleFiles.push_back("analysisOutputFHC_GENIE_Overlay_Kaon_Test.root");

	SelectionParameters P = P_FHC_Tune_325_NoBDT;
	SelectionManager M(P);
	M.SetPOT(POT);
	M.UseFluxWeight(false);
	M.UseGenWeight(false);

	TEfficiency* pEff = new TEfficiency("eff", ";Neutrino Enery [GeV]; Efficiency", 10, 0, 10);

	for(size_t s_itr = 0; s_itr < SampleNames.size(); s_itr++){
		
		E.SetFile(SampleFiles.at(s_itr), SampleTypes.at(s_itr));
		if(SampleTypes.at(s_itr) != "EXT" && SampleTypes.at(s_itr) != "Data") M.AddSample(SampleNames.at(s_itr), SampleTypes.at(s_itr), E.GetPOT());  		
		for(int evt_itr = 0; evt_itr < E.GetNEvents(); evt_itr++){

    			if(evt_itr % 10000 == 0) std::cout << evt_itr << "/" << E.GetNEvents() << std::endl;

    			Event evt = E.GetEvent(evt_itr);
			M.SetSignal(evt);
			M.AddEvent(evt);
			
			if(!evt.EventIsSignal) continue;
			
			bool bPassed = false;

			if(!M.FiducialVolumeCut(evt) && !M.TrackCut(evt) && !M.ShowerCut(evt) && !M.ChooseMuonCandidate(evt) && !M.ChoosePionPairCandidates(evt)) bPassed = true;

			pEff->Fill(bPassed, evt.Neutrino.at(0).E);
		}   

  		E.Close();
	}

	HypPlot::DrawEfficiencyPlot(pEff, "", "", {kFHC}, {POT});
}
