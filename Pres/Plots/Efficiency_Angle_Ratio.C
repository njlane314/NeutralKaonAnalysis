void Efficiency_Angle_Ratio()
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
   pad1->Range(-22.5,-3.678313,202.5,33.10481);
   pad1->SetFillColor(0);
   pad1->SetBorderMode(0);
   pad1->SetBorderSize(2);
   pad1->SetTopMargin(0.01);
   pad1->SetFrameBorderMode(0);
   pad1->SetFrameBorderMode(0);
   
   THStack *hs = new THStack();
   hs->SetName("hs");
   hs->SetTitle("Angle");
   hs->SetMaximum(32.73698);
   
   TH1F *hs_stack_8 = new TH1F("hs_stack_8","Angle",10,0,180);
   hs_stack_8->SetMinimum(0);
   hs_stack_8->SetMaximum(32.73698);
   hs_stack_8->SetDirectory(0);
   hs_stack_8->SetStats(0);

   ci = TColor::GetColor("#000099");
   hs_stack_8->SetLineColor(ci);
   hs_stack_8->GetXaxis()->SetTitle("#theta_{open}");
   hs_stack_8->GetXaxis()->SetLabelFont(42);
   hs_stack_8->GetXaxis()->SetLabelSize(0.045);
   hs_stack_8->GetXaxis()->SetTitleSize(0.05);
   hs_stack_8->GetXaxis()->SetTitleOffset(0.93);
   hs_stack_8->GetXaxis()->SetTitleFont(42);
   hs_stack_8->GetYaxis()->SetTitle(" Entries/bin");
   hs_stack_8->GetYaxis()->SetLabelFont(42);
   hs_stack_8->GetYaxis()->SetLabelSize(0.045);
   hs_stack_8->GetYaxis()->SetTitleSize(0.05);
   hs_stack_8->GetYaxis()->SetTitleOffset(1.06);
   hs_stack_8->GetYaxis()->SetTitleFont(42);
   hs_stack_8->GetZaxis()->SetLabelFont(42);
   hs_stack_8->GetZaxis()->SetLabelSize(0.035);
   hs_stack_8->GetZaxis()->SetTitleSize(0.035);
   hs_stack_8->GetZaxis()->SetTitleFont(42);
   hs->SetHistogram(hs_stack_8);
   
   
   TH1D *h_Before_stack_1 = new TH1D("h_Before_stack_1"," (total)",10,0,180);
   h_Before_stack_1->SetBinContent(1,1.498524);
   h_Before_stack_1->SetBinContent(2,13.25617);
   h_Before_stack_1->SetBinContent(3,24.13776);
   h_Before_stack_1->SetBinContent(4,26.18959);
   h_Before_stack_1->SetBinContent(5,17.89007);
   h_Before_stack_1->SetBinContent(6,9.060306);
   h_Before_stack_1->SetBinContent(7,4.841385);
   h_Before_stack_1->SetBinContent(8,2.674289);
   h_Before_stack_1->SetBinContent(9,1.221873);
   h_Before_stack_1->SetBinContent(10,0.2997048);
   h_Before_stack_1->SetBinError(1,0.185869);
   h_Before_stack_1->SetBinError(2,0.5528206);
   h_Before_stack_1->SetBinError(3,0.7459739);
   h_Before_stack_1->SetBinError(4,0.777033);
   h_Before_stack_1->SetBinError(5,0.6422161);
   h_Before_stack_1->SetBinError(6,0.457032);
   h_Before_stack_1->SetBinError(7,0.3340873);
   h_Before_stack_1->SetBinError(8,0.2483015);
   h_Before_stack_1->SetBinError(9,0.1678372);
   h_Before_stack_1->SetBinError(10,0.08312315);
   h_Before_stack_1->SetEntries(4384);
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
   h_After_stack_2->SetBinContent(0,0.06916264);
   h_After_stack_2->SetBinContent(1,0.4610843);
   h_After_stack_2->SetBinContent(2,1.221873);
   h_After_stack_2->SetBinContent(3,1.406307);
   h_After_stack_2->SetBinContent(4,1.337144);
   h_After_stack_2->SetBinContent(5,0.9452227);
   h_After_stack_2->SetBinContent(6,0.2997048);
   h_After_stack_2->SetBinContent(7,0.2305421);
   h_After_stack_2->SetBinContent(8,0.2305421);
   h_After_stack_2->SetBinContent(9,0.1152711);
   h_After_stack_2->SetBinContent(10,0.06916264);
   h_After_stack_2->SetBinError(0,0.03993107);
   h_After_stack_2->SetBinError(1,0.1031016);
   h_After_stack_2->SetBinError(2,0.1678372);
   h_After_stack_2->SetBinError(3,0.1800592);
   h_After_stack_2->SetBinError(4,0.1755757);
   h_After_stack_2->SetBinError(5,0.147619);
   h_After_stack_2->SetBinError(6,0.08312315);
   h_After_stack_2->SetBinError(7,0.07290382);
   h_After_stack_2->SetBinError(8,0.07290382);
   h_After_stack_2->SetBinError(9,0.05155079);
   h_After_stack_2->SetBinError(10,0.03993107);
   h_After_stack_2->SetEntries(277);
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
   TGaxis *gaxis = new TGaxis(180,0,180,32.73698,0,0.4388805,510,"+L");
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
   
   Double_t Graph0_fx3008[10] = {
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
   Double_t Graph0_fy3008[10] = {
   22.95139,
   6.875439,
   4.345858,
   3.808396,
   3.941073,
   2.467421,
   3.552001,
   6.430347,
   7.036983,
   17.21354};
   Double_t Graph0_felx3008[10] = {
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
   Double_t Graph0_fely3008[10] = {
   4.045798,
   0.8598243,
   0.5165252,
   0.4653467,
   0.5679234,
   0.6138635,
   0.9888795,
   1.75781,
   2.598544,
   7.264395};
   Double_t Graph0_fehx3008[10] = {
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
   Double_t Graph0_fehy3008[10] = {
   4.329427,
   0.9295174,
   0.5580396,
   0.5042443,
   0.6246507,
   0.7314488,
   1.201783,
   2.107361,
   3.34325,
   9.087865};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(10,Graph0_fx3008,Graph0_fy3008,Graph0_felx3008,Graph0_fehx3008,Graph0_fely3008,Graph0_fehy3008);
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
   
   TH1F *Graph_Graph3008 = new TH1F("Graph_Graph3008","Graph",100,0,187.2);
   Graph_Graph3008->SetMinimum(1.668201);
   Graph_Graph3008->SetMaximum(29.82355);
   Graph_Graph3008->SetDirectory(0);
   Graph_Graph3008->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph3008->SetLineColor(ci);
   Graph_Graph3008->GetXaxis()->SetLabelFont(42);
   Graph_Graph3008->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph3008->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph3008->GetXaxis()->SetTitleFont(42);
   Graph_Graph3008->GetYaxis()->SetLabelFont(42);
   Graph_Graph3008->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph3008->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph3008->GetYaxis()->SetTitleOffset(0);
   Graph_Graph3008->GetYaxis()->SetTitleFont(42);
   Graph_Graph3008->GetZaxis()->SetLabelFont(42);
   Graph_Graph3008->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph3008->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph3008->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph3008);
   
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
