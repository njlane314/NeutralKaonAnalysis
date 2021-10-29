#ifndef _GenG4WeightHandler_cxx_
#define _GenG4WeightHandler_cxx_

#include "GenG4WeightHandler.h"

///////////////////////////////////////////////////////////////////////////////////////////////

GenG4WeightHandler::GenG4WeightHandler(){

}

///////////////////////////////////////////////////////////////////////////////////////////////

void GenG4WeightHandler::LoadEvent(Event e){

   theWeightMap.clear();

   theDials = e.SysDials;
   theWeights = e.SysWeights;   

   // Check weight calculators were run
   if(theDials == nullptr || theWeights == nullptr) return;

   OrganiseWeights();

   for(size_t i=0;i<theDials->size();i++) theWeightMap[theDials->at(i)] = theWeights->at(i);
}

///////////////////////////////////////////////////////////////////////////////////////////////

void GenG4WeightHandler::OrganiseWeights(){

   std::vector<std::string> Dials_tmp;
   std::vector<std::vector<double>> Weights_tmp;

   // Collate the weights
   for(size_t i=0;i<theDials->size();i++){

      bool found = false;

      // Check if dial already exists
      for(size_t i_tmp=0;i_tmp<Dials_tmp.size();i_tmp++){
         if(Dials_tmp.at(i_tmp) == theDials->at(i)){
            found = true;
            Weights_tmp.at(i_tmp).insert(Weights_tmp.at(i_tmp).end(),theWeights->at(i).begin(),theWeights->at(i).end());
         }
      }

      // If new dial
      if(!found && theDials->at(i) != "empty"){
         Dials_tmp.push_back(theDials->at(i)); 
         Weights_tmp.push_back(theWeights->at(i));
      }
   }

   // Set any unphysical weights to 1
   for(size_t i_d=0;i_d<Dials_tmp.size();i_d++){
      for(size_t i_w=0;i_w<Weights_tmp.at(i_d).size();i_w++){
         if (std::isinf(Weights_tmp.at(i_d).at(i_w)))      Weights_tmp.at(i_d).at(i_w) = 1.0; 
         if (std::isnan(Weights_tmp.at(i_d).at(i_w)) == 1) Weights_tmp.at(i_d).at(i_w) = 1.0;
         if (Weights_tmp.at(i_d).at(i_w) > 100)            Weights_tmp.at(i_d).at(i_w) = 1.0;
      }
   }

   // Replace original list of weights with collated list
   *theDials = Dials_tmp;
   *theWeights = Weights_tmp;

}

///////////////////////////////////////////////////////////////////////////////////////////////

double GenG4WeightHandler::GetCVWeight(){

   std::map<std::string,std::vector<double>>::iterator it1;
   std::map<std::string,std::vector<double>>::iterator it2;
   std::map<std::string,std::vector<double>>::iterator it3;

   // Check CV weights exists, return 1 if any are missing
   it1 = theWeightMap.find("TunedCentralValue_UBGenie"); if(it1 == theWeightMap.end()) return 1;
   it2 = theWeightMap.find("splines_general_Spline");    if(it2 == theWeightMap.end()) return 1;
   it3 = theWeightMap.find("RootinoFix_UBGenie");        if(it3 == theWeightMap.end()) return 1;

   if(it1->second.size() != 1 || it2->second.size() != 1 || it3->second.size() != 1){
      std::cout << "Found CV weight vectors with size != 1" << std::endl;
      return 1;
   }

   double weight = it1->second.at(0)*it2->second.at(0)*it3->second.at(0); 

   // Add some catches to remove unphysical weights
   if (std::isinf(weight))      weight = 1.0; 
   if (std::isnan(weight) == 1) weight = 1.0;
   if (weight > 100)            weight = 1.0;

   // return product of the three CV weights
   return weight;

}

///////////////////////////////////////////////////////////////////////////////////////////////

std::vector<double> GenG4WeightHandler::GetWeights(std::string dialname){

   std::map<std::string,std::vector<double>>::iterator it;
   it = theWeightMap.find(dialname); 

   if(it == theWeightMap.end()){
      std::cout << "Weights with label " << dialname << " not found, returning empty vector" << std::endl;
      return std::vector<double>();      
   }

   return it->second; 

}

#endif
