void Efficiency_MuonIdentifier_Ratio()
{
//=========Macro generated from canvas: c1/c1
//=========  (Wed Dec  6 06:26:48 2023) by ROOT version 6.12/06
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
   pad1->Range(-0.25,-3.246585,2.25,29.21926);
   pad1->SetFillColor(0);
   pad1->SetBorderMode(0);
   pad1->SetBorderSize(2);
   pad1->SetTopMargin(0.01);
   pad1->SetFrameBorderMode(0);
   pad1->SetFrameBorderMode(0);
   
   THStack *hs = new THStack();
   hs->SetName("hs");
   hs->SetTitle("");
   hs->SetMaximum(28.8946);
   
   TH1F *hs_stack_1 = new TH1F("hs_stack_1","",20,0,2);
   hs_stack_1->SetMinimum(0);
   hs_stack_1->SetMaximum(28.8946);
   hs_stack_1->SetDirectory(0);
   hs_stack_1->SetStats(0);

   ci = TColor::GetColor("#000099");
   hs_stack_1->SetLineColor(ci);
   hs_stack_1->GetXaxis()->SetTitle("Muon Momentum (GeV/c)");
   hs_stack_1->GetXaxis()->SetLabelFont(42);
   hs_stack_1->GetXaxis()->SetLabelSize(0.045);
   hs_stack_1->GetXaxis()->SetTitleSize(0.05);
   hs_stack_1->GetXaxis()->SetTitleOffset(0.93);
   hs_stack_1->GetXaxis()->SetTitleFont(42);
   hs_stack_1->GetYaxis()->SetTitle(" Entries/bin");
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
   
   
   TH1D *h_Before_stack_1 = new TH1D("h_Before_stack_1"," (total)",20,0,2);
   h_Before_stack_1->SetBinContent(2,8.777838);
   h_Before_stack_1->SetBinContent(3,23.11568);
   h_Before_stack_1->SetBinContent(4,21.34736);
   h_Before_stack_1->SetBinContent(5,15.75335);
   h_Before_stack_1->SetBinContent(6,10.30811);
   h_Before_stack_1->SetBinContent(7,6.609946);
   h_Before_stack_1->SetBinContent(8,5.08817);
   h_Before_stack_1->SetBinContent(9,2.903275);
   h_Before_stack_1->SetBinContent(10,2.673734);
   h_Before_stack_1->SetBinContent(11,1.853335);
   h_Before_stack_1->SetBinContent(12,1.313488);
   h_Before_stack_1->SetBinContent(13,0.6843738);
   h_Before_stack_1->SetBinContent(14,0.5270953);
   h_Before_stack_1->SetBinContent(15,0.5355969);
   h_Before_stack_1->SetBinContent(16,0.3528138);
   h_Before_stack_1->SetBinContent(17,0.1742815);
   h_Before_stack_1->SetBinContent(18,0.05951076);
   h_Before_stack_1->SetBinContent(19,0.0680123);
   h_Before_stack_1->SetBinContent(20,0.11052);
   h_Before_stack_1->SetBinContent(21,0.1360246);
   h_Before_stack_1->SetBinError(2,0.1931646);
   h_Before_stack_1->SetBinError(3,0.3134636);
   h_Before_stack_1->SetBinError(4,0.3012353);
   h_Before_stack_1->SetBinError(5,0.2587737);
   h_Before_stack_1->SetBinError(6,0.2093261);
   h_Before_stack_1->SetBinError(7,0.1676226);
   h_Before_stack_1->SetBinError(8,0.1470668);
   h_Before_stack_1->SetBinError(9,0.1110907);
   h_Before_stack_1->SetBinError(10,0.1066087);
   h_Before_stack_1->SetBinError(11,0.08875866);
   h_Before_stack_1->SetBinError(12,0.0747217);
   h_Before_stack_1->SetBinError(13,0.05393621);
   h_Before_stack_1->SetBinError(14,0.04733456);
   h_Before_stack_1->SetBinError(15,0.04771476);
   h_Before_stack_1->SetBinError(16,0.03872635);
   h_Before_stack_1->SetBinError(17,0.0272182);
   h_Before_stack_1->SetBinError(18,0.01590492);
   h_Before_stack_1->SetBinError(19,0.01700308);
   h_Before_stack_1->SetBinError(20,0.02167475);
   h_Before_stack_1->SetBinError(21,0.02404598);
   h_Before_stack_1->SetEntries(24088);
   h_Before_stack_1->SetLineWidth(2);
   h_Before_stack_1->GetXaxis()->SetTitle("Muon Momentum (GeV/c)");
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
   
   TH1D *h_After_stack_2 = new TH1D("h_After_stack_2"," (passed)",20,0,2);
   h_After_stack_2->SetBinContent(2,4.80762);
   h_After_stack_2->SetBinContent(3,12.78631);
   h_After_stack_2->SetBinContent(4,11.8979);
   h_After_stack_2->SetBinContent(5,8.752333);
   h_After_stack_2->SetBinContent(6,5.708783);
   h_After_stack_2->SetBinContent(7,3.740677);
   h_After_stack_2->SetBinContent(8,2.750247);
   h_After_stack_2->SetBinContent(9,1.679054);
   h_After_stack_2->SetBinContent(10,1.500521);
   h_After_stack_2->SetBinContent(11,1.100949);
   h_After_stack_2->SetBinContent(12,0.7693892);
   h_After_stack_2->SetBinContent(13,0.4123246);
   h_After_stack_2->SetBinContent(14,0.3103061);
   h_After_stack_2->SetBinContent(15,0.2592969);
   h_After_stack_2->SetBinContent(16,0.1827831);
   h_After_stack_2->SetBinContent(17,0.09776768);
   h_After_stack_2->SetBinContent(18,0.04250769);
   h_After_stack_2->SetBinContent(19,0.03400615);
   h_After_stack_2->SetBinContent(20,0.04250769);
   h_After_stack_2->SetBinContent(21,0.08076461);
   h_After_stack_2->SetBinError(2,0.1429548);
   h_After_stack_2->SetBinError(3,0.2331344);
   h_After_stack_2->SetBinError(4,0.2248894);
   h_After_stack_2->SetBinError(5,0.1928838);
   h_After_stack_2->SetBinError(6,0.1557778);
   h_After_stack_2->SetBinError(7,0.1260982);
   h_After_stack_2->SetBinError(8,0.1081234);
   h_After_stack_2->SetBinError(9,0.08448236);
   h_After_stack_2->SetBinError(10,0.0798647);
   h_After_stack_2->SetBinError(11,0.06840965);
   h_After_stack_2->SetBinError(12,0.05718825);
   h_After_stack_2->SetBinError(13,0.04186522);
   h_After_stack_2->SetBinError(14,0.03631859);
   h_After_stack_2->SetBinError(15,0.03319957);
   h_After_stack_2->SetBinError(16,0.02787416);
   h_After_stack_2->SetBinError(17,0.02038597);
   h_After_stack_2->SetBinError(18,0.01344211);
   h_After_stack_2->SetBinError(19,0.01202299);
   h_After_stack_2->SetBinError(20,0.01344211);
   h_After_stack_2->SetBinError(21,0.01852867);
   h_After_stack_2->SetEntries(13399);
   h_After_stack_2->SetLineColor(3);
   h_After_stack_2->SetLineWidth(2);
   h_After_stack_2->GetXaxis()->SetTitle("Muon Momentum (GeV/c)");
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
   TGaxis *gaxis = new TGaxis(2,0,2,28.8946,0,0.9819786,510,"+L");
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
   
   Double_t Graph0_fx3001[19] = {
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
   1.95};
   Double_t Graph0_fy3001[19] = {
   16.116,
   16.27621,
   16.39989,
   16.34804,
   16.29592,
   16.65202,
   15.90468,
   17.01732,
   16.51349,
   17.47946,
   17.23593,
   17.72803,
   17.32271,
   14.24538,
   15.24421,
   16.50664,
   21.01777,
   14.71244,
   11.31726};
   Double_t Graph0_felx3001[19] = {
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
   Double_t Graph0_fely3001[19] = {
   0.3207921,
   0.197434,
   0.205277,
   0.2390729,
   0.2956923,
   0.3683764,
   0.4218019,
   0.5543456,
   0.5799572,
   0.6908129,
   0.8227425,
   1.134013,
   1.296595,
   1.290163,
   1.590077,
   2.242532,
   3.592297,
   3.447712,
   2.612111};
   Double_t Graph0_fehx3001[19] = {
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
   Double_t Graph0_fehy3001[19] = {
   0.3198965,
   0.1970552,
   0.204834,
   0.2384913,
   0.2948317,
   0.3667339,
   0.4204904,
   0.5499074,
   0.5761924,
   0.6824784,
   0.8120357,
   1.109584,
   1.26923,
   1.294981,
   1.581808,
   2.187245,
   3.061064,
   3.447712,
   2.773344};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(19,Graph0_fx3001,Graph0_fy3001,Graph0_felx3001,Graph0_fehx3001,Graph0_fely3001,Graph0_fehy3001);
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
   
   TH1F *Graph_Graph3001 = new TH1F("Graph_Graph3001","Graph",100,0,2.13);
   Graph_Graph3001->SetMinimum(7.167782);
   Graph_Graph3001->SetMaximum(25.6162);
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
   entry=leg->AddEntry("NULL","NuMI FHC, 10.0 #times 10^{20} POT","h");
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
