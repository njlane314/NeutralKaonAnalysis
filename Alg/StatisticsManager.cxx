#ifndef _StatisticsManager_cxx_
#define _StatisticsManager_cxx_

#include "StatisticsManager.h"

///////////////////////////////////////////////////////////////////////////////////////////////

StatisticsManager::StatisticsManager(TEfficiency* eff,/*TMatrixDSym cov,*/TMatrixDSym fcov,std::string label,unsigned int seed):
   Eff(eff),
   //Cov(cov),
   FCov(fcov),
   Label(label),
   BinScales(eff->GetTotalHistogram()->GetNbinsX(),1.0),
   BinScales_v(eff->GetTotalHistogram()->GetNbinsX(),std::vector<double>(1,1.0))
{
   if(Eff->GetTotalHistogram()->GetNbinsX() != FCov.GetNrows())
      throw std::runtime_error("Efficiency hist and covariance matrix have different sizes, exiting");

   NBins = Eff->GetTotalHistogram()->GetNbinsX();

   Events.resize(NBins);
   for(size_t i_b=1;i_b<NBins+1;i_b++)
      Events.at(i_b-1) = Eff->GetTotalHistogram()->GetBinContent(i_b);

   //  R_Cov = new MultiVariateRNG(seed,Cov);
   R_FCov = new MultiVariateRNG(seed,FCov);

   //PosteriorPDF_v.resize(NBins);
   //Phi_v.resize(NBins);
   //SmearedPoisson_v.resize(NBins);
   //MakeStatPDFs();
}

///////////////////////////////////////////////////////////////////////////////////////////////

StatisticsManager::~StatisticsManager(){
   //delete R_Cov;
   delete R_FCov;
}

///////////////////////////////////////////////////////////////////////////////////////////////

void StatisticsManager::MakeStatPDFs(){
   /*
      for(size_t i_x=0;i_x<NBins;i_x++)
      for(size_t i_y=0;i_y<NBins;i_y++)
      Cov[i_x][i_y] *= Scales.at(i_x)*Scales.at(i_y);
      */

   for(int i_b=1;i_b<NBins+1;i_b++)
      PosteriorPDF_v.push_back(PosteriorPDF(Eff,i_b,Label,BinScales.at(i_b-1)));

   for(size_t i_b=0;i_b<NBins;i_b++){
      YMin = std::min(PosteriorPDF_v.at(i_b)->GetBinLowEdge(1),YMin); 
      YMax = std::max(PosteriorPDF_v.at(i_b)->GetBinLowEdge(PosteriorPDF_v.at(i_b)->GetNbinsX()+1),YMax); 
   }

}

///////////////////////////////////////////////////////////////////////////////////////////////

// deprecated

/*
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
*/
///////////////////////////////////////////////////////////////////////////////////////////////

TH1D* StatisticsManager::CalculatePhiFuncMC(TH1D* posteriorpdf,int bin) const {

   // Find limits for the histogram
   double sigma_sys = sqrt(FCov[bin-1][bin-1])*posteriorpdf->GetBinCenter(int(posteriorpdf->GetNbinsX()/2)+1);

   TH1D* h = new TH1D(("h_Phi_"+ Label + "_" + std::to_string(bin)).c_str(),";Selected Events;PDF",YBins,std::max(0.0,posteriorpdf->GetBinLowEdge(1)-4*sigma_sys),posteriorpdf->GetBinLowEdge(posteriorpdf->GetNbinsX())+4*sigma_sys);

   for(int i=0;i<Calls;i++){
      if(i % 10000 == 0) std::cout << "Call " << i << "/" << Calls << std::endl;
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

   // TODO: Implement probabilistic method to set bin limits (eg. set so they should
   // contian 99.9% of the final dist

   int n = std::max(max,int(smearfunc->GetBinLowEdge(smearfunc->GetNbinsX()+1)*1.1));

   TH1D* h = new TH1D("h_SmearedPoisson",";Obs. Events;PMF",n+1,-0.5,n+0.5);

   for(int i=1;i<n+2;i++)
      h->SetBinContent(i,SmearedPoisson(smearfunc,i-1));

   return h;
}

///////////////////////////////////////////////////////////////////////////////////////////////

void StatisticsManager::MakePhiFuncs(){

   for(int i=0;i<NBins;i++)
      Phi_v.push_back(CalculatePhiFuncMC(PosteriorPDF_v.at(i),i+1));
}

///////////////////////////////////////////////////////////////////////////////////////////////

void StatisticsManager::MakeSmearedPoissons(int max){

   double max_val=0.0,min_val=1e10;
   for(int i=0;i<NBins;i++){
      SmearedPoisson_v.push_back(MakeSmearedPoisson(Phi_v.at(i),max));
      /*
      //min = std::min(min,SmearedPoisson_v.at(i)->GetBinLowEdge(1));
      //max = std::max(max,SmearedPoisson_v.at(i)->GetBinLowEdge(SmearedPoisson_v.at(i)->GetNbinsX()+1));
      max_val += pow(SmearedPoisson_v.at(i)->GetBinLowEdge(SmearedPoisson_v.back()->GetNbinsX()+1),2);
      min_val = std::min(SmearedPoisson_v.back()->GetBinLowEdge(1),min_val);
      std::cout << sqrt(max_val) << std::endl;
      */
   }
   /*
      max_val = sqrt(max_val);

      min_val = floor(min_val) - 0.5;
      max_val = ceil(max_val) + 0.5;
      min_val = std::max(min_val,-0.5);

      int n = max_val - min_val;
      */
}

///////////////////////////////////////////////////////////////////////////////////////////////

TH1D* StatisticsManager::MakeTotalPoisson(){


   int max = 0;
   int min = 0;

   if(!UseUsrRange){
      for(int i=0;i<Calls/20;i++){
         int events = 0;
         for(size_t i_b=1;i_b<NBins+1;i_b++){
            events += SmearedPoisson_v.at(i_b-1)->GetRandom();
         }
         max = std::max(max,events);
         min = std::min(min,events);
      }
      Min = min;
      Max = max;
   }

   SmearedPoisson_tot = new TH1D("h_SmearedPoisson_tot",";Observed Events;PMF",Max-Min+1,Min-0.5,Max+0.5);

   for(int i=0;i<Calls;i++){
      int events = 0;
      for(size_t i_b=1;i_b<NBins+1;i_b++){
         events += SmearedPoisson_v.at(i_b-1)->GetRandom();
      }
      SmearedPoisson_tot->Fill(events);
   }
   SmearedPoisson_tot->Scale(1.0/Calls);

   return SmearedPoisson_tot;
}

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

void StatisticsManager::Reset(){

   PosteriorPDF_v.clear();
   Phi_v.clear();
   SmearedPoisson_v.clear();
   if(SmearedPoisson_tot != nullptr) delete SmearedPoisson_tot;
}

///////////////////////////////////////////////////////////////////////////////////////////////

std::map<int,double> StatisticsManager::MakeLikelihoodMap(){

   Reset();

   MakeStatPDFs();
   MakePhiFuncs();
   MakeSmearedPoissons();
   MakeTotalPoisson();

   std::map<int,double> likelihoods;

   for(int i_b=1;i_b<SmearedPoisson_tot->GetNbinsX()+1;i_b++)
      likelihoods[SmearedPoisson_tot->GetBinCenter(i_b)] = SmearedPoisson_tot->GetBinContent(i_b);

   return likelihoods;
}

///////////////////////////////////////////////////////////////////////////////////////////////

std::vector<std::map<int,double>> StatisticsManager::MakeLikelihoodMaps(std::vector<std::vector<double>> scales){

   BinScales_v = scales;

   for(size_t i=0;i<BinScales_v.size();i++){
      std::cout << "Calc likelihoods for param set " << i+1 << "/" << BinScales_v.size() << std::endl;
      BinScales = BinScales_v.at(i);
      Likelihoods.push_back(MakeLikelihoodMap());
   }

   //MakeLikelihoodRatioMap();

   return Likelihoods;
}

///////////////////////////////////////////////////////////////////////////////////////////////

void StatisticsManager::MakeLikelihoodRatioMap(){

Likelihood_Ratios.resize(Likelihoods.size());

   for(int i=Min;i<=Max;i++){
      double ML = MaxLikelihood(i).second;
      for(size_t i_p=0;i_p<BinScales_v.size();i_p++){
         Likelihood_Ratios.at(i_p)[i] = Likelihoods.at(i_p)[i]/ML;   
         std::cout << "LR for obs " << i << "  param set " << i_p << "  " << Likelihoods.at(i_p)[i]/ML << std::endl;
        }
   }
}

///////////////////////////////////////////////////////////////////////////////////////////////

std::pair<std::vector<double>,double> StatisticsManager::MaxLikelihood(int n_obs){

   double ML = 0.0;
   int i_ML = -1;
      
   for(size_t i=0;i<BinScales_v.size();i++){
      if(Likelihoods.at(i)[n_obs] > ML){
         ML = Likelihoods.at(i)[n_obs];
         i_ML = i;
      }       
   }

   std::cout << "Max likelihood found at param set " << i_ML << std::endl;

   return {BinScales_v.at(i_ML),ML};
}

///////////////////////////////////////////////////////////////////////////////////////////////

// Calculate conf=level confidence interval for scale of param i_par at i_val
// (assuming all other params are fixed). Use Feldman-Cousins method

std::pair<int,int> StatisticsManager::CalcConfInt(double level,int i_par,int i_val){

   //std::cout << "Calc confidence interval for par=" << BinScales_v.at(i_val).at(i_par) << std::endl;
   //double ML = MaxLikelihood(n_obs).second;

   std::vector<Double_t> Obs_v;
   std::vector<Double_t> LR_v;
   std::vector<Double_t> P_v;

   // Get range of event counts
   int min_n = 0,max_n = 0;
   std::map<int,double>::iterator it;
   for (it = Likelihoods.at(i_val).begin(); it != Likelihoods.at(i_val).end(); it++){
      min_n = std::min(it->first,min_n);
      max_n = std::max(it->first,max_n);
   }

   //std::cout <<"minmax=" <<  min_n << "  " << max_n << std::endl;

   // Calculate LR for each number of events
   for(int i=min_n;i<max_n+1;i++){
      Obs_v.push_back(i);
      P_v.push_back(Likelihoods.at(i_val)[i]);

      // Calculate maximum lielihood for this number of events  
      double ML = 0.0;
      for(size_t i_p=0;i_p<Likelihoods.size();i_p++)
         ML = std::max(ML,Likelihoods.at(i_p)[i]);

      if(ML > 0) LR_v.push_back(Likelihoods.at(i_val)[i]/ML);
      else LR_v.push_back(0.0);

      //    std::cout << "obs=" << i << " P=" << P_v.back() << " ML=" << ML << " LR=" << LR_v.back() << std::endl;
   }

   double P = 0.0;
   std::vector<int> in_v;

   double upper_limit = -1e10;
   double lower_limit = 1e10;

   while(P < level){
      // find the bin with the highest LR
      double max_LR = 0.0;
      int i_max = -1;
      for(size_t i=0;i<Obs_v.size();i++){
         //std::cout << Signal_Scale_v.at(i) << "  " <<  LR_v.at(i) << std::endl;
         if(LR_v.at(i) > max_LR){
            i_max = i;
            max_LR = LR_v.at(i);
         }
      }   

      // add the bin to the confidence interval
      P += P_v.at(i_max);        

      //       std::cout << "Adding " <<  Obs_v.at(i_max) << " to interval with LR" << std::endl;

      in_v.push_back(Obs_v.at(i_max));       
      upper_limit = std::max(upper_limit,Obs_v.at(i_max));
      lower_limit = std::min(lower_limit,Obs_v.at(i_max));

      LR_v.erase(LR_v.begin()+i_max);
      P_v.erase(P_v.begin()+i_max);
      Obs_v.erase(Obs_v.begin()+i_max);
   }

   //std::cout << "Interval for param " << i_par << " val=" << BinScales_v.at(i_val).at(i_par) << "  low=" << lower_limit << "  high=" << upper_limit << std::endl;

   return {lower_limit,upper_limit};

   //return {0,0};
}

///////////////////////////////////////////////////////////////////////////////////////////////

std::pair<TGraph*,TGraph*> StatisticsManager::MakeConfBelt(double level,int i_par){

   std::vector<Double_t> X_low;
   std::vector<Double_t> X_high;
   std::vector<Double_t> Y;

   for(size_t i=0;i<BinScales_v.size();i++){
      std::pair<int,int> limits = CalcConfInt(level,i_par,i);
      X_low.push_back(limits.first);
      X_high.push_back(limits.second);
      Y.push_back(BinScales_v.at(i).at(i_par));
   }

   TGraph *g_low = new TGraph(X_low.size(),&(X_low[0]),&(Y[0]));
   TGraph *g_high = new TGraph(X_high.size(),&(X_high[0]),&(Y[0]));

   return {g_low,g_high};
}

///////////////////////////////////////////////////////////////////////////////////////////////

TGraph* StatisticsManager::MakeMLFit(int i_par){

   std::vector<Double_t> X;
   std::vector<Double_t> Y;

   for(int i=Min;i<=Max;i++){
      std::pair<std::vector<double>,double> ML = MaxLikelihood(i);
      X.push_back(i);
      Y.push_back(ML.first.at(i_par));
   }

   TGraph *g = new TGraph(X.size(),&(X[0]),&(Y[0]));

   return g;
}

///////////////////////////////////////////////////////////////////////////////////////////////

void StatisticsManager::LoadLikelihoodMap(TH2D* h_L,int par){

   int n_obs = h_L->GetNbinsX();
   int n_vals = h_L->GetNbinsY();

   Min = h_L->GetXaxis()->GetBinCenter(1);
   Max = Min + n_obs - 1;

     Likelihoods.clear(); 
     BinScales_v.clear();

     for(int i_p=0;i_p<n_vals;i_p++){

        double par_val = h_L->GetYaxis()->GetBinCenter(i_p+1);
        std::vector<double> par_vals(NBins,1.0);
        par_vals.at(par) = par_val;

        std::map<int,double> this_L;
        for(int i_n=0;i_n<n_obs;i_n++){
           
           this_L[Min+i_n] = h_L->GetBinContent(i_n+1,i_p+1);
        }
        Likelihoods.push_back(this_L);
        BinScales_v.push_back(par_vals);

     }

}

// TODO: Add liklelihood ratio map

#endif
