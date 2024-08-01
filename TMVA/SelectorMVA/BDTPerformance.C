R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so)
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so)

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

void BDTPerformance(){

    gStyle->SetOptStat(0);

    double POT = 1.25e21; // POT to scale samples to
    //double POT = 1.5e21;

    double EXT_POT = 1.0421e20;

    BuildTunes();
    SelectionParameters P = P_FHC_Tune_325_NoBDT;
    //SelectionParameters P = P_RHC_Tune_397_NoBDT;

    std::string label = "signal_bdt_selector_rhc";
    std::string SampleType = "background";

    EventAssembler E(false);
    SelectionManager M(P);
    M.ImportSelectorBDTWeights("/exp/uboone/app/users/nlane/NeutralKaonAnalysis/TMVA/SelectorMVA/dataset/weights");

    M.SetBeamMode(kFHC);
    //M.SetBeamMode(kRHC);
    
    M.SetPOT(POT);
    M.UseFluxWeight(false);
    M.UseGenWeight(false);

    SampleNames.push_back("GENIE kaon");
    SampleTypes.push_back("Kaon");
    SampleFiles.push_back("NoCosmic/analysisOutputFHC_GENIE_NoCosmic_Kaon.root");

    int binsBDT = 20;
    double minBDT = -0.4;
    double maxBDT = 0.1;

    TH1F* hTrainCorrect_BDT = new TH1F("hTrainCorrect_BDT", "", binsBDT, minBDT, maxBDT);
    TH1F* hTrainIncorrect_BDT = new TH1F("hTrainIncorrect_BDT", "", binsBDT, minBDT, maxBDT);
    TH1F* hTestCorrect_BDT = new TH1F("hTestCorrect_BDT", "", binsBDT, minBDT, maxBDT);
    TH1F* hTestIncorrect_BDT = new TH1F("hTestIncorrect_BDT", "", binsBDT, minBDT, maxBDT);

    int binssep = 20;
    double minsep = 0;
    double maxsep = 5;

    TH1F* hTrainCorrect_sep = new TH1F("hTrainCorrect_sep", "", binssep, minsep, maxsep);
    TH1F* hTrainIncorrect_sep = new TH1F("hTrainIncorrect_sep", "", binssep, minsep, maxsep);
    TH1F* hTestCorrect_sep = new TH1F("hTestCorrect_sep", "", binssep, minsep, maxsep);
    TH1F* hTestIncorrect_sep = new TH1F("hTestIncorrect_sep", "", binssep, minsep, maxsep);

    int binspion1dEdx = 20;
    double minpion1dEdx = 0;
    double maxpion1dEdx = 10;

    TH1F* hTrainCorrect_pion1dEdx = new TH1F("hTrainCorrect_pion1dEdx", "", binspion1dEdx, minpion1dEdx, maxpion1dEdx);
    TH1F* hTrainIncorrect_pion1dEdx = new TH1F("hTrainIncorrect_pion1dEdx", "", binspion1dEdx, minpion1dEdx, maxpion1dEdx);
    TH1F* hTestCorrect_pion1dEdx = new TH1F("hTestCorrect_pion1dEdx", "", binspion1dEdx, minpion1dEdx, maxpion1dEdx);
    TH1F* hTestIncorrect_pion1dEdx = new TH1F("hTestIncorrect_pion1dEdx", "", binspion1dEdx, minpion1dEdx, maxpion1dEdx);

    int binspion2dEdx = 20;
    double minpion2dEdx = 0;
    double maxpion2dEdx = 10;

    TH1F* hTrainCorrect_pion2dEdx = new TH1F("hTrainCorrect_pion2dEdx", "", binspion2dEdx, minpion2dEdx, maxpion2dEdx);
    TH1F* hTrainIncorrect_pion2dEdx = new TH1F("hTrainIncorrect_pion2dEdx", "", binspion2dEdx, minpion2dEdx, maxpion2dEdx);
    TH1F* hTestCorrect_pion2dEdx = new TH1F("hTestCorrect_pion2dEdx", "", binspion2dEdx, minpion2dEdx, maxpion2dEdx);
    TH1F* hTestIncorrect_pion2dEdx = new TH1F("hTestIncorrect_pion2dEdx", "", binspion2dEdx, minpion2dEdx, maxpion2dEdx);

    int binspion1TrckScre = 20;
    double minpion1TrckScre = 0;
    double maxpion1TrckScre = 1;

    TH1F* hTrainCorrect_pion1TrckScre = new TH1F("hTrainCorrect_pion1TrckScre", "", binspion1TrckScre, minpion1TrckScre, maxpion1TrckScre);
    TH1F* hTrainIncorrect_pion1TrckScre = new TH1F("hTrainIncorrect_pion1TrckScre", "", binspion1TrckScre, minpion1TrckScre, maxpion1TrckScre);
    TH1F* hTestCorrect_pion1TrckScre = new TH1F("hTestCorrect_pion1TrckScre", "", binspion1TrckScre, minpion1TrckScre, maxpion1TrckScre);
    TH1F* hTestIncorrect_pion1TrckScre = new TH1F("hTestIncorrect_pion1TrckScre", "", binspion1TrckScre, minpion1TrckScre, maxpion1TrckScre);

    int binspion2TrckScre = 20;
    double minpion2TrckScre = 0;
    double maxpion2TrckScre = 1;

    TH1F* hTrainCorrect_pion2TrckScre = new TH1F("hTrainCorrect_pion2TrckScre", "", binspion2TrckScre, minpion2TrckScre, maxpion2TrckScre);
    TH1F* hTrainIncorrect_pion2TrckScre = new TH1F("hTrainIncorrect_pion2TrckScre", "", binspion2TrckScre, minpion2TrckScre, maxpion2TrckScre);
    TH1F* hTestCorrect_pion2TrckScre = new TH1F("hTestCorrect_pion2TrckScre", "", binspion2TrckScre, minpion2TrckScre, maxpion2TrckScre);
    TH1F* hTestIncorrect_pion2TrckScre = new TH1F("hTestIncorrect_pion2TrckScre", "", binspion2TrckScre, minpion2TrckScre, maxpion2TrckScre);

    int binspion1LLR = 40;
    double minpion1LLR = -1;
    double maxpion1LLR = 1;

    TH1F* hTrainCorrect_pion1LLR = new TH1F("hTrainCorrect_pion1LLR", "", binspion1LLR, minpion1LLR, maxpion1LLR);
    TH1F* hTrainIncorrect_pion1LLR = new TH1F("hTrainIncorrect_pion1LLR", "", binspion1LLR, minpion1LLR, maxpion1LLR);
    TH1F* hTestCorrect_pion1LLR = new TH1F("hTestCorrect_pion1LLR", "", binspion1LLR, minpion1LLR, maxpion1LLR);
    TH1F* hTestIncorrect_pion1LLR = new TH1F("hTestIncorrect_pion1LLR", "", binspion1LLR, minpion1LLR, maxpion1LLR);

    int binspion2LLR = 40;
    double minpion2LLR = -1;
    double maxpion2LLR = 1;

    TH1F* hTrainCorrect_pion2LLR = new TH1F("hTrainCorrect_pion2LLR", "", binspion2LLR, minpion2LLR, maxpion2LLR);
    TH1F* hTrainIncorrect_pion2LLR = new TH1F("hTrainIncorrect_pion2LLR", "", binspion2LLR, minpion2LLR, maxpion2LLR);
    TH1F* hTestCorrect_pion2LLR = new TH1F("hTestCorrect_pion2LLR", "", binspion2LLR, minpion2LLR, maxpion2LLR);
    TH1F* hTestIncorrect_pion2LLR = new TH1F("hTestIncorrect_pion2LLR", "", binspion2LLR, minpion2LLR, maxpion2LLR);

    for(size_t i_s=0;i_s<SampleNames.size();i_s++){

        E.SetFile(SampleFiles.at(i_s), SampleTypes.at(i_s));
        if(SampleTypes.at(i_s) != "EXT" && SampleTypes.at(i_s) != "Data") M.AddSample(SampleNames.at(i_s),SampleTypes.at(i_s),E.GetPOT());
        else if(SampleTypes.at(i_s) == "Data") M.AddSample(SampleNames.at(i_s),SampleTypes.at(i_s),Data_POT);
        else if(SampleTypes.at(i_s) == "EXT") M.AddSample(SampleNames.at(i_s),SampleTypes.at(i_s),EXT_POT);

        size_t halfNEvents = E.GetNEvents() / 2;

        for(int i = 0; i < E.GetNEvents(); i++){           
            if(i % 10000 == 0) std::cout << i << "/" << E.GetNEvents() << std::endl;

            Event e = E.GetEvent(i);

            M.SetSignal(e);              
            M.AddEvent(e); 

            if(!M.FiducialVolumeCut(e)) continue;
            if(!M.TrackCut(e)) continue;
            //if(!M.ChooseMuonCandidate(e)) continue;
            //if(!M.ChoosePionPairCandidates(e)) continue;
            //if(!M.WCut(e)) continue;
            //if(!M.PionPairSelector(e)) continue;
            //if(!M.AnalysisBDTCut(e)) continue;       
            //if(!M.ConnectednessTest(e)) continue;           
            //if(!M.WCut(e)) continue;
            //if(!M.AngleCut(e)) continue;

            const std::pair<double,double> separation_limits = { 0 , 20 };
            const std::pair<double,double> pid_limits = { -10 , 10 };
            const std::pair<double,double> trkscore_limits = { 0 , 1.0 };
            const std::pair<double,double> dEdX_limits = { 0.0 , 20 };
            const std::pair<double,double> LLR_limits = { -1.0 , 1.0 };

            //sort through list of candiadate tracks
            for(size_t i_tr=0;i_tr<e.TracklikePrimaryDaughters.size();i_tr++){
                for(size_t j_tr=0;j_tr<e.TracklikePrimaryDaughters.size();j_tr++){

                    if(i_tr == j_tr) continue;

                    double BDT_response = M.a_SelectorBDTManager.GetScore(e.TracklikePrimaryDaughters.at(i_tr),e.TracklikePrimaryDaughters.at(j_tr));
                    if(BDT_response == -1000) continue;
        
                    TVector3 PionPlusPosition(e.TracklikePrimaryDaughters.at(i_tr).TrackStartX,e.TracklikePrimaryDaughters.at(i_tr).TrackStartY,e.TracklikePrimaryDaughters.at(i_tr).TrackStartZ);
                    TVector3 PionMinusPosition(e.TracklikePrimaryDaughters.at(j_tr).TrackStartX,e.TracklikePrimaryDaughters.at(j_tr).TrackStartY,e.TracklikePrimaryDaughters.at(j_tr).TrackStartZ);

                    double v_pion1_trkscore = Limit(e.TracklikePrimaryDaughters.at(i_tr).TrackShowerScore,trkscore_limits);
                    double v_pion2_trkscore = Limit(e.TracklikePrimaryDaughters.at(j_tr).TrackShowerScore,trkscore_limits);
                    if(v_pion1_trkscore == 0) continue;
                    if(v_pion2_trkscore == 0) continue;

                    // Catch default dEdX fills
                    if(e.TracklikePrimaryDaughters.at(i_tr).MeandEdX_ThreePlane < 0 || e.TracklikePrimaryDaughters.at(j_tr).MeandEdX_ThreePlane < 0) continue;
                    if(std::isnan(e.TracklikePrimaryDaughters.at(i_tr).MeandEdX_ThreePlane) || std::isnan(e.TracklikePrimaryDaughters.at(j_tr).MeandEdX_ThreePlane)) continue;

                    double v_pion1_dEdX = Limit(e.TracklikePrimaryDaughters.at(i_tr).MeandEdX_ThreePlane,dEdX_limits);
                    double v_pion2_dEdX = Limit(e.TracklikePrimaryDaughters.at(j_tr).MeandEdX_ThreePlane,dEdX_limits);
                    if(v_pion1_dEdX == 0) continue;
                    if(v_pion2_dEdX == 0) continue;

                    double v_pion1_LLR = Limit(e.TracklikePrimaryDaughters.at(i_tr).Track_LLR_PID,LLR_limits);
                    double v_pion2_LLR = Limit(e.TracklikePrimaryDaughters.at(j_tr).Track_LLR_PID,LLR_limits);

                    double v_separation = Limit((PionPlusPosition-PionMinusPosition).Mag(),separation_limits);
                    if(v_separation <= 0) continue;
            
                    if(e.GoodReco && e.TracklikePrimaryDaughters.at(i_tr).Index == e.TrueDecayPionPlusIndex && e.TracklikePrimaryDaughters.at(j_tr).Index == e.TrueDecayPionMinusIndex){
                        // pair is correct
                        if(i < halfNEvents){
                            // training
                            hTrainCorrect_BDT->Fill(BDT_response);
                            hTrainCorrect_sep->Fill(v_separation);
                            hTrainCorrect_pion1dEdx->Fill(v_pion1_dEdX);
                            hTrainCorrect_pion2dEdx->Fill(v_pion2_dEdX);
                            hTrainCorrect_pion1TrckScre->Fill(v_pion1_trkscore);
                            hTrainCorrect_pion2TrckScre->Fill(v_pion2_trkscore);
                            hTrainCorrect_pion1LLR->Fill(v_pion1_LLR);
                            hTrainCorrect_pion2LLR->Fill(v_pion2_LLR);
                        }
                        else{
                            // testing
                            hTestCorrect_BDT->Fill(BDT_response);
                            hTestCorrect_sep->Fill(v_separation);
                            hTestCorrect_pion1dEdx->Fill(v_pion1_dEdX);
                            hTestCorrect_pion2dEdx->Fill(v_pion2_dEdX);
                            hTestCorrect_pion1TrckScre->Fill(v_pion1_trkscore);
                            hTestCorrect_pion2TrckScre->Fill(v_pion2_trkscore);
                            hTestCorrect_pion1LLR->Fill(v_pion1_LLR);
                            hTestCorrect_pion2LLR->Fill(v_pion2_LLR);
                        }
                    }
                    else{
                        // pair is incorrect
                        if(i < halfNEvents){
                            // training
                            hTrainIncorrect_BDT->Fill(BDT_response);
                            hTrainIncorrect_sep->Fill(v_separation);
                            hTrainIncorrect_pion1dEdx->Fill(v_pion1_dEdX);
                            hTrainIncorrect_pion2dEdx->Fill(v_pion2_dEdX);
                            hTrainIncorrect_pion1TrckScre->Fill(v_pion1_trkscore);
                            hTrainIncorrect_pion2TrckScre->Fill(v_pion2_trkscore);
                            hTrainIncorrect_pion1LLR->Fill(v_pion1_LLR);
                            hTrainIncorrect_pion2LLR->Fill(v_pion2_LLR);
                        }
                        else{
                            // testing
                            hTestIncorrect_BDT->Fill(BDT_response);
                            hTestIncorrect_sep->Fill(v_separation);
                            hTestIncorrect_pion1dEdx->Fill(v_pion1_dEdX);
                            hTestIncorrect_pion2dEdx->Fill(v_pion2_dEdX);
                            hTestIncorrect_pion1TrckScre->Fill(v_pion1_trkscore);
                            hTestIncorrect_pion2TrckScre->Fill(v_pion2_trkscore);
                            hTestIncorrect_pion1LLR->Fill(v_pion1_LLR);
                            hTestIncorrect_pion2LLR->Fill(v_pion2_LLR);
                        }
                    }

                }
            }
           
            //sort through list of candiadate tracks
            for(size_t i_tr=0;i_tr<e.ShowerlikePrimaryDaughters.size();i_tr++){
                for(size_t j_tr=0;j_tr<e.TracklikePrimaryDaughters.size();j_tr++){

                    //if(i_tr == j_tr) continue;

                    double BDT_response = M.a_SelectorBDTManager.GetScore(e.ShowerlikePrimaryDaughters.at(i_tr),e.TracklikePrimaryDaughters.at(j_tr));
                    if(BDT_response == -1000) continue;
            

                    TVector3 PionPlusPosition(e.ShowerlikePrimaryDaughters.at(i_tr).TrackStartX,e.ShowerlikePrimaryDaughters.at(i_tr).TrackStartY,e.ShowerlikePrimaryDaughters.at(i_tr).TrackStartZ);
                    TVector3 PionMinusPosition(e.TracklikePrimaryDaughters.at(j_tr).TrackStartX,e.TracklikePrimaryDaughters.at(j_tr).TrackStartY,e.TracklikePrimaryDaughters.at(j_tr).TrackStartZ);

                    double v_pion1_trkscore = Limit(e.ShowerlikePrimaryDaughters.at(i_tr).TrackShowerScore,trkscore_limits);
                    double v_pion2_trkscore = Limit(e.TracklikePrimaryDaughters.at(j_tr).TrackShowerScore,trkscore_limits);

                    // Catch default dEdX fills
                    if(e.ShowerlikePrimaryDaughters.at(i_tr).MeandEdX_ThreePlane < 0 || e.TracklikePrimaryDaughters.at(j_tr).MeandEdX_ThreePlane < 0) continue;
                    if(std::isnan(e.ShowerlikePrimaryDaughters.at(i_tr).MeandEdX_ThreePlane) || std::isnan(e.TracklikePrimaryDaughters.at(j_tr).MeandEdX_ThreePlane)) continue;

                    double v_pion1_dEdX = Limit(e.ShowerlikePrimaryDaughters.at(i_tr).MeandEdX_ThreePlane,dEdX_limits);
                    double v_pion2_dEdX = Limit(e.TracklikePrimaryDaughters.at(j_tr).MeandEdX_ThreePlane,dEdX_limits);

                    double v_pion1_LLR = Limit(e.ShowerlikePrimaryDaughters.at(i_tr).Track_LLR_PID,LLR_limits);
                    double v_pion2_LLR = Limit(e.TracklikePrimaryDaughters.at(j_tr).Track_LLR_PID,LLR_limits);

                    double v_separation = Limit((PionPlusPosition-PionMinusPosition).Mag(),separation_limits);
                    if(v_separation <= 0) continue;
            
                    if(e.GoodReco && e.ShowerlikePrimaryDaughters.at(i_tr).Index == e.TrueDecayPionPlusIndex && e.TracklikePrimaryDaughters.at(j_tr).Index == e.TrueDecayPionMinusIndex){
                        // pair is correct
                        if(i < halfNEvents){
                            // training
                            hTrainCorrect_BDT->Fill(BDT_response);
                            hTrainCorrect_sep->Fill(v_separation);
                            hTrainCorrect_pion1dEdx->Fill(v_pion1_dEdX);
                            hTrainCorrect_pion2dEdx->Fill(v_pion2_dEdX);
                            hTrainCorrect_pion1TrckScre->Fill(v_pion1_trkscore);
                            hTrainCorrect_pion2TrckScre->Fill(v_pion2_trkscore);
                            hTrainCorrect_pion1LLR->Fill(v_pion1_LLR);
                            hTrainCorrect_pion2LLR->Fill(v_pion2_LLR);
                        }
                        else{
                            // testing
                            hTestCorrect_BDT->Fill(BDT_response);
                            hTestCorrect_sep->Fill(v_separation);
                            hTestCorrect_pion1dEdx->Fill(v_pion1_dEdX);
                            hTestCorrect_pion2dEdx->Fill(v_pion2_dEdX);
                            hTestCorrect_pion1TrckScre->Fill(v_pion1_trkscore);
                            hTestCorrect_pion2TrckScre->Fill(v_pion2_trkscore);
                            hTestCorrect_pion1LLR->Fill(v_pion1_LLR);
                            hTestCorrect_pion2LLR->Fill(v_pion2_LLR);
                        }
                    }
                    else{
                        // pair is incorrect
                        if(i < halfNEvents){
                            // training
                            hTrainIncorrect_BDT->Fill(BDT_response);
                            hTrainIncorrect_sep->Fill(v_separation);
                            hTrainIncorrect_pion1dEdx->Fill(v_pion1_dEdX);
                            hTrainIncorrect_pion2dEdx->Fill(v_pion2_dEdX);
                            hTrainIncorrect_pion1TrckScre->Fill(v_pion1_trkscore);
                            hTrainIncorrect_pion2TrckScre->Fill(v_pion2_trkscore);
                            hTrainIncorrect_pion1LLR->Fill(v_pion1_LLR);
                            hTrainIncorrect_pion2LLR->Fill(v_pion2_LLR);
                        }
                        else{
                            // testing
                            hTestIncorrect_BDT->Fill(BDT_response);
                            hTestIncorrect_sep->Fill(v_separation);
                            hTestIncorrect_pion1dEdx->Fill(v_pion1_dEdX);
                            hTestIncorrect_pion2dEdx->Fill(v_pion2_dEdX);
                            hTestIncorrect_pion1TrckScre->Fill(v_pion1_trkscore);
                            hTestIncorrect_pion2TrckScre->Fill(v_pion2_trkscore);
                            hTestIncorrect_pion1LLR->Fill(v_pion1_LLR);
                            hTestIncorrect_pion2LLR->Fill(v_pion2_LLR);
                        }
                    }

                }
            }
    
            //sort through list of candiadate tracks
            for(size_t i_tr=0;i_tr<e.ShowerlikePrimaryDaughters.size();i_tr++){
                for(size_t j_tr=0;j_tr<e.ShowerlikePrimaryDaughters.size();j_tr++){

                    if(i_tr == j_tr) continue;

                    double BDT_response = M.a_SelectorBDTManager.GetScore(e.ShowerlikePrimaryDaughters.at(i_tr),e.ShowerlikePrimaryDaughters.at(j_tr));
                    if(BDT_response == -1000) continue;
           

                    TVector3 PionPlusPosition(e.ShowerlikePrimaryDaughters.at(i_tr).TrackStartX,e.ShowerlikePrimaryDaughters.at(i_tr).TrackStartY,e.ShowerlikePrimaryDaughters.at(i_tr).TrackStartZ);
                    TVector3 PionMinusPosition(e.ShowerlikePrimaryDaughters.at(j_tr).TrackStartX,e.ShowerlikePrimaryDaughters.at(j_tr).TrackStartY,e.ShowerlikePrimaryDaughters.at(j_tr).TrackStartZ);

                    double v_pion1_trkscore = Limit(e.ShowerlikePrimaryDaughters.at(i_tr).TrackShowerScore,trkscore_limits);
                    double v_pion2_trkscore = Limit(e.ShowerlikePrimaryDaughters.at(j_tr).TrackShowerScore,trkscore_limits);

                    // Catch default dEdX fills
                    if(e.ShowerlikePrimaryDaughters.at(i_tr).MeandEdX_ThreePlane < 0 || e.ShowerlikePrimaryDaughters.at(j_tr).MeandEdX_ThreePlane < 0) continue;
                    if(std::isnan(e.ShowerlikePrimaryDaughters.at(i_tr).MeandEdX_ThreePlane) || std::isnan(e.ShowerlikePrimaryDaughters.at(j_tr).MeandEdX_ThreePlane)) continue;

                    double v_pion1_dEdX = Limit(e.ShowerlikePrimaryDaughters.at(i_tr).MeandEdX_ThreePlane,dEdX_limits);
                    double v_pion2_dEdX = Limit(e.ShowerlikePrimaryDaughters.at(j_tr).MeandEdX_ThreePlane,dEdX_limits);

                    double v_pion1_LLR = Limit(e.ShowerlikePrimaryDaughters.at(i_tr).Track_LLR_PID,LLR_limits);
                    double v_pion2_LLR = Limit(e.ShowerlikePrimaryDaughters.at(j_tr).Track_LLR_PID,LLR_limits);

                    double v_separation = Limit((PionPlusPosition-PionMinusPosition).Mag(),separation_limits);
                    if(v_separation <= 0) continue;
                               
                    if(e.GoodReco && e.ShowerlikePrimaryDaughters.at(i_tr).Index == e.TrueDecayPionPlusIndex && e.ShowerlikePrimaryDaughters.at(j_tr).Index == e.TrueDecayPionMinusIndex){
                        // pair is correct
                        if(i < halfNEvents){
                            // training
                            hTrainCorrect_BDT->Fill(BDT_response);
                            hTrainCorrect_sep->Fill(v_separation);
                            hTrainCorrect_pion1dEdx->Fill(v_pion1_dEdX);
                            hTrainCorrect_pion2dEdx->Fill(v_pion2_dEdX);
                            hTrainCorrect_pion1TrckScre->Fill(v_pion1_trkscore);
                            hTrainCorrect_pion2TrckScre->Fill(v_pion2_trkscore);
                            hTrainCorrect_pion1LLR->Fill(v_pion1_LLR);
                            hTrainCorrect_pion2LLR->Fill(v_pion2_LLR);
                        }
                        else{
                            // testing
                            hTestCorrect_BDT->Fill(BDT_response);
                            hTestCorrect_sep->Fill(v_separation);
                            hTestCorrect_pion1dEdx->Fill(v_pion1_dEdX);
                            hTestCorrect_pion2dEdx->Fill(v_pion2_dEdX);
                            hTestCorrect_pion1TrckScre->Fill(v_pion1_trkscore);
                            hTestCorrect_pion2TrckScre->Fill(v_pion2_trkscore);
                            hTestCorrect_pion1LLR->Fill(v_pion1_LLR);
                            hTestCorrect_pion2LLR->Fill(v_pion2_LLR);
                        }
                    }
                    else{
                        // pair is incorrect
                        if(i < halfNEvents){
                            // training
                            hTrainIncorrect_BDT->Fill(BDT_response);
                            hTrainIncorrect_sep->Fill(v_separation);
                            hTrainIncorrect_pion1dEdx->Fill(v_pion1_dEdX);
                            hTrainIncorrect_pion2dEdx->Fill(v_pion2_dEdX);
                            hTrainIncorrect_pion1TrckScre->Fill(v_pion1_trkscore);
                            hTrainIncorrect_pion2TrckScre->Fill(v_pion2_trkscore);
                            hTrainIncorrect_pion1LLR->Fill(v_pion1_LLR);
                            hTrainIncorrect_pion2LLR->Fill(v_pion2_LLR);
                        }
                        else{
                            // testing
                            hTestIncorrect_BDT->Fill(BDT_response);
                            hTestIncorrect_sep->Fill(v_separation);
                            hTestIncorrect_pion1dEdx->Fill(v_pion1_dEdX);
                            hTestIncorrect_pion2dEdx->Fill(v_pion2_dEdX);
                            hTestIncorrect_pion1TrckScre->Fill(v_pion1_trkscore);
                            hTestIncorrect_pion2TrckScre->Fill(v_pion2_trkscore);
                            hTestIncorrect_pion1LLR->Fill(v_pion1_LLR);
                            hTestIncorrect_pion2LLR->Fill(v_pion2_LLR);
                        }
                    }

                }
            }
        }
    }

    TCanvas *c = new TCanvas("", "", 800, 600);

    hTrainCorrect_BDT->Scale(1.0 / hTrainCorrect_BDT->Integral());
    hTrainIncorrect_BDT->Scale(1.0 / hTrainIncorrect_BDT->Integral());
    hTestCorrect_BDT->Scale(1.0 / hTestCorrect_BDT->Integral());
    hTestIncorrect_BDT->Scale(1.0 / hTestIncorrect_BDT->Integral());

    hTrainCorrect_BDT->SetLineColor(kBlue);
    hTrainCorrect_BDT->SetLineWidth(2);
    hTrainIncorrect_BDT->SetLineColor(kGreen);
    hTrainIncorrect_BDT->SetLineWidth(2);
    hTestCorrect_BDT->SetLineColor(kRed);
    hTestCorrect_BDT->SetLineWidth(2);
    hTestIncorrect_BDT->SetLineColor(kMagenta);
    hTestIncorrect_BDT->SetLineWidth(2);

    hTrainCorrect_BDT->Draw("HIST E");
    hTrainCorrect_BDT->GetXaxis()->SetTitle("BDT Response");
    hTrainIncorrect_BDT->Draw("HIST E SAME");
    hTestCorrect_BDT->Draw("HIST E SAME");
    hTestIncorrect_BDT->Draw("HIST E SAME");

    hTrainCorrect_BDT->SetMaximum(std::max({hTrainCorrect_BDT->GetMaximum(), hTrainIncorrect_BDT->GetMaximum(), hTestCorrect_BDT->GetMaximum(), hTestIncorrect_BDT->GetMaximum()}) * 1.2);


    TLegend *leg = new TLegend(0.1, 0.91, 0.9, 0.99);
    leg->SetNColumns(4); 
    leg->SetBorderSize(0);
    leg->AddEntry(hTrainCorrect_BDT, "Train Correct", "l");
    leg->AddEntry(hTrainIncorrect_BDT, "Train Incorrect", "l");
    leg->AddEntry(hTestCorrect_BDT, "Test Correct", "l");
    leg->AddEntry(hTestIncorrect_BDT, "Test Incorrect", "l");
    leg->Draw();

    c->SaveAs("BDT.png");

    delete hTrainCorrect_BDT;
    delete hTrainIncorrect_BDT;
    delete hTestCorrect_BDT;
    delete hTestIncorrect_BDT;
    delete c;

    TCanvas *c1 = new TCanvas("", "", 800, 600);

    hTrainCorrect_sep->Scale(1.0 / hTrainCorrect_sep->Integral());
    hTrainIncorrect_sep->Scale(1.0 / hTrainIncorrect_sep->Integral());
    hTestCorrect_sep->Scale(1.0 / hTestCorrect_sep->Integral());
    hTestIncorrect_sep->Scale(1.0 / hTestIncorrect_sep->Integral());

    hTrainCorrect_sep->SetLineColor(kBlue);
    hTrainCorrect_sep->SetLineWidth(2);
    hTrainIncorrect_sep->SetLineColor(kGreen);
    hTrainIncorrect_sep->SetLineWidth(2);
    hTestCorrect_sep->SetLineColor(kRed);
    hTestCorrect_sep->SetLineWidth(2);
    hTestIncorrect_sep->SetLineColor(kMagenta);
    hTestIncorrect_sep->SetLineWidth(2);

    hTrainCorrect_sep->Draw("HIST E");
    hTrainCorrect_sep->GetXaxis()->SetTitle("Separation (cm)");
    hTrainIncorrect_sep->Draw("HIST E SAME");
    hTestCorrect_sep->Draw("HIST E SAME");
    hTestIncorrect_sep->Draw("HIST E SAME");

    hTrainCorrect_sep->SetMaximum(std::max({hTrainCorrect_sep->GetMaximum(), hTrainIncorrect_sep->GetMaximum(), hTestCorrect_sep->GetMaximum(), hTestIncorrect_sep->GetMaximum()}) * 1.2);

    leg->Draw();

    c1->SaveAs("separation.png");

    delete hTrainCorrect_sep;
    delete hTrainIncorrect_sep;
    delete hTestCorrect_sep;
    delete hTestIncorrect_sep;
    delete c1;

    TCanvas *c2 = new TCanvas("", "", 800, 600);

    hTrainCorrect_pion1dEdx->Scale(1.0 / hTrainCorrect_pion1dEdx->Integral());
    hTrainIncorrect_pion1dEdx->Scale(1.0 / hTrainIncorrect_pion1dEdx->Integral());
    hTestCorrect_pion1dEdx->Scale(1.0 / hTestCorrect_pion1dEdx->Integral());
    hTestIncorrect_pion1dEdx->Scale(1.0 / hTestIncorrect_pion1dEdx->Integral());

    hTrainCorrect_pion1dEdx->SetLineColor(kBlue);
    hTrainCorrect_pion1dEdx->SetLineWidth(2);
    hTrainIncorrect_pion1dEdx->SetLineColor(kGreen);
    hTrainIncorrect_pion1dEdx->SetLineWidth(2);
    hTestCorrect_pion1dEdx->SetLineColor(kRed);
    hTestCorrect_pion1dEdx->SetLineWidth(2);
    hTestIncorrect_pion1dEdx->SetLineColor(kMagenta);
    hTestIncorrect_pion1dEdx->SetLineWidth(2);

    hTrainCorrect_pion1dEdx->Draw("HIST E");
    hTrainCorrect_pion1dEdx->GetXaxis()->SetTitle("Primary Pion dE/dX (MeV/cm)");
    hTrainIncorrect_pion1dEdx->Draw("HIST E SAME");
    hTestCorrect_pion1dEdx->Draw("HIST E SAME");
    hTestIncorrect_pion1dEdx->Draw("HIST E SAME");

    hTrainCorrect_pion1dEdx->SetMaximum(std::max({hTrainCorrect_pion1dEdx->GetMaximum(), hTrainIncorrect_pion1dEdx->GetMaximum(), hTestCorrect_pion1dEdx->GetMaximum(), hTestIncorrect_pion1dEdx->GetMaximum()}) * 1.2);

    leg->Draw();

    c2->SaveAs("pion1dEdx.png");

    delete hTrainCorrect_pion1dEdx;
    delete hTrainIncorrect_pion1dEdx;
    delete hTestCorrect_pion1dEdx;
    delete hTestIncorrect_pion1dEdx;
    delete c2;

    TCanvas *c3 = new TCanvas("", "", 800, 600);

    hTrainCorrect_pion2dEdx->Scale(1.0 / hTrainCorrect_pion2dEdx->Integral());
    hTrainIncorrect_pion2dEdx->Scale(1.0 / hTrainIncorrect_pion2dEdx->Integral());
    hTestCorrect_pion2dEdx->Scale(1.0 / hTestCorrect_pion2dEdx->Integral());
    hTestIncorrect_pion2dEdx->Scale(1.0 / hTestIncorrect_pion2dEdx->Integral());

    hTrainCorrect_pion2dEdx->SetLineColor(kBlue);
    hTrainCorrect_pion2dEdx->SetLineWidth(2);
    hTrainIncorrect_pion2dEdx->SetLineColor(kGreen);
    hTrainIncorrect_pion2dEdx->SetLineWidth(2);
    hTestCorrect_pion2dEdx->SetLineColor(kRed);
    hTestCorrect_pion2dEdx->SetLineWidth(2);
    hTestIncorrect_pion2dEdx->SetLineColor(kMagenta);
    hTestIncorrect_pion2dEdx->SetLineWidth(2);

    hTrainCorrect_pion2dEdx->Draw("HIST E");
    hTrainCorrect_pion2dEdx->GetXaxis()->SetTitle("Secondary Pion dE/dX (MeV/cm)");
    hTrainIncorrect_pion2dEdx->Draw("HIST E SAME");
    hTestCorrect_pion2dEdx->Draw("HIST E SAME");
    hTestIncorrect_pion2dEdx->Draw("HIST E SAME");

    hTrainCorrect_pion2dEdx->SetMaximum(std::max({hTrainCorrect_pion2dEdx->GetMaximum(), hTrainIncorrect_pion2dEdx->GetMaximum(), hTestCorrect_pion2dEdx->GetMaximum(), hTestIncorrect_pion2dEdx->GetMaximum()}) * 1.2);

    leg->Draw();

    c3->SaveAs("pion2dEdx.png");

    delete hTrainCorrect_pion2dEdx;
    delete hTrainIncorrect_pion2dEdx;
    delete hTestCorrect_pion2dEdx;
    delete hTestIncorrect_pion2dEdx;
    delete c3;

    TCanvas *c4 = new TCanvas("", "", 800, 600);

    hTrainCorrect_pion1TrckScre->Scale(1.0 / hTrainCorrect_pion1TrckScre->Integral());
    hTrainIncorrect_pion1TrckScre->Scale(1.0 / hTrainIncorrect_pion1TrckScre->Integral());
    hTestCorrect_pion1TrckScre->Scale(1.0 / hTestCorrect_pion1TrckScre->Integral());
    hTestIncorrect_pion1TrckScre->Scale(1.0 / hTestIncorrect_pion1TrckScre->Integral());

    hTrainCorrect_pion1TrckScre->SetLineColor(kBlue);
    hTrainCorrect_pion1TrckScre->SetLineWidth(2);
    hTrainIncorrect_pion1TrckScre->SetLineColor(kGreen);
    hTrainIncorrect_pion1TrckScre->SetLineWidth(2);
    hTestCorrect_pion1TrckScre->SetLineColor(kRed);
    hTestCorrect_pion1TrckScre->SetLineWidth(2);
    hTestIncorrect_pion1TrckScre->SetLineColor(kMagenta);
    hTestIncorrect_pion1TrckScre->SetLineWidth(2);

    hTrainCorrect_pion1TrckScre->Draw("HIST E");
    hTrainCorrect_pion1TrckScre->GetXaxis()->SetTitle("Primary Pion Track/Shower Score");
    hTrainIncorrect_pion1TrckScre->Draw("HIST E SAME");
    hTestCorrect_pion1TrckScre->Draw("HIST E SAME");
    hTestIncorrect_pion1TrckScre->Draw("HIST E SAME");

    hTrainCorrect_pion1TrckScre->SetMaximum(std::max({hTrainCorrect_pion1TrckScre->GetMaximum(), hTrainIncorrect_pion1TrckScre->GetMaximum(), hTestCorrect_pion1TrckScre->GetMaximum(), hTestIncorrect_pion1TrckScre->GetMaximum()}) * 1.2);

    leg->Draw();

    c4->SaveAs("pion1TrckScre.png");

    delete hTrainCorrect_pion1TrckScre;
    delete hTrainIncorrect_pion1TrckScre;
    delete hTestCorrect_pion1TrckScre;
    delete hTestIncorrect_pion1TrckScre;
    delete c4;

    TCanvas *c5 = new TCanvas("", "", 800, 600);

    hTrainCorrect_pion2TrckScre->Scale(1.0 / hTrainCorrect_pion2TrckScre->Integral());
    hTrainIncorrect_pion2TrckScre->Scale(1.0 / hTrainIncorrect_pion2TrckScre->Integral());
    hTestCorrect_pion2TrckScre->Scale(1.0 / hTestCorrect_pion2TrckScre->Integral());
    hTestIncorrect_pion2TrckScre->Scale(1.0 / hTestIncorrect_pion2TrckScre->Integral());

    hTrainCorrect_pion2TrckScre->SetLineColor(kBlue);
    hTrainCorrect_pion2TrckScre->SetLineWidth(2);
    hTrainIncorrect_pion2TrckScre->SetLineColor(kGreen);
    hTrainIncorrect_pion2TrckScre->SetLineWidth(2);
    hTestCorrect_pion2TrckScre->SetLineColor(kRed);
    hTestCorrect_pion2TrckScre->SetLineWidth(2);
    hTestIncorrect_pion2TrckScre->SetLineColor(kMagenta);
    hTestIncorrect_pion2TrckScre->SetLineWidth(2);

    hTrainCorrect_pion2TrckScre->Draw("HIST E");
    hTrainCorrect_pion2TrckScre->GetXaxis()->SetTitle("Secondary Pion Track/Shower Score");
    hTrainIncorrect_pion2TrckScre->Draw("HIST E SAME");
    hTestCorrect_pion2TrckScre->Draw("HIST E SAME");
    hTestIncorrect_pion2TrckScre->Draw("HIST E SAME");

    hTrainCorrect_pion2TrckScre->SetMaximum(std::max({hTrainCorrect_pion2TrckScre->GetMaximum(), hTrainIncorrect_pion2TrckScre->GetMaximum(), hTestCorrect_pion2TrckScre->GetMaximum(), hTestIncorrect_pion2TrckScre->GetMaximum()}) * 1.2);

    leg->Draw();

    c5->SaveAs("pion2TrckScre.png");

    delete hTrainCorrect_pion2TrckScre;
    delete hTrainIncorrect_pion2TrckScre;
    delete hTestCorrect_pion2TrckScre;
    delete hTestIncorrect_pion2TrckScre;
    delete c5;

    TCanvas *c6 = new TCanvas("", "", 800, 600);

    hTrainCorrect_pion1LLR->Scale(1.0 / hTrainCorrect_pion1LLR->Integral());
    hTrainIncorrect_pion1LLR->Scale(1.0 / hTrainIncorrect_pion1LLR->Integral());
    hTestCorrect_pion1LLR->Scale(1.0 / hTestCorrect_pion1LLR->Integral());
    hTestIncorrect_pion1LLR->Scale(1.0 / hTestIncorrect_pion1LLR->Integral());

    hTrainCorrect_pion1LLR->SetLineColor(kBlue);
    hTrainCorrect_pion1LLR->SetLineWidth(2);
    hTrainIncorrect_pion1LLR->SetLineColor(kGreen);
    hTrainIncorrect_pion1LLR->SetLineWidth(2);
    hTestCorrect_pion1LLR->SetLineColor(kRed);
    hTestCorrect_pion1LLR->SetLineWidth(2);
    hTestIncorrect_pion1LLR->SetLineColor(kMagenta);
    hTestIncorrect_pion1LLR->SetLineWidth(2);

    hTrainCorrect_pion1LLR->Draw("HIST E");
    hTrainCorrect_pion1LLR->GetXaxis()->SetTitle("Primary Pion LLR PID");
    hTrainIncorrect_pion1LLR->Draw("HIST E SAME");
    hTestCorrect_pion1LLR->Draw("HIST E SAME");
    hTestIncorrect_pion1LLR->Draw("HIST E SAME");

    hTrainCorrect_pion1LLR->SetMaximum(std::max({hTrainCorrect_pion1LLR->GetMaximum(), hTrainIncorrect_pion1LLR->GetMaximum(), hTestCorrect_pion1LLR->GetMaximum(), hTestIncorrect_pion1LLR->GetMaximum()}) * 1.2);

    leg->Draw();

    c6->SaveAs("pion1LLR.png");

    delete hTrainCorrect_pion1LLR;
    delete hTrainIncorrect_pion1LLR;
    delete hTestCorrect_pion1LLR;
    delete hTestIncorrect_pion1LLR;
    delete c6;

    TCanvas *c7 = new TCanvas("", "", 800, 600);

    hTrainCorrect_pion2LLR->Scale(1.0 / hTrainCorrect_pion2LLR->Integral());
    hTrainIncorrect_pion2LLR->Scale(1.0 / hTrainIncorrect_pion2LLR->Integral());
    hTestCorrect_pion2LLR->Scale(1.0 / hTestCorrect_pion2LLR->Integral());
    hTestIncorrect_pion2LLR->Scale(1.0 / hTestIncorrect_pion2LLR->Integral());

    hTrainCorrect_pion2LLR->SetLineColor(kBlue);
    hTrainCorrect_pion2LLR->SetLineWidth(2);
    hTrainIncorrect_pion2LLR->SetLineColor(kGreen);
    hTrainIncorrect_pion2LLR->SetLineWidth(2);
    hTestCorrect_pion2LLR->SetLineColor(kRed);
    hTestCorrect_pion2LLR->SetLineWidth(2);
    hTestIncorrect_pion2LLR->SetLineColor(kMagenta);
    hTestIncorrect_pion2LLR->SetLineWidth(2);

    hTrainCorrect_pion2LLR->Draw("HIST E");
    hTrainCorrect_pion2LLR->GetXaxis()->SetTitle("Secondary Pion LLR PID");
    hTrainIncorrect_pion2LLR->Draw("HIST E SAME");
    hTestCorrect_pion2LLR->Draw("HIST E SAME");
    hTestIncorrect_pion2LLR->Draw("HIST E SAME");

    hTrainCorrect_pion2LLR->SetMaximum(std::max({hTrainCorrect_pion2LLR->GetMaximum(), hTrainIncorrect_pion2LLR->GetMaximum(), hTestCorrect_pion2LLR->GetMaximum(), hTestIncorrect_pion2LLR->GetMaximum()}) * 1.2);

    leg->Draw();

    c7->SaveAs("pion2LLR.png");

    delete hTrainCorrect_pion2LLR;
    delete hTrainIncorrect_pion2LLR;
    delete hTestCorrect_pion2LLR;
    delete hTestIncorrect_pion2LLR;
    delete c7;

    E.Close();

}