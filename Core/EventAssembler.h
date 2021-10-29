#ifndef _EventAssembler_h_
#define _EventAssembler_h_

#include <vector>

#include "TFile.h"
#include "TTree.h"
#include "TLorentzVector.h"
#include "TVector3.h"

//local includes
#include "SimParticle.h"
#include "RecoParticle.h"

#include "Event.h"

using std::vector;

class EventAssembler {

	private:
		//input file and event tree
		TFile * f_in=nullptr;
		TTree * t_in;

		TTree *t_meta;
		Double_t POT;

		//number of events (entries in event tree)
		int nEvents;

                TString DataDir;
		

	public:

		//setters and getters
		void SetFile(std::string infilename);
		void Close();

		Event GetEvent(int i);
		Long64_t GetNEvents();
		double GetPOT();		

	private:

		//truth variables
		std::vector<SimParticle> Neutrino;
		std::vector<SimParticle> Lepton;
		std::vector<SimParticle> Hyperon;
		std::vector<SimParticle> PrimaryNucleon;
		std::vector<SimParticle> PrimaryPion;
		std::vector<SimParticle> Decay;

		//reco variables
		std::vector<RecoParticle> TracklikePrimaryDaughters;
		std::vector<RecoParticle> ShowerlikePrimaryDaughters;

		//////////////////////////////////////////////////////////////////////////////
		//               Variables For the Disassembled Tree                        //
		//////////////////////////////////////////////////////////////////////////////

		// Fixed size dimensions of array or collections stored in the TTree if any.
		static constexpr Int_t kMaxNeutrino = 10;
		static constexpr Int_t kMaxLepton = 10;
		static constexpr Int_t kMaxHyperon = 10;
		static constexpr Int_t kMaxPrimaryNucleon = 100;
		static constexpr Int_t kMaxPrimaryPion = 50;
		static constexpr Int_t kMaxDecay = 50;
		static constexpr Int_t kMaxSigmaZeroDecayPhoton = 10;
		static constexpr Int_t kMaxSigmaZeroDecayLambda = 10;
		static constexpr Int_t kMaxTracklikePrimaryDaughters = 40;
		static constexpr Int_t kMaxShowerlikePrimaryDaughters = 40;

		// Declaration of leaf types
		Bool_t          IsData;
		UInt_t          EventID;
		Int_t           run;
		Int_t           subrun;
		Int_t           event;
		std::string     *Mode=0;
		std::string     *CCNC=0;
		Bool_t          InActiveTPC;
		Bool_t          IsHyperon;
		Bool_t          IsSigmaZero;
		Bool_t          IsLambda;
		Bool_t          IsLambdaCharged;
		Bool_t          IsSignal;
		Bool_t          IsAssociatedHyperon;
		Bool_t          GoodReco;
		Bool_t          SelectedEvent;
   		Double_t        Weight;
   		Int_t           NMCTruths;
		Int_t           Neutrino_;
		Int_t           Neutrino_PDG[kMaxNeutrino];   //[Neutrino_]
		Double_t        Neutrino_E[kMaxNeutrino];   //[Neutrino_]
		Double_t        Neutrino_Px[kMaxNeutrino];   //[Neutrino_]
		Double_t        Neutrino_Py[kMaxNeutrino];   //[Neutrino_]
		Double_t        Neutrino_Pz[kMaxNeutrino];   //[Neutrino_]
		Double_t        Neutrino_ModMomentum[kMaxNeutrino];   //[Neutrino_]
		Double_t        Neutrino_KE[kMaxNeutrino];   //[Neutrino_]
		Double_t        Neutrino_StartX[kMaxNeutrino];   //[Neutrino_]
		Double_t        Neutrino_StartY[kMaxNeutrino];   //[Neutrino_]
		Double_t        Neutrino_StartZ[kMaxNeutrino];   //[Neutrino_]
		Double_t        Neutrino_EndX[kMaxNeutrino];   //[Neutrino_]
		Double_t        Neutrino_EndY[kMaxNeutrino];   //[Neutrino_]
		Double_t        Neutrino_EndZ[kMaxNeutrino];   //[Neutrino_]
		Double_t        Neutrino_Travel[kMaxNeutrino];   //[Neutrino_]
		Double_t        Neutrino_Theta[kMaxNeutrino];   //[Neutrino_]
		Double_t        Neutrino_Phi[kMaxNeutrino];   //[Neutrino_]
		Int_t           Neutrino_Origin[kMaxNeutrino];   //[Neutrino_]
		TVector3        *TruePrimaryVertex=0;
		Int_t           Lepton_;
		Int_t           Lepton_PDG[kMaxLepton];   //[Lepton_]
		Double_t        Lepton_E[kMaxLepton];   //[Lepton_]
		Double_t        Lepton_Px[kMaxLepton];   //[Lepton_]
		Double_t        Lepton_Py[kMaxLepton];   //[Lepton_]
		Double_t        Lepton_Pz[kMaxLepton];   //[Lepton_]
		Double_t        Lepton_ModMomentum[kMaxLepton];   //[Lepton_]
		Double_t        Lepton_KE[kMaxLepton];   //[Lepton_]
		Double_t        Lepton_StartX[kMaxLepton];   //[Lepton_]
		Double_t        Lepton_StartY[kMaxLepton];   //[Lepton_]
		Double_t        Lepton_StartZ[kMaxLepton];   //[Lepton_]
		Double_t        Lepton_EndX[kMaxLepton];   //[Lepton_]
		Double_t        Lepton_EndY[kMaxLepton];   //[Lepton_]
		Double_t        Lepton_EndZ[kMaxLepton];   //[Lepton_]
		Double_t        Lepton_Travel[kMaxLepton];   //[Lepton_]
		Double_t        Lepton_Theta[kMaxLepton];   //[Lepton_]
		Double_t        Lepton_Phi[kMaxLepton];   //[Lepton_]
		Int_t           Lepton_Origin[kMaxLepton];   //[Lepton_]
		Int_t           Hyperon_;
		Int_t           Hyperon_PDG[kMaxHyperon];   //[Hyperon_]
		Double_t        Hyperon_E[kMaxHyperon];   //[Hyperon_]
		Double_t        Hyperon_Px[kMaxHyperon];   //[Hyperon_]
		Double_t        Hyperon_Py[kMaxHyperon];   //[Hyperon_]
		Double_t        Hyperon_Pz[kMaxHyperon];   //[Hyperon_]
		Double_t        Hyperon_ModMomentum[kMaxHyperon];   //[Hyperon_]
		Double_t        Hyperon_KE[kMaxHyperon];   //[Hyperon_]
		Double_t        Hyperon_StartX[kMaxHyperon];   //[Hyperon_]
		Double_t        Hyperon_StartY[kMaxHyperon];   //[Hyperon_]
		Double_t        Hyperon_StartZ[kMaxHyperon];   //[Hyperon_]
		Double_t        Hyperon_EndX[kMaxHyperon];   //[Hyperon_]
		Double_t        Hyperon_EndY[kMaxHyperon];   //[Hyperon_]
		Double_t        Hyperon_EndZ[kMaxHyperon];   //[Hyperon_]
		Double_t        Hyperon_Travel[kMaxHyperon];   //[Hyperon_]
		Double_t        Hyperon_Theta[kMaxHyperon];   //[Hyperon_]
		Double_t        Hyperon_Phi[kMaxHyperon];   //[Hyperon_]
		Int_t           Hyperon_Origin[kMaxHyperon];   //[Hyperon_]
		Int_t           PrimaryNucleon_;
		Int_t           PrimaryNucleon_PDG[kMaxPrimaryNucleon];   //[PrimaryNucleon_]
		Double_t        PrimaryNucleon_E[kMaxPrimaryNucleon];   //[PrimaryNucleon_]
		Double_t        PrimaryNucleon_Px[kMaxPrimaryNucleon];   //[PrimaryNucleon_]
		Double_t        PrimaryNucleon_Py[kMaxPrimaryNucleon];   //[PrimaryNucleon_]
		Double_t        PrimaryNucleon_Pz[kMaxPrimaryNucleon];   //[PrimaryNucleon_]
		Double_t        PrimaryNucleon_ModMomentum[kMaxPrimaryNucleon];   //[PrimaryNucleon_]
		Double_t        PrimaryNucleon_KE[kMaxPrimaryNucleon];   //[PrimaryNucleon_]
		Double_t        PrimaryNucleon_StartX[kMaxPrimaryNucleon];   //[PrimaryNucleon_]
		Double_t        PrimaryNucleon_StartY[kMaxPrimaryNucleon];   //[PrimaryNucleon_]
		Double_t        PrimaryNucleon_StartZ[kMaxPrimaryNucleon];   //[PrimaryNucleon_]
		Double_t        PrimaryNucleon_EndX[kMaxPrimaryNucleon];   //[PrimaryNucleon_]
		Double_t        PrimaryNucleon_EndY[kMaxPrimaryNucleon];   //[PrimaryNucleon_]
		Double_t        PrimaryNucleon_EndZ[kMaxPrimaryNucleon];   //[PrimaryNucleon_]
		Double_t        PrimaryNucleon_Travel[kMaxPrimaryNucleon];   //[PrimaryNucleon_]
		Double_t        PrimaryNucleon_Theta[kMaxPrimaryNucleon];   //[PrimaryNucleon_]
		Double_t        PrimaryNucleon_Phi[kMaxPrimaryNucleon];   //[PrimaryNucleon_]
		Int_t           PrimaryNucleon_Origin[kMaxPrimaryNucleon];   //[PrimaryNucleon_]
		Int_t           PrimaryPion_;
		Int_t           PrimaryPion_PDG[kMaxPrimaryPion];   //[PrimaryPion_]
		Double_t        PrimaryPion_E[kMaxPrimaryPion];   //[PrimaryPion_]
		Double_t        PrimaryPion_Px[kMaxPrimaryPion];   //[PrimaryPion_]
		Double_t        PrimaryPion_Py[kMaxPrimaryPion];   //[PrimaryPion_]
		Double_t        PrimaryPion_Pz[kMaxPrimaryPion];   //[PrimaryPion_]
		Double_t        PrimaryPion_ModMomentum[kMaxPrimaryPion];   //[PrimaryPion_]
		Double_t        PrimaryPion_KE[kMaxPrimaryPion];   //[PrimaryPion_]
		Double_t        PrimaryPion_StartX[kMaxPrimaryPion];   //[PrimaryPion_]
		Double_t        PrimaryPion_StartY[kMaxPrimaryPion];   //[PrimaryPion_]
		Double_t        PrimaryPion_StartZ[kMaxPrimaryPion];   //[PrimaryPion_]
		Double_t        PrimaryPion_EndX[kMaxPrimaryPion];   //[PrimaryPion_]
		Double_t        PrimaryPion_EndY[kMaxPrimaryPion];   //[PrimaryPion_]
		Double_t        PrimaryPion_EndZ[kMaxPrimaryPion];   //[PrimaryPion_]
		Double_t        PrimaryPion_Travel[kMaxPrimaryPion];   //[PrimaryPion_]
		Double_t        PrimaryPion_Theta[kMaxPrimaryPion];   //[PrimaryPion_]
		Double_t        PrimaryPion_Phi[kMaxPrimaryPion];   //[PrimaryPion_]
		Int_t           PrimaryPion_Origin[kMaxPrimaryPion];   //[PrimaryPion_]
		TVector3        *DecayVertex=0;
		Int_t           Decay_;
		Int_t           Decay_PDG[kMaxDecay];   //[Decay_]
		Double_t        Decay_E[kMaxDecay];   //[Decay_]
		Double_t        Decay_Px[kMaxDecay];   //[Decay_]
		Double_t        Decay_Py[kMaxDecay];   //[Decay_]
		Double_t        Decay_Pz[kMaxDecay];   //[Decay_]
		Double_t        Decay_ModMomentum[kMaxDecay];   //[Decay_]
		Double_t        Decay_KE[kMaxDecay];   //[Decay_]
		Double_t        Decay_StartX[kMaxDecay];   //[Decay_]
		Double_t        Decay_StartY[kMaxDecay];   //[Decay_]
		Double_t        Decay_StartZ[kMaxDecay];   //[Decay_]
		Double_t        Decay_EndX[kMaxDecay];   //[Decay_]
		Double_t        Decay_EndY[kMaxDecay];   //[Decay_]
		Double_t        Decay_EndZ[kMaxDecay];   //[Decay_]
		Double_t        Decay_Travel[kMaxDecay];   //[Decay_]
		Double_t        Decay_Theta[kMaxDecay];   //[Decay_]
		Double_t        Decay_Phi[kMaxDecay];   //[Decay_]
		Int_t           Decay_Origin[kMaxDecay];   //[Decay_]
		Int_t           SigmaZeroDecayPhoton_;
		Int_t           SigmaZeroDecayPhoton_PDG[kMaxSigmaZeroDecayPhoton];   //[SigmaZeroDecayPhoton_]
		Double_t        SigmaZeroDecayPhoton_E[kMaxSigmaZeroDecayPhoton];   //[SigmaZeroDecayPhoton_]
		Double_t        SigmaZeroDecayPhoton_Px[kMaxSigmaZeroDecayPhoton];   //[SigmaZeroDecayPhoton_]
		Double_t        SigmaZeroDecayPhoton_Py[kMaxSigmaZeroDecayPhoton];   //[SigmaZeroDecayPhoton_]
		Double_t        SigmaZeroDecayPhoton_Pz[kMaxSigmaZeroDecayPhoton];   //[SigmaZeroDecayPhoton_]
		Double_t        SigmaZeroDecayPhoton_ModMomentum[kMaxSigmaZeroDecayPhoton];   //[SigmaZeroDecayPhoton_]
		Double_t        SigmaZeroDecayPhoton_KE[kMaxSigmaZeroDecayPhoton];   //[SigmaZeroDecayPhoton_]
		Double_t        SigmaZeroDecayPhoton_StartX[kMaxSigmaZeroDecayPhoton];   //[SigmaZeroDecayPhoton_]
		Double_t        SigmaZeroDecayPhoton_StartY[kMaxSigmaZeroDecayPhoton];   //[SigmaZeroDecayPhoton_]
		Double_t        SigmaZeroDecayPhoton_StartZ[kMaxSigmaZeroDecayPhoton];   //[SigmaZeroDecayPhoton_]
		Double_t        SigmaZeroDecayPhoton_EndX[kMaxSigmaZeroDecayPhoton];   //[SigmaZeroDecayPhoton_]
		Double_t        SigmaZeroDecayPhoton_EndY[kMaxSigmaZeroDecayPhoton];   //[SigmaZeroDecayPhoton_]
		Double_t        SigmaZeroDecayPhoton_EndZ[kMaxSigmaZeroDecayPhoton];   //[SigmaZeroDecayPhoton_]
		Double_t        SigmaZeroDecayPhoton_Travel[kMaxSigmaZeroDecayPhoton];   //[SigmaZeroDecayPhoton_]
		Double_t        SigmaZeroDecayPhoton_Theta[kMaxSigmaZeroDecayPhoton];   //[SigmaZeroDecayPhoton_]
		Double_t        SigmaZeroDecayPhoton_Phi[kMaxSigmaZeroDecayPhoton];   //[SigmaZeroDecayPhoton_]
		Int_t           SigmaZeroDecayPhoton_Origin[kMaxSigmaZeroDecayPhoton];   //[SigmaZeroDecayPhoton_]
		Int_t           SigmaZeroDecayLambda_;
		Int_t           SigmaZeroDecayLambda_PDG[kMaxSigmaZeroDecayLambda];   //[SigmaZeroDecayLambda_]
		Double_t        SigmaZeroDecayLambda_E[kMaxSigmaZeroDecayLambda];   //[SigmaZeroDecayLambda_]
		Double_t        SigmaZeroDecayLambda_Px[kMaxSigmaZeroDecayLambda];   //[SigmaZeroDecayLambda_]
		Double_t        SigmaZeroDecayLambda_Py[kMaxSigmaZeroDecayLambda];   //[SigmaZeroDecayLambda_]
		Double_t        SigmaZeroDecayLambda_Pz[kMaxSigmaZeroDecayLambda];   //[SigmaZeroDecayLambda_]
		Double_t        SigmaZeroDecayLambda_ModMomentum[kMaxSigmaZeroDecayLambda];   //[SigmaZeroDecayLambda_]
		Double_t        SigmaZeroDecayLambda_KE[kMaxSigmaZeroDecayLambda];   //[SigmaZeroDecayLambda_]
		Double_t        SigmaZeroDecayLambda_StartX[kMaxSigmaZeroDecayLambda];   //[SigmaZeroDecayLambda_]
		Double_t        SigmaZeroDecayLambda_StartY[kMaxSigmaZeroDecayLambda];   //[SigmaZeroDecayLambda_]
		Double_t        SigmaZeroDecayLambda_StartZ[kMaxSigmaZeroDecayLambda];   //[SigmaZeroDecayLambda_]
		Double_t        SigmaZeroDecayLambda_EndX[kMaxSigmaZeroDecayLambda];   //[SigmaZeroDecayLambda_]
		Double_t        SigmaZeroDecayLambda_EndY[kMaxSigmaZeroDecayLambda];   //[SigmaZeroDecayLambda_]
		Double_t        SigmaZeroDecayLambda_EndZ[kMaxSigmaZeroDecayLambda];   //[SigmaZeroDecayLambda_]
		Double_t        SigmaZeroDecayLambda_Travel[kMaxSigmaZeroDecayLambda];   //[SigmaZeroDecayLambda_]
		Double_t        SigmaZeroDecayLambda_Theta[kMaxSigmaZeroDecayLambda];   //[SigmaZeroDecayLambda_]
		Double_t        SigmaZeroDecayLambda_Phi[kMaxSigmaZeroDecayLambda];   //[SigmaZeroDecayLambda_]
		Int_t           SigmaZeroDecayLambda_Origin[kMaxSigmaZeroDecayLambda];   //[SigmaZeroDecayLambda_]
		Double_t        DecayOpeningAngle;
		Double_t        LeptonPionAngle;
		Double_t        LeptonNucleonAngle;
		TVector3        *RecoPrimaryVertex=0;
		Int_t           NPrimaryTrackDaughters;
		Int_t           NPrimaryShowerDaughters;
		Int_t           TracklikePrimaryDaughters_;
   		Int_t           TracklikePrimaryDaughters_Index[kMaxTracklikePrimaryDaughters];   //[TracklikePrimaryDaughters_]
		Int_t           TracklikePrimaryDaughters_PDG[kMaxTracklikePrimaryDaughters];   //[TracklikePrimaryDaughters_]
		Double_t        TracklikePrimaryDaughters_TrackShowerScore[kMaxTracklikePrimaryDaughters];   //[TracklikePrimaryDaughters_]
		Double_t        TracklikePrimaryDaughters_X[kMaxTracklikePrimaryDaughters];   //[TracklikePrimaryDaughters_]
		Double_t        TracklikePrimaryDaughters_Y[kMaxTracklikePrimaryDaughters];   //[TracklikePrimaryDaughters_]
		Double_t        TracklikePrimaryDaughters_Z[kMaxTracklikePrimaryDaughters];   //[TracklikePrimaryDaughters_]
		Double_t        TracklikePrimaryDaughters_Displacement[kMaxTracklikePrimaryDaughters];   //[TracklikePrimaryDaughters_]
		Double_t        TracklikePrimaryDaughters_TrackLength[kMaxTracklikePrimaryDaughters];   //[TracklikePrimaryDaughters_]
		Double_t        TracklikePrimaryDaughters_TrackDirectionX[kMaxTracklikePrimaryDaughters];   //[TracklikePrimaryDaughters_]
		Double_t        TracklikePrimaryDaughters_TrackDirectionY[kMaxTracklikePrimaryDaughters];   //[TracklikePrimaryDaughters_]
		Double_t        TracklikePrimaryDaughters_TrackDirectionZ[kMaxTracklikePrimaryDaughters];   //[TracklikePrimaryDaughters_]
		Double_t        TracklikePrimaryDaughters_TrackStartX[kMaxTracklikePrimaryDaughters];   //[TracklikePrimaryDaughters_]
		Double_t        TracklikePrimaryDaughters_TrackStartY[kMaxTracklikePrimaryDaughters];   //[TracklikePrimaryDaughters_]
		Double_t        TracklikePrimaryDaughters_TrackStartZ[kMaxTracklikePrimaryDaughters];   //[TracklikePrimaryDaughters_]
		Double_t        TracklikePrimaryDaughters_TrackEndX[kMaxTracklikePrimaryDaughters];   //[TracklikePrimaryDaughters_]
		Double_t        TracklikePrimaryDaughters_TrackEndY[kMaxTracklikePrimaryDaughters];   //[TracklikePrimaryDaughters_]
		Double_t        TracklikePrimaryDaughters_TrackEndZ[kMaxTracklikePrimaryDaughters];   //[TracklikePrimaryDaughters_]
		Double_t        TracklikePrimaryDaughters_TrackMuonClosestApproachPosition[kMaxTracklikePrimaryDaughters];   //[TracklikePrimaryDaughters_]
		Double_t        TracklikePrimaryDaughters_TrackMuonClosestApproachDistance[kMaxTracklikePrimaryDaughters];   //[TracklikePrimaryDaughters_]
		Double_t        TracklikePrimaryDaughters_TrackPID[kMaxTracklikePrimaryDaughters];   //[TracklikePrimaryDaughters_]
		Double_t        TracklikePrimaryDaughters_MeandEdX_Plane0[kMaxTracklikePrimaryDaughters];   //[TracklikePrimaryDaughters_]
		Double_t        TracklikePrimaryDaughters_MeandEdX_Plane1[kMaxTracklikePrimaryDaughters];   //[TracklikePrimaryDaughters_]
		Double_t        TracklikePrimaryDaughters_MeandEdX_Plane2[kMaxTracklikePrimaryDaughters];   //[TracklikePrimaryDaughters_]
		Double_t        TracklikePrimaryDaughters_MeandEdX_ThreePlane[kMaxTracklikePrimaryDaughters];   //[TracklikePrimaryDaughters_]
		Double_t        TracklikePrimaryDaughters_Track_LLR_PID[kMaxTracklikePrimaryDaughters];   //[TracklikePrimaryDaughters_]
		Double_t        TracklikePrimaryDaughters_ProtonMomentum[kMaxTracklikePrimaryDaughters];   //[TracklikePrimaryDaughters_]
		Double_t        TracklikePrimaryDaughters_MuonMomentum[kMaxTracklikePrimaryDaughters];   //[TracklikePrimaryDaughters_]
		Bool_t          TracklikePrimaryDaughters_HasTruth[kMaxTracklikePrimaryDaughters];   //[TracklikePrimaryDaughters_]
		Int_t           TracklikePrimaryDaughters_TrackTruePDG[kMaxTracklikePrimaryDaughters];   //[TracklikePrimaryDaughters_]
		Double_t        TracklikePrimaryDaughters_TrackTrueE[kMaxTracklikePrimaryDaughters];   //[TracklikePrimaryDaughters_]
		Double_t        TracklikePrimaryDaughters_TrackTruePx[kMaxTracklikePrimaryDaughters];   //[TracklikePrimaryDaughters_]
		Double_t        TracklikePrimaryDaughters_TrackTruePy[kMaxTracklikePrimaryDaughters];   //[TracklikePrimaryDaughters_]
		Double_t        TracklikePrimaryDaughters_TrackTruePz[kMaxTracklikePrimaryDaughters];   //[TracklikePrimaryDaughters_]
		Double_t        TracklikePrimaryDaughters_TrackTrueModMomentum[kMaxTracklikePrimaryDaughters];   //[TracklikePrimaryDaughters_]
		Double_t        TracklikePrimaryDaughters_TrackTrueKE[kMaxTracklikePrimaryDaughters];   //[TracklikePrimaryDaughters_]
		Double_t        TracklikePrimaryDaughters_TrackTrueLength[kMaxTracklikePrimaryDaughters];   //[TracklikePrimaryDaughters_]
		Int_t           TracklikePrimaryDaughters_TrackTrueOrigin[kMaxTracklikePrimaryDaughters];   //[TracklikePrimaryDaughters_]
		Double_t        TracklikePrimaryDaughters_TrackTrueTotalEdep[kMaxTracklikePrimaryDaughters];   //[TracklikePrimaryDaughters_]
		Double_t        TracklikePrimaryDaughters_TrackEdepPurity[kMaxTracklikePrimaryDaughters];   //[TracklikePrimaryDaughters_]
		Int_t           ShowerlikePrimaryDaughters_;
   		Int_t           ShowerlikePrimaryDaughters_Index[kMaxShowerlikePrimaryDaughters];   //[ShowerlikePrimaryDaughters_]
		Int_t           ShowerlikePrimaryDaughters_PDG[kMaxShowerlikePrimaryDaughters];   //[ShowerlikePrimaryDaughters_]
		Double_t        ShowerlikePrimaryDaughters_TrackShowerScore[kMaxShowerlikePrimaryDaughters];   //[ShowerlikePrimaryDaughters_]
		Double_t        ShowerlikePrimaryDaughters_X[kMaxShowerlikePrimaryDaughters];   //[ShowerlikePrimaryDaughters_]
		Double_t        ShowerlikePrimaryDaughters_Y[kMaxShowerlikePrimaryDaughters];   //[ShowerlikePrimaryDaughters_]
		Double_t        ShowerlikePrimaryDaughters_Z[kMaxShowerlikePrimaryDaughters];   //[ShowerlikePrimaryDaughters_]
		Double_t        ShowerlikePrimaryDaughters_Displacement[kMaxShowerlikePrimaryDaughters];   //[ShowerlikePrimaryDaughters_]
		Double_t        ShowerlikePrimaryDaughters_TrackLength[kMaxShowerlikePrimaryDaughters];   //[ShowerlikePrimaryDaughters_]
		Double_t        ShowerlikePrimaryDaughters_TrackDirectionX[kMaxShowerlikePrimaryDaughters];   //[ShowerlikePrimaryDaughters_]
		Double_t        ShowerlikePrimaryDaughters_TrackDirectionY[kMaxShowerlikePrimaryDaughters];   //[ShowerlikePrimaryDaughters_]
		Double_t        ShowerlikePrimaryDaughters_TrackDirectionZ[kMaxShowerlikePrimaryDaughters];   //[ShowerlikePrimaryDaughters_]
		Double_t        ShowerlikePrimaryDaughters_TrackStartX[kMaxShowerlikePrimaryDaughters];   //[ShowerlikePrimaryDaughters_]
		Double_t        ShowerlikePrimaryDaughters_TrackStartY[kMaxShowerlikePrimaryDaughters];   //[ShowerlikePrimaryDaughters_]
		Double_t        ShowerlikePrimaryDaughters_TrackStartZ[kMaxShowerlikePrimaryDaughters];   //[ShowerlikePrimaryDaughters_]
		Double_t        ShowerlikePrimaryDaughters_TrackEndX[kMaxShowerlikePrimaryDaughters];   //[ShowerlikePrimaryDaughters_]
		Double_t        ShowerlikePrimaryDaughters_TrackEndY[kMaxShowerlikePrimaryDaughters];   //[ShowerlikePrimaryDaughters_]
		Double_t        ShowerlikePrimaryDaughters_TrackEndZ[kMaxShowerlikePrimaryDaughters];   //[ShowerlikePrimaryDaughters_]
		Double_t        ShowerlikePrimaryDaughters_TrackMuonClosestApproachPosition[kMaxShowerlikePrimaryDaughters];   //[ShowerlikePrimaryDaughters_]
		Double_t        ShowerlikePrimaryDaughters_TrackMuonClosestApproachDistance[kMaxShowerlikePrimaryDaughters];   //[ShowerlikePrimaryDaughters_]
		Double_t        ShowerlikePrimaryDaughters_TrackPID[kMaxShowerlikePrimaryDaughters];   //[ShowerlikePrimaryDaughters_]
		Double_t        ShowerlikePrimaryDaughters_MeandEdX_Plane0[kMaxShowerlikePrimaryDaughters];   //[ShowerlikePrimaryDaughters_]
		Double_t        ShowerlikePrimaryDaughters_MeandEdX_Plane1[kMaxShowerlikePrimaryDaughters];   //[ShowerlikePrimaryDaughters_]
		Double_t        ShowerlikePrimaryDaughters_MeandEdX_Plane2[kMaxShowerlikePrimaryDaughters];   //[ShowerlikePrimaryDaughters_]
		Double_t        ShowerlikePrimaryDaughters_MeandEdX_ThreePlane[kMaxShowerlikePrimaryDaughters];   //[ShowerlikePrimaryDaughters_]
		Double_t        ShowerlikePrimaryDaughters_Track_LLR_PID[kMaxShowerlikePrimaryDaughters];   //[ShowerlikePrimaryDaughters_]
		Double_t        ShowerlikePrimaryDaughters_ProtonMomentum[kMaxShowerlikePrimaryDaughters];   //[ShowerlikePrimaryDaughters_]
		Double_t        ShowerlikePrimaryDaughters_MuonMomentum[kMaxShowerlikePrimaryDaughters];   //[ShowerlikePrimaryDaughters_]
		Bool_t          ShowerlikePrimaryDaughters_HasTruth[kMaxShowerlikePrimaryDaughters];   //[ShowerlikePrimaryDaughters_]
		Int_t           ShowerlikePrimaryDaughters_TrackTruePDG[kMaxShowerlikePrimaryDaughters];   //[ShowerlikePrimaryDaughters_]
		Double_t        ShowerlikePrimaryDaughters_TrackTrueE[kMaxShowerlikePrimaryDaughters];   //[ShowerlikePrimaryDaughters_]
		Double_t        ShowerlikePrimaryDaughters_TrackTruePx[kMaxShowerlikePrimaryDaughters];   //[ShowerlikePrimaryDaughters_]
		Double_t        ShowerlikePrimaryDaughters_TrackTruePy[kMaxShowerlikePrimaryDaughters];   //[ShowerlikePrimaryDaughters_]
		Double_t        ShowerlikePrimaryDaughters_TrackTruePz[kMaxShowerlikePrimaryDaughters];   //[ShowerlikePrimaryDaughters_]
		Double_t        ShowerlikePrimaryDaughters_TrackTrueModMomentum[kMaxShowerlikePrimaryDaughters];   //[ShowerlikePrimaryDaughters_]
		Double_t        ShowerlikePrimaryDaughters_TrackTrueKE[kMaxShowerlikePrimaryDaughters];   //[ShowerlikePrimaryDaughters_]
		Double_t        ShowerlikePrimaryDaughters_TrackTrueLength[kMaxShowerlikePrimaryDaughters];   //[ShowerlikePrimaryDaughters_]
		Int_t           ShowerlikePrimaryDaughters_TrackTrueOrigin[kMaxShowerlikePrimaryDaughters];   //[ShowerlikePrimaryDaughters_]
		Double_t        ShowerlikePrimaryDaughters_TrackTrueTotalEdep[kMaxShowerlikePrimaryDaughters];   //[ShowerlikePrimaryDaughters_]
		Double_t        ShowerlikePrimaryDaughters_TrackEdepPurity[kMaxShowerlikePrimaryDaughters];   //[ShowerlikePrimaryDaughters_]
		Int_t           MuonIndex;

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
                vector<std::string> *SysDials=0;
                vector<vector<double>> *SysWeights=0;

		Int_t           TrueMuonIndex;
		Int_t           TrueDecayProtonIndex;
		Int_t           TrueDecayPionIndex;


};

#endif
