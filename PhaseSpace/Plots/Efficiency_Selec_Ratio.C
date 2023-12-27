void Efficiency_Selec_Ratio()
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
   pad1->Range(-1.25,-1.424699,11.25,12.82229);
   pad1->SetFillColor(0);
   pad1->SetBorderMode(0);
   pad1->SetBorderSize(2);
   pad1->SetTopMargin(0.01);
   pad1->SetFrameBorderMode(0);
   pad1->SetFrameBorderMode(0);
   
   THStack *hs = new THStack();
   hs->SetName("hs");
   hs->SetTitle("Selec");
   hs->SetMaximum(12.67982);
   
   TH1F *hs_stack_4 = new TH1F("hs_stack_4","Selec",10,0,10);
   hs_stack_4->SetMinimum(0);
   hs_stack_4->SetMaximum(12.67982);
   hs_stack_4->SetDirectory(0);
   hs_stack_4->SetStats(0);

   ci = TColor::GetColor("#000099");
   hs_stack_4->SetLineColor(ci);
   hs_stack_4->GetXaxis()->SetTitle("Neutrino Energy (GeV)");
   hs_stack_4->GetXaxis()->SetLabelFont(42);
   hs_stack_4->GetXaxis()->SetLabelSize(0.045);
   hs_stack_4->GetXaxis()->SetTitleSize(0.05);
   hs_stack_4->GetXaxis()->SetTitleOffset(0.93);
   hs_stack_4->GetXaxis()->SetTitleFont(42);
   hs_stack_4->GetYaxis()->SetTitle(" Entries/bin");
   hs_stack_4->GetYaxis()->SetLabelFont(42);
   hs_stack_4->GetYaxis()->SetLabelSize(0.045);
   hs_stack_4->GetYaxis()->SetTitleSize(0.05);
   hs_stack_4->GetYaxis()->SetTitleOffset(1.06);
   hs_stack_4->GetYaxis()->SetTitleFont(42);
   hs_stack_4->GetZaxis()->SetLabelFont(42);
   hs_stack_4->GetZaxis()->SetLabelSize(0.035);
   hs_stack_4->GetZaxis()->SetTitleSize(0.035);
   hs_stack_4->GetZaxis()->SetTitleFont(42);
   hs->SetHistogram(hs_stack_4);
   
   
   TH1D *h_Before_stack_1 = new TH1D("h_Before_stack_1"," (total)",10,0,10);
   h_Before_stack_1->SetBinContent(1,0.4149758);
   h_Before_stack_1->SetBinContent(2,5.210252);
   h_Before_stack_1->SetBinContent(3,10.14385);
   h_Before_stack_1->SetBinContent(4,8.737547);
   h_Before_stack_1->SetBinContent(5,5.901879);
   h_Before_stack_1->SetBinContent(6,4.472517);
   h_Before_stack_1->SetBinContent(7,2.259313);
   h_Before_stack_1->SetBinContent(8,0.8760601);
   h_Before_stack_1->SetBinContent(9,0.5533011);
   h_Before_stack_1->SetBinContent(10,0.2305421);
   h_Before_stack_1->SetBinContent(11,0.06916264);
   h_Before_stack_1->SetBinError(1,0.09781074);
   h_Before_stack_1->SetBinError(2,0.3465808);
   h_Before_stack_1->SetBinError(3,0.4835893);
   h_Before_stack_1->SetBinError(4,0.4488176);
   h_Before_stack_1->SetBinError(5,0.3688674);
   h_Before_stack_1->SetBinError(6,0.321108);
   h_Before_stack_1->SetBinError(7,0.2282251);
   h_Before_stack_1->SetBinError(8,0.1421157);
   h_Before_stack_1->SetBinError(9,0.1129421);
   h_Before_stack_1->SetBinError(10,0.07290382);
   h_Before_stack_1->SetBinError(11,0.03993107);
   h_Before_stack_1->SetEntries(1686);
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
   h_After_stack_2->SetBinContent(1,0.06916264);
   h_After_stack_2->SetBinContent(2,0.6916264);
   h_After_stack_2->SetBinContent(3,1.360199);
   h_After_stack_2->SetBinContent(4,1.221873);
   h_After_stack_2->SetBinContent(5,1.106602);
   h_After_stack_2->SetBinContent(6,0.5533011);
   h_After_stack_2->SetBinContent(7,0.2074879);
   h_After_stack_2->SetBinContent(8,0.06916264);
   h_After_stack_2->SetBinContent(9,0.02305421);
   h_After_stack_2->SetBinContent(11,0.02305421);
   h_After_stack_2->SetBinError(1,0.03993107);
   h_After_stack_2->SetBinError(2,0.1262731);
   h_After_stack_2->SetBinError(3,0.1770828);
   h_After_stack_2->SetBinError(4,0.1678372);
   h_After_stack_2->SetBinError(5,0.1597243);
   h_After_stack_2->SetBinError(6,0.1129421);
   h_After_stack_2->SetBinError(7,0.06916264);
   h_After_stack_2->SetBinError(8,0.03993107);
   h_After_stack_2->SetBinError(9,0.02305421);
   h_After_stack_2->SetBinError(11,0.02305421);
   h_After_stack_2->SetEntries(231);
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
   
   TPaveText *pt = new TPaveText(0.4491709,0.94,0.5508291,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *pt_LaTex = pt->AddText("Selec");
   pt->Draw();
   TGaxis *gaxis = new TGaxis(10,0,10,12.67982,0,0.3150517,510,"+L");
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
   
   Double_t Graph0_fx3004[10] = {
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
   Double_t Graph0_fy3004[10] = {
   6.707796,
   5.342493,
   5.396727,
   5.628177,
   7.546271,
   4.978983,
   3.696133,
   3.177377,
   1.676949,
   0};
   Double_t Graph0_felx3004[10] = {
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
   Double_t Graph0_fely3004[10] = {
   2.940546,
   0.8585107,
   0.627442,
   0.6869126,
   0.9414399,
   0.8928879,
   1.056439,
   1.463196,
   1.188031,
   0};
   Double_t Graph0_fehx3004[10] = {
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
   Double_t Graph0_fehy3004[10] = {
   3.858718,
   0.944346,
   0.6714672,
   0.7371944,
   1.005871,
   0.9953066,
   1.276255,
   2.047274,
   2.25849,
   3.960305};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(10,Graph0_fx3004,Graph0_fy3004,Graph0_felx3004,Graph0_fehx3004,Graph0_fely3004,Graph0_fehy3004);
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
   
   TH1F *Graph_Graph3004 = new TH1F("Graph_Graph3004","Graph",100,0,10.4);
   Graph_Graph3004->SetMinimum(0);
   Graph_Graph3004->SetMaximum(11.62317);
   Graph_Graph3004->SetDirectory(0);
   Graph_Graph3004->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph3004->SetLineColor(ci);
   Graph_Graph3004->GetXaxis()->SetLabelFont(42);
   Graph_Graph3004->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph3004->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph3004->GetXaxis()->SetTitleFont(42);
   Graph_Graph3004->GetYaxis()->SetLabelFont(42);
   Graph_Graph3004->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph3004->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph3004->GetYaxis()->SetTitleOffset(0);
   Graph_Graph3004->GetYaxis()->SetTitleFont(42);
   Graph_Graph3004->GetZaxis()->SetLabelFont(42);
   Graph_Graph3004->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph3004->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph3004->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph3004);
   
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
