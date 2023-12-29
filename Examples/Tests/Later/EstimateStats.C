R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so);
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so);

#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"
#include "Parameters.h"
#include "SampleSets_Example.h"

struct Statistics {
    double count = 0;
    double variance = 0;
};

std::string createKey(bool type_CC, bool type_NC, int leptonPDG, bool is_single_production, const std::vector<SimParticle>& hyperons) {
    std::string key = type_CC ? "CC_" : "NC_";
    key += "L" + std::to_string(leptonPDG) + "_";
    key += is_single_production ? "Single" : "Associated";

    for (const auto& hyperon : hyperons) {
        key += "_H" + std::to_string(abs(hyperon.PDG));
    }

    return key;
}

void updateStats(Statistics& stats, double weight) {
    stats.count += weight;
    stats.variance += weight * weight;
}

void EstimateStats() {
    double POT = 1.24e21;

    // Initialize selection parameters and event assembler
    BuildTunes();
    SelectionParameters P = P_FHC_Tune_325_NoBDT;
    EventAssembler E(false);
    SelectionManager M(P);
    M.SetPOT(POT);
    M.UseFluxWeight(false);
    M.UseGenWeight(false);

    double total_kaon_production = 0.0;
    double total_kaon_production_var = 0.0;

    // Load the data file and add the sample
    E.SetFile("analysisOutputFHC_Overlay_GENIE_Kaon_cthorpe_make_k0s_events_numi_fhc_reco2_reco2_reco2.root", "Signal");
    M.AddSample("Signal", "Signal", E.GetPOT());

    std::map<std::string, Statistics> combinationStats;

    for (int i = 0; i < E.GetNEvents(); i++) {
        if (i % 10000 == 0) {
            std::cout << i << "/" << E.GetNEvents() << std::endl;
        }

        Event e = E.GetEvent(i);

        M.SetSignal(e);                
        M.AddEvent(e);

        if(!e.EventIsSignal) continue;
        total_kaon_production += e.Weight;
        total_kaon_production_var += e.Weight*e.Weight;

        // Determine interaction type
        bool type_CC = e.CCNC.at(0) == "CC";
        bool type_NC = e.CCNC.at(0) == "NC";

        // Determine primary lepton
        int leptonPDG = e.Lepton.at(0).PDG;

        // Determine production type
        bool is_single_production = e.Hyperon.empty();
        bool is_associated_production = !is_single_production;

        // Determine associated hyperons
        std::vector<SimParticle> hyperons;
        if (is_associated_production) {
            hyperons = e.Hyperon;
        }

        std::string key = createKey(type_CC, type_NC, leptonPDG, is_single_production, hyperons);
        updateStats(combinationStats[key], e.Weight);
    }

    E.Close();

    // Calculate variances and print statistics
    double total = 0.0;
    for (auto& pair : combinationStats) {
        std::cout << pair.first << " - Count: " << pair.second.count << " +/- " << sqrt(pair.second.variance) << std::endl;
        total += pair.second.count;
    }
    std::cout << total << std::endl;

    std::cout << "Total - Count: " << total_kaon_production << " +/- " << sqrt(total_kaon_production_var) << std::endl;
}