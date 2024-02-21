void Efficiency_FiducialX_Ratio()
{
//=========Macro generated from canvas: c1/c1
//=========  (Wed Jan 31 06:57:37 2024) by ROOT version 6.12/06
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
   pad1->Range(-31.25,-0.8022972,281.25,7.220674);
   pad1->SetFillColor(0);
   pad1->SetBorderMode(0);
   pad1->SetBorderSize(2);
   pad1->SetTopMargin(0.01);
   pad1->SetFrameBorderMode(0);
   pad1->SetFrameBorderMode(0);
   
   THStack *hs = new THStack();
   hs->SetName("hs");
   hs->SetTitle("");
   hs->SetMaximum(7.140445);
   
   TH1F *hs_stack_1 = new TH1F("hs_stack_1","",25,0,250);
   hs_stack_1->SetMinimum(0);
   hs_stack_1->SetMaximum(7.140445);
   hs_stack_1->SetDirectory(0);
   hs_stack_1->SetStats(0);

   ci = TColor::GetColor("#000099");
   hs_stack_1->SetLineColor(ci);
   hs_stack_1->GetXaxis()->SetTitle("True Neutrino Interaction Vertex, X (cm)");
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
   
   
   TH1D *h_Before_stack_1 = new TH1D("h_Before_stack_1"," (total)",25,0,250);
   h_Before_stack_1->SetBinContent(1,0.7589843);
   h_Before_stack_1->SetBinContent(2,5.033264);
   h_Before_stack_1->SetBinContent(3,5.512623);
   h_Before_stack_1->SetBinContent(4,5.472676);
   h_Before_stack_1->SetBinContent(5,5.562556);
   h_Before_stack_1->SetBinContent(6,5.31289);
   h_Before_stack_1->SetBinContent(7,5.213024);
   h_Before_stack_1->SetBinContent(8,4.853505);
   h_Before_stack_1->SetBinContent(9,5.003305);
   h_Before_stack_1->SetBinContent(10,4.314227);
   h_Before_stack_1->SetBinContent(11,5.43273);
   h_Before_stack_1->SetBinContent(12,5.712356);
   h_Before_stack_1->SetBinContent(13,5.003305);
   h_Before_stack_1->SetBinContent(14,4.553906);
   h_Before_stack_1->SetBinContent(15,4.763625);
   h_Before_stack_1->SetBinContent(16,4.42408);
   h_Before_stack_1->SetBinContent(17,5.542583);
   h_Before_stack_1->SetBinContent(18,4.39412);
   h_Before_stack_1->SetBinContent(19,4.543919);
   h_Before_stack_1->SetBinContent(20,3.555242);
   h_Before_stack_1->SetBinContent(21,4.254307);
   h_Before_stack_1->SetBinContent(22,5.033264);
   h_Before_stack_1->SetBinContent(23,4.39412);
   h_Before_stack_1->SetBinContent(24,3.854841);
   h_Before_stack_1->SetBinContent(25,2.266966);
   h_Before_stack_1->SetBinError(1,0.08706147);
   h_Before_stack_1->SetBinError(2,0.2241994);
   h_Before_stack_1->SetBinError(3,0.2346328);
   h_Before_stack_1->SetBinError(4,0.2337812);
   h_Before_stack_1->SetBinError(5,0.2356931);
   h_Before_stack_1->SetBinError(6,0.230343);
   h_Before_stack_1->SetBinError(7,0.2281679);
   h_Before_stack_1->SetBinError(8,0.2201595);
   h_Before_stack_1->SetBinError(9,0.2235312);
   h_Before_stack_1->SetBinError(10,0.2075683);
   h_Before_stack_1->SetBinError(11,0.2329264);
   h_Before_stack_1->SetBinError(12,0.2388456);
   h_Before_stack_1->SetBinError(13,0.2235312);
   h_Before_stack_1->SetBinError(14,0.2132562);
   h_Before_stack_1->SetBinError(15,0.2181114);
   h_Before_stack_1->SetBinError(16,0.2101944);
   h_Before_stack_1->SetBinError(17,0.2352695);
   h_Before_stack_1->SetBinError(18,0.2094814);
   h_Before_stack_1->SetBinError(19,0.2130222);
   h_Before_stack_1->SetBinError(20,0.1884275);
   h_Before_stack_1->SetBinError(21,0.2061218);
   h_Before_stack_1->SetBinError(22,0.2241994);
   h_Before_stack_1->SetBinError(23,0.2094814);
   h_Before_stack_1->SetBinError(24,0.1962063);
   h_Before_stack_1->SetBinError(25,0.1504638);
   h_Before_stack_1->SetEntries(11642);
   h_Before_stack_1->SetLineWidth(2);
   h_Before_stack_1->GetXaxis()->SetTitle("True Neutrino Interaction Vertex, X (cm)");
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
   
   TH1D *h_After_stack_2 = new TH1D("h_After_stack_2"," (passed)",25,0,250);
   h_After_stack_2->SetBinContent(1,0.5692382);
   h_After_stack_2->SetBinContent(2,4.1844);
   h_After_stack_2->SetBinContent(3,4.673746);
   h_After_stack_2->SetBinContent(4,4.503973);
   h_After_stack_2->SetBinContent(5,4.673746);
   h_After_stack_2->SetBinContent(6,4.573879);
   h_After_stack_2->SetBinContent(7,4.39412);
   h_After_stack_2->SetBinContent(8,4.064561);
   h_After_stack_2->SetBinContent(9,4.384133);
   h_After_stack_2->SetBinContent(10,3.824882);
   h_After_stack_2->SetBinContent(11,4.763625);
   h_After_stack_2->SetBinContent(12,4.903438);
   h_After_stack_2->SetBinContent(13,4.294253);
   h_After_stack_2->SetBinContent(14,3.984668);
   h_After_stack_2->SetBinContent(15,4.1844);
   h_After_stack_2->SetBinContent(16,3.904775);
   h_After_stack_2->SetBinContent(17,4.843518);
   h_After_stack_2->SetBinContent(18,3.695055);
   h_After_stack_2->SetBinContent(19,3.874815);
   h_After_stack_2->SetBinContent(20,2.956044);
   h_After_stack_2->SetBinContent(21,3.615162);
   h_After_stack_2->SetBinContent(22,4.384133);
   h_After_stack_2->SetBinContent(23,3.705042);
   h_After_stack_2->SetBinContent(24,3.335536);
   h_After_stack_2->SetBinContent(25,0.7789576);
   h_After_stack_2->SetBinError(1,0.07539745);
   h_After_stack_2->SetBinError(2,0.2044213);
   h_After_stack_2->SetBinError(3,0.216044);
   h_After_stack_2->SetBinError(4,0.2120838);
   h_After_stack_2->SetBinError(5,0.216044);
   h_After_stack_2->SetBinError(6,0.2137233);
   h_After_stack_2->SetBinError(7,0.2094814);
   h_After_stack_2->SetBinError(8,0.2014728);
   h_After_stack_2->SetBinError(9,0.2092433);
   h_After_stack_2->SetBinError(10,0.1954423);
   h_After_stack_2->SetBinError(11,0.2181114);
   h_After_stack_2->SetBinError(12,0.2212891);
   h_After_stack_2->SetBinError(13,0.2070873);
   h_After_stack_2->SetBinError(14,0.1994829);
   h_After_stack_2->SetBinError(15,0.2044213);
   h_After_stack_2->SetBinError(16,0.1974729);
   h_After_stack_2->SetBinError(17,0.2199328);
   h_After_stack_2->SetBinError(18,0.1920968);
   h_After_stack_2->SetBinError(19,0.1967139);
   h_After_stack_2->SetBinError(20,0.1718166);
   h_After_stack_2->SetBinError(21,0.1900087);
   h_After_stack_2->SetBinError(22,0.2092433);
   h_After_stack_2->SetBinError(23,0.1923562);
   h_After_stack_2->SetBinError(24,0.1825124);
   h_After_stack_2->SetBinError(25,0.08819958);
   h_After_stack_2->SetEntries(9838);
   h_After_stack_2->SetLineColor(3);
   h_After_stack_2->SetLineWidth(2);
   h_After_stack_2->GetXaxis()->SetTitle("True Neutrino Interaction Vertex, X (cm)");
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
   TGaxis *gaxis = new TGaxis(250,0,250,7.140445,0,1.081375,510,"+L");
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
   
   Double_t Graph0_fx3001[25] = {
   5,
   15,
   25,
   35,
   45,
   55,
   65,
   75,
   85,
   95,
   105,
   115,
   125,
   135,
   145,
   155,
   165,
   175,
   185,
   195,
   205,
   215,
   225,
   235,
   245};
   Double_t Graph0_fy3001[25] = {
   4.952336,
   5.489494,
   5.598293,
   5.434315,
   5.548039,
   5.684636,
   5.565844,
   5.529769,
   5.785963,
   5.85415,
   5.789863,
   5.668058,
   5.667344,
   5.777725,
   5.80022,
   5.828031,
   5.770289,
   5.552619,
   5.630788,
   5.49023,
   5.611097,
   5.751522,
   5.567626,
   5.713576,
   2.268912};
   Double_t Graph0_felx3001[25] = {
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
   0,
   0,
   0};
   Double_t Graph0_fely3001[25] = {
   0.3366063,
   0.112237,
   0.1030214,
   0.1094899,
   0.1044868,
   0.1013702,
   0.1073159,
   0.1127721,
   0.09978916,
   0.1039958,
   0.0954596,
   0.0983588,
   0.1053141,
   0.1051753,
   0.1016244,
   0.1040885,
   0.09539211,
   0.1177048,
   0.1123196,
   0.1340829,
   0.1170871,
   0.1011447,
   0.1170635,
   0.1180755,
   0.2031473};
   Double_t Graph0_fehx3001[25] = {
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
   0,
   0,
   0};
   Double_t Graph0_fehy3001[25] = {
   0.308551,
   0.1065276,
   0.09754706,
   0.1043707,
   0.0991807,
   0.09547598,
   0.1016097,
   0.1067424,
   0.09326319,
   0.09622002,
   0.08943902,
   0.09291428,
   0.09910165,
   0.09803064,
   0.0947311,
   0.09658388,
   0.08953737,
   0.110978,
   0.1055869,
   0.1260059,
   0.1099585,
   0.09474802,
   0.1102916,
   0.109859,
   0.2091003};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(25,Graph0_fx3001,Graph0_fy3001,Graph0_felx3001,Graph0_fehx3001,Graph0_fely3001,Graph0_fehy3001);
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
   
   TH1F *Graph_Graph3001 = new TH1F("Graph_Graph3001","Graph",100,0,269);
   Graph_Graph3001->SetMinimum(1.677304);
   Graph_Graph3001->SetMaximum(6.338831);
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
   entry=leg->AddEntry("NULL","NuMI FHC, 15.0 #times 10^{20} POT","h");
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
