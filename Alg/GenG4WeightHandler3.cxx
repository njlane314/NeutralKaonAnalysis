#ifndef _GenG4WeightHandler3_cxx_
#define _GenG4WeightHandler3_cxx_

#include "GenG4WeightHandler3.h"

///////////////////////////////////////////////////////////////////////////////////////////////

GenG4WeightHandler3::GenG4WeightHandler3(){

}

///////////////////////////////////////////////////////////////////////////////////////////////

void GenG4WeightHandler3::LoadEvent(Event e){

   theWeightMap.clear();

   theDials = &e.SysDials;
   theWeights = &e.SysWeights;   

   // Check weight calculators were run
   if(theDials == nullptr || theWeights == nullptr){
      std::cout << "No weight products found, not loading Gen/G4 weights" << std::endl;
      return;
   }

   for(size_t i_d=0;i_d<theDials->size();i_d++)
      theWeightMap[theDials->at(i_d)] = theWeights->at(i_d); 
}

///////////////////////////////////////////////////////////////////////////////////////////////

double GenG4WeightHandler3::GetCVWeight(){

   double weight = 1.0;

   std::map<std::string,std::vector<double>>::iterator it;

   for(size_t i_d=0;i_d<CV_Dials.size();i_d++){
      it = theWeightMap.find(CV_Dials.at(i_d));
      if(it == theWeightMap.end())
         throw std::invalid_argument("GENIE tune dial " + CV_Dials.at(i_d) + " has no weights");
      weight *= it->second.at(0);
   }

   // Add some catches to remove unphysical weights
   if (std::isinf(weight)) weight = 1.0; 
   if (std::isnan(weight) == 1) weight = 1.0;
   if (weight > 100) weight = 1.0;
   return weight;
}

///////////////////////////////////////////////////////////////////////////////////////////////

std::vector<double> GenG4WeightHandler3::GetWeights(std::string dial){

   // which kind of weight are you trying to get?
   bool cv_dial = std::find(CV_Dials.begin(),CV_Dials.end(),dial) != CV_Dials.end(); 
   bool multisim = std::find(Multisim_Dials.begin(),Multisim_Dials.end(),dial) != Multisim_Dials.end(); 
   bool g4_dial = std::find(G4_Dials.begin(),G4_Dials.end(),dial) != G4_Dials.end(); 
   bool altmodel = std::find(AltModel_Dials.begin(),AltModel_Dials.end(),dial) != AltModel_Dials.end();
   bool ccqe_rpa = dial == "RPA_CCQE_UBGenie";

   std::vector<double> weights;

   if(!theWeightMap.size()){
      std::cout << "No weights, returning empty vector" << std::endl;
      return weights;
   }

   std::map<std::string,std::vector<double>>::iterator it;
   it = theWeightMap.find(dial); 

   if(it == theWeightMap.end())
      throw std::invalid_argument("GENIE/G4 weights with label " + dial + " not found");

   weights.resize(it->second.size());

   it = theWeightMap.find(dial);
   if(it->second.size() != weights.size())
      throw std::invalid_argument("GENIE/G4 weights with label " + dial + " has size mismatch");

   for(size_t i_w=0;i_w<weights.size();i_w++)
      weights.at(i_w) = it->second.at(i_w);   

   // Divide out the central value tune weight
   double tunedcentralvalue = theWeightMap.find("TunedCentralValue_UBGenie")->second.at(0);

   if(!g4_dial)      
      for(size_t i_w=0;i_w<weights.size();i_w++)
         weights.at(i_w) /= tunedcentralvalue;  

   if(cv_dial || multisim || ccqe_rpa) return weights;
   else if(altmodel){
      if(dial != "XSecShape_CCMEC_UBGenie") return {weights.at(0)};
      else  return {weights.at(1)};
   }
   else throw std::invalid_argument("GENIE/G4 dial " + dial + "is not CV, Multisim, AltModel or CCQE RPA");

   return weights;
}

///////////////////////////////////////////////////////////////////////////////////////////////

#endif
