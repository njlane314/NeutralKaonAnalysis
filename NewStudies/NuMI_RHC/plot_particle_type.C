R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so);
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so);

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

void updateMultiplicity(const std::vector<SimParticle>& particles,
                        std::map<int, int>& true_particle_multiplicity,
                        const std::vector<int>& pdg_codes_to_bin) {
    for(const auto& particle : particles) {
        int pdg_code = std::abs(particle.PDG);
        auto it = std::find(pdg_codes_to_bin.begin(), pdg_codes_to_bin.end(), pdg_code);
        if(it != pdg_codes_to_bin.end()) {
            true_particle_multiplicity[pdg_code]++;
        }
    }
}

void plot_particle_type(){

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

    std::vector<int> pdg_codes_to_bin = {13, 11, 2212, 211, 3222, 321, 2112};
    std::vector<std::string> bin_labels = {"#mu^{#pm}", "e^{#pm}", "p", "#pi^{#pm}", "#Sigma^{#pm}", "K^{#pm}", "n"};

    std::map<int, int> reco_particle_multiplicity;
    std::map<int, int> true_particle_multiplicity;
    // Initialize the map with zeros
    for (int pdg_code : pdg_codes_to_bin) {
        reco_particle_multiplicity[pdg_code] = 0;
        true_particle_multiplicity[pdg_code] = 0;
    }

    int selected_event_count = 0;

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
        /*passed_pion = M.ChoosePionPairCandidates(e);
        if(!passed_pion) continue;*/

        updateMultiplicity(e.Lepton, true_particle_multiplicity, pdg_codes_to_bin);
        updateMultiplicity(e.Hyperon, true_particle_multiplicity, pdg_codes_to_bin);
        updateMultiplicity(e.PrimaryNucleon, true_particle_multiplicity, pdg_codes_to_bin);
        updateMultiplicity(e.PrimaryPion, true_particle_multiplicity, pdg_codes_to_bin);
        updateMultiplicity(e.PrimaryKaon, true_particle_multiplicity, pdg_codes_to_bin);
        //updateMultiplicity(e.Decay, true_particle_multiplicity, pdg_codes_to_bin);

        for(int d = 0; d < e.Decay.size(); d++){
            //std::cout << e.Decay.at(d).PDG << std::endl;
        }

        for(int t = 0; t < e.TracklikePrimaryDaughters.size(); t++){
            int pdg_code = abs(e.TracklikePrimaryDaughters.at(t).TrackTruePDG);
            auto it = std::find(pdg_codes_to_bin.begin(), pdg_codes_to_bin.end(), pdg_code);
            if (it != pdg_codes_to_bin.end()) {
                reco_particle_multiplicity[pdg_code]++;
            }
        }

        selected_event_count++;
    }

    std::map<int, double> reco_average_multiplicity;
    std::map<int, double> multiplicity_error;
    std::map<int, double> lower_bound;
    std::map<int, double> upper_bound;
    for (const auto& pair : reco_particle_multiplicity) {
        int pdg_code = pair.first;
        int multiplicity = pair.second;
        // Divide the total multiplicity by the total number of events to obtain the average
        reco_average_multiplicity[pdg_code] = static_cast<double>(multiplicity) / selected_event_count;
        // Calculate statistical uncertainty as sqrt(N) for each bin
        multiplicity_error[pdg_code] = sqrt(static_cast<double>(multiplicity)) / selected_event_count;
        // Calculate lower and upper bounds for the 95% confidence interval
        lower_bound[pdg_code] = reco_average_multiplicity[pdg_code] - 1.96 * multiplicity_error[pdg_code];
        upper_bound[pdg_code] = reco_average_multiplicity[pdg_code] + 1.96 * multiplicity_error[pdg_code];
    }

    std::map<int, double> true_average_multiplicity;
    for (const auto& pair : true_particle_multiplicity) {
        int pdg_code = pair.first;
        int multiplicity = pair.second;
        true_average_multiplicity[pdg_code] = static_cast<double>(multiplicity) / selected_event_count;
        multiplicity_error[pdg_code] = sqrt(static_cast<double>(multiplicity)) / selected_event_count;
    }    

    // Draw the average multiplicity on the same plot
    TCanvas *c1 = new TCanvas("", "", 800, 600);

    TH1F *hist_avg_multiplicity_reco = new TH1F("hist_avg_multiplicity_reco", "", 7, 0, 7);
    TH1F *hist_avg_multiplicity_true = new TH1F("hist_avg_multiplicity_true", "", 7, 0, 7);
    hist_avg_multiplicity_reco->GetYaxis()->SetTitle({"Event Average Multiplicity"});
    hist_avg_multiplicity_true->GetYaxis()->SetTitle({"Event Average Multiplicity"});

    for (size_t i = 0; i < pdg_codes_to_bin.size(); ++i) {
        hist_avg_multiplicity_reco->GetXaxis()->SetBinLabel(i+1, bin_labels[i].c_str());
        hist_avg_multiplicity_true->GetXaxis()->SetBinLabel(i+1, bin_labels[i].c_str());
    }

    for (size_t i = 0; i < pdg_codes_to_bin.size(); ++i) {
        hist_avg_multiplicity_reco->SetBinContent(i+1, reco_average_multiplicity[pdg_codes_to_bin[i]]);
        hist_avg_multiplicity_reco->SetBinError(i+1, multiplicity_error[pdg_codes_to_bin[i]]);
        
        hist_avg_multiplicity_true->SetBinContent(i+1, true_average_multiplicity[pdg_codes_to_bin[i]]);
        hist_avg_multiplicity_true->SetBinError(i+1, multiplicity_error[pdg_codes_to_bin[i]]);
    }

    hist_avg_multiplicity_reco->SetLineColor(kRed);
    hist_avg_multiplicity_true->SetLineColor(kBlue);

    hist_avg_multiplicity_reco->SetStats(0);
    hist_avg_multiplicity_true->SetStats(0);

    hist_avg_multiplicity_reco->GetXaxis()->SetLabelSize(0.05);
    hist_avg_multiplicity_true->GetXaxis()->SetLabelSize(0.05);

    hist_avg_multiplicity_reco->Draw("HIST E");
    hist_avg_multiplicity_true->Draw("HIST E SAME");

    TLegend *leg = new TLegend(0.1, 0.91, 0.9, 0.99);
    leg->SetNColumns(2); 
    leg->SetBorderSize(0);
    leg->AddEntry(hist_avg_multiplicity_true, "SimParticles", "l");
    leg->AddEntry(hist_avg_multiplicity_reco, "RecoParticles", "l");
    leg->Draw();

    c1->SaveAs("hist_avg_multiplicity.pdf");

    delete hist_avg_multiplicity_reco;
    delete hist_avg_multiplicity_true;
    delete c1;

    
    E.Close();

}
