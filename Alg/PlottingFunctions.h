#ifndef _PlottingFunctions_h_
#define _PlottingFunctions_h_

#include "TH1D.h"
#include "Misc.h"
#include "TText.h"
#include "TLatex.h"
#include "FluxWeight2.h"

using std::string;
using std::vector;

const bool DrawWatermark = true;
const double _EPSILON_ = 1e-5;

namespace HypPlot {

   // Single panel axis settings etc.

   const double Single_CanvasX = 800;
   const double Single_CanvasY = 600; 
   const double Single_PadSplit = 0.85; // Height at which to split the cavas into plot/legend

   const double Single_XaxisTitleSize = 0.05;
   const double Single_YaxisTitleSize = 0.05;
   const double Single_XaxisTitleOffset = 0.93;
   const double Single_YaxisTitleOffset = 1.06;
   const double Single_XaxisLabelSize = 0.045;
   const double Single_YaxisLabelSize = 0.045;

   const double Single_TextLabelSize = 0.02; // Label size if bin labels are used

   // Two panel axis settings etc.

   const double Dual_CanvasX = 800;
   const double Dual_CanvasY = 750; 
   const double Dual_PadSplitLow = 0.3; // Height at which to split the canvas between the ratio and the main plot
   const double Dual_PadSplitHigh = 0.9; // Height at which to split the canvas between the main plot and the legend

   const double Dual_MainXaxisTitleSize = 0;
   const double Dual_MainYaxisTitleSize = 0.065;
   const double Dual_MainXaxisTitleOffset = 0;
   const double Dual_MainYaxisTitleOffset = 0.8;
   const double Dual_MainXaxisLabelSize = 0;
   const double Dual_MainYaxisLabelSize = 0.05;

   const double Dual_RatioXaxisTitleSize = 0.12;
   const double Dual_RatioYaxisTitleSize = 0.12;
   const double Dual_RatioXaxisTitleOffset = 0.8;
   const double Dual_RatioYaxisTitleOffset = 0.43;
   const double Dual_RatioXaxisLabelSize = 0.1;
   const double Dual_RatioYaxisLabelSize = 0.1;

   const double Dual_TextLabelSize = 0.02; // Label size if bin labels are used
   
   // Matrix axis settings etc.

   const double Matrix_CanvasX = 800;
   const double Matrix_CanvasY = 600; 

   const double Matrix_XaxisTitleSize = 0.05;
   const double Matrix_YaxisTitleSize = 0.05;
   const double Matrix_XaxisTitleOffset = 0.93;
   const double Matrix_YaxisTitleOffset = 1.06;
   const double Matrix_XaxisLabelSize = 0.045;
   const double Matrix_YaxisLabelSize = 0.045;
   const double Matrix_ZaxisLabelSize = 0.045;

   const double Matrix_TextLabelSize = 0.07;

///////////////////////////////////////////////////////////////////////////////////////////////

// Take set of histograms to be stacked together and compute the total stat error
// h_Cov = 2D histogram storing the covariance matrix, systematic errors only

TH1D * MakeErrorBand(std::map<string,TH1D*> hists,TH2D* h_Cov=nullptr){

   TH1D *h_first = hists.begin()->second;
   TH1D *h_errors = new TH1D("h_errors","",h_first->GetNbinsX(),h_first->GetBinLowEdge(1),h_first->GetBinLowEdge(h_first->GetNbinsX()+1));

   // Iterate over the bins of the contributing histograms
   for(int i_b=0;i_b<h_first->GetNbinsX()+1;i_b++){

      std::map<string, TH1D*>::iterator it;

      double events = 0.0;
      double variance = 0.0;

      for (it = hists.begin(); it != hists.end(); it++)
      {
         if(it->first == "Data" || it->first == "All") continue;
         events += it->second->GetBinContent(i_b);
         variance += it->second->GetBinError(i_b)*it->second->GetBinError(i_b);
      }

      if(h_Cov != nullptr) variance += h_Cov->GetBinContent(i_b,i_b);

      h_errors->SetBinContent(i_b,events);
      h_errors->SetBinError(i_b,sqrt(variance));
   }

   return h_errors;
}

///////////////////////////////////////////////////////////////////////////////////////////////

// Get the maximum of a histogram including error bars

double GetHistMaxError(TH1D *h){

   double max = -1e10;

   for(int i_b=1;i_b<h->GetNbinsX()+1;i_b++)
      if(h->GetBinContent(i_b)+h->GetBinError(i_b) > max)
         max = h->GetBinContent(i_b)+h->GetBinError(i_b);

   return max;
}

///////////////////////////////////////////////////////////////////////////////////////////////

// Get the maximum of a histogram not including the errors

double GetHistMax(TH1D *h){

   double max = -1e10;

   for(int i_b=1;i_b<h->GetNbinsX()+1;i_b++)
      if(h->GetBinContent(i_b) > max)
         max = h->GetBinContent(i_b);

   return max;
}

///////////////////////////////////////////////////////////////////////////////////////////////

// Make a 2D histogram from a TMatrix object
// Uses h_example for the bin widths, axis titles etc.

TH2D* MakeHistogram(TMatrixD Mat,TH2D* h_example,string Name=""){

   TH2D* h_Mat = (TH2D*)h_example->Clone(("h_" + Name).c_str());
   const int nbins = h_Mat->GetNbinsX();

   for(int i=1;i<nbins+1;i++)
      for(int j=1;j<nbins+1;j++)
         h_Mat->SetBinContent(i,j,Mat[i-1][j-1]);

   return h_Mat; 
}
///////////////////////////////////////////////////////////////////////////////////////////////

// Draw a 2D matrix as a histogram
// Uses h_example for the bin widths, axis titles etc.
// Can import bin labels from h_example and write bin content on bins if corresponding bools
// are set.

void DrawMatrix(TMatrixD Mat,TH2D* h_example,string title,bool uselabels=false,bool usetext=false){

   TH2D* h = MakeHistogram(Mat,h_example);
   h->SetContour(1000);
   h->GetXaxis()->SetTitleSize(Matrix_XaxisTitleSize);
   h->GetYaxis()->SetTitleSize(Matrix_YaxisTitleSize);
   h->GetXaxis()->SetTitleOffset(Matrix_XaxisTitleOffset);
   h->GetYaxis()->SetTitleOffset(Matrix_YaxisTitleOffset);
   h->GetXaxis()->SetLabelSize(Matrix_XaxisLabelSize);
   h->GetYaxis()->SetLabelSize(Matrix_YaxisLabelSize);
   h->GetZaxis()->SetLabelSize(Matrix_ZaxisLabelSize);

   TCanvas *c = new TCanvas("c","c",Matrix_CanvasX,Matrix_CanvasY);
   c->SetRightMargin(0.13);

   if(uselabels){
      c->SetLeftMargin(0.15);
      h->GetXaxis()->SetLabelSize(Matrix_TextLabelSize);
      h->GetYaxis()->SetLabelSize(Matrix_TextLabelSize);
   }

   TLegend *l_Watermark = new TLegend(0.45,0.91,0.915,0.99);
   l_Watermark->SetBorderSize(0);
   l_Watermark->SetMargin(0.001);
   l_Watermark->SetTextAlign(32);
   l_Watermark->SetTextFont(62);
   l_Watermark->SetTextSize(0.05);
   l_Watermark->SetHeader("MicroBooNE Simulation, Preliminary","R");

   // Generates text with bin content, uses 3 sf
   if(usetext){
      const int sf = 3;
      c->SetRightMargin(0.05);
      h->Draw("col");
      h->SetMarkerSize(3);
      for(int i=1;i<h->GetNbinsX()+1;i++){
         for(int j=1;j<h->GetNbinsX()+1;j++){
            double content = setsf(h->GetBinContent(i,j),sf); 
            string text = std::to_string(content);        
            if(abs(content) < 1e-4 || abs(content) > 1e4){
               int OM = floor(log10(abs(content)));               
               text = to_string_with_precision(content*pow(10,-OM),2) + " #times 10^{" + OM + "}";
            }
            if(abs(content) < 1e-10) text = std::to_string(0);
            auto t = new TLatex(h->GetXaxis()->GetBinCenter(i),h->GetYaxis()->GetBinCenter(j),text.c_str());
            t->SetTextAlign(22);
            t->Draw();
            t->SetTextSize(0.04);
         }
      }
   }
   else h->Draw("colz");

   h->SetStats(0);
   if(DrawWatermark) l_Watermark->Draw();

   c->Print((title + ".png").c_str());
   c->Print((title + ".pdf").c_str());
   c->Print((title + ".C").c_str());
   c->Close();

   delete h;
}

///////////////////////////////////////////////////////////////////////////////////////////////

// Draw a stack of histograms
// If you anto to include systematic uncertainties in the MC, make sure they're already included
// in the error of h_errors
// Inputs:
// hist_v = the stack of histograms you want to draw (including data if applicable)
// h_errors = the total MC prediction with uncertainties
// captions = list of what should be added to the legend for each histogram
// plotdir = the directory to write the plots into
// label = label to be added the front of the plot
// mode = FHC/RHC/BNB
// run = 1,3 or 13 (for 1+3)
// POT = the POT used 
// signalscale = scaling for the signal
// hasdata = flag indicating if there is data in the stack of histograms
// colors = list of colors for the histograms
// binlabels = bin labels
// chi2ndof = chi2 and degrees of freedom if applicable

void DrawHistogram(vector<TH1D*> hist_v,TH1D* h_errors,vector<string> captions,string plotdir,string label,vector<int> mode,vector<int> run,vector<double> POT,double signalscale,bool hasdata,vector<int> colors,vector<string> binlabels,std::pair<double,int> chi2ndof){

   assert(mode.size() == run.size() && run.size() == POT.size() && mode.size() < 3);   
   for(size_t i_r=0;i_r<run.size();i_r++) assert(mode.at(i_r) == kFHC || mode.at(i_r) == kRHC || mode.at(i_r) == kBNB);

   // Set the bin labels
   if(binlabels.size()){
      const int nbins = hist_v.at(0)->GetNbinsX();
      for(int i=1;i<nbins+1;i++){

         for(size_t i_h=0;i_h<hist_v.size();i_h++)
            hist_v.at(i_h)->GetXaxis()->SetBinLabel(i,binlabels.at(i-1).c_str());

         h_errors->GetXaxis()->SetBinLabel(i,binlabels.at(i-1).c_str());
      }
   }

   // Setup the canvas
   TCanvas *c = new TCanvas("c","c",Single_CanvasX,Single_CanvasY);
   TPad *p_plot = new TPad("p_plot","p_plot",0,0,1,Single_PadSplit);
   TPad *p_legend = new TPad("p_legend","p_legend",0,Single_PadSplit,1,1);
   p_legend->SetBottomMargin(0);
   p_legend->SetTopMargin(0.1);
   p_plot->SetTopMargin(0.01);

   THStack *hs = new THStack("hs",hist_v.at(0)->GetTitle());

   // Create the empty legend
   TLegend *l = new TLegend(0.1,0.0,0.9,1.0);
   l->SetBorderSize(0);
   const int nhists = hist_v.size();
   int ncols = 3;
   if(nhists > 6) ncols = 4;
   if(nhists > 12) ncols = 5;
   l->SetNColumns(ncols);
   
   int i_data=-1;
   for(size_t i_h=0;i_h<hist_v.size();i_h++){
      if(captions.at(i_h) == "Data"){
         i_data = i_h;
         continue;
      }
      hist_v.at(i_h)->SetFillColor(colors.at(i_h));
      hs->Add(hist_v.at(i_h),"HIST");
      if(hasdata) l->AddEntry(hist_v.at(i_h),(captions.at(i_h) + " = " + to_string_with_precision(hist_v.at(i_h)->Integral(),1)).c_str(),"F");
      else l->AddEntry(hist_v.at(i_h),captions.at(i_h).c_str(),"F");
   }

   if(hasdata && i_data == -1) throw std::invalid_argument("PlottingFunctions::DrawHistogram: Trying to draw a histogram with data when no data was passed");

   if(hasdata){
      hist_v.at(i_data)->SetLineWidth(1);
      hist_v.at(i_data)->SetLineColor(1);
      hist_v.at(i_data)->SetMarkerStyle(20);
      hist_v.at(i_data)->SetMarkerColor(1);
      l->AddEntry(hist_v.at(i_data),("Data = "+ to_string_with_precision(hist_v.at(i_data)->Integral(),1)).c_str(),"P");
   }

   // Create the "MicroBooNE" watermark
   TLegend *l_Watermark = new TLegend(0.45,0.900,0.89,0.985);
   l_Watermark->SetBorderSize(0);
   l_Watermark->SetMargin(0.005);
   l_Watermark->SetTextAlign(32);
   l_Watermark->SetTextSize(0.05);
   l_Watermark->SetTextFont(62);
   if(!hasdata) l_Watermark->SetHeader("MicroBooNE Simulation, Preliminary","R");
   else if(run.size() == 1) l_Watermark->SetHeader(("MicroBooNE Run " + std::to_string(run.at(0)) + ", Preliminary").c_str());
   else if(run.size() == 2) l_Watermark->SetHeader(("MicroBooNE Runs " + std::to_string(run.at(0)) + " + " + std::to_string(run.at(1)) + ", Preliminary").c_str());
   else throw std::invalid_argument("PlottingFunctions::DrawHistogram: Currently maximum of two running periods supported");

   // Create the POT label
   TLegend *l_POT = new TLegend(0.54,0.820,0.89,0.900);
   l_POT->SetBorderSize(0);
   l_POT->SetMargin(0.005);
   l_POT->SetTextAlign(32);
   TLegend *l_POT2 = new TLegend(0.54,0.74,0.89,0.82,NULL,"brNDC");
   l_POT2->SetBorderSize(0);
   l_POT2->SetMargin(0.005);
   l_POT2->SetTextAlign(32);

   // Chi2
   TLegend *l_Chi2 = new TLegend(0.12,0.900,0.36,0.985);
   l_Chi2->SetBorderSize(0);
   l_Chi2->SetMargin(0.005);
   l_Chi2->SetTextAlign(12);
   l_Chi2->SetTextSize(0.05);
   l_Chi2->SetHeader(("#chi^{2}/ndof = " + to_string_with_precision(chi2ndof.first,1) + "/" + std::to_string(chi2ndof.second)).c_str());

   if(mode.at(0) == kFHC) l_POT->SetHeader(("NuMI FHC, " + to_string_with_precision(POT.at(0)/1e20,1) + " #times 10^{20} POT").c_str());
   else if(mode.at(0) == kRHC) l_POT->SetHeader(("NuMI RHC, " + to_string_with_precision(POT.at(0)/1e20,1) + " #times 10^{20} POT").c_str());
   else if(mode.at(0) == kBNB) l_POT->SetHeader(("BNB, " + to_string_with_precision(POT.at(0)/1e20,1) + " #times 10^{20} POT").c_str());

   if(mode.size() == 2 && mode.at(1) == kFHC) l_POT2->SetHeader(("NuMI FHC, " + to_string_with_precision(POT.at(1)/1e20,1) + " #times 10^{20} POT").c_str());
   else if(mode.size() == 2 && mode.at(1) == kRHC) l_POT2->SetHeader(("NuMI RHC, " + to_string_with_precision(POT.at(1)/1e20,1) + " #times 10^{20} POT").c_str());
   else if(mode.size() == 2 && mode.at(0) == kBNB && mode.at(1) == kBNB) l_POT->SetHeader(("BNB, " + to_string_with_precision(POT.at(0) + POT.at(1)/1e20,1) + " #times 10^{20} POT").c_str());

   // Setup the axis titles etc
   h_errors->SetTitle(hs->GetTitle());
   h_errors->SetFillStyle(3253);
   h_errors->SetFillColor(1);
   h_errors->GetXaxis()->SetTitleSize(Single_XaxisTitleSize);
   h_errors->GetYaxis()->SetTitleSize(Single_YaxisTitleSize);
   h_errors->GetXaxis()->SetTitleOffset(Single_XaxisTitleOffset);
   h_errors->GetYaxis()->SetTitleOffset(Single_YaxisTitleOffset);
   h_errors->GetXaxis()->SetLabelSize(Single_XaxisLabelSize);
   h_errors->GetYaxis()->SetLabelSize(Single_YaxisLabelSize);
   if(binlabels.size()) h_errors->GetXaxis()->SetLabelSize(Single_TextLabelSize);

   // Draw everything
   p_legend->Draw();
   p_legend->cd();
   l->Draw();
   c->cd();
   p_plot->Draw();
   p_plot->cd();

   h_errors->Draw("E2");
   hs->Draw("HIST same");
   h_errors->Draw("E2 same");
   if(hasdata) hist_v.at(i_data)->Draw("E0 P0 same");
   h_errors->GetYaxis()->SetRangeUser(0.0,GetHistMaxError(h_errors)*1.25);
   h_errors->SetStats(0);

   p_plot->RedrawAxis();

   // Draw the various legends, labels etc.
   if(POT.size() > 0) l_POT->Draw();
   if(POT.size() == 2 && mode.at(0) == kFHC && mode.at(1) == kRHC) l_POT2->Draw();
   if(DrawWatermark) l_Watermark->Draw();
   if(hasdata) l_Chi2->Draw();

   c->cd();
   system(("mkdir -p " + plotdir).c_str());
   c->Print((plotdir + "/" + label + ".png").c_str());
   c->Print((plotdir + "/" + label + ".pdf").c_str());
   c->Print((plotdir + "/" + label + ".C").c_str());
   c->Clear();
   c->Close();

   // Draw the ratio and get chi2 if there is data
   if(hasdata){

      // Setup split canvas
      TCanvas *c2 = new TCanvas("c2","c2",Dual_CanvasX,Dual_CanvasY);
      TPad *p_ratio2 = new TPad("p_ratio2","p_ratio2",0,0.0,1,Dual_PadSplitLow);
      TPad *p_plot2 = new TPad("p_plot2","p_plot2",0,Dual_PadSplitLow,1,Dual_PadSplitHigh);
      TPad *p_legend2 = new TPad("p_legend2","p_plot2",0,Dual_PadSplitHigh,1,1);
      p_legend2->SetBottomMargin(0);
      p_legend2->SetTopMargin(0.1);
      p_ratio2->SetTopMargin(0.005);
      p_plot2->SetTopMargin(0.01);
      p_plot2->SetBottomMargin(0.02);
      p_ratio2->SetGrid(0,1);
      p_ratio2->SetBottomMargin(0.22);
      p_legend2->Draw();
      p_legend2->cd();
      l->Draw();
      c2->cd();
      p_plot2->Draw();
      p_plot2->cd();

      h_errors->GetXaxis()->SetLabelSize(Dual_MainXaxisLabelSize);
      h_errors->GetYaxis()->SetLabelSize(Dual_MainYaxisLabelSize);
      h_errors->GetXaxis()->SetTitleSize(Dual_MainXaxisTitleSize);
      h_errors->GetYaxis()->SetTitleSize(Dual_MainYaxisTitleSize);
      h_errors->GetYaxis()->SetTitleOffset(Dual_MainYaxisTitleOffset);

      // Draw the main plot
      h_errors->Draw("E2");
      hs->Draw("HIST same");    
      h_errors->Draw("E2 same");
      hist_v.at(i_data)->Draw("e0 same");

      // Draw the various legends, labels etc.
      if(POT.size() > 0) l_POT->Draw();
      if(POT.size() == 2 && mode.at(0) == kFHC && mode.at(1) == kRHC) l_POT2->Draw();
      if(DrawWatermark) l_Watermark->Draw();
      l_Chi2->Draw();

      // Make the raio plot
      TH1D *h_errors_ratio = (TH1D*)h_errors->Clone("h_errors_ratio");
      TH1D* h_data_ratio = (TH1D*)hist_v.at(i_data)->Clone("h_data_ratio");

      std::pair<double,double> minmax = {1.0,1.0};

      for(int i=1;i<h_errors_ratio->GetNbinsX()+1;i++){

         double pred = h_errors->GetBinContent(i);
         double mc_error = h_errors->GetBinError(i)/pred;
         double data_ratio = hist_v.at(i_data)->GetBinContent(i)/pred;
         double data_ratio_error = hist_v.at(i_data)->GetBinError(i)/pred;

         h_errors_ratio->SetBinContent(i,1.0);

         if(pred > 0){
            h_errors_ratio->SetBinError(i,mc_error);            
            h_data_ratio->SetBinContent(i,data_ratio);
            h_data_ratio->SetBinError(i,data_ratio_error);            
            minmax.first = std::min(minmax.first,std::min(1-mc_error,data_ratio-data_ratio_error));
            minmax.second = std::max(minmax.second,std::max(1+mc_error,data_ratio+data_ratio_error));                          
         }
         else{
            h_errors_ratio->SetBinError(i,0.0); 
            h_data_ratio->SetBinContent(i,1.0); 
            h_data_ratio->SetBinError(i,0.0); 
         }
      }
      
      // Draw the ratio plot
      c2->cd();
      p_ratio2->Draw();
      p_ratio2->cd();
      h_errors_ratio->Draw("E2");
      h_errors_ratio->GetYaxis()->SetRangeUser(0.95*minmax.first,1.05*minmax.second);

      h_errors_ratio->SetStats(0);
      h_errors_ratio->GetXaxis()->SetTitle(hist_v.at(0)->GetXaxis()->GetTitle());
      h_errors_ratio->GetYaxis()->SetTitle("Data/MC");

      h_errors_ratio->GetXaxis()->SetTitleSize(Dual_RatioXaxisTitleSize);
      h_errors_ratio->GetYaxis()->SetTitleSize(Dual_RatioYaxisTitleSize);
      h_errors_ratio->GetXaxis()->SetTitleOffset(Dual_RatioXaxisTitleOffset);
      h_errors_ratio->GetYaxis()->SetTitleOffset(Dual_RatioYaxisTitleOffset);
      h_errors_ratio->GetXaxis()->SetLabelSize(Dual_RatioXaxisLabelSize);
      h_errors_ratio->GetYaxis()->SetLabelSize(Dual_RatioYaxisLabelSize);

      h_data_ratio->Draw("E0 same");
      p_plot2->RedrawAxis();

      c2->Print((plotdir + "/" + label + "_Ratio.pdf").c_str());
      c2->Print((plotdir + "/" + label + "_Ratio.png").c_str());
      c2->Print((plotdir + "/" + label + "_Ratio.C").c_str());
      c2->Close();
   }

   c->Close();
}

///////////////////////////////////////////////////////////////////////////////////////////////

// Draw a stack of histograms
// If you anto to include systematic uncertainties in the MC, make sure they're already included
// in the error of h_errors
// Inputs:
// hist_v = the stack of histograms you want to draw (including data if applicable)
// h_errors = the total MC prediction with uncertainties
// captions = list of what should be added to the legend for each histogram
// plotdir = the directory to write the plots into
// label = label to be added the front of the plot
// mode = FHC/RHC/BNB
// run = 1,3 or 13 (for 1+3)
// POT = the POT used 
// signalscale = scaling for the signal
// binlabels = bin labels

void DrawHistogramSys(vector<TH1D*> hist_v,TH1D* h_cv,string plotdir,string label,string type,string dialname,vector<int> mode,vector<int> run,vector<double> POT,vector<string> binlabels){

   assert(mode.size() == run.size() && run.size() == POT.size() && mode.size() < 3);   
   for(size_t i_r=0;i_r<run.size();i_r++) assert(mode.at(i_r) == kFHC || mode.at(i_r) == kRHC || mode.at(i_r) == kBNB);

   // Set the bin labels
   if(binlabels.size())
      for(size_t i_u=0;i_u<hist_v.size();i_u++)
         for(int i=1;i<h_cv->GetNbinsX()+1;i++) hist_v.at(i_u)->GetXaxis()->SetBinLabel(i,binlabels.at(i-1).c_str());

   // Setup the canvas and pads
   TCanvas *c = new TCanvas("c","c",Single_CanvasX,Single_CanvasY);
   TPad *p_plot = new TPad("pad1","pad1",0,0,1,Single_PadSplit);
   TPad *p_legend = new TPad("pad2","pad2",0,Single_PadSplit,1,1);
   p_legend->SetBottomMargin(0);
   p_legend->SetTopMargin(0.1);
   p_plot->SetTopMargin(0.01);

   std::string title = ";" + string(h_cv->GetXaxis()->GetTitle()) + ";" + string(h_cv->GetYaxis()->GetTitle());
   THStack *hs = new THStack("hs",title.c_str());

   // Setup the legend
   TLegend *l = new TLegend(0.1,0.0,0.9,1.0);
   l->SetBorderSize(0);
   l->SetNColumns(2);
   l->AddEntry(h_cv,"Central Value","L");

   // Prepare the histograms and add the right information to the legend
   double maximum = 0.0;
   for(size_t i=0;i<hist_v.size();i++){
      if(hist_v.size() > 2){
         hist_v.at(i)->SetLineColor(kGreen);
         if(i == 0) l->AddEntry(hist_v.at(0),"Variations","L");
      }
      else if(hist_v.size() == 1){
         hist_v.at(i)->SetLineColor(kRed);
         l->AddEntry(hist_v.at(0),"Alternative Model","L");
      }
      else if(hist_v.size() == 2 && i == 0){
         hist_v.at(i)->SetLineColor(kRed);
         l->AddEntry(hist_v.at(i),"+ 1 #sigma","L");
      }
      else if(hist_v.size() == 2 && i == 1){
         hist_v.at(i)->SetLineColor(kBlue); 
         l->AddEntry(hist_v.at(i),"- 1 #sigma","L");
      }
      hs->Add(hist_v.at(i));
      if(GetHistMax(hist_v.at(i)) > maximum) maximum = GetHistMax(hist_v.at(i));
   }

   // Prepare the CV histogram
   if(GetHistMax(h_cv) > maximum) maximum = GetHistMax(h_cv);
   h_cv->SetLineColor(1);
   h_cv->SetLineWidth(2);
   h_cv->SetFillColor(0);
   h_cv->SetMaximum(maximum*1.25);
   hs->Add(h_cv);

   // Create the "MicroBooNE" watermark
   TLegend *l_Watermark = new TLegend(0.45,0.900,0.89,0.985);
   l_Watermark->SetBorderSize(0);
   l_Watermark->SetMargin(0.005);
   l_Watermark->SetTextAlign(32);
   l_Watermark->SetTextSize(0.05);
   l_Watermark->SetTextFont(62);
   l_Watermark->SetHeader("MicroBooNE Simulation, Preliminary","R");

   // Create the POT label
   TLegend *l_POT = new TLegend(0.54,0.820,0.89,0.900);
   l_POT->SetBorderSize(0);
   l_POT->SetMargin(0.005);
   l_POT->SetTextAlign(32);
   TLegend *l_POT2 = new TLegend(0.54,0.74,0.89,0.82,NULL,"brNDC");
   l_POT2->SetBorderSize(0);
   l_POT2->SetMargin(0.005);
   l_POT2->SetTextAlign(32);

   p_legend->Draw();
   p_legend->cd();
   l->Draw();
   c->cd();
   p_plot->Draw();
   p_plot->cd();

   hs->Draw("HIST nostack");
   hs->GetXaxis()->SetTitleSize(Single_XaxisTitleSize);
   hs->GetYaxis()->SetTitleSize(Single_YaxisTitleSize);
   hs->GetXaxis()->SetTitleOffset(Single_XaxisTitleOffset);
   hs->GetYaxis()->SetTitleOffset(Single_YaxisTitleOffset);
   hs->GetXaxis()->SetLabelSize(Single_XaxisLabelSize);
   hs->GetYaxis()->SetLabelSize(Single_YaxisLabelSize);

   h_cv->Draw("HIST same");

   // Draw the various legends, labels etc.
   if(POT.size() > 0) l_POT->Draw();
   if(POT.size() == 2 && mode.at(0) == kFHC && mode.at(1) == kRHC) l_POT2->Draw();
   if(DrawWatermark) l_Watermark->Draw();

   // If using text labels on the bins
   if(binlabels.size()){
      for(int i=1;i<h_cv->GetNbinsX()+1;i++) hs->GetXaxis()->SetBinLabel(i,binlabels.at(i-1).c_str());
      hs->GetXaxis()->SetLabelSize(Single_TextLabelSize);
   }

   p_plot->Update(); 

   system(("mkdir -p " + plotdir).c_str());
   c->Print((plotdir + "/" + label + "_Sys_" + type + "_" +  dialname + ".png").c_str());
   c->Print((plotdir + "/" + label + "_Sys_" + type + "_" +  dialname + ".pdf").c_str());
   c->Print((plotdir + "/" + label + "_Sys_" + type + "_" +  dialname + ".C").c_str());
   c->Close();

}

///////////////////////////////////////////////////////////////////////////////////////////////

};

#endif
