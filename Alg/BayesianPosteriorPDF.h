#ifndef _BayesianPosteriorPDF_h_
#define _BayesianPosteriorPDF_h_

inline TH1D* PosteriorPDF(TEfficiency * E,int bin,std::string name="",double scale=1.0){

   // if scale is zero, posterior PDF is a delta function at x=0 
   if(!(scale > 0.0)){
      TH1D* h_Posterior = new TH1D(("h_Expected"+name).c_str(),";Events;PDF",1,0.0,1e-10);
      h_Posterior->SetBinContent(1,1.0/h_Posterior->GetBinWidth(1));
      return h_Posterior;
   } 

   double conf = 0.9999;
   double inc = 0.0001;

   // Get an initial pair of limits for the histogram

   E->SetStatisticOption(TEfficiency::kBUniform);  
   E->SetConfidenceLevel(conf);

   // Get total events     
   TH1D *h_Total = (TH1D*)E->GetTotalHistogram();

   double TotalEvents =  h_Total->GetBinContent(bin)*scale;

   double Efficiency = E->GetEfficiency(bin);
   double Efficiency_Low = E->GetEfficiency(bin) - E->GetEfficiencyErrorLow(bin);
   double Efficiency_High = E->GetEfficiency(bin) + E->GetEfficiencyErrorUp(bin);

   TH1D *h_Posterior = new TH1D(("h_Expected"+name).c_str(),";Events;PDF",1000000,Efficiency_Low*TotalEvents,Efficiency_High*TotalEvents);

   while(conf > 0.0){

      E->SetConfidenceLevel(conf);

      double old_low = TotalEvents*(E->GetEfficiency(bin) - E->GetEfficiencyErrorLow(bin));
      double old_high = TotalEvents*(E->GetEfficiency(bin) + E->GetEfficiencyErrorUp(bin));

      E->SetConfidenceLevel(conf-inc);

      double new_low = TotalEvents*(E->GetEfficiency(bin) - E->GetEfficiencyErrorLow(bin));
      double new_high = TotalEvents*(E->GetEfficiency(bin) + E->GetEfficiencyErrorUp(bin)); 

      int old_low_bin = h_Posterior->GetXaxis()->FindBin(old_low);
      int old_high_bin = h_Posterior->GetXaxis()->FindBin(old_high);

      int new_low_bin = h_Posterior->GetXaxis()->FindBin(new_low);
      int new_high_bin = h_Posterior->GetXaxis()->FindBin(new_high);

      int nbins_low = new_low_bin - old_low_bin;
      int nbins_high = old_high_bin - new_high_bin;

      double content_low = inc/2/nbins_low;
      double content_high = inc/2/nbins_high;

      for(int i=0;i<nbins_low;i++)
         h_Posterior->AddBinContent(old_low_bin+i,content_low);

      for(int i=0;i<nbins_high;i++)
         h_Posterior->AddBinContent(new_high_bin+i,content_high);

      conf -= inc;
   }


   h_Posterior->Rebin(1000);
   h_Posterior->Scale(1.0/h_Posterior->GetBinWidth(1));

   return h_Posterior;
}

////////////////////////////////////////////////////////////////////////////////

#endif
