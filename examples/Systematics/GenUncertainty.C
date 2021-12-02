R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so)
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so)

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets.h"

#include "GenG4WeightHandler.h"

   void GenUncertainty(){

      double POT = 1.0e21; // POT to scale samples to

      BuildTunes();
      //ImportSamples(sGENIEFullFHC_Test);

      SampleNames.push_back("GENIE Background");
      SampleTypes.push_back("Background");
      SampleFiles.push_back("analysisOutputFHC_GENIE_Overlay_Background_prodgenie_numi_uboone_overlay_fhc_mcc9_run1_v28_sample2.root");

      SelectionParameters P = P_FHC_Tune_325;

      std::string label = "GENIE_FHC";

      // Setup selection manager. Set POT to scale sample to, import the BDT weights
      EventAssembler E;
      SelectionManager M(P);
      M.SetPOT(POT);
      M.ImportSelectorBDTWeights(P.p_SelectorBDT_WeightsDir);
      M.ImportAnalysisBDTWeights(P.p_AnalysisBDT_WeightsDir);

      double SelectedSignal = 0.0;
      double SelectedBackground = 0.0;

      // Systematics 

      int nuniv = 600;

      std::vector<double> SelectedSignal_Gen_Multisim_V(nuniv);
      std::vector<double> SelectedBackground_Gen_Multisim_V(nuniv);

      std::vector<double> SelectedSignal_Gen_Unisim_V(MAX_GenUnisims);
      std::vector<double> SelectedBackground_Gen_Unisim_V(MAX_GenUnisims);

      for(size_t i_univ=0;i_univ<nuniv;i_univ++) SelectedSignal_Gen_Multisim_V[i_univ] = 0.0;
      for(size_t i_univ=0;i_univ<nuniv;i_univ++) SelectedBackground_Gen_Multisim_V[i_univ] = 0.0;
      for(size_t i_univ=0;i_univ<MAX_GenUnisims;i_univ++) SelectedSignal_Gen_Unisim_V[i_univ] = 0.0;
      for(size_t i_univ=0;i_univ<MAX_GenUnisims;i_univ++) SelectedBackground_Gen_Unisim_V[i_univ] = 0.0;

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
            if(!M.ChooseMuonCandidate(e)) continue;
            if(!M.ChooseProtonPionCandidates(e)) continue;
            if(!M.AnalysisBDTCut(e)) continue;       
            //if(!M.EventListCut(e)) continue;

            ///////////////////////////////////////////////////

            G.LoadEvent(e);

            double TunedCentralValue = G.GetWeights("TunedCentralValue_UBGenie").at(0);            

            if(!(TunedCentralValue > 0)) continue;
            
            // Multisim weights
            std::vector<double> weights_Gen_Multisim = G.GetWeights("All_UBGenie");

            // Unisims
            std::vector<std::vector<double>> weights_Unisim(MAX_GenUnisims-1);
            for(int i_uni=0;i_uni<MAX_GenUnisims-1;i_uni++) weights_Unisim[i_uni] = G.GetWeights(GenUnisim_names[i_uni]);   


            // Update the total weight of selected events in each universe
            if(e.EventIsSignal){
               SelectedSignal += e.Weight;

               for(size_t i_univ=0;i_univ<nuniv;i_univ++) SelectedSignal_Gen_Multisim_V[i_univ] += e.Weight*weights_Gen_Multisim.at(i_univ)/TunedCentralValue;     

               for(int i_uni=0;i_uni<MAX_GenUnisims-2;i_uni++){
                  if(i_uni == gv_XSecShape_CCMEC) SelectedSignal_Gen_Unisim_V[i_uni] += e.Weight*weights_Unisim.at(i_uni).at(1)/TunedCentralValue;
                  else   SelectedSignal_Gen_Unisim_V[i_uni] += e.Weight*weights_Unisim.at(i_uni).at(0)/TunedCentralValue;
               }

               SelectedSignal_Gen_Unisim_V[gv_RPA_CCQE_Up] += e.Weight*weights_Unisim.at(MAX_GenUnisims-2).at(0)/TunedCentralValue;
               SelectedSignal_Gen_Unisim_V[gv_RPA_CCQE_Down] += e.Weight*weights_Unisim.at(MAX_GenUnisims-2).at(1)/TunedCentralValue;
            }

            else if(SampleTypes.at(i_s) != "EXT" && SampleTypes.at(i_s) != "Data"){
               SelectedBackground += e.Weight;

               for(size_t i_univ=0;i_univ<nuniv;i_univ++) SelectedBackground_Gen_Multisim_V[i_univ] += e.Weight*weights_Gen_Multisim.at(i_univ)/TunedCentralValue;

               for(int i_uni=0;i_uni<MAX_GenUnisims-2;i_uni++){
                  if(i_uni == gv_XSecShape_CCMEC) SelectedBackground_Gen_Unisim_V[i_uni] += e.Weight*weights_Unisim.at(i_uni).at(1)/TunedCentralValue;
                  else   SelectedBackground_Gen_Unisim_V[i_uni] += e.Weight*weights_Unisim.at(i_uni).at(0)/TunedCentralValue;
               }

               SelectedBackground_Gen_Unisim_V[gv_RPA_CCQE_Up] += e.Weight*weights_Unisim.at(MAX_GenUnisims-2).at(0)/TunedCentralValue;
               SelectedBackground_Gen_Unisim_V[gv_RPA_CCQE_Down] += e.Weight*weights_Unisim.at(MAX_GenUnisims-2).at(1)/TunedCentralValue;                
            }

            else {
               SelectedBackground += e.Weight;
               for(size_t i_univ=0;i_univ<nuniv;i_univ++) SelectedBackground_Gen_Multisim_V[i_univ] += e.Weight;
               for(int i_uni=0;i_uni<MAX_GenUnisims;i_uni++) SelectedBackground_Gen_Unisim_V[i_uni] += e.Weight;              
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

      // Calculate errors from multisims  

      double MeanSignal_Multisim = MeanSD(SelectedSignal_Gen_Multisim_V).first; 
      double SigmaSignal_Multisim = MeanSD(SelectedSignal_Gen_Multisim_V).second; 

      double MeanBackground_Multisim = MeanSD(SelectedBackground_Gen_Multisim_V).first; 
      double SigmaBackground_Multisim = MeanSD(SelectedBackground_Gen_Multisim_V).second; 

      sigma_events_Signal.push_back(SigmaSignal_Multisim);
      sigma_events_Background.push_back(SigmaBackground_Multisim);
      frac_errors_Signal.push_back(SigmaSignal_Multisim/MeanSignal_Multisim);
      frac_errors_Background.push_back(SigmaBackground_Multisim/MeanBackground_Multisim);

      // Calculate errors from single universe unisims

      for(int i_u=0;i_u<MAX_GenUnisims-2;i_u++){

         double Diff_Signal =  abs(SelectedSignal_Gen_Unisim_V.at(i_u) - SelectedSignal);
         double Diff_Background =  abs(SelectedBackground_Gen_Unisim_V.at(i_u) - SelectedBackground);

         sigma_events_Signal.push_back(Diff_Signal);
         sigma_events_Background.push_back(Diff_Background);

         frac_errors_Signal.push_back(Diff_Signal/SelectedSignal);
         frac_errors_Background.push_back(Diff_Background/SelectedBackground);

      }

      // Calculate errors from two universe multsim (CCQE RPA)

      double Diff_Signal = abs(SelectedSignal_Gen_Unisim_V.at(gv_RPA_CCQE_Up) - SelectedSignal_Gen_Unisim_V.at(gv_RPA_CCQE_Down))/2;
      double Diff_Background = abs(SelectedBackground_Gen_Unisim_V.at(gv_RPA_CCQE_Up) - SelectedBackground_Gen_Unisim_V.at(gv_RPA_CCQE_Down))/2;

      sigma_events_Signal.push_back(Diff_Signal);      
      sigma_events_Background.push_back(Diff_Background);      

      frac_errors_Signal.push_back(Diff_Signal/SelectedSignal);
      frac_errors_Background.push_back(Diff_Background/SelectedBackground);

      // Print summary

      std::cout << "Breakdown of generator systematic uncertainties for selected events" << std::endl;

      std::cout << "         Systematic Dial         | Sigma Signal Events | Fractional Error | Sigma BG Events | Fractional Error" << std::endl;    

      std::cout << "GENIE Multisims     (Multisim):           " << sigma_events_Signal.at(0) << "             " << frac_errors_Signal.at(0) << "            " << sigma_events_Background.at(0) << "          " << frac_errors_Background.at(0) << std::endl; 


   for(int i=0;i<MAX_GenUnisims-1;i++){
      int l = GenUnisim_dials[i].length();
      std::cout << GenUnisim_dials[i];
      for(int s=0;s<21-l;s++) std::cout << " ";
      std::cout << " (Unisim):           " << sigma_events_Signal.at(i+1) << "             " << frac_errors_Signal.at(i+1) << "             " << sigma_events_Background.at(i+1) << "            " << frac_errors_Background.at(i+1) << std::endl; 
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

