#ifndef _GenG4WeightHandler2_cxx_
#define _GenG4WeightHandler2_cxx_

#include "GenG4WeightHandler2.h"

using namespace GW2;

///////////////////////////////////////////////////////////////////////////////////////////////

GenG4WeightHandler2::GenG4WeightHandler2(){

}

///////////////////////////////////////////////////////////////////////////////////////////////

void GenG4WeightHandler2::LoadEvent(Event e){

   theWeightMap.clear();

   theDials = &e.SysDials;
   theWeights = &e.SysWeights;   

   // Check weight calculators were run
   if(theDials == nullptr || theWeights == nullptr){
      std::cout << "No weight products found, not loading Gen/G4 weights" << std::endl;
      return;
   }

   OrganiseWeights();

   theWeightMap.resize(theWeights->size());

   for(size_t i_tr=0;i_tr<theWeights->size();i_tr++)        
      for(size_t i=0;i<theDials->size();i++)
         theWeightMap.at(i_tr)[theDials->at(i)] = theWeights->at(i_tr).at(i);

}

///////////////////////////////////////////////////////////////////////////////////////////////

void GenG4WeightHandler2::OrganiseWeights(){

   std::vector<std::string> Dials_tmp;
   std::vector<std::vector<std::vector<double>>> Weights_tmp(theWeights->size());

   // remove unphysical weights
   for(size_t i_d=0;i_d<theDials->size();i_d++){
      for(size_t i_tr=0;i_tr<theWeights->size();i_tr++){
         for(size_t i_u=0;i_u<theWeights->at(i_tr).at(i_d).size();i_u++){

            if (std::isinf(theWeights->at(i_tr).at(i_d).at(i_u))) theWeights->at(i_tr).at(i_d).at(i_u) = 1.0; 
            if (std::isnan(theWeights->at(i_tr).at(i_d).at(i_u)) == 1) theWeights->at(i_tr).at(i_d).at(i_u) = 1.0;
            if (theWeights->at(i_tr).at(i_d).at(i_u) > 100) theWeights->at(i_tr).at(i_d).at(i_u) = 1.0;


         }
      }
   }
}

///////////////////////////////////////////////////////////////////////////////////////////////

double GenG4WeightHandler2::GetCVWeight(){

   double weight = 1.0;

   for(size_t i_tr=0;i_tr<theWeights->size();i_tr++){ 

      double thistruthweight = 1.0; 
      std::map<std::string,std::vector<double>>::iterator it;

      for(size_t i_d=0;i_d<CV_Dials.size();i_d++){
         it = theWeightMap.at(i_tr).find(CV_Dials.at(i_d));
         if(it == theWeightMap.at(i_tr).end())
            throw std::invalid_argument("GENIE tune dial " + CV_Dials.at(i_d) + " has no weights");
         thistruthweight *= it->second.at(0);
      }

      // Add some catches to remove unphysical weights
      if (std::isinf(thistruthweight)) thistruthweight = 1.0; 
      if (std::isnan(thistruthweight) == 1) thistruthweight = 1.0;
      if (thistruthweight > 100) thistruthweight = 1.0;

      // return product of the three CV weights
      weight *= thistruthweight;
   }

   return weight;
}

///////////////////////////////////////////////////////////////////////////////////////////////

std::vector<double> GenG4WeightHandler2::GetWeights(std::string dial){

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
   it = theWeightMap.at(0).find(dial); 

   if(it == theWeightMap.at(0).end())
      throw std::invalid_argument("GENIE/G4 weights with label " + dial + " not found");
   
   weights.resize(it->second.size());

   for(size_t i_w=0;i_w<weights.size();i_w++) 
      weights.at(i_w) = 1.0;
   
   for(size_t i_tr=0;i_tr<theWeightMap.size();i_tr++){
      it = theWeightMap.at(i_tr).find(dial);
      if(it->second.size() != weights.size())
         throw std::invalid_argument("GENIE/G4 weights with label " + dial + " has size mismatch");

      for(size_t i_w=0;i_w<weights.size();i_w++)
         weights.at(i_w) *= it->second.at(i_w);   

      // Divide out the central value tune weight
      double tunedcentralvalue = theWeightMap.at(i_tr).find("TunedCentralValue_UBGenie")->second.at(0);
      if(!g4_dial)      
         for(size_t i_w=0;i_w<weights.size();i_w++)
            weights.at(i_w) /= tunedcentralvalue;  
   }

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
