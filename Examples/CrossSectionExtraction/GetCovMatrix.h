#ifndef _GetCovMatrix_h_
#define _GetCovMatrix_h_

// Calculate covariance matrices when given a list of efficiencies, fluxes and BG values
// TODO: Generalise this to taking vector<vector> as an argument

///////////////////////////////////////////////////////////////////////////////////////////////

enum quant{keff,kflux,kbg,kMAX};

///////////////////////////////////////////////////////////////////////////////////////////////

TMatrixDSym GetCovMatrix_Multisim(std::vector<double> Eff_v,std::vector<double> Flux_v,std::vector<double> BG_v,double Eff_CV,double Flux_CV,double BG_CV){

   std::vector<double> cv = {Eff_CV,Flux_CV,BG_CV};

   TMatrixDSym Cov(kMAX);

   int n_u = Eff_v.size();
   for(size_t i_u=0;i_u<n_u;i_u++){
      Cov[keff][keff] += (Eff_CV - Eff_v.at(i_u))*(Eff_CV - Eff_v.at(i_u))/n_u;
      Cov[kflux][kflux] += (Flux_CV - Flux_v.at(i_u))*(Flux_CV - Flux_v.at(i_u))/n_u; 
      Cov[kbg][kbg] += (BG_CV - BG_v.at(i_u))*(BG_CV - BG_v.at(i_u))/n_u; 
      Cov[keff][kflux] += (Eff_CV - Eff_v.at(i_u))*(Flux_CV - Flux_v.at(i_u))/n_u;
      Cov[keff][kbg] += (Eff_CV - Eff_v.at(i_u))*(BG_CV - BG_v.at(i_u))/n_u; 
      Cov[kflux][kbg] += (Flux_CV - Flux_v.at(i_u))*(BG_CV - BG_v.at(i_u))/n_u;
   }

   Cov[kflux][keff] = Cov[keff][kflux];
   Cov[kbg][keff] = Cov[keff][kbg];
   Cov[kbg][kflux] = Cov[kflux][kbg];

   return Cov;
}

///////////////////////////////////////////////////////////////////////////////////////////////

TMatrixDSym GetCovMatrix_SingleUnisim(std::vector<double> Eff_v,std::vector<double> Flux_v,std::vector<double> BG_v,double Eff_CV,double Flux_CV,double BG_CV){

   std::vector<double> cv = {Eff_CV,Flux_CV,BG_CV};

   TMatrixDSym Cov(kMAX);
   for(size_t i_u=0;i_u<Eff_v.size();i_u++){
      Cov[keff][keff] += (Eff_CV - Eff_v.at(i_u))*(Eff_CV - Eff_v.at(i_u));
      Cov[kflux][kflux] += (Flux_CV - Flux_v.at(i_u))*(Flux_CV - Flux_v.at(i_u)); 
      Cov[kbg][kbg] += (BG_CV - BG_v.at(i_u))*(BG_CV - BG_v.at(i_u)); 
      Cov[keff][kflux] += (Eff_CV - Eff_v.at(i_u))*(Flux_CV - Flux_v.at(i_u));
      Cov[keff][kbg] += (Eff_CV - Eff_v.at(i_u))*(BG_CV - BG_v.at(i_u)); 
      Cov[kflux][kbg] += (Flux_CV - Flux_v.at(i_u))*(BG_CV - BG_v.at(i_u));
   }

   Cov[kflux][keff] = Cov[keff][kflux];
   Cov[kbg][keff] = Cov[keff][kbg];
   Cov[kbg][kflux] = Cov[kflux][kbg];

   return Cov;
}

///////////////////////////////////////////////////////////////////////////////////////////////

TMatrixDSym GetCovMatrix_DualUnisim(std::vector<double> Eff_v,std::vector<double> Flux_v,std::vector<double> BG_v){

   TMatrixDSym Cov(kMAX);

   Cov[keff][keff] += (Eff_v.at(1) - Eff_v.at(0))*(Eff_v.at(1) - Eff_v.at(0))/4;
   Cov[kflux][kflux] +=  (Flux_v.at(1) - Flux_v.at(0))*(Flux_v.at(1) - Flux_v.at(0))/4;
   Cov[kbg][kbg] +=  (BG_v.at(1) - BG_v.at(0))*(BG_v.at(1) - BG_v.at(0))/4;
   Cov[keff][kflux] += (Eff_v.at(1) - Eff_v.at(0))*(Flux_v.at(1) - Flux_v.at(0))/4;
   Cov[keff][kbg] += (Eff_v.at(1) - Eff_v.at(0))*(BG_v.at(1) - BG_v.at(0))/4;
   Cov[kflux][kbg] += (Flux_v.at(1) - Flux_v.at(0))*(BG_v.at(1) - BG_v.at(0))/4;

   Cov[kflux][keff] = Cov[keff][kflux];
   Cov[kbg][keff] = Cov[keff][kbg];
   Cov[kbg][kflux] = Cov[kflux][kbg];

   return Cov;
}

///////////////////////////////////////////////////////////////////////////////////////////////

TMatrixDSym GetCovMatrix_DualUnisim(std::vector<std::vector<double>> Eff_v,std::vector<std::vector<double>> Flux_v,std::vector<std::vector<double>> BG_v){

   TMatrixDSym Cov(kMAX);

   for(size_t i_var=0;i_var<Eff_v.size();i_var++){
      Cov[keff][keff] += (Eff_v.at(i_var).at(1) - Eff_v.at(i_var).at(0))*(Eff_v.at(i_var).at(1) - Eff_v.at(i_var).at(0))/4;
      Cov[kflux][kflux] +=  (Flux_v.at(i_var).at(1) - Flux_v.at(i_var).at(0))*(Flux_v.at(i_var).at(1) - Flux_v.at(i_var).at(0))/4;
      Cov[kbg][kbg] +=  (BG_v.at(i_var).at(1) - BG_v.at(i_var).at(0))*(BG_v.at(i_var).at(1) - BG_v.at(i_var).at(0))/4;
      Cov[keff][kflux] += (Eff_v.at(i_var).at(1) - Eff_v.at(i_var).at(0))*(Flux_v.at(i_var).at(1) - Flux_v.at(i_var).at(0))/4;
      Cov[keff][kbg] += (Eff_v.at(i_var).at(1) - Eff_v.at(i_var).at(0))*(BG_v.at(i_var).at(1) - BG_v.at(i_var).at(0))/4;
      Cov[kflux][kbg] += (Flux_v.at(i_var).at(1) - Flux_v.at(i_var).at(0))*(BG_v.at(i_var).at(1) - BG_v.at(i_var).at(0))/4;
   } 

   Cov[kflux][keff] = Cov[keff][kflux];
   Cov[kbg][keff] = Cov[keff][kbg];
   Cov[kbg][kflux] = Cov[kflux][kbg];

   return Cov;
}

///////////////////////////////////////////////////////////////////////////////////////////////

#endif
