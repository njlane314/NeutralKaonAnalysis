R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so);
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so);

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

void PionMomBias(){

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

    TH1F *hMuonMomentumBias1 = new TH1F("hMuonMomentumBias1", "", 200, -1, 1);
    TH1F *hMuonMomentumBias2 = new TH1F("hMuonMomentumBias2", "", 200, -1, 1);
    TH1F *hMuonMomentumBias3 = new TH1F("hMuonMomentumBias3", "", 200, -1, 1);
    TH1F *hMuonMomentumBias4 = new TH1F("hMuonMomentumBias4", "", 200, -1, 1);

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
            
            if(e.TracklikePrimaryDaughters.at(i).TrackTrueOrigin != 7) continue;

            double trackLLRPID = e.TracklikePrimaryDaughters.at(i).Track_LLR_PID;
            double trackLength = e.TracklikePrimaryDaughters.at(i).TrackLength;
            double trackTrueMomentum = e.TracklikePrimaryDaughters.at(i).TrackTrueModMomentum;
            double trackMuonMomentum = e.TracklikePrimaryDaughters.at(i).MuonMomentum;
            double trackPionMomentum = PionMomentum(e.TracklikePrimaryDaughters.at(i).TrackLength);
            double trackDisplacement = e.TracklikePrimaryDaughters.at(i).Displacement;
            double trackMeandEdx = e.TracklikePrimaryDaughters.at(i).MeandEdX_ThreePlane;
            int trackPDG = e.TracklikePrimaryDaughters.at(i).TrackTruePDG;
            int trackIndex = e.TracklikePrimaryDaughters.at(i).Index;

            if(abs(trackPDG) == 211){ // 13 muon, 211 pion, 2212 proton
                //std::cout << trackIndex << std::endl;
                double bias = ( trackTrueMomentum - trackPionMomentum ) / trackTrueMomentum;
                if(trackTrueMomentum < 0.2) {
                    hMuonMomentumBias1->Fill(bias);
                }
                else if(trackTrueMomentum > 0.2 && trackTrueMomentum < 0.4) {
                    hMuonMomentumBias2->Fill(bias);
                }
                else if(trackTrueMomentum > 0.4 && trackTrueMomentum < 0.6) {
                    hMuonMomentumBias3->Fill(bias);
                }
                else if(trackTrueMomentum > 0.6 && trackTrueMomentum < 0.8) {
                    hMuonMomentumBias4->Fill(bias);
                }
            }
        }

    }

    double scaleMuonMomentumBias100 = hMuonMomentumBias1->Integral() > 0 ? 1.0 / hMuonMomentumBias1->Integral() : 0;
    double scaleMuonMomentumBias300 = hMuonMomentumBias2->Integral() > 0 ? 1.0 / hMuonMomentumBias2->Integral() : 0;
    double scaleMuonMomentumBias600 = hMuonMomentumBias3->Integral() > 0 ? 1.0 / hMuonMomentumBias3->Integral() : 0;
    double scaleMuonMomentumBias1000 = hMuonMomentumBias4->Integral() > 0 ? 1.0 / hMuonMomentumBias4->Integral() : 0;
   
    TCanvas *c1 = new TCanvas("c1", "", 800, 600);

    double width = 1.8;

    hMuonMomentumBias1->Scale(scaleMuonMomentumBias100);
    hMuonMomentumBias2->Scale(scaleMuonMomentumBias300);
    hMuonMomentumBias3->Scale(scaleMuonMomentumBias600);
    hMuonMomentumBias4->Scale(scaleMuonMomentumBias1000);

    hMuonMomentumBias1->SetLineColor(kBlue);
    hMuonMomentumBias1->SetLineStyle(1);
    hMuonMomentumBias1->SetLineWidth(width);

    hMuonMomentumBias2->SetLineColor(kRed);
    hMuonMomentumBias2->SetLineStyle(1);
    hMuonMomentumBias2->SetLineWidth(width);

    hMuonMomentumBias3->SetLineColor(kGreen+2);
    hMuonMomentumBias3->SetLineStyle(1);
    hMuonMomentumBias3->SetLineWidth(width);

    hMuonMomentumBias4->SetLineColor(kOrange+1);
    hMuonMomentumBias4->SetLineStyle(1);
    hMuonMomentumBias4->SetLineWidth(width);

    hMuonMomentumBias1->SetStats(0);
    hMuonMomentumBias1->SetMaximum(0.07);
    hMuonMomentumBias1->SetMinimum(0);
    hMuonMomentumBias1->GetYaxis()->SetTitle("A. U.");
    hMuonMomentumBias1->GetXaxis()->SetTitle("(p_{#pi, true} - p_{#pi, reco}) / p_{#pi, true}");
    hMuonMomentumBias1->GetXaxis()->SetTitleSize(0.04);
    hMuonMomentumBias1->GetYaxis()->SetTitleSize(0.04);

    hMuonMomentumBias1->Draw("hist");
    hMuonMomentumBias2->Draw("hist SAME");
    hMuonMomentumBias3->Draw("hist SAME");
    hMuonMomentumBias4->Draw("hist SAME");

    TLegend *legend = new TLegend(0.3, 0.65, 0.15, 0.85);
    legend->AddEntry(hMuonMomentumBias1, "p_{#pi} #in [0, 0.2] GeV/c", "l");
    legend->AddEntry(hMuonMomentumBias2, "p_{#pi} #in [0.2, 0.4] GeV/c", "l");
    legend->AddEntry(hMuonMomentumBias3, "p_{#pi} #in [0.4, 0.6] GeV/c", "l");
    legend->AddEntry(hMuonMomentumBias4, "p_{#pi} #in [0.6, 0.8] GeV/c", "l");
    legend->SetTextSize(0.03);
    legend->SetBorderSize(0); 
    legend->SetFillStyle(0);  
    legend->Draw();

    c1->SaveAs("pion_momentum_bias.png");

    E.Close();

}