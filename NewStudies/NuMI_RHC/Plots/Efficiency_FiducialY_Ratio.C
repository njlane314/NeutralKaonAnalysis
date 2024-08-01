void Efficiency_FiducialY_Ratio()
{
//=========Macro generated from canvas: c1/c1
//=========  (Tue Apr 16 08:41:20 2024) by ROOT version 6.12/06
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
   pad1->Range(-125,-0.7560108,125,6.804097);
   pad1->SetFillColor(0);
   pad1->SetBorderMode(0);
   pad1->SetBorderSize(2);
   pad1->SetTopMargin(0.01);
   pad1->SetFrameBorderMode(0);
   pad1->SetFrameBorderMode(0);
   
   THStack *hs = new THStack();
   hs->SetName("hs");
   hs->SetTitle("");
   hs->SetMaximum(6.728496);
   
   TH1F *hs_stack_2 = new TH1F("hs_stack_2","",25,-100,100);
   hs_stack_2->SetMinimum(0);
   hs_stack_2->SetMaximum(6.728496);
   hs_stack_2->SetDirectory(0);
   hs_stack_2->SetStats(0);

   ci = TColor::GetColor("#000099");
   hs_stack_2->SetLineColor(ci);
   hs_stack_2->GetXaxis()->SetTitle("True Neutrino Interaction Vertex, Y (cm)");
   hs_stack_2->GetXaxis()->SetLabelFont(42);
   hs_stack_2->GetXaxis()->SetLabelSize(0.045);
   hs_stack_2->GetXaxis()->SetTitleSize(0.05);
   hs_stack_2->GetXaxis()->SetTitleOffset(0.93);
   hs_stack_2->GetXaxis()->SetTitleFont(42);
   hs_stack_2->GetYaxis()->SetTitle("Entries/bin");
   hs_stack_2->GetYaxis()->SetLabelFont(42);
   hs_stack_2->GetYaxis()->SetLabelSize(0.045);
   hs_stack_2->GetYaxis()->SetTitleSize(0.05);
   hs_stack_2->GetYaxis()->SetTitleOffset(1.06);
   hs_stack_2->GetYaxis()->SetTitleFont(42);
   hs_stack_2->GetZaxis()->SetLabelFont(42);
   hs_stack_2->GetZaxis()->SetLabelSize(0.035);
   hs_stack_2->GetZaxis()->SetTitleSize(0.035);
   hs_stack_2->GetZaxis()->SetTitleFont(42);
   hs->SetHistogram(hs_stack_2);
   
   
   TH1D *h_Before_stack_1 = new TH1D("h_Before_stack_1"," (total)",25,-100,100);
   h_Before_stack_1->SetBinContent(0,2.04726);
   h_Before_stack_1->SetBinContent(1,1.947394);
   h_Before_stack_1->SetBinContent(2,3.834868);
   h_Before_stack_1->SetBinContent(3,4.963358);
   h_Before_stack_1->SetBinContent(4,4.553906);
   h_Before_stack_1->SetBinContent(5,4.354173);
   h_Before_stack_1->SetBinContent(6,5.163091);
   h_Before_stack_1->SetBinContent(7,5.083198);
   h_Before_stack_1->SetBinContent(8,4.444053);
   h_Before_stack_1->SetBinContent(9,4.444053);
   h_Before_stack_1->SetBinContent(10,4.42408);
   h_Before_stack_1->SetBinContent(11,4.444053);
   h_Before_stack_1->SetBinContent(12,4.553906);
   h_Before_stack_1->SetBinContent(13,4.923411);
   h_Before_stack_1->SetBinContent(14,4.493986);
   h_Before_stack_1->SetBinContent(15,5.382797);
   h_Before_stack_1->SetBinContent(16,4.523946);
   h_Before_stack_1->SetBinContent(17,4.474013);
   h_Before_stack_1->SetBinContent(18,3.954708);
   h_Before_stack_1->SetBinContent(19,4.384133);
   h_Before_stack_1->SetBinContent(20,4.523946);
   h_Before_stack_1->SetBinContent(21,4.633799);
   h_Before_stack_1->SetBinContent(22,4.923411);
   h_Before_stack_1->SetBinContent(23,4.483999);
   h_Before_stack_1->SetBinContent(24,3.974681);
   h_Before_stack_1->SetBinContent(25,3.934735);
   h_Before_stack_1->SetBinContent(26,3.395456);
   h_Before_stack_1->SetBinError(0,0.1429869);
   h_Before_stack_1->SetBinError(1,0.1394558);
   h_Before_stack_1->SetBinError(2,0.1956973);
   h_Before_stack_1->SetBinError(3,0.222637);
   h_Before_stack_1->SetBinError(4,0.2132562);
   h_Before_stack_1->SetBinError(5,0.2085271);
   h_Before_stack_1->SetBinError(6,0.2270725);
   h_Before_stack_1->SetBinError(7,0.2253088);
   h_Before_stack_1->SetBinError(8,0.2106683);
   h_Before_stack_1->SetBinError(9,0.2106683);
   h_Before_stack_1->SetBinError(10,0.2101944);
   h_Before_stack_1->SetBinError(11,0.2106683);
   h_Before_stack_1->SetBinError(12,0.2132562);
   h_Before_stack_1->SetBinError(13,0.2217393);
   h_Before_stack_1->SetBinError(14,0.2118485);
   h_Before_stack_1->SetBinError(15,0.2318535);
   h_Before_stack_1->SetBinError(16,0.2125535);
   h_Before_stack_1->SetBinError(17,0.2113772);
   h_Before_stack_1->SetBinError(18,0.1987315);
   h_Before_stack_1->SetBinError(19,0.2092433);
   h_Before_stack_1->SetBinError(20,0.2125535);
   h_Before_stack_1->SetBinError(21,0.2151187);
   h_Before_stack_1->SetBinError(22,0.2217393);
   h_Before_stack_1->SetBinError(23,0.211613);
   h_Before_stack_1->SetBinError(24,0.1992328);
   h_Before_stack_1->SetBinError(25,0.1982291);
   h_Before_stack_1->SetBinError(26,0.1841445);
   h_Before_stack_1->SetEntries(11642);
   h_Before_stack_1->SetLineWidth(2);
   h_Before_stack_1->GetXaxis()->SetTitle("True Neutrino Interaction Vertex, Y (cm)");
   h_Before_stack_1->GetXaxis()->SetLabelFont(42);
   h_Before_stack_1->GetXaxis()->SetLabelSize(0.035);
   h_Before_stack_1->GetXaxis()->SetTitleSize(0.035);
   h_Before_stack_1->GetXaxis()->SetTitleFont(42);
   h_Before_stack_1->GetYaxis()->SetTitle(" Entries/bin");
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
   
   TH1D *h_After_stack_2 = new TH1D("h_After_stack_2"," (passed)",25,-100,100);
   h_After_stack_2->SetBinContent(0,1.507982);
   h_After_stack_2->SetBinContent(1,1.677755);
   h_After_stack_2->SetBinContent(2,3.165764);
   h_After_stack_2->SetBinContent(3,4.124481);
   h_After_stack_2->SetBinContent(4,3.944721);
   h_After_stack_2->SetBinContent(5,3.754975);
   h_After_stack_2->SetBinContent(6,4.643786);
   h_After_stack_2->SetBinContent(7,4.384133);
   h_After_stack_2->SetBinContent(8,3.744988);
   h_After_stack_2->SetBinContent(9,3.844855);
   h_After_stack_2->SetBinContent(10,3.904775);
   h_After_stack_2->SetBinContent(11,3.884801);
   h_After_stack_2->SetBinContent(12,4.044588);
   h_After_stack_2->SetBinContent(13,4.24432);
   h_After_stack_2->SetBinContent(14,3.894788);
   h_After_stack_2->SetBinContent(15,4.753639);
   h_After_stack_2->SetBinContent(16,3.754975);
   h_After_stack_2->SetBinContent(17,3.774948);
   h_After_stack_2->SetBinContent(18,3.255643);
   h_After_stack_2->SetBinContent(19,3.685069);
   h_After_stack_2->SetBinContent(20,3.685069);
   h_After_stack_2->SetBinContent(21,3.854841);
   h_After_stack_2->SetBinContent(22,4.104507);
   h_After_stack_2->SetBinContent(23,3.744988);
   h_After_stack_2->SetBinContent(24,3.14579);
   h_After_stack_2->SetBinContent(25,3.225683);
   h_After_stack_2->SetBinContent(26,2.496659);
   h_After_stack_2->SetBinError(0,0.1227178);
   h_After_stack_2->SetBinError(1,0.1294416);
   h_After_stack_2->SetBinError(2,0.177807);
   h_After_stack_2->SetBinError(3,0.2029524);
   h_After_stack_2->SetBinError(4,0.1984805);
   h_After_stack_2->SetBinError(5,0.1936481);
   h_After_stack_2->SetBinError(6,0.2153504);
   h_After_stack_2->SetBinError(7,0.2092433);
   h_After_stack_2->SetBinError(8,0.1933904);
   h_After_stack_2->SetBinError(9,0.1959519);
   h_After_stack_2->SetBinError(10,0.1974729);
   h_After_stack_2->SetBinError(11,0.1969672);
   h_After_stack_2->SetBinError(12,0.2009772);
   h_After_stack_2->SetBinError(13,0.2058798);
   h_After_stack_2->SetBinError(14,0.1972203);
   h_After_stack_2->SetBinError(15,0.2178827);
   h_After_stack_2->SetBinError(16,0.1936481);
   h_After_stack_2->SetBinError(17,0.1941624);
   h_After_stack_2->SetBinError(18,0.1803134);
   h_After_stack_2->SetBinError(19,0.191837);
   h_After_stack_2->SetBinError(20,0.191837);
   h_After_stack_2->SetBinError(21,0.1962063);
   h_After_stack_2->SetBinError(22,0.2024604);
   h_After_stack_2->SetBinError(23,0.1933904);
   h_After_stack_2->SetBinError(24,0.1772452);
   h_After_stack_2->SetBinError(25,0.1794818);
   h_After_stack_2->SetBinError(26,0.1579026);
   h_After_stack_2->SetEntries(9838);
   h_After_stack_2->SetLineColor(3);
   h_After_stack_2->SetLineWidth(2);
   h_After_stack_2->GetXaxis()->SetTitle("True Neutrino Interaction Vertex, Y (cm)");
   h_After_stack_2->GetXaxis()->SetLabelFont(42);
   h_After_stack_2->GetXaxis()->SetLabelSize(0.035);
   h_After_stack_2->GetXaxis()->SetTitleSize(0.035);
   h_After_stack_2->GetXaxis()->SetTitleFont(42);
   h_After_stack_2->GetYaxis()->SetTitle(" Entries/bin");
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
   TGaxis *gaxis = new TGaxis(100,0,100,6.728496,0,1.094472,510,"+L");
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
   
   Double_t Graph0_fx3002[25] = {
   -96,
   -88,
   -80,
   -72,
   -64,
   -56,
   -48,
   -40,
   -32,
   -24,
   -16,
   -8,
   0,
   8,
   16,
   24,
   32,
   40,
   48,
   56,
   64,
   72,
   80,
   88,
   96};
   Double_t Graph0_fy3002[25] = {
   5.296487,
   5.075061,
   5.108659,
   5.325317,
   5.301693,
   5.52937,
   5.302247,
   5.180653,
   5.318803,
   5.426081,
   5.374064,
   5.460135,
   5.299748,
   5.328013,
   5.429145,
   5.102733,
   5.187129,
   5.060992,
   5.167436,
   5.007736,
   5.114257,
   5.125168,
   5.1345,
   4.865648,
   5.039872};
   Double_t Graph0_felx3002[25] = {
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
   Double_t Graph0_fely3002[25] = {
   0.1582902,
   0.1216228,
   0.105331,
   0.1006021,
   0.1041083,
   0.08396448,
   0.09611397,
   0.1084873,
   0.1021934,
   0.09690968,
   0.09943033,
   0.09361267,
   0.09781876,
   0.1011594,
   0.0874226,
   0.1106814,
   0.1078378,
   0.1202934,
   0.1098095,
   0.1142685,
   0.1088796,
   0.1051345,
   0.10991,
   0.1272174,
   0.1214538};
   Double_t Graph0_fehx3002[25] = {
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
   Double_t Graph0_fehy3002[25] = {
   0.1433458,
   0.1147748,
   0.09994666,
   0.09410692,
   0.09738766,
   0.07771018,
   0.09035368,
   0.1022619,
   0.09555746,
   0.08992263,
   0.0926298,
   0.08672519,
   0.09187867,
   0.09456979,
   0.08167038,
   0.1047928,
   0.1016349,
   0.1136992,
   0.103539,
   0.1086566,
   0.1030973,
   0.0996624,
   0.1038757,
   0.1213031,
   0.1148969};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(25,Graph0_fx3002,Graph0_fy3002,Graph0_felx3002,Graph0_fehx3002,Graph0_fely3002,Graph0_fehy3002);
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
   
   TH1F *Graph_Graph3002 = new TH1F("Graph_Graph3002","Graph",100,-115.2,115.2);
   Graph_Graph3002->SetMinimum(4.651566);
   Graph_Graph3002->SetMaximum(5.693945);
   Graph_Graph3002->SetDirectory(0);
   Graph_Graph3002->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph3002->SetLineColor(ci);
   Graph_Graph3002->GetXaxis()->SetLabelFont(42);
   Graph_Graph3002->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph3002->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph3002->GetXaxis()->SetTitleFont(42);
   Graph_Graph3002->GetYaxis()->SetLabelFont(42);
   Graph_Graph3002->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph3002->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph3002->GetYaxis()->SetTitleOffset(0);
   Graph_Graph3002->GetYaxis()->SetTitleFont(42);
   Graph_Graph3002->GetZaxis()->SetLabelFont(42);
   Graph_Graph3002->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph3002->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph3002->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph3002);
   
   grae->Draw("p ");
   
   leg = new TLegend(0.54,0.82,0.89,0.9,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextAlign(32);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   entry=leg->AddEntry("NULL","NuMI RHC, 1.5 #times 10^{21} POT","h");
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
