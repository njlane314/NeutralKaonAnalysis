#ifndef _FluxWeight_cxx_
#define _FluxWeight_cxx_

#include "FluxWeight.h"

using namespace FluxWeight;

///////////////////////////////////////////////////////////////////////////////////////////////

FluxWeighter::FluxWeighter(int RunPeriod){

   // Presently only have weights for run 1 and 3
   if(RunPeriod != 1 && RunPeriod != 3){
      std::cout << "Requesting flux weights for unknown run period, setting all flux weights to 1" << std::endl;
      fRunPeriod = RunPeriod;
      return;
   }

      fRunPeriod = RunPeriod;

   if (fRunPeriod == 1)
      f_flux = TFile::Open("/home/lar/cthorpe/uboone/hyperons/Alg/FluxHists/output_uboone_fhc_run0_merged.root", "READ");
   else if (fRunPeriod == 3)
      f_flux = TFile::Open("/home/lar/cthorpe/uboone/hyperons/Alg/FluxHists/output_uboone_rhc_run0_merged.root", "READ");
   else
      return;


   hist_ratio.resize(k_FLAV_MAX);
   hist_ratio_uw.resize(k_FLAV_MAX);

   // Get the flux histograms
   for (unsigned int f = 0; f < flav_str.size(); f++){
      hist_ratio.at(f)      = (TH2D*) f_flux->Get(Form("%s/Detsmear/%s_CV_AV_TPC_2D", flav_str.at(f).c_str(), flav_str.at(f).c_str()));
      hist_ratio_uw.at(f)   = (TH2D*) f_flux->Get(Form("%s/Detsmear/%s_unweighted_AV_TPC_2D", flav_str.at(f).c_str(), flav_str.at(f).c_str()));

      hist_ratio.at(f)->SetDirectory(0);
      hist_ratio_uw.at(f)->SetDirectory(0);

      // Take the ratio
      hist_ratio.at(f)->Divide(hist_ratio_uw.at(f));

   }

}

///////////////////////////////////////////////////////////////////////////////////////////////

double FluxWeighter::GetFluxWeight(double nu_e,double nu_angle,int nu_pdg){

   if(fRunPeriod != 1 && fRunPeriod != 3) return 1.0;

   float weight = 1.0;

   double xbin{1.0},ybin{1.0};

   if (nu_pdg == 14) {
      xbin =  hist_ratio.at(k_numu)->GetXaxis()->FindBin(nu_e);
      ybin =  hist_ratio.at(k_numu)->GetYaxis()->FindBin(nu_angle);
      weight =  hist_ratio.at(k_numu)->GetBinContent(xbin, ybin);
   }
   if (nu_pdg == -14) {
      xbin =  hist_ratio.at(k_numubar)->GetXaxis()->FindBin(nu_e);
      ybin = hist_ratio.at(k_numubar)->GetYaxis()->FindBin(nu_angle);
      weight = hist_ratio.at(k_numubar)->GetBinContent(xbin, ybin);
   }
   if (nu_pdg == 12) {
      xbin = hist_ratio.at(k_nue)->GetXaxis()->FindBin(nu_e);
      ybin = hist_ratio.at(k_nue)->GetYaxis()->FindBin(nu_angle);
      weight = hist_ratio.at(k_nue)->GetBinContent(xbin, ybin);
   }
   if (nu_pdg == -12) {
      xbin = hist_ratio.at(k_nuebar)->GetXaxis()->FindBin(nu_e);
      ybin = hist_ratio.at(k_nuebar)->GetYaxis()->FindBin(nu_angle);
      weight = hist_ratio.at(k_nuebar)->GetBinContent(xbin, ybin);
   }

   // Add some catches to remove unphysical weights
   if (std::isinf(weight))      weight = 1.0; 
   if (std::isnan(weight) == 1) weight = 1.0;
   if (weight > 100)            weight = 1.0;

   return  weight;

}

///////////////////////////////////////////////////////////////////////////////////////////////

FluxWeighter::~FluxWeighter(){

   if(f_flux != nullptr){
      f_flux->Close();
      delete f_flux;       
   }


   hist_ratio.clear();
   hist_ratio_uw.clear(); 

}

///////////////////////////////////////////////////////////////////////////////////////////////

#endif
