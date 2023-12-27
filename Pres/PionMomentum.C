R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so);
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so);

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

void PionMomentum(){

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

    E.SetFile("analysisOutputFHC_Overlay_GENIE_Kaon_cthorpe_make_k0s_events_numi_fhc_reco2_reco2_reco2.root", "Background");
    M.AddSample("Background","Background",E.GetPOT());

    TH1F *hPionPlus = new TH1F("hPionPlus", "", 100, -1, 1);
    TH1F *hPionMinus = new TH1F("hPionMinus", "", 100, -1, 1);

    for(int i = 0; i < E.GetNEvents(); i++){

        if(i % 10000 == 0) std::cout << i << "/" << E.GetNEvents() << std::endl;

        Event e = E.GetEvent(i);

        M.SetSignal(e);                
        M.AddEvent(e);
        
        if(!e.EventIsSignal) continue;
        
        bool passed_FV=false,passed_Tracks=false,passed_Showers=false,passed_MuonID=false,passed_TrackLengths=false,passed_Selector=false,passed_CT=false,passed_WCut=false,passed_AngleCut=false,passed_All=false;

        passed_FV = M.FiducialVolumeCut(e);
        if(passed_FV) passed_Tracks = M.TrackCut(e);
        if(passed_Tracks) passed_MuonID = M.ChooseMuonCandidate(e);
        if(passed_MuonID) passed_Selector = M.ChoosePionPairCandidates(e, true);
    
        passed_All = passed_Selector;

        FV::FiducialVolume a_FiducialVolume(P.p_FV,P.p_Padding);

        TVector3 end;
        end.SetXYZ(e.DecayPionPlusCandidate.TrackEndX, e.DecayPionPlusCandidate.TrackEndY, e.DecayPionPlusCandidate.TrackEndZ);
        if(a_FiducialVolume.InFiducialVolume(end)){
            double TRACK_CUT = 0;
            if(e.DecayPionPlusCandidate.TrackLength > TRACK_CUT) {
                double mom_pos_frac = (e.DecayPionPlusCandidate.TrackTrueModMomentum - PionMomentum(e.DecayPionPlusCandidate.TrackLength))/e.DecayPionPlusCandidate.TrackTrueModMomentum;
                hPionPlus->Fill(mom_pos_frac);
            }
        }

        double TRACK_CUT = 0;
        /*if(e.DecayPionPlusCandidate.TrackLength > TRACK_CUT) {
            double mom_pos_frac = (e.DecayPionPlusCandidate.TrackTrueModMomentum - PionMomentum(e.DecayPionPlusCandidate.TrackLength))/e.DecayPionPlusCandidate.TrackTrueModMomentum;
            hPionPlus->Fill(mom_pos_frac);
        }*/
        if(e.DecayPionMinusCandidate.TrackLength > TRACK_CUT) {
            double mom_min_frac = (e.DecayPionMinusCandidate.TrackTrueModMomentum - PionMomentum(e.DecayPionMinusCandidate.TrackLength))/e.DecayPionMinusCandidate.TrackTrueModMomentum;
            hPionMinus->Fill(mom_min_frac);
        }

    }

    TCanvas *c1 = new TCanvas("c1", "", 800, 600);
    hPionPlus->Draw("hist");
    c1->SaveAs("pion_plus.png");

    TCanvas *c2 = new TCanvas("c2", "", 800, 600);
    hPionMinus->Draw("hist");
    c2->SaveAs("pion_minus.png");

    E.Close();
}