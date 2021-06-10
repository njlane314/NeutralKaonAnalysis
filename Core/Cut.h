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


};

#endif


