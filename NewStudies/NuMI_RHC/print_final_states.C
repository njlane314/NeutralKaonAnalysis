R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so);
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so);

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

void print_final_states(){

  //double POT = 1.5e21;
    double POT = 1.2e21;

    BuildTunes();
    SelectionParameters P = P_RHC_Tune_397_NoBDT;

    std::string label = "test";
    std::string SampleType = "Kaon";

    EventAssembler E(false);
    SelectionManager M(P);
    M.ImportSelectorBDTWeights("/exp/uboone/app/users/nlane/NeutralKaonAnalysis/TMVA/SelectorMVA/dataset/weights");

    M.SetBeamMode(kRHC);

    M.SetPOT(POT);
    M.UseFluxWeight(false);
    M.UseGenWeight(false);

    //E.SetFile("analysisOutputRHC_GENIE_Overlay_Kaon_cthorpe_make_k0s_events_numi_rhc_reco2_REAL_reco2_reco2.root", "Kaon");
    E.SetFile("analysisOutputFHC_Overlay_GENIE_Kaon_cthorpe_make_k0s_events_numi_fhc_reco2_reco2_reco2.root", "Kaon");
    M.AddSample("Kaon","Kaon",E.GetPOT());

    M.TuneMuonID(0.6, 0, 5); 

    std::unordered_map<std::string, std::pair<double, double>> primaryParticleCombinationChannels;

  for(int i = 0; i < E.GetNEvents(); i++){
	if(i % 10000 == 0) std::cout << i << "/" << E.GetNEvents() << std::endl;

        Event e = E.GetEvent(i);

        M.SetSignal(e);                
        M.AddEvent(e);

        if(!e.EventIsSignal) continue;

        bool passed_FV, passed_muon, passed_track, passed_pion, passed_WCut = false;

        passed_FV = M.FiducialVolumeCut(e);
        if(!passed_FV) continue;
        /*passed_track = M.TrackCut(e);
        if(!passed_track) continue;
        passed_pion = M.ChoosePionPairCandidates(e);
        if(!passed_pion) continue;*/
	
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

        double var = e.Weight * e.Weight;
        primaryParticleCombinationChannels[primaryParticleChannel].first += e.Weight;
        primaryParticleCombinationChannels[primaryParticleChannel].second += var;
         
  };

  std::vector<std::pair<std::string, std::pair<double, double>>> sortedChannels;
  for (const auto &channel_count : primaryParticleCombinationChannels) {
    sortedChannels.push_back(channel_count);
  }

  std::sort(sortedChannels.begin(), sortedChannels.end(), 
            [](const std::pair<std::string, std::pair<double, double>> &a, const std::pair<std::string, std::pair<double, double>> &b) {
                return a.second > b.second; 
            });

  for (const auto &channel_count : sortedChannels) {
    std::cout << "Final state: " << channel_count.first << " occurs " << channel_count.second.first << " " << sqrt(channel_count.second.second) << " times " << std::endl;
  }

  E.Close();

}
