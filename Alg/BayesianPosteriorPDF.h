#ifndef _BayesianPosteriorPDF_h_
#define _BayesianPosteriorPDF_h_

#include "Math/PdfFuncMathCore.h"

// Beta distribution parameters for prior
const double prior_beta_dist_alpha = 1.0;
const double prior_beta_dist_beta = 1.0;

////////////////////////////////////////////////////////////////////////////////

inline TH1D* PosteriorPDF(TEfficiency * E,int bin,std::string name="",double scale=1.0){

   // if scale is zero, posterior PDF is a delta function at x=0 
   if(!(scale > 0.0)){
      TH1D* h_Posterior = new TH1D(("h_Expected"+name).c_str(),";Events;PDF",1,0.0,1e-10);
      h_Posterior->SetBinContent(1,1.0/h_Posterior->GetBinWidth(1));
      return h_Posterior;
   } 

   double conf = 0.9999;
   double inc = 0.0001;

   E->SetStatisticOption(TEfficiency::kBUniform);  
   E->SetConfidenceLevel(conf);

   // Get total events     
   TH1D *h_Total = (TH1D*)E->GetTotalHistogram();
   double TotalEvents =  h_Total->GetBinContent(bin)*scale;

   // Get an initial pair of limits for the histogram
   double Efficiency = E->GetEfficiency(bin);
   double Efficiency_Low = E->GetEfficiency(bin) - E->GetEfficiencyErrorLow(bin);
   double Efficiency_High = E->GetEfficiency(bin) + E->GetEfficiencyErrorUp(bin);

   TH1D *h_Posterior = new TH1D(("h_Expected"+name).c_str(),";Events;PDF",1000000,Efficiency_Low*TotalEvents,Efficiency_High*TotalEvents);

   while(conf > 0.0){

      E->SetConfidenceLevel(conf);

      double old_low = TotalEvents*(E->GetEfficiency(bin) - E->GetEfficiencyErrorLow(bin));
      double old_high = TotalEvents*(E->GetEfficiency(bin) + E->GetEfficiencyErrorUp(bin));

      E->SetConfidenceLevel(conf-inc);

      double new_low = TotalEvents*(E->GetEfficiency(bin) - E->GetEfficiencyErrorLow(bin));
      double new_high = TotalEvents*(E->GetEfficiency(bin) + E->GetEfficiencyErrorUp(bin)); 

      int old_low_bin = h_Posterior->GetXaxis()->FindBin(old_low);
      int old_high_bin = h_Posterior->GetXaxis()->FindBin(old_high);

      int new_low_bin = h_Posterior->GetXaxis()->FindBin(new_low);
      int new_high_bin = h_Posterior->GetXaxis()->FindBin(new_high);

      int nbins_low = new_low_bin - old_low_bin;
      int nbins_high = old_high_bin - new_high_bin;

      double content_low = inc/2/nbins_low;
      double content_high = inc/2/nbins_high;

      for(int i=0;i<nbins_low;i++)
         h_Posterior->AddBinContent(old_low_bin+i,content_low);

      for(int i=0;i<nbins_high;i++)
         h_Posterior->AddBinContent(new_high_bin+i,content_high);

      conf -= inc;
   }

   h_Posterior->Rebin(1000);
   h_Posterior->Scale(1.0/h_Posterior->GetBinWidth(1));

   return h_Posterior;
}

////////////////////////////////////////////////////////////////////////////////
// New method that does not involve the TEfficiency class but uses the same
// formulae
// sumw = sum of weights of all events
// sumw2 = sum of squares of weights of all events
// sumselw = sum of weights of selected events
// sumselw2 = sum of squares of weights of selected events

inline TH1D* PosteriorPDF2(double sumw,double sumw2,double sumselw,double sumselw2,std::string name="",double scale=1.0){

    std::cout << "Building Bayesian Posterior" << std::endl;
    std::cout << "sumw=" << sumw << " sumw2=" << sumw2 << std::endl;
    std::cout << "sumselw=" << sumselw << " sumselw2=" << sumselw2 << std::endl;

   TH1D* h_Posterior = new TH1D(("h_Posterior_" + name).c_str(),"PMF",10000000,0.0,scale);

   double norm = sumw/sumw2;
   double aa = sumselw*norm + prior_beta_dist_alpha;
   double bb = (sumw - sumselw)*norm + prior_beta_dist_beta;

   for(int i=1;i<h_Posterior->GetNbinsX()+1;i++){
      double x = h_Posterior->GetBinCenter(i)/scale;
      double P = ROOT::Math::beta_pdf(x,aa,bb);
      h_Posterior->SetBinContent(i,P);
   }  

   return h_Posterior;

}

////////////////////////////////////////////////////////////////////////////////
// New method that does not involve the TEfficiency class but uses the same
// formulae
// sumw = sum of weights of all events
// sumw2 = sum of squares of weights of all events
// sumselw = sum of weights of selected events
// sumselw2 = sum of squares of weights of selected events

const double min_p = 0.0001;

inline TH1D* PosteriorPDF3(double sumw,double sumw2,double sumselw,double sumselw2,std::string name="",double scale=1.0){

    std::cout << "Building Bayesian Posterior" << std::endl;
    std::cout << "sumw=" << sumw << " sumw2=" << sumw2 << std::endl;
    std::cout << "sumselw=" << sumselw << " sumselw2=" << sumselw2 << std::endl;

   double norm = sumw/sumw2;
   double aa = sumselw*norm + prior_beta_dist_alpha;
   double bb = (sumw - sumselw)*norm + prior_beta_dist_beta;

   double min = 0.0;
   double max = 1.0;
   double inc = 1e-8;
   double x = min - inc/2;     
   while(x < max){
      if(ROOT::Math::beta_pdf(x,aa,bb) > min_p){
         min = x;
         break;
      }
      inc *= 1.01;
      x += inc;
   }

   inc = 1e-8;
   x = max + inc/2;
   while(x > min){
      std::cout << x << " " << ROOT::Math::beta_pdf(x,aa,bb) << std::endl;
      if(ROOT::Math::beta_pdf(x,aa,bb) > min_p){
         max = x;
         break;
      }
      inc *= 1.01;
      x -= inc;
   }

   std::cout << "Detected limits " << min << " " << max << std::endl;
   std::cout << "Scaled limits " << min*scale << " " << max*scale << std::endl;

   TH1D* h_Posterior = new TH1D(("h_Posterior_" + name).c_str(),"PMF",10000,min*scale,max*scale);
   for(int i=1;i<h_Posterior->GetNbinsX()+1;i++){
      double x = h_Posterior->GetBinCenter(i)/scale;
      double P = ROOT::Math::beta_pdf(x,aa,bb);
      h_Posterior->SetBinContent(i,P);
   }  

   return h_Posterior;

}

////////////////////////////////////////////////////////////////////////////////
// Produce histogram with Bayesian credible interval
// Inputs:
// h_pdf = Bayesian posterior probabiity distribution
// conflev = confidence level

TH1D* GetCredInt(TH1D* h_pdf,double conflev=0.68){

   std::vector<int> bins;
   double P = 0.0;
   int low_bin=h_pdf->GetNbinsX()+1,high_bin=0,center_bin;   

   while(P<conflev){
      double max = 0.0;
      int max_bin = -1;
      for(int i_b=1;i_b<h_pdf->GetNbinsX()+1;i_b++)
         if(h_pdf->GetBinContent(i_b) > max && std::find(bins.begin(), bins.end(),i_b) == bins.end()){
            max = h_pdf->GetBinContent(i_b);
            max_bin = i_b;
         }      
      if(!bins.size()) center_bin = max_bin;     
      if(max_bin < low_bin) low_bin = max_bin;
      if(max_bin > high_bin) high_bin = max_bin;
      bins.push_back(max_bin);
      P += h_pdf->GetBinContent(max_bin)*h_pdf->GetBinWidth(max_bin);
   }  

   // Print measured cross section
   double xsec = h_pdf->GetBinCenter(center_bin);
   double xsec_error_low = xsec - h_pdf->GetBinCenter(low_bin);
   double xsec_error_high = h_pdf->GetBinCenter(high_bin) - xsec;

   std::cout << std::endl << "Measured cross section: " << xsec << " 10^-40 cm^2" << std::endl;
   std::cout << "Confidence region: " << h_pdf->GetBinCenter(low_bin) << " - " << h_pdf->GetBinCenter(high_bin) << std::endl;
   std::cout << "Uncertainty: + " << xsec_error_high << " - " << xsec_error_low << " 10^-40 cm^2" << std::endl << std::endl; 
   std::cout << "Fractional Error = " << (xsec_error_high+xsec_error_low)/xsec/2 << std::endl;

   TH1D* h_cr = (TH1D*)h_pdf->Clone("h_CR");
   for(int i=1;i<h_cr->GetNbinsX()+1;i++)
      if(std::find(bins.begin(), bins.end(),i) == bins.end()) h_cr->SetBinContent(i,0); 

   return h_cr;
}

////////////////////////////////////////////////////////////////////////////////

#endif
