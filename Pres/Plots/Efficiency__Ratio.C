void Efficiency__Ratio()
{
//=========Macro generated from canvas: c1/c1
//=========  (Thu Nov 30 05:41:33 2023) by ROOT version 6.12/06
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
   pad1->Range(-31.25,-1.745256,281.25,15.7073);
   pad1->SetFillColor(0);
   pad1->SetBorderMode(0);
   pad1->SetBorderSize(2);
   pad1->SetTopMargin(0.01);
   pad1->SetFrameBorderMode(0);
   pad1->SetFrameBorderMode(0);
   
   THStack *hs = new THStack();
   hs->SetName("hs");
   hs->SetTitle("FiducialX");
   hs->SetMaximum(15.53278);
   
   TH1F *hs_stack_1 = new TH1F("hs_stack_1","FiducialX",10,0,250);
   hs_stack_1->SetMinimum(0);
   hs_stack_1->SetMaximum(15.53278);
   hs_stack_1->SetDirectory(0);
   hs_stack_1->SetStats(0);

   ci = TColor::GetColor("#000099");
   hs_stack_1->SetLineColor(ci);
   hs_stack_1->GetXaxis()->SetTitle("Interaction Vertex X (cm)");
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
   
   
   TH1D *h_Before_stack_1 = new TH1D("h_Before_stack_1"," (total)",10,0,250);
   h_Before_stack_1->SetBinContent(0,0.2766506);
   h_Before_stack_1->SetBinContent(1,8.530059);
   h_Before_stack_1->SetBinContent(2,10.97381);
   h_Before_stack_1->SetBinContent(3,12.42622);
   h_Before_stack_1->SetBinContent(4,9.798041);
   h_Before_stack_1->SetBinContent(5,11.01991);
   h_Before_stack_1->SetBinContent(6,9.936366);
   h_Before_stack_1->SetBinContent(7,9.95942);
   h_Before_stack_1->SetBinContent(8,10.21302);
   h_Before_stack_1->SetBinContent(9,9.383065);
   h_Before_stack_1->SetBinContent(10,8.322571);
   h_Before_stack_1->SetBinContent(11,0.2305421);
   h_Before_stack_1->SetBinError(0,0.07986214);
   h_Before_stack_1->SetBinError(1,0.4434566);
   h_Before_stack_1->SetBinError(2,0.5029835);
   h_Before_stack_1->SetBinError(3,0.5352352);
   h_Before_stack_1->SetBinError(4,0.4752748);
   h_Before_stack_1->SetBinError(5,0.5040391);
   h_Before_stack_1->SetBinError(6,0.4786179);
   h_Before_stack_1->SetBinError(7,0.4791728);
   h_Before_stack_1->SetBinError(8,0.4852351);
   h_Before_stack_1->SetBinError(9,0.4651012);
   h_Before_stack_1->SetBinError(10,0.43803);
   h_Before_stack_1->SetBinError(11,0.07290382);
   h_Before_stack_1->SetEntries(4384);
   h_Before_stack_1->SetLineWidth(2);
   h_Before_stack_1->GetXaxis()->SetTitle("Interaction Vertex X (cm)");
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
   
   TH1D *h_After_stack_2 = new TH1D("h_After_stack_2"," (passed)",10,0,250);
   h_After_stack_2->SetBinContent(0,0.1152711);
   h_After_stack_2->SetBinContent(1,7.077643);
   h_After_stack_2->SetBinContent(2,9.383065);
   h_After_stack_2->SetBinContent(3,9.867203);
   h_After_stack_2->SetBinContent(4,8.276462);
   h_After_stack_2->SetBinContent(5,9.406119);
   h_After_stack_2->SetBinContent(6,8.414788);
   h_After_stack_2->SetBinContent(7,8.184246);
   h_After_stack_2->SetBinContent(8,8.391734);
   h_After_stack_2->SetBinContent(9,7.446511);
   h_After_stack_2->SetBinContent(10,6.086312);
   h_After_stack_2->SetBinContent(11,0.1844337);
   h_After_stack_2->SetBinError(0,0.05155079);
   h_After_stack_2->SetBinError(1,0.4039424);
   h_After_stack_2->SetBinError(2,0.4651012);
   h_After_stack_2->SetBinError(3,0.4769493);
   h_After_stack_2->SetBinError(4,0.436815);
   h_After_stack_2->SetBinError(5,0.4656723);
   h_After_stack_2->SetBinError(6,0.4404501);
   h_After_stack_2->SetBinError(7,0.4343747);
   h_After_stack_2->SetBinError(8,0.4398464);
   h_After_stack_2->SetBinError(9,0.4143349);
   h_After_stack_2->SetBinError(10,0.3745866);
   h_After_stack_2->SetBinError(11,0.06520716);
   h_After_stack_2->SetEntries(3593);
   h_After_stack_2->SetLineColor(3);
   h_After_stack_2->SetLineWidth(2);
   h_After_stack_2->GetXaxis()->SetTitle("Interaction Vertex X (cm)");
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
   
   TPaveText *pt = new TPaveText(0.4202764,0.94,0.5797236,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *pt_LaTex = pt->AddText("FiducialX");
   pt->Draw();
   TGaxis *gaxis = new TGaxis(250,0,250,15.53278,0,1.044696,510,"+L");
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
   12.5,
   37.5,
   62.5,
   87.5,
   112.5,
   137.5,
   162.5,
   187.5,
   212.5,
   237.5};
   Double_t Graph0_fy3001[10] = {
   12.33661,
   12.71295,
   11.80631,
   12.55927,
   12.69087,
   12.59142,
   12.2181,
   12.21678,
   11.7996,
   10.87316};
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
   0.2971175,
   0.2456133,
   0.2625105,
   0.2673302,
   0.2460583,
   0.2639961,
   0.2791058,
   0.2755903,
   0.3031075,
   0.3503811};
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
   0.2797081,
   0.2310256,
   0.2518436,
   0.2514749,
   0.2315928,
   0.2482624,
   0.2645493,
   0.2613981,
   0.289015,
   0.337876};
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
   
   TH1F *Graph_Graph3001 = new TH1F("Graph_Graph3001","Graph",100,0,260);
   Graph_Graph3001->SetMinimum(10.28066);
   Graph_Graph3001->SetMaximum(13.1861);
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
