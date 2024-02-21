R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so)
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so)

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

void plot_invariant_mass(){

    //double POT = 1.25e21; // POT to scale samples to
    double POT = 1.5e21;

    BuildTunes();
    //SelectionParameters P = P_FHC_Tune_325_NoBDT;
    SelectionParameters P = P_RHC_Tune_397_NoBDT;

    std::string label = "invariant_mass_rhc_FV_muon_pion_pair";
    std::string SampleType = "pure_kaon";

    EventAssembler E(false);
    SelectionManager M(P);
    M.ImportSelectorBDTWeights("/uboone/app/users/nlane/NeutralKaonAnalysis/TMVA/SelectorMVA/dataset/weights");

    //M.SetBeamMode(kFHC);
    M.SetBeamMode(kRHC);
    
    M.SetPOT(POT);
    M.UseFluxWeight(false);
    M.UseGenWeight(false);

    M.SetupHistograms(4,0.2,0.6,";Invariant Mass (GeV);Events/bin");

    //E.SetFile("analysisOutputFHC_Overlay_GENIE_Kaon_cthorpe_make_k0s_events_numi_fhc_reco2_reco2_reco2.root",  "signal");
    E.SetFile("analysisOutputRHC_GENIE_Overlay_Kaon_cthorpe_make_k0s_events_numi_rhc_reco2_REAL_reco2_reco2.root", "signal");
    M.AddSample("Signal", "Signal", E.GetPOT());

    for(int i = 0; i < E.GetNEvents(); i++){

        if(i % 10000 == 0) std::cout << i << "/" << E.GetNEvents() << std::endl;

        Event e = E.GetEvent(i);

        M.SetSignal(e);                
        M.AddEvent(e);

        bool passed_FV = false;
        bool passed_track = false;
        bool passed_shower = false;
        bool passed_muon = false;
        bool passed_pion_pair = false;
        bool passed_connectedness = false;
        bool passed_Wcut = false;

        passed_FV = M.FiducialVolumeCut(e);
        if(!passed_FV) continue;
        passed_muon = M.ChooseMuonCandidate(e);
        if(!passed_muon) continue;
        passed_pion_pair = M.ChoosePionPairCandidates(e);
        if(!passed_pion_pair) continue;
        passed_Wcut = M.WCut(e);
        if(!passed_Wcut) continue;

        M.FillHistograms(e, PionPairInvariantMass(e.DecayPionPlusCandidate, e.DecayPionMinusCandidate));               
    }

    std::cout << "Drawing histograms" << std::endl;
    M.DrawHistograms(label);
    
    E.Close();

}