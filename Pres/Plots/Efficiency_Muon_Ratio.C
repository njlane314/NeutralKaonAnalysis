void Efficiency_Muon_Ratio()
{
//=========Macro generated from canvas: c1/c1
//=========  (Mon Dec  4 08:50:31 2023) by ROOT version 6.12/06
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
   pad1->Range(-1.75,-2.004292,15.75,18.03863);
   pad1->SetFillColor(0);
   pad1->SetBorderMode(0);
   pad1->SetBorderSize(2);
   pad1->SetTopMargin(0.01);
   pad1->SetFrameBorderMode(0);
   pad1->SetFrameBorderMode(0);
   
   THStack *hs = new THStack();
   hs->SetName("hs");
   hs->SetTitle("");
   hs->SetMaximum(17.8382);
   
   TH1F *hs_stack_5 = new TH1F("hs_stack_5","",28,0,14);
   hs_stack_5->SetMinimum(0);
   hs_stack_5->SetMaximum(17.8382);
   hs_stack_5->SetDirectory(0);
   hs_stack_5->SetStats(0);

   ci = TColor::GetColor("#000099");
   hs_stack_5->SetLineColor(ci);
   hs_stack_5->GetXaxis()->SetTitle("Neutrino Energy (GeV)");
   hs_stack_5->GetXaxis()->SetLabelFont(42);
   hs_stack_5->GetXaxis()->SetLabelSize(0.045);
   hs_stack_5->GetXaxis()->SetTitleSize(0.05);
   hs_stack_5->GetXaxis()->SetTitleOffset(0.93);
   hs_stack_5->GetXaxis()->SetTitleFont(42);
   hs_stack_5->GetYaxis()->SetTitle(" Entries/bin");
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
   
   
   TH1D *h_Before_stack_1 = new TH1D("h_Before_stack_1"," (total)",28,0,14);
   h_Before_stack_1->SetBinContent(1,0.1844337);
   h_Before_stack_1->SetBinContent(2,0.4841385);
   h_Before_stack_1->SetBinContent(3,1.636849);
   h_Before_stack_1->SetBinContent(4,8.092029);
   h_Before_stack_1->SetBinContent(5,14.27056);
   h_Before_stack_1->SetBinContent(6,11.25046);
   h_Before_stack_1->SetBinContent(7,12.51844);
   h_Before_stack_1->SetBinContent(8,12.40317);
   h_Before_stack_1->SetBinContent(9,9.821095);
   h_Before_stack_1->SetBinContent(10,7.999812);
   h_Before_stack_1->SetBinContent(11,6.524342);
   h_Before_stack_1->SetBinContent(12,4.910547);
   h_Before_stack_1->SetBinContent(13,3.550349);
   h_Before_stack_1->SetBinContent(14,2.19015);
   h_Before_stack_1->SetBinContent(15,1.544632);
   h_Before_stack_1->SetBinContent(16,1.267982);
   h_Before_stack_1->SetBinContent(17,1.03744);
   h_Before_stack_1->SetBinContent(18,0.3688674);
   h_Before_stack_1->SetBinContent(19,0.2997048);
   h_Before_stack_1->SetBinContent(20,0.2305421);
   h_Before_stack_1->SetBinContent(21,0.1152711);
   h_Before_stack_1->SetBinContent(22,0.02305421);
   h_Before_stack_1->SetBinContent(23,0.1152711);
   h_Before_stack_1->SetBinContent(25,0.1152711);
   h_Before_stack_1->SetBinContent(26,0.06916264);
   h_Before_stack_1->SetBinContent(28,0.02305421);
   h_Before_stack_1->SetBinContent(29,0.02305421);
   h_Before_stack_1->SetBinError(1,0.06520716);
   h_Before_stack_1->SetBinError(2,0.1056477);
   h_Before_stack_1->SetBinError(3,0.1942583);
   h_Before_stack_1->SetBinError(4,0.4319205);
   h_Before_stack_1->SetBinError(5,0.5735821);
   h_Before_stack_1->SetBinError(6,0.5092842);
   h_Before_stack_1->SetBinError(7,0.5372176);
   h_Before_stack_1->SetBinError(8,0.5347385);
   h_Before_stack_1->SetBinError(9,0.4758336);
   h_Before_stack_1->SetBinError(10,0.4294524);
   h_Before_stack_1->SetBinError(11,0.3878319);
   h_Before_stack_1->SetBinError(12,0.3364652);
   h_Before_stack_1->SetBinError(13,0.2860953);
   h_Before_stack_1->SetBinError(14,0.2247047);
   h_Before_stack_1->SetBinError(15,0.1887069);
   h_Before_stack_1->SetBinError(16,0.1709746);
   h_Before_stack_1->SetBinError(17,0.1546524);
   h_Before_stack_1->SetBinError(18,0.09221685);
   h_Before_stack_1->SetBinError(19,0.08312315);
   h_Before_stack_1->SetBinError(20,0.07290382);
   h_Before_stack_1->SetBinError(21,0.05155079);
   h_Before_stack_1->SetBinError(22,0.02305421);
   h_Before_stack_1->SetBinError(23,0.05155079);
   h_Before_stack_1->SetBinError(25,0.05155079);
   h_Before_stack_1->SetBinError(26,0.03993107);
   h_Before_stack_1->SetBinError(28,0.02305421);
   h_Before_stack_1->SetBinError(29,0.02305421);
   h_Before_stack_1->SetEntries(4384);
   h_Before_stack_1->SetLineWidth(2);
   h_Before_stack_1->GetXaxis()->SetTitle("Neutrino Energy (GeV)");
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
   
   TH1D *h_After_stack_2 = new TH1D("h_After_stack_2"," (passed)",28,0,14);
   h_After_stack_2->SetBinContent(1,0.06916264);
   h_After_stack_2->SetBinContent(2,0.1152711);
   h_After_stack_2->SetBinContent(3,0.3688674);
   h_After_stack_2->SetBinContent(4,2.420692);
   h_After_stack_2->SetBinContent(5,4.357246);
   h_After_stack_2->SetBinContent(6,3.365915);
   h_After_stack_2->SetBinContent(7,3.919216);
   h_After_stack_2->SetBinContent(8,3.711728);
   h_After_stack_2->SetBinContent(9,2.950939);
   h_After_stack_2->SetBinContent(10,2.282367);
   h_After_stack_2->SetBinContent(11,2.074879);
   h_After_stack_2->SetBinContent(12,1.682958);
   h_After_stack_2->SetBinContent(13,1.014385);
   h_After_stack_2->SetBinContent(14,0.7146806);
   h_After_stack_2->SetBinContent(15,0.4149758);
   h_After_stack_2->SetBinContent(16,0.3919216);
   h_After_stack_2->SetBinContent(17,0.2305421);
   h_After_stack_2->SetBinContent(18,0.02305421);
   h_After_stack_2->SetBinContent(19,0.09221685);
   h_After_stack_2->SetBinContent(20,0.06916264);
   h_After_stack_2->SetBinContent(21,0.02305421);
   h_After_stack_2->SetBinContent(23,0.04610843);
   h_After_stack_2->SetBinContent(25,0.02305421);
   h_After_stack_2->SetBinContent(29,0.02305421);
   h_After_stack_2->SetBinError(1,0.03993107);
   h_After_stack_2->SetBinError(2,0.05155079);
   h_After_stack_2->SetBinError(3,0.09221685);
   h_After_stack_2->SetBinError(4,0.2362354);
   h_After_stack_2->SetBinError(5,0.316943);
   h_After_stack_2->SetBinError(6,0.2785651);
   h_After_stack_2->SetBinError(7,0.3005902);
   h_After_stack_2->SetBinError(8,0.2925252);
   h_After_stack_2->SetBinError(9,0.2608286);
   h_After_stack_2->SetBinError(10,0.2293865);
   h_After_stack_2->SetBinError(11,0.2187115);
   h_After_stack_2->SetBinError(12,0.1969753);
   h_After_stack_2->SetBinError(13,0.1529243);
   h_After_stack_2->SetBinError(14,0.1283604);
   h_After_stack_2->SetBinError(15,0.09781074);
   h_After_stack_2->SetBinError(16,0.09505496);
   h_After_stack_2->SetBinError(17,0.07290382);
   h_After_stack_2->SetBinError(18,0.02305421);
   h_After_stack_2->SetBinError(19,0.04610843);
   h_After_stack_2->SetBinError(20,0.03993107);
   h_After_stack_2->SetBinError(21,0.02305421);
   h_After_stack_2->SetBinError(23,0.03260358);
   h_After_stack_2->SetBinError(25,0.02305421);
   h_After_stack_2->SetBinError(29,0.02305421);
   h_After_stack_2->SetEntries(1318);
   h_After_stack_2->SetLineColor(3);
   h_After_stack_2->SetLineWidth(2);
   h_After_stack_2->GetXaxis()->SetTitle("Neutrino Energy (GeV)");
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
   TGaxis *gaxis = new TGaxis(14,0,14,17.8382,0,0.7128541,510,"+L");
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
   
   Double_t Graph0_fx3005[26] = {
   0.25,
   0.75,
   1.25,
   1.75,
   2.25,
   2.75,
   3.25,
   3.75,
   4.25,
   4.75,
   5.25,
   5.75,
   6.25,
   6.75,
   7.25,
   7.75,
   8.25,
   8.75,
   9.25,
   9.75,
   10.25,
   10.75,
   11.25,
   12.25,
   12.75,
   13.75};
   Double_t Graph0_fy3005[26] = {
   9.383861,
   5.958007,
   5.639128,
   7.485701,
   7.640495,
   7.486578,
   7.834286,
   7.488484,
   7.518837,
   7.139307,
   7.958045,
   8.576174,
   7.149609,
   8.165606,
   6.722766,
   7.734577,
   5.560807,
   1.563977,
   7.699579,
   7.507089,
   5.004726,
   0,
   10.00945,
   5.004726,
   0,
   0};
   Double_t Graph0_felx3005[26] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
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
   Double_t Graph0_fely3005[26] = {
   3.608051,
   2.035549,
   1.15772,
   0.5972187,
   0.4547884,
   0.5080908,
   0.4887368,
   0.4843327,
   0.5438803,
   0.5915217,
   0.676104,
   0.7936041,
   0.8779511,
   1.155817,
   1.274704,
   1.469726,
   1.417143,
   1.091609,
   2.765422,
   3.033909,
   3.150592,
   0,
   4.36991,
   3.150592,
   0,
   0};
   Double_t Graph0_fehx3005[26] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
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
   Double_t Graph0_fehy3005[26] = {
   4.030365,
   2.418784,
   1.282677,
   0.6160104,
   0.4651372,
   0.5216226,
   0.5000601,
   0.4966061,
   0.5592743,
   0.6118402,
   0.6971948,
   0.8177716,
   0.9233756,
   1.215075,
   1.385937,
   1.580843,
   1.614203,
   2.004882,
   3.197475,
   3.599223,
   4.701262,
   10.86813,
   4.855712,
   4.701262,
   6.202842,
   10.86813};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(26,Graph0_fx3005,Graph0_fy3005,Graph0_felx3005,Graph0_fehx3005,Graph0_fely3005,Graph0_fehy3005);
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
   
   TH1F *Graph_Graph3005 = new TH1F("Graph_Graph3005","Graph",100,0,15.1);
   Graph_Graph3005->SetMinimum(0);
   Graph_Graph3005->SetMaximum(16.35168);
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
