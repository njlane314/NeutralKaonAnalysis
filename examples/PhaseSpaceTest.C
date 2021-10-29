R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so)

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
      ImportSamples(sNuWroFullFHC);

      std::string label = "NuWro_FHC";

      double POT = 1e21; // POT to scale samples to
      std::string Mode = "FHC";

      SelectionParameters P = P_FHC_Tune_325;

      // Setup selection manager. Set POT to scale sample to
      EventAssembler E;
      SelectionManager M(P);
      M.SetPOT(POT);
      M.ImportSelectorBDTWeights(P.p_SelectorBDT_WeightsDir);
      M.ImportAnalysisBDTWeights(P.p_AnalysisBDT_WeightsDir);

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

      // Subleading Track Lengths //

      TH1D *h_Q2_TrackLengths = new TH1D("h_Q2_TrackLengths","",60,0,3.0);
      TH1D *h_SelectedQ2_TrackLengths = new TH1D("h_SelectedQ2_TrackLengths","",60,0,3.0);
      TEfficiency* Efficiency_Q2_TrackLengths = new TEfficiency("Q2_eff_TrackLengths",";True Q^{2} (GeV^{2});Selected/All",60,0,3.0);

      TH1D *h_NuE_TrackLengths = new TH1D("h_TrueNuE_TrackLengths","",60,0,4.0);
      TH1D *h_SelectedNuE_TrackLengths = new TH1D("h_SelectedNuE_TrackLengths","",60,0,4.0);
      TEfficiency* Efficiency_NuE_TrackLengths = new TEfficiency("NuE_eff_TrackLengths",";True E_{#nu} (GeV);Selected/All",60,0,4.0);

      TH1D *h_MuonKE_TrackLengths = new TH1D("h_MuonKE_TrackLengths","",60,0,3.0);
      TH1D *h_SelectedMuonKE_TrackLengths = new TH1D("h_SelectedMuonKE_TrackLengths","",60,0,3.0);
      TEfficiency* Efficiency_MuonKE_TrackLengths = new TEfficiency("MuonKE_eff_TrackLengths",";True Muon KE (GeV);Selected/All",60,0,3.0);

      TH1D *h_MuonTrueTheta_TrackLengths = new TH1D("h_MuonTrueTheta_TrackLengths","",60,0,3.1415);
      TH1D *h_SelectedMuonTrueTheta_TrackLengths = new TH1D("h_SelectedMuonTrueTheta_TrackLengths","",60,0,3.1415);
      TEfficiency* Efficiency_MuonTrueTheta_TrackLengths = new TEfficiency("MuonTrueTheta_eff_TrackLengths",";Muon True #theta;Selected/All",60,0,3.1415);

      TH1D *h_MuonDetectorTheta_TrackLengths = new TH1D("h_TrueMuonDetectorTheta_TrackLengths","",60,0,3.1415);
      TH1D *h_SelectedMuonDetectorTheta_TrackLengths = new TH1D("h_SelectedMuonDetectorTheta_TrackLengths","",60,0,3.1415);
      TEfficiency* Efficiency_MuonDetectorTheta_TrackLengths = new TEfficiency("MuonDetectorTheta_eff",";Muon Detector #theta;Selected/All",60,0,3.1415);

      TH1D *h_MuonDetectorPhi_TrackLengths = new TH1D("h_TrueMuonDetectorPhi_TrackLengths","",60,-3.1415,3.1415);
      TH1D *h_SelectedMuonDetectorPhi_TrackLengths = new TH1D("h_SelectedMuonDetectorPhi_TrackLengths","",60,-3.1415,3.1415);
      TEfficiency* Efficiency_MuonDetectorPhi_TrackLengths = new TEfficiency("MuonDetectorPhi_eff_TrackLengths",";Muon Detector #theta;Selected/All",60,-3.1415,3.1415);

      TH1D *h_MuonBeamTheta_TrackLengths = new TH1D("h_TrueMuonBeamTheta_TrackLengths","",60,0,3.1415);
      TH1D *h_SelectedMuonBeamTheta_TrackLengths = new TH1D("h_SelectedMuonBeamTheta_TrackLengths","",60,0,3.1415);
      TEfficiency* Efficiency_MuonBeamTheta_TrackLengths = new TEfficiency("MuonBeamTheta_eff_TrackLengths",";Muon Beam #theta;Selected/All",60,0,3.1415);

      TH1D *h_MuonBeamPhi_TrackLengths = new TH1D("h_TrueMuonBeamPhi_TrackLengths","",60,-3.1415,3.1415);
      TH1D *h_SelectedMuonBeamPhi_TrackLengths = new TH1D("h_SelectedMuonBeamPhi_TrackLengths","",60,-3.1415,3.1415);
      TEfficiency* Efficiency_MuonBeamPhi_TrackLengths = new TEfficiency("MuonBeamPhi_eff_TrackLengths",";Muon Beam #theta;Selected/All",60,-3.1415,3.1415);

      TH1D *h_LambdaMomentum_TrackLengths = new TH1D("h_TrueLambdaMomentum_TrackLengths","",60,0.0,2.0);
      TH1D *h_SelectedLambdaMomentum_TrackLengths = new TH1D("h_SelectedLambdaMomentum_TrackLengths","",60,0.0,2.0);
      TEfficiency* Efficiency_LambdaMomentum_TrackLengths = new TEfficiency("LambdaMomentum_eff_TrackLengths",";True #Lambda Momentum (GeV/c);Selected/All",60,0.0,2.0);

      TH1D *h_TrackLengths = new TH1D("h_TrackLengths","",1,0,1.0);
      TH1D *h_Selected_TrackLengths = new TH1D("h_Selected_TrackLengths","",1,0,1.0);
      TEfficiency* Efficiency_TrackLengths = new TEfficiency("eff_TrackLengths",";;Selected/All",1,0,1.0);

      TH1D *h_DecayProtonMomentum_TrackLengths = new TH1D("h_TrueDecayProtonMomentum_TrackLengths","",60,0.3,1.5);
      TH1D *h_SelectedDecayProtonMomentum_TrackLengths = new TH1D("h_SelectedDecayProtonMomentum_TrackLengths","",60,0.3,1.5);
      TEfficiency* Efficiency_DecayProtonMomentum_TrackLengths = new TEfficiency("DecayProtonMomentum_eff_TrackLengths",";True Decay Proton Momentum (GeV/c);Selected/All",60,0.3,1.5);

      TH1D *h_OpeningAngle_TrackLengths = new TH1D("h_OpeningAngle_TrackLengths","",60,0,100);
      TH1D *h_SelectedOpeningAngle_TrackLengths = new TH1D("h_SelectedOpeningAngle_TrackLengths","",60,0,100);
      TEfficiency* Efficiency_OpeningAngle_TrackLengths = new TEfficiency("OpeningAngle_eff_TrackLengths",";True Opening Angle (deg);Selected/All",60,0,100);

      TH1D *h_LambdaRange_TrackLengths = new TH1D("h_LambdaRange_TrackLengths","",100,0,20.0);
      TH1D *h_SelectedLambdaRange_TrackLengths = new TH1D("h_SelectedLambdaRange_TrackLengths","",100,0,20.0);
      TEfficiency* Efficiency_LambdaRange_TrackLengths = new TEfficiency("LambdaRange_eff_TrackLengths",";True #Lambda Range (cm);Selected/All",100,0,20.0);

      TH1D *h_DecayPionMomentum_TrackLengths = new TH1D("h_TrueDecayPionMomentum_TrackLengths","",60,0.1,0.8);
      TH1D *h_SelectedDecayPionMomentum_TrackLengths = new TH1D("h_SelectedDecayPionMomentum_TrackLengths","",60,0.1,0.8);
      TEfficiency* Efficiency_DecayPionMomentum_TrackLengths = new TEfficiency("DecayPionMomentum_eff_TrackLengths",";True Decay #pi^{-} Momentum (GeV/c);Selected/All",60,0.1,0.8);

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

      // Analysis BDT //

      TH1D *h_Q2_Analysis = new TH1D("h_Q2_Analysis","",60,0,3.0);
      TH1D *h_SelectedQ2_Analysis = new TH1D("h_SelectedQ2_Analysis","",60,0,3.0);
      TEfficiency* Efficiency_Q2_Analysis = new TEfficiency("Q2_eff_Analysis",";True Q^{2} (GeV^{2});Selected/All",60,0,3.0);

      TH1D *h_NuE_Analysis = new TH1D("h_TrueNuE_Analysis","",60,0,4.0);
      TH1D *h_SelectedNuE_Analysis = new TH1D("h_SelectedNuE_Analysis","",60,0,4.0);
      TEfficiency* Efficiency_NuE_Analysis = new TEfficiency("NuE_eff_Analysis",";True E_{#nu} (GeV);Selected/All",60,0,4.0);

      TH1D *h_MuonKE_Analysis = new TH1D("h_MuonKE_Analysis","",60,0,3.0);
      TH1D *h_SelectedMuonKE_Analysis = new TH1D("h_SelectedMuonKE_Analysis","",60,0,3.0);
      TEfficiency* Efficiency_MuonKE_Analysis = new TEfficiency("MuonKE_eff_Analysis",";True Muon KE (GeV);Selected/All",60,0,3.0);

      TH1D *h_MuonTrueTheta_Analysis = new TH1D("h_MuonTrueTheta_Analysis","",60,0,3.1415);
      TH1D *h_SelectedMuonTrueTheta_Analysis = new TH1D("h_SelectedMuonTrueTheta_Analysis","",60,0,3.1415);
      TEfficiency* Efficiency_MuonTrueTheta_Analysis = new TEfficiency("MuonTrueTheta_eff_Analysis",";Muon True #theta;Selected/All",60,0,3.1415);

      TH1D *h_MuonDetectorTheta_Analysis = new TH1D("h_TrueMuonDetectorTheta_Analysis","",60,0,3.1415);
      TH1D *h_SelectedMuonDetectorTheta_Analysis = new TH1D("h_SelectedMuonDetectorTheta_Analysis","",60,0,3.1415);
      TEfficiency* Efficiency_MuonDetectorTheta_Analysis = new TEfficiency("MuonDetectorTheta_eff",";Muon Detector #theta;Selected/All",60,0,3.1415);

      TH1D *h_MuonDetectorPhi_Analysis = new TH1D("h_TrueMuonDetectorPhi_Analysis","",60,-3.1415,3.1415);
      TH1D *h_SelectedMuonDetectorPhi_Analysis = new TH1D("h_SelectedMuonDetectorPhi_Analysis","",60,-3.1415,3.1415);
      TEfficiency* Efficiency_MuonDetectorPhi_Analysis = new TEfficiency("MuonDetectorPhi_eff_Analysis",";Muon Detector #theta;Selected/All",60,-3.1415,3.1415);

      TH1D *h_MuonBeamTheta_Analysis = new TH1D("h_TrueMuonBeamTheta_Analysis","",60,0,3.1415);
      TH1D *h_SelectedMuonBeamTheta_Analysis = new TH1D("h_SelectedMuonBeamTheta_Analysis","",60,0,3.1415);
      TEfficiency* Efficiency_MuonBeamTheta_Analysis = new TEfficiency("MuonBeamTheta_eff_Analysis",";Muon Beam #theta;Selected/All",60,0,3.1415);

      TH1D *h_MuonBeamPhi_Analysis = new TH1D("h_TrueMuonBeamPhi_Analysis","",60,-3.1415,3.1415);
      TH1D *h_SelectedMuonBeamPhi_Analysis = new TH1D("h_SelectedMuonBeamPhi_Analysis","",60,-3.1415,3.1415);
      TEfficiency* Efficiency_MuonBeamPhi_Analysis = new TEfficiency("MuonBeamPhi_eff_Analysis",";Muon Beam #theta;Selected/All",60,-3.1415,3.1415);

      TH1D *h_LambdaMomentum_Analysis = new TH1D("h_TrueLambdaMomentum_Analysis","",60,0.0,2.0);
      TH1D *h_SelectedLambdaMomentum_Analysis = new TH1D("h_SelectedLambdaMomentum_Analysis","",60,0.0,2.0);
      TEfficiency* Efficiency_LambdaMomentum_Analysis = new TEfficiency("LambdaMomentum_eff_Analysis",";True #Lambda Momentum (GeV/c);Selected/All",60,0.0,2.0);

      TH1D *h_DecayProtonMomentum_Analysis = new TH1D("h_TrueDecayProtonMomentum_Analysis","",60,0.3,1.5);
      TH1D *h_SelectedDecayProtonMomentum_Analysis = new TH1D("h_SelectedDecayProtonMomentum_Analysis","",60,0.3,1.5);
      TEfficiency* Efficiency_DecayProtonMomentum_Analysis = new TEfficiency("DecayProtonMomentum_eff_Analysis",";True Decay Proton Momentum (GeV/c);Selected/All",60,0.3,1.5);

      TH1D *h_DecayPionMomentum_Analysis = new TH1D("h_TrueDecayPionMomentum_Analysis","",60,0.1,0.8);
      TH1D *h_SelectedDecayPionMomentum_Analysis = new TH1D("h_SelectedDecayPionMomentum_Analysis","",60,0.1,0.8);
      TEfficiency* Efficiency_DecayPionMomentum_Analysis = new TEfficiency("DecayPionMomentum_eff_Analysis",";True Decay #pi^{-} Momentum (GeV/c);Selected/All",60,0.1,0.8);

      TH1D *h_OpeningAngle_Analysis = new TH1D("h_OpeningAngle_Analysis","",60,0,100);
      TH1D *h_SelectedOpeningAngle_Analysis = new TH1D("h_SelectedOpeningAngle_Analysis","",60,0,100);
      TEfficiency* Efficiency_OpeningAngle_Analysis = new TEfficiency("OpeningAngle_eff_Analysis",";True Opening Angle (deg);Selected/All",60,0,100);

      TH1D *h_LambdaRange_Analysis = new TH1D("h_LambdaRange_Analysis","",100,0,20.0);
      TH1D *h_SelectedLambdaRange_Analysis = new TH1D("h_SelectedLambdaRange_Analysis","",100,0,20.0);
      TEfficiency* Efficiency_LambdaRange_Analysis = new TEfficiency("LambdaRange_eff_Analysis",";True #Lambda Range (cm);Selected/All",100,0,20.0);

      TH1D *h_Analysis = new TH1D("h_Analysis","",1,0,1.0);
      TH1D *h_Selected_Analysis = new TH1D("h_Selected_Analysis","",1,0,1.0);
      TEfficiency* Efficiency_Analysis = new TEfficiency("eff_Analysis",";;Selected/All",1,0,1.0);

      // Connectedness Test //

      TH1D *h_Q2_Connectedness = new TH1D("h_Q2_Connectedness","",60,0,3.0);
      TH1D *h_SelectedQ2_Connectedness = new TH1D("h_SelectedQ2_Connectedness","",60,0,3.0);
      TEfficiency* Efficiency_Q2_Connectedness = new TEfficiency("Q2_eff_Connectedness",";True Q^{2} (GeV^{2});Selected/All",60,0,3.0);

      TH1D *h_NuE_Connectedness = new TH1D("h_TrueNuE_Connectedness","",60,0,4.0);
      TH1D *h_SelectedNuE_Connectedness = new TH1D("h_SelectedNuE_Connectedness","",60,0,4.0);
      TEfficiency* Efficiency_NuE_Connectedness = new TEfficiency("NuE_eff_Connectedness",";True E_{#nu} (GeV);Selected/All",60,0,4.0);

      TH1D *h_MuonKE_Connectedness = new TH1D("h_MuonKE_Connectedness","",60,0,3.0);
      TH1D *h_SelectedMuonKE_Connectedness = new TH1D("h_SelectedMuonKE_Connectedness","",60,0,3.0);
      TEfficiency* Efficiency_MuonKE_Connectedness = new TEfficiency("MuonKE_eff_Connectedness",";True Muon KE (GeV);Selected/All",60,0,3.0);

      TH1D *h_MuonTrueTheta_Connectedness = new TH1D("h_MuonTrueTheta_Connectedness","",60,0,3.1415);
      TH1D *h_SelectedMuonTrueTheta_Connectedness = new TH1D("h_SelectedMuonTrueTheta_Connectedness","",60,0,3.1415);
      TEfficiency* Efficiency_MuonTrueTheta_Connectedness = new TEfficiency("MuonTrueTheta_eff_Connectedness",";Muon True #theta;Selected/All",60,0,3.1415);

      TH1D *h_MuonDetectorTheta_Connectedness = new TH1D("h_TrueMuonDetectorTheta_Connectedness","",60,0,3.1415);
      TH1D *h_SelectedMuonDetectorTheta_Connectedness = new TH1D("h_SelectedMuonDetectorTheta_Connectedness","",60,0,3.1415);
      TEfficiency* Efficiency_MuonDetectorTheta_Connectedness = new TEfficiency("MuonDetectorTheta_eff",";Muon Detector #theta;Selected/All",60,0,3.1415);

      TH1D *h_MuonDetectorPhi_Connectedness = new TH1D("h_TrueMuonDetectorPhi_Connectedness","",60,-3.1415,3.1415);
      TH1D *h_SelectedMuonDetectorPhi_Connectedness = new TH1D("h_SelectedMuonDetectorPhi_Connectedness","",60,-3.1415,3.1415);
      TEfficiency* Efficiency_MuonDetectorPhi_Connectedness = new TEfficiency("MuonDetectorPhi_eff_Connectedness",";Muon Detector #theta;Selected/All",60,-3.1415,3.1415);

      TH1D *h_MuonBeamTheta_Connectedness = new TH1D("h_TrueMuonBeamTheta_Connectedness","",60,0,3.1415);
      TH1D *h_SelectedMuonBeamTheta_Connectedness = new TH1D("h_SelectedMuonBeamTheta_Connectedness","",60,0,3.1415);
      TEfficiency* Efficiency_MuonBeamTheta_Connectedness = new TEfficiency("MuonBeamTheta_eff_Connectedness",";Muon Beam #theta;Selected/All",60,0,3.1415);

      TH1D *h_MuonBeamPhi_Connectedness = new TH1D("h_TrueMuonBeamPhi_Connectedness","",60,-3.1415,3.1415);
      TH1D *h_SelectedMuonBeamPhi_Connectedness = new TH1D("h_SelectedMuonBeamPhi_Connectedness","",60,-3.1415,3.1415);
      TEfficiency* Efficiency_MuonBeamPhi_Connectedness = new TEfficiency("MuonBeamPhi_eff_Connectedness",";Muon Beam #theta;Selected/All",60,-3.1415,3.1415);

      TH1D *h_LambdaMomentum_Connectedness = new TH1D("h_TrueLambdaMomentum_Connectedness","",60,0.0,2.0);
      TH1D *h_SelectedLambdaMomentum_Connectedness = new TH1D("h_SelectedLambdaMomentum_Connectedness","",60,0.0,2.0);
      TEfficiency* Efficiency_LambdaMomentum_Connectedness = new TEfficiency("LambdaMomentum_eff_Connectedness",";True #Lambda Momentum (GeV/c);Selected/All",60,0.0,2.0);

      TH1D *h_DecayProtonMomentum_Connectedness = new TH1D("h_TrueDecayProtonMomentum_Connectedness","",60,0.3,1.5);
      TH1D *h_SelectedDecayProtonMomentum_Connectedness = new TH1D("h_SelectedDecayProtonMomentum_Connectedness","",60,0.3,1.5);
      TEfficiency* Efficiency_DecayProtonMomentum_Connectedness = new TEfficiency("DecayProtonMomentum_eff_Connectedness",";True Decay Proton Momentum (GeV/c);Selected/All",60,0.3,1.5);

      TH1D *h_DecayPionMomentum_Connectedness = new TH1D("h_TrueDecayPionMomentum_Connectedness","",60,0.1,0.8);
      TH1D *h_SelectedDecayPionMomentum_Connectedness = new TH1D("h_SelectedDecayPionMomentum_Connectedness","",60,0.1,0.8);
      TEfficiency* Efficiency_DecayPionMomentum_Connectedness = new TEfficiency("DecayPionMomentum_eff_Connectedness",";True Decay #pi^{-} Momentum (GeV/c);Selected/All",60,0.1,0.8);

      TH1D *h_OpeningAngle_Connectedness = new TH1D("h_OpeningAngle_Connectedness","",60,0,100);
      TH1D *h_SelectedOpeningAngle_Connectedness = new TH1D("h_SelectedOpeningAngle_Connectedness","",60,0,100);
      TEfficiency* Efficiency_OpeningAngle_Connectedness = new TEfficiency("OpeningAngle_eff_Connectedness",";True Opening Angle (deg);Selected/All",60,0,100);

      TH1D *h_LambdaRange_Connectedness = new TH1D("h_LambdaRange_Connectedness","",100,0,20.0);
      TH1D *h_SelectedLambdaRange_Connectedness = new TH1D("h_SelectedLambdaRange_Connectedness","",100,0,20.0);
      TEfficiency* Efficiency_LambdaRange_Connectedness = new TEfficiency("LambdaRange_eff_Connectedness",";True #Lambda Range (cm);Selected/All",100,0,20.0);

      TH1D *h_Connectedness = new TH1D("h_Connectedness","",1,0,1.0);
      TH1D *h_Selected_Connectedness = new TH1D("h_Selected_Connectedness","",1,0,1.0);
      TEfficiency* Efficiency_Connectedness = new TEfficiency("eff_Connectedness",";;Selected/All",1,0,1.0);

      /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

      // Iterate over the samples. 
      for(size_t i_s=0;i_s<SampleNames.size();i_s++){

         E.SetFile(SampleFiles.at(i_s));
         if(SampleTypes.at(i_s) != "EXT" && SampleTypes.at(i_s) != "Data") M.AddSample(SampleNames.at(i_s),SampleTypes.at(i_s),E.GetPOT(),EventLists.at(i_s));
         else if(SampleTypes.at(i_s) == "Data") M.AddSample(SampleNames.at(i_s),SampleTypes.at(i_s),Data_POT,EventLists.at(i_s));
         else if(SampleTypes.at(i_s) == "EXT") M.AddSample(SampleNames.at(i_s),SampleTypes.at(i_s),EXT_POT,EventLists.at(i_s));

         for(int i=0;i<E.GetNEvents();i++){

            //get an event
            Event e = E.GetEvent(i);

            if((SampleTypes.at(i_s) == "Background" || SampleTypes.at(i_s) == "Hyperon") && e.NMCTruths > 1) continue;
            if(SampleTypes.at(i_s) == "Background" && e.Mode == "HYP") continue;
            if(SampleTypes.at(i_s) == "Hyperon" && e.Mode != "HYP") continue;

            M.SetSignal(e);

            if(!e.IsSignal) continue;

            //update metadata
            M.AddEvent(e);

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

            bool passed_FV=false,passed_Tracks=false,passed_Showers=false,passed_MuonID=false,passed_TrackLengths=false,passed_Selector=false,passed_Analysis=false,passed_Connectedness=false,passed_All=false;

            passed_FV = M.FiducialVolumeCut(e);
            if(passed_FV) passed_Tracks = M.TrackCut(e);
            if(passed_Tracks) passed_Showers = M.ShowerCut(e);
            if(passed_Showers) passed_MuonID = M.ChooseMuonCandidate(e);
            if(passed_MuonID) passed_TrackLengths = M.TrackLengthCut(e);
            if(passed_TrackLengths) passed_Selector = M.ChooseProtonPionCandidates(e); 
            if(passed_Selector) passed_Analysis = M.AnalysisBDTCut(e);
            if(passed_Analysis) passed_Connectedness = M.EventListCut(e);
            if(passed_Connectedness) passed_All = true;

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

            // Subleading Track Length Cut
            h_Q2_TrackLengths->Fill(Q2,e.Weight);
            Efficiency_Q2_TrackLengths->FillWeighted(passed_TrackLengths,e.Weight,Q2);
            if(Q2 > 0 && passed_TrackLengths) h_SelectedQ2_TrackLengths->Fill(Q2,e.Weight);

            h_NuE_TrackLengths->Fill(NuE,e.Weight); 
            Efficiency_NuE_TrackLengths->FillWeighted(passed_TrackLengths,e.Weight,NuE);
            if(NuE > 0 && passed_TrackLengths)  h_SelectedNuE_TrackLengths->Fill(NuE,e.Weight);

            h_MuonKE_TrackLengths->Fill(MuonKE,e.Weight); 
            Efficiency_MuonKE_TrackLengths->FillWeighted(passed_TrackLengths,e.Weight,MuonKE);
            if(MuonKE > 0 && passed_TrackLengths)  h_SelectedMuonKE_TrackLengths->Fill(MuonKE,e.Weight);

            h_MuonTrueTheta_TrackLengths->Fill(MuonTrueTheta,e.Weight); 
            Efficiency_MuonTrueTheta_TrackLengths->FillWeighted(passed_TrackLengths,e.Weight,MuonTrueTheta);
            if(passed_TrackLengths)  h_SelectedMuonTrueTheta_TrackLengths->Fill(MuonTrueTheta,e.Weight);

            h_MuonDetectorTheta_TrackLengths->Fill(MuonDetectorTheta,e.Weight); 
            Efficiency_MuonDetectorTheta_TrackLengths->FillWeighted(passed_TrackLengths,e.Weight,MuonDetectorTheta);
            if(passed_TrackLengths)  h_SelectedMuonDetectorTheta_TrackLengths->Fill(MuonDetectorTheta,e.Weight);

            h_MuonDetectorPhi_TrackLengths->Fill(MuonDetectorPhi,e.Weight); 
            Efficiency_MuonDetectorPhi_TrackLengths->FillWeighted(passed_TrackLengths,e.Weight,MuonDetectorPhi);
            if(passed_TrackLengths)  h_SelectedMuonDetectorPhi_TrackLengths->Fill(MuonDetectorPhi,e.Weight);

            h_MuonBeamTheta_TrackLengths->Fill(MuonBeamTheta,e.Weight); 
            Efficiency_MuonBeamTheta_TrackLengths->FillWeighted(passed_TrackLengths,e.Weight,MuonBeamTheta);
            if(passed_TrackLengths)  h_SelectedMuonBeamTheta_TrackLengths->Fill(MuonBeamTheta,e.Weight);

            h_MuonBeamPhi_TrackLengths->Fill(MuonBeamPhi,e.Weight); 
            Efficiency_MuonBeamPhi_TrackLengths->FillWeighted(passed_TrackLengths,e.Weight,MuonBeamPhi);
            if(passed_TrackLengths)  h_SelectedMuonBeamPhi_TrackLengths->Fill(MuonBeamPhi,e.Weight);

            h_LambdaMomentum_TrackLengths->Fill(LambdaMomentum,e.Weight); 
            Efficiency_LambdaMomentum_TrackLengths->FillWeighted(passed_TrackLengths,e.Weight,LambdaMomentum);
            if(passed_TrackLengths)  h_SelectedLambdaMomentum_TrackLengths->Fill(LambdaMomentum,e.Weight);

            h_DecayProtonMomentum_TrackLengths->Fill(DecayProtonMomentum,e.Weight); 
            Efficiency_DecayProtonMomentum_TrackLengths->FillWeighted(passed_TrackLengths,e.Weight,DecayProtonMomentum);
            if(passed_TrackLengths)  h_SelectedDecayProtonMomentum_TrackLengths->Fill(DecayProtonMomentum,e.Weight);

            h_DecayPionMomentum_TrackLengths->Fill(DecayPionMomentum,e.Weight); 
            Efficiency_DecayPionMomentum_TrackLengths->FillWeighted(passed_TrackLengths,e.Weight,DecayPionMomentum);
            if(passed_TrackLengths)  h_SelectedDecayPionMomentum_TrackLengths->Fill(DecayPionMomentum,e.Weight);

            h_OpeningAngle_TrackLengths->Fill(OpeningAngle,e.Weight);
            Efficiency_OpeningAngle_TrackLengths->FillWeighted(passed_TrackLengths,e.Weight,OpeningAngle);
            if(OpeningAngle > 0 && passed_TrackLengths) h_SelectedOpeningAngle_TrackLengths->Fill(OpeningAngle,e.Weight);

            h_LambdaRange_TrackLengths->Fill(LambdaRange,e.Weight);
            Efficiency_LambdaRange_TrackLengths->FillWeighted(passed_TrackLengths,e.Weight,LambdaRange);
            if(LambdaRange > 0 && passed_TrackLengths) h_SelectedLambdaRange_TrackLengths->Fill(LambdaRange,e.Weight);

            h_TrackLengths->Fill(0.5,e.Weight);
            Efficiency_TrackLengths->FillWeighted(passed_TrackLengths,e.Weight,0.5);
            if(passed_TrackLengths) h_Selected_TrackLengths->Fill(0.5,e.Weight);

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

            // Decay Analysis
            h_Q2_Analysis->Fill(Q2,e.Weight);
            Efficiency_Q2_Analysis->FillWeighted(passed_Analysis,e.Weight,Q2);
            if(Q2 > 0 && passed_Analysis) h_SelectedQ2_Analysis->Fill(Q2,e.Weight);

            h_NuE_Analysis->Fill(NuE,e.Weight); 
            Efficiency_NuE_Analysis->FillWeighted(passed_Analysis,e.Weight,NuE);
            if(NuE > 0 && passed_Analysis)  h_SelectedNuE_Analysis->Fill(NuE,e.Weight);

            h_MuonKE_Analysis->Fill(MuonKE,e.Weight); 
            Efficiency_MuonKE_Analysis->FillWeighted(passed_Analysis,e.Weight,MuonKE);
            if(MuonKE > 0 && passed_Analysis)  h_SelectedMuonKE_Analysis->Fill(MuonKE,e.Weight);

            h_MuonTrueTheta_Analysis->Fill(MuonTrueTheta,e.Weight); 
            Efficiency_MuonTrueTheta_Analysis->FillWeighted(passed_Analysis,e.Weight,MuonTrueTheta);
            if(passed_Analysis)  h_SelectedMuonTrueTheta_Analysis->Fill(MuonTrueTheta,e.Weight);

            h_MuonDetectorTheta_Analysis->Fill(MuonDetectorTheta,e.Weight); 
            Efficiency_MuonDetectorTheta_Analysis->FillWeighted(passed_Analysis,e.Weight,MuonDetectorTheta);
            if(passed_Analysis)  h_SelectedMuonDetectorTheta_Analysis->Fill(MuonDetectorTheta,e.Weight);

            h_MuonDetectorPhi_Analysis->Fill(MuonDetectorPhi,e.Weight); 
            Efficiency_MuonDetectorPhi_Analysis->FillWeighted(passed_Analysis,e.Weight,MuonDetectorPhi);
            if(passed_Analysis)  h_SelectedMuonDetectorPhi_Analysis->Fill(MuonDetectorPhi,e.Weight);

            h_MuonBeamTheta_Analysis->Fill(MuonBeamTheta,e.Weight); 
            Efficiency_MuonBeamTheta_Analysis->FillWeighted(passed_Analysis,e.Weight,MuonBeamTheta);
            if(passed_Analysis)  h_SelectedMuonBeamTheta_Analysis->Fill(MuonBeamTheta,e.Weight);

            h_MuonBeamPhi_Analysis->Fill(MuonBeamPhi,e.Weight); 
            Efficiency_MuonBeamPhi_Analysis->FillWeighted(passed_Analysis,e.Weight,MuonBeamPhi);
            if(passed_Analysis)  h_SelectedMuonBeamPhi_Analysis->Fill(MuonBeamPhi,e.Weight);

            h_LambdaMomentum_Analysis->Fill(LambdaMomentum,e.Weight); 
            Efficiency_LambdaMomentum_Analysis->FillWeighted(passed_Analysis,e.Weight,LambdaMomentum);
            if(passed_Analysis)  h_SelectedLambdaMomentum_Analysis->Fill(LambdaMomentum,e.Weight);

            h_DecayProtonMomentum_Analysis->Fill(DecayProtonMomentum,e.Weight); 
            Efficiency_DecayProtonMomentum_Analysis->FillWeighted(passed_Analysis,e.Weight,DecayProtonMomentum);
            if(passed_Analysis)  h_SelectedDecayProtonMomentum_Analysis->Fill(DecayProtonMomentum,e.Weight);

            h_DecayPionMomentum_Analysis->Fill(DecayPionMomentum,e.Weight); 
            Efficiency_DecayPionMomentum_Analysis->FillWeighted(passed_Analysis,e.Weight,DecayPionMomentum);
            if(passed_Analysis)  h_SelectedDecayPionMomentum_Analysis->Fill(DecayPionMomentum,e.Weight);

            h_OpeningAngle_Analysis->Fill(OpeningAngle,e.Weight);
            Efficiency_OpeningAngle_Analysis->FillWeighted(passed_Analysis,e.Weight,OpeningAngle);
            if(OpeningAngle > 0 && passed_Analysis) h_SelectedOpeningAngle_Analysis->Fill(OpeningAngle,e.Weight);

            h_LambdaRange_Analysis->Fill(LambdaRange,e.Weight);
            Efficiency_LambdaRange_Analysis->FillWeighted(passed_Analysis,e.Weight,LambdaRange);
            if(LambdaRange > 0 && passed_Analysis) h_SelectedLambdaRange_Analysis->Fill(LambdaRange,e.Weight);

            h_Analysis->Fill(0.5,e.Weight);
            Efficiency_Analysis->FillWeighted(passed_Analysis,e.Weight,0.5);
            if(passed_Analysis) h_Selected_Analysis->Fill(0.5,e.Weight);

            // Connectedness
            h_Q2_Connectedness->Fill(Q2,e.Weight);
            Efficiency_Q2_Connectedness->FillWeighted(passed_Connectedness,e.Weight,Q2);
            if(Q2 > 0 && passed_Connectedness) h_SelectedQ2_Connectedness->Fill(Q2,e.Weight);

            h_NuE_Connectedness->Fill(NuE,e.Weight); 
            Efficiency_NuE_Connectedness->FillWeighted(passed_Connectedness,e.Weight,NuE);
            if(NuE > 0 && passed_Connectedness)  h_SelectedNuE_Connectedness->Fill(NuE,e.Weight);

            h_MuonKE_Connectedness->Fill(MuonKE,e.Weight); 
            Efficiency_MuonKE_Connectedness->FillWeighted(passed_Connectedness,e.Weight,MuonKE);
            if(MuonKE > 0 && passed_Connectedness)  h_SelectedMuonKE_Connectedness->Fill(MuonKE,e.Weight);

            h_MuonTrueTheta_Connectedness->Fill(MuonTrueTheta,e.Weight); 
            Efficiency_MuonTrueTheta_Connectedness->FillWeighted(passed_Connectedness,e.Weight,MuonTrueTheta);
            if(passed_Connectedness)  h_SelectedMuonTrueTheta_Connectedness->Fill(MuonTrueTheta,e.Weight);

            h_MuonDetectorTheta_Connectedness->Fill(MuonDetectorTheta,e.Weight); 
            Efficiency_MuonDetectorTheta_Connectedness->FillWeighted(passed_Connectedness,e.Weight,MuonDetectorTheta);
            if(passed_Connectedness)  h_SelectedMuonDetectorTheta_Connectedness->Fill(MuonDetectorTheta,e.Weight);

            h_MuonDetectorPhi_Connectedness->Fill(MuonDetectorPhi,e.Weight); 
            Efficiency_MuonDetectorPhi_Connectedness->FillWeighted(passed_Connectedness,e.Weight,MuonDetectorPhi);
            if(passed_Connectedness)  h_SelectedMuonDetectorPhi_Connectedness->Fill(MuonDetectorPhi,e.Weight);

            h_MuonBeamTheta_Connectedness->Fill(MuonBeamTheta,e.Weight); 
            Efficiency_MuonBeamTheta_Connectedness->FillWeighted(passed_Connectedness,e.Weight,MuonBeamTheta);
            if(passed_Connectedness)  h_SelectedMuonBeamTheta_Connectedness->Fill(MuonBeamTheta,e.Weight);

            h_MuonBeamPhi_Connectedness->Fill(MuonBeamPhi,e.Weight); 
            Efficiency_MuonBeamPhi_Connectedness->FillWeighted(passed_Connectedness,e.Weight,MuonBeamPhi);
            if(passed_Connectedness)  h_SelectedMuonBeamPhi_Connectedness->Fill(MuonBeamPhi,e.Weight);

            h_LambdaMomentum_Connectedness->Fill(LambdaMomentum,e.Weight); 
            Efficiency_LambdaMomentum_Connectedness->FillWeighted(passed_Connectedness,e.Weight,LambdaMomentum);
            if(passed_Connectedness)  h_SelectedLambdaMomentum_Connectedness->Fill(LambdaMomentum,e.Weight);

            h_DecayProtonMomentum_Connectedness->Fill(DecayProtonMomentum,e.Weight); 
            Efficiency_DecayProtonMomentum_Connectedness->FillWeighted(passed_Connectedness,e.Weight,DecayProtonMomentum);
            if(passed_Connectedness)  h_SelectedDecayProtonMomentum_Connectedness->Fill(DecayProtonMomentum,e.Weight);

            h_DecayPionMomentum_Connectedness->Fill(DecayPionMomentum,e.Weight); 
            Efficiency_DecayPionMomentum_Connectedness->FillWeighted(passed_Connectedness,e.Weight,DecayPionMomentum);
            if(passed_Connectedness)  h_SelectedDecayPionMomentum_Connectedness->Fill(DecayPionMomentum,e.Weight);

            h_OpeningAngle_Connectedness->Fill(OpeningAngle,e.Weight);
            Efficiency_OpeningAngle_Connectedness->FillWeighted(passed_Connectedness,e.Weight,OpeningAngle);
            if(OpeningAngle > 0 && passed_Connectedness) h_SelectedOpeningAngle_Connectedness->Fill(OpeningAngle,e.Weight);

            h_LambdaRange_Connectedness->Fill(LambdaRange,e.Weight);
            Efficiency_LambdaRange_Connectedness->FillWeighted(passed_Connectedness,e.Weight,LambdaRange);
            if(LambdaRange > 0 && passed_Connectedness) h_SelectedLambdaRange_Connectedness->Fill(LambdaRange,e.Weight);

            h_Connectedness->Fill(0.5,e.Weight);
            Efficiency_Connectedness->FillWeighted(passed_Connectedness,e.Weight,0.5);
            if(passed_Connectedness) h_Selected_Connectedness->Fill(0.5,e.Weight);

         }

         //close the event assembler
         E.Close();

      }

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

      // Subleading Track Lengths
      DrawEfficiencyPlot(h_Q2_TrackLengths,h_SelectedQ2_TrackLengths,Efficiency_Q2_TrackLengths,";True Q^{2} (GeV^{2},Mode,POT);Events",label + "_Q2_TrackLengths",Mode,POT);
      DrawEfficiencyPlot(h_NuE_TrackLengths,h_SelectedNuE_TrackLengths,Efficiency_NuE_TrackLengths,";True E_{#nu} (GeV,Mode,POT);Events",label + "_NuE_TrackLengths",Mode,POT);
      DrawEfficiencyPlot(h_MuonKE_TrackLengths,h_SelectedMuonKE_TrackLengths,Efficiency_MuonKE_TrackLengths,";True Muon E_{k} (GeV,Mode,POT);Events",label + "_MuonKE_TrackLengths",Mode,POT);
      DrawEfficiencyPlot(h_MuonTrueTheta_TrackLengths,h_SelectedMuonTrueTheta_TrackLengths,Efficiency_MuonTrueTheta_TrackLengths,";True Muon #theta;Events",label + "_MuonTrueTheta_TrackLengths",Mode,POT);
      DrawEfficiencyPlot(h_MuonDetectorTheta_TrackLengths,h_SelectedMuonDetectorTheta_TrackLengths,Efficiency_MuonDetectorTheta_TrackLengths,";Detector Muon #theta;Events",label + "_MuonDetectorTheta_TrackLengths",Mode,POT);
      DrawEfficiencyPlot(h_MuonDetectorPhi_TrackLengths,h_SelectedMuonDetectorPhi_TrackLengths,Efficiency_MuonDetectorPhi_TrackLengths,";Detector Muon #phi;Events",label + "_MuonDetectorPhi_TrackLengths",Mode,POT);
      DrawEfficiencyPlot(h_MuonBeamTheta_TrackLengths,h_SelectedMuonBeamTheta_TrackLengths,Efficiency_MuonBeamTheta_TrackLengths,";Beam Muon #theta;Events",label + "_MuonBeamTheta_TrackLengths",Mode,POT);
      DrawEfficiencyPlot(h_MuonBeamPhi_TrackLengths,h_SelectedMuonBeamPhi_TrackLengths,Efficiency_MuonBeamPhi_TrackLengths,";Beam Muon #phi;Events",label + "_MuonBeamPhi_TrackLengths",Mode,POT);
      DrawEfficiencyPlot(h_LambdaMomentum_TrackLengths,h_SelectedLambdaMomentum_TrackLengths,Efficiency_LambdaMomentum_TrackLengths,";True #Lambda Momentum (GeV/c,Mode,POT);Events",label + "_LambdaMomentum_TrackLengths",Mode,POT);
      DrawEfficiencyPlot(h_DecayProtonMomentum_TrackLengths,h_SelectedDecayProtonMomentum_TrackLengths,Efficiency_DecayProtonMomentum_TrackLengths,";True Decay Proton Momentum (GeV/c,Mode,POT);Events",label + "_DecayProtonMomentum_TrackLengths",Mode,POT);
      DrawEfficiencyPlot(h_DecayPionMomentum_TrackLengths,h_SelectedDecayPionMomentum_TrackLengths,Efficiency_DecayPionMomentum_TrackLengths,";True Decay #pi^{-} Momentum (GeV/c,Mode,POT);Events",label + "_DecayPionMomentum_TrackLengths",Mode,POT);
      DrawEfficiencyPlot(h_OpeningAngle_TrackLengths,h_SelectedOpeningAngle_TrackLengths,Efficiency_OpeningAngle_TrackLengths,";True Opening Angle (deg,Mode,POT);Events",label + "_OpeningAngle_TrackLengths",Mode,POT);
      DrawEfficiencyPlot(h_LambdaRange_TrackLengths,h_SelectedLambdaRange_TrackLengths,Efficiency_LambdaRange_TrackLengths,";True #Lambda Range (cm,Mode,POT);Events",label + "_LambdaRange_TrackLengths",Mode,POT);
      DrawEfficiencyPlot(h_TrackLengths,h_Selected_TrackLengths,Efficiency_TrackLengths,";;Events",label + "_TrackLengths",Mode,POT);

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


      // Analysis BDT
      DrawEfficiencyPlot(h_Q2_Analysis,h_SelectedQ2_Analysis,Efficiency_Q2_Analysis,";True Q^{2} (GeV^{2},Mode,POT);Events",label + "_Q2_Analysis",Mode,POT);
      DrawEfficiencyPlot(h_NuE_Analysis,h_SelectedNuE_Analysis,Efficiency_NuE_Analysis,";True E_{#nu} (GeV,Mode,POT);Events",label + "_NuE_Analysis",Mode,POT);
      DrawEfficiencyPlot(h_MuonKE_Analysis,h_SelectedMuonKE_Analysis,Efficiency_MuonKE_Analysis,";True Muon E_{k} (GeV,Mode,POT);Events",label + "_MuonKE_Analysis",Mode,POT);
      DrawEfficiencyPlot(h_MuonTrueTheta_Analysis,h_SelectedMuonTrueTheta_Analysis,Efficiency_MuonTrueTheta_Analysis,";True Muon #theta;Events",label + "_MuonTrueTheta_Analysis",Mode,POT);
      DrawEfficiencyPlot(h_MuonDetectorTheta_Analysis,h_SelectedMuonDetectorTheta_Analysis,Efficiency_MuonDetectorTheta_Analysis,";Detector Muon #theta;Events",label + "_MuonDetectorTheta_Analysis",Mode,POT);
      DrawEfficiencyPlot(h_MuonDetectorPhi_Analysis,h_SelectedMuonDetectorPhi_Analysis,Efficiency_MuonDetectorPhi_Analysis,";Detector Muon #phi;Events",label + "_MuonDetectorPhi_Analysis",Mode,POT);
      DrawEfficiencyPlot(h_MuonBeamTheta_Analysis,h_SelectedMuonBeamTheta_Analysis,Efficiency_MuonBeamTheta_Analysis,";Beam Muon #theta;Events",label + "_MuonBeamTheta_Analysis",Mode,POT);
      DrawEfficiencyPlot(h_MuonBeamPhi_Analysis,h_SelectedMuonBeamPhi_Analysis,Efficiency_MuonBeamPhi_Analysis,";Beam Muon #phi;Events",label + "_MuonBeamPhi_Analysis",Mode,POT);
      DrawEfficiencyPlot(h_LambdaMomentum_Analysis,h_SelectedLambdaMomentum_Analysis,Efficiency_LambdaMomentum_Analysis,";True #Lambda Momentum (GeV/c,Mode,POT);Events",label + "_LambdaMomentum_Analysis",Mode,POT);
      DrawEfficiencyPlot(h_DecayProtonMomentum_Analysis,h_SelectedDecayProtonMomentum_Analysis,Efficiency_DecayProtonMomentum_Analysis,";True Decay Proton Momentum (GeV/c,Mode,POT);Events",label + "_DecayProtonMomentum_Analysis",Mode,POT);
      DrawEfficiencyPlot(h_DecayPionMomentum_Analysis,h_SelectedDecayPionMomentum_Analysis,Efficiency_DecayPionMomentum_Analysis,";True Decay #pi^{-} Momentum (GeV/c,Mode,POT);Events",label + "_DecayPionMomentum_Analysis",Mode,POT);
      DrawEfficiencyPlot(h_OpeningAngle_Analysis,h_SelectedOpeningAngle_Analysis,Efficiency_OpeningAngle_Analysis,";True Opening Angle (deg,Mode,POT);Events",label + "_OpeningAngle_Analysis",Mode,POT);
      DrawEfficiencyPlot(h_LambdaRange_Analysis,h_SelectedLambdaRange_Analysis,Efficiency_LambdaRange_Analysis,";True #Lambda Range (cm,Mode,POT);Events",label + "_LambdaRange_Analysis",Mode,POT);
      DrawEfficiencyPlot(h_Analysis,h_Selected_Analysis,Efficiency_Analysis,";;Events",label + "_Analysis",Mode,POT);

      // Connectedness
      DrawEfficiencyPlot(h_Q2_Connectedness,h_SelectedQ2_Connectedness,Efficiency_Q2_Connectedness,";True Q^{2} (GeV^{2},Mode,POT);Events",label + "_Q2_Connectedness",Mode,POT);
      DrawEfficiencyPlot(h_NuE_Connectedness,h_SelectedNuE_Connectedness,Efficiency_NuE_Connectedness,";True E_{#nu} (GeV,Mode,POT);Events",label + "_NuE_Connectedness",Mode,POT);
      DrawEfficiencyPlot(h_MuonKE_Connectedness,h_SelectedMuonKE_Connectedness,Efficiency_MuonKE_Connectedness,";True Muon E_{k} (GeV,Mode,POT);Events",label + "_MuonKE_Connectedness",Mode,POT);
      DrawEfficiencyPlot(h_MuonTrueTheta_Connectedness,h_SelectedMuonTrueTheta_Connectedness,Efficiency_MuonTrueTheta_Connectedness,";True Muon #theta;Events",label + "_MuonTrueTheta_Connectedness",Mode,POT);
      DrawEfficiencyPlot(h_MuonDetectorTheta_Connectedness,h_SelectedMuonDetectorTheta_Connectedness,Efficiency_MuonDetectorTheta_Connectedness,";Detector Muon #theta;Events",label + "_MuonDetectorTheta_Connectedness",Mode,POT);
      DrawEfficiencyPlot(h_MuonDetectorPhi_Connectedness,h_SelectedMuonDetectorPhi_Connectedness,Efficiency_MuonDetectorPhi_Connectedness,";Detector Muon #phi;Events",label + "_MuonDetectorPhi_Connectedness",Mode,POT);
      DrawEfficiencyPlot(h_MuonBeamTheta_Connectedness,h_SelectedMuonBeamTheta_Connectedness,Efficiency_MuonBeamTheta_Connectedness,";Beam Muon #theta;Events",label + "_MuonBeamTheta_Connectedness",Mode,POT);
      DrawEfficiencyPlot(h_MuonBeamPhi_Connectedness,h_SelectedMuonBeamPhi_Connectedness,Efficiency_MuonBeamPhi_Connectedness,";Beam Muon #phi;Events",label + "_MuonBeamPhi_Connectedness",Mode,POT);
      DrawEfficiencyPlot(h_LambdaMomentum_Connectedness,h_SelectedLambdaMomentum_Connectedness,Efficiency_LambdaMomentum_Connectedness,";True #Lambda Momentum (GeV/c,Mode,POT);Events",label + "_LambdaMomentum_Connectedness",Mode,POT);
      DrawEfficiencyPlot(h_DecayProtonMomentum_Connectedness,h_SelectedDecayProtonMomentum_Connectedness,Efficiency_DecayProtonMomentum_Connectedness,";True Decay Proton Momentum (GeV/c,Mode,POT);Events",label + "_DecayProtonMomentum_Connectedness",Mode,POT);
      DrawEfficiencyPlot(h_DecayPionMomentum_Connectedness,h_SelectedDecayPionMomentum_Connectedness,Efficiency_DecayPionMomentum_Connectedness,";True Decay #pi^{-} Momentum (GeV/c,Mode,POT);Events",label + "_DecayPionMomentum_Connectedness",Mode,POT);
      DrawEfficiencyPlot(h_OpeningAngle_Connectedness,h_SelectedOpeningAngle_Connectedness,Efficiency_OpeningAngle_Connectedness,";True Opening Angle (deg,Mode,POT);Events",label + "_OpeningAngle_Connectedness",Mode,POT);
      DrawEfficiencyPlot(h_LambdaRange_Connectedness,h_SelectedLambdaRange_Connectedness,Efficiency_LambdaRange_Connectedness,";True #Lambda Range (cm,Mode,POT);Events",label + "_LambdaRange_Connectedness",Mode,POT);
      DrawEfficiencyPlot(h_Connectedness,h_Selected_Connectedness,Efficiency_Connectedness,";;Events",label + "_Connectedness",Mode,POT);

   }

