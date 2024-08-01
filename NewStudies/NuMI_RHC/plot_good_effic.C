R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so);
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so);

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

void plot_good_effic(){

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

    TEfficiency* pSignal = new TEfficiency("pSignal", ";; Entries/bin", 1, 0, 1);
    TEfficiency* pGoodReco = new TEfficiency("pGoodReco", ";; Entries/bin", 1, 0, 1);
    TEfficiency* pCorrectPair = new TEfficiency("pCorrectPair", ";; Entries/bin", 1, 0, 1);

    for(int i = 0; i < E.GetNEvents(); i++){

        if(i % 10000 == 0) std::cout << i << "/" << E.GetNEvents() << std::endl;

        Event e = E.GetEvent(i);

        M.SetSignal(e);                
        M.AddEvent(e);

        if(!e.EventIsSignal) continue;

        bool passed_FV, passed_muon, passed_track, passed_pion, passed_WCut, passed_All = false;

        passed_FV = M.FiducialVolumeCut(e);
        //if(!passed_FV) continue;
        if(passed_FV) passed_track = M.TrackCut(e);
        //if(!passed_track) continue;
        if(passed_track) passed_pion = M.ChoosePionPairCandidates(e);
        //if(!passed_pion) continue;

        passed_All = passed_pion;
        
        pSignal->FillWeighted(passed_All, e.Weight, 0.5);

        //if(!passed_All) continue;  
        bool correct_pair = false;

        for(size_t i_tr=0;i_tr<e.TracklikePrimaryDaughters.size();i_tr++){
            for(size_t j_tr=0;j_tr<e.TracklikePrimaryDaughters.size();j_tr++){

                if(i_tr == j_tr) continue;

                if(e.TracklikePrimaryDaughters.at(i_tr).Index == e.TrueDecayPionPlusIndex && e.TracklikePrimaryDaughters.at(j_tr).Index == e.TrueDecayPionMinusIndex){
                    
                    // if correct 
                    correct_pair = true;
                }

            }
        }

        if(!correct_pair) e.Print();

        pCorrectPair->FillWeighted(correct_pair, e.Weight, 0.5);

        if(!e.GoodReco) passed_All = false;
        pGoodReco->FillWeighted(passed_All, e.Weight, 0.5);
    
    }

    HypPlot::DrawEfficiencyPlot(pSignal, "", "SignalEffic", "", {kRHC}, {POT});
    HypPlot::DrawEfficiencyPlot(pGoodReco, "", "GoodRecoEffic", "", {kRHC}, {POT});
    HypPlot::DrawEfficiencyPlot(pCorrectPair, "", "CorrectPair", "", {kRHC}, {POT});
    
    E.Close();

}
