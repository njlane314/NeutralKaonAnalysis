R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so)
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so)

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "TEfficiency.h"
#include "DrawEfficiencyPlot.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

   // Generates efficiency curves for every stage of the selection
   // against a variety of different variables to monitor any
   // phase space dependence in the selection

   void PhaseSpaceTest(){

      BuildTunes();

      std::string label = "test";

      const double POT = 1e21; // POT to scale samples to
      const int Mode = kFHC;

      SelectionParameters P = P_FHC_Tune_325_NoBDT;

      // Setup selection manager. Set POT to scale sample to
      EventAssembler E;
      SelectionManager M(P);
      M.SetPOT(POT);
      M.ImportSelectorBDTWeights(P.p_SelectorBDT_WeightsDir);
      //M.ImportAnalysisBDTWeights(P.p_AnalysisBDT_WeightsDir);

      /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

      // All Cuts //

      TH1D *h_Q2_All = new TH1D("h_Q2_All","",60,0,3.0);
      TH1D *h_SelectedQ2_All = new TH1D("h_SelectedQ2_All","",60,0,3.0);
      TEfficiency* Efficiency_Q2_All = new TEfficiency("Q2_eff_All",";True Q^{2} (GeV^{2});Selected/All",60,0,3.0);

      TH1D *h_NuE_All = new TH1D("h_TrueNuE_All","",60,0,4.0);
      TH1D *h_SelectedNuE_All = new TH1D("h_SelectedNuE_All","",60,0,4.0);
      TEfficiency* Efficiency_NuE_All = new TEfficiency("NuE_eff_All",";True E_{#nu} (GeV);Selected/All",60,0,4.0);

      TH1D *h_MuonKE_All = new TH1D("h_MuonKE_All","",60,0,3.0);
      TH1D *h_SelectedMuonKE_All = new TH1D("h_SelectedMuonKE_All","",60,0,3.0);
      TEfficiency* Efficiency_MuonKE_All = new TEfficiency("MuonKE_eff_All",";True Muon KE (GeV);Selected/All",60,0,3.0);

      TH1D *h_MuonTrueTheta_All = new TH1D("h_MuonTrueTheta_All","",60,0,3.1415);
      TH1D *h_SelectedMuonTrueTheta_All = new TH1D("h_SelectedMuonTrueTheta_All","",60,0,3.1415);
      TEfficiency* Efficiency_MuonTrueTheta_All = new TEfficiency("MuonTrueTheta_eff_All",";Muon True #theta;Selected/All",60,0,3.1415);

      TH1D *h_MuonDetectorTheta_All = new TH1D("h_TrueMuonDetectorTheta_All","",60,0,3.1415);
      TH1D *h_SelectedMuonDetectorTheta_All = new TH1D("h_SelectedMuonDetectorTheta_All","",60,0,3.1415);
      TEfficiency* Efficiency_MuonDetectorTheta_All = new TEfficiency("MuonDetectorTheta_eff",";Muon Detector #theta;Selected/All",60,0,3.1415);

      TH1D *h_MuonDetectorPhi_All = new TH1D("h_TrueMuonDetectorPhi_All","",60,-3.1415,3.1415);
      TH1D *h_SelectedMuonDetectorPhi_All = new TH1D("h_SelectedMuonDetectorPhi_All","",60,-3.1415,3.1415);
      TEfficiency* Efficiency_MuonDetectorPhi_All = new TEfficiency("MuonDetectorPhi_eff_All",";Muon Detector #theta;Selected/All",60,-3.1415,3.1415);

      TH1D *h_MuonBeamTheta_All = new TH1D("h_TrueMuonBeamTheta_All","",60,0,3.1415);
      TH1D *h_SelectedMuonBeamTheta_All = new TH1D("h_SelectedMuonBeamTheta_All","",60,0,3.1415);
      TEfficiency* Efficiency_MuonBeamTheta_All = new TEfficiency("MuonBeamTheta_eff_All",";Muon Beam #theta;Selected/All",60,0,3.1415);

      TH1D *h_MuonBeamPhi_All = new TH1D("h_TrueMuonBeamPhi_All","",60,-3.1415,3.1415);
      TH1D *h_SelectedMuonBeamPhi_All = new TH1D("h_SelectedMuonBeamPhi_All","",60,-3.1415,3.1415);
      TEfficiency* Efficiency_MuonBeamPhi_All = new TEfficiency("MuonBeamPhi_eff_All",";Muon Beam #theta;Selected/All",60,-3.1415,3.1415);

      TH1D *h_LambdaMomentum_All = new TH1D("h_TrueLambdaMomentum_All","",60,0.0,2.0);
      TH1D *h_SelectedLambdaMomentum_All = new TH1D("h_SelectedLambdaMomentum_All","",60,0.0,2.0);
      TEfficiency* Efficiency_LambdaMomentum_All = new TEfficiency("LambdaMomentum_eff_All",";True #Lambda Momentum (GeV/c);Selected/All",60,0.0,2.0);

      TH1D *h_DecayProtonMomentum_All = new TH1D("h_TrueDecayProtonMomentum_All","",60,0.3,1.5);
      TH1D *h_SelectedDecayProtonMomentum_All = new TH1D("h_SelectedDecayProtonMomentum_All","",60,0.3,1.5);
      TEfficiency* Efficiency_DecayProtonMomentum_All = new TEfficiency("DecayProtonMomentum_eff_All",";True Decay Proton Momentum (GeV/c);Selected/All",60,0.3,1.5);

      TH1D *h_DecayPionMomentum_All = new TH1D("h_TrueDecayPionMomentum_All","",60,0.1,0.8);
      TH1D *h_SelectedDecayPionMomentum_All = new TH1D("h_SelectedDecayPionMomentum_All","",60,0.1,0.8);
      TEfficiency* Efficiency_DecayPionMomentum_All = new TEfficiency("DecayPionMomentum_eff_All",";True Decay #pi^{-} Momentum (GeV/c);Selected/All",60,0.1,0.8);

      TH1D *h_OpeningAngle_All = new TH1D("h_OpeningAngle_All","",60,0,100);
      TH1D *h_SelectedOpeningAngle_All = new TH1D("h_SelectedOpeningAngle_All","",60,0,100);
      TEfficiency* Efficiency_OpeningAngle_All = new TEfficiency("OpeningAngle_eff_All",";True Opening Angle (deg);Selected/All",60,0,100);

      TH1D *h_LambdaRange_All = new TH1D("h_LambdaRange_All","",100,0,20.0);
      TH1D *h_SelectedLambdaRange_All = new TH1D("h_SelectedLambdaRange_All","",100,0,20.0);
      TEfficiency* Efficiency_LambdaRange_All = new TEfficiency("LambdaRange_eff_All",";True #Lambda Range (cm);Selected/All",100,0,20.0);

      TH1D *h_All = new TH1D("h_All","",1,0,1.0);
      TH1D *h_Selected_All = new TH1D("h_Selected_All","",1,0,1.0);
      TEfficiency* Efficiency_All = new TEfficiency("eff_All",";;Selected/All",1,0,1.0);


      // Fiducial Volume Cut //

      TH1D *h_Q2_FV = new TH1D("h_Q2_FV","",60,0,3.0);
      TH1D *h_SelectedQ2_FV = new TH1D("h_SelectedQ2_FV","",60,0,3.0);
      TEfficiency* Efficiency_Q2_FV = new TEfficiency("Q2_eff_FV",";True Q^{2} (GeV^{2});Selected/All",60,0,3.0);

      TH1D *h_NuE_FV = new TH1D("h_TrueNuE_FV","",60,0,4.0);
      TH1D *h_SelectedNuE_FV = new TH1D("h_SelectedNuE_FV","",60,0,4.0);
      TEfficiency* Efficiency_NuE_FV = new TEfficiency("NuE_eff_FV",";True E_{#nu} (GeV);Selected/All",60,0,4.0);

      TH1D *h_MuonKE_FV = new TH1D("h_MuonKE_FV","",60,0,3.0);
      TH1D *h_SelectedMuonKE_FV = new TH1D("h_SelectedMuonKE_FV","",60,0,3.0);
      TEfficiency* Efficiency_MuonKE_FV = new TEfficiency("MuonKE_eff_FV",";True Muon KE (GeV);Selected/All",60,0,3.0);

      TH1D *h_MuonTrueTheta_FV = new TH1D("h_MuonTrueTheta_FV","",60,0,3.1415);
      TH1D *h_SelectedMuonTrueTheta_FV = new TH1D("h_SelectedMuonTrueTheta_FV","",60,0,3.1415);
      TEfficiency* Efficiency_MuonTrueTheta_FV = new TEfficiency("MuonTrueTheta_eff_FV",";Muon True #theta;Selected/All",60,0,3.1415);

      TH1D *h_MuonDetectorTheta_FV = new TH1D("h_TrueMuonDetectorTheta_FV","",60,0,3.1415);
      TH1D *h_SelectedMuonDetectorTheta_FV = new TH1D("h_SelectedMuonDetectorTheta_FV","",60,0,3.1415);
      TEfficiency* Efficiency_MuonDetectorTheta_FV = new TEfficiency("MuonDetectorTheta_eff",";Muon Detector #theta;Selected/All",60,0,3.1415);

      TH1D *h_MuonDetectorPhi_FV = new TH1D("h_TrueMuonDetectorPhi_FV","",60,-3.1415,3.1415);
      TH1D *h_SelectedMuonDetectorPhi_FV = new TH1D("h_SelectedMuonDetectorPhi_FV","",60,-3.1415,3.1415);
      TEfficiency* Efficiency_MuonDetectorPhi_FV = new TEfficiency("MuonDetectorPhi_eff_FV",";Muon Detector #theta;Selected/All",60,-3.1415,3.1415);

      TH1D *h_MuonBeamTheta_FV = new TH1D("h_TrueMuonBeamTheta_FV","",60,0,3.1415);
      TH1D *h_SelectedMuonBeamTheta_FV = new TH1D("h_SelectedMuonBeamTheta_FV","",60,0,3.1415);
      TEfficiency* Efficiency_MuonBeamTheta_FV = new TEfficiency("MuonBeamTheta_eff_FV",";Muon Beam #theta;Selected/All",60,0,3.1415);

      TH1D *h_MuonBeamPhi_FV = new TH1D("h_TrueMuonBeamPhi_FV","",60,-3.1415,3.1415);
      TH1D *h_SelectedMuonBeamPhi_FV = new TH1D("h_SelectedMuonBeamPhi_FV","",60,-3.1415,3.1415);
      TEfficiency* Efficiency_MuonBeamPhi_FV = new TEfficiency("MuonBeamPhi_eff_FV",";Muon Beam #theta;Selected/All",60,-3.1415,3.1415);

      TH1D *h_LambdaMomentum_FV = new TH1D("h_TrueLambdaMomentum_FV","",60,0.0,2.0);
      TH1D *h_SelectedLambdaMomentum_FV = new TH1D("h_SelectedLambdaMomentum_FV","",60,0.0,2.0);
      TEfficiency* Efficiency_LambdaMomentum_FV = new TEfficiency("LambdaMomentum_eff_FV",";True #Lambda Momentum (GeV/c);Selected/All",60,0.0,2.0);

      TH1D *h_DecayProtonMomentum_FV = new TH1D("h_TrueDecayProtonMomentum_FV","",60,0.3,1.5);
      TH1D *h_SelectedDecayProtonMomentum_FV = new TH1D("h_SelectedDecayProtonMomentum_FV","",60,0.3,1.5);
      TEfficiency* Efficiency_DecayProtonMomentum_FV = new TEfficiency("DecayProtonMomentum_eff_FV",";True Decay Proton Momentum (GeV/c);Selected/All",60,0.3,1.5);

      TH1D *h_DecayPionMomentum_FV = new TH1D("h_TrueDecayPionMomentum_FV","",60,0.1,0.8);
      TH1D *h_SelectedDecayPionMomentum_FV = new TH1D("h_SelectedDecayPionMomentum_FV","",60,0.1,0.8);
      TEfficiency* Efficiency_DecayPionMomentum_FV = new TEfficiency("DecayPionMomentum_eff_FV",";True Decay #pi^{-} Momentum (GeV/c);Selected/All",60,0.1,0.8);

      TH1D *h_OpeningAngle_FV = new TH1D("h_OpeningAngle_FV","",60,0,100);
      TH1D *h_SelectedOpeningAngle_FV = new TH1D("h_SelectedOpeningAngle_FV","",60,0,100);
      TEfficiency* Efficiency_OpeningAngle_FV = new TEfficiency("OpeningAngle_eff_FV",";True Opening Angle (deg);Selected/All",60,0,100);

      TH1D *h_LambdaRange_FV = new TH1D("h_LambdaRange_FV","",100,0,20.0);
      TH1D *h_SelectedLambdaRange_FV = new TH1D("h_SelectedLambdaRange_FV","",100,0,20.0);
      TEfficiency* Efficiency_LambdaRange_FV = new TEfficiency("LambdaRange_eff_FV",";True #Lambda Range (cm);Selected/All",100,0,20.0);

      TH1D *h_FV = new TH1D("h_FV","",1,0,1.0);
      TH1D *h_Selected_FV = new TH1D("h_Selected_FV","",1,0,1.0);
      TEfficiency* Efficiency_FV = new TEfficiency("eff_FV",";;Selected/All",1,0,1.0);

      // Track Cut //

      TH1D *h_Q2_Tracks = new TH1D("h_Q2_Tracks","",60,0,3.0);
      TH1D *h_SelectedQ2_Tracks = new TH1D("h_SelectedQ2_Tracks","",60,0,3.0);
      TEfficiency* Efficiency_Q2_Tracks = new TEfficiency("Q2_eff_Tracks",";True Q^{2} (GeV^{2});Selected/All",60,0,3.0);

      TH1D *h_NuE_Tracks = new TH1D("h_TrueNuE_Tracks","",60,0,4.0);
      TH1D *h_SelectedNuE_Tracks = new TH1D("h_SelectedNuE_Tracks","",60,0,4.0);
      TEfficiency* Efficiency_NuE_Tracks = new TEfficiency("NuE_eff_Tracks",";True E_{#nu} (GeV);Selected/All",60,0,4.0);

      TH1D *h_MuonKE_Tracks = new TH1D("h_MuonKE_Tracks","",60,0,3.0);
      TH1D *h_SelectedMuonKE_Tracks = new TH1D("h_SelectedMuonKE_Tracks","",60,0,3.0);
      TEfficiency* Efficiency_MuonKE_Tracks = new TEfficiency("MuonKE_eff_Tracks",";True Muon KE (GeV);Selected/All",60,0,3.0);

      TH1D *h_MuonTrueTheta_Tracks = new TH1D("h_MuonTrueTheta_Tracks","",60,0,3.1415);
      TH1D *h_SelectedMuonTrueTheta_Tracks = new TH1D("h_SelectedMuonTrueTheta_Tracks","",60,0,3.1415);
      TEfficiency* Efficiency_MuonTrueTheta_Tracks = new TEfficiency("MuonTrueTheta_eff_Tracks",";Muon True #theta;Selected/All",60,0,3.1415);

      TH1D *h_MuonDetectorTheta_Tracks = new TH1D("h_TrueMuonDetectorTheta_Tracks","",60,0,3.1415);
      TH1D *h_SelectedMuonDetectorTheta_Tracks = new TH1D("h_SelectedMuonDetectorTheta_Tracks","",60,0,3.1415);
      TEfficiency* Efficiency_MuonDetectorTheta_Tracks = new TEfficiency("MuonDetectorTheta_eff",";Muon Detector #theta;Selected/All",60,0,3.1415);

      TH1D *h_MuonDetectorPhi_Tracks = new TH1D("h_TrueMuonDetectorPhi_Tracks","",60,-3.1415,3.1415);
      TH1D *h_SelectedMuonDetectorPhi_Tracks = new TH1D("h_SelectedMuonDetectorPhi_Tracks","",60,-3.1415,3.1415);
      TEfficiency* Efficiency_MuonDetectorPhi_Tracks = new TEfficiency("MuonDetectorPhi_eff_Tracks",";Muon Detector #theta;Selected/All",60,-3.1415,3.1415);

      TH1D *h_MuonBeamTheta_Tracks = new TH1D("h_TrueMuonBeamTheta_Tracks","",60,0,3.1415);
      TH1D *h_SelectedMuonBeamTheta_Tracks = new TH1D("h_SelectedMuonBeamTheta_Tracks","",60,0,3.1415);
      TEfficiency* Efficiency_MuonBeamTheta_Tracks = new TEfficiency("MuonBeamTheta_eff_Tracks",";Muon Beam #theta;Selected/All",60,0,3.1415);

      TH1D *h_MuonBeamPhi_Tracks = new TH1D("h_TrueMuonBeamPhi_Tracks","",60,-3.1415,3.1415);
      TH1D *h_SelectedMuonBeamPhi_Tracks = new TH1D("h_SelectedMuonBeamPhi_Tracks","",60,-3.1415,3.1415);
      TEfficiency* Efficiency_MuonBeamPhi_Tracks = new TEfficiency("MuonBeamPhi_eff_Tracks",";Muon Beam #theta;Selected/All",60,-3.1415,3.1415);

      TH1D *h_LambdaMomentum_Tracks = new TH1D("h_TrueLambdaMomentum_Tracks","",60,0.0,2.0);
      TH1D *h_SelectedLambdaMomentum_Tracks = new TH1D("h_SelectedLambdaMomentum_Tracks","",60,0.0,2.0);
      TEfficiency* Efficiency_LambdaMomentum_Tracks = new TEfficiency("LambdaMomentum_eff_Tracks",";True #Lambda Momentum (GeV/c);Selected/All",60,0.0,2.0);

      TH1D *h_DecayProtonMomentum_Tracks = new TH1D("h_TrueDecayProtonMomentum_Tracks","",60,0.3,1.5);
      TH1D *h_SelectedDecayProtonMomentum_Tracks = new TH1D("h_SelectedDecayProtonMomentum_Tracks","",60,0.3,1.5);
      TEfficiency* Efficiency_DecayProtonMomentum_Tracks = new TEfficiency("DecayProtonMomentum_eff_Tracks",";True Decay Proton Momentum (GeV/c);Selected/All",60,0.3,1.5);

      TH1D *h_DecayPionMomentum_Tracks = new TH1D("h_TrueDecayPionMomentum_Tracks","",60,0.1,0.8);
      TH1D *h_SelectedDecayPionMomentum_Tracks = new TH1D("h_SelectedDecayPionMomentum_Tracks","",60,0.1,0.8);
      TEfficiency* Efficiency_DecayPionMomentum_Tracks = new TEfficiency("DecayPionMomentum_eff_Tracks",";True Decay #pi^{-} Momentum (GeV/c);Selected/All",60,0.1,0.8);

      TH1D *h_OpeningAngle_Tracks = new TH1D("h_OpeningAngle_Tracks","",60,0,100);
      TH1D *h_SelectedOpeningAngle_Tracks = new TH1D("h_SelectedOpeningAngle_Tracks","",60,0,100);
      TEfficiency* Efficiency_OpeningAngle_Tracks = new TEfficiency("OpeningAngle_eff_Tracks",";True Opening Angle (deg);Selected/All",60,0,100);

      TH1D *h_LambdaRange_Tracks = new TH1D("h_LambdaRange_Tracks","",100,0,20.0);
      TH1D *h_SelectedLambdaRange_Tracks = new TH1D("h_SelectedLambdaRange_Tracks","",100,0,20.0);
      TEfficiency* Efficiency_LambdaRange_Tracks = new TEfficiency("LambdaRange_eff_Tracks",";True #Lambda Range (cm);Selected/All",100,0,20.0);

      TH1D *h_Tracks = new TH1D("h_Tracks","",1,0,1.0);
      TH1D *h_Selected_Tracks = new TH1D("h_Selected_Tracks","",1,0,1.0);
      TEfficiency* Efficiency_Tracks = new TEfficiency("eff_Tracks",";;Selected/All",1,0,1.0);

      // Shower Cut //

      TH1D *h_Q2_Showers = new TH1D("h_Q2_Showers","",60,0,3.0);
      TH1D *h_SelectedQ2_Showers = new TH1D("h_SelectedQ2_Showers","",60,0,3.0);
      TEfficiency* Efficiency_Q2_Showers = new TEfficiency("Q2_eff_Showers",";True Q^{2} (GeV^{2});Selected/All",60,0,3.0);

      TH1D *h_NuE_Showers = new TH1D("h_TrueNuE_Showers","",60,0,4.0);
      TH1D *h_SelectedNuE_Showers = new TH1D("h_SelectedNuE_Showers","",60,0,4.0);
      TEfficiency* Efficiency_NuE_Showers = new TEfficiency("NuE_eff_Showers",";True E_{#nu} (GeV);Selected/All",60,0,4.0);

      TH1D *h_MuonKE_Showers = new TH1D("h_MuonKE_Showers","",60,0,3.0);
      TH1D *h_SelectedMuonKE_Showers = new TH1D("h_SelectedMuonKE_Showers","",60,0,3.0);
      TEfficiency* Efficiency_MuonKE_Showers = new TEfficiency("MuonKE_eff_Showers",";True Muon KE (GeV);Selected/All",60,0,3.0);

      TH1D *h_MuonTrueTheta_Showers = new TH1D("h_MuonTrueTheta_Showers","",60,0,3.1415);
      TH1D *h_SelectedMuonTrueTheta_Showers = new TH1D("h_SelectedMuonTrueTheta_Showers","",60,0,3.1415);
      TEfficiency* Efficiency_MuonTrueTheta_Showers = new TEfficiency("MuonTrueTheta_eff_Showers",";Muon True #theta;Selected/All",60,0,3.1415);

      TH1D *h_MuonDetectorTheta_Showers = new TH1D("h_TrueMuonDetectorTheta_Showers","",60,0,3.1415);
      TH1D *h_SelectedMuonDetectorTheta_Showers = new TH1D("h_SelectedMuonDetectorTheta_Showers","",60,0,3.1415);
      TEfficiency* Efficiency_MuonDetectorTheta_Showers = new TEfficiency("MuonDetectorTheta_eff",";Muon Detector #theta;Selected/All",60,0,3.1415);

      TH1D *h_MuonDetectorPhi_Showers = new TH1D("h_TrueMuonDetectorPhi_Showers","",60,-3.1415,3.1415);
      TH1D *h_SelectedMuonDetectorPhi_Showers = new TH1D("h_SelectedMuonDetectorPhi_Showers","",60,-3.1415,3.1415);
      TEfficiency* Efficiency_MuonDetectorPhi_Showers = new TEfficiency("MuonDetectorPhi_eff_Showers",";Muon Detector #theta;Selected/All",60,-3.1415,3.1415);

      TH1D *h_MuonBeamTheta_Showers = new TH1D("h_TrueMuonBeamTheta_Showers","",60,0,3.1415);
      TH1D *h_SelectedMuonBeamTheta_Showers = new TH1D("h_SelectedMuonBeamTheta_Showers","",60,0,3.1415);
      TEfficiency* Efficiency_MuonBeamTheta_Showers = new TEfficiency("MuonBeamTheta_eff_Showers",";Muon Beam #theta;Selected/All",60,0,3.1415);

      TH1D *h_MuonBeamPhi_Showers = new TH1D("h_TrueMuonBeamPhi_Showers","",60,-3.1415,3.1415);
      TH1D *h_SelectedMuonBeamPhi_Showers = new TH1D("h_SelectedMuonBeamPhi_Showers","",60,-3.1415,3.1415);
      TEfficiency* Efficiency_MuonBeamPhi_Showers = new TEfficiency("MuonBeamPhi_eff_Showers",";Muon Beam #theta;Selected/All",60,-3.1415,3.1415);

      TH1D *h_LambdaMomentum_Showers = new TH1D("h_TrueLambdaMomentum_Showers","",60,0.0,2.0);
      TH1D *h_SelectedLambdaMomentum_Showers = new TH1D("h_SelectedLambdaMomentum_Showers","",60,0.0,2.0);
      TEfficiency* Efficiency_LambdaMomentum_Showers = new TEfficiency("LambdaMomentum_eff_Showers",";True #Lambda Momentum (GeV/c);Selected/All",60,0.0,2.0);

      TH1D *h_DecayProtonMomentum_Showers = new TH1D("h_TrueDecayProtonMomentum_Showers","",60,0.3,1.5);
      TH1D *h_SelectedDecayProtonMomentum_Showers = new TH1D("h_SelectedDecayProtonMomentum_Showers","",60,0.3,1.5);
      TEfficiency* Efficiency_DecayProtonMomentum_Showers = new TEfficiency("DecayProtonMomentum_eff_Showers",";True Decay Proton Momentum (GeV/c);Selected/All",60,0.3,1.5);

      TH1D *h_DecayPionMomentum_Showers = new TH1D("h_TrueDecayPionMomentum_Showers","",60,0.1,0.8);
      TH1D *h_SelectedDecayPionMomentum_Showers = new TH1D("h_SelectedDecayPionMomentum_Showers","",60,0.1,0.8);
      TEfficiency* Efficiency_DecayPionMomentum_Showers = new TEfficiency("DecayPionMomentum_eff_Showers",";True Decay #pi^{-} Momentum (GeV/c);Selected/All",60,0.1,0.8);

      TH1D *h_OpeningAngle_Showers = new TH1D("h_OpeningAngle_Showers","",60,0,100);
      TH1D *h_SelectedOpeningAngle_Showers = new TH1D("h_SelectedOpeningAngle_Showers","",60,0,100);
      TEfficiency* Efficiency_OpeningAngle_Showers = new TEfficiency("OpeningAngle_eff_Showers",";True Opening Angle (deg);Selected/All",60,0,100);

      TH1D *h_LambdaRange_Showers = new TH1D("h_LambdaRange_Showers","",100,0,20.0);
      TH1D *h_SelectedLambdaRange_Showers = new TH1D("h_SelectedLambdaRange_Showers","",100,0,20.0);
      TEfficiency* Efficiency_LambdaRange_Showers = new TEfficiency("LambdaRange_eff_Showers",";True #Lambda Range (cm);Selected/All",100,0,20.0);

      TH1D *h_Showers = new TH1D("h_Showers","",1,0,1.0);
      TH1D *h_Selected_Showers = new TH1D("h_Selected_Showers","",1,0,1.0);
      TEfficiency* Efficiency_Showers = new TEfficiency("eff_Showers",";;Selected/All",1,0,1.0);

      // MuonID //

      TH1D *h_Q2_MuonID = new TH1D("h_Q2_MuonID","",60,0,3.0);
      TH1D *h_SelectedQ2_MuonID = new TH1D("h_SelectedQ2_MuonID","",60,0,3.0);
      TEfficiency* Efficiency_Q2_MuonID = new TEfficiency("Q2_eff_MuonID",";True Q^{2} (GeV^{2});Selected/All",60,0,3.0);

      TH1D *h_NuE_MuonID = new TH1D("h_TrueNuE_MuonID","",60,0,4.0);
      TH1D *h_SelectedNuE_MuonID = new TH1D("h_SelectedNuE_MuonID","",60,0,4.0);
      TEfficiency* Efficiency_NuE_MuonID = new TEfficiency("NuE_eff_MuonID",";True E_{#nu} (GeV);Selected/All",60,0,4.0);

      TH1D *h_MuonKE_MuonID = new TH1D("h_MuonKE_MuonID","",60,0,3.0);
      TH1D *h_SelectedMuonKE_MuonID = new TH1D("h_SelectedMuonKE_MuonID","",60,0,3.0);
      TEfficiency* Efficiency_MuonKE_MuonID = new TEfficiency("MuonKE_eff_MuonID",";True Muon KE (GeV);Selected/All",60,0,3.0);

      TH1D *h_MuonTrueTheta_MuonID = new TH1D("h_MuonTrueTheta_MuonID","",60,0,3.1415);
      TH1D *h_SelectedMuonTrueTheta_MuonID = new TH1D("h_SelectedMuonTrueTheta_MuonID","",60,0,3.1415);
      TEfficiency* Efficiency_MuonTrueTheta_MuonID = new TEfficiency("MuonTrueTheta_eff_MuonID",";Muon True #theta;Selected/All",60,0,3.1415);

      TH1D *h_MuonDetectorTheta_MuonID = new TH1D("h_TrueMuonDetectorTheta_MuonID","",60,0,3.1415);
      TH1D *h_SelectedMuonDetectorTheta_MuonID = new TH1D("h_SelectedMuonDetectorTheta_MuonID","",60,0,3.1415);
      TEfficiency* Efficiency_MuonDetectorTheta_MuonID = new TEfficiency("MuonDetectorTheta_eff",";Muon Detector #theta;Selected/All",60,0,3.1415);

      TH1D *h_MuonDetectorPhi_MuonID = new TH1D("h_TrueMuonDetectorPhi_MuonID","",60,-3.1415,3.1415);
      TH1D *h_SelectedMuonDetectorPhi_MuonID = new TH1D("h_SelectedMuonDetectorPhi_MuonID","",60,-3.1415,3.1415);
      TEfficiency* Efficiency_MuonDetectorPhi_MuonID = new TEfficiency("MuonDetectorPhi_eff_MuonID",";Muon Detector #theta;Selected/All",60,-3.1415,3.1415);

      TH1D *h_MuonBeamTheta_MuonID = new TH1D("h_TrueMuonBeamTheta_MuonID","",60,0,3.1415);
      TH1D *h_SelectedMuonBeamTheta_MuonID = new TH1D("h_SelectedMuonBeamTheta_MuonID","",60,0,3.1415);
      TEfficiency* Efficiency_MuonBeamTheta_MuonID = new TEfficiency("MuonBeamTheta_eff_MuonID",";Muon Beam #theta;Selected/All",60,0,3.1415);

      TH1D *h_MuonBeamPhi_MuonID = new TH1D("h_TrueMuonBeamPhi_MuonID","",60,-3.1415,3.1415);
      TH1D *h_SelectedMuonBeamPhi_MuonID = new TH1D("h_SelectedMuonBeamPhi_MuonID","",60,-3.1415,3.1415);
      TEfficiency* Efficiency_MuonBeamPhi_MuonID = new TEfficiency("MuonBeamPhi_eff_MuonID",";Muon Beam #theta;Selected/All",60,-3.1415,3.1415);

      TH1D *h_LambdaMomentum_MuonID = new TH1D("h_TrueLambdaMomentum_MuonID","",60,0.0,2.0);
      TH1D *h_SelectedLambdaMomentum_MuonID = new TH1D("h_SelectedLambdaMomentum_MuonID","",60,0.0,2.0);
      TEfficiency* Efficiency_LambdaMomentum_MuonID = new TEfficiency("LambdaMomentum_eff_MuonID",";True #Lambda Momentum (GeV/c);Selected/All",60,0.0,2.0);

      TH1D *h_DecayProtonMomentum_MuonID = new TH1D("h_TrueDecayProtonMomentum_MuonID","",60,0.3,1.5);
      TH1D *h_SelectedDecayProtonMomentum_MuonID = new TH1D("h_SelectedDecayProtonMomentum_MuonID","",60,0.3,1.5);
      TEfficiency* Efficiency_DecayProtonMomentum_MuonID = new TEfficiency("DecayProtonMomentum_eff_MuonID",";True Decay Proton Momentum (GeV/c);Selected/All",60,0.3,1.5);

      TH1D *h_DecayPionMomentum_MuonID = new TH1D("h_TrueDecayPionMomentum_MuonID","",60,0.1,0.8);
      TH1D *h_SelectedDecayPionMomentum_MuonID = new TH1D("h_SelectedDecayPionMomentum_MuonID","",60,0.1,0.8);
      TEfficiency* Efficiency_DecayPionMomentum_MuonID = new TEfficiency("DecayPionMomentum_eff_MuonID",";True Decay #pi^{-} Momentum (GeV/c);Selected/All",60,0.1,0.8);

      TH1D *h_OpeningAngle_MuonID = new TH1D("h_OpeningAngle_MuonID","",60,0,100);
      TH1D *h_SelectedOpeningAngle_MuonID = new TH1D("h_SelectedOpeningAngle_MuonID","",60,0,100);
      TEfficiency* Efficiency_OpeningAngle_MuonID = new TEfficiency("OpeningAngle_eff_MuonID",";True Opening Angle (deg);Selected/All",60,0,100);

      TH1D *h_LambdaRange_MuonID = new TH1D("h_LambdaRange_MuonID","",100,0,20.0);
      TH1D *h_SelectedLambdaRange_MuonID = new TH1D("h_SelectedLambdaRange_MuonID","",100,0,20.0);
      TEfficiency* Efficiency_LambdaRange_MuonID = new TEfficiency("LambdaRange_eff_MuonID",";True #Lambda Range (cm);Selected/All",100,0,20.0);

      TH1D *h_MuonID = new TH1D("h_MuonID","",1,0,1.0);
      TH1D *h_Selected_MuonID = new TH1D("h_Selected_MuonID","",1,0,1.0);
      TEfficiency* Efficiency_MuonID = new TEfficiency("eff_MuonID",";;Selected/All",1,0,1.0);

      // Selector BDT //

      TH1D *h_Q2_Selector = new TH1D("h_Q2_Selector","",60,0,3.0);
      TH1D *h_SelectedQ2_Selector = new TH1D("h_SelectedQ2_Selector","",60,0,3.0);
      TEfficiency* Efficiency_Q2_Selector = new TEfficiency("Q2_eff_Selector",";True Q^{2} (GeV^{2});Selected/All",60,0,3.0);

      TH1D *h_NuE_Selector = new TH1D("h_TrueNuE_Selector","",60,0,4.0);
      TH1D *h_SelectedNuE_Selector = new TH1D("h_SelectedNuE_Selector","",60,0,4.0);
      TEfficiency* Efficiency_NuE_Selector = new TEfficiency("NuE_eff_Selector",";True E_{#nu} (GeV);Selected/All",60,0,4.0);

      TH1D *h_MuonKE_Selector = new TH1D("h_MuonKE_Selector","",60,0,3.0);
      TH1D *h_SelectedMuonKE_Selector = new TH1D("h_SelectedMuonKE_Selector","",60,0,3.0);
      TEfficiency* Efficiency_MuonKE_Selector = new TEfficiency("MuonKE_eff_Selector",";True Muon KE (GeV);Selected/All",60,0,3.0);

      TH1D *h_MuonTrueTheta_Selector = new TH1D("h_MuonTrueTheta_Selector","",60,0,3.1415);
      TH1D *h_SelectedMuonTrueTheta_Selector = new TH1D("h_SelectedMuonTrueTheta_Selector","",60,0,3.1415);
      TEfficiency* Efficiency_MuonTrueTheta_Selector = new TEfficiency("MuonTrueTheta_eff_Selector",";Muon True #theta;Selected/All",60,0,3.1415);

      TH1D *h_MuonDetectorTheta_Selector = new TH1D("h_TrueMuonDetectorTheta_Selector","",60,0,3.1415);
      TH1D *h_SelectedMuonDetectorTheta_Selector = new TH1D("h_SelectedMuonDetectorTheta_Selector","",60,0,3.1415);
      TEfficiency* Efficiency_MuonDetectorTheta_Selector = new TEfficiency("MuonDetectorTheta_eff",";Muon Detector #theta;Selected/All",60,0,3.1415);

      TH1D *h_MuonDetectorPhi_Selector = new TH1D("h_TrueMuonDetectorPhi_Selector","",60,-3.1415,3.1415);
      TH1D *h_SelectedMuonDetectorPhi_Selector = new TH1D("h_SelectedMuonDetectorPhi_Selector","",60,-3.1415,3.1415);
      TEfficiency* Efficiency_MuonDetectorPhi_Selector = new TEfficiency("MuonDetectorPhi_eff_Selector",";Muon Detector #theta;Selected/All",60,-3.1415,3.1415);

      TH1D *h_MuonBeamTheta_Selector = new TH1D("h_TrueMuonBeamTheta_Selector","",60,0,3.1415);
      TH1D *h_SelectedMuonBeamTheta_Selector = new TH1D("h_SelectedMuonBeamTheta_Selector","",60,0,3.1415);
      TEfficiency* Efficiency_MuonBeamTheta_Selector = new TEfficiency("MuonBeamTheta_eff_Selector",";Muon Beam #theta;Selected/All",60,0,3.1415);

      TH1D *h_MuonBeamPhi_Selector = new TH1D("h_TrueMuonBeamPhi_Selector","",60,-3.1415,3.1415);
      TH1D *h_SelectedMuonBeamPhi_Selector = new TH1D("h_SelectedMuonBeamPhi_Selector","",60,-3.1415,3.1415);
      TEfficiency* Efficiency_MuonBeamPhi_Selector = new TEfficiency("MuonBeamPhi_eff_Selector",";Muon Beam #theta;Selected/All",60,-3.1415,3.1415);

      TH1D *h_LambdaMomentum_Selector = new TH1D("h_TrueLambdaMomentum_Selector","",60,0.0,2.0);
      TH1D *h_SelectedLambdaMomentum_Selector = new TH1D("h_SelectedLambdaMomentum_Selector","",60,0.0,2.0);
      TEfficiency* Efficiency_LambdaMomentum_Selector = new TEfficiency("LambdaMomentum_eff_Selector",";True #Lambda Momentum (GeV/c);Selected/All",60,0.0,2.0);

      TH1D *h_DecayProtonMomentum_Selector = new TH1D("h_TrueDecayProtonMomentum_Selector","",60,0.3,1.5);
      TH1D *h_SelectedDecayProtonMomentum_Selector = new TH1D("h_SelectedDecayProtonMomentum_Selector","",60,0.3,1.5);
      TEfficiency* Efficiency_DecayProtonMomentum_Selector = new TEfficiency("DecayProtonMomentum_eff_Selector",";True Decay Proton Momentum (GeV/c);Selected/All",60,0.3,1.5);

      TH1D *h_DecayPionMomentum_Selector = new TH1D("h_TrueDecayPionMomentum_Selector","",60,0.1,0.8);
      TH1D *h_SelectedDecayPionMomentum_Selector = new TH1D("h_SelectedDecayPionMomentum_Selector","",60,0.1,0.8);
      TEfficiency* Efficiency_DecayPionMomentum_Selector = new TEfficiency("DecayPionMomentum_eff_Selector",";True Decay #pi^{-} Momentum (GeV/c);Selected/All",60,0.1,0.8);

      TH1D *h_OpeningAngle_Selector = new TH1D("h_OpeningAngle_Selector","",60,0,100);
      TH1D *h_SelectedOpeningAngle_Selector = new TH1D("h_SelectedOpeningAngle_Selector","",60,0,100);
      TEfficiency* Efficiency_OpeningAngle_Selector = new TEfficiency("OpeningAngle_eff_Selector",";True Opening Angle (deg);Selected/All",60,0,100);

      TH1D *h_LambdaRange_Selector = new TH1D("h_LambdaRange_Selector","",100,0,20.0);
      TH1D *h_SelectedLambdaRange_Selector = new TH1D("h_SelectedLambdaRange_Selector","",100,0,20.0);
      TEfficiency* Efficiency_LambdaRange_Selector = new TEfficiency("LambdaRange_eff_Selector",";True #Lambda Range (cm);Selected/All",100,0,20.0);

      TH1D *h_Selector = new TH1D("h_Selector","",1,0,1.0);
      TH1D *h_Selected_Selector = new TH1D("h_Selected_Selector","",1,0,1.0);
      TEfficiency* Efficiency_Selector = new TEfficiency("eff_Selector",";;Selected/All",1,0,1.0);

      // Connectedness //

      TH1D *h_Q2_CT = new TH1D("h_Q2_CT","",60,0,3.0);
      TH1D *h_SelectedQ2_CT = new TH1D("h_SelectedQ2_CT","",60,0,3.0);
      TEfficiency* Efficiency_Q2_CT = new TEfficiency("Q2_eff_CT",";True Q^{2} (GeV^{2});Selected/All",60,0,3.0);

      TH1D *h_NuE_CT = new TH1D("h_TrueNuE_CT","",60,0,4.0);
      TH1D *h_SelectedNuE_CT = new TH1D("h_SelectedNuE_CT","",60,0,4.0);
      TEfficiency* Efficiency_NuE_CT = new TEfficiency("NuE_eff_CT",";True E_{#nu} (GeV);Selected/All",60,0,4.0);

      TH1D *h_MuonKE_CT = new TH1D("h_MuonKE_CT","",60,0,3.0);
      TH1D *h_SelectedMuonKE_CT = new TH1D("h_SelectedMuonKE_CT","",60,0,3.0);
      TEfficiency* Efficiency_MuonKE_CT = new TEfficiency("MuonKE_eff_CT",";True Muon KE (GeV);Selected/All",60,0,3.0);

      TH1D *h_MuonTrueTheta_CT = new TH1D("h_MuonTrueTheta_CT","",60,0,3.1415);
      TH1D *h_SelectedMuonTrueTheta_CT = new TH1D("h_SelectedMuonTrueTheta_CT","",60,0,3.1415);
      TEfficiency* Efficiency_MuonTrueTheta_CT = new TEfficiency("MuonTrueTheta_eff_CT",";Muon True #theta;Selected/All",60,0,3.1415);

      TH1D *h_MuonDetectorTheta_CT = new TH1D("h_TrueMuonDetectorTheta_CT","",60,0,3.1415);
      TH1D *h_SelectedMuonDetectorTheta_CT = new TH1D("h_SelectedMuonDetectorTheta_CT","",60,0,3.1415);
      TEfficiency* Efficiency_MuonDetectorTheta_CT = new TEfficiency("MuonDetectorTheta_eff",";Muon Detector #theta;Selected/All",60,0,3.1415);

      TH1D *h_MuonDetectorPhi_CT = new TH1D("h_TrueMuonDetectorPhi_CT","",60,-3.1415,3.1415);
      TH1D *h_SelectedMuonDetectorPhi_CT = new TH1D("h_SelectedMuonDetectorPhi_CT","",60,-3.1415,3.1415);
      TEfficiency* Efficiency_MuonDetectorPhi_CT = new TEfficiency("MuonDetectorPhi_eff_CT",";Muon Detector #theta;Selected/All",60,-3.1415,3.1415);

      TH1D *h_MuonBeamTheta_CT = new TH1D("h_TrueMuonBeamTheta_CT","",60,0,3.1415);
      TH1D *h_SelectedMuonBeamTheta_CT = new TH1D("h_SelectedMuonBeamTheta_CT","",60,0,3.1415);
      TEfficiency* Efficiency_MuonBeamTheta_CT = new TEfficiency("MuonBeamTheta_eff_CT",";Muon Beam #theta;Selected/All",60,0,3.1415);

      TH1D *h_MuonBeamPhi_CT = new TH1D("h_TrueMuonBeamPhi_CT","",60,-3.1415,3.1415);
      TH1D *h_SelectedMuonBeamPhi_CT = new TH1D("h_SelectedMuonBeamPhi_CT","",60,-3.1415,3.1415);
      TEfficiency* Efficiency_MuonBeamPhi_CT = new TEfficiency("MuonBeamPhi_eff_CT",";Muon Beam #theta;Selected/All",60,-3.1415,3.1415);

      TH1D *h_LambdaMomentum_CT = new TH1D("h_TrueLambdaMomentum_CT","",60,0.0,2.0);
      TH1D *h_SelectedLambdaMomentum_CT = new TH1D("h_SelectedLambdaMomentum_CT","",60,0.0,2.0);
      TEfficiency* Efficiency_LambdaMomentum_CT = new TEfficiency("LambdaMomentum_eff_CT",";True #Lambda Momentum (GeV/c);Selected/All",60,0.0,2.0);

      TH1D *h_DecayProtonMomentum_CT = new TH1D("h_TrueDecayProtonMomentum_CT","",60,0.3,1.5);
      TH1D *h_SelectedDecayProtonMomentum_CT = new TH1D("h_SelectedDecayProtonMomentum_CT","",60,0.3,1.5);
      TEfficiency* Efficiency_DecayProtonMomentum_CT = new TEfficiency("DecayProtonMomentum_eff_CT",";True Decay Proton Momentum (GeV/c);Selected/All",60,0.3,1.5);

      TH1D *h_DecayPionMomentum_CT = new TH1D("h_TrueDecayPionMomentum_CT","",60,0.1,0.8);
      TH1D *h_SelectedDecayPionMomentum_CT = new TH1D("h_SelectedDecayPionMomentum_CT","",60,0.1,0.8);
      TEfficiency* Efficiency_DecayPionMomentum_CT = new TEfficiency("DecayPionMomentum_eff_CT",";True Decay #pi^{-} Momentum (GeV/c);Selected/All",60,0.1,0.8);

      TH1D *h_OpeningAngle_CT = new TH1D("h_OpeningAngle_CT","",60,0,100);
      TH1D *h_SelectedOpeningAngle_CT = new TH1D("h_SelectedOpeningAngle_CT","",60,0,100);
      TEfficiency* Efficiency_OpeningAngle_CT = new TEfficiency("OpeningAngle_eff_CT",";True Opening Angle (deg);Selected/All",60,0,100);

      TH1D *h_LambdaRange_CT = new TH1D("h_LambdaRange_CT","",100,0,20.0);
      TH1D *h_SelectedLambdaRange_CT = new TH1D("h_SelectedLambdaRange_CT","",100,0,20.0);
      TEfficiency* Efficiency_LambdaRange_CT = new TEfficiency("LambdaRange_eff_CT",";True #Lambda Range (cm);Selected/All",100,0,20.0);

      TH1D *h_CT = new TH1D("h_CT","",1,0,1.0);
      TH1D *h_Selected_CT = new TH1D("h_Selected_CT","",1,0,1.0);
      TEfficiency* Efficiency_CT = new TEfficiency("eff_CT",";;Selected/All",1,0,1.0);

      // Invariant mass cut //

      TH1D *h_Q2_WCut = new TH1D("h_Q2_WCut","",60,0,3.0);
      TH1D *h_SelectedQ2_WCut = new TH1D("h_SelectedQ2_WCut","",60,0,3.0);
      TEfficiency* Efficiency_Q2_WCut = new TEfficiency("Q2_eff_WCut",";True Q^{2} (GeV^{2});Selected/All",60,0,3.0);

      TH1D *h_NuE_WCut = new TH1D("h_TrueNuE_WCut","",60,0,4.0);
      TH1D *h_SelectedNuE_WCut = new TH1D("h_SelectedNuE_WCut","",60,0,4.0);
      TEfficiency* Efficiency_NuE_WCut = new TEfficiency("NuE_eff_WCut",";True E_{#nu} (GeV);Selected/All",60,0,4.0);

      TH1D *h_MuonKE_WCut = new TH1D("h_MuonKE_WCut","",60,0,3.0);
      TH1D *h_SelectedMuonKE_WCut = new TH1D("h_SelectedMuonKE_WCut","",60,0,3.0);
      TEfficiency* Efficiency_MuonKE_WCut = new TEfficiency("MuonKE_eff_WCut",";True Muon KE (GeV);Selected/All",60,0,3.0);

      TH1D *h_MuonTrueTheta_WCut = new TH1D("h_MuonTrueTheta_WCut","",60,0,3.1415);
      TH1D *h_SelectedMuonTrueTheta_WCut = new TH1D("h_SelectedMuonTrueTheta_WCut","",60,0,3.1415);
      TEfficiency* Efficiency_MuonTrueTheta_WCut = new TEfficiency("MuonTrueTheta_eff_WCut",";Muon True #theta;Selected/All",60,0,3.1415);

      TH1D *h_MuonDetectorTheta_WCut = new TH1D("h_TrueMuonDetectorTheta_WCut","",60,0,3.1415);
      TH1D *h_SelectedMuonDetectorTheta_WCut = new TH1D("h_SelectedMuonDetectorTheta_WCut","",60,0,3.1415);
      TEfficiency* Efficiency_MuonDetectorTheta_WCut = new TEfficiency("MuonDetectorTheta_eff",";Muon Detector #theta;Selected/All",60,0,3.1415);

      TH1D *h_MuonDetectorPhi_WCut = new TH1D("h_TrueMuonDetectorPhi_WCut","",60,-3.1415,3.1415);
      TH1D *h_SelectedMuonDetectorPhi_WCut = new TH1D("h_SelectedMuonDetectorPhi_WCut","",60,-3.1415,3.1415);
      TEfficiency* Efficiency_MuonDetectorPhi_WCut = new TEfficiency("MuonDetectorPhi_eff_WCut",";Muon Detector #theta;Selected/All",60,-3.1415,3.1415);

      TH1D *h_MuonBeamTheta_WCut = new TH1D("h_TrueMuonBeamTheta_WCut","",60,0,3.1415);
      TH1D *h_SelectedMuonBeamTheta_WCut = new TH1D("h_SelectedMuonBeamTheta_WCut","",60,0,3.1415);
      TEfficiency* Efficiency_MuonBeamTheta_WCut = new TEfficiency("MuonBeamTheta_eff_WCut",";Muon Beam #theta;Selected/All",60,0,3.1415);

      TH1D *h_MuonBeamPhi_WCut = new TH1D("h_TrueMuonBeamPhi_WCut","",60,-3.1415,3.1415);
      TH1D *h_SelectedMuonBeamPhi_WCut = new TH1D("h_SelectedMuonBeamPhi_WCut","",60,-3.1415,3.1415);
      TEfficiency* Efficiency_MuonBeamPhi_WCut = new TEfficiency("MuonBeamPhi_eff_WCut",";Muon Beam #theta;Selected/All",60,-3.1415,3.1415);

      TH1D *h_LambdaMomentum_WCut = new TH1D("h_TrueLambdaMomentum_WCut","",60,0.0,2.0);
      TH1D *h_SelectedLambdaMomentum_WCut = new TH1D("h_SelectedLambdaMomentum_WCut","",60,0.0,2.0);
      TEfficiency* Efficiency_LambdaMomentum_WCut = new TEfficiency("LambdaMomentum_eff_WCut",";True #Lambda Momentum (GeV/c);Selected/All",60,0.0,2.0);

      TH1D *h_DecayProtonMomentum_WCut = new TH1D("h_TrueDecayProtonMomentum_WCut","",60,0.3,1.5);
      TH1D *h_SelectedDecayProtonMomentum_WCut = new TH1D("h_SelectedDecayProtonMomentum_WCut","",60,0.3,1.5);
      TEfficiency* Efficiency_DecayProtonMomentum_WCut = new TEfficiency("DecayProtonMomentum_eff_WCut",";True Decay Proton Momentum (GeV/c);Selected/All",60,0.3,1.5);

      TH1D *h_DecayPionMomentum_WCut = new TH1D("h_TrueDecayPionMomentum_WCut","",60,0.1,0.8);
      TH1D *h_SelectedDecayPionMomentum_WCut = new TH1D("h_SelectedDecayPionMomentum_WCut","",60,0.1,0.8);
      TEfficiency* Efficiency_DecayPionMomentum_WCut = new TEfficiency("DecayPionMomentum_eff_WCut",";True Decay #pi^{-} Momentum (GeV/c);Selected/All",60,0.1,0.8);

      TH1D *h_OpeningAngle_WCut = new TH1D("h_OpeningAngle_WCut","",60,0,100);
      TH1D *h_SelectedOpeningAngle_WCut = new TH1D("h_SelectedOpeningAngle_WCut","",60,0,100);
      TEfficiency* Efficiency_OpeningAngle_WCut = new TEfficiency("OpeningAngle_eff_WCut",";True Opening Angle (deg);Selected/All",60,0,100);

      TH1D *h_LambdaRange_WCut = new TH1D("h_LambdaRange_WCut","",100,0,20.0);
      TH1D *h_SelectedLambdaRange_WCut = new TH1D("h_SelectedLambdaRange_WCut","",100,0,20.0);
      TEfficiency* Efficiency_LambdaRange_WCut = new TEfficiency("LambdaRange_eff_WCut",";True #Lambda Range (cm);Selected/All",100,0,20.0);

      TH1D *h_WCut = new TH1D("h_WCut","",1,0,1.0);
      TH1D *h_Selected_WCut = new TH1D("h_Selected_WCut","",1,0,1.0);
      TEfficiency* Efficiency_WCut = new TEfficiency("eff_WCut",";;Selected/All",1,0,1.0);

      // Angular deviation cut //

      TH1D *h_Q2_AngleCut = new TH1D("h_Q2_AngleCut","",60,0,3.0);
      TH1D *h_SelectedQ2_AngleCut = new TH1D("h_SelectedQ2_AngleCut","",60,0,3.0);
      TEfficiency* Efficiency_Q2_AngleCut = new TEfficiency("Q2_eff_AngleCut",";True Q^{2} (GeV^{2});Selected/All",60,0,3.0);

      TH1D *h_NuE_AngleCut = new TH1D("h_TrueNuE_AngleCut","",60,0,4.0);
      TH1D *h_SelectedNuE_AngleCut = new TH1D("h_SelectedNuE_AngleCut","",60,0,4.0);
      TEfficiency* Efficiency_NuE_AngleCut = new TEfficiency("NuE_eff_AngleCut",";True E_{#nu} (GeV);Selected/All",60,0,4.0);

      TH1D *h_MuonKE_AngleCut = new TH1D("h_MuonKE_AngleCut","",60,0,3.0);
      TH1D *h_SelectedMuonKE_AngleCut = new TH1D("h_SelectedMuonKE_AngleCut","",60,0,3.0);
      TEfficiency* Efficiency_MuonKE_AngleCut = new TEfficiency("MuonKE_eff_AngleCut",";True Muon KE (GeV);Selected/All",60,0,3.0);

      TH1D *h_MuonTrueTheta_AngleCut = new TH1D("h_MuonTrueTheta_AngleCut","",60,0,3.1415);
      TH1D *h_SelectedMuonTrueTheta_AngleCut = new TH1D("h_SelectedMuonTrueTheta_AngleCut","",60,0,3.1415);
      TEfficiency* Efficiency_MuonTrueTheta_AngleCut = new TEfficiency("MuonTrueTheta_eff_AngleCut",";Muon True #theta;Selected/All",60,0,3.1415);

      TH1D *h_MuonDetectorTheta_AngleCut = new TH1D("h_TrueMuonDetectorTheta_AngleCut","",60,0,3.1415);
      TH1D *h_SelectedMuonDetectorTheta_AngleCut = new TH1D("h_SelectedMuonDetectorTheta_AngleCut","",60,0,3.1415);
      TEfficiency* Efficiency_MuonDetectorTheta_AngleCut = new TEfficiency("MuonDetectorTheta_eff",";Muon Detector #theta;Selected/All",60,0,3.1415);

      TH1D *h_MuonDetectorPhi_AngleCut = new TH1D("h_TrueMuonDetectorPhi_AngleCut","",60,-3.1415,3.1415);
      TH1D *h_SelectedMuonDetectorPhi_AngleCut = new TH1D("h_SelectedMuonDetectorPhi_AngleCut","",60,-3.1415,3.1415);
      TEfficiency* Efficiency_MuonDetectorPhi_AngleCut = new TEfficiency("MuonDetectorPhi_eff_AngleCut",";Muon Detector #theta;Selected/All",60,-3.1415,3.1415);

      TH1D *h_MuonBeamTheta_AngleCut = new TH1D("h_TrueMuonBeamTheta_AngleCut","",60,0,3.1415);
      TH1D *h_SelectedMuonBeamTheta_AngleCut = new TH1D("h_SelectedMuonBeamTheta_AngleCut","",60,0,3.1415);
      TEfficiency* Efficiency_MuonBeamTheta_AngleCut = new TEfficiency("MuonBeamTheta_eff_AngleCut",";Muon Beam #theta;Selected/All",60,0,3.1415);

      TH1D *h_MuonBeamPhi_AngleCut = new TH1D("h_TrueMuonBeamPhi_AngleCut","",60,-3.1415,3.1415);
      TH1D *h_SelectedMuonBeamPhi_AngleCut = new TH1D("h_SelectedMuonBeamPhi_AngleCut","",60,-3.1415,3.1415);
      TEfficiency* Efficiency_MuonBeamPhi_AngleCut = new TEfficiency("MuonBeamPhi_eff_AngleCut",";Muon Beam #theta;Selected/All",60,-3.1415,3.1415);

      TH1D *h_LambdaMomentum_AngleCut = new TH1D("h_TrueLambdaMomentum_AngleCut","",60,0.0,2.0);
      TH1D *h_SelectedLambdaMomentum_AngleCut = new TH1D("h_SelectedLambdaMomentum_AngleCut","",60,0.0,2.0);
      TEfficiency* Efficiency_LambdaMomentum_AngleCut = new TEfficiency("LambdaMomentum_eff_AngleCut",";True #Lambda Momentum (GeV/c);Selected/All",60,0.0,2.0);

      TH1D *h_DecayProtonMomentum_AngleCut = new TH1D("h_TrueDecayProtonMomentum_AngleCut","",60,0.3,1.5);
      TH1D *h_SelectedDecayProtonMomentum_AngleCut = new TH1D("h_SelectedDecayProtonMomentum_AngleCut","",60,0.3,1.5);
      TEfficiency* Efficiency_DecayProtonMomentum_AngleCut = new TEfficiency("DecayProtonMomentum_eff_AngleCut",";True Decay Proton Momentum (GeV/c);Selected/All",60,0.3,1.5);

      TH1D *h_DecayPionMomentum_AngleCut = new TH1D("h_TrueDecayPionMomentum_AngleCut","",60,0.1,0.8);
      TH1D *h_SelectedDecayPionMomentum_AngleCut = new TH1D("h_SelectedDecayPionMomentum_AngleCut","",60,0.1,0.8);
      TEfficiency* Efficiency_DecayPionMomentum_AngleCut = new TEfficiency("DecayPionMomentum_eff_AngleCut",";True Decay #pi^{-} Momentum (GeV/c);Selected/All",60,0.1,0.8);

      TH1D *h_OpeningAngle_AngleCut = new TH1D("h_OpeningAngle_AngleCut","",60,0,100);
      TH1D *h_SelectedOpeningAngle_AngleCut = new TH1D("h_SelectedOpeningAngle_AngleCut","",60,0,100);
      TEfficiency* Efficiency_OpeningAngle_AngleCut = new TEfficiency("OpeningAngle_eff_AngleCut",";True Opening Angle (deg);Selected/All",60,0,100);

      TH1D *h_LambdaRange_AngleCut = new TH1D("h_LambdaRange_AngleCut","",100,0,20.0);
      TH1D *h_SelectedLambdaRange_AngleCut = new TH1D("h_SelectedLambdaRange_AngleCut","",100,0,20.0);
      TEfficiency* Efficiency_LambdaRange_AngleCut = new TEfficiency("LambdaRange_eff_AngleCut",";True #Lambda Range (cm);Selected/All",100,0,20.0);

      TH1D *h_AngleCut = new TH1D("h_AngleCut","",1,0,1.0);
      TH1D *h_Selected_AngleCut = new TH1D("h_Selected_AngleCut","",1,0,1.0);
      TEfficiency* Efficiency_AngleCut = new TEfficiency("eff_AngleCut",";;Selected/All",1,0,1.0);

      /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

      E.SetFile("run1_FHC/analysisOutputFHC_Overlay_GENIE_Hyperon_All.root");
      M.AddSample("Hyperon","Hyperon",E.GetPOT());         

      for(int i=0;i<E.GetNEvents();i++){
        
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
         if(passed_MuonID) passed_Selector = M.ChooseProtonPionCandidates(e); 
         if(passed_Selector) passed_CT = M.ConnectednessTest(e);
         if(passed_CT) passed_WCut = M.WCut(e);
         if(passed_WCut) passed_AngleCut = M.AngleCut(e);

         passed_All = passed_AngleCut;

         // Entire Selection         
         h_Q2_All->Fill(Q2,e.Weight);
         Efficiency_Q2_All->FillWeighted(passed_All,e.Weight,Q2);
         if(Q2 > 0 && passed_All) h_SelectedQ2_All->Fill(Q2,e.Weight);

         h_NuE_All->Fill(NuE,e.Weight); 
         Efficiency_NuE_All->FillWeighted(passed_All,e.Weight,NuE);
         if(NuE > 0 && passed_All)  h_SelectedNuE_All->Fill(NuE,e.Weight);

         h_MuonKE_All->Fill(MuonKE,e.Weight); 
         Efficiency_MuonKE_All->FillWeighted(passed_All,e.Weight,MuonKE);
         if(MuonKE > 0 && passed_All)  h_SelectedMuonKE_All->Fill(MuonKE,e.Weight);

         h_MuonTrueTheta_All->Fill(MuonTrueTheta,e.Weight); 
         Efficiency_MuonTrueTheta_All->FillWeighted(passed_All,e.Weight,MuonTrueTheta);
         if(passed_All)  h_SelectedMuonTrueTheta_All->Fill(MuonTrueTheta,e.Weight);

         h_MuonDetectorTheta_All->Fill(MuonDetectorTheta,e.Weight); 
         Efficiency_MuonDetectorTheta_All->FillWeighted(passed_All,e.Weight,MuonDetectorTheta);
         if(passed_All)  h_SelectedMuonDetectorTheta_All->Fill(MuonDetectorTheta,e.Weight);

         h_MuonDetectorPhi_All->Fill(MuonDetectorPhi,e.Weight); 
         Efficiency_MuonDetectorPhi_All->FillWeighted(passed_All,e.Weight,MuonDetectorPhi);
         if(passed_All)  h_SelectedMuonDetectorPhi_All->Fill(MuonDetectorPhi,e.Weight);

         h_MuonBeamTheta_All->Fill(MuonBeamTheta,e.Weight); 
         Efficiency_MuonBeamTheta_All->FillWeighted(passed_All,e.Weight,MuonBeamTheta);
         if(passed_All)  h_SelectedMuonBeamTheta_All->Fill(MuonBeamTheta,e.Weight);

         h_MuonBeamPhi_All->Fill(MuonBeamPhi,e.Weight); 
         Efficiency_MuonBeamPhi_All->FillWeighted(passed_All,e.Weight,MuonBeamPhi);
         if(passed_All)  h_SelectedMuonBeamPhi_All->Fill(MuonBeamPhi,e.Weight);

         h_LambdaMomentum_All->Fill(LambdaMomentum,e.Weight); 
         Efficiency_LambdaMomentum_All->FillWeighted(passed_All,e.Weight,LambdaMomentum);
         if(passed_All)  h_SelectedLambdaMomentum_All->Fill(LambdaMomentum,e.Weight);

         h_DecayProtonMomentum_All->Fill(DecayProtonMomentum,e.Weight); 
         Efficiency_DecayProtonMomentum_All->FillWeighted(passed_All,e.Weight,DecayProtonMomentum);
         if(passed_All)  h_SelectedDecayProtonMomentum_All->Fill(DecayProtonMomentum,e.Weight);

         h_DecayPionMomentum_All->Fill(DecayPionMomentum,e.Weight); 
         Efficiency_DecayPionMomentum_All->FillWeighted(passed_All,e.Weight,DecayPionMomentum);
         if(passed_All)  h_SelectedDecayPionMomentum_All->Fill(DecayPionMomentum,e.Weight);

         h_OpeningAngle_All->Fill(OpeningAngle,e.Weight);
         Efficiency_OpeningAngle_All->FillWeighted(passed_All,e.Weight,OpeningAngle);
         if(OpeningAngle > 0 && passed_All) h_SelectedOpeningAngle_All->Fill(OpeningAngle,e.Weight);

         h_LambdaRange_All->Fill(LambdaRange,e.Weight);
         Efficiency_LambdaRange_All->FillWeighted(passed_All,e.Weight,LambdaRange);
         if(LambdaRange > 0 && passed_All) h_SelectedLambdaRange_All->Fill(LambdaRange,e.Weight);

         h_All->Fill(0.5,e.Weight);
         Efficiency_All->FillWeighted(passed_All,e.Weight,0.5);
         if(passed_All) h_Selected_All->Fill(0.5,e.Weight);

         // Fiducial Volume Cut
         h_Q2_FV->Fill(Q2,e.Weight);
         Efficiency_Q2_FV->FillWeighted(passed_FV,e.Weight,Q2);
         if(Q2 > 0 && passed_FV) h_SelectedQ2_FV->Fill(Q2,e.Weight);

         h_NuE_FV->Fill(NuE,e.Weight); 
         Efficiency_NuE_FV->FillWeighted(passed_FV,e.Weight,NuE);
         if(NuE > 0 && passed_FV)  h_SelectedNuE_FV->Fill(NuE,e.Weight);

         h_MuonKE_FV->Fill(MuonKE,e.Weight); 
         Efficiency_MuonKE_FV->FillWeighted(passed_FV,e.Weight,MuonKE);
         if(MuonKE > 0 && passed_FV)  h_SelectedMuonKE_FV->Fill(MuonKE,e.Weight);

         h_MuonTrueTheta_FV->Fill(MuonTrueTheta,e.Weight); 
         Efficiency_MuonTrueTheta_FV->FillWeighted(passed_FV,e.Weight,MuonTrueTheta);
         if(passed_FV)  h_SelectedMuonTrueTheta_FV->Fill(MuonTrueTheta,e.Weight);

         h_MuonDetectorTheta_FV->Fill(MuonDetectorTheta,e.Weight); 
         Efficiency_MuonDetectorTheta_FV->FillWeighted(passed_FV,e.Weight,MuonDetectorTheta);
         if(passed_FV)  h_SelectedMuonDetectorTheta_FV->Fill(MuonDetectorTheta,e.Weight);

         h_MuonDetectorPhi_FV->Fill(MuonDetectorPhi,e.Weight); 
         Efficiency_MuonDetectorPhi_FV->FillWeighted(passed_FV,e.Weight,MuonDetectorPhi);
         if(passed_FV)  h_SelectedMuonDetectorPhi_FV->Fill(MuonDetectorPhi,e.Weight);

         h_MuonBeamTheta_FV->Fill(MuonBeamTheta,e.Weight); 
         Efficiency_MuonBeamTheta_FV->FillWeighted(passed_FV,e.Weight,MuonBeamTheta);
         if(passed_FV)  h_SelectedMuonBeamTheta_FV->Fill(MuonBeamTheta,e.Weight);

         h_MuonBeamPhi_FV->Fill(MuonBeamPhi,e.Weight); 
         Efficiency_MuonBeamPhi_FV->FillWeighted(passed_FV,e.Weight,MuonBeamPhi);
         if(passed_FV)  h_SelectedMuonBeamPhi_FV->Fill(MuonBeamPhi,e.Weight);

         h_LambdaMomentum_FV->Fill(LambdaMomentum,e.Weight); 
         Efficiency_LambdaMomentum_FV->FillWeighted(passed_FV,e.Weight,LambdaMomentum);
         if(passed_FV)  h_SelectedLambdaMomentum_FV->Fill(LambdaMomentum,e.Weight);

         h_DecayProtonMomentum_FV->Fill(DecayProtonMomentum,e.Weight); 
         Efficiency_DecayProtonMomentum_FV->FillWeighted(passed_FV,e.Weight,DecayProtonMomentum);
         if(passed_FV)  h_SelectedDecayProtonMomentum_FV->Fill(DecayProtonMomentum,e.Weight);

         h_DecayPionMomentum_FV->Fill(DecayPionMomentum,e.Weight); 
         Efficiency_DecayPionMomentum_FV->FillWeighted(passed_FV,e.Weight,DecayPionMomentum);
         if(passed_FV)  h_SelectedDecayPionMomentum_FV->Fill(DecayPionMomentum,e.Weight);

         h_OpeningAngle_FV->Fill(OpeningAngle,e.Weight);
         Efficiency_OpeningAngle_FV->FillWeighted(passed_FV,e.Weight,OpeningAngle);
         if(OpeningAngle > 0 && passed_FV) h_SelectedOpeningAngle_FV->Fill(OpeningAngle,e.Weight);

         h_LambdaRange_FV->Fill(LambdaRange,e.Weight);
         Efficiency_LambdaRange_FV->FillWeighted(passed_FV,e.Weight,LambdaRange);
         if(LambdaRange > 0 && passed_FV) h_SelectedLambdaRange_FV->Fill(LambdaRange,e.Weight);

         h_FV->Fill(0.5,e.Weight);
         Efficiency_FV->FillWeighted(passed_FV,e.Weight,0.5);
         if(passed_FV) h_Selected_FV->Fill(0.5,e.Weight);

         // Track Cut
         h_Q2_Tracks->Fill(Q2,e.Weight);
         Efficiency_Q2_Tracks->FillWeighted(passed_Tracks,e.Weight,Q2);
         if(Q2 > 0 && passed_Tracks) h_SelectedQ2_Tracks->Fill(Q2,e.Weight);

         h_NuE_Tracks->Fill(NuE,e.Weight); 
         Efficiency_NuE_Tracks->FillWeighted(passed_Tracks,e.Weight,NuE);
         if(NuE > 0 && passed_Tracks)  h_SelectedNuE_Tracks->Fill(NuE,e.Weight);

         h_MuonKE_Tracks->Fill(MuonKE,e.Weight); 
         Efficiency_MuonKE_Tracks->FillWeighted(passed_Tracks,e.Weight,MuonKE);
         if(MuonKE > 0 && passed_Tracks)  h_SelectedMuonKE_Tracks->Fill(MuonKE,e.Weight);

         h_MuonTrueTheta_Tracks->Fill(MuonTrueTheta,e.Weight); 
         Efficiency_MuonTrueTheta_Tracks->FillWeighted(passed_Tracks,e.Weight,MuonTrueTheta);
         if(passed_Tracks)  h_SelectedMuonTrueTheta_Tracks->Fill(MuonTrueTheta,e.Weight);

         h_MuonDetectorTheta_Tracks->Fill(MuonDetectorTheta,e.Weight); 
         Efficiency_MuonDetectorTheta_Tracks->FillWeighted(passed_Tracks,e.Weight,MuonDetectorTheta);
         if(passed_Tracks)  h_SelectedMuonDetectorTheta_Tracks->Fill(MuonDetectorTheta,e.Weight);

         h_MuonDetectorPhi_Tracks->Fill(MuonDetectorPhi,e.Weight); 
         Efficiency_MuonDetectorPhi_Tracks->FillWeighted(passed_Tracks,e.Weight,MuonDetectorPhi);
         if(passed_Tracks)  h_SelectedMuonDetectorPhi_Tracks->Fill(MuonDetectorPhi,e.Weight);

         h_MuonBeamTheta_Tracks->Fill(MuonBeamTheta,e.Weight); 
         Efficiency_MuonBeamTheta_Tracks->FillWeighted(passed_Tracks,e.Weight,MuonBeamTheta);
         if(passed_Tracks)  h_SelectedMuonBeamTheta_Tracks->Fill(MuonBeamTheta,e.Weight);

         h_MuonBeamPhi_Tracks->Fill(MuonBeamPhi,e.Weight); 
         Efficiency_MuonBeamPhi_Tracks->FillWeighted(passed_Tracks,e.Weight,MuonBeamPhi);
         if(passed_Tracks)  h_SelectedMuonBeamPhi_Tracks->Fill(MuonBeamPhi,e.Weight);

         h_LambdaMomentum_Tracks->Fill(LambdaMomentum,e.Weight); 
         Efficiency_LambdaMomentum_Tracks->FillWeighted(passed_Tracks,e.Weight,LambdaMomentum);
         if(passed_Tracks)  h_SelectedLambdaMomentum_Tracks->Fill(LambdaMomentum,e.Weight);

         h_DecayProtonMomentum_Tracks->Fill(DecayProtonMomentum,e.Weight); 
         Efficiency_DecayProtonMomentum_Tracks->FillWeighted(passed_Tracks,e.Weight,DecayProtonMomentum);
         if(passed_Tracks)  h_SelectedDecayProtonMomentum_Tracks->Fill(DecayProtonMomentum,e.Weight);

         h_DecayPionMomentum_Tracks->Fill(DecayPionMomentum,e.Weight); 
         Efficiency_DecayPionMomentum_Tracks->FillWeighted(passed_Tracks,e.Weight,DecayPionMomentum);
         if(passed_Tracks)  h_SelectedDecayPionMomentum_Tracks->Fill(DecayPionMomentum,e.Weight);

         h_OpeningAngle_Tracks->Fill(OpeningAngle,e.Weight);
         Efficiency_OpeningAngle_Tracks->FillWeighted(passed_Tracks,e.Weight,OpeningAngle);
         if(OpeningAngle > 0 && passed_Tracks) h_SelectedOpeningAngle_Tracks->Fill(OpeningAngle,e.Weight);

         h_LambdaRange_Tracks->Fill(LambdaRange,e.Weight);
         Efficiency_LambdaRange_Tracks->FillWeighted(passed_Tracks,e.Weight,LambdaRange);
         if(LambdaRange > 0 && passed_Tracks) h_SelectedLambdaRange_Tracks->Fill(LambdaRange,e.Weight);

         h_Tracks->Fill(0.5,e.Weight);
         Efficiency_Tracks->FillWeighted(passed_Tracks,e.Weight,0.5);
         if(passed_Tracks) h_Selected_Tracks->Fill(0.5,e.Weight);

         // Shower Cut
         h_Q2_Showers->Fill(Q2,e.Weight);
         Efficiency_Q2_Showers->FillWeighted(passed_Showers,e.Weight,Q2);
         if(Q2 > 0 && passed_Showers) h_SelectedQ2_Showers->Fill(Q2,e.Weight);

         h_NuE_Showers->Fill(NuE,e.Weight); 
         Efficiency_NuE_Showers->FillWeighted(passed_Showers,e.Weight,NuE);
         if(NuE > 0 && passed_Showers)  h_SelectedNuE_Showers->Fill(NuE,e.Weight);

         h_MuonKE_Showers->Fill(MuonKE,e.Weight); 
         Efficiency_MuonKE_Showers->FillWeighted(passed_Showers,e.Weight,MuonKE);
         if(MuonKE > 0 && passed_Showers)  h_SelectedMuonKE_Showers->Fill(MuonKE,e.Weight);

         h_MuonTrueTheta_Showers->Fill(MuonTrueTheta,e.Weight); 
         Efficiency_MuonTrueTheta_Showers->FillWeighted(passed_Showers,e.Weight,MuonTrueTheta);
         if(passed_Showers)  h_SelectedMuonTrueTheta_Showers->Fill(MuonTrueTheta,e.Weight);

         h_MuonDetectorTheta_Showers->Fill(MuonDetectorTheta,e.Weight); 
         Efficiency_MuonDetectorTheta_Showers->FillWeighted(passed_Showers,e.Weight,MuonDetectorTheta);
         if(passed_Showers)  h_SelectedMuonDetectorTheta_Showers->Fill(MuonDetectorTheta,e.Weight);

         h_MuonDetectorPhi_Showers->Fill(MuonDetectorPhi,e.Weight); 
         Efficiency_MuonDetectorPhi_Showers->FillWeighted(passed_Showers,e.Weight,MuonDetectorPhi);
         if(passed_Showers)  h_SelectedMuonDetectorPhi_Showers->Fill(MuonDetectorPhi,e.Weight);

         h_MuonBeamTheta_Showers->Fill(MuonBeamTheta,e.Weight); 
         Efficiency_MuonBeamTheta_Showers->FillWeighted(passed_Showers,e.Weight,MuonBeamTheta);
         if(passed_Showers)  h_SelectedMuonBeamTheta_Showers->Fill(MuonBeamTheta,e.Weight);

         h_MuonBeamPhi_Showers->Fill(MuonBeamPhi,e.Weight); 
         Efficiency_MuonBeamPhi_Showers->FillWeighted(passed_Showers,e.Weight,MuonBeamPhi);
         if(passed_Showers)  h_SelectedMuonBeamPhi_Showers->Fill(MuonBeamPhi,e.Weight);

         h_LambdaMomentum_Showers->Fill(LambdaMomentum,e.Weight); 
         Efficiency_LambdaMomentum_Showers->FillWeighted(passed_Showers,e.Weight,LambdaMomentum);
         if(passed_Showers)  h_SelectedLambdaMomentum_Showers->Fill(LambdaMomentum,e.Weight);

         h_DecayProtonMomentum_Showers->Fill(DecayProtonMomentum,e.Weight); 
         Efficiency_DecayProtonMomentum_Showers->FillWeighted(passed_Showers,e.Weight,DecayProtonMomentum);
         if(passed_Showers)  h_SelectedDecayProtonMomentum_Showers->Fill(DecayProtonMomentum,e.Weight);

         h_DecayPionMomentum_Showers->Fill(DecayPionMomentum,e.Weight); 
         Efficiency_DecayPionMomentum_Showers->FillWeighted(passed_Showers,e.Weight,DecayPionMomentum);
         if(passed_Showers)  h_SelectedDecayPionMomentum_Showers->Fill(DecayPionMomentum,e.Weight);

         h_OpeningAngle_Showers->Fill(OpeningAngle,e.Weight);
         Efficiency_OpeningAngle_Showers->FillWeighted(passed_Showers,e.Weight,OpeningAngle);
         if(OpeningAngle > 0 && passed_Showers) h_SelectedOpeningAngle_Showers->Fill(OpeningAngle,e.Weight);

         h_LambdaRange_Showers->Fill(LambdaRange,e.Weight);
         Efficiency_LambdaRange_Showers->FillWeighted(passed_Showers,e.Weight,LambdaRange);
         if(LambdaRange > 0 && passed_Showers) h_SelectedLambdaRange_Showers->Fill(LambdaRange,e.Weight);

         h_Showers->Fill(0.5,e.Weight);
         Efficiency_Showers->FillWeighted(passed_Showers,e.Weight,0.5);
         if(passed_Showers) h_Selected_Showers->Fill(0.5,e.Weight);

         // Muon ID
         h_Q2_MuonID->Fill(Q2,e.Weight);
         Efficiency_Q2_MuonID->FillWeighted(passed_MuonID,e.Weight,Q2);
         if(Q2 > 0 && passed_MuonID) h_SelectedQ2_MuonID->Fill(Q2,e.Weight);

         h_NuE_MuonID->Fill(NuE,e.Weight); 
         Efficiency_NuE_MuonID->FillWeighted(passed_MuonID,e.Weight,NuE);
         if(NuE > 0 && passed_MuonID)  h_SelectedNuE_MuonID->Fill(NuE,e.Weight);

         h_MuonKE_MuonID->Fill(MuonKE,e.Weight); 
         Efficiency_MuonKE_MuonID->FillWeighted(passed_MuonID,e.Weight,MuonKE);
         if(MuonKE > 0 && passed_MuonID)  h_SelectedMuonKE_MuonID->Fill(MuonKE,e.Weight);

         h_MuonTrueTheta_MuonID->Fill(MuonTrueTheta,e.Weight); 
         Efficiency_MuonTrueTheta_MuonID->FillWeighted(passed_MuonID,e.Weight,MuonTrueTheta);
         if(passed_MuonID)  h_SelectedMuonTrueTheta_MuonID->Fill(MuonTrueTheta,e.Weight);

         h_MuonDetectorTheta_MuonID->Fill(MuonDetectorTheta,e.Weight); 
         Efficiency_MuonDetectorTheta_MuonID->FillWeighted(passed_MuonID,e.Weight,MuonDetectorTheta);
         if(passed_MuonID)  h_SelectedMuonDetectorTheta_MuonID->Fill(MuonDetectorTheta,e.Weight);

         h_MuonDetectorPhi_MuonID->Fill(MuonDetectorPhi,e.Weight); 
         Efficiency_MuonDetectorPhi_MuonID->FillWeighted(passed_MuonID,e.Weight,MuonDetectorPhi);
         if(passed_MuonID)  h_SelectedMuonDetectorPhi_MuonID->Fill(MuonDetectorPhi,e.Weight);

         h_MuonBeamTheta_MuonID->Fill(MuonBeamTheta,e.Weight); 
         Efficiency_MuonBeamTheta_MuonID->FillWeighted(passed_MuonID,e.Weight,MuonBeamTheta);
         if(passed_MuonID)  h_SelectedMuonBeamTheta_MuonID->Fill(MuonBeamTheta,e.Weight);

         h_MuonBeamPhi_MuonID->Fill(MuonBeamPhi,e.Weight); 
         Efficiency_MuonBeamPhi_MuonID->FillWeighted(passed_MuonID,e.Weight,MuonBeamPhi);
         if(passed_MuonID)  h_SelectedMuonBeamPhi_MuonID->Fill(MuonBeamPhi,e.Weight);

         h_LambdaMomentum_MuonID->Fill(LambdaMomentum,e.Weight); 
         Efficiency_LambdaMomentum_MuonID->FillWeighted(passed_MuonID,e.Weight,LambdaMomentum);
         if(passed_MuonID)  h_SelectedLambdaMomentum_MuonID->Fill(LambdaMomentum,e.Weight);

         h_DecayProtonMomentum_MuonID->Fill(DecayProtonMomentum,e.Weight); 
         Efficiency_DecayProtonMomentum_MuonID->FillWeighted(passed_MuonID,e.Weight,DecayProtonMomentum);
         if(passed_MuonID)  h_SelectedDecayProtonMomentum_MuonID->Fill(DecayProtonMomentum,e.Weight);

         h_DecayPionMomentum_MuonID->Fill(DecayPionMomentum,e.Weight); 
         Efficiency_DecayPionMomentum_MuonID->FillWeighted(passed_MuonID,e.Weight,DecayPionMomentum);
         if(passed_MuonID)  h_SelectedDecayPionMomentum_MuonID->Fill(DecayPionMomentum,e.Weight);

         h_OpeningAngle_MuonID->Fill(OpeningAngle,e.Weight);
         Efficiency_OpeningAngle_MuonID->FillWeighted(passed_MuonID,e.Weight,OpeningAngle);
         if(OpeningAngle > 0 && passed_MuonID) h_SelectedOpeningAngle_MuonID->Fill(OpeningAngle,e.Weight);

         h_LambdaRange_MuonID->Fill(LambdaRange,e.Weight);
         Efficiency_LambdaRange_MuonID->FillWeighted(passed_MuonID,e.Weight,LambdaRange);
         if(LambdaRange > 0 && passed_MuonID) h_SelectedLambdaRange_MuonID->Fill(LambdaRange,e.Weight);

         h_MuonID->Fill(0.5,e.Weight);
         Efficiency_MuonID->FillWeighted(passed_MuonID,e.Weight,0.5);
         if(passed_MuonID) h_Selected_MuonID->Fill(0.5,e.Weight);

         // Decay Selector
         h_Q2_Selector->Fill(Q2,e.Weight);
         Efficiency_Q2_Selector->FillWeighted(passed_Selector,e.Weight,Q2);
         if(Q2 > 0 && passed_Selector) h_SelectedQ2_Selector->Fill(Q2,e.Weight);

         h_NuE_Selector->Fill(NuE,e.Weight); 
         Efficiency_NuE_Selector->FillWeighted(passed_Selector,e.Weight,NuE);
         if(NuE > 0 && passed_Selector)  h_SelectedNuE_Selector->Fill(NuE,e.Weight);

         h_MuonKE_Selector->Fill(MuonKE,e.Weight); 
         Efficiency_MuonKE_Selector->FillWeighted(passed_Selector,e.Weight,MuonKE);
         if(MuonKE > 0 && passed_Selector)  h_SelectedMuonKE_Selector->Fill(MuonKE,e.Weight);

         h_MuonTrueTheta_Selector->Fill(MuonTrueTheta,e.Weight); 
         Efficiency_MuonTrueTheta_Selector->FillWeighted(passed_Selector,e.Weight,MuonTrueTheta);
         if(passed_Selector)  h_SelectedMuonTrueTheta_Selector->Fill(MuonTrueTheta,e.Weight);

         h_MuonDetectorTheta_Selector->Fill(MuonDetectorTheta,e.Weight); 
         Efficiency_MuonDetectorTheta_Selector->FillWeighted(passed_Selector,e.Weight,MuonDetectorTheta);
         if(passed_Selector)  h_SelectedMuonDetectorTheta_Selector->Fill(MuonDetectorTheta,e.Weight);

         h_MuonDetectorPhi_Selector->Fill(MuonDetectorPhi,e.Weight); 
         Efficiency_MuonDetectorPhi_Selector->FillWeighted(passed_Selector,e.Weight,MuonDetectorPhi);
         if(passed_Selector)  h_SelectedMuonDetectorPhi_Selector->Fill(MuonDetectorPhi,e.Weight);

         h_MuonBeamTheta_Selector->Fill(MuonBeamTheta,e.Weight); 
         Efficiency_MuonBeamTheta_Selector->FillWeighted(passed_Selector,e.Weight,MuonBeamTheta);
         if(passed_Selector)  h_SelectedMuonBeamTheta_Selector->Fill(MuonBeamTheta,e.Weight);

         h_MuonBeamPhi_Selector->Fill(MuonBeamPhi,e.Weight); 
         Efficiency_MuonBeamPhi_Selector->FillWeighted(passed_Selector,e.Weight,MuonBeamPhi);
         if(passed_Selector)  h_SelectedMuonBeamPhi_Selector->Fill(MuonBeamPhi,e.Weight);

         h_LambdaMomentum_Selector->Fill(LambdaMomentum,e.Weight); 
         Efficiency_LambdaMomentum_Selector->FillWeighted(passed_Selector,e.Weight,LambdaMomentum);
         if(passed_Selector)  h_SelectedLambdaMomentum_Selector->Fill(LambdaMomentum,e.Weight);

         h_DecayProtonMomentum_Selector->Fill(DecayProtonMomentum,e.Weight); 
         Efficiency_DecayProtonMomentum_Selector->FillWeighted(passed_Selector,e.Weight,DecayProtonMomentum);
         if(passed_Selector)  h_SelectedDecayProtonMomentum_Selector->Fill(DecayProtonMomentum,e.Weight);

         h_DecayPionMomentum_Selector->Fill(DecayPionMomentum,e.Weight); 
         Efficiency_DecayPionMomentum_Selector->FillWeighted(passed_Selector,e.Weight,DecayPionMomentum);
         if(passed_Selector)  h_SelectedDecayPionMomentum_Selector->Fill(DecayPionMomentum,e.Weight);

         h_OpeningAngle_Selector->Fill(OpeningAngle,e.Weight);
         Efficiency_OpeningAngle_Selector->FillWeighted(passed_Selector,e.Weight,OpeningAngle);
         if(OpeningAngle > 0 && passed_Selector) h_SelectedOpeningAngle_Selector->Fill(OpeningAngle,e.Weight);

         h_Selector->Fill(0.5,e.Weight);
         Efficiency_Selector->FillWeighted(passed_Selector,e.Weight,0.5);
         if(passed_Selector) h_Selected_Selector->Fill(0.5,e.Weight);

         h_LambdaRange_Selector->Fill(LambdaRange,e.Weight);
         Efficiency_LambdaRange_Selector->FillWeighted(passed_Selector,e.Weight,LambdaRange);
         if(LambdaRange > 0 && passed_Selector) h_SelectedLambdaRange_Selector->Fill(LambdaRange,e.Weight);

         // Connectedness
         h_Q2_CT->Fill(Q2,e.Weight);
         Efficiency_Q2_CT->FillWeighted(passed_CT,e.Weight,Q2);
         if(Q2 > 0 && passed_CT) h_SelectedQ2_CT->Fill(Q2,e.Weight);

         h_NuE_CT->Fill(NuE,e.Weight); 
         Efficiency_NuE_CT->FillWeighted(passed_CT,e.Weight,NuE);
         if(NuE > 0 && passed_CT)  h_SelectedNuE_CT->Fill(NuE,e.Weight);

         h_MuonKE_CT->Fill(MuonKE,e.Weight); 
         Efficiency_MuonKE_CT->FillWeighted(passed_CT,e.Weight,MuonKE);
         if(MuonKE > 0 && passed_CT)  h_SelectedMuonKE_CT->Fill(MuonKE,e.Weight);

         h_MuonTrueTheta_CT->Fill(MuonTrueTheta,e.Weight); 
         Efficiency_MuonTrueTheta_CT->FillWeighted(passed_CT,e.Weight,MuonTrueTheta);
         if(passed_CT)  h_SelectedMuonTrueTheta_CT->Fill(MuonTrueTheta,e.Weight);

         h_MuonDetectorTheta_CT->Fill(MuonDetectorTheta,e.Weight); 
         Efficiency_MuonDetectorTheta_CT->FillWeighted(passed_CT,e.Weight,MuonDetectorTheta);
         if(passed_CT)  h_SelectedMuonDetectorTheta_CT->Fill(MuonDetectorTheta,e.Weight);

         h_MuonDetectorPhi_CT->Fill(MuonDetectorPhi,e.Weight); 
         Efficiency_MuonDetectorPhi_CT->FillWeighted(passed_CT,e.Weight,MuonDetectorPhi);
         if(passed_CT)  h_SelectedMuonDetectorPhi_CT->Fill(MuonDetectorPhi,e.Weight);

         h_MuonBeamTheta_CT->Fill(MuonBeamTheta,e.Weight); 
         Efficiency_MuonBeamTheta_CT->FillWeighted(passed_CT,e.Weight,MuonBeamTheta);
         if(passed_CT)  h_SelectedMuonBeamTheta_CT->Fill(MuonBeamTheta,e.Weight);

         h_MuonBeamPhi_CT->Fill(MuonBeamPhi,e.Weight); 
         Efficiency_MuonBeamPhi_CT->FillWeighted(passed_CT,e.Weight,MuonBeamPhi);
         if(passed_CT)  h_SelectedMuonBeamPhi_CT->Fill(MuonBeamPhi,e.Weight);

         h_LambdaMomentum_CT->Fill(LambdaMomentum,e.Weight); 
         Efficiency_LambdaMomentum_CT->FillWeighted(passed_CT,e.Weight,LambdaMomentum);
         if(passed_CT)  h_SelectedLambdaMomentum_CT->Fill(LambdaMomentum,e.Weight);

         h_DecayProtonMomentum_CT->Fill(DecayProtonMomentum,e.Weight); 
         Efficiency_DecayProtonMomentum_CT->FillWeighted(passed_CT,e.Weight,DecayProtonMomentum);
         if(passed_CT)  h_SelectedDecayProtonMomentum_CT->Fill(DecayProtonMomentum,e.Weight);

         h_DecayPionMomentum_CT->Fill(DecayPionMomentum,e.Weight); 
         Efficiency_DecayPionMomentum_CT->FillWeighted(passed_CT,e.Weight,DecayPionMomentum);
         if(passed_CT)  h_SelectedDecayPionMomentum_CT->Fill(DecayPionMomentum,e.Weight);

         h_OpeningAngle_CT->Fill(OpeningAngle,e.Weight);
         Efficiency_OpeningAngle_CT->FillWeighted(passed_CT,e.Weight,OpeningAngle);
         if(OpeningAngle > 0 && passed_CT) h_SelectedOpeningAngle_CT->Fill(OpeningAngle,e.Weight);

         h_LambdaRange_CT->Fill(LambdaRange,e.Weight);
         Efficiency_LambdaRange_CT->FillWeighted(passed_CT,e.Weight,LambdaRange);
         if(LambdaRange > 0 && passed_CT) h_SelectedLambdaRange_CT->Fill(LambdaRange,e.Weight);

         h_CT->Fill(0.5,e.Weight);
         Efficiency_CT->FillWeighted(passed_CT,e.Weight,0.5);
         if(passed_CT) h_Selected_CT->Fill(0.5,e.Weight);

         // Invariant mass cut
         h_Q2_WCut->Fill(Q2,e.Weight);
         Efficiency_Q2_WCut->FillWeighted(passed_WCut,e.Weight,Q2);
         if(Q2 > 0 && passed_WCut) h_SelectedQ2_WCut->Fill(Q2,e.Weight);

         h_NuE_WCut->Fill(NuE,e.Weight); 
         Efficiency_NuE_WCut->FillWeighted(passed_WCut,e.Weight,NuE);
         if(NuE > 0 && passed_WCut)  h_SelectedNuE_WCut->Fill(NuE,e.Weight);

         h_MuonKE_WCut->Fill(MuonKE,e.Weight); 
         Efficiency_MuonKE_WCut->FillWeighted(passed_WCut,e.Weight,MuonKE);
         if(MuonKE > 0 && passed_WCut)  h_SelectedMuonKE_WCut->Fill(MuonKE,e.Weight);

         h_MuonTrueTheta_WCut->Fill(MuonTrueTheta,e.Weight); 
         Efficiency_MuonTrueTheta_WCut->FillWeighted(passed_WCut,e.Weight,MuonTrueTheta);
         if(passed_WCut)  h_SelectedMuonTrueTheta_WCut->Fill(MuonTrueTheta,e.Weight);

         h_MuonDetectorTheta_WCut->Fill(MuonDetectorTheta,e.Weight); 
         Efficiency_MuonDetectorTheta_WCut->FillWeighted(passed_WCut,e.Weight,MuonDetectorTheta);
         if(passed_WCut)  h_SelectedMuonDetectorTheta_WCut->Fill(MuonDetectorTheta,e.Weight);

         h_MuonDetectorPhi_WCut->Fill(MuonDetectorPhi,e.Weight); 
         Efficiency_MuonDetectorPhi_WCut->FillWeighted(passed_WCut,e.Weight,MuonDetectorPhi);
         if(passed_WCut)  h_SelectedMuonDetectorPhi_WCut->Fill(MuonDetectorPhi,e.Weight);

         h_MuonBeamTheta_WCut->Fill(MuonBeamTheta,e.Weight); 
         Efficiency_MuonBeamTheta_WCut->FillWeighted(passed_WCut,e.Weight,MuonBeamTheta);
         if(passed_WCut)  h_SelectedMuonBeamTheta_WCut->Fill(MuonBeamTheta,e.Weight);

         h_MuonBeamPhi_WCut->Fill(MuonBeamPhi,e.Weight); 
         Efficiency_MuonBeamPhi_WCut->FillWeighted(passed_WCut,e.Weight,MuonBeamPhi);
         if(passed_WCut)  h_SelectedMuonBeamPhi_WCut->Fill(MuonBeamPhi,e.Weight);

         h_LambdaMomentum_WCut->Fill(LambdaMomentum,e.Weight); 
         Efficiency_LambdaMomentum_WCut->FillWeighted(passed_WCut,e.Weight,LambdaMomentum);
         if(passed_WCut)  h_SelectedLambdaMomentum_WCut->Fill(LambdaMomentum,e.Weight);

         h_DecayProtonMomentum_WCut->Fill(DecayProtonMomentum,e.Weight); 
         Efficiency_DecayProtonMomentum_WCut->FillWeighted(passed_WCut,e.Weight,DecayProtonMomentum);
         if(passed_WCut)  h_SelectedDecayProtonMomentum_WCut->Fill(DecayProtonMomentum,e.Weight);

         h_DecayPionMomentum_WCut->Fill(DecayPionMomentum,e.Weight); 
         Efficiency_DecayPionMomentum_WCut->FillWeighted(passed_WCut,e.Weight,DecayPionMomentum);
         if(passed_WCut)  h_SelectedDecayPionMomentum_WCut->Fill(DecayPionMomentum,e.Weight);

         h_OpeningAngle_WCut->Fill(OpeningAngle,e.Weight);
         Efficiency_OpeningAngle_WCut->FillWeighted(passed_WCut,e.Weight,OpeningAngle);
         if(OpeningAngle > 0 && passed_WCut) h_SelectedOpeningAngle_WCut->Fill(OpeningAngle,e.Weight);

         h_LambdaRange_WCut->Fill(LambdaRange,e.Weight);
         Efficiency_LambdaRange_WCut->FillWeighted(passed_WCut,e.Weight,LambdaRange);
         if(LambdaRange > 0 && passed_WCut) h_SelectedLambdaRange_WCut->Fill(LambdaRange,e.Weight);

         h_WCut->Fill(0.5,e.Weight);
         Efficiency_WCut->FillWeighted(passed_WCut,e.Weight,0.5);
         if(passed_WCut) h_Selected_WCut->Fill(0.5,e.Weight);

         // Angle cut
         h_Q2_AngleCut->Fill(Q2,e.Weight);
         Efficiency_Q2_AngleCut->FillWeighted(passed_AngleCut,e.Weight,Q2);
         if(Q2 > 0 && passed_AngleCut) h_SelectedQ2_AngleCut->Fill(Q2,e.Weight);

         h_NuE_AngleCut->Fill(NuE,e.Weight); 
         Efficiency_NuE_AngleCut->FillWeighted(passed_AngleCut,e.Weight,NuE);
         if(NuE > 0 && passed_AngleCut)  h_SelectedNuE_AngleCut->Fill(NuE,e.Weight);

         h_MuonKE_AngleCut->Fill(MuonKE,e.Weight); 
         Efficiency_MuonKE_AngleCut->FillWeighted(passed_AngleCut,e.Weight,MuonKE);
         if(MuonKE > 0 && passed_AngleCut)  h_SelectedMuonKE_AngleCut->Fill(MuonKE,e.Weight);

         h_MuonTrueTheta_AngleCut->Fill(MuonTrueTheta,e.Weight); 
         Efficiency_MuonTrueTheta_AngleCut->FillWeighted(passed_AngleCut,e.Weight,MuonTrueTheta);
         if(passed_AngleCut)  h_SelectedMuonTrueTheta_AngleCut->Fill(MuonTrueTheta,e.Weight);

         h_MuonDetectorTheta_AngleCut->Fill(MuonDetectorTheta,e.Weight); 
         Efficiency_MuonDetectorTheta_AngleCut->FillWeighted(passed_AngleCut,e.Weight,MuonDetectorTheta);
         if(passed_AngleCut)  h_SelectedMuonDetectorTheta_AngleCut->Fill(MuonDetectorTheta,e.Weight);

         h_MuonDetectorPhi_AngleCut->Fill(MuonDetectorPhi,e.Weight); 
         Efficiency_MuonDetectorPhi_AngleCut->FillWeighted(passed_AngleCut,e.Weight,MuonDetectorPhi);
         if(passed_AngleCut)  h_SelectedMuonDetectorPhi_AngleCut->Fill(MuonDetectorPhi,e.Weight);

         h_MuonBeamTheta_AngleCut->Fill(MuonBeamTheta,e.Weight); 
         Efficiency_MuonBeamTheta_AngleCut->FillWeighted(passed_AngleCut,e.Weight,MuonBeamTheta);
         if(passed_AngleCut)  h_SelectedMuonBeamTheta_AngleCut->Fill(MuonBeamTheta,e.Weight);

         h_MuonBeamPhi_AngleCut->Fill(MuonBeamPhi,e.Weight); 
         Efficiency_MuonBeamPhi_AngleCut->FillWeighted(passed_AngleCut,e.Weight,MuonBeamPhi);
         if(passed_AngleCut)  h_SelectedMuonBeamPhi_AngleCut->Fill(MuonBeamPhi,e.Weight);

         h_LambdaMomentum_AngleCut->Fill(LambdaMomentum,e.Weight); 
         Efficiency_LambdaMomentum_AngleCut->FillWeighted(passed_AngleCut,e.Weight,LambdaMomentum);
         if(passed_AngleCut)  h_SelectedLambdaMomentum_AngleCut->Fill(LambdaMomentum,e.Weight);

         h_DecayProtonMomentum_AngleCut->Fill(DecayProtonMomentum,e.Weight); 
         Efficiency_DecayProtonMomentum_AngleCut->FillWeighted(passed_AngleCut,e.Weight,DecayProtonMomentum);
         if(passed_AngleCut)  h_SelectedDecayProtonMomentum_AngleCut->Fill(DecayProtonMomentum,e.Weight);

         h_DecayPionMomentum_AngleCut->Fill(DecayPionMomentum,e.Weight); 
         Efficiency_DecayPionMomentum_AngleCut->FillWeighted(passed_AngleCut,e.Weight,DecayPionMomentum);
         if(passed_AngleCut)  h_SelectedDecayPionMomentum_AngleCut->Fill(DecayPionMomentum,e.Weight);

         h_OpeningAngle_AngleCut->Fill(OpeningAngle,e.Weight);
         Efficiency_OpeningAngle_AngleCut->FillWeighted(passed_AngleCut,e.Weight,OpeningAngle);
         if(OpeningAngle > 0 && passed_AngleCut) h_SelectedOpeningAngle_AngleCut->Fill(OpeningAngle,e.Weight);

         h_LambdaRange_AngleCut->Fill(LambdaRange,e.Weight);
         Efficiency_LambdaRange_AngleCut->FillWeighted(passed_AngleCut,e.Weight,LambdaRange);
         if(LambdaRange > 0 && passed_AngleCut) h_SelectedLambdaRange_AngleCut->Fill(LambdaRange,e.Weight);

         h_AngleCut->Fill(0.5,e.Weight);
         Efficiency_AngleCut->FillWeighted(passed_AngleCut,e.Weight,0.5);
         if(passed_AngleCut) h_Selected_AngleCut->Fill(0.5,e.Weight);
      }

      //close the event assembler
      E.Close();

      // Entire Selection
      DrawEfficiencyPlot(h_Q2_All,h_SelectedQ2_All,Efficiency_Q2_All,";True Q^{2} (GeV^{2},Mode,POT);Events",label + "_Q2_All",Mode,POT);
      DrawEfficiencyPlot(h_NuE_All,h_SelectedNuE_All,Efficiency_NuE_All,";True E_{#nu} (GeV,Mode,POT);Events",label + "_NuE_All",Mode,POT);
      DrawEfficiencyPlot(h_MuonKE_All,h_SelectedMuonKE_All,Efficiency_MuonKE_All,";True Muon E_{k} (GeV,Mode,POT);Events",label + "_MuonKE_All",Mode,POT);
      DrawEfficiencyPlot(h_MuonTrueTheta_All,h_SelectedMuonTrueTheta_All,Efficiency_MuonTrueTheta_All,";True Muon #theta;Events",label + "_MuonTrueTheta_All",Mode,POT);
      DrawEfficiencyPlot(h_MuonDetectorTheta_All,h_SelectedMuonDetectorTheta_All,Efficiency_MuonDetectorTheta_All,";Detector Muon #theta;Events",label + "_MuonDetectorTheta_All",Mode,POT);
      DrawEfficiencyPlot(h_MuonDetectorPhi_All,h_SelectedMuonDetectorPhi_All,Efficiency_MuonDetectorPhi_All,";Detector Muon #phi;Events",label + "_MuonDetectorPhi_All",Mode,POT);
      DrawEfficiencyPlot(h_MuonBeamTheta_All,h_SelectedMuonBeamTheta_All,Efficiency_MuonBeamTheta_All,";Beam Muon #theta;Events",label + "_MuonBeamTheta_All",Mode,POT);
      DrawEfficiencyPlot(h_MuonBeamPhi_All,h_SelectedMuonBeamPhi_All,Efficiency_MuonBeamPhi_All,";Beam Muon #phi;Events",label + "_MuonBeamPhi_All",Mode,POT);
      DrawEfficiencyPlot(h_LambdaMomentum_All,h_SelectedLambdaMomentum_All,Efficiency_LambdaMomentum_All,";True #Lambda Momentum (GeV/c,Mode,POT);Events",label + "_LambdaMomentum_All",Mode,POT);
      DrawEfficiencyPlot(h_DecayProtonMomentum_All,h_SelectedDecayProtonMomentum_All,Efficiency_DecayProtonMomentum_All,";True Decay Proton Momentum (GeV/c,Mode,POT);Events",label + "_DecayProtonMomentum_All",Mode,POT);
      DrawEfficiencyPlot(h_DecayPionMomentum_All,h_SelectedDecayPionMomentum_All,Efficiency_DecayPionMomentum_All,";True Decay #pi^{-} Momentum (GeV/c,Mode,POT);Events",label + "_DecayPionMomentum_All",Mode,POT);
      DrawEfficiencyPlot(h_OpeningAngle_All,h_SelectedOpeningAngle_All,Efficiency_OpeningAngle_All,";True Opening Angle (deg,Mode,POT);Events",label + "_OpeningAngle_All",Mode,POT);
      DrawEfficiencyPlot(h_LambdaRange_All,h_SelectedLambdaRange_All,Efficiency_LambdaRange_All,";True #Lambda Range (cm,Mode,POT);Events",label + "_LambdaRange_All",Mode,POT);
      DrawEfficiencyPlot(h_All,h_Selected_All,Efficiency_All,";;Events",label + "_All",Mode,POT);

      // Fiducial Volume Cut
      DrawEfficiencyPlot(h_Q2_FV,h_SelectedQ2_FV,Efficiency_Q2_FV,";True Q^{2} (GeV^{2},Mode,POT);Events",label + "_Q2_FV",Mode,POT);
      DrawEfficiencyPlot(h_NuE_FV,h_SelectedNuE_FV,Efficiency_NuE_FV,";True E_{#nu} (GeV,Mode,POT);Events",label + "_NuE_FV",Mode,POT);
      DrawEfficiencyPlot(h_MuonKE_FV,h_SelectedMuonKE_FV,Efficiency_MuonKE_FV,";True Muon E_{k} (GeV,Mode,POT);Events",label + "_MuonKE_FV",Mode,POT);
      DrawEfficiencyPlot(h_MuonTrueTheta_FV,h_SelectedMuonTrueTheta_FV,Efficiency_MuonTrueTheta_FV,";True Muon #theta;Events",label + "_MuonTrueTheta_FV",Mode,POT);
      DrawEfficiencyPlot(h_MuonDetectorTheta_FV,h_SelectedMuonDetectorTheta_FV,Efficiency_MuonDetectorTheta_FV,";Detector Muon #theta;Events",label + "_MuonDetectorTheta_FV",Mode,POT);
      DrawEfficiencyPlot(h_MuonDetectorPhi_FV,h_SelectedMuonDetectorPhi_FV,Efficiency_MuonDetectorPhi_FV,";Detector Muon #phi;Events",label + "_MuonDetectorPhi_FV",Mode,POT);
      DrawEfficiencyPlot(h_MuonBeamTheta_FV,h_SelectedMuonBeamTheta_FV,Efficiency_MuonBeamTheta_FV,";Beam Muon #theta;Events",label + "_MuonBeamTheta_FV",Mode,POT);
      DrawEfficiencyPlot(h_MuonBeamPhi_FV,h_SelectedMuonBeamPhi_FV,Efficiency_MuonBeamPhi_FV,";Beam Muon #phi;Events",label + "_MuonBeamPhi_FV",Mode,POT);
      DrawEfficiencyPlot(h_LambdaMomentum_FV,h_SelectedLambdaMomentum_FV,Efficiency_LambdaMomentum_FV,";True #Lambda Momentum (GeV/c,Mode,POT);Events",label + "_LambdaMomentum_FV",Mode,POT);
      DrawEfficiencyPlot(h_DecayProtonMomentum_FV,h_SelectedDecayProtonMomentum_FV,Efficiency_DecayProtonMomentum_FV,";True Decay Proton Momentum (GeV/c,Mode,POT);Events",label + "_DecayProtonMomentum_FV",Mode,POT);
      DrawEfficiencyPlot(h_DecayPionMomentum_FV,h_SelectedDecayPionMomentum_FV,Efficiency_DecayPionMomentum_FV,";True Decay #pi^{-} Momentum (GeV/c,Mode,POT);Events",label + "_DecayPionMomentum_FV",Mode,POT);
      DrawEfficiencyPlot(h_OpeningAngle_FV,h_SelectedOpeningAngle_FV,Efficiency_OpeningAngle_FV,";True Opening Angle (deg,Mode,POT);Events",label + "_OpeningAngle_FV",Mode,POT);
      DrawEfficiencyPlot(h_LambdaRange_FV,h_SelectedLambdaRange_FV,Efficiency_LambdaRange_FV,";True #Lambda Range (cm,Mode,POT);Events",label + "_LambdaRange_FV",Mode,POT);
      DrawEfficiencyPlot(h_FV,h_Selected_FV,Efficiency_FV,";;Events",label + "_FV",Mode,POT);


      // Track Cut
      DrawEfficiencyPlot(h_Q2_Tracks,h_SelectedQ2_Tracks,Efficiency_Q2_Tracks,";True Q^{2} (GeV^{2},Mode,POT);Events",label + "_Q2_Tracks",Mode,POT);
      DrawEfficiencyPlot(h_NuE_Tracks,h_SelectedNuE_Tracks,Efficiency_NuE_Tracks,";True E_{#nu} (GeV,Mode,POT);Events",label + "_NuE_Tracks",Mode,POT);
      DrawEfficiencyPlot(h_MuonKE_Tracks,h_SelectedMuonKE_Tracks,Efficiency_MuonKE_Tracks,";True Muon E_{k} (GeV,Mode,POT);Events",label + "_MuonKE_Tracks",Mode,POT);
      DrawEfficiencyPlot(h_MuonTrueTheta_Tracks,h_SelectedMuonTrueTheta_Tracks,Efficiency_MuonTrueTheta_Tracks,";True Muon #theta;Events",label + "_MuonTrueTheta_Tracks",Mode,POT);
      DrawEfficiencyPlot(h_MuonDetectorTheta_Tracks,h_SelectedMuonDetectorTheta_Tracks,Efficiency_MuonDetectorTheta_Tracks,";Detector Muon #theta;Events",label + "_MuonDetectorTheta_Tracks",Mode,POT);
      DrawEfficiencyPlot(h_MuonDetectorPhi_Tracks,h_SelectedMuonDetectorPhi_Tracks,Efficiency_MuonDetectorPhi_Tracks,";Detector Muon #phi;Events",label + "_MuonDetectorPhi_Tracks",Mode,POT);
      DrawEfficiencyPlot(h_MuonBeamTheta_Tracks,h_SelectedMuonBeamTheta_Tracks,Efficiency_MuonBeamTheta_Tracks,";Beam Muon #theta;Events",label + "_MuonBeamTheta_Tracks",Mode,POT);
      DrawEfficiencyPlot(h_MuonBeamPhi_Tracks,h_SelectedMuonBeamPhi_Tracks,Efficiency_MuonBeamPhi_Tracks,";Beam Muon #phi;Events",label + "_MuonBeamPhi_Tracks",Mode,POT);
      DrawEfficiencyPlot(h_LambdaMomentum_Tracks,h_SelectedLambdaMomentum_Tracks,Efficiency_LambdaMomentum_Tracks,";True #Lambda Momentum (GeV/c,Mode,POT);Events",label + "_LambdaMomentum_Tracks",Mode,POT);
      DrawEfficiencyPlot(h_DecayProtonMomentum_Tracks,h_SelectedDecayProtonMomentum_Tracks,Efficiency_DecayProtonMomentum_Tracks,";True Decay Proton Momentum (GeV/c,Mode,POT);Events",label + "_DecayProtonMomentum_Tracks",Mode,POT);
      DrawEfficiencyPlot(h_DecayPionMomentum_Tracks,h_SelectedDecayPionMomentum_Tracks,Efficiency_DecayPionMomentum_Tracks,";True Decay #pi^{-} Momentum (GeV/c,Mode,POT);Events",label + "_DecayPionMomentum_Tracks",Mode,POT);
      DrawEfficiencyPlot(h_OpeningAngle_Tracks,h_SelectedOpeningAngle_Tracks,Efficiency_OpeningAngle_Tracks,";True Opening Angle (deg,Mode,POT);Events",label + "_OpeningAngle_Tracks",Mode,POT);
      DrawEfficiencyPlot(h_LambdaRange_Tracks,h_SelectedLambdaRange_Tracks,Efficiency_LambdaRange_Tracks,";True #Lambda Range (cm,Mode,POT);Events",label + "_LambdaRange_Tracks",Mode,POT);
      DrawEfficiencyPlot(h_Tracks,h_Selected_Tracks,Efficiency_Tracks,";;Events",label + "_Tracks",Mode,POT);

      // Shower Cut
      DrawEfficiencyPlot(h_Q2_Showers,h_SelectedQ2_Showers,Efficiency_Q2_Showers,";True Q^{2} (GeV^{2},Mode,POT);Events",label + "_Q2_Showers",Mode,POT);
      DrawEfficiencyPlot(h_NuE_Showers,h_SelectedNuE_Showers,Efficiency_NuE_Showers,";True E_{#nu} (GeV,Mode,POT);Events",label + "_NuE_Showers",Mode,POT);
      DrawEfficiencyPlot(h_MuonKE_Showers,h_SelectedMuonKE_Showers,Efficiency_MuonKE_Showers,";True Muon E_{k} (GeV,Mode,POT);Events",label + "_MuonKE_Showers",Mode,POT);
      DrawEfficiencyPlot(h_MuonTrueTheta_Showers,h_SelectedMuonTrueTheta_Showers,Efficiency_MuonTrueTheta_Showers,";True Muon #theta;Events",label + "_MuonTrueTheta_Showers",Mode,POT);
      DrawEfficiencyPlot(h_MuonDetectorTheta_Showers,h_SelectedMuonDetectorTheta_Showers,Efficiency_MuonDetectorTheta_Showers,";Detector Muon #theta;Events",label + "_MuonDetectorTheta_Showers",Mode,POT);
      DrawEfficiencyPlot(h_MuonDetectorPhi_Showers,h_SelectedMuonDetectorPhi_Showers,Efficiency_MuonDetectorPhi_Showers,";Detector Muon #phi;Events",label + "_MuonDetectorPhi_Showers",Mode,POT);
      DrawEfficiencyPlot(h_MuonBeamTheta_Showers,h_SelectedMuonBeamTheta_Showers,Efficiency_MuonBeamTheta_Showers,";Beam Muon #theta;Events",label + "_MuonBeamTheta_Showers",Mode,POT);
      DrawEfficiencyPlot(h_MuonBeamPhi_Showers,h_SelectedMuonBeamPhi_Showers,Efficiency_MuonBeamPhi_Showers,";Beam Muon #phi;Events",label + "_MuonBeamPhi_Showers",Mode,POT);
      DrawEfficiencyPlot(h_LambdaMomentum_Showers,h_SelectedLambdaMomentum_Showers,Efficiency_LambdaMomentum_Showers,";True #Lambda Momentum (GeV/c,Mode,POT);Events",label + "_LambdaMomentum_Showers",Mode,POT);
      DrawEfficiencyPlot(h_DecayProtonMomentum_Showers,h_SelectedDecayProtonMomentum_Showers,Efficiency_DecayProtonMomentum_Showers,";True Decay Proton Momentum (GeV/c,Mode,POT);Events",label + "_DecayProtonMomentum_Showers",Mode,POT);
      DrawEfficiencyPlot(h_DecayPionMomentum_Showers,h_SelectedDecayPionMomentum_Showers,Efficiency_DecayPionMomentum_Showers,";True Decay #pi^{-} Momentum (GeV/c,Mode,POT);Events",label + "_DecayPionMomentum_Showers",Mode,POT);
      DrawEfficiencyPlot(h_OpeningAngle_Showers,h_SelectedOpeningAngle_Showers,Efficiency_OpeningAngle_Showers,";True Opening Angle (deg,Mode,POT);Events",label + "_OpeningAngle_Showers",Mode,POT);
      DrawEfficiencyPlot(h_LambdaRange_Showers,h_SelectedLambdaRange_Showers,Efficiency_LambdaRange_Showers,";True #Lambda Range (cm,Mode,POT);Events",label + "_LambdaRange_Showers",Mode,POT);
      DrawEfficiencyPlot(h_Showers,h_Selected_Showers,Efficiency_Showers,";;Events",label + "_Showers",Mode,POT);

      // Muon ID
      DrawEfficiencyPlot(h_Q2_MuonID,h_SelectedQ2_MuonID,Efficiency_Q2_MuonID,";True Q^{2} (GeV^{2},Mode,POT);Events",label + "_Q2_MuonID",Mode,POT);
      DrawEfficiencyPlot(h_NuE_MuonID,h_SelectedNuE_MuonID,Efficiency_NuE_MuonID,";True E_{#nu} (GeV,Mode,POT);Events",label + "_NuE_MuonID",Mode,POT);
      DrawEfficiencyPlot(h_MuonKE_MuonID,h_SelectedMuonKE_MuonID,Efficiency_MuonKE_MuonID,";True Muon E_{k} (GeV,Mode,POT);Events",label + "_MuonKE_MuonID",Mode,POT);
      DrawEfficiencyPlot(h_MuonTrueTheta_MuonID,h_SelectedMuonTrueTheta_MuonID,Efficiency_MuonTrueTheta_MuonID,";True Muon #theta;Events",label + "_MuonTrueTheta_MuonID",Mode,POT);
      DrawEfficiencyPlot(h_MuonDetectorTheta_MuonID,h_SelectedMuonDetectorTheta_MuonID,Efficiency_MuonDetectorTheta_MuonID,";Detector Muon #theta;Events",label + "_MuonDetectorTheta_MuonID",Mode,POT);
      DrawEfficiencyPlot(h_MuonDetectorPhi_MuonID,h_SelectedMuonDetectorPhi_MuonID,Efficiency_MuonDetectorPhi_MuonID,";Detector Muon #phi;Events",label + "_MuonDetectorPhi_MuonID",Mode,POT);
      DrawEfficiencyPlot(h_MuonBeamTheta_MuonID,h_SelectedMuonBeamTheta_MuonID,Efficiency_MuonBeamTheta_MuonID,";Beam Muon #theta;Events",label + "_MuonBeamTheta_MuonID",Mode,POT);
      DrawEfficiencyPlot(h_MuonBeamPhi_MuonID,h_SelectedMuonBeamPhi_MuonID,Efficiency_MuonBeamPhi_MuonID,";Beam Muon #phi;Events",label + "_MuonBeamPhi_MuonID",Mode,POT);
      DrawEfficiencyPlot(h_LambdaMomentum_MuonID,h_SelectedLambdaMomentum_MuonID,Efficiency_LambdaMomentum_MuonID,";True #Lambda Momentum (GeV/c,Mode,POT);Events",label + "_LambdaMomentum_MuonID",Mode,POT);
      DrawEfficiencyPlot(h_DecayProtonMomentum_MuonID,h_SelectedDecayProtonMomentum_MuonID,Efficiency_DecayProtonMomentum_MuonID,";True Decay Proton Momentum (GeV/c,Mode,POT);Events",label + "_DecayProtonMomentum_MuonID",Mode,POT);
      DrawEfficiencyPlot(h_DecayPionMomentum_MuonID,h_SelectedDecayPionMomentum_MuonID,Efficiency_DecayPionMomentum_MuonID,";True Decay #pi^{-} Momentum (GeV/c,Mode,POT);Events",label + "_DecayPionMomentum_MuonID",Mode,POT);
      DrawEfficiencyPlot(h_OpeningAngle_MuonID,h_SelectedOpeningAngle_MuonID,Efficiency_OpeningAngle_MuonID,";True Opening Angle (deg,Mode,POT);Events",label + "_OpeningAngle_MuonID",Mode,POT);
      DrawEfficiencyPlot(h_LambdaRange_MuonID,h_SelectedLambdaRange_MuonID,Efficiency_LambdaRange_MuonID,";True #Lambda Range (cm,Mode,POT);Events",label + "_LambdaRange_MuonID",Mode,POT);
      DrawEfficiencyPlot(h_MuonID,h_Selected_MuonID,Efficiency_MuonID,";;Events",label + "_MuonID",Mode,POT);

      // Track Selector BDT
      DrawEfficiencyPlot(h_Q2_Selector,h_SelectedQ2_Selector,Efficiency_Q2_Selector,";True Q^{2} (GeV^{2},Mode,POT);Events",label + "_Q2_Selector",Mode,POT);
      DrawEfficiencyPlot(h_NuE_Selector,h_SelectedNuE_Selector,Efficiency_NuE_Selector,";True E_{#nu} (GeV,Mode,POT);Events",label + "_NuE_Selector",Mode,POT);
      DrawEfficiencyPlot(h_MuonKE_Selector,h_SelectedMuonKE_Selector,Efficiency_MuonKE_Selector,";True Muon E_{k} (GeV,Mode,POT);Events",label + "_MuonKE_Selector",Mode,POT);
      DrawEfficiencyPlot(h_MuonTrueTheta_Selector,h_SelectedMuonTrueTheta_Selector,Efficiency_MuonTrueTheta_Selector,";True Muon #theta;Events",label + "_MuonTrueTheta_Selector",Mode,POT);
      DrawEfficiencyPlot(h_MuonDetectorTheta_Selector,h_SelectedMuonDetectorTheta_Selector,Efficiency_MuonDetectorTheta_Selector,";Detector Muon #theta;Events",label + "_MuonDetectorTheta_Selector",Mode,POT);
      DrawEfficiencyPlot(h_MuonDetectorPhi_Selector,h_SelectedMuonDetectorPhi_Selector,Efficiency_MuonDetectorPhi_Selector,";Detector Muon #phi;Events",label + "_MuonDetectorPhi_Selector",Mode,POT);
      DrawEfficiencyPlot(h_MuonBeamTheta_Selector,h_SelectedMuonBeamTheta_Selector,Efficiency_MuonBeamTheta_Selector,";Beam Muon #theta;Events",label + "_MuonBeamTheta_Selector",Mode,POT);
      DrawEfficiencyPlot(h_MuonBeamPhi_Selector,h_SelectedMuonBeamPhi_Selector,Efficiency_MuonBeamPhi_Selector,";Beam Muon #phi;Events",label + "_MuonBeamPhi_Selector",Mode,POT);
      DrawEfficiencyPlot(h_LambdaMomentum_Selector,h_SelectedLambdaMomentum_Selector,Efficiency_LambdaMomentum_Selector,";True #Lambda Momentum (GeV/c,Mode,POT);Events",label + "_LambdaMomentum_Selector",Mode,POT);
      DrawEfficiencyPlot(h_DecayProtonMomentum_Selector,h_SelectedDecayProtonMomentum_Selector,Efficiency_DecayProtonMomentum_Selector,";True Decay Proton Momentum (GeV/c,Mode,POT);Events",label + "_DecayProtonMomentum_Selector",Mode,POT);
      DrawEfficiencyPlot(h_DecayPionMomentum_Selector,h_SelectedDecayPionMomentum_Selector,Efficiency_DecayPionMomentum_Selector,";True Decay #pi^{-} Momentum (GeV/c,Mode,POT);Events",label + "_DecayPionMomentum_Selector",Mode,POT);
      DrawEfficiencyPlot(h_OpeningAngle_Selector,h_SelectedOpeningAngle_Selector,Efficiency_OpeningAngle_Selector,";True Opening Angle (deg,Mode,POT);Events",label + "_OpeningAngle_Selector",Mode,POT);
      DrawEfficiencyPlot(h_LambdaRange_Selector,h_SelectedLambdaRange_Selector,Efficiency_LambdaRange_Selector,";True #Lambda Range (cm,Mode,POT);Events",label + "_LambdaRange_Selector",Mode,POT);
      DrawEfficiencyPlot(h_Selector,h_Selected_Selector,Efficiency_Selector,";;Events",label + "_Selector",Mode,POT);


      // CT
      DrawEfficiencyPlot(h_Q2_CT,h_SelectedQ2_CT,Efficiency_Q2_CT,";True Q^{2} (GeV^{2},Mode,POT);Events",label + "_Q2_CT",Mode,POT);
      DrawEfficiencyPlot(h_NuE_CT,h_SelectedNuE_CT,Efficiency_NuE_CT,";True E_{#nu} (GeV,Mode,POT);Events",label + "_NuE_CT",Mode,POT);
      DrawEfficiencyPlot(h_MuonKE_CT,h_SelectedMuonKE_CT,Efficiency_MuonKE_CT,";True Muon E_{k} (GeV,Mode,POT);Events",label + "_MuonKE_CT",Mode,POT);
      DrawEfficiencyPlot(h_MuonTrueTheta_CT,h_SelectedMuonTrueTheta_CT,Efficiency_MuonTrueTheta_CT,";True Muon #theta;Events",label + "_MuonTrueTheta_CT",Mode,POT);
      DrawEfficiencyPlot(h_MuonDetectorTheta_CT,h_SelectedMuonDetectorTheta_CT,Efficiency_MuonDetectorTheta_CT,";Detector Muon #theta;Events",label + "_MuonDetectorTheta_CT",Mode,POT);
      DrawEfficiencyPlot(h_MuonDetectorPhi_CT,h_SelectedMuonDetectorPhi_CT,Efficiency_MuonDetectorPhi_CT,";Detector Muon #phi;Events",label + "_MuonDetectorPhi_CT",Mode,POT);
      DrawEfficiencyPlot(h_MuonBeamTheta_CT,h_SelectedMuonBeamTheta_CT,Efficiency_MuonBeamTheta_CT,";Beam Muon #theta;Events",label + "_MuonBeamTheta_CT",Mode,POT);
      DrawEfficiencyPlot(h_MuonBeamPhi_CT,h_SelectedMuonBeamPhi_CT,Efficiency_MuonBeamPhi_CT,";Beam Muon #phi;Events",label + "_MuonBeamPhi_CT",Mode,POT);
      DrawEfficiencyPlot(h_LambdaMomentum_CT,h_SelectedLambdaMomentum_CT,Efficiency_LambdaMomentum_CT,";True #Lambda Momentum (GeV/c,Mode,POT);Events",label + "_LambdaMomentum_CT",Mode,POT);
      DrawEfficiencyPlot(h_DecayProtonMomentum_CT,h_SelectedDecayProtonMomentum_CT,Efficiency_DecayProtonMomentum_CT,";True Decay Proton Momentum (GeV/c,Mode,POT);Events",label + "_DecayProtonMomentum_CT",Mode,POT);
      DrawEfficiencyPlot(h_DecayPionMomentum_CT,h_SelectedDecayPionMomentum_CT,Efficiency_DecayPionMomentum_CT,";True Decay #pi^{-} Momentum (GeV/c,Mode,POT);Events",label + "_DecayPionMomentum_CT",Mode,POT);
      DrawEfficiencyPlot(h_OpeningAngle_CT,h_SelectedOpeningAngle_CT,Efficiency_OpeningAngle_CT,";True Opening Angle (deg,Mode,POT);Events",label + "_OpeningAngle_CT",Mode,POT);
      DrawEfficiencyPlot(h_LambdaRange_CT,h_SelectedLambdaRange_CT,Efficiency_LambdaRange_CT,";True #Lambda Range (cm,Mode,POT);Events",label + "_LambdaRange_CT",Mode,POT);
      DrawEfficiencyPlot(h_CT,h_Selected_CT,Efficiency_CT,";;Events",label + "_CT",Mode,POT);

      // WCut
      DrawEfficiencyPlot(h_Q2_WCut,h_SelectedQ2_WCut,Efficiency_Q2_WCut,";True Q^{2} (GeV^{2},Mode,POT);Events",label + "_Q2_WCut",Mode,POT);
      DrawEfficiencyPlot(h_NuE_WCut,h_SelectedNuE_WCut,Efficiency_NuE_WCut,";True E_{#nu} (GeV,Mode,POT);Events",label + "_NuE_WCut",Mode,POT);
      DrawEfficiencyPlot(h_MuonKE_WCut,h_SelectedMuonKE_WCut,Efficiency_MuonKE_WCut,";True Muon E_{k} (GeV,Mode,POT);Events",label + "_MuonKE_WCut",Mode,POT);
      DrawEfficiencyPlot(h_MuonTrueTheta_WCut,h_SelectedMuonTrueTheta_WCut,Efficiency_MuonTrueTheta_WCut,";True Muon #theta;Events",label + "_MuonTrueTheta_WCut",Mode,POT);
      DrawEfficiencyPlot(h_MuonDetectorTheta_WCut,h_SelectedMuonDetectorTheta_WCut,Efficiency_MuonDetectorTheta_WCut,";Detector Muon #theta;Events",label + "_MuonDetectorTheta_WCut",Mode,POT);
      DrawEfficiencyPlot(h_MuonDetectorPhi_WCut,h_SelectedMuonDetectorPhi_WCut,Efficiency_MuonDetectorPhi_WCut,";Detector Muon #phi;Events",label + "_MuonDetectorPhi_WCut",Mode,POT);
      DrawEfficiencyPlot(h_MuonBeamTheta_WCut,h_SelectedMuonBeamTheta_WCut,Efficiency_MuonBeamTheta_WCut,";Beam Muon #theta;Events",label + "_MuonBeamTheta_WCut",Mode,POT);
      DrawEfficiencyPlot(h_MuonBeamPhi_WCut,h_SelectedMuonBeamPhi_WCut,Efficiency_MuonBeamPhi_WCut,";Beam Muon #phi;Events",label + "_MuonBeamPhi_WCut",Mode,POT);
      DrawEfficiencyPlot(h_LambdaMomentum_WCut,h_SelectedLambdaMomentum_WCut,Efficiency_LambdaMomentum_WCut,";True #Lambda Momentum (GeV/c,Mode,POT);Events",label + "_LambdaMomentum_WCut",Mode,POT);
      DrawEfficiencyPlot(h_DecayProtonMomentum_WCut,h_SelectedDecayProtonMomentum_WCut,Efficiency_DecayProtonMomentum_WCut,";True Decay Proton Momentum (GeV/c,Mode,POT);Events",label + "_DecayProtonMomentum_WCut",Mode,POT);
      DrawEfficiencyPlot(h_DecayPionMomentum_WCut,h_SelectedDecayPionMomentum_WCut,Efficiency_DecayPionMomentum_WCut,";True Decay #pi^{-} Momentum (GeV/c,Mode,POT);Events",label + "_DecayPionMomentum_WCut",Mode,POT);
      DrawEfficiencyPlot(h_OpeningAngle_WCut,h_SelectedOpeningAngle_WCut,Efficiency_OpeningAngle_WCut,";True Opening Angle (deg,Mode,POT);Events",label + "_OpeningAngle_WCut",Mode,POT);
      DrawEfficiencyPlot(h_LambdaRange_WCut,h_SelectedLambdaRange_WCut,Efficiency_LambdaRange_WCut,";True #Lambda Range (cm,Mode,POT);Events",label + "_LambdaRange_WCut",Mode,POT);
      DrawEfficiencyPlot(h_WCut,h_Selected_WCut,Efficiency_WCut,";;Events",label + "_WCut",Mode,POT);

      // AngleCut
      DrawEfficiencyPlot(h_Q2_AngleCut,h_SelectedQ2_AngleCut,Efficiency_Q2_AngleCut,";True Q^{2} (GeV^{2},Mode,POT);Events",label + "_Q2_AngleCut",Mode,POT);
      DrawEfficiencyPlot(h_NuE_AngleCut,h_SelectedNuE_AngleCut,Efficiency_NuE_AngleCut,";True E_{#nu} (GeV,Mode,POT);Events",label + "_NuE_AngleCut",Mode,POT);
      DrawEfficiencyPlot(h_MuonKE_AngleCut,h_SelectedMuonKE_AngleCut,Efficiency_MuonKE_AngleCut,";True Muon E_{k} (GeV,Mode,POT);Events",label + "_MuonKE_AngleCut",Mode,POT);
      DrawEfficiencyPlot(h_MuonTrueTheta_AngleCut,h_SelectedMuonTrueTheta_AngleCut,Efficiency_MuonTrueTheta_AngleCut,";True Muon #theta;Events",label + "_MuonTrueTheta_AngleCut",Mode,POT);
      DrawEfficiencyPlot(h_MuonDetectorTheta_AngleCut,h_SelectedMuonDetectorTheta_AngleCut,Efficiency_MuonDetectorTheta_AngleCut,";Detector Muon #theta;Events",label + "_MuonDetectorTheta_AngleCut",Mode,POT);
      DrawEfficiencyPlot(h_MuonDetectorPhi_AngleCut,h_SelectedMuonDetectorPhi_AngleCut,Efficiency_MuonDetectorPhi_AngleCut,";Detector Muon #phi;Events",label + "_MuonDetectorPhi_AngleCut",Mode,POT);
      DrawEfficiencyPlot(h_MuonBeamTheta_AngleCut,h_SelectedMuonBeamTheta_AngleCut,Efficiency_MuonBeamTheta_AngleCut,";Beam Muon #theta;Events",label + "_MuonBeamTheta_AngleCut",Mode,POT);
      DrawEfficiencyPlot(h_MuonBeamPhi_AngleCut,h_SelectedMuonBeamPhi_AngleCut,Efficiency_MuonBeamPhi_AngleCut,";Beam Muon #phi;Events",label + "_MuonBeamPhi_AngleCut",Mode,POT);
      DrawEfficiencyPlot(h_LambdaMomentum_AngleCut,h_SelectedLambdaMomentum_AngleCut,Efficiency_LambdaMomentum_AngleCut,";True #Lambda Momentum (GeV/c,Mode,POT);Events",label + "_LambdaMomentum_AngleCut",Mode,POT);
      DrawEfficiencyPlot(h_DecayProtonMomentum_AngleCut,h_SelectedDecayProtonMomentum_AngleCut,Efficiency_DecayProtonMomentum_AngleCut,";True Decay Proton Momentum (GeV/c,Mode,POT);Events",label + "_DecayProtonMomentum_AngleCut",Mode,POT);
      DrawEfficiencyPlot(h_DecayPionMomentum_AngleCut,h_SelectedDecayPionMomentum_AngleCut,Efficiency_DecayPionMomentum_AngleCut,";True Decay #pi^{-} Momentum (GeV/c,Mode,POT);Events",label + "_DecayPionMomentum_AngleCut",Mode,POT);
      DrawEfficiencyPlot(h_OpeningAngle_AngleCut,h_SelectedOpeningAngle_AngleCut,Efficiency_OpeningAngle_AngleCut,";True Opening Angle (deg,Mode,POT);Events",label + "_OpeningAngle_AngleCut",Mode,POT);
      DrawEfficiencyPlot(h_LambdaRange_AngleCut,h_SelectedLambdaRange_AngleCut,Efficiency_LambdaRange_AngleCut,";True #Lambda Range (cm,Mode,POT);Events",label + "_LambdaRange_AngleCut",Mode,POT);
      DrawEfficiencyPlot(h_AngleCut,h_Selected_AngleCut,Efficiency_AngleCut,";;Events",label + "_AngleCut",Mode,POT);
   }

