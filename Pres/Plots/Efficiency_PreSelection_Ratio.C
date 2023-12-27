void Efficiency_PreSelection_Ratio()
{
//=========Macro generated from canvas: c1/c1
//=========  (Tue Dec  5 07:59:33 2023) by ROOT version 6.12/06
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
   pad1->Range(-1.75,-3.584412,15.75,32.25971);
   pad1->SetFillColor(0);
   pad1->SetBorderMode(0);
   pad1->SetBorderSize(2);
   pad1->SetTopMargin(0.01);
   pad1->SetFrameBorderMode(0);
   pad1->SetFrameBorderMode(0);
   
   THStack *hs = new THStack();
   hs->SetName("hs");
   hs->SetTitle("");
   hs->SetMaximum(31.90127);
   
   TH1F *hs_stack_1 = new TH1F("hs_stack_1","",14,0,14);
   hs_stack_1->SetMinimum(0);
   hs_stack_1->SetMaximum(31.90127);
   hs_stack_1->SetDirectory(0);
   hs_stack_1->SetStats(0);

   ci = TColor::GetColor("#000099");
   hs_stack_1->SetLineColor(ci);
   hs_stack_1->GetXaxis()->SetTitle("Neutrino Energy (GeV)");
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
   
   
   TH1D *h_Before_stack_1 = new TH1D("h_Before_stack_1"," (total)",14,0,14);
   h_Before_stack_1->SetBinContent(1,0.6685722);
   h_Before_stack_1->SetBinContent(2,9.728878);
   h_Before_stack_1->SetBinContent(3,25.52101);
   h_Before_stack_1->SetBinContent(4,24.9216);
   h_Before_stack_1->SetBinContent(5,17.82091);
   h_Before_stack_1->SetBinContent(6,11.43489);
   h_Before_stack_1->SetBinContent(7,5.740499);
   h_Before_stack_1->SetBinContent(8,2.812614);
   h_Before_stack_1->SetBinContent(9,1.406307);
   h_Before_stack_1->SetBinContent(10,0.5302469);
   h_Before_stack_1->SetBinContent(11,0.1383253);
   h_Before_stack_1->SetBinContent(12,0.1152711);
   h_Before_stack_1->SetBinContent(13,0.1844337);
   h_Before_stack_1->SetBinContent(14,0.02305421);
   h_Before_stack_1->SetBinContent(15,0.02305421);
   h_Before_stack_1->SetBinError(1,0.1241507);
   h_Before_stack_1->SetBinError(2,0.4735944);
   h_Before_stack_1->SetBinError(3,0.7670508);
   h_Before_stack_1->SetBinError(4,0.7579894);
   h_Before_stack_1->SetBinError(5,0.6409735);
   h_Before_stack_1->SetBinError(6,0.5134417);
   h_Before_stack_1->SetBinError(7,0.3637893);
   h_Before_stack_1->SetBinError(8,0.2546421);
   h_Before_stack_1->SetBinError(9,0.1800592);
   h_Before_stack_1->SetBinError(10,0.1105641);
   h_Before_stack_1->SetBinError(11,0.05647106);
   h_Before_stack_1->SetBinError(12,0.05155079);
   h_Before_stack_1->SetBinError(13,0.06520716);
   h_Before_stack_1->SetBinError(14,0.02305421);
   h_Before_stack_1->SetBinError(15,0.02305421);
   h_Before_stack_1->SetEntries(4384);
   h_Before_stack_1->SetLineWidth(2);
   h_Before_stack_1->GetXaxis()->SetTitle("Neutrino Energy (GeV)");
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
   
   TH1D *h_After_stack_2 = new TH1D("h_After_stack_2"," (passed)",14,0,14);
   h_After_stack_2->SetBinContent(1,0.1844337);
   h_After_stack_2->SetBinContent(2,2.78956);
   h_After_stack_2->SetBinContent(3,7.723161);
   h_After_stack_2->SetBinContent(4,7.630944);
   h_After_stack_2->SetBinContent(5,5.233306);
   h_After_stack_2->SetBinContent(6,3.757837);
   h_After_stack_2->SetBinContent(7,1.729066);
   h_After_stack_2->SetBinContent(8,0.8068975);
   h_After_stack_2->SetBinContent(9,0.2535963);
   h_After_stack_2->SetBinContent(10,0.1613795);
   h_After_stack_2->SetBinContent(11,0.02305421);
   h_After_stack_2->SetBinContent(12,0.04610843);
   h_After_stack_2->SetBinContent(13,0.02305421);
   h_After_stack_2->SetBinContent(15,0.02305421);
   h_After_stack_2->SetBinError(1,0.06520716);
   h_After_stack_2->SetBinError(2,0.2535963);
   h_After_stack_2->SetBinError(3,0.4219614);
   h_After_stack_2->SetBinError(4,0.4194346);
   h_After_stack_2->SetBinError(5,0.3473467);
   h_After_stack_2->SetBinError(6,0.2943365);
   h_After_stack_2->SetBinError(7,0.1996553);
   h_After_stack_2->SetBinError(8,0.1363906);
   h_After_stack_2->SetBinError(9,0.07646217);
   h_After_stack_2->SetBinError(10,0.06099571);
   h_After_stack_2->SetBinError(11,0.02305421);
   h_After_stack_2->SetBinError(12,0.03260358);
   h_After_stack_2->SetBinError(13,0.02305421);
   h_After_stack_2->SetBinError(15,0.02305421);
   h_After_stack_2->SetEntries(1318);
   h_After_stack_2->SetLineColor(3);
   h_After_stack_2->SetLineWidth(2);
   h_After_stack_2->GetXaxis()->SetTitle("Neutrino Energy (GeV)");
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
   TGaxis *gaxis = new TGaxis(14,0,14,31.90127,0,0.7128541,510,"+L");
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
   
   Double_t Graph0_fx3001[14] = {
   0.5,
   1.5,
   2.5,
   3.5,
   4.5,
   5.5,
   6.5,
   7.5,
   8.5,
   9.5,
   10.5,
   11.5,
   12.5,
   13.5};
   Double_t Graph0_fy3001[14] = {
   12.34523,
   12.83158,
   13.54268,
   13.70281,
   13.14176,
   14.70663,
   13.47936,
   12.83854,
   8.069937,
   13.62001,
   7.458578,
   17.90059,
   5.593934,
   0};
   Double_t Graph0_felx3001[14] = {
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
   Double_t Graph0_fely3001[14] = {
   3.370059,
   0.9627855,
   0.6087134,
   0.6180673,
   0.7202984,
   0.9266843,
   1.265776,
   1.758291,
   2.015205,
   3.8753,
   4.817718,
   7.815008,
   3.729128,
   0};
   Double_t Graph0_fehx3001[14] = {
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
   Double_t Graph0_fehy3001[14] = {
   3.801775,
   0.9924908,
   0.619219,
   0.6286298,
   0.7360159,
   0.9470028,
   1.312572,
   1.859989,
   2.317713,
   4.343046,
   7.53984,
   8.683802,
   6.208159,
   19.43621};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(14,Graph0_fx3001,Graph0_fy3001,Graph0_felx3001,Graph0_fehx3001,Graph0_fely3001,Graph0_fehy3001);
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
   
   TH1F *Graph_Graph3001 = new TH1F("Graph_Graph3001","Graph",100,0,14.8);
   Graph_Graph3001->SetMinimum(0);
   Graph_Graph3001->SetMaximum(29.24283);
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
