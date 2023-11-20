void Efficiency_energy_Ratio()
{
//=========Macro generated from canvas: c1/c1
//=========  (Sun Nov 19 07:40:14 2023) by ROOT version 6.12/06
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
   pad1->Range(-1.25,-1.86506,11.25,16.78554);
   pad1->SetFillColor(0);
   pad1->SetBorderMode(0);
   pad1->SetBorderSize(2);
   pad1->SetTopMargin(0.01);
   pad1->SetFrameBorderMode(0);
   pad1->SetFrameBorderMode(0);
   
   THStack *hs = new THStack();
   hs->SetName("hs");
   hs->SetTitle("energy");
   hs->SetMaximum(16.59903);
   
   TH1F *hs_stack_7 = new TH1F("hs_stack_7","energy",20,0,10);
   hs_stack_7->SetMinimum(0);
   hs_stack_7->SetMaximum(16.59903);
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
   hs_stack_7->GetYaxis()->SetTitle(" Events/bin");
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
   
   
   TH1D *h_Before_stack_1 = new TH1D("h_Before_stack_1"," (total)",20,0,10);
   h_Before_stack_1->SetBinContent(1,0.2305421);
   h_Before_stack_1->SetBinContent(2,0.5994095);
   h_Before_stack_1->SetBinContent(3,1.544632);
   h_Before_stack_1->SetBinContent(4,8.345625);
   h_Before_stack_1->SetBinContent(5,13.27923);
   h_Before_stack_1->SetBinContent(6,10.85853);
   h_Before_stack_1->SetBinContent(7,12.31095);
   h_Before_stack_1->SetBinContent(8,10.48967);
   h_Before_stack_1->SetBinContent(9,8.622276);
   h_Before_stack_1->SetBinContent(10,6.362963);
   h_Before_stack_1->SetBinContent(11,5.809662);
   h_Before_stack_1->SetBinContent(12,4.288084);
   h_Before_stack_1->SetBinContent(13,3.112319);
   h_Before_stack_1->SetBinContent(14,1.659903);
   h_Before_stack_1->SetBinContent(15,1.221873);
   h_Before_stack_1->SetBinContent(16,0.9221685);
   h_Before_stack_1->SetBinContent(17,0.8991143);
   h_Before_stack_1->SetBinContent(18,0.3458132);
   h_Before_stack_1->SetBinContent(19,0.2074879);
   h_Before_stack_1->SetBinContent(20,0.1613795);
   h_Before_stack_1->SetBinContent(21,0.5533011);
   h_Before_stack_1->SetBinError(1,0.07290382);
   h_Before_stack_1->SetBinError(2,0.1175539);
   h_Before_stack_1->SetBinError(3,0.1887069);
   h_Before_stack_1->SetBinError(4,0.4386363);
   h_Before_stack_1->SetBinError(5,0.5533011);
   h_Before_stack_1->SetBinError(6,0.5003349);
   h_Before_stack_1->SetBinError(7,0.5327469);
   h_Before_stack_1->SetBinError(8,0.4917632);
   h_Before_stack_1->SetBinError(9,0.4458473);
   h_Before_stack_1->SetBinError(10,0.3830054);
   h_Before_stack_1->SetBinError(11,0.3659743);
   h_Before_stack_1->SetBinError(12,0.3144175);
   h_Before_stack_1->SetBinError(13,0.2678657);
   h_Before_stack_1->SetBinError(14,0.1956215);
   h_Before_stack_1->SetBinError(15,0.1678372);
   h_Before_stack_1->SetBinError(16,0.1458076);
   h_Before_stack_1->SetBinError(17,0.1439735);
   h_Before_stack_1->SetBinError(18,0.08928858);
   h_Before_stack_1->SetBinError(19,0.06916264);
   h_Before_stack_1->SetBinError(20,0.06099571);
   h_Before_stack_1->SetBinError(21,0.1129421);
   h_Before_stack_1->SetEntries(3983);
   h_Before_stack_1->SetLineWidth(2);
   h_Before_stack_1->GetXaxis()->SetTitle("Neutrino Energy (GeV)");
   h_Before_stack_1->GetXaxis()->SetLabelFont(42);
   h_Before_stack_1->GetXaxis()->SetLabelSize(0.035);
   h_Before_stack_1->GetXaxis()->SetTitleSize(0.035);
   h_Before_stack_1->GetXaxis()->SetTitleFont(42);
   h_Before_stack_1->GetYaxis()->SetTitle(" Events/bin");
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
   h_After_stack_2->SetBinContent(2,0.09221685);
   h_After_stack_2->SetBinContent(3,0.3919216);
   h_After_stack_2->SetBinContent(4,2.328476);
   h_After_stack_2->SetBinContent(5,3.412024);
   h_After_stack_2->SetBinContent(6,2.144042);
   h_After_stack_2->SetBinContent(7,2.651234);
   h_After_stack_2->SetBinContent(8,2.374584);
   h_After_stack_2->SetBinContent(9,2.097933);
   h_After_stack_2->SetBinContent(10,1.498524);
   h_After_stack_2->SetBinContent(11,1.129656);
   h_After_stack_2->SetBinContent(12,0.645518);
   h_After_stack_2->SetBinContent(13,0.5302469);
   h_After_stack_2->SetBinContent(14,0.2305421);
   h_After_stack_2->SetBinContent(15,0.1844337);
   h_After_stack_2->SetBinContent(16,0.1613795);
   h_After_stack_2->SetBinContent(17,0.06916264);
   h_After_stack_2->SetBinContent(18,0.06916264);
   h_After_stack_2->SetBinContent(20,0.02305421);
   h_After_stack_2->SetBinContent(21,0.06916264);
   h_After_stack_2->SetBinError(2,0.04610843);
   h_After_stack_2->SetBinError(3,0.09505496);
   h_After_stack_2->SetBinError(4,0.231692);
   h_After_stack_2->SetBinError(5,0.2804666);
   h_After_stack_2->SetBinError(6,0.2223268);
   h_After_stack_2->SetBinError(7,0.2472289);
   h_After_stack_2->SetBinError(8,0.2339747);
   h_After_stack_2->SetBinError(9,0.2199232);
   h_After_stack_2->SetBinError(10,0.185869);
   h_After_stack_2->SetBinError(11,0.1613795);
   h_After_stack_2->SetBinError(12,0.1219914);
   h_After_stack_2->SetBinError(13,0.1105641);
   h_After_stack_2->SetBinError(14,0.07290382);
   h_After_stack_2->SetBinError(15,0.06520716);
   h_After_stack_2->SetBinError(16,0.06099571);
   h_After_stack_2->SetBinError(17,0.03993107);
   h_After_stack_2->SetBinError(18,0.03993107);
   h_After_stack_2->SetBinError(20,0.02305421);
   h_After_stack_2->SetBinError(21,0.03993107);
   h_After_stack_2->SetEntries(872);
   h_After_stack_2->SetLineColor(3);
   h_After_stack_2->SetLineWidth(2);
   h_After_stack_2->GetXaxis()->SetTitle("Neutrino Energy (GeV)");
   h_After_stack_2->GetXaxis()->SetLabelFont(42);
   h_After_stack_2->GetXaxis()->SetLabelSize(0.035);
   h_After_stack_2->GetXaxis()->SetTitleSize(0.035);
   h_After_stack_2->GetXaxis()->SetTitleFont(42);
   h_After_stack_2->GetYaxis()->SetTitle(" Events/bin");
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
   
   TPaveText *pt = new TPaveText(0.4384925,0.94,0.5615075,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *pt_LaTex = pt->AddText("energy");
   pt->Draw();
   TGaxis *gaxis = new TGaxis(10,0,10,16.59903,0,0.3720839,510,"+L");
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
   
   Double_t Graph0_fx3002[20] = {
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
   8.75,
   9.25,
   9.75};
   Double_t Graph0_fy3002[20] = {
   0,
   6.86323,
   11.31921,
   12.44671,
   11.46255,
   8.808541,
   9.607237,
   10.09875,
   10.85455,
   10.50621,
   8.67436,
   6.715634,
   7.600392,
   6.195972,
   6.733735,
   7.806924,
   3.431615,
   8.922199,
   0,
   6.372999};
   Double_t Graph0_felx3002[20] = {
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
   Double_t Graph0_fely3002[20] = {
   0,
   2.697592,
   2.223354,
   1.02536,
   0.7941154,
   0.7936257,
   0.7723828,
   0.8511958,
   0.9620162,
   1.101687,
   1.067386,
   1.104767,
   1.357464,
   1.650216,
   1.969082,
   2.390737,
   1.582015,
   3.835575,
   0,
   4.191774};
   Double_t Graph0_fehx3002[20] = {
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
   Double_t Graph0_fehy3002[20] = {
   4.389747,
   3.446275,
   2.434544,
   1.061108,
   0.818868,
   0.8312959,
   0.8036504,
   0.8864524,
   1.002219,
   1.157743,
   1.13831,
   1.21458,
   1.49971,
   1.94078,
   2.347982,
   2.853336,
   2.21678,
   4.910328,
   4.804228,
   6.793771};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(20,Graph0_fx3002,Graph0_fy3002,Graph0_felx3002,Graph0_fehx3002,Graph0_fely3002,Graph0_fehy3002);
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
   
   TH1F *Graph_Graph3002 = new TH1F("Graph_Graph3002","Graph",100,0,10.7);
   Graph_Graph3002->SetMinimum(0);
   Graph_Graph3002->SetMaximum(15.21578);
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
