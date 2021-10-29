#include "ForwardFolder.h"

ForwardFolder::ForwardFolder(std::string label,std::string axistitle,int nbins,double min,double max){


   h_Gen = new TH1D("h_Gen",("All Events;True " + axistitle + ";Events").c_str(),nbins,min,max);
   h_Reco = new TH1D("h_Reco",("Selected Events;Reco " + axistitle + ";Events").c_str(),nbins,min,max);

   h_Reco_Gen = new TH2D("h_Reco_Gen",("Selected Events;Reco " + axistitle + ";True " + axistitle).c_str(),nbins,min,max,nbins,min,max); 

   h_Response = new TH2D("h_Response",("Response Matrix;Reco " + axistitle + ";True " + axistitle).c_str(),nbins,min,max,nbins,min,max); 

   h_Eff = new TH1D("h_Eff",("Efficiency;Reco " + axistitle + ";Events").c_str(),nbins,min,max);

   fLabel = label;

}

ForwardFolder::~ForwardFolder(){

   delete h_Gen;
   delete h_Reco;
   delete h_Reco_Gen;
   delete h_Response;
   delete h_Eff;
}

void ForwardFolder::AddGenEvent(double truevar,double weight){

   h_Gen->Fill(truevar,weight);

}

void ForwardFolder::AddRecoEvent(double recovar,double truevar,double weight){

   h_Reco->Fill(recovar,weight);
   h_Reco_Gen->Fill(recovar,truevar,weight);

}

TH2D* ForwardFolder::GetResponseMatrix(){

   for(int i=1;i<h_Gen->GetNbinsX()+1;i++){

      for(int j=1;j<h_Gen->GetNbinsX()+1;j++){

         if(h_Gen->GetBinContent(j) > 0) h_Response->SetBinContent(i,j,h_Reco_Gen->GetBinContent(i,j)/h_Gen->GetBinContent(j));
         else h_Response->SetBinContent(i,j,0);


      }

   }

      for(int i=1;i<h_Eff->GetNbinsX()+1;i++){

         double numerator=0.;
         double denominator=0.;            

         for(int j=1;j<h_Eff->GetNbinsX()+1;j++) numerator += h_Response->GetBinContent(i,j)*h_Reco->GetBinContent(j);
         for(int j=1;j<h_Eff->GetNbinsX()+1;j++) denominator += h_Response->GetBinContent(i,j)*h_Gen->GetBinContent(j);

         if(denominator > 0) h_Eff->SetBinContent(i,numerator/denominator);
         else h_Eff->SetBinContent(i,0.);

      }

}

double ForwardFolder::SetFlux(double flux){

fFlux = flux;

}

double ForwardFolder::SetTargets(double targets){

fTargets = targets;

}

void ForwardFolder::AddDifferentialCrossSection(TH1D *h){

   h_TrueCrossSection = h; 
   h_TrueCrossSection->SetTitle("True Differential Cross Section");

   h_FoldedCrossSection = (TH1D*)h_TrueCrossSection->Clone("h_FoldedCrossSection");
   h_FoldedCrossSection->SetTitle("Forward Folded Differential Cross Section");

   for(int i=1;i<h_Gen->GetNbinsX()+1;i++){

      double Content=0.;

      for(int j=1;j<h_Gen->GetNbinsX()+1;j++){

         Content += h_TrueCrossSection->GetBinContent(j)*h_Response->GetBinContent(i,j);          

      }

      h_FoldedCrossSection->SetBinContent(i,Content);

   }


h_RecoCrossSection = (TH1D*)h_Reco->Clone();
h_RecoCrossSection->SetTitle("Measured Differential Cross Section");


for(int i=1;i<h_Reco->GetNbinsX();i++){

double Content;

//if(h_Eff->GetBinContent(i) > 0) Content = h_Reco->GetBinContent(i)/h_Eff->GetBinContent(i)/fTargets/fFlux/h_Reco->GetBinWidth(i)/40/0.64;
if(h_Eff->GetBinContent(i) > 0) Content = h_Reco->GetBinContent(i)/fTargets/fFlux/h_Reco->GetBinWidth(i)/0.64;
else Content = 0.;

h_RecoCrossSection->SetBinContent(i,Content);

}


}


void ForwardFolder::Write(){

TFile *f = TFile::Open((fLabel + "_ResponseMatrices.root").c_str(),"RECREATE");

h_Gen->Write("TrueDist");
h_Reco->Write("RecoDist");
h_Reco_Gen->Write("RecoVsTrueDist");
h_Response->Write("ResponseMatrix");
h_Eff->Write("Efficiency");
h_TrueCrossSection->Write("TrueDiffXsec");
h_FoldedCrossSection->Write("FoldedDiffXsec");
h_RecoCrossSection->Write("MeasuredDiffXsec");


f->Close();

}




