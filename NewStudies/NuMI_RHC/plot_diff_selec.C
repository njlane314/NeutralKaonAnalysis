R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so);
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so);

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

double calculateMean(const std::vector<double>& data) {
    double sum = 0.0;
    for (double num : data) {
        sum += num;
    }
    return sum / data.size();
}

double calculateVariance(const std::vector<double>& data) {
    double mean = calculateMean(data);
    double variance = 0.0;
    for (double num : data) {
        variance += pow(num - mean, 2);
    }
    return variance / data.size();
}

void plot_diff_selec(){

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

    M.TuneMuonID(0.6, 0, 5); 

    TH1F *hist_pdg = new TH1F("", "", 3, 0, 3); 

    std::vector<int> pdg_codes_to_bin = {13, 2212, 211};
    std::vector<std::string> bin_labels = {"#mu", "p", "#pi"};

    // Set bin labels
    for (size_t i = 0; i < pdg_codes_to_bin.size(); ++i) {
        hist_pdg->GetXaxis()->SetBinLabel(i+1, bin_labels[i].c_str());
    }

    std::vector<TH1F*> histograms;
    std::vector<int> colors = {kBlue, kRed, kGreen, kMagenta, kCyan};

    for (size_t i = 0; i < pdg_codes_to_bin.size(); ++i) {
        histograms.push_back(new TH1F(Form("hist_pdg_%d", pdg_codes_to_bin[i]), bin_labels[i].c_str(), 20, -1, 1)); // Adjust the binning as needed
        histograms[i]->SetLineColor(colors[i]); // Set color for histogram
        histograms[i]->SetTitle(""); // Remove title
        histograms[i]->SetStats(0); // Remove stats box
    }
    
    std::vector<double> M0s;

    for(int i = 0; i < E.GetNEvents(); i++){

        if(i % 10000 == 0) std::cout << i << "/" << E.GetNEvents() << std::endl;

        Event e = E.GetEvent(i);

        M.SetSignal(e);                
        M.AddEvent(e);

        if(!e.EventIsSignal) continue;

        bool passed_FV, passed_muon, passed_track, passed_pion, passed_WCut = false;

        passed_FV = M.FiducialVolumeCut(e);
        if(!passed_FV) continue;
        passed_track = M.TrackCut(e);
        if(!passed_track) continue;
        passed_muon = M.ChooseMuonCandidate(e);
        if(!passed_muon) continue;
        passed_pion = M.ChoosePionPairCandidates(e);
        if(!passed_pion) continue;

        double invariant_mass = PionPairInvariantMass(e.DecayPionPlusCandidate, e.DecayPionMinusCandidate);
        //std::cout << invariant_mass << std::endl;
        if(!std::isnan(invariant_mass)) M0s.push_back(invariant_mass);

        passed_WCut = M.WCut(e);
        if(!passed_WCut) continue;

        int pdg_code = abs(e.MuonCandidate.TrackTruePDG);
        double muon_momentum = e.MuonCandidate.MuonMomentum;
        double proton_momentum = e.MuonCandidate.ProtonMomentum;
        double track_shower_score = e.MuonCandidate.TrackShowerScore;
        double mean_dEdx = e.MuonCandidate.MeandEdX_ThreePlane;
        double track_length = e.MuonCandidate.TrackLength;
        double LLRPID = e.MuonCandidate.Track_LLR_PID;

        auto it = std::find(pdg_codes_to_bin.begin(), pdg_codes_to_bin.end(), pdg_code);
        if (it != pdg_codes_to_bin.end()) {
            // Fill the histogram with PDG codes
            hist_pdg->Fill(std::distance(pdg_codes_to_bin.begin(), it));
            histograms[std::distance(pdg_codes_to_bin.begin(), it)]->Fill(track_shower_score);
        }
        else{
            //std::cout << pdg_code << std::endl;
        }


        /*if(pdg_code == 211){
            std::cout << muon_momentum << std::endl;
            std::cout << proton_momentum << std::endl;
            std::cout << "---------------" << std::endl;
        }*/

    }

    for (size_t i = 0; i < histograms.size(); ++i) {
        histograms[i]->Scale(1.0 / histograms[i]->Integral());
    }

    TCanvas *c1 = new TCanvas("c1", "Muon Candidate PDG", 800, 600);
    hist_pdg->Scale(1.0 / hist_pdg->Integral());
    hist_pdg->SetStats(0);
    hist_pdg->SetLineColor(kBlue);
    hist_pdg->Draw("HIST E");
    hist_pdg->SetMinimum(0);
    hist_pdg->GetXaxis()->SetLabelSize(0.08);
    hist_pdg->SetLineWidth(2);
    c1->SaveAs("hist_pdg.pdf"); 

    delete hist_pdg;
    delete c1;

    M.PrintAllCuts();

    double variance = calculateVariance(M0s);
    double mean = calculateMean(M0s);
    std::cout << "Invariant mass mean: " << mean << std::endl;
    std::cout << "Variance: " << variance << std::endl;

    double maxY = 0;
    for (auto hist : histograms) {
        double maxBinContent = hist->GetBinContent(hist->GetMaximumBin());
        if (maxBinContent > maxY) {
            maxY = maxBinContent;
        }
    }
    // Add some padding
    maxY *= 1.1;

    TCanvas *c2 = new TCanvas("c2", "Muon Momentum for Different PDG Particles", 800, 600);

    for (size_t i = 0; i < histograms.size(); ++i) {
        histograms[i]->SetMaximum(maxY);
        if (i == 0) histograms[i]->Draw("HIST E");
        else histograms[i]->Draw("HIST E SAME");
    }

    TLegend *leg = new TLegend(0.1, 0.91, 0.9, 0.99);
    leg->SetNColumns(3); 
    leg->SetBorderSize(0);
    for (size_t i = 0; i < histograms.size(); ++i) {
        leg->AddEntry(histograms[i], bin_labels[i].c_str(), "l");
    }
    leg->Draw();
    
    c2->SaveAs("hist_pdg_muon_momentum.pdf");

    // Cleanup
    for (auto hist : histograms) {
        delete hist;
    }
    delete c2;

    E.Close();

}