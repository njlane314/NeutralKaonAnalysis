void Efficiency_MuonKE_Ratio()
{
//=========Macro generated from canvas: c1/c1
//=========  (Thu Nov 23 05:52:21 2023) by ROOT version 6.12/06
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
   pad1->Range(-1.625,-1.797063,14.625,16.17357);
   pad1->SetFillColor(0);
   pad1->SetBorderMode(0);
   pad1->SetBorderSize(2);
   pad1->SetTopMargin(0.01);
   pad1->SetFrameBorderMode(0);
   pad1->SetFrameBorderMode(0);
   
   THStack *hs = new THStack();
   hs->SetName("hs");
   hs->SetTitle("MuonKE");
   hs->SetMaximum(15.99386);
   
   TH1F *hs_stack_3 = new TH1F("hs_stack_3","MuonKE",26,0,13);
   hs_stack_3->SetMinimum(0);
   hs_stack_3->SetMaximum(15.99386);
   hs_stack_3->SetDirectory(0);
   hs_stack_3->SetStats(0);

   ci = TColor::GetColor("#000099");
   hs_stack_3->SetLineColor(ci);
   hs_stack_3->GetXaxis()->SetTitle("True Muon Kinetic Energy (GeV)");
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
   h_Before_stack_1->SetBinContent(1,12.79509);
   h_Before_stack_1->SetBinContent(2,8.576167);
   h_Before_stack_1->SetBinContent(3,4.587788);
   h_Before_stack_1->SetBinContent(4,4.288084);
   h_Before_stack_1->SetBinContent(5,2.904831);
   h_Before_stack_1->SetBinContent(6,1.9135);
   h_Before_stack_1->SetBinContent(7,1.47547);
   h_Before_stack_1->SetBinContent(8,1.014385);
   h_Before_stack_1->SetBinContent(9,0.5071927);
   h_Before_stack_1->SetBinContent(10,0.1613795);
   h_Before_stack_1->SetBinContent(11,0.2074879);
   h_Before_stack_1->SetBinContent(12,0.1383253);
   h_Before_stack_1->SetBinContent(13,0.06916264);
   h_Before_stack_1->SetBinContent(14,0.1383253);
   h_Before_stack_1->SetBinContent(15,0.06916264);
   h_Before_stack_1->SetBinContent(16,0.02305421);
   h_Before_stack_1->SetBinError(1,0.5431212);
   h_Before_stack_1->SetBinError(2,0.4446536);
   h_Before_stack_1->SetBinError(3,0.3252197);
   h_Before_stack_1->SetBinError(4,0.3144175);
   h_Before_stack_1->SetBinError(5,0.2587829);
   h_Before_stack_1->SetBinError(6,0.2100339);
   h_Before_stack_1->SetBinError(7,0.1844337);
   h_Before_stack_1->SetBinError(8,0.1529243);
   h_Before_stack_1->SetBinError(9,0.1081338);
   h_Before_stack_1->SetBinError(10,0.06099571);
   h_Before_stack_1->SetBinError(11,0.06916264);
   h_Before_stack_1->SetBinError(12,0.05647106);
   h_Before_stack_1->SetBinError(13,0.03993107);
   h_Before_stack_1->SetBinError(14,0.05647106);
   h_Before_stack_1->SetBinError(15,0.03993107);
   h_Before_stack_1->SetBinError(16,0.02305421);
   h_Before_stack_1->SetEntries(1686);
   h_Before_stack_1->SetLineWidth(2);
   h_Before_stack_1->GetXaxis()->SetTitle("True Muon Kinetic Energy (GeV)");
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
   h_After_stack_2->SetBinContent(1,5.025818);
   h_After_stack_2->SetBinContent(2,3.06621);
   h_After_stack_2->SetBinContent(3,1.47547);
   h_After_stack_2->SetBinContent(4,1.729066);
   h_After_stack_2->SetBinContent(5,0.8760601);
   h_After_stack_2->SetBinContent(6,0.6916264);
   h_After_stack_2->SetBinContent(7,0.5071927);
   h_After_stack_2->SetBinContent(8,0.5763553);
   h_After_stack_2->SetBinContent(9,0.2074879);
   h_After_stack_2->SetBinContent(10,0.09221685);
   h_After_stack_2->SetBinContent(11,0.1152711);
   h_After_stack_2->SetBinContent(12,0.02305421);
   h_After_stack_2->SetBinContent(13,0.02305421);
   h_After_stack_2->SetBinContent(14,0.06916264);
   h_After_stack_2->SetBinError(1,0.3403914);
   h_After_stack_2->SetBinError(2,0.2658742);
   h_After_stack_2->SetBinError(3,0.1844337);
   h_After_stack_2->SetBinError(4,0.1996553);
   h_After_stack_2->SetBinError(5,0.1421157);
   h_After_stack_2->SetBinError(6,0.1262731);
   h_After_stack_2->SetBinError(7,0.1081338);
   h_After_stack_2->SetBinError(8,0.1152711);
   h_After_stack_2->SetBinError(9,0.06916264);
   h_After_stack_2->SetBinError(10,0.04610843);
   h_After_stack_2->SetBinError(11,0.05155079);
   h_After_stack_2->SetBinError(12,0.02305421);
   h_After_stack_2->SetBinError(13,0.02305421);
   h_After_stack_2->SetBinError(14,0.03993107);
   h_After_stack_2->SetEntries(628);
   h_After_stack_2->SetLineColor(3);
   h_After_stack_2->SetLineWidth(2);
   h_After_stack_2->GetXaxis()->SetTitle("True Muon Kinetic Energy (GeV)");
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
   
   TPaveText *pt = new TPaveText(0.4265578,0.94,0.5734422,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *pt_LaTex = pt->AddText("MuonKE");
   pt->Draw();
   TGaxis *gaxis = new TGaxis(13,0,13,15.99386,0,0.8761357,510,"+L");
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
   
   Double_t Graph0_fx3003[16] = {
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
   7.75};
   Double_t Graph0_fy3003[16] = {
   7.170434,
   6.526654,
   5.870956,
   7.360888,
   5.505477,
   6.598194,
   6.275157,
   10.37216,
   7.467956,
   10.43143,
   10.14167,
   3.042501,
   6.085001,
   9.127502,
   0,
   0};
   Double_t Graph0_felx3003[16] = {
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
   Double_t Graph0_fely3003[16] = {
   0.3733552,
   0.4453605,
   0.5876035,
   0.6433487,
   0.718211,
   0.92673,
   1.03353,
   1.34399,
   1.776973,
   3.092082,
   2.781103,
   1.965242,
   3.443972,
   3.203724,
   0,
   0};
   Double_t Graph0_fehx3003[16] = {
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
   Double_t Graph0_fehy3003[16] = {
   0.3779901,
   0.4545365,
   0.6089981,
   0.6557543,
   0.7556169,
   0.9660844,
   1.09075,
   1.308148,
   1.868986,
   2.896787,
   2.657355,
   3.075649,
   4.293519,
   3.203724,
   4.525039,
   7.928414};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(16,Graph0_fx3003,Graph0_fy3003,Graph0_felx3003,Graph0_fehx3003,Graph0_fely3003,Graph0_fehy3003);
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
   
   TH1F *Graph_Graph3003 = new TH1F("Graph_Graph3003","Graph",100,0,8.5);
   Graph_Graph3003->SetMinimum(0);
   Graph_Graph3003->SetMaximum(14.66104);
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
