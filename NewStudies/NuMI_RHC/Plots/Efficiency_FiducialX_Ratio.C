void Efficiency_FiducialX_Ratio()
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
   pad1->Range(-31.25,-0.7293611,281.25,6.564249);
   pad1->SetFillColor(0);
   pad1->SetBorderMode(0);
   pad1->SetBorderSize(2);
   pad1->SetTopMargin(0.01);
   pad1->SetFrameBorderMode(0);
   pad1->SetFrameBorderMode(0);
   
   THStack *hs = new THStack();
   hs->SetName("hs");
   hs->SetTitle("");
   hs->SetMaximum(6.491313);
   
   TH1F *hs_stack_1 = new TH1F("hs_stack_1","",30,0,250);
   hs_stack_1->SetMinimum(0);
   hs_stack_1->SetMaximum(6.491313);
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
   hs_stack_1->GetYaxis()->SetTitle("Entries/bin");
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
   
   
   TH1D *h_Before_stack_1 = new TH1D("h_Before_stack_1"," (total)",30,0,250);
   h_Before_stack_1->SetBinContent(2,4.054574);
   h_Before_stack_1->SetBinContent(3,4.444053);
   h_Before_stack_1->SetBinContent(4,4.493986);
   h_Before_stack_1->SetBinContent(5,5.193051);
   h_Before_stack_1->SetBinContent(6,4.414093);
   h_Before_stack_1->SetBinContent(7,4.553906);
   h_Before_stack_1->SetBinContent(8,4.224347);
   h_Before_stack_1->SetBinContent(9,4.513959);
   h_Before_stack_1->SetBinContent(10,3.814895);
   h_Before_stack_1->SetBinContent(11,4.204374);
   h_Before_stack_1->SetBinContent(12,3.874815);
   h_Before_stack_1->SetBinContent(13,4.503973);
   h_Before_stack_1->SetBinContent(14,4.973345);
   h_Before_stack_1->SetBinContent(15,4.30424);
   h_Before_stack_1->SetBinContent(16,4.084534);
   h_Before_stack_1->SetBinContent(17,3.774948);
   h_Before_stack_1->SetBinContent(18,4.224347);
   h_Before_stack_1->SetBinContent(19,3.824882);
   h_Before_stack_1->SetBinContent(20,4.36416);
   h_Before_stack_1->SetBinContent(21,3.705042);
   h_Before_stack_1->SetBinContent(22,4.014628);
   h_Before_stack_1->SetBinContent(23,3.625149);
   h_Before_stack_1->SetBinContent(24,3.08587);
   h_Before_stack_1->SetBinContent(25,3.675082);
   h_Before_stack_1->SetBinContent(26,3.914761);
   h_Before_stack_1->SetBinContent(27,4.314227);
   h_Before_stack_1->SetBinContent(28,2.966031);
   h_Before_stack_1->SetBinContent(29,3.365496);
   h_Before_stack_1->SetBinContent(30,1.757648);
   h_Before_stack_1->SetBinError(2,0.2012251);
   h_Before_stack_1->SetBinError(3,0.2106683);
   h_Before_stack_1->SetBinError(4,0.2118485);
   h_Before_stack_1->SetBinError(5,0.2277303);
   h_Before_stack_1->SetBinError(6,0.209957);
   h_Before_stack_1->SetBinError(7,0.2132562);
   h_Before_stack_1->SetBinError(8,0.2053948);
   h_Before_stack_1->SetBinError(9,0.2123188);
   h_Before_stack_1->SetBinError(10,0.195187);
   h_Before_stack_1->SetBinError(11,0.2049086);
   h_Before_stack_1->SetBinError(12,0.1967139);
   h_Before_stack_1->SetBinError(13,0.2120838);
   h_Before_stack_1->SetBinError(14,0.2228609);
   h_Before_stack_1->SetBinError(15,0.2073279);
   h_Before_stack_1->SetBinError(16,0.2019672);
   h_Before_stack_1->SetBinError(17,0.1941624);
   h_Before_stack_1->SetBinError(18,0.2053948);
   h_Before_stack_1->SetBinError(19,0.1954423);
   h_Before_stack_1->SetBinError(20,0.2087661);
   h_Before_stack_1->SetBinError(21,0.1923562);
   h_Before_stack_1->SetBinError(22,0.2002314);
   h_Before_stack_1->SetBinError(23,0.190271);
   h_Before_stack_1->SetBinError(24,0.175549);
   h_Before_stack_1->SetBinError(25,0.1915769);
   h_Before_stack_1->SetBinError(26,0.1977253);
   h_Before_stack_1->SetBinError(27,0.2075683);
   h_Before_stack_1->SetBinError(28,0.1721066);
   h_Before_stack_1->SetBinError(29,0.1833303);
   h_Before_stack_1->SetBinError(30,0.1324877);
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
   
   TH1D *h_After_stack_2 = new TH1D("h_After_stack_2"," (passed)",30,0,250);
   h_After_stack_2->SetBinContent(2,3.335536);
   h_After_stack_2->SetBinContent(3,3.685069);
   h_After_stack_2->SetBinContent(4,3.854841);
   h_After_stack_2->SetBinContent(5,4.24432);
   h_After_stack_2->SetBinContent(6,3.705042);
   h_After_stack_2->SetBinContent(7,3.844855);
   h_After_stack_2->SetBinContent(8,3.535269);
   h_After_stack_2->SetBinContent(9,3.864828);
   h_After_stack_2->SetBinContent(10,3.275617);
   h_After_stack_2->SetBinContent(11,3.655109);
   h_After_stack_2->SetBinContent(12,3.435403);
   h_After_stack_2->SetBinContent(13,3.894788);
   h_After_stack_2->SetBinContent(14,4.374146);
   h_After_stack_2->SetBinContent(15,3.665095);
   h_After_stack_2->SetBinContent(16,3.515296);
   h_After_stack_2->SetBinContent(17,3.29559);
   h_After_stack_2->SetBinContent(18,3.695055);
   h_After_stack_2->SetBinContent(19,3.395456);
   h_After_stack_2->SetBinContent(20,3.794922);
   h_After_stack_2->SetBinContent(21,3.135804);
   h_After_stack_2->SetBinContent(22,3.485336);
   h_After_stack_2->SetBinContent(23,3.045924);
   h_After_stack_2->SetBinContent(24,2.566565);
   h_After_stack_2->SetBinContent(25,3.14579);
   h_After_stack_2->SetBinContent(26,3.315563);
   h_After_stack_2->SetBinContent(27,3.774948);
   h_After_stack_2->SetBinContent(28,2.466699);
   h_After_stack_2->SetBinContent(29,2.896124);
   h_After_stack_2->SetBinContent(30,0.3495323);
   h_After_stack_2->SetBinError(2,0.1825124);
   h_After_stack_2->SetBinError(3,0.191837);
   h_After_stack_2->SetBinError(4,0.1962063);
   h_After_stack_2->SetBinError(5,0.2058798);
   h_After_stack_2->SetBinError(6,0.1923562);
   h_After_stack_2->SetBinError(7,0.1959519);
   h_After_stack_2->SetBinError(8,0.1878974);
   h_After_stack_2->SetBinError(9,0.1964603);
   h_After_stack_2->SetBinError(10,0.1808657);
   h_After_stack_2->SetBinError(11,0.1910556);
   h_After_stack_2->SetBinError(12,0.1852245);
   h_After_stack_2->SetBinError(13,0.1972203);
   h_After_stack_2->SetBinError(14,0.2090048);
   h_After_stack_2->SetBinError(15,0.1913164);
   h_After_stack_2->SetBinError(16,0.1873659);
   h_After_stack_2->SetBinError(17,0.1814162);
   h_After_stack_2->SetBinError(18,0.1920968);
   h_After_stack_2->SetBinError(19,0.1841445);
   h_After_stack_2->SetBinError(20,0.1946754);
   h_After_stack_2->SetBinError(21,0.1769636);
   h_After_stack_2->SetBinError(22,0.1865658);
   h_After_stack_2->SetBinError(23,0.1744091);
   h_After_stack_2->SetBinError(24,0.160098);
   h_After_stack_2->SetBinError(25,0.1772452);
   h_After_stack_2->SetBinError(26,0.1819652);
   h_After_stack_2->SetBinError(27,0.1941624);
   h_After_stack_2->SetBinError(28,0.1569523);
   h_After_stack_2->SetBinError(29,0.1700663);
   h_After_stack_2->SetBinError(30,0.05908173);
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
   TGaxis *gaxis = new TGaxis(250,0,250,6.491313,0,1.083709,510,"+L");
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
   
   Double_t Graph0_fx3001[29] = {
   12.5,
   20.83333,
   29.16667,
   37.5,
   45.83333,
   54.16667,
   62.5,
   70.83333,
   79.16667,
   87.5,
   95.83333,
   104.1667,
   112.5,
   120.8333,
   129.1667,
   137.5,
   145.8333,
   154.1667,
   162.5,
   170.8333,
   179.1667,
   187.5,
   195.8333,
   204.1667,
   212.5,
   220.8333,
   229.1667,
   237.5,
   245.8333};
   Double_t Graph0_fy3001[29] = {
   4.927655,
   4.966909,
   5.138006,
   4.895594,
   5.027725,
   5.057265,
   5.012827,
   5.128524,
   5.143163,
   5.207375,
   5.310636,
   5.179739,
   5.268229,
   5.100452,
   5.155125,
   5.229281,
   5.239396,
   5.317408,
   5.208612,
   5.069622,
   5.20019,
   5.032839,
   4.981894,
   5.127227,
   5.073082,
   5.241166,
   4.981502,
   5.154517,
   1.191174};
   Double_t Graph0_felx3001[29] = {
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
   Double_t Graph0_fely3001[29] = {
   0.1158557,
   0.1090204,
   0.1010942,
   0.1032069,
   0.1069157,
   0.1039806,
   0.1099865,
   0.1013,
   0.1097312,
   0.101186,
   0.09973092,
   0.09900822,
   0.08982627,
   0.1051055,
   0.1053513,
   0.105779,
   0.09927454,
   0.09999781,
   0.0991955,
   0.1150174,
   0.1040016,
   0.1180492,
   0.1307326,
   0.1126738,
   0.1116464,
   0.09810832,
   0.1334411,
   0.1164504,
   0.1717631};
   Double_t Graph0_fehx3001[29] = {
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
   Double_t Graph0_fehy3001[29] = {
   0.1095996,
   0.1031944,
   0.09483045,
   0.09840004,
   0.1008687,
   0.09803318,
   0.1037153,
   0.09509167,
   0.1023379,
   0.09427373,
   0.09187878,
   0.09263585,
   0.08381857,
   0.0986816,
   0.09840605,
   0.09800574,
   0.0922945,
   0.09201983,
   0.09253195,
   0.1076678,
   0.0967872,
   0.1106722,
   0.1222894,
   0.1050575,
   0.1046777,
   0.09126789,
   0.12466,
   0.1080286,
   0.1851674};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(29,Graph0_fx3001,Graph0_fy3001,Graph0_felx3001,Graph0_fehx3001,Graph0_fely3001,Graph0_fehy3001);
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
   
   TH1F *Graph_Graph3001 = new TH1F("Graph_Graph3001","Graph",100,0,269.1667);
   Graph_Graph3001->SetMinimum(0.5804093);
   Graph_Graph3001->SetMaximum(5.84843);
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
