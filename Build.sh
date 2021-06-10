#!/bin/bash


echo "Building Algs"
g++ `${ROOTSYS}/bin/root-config --cflags` -c -fPIC $HYP_TOP/Alg/FiducialVolume.cxx  -o $HYP_TOP/lib/FiducialVolume.o
g++ `${ROOTSYS}/bin/root-config --cflags` -c -fPIC $HYP_TOP/Alg/FluxWeight.cxx  -o $HYP_TOP/lib/FluxWeight.o
g++ `${ROOTSYS}/bin/root-config --cflags` -c -fPIC -I$HYP_TOP/Core $HYP_TOP/Alg/Muon_ID.cxx  -o $HYP_TOP/lib/Muon_ID.o
g++ `${ROOTSYS}/bin/root-config --cflags` -c -fPIC -I$HYP_TOP/Core $HYP_TOP/Alg/TrackLengthCutManager.cxx  -o $HYP_TOP/lib/TrackLengthCutManager.o
g++ `${ROOTSYS}/bin/root-config --cflags` -c -fPIC -I$HYP_TOP/Core $HYP_TOP/Alg/SelectorBDTManager.cxx  -o $HYP_TOP/lib/SelectorBDTManager.o
g++ `${ROOTSYS}/bin/root-config --cflags` -c -fPIC -I$HYP_TOP/Core $HYP_TOP/Alg/AnalysisBDTManager.cxx  -o $HYP_TOP/lib/AnalysisBDTManager.o
g++ `${ROOTSYS}/bin/root-config --cflags` -c -fPIC -I$HYP_TOP/Core $HYP_TOP/Alg/SecondaryVertexFitter.cxx  -o $HYP_TOP/lib/SecondaryVertexFitter.o


echo "Linking Algs"
g++ -shared `${ROOTSYS}/bin/root-config --libs` $HYP_TOP/lib/FiducialVolume.o $HYP_TOP/lib/FluxWeight.o $HYP_TOP/lib/Muon_ID.o $HYP_TOP/lib/TrackLengthCutManager.o $HYP_TOP/lib/SelectorBDTManager.o $HYP_TOP/lib/SecondaryVertexFitter.o $HYP_TOP/lib/AnalysisBDTManager.o -o $HYP_TOP/lib/libAlg.so 

echo "Building Selection Manager"
g++ `${ROOTSYS}/bin/root-config --cflags` -c -fPIC -I$HYP_TOP/Alg -I$HYP_TOP/Core $HYP_TOP/Core/SelectionManager.cxx  -o $HYP_TOP/lib/SelectionManager.o

echo "Building Event Assembler"
g++ `${ROOTSYS}/bin/root-config --cflags` -c -fPIC -I$HYP_TOP/Alg -I$HYP_TOP/Core $HYP_TOP/Core/EventAssembler.cxx  -o $HYP_TOP/lib/EventAssembler.o

echo "Linking Core"
g++ -shared `${ROOTSYS}/bin/root-config --libs` $HYP_TOP/lib/EventAssembler.o  $HYP_TOP/lib/SelectionManager.o -o $HYP_TOP/lib/libCore.so
