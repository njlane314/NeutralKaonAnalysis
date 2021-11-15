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
#include "TGraph.h"
#include <TROOT.h>
#include <TStyle.h>
#include "TMatrix.h"

// Local includes
#include "FluxWeight.h"
#include "GenG4WeightHandler.h"
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
#include "EventListFilter.h"
#include "CTTest.h"

enum Generators {kGENIE,kNuWro};
enum Systemtic_Types {kMultisim,kSingleUnisim,kDualUnisim};

class SelectionManager {

   // General variables/functions //

   public:

      // Constructors/Destructors
      SelectionManager();
      ~SelectionManager();
      SelectionManager(SelectionParameters p);

      // Start processing a sample
      void AddSample(std::string Name,std::string Type,double SamplePOT,std::string EventList="");

      // Increment metadata
      void AddEvent(Event &e);  
      void SetSignal(Event &e);

      // Set POT
      void SetPOT(double POT);

      // Beam Mode
      std::string BeamMode = "FHC"; 
      void SetBeamMode(std::string Mode);

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
      int thisSampleGenerator;

      // Flux and Generator/G4 weight calculators
      FluxWeighter a_FluxWeightCalc;
      GenG4WeightHandler a_GenG4WeightCalc;

      // Selection Algs
      FV::FiducialVolume a_FiducialVolume;
      MuonID a_MuonID;
      TrackLengthCutManager a_TrackLengthCutManager;
      SelectorBDTManager a_SelectorBDTManager;
      AnalysisBDTManager a_AnalysisBDTManager;
      EventListFilter a_EventListFilter;
      CTTest a_CTTest_Plane0;
      CTTest a_CTTest_Plane1;
      CTTest a_CTTest_Plane2;

      // Cut Data Management //
      std::vector<std::string> CutTypes = { "FV" , "Tracks" , "Showers" , "MuonID" , "SubleadingTracks" , "DecaySelector" , "DecayAnalysis" , "Connectedness" };
      void DeclareCuts();
      std::vector<Cut> Cuts;
      void UpdateCut(Event e,bool Passed,std::string CutName);

   public:

      Cut GetCut(std::string CutName);
      void Reset();

      // Cut Functions //

   public:

      bool FiducialVolumeCut(Event e);
      bool TrackCut(Event e);
      bool ShowerCut(Event e);
      bool ChooseMuonCandidate(Event &e);
      bool TrackLengthCut(Event e);
      bool ChooseProtonPionCandidates(Event &e, bool cheat=false);
      bool AnalysisBDTCut(Event &e);
      bool EventListCut(Event e);
      bool ConnectednessTest(Event e);

      // Histogram Functions //

    private:

      std::string fTitle;
      int fHistNBins;
      int fHistLow;
      int fHistHigh;

      bool fHasData=false;

      std::map< std::string , TH1D* > Hists_ByProc;
      std::map< std::string , TH1D* > Hists_ByType;

      std::map<std::string,std::vector<TH1D*>> Multisim_Sys_Hists; // histogram in different multisim universes
      std::map<std::string,std::vector<TH1D*>> SingleUnisim_Sys_Hists; // histogram in different single univese unisims
      std::map<std::string,std::vector<TH1D*>> DualUnisim_Sys_Hists;  // histogram in different two universe multisims

      const std::vector<std::string> Types = { "Signal","OtherHYP","OtherNu","EXT","Dirt","Data" };
      const std::vector<std::string> Procs = { "Signal","OtherHYP","EXT","Dirt","Data","CCQEL","CCRES","CCDIS","CCMEC","CCCOH","NC","ElectronScattering","Diffractive","Other" };

  public:

     
      void AddSystematic(int type,int universes,std::string name);
      void FillHistogramsSys(Event e,double variable,std::string name,std::vector<double> weights);
      void DrawHistogramsSys(std::string name,std::string label="Hists");
      TMatrixD GetCovarianceMatrix(std::string name,int type,std::string label="Hists");

      void SetupHistograms(int n,double low,double high,std::string title="",int multisim_universes=0,int single_unisim_universes=0,int dual_unisim_universes=0);
      void FillHistograms(Event e,double variable,double weight=1.0);
      void DrawHistograms(std::string label="Hists",double Scale=1.0,double SignalScale=1.0);
   

};


#endif
