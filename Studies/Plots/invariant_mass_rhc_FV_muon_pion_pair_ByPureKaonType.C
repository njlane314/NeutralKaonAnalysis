void invariant_mass_rhc_FV_muon_pion_pair_ByPureKaonType()
{
//=========Macro generated from canvas: c/c
//=========  (Mon Feb 12 10:09:57 2024) by ROOT version 6.12/06
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
   TLegendEntry *entry=leg->AddEntry("h_PureKaonSignalNuMuCCKaon","#nu_{#mu}CCK^{0}0#pi","F");

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
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
   entry=leg->AddEntry("h_PureKaonSignalNuMuCCKaonMultiPion","#nu_{#mu}CCK^{0}N#pi","F");

   ci = TColor::GetColor("#00cc00");
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
   entry=leg->AddEntry("h_PureKaonSignalNuMuCCKaonHyperon","#nu_{#mu}CCK^{0}Y0#pi","F");

   ci = TColor::GetColor("#009900");
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
   entry=leg->AddEntry("h_PureKaonSignalNuMuCCKaonHyperonMultiPion","#nu_{#mu}CCK^{0}YN#pi","F");

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
   entry=leg->AddEntry("h_PureKaonOtherNuMuCC","Other #nu_{#mu}CC","F");
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
   entry=leg->AddEntry("h_PureKaonNuECC","#nu_{e}CC","F");

   ci = TColor::GetColor("#cc33ff");
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
   entry=leg->AddEntry("h_PureKaonNC","NC","F");

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
   entry=leg->AddEntry("h_PureKaonOutFV","Out FV","F");

   ci = TColor::GetColor("#cccccc");
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
   p_plot->Range(0.15,-1.354336,0.65,12.18903);
   p_plot->SetFillColor(0);
   p_plot->SetBorderMode(0);
   p_plot->SetBorderSize(2);
   p_plot->SetTopMargin(0.01);
   p_plot->SetFrameBorderMode(0);
   p_plot->SetFrameBorderMode(0);
   
   TH1D *h_errors__1 = new TH1D("h_errors__1","",4,0.2,0.6);
   h_errors__1->SetBinContent(1,1.847528);
   h_errors__1->SetBinContent(2,9.337505);
   h_errors__1->SetBinContent(3,4.004641);
   h_errors__1->SetBinContent(4,1.737675);
   h_errors__1->SetBinContent(5,26.79414);
   h_errors__1->SetBinError(1,0.1358329);
   h_errors__1->SetBinError(2,0.3053691);
   h_errors__1->SetBinError(3,0.1999822);
   h_errors__1->SetBinError(4,0.1317328);
   h_errors__1->SetBinError(5,0.5172846);
   h_errors__1->SetMinimum(0);
   h_errors__1->SetMaximum(12.05359);
   h_errors__1->SetEntries(4435);
   h_errors__1->SetStats(0);
   h_errors__1->SetFillColor(1);
   h_errors__1->SetFillStyle(3253);

   ci = TColor::GetColor("#000099");
   h_errors__1->SetLineColor(ci);
   h_errors__1->GetXaxis()->SetTitle("Invariant Mass (GeV)");
   h_errors__1->GetXaxis()->SetLabelFont(42);
   h_errors__1->GetXaxis()->SetLabelSize(0.045);
   h_errors__1->GetXaxis()->SetTitleSize(0.05);
   h_errors__1->GetXaxis()->SetTitleOffset(0.93);
   h_errors__1->GetXaxis()->SetTitleFont(42);
   h_errors__1->GetYaxis()->SetTitle("Events/bin");
   h_errors__1->GetYaxis()->SetLabelFont(42);
   h_errors__1->GetYaxis()->SetLabelSize(0.045);
   h_errors__1->GetYaxis()->SetTitleSize(0.05);
   h_errors__1->GetYaxis()->SetTitleOffset(1.06);
   h_errors__1->GetYaxis()->SetTitleFont(42);
   h_errors__1->GetZaxis()->SetLabelFont(42);
   h_errors__1->GetZaxis()->SetLabelSize(0.035);
   h_errors__1->GetZaxis()->SetTitleSize(0.035);
   h_errors__1->GetZaxis()->SetTitleFont(42);
   h_errors__1->Draw("E2");
   
   THStack *hs = new THStack();
   hs->SetName("hs");
   hs->SetTitle("");
   
   TH1F *hs_stack_1 = new TH1F("hs_stack_1","",4,0.2,0.6);
   hs_stack_1->SetMinimum(0);
   hs_stack_1->SetMaximum(9.80438);
   hs_stack_1->SetDirectory(0);
   hs_stack_1->SetStats(0);

   ci = TColor::GetColor("#000099");
   hs_stack_1->SetLineColor(ci);
   hs_stack_1->GetXaxis()->SetLabelFont(42);
   hs_stack_1->GetXaxis()->SetLabelSize(0.035);
   hs_stack_1->GetXaxis()->SetTitleSize(0.035);
   hs_stack_1->GetXaxis()->SetTitleFont(42);
   hs_stack_1->GetYaxis()->SetLabelFont(42);
   hs_stack_1->GetYaxis()->SetLabelSize(0.035);
   hs_stack_1->GetYaxis()->SetTitleSize(0.035);
   hs_stack_1->GetYaxis()->SetTitleOffset(0);
   hs_stack_1->GetYaxis()->SetTitleFont(42);
   hs_stack_1->GetZaxis()->SetLabelFont(42);
   hs_stack_1->GetZaxis()->SetLabelSize(0.035);
   hs_stack_1->GetZaxis()->SetTitleSize(0.035);
   hs_stack_1->GetZaxis()->SetTitleFont(42);
   hs->SetHistogram(hs_stack_1);
   
   
   TH1D *h_PureKaonSignalNuMuCCKaon_stack_1 = new TH1D("h_PureKaonSignalNuMuCCKaon_stack_1","",4,0.2,0.6);
   h_PureKaonSignalNuMuCCKaon_stack_1->SetBinContent(1,0.04993318);
   h_PureKaonSignalNuMuCCKaon_stack_1->SetBinContent(2,0.3195723);
   h_PureKaonSignalNuMuCCKaon_stack_1->SetBinContent(3,0.1497995);
   h_PureKaonSignalNuMuCCKaon_stack_1->SetBinContent(4,0.03994654);
   h_PureKaonSignalNuMuCCKaon_stack_1->SetBinContent(5,0.848864);
   h_PureKaonSignalNuMuCCKaon_stack_1->SetBinError(1,0.0223308);
   h_PureKaonSignalNuMuCCKaon_stack_1->SetBinError(2,0.05649294);
   h_PureKaonSignalNuMuCCKaon_stack_1->SetBinError(3,0.03867807);
   h_PureKaonSignalNuMuCCKaon_stack_1->SetBinError(4,0.01997327);
   h_PureKaonSignalNuMuCCKaon_stack_1->SetBinError(5,0.09207223);
   h_PureKaonSignalNuMuCCKaon_stack_1->SetEntries(143);

   ci = TColor::GetColor("#00ff00");
   h_PureKaonSignalNuMuCCKaon_stack_1->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   h_PureKaonSignalNuMuCCKaon_stack_1->SetLineColor(ci);
   h_PureKaonSignalNuMuCCKaon_stack_1->GetXaxis()->SetTitle("Invariant Mass (GeV)");
   h_PureKaonSignalNuMuCCKaon_stack_1->GetXaxis()->SetLabelFont(42);
   h_PureKaonSignalNuMuCCKaon_stack_1->GetXaxis()->SetLabelSize(0.035);
   h_PureKaonSignalNuMuCCKaon_stack_1->GetXaxis()->SetTitleSize(0.035);
   h_PureKaonSignalNuMuCCKaon_stack_1->GetXaxis()->SetTitleFont(42);
   h_PureKaonSignalNuMuCCKaon_stack_1->GetYaxis()->SetTitle("Events/bin");
   h_PureKaonSignalNuMuCCKaon_stack_1->GetYaxis()->SetLabelFont(42);
   h_PureKaonSignalNuMuCCKaon_stack_1->GetYaxis()->SetLabelSize(0.035);
   h_PureKaonSignalNuMuCCKaon_stack_1->GetYaxis()->SetTitleSize(0.035);
   h_PureKaonSignalNuMuCCKaon_stack_1->GetYaxis()->SetTitleOffset(0);
   h_PureKaonSignalNuMuCCKaon_stack_1->GetYaxis()->SetTitleFont(42);
   h_PureKaonSignalNuMuCCKaon_stack_1->GetZaxis()->SetLabelFont(42);
   h_PureKaonSignalNuMuCCKaon_stack_1->GetZaxis()->SetLabelSize(0.035);
   h_PureKaonSignalNuMuCCKaon_stack_1->GetZaxis()->SetTitleSize(0.035);
   h_PureKaonSignalNuMuCCKaon_stack_1->GetZaxis()->SetTitleFont(42);
   hs->Add(h_PureKaonSignalNuMuCCKaon_stack_1,"HIST");
   
   TH1D *h_PureKaonSignalNuMuCCKaonMultiPion_stack_2 = new TH1D("h_PureKaonSignalNuMuCCKaonMultiPion_stack_2","",4,0.2,0.6);
   h_PureKaonSignalNuMuCCKaonMultiPion_stack_2->SetBinContent(1,0.1497995);
   h_PureKaonSignalNuMuCCKaonMultiPion_stack_2->SetBinContent(2,0.5093184);
   h_PureKaonSignalNuMuCCKaonMultiPion_stack_2->SetBinContent(3,0.2396793);
   h_PureKaonSignalNuMuCCKaonMultiPion_stack_2->SetBinContent(4,0.1697728);
   h_PureKaonSignalNuMuCCKaonMultiPion_stack_2->SetBinContent(5,1.248329);
   h_PureKaonSignalNuMuCCKaonMultiPion_stack_2->SetBinError(1,0.03867807);
   h_PureKaonSignalNuMuCCKaonMultiPion_stack_2->SetBinError(2,0.07131885);
   h_PureKaonSignalNuMuCCKaonMultiPion_stack_2->SetBinError(3,0.04892432);
   h_PureKaonSignalNuMuCCKaonMultiPion_stack_2->SetBinError(4,0.04117595);
   h_PureKaonSignalNuMuCCKaonMultiPion_stack_2->SetBinError(5,0.111654);
   h_PureKaonSignalNuMuCCKaonMultiPion_stack_2->SetEntries(249);

   ci = TColor::GetColor("#00cc00");
   h_PureKaonSignalNuMuCCKaonMultiPion_stack_2->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   h_PureKaonSignalNuMuCCKaonMultiPion_stack_2->SetLineColor(ci);
   h_PureKaonSignalNuMuCCKaonMultiPion_stack_2->GetXaxis()->SetTitle("Invariant Mass (GeV)");
   h_PureKaonSignalNuMuCCKaonMultiPion_stack_2->GetXaxis()->SetLabelFont(42);
   h_PureKaonSignalNuMuCCKaonMultiPion_stack_2->GetXaxis()->SetLabelSize(0.035);
   h_PureKaonSignalNuMuCCKaonMultiPion_stack_2->GetXaxis()->SetTitleSize(0.035);
   h_PureKaonSignalNuMuCCKaonMultiPion_stack_2->GetXaxis()->SetTitleFont(42);
   h_PureKaonSignalNuMuCCKaonMultiPion_stack_2->GetYaxis()->SetTitle("Events/bin");
   h_PureKaonSignalNuMuCCKaonMultiPion_stack_2->GetYaxis()->SetLabelFont(42);
   h_PureKaonSignalNuMuCCKaonMultiPion_stack_2->GetYaxis()->SetLabelSize(0.035);
   h_PureKaonSignalNuMuCCKaonMultiPion_stack_2->GetYaxis()->SetTitleSize(0.035);
   h_PureKaonSignalNuMuCCKaonMultiPion_stack_2->GetYaxis()->SetTitleOffset(0);
   h_PureKaonSignalNuMuCCKaonMultiPion_stack_2->GetYaxis()->SetTitleFont(42);
   h_PureKaonSignalNuMuCCKaonMultiPion_stack_2->GetZaxis()->SetLabelFont(42);
   h_PureKaonSignalNuMuCCKaonMultiPion_stack_2->GetZaxis()->SetLabelSize(0.035);
   h_PureKaonSignalNuMuCCKaonMultiPion_stack_2->GetZaxis()->SetTitleSize(0.035);
   h_PureKaonSignalNuMuCCKaonMultiPion_stack_2->GetZaxis()->SetTitleFont(42);
   hs->Add(h_PureKaonSignalNuMuCCKaonMultiPion_stack_2,"HIST");
   
   TH1D *h_PureKaonSignalNuMuCCKaonHyperon_stack_3 = new TH1D("h_PureKaonSignalNuMuCCKaonHyperon_stack_3","",4,0.2,0.6);
   h_PureKaonSignalNuMuCCKaonHyperon_stack_3->SetBinContent(1,0.1298263);
   h_PureKaonSignalNuMuCCKaonHyperon_stack_3->SetBinContent(2,0.9886769);
   h_PureKaonSignalNuMuCCKaonHyperon_stack_3->SetBinContent(3,0.6890779);
   h_PureKaonSignalNuMuCCKaonHyperon_stack_3->SetBinContent(4,0.219706);
   h_PureKaonSignalNuMuCCKaonHyperon_stack_3->SetBinContent(5,3.665095);
   h_PureKaonSignalNuMuCCKaonHyperon_stack_3->SetBinError(1,0.03600733);
   h_PureKaonSignalNuMuCCKaonHyperon_stack_3->SetBinError(2,0.09936577);
   h_PureKaonSignalNuMuCCKaonHyperon_stack_3->SetBinError(3,0.08295523);
   h_PureKaonSignalNuMuCCKaonHyperon_stack_3->SetBinError(4,0.04684147);
   h_PureKaonSignalNuMuCCKaonHyperon_stack_3->SetBinError(5,0.1913164);
   h_PureKaonSignalNuMuCCKaonHyperon_stack_3->SetEntries(570);

   ci = TColor::GetColor("#009900");
   h_PureKaonSignalNuMuCCKaonHyperon_stack_3->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   h_PureKaonSignalNuMuCCKaonHyperon_stack_3->SetLineColor(ci);
   h_PureKaonSignalNuMuCCKaonHyperon_stack_3->GetXaxis()->SetTitle("Invariant Mass (GeV)");
   h_PureKaonSignalNuMuCCKaonHyperon_stack_3->GetXaxis()->SetLabelFont(42);
   h_PureKaonSignalNuMuCCKaonHyperon_stack_3->GetXaxis()->SetLabelSize(0.035);
   h_PureKaonSignalNuMuCCKaonHyperon_stack_3->GetXaxis()->SetTitleSize(0.035);
   h_PureKaonSignalNuMuCCKaonHyperon_stack_3->GetXaxis()->SetTitleFont(42);
   h_PureKaonSignalNuMuCCKaonHyperon_stack_3->GetYaxis()->SetTitle("Events/bin");
   h_PureKaonSignalNuMuCCKaonHyperon_stack_3->GetYaxis()->SetLabelFont(42);
   h_PureKaonSignalNuMuCCKaonHyperon_stack_3->GetYaxis()->SetLabelSize(0.035);
   h_PureKaonSignalNuMuCCKaonHyperon_stack_3->GetYaxis()->SetTitleSize(0.035);
   h_PureKaonSignalNuMuCCKaonHyperon_stack_3->GetYaxis()->SetTitleOffset(0);
   h_PureKaonSignalNuMuCCKaonHyperon_stack_3->GetYaxis()->SetTitleFont(42);
   h_PureKaonSignalNuMuCCKaonHyperon_stack_3->GetZaxis()->SetLabelFont(42);
   h_PureKaonSignalNuMuCCKaonHyperon_stack_3->GetZaxis()->SetLabelSize(0.035);
   h_PureKaonSignalNuMuCCKaonHyperon_stack_3->GetZaxis()->SetTitleSize(0.035);
   h_PureKaonSignalNuMuCCKaonHyperon_stack_3->GetZaxis()->SetTitleFont(42);
   hs->Add(h_PureKaonSignalNuMuCCKaonHyperon_stack_3,"HIST");
   
   TH1D *h_PureKaonSignalNuMuCCKaonHyperonMultiPion_stack_4 = new TH1D("h_PureKaonSignalNuMuCCKaonHyperonMultiPion_stack_4","",4,0.2,0.6);
   h_PureKaonSignalNuMuCCKaonHyperonMultiPion_stack_4->SetBinContent(1,0.5892115);
   h_PureKaonSignalNuMuCCKaonHyperonMultiPion_stack_4->SetBinContent(2,2.456712);
   h_PureKaonSignalNuMuCCKaonHyperonMultiPion_stack_4->SetBinContent(3,1.12849);
   h_PureKaonSignalNuMuCCKaonHyperonMultiPion_stack_4->SetBinContent(4,0.5093184);
   h_PureKaonSignalNuMuCCKaonHyperonMultiPion_stack_4->SetBinContent(5,5.962022);
   h_PureKaonSignalNuMuCCKaonHyperonMultiPion_stack_4->SetBinError(1,0.07670881);
   h_PureKaonSignalNuMuCCKaonHyperonMultiPion_stack_4->SetBinError(2,0.1566343);
   h_PureKaonSignalNuMuCCKaonHyperonMultiPion_stack_4->SetBinError(3,0.1061594);
   h_PureKaonSignalNuMuCCKaonHyperonMultiPion_stack_4->SetBinError(4,0.07131885);
   h_PureKaonSignalNuMuCCKaonHyperonMultiPion_stack_4->SetBinError(5,0.2440093);
   h_PureKaonSignalNuMuCCKaonHyperonMultiPion_stack_4->SetEntries(1068);

   ci = TColor::GetColor("#006600");
   h_PureKaonSignalNuMuCCKaonHyperonMultiPion_stack_4->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   h_PureKaonSignalNuMuCCKaonHyperonMultiPion_stack_4->SetLineColor(ci);
   h_PureKaonSignalNuMuCCKaonHyperonMultiPion_stack_4->GetXaxis()->SetTitle("Invariant Mass (GeV)");
   h_PureKaonSignalNuMuCCKaonHyperonMultiPion_stack_4->GetXaxis()->SetLabelFont(42);
   h_PureKaonSignalNuMuCCKaonHyperonMultiPion_stack_4->GetXaxis()->SetLabelSize(0.035);
   h_PureKaonSignalNuMuCCKaonHyperonMultiPion_stack_4->GetXaxis()->SetTitleSize(0.035);
   h_PureKaonSignalNuMuCCKaonHyperonMultiPion_stack_4->GetXaxis()->SetTitleFont(42);
   h_PureKaonSignalNuMuCCKaonHyperonMultiPion_stack_4->GetYaxis()->SetTitle("Events/bin");
   h_PureKaonSignalNuMuCCKaonHyperonMultiPion_stack_4->GetYaxis()->SetLabelFont(42);
   h_PureKaonSignalNuMuCCKaonHyperonMultiPion_stack_4->GetYaxis()->SetLabelSize(0.035);
   h_PureKaonSignalNuMuCCKaonHyperonMultiPion_stack_4->GetYaxis()->SetTitleSize(0.035);
   h_PureKaonSignalNuMuCCKaonHyperonMultiPion_stack_4->GetYaxis()->SetTitleOffset(0);
   h_PureKaonSignalNuMuCCKaonHyperonMultiPion_stack_4->GetYaxis()->SetTitleFont(42);
   h_PureKaonSignalNuMuCCKaonHyperonMultiPion_stack_4->GetZaxis()->SetLabelFont(42);
   h_PureKaonSignalNuMuCCKaonHyperonMultiPion_stack_4->GetZaxis()->SetLabelSize(0.035);
   h_PureKaonSignalNuMuCCKaonHyperonMultiPion_stack_4->GetZaxis()->SetTitleSize(0.035);
   h_PureKaonSignalNuMuCCKaonHyperonMultiPion_stack_4->GetZaxis()->SetTitleFont(42);
   hs->Add(h_PureKaonSignalNuMuCCKaonHyperonMultiPion_stack_4,"HIST");
   
   TH1D *h_PureKaonOtherNuMuCC_stack_5 = new TH1D("h_PureKaonOtherNuMuCC_stack_5","",4,0.2,0.6);
   h_PureKaonOtherNuMuCC_stack_5->SetBinContent(1,0.4094521);
   h_PureKaonOtherNuMuCC_stack_5->SetBinContent(2,2.776285);
   h_PureKaonOtherNuMuCC_stack_5->SetBinContent(3,0.848864);
   h_PureKaonOtherNuMuCC_stack_5->SetBinContent(4,0.4893452);
   h_PureKaonOtherNuMuCC_stack_5->SetBinContent(5,7.849496);
   h_PureKaonOtherNuMuCC_stack_5->SetBinError(1,0.06394567);
   h_PureKaonOtherNuMuCC_stack_5->SetBinError(2,0.1665105);
   h_PureKaonOtherNuMuCC_stack_5->SetBinError(3,0.09207223);
   h_PureKaonOtherNuMuCC_stack_5->SetBinError(4,0.06990645);
   h_PureKaonOtherNuMuCC_stack_5->SetBinError(5,0.2799822);
   h_PureKaonOtherNuMuCC_stack_5->SetEntries(1250);
   h_PureKaonOtherNuMuCC_stack_5->SetFillColor(30);

   ci = TColor::GetColor("#000099");
   h_PureKaonOtherNuMuCC_stack_5->SetLineColor(ci);
   h_PureKaonOtherNuMuCC_stack_5->GetXaxis()->SetTitle("Invariant Mass (GeV)");
   h_PureKaonOtherNuMuCC_stack_5->GetXaxis()->SetLabelFont(42);
   h_PureKaonOtherNuMuCC_stack_5->GetXaxis()->SetLabelSize(0.035);
   h_PureKaonOtherNuMuCC_stack_5->GetXaxis()->SetTitleSize(0.035);
   h_PureKaonOtherNuMuCC_stack_5->GetXaxis()->SetTitleFont(42);
   h_PureKaonOtherNuMuCC_stack_5->GetYaxis()->SetTitle("Events/bin");
   h_PureKaonOtherNuMuCC_stack_5->GetYaxis()->SetLabelFont(42);
   h_PureKaonOtherNuMuCC_stack_5->GetYaxis()->SetLabelSize(0.035);
   h_PureKaonOtherNuMuCC_stack_5->GetYaxis()->SetTitleSize(0.035);
   h_PureKaonOtherNuMuCC_stack_5->GetYaxis()->SetTitleOffset(0);
   h_PureKaonOtherNuMuCC_stack_5->GetYaxis()->SetTitleFont(42);
   h_PureKaonOtherNuMuCC_stack_5->GetZaxis()->SetLabelFont(42);
   h_PureKaonOtherNuMuCC_stack_5->GetZaxis()->SetLabelSize(0.035);
   h_PureKaonOtherNuMuCC_stack_5->GetZaxis()->SetTitleSize(0.035);
   h_PureKaonOtherNuMuCC_stack_5->GetZaxis()->SetTitleFont(42);
   hs->Add(h_PureKaonOtherNuMuCC_stack_5,"HIST");
   
   TH1D *h_PureKaonNuECC_stack_6 = new TH1D("h_PureKaonNuECC_stack_6","",4,0.2,0.6);
   h_PureKaonNuECC_stack_6->SetBinContent(2,0.08987972);
   h_PureKaonNuECC_stack_6->SetBinContent(3,0.009986636);
   h_PureKaonNuECC_stack_6->SetBinContent(4,0.009986636);
   h_PureKaonNuECC_stack_6->SetBinContent(5,0.1897461);
   h_PureKaonNuECC_stack_6->SetBinError(2,0.02995991);
   h_PureKaonNuECC_stack_6->SetBinError(3,0.009986636);
   h_PureKaonNuECC_stack_6->SetBinError(4,0.009986636);
   h_PureKaonNuECC_stack_6->SetBinError(5,0.04353074);
   h_PureKaonNuECC_stack_6->SetEntries(30);

   ci = TColor::GetColor("#cc33ff");
   h_PureKaonNuECC_stack_6->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   h_PureKaonNuECC_stack_6->SetLineColor(ci);
   h_PureKaonNuECC_stack_6->GetXaxis()->SetTitle("Invariant Mass (GeV)");
   h_PureKaonNuECC_stack_6->GetXaxis()->SetLabelFont(42);
   h_PureKaonNuECC_stack_6->GetXaxis()->SetLabelSize(0.035);
   h_PureKaonNuECC_stack_6->GetXaxis()->SetTitleSize(0.035);
   h_PureKaonNuECC_stack_6->GetXaxis()->SetTitleFont(42);
   h_PureKaonNuECC_stack_6->GetYaxis()->SetTitle("Events/bin");
   h_PureKaonNuECC_stack_6->GetYaxis()->SetLabelFont(42);
   h_PureKaonNuECC_stack_6->GetYaxis()->SetLabelSize(0.035);
   h_PureKaonNuECC_stack_6->GetYaxis()->SetTitleSize(0.035);
   h_PureKaonNuECC_stack_6->GetYaxis()->SetTitleOffset(0);
   h_PureKaonNuECC_stack_6->GetYaxis()->SetTitleFont(42);
   h_PureKaonNuECC_stack_6->GetZaxis()->SetLabelFont(42);
   h_PureKaonNuECC_stack_6->GetZaxis()->SetLabelSize(0.035);
   h_PureKaonNuECC_stack_6->GetZaxis()->SetTitleSize(0.035);
   h_PureKaonNuECC_stack_6->GetZaxis()->SetTitleFont(42);
   hs->Add(h_PureKaonNuECC_stack_6,"HIST");
   
   TH1D *h_PureKaonNC_stack_7 = new TH1D("h_PureKaonNC_stack_7","",4,0.2,0.6);
   h_PureKaonNC_stack_7->SetBinContent(1,0.439412);
   h_PureKaonNC_stack_7->SetBinContent(2,1.717701);
   h_PureKaonNC_stack_7->SetBinContent(3,0.7290244);
   h_PureKaonNC_stack_7->SetBinContent(4,0.1597862);
   h_PureKaonNC_stack_7->SetBinContent(5,4.693719);
   h_PureKaonNC_stack_7->SetBinError(1,0.06624385);
   h_PureKaonNC_stack_7->SetBinError(2,0.1309735);
   h_PureKaonNC_stack_7->SetBinError(3,0.08532585);
   h_PureKaonNC_stack_7->SetBinError(4,0.03994654);
   h_PureKaonNC_stack_7->SetBinError(5,0.2165051);
   h_PureKaonNC_stack_7->SetEntries(788);

   ci = TColor::GetColor("#ffcc00");
   h_PureKaonNC_stack_7->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   h_PureKaonNC_stack_7->SetLineColor(ci);
   h_PureKaonNC_stack_7->GetXaxis()->SetTitle("Invariant Mass (GeV)");
   h_PureKaonNC_stack_7->GetXaxis()->SetLabelFont(42);
   h_PureKaonNC_stack_7->GetXaxis()->SetLabelSize(0.035);
   h_PureKaonNC_stack_7->GetXaxis()->SetTitleSize(0.035);
   h_PureKaonNC_stack_7->GetXaxis()->SetTitleFont(42);
   h_PureKaonNC_stack_7->GetYaxis()->SetTitle("Events/bin");
   h_PureKaonNC_stack_7->GetYaxis()->SetLabelFont(42);
   h_PureKaonNC_stack_7->GetYaxis()->SetLabelSize(0.035);
   h_PureKaonNC_stack_7->GetYaxis()->SetTitleSize(0.035);
   h_PureKaonNC_stack_7->GetYaxis()->SetTitleOffset(0);
   h_PureKaonNC_stack_7->GetYaxis()->SetTitleFont(42);
   h_PureKaonNC_stack_7->GetZaxis()->SetLabelFont(42);
   h_PureKaonNC_stack_7->GetZaxis()->SetLabelSize(0.035);
   h_PureKaonNC_stack_7->GetZaxis()->SetTitleSize(0.035);
   h_PureKaonNC_stack_7->GetZaxis()->SetTitleFont(42);
   hs->Add(h_PureKaonNC_stack_7,"HIST");
   
   TH1D *h_PureKaonOutFV_stack_8 = new TH1D("h_PureKaonOutFV_stack_8","",4,0.2,0.6);
   h_PureKaonOutFV_stack_8->SetBinContent(1,0.07989309);
   h_PureKaonOutFV_stack_8->SetBinContent(2,0.4793585);
   h_PureKaonOutFV_stack_8->SetBinContent(3,0.2097194);
   h_PureKaonOutFV_stack_8->SetBinContent(4,0.1398129);
   h_PureKaonOutFV_stack_8->SetBinContent(5,2.336873);
   h_PureKaonOutFV_stack_8->SetBinError(1,0.02824647);
   h_PureKaonOutFV_stack_8->SetBinError(2,0.06918944);
   h_PureKaonOutFV_stack_8->SetBinError(3,0.04576451);
   h_PureKaonOutFV_stack_8->SetBinError(4,0.03736657);
   h_PureKaonOutFV_stack_8->SetBinError(5,0.1527662);
   h_PureKaonOutFV_stack_8->SetEntries(337);

   ci = TColor::GetColor("#cccccc");
   h_PureKaonOutFV_stack_8->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   h_PureKaonOutFV_stack_8->SetLineColor(ci);
   h_PureKaonOutFV_stack_8->GetXaxis()->SetTitle("Invariant Mass (GeV)");
   h_PureKaonOutFV_stack_8->GetXaxis()->SetLabelFont(42);
   h_PureKaonOutFV_stack_8->GetXaxis()->SetLabelSize(0.035);
   h_PureKaonOutFV_stack_8->GetXaxis()->SetTitleSize(0.035);
   h_PureKaonOutFV_stack_8->GetXaxis()->SetTitleFont(42);
   h_PureKaonOutFV_stack_8->GetYaxis()->SetTitle("Events/bin");
   h_PureKaonOutFV_stack_8->GetYaxis()->SetLabelFont(42);
   h_PureKaonOutFV_stack_8->GetYaxis()->SetLabelSize(0.035);
   h_PureKaonOutFV_stack_8->GetYaxis()->SetTitleSize(0.035);
   h_PureKaonOutFV_stack_8->GetYaxis()->SetTitleOffset(0);
   h_PureKaonOutFV_stack_8->GetYaxis()->SetTitleFont(42);
   h_PureKaonOutFV_stack_8->GetZaxis()->SetLabelFont(42);
   h_PureKaonOutFV_stack_8->GetZaxis()->SetLabelSize(0.035);
   h_PureKaonOutFV_stack_8->GetZaxis()->SetTitleSize(0.035);
   h_PureKaonOutFV_stack_8->GetZaxis()->SetTitleFont(42);
   hs->Add(h_PureKaonOutFV_stack_8,"HIST");
   hs->Draw("hist same");
   
   TH1D *h_errors__2 = new TH1D("h_errors__2","",4,0.2,0.6);
   h_errors__2->SetBinContent(1,1.847528);
   h_errors__2->SetBinContent(2,9.337505);
   h_errors__2->SetBinContent(3,4.004641);
   h_errors__2->SetBinContent(4,1.737675);
   h_errors__2->SetBinContent(5,26.79414);
   h_errors__2->SetBinError(1,0.1358329);
   h_errors__2->SetBinError(2,0.3053691);
   h_errors__2->SetBinError(3,0.1999822);
   h_errors__2->SetBinError(4,0.1317328);
   h_errors__2->SetBinError(5,0.5172846);
   h_errors__2->SetMinimum(0);
   h_errors__2->SetMaximum(12.05359);
   h_errors__2->SetEntries(4435);
   h_errors__2->SetStats(0);
   h_errors__2->SetFillColor(1);
   h_errors__2->SetFillStyle(3253);

   ci = TColor::GetColor("#000099");
   h_errors__2->SetLineColor(ci);
   h_errors__2->GetXaxis()->SetTitle("Invariant Mass (GeV)");
   h_errors__2->GetXaxis()->SetLabelFont(42);
   h_errors__2->GetXaxis()->SetLabelSize(0.045);
   h_errors__2->GetXaxis()->SetTitleSize(0.05);
   h_errors__2->GetXaxis()->SetTitleOffset(0.93);
   h_errors__2->GetXaxis()->SetTitleFont(42);
   h_errors__2->GetYaxis()->SetTitle("Events/bin");
   h_errors__2->GetYaxis()->SetLabelFont(42);
   h_errors__2->GetYaxis()->SetLabelSize(0.045);
   h_errors__2->GetYaxis()->SetTitleSize(0.05);
   h_errors__2->GetYaxis()->SetTitleOffset(1.06);
   h_errors__2->GetYaxis()->SetTitleFont(42);
   h_errors__2->GetZaxis()->SetLabelFont(42);
   h_errors__2->GetZaxis()->SetLabelSize(0.035);
   h_errors__2->GetZaxis()->SetTitleSize(0.035);
   h_errors__2->GetZaxis()->SetTitleFont(42);
   h_errors__2->Draw("E2 same");
   
   TH1D *h_errors_copy__3 = new TH1D("h_errors_copy__3","",4,0.2,0.6);
   h_errors_copy__3->SetBinContent(1,1.847528);
   h_errors_copy__3->SetBinContent(2,9.337505);
   h_errors_copy__3->SetBinContent(3,4.004641);
   h_errors_copy__3->SetBinContent(4,1.737675);
   h_errors_copy__3->SetBinContent(5,26.79414);
   h_errors_copy__3->SetBinError(1,0.1358329);
   h_errors_copy__3->SetBinError(2,0.3053691);
   h_errors_copy__3->SetBinError(3,0.1999822);
   h_errors_copy__3->SetBinError(4,0.1317328);
   h_errors_copy__3->SetBinError(5,0.5172846);
   h_errors_copy__3->SetMinimum(0);
   h_errors_copy__3->SetMaximum(12.05359);
   h_errors_copy__3->SetEntries(4435);
   h_errors_copy__3->SetDirectory(0);
   h_errors_copy__3->SetStats(0);
   h_errors_copy__3->SetFillColor(1);
   h_errors_copy__3->SetFillStyle(3253);

   ci = TColor::GetColor("#000099");
   h_errors_copy__3->SetLineColor(ci);
   h_errors_copy__3->GetXaxis()->SetTitle("Invariant Mass (GeV)");
   h_errors_copy__3->GetXaxis()->SetLabelFont(42);
   h_errors_copy__3->GetXaxis()->SetLabelSize(0.045);
   h_errors_copy__3->GetXaxis()->SetTitleSize(0.05);
   h_errors_copy__3->GetXaxis()->SetTitleOffset(0.93);
   h_errors_copy__3->GetXaxis()->SetTitleFont(42);
   h_errors_copy__3->GetYaxis()->SetTitle("Events/bin");
   h_errors_copy__3->GetYaxis()->SetLabelFont(42);
   h_errors_copy__3->GetYaxis()->SetLabelSize(0.045);
   h_errors_copy__3->GetYaxis()->SetTitleSize(0.05);
   h_errors_copy__3->GetYaxis()->SetTitleOffset(1.06);
   h_errors_copy__3->GetYaxis()->SetTitleFont(42);
   h_errors_copy__3->GetZaxis()->SetLabelFont(42);
   h_errors_copy__3->GetZaxis()->SetLabelSize(0.035);
   h_errors_copy__3->GetZaxis()->SetTitleSize(0.035);
   h_errors_copy__3->GetZaxis()->SetTitleFont(42);
   h_errors_copy__3->Draw("sameaxis");
   
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
