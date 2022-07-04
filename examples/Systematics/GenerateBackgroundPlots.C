R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so)
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so)

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

#include "FluxWeight2.h"
#include "GenG4WeightHandler2.h"
#include "SystematicsHeader.h"

   // Generate histogram with the full suite of systematics
   // dials excluding the detector uncertainties

   void GenerateBackgroundPlots(){

      double POT = 1.0e21; // POT to scale samples to
      std::string label = "test";
      int Mode = kFHC;

      SampleNames.push_back("GENIE Background");
      SampleTypes.push_back("Background");
      SampleFiles.push_back("run1_FHC/analysisOutputFHC_Overlay_GENIE_Background_All.root");

      SampleNames.push_back("GENIE Hyperon");
      SampleTypes.push_back("Hyperon");
      SampleFiles.push_back("run1_FHC/analysisOutputFHC_Overlay_GENIE_Hyperon_All.root");

      BuildTunes();
      SelectionParameters P = P_FHC_Tune_325_NoBDT;

      // Setup selection manager. Set POT to scale sample to, import the BDT weights
      EventAssembler E;
      SelectionManager M(P);
      M.SetPOT(POT);
      M.SetBeamMode(Mode);
      M.ImportSelectorBDTWeights(P.p_SelectorBDT_WeightsDir);
      //M.ImportAnalysisBDTWeights(P.p_AnalysisBDT_WeightsDir);

      M.SetupHistograms(20,1.05,1.5,";Invariant Mass (GeV/c^{2});Events");

      // Setup Systematics //

      std::vector<std::string> Sys_Dials;
      for(int i_sys=0;i_sys<fuMAX;i_sys++){
         M.AddSystematic(FluxU_SysTypes.at(i_sys),FluxU_Universes.at(i_sys),FluxU_Str.at(i_sys));
         Sys_Dials.push_back(FluxU_Str.at(i_sys));
      }
      for(int i_sys=0;i_sys<guMAX;i_sys++){
         M.AddSystematic(GeneratorU_SysTypes.at(i_sys),GeneratorU_Universes.at(i_sys),GeneratorU_Str.at(i_sys));
         Sys_Dials.push_back(GeneratorU_Str.at(i_sys));
      }
      for(int i_sys=0;i_sys<g4uMAX;i_sys++){
         M.AddSystematic(ReintU_SysTypes.at(i_sys),ReintU_Universes.at(i_sys),ReintU_Str.at(i_sys));
         Sys_Dials.push_back(ReintU_Str.at(i_sys));
      }
      for(int i_sys=0;i_sys<muMAX;i_sys++){
         M.AddSystematic(MiscU_SysTypes.at(i_sys),MiscU_Universes.at(i_sys),MiscU_Str.at(i_sys));
         Sys_Dials.push_back(MiscU_Str.at(i_sys));
      }

      ///////////////////////

      GW2::GenG4WeightHandler2 G;  
      FluxWeighter FluxWeightCalc(Mode);
      FluxWeightCalc.PrepareHPUniv();
      FluxWeightCalc.PrepareBeamlineUniv();

      // Sample Loop
      for(size_t i_s=0;i_s<SampleNames.size();i_s++){

         E.SetFile(SampleFiles.at(i_s));
         if(SampleTypes.at(i_s) != "EXT" && SampleTypes.at(i_s) != "Data") M.AddSample(SampleNames.at(i_s),SampleTypes.at(i_s),E.GetPOT());
         else if(SampleTypes.at(i_s) == "Data") M.AddSample(SampleNames.at(i_s),SampleTypes.at(i_s),Data_POT);
         else if(SampleTypes.at(i_s) == "EXT") M.AddSample(SampleNames.at(i_s),SampleTypes.at(i_s),EXT_POT);

         // Event Loop
         for(int i=0;i<E.GetNEvents();i++){

            if(i % 20000 == 0) std::cout << i << "/" << E.GetNEvents() << std::endl;

            Event e = E.GetEvent(i);

            M.SetSignal(e);                
            M.AddEvent(e);

            if(!M.FiducialVolumeCut(e)) continue;
            if(!M.TrackCut(e)) continue;
            if(!M.ShowerCut(e)) continue;
            if(!M.ChooseMuonCandidate(e)) continue;
            if(!M.ChooseProtonPionCandidates(e)) continue;
            //if(!M.AnalysisBDTCut(e)) continue;       
            //if(!M.ConnectednessTest(e)) continue;

            G.LoadEvent(e); 
            e.Weight *= FluxWeightCalc.GetFluxWeight(e)*G.GetCVWeight();               

            // Systematics Calculations //               

            std::map<std::string,std::vector<double>> sys_weights;
            for(int i_sys=0;i_sys<fuMAX;i_sys++) sys_weights[FluxU_Str.at(i_sys)] = std::vector<double>(FluxU_Universes.at(i_sys),1.0);
            for(int i_sys=0;i_sys<guMAX;i_sys++) sys_weights[GeneratorU_Str.at(i_sys)] = std::vector<double>(GeneratorU_Universes.at(i_sys),1.0); 
            for(int i_sys=0;i_sys<g4uMAX;i_sys++) sys_weights[ReintU_Str.at(i_sys)] = std::vector<double>(ReintU_Universes.at(i_sys),1.0);
            for(int i_sys=0;i_sys<muMAX;i_sys++) sys_weights[MiscU_Str.at(i_sys)] = std::vector<double>(MiscU_Universes.at(i_sys),1.0);

            if(SampleTypes.at(i_s) != "EXT" && SampleTypes.at(i_s) != "Data" && SampleTypes.at(i_s) != "Dirt"){

               // Flux
               for(int i_w=0;i_w<Flux_HP_Universes;i_w++) sys_weights["Flux_HP"] = FluxWeightCalc.GetSysWeightV(e,"Flux_HP");              
               for(size_t i_d=0;i_d<Beamline_Dials.size();i_d++) sys_weights[Beamline_Dials.at(i_d)] = FluxWeightCalc.GetSysWeightV(e,Beamline_Dials.at(i_d)); 
               sys_weights["POT"] = {0.98,1.02};

               // Generator
               //double TunedCentralValue = G.GetWeights("TunedCentralValue_UBGenie").at(0);
               sys_weights["All_UBGenie"] = G.GetWeights("All_UBGenie");
               for(size_t i_d=0;i_d<GW2::AltModel_Dials.size();i_d++) sys_weights[GW2::AltModel_Dials.at(i_d)] = G.GetWeights(GW2::AltModel_Dials.at(i_d));
               sys_weights["RPA_CCQE_UBGenie"] = G.GetWeights("RPA_CCQE_UBGenie");

               // Geant 4
               for(int i_sys=0;i_sys<g4uMAX-1;i_sys++) sys_weights[ReintU_Str.at(i_sys)] = G.GetWeights(GW2::G4_Dials.at(i_sys));
               if(e.EventHasNeutronScatter) sys_weights["G4_Neutron_Dual"] = {1.26,0.74};
            }

            if(SampleTypes.at(i_s) == "Dirt") sys_weights["DirtScale"] = { 1.0-25.0/35.0 , 1.0+25.0/35.0 };

            ////////////////////////////

            double var = ProtonPionInvariantMass(e.DecayProtonCandidate,e.DecayPionCandidate);
            M.FillHistograms(e,var);                
            for(size_t i_sys=0;i_sys<Sys_Dials.size();i_sys++) M.FillHistogramsSys(e,var,Sys_Dials.at(i_sys),sys_weights[Sys_Dials.at(i_sys)]);               
         }

         E.Close();
      }

      M.DrawHistograms(label);
      for(size_t i_sys=0;i_sys<Sys_Dials.size();i_sys++){
         M.DrawHistogramsSys(label,Sys_Dials.at(i_sys));
         M.GetCovarianceMatrix(label,Sys_Dials.at(i_sys));
      }    
   }
