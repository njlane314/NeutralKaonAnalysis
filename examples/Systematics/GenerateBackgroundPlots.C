R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so)
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so)

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

   const int flux_HP_universes = 600;

   void GenerateBackgroundPlots(){

      double POT = 1.0e21; // POT to scale samples to

      BuildTunes();
      //ImportSamples(sNuWroFullFHC);

      SampleNames.push_back("GENIE Background");
      SampleTypes.push_back("Background");
      SampleFiles.push_back("HyperonTrees_Sys.root");
/*
      SampleNames.push_back("GENIE Hyperon");
      SampleTypes.push_back("Hyperon");
      SampleFiles.push_back("analysisOutputFHC_GENIE_Overlay_Hyperon_cthorpe_prod_numi_uboone_overlay_fhc_mcc9_run1_v51_GENIE_hyperon_real_GENIE_reco2_reco2.root");
*/
      SelectionParameters P = P_FHC_Tune_325;

      std::string label = "test";

      // Setup selection manager. Set POT to scale sample to, import the BDT weights
      EventAssembler E;
      SelectionManager M(P);
      M.SetPOT(POT);
      M.ImportSelectorBDTWeights(P.p_SelectorBDT_WeightsDir);
      M.ImportAnalysisBDTWeights(P.p_AnalysisBDT_WeightsDir);

      M.SetupHistograms(20,1.05,1.5,";Invariant Mass (GeV/c^{2});Events");

      // Flux HP
      M.AddSystematic(kMultisim,flux_HP_universes,"Flux_HP");

      // Flux beamline geometry
      for(int i_d=0;i_d<Beamline_Universes/2;i_d++)
         M.AddSystematic(kDualUnisim,2,beamline_labels[i_d]);

      FluxWeighter FluxWeightCalc(1);
      FluxWeightCalc.PrepareHPUniv(flux_HP_universes);
      FluxWeightCalc.PrepareBeamlineUniv();

      // GENIE systematics
      M.AddSystematic(0,600,"All_UBGenie");
      for(int i_d=0;i_d<MAX_GenUnisims-2;i_d++)
         M.AddSystematic(kSingleUnisim,1,GenUnisim_names[i_d]);

      M.AddSystematic(kDualUnisim,2,"RPA_CCQE_UBGenie");

      GenG4WeightHandler G;  

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
            if(!M.AnalysisBDTCut(e)) continue;       
            if(!M.ConnectednessTest(e)) continue;

            // Flux systematics //

            double fluxweight = FluxWeightCalc.GetFluxWeight(e);

            std::vector<double> fluxweights_HP = FluxWeightCalc.GetSysWeightV(e,1);
            for(size_t i_w=0;i_w<fluxweights_HP.size();i_w++) fluxweights_HP.at(i_w)/=fluxweight;     

            std::vector<double> fluxweights_Beamline = FluxWeightCalc.GetSysWeightV(e,2);
            std::vector<std::vector<double>> fluxweights_Beamline_Vars;
            for(size_t i_var=0;i_var<fluxweights_Beamline.size()/2;i_var++)
               fluxweights_Beamline_Vars.push_back({fluxweights_Beamline.at(2*i_var),fluxweights_Beamline.at(2*i_var+1)});

            // Generator systematics //

            G.LoadEvent(e);

            double TunedCentralValue = G.GetWeights("TunedCentralValue_UBGenie").at(0);

            if(!(TunedCentralValue > 0)) continue;

            // Multisim weights
            std::vector<double> weights_Gen_Multisim = G.GetWeights("All_UBGenie");
            for(size_t i_w=0;i_w<weights_Gen_Multisim.size();i_w++) weights_Gen_Multisim.at(i_w) /= TunedCentralValue;

            // Unisims
            std::vector<std::vector<double>> weights_SingleUnisims(MAX_GenUnisims-2);


            for(int i_uni=0;i_uni<MAX_GenUnisims-2;i_uni++) {
               if(i_uni != gv_XSecShape_CCMEC) weights_SingleUnisims.at(i_uni).push_back(G.GetWeights(GenUnisim_names[i_uni]).at(0)/TunedCentralValue);
               else weights_SingleUnisims.at(i_uni).push_back(G.GetWeights(GenUnisim_names[i_uni]).at(1)/TunedCentralValue);
            }             


            std::vector<double> weights_DualUnisims;

            weights_DualUnisims.push_back(G.GetWeights("RPA_CCQE_UBGenie").at(0)/TunedCentralValue);
            weights_DualUnisims.push_back(G.GetWeights("RPA_CCQE_UBGenie").at(1)/TunedCentralValue);


            ////////////////////////////

            double W = ProtonPionInvariantMass(e.DecayProtonCandidate,e.DecayPionCandidate);


            M.FillHistograms(e,W);                
            M.FillHistogramsSys(e,W,"Flux_HP",fluxweights_HP);

            for(int i_d=0;i_d<Beamline_Universes/2;i_d++){
               M.FillHistogramsSys(e,W,beamline_labels[i_d],fluxweights_Beamline_Vars.at(i_d));

            }


            M.FillHistogramsSys(e,W,"All_UBGenie",weights_Gen_Multisim);

            for(int i_d=0;i_d<MAX_GenUnisims-2;i_d++){
               M.FillHistogramsSys(e,W,GenUnisim_names[i_d],weights_SingleUnisims.at(i_d));
            }        


            M.FillHistogramsSys(e,W,"RPA_CCQE_UBGenie",weights_DualUnisims);
         }

         E.Close();

      }

      M.DrawHistograms(label);

      // Flux systematics     

      M.DrawHistogramsSys("Flux_HP",kMultisim,label);

      TMatrixD Cov_Flux_HP = M.GetCovarianceMatrix("Flux_HP",kMultisim);

      for(int i_d=0;i_d<Beamline_Universes/2;i_d++){
         M.DrawHistogramsSys(beamline_labels[i_d],kDualUnisim,label);
         Cov_Flux_HP += M.GetCovarianceMatrix(beamline_labels[i_d],kDualUnisim);
      }

      TMatrixD Cov_Flux_POT = Cov_Flux_HP;

      for(int i=0;i<Cov_Flux_POT.GetNcols();i++)
         for(int j=0;j<Cov_Flux_POT.GetNcols();j++)
            Cov_Flux_POT[i][j] = 0.02*0.02*M.GetPrediction(i+1)*M.GetPrediction(j+1);              

      Cov_Flux_HP += Cov_Flux_POT;

      std::cout << "Flux covariance matrix" << std::endl;
      Cov_Flux_HP.Print();

      // Generator systematics

      M.DrawHistogramsSys("All_UBGenie",kMultisim,label);
      TMatrixD Cov_Gen = M.GetCovarianceMatrix("AllUBGENIE",kMultisim);

      for(int i_d=0;i_d<MAX_GenUnisims-2;i_d++){
         M.DrawHistogramsSys(GenUnisim_names[i_d],kSingleUnisim,label);
         Cov_Gen += M.GetCovarianceMatrix(GenUnisim_names[i_d],kSingleUnisim);
      }


      M.DrawHistogramsSys("RPA_CCQE_UBGenie",kDualUnisim,label);
      Cov_Gen +=  M.GetCovarianceMatrix("RPA_CCQE_UBGenie",kDualUnisim);

      std::cout << "Generator covariance matrix" << std::endl;
      Cov_Gen.Print();

      // Combine

      TMatrixD Cov_All = Cov_Flux_HP + Cov_Gen; 

      std::cout << "Flux + Generator covariance matrix" << std::endl;
      Cov_All.Print();  

      std::cout << "Bin by Bin Uncertainties" << std::endl;
      for(int i=0;i<Cov_All.GetNcols();i++) std::cout << sqrt(Cov_All[i][i]) << std::endl;    

   }
