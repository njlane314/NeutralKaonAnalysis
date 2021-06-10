#ifndef _SelectionManager_h_
#define _SelectionManager_h_

#include "TFile.h"
#include "TTree.h"
#include "TLorentzVector.h"
#include "TVector3.h"
#include "TH1D.h"
#include "THStack.h"
#include "TCanvas.h"
#include "TMVA/Reader.h"
#include "TLegend.h"
#include "TPad.h"


// Local includes
#include "FluxWeight.h"
#include "FiducialVolume.h"
#include "Muon_ID.h"
#include "TrackLengthCutManager.h"
#include "SelectionParameters.h"
#include "Event.h"
#include "RecoParticle.h"
#include "SimParticle.h"
#include "Cut.h"
#include "Misc.h"
#include "SelectorBDTManager.h"
#include "AnalysisBDTManager.h"
#include "PlottingFunctions.h"

class SelectionManager {


   // General variables/functions //

   public:

      // Constructors/Destructors
      SelectionManager();
      ~SelectionManager();
      SelectionManager(SelectionParameters p);

      // Start processing a sample
      void AddSample(std::string Name,std::string Type,double SamplePOT);

      // Increment metadata
      void AddEvent(Event &e);  
      void SetSignal(Event &e);

      // Set POT
      void SetPOT(double POT);

      // Beam Mode
      std::string BeamMode = "FHC"; 

      void ImportSelectorBDTWeights(std::string WeightDir="");
      void ImportAnalysisBDTWeights(std::string WeightDir="");

   private: 

      // Stores the parameters controlling the selection
      SelectionParameters TheParams;

      // POT to scale samples to
      double fPOT;

      // List of allowed sample types
      std::vector<std::string> SampleTypes = { "Hyperon" , "Background" , "Dirt" , "EXT" , "Data" };

      // Parameters of current sample being processed
      double thisSampleWeight;
      std::string thisSampleName;
      std::string thisSampleType;

      // Flux weight calculator
      FluxWeight::FluxWeighter a_FluxWeightCalc;

      // Selection Algs
      FV::FiducialVolume a_FiducialVolume;
      MuonID a_MuonID;
      TrackLengthCutManager a_TrackLengthCutManager;
      SelectorBDTManager a_SelectorBDTManager;
      AnalysisBDTManager a_AnalysisBDTManager;


      // Cut Data Management //
      std::vector<std::string> CutTypes = { "FV" , "Tracks" , "Showers" , "MuonID" , "SubleadingTracks" , "DecaySelector" , "DecayAnalysis" };
      void DeclareCuts();
      std::vector<Cut> Cuts;
      void UpdateCut(Event e,bool Passed,std::string CutName);

   public:

      Cut GetCut(std::string CutName);

      // Cut Functions //

   public:

      bool FiducialVolumeCut(Event e);
      bool TrackCut(Event e);
      bool ShowerCut(Event e);
      bool ChooseMuonCandidate(Event &e);
      bool TrackLengthCut(Event e);
      bool ChooseProtonPionCandidates(Event &e);
      bool AnalysisBDTCut(Event &e);

      // Histogram Functions //

    private:

      std::string fTitle;
      bool fHasData=false;

      std::map< std::string , TH1D* > Hists_ByProc;
      std::map< std::string , TH1D* > Hists_ByType;

      const std::vector<std::string> Types = { "Signal","OtherHYP","OtherNu","EXT","Dirt","Data" };
      const std::vector<std::string> Procs = { "Signal","OtherHYP","EXT","Dirt","Data","CCQEL","CCRES","CCDIS","CCMEC","CCCOH","NC","ElectronScattering","Diffractive","Other" };

  public:

      void SetupHistograms(int n=20,double low=0.0,double high=1.0,std::string title="");
      void FillHistograms(Event e,double variable,double weight=1.0);
      void DrawHistograms(std::string label="Hists",double Scale=1.0);

};


#endif
