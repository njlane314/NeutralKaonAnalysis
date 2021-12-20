#ifndef _Parameters_h_
#define _Parameters_h_

#include "SelectionParameters.h"

// Pre-defined settings for the selection
// To use - include this header and add:
// BuildTunes(); at the start of your code
// Then SelectionManager(P_FHC_325) etc. 

SelectionParameters P_FHC_Tune_325;
SelectionParameters P_RHC_Tune_397;

SelectionParameters P_FHC_Tune_test;
SelectionParameters P_FHC_Tune_test2;

SelectionParameters P_FHC_Tune_1000;

void BuildTunes(){

/////////////////////
// FROZEN FHC TUNE //
/////////////////////

//FHC Tune 325
P_FHC_Tune_325.p_RunPeriod=1;
P_FHC_Tune_325.p_FV=FV::kWirecellPadded;
P_FHC_Tune_325.p_Padding=10;
P_FHC_Tune_325.p_Minimum_MIP_Length=10;
P_FHC_Tune_325.p_SecondaryTrackLengthCut=1000;
P_FHC_Tune_325.p_TertiaryTrackLengthCut=1000;
P_FHC_Tune_325.p_Max_Displacement=1;
P_FHC_Tune_325.p_PID_Cut=0.6;
P_FHC_Tune_325.p_Proton_PID_Cut = 0.1;
P_FHC_Tune_325.p_Pion_PID_Cut = -0.1;
P_FHC_Tune_325.p_Separation_Cut=3;
P_FHC_Tune_325.p_VertexPull=5;
P_FHC_Tune_325.p_SelectorBDT_WeightsDir="/home/lar/cthorpe/uboone/HyperonSelection/TMVA/SelectorMVA/Tunes/FHC_Tune_325/dataset/weights";
P_FHC_Tune_325.p_AnalysisBDT_WeightsDir="/home/lar/cthorpe/uboone/HyperonSelection/TMVA/AnalysisMVA/Tunes/FHC_Tune_325/dataset/weights";
P_FHC_Tune_325.p_AnalysisBDT_Cut=0.15;

/////////////////////
// FROZEN RHC TUNE //
/////////////////////

// RHC Tune 397
P_RHC_Tune_397.p_RunPeriod=3;
P_RHC_Tune_397.p_FV=FV::kWirecellPadded;
P_RHC_Tune_397.p_Padding=10;
P_RHC_Tune_397.p_Minimum_MIP_Length=10;
P_RHC_Tune_397.p_SecondaryTrackLengthCut=1000;
P_RHC_Tune_397.p_TertiaryTrackLengthCut=1000;
P_RHC_Tune_397.p_Max_Displacement=1;
P_RHC_Tune_397.p_PID_Cut=0.6;
P_RHC_Tune_397.p_Proton_PID_Cut = 0.0;
P_RHC_Tune_397.p_Pion_PID_Cut = -0.1;
P_RHC_Tune_397.p_Separation_Cut=3;
P_RHC_Tune_397.p_VertexPull=5;
P_RHC_Tune_397.p_SelectorBDT_WeightsDir="/home/lar/cthorpe/uboone/HyperonSelection/TMVA/SelectorMVA/Tunes/RHC_Tune_397/dataset/weights";
P_RHC_Tune_397.p_AnalysisBDT_WeightsDir="/home/lar/cthorpe/uboone/HyperonSelection/TMVA/AnalysisMVA/Tunes/RHC_Tune_397/dataset/weights";
P_RHC_Tune_397.p_AnalysisBDT_Cut=0.2;

//FHC test tune
P_FHC_Tune_test.p_RunPeriod=1;
P_FHC_Tune_test.p_FV=FV::kWirecellPadded;
P_FHC_Tune_test.p_Padding=0;
P_FHC_Tune_test.p_Minimum_MIP_Length=0;
P_FHC_Tune_test.p_SecondaryTrackLengthCut=1000;
P_FHC_Tune_test.p_TertiaryTrackLengthCut=1000;
P_FHC_Tune_test.p_Max_Displacement=1;
P_FHC_Tune_test.p_PID_Cut=0.3;
P_FHC_Tune_test.p_Proton_PID_Cut = 1.0;
P_FHC_Tune_test.p_Pion_PID_Cut = -1.0;
P_FHC_Tune_test.p_Separation_Cut=100;
P_FHC_Tune_test.p_VertexPull=5;
P_FHC_Tune_test.p_SelectorBDT_WeightsDir="/home/lar/cthorpe/uboone/HyperonSelection/TMVA/SelectorMVA/Tunes/FHC_Tune_test/dataset/weights";
P_FHC_Tune_test.p_AnalysisBDT_WeightsDir="/home/lar/cthorpe/uboone/HyperonSelection/TMVA/AnalysisMVA/Tunes/FHC_Tune_test/dataset/weights";
P_FHC_Tune_test.p_AnalysisBDT_Cut=0.15;


//FHC test2 tune2
P_FHC_Tune_test2.p_RunPeriod=1;
P_FHC_Tune_test2.p_FV=FV::kWirecellPadded;
P_FHC_Tune_test2.p_Padding=10;
P_FHC_Tune_test2.p_Minimum_MIP_Length=10;
P_FHC_Tune_test2.p_SecondaryTrackLengthCut=1000;
P_FHC_Tune_test2.p_TertiaryTrackLengthCut=1000;
P_FHC_Tune_test2.p_Max_Displacement=1;
P_FHC_Tune_test2.p_PID_Cut=0.6;
P_FHC_Tune_test2.p_Proton_PID_Cut = 1.0;
P_FHC_Tune_test2.p_Pion_PID_Cut = -1.0;
P_FHC_Tune_test2.p_Separation_Cut=100;
P_FHC_Tune_test2.p_VertexPull=5;
P_FHC_Tune_test2.p_SelectorBDT_WeightsDir="/home/lar/cthorpe/uboone/HyperonSelection/TMVA/SelectorMVA/Tunes/FHC_Tune_test2/dataset/weights";
P_FHC_Tune_test2.p_AnalysisBDT_WeightsDir="/home/lar/cthorpe/uboone/HyperonSelection/TMVA/AnalysisMVA/Tunes/FHC_Tune_test2/dataset/weights";
P_FHC_Tune_test2.p_AnalysisBDT_Cut=0.15;

//FHC Tune 1000
P_FHC_Tune_1000.p_RunPeriod=1;
P_FHC_Tune_1000.p_FV=FV::kWirecellPadded;
P_FHC_Tune_1000.p_Padding=5;
P_FHC_Tune_1000.p_Minimum_MIP_Length=5;
P_FHC_Tune_1000.p_SecondaryTrackLengthCut=1000;
P_FHC_Tune_1000.p_TertiaryTrackLengthCut=1000;
P_FHC_Tune_1000.p_Max_Displacement=1;
P_FHC_Tune_1000.p_PID_Cut=0.6;
P_FHC_Tune_1000.p_Proton_PID_Cut = 0.1;
P_FHC_Tune_1000.p_Pion_PID_Cut = 0.0;
P_FHC_Tune_1000.p_Separation_Cut=10;
P_FHC_Tune_1000.p_VertexPull=5;
P_FHC_Tune_1000.p_SelectorBDT_WeightsDir="/home/lar/cthorpe/uboone/HyperonSelection/TMVA/SelectorMVA/Tunes/FHC_Tune_1000/dataset/weights";
P_FHC_Tune_1000.p_AnalysisBDT_WeightsDir="/home/lar/cthorpe/uboone/HyperonSelection/TMVA/AnalysisMVA/Tunes/FHC_Tune_1000/dataset/weights";
P_FHC_Tune_1000.p_AnalysisBDT_Cut=0.15;

}

#endif
