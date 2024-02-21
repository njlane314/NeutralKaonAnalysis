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

    double SignalEfficiency() const { return fSignalEventsOut/fSignalEvents; }
    double SignalPurity() const { return fSignalEventsOut/fEventsOut; }

    double SignalPurityErrorLow() const { return PurityError_Low(fSignalEventsOut,fEventsOut-fSignalEventsOut,sqrt(fSignalEventsOutVar),sqrt(fEventsOutVar-fSignalEventsOutVar)); }
    double SignalPurityErrorHigh() const { return PurityError_High(fSignalEventsOut,fEventsOut-fSignalEventsOut,sqrt(fSignalEventsOutVar),sqrt(fEventsOutVar-fSignalEventsOutVar)); }

    double GoodRecoEfficiency() const { return fGoodRecoEventsOut/fGoodRecoEvents; }
    double GoodRecoPurity() const { return fGoodRecoEventsOut/fEventsOut; }

    double Significance() const { return fSignalEventsOut/sqrt(fEventsOut); }

    double BackgroundAcceptance() const { return (fEventsOut-fSignalEventsOut)/(fTotalEvents - fSignalEvents); }

    double PredictedSignal() const { return fSignalEventsOut; };
    double PredictedSignalError() const { return sqrt(fSignalEventsOutVar); };
    
    double PredictedBackground() const { return fEventsOut-fSignalEventsOut; };
    double PredictedBackgroundError() const { return sqrt(fEventsOutVar-fSignalEventsOutVar); };
    
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

    void Print() const {
        std::cout << "Cut: " << fName << std::endl;
        std::cout << "Total Events: " << fTotalEvents << ", Variance: " << fTotalEventsVar << std::endl;
        std::cout << "Signal Events: " << fSignalEvents << ", Variance: " << fSignalEventsVar << std::endl;
        std::cout << "Good Reco Events: " << fGoodRecoEvents << ", Variance: " << fGoodRecoEventsVar << std::endl;
        std::cout << "Events In: " << fEventsIn << ", Variance: " << fEventsInVar << std::endl;
        std::cout << "Events Out: " << fEventsOut << ", Variance: " << fEventsOutVar << std::endl;
        std::cout << "Signal Events In: " << fSignalEventsIn << ", Variance: " << fSignalEventsInVar << std::endl;
        std::cout << "Signal Events Out: " << fSignalEventsOut << ", Variance: " << fSignalEventsOutVar << std::endl;
        std::cout << "Good Reco Events In: " << fGoodRecoEventsIn << ", Variance: " << fGoodRecoEventsInVar << std::endl;
        std::cout << "Good Reco Events Out: " << fGoodRecoEventsOut << ", Variance: " << fGoodRecoEventsOutVar << std::endl;

        std::cout << "Signal Efficiency: " << SignalEfficiency() << std::endl;
        std::cout << "Signal Purity: " << SignalPurity() << std::endl;
        std::cout << "Signal Purity Error Low: " << SignalPurityErrorLow() << std::endl;
        std::cout << "Signal Purity Error High: " << SignalPurityErrorHigh() << std::endl;
        std::cout << "Good Reco Efficiency: " << GoodRecoEfficiency() << std::endl;
        std::cout << "Good Reco Purity: " << GoodRecoPurity() << std::endl;
        std::cout << "Significance: " << Significance() << std::endl;
        std::cout << "Background Acceptance: " << BackgroundAcceptance() << std::endl;
        std::cout << "Predicted Signal: " << PredictedSignal() << ", Error: " << PredictedSignalError() << std::endl;
        std::cout << "Predicted Background: " << PredictedBackground() << ", Error: " << PredictedBackgroundError() << std::endl;
    }

};

#endif