R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so);
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so);

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Nov21.h"

#include "GetCovMatrix.h"
//#include "HandScanning.h"

#include "FluxWeight2.h"
#include "GenG4WeightHandler2.h"
#include "SystematicsHeader.h"

void Detector_Uncertainties_ForSensitivity(){

   std::string label="test";

   BuildTunes();

   std::vector<int> Runs = {1,3};
   std::vector<SelectionParameters> P = {P_FHC_Tune_325_NoBDT,P_RHC_Tune_397_NoBDT};
   std::vector<int> Samples = {sGENIERun1FHCDetvar,sGENIERun3bRHCDetvar};

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

   for(int i_sys=0;i_sys<duMAX;i_sys++){
      Flux_m[DetectorU_Str.at(i_sys)] = std::vector<double>(DetectorU_Universes.at(i_sys),0);
      Eff_m[DetectorU_Str.at(i_sys)] = std::vector<double>(DetectorU_Universes.at(i_sys),0);
      Signal_m[DetectorU_Str.at(i_sys)] = std::vector<double>(DetectorU_Universes.at(i_sys),0);
      SelSignal_m[DetectorU_Str.at(i_sys)] = std::vector<double>(DetectorU_Universes.at(i_sys),0);
      BG_m[DetectorU_Str.at(i_sys)] = std::vector<double>(DetectorU_Universes.at(i_sys),0);
      Sys_Dials.push_back(DetectorU_Str.at(i_sys));
   }

   // Set the fluxes 
   double Flux_CV = 0.0;
   for(size_t i_r=0;i_r<Runs.size();i_r++){
      ImportSamples(Samples.at(i_r));
      Flux_CV += GetIntegratedFlux2(Mode,Data_POT,"CV").at(0);
   }
   for(size_t i_sys=0;i_sys<Sys_Dials.size();i_sys++)
      for(size_t i_u=0;i_u<Flux_m[Sys_Dials.at(i_sys)].size();i_u++)
         Flux_m[Sys_Dials.at(i_sys)].at(i_u) = Flux_CV;

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

      // Loop over variations
      for(size_t i_var=0;i_var<Detvar_Names.size();i_var++){

         std::cout << "Processing variation " << Detvar_Names.at(i_var) << std::endl;

         // Sample Loop
         for(size_t i_s=0;i_s<SampleNames_Detvar.at(i_var).size();i_s++){

            std::string SampleName = SampleNames_Detvar.at(i_var).at(i_s);
            std::string SampleType = SampleTypes_Detvar.at(i_var).at(i_s);
            std::string SampleFile = SampleFiles_Detvar.at(i_var).at(i_s);        

            if(SampleType != "Hyperon" && SampleType != "Neutron") continue;

            E.SetFile(SampleFile);
            double POT = POTs.at(i_s)*Scales.at(i_s); 
            M.AddSample(SampleName,SampleType,POT);

            // Event Loop
            for(int i=0;i<E.GetNEvents();i++){

               if(i % 10000 == 0) std::cout << "Event " << i << " of " << E.GetNEvents() << std::endl;

               Event e = E.GetEvent(i);

               M.SetSignal(e);                
               M.AddEvent(e);

               if((SampleType == "EXT" || SampleType == "Data") && !(std::find(GoodRuns.begin(),GoodRuns.end(), e.run) != GoodRuns.end())) continue;
               if(CommonRSLists.at(i_s).size() && !(std::find(CommonRSLists.at(i_s).begin(),CommonRSLists.at(i_s).end(),std::make_pair(e.run,e.subrun)) != CommonRSLists.at(i_s).end())) continue;

               bool passed = M.FiducialVolumeCut(e) && M.TrackCut(e) && M.ShowerCut(e) && M.ChooseMuonCandidate(e) && M.ChooseProtonPionCandidates(e) && M.ConnectednessTest(e) && M.WCut(e) && M.AngleCut(e);

               G.LoadEvent(e); 
               e.Weight *= FluxWeightCalc.GetFluxWeight(e)*G.GetCVWeight();

               ////////////////////////////

               if(e.EventIsSignal){
                  if(Detvar_Names.at(i_var) == "CV"){ 
                     Signal_CV += e.Weight;
                     if(passed) SelSignal_CV += e.Weight;
                  }
                  else {
                     Signal_m[Detvar_Names.at(i_var)].at(0) += e.Weight;
                     if(passed) SelSignal_m[Detvar_Names.at(i_var)].at(0) += e.Weight;
                  }                  
               }
               else {
                  if(Detvar_Names.at(i_var) == "CV"){ 
                     if(passed) BG_CV += e.Weight;
                  }
                  else {
                     if(passed) BG_m[Detvar_Names.at(i_var)].at(0) += e.Weight;
                  }
               } 
            }
            E.Close();
         }
      }
   }

   // Calculate the efficiency in each universe
   double Eff_CV = SelSignal_CV/Signal_CV;
   for(size_t i_sys=0;i_sys<Sys_Dials.size();i_sys++)
      for(size_t i_u=0;i_u<Flux_m[Sys_Dials.at(i_sys)].size();i_u++)
         Eff_m[Sys_Dials.at(i_sys)].at(i_u) = SelSignal_m[Sys_Dials.at(i_sys)].at(i_u)/Signal_m[Sys_Dials.at(i_sys)].at(i_u); 

   gSystem->Exec("mkdir -p rootfiles");
   TFile *f = TFile::Open(("rootfiles/" + label + "_Detector_CrossSectionCov.root").c_str(),"RECREATE");

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
