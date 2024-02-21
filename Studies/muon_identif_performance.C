R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so)
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so)

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

void muon_identif_performance(){

    double POT = 1.25e21; // POT to scale samples to
    //double POT = 1.5e21;

    BuildTunes();
    SelectionParameters P = P_FHC_Tune_325_NoBDT;
    //SelectionParameters P = P_RHC_Tune_397_NoBDT;

    std::string label = "fhc_fiducial_cut";
    std::string SampleType = "pure_kaon";

    EventAssembler E(false);
    SelectionManager M(P);

    M.SetBeamMode(kFHC);
    //M.SetBeamMode(kRHC);
    
    M.SetPOT(POT);
    M.UseFluxWeight(false);
    M.UseGenWeight(false);

    E.SetFile("analysisOutputFHC_Overlay_GENIE_Kaon_cthorpe_make_k0s_events_numi_fhc_reco2_reco2_reco2.root",  "signal");
    //E.SetFile("analysisOutputRHC_GENIE_Overlay_Kaon_cthorpe_make_k0s_events_numi_rhc_reco2_REAL_reco2_reco2.root", "signal");
    M.AddSample("Signal", "Signal", E.GetPOT());

    TEfficiency* pMuonMomEffic = new TEfficiency("pMuonMomEffic", ";True Muon Momentum (GeV/c); Entries/bin", 20, 0, 5);

    for(int i = 0; i < E.GetNEvents(); i++){

        if(i % 10000 == 0) std::cout << i << "/" << E.GetNEvents() << std::endl;

        Event e = E.GetEvent(i);

        M.SetSignal(e);                
        M.AddEvent(e);

        bool passed_FV = false;
        bool passed_track = false;
        bool passed_shower = false;
        bool passed_muon = false;

        passed_FV = M.FiducialVolumeCut(e);
        passed_track = M.TrackCut(e);
        passed_shower = M.ShowerCut(e);
        passed_muon = M.ChooseMuonCandidate(e);
        
        //if(!passed_FV) continue;
        //if(!passed_muon) continue;

        if(!e.EventIsSignal) continue;

        pMuonMomEffic->FillWeighted(passed_muon && passed_FV && passed_track && passed_shower, e.Weight, e.MuonCandidate.TrackTrueModMomentum);
              
    }

    HypPlot::DrawEfficiencyPlot(pMuonMomEffic, "", "MuonMom", {kFHC}, {POT});

    E.Close();

}