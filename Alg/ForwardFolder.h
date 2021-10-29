#ifndef _ForwardFolder_h_
#define _ForwardFolder_h_

#include <iostream>

#include "TH1D.h"
#include "TH2D.h"
#include "TFile.h"

class ForwardFolder {

public:

ForwardFolder(std::string label,std::string axistitle,int nbins,double min,double max);
~ForwardFolder();

void AddGenEvent(double truevar,double weight=1.0);
void AddRecoEvent(double recovar,double truevar,double weight=1.0);

TH2D* GetResponseMatrix();

void Write();

void AddDifferentialCrossSection(TH1D *h);

double SetFlux(double flux);
double SetTargets(double targets);

private:

// True distribution
TH1D *h_Gen;

// Reconstructed distribution
TH1D *h_Reco;

// 2D hist of selected events, gen and reco
TH2D *h_Reco_Gen;

// 2D hist of selected events, gen and reco
TH2D *h_Response;

// Efficiency in reco space
TH1D *h_Eff;

// Original differential cross section
TH1D *h_TrueCrossSection;

// Forward folded differential cross section
TH1D *h_FoldedCrossSection;

// Measured cross section in reco space
TH1D *h_RecoCrossSection;

std::string fLabel="";

double fTargets=0.;
double fFlux=0.;

};

#endif
