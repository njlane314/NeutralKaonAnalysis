R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so);
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so);

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

void MuonMomentum(){

    double POT = 1.0e21; 

    BuildTunes();
    SelectionParameters P = P_FHC_Tune_325_NoBDT;

    std::string label = "test";
    std::string SampleType = "background";

    EventAssembler E(false);
    SelectionManager M(P);
    M.SetPOT(POT);
    M.UseFluxWeight(false);
    M.UseGenWeight(false);

    E.SetFile("analysisOutputFHC_GENIE_Overlay_Kaon.root", "Background");
    M.AddSample("Background","Background",E.GetPOT());

    TEfficiency* pMuonIdentifier = new TEfficiency("pMuonIdentifier", ";Reconstructed Muon Momentum (GeV/c); Entries/bin", 20, 0, 2);

    for(int i = 0; i < E.GetNEvents(); i++){
        if(i % 10000 == 0) std::cout << i << "/" << E.GetNEvents() << std::endl;

        Event e = E.GetEvent(i);

        M.SetSignal(e);                
        M.AddEvent(e);

        if(!e.EventIsSignal) continue;

        bool passed_FV = false;
        bool passed_Tracks = false;

        passed_FV = M.FiducialVolumeCut(e);
        if(passed_FV) passed_Tracks = M.TrackCut(e);

        if(!passed_Tracks) continue;

        int i_longest = -1;
        int length = -1;
        for(size_t i = 0; i < e.TracklikePrimaryDaughters.size(); i++){
            double trackPID = e.TracklikePrimaryDaughters.at(i).Track_LLR_PID;
            double trackLength = e.TracklikePrimaryDaughters.at(i).TrackLength;
            double trackDisplacement = e.TracklikePrimaryDaughters.at(i).Displacement;
            int trackPDG = e.TracklikePrimaryDaughters.at(i).TrackTruePDG;

            //if(trackPID < 0.9 || trackLength < 100 || trackDisplacement > 10) continue;
            if(trackPID < 0.9) continue;
            if(trackLength > length){
                length = trackLength;
                i_longest = i;
            }
        }

        if(i_longest == -1) continue;

        double longestPDG = e.TracklikePrimaryDaughters.at(i_longest).TrackTruePDG;
        double trackFill = e.TracklikePrimaryDaughters.at(i_longest).MuonMomentum;

        bool passed_Muon = false;
        if(abs(longestPDG) == 13){
            passed_Muon = true;
        }
        
        pMuonIdentifier->FillWeighted(passed_Muon, e.Weight, trackFill);
    }

    HypPlot::DrawEfficiencyPlot(pMuonIdentifier, "", "MuonIdentifier", {kFHC}, {POT});

    E.Close();

}