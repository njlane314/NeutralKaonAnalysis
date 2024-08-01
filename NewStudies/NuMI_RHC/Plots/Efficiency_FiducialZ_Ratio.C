void Efficiency_FiducialZ_Ratio()
{
//=========Macro generated from canvas: c1/c1
//=========  (Tue Apr 16 08:41:20 2024) by ROOT version 6.12/06
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
   pad1->Range(-125,-0.5862941,1125,5.276647);
   pad1->SetFillColor(0);
   pad1->SetBorderMode(0);
   pad1->SetBorderSize(2);
   pad1->SetTopMargin(0.01);
   pad1->SetFrameBorderMode(0);
   pad1->SetFrameBorderMode(0);
   
   THStack *hs = new THStack();
   hs->SetName("hs");
   hs->SetTitle("");
   hs->SetMaximum(5.218017);
   
   TH1F *hs_stack_3 = new TH1F("hs_stack_3","",40,0,1000);
   hs_stack_3->SetMinimum(0);
   hs_stack_3->SetMaximum(5.218017);
   hs_stack_3->SetDirectory(0);
   hs_stack_3->SetStats(0);

   ci = TColor::GetColor("#000099");
   hs_stack_3->SetLineColor(ci);
   hs_stack_3->GetXaxis()->SetTitle("True Neutrino Interaction Vertex, Z (cm)");
   hs_stack_3->GetXaxis()->SetLabelFont(42);
   hs_stack_3->GetXaxis()->SetLabelSize(0.045);
   hs_stack_3->GetXaxis()->SetTitleSize(0.05);
   hs_stack_3->GetXaxis()->SetTitleOffset(0.93);
   hs_stack_3->GetXaxis()->SetTitleFont(42);
   hs_stack_3->GetYaxis()->SetTitle("Entries/bin");
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
   
   
   TH1D *h_Before_stack_1 = new TH1D("h_Before_stack_1"," (total)",40,0,1000);
   h_Before_stack_1->SetBinContent(1,0.9187705);
   h_Before_stack_1->SetBinContent(2,1.657782);
   h_Before_stack_1->SetBinContent(3,1.707715);
   h_Before_stack_1->SetBinContent(4,2.246993);
   h_Before_stack_1->SetBinContent(5,2.826218);
   h_Before_stack_1->SetBinContent(6,3.655109);
   h_Before_stack_1->SetBinContent(7,3.35551);
   h_Before_stack_1->SetBinContent(8,3.904775);
   h_Before_stack_1->SetBinContent(9,3.125817);
   h_Before_stack_1->SetBinContent(10,3.465363);
   h_Before_stack_1->SetBinContent(11,3.764962);
   h_Before_stack_1->SetBinContent(12,3.445389);
   h_Before_stack_1->SetBinContent(13,2.796258);
   h_Before_stack_1->SetBinContent(14,3.774948);
   h_Before_stack_1->SetBinContent(15,3.615162);
   h_Before_stack_1->SetBinContent(16,3.195723);
   h_Before_stack_1->SetBinContent(17,3.32555);
   h_Before_stack_1->SetBinContent(18,3.045924);
   h_Before_stack_1->SetBinContent(19,3.455376);
   h_Before_stack_1->SetBinContent(20,3.455376);
   h_Before_stack_1->SetBinContent(21,2.946058);
   h_Before_stack_1->SetBinContent(22,2.816231);
   h_Before_stack_1->SetBinContent(23,3.035937);
   h_Before_stack_1->SetBinContent(24,3.645122);
   h_Before_stack_1->SetBinContent(25,2.766298);
   h_Before_stack_1->SetBinContent(26,4.174414);
   h_Before_stack_1->SetBinContent(27,3.735002);
   h_Before_stack_1->SetBinContent(32,3.645122);
   h_Before_stack_1->SetBinContent(33,3.585202);
   h_Before_stack_1->SetBinContent(34,3.405443);
   h_Before_stack_1->SetBinContent(35,3.705042);
   h_Before_stack_1->SetBinContent(36,3.725015);
   h_Before_stack_1->SetBinContent(37,3.015964);
   h_Before_stack_1->SetBinContent(38,3.784935);
   h_Before_stack_1->SetBinContent(39,3.695055);
   h_Before_stack_1->SetBinContent(40,3.844855);
   h_Before_stack_1->SetBinError(1,0.09578845);
   h_Before_stack_1->SetBinError(2,0.1286688);
   h_Before_stack_1->SetBinError(3,0.1305922);
   h_Before_stack_1->SetBinError(4,0.1497995);
   h_Before_stack_1->SetBinError(5,0.1680012);
   h_Before_stack_1->SetBinError(6,0.1910556);
   h_Before_stack_1->SetBinError(7,0.1830581);
   h_Before_stack_1->SetBinError(8,0.1974729);
   h_Before_stack_1->SetBinError(9,0.1766816);
   h_Before_stack_1->SetBinError(10,0.1860304);
   h_Before_stack_1->SetBinError(11,0.1939054);
   h_Before_stack_1->SetBinError(12,0.1854935);
   h_Before_stack_1->SetBinError(13,0.1671084);
   h_Before_stack_1->SetBinError(14,0.1941624);
   h_Before_stack_1->SetBinError(15,0.1900087);
   h_Before_stack_1->SetBinError(16,0.1786464);
   h_Before_stack_1->SetBinError(17,0.182239);
   h_Before_stack_1->SetBinError(18,0.1744091);
   h_Before_stack_1->SetBinError(19,0.1857622);
   h_Before_stack_1->SetBinError(20,0.1857622);
   h_Before_stack_1->SetBinError(21,0.1715261);
   h_Before_stack_1->SetBinError(22,0.1677041);
   h_Before_stack_1->SetBinError(23,0.1741229);
   h_Before_stack_1->SetBinError(24,0.1907944);
   h_Before_stack_1->SetBinError(25,0.1662107);
   h_Before_stack_1->SetBinError(26,0.2041773);
   h_Before_stack_1->SetBinError(27,0.1931323);
   h_Before_stack_1->SetBinError(32,0.1907944);
   h_Before_stack_1->SetBinError(33,0.1892197);
   h_Before_stack_1->SetBinError(34,0.1844151);
   h_Before_stack_1->SetBinError(35,0.1923562);
   h_Before_stack_1->SetBinError(36,0.192874);
   h_Before_stack_1->SetBinError(37,0.1735492);
   h_Before_stack_1->SetBinError(38,0.1944191);
   h_Before_stack_1->SetBinError(39,0.1920968);
   h_Before_stack_1->SetBinError(40,0.1959519);
   h_Before_stack_1->SetEntries(11642);
   h_Before_stack_1->SetLineWidth(2);
   h_Before_stack_1->GetXaxis()->SetTitle("True Neutrino Interaction Vertex, Z (cm)");
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
   
   TH1D *h_After_stack_2 = new TH1D("h_After_stack_2"," (passed)",40,0,1000);
   h_After_stack_2->SetBinContent(1,0.5792249);
   h_After_stack_2->SetBinContent(2,1.088543);
   h_After_stack_2->SetBinContent(3,1.148463);
   h_After_stack_2->SetBinContent(4,1.577888);
   h_After_stack_2->SetBinContent(5,2.207047);
   h_After_stack_2->SetBinContent(6,2.995991);
   h_After_stack_2->SetBinContent(7,2.936071);
   h_After_stack_2->SetBinContent(8,3.255643);
   h_After_stack_2->SetBinContent(9,2.536606);
   h_After_stack_2->SetBinContent(10,2.956044);
   h_After_stack_2->SetBinContent(11,3.255643);
   h_After_stack_2->SetBinContent(12,2.906111);
   h_After_stack_2->SetBinContent(13,2.386806);
   h_After_stack_2->SetBinContent(14,3.375483);
   h_After_stack_2->SetBinContent(15,3.225683);
   h_After_stack_2->SetBinContent(16,2.766298);
   h_After_stack_2->SetBinContent(17,2.936071);
   h_After_stack_2->SetBinContent(18,2.736338);
   h_After_stack_2->SetBinContent(19,3.08587);
   h_After_stack_2->SetBinContent(20,3.065897);
   h_After_stack_2->SetBinContent(21,2.596525);
   h_After_stack_2->SetBinContent(22,2.496659);
   h_After_stack_2->SetBinContent(23,2.716365);
   h_After_stack_2->SetBinContent(24,3.35551);
   h_After_stack_2->SetBinContent(25,2.426753);
   h_After_stack_2->SetBinContent(26,3.595189);
   h_After_stack_2->SetBinContent(27,3.23567);
   h_After_stack_2->SetBinContent(32,2.986004);
   h_After_stack_2->SetBinContent(33,2.986004);
   h_After_stack_2->SetBinContent(34,3.015964);
   h_After_stack_2->SetBinContent(35,3.11583);
   h_After_stack_2->SetBinContent(36,3.14579);
   h_After_stack_2->SetBinContent(37,2.636472);
   h_After_stack_2->SetBinContent(38,3.105844);
   h_After_stack_2->SetBinContent(39,3.135804);
   h_After_stack_2->SetBinContent(40,2.676418);
   h_After_stack_2->SetBinError(1,0.07605595);
   h_After_stack_2->SetBinError(2,0.1042635);
   h_After_stack_2->SetBinError(3,0.1070947);
   h_After_stack_2->SetBinError(4,0.1255301);
   h_After_stack_2->SetBinError(5,0.148462);
   h_After_stack_2->SetBinError(6,0.1729736);
   h_After_stack_2->SetBinError(7,0.1712351);
   h_After_stack_2->SetBinError(8,0.1803134);
   h_After_stack_2->SetBinError(9,0.1591608);
   h_After_stack_2->SetBinError(10,0.1718166);
   h_After_stack_2->SetBinError(11,0.1803134);
   h_After_stack_2->SetBinError(12,0.1703592);
   h_After_stack_2->SetBinError(13,0.1543896);
   h_After_stack_2->SetBinError(14,0.1836021);
   h_After_stack_2->SetBinError(15,0.1794818);
   h_After_stack_2->SetBinError(16,0.1662107);
   h_After_stack_2->SetBinError(17,0.1712351);
   h_After_stack_2->SetBinError(18,0.1653082);
   h_After_stack_2->SetBinError(19,0.175549);
   h_After_stack_2->SetBinError(20,0.17498);
   h_After_stack_2->SetBinError(21,0.1610297);
   h_After_stack_2->SetBinError(22,0.1579026);
   h_After_stack_2->SetBinError(23,0.1647038);
   h_After_stack_2->SetBinError(24,0.1830581);
   h_After_stack_2->SetBinError(25,0.1556762);
   h_After_stack_2->SetBinError(26,0.1894831);
   h_After_stack_2->SetBinError(27,0.1797594);
   h_After_stack_2->SetBinError(32,0.1726851);
   h_After_stack_2->SetBinError(33,0.1726851);
   h_After_stack_2->SetBinError(34,0.1735492);
   h_After_stack_2->SetBinError(35,0.1763992);
   h_After_stack_2->SetBinError(36,0.1772452);
   h_After_stack_2->SetBinError(37,0.1622636);
   h_After_stack_2->SetBinError(38,0.1761162);
   h_After_stack_2->SetBinError(39,0.1769636);
   h_After_stack_2->SetBinError(40,0.1634883);
   h_After_stack_2->SetEntries(9838);
   h_After_stack_2->SetLineColor(3);
   h_After_stack_2->SetLineWidth(2);
   h_After_stack_2->GetXaxis()->SetTitle("True Neutrino Interaction Vertex, Z (cm)");
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
   TGaxis *gaxis = new TGaxis(1000,0,1000,5.218017,0,1.120643,510,"+L");
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
   
   Double_t Graph0_fx3003[36] = {
   12.5,
   37.5,
   62.5,
   87.5,
   112.5,
   137.5,
   162.5,
   187.5,
   212.5,
   237.5,
   262.5,
   287.5,
   312.5,
   337.5,
   362.5,
   387.5,
   412.5,
   437.5,
   462.5,
   487.5,
   512.5,
   537.5,
   562.5,
   587.5,
   612.5,
   637.5,
   662.5,
   787.5,
   812.5,
   837.5,
   862.5,
   887.5,
   912.5,
   937.5,
   962.5,
   987.5};
   Double_t Graph0_fy3003[36] = {
   2.935475,
   3.057431,
   3.13141,
   3.269737,
   3.636169,
   3.816616,
   4.074237,
   3.882211,
   3.778571,
   3.97192,
   4.026378,
   3.927464,
   3.97446,
   4.163544,
   4.154629,
   4.030585,
   4.110942,
   4.183011,
   4.158346,
   4.131431,
   4.103832,
   4.1279,
   4.166137,
   4.286321,
   4.084743,
   4.010186,
   4.033775,
   3.814315,
   3.878064,
   4.123736,
   3.915786,
   3.93224,
   4.070383,
   3.820845,
   3.951538,
   3.241249};
   Double_t Graph0_felx3003[36] = {
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
   Double_t Graph0_fely3003[36] = {
   0.2348848,
   0.1725518,
   0.1683407,
   0.1433326,
   0.1165648,
   0.09555052,
   0.0868542,
   0.08965105,
   0.1051734,
   0.09098806,
   0.08442064,
   0.09346975,
   0.1014994,
   0.07640433,
   0.07871594,
   0.09164426,
   0.08502544,
   0.08405941,
   0.0803468,
   0.08207735,
   0.09102342,
   0.09154781,
   0.08540907,
   0.06909518,
   0.09532686,
   0.08084371,
   0.08437772,
   0.09577915,
   0.09385203,
   0.08318693,
   0.09058331,
   0.08956978,
   0.09203565,
   0.09368661,
   0.08902337,
   0.1098404};
   Double_t Graph0_fehx3003[36] = {
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
   Double_t Graph0_fehy3003[36] = {
   0.2263427,
   0.1668184,
   0.162208,
   0.1378552,
   0.1105025,
   0.09020786,
   0.08002201,
   0.08442747,
   0.0990902,
   0.08476277,
   0.07849793,
   0.08737894,
   0.09377868,
   0.07001481,
   0.07207749,
   0.08465269,
   0.07798522,
   0.07605894,
   0.07338773,
   0.07522208,
   0.08311125,
   0.08315816,
   0.07745672,
   0.06202661,
   0.08699411,
   0.07555173,
   0.07838139,
   0.09043025,
   0.08817974,
   0.07626148,
   0.08495954,
   0.08391777,
   0.08445375,
   0.08851182,
   0.08325672,
   0.1067266};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(36,Graph0_fx3003,Graph0_fy3003,Graph0_felx3003,Graph0_fehx3003,Graph0_fely3003,Graph0_fehy3003);
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
   
   TH1F *Graph_Graph3003 = new TH1F("Graph_Graph3003","Graph",100,0,1085);
   Graph_Graph3003->SetMinimum(2.535815);
   Graph_Graph3003->SetMaximum(4.513123);
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
   entry=leg->AddEntry("NULL","NuMI RHC, 1.5 #times 10^{21} POT","h");
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
