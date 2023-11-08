R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so);
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so);

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

// Search for K0 -> pi+ pi- decays from muon anti-neutrino interactions in microboone
// 

void SignalBackgroundPlots(){

    double POT = 1.0e21; 

    BuildTunes();

    std::string label = "test";

    SelectionParameters P = P_FHC_Tune_325_NoBDT;

    EventAssembler E;
    SelectionManager M(P);
    M.SetPOT(POT);
    M.UseFluxWeight(false);
	M.UseGenWeight(false);

    E.SetFile("analysisOutputRHC_GENIE_Overlay_Kaon_TEST.root", "Background");

    M.SetupHistograms(100, 1, 0, ";Neutrino Energy (GeV);Events");

    for(int i_evt = 0; i_evt < E.GetNEvents(); i_evt++) {
        
        if(i_evt % 10000 == 0) std::cout << i_evt << "/" << E.GetNEvents() << std::endl;

        Event evt = E.GetEvent(i_evt);

        M.SetSignal(evt);
        M.AddEvent(evt);

    }

    E.Close();

}
