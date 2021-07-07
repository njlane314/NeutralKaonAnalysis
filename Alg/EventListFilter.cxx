#ifndef _EventListFilter_cxx_
#define _EventListFilter_cxx_

#include "EventListFilter.h"

EventListFilter::EventListFilter(){

}

///////////////////////////////////////////////////////////////////////////////////////////////

void EventListFilter::SetList(TString ineventlist){

   fEventsToUse.clear();

   std::ifstream input((std::string)ineventlist);

   // Exit if file does not exist/cannot be opened
   assert(input.good());

   int r,s,e;

   while(!input.eof()){

      input >> r >> s >> e;

      //std::cout << r << " " << s << " " << e << std::endl;

      rse theEvent;
      theEvent.run = r;
      theEvent.subrun = s;
      theEvent.event = e;

      fEventsToUse.push_back(theEvent);

   }

}

///////////////////////////////////////////////////////////////////////////////////////////////

bool EventListFilter::EventPassed(int run,int subrun,int event){

   // Search the rse list of this event

   for(size_t i=0;i<fEventsToUse.size();i++){

      if(fEventsToUse.at(i).run == run && fEventsToUse.at(i).event == event && fEventsToUse.at(i).event == event) return true;

   }

   return false;

}

///////////////////////////////////////////////////////////////////////////////////////////////



#endif
