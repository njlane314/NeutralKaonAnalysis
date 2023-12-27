void Efficiency_Selec_Ratio()
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
   pad1->Range(-1.25,-3.584412,11.25,32.25971);
   pad1->SetFillColor(0);
   pad1->SetBorderMode(0);
   pad1->SetBorderSize(2);
   pad1->SetTopMargin(0.01);
   pad1->SetFrameBorderMode(0);
   pad1->SetFrameBorderMode(0);
   
   THStack *hs = new THStack();
   hs->SetName("hs");
   hs->SetTitle("Selec");
   hs->SetMaximum(31.90127);
   
   TH1F *hs_stack_7 = new TH1F("hs_stack_7","Selec",10,0,10);
   hs_stack_7->SetMinimum(0);
   hs_stack_7->SetMaximum(31.90127);
   hs_stack_7->SetDirectory(0);
   hs_stack_7->SetStats(0);

   ci = TColor::GetColor("#000099");
   hs_stack_7->SetLineColor(ci);
   hs_stack_7->GetXaxis()->SetTitle("Neutrino Energy (GeV)");
   hs_stack_7->GetXaxis()->SetLabelFont(42);
   hs_stack_7->GetXaxis()->SetLabelSize(0.045);
   hs_stack_7->GetXaxis()->SetTitleSize(0.05);
   hs_stack_7->GetXaxis()->SetTitleOffset(0.93);
   hs_stack_7->GetXaxis()->SetTitleFont(42);
   hs_stack_7->GetYaxis()->SetTitle(" Entries/bin");
   hs_stack_7->GetYaxis()->SetLabelFont(42);
   hs_stack_7->GetYaxis()->SetLabelSize(0.045);
   hs_stack_7->GetYaxis()->SetTitleSize(0.05);
   hs_stack_7->GetYaxis()->SetTitleOffset(1.06);
   hs_stack_7->GetYaxis()->SetTitleFont(42);
   hs_stack_7->GetZaxis()->SetLabelFont(42);
   hs_stack_7->GetZaxis()->SetLabelSize(0.035);
   hs_stack_7->GetZaxis()->SetTitleSize(0.035);
   hs_stack_7->GetZaxis()->SetTitleFont(42);
   hs->SetHistogram(hs_stack_7);
   
   
   TH1D *h_Before_stack_1 = new TH1D("h_Before_stack_1"," (total)",10,0,10);
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
   h_Before_stack_1->SetBinContent(11,0.4841385);
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
   h_Before_stack_1->SetBinError(11,0.1056477);
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
   
   TH1D *h_After_stack_2 = new TH1D("h_After_stack_2"," (passed)",10,0,10);
   h_After_stack_2->SetBinContent(2,0.43803);
   h_After_stack_2->SetBinContent(3,1.337144);
   h_After_stack_2->SetBinContent(4,1.75212);
   h_After_stack_2->SetBinContent(5,1.498524);
   h_After_stack_2->SetBinContent(6,0.8991143);
   h_After_stack_2->SetBinContent(7,0.322759);
   h_After_stack_2->SetBinContent(8,0.06916264);
   h_After_stack_2->SetBinContent(9,0.02305421);
   h_After_stack_2->SetBinContent(10,0.02305421);
   h_After_stack_2->SetBinContent(11,0.02305421);
   h_After_stack_2->SetBinError(2,0.100491);
   h_After_stack_2->SetBinError(3,0.1755757);
   h_After_stack_2->SetBinError(4,0.200982);
   h_After_stack_2->SetBinError(5,0.185869);
   h_After_stack_2->SetBinError(6,0.1439735);
   h_After_stack_2->SetBinError(7,0.08626097);
   h_After_stack_2->SetBinError(8,0.03993107);
   h_After_stack_2->SetBinError(9,0.02305421);
   h_After_stack_2->SetBinError(10,0.02305421);
   h_After_stack_2->SetBinError(11,0.02305421);
   h_After_stack_2->SetEntries(277);
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
   TGaxis *gaxis = new TGaxis(10,0,10,31.90127,0,0.122138,510,"+L");
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
   
   Double_t Graph0_fx3007[10] = {
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
   Double_t Graph0_fy3007[10] = {
   0,
   11.75976,
   13.68477,
   18.36307,
   21.96297,
   20.53715,
   14.68541,
   6.422716,
   4.281811,
   11.35611};
   Double_t Graph0_felx3007[10] = {
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
   Double_t Graph0_fely3007[10] = {
   0,
   2.442725,
   1.671071,
   1.951767,
   2.500064,
   2.993505,
   3.494152,
   3.04488,
   3.087855,
   8.03486};
   Double_t Graph0_fehx3007[10] = {
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
   Double_t Graph0_fehy3007[10] = {
   9.734282,
   2.815099,
   1.810416,
   2.088663,
   2.685276,
   3.285932,
   4.109234,
   4.431575,
   6.128732,
   15.22828};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(10,Graph0_fx3007,Graph0_fy3007,Graph0_felx3007,Graph0_fehx3007,Graph0_fely3007,Graph0_fehy3007);
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
   
   TH1F *Graph_Graph3007 = new TH1F("Graph_Graph3007","Graph",100,0,10.4);
   Graph_Graph3007->SetMinimum(0);
   Graph_Graph3007->SetMaximum(29.24283);
   Graph_Graph3007->SetDirectory(0);
   Graph_Graph3007->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph3007->SetLineColor(ci);
   Graph_Graph3007->GetXaxis()->SetLabelFont(42);
   Graph_Graph3007->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph3007->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph3007->GetXaxis()->SetTitleFont(42);
   Graph_Graph3007->GetYaxis()->SetLabelFont(42);
   Graph_Graph3007->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph3007->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph3007->GetYaxis()->SetTitleOffset(0);
   Graph_Graph3007->GetYaxis()->SetTitleFont(42);
   Graph_Graph3007->GetZaxis()->SetLabelFont(42);
   Graph_Graph3007->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph3007->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph3007->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph3007);
   
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
