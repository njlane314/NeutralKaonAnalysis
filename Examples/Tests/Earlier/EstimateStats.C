R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so);
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so);

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

void EstimateStats(){
    //double POT = 1.25e21; // POT to scale samples to
    double POT = 1.5e21;

    BuildTunes();
    //SelectionParameters P = P_FHC_Tune_325_NoBDT;
    SelectionParameters P = P_RHC_Tune_397_NoBDT;

    std::string label = "test";
    std::string SampleType = "background";

    EventAssembler E(false);
    SelectionManager M(P);
    M.SetPOT(POT);
    M.UseFluxWeight(false);
    M.UseGenWeight(false);

    double lpk = 0.0;
    double lpk_var = 0.0;

    double lnk = 0.0;
    double lnk_var = 0.0;

    double llambdak = 0.0;
    double llambdak_var = 0.0;

    double lsigmaplusk = 0.0;
    double lsigmaplusk_var = 0.0;

    double lsigmaminusk = 0.0;
    double lsigmaminusk_var = 0.0;

    double lsigmazerok = 0.0;
    double lsigmazerok_var = 0.0;

    double lotherk = 0.0;
    double lotherk_var = 0.0;

    //E.SetFile("analysisOutputFHC_Overlay_GENIE_Kaon_cthorpe_make_k0s_events_numi_fhc_reco2_reco2_reco2.root",  "signal");
    E.SetFile("analysisOutputRHC_GENIE_Overlay_Kaon_cthorpe_make_k0s_events_numi_rhc_reco2_REAL_reco2_reco2.root", "signal");
    M.AddSample("Background","Background",E.GetPOT());

    for(int i = 0; i < E.GetNEvents(); i++){

        if(i % 10000 == 0) std::cout << i << "/" << E.GetNEvents() << std::endl;

        Event e = E.GetEvent(i);

        M.SetSignal(e);                
        M.AddEvent(e);

        bool passed_FV=false,passed_Tracks=false,passed_Showers=false,passed_MuonID=false,passed_TrackLengths=false,passed_Selector=false,passed_CT=false,passed_WCut=false,passed_AngleCut=false,passed_All=false;

        passed_FV = M.FiducialVolumeCut(e);
        if(passed_FV) passed_Tracks = M.TrackCut(e);
        if(passed_Tracks) passed_Showers = M.ShowerCut(e);
        if(passed_Showers) passed_MuonID = M.ChooseMuonCandidate(e);
        if(passed_MuonID) passed_Selector = M.ChoosePionPairCandidates(e, true);

        //if(!passed_Showers) continue;
        if(!e.EventIsSignal) continue;

        bool found_lambda = false;
        bool found_sigma_plus = false;
        bool found_sigma_minus = false;
        bool found_sigma_zero = false;
        bool found_associated_hyperon = false;
        bool found_muon = false;
        bool found_anti_muon = false;
        for(size_t i_tr = 0; i_tr < e.NMCTruths; i_tr++){
            if(abs(e.Lepton.at(i_tr).PDG) == 13){
                for(SimParticle hyperon : e.Hyperon){
                    if(abs(hyperon.PDG) == 3122) found_lambda = true;   
                    if(abs(hyperon.PDG) == 3222) found_sigma_plus = true;
                    if(abs(hyperon.PDG) == 3112) found_sigma_minus = true;
                    if(abs(hyperon.PDG) == 3212) found_sigma_zero = true;
                }

                if(e.Lepton.at(i_tr).PDG == 13) found_muon = true;
                else if(e.Lepton.at(i_tr).PDG == -13) found_anti_muon = true;
            }
        }

        if(found_lambda || found_sigma_plus || found_sigma_minus || found_sigma_zero) found_associated_hyperon = true;

        if(!found_associated_hyperon){
            if(found_muon){
                lpk += e.Weight;
                lpk_var += e.Weight*e.Weight;
            }
            else if(found_anti_muon){
                lnk += e.Weight;
                lnk_var += e.Weight*e.Weight;
            }
            else{
                lotherk += e.Weight;
                lotherk_var += e.Weight*e.Weight;
            }
        }
        else if(found_associated_hyperon){
            if(found_anti_muon && found_lambda && !found_sigma_plus && !found_sigma_zero && !found_sigma_minus){
                llambdak += e.Weight;
                llambdak_var += e.Weight*e.Weight;
            }
            else if(found_muon && !found_lambda && found_sigma_plus && !found_sigma_zero && !found_sigma_minus){
                lsigmaplusk += e.Weight;
                lsigmaplusk_var += e.Weight*e.Weight;
            }
            else if(found_anti_muon && !found_lambda && !found_sigma_plus && found_sigma_zero && !found_sigma_minus){
                lsigmazerok += e.Weight;
                lsigmazerok_var += e.Weight*e.Weight;
            }
            else if(found_anti_muon && !found_lambda && !found_sigma_plus && !found_sigma_zero && found_sigma_minus){
                lsigmaminusk += e.Weight;
                lsigmaminusk_var += e.Weight*e.Weight;
            }
            else{
                lotherk += e.Weight;
                lotherk_var += e.Weight*e.Weight;
            }
        }
    }

    std::cout << "lpk = " << lpk << "  +/-  " << sqrt(lpk_var) << std::endl;
    std::cout << "lnk = " << lnk << "  +/-  " << sqrt(lnk_var) << std::endl;
    std::cout << "llambdak = " << llambdak << "  +/-  " << sqrt(llambdak_var) << std::endl;
    std::cout << "lsigmaplusk = " << lsigmaplusk << "  +/-  " << sqrt(lsigmaplusk_var) << std::endl;
    std::cout << "lsigmaminusk = " << lsigmaminusk << "  +/-  " << sqrt(lsigmaminusk_var) << std::endl;
    std::cout << "lsigmazerok = " << lsigmazerok << "  +/-  " << sqrt(lsigmazerok_var) << std::endl;
    std::cout << "lotherl = " << lotherk << " +/ " << sqrt(lotherk_var) << std::endl;

    E.Close();
}