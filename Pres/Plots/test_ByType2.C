void test_ByType2()
{
//=========Macro generated from canvas: c/c
//=========  (Mon Dec 11 06:05:23 2023) by ROOT version 6.12/06
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
   TLegendEntry *entry=leg->AddEntry("h_ByType2_DirectLambda","Direct #Lambda","F");
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
   entry=leg->AddEntry("h_ByType2_DirectHYP","Direct Hyp","F");

   ci = TColor::GetColor("#6666ff");
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
   entry=leg->AddEntry("h_ByType2_Neutron","Neutron","F");

   ci = TColor::GetColor("#ff6666");
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
   entry=leg->AddEntry("h_ByType2_Dirt","Dirt","F");

   ci = TColor::GetColor("#006666");
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
   entry=leg->AddEntry("h_ByType2_RESLambda","RES #Lambda","F");

   ci = TColor::GetColor("#006600");
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
   entry=leg->AddEntry("h_ByType2_RESHYP","RES Hyp","F");

   ci = TColor::GetColor("#ccccff");
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
   entry=leg->AddEntry("h_ByType2_Other","Other #nu","F");

   ci = TColor::GetColor("#ffcccc");
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
   entry=leg->AddEntry("h_ByType2_EXT","Cosmic","F");

   ci = TColor::GetColor("#ff66ff");
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
   entry=leg->AddEntry("h_ByType2_DISLambda","DIS #Lambda","F");
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
   entry=leg->AddEntry("h_ByType2_DISHYP","DIS Hyp","F");
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
   p_plot->Range(-0.1,-0.6177168,0.9,5.559451);
   p_plot->SetFillColor(0);
   p_plot->SetBorderMode(0);
   p_plot->SetBorderSize(2);
   p_plot->SetTopMargin(0.01);
   p_plot->SetFrameBorderMode(0);
   p_plot->SetFrameBorderMode(0);
   
   TH1D *h_errors__4 = new TH1D("h_errors__4","",16,0,0.8);
   h_errors__4->SetBinContent(6,0.6078599);
   h_errors__4->SetBinContent(7,3.97872);
   h_errors__4->SetBinContent(8,4.263521);
   h_errors__4->SetBinContent(9,2.291164);
   h_errors__4->SetBinContent(10,0.9691753);
   h_errors__4->SetBinContent(11,0.2763);
   h_errors__4->SetBinContent(12,0.05526);
   h_errors__4->SetBinContent(13,0.01275231);
   h_errors__4->SetBinContent(14,0.02975538);
   h_errors__4->SetBinContent(16,0.01700308);
   h_errors__4->SetBinContent(17,89.89101);
   h_errors__4->SetBinError(6,0.0508318);
   h_errors__4->SetBinError(7,0.1300485);
   h_errors__4->SetBinError(8,0.1346226);
   h_errors__4->SetBinError(9,0.09868744);
   h_errors__4->SetBinError(10,0.0641852);
   h_errors__4->SetBinError(11,0.03427079);
   h_errors__4->SetBinError(12,0.01532637);
   h_errors__4->SetBinError(13,0.007362548);
   h_errors__4->SetBinError(14,0.01124648);
   h_errors__4->SetBinError(16,0.008501538);
   h_errors__4->SetBinError(17,0.6181472);
   h_errors__4->SetMinimum(0);
   h_errors__4->SetMaximum(5.49768);
   h_errors__4->SetEntries(24088);
   h_errors__4->SetStats(0);
   h_errors__4->SetFillColor(1);
   h_errors__4->SetFillStyle(3253);

   ci = TColor::GetColor("#000099");
   h_errors__4->SetLineColor(ci);
   h_errors__4->GetXaxis()->SetTitle("Reconstructed Invariant Mass of Pion Pair (GeV)");
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
   
   TH1F *hs_stack_2 = new TH1F("hs_stack_2","",16,0,0.8);
   hs_stack_2->SetMinimum(0);
   hs_stack_2->SetMaximum(4.618051);
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
   
   
   TH1D *h_ByType2_DirectLambda_stack_1 = new TH1D("h_ByType2_DirectLambda_stack_1","",16,0,0.8);
   h_ByType2_DirectLambda_stack_1->SetBinContent(6,0.6078599);
   h_ByType2_DirectLambda_stack_1->SetBinContent(7,3.97872);
   h_ByType2_DirectLambda_stack_1->SetBinContent(8,4.263521);
   h_ByType2_DirectLambda_stack_1->SetBinContent(9,2.291164);
   h_ByType2_DirectLambda_stack_1->SetBinContent(10,0.9691753);
   h_ByType2_DirectLambda_stack_1->SetBinContent(11,0.2763);
   h_ByType2_DirectLambda_stack_1->SetBinContent(12,0.05526);
   h_ByType2_DirectLambda_stack_1->SetBinContent(13,0.01275231);
   h_ByType2_DirectLambda_stack_1->SetBinContent(14,0.02975538);
   h_ByType2_DirectLambda_stack_1->SetBinContent(16,0.01700308);
   h_ByType2_DirectLambda_stack_1->SetBinContent(17,89.89101);
   h_ByType2_DirectLambda_stack_1->SetBinError(6,0.0508318);
   h_ByType2_DirectLambda_stack_1->SetBinError(7,0.1300485);
   h_ByType2_DirectLambda_stack_1->SetBinError(8,0.1346226);
   h_ByType2_DirectLambda_stack_1->SetBinError(9,0.09868744);
   h_ByType2_DirectLambda_stack_1->SetBinError(10,0.0641852);
   h_ByType2_DirectLambda_stack_1->SetBinError(11,0.03427079);
   h_ByType2_DirectLambda_stack_1->SetBinError(12,0.01532637);
   h_ByType2_DirectLambda_stack_1->SetBinError(13,0.007362548);
   h_ByType2_DirectLambda_stack_1->SetBinError(14,0.01124648);
   h_ByType2_DirectLambda_stack_1->SetBinError(16,0.008501538);
   h_ByType2_DirectLambda_stack_1->SetBinError(17,0.6181472);
   h_ByType2_DirectLambda_stack_1->SetEntries(24088);
   h_ByType2_DirectLambda_stack_1->SetFillColor(8);

   ci = TColor::GetColor("#000099");
   h_ByType2_DirectLambda_stack_1->SetLineColor(ci);
   h_ByType2_DirectLambda_stack_1->GetXaxis()->SetTitle("Reconstructed Invariant Mass of Pion Pair (GeV)");
   h_ByType2_DirectLambda_stack_1->GetXaxis()->SetLabelFont(42);
   h_ByType2_DirectLambda_stack_1->GetXaxis()->SetLabelSize(0.035);
   h_ByType2_DirectLambda_stack_1->GetXaxis()->SetTitleSize(0.035);
   h_ByType2_DirectLambda_stack_1->GetXaxis()->SetTitleFont(42);
   h_ByType2_DirectLambda_stack_1->GetYaxis()->SetTitle("Events/bin");
   h_ByType2_DirectLambda_stack_1->GetYaxis()->SetLabelFont(42);
   h_ByType2_DirectLambda_stack_1->GetYaxis()->SetLabelSize(0.035);
   h_ByType2_DirectLambda_stack_1->GetYaxis()->SetTitleSize(0.035);
   h_ByType2_DirectLambda_stack_1->GetYaxis()->SetTitleOffset(0);
   h_ByType2_DirectLambda_stack_1->GetYaxis()->SetTitleFont(42);
   h_ByType2_DirectLambda_stack_1->GetZaxis()->SetLabelFont(42);
   h_ByType2_DirectLambda_stack_1->GetZaxis()->SetLabelSize(0.035);
   h_ByType2_DirectLambda_stack_1->GetZaxis()->SetTitleSize(0.035);
   h_ByType2_DirectLambda_stack_1->GetZaxis()->SetTitleFont(42);
   hs->Add(h_ByType2_DirectLambda_stack_1,"HIST");
   
   TH1D *h_ByType2_DirectHYP_stack_2 = new TH1D("h_ByType2_DirectHYP_stack_2","",16,0,0.8);

   ci = TColor::GetColor("#6666ff");
   h_ByType2_DirectHYP_stack_2->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   h_ByType2_DirectHYP_stack_2->SetLineColor(ci);
   h_ByType2_DirectHYP_stack_2->GetXaxis()->SetTitle("Reconstructed Invariant Mass of Pion Pair (GeV)");
   h_ByType2_DirectHYP_stack_2->GetXaxis()->SetLabelFont(42);
   h_ByType2_DirectHYP_stack_2->GetXaxis()->SetLabelSize(0.035);
   h_ByType2_DirectHYP_stack_2->GetXaxis()->SetTitleSize(0.035);
   h_ByType2_DirectHYP_stack_2->GetXaxis()->SetTitleFont(42);
   h_ByType2_DirectHYP_stack_2->GetYaxis()->SetTitle("Events/bin");
   h_ByType2_DirectHYP_stack_2->GetYaxis()->SetLabelFont(42);
   h_ByType2_DirectHYP_stack_2->GetYaxis()->SetLabelSize(0.035);
   h_ByType2_DirectHYP_stack_2->GetYaxis()->SetTitleSize(0.035);
   h_ByType2_DirectHYP_stack_2->GetYaxis()->SetTitleOffset(0);
   h_ByType2_DirectHYP_stack_2->GetYaxis()->SetTitleFont(42);
   h_ByType2_DirectHYP_stack_2->GetZaxis()->SetLabelFont(42);
   h_ByType2_DirectHYP_stack_2->GetZaxis()->SetLabelSize(0.035);
   h_ByType2_DirectHYP_stack_2->GetZaxis()->SetTitleSize(0.035);
   h_ByType2_DirectHYP_stack_2->GetZaxis()->SetTitleFont(42);
   hs->Add(h_ByType2_DirectHYP_stack_2,"HIST");
   
   TH1D *h_ByType2_Neutron_stack_3 = new TH1D("h_ByType2_Neutron_stack_3","",16,0,0.8);

   ci = TColor::GetColor("#ff6666");
   h_ByType2_Neutron_stack_3->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   h_ByType2_Neutron_stack_3->SetLineColor(ci);
   h_ByType2_Neutron_stack_3->GetXaxis()->SetTitle("Reconstructed Invariant Mass of Pion Pair (GeV)");
   h_ByType2_Neutron_stack_3->GetXaxis()->SetLabelFont(42);
   h_ByType2_Neutron_stack_3->GetXaxis()->SetLabelSize(0.035);
   h_ByType2_Neutron_stack_3->GetXaxis()->SetTitleSize(0.035);
   h_ByType2_Neutron_stack_3->GetXaxis()->SetTitleFont(42);
   h_ByType2_Neutron_stack_3->GetYaxis()->SetTitle("Events/bin");
   h_ByType2_Neutron_stack_3->GetYaxis()->SetLabelFont(42);
   h_ByType2_Neutron_stack_3->GetYaxis()->SetLabelSize(0.035);
   h_ByType2_Neutron_stack_3->GetYaxis()->SetTitleSize(0.035);
   h_ByType2_Neutron_stack_3->GetYaxis()->SetTitleOffset(0);
   h_ByType2_Neutron_stack_3->GetYaxis()->SetTitleFont(42);
   h_ByType2_Neutron_stack_3->GetZaxis()->SetLabelFont(42);
   h_ByType2_Neutron_stack_3->GetZaxis()->SetLabelSize(0.035);
   h_ByType2_Neutron_stack_3->GetZaxis()->SetTitleSize(0.035);
   h_ByType2_Neutron_stack_3->GetZaxis()->SetTitleFont(42);
   hs->Add(h_ByType2_Neutron_stack_3,"HIST");
   
   TH1D *h_ByType2_Dirt_stack_4 = new TH1D("h_ByType2_Dirt_stack_4","",16,0,0.8);

   ci = TColor::GetColor("#006666");
   h_ByType2_Dirt_stack_4->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   h_ByType2_Dirt_stack_4->SetLineColor(ci);
   h_ByType2_Dirt_stack_4->GetXaxis()->SetTitle("Reconstructed Invariant Mass of Pion Pair (GeV)");
   h_ByType2_Dirt_stack_4->GetXaxis()->SetLabelFont(42);
   h_ByType2_Dirt_stack_4->GetXaxis()->SetLabelSize(0.035);
   h_ByType2_Dirt_stack_4->GetXaxis()->SetTitleSize(0.035);
   h_ByType2_Dirt_stack_4->GetXaxis()->SetTitleFont(42);
   h_ByType2_Dirt_stack_4->GetYaxis()->SetTitle("Events/bin");
   h_ByType2_Dirt_stack_4->GetYaxis()->SetLabelFont(42);
   h_ByType2_Dirt_stack_4->GetYaxis()->SetLabelSize(0.035);
   h_ByType2_Dirt_stack_4->GetYaxis()->SetTitleSize(0.035);
   h_ByType2_Dirt_stack_4->GetYaxis()->SetTitleOffset(0);
   h_ByType2_Dirt_stack_4->GetYaxis()->SetTitleFont(42);
   h_ByType2_Dirt_stack_4->GetZaxis()->SetLabelFont(42);
   h_ByType2_Dirt_stack_4->GetZaxis()->SetLabelSize(0.035);
   h_ByType2_Dirt_stack_4->GetZaxis()->SetTitleSize(0.035);
   h_ByType2_Dirt_stack_4->GetZaxis()->SetTitleFont(42);
   hs->Add(h_ByType2_Dirt_stack_4,"HIST");
   
   TH1D *h_ByType2_RESLambda_stack_5 = new TH1D("h_ByType2_RESLambda_stack_5","",16,0,0.8);

   ci = TColor::GetColor("#006600");
   h_ByType2_RESLambda_stack_5->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   h_ByType2_RESLambda_stack_5->SetLineColor(ci);
   h_ByType2_RESLambda_stack_5->GetXaxis()->SetTitle("Reconstructed Invariant Mass of Pion Pair (GeV)");
   h_ByType2_RESLambda_stack_5->GetXaxis()->SetLabelFont(42);
   h_ByType2_RESLambda_stack_5->GetXaxis()->SetLabelSize(0.035);
   h_ByType2_RESLambda_stack_5->GetXaxis()->SetTitleSize(0.035);
   h_ByType2_RESLambda_stack_5->GetXaxis()->SetTitleFont(42);
   h_ByType2_RESLambda_stack_5->GetYaxis()->SetTitle("Events/bin");
   h_ByType2_RESLambda_stack_5->GetYaxis()->SetLabelFont(42);
   h_ByType2_RESLambda_stack_5->GetYaxis()->SetLabelSize(0.035);
   h_ByType2_RESLambda_stack_5->GetYaxis()->SetTitleSize(0.035);
   h_ByType2_RESLambda_stack_5->GetYaxis()->SetTitleOffset(0);
   h_ByType2_RESLambda_stack_5->GetYaxis()->SetTitleFont(42);
   h_ByType2_RESLambda_stack_5->GetZaxis()->SetLabelFont(42);
   h_ByType2_RESLambda_stack_5->GetZaxis()->SetLabelSize(0.035);
   h_ByType2_RESLambda_stack_5->GetZaxis()->SetTitleSize(0.035);
   h_ByType2_RESLambda_stack_5->GetZaxis()->SetTitleFont(42);
   hs->Add(h_ByType2_RESLambda_stack_5,"HIST");
   
   TH1D *h_ByType2_RESHYP_stack_6 = new TH1D("h_ByType2_RESHYP_stack_6","",16,0,0.8);

   ci = TColor::GetColor("#ccccff");
   h_ByType2_RESHYP_stack_6->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   h_ByType2_RESHYP_stack_6->SetLineColor(ci);
   h_ByType2_RESHYP_stack_6->GetXaxis()->SetTitle("Reconstructed Invariant Mass of Pion Pair (GeV)");
   h_ByType2_RESHYP_stack_6->GetXaxis()->SetLabelFont(42);
   h_ByType2_RESHYP_stack_6->GetXaxis()->SetLabelSize(0.035);
   h_ByType2_RESHYP_stack_6->GetXaxis()->SetTitleSize(0.035);
   h_ByType2_RESHYP_stack_6->GetXaxis()->SetTitleFont(42);
   h_ByType2_RESHYP_stack_6->GetYaxis()->SetTitle("Events/bin");
   h_ByType2_RESHYP_stack_6->GetYaxis()->SetLabelFont(42);
   h_ByType2_RESHYP_stack_6->GetYaxis()->SetLabelSize(0.035);
   h_ByType2_RESHYP_stack_6->GetYaxis()->SetTitleSize(0.035);
   h_ByType2_RESHYP_stack_6->GetYaxis()->SetTitleOffset(0);
   h_ByType2_RESHYP_stack_6->GetYaxis()->SetTitleFont(42);
   h_ByType2_RESHYP_stack_6->GetZaxis()->SetLabelFont(42);
   h_ByType2_RESHYP_stack_6->GetZaxis()->SetLabelSize(0.035);
   h_ByType2_RESHYP_stack_6->GetZaxis()->SetTitleSize(0.035);
   h_ByType2_RESHYP_stack_6->GetZaxis()->SetTitleFont(42);
   hs->Add(h_ByType2_RESHYP_stack_6,"HIST");
   
   TH1D *h_ByType2_Other_stack_7 = new TH1D("h_ByType2_Other_stack_7","",16,0,0.8);

   ci = TColor::GetColor("#ffcccc");
   h_ByType2_Other_stack_7->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   h_ByType2_Other_stack_7->SetLineColor(ci);
   h_ByType2_Other_stack_7->GetXaxis()->SetTitle("Reconstructed Invariant Mass of Pion Pair (GeV)");
   h_ByType2_Other_stack_7->GetXaxis()->SetLabelFont(42);
   h_ByType2_Other_stack_7->GetXaxis()->SetLabelSize(0.035);
   h_ByType2_Other_stack_7->GetXaxis()->SetTitleSize(0.035);
   h_ByType2_Other_stack_7->GetXaxis()->SetTitleFont(42);
   h_ByType2_Other_stack_7->GetYaxis()->SetTitle("Events/bin");
   h_ByType2_Other_stack_7->GetYaxis()->SetLabelFont(42);
   h_ByType2_Other_stack_7->GetYaxis()->SetLabelSize(0.035);
   h_ByType2_Other_stack_7->GetYaxis()->SetTitleSize(0.035);
   h_ByType2_Other_stack_7->GetYaxis()->SetTitleOffset(0);
   h_ByType2_Other_stack_7->GetYaxis()->SetTitleFont(42);
   h_ByType2_Other_stack_7->GetZaxis()->SetLabelFont(42);
   h_ByType2_Other_stack_7->GetZaxis()->SetLabelSize(0.035);
   h_ByType2_Other_stack_7->GetZaxis()->SetTitleSize(0.035);
   h_ByType2_Other_stack_7->GetZaxis()->SetTitleFont(42);
   hs->Add(h_ByType2_Other_stack_7,"HIST");
   
   TH1D *h_ByType2_EXT_stack_8 = new TH1D("h_ByType2_EXT_stack_8","",16,0,0.8);

   ci = TColor::GetColor("#ff66ff");
   h_ByType2_EXT_stack_8->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   h_ByType2_EXT_stack_8->SetLineColor(ci);
   h_ByType2_EXT_stack_8->GetXaxis()->SetTitle("Reconstructed Invariant Mass of Pion Pair (GeV)");
   h_ByType2_EXT_stack_8->GetXaxis()->SetLabelFont(42);
   h_ByType2_EXT_stack_8->GetXaxis()->SetLabelSize(0.035);
   h_ByType2_EXT_stack_8->GetXaxis()->SetTitleSize(0.035);
   h_ByType2_EXT_stack_8->GetXaxis()->SetTitleFont(42);
   h_ByType2_EXT_stack_8->GetYaxis()->SetTitle("Events/bin");
   h_ByType2_EXT_stack_8->GetYaxis()->SetLabelFont(42);
   h_ByType2_EXT_stack_8->GetYaxis()->SetLabelSize(0.035);
   h_ByType2_EXT_stack_8->GetYaxis()->SetTitleSize(0.035);
   h_ByType2_EXT_stack_8->GetYaxis()->SetTitleOffset(0);
   h_ByType2_EXT_stack_8->GetYaxis()->SetTitleFont(42);
   h_ByType2_EXT_stack_8->GetZaxis()->SetLabelFont(42);
   h_ByType2_EXT_stack_8->GetZaxis()->SetLabelSize(0.035);
   h_ByType2_EXT_stack_8->GetZaxis()->SetTitleSize(0.035);
   h_ByType2_EXT_stack_8->GetZaxis()->SetTitleFont(42);
   hs->Add(h_ByType2_EXT_stack_8,"HIST");
   
   TH1D *h_ByType2_DISLambda_stack_9 = new TH1D("h_ByType2_DISLambda_stack_9","",16,0,0.8);
   h_ByType2_DISLambda_stack_9->SetFillColor(30);

   ci = TColor::GetColor("#000099");
   h_ByType2_DISLambda_stack_9->SetLineColor(ci);
   h_ByType2_DISLambda_stack_9->GetXaxis()->SetTitle("Reconstructed Invariant Mass of Pion Pair (GeV)");
   h_ByType2_DISLambda_stack_9->GetXaxis()->SetLabelFont(42);
   h_ByType2_DISLambda_stack_9->GetXaxis()->SetLabelSize(0.035);
   h_ByType2_DISLambda_stack_9->GetXaxis()->SetTitleSize(0.035);
   h_ByType2_DISLambda_stack_9->GetXaxis()->SetTitleFont(42);
   h_ByType2_DISLambda_stack_9->GetYaxis()->SetTitle("Events/bin");
   h_ByType2_DISLambda_stack_9->GetYaxis()->SetLabelFont(42);
   h_ByType2_DISLambda_stack_9->GetYaxis()->SetLabelSize(0.035);
   h_ByType2_DISLambda_stack_9->GetYaxis()->SetTitleSize(0.035);
   h_ByType2_DISLambda_stack_9->GetYaxis()->SetTitleOffset(0);
   h_ByType2_DISLambda_stack_9->GetYaxis()->SetTitleFont(42);
   h_ByType2_DISLambda_stack_9->GetZaxis()->SetLabelFont(42);
   h_ByType2_DISLambda_stack_9->GetZaxis()->SetLabelSize(0.035);
   h_ByType2_DISLambda_stack_9->GetZaxis()->SetTitleSize(0.035);
   h_ByType2_DISLambda_stack_9->GetZaxis()->SetTitleFont(42);
   hs->Add(h_ByType2_DISLambda_stack_9,"HIST");
   
   TH1D *h_ByType2_DISHYP_stack_10 = new TH1D("h_ByType2_DISHYP_stack_10","",16,0,0.8);
   h_ByType2_DISHYP_stack_10->SetFillColor(15);

   ci = TColor::GetColor("#000099");
   h_ByType2_DISHYP_stack_10->SetLineColor(ci);
   h_ByType2_DISHYP_stack_10->GetXaxis()->SetTitle("Reconstructed Invariant Mass of Pion Pair (GeV)");
   h_ByType2_DISHYP_stack_10->GetXaxis()->SetLabelFont(42);
   h_ByType2_DISHYP_stack_10->GetXaxis()->SetLabelSize(0.035);
   h_ByType2_DISHYP_stack_10->GetXaxis()->SetTitleSize(0.035);
   h_ByType2_DISHYP_stack_10->GetXaxis()->SetTitleFont(42);
   h_ByType2_DISHYP_stack_10->GetYaxis()->SetTitle("Events/bin");
   h_ByType2_DISHYP_stack_10->GetYaxis()->SetLabelFont(42);
   h_ByType2_DISHYP_stack_10->GetYaxis()->SetLabelSize(0.035);
   h_ByType2_DISHYP_stack_10->GetYaxis()->SetTitleSize(0.035);
   h_ByType2_DISHYP_stack_10->GetYaxis()->SetTitleOffset(0);
   h_ByType2_DISHYP_stack_10->GetYaxis()->SetTitleFont(42);
   h_ByType2_DISHYP_stack_10->GetZaxis()->SetLabelFont(42);
   h_ByType2_DISHYP_stack_10->GetZaxis()->SetLabelSize(0.035);
   h_ByType2_DISHYP_stack_10->GetZaxis()->SetTitleSize(0.035);
   h_ByType2_DISHYP_stack_10->GetZaxis()->SetTitleFont(42);
   hs->Add(h_ByType2_DISHYP_stack_10,"HIST");
   hs->Draw("hist same");
   
   TH1D *h_errors__5 = new TH1D("h_errors__5","",16,0,0.8);
   h_errors__5->SetBinContent(6,0.6078599);
   h_errors__5->SetBinContent(7,3.97872);
   h_errors__5->SetBinContent(8,4.263521);
   h_errors__5->SetBinContent(9,2.291164);
   h_errors__5->SetBinContent(10,0.9691753);
   h_errors__5->SetBinContent(11,0.2763);
   h_errors__5->SetBinContent(12,0.05526);
   h_errors__5->SetBinContent(13,0.01275231);
   h_errors__5->SetBinContent(14,0.02975538);
   h_errors__5->SetBinContent(16,0.01700308);
   h_errors__5->SetBinContent(17,89.89101);
   h_errors__5->SetBinError(6,0.0508318);
   h_errors__5->SetBinError(7,0.1300485);
   h_errors__5->SetBinError(8,0.1346226);
   h_errors__5->SetBinError(9,0.09868744);
   h_errors__5->SetBinError(10,0.0641852);
   h_errors__5->SetBinError(11,0.03427079);
   h_errors__5->SetBinError(12,0.01532637);
   h_errors__5->SetBinError(13,0.007362548);
   h_errors__5->SetBinError(14,0.01124648);
   h_errors__5->SetBinError(16,0.008501538);
   h_errors__5->SetBinError(17,0.6181472);
   h_errors__5->SetMinimum(0);
   h_errors__5->SetMaximum(5.49768);
   h_errors__5->SetEntries(24088);
   h_errors__5->SetStats(0);
   h_errors__5->SetFillColor(1);
   h_errors__5->SetFillStyle(3253);

   ci = TColor::GetColor("#000099");
   h_errors__5->SetLineColor(ci);
   h_errors__5->GetXaxis()->SetTitle("Reconstructed Invariant Mass of Pion Pair (GeV)");
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
   
   TH1D *h_errors_copy__6 = new TH1D("h_errors_copy__6","",16,0,0.8);
   h_errors_copy__6->SetBinContent(6,0.6078599);
   h_errors_copy__6->SetBinContent(7,3.97872);
   h_errors_copy__6->SetBinContent(8,4.263521);
   h_errors_copy__6->SetBinContent(9,2.291164);
   h_errors_copy__6->SetBinContent(10,0.9691753);
   h_errors_copy__6->SetBinContent(11,0.2763);
   h_errors_copy__6->SetBinContent(12,0.05526);
   h_errors_copy__6->SetBinContent(13,0.01275231);
   h_errors_copy__6->SetBinContent(14,0.02975538);
   h_errors_copy__6->SetBinContent(16,0.01700308);
   h_errors_copy__6->SetBinContent(17,89.89101);
   h_errors_copy__6->SetBinError(6,0.0508318);
   h_errors_copy__6->SetBinError(7,0.1300485);
   h_errors_copy__6->SetBinError(8,0.1346226);
   h_errors_copy__6->SetBinError(9,0.09868744);
   h_errors_copy__6->SetBinError(10,0.0641852);
   h_errors_copy__6->SetBinError(11,0.03427079);
   h_errors_copy__6->SetBinError(12,0.01532637);
   h_errors_copy__6->SetBinError(13,0.007362548);
   h_errors_copy__6->SetBinError(14,0.01124648);
   h_errors_copy__6->SetBinError(16,0.008501538);
   h_errors_copy__6->SetBinError(17,0.6181472);
   h_errors_copy__6->SetMinimum(0);
   h_errors_copy__6->SetMaximum(5.49768);
   h_errors_copy__6->SetEntries(24088);
   h_errors_copy__6->SetDirectory(0);
   h_errors_copy__6->SetStats(0);
   h_errors_copy__6->SetFillColor(1);
   h_errors_copy__6->SetFillStyle(3253);

   ci = TColor::GetColor("#000099");
   h_errors_copy__6->SetLineColor(ci);
   h_errors_copy__6->GetXaxis()->SetTitle("Reconstructed Invariant Mass of Pion Pair (GeV)");
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
