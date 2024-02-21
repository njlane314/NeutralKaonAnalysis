R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so)
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so)

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

#include <cmath>

const double Mpi = 0.139; // rest mass of the pion in GeV
const double MK = 0.493; // rest mass of the kaon in GeV
const double p_pi = sqrt(MK*MK / 4 - Mpi*Mpi); // momentum of the pion in the kaon rest frame

double energy_pi(double p) {
    return sqrt(Mpi*Mpi + p*p);
}

double energy_K(double p) {
    return sqrt(MK*MK + p*p);
}

double restricted_phase_space(double pK) {
    double beta = pK / energy_K(pK); 
    double gamma = 1.0 / sqrt(1 - beta*beta); 
    double p_thresh_pion = 0.1; // pion momentum threshold in GeV

    double A = (sqrt(Mpi*Mpi + p_thresh_pion*p_thresh_pion) - gamma*energy_pi(p_pi)) / (beta*gamma*p_pi);
    double B = (- sqrt(Mpi*Mpi + p_thresh_pion*p_thresh_pion) + gamma*energy_pi(p_pi)) / (beta*gamma*p_pi);

    if(A < -1) A = -1;
    if(B > 1) B = 1;

    if (A > B) return 0;
    else return (B - A) / 2;
}

void restricted_phase() {
    const int nPoints = 200;
    double pK_min = 0; // Min kaon momentum in GeV
    double pK_max = 2.0; // Max kaon momentum in GeV
    double step = (pK_max - pK_min) / nPoints;

    std::vector<double> pK_values(nPoints);
    std::vector<double> phase_space_values(nPoints);

    for (int i = 0; i < nPoints; ++i) {
        pK_values[i] = pK_min + i * step;
        phase_space_values[i] = restricted_phase_space(pK_values[i]);
    }

    /*gStyle->SetOptTitle(0); // Turn off the default title
    gStyle->SetTextFont(42); // Set the global font to a more pleasing one
    gStyle->SetLabelFont(42, "XYZ"); // Set the font for axis labels
    gStyle->SetTitleFont(42, "XYZ"); // Set the font for axis titles
    gStyle->SetStatFont(42); // Set the font for stats box
    gStyle->SetLegendFont(42); // Set the font for legends*/

    TCanvas *c1 = new TCanvas("", "", 800, 600); // Slightly larger canvas
    c1->SetLeftMargin(0.12); // Adjust the left margin
    c1->SetBottomMargin(0.12); // Adjust the bottom margin

    TGraph *graph = new TGraph(nPoints, &pK_values[0], &phase_space_values[0]);
    graph->SetTitle(";p_{K^{0}} (GeV/c);f(p_{K^{0}})"); // Set title with axes labels

    // Improve the graph's aesthetics
    graph->SetMarkerStyle(0); // Set marker style
    graph->SetMarkerSize(0.8); // Set marker size
    graph->SetMarkerColor(kBlack); // Set marker color
    graph->SetLineColor(kBlack); // Set line color
    graph->SetLineWidth(2); // Set line width

    // Draw the graph with axes and markers
    graph->Draw("ACP");

    // Make the axes look nicer
    graph->GetXaxis()->SetTitleSize(HypPlot::Single_XaxisTitleSize);
    graph->GetYaxis()->SetTitleSize(HypPlot::Single_YaxisTitleSize);
    graph->GetXaxis()->SetTitleOffset(HypPlot::Single_XaxisTitleOffset);
    graph->GetYaxis()->SetTitleOffset(1.15);
    graph->GetXaxis()->SetLabelSize(HypPlot::Single_XaxisLabelSize);
    graph->GetYaxis()->SetLabelSize(HypPlot::Single_YaxisLabelSize);
    graph->GetXaxis()->SetNdivisions(510); // Improve x-axis divisions
    graph->GetYaxis()->SetNdivisions(510); // Improve y-axis divisions
    graph->GetYaxis()->SetRangeUser(0.85, 1.02);

    // Update the canvas to draw the changes
    c1->Modified();
    c1->Update();

    // Save the canvas to a file
    c1->SaveAs("restricted_phase_space.png");

    return 0;
}
