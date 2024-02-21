void Efficiency_invariant_mass_fhc_FV_muon_pion_pair_NuE_All_Ratio()
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
   pad1->Range(-1,-0.7925416,9,7.132874);
   pad1->SetFillColor(0);
   pad1->SetBorderMode(0);
   pad1->SetBorderSize(2);
   pad1->SetTopMargin(0.01);
   pad1->SetFrameBorderMode(0);
   pad1->SetFrameBorderMode(0);
   
   THStack *hs = new THStack();
   hs->SetName("hs");
   hs->SetTitle(";True E_{#nu} (GeV);Events/bin");
   hs->SetMaximum(7.05362);
   
   TH1F *hs_stack_2 = new TH1F("hs_stack_2","",20,0,8);
   hs_stack_2->SetMinimum(0);
   hs_stack_2->SetMaximum(7.05362);
   hs_stack_2->SetDirectory(0);
   hs_stack_2->SetStats(0);

   ci = TColor::GetColor("#000099");
   hs_stack_2->SetLineColor(ci);
   hs_stack_2->GetXaxis()->SetTitle("True E_{#nu} (GeV)");
   hs_stack_2->GetXaxis()->SetLabelFont(42);
   hs_stack_2->GetXaxis()->SetLabelSize(0.045);
   hs_stack_2->GetXaxis()->SetTitleSize(0.05);
   hs_stack_2->GetXaxis()->SetTitleOffset(0.93);
   hs_stack_2->GetXaxis()->SetTitleFont(42);
   hs_stack_2->GetYaxis()->SetTitle("Events/bin");
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
   
   
   TH1D *h_Before_stack_1 = new TH1D("h_Before_stack_1"," (total)",20,0,8);
   h_Before_stack_1->SetBinContent(2,0.02656731);
   h_Before_stack_1->SetBinContent(3,0.03719423);
   h_Before_stack_1->SetBinContent(4,0.5579134);
   h_Before_stack_1->SetBinContent(5,1.880965);
   h_Before_stack_1->SetBinContent(6,4.941519);
   h_Before_stack_1->SetBinContent(7,5.063728);
   h_Before_stack_1->SetBinContent(8,5.116863);
   h_Before_stack_1->SetBinContent(9,5.642896);
   h_Before_stack_1->SetBinContent(10,4.909638);
   h_Before_stack_1->SetBinContent(11,5.063728);
   h_Before_stack_1->SetBinContent(12,3.969155);
   h_Before_stack_1->SetBinContent(13,2.598282);
   h_Before_stack_1->SetBinContent(14,2.465446);
   h_Before_stack_1->SetBinContent(15,2.157265);
   h_Before_stack_1->SetBinContent(16,1.450575);
   h_Before_stack_1->SetBinContent(17,1.477142);
   h_Before_stack_1->SetBinContent(18,0.8820345);
   h_Before_stack_1->SetBinContent(19,0.4622711);
   h_Before_stack_1->SetBinContent(20,0.345375);
   h_Before_stack_1->SetBinContent(21,0.9829903);
   h_Before_stack_1->SetBinError(2,0.01188126);
   h_Before_stack_1->SetBinError(3,0.0140581);
   h_Before_stack_1->SetBinError(4,0.05444677);
   h_Before_stack_1->SetBinError(5,0.09997217);
   h_Before_stack_1->SetBinError(6,0.1620388);
   h_Before_stack_1->SetBinError(7,0.1640303);
   h_Before_stack_1->SetBinError(8,0.1648886);
   h_Before_stack_1->SetBinError(9,0.1731569);
   h_Before_stack_1->SetBinError(10,0.1615152);
   h_Before_stack_1->SetBinError(11,0.1640303);
   h_Before_stack_1->SetBinError(12,0.1452238);
   h_Before_stack_1->SetBinError(13,0.1174984);
   h_Before_stack_1->SetBinError(14,0.1144555);
   h_Before_stack_1->SetBinError(15,0.1070633);
   h_Before_stack_1->SetBinError(16,0.08779279);
   h_Before_stack_1->SetBinError(17,0.0885931);
   h_Before_stack_1->SetBinError(18,0.06845916);
   h_Before_stack_1->SetBinError(19,0.04956067);
   h_Before_stack_1->SetBinError(20,0.04283849);
   h_Before_stack_1->SetBinError(21,0.07227088);
   h_Before_stack_1->SetEntries(9506);
   h_Before_stack_1->SetLineWidth(2);
   h_Before_stack_1->GetXaxis()->SetTitle("True E_{#nu} (GeV)");
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
   
   TH1D *h_After_stack_2 = new TH1D("h_After_stack_2"," (passed)",20,0,8);
   h_After_stack_2->SetBinContent(2,0.01594038);
   h_After_stack_2->SetBinContent(3,0.02656731);
   h_After_stack_2->SetBinContent(4,0.3241211);
   h_After_stack_2->SetBinContent(5,1.12114);
   h_After_stack_2->SetBinContent(6,2.890523);
   h_After_stack_2->SetBinContent(7,3.166823);
   h_After_stack_2->SetBinContent(8,3.145569);
   h_After_stack_2->SetBinContent(9,3.575959);
   h_After_stack_2->SetBinContent(10,3.092434);
   h_After_stack_2->SetBinContent(11,3.134942);
   h_After_stack_2->SetBinContent(12,2.64079);
   h_After_stack_2->SetBinContent(13,1.732188);
   h_After_stack_2->SetBinContent(14,1.615292);
   h_After_stack_2->SetBinContent(15,1.386813);
   h_After_stack_2->SetBinContent(16,0.749198);
   h_After_stack_2->SetBinContent(17,0.9511095);
   h_After_stack_2->SetBinContent(18,0.5632269);
   h_After_stack_2->SetBinContent(19,0.3134942);
   h_After_stack_2->SetBinContent(20,0.2125384);
   h_After_stack_2->SetBinContent(21,0.680123);
   h_After_stack_2->SetBinError(2,0.009203185);
   h_After_stack_2->SetBinError(3,0.01188126);
   h_After_stack_2->SetBinError(4,0.04149946);
   h_After_stack_2->SetBinError(5,0.07718248);
   h_After_stack_2->SetBinError(6,0.1239301);
   h_After_stack_2->SetBinError(7,0.1297181);
   h_After_stack_2->SetBinError(8,0.1292821);
   h_After_stack_2->SetBinError(9,0.1378431);
   h_After_stack_2->SetBinError(10,0.1281855);
   h_After_stack_2->SetBinError(11,0.1290635);
   h_After_stack_2->SetBinError(12,0.1184556);
   h_After_stack_2->SetBinError(13,0.09593704);
   h_After_stack_2->SetBinError(14,0.09264336);
   h_After_stack_2->SetBinError(15,0.08584159);
   h_After_stack_2->SetBinError(16,0.06309385);
   h_After_stack_2->SetBinError(17,0.07108926);
   h_After_stack_2->SetBinError(18,0.05470543);
   h_After_stack_2->SetBinError(19,0.04081347);
   h_After_stack_2->SetBinError(20,0.03360528);
   h_After_stack_2->SetBinError(21,0.06011495);
   h_After_stack_2->SetEntries(5948);
   h_After_stack_2->SetLineColor(3);
   h_After_stack_2->SetLineWidth(2);
   h_After_stack_2->GetXaxis()->SetTitle("True E_{#nu} (GeV)");
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
   TGaxis *gaxis = new TGaxis(8,0,8,7.05362,0,1.019418,510,"+L");
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
   
   Double_t Graph0_fx3002[19] = {
   0.6,
   1,
   1.4,
   1.8,
   2.2,
   2.6,
   3,
   3.4,
   3.8,
   4.2,
   4.6,
   5,
   5.4,
   5.8,
   6.2,
   6.6,
   7,
   7.4,
   7.8};
   Double_t Graph0_fy3002[19] = {
   4.151559,
   4.942332,
   4.019763,
   4.124194,
   4.047398,
   4.327263,
   4.253587,
   4.384807,
   4.358238,
   4.2837,
   4.60358,
   4.612843,
   4.533311,
   4.448099,
   3.573686,
   4.45521,
   4.418326,
   4.692375,
   4.258009};
   Double_t Graph0_felx3002[19] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
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
   Double_t Graph0_fely3002[19] = {
   1.342649,
   1.161836,
   0.3317139,
   0.1801894,
   0.1114754,
   0.1083756,
   0.108342,
   0.1022096,
   0.1098241,
   0.1086986,
   0.1196569,
   0.1479526,
   0.153043,
   0.164843,
   0.2076304,
   0.1992858,
   0.2588698,
   0.3501699,
   0.4170195};
   Double_t Graph0_fehx3002[19] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
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
   Double_t Graph0_fehy3002[19] = {
   1.20832,
   0.9356848,
   0.3247972,
   0.1777265,
   0.1106437,
   0.1071773,
   0.1072569,
   0.1010628,
   0.1085442,
   0.1075605,
   0.1176423,
   0.1448539,
   0.1500031,
   0.1616464,
   0.2070832,
   0.194593,
   0.2513339,
   0.3318456,
   0.4012514};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(19,Graph0_fx3002,Graph0_fy3002,Graph0_felx3002,Graph0_fehx3002,Graph0_fely3002,Graph0_fehy3002);
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
   
   TH1F *Graph_Graph3002 = new TH1F("Graph_Graph3002","Graph",100,0,8.52);
   Graph_Graph3002->SetMinimum(2.501999);
   Graph_Graph3002->SetMaximum(6.184927);
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
