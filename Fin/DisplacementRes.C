R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so);
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so);

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

void DisplacementRes(){

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

    TH1F *hMuonDisplacementBias = new TH1F("hMuonDisplacementBias", "", 100, 0, 5);
    TH1F *hPionDisplacementBias = new TH1F("hPionDisplacementBias", "", 100, 0, 5);
    TH1F *hProtonDisplacementBias = new TH1F("hProtonDisplacementBias", "", 100, 0, 5);

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
            
            double trackLLRPID = e.TracklikePrimaryDaughters.at(i).Track_LLR_PID;
            double trackLength = e.TracklikePrimaryDaughters.at(i).TrackLength;
            double trackTrueMomentum = e.TracklikePrimaryDaughters.at(i).TrackTrueModMomentum;
            double trackMuonMomentum = e.TracklikePrimaryDaughters.at(i).MuonMomentum;
            double trackPionMomentum = PionMomentum(e.TracklikePrimaryDaughters.at(i).TrackLength);
            double trackDisplacement = e.TracklikePrimaryDaughters.at(i).Displacement;
            double trackMeandEdx = e.TracklikePrimaryDaughters.at(i).MeandEdX_ThreePlane;
            int trackPDG = e.TracklikePrimaryDaughters.at(i).TrackTruePDG;
            int trackIndex = e.TracklikePrimaryDaughters.at(i).Index;

            if(abs(trackPDG) == 13 && trackIndex == 0){ // 13 muon, 211 pion, 2212 proton
                hMuonDisplacementBias->Fill(trackDisplacement);
            } else if(abs(trackPDG) == 211 && trackIndex != 0){
                if(e.TracklikePrimaryDaughters.at(i).TrackTrueOrigin != 7) continue;
                hPionDisplacementBias->Fill(trackDisplacement);
            } else if(abs(trackPDG) == 2212 && trackIndex == 0){
                hProtonDisplacementBias->Fill(trackDisplacement);
            }
        }

    }

    double scaleMuonDispalcement = hMuonDisplacementBias->Integral() > 0 ? 1.0 / hMuonDisplacementBias->Integral() : 0;
    double scalePionDispalcement = hPionDisplacementBias->Integral() > 0 ? 1.0 / hPionDisplacementBias->Integral() : 0;
    double scaleProtonDispalcement = hProtonDisplacementBias->Integral() > 0 ? 1.0 / hProtonDisplacementBias->Integral() : 0;

    TCanvas *c1 = new TCanvas("c1", "", 800, 600);

    double width = 1.8;

    hMuonDisplacementBias->Scale(scaleMuonDispalcement);
    hPionDisplacementBias->Scale(scalePionDispalcement);
    hProtonDisplacementBias->Scale(scaleProtonDispalcement);

    hMuonDisplacementBias->SetLineColor(kBlue);
    hMuonDisplacementBias->SetLineStyle(1);
    hMuonDisplacementBias->SetLineWidth(width);

    hPionDisplacementBias->SetLineColor(kRed);
    hPionDisplacementBias->SetLineStyle(1);
    hPionDisplacementBias->SetLineWidth(width);

    hProtonDisplacementBias->SetLineColor(kGreen+2);
    hProtonDisplacementBias->SetLineStyle(1);
    hProtonDisplacementBias->SetLineWidth(width);

    hMuonDisplacementBias->SetStats(0);
    hMuonDisplacementBias->SetMaximum(0.05);
    hMuonDisplacementBias->SetMinimum(0);
    hMuonDisplacementBias->GetYaxis()->SetTitle("Arb. Units");
    hMuonDisplacementBias->GetXaxis()->SetTitle("Displacement (cm)");
    hMuonDisplacementBias->GetXaxis()->SetTitleSize(0.04);
    hMuonDisplacementBias->GetYaxis()->SetTitleSize(0.04);

    hMuonDisplacementBias->Draw("hist");
    hPionDisplacementBias->Draw("hist SAME");
    //hProtonDisplacementBias->Draw("hist SAME");

    TLegend *legend = new TLegend(0.3, 0.65, 0.4, 0.85);
    legend->AddEntry(hMuonDisplacementBias, "primtary #mu", "l");
    legend->AddEntry(hPionDisplacementBias, "secondary #pi", "l");

    legend->SetTextSize(0.03);
    legend->SetBorderSize(0); 
    legend->SetFillStyle(0);  
    legend->Draw();

    c1->SetLeftMargin(0.12);
    c1->SaveAs("displacement.png");

    E.Close();

}