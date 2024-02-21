void Efficiency_invariant_mass_fhc_FV_muon_pion_pair_Q2_All_Ratio()
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
   pad1->Range(-0.375,-0.4552263,3.375,4.097037);
   pad1->SetFillColor(0);
   pad1->SetBorderMode(0);
   pad1->SetBorderSize(2);
   pad1->SetTopMargin(0.01);
   pad1->SetFrameBorderMode(0);
   pad1->SetFrameBorderMode(0);
   
   THStack *hs = new THStack();
   hs->SetName("hs");
   hs->SetTitle(";True Q^{2} (GeV^{2});Events/bin");
   hs->SetMaximum(4.051514);
   
   TH1F *hs_stack_1 = new TH1F("hs_stack_1","",30,0,3);
   hs_stack_1->SetMinimum(0);
   hs_stack_1->SetMaximum(4.051514);
   hs_stack_1->SetDirectory(0);
   hs_stack_1->SetStats(0);

   ci = TColor::GetColor("#000099");
   hs_stack_1->SetLineColor(ci);
   hs_stack_1->GetXaxis()->SetTitle("True Q^{2} (GeV^{2})");
   hs_stack_1->GetXaxis()->SetLabelFont(42);
   hs_stack_1->GetXaxis()->SetLabelSize(0.045);
   hs_stack_1->GetXaxis()->SetTitleSize(0.05);
   hs_stack_1->GetXaxis()->SetTitleOffset(0.93);
   hs_stack_1->GetXaxis()->SetTitleFont(42);
   hs_stack_1->GetYaxis()->SetTitle("Events/bin");
   hs_stack_1->GetYaxis()->SetLabelFont(42);
   hs_stack_1->GetYaxis()->SetLabelSize(0.045);
   hs_stack_1->GetYaxis()->SetTitleSize(0.05);
   hs_stack_1->GetYaxis()->SetTitleOffset(1.06);
   hs_stack_1->GetYaxis()->SetTitleFont(42);
   hs_stack_1->GetZaxis()->SetLabelFont(42);
   hs_stack_1->GetZaxis()->SetLabelSize(0.035);
   hs_stack_1->GetZaxis()->SetTitleSize(0.035);
   hs_stack_1->GetZaxis()->SetTitleFont(42);
   hs->SetHistogram(hs_stack_1);
   
   
   TH1D *h_Before_stack_1 = new TH1D("h_Before_stack_1"," (total)",30,0,3);
   h_Before_stack_1->SetBinContent(1,0.6163615);
   h_Before_stack_1->SetBinContent(2,1.705621);
   h_Before_stack_1->SetBinContent(3,1.9341);
   h_Before_stack_1->SetBinContent(4,2.608909);
   h_Before_stack_1->SetBinContent(5,2.523894);
   h_Before_stack_1->SetBinContent(6,3.241211);
   h_Before_stack_1->SetBinContent(7,2.943657);
   h_Before_stack_1->SetBinContent(8,2.826761);
   h_Before_stack_1->SetBinContent(9,2.805507);
   h_Before_stack_1->SetBinContent(10,2.704552);
   h_Before_stack_1->SetBinContent(11,2.444192);
   h_Before_stack_1->SetBinContent(12,2.476073);
   h_Before_stack_1->SetBinContent(13,2.268848);
   h_Before_stack_1->SetBinContent(14,2.093504);
   h_Before_stack_1->SetBinContent(15,1.3815);
   h_Before_stack_1->SetBinContent(16,1.466515);
   h_Before_stack_1->SetBinContent(17,1.232723);
   h_Before_stack_1->SetBinContent(18,1.195529);
   h_Before_stack_1->SetBinContent(19,0.8342134);
   h_Before_stack_1->SetBinContent(20,0.8342134);
   h_Before_stack_1->SetBinContent(21,0.9883038);
   h_Before_stack_1->SetBinContent(22,0.9298557);
   h_Before_stack_1->SetBinContent(23,0.4675846);
   h_Before_stack_1->SetBinContent(24,0.680123);
   h_Before_stack_1->SetBinContent(25,0.3772557);
   h_Before_stack_1->SetBinContent(26,0.7598249);
   h_Before_stack_1->SetBinContent(27,0.5207192);
   h_Before_stack_1->SetBinContent(28,0.4782115);
   h_Before_stack_1->SetBinContent(29,0.483525);
   h_Before_stack_1->SetBinContent(30,0.4622711);
   h_Before_stack_1->SetBinContent(31,3.74599);
   h_Before_stack_1->SetBinError(1,0.05722773);
   h_Before_stack_1->SetBinError(2,0.09519848);
   h_Before_stack_1->SetBinError(3,0.1013744);
   h_Before_stack_1->SetBinError(4,0.1177384);
   h_Before_stack_1->SetBinError(5,0.1158042);
   h_Before_stack_1->SetBinError(6,0.1312328);
   h_Before_stack_1->SetBinError(7,0.125064);
   h_Before_stack_1->SetBinError(8,0.1225556);
   h_Before_stack_1->SetBinError(9,0.122094);
   h_Before_stack_1->SetBinError(10,0.1198771);
   h_Before_stack_1->SetBinError(11,0.113961);
   h_Before_stack_1->SetBinError(12,0.1147019);
   h_Before_stack_1->SetBinError(13,0.1097972);
   h_Before_stack_1->SetBinError(14,0.1054692);
   h_Before_stack_1->SetBinError(15,0.08567699);
   h_Before_stack_1->SetBinError(16,0.08827385);
   h_Before_stack_1->SetBinError(17,0.08093223);
   h_Before_stack_1->SetBinError(18,0.07970192);
   h_Before_stack_1->SetBinError(19,0.06657748);
   h_Before_stack_1->SetBinError(20,0.06657748);
   h_Before_stack_1->SetBinError(21,0.07246595);
   h_Before_stack_1->SetBinError(22,0.07029048);
   h_Before_stack_1->SetBinError(23,0.04984468);
   h_Before_stack_1->SetBinError(24,0.06011495);
   h_Before_stack_1->SetBinError(25,0.04477202);
   h_Before_stack_1->SetBinError(26,0.06353975);
   h_Before_stack_1->SetBinError(27,0.05260058);
   h_Before_stack_1->SetBinError(28,0.05040792);
   h_Before_stack_1->SetBinError(29,0.05068719);
   h_Before_stack_1->SetBinError(30,0.04956067);
   h_Before_stack_1->SetBinError(31,0.1410821);
   h_Before_stack_1->SetEntries(9506);
   h_Before_stack_1->SetLineWidth(2);
   h_Before_stack_1->GetXaxis()->SetTitle("True Q^{2} (GeV^{2})");
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
   
   TH1D *h_After_stack_2 = new TH1D("h_After_stack_2"," (passed)",30,0,3);
   h_After_stack_2->SetBinContent(1,0.4197634);
   h_After_stack_2->SetBinContent(2,1.08926);
   h_After_stack_2->SetBinContent(3,1.232723);
   h_After_stack_2->SetBinContent(4,1.694994);
   h_After_stack_2->SetBinContent(5,1.631233);
   h_After_stack_2->SetBinContent(6,2.045683);
   h_After_stack_2->SetBinContent(7,1.753442);
   h_After_stack_2->SetBinContent(8,1.79595);
   h_After_stack_2->SetBinContent(9,1.748129);
   h_After_stack_2->SetBinContent(10,1.705621);
   h_After_stack_2->SetBinContent(11,1.487769);
   h_After_stack_2->SetBinContent(12,1.663113);
   h_After_stack_2->SetBinContent(13,1.39744);
   h_After_stack_2->SetBinContent(14,1.232723);
   h_After_stack_2->SetBinContent(15,0.8660942);
   h_After_stack_2->SetBinContent(16,0.9617365);
   h_After_stack_2->SetBinContent(17,0.7704519);
   h_After_stack_2->SetBinContent(18,0.7173172);
   h_After_stack_2->SetBinContent(19,0.541973);
   h_After_stack_2->SetBinContent(20,0.483525);
   h_After_stack_2->SetBinContent(21,0.6269884);
   h_After_stack_2->SetBinContent(22,0.5526);
   h_After_stack_2->SetBinContent(23,0.3081807);
   h_After_stack_2->SetBinContent(24,0.3985096);
   h_After_stack_2->SetBinContent(25,0.2922404);
   h_After_stack_2->SetBinContent(26,0.4516442);
   h_After_stack_2->SetBinContent(27,0.3134942);
   h_After_stack_2->SetBinContent(28,0.2709865);
   h_After_stack_2->SetBinContent(29,0.2763);
   h_After_stack_2->SetBinContent(30,0.3028673);
   h_After_stack_2->SetBinContent(31,2.306042);
   h_After_stack_2->SetBinError(1,0.04722708);
   h_After_stack_2->SetBinError(2,0.07607718);
   h_After_stack_2->SetBinError(3,0.08093223);
   h_After_stack_2->SetBinError(4,0.09490145);
   h_After_stack_2->SetBinError(5,0.09309936);
   h_After_stack_2->SetBinError(6,0.1042576);
   h_After_stack_2->SetBinError(7,0.09652381);
   h_After_stack_2->SetBinError(8,0.09768679);
   h_After_stack_2->SetBinError(9,0.09637745);
   h_After_stack_2->SetBinError(10,0.09519848);
   h_After_stack_2->SetBinError(11,0.08891121);
   h_After_stack_2->SetBinError(12,0.09400472);
   h_After_stack_2->SetBinError(13,0.08616986);
   h_After_stack_2->SetBinError(14,0.08093223);
   h_After_stack_2->SetBinError(15,0.06783773);
   h_After_stack_2->SetBinError(16,0.07148531);
   h_After_stack_2->SetBinError(17,0.06398254);
   h_After_stack_2->SetBinError(18,0.06173684);
   h_After_stack_2->SetBinError(19,0.05366333);
   h_After_stack_2->SetBinError(20,0.05068719);
   h_After_stack_2->SetBinError(21,0.05771896);
   h_After_stack_2->SetBinError(22,0.05418688);
   h_After_stack_2->SetBinError(23,0.04046611);
   h_After_stack_2->SetBinError(24,0.04601592);
   h_After_stack_2->SetBinError(25,0.03940568);
   h_After_stack_2->SetBinError(26,0.04898769);
   h_After_stack_2->SetBinError(27,0.04081347);
   h_After_stack_2->SetBinError(28,0.0379457);
   h_After_stack_2->SetBinError(29,0.03831591);
   h_After_stack_2->SetBinError(30,0.04011575);
   h_After_stack_2->SetBinError(31,0.1106936);
   h_After_stack_2->SetEntries(5948);
   h_After_stack_2->SetLineColor(3);
   h_After_stack_2->SetLineWidth(2);
   h_After_stack_2->GetXaxis()->SetTitle("True Q^{2} (GeV^{2})");
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
   TGaxis *gaxis = new TGaxis(3,0,3,4.051514,0,0.9850956,510,"+L");
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
   
   Double_t Graph0_fx3001[30] = {
   0.05,
   0.15,
   0.25,
   0.35,
   0.45,
   0.55,
   0.65,
   0.75,
   0.85,
   0.95,
   1.05,
   1.15,
   1.25,
   1.35,
   1.45,
   1.55,
   1.65,
   1.75,
   1.85,
   1.95,
   2.05,
   2.15,
   2.25,
   2.35,
   2.45,
   2.55,
   2.65,
   2.75,
   2.85,
   2.95};
   Double_t Graph0_fy3001[30] = {
   2.800968,
   2.626563,
   2.621353,
   2.672072,
   2.658176,
   2.595792,
   2.449871,
   2.613028,
   2.562719,
   2.593739,
   2.503452,
   2.762469,
   2.533185,
   2.421758,
   2.578418,
   2.697171,
   2.570508,
   2.467688,
   2.672019,
   2.38386,
   2.609204,
   2.444186,
   2.710718,
   2.409852,
   3.185982,
   2.444679,
   2.476081,
   2.330594,
   2.350179,
   2.694602};
   Double_t Graph0_felx3001[30] = {
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
   Double_t Graph0_fely3001[30] = {
   0.1797593,
   0.1105045,
   0.1038106,
   0.08870999,
   0.09037625,
   0.08035627,
   0.08559514,
   0.08588625,
   0.08673021,
   0.08802259,
   0.0935103,
   0.08979096,
   0.09678298,
   0.1017436,
   0.123533,
   0.1180875,
   0.1309091,
   0.1341977,
   0.1573439,
   0.1614839,
   0.1456271,
   0.1524168,
   0.2092865,
   0.1785067,
   0.2108172,
   0.1685636,
   0.2030125,
   0.2132948,
   0.2119945,
   0.210924};
   Double_t Graph0_fehx3001[30] = {
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
   Double_t Graph0_fehy3001[30] = {
   0.1714182,
   0.108175,
   0.1017739,
   0.08706244,
   0.0887118,
   0.07919365,
   0.08466163,
   0.08451115,
   0.08546996,
   0.08663539,
   0.09223375,
   0.08780043,
   0.09531675,
   0.1005264,
   0.1209033,
   0.1150453,
   0.1280091,
   0.1318062,
   0.1522301,
   0.1587646,
   0.1417448,
   0.1495242,
   0.199671,
   0.1749156,
   0.1902796,
   0.1650273,
   0.197466,
   0.2093559,
   0.2078196,
   0.20144};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(30,Graph0_fx3001,Graph0_fy3001,Graph0_felx3001,Graph0_fehx3001,Graph0_fely3001,Graph0_fehy3001);
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
   
   TH1F *Graph_Graph3001 = new TH1F("Graph_Graph3001","Graph",100,0,3.24);
   Graph_Graph3001->SetMinimum(1.991403);
   Graph_Graph3001->SetMaximum(3.502158);
   Graph_Graph3001->SetDirectory(0);
   Graph_Graph3001->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph3001->SetLineColor(ci);
   Graph_Graph3001->GetXaxis()->SetLabelFont(42);
   Graph_Graph3001->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph3001->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph3001->GetXaxis()->SetTitleFont(42);
   Graph_Graph3001->GetYaxis()->SetLabelFont(42);
   Graph_Graph3001->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph3001->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph3001->GetYaxis()->SetTitleOffset(0);
   Graph_Graph3001->GetYaxis()->SetTitleFont(42);
   Graph_Graph3001->GetZaxis()->SetLabelFont(42);
   Graph_Graph3001->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph3001->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph3001->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph3001);
   
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
