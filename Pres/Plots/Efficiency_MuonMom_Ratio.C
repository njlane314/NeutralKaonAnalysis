void Efficiency_MuonMom_Ratio()
{
//=========Macro generated from canvas: c1/c1
//=========  (Sun Nov 19 15:01:36 2023) by ROOT version 6.12/06
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
   pad1->Range(-1.625,-8.204969,14.625,73.84472);
   pad1->SetFillColor(0);
   pad1->SetBorderMode(0);
   pad1->SetBorderSize(2);
   pad1->SetTopMargin(0.01);
   pad1->SetFrameBorderMode(0);
   pad1->SetFrameBorderMode(0);
   
   THStack *hs = new THStack();
   hs->SetName("hs");
   hs->SetTitle("MuonMom");
   hs->SetMaximum(73.02422);
   
   TH1F *hs_stack_3 = new TH1F("hs_stack_3","MuonMom",26,0,13);
   hs_stack_3->SetMinimum(0);
   hs_stack_3->SetMaximum(73.02422);
   hs_stack_3->SetDirectory(0);
   hs_stack_3->SetStats(0);

   ci = TColor::GetColor("#000099");
   hs_stack_3->SetLineColor(ci);
   hs_stack_3->GetXaxis()->SetTitle("True Muon Momentum (GeV/c)");
   hs_stack_3->GetXaxis()->SetLabelFont(42);
   hs_stack_3->GetXaxis()->SetLabelSize(0.045);
   hs_stack_3->GetXaxis()->SetTitleSize(0.05);
   hs_stack_3->GetXaxis()->SetTitleOffset(0.93);
   hs_stack_3->GetXaxis()->SetTitleFont(42);
   hs_stack_3->GetYaxis()->SetTitle(" Entries/bin");
   hs_stack_3->GetYaxis()->SetLabelFont(42);
   hs_stack_3->GetYaxis()->SetLabelSize(0.045);
   hs_stack_3->GetYaxis()->SetTitleSize(0.05);
   hs_stack_3->GetYaxis()->SetTitleOffset(1.06);
   hs_stack_3->GetYaxis()->SetTitleFont(42);
   hs_stack_3->GetZaxis()->SetLabelFont(42);
   hs_stack_3->GetZaxis()->SetLabelSize(0.035);
   hs_stack_3->GetZaxis()->SetTitleSize(0.035);
   hs_stack_3->GetZaxis()->SetTitleFont(42);
   hs->SetHistogram(hs_stack_3);
   
   
   TH1D *h_Before_stack_1 = new TH1D("h_Before_stack_1"," (total)",26,0,13);
   h_Before_stack_1->SetBinContent(1,58.41938);
   h_Before_stack_1->SetBinContent(2,49.08242);
   h_Before_stack_1->SetBinContent(3,33.56693);
   h_Before_stack_1->SetBinContent(4,24.16082);
   h_Before_stack_1->SetBinContent(5,17.19844);
   h_Before_stack_1->SetBinContent(6,12.01124);
   h_Before_stack_1->SetBinContent(7,8.530059);
   h_Before_stack_1->SetBinContent(8,5.279415);
   h_Before_stack_1->SetBinContent(9,3.734783);
   h_Before_stack_1->SetBinContent(10,2.120988);
   h_Before_stack_1->SetBinContent(11,1.521578);
   h_Before_stack_1->SetBinContent(12,1.014385);
   h_Before_stack_1->SetBinContent(13,0.8299517);
   h_Before_stack_1->SetBinContent(14,0.5994095);
   h_Before_stack_1->SetBinContent(15,0.1152711);
   h_Before_stack_1->SetBinContent(16,0.2074879);
   h_Before_stack_1->SetBinContent(17,0.2074879);
   h_Before_stack_1->SetBinContent(18,0.1613795);
   h_Before_stack_1->SetBinContent(19,0.02305421);
   h_Before_stack_1->SetBinContent(21,0.06916264);
   h_Before_stack_1->SetBinContent(22,0.04610843);
   h_Before_stack_1->SetBinContent(23,0.04610843);
   h_Before_stack_1->SetBinContent(26,0.09221685);
   h_Before_stack_1->SetBinError(1,1.160523);
   h_Before_stack_1->SetBinError(2,1.063746);
   h_Before_stack_1->SetBinError(3,0.8796927);
   h_Before_stack_1->SetBinError(4,0.7463301);
   h_Before_stack_1->SetBinError(5,0.6296797);
   h_Before_stack_1->SetBinError(6,0.5262222);
   h_Before_stack_1->SetBinError(7,0.4434566);
   h_Before_stack_1->SetBinError(8,0.3488735);
   h_Before_stack_1->SetBinError(9,0.2934322);
   h_Before_stack_1->SetBinError(10,0.2211282);
   h_Before_stack_1->SetBinError(11,0.1872933);
   h_Before_stack_1->SetBinError(12,0.1529243);
   h_Before_stack_1->SetBinError(13,0.1383253);
   h_Before_stack_1->SetBinError(14,0.1175539);
   h_Before_stack_1->SetBinError(15,0.05155079);
   h_Before_stack_1->SetBinError(16,0.06916264);
   h_Before_stack_1->SetBinError(17,0.06916264);
   h_Before_stack_1->SetBinError(18,0.06099571);
   h_Before_stack_1->SetBinError(19,0.02305421);
   h_Before_stack_1->SetBinError(21,0.03993107);
   h_Before_stack_1->SetBinError(22,0.03260358);
   h_Before_stack_1->SetBinError(23,0.03260358);
   h_Before_stack_1->SetBinError(26,0.04610843);
   h_Before_stack_1->SetEntries(9501);
   h_Before_stack_1->SetLineWidth(2);
   h_Before_stack_1->GetXaxis()->SetTitle("True Muon Momentum (GeV/c)");
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
   
   TH1D *h_After_stack_2 = new TH1D("h_After_stack_2"," (passed)",26,0,13);
   h_After_stack_2->SetBinContent(1,8.276462);
   h_After_stack_2->SetBinContent(2,8.022866);
   h_After_stack_2->SetBinContent(3,4.703059);
   h_After_stack_2->SetBinContent(4,3.458132);
   h_After_stack_2->SetBinContent(5,2.881777);
   h_After_stack_2->SetBinContent(6,1.75212);
   h_After_stack_2->SetBinContent(7,1.682958);
   h_After_stack_2->SetBinContent(8,1.060494);
   h_After_stack_2->SetBinContent(9,0.760789);
   h_After_stack_2->SetBinContent(10,0.3688674);
   h_After_stack_2->SetBinContent(11,0.2074879);
   h_After_stack_2->SetBinContent(12,0.09221685);
   h_After_stack_2->SetBinContent(13,0.09221685);
   h_After_stack_2->SetBinContent(14,0.06916264);
   h_After_stack_2->SetBinContent(16,0.02305421);
   h_After_stack_2->SetBinContent(17,0.04610843);
   h_After_stack_2->SetBinContent(19,0.02305421);
   h_After_stack_2->SetBinContent(23,0.02305421);
   h_After_stack_2->SetBinError(1,0.436815);
   h_After_stack_2->SetBinError(2,0.4300708);
   h_After_stack_2->SetBinError(3,0.32928);
   h_After_stack_2->SetBinError(4,0.2823553);
   h_After_stack_2->SetBinError(5,0.2577539);
   h_After_stack_2->SetBinError(6,0.200982);
   h_After_stack_2->SetBinError(7,0.1969753);
   h_After_stack_2->SetBinError(8,0.1563613);
   h_After_stack_2->SetBinError(9,0.1324364);
   h_After_stack_2->SetBinError(10,0.09221685);
   h_After_stack_2->SetBinError(11,0.06916264);
   h_After_stack_2->SetBinError(12,0.04610843);
   h_After_stack_2->SetBinError(13,0.04610843);
   h_After_stack_2->SetBinError(14,0.03993107);
   h_After_stack_2->SetBinError(16,0.02305421);
   h_After_stack_2->SetBinError(17,0.03260358);
   h_After_stack_2->SetBinError(19,0.02305421);
   h_After_stack_2->SetBinError(23,0.02305421);
   h_After_stack_2->SetEntries(1455);
   h_After_stack_2->SetLineColor(3);
   h_After_stack_2->SetLineWidth(2);
   h_After_stack_2->GetXaxis()->SetTitle("True Muon Momentum (GeV/c)");
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
   
   TPaveText *pt = new TPaveText(0.4121106,0.94,0.5878894,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *pt_LaTex = pt->AddText("MuonMom");
   pt->Draw();
   TGaxis *gaxis = new TGaxis(13,0,13,73.02422,0,1.2,510,"+L");
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
   
   Double_t Graph0_fx3003[23] = {
   0.25,
   0.75,
   1.25,
   1.75,
   2.25,
   2.75,
   3.25,
   3.75,
   4.25,
   4.75,
   5.25,
   5.75,
   6.25,
   6.75,
   7.25,
   7.75,
   8.25,
   8.75,
   9.25,
   10.25,
   10.75,
   11.25,
   12.75};
   Double_t Graph0_fy3003[23] = {
   8.621315,
   9.946934,
   8.526179,
   8.70995,
   10.19663,
   8.876904,
   12.00623,
   12.22385,
   12.39609,
   10.58322,
   8.298206,
   5.532138,
   6.761502,
   7.021559,
   0,
   6.761502,
   13.523,
   0,
   60.85351,
   0,
   0,
   30.42676,
   0};
   Double_t Graph0_felx3003[23] = {
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
   Double_t Graph0_fely3003[23] = {
   0.4134591,
   0.4785053,
   0.5403815,
   0.6406752,
   0.8089306,
   0.9076452,
   1.21682,
   1.544931,
   1.833323,
   2.234129,
   2.319977,
   2.248838,
   2.719532,
   3.169164,
   0,
   4.554405,
   6.677323,
   0,
   26.42957,
   0,
   0,
   15.01142,
   0};
   Double_t Graph0_fehx3003[23] = {
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
   Double_t Graph0_fehy3003[23] = {
   0.4248001,
   0.491182,
   0.5601997,
   0.6679693,
   0.8446261,
   0.9620639,
   1.282213,
   1.649086,
   1.978775,
   2.514487,
   2.75493,
   2.986287,
   3.56711,
   4.318154,
   10.5254,
   7.744633,
   8.802703,
   8.078372,
   0,
   15.08433,
   19.2303,
   15.01142,
   12.40107};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(23,Graph0_fx3003,Graph0_fy3003,Graph0_felx3003,Graph0_fehx3003,Graph0_fely3003,Graph0_fehy3003);
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
   
   TH1F *Graph_Graph3003 = new TH1F("Graph_Graph3003","Graph",100,0,14);
   Graph_Graph3003->SetMinimum(0);
   Graph_Graph3003->SetMaximum(66.93887);
   Graph_Graph3003->SetDirectory(0);
   Graph_Graph3003->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph3003->SetLineColor(ci);
   Graph_Graph3003->GetXaxis()->SetLabelFont(42);
   Graph_Graph3003->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph3003->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph3003->GetXaxis()->SetTitleFont(42);
   Graph_Graph3003->GetYaxis()->SetLabelFont(42);
   Graph_Graph3003->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph3003->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph3003->GetYaxis()->SetTitleOffset(0);
   Graph_Graph3003->GetYaxis()->SetTitleFont(42);
   Graph_Graph3003->GetZaxis()->SetLabelFont(42);
   Graph_Graph3003->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph3003->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph3003->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph3003);
   
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
