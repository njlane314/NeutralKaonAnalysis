R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so)
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so)

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

void plot_shower_track(){

    //double POT = 1.25e21; // POT to scale samples to
    double POT = 1.5e21;

    BuildTunes();
    //SelectionParameters P = P_FHC_Tune_325_NoBDT;
    SelectionParameters P = P_RHC_Tune_397_NoBDT;

    std::string label = "shower_track";
    std::string SampleType = "pure_kaon";

    EventAssembler E(false);
    SelectionManager M(P);

    //M.SetBeamMode(kFHC);
    M.SetBeamMode(kRHC);
    
    M.SetPOT(POT);
    M.UseFluxWeight(false);
    M.UseGenWeight(false);

    //E.SetFile("analysisOutputFHC_Overlay_GENIE_Kaon_cthorpe_make_k0s_events_numi_fhc_reco2_reco2_reco2.root",  "Kaon");
    E.SetFile("analysisOutputRHC_GENIE_Overlay_Kaon_cthorpe_make_k0s_events_numi_rhc_reco2_REAL_reco2_reco2.root", "Kaon");
    M.AddSample("Kaon", "Kaon", E.GetPOT());

    TH2D *hShowerTrack = new TH2D("", "", 10, 0, 10, 8, 0, 8);

    for(int i = 0; i < E.GetNEvents(); i++){

        if(i % 10000 == 0) std::cout << i << "/" << E.GetNEvents() << std::endl;

        Event e = E.GetEvent(i);

        M.SetSignal(e);                
        M.AddEvent(e);

        if(!e.EventIsSignal) continue;
        if(!(EventType::GetPureKaonType(e) == "SignalNuMuCCKaonHyperon")) continue;

        bool passed_FV = false;

        passed_FV = M.FiducialVolumeCut(e);
        if(!passed_FV) continue;

        //if(!e.GoodReco) continue;

        hShowerTrack->Fill(e.NPrimaryTrackDaughters,e. NPrimaryShowerDaughters);
                 
    }

    gStyle->SetPaintTextFormat(".2f");

    TCanvas *canvas = new TCanvas("canvas", "Matrix Plot", 800, 600);
    hShowerTrack->Scale(1.0 / hShowerTrack->GetEntries()); // Normalize by total number of entries.
    hShowerTrack->GetXaxis()->SetTitle("Track Multiplicity");
    hShowerTrack->GetYaxis()->SetTitle("Shower Multiplicity");
    hShowerTrack->GetXaxis()->SetTitleSize(HypPlot::Single_XaxisTitleSize);
    hShowerTrack->GetYaxis()->SetTitleSize(HypPlot::Single_YaxisTitleSize);
    hShowerTrack->GetXaxis()->SetTitleOffset(HypPlot::Single_XaxisTitleOffset);
    hShowerTrack->GetYaxis()->SetTitleOffset(1.0);
    hShowerTrack->GetXaxis()->SetLabelSize(HypPlot::Single_XaxisLabelSize);
    hShowerTrack->GetYaxis()->SetLabelSize(HypPlot::Single_YaxisLabelSize);

    // Remove the statistics box
    hShowerTrack->SetStats(0);
    hShowerTrack->SetMarkerSize(1.3);
    hShowerTrack->SetMarkerColor(kRed);
    hShowerTrack->Draw("COL TEXT");
    canvas->Draw();
    canvas->SaveAs("matrix_plot.png");
    
    E.Close();

}