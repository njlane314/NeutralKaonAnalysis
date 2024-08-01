R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so);
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so);

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

void plot_muon_accuracy(){

    double POT = 1.5e21;

    BuildTunes();
    SelectionParameters P = P_RHC_Tune_397_NoBDT;

    std::string label = "test";
    std::string SampleType = "Kaon";

    EventAssembler E(false);
    SelectionManager M(P);
    M.SetBeamMode(kRHC);

    M.SetPOT(POT);
    M.UseFluxWeight(false);
    M.UseGenWeight(false);

    E.SetFile("analysisOutputRHC_GENIE_Overlay_Kaon_cthorpe_make_k0s_events_numi_rhc_reco2_REAL_reco2_reco2.root", "Kaon");
    M.AddSample("Kaon","Kaon",E.GetPOT());

    std::vector<double> accuracy;
    std::vector<double> thresholds;

    for(double j = 0.6; j < 0.9 ; j+= 0.1){
        M.TuneMuonID(j, 20, 5); 

        int truePositives = 0;
        int totalSignalEvents = 0;

        thresholds.push_back(j);

        for(int i = 0; i < E.GetNEvents(); i++){

            if(i % 10000 == 0) std::cout << i << "/" << E.GetNEvents() << std::endl;

            Event e = E.GetEvent(i);

            M.SetSignal(e);                
            M.AddEvent(e);

            if(!e.EventIsSignal) continue;

            bool passed_FV, passed_muon, passed_track = false;

            passed_FV = M.FiducialVolumeCut(e);
            if(!passed_FV) continue;
            passed_track = M.TrackCut(e);
            if(!passed_track) continue;
            passed_muon = M.ChooseMuonCandidate(e);
            //if(!passed_muon) continue;

            if(abs(e.MuonCandidate.TrackTruePDG) == 13 && passed_muon){
                truePositives++;
            }

            totalSignalEvents += 1;

        }

        double acc = static_cast<double>(truePositives) / totalSignalEvents;

        accuracy.push_back(acc);
    }

    TCanvas *c1 = new TCanvas("", "", 800, 600);
    c1->SetLeftMargin(0.12); // Adjust the left margin
    c1->SetBottomMargin(0.12); // Adjust the bottom margin

    TGraph *accuracy_plot = new TGraph(thresholds.size(), &(thresholds[0]), &(accuracy[0]));

    accuracy_plot->SetMarkerStyle(0); // Set marker style
    accuracy_plot->SetMarkerSize(0.8); // Set marker size
    accuracy_plot->SetMarkerColor(kBlack); // Set marker color
    accuracy_plot->SetLineColor(kBlack); // Set line color
    accuracy_plot->SetLineWidth(2); // Set line width

    accuracy_plot->Draw("ACP");

    accuracy_plot->GetXaxis()->SetTitleSize(HypPlot::Single_XaxisTitleSize);
    accuracy_plot->GetYaxis()->SetTitleSize(HypPlot::Single_YaxisTitleSize);
    accuracy_plot->GetXaxis()->SetTitleOffset(HypPlot::Single_XaxisTitleOffset);
    accuracy_plot->GetYaxis()->SetTitleOffset(1.15);
    accuracy_plot->GetXaxis()->SetLabelSize(HypPlot::Single_XaxisLabelSize);
    accuracy_plot->GetYaxis()->SetLabelSize(HypPlot::Single_YaxisLabelSize);
    accuracy_plot->GetXaxis()->SetNdivisions(510); // Improve x-axis divisions
    accuracy_plot->GetYaxis()->SetNdivisions(510); // Improve y-axis divisions
    accuracy_plot->GetYaxis()->SetRangeUser(0., 1.);
    accuracy_plot->GetXaxis()->SetRangeUser(0., 1.);

    c1->Modified();
    c1->Update();

    c1->SaveAs("accuracy.png");

    //M.PrintAllCuts();

    E.Close();

}