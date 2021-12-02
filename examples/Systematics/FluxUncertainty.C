R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so)
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so)

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"
#include "Parameters.h"
#include "SampleSets.h"
#include "FluxWeight.h"

#include "TMatrixD.h"

   // Print flux uncertainties on selected signal/background
   // for some configuration of the selection and produce histograms
   // of useful information

   void FluxUncertainty(){

      double POT = 1.0e21; // POT to scale samples to

      BuildTunes();
      //ImportSamples(sGENIEFullFHC_Test);

      SampleNames.push_back("GENIE Background");
      SampleTypes.push_back("Background");
      SampleFiles.push_back("analysisOutputFHC_GENIE_Overlay_Background_prodgenie_numi_uboone_overlay_fhc_mcc9_run1_v28_sample2.root");

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
      std::vector<double> SelectedTotal_HP_V(n_multisims);

      std::vector<double> SelectedSignal_Beamline_V(MAX_beamline_vars);
      std::vector<double> SelectedBackground_Beamline_V(MAX_beamline_vars);
      std::vector<double> SelectedTotal_Beamline_V(MAX_beamline_vars);

      // Fill the vectors with zeros
      for(size_t i_univ=0;i_univ<n_multisims;i_univ++) SelectedSignal_HP_V[i_univ] = 0.0;
      for(size_t i_univ=0;i_univ<n_multisims;i_univ++) SelectedBackground_HP_V[i_univ] = 0.0;
      for(size_t i_univ=0;i_univ<n_multisims;i_univ++) SelectedTotal_HP_V[i_univ] = 0.0;
      for(size_t i_univ=0;i_univ<MAX_beamline_vars;i_univ++) SelectedSignal_Beamline_V[i_univ] = 0.0;
      for(size_t i_univ=0;i_univ<MAX_beamline_vars;i_univ++) SelectedBackground_Beamline_V[i_univ] = 0.0;
      for(size_t i_univ=0;i_univ<MAX_beamline_vars;i_univ++) SelectedTotal_Beamline_V[i_univ] = 0.0;

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
            if(!M.ChooseMuonCandidate(e)) continue;
            if(!M.ChooseProtonPionCandidates(e)) continue;
            if(!M.AnalysisBDTCut(e)) continue;       
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
               for(size_t i_univ=0;i_univ<n_multisims;i_univ++) SelectedTotal_HP_V.at(i_univ) += e.Weight*fluxweights_HP.at(i_univ)/fluxweight;
               for(size_t i_univ=0;i_univ<MAX_beamline_vars;i_univ++) SelectedTotal_Beamline_V.at(i_univ) += e.Weight*fluxweights_Beamline.at(i_univ);
               h_NeutrinoE_Angle_numubar_Signal->Fill(nu_e,nu_angle,e.Weight);
            }
            else if(SampleTypes.at(i_s) != "EXT" && SampleTypes.at(i_s) != "Data"){
               SelectedBackground += e.Weight;
               for(size_t i_univ=0;i_univ<n_multisims;i_univ++) SelectedBackground_HP_V.at(i_univ) += e.Weight*fluxweights_HP.at(i_univ)/fluxweight;
               for(size_t i_univ=0;i_univ<MAX_beamline_vars;i_univ++) SelectedBackground_Beamline_V.at(i_univ) += e.Weight*fluxweights_Beamline.at(i_univ);
               for(size_t i_univ=0;i_univ<n_multisims;i_univ++) SelectedTotal_HP_V.at(i_univ) += e.Weight*fluxweights_HP.at(i_univ)/fluxweight;
               for(size_t i_univ=0;i_univ<MAX_beamline_vars;i_univ++) SelectedTotal_Beamline_V.at(i_univ) += e.Weight*fluxweights_Beamline.at(i_univ);

               if(e.Neutrino.at(0).PDG == 14) h_NeutrinoE_Angle_numu_Background->Fill(nu_e,nu_angle,e.Weight);
               else if(e.Neutrino.at(0).PDG == -14) h_NeutrinoE_Angle_numubar_Background->Fill(nu_e,nu_angle,e.Weight);
               else if(e.Neutrino.at(0).PDG == 12) h_NeutrinoE_Angle_nue_Background->Fill(nu_e,nu_angle,e.Weight);
               else if(e.Neutrino.at(0).PDG == -12) h_NeutrinoE_Angle_nuebar_Background->Fill(nu_e,nu_angle,e.Weight);

            }
            else {
               SelectedBackground += e.Weight;
               for(size_t i_univ=0;i_univ<n_multisims;i_univ++) SelectedBackground_HP_V.at(i_univ) += e.Weight;
               for(size_t i_univ=0;i_univ<MAX_beamline_vars;i_univ++) SelectedBackground_Beamline_V.at(i_univ) += e.Weight;
               for(size_t i_univ=0;i_univ<n_multisims;i_univ++) SelectedTotal_HP_V.at(i_univ) += e.Weight;
               for(size_t i_univ=0;i_univ<MAX_beamline_vars;i_univ++) SelectedTotal_Beamline_V.at(i_univ) += e.Weight;
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

      std::vector<TMatrixD> Cov_Matrices;
      std::vector<TMatrixD> frac_Cov_Matrices;

      // Calculate hadron production fractional errors

      double MeanSignal_HP = MeanSD(SelectedSignal_HP_V).first;
      double SigmaSignal_HP = MeanSD(SelectedSignal_HP_V).second;

      double MeanBackground_HP = MeanSD(SelectedBackground_HP_V).first;
      double SigmaBackground_HP = MeanSD(SelectedBackground_HP_V).second;

      double MeanTotal_HP = MeanSD(SelectedTotal_HP_V).first;
      double SigmaTotal_HP = MeanSD(SelectedTotal_HP_V).second;

      double Signal_Background_Covariance_HP = 0.0;

      for(int i_hp=0;i_hp<n_multisims;i_hp++)
         Signal_Background_Covariance_HP += (SelectedSignal_HP_V.at(i_hp) - MeanSignal_HP)*(SelectedBackground_HP_V.at(i_hp) - MeanBackground_HP)/(n_multisims-1);

      std::cout << "Signal background covariance = " << Signal_Background_Covariance_HP << std::endl;
      std::cout << "Signal background fractional covariance = " << Signal_Background_Covariance_HP/MeanSignal_HP/MeanBackground_HP << std::endl;

      TMatrixD Cov_HP(2,2);
      Cov_HP[0][0] = SigmaSignal_HP*SigmaSignal_HP;
      Cov_HP[1][1] = SigmaBackground_HP*SigmaBackground_HP;
      Cov_HP[0][1] = Cov_HP[1][0] = Signal_Background_Covariance_HP;

      std::cout << "HP Covariance Matrix: " << std::endl;
      Cov_HP.Print();
      

      Cov_Matrices.push_back(Cov_HP);

      Cov_HP[0][0] /= MeanSignal_HP*MeanSignal_HP;
      Cov_HP[1][1] /= MeanBackground_HP*MeanBackground_HP;
      Cov_HP[0][1] = Cov_HP[1][0] = Signal_Background_Covariance_HP/MeanSignal_HP/MeanBackground_HP;

      std::cout << "HP Fractional Covariance Matrix: " << std::endl;
      Cov_HP.Print();

      frac_Cov_Matrices.push_back(Cov_HP); 

      sigma_events_Signal.push_back(SigmaSignal_HP);
      sigma_events_Background.push_back(SigmaBackground_HP);
      sigma_events_Total.push_back(SigmaTotal_HP);
      frac_errors_Signal.push_back(SigmaSignal_HP/MeanSignal_HP);
      frac_errors_Background.push_back(SigmaBackground_HP/MeanBackground_HP);
      frac_errors_Total.push_back(SigmaTotal_HP/MeanTotal_HP);

      // Calculate beamline geometry fractional errors

      for(size_t i_univ=0;i_univ<MAX_beamline_vars/2;i_univ++){

         TMatrixD Cov(2,2);
         TMatrixD frac_Cov(2,2);

         double Diff = abs(SelectedSignal_Beamline_V.at(2*i_univ) - SelectedSignal_Beamline_V.at(2*i_univ+1));
         sigma_events_Signal.push_back(Diff/2);
         frac_errors_Signal.push_back(Diff/2/SelectedSignal);        
         Cov[0][0] = Diff*Diff/2/2;
         frac_Cov[0][0] = Diff*Diff/2/2/SelectedSignal/SelectedSignal;


         Diff = abs(SelectedBackground_Beamline_V.at(2*i_univ) - SelectedBackground_Beamline_V.at(2*i_univ+1));
         sigma_events_Background.push_back(Diff/2);
         frac_errors_Background.push_back(Diff/2/SelectedBackground);        
         Cov[1][1] = Diff*Diff/2/2;
         frac_Cov[1][1] = Diff*Diff/2/2/SelectedBackground/SelectedBackground;

         Cov[0][1] = Cov[1][0] = (SelectedSignal_Beamline_V.at(2*i_univ) - SelectedSignal_Beamline_V.at(2*i_univ+1))*(SelectedBackground_Beamline_V.at(2*i_univ) - SelectedBackground_Beamline_V.at(2*i_univ+1))/4; 
         frac_Cov[0][1] = frac_Cov[1][0] = (SelectedSignal_Beamline_V.at(2*i_univ) - SelectedSignal_Beamline_V.at(2*i_univ+1))*(SelectedBackground_Beamline_V.at(2*i_univ) - SelectedBackground_Beamline_V.at(2*i_univ+1))/4/SelectedSignal/SelectedBackground;

         std::cout << "Fractional CM for beamline var " << i_univ << std::endl;
         frac_Cov.Print();


         Diff = abs(SelectedTotal_Beamline_V.at(2*i_univ) - SelectedTotal_Beamline_V.at(2*i_univ+1));
         sigma_events_Total.push_back(Diff/2);
         frac_errors_Total.push_back(Diff/2/(SelectedSignal+SelectedBackground));        


        Cov_Matrices.push_back(Cov);
        frac_Cov_Matrices.push_back(frac_Cov); 

      }     

        cout.precision(4);

      // Print summary
      std::cout << std::endl;
      std::cout << "Breakdown of flux systematic uncertainties for selected events" << std::endl;

      std::cout << "       Systematic Dial       | Sigma Signal Events | Fractional Error  | Sigma BG Events  |  Fractional Error  |  Sigma S+B Events  | Fractional Error |" << std::endl;    
      std::cout << "Had Prod        (Multisim):        " << sigma_events_Signal.at(0) << "             " << frac_errors_Signal.at(0) << "            " << sigma_events_Background.at(0) << "          " << frac_errors_Background.at(0) << "      " <<  sigma_events_Total.at(0) << "     " <<  frac_errors_Total.at(0)  <<std::endl; 

      for(int i=0;i<MAX_beamline_vars/2;i++){
         int l = beamline_dials[i].length();
         std::cout << beamline_dials[i];
         for(int s=0;s<17-l;s++) std::cout << " ";
         std::cout << " (Unisim):        " << sigma_events_Signal.at(i+1) << "             " << frac_errors_Signal.at(i+1) << "             " << sigma_events_Background.at(i+1) << "            " << frac_errors_Background.at(i+1) << "     " << sigma_events_Total.at(i+1) << "     " << frac_errors_Total.at(i+1) <<  std::endl; 
      }


      // Calculate overall uncertainty
      double SigmaSignal = 0.0,SigmaBackground=0.0,SigmaTotal=0.0;
      TMatrixD Cov_Matrix(2,2);
      TMatrixD frac_Cov_Matrix(2,2);
        
      Cov_Matrix[0][0] = Cov_Matrix[1][1] = Cov_Matrix[0][1] = Cov_Matrix[1][0] = 0.;     
      frac_Cov_Matrix[0][0] = frac_Cov_Matrix[1][1] = frac_Cov_Matrix[0][1] = frac_Cov_Matrix[1][0] = 0.;     

      for(size_t i=0;i<frac_errors_Signal.size();i++){
         SigmaSignal += frac_errors_Signal.at(i)*frac_errors_Signal.at(i);
         SigmaBackground += frac_errors_Background.at(i)*frac_errors_Background.at(i);        
         SigmaTotal += frac_errors_Total.at(i)*frac_errors_Total.at(i);        

         Cov_Matrix += Cov_Matrices.at(i); 
         frac_Cov_Matrix += frac_Cov_Matrices.at(i); 
      }

      // 2% for POT counting
      SigmaSignal += 0.02*0.02;
      SigmaBackground += 0.02*0.02;
      SigmaTotal += 0.02*0.02;

      TMatrixD Cov_POT(2,2);
      TMatrixD frac_Cov_POT(2,2);
      Cov_POT[0][0] = 0.02*0.02*SelectedSignal*SelectedSignal;      
      Cov_POT[1][1] = 0.02*0.02*SelectedBackground*SelectedBackground;      
      Cov_POT[0][1] = Cov_POT[1][0] = 0.02*0.02*SelectedSignal*SelectedBackground;
      frac_Cov_POT[0][0] = frac_Cov_POT[1][1] = frac_Cov_POT[0][1] = frac_Cov_POT[1][0] = 0.02*0.02;     
       
      Cov_Matrix += Cov_POT;
      //frac_Cov_Matrix += frac_Cov_POT; 

      SigmaSignal = SelectedSignal*sqrt(SigmaSignal);
      SigmaBackground = SelectedBackground*sqrt(SigmaBackground);
      SigmaTotal = (SelectedSignal+SelectedBackground)*sqrt(SigmaTotal);

      std::cout << std::endl;

      std::cout << "Overall Uncertainties" << std::endl;
      std::cout << "Selected Signal = " << SelectedSignal << " +/- " << SigmaSignal << " fractional error = " << SigmaSignal/SelectedSignal << std::endl;
      std::cout << "Selected Background = " << SelectedBackground << " +/- " << SigmaBackground << " fractional error = " << SigmaBackground/SelectedBackground << std::endl;
      std::cout << "Selected Total = " << SelectedSignal + SelectedBackground << " +/- " << SigmaTotal << " fractional error = " << SigmaTotal/(SelectedSignal+SelectedBackground) << std::endl;

      /*
         std::cout << std::endl << "Covariance matrices:" << std::endl;
         for(size_t i=0;i<Cov_Matrices.size();i++){
         std::cout << "Parameter " << i << std::endl;
         std::cout << "Covariance matrix" << std::endl;
         Cov_Matrices.at(i).Print();
         std::cout << "Fractional Covariance matrix" << std::endl;
         frac_Cov_Matrices.at(i).Print();
         }
         */

      std::cout << std::endl << "Flux Covariance Matrix" << std::endl;
       Cov_Matrix.Print();
       std::cout << std::endl << "Flux fractional Covariance Matrix" << std::endl; 
       frac_Cov_Matrix.Print();

      TCanvas *c = new TCanvas("c","c");

      h_NeutrinoE_Angle_numu_Background->Draw("colz");
      c->Print("Plots/numu_Selected_Background.png");       
      c->Clear();

      h_NeutrinoE_Angle_numubar_Background->Draw("colz");
      c->Print("Plots/numubar_Selected_Background.png");       
      c->Clear();

      h_NeutrinoE_Angle_nue_Background->Draw("colz");
      c->Print("Plots/nue_Selected_Background.png");       
      c->Clear();

      h_NeutrinoE_Angle_nuebar_Background->Draw("colz");
      c->Print("Plots/nuebar_Selected_Background.png");       
      c->Clear();

      h_NeutrinoE_Angle_numubar_Signal->Draw("colz");
      c->Print("Plots/numubar_Selected_Signal.png");       
      c->Clear();

   }

