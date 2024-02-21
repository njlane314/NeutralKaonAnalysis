void Efficiency_invariant_mass_fhc_FV_muon_pion_pair_MuonDetectorPhi_All_Ratio()
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
   pad1->Range(-3.926875,-0.6074659,3.926875,5.467193);
   pad1->SetFillColor(0);
   pad1->SetBorderMode(0);
   pad1->SetBorderSize(2);
   pad1->SetTopMargin(0.01);
   pad1->SetFrameBorderMode(0);
   pad1->SetFrameBorderMode(0);
   
   THStack *hs = new THStack();
   hs->SetName("hs");
   hs->SetTitle(";Detector-Muon #phi;Events/bin");
   hs->SetMaximum(5.406447);
   
   TH1F *hs_stack_6 = new TH1F("hs_stack_6","",30,-3.1415,3.1415);
   hs_stack_6->SetMinimum(0);
   hs_stack_6->SetMaximum(5.406447);
   hs_stack_6->SetDirectory(0);
   hs_stack_6->SetStats(0);

   ci = TColor::GetColor("#000099");
   hs_stack_6->SetLineColor(ci);
   hs_stack_6->GetXaxis()->SetTitle("Detector-Muon #phi");
   hs_stack_6->GetXaxis()->SetLabelFont(42);
   hs_stack_6->GetXaxis()->SetLabelSize(0.045);
   hs_stack_6->GetXaxis()->SetTitleSize(0.05);
   hs_stack_6->GetXaxis()->SetTitleOffset(0.93);
   hs_stack_6->GetXaxis()->SetTitleFont(42);
   hs_stack_6->GetYaxis()->SetTitle("Events/bin");
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
   
   
   TH1D *h_Before_stack_1 = new TH1D("h_Before_stack_1"," (total)",30,-3.1415,3.1415);
   h_Before_stack_1->SetBinContent(1,0.6641826);
   h_Before_stack_1->SetBinContent(2,0.4675846);
   h_Before_stack_1->SetBinContent(3,0.5844807);
   h_Before_stack_1->SetBinContent(4,0.5685403);
   h_Before_stack_1->SetBinContent(5,0.5632269);
   h_Before_stack_1->SetBinContent(6,0.7651384);
   h_Before_stack_1->SetBinContent(7,0.8501538);
   h_Before_stack_1->SetBinContent(8,0.6429288);
   h_Before_stack_1->SetBinContent(9,1.317738);
   h_Before_stack_1->SetBinContent(10,1.546217);
   h_Before_stack_1->SetBinContent(11,2.295415);
   h_Before_stack_1->SetBinContent(12,2.555775);
   h_Before_stack_1->SetBinContent(13,3.916021);
   h_Before_stack_1->SetBinContent(14,4.149813);
   h_Before_stack_1->SetBinContent(15,4.00635);
   h_Before_stack_1->SetBinContent(16,3.0393);
   h_Before_stack_1->SetBinContent(17,4.325157);
   h_Before_stack_1->SetBinContent(18,3.363421);
   h_Before_stack_1->SetBinContent(19,3.267779);
   h_Before_stack_1->SetBinContent(20,1.939413);
   h_Before_stack_1->SetBinContent(21,1.434634);
   h_Before_stack_1->SetBinContent(22,1.51965);
   h_Before_stack_1->SetBinContent(23,1.487769);
   h_Before_stack_1->SetBinContent(24,0.9298557);
   h_Before_stack_1->SetBinContent(25,1.126454);
   h_Before_stack_1->SetBinContent(26,0.7226307);
   h_Before_stack_1->SetBinContent(27,0.6163615);
   h_Before_stack_1->SetBinContent(28,0.4463307);
   h_Before_stack_1->SetBinContent(29,0.2550461);
   h_Before_stack_1->SetBinContent(30,0.6641826);
   h_Before_stack_1->SetBinError(1,0.0594063);
   h_Before_stack_1->SetBinError(2,0.04984468);
   h_Before_stack_1->SetBinError(3,0.05572805);
   h_Before_stack_1->SetBinError(4,0.05496287);
   h_Before_stack_1->SetBinError(5,0.05470543);
   h_Before_stack_1->SetBinError(6,0.06376153);
   h_Before_stack_1->SetBinError(7,0.06721056);
   h_Before_stack_1->SetBinError(8,0.05844807);
   h_Before_stack_1->SetBinError(9,0.08367647);
   h_Before_stack_1->SetBinError(10,0.09064086);
   h_Before_stack_1->SetBinError(11,0.1104382);
   h_Before_stack_1->SetBinError(12,0.1165333);
   h_Before_stack_1->SetBinError(13,0.1442485);
   h_Before_stack_1->SetBinError(14,0.148492);
   h_Before_stack_1->SetBinError(15,0.1459026);
   h_Before_stack_1->SetBinError(16,0.1270795);
   h_Before_stack_1->SetBinError(17,0.1515967);
   h_Before_stack_1->SetBinError(18,0.133684);
   h_Before_stack_1->SetBinError(19,0.1317695);
   h_Before_stack_1->SetBinError(20,0.1015135);
   h_Before_stack_1->SetBinError(21,0.08730907);
   h_Before_stack_1->SetBinError(22,0.08985878);
   h_Before_stack_1->SetBinError(23,0.08891121);
   h_Before_stack_1->SetBinError(24,0.07029048);
   h_Before_stack_1->SetBinError(25,0.07736516);
   h_Before_stack_1->SetBinError(26,0.06196507);
   h_Before_stack_1->SetBinError(27,0.05722773);
   h_Before_stack_1->SetBinError(28,0.04869868);
   h_Before_stack_1->SetBinError(29,0.03681274);
   h_Before_stack_1->SetBinError(30,0.0594063);
   h_Before_stack_1->SetEntries(9506);
   h_Before_stack_1->SetLineWidth(2);
   h_Before_stack_1->GetXaxis()->SetTitle("Muon Detector #theta");
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
   
   TH1D *h_After_stack_2 = new TH1D("h_After_stack_2"," (passed)",30,-3.1415,3.1415);
   h_After_stack_2->SetBinContent(1,0.4463307);
   h_After_stack_2->SetBinContent(2,0.2391057);
   h_After_stack_2->SetBinContent(3,0.3560019);
   h_After_stack_2->SetBinContent(4,0.3294346);
   h_After_stack_2->SetBinContent(5,0.345375);
   h_After_stack_2->SetBinContent(6,0.483525);
   h_After_stack_2->SetBinContent(7,0.5207192);
   h_After_stack_2->SetBinContent(8,0.3613154);
   h_After_stack_2->SetBinContent(9,0.8288999);
   h_After_stack_2->SetBinContent(10,0.8714076);
   h_After_stack_2->SetBinContent(11,1.562158);
   h_After_stack_2->SetBinContent(12,1.694994);
   h_After_stack_2->SetBinContent(13,2.492013);
   h_After_stack_2->SetBinContent(14,2.667357);
   h_After_stack_2->SetBinContent(15,2.62485);
   h_After_stack_2->SetBinContent(16,1.960667);
   h_After_stack_2->SetBinContent(17,2.800194);
   h_After_stack_2->SetBinContent(18,2.066936);
   h_After_stack_2->SetBinContent(19,1.870338);
   h_After_stack_2->SetBinContent(20,1.147708);
   h_After_stack_2->SetBinContent(21,0.8767211);
   h_After_stack_2->SetBinContent(22,0.818273);
   h_After_stack_2->SetBinContent(23,0.8342134);
   h_After_stack_2->SetBinContent(24,0.5791673);
   h_After_stack_2->SetBinContent(25,0.7545115);
   h_After_stack_2->SetBinContent(26,0.4463307);
   h_After_stack_2->SetBinContent(27,0.4250769);
   h_After_stack_2->SetBinContent(28,0.2444192);
   h_After_stack_2->SetBinContent(29,0.2019115);
   h_After_stack_2->SetBinContent(30,0.4888384);
   h_After_stack_2->SetBinError(1,0.04869868);
   h_After_stack_2->SetBinError(2,0.03564378);
   h_After_stack_2->SetBinError(3,0.04349255);
   h_After_stack_2->SetBinError(4,0.04183823);
   h_After_stack_2->SetBinError(5,0.04283849);
   h_After_stack_2->SetBinError(6,0.05068719);
   h_After_stack_2->SetBinError(7,0.05260058);
   h_After_stack_2->SetBinError(8,0.04381592);
   h_After_stack_2->SetBinError(9,0.06636511);
   h_After_stack_2->SetBinError(10,0.0680455);
   h_After_stack_2->SetBinError(11,0.09110688);
   h_After_stack_2->SetBinError(12,0.09490145);
   h_After_stack_2->SetBinError(13,0.1150705);
   h_After_stack_2->SetBinError(14,0.11905);
   h_After_stack_2->SetBinError(15,0.1180976);
   h_After_stack_2->SetBinError(16,0.1020683);
   h_After_stack_2->SetBinError(17,0.1219784);
   h_After_stack_2->SetBinError(18,0.1047978);
   h_After_stack_2->SetBinError(19,0.09968937);
   h_After_stack_2->SetBinError(20,0.07809161);
   h_After_stack_2->SetBinError(21,0.06825264);
   h_After_stack_2->SetBinError(22,0.06593832);
   h_After_stack_2->SetBinError(23,0.06657748);
   h_After_stack_2->SetBinError(24,0.05547416);
   h_After_stack_2->SetBinError(25,0.0633172);
   h_After_stack_2->SetBinError(26,0.04869868);
   h_After_stack_2->SetBinError(27,0.04752504);
   h_After_stack_2->SetBinError(28,0.03603765);
   h_After_stack_2->SetBinError(29,0.03275437);
   h_After_stack_2->SetBinError(30,0.05096493);
   h_After_stack_2->SetEntries(5948);
   h_After_stack_2->SetLineColor(3);
   h_After_stack_2->SetLineWidth(2);
   h_After_stack_2->GetXaxis()->SetTitle("Muon Detector #theta");
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
   TGaxis *gaxis = new TGaxis(3.1415,0,3.1415,5.406447,0,1.014199,510,"+L");
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
   
   Double_t Graph0_fx3006[30] = {
   -3.036783,
   -2.82735,
   -2.617917,
   -2.408483,
   -2.19905,
   -1.989617,
   -1.780183,
   -1.57075,
   -1.361317,
   -1.151883,
   -0.94245,
   -0.7330167,
   -0.5235833,
   -0.31415,
   -0.1047167,
   0.1047167,
   0.31415,
   0.5235833,
   0.7330167,
   0.94245,
   1.151883,
   1.361317,
   1.57075,
   1.780183,
   1.989617,
   2.19905,
   2.408483,
   2.617917,
   2.82735,
   3.036783};
   Double_t Graph0_fy3006[30] = {
   3.582268,
   2.725955,
   3.246915,
   3.08885,
   3.26886,
   3.368742,
   3.265088,
   2.995797,
   3.353218,
   3.004275,
   3.627876,
   3.535367,
   3.3923,
   3.426427,
   3.492565,
   3.438897,
   3.451239,
   3.275931,
   3.0511,
   3.154639,
   3.257684,
   2.870407,
   2.989031,
   3.3203,
   3.570601,
   3.292526,
   3.676384,
   2.919224,
   4.220182,
   3.923437};
   Double_t Graph0_felx3006[30] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
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
   Double_t Graph0_fely3006[30] = {
   0.2257273,
   0.279776,
   0.2479079,
   0.2532543,
   0.2521829,
   0.214823,
   0.2053881,
   0.2389446,
   0.1637986,
   0.1543615,
   0.1201299,
   0.1152026,
   0.09446152,
   0.09142737,
   0.09236935,
   0.1067697,
   0.08930502,
   0.1030278,
   0.1060005,
   0.1368956,
   0.1581497,
   0.1561981,
   0.1574356,
   0.1956002,
   0.1732627,
   0.2223459,
   0.2315847,
   0.2864918,
   0.3266347,
   0.2141188};
   Double_t Graph0_fehx3006[30] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
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
   Double_t Graph0_fehy3006[30] = {
   0.2161861,
   0.2788865,
   0.241047,
   0.2481213,
   0.2447988,
   0.2084597,
   0.2004997,
   0.2353963,
   0.1601671,
   0.1528352,
   0.1172036,
   0.1128261,
   0.09316398,
   0.09014535,
   0.09092615,
   0.104992,
   0.08803465,
   0.1017595,
   0.1051759,
   0.1351367,
   0.1552758,
   0.1552587,
   0.1559211,
   0.1907146,
   0.1676776,
   0.2163431,
   0.2202576,
   0.2825903,
   0.2851901,
   0.2010173};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(30,Graph0_fx3006,Graph0_fy3006,Graph0_felx3006,Graph0_fehx3006,Graph0_fely3006,Graph0_fehy3006);
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
   
   TH1F *Graph_Graph3006 = new TH1F("Graph_Graph3006","Graph",100,-3.64414,3.64414);
   Graph_Graph3006->SetMinimum(2.24026);
   Graph_Graph3006->SetMaximum(4.711292);
   Graph_Graph3006->SetDirectory(0);
   Graph_Graph3006->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph3006->SetLineColor(ci);
   Graph_Graph3006->GetXaxis()->SetLabelFont(42);
   Graph_Graph3006->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph3006->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph3006->GetXaxis()->SetTitleFont(42);
   Graph_Graph3006->GetYaxis()->SetLabelFont(42);
   Graph_Graph3006->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph3006->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph3006->GetYaxis()->SetTitleOffset(0);
   Graph_Graph3006->GetYaxis()->SetTitleFont(42);
   Graph_Graph3006->GetZaxis()->SetLabelFont(42);
   Graph_Graph3006->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph3006->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph3006->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph3006);
   
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
