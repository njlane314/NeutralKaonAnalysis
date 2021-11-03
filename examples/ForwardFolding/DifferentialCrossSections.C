#include "TH1D.h"
#include "TTree.h"
#include "THStack.h"
#include "TCanvas.h"
#include "TFile.h"
#include "TLegend.h"

const double MLambda = 1.116;
const double p_cms = 0.101;

std::pair<double,double> Decay(double LambdaMomentum,double theta){

   // Calculate Lambda boost factor
   double beta = LambdaMomentum/sqrt(LambdaMomentum*LambdaMomentum+MLambda*MLambda);
   double gamma = 1.0/sqrt(1.0-beta*beta);

   double p_prot_z = beta*gamma*sqrt(0.938*0.938+p_cms*p_cms) + gamma*p_cms*cos(theta);
   double p_prot_y = p_cms*sin(theta);
   double p_prot = sqrt(p_prot_z*p_prot_z+p_prot_y*p_prot_y);

   double p_pi_z = beta*gamma*sqrt(0.1396*0.1396+p_cms*p_cms) - gamma*p_cms*cos(theta);
   double p_pi_y = (-1)*p_cms*sin(theta);
   double p_pi = sqrt(p_pi_z*p_pi_z+p_pi_y*p_pi_y);

   return std::make_pair(p_prot,p_pi);

}

void DifferentialCrossSections(){

   // File containing NuWro hyperon events
   TFile *f = TFile::Open("NuMI_FHC_events_MA1000.root");

   double frac = 1;

   int nbins = 10;

   TH1D *h_Muon_Momentum = new TH1D("h_Muon_Momentum",";Muon Momentum (GeV/c);d#sigma/dP (cm^{2}/GeV/c)",nbins,0,6.0);
   TH1D *h_Lambda_Momentum = new TH1D("h_Lambda_Momentum",";Lambda Momentum (GeV/c);d#sigma/dP (cm^{2}/GeV/c)",nbins,0,2.0);
   TH1D *h_Proton_Momentum = new TH1D("h_Proton_Momentum",";Proton Momentum (GeV/c);d#sigma/dP (cm^{2}/GeV/c)",nbins,0,1.5);
   TH1D *h_Pion_Momentum = new TH1D("h_Pion_Momentum",";Pion Momentum (GeV/c);d#sigma/dP (cm^{2}/GeV/c)",nbins,0,0.5);

   TF1 *func = new TF1("func","sin(x)",0.0,3.1415);

   string histname;

   if ((!f) || f->IsZombie()) { delete f; return; } // just a precaution
   TTree *t;
   f->GetObject("treeout", t);
   if (!t) { delete f; return; } // just a precaution
   t->SetMakeClass(1); // tree in MakeClass mode
   t->SetBranchStatus("*", 0); // disable all branches

   const Int_t kMaxin = 2;
   const Int_t kMaxout = 2;
   const Int_t kMaxpost = 100;

   Int_t in;
   Int_t out;
   Int_t post;

   Double_t intt[kMaxin];
   Double_t inx[kMaxin];
   Double_t iny[kMaxin];
   Double_t inz[kMaxin];

   t->SetBranchStatus("in", 1); // activate branch
   t->SetBranchAddress("in", &in);
   t->SetBranchStatus("in.t", 1); // activate branch
   t->SetBranchAddress("in.t", intt);
   t->SetBranchStatus("in.x", 1); // activate branch
   t->SetBranchAddress("in.x", inx);
   t->SetBranchStatus("in.y", 1); // activate branch
   t->SetBranchAddress("in.y", iny);
   t->SetBranchStatus("in.z", 1); // activate branch
   t->SetBranchAddress("in.z", inz);


   Double_t outt[kMaxout];
   Double_t outx[kMaxout];
   Double_t outy[kMaxout];
   Double_t outz[kMaxout];
   Double_t out_mass[kMaxout];

   t->SetBranchStatus("out", 1); // activate branch
   t->SetBranchAddress("out", &out);
   t->SetBranchStatus("out.t", 1); // activate branch
   t->SetBranchAddress("out.t", outt);
   t->SetBranchStatus("out.x", 1); // activate branch
   t->SetBranchAddress("out.x", outx);
   t->SetBranchStatus("out.y", 1); // activate branch
   t->SetBranchAddress("out.y", outy);
   t->SetBranchStatus("out.z", 1); // activate branch
   t->SetBranchAddress("out.z", outz);
   t->SetBranchStatus("out._mass", 1); // activate branch
   t->SetBranchAddress("out._mass", out_mass);

   Double_t postt[kMaxpost];
   Double_t postx[kMaxpost];
   Double_t posty[kMaxpost];
   Double_t postz[kMaxpost];
   Double_t post_mass[kMaxpost];

   t->SetBranchStatus("post", 1); // activate branch
   t->SetBranchAddress("post", &post);
   t->SetBranchStatus("post.t", 1); // activate branch
   t->SetBranchAddress("post.t", postt);
   t->SetBranchStatus("post.x", 1); // activate branch
   t->SetBranchAddress("post.x", postx);
   t->SetBranchStatus("post.y", 1); // activate branch
   t->SetBranchAddress("post.y",posty);
   t->SetBranchStatus("post.z", 1); // activate branch
   t->SetBranchAddress("post.z", postz);
   t->SetBranchStatus("post._mass", 1); // activate branch
   t->SetBranchAddress("post._mass", post_mass);


   Double_t weight;

   t->SetBranchStatus("weight",1);
   t->SetBranchAddress("weight",&weight);

   Int_t in_pdg[kMaxin];
   Int_t out_pdg[kMaxout];
   Int_t post_pdg[kMaxpost];
   //check pdg values


   t->SetBranchStatus("in.pdg",1);
   t->SetBranchAddress("in.pdg",in_pdg);
   t->SetBranchStatus("out.pdg",1);
   t->SetBranchAddress("out.pdg",out_pdg);
   t->SetBranchStatus("post.pdg",1);
   t->SetBranchAddress("post.pdg",post_pdg);

   double P;

   int n=0;

   Long64_t nevents = t->GetEntries();

   for (Long64_t i = 0; i < nevents*frac; i++) {
      t->GetEntry(i);

      if(in_pdg[0] != -14) continue;

      n++;

      bool found_Lambda=false;

      for(int k=0;k<post;k++){

         P = sqrt(postt[k]*postt[k] - post_mass[k]*post_mass[k])/1e3;

         if(post_pdg[k] == 3122){ 
            h_Lambda_Momentum->Fill(P,weight);
            found_Lambda = true;
            break; 
         }

      }


      if(found_Lambda){

         double theta = func->GetRandom();

         std::pair<double,double> momenta = Decay(P,theta); 

         h_Proton_Momentum->Fill(momenta.first,weight);
         h_Pion_Momentum->Fill(momenta.second,weight);

         double P_muon = sqrt(outt[0]*outt[0] - out_mass[0]*out_mass[0])/1e3;

         h_Muon_Momentum->Fill(P_muon,weight);

      }

   }



   //normalise to total cross section

   h_Muon_Momentum->Scale(1.0/n/h_Muon_Momentum->GetBinWidth(1));
   h_Muon_Momentum->Scale(40);

   h_Lambda_Momentum->Scale(1.0/n/h_Lambda_Momentum->GetBinWidth(1));
   h_Lambda_Momentum->Scale(40);

   h_Proton_Momentum->Scale(1.0/n/h_Proton_Momentum->GetBinWidth(1));
   h_Proton_Momentum->Scale(40);

   h_Pion_Momentum->Scale(1.0/n/h_Pion_Momentum->GetBinWidth(1));
   h_Pion_Momentum->Scale(40);

   TFile *f_out = TFile::Open("DifferentialCrossSections.root","RECREATE");

   h_Muon_Momentum->Write("Muon_Momentum");
   h_Lambda_Momentum->Write("Lambda_Momentum");
   h_Proton_Momentum->Write("Proton_Momentum");
   h_Pion_Momentum->Write("Pion_Momentum");

}
