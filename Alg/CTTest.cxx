#ifndef _CTTest_cxx_
#define _CTTest_cxx_

#include "CTTest.h"

///////////////////////////////////////////////////////////////////////////////////////////////

CTTest::CTTest(int plane){

   fPlane = plane;

   // Load the dead wire maps

   std::cout << "Getting dead channel lists" << std::endl;

   std::string HYP_TOP = std::getenv("HYP_TOP");

   std::ifstream input_DeadChannels(HYP_TOP + "/Alg/DeadWireMaps/Plane" + std::to_string(fPlane) + ".txt");

   int dead;

   while(!input_DeadChannels.eof()){ input_DeadChannels >> dead; DeadChannels.push_back(dead); }

   std::cout << "Found " << DeadChannels.size() << " dead channels in Plane " << fPlane << std::endl;

}

///////////////////////////////////////////////////////////////////////////////////////////////

void CTTest::LoadInfo(std::vector<std::vector<int>> seedindexes,std::vector<std::vector<int>> outputindexes,std::vector<std::vector<int>> outputsizes,std::vector<std::vector<int>> seedchannels){

   SeedIndexes = seedindexes;
   OutputIndexes = outputindexes;
   OutputSizes = outputsizes;
   SeedChannels = seedchannels;
}

///////////////////////////////////////////////////////////////////////////////////////////////

bool CTTest::DoTest(int muonindex,int pionplusindex,int pionminusindex){

   // Get the entry of the vectors corresponding to that combination of seeds

   int test_index=-1;

   for(size_t i=0;i<SeedIndexes.size();i++){

      bool found_muon=false,found_pion_plus=false,found_pion_minus=false;

      for(int j=0;j<3;j++) if(SeedIndexes.at(i).at(j) == muonindex) found_muon = true;
      for(int j=0;j<3;j++) if(SeedIndexes.at(i).at(j) == pionplusindex) found_pion_plus = true;
      for(int j=0;j<3;j++) if(SeedIndexes.at(i).at(j) == pionminusindex) found_pion_minus = true;

      if(found_muon && found_pion_plus && found_pion_minus){ test_index = i; break; }

   }

   if(test_index == -1) return false;

   int output_muonindex=-1;
   int output_pion_plus_index=-1;
   int output_pion_minus_index=-1;

   for(int j=0;j<3;j++) if(SeedIndexes.at(test_index).at(j) == muonindex)  output_muonindex = j;
   for(int j=0;j<3;j++) if(SeedIndexes.at(test_index).at(j) == pionplusindex)  output_pion_plus_index = j;
   for(int j=0;j<3;j++) if(SeedIndexes.at(test_index).at(j) == pionminusindex)  output_pion_minus_index = j;

   // Reject events with a -1
   if(OutputIndexes.at(test_index).at(0) == -1 || OutputIndexes.at(test_index).at(1) == -1 || OutputIndexes.at(test_index).at(2) == -1) return false;

   // Reject events with clusters below the minimum size

   if(OutputSizes.at(test_index).at(0) < fMinClusterSize || OutputSizes.at(test_index).at(1) < fMinClusterSize || OutputSizes.at(test_index).at(2) < fMinClusterSize) return false;

   // Check seeds are not separated by dead wires
   if(DeadWireCheck(SeedChannels.at(test_index))) return false;

   // Fail if all three output indexes are the same = all three particles merged
   if(OutputIndexes.at(test_index).at(0) == OutputIndexes.at(test_index).at(1) && OutputIndexes.at(test_index).at(1) == OutputIndexes.at(test_index).at(2)) return false;

   if(OutputIndexes.at(test_index).at(output_muonindex) != OutputIndexes.at(test_index).at(output_pion_plus_index)
         && OutputIndexes.at(test_index).at(output_muonindex) != OutputIndexes.at(test_index).at(output_pion_minus_index)
         && OutputIndexes.at(test_index).at(output_pion_plus_index) == OutputIndexes.at(test_index).at(output_pion_minus_index)) return true;

   return false;
}

///////////////////////////////////////////////////////////////////////////////////////////////

bool CTTest::DeadWireCheck(std::vector<int> seeds_channel){

   // if there is zero or 1 seed, this check is meaningless
   if(seeds_channel.size() < 2) return false;

   // find lowest/highest channel seeds
   int min_ch=seeds_channel.at(0);
   int max_ch=seeds_channel.at(0);

   for(size_t i_s=1;i_s<seeds_channel.size();i_s++){
      if(seeds_channel.at(i_s) < min_ch) min_ch = seeds_channel.at(i_s);
      if(seeds_channel.at(i_s) > max_ch) max_ch = seeds_channel.at(i_s);
   }

   int ch=min_ch;

   while(ch <= max_ch){
      if(std::find(DeadChannels.begin(),DeadChannels.end(),ch) != DeadChannels.end()) return true;
      ch++;
   }

   return false;
}

#endif
