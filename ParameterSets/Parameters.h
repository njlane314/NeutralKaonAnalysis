
SelectionParameters P_FHC_Tune_249;

void BuildTunes(){

P_FHC_Tune_249.p_RunPeriod=1;
P_FHC_Tune_249.p_FV=FV::kWirecellPadded;
P_FHC_Tune_249.p_Padding=10;
P_FHC_Tune_249.p_Minimum_MIP_Length=10;
P_FHC_Tune_249.p_SecondaryTrackLengthCut=150;
P_FHC_Tune_249.p_TertiaryTrackLengthCut=50;
P_FHC_Tune_249.p_Max_Displacement=1;
P_FHC_Tune_249.p_PID_Cut=0.6;
P_FHC_Tune_249.p_Proton_PID_Cut = 0.1;
P_FHC_Tune_249.p_Pion_PID_Cut = 0.0;
P_FHC_Tune_249.p_Separation_Cut=4;
P_FHC_Tune_249.p_VertexPull=10;
P_FHC_Tune_249.p_SelectorBDT_WeightsDir="/home/lar/cthorpe/uboone/HyperonSelection/TMVA/SelectorMVA/Tunes/FHC_Tune_249/dataset/weights";
P_FHC_Tune_249.p_AnalysisBDT_WeightsDir="/home/lar/cthorpe/uboone/HyperonSelection/TMVA/AnalysisMVA/Tunes/FHC_Tune_249/dataset/weights";

P_FHC_Tune_249.p_AnalysisBDT_Cut=0.0;

}

