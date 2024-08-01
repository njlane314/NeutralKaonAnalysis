R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so)
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so)

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

void PionVariables(){

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

    SampleNames.push_back("GENIE kaon");
    SampleTypes.push_back("Kaon");
    SampleFiles.push_back("analysisOutputFHC_Overlay_GENIE_Kaon_cthorpe_make_k0s_events_numi_fhc_reco2_reco2_reco2.root");

    SampleNames.push_back("GENIE kaon");
    SampleTypes.push_back("Kaon");
    SampleFiles.push_back("analysisOutputRHC_GENIE_Overlay_Kaon_cthorpe_make_k0s_events_numi_rhc_reco2_REAL_reco2_reco2.root");
    
    int bin_pion_dEdX = 20;
    double min_pion_dEdX = 0;
    double max_pion_dEdX = 10;

    TH1F* hPionPlusdEdX = new TH1F("hPionPlusdEdX", "", bin_pion_dEdX, min_pion_dEdX, max_pion_dEdX);
    TH1F* hPionMinusdEdX = new TH1F("hPionMinusdEdX", "", bin_pion_dEdX, min_pion_dEdX, max_pion_dEdX);

    int bin_pion_track_score = 10;
    double min_pion_track_score = 0.5;
    double max_pion_track_score = 1;

    TH1F* hPionPlusTrackScore = new TH1F("hPionPlusTrackScore", "", bin_pion_track_score, min_pion_track_score, max_pion_track_score);
    TH1F* hPionMinusTrackScore = new TH1F("hPionMinusTrackScore", "", bin_pion_track_score, min_pion_track_score, max_pion_track_score);

    int bin_pion_LLR = 40;
    double min_pion_LLR = -1;
    double max_pion_LLR = 1;

    TH1F* hPionPlusLLR = new TH1F("hPionPlusLLR", "", bin_pion_LLR, min_pion_LLR, max_pion_LLR);
    TH1F* hPionMinusLLR = new TH1F("hPionMinusLLR", "", bin_pion_LLR, min_pion_LLR, max_pion_LLR);

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

            if(!M.FiducialVolumeCut(e)) continue;
            if(!M.TrackCut(e)) continue;
            if(!M.ChooseMuonCandidate(e)) continue;
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
        
                    TVector3 PionPlusPosition(e.TracklikePrimaryDaughters.at(i_tr).TrackStartX,e.TracklikePrimaryDaughters.at(i_tr).TrackStartY,e.TracklikePrimaryDaughters.at(i_tr).TrackStartZ);
                    TVector3 PionMinusPosition(e.TracklikePrimaryDaughters.at(j_tr).TrackStartX,e.TracklikePrimaryDaughters.at(j_tr).TrackStartY,e.TracklikePrimaryDaughters.at(j_tr).TrackStartZ);

                    double v_pion_plus_track_score = Limit(e.TracklikePrimaryDaughters.at(i_tr).TrackShowerScore,trkscore_limits);
                    double v_pion_minus_track_score = Limit(e.TracklikePrimaryDaughters.at(j_tr).TrackShowerScore,trkscore_limits);
              
                    // Catch default dEdX fills
                    if(e.TracklikePrimaryDaughters.at(i_tr).MeandEdX_ThreePlane < 0 || e.TracklikePrimaryDaughters.at(j_tr).MeandEdX_ThreePlane < 0) continue;
                    if(std::isnan(e.TracklikePrimaryDaughters.at(i_tr).MeandEdX_ThreePlane) || std::isnan(e.TracklikePrimaryDaughters.at(j_tr).MeandEdX_ThreePlane)) continue;

                    double v_pion_plus_dEdX = Limit(e.TracklikePrimaryDaughters.at(i_tr).MeandEdX_ThreePlane,dEdX_limits);
                    double v_pion_minus_dEdX = Limit(e.TracklikePrimaryDaughters.at(j_tr).MeandEdX_ThreePlane,dEdX_limits);

                    double v_pion_plus_LLR = Limit(e.TracklikePrimaryDaughters.at(i_tr).Track_LLR_PID,LLR_limits);
                    double v_pion_minus_LLR = Limit(e.TracklikePrimaryDaughters.at(j_tr).Track_LLR_PID,LLR_limits);
            
                    if(e.GoodReco && e.TracklikePrimaryDaughters.at(i_tr).Index == e.TrueDecayPionPlusIndex && e.TracklikePrimaryDaughters.at(j_tr).Index == e.TrueDecayPionMinusIndex){ 
                        hPionPlusdEdX->Fill(v_pion_plus_dEdX);
                        hPionMinusdEdX->Fill(v_pion_minus_dEdX);
                        hPionPlusTrackScore->Fill(v_pion_plus_track_score);
                        hPionMinusTrackScore->Fill(v_pion_minus_track_score);
                        hPionPlusLLR->Fill(v_pion_plus_LLR);
                        hPionMinusLLR->Fill(v_pion_minus_LLR);
                    }
                }
            }
        }
    }

    TCanvas *c = new TCanvas("", "", 800, 600);

    hPionPlusdEdX->Scale(1.0 / hPionPlusdEdX->Integral());
    hPionMinusdEdX->Scale(1.0 / hPionMinusdEdX->Integral());

    hPionPlusdEdX->SetLineColor(kBlue);
    hPionPlusdEdX->SetLineWidth(2);
    hPionMinusdEdX->SetLineColor(kRed);
    hPionMinusdEdX->SetLineWidth(2);

    hPionPlusdEdX->Draw("HIST E");
    hPionPlusdEdX->GetXaxis()->SetTitle("dE/dx (MeV/cm)");
    hPionMinusdEdX->Draw("HIST E SAME");

    hPionPlusdEdX->SetMaximum(std::max({hPionPlusdEdX->GetMaximum(), hPionMinusdEdX->GetMaximum()}) * 1.2);

    TLegend *leg = new TLegend(0.1, 0.91, 0.9, 0.99);
    leg->SetNColumns(2); 
    leg->SetBorderSize(0);
    leg->AddEntry(hPionPlusdEdX, "Pion Plus", "l");
    leg->AddEntry(hPionMinusdEdX, "Pion Minus", "l");
    leg->Draw();

    c->SaveAs("pion_dEdx.png");

    delete hPionPlusdEdX;
    delete hPionMinusdEdX;
    delete c;

    TCanvas *c1 = new TCanvas("", "", 800, 600);

    hPionPlusTrackScore->Scale(1.0 / hPionPlusTrackScore->Integral());
    hPionMinusTrackScore->Scale(1.0 / hPionMinusTrackScore->Integral());

    hPionPlusTrackScore->SetLineColor(kBlue);
    hPionPlusTrackScore->SetLineWidth(2);
    hPionMinusTrackScore->SetLineColor(kRed);
    hPionMinusTrackScore->SetLineWidth(2);

    hPionPlusTrackScore->Draw("HIST E");
    hPionPlusTrackScore->GetXaxis()->SetTitle("Track/Shower Score");
    hPionMinusTrackScore->Draw("HIST E SAME");

    hPionPlusTrackScore->SetMaximum(std::max({hPionPlusTrackScore->GetMaximum(), hPionMinusTrackScore->GetMaximum()}) * 1.2);

    leg->Draw();

    c1->SaveAs("pion_track_score.png");

    delete hPionPlusTrackScore;
    delete hPionMinusTrackScore;
    delete c1;
    
    TCanvas *c2 = new TCanvas("", "", 800, 600);

    hPionPlusLLR->Scale(1.0 / hPionPlusLLR->Integral());
    hPionMinusLLR->Scale(1.0 / hPionMinusLLR->Integral());

    hPionPlusLLR->SetLineColor(kBlue);
    hPionPlusLLR->SetLineWidth(2);
    hPionMinusLLR->SetLineColor(kRed);
    hPionMinusLLR->SetLineWidth(2);

    hPionPlusLLR->Draw("HIST E");
    hPionPlusLLR->GetXaxis()->SetTitle("LLR PID");
    hPionMinusLLR->Draw("HIST E SAME");

    hPionPlusLLR->SetMaximum(std::max({hPionPlusLLR->GetMaximum(), hPionMinusLLR->GetMaximum()}) * 1.2);

    leg->Draw();

    c2->SaveAs("pion_LLR.png");

    delete hPionPlusLLR;
    delete hPionMinusLLR;
    delete c2;

    E.Close();

}