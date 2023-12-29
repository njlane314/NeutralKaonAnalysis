R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so);
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so);

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

// Generic script that loads some data and prints a few variables

void RecoPionPair(){

  double POT = 1.0e21; // POT to scale samples to

  BuildTunes();
  SelectionParameters P = P_FHC_Tune_325_NoBDT;

  std::string label = "test";

  EventAssembler E(false);

  TEfficiency *pPionPairReconstructionEfficiency = new TEfficiency("pPionPairReconstructionEfficiency", "Pion Pair Recontruction Efficiency;Neutral Kaon Short Momentum [GeV]; Reconstructed Pion Pairs Efficiency", 10, 0, 2);
  TH1F *hPionPairReconstructionMomentum = new TH1F("hPionPairReconstructionMomentum", "Kaon Short Momentum of Pion Pair Reconstructions;Neutral Kaon Short Momentum [GeV]; Reconstructed Pion Pairs",10, 0, 2);

  int sig = 0, sig_selec = 0;

  E.SetFile("analysisOutputRHC_GENIE_Overlay_Kaon_TEST.root","Background");

  for(int ievent = 0; ievent < E.GetNEvents(); ievent++){

  	if(ievent % 10000 == 0) std::cout << ievent << "/" << E.GetNEvents() << std::endl;

        Event e = E.GetEvent(ievent);
	bool isActiveTPC = false;
	
	std::vector<int> primaryNeutralKaonIndices;
	for (const SimParticle& primaryKaon : e.PrimaryKaon) {
    		if (primaryKaon.PDG == 311 || primaryKaon.PDG == -311) { 
			primaryNeutralKaonIndices.push_back(primaryKaon.MCTruthIndex); 
		}
		if (e.InActiveTPC.at(primaryKaon.MCTruthIndex) == true) { 
			isActiveTPC = true; 
		}
	}

	bool isNeutralPrimaryKaon = false;
	bool isKaonShort = false;
	bool isKaonLong = false;

	double kaonShortModMomentum = -1;
	
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
				kaonShortModMomentum = kaonDecayProduct.ModMomentum;
			}
			if (kaonDecayProduct.PDG == 130 || kaonDecayProduct.PDG == -130) { 
				isKaonLong = true;
			}
		}
	}
	
	bool isPionPlus = false;
	bool isPionMinus = false;

	if (!isKaonShort) continue; // only interested in kaon shorts
	
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

	bool isSignal = false;
	if (isKaonShort && isPionPlus && isPionMinus) isSignal = true;
	
	if(!isSignal) continue;

	bool isPionPlusFound = false;
	bool isPionMinusFound = false;

	for(size_t i = 0; i < e.TracklikePrimaryDaughters.size(); i++) {
		if(e.TracklikePrimaryDaughters.at(i).TrackTruePDG == 211) {
			isPionPlusFound = true;
		}
		if(e.TracklikePrimaryDaughters.at(i).TrackTruePDG == -211) {
			isPionMinusFound = true;
		}
	}		

	bool isReconstructed = false;
	if(isSignal && isPionPlusFound && isPionMinusFound) isReconstructed = true;

	if(isReconstructed) sig_selec += 1;
	sig += 1;

	pPionPairReconstructionEfficiency->Fill(isReconstructed, kaonShortModMomentum); 	
	if(isReconstructed) {
		hPionPairReconstructionMomentum->Fill(kaonShortModMomentum);
	}
    }

    std::cout << "Signal " << sig << "   Selected " << sig_selec << std::endl;

    TCanvas *c1 = new TCanvas("c1", "Distribution", 800, 600);
    pPionPairReconstructionEfficiency->Draw("AP");
    c1->SaveAs("neutral_kaon_short_pion_pair_reconstruction_efficiency.png");

    TCanvas *c2 = new TCanvas("c2", "Distribution", 800, 600);
    hPionPairReconstructionMomentum->Draw();
    c2->SaveAs("neutral_kaon_short_pion_pair_reconstruction_momentum.png");

    E.Close();
    delete pPionPairReconstructionEfficiency;
    delete hPionPairReconstructionMomentum;
    delete c1;
    delete c2;
}
