R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so)
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so)

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

void background_angular_dev(){

    double POT = 1.25e21; // POT to scale samples to
    //double POT = 1.5e21;

    double EXT_POT = 1.0421e20;

    BuildTunes();
    SelectionParameters P = P_FHC_Tune_325_NoBDT;
    //SelectionParameters P = P_RHC_Tune_397_NoBDT;

    std::string label = "background_fhc_ang_dev";
    std::string SampleType = "background";

    EventAssembler E(false);
    SelectionManager M(P);
    M.ImportSelectorBDTWeights("/uboone/app/users/nlane/NeutralKaonAnalysis/TMVA/SelectorMVA/dataset/weights");

    M.SetBeamMode(kFHC);
    //M.SetBeamMode(kRHC);
    
    M.SetPOT(POT);
    M.UseFluxWeight(false);
    M.UseGenWeight(false);

    //////// RHC!!!

    /*SampleNames.push_back("GENIE Background");
    SampleTypes.push_back("Background");
    SampleFiles.push_back("analysisOutputRHC_GENIE_Overlay_Background_prodgenie_numi_uboone_overlay_rhc_mcc9_run3b_v28_v2_sample0.root");

    SampleNames.push_back("GENIE Dirt");
    SampleTypes.push_back("Dirt");
    SampleFiles.push_back("analysisOutputRHC_GENIE_Overlay_Dirt_prodgenie_numi_uboone_overlay_dirt_rhc_mcc9_run3b_v28_sample0.root");

    SampleNames.push_back("GENIE kaon");
    SampleTypes.push_back("Kaon");
    SampleFiles.push_back("analysisOutputRHC_GENIE_Overlay_Kaon_cthorpe_make_k0s_events_numi_rhc_reco2_REAL_reco2_reco2.root");

    SampleNames.push_back("EXT run3");
    SampleTypes.push_back("EXT");
    SampleFiles.push_back("analysisOutputEXT_cthorpe_prod_extnumi_mcc9_v08_00_00_45_run3_run3b_reco2_all_reco2_pt1.root");

    SampleNames.push_back("EXT run1");
    SampleTypes.push_back("EXT");
    SampleFiles.push_back("analysisOutputEXT_cthorpe_prod_mcc9_v08_00_00_45_extnumi_reco2_run1_all_reco2_pt1.root");*/


    /////// FHC!!!!!

    SampleNames.push_back("GENIE Background");
    SampleTypes.push_back("Background");
    SampleFiles.push_back("analysisOutputFHC_GENIE_Overlay_Background_prodgenie_numi_uboone_overlay_fhc_mcc9_run1_v28_v2_sample0.root");

    SampleNames.push_back("GENIE Dirt");
    SampleTypes.push_back("Dirt");
    SampleFiles.push_back("analysisOutputRHC_GENIE_Overlay_Dirt_prodgenie_numi_uboone_overlay_dirt_rhc_mcc9_run3b_v28_sample0.root");

    SampleNames.push_back("GENIE kaon");
    SampleTypes.push_back("Kaon");
    SampleFiles.push_back("analysisOutputFHC_Overlay_GENIE_Kaon_cthorpe_make_k0s_events_numi_fhc_reco2_reco2_reco2.root");

    SampleNames.push_back("EXT run3");
    SampleTypes.push_back("EXT");
    SampleFiles.push_back("analysisOutputEXT_cthorpe_prod_extnumi_mcc9_v08_00_00_45_run3_run3b_reco2_all_reco2_pt1.root");

    SampleNames.push_back("EXT run1");
    SampleTypes.push_back("EXT");
    SampleFiles.push_back("analysisOutputEXT_cthorpe_prod_mcc9_v08_00_00_45_extnumi_reco2_run1_all_reco2_pt1.root");

    /*SampleNames.push_back("Neutron");
    SampleTypes.push_back("Neutron");
    SampleFiles.push_back("analysisOutputFHC_GENIE_Overlay_Neutron_cthorpe_numi_run1_fhc_neutron.root");*/

    //M.SetupHistograms(8,0,8.0,";Track Multiplicity; Events/bin"); 
    //M.SetupHistograms(5,0,5.0,";Shower Multiplicity; Events/bin");

    M.SetupHistograms(18,0,180,";Angular Deviation (deg);Events/bin");

    for(size_t i_s=0;i_s<SampleNames.size();i_s++){

        E.SetFile(SampleFiles.at(i_s), SampleTypes.at(i_s));
        if(SampleTypes.at(i_s) != "EXT" && SampleTypes.at(i_s) != "Data") M.AddSample(SampleNames.at(i_s),SampleTypes.at(i_s),E.GetPOT());
        else if(SampleTypes.at(i_s) == "Data") M.AddSample(SampleNames.at(i_s),SampleTypes.at(i_s),Data_POT);
        else if(SampleTypes.at(i_s) == "EXT") M.AddSample(SampleNames.at(i_s),SampleTypes.at(i_s),EXT_POT);

        for(int i = 0; i < E.GetNEvents(); i++){           
            if(i % 10000 == 0) std::cout << i << "/" << E.GetNEvents() << std::endl;

            Event e = E.GetEvent(i);

            M.SetSignal(e);              
            M.AddEvent(e); 

            if(!M.FiducialVolumeCut(e)) continue;
            if(!M.TrackCut(e)) continue;
            if(!M.ShowerCut(e)) continue;
            if(!M.ChooseMuonCandidate(e)) continue;
            if(!M.ChoosePionPairCandidates(e)) continue;

            SecondaryVertexFitter a_SecondaryVertexFitter;
            SecondaryVertex V = a_SecondaryVertexFitter.MakeVertex(e.DecayPionPlusCandidate, e.DecayPionMinusCandidate);

            TVector3 GapVector = V.Vertex - e.RecoPrimaryVertex;
            double Reco_DecayLength = (V.Vertex - e.RecoPrimaryVertex).Mag();

            TLorentzVector NeutralKaon4Momentum = PionPair4Momentum(e.DecayPionPlusCandidate, e.DecayPionMinusCandidate);

            TVector3 NeutralKaonDirection(NeutralKaon4Momentum.X(), NeutralKaon4Momentum.Y(), NeutralKaon4Momentum.Z());
            double alpha = (180/3.1415) * NeutralKaonDirection.Angle(GapVector);
            
            M.FillHistograms(e,alpha);   
            
        }
    }

    std::cout << "Drawing histograms" << std::endl;
    M.DrawHistograms(label);

    E.Close();
}