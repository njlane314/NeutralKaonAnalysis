R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so)
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so)

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets.h"

#include "FluxWeight.h"

   // Print flux uncertainties on selected signal/background
   // for some configuration of the selection and produce histograms
   // of useful information

   void FluxUncertainty(){

      double POT = 1.0e21; // POT to scale samples to

      BuildTunes();
      //ImportSamples(sGENIEFullFHC_Test);

      SampleNames.push_back("GENIE Background");
      SampleTypes.push_back("Background");
      SampleFiles.push_back("HyperonTrees_Sys.root");

      SelectionParameters P = P_FHC_Tune_325;

      std::string label = "GENIE_FHC";

      EventAssembler E;
      SelectionManager M(P);
      M.SetPOT(POT);
      M.ImportSelectorBDTWeights(P.p_SelectorBDT_WeightsDir);
      M.ImportAnalysisBDTWeights(P.p_AnalysisBDT_WeightsDir);

      // Systematics 

      int n_multisims = 600;

      FluxWeighter F(1);
      F.PrepareSysUniv(n_multisims);

      double SelectedSignal = 0.0;
      double SelectedBackground = 0.0;

      std::vector<double> SelectedSignal_HP_V(n_multisims);
      std::vector<double> SelectedBackground_HP_V(n_multisims);

      std::vector<double> SelectedSignal_Beamline_V(MAX_beamline_vars);
      std::vector<double> SelectedBackground_Beamline_V(MAX_beamline_vars);

      // Fill the vectors with zeros
      for(size_t i_univ=0;i_univ<n_multisims;i_univ++) SelectedSignal_HP_V[i_univ] = 0.0;
      for(size_t i_univ=0;i_univ<n_multisims;i_univ++) SelectedBackground_HP_V[i_univ] = 0.0;
      for(size_t i_univ=0;i_univ<MAX_beamline_vars;i_univ++) SelectedSignal_Beamline_V[i_univ] = 0.0;
      for(size_t i_univ=0;i_univ<MAX_beamline_vars;i_univ++) SelectedBackground_Beamline_V[i_univ] = 0.0;

      TH2D *h_NeutrinoE_Angle_numubar_Signal = new TH2D("h_NeutrinoE_Angle_Signal","#bar{#nu}_{#mu} Selected Signal;E_{#nu} (GeV);Angle",80,0,10,80,0,160);
      TH2D *h_NeutrinoE_Angle_numu_Background = new TH2D("h_NeutrinoE_Angle_Background","#nu_{#mu} Selected Background;E_{#nu} (GeV);Angle",80,0,10,80,0,160);
      TH2D *h_NeutrinoE_Angle_numubar_Background = new TH2D("h_NeutrinoE_Angle_Background","#bar{#nu}_{#mu} Selected Background;E_{#nu} (GeV);Angle",80,0,10,80,0,160);
      TH2D *h_NeutrinoE_Angle_nue_Background = new TH2D("h_NeutrinoE_Angle_Background","#nu_{e} Selected Background;E_{#nu} (GeV);Angle",80,0,10,80,0,160);
      TH2D *h_NeutrinoE_Angle_nuebar_Background = new TH2D("h_NeutrinoE_Angle_Background","#bar{#nu}_{e} Selected Background;E_{#nu} (GeV);Angle",80,0,10,80,0,160);

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

            //////////// Put your selection here //////////////

            if(!M.FiducialVolumeCut(e)) continue;
            if(!M.TrackCut(e)) continue;
            if(!M.ShowerCut(e)) continue;
            //if(!M.ChooseMuonCandidate(e)) continue;
            //if(!M.ChooseProtonPionCandidates(e)) continue;
            //if(!M.AnalysisBDTCut(e)) continue;       
            //if(!M.ConnectednessTest(e)) continue;


            ///////////////////////////////////////////////////

            double nu_e=-1,nu_angle=-1;

            if(SampleTypes.at(i_s) != "EXT" && SampleTypes.at(i_s) != "Data"){
               nu_e = e.Neutrino.at(0).E;
               nu_angle = GetNuMIAngle(e.Neutrino.at(0).Px,e.Neutrino.at(0).Py,e.Neutrino.at(0).Pz);
            }

            double fluxweight = F.GetFluxWeight(e);
            std::vector<double> fluxweights_HP = F.GetSysWeightV(e,1);
            std::vector<double> fluxweights_Beamline = F.GetSysWeightV(e,2);

            // Update the total weight of selected events in each universe
            if(e.EventIsSignal){
               SelectedSignal += e.Weight;
               for(size_t i_univ=0;i_univ<n_multisims;i_univ++) SelectedSignal_HP_V.at(i_univ) += e.Weight*fluxweights_HP.at(i_univ)/fluxweight;
               for(size_t i_univ=0;i_univ<MAX_beamline_vars;i_univ++) SelectedSignal_Beamline_V.at(i_univ) += e.Weight*fluxweights_Beamline.at(i_univ);
               h_NeutrinoE_Angle_numubar_Signal->Fill(nu_e,nu_angle,e.Weight);
            }
            else if(SampleTypes.at(i_s) != "EXT" && SampleTypes.at(i_s) != "Data"){
               SelectedBackground += e.Weight;
               for(size_t i_univ=0;i_univ<n_multisims;i_univ++) SelectedBackground_HP_V.at(i_univ) += e.Weight*fluxweights_HP.at(i_univ)/fluxweight;
               for(size_t i_univ=0;i_univ<MAX_beamline_vars;i_univ++) SelectedBackground_Beamline_V.at(i_univ) += e.Weight*fluxweights_Beamline.at(i_univ);

               if(e.Neutrino.at(0).PDG == 14) h_NeutrinoE_Angle_numu_Background->Fill(nu_e,nu_angle,e.Weight);
               else if(e.Neutrino.at(0).PDG == -14) h_NeutrinoE_Angle_numubar_Background->Fill(nu_e,nu_angle,e.Weight);
               else if(e.Neutrino.at(0).PDG == 12) h_NeutrinoE_Angle_nue_Background->Fill(nu_e,nu_angle,e.Weight);
               else if(e.Neutrino.at(0).PDG == -12) h_NeutrinoE_Angle_nuebar_Background->Fill(nu_e,nu_angle,e.Weight);

            }
            else {
               SelectedBackground += e.Weight;
               for(size_t i_univ=0;i_univ<n_multisims;i_univ++) SelectedBackground_HP_V.at(i_univ) += e.Weight;
               for(size_t i_univ=0;i_univ<MAX_beamline_vars;i_univ++) SelectedBackground_Beamline_V.at(i_univ) += e.Weight;
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

      // Calculate hadron production fractional errors

      double MeanSignal_HP = MeanSD(SelectedSignal_HP_V).first;
      double SigmaSignal_HP = MeanSD(SelectedSignal_HP_V).second;

      double MeanBackground_HP = MeanSD(SelectedBackground_HP_V).first;
      double SigmaBackground_HP = MeanSD(SelectedBackground_HP_V).second;

      sigma_events_Signal.push_back(SigmaSignal_HP);
      sigma_events_Background.push_back(SigmaBackground_HP);
      frac_errors_Signal.push_back(SigmaSignal_HP/MeanSignal_HP);
      frac_errors_Background.push_back(SigmaBackground_HP/MeanBackground_HP);

      // Calculate beamline geometry fractional errors

      for(size_t i_univ=0;i_univ<MAX_beamline_vars/2;i_univ++){

         double Diff = abs(SelectedSignal_Beamline_V.at(2*i_univ) - SelectedSignal_Beamline_V.at(2*i_univ+1));
         sigma_events_Signal.push_back(Diff/2);
         frac_errors_Signal.push_back(Diff/2/SelectedSignal);        

         Diff = abs(SelectedBackground_Beamline_V.at(2*i_univ) - SelectedBackground_Beamline_V.at(2*i_univ+1));
         sigma_events_Background.push_back(Diff/2);
         frac_errors_Background.push_back(Diff/2/SelectedBackground);        
      }     


      // Print summary

      std::cout << "Breakdown of flux systematic uncertainties for selected events" << std::endl;

      std::cout << "       Systematic Dial       | Sigma Signal Events | Fractional Error | Sigma BG Events | Fractional Error" << std::endl;    
      std::cout << "Had Prod        (Multisim):        " << sigma_events_Signal.at(0) << "             " << frac_errors_Signal.at(0) << "            " << sigma_events_Background.at(0) << "          " << frac_errors_Background.at(0) << std::endl; 

      for(int i=0;i<MAX_beamline_vars/2;i++){
         int l = beamline_dials[i].length();
         std::cout << beamline_dials[i];
         for(int s=0;s<17-l;s++) std::cout << " ";
         std::cout << " (Unisim):        " << sigma_events_Signal.at(i+1) << "             " << frac_errors_Signal.at(i+1) << "             " << sigma_events_Background.at(i+1) << "            " << frac_errors_Background.at(i+1) << std::endl; 
      }


      // Calculate overall uncertainty
      double SigmaSignal = 0.0,SigmaBackground=0.0;
      for(size_t i=0;i<frac_errors_Signal.size();i++){
         SigmaSignal += frac_errors_Signal.at(i)*frac_errors_Signal.at(i);
         SigmaBackground += frac_errors_Background.at(i)*frac_errors_Background.at(i);        
      }

      // 2% for POT counting
      SigmaSignal += 0.02*0.02;
      SigmaBackground += 0.02*0.02;

      SigmaSignal = SelectedSignal*sqrt(SigmaSignal);
      SigmaBackground = SelectedBackground*sqrt(SigmaBackground);

      std::cout << "Overall Uncertainties" << std::endl;
      std::cout << "Selected Signal = " << SelectedSignal << " +/- " << SigmaSignal << " Total fractional error = " << SigmaSignal/SelectedSignal << std::endl;
      std::cout << "Selected Background = " << SelectedBackground << " +/- " << SigmaBackground << " Total fractional error = " << SigmaBackground/SelectedBackground << std::endl;


      TCanvas *c = new TCanvas("c","c");

      h_NeutrinoE_Angle_numu_Background->Draw("colz");
      c->Print("Plots/numu_Selected_Background.pdf");       
      c->Clear();

      h_NeutrinoE_Angle_numubar_Background->Draw("colz");
      c->Print("Plots/numubar_Selected_Background.pdf");       
      c->Clear();

      h_NeutrinoE_Angle_nue_Background->Draw("colz");
      c->Print("Plots/nue_Selected_Background.pdf");       
      c->Clear();

      h_NeutrinoE_Angle_nuebar_Background->Draw("colz");
      c->Print("Plots/nuebar_Selected_Background.pdf");       
      c->Clear();

      h_NeutrinoE_Angle_numubar_Signal->Draw("colz");
      c->Print("Plots/numubar_Selected_Signal.pdf");       
      c->Clear();

   }

