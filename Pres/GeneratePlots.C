R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so);
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so);

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

void GeneratePlots(){

    double POT = 1.0e21; 

    BuildTunes();
    SelectionParameters P = P_FHC_Tune_325_NoBDT;

    std::string label = "test";
    std::string SampleType = "background";

    EventAssembler E(false);
    SelectionManager M(P);
    M.SetPOT(POT);
    M.UseFluxWeight(false);
    M.UseGenWeight(false);

    //M.SetupHistograms(10,0,10.0,";Neutrino Energy (GeV);Events/bin");
    //M.SetupHistograms(16,0.,0.8,";Reconstructed Invariant Mass of Pion Pair (GeV);Events/bin");
    M.SetupHistograms(10,0.,10,";Shower Multiplicity;Events/bin");

    double Signal = 0.0;
    double Signal_var = 0.0;

    E.SetFile("analysisOutputFHC_GENIE_Overlay_Kaon.root", "Background");
    //E.SetFile("analysisOutputFHC_GENIE_Background_Overlay_prodgenie_numi_uboone_overlay_fhc_mcc9_run1_v28_v2_sample0.root","Background");
    M.AddSample("Background","Background",E.GetPOT());

    TEfficiency* pFiducalEfficX = new TEfficiency("pFiducalEffic", ";Interaction Vertex X (cm); Entries/bin", 25, 0, 250);
    TEfficiency* pFiducalEfficY = new TEfficiency("pFiducalEffic", ";Interaction Vertex Y (cm); Entries/bin", 20, -100, 100);
    TEfficiency* pFiducalEfficZ = new TEfficiency("pFiducalEffic", ";Interaction Vertex Z (cm); Entries/bin", 50, 0, 1000);

    TEfficiency* pMuonEffic = new TEfficiency("pMuonEffic", ";Neutrino Energy (GeV); Entries/bin", 28, 0, 14);
    TEfficiency* pMuonMomEffic = new TEfficiency("pMuonMomEffic", ";True Muon Momentum (GeV/c); Entries/bin", 20, 0, 10);
    TEfficiency* pSelectorEffic = new TEfficiency("pSelectorEffic", ";Neutrino Energy (GeV); Entries/bin", 10, 0, 10);

    TH2F *hPionMomenta = new TH2F("hPionMomenta", ";True #pi^{+} Momentum (GeV/c);True #pi^{-} Momentum (GeV/c)", 
                    12, 0, 1.2, 12, 0, 1.2);
    TH2F *hPionPlusRecoMomenta = new TH2F("hPionPlusRecoMomenta", ";#pi^{+} True Momentum (GeV/c);#pi^{+} Reconstructed Momentum (GeV/c)", 
                    150, 0, 1.5, 150, 0, 1.5);
    TH2F *hPionMinusRecoMomenta = new TH2F("hPionMinusRecoMomenta", ";#pi^{-} True Momentum (GeV/c);#pi^{-} Reconstructed Momentum (GeV/c)", 
                    150, 0, 1.5, 150, 0, 1.5);
    
    TH2F *hPionMinusTravel = new TH2F("hPionMinusTravel", ";True #pi^{+} Travel (cm);Reconstructed #pi^{+} Travel (cm)",
                    50, 0, 50, 50, 0, 50);
    TH2F *hPionMomeRecoTrue = new TH2F("hPionMomRecoTrue", ";True #pi^{+} Momentum (GeV/c); Reconstructed #pi^{+} Momentum (GeV/c)",
                    100, 0, 2, 100, 0, 2);

    TEfficiency* pAngleEff = new TEfficiency("pAngleEff", ";#theta_{open}; Entries/bin", 10, 1, 0);

    TEfficiency* pPreSelection = new TEfficiency("pPreSelection", ";Neutrino Energy (GeV); Entries/bin", 14, 0, 14);

    for(int i = 0; i < E.GetNEvents(); i++){

        std::cout << "New event..." << i << std::endl;

        if(i % 10000 == 0) std::cout << i << "/" << E.GetNEvents() << std::endl;

        Event e = E.GetEvent(i);

        M.SetSignal(e);                
        M.AddEvent(e);

        double Enu = e.Neutrino.at(0).E;

        //M.FillHistograms(e, Enu);  
        
        bool isSignal = false;
        for(size_t i_tr = 0; i_tr < e.NMCTruths; i_tr++) {
            if(e.IsK0SCharged.at(i_tr)) isSignal = true;
        }

        if(!e.EventIsSignal) continue;

        double pionplusmom, pionminusmom, pionplusmomreco, pionminusmomreco = 1.0;
        TVector3 Momentum1;
        TVector3 Momentum2;
        for(size_t i_tr = 0; i_tr < e.KaonDecay.size(); i_tr++) {
            if(e.KaonDecay.at(i_tr).Origin != 7) continue;
            if(e.KaonDecay.at(i_tr).PDG == -211) {
                pionminusmom = e.KaonDecay.at(i_tr).ModMomentum;
                hPionMinusRecoMomenta->Fill(pionminusmom, PionMomentum(e.KaonDecay.at(i_tr).Travel));
                Momentum1.SetX(e.KaonDecay.at(i_tr).Px); Momentum1.SetY(e.KaonDecay.at(i_tr).Py); Momentum1.SetZ(e.KaonDecay.at(i_tr).Pz);
                //hPionMinusTravel->Fill(e.KoanDecay.at(i_tr).Travel, );
            }
            else if(e.KaonDecay.at(i_tr).PDG == 211) {
                pionplusmom = e.KaonDecay.at(i_tr).ModMomentum;
                hPionPlusRecoMomenta->Fill(pionplusmom, PionMomentum(e.KaonDecay.at(i_tr).Travel));
                Momentum2.SetX(e.KaonDecay.at(i_tr).Px); Momentum2.SetY(e.KaonDecay.at(i_tr).Py); Momentum2.SetZ(e.KaonDecay.at(i_tr).Pz);
            }
        }
        
        if(pionminusmom > 0 && pionplusmom > 0) {
            hPionMomenta->Fill(pionplusmom, pionminusmom);
        }

        double MuonMom = -1;
        MuonMom = e.Lepton.at(0).ModMomentum;

        bool passed_FV=false,passed_Tracks=false,passed_Showers=false,passed_MuonID=false,passed_TrackLengths=false,passed_Selector=false,passed_CT=false,passed_WCut=false,passed_AngleCut=false,passed_All=false;

        std::cout << "Starting new selection..." << std::endl;
        passed_FV = M.FiducialVolumeCut(e);
        if(passed_FV) passed_Tracks = M.TrackCut(e);
        //if(passed_Tracks) passed_Showers = M.ShowerCut(e);

        if(passed_Tracks) M.FillHistograms(e, e.NPrimaryShowerDaughters, e.Weight); 

        pPreSelection->FillWeighted(passed_Tracks, e.Weight, Enu);

        if(passed_Tracks) passed_MuonID = M.ChooseMuonCandidate(e);
        if(passed_MuonID) passed_Selector = M.ChoosePionPairCandidates(e, true);
        //if(passed_FV) passed_Tracks = M.TrackCut(e);
        //if(passed_Tracks) passed_Showers = M.ShowerCut(e);
        //if(passed_Showers) passed_MuonID = M.ChooseMuonCandidate(e);
        //if(passed_MuonID) passed_Selector = M.ChooseProtonPionCandidates(e); 
        //if(passed_Selector) passed_CT = M.ConnectednessTest(e);
        //if(passed_CT) passed_WCut = M.WCut(e);
        //if(passed_WCut) passed_AngleCut = M.AngleCut(e);

        passed_All = passed_Selector;

        std::cout << "Finished selection..." << std::endl;

        if(e.GoodReco && passed_All) {
            hPionMomeRecoTrue->Fill(e.DecayPionPlusCandidate.TrackTrueModMomentum, PionMomentum(e.DecayPionPlusCandidate.TrackLength));
            hPionMinusTravel->Fill(e.DecayPionPlusCandidate.TrackTrueLength, e.DecayPionPlusCandidate.TrackLength);
            //std::cout << e.DecayPionPlusCandidate.TrackLength << std::endl;
            std::cout << e.DecayPionMinusCandidate.TrackLength << std::endl;
            std::cout << e.DecayPionMinusCandidate.TrackTrueOrigin << std::endl;
        }

        if (passed_All) {
            Signal += e.Weight;
            Signal_var += e.Weight*e.Weight;
        }

        double OpeningAngle = (180/3.1415)*Momentum1.Angle(Momentum2);

        pAngleEff->FillWeighted(passed_Selector, e.Weight, OpeningAngle);

        pFiducalEfficX->FillWeighted(passed_FV, e.Weight, e.Neutrino.at(0).EndX);
        pFiducalEfficY->FillWeighted(passed_FV, e.Weight, e.Neutrino.at(0).EndY);
        pFiducalEfficZ->FillWeighted(passed_FV, e.Weight, e.Neutrino.at(0).EndZ);

        pMuonEffic->FillWeighted(passed_MuonID, e.Weight, Enu);
        pMuonMomEffic->FillWeighted(passed_MuonID, e.Weight, MuonMom);
        pSelectorEffic->FillWeighted(passed_Selector, e.Weight, Enu);

        double invariantMass = PionPairInvariantMass(e.DecayPionPlusCandidate, e.DecayPionMinusCandidate);
        
    }

    HypPlot::DrawEfficiencyPlot(pFiducalEfficX, "", "FiducialX", {kFHC}, {POT});
    HypPlot::DrawEfficiencyPlot(pFiducalEfficY, "", "FiducialY", {kFHC}, {POT});
    HypPlot::DrawEfficiencyPlot(pFiducalEfficZ, "", "FiducialZ", {kFHC}, {POT});

    HypPlot::DrawEfficiencyPlot(pPreSelection, "", "PreSelection", {kFHC}, {POT});

    HypPlot::DrawEfficiencyPlot(pMuonEffic, "", "Muon", {kFHC}, {POT});
    HypPlot::DrawEfficiencyPlot(pMuonMomEffic, "", "MuonMom", {kFHC}, {POT});
    HypPlot::DrawEfficiencyPlot(pSelectorEffic, "Selec", "Selec", {kFHC}, {POT});
    HypPlot::DrawEfficiencyPlot(pAngleEff, "Angle", "Angle", {kFHC}, {POT});

    TCanvas *canvas = new TCanvas("", "", 800, 600);
    hPionMomenta->Draw("COLZ");
    hPionMomenta->SetStats(0);
    hPionMomenta->GetXaxis()->SetTitleSize(HypPlot::Single_XaxisTitleSize);
    hPionMomenta->GetYaxis()->SetTitleSize(HypPlot::Single_YaxisTitleSize);
    hPionMomenta->GetXaxis()->SetTitleOffset(HypPlot::Single_XaxisTitleOffset);
    hPionMomenta->GetYaxis()->SetTitleOffset(HypPlot::Single_YaxisTitleOffset);
    hPionMomenta->GetXaxis()->SetLabelSize(HypPlot::Single_XaxisLabelSize);
    hPionMomenta->GetYaxis()->SetLabelSize(HypPlot::Single_YaxisLabelSize);
    canvas->SaveAs("Plots/pionplusminus.png");
    canvas->Close();

    TCanvas *canvas2 = new TCanvas("", "", 800, 600);
    hPionPlusRecoMomenta->Draw("COLZ");
    hPionPlusRecoMomenta->SetStats(0);
    TF1 *line = new TF1("line", "x", 0, 100);
    line->SetLineColor(kRed); 
    line->Draw("SAME"); 
    hPionPlusRecoMomenta->GetXaxis()->SetTitleSize(HypPlot::Single_XaxisTitleSize);
    hPionPlusRecoMomenta->GetYaxis()->SetTitleSize(HypPlot::Single_YaxisTitleSize);
    hPionPlusRecoMomenta->GetXaxis()->SetTitleOffset(HypPlot::Single_XaxisTitleOffset);
    hPionPlusRecoMomenta->GetYaxis()->SetTitleOffset(HypPlot::Single_YaxisTitleOffset);
    hPionPlusRecoMomenta->GetXaxis()->SetLabelSize(HypPlot::Single_XaxisLabelSize);
    hPionPlusRecoMomenta->GetYaxis()->SetLabelSize(HypPlot::Single_YaxisLabelSize);
    canvas2->SaveAs("Plots/pionplusreco.png");
    canvas2->Close();

    TCanvas *canvas3 = new TCanvas("", "", 800, 600);
    hPionMinusRecoMomenta->Draw("COLZ");
    hPionMinusRecoMomenta->SetStats(0);
    line->SetLineColor(kRed); 
    line->Draw("SAME"); 
    hPionMinusRecoMomenta->GetXaxis()->SetTitleSize(HypPlot::Single_XaxisTitleSize);
    hPionMinusRecoMomenta->GetYaxis()->SetTitleSize(HypPlot::Single_YaxisTitleSize);
    hPionMinusRecoMomenta->GetXaxis()->SetTitleOffset(HypPlot::Single_XaxisTitleOffset);
    hPionMinusRecoMomenta->GetYaxis()->SetTitleOffset(HypPlot::Single_YaxisTitleOffset);
    hPionMinusRecoMomenta->GetXaxis()->SetLabelSize(HypPlot::Single_XaxisLabelSize);
    hPionMinusRecoMomenta->GetYaxis()->SetLabelSize(HypPlot::Single_YaxisLabelSize);
    canvas3->SaveAs("Plots/pionminusreco.png");
    canvas3->Close();

    TCanvas *canvas4 = new TCanvas("", "", 800, 600);
    hPionMomeRecoTrue->Draw("COLZ");
    hPionMomeRecoTrue->SetStats(0);
    line->SetLineColor(kRed); 
    line->Draw("SAME"); 
    hPionMomeRecoTrue->GetXaxis()->SetTitleSize(HypPlot::Single_XaxisTitleSize);
    hPionMomeRecoTrue->GetYaxis()->SetTitleSize(HypPlot::Single_YaxisTitleSize);
    hPionMomeRecoTrue->GetXaxis()->SetTitleOffset(HypPlot::Single_XaxisTitleOffset);
    hPionMomeRecoTrue->GetYaxis()->SetTitleOffset(HypPlot::Single_YaxisTitleOffset);
    hPionMomeRecoTrue->GetXaxis()->SetLabelSize(HypPlot::Single_XaxisLabelSize);
    hPionMomeRecoTrue->GetYaxis()->SetLabelSize(HypPlot::Single_YaxisLabelSize);
    canvas4->SaveAs("Plots/pionplusrecotrue.png");
    canvas4->Close();

    TCanvas *canvas5 = new TCanvas("", "", 800, 600);
    hPionMinusTravel->Draw("COLZ");
    hPionMinusTravel->SetStats(0);
    line->SetLineColor(kRed); 
    line->Draw("SAME"); 
    hPionMinusTravel->GetXaxis()->SetTitleSize(HypPlot::Single_XaxisTitleSize);
    hPionMinusTravel->GetYaxis()->SetTitleSize(HypPlot::Single_YaxisTitleSize);
    hPionMinusTravel->GetXaxis()->SetTitleOffset(HypPlot::Single_XaxisTitleOffset);
    hPionMinusTravel->GetYaxis()->SetTitleOffset(HypPlot::Single_YaxisTitleOffset);
    hPionMinusTravel->GetXaxis()->SetLabelSize(HypPlot::Single_XaxisLabelSize);
    hPionMinusTravel->GetYaxis()->SetLabelSize(HypPlot::Single_YaxisLabelSize);
    canvas5->SaveAs("Plots/pionminustraveltruereco.png");
    canvas5->Close();

    M.DrawHistograms(label);

    std::cout << "Signal = " << Signal << "  +/-  " << sqrt(Signal_var) << std::endl;

    E.Close();
}