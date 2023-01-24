#ifndef _SidebandFitter_h_
#define _SidebandFitter_h_

#include <vector>
#include "TH1D.h"
#include "TMatrixDSym.h"
#include "Math/Minimizer.h"
#include "Math/Functor.h"
#include "Math/Factory.h"

// Tools for performing fits to sideband data.

struct FitResult {

   std::vector<double> FitVals;
   TMatrixDSym FitCov;

};

class SidebandFitter {

   public: 

      SidebandFitter();
      void AddHistograms(std::vector<TH1D*> h_fixed_v,std::vector<TH1D*> h_tovar_v,TH1D* h_data);
      void AddFixedHistograms(std::vector<TH1D*> h_fixed_v);
      void AddVariedHistograms(std::vector<TH1D*> h_tovar_v);
      void AddDataHistogram(TH1D* h_data);
      void AddCovMatrix(TMatrixDSym covsys);

      FitResult DoFit();
      void Clear();

   private:
      
      std::vector<TH1D*> h_ToVar_v;
      std::vector<TH1D*> h_Fixed_v;
      TH1D* h_Data = nullptr;

      bool HasSys = false;
      TMatrixDSym CovSys; 

      std::unique_ptr< ROOT::Math::Minimizer > Minimizer = std::unique_ptr<ROOT::Math::Minimizer>
         (ROOT::Math::Factory::CreateMinimizer("Minuit2","Migrad"));

};

#endif
