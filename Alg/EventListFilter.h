#ifndef _EventListFilter_h_
#define _EventListFilter_h_

#include <cassert>

#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <iostream>
#include "TString.h"

struct rse {

   int run;
   int subrun;
   int event;

};

class EventListFilter {

   public:

      EventListFilter();

      void SetList(TString ineventlist);
        
      bool EventPassed(int run,int subrun,int event);

   private:

      std::vector<rse> fEventsToUse;



};

#endif
