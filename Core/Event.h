#ifndef _Event_h_
#define _Event_h_

#include "TVector3.h"

#include "SimParticle.h"
#include "RecoParticle.h"

struct Event {

	bool 		IsData=false;
	UInt_t          EventID;
	Int_t           run;
	Int_t           subrun;
	Int_t           event;
	Int_t           fileID;

	//event type information

	bool GoodReco;
	bool IsSignal;
	bool IsHyperon;
	bool IsAssociatedHyperon;
	bool IsSigmaZero;
	bool IsLambdaCharged;
        bool InActiveTPC; 
   	Int_t NMCTruths;
	std::string Mode;
	std::string CCNC;

	double Weight=1.0;

	//true variables
	std::vector<SimParticle> Neutrino;
	std::vector<SimParticle> Lepton;
	std::vector<SimParticle> Hyperon;
	std::vector<SimParticle> PrimaryNucleon;
	std::vector<SimParticle> PrimaryPion;
	std::vector<SimParticle> Decay;

	TVector3 TruePrimaryVertex;
	TVector3 DecayVertex;

	//reco variables

	TVector3 RecoPrimaryVertex;
	Int_t NPrimaryTrackDaughters;
	Int_t NPrimaryShowerDaughters;

	std::vector<RecoParticle> TracklikePrimaryDaughters;
	std::vector<RecoParticle> ShowerlikePrimaryDaughters;

	int TrueMuonIndex;
	int TrueDecayProtonIndex;
	int TrueDecayPionIndex;

	// Muon, proton and pion candidates
	RecoParticle MuonCandidate;
	RecoParticle DecayProtonCandidate;
	RecoParticle DecayPionCandidate;

	Float_t SelectorBDTScore;
	Float_t AnalysisBDTScore;

/*
	Double_t ProtonPionSep;	
	
	TLorentzVector RecoLambda4Momentum;
	TLorentzVector RecoMuon4Momentum;

	double Reco_W;
	double Reco_Gap;
	double Reco_Angle;	
	double Reco_LambdaImpactParameter;	
	double Reco_ProtonImpactParameter;	
	double Reco_PionImpactParameter;
	
	double LambdaTransverseFraction;

	Float_t Analysis_BDT_Score;

//	Decay_V FittedV;
        double FittedV_Quality;
        double MuonProtonV_Quality;
        double MuonPionV_Quality;


        double FittedV_Quality_R;
	TVector3 RecoDecayVertex;
	TVector3 RecoGapVector;
*/   
        void Print(){ std::cout << run << "  " << subrun << "  " << event << std::endl; }

};

#endif
