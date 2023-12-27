void Efficiency_FiducialY_Ratio()
{
//=========Macro generated from canvas: c1/c1
//=========  (Mon Dec  4 08:50:30 2023) by ROOT version 6.12/06
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
   pad1->Range(-125,-0.8774848,125,7.897363);
   pad1->SetFillColor(0);
   pad1->SetBorderMode(0);
   pad1->SetBorderSize(2);
   pad1->SetTopMargin(0.01);
   pad1->SetFrameBorderMode(0);
   pad1->SetFrameBorderMode(0);
   
   THStack *hs = new THStack();
   hs->SetName("hs");
   hs->SetTitle("");
   hs->SetMaximum(7.809615);
   
   TH1F *hs_stack_2 = new TH1F("hs_stack_2","",20,-100,100);
   hs_stack_2->SetMinimum(0);
   hs_stack_2->SetMaximum(7.809615);
   hs_stack_2->SetDirectory(0);
   hs_stack_2->SetStats(0);

   ci = TColor::GetColor("#000099");
   hs_stack_2->SetLineColor(ci);
   hs_stack_2->GetXaxis()->SetTitle("Interaction Vertex Y (cm)");
   hs_stack_2->GetXaxis()->SetLabelFont(42);
   hs_stack_2->GetXaxis()->SetLabelSize(0.045);
   hs_stack_2->GetXaxis()->SetTitleSize(0.05);
   hs_stack_2->GetXaxis()->SetTitleOffset(0.93);
   hs_stack_2->GetXaxis()->SetTitleFont(42);
   hs_stack_2->GetYaxis()->SetTitle(" Entries/bin");
   hs_stack_2->GetYaxis()->SetLabelFont(42);
   hs_stack_2->GetYaxis()->SetLabelSize(0.045);
   hs_stack_2->GetYaxis()->SetTitleSize(0.05);
   hs_stack_2->GetYaxis()->SetTitleOffset(1.06);
   hs_stack_2->GetYaxis()->SetTitleFont(42);
   hs_stack_2->GetZaxis()->SetLabelFont(42);
   hs_stack_2->GetZaxis()->SetLabelSize(0.035);
   hs_stack_2->GetZaxis()->SetTitleSize(0.035);
   hs_stack_2->GetZaxis()->SetTitleFont(42);
   hs->SetHistogram(hs_stack_2);
   
   
   TH1D *h_Before_stack_1 = new TH1D("h_Before_stack_1"," (total)",20,-100,100);
   h_Before_stack_1->SetBinContent(0,1.821283);
   h_Before_stack_1->SetBinContent(1,2.489855);
   h_Before_stack_1->SetBinContent(2,5.279415);
   h_Before_stack_1->SetBinContent(3,5.025818);
   h_Before_stack_1->SetBinContent(4,5.071927);
   h_Before_stack_1->SetBinContent(5,4.172813);
   h_Before_stack_1->SetBinContent(6,6.247692);
   h_Before_stack_1->SetBinContent(7,4.564734);
   h_Before_stack_1->SetBinContent(8,5.302469);
   h_Before_stack_1->SetBinContent(9,5.717445);
   h_Before_stack_1->SetBinContent(10,4.749168);
   h_Before_stack_1->SetBinContent(11,4.910547);
   h_Before_stack_1->SetBinContent(12,4.610843);
   h_Before_stack_1->SetBinContent(13,4.403355);
   h_Before_stack_1->SetBinContent(14,5.118035);
   h_Before_stack_1->SetBinContent(15,4.265029);
   h_Before_stack_1->SetBinContent(16,5.025818);
   h_Before_stack_1->SetBinContent(17,4.610843);
   h_Before_stack_1->SetBinContent(18,5.256361);
   h_Before_stack_1->SetBinContent(19,4.956656);
   h_Before_stack_1->SetBinContent(20,4.288084);
   h_Before_stack_1->SetBinContent(21,3.181481);
   h_Before_stack_1->SetBinError(0,0.2049103);
   h_Before_stack_1->SetBinError(1,0.2395864);
   h_Before_stack_1->SetBinError(2,0.3488735);
   h_Before_stack_1->SetBinError(3,0.3403914);
   h_Before_stack_1->SetBinError(4,0.3419492);
   h_Before_stack_1->SetBinError(5,0.3101627);
   h_Before_stack_1->SetBinError(6,0.3795202);
   h_Before_stack_1->SetBinError(7,0.3244015);
   h_Before_stack_1->SetBinError(8,0.3496345);
   h_Before_stack_1->SetBinError(9,0.3630581);
   h_Before_stack_1->SetBinError(10,0.3308902);
   h_Before_stack_1->SetBinError(11,0.3364652);
   h_Before_stack_1->SetBinError(12,0.3260358);
   h_Before_stack_1->SetBinError(13,0.3186156);
   h_Before_stack_1->SetBinError(14,0.3435);
   h_Before_stack_1->SetBinError(15,0.3135712);
   h_Before_stack_1->SetBinError(16,0.3403914);
   h_Before_stack_1->SetBinError(17,0.3260358);
   h_Before_stack_1->SetBinError(18,0.348111);
   h_Before_stack_1->SetBinError(19,0.3380411);
   h_Before_stack_1->SetBinError(20,0.3144175);
   h_Before_stack_1->SetBinError(21,0.2708257);
   h_Before_stack_1->SetEntries(4384);
   h_Before_stack_1->SetLineWidth(2);
   h_Before_stack_1->GetXaxis()->SetTitle("Interaction Vertex Y (cm)");
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
   
   TH1D *h_After_stack_2 = new TH1D("h_After_stack_2"," (passed)",20,-100,100);
   h_After_stack_2->SetBinContent(0,1.47547);
   h_After_stack_2->SetBinContent(1,2.19015);
   h_After_stack_2->SetBinContent(2,4.449463);
   h_After_stack_2->SetBinContent(3,4.265029);
   h_After_stack_2->SetBinContent(4,4.472517);
   h_After_stack_2->SetBinContent(5,3.550349);
   h_After_stack_2->SetBinContent(6,5.233306);
   h_After_stack_2->SetBinContent(7,3.873108);
   h_After_stack_2->SetBinContent(8,4.149758);
   h_After_stack_2->SetBinContent(9,4.749168);
   h_After_stack_2->SetBinContent(10,3.896162);
   h_After_stack_2->SetBinContent(11,4.057541);
   h_After_stack_2->SetBinContent(12,3.896162);
   h_After_stack_2->SetBinContent(13,3.412024);
   h_After_stack_2->SetBinContent(14,4.149758);
   h_After_stack_2->SetBinContent(15,3.481186);
   h_After_stack_2->SetBinContent(16,4.126704);
   h_After_stack_2->SetBinContent(17,3.734783);
   h_After_stack_2->SetBinContent(18,4.334192);
   h_After_stack_2->SetBinContent(19,3.688674);
   h_After_stack_2->SetBinContent(20,3.342861);
   h_After_stack_2->SetBinContent(21,2.305421);
   h_After_stack_2->SetBinError(0,0.1844337);
   h_After_stack_2->SetBinError(1,0.2247047);
   h_After_stack_2->SetBinError(2,0.3202794);
   h_After_stack_2->SetBinError(3,0.3135712);
   h_After_stack_2->SetBinError(4,0.321108);
   h_After_stack_2->SetBinError(5,0.2860953);
   h_After_stack_2->SetBinError(6,0.3473467);
   h_After_stack_2->SetBinError(7,0.2988168);
   h_After_stack_2->SetBinError(8,0.3093047);
   h_After_stack_2->SetBinError(9,0.3308902);
   h_After_stack_2->SetBinError(10,0.2997048);
   h_After_stack_2->SetBinError(11,0.3058487);
   h_After_stack_2->SetBinError(12,0.2997048);
   h_After_stack_2->SetBinError(13,0.2804666);
   h_After_stack_2->SetBinError(14,0.3093047);
   h_After_stack_2->SetBinError(15,0.2832949);
   h_After_stack_2->SetBinError(16,0.3084443);
   h_After_stack_2->SetBinError(17,0.2934322);
   h_After_stack_2->SetBinError(18,0.3161034);
   h_After_stack_2->SetBinError(19,0.2916153);
   h_After_stack_2->SetBinError(20,0.2776095);
   h_After_stack_2->SetBinError(21,0.2305421);
   h_After_stack_2->SetEntries(3593);
   h_After_stack_2->SetLineColor(3);
   h_After_stack_2->SetLineWidth(2);
   h_After_stack_2->GetXaxis()->SetTitle("Interaction Vertex Y (cm)");
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
   TGaxis *gaxis = new TGaxis(100,0,100,7.809615,0,1.09003,510,"+L");
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
   -95,
   -85,
   -75,
   -65,
   -55,
   -45,
   -35,
   -25,
   -15,
   -5,
   5,
   15,
   25,
   35,
   45,
   55,
   65,
   75,
   85,
   95};
   Double_t Graph0_fy3002[20] = {
   6.302184,
   6.038277,
   6.08004,
   6.317864,
   6.095837,
   6.001334,
   6.079044,
   5.607069,
   5.95123,
   5.877744,
   5.920035,
   6.054077,
   5.551618,
   5.809125,
   5.847853,
   5.88285,
   5.803316,
   5.907643,
   5.331786,
   5.585297};
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
   0.2387493,
   0.1779614,
   0.1800133,
   0.1629716,
   0.1971793,
   0.1651022,
   0.1892866,
   0.1988847,
   0.1755114,
   0.1972213,
   0.1915693,
   0.1898902,
   0.2211668,
   0.1932575,
   0.2101347,
   0.1912852,
   0.2042069,
   0.1856242,
   0.2164965,
   0.2226862};
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
   0.205828,
   0.1638959,
   0.1649884,
   0.146644,
   0.1789874,
   0.153387,
   0.1727599,
   0.187352,
   0.1629823,
   0.1826246,
   0.1771873,
   0.1736932,
   0.207679,
   0.180114,
   0.1941062,
   0.1774561,
   0.1896659,
   0.1722546,
   0.2058462,
   0.2086009};
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
   
   TH1F *Graph_Graph3002 = new TH1F("Graph_Graph3002","Graph",100,-114,114);
   Graph_Graph3002->SetMinimum(4.976018);
   Graph_Graph3002->SetMaximum(6.647284);
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
