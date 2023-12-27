void Efficiency_MuonMom_Ratio()
{
//=========Macro generated from canvas: c1/c1
//=========  (Thu Nov 23 04:44:55 2023) by ROOT version 6.12/06
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
   pad1->Range(-1.625,-9.70414,14.625,87.33726);
   pad1->SetFillColor(0);
   pad1->SetBorderMode(0);
   pad1->SetBorderSize(2);
   pad1->SetTopMargin(0.01);
   pad1->SetFrameBorderMode(0);
   pad1->SetFrameBorderMode(0);
   
   THStack *hs = new THStack();
   hs->SetName("hs");
   hs->SetTitle("MuonMom");
   hs->SetMaximum(86.36685);
   
   TH1F *hs_stack_3 = new TH1F("hs_stack_3","MuonMom",26,0,13);
   hs_stack_3->SetMinimum(0);
   hs_stack_3->SetMaximum(86.36685);
   hs_stack_3->SetDirectory(0);
   hs_stack_3->SetStats(0);

   ci = TColor::GetColor("#000099");
   hs_stack_3->SetLineColor(ci);
   hs_stack_3->GetXaxis()->SetTitle("True Muon Momentum (GeV/c)");
   hs_stack_3->GetXaxis()->SetLabelFont(42);
   hs_stack_3->GetXaxis()->SetLabelSize(0.045);
   hs_stack_3->GetXaxis()->SetTitleSize(0.05);
   hs_stack_3->GetXaxis()->SetTitleOffset(0.93);
   hs_stack_3->GetXaxis()->SetTitleFont(42);
   hs_stack_3->GetYaxis()->SetTitle(" Entries/bin");
   hs_stack_3->GetYaxis()->SetLabelFont(42);
   hs_stack_3->GetYaxis()->SetLabelSize(0.045);
   hs_stack_3->GetYaxis()->SetTitleSize(0.05);
   hs_stack_3->GetYaxis()->SetTitleOffset(1.06);
   hs_stack_3->GetYaxis()->SetTitleFont(42);
   hs_stack_3->GetZaxis()->SetLabelFont(42);
   hs_stack_3->GetZaxis()->SetLabelSize(0.035);
   hs_stack_3->GetZaxis()->SetTitleSize(0.035);
   hs_stack_3->GetZaxis()->SetTitleFont(42);
   hs->SetHistogram(hs_stack_3);
   
   
   TH1D *h_Before_stack_1 = new TH1D("h_Before_stack_1"," (total)",26,0,13);
   h_Before_stack_1->SetBinContent(1,69.09348);
   h_Before_stack_1->SetBinContent(2,45.43985);
   h_Before_stack_1->SetBinContent(3,31.93008);
   h_Before_stack_1->SetBinContent(4,22.77756);
   h_Before_stack_1->SetBinContent(5,15.6077);
   h_Before_stack_1->SetBinContent(6,12.10346);
   h_Before_stack_1->SetBinContent(7,7.123752);
   h_Before_stack_1->SetBinContent(8,5.048873);
   h_Before_stack_1->SetBinContent(9,3.342861);
   h_Before_stack_1->SetBinContent(10,2.005717);
   h_Before_stack_1->SetBinContent(11,1.383253);
   h_Before_stack_1->SetBinContent(12,0.8760601);
   h_Before_stack_1->SetBinContent(13,0.9221685);
   h_Before_stack_1->SetBinContent(14,0.43803);
   h_Before_stack_1->SetBinContent(15,0.1152711);
   h_Before_stack_1->SetBinContent(16,0.3458132);
   h_Before_stack_1->SetBinContent(17,0.04610843);
   h_Before_stack_1->SetBinContent(18,0.1844337);
   h_Before_stack_1->SetBinContent(20,0.02305421);
   h_Before_stack_1->SetBinContent(21,0.04610843);
   h_Before_stack_1->SetBinContent(22,0.06916264);
   h_Before_stack_1->SetBinContent(23,0.02305421);
   h_Before_stack_1->SetBinContent(26,0.09221685);
   h_Before_stack_1->SetBinError(1,1.2621);
   h_Before_stack_1->SetBinError(2,1.023514);
   h_Before_stack_1->SetBinError(3,0.8579761);
   h_Before_stack_1->SetBinError(4,0.7246508);
   h_Before_stack_1->SetBinError(5,0.5998527);
   h_Before_stack_1->SetBinError(6,0.5282384);
   h_Before_stack_1->SetBinError(7,0.4052561);
   h_Before_stack_1->SetBinError(8,0.3411712);
   h_Before_stack_1->SetBinError(9,0.2776095);
   h_Before_stack_1->SetBinError(10,0.2150354);
   h_Before_stack_1->SetBinError(11,0.1785772);
   h_Before_stack_1->SetBinError(12,0.1421157);
   h_Before_stack_1->SetBinError(13,0.1458076);
   h_Before_stack_1->SetBinError(14,0.100491);
   h_Before_stack_1->SetBinError(15,0.05155079);
   h_Before_stack_1->SetBinError(16,0.08928858);
   h_Before_stack_1->SetBinError(17,0.03260358);
   h_Before_stack_1->SetBinError(18,0.06520716);
   h_Before_stack_1->SetBinError(20,0.02305421);
   h_Before_stack_1->SetBinError(21,0.03260358);
   h_Before_stack_1->SetBinError(22,0.03993107);
   h_Before_stack_1->SetBinError(23,0.02305421);
   h_Before_stack_1->SetBinError(26,0.04610843);
   h_Before_stack_1->SetEntries(9501);
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
   
   TH1D *h_After_stack_2 = new TH1D("h_After_stack_2"," (passed)",26,0,13);
   h_After_stack_2->SetBinContent(1,10.23607);
   h_After_stack_2->SetBinContent(2,6.870155);
   h_After_stack_2->SetBinContent(3,4.564734);
   h_After_stack_2->SetBinContent(4,3.296752);
   h_After_stack_2->SetBinContent(5,2.858722);
   h_After_stack_2->SetBinContent(6,1.844337);
   h_After_stack_2->SetBinContent(7,1.291036);
   h_After_stack_2->SetBinContent(8,1.244928);
   h_After_stack_2->SetBinContent(9,0.43803);
   h_After_stack_2->SetBinContent(10,0.3919216);
   h_After_stack_2->SetBinContent(11,0.1613795);
   h_After_stack_2->SetBinContent(12,0.09221685);
   h_After_stack_2->SetBinContent(13,0.06916264);
   h_After_stack_2->SetBinContent(14,0.06916264);
   h_After_stack_2->SetBinContent(16,0.06916264);
   h_After_stack_2->SetBinContent(18,0.02305421);
   h_After_stack_2->SetBinContent(22,0.02305421);
   h_After_stack_2->SetBinError(1,0.4857824);
   h_After_stack_2->SetBinError(2,0.3979774);
   h_After_stack_2->SetBinError(3,0.3244015);
   h_After_stack_2->SetBinError(4,0.2756883);
   h_After_stack_2->SetBinError(5,0.2567209);
   h_After_stack_2->SetBinError(6,0.2062031);
   h_After_stack_2->SetBinError(7,0.1725219);
   h_After_stack_2->SetBinError(8,0.1694132);
   h_After_stack_2->SetBinError(9,0.100491);
   h_After_stack_2->SetBinError(10,0.09505496);
   h_After_stack_2->SetBinError(11,0.06099571);
   h_After_stack_2->SetBinError(12,0.04610843);
   h_After_stack_2->SetBinError(13,0.03993107);
   h_After_stack_2->SetBinError(14,0.03993107);
   h_After_stack_2->SetBinError(16,0.03993107);
   h_After_stack_2->SetBinError(18,0.02305421);
   h_After_stack_2->SetBinError(22,0.02305421);
   h_After_stack_2->SetEntries(1455);
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
   
   TPaveText *pt = new TPaveText(0.4121106,0.94,0.5878894,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *pt_LaTex = pt->AddText("MuonMom");
   pt->Draw();
   TGaxis *gaxis = new TGaxis(13,0,13,86.36685,0,0.6822362,510,"+L");
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
   
   Double_t Graph0_fx3003[23] = {
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
   9.75,
   10.25,
   10.75,
   11.25,
   12.75};
   Double_t Graph0_fy3003[23] = {
   18.75463,
   19.14,
   18.09788,
   18.32278,
   23.18704,
   19.29048,
   22.94256,
   31.2149,
   16.58815,
   24.73671,
   14.76927,
   13.32566,
   9.494532,
   19.98849,
   0,
   25.31875,
   0,
   15.82422,
   0,
   0,
   42.19792,
   0,
   0};
   Double_t Graph0_felx3003[23] = {
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
   0,
   0,
   0,
   0};
   Double_t Graph0_fely3003[23] = {
   0.8069824,
   1.00078,
   1.162127,
   1.378405,
   1.830585,
   1.917305,
   2.666882,
   3.556734,
   3.305749,
   5.019691,
   4.661334,
   5.376291,
   4.381665,
   8.80699,
   0,
   10.88431,
   0,
   10.54902,
   0,
   0,
   23.88306,
   0,
   0};
   Double_t Graph0_fehx3003[23] = {
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
   0,
   0,
   0,
   0};
   Double_t Graph0_fehy3003[23] = {
   0.8265735,
   1.030303,
   1.205123,
   1.438357,
   1.908548,
   2.027577,
   2.838327,
   3.748515,
   3.727466,
   5.594709,
   5.712177,
   7.07714,
   6.148338,
   11.6319,
   21.89602,
   13.93416,
   40.00485,
   17.56175,
   54.98152,
   40.00485,
   29.77445,
   54.98152,
   25.79799};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(23,Graph0_fx3003,Graph0_fy3003,Graph0_felx3003,Graph0_fehx3003,Graph0_fely3003,Graph0_fehy3003);
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
   
   TH1F *Graph_Graph3003 = new TH1F("Graph_Graph3003","Graph",100,0,14);
   Graph_Graph3003->SetMinimum(0);
   Graph_Graph3003->SetMaximum(79.16961);
   Graph_Graph3003->SetDirectory(0);
   Graph_Graph3003->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph3003->SetLineColor(ci);
   Graph_Graph3003->GetXaxis()->SetLabelFont(42);
   Graph_Graph3003->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph3003->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph3003->GetXaxis()->SetTitleFont(42);
   Graph_Graph3003->GetYaxis()->SetLabelFont(42);
   Graph_Graph3003->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph3003->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph3003->GetYaxis()->SetTitleOffset(0);
   Graph_Graph3003->GetYaxis()->SetTitleFont(42);
   Graph_Graph3003->GetZaxis()->SetLabelFont(42);
   Graph_Graph3003->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph3003->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph3003->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph3003);
   
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
