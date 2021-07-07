#ifndef _Cut_h_
#define _Cut_h_

#include "TEfficiency.h"
#include "Misc.h"

struct Cut {

   std::string fName="";

   double fTotalEvents=0.;
   double fSignalEvents=0.;
   double fGoodRecoEvents=0.;

   double fTotalEventsVar=0.;
   double fSignalEventsVar=0.;
   double fGoodRecoEventsVar=0.;

   double fEventsIn=0.;
   double fEventsOut=0.;

   double fEventsInVar=0.;
   double fEventsOutVar=0.;

   double fSignalEventsIn=0.;
   double fSignalEventsOut=0.;
   double fGoodRecoEventsIn=0.;
   double fGoodRecoEventsOut=0.;

   double fSignalEventsInVar=0.;
   double fSignalEventsOutVar=0.;
   double fGoodRecoEventsInVar=0.;
   double fGoodRecoEventsOutVar=0.;

   double SignalEfficiency(){ return fSignalEventsOut/fSignalEvents; }
   double SignalPurity(){ return fSignalEventsOut/fEventsOut; }

/*
   double SignalPurityErrorLow(){ 
double Pmin = SignalPurity() - PurityError(fSignalEventsOut,fEventsOut-fSignalEventsOut,sqrt(fSignalEventsOutVar),sqrt(fEventsOutVar-fSignalEventsOutVar));
return std::max(Pmin,0.0);
 }

   double SignalPurityErrorHigh(){ 
double Pmax = SignalPurity() + PurityError(fSignalEventsOut,fEventsOut-fSignalEventsOut,sqrt(fSignalEventsOutVar),sqrt(fEventsOutVar-fSignalEventsOutVar));
return std::min(Pmax,1.0);
 }
*/

double SignalPurityErrorLow() { return PurityError_Low(fSignalEventsOut,fEventsOut-fSignalEventsOut,sqrt(fSignalEventsOutVar),sqrt(fEventsOutVar-fSignalEventsOutVar)); }
double SignalPurityErrorHigh() { return PurityError_High(fSignalEventsOut,fEventsOut-fSignalEventsOut,sqrt(fSignalEventsOutVar),sqrt(fEventsOutVar-fSignalEventsOutVar)); }


   double GoodRecoEfficiency(){ return fGoodRecoEventsOut/fGoodRecoEvents; }
   double GoodRecoPurity(){ return fGoodRecoEventsOut/fEventsOut; }

   double Significance(){ return fSignalEventsOut/sqrt(fEventsOut); }

   double BackgroundAcceptance(){ return (fEventsOut-fSignalEventsOut)/(fTotalEvents - fSignalEvents); }

   double PredictedSignal(){ return fSignalEventsOut; };
   double PredictedSignalError(){ return sqrt(fSignalEventsOutVar); };
   
   double PredictedBackground(){ return fEventsOut-fSignalEventsOut; };
   double PredictedBackgroundError(){ return sqrt(fEventsOutVar-fSignalEventsOutVar); };
   
   void Reset(){

      fTotalEvents=0;
      fSignalEvents=0;
      fGoodRecoEvents=0;
      fEventsIn=0;
      fEventsOut=0;
      fSignalEventsIn=0;
      fSignalEventsOut=0;
      fGoodRecoEventsIn=0;
      fGoodRecoEventsOut=0;
   }

};

#endif


