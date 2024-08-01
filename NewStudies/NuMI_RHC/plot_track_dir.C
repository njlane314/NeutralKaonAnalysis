R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so);
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so);

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

void plot_track_dir(){

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

    //M.SetupHistograms(15,0.275,0.625,";Invariant Mass (GeV);Events/bin");
    M.SetupHistograms(40,-1,1,";Dot Product;Events/bin");

    E.SetFile("analysisOutputRHC_GENIE_Overlay_Kaon_cthorpe_make_k0s_events_numi_rhc_reco2_REAL_reco2_reco2.root", "Kaon");
    M.AddSample("Kaon","Kaon",E.GetPOT());
    
    std::vector<double> M0s;

    for(int i = 0; i < E.GetNEvents(); i++){

        if(i % 10000 == 0) std::cout << i << "/" << E.GetNEvents() << std::endl;

        Event e = E.GetEvent(i);

        M.SetSignal(e);                
        M.AddEvent(e);

        if(!e.EventIsSignal) continue;

        bool passed_FV, passed_muon, passed_track, passed_pion, passed_WCut, passed_connected = false;

        passed_FV = M.FiducialVolumeCut(e);
        if(!passed_FV) continue;
        passed_track = M.TrackCut(e);
        if(!passed_track) continue;
        passed_pion = M.ChoosePionPairCandidates(e);
        if(!passed_pion) continue;

        bool correct_pair = false;

        for(size_t i_tr=0;i_tr<e.TracklikePrimaryDaughters.size();i_tr++){
            for(size_t j_tr=0;j_tr<e.TracklikePrimaryDaughters.size();j_tr++){

                if(i_tr == j_tr) continue;
                if(e.TracklikePrimaryDaughters.at(i_tr).Index == e.TrueDecayPionPlusIndex && e.TracklikePrimaryDaughters.at(j_tr).Index == e.TrueDecayPionMinusIndex){
                    correct_pair = true;
                }

            }
        }

        if(!correct_pair) continue;

        /*double invariant_mass = PionPairInvariantMass(e.DecayPionPlusCandidate, e.DecayPionMinusCandidate);
        //std::cout << invariant_mass << std::endl;
        if(!std::isnan(invariant_mass)){
            M.FillHistograms(e, invariant_mass); 
        }*/

        double momentum_pionPlus = PionMomentum(e.DecayPionPlusCandidate.TrackLength);
        double momentum_pionMinus = PionMomentum(e.DecayPionMinusCandidate.TrackLength);

        double energy_pionPlus = sqrt(momentum_pionPlus*momentum_pionPlus + 0.1396*0.1396);
        double energy_pionMinus = sqrt(momentum_pionMinus*momentum_pionMinus + 0.1396*0.1396);

        TLorentzVector PionPlus4Momentum(e.DecayPionPlusCandidate.TrackDirectionX*momentum_pionPlus, e.DecayPionPlusCandidate.TrackDirectionY*momentum_pionPlus, e.DecayPionPlusCandidate.TrackDirectionZ*momentum_pionPlus, energy_pionPlus);
        TLorentzVector PionMinus4Momentum(e.DecayPionMinusCandidate.TrackDirectionX*momentum_pionMinus, e.DecayPionMinusCandidate.TrackDirectionY*momentum_pionMinus, e.DecayPionMinusCandidate.TrackDirectionZ*momentum_pionMinus, energy_pionMinus);

        TLorentzVector P = PionPlus4Momentum + PionMinus4Momentum;

        double M0 = sqrt(P*P);

        TVector3 PionPlusDir(e.DecayPionPlusCandidate.TrackDirectionX, e.DecayPionPlusCandidate.TrackDirectionY, e.DecayPionPlusCandidate.TrackDirectionZ);
        TVector3 PionMinusDir(e.DecayPionMinusCandidate.TrackDirectionX, e.DecayPionMinusCandidate.TrackDirectionY, e.DecayPionMinusCandidate.TrackDirectionZ);

        double true_mom_pion_plus = sqrt(e.DecayPionPlusCandidate.TrackTruePx*e.DecayPionPlusCandidate.TrackTruePx + e.DecayPionPlusCandidate.TrackTruePy*e.DecayPionPlusCandidate.TrackTruePy + e.DecayPionPlusCandidate.TrackTruePz*e.DecayPionPlusCandidate.TrackTruePz);
        double true_mom_pion_minus = sqrt(e.DecayPionMinusCandidate.TrackTruePx*e.DecayPionMinusCandidate.TrackTruePx + e.DecayPionMinusCandidate.TrackTruePy*e.DecayPionMinusCandidate.TrackTruePy + e.DecayPionMinusCandidate.TrackTruePz*e.DecayPionMinusCandidate.TrackTruePz);

        TVector3 TruePionPlusDir(e.DecayPionPlusCandidate.TrackTruePx/true_mom_pion_plus, e.DecayPionPlusCandidate.TrackTruePy/true_mom_pion_plus, e.DecayPionPlusCandidate.TrackTruePz/true_mom_pion_plus);
        TVector3 TruePionMinusDir(e.DecayPionMinusCandidate.TrackTruePx/true_mom_pion_minus, e.DecayPionMinusCandidate.TrackTruePy/true_mom_pion_minus, e.DecayPionMinusCandidate.TrackTruePz/true_mom_pion_minus);

        TLorentzVector TruePionPlus4Mom(momentum_pionPlus * TruePionPlusDir, energy_pionPlus);
        TLorentzVector TruePionMinus4Mom(momentum_pionPlus * TruePionMinusDir, energy_pionMinus);
        //TLorentzVector TruePionPlus4Mom(e.DecayPionPlusCandidate.TrackDirectionX*true_mom_pion_plus, e.DecayPionPlusCandidate.TrackDirectionY*true_mom_pion_plus, e.DecayPionPlusCandidate.TrackDirectionZ*true_mom_pion_plus, energy_pionPlus);
        //TLorentzVector TruePionMinus4Mom(e.DecayPionMinusCandidate.TrackDirectionX*true_mom_pion_minus, e.DecayPionMinusCandidate.TrackDirectionY*true_mom_pion_minus, e.DecayPionMinusCandidate.TrackDirectionZ*true_mom_pion_minus, energy_pionMinus);
        TLorentzVector true_P = TruePionMinus4Mom + TruePionPlus4Mom;
        double true_M0 = sqrt(abs(true_P*true_P));

        double alpha = (180/3.142)*PionPlusDir.Angle(PionMinusDir);
        double true_alpha = (180/3.142)*TruePionPlusDir.Angle(TruePionMinusDir);

        double res = (M0 - true_M0)/true_M0;
        //std::cout << res << std::endl;

        double dot_prod = e.DecayPionPlusCandidate.TrackDirectionX*(e.DecayPionPlusCandidate.TrackTruePx/true_mom_pion_plus) + e.DecayPionPlusCandidate.TrackDirectionY*(e.DecayPionPlusCandidate.TrackTruePy/true_mom_pion_plus) + e.DecayPionPlusCandidate.TrackDirectionZ*(e.DecayPionPlusCandidate.TrackTruePz/true_mom_pion_plus);
        double dot_prod_minus = e.DecayPionMinusCandidate.TrackDirectionX*(e.DecayPionMinusCandidate.TrackTruePx/true_mom_pion_minus) + e.DecayPionMinusCandidate.TrackDirectionY*(e.DecayPionMinusCandidate.TrackTruePy/true_mom_pion_minus) + e.DecayPionMinusCandidate.TrackDirectionZ*(e.DecayPionMinusCandidate.TrackTruePz/true_mom_pion_minus);

        M.FillHistograms(e, dot_prod);  
        M.FillHistograms(e, dot_prod_minus);             
    }

    std::cout << "Drawing histograms" << std::endl;
    M.DrawHistograms(label);

    E.Close();
}