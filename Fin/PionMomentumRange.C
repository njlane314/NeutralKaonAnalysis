R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so);
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so);

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

void PionMomentumRange(){

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

    TH2F *hMuonMomVsRange = new TH2F("hMuonMomVsRange", "", 100, 0, 6, 100, 0, 1000);

    for(int i = 0; i < E.GetNEvents(); i++){

        if(i % 10000 == 0) std::cout << i << "/" << E.GetNEvents() << std::endl;

        //if(i > 10000) continue;

        Event e = E.GetEvent(i);

        M.SetSignal(e);                
        M.AddEvent(e);

        bool found_charged_K_short = false;
        FV::FiducialVolume a_FiducialVolume(P.p_FV,P.p_Padding);
        for(size_t i_tr = 0; i_tr < e.NMCTruths; i_tr++){
            found_charged_K_short = e.IsK0SCharged.at(i_tr) && a_FiducialVolume.InFiducialVolume(e.TruePrimaryVertex.at(i_tr));
        }

        if(!found_charged_K_short) continue;

        for(size_t i = 0; i < e.TracklikePrimaryDaughters.size(); i++){
            
            //if(e.TracklikePrimaryDaughters.at(i).TrackTrueOrigin != 7) continue;

            double trackLLRPID = e.TracklikePrimaryDaughters.at(i).Track_LLR_PID;
            double trackLength = e.TracklikePrimaryDaughters.at(i).TrackLength;
            double trackTrueLength = e.TracklikePrimaryDaughters.at(i).TrackTrueLength;
            double trackTrueMomentum = e.TracklikePrimaryDaughters.at(i).TrackTrueModMomentum;
            double trackMuonMomentum = e.TracklikePrimaryDaughters.at(i).MuonMomentum;
            double trackPionMomentum = PionMomentum(e.TracklikePrimaryDaughters.at(i).TrackLength);
            double trackDisplacement = e.TracklikePrimaryDaughters.at(i).Displacement;
            double trackMeandEdx = e.TracklikePrimaryDaughters.at(i).MeandEdX_ThreePlane;
            int trackPDG = e.TracklikePrimaryDaughters.at(i).TrackTruePDG;
            int trackIndex = e.TracklikePrimaryDaughters.at(i).Index;

            if(abs(trackPDG) == 13){ // 13 muon, 211 pion, 2212 proton
                hMuonMomVsRange->Fill(trackTrueMomentum, trackTrueLength);
            }
        }

    }

    TCanvas *c1 = new TCanvas("c1", "", 800, 600);
    //c1->SetFillColor(kWhite); 

    hMuonMomVsRange->SetStats(0);
    hMuonMomVsRange->GetYaxis()->SetTitle("True Track Length (cm)");
    hMuonMomVsRange->GetXaxis()->SetTitle("True Muon Momentum (GeV/c)");
    hMuonMomVsRange->GetXaxis()->SetTitleSize(0.04);
    hMuonMomVsRange->GetYaxis()->SetTitleSize(0.04);
    //hMuonMomVsRange->SetFillColor(kAzure);

    hMuonMomVsRange->Draw("COLZ");

    c1->SetLeftMargin(0.12);
    c1->Update();
    c1->SaveAs("Plots/muon_momentum_range.png");

    E.Close();

}