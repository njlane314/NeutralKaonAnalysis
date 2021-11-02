#ifndef _EventAssembler_cxx_
#define _EventAssembler_cxx_

#include "EventAssembler.h"

void EventAssembler::SetFile(std::string infilename){

   DataDir = getenv("DATA_DIR");         

   TString file = DataDir + TString("/") +  TString(infilename);

   f_in = TFile::Open( file );

   f_in->GetObject("ana/OutputTree",t_in);
   //f_in->GetObject("HyperonNTuples/OutputTree",t_in);

   nEvents = t_in->GetEntries();

   //disable all branches
   t_in->SetMakeClass(1);
   t_in->SetBranchStatus("*",0);


   t_in->SetBranchStatus("IsData",1);
   t_in->SetBranchStatus("EventID",1);
   t_in->SetBranchStatus("run",1);
   t_in->SetBranchStatus("subrun",1);
   t_in->SetBranchStatus("event",1);
   t_in->SetBranchStatus("Mode",1);
   t_in->SetBranchStatus("CCNC",1);
   t_in->SetBranchStatus("InActiveTPC",1);
   t_in->SetBranchStatus("IsHyperon",1);
   t_in->SetBranchStatus("IsSigmaZero",1);
   t_in->SetBranchStatus("IsLambda",1);
   t_in->SetBranchStatus("IsLambdaCharged",1);
   t_in->SetBranchStatus("IsSignal",1);
   t_in->SetBranchStatus("GoodReco",1);
   t_in->SetBranchStatus("IsAssociatedHyperon",1);
   t_in->SetBranchStatus("SelectedEvent",1);
   t_in->SetBranchStatus("NMCTruths",1);
   t_in->SetBranchStatus("Weight",1);
   t_in->SetBranchStatus("Neutrino",1);
   t_in->SetBranchStatus("Neutrino.PDG",1);
   t_in->SetBranchStatus("Neutrino.E",1);
   t_in->SetBranchStatus("Neutrino.Px",1);
   t_in->SetBranchStatus("Neutrino.Py",1);
   t_in->SetBranchStatus("Neutrino.Pz",1);
   t_in->SetBranchStatus("Neutrino.ModMomentum",1);
   t_in->SetBranchStatus("Neutrino.KE",1);
   t_in->SetBranchStatus("Neutrino.StartX",1);
   t_in->SetBranchStatus("Neutrino.StartY",1);
   t_in->SetBranchStatus("Neutrino.StartZ",1);
   t_in->SetBranchStatus("Neutrino.EndX",1);
   t_in->SetBranchStatus("Neutrino.EndY",1);
   t_in->SetBranchStatus("Neutrino.EndZ",1);
   t_in->SetBranchStatus("Neutrino.Travel",1);
   t_in->SetBranchStatus("Neutrino.Theta",1);
   t_in->SetBranchStatus("Neutrino.Phi",1);
   t_in->SetBranchStatus("Neutrino.Origin",1);
   t_in->SetBranchStatus("TruePrimaryVertex",1);
   t_in->SetBranchStatus("Lepton",1);
   t_in->SetBranchStatus("Lepton.PDG",1);
   t_in->SetBranchStatus("Lepton.E",1);
   t_in->SetBranchStatus("Lepton.Px",1);
   t_in->SetBranchStatus("Lepton.Py",1);
   t_in->SetBranchStatus("Lepton.Pz",1);
   t_in->SetBranchStatus("Lepton.ModMomentum",1);
   t_in->SetBranchStatus("Lepton.KE",1);
   t_in->SetBranchStatus("Lepton.StartX",1);
   t_in->SetBranchStatus("Lepton.StartY",1);
   t_in->SetBranchStatus("Lepton.StartZ",1);
   t_in->SetBranchStatus("Lepton.EndX",1);
   t_in->SetBranchStatus("Lepton.EndY",1);
   t_in->SetBranchStatus("Lepton.EndZ",1);
   t_in->SetBranchStatus("Lepton.Travel",1);
   t_in->SetBranchStatus("Lepton.Theta",1);
   t_in->SetBranchStatus("Lepton.Phi",1);
   t_in->SetBranchStatus("Lepton.Origin",1);
   t_in->SetBranchStatus("Hyperon",1);
   t_in->SetBranchStatus("Hyperon.PDG",1);
   t_in->SetBranchStatus("Hyperon.E",1);
   t_in->SetBranchStatus("Hyperon.Px",1);
   t_in->SetBranchStatus("Hyperon.Py",1);
   t_in->SetBranchStatus("Hyperon.Pz",1);
   t_in->SetBranchStatus("Hyperon.ModMomentum",1);
   t_in->SetBranchStatus("Hyperon.KE",1);
   t_in->SetBranchStatus("Hyperon.StartX",1);
   t_in->SetBranchStatus("Hyperon.StartY",1);
   t_in->SetBranchStatus("Hyperon.StartZ",1);
   t_in->SetBranchStatus("Hyperon.EndX",1);
   t_in->SetBranchStatus("Hyperon.EndY",1);
   t_in->SetBranchStatus("Hyperon.EndZ",1);
   t_in->SetBranchStatus("Hyperon.Travel",1);
   t_in->SetBranchStatus("Hyperon.Theta",1);
   t_in->SetBranchStatus("Hyperon.Phi",1);
   t_in->SetBranchStatus("Hyperon.Origin",1);
   t_in->SetBranchStatus("PrimaryNucleon",1);
   t_in->SetBranchStatus("PrimaryNucleon.PDG",1);
   t_in->SetBranchStatus("PrimaryNucleon.E",1);
   t_in->SetBranchStatus("PrimaryNucleon.Px",1);
   t_in->SetBranchStatus("PrimaryNucleon.Py",1);
   t_in->SetBranchStatus("PrimaryNucleon.Pz",1);
   t_in->SetBranchStatus("PrimaryNucleon.ModMomentum",1);
   t_in->SetBranchStatus("PrimaryNucleon.KE",1);
   t_in->SetBranchStatus("PrimaryNucleon.StartX",1);
   t_in->SetBranchStatus("PrimaryNucleon.StartY",1);
   t_in->SetBranchStatus("PrimaryNucleon.StartZ",1);
   t_in->SetBranchStatus("PrimaryNucleon.EndX",1);
   t_in->SetBranchStatus("PrimaryNucleon.EndY",1);
   t_in->SetBranchStatus("PrimaryNucleon.EndZ",1);
   t_in->SetBranchStatus("PrimaryNucleon.Travel",1);
   t_in->SetBranchStatus("PrimaryNucleon.Theta",1);
   t_in->SetBranchStatus("PrimaryNucleon.Phi",1);
   t_in->SetBranchStatus("PrimaryNucleon.Origin",1);
   t_in->SetBranchStatus("PrimaryPion",1);
   t_in->SetBranchStatus("PrimaryPion.PDG",1);
   t_in->SetBranchStatus("PrimaryPion.E",1);
   t_in->SetBranchStatus("PrimaryPion.Px",1);
   t_in->SetBranchStatus("PrimaryPion.Py",1);
   t_in->SetBranchStatus("PrimaryPion.Pz",1);
   t_in->SetBranchStatus("PrimaryPion.ModMomentum",1);
   t_in->SetBranchStatus("PrimaryPion.KE",1);
   t_in->SetBranchStatus("PrimaryPion.StartX",1);
   t_in->SetBranchStatus("PrimaryPion.StartY",1);
   t_in->SetBranchStatus("PrimaryPion.StartZ",1);
   t_in->SetBranchStatus("PrimaryPion.EndX",1);
   t_in->SetBranchStatus("PrimaryPion.EndY",1);
   t_in->SetBranchStatus("PrimaryPion.EndZ",1);
   t_in->SetBranchStatus("PrimaryPion.Travel",1);
   t_in->SetBranchStatus("PrimaryPion.Theta",1);
   t_in->SetBranchStatus("PrimaryPion.Phi",1);
   t_in->SetBranchStatus("PrimaryPion.Origin",1);
   t_in->SetBranchStatus("DecayVertex",1);
   t_in->SetBranchStatus("Decay",1);
   t_in->SetBranchStatus("Decay.PDG",1);
   t_in->SetBranchStatus("Decay.E",1);
   t_in->SetBranchStatus("Decay.Px",1);
   t_in->SetBranchStatus("Decay.Py",1);
   t_in->SetBranchStatus("Decay.Pz",1);
   t_in->SetBranchStatus("Decay.ModMomentum",1);
   t_in->SetBranchStatus("Decay.KE",1);
   t_in->SetBranchStatus("Decay.StartX",1);
   t_in->SetBranchStatus("Decay.StartY",1);
   t_in->SetBranchStatus("Decay.StartZ",1);
   t_in->SetBranchStatus("Decay.EndX",1);
   t_in->SetBranchStatus("Decay.EndY",1);
   t_in->SetBranchStatus("Decay.EndZ",1);
   t_in->SetBranchStatus("Decay.Travel",1);
   t_in->SetBranchStatus("Decay.Theta",1);
   t_in->SetBranchStatus("Decay.Phi",1);
   t_in->SetBranchStatus("Decay.Origin",1);
   t_in->SetBranchStatus("SigmaZeroDecayPhoton",1);
   t_in->SetBranchStatus("SigmaZeroDecayPhoton.PDG",1);
   t_in->SetBranchStatus("SigmaZeroDecayPhoton.E",1);
   t_in->SetBranchStatus("SigmaZeroDecayPhoton.Px",1);
   t_in->SetBranchStatus("SigmaZeroDecayPhoton.Py",1);
   t_in->SetBranchStatus("SigmaZeroDecayPhoton.Pz",1);
   t_in->SetBranchStatus("SigmaZeroDecayPhoton.ModMomentum",1);
   t_in->SetBranchStatus("SigmaZeroDecayPhoton.KE",1);
   t_in->SetBranchStatus("SigmaZeroDecayPhoton.StartX",1);
   t_in->SetBranchStatus("SigmaZeroDecayPhoton.StartY",1);
   t_in->SetBranchStatus("SigmaZeroDecayPhoton.StartZ",1);
   t_in->SetBranchStatus("SigmaZeroDecayPhoton.EndX",1);
   t_in->SetBranchStatus("SigmaZeroDecayPhoton.EndY",1);
   t_in->SetBranchStatus("SigmaZeroDecayPhoton.EndZ",1);
   t_in->SetBranchStatus("SigmaZeroDecayPhoton.Travel",1);
   t_in->SetBranchStatus("SigmaZeroDecayPhoton.Theta",1);
   t_in->SetBranchStatus("SigmaZeroDecayPhoton.Phi",1);
   t_in->SetBranchStatus("SigmaZeroDecayPhoton.Origin",1);
   t_in->SetBranchStatus("SigmaZeroDecayLambda",1);
   t_in->SetBranchStatus("SigmaZeroDecayLambda.PDG",1);
   t_in->SetBranchStatus("SigmaZeroDecayLambda.E",1);
   t_in->SetBranchStatus("SigmaZeroDecayLambda.Px",1);
   t_in->SetBranchStatus("SigmaZeroDecayLambda.Py",1);
   t_in->SetBranchStatus("SigmaZeroDecayLambda.Pz",1);
   t_in->SetBranchStatus("SigmaZeroDecayLambda.ModMomentum",1);
   t_in->SetBranchStatus("SigmaZeroDecayLambda.KE",1);
   t_in->SetBranchStatus("SigmaZeroDecayLambda.StartX",1);
   t_in->SetBranchStatus("SigmaZeroDecayLambda.StartY",1);
   t_in->SetBranchStatus("SigmaZeroDecayLambda.StartZ",1);
   t_in->SetBranchStatus("SigmaZeroDecayLambda.EndX",1);
   t_in->SetBranchStatus("SigmaZeroDecayLambda.EndY",1);
   t_in->SetBranchStatus("SigmaZeroDecayLambda.EndZ",1);
   t_in->SetBranchStatus("SigmaZeroDecayLambda.Travel",1);
   t_in->SetBranchStatus("SigmaZeroDecayLambda.Theta",1);
   t_in->SetBranchStatus("SigmaZeroDecayLambda.Phi",1);
   t_in->SetBranchStatus("SigmaZeroDecayLambda.Origin",1);
   t_in->SetBranchStatus("DecayOpeningAngle",1);
   t_in->SetBranchStatus("LeptonPionAngle",1);
   t_in->SetBranchStatus("LeptonNucleonAngle",1);
   t_in->SetBranchStatus("RecoPrimaryVertex",1);
   t_in->SetBranchStatus("NPrimaryTrackDaughters",1);
   t_in->SetBranchStatus("NPrimaryShowerDaughters",1);
   t_in->SetBranchStatus("TracklikePrimaryDaughters",1);
   t_in->SetBranchStatus("TracklikePrimaryDaughters.Index",1);
   t_in->SetBranchStatus("TracklikePrimaryDaughters.PDG",1);
   t_in->SetBranchStatus("TracklikePrimaryDaughters.TrackShowerScore",1);
   t_in->SetBranchStatus("TracklikePrimaryDaughters.X",1);
   t_in->SetBranchStatus("TracklikePrimaryDaughters.Y",1);
   t_in->SetBranchStatus("TracklikePrimaryDaughters.Z",1);
   t_in->SetBranchStatus("TracklikePrimaryDaughters.Displacement",1);
   t_in->SetBranchStatus("TracklikePrimaryDaughters.TrackLength",1);
   t_in->SetBranchStatus("TracklikePrimaryDaughters.TrackDirectionX",1);
   t_in->SetBranchStatus("TracklikePrimaryDaughters.TrackDirectionY",1);
   t_in->SetBranchStatus("TracklikePrimaryDaughters.TrackDirectionZ",1);
   t_in->SetBranchStatus("TracklikePrimaryDaughters.TrackStartX",1);
   t_in->SetBranchStatus("TracklikePrimaryDaughters.TrackStartY",1);
   t_in->SetBranchStatus("TracklikePrimaryDaughters.TrackStartZ",1);
   t_in->SetBranchStatus("TracklikePrimaryDaughters.TrackEndX",1);
   t_in->SetBranchStatus("TracklikePrimaryDaughters.TrackEndY",1);
   t_in->SetBranchStatus("TracklikePrimaryDaughters.TrackEndZ",1);
   t_in->SetBranchStatus("TracklikePrimaryDaughters.TrackMuonClosestApproachPosition",1);
   t_in->SetBranchStatus("TracklikePrimaryDaughters.TrackMuonClosestApproachDistance",1);
   t_in->SetBranchStatus("TracklikePrimaryDaughters.TrackPID",1);
   t_in->SetBranchStatus("TracklikePrimaryDaughters.MeandEdX_Plane0",1);
   t_in->SetBranchStatus("TracklikePrimaryDaughters.MeandEdX_Plane1",1);
   t_in->SetBranchStatus("TracklikePrimaryDaughters.MeandEdX_Plane2",1);
   t_in->SetBranchStatus("TracklikePrimaryDaughters.MeandEdX_ThreePlane",1);
   t_in->SetBranchStatus("TracklikePrimaryDaughters.Track_LLR_PID",1);
   t_in->SetBranchStatus("TracklikePrimaryDaughters.ProtonMomentum",1);
   t_in->SetBranchStatus("TracklikePrimaryDaughters.MuonMomentum",1);
   t_in->SetBranchStatus("TracklikePrimaryDaughters.HasTruth",1);
   t_in->SetBranchStatus("TracklikePrimaryDaughters.TrackTruePDG",1);
   t_in->SetBranchStatus("TracklikePrimaryDaughters.TrackTrueE",1);
   t_in->SetBranchStatus("TracklikePrimaryDaughters.TrackTruePx",1);
   t_in->SetBranchStatus("TracklikePrimaryDaughters.TrackTruePy",1);
   t_in->SetBranchStatus("TracklikePrimaryDaughters.TrackTruePz",1);
   t_in->SetBranchStatus("TracklikePrimaryDaughters.TrackTrueModMomentum",1);
   t_in->SetBranchStatus("TracklikePrimaryDaughters.TrackTrueKE",1);
   t_in->SetBranchStatus("TracklikePrimaryDaughters.TrackTrueLength",1);
   t_in->SetBranchStatus("TracklikePrimaryDaughters.TrackTrueOrigin",1);
   //t_in->SetBranchStatus("TracklikePrimaryDaughters.TrackTrueTotalEdep",1);
   t_in->SetBranchStatus("TracklikePrimaryDaughters.TrackEdepPurity",1);
   t_in->SetBranchStatus("ShowerlikePrimaryDaughters",1);
   t_in->SetBranchStatus("ShowerlikePrimaryDaughters.Index",1);
   t_in->SetBranchStatus("ShowerlikePrimaryDaughters.PDG",1);
   t_in->SetBranchStatus("ShowerlikePrimaryDaughters.TrackShowerScore",1);
   t_in->SetBranchStatus("ShowerlikePrimaryDaughters.X",1);
   t_in->SetBranchStatus("ShowerlikePrimaryDaughters.Y",1);
   t_in->SetBranchStatus("ShowerlikePrimaryDaughters.Z",1);
   t_in->SetBranchStatus("ShowerlikePrimaryDaughters.Displacement",1);
   t_in->SetBranchStatus("ShowerlikePrimaryDaughters.TrackLength",1);
   t_in->SetBranchStatus("ShowerlikePrimaryDaughters.TrackDirectionX",1);
   t_in->SetBranchStatus("ShowerlikePrimaryDaughters.TrackDirectionY",1);
   t_in->SetBranchStatus("ShowerlikePrimaryDaughters.TrackDirectionZ",1);
   t_in->SetBranchStatus("ShowerlikePrimaryDaughters.TrackStartX",1);
   t_in->SetBranchStatus("ShowerlikePrimaryDaughters.TrackStartY",1);
   t_in->SetBranchStatus("ShowerlikePrimaryDaughters.TrackStartZ",1);
   t_in->SetBranchStatus("ShowerlikePrimaryDaughters.TrackEndX",1);
   t_in->SetBranchStatus("ShowerlikePrimaryDaughters.TrackEndY",1);
   t_in->SetBranchStatus("ShowerlikePrimaryDaughters.TrackEndZ",1);
   t_in->SetBranchStatus("ShowerlikePrimaryDaughters.TrackMuonClosestApproachPosition",1);
   t_in->SetBranchStatus("ShowerlikePrimaryDaughters.TrackMuonClosestApproachDistance",1);
   t_in->SetBranchStatus("ShowerlikePrimaryDaughters.TrackPID",1);
   t_in->SetBranchStatus("ShowerlikePrimaryDaughters.MeandEdX_Plane0",1);
   t_in->SetBranchStatus("ShowerlikePrimaryDaughters.MeandEdX_Plane1",1);
   t_in->SetBranchStatus("ShowerlikePrimaryDaughters.MeandEdX_Plane2",1);
   t_in->SetBranchStatus("ShowerlikePrimaryDaughters.MeandEdX_ThreePlane",1);
   t_in->SetBranchStatus("ShowerlikePrimaryDaughters.Track_LLR_PID",1);
   t_in->SetBranchStatus("ShowerlikePrimaryDaughters.ProtonMomentum",1);
   t_in->SetBranchStatus("ShowerlikePrimaryDaughters.MuonMomentum",1);
   t_in->SetBranchStatus("ShowerlikePrimaryDaughters.HasTruth",1);
   t_in->SetBranchStatus("ShowerlikePrimaryDaughters.TrackTruePDG",1);
   t_in->SetBranchStatus("ShowerlikePrimaryDaughters.TrackTrueE",1);
   t_in->SetBranchStatus("ShowerlikePrimaryDaughters.TrackTruePx",1);
   t_in->SetBranchStatus("ShowerlikePrimaryDaughters.TrackTruePy",1);
   t_in->SetBranchStatus("ShowerlikePrimaryDaughters.TrackTruePz",1);
   t_in->SetBranchStatus("ShowerlikePrimaryDaughters.TrackTrueModMomentum",1);
   t_in->SetBranchStatus("ShowerlikePrimaryDaughters.TrackTrueKE",1);
   t_in->SetBranchStatus("ShowerlikePrimaryDaughters.TrackTrueLength",1);
   t_in->SetBranchStatus("ShowerlikePrimaryDaughters.TrackTrueOrigin",1);
   //t_in->SetBranchStatus("ShowerlikePrimaryDaughters.TrackTrueTotalEdep",1);
   t_in->SetBranchStatus("ShowerlikePrimaryDaughters.TrackEdepPurity",1);
   t_in->SetBranchStatus("MuonIndex",1);
   t_in->SetBranchStatus("TrueMuonIndex",1);
   t_in->SetBranchStatus("TrueDecayProtonIndex",1);
   t_in->SetBranchStatus("TrueDecayPionIndex",1);
/*
   t_in->SetBranchStatus("ConnSeedIndexes_Plane0",1);
   t_in->SetBranchStatus("ConnOutputIndexes_Plane0",1);
   t_in->SetBranchStatus("ConnOutputSizes_Plane0",1);
   t_in->SetBranchStatus("ConnSeedChannels_Plane0",1);
   t_in->SetBranchStatus("ConnSeedTicks_Plane0",1);
   t_in->SetBranchStatus("ConnSeedIndexes_Plane1",1);
   t_in->SetBranchStatus("ConnOutputIndexes_Plane1",1);
   t_in->SetBranchStatus("ConnOutputSizes_Plane1",1);
   t_in->SetBranchStatus("ConnSeedChannels_Plane1",1);
   t_in->SetBranchStatus("ConnSeedTicks_Plane1",1);
   t_in->SetBranchStatus("ConnSeedIndexes_Plane2",1);
   t_in->SetBranchStatus("ConnOutputIndexes_Plane2",1);
   t_in->SetBranchStatus("ConnOutputSizes_Plane2",1);
   t_in->SetBranchStatus("ConnSeedChannels_Plane2",1);
   t_in->SetBranchStatus("ConnSeedTicks_Plane2",1);
   t_in->SetBranchStatus("SysDials",1);
   t_in->SetBranchStatus("SysWeights",1);
*/

   //activate all the desired branches
   t_in->SetBranchAddress("IsData", &IsData);
   t_in->SetBranchAddress("EventID", &EventID);
   t_in->SetBranchAddress("run", &run);
   t_in->SetBranchAddress("subrun", &subrun);
   t_in->SetBranchAddress("event", &event);
   t_in->SetBranchAddress("Mode", &Mode);
   t_in->SetBranchAddress("CCNC", &CCNC);
   t_in->SetBranchAddress("InActiveTPC", &InActiveTPC);
   t_in->SetBranchAddress("IsHyperon", &IsHyperon);
   t_in->SetBranchAddress("IsSigmaZero", &IsSigmaZero);
   t_in->SetBranchAddress("IsLambda", &IsLambda);
   t_in->SetBranchAddress("IsLambdaCharged", &IsLambdaCharged);
   t_in->SetBranchAddress("IsSignal", &IsSignal);
   t_in->SetBranchAddress("GoodReco", &GoodReco);
   t_in->SetBranchAddress("IsAssociatedHyperon", &IsAssociatedHyperon);
   t_in->SetBranchAddress("NMCTruths", &NMCTruths);
   t_in->SetBranchAddress("SelectedEvent", &SelectedEvent); 
   t_in->SetBranchAddress("Weight", &Weight); 
   t_in->SetBranchAddress("Neutrino", &Neutrino_);
   t_in->SetBranchAddress("Neutrino.PDG", Neutrino_PDG);
   t_in->SetBranchAddress("Neutrino.E", Neutrino_E);
   t_in->SetBranchAddress("Neutrino.Px", Neutrino_Px);
   t_in->SetBranchAddress("Neutrino.Py", Neutrino_Py);
   t_in->SetBranchAddress("Neutrino.Pz", Neutrino_Pz);
   t_in->SetBranchAddress("Neutrino.ModMomentum", Neutrino_ModMomentum);
   t_in->SetBranchAddress("Neutrino.KE", Neutrino_KE);
   t_in->SetBranchAddress("Neutrino.StartX", Neutrino_StartX);
   t_in->SetBranchAddress("Neutrino.StartY", Neutrino_StartY);
   t_in->SetBranchAddress("Neutrino.StartZ", Neutrino_StartZ);
   t_in->SetBranchAddress("Neutrino.EndX", Neutrino_EndX);
   t_in->SetBranchAddress("Neutrino.EndY", Neutrino_EndY);
   t_in->SetBranchAddress("Neutrino.EndZ", Neutrino_EndZ);
   t_in->SetBranchAddress("Neutrino.Travel", Neutrino_Travel);
   t_in->SetBranchAddress("Neutrino.Theta", Neutrino_Theta);
   t_in->SetBranchAddress("Neutrino.Phi", Neutrino_Phi);
   t_in->SetBranchAddress("Neutrino.Origin", Neutrino_Origin);
   t_in->SetBranchAddress("TruePrimaryVertex", &TruePrimaryVertex);
   t_in->SetBranchAddress("Lepton", &Lepton_);
   t_in->SetBranchAddress("Lepton.PDG", Lepton_PDG);
   t_in->SetBranchAddress("Lepton.E", Lepton_E);
   t_in->SetBranchAddress("Lepton.Px", Lepton_Px);
   t_in->SetBranchAddress("Lepton.Py", Lepton_Py);
   t_in->SetBranchAddress("Lepton.Pz", Lepton_Pz);
   t_in->SetBranchAddress("Lepton.ModMomentum", Lepton_ModMomentum);
   t_in->SetBranchAddress("Lepton.KE", Lepton_KE);
   t_in->SetBranchAddress("Lepton.StartX", Lepton_StartX);
   t_in->SetBranchAddress("Lepton.StartY", Lepton_StartY);
   t_in->SetBranchAddress("Lepton.StartZ", Lepton_StartZ);
   t_in->SetBranchAddress("Lepton.EndX", Lepton_EndX);
   t_in->SetBranchAddress("Lepton.EndY", Lepton_EndY);
   t_in->SetBranchAddress("Lepton.EndZ", Lepton_EndZ);
   t_in->SetBranchAddress("Lepton.Travel", Lepton_Travel);
   t_in->SetBranchAddress("Lepton.Theta", Lepton_Theta);
   t_in->SetBranchAddress("Lepton.Phi", Lepton_Phi);
   t_in->SetBranchAddress("Lepton.Origin", Lepton_Origin);
   t_in->SetBranchAddress("Hyperon", &Hyperon_);
   t_in->SetBranchAddress("Hyperon.PDG", Hyperon_PDG);
   t_in->SetBranchAddress("Hyperon.E", Hyperon_E);
   t_in->SetBranchAddress("Hyperon.Px", Hyperon_Px);
   t_in->SetBranchAddress("Hyperon.Py", Hyperon_Py);
   t_in->SetBranchAddress("Hyperon.Pz", Hyperon_Pz);
   t_in->SetBranchAddress("Hyperon.ModMomentum", Hyperon_ModMomentum);
   t_in->SetBranchAddress("Hyperon.KE", Hyperon_KE);
   t_in->SetBranchAddress("Hyperon.StartX", Hyperon_StartX);
   t_in->SetBranchAddress("Hyperon.StartY", Hyperon_StartY);
   t_in->SetBranchAddress("Hyperon.StartZ", Hyperon_StartZ);
   t_in->SetBranchAddress("Hyperon.EndX", Hyperon_EndX);
   t_in->SetBranchAddress("Hyperon.EndY", Hyperon_EndY);
   t_in->SetBranchAddress("Hyperon.EndZ", Hyperon_EndZ);
   t_in->SetBranchAddress("Hyperon.Travel", Hyperon_Travel);
   t_in->SetBranchAddress("Hyperon.Theta", Hyperon_Theta);
   t_in->SetBranchAddress("Hyperon.Phi", Hyperon_Phi);
   t_in->SetBranchAddress("Hyperon.Origin", Hyperon_Origin);
   t_in->SetBranchAddress("PrimaryNucleon", &PrimaryNucleon_);
   t_in->SetBranchAddress("PrimaryNucleon.PDG", PrimaryNucleon_PDG);
   t_in->SetBranchAddress("PrimaryNucleon.E", PrimaryNucleon_E);
   t_in->SetBranchAddress("PrimaryNucleon.Px", PrimaryNucleon_Px);
   t_in->SetBranchAddress("PrimaryNucleon.Py", PrimaryNucleon_Py);
   t_in->SetBranchAddress("PrimaryNucleon.Pz", PrimaryNucleon_Pz);
   t_in->SetBranchAddress("PrimaryNucleon.ModMomentum", PrimaryNucleon_ModMomentum);
   t_in->SetBranchAddress("PrimaryNucleon.KE", PrimaryNucleon_KE);
   t_in->SetBranchAddress("PrimaryNucleon.StartX", PrimaryNucleon_StartX);
   t_in->SetBranchAddress("PrimaryNucleon.StartY", PrimaryNucleon_StartY);
   t_in->SetBranchAddress("PrimaryNucleon.StartZ", PrimaryNucleon_StartZ);
   t_in->SetBranchAddress("PrimaryNucleon.EndX", PrimaryNucleon_EndX);
   t_in->SetBranchAddress("PrimaryNucleon.EndY", PrimaryNucleon_EndY);
   t_in->SetBranchAddress("PrimaryNucleon.EndZ", PrimaryNucleon_EndZ);
   t_in->SetBranchAddress("PrimaryNucleon.Travel", PrimaryNucleon_Travel);
   t_in->SetBranchAddress("PrimaryNucleon.Theta", PrimaryNucleon_Theta);
   t_in->SetBranchAddress("PrimaryNucleon.Phi", PrimaryNucleon_Phi);
   t_in->SetBranchAddress("PrimaryNucleon.Origin", PrimaryNucleon_Origin);
   t_in->SetBranchAddress("PrimaryPion", &PrimaryPion_);
   t_in->SetBranchAddress("PrimaryPion.PDG", PrimaryPion_PDG);
   t_in->SetBranchAddress("PrimaryPion.E", PrimaryPion_E);
   t_in->SetBranchAddress("PrimaryPion.Px", PrimaryPion_Px);
   t_in->SetBranchAddress("PrimaryPion.Py", PrimaryPion_Py);
   t_in->SetBranchAddress("PrimaryPion.Pz", PrimaryPion_Pz);
   t_in->SetBranchAddress("PrimaryPion.ModMomentum", PrimaryPion_ModMomentum);
   t_in->SetBranchAddress("PrimaryPion.KE", PrimaryPion_KE);
   t_in->SetBranchAddress("PrimaryPion.StartX", PrimaryPion_StartX);
   t_in->SetBranchAddress("PrimaryPion.StartY", PrimaryPion_StartY);
   t_in->SetBranchAddress("PrimaryPion.StartZ", PrimaryPion_StartZ);
   t_in->SetBranchAddress("PrimaryPion.EndX", PrimaryPion_EndX);
   t_in->SetBranchAddress("PrimaryPion.EndY", PrimaryPion_EndY);
   t_in->SetBranchAddress("PrimaryPion.EndZ", PrimaryPion_EndZ);
   t_in->SetBranchAddress("PrimaryPion.Travel", PrimaryPion_Travel);
   t_in->SetBranchAddress("PrimaryPion.Theta", PrimaryPion_Theta);
   t_in->SetBranchAddress("PrimaryPion.Phi", PrimaryPion_Phi);
   t_in->SetBranchAddress("PrimaryPion.Origin", PrimaryPion_Origin);
   t_in->SetBranchAddress("DecayVertex", &DecayVertex);
   t_in->SetBranchAddress("Decay", &Decay_);
   t_in->SetBranchAddress("Decay.PDG", Decay_PDG);
   t_in->SetBranchAddress("Decay.E", Decay_E);
   t_in->SetBranchAddress("Decay.Px", Decay_Px);
   t_in->SetBranchAddress("Decay.Py", Decay_Py);
   t_in->SetBranchAddress("Decay.Pz", Decay_Pz);
   t_in->SetBranchAddress("Decay.ModMomentum", Decay_ModMomentum);
   t_in->SetBranchAddress("Decay.KE", Decay_KE);
   t_in->SetBranchAddress("Decay.StartX", Decay_StartX);
   t_in->SetBranchAddress("Decay.StartY", Decay_StartY);
   t_in->SetBranchAddress("Decay.StartZ", Decay_StartZ);
   t_in->SetBranchAddress("Decay.EndX", Decay_EndX);
   t_in->SetBranchAddress("Decay.EndY", Decay_EndY);
   t_in->SetBranchAddress("Decay.EndZ", Decay_EndZ);
   t_in->SetBranchAddress("Decay.Travel", Decay_Travel);
   t_in->SetBranchAddress("Decay.Theta", Decay_Theta);
   t_in->SetBranchAddress("Decay.Phi", Decay_Phi);
   t_in->SetBranchAddress("Decay.Origin", Decay_Origin);
   t_in->SetBranchAddress("SigmaZeroDecayPhoton", &SigmaZeroDecayPhoton_);
   t_in->SetBranchAddress("SigmaZeroDecayPhoton.PDG", SigmaZeroDecayPhoton_PDG);
   t_in->SetBranchAddress("SigmaZeroDecayPhoton.E", SigmaZeroDecayPhoton_E);
   t_in->SetBranchAddress("SigmaZeroDecayPhoton.Px", SigmaZeroDecayPhoton_Px);
   t_in->SetBranchAddress("SigmaZeroDecayPhoton.Py", SigmaZeroDecayPhoton_Py);
   t_in->SetBranchAddress("SigmaZeroDecayPhoton.Pz", SigmaZeroDecayPhoton_Pz);
   t_in->SetBranchAddress("SigmaZeroDecayPhoton.ModMomentum", SigmaZeroDecayPhoton_ModMomentum);
   t_in->SetBranchAddress("SigmaZeroDecayPhoton.KE", SigmaZeroDecayPhoton_KE);
   t_in->SetBranchAddress("SigmaZeroDecayPhoton.StartX", SigmaZeroDecayPhoton_StartX);
   t_in->SetBranchAddress("SigmaZeroDecayPhoton.StartY", SigmaZeroDecayPhoton_StartY);
   t_in->SetBranchAddress("SigmaZeroDecayPhoton.StartZ", SigmaZeroDecayPhoton_StartZ);
   t_in->SetBranchAddress("SigmaZeroDecayPhoton.EndX", SigmaZeroDecayPhoton_EndX);
   t_in->SetBranchAddress("SigmaZeroDecayPhoton.EndY", SigmaZeroDecayPhoton_EndY);
   t_in->SetBranchAddress("SigmaZeroDecayPhoton.EndZ", SigmaZeroDecayPhoton_EndZ);
   t_in->SetBranchAddress("SigmaZeroDecayPhoton.Travel", SigmaZeroDecayPhoton_Travel);
   t_in->SetBranchAddress("SigmaZeroDecayPhoton.Theta", SigmaZeroDecayPhoton_Theta);
   t_in->SetBranchAddress("SigmaZeroDecayPhoton.Phi", SigmaZeroDecayPhoton_Phi);
   t_in->SetBranchAddress("SigmaZeroDecayPhoton.Origin", SigmaZeroDecayPhoton_Origin);
   t_in->SetBranchAddress("SigmaZeroDecayLambda", &SigmaZeroDecayLambda_);
   t_in->SetBranchAddress("SigmaZeroDecayLambda.PDG", SigmaZeroDecayLambda_PDG);
   t_in->SetBranchAddress("SigmaZeroDecayLambda.E", SigmaZeroDecayLambda_E);
   t_in->SetBranchAddress("SigmaZeroDecayLambda.Px", SigmaZeroDecayLambda_Px);
   t_in->SetBranchAddress("SigmaZeroDecayLambda.Py", SigmaZeroDecayLambda_Py);
   t_in->SetBranchAddress("SigmaZeroDecayLambda.Pz", SigmaZeroDecayLambda_Pz);
   t_in->SetBranchAddress("SigmaZeroDecayLambda.ModMomentum", SigmaZeroDecayLambda_ModMomentum);
   t_in->SetBranchAddress("SigmaZeroDecayLambda.KE", SigmaZeroDecayLambda_KE);
   t_in->SetBranchAddress("SigmaZeroDecayLambda.StartX", SigmaZeroDecayLambda_StartX);
   t_in->SetBranchAddress("SigmaZeroDecayLambda.StartY", SigmaZeroDecayLambda_StartY);
   t_in->SetBranchAddress("SigmaZeroDecayLambda.StartZ", SigmaZeroDecayLambda_StartZ);
   t_in->SetBranchAddress("SigmaZeroDecayLambda.EndX", SigmaZeroDecayLambda_EndX);
   t_in->SetBranchAddress("SigmaZeroDecayLambda.EndY", SigmaZeroDecayLambda_EndY);
   t_in->SetBranchAddress("SigmaZeroDecayLambda.EndZ", SigmaZeroDecayLambda_EndZ);
   t_in->SetBranchAddress("SigmaZeroDecayLambda.Travel", SigmaZeroDecayLambda_Travel);
   t_in->SetBranchAddress("SigmaZeroDecayLambda.Theta", SigmaZeroDecayLambda_Theta);
   t_in->SetBranchAddress("SigmaZeroDecayLambda.Phi", SigmaZeroDecayLambda_Phi);
   t_in->SetBranchAddress("SigmaZeroDecayLambda.Origin", SigmaZeroDecayLambda_Origin);
   t_in->SetBranchAddress("DecayOpeningAngle", &DecayOpeningAngle);
   t_in->SetBranchAddress("LeptonPionAngle", &LeptonPionAngle);
   t_in->SetBranchAddress("LeptonNucleonAngle", &LeptonNucleonAngle);
   t_in->SetBranchAddress("RecoPrimaryVertex", &RecoPrimaryVertex);
   t_in->SetBranchAddress("NPrimaryTrackDaughters", &NPrimaryTrackDaughters);
   t_in->SetBranchAddress("NPrimaryShowerDaughters", &NPrimaryShowerDaughters);
   t_in->SetBranchAddress("TracklikePrimaryDaughters", &TracklikePrimaryDaughters_);
   t_in->SetBranchAddress("TracklikePrimaryDaughters.Index", TracklikePrimaryDaughters_Index);
   t_in->SetBranchAddress("TracklikePrimaryDaughters.PDG", TracklikePrimaryDaughters_PDG);
   t_in->SetBranchAddress("TracklikePrimaryDaughters.TrackShowerScore", TracklikePrimaryDaughters_TrackShowerScore);
   t_in->SetBranchAddress("TracklikePrimaryDaughters.X", TracklikePrimaryDaughters_X);
   t_in->SetBranchAddress("TracklikePrimaryDaughters.Y", TracklikePrimaryDaughters_Y);
   t_in->SetBranchAddress("TracklikePrimaryDaughters.Z", TracklikePrimaryDaughters_Z);
   t_in->SetBranchAddress("TracklikePrimaryDaughters.Displacement", TracklikePrimaryDaughters_Displacement);
   t_in->SetBranchAddress("TracklikePrimaryDaughters.TrackLength", TracklikePrimaryDaughters_TrackLength);
   t_in->SetBranchAddress("TracklikePrimaryDaughters.TrackDirectionX", TracklikePrimaryDaughters_TrackDirectionX);
   t_in->SetBranchAddress("TracklikePrimaryDaughters.TrackDirectionY", TracklikePrimaryDaughters_TrackDirectionY);
   t_in->SetBranchAddress("TracklikePrimaryDaughters.TrackDirectionZ", TracklikePrimaryDaughters_TrackDirectionZ);
   t_in->SetBranchAddress("TracklikePrimaryDaughters.TrackStartX", TracklikePrimaryDaughters_TrackStartX);
   t_in->SetBranchAddress("TracklikePrimaryDaughters.TrackStartY", TracklikePrimaryDaughters_TrackStartY);
   t_in->SetBranchAddress("TracklikePrimaryDaughters.TrackStartZ", TracklikePrimaryDaughters_TrackStartZ);
   t_in->SetBranchAddress("TracklikePrimaryDaughters.TrackEndX", TracklikePrimaryDaughters_TrackEndX);
   t_in->SetBranchAddress("TracklikePrimaryDaughters.TrackEndY", TracklikePrimaryDaughters_TrackEndY);
   t_in->SetBranchAddress("TracklikePrimaryDaughters.TrackEndZ", TracklikePrimaryDaughters_TrackEndZ);
   t_in->SetBranchAddress("TracklikePrimaryDaughters.TrackMuonClosestApproachPosition", TracklikePrimaryDaughters_TrackMuonClosestApproachPosition);
   t_in->SetBranchAddress("TracklikePrimaryDaughters.TrackMuonClosestApproachDistance", TracklikePrimaryDaughters_TrackMuonClosestApproachDistance);
   t_in->SetBranchAddress("TracklikePrimaryDaughters.TrackPID", TracklikePrimaryDaughters_TrackPID);
   t_in->SetBranchAddress("TracklikePrimaryDaughters.MeandEdX_Plane0", TracklikePrimaryDaughters_MeandEdX_Plane0);
   t_in->SetBranchAddress("TracklikePrimaryDaughters.MeandEdX_Plane1", TracklikePrimaryDaughters_MeandEdX_Plane1);
   t_in->SetBranchAddress("TracklikePrimaryDaughters.MeandEdX_Plane2", TracklikePrimaryDaughters_MeandEdX_Plane2);
   t_in->SetBranchAddress("TracklikePrimaryDaughters.MeandEdX_ThreePlane", TracklikePrimaryDaughters_MeandEdX_ThreePlane);
   t_in->SetBranchAddress("TracklikePrimaryDaughters.Track_LLR_PID", TracklikePrimaryDaughters_Track_LLR_PID);
   t_in->SetBranchAddress("TracklikePrimaryDaughters.ProtonMomentum", TracklikePrimaryDaughters_ProtonMomentum);
   t_in->SetBranchAddress("TracklikePrimaryDaughters.MuonMomentum", TracklikePrimaryDaughters_MuonMomentum);
   t_in->SetBranchAddress("TracklikePrimaryDaughters.HasTruth", TracklikePrimaryDaughters_HasTruth);
   t_in->SetBranchAddress("TracklikePrimaryDaughters.TrackTruePDG", TracklikePrimaryDaughters_TrackTruePDG);
   t_in->SetBranchAddress("TracklikePrimaryDaughters.TrackTrueE", TracklikePrimaryDaughters_TrackTrueE);
   t_in->SetBranchAddress("TracklikePrimaryDaughters.TrackTruePx", TracklikePrimaryDaughters_TrackTruePx);
   t_in->SetBranchAddress("TracklikePrimaryDaughters.TrackTruePy", TracklikePrimaryDaughters_TrackTruePy);
   t_in->SetBranchAddress("TracklikePrimaryDaughters.TrackTruePz", TracklikePrimaryDaughters_TrackTruePz);
   t_in->SetBranchAddress("TracklikePrimaryDaughters.TrackTrueModMomentum", TracklikePrimaryDaughters_TrackTrueModMomentum);
   t_in->SetBranchAddress("TracklikePrimaryDaughters.TrackTrueKE", TracklikePrimaryDaughters_TrackTrueKE);
   t_in->SetBranchAddress("TracklikePrimaryDaughters.TrackTrueLength", TracklikePrimaryDaughters_TrackTrueLength);
   t_in->SetBranchAddress("TracklikePrimaryDaughters.TrackTrueOrigin", TracklikePrimaryDaughters_TrackTrueOrigin);
   //t_in->SetBranchAddress("TracklikePrimaryDaughters.TrackTrueTotalEdep", TracklikePrimaryDaughters_TrackTrueTotalEdep);
   t_in->SetBranchAddress("TracklikePrimaryDaughters.TrackEdepPurity", TracklikePrimaryDaughters_TrackEdepPurity);
   t_in->SetBranchAddress("ShowerlikePrimaryDaughters", &ShowerlikePrimaryDaughters_);
   t_in->SetBranchAddress("ShowerlikePrimaryDaughters.Index", ShowerlikePrimaryDaughters_Index);
   t_in->SetBranchAddress("ShowerlikePrimaryDaughters.PDG", ShowerlikePrimaryDaughters_PDG);
   t_in->SetBranchAddress("ShowerlikePrimaryDaughters.TrackShowerScore", ShowerlikePrimaryDaughters_TrackShowerScore);
   t_in->SetBranchAddress("ShowerlikePrimaryDaughters.X", ShowerlikePrimaryDaughters_X);
   t_in->SetBranchAddress("ShowerlikePrimaryDaughters.Y", ShowerlikePrimaryDaughters_Y);
   t_in->SetBranchAddress("ShowerlikePrimaryDaughters.Z", ShowerlikePrimaryDaughters_Z);
   t_in->SetBranchAddress("ShowerlikePrimaryDaughters.Displacement", ShowerlikePrimaryDaughters_Displacement);
   t_in->SetBranchAddress("ShowerlikePrimaryDaughters.TrackLength", ShowerlikePrimaryDaughters_TrackLength);
   t_in->SetBranchAddress("ShowerlikePrimaryDaughters.TrackDirectionX", ShowerlikePrimaryDaughters_TrackDirectionX);
   t_in->SetBranchAddress("ShowerlikePrimaryDaughters.TrackDirectionY", ShowerlikePrimaryDaughters_TrackDirectionY);
   t_in->SetBranchAddress("ShowerlikePrimaryDaughters.TrackDirectionZ", ShowerlikePrimaryDaughters_TrackDirectionZ);
   t_in->SetBranchAddress("ShowerlikePrimaryDaughters.TrackStartX", ShowerlikePrimaryDaughters_TrackStartX);
   t_in->SetBranchAddress("ShowerlikePrimaryDaughters.TrackStartY", ShowerlikePrimaryDaughters_TrackStartY);
   t_in->SetBranchAddress("ShowerlikePrimaryDaughters.TrackStartZ", ShowerlikePrimaryDaughters_TrackStartZ);
   t_in->SetBranchAddress("ShowerlikePrimaryDaughters.TrackEndX", ShowerlikePrimaryDaughters_TrackEndX);
   t_in->SetBranchAddress("ShowerlikePrimaryDaughters.TrackEndY", ShowerlikePrimaryDaughters_TrackEndY);
   t_in->SetBranchAddress("ShowerlikePrimaryDaughters.TrackEndZ", ShowerlikePrimaryDaughters_TrackEndZ);
   t_in->SetBranchAddress("ShowerlikePrimaryDaughters.TrackMuonClosestApproachPosition", ShowerlikePrimaryDaughters_TrackMuonClosestApproachPosition);
   t_in->SetBranchAddress("ShowerlikePrimaryDaughters.TrackMuonClosestApproachDistance", ShowerlikePrimaryDaughters_TrackMuonClosestApproachDistance);
   t_in->SetBranchAddress("ShowerlikePrimaryDaughters.TrackPID", ShowerlikePrimaryDaughters_TrackPID);
   t_in->SetBranchAddress("ShowerlikePrimaryDaughters.MeandEdX_Plane0", ShowerlikePrimaryDaughters_MeandEdX_Plane0);
   t_in->SetBranchAddress("ShowerlikePrimaryDaughters.MeandEdX_Plane1", ShowerlikePrimaryDaughters_MeandEdX_Plane1);
   t_in->SetBranchAddress("ShowerlikePrimaryDaughters.MeandEdX_Plane2", ShowerlikePrimaryDaughters_MeandEdX_Plane2);
   t_in->SetBranchAddress("ShowerlikePrimaryDaughters.MeandEdX_ThreePlane", ShowerlikePrimaryDaughters_MeandEdX_ThreePlane);
   t_in->SetBranchAddress("ShowerlikePrimaryDaughters.Track_LLR_PID", ShowerlikePrimaryDaughters_Track_LLR_PID);
   t_in->SetBranchAddress("ShowerlikePrimaryDaughters.ProtonMomentum", ShowerlikePrimaryDaughters_ProtonMomentum);
   t_in->SetBranchAddress("ShowerlikePrimaryDaughters.MuonMomentum", ShowerlikePrimaryDaughters_MuonMomentum);
   t_in->SetBranchAddress("ShowerlikePrimaryDaughters.HasTruth", ShowerlikePrimaryDaughters_HasTruth);
   t_in->SetBranchAddress("ShowerlikePrimaryDaughters.TrackTruePDG", ShowerlikePrimaryDaughters_TrackTruePDG);
   t_in->SetBranchAddress("ShowerlikePrimaryDaughters.TrackTrueE", ShowerlikePrimaryDaughters_TrackTrueE);
   t_in->SetBranchAddress("ShowerlikePrimaryDaughters.TrackTruePx", ShowerlikePrimaryDaughters_TrackTruePx);
   t_in->SetBranchAddress("ShowerlikePrimaryDaughters.TrackTruePy", ShowerlikePrimaryDaughters_TrackTruePy);
   t_in->SetBranchAddress("ShowerlikePrimaryDaughters.TrackTruePz", ShowerlikePrimaryDaughters_TrackTruePz);
   t_in->SetBranchAddress("ShowerlikePrimaryDaughters.TrackTrueModMomentum", ShowerlikePrimaryDaughters_TrackTrueModMomentum);
   t_in->SetBranchAddress("ShowerlikePrimaryDaughters.TrackTrueKE", ShowerlikePrimaryDaughters_TrackTrueKE);
   t_in->SetBranchAddress("ShowerlikePrimaryDaughters.TrackTrueLength", ShowerlikePrimaryDaughters_TrackTrueLength);
   t_in->SetBranchAddress("ShowerlikePrimaryDaughters.TrackTrueOrigin", ShowerlikePrimaryDaughters_TrackTrueOrigin);
  // t_in->SetBranchAddress("ShowerlikePrimaryDaughters.TrackTrueTotalEdep", ShowerlikePrimaryDaughters_TrackTrueTotalEdep);
   t_in->SetBranchAddress("ShowerlikePrimaryDaughters.TrackEdepPurity", ShowerlikePrimaryDaughters_TrackEdepPurity);
   t_in->SetBranchAddress("MuonIndex", &MuonIndex);
   t_in->SetBranchAddress("TrueMuonIndex", &TrueMuonIndex);
   t_in->SetBranchAddress("TrueDecayProtonIndex", &TrueDecayProtonIndex);
   t_in->SetBranchAddress("TrueDecayPionIndex", &TrueDecayPionIndex);
/*
   t_in->SetBranchAddress("ConnSeedIndexes_Plane0", &ConnSeedIndexes_Plane0);
   t_in->SetBranchAddress("ConnOutputIndexes_Plane0", &ConnOutputIndexes_Plane0);
   t_in->SetBranchAddress("ConnOutputSizes_Plane0", &ConnOutputSizes_Plane0);
   t_in->SetBranchAddress("ConnSeedChannels_Plane0", &ConnSeedChannels_Plane0);
   t_in->SetBranchAddress("ConnSeedTicks_Plane0", &ConnSeedTicks_Plane0);
   t_in->SetBranchAddress("ConnSeedIndexes_Plane1", &ConnSeedIndexes_Plane1);
   t_in->SetBranchAddress("ConnOutputIndexes_Plane1", &ConnOutputIndexes_Plane1);
   t_in->SetBranchAddress("ConnOutputSizes_Plane1", &ConnOutputSizes_Plane1);
   t_in->SetBranchAddress("ConnSeedChannels_Plane1", &ConnSeedChannels_Plane1);
   t_in->SetBranchAddress("ConnSeedTicks_Plane1", &ConnSeedTicks_Plane1);
   t_in->SetBranchAddress("ConnSeedIndexes_Plane2", &ConnSeedIndexes_Plane2);
   t_in->SetBranchAddress("ConnOutputIndexes_Plane2", &ConnOutputIndexes_Plane2);
   t_in->SetBranchAddress("ConnOutputSizes_Plane2", &ConnOutputSizes_Plane2);
   t_in->SetBranchAddress("ConnSeedChannels_Plane2", &ConnSeedChannels_Plane2);
   t_in->SetBranchAddress("ConnSeedTicks_Plane2", &ConnSeedTicks_Plane2);
   t_in->SetBranchAddress("SysDials", &SysDials);
   t_in->SetBranchAddress("SysWeights", &SysWeights);
*/

   // Get the metadata tree

   f_in->GetObject("ana/MetaTree",t_meta);
   //f_in->GetObject("HyperonNTuples/MetaTree",t_meta);

   t_meta->SetBranchAddress("POT",&POT);
   //t_meta->GetEntry(0);

}


void EventAssembler::Close(){

   if(f_in != nullptr) f_in->Close();

}


double EventAssembler::GetPOT(){

   int n_meta = t_meta->GetEntries();

   double TotalPOT=0.0;

   for(int i_meta=0;i_meta<n_meta;i_meta++){

      t_meta->GetEntry(i_meta);
      //std::cout << "Adding POT " << POT << std::endl;
      TotalPOT += POT;

   }

   return TotalPOT;
}


Long64_t EventAssembler::GetNEvents(){

   return nEvents;

}

///////////////////////////////////////////////////
//    Get Entry in the Tree and set variables    //
///////////////////////////////////////////////////

Event EventAssembler::GetEvent(int i){

   Event e;

   t_in->GetEntry(i);

   e.IsData = IsData;
   e.EventID = EventID;
   e.run = run;
   e.subrun = subrun;
   e.event = event;



   ///////////// Set Truth Variables ///////////////////////


   e.Mode = *Mode;
   e.CCNC = *CCNC;
   e.IsSignal = IsSignal;
   e.GoodReco = GoodReco;
   e.IsHyperon = IsHyperon;
   e.IsAssociatedHyperon = IsAssociatedHyperon;
   e.IsSigmaZero = IsSigmaZero;
   e.NMCTruths = NMCTruths;	
   e.IsLambdaCharged = IsLambdaCharged;
   e.InActiveTPC = InActiveTPC;

   e.Weight = Weight;

   e.TruePrimaryVertex =  *TruePrimaryVertex;
   e.DecayVertex =  *DecayVertex;


   //set Neutrino variables
   Neutrino.clear();
   Neutrino.resize(Neutrino_);

   for(int j=0;j<Neutrino_;j++){
      Neutrino[j].SetKinematics( TLorentzVector(Neutrino_Px[j],Neutrino_Py[j],Neutrino_Pz[j],Neutrino_E[j]) , 0.0 );
      Neutrino[j].Origin = Neutrino_Origin[j];
      Neutrino[j].PDG = Neutrino_PDG[j];
      Neutrino[j].SetPositions( TLorentzVector(Neutrino_StartX[j],Neutrino_StartY[j],Neutrino_StartZ[j],0) , TLorentzVector(Neutrino_EndX[j],Neutrino_EndY[j],Neutrino_EndZ[j],0) );
   }


   e.Neutrino = Neutrino;

   //set Lepton variables
   Lepton.clear();
   Lepton.resize(Lepton_);

   for(int j=0;j<Lepton_;j++){
      Lepton[j].SetKinematics( TLorentzVector(Lepton_Px[j],Lepton_Py[j],Lepton_Pz[j],Lepton_E[j]) , 0.0 );
      Lepton[j].Origin = Lepton_Origin[j];
      Lepton[j].PDG = Lepton_PDG[j];
      Lepton[j].SetPositions( TLorentzVector(Lepton_StartX[j],Lepton_StartY[j],Lepton_StartZ[j],0) , TLorentzVector(Lepton_EndX[j],Lepton_EndY[j],Lepton_EndZ[j],0) );
   }

   e.Lepton = Lepton;

   //set Hyperon variables
   Hyperon.clear();
   Hyperon.resize(Hyperon_);

   for(int j=0;j<Hyperon_;j++){
      Hyperon[j].SetKinematics( TLorentzVector(Hyperon_Px[j],Hyperon_Py[j],Hyperon_Pz[j],Hyperon_E[j]) , 0.0 );
      Hyperon[j].Origin = Hyperon_Origin[j];
      Hyperon[j].PDG = Hyperon_PDG[j];
      Hyperon[j].SetPositions( TLorentzVector(Hyperon_StartX[j],Hyperon_StartY[j],Hyperon_StartZ[j],0) , TLorentzVector(Hyperon_EndX[j],Hyperon_EndY[j],Hyperon_EndZ[j],0) );
   }

   e.Hyperon = Hyperon;

   //set PrimaryNucleon variables
   PrimaryNucleon.clear();
   PrimaryNucleon.resize(PrimaryNucleon_);

   for(int j=0;j<PrimaryNucleon_;j++){
      PrimaryNucleon[j].SetKinematics( TLorentzVector(PrimaryNucleon_Px[j],PrimaryNucleon_Py[j],PrimaryNucleon_Pz[j],PrimaryNucleon_E[j]) , 0.0 );
      PrimaryNucleon[j].Origin = PrimaryNucleon_Origin[j];
      PrimaryNucleon[j].PDG = PrimaryNucleon_PDG[j];
      PrimaryNucleon[j].SetPositions( TLorentzVector(PrimaryNucleon_StartX[j],PrimaryNucleon_StartY[j],PrimaryNucleon_StartZ[j],0) , TLorentzVector(PrimaryNucleon_EndX[j],PrimaryNucleon_EndY[j],PrimaryNucleon_EndZ[j],0) );
   }

   e.PrimaryNucleon = PrimaryNucleon;

   //set PrimaryPion variables
   PrimaryPion.clear();
   PrimaryPion.resize(PrimaryPion_);

   for(int j=0;j<PrimaryPion_;j++){
      PrimaryPion[j].SetKinematics( TLorentzVector(PrimaryPion_Px[j],PrimaryPion_Py[j],PrimaryPion_Pz[j],PrimaryPion_E[j]) , 0.0 );
      PrimaryPion[j].Origin = PrimaryPion_Origin[j];
      PrimaryPion[j].PDG = PrimaryPion_PDG[j];
      PrimaryPion[j].SetPositions( TLorentzVector(PrimaryPion_StartX[j],PrimaryPion_StartY[j],PrimaryPion_StartZ[j],0) , TLorentzVector(PrimaryPion_EndX[j],PrimaryPion_EndY[j],PrimaryPion_EndZ[j],0) );
   }

   e.PrimaryPion = PrimaryPion;

   //set Decay variables
   Decay.clear();
   Decay.resize(Decay_);

   for(int j=0;j<Decay_;j++){
      Decay[j].SetKinematics( TLorentzVector(Decay_Px[j],Decay_Py[j],Decay_Pz[j],Decay_E[j]) , 0.0 );
      Decay[j].Origin = Decay_Origin[j];
      Decay[j].PDG = Decay_PDG[j];
      Decay[j].SetPositions( TLorentzVector(Decay_StartX[j],Decay_StartY[j],Decay_StartZ[j],0) , TLorentzVector(Decay_EndX[j],Decay_EndY[j],Decay_EndZ[j],0) );
   }

   e.Decay = Decay;

   ///////////// Set Reco Variables ///////////////////////

   e.RecoPrimaryVertex = *RecoPrimaryVertex;
   e.NPrimaryTrackDaughters = NPrimaryTrackDaughters;
   e.NPrimaryShowerDaughters = NPrimaryShowerDaughters;

   TracklikePrimaryDaughters.clear();
   TracklikePrimaryDaughters.resize(TracklikePrimaryDaughters_);


   for(int j=0;j<TracklikePrimaryDaughters_;j++){

      TracklikePrimaryDaughters[j].Index = TracklikePrimaryDaughters_Index[j];

      //basic information
      TracklikePrimaryDaughters[j].PDG = TracklikePrimaryDaughters_PDG[j];
      TracklikePrimaryDaughters[j].TrackShowerScore = TracklikePrimaryDaughters_TrackShowerScore[j];
      TracklikePrimaryDaughters[j].Displacement = TracklikePrimaryDaughters_Displacement[j];


      //track variables
      TracklikePrimaryDaughters[j].TrackStartX = TracklikePrimaryDaughters_TrackStartX[j];
      TracklikePrimaryDaughters[j].TrackStartY = TracklikePrimaryDaughters_TrackStartY[j];
      TracklikePrimaryDaughters[j].TrackStartZ = TracklikePrimaryDaughters_TrackStartZ[j];
      TracklikePrimaryDaughters[j].TrackLength = TracklikePrimaryDaughters_TrackLength[j];
      TracklikePrimaryDaughters[j].TrackEndX = TracklikePrimaryDaughters_TrackEndX[j];
      TracklikePrimaryDaughters[j].TrackEndY = TracklikePrimaryDaughters_TrackEndY[j];
      TracklikePrimaryDaughters[j].TrackEndZ = TracklikePrimaryDaughters_TrackEndZ[j];
      TracklikePrimaryDaughters[j].TrackDirectionX = TracklikePrimaryDaughters_TrackDirectionX[j];
      TracklikePrimaryDaughters[j].TrackDirectionY = TracklikePrimaryDaughters_TrackDirectionY[j];
      TracklikePrimaryDaughters[j].TrackDirectionZ = TracklikePrimaryDaughters_TrackDirectionZ[j];

      //pid scores
      TracklikePrimaryDaughters[j].TrackPID = TracklikePrimaryDaughters_TrackPID[j];
      TracklikePrimaryDaughters[j].MeandEdX_ThreePlane = TracklikePrimaryDaughters_MeandEdX_ThreePlane[j];
      TracklikePrimaryDaughters[j].Track_LLR_PID = TracklikePrimaryDaughters_Track_LLR_PID[j];

      //Momentum estimates
      TracklikePrimaryDaughters[j].MuonMomentum = TracklikePrimaryDaughters_MuonMomentum[j];
      TracklikePrimaryDaughters[j].ProtonMomentum = TracklikePrimaryDaughters_ProtonMomentum[j];

      //truth matching 
      TracklikePrimaryDaughters[j].HasTruth = TracklikePrimaryDaughters_HasTruth[j];
      TracklikePrimaryDaughters[j].TrackTruePDG = TracklikePrimaryDaughters_TrackTruePDG[j];
      TracklikePrimaryDaughters[j].TrackTrueE = TracklikePrimaryDaughters_TrackTrueE[j];
      TracklikePrimaryDaughters[j].TrackTruePx = TracklikePrimaryDaughters_TrackTruePx[j];
      TracklikePrimaryDaughters[j].TrackTruePy = TracklikePrimaryDaughters_TrackTruePy[j];
      TracklikePrimaryDaughters[j].TrackTruePz = TracklikePrimaryDaughters_TrackTruePz[j];
      TracklikePrimaryDaughters[j].TrackTrueModMomentum = TracklikePrimaryDaughters_TrackTrueModMomentum[j];
      TracklikePrimaryDaughters[j].TrackTrueKE = TracklikePrimaryDaughters_TrackTrueKE[j];
      TracklikePrimaryDaughters[j].TrackTrueLength = TracklikePrimaryDaughters_TrackTrueLength[j];
      TracklikePrimaryDaughters[j].TrackTrueOrigin = TracklikePrimaryDaughters_TrackTrueOrigin[j];
      //TracklikePrimaryDaughters[j].TrackTrueTotalEdep = TracklikePrimaryDaughters_TrackTrueTotalEdep[j];


   }

   e.TracklikePrimaryDaughters = TracklikePrimaryDaughters;


   ShowerlikePrimaryDaughters.clear();
   ShowerlikePrimaryDaughters.resize(ShowerlikePrimaryDaughters_);


   for(int j=0;j<ShowerlikePrimaryDaughters_;j++){

      ShowerlikePrimaryDaughters[j].Index = ShowerlikePrimaryDaughters_Index[j];

      //basic information
      ShowerlikePrimaryDaughters[j].PDG = ShowerlikePrimaryDaughters_PDG[j];
      ShowerlikePrimaryDaughters[j].TrackShowerScore = ShowerlikePrimaryDaughters_TrackShowerScore[j];
      ShowerlikePrimaryDaughters[j].Displacement = ShowerlikePrimaryDaughters_Displacement[j];


      //track variables
      ShowerlikePrimaryDaughters[j].TrackStartX = ShowerlikePrimaryDaughters_TrackStartX[j];
      ShowerlikePrimaryDaughters[j].TrackStartY = ShowerlikePrimaryDaughters_TrackStartY[j];
      ShowerlikePrimaryDaughters[j].TrackStartZ = ShowerlikePrimaryDaughters_TrackStartZ[j];
      ShowerlikePrimaryDaughters[j].TrackLength = ShowerlikePrimaryDaughters_TrackLength[j];
      ShowerlikePrimaryDaughters[j].TrackEndX = ShowerlikePrimaryDaughters_TrackEndX[j];
      ShowerlikePrimaryDaughters[j].TrackEndY = ShowerlikePrimaryDaughters_TrackEndY[j];
      ShowerlikePrimaryDaughters[j].TrackEndZ = ShowerlikePrimaryDaughters_TrackEndZ[j];
      ShowerlikePrimaryDaughters[j].TrackDirectionX = ShowerlikePrimaryDaughters_TrackDirectionX[j];
      ShowerlikePrimaryDaughters[j].TrackDirectionY = ShowerlikePrimaryDaughters_TrackDirectionY[j];
      ShowerlikePrimaryDaughters[j].TrackDirectionZ = ShowerlikePrimaryDaughters_TrackDirectionZ[j];

      //pid scores
      ShowerlikePrimaryDaughters[j].TrackPID = ShowerlikePrimaryDaughters_TrackPID[j];
      ShowerlikePrimaryDaughters[j].MeandEdX_ThreePlane = ShowerlikePrimaryDaughters_MeandEdX_ThreePlane[j];
      ShowerlikePrimaryDaughters[j].Track_LLR_PID = ShowerlikePrimaryDaughters_Track_LLR_PID[j];

      //Momentum estimates
      ShowerlikePrimaryDaughters[j].MuonMomentum = ShowerlikePrimaryDaughters_MuonMomentum[j];
      ShowerlikePrimaryDaughters[j].ProtonMomentum = ShowerlikePrimaryDaughters_ProtonMomentum[j];

      //truth matching 
      ShowerlikePrimaryDaughters[j].HasTruth = ShowerlikePrimaryDaughters_HasTruth[j];
      ShowerlikePrimaryDaughters[j].TrackTruePDG = ShowerlikePrimaryDaughters_TrackTruePDG[j];
      ShowerlikePrimaryDaughters[j].TrackTrueE = ShowerlikePrimaryDaughters_TrackTrueE[j];
      ShowerlikePrimaryDaughters[j].TrackTruePx = ShowerlikePrimaryDaughters_TrackTruePx[j];
      ShowerlikePrimaryDaughters[j].TrackTruePy = ShowerlikePrimaryDaughters_TrackTruePy[j];
      ShowerlikePrimaryDaughters[j].TrackTruePz = ShowerlikePrimaryDaughters_TrackTruePz[j];
      ShowerlikePrimaryDaughters[j].TrackTrueModMomentum = ShowerlikePrimaryDaughters_TrackTrueModMomentum[j];
      ShowerlikePrimaryDaughters[j].TrackTrueKE = ShowerlikePrimaryDaughters_TrackTrueKE[j];
      ShowerlikePrimaryDaughters[j].TrackTrueLength = ShowerlikePrimaryDaughters_TrackTrueLength[j];
      ShowerlikePrimaryDaughters[j].TrackTrueOrigin = ShowerlikePrimaryDaughters_TrackTrueOrigin[j];
      //ShowerlikePrimaryDaughters[j].TrackTrueTotalEdep = ShowerlikePrimaryDaughters_TrackTrueTotalEdep[j];


   }

   e.ShowerlikePrimaryDaughters = ShowerlikePrimaryDaughters;

   e.TrueMuonIndex = TrueMuonIndex;
   e.TrueDecayProtonIndex = TrueDecayProtonIndex;
   e.TrueDecayPionIndex = TrueDecayPionIndex;


   // CT Algorithm stuff       
/*
   e.ConnSeedIndexes_Plane0 = ConnSeedIndexes_Plane0;
   e.ConnOutputIndexes_Plane0 = ConnOutputIndexes_Plane0;
   e.ConnOutputSizes_Plane0 = ConnOutputSizes_Plane0;
   e.ConnSeedChannels_Plane0 = ConnSeedChannels_Plane0;
   e.ConnSeedTicks_Plane0 = ConnSeedTicks_Plane0;

   e.ConnSeedIndexes_Plane1 = ConnSeedIndexes_Plane1;
   e.ConnOutputIndexes_Plane1 = ConnOutputIndexes_Plane1;
   e.ConnOutputSizes_Plane1 = ConnOutputSizes_Plane1;
   e.ConnSeedChannels_Plane1 = ConnSeedChannels_Plane1;
   e.ConnSeedTicks_Plane1 = ConnSeedTicks_Plane1;

   e.ConnSeedIndexes_Plane2 = ConnSeedIndexes_Plane2;
   e.ConnOutputIndexes_Plane2 = ConnOutputIndexes_Plane2;
   e.ConnOutputSizes_Plane2 = ConnOutputSizes_Plane2;
   e.ConnSeedChannels_Plane2 = ConnSeedChannels_Plane2;
   e.ConnSeedTicks_Plane2 = ConnSeedTicks_Plane2;

   // Systematic weights
   e.SysDials = SysDials;
   e.SysWeights = SysWeights;
*/

   ///////////////////////////////////////////////////////////////////////////////////////////////////////////

   return e;

}

#endif
