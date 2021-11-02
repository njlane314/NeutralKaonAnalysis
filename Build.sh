#!/bin/bash

BLUE='\033[0;34m'
NC='\033[0m'
bold=$(tput bold)
normal=$(tput sgr0)

echo -e "${BLUE}${bold}Building Algs${normal}${NC}"

echo "Building FiducialVolume"
g++ `${ROOTSYS}/bin/root-config --cflags` -c -fPIC $HYP_TOP/Alg/FiducialVolume.cxx  -o $HYP_TOP/lib/FiducialVolume.o

echo "Building FluxWeight"
g++ `${ROOTSYS}/bin/root-config --cflags` -c -fPIC -I$HYP_TOP/Core $HYP_TOP/Alg/FluxWeight.cxx  -o $HYP_TOP/lib/FluxWeight.o

echo "Building Muon_ID"
g++ `${ROOTSYS}/bin/root-config --cflags` -c -fPIC -I$HYP_TOP/Core $HYP_TOP/Alg/Muon_ID.cxx  -o $HYP_TOP/lib/Muon_ID.o

echo "Building TrackLengthCutManager"
g++ `${ROOTSYS}/bin/root-config --cflags` -c -fPIC -I$HYP_TOP/Core $HYP_TOP/Alg/TrackLengthCutManager.cxx  -o $HYP_TOP/lib/TrackLengthCutManager.o

echo "Building SelectorBDTManager"
g++ `${ROOTSYS}/bin/root-config --cflags` -c -fPIC -I$HYP_TOP/Core $HYP_TOP/Alg/SelectorBDTManager.cxx  -o $HYP_TOP/lib/SelectorBDTManager.o

echo "Building AnalysisBDTManager"
g++ `${ROOTSYS}/bin/root-config --cflags` -c -fPIC -I$HYP_TOP/Core $HYP_TOP/Alg/AnalysisBDTManager.cxx  -o $HYP_TOP/lib/AnalysisBDTManager.o

echo "Building SecondaryVertexFitter"
g++ `${ROOTSYS}/bin/root-config --cflags` -c -fPIC -I$HYP_TOP/Core $HYP_TOP/Alg/SecondaryVertexFitter.cxx  -o $HYP_TOP/lib/SecondaryVertexFitter.o

echo "Building EventListFilter"
g++ `${ROOTSYS}/bin/root-config --cflags` -c -fPIC $HYP_TOP/Alg/EventListFilter.cxx  -o $HYP_TOP/lib/EventListFilter.o

echo "Building ForwardFolder"
g++ `${ROOTSYS}/bin/root-config --cflags` -c -fPIC $HYP_TOP/Alg/ForwardFolder.cxx  -o $HYP_TOP/lib/ForwardFolder.o

echo "Building ForwardFolder2"
g++ `${ROOTSYS}/bin/root-config --cflags` -c -fPIC $HYP_TOP/Alg/ForwardFolder2.cxx  -o $HYP_TOP/lib/ForwardFolder2.o

echo "Building CTTest"
g++ `${ROOTSYS}/bin/root-config --cflags` -c -fPIC $HYP_TOP/Alg/CTTest.cxx  -o $HYP_TOP/lib/CTTest.o

echo "Building GenG4WeightHandler"
g++ `${ROOTSYS}/bin/root-config --cflags` -c -fPIC -I$HYP_TOP/Core $HYP_TOP/Alg/GenG4WeightHandler.cxx  -o $HYP_TOP/lib/GenG4WeightHandler.o

echo -e "${BLUE}${bold}Building Core${NC}"

echo "Building SelectionManager"
g++ `${ROOTSYS}/bin/root-config --cflags` -c -fPIC -I$HYP_TOP/Alg -I$HYP_TOP/Core $HYP_TOP/Core/SelectionManager.cxx  -o $HYP_TOP/lib/SelectionManager.o

echo "Building EventAssembler"
g++ `${ROOTSYS}/bin/root-config --cflags` -c -fPIC -I$HYP_TOP/Alg -I$HYP_TOP/Core $HYP_TOP/Core/EventAssembler.cxx  -o $HYP_TOP/lib/EventAssembler.o

echo -e "${BLUE}${bold}Building Dictionary${NC}"
rootcling -v4 -f ${HYP_TOP}/lib/ParticleDict.cxx  -rmf ${HYP_TOP}/lib/libParticleDict.rootmap -rml ${HYP_TOP}/lib/libParticleDict.so  ${HYP_TOP}/Core/LinkDef.h
g++ -shared -fPIC -I$HYP_TOP/Core -o ${HYP_TOP}/lib/libParticleDict.so ${HYP_TOP}/lib/ParticleDict.cxx `root-config --cflags --libs`

g++ -shared `${ROOTSYS}/bin/root-config --libs` $HYP_TOP/lib/FiducialVolume.o $HYP_TOP/lib/FluxWeight.o $HYP_TOP/lib/Muon_ID.o $HYP_TOP/lib/TrackLengthCutManager.o $HYP_TOP/lib/SelectorBDTManager.o $HYP_TOP/lib/SecondaryVertexFitter.o $HYP_TOP/lib/AnalysisBDTManager.o $HYP_TOP/lib/EventListFilter.o $HYP_TOP/lib/ForwardFolder.o $HYP_TOP/lib/ForwardFolder2.o $HYP_TOP/lib/CTTest.o $HYP_TOP/lib/EventAssembler.o $HYP_TOP/lib/SelectionManager.o $HYP_TOP/lib/GenG4WeightHandler.o  -o $HYP_TOP/lib/libHyperon.so

echo "Done!"
