R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so);
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so);

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

void restricted_phase_check(){

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

    E.SetFile("analysisOutputFHC_Overlay_GENIE_Kaon_cthorpe_make_k0s_events_numi_fhc_reco2_reco2_reco2.root", "Signal");
    M.AddSample("Signal","Signal",E.GetPOT());

    TH1F *hKaonMomBefore = new TH1F("", "", 50, 0, 2.5);
    TH1F *hKaonMomAfter = new TH1F("", "", 50, 0, 2.5);

    for(int i = 0; i < E.GetNEvents(); i++){

        if(i % 10000 == 0) std::cout << i << "/" << E.GetNEvents() << std::endl;

        Event e = E.GetEvent(i);

        int pion_plus_index = -1;
        int pion_minus_index = -1;

        for(size_t i = 0; i < e.KaonDecay.size(); i++) {
            int particle_pdg = e.KaonDecay.at(i).PDG;

            if(particle_pdg == +211){
                pion_plus_index = i;
            }
            else if(particle_pdg == -211){
                pion_minus_index = i;
            }
        }

        if(pion_plus_index == -1 || pion_minus_index == -1) continue;

        double kaon_momentum = 0;
        double kaon_px = e.KaonDecay.at(pion_plus_index).Px - e.KaonDecay.at(pion_minus_index).Px;
        double kaon_py = e.KaonDecay.at(pion_plus_index).Py - e.KaonDecay.at(pion_minus_index).Py;
        double kaon_pz = e.KaonDecay.at(pion_plus_index).Pz - e.KaonDecay.at(pion_minus_index).Pz;

        kaon_momentum = sqrt(kaon_px*kaon_px + kaon_py*kaon_py + kaon_pz*kaon_pz);
        hKaonMomBefore->Fill(kaon_momentum);

        if(e.KaonDecay.at(pion_plus_index).ModMomentum < 0.1 || e.KaonDecay.at(pion_minus_index).ModMomentum < 0.1) continue;
        hKaonMomAfter->Fill(kaon_momentum);
       
    }

    TCanvas *c1 = new TCanvas("c1", "", 800, 600);
    hKaonMomAfter->GetXaxis()->SetTitle("Kaon Momentum");
    hKaonMomAfter->Draw("hist");
    c1->SaveAs("Plots/kaon_mom.png");

    hKaonMomAfter->Divide(hKaonMomBefore);

    TCanvas *c2 = new TCanvas("c2", "", 800, 600);

    hKaonMomAfter->GetXaxis()->SetTitle("Kaon Momentum");
    hKaonMomAfter->GetYaxis()->SetTitle("Ratio");

    hKaonMomAfter->Draw("hist");

    c2->SaveAs("Plots/kaon_mom_ratio.png");

    E.Close();

}