#!/bin/sh

#cvmfs_config probe
if [ ! -e /cvmfs/uboone.opensciencegrid.org/products/setup_uboone.sh ]
then 
echo "NOT SETUP SCRIPT AAAAAAAA"
exit 1
fi

source /cvmfs/uboone.opensciencegrid.org/products/setup_uboone.sh
setup uboonecode v08_30_02 -q e17:prof 

export HYP_TOP=$PWD/

export ROOT_INCLUDE_PATH=$ROOT_INCLUDE_PATH:$PWD/Core:$PWD/Alg:$PWD/ParameterSets
export DATA_DIR=$PWD/data/
