#ifndef _Reweighter_h_
#define _Reweighter_h_

#include <iostream>
#include <string>
#include <vector>
#include "TFile.h"
#include "TH1D.h"

class Reweighter {

   public: 

      Reweighter(std::string filename);
      void LoadAltHistograms(std::vector<std::string> names);
      void LoadCVHistogram(std::string name);
      double GetWeight(double var,int u) const;
      TH1D* GetCVHistogram() const {return (TH1D*)h_CV->Clone("h_CV");}
      TH1D* GetAltHistogram(int u) const {return (TH1D*)h_Alt_v.at(u)->Clone(("h_Alt_"+std::to_string(u)).c_str());}

   private:

      const std::string FileName;
      TFile* f_Hists=nullptr;
      TH1D* h_CV=nullptr;
      std::vector<TH1D*> h_Alt_v;

};

#endif
