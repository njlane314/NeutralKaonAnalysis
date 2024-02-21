R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so)
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so)

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

void kaon_momentum(){

    double POT = 1.25e21; // POT to scale samples to
    //double POT = 1.5e21;

    BuildTunes();
    SelectionParameters P = P_FHC_Tune_325_NoBDT;
    //SelectionParameters P = P_RHC_Tune_397_NoBDT;

    std::string label = "invariant_mass_fhc_FV_muon_pion_pair";
    std::string SampleType = "pure_kaon";

    EventAssembler E(false);
    SelectionManager M(P);
    M.ImportSelectorBDTWeights("/uboone/app/users/nlane/NeutralKaonAnalysis/TMVA/SelectorMVA/dataset/weights");

    M.SetBeamMode(kFHC);
    //M.SetBeamMode(kRHC);
    
    M.SetPOT(POT);
    M.UseFluxWeight(false);
    M.UseGenWeight(false);

    E.SetFile("analysisOutputFHC_Overlay_GENIE_Kaon_cthorpe_make_k0s_events_numi_fhc_reco2_reco2_reco2.root",  "signal");
    //E.SetFile("analysisOutputRHC_GENIE_Overlay_Kaon_cthorpe_make_k0s_events_numi_rhc_reco2_REAL_reco2_reco2.root", "signal");
    M.AddSample("Signal", "Signal", E.GetPOT());

    for(int i=0;i<E.GetNEvents();i++){
    
        if(i % 10000 == 0) std::cout << "Processing event " << i << "/" << E.GetNEvents() << std::endl;
    
        //get an event
        Event e = E.GetEvent(i);

        //update metadata
        M.SetSignal(e);
        M.AddEvent(e);

        if(!e.EventIsSignal) continue;

        bool passed_FV = false;
        bool passed_track = false;
        bool passed_shower = false;
        bool passed_muon = false;
        bool passed_pion_pair = false;
        bool passed_connectedness = false;
        bool passed_Wcut = false;

        passed_FV = M.FiducialVolumeCut(e);
        //if(!passed_FV) continue;
        passed_muon = M.ChooseMuonCandidate(e);
        //if(!passed_muon) continue;
        passed_pion_pair = M.ChoosePionPairCandidates(e);
        //if(!passed_pion_pair) continue;
        passed_Wcut = M.WCut(e);
        //if(!passed_Wcut) continue;
        
        double kaon_momentum = -1;

        for(size_t i_tr = 0; i_tr < e.NMCTruths; i_tr++){ 
            if(e.IsK0SCharged.at(i_tr)){
                std::cout << e.PrimaryKaon.size() << std::endl;
                kaon_momentum = e.PrimaryKaon.at(0).ModMomentum;
            }
        }

        
      
    }

    std::cout << "Drawing histograms..." << std::endl;

    E.Close();

}