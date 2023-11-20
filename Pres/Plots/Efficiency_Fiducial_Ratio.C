void Efficiency_Fiducial_Ratio()
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
   hs->SetTitle("Fiducial");
   hs->SetMaximum(69.50845);
   
   TH1F *hs_stack_1 = new TH1F("hs_stack_1","Fiducial",10,0,10);
   hs_stack_1->SetMinimum(0);
   hs_stack_1->SetMaximum(69.50845);
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
   h_After_stack_2->SetBinContent(1,0.5994095);
   h_After_stack_2->SetBinContent(2,4.034487);
   h_After_stack_2->SetBinContent(3,15.81519);
   h_After_stack_2->SetBinContent(4,17.31371);
   h_After_stack_2->SetBinContent(5,11.84987);
   h_After_stack_2->SetBinContent(6,8.64533);
   h_After_stack_2->SetBinContent(7,3.94227);
   h_After_stack_2->SetBinContent(8,2.259313);
   h_After_stack_2->SetBinContent(9,0.9221685);
   h_After_stack_2->SetBinContent(10,0.2074879);
   h_After_stack_2->SetBinContent(11,0.4610843);
   h_After_stack_2->SetBinError(1,0.1175539);
   h_After_stack_2->SetBinError(2,0.3049786);
   h_After_stack_2->SetBinError(3,0.6038268);
   h_After_stack_2->SetBinError(4,0.6317864);
   h_After_stack_2->SetBinError(5,0.5226752);
   h_After_stack_2->SetBinError(6,0.4464429);
   h_After_stack_2->SetBinError(7,0.301473);
   h_After_stack_2->SetBinError(8,0.2282251);
   h_After_stack_2->SetBinError(9,0.1458076);
   h_After_stack_2->SetBinError(10,0.06916264);
   h_After_stack_2->SetBinError(11,0.1031016);
   h_After_stack_2->SetEntries(2865);
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
   
   TPaveText *pt = new TPaveText(0.4315829,0.94,0.5684171,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *pt_LaTex = pt->AddText("Fiducial");
   pt->Draw();
   TGaxis *gaxis = new TGaxis(10,0,10,69.50845,0,0.453467,510,"+L");
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
   
   Double_t Graph0_fx3001[10] = {
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
   Double_t Graph0_fy3001[10] = {
   49.81674,
   41.78256,
   46.96367,
   47.72595,
   45.33205,
   50.11409,
   40.76403,
   44.97504,
   42.28477,
   26.52963};
   Double_t Graph0_felx3001[10] = {
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
   Double_t Graph0_fely3001[10] = {
   7.674089,
   2.639502,
   1.475722,
   1.428753,
   1.655954,
   2.094389,
   2.615726,
   3.725306,
   5.46914,
   7.277783};
   Double_t Graph0_fehx3001[10] = {
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
   Double_t Graph0_fehy3001[10] = {
   8.106967,
   2.710916,
   1.493186,
   1.444547,
   1.679685,
   2.124839,
   2.689114,
   3.849699,
   5.778077,
   8.517027};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(10,Graph0_fx3001,Graph0_fy3001,Graph0_felx3001,Graph0_fehx3001,Graph0_fely3001,Graph0_fehy3001);
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
   
   TH1F *Graph_Graph3001 = new TH1F("Graph_Graph3001","Graph",100,0,10.4);
   Graph_Graph3001->SetMinimum(15.38466);
   Graph_Graph3001->SetMaximum(61.7909);
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
