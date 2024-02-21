void Efficiency_invariant_mass_fhc_FV_muon_pion_pair_MuonBeamPhi_All_Ratio()
{
//=========Macro generated from canvas: c1/c1
//=========  (Mon Feb 12 09:00:55 2024) by ROOT version 6.12/06
   TCanvas *c1 = new TCanvas("c1", "c1",0,0,800,600);
   c1->Range(0,0,1,1);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: pad2
   TPad *pad2 = new TPad("pad2", "pad2",0,0.85,1,1);
   pad2->Draw();
   pad2->cd();
   pad2->Range(0,0,1,1);
   pad2->SetFillColor(0);
   pad2->SetBorderMode(0);
   pad2->SetBorderSize(2);
   pad2->SetBottomMargin(0);
   pad2->SetFrameBorderMode(0);
   
   TLegend *leg = new TLegend(0.1,0,0.9,1,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("h_Before","All Events","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph","Efficiency","P");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ff0000");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(5);
   entry->SetMarkerSize(2);
   entry->SetTextFont(42);
   entry=leg->AddEntry("h_After","Selected","L");
   entry->SetLineColor(3);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   pad2->Modified();
   c1->cd();
  
// ------------>Primitives in pad: pad1
   TPad *pad1 = new TPad("pad1", "pad1",0,0,1,0.85);
   pad1->Draw();
   pad1->cd();
   pad1->Range(-3.926875,-0.361196,3.926875,3.250764);
   pad1->SetFillColor(0);
   pad1->SetBorderMode(0);
   pad1->SetBorderSize(2);
   pad1->SetTopMargin(0.01);
   pad1->SetFrameBorderMode(0);
   pad1->SetFrameBorderMode(0);
   
   THStack *hs = new THStack();
   hs->SetName("hs");
   hs->SetTitle(";Beam-Muon #phi;Events/bin");
   hs->SetMaximum(3.214644);
   
   TH1F *hs_stack_8 = new TH1F("hs_stack_8","",30,-3.1415,3.1415);
   hs_stack_8->SetMinimum(0);
   hs_stack_8->SetMaximum(3.214644);
   hs_stack_8->SetDirectory(0);
   hs_stack_8->SetStats(0);

   ci = TColor::GetColor("#000099");
   hs_stack_8->SetLineColor(ci);
   hs_stack_8->GetXaxis()->SetTitle("Beam-Muon #phi");
   hs_stack_8->GetXaxis()->SetLabelFont(42);
   hs_stack_8->GetXaxis()->SetLabelSize(0.045);
   hs_stack_8->GetXaxis()->SetTitleSize(0.05);
   hs_stack_8->GetXaxis()->SetTitleOffset(0.93);
   hs_stack_8->GetXaxis()->SetTitleFont(42);
   hs_stack_8->GetYaxis()->SetTitle("Events/bin");
   hs_stack_8->GetYaxis()->SetLabelFont(42);
   hs_stack_8->GetYaxis()->SetLabelSize(0.045);
   hs_stack_8->GetYaxis()->SetTitleSize(0.05);
   hs_stack_8->GetYaxis()->SetTitleOffset(1.06);
   hs_stack_8->GetYaxis()->SetTitleFont(42);
   hs_stack_8->GetZaxis()->SetLabelFont(42);
   hs_stack_8->GetZaxis()->SetLabelSize(0.035);
   hs_stack_8->GetZaxis()->SetTitleSize(0.035);
   hs_stack_8->GetZaxis()->SetTitleFont(42);
   hs->SetHistogram(hs_stack_8);
   
   
   TH1D *h_Before_stack_1 = new TH1D("h_Before_stack_1"," (total)",30,-3.1415,3.1415);
   h_Before_stack_1->SetBinContent(1,1.482456);
   h_Before_stack_1->SetBinContent(2,1.163648);
   h_Before_stack_1->SetBinContent(3,1.08926);
   h_Before_stack_1->SetBinContent(4,1.477142);
   h_Before_stack_1->SetBinContent(5,1.068006);
   h_Before_stack_1->SetBinContent(6,1.153021);
   h_Before_stack_1->SetBinContent(7,1.354933);
   h_Before_stack_1->SetBinContent(8,1.599352);
   h_Before_stack_1->SetBinContent(9,1.461202);
   h_Before_stack_1->SetBinContent(10,1.344306);
   h_Before_stack_1->SetBinContent(11,1.827831);
   h_Before_stack_1->SetBinContent(12,1.540904);
   h_Before_stack_1->SetBinContent(13,2.024429);
   h_Before_stack_1->SetBinContent(14,2.22634);
   h_Before_stack_1->SetBinContent(15,2.061623);
   h_Before_stack_1->SetBinContent(16,1.620606);
   h_Before_stack_1->SetBinContent(17,1.838458);
   h_Before_stack_1->SetBinContent(18,2.221027);
   h_Before_stack_1->SetBinContent(19,2.571715);
   h_Before_stack_1->SetBinContent(20,1.769383);
   h_Before_stack_1->SetBinContent(21,2.353863);
   h_Before_stack_1->SetBinContent(22,1.578098);
   h_Before_stack_1->SetBinContent(23,2.082877);
   h_Before_stack_1->SetBinContent(24,1.780009);
   h_Before_stack_1->SetBinContent(25,1.902219);
   h_Before_stack_1->SetBinContent(26,1.859711);
   h_Before_stack_1->SetBinContent(27,1.556844);
   h_Before_stack_1->SetBinContent(28,1.365559);
   h_Before_stack_1->SetBinContent(29,1.264604);
   h_Before_stack_1->SetBinContent(30,1.370873);
   h_Before_stack_1->SetBinContent(31,0.02125384);
   h_Before_stack_1->SetBinError(1,0.0887523);
   h_Before_stack_1->SetBinError(2,0.07863204);
   h_Before_stack_1->SetBinError(3,0.07607718);
   h_Before_stack_1->SetBinError(4,0.0885931);
   h_Before_stack_1->SetBinError(5,0.07533131);
   h_Before_stack_1->SetBinError(6,0.07827217);
   h_Before_stack_1->SetBinError(7,0.08484917);
   h_Before_stack_1->SetBinError(8,0.0921851);
   h_Before_stack_1->SetBinError(9,0.08811378);
   h_Before_stack_1->SetBinError(10,0.08451577);
   h_Before_stack_1->SetBinError(11,0.09855002);
   h_Before_stack_1->SetBinError(12,0.09048498);
   h_Before_stack_1->SetBinError(13,0.1037146);
   h_Before_stack_1->SetBinError(14,0.1087638);
   h_Before_stack_1->SetBinError(15,0.104663);
   h_Before_stack_1->SetBinError(16,0.09279561);
   h_Before_stack_1->SetBinError(17,0.09883609);
   h_Before_stack_1->SetBinError(18,0.108634);
   h_Before_stack_1->SetBinError(19,0.1168961);
   h_Before_stack_1->SetBinError(20,0.09696157);
   h_Before_stack_1->SetBinError(21,0.1118354);
   h_Before_stack_1->SetBinError(22,0.09157053);
   h_Before_stack_1->SetBinError(23,0.1052012);
   h_Before_stack_1->SetBinError(24,0.09725231);
   h_Before_stack_1->SetBinError(25,0.1005354);
   h_Before_stack_1->SetBinError(26,0.09940575);
   h_Before_stack_1->SetBinError(27,0.0909518);
   h_Before_stack_1->SetBinError(28,0.08518126);
   h_Before_stack_1->SetBinError(29,0.08197209);
   h_Before_stack_1->SetBinError(30,0.08534682);
   h_Before_stack_1->SetBinError(31,0.01062692);
   h_Before_stack_1->SetEntries(9506);
   h_Before_stack_1->SetLineWidth(2);
   h_Before_stack_1->GetXaxis()->SetTitle("Muon Beam #theta");
   h_Before_stack_1->GetXaxis()->SetLabelFont(42);
   h_Before_stack_1->GetXaxis()->SetLabelSize(0.035);
   h_Before_stack_1->GetXaxis()->SetTitleSize(0.035);
   h_Before_stack_1->GetXaxis()->SetTitleFont(42);
   h_Before_stack_1->GetYaxis()->SetTitle("Selected/All");
   h_Before_stack_1->GetYaxis()->SetLabelFont(42);
   h_Before_stack_1->GetYaxis()->SetLabelSize(0.035);
   h_Before_stack_1->GetYaxis()->SetTitleSize(0.035);
   h_Before_stack_1->GetYaxis()->SetTitleOffset(0);
   h_Before_stack_1->GetYaxis()->SetTitleFont(42);
   h_Before_stack_1->GetZaxis()->SetLabelFont(42);
   h_Before_stack_1->GetZaxis()->SetLabelSize(0.035);
   h_Before_stack_1->GetZaxis()->SetTitleSize(0.035);
   h_Before_stack_1->GetZaxis()->SetTitleFont(42);
   hs->Add(h_Before_stack_1,"");
   
   TH1D *h_After_stack_2 = new TH1D("h_After_stack_2"," (passed)",30,-3.1415,3.1415);
   h_After_stack_2->SetBinContent(1,0.9139153);
   h_After_stack_2->SetBinContent(2,0.7173172);
   h_After_stack_2->SetBinContent(3,0.6641826);
   h_After_stack_2->SetBinContent(4,0.9086018);
   h_After_stack_2->SetBinContent(5,0.6269884);
   h_After_stack_2->SetBinContent(6,0.680123);
   h_After_stack_2->SetBinContent(7,0.8076461);
   h_After_stack_2->SetBinContent(8,1.025498);
   h_After_stack_2->SetBinContent(9,0.9192288);
   h_After_stack_2->SetBinContent(10,0.8076461);
   h_After_stack_2->SetBinContent(11,1.238036);
   h_After_stack_2->SetBinContent(12,1.052065);
   h_After_stack_2->SetBinContent(13,1.3815);
   h_After_stack_2->SetBinContent(14,1.3815);
   h_After_stack_2->SetBinContent(15,1.248663);
   h_After_stack_2->SetBinContent(16,0.9776768);
   h_After_stack_2->SetBinContent(17,1.195529);
   h_After_stack_2->SetBinContent(18,1.51965);
   h_After_stack_2->SetBinContent(19,1.679054);
   h_After_stack_2->SetBinContent(20,0.9989307);
   h_After_stack_2->SetBinContent(21,1.392127);
   h_After_stack_2->SetBinContent(22,0.8660942);
   h_After_stack_2->SetBinContent(23,1.057379);
   h_After_stack_2->SetBinContent(24,1.062692);
   h_After_stack_2->SetBinContent(25,1.137081);
   h_After_stack_2->SetBinContent(26,1.25929);
   h_After_stack_2->SetBinContent(27,1.025498);
   h_After_stack_2->SetBinContent(28,0.8714076);
   h_After_stack_2->SetBinContent(29,0.8714076);
   h_After_stack_2->SetBinContent(30,1.036125);
   h_After_stack_2->SetBinContent(31,0.01594038);
   h_After_stack_2->SetBinError(1,0.06968539);
   h_After_stack_2->SetBinError(2,0.06173684);
   h_After_stack_2->SetBinError(3,0.0594063);
   h_After_stack_2->SetBinError(4,0.06948252);
   h_After_stack_2->SetBinError(5,0.05771896);
   h_After_stack_2->SetBinError(6,0.06011495);
   h_After_stack_2->SetBinError(7,0.06550875);
   h_After_stack_2->SetBinError(8,0.07381696);
   h_After_stack_2->SetBinError(9,0.06988767);
   h_After_stack_2->SetBinError(10,0.06550875);
   h_After_stack_2->SetBinError(11,0.08110646);
   h_After_stack_2->SetBinError(12,0.07476702);
   h_After_stack_2->SetBinError(13,0.08567699);
   h_After_stack_2->SetBinError(14,0.08567699);
   h_After_stack_2->SetBinError(15,0.08145382);
   h_After_stack_2->SetBinError(16,0.07207529);
   h_After_stack_2->SetBinError(17,0.07970192);
   h_After_stack_2->SetBinError(18,0.08985878);
   h_After_stack_2->SetBinError(19,0.09445415);
   h_After_stack_2->SetBinError(20,0.07285451);
   h_After_stack_2->SetBinError(21,0.08600588);
   h_After_stack_2->SetBinError(22,0.06783773);
   h_After_stack_2->SetBinError(23,0.07495559);
   h_After_stack_2->SetBinError(24,0.07514369);
   h_After_stack_2->SetBinError(25,0.07772923);
   h_After_stack_2->SetBinError(26,0.08179969);
   h_After_stack_2->SetBinError(27,0.07381696);
   h_After_stack_2->SetBinError(28,0.0680455);
   h_After_stack_2->SetBinError(29,0.0680455);
   h_After_stack_2->SetBinError(30,0.07419845);
   h_After_stack_2->SetBinError(31,0.009203185);
   h_After_stack_2->SetEntries(5948);
   h_After_stack_2->SetLineColor(3);
   h_After_stack_2->SetLineWidth(2);
   h_After_stack_2->GetXaxis()->SetTitle("Muon Beam #theta");
   h_After_stack_2->GetXaxis()->SetLabelFont(42);
   h_After_stack_2->GetXaxis()->SetLabelSize(0.035);
   h_After_stack_2->GetXaxis()->SetTitleSize(0.035);
   h_After_stack_2->GetXaxis()->SetTitleFont(42);
   h_After_stack_2->GetYaxis()->SetTitle("Selected/All");
   h_After_stack_2->GetYaxis()->SetLabelFont(42);
   h_After_stack_2->GetYaxis()->SetLabelSize(0.035);
   h_After_stack_2->GetYaxis()->SetTitleSize(0.035);
   h_After_stack_2->GetYaxis()->SetTitleOffset(0);
   h_After_stack_2->GetYaxis()->SetTitleFont(42);
   h_After_stack_2->GetZaxis()->SetLabelFont(42);
   h_After_stack_2->GetZaxis()->SetLabelSize(0.035);
   h_After_stack_2->GetZaxis()->SetTitleSize(0.035);
   h_After_stack_2->GetZaxis()->SetTitleFont(42);
   hs->Add(h_After_stack_2,"");
   hs->Draw("nostack e0");
   TGaxis *gaxis = new TGaxis(3.1415,0,3.1415,3.214644,0,0.9380109,510,"+L");
   gaxis->SetLabelOffset(0.005);
   gaxis->SetLabelSize(0.045);
   gaxis->SetTickSize(0.03);
   gaxis->SetGridLength(0);
   gaxis->SetTitleOffset(0.954);
   gaxis->SetTitleSize(0.05);
   gaxis->SetTitleColor(632);
   gaxis->SetTitleFont(62);
   gaxis->SetTitle("Efficiency");

   ci = TColor::GetColor("#ff0000");
   gaxis->SetLabelColor(ci);
   gaxis->Draw();
   
   Double_t Graph0_fx3008[30] = {
   -3.036783,
   -2.82735,
   -2.617917,
   -2.408483,
   -2.19905,
   -1.989617,
   -1.780183,
   -1.57075,
   -1.361317,
   -1.151883,
   -0.94245,
   -0.7330167,
   -0.5235833,
   -0.31415,
   -0.1047167,
   0.1047167,
   0.31415,
   0.5235833,
   0.7330167,
   0.94245,
   1.151883,
   1.361317,
   1.57075,
   1.780183,
   1.989617,
   2.19905,
   2.408483,
   2.617917,
   2.82735,
   3.036783};
   Double_t Graph0_fy3008[30] = {
   2.112755,
   2.112587,
   2.089686,
   2.108028,
   2.011921,
   2.021507,
   2.042812,
   2.197434,
   2.155949,
   2.058961,
   2.321253,
   2.339872,
   2.338694,
   2.126593,
   2.075683,
   2.067488,
   2.228596,
   2.344848,
   2.237519,
   1.934811,
   2.026854,
   1.880859,
   1.739771,
   2.046021,
   2.048593,
   2.320627,
   2.257432,
   2.186934,
   2.361521,
   2.590239};
   Double_t Graph0_felx3008[30] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph0_fely3008[30] = {
   0.09980488,
   0.1126808,
   0.1167639,
   0.1000402,
   0.1187529,
   0.1142107,
   0.1051679,
   0.09497698,
   0.09998107,
   0.1054235,
   0.08683074,
   0.09425969,
   0.08216312,
   0.08125415,
   0.08495631,
   0.09592527,
   0.08811056,
   0.0783052,
   0.07431317,
   0.092761,
   0.07988537,
   0.09844798,
   0.08588301,
   0.09171748,
   0.08869649,
   0.08608878,
   0.09531639,
   0.102985,
   0.1036427,
   0.0930842};
   Double_t Graph0_fehx3008[30] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph0_fehy3008[30] = {
   0.09792999,
   0.1102973,
   0.1143651,
   0.09818086,
   0.1168127,
   0.1123546,
   0.103477,
   0.09286939,
   0.09787322,
   0.1036357,
   0.08451281,
   0.09142845,
   0.08000916,
   0.07995972,
   0.08373118,
   0.0944039,
   0.0861575,
   0.07632177,
   0.07289072,
   0.09188953,
   0.07895651,
   0.09770963,
   0.08579521,
   0.09041569,
   0.08746846,
   0.08381273,
   0.09288306,
   0.1005726,
   0.1000781,
   0.08863072};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(30,Graph0_fx3008,Graph0_fy3008,Graph0_felx3008,Graph0_fehx3008,Graph0_fely3008,Graph0_fehy3008);
   grae->SetName("Graph0");
   grae->SetTitle("Graph");
   grae->SetFillStyle(1000);

   ci = TColor::GetColor("#ff0000");
   grae->SetLineColor(ci);
   grae->SetLineWidth(2);

   ci = TColor::GetColor("#ff0000");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(5);
   grae->SetMarkerSize(2);
   
   TH1F *Graph_Graph3008 = new TH1F("Graph_Graph3008","Graph",100,-3.64414,3.64414);
   Graph_Graph3008->SetMinimum(1.551389);
   Graph_Graph3008->SetMaximum(2.781368);
   Graph_Graph3008->SetDirectory(0);
   Graph_Graph3008->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph3008->SetLineColor(ci);
   Graph_Graph3008->GetXaxis()->SetLabelFont(42);
   Graph_Graph3008->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph3008->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph3008->GetXaxis()->SetTitleFont(42);
   Graph_Graph3008->GetYaxis()->SetLabelFont(42);
   Graph_Graph3008->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph3008->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph3008->GetYaxis()->SetTitleOffset(0);
   Graph_Graph3008->GetYaxis()->SetTitleFont(42);
   Graph_Graph3008->GetZaxis()->SetLabelFont(42);
   Graph_Graph3008->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph3008->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph3008->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph3008);
   
   grae->Draw("p ");
   
   leg = new TLegend(0.54,0.82,0.89,0.9,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextAlign(32);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   entry=leg->AddEntry("NULL","NuMI RHC, 12.5 #times 10^{20} POT","h");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   leg = new TLegend(0.45,0.9,0.89,0.985,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextAlign(32);
   leg->SetTextFont(62);
   leg->SetTextSize(0.05);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   entry=leg->AddEntry("NULL","MicroBooNE Simulation, Preliminary","h");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   leg->Draw();
   pad1->Modified();
   c1->cd();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
