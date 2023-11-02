R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so);
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so);

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

// Generic script that loads some data and prints a few variables

void NeutralKaonDecay(){

  double POT = 1.0e21; // POT to scale samples to

  BuildTunes();
  SelectionParameters P = P_FHC_Tune_325_NoBDT;

  std::string label = "test";

  EventAssembler E(false);
  SelectionManager M(P);
  M.SetPOT(POT);

  TH1F *hNeutralKaonShort = new TH1F("hNeutralKaonShort", "Neutral Kaon Short Travel;Travel [cm];Events", 100, 1, 0);
  TH1F *hNeutralKaonLong = new TH1F("hNeutralKaonLong", "Neutral Kaon Long Travel;Travel [cm];Events", 100, 1, 0);	
  TH1F *hNeutralKaonSMomentum = new TH1F("hNeutralKaonSMomentum", "Neutral Kaon Short Momentum;Momentum [GeV];Events", 100, 1, 0);
  TH1F *hNeutralKaonLMomentum = new TH1F("hNeutralKaonLMomentum", "Neutral Kaon Long Momentum;Momentum [GeV];Events", 100, 1, 0);

  E.SetFile("analysisOutputRHC_GENIE_Overlay_Kaon_TEST.root","Background");
  M.AddSample("Background","Background",E.GetPOT());

  for(int ievent=0;ievent<E.GetNEvents();ievent++){

  	if(ievent % 10000 == 0) std::cout << ievent << "/" << E.GetNEvents() << std::endl;

        Event e = E.GetEvent(ievent);
	bool isActiveTPC = false;
	
	M.SetSignal.(e); 
	M.AddEvent(e);
	
	std::vector<int> primaryNeutralKaonIndices;
	for (const SimParticle& primaryKaon : e.PrimaryKaon) {
    		if (primaryKaon.PDG == 311 || primaryKaon.PDG == -311) { 
			primaryNeutralKaonIndices.push_back(primaryKaon.MCTruthIndex); 
		}
		if (e.InActiveTPC.at(primaryKaon.MCTruthIndex) == true) { isActiveTPC = true; }
	}

	bool isNeutralPrimaryKaon = false;
	bool isKaonShort = false;
	bool isKaonLong = false;

	for (size_t i = 0; i < e.KaonDecay.size(); ++i) {
		const SimParticle kaonDecayProduct = e.KaonDecay.at(i);
		
		for (int neutralIndex : primaryNeutralKaonIndices) {
			if (kaonDecayProduct.MCTruthIndex == neutralIndex) {
				isNeutralPrimaryKaon = true;
				break;
			}
		}
		
		if (isActiveTPC && isNeutralPrimaryKaon) {
			if (kaonDecayProduct.PDG == 310 || kaonDecayProduct.PDG == -310) { 
				isKaonShort = true;
				hNeutralKaonShort->Fill(kaonDecayProduct.Travel); 
				hNeutralKaonSMomentum->Fill(kaonDecayProduct.ModMomentum);
			}
			if (kaonDecayProduct.PDG == 130 || kaonDecayProduct.PDG == -130) { 
				isKaonLong = true;
				hNeutralKaonLong->Fill(kaonDecayProduct.Travel); 
				hNeutralKaonLMomentum->Fill(kaonDecayProduct.ModMomentum);
			}
		}
	}

	bool isPionPlus = false;
	bool isPionMinus = false;
	
	if (isNeutralPrimaryKaon == true) {
		for (size_t i = 0; i < e.KaonDecay.size(); ++i) {
			const SimParticle kaonDecayProduct = e.KaonDecay.at(i);
			
			if (kaonDecayProduct.Origin == 7 && kaonDecayProduct.PDG == 211 && kaonDecayProduct.ModMomentum > 0.1) {
				isPionPlus = true;
			}
			if (kaonDecayProduct.Origin == 7 && kaonDecayProduct.PDG == -211 && kaonDecayProduct.ModMomentum > 0.1) {
				isPionMinus = true;
			}
		}
	}
    }

    TCanvas *c1 = new TCanvas("c1", "Distribution", 800, 600);
    hNeutralKaonShort->Draw();
    c1->SaveAs("neutral_kaon_short_travel_distribution.png");

    TCanvas *c2 = new TCanvas("c2", "Distribution", 800, 600);
    hNeutralKaonLong->Draw();
    c2->SaveAs("neutral_kaon_long_travel_distribution.png");

    	TCanvas *c3 = new TCanvas("c3", "Distribution", 800, 600);
	hNeutralKaonSMomentum->Draw();
	c3->SaveAs("neutral_kaon_short_momentum_distribution.png");
	
	TCanvas *c4 = new TCanvas("c4", "Distribution", 800, 600);
	hNeutralKaonLMomentum->Draw();
	c4->SaveAs("neutral_kaon_long_momentum_distribution.png");

    E.Close();
    delete hNeutralKaonShort;
    delete c1;
    delete hNeutralKaonLong;
    delete c2; 
    delete hNeutralKaonSMomentum;
    delete c3; 
    delete hNeutralKaonLMomentum;
    delete c4;
}
