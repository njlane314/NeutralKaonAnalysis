#ifndef _GenG4WeightHandler_h_
#define _GenG4WeightHandler_h_

#include <vector>
#include <map>

#include "Event.h"

enum GenUnisims { gv_AxFFCCQEshape,   // z expansion of axial form factor
                  gv_DecayAngMEC,     // non-isotropic MEC decay
                  gv_NormCCCOH,       // 2x CCCOH xsec
                  gv_NormNCCOH,       // 2x NCCOH xsec
                  gv_ThetaDelta2NRad, // non-isotropic Delta radiative decay
                  gv_Theta_Delta2Npi, // non-isotropic Delta hadronic decay
                  gv_VecFFCCQEshape,  // Use dipole FF for CCQE
                  gv_XSecShape_CCMEC, // Use Valencia MEC
                  gv_RPA_CCQE_Up,     // CCQE RPA +1 sigma
                  gv_RPA_CCQE_Down,   // CCQE RPA -1 sigma
                  MAX_GenUnisims }; 

inline std::string GenUnisim_dials[MAX_GenUnisims-1] = {"CCQE Axial FF Shape","MEC Decay Angle","CCCOH Norm","NCCOH Norm","DeltaRad Angle","DeltaHad Angle","CCQE Dipole","Valencia MEC","CCQE RPA"};
inline std::string GenUnisim_names[MAX_GenUnisims-1] = {"AxFFCCQEshape_UBGenie","DecayAngMEC_UBGenie","NormCCCOH_UBGenie","NormNCCOH_UBGenie","ThetaDelta2NRad_UBGenie","Theta_Delta2Npi_UBGenie","VecFFCCQEshape_UBGenie","XSecShape_CCMEC_UBGenie","RPA_CCQE_UBGenie"};


enum G4Multisims { g4v_Proton,g4v_PiPlus,g4v_PiMinus,g4v_Neutron,g4v_Lambda,MAX_G4Multisims };

inline std::string G4Multisim_dials[MAX_G4Multisims] = {"Proton Reinteractions","PiPlus Reinteractions","PiMinus Reinteractions","Neutron Reinteractions","Lambda Reinteractions"};
inline std::string G4Multisim_names[MAX_G4Multisims] = {"reinteractions_proton_Geant4","reinteractions_piplus_Geant4","reinteractions_piminus_Geant4","reinteractions_neutron_Geant4","reinteractions_Lambda_Geant4"};

class GenG4WeightHandler {

   public: 

      GenG4WeightHandler();
      void LoadEvent(Event e);

      // Retrieve the central value weight for an event      
      double GetCVWeight();

      std::vector<double> GetWeights(std::string dialname);

   private:

      bool HasWeights;

      void OrganiseWeights();

      std::vector<std::string> *theDials;
      std::vector<std::vector<std::vector<double>>> *theWeights;
      std::vector<std::map<std::string,std::vector<double>>> theWeightMap;
     
};

#endif
