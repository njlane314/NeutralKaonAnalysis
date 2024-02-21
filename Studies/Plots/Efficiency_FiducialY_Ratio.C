void Efficiency_FiducialY_Ratio()
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
   pad1->Range(-125,-0.9074935,125,8.167441);
   pad1->SetFillColor(0);
   pad1->SetBorderMode(0);
   pad1->SetBorderSize(2);
   pad1->SetTopMargin(0.01);
   pad1->SetFrameBorderMode(0);
   pad1->SetFrameBorderMode(0);
   
   THStack *hs = new THStack();
   hs->SetName("hs");
   hs->SetTitle("");
   hs->SetMaximum(8.076692);
   
   TH1F *hs_stack_2 = new TH1F("hs_stack_2","",20,-100,100);
   hs_stack_2->SetMinimum(0);
   hs_stack_2->SetMaximum(8.076692);
   hs_stack_2->SetDirectory(0);
   hs_stack_2->SetStats(0);

   ci = TColor::GetColor("#000099");
   hs_stack_2->SetLineColor(ci);
   hs_stack_2->GetXaxis()->SetTitle("True Neutrino Interaction Vertex, Y (cm)");
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
   h_Before_stack_1->SetBinContent(0,2.0173);
   h_Before_stack_1->SetBinContent(1,3.20571);
   h_Before_stack_1->SetBinContent(2,4.953371);
   h_Before_stack_1->SetBinContent(3,5.742316);
   h_Before_stack_1->SetBinContent(4,5.49265);
   h_Before_stack_1->SetBinContent(5,6.461353);
   h_Before_stack_1->SetBinContent(6,5.682396);
   h_Before_stack_1->SetBinContent(7,5.812222);
   h_Before_stack_1->SetBinContent(8,5.352837);
   h_Before_stack_1->SetBinContent(9,5.452703);
   h_Before_stack_1->SetBinContent(10,6.101834);
   h_Before_stack_1->SetBinContent(11,5.422743);
   h_Before_stack_1->SetBinContent(12,6.44138);
   h_Before_stack_1->SetBinContent(13,5.572543);
   h_Before_stack_1->SetBinContent(14,5.003305);
   h_Before_stack_1->SetBinContent(15,5.562556);
   h_Before_stack_1->SetBinContent(16,5.502636);
   h_Before_stack_1->SetBinContent(17,5.882129);
   h_Before_stack_1->SetBinContent(18,5.642449);
   h_Before_stack_1->SetBinContent(19,5.242984);
   h_Before_stack_1->SetBinContent(20,4.893452);
   h_Before_stack_1->SetBinContent(21,3.32555);
   h_Before_stack_1->SetBinError(0,0.1419368);
   h_Before_stack_1->SetBinError(1,0.1789253);
   h_Before_stack_1->SetBinError(2,0.2224129);
   h_Before_stack_1->SetBinError(3,0.2394711);
   h_Before_stack_1->SetBinError(4,0.2342074);
   h_Before_stack_1->SetBinError(5,0.254022);
   h_Before_stack_1->SetBinError(6,0.2382184);
   h_Before_stack_1->SetBinError(7,0.2409244);
   h_Before_stack_1->SetBinError(8,0.2312073);
   h_Before_stack_1->SetBinError(9,0.2333542);
   h_Before_stack_1->SetBinError(10,0.2468538);
   h_Before_stack_1->SetBinError(11,0.2327122);
   h_Before_stack_1->SetBinError(12,0.2536291);
   h_Before_stack_1->SetBinError(13,0.2359045);
   h_Before_stack_1->SetBinError(14,0.2235312);
   h_Before_stack_1->SetBinError(15,0.2356931);
   h_Before_stack_1->SetBinError(16,0.2344202);
   h_Before_stack_1->SetBinError(17,0.2423689);
   h_Before_stack_1->SetBinError(18,0.2373796);
   h_Before_stack_1->SetBinError(19,0.2288226);
   h_Before_stack_1->SetBinError(20,0.2210636);
   h_Before_stack_1->SetBinError(21,0.182239);
   h_Before_stack_1->SetEntries(11642);
   h_Before_stack_1->SetLineWidth(2);
   h_Before_stack_1->GetXaxis()->SetTitle("True Neutrino Interaction Vertex, Y (cm)");
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
   h_After_stack_2->SetBinContent(0,1.488009);
   h_After_stack_2->SetBinContent(1,2.686405);
   h_After_stack_2->SetBinContent(2,4.124481);
   h_After_stack_2->SetBinContent(3,4.893452);
   h_After_stack_2->SetBinContent(4,4.743652);
   h_After_stack_2->SetBinContent(5,5.732329);
   h_After_stack_2->SetBinContent(6,4.873478);
   h_After_stack_2->SetBinContent(7,4.963358);
   h_After_stack_2->SetBinContent(8,4.743652);
   h_After_stack_2->SetBinContent(9,4.783599);
   h_After_stack_2->SetBinContent(10,5.422743);
   h_After_stack_2->SetBinContent(11,4.593852);
   h_After_stack_2->SetBinContent(12,5.692382);
   h_After_stack_2->SetBinContent(13,4.663759);
   h_After_stack_2->SetBinContent(14,4.204374);
   h_After_stack_2->SetBinContent(15,4.673746);
   h_After_stack_2->SetBinContent(16,4.474013);
   h_After_stack_2->SetBinContent(17,4.863492);
   h_After_stack_2->SetBinContent(18,4.803572);
   h_After_stack_2->SetBinContent(19,4.194387);
   h_After_stack_2->SetBinContent(20,3.994654);
   h_After_stack_2->SetBinContent(21,2.456712);
   h_After_stack_2->SetBinError(0,0.1219024);
   h_After_stack_2->SetBinError(1,0.163793);
   h_After_stack_2->SetBinError(2,0.2029524);
   h_After_stack_2->SetBinError(3,0.2210636);
   h_After_stack_2->SetBinError(4,0.2176537);
   h_After_stack_2->SetBinError(5,0.2392628);
   h_After_stack_2->SetBinError(6,0.220612);
   h_After_stack_2->SetBinError(7,0.222637);
   h_After_stack_2->SetBinError(8,0.2176537);
   h_After_stack_2->SetBinError(9,0.2185682);
   h_After_stack_2->SetBinError(10,0.2327122);
   h_After_stack_2->SetBinError(11,0.2141895);
   h_After_stack_2->SetBinError(12,0.2384277);
   h_After_stack_2->SetBinError(13,0.215813);
   h_After_stack_2->SetBinError(14,0.2049086);
   h_After_stack_2->SetBinError(15,0.216044);
   h_After_stack_2->SetBinError(16,0.2113772);
   h_After_stack_2->SetBinError(17,0.2203858);
   h_After_stack_2->SetBinError(18,0.219024);
   h_After_stack_2->SetBinError(19,0.2046651);
   h_After_stack_2->SetBinError(20,0.1997327);
   h_After_stack_2->SetBinError(21,0.1566343);
   h_After_stack_2->SetEntries(9838);
   h_After_stack_2->SetLineColor(3);
   h_After_stack_2->SetLineWidth(2);
   h_After_stack_2->GetXaxis()->SetTitle("True Neutrino Interaction Vertex, Y (cm)");
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
   TGaxis *gaxis = new TGaxis(100,0,100,8.076692,0,1.081121,510,"+L");
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
   6.260463,
   6.220533,
   6.366305,
   6.451937,
   6.627761,
   6.407178,
   6.379588,
   6.620458,
   6.553934,
   6.639232,
   6.328739,
   6.601982,
   6.25233,
   6.277744,
   6.276967,
   6.074152,
   6.176933,
   6.359981,
   5.976531,
   6.098501};
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
   0.15765,
   0.1276527,
   0.1128677,
   0.1118639,
   0.09530338,
   0.1118133,
   0.1116415,
   0.1053867,
   0.1076378,
   0.09760292,
   0.1177451,
   0.09664583,
   0.1190279,
   0.1247722,
   0.1182148,
   0.1260214,
   0.1184304,
   0.1141403,
   0.1323183,
   0.1329432};
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
   0.1473182,
   0.1210632,
   0.1068468,
   0.105364,
   0.08941642,
   0.105634,
   0.1056626,
   0.09830071,
   0.1008429,
   0.0913447,
   0.1114615,
   0.09079362,
   0.1130936,
   0.1180976,
   0.1122115,
   0.1204385,
   0.1129767,
   0.1080278,
   0.1267048,
   0.1266017};
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
   Graph_Graph3002->SetMinimum(5.755577);
   Graph_Graph3002->SetMaximum(6.819213);
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
