R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so);
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so);

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

void InvariantMass(){

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

    //M.SetupHistograms(10,0,10.0,";Neutrino Energy (GeV);Events/bin");
    M.SetupHistograms(16,0.,0.8,";Reconstructed Invariant Mass of Pion Pair (GeV);Events/bin");
    //M.SetupHistograms(50,0.,1,";Shower Multiplicity;Events/bin");

    double Signal = 0.0;
    double Signal_var = 0.0;

    E.SetFile("analysisOutputFHC_Overlay_GENIE_Kaon_cthorpe_make_k0s_events_numi_fhc_reco2_reco2_reco2.root", "Background");
    M.AddSample("Background","Background",E.GetPOT());

    for(int i = 0; i < E.GetNEvents(); i++){

        if(i % 10000 == 0) std::cout << i << "/" << E.GetNEvents() << std::endl;

        Event e = E.GetEvent(i);

        M.SetSignal(e);                
        M.AddEvent(e);
        
        if(!e.EventIsSignal) continue;
        
        bool passed_FV=false,passed_Tracks=false,passed_Showers=false,passed_MuonID=false,passed_TrackLengths=false,passed_Selector=false,passed_CT=false,passed_WCut=false,passed_AngleCut=false,passed_All=false;

        passed_FV = M.FiducialVolumeCut(e);
        if(passed_FV) passed_Tracks = M.TrackCut(e);
        if(passed_Tracks) passed_MuonID = M.ChooseMuonCandidate(e);
        if(passed_Tracks) passed_Selector = M.ChoosePionPairCandidates(e, true);
    
        passed_All = passed_Selector;

        if (passed_All) {
            Signal += e.Weight;
            Signal_var += e.Weight*e.Weight;
        }

        double invariantMass = PionPairInvariantMass(e.DecayPionPlusCandidate, e.DecayPionMinusCandidate);

        M.FillHistograms(e, invariantMass);
        
    }

    M.DrawHistograms(label);

    std::cout << "Signal = " << Signal << "  +/-  " << sqrt(Signal_var) << std::endl;

    E.Close();
}