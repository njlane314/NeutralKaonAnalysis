R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so);
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so);

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

void NeutralKaonTravel(){

	double POT = 1.0e21;
	std::string label = "travel";

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

	M.SetupHistograms(30, 0, 300, ";Travel (cm);Events");

	for(size_t s_itr = 0; s_itr < SampleNames.size(); s_itr++){
		
		E.SetFile(SampleFiles.at(s_itr), SampleTypes.at(s_itr));
		if(SampleTypes.at(s_itr) != "EXT" && SampleTypes.at(s_itr) != "Data") M.AddSample(SampleNames.at(s_itr), SampleTypes.at(s_itr), E.GetPOT());  		

		for(int evt_itr = 0; evt_itr < E.GetNEvents(); evt_itr++){

    			if(evt_itr % 10000 == 0) std::cout << evt_itr << "/" << E.GetNEvents() << std::endl;

    			Event evt = E.GetEvent(evt_itr);
		
			M.SetSignal(evt);
			M.AddEvent(evt);
		
			if(!M.FiducialVolumeCut(evt)) continue;

			for (const SimParticle& kaonDecayProduct : evt.KaonDecay) {
				if (kaonDecayProduct.MCTruthIndex == evt.TrueNeutralKaonIndex) {
					M.FillHistograms(evt, kaonDecayProduct.Travel);
                		}
        		}
		}   

  		E.Close();
	}

	std::cout << "Drawing histograms..." << std::endl;
	M.DrawHistograms(label);
}
