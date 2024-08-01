R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so);
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so);

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

void plot_invariant_mass_var(){

    double POT = 1.5e21;

    BuildTunes();
    SelectionParameters P = P_RHC_Tune_397_NoBDT;

    std::string label = "test";
    std::string SampleType = "Kaon";

    EventAssembler E(false);
    SelectionManager M(P);
    M.ImportSelectorBDTWeights("/exp/uboone/app/users/nlane/NeutralKaonAnalysis/TMVA/SelectorMVA/dataset/weights");

    M.SetBeamMode(kRHC);

    M.SetPOT(POT);
    M.UseFluxWeight(false);
    M.UseGenWeight(false);

    E.SetFile("analysisOutputRHC_GENIE_Overlay_Kaon_cthorpe_make_k0s_events_numi_rhc_reco2_REAL_reco2_reco2.root", "Kaon");
    M.AddSample("Kaon","Kaon",E.GetPOT());

    TH1F *hPionMomBias = new TH1F("hPionMomBias", "", 50, -1, 1);

    for(int i = 0; i < E.GetNEvents(); i++){

        if(i % 10000 == 0) std::cout << i << "/" << E.GetNEvents() << std::endl;

        Event e = E.GetEvent(i);

        M.SetSignal(e);                
        M.AddEvent(e);

        if(!e.EventIsSignal) continue;

        bool passed_FV, passed_muon, passed_track, passed_pion, passed_WCut, passed_connected = false;

        passed_FV = M.FiducialVolumeCut(e);
        if(!passed_FV) continue;
        passed_track = M.TrackCut(e);
        if(!passed_track) continue;
        passed_pion = M.ChoosePionPairCandidates(e);
        if(!passed_pion) continue;

        bool correct_pair = false;

        for(size_t i_tr = 0; i_tr < e.TracklikePrimaryDaughters.size(); i_tr++){
            for(size_t j_tr = 0; j_tr < e.TracklikePrimaryDaughters.size(); j_tr++){

                if(i_tr == j_tr) continue;
                if(e.TracklikePrimaryDaughters.at(i_tr).Index == e.TrueDecayPionPlusIndex && e.TracklikePrimaryDaughters.at(j_tr).Index == e.TrueDecayPionMinusIndex){
                    correct_pair = true;
                }
            }
        }

        if(!correct_pair) continue;

        double pionplusmom = PionMomentum(e.DecayPionPlusCandidate.TrackLength);
        double residual = (pionplusmom - e.DecayPionPlusCandidate.TrackTrueModMomentum) / e.DecayPionPlusCandidate.TrackTrueModMomentum;

        hPionMomBias->Fill(residual);
    }

    double scalepionmom = hPionMomBias->Integral() > 0 ? 1.0 / hPionMomBias->Integral() : 0;
   
    TCanvas *c1 = new TCanvas("c1", "", 800, 600);

    double width = 1.8;

    hPionMomBias->Scale(scalepionmom);

    hPionMomBias->SetLineColor(kAzure - 1);
    hPionMomBias->SetLineStyle(1);
    hPionMomBias->SetLineWidth(width);

    hPionMomBias->SetStats(0);
    //hPionMomBias->SetMaximum(0.25);
    hPionMomBias->SetMinimum(0);
    hPionMomBias->GetYaxis()->SetTitle("");
    hPionMomBias->GetXaxis()->SetTitle("(p_{#pi, reco} - p_{#pi, true}) / p_{#pi, true}");
    hPionMomBias->GetXaxis()->SetTitleSize(0.04);
    hPionMomBias->GetYaxis()->SetTitleSize(0.04);
    hPionMomBias->GetXaxis()->SetTitleOffset(1.15);
    hPionMomBias->GetYaxis()->SetTitleOffset(1.3);
    hPionMomBias->GetXaxis()->SetLabelSize(0.04);
    hPionMomBias->GetYaxis()->SetLabelSize(0.04);

    hPionMomBias->Draw("hist");
    c1->SaveAs("Plots/pion_momentum_bias.png");

    E.Close();
}