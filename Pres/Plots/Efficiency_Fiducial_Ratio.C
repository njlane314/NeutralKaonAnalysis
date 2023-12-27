void Efficiency_Fiducial_Ratio()
{
//=========Macro generated from canvas: c1/c1
//=========  (Wed Nov 29 08:56:46 2023) by ROOT version 6.12/06
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
   pad1->Range(-125,-1.518599,1125,13.66739);
   pad1->SetFillColor(0);
   pad1->SetBorderMode(0);
   pad1->SetBorderSize(2);
   pad1->SetTopMargin(0.01);
   pad1->SetFrameBorderMode(0);
   pad1->SetFrameBorderMode(0);
   
   THStack *hs = new THStack();
   hs->SetName("hs");
   hs->SetTitle("Fiducial");
   hs->SetMaximum(13.51553);
   
   TH1F *hs_stack_1 = new TH1F("hs_stack_1","Fiducial",12,0,1000);
   hs_stack_1->SetMinimum(0);
   hs_stack_1->SetMaximum(13.51553);
   hs_stack_1->SetDirectory(0);
   hs_stack_1->SetStats(0);

   ci = TColor::GetColor("#000099");
   hs_stack_1->SetLineColor(ci);
   hs_stack_1->GetXaxis()->SetTitle("Neutrino Interaction Vertex (cm)");
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
   
   
   TH1D *h_Before_stack_1 = new TH1D("h_Before_stack_1"," (total)",12,0,1000);
   h_Before_stack_1->SetBinContent(0,0.06916264);
   h_Before_stack_1->SetBinContent(1,4.680005);
   h_Before_stack_1->SetBinContent(2,8.829764);
   h_Before_stack_1->SetBinContent(3,9.544444);
   h_Before_stack_1->SetBinContent(4,9.429173);
   h_Before_stack_1->SetBinContent(5,9.475282);
   h_Before_stack_1->SetBinContent(6,10.69715);
   h_Before_stack_1->SetBinContent(7,9.52139);
   h_Before_stack_1->SetBinContent(8,10.14385);
   h_Before_stack_1->SetBinContent(9,0.9913312);
   h_Before_stack_1->SetBinContent(10,6.939318);
   h_Before_stack_1->SetBinContent(11,10.81243);
   h_Before_stack_1->SetBinContent(12,9.821095);
   h_Before_stack_1->SetBinContent(13,0.1152711);
   h_Before_stack_1->SetBinError(0,0.03993107);
   h_Before_stack_1->SetBinError(1,0.328472);
   h_Before_stack_1->SetBinError(2,0.4511798);
   h_Before_stack_1->SetBinError(3,0.4690838);
   h_Before_stack_1->SetBinError(4,0.4662426);
   h_Before_stack_1->SetBinError(5,0.4673812);
   h_Before_stack_1->SetBinError(6,0.4966029);
   h_Before_stack_1->SetBinError(7,0.468517);
   h_Before_stack_1->SetBinError(8,0.4835893);
   h_Before_stack_1->SetBinError(9,0.1511766);
   h_Before_stack_1->SetBinError(10,0.3999756);
   h_Before_stack_1->SetBinError(11,0.4992714);
   h_Before_stack_1->SetBinError(12,0.4758336);
   h_Before_stack_1->SetBinError(13,0.05155079);
   h_Before_stack_1->SetEntries(4384);
   h_Before_stack_1->SetLineWidth(2);
   h_Before_stack_1->GetXaxis()->SetTitle("Neutrino Interaction Vertex (cm)");
   h_Before_stack_1->GetXaxis()->SetRange(1,12);
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
   
   TH1D *h_After_stack_2 = new TH1D("h_After_stack_2"," (passed)",12,0,1000);
   h_After_stack_2->SetBinContent(0,0.02305421);
   h_After_stack_2->SetBinContent(1,3.688674);
   h_After_stack_2->SetBinContent(2,6.962372);
   h_After_stack_2->SetBinContent(3,7.469565);
   h_After_stack_2->SetBinContent(4,7.861487);
   h_After_stack_2->SetBinContent(5,8.322571);
   h_After_stack_2->SetBinContent(6,9.336956);
   h_After_stack_2->SetBinContent(7,8.2073);
   h_After_stack_2->SetBinContent(8,8.945035);
   h_After_stack_2->SetBinContent(9,0.645518);
   h_After_stack_2->SetBinContent(10,5.486903);
   h_After_stack_2->SetBinContent(11,8.576167);
   h_After_stack_2->SetBinContent(12,7.215969);
   h_After_stack_2->SetBinContent(13,0.09221685);
   h_After_stack_2->SetBinError(0,0.02305421);
   h_After_stack_2->SetBinError(1,0.2916153);
   h_After_stack_2->SetBinError(2,0.4006395);
   h_After_stack_2->SetBinError(3,0.4149758);
   h_After_stack_2->SetBinError(4,0.4257234);
   h_After_stack_2->SetBinError(5,0.43803);
   h_After_stack_2->SetBinError(6,0.4639571);
   h_After_stack_2->SetBinError(7,0.434986);
   h_After_stack_2->SetBinError(8,0.4541153);
   h_After_stack_2->SetBinError(9,0.1219914);
   h_After_stack_2->SetBinError(10,0.3556631);
   h_After_stack_2->SetBinError(11,0.4446536);
   h_After_stack_2->SetBinError(12,0.4078707);
   h_After_stack_2->SetBinError(13,0.04610843);
   h_After_stack_2->SetEntries(3593);
   h_After_stack_2->SetLineColor(3);
   h_After_stack_2->SetLineWidth(2);
   h_After_stack_2->GetXaxis()->SetTitle("Neutrino Interaction Vertex (cm)");
   h_After_stack_2->GetXaxis()->SetRange(1,12);
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
   
   TPaveText *pt = new TPaveText(0.4315829,0.94,0.5684171,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *pt_LaTex = pt->AddText("Fiducial");
   pt->Draw();
   TGaxis *gaxis = new TGaxis(1000,0,1000,13.51553,0,1.075847,510,"+L");
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
   
   Double_t Graph0_fx3001[12] = {
   41.66667,
   125,
   208.3333,
   291.6667,
   375,
   458.3333,
   541.6667,
   625,
   708.3333,
   791.6667,
   875,
   958.3333};
   Double_t Graph0_fy3001[12] = {
   9.901631,
   9.905832,
   9.831673,
   10.47403,
   11.03439,
   10.96528,
   10.82886,
   11.07801,
   8.180359,
   9.933293,
   9.964439,
   9.230336};
   Double_t Graph0_felx3001[12] = {
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
   Double_t Graph0_fely3001[12] = {
   0.3685884,
   0.2663744,
   0.2584099,
   0.2363716,
   0.2088496,
   0.1996747,
   0.2190143,
   0.1992765,
   0.9165036,
   0.3001529,
   0.2384322,
   0.2712198};
   Double_t Graph0_fehx3001[12] = {
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
   Double_t Graph0_fehy3001[12] = {
   0.3452434,
   0.2539442,
   0.247143,
   0.2228973,
   0.1936362,
   0.1863929,
   0.2045342,
   0.184932,
   0.8605296,
   0.2842329,
   0.2281094,
   0.2621264};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(12,Graph0_fx3001,Graph0_fy3001,Graph0_felx3001,Graph0_fehx3001,Graph0_fely3001,Graph0_fehy3001);
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
   
   TH1F *Graph_Graph3001 = new TH1F("Graph_Graph3001","Graph",100,0,1050);
   Graph_Graph3001->SetMinimum(6.863946);
   Graph_Graph3001->SetMaximum(11.66285);
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
