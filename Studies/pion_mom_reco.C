R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so)
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so)

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

void pion_mom_reco(){

    //double POT = 1.25e21; // POT to scale samples to
    double POT = 1.5e21;

    BuildTunes();
    //SelectionParameters P = P_FHC_Tune_325_NoBDT;
    SelectionParameters P = P_RHC_Tune_397_NoBDT;

    std::string label = "background_rhc_track_multi";
    std::string SampleType = "background";

    EventAssembler E(false);
    SelectionManager M(P);

    //M.SetBeamMode(kFHC);
    M.SetBeamMode(kRHC);
    
    M.SetPOT(POT);
    M.UseFluxWeight(false);
    M.UseGenWeight(false);
    
    SampleNames.push_back("GENIE EXT");
    SampleTypes.push_back("EXT");
    SampleFiles.push_back("analysisOutputEXT_cthorpe_prod_extnumi_mcc9_v08_00_00_45_run3_run3b_reco2_all_reco2_pt1.root");

    SampleNames.push_back("GENIE Background");
    SampleTypes.push_back("Background");
    SampleFiles.push_back("analysisOutputRHC_GENIE_Overlay_Background_prodgenie_numi_uboone_overlay_rhc_mcc9_run3b_v28_v2_sample0.root");

    SampleNames.push_back("GENIE Dirt");
    SampleTypes.push_back("Dirt");
    SampleFiles.push_back("analysisOutputRHC_GENIE_Overlay_Dirt_prodgenie_numi_uboone_overlay_dirt_rhc_mcc9_run3b_v28_sample0.root");

    SampleNames.push_back("GENIE kaon");
    SampleTypes.push_back("Kaon");
    SampleFiles.push_back("analysisOutputRHC_GENIE_Overlay_Kaon_cthorpe_make_k0s_events_numi_rhc_reco2_REAL_reco2_reco2.root");

    SampleNames.push_back("EXT run3");
    SampleTypes.push_back("EXT");
    SampleFiles.push_back("analysisOutputEXT_cthorpe_prod_extnumi_mcc9_v08_00_00_45_run3_run3b_reco2_all_reco2_pt1.root");

    SampleNames.push_back("EXT run1");
    SampleTypes.push_back("EXT");
    SampleFiles.push_back("analysisOutputEXT_cthorpe_prod_mcc9_v08_00_00_45_extnumi_reco2_run1_all_reco2_pt1.root");

    SampleNames.push_back("GENIE Background");
    SampleTypes.push_back("Background");
    SampleFiles.push_back("analysisOutputFHC_GENIE_Overlay_Background_prodgenie_numi_uboone_overlay_fhc_mcc9_run1_v28_v2_sample0.root");

    SampleNames.push_back("GENIE Dirt");
    SampleTypes.push_back("Dirt");
    SampleFiles.push_back("analysisOutputRHC_GENIE_Overlay_Dirt_prodgenie_numi_uboone_overlay_dirt_rhc_mcc9_run3b_v28_sample0.root");

    SampleNames.push_back("GENIE kaon");
    SampleTypes.push_back("Kaon");
    SampleFiles.push_back("analysisOutputFHC_Overlay_GENIE_Kaon_cthorpe_make_k0s_events_numi_fhc_reco2_reco2_reco2.root");

    SampleNames.push_back("EXT run3");
    SampleTypes.push_back("EXT");
    SampleFiles.push_back("analysisOutputEXT_cthorpe_prod_extnumi_mcc9_v08_00_00_45_run3_run3b_reco2_all_reco2_pt1.root");

    SampleNames.push_back("EXT run1");
    SampleTypes.push_back("EXT");
    SampleFiles.push_back("analysisOutputEXT_cthorpe_prod_mcc9_v08_00_00_45_extnumi_reco2_run1_all_reco2_pt1.root");

    SampleNames.push_back("Neutron");
    SampleTypes.push_back("Neutron");
    SampleFiles.push_back("analysisOutputFHC_GENIE_Overlay_Neutron_cthorpe_numi_run1_fhc_neutron.root");

    TH2F *hMuonMom = new TH2F("hMuonMom", "", 200, 0, 200, 200, 0, 1); 

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

            for(size_t i = 0; i < e.TracklikePrimaryDaughters.size(); i++){

                double trackLength = e.TracklikePrimaryDaughters.at(i).TrackLength;
                double trackTrueMomentum = e.TracklikePrimaryDaughters.at(i).TrackTrueModMomentum;
                double trackPionMomentum = PionMomentum(e.TracklikePrimaryDaughters.at(i).TrackLength);
                int trackPDG = e.TracklikePrimaryDaughters.at(i).TrackTruePDG;

                if(abs(trackPDG) == 211){ // 13 muon, 211 pion, 2212 proton
                    hMuonMom->Fill(trackLength, trackTrueMomentum);
                }
            }      

        }
    }
    // Function for pion momentum
    TF1 *pionMomentumFunc = new TF1("", "0.25798 + 0.0024088*x - 0.18828*pow(x,-0.11687)", 0, 200);

    // Set line color and style
    pionMomentumFunc->SetLineColor(kRed);
    pionMomentumFunc->SetLineStyle(1);

    TCanvas *canvas = new TCanvas("", "", 800, 600);
    // Draw the function on the same canvas
    hMuonMom->Draw("COLZ");
    hMuonMom->SetStats(0);
    hMuonMom->GetXaxis()->SetTitleSize(HypPlot::Single_XaxisTitleSize);
    hMuonMom->GetYaxis()->SetTitleSize(HypPlot::Single_YaxisTitleSize);
    hMuonMom->GetXaxis()->SetTitleOffset(HypPlot::Single_XaxisTitleOffset);
    hMuonMom->GetYaxis()->SetTitleOffset(HypPlot::Single_YaxisTitleOffset);
    hMuonMom->GetXaxis()->SetLabelSize(HypPlot::Single_XaxisLabelSize);
    hMuonMom->GetYaxis()->SetLabelSize(HypPlot::Single_YaxisLabelSize);
    hMuonMom->GetYaxis()->SetTitle("True Pion Momentum (GeV/c)");
    hMuonMom->GetXaxis()->SetTitle("Reconstructed Track Length (cm)");

    pionMomentumFunc->Draw("same");

    canvas->SaveAs("Plots/muon_mom.png");
    canvas->Close();

    E.Close();
}