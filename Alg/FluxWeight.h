#ifndef _FluxWeight_h_
#define _FluxWeight_h_

#include <iostream>

#include "TFile.h"
#include "TMatrixD.h"
#include "TH2D.h"

#include "Event.h"
#include "Misc.h"

// Beamline variations
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

 inline std::string beamline_dials[MAX_beamline_vars/2] = {"Horn Current","Horn 1 X Position","Horn 1 Y Position","Beam Spot Size","Horn 2 X Position","Horn 2 Y Position","Horn Water","Beam Shift X","Beam Shift Y","Target Position Z"}; 

class FluxWeighter {

   public:

      enum flav { k_numu, k_numubar, k_nue, k_nuebar, k_FLAV_MAX };
      std::vector<std::string> flav_str = {"numu","numubar","nue","nuebar"};       

      FluxWeighter(int RunPeriod);
      ~FluxWeighter();

      void PrepareSysUniv(int nuniv=600);

      // mode = 0 CV , mode = 1 HP universes , mode = 2 beamline variations
      double GetFluxWeight(double nu_e,double nu_angle,int nu_pdg,int mode=0,int univ=-1); 

      std::vector<double> GetSysWeightV(double nu_e,double nu_angle,int nu_pdg,int mode); 

      double GetFluxWeight(Event e);
      std::vector<double> GetSysWeightV(Event e,int mode);


   private:

      int fRunPeriod;
      std::string fRunMode;
      std::string fRunModeCaps;

      TFile *f_flux=nullptr;
      std::vector<TH2D*> hist_ratio;
      std::vector<TH2D*> hist_ratio_uw;       

      std::vector<TH2D> hist_CV;

      int HP_Universes = 0;
      std::vector<std::vector<TH2D*>> hist_sys_ratio;


      int Beamline_Universes = 0;
      //std::vector<TFile*> f_beamline_vars;
      TFile *f_beamline_vars; 
      std::vector<std::vector<TH2D*>> hist_beamline_vars_ratio;

};

#endif
