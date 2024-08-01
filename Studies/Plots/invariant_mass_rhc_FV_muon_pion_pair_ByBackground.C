void invariant_mass_rhc_FV_muon_pion_pair_ByBackground()
{
//=========Macro generated from canvas: c/c
//=========  (Wed Feb 21 08:52:28 2024) by ROOT version 6.12/06
   TCanvas *c = new TCanvas("c", "c",0,0,800,600);
   c->Range(0,0,1,1);
   c->SetFillColor(0);
   c->SetBorderMode(0);
   c->SetBorderSize(2);
   c->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: p_legend
   TPad *p_legend = new TPad("p_legend", "p_legend",0,0.85,1,1);
   p_legend->Draw();
   p_legend->cd();
   p_legend->Range(0,0,1,1);
   p_legend->SetFillColor(0);
   p_legend->SetBorderMode(0);
   p_legend->SetBorderSize(2);
   p_legend->SetBottomMargin(0);
   p_legend->SetFrameBorderMode(0);
   
   TLegend *leg = new TLegend(0.1,0,0.9,1,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("h_BackgroundSignal","Signal","F");
   entry->SetFillColor(8);
   entry->SetFillStyle(1001);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("h_BackgroundOther","Other #nu","F");
   entry->SetFillColor(30);
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#000099");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("h_BackgroundDirt","Dirt","F");
   entry->SetFillColor(38);
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#000099");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("h_BackgroundCosmic","Cosmic","F");
   entry->SetFillColor(15);
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#000099");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   p_legend->Modified();
   c->cd();
  
// ------------>Primitives in pad: p_plot
   TPad *p_plot = new TPad("p_plot", "p_plot",0,0,1,0.85);
   p_plot->Draw();
   p_plot->cd();
   p_plot->Range(0.15,-0.1123596,0.65,1.011236);
   p_plot->SetFillColor(0);
   p_plot->SetBorderMode(0);
   p_plot->SetBorderSize(2);
   p_plot->SetTopMargin(0.01);
   p_plot->SetFrameBorderMode(0);
   p_plot->SetFrameBorderMode(0);
   
   TH1D *h_errors__4 = new TH1D("h_errors__4","",4,0.2,0.6);
   h_errors__4->SetMinimum(0);
   h_errors__4->SetMaximum(0);
   h_errors__4->SetEntries(1717);
   h_errors__4->SetStats(0);
   h_errors__4->SetFillColor(1);
   h_errors__4->SetFillStyle(3253);

   ci = TColor::GetColor("#000099");
   h_errors__4->SetLineColor(ci);
   h_errors__4->GetXaxis()->SetTitle("Invariant Mass (GeV)");
   h_errors__4->GetXaxis()->SetLabelFont(42);
   h_errors__4->GetXaxis()->SetLabelSize(0.045);
   h_errors__4->GetXaxis()->SetTitleSize(0.05);
   h_errors__4->GetXaxis()->SetTitleOffset(0.93);
   h_errors__4->GetXaxis()->SetTitleFont(42);
   h_errors__4->GetYaxis()->SetTitle("Events/bin");
   h_errors__4->GetYaxis()->SetLabelFont(42);
   h_errors__4->GetYaxis()->SetLabelSize(0.045);
   h_errors__4->GetYaxis()->SetTitleSize(0.05);
   h_errors__4->GetYaxis()->SetTitleOffset(1.06);
   h_errors__4->GetYaxis()->SetTitleFont(42);
   h_errors__4->GetZaxis()->SetLabelFont(42);
   h_errors__4->GetZaxis()->SetLabelSize(0.035);
   h_errors__4->GetZaxis()->SetTitleSize(0.035);
   h_errors__4->GetZaxis()->SetTitleFont(42);
   h_errors__4->Draw("E2");
   
   THStack *hs = new THStack();
   hs->SetName("hs");
   hs->SetTitle("");
   
   TH1F *hs_stack_2 = new TH1F("hs_stack_2","",4,0.2,0.6);
   hs_stack_2->SetMinimum(0);
   hs_stack_2->SetMaximum(0);
   hs_stack_2->SetDirectory(0);
   hs_stack_2->SetStats(0);

   ci = TColor::GetColor("#000099");
   hs_stack_2->SetLineColor(ci);
   hs_stack_2->GetXaxis()->SetLabelFont(42);
   hs_stack_2->GetXaxis()->SetLabelSize(0.035);
   hs_stack_2->GetXaxis()->SetTitleSize(0.035);
   hs_stack_2->GetXaxis()->SetTitleFont(42);
   hs_stack_2->GetYaxis()->SetLabelFont(42);
   hs_stack_2->GetYaxis()->SetLabelSize(0.035);
   hs_stack_2->GetYaxis()->SetTitleSize(0.035);
   hs_stack_2->GetYaxis()->SetTitleOffset(0);
   hs_stack_2->GetYaxis()->SetTitleFont(42);
   hs_stack_2->GetZaxis()->SetLabelFont(42);
   hs_stack_2->GetZaxis()->SetLabelSize(0.035);
   hs_stack_2->GetZaxis()->SetTitleSize(0.035);
   hs_stack_2->GetZaxis()->SetTitleFont(42);
   hs->SetHistogram(hs_stack_2);
   
   
   TH1D *h_BackgroundSignal_stack_1 = new TH1D("h_BackgroundSignal_stack_1","",4,0.2,0.6);
   h_BackgroundSignal_stack_1->SetEntries(843);
   h_BackgroundSignal_stack_1->SetFillColor(8);

   ci = TColor::GetColor("#000099");
   h_BackgroundSignal_stack_1->SetLineColor(ci);
   h_BackgroundSignal_stack_1->GetXaxis()->SetTitle("Invariant Mass (GeV)");
   h_BackgroundSignal_stack_1->GetXaxis()->SetLabelFont(42);
   h_BackgroundSignal_stack_1->GetXaxis()->SetLabelSize(0.035);
   h_BackgroundSignal_stack_1->GetXaxis()->SetTitleSize(0.035);
   h_BackgroundSignal_stack_1->GetXaxis()->SetTitleFont(42);
   h_BackgroundSignal_stack_1->GetYaxis()->SetTitle("Events/bin");
   h_BackgroundSignal_stack_1->GetYaxis()->SetLabelFont(42);
   h_BackgroundSignal_stack_1->GetYaxis()->SetLabelSize(0.035);
   h_BackgroundSignal_stack_1->GetYaxis()->SetTitleSize(0.035);
   h_BackgroundSignal_stack_1->GetYaxis()->SetTitleOffset(0);
   h_BackgroundSignal_stack_1->GetYaxis()->SetTitleFont(42);
   h_BackgroundSignal_stack_1->GetZaxis()->SetLabelFont(42);
   h_BackgroundSignal_stack_1->GetZaxis()->SetLabelSize(0.035);
   h_BackgroundSignal_stack_1->GetZaxis()->SetTitleSize(0.035);
   h_BackgroundSignal_stack_1->GetZaxis()->SetTitleFont(42);
   hs->Add(h_BackgroundSignal_stack_1,"HIST");
   
   TH1D *h_BackgroundOther_stack_2 = new TH1D("h_BackgroundOther_stack_2","",4,0.2,0.6);
   h_BackgroundOther_stack_2->SetEntries(874);
   h_BackgroundOther_stack_2->SetFillColor(30);

   ci = TColor::GetColor("#000099");
   h_BackgroundOther_stack_2->SetLineColor(ci);
   h_BackgroundOther_stack_2->GetXaxis()->SetTitle("Invariant Mass (GeV)");
   h_BackgroundOther_stack_2->GetXaxis()->SetLabelFont(42);
   h_BackgroundOther_stack_2->GetXaxis()->SetLabelSize(0.035);
   h_BackgroundOther_stack_2->GetXaxis()->SetTitleSize(0.035);
   h_BackgroundOther_stack_2->GetXaxis()->SetTitleFont(42);
   h_BackgroundOther_stack_2->GetYaxis()->SetTitle("Events/bin");
   h_BackgroundOther_stack_2->GetYaxis()->SetLabelFont(42);
   h_BackgroundOther_stack_2->GetYaxis()->SetLabelSize(0.035);
   h_BackgroundOther_stack_2->GetYaxis()->SetTitleSize(0.035);
   h_BackgroundOther_stack_2->GetYaxis()->SetTitleOffset(0);
   h_BackgroundOther_stack_2->GetYaxis()->SetTitleFont(42);
   h_BackgroundOther_stack_2->GetZaxis()->SetLabelFont(42);
   h_BackgroundOther_stack_2->GetZaxis()->SetLabelSize(0.035);
   h_BackgroundOther_stack_2->GetZaxis()->SetTitleSize(0.035);
   h_BackgroundOther_stack_2->GetZaxis()->SetTitleFont(42);
   hs->Add(h_BackgroundOther_stack_2,"HIST");
   
   TH1D *h_BackgroundDirt_stack_3 = new TH1D("h_BackgroundDirt_stack_3","",4,0.2,0.6);
   h_BackgroundDirt_stack_3->SetFillColor(38);

   ci = TColor::GetColor("#000099");
   h_BackgroundDirt_stack_3->SetLineColor(ci);
   h_BackgroundDirt_stack_3->GetXaxis()->SetTitle("Invariant Mass (GeV)");
   h_BackgroundDirt_stack_3->GetXaxis()->SetLabelFont(42);
   h_BackgroundDirt_stack_3->GetXaxis()->SetLabelSize(0.035);
   h_BackgroundDirt_stack_3->GetXaxis()->SetTitleSize(0.035);
   h_BackgroundDirt_stack_3->GetXaxis()->SetTitleFont(42);
   h_BackgroundDirt_stack_3->GetYaxis()->SetTitle("Events/bin");
   h_BackgroundDirt_stack_3->GetYaxis()->SetLabelFont(42);
   h_BackgroundDirt_stack_3->GetYaxis()->SetLabelSize(0.035);
   h_BackgroundDirt_stack_3->GetYaxis()->SetTitleSize(0.035);
   h_BackgroundDirt_stack_3->GetYaxis()->SetTitleOffset(0);
   h_BackgroundDirt_stack_3->GetYaxis()->SetTitleFont(42);
   h_BackgroundDirt_stack_3->GetZaxis()->SetLabelFont(42);
   h_BackgroundDirt_stack_3->GetZaxis()->SetLabelSize(0.035);
   h_BackgroundDirt_stack_3->GetZaxis()->SetTitleSize(0.035);
   h_BackgroundDirt_stack_3->GetZaxis()->SetTitleFont(42);
   hs->Add(h_BackgroundDirt_stack_3,"HIST");
   
   TH1D *h_BackgroundCosmic_stack_4 = new TH1D("h_BackgroundCosmic_stack_4","",4,0.2,0.6);
   h_BackgroundCosmic_stack_4->SetFillColor(15);

   ci = TColor::GetColor("#000099");
   h_BackgroundCosmic_stack_4->SetLineColor(ci);
   h_BackgroundCosmic_stack_4->GetXaxis()->SetTitle("Invariant Mass (GeV)");
   h_BackgroundCosmic_stack_4->GetXaxis()->SetLabelFont(42);
   h_BackgroundCosmic_stack_4->GetXaxis()->SetLabelSize(0.035);
   h_BackgroundCosmic_stack_4->GetXaxis()->SetTitleSize(0.035);
   h_BackgroundCosmic_stack_4->GetXaxis()->SetTitleFont(42);
   h_BackgroundCosmic_stack_4->GetYaxis()->SetTitle("Events/bin");
   h_BackgroundCosmic_stack_4->GetYaxis()->SetLabelFont(42);
   h_BackgroundCosmic_stack_4->GetYaxis()->SetLabelSize(0.035);
   h_BackgroundCosmic_stack_4->GetYaxis()->SetTitleSize(0.035);
   h_BackgroundCosmic_stack_4->GetYaxis()->SetTitleOffset(0);
   h_BackgroundCosmic_stack_4->GetYaxis()->SetTitleFont(42);
   h_BackgroundCosmic_stack_4->GetZaxis()->SetLabelFont(42);
   h_BackgroundCosmic_stack_4->GetZaxis()->SetLabelSize(0.035);
   h_BackgroundCosmic_stack_4->GetZaxis()->SetTitleSize(0.035);
   h_BackgroundCosmic_stack_4->GetZaxis()->SetTitleFont(42);
   hs->Add(h_BackgroundCosmic_stack_4,"HIST");
   hs->Draw("hist same");
   
   TH1D *h_errors__5 = new TH1D("h_errors__5","",4,0.2,0.6);
   h_errors__5->SetMinimum(0);
   h_errors__5->SetMaximum(0);
   h_errors__5->SetEntries(1717);
   h_errors__5->SetStats(0);
   h_errors__5->SetFillColor(1);
   h_errors__5->SetFillStyle(3253);

   ci = TColor::GetColor("#000099");
   h_errors__5->SetLineColor(ci);
   h_errors__5->GetXaxis()->SetTitle("Invariant Mass (GeV)");
   h_errors__5->GetXaxis()->SetLabelFont(42);
   h_errors__5->GetXaxis()->SetLabelSize(0.045);
   h_errors__5->GetXaxis()->SetTitleSize(0.05);
   h_errors__5->GetXaxis()->SetTitleOffset(0.93);
   h_errors__5->GetXaxis()->SetTitleFont(42);
   h_errors__5->GetYaxis()->SetTitle("Events/bin");
   h_errors__5->GetYaxis()->SetLabelFont(42);
   h_errors__5->GetYaxis()->SetLabelSize(0.045);
   h_errors__5->GetYaxis()->SetTitleSize(0.05);
   h_errors__5->GetYaxis()->SetTitleOffset(1.06);
   h_errors__5->GetYaxis()->SetTitleFont(42);
   h_errors__5->GetZaxis()->SetLabelFont(42);
   h_errors__5->GetZaxis()->SetLabelSize(0.035);
   h_errors__5->GetZaxis()->SetTitleSize(0.035);
   h_errors__5->GetZaxis()->SetTitleFont(42);
   h_errors__5->Draw("E2 same");
   
   TH1D *h_errors_copy__6 = new TH1D("h_errors_copy__6","",4,0.2,0.6);
   h_errors_copy__6->SetMinimum(0);
   h_errors_copy__6->SetMaximum(0);
   h_errors_copy__6->SetEntries(1717);
   h_errors_copy__6->SetDirectory(0);
   h_errors_copy__6->SetStats(0);
   h_errors_copy__6->SetFillColor(1);
   h_errors_copy__6->SetFillStyle(3253);

   ci = TColor::GetColor("#000099");
   h_errors_copy__6->SetLineColor(ci);
   h_errors_copy__6->GetXaxis()->SetTitle("Invariant Mass (GeV)");
   h_errors_copy__6->GetXaxis()->SetLabelFont(42);
   h_errors_copy__6->GetXaxis()->SetLabelSize(0.045);
   h_errors_copy__6->GetXaxis()->SetTitleSize(0.05);
   h_errors_copy__6->GetXaxis()->SetTitleOffset(0.93);
   h_errors_copy__6->GetXaxis()->SetTitleFont(42);
   h_errors_copy__6->GetYaxis()->SetTitle("Events/bin");
   h_errors_copy__6->GetYaxis()->SetLabelFont(42);
   h_errors_copy__6->GetYaxis()->SetLabelSize(0.045);
   h_errors_copy__6->GetYaxis()->SetTitleSize(0.05);
   h_errors_copy__6->GetYaxis()->SetTitleOffset(1.06);
   h_errors_copy__6->GetYaxis()->SetTitleFont(42);
   h_errors_copy__6->GetZaxis()->SetLabelFont(42);
   h_errors_copy__6->GetZaxis()->SetLabelSize(0.035);
   h_errors_copy__6->GetZaxis()->SetTitleSize(0.035);
   h_errors_copy__6->GetZaxis()->SetTitleFont(42);
   h_errors_copy__6->Draw("sameaxis");
   
   leg = new TLegend(0.54,0.815,0.885,0.9,NULL,"brNDC");
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
   p_plot->Modified();
   c->cd();
   c->Modified();
   c->cd();
   c->SetSelected(c);
}
