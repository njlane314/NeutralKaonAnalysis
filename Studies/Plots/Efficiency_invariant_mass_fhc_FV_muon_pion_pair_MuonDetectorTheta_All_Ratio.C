void Efficiency_invariant_mass_fhc_FV_muon_pion_pair_MuonDetectorTheta_All_Ratio()
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
   pad1->Range(-0.3926875,-0.7850788,3.534188,7.065709);
   pad1->SetFillColor(0);
   pad1->SetBorderMode(0);
   pad1->SetBorderSize(2);
   pad1->SetTopMargin(0.01);
   pad1->SetFrameBorderMode(0);
   pad1->SetFrameBorderMode(0);
   
   THStack *hs = new THStack();
   hs->SetName("hs");
   hs->SetTitle(";Detector-Muon #theta;Events/bin");
   hs->SetMaximum(6.987201);
   
   TH1F *hs_stack_5 = new TH1F("hs_stack_5","",30,0,3.1415);
   hs_stack_5->SetMinimum(0);
   hs_stack_5->SetMaximum(6.987201);
   hs_stack_5->SetDirectory(0);
   hs_stack_5->SetStats(0);

   ci = TColor::GetColor("#000099");
   hs_stack_5->SetLineColor(ci);
   hs_stack_5->GetXaxis()->SetTitle("Detector-Muon #theta");
   hs_stack_5->GetXaxis()->SetLabelFont(42);
   hs_stack_5->GetXaxis()->SetLabelSize(0.045);
   hs_stack_5->GetXaxis()->SetTitleSize(0.05);
   hs_stack_5->GetXaxis()->SetTitleOffset(0.93);
   hs_stack_5->GetXaxis()->SetTitleFont(42);
   hs_stack_5->GetYaxis()->SetTitle("Events/bin");
   hs_stack_5->GetYaxis()->SetLabelFont(42);
   hs_stack_5->GetYaxis()->SetLabelSize(0.045);
   hs_stack_5->GetYaxis()->SetTitleSize(0.05);
   hs_stack_5->GetYaxis()->SetTitleOffset(1.06);
   hs_stack_5->GetYaxis()->SetTitleFont(42);
   hs_stack_5->GetZaxis()->SetLabelFont(42);
   hs_stack_5->GetZaxis()->SetLabelSize(0.035);
   hs_stack_5->GetZaxis()->SetTitleSize(0.035);
   hs_stack_5->GetZaxis()->SetTitleFont(42);
   hs->SetHistogram(hs_stack_5);
   
   
   TH1D *h_Before_stack_1 = new TH1D("h_Before_stack_1"," (total)",30,0,3.1415);
   h_Before_stack_1->SetBinContent(1,0.7757653);
   h_Before_stack_1->SetBinContent(2,1.843771);
   h_Before_stack_1->SetBinContent(3,2.789567);
   h_Before_stack_1->SetBinContent(4,4.001036);
   h_Before_stack_1->SetBinContent(5,4.681159);
   h_Before_stack_1->SetBinContent(6,4.707727);
   h_Before_stack_1->SetBinContent(7,5.589761);
   h_Before_stack_1->SetBinContent(8,5.100923);
   h_Before_stack_1->SetBinContent(9,4.245455);
   h_Before_stack_1->SetBinContent(10,3.974469);
   h_Before_stack_1->SetBinContent(11,2.353863);
   h_Before_stack_1->SetBinContent(12,2.056309);
   h_Before_stack_1->SetBinContent(13,1.477142);
   h_Before_stack_1->SetBinContent(14,1.25929);
   h_Before_stack_1->SetBinContent(15,1.036125);
   h_Before_stack_1->SetBinContent(16,0.8660942);
   h_Before_stack_1->SetBinContent(17,0.6376153);
   h_Before_stack_1->SetBinContent(18,0.7226307);
   h_Before_stack_1->SetBinContent(19,0.5472865);
   h_Before_stack_1->SetBinContent(20,0.2922404);
   h_Before_stack_1->SetBinContent(21,0.3506884);
   h_Before_stack_1->SetBinContent(22,0.2975538);
   h_Before_stack_1->SetBinContent(23,0.05313461);
   h_Before_stack_1->SetBinContent(24,0.08501538);
   h_Before_stack_1->SetBinContent(25,0.07438846);
   h_Before_stack_1->SetBinContent(26,0.09032884);
   h_Before_stack_1->SetBinContent(27,0.05844807);
   h_Before_stack_1->SetBinContent(28,0.04250769);
   h_Before_stack_1->SetBinContent(30,0.02125384);
   h_Before_stack_1->SetBinError(1,0.06420279);
   h_Before_stack_1->SetBinError(2,0.09897881);
   h_Before_stack_1->SetBinError(3,0.1217467);
   h_Before_stack_1->SetBinError(4,0.1458059);
   h_Before_stack_1->SetBinError(5,0.1577123);
   h_Before_stack_1->SetBinError(6,0.1581592);
   h_Before_stack_1->SetBinError(7,0.1723397);
   h_Before_stack_1->SetBinError(8,0.1646316);
   h_Before_stack_1->SetBinError(9,0.1501934);
   h_Before_stack_1->SetBinError(10,0.145321);
   h_Before_stack_1->SetBinError(11,0.1118354);
   h_Before_stack_1->SetBinError(12,0.1045281);
   h_Before_stack_1->SetBinError(13,0.0885931);
   h_Before_stack_1->SetBinError(14,0.08179969);
   h_Before_stack_1->SetBinError(15,0.07419845);
   h_Before_stack_1->SetBinError(16,0.06783773);
   h_Before_stack_1->SetBinError(17,0.05820605);
   h_Before_stack_1->SetBinError(18,0.06196507);
   h_Before_stack_1->SetBinError(19,0.05392574);
   h_Before_stack_1->SetBinError(20,0.03940568);
   h_Before_stack_1->SetBinError(21,0.04316676);
   h_Before_stack_1->SetBinError(22,0.0397623);
   h_Before_stack_1->SetBinError(23,0.01680264);
   h_Before_stack_1->SetBinError(24,0.02125384);
   h_Before_stack_1->SetBinError(25,0.01988115);
   h_Before_stack_1->SetBinError(26,0.02190796);
   h_Before_stack_1->SetBinError(27,0.01762276);
   h_Before_stack_1->SetBinError(28,0.01502874);
   h_Before_stack_1->SetBinError(30,0.01062692);
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
   
   TH1D *h_After_stack_2 = new TH1D("h_After_stack_2"," (passed)",30,0,3.1415);
   h_After_stack_2->SetBinContent(1,0.5632269);
   h_After_stack_2->SetBinContent(2,1.222096);
   h_After_stack_2->SetBinContent(3,1.721561);
   h_After_stack_2->SetBinContent(4,2.481386);
   h_After_stack_2->SetBinContent(5,2.980852);
   h_After_stack_2->SetBinContent(6,2.996792);
   h_After_stack_2->SetBinContent(7,3.831005);
   h_After_stack_2->SetBinContent(8,3.3156);
   h_After_stack_2->SetBinContent(9,2.64079);
   h_After_stack_2->SetBinContent(10,2.513267);
   h_After_stack_2->SetBinContent(11,1.482456);
   h_After_stack_2->SetBinContent(12,1.222096);
   h_After_stack_2->SetBinContent(13,0.8926615);
   h_After_stack_2->SetBinContent(14,0.7120038);
   h_After_stack_2->SetBinContent(15,0.6057346);
   h_After_stack_2->SetBinContent(16,0.4410173);
   h_After_stack_2->SetBinContent(17,0.3613154);
   h_After_stack_2->SetBinContent(18,0.3719423);
   h_After_stack_2->SetBinContent(19,0.3188077);
   h_After_stack_2->SetBinContent(20,0.1115827);
   h_After_stack_2->SetBinContent(21,0.1965981);
   h_After_stack_2->SetBinContent(22,0.1912846);
   h_After_stack_2->SetBinContent(23,0.01062692);
   h_After_stack_2->SetBinContent(24,0.04782115);
   h_After_stack_2->SetBinContent(25,0.03719423);
   h_After_stack_2->SetBinContent(26,0.01594038);
   h_After_stack_2->SetBinContent(27,0.02656731);
   h_After_stack_2->SetBinContent(28,0.01594038);
   h_After_stack_2->SetBinContent(30,0.01062692);
   h_After_stack_2->SetBinError(1,0.05470543);
   h_After_stack_2->SetBinError(2,0.08058263);
   h_After_stack_2->SetBinError(3,0.0956423);
   h_After_stack_2->SetBinError(4,0.1148249);
   h_After_stack_2->SetBinError(5,0.1258517);
   h_After_stack_2->SetBinError(6,0.1261877);
   h_After_stack_2->SetBinError(7,0.1426741);
   h_After_stack_2->SetBinError(8,0.1327302);
   h_After_stack_2->SetBinError(9,0.1184556);
   h_After_stack_2->SetBinError(10,0.1155601);
   h_After_stack_2->SetBinError(11,0.0887523);
   h_After_stack_2->SetBinError(12,0.08058263);
   h_After_stack_2->SetBinError(13,0.06887033);
   h_After_stack_2->SetBinError(14,0.06150776);
   h_After_stack_2->SetBinError(15,0.05673224);
   h_After_stack_2->SetBinError(16,0.04840793);
   h_After_stack_2->SetBinError(17,0.04381592);
   h_After_stack_2->SetBinError(18,0.0444556);
   h_After_stack_2->SetBinError(19,0.04115789);
   h_After_stack_2->SetBinError(20,0.02434934);
   h_After_stack_2->SetBinError(21,0.03232052);
   h_After_stack_2->SetBinError(22,0.03188077);
   h_After_stack_2->SetBinError(23,0.007514369);
   h_After_stack_2->SetBinError(24,0.01594038);
   h_After_stack_2->SetBinError(25,0.0140581);
   h_After_stack_2->SetBinError(26,0.009203185);
   h_After_stack_2->SetBinError(27,0.01188126);
   h_After_stack_2->SetBinError(28,0.009203185);
   h_After_stack_2->SetBinError(30,0.007514369);
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
   TGaxis *gaxis = new TGaxis(3.1415,0,3.1415,6.987201,0,0.9138051,510,"+L");
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
   
   Double_t Graph0_fx3005[29] = {
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
   3.089142};
   Double_t Graph0_fy3005[29] = {
   5.551402,
   5.068133,
   4.718841,
   4.742109,
   4.868965,
   4.867378,
   5.240457,
   4.970076,
   4.756191,
   4.835142,
   4.815597,
   4.544295,
   4.620768,
   4.323208,
   4.470127,
   3.8935,
   4.332887,
   3.93558,
   4.454138,
   2.919485,
   4.286546,
   4.91546,
   1.529254,
   4.301027,
   3.823135,
   1.349342,
   3.475578,
   2.867351,
   3.823135};
   Double_t Graph0_felx3005[29] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
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
   Double_t Graph0_fely3005[29] = {
   0.2867016,
   0.1948045,
   0.1621357,
   0.1351183,
   0.1238519,
   0.1235144,
   0.1096575,
   0.1177255,
   0.1310463,
   0.1347717,
   0.1755357,
   0.190538,
   0.2241074,
   0.2452055,
   0.2691589,
   0.2962165,
   0.3439259,
   0.3240465,
   0.3699633,
   0.4790519,
   0.462213,
   0.4912216,
   0.7660788,
   0.9069719,
   0.9501773,
   0.5881594,
   1.031977,
   1.102483,
   1.547135};
   Double_t Graph0_fehx3005[29] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
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
   Double_t Graph0_fehy3005[29] = {
   0.2712657,
   0.1900969,
   0.1598935,
   0.1335128,
   0.1222898,
   0.1219633,
   0.1078839,
   0.116153,
   0.1295099,
   0.1329919,
   0.1725932,
   0.1880921,
   0.2203481,
   0.2424442,
   0.2648236,
   0.2956534,
   0.3384068,
   0.3229705,
   0.3620226,
   0.5000439,
   0.4531992,
   0.4662777,
   1.031202,
   0.8715647,
   0.9501773,
   0.7662382,
   1.067762,
   1.231526,
   1.547135};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(29,Graph0_fx3005,Graph0_fy3005,Graph0_felx3005,Graph0_fehx3005,Graph0_fely3005,Graph0_fehy3005);
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
   
   TH1F *Graph_Graph3005 = new TH1F("Graph_Graph3005","Graph",100,0,3.39282);
   Graph_Graph3005->SetMinimum(0.2550339);
   Graph_Graph3005->SetMaximum(6.328816);
   Graph_Graph3005->SetDirectory(0);
   Graph_Graph3005->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph3005->SetLineColor(ci);
   Graph_Graph3005->GetXaxis()->SetLabelFont(42);
   Graph_Graph3005->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph3005->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph3005->GetXaxis()->SetTitleFont(42);
   Graph_Graph3005->GetYaxis()->SetLabelFont(42);
   Graph_Graph3005->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph3005->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph3005->GetYaxis()->SetTitleOffset(0);
   Graph_Graph3005->GetYaxis()->SetTitleFont(42);
   Graph_Graph3005->GetZaxis()->SetLabelFont(42);
   Graph_Graph3005->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph3005->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph3005->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph3005);
   
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
