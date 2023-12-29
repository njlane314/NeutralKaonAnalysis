R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so);
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so);

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

void HadronicChannels(){

  double POT = 1.0e21; // POT to scale samples to

  BuildTunes();
  SelectionParameters P = P_FHC_Tune_325_NoBDT;

  std::string label = "test";

  EventAssembler E(false);

  std::unordered_map<std::string, int> primaryParticleCombinationChannels;

  E.SetFile("analysisOutputFHC_GENIE_Overlay_Kaon.root","Background");

  for(int ievent = 0; ievent < E.GetNEvents(); ievent++){
	Event e = E.GetEvent(ievent);
	
	std::vector<SimParticle> allPrimaryParticles; 

	if(!e.PrimaryKaon.empty()) { 
			allPrimaryParticles.insert(allPrimaryParticles.end(), e.Lepton.begin(), e.Lepton.end());
			allPrimaryParticles.insert(allPrimaryParticles.end(), e.Hyperon.begin(), e.Hyperon.end());
			allPrimaryParticles.insert(allPrimaryParticles.end(), e.PrimaryKaon.begin(), e.PrimaryKaon.end());
	}


	std::sort(allPrimaryParticles.begin(), allPrimaryParticles.end(),
		[](const SimParticle& a, const SimParticle& b) {
			return abs(a.PDG) < abs(b.PDG);
		});
	
	std::string primaryParticleChannel;	
	for(const SimParticle& particle : allPrimaryParticles) {
		if(!primaryParticleChannel.empty()) {
			primaryParticleChannel += "_";
		}
		primaryParticleChannel += std::to_string(particle.PDG);
	}

	if(primaryParticleChannel.empty() || primaryParticleChannel[0] == '_') {
		continue;
	}
	primaryParticleCombinationChannels[primaryParticleChannel]++;
	
  	if(ievent % 10000 == 0) std::cout << ievent << "/" << E.GetNEvents() << std::endl;
   
  };

  std::vector<std::pair<std::string, int>> sortedChannels;
  for (const auto &channel_count : primaryParticleCombinationChannels) {
    sortedChannels.push_back(channel_count);
  }

  std::sort(sortedChannels.begin(), sortedChannels.end(), 
            [](const std::pair<std::string, int> &a, const std::pair<std::string, int> &b) {
                return a.second > b.second; 
            });

  for (const auto &channel_count : sortedChannels) {
    std::cout << "Final state: " << channel_count.first << " occurs " << channel_count.second << " times." << std::endl;
  }

  E.Close();

}
