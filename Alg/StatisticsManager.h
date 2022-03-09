#ifndef _StatisticsManager_h_
#define _StatisticsManager_h_

#include <iostream>

#include "TEfficiency.h"
#include "TH2D.h"
#include "TMatrixDSym.h"
#include "TCanvas.h"
#include "TMath.h"
#include "TFile.h"
#include "TGraph.h"

#include "MultiVariateRNG.h"
#include "BayesianPosteriorPDF.h"

const int STAT_MAX_Calls = 1e6;

class StatisticsManager {

   public:

      StatisticsManager(TEfficiency* eff,/*TMatrixDSym cov,*/TMatrixDSym fcov,std::string label="Hist",unsigned int seed=1234);
      ~StatisticsManager();

      // Calculate Phi function by numerically integrating Gaussian
      //TH1D* CalculatePhiFunc(TH1D* posteriorpdf,int bin) const; //deprecated, use MC instead

      // Calculate Phi function by MC
      TH1D* CalculatePhiFuncMC(TH1D* posteriorpdf,int bin) const;
      void MakePhiFuncs();

      double SmearedPoisson(TH1D* smearfunc,int n) const;
      TH1D* MakeSmearedPoisson(TH1D* smearfunc,int max=-1) const;
      void MakeSmearedPoissons(int max=-1);

      void SetBinScales(std::vector<double> scales){ BinScales = scales; }
      void SetBinScales(std::vector<std::vector<double>> scales){ BinScales_v = scales; }

      void MakeStatPDFs();
      TH1D* MakeTotalPoisson();

      void Write();

      std::vector<TH1D*> GetSmearedPoissons(){ return SmearedPoisson_v; }

      void SetCalls(int calls){ Calls = calls; }

      std::map<int,double> MakeLikelihoodMap();
      std::vector<std::map<int,double>> MakeLikelihoodMaps(std::vector<std::vector<double>> scales); 
      void MakeLikelihoodRatioMap();
      std::pair<std::vector<double>,double> MaxLikelihood(int n_obs);
      std::pair<int,int> CalcConfInt(double level,int i_par,int i_val);
      std::pair<TGraph*,TGraph*> MakeConfBelt(double level,int i_par);
      TGraph* MakeMLFit(int i_par);

      void Reset();
        
      void SetRange(int min,int max){ Min = min; Max = max; UseUsrRange = true; } 

      void LoadLikelihoodMap(TH2D* h_L,int par);

   private:

      std::string Label;

      TEfficiency* Eff = nullptr;
      std::vector<double> Events;

      TMatrixDSym Cov;
      TMatrixDSym FCov;

      int NBins;
      MultiVariateRNG* R_Cov = nullptr;
      MultiVariateRNG* R_FCov = nullptr;

      // phi functions
      std::vector<TH1D*> PosteriorPDF_v;      

      // (uppercase) Phi functions
      std::vector<TH1D*> Phi_v; 

      std::vector<TH1D*> SmearedPoisson_v; // Smeared Poisson for each bin

      TH1D* SmearedPoisson_tot = nullptr; // Smeard Poisson for total events
      int Min;
      int Max;
      bool UseUsrRange=false;


      double YMin=1e10;
      double YMax=-1e10;

      // number of bins to split the posterior PDFs into
      const int YBins = 200;

      // number of rectangles used in numeric Gaussian integration
      const double Gauss_steps = 100;

      // MC integration params
      int Calls = STAT_MAX_Calls;

      // Parameters for Bayesian PDF calculation
      const double conf = 0.9999;
      const double inc = 0.0001;
      const int Prior = TEfficiency::kBUniform;

      // Fitting parameters

      // BinScales.at(i-1) scale param for bin i
      std::vector<double> BinScales; // current set of parameters being used

      // BinScales_v.at(i).at(j-1) scale parameter for bin j in universe i
      std::vector<std::vector<double>> BinScales_v; 

      // Likelihoods.at(i)[j] = prob of observing j events in universe i
      std::vector<std::map<int,double>> Likelihoods;
      std::vector<std::map<int,double>> Likelihood_Ratios;
};

// Calculate LLR

// inputs
// h_PMFs = 2D histogram containing set of PMFs with number of observed
// events on x axis and scaling parameter on y axis (ie slice at some fixed y
// gives pmf for different numbers of observed events when scale parameter is y).
// obs_events = number of events observed
// scale = scaling parameter to test

double LR(TH2D* h_PMFs,int obs_events,double scale){

   if(obs_events > h_PMFs->GetXaxis()->GetBinCenter(h_PMFs->GetNbinsX())){
      std::cout << "StatisticsManager: obs_events outside range covered by PMFs, returning 0.0 for LLR" << std::endl;
      return 0.0;
   }

   // calculate denominator of LLR 
   int bin = h_PMFs->GetXaxis()->FindBin(obs_events);

   double denom = 0.0;

   for(int i=1;i<h_PMFs->GetNbinsY()+1;i++)
      denom = std::max(denom,h_PMFs->GetBinContent(bin,i));

   double num = h_PMFs->GetBinContent(bin,h_PMFs->GetYaxis()->FindBin(scale));

   return num/denom;

}

double NLLR2(TH2D* h_PMFs,int obs_events,double scale){

   return -2*log(LR(h_PMFs,obs_events,scale));

}


#endif
