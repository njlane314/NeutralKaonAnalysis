R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so)
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so)

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

void muon_effic_plots(){

    //double POT = 1.25e21; // POT to scale samples to
    double POT = 1.5e21;

    BuildTunes();
    //SelectionParameters P = P_FHC_Tune_325_NoBDT;
    SelectionParameters P = P_RHC_Tune_397_NoBDT;

    std::string label = "muon_effic";
    std::string SampleType = "signal";

    EventAssembler E(false);
    SelectionManager M(P);
    M.ImportSelectorBDTWeights("/uboone/app/users/nlane/NeutralKaonAnalysis/TMVA/SelectorMVA/dataset/weights");

    //M.SetBeamMode(kFHC);
    M.SetBeamMode(kRHC);
    
    M.SetPOT(POT);
    M.UseFluxWeight(false);
    M.UseGenWeight(false);

    //E.SetFile("analysisOutputFHC_Overlay_GENIE_Kaon_cthorpe_make_k0s_events_numi_fhc_reco2_reco2_reco2.root",  "signal");
    E.SetFile("analysisOutputRHC_GENIE_Overlay_Kaon_cthorpe_make_k0s_events_numi_rhc_reco2_REAL_reco2_reco2.root", "signal");
    M.AddSample("Signal", "Signal", E.GetPOT());

    TEfficiency* Efficiency_MuonMom_All = new TEfficiency("MuonMom_eff_All",";Muon Momentum (GeV/c);Selected/All",15,0,6.0);
    TEfficiency* Efficiency_MuonDetectorTheta_All = new TEfficiency("MuonDetectorTheta_eff",";Muon Detector #theta;Selected/All",30,0,3.1415);
    TEfficiency* Efficiency_MuonDetectorPhi_All = new TEfficiency("MuonDetectorPhi_eff_All",";Muon Detector #theta;Selected/All",30,-3.1415,3.1415);

    for(int i=0;i<E.GetNEvents();i++){
    
        if(i % 10000 == 0) std::cout << "Processing event " << i << "/" << E.GetNEvents() << std::endl;
    
        //get an event
        Event e = E.GetEvent(i);

        //update metadata
        M.SetSignal(e);
        M.AddEvent(e);

        if(!e.EventIsSignal) continue;

        // Calculate Q2
        double Q2 = -1;

        TLorentzVector Nu4Momentum(e.Neutrino.at(0).Px,e.Neutrino.at(0).Py,e.Neutrino.at(0).Pz,e.Neutrino.at(0).E);
        TLorentzVector Muon4Momentum(e.Lepton.at(0).Px,e.Lepton.at(0).Py,e.Lepton.at(0).Pz,e.Lepton.at(0).E);
        Q2 = (-1)*(Nu4Momentum - Muon4Momentum)*(Nu4Momentum - Muon4Momentum);

        // Calculate NuE
        double NuE = -1;
        if(e.Neutrino.empty()) continue;
        NuE = e.Neutrino.at(0).E;

        // Calculate Muon KE
        double MuonKE = -1;
        MuonKE = e.Lepton.at(0).ModMomentum;

        // Get the Neutrino's true direction
        TVector3 NuDirection(e.Neutrino.at(0).Px,e.Neutrino.at(0).Py,e.Neutrino.at(0).Pz);
        NuDirection *= 1.0/NuDirection.Mag();

        // Get the muon's true direction
        TVector3 MuonTrueDir(e.Lepton.at(0).Px,e.Lepton.at(0).Py,e.Lepton.at(0).Pz);

        double MuonTrueTheta = MuonTrueDir.Angle(NuDirection);
        double MuonDetectorTheta = MuonTrueDir.Theta();
        double MuonDetectorPhi = MuonTrueDir.Phi();

        TVector3 MuonTrueDirBeam = RotateToBeam(MuonTrueDir);

        double MuonBeamTheta = MuonTrueDirBeam.Theta();
        double MuonBeamPhi = MuonTrueDirBeam.Phi();

        bool passed_FV=false,passed_Tracks=false,passed_Showers=false,passed_MuonID=false,passed_TrackLengths=false,passed_Selector=false,passed_CT=false,passed_WCut=false,passed_AngleCut=false,passed_All=false;
    
        passed_FV = M.FiducialVolumeCut(e);
        if(passed_FV) passed_Tracks = M.TrackCut(e);
        if(passed_Tracks) passed_MuonID = M.ChooseMuonCandidate(e);
        //if(passed_MuonID) passed_Selector = M.ChoosePionPairCandidates(e); 
        //if(passed_Selector) passed_WCut = M.WCut(e);
        //if(passed_WCut) passed_AngleCut = M.AngleCut(e);

        passed_All = passed_MuonID;

        Efficiency_MuonMom_All->FillWeighted(passed_All,e.Weight,MuonKE);
        Efficiency_MuonDetectorTheta_All->FillWeighted(passed_All,e.Weight,MuonDetectorTheta);
        Efficiency_MuonDetectorPhi_All->FillWeighted(passed_All,e.Weight,MuonDetectorPhi);

    }

    std::cout << "Drawing histograms..." << std::endl;

    HypPlot::DrawEfficiencyPlot(Efficiency_MuonMom_All,";Muon Momentum (GeV/c);Events/bin",label + "_MuonMom_All",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_MuonDetectorTheta_All,";Muon #theta;Events/bin",label + "_MuonDetectorTheta_All",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_MuonDetectorPhi_All,";Muon #phi;Events/bin",label + "_MuonDetectorPhi_All",{kRHC},{POT});

    E.Close();

}