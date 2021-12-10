#ifndef _FluxWeight_cxx_
#define _FluxWeight_cxx_

#include "FluxWeight.h"

///////////////////////////////////////////////////////////////////////////////////////////////

FluxWeighter::FluxWeighter(int RunPeriod){

   FLUX_DIR = std::string(std::getenv("HYP_TOP")) + "Fluxes/";

   // Presently only have weights for run 1 and 3
   if(RunPeriod != 1 && RunPeriod != 3){
      std::cout << "Requesting flux weights for unknown run period, setting all flux weights to 1" << std::endl;
      fRunPeriod = RunPeriod;
      return;
   }

      fRunPeriod = RunPeriod;
       
      if(RunPeriod == 1){ fRunMode = "fhc"; fRunModeCaps = "FHC"; }
      else if(RunPeriod == 3){ fRunMode = "rhc"; fRunModeCaps = "RHC"; }

   if (fRunPeriod == 1)
        f_flux = TFile::Open((FLUX_DIR + "output_uboone_fhc_run0_merged.root").c_str(), "READ");               
   else if (fRunPeriod == 3)
        f_flux = TFile::Open((FLUX_DIR + "output_uboone_rhc_run0_merged.root").c_str(), "READ");               
   else
      return;


   hist_ratio.resize(k_FLAV_MAX);
   hist_ratio_uw.resize(k_FLAV_MAX);
   hist_CV.resize(k_FLAV_MAX);

   // Get the flux histograms
   for (unsigned int f = 0; f < flav_str.size(); f++){
      hist_ratio.at(f)      = (TH2D*) f_flux->Get(Form("%s/Detsmear/%s_CV_AV_TPC_2D", flav_str.at(f).c_str(), flav_str.at(f).c_str()));
      hist_ratio_uw.at(f)   = (TH2D*) f_flux->Get(Form("%s/Detsmear/%s_unweighted_AV_TPC_2D", flav_str.at(f).c_str(), flav_str.at(f).c_str()));

      hist_CV.at(f) = *(TH2D*) f_flux->Get(Form("%s/Detsmear/%s_CV_AV_TPC_2D", flav_str.at(f).c_str(), flav_str.at(f).c_str()));      

      hist_ratio.at(f)->SetDirectory(0);
      hist_ratio_uw.at(f)->SetDirectory(0);

      // Take the ratio
      hist_ratio.at(f)->Divide(hist_ratio_uw.at(f));

   }

}

///////////////////////////////////////////////////////////////////////////////////////////////

double FluxWeighter::GetFluxWeight(double nu_e,double nu_angle,int nu_pdg,int mode,int univ){

   if(fRunPeriod != 1 && fRunPeriod != 3) return 1.0;

   float weight = 1.0;

   double xbin{1.0},ybin{1.0};

   if (nu_pdg == 14) {
      xbin =  hist_ratio.at(k_numu)->GetXaxis()->FindBin(nu_e);
      ybin =  hist_ratio.at(k_numu)->GetYaxis()->FindBin(nu_angle);

      if(mode == 0)  weight = hist_ratio.at(k_numu)->GetBinContent(xbin, ybin);
      else if(mode == 1) weight = hist_sys_ratio.at(k_numu).at(univ)->GetBinContent(xbin, ybin);
      else if(mode == 2) weight = hist_beamline_vars_ratio.at(k_numu).at(univ)->GetBinContent(xbin, ybin);
      else return 1.0;
   }
   if (nu_pdg == -14) {
      xbin =  hist_ratio.at(k_numubar)->GetXaxis()->FindBin(nu_e);
      ybin = hist_ratio.at(k_numubar)->GetYaxis()->FindBin(nu_angle);

      if(mode == 0)  weight = hist_ratio.at(k_numubar)->GetBinContent(xbin, ybin);
      else if(mode == 1) weight = hist_sys_ratio.at(k_numubar).at(univ)->GetBinContent(xbin, ybin);
      else if(mode == 2) weight = hist_beamline_vars_ratio.at(k_numubar).at(univ)->GetBinContent(xbin, ybin);
      else return 1.0;
   }
   if (nu_pdg == 12) {
      xbin = hist_ratio.at(k_nue)->GetXaxis()->FindBin(nu_e);
      ybin = hist_ratio.at(k_nue)->GetYaxis()->FindBin(nu_angle);

      if(mode == 0)  weight = hist_ratio.at(k_nue)->GetBinContent(xbin, ybin);
      else if(mode == 1) weight = hist_sys_ratio.at(k_nue).at(univ)->GetBinContent(xbin, ybin);
      else if(mode == 2) weight = hist_beamline_vars_ratio.at(k_nue).at(univ)->GetBinContent(xbin, ybin);
      else return 1.0;

   }
   if (nu_pdg == -12) {
      xbin = hist_ratio.at(k_nuebar)->GetXaxis()->FindBin(nu_e);
      ybin = hist_ratio.at(k_nuebar)->GetYaxis()->FindBin(nu_angle);

      if(mode == 0)  weight = hist_ratio.at(k_nuebar)->GetBinContent(xbin, ybin);
      else if(mode == 1) weight = hist_sys_ratio.at(k_nuebar).at(univ)->GetBinContent(xbin, ybin);
      else if(mode == 2) weight = hist_beamline_vars_ratio.at(k_nuebar).at(univ)->GetBinContent(xbin, ybin);
      else return 1.0;

   }

   // Add some catches to remove unphysical weights
   if (std::isinf(weight))      weight = 1.0; 
   if (std::isnan(weight) == 1) weight = 1.0;
   if (weight > 100)            weight = 1.0;

   return  weight;

}

//////////////////////////////////////////////////////////////////////////////////////////////

double FluxWeighter::GetFluxWeight(Event e){

   if(!e.Neutrino.size()) return 1.0;

   double weight = 1.0;

   // Get weight for each neutrino and multiply together
   for(size_t i_n=0;i_n<e.Neutrino.size();i_n++){

   double nu_e = e.Neutrino.at(i_n).E;
   double nu_angle = GetNuMIAngle(e.Neutrino.at(i_n).Px,e.Neutrino.at(i_n).Py,e.Neutrino.at(i_n).Pz);
   int nu_pdg = e.Neutrino.at(i_n).PDG;

   weight *= GetFluxWeight(nu_e,nu_angle,nu_pdg);

   }

   //return GetFluxWeight(nu_e,nu_angle,nu_pdg);
   return weight;

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

void FluxWeighter::PrepareHPUniv(int nuniv){

   std::cout << "Loading Flux HP_Universes" << std::endl;


   hist_sys_ratio.resize(flav_str.size());
   
   for (unsigned int f = 0; f < flav_str.size(); f++)
      hist_sys_ratio.at(f).resize(nuniv);

   for (unsigned int f = 0; f < flav_str.size(); f++){
      for(size_t i_univ=0;i_univ<nuniv;i_univ++){

        //std::cout << "Loading HP histogram for flavour " << flav_str.at(f) << " universe " << i_univ << std::endl;

         hist_sys_ratio.at(f).at(i_univ) = (TH2D*) f_flux->Get(Form("%s/Multisims/%s_ppfx_ms_UBPPFX_Uni_%s_AV_TPC_2D", flav_str.at(f).c_str(), flav_str.at(f).c_str(),std::to_string(i_univ).c_str()));

        
      hist_sys_ratio.at(f).at(i_univ)->Divide(hist_ratio_uw.at(f));

      }
   }

   HP_Universes = nuniv;

}

///////////////////////////////////////////////////////////////////////////////////////////////

void FluxWeighter::PrepareBeamlineUniv(){

   // Load the beamline variations

   std::cout << "Loading beamline variation universes" << std::endl;
  
   //f_beamline_vars.resize(Beamline_Universes);  
   f_beamline_vars = TFile::Open((FLUX_DIR + "NuMI_Beamline_Variations_to_CV_Ratios.root").c_str());
   hist_beamline_vars_ratio.resize(flav_str.size());

   for (unsigned int f = 0; f < flav_str.size(); f++){       
      hist_beamline_vars_ratio.at(f).resize(Beamline_Universes);  
      for(unsigned int bv=0;bv<Beamline_Universes;bv++){
         std::string histname = "EnergyTheta2D/ratio_run" + std::to_string(bv+1) + "_" + fRunModeCaps + "_" + flav_str.at(f) + "_CV_AV_TPC_2D"; 
         hist_beamline_vars_ratio.at(f).at(bv) = (TH2D*) f_beamline_vars->Get(histname.c_str());
      }
   }

}

///////////////////////////////////////////////////////////////////////////////////////////////

std::vector<double> FluxWeighter::GetSysWeightV(double nu_e,double nu_angle,int nu_pdg,int mode){

   std::vector<double> weights;

   if(mode == 1)  for(size_t i_univ=0;i_univ<HP_Universes;i_univ++) weights.push_back(GetFluxWeight(nu_e,nu_angle,nu_pdg,mode,i_univ));
   else if(mode == 2) for(size_t i_univ=0;i_univ<Beamline_Universes;i_univ++) weights.push_back(GetFluxWeight(nu_e,nu_angle,nu_pdg,mode,i_univ));

   return weights;

}

///////////////////////////////////////////////////////////////////////////////////////////////

std::vector<double> FluxWeighter::GetSysWeightV(Event e,int mode){

   std::vector<double> weights;
   if(mode == 1)for(size_t i_univ=0;i_univ<HP_Universes;i_univ++) weights.push_back(1.0);
   else if(mode == 2)for(size_t i_univ=0;i_univ<Beamline_Universes;i_univ++) weights.push_back(1.0);        


   // If no neutrinos simulated, return vector of 1's
   if(!e.Neutrino.size()) return weights;

   for(size_t i_tr=0;i_tr<e.Neutrino.size();i_tr++){ 

      double nu_e = e.Neutrino.at(0).E;
      double nu_angle = GetNuMIAngle(e.Neutrino.at(0).Px,e.Neutrino.at(0).Py,e.Neutrino.at(0).Pz);
      int nu_pdg = e.Neutrino.at(0).PDG;

      std::vector<double> weights_thistruth = GetSysWeightV(nu_e,nu_angle,nu_pdg,mode);

      for(size_t i_w=0;i_w<weights.size();i_w++) weights.at(i_w) *= weights_thistruth.at(i_w); 

   }

   return weights;

}

///////////////////////////////////////////////////////////////////////////////////////////////

#endif
