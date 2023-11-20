void Efficiency_open_Ratio()
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
   pad1->Range(-1.25,-2.745783,1.25,24.71204);
   pad1->SetFillColor(0);
   pad1->SetBorderMode(0);
   pad1->SetBorderSize(2);
   pad1->SetTopMargin(0.01);
   pad1->SetFrameBorderMode(0);
   pad1->SetFrameBorderMode(0);
   
   THStack *hs = new THStack();
   hs->SetName("hs");
   hs->SetTitle("open");
   hs->SetMaximum(24.43747);
   
   TH1F *hs_stack_6 = new TH1F("hs_stack_6","open",10,-1,1);
   hs_stack_6->SetMinimum(0);
   hs_stack_6->SetMaximum(24.43747);
   hs_stack_6->SetDirectory(0);
   hs_stack_6->SetStats(0);

   ci = TColor::GetColor("#000099");
   hs_stack_6->SetLineColor(ci);
   hs_stack_6->GetXaxis()->SetTitle("cos(#theta_{opn})");
   hs_stack_6->GetXaxis()->SetLabelFont(42);
   hs_stack_6->GetXaxis()->SetLabelSize(0.045);
   hs_stack_6->GetXaxis()->SetTitleSize(0.05);
   hs_stack_6->GetXaxis()->SetTitleOffset(0.93);
   hs_stack_6->GetXaxis()->SetTitleFont(42);
   hs_stack_6->GetYaxis()->SetTitle(" Events/bin");
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
   
   
   TH1D *h_Before_stack_1 = new TH1D("h_Before_stack_1"," (total)",10,-1,1);
   h_Before_stack_1->SetBinContent(1,1.383253);
   h_Before_stack_1->SetBinContent(2,2.259313);
   h_Before_stack_1->SetBinContent(3,3.527295);
   h_Before_stack_1->SetBinContent(4,3.896162);
   h_Before_stack_1->SetBinContent(5,6.2938);
   h_Before_stack_1->SetBinContent(6,9.751932);
   h_Before_stack_1->SetBinContent(7,13.00258);
   h_Before_stack_1->SetBinContent(8,17.12928);
   h_Before_stack_1->SetBinContent(9,19.54997);
   h_Before_stack_1->SetBinContent(10,15.03135);
   h_Before_stack_1->SetBinError(1,0.1785772);
   h_Before_stack_1->SetBinError(2,0.2282251);
   h_Before_stack_1->SetBinError(3,0.2851649);
   h_Before_stack_1->SetBinError(4,0.2997048);
   h_Before_stack_1->SetBinError(5,0.3809181);
   h_Before_stack_1->SetBinError(6,0.4741552);
   h_Before_stack_1->SetBinError(7,0.5475072);
   h_Before_stack_1->SetBinError(8,0.6284123);
   h_Before_stack_1->SetBinError(9,0.6713488);
   h_Before_stack_1->SetBinError(10,0.588673);
   h_Before_stack_1->SetEntries(3983);
   h_Before_stack_1->SetLineWidth(2);
   h_Before_stack_1->GetXaxis()->SetTitle("cos(#theta_{opn})");
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
   
   TH1D *h_After_stack_2 = new TH1D("h_After_stack_2"," (passed)",10,-1,1);
   h_After_stack_2->SetBinContent(1,0.3458132);
   h_After_stack_2->SetBinContent(2,0.3688674);
   h_After_stack_2->SetBinContent(3,0.6685722);
   h_After_stack_2->SetBinContent(4,0.6224638);
   h_After_stack_2->SetBinContent(5,1.429361);
   h_After_stack_2->SetBinContent(6,2.397638);
   h_After_stack_2->SetBinContent(7,3.388969);
   h_After_stack_2->SetBinContent(8,4.011433);
   h_After_stack_2->SetBinContent(9,4.610843);
   h_After_stack_2->SetBinContent(10,2.259313);
   h_After_stack_2->SetBinError(1,0.08928858);
   h_After_stack_2->SetBinError(2,0.09221685);
   h_After_stack_2->SetBinError(3,0.1241507);
   h_After_stack_2->SetBinError(4,0.1197932);
   h_After_stack_2->SetBinError(5,0.1815291);
   h_After_stack_2->SetBinError(6,0.2351078);
   h_After_stack_2->SetBinError(7,0.2795175);
   h_After_stack_2->SetBinError(8,0.304106);
   h_After_stack_2->SetBinError(9,0.3260358);
   h_After_stack_2->SetBinError(10,0.2282251);
   h_After_stack_2->SetEntries(872);
   h_After_stack_2->SetLineColor(3);
   h_After_stack_2->SetLineWidth(2);
   h_After_stack_2->GetXaxis()->SetTitle("cos(#theta_{opn})");
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
   
   TPaveText *pt = new TPaveText(0.4529397,0.94,0.5470603,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *pt_LaTex = pt->AddText("open");
   pt->Draw();
   TGaxis *gaxis = new TGaxis(1,0,1,24.43747,0,0.3689988,510,"+L");
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
   -0.9,
   -0.7,
   -0.5,
   -0.3,
   -0.1,
   0.1,
   0.3,
   0.5,
   0.7,
   0.9};
   Double_t Graph0_fy3001[10] = {
   16.5566,
   10.81248,
   12.55272,
   10.58055,
   15.04043,
   16.28262,
   17.26114,
   15.50928,
   15.61944,
   9.954277};
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
   3.453461,
   2.295271,
   1.989336,
   1.762203,
   1.621651,
   1.349983,
   1.197037,
   1.006492,
   0.945613,
   0.8975691};
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
   3.80795,
   2.591481,
   2.164922,
   1.936714,
   1.708456,
   1.402253,
   1.233993,
   1.037668,
   0.9727643,
   0.9443194};
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
   
   TH1F *Graph_Graph3001 = new TH1F("Graph_Graph3001","Graph",100,-1.08,1.08);
   Graph_Graph3001->SetMinimum(7.33247);
   Graph_Graph3001->SetMaximum(21.54929);
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
