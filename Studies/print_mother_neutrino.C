R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so)
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so)

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

void print_mother_neutrino(){

    //double POT = 1.25e21; // POT to scale samples to
    double POT = 1.5e21;

    BuildTunes();
    //SelectionParameters P = P_FHC_Tune_325_NoBDT;
    SelectionParameters P = P_RHC_Tune_397_NoBDT;

    //std::string label = "kaon_mom";
    //std::string SampleType = "pure_kaon";

    EventAssembler E(false);
    SelectionManager M(P);
    M.ImportSelectorBDTWeights("/exp/uboone/app/users/nlane/NeutralKaonAnalysis/TMVA/SelectorMVA/dataset/weights");

    //M.SetBeamMode(kFHC);
    //M.SetBeamMode(kRHC);
    
    M.SetPOT(POT);
    M.UseFluxWeight(false);
    M.UseGenWeight(false);

    //M.SetupHistograms(100,0,250,";Kaon Momentum X-direction (GeV/C);Events/bin");

    //E.SetFile("analysisOutputFHC_Overlay_GENIE_Kaon_cthorpe_make_k0s_events_numi_fhc_reco2_reco2_reco2.root",  "signal");
    //E.SetFile("analysisOutputRHC_GENIE_Overlay_Kaon_cthorpe_make_k0s_events_numi_rhc_reco2_REAL_reco2_reco2.root", "signal");

    E.SetFile("analysisOutputRHC_GENIE_Overlay_Kaon_cthorpe_make_k0s_events_numi_rhc_reco2_REAL_reco2_reco2.root", "Kaon");
    //E.SetFile("analysisOutputRHC_GENIE_Overlay_Background_prodgenie_numi_uboone_overlay_rhc_mcc9_run3b_v28_v2_sample0.root", "background");
    M.AddSample("Kaon", "Kaon", E.GetPOT());

    int nu_count = 0;
    int anti_nu_count = 0;

    int nue_count = 0;
    int anti_nue_count = 0;

    for(int i = 0; i < E.GetNEvents(); i++){

        if(i % 10000 == 0) std::cout << i << "/" << E.GetNEvents() << std::endl;

        Event e = E.GetEvent(i);

        M.SetSignal(e);                
        M.AddEvent(e);

        bool passed_FV = false;
        bool passed_track = false;
        bool passed_shower = false;
        bool passed_muon = false;
        bool passed_pion_pair = false;
        bool passed_connectedness = false;
        bool passed_Wcut = false;

        //passed_FV = M.FiducialVolumeCut(e);
        //if(!passed_FV) continue;
        /*passed_track = M.TrackCut(e);
        if(!passed_track) continue;
        passed_muon = M.ChooseMuonCandidate(e);
        if(!passed_muon) continue;
        passed_pion_pair = M.ChoosePionPairCandidates(e);
        if(!passed_pion_pair) continue;*/

	//double W = PionPairInvariantMass(e.DecayPionPlusCandidate, e.DecayPionMinusCandidate); 
    	//bool passed_W = W > 0.3 && W < 0.4;

        //if(e.EventIsSignal && e.GoodReco && passed_W) e.Print();

	/*bool has_charged_pion = false;
	for (const SimParticle& primaryPion : e.PrimaryPion) {
                if (abs(primaryPion.PDG) == 211 && primaryPion.ModMomentum > 0.4) {
                	has_charged_pion = true;
                }
        }
	
	if(e.TracklikePrimaryDaughters.size() < 3 && has_charged_pion){
		e.Print();
	}*/

	/*for(const SimParticle& neutrino : e.Neutrino) {
		std::cout << neutrino.PDG << std::endl;
		std::cout << "###################" << std::endl;	
	}*/

	if(e.EventIsSignal){
		if(e.Neutrino.at(0).PDG == 14){
			nu_count += 1;
		}
		else if(e.Neutrino.at(0).PDG == -14){
			anti_nu_count += 1;
		}
  		else if(e.Neutrino.at(0).PDG == 12){
			nue_count += 1;
		}
		else if(e.Neutrino.at(0).PDG == -12){
			anti_nue_count += 1;
		}
	}
    }

    std::cout << "Neutrino count " << nu_count << std::endl;
    std::cout << "Anti-neutrino count " << anti_nu_count << std::endl; 
    std::cout << "Electron neutrino count " << nue_count << std::endl;
    std::cout << "Anti-electron neutrino count " << anti_nue_count << std::endl;

    E.Close();

}
