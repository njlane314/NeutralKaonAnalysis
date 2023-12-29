R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so);
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so);

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

void PlotMuonMomVsLLRPID(){

    double POT = 1.0e21; 

    BuildTunes();
    SelectionParameters P = P_FHC_Tune_325_NoBDT;

    std::string label = "test";
    std::string SampleType = "background";

    EventAssembler E(false);
    SelectionManager M(P);
    M.SetPOT(POT);
    M.UseFluxWeight(false);
    M.UseGenWeight(false);

    E.SetFile("analysisOutputFHC_Overlay_GENIE_Kaon_cthorpe_make_k0s_events_numi_fhc_reco2_reco2_reco2.root", "Signal");
    M.AddSample("Signal","Signal",E.GetPOT());

    TH2F *hMuonMomVsLLRPID = new TH2F("hMuonMomVsLLRPDI", "", 100, -1, 1, 100, 1, 0);

    for(int i = 0; i < E.GetNEvents(); i++){

        if(i % 10000 == 0) std::cout << i << "/" << E.GetNEvents() << std::endl;

        Event e = E.GetEvent(i);

        M.SetSignal(e);                
        M.AddEvent(e);

        bool passed_FV = false;

        passed_FV = M.FiducialVolumeCut(e);
        if(!passed_FV) continue;

        for(size_t i = 0; i < e.TracklikePrimaryDaughters.size(); i++){

            double trackLLRPID = e.TracklikePrimaryDaughters.at(i).Track_LLR_PID;
            double trackLength = e.TracklikePrimaryDaughters.at(i).TrackLength;
            double trackMomentum = e.TracklikePrimaryDaughters.at(i).TrackTrueModMomentum;
            double trackDisplacement = e.TracklikePrimaryDaughters.at(i).Displacement;
            double trackMeandEdx = e.TracklikePrimaryDaughters.at(i).MeandEdX_ThreePlane;
            int trackPDG = e.TracklikePrimaryDaughters.at(i).TrackTruePDG;

            if(abs(trackPDG) == 13){ // 13 muon, 211 pion, 2212 proton
                hMuonMomVsLLRPID->Fill(trackLLRPID, trackMomentum);
            }
        }

    }

    TCanvas *c1 = new TCanvas("c1", "", 800, 600);
    //c1->SetFillColor(kWhite); 

    hMuonMomVsLLRPID->SetStats(0);
    hMuonMomVsLLRPID->GetYaxis()->SetTitle("True Muon Momentum");
    hMuonMomVsLLRPID->GetXaxis()->SetTitle("LLR PID Score");
    hMuonMomVsLLRPID->GetXaxis()->SetTitleSize(0.04);
    hMuonMomVsLLRPID->GetYaxis()->SetTitleSize(0.04);
    //hMuonMomVsLLRPID->SetFillColor(kAzure);

    hMuonMomVsLLRPID->Draw("COLZ");

    c1->SaveAs("Plots/MuonMomVsLLRPID.png");

    E.Close();

}