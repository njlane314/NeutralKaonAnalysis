void Efficiency_Muon_Ratio()
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
   pad1->Range(-1.25,-7.809939,11.25,70.28945);
   pad1->SetFillColor(0);
   pad1->SetBorderMode(0);
   pad1->SetBorderSize(2);
   pad1->SetTopMargin(0.01);
   pad1->SetFrameBorderMode(0);
   pad1->SetFrameBorderMode(0);
   
   THStack *hs = new THStack();
   hs->SetName("hs");
   hs->SetTitle("Muon");
   hs->SetMaximum(69.50845);
   
   TH1F *hs_stack_2 = new TH1F("hs_stack_2","Muon",10,0,10);
   hs_stack_2->SetMinimum(0);
   hs_stack_2->SetMaximum(69.50845);
   hs_stack_2->SetDirectory(0);
   hs_stack_2->SetStats(0);

   ci = TColor::GetColor("#000099");
   hs_stack_2->SetLineColor(ci);
   hs_stack_2->GetXaxis()->SetTitle("Neutrino Energy (GeV)");
   hs_stack_2->GetXaxis()->SetLabelFont(42);
   hs_stack_2->GetXaxis()->SetLabelSize(0.045);
   hs_stack_2->GetXaxis()->SetTitleSize(0.05);
   hs_stack_2->GetXaxis()->SetTitleOffset(0.93);
   hs_stack_2->GetXaxis()->SetTitleFont(42);
   hs_stack_2->GetYaxis()->SetTitle(" Entries/bin");
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
   
   
   TH1D *h_Before_stack_1 = new TH1D("h_Before_stack_1"," (total)",10,0,10);
   h_Before_stack_1->SetBinContent(1,1.844337);
   h_Before_stack_1->SetBinContent(2,14.8008);
   h_Before_stack_1->SetBinContent(3,51.61838);
   h_Before_stack_1->SetBinContent(4,55.60676);
   h_Before_stack_1->SetBinContent(5,40.06822);
   h_Before_stack_1->SetBinContent(6,26.44318);
   h_Before_stack_1->SetBinContent(7,14.82386);
   h_Before_stack_1->SetBinContent(8,7.700107);
   h_Before_stack_1->SetBinContent(9,3.342861);
   h_Before_stack_1->SetBinContent(10,1.198819);
   h_Before_stack_1->SetBinContent(11,1.590741);
   h_Before_stack_1->SetBinError(1,0.2062031);
   h_Before_stack_1->SetBinError(2,0.5841412);
   h_Before_stack_1->SetBinError(3,1.090881);
   h_Before_stack_1->SetBinError(4,1.132241);
   h_Before_stack_1->SetBinError(5,0.9611146);
   h_Before_stack_1->SetBinError(6,0.780786);
   h_Before_stack_1->SetBinError(7,0.5845959);
   h_Before_stack_1->SetBinError(8,0.4213311);
   h_Before_stack_1->SetBinError(9,0.2776095);
   h_Before_stack_1->SetBinError(10,0.1662463);
   h_Before_stack_1->SetBinError(11,0.1915027);
   h_Before_stack_1->SetEntries(9501);
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
   
   TH1D *h_After_stack_2 = new TH1D("h_After_stack_2"," (passed)",10,0,10);
   h_After_stack_2->SetBinContent(1,0.3688674);
   h_After_stack_2->SetBinContent(2,2.120988);
   h_After_stack_2->SetBinContent(3,7.884541);
   h_After_stack_2->SetBinContent(4,8.945035);
   h_After_stack_2->SetBinContent(5,5.85577);
   h_After_stack_2->SetBinContent(6,4.518626);
   h_After_stack_2->SetBinContent(7,2.120988);
   h_After_stack_2->SetBinContent(8,1.03744);
   h_After_stack_2->SetBinContent(9,0.3919216);
   h_After_stack_2->SetBinContent(10,0.1152711);
   h_After_stack_2->SetBinContent(11,0.1844337);
   h_After_stack_2->SetBinError(1,0.09221685);
   h_After_stack_2->SetBinError(2,0.2211282);
   h_After_stack_2->SetBinError(3,0.4263471);
   h_After_stack_2->SetBinError(4,0.4541153);
   h_After_stack_2->SetBinError(5,0.3674237);
   h_After_stack_2->SetBinError(6,0.322759);
   h_After_stack_2->SetBinError(7,0.2211282);
   h_After_stack_2->SetBinError(8,0.1546524);
   h_After_stack_2->SetBinError(9,0.09505496);
   h_After_stack_2->SetBinError(10,0.05155079);
   h_After_stack_2->SetBinError(11,0.06520716);
   h_After_stack_2->SetEntries(1455);
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
   
   TPaveText *pt = new TPaveText(0.4485427,0.94,0.5514573,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *pt_LaTex = pt->AddText("Muon");
   pt->Draw();
   TGaxis *gaxis = new TGaxis(10,0,10,69.50845,0,0.2957924,510,"+L");
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
   
   Double_t Graph0_fx3002[10] = {
   0.5,
   1.5,
   2.5,
   3.5,
   4.5,
   5.5,
   6.5,
   7.5,
   8.5,
   9.5};
   Double_t Graph0_fy3002[10] = {
   46.99814,
   33.67468,
   35.89407,
   37.80116,
   34.34271,
   40.15534,
   33.62231,
   31.66042,
   27.55063,
   22.59526};
   Double_t Graph0_felx3002[10] = {
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
   Double_t Graph0_fely3002[10] = {
   9.784168,
   3.142916,
   1.752175,
   1.725984,
   1.94799,
   2.551336,
   3.138404,
   4.19063,
   5.821185,
   8.336047};
   Double_t Graph0_fehx3002[10] = {
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
   Double_t Graph0_fehy3002[10] = {
   10.92557,
   3.314766,
   1.800205,
   1.769528,
   2.011035,
   2.640144,
   3.310094,
   4.528402,
   6.63403,
   10.71468};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(10,Graph0_fx3002,Graph0_fy3002,Graph0_felx3002,Graph0_fehx3002,Graph0_fely3002,Graph0_fehy3002);
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
   
   TH1F *Graph_Graph3002 = new TH1F("Graph_Graph3002","Graph",100,0,10.4);
   Graph_Graph3002->SetMinimum(9.892761);
   Graph_Graph3002->SetMaximum(62.29016);
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
