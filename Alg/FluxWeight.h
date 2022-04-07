#ifndef _FluxWeight_h_
#define _FluxWeight_h_

#include <iostream>
#include <map>

#include "TFile.h"
#include "TMatrixD.h"
#include "TH2D.h"

#include "Event.h"
#include "Misc.h"

const int flux_HP_universes = 600;
const int Beamline_Universes = 20;

enum modes{kFHC,kRHC};

// Beamline variations
/*
   enum beamline_vars { bv_HCU,  // HC +2kA 
   bv_HCD,  // HC -2kA
   bv_H1xU, // Horn 1 x position +3mm
   bv_H1xD, // Horn 1 x position -3mm
   bv_H1yU, // Horn 1 y position +3mm
   bv_H1yD, // Horn 1 y position -3mm
   bv_BSD,  // Beam spot size 1.1mm
   bv_BSU,  // Beam spot size 1.5mm
   bv_H2xU, // Horn 2 x position +3mm
   bv_H2xD, // Horn 2 x position -3mm
   bv_H2yU, // Horn 2 y position +3mm 
   bv_H2yD, // Horn 2 y position -3mm
   bv_HW0,  // 0mm water on horns
   bv_HW2,  // 2mm water on horns
   bv_BxU,  // beam shift x +1mm
   bv_BxD,  // beam shift x -1mm
   bv_ByU,  // beam shift y +1mm
   bv_ByD,  // beam shift y -1mm
   bv_TzU,  // target z position +7mm
   bv_TzD,  // target z position -7mm
   MAX_beamline_vars };
   */

inline std::string beamline_labels[Beamline_Universes/2] = {"HC","H1X","H1Y","BSS","H2X","H2Y","HW","BSX","BSY","TPZ"};

class FluxWeighter {

   public:

      enum flav { k_numu, k_numubar, k_nue, k_nuebar, k_FLAV_MAX };
      std::vector<std::string> flav_str = {"numu","numubar","nue","nuebar"};       

      //FluxWeighter(int RunPeriod);
      FluxWeighter(int mode);
      ~FluxWeighter();

      void PrepareHPUniv(int nuniv=600);
      void PrepareBeamlineUniv();

      // mode = 0 CV , mode = 1 HP universes , mode = 2 beamline variations
      double GetFluxWeight(double nu_e,double nu_angle,int nu_pdg,int mode=0,int univ=-1); 

      std::vector<double> GetSysWeightV(double nu_e,double nu_angle,int nu_pdg,int mode); 

      double GetFluxWeight(Event e);
      std::vector<double> GetSysWeightV(Event e,int mode);

   private:

      std::string FLUX_DIR;

      //int fRunPeriod;
      int fMode;
      std::string fRunMode;
      std::string fRunModeCaps;

      TFile *f_flux=nullptr;
      std::vector<TH2D*> hist_ratio;
      std::vector<TH2D*> hist_ratio_uw;       

      std::vector<TH2D> hist_CV;

      int HP_Universes = 0;
      std::vector<std::vector<TH2D*>> hist_sys_ratio;

      TFile *f_beamline_vars; 
      std::vector<std::vector<TH2D*>> hist_beamline_vars_ratio;

};

inline std::map<int,double> GetIntegratedFlux(int mode, int CV_HP_Beamline,double POT){

  assert(mode == kFHC || mode == kRHC);
  
  std::string BeamModeCaps = mode == kFHC ? "FHC" : "RHC";
  std::string BeamMode = mode == kFHC ? "fhc" : "rhc";
 
  std::cout << "BeamModeCaps = " << BeamModeCaps << std::endl;  
 
   // Get the flux histograms
   std::string FLUX_DIR = std::string(std::getenv("HYP_TOP")) + "Fluxes/";
   TFile *f_flux = TFile::Open((FLUX_DIR + "output_uboone_" + BeamMode + "_run0_merged.root").c_str());

   TH1D *h_numubar_flux;

   f_flux->GetObject("numubar/Detsmear/numubar_CV_AV_TPC",h_numubar_flux);

   for(int i=1;i<h_numubar_flux->GetNbinsX()+1;i++) h_numubar_flux->SetBinContent(i,h_numubar_flux->GetBinContent(i)/h_numubar_flux->GetBinWidth(i));

   h_numubar_flux->Scale(POT);

   std::map<int,double> univ_flux;

   if(CV_HP_Beamline == 0){
      univ_flux[0] =  h_numubar_flux->Integral("width")/100/100;
   }
   else if(CV_HP_Beamline == 1){
      // Calculate in HP universes
      std::vector<TH1D*> h_numubar_flux_HP(600);
      for(int i=0;i<600;i++){
         f_flux->GetObject(("numubar/Multisims/numubar_ppfx_ms_UBPPFX_Uni_" + std::to_string(i) + "_AV_TPC").c_str(),h_numubar_flux_HP[i]);
         for(int i_b=1;i_b<h_numubar_flux_HP[i]->GetNbinsX()+1;i_b++) h_numubar_flux_HP[i]->SetBinContent(i_b,h_numubar_flux_HP[i]->GetBinContent(i_b)/h_numubar_flux_HP[i]->GetBinWidth(i_b));
         h_numubar_flux_HP[i]->Scale(POT);
         univ_flux[i] = h_numubar_flux_HP[i]->Integral("width")/100/100;
      }
   }
   else {
      // Calculate in beamline geometry universes
      TFile *f_Beamline = TFile::Open((FLUX_DIR + "NuMI_Beamline_Variations_to_CV_Ratios.root").c_str());
      std::vector<TH1D*> h_numubar_flux_Beamline(20);
      std::vector<TH1D*> h_numubar_ratio_Beamline(20);       
      for(int i=0;i<20;i++){
         f_Beamline->GetObject(("EnergyVarBin/ratio_run" + std::to_string(i+1) + "_" + BeamModeCaps + "_numubar_CV_AV_TPC").c_str(),h_numubar_ratio_Beamline[i]);           
         h_numubar_flux_Beamline[i] = (TH1D*)h_numubar_flux->Clone(("h_numubar_flux_Beamline_" + std::to_string(i)).c_str());
         for(int i_b=1;i_b<h_numubar_flux->GetNbinsX()+1;i_b++) h_numubar_flux_Beamline.at(i)->SetBinContent(i_b,h_numubar_flux->GetBinContent(i_b)*h_numubar_ratio_Beamline.at(i)->GetBinContent(i_b));
         univ_flux[i] = h_numubar_flux_Beamline[i]->Integral("width")/100/100;
      }  
   }
   return univ_flux;
}




#endif
