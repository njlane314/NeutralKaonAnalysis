#ifndef _GenG4WeightHandler3_h_
#define _GenG4WeightHandler3_h_

#include <vector>
#include <map>

#include "Event.h"

const int GENIE_Multisim_Universes = 600;
const int G4_Multisim_Universes = 1000; 

// New setup

// Weights to be applied to give GENIE tune
const std::vector<std::string> CV_Dials = {"TunedCentralValue_UBGenie","splines_general_Spline","RootinoFix_UBGenie"};
const std::vector<std::string> AltModel_Dials = {"AxFFCCQEshape_UBGenie","DecayAngMEC_UBGenie","NormCCCOH_UBGenie","NormNCCOH_UBGenie","ThetaDelta2NRad_UBGenie","Theta_Delta2Npi_UBGenie","VecFFCCQEshape_UBGenie","XSecShape_CCMEC_UBGenie"};
const std::vector<std::string> G4_Dials = {"reinteractions_proton_Geant4","reinteractions_piplus_Geant4","reinteractions_piminus_Geant4","reinteractions_Lambda_Geant4"};
const std::vector<std::string> Multisim_Dials = {"All_UBGenie","reinteractions_proton_Geant4","reinteractions_piplus_Geant4","reinteractions_piminus_Geant4","reinteractions_Lambda_Geant4"};
 
class GenG4WeightHandler3 {

   public: 

      GenG4WeightHandler3();
      void LoadEvent(Event e);

      // Retrieve the central value weight for an event      
      double GetCVWeight();
      std::vector<double> GetWeights(std::string dial);

   private:

      bool HasWeights;
      std::vector<std::string> *theDials;
      std::vector<std::vector<double>> *theWeights;
      std::map<std::string,std::vector<double>> theWeightMap;     
      double EventTunedCentralValue = 1.0;

};

#endif
