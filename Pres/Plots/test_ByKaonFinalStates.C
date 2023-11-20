void test_ByKaonFinalStates()
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
   TLegendEntry *entry=leg->AddEntry("h_ByKaonFinalStates_nu_mu_CC-13_311_3222","#nu_{#mu}CC-#mu^{-}K^{0}#Sigma^{+}X_{h}","F");

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
   entry=leg->AddEntry("h_ByKaonFinalStates_nu_mu_NC-14_311_3122","#nu_{#mu}NC-#nu_{#mu}K^{0}#Lambda X_{h}","F");

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
   entry=leg->AddEntry("h_ByKaonFinalStates_nu_mu_CC-13_311_3122","#nu_{#mu}CC-#mu^{-}K^{0}#Lambda X_{h}","F");

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
   entry=leg->AddEntry("h_ByKaonFinalStates_nu_bar_mu_CC--13_311_3122","#bar{#nu}_{#mu}CC-#mu^{+}K^{0}#Lambda X_{h}","F");

   ci = TColor::GetColor("#00ffff");
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
   entry=leg->AddEntry("h_ByKaonFinalStates_nu_bar_mu_CC--13_311_3112","#bar{#nu}_{#mu}CC-#mu^{+}K^{0}#Sigma^{-}X_{h}","F");

   ci = TColor::GetColor("#0033ff");
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
   entry=leg->AddEntry("h_ByKaonFinalStates_nu_mu_CC-13_311_-311","#nu_{#mu}CC-#mu^{-}K^{0}#bar{K}^{0}X_{h}","F");

   ci = TColor::GetColor("#ff0033");
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
   entry=leg->AddEntry("h_ByKaonFinalStates_nu_bar_mu_NC--14_311_3122","#bar{#nu}_{#mu}NC-#bar{#nu}_{#mu}K^{0}#Lambda X_{h}","F");

   ci = TColor::GetColor("#33ff00");
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
   entry=leg->AddEntry("h_ByKaonFinalStates_nu_mu_NC-14_311_3222","#nu_{#mu}NC-#nu_{#mu}K^{0}#Sigma^{+}X_{h}","F");

   ci = TColor::GetColor("#cc00ff");
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
   entry=leg->AddEntry("h_ByKaonFinalStates_nu_mu_NC-14_311_-311","#nu_{#mu}NC-#nu_{#mu}K^{0}#bar{K}^{0}X_{h}","F");

   ci = TColor::GetColor("#000099");
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
   entry=leg->AddEntry("h_ByKaonFinalStates_nu_mu_NC-14_311_3112","#nu_{#mu}NC-#nu_{#mu}K^{0}#Sigma^{-}X_{h}","F");

   ci = TColor::GetColor("#ff0000");
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
   entry=leg->AddEntry("h_ByKaonFinalStates_nu_bar_mu_CC--13_311_-311","#nu_{#mu}NC-#nu_{#mu}K^{0}#bar{K}^{0}X_{h}","F");

   ci = TColor::GetColor("#00ff00");
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
   entry=leg->AddEntry("h_ByKaonFinalStates_nu_bar_mu_NC--14_311_3212","#bar{#nu}_{#mu}NC-#mu^{+}K^{0}#Sigma^{0}X_{h}","F");

   ci = TColor::GetColor("#ff6600");
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
   entry=leg->AddEntry("h_ByKaonFinalStates_nu_bar_mu_NC--14_311_3222","#bar{#nu}_{#mu}NC-#mu^{+}K^{0}#Sigma^{+}X_{h}","F");

   ci = TColor::GetColor("#cc00cc");
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
   entry=leg->AddEntry("h_ByKaonFinalStates_nu_mu_CC-13_311","#nu_{#mu}CC-#mu^{-}K^{0}X_{h}","F");

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
   entry=leg->AddEntry("h_ByKaonFinalStates_nu_bar_mu_CC--13_311","#bar{#nu}_{#mu}CC-#mu^{+}K^{0}X_{h}","F");

   ci = TColor::GetColor("#3399ff");
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
   entry=leg->AddEntry("h_ByKaonFinalStates_","Other","F");

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
   
   TH1D *h_errors__10 = new TH1D("h_errors__10","",8,0,0.8);
   h_errors__10->SetMinimum(0);
   h_errors__10->SetMaximum(0);
   h_errors__10->SetStats(0);
   h_errors__10->SetFillColor(1);
   h_errors__10->SetFillStyle(3253);

   ci = TColor::GetColor("#000099");
   h_errors__10->SetLineColor(ci);
   h_errors__10->GetXaxis()->SetTitle("Reconstructed Invariant Mass of Pion Pair (GeV)");
   h_errors__10->GetXaxis()->SetLabelFont(42);
   h_errors__10->GetXaxis()->SetLabelSize(0.045);
   h_errors__10->GetXaxis()->SetTitleSize(0.05);
   h_errors__10->GetXaxis()->SetTitleOffset(0.93);
   h_errors__10->GetXaxis()->SetTitleFont(42);
   h_errors__10->GetYaxis()->SetTitle("Events/bin");
   h_errors__10->GetYaxis()->SetLabelFont(42);
   h_errors__10->GetYaxis()->SetLabelSize(0.045);
   h_errors__10->GetYaxis()->SetTitleSize(0.05);
   h_errors__10->GetYaxis()->SetTitleOffset(1.06);
   h_errors__10->GetYaxis()->SetTitleFont(42);
   h_errors__10->GetZaxis()->SetLabelFont(42);
   h_errors__10->GetZaxis()->SetLabelSize(0.035);
   h_errors__10->GetZaxis()->SetTitleSize(0.035);
   h_errors__10->GetZaxis()->SetTitleFont(42);
   h_errors__10->Draw("E2");
   
   THStack *hs = new THStack();
   hs->SetName("hs");
   hs->SetTitle("");
   
   TH1F *hs_stack_9 = new TH1F("hs_stack_9","",8,0,0.8);
   hs_stack_9->SetMinimum(0);
   hs_stack_9->SetMaximum(0);
   hs_stack_9->SetDirectory(0);
   hs_stack_9->SetStats(0);

   ci = TColor::GetColor("#000099");
   hs_stack_9->SetLineColor(ci);
   hs_stack_9->GetXaxis()->SetLabelFont(42);
   hs_stack_9->GetXaxis()->SetLabelSize(0.035);
   hs_stack_9->GetXaxis()->SetTitleSize(0.035);
   hs_stack_9->GetXaxis()->SetTitleFont(42);
   hs_stack_9->GetYaxis()->SetLabelFont(42);
   hs_stack_9->GetYaxis()->SetLabelSize(0.035);
   hs_stack_9->GetYaxis()->SetTitleSize(0.035);
   hs_stack_9->GetYaxis()->SetTitleOffset(0);
   hs_stack_9->GetYaxis()->SetTitleFont(42);
   hs_stack_9->GetZaxis()->SetLabelFont(42);
   hs_stack_9->GetZaxis()->SetLabelSize(0.035);
   hs_stack_9->GetZaxis()->SetTitleSize(0.035);
   hs_stack_9->GetZaxis()->SetTitleFont(42);
   hs->SetHistogram(hs_stack_9);
   
   
   TH1D *h_ByKaonFinalStates_nu_mu_CCmI13_311_3222_stack_1 = new TH1D("h_ByKaonFinalStates_nu_mu_CCmI13_311_3222_stack_1","",8,0,0.8);

   ci = TColor::GetColor("#3333ff");
   h_ByKaonFinalStates_nu_mu_CCmI13_311_3222_stack_1->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   h_ByKaonFinalStates_nu_mu_CCmI13_311_3222_stack_1->SetLineColor(ci);
   h_ByKaonFinalStates_nu_mu_CCmI13_311_3222_stack_1->GetXaxis()->SetTitle("Reconstructed Invariant Mass of Pion Pair (GeV)");
   h_ByKaonFinalStates_nu_mu_CCmI13_311_3222_stack_1->GetXaxis()->SetLabelFont(42);
   h_ByKaonFinalStates_nu_mu_CCmI13_311_3222_stack_1->GetXaxis()->SetLabelSize(0.035);
   h_ByKaonFinalStates_nu_mu_CCmI13_311_3222_stack_1->GetXaxis()->SetTitleSize(0.035);
   h_ByKaonFinalStates_nu_mu_CCmI13_311_3222_stack_1->GetXaxis()->SetTitleFont(42);
   h_ByKaonFinalStates_nu_mu_CCmI13_311_3222_stack_1->GetYaxis()->SetTitle("Events/bin");
   h_ByKaonFinalStates_nu_mu_CCmI13_311_3222_stack_1->GetYaxis()->SetLabelFont(42);
   h_ByKaonFinalStates_nu_mu_CCmI13_311_3222_stack_1->GetYaxis()->SetLabelSize(0.035);
   h_ByKaonFinalStates_nu_mu_CCmI13_311_3222_stack_1->GetYaxis()->SetTitleSize(0.035);
   h_ByKaonFinalStates_nu_mu_CCmI13_311_3222_stack_1->GetYaxis()->SetTitleOffset(0);
   h_ByKaonFinalStates_nu_mu_CCmI13_311_3222_stack_1->GetYaxis()->SetTitleFont(42);
   h_ByKaonFinalStates_nu_mu_CCmI13_311_3222_stack_1->GetZaxis()->SetLabelFont(42);
   h_ByKaonFinalStates_nu_mu_CCmI13_311_3222_stack_1->GetZaxis()->SetLabelSize(0.035);
   h_ByKaonFinalStates_nu_mu_CCmI13_311_3222_stack_1->GetZaxis()->SetTitleSize(0.035);
   h_ByKaonFinalStates_nu_mu_CCmI13_311_3222_stack_1->GetZaxis()->SetTitleFont(42);
   hs->Add(h_ByKaonFinalStates_nu_mu_CC-13_311_3222_stack_1,"HIST");
   
   TH1D *h_ByKaonFinalStates_nu_mu_NCmI14_311_3122_stack_2 = new TH1D("h_ByKaonFinalStates_nu_mu_NCmI14_311_3122_stack_2","",8,0,0.8);

   ci = TColor::GetColor("#ffcc00");
   h_ByKaonFinalStates_nu_mu_NCmI14_311_3122_stack_2->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   h_ByKaonFinalStates_nu_mu_NCmI14_311_3122_stack_2->SetLineColor(ci);
   h_ByKaonFinalStates_nu_mu_NCmI14_311_3122_stack_2->GetXaxis()->SetTitle("Reconstructed Invariant Mass of Pion Pair (GeV)");
   h_ByKaonFinalStates_nu_mu_NCmI14_311_3122_stack_2->GetXaxis()->SetLabelFont(42);
   h_ByKaonFinalStates_nu_mu_NCmI14_311_3122_stack_2->GetXaxis()->SetLabelSize(0.035);
   h_ByKaonFinalStates_nu_mu_NCmI14_311_3122_stack_2->GetXaxis()->SetTitleSize(0.035);
   h_ByKaonFinalStates_nu_mu_NCmI14_311_3122_stack_2->GetXaxis()->SetTitleFont(42);
   h_ByKaonFinalStates_nu_mu_NCmI14_311_3122_stack_2->GetYaxis()->SetTitle("Events/bin");
   h_ByKaonFinalStates_nu_mu_NCmI14_311_3122_stack_2->GetYaxis()->SetLabelFont(42);
   h_ByKaonFinalStates_nu_mu_NCmI14_311_3122_stack_2->GetYaxis()->SetLabelSize(0.035);
   h_ByKaonFinalStates_nu_mu_NCmI14_311_3122_stack_2->GetYaxis()->SetTitleSize(0.035);
   h_ByKaonFinalStates_nu_mu_NCmI14_311_3122_stack_2->GetYaxis()->SetTitleOffset(0);
   h_ByKaonFinalStates_nu_mu_NCmI14_311_3122_stack_2->GetYaxis()->SetTitleFont(42);
   h_ByKaonFinalStates_nu_mu_NCmI14_311_3122_stack_2->GetZaxis()->SetLabelFont(42);
   h_ByKaonFinalStates_nu_mu_NCmI14_311_3122_stack_2->GetZaxis()->SetLabelSize(0.035);
   h_ByKaonFinalStates_nu_mu_NCmI14_311_3122_stack_2->GetZaxis()->SetTitleSize(0.035);
   h_ByKaonFinalStates_nu_mu_NCmI14_311_3122_stack_2->GetZaxis()->SetTitleFont(42);
   hs->Add(h_ByKaonFinalStates_nu_mu_NC-14_311_3122_stack_2,"HIST");
   
   TH1D *h_ByKaonFinalStates_nu_mu_CCmI13_311_3122_stack_3 = new TH1D("h_ByKaonFinalStates_nu_mu_CCmI13_311_3122_stack_3","",8,0,0.8);

   ci = TColor::GetColor("#ff00ff");
   h_ByKaonFinalStates_nu_mu_CCmI13_311_3122_stack_3->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   h_ByKaonFinalStates_nu_mu_CCmI13_311_3122_stack_3->SetLineColor(ci);
   h_ByKaonFinalStates_nu_mu_CCmI13_311_3122_stack_3->GetXaxis()->SetTitle("Reconstructed Invariant Mass of Pion Pair (GeV)");
   h_ByKaonFinalStates_nu_mu_CCmI13_311_3122_stack_3->GetXaxis()->SetLabelFont(42);
   h_ByKaonFinalStates_nu_mu_CCmI13_311_3122_stack_3->GetXaxis()->SetLabelSize(0.035);
   h_ByKaonFinalStates_nu_mu_CCmI13_311_3122_stack_3->GetXaxis()->SetTitleSize(0.035);
   h_ByKaonFinalStates_nu_mu_CCmI13_311_3122_stack_3->GetXaxis()->SetTitleFont(42);
   h_ByKaonFinalStates_nu_mu_CCmI13_311_3122_stack_3->GetYaxis()->SetTitle("Events/bin");
   h_ByKaonFinalStates_nu_mu_CCmI13_311_3122_stack_3->GetYaxis()->SetLabelFont(42);
   h_ByKaonFinalStates_nu_mu_CCmI13_311_3122_stack_3->GetYaxis()->SetLabelSize(0.035);
   h_ByKaonFinalStates_nu_mu_CCmI13_311_3122_stack_3->GetYaxis()->SetTitleSize(0.035);
   h_ByKaonFinalStates_nu_mu_CCmI13_311_3122_stack_3->GetYaxis()->SetTitleOffset(0);
   h_ByKaonFinalStates_nu_mu_CCmI13_311_3122_stack_3->GetYaxis()->SetTitleFont(42);
   h_ByKaonFinalStates_nu_mu_CCmI13_311_3122_stack_3->GetZaxis()->SetLabelFont(42);
   h_ByKaonFinalStates_nu_mu_CCmI13_311_3122_stack_3->GetZaxis()->SetLabelSize(0.035);
   h_ByKaonFinalStates_nu_mu_CCmI13_311_3122_stack_3->GetZaxis()->SetTitleSize(0.035);
   h_ByKaonFinalStates_nu_mu_CCmI13_311_3122_stack_3->GetZaxis()->SetTitleFont(42);
   hs->Add(h_ByKaonFinalStates_nu_mu_CC-13_311_3122_stack_3,"HIST");
   
   TH1D *h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_3122_stack_4 = new TH1D("h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_3122_stack_4","",8,0,0.8);

   ci = TColor::GetColor("#00ffff");
   h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_3122_stack_4->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_3122_stack_4->SetLineColor(ci);
   h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_3122_stack_4->GetXaxis()->SetTitle("Reconstructed Invariant Mass of Pion Pair (GeV)");
   h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_3122_stack_4->GetXaxis()->SetLabelFont(42);
   h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_3122_stack_4->GetXaxis()->SetLabelSize(0.035);
   h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_3122_stack_4->GetXaxis()->SetTitleSize(0.035);
   h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_3122_stack_4->GetXaxis()->SetTitleFont(42);
   h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_3122_stack_4->GetYaxis()->SetTitle("Events/bin");
   h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_3122_stack_4->GetYaxis()->SetLabelFont(42);
   h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_3122_stack_4->GetYaxis()->SetLabelSize(0.035);
   h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_3122_stack_4->GetYaxis()->SetTitleSize(0.035);
   h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_3122_stack_4->GetYaxis()->SetTitleOffset(0);
   h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_3122_stack_4->GetYaxis()->SetTitleFont(42);
   h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_3122_stack_4->GetZaxis()->SetLabelFont(42);
   h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_3122_stack_4->GetZaxis()->SetLabelSize(0.035);
   h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_3122_stack_4->GetZaxis()->SetTitleSize(0.035);
   h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_3122_stack_4->GetZaxis()->SetTitleFont(42);
   hs->Add(h_ByKaonFinalStates_nu_bar_mu_CC--13_311_3122_stack_4,"HIST");
   
   TH1D *h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_3112_stack_5 = new TH1D("h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_3112_stack_5","",8,0,0.8);

   ci = TColor::GetColor("#0033ff");
   h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_3112_stack_5->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_3112_stack_5->SetLineColor(ci);
   h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_3112_stack_5->GetXaxis()->SetTitle("Reconstructed Invariant Mass of Pion Pair (GeV)");
   h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_3112_stack_5->GetXaxis()->SetLabelFont(42);
   h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_3112_stack_5->GetXaxis()->SetLabelSize(0.035);
   h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_3112_stack_5->GetXaxis()->SetTitleSize(0.035);
   h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_3112_stack_5->GetXaxis()->SetTitleFont(42);
   h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_3112_stack_5->GetYaxis()->SetTitle("Events/bin");
   h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_3112_stack_5->GetYaxis()->SetLabelFont(42);
   h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_3112_stack_5->GetYaxis()->SetLabelSize(0.035);
   h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_3112_stack_5->GetYaxis()->SetTitleSize(0.035);
   h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_3112_stack_5->GetYaxis()->SetTitleOffset(0);
   h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_3112_stack_5->GetYaxis()->SetTitleFont(42);
   h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_3112_stack_5->GetZaxis()->SetLabelFont(42);
   h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_3112_stack_5->GetZaxis()->SetLabelSize(0.035);
   h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_3112_stack_5->GetZaxis()->SetTitleSize(0.035);
   h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_3112_stack_5->GetZaxis()->SetTitleFont(42);
   hs->Add(h_ByKaonFinalStates_nu_bar_mu_CC--13_311_3112_stack_5,"HIST");
   
   TH1D *h_ByKaonFinalStates_nu_mu_CCmI13_311_mI311_stack_6 = new TH1D("h_ByKaonFinalStates_nu_mu_CCmI13_311_mI311_stack_6","",8,0,0.8);

   ci = TColor::GetColor("#ff0033");
   h_ByKaonFinalStates_nu_mu_CCmI13_311_mI311_stack_6->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   h_ByKaonFinalStates_nu_mu_CCmI13_311_mI311_stack_6->SetLineColor(ci);
   h_ByKaonFinalStates_nu_mu_CCmI13_311_mI311_stack_6->GetXaxis()->SetTitle("Reconstructed Invariant Mass of Pion Pair (GeV)");
   h_ByKaonFinalStates_nu_mu_CCmI13_311_mI311_stack_6->GetXaxis()->SetLabelFont(42);
   h_ByKaonFinalStates_nu_mu_CCmI13_311_mI311_stack_6->GetXaxis()->SetLabelSize(0.035);
   h_ByKaonFinalStates_nu_mu_CCmI13_311_mI311_stack_6->GetXaxis()->SetTitleSize(0.035);
   h_ByKaonFinalStates_nu_mu_CCmI13_311_mI311_stack_6->GetXaxis()->SetTitleFont(42);
   h_ByKaonFinalStates_nu_mu_CCmI13_311_mI311_stack_6->GetYaxis()->SetTitle("Events/bin");
   h_ByKaonFinalStates_nu_mu_CCmI13_311_mI311_stack_6->GetYaxis()->SetLabelFont(42);
   h_ByKaonFinalStates_nu_mu_CCmI13_311_mI311_stack_6->GetYaxis()->SetLabelSize(0.035);
   h_ByKaonFinalStates_nu_mu_CCmI13_311_mI311_stack_6->GetYaxis()->SetTitleSize(0.035);
   h_ByKaonFinalStates_nu_mu_CCmI13_311_mI311_stack_6->GetYaxis()->SetTitleOffset(0);
   h_ByKaonFinalStates_nu_mu_CCmI13_311_mI311_stack_6->GetYaxis()->SetTitleFont(42);
   h_ByKaonFinalStates_nu_mu_CCmI13_311_mI311_stack_6->GetZaxis()->SetLabelFont(42);
   h_ByKaonFinalStates_nu_mu_CCmI13_311_mI311_stack_6->GetZaxis()->SetLabelSize(0.035);
   h_ByKaonFinalStates_nu_mu_CCmI13_311_mI311_stack_6->GetZaxis()->SetTitleSize(0.035);
   h_ByKaonFinalStates_nu_mu_CCmI13_311_mI311_stack_6->GetZaxis()->SetTitleFont(42);
   hs->Add(h_ByKaonFinalStates_nu_mu_CC-13_311_-311_stack_6,"HIST");
   
   TH1D *h_ByKaonFinalStates_nu_bar_mu_NCmImI14_311_3122_stack_7 = new TH1D("h_ByKaonFinalStates_nu_bar_mu_NCmImI14_311_3122_stack_7","",8,0,0.8);

   ci = TColor::GetColor("#33ff00");
   h_ByKaonFinalStates_nu_bar_mu_NCmImI14_311_3122_stack_7->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   h_ByKaonFinalStates_nu_bar_mu_NCmImI14_311_3122_stack_7->SetLineColor(ci);
   h_ByKaonFinalStates_nu_bar_mu_NCmImI14_311_3122_stack_7->GetXaxis()->SetTitle("Reconstructed Invariant Mass of Pion Pair (GeV)");
   h_ByKaonFinalStates_nu_bar_mu_NCmImI14_311_3122_stack_7->GetXaxis()->SetLabelFont(42);
   h_ByKaonFinalStates_nu_bar_mu_NCmImI14_311_3122_stack_7->GetXaxis()->SetLabelSize(0.035);
   h_ByKaonFinalStates_nu_bar_mu_NCmImI14_311_3122_stack_7->GetXaxis()->SetTitleSize(0.035);
   h_ByKaonFinalStates_nu_bar_mu_NCmImI14_311_3122_stack_7->GetXaxis()->SetTitleFont(42);
   h_ByKaonFinalStates_nu_bar_mu_NCmImI14_311_3122_stack_7->GetYaxis()->SetTitle("Events/bin");
   h_ByKaonFinalStates_nu_bar_mu_NCmImI14_311_3122_stack_7->GetYaxis()->SetLabelFont(42);
   h_ByKaonFinalStates_nu_bar_mu_NCmImI14_311_3122_stack_7->GetYaxis()->SetLabelSize(0.035);
   h_ByKaonFinalStates_nu_bar_mu_NCmImI14_311_3122_stack_7->GetYaxis()->SetTitleSize(0.035);
   h_ByKaonFinalStates_nu_bar_mu_NCmImI14_311_3122_stack_7->GetYaxis()->SetTitleOffset(0);
   h_ByKaonFinalStates_nu_bar_mu_NCmImI14_311_3122_stack_7->GetYaxis()->SetTitleFont(42);
   h_ByKaonFinalStates_nu_bar_mu_NCmImI14_311_3122_stack_7->GetZaxis()->SetLabelFont(42);
   h_ByKaonFinalStates_nu_bar_mu_NCmImI14_311_3122_stack_7->GetZaxis()->SetLabelSize(0.035);
   h_ByKaonFinalStates_nu_bar_mu_NCmImI14_311_3122_stack_7->GetZaxis()->SetTitleSize(0.035);
   h_ByKaonFinalStates_nu_bar_mu_NCmImI14_311_3122_stack_7->GetZaxis()->SetTitleFont(42);
   hs->Add(h_ByKaonFinalStates_nu_bar_mu_NC--14_311_3122_stack_7,"HIST");
   
   TH1D *h_ByKaonFinalStates_nu_mu_NCmI14_311_3222_stack_8 = new TH1D("h_ByKaonFinalStates_nu_mu_NCmI14_311_3222_stack_8","",8,0,0.8);

   ci = TColor::GetColor("#cc00ff");
   h_ByKaonFinalStates_nu_mu_NCmI14_311_3222_stack_8->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   h_ByKaonFinalStates_nu_mu_NCmI14_311_3222_stack_8->SetLineColor(ci);
   h_ByKaonFinalStates_nu_mu_NCmI14_311_3222_stack_8->GetXaxis()->SetTitle("Reconstructed Invariant Mass of Pion Pair (GeV)");
   h_ByKaonFinalStates_nu_mu_NCmI14_311_3222_stack_8->GetXaxis()->SetLabelFont(42);
   h_ByKaonFinalStates_nu_mu_NCmI14_311_3222_stack_8->GetXaxis()->SetLabelSize(0.035);
   h_ByKaonFinalStates_nu_mu_NCmI14_311_3222_stack_8->GetXaxis()->SetTitleSize(0.035);
   h_ByKaonFinalStates_nu_mu_NCmI14_311_3222_stack_8->GetXaxis()->SetTitleFont(42);
   h_ByKaonFinalStates_nu_mu_NCmI14_311_3222_stack_8->GetYaxis()->SetTitle("Events/bin");
   h_ByKaonFinalStates_nu_mu_NCmI14_311_3222_stack_8->GetYaxis()->SetLabelFont(42);
   h_ByKaonFinalStates_nu_mu_NCmI14_311_3222_stack_8->GetYaxis()->SetLabelSize(0.035);
   h_ByKaonFinalStates_nu_mu_NCmI14_311_3222_stack_8->GetYaxis()->SetTitleSize(0.035);
   h_ByKaonFinalStates_nu_mu_NCmI14_311_3222_stack_8->GetYaxis()->SetTitleOffset(0);
   h_ByKaonFinalStates_nu_mu_NCmI14_311_3222_stack_8->GetYaxis()->SetTitleFont(42);
   h_ByKaonFinalStates_nu_mu_NCmI14_311_3222_stack_8->GetZaxis()->SetLabelFont(42);
   h_ByKaonFinalStates_nu_mu_NCmI14_311_3222_stack_8->GetZaxis()->SetLabelSize(0.035);
   h_ByKaonFinalStates_nu_mu_NCmI14_311_3222_stack_8->GetZaxis()->SetTitleSize(0.035);
   h_ByKaonFinalStates_nu_mu_NCmI14_311_3222_stack_8->GetZaxis()->SetTitleFont(42);
   hs->Add(h_ByKaonFinalStates_nu_mu_NC-14_311_3222_stack_8,"HIST");
   
   TH1D *h_ByKaonFinalStates_nu_mu_NCmI14_311_mI311_stack_9 = new TH1D("h_ByKaonFinalStates_nu_mu_NCmI14_311_mI311_stack_9","",8,0,0.8);

   ci = TColor::GetColor("#000099");
   h_ByKaonFinalStates_nu_mu_NCmI14_311_mI311_stack_9->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   h_ByKaonFinalStates_nu_mu_NCmI14_311_mI311_stack_9->SetLineColor(ci);
   h_ByKaonFinalStates_nu_mu_NCmI14_311_mI311_stack_9->GetXaxis()->SetTitle("Reconstructed Invariant Mass of Pion Pair (GeV)");
   h_ByKaonFinalStates_nu_mu_NCmI14_311_mI311_stack_9->GetXaxis()->SetLabelFont(42);
   h_ByKaonFinalStates_nu_mu_NCmI14_311_mI311_stack_9->GetXaxis()->SetLabelSize(0.035);
   h_ByKaonFinalStates_nu_mu_NCmI14_311_mI311_stack_9->GetXaxis()->SetTitleSize(0.035);
   h_ByKaonFinalStates_nu_mu_NCmI14_311_mI311_stack_9->GetXaxis()->SetTitleFont(42);
   h_ByKaonFinalStates_nu_mu_NCmI14_311_mI311_stack_9->GetYaxis()->SetTitle("Events/bin");
   h_ByKaonFinalStates_nu_mu_NCmI14_311_mI311_stack_9->GetYaxis()->SetLabelFont(42);
   h_ByKaonFinalStates_nu_mu_NCmI14_311_mI311_stack_9->GetYaxis()->SetLabelSize(0.035);
   h_ByKaonFinalStates_nu_mu_NCmI14_311_mI311_stack_9->GetYaxis()->SetTitleSize(0.035);
   h_ByKaonFinalStates_nu_mu_NCmI14_311_mI311_stack_9->GetYaxis()->SetTitleOffset(0);
   h_ByKaonFinalStates_nu_mu_NCmI14_311_mI311_stack_9->GetYaxis()->SetTitleFont(42);
   h_ByKaonFinalStates_nu_mu_NCmI14_311_mI311_stack_9->GetZaxis()->SetLabelFont(42);
   h_ByKaonFinalStates_nu_mu_NCmI14_311_mI311_stack_9->GetZaxis()->SetLabelSize(0.035);
   h_ByKaonFinalStates_nu_mu_NCmI14_311_mI311_stack_9->GetZaxis()->SetTitleSize(0.035);
   h_ByKaonFinalStates_nu_mu_NCmI14_311_mI311_stack_9->GetZaxis()->SetTitleFont(42);
   hs->Add(h_ByKaonFinalStates_nu_mu_NC-14_311_-311_stack_9,"HIST");
   
   TH1D *h_ByKaonFinalStates_nu_mu_NCmI14_311_3112_stack_10 = new TH1D("h_ByKaonFinalStates_nu_mu_NCmI14_311_3112_stack_10","",8,0,0.8);

   ci = TColor::GetColor("#ff0000");
   h_ByKaonFinalStates_nu_mu_NCmI14_311_3112_stack_10->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   h_ByKaonFinalStates_nu_mu_NCmI14_311_3112_stack_10->SetLineColor(ci);
   h_ByKaonFinalStates_nu_mu_NCmI14_311_3112_stack_10->GetXaxis()->SetTitle("Reconstructed Invariant Mass of Pion Pair (GeV)");
   h_ByKaonFinalStates_nu_mu_NCmI14_311_3112_stack_10->GetXaxis()->SetLabelFont(42);
   h_ByKaonFinalStates_nu_mu_NCmI14_311_3112_stack_10->GetXaxis()->SetLabelSize(0.035);
   h_ByKaonFinalStates_nu_mu_NCmI14_311_3112_stack_10->GetXaxis()->SetTitleSize(0.035);
   h_ByKaonFinalStates_nu_mu_NCmI14_311_3112_stack_10->GetXaxis()->SetTitleFont(42);
   h_ByKaonFinalStates_nu_mu_NCmI14_311_3112_stack_10->GetYaxis()->SetTitle("Events/bin");
   h_ByKaonFinalStates_nu_mu_NCmI14_311_3112_stack_10->GetYaxis()->SetLabelFont(42);
   h_ByKaonFinalStates_nu_mu_NCmI14_311_3112_stack_10->GetYaxis()->SetLabelSize(0.035);
   h_ByKaonFinalStates_nu_mu_NCmI14_311_3112_stack_10->GetYaxis()->SetTitleSize(0.035);
   h_ByKaonFinalStates_nu_mu_NCmI14_311_3112_stack_10->GetYaxis()->SetTitleOffset(0);
   h_ByKaonFinalStates_nu_mu_NCmI14_311_3112_stack_10->GetYaxis()->SetTitleFont(42);
   h_ByKaonFinalStates_nu_mu_NCmI14_311_3112_stack_10->GetZaxis()->SetLabelFont(42);
   h_ByKaonFinalStates_nu_mu_NCmI14_311_3112_stack_10->GetZaxis()->SetLabelSize(0.035);
   h_ByKaonFinalStates_nu_mu_NCmI14_311_3112_stack_10->GetZaxis()->SetTitleSize(0.035);
   h_ByKaonFinalStates_nu_mu_NCmI14_311_3112_stack_10->GetZaxis()->SetTitleFont(42);
   hs->Add(h_ByKaonFinalStates_nu_mu_NC-14_311_3112_stack_10,"HIST");
   
   TH1D *h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_mI311_stack_11 = new TH1D("h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_mI311_stack_11","",8,0,0.8);

   ci = TColor::GetColor("#00ff00");
   h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_mI311_stack_11->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_mI311_stack_11->SetLineColor(ci);
   h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_mI311_stack_11->GetXaxis()->SetTitle("Reconstructed Invariant Mass of Pion Pair (GeV)");
   h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_mI311_stack_11->GetXaxis()->SetLabelFont(42);
   h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_mI311_stack_11->GetXaxis()->SetLabelSize(0.035);
   h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_mI311_stack_11->GetXaxis()->SetTitleSize(0.035);
   h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_mI311_stack_11->GetXaxis()->SetTitleFont(42);
   h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_mI311_stack_11->GetYaxis()->SetTitle("Events/bin");
   h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_mI311_stack_11->GetYaxis()->SetLabelFont(42);
   h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_mI311_stack_11->GetYaxis()->SetLabelSize(0.035);
   h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_mI311_stack_11->GetYaxis()->SetTitleSize(0.035);
   h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_mI311_stack_11->GetYaxis()->SetTitleOffset(0);
   h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_mI311_stack_11->GetYaxis()->SetTitleFont(42);
   h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_mI311_stack_11->GetZaxis()->SetLabelFont(42);
   h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_mI311_stack_11->GetZaxis()->SetLabelSize(0.035);
   h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_mI311_stack_11->GetZaxis()->SetTitleSize(0.035);
   h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_mI311_stack_11->GetZaxis()->SetTitleFont(42);
   hs->Add(h_ByKaonFinalStates_nu_bar_mu_CC--13_311_-311_stack_11,"HIST");
   
   TH1D *h_ByKaonFinalStates_nu_bar_mu_NCmImI14_311_3212_stack_12 = new TH1D("h_ByKaonFinalStates_nu_bar_mu_NCmImI14_311_3212_stack_12","",8,0,0.8);

   ci = TColor::GetColor("#ff6600");
   h_ByKaonFinalStates_nu_bar_mu_NCmImI14_311_3212_stack_12->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   h_ByKaonFinalStates_nu_bar_mu_NCmImI14_311_3212_stack_12->SetLineColor(ci);
   h_ByKaonFinalStates_nu_bar_mu_NCmImI14_311_3212_stack_12->GetXaxis()->SetTitle("Reconstructed Invariant Mass of Pion Pair (GeV)");
   h_ByKaonFinalStates_nu_bar_mu_NCmImI14_311_3212_stack_12->GetXaxis()->SetLabelFont(42);
   h_ByKaonFinalStates_nu_bar_mu_NCmImI14_311_3212_stack_12->GetXaxis()->SetLabelSize(0.035);
   h_ByKaonFinalStates_nu_bar_mu_NCmImI14_311_3212_stack_12->GetXaxis()->SetTitleSize(0.035);
   h_ByKaonFinalStates_nu_bar_mu_NCmImI14_311_3212_stack_12->GetXaxis()->SetTitleFont(42);
   h_ByKaonFinalStates_nu_bar_mu_NCmImI14_311_3212_stack_12->GetYaxis()->SetTitle("Events/bin");
   h_ByKaonFinalStates_nu_bar_mu_NCmImI14_311_3212_stack_12->GetYaxis()->SetLabelFont(42);
   h_ByKaonFinalStates_nu_bar_mu_NCmImI14_311_3212_stack_12->GetYaxis()->SetLabelSize(0.035);
   h_ByKaonFinalStates_nu_bar_mu_NCmImI14_311_3212_stack_12->GetYaxis()->SetTitleSize(0.035);
   h_ByKaonFinalStates_nu_bar_mu_NCmImI14_311_3212_stack_12->GetYaxis()->SetTitleOffset(0);
   h_ByKaonFinalStates_nu_bar_mu_NCmImI14_311_3212_stack_12->GetYaxis()->SetTitleFont(42);
   h_ByKaonFinalStates_nu_bar_mu_NCmImI14_311_3212_stack_12->GetZaxis()->SetLabelFont(42);
   h_ByKaonFinalStates_nu_bar_mu_NCmImI14_311_3212_stack_12->GetZaxis()->SetLabelSize(0.035);
   h_ByKaonFinalStates_nu_bar_mu_NCmImI14_311_3212_stack_12->GetZaxis()->SetTitleSize(0.035);
   h_ByKaonFinalStates_nu_bar_mu_NCmImI14_311_3212_stack_12->GetZaxis()->SetTitleFont(42);
   hs->Add(h_ByKaonFinalStates_nu_bar_mu_NC--14_311_3212_stack_12,"HIST");
   
   TH1D *h_ByKaonFinalStates_nu_bar_mu_NCmImI14_311_3222_stack_13 = new TH1D("h_ByKaonFinalStates_nu_bar_mu_NCmImI14_311_3222_stack_13","",8,0,0.8);

   ci = TColor::GetColor("#cc00cc");
   h_ByKaonFinalStates_nu_bar_mu_NCmImI14_311_3222_stack_13->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   h_ByKaonFinalStates_nu_bar_mu_NCmImI14_311_3222_stack_13->SetLineColor(ci);
   h_ByKaonFinalStates_nu_bar_mu_NCmImI14_311_3222_stack_13->GetXaxis()->SetTitle("Reconstructed Invariant Mass of Pion Pair (GeV)");
   h_ByKaonFinalStates_nu_bar_mu_NCmImI14_311_3222_stack_13->GetXaxis()->SetLabelFont(42);
   h_ByKaonFinalStates_nu_bar_mu_NCmImI14_311_3222_stack_13->GetXaxis()->SetLabelSize(0.035);
   h_ByKaonFinalStates_nu_bar_mu_NCmImI14_311_3222_stack_13->GetXaxis()->SetTitleSize(0.035);
   h_ByKaonFinalStates_nu_bar_mu_NCmImI14_311_3222_stack_13->GetXaxis()->SetTitleFont(42);
   h_ByKaonFinalStates_nu_bar_mu_NCmImI14_311_3222_stack_13->GetYaxis()->SetTitle("Events/bin");
   h_ByKaonFinalStates_nu_bar_mu_NCmImI14_311_3222_stack_13->GetYaxis()->SetLabelFont(42);
   h_ByKaonFinalStates_nu_bar_mu_NCmImI14_311_3222_stack_13->GetYaxis()->SetLabelSize(0.035);
   h_ByKaonFinalStates_nu_bar_mu_NCmImI14_311_3222_stack_13->GetYaxis()->SetTitleSize(0.035);
   h_ByKaonFinalStates_nu_bar_mu_NCmImI14_311_3222_stack_13->GetYaxis()->SetTitleOffset(0);
   h_ByKaonFinalStates_nu_bar_mu_NCmImI14_311_3222_stack_13->GetYaxis()->SetTitleFont(42);
   h_ByKaonFinalStates_nu_bar_mu_NCmImI14_311_3222_stack_13->GetZaxis()->SetLabelFont(42);
   h_ByKaonFinalStates_nu_bar_mu_NCmImI14_311_3222_stack_13->GetZaxis()->SetLabelSize(0.035);
   h_ByKaonFinalStates_nu_bar_mu_NCmImI14_311_3222_stack_13->GetZaxis()->SetTitleSize(0.035);
   h_ByKaonFinalStates_nu_bar_mu_NCmImI14_311_3222_stack_13->GetZaxis()->SetTitleFont(42);
   hs->Add(h_ByKaonFinalStates_nu_bar_mu_NC--14_311_3222_stack_13,"HIST");
   
   TH1D *h_ByKaonFinalStates_nu_mu_CCmI13_311_stack_14 = new TH1D("h_ByKaonFinalStates_nu_mu_CCmI13_311_stack_14","",8,0,0.8);

   ci = TColor::GetColor("#00cccc");
   h_ByKaonFinalStates_nu_mu_CCmI13_311_stack_14->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   h_ByKaonFinalStates_nu_mu_CCmI13_311_stack_14->SetLineColor(ci);
   h_ByKaonFinalStates_nu_mu_CCmI13_311_stack_14->GetXaxis()->SetTitle("Reconstructed Invariant Mass of Pion Pair (GeV)");
   h_ByKaonFinalStates_nu_mu_CCmI13_311_stack_14->GetXaxis()->SetLabelFont(42);
   h_ByKaonFinalStates_nu_mu_CCmI13_311_stack_14->GetXaxis()->SetLabelSize(0.035);
   h_ByKaonFinalStates_nu_mu_CCmI13_311_stack_14->GetXaxis()->SetTitleSize(0.035);
   h_ByKaonFinalStates_nu_mu_CCmI13_311_stack_14->GetXaxis()->SetTitleFont(42);
   h_ByKaonFinalStates_nu_mu_CCmI13_311_stack_14->GetYaxis()->SetTitle("Events/bin");
   h_ByKaonFinalStates_nu_mu_CCmI13_311_stack_14->GetYaxis()->SetLabelFont(42);
   h_ByKaonFinalStates_nu_mu_CCmI13_311_stack_14->GetYaxis()->SetLabelSize(0.035);
   h_ByKaonFinalStates_nu_mu_CCmI13_311_stack_14->GetYaxis()->SetTitleSize(0.035);
   h_ByKaonFinalStates_nu_mu_CCmI13_311_stack_14->GetYaxis()->SetTitleOffset(0);
   h_ByKaonFinalStates_nu_mu_CCmI13_311_stack_14->GetYaxis()->SetTitleFont(42);
   h_ByKaonFinalStates_nu_mu_CCmI13_311_stack_14->GetZaxis()->SetLabelFont(42);
   h_ByKaonFinalStates_nu_mu_CCmI13_311_stack_14->GetZaxis()->SetLabelSize(0.035);
   h_ByKaonFinalStates_nu_mu_CCmI13_311_stack_14->GetZaxis()->SetTitleSize(0.035);
   h_ByKaonFinalStates_nu_mu_CCmI13_311_stack_14->GetZaxis()->SetTitleFont(42);
   hs->Add(h_ByKaonFinalStates_nu_mu_CC-13_311_stack_14,"HIST");
   
   TH1D *h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_stack_15 = new TH1D("h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_stack_15","",8,0,0.8);

   ci = TColor::GetColor("#3399ff");
   h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_stack_15->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_stack_15->SetLineColor(ci);
   h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_stack_15->GetXaxis()->SetTitle("Reconstructed Invariant Mass of Pion Pair (GeV)");
   h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_stack_15->GetXaxis()->SetLabelFont(42);
   h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_stack_15->GetXaxis()->SetLabelSize(0.035);
   h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_stack_15->GetXaxis()->SetTitleSize(0.035);
   h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_stack_15->GetXaxis()->SetTitleFont(42);
   h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_stack_15->GetYaxis()->SetTitle("Events/bin");
   h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_stack_15->GetYaxis()->SetLabelFont(42);
   h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_stack_15->GetYaxis()->SetLabelSize(0.035);
   h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_stack_15->GetYaxis()->SetTitleSize(0.035);
   h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_stack_15->GetYaxis()->SetTitleOffset(0);
   h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_stack_15->GetYaxis()->SetTitleFont(42);
   h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_stack_15->GetZaxis()->SetLabelFont(42);
   h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_stack_15->GetZaxis()->SetLabelSize(0.035);
   h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_stack_15->GetZaxis()->SetTitleSize(0.035);
   h_ByKaonFinalStates_nu_bar_mu_CCmImI13_311_stack_15->GetZaxis()->SetTitleFont(42);
   hs->Add(h_ByKaonFinalStates_nu_bar_mu_CC--13_311_stack_15,"HIST");
   
   TH1D *h_ByKaonFinalStates__stack_16 = new TH1D("h_ByKaonFinalStates__stack_16","",8,0,0.8);

   ci = TColor::GetColor("#ff99cc");
   h_ByKaonFinalStates__stack_16->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   h_ByKaonFinalStates__stack_16->SetLineColor(ci);
   h_ByKaonFinalStates__stack_16->GetXaxis()->SetTitle("Reconstructed Invariant Mass of Pion Pair (GeV)");
   h_ByKaonFinalStates__stack_16->GetXaxis()->SetLabelFont(42);
   h_ByKaonFinalStates__stack_16->GetXaxis()->SetLabelSize(0.035);
   h_ByKaonFinalStates__stack_16->GetXaxis()->SetTitleSize(0.035);
   h_ByKaonFinalStates__stack_16->GetXaxis()->SetTitleFont(42);
   h_ByKaonFinalStates__stack_16->GetYaxis()->SetTitle("Events/bin");
   h_ByKaonFinalStates__stack_16->GetYaxis()->SetLabelFont(42);
   h_ByKaonFinalStates__stack_16->GetYaxis()->SetLabelSize(0.035);
   h_ByKaonFinalStates__stack_16->GetYaxis()->SetTitleSize(0.035);
   h_ByKaonFinalStates__stack_16->GetYaxis()->SetTitleOffset(0);
   h_ByKaonFinalStates__stack_16->GetYaxis()->SetTitleFont(42);
   h_ByKaonFinalStates__stack_16->GetZaxis()->SetLabelFont(42);
   h_ByKaonFinalStates__stack_16->GetZaxis()->SetLabelSize(0.035);
   h_ByKaonFinalStates__stack_16->GetZaxis()->SetTitleSize(0.035);
   h_ByKaonFinalStates__stack_16->GetZaxis()->SetTitleFont(42);
   hs->Add(h_ByKaonFinalStates__stack_16,"HIST");
   hs->Draw("hist same");
   
   TH1D *h_errors__11 = new TH1D("h_errors__11","",8,0,0.8);
   h_errors__11->SetMinimum(0);
   h_errors__11->SetMaximum(0);
   h_errors__11->SetStats(0);
   h_errors__11->SetFillColor(1);
   h_errors__11->SetFillStyle(3253);

   ci = TColor::GetColor("#000099");
   h_errors__11->SetLineColor(ci);
   h_errors__11->GetXaxis()->SetTitle("Reconstructed Invariant Mass of Pion Pair (GeV)");
   h_errors__11->GetXaxis()->SetLabelFont(42);
   h_errors__11->GetXaxis()->SetLabelSize(0.045);
   h_errors__11->GetXaxis()->SetTitleSize(0.05);
   h_errors__11->GetXaxis()->SetTitleOffset(0.93);
   h_errors__11->GetXaxis()->SetTitleFont(42);
   h_errors__11->GetYaxis()->SetTitle("Events/bin");
   h_errors__11->GetYaxis()->SetLabelFont(42);
   h_errors__11->GetYaxis()->SetLabelSize(0.045);
   h_errors__11->GetYaxis()->SetTitleSize(0.05);
   h_errors__11->GetYaxis()->SetTitleOffset(1.06);
   h_errors__11->GetYaxis()->SetTitleFont(42);
   h_errors__11->GetZaxis()->SetLabelFont(42);
   h_errors__11->GetZaxis()->SetLabelSize(0.035);
   h_errors__11->GetZaxis()->SetTitleSize(0.035);
   h_errors__11->GetZaxis()->SetTitleFont(42);
   h_errors__11->Draw("E2 same");
   
   TH1D *h_errors_copy__12 = new TH1D("h_errors_copy__12","",8,0,0.8);
   h_errors_copy__12->SetMinimum(0);
   h_errors_copy__12->SetMaximum(0);
   h_errors_copy__12->SetDirectory(0);
   h_errors_copy__12->SetStats(0);
   h_errors_copy__12->SetFillColor(1);
   h_errors_copy__12->SetFillStyle(3253);

   ci = TColor::GetColor("#000099");
   h_errors_copy__12->SetLineColor(ci);
   h_errors_copy__12->GetXaxis()->SetTitle("Reconstructed Invariant Mass of Pion Pair (GeV)");
   h_errors_copy__12->GetXaxis()->SetLabelFont(42);
   h_errors_copy__12->GetXaxis()->SetLabelSize(0.045);
   h_errors_copy__12->GetXaxis()->SetTitleSize(0.05);
   h_errors_copy__12->GetXaxis()->SetTitleOffset(0.93);
   h_errors_copy__12->GetXaxis()->SetTitleFont(42);
   h_errors_copy__12->GetYaxis()->SetTitle("Events/bin");
   h_errors_copy__12->GetYaxis()->SetLabelFont(42);
   h_errors_copy__12->GetYaxis()->SetLabelSize(0.045);
   h_errors_copy__12->GetYaxis()->SetTitleSize(0.05);
   h_errors_copy__12->GetYaxis()->SetTitleOffset(1.06);
   h_errors_copy__12->GetYaxis()->SetTitleFont(42);
   h_errors_copy__12->GetZaxis()->SetLabelFont(42);
   h_errors_copy__12->GetZaxis()->SetLabelSize(0.035);
   h_errors_copy__12->GetZaxis()->SetTitleSize(0.035);
   h_errors_copy__12->GetZaxis()->SetTitleFont(42);
   h_errors_copy__12->Draw("sameaxis");
   
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
