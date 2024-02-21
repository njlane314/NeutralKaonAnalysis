void Efficiency_invariant_mass_fhc_FV_muon_pion_pair_MuonKE_All_Ratio()
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
   pad1->Range(-0.7500001,-1.119409,6.75,10.07468);
   pad1->SetFillColor(0);
   pad1->SetBorderMode(0);
   pad1->SetBorderSize(2);
   pad1->SetTopMargin(0.01);
   pad1->SetFrameBorderMode(0);
   pad1->SetFrameBorderMode(0);
   
   THStack *hs = new THStack();
   hs->SetName("hs");
   hs->SetTitle(";True Muon E_{k} (GeV);Events/bin");
   hs->SetMaximum(9.96274);
   
   TH1F *hs_stack_3 = new TH1F("hs_stack_3","",30,0,6);
   hs_stack_3->SetMinimum(0);
   hs_stack_3->SetMaximum(9.96274);
   hs_stack_3->SetDirectory(0);
   hs_stack_3->SetStats(0);

   ci = TColor::GetColor("#000099");
   hs_stack_3->SetLineColor(ci);
   hs_stack_3->GetXaxis()->SetTitle("True Muon E_{k} (GeV)");
   hs_stack_3->GetXaxis()->SetLabelFont(42);
   hs_stack_3->GetXaxis()->SetLabelSize(0.045);
   hs_stack_3->GetXaxis()->SetTitleSize(0.05);
   hs_stack_3->GetXaxis()->SetTitleOffset(0.93);
   hs_stack_3->GetXaxis()->SetTitleFont(42);
   hs_stack_3->GetYaxis()->SetTitle("Events/bin");
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
   
   
   TH1D *h_Before_stack_1 = new TH1D("h_Before_stack_1"," (total)",30,0,6);
   h_Before_stack_1->SetBinContent(1,6.360213);
   h_Before_stack_1->SetBinContent(2,7.970192);
   h_Before_stack_1->SetBinContent(3,6.222063);
   h_Before_stack_1->SetBinContent(4,5.12749);
   h_Before_stack_1->SetBinContent(5,3.76193);
   h_Before_stack_1->SetBinContent(6,3.714109);
   h_Before_stack_1->SetBinContent(7,2.773627);
   h_Before_stack_1->SetBinContent(8,2.08819);
   h_Before_stack_1->SetBinContent(9,2.173206);
   h_Before_stack_1->SetBinContent(10,1.376186);
   h_Before_stack_1->SetBinContent(11,1.636546);
   h_Before_stack_1->SetBinContent(12,1.08926);
   h_Before_stack_1->SetBinContent(13,1.238036);
   h_Before_stack_1->SetBinContent(14,0.8235865);
   h_Before_stack_1->SetBinContent(15,0.7970192);
   h_Before_stack_1->SetBinContent(16,0.4941519);
   h_Before_stack_1->SetBinContent(17,0.4357038);
   h_Before_stack_1->SetBinContent(18,0.1700308);
   h_Before_stack_1->SetBinContent(19,0.3028673);
   h_Before_stack_1->SetBinContent(20,0.2019115);
   h_Before_stack_1->SetBinContent(21,0.1647173);
   h_Before_stack_1->SetBinContent(22,0.1912846);
   h_Before_stack_1->SetBinContent(23,0.1222096);
   h_Before_stack_1->SetBinContent(24,0.1062692);
   h_Before_stack_1->SetBinContent(25,0.08501538);
   h_Before_stack_1->SetBinContent(26,0.03188077);
   h_Before_stack_1->SetBinContent(27,0.03719423);
   h_Before_stack_1->SetBinContent(28,0.1168961);
   h_Before_stack_1->SetBinContent(29,0.1328365);
   h_Before_stack_1->SetBinContent(31,0.2869269);
   h_Before_stack_1->SetBinError(1,0.1838335);
   h_Before_stack_1->SetBinError(2,0.2057895);
   h_Before_stack_1->SetBinError(3,0.181826);
   h_Before_stack_1->SetBinError(4,0.1650597);
   h_Before_stack_1->SetBinError(5,0.141382);
   h_Before_stack_1->SetBinError(6,0.1404805);
   h_Before_stack_1->SetBinError(7,0.1213983);
   h_Before_stack_1->SetBinError(8,0.1053353);
   h_Before_stack_1->SetBinError(9,0.1074581);
   h_Before_stack_1->SetBinError(10,0.08551206);
   h_Before_stack_1->SetBinError(11,0.09325086);
   h_Before_stack_1->SetBinError(12,0.07607718);
   h_Before_stack_1->SetBinError(13,0.08110646);
   h_Before_stack_1->SetBinError(14,0.06615206);
   h_Before_stack_1->SetBinError(15,0.06507634);
   h_Before_stack_1->SetBinError(16,0.05124116);
   h_Before_stack_1->SetBinError(17,0.04811544);
   h_Before_stack_1->SetBinError(18,0.03005747);
   h_Before_stack_1->SetBinError(19,0.04011575);
   h_Before_stack_1->SetBinError(20,0.03275437);
   h_Before_stack_1->SetBinError(21,0.0295841);
   h_Before_stack_1->SetBinError(22,0.03188077);
   h_Before_stack_1->SetBinError(23,0.02548246);
   h_Before_stack_1->SetBinError(24,0.02376252);
   h_Before_stack_1->SetBinError(25,0.02125384);
   h_Before_stack_1->SetBinError(26,0.01301527);
   h_Before_stack_1->SetBinError(27,0.0140581);
   h_Before_stack_1->SetBinError(28,0.02492234);
   h_Before_stack_1->SetBinError(29,0.02656731);
   h_Before_stack_1->SetBinError(31,0.03904581);
   h_Before_stack_1->SetEntries(9506);
   h_Before_stack_1->SetLineWidth(2);
   h_Before_stack_1->GetXaxis()->SetTitle("True Muon KE (GeV)");
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
   
   TH1D *h_After_stack_2 = new TH1D("h_After_stack_2"," (passed)",30,0,6);
   h_After_stack_2->SetBinContent(1,3.395302);
   h_After_stack_2->SetBinContent(2,4.968086);
   h_After_stack_2->SetBinContent(3,4.016977);
   h_After_stack_2->SetBinContent(4,3.262465);
   h_After_stack_2->SetBinContent(5,2.577029);
   h_After_stack_2->SetBinContent(6,2.295415);
   h_After_stack_2->SetBinContent(7,1.822517);
   h_After_stack_2->SetBinContent(8,1.264604);
   h_After_stack_2->SetBinContent(9,1.418694);
   h_After_stack_2->SetBinContent(10,0.8448403);
   h_After_stack_2->SetBinContent(11,1.1052);
   h_After_stack_2->SetBinContent(12,0.6960634);
   h_After_stack_2->SetBinContent(13,0.7545115);
   h_After_stack_2->SetBinContent(14,0.5313461);
   h_After_stack_2->SetBinContent(15,0.4782115);
   h_After_stack_2->SetBinContent(16,0.334748);
   h_After_stack_2->SetBinContent(17,0.3241211);
   h_After_stack_2->SetBinContent(18,0.0956423);
   h_After_stack_2->SetBinContent(19,0.1753442);
   h_After_stack_2->SetBinContent(20,0.1700308);
   h_After_stack_2->SetBinContent(21,0.1222096);
   h_After_stack_2->SetBinContent(22,0.1328365);
   h_After_stack_2->SetBinContent(23,0.05844807);
   h_After_stack_2->SetBinContent(24,0.03719423);
   h_After_stack_2->SetBinContent(25,0.05844807);
   h_After_stack_2->SetBinContent(26,0.01594038);
   h_After_stack_2->SetBinContent(27,0.02656731);
   h_After_stack_2->SetBinContent(28,0.07438846);
   h_After_stack_2->SetBinContent(29,0.07438846);
   h_After_stack_2->SetBinContent(31,0.207225);
   h_After_stack_2->SetBinError(1,0.1343161);
   h_After_stack_2->SetBinError(2,0.1624738);
   h_After_stack_2->SetBinError(3,0.146096);
   h_After_stack_2->SetBinError(4,0.1316624);
   h_After_stack_2->SetBinError(5,0.1170168);
   h_After_stack_2->SetBinError(6,0.1104382);
   h_After_stack_2->SetBinError(7,0.09840668);
   h_After_stack_2->SetBinError(8,0.08197209);
   h_After_stack_2->SetBinError(9,0.08682267);
   h_After_stack_2->SetBinError(10,0.06700019);
   h_After_stack_2->SetBinError(11,0.07663183);
   h_After_stack_2->SetBinError(12,0.06081534);
   h_After_stack_2->SetBinError(13,0.0633172);
   h_After_stack_2->SetBinError(14,0.05313461);
   h_After_stack_2->SetBinError(15,0.05040792);
   h_After_stack_2->SetBinError(16,0.04217429);
   h_After_stack_2->SetBinError(17,0.04149946);
   h_After_stack_2->SetBinError(18,0.02254311);
   h_After_stack_2->SetBinError(19,0.03052351);
   h_After_stack_2->SetBinError(20,0.03005747);
   h_After_stack_2->SetBinError(21,0.02548246);
   h_After_stack_2->SetBinError(22,0.02656731);
   h_After_stack_2->SetBinError(23,0.01762276);
   h_After_stack_2->SetBinError(24,0.0140581);
   h_After_stack_2->SetBinError(25,0.01762276);
   h_After_stack_2->SetBinError(26,0.009203185);
   h_After_stack_2->SetBinError(27,0.01188126);
   h_After_stack_2->SetBinError(28,0.01988115);
   h_After_stack_2->SetBinError(29,0.01988115);
   h_After_stack_2->SetBinError(31,0.03318255);
   h_After_stack_2->SetEntries(5948);
   h_After_stack_2->SetLineColor(3);
   h_After_stack_2->SetLineWidth(2);
   h_After_stack_2->GetXaxis()->SetTitle("True Muon KE (GeV)");
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
   TGaxis *gaxis = new TGaxis(6,0,6,9.96274,0,1.073133,510,"+L");
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
   
   Double_t Graph0_fx3003[29] = {
   0.1,
   0.3,
   0.5,
   0.7,
   0.9,
   1.1,
   1.3,
   1.5,
   1.7,
   1.9,
   2.1,
   2.3,
   2.5,
   2.7,
   2.9,
   3.1,
   3.3,
   3.5,
   3.7,
   3.9,
   4.1,
   4.3,
   4.5,
   4.7,
   4.9,
   5.1,
   5.3,
   5.5,
   5.7};
   Double_t Graph0_fy3003[29] = {
   4.956008,
   5.786895,
   5.993633,
   5.906991,
   6.359658,
   5.737621,
   6.100268,
   5.622244,
   6.060567,
   5.699315,
   6.269572,
   5.932568,
   5.657932,
   5.989542,
   5.570274,
   6.289019,
   6.906234,
   5.222132,
   5.374825,
   7.817928,
   6.887973,
   6.447076,
   4.440073,
   3.249326,
   6.382605,
   4.641895,
   6.631278,
   5.907866,
   5.198922};
   Double_t Graph0_felx3003[29] = {
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
   Double_t Graph0_fely3003[29] = {
   0.1331806,
   0.1159342,
   0.1297056,
   0.1436949,
   0.1625555,
   0.1704611,
   0.1933018,
   0.2286763,
   0.2191066,
   0.2809232,
   0.2490504,
   0.3123688,
   0.2967078,
   0.3583082,
   0.3709385,
   0.4545661,
   0.4582797,
   0.796927,
   0.6017794,
   0.5911056,
   0.7516836,
   0.7229682,
   0.9169449,
   0.8984982,
   1.077735,
   1.62929,
   1.558871,
   0.9430433,
   0.8958315};
   Double_t Graph0_fehx3003[29] = {
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
   Double_t Graph0_fehy3003[29] = {
   0.1328351,
   0.1149289,
   0.1281858,
   0.1419694,
   0.159364,
   0.1683993,
   0.1896301,
   0.2254017,
   0.2145523,
   0.2755761,
   0.2421205,
   0.304137,
   0.2910011,
   0.3469709,
   0.3628728,
   0.4316334,
   0.422565,
   0.7742858,
   0.5853388,
   0.4843548,
   0.6608372,
   0.659805,
   0.927674,
   0.9829679,
   0.9480136,
   1.62929,
   1.255437,
   0.8727588,
   0.8684193};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(29,Graph0_fx3003,Graph0_fy3003,Graph0_felx3003,Graph0_fehx3003,Graph0_fely3003,Graph0_fehy3003);
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
   
   TH1F *Graph_Graph3003 = new TH1F("Graph_Graph3003","Graph",100,0,6.26);
   Graph_Graph3003->SetMinimum(1.755683);
   Graph_Graph3003->SetMaximum(8.897428);
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
