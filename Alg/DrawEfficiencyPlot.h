#ifndef _DrawEfficiencyPlot_h_
#define _DrawEfficiencyPlot_h_

#include "TEfficiency.h"
#include "TH1D.h"
#include "TCanvas.h"
#include <vector>

#include <sstream>

void DrawEfficiencyPlot(TH1D *h_Before,TH1D *h_After,TEfficiency * Efficiency,std::string title,std::string name){

   TCanvas *c1 = new TCanvas("c1","c1",800,600);

   TPad *p_plot = new TPad("pad1","pad1",0,0,1,0.85);
   TPad *p_legend = new TPad("pad2","pad2",0,0.85,1,1);

   p_legend->SetBottomMargin(0);
   p_legend->SetTopMargin(0.1);
   p_plot->SetTopMargin(0.01);

   TLegend *l = new TLegend(0.1,0.0,0.9,1.0);
   l->SetBorderSize(0);
   l->SetNColumns(2);


   THStack *hs = new THStack("hs",title.c_str());

   h_Before->SetLineWidth(2);
   h_Before->SetLineColor(1);
   hs->Add(h_Before);

   h_After->SetLineWidth(2);
   h_After->SetLineColor(3);
   hs->Add(h_After);

   p_legend->Draw();
   c1->cd();
   p_plot->Draw();
   p_plot->cd();

   hs->Draw("nostack E0");

   c1->Print(("Plots/" + name + ".pdf").c_str());
   c1->Print(("Plots/" + name + ".png").c_str());

   p_plot->cd();

   Efficiency->SetConfidenceLevel(0.68);
   Efficiency->SetStatisticOption(TEfficiency::kFCP);


   // Find the highest bin of the   
   std::vector<double> Efficiency_X;
   std::vector<double> Efficiency_CV;
   std::vector<double> Efficiency_Low;
   std::vector<double> Efficiency_High;


   // scale
   int binmax = h_Before->GetMaximumBin();

   Float_t rightmax = 1.15;
   double scale = p_plot->GetUymax()/rightmax;

   for(size_t i=1;i<h_Before->GetNbinsX()+1;i++){

      Efficiency_X.push_back(h_Before->GetBinCenter(i));
      Efficiency_CV.push_back(Efficiency->GetEfficiency(i)*scale);
      Efficiency_Low.push_back(Efficiency->GetEfficiencyErrorLow(i)*scale);
      Efficiency_High.push_back(Efficiency->GetEfficiencyErrorUp(i)*scale);

      //    std::cout << h_Before->GetBinCenter(i) << "  " << Efficiency->GetEfficiency(i) << "  " << Efficiency->GetEfficiencyErrorLow(i) << "  " << Efficiency->GetEfficiencyErrorUp(i) << std::endl;

   }

   TGraphAsymmErrors *g_Efficiency = new  TGraphAsymmErrors(Efficiency_X.size(),&(Efficiency_X[0]),&(Efficiency_CV[0]),0,0,&(Efficiency_Low[0]),&(Efficiency_High[0]));

   g_Efficiency->SetLineWidth(1);
   g_Efficiency->SetLineColor(kRed);
   g_Efficiency->SetMarkerStyle(5);
   g_Efficiency->SetMarkerColor(kRed);

   TGaxis *axis = new TGaxis(p_plot->GetUxmax(),p_plot->GetUymin(),
         p_plot->GetUxmax(), p_plot->GetUymax(),0,rightmax,510,"+L");



//   axis->SetLineColor(kRed);
   axis->SetTitleColor(kRed);
   axis->SetLabelColor(kRed);
  axis->SetLabelSize(0.035);
  axis->SetTitleSize(0.035);
  axis->SetTitleFont(42);
  axis->SetLabelFont(42);

  axis->SetTitle("Selected/All");
  axis->Draw();

   l->AddEntry(h_Before,"All Events","L");
   l->AddEntry(g_Efficiency,"Selected/All","P");
   l->AddEntry(h_After,"Selected","L");

   g_Efficiency->Draw("P same");

   // Setup the legend
   c1->cd();
   p_legend->cd();
   l->Draw();

   c1->cd();
   p_plot->cd();

   c1->Print(("Plots/" + name + "_Ratio.pdf").c_str());
   c1->Print(("Plots/" + name + "_Ratio.png").c_str());

}


#endif
