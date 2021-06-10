#include "SelectionParameters.h"

#include "FiducialVolume.h"

SelectionParameters P_FHC_v0;

void BuildTunes(){

// Put your sets of selection parameters in here

// Old Tune

P_FHC_v0.p_RunPeriod = 1;
P_FHC_v0.p_FV = FV::kOldFV;
P_FHC_v0.p_Padding = 0.0;
P_FHC_v0.p_Minimum_MIP_Length = 0.0;
P_FHC_v0.p_Max_Displacement = 5.0;
P_FHC_v0.p_PID_Cut = -0.35;
P_FHC_v0.p_SecondaryTrackLengthCut = 65.0;
P_FHC_v0.p_TertiaryTrackLengthCut = 35.0;
P_FHC_v0.p_Proton_PID_Cut = 0.1;
P_FHC_v0.p_Pion_PID_Cut = -0.1;
P_FHC_v0.p_Separation_Cut = 4.0;
P_FHC_v0.p_AnalysisBDT_Cut = 0.1;

}
