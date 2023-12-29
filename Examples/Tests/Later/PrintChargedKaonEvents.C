R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so);
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so);

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

void PrintChargedKaonEvents(){

    double POT = 1.0e21; 

    BuildTunes();
    SelectionParameters P = P_FHC_Tune_325_NoBDT;

    std::string label = "preliminary";
    std::string SampleType = "signal";

    EventAssembler E(false);
    SelectionManager M(P);
    M.SetPOT(POT);
    M.UseFluxWeight(false);
    M.UseGenWeight(false);

    E.SetFile("analysisOutputFHC_Overlay_GENIE_Kaon_cthorpe_make_k0s_events_numi_fhc_reco2_reco2_reco2.root", "Signal");
    M.AddSample("Signal","Signal",E.GetPOT());

    for(int i = 0; i < E.GetNEvents(); i++){

        //if(i % 10000 == 0) std::cout << i << "/" << E.GetNEvents() << std::endl;

        //if(i > 10000) continue;

        Event e = E.GetEvent(i);

        M.SetSignal(e);                
        M.AddEvent(e);

        if(!e.EventIsSignal) continue;
        
        bool passed_FV=false,passed_Tracks=false,passed_Showers=false,passed_MuonID=false,passed_TrackLengths=false,passed_Selector=false,passed_CT=false,passed_WCut=false,passed_AngleCut=false,passed_All=false;

        passed_FV = M.FiducialVolumeCut(e);
        if(passed_FV) passed_Tracks = M.TrackCut(e);
        if(passed_Tracks) passed_MuonID = M.ChooseMuonCandidate(e);
        if(passed_Tracks) passed_Selector = M.ChoosePionPairCandidates(e, true);
    
        passed_All = passed_Selector;
        if(!passed_All) continue;

        double invariantMass = PionPairInvariantMass(e.DecayPionPlusCandidate, e.DecayPionMinusCandidate);

        bool selector_displacement = false;
        for(size_t i = 0; i < e.TracklikePrimaryDaughters.size(); i++){
            
            double trackLLRPID = e.TracklikePrimaryDaughters.at(i).Track_LLR_PID;
            double trackLength = e.TracklikePrimaryDaughters.at(i).TrackLength;
            double trackTrueMomentum = e.TracklikePrimaryDaughters.at(i).TrackTrueModMomentum;
            double trackMuonMomentum = e.TracklikePrimaryDaughters.at(i).MuonMomentum;
            double trackPionMomentum = PionMomentum(e.TracklikePrimaryDaughters.at(i).TrackLength);
            double trackDisplacement = e.TracklikePrimaryDaughters.at(i).Displacement;
            double trackMeandEdx = e.TracklikePrimaryDaughters.at(i).MeandEdX_ThreePlane;
            int trackPDG = e.TracklikePrimaryDaughters.at(i).TrackTruePDG;
            int trackIndex = e.TracklikePrimaryDaughters.at(i).Index;

            if(abs(trackPDG) == 211 && trackIndex != 0){
                if(e.TracklikePrimaryDaughters.at(i).TrackTrueOrigin != 7) continue;
                if(trackDisplacement > 15) selector_displacement = true;
            } 
        }

        if(invariantMass > 0.45 && invariantMass < 0.55 && selector_displacement){
            e.Print();
        }
   
    }

    E.Close();

}
