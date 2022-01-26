#ifndef _StatisticsManager_cxx_
#define _StatisticsManager_cxx_

#include "StatisticsManager.h"

///////////////////////////////////////////////////////////////////////////////////////////////

StatisticsManager::StatisticsManager(TEfficiency* eff,TMatrixDSym cov,TMatrixDSym fcov,std::string label,unsigned int seed):
   Eff(eff),
   Cov(cov),
   FCov(fcov),
   Label(label),
   Scales(eff->GetTotalHistogram()->GetNbinsX(),1.0)
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
   Phi_v.resize(NBins);
   SmearedPoisson_v.resize(NBins);
   //MakeStatPDFs();
}

///////////////////////////////////////////////////////////////////////////////////////////////

StatisticsManager::~StatisticsManager(){
   delete R_Cov;
   delete R_FCov;
}

///////////////////////////////////////////////////////////////////////////////////////////////

void StatisticsManager::MakeStatPDFs(){

   for(int i_b=1;i_b<NBins+1;i_b++){
      PosteriorPDF_v.at(i_b-1) = PosteriorPDF(Eff,i_b,Label,Scales.at(i_b-1));
   }

   for(size_t i_b=0;i_b<NBins;i_b++){
      YMin = std::min(PosteriorPDF_v.at(i_b)->GetBinLowEdge(1),YMin); 
      YMax = std::max(PosteriorPDF_v.at(i_b)->GetBinLowEdge(PosteriorPDF_v.at(i_b)->GetNbinsX()+1),YMax); 
   }

   for(size_t i_x=0;i_x<NBins;i_x++)
      for(size_t i_y=0;i_y<NBins;i_y++)
         Cov[i_x][i_y] *= Scales.at(i_x)*Scales.at(i_y);

}

///////////////////////////////////////////////////////////////////////////////////////////////

TH1D* StatisticsManager::CalculatePhiFunc(TH1D* posteriorpdf,int bin) const {

   if(NBins > 2)
      throw std::runtime_error("Numerical integration only implemented for up to 2 bins, use MC integration instead");

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

            double phi = posteriorpdf->GetBinContent(posteriorpdf->FindBin(h->GetBinCenter(i_b) - smear_params.at(bin-1)));
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

TH1D* StatisticsManager::CalculatePhiFuncMC(TH1D* posteriorpdf,int bin,int calls) const {

   if(calls == -1) calls = std::max(pow(MAX_Calls,NBins),1e7);

   // Find limits for the histogram
   double sigma_sys = sqrt(FCov[bin-1][bin-1])*posteriorpdf->GetBinCenter(int(posteriorpdf->GetNbinsX()/2)+1);

   TH1D* h = new TH1D(("h_Phi_"+ Label + "_" + std::to_string(bin)).c_str(),";Selected Events;PDF",YBins,std::max(0.0,posteriorpdf->GetBinLowEdge(1)-5*sigma_sys),posteriorpdf->GetBinLowEdge(posteriorpdf->GetNbinsX())+5*sigma_sys);

   for(int i=0;i<calls;i++){
      if(i % 10000 == 0) std::cout << "Call " << i << "/" << calls << std::endl;
      h->Fill(posteriorpdf->GetRandom()*R_FCov->GetParameterSet().at(bin-1));
   }

   h->Scale(1.0/h->Integral("width"));

   return h;

}

///////////////////////////////////////////////////////////////////////////////////////////////

double StatisticsManager::SmearedPoisson(TH1D* smearfunc,int n) const {

   double P = 0.0;

   for(int i=1;i<smearfunc->GetNbinsX()+1;i++)
      P += TMath::Poisson(n,smearfunc->GetBinCenter(i))*smearfunc->GetBinContent(i)*smearfunc->GetBinWidth(i);

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

void StatisticsManager::MakePhiFuncs(int calls){

   for(int i=0;i<NBins;i++)
      Phi_v.at(i) = CalculatePhiFuncMC(PosteriorPDF_v.at(i),i+1,calls);
}

///////////////////////////////////////////////////////////////////////////////////////////////

void StatisticsManager::MakeSmearedPoissons(int max){

   double max_val=-0.5,min_val=1e10;
   for(int i=0;i<NBins;i++){
      SmearedPoisson_v.at(i) = MakeSmearedPoisson(Phi_v.at(i),max);
      //min = std::min(min,SmearedPoisson_v.at(i)->GetBinLowEdge(1));
      //max = std::max(max,SmearedPoisson_v.at(i)->GetBinLowEdge(SmearedPoisson_v.at(i)->GetNbinsX()+1));
      max_val += SmearedPoisson_v.at(i)->GetBinLowEdge(SmearedPoisson_v.at(i)->GetNbinsX()+1);
      min_val = std::min(SmearedPoisson_v.at(i)->GetBinLowEdge(1),min_val);
   }

   min_val = floor(min_val) - 0.5;
   max_val = ceil(max_val) + 0.5;
   min_val = std::max(min_val,-0.5);

   int n = max_val - min_val;

   SmearedPoisson_tot = new TH1D("h_SmearedPoisson_tot",";Observed Events;PMF",n,min_val,max_val);
}

///////////////////////////////////////////////////////////////////////////////////////////////

TH1D* StatisticsManager::MakeTotalPoisson(int calls){

   if(calls == -1) calls = std::max(pow(MAX_Calls,NBins),1e7);

   for(int i=0;i<calls;i++){
      int events = 0;
      for(size_t i_b=1;i_b<NBins+1;i_b++){
         events += SmearedPoisson_v.at(i_b-1)->GetRandom();
      }
      SmearedPoisson_tot->Fill(events);
   }
   SmearedPoisson_tot->Scale(1.0/calls);

   return SmearedPoisson_tot;
}

///////////////////////////////////////////////////////////////////////////////////////////////

void StatisticsManager::SetBinScales(std::vector<double> scales){

   Scales = scales;

}


///////////////////////////////////////////////////////////////////////////////////////////////

double StatisticsManager::CalculateP(std::vector<int> obs_events){

   if(obs_events.size() != NBins)
      throw std::runtime_error("StatisticsManager::CalculateP : obs_events.size != NBins, exiting");


   double P = 1.0;

   for(int i=0;i<NBins;i++){

       P *= SmearedPoisson_v.at(i)->GetBinContent(SmearedPoisson_v.at(i)->FindBin(obs_events.at(i)));

        /*
      // observation above CV
      if(SmearedPoisson_v.at(i)->FindBin(obs_events.at(i)) > SmearedPoisson_v.at(i)->GetMaximumBin()){


//         double Integral = SmearedPoisson_v.at(i)->Integral(SmearedPoisson_v.at(i)->FindBin(obs_events.at(i)),SmearedPoisson_v.at(i)->GetNbinsX()+1);

//         P *= Integral;

      }  

      // observation below CV
      if(SmearedPoisson_v.at(i)->FindBin(obs_events.at(i)) <= SmearedPoisson_v.at(i)->GetMaximumBin()){

         double Integral = SmearedPoisson_v.at(i)->Integral(1,SmearedPoisson_v.at(i)->FindBin(obs_events.at(i)));

         //std::cout << "Integral=" << Integral << std::endl;

         P *=  Integral;

      }
*/
   }

   return P;

}

///////////////////////////////////////////////////////////////////////////////////////////////
/*
std::vector<TH1D*> GetSmearedPoissons(){

return SmearedPoisson_v;

}
*/
///////////////////////////////////////////////////////////////////////////////////////////////

void StatisticsManager::Write(){

   TFile *f = TFile::Open(("rootfiles/" + Label + "_Statistics.root").c_str(),"RECREATE");

   for(size_t i=0;i<NBins;i++){

      PosteriorPDF_v.at(i)->SetDirectory(f);
      Phi_v.at(i)->SetDirectory(f);
      SmearedPoisson_v.at(i)->SetDirectory(f);

      PosteriorPDF_v.at(i)->Write(("PosteriorPDF_bin_" + std::to_string(i)).c_str());
      Phi_v.at(i)->Write(("PhiFunc_bin_" + std::to_string(i)).c_str());
      SmearedPoisson_v.at(i)->Write(("SmearedPoisson_bin_" + std::to_string(i)).c_str());

   }

   SmearedPoisson_tot->SetDirectory(f);
   SmearedPoisson_tot->Write("TotalEvents_SmearedPoisson");

}

///////////////////////////////////////////////////////////////////////////////////////////////

#endif
