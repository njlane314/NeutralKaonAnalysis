void Efficiency_Angle_Ratio()
{
//=========Macro generated from canvas: c1/c1
//=========  (Sun Nov 19 15:01:36 2023) by ROOT version 6.12/06
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
   pad1->Range(-22.5,-7.46024,202.5,67.14216);
   pad1->SetFillColor(0);
   pad1->SetBorderMode(0);
   pad1->SetBorderSize(2);
   pad1->SetTopMargin(0.01);
   pad1->SetFrameBorderMode(0);
   pad1->SetFrameBorderMode(0);
   
   THStack *hs = new THStack();
   hs->SetName("hs");
   hs->SetTitle("Angle");
   hs->SetMaximum(66.39613);
   
   TH1F *hs_stack_5 = new TH1F("hs_stack_5","Angle",10,0,180);
   hs_stack_5->SetMinimum(0);
   hs_stack_5->SetMaximum(66.39613);
   hs_stack_5->SetDirectory(0);
   hs_stack_5->SetStats(0);

   ci = TColor::GetColor("#000099");
   hs_stack_5->SetLineColor(ci);
   hs_stack_5->GetXaxis()->SetTitle("#theta_{open}");
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
   
   
   TH1D *h_Before_stack_1 = new TH1D("h_Before_stack_1"," (total)",10,0,180);
   h_Before_stack_1->SetBinContent(1,3.273698);
   h_Before_stack_1->SetBinContent(2,30.24713);
   h_Before_stack_1->SetBinContent(3,53.11691);
   h_Before_stack_1->SetBinContent(4,52.8172);
   h_Before_stack_1->SetBinContent(5,38.59275);
   h_Before_stack_1->SetBinContent(6,20.86406);
   h_Before_stack_1->SetBinContent(7,11.13518);
   h_Before_stack_1->SetBinContent(8,5.763553);
   h_Before_stack_1->SetBinContent(9,2.282367);
   h_Before_stack_1->SetBinContent(10,0.9452227);
   h_Before_stack_1->SetBinError(1,0.2747227);
   h_Before_stack_1->SetBinError(2,0.8350591);
   h_Before_stack_1->SetBinError(3,1.106602);
   h_Before_stack_1->SetBinError(4,1.103476);
   h_Before_stack_1->SetBinError(5,0.9432526);
   h_Before_stack_1->SetBinError(6,0.6935449);
   h_Before_stack_1->SetBinError(7,0.5066685);
   h_Before_stack_1->SetBinError(8,0.3645191);
   h_Before_stack_1->SetBinError(9,0.2293865);
   h_Before_stack_1->SetBinError(10,0.147619);
   h_Before_stack_1->SetEntries(9501);
   h_Before_stack_1->SetLineWidth(2);
   h_Before_stack_1->GetXaxis()->SetTitle("#theta_{open}");
   h_Before_stack_1->GetXaxis()->SetRange(1,10);
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
   
   TH1D *h_After_stack_2 = new TH1D("h_After_stack_2"," (passed)",10,20,160);
   h_After_stack_2->SetBinContent(0,0.09221685);
   h_After_stack_2->SetBinContent(1,0.3919216);
   h_After_stack_2->SetBinContent(2,0.8068975);
   h_After_stack_2->SetBinContent(3,1.060494);
   h_After_stack_2->SetBinContent(4,0.8991143);
   h_After_stack_2->SetBinContent(5,0.7838432);
   h_After_stack_2->SetBinContent(6,0.2074879);
   h_After_stack_2->SetBinContent(7,0.1152711);
   h_After_stack_2->SetBinContent(8,0.04610843);
   h_After_stack_2->SetBinContent(9,0.02305421);
   h_After_stack_2->SetBinContent(10,0.04610843);
   h_After_stack_2->SetBinContent(11,0.02305421);
   h_After_stack_2->SetBinError(0,0.04610843);
   h_After_stack_2->SetBinError(1,0.09505496);
   h_After_stack_2->SetBinError(2,0.1363906);
   h_After_stack_2->SetBinError(3,0.1563613);
   h_After_stack_2->SetBinError(4,0.1439735);
   h_After_stack_2->SetBinError(5,0.134428);
   h_After_stack_2->SetBinError(6,0.06916264);
   h_After_stack_2->SetBinError(7,0.05155079);
   h_After_stack_2->SetBinError(8,0.03260358);
   h_After_stack_2->SetBinError(9,0.02305421);
   h_After_stack_2->SetBinError(10,0.03260358);
   h_After_stack_2->SetBinError(11,0.02305421);
   h_After_stack_2->SetEntries(195);
   h_After_stack_2->SetLineColor(3);
   h_After_stack_2->SetLineWidth(2);
   h_After_stack_2->GetXaxis()->SetTitle("#theta_{open}");
   h_After_stack_2->GetXaxis()->SetRange(1,10);
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
   
   TPaveText *pt = new TPaveText(0.4466583,0.933297,0.5533417,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *pt_LaTex = pt->AddText("Angle");
   pt->Draw();
   TGaxis *gaxis = new TGaxis(180,0,180,66.39613,0,0.1781889,510,"+L");
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
   
   Double_t Graph0_fx3005[10] = {
   9,
   27,
   45,
   63,
   81,
   99,
   117,
   135,
   153,
   171};
   Double_t Graph0_fy3005[10] = {
   44.60903,
   9.940229,
   7.439394,
   6.343102,
   7.568079,
   3.705579,
   3.857315,
   2.980933,
   3.763804,
   18.17642};
   Double_t Graph0_felx3005[10] = {
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
   Double_t Graph0_fely3005[10] = {
   9.413884,
   1.563145,
   1.03053,
   0.951769,
   1.210079,
   1.10057,
   1.484443,
   1.678252,
   2.726192,
   9.993757};
   Double_t Graph0_fehx3005[10] = {
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
   Double_t Graph0_fehy3005[10] = {
   10.72108,
   1.740882,
   1.133144,
   1.055659,
   1.351326,
   1.37057,
   1.995748,
   2.711651,
   5.47058,
   15.52183};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(10,Graph0_fx3005,Graph0_fy3005,Graph0_felx3005,Graph0_fehx3005,Graph0_fely3005,Graph0_fehy3005);
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
   
   TH1F *Graph_Graph3005 = new TH1F("Graph_Graph3005","Graph",100,0,187.2);
   Graph_Graph3005->SetMinimum(0.9338512);
   Graph_Graph3005->SetMaximum(60.75936);
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
