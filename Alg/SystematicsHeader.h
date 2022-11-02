#ifndef _SystematicsHeader_h_
#define _SystematicsHeader_h_

#include "FluxWeight2.h"
#include "GenG4WeightHandler3.h"

enum Systemtic_Types {kMultisim,kSingleUnisim,kDualUnisim};

// Lots of information about systematics

// Histogram components 
enum Components{kSignal,kOtherHYP,kOtherNu,kDirt,kEXT,COMPONENTS_MAX};
const std::vector<std::string> Components_Str = {"Signal","OtherHYP","OtherNu","Dirt","EXT"};
const std::vector<std::string> Captions_Str = {"Signal","Other HYP","Other #nu","Dirt","EXT"};

// Histogram components with alternative categories
enum Components2{k2DirectLambda,k2DirectHYP,k2Neutron,k2Dirt,k2RESLambda,k2RESHYP,k2Other,k2EXT,k2DISLambda,k2DISHYP,COMPONENTS2_MAX};
const std::vector<std::string> Components_Str2 = {"DirectLambda","DirectHYP","Neutron","Dirt","RESLambda","RESHYP","Other","EXT","DISLambda","DISHYP"};
const std::vector<std::string> Captions_Str2 = {"Direct #Lambda","Direct Hyp","Neutron","Dirt","RES #Lambda","RES Hyp","Other #nu","EXT","DIS #Lambda","DIS Hyp"};

// Different systematic categories
enum Systematics{sFlux,sGenerator,sReint,sDetector,sMisc,sMAX};
const std::vector<std::string> Systematics_Str = {"Flux","Gen","G4","Detector","Misc"};

// Group the systematics together, setup emums, labels, figure captions, number of universes and type of systematic

// Flux systematics
enum FluxU{fuFlux_HP,fuHC,fuH1X,fuH1Y,fuBSS,fuH2X,fuH2Y,fuHW,fuBSX,fuBSY,fuTPZ,fuPOT,fuMAX};
const std::vector<std::string> FluxU_Str = {"Flux_HP","HC","H1X","H1Y","BSS","H2X","H2Y","HW","BSX","BSY","TPZ","POT"};
const std::vector<std::string> FluxU_Str_Long = {"Hadron Production","Horn Current","Horn 1 X","Horn 1 Y","Beam Spot Size","Horn 2 X","Horn 2 Y","Horn Water","Beam Spot X","Beam Spot Y","Target Pos. Z","POT"};
const std::vector<int> FluxU_Universes = {Flux_HP_Universes,2,2,2,2,2,2,2,2,2,2,2};
const std::vector<int> FluxU_SysTypes = {kMultisim,kDualUnisim,kDualUnisim,kDualUnisim,kDualUnisim,kDualUnisim,kDualUnisim,kDualUnisim,kDualUnisim,kDualUnisim,kDualUnisim,kDualUnisim};

// Generator systematics
enum GeneratorU{guAll_UBGenie,guAxFFCCQEshape_UBGenie,guDecayAngMEC_UBGenie,guNormCCCOH_UBGenie,guNormNCCOH_UBGenie,guThetaDelta2NRad_UBGenie,guTheta_Delta2Npi_UBGenie,guVecFFCCQEshape_UBGenie,guXSecShape_CCMEC_UBGenie,guRPA_CCQE_UBGenie,guMAX};
const std::vector<std::string> GeneratorU_Str = {"All_UBGenie","AxFFCCQEshape_UBGenie","DecayAngMEC_UBGenie","NormCCCOH_UBGenie","NormNCCOH_UBGenie","ThetaDelta2NRad_UBGenie","Theta_Delta2Npi_UBGenie","VecFFCCQEshape_UBGenie","XSecShape_CCMEC_UBGenie","RPA_CCQE_UBGenie"};
const std::vector<std::string> GeneratorU_Str_Long = {"Multisim","CCQE Ax. Shape","MEC Decay Ang.","CCCOH Norm.","NCCOH Norm.","#Delta Rad Angle.","#Delta Had Angle.","CCQE Vec. Shape","CCMEC Shape","CCQE RPA"};
const std::vector<int> GeneratorU_Universes = {GENIE_Multisim_Universes,1,1,1,1,1,1,1,1,2}; 
const std::vector<int> GeneratorU_SysTypes = {kMultisim,kSingleUnisim,kSingleUnisim,kSingleUnisim,kSingleUnisim,kSingleUnisim,kSingleUnisim,kSingleUnisim,kSingleUnisim,kDualUnisim};

// Reinteraction systematics
enum ReintU{g4uG4_Proton,g4uG4_PiPlus,g4uG4_PiMinus,g4uG4_Lambda,g4uG4_Neutron,g4uMAX};
const std::vector<std::string> ReintU_Str = {"G4_Proton","G4_PiPlus","G4_PiMinus","G4_Lambda","G4_Neutron_Dual"};
const std::vector<std::string> ReintU_Str_Long = {"Proton","#pi^{+}","#pi^{-}","#Lambda","Neutron"};
const std::vector<int> ReintU_Universes = {G4_Multisim_Universes,G4_Multisim_Universes,G4_Multisim_Universes,G4_Multisim_Universes,2};
const std::vector<int> ReintU_SysTypes = {kMultisim,kMultisim,kMultisim,kMultisim,kDualUnisim};

// Detector systematics
enum DetectorU{duLYAttenuation,duLYDown,duLYRayleigh,duSCE,duRecomb2,duWireModX,duWireModYZ,duWireModThetaXZ,duWireModThetaYZ,duMAX};
const std::vector<std::string> DetectorU_Str = {"LYAttenuation","LYDown","LYRayleigh","SCE","Recomb2","WireModX","WireModYZ","WireModThetaXZ","WireModThetaYZ"};
const std::vector<std::string> DetectorU_Str_Long = {"LY Att.","LY Down","LY Rayleigh","SCE","Recomb.","Wire Mod X","Wire Mod YZ","Wire Mod #theta XZ","Wire Mod #theta YZ"};
const std::vector<int> DetectorU_Universes = {1,1,1,1,1,1,1,1,1};
const std::vector<int> DetectorU_SysTypes = {kSingleUnisim,kSingleUnisim,kSingleUnisim,kSingleUnisim,kSingleUnisim,kSingleUnisim,kSingleUnisim,kSingleUnisim,kSingleUnisim};

// Misc systematics
enum MiscU{muDirtScale,muMAX};
const std::vector<std::string> MiscU_Str = {"DirtScale"};
const std::vector<std::string> MiscU_Str_Long = {"Dirt Scaling"};
const std::vector<int> MiscU_Universes = {2};
const std::vector<int> MiscU_SysTypes = {kDualUnisim};

#endif
