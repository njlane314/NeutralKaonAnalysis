R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so);
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so);

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

void TrackShowers(){

	double POT = 1.0e21;

  	BuildTunes();

  	std::string label = "test";

  	EventAssembler E;

  	E.SetFile("analysisOutputRHC_GENIE_Overaly_Kaon_TEST.root","Background");

  	for(int evt_itr = 0; evt_it < E.GetNEvents(); evt_itr++){

    		if(evt_itr % 10000 == 0) std::cout << evt_itr << "/" << E.GetNEvents() << std::endl;

    		Event e = E.GetEvent(evt_itr);

	}   

  	E.Close();
}
