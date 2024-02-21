R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so)
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so)

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

struct PurityStatistics {
    double trueSignal = 0; 
    double totalSelected = 0; 
};

// Functions to update purity statistics
void updateTrueSignal(PurityStatistics& stats, double weight) {
    stats.trueSignal += weight;
}

void updateTotalSelected(PurityStatistics& stats, double weight) {
    stats.totalSelected += weight;
}

void cut_purity(){

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

    M.SetPOT(POT);
    M.UseFluxWeight(false);
    M.UseGenWeight(false);

    //E.SetFile("analysisOutputFHC_Overlay_GENIE_Kaon_cthorpe_make_k0s_events_numi_fhc_reco2_reco2_reco2.root",  "signal");
    //E.SetFile("analysisOutputRHC_GENIE_Overlay_Kaon_cthorpe_make_k0s_events_numi_rhc_reco2_REAL_reco2_reco2.root", "signal");
    //M.AddSample("Signal", "Signal", E.GetPOT());

    std::vector<std::map<std::string, PurityStatistics>> purityStatsFVCut(EventType::PureKaonSampleTypes.size());
    std::vector<std::map<std::string, PurityStatistics>> purityStatsTrackCut(EventType::PureKaonSampleTypes.size());
    std::vector<std::map<std::string, PurityStatistics>> purityStatsShowerCut(EventType::PureKaonSampleTypes.size());
    std::vector<std::map<std::string, PurityStatistics>> purityStatsMuonIdentifCut(EventType::PureKaonSampleTypes.size());
    std::vector<std::map<std::string, PurityStatistics>> purityStatsChoosePionPairCut(EventType::PureKaonSampleTypes.size());

    SampleNames.push_back("GENIE Background");
    SampleTypes.push_back("Background");
    SampleFiles.push_back("analysisOutputRHC_GENIE_Overlay_Background_prodgenie_numi_uboone_overlay_rhc_mcc9_run3b_v28_v2_sample0.root");

    SampleNames.push_back("GENIE Dirt");
    SampleTypes.push_back("Dirt");
    SampleFiles.push_back("analysisOutputRHC_GENIE_Overlay_Dirt_prodgenie_numi_uboone_overlay_dirt_rhc_mcc9_run3b_v28_sample0.root");

    SampleNames.push_back("GENIE Signal");
    SampleTypes.push_back("Signal");
    SampleFiles.push_back("analysisOutputRHC_GENIE_Overlay_Kaon_cthorpe_make_k0s_events_numi_rhc_reco2_REAL_reco2_reco2.root");

    for(size_t i_s=0;i_s<SampleNames.size();i_s++){

        E.SetFile(SampleFiles.at(i_s), SampleTypes.at(i_s));
        if(SampleTypes.at(i_s) != "EXT" && SampleTypes.at(i_s) != "Data") M.AddSample(SampleNames.at(i_s),SampleTypes.at(i_s),E.GetPOT());
        else if(SampleTypes.at(i_s) == "Data") M.AddSample(SampleNames.at(i_s),SampleTypes.at(i_s),Data_POT);
        else if(SampleTypes.at(i_s) == "EXT") M.AddSample(SampleNames.at(i_s),SampleTypes.at(i_s),EXT_POT);

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

            passed_FV = M.FiducialVolumeCut(e);
            passed_track = M.TrackCut(e);
            passed_shower = M.ShowerCut(e);
            passed_muon = M.ChooseMuonCandidate(e);
            passed_pion_pair = M.ChoosePionPairCandidates(e, true);

            std::string kaonType = EventType::GetPureKaonType(e); 

            for (size_t j = 0; j < EventType::PureKaonSampleTypes.size(); ++j) {
                if (kaonType == EventType::PureKaonSampleTypes[j]) {
                    if (passed_FV){
                        updateTotalSelected(purityStatsFVCut[j][kaonType], e.Weight);
                        if (e.EventIsSignal) updateTrueSignal(purityStatsFVCut[j][kaonType], e.Weight);
                    }
                    if (passed_FV && passed_track){
                        updateTotalSelected(purityStatsTrackCut[j][kaonType], e.Weight);
                        if (e.EventIsSignal) updateTrueSignal(purityStatsTrackCut[j][kaonType], e.Weight);
                    }
                    if (passed_FV && passed_track && passed_shower){
                        updateTotalSelected(purityStatsShowerCut[j][kaonType], e.Weight);
                        if (e.EventIsSignal) updateTrueSignal(purityStatsShowerCut[j][kaonType], e.Weight);
                    }
                    if (passed_FV && passed_track && passed_shower && passed_muon){
                        updateTotalSelected(purityStatsMuonIdentifCut[j][kaonType], e.Weight);
                        if (e.EventIsSignal) updateTrueSignal(purityStatsMuonIdentifCut[j][kaonType], e.Weight);
                    }
                    if (passed_FV && passed_track && passed_shower && passed_muon && passed_pion_pair && e.GoodReco){
                        updateTotalSelected(purityStatsChoosePionPairCut[j][kaonType], e.Weight);
                        if (e.EventIsSignal) updateTrueSignal(purityStatsChoosePionPairCut[j][kaonType], e.Weight);
                    }
                }
            }
        }
    }
    
    E.Close();

    gStyle->SetOptStat(0);
    gStyle->SetTitleFontSize(0.05);

    const int nCuts = 5;
    TCanvas *c1 = new TCanvas("c1", "", 800, 600);
    c1->SetLogy();
    c1->SetLeftMargin(0.12);  
    c1->SetRightMargin(0.05); 
    c1->SetBottomMargin(0.12);

    TH1F *frame = new TH1F("", "", nCuts, 0, nCuts);
    frame->SetMinimum(0.001);
    frame->SetMaximum(1);
    frame->GetXaxis()->SetBinLabel(1, "In FV");
    frame->GetXaxis()->SetBinLabel(2, "Track Cut");
    frame->GetXaxis()->SetBinLabel(3, "Shower Cut");
    frame->GetXaxis()->SetBinLabel(4, "Muon Identif.");
    frame->GetXaxis()->SetBinLabel(5, "Pion Pair Selec.");
    frame->GetXaxis()->SetTitleSize(0.04); 
    frame->GetXaxis()->SetLabelSize(0.04);
    frame->GetYaxis()->SetTitle("Efficiency");
    frame->GetYaxis()->SetTitleSize(0.04); 
    frame->GetYaxis()->SetTitleOffset(1.2); 
    frame->GetYaxis()->SetLabelSize(0.03); 
    frame->Draw();

    double xValues[nCuts] = {0.5, 1.5, 2.5, 3.5, 4.5};
    TLegend *legend = new TLegend(0.15, 0.15, 0.35, 0.55);

    for (size_t j = 0; j < EventType::PureKaonSampleTypes.size(); ++j) {
        std::string eventType = EventType::PureKaonSampleTypes[j];

        std::cout << purityStatsFVCut[j][eventType].trueSignal << std::endl;
        std::cout << purityStatsFVCut[j][eventType].totalSelected << std::endl;

        double purFV = purityStatsFVCut[j][eventType].trueSignal / purityStatsFVCut[j][eventType].totalSelected;
        double purTrack = purityStatsTrackCut[j][eventType].trueSignal / purityStatsTrackCut[j][eventType].totalSelected;
        double purShower = purityStatsShowerCut[j][eventType].trueSignal / purityStatsShowerCut[j][eventType].totalSelected;
        double purMuon = purityStatsMuonIdentifCut[j][eventType].trueSignal / purityStatsMuonIdentifCut[j][eventType].totalSelected;
        double purPionPair = purityStatsChoosePionPairCut[j][eventType].trueSignal / purityStatsChoosePionPairCut[j][eventType].totalSelected;

        std::cout << purFV << purTrack << purPionPair << std::endl;
        
        double purities[nCuts] = {purFV, purTrack, purShower, purMuon, purPionPair};
        
        TGraph *graph = new TGraph(nCuts, xValues, purities);
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
    c1->SaveAs("Plots/cut_purities.png");

}