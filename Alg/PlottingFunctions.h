#ifndef _PlottingFunctions_h_
#define _PlottingFunctions_h_

#include "TH1D.h"
#include "Misc.h"
#include "TText.h"
#include "TLatex.h"
#include "FluxWeight.h"

const double _EPSILON_ = 1e-5;

///////////////////////////////////////////////////////////////////////////////////////////////

TH1D * MakeErrorBand(std::map<std::string,TH1D*> hists){

   TH1D *h_first = hists.begin()->second;
   TH1D *h_errors = new TH1D("h_errors","",h_first->GetNbinsX(),h_first->GetBinLowEdge(1),h_first->GetBinLowEdge(h_first->GetNbinsX()+1));

   // iterate over the bins of the contributing histograms
   for(int i_b=0;i_b<h_first->GetNbinsX()+1;i_b++){

      std::map<std::string, TH1D*>::iterator it;

      double events = 0.0;
      double variance = 0.0;

      for (it = hists.begin(); it != hists.end(); it++)
      {
         if(it->first == "Data" || it->first == "All") continue;
         events += it->second->GetBinContent(i_b);
         variance += it->second->GetBinError(i_b)*it->second->GetBinError(i_b);
      }

      h_errors->SetBinContent(i_b,events);
      h_errors->SetBinError(i_b,sqrt(variance));

   }

   return h_errors;

}

///////////////////////////////////////////////////////////////////////////////////////////////

TH1D * MakeRatioPlot(std::map<std::string,TH1D*> hists,TH1D* h_MCError){

   //std::cout << "Setting histogram errors" << std::endl;

   TH1D *h_first = hists.begin()->second;

   //std::cout << "Setting up error hist with params: " << "bins=" << h_first->GetNbinsX() << "  low edge=" << h_first->GetBinLowEdge(1) << "  high edge=" << h_first->GetBinLowEdge(h_first->GetNbinsX()+1) << std::endl;

   std::string x_axis_title = h_first->GetXaxis()->GetTitle();

   TH1D *h_Ratio = new TH1D("h_Ratio",";;Data/MC",h_first->GetNbinsX(),h_first->GetBinLowEdge(1),h_first->GetBinLowEdge(h_first->GetNbinsX()+1));

   // iterate over the bins of the contributing histograms
   for(int i_b=1;i_b<h_first->GetNbinsX()+1;i_b++){

      double mc_events = hists["Signal"]->GetBinContent(i_b)
         + hists["OtherHYP"]->GetBinContent(i_b)
         + hists["OtherNu"]->GetBinContent(i_b)
         + hists["Dirt"]->GetBinContent(i_b)
         + hists["EXT"]->GetBinContent(i_b);


      double mc_variance = h_MCError->GetBinError(i_b)*h_MCError->GetBinError(i_b);

      double data_events = hists["Data"]->GetBinContent(i_b);
      double data_variance = hists["Data"]->GetBinError(i_b)*hists["Data"]->GetBinError(i_b);

      double ratio = data_events/mc_events;
      double ratio_variance = ratio*ratio*(data_variance/data_events/data_events + mc_variance/mc_events/mc_events);


      if(data_events < _EPSILON_ || mc_events < _EPSILON_){ ratio = 1.0; ratio_variance = 0.0; }


      //      std::cout << "Looing at bin " << i_b << "  events = "  << mc_events << " sigma = " << sqrt(mc_variance) << " Data = " << data_events << " sigma = " << sqrt(data_variance) <<  " data/mc = " << ratio <<  " sigma = " << sqrt(ratio_variance) << std::endl;

      h_Ratio->SetBinContent(i_b,ratio);
      h_Ratio->SetBinError(i_b,sqrt(ratio_variance));

   }

   return h_Ratio;

}

///////////////////////////////////////////////////////////////////////////////////////////////

double GetHistMaxError(TH1D *h){

   double max = -1e10;

   for(int i_b=1;i_b<h->GetNbinsX()+1;i_b++){
      if(h->GetBinContent(i_b)+h->GetBinError(i_b) > max){
         max = h->GetBinContent(i_b)+h->GetBinError(i_b);
      }
   }
   return max;
}

///////////////////////////////////////////////////////////////////////////////////////////////

double GetHistMax(TH1D *h){

   double max = -1e10;

   for(int i_b=1;i_b<h->GetNbinsX()+1;i_b++){
      if(h->GetBinContent(i_b) > max){
         max = h->GetBinContent(i_b);
         //std::cout << "BinContent=" << h->GetBinContent(i_b) << "  max=" << max << std::endl;
      }
   }

   return max;
}

///////////////////////////////////////////////////////////////////////////////////////////////

TH2D* MakeHistogram(TMatrixD Mat,TH2D* h_example,std::string Name=""){

   TH2D* h_Mat = (TH2D*)h_example->Clone(("h_" + Name).c_str());;
   const int nbins = h_Mat->GetNbinsX();

   for(int i=1;i<nbins+1;i++)
      for(int j=1;j<nbins+1;j++)
         h_Mat->SetBinContent(i,j,Mat[i-1][j-1]);

   return h_Mat; 
}

///////////////////////////////////////////////////////////////////////////////////////////////

void DrawMatrix(TMatrixD Mat,TH2D* h_example,std::string title,bool uselabels=false,bool usetext=false){

   TH2D* h = MakeHistogram(Mat,h_example);

   TCanvas *c = new TCanvas("c","c",800,600);

   c->SetRightMargin(0.13);
   if(uselabels) c->SetLeftMargin(0.15);

   TLegend *l_Watermark = new TLegend(0.45,0.91,0.915,0.99);
   l_Watermark->SetBorderSize(0);
   l_Watermark->SetMargin(0.001);
   l_Watermark->SetTextAlign(32);
   l_Watermark->SetTextFont(62);
   l_Watermark->SetTextSize(0.05);
   //l_Watermark->SetHeader("MicroBooNE Simulation, Preliminary","R");
   l_Watermark->SetHeader("MicroBooNE Simulation, In Progress","R");

   h->SetContour(1000);

   if(usetext){
      c->SetRightMargin(0.05);
      h->SetMarkerSize(3.0);
      h->Draw("col");

      for(int i=1;i<h->GetNbinsX()+1;i++){
         for(int j=1;j<h->GetNbinsX()+1;j++){
            double content = setsf(h->GetBinContent(i,j),3);            
            std::string text = std::to_string(content);        
            if(abs(content) < 1e-4 || abs(content) > 1e4){
               // text = std::to_string(1e5*content) + 
               int OM = floor(log10(abs(content)));               
               text = to_string_with_precision(content*pow(10,-OM),2) + " #times 10^{" + OM + "}";
            }
            if(abs(content) < 1e-10) text = std::to_string(0);
            //auto t = new TText(h->GetXaxis()->GetBinCenter(i),h->GetYaxis()->GetBinCenter(j),text.c_str());
            auto t = new TLatex(h->GetXaxis()->GetBinCenter(i),h->GetYaxis()->GetBinCenter(j),text.c_str());
            t->SetTextAlign(22);
            t->Draw();
         }
      }


      /*
         for(size_t i=1;i<h->GetNbinsX()+1;i++){
         for(size_t j=1;j<h->GetNbinsX()+1;j++){
         if(abs(h->GetBinContent(i,j)) < 1e-10) h->SetBinContent(i,j,0.0); 
         h->SetBinContent(i,j,setsf(h->GetBinContent(i,j),3));
         }
         }
         */
      //gStyle->SetPaintTextFormat("4.1f");
   }
   else h->Draw("colz");

   h->SetStats(0);
   l_Watermark->Draw();

   c->Print((title + ".png").c_str());
   c->Print((title + ".pdf").c_str());
   c->Print((title + ".C").c_str());

   c->Close();
   delete h;

}

///////////////////////////////////////////////////////////////////////////////////////////////

void DrawHistogram(std::vector<TH1D*> hist_v,TH1D* h_errors,std::vector<std::string> captions,std::string plotdir,std::string label,int mode,int run,double POT,double signalscale,bool hasdata,std::vector<int> colors,std::vector<std::string> binlabels,std::pair<double,int> chi2ndof){

  assert(mode == kFHC || mode == kRHC || mode == kBNB);

   if(binlabels.size()){
      const int nbins = hist_v.at(0)->GetNbinsX();
      for(int i=1;i<nbins+1;i++){
         for(size_t i_h=0;i_h<hist_v.size();i_h++)
            hist_v.at(i_h)->GetXaxis()->SetBinLabel(i,binlabels.at(i-1).c_str());
         h_errors->GetXaxis()->SetBinLabel(i,binlabels.at(i-1).c_str());                
      }
   }

   TCanvas *c = new TCanvas("c","c",800,600);

   TPad *p_plot = new TPad("pad1","pad1",0,0,1,0.85);
   TPad *p_legend = new TPad("pad2","pad2",0,0.85,1,1);

   p_legend->SetBottomMargin(0);
   p_legend->SetTopMargin(0.1);
   p_plot->SetTopMargin(0.01);

   THStack *hs = new THStack("hs",hist_v.at(0)->GetTitle());

   TLegend *l = new TLegend(0.1,0.0,0.9,1.0);
   l->SetBorderSize(0);

   TLegend *l_Watermark = new TLegend(0.45,0.900,0.89,0.985);
   l_Watermark->SetBorderSize(0);
   l_Watermark->SetMargin(0.005);
   l_Watermark->SetTextAlign(32);
   l_Watermark->SetTextSize(0.05);
   l_Watermark->SetTextFont(62);

   //l_Watermark->SetHeader("MicroBooNE Simulation, Preliminary","R");
   l_Watermark->SetHeader("MicroBooNE Simulation, In Progress","R");

   TLegend *l_POT = new TLegend(0.55,0.820,0.89,0.900);
   l_POT->SetBorderSize(0);
   l_POT->SetMargin(0.005);
   l_POT->SetTextAlign(32);
   l_POT->SetTextSize(0.05);

   if(mode == kFHC)  l_POT->SetHeader(("NuMI FHC, " + to_string_with_precision(POT/1e20,1) + " #times 10^{20} POT").c_str());
   if(mode == kRHC)  l_POT->SetHeader(("NuMI RHC, " + to_string_with_precision(POT/1e20,1) + " #times 10^{20} POT").c_str());
   if(mode == kBNB)  l_POT->SetHeader(("BNB, " + to_string_with_precision(POT/1e20,1) + " #times 10^{20} POT").c_str());

   //if(BeamMode == "FHC")  l_POT->SetHeader(("NuMI FHC, " + to_string_with_precision(fPOT/1e19,1) + " #times 10^{19} POT").c_str());
   //if(BeamMode == "RHC")  l_POT->SetHeader(("NuMI RHC, " + to_string_with_precision(fPOT/1e19,1) + " #times 10^{19} POT").c_str());

   TLegend *l_Scale = new TLegend(0.65,0.745,0.89,0.805);
   l_Scale->SetHeader(("Signal #times " + to_string_with_precision(signalscale,0)).c_str());
   l_Scale->SetBorderSize(0);
   l_Scale->SetMargin(0.005);
   l_Scale->SetTextAlign(32);

   const int nhists = hist_v.size();
   int ncols = 3;
   if(nhists > 6) ncols = 4;
   if(nhists > 12) ncols = 5;

   l->SetNColumns(ncols);

   h_errors->SetTitle(hs->GetTitle());
   h_errors->SetFillStyle(3253);
   h_errors->SetFillColor(1);
   h_errors->GetXaxis()->SetTitleSize(0.05);
   h_errors->GetYaxis()->SetTitleSize(0.05);
   h_errors->GetXaxis()->SetTitleOffset(0.93);
   h_errors->GetYaxis()->SetTitleOffset(1.06);
   h_errors->GetXaxis()->SetLabelSize(0.045);
   h_errors->GetYaxis()->SetLabelSize(0.045);

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

   TLegend *l_DataMCRatio = new TLegend(0.12,0.905,0.46,0.985);
   l_DataMCRatio->SetBorderSize(0);
   l_DataMCRatio->SetMargin(0.005);

   if(hasdata && i_data != -1){
      hist_v.at(i_data)->SetLineWidth(1);
      hist_v.at(i_data)->SetLineColor(1);
      hist_v.at(i_data)->SetMarkerStyle(20);
      hist_v.at(i_data)->SetMarkerColor(1);
      l->AddEntry(hist_v.at(i_data),("Data = "+ to_string_with_precision(hist_v.at(i_data)->Integral(),1)).c_str(),"P");
      l_DataMCRatio->SetHeader(("Data/MC = " + to_string_with_precision(hist_v.at(i_data)->Integral()/h_errors->Integral(),2)).c_str());
   }

   p_legend->Draw();
   p_legend->cd();
   l->Draw();
   c->cd();
   p_plot->Draw();
   p_plot->cd();

   hs->Draw();

   if(binlabels.size()) hs->GetXaxis()->SetLabelSize(0.2);

   h_errors->Draw("E2");
   hs->Draw("HIST same");
   h_errors->Draw("E2 same");
   h_errors->GetYaxis()->SetRangeUser(0.0,GetHistMaxError(h_errors)*1.25);
   h_errors->SetStats(0);

   if(binlabels.size()){
      h_errors->GetXaxis()->SetLabelSize(0.07);
      gPad->Modified();
   }

   if(hasdata && i_data != -1) hist_v.at(i_data)->Draw("E0 P0 same");
   l_POT->Draw();
   l_Watermark->Draw();
   if(signalscale != 1.0) l_Scale->Draw();
   if(hasdata) l_DataMCRatio->Draw();

   c->cd();
   c->Print((plotdir + label + ".png").c_str());
   c->Print((plotdir + label + ".pdf").c_str());
   c->Print((plotdir + label + ".C").c_str());
   c->Clear();
   c->Close();

   // Draw the ratio and get chi2 if there is data
   if(hasdata && i_data != -1){

      std::cout << "Drawing data/MC with ratio" << std::endl;

      TCanvas *c2 = new TCanvas("c2","c2",800,750);

      // Setup split canvas
      TPad *p_plot2 = new TPad("p_plot","p_plot2",0,0.25,1,0.9);
      TPad *p_legend2 = new TPad("p_plot","p_plot2",0,0.9,1,1);
      TPad *p_ratio2 = new TPad("p_ratio","p_ratio",0,0.0,1,0.25);

      p_legend2->SetBottomMargin(0);
      p_legend2->SetTopMargin(0.1);
      p_ratio2->SetTopMargin(0.01);
      p_plot2->SetTopMargin(0.01);
      //p_plot->SetBottomMargin(0.01);

      p_ratio2->SetGrid(0,1);
      p_ratio2->SetBottomMargin(0.12);

      TLegend *l2 = new TLegend(0.1,0.0,0.9,1.0);
      l2->SetBorderSize(0);
      l2->SetNColumns(ncols);

      for(size_t i_h=0;i_h<hist_v.size();i_h++){
         if(captions.at(i_h) == "Data") l2->AddEntry(hist_v.at(i_data),("Data = "+ to_string_with_precision(hist_v.at(i_data)->Integral(),1)).c_str(),"P");
         else {
            if(hasdata) l2->AddEntry(hist_v.at(i_h),(captions.at(i_h) + " = " + to_string_with_precision(hist_v.at(i_h)->Integral(),1)).c_str(),"F");
            else l2->AddEntry(hist_v.at(i_h),captions.at(i_h).c_str(),"F");
         }
      }


      TLegend *l_Watermark2 = new TLegend(0.45,0.900,0.89,0.985);
      l_Watermark2->SetBorderSize(0);
      l_Watermark2->SetMargin(0.005);
      l_Watermark2->SetTextAlign(32);
      l_Watermark2->SetTextFont(62);
      l_Watermark2->SetTextSize(0.05);
      //l_Watermark2->SetHeader("MicroBooNE Run 1 Preliminary","R");
      l_Watermark2->SetHeader(("MicroBooNE Run " + std::to_string(run) + " Preliminary").c_str(),"R");
       

      TLegend *l_POT2 = new TLegend(0.55,0.820,0.89,0.900);
      l_POT2->SetBorderSize(0);
      l_POT2->SetMargin(0.005);
      l_POT2->SetTextAlign(32);
      l_POT2->SetTextSize(0.05);

      if(mode == kFHC)  l_POT2->SetHeader(("NuMI FHC, " + to_string_with_precision(POT/1e20,1) + " #times 10^{20} POT").c_str());
      if(mode == kRHC)  l_POT2->SetHeader(("NuMI RHC, " + to_string_with_precision(POT/1e20,1) + " #times 10^{20} POT").c_str());
      if(mode == kBNB)  l_POT2->SetHeader(("BNB, " + to_string_with_precision(POT/1e20,1) + " #times 10^{20} POT").c_str());


      if(hasdata) h_errors->GetYaxis()->SetRangeUser(0.0,std::max(GetHistMaxError(h_errors),GetHistMaxError(hist_v.at(i_data)))*1.3);
      else if(POT > 0) h_errors->GetYaxis()->SetRangeUser(0.0,GetHistMaxError(h_errors)*1.30);
      else h_errors->GetYaxis()->SetRangeUser(0.0,GetHistMaxError(h_errors)*1.2);

      p_legend2->Draw();
      p_legend2->cd();
      l2->Draw();
      c2->cd();

      p_plot2->Draw();
      p_plot2->cd();

      h_errors->Draw("E2");
      
      if(hasdata) hist_v.at(i_data)->Draw("e0 same");
      hs->Draw("HIST same");    
      h_errors->Draw("E2 same");
      if(hasdata) hist_v.at(i_data)->Draw("e0 same");

      l_Watermark2->Draw();
      if(POT > 0) l_POT2->Draw();
         
      //l_DataMCRatio->Draw();
      
      // Calculate the chi2 score 
      TLegend *l_Chi2 = new TLegend(0.12,0.900,0.36,0.985);
      l_Chi2->SetBorderSize(0);
      l_Chi2->SetMargin(0.005);
      l_Chi2->SetTextAlign(12);
      l_Chi2->SetTextSize(0.05);
      //l_Chi2->SetTextFont(62);

      l_Chi2->SetHeader(("#chi^{2}/ndof = " + to_string_with_precision(chi2ndof.first,1) + "/" + std::to_string(chi2ndof.second)).c_str());
      l_Chi2->Draw();


      // Make the raio plot

      TH1D *h_errors_ratio = (TH1D*)h_errors->Clone("h_errors_ratio");
      std::pair<double,double> ratio_range = {1.0,1.0};
      for(int i=1;i<h_errors_ratio->GetNbinsX()+1;i++){

         double pred = h_errors_ratio->GetBinContent(i);
         double error = h_errors_ratio->GetBinError(i);
         error /= pred;
         h_errors_ratio->SetBinContent(i,1.0);
         if(pred > 0) h_errors_ratio->SetBinError(i,error);
         else h_errors_ratio->SetBinError(i,0.0); 

         if( 1.0+h_errors_ratio->GetBinError(i) > ratio_range.second){
            ratio_range.first = 1.0-h_errors_ratio->GetBinError(i);
            ratio_range.second = 1.0+h_errors_ratio->GetBinError(i);
         }

      }

      c2->cd();
      p_ratio2->Draw();

      p_ratio2->cd();
      h_errors_ratio->Draw("E2");
      h_errors_ratio->GetYaxis()->SetRangeUser(0.9*ratio_range.first,1.1*ratio_range.second);

      h_errors_ratio->SetStats(0);
      h_errors_ratio->GetXaxis()->SetTitle("");
      h_errors_ratio->GetYaxis()->SetTitle("Data/MC");
      h_errors_ratio->GetYaxis()->SetTitleSize(0.12);
      h_errors_ratio->GetYaxis()->SetTitleOffset(0.43);
      //h_errors_ratio->GetXaxis()->SetLabelSize(0.09);
      //h_errors_ratio->GetYaxis()->SetLabelSize(0.09);
      h_errors_ratio->GetXaxis()->SetLabelSize(0.12);
      h_errors_ratio->GetYaxis()->SetLabelSize(0.12);

      TH1D* h_Data_ratio = nullptr;

         h_Data_ratio = (TH1D*) hist_v.at(i_data)->Clone("h_Data_ratio");
         for(int i=1;i<h_Data_ratio->GetNbinsX()+1;i++){
            double pred = h_errors->GetBinContent(i);        
            double Data = hist_v.at(i_data)->GetBinContent(i);
            double error = h_Data_ratio->GetBinError(i);
            double ratio = Data/pred;
            error /= pred;
            h_Data_ratio->SetBinContent(i,ratio);
            if(pred > 0){
               h_Data_ratio->SetBinContent(i,ratio);
               h_Data_ratio->SetBinError(i,error);

            }
            else{
               h_Data_ratio->SetBinContent(i,1.0); 
               h_Data_ratio->SetBinError(i,0.0); 
            }

            //std::cout <<  h_Data_ratio->GetBinContent(i) << "  " << h_Data_ratio->GetBinError(i) << std::endl;

         }

         h_Data_ratio->Draw("E0 same");

 
      // gSystem->Exec("mkdir -p Plots/");
      c2->Print(("Plots/" + label + "_Complete_Ratio.pdf").c_str());
   c2->Print(("Plots/" + label + "_Complete_Ratio.png").c_str());
   c2->Print(("Plots/" + label + "_Complete_Ratio.C").c_str());
   c2->Close();

   }

   c->Close();
}

///////////////////////////////////////////////////////////////////////////////////////////////


#endif
