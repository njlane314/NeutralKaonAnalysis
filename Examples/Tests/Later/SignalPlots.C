R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so)
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so)

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

void SignalPlots(){

    double POT = 1.24e21; // POT to scale samples to

    BuildTunes();
    SelectionParameters P = P_FHC_Tune_325_NoBDT;

    std::string label = "signal";
    std::string SampleType = "purekaon";

    EventAssembler E(false);
    SelectionManager M(P);
    M.SetPOT(POT);
    M.UseFluxWeight(false);
    M.UseGenWeight(false);

    M.SetupHistograms(20,0,10.0,";True Neutrino Energy (GeV);Events/bin");

    E.SetFile("analysisOutputFHC_Overlay_GENIE_Kaon_cthorpe_make_k0s_events_numi_fhc_reco2_reco2_reco2.root",  "signal");
    M.AddSample("Signal", "Signal", E.GetPOT());

    for(int i = 0; i < E.GetNEvents(); i++){

        if(i % 10000 == 0) std::cout << i << "/" << E.GetNEvents() << std::endl;

        //if(i > 40000) continue;

        Event e = E.GetEvent(i);

        M.SetSignal(e);                
        M.AddEvent(e);

        double E = e.Neutrino.at(0).E;

        M.FillHistograms(e,E);                
    }

    std::cout << "Drawing histograms" << std::endl;
    M.DrawHistograms(label);
    
    E.Close();

}