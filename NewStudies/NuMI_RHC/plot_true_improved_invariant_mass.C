R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so);
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so);

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

void plot_true_improved_invariant_mass(){

    double POT = 1.5e21;

    double EXT_POT = 1.0421e20;

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

    SampleNames.push_back("GENIE kaon");
    SampleTypes.push_back("Kaon");
    SampleFiles.push_back("analysisOutputRHC_GENIE_Overlay_Kaon_cthorpe_make_k0s_events_numi_rhc_reco2_REAL_reco2_reco2.root");

    SampleNames.push_back("GENIE Background");
    SampleTypes.push_back("Background");
    SampleFiles.push_back("analysisOutputRHC_GENIE_Overlay_Background_prodgenie_numi_uboone_overlay_rhc_mcc9_run3b_v28_v2_sample0.root");

    SampleNames.push_back("GENIE Dirt");
    SampleTypes.push_back("Dirt");
    SampleFiles.push_back("analysisOutputRHC_GENIE_Overlay_Dirt_prodgenie_numi_uboone_overlay_dirt_rhc_mcc9_run3b_v28_sample0.root");

    SampleNames.push_back("EXT run3");
    SampleTypes.push_back("EXT");
    SampleFiles.push_back("analysisOutputEXT_cthorpe_prod_extnumi_mcc9_v08_00_00_45_run3_run3b_reco2_all_reco2_pt1.root");

    SampleNames.push_back("EXT run1");
    SampleTypes.push_back("EXT");
    SampleFiles.push_back("analysisOutputEXT_cthorpe_prod_mcc9_v08_00_00_45_extnumi_reco2_run1_all_reco2_pt1.root");

    //E.SetFile("analysisOutputRHC_GENIE_Overlay_Kaon_cthorpe_make_k0s_events_numi_rhc_reco2_REAL_reco2_reco2.root", "Kaon");
    //M.AddSample("Kaon","Kaon",E.GetPOT());

    M.SetupHistograms(15,0.275,0.625,";Invariant Mass (GeV);Events/bin");

    double signal_count = 0;
    double background_count = 0;

    double total_signal_count = 0;

    for(size_t i_s=0;i_s<SampleNames.size();i_s++){

        E.SetFile(SampleFiles.at(i_s), SampleTypes.at(i_s));
        if(SampleTypes.at(i_s) != "EXT" && SampleTypes.at(i_s) != "Data") M.AddSample(SampleNames.at(i_s),SampleTypes.at(i_s),E.GetPOT());
        else if(SampleTypes.at(i_s) == "Data") M.AddSample(SampleNames.at(i_s),SampleTypes.at(i_s),Data_POT);
        else if(SampleTypes.at(i_s) == "EXT") M.AddSample(SampleNames.at(i_s),SampleTypes.at(i_s),EXT_POT);

        for(int i = 0; i < E.GetNEvents(); i++){

            if(i % 10000 == 0) std::cout << i << "/" << E.GetNEvents() << std::endl;

            Event e = E.GetEvent(i);

            M.SetSignal(e);                
            M.AddEvent(e);

            if(e.EventIsSignal) total_signal_count += e.Weight;

            //if(!e.EventIsSignal) continue;

            bool passed_FV, passed_muon, passed_track, passed_pion, passed_WCut, passed_connected = false;

            passed_FV = M.FiducialVolumeCut(e);
            if(!passed_FV) continue;
            passed_track = M.TrackCut(e);
            if(!passed_track) continue;
            passed_pion = M.ChoosePionPairCandidates(e);
            if(!passed_pion) continue;

            /*bool correct_pair = false;

            for(size_t i_tr = 0; i_tr < e.TracklikePrimaryDaughters.size(); i_tr++){
                for(size_t j_tr = 0; j_tr < e.TracklikePrimaryDaughters.size(); j_tr++){

                    if(i_tr == j_tr) continue;
                    if(e.TracklikePrimaryDaughters.at(i_tr).Index == e.TrueDecayPionPlusIndex && e.TracklikePrimaryDaughters.at(j_tr).Index == e.TrueDecayPionMinusIndex){
                        correct_pair = true;
                    }
                }
            }

            if(!correct_pair) continue;*/

            double pionplusmomest = PionMomentum(e.DecayPionPlusCandidate.TrackLength);
            double pionminusmomest = PionMomentum(e.DecayPionMinusCandidate.TrackLength);

            double pionplusmom = pionplusmomest + 0.8*(e.DecayPionPlusCandidate.TrackTrueModMomentum - pionplusmomest);
            double pionminusmom = pionminusmomest + 0.8*(e.DecayPionMinusCandidate.TrackTrueModMomentum - pionminusmomest);

            double energy_pionPlus = sqrt(pionplusmom*pionplusmom + 0.1396*0.1396);
            double energy_pionMinus = sqrt(pionminusmom*pionminusmom + 0.1396*0.1396);

            TLorentzVector PionPlus4Momentum(e.DecayPionPlusCandidate.TrackDirectionX*pionplusmom, e.DecayPionPlusCandidate.TrackDirectionY*pionplusmom, e.DecayPionPlusCandidate.TrackDirectionZ*pionplusmom, energy_pionPlus);
            TLorentzVector PionMinus4Momentum(e.DecayPionMinusCandidate.TrackDirectionX*pionminusmom, e.DecayPionMinusCandidate.TrackDirectionY*pionminusmom, e.DecayPionMinusCandidate.TrackDirectionZ*pionminusmom, energy_pionMinus);

            TLorentzVector P2 = PionPlus4Momentum + PionMinus4Momentum;

            double invariant_mass = sqrt(P2*P2);

            //if(!e.EventIsSignal) continue;

            if(!std::isnan(invariant_mass)){
                //std::cout << invariant_mass << std::endl;
                M.FillHistograms(e, invariant_mass); 
            }

            if(invariant_mass < 0.51 && invariant_mass > 0.43){
                if(e.EventIsSignal) {
                    signal_count += e.Weight;
                }
                else {
                    background_count += e.Weight;
                }
            }    
        }
    }

    M.PrintAllCuts();

    std::cout << signal_count << std::endl;
    std::cout << total_signal_count << std::endl;
    std::cout << background_count << std::endl;

    std::cout << "Drawing histograms" << std::endl;
    M.DrawHistograms(label);

    E.Close();
}