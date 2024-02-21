void Efficiency_invariant_mass_fhc_FV_muon_pion_pair_MuonTrueTheta_All_Ratio()
{
//=========Macro generated from canvas: c1/c1
//=========  (Mon Feb 12 09:00:55 2024) by ROOT version 6.12/06
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
   pad1->Range(-0.3926875,-0.9037362,3.534188,8.133625);
   pad1->SetFillColor(0);
   pad1->SetBorderMode(0);
   pad1->SetBorderSize(2);
   pad1->SetTopMargin(0.01);
   pad1->SetFrameBorderMode(0);
   pad1->SetFrameBorderMode(0);
   
   THStack *hs = new THStack();
   hs->SetName("hs");
   hs->SetTitle(";True Muon #theta;Events/bin");
   hs->SetMaximum(8.043252);
   
   TH1F *hs_stack_4 = new TH1F("hs_stack_4","",30,0,3.1415);
   hs_stack_4->SetMinimum(0);
   hs_stack_4->SetMaximum(8.043252);
   hs_stack_4->SetDirectory(0);
   hs_stack_4->SetStats(0);

   ci = TColor::GetColor("#000099");
   hs_stack_4->SetLineColor(ci);
   hs_stack_4->GetXaxis()->SetTitle("True Muon #theta");
   hs_stack_4->GetXaxis()->SetLabelFont(42);
   hs_stack_4->GetXaxis()->SetLabelSize(0.045);
   hs_stack_4->GetXaxis()->SetTitleSize(0.05);
   hs_stack_4->GetXaxis()->SetTitleOffset(0.93);
   hs_stack_4->GetXaxis()->SetTitleFont(42);
   hs_stack_4->GetYaxis()->SetTitle("Events/bin");
   hs_stack_4->GetYaxis()->SetLabelFont(42);
   hs_stack_4->GetYaxis()->SetLabelSize(0.045);
   hs_stack_4->GetYaxis()->SetTitleSize(0.05);
   hs_stack_4->GetYaxis()->SetTitleOffset(1.06);
   hs_stack_4->GetYaxis()->SetTitleFont(42);
   hs_stack_4->GetZaxis()->SetLabelFont(42);
   hs_stack_4->GetZaxis()->SetLabelSize(0.035);
   hs_stack_4->GetZaxis()->SetTitleSize(0.035);
   hs_stack_4->GetZaxis()->SetTitleFont(42);
   hs->SetHistogram(hs_stack_4);
   
   
   TH1D *h_Before_stack_1 = new TH1D("h_Before_stack_1"," (total)",30,0,3.1415);
   h_Before_stack_1->SetBinContent(1,0.5313461);
   h_Before_stack_1->SetBinContent(2,3.522825);
   h_Before_stack_1->SetBinContent(3,6.041405);
   h_Before_stack_1->SetBinContent(4,6.434601);
   h_Before_stack_1->SetBinContent(5,6.275198);
   h_Before_stack_1->SetBinContent(6,4.798055);
   h_Before_stack_1->SetBinContent(7,4.877757);
   h_Before_stack_1->SetBinContent(8,3.544079);
   h_Before_stack_1->SetBinContent(9,2.890523);
   h_Before_stack_1->SetBinContent(10,1.960667);
   h_Before_stack_1->SetBinContent(11,1.81189);
   h_Before_stack_1->SetBinContent(12,1.248663);
   h_Before_stack_1->SetBinContent(13,1.020185);
   h_Before_stack_1->SetBinContent(14,0.8979749);
   h_Before_stack_1->SetBinContent(15,0.8820345);
   h_Before_stack_1->SetBinContent(16,0.8129595);
   h_Before_stack_1->SetBinContent(17,0.4941519);
   h_Before_stack_1->SetBinContent(18,0.3719423);
   h_Before_stack_1->SetBinContent(19,0.4941519);
   h_Before_stack_1->SetBinContent(20,0.1806577);
   h_Before_stack_1->SetBinContent(21,0.2019115);
   h_Before_stack_1->SetBinContent(22,0.1859711);
   h_Before_stack_1->SetBinContent(23,0.1115827);
   h_Before_stack_1->SetBinContent(24,0.1753442);
   h_Before_stack_1->SetBinContent(25,0.07970192);
   h_Before_stack_1->SetBinContent(26,0.08501538);
   h_Before_stack_1->SetBinContent(27,0.02125384);
   h_Before_stack_1->SetBinContent(28,0.05313461);
   h_Before_stack_1->SetBinContent(29,0.02656731);
   h_Before_stack_1->SetBinError(1,0.05313461);
   h_Before_stack_1->SetBinError(2,0.1368152);
   h_Before_stack_1->SetBinError(3,0.1791669);
   h_Before_stack_1->SetBinError(4,0.1849054);
   h_Before_stack_1->SetBinError(5,0.1826007);
   h_Before_stack_1->SetBinError(6,0.1596693);
   h_Before_stack_1->SetBinError(7,0.16099);
   h_Before_stack_1->SetBinError(8,0.1372273);
   h_Before_stack_1->SetBinError(9,0.1239301);
   h_Before_stack_1->SetBinError(10,0.1020683);
   h_Before_stack_1->SetBinError(11,0.09811936);
   h_Before_stack_1->SetBinError(12,0.08145382);
   h_Before_stack_1->SetBinError(13,0.07362548);
   h_Before_stack_1->SetBinError(14,0.06907499);
   h_Before_stack_1->SetBinError(15,0.06845916);
   h_Before_stack_1->SetBinError(16,0.06572388);
   h_Before_stack_1->SetBinError(17,0.05124116);
   h_Before_stack_1->SetBinError(18,0.0444556);
   h_Before_stack_1->SetBinError(19,0.05124116);
   h_Before_stack_1->SetBinError(20,0.03098254);
   h_Before_stack_1->SetBinError(21,0.03275437);
   h_Before_stack_1->SetBinError(22,0.03143486);
   h_Before_stack_1->SetBinError(23,0.02434934);
   h_Before_stack_1->SetBinError(24,0.03052351);
   h_Before_stack_1->SetBinError(25,0.02057895);
   h_Before_stack_1->SetBinError(26,0.02125384);
   h_Before_stack_1->SetBinError(27,0.01062692);
   h_Before_stack_1->SetBinError(28,0.01680264);
   h_Before_stack_1->SetBinError(29,0.01188126);
   h_Before_stack_1->SetEntries(9506);
   h_Before_stack_1->SetLineWidth(2);
   h_Before_stack_1->GetXaxis()->SetTitle("Muon True #theta");
   h_Before_stack_1->GetXaxis()->SetLabelFont(42);
   h_Before_stack_1->GetXaxis()->SetLabelSize(0.035);
   h_Before_stack_1->GetXaxis()->SetTitleSize(0.035);
   h_Before_stack_1->GetXaxis()->SetTitleFont(42);
   h_Before_stack_1->GetYaxis()->SetTitle("Selected/All");
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
   
   TH1D *h_After_stack_2 = new TH1D("h_After_stack_2"," (passed)",30,0,3.1415);
   h_After_stack_2->SetBinContent(1,0.3719423);
   h_After_stack_2->SetBinContent(2,2.337923);
   h_After_stack_2->SetBinContent(3,3.815065);
   h_After_stack_2->SetBinContent(4,4.229515);
   h_After_stack_2->SetBinContent(5,3.889454);
   h_After_stack_2->SetBinContent(6,3.161509);
   h_After_stack_2->SetBinContent(7,3.150882);
   h_After_stack_2->SetBinContent(8,2.221027);
   h_After_stack_2->SetBinContent(9,1.742815);
   h_After_stack_2->SetBinContent(10,1.163648);
   h_After_stack_2->SetBinContent(11,1.110513);
   h_After_stack_2->SetBinContent(12,0.7279442);
   h_After_stack_2->SetBinContent(13,0.5844807);
   h_After_stack_2->SetBinContent(14,0.5366596);
   h_After_stack_2->SetBinContent(15,0.4941519);
   h_After_stack_2->SetBinContent(16,0.3878827);
   h_After_stack_2->SetBinContent(17,0.3560019);
   h_After_stack_2->SetBinContent(18,0.2337923);
   h_After_stack_2->SetBinContent(19,0.2763);
   h_After_stack_2->SetBinContent(20,0.1168961);
   h_After_stack_2->SetBinContent(21,0.0956423);
   h_After_stack_2->SetBinContent(22,0.07970192);
   h_After_stack_2->SetBinContent(23,0.05313461);
   h_After_stack_2->SetBinContent(24,0.1115827);
   h_After_stack_2->SetBinContent(25,0.02125384);
   h_After_stack_2->SetBinContent(26,0.04250769);
   h_After_stack_2->SetBinContent(27,0.01594038);
   h_After_stack_2->SetBinContent(28,0.005313461);
   h_After_stack_2->SetBinContent(29,0.005313461);
   h_After_stack_2->SetBinError(1,0.0444556);
   h_After_stack_2->SetBinError(2,0.1114561);
   h_After_stack_2->SetBinError(3,0.142377);
   h_After_stack_2->SetBinError(4,0.1499112);
   h_After_stack_2->SetBinError(5,0.1437583);
   h_After_stack_2->SetBinError(6,0.1296092);
   h_After_stack_2->SetBinError(7,0.1293912);
   h_After_stack_2->SetBinError(8,0.108634);
   h_After_stack_2->SetBinError(9,0.09623087);
   h_After_stack_2->SetBinError(10,0.07863204);
   h_After_stack_2->SetBinError(11,0.07681582);
   h_After_stack_2->SetBinError(12,0.06219247);
   h_After_stack_2->SetBinError(13,0.05572805);
   h_After_stack_2->SetBinError(14,0.05339962);
   h_After_stack_2->SetBinError(15,0.05124116);
   h_After_stack_2->SetBinError(16,0.04539823);
   h_After_stack_2->SetBinError(17,0.04349255);
   h_After_stack_2->SetBinError(18,0.03524551);
   h_After_stack_2->SetBinError(19,0.03831591);
   h_After_stack_2->SetBinError(20,0.02492234);
   h_After_stack_2->SetBinError(21,0.02254311);
   h_After_stack_2->SetBinError(22,0.02057895);
   h_After_stack_2->SetBinError(23,0.01680264);
   h_After_stack_2->SetBinError(24,0.02434934);
   h_After_stack_2->SetBinError(25,0.01062692);
   h_After_stack_2->SetBinError(26,0.01502874);
   h_After_stack_2->SetBinError(27,0.009203185);
   h_After_stack_2->SetBinError(28,0.005313461);
   h_After_stack_2->SetBinError(29,0.005313461);
   h_After_stack_2->SetEntries(5948);
   h_After_stack_2->SetLineColor(3);
   h_After_stack_2->SetLineWidth(2);
   h_After_stack_2->GetXaxis()->SetTitle("Muon True #theta");
   h_After_stack_2->GetXaxis()->SetLabelFont(42);
   h_After_stack_2->GetXaxis()->SetLabelSize(0.035);
   h_After_stack_2->GetXaxis()->SetTitleSize(0.035);
   h_After_stack_2->GetXaxis()->SetTitleFont(42);
   h_After_stack_2->GetYaxis()->SetTitle("Selected/All");
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
   TGaxis *gaxis = new TGaxis(3.1415,0,3.1415,8.043252,0,1.081577,510,"+L");
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
   
   Double_t Graph0_fx3004[29] = {
   0.05235833,
   0.157075,
   0.2617917,
   0.3665083,
   0.471225,
   0.5759417,
   0.6806583,
   0.785375,
   0.8900917,
   0.9948083,
   1.099525,
   1.204242,
   1.308958,
   1.413675,
   1.518392,
   1.623108,
   1.727825,
   1.832542,
   1.937258,
   2.041975,
   2.146692,
   2.251408,
   2.356125,
   2.460842,
   2.565558,
   2.670275,
   2.774992,
   2.879708,
   2.984425};
   Double_t Graph0_fy3004[29] = {
   5.205617,
   4.935297,
   4.696109,
   4.888134,
   4.609304,
   4.900082,
   4.803814,
   4.660415,
   4.483829,
   4.413589,
   4.557913,
   4.335377,
   4.260549,
   4.444356,
   4.166285,
   3.548179,
   5.357547,
   4.674431,
   4.158096,
   4.811915,
   3.522598,
   3.187112,
   3.541236,
   4.732379,
   1.983092,
   3.718298,
   5.577446,
   0.7436595,
   1.487319};
   Double_t Graph0_felx3004[29] = {
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
   Double_t Graph0_fely3004[29] = {
   0.3454915,
   0.1367109,
   0.1062773,
   0.1014184,
   0.1048744,
   0.1174099,
   0.1173822,
   0.1392316,
   0.1557875,
   0.1898342,
   0.1961297,
   0.2385931,
   0.2645014,
   0.2801614,
   0.2849797,
   0.2959756,
   0.3523323,
   0.4301025,
   0.379802,
   0.6099053,
   0.5806174,
   0.5922889,
   0.7649727,
   0.6211982,
   0.7304842,
   0.8713457,
   1.567025,
   0.5050509,
   0.9363022};
   Double_t Graph0_fehx3004[29] = {
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
   Double_t Graph0_fehy3004[29] = {
   0.3262034,
   0.1342967,
   0.1051451,
   0.1001465,
   0.1038811,
   0.1156875,
   0.1158259,
   0.137374,
   0.1539379,
   0.1873614,
   0.1928998,
   0.2351567,
   0.2608116,
   0.2745552,
   0.2814591,
   0.2974248,
   0.3294944,
   0.412532,
   0.3736841,
   0.5695571,
   0.587101,
   0.611328,
   0.7752108,
   0.582718,
   0.8682008,
   0.8713457,
   1.125263,
   0.8737363,
   1.397135};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(29,Graph0_fx3004,Graph0_fy3004,Graph0_felx3004,Graph0_fehx3004,Graph0_fely3004,Graph0_fehy3004);
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
   
   TH1F *Graph_Graph3004 = new TH1F("Graph_Graph3004","Graph",100,0,3.277632);
   Graph_Graph3004->SetMinimum(0.2147478);
   Graph_Graph3004->SetMaximum(7.34912);
   Graph_Graph3004->SetDirectory(0);
   Graph_Graph3004->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph3004->SetLineColor(ci);
   Graph_Graph3004->GetXaxis()->SetLabelFont(42);
   Graph_Graph3004->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph3004->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph3004->GetXaxis()->SetTitleFont(42);
   Graph_Graph3004->GetYaxis()->SetLabelFont(42);
   Graph_Graph3004->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph3004->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph3004->GetYaxis()->SetTitleOffset(0);
   Graph_Graph3004->GetYaxis()->SetTitleFont(42);
   Graph_Graph3004->GetZaxis()->SetLabelFont(42);
   Graph_Graph3004->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph3004->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph3004->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph3004);
   
   grae->Draw("p ");
   
   leg = new TLegend(0.54,0.82,0.89,0.9,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextAlign(32);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   entry=leg->AddEntry("NULL","NuMI RHC, 12.5 #times 10^{20} POT","h");
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
