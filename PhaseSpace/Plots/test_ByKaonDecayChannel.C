void test_ByKaonDecayChannel()
{
//=========Macro generated from canvas: c/c
//=========  (Thu Nov 23 05:52:22 2023) by ROOT version 6.12/06
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
   TLegendEntry *entry=leg->AddEntry("h_ByKaonDecayChannel_-211_211","#pi^{-}#pi^{+}","F");

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
   entry=leg->AddEntry("h_ByKaonDecayChannel_111_111","#pi^{0}#pi^{0}","F");

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
   entry=leg->AddEntry("h_ByKaonDecayChannel_","Other","F");

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
   leg->Draw();
   p_legend->Modified();
   c->cd();
  
// ------------>Primitives in pad: p_plot
   TPad *p_plot = new TPad("p_plot", "p_plot",0,0,1,0.85);
   p_plot->Draw();
   p_plot->cd();
   p_plot->Range(-0.25,-5.592139,2.25,50.32925);
   p_plot->SetFillColor(0);
   p_plot->SetBorderMode(0);
   p_plot->SetBorderSize(2);
   p_plot->SetTopMargin(0.01);
   p_plot->SetFrameBorderMode(0);
   p_plot->SetFrameBorderMode(0);
   
   TH1D *h_errors__13 = new TH1D("h_errors__13","",2,0,2);
   h_errors__13->SetBinContent(2,38.8694);
   h_errors__13->SetBinError(2,0.9466274);
   h_errors__13->SetMinimum(0);
   h_errors__13->SetMaximum(49.77004);
   h_errors__13->SetEntries(1686);
   h_errors__13->SetStats(0);
   h_errors__13->SetFillColor(1);
   h_errors__13->SetFillStyle(3253);

   ci = TColor::GetColor("#000099");
   h_errors__13->SetLineColor(ci);
   h_errors__13->GetXaxis()->SetTitle("Hyperon Multiplicity");
   h_errors__13->GetXaxis()->SetLabelFont(42);
   h_errors__13->GetXaxis()->SetLabelSize(0.045);
   h_errors__13->GetXaxis()->SetTitleSize(0.05);
   h_errors__13->GetXaxis()->SetTitleOffset(0.93);
   h_errors__13->GetXaxis()->SetTitleFont(42);
   h_errors__13->GetYaxis()->SetTitle("Events/bin");
   h_errors__13->GetYaxis()->SetLabelFont(42);
   h_errors__13->GetYaxis()->SetLabelSize(0.045);
   h_errors__13->GetYaxis()->SetTitleSize(0.05);
   h_errors__13->GetYaxis()->SetTitleOffset(1.06);
   h_errors__13->GetYaxis()->SetTitleFont(42);
   h_errors__13->GetZaxis()->SetLabelFont(42);
   h_errors__13->GetZaxis()->SetLabelSize(0.035);
   h_errors__13->GetZaxis()->SetTitleSize(0.035);
   h_errors__13->GetZaxis()->SetTitleFont(42);
   h_errors__13->Draw("E2");
   
   THStack *hs = new THStack();
   hs->SetName("hs");
   hs->SetTitle("");
   
   TH1F *hs_stack_11 = new TH1F("hs_stack_11","",2,0,2);
   hs_stack_11->SetMinimum(0);
   hs_stack_11->SetMaximum(41.78233);
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
   
   
   TH1D *h_ByKaonDecayChannel_mI211_211_stack_1 = new TH1D("h_ByKaonDecayChannel_mI211_211_stack_1","",2,0,2);
   h_ByKaonDecayChannel_mI211_211_stack_1->SetBinContent(2,38.84635);
   h_ByKaonDecayChannel_mI211_211_stack_1->SetBinError(2,0.9463467);
   h_ByKaonDecayChannel_mI211_211_stack_1->SetEntries(1685);

   ci = TColor::GetColor("#3333ff");
   h_ByKaonDecayChannel_mI211_211_stack_1->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   h_ByKaonDecayChannel_mI211_211_stack_1->SetLineColor(ci);
   h_ByKaonDecayChannel_mI211_211_stack_1->GetXaxis()->SetTitle("Hyperon Multiplicity");
   h_ByKaonDecayChannel_mI211_211_stack_1->GetXaxis()->SetLabelFont(42);
   h_ByKaonDecayChannel_mI211_211_stack_1->GetXaxis()->SetLabelSize(0.035);
   h_ByKaonDecayChannel_mI211_211_stack_1->GetXaxis()->SetTitleSize(0.035);
   h_ByKaonDecayChannel_mI211_211_stack_1->GetXaxis()->SetTitleFont(42);
   h_ByKaonDecayChannel_mI211_211_stack_1->GetYaxis()->SetTitle("Events/bin");
   h_ByKaonDecayChannel_mI211_211_stack_1->GetYaxis()->SetLabelFont(42);
   h_ByKaonDecayChannel_mI211_211_stack_1->GetYaxis()->SetLabelSize(0.035);
   h_ByKaonDecayChannel_mI211_211_stack_1->GetYaxis()->SetTitleSize(0.035);
   h_ByKaonDecayChannel_mI211_211_stack_1->GetYaxis()->SetTitleOffset(0);
   h_ByKaonDecayChannel_mI211_211_stack_1->GetYaxis()->SetTitleFont(42);
   h_ByKaonDecayChannel_mI211_211_stack_1->GetZaxis()->SetLabelFont(42);
   h_ByKaonDecayChannel_mI211_211_stack_1->GetZaxis()->SetLabelSize(0.035);
   h_ByKaonDecayChannel_mI211_211_stack_1->GetZaxis()->SetTitleSize(0.035);
   h_ByKaonDecayChannel_mI211_211_stack_1->GetZaxis()->SetTitleFont(42);
   hs->Add(h_ByKaonDecayChannel_-211_211_stack_1,"HIST");
   
   TH1D *h_ByKaonDecayChannel_111_111_stack_2 = new TH1D("h_ByKaonDecayChannel_111_111_stack_2","",2,0,2);

   ci = TColor::GetColor("#ffcc00");
   h_ByKaonDecayChannel_111_111_stack_2->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   h_ByKaonDecayChannel_111_111_stack_2->SetLineColor(ci);
   h_ByKaonDecayChannel_111_111_stack_2->GetXaxis()->SetTitle("Hyperon Multiplicity");
   h_ByKaonDecayChannel_111_111_stack_2->GetXaxis()->SetLabelFont(42);
   h_ByKaonDecayChannel_111_111_stack_2->GetXaxis()->SetLabelSize(0.035);
   h_ByKaonDecayChannel_111_111_stack_2->GetXaxis()->SetTitleSize(0.035);
   h_ByKaonDecayChannel_111_111_stack_2->GetXaxis()->SetTitleFont(42);
   h_ByKaonDecayChannel_111_111_stack_2->GetYaxis()->SetTitle("Events/bin");
   h_ByKaonDecayChannel_111_111_stack_2->GetYaxis()->SetLabelFont(42);
   h_ByKaonDecayChannel_111_111_stack_2->GetYaxis()->SetLabelSize(0.035);
   h_ByKaonDecayChannel_111_111_stack_2->GetYaxis()->SetTitleSize(0.035);
   h_ByKaonDecayChannel_111_111_stack_2->GetYaxis()->SetTitleOffset(0);
   h_ByKaonDecayChannel_111_111_stack_2->GetYaxis()->SetTitleFont(42);
   h_ByKaonDecayChannel_111_111_stack_2->GetZaxis()->SetLabelFont(42);
   h_ByKaonDecayChannel_111_111_stack_2->GetZaxis()->SetLabelSize(0.035);
   h_ByKaonDecayChannel_111_111_stack_2->GetZaxis()->SetTitleSize(0.035);
   h_ByKaonDecayChannel_111_111_stack_2->GetZaxis()->SetTitleFont(42);
   hs->Add(h_ByKaonDecayChannel_111_111_stack_2,"HIST");
   
   TH1D *h_ByKaonDecayChannel__stack_3 = new TH1D("h_ByKaonDecayChannel__stack_3","",2,0,2);
   h_ByKaonDecayChannel__stack_3->SetBinContent(2,0.02305421);
   h_ByKaonDecayChannel__stack_3->SetBinError(2,0.02305421);
   h_ByKaonDecayChannel__stack_3->SetEntries(1);

   ci = TColor::GetColor("#ff00ff");
   h_ByKaonDecayChannel__stack_3->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   h_ByKaonDecayChannel__stack_3->SetLineColor(ci);
   h_ByKaonDecayChannel__stack_3->GetXaxis()->SetTitle("Hyperon Multiplicity");
   h_ByKaonDecayChannel__stack_3->GetXaxis()->SetLabelFont(42);
   h_ByKaonDecayChannel__stack_3->GetXaxis()->SetLabelSize(0.035);
   h_ByKaonDecayChannel__stack_3->GetXaxis()->SetTitleSize(0.035);
   h_ByKaonDecayChannel__stack_3->GetXaxis()->SetTitleFont(42);
   h_ByKaonDecayChannel__stack_3->GetYaxis()->SetTitle("Events/bin");
   h_ByKaonDecayChannel__stack_3->GetYaxis()->SetLabelFont(42);
   h_ByKaonDecayChannel__stack_3->GetYaxis()->SetLabelSize(0.035);
   h_ByKaonDecayChannel__stack_3->GetYaxis()->SetTitleSize(0.035);
   h_ByKaonDecayChannel__stack_3->GetYaxis()->SetTitleOffset(0);
   h_ByKaonDecayChannel__stack_3->GetYaxis()->SetTitleFont(42);
   h_ByKaonDecayChannel__stack_3->GetZaxis()->SetLabelFont(42);
   h_ByKaonDecayChannel__stack_3->GetZaxis()->SetLabelSize(0.035);
   h_ByKaonDecayChannel__stack_3->GetZaxis()->SetTitleSize(0.035);
   h_ByKaonDecayChannel__stack_3->GetZaxis()->SetTitleFont(42);
   hs->Add(h_ByKaonDecayChannel__stack_3,"HIST");
   hs->Draw("hist same");
   
   TH1D *h_errors__14 = new TH1D("h_errors__14","",2,0,2);
   h_errors__14->SetBinContent(2,38.8694);
   h_errors__14->SetBinError(2,0.9466274);
   h_errors__14->SetMinimum(0);
   h_errors__14->SetMaximum(49.77004);
   h_errors__14->SetEntries(1686);
   h_errors__14->SetStats(0);
   h_errors__14->SetFillColor(1);
   h_errors__14->SetFillStyle(3253);

   ci = TColor::GetColor("#000099");
   h_errors__14->SetLineColor(ci);
   h_errors__14->GetXaxis()->SetTitle("Hyperon Multiplicity");
   h_errors__14->GetXaxis()->SetLabelFont(42);
   h_errors__14->GetXaxis()->SetLabelSize(0.045);
   h_errors__14->GetXaxis()->SetTitleSize(0.05);
   h_errors__14->GetXaxis()->SetTitleOffset(0.93);
   h_errors__14->GetXaxis()->SetTitleFont(42);
   h_errors__14->GetYaxis()->SetTitle("Events/bin");
   h_errors__14->GetYaxis()->SetLabelFont(42);
   h_errors__14->GetYaxis()->SetLabelSize(0.045);
   h_errors__14->GetYaxis()->SetTitleSize(0.05);
   h_errors__14->GetYaxis()->SetTitleOffset(1.06);
   h_errors__14->GetYaxis()->SetTitleFont(42);
   h_errors__14->GetZaxis()->SetLabelFont(42);
   h_errors__14->GetZaxis()->SetLabelSize(0.035);
   h_errors__14->GetZaxis()->SetTitleSize(0.035);
   h_errors__14->GetZaxis()->SetTitleFont(42);
   h_errors__14->Draw("E2 same");
   
   TH1D *h_errors_copy__15 = new TH1D("h_errors_copy__15","",2,0,2);
   h_errors_copy__15->SetBinContent(2,38.8694);
   h_errors_copy__15->SetBinError(2,0.9466274);
   h_errors_copy__15->SetMinimum(0);
   h_errors_copy__15->SetMaximum(49.77004);
   h_errors_copy__15->SetEntries(1686);
   h_errors_copy__15->SetDirectory(0);
   h_errors_copy__15->SetStats(0);
   h_errors_copy__15->SetFillColor(1);
   h_errors_copy__15->SetFillStyle(3253);

   ci = TColor::GetColor("#000099");
   h_errors_copy__15->SetLineColor(ci);
   h_errors_copy__15->GetXaxis()->SetTitle("Hyperon Multiplicity");
   h_errors_copy__15->GetXaxis()->SetLabelFont(42);
   h_errors_copy__15->GetXaxis()->SetLabelSize(0.045);
   h_errors_copy__15->GetXaxis()->SetTitleSize(0.05);
   h_errors_copy__15->GetXaxis()->SetTitleOffset(0.93);
   h_errors_copy__15->GetXaxis()->SetTitleFont(42);
   h_errors_copy__15->GetYaxis()->SetTitle("Events/bin");
   h_errors_copy__15->GetYaxis()->SetLabelFont(42);
   h_errors_copy__15->GetYaxis()->SetLabelSize(0.045);
   h_errors_copy__15->GetYaxis()->SetTitleSize(0.05);
   h_errors_copy__15->GetYaxis()->SetTitleOffset(1.06);
   h_errors_copy__15->GetYaxis()->SetTitleFont(42);
   h_errors_copy__15->GetZaxis()->SetLabelFont(42);
   h_errors_copy__15->GetZaxis()->SetLabelSize(0.035);
   h_errors_copy__15->GetZaxis()->SetTitleSize(0.035);
   h_errors_copy__15->GetZaxis()->SetTitleFont(42);
   h_errors_copy__15->Draw("sameaxis");
   
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
