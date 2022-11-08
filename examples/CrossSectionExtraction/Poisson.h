#ifndef _Poisson_h_
#define _Poisson_h_

///////////////////////////////////////////////////////////////////////////////////////////////

// Calculate n factorial

int fact(int n){
   return (n==0) || (n==1) ? 1 : n* fact(n-1);
}

///////////////////////////////////////////////////////////////////////////////////////////////

// Poisson probability mass calc

double Poiss(int k,double lambda){
   return pow(lambda,k)*exp(-lambda)/fact(k);
}

///////////////////////////////////////////////////////////////////////////////////////////////

// Denominator in Bayes' theorem

const int n_inc = 1000;

double Norm(double a, double b,int N_Obs){

   const double inc = (b-a)/n_inc;

   double N = a;
   double I = 0.0;

   while(N <= b){
      I += Poiss(N_Obs,N)*inc;
      N += inc;
   }

   return I/(b-a);
}

///////////////////////////////////////////////////////////////////////////////////////////////

// Bayesian posterior probability. Uniform prior on the interval [a,b]

double P(double a,double b,double N,int N_Obs){

   if(N > b || N < a) return 0;
   return Poiss(N_Obs,N)/(b-a)/Norm(a,b,N_Obs);
}

///////////////////////////////////////////////////////////////////////////////////////////////

// Make histogram of Bayesian posterior dist for N_Obs observed events. Uniform prior on the
// interval [a,b]

const double Nmin = 0;
const double Nmax = 100;

TH1D* MakePosterior(double a,double b,int N_Obs){

   TH1D* h = new TH1D(("h_Data_Posterior_" + std::to_string(N_Obs)).c_str(),";N (Data);PDF",n_inc,Nmin,Nmax);

   for(int i=1;i<h->GetNbinsX();i++)
      h->SetBinContent(i,P(a,b,h->GetBinCenter(i),N_Obs));
   
   h->Scale(1.0/h->Integral("width"));
   return h;
}

///////////////////////////////////////////////////////////////////////////////////////////////

// Smear a histogram with a 1D Gaussian of standard deviation sigma

TH1D* SmearDist(TH1D* h_in,double sigma){

   TH1D* h = (TH1D*)h_in->Clone("h_Smeared");
   h->Reset();

   TRandom2 *r = new TRandom2();

   for(int i=0;i<100000;i++)
      h->Fill(h_in->GetRandom()+r->Gaus(0,sigma));

   h->Scale(1.0/h->Integral("width"));
   return h;
}

///////////////////////////////////////////////////////////////////////////////////////////////

#endif 
