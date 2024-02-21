R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so)
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so)

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

#include <cmath>
#include <TFeldmanCousins.h>

void proton_decay_sens() {
    // Signal selection efficiency


    // Constants for lifetime calculations
    const double protonLifetimeFactor = 2.7;
    const double neutronLifetimeFactor = 3.3;
    const double AvogadroNumberProtons = 2.7e32;
    const double AvogadroNumberNeutrons = 3.3e32;

    // Confidence level and background estimation
    double cl = 0.90; // 90% confidence level

    double eps1 = 0.1;
    double eps2 = 0.2;
    double b1 = 0.1;
    double b2 = 0.01;

    // Exposure values in kilotons*year
    const int nPoints = 5; // Number of points in the grLifetimeLimitProton1
    double exposures[nPoints];

    double lifetimeLimitProton1[nPoints];
    double lifetimeLimitProton2[nPoints];
    double lifetimeLimitProton3[nPoints];
    double lifetimeLimitProton4[nPoints];
    
    double logExposureStart = log10(1); // log10 of starting exposure in kiloton*years, avoiding log(0)
    double logExposureEnd = log10(400); // log10 of ending exposure in kiloton*years
    double logExposureStep = (logExposureEnd - logExposureStart) / (nPoints - 1);

    // Initialize Feldman-Cousins calculator
    TFeldmanCousins fc(cl);

    for (int i = 0; i < nPoints; ++i) {
        // Use the anti-log to get the actual exposure
        exposures[i] = pow(10, logExposureStart + i * logExposureStep);

        // Calculate the upper limit S for the observed number of events
        // S scales with the background and exposure
        double S1 = fc.CalculateUpperLimit(0, b1 * exposures[i]);
        double S2 = fc.CalculateUpperLimit(0, b1 * exposures[i]);
        double S3 = fc.CalculateUpperLimit(0, b2 * exposures[i]);
        double S4 = fc.CalculateUpperLimit(0, b2 * exposures[i]);

        // Calculate the lifetime limits using the previously defined formulas
        lifetimeLimitProton1[i] = protonLifetimeFactor * exposures[i] * eps1 * AvogadroNumberProtons / S1;
        lifetimeLimitProton2[i] = protonLifetimeFactor * exposures[i] * eps2 * AvogadroNumberNeutrons / S2;
        lifetimeLimitProton3[i] = protonLifetimeFactor * exposures[i] * eps1 * AvogadroNumberNeutrons / S3;
        lifetimeLimitProton4[i] = protonLifetimeFactor * exposures[i] * eps2 * AvogadroNumberNeutrons / S4;
    }

    // grLifetimeLimitProton1s for plotting
    TGraph* grLifetimeLimitProton1 = new TGraph(nPoints, exposures, lifetimeLimitProton1);
    TGraph* grLifetimeLimitProton2 = new TGraph(nPoints, exposures, lifetimeLimitProton2);
    TGraph* grLifetimeLimitProton3 = new TGraph(nPoints, exposures, lifetimeLimitProton3);
    TGraph* grLifetimeLimitProton4 = new TGraph(nPoints, exposures, lifetimeLimitProton4);

    grLifetimeLimitProton1->SetLineWidth(2); // Thicker line for visibility
    grLifetimeLimitProton2->SetLineWidth(2);
    grLifetimeLimitProton3->SetLineWidth(2);
    grLifetimeLimitProton4->SetLineWidth(2);

    // Canvas to draw the grLifetimeLimitProton1s
    TCanvas* c1 = new TCanvas("", "", 800, 600);
    c1->SetLogx(); // Set the x-axis to log scale
    c1->SetLogy();
    c1->SetRightMargin(0.05); // Adjust the right margin if necessary
    c1->SetTopMargin(0.05);   // Adjust the top margin if necessary
    c1->SetLeftMargin(0.15);  // Increase the left margin if y-axis labels are cut off
    c1->SetBottomMargin(0.15);

        // Set line colors using predefined ROOT colors
    grLifetimeLimitProton1->SetLineColor(kRed);
    grLifetimeLimitProton1->SetLineStyle(2); // Solid line

    grLifetimeLimitProton2->SetLineColor(kRed);
    grLifetimeLimitProton2->SetLineStyle(1); // Dashed line

    grLifetimeLimitProton3->SetLineColor(kBlue);
    grLifetimeLimitProton3->SetLineStyle(2); // Dotted line

    grLifetimeLimitProton4->SetLineColor(kBlue);
    grLifetimeLimitProton4->SetLineStyle(1); // Dash-dotted line

    // Draw the grLifetimeLimitProton1 for proton decay sensitivity
    grLifetimeLimitProton1->SetTitle(";Exposure (kTxYear);Lifetime 90\% C.L. (Year)");
    grLifetimeLimitProton1->GetXaxis()->SetTitleSize(HypPlot::Single_XaxisTitleSize);
    grLifetimeLimitProton1->GetYaxis()->SetTitleSize(HypPlot::Single_YaxisTitleSize);
    grLifetimeLimitProton1->GetXaxis()->SetTitleOffset(HypPlot::Single_XaxisTitleOffset);
    grLifetimeLimitProton1->GetYaxis()->SetTitleOffset(1.15);
    grLifetimeLimitProton1->GetXaxis()->SetTitleOffset(1.15);
    grLifetimeLimitProton1->GetXaxis()->SetLabelSize(HypPlot::Single_XaxisLabelSize);
    grLifetimeLimitProton1->GetYaxis()->SetLabelSize(HypPlot::Single_YaxisLabelSize);
    grLifetimeLimitProton1->GetXaxis()->SetNdivisions(510); // Improve x-axis divisions
    grLifetimeLimitProton1->GetYaxis()->SetNdivisions(510); // Improve y-axis divisions
    grLifetimeLimitProton1->GetYaxis()->SetRangeUser(2e31, 1e35);
    grLifetimeLimitProton1->GetXaxis()->SetRangeUser(1, 500);
    grLifetimeLimitProton1->Draw("AL");

    // Draw the grLifetimeLimitProton1 for neutron decay sensitivity
    grLifetimeLimitProton2->SetTitle(";Exposure (kiloton*year);Lifetime Limit (years)");
    grLifetimeLimitProton2->GetXaxis()->SetTitleSize(HypPlot::Single_XaxisTitleSize);
    grLifetimeLimitProton2->GetYaxis()->SetTitleSize(HypPlot::Single_YaxisTitleSize);
    grLifetimeLimitProton2->GetXaxis()->SetTitleOffset(HypPlot::Single_XaxisTitleOffset);
    grLifetimeLimitProton2->GetYaxis()->SetTitleOffset(1.15);
    grLifetimeLimitProton2->GetXaxis()->SetLabelSize(HypPlot::Single_XaxisLabelSize);
    grLifetimeLimitProton2->GetYaxis()->SetLabelSize(HypPlot::Single_YaxisLabelSize);
    grLifetimeLimitProton2->GetXaxis()->SetNdivisions(510); // Improve x-axis divisions
    grLifetimeLimitProton2->GetYaxis()->SetNdivisions(510); // Improve y-axis divisions
    grLifetimeLimitProton2->GetYaxis()->SetRangeUser(1e31, 1e35);
    grLifetimeLimitProton2->GetXaxis()->SetRangeUser(1, 500);
    grLifetimeLimitProton2->Draw("L SAME");

    grLifetimeLimitProton3->SetTitle(";Exposure (kiloton*year);Lifetime Limit (years)");
    grLifetimeLimitProton3->GetXaxis()->SetTitleSize(HypPlot::Single_XaxisTitleSize);
    grLifetimeLimitProton3->GetYaxis()->SetTitleSize(HypPlot::Single_YaxisTitleSize);
    grLifetimeLimitProton3->GetXaxis()->SetTitleOffset(HypPlot::Single_XaxisTitleOffset);
    grLifetimeLimitProton3->GetYaxis()->SetTitleOffset(1.15);
    grLifetimeLimitProton3->GetXaxis()->SetLabelSize(HypPlot::Single_XaxisLabelSize);
    grLifetimeLimitProton3->GetYaxis()->SetLabelSize(HypPlot::Single_YaxisLabelSize);
    grLifetimeLimitProton3->GetXaxis()->SetNdivisions(510); // Improve x-axis divisions
    grLifetimeLimitProton3->GetYaxis()->SetNdivisions(510); // Improve y-axis divisions
    grLifetimeLimitProton3->GetYaxis()->SetRangeUser(1e31, 1e35);
    grLifetimeLimitProton3->GetXaxis()->SetRangeUser(1, 500);
    grLifetimeLimitProton3->Draw("L SAME");

    grLifetimeLimitProton4->SetTitle(";Exposure (kiloton*year);Lifetime Limit (years)");
    grLifetimeLimitProton4->GetXaxis()->SetTitleSize(HypPlot::Single_XaxisTitleSize);
    grLifetimeLimitProton4->GetYaxis()->SetTitleSize(HypPlot::Single_YaxisTitleSize);
    grLifetimeLimitProton4->GetXaxis()->SetTitleOffset(HypPlot::Single_XaxisTitleOffset);
    grLifetimeLimitProton4->GetYaxis()->SetTitleOffset(1.15);
    grLifetimeLimitProton4->GetXaxis()->SetLabelSize(HypPlot::Single_XaxisLabelSize);
    grLifetimeLimitProton4->GetYaxis()->SetLabelSize(HypPlot::Single_YaxisLabelSize);
    grLifetimeLimitProton4->GetXaxis()->SetNdivisions(510); // Improve x-axis divisions
    grLifetimeLimitProton4->GetYaxis()->SetNdivisions(510); // Improve y-axis divisions
    grLifetimeLimitProton4->GetYaxis()->SetRangeUser(1e31, 1e35);
    grLifetimeLimitProton4->GetXaxis()->SetRangeUser(1, 500);
    grLifetimeLimitProton4->Draw("L SAME");

    // Legend for the grLifetimeLimitProton1
    TLegend* legend = new TLegend(0.2, 0.63, 0.5, 0.93);
    legend->SetFillColor(0); // Transparent background
    legend->SetFillStyle(0); // Transparent fill
    legend->SetBorderSize(0); // No border
    legend->AddEntry(grLifetimeLimitProton1, "#epsilon = 0.1, B = 0.1", "l");
    legend->AddEntry(grLifetimeLimitProton2, "#epsilon = 0.2, B = 0.1", "l");
    legend->AddEntry(grLifetimeLimitProton3, "#epsilon = 0.1, B = 0.01", "l");
    legend->AddEntry(grLifetimeLimitProton4, "#epsilon = 0.2, B = 0.01", "l");
    legend->Draw();

    // Save the canvas to a file
    c1->SaveAs("lifetime_limit_sensitivity.png");
}
