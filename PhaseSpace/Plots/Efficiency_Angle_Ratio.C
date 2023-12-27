void Efficiency_Angle_Ratio()
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
   pad1->Range(-20,-4.717695,180,42.45925);
   pad1->SetFillColor(0);
   pad1->SetBorderMode(0);
   pad1->SetBorderSize(2);
   pad1->SetTopMargin(0.01);
   pad1->SetFrameBorderMode(0);
   pad1->SetFrameBorderMode(0);
   
   THStack *hs = new THStack();
   hs->SetName("hs");
   hs->SetTitle("Angle");
   hs->SetMaximum(41.98749);
   
   TH1F *hs_stack_5 = new TH1F("hs_stack_5","Angle",10,0,160);
   hs_stack_5->SetMinimum(0);
   hs_stack_5->SetMaximum(41.98749);
   hs_stack_5->SetDirectory(0);
   hs_stack_5->SetStats(0);

   ci = TColor::GetColor("#000099");
   hs_stack_5->SetLineColor(ci);
   hs_stack_5->GetXaxis()->SetTitle("#theta_{open}");
   hs_stack_5->GetXaxis()->SetLabelFont(42);
   hs_stack_5->GetXaxis()->SetLabelSize(0.045);
   hs_stack_5->GetXaxis()->SetTitleSize(0.05);
   hs_stack_5->GetXaxis()->SetTitleOffset(0.93);
   hs_stack_5->GetXaxis()->SetTitleFont(42);
   hs_stack_5->GetYaxis()->SetTitle(" Entries/bin");
   hs_stack_5->GetYaxis()->SetLabelFont(42);
   hs_stack_5->GetYaxis()->SetLabelSize(0.045);
   hs_stack_5->GetYaxis()->SetTitleSize(0.05);
   hs_stack_5->GetYaxis()->SetTitleOffset(1.06);
   hs_stack_5->GetYaxis()->SetTitleFont(42);
   hs_stack_5->GetZaxis()->SetLabelFont(42);
   hs_stack_5->GetZaxis()->SetLabelSize(0.035);
   hs_stack_5->GetZaxis()->SetTitleSize(0.035);
   hs_stack_5->GetZaxis()->SetTitleFont(42);
   hs->SetHistogram(hs_stack_5);
   
   
   TH1D *h_Before_stack_1 = new TH1D("h_Before_stack_1"," (total)",10,0,160);
   h_Before_stack_1->SetBinContent(1,33.58999);
   h_Before_stack_1->SetBinContent(2,0.5302469);
   h_Before_stack_1->SetBinContent(3,0.9221685);
   h_Before_stack_1->SetBinContent(4,1.060494);
   h_Before_stack_1->SetBinContent(5,1.014385);
   h_Before_stack_1->SetBinContent(6,0.7838432);
   h_Before_stack_1->SetBinContent(7,0.3458132);
   h_Before_stack_1->SetBinContent(8,0.3458132);
   h_Before_stack_1->SetBinContent(9,0.1383253);
   h_Before_stack_1->SetBinContent(10,0.1152711);
   h_Before_stack_1->SetBinContent(11,0.02305421);
   h_Before_stack_1->SetBinError(1,0.8799947);
   h_Before_stack_1->SetBinError(2,0.1105641);
   h_Before_stack_1->SetBinError(3,0.1458076);
   h_Before_stack_1->SetBinError(4,0.1563613);
   h_Before_stack_1->SetBinError(5,0.1529243);
   h_Before_stack_1->SetBinError(6,0.134428);
   h_Before_stack_1->SetBinError(7,0.08928858);
   h_Before_stack_1->SetBinError(8,0.08928858);
   h_Before_stack_1->SetBinError(9,0.05647106);
   h_Before_stack_1->SetBinError(10,0.05155079);
   h_Before_stack_1->SetBinError(11,0.02305421);
   h_Before_stack_1->SetEntries(1686);
   h_Before_stack_1->SetLineWidth(2);
   h_Before_stack_1->GetXaxis()->SetTitle("#theta_{open}");
   h_Before_stack_1->GetXaxis()->SetRange(1,10);
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
   
   TH1D *h_After_stack_2 = new TH1D("h_After_stack_2"," (passed)",10,0,160);
   h_After_stack_2->SetBinContent(1,0.04610843);
   h_After_stack_2->SetBinContent(2,0.5302469);
   h_After_stack_2->SetBinContent(3,0.9221685);
   h_After_stack_2->SetBinContent(4,1.060494);
   h_After_stack_2->SetBinContent(5,1.014385);
   h_After_stack_2->SetBinContent(6,0.7838432);
   h_After_stack_2->SetBinContent(7,0.3458132);
   h_After_stack_2->SetBinContent(8,0.3458132);
   h_After_stack_2->SetBinContent(9,0.1383253);
   h_After_stack_2->SetBinContent(10,0.1152711);
   h_After_stack_2->SetBinContent(11,0.02305421);
   h_After_stack_2->SetBinError(1,0.03260358);
   h_After_stack_2->SetBinError(2,0.1105641);
   h_After_stack_2->SetBinError(3,0.1458076);
   h_After_stack_2->SetBinError(4,0.1563613);
   h_After_stack_2->SetBinError(5,0.1529243);
   h_After_stack_2->SetBinError(6,0.134428);
   h_After_stack_2->SetBinError(7,0.08928858);
   h_After_stack_2->SetBinError(8,0.08928858);
   h_After_stack_2->SetBinError(9,0.05647106);
   h_After_stack_2->SetBinError(10,0.05155079);
   h_After_stack_2->SetBinError(11,0.02305421);
   h_After_stack_2->SetEntries(231);
   h_After_stack_2->SetLineColor(3);
   h_After_stack_2->SetLineWidth(2);
   h_After_stack_2->GetXaxis()->SetTitle("#theta_{open}");
   h_After_stack_2->GetXaxis()->SetRange(1,10);
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
   
   TPaveText *pt = new TPaveText(0.4466583,0.933297,0.5533417,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *pt_LaTex = pt->AddText("Angle");
   pt->Draw();
   TGaxis *gaxis = new TGaxis(160,0,160,41.98749,0,1.2,510,"+L");
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
   
   Double_t Graph0_fx3005[10] = {
   8,
   24,
   40,
   56,
   72,
   88,
   104,
   120,
   136,
   152};
   Double_t Graph0_fy3005[10] = {
   0.04802961,
   34.98957,
   34.98957,
   34.98957,
   34.98957,
   34.98957,
   34.98957,
   34.98957,
   34.98957,
   34.98957};
   Double_t Graph0_felx3005[10] = {
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
   Double_t Graph0_fely3005[10] = {
   0.02714325,
   1.622363,
   0.9590102,
   0.8380623,
   0.87484,
   1.120753,
   2.405114,
   2.405114,
   5.25609,
   6.051897};
   Double_t Graph0_fehx3005[10] = {
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
   Double_t Graph0_fehy3005[10] = {
   0.04414202,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(10,Graph0_fx3005,Graph0_fy3005,Graph0_felx3005,Graph0_fehx3005,Graph0_fely3005,Graph0_fehy3005);
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
   
   TH1F *Graph_Graph3005 = new TH1F("Graph_Graph3005","Graph",100,0,166.4);
   Graph_Graph3005->SetMinimum(0.01879772);
   Graph_Graph3005->SetMaximum(38.48644);
   Graph_Graph3005->SetDirectory(0);
   Graph_Graph3005->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph3005->SetLineColor(ci);
   Graph_Graph3005->GetXaxis()->SetLabelFont(42);
   Graph_Graph3005->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph3005->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph3005->GetXaxis()->SetTitleFont(42);
   Graph_Graph3005->GetYaxis()->SetLabelFont(42);
   Graph_Graph3005->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph3005->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph3005->GetYaxis()->SetTitleOffset(0);
   Graph_Graph3005->GetYaxis()->SetTitleFont(42);
   Graph_Graph3005->GetZaxis()->SetLabelFont(42);
   Graph_Graph3005->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph3005->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph3005->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph3005);
   
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
