#ifndef _StatisticsManager_h_
#define _StatisticsManager_h_

#include <iostream>

#include "TEfficiency.h"
#include "TH2D.h"
#include "TMatrixDSym.h"
#include "TCanvas.h"
#include "TMath.h"
#include "TFile.h"

#include "MultiVariateRNG.h"
#include "BayesianPosteriorPDF.h"

class StatisticsManager {

   public:

      StatisticsManager(TEfficiency* eff,TMatrixDSym cov,TMatrixDSym fcov,std::string label="Hist",unsigned int seed=1234);
      ~StatisticsManager();

     // Calculate Phi function by numerically integrating Gaussian
     TH1D* CalculatePhiFunc(TH1D* posteriorpdf,int bin) const;

     // Calculate Phi function by MC
     TH1D* CalculatePhiFuncMC(TH1D* posteriorpdf,int bin,int calls=-1) const;
     void MakePhiFuncs(int calls=-1);

     double SmearedPoisson(TH1D* smearfunc,int n) const;
     TH1D* MakeSmearedPoisson(TH1D* smearfunc,int max=-1) const;
     void MakeSmearedPoissons(int max=-1);

     void SetBinScales(std::vector<double> scales);
     void MakeStatPDFs();
     TH1D* MakeTotalPoisson(int calls=-1);

     double CalculateP(std::vector<int> obs_events);
        
     void Write();

     std::vector<TH1D*> GetSmearedPoissons(){ return SmearedPoisson_v; }
 
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
      TH1D* SmearedPoisson_tot; // Smeard Poisson for total events

      double YMin=1e10;
      double YMax=-1e10;

      // number of bins to split the posterior PDFs into
      const int YBins = 200;

      // number of rectangles used in numeric Gaussian integration
      const double Gauss_steps = 100;

      // MC integration params
      const int MAX_Calls = 150;

      // Parameters for Bayesian PDF calculation
      const double conf = 0.9999;
      const double inc = 0.0001;
      const int Prior = TEfficiency::kBUniform;

      // Fitting parameters
      std::vector<double> Scales;
      
     
};

#endif
