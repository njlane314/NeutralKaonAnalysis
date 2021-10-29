#ifndef _Event_h_
#define _Event_h_

#include <vector>

#include "TVector3.h"

#include "SimParticle.h"
#include "RecoParticle.h"

using std::vector;

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

        vector<vector<int> > *ConnSeedIndexes_Plane0=0;
        vector<vector<int> > *ConnOutputIndexes_Plane0=0;
        vector<vector<int> > *ConnOutputSizes_Plane0=0;
        vector<vector<int> > *ConnSeedChannels_Plane0=0;
        vector<vector<int> > *ConnSeedTicks_Plane0=0;
        vector<vector<int> > *ConnSeedIndexes_Plane1=0;
        vector<vector<int> > *ConnOutputIndexes_Plane1=0;
        vector<vector<int> > *ConnOutputSizes_Plane1=0;
        vector<vector<int> > *ConnSeedChannels_Plane1=0;
        vector<vector<int> > *ConnSeedTicks_Plane1=0;
        vector<vector<int> > *ConnSeedIndexes_Plane2=0;
        vector<vector<int> > *ConnOutputIndexes_Plane2=0;
        vector<vector<int> > *ConnOutputSizes_Plane2=0;
        vector<vector<int> > *ConnSeedChannels_Plane2=0;
        vector<vector<int> > *ConnSeedTicks_Plane2=0;
    
        std::vector<std::string> *SysDials=nullptr;
        std::vector<std::vector<double>> *SysWeights=nullptr;

        void Print(){ std::cout << run << "  " << subrun << "  " << event << std::endl; }

};

#endif
