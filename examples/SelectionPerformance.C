R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so)

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

#include "TGraphAsymmErrors.h"

   // Produces graph with efficiency, purity and S/sqrt(S+B)
   // for each step of the selection and prints lots of
   // performance metrics.

   void SelectionPerformance(){

      // Diables TEfficiency warnings
      gErrorIgnoreLevel = kWarning;

      double POT = 1.0e21; // POT to scale samples to

      BuildTunes();
      ImportSamples(sNuWroFullFHC);

      SelectionParameters P = P_FHC_Tune_325;

      std::string label = "NuWro_FHC";

      // Setup selection manager. Set POT to scale sample to
      EventAssembler E;
      SelectionManager M(P);
      M.SetPOT(POT);
      M.ImportSelectorBDTWeights(P.p_SelectorBDT_WeightsDir);
      M.ImportAnalysisBDTWeights(P.p_AnalysisBDT_WeightsDir);

      TEfficiency* Eff = new TEfficiency("Eff","",8,-0.5,7.5);
      TEfficiency* Background_Acceptance = new TEfficiency("Background_Acceptance","",8,-0.5,7.5);     

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

            bool passed_FV=false,passed_Tracks=false,passed_Showers=false,passed_MuonID=false,passed_TrackLengths=false,passed_Selector=false,passed_Analysis=false,passed_Connectedness=false;

            passed_FV = M.FiducialVolumeCut(e);
            if(passed_FV) passed_Tracks = M.TrackCut(e);
            if(passed_Tracks) passed_Showers = M.ShowerCut(e);
            if(passed_Showers) passed_MuonID = M.ChooseMuonCandidate(e);
            if(passed_MuonID) passed_Selector = M.ChooseProtonPionCandidates(e); 
            if(passed_Selector) passed_Analysis = M.AnalysisBDTCut(e);
            if(passed_Analysis) passed_Connectedness = M.EventListCut(e);


            if(e.IsSignal){
               Eff->FillWeighted(true,e.Weight,0);
               Eff->FillWeighted(passed_FV,e.Weight,1);
               Eff->FillWeighted(passed_Tracks,e.Weight,2);
               Eff->FillWeighted(passed_Showers,e.Weight,3);
               Eff->FillWeighted(passed_MuonID,e.Weight,4);
               Eff->FillWeighted(passed_Selector,e.Weight,5);
               Eff->FillWeighted(passed_Analysis,e.Weight,6);
               Eff->FillWeighted(passed_Connectedness,e.Weight,7);

            }
            else {
               Background_Acceptance->FillWeighted(true,e.Weight,0);
               Background_Acceptance->FillWeighted(passed_FV,e.Weight,1);
               Background_Acceptance->FillWeighted(passed_Tracks,e.Weight,2);
               Background_Acceptance->FillWeighted(passed_Showers,e.Weight,3);
               Background_Acceptance->FillWeighted(passed_MuonID,e.Weight,4);
               Background_Acceptance->FillWeighted(passed_Selector,e.Weight,5);
               Background_Acceptance->FillWeighted(passed_Analysis,e.Weight,6);
               Background_Acceptance->FillWeighted(passed_Connectedness,e.Weight,7);


            }


         }

         E.Close();
      }


      // Set up the efficiency vectors

      std::vector<Double_t> x = {0,1,2,3,4,5,6,7};
      std::vector<Double_t> E_v,E_low_v,E_high_v;

      for(size_t i_c=1;i_c<x.size()+1;i_c++){

         E_v.push_back(Eff->GetEfficiency(i_c));
         E_low_v.push_back(Eff->GetEfficiencyErrorLow(i_c));
         E_high_v.push_back(Eff->GetEfficiencyErrorUp(i_c));

      }

      Cut C_FV = M.GetCut("FV");
      Cut C_Tracks = M.GetCut("Tracks");
      Cut C_Showers = M.GetCut("Showers");
      Cut C_MuonID = M.GetCut("MuonID");
      Cut C_DecaySelector = M.GetCut("DecaySelector");
      Cut C_DecayAnalyser = M.GetCut("DecayAnalysis");
      Cut C_Connectedness = M.GetCut("Connectedness");

      /////////////////////////////////////////////////////////////////////////////////////////////////////////////////

      std::cout << "Selection Performance Metrics:" << std::endl;

      std::cout << "No Selection: " << std::endl
         << "Signal = " << C_FV.fSignalEventsIn << " +/- " << sqrt(C_FV.fSignalEventsInVar) << "  Background = " << C_FV.fEventsIn-C_FV.fSignalEventsIn << " +/- " << sqrt(C_FV.fEventsInVar-C_FV.fSignalEventsInVar) << std::endl;

      std::cout << std::endl
         << "Fiducial Volume Cut: " << std::endl
         << "Selected Signal = " << C_FV.PredictedSignal() << " +/- " << C_FV.PredictedSignalError() << "  Selected Background = " <<  C_FV.PredictedBackground() << " +/- " << C_FV.PredictedBackgroundError() << std::endl
         <<  "Efficiency = " << E_v.at(1) << " + " << E_high_v.at(1) << " - " << E_low_v.at(1)  << "  Purity = " << C_FV.SignalPurity() << " + " << C_FV.SignalPurityErrorHigh() - C_FV.SignalPurity() << " - " << C_FV.SignalPurity() - C_FV.SignalPurityErrorLow() <<  std::endl;

      std::cout << std::endl
         << "Track Cut: " << std::endl
         << "Selected Signal = " << C_Tracks.PredictedSignal() << " +/- " << C_Tracks.PredictedSignalError() << "  Selected Background = " <<  C_Tracks.PredictedBackground() << " +/- " << C_Tracks.PredictedBackgroundError() << std::endl
         <<  "Efficiency = " << E_v.at(2) << " + " << E_high_v.at(2) << " - " << E_low_v.at(2)  << "  Purity = " << C_Tracks.SignalPurity() << " + " << C_Tracks.SignalPurityErrorHigh() - C_Tracks.SignalPurity() << " - " << C_Tracks.SignalPurity() - C_Tracks.SignalPurityErrorLow() <<  std::endl;

      std::cout << std::endl
         << "Shower Cut: " << std::endl
         << "Selected Signal = " << C_Showers.PredictedSignal() << " +/- " << C_Showers.PredictedSignalError() << "  Selected Background = " <<  C_Showers.PredictedBackground() << " +/- " << C_Showers.PredictedBackgroundError() << std::endl
         <<  "Efficiency = " << E_v.at(3) << " + " << E_high_v.at(3) << " - " << E_low_v.at(3)  << "  Purity = " << C_Showers.SignalPurity() << " + " << C_Showers.SignalPurityErrorHigh() - C_Showers.SignalPurity() << " - " << C_Showers.SignalPurity() - C_Showers.SignalPurityErrorLow() <<  std::endl;

      std::cout << std::endl
         << "Muon ID: " << std::endl
         << "Selected Signal = " << C_MuonID.PredictedSignal() << " +/- " << C_MuonID.PredictedSignalError() << "  Selected Background = " <<  C_MuonID.PredictedBackground() << " +/- " << C_MuonID.PredictedBackgroundError() << std::endl
         <<  "Efficiency = " << E_v.at(4) << " + " << E_high_v.at(4) << " - " << E_low_v.at(4)  << "  Purity = " << C_MuonID.SignalPurity() << " + " << C_MuonID.SignalPurityErrorHigh() - C_MuonID.SignalPurity() << " - " << C_MuonID.SignalPurity() - C_MuonID.SignalPurityErrorLow() <<  std::endl;

      std::cout << std::endl
         << "Decay Selector: " << std::endl
         << "Selected Signal = " << C_DecaySelector.PredictedSignal() << " +/- " << C_DecaySelector.PredictedSignalError() << "  Selected Background = " <<  C_DecaySelector.PredictedBackground() << " +/- " << C_DecaySelector.PredictedBackgroundError() << std::endl
         <<  "Efficiency = " << E_v.at(5) << " + " << E_high_v.at(5) << " - " << E_low_v.at(5)  << "  Purity = " << C_DecaySelector.SignalPurity() << " + " << C_DecaySelector.SignalPurityErrorHigh() - C_DecaySelector.SignalPurity() << " - " << C_DecaySelector.SignalPurity() - C_DecaySelector.SignalPurityErrorLow() <<  std::endl;

      std::cout << std::endl
         << "Decay Analyser: " << std::endl
         << "Selected Signal = " << C_DecayAnalyser.PredictedSignal() << " +/- " << C_DecayAnalyser.PredictedSignalError() << "  Selected Background = " <<  C_DecayAnalyser.PredictedBackground() << " +/- " << C_DecayAnalyser.PredictedBackgroundError() << std::endl
         <<  "Efficiency = " << E_v.at(6) << " + " << E_high_v.at(6) << " - " << E_low_v.at(6)  << "  Purity = " << C_DecayAnalyser.SignalPurity() << " + " << C_DecayAnalyser.SignalPurityErrorHigh() - C_DecayAnalyser.SignalPurity() << " - " << C_DecayAnalyser.SignalPurity() - C_DecayAnalyser.SignalPurityErrorLow() <<  std::endl;

      std::cout << std::endl
         << "Connectedness: " << std::endl
         << "Selected Signal = " << C_Connectedness.PredictedSignal() << " +/- " << C_Connectedness.PredictedSignalError() << "  Selected Background = " <<  C_Connectedness.PredictedBackground() << " +/- " << C_Connectedness.PredictedBackgroundError() << std::endl
         <<  "Efficiency = " << E_v.at(7) << " + " << E_high_v.at(7) << " - " << E_low_v.at(7)  << "  Purity = " << C_Connectedness.SignalPurity() << " + " << C_Connectedness.SignalPurityErrorHigh() - C_Connectedness.SignalPurity() << " - " << C_Connectedness.SignalPurity() - C_Connectedness.SignalPurityErrorLow() <<  std::endl;

      /////////////////////////////////////////////////////////////////////////////////////////////////////////////////

      TH1D *h_Container = new TH1D("h_Container",";;",8,-0.5,7.5);

      std::vector<Double_t> P_v = { 0.0 , C_FV.SignalPurity() , C_Tracks.SignalPurity() , C_Showers.SignalPurity() , C_MuonID.SignalPurity() , C_DecaySelector.SignalPurity() , C_DecayAnalyser.SignalPurity() , C_Connectedness.SignalPurity() };

      std::vector<Double_t> P_low_v = { 0.0 , C_FV.SignalPurity() - C_FV.SignalPurityErrorLow() , C_Tracks.SignalPurity() - C_Tracks.SignalPurityErrorLow() , C_Showers.SignalPurity() - C_Showers.SignalPurityErrorLow() , C_MuonID.SignalPurity() - C_MuonID.SignalPurityErrorLow() , C_DecaySelector.SignalPurity() - C_DecaySelector.SignalPurityErrorLow() ,  C_DecayAnalyser.SignalPurity() - C_DecayAnalyser.SignalPurityErrorLow() , C_Connectedness.SignalPurity() - C_Connectedness.SignalPurityErrorLow() };

      std::vector<Double_t> P_high_v = { 0.0 , C_FV.SignalPurityErrorHigh() -  C_FV.SignalPurity() , C_Tracks.SignalPurityErrorHigh() -  C_Tracks.SignalPurity() , C_Showers.SignalPurityErrorHigh() - C_Showers.SignalPurity() , C_MuonID.SignalPurityErrorHigh() - C_MuonID.SignalPurity() , C_DecaySelector.SignalPurityErrorHigh() - C_DecaySelector.SignalPurity() , C_DecayAnalyser.SignalPurityErrorHigh() - C_DecayAnalyser.SignalPurity() , C_Connectedness.SignalPurityErrorHigh() - C_Connectedness.SignalPurity() };

      std::vector<Double_t> S_v = { C_FV.fSignalEventsIn/sqrt(C_FV.fEventsIn) ,  C_FV.Significance() , C_Tracks.Significance() , C_Showers.Significance() , C_MuonID.Significance() , C_DecaySelector.Significance() , C_DecayAnalyser.Significance() , C_Connectedness.Significance() };


      TFile *f_graphs = TFile::Open(("Performance_Plots_" + label + ".root").c_str(),"RECREATE");



      TGraphAsymmErrors *g_Eff = new TGraphAsymmErrors(x.size(),&(x[0]),&(E_v[0]),0,0,&(E_low_v[0]),&(E_high_v[0]));

      g_Eff->SetMarkerStyle(5);
      g_Eff->SetMarkerColor(2);

      TGraphAsymmErrors *g_Pur = new TGraphAsymmErrors(x.size(),&(x[0]),&(P_v[0]),0,0,&(P_low_v[0]),&(P_high_v[0]));

      g_Pur->SetMarkerStyle(8);
      g_Pur->SetMarkerColor(6);

      h_Container->Draw("");
      h_Container->GetYaxis()->SetRange(0.0,1.0);
      h_Container->GetYaxis()->SetTitle("Efficiency/Purity");

      h_Container->GetXaxis()->SetBinLabel(1,"None");
      h_Container->GetXaxis()->SetBinLabel(2,"FV");
      h_Container->GetXaxis()->SetBinLabel(3,"Tracks");
      h_Container->GetXaxis()->SetBinLabel(4,"Showers");
      h_Container->GetXaxis()->SetBinLabel(5,"Muon ID");
      h_Container->GetXaxis()->SetBinLabel(6,"D. Sel.");
      h_Container->GetXaxis()->SetBinLabel(7,"D. An.");
      h_Container->GetXaxis()->SetBinLabel(8,"Conn.");

      h_Container->GetXaxis()->SetLabelSize(0.07); 
      h_Container->GetXaxis()->SetLabelOffset(0.01);

      TCanvas *c1 = new TCanvas("c1","c1",800,600);

      TPad *p_plot = new TPad("pad1","pad1",0,0,1,0.85);
      TPad *p_legend = new TPad("pad2","pad2",0,0.85,1,1);

      p_legend->SetBottomMargin(0);
      p_legend->SetTopMargin(0.1);
      p_plot->SetTopMargin(0.01);

      TLegend *l = new TLegend(0.1,0.0,0.9,1.0);
      l->SetBorderSize(0);
      l->SetNColumns(2);

      p_legend->Draw();
      c1->cd();
      p_plot->Draw();
      p_plot->cd();


      h_Container->Draw();
      h_Container->SetStats(0);       

      g_Eff->Draw("P same");
      g_Pur->Draw("P same");


      c1->Print("test.pdf");
      c1->Print("test.png");

      p_plot->cd();

      int binmax = 1.0;

      Float_t rightmax = 2.55;
      double scale = p_plot->GetUymax()/rightmax;

      TGaxis *axis = new TGaxis(p_plot->GetUxmax(),p_plot->GetUymin(),
            p_plot->GetUxmax(), p_plot->GetUymax(),0,rightmax,510,"+L");

      axis->SetTitleColor(4);
      axis->SetLabelColor(4);
      axis->SetLabelSize(0.035);
      axis->SetTitleSize(0.035);
      axis->SetTitleFont(42);
      axis->SetLabelFont(42);

      for(int i=0;i<S_v.size();i++){

         S_v[i] *= scale;

      }

      TGraph *g_S = new TGraph(x.size(),&(x[0]),&(S_v[0]));
      g_S->SetMarkerStyle(21);
      g_S->SetMarkerColor(4);

      axis->SetTitle("S/#sqrt{S+B}");
      axis->Draw();

      l->AddEntry(g_Eff,"Efficiency","P");
      l->AddEntry(g_S,"S/#sqrt{S+B}","P");
      l->AddEntry(g_Pur,"Purity","P");

      g_S->Draw("P same");

      c1->cd();
      p_legend->cd();
      l->Draw();

      c1->cd();
      p_plot->cd();

      c1->Print(("Plots/" + label +"_Performance.pdf").c_str());        

      c1->Clear();          
      c1->Close();


      g_Eff->Write("Efficiency");
      g_Pur->Write("Purity");
      g_S->Write("Significance");

      f_graphs->Close(); 

      std::cout << std::endl << std::endl << "Trying New Estimators" << std::endl;

      TCanvas *c2 = new TCanvas("c","c");

      TH1D *h_PassedSignal = (TH1D*)Eff->GetPassedHistogram();
      TH1D *h_TotalSignal = (TH1D*)Eff->GetTotalHistogram();
      TH1D *h_PassedBackground = (TH1D*)Background_Acceptance->GetPassedHistogram();
      TH1D *h_TotalBackground = (TH1D*)Background_Acceptance->GetTotalHistogram();

      Eff->SetStatisticOption(TEfficiency::kBUniform);
      Background_Acceptance->SetStatisticOption(TEfficiency::kBUniform);


      //     Eff->SetPosteriorMode();
      Background_Acceptance->SetPosteriorMode();

      for(int i_c=1;i_c<h_PassedSignal->GetNbinsX()+1;i_c++){
         std::cout << std::endl << "Cut Number " << i_c << std::endl;

         std::cout << "Total Signal = " << h_TotalSignal->GetBinContent(i_c) << "  Signal Passed = " << h_PassedSignal->GetBinContent(i_c) << std::endl;
         std::cout << "Total Background = " << h_TotalBackground->GetBinContent(i_c) << "  Background Passed = " << h_PassedBackground->GetBinContent(i_c) << std::endl;

         std::cout << "Signal Efficiency = " << Eff->GetEfficiency(i_c) << " + " << Eff->GetEfficiencyErrorUp(i_c) << " - " << Eff->GetEfficiencyErrorLow(i_c) << std::endl;

         std::cout << "Background Acceptance = " << Background_Acceptance->GetEfficiency(i_c) << " + " << Background_Acceptance->GetEfficiencyErrorUp(i_c) << " - " << Background_Acceptance->GetEfficiencyErrorLow(i_c) << std::endl;


         std::cout << "Selected Signal = " << h_TotalSignal->GetBinContent(i_c)*Eff->GetEfficiency(i_c)  << " + " << h_TotalSignal->GetBinContent(i_c)*Eff->GetEfficiencyErrorUp(i_c) << " - " << h_TotalSignal->GetBinContent(i_c)*Eff->GetEfficiencyErrorLow(i_c) << std::endl;

         std::cout << "Selected Background = " << h_TotalBackground->GetBinContent(i_c)*Background_Acceptance->GetEfficiency(i_c) << " + " << h_TotalBackground->GetBinContent(i_c)*Background_Acceptance->GetEfficiencyErrorUp(i_c) << " - " << h_TotalBackground->GetBinContent(i_c)*Background_Acceptance->GetEfficiencyErrorLow(i_c) << std::endl;

      }

      std::cout << std::endl << std::endl;


      TFile *f_out = TFile::Open(("Expected_Events_" + label + ".root").c_str(),"RECREATE");

      TH1D *h_ExpectedSignal = PosteriorPDF(Eff,8,"Signal");
      TH1D *h_ExpectedBackground = PosteriorPDF(Background_Acceptance,8,"Background");

      h_ExpectedSignal->Write();
      h_ExpectedBackground->Write();  

      f_out->Close();


      std::cout << std::endl << std::endl << "Background AR = " << Background_Acceptance->GetEfficiency(8) << std::endl;

   }
