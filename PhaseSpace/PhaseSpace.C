R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so);
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so);

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

void PhaseSpace(){

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

    M.SetupHistograms(2,0,2,";Hyperon Multiplicity;Events/bin");

    double Signal = 0.0;
    double Signal_var = 0.0;

    E.SetFile("analysisOutputFHC_GENIE_Overlay_Kaon.root", "Background");
    M.AddSample("Background","Background",E.GetPOT());

    TEfficiency* pFiducalEffic = new TEfficiency("pFiducalEffic", ";Neutrino Energy (GeV); Entries/bin", 10, 0, 10);
    TEfficiency* pMuonEffic = new TEfficiency("pMuonEffic", ";Neutrino Energy (GeV); Entries/bin", 10, 0, 10);
    TEfficiency* pMuonMomEffic = new TEfficiency("pMuonMomEffic", ";True Muon Kinetic Energy (GeV); Entries/bin", 26, 0, 13);
    TEfficiency* pSelectorEffic = new TEfficiency("pSelectorEffic", ";Neutrino Energy (GeV); Entries/bin", 10, 0, 10);
    TEfficiency* pAngleEff = new TEfficiency("pAngleEff", ";#theta_{open}; Entries/bin", 10, 1, 0);
    TEfficiency* pInvariantMass = new TEfficiency("pInvariantMass", ";#Reconstrucetd Invariant Mass (GeV); Entries/bin", 10, 1, 0);

    TH2F *hHyperonTracks= new TH2F("hHyperonTracks", ";Hyperon Multiplicity; Reconstructed Tracks",
                    2, 0, 2, 11, 0, 11);
    TH2F *hHyperonShowers= new TH2F("hHyperonShowers", ";Hyperon Multiplicity; Reconstructed Showers",
                    2, 0, 2, 9, 0, 9);

    for(int i = 0; i < E.GetNEvents(); i++){

        if(i % 10000 == 0) std::cout << i << "/" << E.GetNEvents() << std::endl;

        Event e = E.GetEvent(i);

        M.SetSignal(e);                
        M.AddEvent(e);

        double Enu = e.Neutrino.at(0).E;

        if(!e.EventIsSignal) continue;

        double MuonKE = -1;
        MuonKE = e.Lepton.at(0).KE;

        bool passed_FV=false,passed_Tracks=false,passed_Showers=false,passed_MuonID=false,passed_TrackLengths=false,passed_Selector=false,passed_CT=false,passed_WCut=false,passed_AngleCut=false,passed_All=false;

        passed_FV = M.FiducialVolumeCut(e);
        passed_MuonID = M.ChooseMuonCandidate(e);
        passed_Selector = M.ChoosePionPairCandidates(e, true);
        
        //if(passed_FV) passed_Tracks = M.TrackCut(e);
        //if(passed_Tracks) passed_Showers = M.ShowerCut(e);
        //if(passed_Showers) passed_MuonID = M.ChooseMuonCandidate(e);
        //if(passed_MuonID) passed_Selector = M.ChooseProtonPionCandidates(e); 
        //if(passed_Selector) passed_CT = M.ConnectednessTest(e);
        //if(passed_CT) passed_WCut = M.WCut(e);
        //if(passed_WCut) passed_AngleCut = M.AngleCut(e);

        passed_All = passed_Selector;

        if (passed_All) {
            Signal += e.Weight;
            Signal_var += e.Weight*e.Weight;
        }

        double openingAngle = PionPairOpeningAngle(e.DecayPionPlusCandidate, e.DecayPionMinusCandidate);
        double invariantMass = PionPairInvariantMass(e.DecayPionPlusCandidate, e.DecayPionMinusCandidate);

        pFiducalEffic->FillWeighted(passed_FV, e.Weight, Enu);
        pMuonEffic->FillWeighted(passed_MuonID, e.Weight, Enu);
        pMuonMomEffic->FillWeighted(passed_MuonID, e.Weight, MuonKE);
        pSelectorEffic->FillWeighted(passed_Selector, e.Weight, Enu);
        pAngleEff->FillWeighted(passed_Selector, e.Weight, openingAngle);
        pInvariantMass->FillWeighted(passed_Selector, e.Weight, invariantMass);

        int hyperon_multiplicity = 0;
        for(size_t i_tr = 0; i_tr < e.NMCTruths; i_tr++){
            if(e.IsHyperon.at(i_tr)) hyperon_multiplicity++;
        }

        M.FillHistograms(e, hyperon_multiplicity);
        hHyperonTracks->Fill(hyperon_multiplicity, e.NPrimaryTrackDaughters);
        hHyperonShowers->Fill(hyperon_multiplicity, e.NPrimaryShowerDaughters);
    }

    HypPlot::DrawEfficiencyPlot(pFiducalEffic, "Fiducial", "Fiducial", {kFHC}, {POT});
    HypPlot::DrawEfficiencyPlot(pMuonEffic, "Muon", "Muon", {kFHC}, {POT});
    HypPlot::DrawEfficiencyPlot(pMuonMomEffic, "MuonKE", "MuonKE", {kFHC}, {POT});
    HypPlot::DrawEfficiencyPlot(pSelectorEffic, "Selec", "Selec", {kFHC}, {POT});
    HypPlot::DrawEfficiencyPlot(pAngleEff, "Angle", "Angle", {kFHC}, {POT});
    HypPlot::DrawEfficiencyPlot(pInvariantMass, "InvariantMass", "InvariantMass", {kFHC}, {POT});

    TCanvas *canvas = new TCanvas("", "", 800, 600);
    hHyperonTracks->Draw("COLZ");
    hHyperonTracks->SetStats(0);
    hHyperonTracks->GetXaxis()->SetTitleSize(HypPlot::Single_XaxisTitleSize);
    hHyperonTracks->GetYaxis()->SetTitleSize(HypPlot::Single_YaxisTitleSize);
    hHyperonTracks->GetXaxis()->SetTitleOffset(HypPlot::Single_XaxisTitleOffset);
    hHyperonTracks->GetYaxis()->SetTitleOffset(HypPlot::Single_YaxisTitleOffset);
    hHyperonTracks->GetXaxis()->SetLabelSize(HypPlot::Single_XaxisLabelSize);
    hHyperonTracks->GetYaxis()->SetLabelSize(HypPlot::Single_YaxisLabelSize);
    canvas->SaveAs("Plots/hyperontracks.png");
    canvas->Close();

    TCanvas *canvas1 = new TCanvas("", "", 800, 600);
    hHyperonShowers->Draw("COLZ");
    hHyperonShowers->SetStats(0);
    hHyperonShowers->GetXaxis()->SetTitleSize(HypPlot::Single_XaxisTitleSize);
    hHyperonShowers->GetYaxis()->SetTitleSize(HypPlot::Single_YaxisTitleSize);
    hHyperonShowers->GetXaxis()->SetTitleOffset(HypPlot::Single_XaxisTitleOffset);
    hHyperonShowers->GetYaxis()->SetTitleOffset(HypPlot::Single_YaxisTitleOffset);
    hHyperonShowers->GetXaxis()->SetLabelSize(HypPlot::Single_XaxisLabelSize);
    hHyperonShowers->GetYaxis()->SetLabelSize(HypPlot::Single_YaxisLabelSize);
    canvas1->SaveAs("Plots/hyperonshowers.png");
    canvas1->Close();

    std::cout << "Signal = " << Signal << "  +/-  " << sqrt(Signal_var) << std::endl;

    M.DrawHistograms(label);

    E.Close();
}