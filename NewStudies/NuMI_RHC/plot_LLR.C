R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so);
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so);

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

void plot_LLR(){

    BuildTunes();
    SelectionParameters P = P_RHC_Tune_397_NoBDT;

    std::string label = "test";
    std::string SampleType = "signal";

    EventAssembler E(false);
    SelectionManager M(P);
    M.UseFluxWeight(false);
    M.UseGenWeight(false);

    E.SetFile("analysisOutput_nlane_neutralkaon_events_nummi_rhc_reco2_reco2_TEST.root", "Signal");
    M.AddSample("Signal","Signal",E.GetPOT());

    TH1F *hBraggLikelihood = new TH1F("", "", 100, -1, 1);

    for(int i = 0; i < E.GetNEvents(); i++){

        if(i % 10000 == 0) std::cout << i << "/" << E.GetNEvents() << std::endl;

        Event e = E.GetEvent(i);

        M.SetSignal(e);                
        M.AddEvent(e);

        bool passed_FV = false;

        passed_FV = M.FiducialVolumeCut(e);
        if(!passed_FV) continue;

        for(size_t i = 0; i < e.TracklikePrimaryDaughters.size(); i++){

            int trackIndex = e.TracklikePrimaryDaughters.at(i).Index;
            double trackLLRPID = e.TracklikePrimaryDaughters.at(i).Track_LLR_PID;
            double trackLength = e.TracklikePrimaryDaughters.at(i).TrackLength;
            double trackMomentum = e.TracklikePrimaryDaughters.at(i).TrackTrueModMomentum;
            double trackDisplacement = e.TracklikePrimaryDaughters.at(i).Displacement;
            double trackMeandEdx = e.TracklikePrimaryDaughters.at(i).MeandEdX_ThreePlane;
            int trackPDG = e.TracklikePrimaryDaughters.at(i).TrackTruePDG;
		
	    double trackBraggPIDPionPlusForward = e.TracklikePrimaryDaughters.at(i).Track_Bragg_PID_PionPlus_Forward;
	    double trackBraggPIDPionPlusBackward = e.TracklikePrimaryDaughters.at(i).Track_Bragg_PID_PionPlus_Backward;
	    double trackBraggPIDPionMinusForward = e.TracklikePrimaryDaughters.at(i).Track_Bragg_PID_PionMinus_Forward;
	    double trackBraggPIDPionMinusBackward = e.TracklikePrimaryDaughters.at(i).Track_Bragg_PID_PionMinus_Backward;
	
		std::cout << trackBraggPIDPionPlusForward << std::endl;
        std::cout << trackBraggPIDPionPlusBackward << std::endl;
        std::cout << trackBraggPIDPionMinusForward << std::endl;
		std::cout << trackBraggPIDPionMinusBackward << std::endl;

            if(trackIndex != 2) continue;

	    if(trackPDG == 211){
		hBraggLikelihood->Fill(trackBraggPIDPionPlusForward);
	    }
        }

    }

    TCanvas *c1 = new TCanvas("c1", "", 800, 600);

    hBraggLikelihood->Draw();
    
    c1->SaveAs("Plots/bragg_PID_test.png");

    E.Close();

}
