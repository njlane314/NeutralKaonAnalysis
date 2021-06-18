#ifndef _Cut_h_
#define _Cut_h_

struct Cut {

   std::string fName="";

   double fTotalEvents=0;
   double fSignalEvents=0;
   double fGoodRecoEvents=0;

   double fEventsIn=0;
   double fEventsOut=0;

   double fSignalEventsIn=0;
   double fSignalEventsOut=0;
   double fGoodRecoEventsIn=0;
   double fGoodRecoEventsOut=0;

   double SignalEfficiency(){ return fSignalEventsOut/fSignalEvents; }
   double SignalPurity(){ return fSignalEventsOut/fEventsOut; }

   double GoodRecoEfficiency(){ return fGoodRecoEventsOut/fGoodRecoEvents; }
   double GoodRecoPurity(){ return fGoodRecoEventsOut/fEventsOut; }

   double Significance(){ return fSignalEventsOut/sqrt(fEventsOut); }

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


