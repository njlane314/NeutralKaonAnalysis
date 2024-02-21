void Efficiency_MuonMom_Ratio()
{
//=========Macro generated from canvas: c1/c1
//=========  (Thu Feb  1 05:32:41 2024) by ROOT version 6.12/06
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
   pad1->Range(-0.625,-1.416425,5.625,12.74783);
   pad1->SetFillColor(0);
   pad1->SetBorderMode(0);
   pad1->SetBorderSize(2);
   pad1->SetTopMargin(0.01);
   pad1->SetFrameBorderMode(0);
   pad1->SetFrameBorderMode(0);
   
   THStack *hs = new THStack();
   hs->SetName("hs");
   hs->SetTitle("");
   hs->SetMaximum(12.60619);
   
   TH1F *hs_stack_1 = new TH1F("hs_stack_1","",20,0,5);
   hs_stack_1->SetMinimum(0);
   hs_stack_1->SetMaximum(12.60619);
   hs_stack_1->SetDirectory(0);
   hs_stack_1->SetStats(0);

   ci = TColor::GetColor("#000099");
   hs_stack_1->SetLineColor(ci);
   hs_stack_1->GetXaxis()->SetTitle("True Muon Momentum (GeV/c)");
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
   
   
   TH1D *h_Before_stack_1 = new TH1D("h_Before_stack_1"," (total)",20,0,5);
   h_Before_stack_1->SetBinContent(1,4.952146);
   h_Before_stack_1->SetBinContent(2,10.08495);
   h_Before_stack_1->SetBinContent(3,8.209297);
   h_Before_stack_1->SetBinContent(4,5.908569);
   h_Before_stack_1->SetBinContent(5,4.527069);
   h_Before_stack_1->SetBinContent(6,4.091365);
   h_Before_stack_1->SetBinContent(7,2.178519);
   h_Before_stack_1->SetBinContent(8,2.199773);
   h_Before_stack_1->SetBinContent(9,1.817204);
   h_Before_stack_1->SetBinContent(10,1.174275);
   h_Before_stack_1->SetBinContent(11,1.312425);
   h_Before_stack_1->SetBinContent(12,0.5951076);
   h_Before_stack_1->SetBinContent(13,0.5579134);
   h_Before_stack_1->SetBinContent(14,0.6588692);
   h_Before_stack_1->SetBinContent(15,0.2603596);
   h_Before_stack_1->SetBinContent(16,0.3400615);
   h_Before_stack_1->SetBinContent(17,0.2125384);
   h_Before_stack_1->SetBinContent(18,0.1594038);
   h_Before_stack_1->SetBinContent(19,0.1328365);
   h_Before_stack_1->SetBinContent(20,0.08501538);
   h_Before_stack_1->SetBinContent(21,0.5738538);
   h_Before_stack_1->SetBinError(1,0.1622129);
   h_Before_stack_1->SetBinError(2,0.2314865);
   h_Before_stack_1->SetBinError(3,0.2088535);
   h_Before_stack_1->SetBinError(4,0.1771862);
   h_Before_stack_1->SetBinError(5,0.1550948);
   h_Before_stack_1->SetBinError(6,0.1474426);
   h_Before_stack_1->SetBinError(7,0.1075894);
   h_Before_stack_1->SetBinError(8,0.1081129);
   h_Before_stack_1->SetBinError(9,0.09826312);
   h_Before_stack_1->SetBinError(10,0.07899028);
   h_Before_stack_1->SetBinError(11,0.0835076);
   h_Before_stack_1->SetBinError(12,0.05623239);
   h_Before_stack_1->SetBinError(13,0.05444677);
   h_Before_stack_1->SetBinError(14,0.0591682);
   h_Before_stack_1->SetBinError(15,0.03719423);
   h_Before_stack_1->SetBinError(16,0.04250769);
   h_Before_stack_1->SetBinError(17,0.03360528);
   h_Before_stack_1->SetBinError(18,0.02910302);
   h_Before_stack_1->SetBinError(19,0.02656731);
   h_Before_stack_1->SetBinError(20,0.02125384);
   h_Before_stack_1->SetBinError(21,0.05521911);
   h_Before_stack_1->SetEntries(9506);
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
   
   TH1D *h_After_stack_2 = new TH1D("h_After_stack_2"," (passed)",20,0,5);
   h_After_stack_2->SetBinContent(1,1.206156);
   h_After_stack_2->SetBinContent(2,6.152988);
   h_After_stack_2->SetBinContent(3,5.196565);
   h_After_stack_2->SetBinContent(4,3.963842);
   h_After_stack_2->SetBinContent(5,2.752373);
   h_After_stack_2->SetBinContent(6,2.747059);
   h_After_stack_2->SetBinContent(7,1.354933);
   h_After_stack_2->SetBinContent(8,1.445261);
   h_After_stack_2->SetBinContent(9,1.200842);
   h_After_stack_2->SetBinContent(10,0.7120038);
   h_After_stack_2->SetBinContent(11,0.8395268);
   h_After_stack_2->SetBinContent(12,0.3081807);
   h_After_stack_2->SetBinContent(13,0.2975538);
   h_After_stack_2->SetBinContent(14,0.3560019);
   h_After_stack_2->SetBinContent(15,0.1328365);
   h_After_stack_2->SetBinContent(16,0.1806577);
   h_After_stack_2->SetBinContent(17,0.1647173);
   h_After_stack_2->SetBinContent(18,0.1115827);
   h_After_stack_2->SetBinContent(19,0.04782115);
   h_After_stack_2->SetBinContent(20,0.03719423);
   h_After_stack_2->SetBinContent(21,0.3560019);
   h_After_stack_2->SetBinError(1,0.08005536);
   h_After_stack_2->SetBinError(2,0.1808139);
   h_After_stack_2->SetBinError(3,0.1661678);
   h_After_stack_2->SetBinError(4,0.1451266);
   h_After_stack_2->SetBinError(5,0.1209323);
   h_After_stack_2->SetBinError(6,0.1208155);
   h_After_stack_2->SetBinError(7,0.08484917);
   h_After_stack_2->SetBinError(8,0.08763185);
   h_After_stack_2->SetBinError(9,0.07987884);
   h_After_stack_2->SetBinError(10,0.06150776);
   h_After_stack_2->SetBinError(11,0.06678917);
   h_After_stack_2->SetBinError(12,0.04046611);
   h_After_stack_2->SetBinError(13,0.0397623);
   h_After_stack_2->SetBinError(14,0.04349255);
   h_After_stack_2->SetBinError(15,0.02656731);
   h_After_stack_2->SetBinError(16,0.03098254);
   h_After_stack_2->SetBinError(17,0.0295841);
   h_After_stack_2->SetBinError(18,0.02434934);
   h_After_stack_2->SetBinError(19,0.01594038);
   h_After_stack_2->SetBinError(20,0.0140581);
   h_After_stack_2->SetBinError(21,0.04349255);
   h_After_stack_2->SetEntries(5608);
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
   TGaxis *gaxis = new TGaxis(5,0,5,12.60619,0,1.002019,510,"+L");
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
   
   Double_t Graph0_fx3001[20] = {
   0.125,
   0.375,
   0.625,
   0.875,
   1.125,
   1.375,
   1.625,
   1.875,
   2.125,
   2.375,
   2.625,
   2.875,
   3.125,
   3.375,
   3.625,
   3.875,
   4.125,
   4.375,
   4.625,
   4.875};
   Double_t Graph0_fy3001[20] = {
   3.064203,
   7.675735,
   7.963757,
   8.439985,
   7.648879,
   8.447097,
   7.824633,
   8.265635,
   8.313616,
   7.628167,
   8.047626,
   6.515048,
   6.709751,
   6.797681,
   6.418766,
   6.683541,
   9.750106,
   8.806548,
   4.529082,
   5.504092};
   Double_t Graph0_felx3001[20] = {
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
   Double_t Graph0_fely3001[20] = {
   0.1734683,
   0.1404707,
   0.1540307,
   0.1774217,
   0.2100634,
   0.2133545,
   0.3013592,
   0.2943578,
   0.3232844,
   0.4133206,
   0.3853645,
   0.5868233,
   0.6060087,
   0.5581512,
   0.8774416,
   0.7724673,
   0.864926,
   1.068666,
   1.113944,
   1.434028};
   Double_t Graph0_fehx3001[20] = {
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
   Double_t Graph0_fehy3001[20] = {
   0.178025,
   0.1395092,
   0.1526042,
   0.1748766,
   0.2079652,
   0.2096694,
   0.2964461,
   0.2880928,
   0.3155229,
   0.4054021,
   0.3760494,
   0.5842202,
   0.6008309,
   0.5528337,
   0.8741094,
   0.7645885,
   0.7550495,
   0.9639272,
   1.200774,
   1.492285};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(20,Graph0_fx3001,Graph0_fy3001,Graph0_felx3001,Graph0_fehx3001,Graph0_fely3001,Graph0_fehy3001);
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
   
   TH1F *Graph_Graph3001 = new TH1F("Graph_Graph3001","Graph",100,0,5.35);
   Graph_Graph3001->SetMinimum(2.129293);
   Graph_Graph3001->SetMaximum(11.2666);
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
   entry=leg->AddEntry("NULL","NuMI FHC, 12.5 #times 10^{20} POT","h");
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
