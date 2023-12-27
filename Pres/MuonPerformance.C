R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so);
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so);

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

void MuonPerformance(){

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
    
    E.SetFile("analysisOutputFHC_Overlay_GENIE_Kaon_cthorpe_make_k0s_events_numi_fhc_reco2_reco2_reco2.root", "Background");
    M.AddSample("Background","Background",E.GetPOT());

    TEfficiency* pMuonIdentifier = new TEfficiency("pMuonIdentifier", ";Muon Momentum (GeV/c); Entries/bin", 20, 0, 2);

    int nbins = 120;
    double xstart = 0.;
    double xfinish = 600.;
    double ymax = 1000;
    double ymin = 10;
    const char* xaxistitle = "Reconstructed Displacement (cm)";
    const char* yaxistitle = "Tracks/bin";
    TH1F *hMuon = new TH1F("hMuon", "", nbins, xstart, xfinish);
    TH1F *hChargedPion = new TH1F("hChargedPion", "", nbins, xstart, xfinish);
    TH1F *hProton = new TH1F("hProton", "", nbins, xstart, xfinish);
    TH1F *hElectron = new TH1F("hElectron", "", nbins, xstart, xfinish);
    TH1F *hSigmaPlus = new TH1F("hSigmaPlus", "", nbins, xstart, xfinish);
    TH1F *hSigmaMinus = new TH1F("hSigmaMinus", "", nbins, xstart, xfinish);
    TH1F *hOther = new TH1F("hOther", "", nbins, xstart, xfinish);

    for(int i = 0; i < E.GetNEvents(); i++){
        if(i % 10000 == 0) std::cout << i << "/" << E.GetNEvents() << std::endl;

        Event e = E.GetEvent(i);

        M.SetSignal(e);                
        M.AddEvent(e);

        if(!e.EventIsSignal) continue;

        bool passed_FV = false;
        bool passed_Tracks = false;
        bool passed_Muon_Identifier = false;

        bool passed_All = false;

        passed_FV = M.FiducialVolumeCut(e);
        if(passed_FV) passed_Tracks = M.TrackCut(e);
        if(passed_Tracks) passed_Muon_Identifier = M.ChooseMuonCandidate(e);
 
        passed_All = passed_Muon_Identifier;

        pMuonIdentifier->FillWeighted(passed_All, e.Weight, e.MuonCandidate.MuonMomentum);

        if(!passed_All) continue;

        int i_longest = -1;
        int length = -1;
        for(size_t i = 0; i < e.TracklikePrimaryDaughters.size(); i++){
            double trackPID = e.TracklikePrimaryDaughters.at(i).Track_LLR_PID;
            double trackLength = e.TracklikePrimaryDaughters.at(i).TrackLength;
            double trackDisplacement = e.TracklikePrimaryDaughters.at(i).Displacement;
            int trackPDG = e.TracklikePrimaryDaughters.at(i).TrackTruePDG;

            //if(trackPID < 0.9 || trackLength < 100 || trackDisplacement > 10) continue;
            if(trackPID < 0.9) continue;
            if(trackLength > length){
                length = trackLength;
                i_longest = i;
            }
        }

        if(i_longest == -1) continue;

        double longestPDG = e.TracklikePrimaryDaughters.at(i_longest).TrackTruePDG;
        double trackFill = e.TracklikePrimaryDaughters.at(i_longest).TrackLength;
        if(abs(longestPDG) == 13){
            hMuon->Fill(trackFill);
        }
        else if(abs(longestPDG) == 211){
            hChargedPion->Fill(trackFill);
        }
        else if(abs(longestPDG) == 2212){
            hProton->Fill(trackFill);
        }
        else if(abs(longestPDG) == 11){
            hElectron->Fill(trackFill);
        }
        else if(abs(longestPDG) == 3222){
            hSigmaPlus->Fill(trackFill);
        }
        else if(abs(longestPDG) == 3112){
            hSigmaMinus->Fill(trackFill);
        }
        else {
            hOther->Fill(trackFill);
            //std::cout << trackPDG << std::endl;
        }
    }

    HypPlot::DrawEfficiencyPlot(pMuonIdentifier, "", "MuonIdentifier", {kFHC}, {POT});

    TCanvas *c1 = new TCanvas("c1", "", 800, 600);

    hMuon->SetLineColor(kBlue);
    hMuon->SetLineStyle(1);
    hMuon->SetLineWidth(1);

    hChargedPion->SetLineColor(kRed);
    hChargedPion->SetLineStyle(1);
    hChargedPion->SetLineWidth(1);

    hProton->SetLineColor(kGreen + 2);
    hProton->SetLineStyle(1);
    hProton->SetLineWidth(1);

    hElectron->SetLineColor(kMagenta);
    hElectron->SetLineStyle(1);
    hElectron->SetLineWidth(1);

    hMuon->SetStats(0);
    hMuon->SetMaximum(ymax);
    hMuon->SetMinimum(ymin);
    hMuon->GetYaxis()->SetTitle(yaxistitle);
    hMuon->GetXaxis()->SetTitle(xaxistitle);
    hMuon->GetXaxis()->SetTitleSize(0.04);
    hMuon->GetYaxis()->SetTitleSize(0.04);

    hMuon->Draw("hist");
    hChargedPion->Draw("hist SAME");
    hProton->Draw("hist SAME");
    hElectron->Draw("hist SAME");
    //hSigmaPlus->Draw("SAME");
    //hSigmaMinus->Draw("SAME");
    //hOther->Draw("SAME");

    TLegend *legend = new TLegend(0.3, 0.7, 0.15, 0.85);
    legend->AddEntry(hMuon, "Muon", "l");
    legend->AddEntry(hChargedPion, "Pion", "l");
    legend->AddEntry(hProton, "Proton", "l");
    legend->AddEntry(hElectron, "Electron", "l");
    //legend->AddEntry(hSigmaPlus, "Sigma Plus", "l");
    //legend->AddEntry(hSigmaMinus, "Sigma Minus", "l");
    //legend->AddEntry(hOther, "Other", "l");
    legend->SetTextSize(0.03);
    legend->SetBorderSize(0); 
    legend->SetFillStyle(0);  
    legend->Draw();

    //c1->SetGrid();
    c1->SetLogy();
    c1->SaveAs("unstacked_histogram.png");

    E.Close();

}