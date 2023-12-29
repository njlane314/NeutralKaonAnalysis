R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so);
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so);

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

double CalculateSignalAccuracy(int TP, int FP) {
    if (TP + FP == 0) return 0; 
    return static_cast<double>(TP) / (TP + FP);
}

double GetSignalAccuracy(double PID_thresh, double length_thresh, double displacement_thresh){

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

    int TP = 0;
    int FP = 0;

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
        double length = -1;
        for(size_t i = 0; i < e.TracklikePrimaryDaughters.size(); i++){

            double trackPID = e.TracklikePrimaryDaughters.at(i).Track_LLR_PID;
            double trackLength = e.TracklikePrimaryDaughters.at(i).TrackLength;
            double trackDisplacement = e.TracklikePrimaryDaughters.at(i).Displacement;
           
            int trackPDG = e.TracklikePrimaryDaughters.at(i).TrackTruePDG;

            if(trackPID < PID_thresh || trackLength < length_thresh || trackDisplacement > displacement_thresh) continue; 

            if(length < trackLength){
                length = trackLength;
                i_longest = i;
            }
        }

        if(i_longest == -1) continue;
    
        int trackPDG = e.TracklikePrimaryDaughters.at(i_longest).TrackTruePDG;
        if(abs(trackPDG) == 13){
            TP += 1;
        }
        else {
            FP += 1;
        }
    }

    E.Close();

    return CalculateSignalAccuracy(TP, FP);

}

void MuonSelection() {
    const double pidStep = 0.02; 
    const double lengthStep = 50.0;
    const double displacementThreshold = 15.0; 

    TMultiGraph *mg = new TMultiGraph();
    TLegend *legend = new TLegend(0.7, 0.7, 0.9, 0.9); 

    int colorIndex = 1; 

    for (double lengthThreshold = 200.0; lengthThreshold < 300.0; lengthThreshold += lengthStep) {
        const int nPoints = static_cast<int>((2.0 - (0.6)) / pidStep) + 1; 
        double *pidValues = new double[nPoints];
        double *accuracies = new double[nPoints];

        int i = 0;
        for(double pidThreshold = 0.6; pidThreshold < 1.0; pidThreshold += pidStep){
            double accuracy = GetSignalAccuracy(pidThreshold, lengthThreshold, displacementThreshold);
            std::cout << accuracy << std::endl;
            pidValues[i] = pidThreshold;
            accuracies[i] = accuracy;
            ++i;
        }

        TGraph *gr = new TGraph();
        for(int i = 0; i < nPoints; i++){
            gr->SetPoint(gr->GetN(), pidValues[i], accuracies[i]);

        }

        gr->SetLineColor(TColor::GetColorPalette(colorIndex++));
        gr->SetMarkerStyle(23);
        gr->SetMarkerSize(3);

        mg->Add(gr);
        legend->AddEntry(gr, gr->GetTitle(), "l");

        delete[] pidValues;
        delete[] accuracies;
    }

    TCanvas *c1 = new TCanvas("c1", "", 800, 600);
    mg->Draw("AL");
    mg->SetTitle(";PID Threshold;Signal Accuracy");
    mg->GetYaxis()->SetLimits(0.0, 1.0);
    mg->GetXaxis()->SetLimits(0.6, 1.0);
    //legend->Draw();
    c1->SaveAs("Plots/MuonSelectionOptimisation.png");

    delete mg;
    delete c1;
    delete legend;
}