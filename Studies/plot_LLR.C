R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so);
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so);

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

void plot_LLR(){

    BuildTunes();
    SelectionParameters P = P_FHC_Tune_325_NoBDT;

    std::string label = "test";
    std::string SampleType = "background";

    EventAssembler E(false);
    SelectionManager M(P);
    M.UseFluxWeight(false);
    M.UseGenWeight(false);

    E.SetFile("analysisOutputFHC_Overlay_GENIE_Kaon_cthorpe_make_k0s_events_numi_fhc_reco2_reco2_reco2.root", "Signal");
    M.AddSample("Signal","Signal",E.GetPOT());

    TH1F *hLLRMuon = new TH1F("", "", 100, -1, 1);
    TH1F *hLLRProton = new TH1F("", "", 100, -1, 1); 

    for(int i = 0; i < E.GetNEvents(); i++){

        if(i % 10000 == 0) std::cout << i << "/" << E.GetNEvents() << std::endl;

        Event e = E.GetEvent(i);

        M.SetSignal(e);                
        M.AddEvent(e);

        bool passed_FV = false;

        passed_FV = M.FiducialVolumeCut(e);
        if(!passed_FV) continue;

        for(size_t i = 0; i < e.TracklikePrimaryDaughters.size(); i++){

            int trackIndex = e.TracklikePrimaryDaughters.at(i).Index;
            double trackLLRPID = e.TracklikePrimaryDaughters.at(i).Track_LLR_PID;
            double trackLength = e.TracklikePrimaryDaughters.at(i).TrackLength;
            double trackMomentum = e.TracklikePrimaryDaughters.at(i).TrackTrueModMomentum;
            double trackDisplacement = e.TracklikePrimaryDaughters.at(i).Displacement;
            double trackMeandEdx = e.TracklikePrimaryDaughters.at(i).MeandEdX_ThreePlane;
            int trackPDG = e.TracklikePrimaryDaughters.at(i).TrackTruePDG;

            if(trackIndex != 2) continue;

            if(abs(trackPDG) == 13){ // 13 muon, 211 pion, 2212 proton
                hLLRMuon->Fill(trackLLRPID);
            }
            else if(abs(trackPDG) == 2212){
                hLLRProton->Fill(trackLLRPID);
            }
        }

    }

    TCanvas *c1 = new TCanvas("c1", "", 800, 600);
    THStack *hs = new THStack("hs","Stacked LLR PID");

    hLLRMuon->SetFillColor(kRed);
    hLLRProton->SetFillColor(kBlue);

    hs->Add(hLLRMuon);
    hs->Add(hLLRProton);

    hs->Draw("nostack"); // Use "nostack" for overlaying histograms instead of stacking
    c1->BuildLegend(); // Automatically build a legend
    c1->SaveAs("Plots/LLRPID_Stacked.png");

    E.Close();

}