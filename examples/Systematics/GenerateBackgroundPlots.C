R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so)
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so)

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

   void GenerateBackgroundPlots(){

      double POT = 1.0e21; // POT to scale samples to

      BuildTunes();
      //ImportSamples(sNuWroFullFHC);

      SampleNames.push_back("GENIE Background");
      SampleTypes.push_back("Background");
      SampleFiles.push_back("analysisOutputFHC_GENIE_Overlay_Background_Test.root");

      SelectionParameters P = P_FHC_Tune_325;

      std::string label = "test";

      // Setup selection manager. Set POT to scale sample to, import the BDT weights
      EventAssembler E;
      SelectionManager M(P);
      M.SetPOT(POT);
      M.ImportSelectorBDTWeights(P.p_SelectorBDT_WeightsDir);

      M.SetupHistograms(25,1.05,1.5,";Invariant Mass (GeV/c^{2});Events");
      M.AddSystematic(0,600,"Flux_HP");

      FluxWeighter F(1);
      F.PrepareSysUniv(600);

      // Sample Loop
      for(size_t i_s=0;i_s<SampleNames.size();i_s++){

         E.SetFile(SampleFiles.at(i_s));
         if(SampleTypes.at(i_s) != "EXT" && SampleTypes.at(i_s) != "Data") M.AddSample(SampleNames.at(i_s),SampleTypes.at(i_s),E.GetPOT());
         else if(SampleTypes.at(i_s) == "Data") M.AddSample(SampleNames.at(i_s),SampleTypes.at(i_s),Data_POT);
         else if(SampleTypes.at(i_s) == "EXT") M.AddSample(SampleNames.at(i_s),SampleTypes.at(i_s),EXT_POT);

         // Event Loop
         for(int i=0;i<E.GetNEvents();i++){

            Event e = E.GetEvent(i);

            M.SetSignal(e);                
            M.AddEvent(e);

            if(!M.FiducialVolumeCut(e)) continue;
            if(!M.TrackCut(e)) continue;
            if(!M.ShowerCut(e)) continue;
            if(!M.ChooseMuonCandidate(e)) continue;
            if(!M.ChooseProtonPionCandidates(e)) continue;

            double fluxweight = F.GetFluxWeight(e);
            std::vector<double> fluxweights_HP = F.GetSysWeightV(e,1);
            for(size_t i_w=0;i_w<fluxweights_HP.size();i_w++) fluxweights_HP.at(i_w) /= fluxweight;     

            double W = ProtonPionInvariantMass(e.DecayProtonCandidate,e.DecayPionCandidate);

            M.FillHistograms(e,W);                
            M.FillHistogramsSys(e,W,"Flux_HP",fluxweights_HP);

         }

         E.Close();

      }

      M.DrawHistogramsSys("Flux_HP",label);

      M.GetCovarianceMatrix("Flux_HP",0);

   }
