R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so)
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so)

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

void pion_proton_plot(){

    double POT = 1.25e21; // POT to scale samples to
    //double POT = 1.5e21;

    BuildTunes();
    SelectionParameters P = P_FHC_Tune_325_NoBDT;
    //SelectionParameters P = P_RHC_Tune_397_NoBDT;

    std::string label = "shower_track";
    std::string SampleType = "pure_kaon";

    EventAssembler E(false);
    SelectionManager M(P);

    M.SetBeamMode(kFHC);
    //M.SetBeamMode(kRHC);
    
    M.SetPOT(POT);
    M.UseFluxWeight(false);
    M.UseGenWeight(false);

    E.SetFile("analysisOutputFHC_Overlay_GENIE_Kaon_cthorpe_make_k0s_events_numi_fhc_reco2_reco2_reco2.root",  "signal");
    //E.SetFile("analysisOutputRHC_GENIE_Overlay_Kaon_cthorpe_make_k0s_events_numi_rhc_reco2_REAL_reco2_reco2.root", "signal");
    //E.SetFile("/pnfs/uboone/scratch/users/cthorpe/hyperon_tree/v08_00_00_51/process_dataset_data_cthorpe_prod_mcc9_v08_00_00_45_extnumi_reco2_run1_all_reco2_pt1/out/0/7772218_0/HyperonTrees.root", "signal");
    M.AddSample("Signal", "Signal", E.GetPOT());

    TH2D *hShowerTrack = new TH2D("", "", 3, 0, 3, 3, 0, 3);

    for(int i = 0; i < E.GetNEvents(); i++){

        if(i % 10000 == 0) std::cout << i << "/" << E.GetNEvents() << std::endl;

        Event e = E.GetEvent(i);

        M.SetSignal(e);                
        M.AddEvent(e);

        bool passed_FV = false;

        passed_FV = M.FiducialVolumeCut(e);
        if(!passed_FV) continue;

        if(!e.EventIsSignal) continue;

        hShowerTrack->Fill(e.PrimaryNucleon.size(),e.PrimaryPion.size());
                 
    }

    gStyle->SetPaintTextFormat(".2f");

    TCanvas *canvas = new TCanvas("canvas", "Matrix Plot", 800, 600);
    hShowerTrack->Scale(1.0 / hShowerTrack->GetEntries()); // Normalize by total number of entries.
    hShowerTrack->GetXaxis()->SetTitle("Nucleon Multiplicity");
    hShowerTrack->GetYaxis()->SetTitle("Pion Multiplicity");
    hShowerTrack->GetXaxis()->SetTitleSize(HypPlot::Single_XaxisTitleSize);
    hShowerTrack->GetYaxis()->SetTitleSize(HypPlot::Single_YaxisTitleSize);
    hShowerTrack->GetXaxis()->SetTitleOffset(HypPlot::Single_XaxisTitleOffset);
    hShowerTrack->GetYaxis()->SetTitleOffset(1.0);
    hShowerTrack->GetXaxis()->SetLabelSize(HypPlot::Single_XaxisLabelSize);
    hShowerTrack->GetYaxis()->SetLabelSize(HypPlot::Single_YaxisLabelSize);

    hShowerTrack->GetXaxis()->SetNdivisions(505);
    hShowerTrack->GetYaxis()->SetNdivisions(505);

    // Remove the statistics box
    hShowerTrack->SetStats(0);
    hShowerTrack->SetMarkerSize(1.8);
    hShowerTrack->SetMarkerColor(kRed);
    hShowerTrack->Draw("COL TEXT");
    canvas->Draw();
    canvas->SaveAs("proton_pion_plot.png");
    
    E.Close();

}