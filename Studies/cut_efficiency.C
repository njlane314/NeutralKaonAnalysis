R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so)
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so)

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

struct Statistics {
    double numerator = 0;
    double denominator = 0;
};

// Update functions for the Statistics structure
void updateNumerator(Statistics& stats) {
    stats.numerator += 1;
}

void updateDenominator(Statistics& stats) {
    stats.denominator += 1;
}

void cut_efficiency(){

    //double POT = 1.25e21; // POT to scale samples to
    double POT = 1.5e21;

    BuildTunes();
    //SelectionParameters P = P_FHC_Tune_325_NoBDT;
    SelectionParameters P = P_RHC_Tune_397_NoBDT;

    std::string label = "signal";
    std::string SampleType = "pureKaon";

    EventAssembler E(false);
    SelectionManager M(P);

    //M.SetBeamMode(kFHC);
    M.SetBeamMode(kRHC);

    M.ImportSelectorBDTWeights("/exp/uboone/app/users/nlane/NeutralKaonAnalysis/TMVA/SelectorMVA/dataset/weights");

    M.SetPOT(POT);
    M.UseFluxWeight(false);
    M.UseGenWeight(false);

    //E.SetFile("analysisOutputFHC_Overlay_GENIE_Kaon_cthorpe_make_k0s_events_numi_fhc_reco2_reco2_reco2.root",  "signal");
    E.SetFile("analysisOutputRHC_GENIE_Overlay_Kaon_cthorpe_make_k0s_events_numi_rhc_reco2_REAL_reco2_reco2.root", "signal");
    M.AddSample("Signal", "Signal", E.GetPOT());

    std::vector<std::map<std::string, Statistics>> effStatsFVCut(EventType::PureKaonSampleTypes.size());
    std::vector<std::map<std::string, Statistics>> effStatsTrackCut(EventType::PureKaonSampleTypes.size());
    std::vector<std::map<std::string, Statistics>> effStatsMuonIdentifCut(EventType::PureKaonSampleTypes.size());
    std::vector<std::map<std::string, Statistics>> effStatsChoosePionPairCut(EventType::PureKaonSampleTypes.size());

    for(int i = 0; i < E.GetNEvents(); i++){

        if(i % 10000 == 0) std::cout << i << "/" << E.GetNEvents() << std::endl;

        Event e = E.GetEvent(i);

        M.SetSignal(e);                
        M.AddEvent(e);

        bool passed_FV = false;
        bool passed_track = false;
        bool passed_muon = false;
        bool passed_pion_pair = false;

        passed_FV = M.FiducialVolumeCut(e);
        if(passed_FV) passed_track = M.TrackCut(e);
        if(passed_track) passed_muon = M.ChooseMuonCandidate(e);
        if(passed_muon) passed_pion_pair = M.ChoosePionPairCandidates(e);

        std::string kaonType = EventType::GetPureKaonType(e); 

        for (size_t j = 0; j < 4; ++j) {
            if (kaonType == EventType::PureKaonSampleTypes[j]) {
                updateDenominator(effStatsFVCut[j][kaonType]);
                if (passed_FV) updateNumerator(effStatsFVCut[j][kaonType]);

                updateDenominator(effStatsTrackCut[j][kaonType]);
                if (passed_FV && passed_track) updateNumerator(effStatsTrackCut[j][kaonType]);

                updateDenominator(effStatsMuonIdentifCut[j][kaonType]);
                if (passed_FV && passed_track && passed_muon) updateNumerator(effStatsMuonIdentifCut[j][kaonType]);

                updateDenominator(effStatsChoosePionPairCut[j][kaonType]);
                if (passed_FV && passed_track && passed_muon && passed_pion_pair && e.GoodReco) updateNumerator(effStatsChoosePionPairCut[j][kaonType]);
            }
        }
    }
    
    E.Close();

    gStyle->SetOptStat(0);
    gStyle->SetTitleFontSize(0.05);

    const int nCuts = 4;
    TCanvas *c1 = new TCanvas("c1", "", 800, 600);
    c1->SetLogy();
    c1->SetLeftMargin(0.12);  // Adjust left margin
    c1->SetRightMargin(0.05); // Adjust right margin
    c1->SetBottomMargin(0.12); // Adjust bottom margin

    TH1F *frame = new TH1F("", "", nCuts, 0, nCuts);
    frame->SetMinimum(0.04);
    frame->SetMaximum(1);
    frame->GetXaxis()->SetBinLabel(1, "In FV");
    frame->GetXaxis()->SetBinLabel(2, "Track Cut");
    frame->GetXaxis()->SetBinLabel(3, "Muon Identif");
    frame->GetXaxis()->SetBinLabel(4, "Pion Pair Selec.");
    frame->GetXaxis()->SetTitleSize(0.04); // Increase x-axis title size
    frame->GetXaxis()->SetLabelSize(0.04);
    frame->GetYaxis()->SetTitle("Signal Efficiency");
    frame->GetYaxis()->SetTitleSize(0.04); // Increase y-axis title size
    frame->GetYaxis()->SetTitleOffset(1.2); // Adjust y-axis title position
    frame->GetYaxis()->SetLabelSize(0.03); // Increase y-axis label size
    frame->Draw();

    double xValues[nCuts] = {0.5, 1.5, 2.5, 3.5};
    TLegend *legend = new TLegend(0.15, 0.15, 0.35, 0.35);

    for (size_t j = 0; j < 4; ++j) {
        std::string eventType = EventType::PureKaonSampleTypes[j];

        double effFV = effStatsFVCut[j][eventType].numerator / effStatsFVCut[j][eventType].denominator;
        double effTrack = effStatsTrackCut[j][eventType].numerator / effStatsTrackCut[j][eventType].denominator;
        double effMuon = effStatsMuonIdentifCut[j][eventType].numerator / effStatsMuonIdentifCut[j][eventType].denominator;
        double effPionPair = effStatsChoosePionPairCut[j][eventType].numerator / effStatsChoosePionPairCut[j][eventType].denominator;

        double relEffTrack = effStatsTrackCut[j][eventType].numerator / effStatsFVCut[j][eventType].numerator;
        double relEffMuon = effStatsMuonIdentifCut[j][eventType].numerator / effStatsTrackCut[j][eventType].numerator;

        std::cout << eventType << std::endl;
        std::cout << effFV << std::endl;
        std::cout << relEffTrack << std::endl;
        std::cout << relEffMuon << std::endl << std::endl;
        
        double efficiencies[nCuts] = {effFV, effTrack, effMuon, effPionPair};
        
        TGraph *graph = new TGraph(nCuts, xValues, efficiencies);
        graph->SetMarkerColor(EventType::PureKaonSampleColours[j]);
        graph->SetMarkerStyle(21); 
        graph->SetLineColor(EventType::PureKaonSampleColours[j]); 
        graph->SetLineWidth(2); 
        graph->Draw("PL"); 

        legend->AddEntry(graph, EventType::PureKaonSampleCaptions[j].c_str(), "lp");
    }

    legend->SetTextSize(0.03);
    legend->SetBorderSize(0); 
    legend->SetFillStyle(0);  
    legend->Draw();
    c1->SaveAs("Plots/cut_efficiencies.png");

}