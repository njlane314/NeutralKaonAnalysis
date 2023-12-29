R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so);
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so);

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Nov21.h"
#include "GetCovMatrix.h"
#include "FluxWeight2.h"
#include "GenG4WeightHandler2.h"
#include "SystematicsHeader.h"

void SelectedSignalBG_ForSensitivity(){

   std::string label="test";

   BuildTunes();

   std::vector<int> Runs = {1,3};
   std::vector<SelectionParameters> P = {P_FHC_Tune_325_NoBDT,P_RHC_Tune_397_NoBDT};
   std::vector<int> Samples = {sGENIERun1FHC,sGENIERun3bRHC};

   // Calculate the fluxes
   ImportSamples(Samples.at(0));

   // Need to record the flux, efficiency and selected background in every universe,
   // set up maps to store this information
   std::map<std::string,std::vector<double>> Flux_m; // Flux in each systematic universe for each dial
   std::map<std::string,std::vector<double>> Eff_m; // Efficiency in each systematic universe for each dial
   std::map<std::string,std::vector<double>> Signal_m; // Total signal in each systematic universe for each dial
   std::map<std::string,std::vector<double>> SelSignal_m; // Selected signal in each systematic universe for each dial   
   std::map<std::string,std::vector<double>> BG_m; // Selected BG in each systematic universe for each dial
   std::vector<std::string> Sys_Dials;

   double Signal_CV = 0.0;
   double SelSignal_CV = 0.0;
   double BG_CV = 0.0;

   for(int i_sys=0;i_sys<fuMAX;i_sys++){
      Flux_m[FluxU_Str.at(i_sys)] = std::vector<double>(FluxU_Universes.at(i_sys),0);
      Eff_m[FluxU_Str.at(i_sys)] = std::vector<double>(FluxU_Universes.at(i_sys),0);
      Signal_m[FluxU_Str.at(i_sys)] = std::vector<double>(FluxU_Universes.at(i_sys),0);
      SelSignal_m[FluxU_Str.at(i_sys)] = std::vector<double>(FluxU_Universes.at(i_sys),0);
      BG_m[FluxU_Str.at(i_sys)] = std::vector<double>(FluxU_Universes.at(i_sys),0);
      Sys_Dials.push_back(FluxU_Str.at(i_sys));
   }
   for(int i_sys=0;i_sys<guMAX;i_sys++){
      Flux_m[GeneratorU_Str.at(i_sys)] = std::vector<double>(GeneratorU_Universes.at(i_sys),0);
      Eff_m[GeneratorU_Str.at(i_sys)] = std::vector<double>(GeneratorU_Universes.at(i_sys),0);
      Signal_m[GeneratorU_Str.at(i_sys)] = std::vector<double>(GeneratorU_Universes.at(i_sys),0);
      SelSignal_m[GeneratorU_Str.at(i_sys)] = std::vector<double>(GeneratorU_Universes.at(i_sys),0);
      BG_m[GeneratorU_Str.at(i_sys)] = std::vector<double>(GeneratorU_Universes.at(i_sys),0);
      Sys_Dials.push_back(GeneratorU_Str.at(i_sys));
   }
   for(int i_sys=0;i_sys<g4uMAX;i_sys++){
      Flux_m[ReintU_Str.at(i_sys)] = std::vector<double>(ReintU_Universes.at(i_sys),0);
      Eff_m[ReintU_Str.at(i_sys)] = std::vector<double>(ReintU_Universes.at(i_sys),0);
      Signal_m[ReintU_Str.at(i_sys)] = std::vector<double>(ReintU_Universes.at(i_sys),0);
      SelSignal_m[ReintU_Str.at(i_sys)] = std::vector<double>(ReintU_Universes.at(i_sys),0);
      BG_m[ReintU_Str.at(i_sys)] = std::vector<double>(ReintU_Universes.at(i_sys),0);
      Sys_Dials.push_back(ReintU_Str.at(i_sys));
   }
   for(int i_sys=0;i_sys<muMAX;i_sys++){
      Flux_m[MiscU_Str.at(i_sys)] = std::vector<double>(MiscU_Universes.at(i_sys),0);
      Eff_m[MiscU_Str.at(i_sys)] = std::vector<double>(MiscU_Universes.at(i_sys),0);
      Signal_m[MiscU_Str.at(i_sys)] = std::vector<double>(MiscU_Universes.at(i_sys),0);
      SelSignal_m[MiscU_Str.at(i_sys)] = std::vector<double>(MiscU_Universes.at(i_sys),0);
      BG_m[MiscU_Str.at(i_sys)] = std::vector<double>(MiscU_Universes.at(i_sys),0);
      Sys_Dials.push_back(MiscU_Str.at(i_sys));
   }

   // Set the fluxes 
   double Flux_CV = 0.0;
   for(size_t i_r=0;i_r<Runs.size();i_r++){
      ImportSamples(Samples.at(i_r));
      Flux_CV += GetIntegratedFlux2(Mode,Data_POT,"CV").at(0);
      for(size_t i_sys=0;i_sys<fuMAX;i_sys++){
         if(FluxU_Str.at(i_sys) == "POT") continue;
         std::vector<double> int_flux_v = GetIntegratedFlux2(Mode,Data_POT,FluxU_Str.at(i_sys));
         for(size_t i_u=0;i_u<int_flux_v.size();i_u++){
            Flux_m[FluxU_Str.at(i_sys)].at(i_u) += int_flux_v.at(i_u);
         }
      }        
   }
   for(size_t i_sys=0;i_sys<Sys_Dials.size();i_sys++){
      if(std::find(FluxU_Str.begin(),FluxU_Str.end(),Sys_Dials.at(i_sys)) != FluxU_Str.end() && Sys_Dials.at(i_sys) != "POT") continue;
      for(size_t i_u=0;i_u<Flux_m[Sys_Dials.at(i_sys)].size();i_u++)
         Flux_m[Sys_Dials.at(i_sys)].at(i_u) = Flux_CV;
   }

   // Record the efficiency and BG acceptance using TEfficiency
   TEfficiency* Eff = new TEfficiency("Eff","",1,0,1.0); 
   TEfficiency* BG_Acc = new TEfficiency("BG","",1,0,1.0); 

   // Sample Loop

   for(int i_r=0;i_r<Runs.size();i_r++){

      ImportSamples(Samples.at(i_r));

      SelectionManager M(P.at(i_r));
      M.SetPOT(Data_POT);
      M.SetBeamMode(Mode);
      M.ImportSelectorBDTWeights(P.at(i_r).p_SelectorBDT_WeightsDir);
      M.ImportAnalysisBDTWeights(P.at(i_r).p_AnalysisBDT_WeightsDir);

      // Only calculate CV weights for selected events
      M.UseFluxWeight(false);
      M.UseGenWeight(false);

      EventAssembler E;
      GenG4WeightHandler G;  
      FluxWeighter FluxWeightCalc(Mode);
      FluxWeightCalc.PrepareHPUniv();
      FluxWeightCalc.PrepareBeamlineUniv();

      for(size_t i_s=0;i_s<SampleNames.size();i_s++){

         E.SetFile(SampleFiles.at(i_s));
         double SamplePOT = ((SampleTypes.at(i_s) != "EXT" && SampleTypes.at(i_s) != "Data") ? E.GetPOT() : SampleTypes.at(i_s) == "Data" ? Data_POT : EXT_POT)*Scales.at(i_s);
         M.AddSample(SampleNames.at(i_s),SampleTypes.at(i_s),SamplePOT);

         // Event Loop
         for(int i=0;i<E.GetNEvents();i++){

            if(i % 10000 == 0) std::cout << "Processing event " << i << " of " << E.GetNEvents() << std::endl;

            Event e = E.GetEvent(i);

            M.SetSignal(e);                
            M.AddEvent(e);        

            if((SampleTypes.at(i_s) == "EXT" || SampleTypes.at(i_s) == "Data") && !(std::find(GoodRuns.begin(),GoodRuns.end(), e.run) != GoodRuns.end())) continue;

            bool passed = M.FiducialVolumeCut(e) && M.TrackCut(e) && M.ShowerCut(e) && M.ChooseMuonCandidate(e) && M.ChooseProtonPionCandidates(e) && M.ConnectednessTest(e) && M.WCut(e) && M.AngleCut(e);

            G.LoadEvent(e); 
            e.Weight *= FluxWeightCalc.GetFluxWeight(e)*G.GetCVWeight();

            ////////////////////////////

            std::map<std::string,std::vector<double>> sys_weights;
            for(size_t i_sys=0;i_sys<Sys_Dials.size();i_sys++)
               sys_weights[Sys_Dials.at(i_sys)] = std::vector<double>(Flux_m[Sys_Dials.at(i_sys)].size(),1.0);          

            if((passed || e.EventIsSignal) && SampleTypes.at(i_s) != "EXT" && SampleTypes.at(i_s) != "Data" && SampleTypes.at(i_s) != "Dirt"){

               // Flux
               for(int i_w=0;i_w<Flux_HP_Universes;i_w++) sys_weights["Flux_HP"] = FluxWeightCalc.GetSysWeightV(e,"Flux_HP");              
               for(size_t i_d=0;i_d<Beamline_Dials.size();i_d++) sys_weights[Beamline_Dials.at(i_d)] = FluxWeightCalc.GetSysWeightV(e,Beamline_Dials.at(i_d)); 
               sys_weights["POT"] = {0.98,1.02};

               // Generator
               sys_weights["All_UBGenie"] = G.GetWeights("All_UBGenie");
               for(size_t i_d=0;i_d<AltModel_Dials.size();i_d++) sys_weights[AltModel_Dials.at(i_d)] = G.GetWeights(AltModel_Dials.at(i_d));
               sys_weights["RPA_CCQE_UBGenie"] = G.GetWeights("RPA_CCQE_UBGenie");

               // Geant 4
               for(int i_sys=0;i_sys<g4uMAX-1;i_sys++) sys_weights[ReintU_Str.at(i_sys)] = G.GetWeights(G4_Dials.at(i_sys));
               if(e.EventHasNeutronScatter) sys_weights["G4_Neutron_Dual"] = {1.26,0.74};
            }

            if(SampleTypes.at(i_s) == "Dirt") sys_weights["DirtScale"] = { 1.0-25.0/35.0 , 1.0+25.0/35.0 };

            ////////////////////////////

            if(e.EventIsSignal){                  

               Eff->FillWeighted(passed,e.Weight,0.5);
               Signal_CV += e.Weight;
               if(passed) SelSignal_CV += e.Weight;

               for(size_t i_sys=0;i_sys<Sys_Dials.size();i_sys++)
                  for(size_t i_u=0;i_u<Flux_m[Sys_Dials.at(i_sys)].size();i_u++)
                     Signal_m[Sys_Dials.at(i_sys)].at(i_u) += e.Weight*sys_weights[Sys_Dials.at(i_sys)].at(i_u);

               if(passed)             
                  for(size_t i_sys=0;i_sys<Sys_Dials.size();i_sys++)
                     for(size_t i_u=0;i_u<Flux_m[Sys_Dials.at(i_sys)].size();i_u++)
                        SelSignal_m[Sys_Dials.at(i_sys)].at(i_u) += e.Weight*sys_weights[Sys_Dials.at(i_sys)].at(i_u);
            } //Signal
            else {        
               BG_Acc->FillWeighted(passed,e.Weight,0.5);
               if(passed){             
                  BG_CV += e.Weight;
                  for(size_t i_sys=0;i_sys<Sys_Dials.size();i_sys++)
                     for(size_t i_u=0;i_u<Flux_m[Sys_Dials.at(i_sys)].size();i_u++)
                        BG_m[Sys_Dials.at(i_sys)].at(i_u) += e.Weight*sys_weights[Sys_Dials.at(i_sys)].at(i_u);
               }
            }//BG
         }
         E.Close();
      }
   }

   // Calculate the efficiency in each universe
   double Eff_CV = SelSignal_CV/Signal_CV;
   for(size_t i_sys=0;i_sys<Sys_Dials.size();i_sys++)
      for(size_t i_u=0;i_u<Flux_m[Sys_Dials.at(i_sys)].size();i_u++)
         Eff_m[Sys_Dials.at(i_sys)].at(i_u) = SelSignal_m[Sys_Dials.at(i_sys)].at(i_u)/Signal_m[Sys_Dials.at(i_sys)].at(i_u); 
        
   gSystem->Exec("mkdir -p rootfiles");
   TFile *f = TFile::Open(("rootfiles/" + label + "_CrossSectionCov.root").c_str(),"RECREATE");

   Eff->Write("Efficiency");
   BG_Acc->Write("Background_Acceptance");

   TH2D* h_template = new TH2D("h_template","",3,-0.5,2.5,3,-0.5,2.5);
   h_template->GetXaxis()->SetBinLabel(keff+1,"Eff");
   h_template->GetXaxis()->SetBinLabel(kflux+1,"Flux");
   h_template->GetXaxis()->SetBinLabel(kbg+1,"BG");
   h_template->GetYaxis()->SetBinLabel(keff+1,"Eff");
   h_template->GetYaxis()->SetBinLabel(kflux+1,"Flux");
   h_template->GetYaxis()->SetBinLabel(kbg+1,"BG");

   TH1D* h_CV = new TH1D("h_CV","",3,-0.5,2.5);
   h_CV->GetXaxis()->SetBinLabel(keff+1,"Eff");
   h_CV->GetXaxis()->SetBinLabel(kflux+1,"Flux");
   h_CV->GetXaxis()->SetBinLabel(kbg+1,"BG");
   h_CV->SetBinContent(keff+1,Eff_CV);
   h_CV->SetBinContent(kflux+1,Flux_CV);
   h_CV->SetBinContent(kbg+1,BG_CV);
   h_CV->Write("CV");

   // Calculate the covariance matrices
   TMatrixDSym Cov(3);
   TMatrixDSym FCov(3);

   for(size_t i_sys=0;i_sys<Sys_Dials.size();i_sys++){

      TMatrixDSym thisCov(3);
      if(Flux_m[Sys_Dials.at(i_sys)].size() == 1) thisCov = GetCovMatrix_SingleUnisim(Eff_m[Sys_Dials.at(i_sys)],Flux_m[Sys_Dials.at(i_sys)],BG_m[Sys_Dials.at(i_sys)],Eff_CV,Flux_CV,BG_CV);
      if(Flux_m[Sys_Dials.at(i_sys)].size() == 2) thisCov = GetCovMatrix_DualUnisim(Eff_m[Sys_Dials.at(i_sys)],Flux_m[Sys_Dials.at(i_sys)],BG_m[Sys_Dials.at(i_sys)]);
      if(Flux_m[Sys_Dials.at(i_sys)].size() > 2) thisCov = GetCovMatrix_Multisim(Eff_m[Sys_Dials.at(i_sys)],Flux_m[Sys_Dials.at(i_sys)],BG_m[Sys_Dials.at(i_sys)],Eff_CV,Flux_CV,BG_CV);

      TH2D* h_Cov = MakeHistogram(TMatrixD(thisCov),h_template,("Cov_" + Sys_Dials.at(i_sys)).c_str());  
      h_Cov->Write(("Cov_" + Sys_Dials.at(i_sys)).c_str());
      Cov += thisCov;

      TMatrixDSym thisFCov = thisCov;
      thisFCov[keff][keff] /= Eff_CV*Eff_CV;
      thisFCov[kbg][kbg] /= BG_CV*BG_CV;
      thisFCov[kflux][kflux] /= Flux_CV*Flux_CV;
      thisFCov[keff][kbg] = thisFCov[kbg][keff] = thisCov[keff][kbg]/Eff_CV/BG_CV; 
      thisFCov[keff][kflux] = thisFCov[kflux][keff] = thisCov[keff][kflux]/Eff_CV/Flux_CV; 
      thisFCov[kbg][kflux] = thisFCov[kflux][kbg] = thisCov[kflux][kbg]/Flux_CV/BG_CV; 

      TH2D* h_FCov = MakeHistogram(TMatrixD(thisFCov),h_template,("FCov_" + Sys_Dials.at(i_sys)).c_str());  
      h_FCov->Write(("FCov_" + Sys_Dials.at(i_sys)).c_str()); 
      FCov += thisFCov;
   }

   TH2D* h_Cov = MakeHistogram(TMatrixD(Cov),h_template,"Cov");  
   h_Cov->Write("Cov");
   TH2D* h_FCov = MakeHistogram(TMatrixD(FCov),h_template,"FCov");  
   h_FCov->Write("FCov");

   f->Close();
}
