R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so)
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so)

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

void kaon_nu_ang_dev(){

    //double POT = 1.25e21; // POT to scale samples to
    double POT = 1.5e21;

    BuildTunes();
    //SelectionParameters P = P_FHC_Tune_325_NoBDT;
    SelectionParameters P = P_RHC_Tune_397_NoBDT;

    std::string label = "kaon_muon_angle";
    std::string SampleType = "pure_kaon";

    EventAssembler E(false);
    SelectionManager M(P);
    M.ImportSelectorBDTWeights("/uboone/app/users/nlane/NeutralKaonAnalysis/TMVA/SelectorMVA/dataset/weights");

    //M.SetBeamMode(kFHC);
    M.SetBeamMode(kRHC);
    
    M.SetPOT(POT);
    M.UseFluxWeight(false);
    M.UseGenWeight(false);

    M.SetupHistograms(18,0,180,";Angular Deviation (deg);Events/bin");

    //E.SetFile("analysisOutputFHC_Overlay_GENIE_Kaon_cthorpe_make_k0s_events_numi_fhc_reco2_reco2_reco2.root",  "signal");
    E.SetFile("analysisOutputRHC_GENIE_Overlay_Kaon_cthorpe_make_k0s_events_numi_rhc_reco2_REAL_reco2_reco2.root", "signal");
    M.AddSample("Signal", "Signal", E.GetPOT());

    double Signal = 0.0;
    double Selected_Signal = 0.0;

    for(int i = 0; i < E.GetNEvents(); i++){

        if(i % 10000 == 0) std::cout << i << "/" << E.GetNEvents() << std::endl;

        Event e = E.GetEvent(i);

        M.SetSignal(e);                
        M.AddEvent(e);

        bool passed_FV = false;
        bool passed_track = false;
        bool passed_shower = false;
        bool passed_muon = false;
        bool passed_pion_pair = false;
        bool passed_connectedness = false;
        bool passed_Wcut = false;

        if(e.EventIsSignal) Signal += e.Weight;


        passed_FV = M.FiducialVolumeCut(e);
        if(!passed_FV) continue;
        passed_muon = M.ChooseMuonCandidate(e);
        if(!passed_muon) continue;
        passed_pion_pair = M.ChoosePionPairCandidates(e);
        if(!passed_pion_pair) continue;

        SecondaryVertexFitter a_SecondaryVertexFitter;
        SecondaryVertex V = a_SecondaryVertexFitter.MakeVertex(e.DecayPionPlusCandidate, e.DecayPionMinusCandidate);

        TVector3 GapVector = V.Vertex - e.RecoPrimaryVertex;
        double Reco_DecayLength = (V.Vertex - e.RecoPrimaryVertex).Mag();

        TLorentzVector NeutralKaon4Momentum = PionPair4Momentum(e.DecayPionPlusCandidate, e.DecayPionMinusCandidate);

        TVector3 NeutralKaonDirection(NeutralKaon4Momentum.X(), NeutralKaon4Momentum.Y(), NeutralKaon4Momentum.Z());
        TVector3 MuonDirection(e.MuonCandidate.TrackDirectionX, e.MuonCandidate.TrackDirectionY, e.MuonCandidate.TrackDirectionZ);
        double alpha = (180/3.1415) * NeutralKaonDirection.Angle(MuonDirection);

        if(e.EventIsSignal) Selected_Signal += e.Weight;

        M.FillHistograms(e, alpha);               
    }

    std::cout << "Drawing histograms" << std::endl;
    M.DrawHistograms(label);

    std::cout << "Signal = " << Signal << " Selected = " << Selected_Signal << std::endl;
    
    E.Close();

}