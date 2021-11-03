R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so)
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so)

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets.h"

   void DetVarTest(){

      double POT = 1.0e21; // POT to scale samples to

      BuildTunes();

      // Number of variations to test + CV
      const int n_models = 2;

      std::vector<std::vector<std::string>> SampleNames_Variations(n_models);
      std::vector<std::vector<std::string>> SampleTypes_Variations(n_models);
      std::vector<std::vector<std::string>> SampleFiles_Variations(n_models);

      SampleNames_Variations.at(0).push_back("GENIE Background CV"); 
      SampleTypes_Variations.at(0).push_back("Background");
      SampleFiles_Variations.at(0).push_back("Oct_2021/Systematics/Detvar/analysisOutputFHC_GENIE_Overlay_Background_Detvar_prodgenie_numi_nu_overlay_v08_00_00_53_CV_300k_reco2_run1_reco2.root");

      SampleNames_Variations.at(1).push_back("GENIE Background LYAttenuation"); 
      SampleTypes_Variations.at(1).push_back("Background");
      SampleFiles_Variations.at(1).push_back("Oct_2021/Systematics/Detvar/analysisOutputFHC_GENIE_Overlay_Background_Detvar_prodgenie_numi_nu_overlay_detvar_LY_suppression75attenuation8m_run1_reco2_run1_reco2.root");


      SelectionParameters P = P_FHC_Tune_325;

      std::string label = "GENIE_FHC";

      EventAssembler E;
      SelectionManager M(P);
      M.SetPOT(POT);
      M.ImportSelectorBDTWeights(P.p_SelectorBDT_WeightsDir);
      M.ImportAnalysisBDTWeights(P.p_AnalysisBDT_WeightsDir);


      double SelectedSignal[n_models];
      double SelectedBackground[n_models];

      // Zero everything
      for(int i_var=0;i_var<n_models;i_var++){
         SelectedSignal[i_var] = 0.0;
         SelectedBackground[i_var] = 0.0;
      }


      // Variation loop
      for(int i_var=0;i_var<n_models;i_var++){

         SampleNames = SampleNames_Variations.at(i_var);
         SampleTypes = SampleTypes_Variations.at(i_var);
         SampleFiles = SampleFiles_Variations.at(i_var);

         // Sample Loop
         for(size_t i_s=0;i_s<SampleNames.size();i_s++){

            E.SetFile(SampleFiles.at(i_s));
            if(SampleTypes.at(i_s) != "EXT" && SampleTypes.at(i_s) != "Data") M.AddSample(SampleNames.at(i_s),SampleTypes.at(i_s),E.GetPOT());
            else if(SampleTypes.at(i_s) == "Data") M.AddSample(SampleNames.at(i_s),SampleTypes.at(i_s),Data_POT);
            else if(SampleTypes.at(i_s) == "EXT") M.AddSample(SampleNames.at(i_s),SampleTypes.at(i_s),EXT_POT);

            // Event Loop
            for(int i=0;i<E.GetNEvents();i++){

               Event e = E.GetEvent(i);
               
               if((SampleTypes.at(i_s) == "Background" || SampleTypes.at(i_s) == "Hyperon") && e.NMCTruths > 1) continue;
               if(SampleTypes.at(i_s) == "Background" && e.Mode == "HYP") continue;
               if(SampleTypes.at(i_s) == "Hyperon" && e.Mode != "HYP") continue;

               M.SetSignal(e);                
               M.AddEvent(e);

               //////////// Put your selection here //////////////

               if(!M.FiducialVolumeCut(e)) continue;
               if(!M.TrackCut(e)) continue;
               if(!M.ShowerCut(e)) continue;
               if(!M.ChooseMuonCandidate(e)) continue;
               if(!M.ChooseProtonPionCandidates(e)) continue;
               if(!M.AnalysisBDTCut(e)) continue;       
               if(!M.ConnectednessTest(e)) continue;

               ///////////////////////////////////////////////////

               if(e.EventIsSignal) SelectedSignal[i_var] += e.Weight;
               else SelectedBackground[i_var] += e.Weight;

            }

            E.Close();

         }
      }

      
      // Print selected signal/background for each variation
      for(int i_var=0;i_var<n_models;i_var++){

         std::cout << "Model " << i_var << std::endl;
         std::cout << "Selected Signal = " << SelectedSignal[i_var] << "  Selected Background = " << SelectedBackground[i_var] << std::endl;        

      }
    
    // Calculate uncertainties/fractional uncertainties

      std::vector<double> sigma_events_Signal;
      std::vector<double> sigma_events_Background;
      std::vector<double> sigma_events_Total;

      std::vector<double> frac_errors_Signal;
      std::vector<double> frac_errors_Background;
      std::vector<double> frac_errors_Total;

      for(int i_var=1;i_var<n_models;i_var++){

        double SigmaSignal = abs(SelectedSignal[i_var] - SelectedSignal[0]);    
        double SigmaBackground = abs(SelectedBackground[i_var] - SelectedBackground[0]);    

        sigma_events_Signal.push_back(SigmaSignal);
        frac_errors_Signal.push_back(SigmaSignal/SelectedSignal[0]); 

        sigma_events_Background.push_back(SigmaBackground);
        frac_errors_Background.push_back(SigmaBackground/SelectedBackground[0]); 

      }


      std::cout << "Uncertainty Summary" << std::endl;
      std::cout << "  Variation  | Sigma Signal Events | Fractional Error | Sigma BG Events | Fractional Error" << std::endl;    

      for(int i_var=1;i_var<n_models;i_var++){
                
         std::cout << "Variation " << i_var << "        " << sigma_events_Signal.at(i_var-1) << "             " << frac_errors_Signal.at(i_var-1) << "             " << sigma_events_Background.at(i_var-1) << "            " << frac_errors_Background.at(i_var-1) << std::endl; 
      

      }
 

   }

