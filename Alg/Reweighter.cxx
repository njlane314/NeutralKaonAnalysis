#ifndef _Reweighter_cxx_
#define _Reweighter_cxx_

#include "Reweighter.h"

///////////////////////////////////////////////////////////////////////////////////////////////
// Constructor
// filename = name of file containing histograms for use in reweighting

Reweighter::Reweighter(std::string filename):
   FileName(filename)
{

   f_Hists = TFile::Open(FileName.c_str());

}

///////////////////////////////////////////////////////////////////////////////////////////////
// Set up the central value histogram
// name = name of TH1D object inside the root file

void Reweighter::LoadCVHistogram(std::string name){

   h_CV = (TH1D*)f_Hists->Get(name.c_str());
   if(h_CV == nullptr)
      throw std::invalid_argument("Reweighter.cxx: Unable to find a histogram called " + name + " in file " + FileName);

}

///////////////////////////////////////////////////////////////////////////////////////////////
// Set up the alternative universe histograms
// names = names of TH1D objects inside the root file

void Reweighter::LoadAltHistograms(std::vector<std::string> names){

   h_Alt_v.resize(names.size(),nullptr);

   for(size_t i=0;i<names.size();i++){
      h_Alt_v.at(i) = (TH1D*)f_Hists->Get(names.at(i).c_str());
      if(h_Alt_v.at(i) == nullptr)
         throw std::invalid_argument("Reweighter.cxx: Unable to find a histogram called " + names.at(i) + " in file " + FileName);
   }

}

///////////////////////////////////////////////////////////////////////////////////////////////
// Get the weight for universe u
// var =  value of the variable being used for reweighting
// u = universe to reweight to

double Reweighter::GetWeight(double var,int u) const {

   int bin = h_CV->FindBin(var);
   return h_Alt_v.at(u)->GetBinContent(bin)/h_CV->GetBinContent(bin);

}

#endif
