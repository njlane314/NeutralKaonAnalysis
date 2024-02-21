R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so);
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so);

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

void proton_mom_LLR(){

    double POT = 1.25e21; // POT to scale samples to
    //double POT = 1.5e21;

    BuildTunes();
    SelectionParameters P = P_FHC_Tune_325_NoBDT;
    //SelectionParameters P = P_RHC_Tune_397_NoBDT;

    std::string label = "proton_mom_LLR";
    std::string SampleType = "pure_kaon";

    EventAssembler E(false);
    SelectionManager M(P);

    M.SetBeamMode(kFHC);
    //M.SetBeamMode(kRHC);
    
    M.SetPOT(POT);
    M.UseFluxWeight(false);
    M.UseGenWeight(false);

    //E.SetFile("analysisOutputFHC_Overlay_GENIE_Kaon_cthorpe_make_k0s_events_numi_fhc_reco2_reco2_reco2.root",  "signal");
    //E.SetFile("analysisOutputRHC_GENIE_Overlay_Kaon_cthorpe_make_k0s_events_numi_rhc_reco2_REAL_reco2_reco2.root", "signal");
    //M.AddSample("Signal", "Signal", E.GetPOT());

    TH2F *hProtonMomLLR = new TH2F("hProtonMomLLR", ";True Muon Momentum (GeV/c);LLR PID Score", 
                    200, 0, 2, 200, -1, 1);

    SampleNames.push_back("GENIE Background");
    SampleTypes.push_back("Background");
    SampleFiles.push_back("analysisOutputRHC_GENIE_Overlay_Background_prodgenie_numi_uboone_overlay_rhc_mcc9_run3b_v28_v2_sample0.root");

    SampleNames.push_back("GENIE Dirt");
    SampleTypes.push_back("Dirt");
    SampleFiles.push_back("analysisOutputRHC_GENIE_Overlay_Dirt_prodgenie_numi_uboone_overlay_dirt_rhc_mcc9_run3b_v28_sample0.root");

    SampleNames.push_back("GENIE Kaon FHC");
    SampleTypes.push_back("Signal FHC");
    SampleFiles.push_back("analysisOutputFHC_Overlay_GENIE_Kaon_cthorpe_make_k0s_events_numi_fhc_reco2_reco2_reco2.root");

    SampleNames.push_back("GENIE Kaon RHC");
    SampleTypes.push_back("Signal RHC");
    SampleFiles.push_back("analysisOutputRHC_GENIE_Overlay_Kaon_cthorpe_make_k0s_events_numi_rhc_reco2_REAL_reco2_reco2.root");

    for(size_t i_s=0;i_s<SampleNames.size();i_s++){

        E.SetFile(SampleFiles.at(i_s), SampleTypes.at(i_s));

        for(int i = 0; i < E.GetNEvents(); i++){

            if(i % 10000 == 0) std::cout << i << "/" << E.GetNEvents() << std::endl;

            Event e = E.GetEvent(i);

            M.SetSignal(e);                
            M.AddEvent(e);

            for(size_t i_tr = 0; i_tr < e.TracklikePrimaryDaughters.size(); i_tr++){
                if(abs(e.TracklikePrimaryDaughters.at(i_tr).TrackTruePDG) == 13 && e.TracklikePrimaryDaughters.at(i_tr).HasTruth){
                    hProtonMomLLR->Fill(e.TracklikePrimaryDaughters.at(i_tr).TrackTrueModMomentum, e.TracklikePrimaryDaughters.at(i_tr).Track_LLR_PID);
                }
            }
            
        }
    }

    TCanvas *canvas = new TCanvas("", "", 800, 600);
    hProtonMomLLR->Draw("COLZ");
    hProtonMomLLR->SetStats(0);
    hProtonMomLLR->GetXaxis()->SetTitleSize(HypPlot::Single_XaxisTitleSize);
    hProtonMomLLR->GetYaxis()->SetTitleSize(HypPlot::Single_YaxisTitleSize);
    hProtonMomLLR->GetXaxis()->SetTitleOffset(HypPlot::Single_XaxisTitleOffset);
    hProtonMomLLR->GetYaxis()->SetTitleOffset(HypPlot::Single_YaxisTitleOffset);
    hProtonMomLLR->GetXaxis()->SetLabelSize(HypPlot::Single_XaxisLabelSize);
    hProtonMomLLR->GetYaxis()->SetLabelSize(HypPlot::Single_YaxisLabelSize);
    canvas->SaveAs("Plots/proton_mom_LLR.png");
    canvas->Close();

    E.Close();

}