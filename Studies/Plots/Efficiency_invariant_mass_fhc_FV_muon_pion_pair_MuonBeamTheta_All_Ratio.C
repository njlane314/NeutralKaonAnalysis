void Efficiency_invariant_mass_fhc_FV_muon_pion_pair_MuonBeamTheta_All_Ratio()
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
   pad1->Range(-0.3926875,-0.9104526,3.534188,8.194073);
   pad1->SetFillColor(0);
   pad1->SetBorderMode(0);
   pad1->SetBorderSize(2);
   pad1->SetTopMargin(0.01);
   pad1->SetFrameBorderMode(0);
   pad1->SetFrameBorderMode(0);
   
   THStack *hs = new THStack();
   hs->SetName("hs");
   hs->SetTitle(";Beam-Muon #theta;Events/bin");
   hs->SetMaximum(8.103028);
   
   TH1F *hs_stack_7 = new TH1F("hs_stack_7","",30,0,3.1415);
   hs_stack_7->SetMinimum(0);
   hs_stack_7->SetMaximum(8.103028);
   hs_stack_7->SetDirectory(0);
   hs_stack_7->SetStats(0);

   ci = TColor::GetColor("#000099");
   hs_stack_7->SetLineColor(ci);
   hs_stack_7->GetXaxis()->SetTitle("Beam-Muon #theta");
   hs_stack_7->GetXaxis()->SetLabelFont(42);
   hs_stack_7->GetXaxis()->SetLabelSize(0.045);
   hs_stack_7->GetXaxis()->SetTitleSize(0.05);
   hs_stack_7->GetXaxis()->SetTitleOffset(0.93);
   hs_stack_7->GetXaxis()->SetTitleFont(42);
   hs_stack_7->GetYaxis()->SetTitle("Events/bin");
   hs_stack_7->GetYaxis()->SetLabelFont(42);
   hs_stack_7->GetYaxis()->SetLabelSize(0.045);
   hs_stack_7->GetYaxis()->SetTitleSize(0.05);
   hs_stack_7->GetYaxis()->SetTitleOffset(1.06);
   hs_stack_7->GetYaxis()->SetTitleFont(42);
   hs_stack_7->GetZaxis()->SetLabelFont(42);
   hs_stack_7->GetZaxis()->SetLabelSize(0.035);
   hs_stack_7->GetZaxis()->SetTitleSize(0.035);
   hs_stack_7->GetZaxis()->SetTitleFont(42);
   hs->SetHistogram(hs_stack_7);
   
   
   TH1D *h_Before_stack_1 = new TH1D("h_Before_stack_1"," (total)",30,0,3.1415);
   h_Before_stack_1->SetBinContent(1,1.004244);
   h_Before_stack_1->SetBinContent(2,3.459063);
   h_Before_stack_1->SetBinContent(3,4.957459);
   h_Before_stack_1->SetBinContent(4,6.253944);
   h_Before_stack_1->SetBinContent(5,6.482423);
   h_Before_stack_1->SetBinContent(6,5.642896);
   h_Before_stack_1->SetBinContent(7,3.703482);
   h_Before_stack_1->SetBinContent(8,4.229515);
   h_Before_stack_1->SetBinContent(9,2.449506);
   h_Before_stack_1->SetBinContent(10,2.630163);
   h_Before_stack_1->SetBinContent(11,1.684367);
   h_Before_stack_1->SetBinContent(12,1.365559);
   h_Before_stack_1->SetBinContent(13,1.238036);
   h_Before_stack_1->SetBinContent(14,0.5526);
   h_Before_stack_1->SetBinContent(15,0.9298557);
   h_Before_stack_1->SetBinContent(16,0.9086018);
   h_Before_stack_1->SetBinContent(17,0.41445);
   h_Before_stack_1->SetBinContent(18,0.541973);
   h_Before_stack_1->SetBinContent(19,0.2709865);
   h_Before_stack_1->SetBinContent(20,0.3081807);
   h_Before_stack_1->SetBinContent(21,0.2656731);
   h_Before_stack_1->SetBinContent(22,0.207225);
   h_Before_stack_1->SetBinContent(23,0.1328365);
   h_Before_stack_1->SetBinContent(24,0.1222096);
   h_Before_stack_1->SetBinContent(25,0.1009558);
   h_Before_stack_1->SetBinContent(26,0.04782115);
   h_Before_stack_1->SetBinContent(27,0.1009558);
   h_Before_stack_1->SetBinContent(29,0.02656731);
   h_Before_stack_1->SetBinError(1,0.07304801);
   h_Before_stack_1->SetBinError(2,0.1355714);
   h_Before_stack_1->SetBinError(3,0.1622999);
   h_Before_stack_1->SetBinError(4,0.1822912);
   h_Before_stack_1->SetBinError(5,0.1855912);
   h_Before_stack_1->SetBinError(6,0.1731569);
   h_Before_stack_1->SetBinError(7,0.1402794);
   h_Before_stack_1->SetBinError(8,0.1499112);
   h_Before_stack_1->SetBinError(9,0.1140848);
   h_Before_stack_1->SetBinError(10,0.118217);
   h_Before_stack_1->SetBinError(11,0.09460348);
   h_Before_stack_1->SetBinError(12,0.08518126);
   h_Before_stack_1->SetBinError(13,0.08110646);
   h_Before_stack_1->SetBinError(14,0.05418688);
   h_Before_stack_1->SetBinError(15,0.07029048);
   h_Before_stack_1->SetBinError(16,0.06948252);
   h_Before_stack_1->SetBinError(17,0.04692722);
   h_Before_stack_1->SetBinError(18,0.05366333);
   h_Before_stack_1->SetBinError(19,0.0379457);
   h_Before_stack_1->SetBinError(20,0.04046611);
   h_Before_stack_1->SetBinError(21,0.03757184);
   h_Before_stack_1->SetBinError(22,0.03318255);
   h_Before_stack_1->SetBinError(23,0.02656731);
   h_Before_stack_1->SetBinError(24,0.02548246);
   h_Before_stack_1->SetBinError(25,0.02316084);
   h_Before_stack_1->SetBinError(26,0.01594038);
   h_Before_stack_1->SetBinError(27,0.02316084);
   h_Before_stack_1->SetBinError(29,0.01188126);
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
   
   TH1D *h_After_stack_2 = new TH1D("h_After_stack_2"," (passed)",30,0,3.1415);
   h_After_stack_2->SetBinContent(1,0.7332576);
   h_After_stack_2->SetBinContent(2,2.151952);
   h_After_stack_2->SetBinContent(3,3.103061);
   h_After_stack_2->SetBinContent(4,4.107305);
   h_After_stack_2->SetBinContent(5,4.28265);
   h_After_stack_2->SetBinContent(6,3.501571);
   h_After_stack_2->SetBinContent(7,2.359177);
   h_After_stack_2->SetBinContent(8,2.810821);
   h_After_stack_2->SetBinContent(9,1.524963);
   h_After_stack_2->SetBinContent(10,1.716248);
   h_After_stack_2->SetBinContent(11,0.9776768);
   h_After_stack_2->SetBinContent(12,0.7066903);
   h_After_stack_2->SetBinContent(13,0.6641826);
   h_After_stack_2->SetBinContent(14,0.2816134);
   h_After_stack_2->SetBinContent(15,0.4994653);
   h_After_stack_2->SetBinContent(16,0.5366596);
   h_After_stack_2->SetBinContent(17,0.2337923);
   h_After_stack_2->SetBinContent(18,0.3506884);
   h_After_stack_2->SetBinContent(19,0.1540904);
   h_After_stack_2->SetBinContent(20,0.1859711);
   h_After_stack_2->SetBinContent(21,0.1062692);
   h_After_stack_2->SetBinContent(22,0.1115827);
   h_After_stack_2->SetBinContent(23,0.08501538);
   h_After_stack_2->SetBinContent(24,0.05844807);
   h_After_stack_2->SetBinContent(25,0.04250769);
   h_After_stack_2->SetBinContent(26,0.02656731);
   h_After_stack_2->SetBinContent(27,0.02125384);
   h_After_stack_2->SetBinContent(29,0.005313461);
   h_After_stack_2->SetBinError(1,0.06241903);
   h_After_stack_2->SetBinError(2,0.1069313);
   h_After_stack_2->SetBinError(3,0.1284056);
   h_After_stack_2->SetBinError(4,0.1477295);
   h_After_stack_2->SetBinError(5,0.1508499);
   h_After_stack_2->SetBinError(6,0.1364018);
   h_After_stack_2->SetBinError(7,0.1119616);
   h_After_stack_2->SetBinError(8,0.1222096);
   h_After_stack_2->SetBinError(9,0.09001574);
   h_After_stack_2->SetBinError(10,0.09549459);
   h_After_stack_2->SetBinError(11,0.07207529);
   h_After_stack_2->SetBinError(12,0.06127782);
   h_After_stack_2->SetBinError(13,0.0594063);
   h_After_stack_2->SetBinError(14,0.03868258);
   h_After_stack_2->SetBinError(15,0.05151592);
   h_After_stack_2->SetBinError(16,0.05339962);
   h_After_stack_2->SetBinError(17,0.03524551);
   h_After_stack_2->SetBinError(18,0.04316676);
   h_After_stack_2->SetBinError(19,0.02861386);
   h_After_stack_2->SetBinError(20,0.03143486);
   h_After_stack_2->SetBinError(21,0.02376252);
   h_After_stack_2->SetBinError(22,0.02434934);
   h_After_stack_2->SetBinError(23,0.02125384);
   h_After_stack_2->SetBinError(24,0.01762276);
   h_After_stack_2->SetBinError(25,0.01502874);
   h_After_stack_2->SetBinError(26,0.01188126);
   h_After_stack_2->SetBinError(27,0.01062692);
   h_After_stack_2->SetBinError(29,0.005313461);
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
   TGaxis *gaxis = new TGaxis(3.1415,0,3.1415,8.103028,0,0.9135876,510,"+L");
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
   
   Double_t Graph0_fx3007[28] = {
   0.05235833,
   0.157075,
   0.2617917,
   0.3665083,
   0.471225,
   0.5759417,
   0.6806583,
   0.785375,
   0.8900917,
   0.9948083,
   1.099525,
   1.204242,
   1.308958,
   1.413675,
   1.518392,
   1.623108,
   1.727825,
   1.832542,
   1.937258,
   2.041975,
   2.146692,
   2.251408,
   2.356125,
   2.460842,
   2.565558,
   2.670275,
   2.774992,
   2.984425};
   Double_t Graph0_fy3007[28] = {
   6.476113,
   5.517866,
   5.55173,
   5.825057,
   5.859659,
   5.503742,
   5.649985,
   5.894402,
   5.521767,
   5.787546,
   5.148203,
   4.590031,
   4.758294,
   4.520013,
   4.764167,
   5.238686,
   5.003285,
   5.739062,
   5.043418,
   5.35226,
   3.547784,
   4.775863,
   5.676454,
   4.241915,
   3.734509,
   4.927477,
   1.867255,
   1.773892};
   Double_t Graph0_felx3007[28] = {
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
   Double_t Graph0_fely3007[28] = {
   0.2905307,
   0.1684578,
   0.1403701,
   0.1227466,
   0.1202433,
   0.1318812,
   0.1615775,
   0.1486355,
   0.2002665,
   0.1902072,
   0.2451911,
   0.274264,
   0.287834,
   0.4288112,
   0.3318084,
   0.3328425,
   0.4937526,
   0.4217886,
   0.6077539,
   0.5673453,
   0.588151,
   0.6922631,
   0.8465467,
   0.8760222,
   0.9285031,
   1.351239,
   0.7109452,
   1.116707};
   Double_t Graph0_fehx3007[28] = {
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
   Double_t Graph0_fehy3007[28] = {
   0.2764103,
   0.1662698,
   0.1387945,
   0.1211913,
   0.1187055,
   0.1305561,
   0.1592842,
   0.1462227,
   0.197169,
   0.186616,
   0.2422398,
   0.2734728,
   0.2860169,
   0.4277482,
   0.3293514,
   0.3267069,
   0.4843566,
   0.4052096,
   0.5925495,
   0.547104,
   0.6107401,
   0.6812376,
   0.7853314,
   0.8862724,
   0.9729165,
   1.291115,
   0.8763817,
   1.666331};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(28,Graph0_fx3007,Graph0_fy3007,Graph0_felx3007,Graph0_fehx3007,Graph0_fely3007,Graph0_fehy3007);
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
   
   TH1F *Graph_Graph3007 = new TH1F("Graph_Graph3007","Graph",100,0,3.277632);
   Graph_Graph3007->SetMinimum(0.04765152);
   Graph_Graph3007->SetMaximum(7.362057);
   Graph_Graph3007->SetDirectory(0);
   Graph_Graph3007->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph3007->SetLineColor(ci);
   Graph_Graph3007->GetXaxis()->SetLabelFont(42);
   Graph_Graph3007->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph3007->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph3007->GetXaxis()->SetTitleFont(42);
   Graph_Graph3007->GetYaxis()->SetLabelFont(42);
   Graph_Graph3007->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph3007->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph3007->GetYaxis()->SetTitleOffset(0);
   Graph_Graph3007->GetYaxis()->SetTitleFont(42);
   Graph_Graph3007->GetZaxis()->SetLabelFont(42);
   Graph_Graph3007->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph3007->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph3007->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph3007);
   
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
