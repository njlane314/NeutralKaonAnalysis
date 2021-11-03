R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so)
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so)

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

#include "ForwardFolder2.h"

   // Produces response matrix, calculates cross sections
   // in reco space. Takes generator predictions supplied in
   // DifferentialCrossSections_NuMI_FHC.root and folds them
   // through the response for comparison
   // Run DifferentialCrossSections.C on some NuWro events
   // first

   void GenerateResponseMatrix(){

      double POT = 1.0e21; // POT to scale samples to

      BuildTunes();
      //ImportSamples(sNuWroFullFHC);

      SampleNames.push_back("GENIE Background");
      SampleTypes.push_back("Background");
      SampleFiles.push_back("HyperonTrees_Sys.root");

      SelectionParameters P = P_FHC_Tune_325;

      std::string label = "test";

      double ntrgts = 6.5318e29;

      // Setup selection manager. Set POT to scale sample to, import the BDT weights
      EventAssembler E;
      SelectionManager M(P);
      M.SetPOT(POT);
      M.ImportSelectorBDTWeights(P.p_SelectorBDT_WeightsDir);
      M.ImportAnalysisBDTWeights(P.p_AnalysisBDT_WeightsDir);

      ForwardFolder2 Muon_Momentum_Folder2("Muon_Momentum","Muon Momentum (GeV/c)",10,10,0.0,6.0);
      ForwardFolder2 Lambda_Momentum_Folder2("Lambda_Momentum","Lambda Momentum (GeV/c)",10,10,0.0,2.0);
      ForwardFolder2 Proton_Momentum_Folder2("Proton_Momentum","Proton Momentum (GeV/c)",10,10,0.0,1.5);
      ForwardFolder2 Pion_Momentum_Folder2("Pion_Momentum","Pion Momentum (GeV/c)",10,10,0.0,0.5);

      // Sample Loop
      for(size_t i_s=0;i_s<SampleNames.size();i_s++){

         E.SetFile(SampleFiles.at(i_s));
         if(SampleTypes.at(i_s) != "EXT" && SampleTypes.at(i_s) != "Data") M.AddSample(SampleNames.at(i_s),SampleTypes.at(i_s),E.GetPOT(),EventLists.at(i_s));
         else if(SampleTypes.at(i_s) == "Data") M.AddSample(SampleNames.at(i_s),SampleTypes.at(i_s),Data_POT,EventLists.at(i_s));
         else if(SampleTypes.at(i_s) == "EXT") M.AddSample(SampleNames.at(i_s),SampleTypes.at(i_s),EXT_POT,EventLists.at(i_s));

         // Event Loop
         for(int i=0;i<E.GetNEvents();i++){

            Event e = E.GetEvent(i);

            M.SetSignal(e);                

            if(!e.IsSignal) continue;

            M.AddEvent(e);           

            double TrueLambdaMomentum = e.Hyperon.at(0).ModMomentum;
            double TrueMuonMomentum = e.Lepton.at(0).ModMomentum;

            double TrueDecayProtonMomentum,TrueDecayPionMomentum;

            if(e.Decay.at(0).PDG == 2212) TrueDecayProtonMomentum = e.Decay.at(0).ModMomentum;                
            if(e.Decay.at(0).PDG == -211) TrueDecayPionMomentum = e.Decay.at(0).ModMomentum;               

            if(e.Decay.at(1).PDG == 2212) TrueDecayProtonMomentum = e.Decay.at(1).ModMomentum;                
            if(e.Decay.at(1).PDG == -211) TrueDecayPionMomentum = e.Decay.at(1).ModMomentum;                                             

            Muon_Momentum_Folder2.AddGenEvent(TrueMuonMomentum,e.Weight);
            Lambda_Momentum_Folder2.AddGenEvent(TrueLambdaMomentum,e.Weight);
            Proton_Momentum_Folder2.AddGenEvent(TrueDecayProtonMomentum,e.Weight);
            Pion_Momentum_Folder2.AddGenEvent(TrueDecayPionMomentum,e.Weight);

            if(!M.FiducialVolumeCut(e)) continue;
            if(!M.TrackCut(e)) continue;
            if(!M.ShowerCut(e)) continue;
            if(!M.ChooseMuonCandidate(e)) continue;
            if(!M.ChooseProtonPionCandidates(e)) continue;
            if(!M.AnalysisBDTCut(e)) continue;       
            if(!M.EventListCut(e)) continue;

            double RecoMuonMomentum = e.MuonCandidate.MuonMomentum;
            double RecoLambdaMomentum = LambdaMomentum(e.DecayProtonCandidate,e.DecayPionCandidate);
            double RecoDecayProtonMomentum = ProtonMomentum(e.DecayProtonCandidate.TrackLength);
            double RecoDecayPionMomentum = PionMomentum(e.DecayPionCandidate.TrackLength);

            Muon_Momentum_Folder2.AddRecoEvent(RecoMuonMomentum,TrueMuonMomentum,e.Weight);
            Lambda_Momentum_Folder2.AddRecoEvent(RecoLambdaMomentum,TrueLambdaMomentum,e.Weight);
            Proton_Momentum_Folder2.AddRecoEvent(RecoDecayProtonMomentum,TrueDecayProtonMomentum,e.Weight);
            Pion_Momentum_Folder2.AddRecoEvent(RecoDecayPionMomentum,TrueDecayPionMomentum,e.Weight);

         }

         E.Close();

      }

      // Get the true differential cross section
      TFile *f_true = TFile::Open("DifferentialCrossSections_NuMI_FHC.root");

      Muon_Momentum_Folder2.GetResponseMatrix();
      Lambda_Momentum_Folder2.GetResponseMatrix();
      Proton_Momentum_Folder2.GetResponseMatrix();
      Pion_Momentum_Folder2.GetResponseMatrix();

      TH1D *h_true_Muon_Momentum;
      TH1D *h_true_Lambda_Momentum;
      TH1D *h_true_Proton_Momentum;
      TH1D *h_true_Pion_Momentum;

      f_true->GetObject("Muon_Momentum",h_true_Muon_Momentum);
      f_true->GetObject("Lambda_Momentum",h_true_Lambda_Momentum);
      f_true->GetObject("Proton_Momentum",h_true_Proton_Momentum);
      f_true->GetObject("Pion_Momentum",h_true_Pion_Momentum);

      // Get the flux histograms
      TFile *f_flux = TFile::Open("../Fluxes/output_uboone_fhc_run0_merged.root");

      TH1D *h_numubar_flux;

      f_flux->GetObject("numubar/Detsmear/numubar_CV_AV_TPC",h_numubar_flux);

      for(int i=1;i<h_numubar_flux->GetNbinsX()+1;i++) h_numubar_flux->SetBinContent(i,h_numubar_flux->GetBinContent(i)/h_numubar_flux->GetBinWidth(i));

      h_numubar_flux->Draw("HIST");
      h_numubar_flux->Scale(POT);

      Muon_Momentum_Folder2.AddFluxHist(h_numubar_flux);
      Lambda_Momentum_Folder2.AddFluxHist(h_numubar_flux);
      Proton_Momentum_Folder2.AddFluxHist(h_numubar_flux);
      Pion_Momentum_Folder2.AddFluxHist(h_numubar_flux);

      Muon_Momentum_Folder2.SetTargets(ntrgts);
      Muon_Momentum_Folder2.AddDifferentialCrossSection(h_true_Muon_Momentum);
      Muon_Momentum_Folder2.Write();


      Lambda_Momentum_Folder2.SetTargets(ntrgts);
      Lambda_Momentum_Folder2.AddDifferentialCrossSection(h_true_Lambda_Momentum);
      Lambda_Momentum_Folder2.Write();

      Proton_Momentum_Folder2.SetTargets(ntrgts);
      Proton_Momentum_Folder2.AddDifferentialCrossSection(h_true_Proton_Momentum);
      Proton_Momentum_Folder2.Write();

      Pion_Momentum_Folder2.SetTargets(ntrgts);
      Pion_Momentum_Folder2.AddDifferentialCrossSection(h_true_Pion_Momentum);
      Pion_Momentum_Folder2.Write();

   }
