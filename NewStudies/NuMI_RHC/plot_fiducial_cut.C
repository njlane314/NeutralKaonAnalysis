R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so)
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so)

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

void plot_fiducial_cut(){

    //double POT = 1.25e21; // POT to scale samples to
    double POT = 1.5e21;

    BuildTunes();
    //SelectionParameters P = P_FHC_Tune_325_NoBDT;
    SelectionParameters P = P_RHC_Tune_397_NoBDT;

    std::string label = "test";
    std::string SampleType = "Kaon";

    EventAssembler E(false);
    SelectionManager M(P);
    M.ImportSelectorBDTWeights("/exp/uboone/app/users/nlane/NeutralKaonAnalysis/TMVA/SelectorMVA/dataset/weights");

    //M.SetBeamMode(kFHC);
    M.SetBeamMode(kRHC);
    
    M.SetPOT(POT);
    M.UseFluxWeight(false);
    M.UseGenWeight(false);

    //E.SetFile("analysisOutputFHC_Overlay_GENIE_Kaon_cthorpe_make_k0s_events_numi_fhc_reco2_reco2_reco2.root", "Kaon");
    E.SetFile("analysisOutputRHC_GENIE_Overlay_Kaon_cthorpe_make_k0s_events_numi_rhc_reco2_REAL_reco2_reco2.root", "Kaon");
    M.AddSample("Kaon", "Kaon", E.GetPOT());

    M.TuneMuonID(0.6, 0, 5); 

    TEfficiency* pFiducalEfficX = new TEfficiency("pFiducalEffic", ";True Neutrino Interaction Vertex, X (cm); Entries/bin", 30, 0, 250);
    TEfficiency* pFiducalEfficY = new TEfficiency("pFiducalEffic", ";True Neutrino Interaction Vertex, Y (cm); Entries/bin", 25, -100, 100);
    TEfficiency* pFiducalEfficZ = new TEfficiency("pFiducalEffic", ";True Neutrino Interaction Vertex, Z (cm); Entries/bin", 40, 0, 1000);

    for(int i = 0; i < E.GetNEvents(); i++){

        if(i % 10000 == 0) std::cout << i << "/" << E.GetNEvents() << std::endl;

        Event e = E.GetEvent(i);

        M.SetSignal(e);                
        M.AddEvent(e);

        bool passed_FV = false;
        bool passed_muon = false;

        if(!e.EventIsSignal) continue;

        passed_FV = M.FiducialVolumeCut(e);
        //passed_muon = M.ChooseMuonCandidate(e);
        //if(!passed_FV) continue;
        //if(!passed_muon) continue;

        pFiducalEfficX->FillWeighted(passed_FV, e.Weight, e.Neutrino.at(0).EndX);
        pFiducalEfficY->FillWeighted(passed_FV, e.Weight, e.Neutrino.at(0).EndY);
        pFiducalEfficZ->FillWeighted(passed_FV, e.Weight, e.Neutrino.at(0).EndZ);
              
    }

    HypPlot::DrawEfficiencyPlot(pFiducalEfficX, "", "FiducialX", "True Neutrino Interaction Vertex, X (cm)", {kRHC}, {POT});
    HypPlot::DrawEfficiencyPlot(pFiducalEfficY, "", "FiducialY", "True Neutrino Interaction Vertex, Y (cm)", {kRHC}, {POT});
    HypPlot::DrawEfficiencyPlot(pFiducalEfficZ, "", "FiducialZ", "True Neutrino Interaction Vertex, Z (cm)", {kRHC}, {POT});

    E.Close();

}