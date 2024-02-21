#ifndef _SelectorBDTManager_cxx_
#define _SelectorBDTManager_cxx_

#include "SelectorBDTManager.h"

///////////////////////////////////////////////////////////////////////////////////////////////

SelectorBDTManager::SelectorBDTManager(){

   fMode = "Test";
   fPionPIDCut = -0.1;
   fSeparationCut = 5.0;
}

///////////////////////////////////////////////////////////////////////////////////////////////

SelectorBDTManager::SelectorBDTManager(std::string Mode){

   fMode = Mode;
   if(fMode == "Train") SetupTrainingTrees();    
   fPionPIDCut = -0.1;
   fSeparationCut = 5.0;

}

///////////////////////////////////////////////////////////////////////////////////////////////

SelectorBDTManager::~SelectorBDTManager(){

   if(fMode == "Train"){
      f_Trees->Close();
      delete f_Trees;
   }
   else if(fMode == "Test"){
      if(reader != nullptr)  delete reader;
   }

}


///////////////////////////////////////////////////////////////////////////////////////////////

void SelectorBDTManager::SetCuts(double PionPIDCut,double SelectionCut){

   fPionPIDCut =  PionPIDCut;
   fSeparationCut = SelectionCut;

}

///////////////////////////////////////////////////////////////////////////////////////////////

void SelectorBDTManager::WriteTrainingTrees(){

   std::cout << "Entries in Signal tree = " << t_Signal->GetEntries() << std::endl;
   std::cout << "Entries in Background tree = " << t_Background->GetEntries() << std::endl;

   f_Trees->cd();

   t_Signal->Write("SignalTree");
   t_Background->Write("BackgroundTree");

}   

///////////////////////////////////////////////////////////////////////////////////////////////

void SelectorBDTManager::SetupTrainingTrees(){

   system("mkdir -p SelectorMVA");

   f_Trees = TFile::Open( "SelectorMVA/Trees.root" , "RECREATE" );
   t_Signal = new TTree("t_SelectorMVA_Signal","Signal Pairings");
   t_Background = new TTree("t_SelectorMVA_Background","Background Pairings");

   t_Signal->Branch("separation",&v_separation);
   t_Signal->Branch("pion1_trkscore",&v_pion1_trkscore);
   t_Signal->Branch("pion2_trkscore",&v_pion2_trkscore);
   t_Signal->Branch("pion1_dEdX",&v_pion1_dEdX);
   t_Signal->Branch("pion2_dEdX",&v_pion2_dEdX);
   t_Signal->Branch("pion1_LLR",&v_pion1_LLR);
   t_Signal->Branch("pion2_LLR",&v_pion2_LLR);

   t_Background->Branch("separation",&v_separation);
   t_Background->Branch("pion1_trkscore",&v_pion1_trkscore);
   t_Background->Branch("pion2_trkscore",&v_pion2_trkscore);
   t_Background->Branch("pion1_dEdX",&v_pion1_dEdX);
   t_Background->Branch("pion2_dEdX",&v_pion2_dEdX);
   t_Background->Branch("pion1_LLR",&v_pion1_LLR);
   t_Background->Branch("pion2_LLR",&v_pion2_LLR);

}


///////////////////////////////////////////////////////////////////////////////////////////////

void SelectorBDTManager::FillTree(const Event &e){

   // Check in the right running mode first
   assert(fMode == "Train");

   // Only train this alg on events with real reconstructed decays
   if(!e.GoodReco) return;

   if( t_Signal == nullptr || t_Background == nullptr ){ std::cout << "Trees not setup, exiting" << std::endl; return; }

   // Sort through list of candiadate tracks
   for(size_t i_tr=0;i_tr<e.TracklikePrimaryDaughters.size();i_tr++){
      for(size_t j_tr=0;j_tr<e.TracklikePrimaryDaughters.size();j_tr++){

         if(i_tr == j_tr) continue;

         // Returns false if tracks fail PID/separation cuts     
         if(!SetVariables(e.TracklikePrimaryDaughters.at(i_tr),e.TracklikePrimaryDaughters.at(j_tr))) continue;
         
         // If these tracks are the correct pair of decay tracks, fill signal tree 
         if(e.GoodReco && e.TracklikePrimaryDaughters.at(i_tr).Index == e.TrueDecayPionPlusIndex && e.TracklikePrimaryDaughters.at(j_tr).Index == e.TrueDecayPionMinusIndex)
            t_Signal->Fill();         
         else t_Background->Fill();

      }
   }
}

///////////////////////////////////////////////////////////////////////////////////////////////

bool SelectorBDTManager::SetVariables(RecoParticle thisPionPlusIndex, RecoParticle thisPionMinusIndex){

   TVector3 PionPlusPosition(thisPionPlusIndex.TrackStartX,thisPionPlusIndex.TrackStartY,thisPionPlusIndex.TrackStartZ);
   TVector3 PionMinusPosition(thisPionMinusIndex.TrackStartX,thisPionMinusIndex.TrackStartY,thisPionMinusIndex.TrackStartZ);

   v_separation = Limit((PionPlusPosition-PionMinusPosition).Mag(),separation_limits);
   v_pion1_trkscore = Limit(thisPionPlusIndex.TrackShowerScore,trkscore_limits);
   v_pion2_trkscore = Limit(thisPionMinusIndex.TrackShowerScore,trkscore_limits);

   // Catch default dEdX fills
   if(thisPionPlusIndex.MeandEdX_ThreePlane < 0 || thisPionMinusIndex.MeandEdX_ThreePlane < 0) return false;
   if(std::isnan(thisPionPlusIndex.MeandEdX_ThreePlane) || std::isnan(thisPionMinusIndex.MeandEdX_ThreePlane)) return false;

   v_pion1_dEdX = Limit(thisPionPlusIndex.MeandEdX_ThreePlane,dEdX_limits);
   v_pion2_dEdX = Limit(thisPionMinusIndex.MeandEdX_ThreePlane,dEdX_limits);

   v_pion1_LLR = Limit(thisPionPlusIndex.Track_LLR_PID,LLR_limits);
   v_pion2_LLR = Limit(thisPionMinusIndex.Track_LLR_PID,LLR_limits);

   // Pion PID Cut
   if(v_pion2_LLR < fPionPIDCut) return false;
   if(v_pion1_LLR < fPionPIDCut) return false;

   // Separation
   if(v_separation > fSeparationCut) return false;

   return true;

}

///////////////////////////////////////////////////////////////////////////////////////////////

void SelectorBDTManager::SetupSelectorBDT(std::string WeightsDir,std::string alg){

   assert(fMode == "Test");

   if(WeightsDir == ""){ 
      std::cout << "No weights directory given, assuming default location" << std::endl;
      fWeightsDir = "/uboone/app/users/nlane/NeutralKaonAnalysis/TMVA/SelectorMVA/dataset/weights";
   }
   else fWeightsDir = WeightsDir;  


   TMVA::Tools::Instance();
   reader = new TMVA::Reader( "!Color:!Silent" );

   reader->AddVariable("separation",&v_separation);
   reader->AddVariable("pion1_trkscore",&v_pion1_trkscore);
   reader->AddVariable("pion2_trkscore",&v_pion2_trkscore);
   reader->AddVariable("pion1_dEdX",&v_pion1_dEdX);
   reader->AddVariable("pion2_dEdX",&v_pion2_dEdX);
   reader->AddVariable("pion1_LLR",&v_pion1_LLR);
   reader->AddVariable("pion2_LLR",&v_pion2_LLR);

   std::map<std::string,int> Use;
   for(size_t i_a=0;i_a<Algs_str.size();i_a++)
      Use[Algs_str.at(i_a)] = 1;

   TString prefix = "TMVAClassification";

   for (std::map<std::string,int>::iterator it = Use.begin(); it != Use.end(); it++) {
      if (it->second) {
         TString methodName = TString(it->first) + TString(" method");
         TString weightfile = fWeightsDir + "/" + prefix + TString("_") + TString(it->first) + TString(".weights.xml");
         std::cout << "Opening weight file " << weightfile << std::endl; 
         reader->BookMVA( methodName, weightfile );
      }
   }

}

///////////////////////////////////////////////////////////////////////////////////////////////

void SelectorBDTManager::SetAlg(std::string alg){

   bool found_alg = false;
   for(size_t i_a=0;i_a<Algs_str.size();i_a++)
      if(alg == Algs_str.at(i_a)) found_alg = true;

   if(!found_alg) throw std::invalid_argument("SelectorBDTManager: Classifier " + alg + " not found, exiting");

   Alg = alg;

}

///////////////////////////////////////////////////////////////////////////////////////////////

std::pair<int,int> SelectorBDTManager::NominateTracks(Event &e){

   int i_pion_plus_candidate=-1;
   int i_pion_minus_candidate=-1;

   Float_t BDT_Best = -1e10;

   //sort through list of candiadate tracks
   for(size_t i_tr=0;i_tr<e.TracklikePrimaryDaughters.size();i_tr++){
      for(size_t j_tr=0;j_tr<e.TracklikePrimaryDaughters.size();j_tr++){

         if(i_tr == j_tr) continue;

         // Returns false if tracks fail PID/separation cuts    
         if(!SetVariables(e.TracklikePrimaryDaughters.at(i_tr),e.TracklikePrimaryDaughters.at(j_tr))) continue;

         //calculate BDT Score
         //double BDT_Score = reader->EvaluateMVA("BDT method");
         double BDT_Score = reader->EvaluateMVA(Alg + " method");

         if( BDT_Score > BDT_Best){
            i_pion_plus_candidate = i_tr;
            i_pion_minus_candidate = j_tr;
            BDT_Best = BDT_Score;
         }
      }
   }

   e.SelectorBDTScore = BDT_Best;

   return std::make_pair(i_pion_plus_candidate,i_pion_minus_candidate);

}

///////////////////////////////////////////////////////////////////////////////////////////////

std::pair<int,int> SelectorBDTManager::NominateTracksCheat(Event &e){
   
   // Use truth information to choose the proton/pion candidates

   if(!e.GoodReco) return {-1,-1};

   int i_pion_plus_candidate=-1;
   int i_pion_minus_candidate=-1;

   for(size_t i_tr=0; i_tr<e.TracklikePrimaryDaughters.size();i_tr++){
      if(e.TracklikePrimaryDaughters.at(i_tr).Index == e.TrueDecayPionMinusIndex) {
         i_pion_minus_candidate = e.TracklikePrimaryDaughters.at(i_tr).Index;
         //std::cout << "Track length " << e.TracklikePrimaryDaughters.at(i_tr).TrackLength << std::endl;
      }
      if(e.TracklikePrimaryDaughters.at(i_tr).Index == e.TrueDecayPionPlusIndex) {
         i_pion_plus_candidate = e.TracklikePrimaryDaughters.at(i_tr).Index;
         //std::cout << "Track length " << e.TracklikePrimaryDaughters.at(i_tr).TrackLength << std::endl;
      }
   }

   if(i_pion_plus_candidate == -1 || i_pion_minus_candidate == -1) return {-1,-1};

   //e.SelectorBDTScore = reader->EvaluateMVA(Alg + " method"); 

   return std::make_pair(i_pion_plus_candidate, i_pion_minus_candidate);
}

///////////////////////////////////////////////////////////////////////////////////////////////

double SelectorBDTManager::GetScore(RecoParticle DecayProtonCandidate,RecoParticle DecayPionCandidate){

   if(!SetVariables(DecayProtonCandidate,DecayPionCandidate)) return -1000;

   return reader->EvaluateMVA(Alg + " method");
}

///////////////////////////////////////////////////////////////////////////////////////////////

#endif
