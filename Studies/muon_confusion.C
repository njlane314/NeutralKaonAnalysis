R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so)
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so)

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

void muon_confusion(){

    double POT = 1.25e21; // POT to scale samples to

    BuildTunes();
    SelectionParameters P = P_FHC_Tune_325_NoBDT;
    
    std::string label = "muon_identification";
    std::string SampleType = "muon_sample";

    EventAssembler E(false);
    SelectionManager M(P);

    M.SetBeamMode(kFHC);
    M.SetPOT(POT);
    M.UseFluxWeight(false);
    M.UseGenWeight(false);

    // Assuming this file contains your events
    //E.SetFile("analysisOutputFHC_Overlay_GENIE_Kaon_cthorpe_make_k0s_events_numi_fhc_reco2_reco2_reco2.root",  "signal");
    E.SetFile("analysisOutputFHC_GENIE_Overlay_Background_prodgenie_numi_uboone_overlay_fhc_mcc9_run1_v28_v2_sample0.root", "background");

    M.AddSample("Signal", "Signal", E.GetPOT());

    // Initialize counters for the confusion matrix
    int truePositives = 0;
    int trueNegatives = 0;
    int falsePositives = 0;
    int falseNegatives = 0;

    std::cout << E.GetNEvents() << std::endl;

    for(int i = 0; i < E.GetNEvents(); i++){
        if(i % 10000 == 0) std::cout << i << "/" << E.GetNEvents() << std::endl;

        Event e = E.GetEvent(i);

        M.SetSignal(e);                
        M.AddEvent(e);

        //if(!e.EventIsSignal) continue;

        // Implement your fiducial volume cut or other preselection criteria
        bool passed_FV = M.FiducialVolumeCut(e);
        bool passed_muon = M.ChooseMuonCandidate(e);
        if(!passed_FV) continue;

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
                trueNegatives++;
            }
            else{
                falseNegatives++;
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

    int total = truePositives + trueNegatives + falsePositives + falseNegatives;

    // Now you can print or use the confusion matrix as needed
    std::cout << "Confusion Matrix for Muon Identification:" << std::endl;
    std::cout << "True Positives: " << truePositives << std::endl;
    std::cout << "True Negatives: " << trueNegatives << std::endl;
    std::cout << "False Positives: " << falsePositives << std::endl;
    std::cout << "False Negatives: " << falseNegatives << std::endl;

    gStyle->SetPaintTextFormat(".2f");

    // Create a 2D histogram for the confusion matrix
    TH2F *hConfusionMatrix = new TH2F("hConfusionMatrix", "", 2, 0, 2, 2, 0, 2);
    hConfusionMatrix->GetXaxis()->SetTitleSize(HypPlot::Single_XaxisTitleSize);
    hConfusionMatrix->GetYaxis()->SetTitleSize(HypPlot::Single_YaxisTitleSize);
    hConfusionMatrix->GetXaxis()->SetTitleOffset(HypPlot::Single_XaxisTitleOffset);
    hConfusionMatrix->GetYaxis()->SetTitleOffset(1.0);
    hConfusionMatrix->GetXaxis()->SetLabelSize(HypPlot::Single_XaxisLabelSize);
    hConfusionMatrix->GetYaxis()->SetLabelSize(HypPlot::Single_YaxisLabelSize);
    hConfusionMatrix->GetXaxis()->SetNdivisions(505);
    hConfusionMatrix->GetYaxis()->SetNdivisions(505);

    // Fill the histogram with your confusion matrix values
    // Note: The Fill method parameters are (x, y, value). Adjust indices according to your preference.
    hConfusionMatrix->SetBinContent(1, 2, trueNegatives); // TP
    hConfusionMatrix->SetBinContent(2, 2, falseNegatives); // FN
    hConfusionMatrix->SetBinContent(1, 1, truePositives); // FP
    hConfusionMatrix->SetBinContent(2, 1, falsePositives); // TN
    hConfusionMatrix->Scale(1.0/total);

    // Set labels for axes
    hConfusionMatrix->GetXaxis()->SetBinLabel(1, "Positive");
    hConfusionMatrix->GetXaxis()->SetBinLabel(2, "Negative");
    hConfusionMatrix->GetYaxis()->SetBinLabel(1, "True");
    hConfusionMatrix->GetYaxis()->SetBinLabel(2, "False");

    // Styling
    gStyle->SetPaintTextFormat("g"); // Use general numeric format for cell values
    hConfusionMatrix->SetMarkerSize(1.8);
    hConfusionMatrix->SetMarkerColor(kRed);
    hConfusionMatrix->LabelsDeflate(); // Adjust label spacing
    hConfusionMatrix->SetStats(0);

    // Draw the confusion matrix
    TCanvas *c1 = new TCanvas("c1", "Muon Identification Confusion Matrix", 600, 600);
    hConfusionMatrix->Draw("COL TEXT"); // Draw with color scale and cell values

    // Save the plot
    c1->Draw();
    c1->SaveAs("Muon_Identification_Confusion_Matrix.png");

    // Clean up to avoid memory leaks
    delete c1;
    delete hConfusionMatrix;

    E.Close();
}
