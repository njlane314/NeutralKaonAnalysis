R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so);
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so);

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

void print_singleprod_trackshow(){

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

    std::vector<double> recall;
    std::vector<double> precision;

    // Define arrays to store false positive rate and true positive rate for ROC curve
    std::vector<double> fpr;
    std::vector<double> tpr;

    std::vector<double> f1_scores;

    std::vector<double> thresholds;

    for(double j = 0.6; j < 0.9 ; j+= 0.1){
        M.TuneMuonID(j, 10, 5); 

        int truePositives = 0;
        int trueNegatives = 0;
        int falsePositives = 0;
        int falseNegatives = 0;

        thresholds.push_back(j);

        for(int i = 0; i < E.GetNEvents(); i++){

            if(i % 10000 == 0) std::cout << i << "/" << E.GetNEvents() << std::endl;

            Event e = E.GetEvent(i);

            M.SetSignal(e);                
            M.AddEvent(e);

            bool passed_FV, passed_muon, passed_track = false;

            passed_FV = M.FiducialVolumeCut(e);
            if(!passed_FV) continue;
            passed_track = M.TrackCut(e);
            if(!passed_track) continue;
            passed_muon = M.ChooseMuonCandidate(e);
            //if(!passed_muon) continue;

            bool has_muon = false;
            for(int j = 0; j < e.Lepton.size(); j++){
                if(abs(e.Lepton.at(j).PDG) == 13){
                    has_muon = true;
                }
            }

            if(!passed_muon){
                // if does not pass muon identifier, determine if there was a muon lepton produced in the event
                // negative
                if(has_muon){
                    falseNegatives++;
                }
                else{
                    trueNegatives++;
                }

                continue;
            }

            bool isTrueMuon = (abs(e.MuonCandidate.TrackTruePDG) == 13);
            if(isTrueMuon){
                truePositives++;
            }
            else{
                falsePositives++;
            }

        }

        // Calculate true positive rate (recall) and precision
        double recall_value = static_cast<double>(truePositives) / (truePositives + falseNegatives);
        double precision_value = static_cast<double>(truePositives) / (truePositives + falsePositives);

        std::cout << falseNegatives << std::endl;
        std::cout << trueNegatives << std::endl;

        // Store values
        recall.push_back(recall_value);
        precision.push_back(precision_value);

        double f1_score = 2 * (precision_value * recall_value) / (precision_value + recall_value + 1e-9);
        f1_scores.push_back(f1_score);


        std::cout << recall_value << std::endl;
        std::cout << precision_value << std::endl;

        // Calculate false positive rate (fpr) and true positive rate (tpr) for ROC curve
        double falsePositiveRate = static_cast<double>(falsePositives) / (falsePositives + trueNegatives);
        double truePositiveRate = static_cast<double>(truePositives) / (truePositives + falseNegatives);

        // Store values
        fpr.push_back(falsePositiveRate);
        tpr.push_back(truePositiveRate);
    }

    TCanvas *c1 = new TCanvas("", "", 800, 600);
    c1->SetLeftMargin(0.12); // Adjust the left margin
    c1->SetBottomMargin(0.12); // Adjust the bottom margin

    TGraph *precision_recall_curve = new TGraph(recall.size(), &(recall[0]), &(precision[0]));
    //TGraph *roc_curve = new TGraph(fpr.size(), &(fpr[0]), &(tpr[0]));

    precision_recall_curve->SetMarkerStyle(0); // Set marker style
    precision_recall_curve->SetMarkerSize(0.8); // Set marker size
    precision_recall_curve->SetMarkerColor(kBlack); // Set marker color
    precision_recall_curve->SetLineColor(kBlack); // Set line color
    precision_recall_curve->SetLineWidth(2); // Set line width

    precision_recall_curve->Draw("ACP");

    precision_recall_curve->GetXaxis()->SetTitleSize(HypPlot::Single_XaxisTitleSize);
    precision_recall_curve->GetYaxis()->SetTitleSize(HypPlot::Single_YaxisTitleSize);
    precision_recall_curve->GetXaxis()->SetTitleOffset(HypPlot::Single_XaxisTitleOffset);
    precision_recall_curve->GetYaxis()->SetTitleOffset(1.15);
    precision_recall_curve->GetXaxis()->SetLabelSize(HypPlot::Single_XaxisLabelSize);
    precision_recall_curve->GetYaxis()->SetLabelSize(HypPlot::Single_YaxisLabelSize);
    precision_recall_curve->GetXaxis()->SetNdivisions(510); // Improve x-axis divisions
    precision_recall_curve->GetYaxis()->SetNdivisions(510); // Improve y-axis divisions
    precision_recall_curve->GetYaxis()->SetRangeUser(0., 1.);
    precision_recall_curve->GetXaxis()->SetRangeUser(0., 1.);

    c1->Modified();
    c1->Update();

    for(int i = 0; i < recall.size(); i++){
        std::cout << recall[i] << std::endl;
        std::cout << precision[i] << std::endl;
    }

    c1->SaveAs("precision_recall_curve.png");

    TCanvas *c2 = new TCanvas("", "", 800, 600);
    // Your existing code...
    TGraph *roc_curve = new TGraph(fpr.size(), &(fpr[0]), &(tpr[0]));
    // Your existing code...
    roc_curve->Draw("ACP");
    // Your existing code...
    c2->SaveAs("roc_curve.png");

    TCanvas *c3 = new TCanvas("", "", 800, 600);
    // Your existing code...
    TGraph *f1_score_plot = new TGraph(f1_scores.size(), &(thresholds[0]), &(f1_scores[0])); // Assuming you have thresholds
    // Your existing code...
    f1_score_plot->Draw("ACP");
    // Your existing code...
    c3->SaveAs("f1_score_plot.png");

    //M.PrintAllCuts();

    E.Close();

}