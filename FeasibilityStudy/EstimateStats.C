R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so);
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so);

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

void EstimateStats(){

  double POT = 1.0e21; // POT to scale samples to

  BuildTunes();
  SelectionParameters P = P_FHC_Tune_325_NoBDT;

  std::string label = "test";

  // Setup selection manager. Set POT to scale sample to, import the BDT weights
  EventAssembler E(false);
  SelectionManager M(P);
  M.SetPOT(POT);
  //M.ImportSelectorBDTWeights(P.p_SelectorBDT_WeightsDir);
  //M.ImportAnalysisBDTWeights(P.p_AnalysisBDT_WeightsDir);
  M.UseFluxWeight(false);
  M.UseGenWeight(false); 

  double Signal = 0.0;
  double Signal_var = 0.0;

  E.SetFile("analysisOutputFHC_GENIE_Overlay_Kaon.root", "Background");
  //E.SetFile("analysisOutputFHC_GENIE_Background_Overlay_prodgenie_numi_uboone_overlay_fhc_mcc9_run1_v28_v2_sample0.root","Background");
  M.AddSample("Background","Background",E.GetPOT());

  // Event Loop
  for(int i=0;i<E.GetNEvents();i++){

    if(i % 10000 == 0) std::cout << i << "/" << E.GetNEvents() << std::endl;

    Event e = E.GetEvent(i);

    M.SetSignal(e);                
    M.AddEvent(e);

    if(!e.PrimaryKaon.size()) continue;

    bool found_pip=false,found_pim=false;
    for(size_t i_tr=0;i_tr<e.NMCTruths;i_tr++){
      if(!e.InActiveTPC.at(i_tr)) continue;
      if(abs(e.Lepton.at(i_tr).PDG) == 13 && e.Lepton.at(i_tr).ModMomentum > 0.1){
        bool found_kaon=false;
        for(SimParticle kaon : e.NeutralKaonDecayK0SL){
          if(kaon.PDG == 310 && kaon.MCTruthIndex == i_tr) found_kaon = true;     
        }
        if(!found_kaon) continue;
        for(SimParticle decay : e.KaonDecay){
          if(decay.Origin == 7 && decay.PDG == 211 && decay.ModMomentum > 0.1/* && decay.MCTruthIndex == i_tr*/) found_pip=true;
          if(decay.Origin == 7 && decay.PDG == -211 && decay.ModMomentum > 0.1/* && decay.MCTruthIndex == i_tr*/) found_pim=true;        
        }   
      }
    }

    if(found_pip && found_pim){
      Signal += e.Weight;
      Signal_var += e.Weight*e.Weight;
    }

  }

  E.Close();

  std::cout << "Signal = " << Signal << "  +/-  " << sqrt(Signal_var) << std::endl;
}
