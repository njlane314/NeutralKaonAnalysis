void Efficiency_MuonMom_Ratio()
{
//=========Macro generated from canvas: c1/c1
//=========  (Mon Dec  4 08:50:31 2023) by ROOT version 6.12/06
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
   pad1->Range(-1.25,-4.066867,11.25,36.6018);
   pad1->SetFillColor(0);
   pad1->SetBorderMode(0);
   pad1->SetBorderSize(2);
   pad1->SetTopMargin(0.01);
   pad1->SetFrameBorderMode(0);
   pad1->SetFrameBorderMode(0);
   
   THStack *hs = new THStack();
   hs->SetName("hs");
   hs->SetTitle("");
   hs->SetMaximum(36.19511);
   
   TH1F *hs_stack_6 = new TH1F("hs_stack_6","",20,0,10);
   hs_stack_6->SetMinimum(0);
   hs_stack_6->SetMaximum(36.19511);
   hs_stack_6->SetDirectory(0);
   hs_stack_6->SetStats(0);

   ci = TColor::GetColor("#000099");
   hs_stack_6->SetLineColor(ci);
   hs_stack_6->GetXaxis()->SetTitle("True Muon Momentum (GeV/c)");
   hs_stack_6->GetXaxis()->SetLabelFont(42);
   hs_stack_6->GetXaxis()->SetLabelSize(0.045);
   hs_stack_6->GetXaxis()->SetTitleSize(0.05);
   hs_stack_6->GetXaxis()->SetTitleOffset(0.93);
   hs_stack_6->GetXaxis()->SetTitleFont(42);
   hs_stack_6->GetYaxis()->SetTitle(" Entries/bin");
   hs_stack_6->GetYaxis()->SetLabelFont(42);
   hs_stack_6->GetYaxis()->SetLabelSize(0.045);
   hs_stack_6->GetYaxis()->SetTitleSize(0.05);
   hs_stack_6->GetYaxis()->SetTitleOffset(1.06);
   hs_stack_6->GetYaxis()->SetTitleFont(42);
   hs_stack_6->GetZaxis()->SetLabelFont(42);
   hs_stack_6->GetZaxis()->SetLabelSize(0.035);
   hs_stack_6->GetZaxis()->SetTitleSize(0.035);
   hs_stack_6->GetZaxis()->SetTitleFont(42);
   hs->SetHistogram(hs_stack_6);
   
   
   TH1D *h_Before_stack_1 = new TH1D("h_Before_stack_1"," (total)",20,0,10);
   h_Before_stack_1->SetBinContent(1,28.95609);
   h_Before_stack_1->SetBinContent(2,24.43747);
   h_Before_stack_1->SetBinContent(3,14.15529);
   h_Before_stack_1->SetBinContent(4,10.1208);
   h_Before_stack_1->SetBinContent(5,8.391734);
   h_Before_stack_1->SetBinContent(6,4.956656);
   h_Before_stack_1->SetBinContent(7,3.826999);
   h_Before_stack_1->SetBinContent(8,2.259313);
   h_Before_stack_1->SetBinContent(9,1.360199);
   h_Before_stack_1->SetBinContent(10,0.8068975);
   h_Before_stack_1->SetBinContent(11,0.5533011);
   h_Before_stack_1->SetBinContent(12,0.4149758);
   h_Before_stack_1->SetBinContent(13,0.2766506);
   h_Before_stack_1->SetBinContent(14,0.2074879);
   h_Before_stack_1->SetBinContent(15,0.1844337);
   h_Before_stack_1->SetBinContent(16,0.02305421);
   h_Before_stack_1->SetBinContent(17,0.09221685);
   h_Before_stack_1->SetBinContent(19,0.02305421);
   h_Before_stack_1->SetBinContent(21,0.02305421);
   h_Before_stack_1->SetBinError(1,0.8170434);
   h_Before_stack_1->SetBinError(2,0.7505908);
   h_Before_stack_1->SetBinError(3,0.5712609);
   h_Before_stack_1->SetBinError(4,0.4830394);
   h_Before_stack_1->SetBinError(5,0.4398464);
   h_Before_stack_1->SetBinError(6,0.3380411);
   h_Before_stack_1->SetBinError(7,0.2970328);
   h_Before_stack_1->SetBinError(8,0.2282251);
   h_Before_stack_1->SetBinError(9,0.1770828);
   h_Before_stack_1->SetBinError(10,0.1363906);
   h_Before_stack_1->SetBinError(11,0.1129421);
   h_Before_stack_1->SetBinError(12,0.09781074);
   h_Before_stack_1->SetBinError(13,0.07986214);
   h_Before_stack_1->SetBinError(14,0.06916264);
   h_Before_stack_1->SetBinError(15,0.06520716);
   h_Before_stack_1->SetBinError(16,0.02305421);
   h_Before_stack_1->SetBinError(17,0.04610843);
   h_Before_stack_1->SetBinError(19,0.02305421);
   h_Before_stack_1->SetBinError(21,0.02305421);
   h_Before_stack_1->SetEntries(4384);
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
   
   TH1D *h_After_stack_2 = new TH1D("h_After_stack_2"," (passed)",20,0,10);
   h_After_stack_2->SetBinContent(1,8.161191);
   h_After_stack_2->SetBinContent(2,7.469565);
   h_After_stack_2->SetBinContent(3,4.357246);
   h_After_stack_2->SetBinContent(4,3.181481);
   h_After_stack_2->SetBinContent(5,2.305421);
   h_After_stack_2->SetBinContent(6,1.429361);
   h_After_stack_2->SetBinContent(7,1.106602);
   h_After_stack_2->SetBinContent(8,0.8991143);
   h_After_stack_2->SetBinContent(9,0.6224638);
   h_After_stack_2->SetBinContent(10,0.2997048);
   h_After_stack_2->SetBinContent(11,0.2305421);
   h_After_stack_2->SetBinContent(12,0.09221685);
   h_After_stack_2->SetBinContent(13,0.09221685);
   h_After_stack_2->SetBinContent(14,0.06916264);
   h_After_stack_2->SetBinContent(17,0.02305421);
   h_After_stack_2->SetBinContent(19,0.02305421);
   h_After_stack_2->SetBinContent(21,0.02305421);
   h_After_stack_2->SetBinError(1,0.4337624);
   h_After_stack_2->SetBinError(2,0.4149758);
   h_After_stack_2->SetBinError(3,0.316943);
   h_After_stack_2->SetBinError(4,0.2708257);
   h_After_stack_2->SetBinError(5,0.2305421);
   h_After_stack_2->SetBinError(6,0.1815291);
   h_After_stack_2->SetBinError(7,0.1597243);
   h_After_stack_2->SetBinError(8,0.1439735);
   h_After_stack_2->SetBinError(9,0.1197932);
   h_After_stack_2->SetBinError(10,0.08312315);
   h_After_stack_2->SetBinError(11,0.07290382);
   h_After_stack_2->SetBinError(12,0.04610843);
   h_After_stack_2->SetBinError(13,0.04610843);
   h_After_stack_2->SetBinError(14,0.03993107);
   h_After_stack_2->SetBinError(17,0.02305421);
   h_After_stack_2->SetBinError(19,0.02305421);
   h_After_stack_2->SetBinError(21,0.02305421);
   h_After_stack_2->SetEntries(1318);
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
   TGaxis *gaxis = new TGaxis(10,0,10,36.19511,0,1.2,510,"+L");
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
   
   Double_t Graph0_fx3006[18] = {
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
   9.25};
   Double_t Graph0_fy3006[18] = {
   8.501241,
   9.21951,
   9.284577,
   9.481636,
   8.286427,
   8.69805,
   8.721714,
   12.00348,
   13.80322,
   11.20325,
   12.56775,
   6.702799,
   10.0542,
   10.0542,
   0,
   0,
   7.540649,
   30.16259};
   Double_t Graph0_felx3006[18] = {
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
   Double_t Graph0_fely3006[18] = {
   0.3770613,
   0.4204241,
   0.5517203,
   0.6548564,
   0.6878356,
   0.9034187,
   1.024799,
   1.448178,
   1.899618,
   2.315212,
   2.837161,
   2.534864,
   3.552716,
   3.975898,
   0,
   0,
   4.564033,
   13.10005};
   Double_t Graph0_fehx3006[18] = {
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
   Double_t Graph0_fehy3006[18] = {
   0.3839602,
   0.4277046,
   0.5641349,
   0.6716109,
   0.7123402,
   0.9422671,
   1.074815,
   1.488855,
   1.927339,
   2.454336,
   2.965697,
   3.101371,
   4.035814,
   4.594151,
   3.586855,
   13.10005,
   6.355802,
   0};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(18,Graph0_fx3006,Graph0_fy3006,Graph0_felx3006,Graph0_fehx3006,Graph0_fely3006,Graph0_fehy3006);
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
   
   TH1F *Graph_Graph3006 = new TH1F("Graph_Graph3006","Graph",100,0,10.15);
   Graph_Graph3006->SetMinimum(0);
   Graph_Graph3006->SetMaximum(33.17885);
   Graph_Graph3006->SetDirectory(0);
   Graph_Graph3006->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph3006->SetLineColor(ci);
   Graph_Graph3006->GetXaxis()->SetLabelFont(42);
   Graph_Graph3006->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph3006->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph3006->GetXaxis()->SetTitleFont(42);
   Graph_Graph3006->GetYaxis()->SetLabelFont(42);
   Graph_Graph3006->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph3006->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph3006->GetYaxis()->SetTitleOffset(0);
   Graph_Graph3006->GetYaxis()->SetTitleFont(42);
   Graph_Graph3006->GetZaxis()->SetLabelFont(42);
   Graph_Graph3006->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph3006->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph3006->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph3006);
   
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
