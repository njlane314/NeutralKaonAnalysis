#ifndef _StatisticsManager_cxx_
#define _StatisticsManager_cxx_

#include "StatisticsManager.h"

///////////////////////////////////////////////////////////////////////////////////////////////

StatisticsManager::StatisticsManager(TEfficiency* eff,TMatrixDSym cov,TMatrixDSym fcov,std::string label,unsigned int seed):
   Eff(eff),
   Cov(cov),
   FCov(fcov),
   Label(label)
{
   if(Eff->GetTotalHistogram()->GetNbinsX() != Cov.GetNrows())
      throw std::runtime_error("Efficiency hist and covariance matrix have different sizes, exiting");

   NBins = Eff->GetTotalHistogram()->GetNbinsX();

   Events.resize(NBins);
   for(size_t i_b=1;i_b<NBins+1;i_b++)
      Events.at(i_b-1) = Eff->GetTotalHistogram()->GetBinContent(i_b);

   R_Cov = new MultiVariateRNG(seed,Cov);
   R_FCov = new MultiVariateRNG(seed,FCov);

   PosteriorPDF_v.resize(NBins);
   MakeStatPDFs();
}

///////////////////////////////////////////////////////////////////////////////////////////////

StatisticsManager::~StatisticsManager(){
   delete R_Cov;
   delete R_FCov;
}

///////////////////////////////////////////////////////////////////////////////////////////////

void StatisticsManager::MakeStatPDFs(){

   for(int i_b=1;i_b<NBins+1;i_b++){
      PosteriorPDF_v.at(i_b-1) = PosteriorPDF(Eff,i_b,Label);
   }

   for(size_t i_b=0;i_b<NBins;i_b++){
      YMin = std::min(PosteriorPDF_v.at(i_b)->GetBinLowEdge(1),YMin); 
      YMax = std::max(PosteriorPDF_v.at(i_b)->GetBinLowEdge(PosteriorPDF_v.at(i_b)->GetNbinsX()+1),YMax); 
   }

}

///////////////////////////////////////////////////////////////////////////////////////////////

TH1D* StatisticsManager::CalculatePhiFunc(int bin) const {

   if(NBins > 2)
      throw std::runtime_error("Numerical integration only implemented for up to 2 bins, use MC integration instead");

   TH1D* theh = PosteriorPDF_v.at(bin-1);

   TH1D* h = new TH1D(("h_Phi_"+ Label + "_" + std::to_string(bin)).c_str(),"",YBins,YMin,YMax*4.0);

   for(int i_b=1;i_b<YBins+1;i_b++){

      double content = 0.0;

      // numerically integrate the Gaussian      
      std::vector<double> smear_params(2);

      double xmin = -3*Cov[0][0];
      double xmax = 3*Cov[0][0];
      double xinc = 6*Cov[0][0]/Gauss_steps;

      double ymin = -3*Cov[1][1];
      double ymax = 3*Cov[1][1];
      double yinc = 6*Cov[1][1]/Gauss_steps;

      double x = xmin;
      double y = ymin;

      while(x<xmax){
         while(y<ymax){

            smear_params = {x,y};

            double phi = theh->GetBinContent(theh->FindBin(h->GetBinCenter(i_b) - smear_params.at(bin-1)));
            double gaus = R_Cov->EvalGauss(smear_params);

            content += phi*gaus;

            y += yinc;
         }

         x += xinc;
         y = yinc;
      }       
      h->SetBinContent(i_b,content*xinc*yinc);

   }

   return h;

}

///////////////////////////////////////////////////////////////////////////////////////////////

TH1D* StatisticsManager::CalculatePhiFuncMC(int bin,int calls) const {

   TH1D* theh = PosteriorPDF_v.at(bin-1);

   if(calls == -1) calls = std::max(pow(MAX_Calls,NBins),1e7);

   // Find limits for the histogram
   double sigma_sys = sqrt(FCov[bin-1][bin-1])*theh->GetBinCenter(int(theh->GetNbinsX()/2)+1);
   //std::cout << "theh->GetMean()=" << theh->GetMean() << std::endl;

   std::cout << "sigma_sys=" << sigma_sys << std::endl;

   TH1D* h = new TH1D(("h_Phi_"+ Label + "_" + std::to_string(bin)).c_str(),"",YBins,std::max(0.0,theh->GetBinLowEdge(1)-5*sigma_sys),theh->GetBinLowEdge(theh->GetNbinsX())+5*sigma_sys);

   std::cout << "Using bin range = " << std::max(0.0,theh->GetBinLowEdge(1)-5*sigma_sys) << "  " << theh->GetBinLowEdge(theh->GetNbinsX())+5*sigma_sys << std::endl;

   for(int i=0;i<calls;i++){
      if(i % 10000 == 0) std::cout << "Call " << i << "/" << calls << std::endl;
      h->Fill(theh->GetRandom()*R_FCov->GetParameterSet().at(bin-1));
   }

   h->Scale(1.0/calls);

   return h;

}

///////////////////////////////////////////////////////////////////////////////////////////////

double StatisticsManager::SmearedPoisson(TH1D* smearfunc,int n) const {

   double P = 0.0;

   for(int i=1;i<smearfunc->GetNbinsX()+1;i++)
      P += TMath::Poisson(n,smearfunc->GetBinCenter(i))*smearfunc->GetBinContent(i);

   return P;
}

///////////////////////////////////////////////////////////////////////////////////////////////

TH1D* StatisticsManager::MakeSmearedPoisson(TH1D* smearfunc,int max) const {

   int n = std::max(max,int(smearfunc->GetBinLowEdge(smearfunc->GetNbinsX()+1)*1.5));

   TH1D* h = new TH1D("h_SmearedPoisson",";Obs. Events;PMF",n+1,-0.5,n+0.5);

   double P = 0.0;

   for(int i=1;i<n+2;i++)
      h->SetBinContent(i,SmearedPoisson(smearfunc,i-1));

   return h;
}

///////////////////////////////////////////////////////////////////////////////////////////////


#endif
