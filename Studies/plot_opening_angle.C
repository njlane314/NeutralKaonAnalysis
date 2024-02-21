R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so)
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so)

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

void plot_opening_angle(){

    double POT = 1.25e21; // POT to scale samples to
    //double POT = 1.5e21;

    BuildTunes();
    SelectionParameters P = P_FHC_Tune_325_NoBDT;
    //SelectionParameters P = P_RHC_Tune_397_NoBDT;

    std::string label = "opening_angle_fhc_FV_muon_pion_pair";
    std::string SampleType = "pure_kaon";

    EventAssembler E(false);
    SelectionManager M(P);

    M.SetBeamMode(kFHC);
    //M.SetBeamMode(kRHC);
    
    M.SetPOT(POT);
    M.UseFluxWeight(false);
    M.UseGenWeight(false);

    M.SetupHistograms(72,0,180,";Opening Angle (deg);Events/bin");

    E.SetFile("analysisOutputFHC_Overlay_GENIE_Kaon_cthorpe_make_k0s_events_numi_fhc_reco2_reco2_reco2.root",  "signal");
    //E.SetFile("analysisOutputRHC_GENIE_Overlay_Kaon_cthorpe_make_k0s_events_numi_rhc_reco2_REAL_reco2_reco2.root", "signal");
    M.AddSample("Signal", "Signal", E.GetPOT());

    for(int i = 0; i < E.GetNEvents(); i++){

        if(i % 10000 == 0) std::cout << i << "/" << E.GetNEvents() << std::endl;

        Event e = E.GetEvent(i);

        M.SetSignal(e);                
        M.AddEvent(e);

        bool passed_FV = false;
        bool passed_muon = false;
        bool passed_pion_pair = false;

        passed_FV = M.FiducialVolumeCut(e);
        passed_muon = M.ChooseMuonCandidate(e);
        passed_pion_pair = M.ChoosePionPairCandidates(e, true);

        TVector3 PionPlusMom;
        TVector3 PionMinusMom;
        double OpeningAngle = PionPairOpeningAngle(e.DecayPionMinusCandidate, e.DecayPionPlusCandidate);

        if(!passed_FV) continue;
        if(!passed_muon) continue;
        //if(!passed_pion_pair) continue;
        if(!e.GoodReco) continue;

        M.FillHistograms(e, OpeningAngle);               
    }

    std::cout << "Drawing histograms" << std::endl;
    M.DrawHistograms(label);
    
    E.Close();

}