R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so);
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so);

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

// Generic script that loads some data and prints a few variables

void Sandbox(){

  double POT = 1.0e21; // POT to scale samples to

  BuildTunes();

  std::string label = "test";

  // Setup selection manager. Set POT to scale sample to, import the BDT weights
  EventAssembler E;

  double Signal = 0.0;
  double BG = 0.0;
  double Sel_Signal = 0.0;
  double Sel_BG = 0.0;

  // Load an ntuple file
  E.SetFile("analysisOutputFHC_GENIE_Overlay_Background_prodgenie_numi_uboone_overlay_fhc_mcc9_run1_v28_v2_sample0.root","Background");

  // Event Loop
  for(int ievent=0;ievent<E.GetNEvents();ievent++){

    if(ievent % 10000 == 0) std::cout << ievent << "/" << E.GetNEvents() << std::endl;

    // grab an event from the ntuple file
    Event e = E.GetEvent(ievent);

    // ntuple contains several vectors storing info about particles produced in the nu-nucleus interaction
    // print some info from one:
   
    std::cout << ievent << "th event:" << std::endl;
    for(int i_n=0;i_n<e.PrimaryNucleon.size();i_n++){
        std::cout << "pdg=" << e.PrimaryNucleon.at(i_n).PDG << "  momentum=" << e.PrimaryNucleon.at(i_n).ModMomentum << std::endl; 
     }    
    std::cout << std::endl;

    if(ievent > 100) break; // stop after 100 events

  }

  E.Close();

}
