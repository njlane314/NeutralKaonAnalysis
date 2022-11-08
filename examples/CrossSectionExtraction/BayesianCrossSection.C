R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so)
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so)

#include "BayesianPosteriorPDF.h"
#include "PlottingFunctions.h"
#include "MultiVariateRNG.h"

#include "GetCovMatrix.h"
#include "Poisson.h"

std::vector<double> GENIE_xsec = {2.026,2.026};
std::vector<double> NuWro_Default_xsec = {2.063,2.063};
std::vector<double> NuWro_NoFSI_xsec = {2.070,2.070};
std::vector<double> NuWro_MA500_xsec = {1.89,1.89};
std::vector<double> NuWro_MA800_xsec = {1.919,1.919};
std::vector<double> NuWro_MA1200_xsec = {2.208,2.208};
std::vector<double> NuWro_MA1500_xsec = {2.47,2.47};

std::vector<double> Y = {-1000,1000};

TGraph *g_GENIE_xsec = new TGraph(GENIE_xsec.size(),&(GENIE_xsec[0]),&(Y[0]));
TGraph *g_NuWro_Default_xsec = new TGraph(NuWro_Default_xsec.size(),&(NuWro_Default_xsec[0]),&(Y[0]));
TGraph *g_NuWro_NoFSI_xsec = new TGraph(NuWro_NoFSI_xsec.size(),&(NuWro_NoFSI_xsec[0]),&(Y[0]));
TGraph *g_NuWro_MA500_xsec = new TGraph(NuWro_MA500_xsec.size(),&(NuWro_MA500_xsec[0]),&(Y[0]));
TGraph *g_NuWro_MA800_xsec = new TGraph(NuWro_MA800_xsec.size(),&(NuWro_MA800_xsec[0]),&(Y[0]));
TGraph *g_NuWro_MA1200_xsec = new TGraph(NuWro_MA1200_xsec.size(),&(NuWro_MA1200_xsec[0]),&(Y[0]));
TGraph *g_NuWro_MA1500_xsec = new TGraph(NuWro_MA1500_xsec.size(),&(NuWro_MA1500_xsec[0]),&(Y[0]));

const double T = 6.5318e29;
const double Gamma = 0.639;

double CrossSection(double N,double B,double Phi,double Eff){
   return ((double)N-B)/T/Phi/Gamma/Eff*1e40;
}

void BayesianCrossSection(){

   gStyle->SetHistTopMargin(0.);
   const int MAX_Obs = 7;

   // Open files containing covariance matrices
   std::string label="test";
   TFile *f = new TFile(("rootfiles/" + label + "_CrossSectionCov.root").c_str());
   TFile *f_Systematics = new TFile(("rootfiles/" + label + "_CrossSectionCov.root").c_str());
   TFile *f_Detector = new TFile(("rootfiles/" + label + "_Detector_CrossSectionCov.root").c_str());

   TH1D* h_CV;
   f->GetObject("CV",h_CV);
   h_CV->SetDirectory(0);

   TH2D* h_Cov,*h_Cov_Detector;
   f_Systematics->GetObject("Cov",h_Cov);
   f_Detector->GetObject("Cov",h_Cov_Detector);
   h_Cov->SetDirectory(0);
   h_Cov_Detector->SetDirectory(0);

   TEfficiency* Eff,*BG_Acc;
   f->GetObject("Efficiency",Eff);
   f->GetObject("Background_Acceptance",BG_Acc);
   Eff->SetDirectory(0);
   BG_Acc->SetDirectory(0);

   TMatrixDSym Cov(kMAX);
   TMatrixDSym FCov(kMAX);

   for(int i=1;i<kMAX+1;i++){
      for(int j=1;j<kMAX+1;j++){
         Cov[i-1][j-1] = h_Cov->GetBinContent(i,j) + h_Cov_Detector->GetBinContent(i,j);       
         FCov[i-1][j-1] = Cov[i-1][j-1]/h_CV->GetBinContent(i)/h_CV->GetBinContent(j);
      }
   }
 
   gSystem->Exec("mkdir -p Plots/");
   DrawMatrix(Cov,h_Cov,"Plots/" + label + "_Cov",true,true);
   DrawMatrix(FCov,h_Cov,"Plots/" + label + "_FCov",true,true);

   double Eff_CV = h_CV->GetBinContent(1);
   double Flux_CV = h_CV->GetBinContent(2);
   double BG_CV = h_CV->GetBinContent(3);

   f->Close();
   f_Detector->Close(); 

   TFile *f_out = TFile::Open(("rootfiles/" + label + "_PDFs.root").c_str(),"RECREATE");

   // Make the Posterior PDFs describing the statistical errors
   TH1D *h_Eff = PosteriorPDF(Eff,1,"Efficiency",1.0/Eff->GetTotalHistogram()->GetBinContent(1));
   TH1D *h_BG = PosteriorPDF(BG_Acc,1,"BG");
   MultiVariateRNG* R_Cov = new MultiVariateRNG(1234,Cov,{0,0,0});

   h_Eff->Write();
   h_BG->Write();

   std::vector<TH1D*> h_SmearedCrossSection_v(MAX_Obs+1);
   std::vector<TH1D*> h_Data_v(MAX_Obs+1);
   THStack *hs_Smeared = new THStack("hs",";#sigma (10^{-40} cm^{2});PDF (1/10^{-40} cm^{2})");

   const int nthrows = 500000;

   for(int i_h=0;i_h<MAX_Obs+1;i_h++){

      std::cout << "Getting PDFs for obs = " << i_h << std::endl;

      h_Data_v.at(i_h) = MakePosterior(0,5*MAX_Obs,i_h);

      double min = 1e10,max=0.0;
      for(int i=0;i<nthrows/100;i++){
         std::vector<double> sys_fluc = R_Cov->GetParameterSet();
         double n = h_Data_v.at(i_h)->GetRandom();
         double e = h_Eff->GetRandom() + sys_fluc.at(0);
         double flux = Flux_CV + sys_fluc.at(1);
         double bg = h_BG->GetRandom() + sys_fluc.at(2);
         min = std::min(CrossSection(n,bg,flux,e),min);
         max = std::max(CrossSection(n,bg,flux,e),max);
      }

      h_SmearedCrossSection_v.at(i_h) = new TH1D(("CrossSection_"+std::to_string(i_h)).c_str(),";#sigma (10^{40} cm^{2});PDF (1/10^{-40} cm^{2})",500,std::max(0.0,min),max);

      for(int i=0;i<nthrows;i++){
         if(i % nthrows == 0) std::cout << 100*i/nthrows << " \% " << std::endl;
         // Calculate systematic fluctuations
         std::vector<double> sys_fluc = R_Cov->GetParameterSet();
         double n = h_Data_v.at(i_h)->GetRandom();
         double e = h_Eff->GetRandom() + sys_fluc.at(0);
         double flux = Flux_CV + sys_fluc.at(1);
         double bg = h_BG->GetRandom() + sys_fluc.at(2);
         h_SmearedCrossSection_v.at(i_h)->Fill(CrossSection(n,bg,flux,e));
      }

      h_SmearedCrossSection_v.at(i_h)->SetLineWidth(2);
      h_SmearedCrossSection_v.at(i_h)->SetLineColor(i_h+1);
      if(i_h+1 == 5) h_SmearedCrossSection_v.at(i_h)->SetLineColor(40);
      h_SmearedCrossSection_v.at(i_h)->Scale(1.0/h_SmearedCrossSection_v.at(i_h)->Integral("width"));
      hs_Smeared->Add(h_SmearedCrossSection_v.at(i_h));

      h_SmearedCrossSection_v.at(i_h)->Write();
      h_Data_v.at(i_h)->Write();     
   }   

   // Draw the plot

   TCanvas *c = new TCanvas("c","c",800,600);

   TPad *p_plot = new TPad("pad1","pad1",0,0,1,0.85);
   TPad *p_legend = new TPad("pad2","pad2",0,0.85,1,1);

   p_legend->SetBottomMargin(0);
   p_legend->SetTopMargin(0.1);
   p_plot->SetTopMargin(0.01);

   TLegend *l = new TLegend(0.1,0.0,0.9,1.0);
   l->SetBorderSize(0);

   for(size_t i_h=0;i_h<h_SmearedCrossSection_v.size();i_h++) l->AddEntry(h_SmearedCrossSection_v.at(i_h),("N_{Obs} = " + std::to_string(i_h)).c_str(),"L");

   TLegend *l_Watermark = new TLegend(0.45,0.900,0.89,0.985);
   l_Watermark->SetBorderSize(0);
   l_Watermark->SetMargin(0.005);
   l_Watermark->SetTextAlign(32);
   l_Watermark->SetTextSize(0.05);
   l_Watermark->SetTextFont(62);

   l_Watermark->SetHeader("MicroBooNE Simulation, In Progress","R");

   TLegend *l_POT = new TLegend(0.55,0.820,0.89,0.900);
   l_POT->SetBorderSize(0);
   l_POT->SetMargin(0.005);
   l_POT->SetTextAlign(32);
   l_POT->SetTextSize(0.05);

   const int nhists =  h_SmearedCrossSection_v.size();
   int ncols = 3;
   if(nhists > 6) ncols = 4;
   if(nhists > 12) ncols = 5;

   l->SetNColumns(ncols);

   p_legend->Draw();
   p_legend->cd();
   l->Draw();
   c->cd();
   p_plot->Draw();
   p_plot->cd();

   hs_Smeared->Draw("nostack HIST");
   hs_Smeared->SetMaximum(1.2); 
   hs_Smeared->Draw("nostack HIST");

   hs_Smeared->GetXaxis()->SetTitleSize(0.05);
   hs_Smeared->GetYaxis()->SetTitleSize(0.05);
   hs_Smeared->GetXaxis()->SetTitleOffset(0.95);
   hs_Smeared->GetYaxis()->SetTitleOffset(0.95);
   hs_Smeared->GetXaxis()->SetLabelSize(0.045);
   hs_Smeared->GetYaxis()->SetLabelSize(0.045);

   l_Watermark->Draw(); 

   TLegend *l_Generators = new TLegend(0.4,0.55,0.89,0.9);
   l_Generators->SetBorderSize(0);
 
   g_GENIE_xsec->SetLineStyle(9);
   g_GENIE_xsec->SetLineWidth(2);
   g_GENIE_xsec->SetLineColor(1);
   g_GENIE_xsec->Draw("L same");
   l_Generators->AddEntry(g_GENIE_xsec,"GENIE v3","L");

   g_NuWro_Default_xsec->SetLineStyle(9);
   g_NuWro_Default_xsec->SetLineWidth(2);
   g_NuWro_Default_xsec->SetLineColor(2);
   g_NuWro_Default_xsec->Draw("L same");
   l_Generators->AddEntry(g_NuWro_Default_xsec,"NuWro 21","L");

   g_NuWro_MA500_xsec->SetLineStyle(9);
   g_NuWro_MA500_xsec->SetLineWidth(2);
   g_NuWro_MA500_xsec->SetLineColor(4);
   g_NuWro_MA500_xsec->Draw("L same");
   l_Generators->AddEntry(g_NuWro_MA500_xsec,"NuWro 21 M_{A} = 0.5 GeV","L");

   g_NuWro_MA1500_xsec->SetLineStyle(9);
   g_NuWro_MA1500_xsec->SetLineWidth(2);
   g_NuWro_MA1500_xsec->SetLineColor(6);
   g_NuWro_MA1500_xsec->Draw("L same");
   l_Generators->AddEntry(g_NuWro_MA1500_xsec,"NuWro 21 M_{A} = 1.5 GeV","L");

   l_Generators->Draw();

   c->Print(("Plots/" + label + "_PosteriorPDFs_BothRuns.C").c_str());
   c->Print(("Plots/" + label + "_PosteriorPDFs_BothRuns.png").c_str());
   c->Print(("Plots/" + label + "_PosteriorPDFs_BothRuns.pdf").c_str());

   g_GENIE_xsec->Write("GENIE_xsec");
   g_NuWro_Default_xsec->Write("NuWro_Default_xsec");
   g_NuWro_NoFSI_xsec->Write("NuWro_NoFSI_xsec");
   g_NuWro_MA500_xsec->Write("NuWro_MA500_xsec");
   g_NuWro_MA800_xsec->Write("NuWro_MA800_xsec");
   g_NuWro_MA1200_xsec->Write("NuWro_MA1200_xsec");
   g_NuWro_MA1500_xsec->Write("NuWro_MA1500_xsec");

   f_out->Close();
}
