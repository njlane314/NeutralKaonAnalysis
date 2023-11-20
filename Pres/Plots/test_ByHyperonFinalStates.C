void test_ByHyperonFinalStates()
{
//=========Macro generated from canvas: c/c
//=========  (Sun Nov 19 15:01:37 2023) by ROOT version 6.12/06
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
   TLegendEntry *entry=leg->AddEntry("h_ByHyperonDecayChannel_SigmaPlus","K^{0} #Sigma^{+} X_{hd}","F");

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#3333ff");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#000099");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("h_ByHyperonDecayChannel_Lambda"," K^{0} #Lambda X_{hd}","F");

   ci = TColor::GetColor("#ffcc00");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#000099");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("h_ByHyperonDecayChannel_SigmaMinus","K^{0} #Sigma^{-} X_{hd}","F");

   ci = TColor::GetColor("#ff00ff");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#000099");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("h_ByHyperonDecayChannel_Kaon","K^{0} X_{hd}","F");

   ci = TColor::GetColor("#00cccc");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#000099");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("h_ByHyperonDecayChannel_Other","Other","F");

   ci = TColor::GetColor("#ff99cc");
   entry->SetFillColor(ci);
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
   p_plot->Range(-0.1,-0.1123596,0.9,1.011236);
   p_plot->SetFillColor(0);
   p_plot->SetBorderMode(0);
   p_plot->SetBorderSize(2);
   p_plot->SetTopMargin(0.01);
   p_plot->SetFrameBorderMode(0);
   p_plot->SetFrameBorderMode(0);
   
   TH1D *h_errors__16 = new TH1D("h_errors__16","",8,0,0.8);
   h_errors__16->SetMinimum(0);
   h_errors__16->SetMaximum(0);
   h_errors__16->SetStats(0);
   h_errors__16->SetFillColor(1);
   h_errors__16->SetFillStyle(3253);

   ci = TColor::GetColor("#000099");
   h_errors__16->SetLineColor(ci);
   h_errors__16->GetXaxis()->SetTitle("Reconstructed Invariant Mass of Pion Pair (GeV)");
   h_errors__16->GetXaxis()->SetLabelFont(42);
   h_errors__16->GetXaxis()->SetLabelSize(0.045);
   h_errors__16->GetXaxis()->SetTitleSize(0.05);
   h_errors__16->GetXaxis()->SetTitleOffset(0.93);
   h_errors__16->GetXaxis()->SetTitleFont(42);
   h_errors__16->GetYaxis()->SetTitle("Events/bin");
   h_errors__16->GetYaxis()->SetLabelFont(42);
   h_errors__16->GetYaxis()->SetLabelSize(0.045);
   h_errors__16->GetYaxis()->SetTitleSize(0.05);
   h_errors__16->GetYaxis()->SetTitleOffset(1.06);
   h_errors__16->GetYaxis()->SetTitleFont(42);
   h_errors__16->GetZaxis()->SetLabelFont(42);
   h_errors__16->GetZaxis()->SetLabelSize(0.035);
   h_errors__16->GetZaxis()->SetTitleSize(0.035);
   h_errors__16->GetZaxis()->SetTitleFont(42);
   h_errors__16->Draw("E2");
   
   THStack *hs = new THStack();
   hs->SetName("hs");
   hs->SetTitle("");
   
   TH1F *hs_stack_11 = new TH1F("hs_stack_11","",8,0,0.8);
   hs_stack_11->SetMinimum(0);
   hs_stack_11->SetMaximum(0);
   hs_stack_11->SetDirectory(0);
   hs_stack_11->SetStats(0);

   ci = TColor::GetColor("#000099");
   hs_stack_11->SetLineColor(ci);
   hs_stack_11->GetXaxis()->SetLabelFont(42);
   hs_stack_11->GetXaxis()->SetLabelSize(0.035);
   hs_stack_11->GetXaxis()->SetTitleSize(0.035);
   hs_stack_11->GetXaxis()->SetTitleFont(42);
   hs_stack_11->GetYaxis()->SetLabelFont(42);
   hs_stack_11->GetYaxis()->SetLabelSize(0.035);
   hs_stack_11->GetYaxis()->SetTitleSize(0.035);
   hs_stack_11->GetYaxis()->SetTitleOffset(0);
   hs_stack_11->GetYaxis()->SetTitleFont(42);
   hs_stack_11->GetZaxis()->SetLabelFont(42);
   hs_stack_11->GetZaxis()->SetLabelSize(0.035);
   hs_stack_11->GetZaxis()->SetTitleSize(0.035);
   hs_stack_11->GetZaxis()->SetTitleFont(42);
   hs->SetHistogram(hs_stack_11);
   
   
   TH1D *h_ByHyperonDecayChannel_SigmaPlus_stack_1 = new TH1D("h_ByHyperonDecayChannel_SigmaPlus_stack_1","",8,0,0.8);

   ci = TColor::GetColor("#3333ff");
   h_ByHyperonDecayChannel_SigmaPlus_stack_1->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   h_ByHyperonDecayChannel_SigmaPlus_stack_1->SetLineColor(ci);
   h_ByHyperonDecayChannel_SigmaPlus_stack_1->GetXaxis()->SetTitle("Reconstructed Invariant Mass of Pion Pair (GeV)");
   h_ByHyperonDecayChannel_SigmaPlus_stack_1->GetXaxis()->SetLabelFont(42);
   h_ByHyperonDecayChannel_SigmaPlus_stack_1->GetXaxis()->SetLabelSize(0.035);
   h_ByHyperonDecayChannel_SigmaPlus_stack_1->GetXaxis()->SetTitleSize(0.035);
   h_ByHyperonDecayChannel_SigmaPlus_stack_1->GetXaxis()->SetTitleFont(42);
   h_ByHyperonDecayChannel_SigmaPlus_stack_1->GetYaxis()->SetTitle("Events/bin");
   h_ByHyperonDecayChannel_SigmaPlus_stack_1->GetYaxis()->SetLabelFont(42);
   h_ByHyperonDecayChannel_SigmaPlus_stack_1->GetYaxis()->SetLabelSize(0.035);
   h_ByHyperonDecayChannel_SigmaPlus_stack_1->GetYaxis()->SetTitleSize(0.035);
   h_ByHyperonDecayChannel_SigmaPlus_stack_1->GetYaxis()->SetTitleOffset(0);
   h_ByHyperonDecayChannel_SigmaPlus_stack_1->GetYaxis()->SetTitleFont(42);
   h_ByHyperonDecayChannel_SigmaPlus_stack_1->GetZaxis()->SetLabelFont(42);
   h_ByHyperonDecayChannel_SigmaPlus_stack_1->GetZaxis()->SetLabelSize(0.035);
   h_ByHyperonDecayChannel_SigmaPlus_stack_1->GetZaxis()->SetTitleSize(0.035);
   h_ByHyperonDecayChannel_SigmaPlus_stack_1->GetZaxis()->SetTitleFont(42);
   hs->Add(h_ByHyperonDecayChannel_SigmaPlus_stack_1,"HIST");
   
   TH1D *h_ByHyperonDecayChannel_Lambda_stack_2 = new TH1D("h_ByHyperonDecayChannel_Lambda_stack_2","",8,0,0.8);

   ci = TColor::GetColor("#ffcc00");
   h_ByHyperonDecayChannel_Lambda_stack_2->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   h_ByHyperonDecayChannel_Lambda_stack_2->SetLineColor(ci);
   h_ByHyperonDecayChannel_Lambda_stack_2->GetXaxis()->SetTitle("Reconstructed Invariant Mass of Pion Pair (GeV)");
   h_ByHyperonDecayChannel_Lambda_stack_2->GetXaxis()->SetLabelFont(42);
   h_ByHyperonDecayChannel_Lambda_stack_2->GetXaxis()->SetLabelSize(0.035);
   h_ByHyperonDecayChannel_Lambda_stack_2->GetXaxis()->SetTitleSize(0.035);
   h_ByHyperonDecayChannel_Lambda_stack_2->GetXaxis()->SetTitleFont(42);
   h_ByHyperonDecayChannel_Lambda_stack_2->GetYaxis()->SetTitle("Events/bin");
   h_ByHyperonDecayChannel_Lambda_stack_2->GetYaxis()->SetLabelFont(42);
   h_ByHyperonDecayChannel_Lambda_stack_2->GetYaxis()->SetLabelSize(0.035);
   h_ByHyperonDecayChannel_Lambda_stack_2->GetYaxis()->SetTitleSize(0.035);
   h_ByHyperonDecayChannel_Lambda_stack_2->GetYaxis()->SetTitleOffset(0);
   h_ByHyperonDecayChannel_Lambda_stack_2->GetYaxis()->SetTitleFont(42);
   h_ByHyperonDecayChannel_Lambda_stack_2->GetZaxis()->SetLabelFont(42);
   h_ByHyperonDecayChannel_Lambda_stack_2->GetZaxis()->SetLabelSize(0.035);
   h_ByHyperonDecayChannel_Lambda_stack_2->GetZaxis()->SetTitleSize(0.035);
   h_ByHyperonDecayChannel_Lambda_stack_2->GetZaxis()->SetTitleFont(42);
   hs->Add(h_ByHyperonDecayChannel_Lambda_stack_2,"HIST");
   
   TH1D *h_ByHyperonDecayChannel_SigmaMinus_stack_3 = new TH1D("h_ByHyperonDecayChannel_SigmaMinus_stack_3","",8,0,0.8);

   ci = TColor::GetColor("#ff00ff");
   h_ByHyperonDecayChannel_SigmaMinus_stack_3->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   h_ByHyperonDecayChannel_SigmaMinus_stack_3->SetLineColor(ci);
   h_ByHyperonDecayChannel_SigmaMinus_stack_3->GetXaxis()->SetTitle("Reconstructed Invariant Mass of Pion Pair (GeV)");
   h_ByHyperonDecayChannel_SigmaMinus_stack_3->GetXaxis()->SetLabelFont(42);
   h_ByHyperonDecayChannel_SigmaMinus_stack_3->GetXaxis()->SetLabelSize(0.035);
   h_ByHyperonDecayChannel_SigmaMinus_stack_3->GetXaxis()->SetTitleSize(0.035);
   h_ByHyperonDecayChannel_SigmaMinus_stack_3->GetXaxis()->SetTitleFont(42);
   h_ByHyperonDecayChannel_SigmaMinus_stack_3->GetYaxis()->SetTitle("Events/bin");
   h_ByHyperonDecayChannel_SigmaMinus_stack_3->GetYaxis()->SetLabelFont(42);
   h_ByHyperonDecayChannel_SigmaMinus_stack_3->GetYaxis()->SetLabelSize(0.035);
   h_ByHyperonDecayChannel_SigmaMinus_stack_3->GetYaxis()->SetTitleSize(0.035);
   h_ByHyperonDecayChannel_SigmaMinus_stack_3->GetYaxis()->SetTitleOffset(0);
   h_ByHyperonDecayChannel_SigmaMinus_stack_3->GetYaxis()->SetTitleFont(42);
   h_ByHyperonDecayChannel_SigmaMinus_stack_3->GetZaxis()->SetLabelFont(42);
   h_ByHyperonDecayChannel_SigmaMinus_stack_3->GetZaxis()->SetLabelSize(0.035);
   h_ByHyperonDecayChannel_SigmaMinus_stack_3->GetZaxis()->SetTitleSize(0.035);
   h_ByHyperonDecayChannel_SigmaMinus_stack_3->GetZaxis()->SetTitleFont(42);
   hs->Add(h_ByHyperonDecayChannel_SigmaMinus_stack_3,"HIST");
   
   TH1D *h_ByHyperonDecayChannel_Kaon_stack_4 = new TH1D("h_ByHyperonDecayChannel_Kaon_stack_4","",8,0,0.8);

   ci = TColor::GetColor("#00cccc");
   h_ByHyperonDecayChannel_Kaon_stack_4->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   h_ByHyperonDecayChannel_Kaon_stack_4->SetLineColor(ci);
   h_ByHyperonDecayChannel_Kaon_stack_4->GetXaxis()->SetTitle("Reconstructed Invariant Mass of Pion Pair (GeV)");
   h_ByHyperonDecayChannel_Kaon_stack_4->GetXaxis()->SetLabelFont(42);
   h_ByHyperonDecayChannel_Kaon_stack_4->GetXaxis()->SetLabelSize(0.035);
   h_ByHyperonDecayChannel_Kaon_stack_4->GetXaxis()->SetTitleSize(0.035);
   h_ByHyperonDecayChannel_Kaon_stack_4->GetXaxis()->SetTitleFont(42);
   h_ByHyperonDecayChannel_Kaon_stack_4->GetYaxis()->SetTitle("Events/bin");
   h_ByHyperonDecayChannel_Kaon_stack_4->GetYaxis()->SetLabelFont(42);
   h_ByHyperonDecayChannel_Kaon_stack_4->GetYaxis()->SetLabelSize(0.035);
   h_ByHyperonDecayChannel_Kaon_stack_4->GetYaxis()->SetTitleSize(0.035);
   h_ByHyperonDecayChannel_Kaon_stack_4->GetYaxis()->SetTitleOffset(0);
   h_ByHyperonDecayChannel_Kaon_stack_4->GetYaxis()->SetTitleFont(42);
   h_ByHyperonDecayChannel_Kaon_stack_4->GetZaxis()->SetLabelFont(42);
   h_ByHyperonDecayChannel_Kaon_stack_4->GetZaxis()->SetLabelSize(0.035);
   h_ByHyperonDecayChannel_Kaon_stack_4->GetZaxis()->SetTitleSize(0.035);
   h_ByHyperonDecayChannel_Kaon_stack_4->GetZaxis()->SetTitleFont(42);
   hs->Add(h_ByHyperonDecayChannel_Kaon_stack_4,"HIST");
   
   TH1D *h_ByHyperonDecayChannel_Other_stack_5 = new TH1D("h_ByHyperonDecayChannel_Other_stack_5","",8,0,0.8);

   ci = TColor::GetColor("#ff99cc");
   h_ByHyperonDecayChannel_Other_stack_5->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   h_ByHyperonDecayChannel_Other_stack_5->SetLineColor(ci);
   h_ByHyperonDecayChannel_Other_stack_5->GetXaxis()->SetTitle("Reconstructed Invariant Mass of Pion Pair (GeV)");
   h_ByHyperonDecayChannel_Other_stack_5->GetXaxis()->SetLabelFont(42);
   h_ByHyperonDecayChannel_Other_stack_5->GetXaxis()->SetLabelSize(0.035);
   h_ByHyperonDecayChannel_Other_stack_5->GetXaxis()->SetTitleSize(0.035);
   h_ByHyperonDecayChannel_Other_stack_5->GetXaxis()->SetTitleFont(42);
   h_ByHyperonDecayChannel_Other_stack_5->GetYaxis()->SetTitle("Events/bin");
   h_ByHyperonDecayChannel_Other_stack_5->GetYaxis()->SetLabelFont(42);
   h_ByHyperonDecayChannel_Other_stack_5->GetYaxis()->SetLabelSize(0.035);
   h_ByHyperonDecayChannel_Other_stack_5->GetYaxis()->SetTitleSize(0.035);
   h_ByHyperonDecayChannel_Other_stack_5->GetYaxis()->SetTitleOffset(0);
   h_ByHyperonDecayChannel_Other_stack_5->GetYaxis()->SetTitleFont(42);
   h_ByHyperonDecayChannel_Other_stack_5->GetZaxis()->SetLabelFont(42);
   h_ByHyperonDecayChannel_Other_stack_5->GetZaxis()->SetLabelSize(0.035);
   h_ByHyperonDecayChannel_Other_stack_5->GetZaxis()->SetTitleSize(0.035);
   h_ByHyperonDecayChannel_Other_stack_5->GetZaxis()->SetTitleFont(42);
   hs->Add(h_ByHyperonDecayChannel_Other_stack_5,"HIST");
   hs->Draw("hist same");
   
   TH1D *h_errors__17 = new TH1D("h_errors__17","",8,0,0.8);
   h_errors__17->SetMinimum(0);
   h_errors__17->SetMaximum(0);
   h_errors__17->SetStats(0);
   h_errors__17->SetFillColor(1);
   h_errors__17->SetFillStyle(3253);

   ci = TColor::GetColor("#000099");
   h_errors__17->SetLineColor(ci);
   h_errors__17->GetXaxis()->SetTitle("Reconstructed Invariant Mass of Pion Pair (GeV)");
   h_errors__17->GetXaxis()->SetLabelFont(42);
   h_errors__17->GetXaxis()->SetLabelSize(0.045);
   h_errors__17->GetXaxis()->SetTitleSize(0.05);
   h_errors__17->GetXaxis()->SetTitleOffset(0.93);
   h_errors__17->GetXaxis()->SetTitleFont(42);
   h_errors__17->GetYaxis()->SetTitle("Events/bin");
   h_errors__17->GetYaxis()->SetLabelFont(42);
   h_errors__17->GetYaxis()->SetLabelSize(0.045);
   h_errors__17->GetYaxis()->SetTitleSize(0.05);
   h_errors__17->GetYaxis()->SetTitleOffset(1.06);
   h_errors__17->GetYaxis()->SetTitleFont(42);
   h_errors__17->GetZaxis()->SetLabelFont(42);
   h_errors__17->GetZaxis()->SetLabelSize(0.035);
   h_errors__17->GetZaxis()->SetTitleSize(0.035);
   h_errors__17->GetZaxis()->SetTitleFont(42);
   h_errors__17->Draw("E2 same");
   
   TH1D *h_errors_copy__18 = new TH1D("h_errors_copy__18","",8,0,0.8);
   h_errors_copy__18->SetMinimum(0);
   h_errors_copy__18->SetMaximum(0);
   h_errors_copy__18->SetDirectory(0);
   h_errors_copy__18->SetStats(0);
   h_errors_copy__18->SetFillColor(1);
   h_errors_copy__18->SetFillStyle(3253);

   ci = TColor::GetColor("#000099");
   h_errors_copy__18->SetLineColor(ci);
   h_errors_copy__18->GetXaxis()->SetTitle("Reconstructed Invariant Mass of Pion Pair (GeV)");
   h_errors_copy__18->GetXaxis()->SetLabelFont(42);
   h_errors_copy__18->GetXaxis()->SetLabelSize(0.045);
   h_errors_copy__18->GetXaxis()->SetTitleSize(0.05);
   h_errors_copy__18->GetXaxis()->SetTitleOffset(0.93);
   h_errors_copy__18->GetXaxis()->SetTitleFont(42);
   h_errors_copy__18->GetYaxis()->SetTitle("Events/bin");
   h_errors_copy__18->GetYaxis()->SetLabelFont(42);
   h_errors_copy__18->GetYaxis()->SetLabelSize(0.045);
   h_errors_copy__18->GetYaxis()->SetTitleSize(0.05);
   h_errors_copy__18->GetYaxis()->SetTitleOffset(1.06);
   h_errors_copy__18->GetYaxis()->SetTitleFont(42);
   h_errors_copy__18->GetZaxis()->SetLabelFont(42);
   h_errors_copy__18->GetZaxis()->SetLabelSize(0.035);
   h_errors_copy__18->GetZaxis()->SetTitleSize(0.035);
   h_errors_copy__18->GetZaxis()->SetTitleFont(42);
   h_errors_copy__18->Draw("sameaxis");
   
   leg = new TLegend(0.54,0.815,0.885,0.9,NULL,"brNDC");
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
   p_plot->Modified();
   c->cd();
   c->Modified();
   c->cd();
   c->SetSelected(c);
}
