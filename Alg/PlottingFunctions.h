#ifndef _PlottingFunctions_h_
#define _PlottingFunctions_h_

#include "TH1D.h"

const double _EPSILON_ = 1e-5;

///////////////////////////////////////////////////////////////////////////////////////////////

TH1D * MakeErrorBand(std::map<std::string,TH1D*> hists){

   TH1D *h_first = hists.begin()->second;
   TH1D *h_errors = new TH1D("h_errors","",h_first->GetNbinsX(),h_first->GetBinLowEdge(1),h_first->GetBinLowEdge(h_first->GetNbinsX()+1));

   // iterate over the bins of the contributing histograms
   for(int i_b=0;i_b<h_first->GetNbinsX()+1;i_b++){

      std::map<std::string, TH1D*>::iterator it;

      double events = 0.0;
      double variance = 0.0;

      for (it = hists.begin(); it != hists.end(); it++)
      {
         if(it->first == "Data" || it->first == "All") continue;
         events += it->second->GetBinContent(i_b);
         variance += it->second->GetBinError(i_b)*it->second->GetBinError(i_b);
      }

      h_errors->SetBinContent(i_b,events);
      h_errors->SetBinError(i_b,sqrt(variance));

   }

   return h_errors;

}

///////////////////////////////////////////////////////////////////////////////////////////////

TH1D * MakeRatioPlot(std::map<std::string,TH1D*> hists,TH1D* h_MCError){

   //std::cout << "Setting histogram errors" << std::endl;

   TH1D *h_first = hists.begin()->second;

   //std::cout << "Setting up error hist with params: " << "bins=" << h_first->GetNbinsX() << "  low edge=" << h_first->GetBinLowEdge(1) << "  high edge=" << h_first->GetBinLowEdge(h_first->GetNbinsX()+1) << std::endl;

   std::string x_axis_title = h_first->GetXaxis()->GetTitle();

   TH1D *h_Ratio = new TH1D("h_Ratio",";;Data/MC",h_first->GetNbinsX(),h_first->GetBinLowEdge(1),h_first->GetBinLowEdge(h_first->GetNbinsX()+1));

   // iterate over the bins of the contributing histograms
   for(int i_b=1;i_b<h_first->GetNbinsX()+1;i_b++){

      double mc_events = hists["Signal"]->GetBinContent(i_b)
         + hists["OtherHYP"]->GetBinContent(i_b)
         + hists["OtherNu"]->GetBinContent(i_b)
         + hists["Dirt"]->GetBinContent(i_b)
         + hists["EXT"]->GetBinContent(i_b);


      double mc_variance = h_MCError->GetBinError(i_b)*h_MCError->GetBinError(i_b);

      double data_events = hists["Data"]->GetBinContent(i_b);
      double data_variance = hists["Data"]->GetBinError(i_b)*hists["Data"]->GetBinError(i_b);

      double ratio = data_events/mc_events;
      double ratio_variance = ratio*ratio*(data_variance/data_events/data_events + mc_variance/mc_events/mc_events);


      if(data_events < _EPSILON_ || mc_events < _EPSILON_){ ratio = 1.0; ratio_variance = 0.0; }


      //      std::cout << "Looing at bin " << i_b << "  events = "  << mc_events << " sigma = " << sqrt(mc_variance) << " Data = " << data_events << " sigma = " << sqrt(data_variance) <<  " data/mc = " << ratio <<  " sigma = " << sqrt(ratio_variance) << std::endl;

      h_Ratio->SetBinContent(i_b,ratio);
      h_Ratio->SetBinError(i_b,sqrt(ratio_variance));

   }

   return h_Ratio;

}

///////////////////////////////////////////////////////////////////////////////////////////////

double GetHistMax(TH1D *h){

   double max = -1e10;

   for(int i_b=1;i_b<h->GetNbinsX()+1;i_b++){

      if(h->GetBinContent(i_b)+h->GetBinError(i_b) > max) max = h->GetBinContent(i_b)+h->GetBinError(i_b);

   }

   return max;

}

///////////////////////////////////////////////////////////////////////////////////////////////

#endif
