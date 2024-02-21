#ifndef _CTTest_h_
#define _CTTest_h_

#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

// Performs connectedness test for a single plane

class CTTest {

   public:

      CTTest(int plane);
      void LoadInfo(std::vector<std::vector<int>> seedindexes,std::vector<std::vector<int>> outputindexes,std::vector<std::vector<int>> outputsizes,std::vector<std::vector<int>> seedchannels);

      bool DoTest(int muonindex,int pionplusindex,int pionminusindex);

   private:

      int fMinClusterSize = 50;

      int fPlane;

      std::vector<std::vector<int>> SeedIndexes;
      std::vector<std::vector<int>> OutputIndexes;
      std::vector<std::vector<int>> OutputSizes;
      std::vector<std::vector<int>> SeedChannels;
      
      std::vector<int> DeadChannels;

      bool DeadWireCheck(std::vector<int> seeds_channel);


};



#endif 
