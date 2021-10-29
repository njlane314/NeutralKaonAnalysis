#!/bin/bash

CXX=g++
CFLAGS=`${ROOTSYS}/bin/root-config --cflags` -fPIC 
INC=-I${HYP_TOP}/Core  -I${HYP_TOP}/Alg

all: $(addprefix lib/, AnalysisBDTManager.o CTTest.o FiducialVolume.o FluxWeight.o Muon_ID.o\
	TrackLengthCutManager.o SelectorBDTManager.o AnalysisBDTManager.o\
	EventListFilter.o ForwardFolder.o ForwardFolder2.o GenG4WeightHandler.o\
	SecondaryVertexFitter.o SelectionManager.o EventAssembler.o EventAssembler2.o  libParticleDict.rootmap\
	libParticleDict.so libHyperon.so) 


lib/libParticleDict.rootmap: Core/LinkDef.h
	rootcling -v4 -f ${HYP_TOP}/lib/ParticleDict.cxx  -rmf ${HYP_TOP}/lib/libParticleDict.rootmap -rml ${HYP_TOP}/lib/libParticleDict.so  ${HYP_TOP}/Core/LinkDef.h

lib/libParticleDict.so: lib/libParticleDict.rootmap	
	g++ -shared -fPIC -I${HYP_TOP}/Core -o ${HYP_TOP}/lib/libParticleDict.so ${HYP_TOP}/lib/ParticleDict.cxx `root-config --cflags --libs`

%.o: %.cxx
	g++ $(CFLAGS) -c $(INC)  $< -o $@

lib/AnalysisBDTManager.o: Alg/AnalysisBDTManager.cxx
	g++ $(CFLAGS) -c $(INC)  $< -o $@	

lib/CTTest.o: Alg/CTTest.cxx
	g++ $(CFLAGS) -c $(INC)  $< -o $@	

lib/FiducialVolume.o: Alg/FiducialVolume.cxx
	g++ $(CFLAGS) -c $(INC)  $< -o $@	

lib/FluxWeight.o: Alg/FluxWeight.cxx
	g++ $(CFLAGS) -c $(INC)  $< -o $@	

lib/Muon_ID.o: Alg/Muon_ID.cxx
	g++ $(CFLAGS) -c $(INC)  $< -o $@	
	
lib/TrackLengthCutManager.o: Alg/TrackLengthCutManager.cxx
	g++ $(CFLAGS) -c $(INC)  $< -o $@	

lib/SelectorBDTManager.o: Alg/SelectorBDTManager.cxx
	g++ $(CFLAGS) -c $(INC)  $< -o $@	

lib/EventListFilter.o: Alg/EventListFilter.cxx
	g++ $(CFLAGS) -c $(INC)  $< -o $@	

lib/ForwardFolder.o: Alg/ForwardFolder.cxx
	g++ $(CFLAGS) -c $(INC)  $< -o $@	

lib/ForwardFolder2.o: Alg/ForwardFolder2.cxx
	g++ $(CFLAGS) -c $(INC)  $< -o $@	

lib/GenG4WeightHandler.o: Alg/GenG4WeightHandler.cxx
	g++ $(CFLAGS) -c $(INC)  $< -o $@	

lib/SecondaryVertexFitter.o: Alg/SecondaryVertexFitter.cxx
	g++ $(CFLAGS) -c $(INC)  $< -o $@	

lib/SelectionManager.o: Core/SelectionManager.cxx
	g++ $(CFLAGS) -c $(INC)  $< -o $@	

lib/EventAssembler.o: Core/EventAssembler.cxx
	g++ $(CFLAGS) -c $(INC)  $< -o $@	
	

lib/EventAssembler2.o: Core/EventAssembler2.cxx
	g++ $(CFLAGS) -c $(INC)  $< -o $@	

	
lib/libHyperon.so: $(addprefix lib/, AnalysisBDTManager.o CTTest.o FiducialVolume.o FluxWeight.o Muon_ID.o TrackLengthCutManager.o SelectorBDTManager.o SecondaryVertexFitter.o EventListFilter.o ForwardFolder.o ForwardFolder2.o GenG4WeightHandler.o EventAssembler.o EventAssembler2.o SelectionManager.o)
	g++ -shared `${ROOTSYS}/bin/root-config --libs` lib/FiducialVolume.o lib/FluxWeight.o lib/Muon_ID.o lib/TrackLengthCutManager.o lib/SelectorBDTManager.o lib/SecondaryVertexFitter.o lib/AnalysisBDTManager.o lib/EventListFilter.o lib/ForwardFolder.o lib/ForwardFolder2.o lib/CTTest.o lib/GenG4WeightHandler.o lib/EventAssembler.o  lib/EventAssembler2.o lib/SelectionManager.o -o lib/libHyperon.so
