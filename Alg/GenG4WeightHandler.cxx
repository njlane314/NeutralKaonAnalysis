#ifndef _GenG4WeightHandler_cxx_
#define _GenG4WeightHandler_cxx_

#include "GenG4WeightHandler.h"

///////////////////////////////////////////////////////////////////////////////////////////////

GenG4WeightHandler::GenG4WeightHandler(){

}

///////////////////////////////////////////////////////////////////////////////////////////////

void GenG4WeightHandler::LoadEvent(Event e){

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

void GenG4WeightHandler::OrganiseWeights(){

   std::vector<std::string> Dials_tmp;
   std::vector<std::vector<std::vector<double>>> Weights_tmp(theWeights->size());
   /*
   // Find all the unique dial names
   for(size_t i=0;i<theDials->size();i++)
   if (std::find(Dials_tmp.begin(), Dials_tmp.end(), theDials->at(i)) != Dials_tmp.end()) Dials_tmp.push_back(theDials->at(i));


   for(size_t i_tr=0;i_tr<theWeights->size();i_tr++){

   Weights_tmp.at(i_tr).resize(Dials_tmp.size());

   for(size_t i_d=0;i_d<theDials.size();i_d++){

   } 


   }
   */
/*
   for(size_t i_tr=0;i_tr<theWeights->size();i_tr++){

        std::cout << "Getting weights for truth " << i_tr << std::endl;

      // Collate the weights
      for(size_t i=0;i<theDials->size();i++){

         bool found = false;

         // Check if dial already exists
         for(size_t i_tmp=0;i_tmp<Dials_tmp.size();i_tmp++){
            if(Dials_tmp.at(i_tmp) == theDials->at(i)){
               found = true;
               Weights_tmp.at(i_tr).at(i_tmp).insert(Weights_tmp.at(i_tr).at(i_tmp).end(),theWeights->at(i_tr).at(i).begin(),theWeights->at(i_tr).at(i).end());
            }
         }

         // If new dial
         if(!found && theDials->at(i) != "empty"){
            Dials_tmp.push_back(theDials->at(i)); 
            Weights_tmp.at(i_tr).push_back(theWeights->at(i_tr).at(i));
         }
      }


      // Set any unphysical weights to 1
      for(size_t i_d=0;i_d<Dials_tmp.size();i_d++){
         for(size_t i_w=0;i_w<Weights_tmp.at(i_tr).at(i_d).size();i_w++){
            if (std::isinf(Weights_tmp.at(i_tr).at(i_d).at(i_w))) Weights_tmp.at(i_tr).at(i_d).at(i_w) = 1.0; 
            if (std::isnan(Weights_tmp.at(i_tr).at(i_d).at(i_w)) == 1) Weights_tmp.at(i_tr).at(i_d).at(i_w) = 1.0;
            if (Weights_tmp.at(i_tr).at(i_d).at(i_w) > 100) Weights_tmp.at(i_tr).at(i_d).at(i_w) = 1.0;
         }
      }

   }
   */

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

   // Replace original list of weights with collated list
   //*theDials = Dials_tmp;
   //*theWeights = Weights_tmp;

}

///////////////////////////////////////////////////////////////////////////////////////////////

double GenG4WeightHandler::GetCVWeight(){

   double weight = 1.0;

   for(size_t i_tr=0;i_tr<theWeights->size();i_tr++){

      std::map<std::string,std::vector<double>>::iterator it1;
      std::map<std::string,std::vector<double>>::iterator it2;
      std::map<std::string,std::vector<double>>::iterator it3;

      // Check CV weights exists, return 1 if any are missing
      it1 = theWeightMap.at(i_tr).find("TunedCentralValue_UBGenie"); if(it1 == theWeightMap.at(i_tr).end()) return 1;
      it2 = theWeightMap.at(i_tr).find("splines_general_Spline");    if(it2 == theWeightMap.at(i_tr).end()) return 1;
      it3 = theWeightMap.at(i_tr).find("RootinoFix_UBGenie");        if(it3 == theWeightMap.at(i_tr).end()) return 1;

      if(it1->second.size() != 1 || it2->second.size() != 1 || it3->second.size() != 1){
         std::cout << "Found CV weight vectors with size != 1" << std::endl;
         return 1;
      }

      double thisweight = it1->second.at(0)*it2->second.at(0)*it3->second.at(0); 

      // Add some catches to remove unphysical weights
      if (std::isinf(thisweight)) thisweight = 1.0; 
      if (std::isnan(thisweight) == 1) thisweight = 1.0;
      if (thisweight > 100) thisweight = 1.0;

      // return product of the three CV weights
      weight *= thisweight;
   }

   std::cout << weight << std::endl;

   return weight;
}

///////////////////////////////////////////////////////////////////////////////////////////////

std::vector<double> GenG4WeightHandler::GetWeights(std::string dialname){

   std::vector<double> weights;

   if(!theWeightMap.size()){
      std::cout << "No weights, returning empty vector" << std::endl;
      return weights;
   }

   std::map<std::string,std::vector<double>>::iterator it;
   it = theWeightMap.at(0).find(dialname); 

   if(it == theWeightMap.at(0).end()){
      std::cout << "Weights with label " << dialname << " not found, returning empty vector" << std::endl;
      return std::vector<double>();      
   }

   weights.resize(it->second.size());

   for(size_t i_w=0;i_w<weights.size();i_w++) 
      weights.at(i_w) = 1.0;
   

   for(size_t i_tr=0;i_tr<theWeightMap.size();i_tr++){

      it = theWeightMap.at(i_tr).find(dialname);

      if(it->second.size() != weights.size()){
         std::cout << "Weight vector size mismatch for dial " << dialname << " returning empty vector" << std::endl;
         return std::vector<double>();
      }

      for(size_t i_w=0;i_w<weights.size();i_w++)
         weights.at(i_w) *= it->second.at(i_w);
     
   }

   return weights;
}

#endif
