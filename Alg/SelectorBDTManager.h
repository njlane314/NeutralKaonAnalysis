#ifndef _SelectorBDTManager_h_
#define _SelectorBDTManager_h_

#include "Event.h"
#include "TFile.h"
#include "TTree.h"
#include "TVector3.h"
#include "RecoParticle.h"
#include "Misc.h"

#include "TMVA/Tools.h"
#include "TMVA/Reader.h"

// Track selector BDT class. Has two modes, training
// and testing. Training for filling the trees train
// new BDT tunes. Testing to use them in the selection

class SelectorBDTManager {

   public:

      SelectorBDTManager();
      SelectorBDTManager(std::string Mode);
      ~SelectorBDTManager();

      void FillTree(const Event &e);
      void WriteTrainingTrees();    

      void SetCuts(double PionPIDCut,double SelectionCut);
   

   private:

      enum e_Algs{kLD,kBDT,kBDTG,kKNN,kLikelihood,kMLPBNN,kAlgMAX};
      const std::vector<std::string> Algs_str = {"LD","BDT","BDTG","KNN","Likelihood","MLPBNN"};
      std::string Alg = "BDT";

      std::string fMode;

      double fPionPIDCut;
      double fSeparationCut;

      bool SetVariables(RecoParticle thisProtonCandidate, RecoParticle thisPionCandidate);

      // Training trees

      void SetupTrainingTrees();    

      TFile *f_Trees;
      TTree *t_Signal=nullptr;
      TTree *t_Background=nullptr;

      // Variables
      Float_t v_separation;
      Float_t v_pion_plus_trkscore;
      Float_t v_pion_minus_trkscore;
      Float_t v_pion_plus_dEdX;
      Float_t v_pion_minus_dEdX;
      Float_t v_pion_plus_LLR;
      Float_t v_pion_minus_LLR;

      const std::pair<double,double> separation_limits = { 0 , 20 };
      const std::pair<double,double> pid_limits = { -10 , 10 };
      const std::pair<double,double> trkscore_limits = { 0 , 1.0 };
      const std::pair<double,double> dEdX_limits = { 0.0 , 20 };
      const std::pair<double,double> LLR_limits = { -1.0 , 1.0 };

      // Importing BDT and using in selection
      std::string fWeightsDir;
      TMVA::Reader *reader=nullptr;

   public:

      void SetupSelectorBDT(std::string WeightsDir="",std::string alg="BDT");
      void SetAlg(std::string alg);
      std::pair<int,int> NominateTracks(Event &e);      
      std::pair<int,int> NominateTracksCheat(Event &e);
      double GetScore(RecoParticle DecayProtonCandidate,RecoParticle DecayPionCandidate);

};

#endif
