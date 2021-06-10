#ifndef _FluxWeight_h_
#define _FluxWeight_h_

#include <iostream>

#include "TFile.h"
#include "TMatrixD.h"
#include "TH2D.h"

namespace FluxWeight {


   class FluxWeighter {

      public:

         enum flav { k_numu, k_numubar, k_nue, k_nuebar, k_FLAV_MAX };
         std::vector<std::string> flav_str = {"numu","numubar","nue","nuebar"};

         FluxWeighter(int RunPeriod);
         ~FluxWeighter();
         double GetFluxWeight(double nu_e,double nu_angle,int nu_pdg); 

      private:

         int fRunPeriod;

         TFile *f_flux=nullptr;
         std::vector<TH2D*> hist_ratio;
         std::vector<TH2D*> hist_ratio_uw;       


   };

};

#endif
