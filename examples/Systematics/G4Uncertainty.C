R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so)
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so)

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets.h"

#include "GenG4WeightHandler.h"

   void G4Uncertainty(){

      double POT = 1.0e21; // POT to scale samples to

      BuildTunes();
      //ImportSamples(sGENIEFullFHC_Test);

      SampleNames.push_back("GENIE Background");
      SampleTypes.push_back("Background");
      SampleFiles.push_back("HyperonTrees_Sys.root");


      SelectionParameters P = P_FHC_Tune_325;

      std::string label = "GENIE_FHC";

      // Setup selection manager. Set POT to scale sample to, import the BDT weights
      EventAssembler E;
      SelectionManager M(P);
      M.SetPOT(POT);
      M.ImportSelectorBDTWeights(P.p_SelectorBDT_WeightsDir);
      M.ImportAnalysisBDTWeights(P.p_AnalysisBDT_WeightsDir);

      // Systematics 

      int nuniv = 1000;

      double SelectedSignal = 0.0;
      double SelectedBackground = 0.0;

      std::vector<std::vector<double>> SelectedSignal_G4_Multisim_V(MAX_G4Multisims);
      std::vector<std::vector<double>> SelectedBackground_G4_Multisim_V(MAX_G4Multisims);

      for(int i_d=0;i_d<MAX_G4Multisims;i_d++){
         SelectedSignal_G4_Multisim_V[i_d].resize(nuniv);
         SelectedBackground_G4_Multisim_V[i_d].resize(nuniv);
         for(int i_u=0;i_u<nuniv;i_u++){
            SelectedSignal_G4_Multisim_V[i_d][i_u] = 0.0;
            SelectedBackground_G4_Multisim_V[i_d][i_u] = 0.0;
         }
      }      

      GenG4WeightHandler G;  

      // Sample Loop
      for(size_t i_s=0;i_s<SampleNames.size();i_s++){

         if(SampleTypes.at(i_s) == "EXT") continue;

         E.SetFile(SampleFiles.at(i_s));
         if(SampleTypes.at(i_s) != "EXT" && SampleTypes.at(i_s) != "Data") M.AddSample(SampleNames.at(i_s),SampleTypes.at(i_s),E.GetPOT());
         else if(SampleTypes.at(i_s) == "Data") M.AddSample(SampleNames.at(i_s),SampleTypes.at(i_s),Data_POT);
         else if(SampleTypes.at(i_s) == "EXT") M.AddSample(SampleNames.at(i_s),SampleTypes.at(i_s),EXT_POT);

         // Event Loop
         for(int i=0;i<E.GetNEvents();i++){

            Event e = E.GetEvent(i);

            M.SetSignal(e);                
            M.AddEvent(e);

            //////////// Put your selection here //////////////

            if(!M.FiducialVolumeCut(e)) continue;
            if(!M.TrackCut(e)) continue;
            if(!M.ShowerCut(e)) continue;
            //if(!M.ChooseMuonCandidate(e)) continue;
            //if(!M.ChooseProtonPionCandidates(e)) continue;
            //if(!M.AnalysisBDTCut(e)) continue;       

            ///////////////////////////////////////////////////

            G.LoadEvent(e);

            // Multisim weights
            std::vector<std::vector<double>> weights_G4_Multisim(MAX_G4Multisims);
            for(int i_m=0;i_m<MAX_G4Multisims;i_m++) weights_G4_Multisim[i_m] = G.GetWeights(G4Multisim_names[i_m]);

            // Update the total weight of selected events in each universe
            if(e.EventIsSignal){
               SelectedSignal += e.Weight;
               for(int i_d=0;i_d<MAX_G4Multisims;i_d++)
                  for(int i_u=0;i_u<nuniv;i_u++)
                     SelectedSignal_G4_Multisim_V[i_d][i_u] += e.Weight*weights_G4_Multisim.at(i_d).at(i_u);               
            }

            else if(SampleTypes.at(i_s) != "EXT" && SampleTypes.at(i_s) != "Data"){
               SelectedBackground += e.Weight;
               for(int i_d=0;i_d<MAX_G4Multisims;i_d++)
                  for(int i_u=0;i_u<nuniv;i_u++)
                     SelectedBackground_G4_Multisim_V[i_d][i_u] += e.Weight*weights_G4_Multisim.at(i_d).at(i_u);               
            }

            else {
               SelectedBackground += e.Weight;
               for(int i_d=0;i_d<MAX_G4Multisims;i_d++)
                  for(int i_u=0;i_u<nuniv;i_u++)
                     SelectedBackground_G4_Multisim_V[i_d][i_u] += e.Weight;               
            }                        

         }

         E.Close();

      }


      std::vector<double> sigma_events_Signal;
      std::vector<double> sigma_events_Background;
      std::vector<double> sigma_events_Total;

      std::vector<double> frac_errors_Signal;
      std::vector<double> frac_errors_Background;
      std::vector<double> frac_errors_Total;


      for(int i_d=0;i_d<MAX_G4Multisims;i_d++){

         double MeanSignal = MeanSD(SelectedSignal_G4_Multisim_V.at(i_d)).first;
         double SigmaSignal = MeanSD(SelectedSignal_G4_Multisim_V.at(i_d)).second;

         sigma_events_Signal.push_back(SigmaSignal);
         frac_errors_Signal.push_back(SigmaSignal/MeanSignal);

         double MeanBackground = MeanSD(SelectedBackground_G4_Multisim_V.at(i_d)).first;
         double SigmaBackground = MeanSD(SelectedBackground_G4_Multisim_V.at(i_d)).second;

         sigma_events_Background.push_back(SigmaBackground);
         frac_errors_Background.push_back(SigmaBackground/MeanBackground);
      }


      // Print summary

      std::cout << "Breakdown of G4 reinteraction systematic uncertainties for selected events" << std::endl;

      std::cout << "           Systematic Dial           | Sigma Signal Events | Fractional Error | Sigma BG Events | Fractional Error" << std::endl;    

      for(int i=0;i<MAX_G4Multisims;i++){
         int l = G4Multisim_dials[i].length();
         std::cout << G4Multisim_dials[i];
         for(int s=0;s<17-l;s++) std::cout << " ";
         std::cout << " (Multisim):             " << sigma_events_Signal.at(i) << "             " << frac_errors_Signal.at(i) << "             " << sigma_events_Background.at(i) << "            " << frac_errors_Background.at(i) << std::endl; 
      }
    

      // Calculate overall uncertainty
      double SigmaSignal = 0.0,SigmaBackground=0.0;
      for(size_t i=0;i<frac_errors_Signal.size();i++){
         SigmaSignal += frac_errors_Signal.at(i)*frac_errors_Signal.at(i);
         SigmaBackground += frac_errors_Background.at(i)*frac_errors_Background.at(i);        
      }


      SigmaSignal = SelectedSignal*sqrt(SigmaSignal);
      SigmaBackground = SelectedBackground*sqrt(SigmaBackground);

      std::cout << "Overall Uncertainties" << std::endl;
      std::cout << "Selected Signal = " << SelectedSignal << " +/- " << SigmaSignal << " Total fractional error = " << SigmaSignal/SelectedSignal << std::endl;
      std::cout << "Selected Background = " << SelectedBackground << " +/- " << SigmaBackground << " Total fractional error = " << SigmaBackground/SelectedBackground << std::endl;

   }
