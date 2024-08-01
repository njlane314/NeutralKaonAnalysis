#!/bin/sh

source /cvmfs/uboone.opensciencegrid.org/products/setup_uboone.sh
setup uboonecode v08_00_00_81 -q e17:prof 

export HYP_TOP=$PWD/

export ROOT_INCLUDE_PATH=$ROOT_INCLUDE_PATH:$PWD/Core:$PWD/Alg:$PWD/ParameterSets:$PWD/SampleSets
export DATA_DIR=/exp/uboone/data/users/cthorpe/K0SAnalysis/
