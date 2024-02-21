R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so)
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so)

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

void updateStats(Statistics& stats, double weight) {
    stats.count += weight;
    stats.variance += weight * weight;
}

void estimate_stats(){

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
    E.SetFile("analysisOutputRHC_GENIE_Overlay_Kaon_cthorpe_make_k0s_events_numi_rhc_reco2_REAL_reco2_reco2.root", "signal");
    M.AddSample("Signal", "Signal", E.GetPOT());

    std::map<std::string, Statistics> combinationStats;

    double total = 0.0;
    double total_var = 0.0;

    double signal = 0.0;
    double signal_var = 0.0;

    for(int i = 0; i < E.GetNEvents(); i++){

        if(i % 10000 == 0) std::cout << i << "/" << E.GetNEvents() << std::endl;

        Event e = E.GetEvent(i);

        M.SetSignal(e);                
        M.AddEvent(e);

        total += e.Weight;
        total_var += e.Weight * e.Weight;

        if(e.EventIsSignal){
            signal += e.Weight;
            signal_var += e.Weight * e.Weight;
        }

        std::string kaonType = EventType::GetPureKaonType(e); // Get the event type
        updateStats(combinationStats[kaonType], e.Weight); // Update stats using the event type as key
    }
    
    E.Close();

    for (auto& pair : combinationStats) {
        std::cout << pair.first << " - Count: " << pair.second.count << " +/- " << sqrt(pair.second.variance) << std::endl;
    }

    std::cout << "Signal - Count: " << signal << " +/- " << sqrt(signal_var) << std::endl;
    std::cout << "Total - Count: " << total << " +/- " << sqrt(total_var) << std::endl;

}