R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so)
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so)

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

void selection_phase_space(){

    //double POT = 1.25e21; // POT to scale samples to
    double POT = 1.5e21;

    BuildTunes();
    //SelectionParameters P = P_FHC_Tune_325_NoBDT;
    SelectionParameters P = P_RHC_Tune_397_NoBDT;

    std::string label = "effic_phase";
    std::string SampleType = "pure_kaon";

    EventAssembler E(false);
    SelectionManager M(P);

    //M.SetBeamMode(kFHC);
    M.SetBeamMode(kRHC);
    
    M.SetPOT(POT);
    M.UseFluxWeight(false);
    M.UseGenWeight(false);

    //E.SetFile("analysisOutputFHC_Overlay_GENIE_Kaon_cthorpe_make_k0s_events_numi_fhc_reco2_reco2_reco2.root",  "signal");
    E.SetFile("analysisOutputRHC_GENIE_Overlay_Kaon_cthorpe_make_k0s_events_numi_rhc_reco2_REAL_reco2_reco2.root", "signal");
    M.AddSample("Signal", "Signal", E.GetPOT());

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // All Cuts //

    TEfficiency* Efficiency_Q2_All = new TEfficiency("Q2_eff_All",";True Q^{2} (GeV^{2});Selected/All",60,0,3.0);
    TEfficiency* Efficiency_NuE_All = new TEfficiency("NuE_eff_All",";True E_{#nu} (GeV);Selected/All",60,0,4.0);
    TEfficiency* Efficiency_MuonKE_All = new TEfficiency("MuonKE_eff_All",";True Muon KE (GeV);Selected/All",60,0,3.0);
    TEfficiency* Efficiency_MuonTrueTheta_All = new TEfficiency("MuonTrueTheta_eff_All",";Muon True #theta;Selected/All",60,0,3.1415);
    TEfficiency* Efficiency_MuonDetectorTheta_All = new TEfficiency("MuonDetectorTheta_eff",";Muon Detector #theta;Selected/All",60,0,3.1415);
    TEfficiency* Efficiency_MuonDetectorPhi_All = new TEfficiency("MuonDetectorPhi_eff_All",";Muon Detector #theta;Selected/All",60,-3.1415,3.1415);
    TEfficiency* Efficiency_MuonBeamTheta_All = new TEfficiency("MuonBeamTheta_eff_All",";Muon Beam #theta;Selected/All",60,0,3.1415);
    TEfficiency* Efficiency_MuonBeamPhi_All = new TEfficiency("MuonBeamPhi_eff_All",";Muon Beam #theta;Selected/All",60,-3.1415,3.1415);
    TEfficiency* Efficiency_LambdaMomentum_All = new TEfficiency("LambdaMomentum_eff_All",";True #Lambda Momentum (GeV/c);Selected/All",60,0.0,2.0);
    TEfficiency* Efficiency_DecayProtonMomentum_All = new TEfficiency("DecayProtonMomentum_eff_All",";True Decay Proton Momentum (GeV/c);Selected/All",60,0.3,1.5);
    TEfficiency* Efficiency_DecayPionMomentum_All = new TEfficiency("DecayPionMomentum_eff_All",";True Decay #pi^{-} Momentum (GeV/c);Selected/All",60,0.1,0.8);
    TEfficiency* Efficiency_OpeningAngle_All = new TEfficiency("OpeningAngle_eff_All",";True Opening Angle (deg);Selected/All",60,0,100);
    TEfficiency* Efficiency_LambdaRange_All = new TEfficiency("LambdaRange_eff_All",";True #Lambda Range (cm);Selected/All",100,0,20.0);
    TEfficiency* Efficiency_All = new TEfficiency("eff_All",";;Selected/All",1,0,1.0);

    // Fiducial Volume Cut //

    TEfficiency* Efficiency_Q2_FV = new TEfficiency("Q2_eff_FV",";True Q^{2} (GeV^{2});Selected/All",60,0,3.0);
    TEfficiency* Efficiency_NuE_FV = new TEfficiency("NuE_eff_FV",";True E_{#nu} (GeV);Selected/All",60,0,4.0);
    TEfficiency* Efficiency_MuonKE_FV = new TEfficiency("MuonKE_eff_FV",";True Muon KE (GeV);Selected/All",60,0,3.0);
    TEfficiency* Efficiency_MuonTrueTheta_FV = new TEfficiency("MuonTrueTheta_eff_FV",";Muon True #theta;Selected/All",60,0,3.1415);
    TEfficiency* Efficiency_MuonDetectorTheta_FV = new TEfficiency("MuonDetectorTheta_eff",";Muon Detector #theta;Selected/All",60,0,3.1415);
    TEfficiency* Efficiency_MuonDetectorPhi_FV = new TEfficiency("MuonDetectorPhi_eff_FV",";Muon Detector #theta;Selected/All",60,-3.1415,3.1415);
    TEfficiency* Efficiency_MuonBeamTheta_FV = new TEfficiency("MuonBeamTheta_eff_FV",";Muon Beam #theta;Selected/All",60,0,3.1415);
    TEfficiency* Efficiency_MuonBeamPhi_FV = new TEfficiency("MuonBeamPhi_eff_FV",";Muon Beam #theta;Selected/All",60,-3.1415,3.1415);
    TEfficiency* Efficiency_LambdaMomentum_FV = new TEfficiency("LambdaMomentum_eff_FV",";True #Lambda Momentum (GeV/c);Selected/All",60,0.0,2.0);
    TEfficiency* Efficiency_DecayProtonMomentum_FV = new TEfficiency("DecayProtonMomentum_eff_FV",";True Decay Proton Momentum (GeV/c);Selected/All",60,0.3,1.5);
    TEfficiency* Efficiency_DecayPionMomentum_FV = new TEfficiency("DecayPionMomentum_eff_FV",";True Decay #pi^{-} Momentum (GeV/c);Selected/All",60,0.1,0.8);
    TEfficiency* Efficiency_OpeningAngle_FV = new TEfficiency("OpeningAngle_eff_FV",";True Opening Angle (deg);Selected/All",60,0,100);
    TEfficiency* Efficiency_LambdaRange_FV = new TEfficiency("LambdaRange_eff_FV",";True #Lambda Range (cm);Selected/All",100,0,20.0);
    TEfficiency* Efficiency_FV = new TEfficiency("eff_FV",";;Selected/All",1,0,1.0);

    // Track Cut //

    TEfficiency* Efficiency_Q2_Tracks = new TEfficiency("Q2_eff_Tracks",";True Q^{2} (GeV^{2});Selected/All",60,0,3.0);
    TEfficiency* Efficiency_NuE_Tracks = new TEfficiency("NuE_eff_Tracks",";True E_{#nu} (GeV);Selected/All",60,0,4.0);
    TEfficiency* Efficiency_MuonKE_Tracks = new TEfficiency("MuonKE_eff_Tracks",";True Muon KE (GeV);Selected/All",60,0,3.0);
    TEfficiency* Efficiency_MuonTrueTheta_Tracks = new TEfficiency("MuonTrueTheta_eff_Tracks",";Muon True #theta;Selected/All",60,0,3.1415);
    TEfficiency* Efficiency_MuonDetectorTheta_Tracks = new TEfficiency("MuonDetectorTheta_eff",";Muon Detector #theta;Selected/All",60,0,3.1415);
    TEfficiency* Efficiency_MuonDetectorPhi_Tracks = new TEfficiency("MuonDetectorPhi_eff_Tracks",";Muon Detector #theta;Selected/All",60,-3.1415,3.1415);
    TEfficiency* Efficiency_MuonBeamTheta_Tracks = new TEfficiency("MuonBeamTheta_eff_Tracks",";Muon Beam #theta;Selected/All",60,0,3.1415);
    TEfficiency* Efficiency_MuonBeamPhi_Tracks = new TEfficiency("MuonBeamPhi_eff_Tracks",";Muon Beam #theta;Selected/All",60,-3.1415,3.1415);
    TEfficiency* Efficiency_LambdaMomentum_Tracks = new TEfficiency("LambdaMomentum_eff_Tracks",";True #Lambda Momentum (GeV/c);Selected/All",60,0.0,2.0);
    TEfficiency* Efficiency_DecayProtonMomentum_Tracks = new TEfficiency("DecayProtonMomentum_eff_Tracks",";True Decay Proton Momentum (GeV/c);Selected/All",60,0.3,1.5);
    TEfficiency* Efficiency_DecayPionMomentum_Tracks = new TEfficiency("DecayPionMomentum_eff_Tracks",";True Decay #pi^{-} Momentum (GeV/c);Selected/All",60,0.1,0.8);
    TEfficiency* Efficiency_OpeningAngle_Tracks = new TEfficiency("OpeningAngle_eff_Tracks",";True Opening Angle (deg);Selected/All",60,0,100);
    TEfficiency* Efficiency_LambdaRange_Tracks = new TEfficiency("LambdaRange_eff_Tracks",";True #Lambda Range (cm);Selected/All",100,0,20.0);
    TEfficiency* Efficiency_Tracks = new TEfficiency("eff_Tracks",";;Selected/All",1,0,1.0);

    // Shower Cut //

    TEfficiency* Efficiency_Q2_Showers = new TEfficiency("Q2_eff_Showers",";True Q^{2} (GeV^{2});Selected/All",60,0,3.0);
    TEfficiency* Efficiency_NuE_Showers = new TEfficiency("NuE_eff_Showers",";True E_{#nu} (GeV);Selected/All",60,0,4.0);
    TEfficiency* Efficiency_MuonKE_Showers = new TEfficiency("MuonKE_eff_Showers",";True Muon KE (GeV);Selected/All",60,0,3.0);
    TEfficiency* Efficiency_MuonTrueTheta_Showers = new TEfficiency("MuonTrueTheta_eff_Showers",";Muon True #theta;Selected/All",60,0,3.1415);
    TEfficiency* Efficiency_MuonDetectorTheta_Showers = new TEfficiency("MuonDetectorTheta_eff",";Muon Detector #theta;Selected/All",60,0,3.1415);
    TEfficiency* Efficiency_MuonDetectorPhi_Showers = new TEfficiency("MuonDetectorPhi_eff_Showers",";Muon Detector #theta;Selected/All",60,-3.1415,3.1415);
    TEfficiency* Efficiency_MuonBeamTheta_Showers = new TEfficiency("MuonBeamTheta_eff_Showers",";Muon Beam #theta;Selected/All",60,0,3.1415);
    TEfficiency* Efficiency_MuonBeamPhi_Showers = new TEfficiency("MuonBeamPhi_eff_Showers",";Muon Beam #theta;Selected/All",60,-3.1415,3.1415);
    TEfficiency* Efficiency_LambdaMomentum_Showers = new TEfficiency("LambdaMomentum_eff_Showers",";True #Lambda Momentum (GeV/c);Selected/All",60,0.0,2.0);
    TEfficiency* Efficiency_DecayProtonMomentum_Showers = new TEfficiency("DecayProtonMomentum_eff_Showers",";True Decay Proton Momentum (GeV/c);Selected/All",60,0.3,1.5);
    TEfficiency* Efficiency_DecayPionMomentum_Showers = new TEfficiency("DecayPionMomentum_eff_Showers",";True Decay #pi^{-} Momentum (GeV/c);Selected/All",60,0.1,0.8);
    TEfficiency* Efficiency_OpeningAngle_Showers = new TEfficiency("OpeningAngle_eff_Showers",";True Opening Angle (deg);Selected/All",60,0,100);
    TEfficiency* Efficiency_LambdaRange_Showers = new TEfficiency("LambdaRange_eff_Showers",";True #Lambda Range (cm);Selected/All",100,0,20.0);
    TEfficiency* Efficiency_Showers = new TEfficiency("eff_Showers",";;Selected/All",1,0,1.0);

    // MuonID //

    TEfficiency* Efficiency_Q2_MuonID = new TEfficiency("Q2_eff_MuonID",";True Q^{2} (GeV^{2});Selected/All",60,0,3.0);
    TEfficiency* Efficiency_NuE_MuonID = new TEfficiency("NuE_eff_MuonID",";True E_{#nu} (GeV);Selected/All",60,0,4.0);
    TEfficiency* Efficiency_MuonKE_MuonID = new TEfficiency("MuonKE_eff_MuonID",";True Muon KE (GeV);Selected/All",60,0,3.0);
    TEfficiency* Efficiency_MuonTrueTheta_MuonID = new TEfficiency("MuonTrueTheta_eff_MuonID",";Muon True #theta;Selected/All",60,0,3.1415);
    TEfficiency* Efficiency_MuonDetectorTheta_MuonID = new TEfficiency("MuonDetectorTheta_eff",";Muon Detector #theta;Selected/All",60,0,3.1415);
    TEfficiency* Efficiency_MuonDetectorPhi_MuonID = new TEfficiency("MuonDetectorPhi_eff_MuonID",";Muon Detector #theta;Selected/All",60,-3.1415,3.1415);
    TEfficiency* Efficiency_MuonBeamTheta_MuonID = new TEfficiency("MuonBeamTheta_eff_MuonID",";Muon Beam #theta;Selected/All",60,0,3.1415);
    TEfficiency* Efficiency_MuonBeamPhi_MuonID = new TEfficiency("MuonBeamPhi_eff_MuonID",";Muon Beam #theta;Selected/All",60,-3.1415,3.1415);
    TEfficiency* Efficiency_LambdaMomentum_MuonID = new TEfficiency("LambdaMomentum_eff_MuonID",";True #Lambda Momentum (GeV/c);Selected/All",60,0.0,2.0);
    TEfficiency* Efficiency_DecayProtonMomentum_MuonID = new TEfficiency("DecayProtonMomentum_eff_MuonID",";True Decay Proton Momentum (GeV/c);Selected/All",60,0.3,1.5);
    TEfficiency* Efficiency_DecayPionMomentum_MuonID = new TEfficiency("DecayPionMomentum_eff_MuonID",";True Decay #pi^{-} Momentum (GeV/c);Selected/All",60,0.1,0.8);
    TEfficiency* Efficiency_OpeningAngle_MuonID = new TEfficiency("OpeningAngle_eff_MuonID",";True Opening Angle (deg);Selected/All",60,0,100);
    TEfficiency* Efficiency_LambdaRange_MuonID = new TEfficiency("LambdaRange_eff_MuonID",";True #Lambda Range (cm);Selected/All",100,0,20.0);
    TEfficiency* Efficiency_MuonID = new TEfficiency("eff_MuonID",";;Selected/All",1,0,1.0);

    // Selector BDT //

    TEfficiency* Efficiency_Q2_Selector = new TEfficiency("Q2_eff_Selector",";True Q^{2} (GeV^{2});Selected/All",60,0,3.0);
    TEfficiency* Efficiency_NuE_Selector = new TEfficiency("NuE_eff_Selector",";True E_{#nu} (GeV);Selected/All",60,0,4.0);
    TEfficiency* Efficiency_MuonKE_Selector = new TEfficiency("MuonKE_eff_Selector",";True Muon KE (GeV);Selected/All",60,0,3.0);
    TEfficiency* Efficiency_MuonTrueTheta_Selector = new TEfficiency("MuonTrueTheta_eff_Selector",";Muon True #theta;Selected/All",60,0,3.1415);
    TEfficiency* Efficiency_MuonDetectorTheta_Selector = new TEfficiency("MuonDetectorTheta_eff",";Muon Detector #theta;Selected/All",60,0,3.1415);
    TEfficiency* Efficiency_MuonDetectorPhi_Selector = new TEfficiency("MuonDetectorPhi_eff_Selector",";Muon Detector #theta;Selected/All",60,-3.1415,3.1415);
    TEfficiency* Efficiency_MuonBeamTheta_Selector = new TEfficiency("MuonBeamTheta_eff_Selector",";Muon Beam #theta;Selected/All",60,0,3.1415);
    TEfficiency* Efficiency_MuonBeamPhi_Selector = new TEfficiency("MuonBeamPhi_eff_Selector",";Muon Beam #theta;Selected/All",60,-3.1415,3.1415);
    TEfficiency* Efficiency_LambdaMomentum_Selector = new TEfficiency("LambdaMomentum_eff_Selector",";True #Lambda Momentum (GeV/c);Selected/All",60,0.0,2.0);
    TEfficiency* Efficiency_DecayProtonMomentum_Selector = new TEfficiency("DecayProtonMomentum_eff_Selector",";True Decay Proton Momentum (GeV/c);Selected/All",60,0.3,1.5);
    TEfficiency* Efficiency_DecayPionMomentum_Selector = new TEfficiency("DecayPionMomentum_eff_Selector",";True Decay #pi^{-} Momentum (GeV/c);Selected/All",60,0.1,0.8);
    TEfficiency* Efficiency_OpeningAngle_Selector = new TEfficiency("OpeningAngle_eff_Selector",";True Opening Angle (deg);Selected/All",60,0,100);
    TEfficiency* Efficiency_LambdaRange_Selector = new TEfficiency("LambdaRange_eff_Selector",";True #Lambda Range (cm);Selected/All",100,0,20.0);
    TEfficiency* Efficiency_Selector = new TEfficiency("eff_Selector",";;Selected/All",1,0,1.0);

    // Connectedness //

    TEfficiency* Efficiency_Q2_CT = new TEfficiency("Q2_eff_CT",";True Q^{2} (GeV^{2});Selected/All",60,0,3.0);
    TEfficiency* Efficiency_NuE_CT = new TEfficiency("NuE_eff_CT",";True E_{#nu} (GeV);Selected/All",60,0,4.0);
    TEfficiency* Efficiency_MuonKE_CT = new TEfficiency("MuonKE_eff_CT",";True Muon KE (GeV);Selected/All",60,0,3.0);
    TEfficiency* Efficiency_MuonTrueTheta_CT = new TEfficiency("MuonTrueTheta_eff_CT",";Muon True #theta;Selected/All",60,0,3.1415);
    TEfficiency* Efficiency_MuonDetectorTheta_CT = new TEfficiency("MuonDetectorTheta_eff",";Muon Detector #theta;Selected/All",60,0,3.1415);
    TEfficiency* Efficiency_MuonDetectorPhi_CT = new TEfficiency("MuonDetectorPhi_eff_CT",";Muon Detector #theta;Selected/All",60,-3.1415,3.1415);
    TEfficiency* Efficiency_MuonBeamTheta_CT = new TEfficiency("MuonBeamTheta_eff_CT",";Muon Beam #theta;Selected/All",60,0,3.1415);
    TEfficiency* Efficiency_MuonBeamPhi_CT = new TEfficiency("MuonBeamPhi_eff_CT",";Muon Beam #theta;Selected/All",60,-3.1415,3.1415);
    TEfficiency* Efficiency_LambdaMomentum_CT = new TEfficiency("LambdaMomentum_eff_CT",";True #Lambda Momentum (GeV/c);Selected/All",60,0.0,2.0);
    TEfficiency* Efficiency_DecayProtonMomentum_CT = new TEfficiency("DecayProtonMomentum_eff_CT",";True Decay Proton Momentum (GeV/c);Selected/All",60,0.3,1.5);
    TEfficiency* Efficiency_DecayPionMomentum_CT = new TEfficiency("DecayPionMomentum_eff_CT",";True Decay #pi^{-} Momentum (GeV/c);Selected/All",60,0.1,0.8);
    TEfficiency* Efficiency_OpeningAngle_CT = new TEfficiency("OpeningAngle_eff_CT",";True Opening Angle (deg);Selected/All",60,0,100);
    TEfficiency* Efficiency_LambdaRange_CT = new TEfficiency("LambdaRange_eff_CT",";True #Lambda Range (cm);Selected/All",100,0,20.0);
    TEfficiency* Efficiency_CT = new TEfficiency("eff_CT",";;Selected/All",1,0,1.0);

    // Invariant mass cut //

    TEfficiency* Efficiency_Q2_WCut = new TEfficiency("Q2_eff_WCut",";True Q^{2} (GeV^{2});Selected/All",60,0,3.0);
    TEfficiency* Efficiency_NuE_WCut = new TEfficiency("NuE_eff_WCut",";True E_{#nu} (GeV);Selected/All",60,0,4.0);
    TEfficiency* Efficiency_MuonKE_WCut = new TEfficiency("MuonKE_eff_WCut",";True Muon KE (GeV);Selected/All",60,0,3.0);
    TEfficiency* Efficiency_MuonTrueTheta_WCut = new TEfficiency("MuonTrueTheta_eff_WCut",";Muon True #theta;Selected/All",60,0,3.1415);
    TEfficiency* Efficiency_MuonDetectorTheta_WCut = new TEfficiency("MuonDetectorTheta_eff",";Muon Detector #theta;Selected/All",60,0,3.1415);
    TEfficiency* Efficiency_MuonDetectorPhi_WCut = new TEfficiency("MuonDetectorPhi_eff_WCut",";Muon Detector #theta;Selected/All",60,-3.1415,3.1415);
    TEfficiency* Efficiency_MuonBeamTheta_WCut = new TEfficiency("MuonBeamTheta_eff_WCut",";Muon Beam #theta;Selected/All",60,0,3.1415);
    TEfficiency* Efficiency_MuonBeamPhi_WCut = new TEfficiency("MuonBeamPhi_eff_WCut",";Muon Beam #theta;Selected/All",60,-3.1415,3.1415);
    TEfficiency* Efficiency_LambdaMomentum_WCut = new TEfficiency("LambdaMomentum_eff_WCut",";True #Lambda Momentum (GeV/c);Selected/All",60,0.0,2.0);
    TEfficiency* Efficiency_DecayProtonMomentum_WCut = new TEfficiency("DecayProtonMomentum_eff_WCut",";True Decay Proton Momentum (GeV/c);Selected/All",60,0.3,1.5);
    TEfficiency* Efficiency_DecayPionMomentum_WCut = new TEfficiency("DecayPionMomentum_eff_WCut",";True Decay #pi^{-} Momentum (GeV/c);Selected/All",60,0.1,0.8);
    TEfficiency* Efficiency_OpeningAngle_WCut = new TEfficiency("OpeningAngle_eff_WCut",";True Opening Angle (deg);Selected/All",60,0,100);
    TEfficiency* Efficiency_LambdaRange_WCut = new TEfficiency("LambdaRange_eff_WCut",";True #Lambda Range (cm);Selected/All",100,0,20.0);
    TEfficiency* Efficiency_WCut = new TEfficiency("eff_WCut",";;Selected/All",1,0,1.0);

    // Angular deviation cut //

    TEfficiency* Efficiency_Q2_AngleCut = new TEfficiency("Q2_eff_AngleCut",";True Q^{2} (GeV^{2});Selected/All",60,0,3.0);
    TEfficiency* Efficiency_NuE_AngleCut = new TEfficiency("NuE_eff_AngleCut",";True E_{#nu} (GeV);Selected/All",60,0,4.0);
    TEfficiency* Efficiency_MuonKE_AngleCut = new TEfficiency("MuonKE_eff_AngleCut",";True Muon KE (GeV);Selected/All",60,0,3.0);
    TEfficiency* Efficiency_MuonTrueTheta_AngleCut = new TEfficiency("MuonTrueTheta_eff_AngleCut",";Muon True #theta;Selected/All",60,0,3.1415);
    TEfficiency* Efficiency_MuonDetectorTheta_AngleCut = new TEfficiency("MuonDetectorTheta_eff",";Muon Detector #theta;Selected/All",60,0,3.1415);
    TEfficiency* Efficiency_MuonDetectorPhi_AngleCut = new TEfficiency("MuonDetectorPhi_eff_AngleCut",";Muon Detector #theta;Selected/All",60,-3.1415,3.1415);
    TEfficiency* Efficiency_MuonBeamTheta_AngleCut = new TEfficiency("MuonBeamTheta_eff_AngleCut",";Muon Beam #theta;Selected/All",60,0,3.1415);
    TEfficiency* Efficiency_MuonBeamPhi_AngleCut = new TEfficiency("MuonBeamPhi_eff_AngleCut",";Muon Beam #theta;Selected/All",60,-3.1415,3.1415);
    TEfficiency* Efficiency_LambdaMomentum_AngleCut = new TEfficiency("LambdaMomentum_eff_AngleCut",";True #Lambda Momentum (GeV/c);Selected/All",60,0.0,2.0);
    TEfficiency* Efficiency_DecayProtonMomentum_AngleCut = new TEfficiency("DecayProtonMomentum_eff_AngleCut",";True Decay Proton Momentum (GeV/c);Selected/All",60,0.3,1.5);
    TEfficiency* Efficiency_DecayPionMomentum_AngleCut = new TEfficiency("DecayPionMomentum_eff_AngleCut",";True Decay #pi^{-} Momentum (GeV/c);Selected/All",60,0.1,0.8);
    TEfficiency* Efficiency_OpeningAngle_AngleCut = new TEfficiency("OpeningAngle_eff_AngleCut",";True Opening Angle (deg);Selected/All",60,0,100);
    TEfficiency* Efficiency_LambdaRange_AngleCut = new TEfficiency("LambdaRange_eff_AngleCut",";True #Lambda Range (cm);Selected/All",100,0,20.0);
    TEfficiency* Efficiency_AngleCut = new TEfficiency("eff_AngleCut",";;Selected/All",1,0,1.0);

    std::cout << "Here?" << std::endl;

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    for(int i=0;i<E.GetNEvents();i++){

        std::cout << E.GetNEvents() << std::endl;
    
        if(i % 10000 == 0) std::cout << "Processing event " << i << "/" << E.GetNEvents() << std::endl;
    
        //get an event
        Event e = E.GetEvent(i);

        //update metadata
        M.AddEvent(e);
        M.SetSignal(e);

        if(!e.EventIsSignal) continue;

        // Calculate Q2
        double Q2 = -1;

        TLorentzVector Nu4Momentum(e.Neutrino.at(0).Px,e.Neutrino.at(0).Py,e.Neutrino.at(0).Pz,e.Neutrino.at(0).E);
        TLorentzVector Muon4Momentum(e.Lepton.at(0).Px,e.Lepton.at(0).Py,e.Lepton.at(0).Pz,e.Lepton.at(0).E);

        Q2 = (-1)*(Nu4Momentum - Muon4Momentum)*(Nu4Momentum - Muon4Momentum);

        // Calculate NuE
        double NuE = -1;
        NuE = e.Neutrino.at(0).E;

        // Calculate Muon KE
        double MuonKE = -1;
        MuonKE = e.Lepton.at(0).KE;

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
        double LambdaMomentum = e.Hyperon.at(0).ModMomentum;
        double DecayProtonMomentum,DecayPionMomentum=-1.0;
        double OpeningAngle=-1.0;
        double LambdaRange = e.Hyperon.at(0).Travel;

        if(e.Decay.size() == 2){

            if(e.Decay.at(0).PDG == 2212) DecayProtonMomentum = e.Decay.at(0).ModMomentum;                
            if(e.Decay.at(0).PDG == -211) DecayPionMomentum = e.Decay.at(0).ModMomentum;               

            if(e.Decay.at(1).PDG == 2212) DecayProtonMomentum = e.Decay.at(1).ModMomentum;                
            if(e.Decay.at(1).PDG == -211) DecayPionMomentum = e.Decay.at(1).ModMomentum;                

            TVector3 Momentum1(e.Decay.at(0).Px,e.Decay.at(0).Py,e.Decay.at(0).Pz);
            TVector3 Momentum2(e.Decay.at(1).Px,e.Decay.at(1).Py,e.Decay.at(1).Pz);

            OpeningAngle = (180/3.1415)*Momentum1.Angle(Momentum2);
        }

        bool passed_FV=false,passed_Tracks=false,passed_Showers=false,passed_MuonID=false,passed_TrackLengths=false,passed_Selector=false,passed_CT=false,passed_WCut=false,passed_AngleCut=false,passed_All=false;
    
        passed_FV = M.FiducialVolumeCut(e);
        if(passed_FV) passed_Tracks = M.TrackCut(e);
        if(passed_Tracks) passed_Showers = M.ShowerCut(e);
        if(passed_Showers) passed_MuonID = M.ChooseMuonCandidate(e);
        if(passed_MuonID) passed_Selector = M.ChoosePionPairCandidates(e); 
        if(passed_Selector) passed_CT = M.ConnectednessTest(e);
        if(passed_CT) passed_WCut = M.WCut(e);
        if(passed_WCut) passed_AngleCut = M.AngleCut(e);

        passed_All = passed_AngleCut;

        // Entire Selection         
        
        Efficiency_Q2_All->FillWeighted(passed_All,e.Weight,Q2);
        Efficiency_NuE_All->FillWeighted(passed_All,e.Weight,NuE);
        Efficiency_MuonKE_All->FillWeighted(passed_All,e.Weight,MuonKE);
        Efficiency_MuonTrueTheta_All->FillWeighted(passed_All,e.Weight,MuonTrueTheta);
        Efficiency_MuonDetectorTheta_All->FillWeighted(passed_All,e.Weight,MuonDetectorTheta);
        Efficiency_MuonDetectorPhi_All->FillWeighted(passed_All,e.Weight,MuonDetectorPhi);
        Efficiency_MuonBeamTheta_All->FillWeighted(passed_All,e.Weight,MuonBeamTheta);
        Efficiency_MuonBeamPhi_All->FillWeighted(passed_All,e.Weight,MuonBeamPhi);
        Efficiency_LambdaMomentum_All->FillWeighted(passed_All,e.Weight,LambdaMomentum);
        Efficiency_DecayProtonMomentum_All->FillWeighted(passed_All,e.Weight,DecayProtonMomentum);
        Efficiency_DecayPionMomentum_All->FillWeighted(passed_All,e.Weight,DecayPionMomentum);
        Efficiency_OpeningAngle_All->FillWeighted(passed_All,e.Weight,OpeningAngle);
        Efficiency_LambdaRange_All->FillWeighted(passed_All,e.Weight,LambdaRange);
        Efficiency_All->FillWeighted(passed_All,e.Weight,0.5);

        // Fiducial Volume Cut

        Efficiency_Q2_FV->FillWeighted(passed_FV,e.Weight,Q2);
        Efficiency_NuE_FV->FillWeighted(passed_FV,e.Weight,NuE);
        Efficiency_MuonKE_FV->FillWeighted(passed_FV,e.Weight,MuonKE);
        Efficiency_MuonTrueTheta_FV->FillWeighted(passed_FV,e.Weight,MuonTrueTheta);
        Efficiency_MuonDetectorTheta_FV->FillWeighted(passed_FV,e.Weight,MuonDetectorTheta);
        Efficiency_MuonDetectorPhi_FV->FillWeighted(passed_FV,e.Weight,MuonDetectorPhi);
        Efficiency_MuonBeamTheta_FV->FillWeighted(passed_FV,e.Weight,MuonBeamTheta); 
        Efficiency_MuonBeamPhi_FV->FillWeighted(passed_FV,e.Weight,MuonBeamPhi);
        Efficiency_LambdaMomentum_FV->FillWeighted(passed_FV,e.Weight,LambdaMomentum);
        Efficiency_DecayProtonMomentum_FV->FillWeighted(passed_FV,e.Weight,DecayProtonMomentum);
        Efficiency_DecayPionMomentum_FV->FillWeighted(passed_FV,e.Weight,DecayPionMomentum);
        Efficiency_OpeningAngle_FV->FillWeighted(passed_FV,e.Weight,OpeningAngle);
        Efficiency_LambdaRange_FV->FillWeighted(passed_FV,e.Weight,LambdaRange);
        Efficiency_FV->FillWeighted(passed_FV,e.Weight,0.5);

        // Track Cut

        Efficiency_Q2_Tracks->FillWeighted(passed_Tracks,e.Weight,Q2);
        Efficiency_NuE_Tracks->FillWeighted(passed_Tracks,e.Weight,NuE);
        Efficiency_MuonKE_Tracks->FillWeighted(passed_Tracks,e.Weight,MuonKE);
        Efficiency_MuonTrueTheta_Tracks->FillWeighted(passed_Tracks,e.Weight,MuonTrueTheta);
        Efficiency_MuonDetectorTheta_Tracks->FillWeighted(passed_Tracks,e.Weight,MuonDetectorTheta);
        Efficiency_MuonDetectorPhi_Tracks->FillWeighted(passed_Tracks,e.Weight,MuonDetectorPhi);
        Efficiency_MuonBeamTheta_Tracks->FillWeighted(passed_Tracks,e.Weight,MuonBeamTheta);
        Efficiency_MuonBeamPhi_Tracks->FillWeighted(passed_Tracks,e.Weight,MuonBeamPhi);
        Efficiency_LambdaMomentum_Tracks->FillWeighted(passed_Tracks,e.Weight,LambdaMomentum);
        Efficiency_DecayProtonMomentum_Tracks->FillWeighted(passed_Tracks,e.Weight,DecayProtonMomentum);
        Efficiency_DecayPionMomentum_Tracks->FillWeighted(passed_Tracks,e.Weight,DecayPionMomentum);
        Efficiency_OpeningAngle_Tracks->FillWeighted(passed_Tracks,e.Weight,OpeningAngle);
        Efficiency_LambdaRange_Tracks->FillWeighted(passed_Tracks,e.Weight,LambdaRange);
        Efficiency_Tracks->FillWeighted(passed_Tracks,e.Weight,0.5);

        // Shower Cut

        Efficiency_Q2_Showers->FillWeighted(passed_Showers,e.Weight,Q2);
        Efficiency_NuE_Showers->FillWeighted(passed_Showers,e.Weight,NuE);
        Efficiency_MuonKE_Showers->FillWeighted(passed_Showers,e.Weight,MuonKE);
        Efficiency_MuonTrueTheta_Showers->FillWeighted(passed_Showers,e.Weight,MuonTrueTheta);
        Efficiency_MuonDetectorTheta_Showers->FillWeighted(passed_Showers,e.Weight,MuonDetectorTheta);
        Efficiency_MuonDetectorPhi_Showers->FillWeighted(passed_Showers,e.Weight,MuonDetectorPhi);
        Efficiency_MuonBeamTheta_Showers->FillWeighted(passed_Showers,e.Weight,MuonBeamTheta);
        Efficiency_MuonBeamPhi_Showers->FillWeighted(passed_Showers,e.Weight,MuonBeamPhi);
        Efficiency_LambdaMomentum_Showers->FillWeighted(passed_Showers,e.Weight,LambdaMomentum);
        Efficiency_DecayProtonMomentum_Showers->FillWeighted(passed_Showers,e.Weight,DecayProtonMomentum);
        Efficiency_DecayPionMomentum_Showers->FillWeighted(passed_Showers,e.Weight,DecayPionMomentum);
        Efficiency_OpeningAngle_Showers->FillWeighted(passed_Showers,e.Weight,OpeningAngle);
        Efficiency_LambdaRange_Showers->FillWeighted(passed_Showers,e.Weight,LambdaRange);
        Efficiency_Showers->FillWeighted(passed_Showers,e.Weight,0.5);

        // Muon ID

        Efficiency_Q2_MuonID->FillWeighted(passed_MuonID,e.Weight,Q2);
        Efficiency_NuE_MuonID->FillWeighted(passed_MuonID,e.Weight,NuE);
        Efficiency_MuonKE_MuonID->FillWeighted(passed_MuonID,e.Weight,MuonKE);
        Efficiency_MuonTrueTheta_MuonID->FillWeighted(passed_MuonID,e.Weight,MuonTrueTheta);
        Efficiency_MuonDetectorTheta_MuonID->FillWeighted(passed_MuonID,e.Weight,MuonDetectorTheta);
        Efficiency_MuonDetectorPhi_MuonID->FillWeighted(passed_MuonID,e.Weight,MuonDetectorPhi);
        Efficiency_MuonBeamTheta_MuonID->FillWeighted(passed_MuonID,e.Weight,MuonBeamTheta);
        Efficiency_MuonBeamPhi_MuonID->FillWeighted(passed_MuonID,e.Weight,MuonBeamPhi);
        Efficiency_LambdaMomentum_MuonID->FillWeighted(passed_MuonID,e.Weight,LambdaMomentum);
        Efficiency_DecayProtonMomentum_MuonID->FillWeighted(passed_MuonID,e.Weight,DecayProtonMomentum);
        Efficiency_DecayPionMomentum_MuonID->FillWeighted(passed_MuonID,e.Weight,DecayPionMomentum);
        Efficiency_OpeningAngle_MuonID->FillWeighted(passed_MuonID,e.Weight,OpeningAngle);
        Efficiency_LambdaRange_MuonID->FillWeighted(passed_MuonID,e.Weight,LambdaRange);
        Efficiency_MuonID->FillWeighted(passed_MuonID,e.Weight,0.5);

        // Decay Selector

        Efficiency_Q2_Selector->FillWeighted(passed_Selector,e.Weight,Q2); 
        Efficiency_NuE_Selector->FillWeighted(passed_Selector,e.Weight,NuE);
        Efficiency_MuonKE_Selector->FillWeighted(passed_Selector,e.Weight,MuonKE); 
        Efficiency_MuonTrueTheta_Selector->FillWeighted(passed_Selector,e.Weight,MuonTrueTheta); 
        Efficiency_MuonDetectorTheta_Selector->FillWeighted(passed_Selector,e.Weight,MuonDetectorTheta);
        Efficiency_MuonDetectorPhi_Selector->FillWeighted(passed_Selector,e.Weight,MuonDetectorPhi);
        Efficiency_MuonBeamTheta_Selector->FillWeighted(passed_Selector,e.Weight,MuonBeamTheta);
        Efficiency_MuonBeamPhi_Selector->FillWeighted(passed_Selector,e.Weight,MuonBeamPhi); 
        Efficiency_LambdaMomentum_Selector->FillWeighted(passed_Selector,e.Weight,LambdaMomentum); 
        Efficiency_DecayProtonMomentum_Selector->FillWeighted(passed_Selector,e.Weight,DecayProtonMomentum); 
        Efficiency_DecayPionMomentum_Selector->FillWeighted(passed_Selector,e.Weight,DecayPionMomentum);
        Efficiency_OpeningAngle_Selector->FillWeighted(passed_Selector,e.Weight,OpeningAngle);
        Efficiency_Selector->FillWeighted(passed_Selector,e.Weight,0.5);
        Efficiency_LambdaRange_Selector->FillWeighted(passed_Selector,e.Weight,LambdaRange);

        // Connectedness

        Efficiency_Q2_CT->FillWeighted(passed_CT,e.Weight,Q2); 
        Efficiency_NuE_CT->FillWeighted(passed_CT,e.Weight,NuE); 
        Efficiency_MuonKE_CT->FillWeighted(passed_CT,e.Weight,MuonKE); 
        Efficiency_MuonTrueTheta_CT->FillWeighted(passed_CT,e.Weight,MuonTrueTheta); 
        Efficiency_MuonDetectorTheta_CT->FillWeighted(passed_CT,e.Weight,MuonDetectorTheta);
        Efficiency_MuonDetectorPhi_CT->FillWeighted(passed_CT,e.Weight,MuonDetectorPhi); 
        Efficiency_MuonBeamTheta_CT->FillWeighted(passed_CT,e.Weight,MuonBeamTheta);
        Efficiency_MuonBeamPhi_CT->FillWeighted(passed_CT,e.Weight,MuonBeamPhi); 
        Efficiency_LambdaMomentum_CT->FillWeighted(passed_CT,e.Weight,LambdaMomentum); 
        Efficiency_DecayProtonMomentum_CT->FillWeighted(passed_CT,e.Weight,DecayProtonMomentum); 
        Efficiency_DecayPionMomentum_CT->FillWeighted(passed_CT,e.Weight,DecayPionMomentum);
        Efficiency_OpeningAngle_CT->FillWeighted(passed_CT,e.Weight,OpeningAngle);
        Efficiency_LambdaRange_CT->FillWeighted(passed_CT,e.Weight,LambdaRange);
        Efficiency_CT->FillWeighted(passed_CT,e.Weight,0.5);

        // Invariant mass cut

        Efficiency_Q2_WCut->FillWeighted(passed_WCut,e.Weight,Q2); 
        Efficiency_NuE_WCut->FillWeighted(passed_WCut,e.Weight,NuE); 
        Efficiency_MuonKE_WCut->FillWeighted(passed_WCut,e.Weight,MuonKE);
        Efficiency_MuonTrueTheta_WCut->FillWeighted(passed_WCut,e.Weight,MuonTrueTheta); 
        Efficiency_MuonDetectorTheta_WCut->FillWeighted(passed_WCut,e.Weight,MuonDetectorTheta);
        Efficiency_MuonDetectorPhi_WCut->FillWeighted(passed_WCut,e.Weight,MuonDetectorPhi); 
        Efficiency_MuonBeamTheta_WCut->FillWeighted(passed_WCut,e.Weight,MuonBeamTheta); 
        Efficiency_MuonBeamPhi_WCut->FillWeighted(passed_WCut,e.Weight,MuonBeamPhi); 
        Efficiency_LambdaMomentum_WCut->FillWeighted(passed_WCut,e.Weight,LambdaMomentum);
        Efficiency_DecayProtonMomentum_WCut->FillWeighted(passed_WCut,e.Weight,DecayProtonMomentum);
        Efficiency_DecayPionMomentum_WCut->FillWeighted(passed_WCut,e.Weight,DecayPionMomentum);
        Efficiency_OpeningAngle_WCut->FillWeighted(passed_WCut,e.Weight,OpeningAngle);
        Efficiency_LambdaRange_WCut->FillWeighted(passed_WCut,e.Weight,LambdaRange);
        Efficiency_WCut->FillWeighted(passed_WCut,e.Weight,0.5);

        // Angle cut

        Efficiency_Q2_AngleCut->FillWeighted(passed_AngleCut,e.Weight,Q2); 
        Efficiency_NuE_AngleCut->FillWeighted(passed_AngleCut,e.Weight,NuE); 
        Efficiency_MuonKE_AngleCut->FillWeighted(passed_AngleCut,e.Weight,MuonKE); 
        Efficiency_MuonTrueTheta_AngleCut->FillWeighted(passed_AngleCut,e.Weight,MuonTrueTheta);
        Efficiency_MuonDetectorTheta_AngleCut->FillWeighted(passed_AngleCut,e.Weight,MuonDetectorTheta); 
        Efficiency_MuonDetectorPhi_AngleCut->FillWeighted(passed_AngleCut,e.Weight,MuonDetectorPhi); 
        Efficiency_MuonBeamTheta_AngleCut->FillWeighted(passed_AngleCut,e.Weight,MuonBeamTheta); 
        Efficiency_MuonBeamPhi_AngleCut->FillWeighted(passed_AngleCut,e.Weight,MuonBeamPhi); 
        Efficiency_LambdaMomentum_AngleCut->FillWeighted(passed_AngleCut,e.Weight,LambdaMomentum); 
        Efficiency_DecayProtonMomentum_AngleCut->FillWeighted(passed_AngleCut,e.Weight,DecayProtonMomentum); 
        Efficiency_DecayPionMomentum_AngleCut->FillWeighted(passed_AngleCut,e.Weight,DecayPionMomentum);
        Efficiency_OpeningAngle_AngleCut->FillWeighted(passed_AngleCut,e.Weight,OpeningAngle);
        Efficiency_LambdaRange_AngleCut->FillWeighted(passed_AngleCut,e.Weight,LambdaRange);
        Efficiency_AngleCut->FillWeighted(passed_AngleCut,e.Weight,0.5);
    }

    //close the event assembler
    E.Close();

    // Entire Selection
    HypPlot::DrawEfficiencyPlot(Efficiency_Q2_All,";True Q^{2} (GeV^{2},Mode,POT);Events",label + "_Q2_All",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_NuE_All,";True E_{#nu} (GeV,Mode,POT);Events",label + "_NuE_All",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_MuonKE_All,";True Muon E_{k} (GeV,Mode,POT);Events",label + "_MuonKE_All",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_MuonTrueTheta_All,";True Muon #theta;Events",label + "_MuonTrueTheta_All",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_MuonDetectorTheta_All,";Detector Muon #theta;Events",label + "_MuonDetectorTheta_All",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_MuonDetectorPhi_All,";Detector Muon #phi;Events",label + "_MuonDetectorPhi_All",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_MuonBeamTheta_All,";Beam Muon #theta;Events",label + "_MuonBeamTheta_All",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_MuonBeamPhi_All,";Beam Muon #phi;Events",label + "_MuonBeamPhi_All",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_LambdaMomentum_All,";True #Lambda Momentum (GeV/c,Mode,POT);Events",label + "_LambdaMomentum_All",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_DecayProtonMomentum_All,";True Decay Proton Momentum (GeV/c,Mode,POT);Events",label + "_DecayProtonMomentum_All",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_DecayPionMomentum_All,";True Decay #pi^{-} Momentum (GeV/c,Mode,POT);Events",label + "_DecayPionMomentum_All",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_OpeningAngle_All,";True Opening Angle (deg,Mode,POT);Events",label + "_OpeningAngle_All",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_LambdaRange_All,";True #Lambda Range (cm,Mode,POT);Events",label + "_LambdaRange_All",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_All,";;Events",label + "_All",{kRHC},{POT});

    // Fiducial Volume Cut
    HypPlot::DrawEfficiencyPlot(Efficiency_Q2_FV,";True Q^{2} (GeV^{2},Mode,POT);Events",label + "_Q2_FV",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_NuE_FV,";True E_{#nu} (GeV,Mode,POT);Events",label + "_NuE_FV",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_MuonKE_FV,";True Muon E_{k} (GeV,Mode,POT);Events",label + "_MuonKE_FV",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_MuonTrueTheta_FV,";True Muon #theta;Events",label + "_MuonTrueTheta_FV",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_MuonDetectorTheta_FV,";Detector Muon #theta;Events",label + "_MuonDetectorTheta_FV",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_MuonDetectorPhi_FV,";Detector Muon #phi;Events",label + "_MuonDetectorPhi_FV",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_MuonBeamTheta_FV,";Beam Muon #theta;Events",label + "_MuonBeamTheta_FV",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_MuonBeamPhi_FV,";Beam Muon #phi;Events",label + "_MuonBeamPhi_FV",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_LambdaMomentum_FV,";True #Lambda Momentum (GeV/c,Mode,POT);Events",label + "_LambdaMomentum_FV",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_DecayProtonMomentum_FV,";True Decay Proton Momentum (GeV/c,Mode,POT);Events",label + "_DecayProtonMomentum_FV",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_DecayPionMomentum_FV,";True Decay #pi^{-} Momentum (GeV/c,Mode,POT);Events",label + "_DecayPionMomentum_FV",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_OpeningAngle_FV,";True Opening Angle (deg,Mode,POT);Events",label + "_OpeningAngle_FV",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_LambdaRange_FV,";True #Lambda Range (cm,Mode,POT);Events",label + "_LambdaRange_FV",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_FV,";;Events",label + "_FV",{kRHC},{POT});


    // Track Cut
    HypPlot::DrawEfficiencyPlot(Efficiency_Q2_Tracks,";True Q^{2} (GeV^{2},Mode,POT);Events",label + "_Q2_Tracks",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_NuE_Tracks,";True E_{#nu} (GeV,Mode,POT);Events",label + "_NuE_Tracks",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_MuonKE_Tracks,";True Muon E_{k} (GeV,Mode,POT);Events",label + "_MuonKE_Tracks",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_MuonTrueTheta_Tracks,";True Muon #theta;Events",label + "_MuonTrueTheta_Tracks",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_MuonDetectorTheta_Tracks,";Detector Muon #theta;Events",label + "_MuonDetectorTheta_Tracks",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_MuonDetectorPhi_Tracks,";Detector Muon #phi;Events",label + "_MuonDetectorPhi_Tracks",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_MuonBeamTheta_Tracks,";Beam Muon #theta;Events",label + "_MuonBeamTheta_Tracks",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_MuonBeamPhi_Tracks,";Beam Muon #phi;Events",label + "_MuonBeamPhi_Tracks",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_LambdaMomentum_Tracks,";True #Lambda Momentum (GeV/c,Mode,POT);Events",label + "_LambdaMomentum_Tracks",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_DecayProtonMomentum_Tracks,";True Decay Proton Momentum (GeV/c,Mode,POT);Events",label + "_DecayProtonMomentum_Tracks",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_DecayPionMomentum_Tracks,";True Decay #pi^{-} Momentum (GeV/c,Mode,POT);Events",label + "_DecayPionMomentum_Tracks",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_OpeningAngle_Tracks,";True Opening Angle (deg,Mode,POT);Events",label + "_OpeningAngle_Tracks",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_LambdaRange_Tracks,";True #Lambda Range (cm,Mode,POT);Events",label + "_LambdaRange_Tracks",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_Tracks,";;Events",label + "_Tracks",{kRHC},{POT});

    // Shower Cut
    HypPlot::DrawEfficiencyPlot(Efficiency_Q2_Showers,";True Q^{2} (GeV^{2},Mode,POT);Events",label + "_Q2_Showers",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_NuE_Showers,";True E_{#nu} (GeV,Mode,POT);Events",label + "_NuE_Showers",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_MuonKE_Showers,";True Muon E_{k} (GeV,Mode,POT);Events",label + "_MuonKE_Showers",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_MuonTrueTheta_Showers,";True Muon #theta;Events",label + "_MuonTrueTheta_Showers",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_MuonDetectorTheta_Showers,";Detector Muon #theta;Events",label + "_MuonDetectorTheta_Showers",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_MuonDetectorPhi_Showers,";Detector Muon #phi;Events",label + "_MuonDetectorPhi_Showers",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_MuonBeamTheta_Showers,";Beam Muon #theta;Events",label + "_MuonBeamTheta_Showers",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_MuonBeamPhi_Showers,";Beam Muon #phi;Events",label + "_MuonBeamPhi_Showers",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_LambdaMomentum_Showers,";True #Lambda Momentum (GeV/c,Mode,POT);Events",label + "_LambdaMomentum_Showers",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_DecayProtonMomentum_Showers,";True Decay Proton Momentum (GeV/c,Mode,POT);Events",label + "_DecayProtonMomentum_Showers",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_DecayPionMomentum_Showers,";True Decay #pi^{-} Momentum (GeV/c,Mode,POT);Events",label + "_DecayPionMomentum_Showers",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_OpeningAngle_Showers,";True Opening Angle (deg,Mode,POT);Events",label + "_OpeningAngle_Showers",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_LambdaRange_Showers,";True #Lambda Range (cm,Mode,POT);Events",label + "_LambdaRange_Showers",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_Showers,";;Events",label + "_Showers",{kRHC},{POT});

    // Muon ID
    HypPlot::DrawEfficiencyPlot(Efficiency_Q2_MuonID,";True Q^{2} (GeV^{2},Mode,POT);Events",label + "_Q2_MuonID",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_NuE_MuonID,";True E_{#nu} (GeV,Mode,POT);Events",label + "_NuE_MuonID",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_MuonKE_MuonID,";True Muon E_{k} (GeV,Mode,POT);Events",label + "_MuonKE_MuonID",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_MuonTrueTheta_MuonID,";True Muon #theta;Events",label + "_MuonTrueTheta_MuonID",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_MuonDetectorTheta_MuonID,";Detector Muon #theta;Events",label + "_MuonDetectorTheta_MuonID",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_MuonDetectorPhi_MuonID,";Detector Muon #phi;Events",label + "_MuonDetectorPhi_MuonID",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_MuonBeamTheta_MuonID,";Beam Muon #theta;Events",label + "_MuonBeamTheta_MuonID",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_MuonBeamPhi_MuonID,";Beam Muon #phi;Events",label + "_MuonBeamPhi_MuonID",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_LambdaMomentum_MuonID,";True #Lambda Momentum (GeV/c,Mode,POT);Events",label + "_LambdaMomentum_MuonID",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_DecayProtonMomentum_MuonID,";True Decay Proton Momentum (GeV/c,Mode,POT);Events",label + "_DecayProtonMomentum_MuonID",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_DecayPionMomentum_MuonID,";True Decay #pi^{-} Momentum (GeV/c,Mode,POT);Events",label + "_DecayPionMomentum_MuonID",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_OpeningAngle_MuonID,";True Opening Angle (deg,Mode,POT);Events",label + "_OpeningAngle_MuonID",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_LambdaRange_MuonID,";True #Lambda Range (cm,Mode,POT);Events",label + "_LambdaRange_MuonID",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_MuonID,";;Events",label + "_MuonID",{kRHC},{POT});

    // Track Selector BDT
    HypPlot::DrawEfficiencyPlot(Efficiency_Q2_Selector,";True Q^{2} (GeV^{2},Mode,POT);Events",label + "_Q2_Selector",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_NuE_Selector,";True E_{#nu} (GeV,Mode,POT);Events",label + "_NuE_Selector",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_MuonKE_Selector,";True Muon E_{k} (GeV,Mode,POT);Events",label + "_MuonKE_Selector",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_MuonTrueTheta_Selector,";True Muon #theta;Events",label + "_MuonTrueTheta_Selector",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_MuonDetectorTheta_Selector,";Detector Muon #theta;Events",label + "_MuonDetectorTheta_Selector",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_MuonDetectorPhi_Selector,";Detector Muon #phi;Events",label + "_MuonDetectorPhi_Selector",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_MuonBeamTheta_Selector,";Beam Muon #theta;Events",label + "_MuonBeamTheta_Selector",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_MuonBeamPhi_Selector,";Beam Muon #phi;Events",label + "_MuonBeamPhi_Selector",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_LambdaMomentum_Selector,";True #Lambda Momentum (GeV/c,Mode,POT);Events",label + "_LambdaMomentum_Selector",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_DecayProtonMomentum_Selector,";True Decay Proton Momentum (GeV/c,Mode,POT);Events",label + "_DecayProtonMomentum_Selector",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_DecayPionMomentum_Selector,";True Decay #pi^{-} Momentum (GeV/c,Mode,POT);Events",label + "_DecayPionMomentum_Selector",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_OpeningAngle_Selector,";True Opening Angle (deg,Mode,POT);Events",label + "_OpeningAngle_Selector",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_LambdaRange_Selector,";True #Lambda Range (cm,Mode,POT);Events",label + "_LambdaRange_Selector",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_Selector,";;Events",label + "_Selector",{kRHC},{POT});


    // CT
    HypPlot::DrawEfficiencyPlot(Efficiency_Q2_CT,";True Q^{2} (GeV^{2},Mode,POT);Events",label + "_Q2_CT",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_NuE_CT,";True E_{#nu} (GeV,Mode,POT);Events",label + "_NuE_CT",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_MuonKE_CT,";True Muon E_{k} (GeV,Mode,POT);Events",label + "_MuonKE_CT",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_MuonTrueTheta_CT,";True Muon #theta;Events",label + "_MuonTrueTheta_CT",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_MuonDetectorTheta_CT,";Detector Muon #theta;Events",label + "_MuonDetectorTheta_CT",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_MuonDetectorPhi_CT,";Detector Muon #phi;Events",label + "_MuonDetectorPhi_CT",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_MuonBeamTheta_CT,";Beam Muon #theta;Events",label + "_MuonBeamTheta_CT",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_MuonBeamPhi_CT,";Beam Muon #phi;Events",label + "_MuonBeamPhi_CT",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_LambdaMomentum_CT,";True #Lambda Momentum (GeV/c,Mode,POT);Events",label + "_LambdaMomentum_CT",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_DecayProtonMomentum_CT,";True Decay Proton Momentum (GeV/c,Mode,POT);Events",label + "_DecayProtonMomentum_CT",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_DecayPionMomentum_CT,";True Decay #pi^{-} Momentum (GeV/c,Mode,POT);Events",label + "_DecayPionMomentum_CT",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_OpeningAngle_CT,";True Opening Angle (deg,Mode,POT);Events",label + "_OpeningAngle_CT",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_LambdaRange_CT,";True #Lambda Range (cm,Mode,POT);Events",label + "_LambdaRange_CT",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_CT,";;Events",label + "_CT",{kRHC},{POT});

    // WCut
    HypPlot::DrawEfficiencyPlot(Efficiency_Q2_WCut,";True Q^{2} (GeV^{2},Mode,POT);Events",label + "_Q2_WCut",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_NuE_WCut,";True E_{#nu} (GeV,Mode,POT);Events",label + "_NuE_WCut",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_MuonKE_WCut,";True Muon E_{k} (GeV,Mode,POT);Events",label + "_MuonKE_WCut",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_MuonTrueTheta_WCut,";True Muon #theta;Events",label + "_MuonTrueTheta_WCut",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_MuonDetectorTheta_WCut,";Detector Muon #theta;Events",label + "_MuonDetectorTheta_WCut",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_MuonDetectorPhi_WCut,";Detector Muon #phi;Events",label + "_MuonDetectorPhi_WCut",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_MuonBeamTheta_WCut,";Beam Muon #theta;Events",label + "_MuonBeamTheta_WCut",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_MuonBeamPhi_WCut,";Beam Muon #phi;Events",label + "_MuonBeamPhi_WCut",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_LambdaMomentum_WCut,";True #Lambda Momentum (GeV/c,Mode,POT);Events",label + "_LambdaMomentum_WCut",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_DecayProtonMomentum_WCut,";True Decay Proton Momentum (GeV/c,Mode,POT);Events",label + "_DecayProtonMomentum_WCut",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_DecayPionMomentum_WCut,";True Decay #pi^{-} Momentum (GeV/c,Mode,POT);Events",label + "_DecayPionMomentum_WCut",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_OpeningAngle_WCut,";True Opening Angle (deg,Mode,POT);Events",label + "_OpeningAngle_WCut",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_LambdaRange_WCut,";True #Lambda Range (cm,Mode,POT);Events",label + "_LambdaRange_WCut",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_WCut,";;Events",label + "_WCut",{kRHC},{POT});

    // AngleCut
    HypPlot::DrawEfficiencyPlot(Efficiency_Q2_AngleCut,";True Q^{2} (GeV^{2},Mode,POT);Events",label + "_Q2_AngleCut",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_NuE_AngleCut,";True E_{#nu} (GeV,Mode,POT);Events",label + "_NuE_AngleCut",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_MuonKE_AngleCut,";True Muon E_{k} (GeV,Mode,POT);Events",label + "_MuonKE_AngleCut",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_MuonTrueTheta_AngleCut,";True Muon #theta;Events",label + "_MuonTrueTheta_AngleCut",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_MuonDetectorTheta_AngleCut,";Detector Muon #theta;Events",label + "_MuonDetectorTheta_AngleCut",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_MuonDetectorPhi_AngleCut,";Detector Muon #phi;Events",label + "_MuonDetectorPhi_AngleCut",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_MuonBeamTheta_AngleCut,";Beam Muon #theta;Events",label + "_MuonBeamTheta_AngleCut",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_MuonBeamPhi_AngleCut,";Beam Muon #phi;Events",label + "_MuonBeamPhi_AngleCut",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_LambdaMomentum_AngleCut,";True #Lambda Momentum (GeV/c,Mode,POT);Events",label + "_LambdaMomentum_AngleCut",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_DecayProtonMomentum_AngleCut,";True Decay Proton Momentum (GeV/c,Mode,POT);Events",label + "_DecayProtonMomentum_AngleCut",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_DecayPionMomentum_AngleCut,";True Decay #pi^{-} Momentum (GeV/c,Mode,POT);Events",label + "_DecayPionMomentum_AngleCut",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_OpeningAngle_AngleCut,";True Opening Angle (deg,Mode,POT);Events",label + "_OpeningAngle_AngleCut",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_LambdaRange_AngleCut,";True #Lambda Range (cm,Mode,POT);Events",label + "_LambdaRange_AngleCut",{kRHC},{POT});
    HypPlot::DrawEfficiencyPlot(Efficiency_AngleCut,";;Events",label + "_AngleCut",{kRHC},{POT});
}

