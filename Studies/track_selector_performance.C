R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so)
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so)

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

void track_selector_performance(){

    //double POT = 1.25e21; // POT to scale samples to
    double POT = 1.5e21;

    double EXT_POT = 1.0421e20;

    BuildTunes();
    //SelectionParameters P = P_FHC_Tune_325_NoBDT;
    SelectionParameters P = P_RHC_Tune_397_NoBDT;

    std::string label = "background_rhc_track_multi";
    std::string SampleType = "background";

    EventAssembler E(false);
    SelectionManager M(P);
    M.ImportSelectorBDTWeights("/exp/uboone/app/users/nlane/NeutralKaonAnalysis/TMVA/SelectorMVA/dataset/weights");
    M.ImportAnalysisBDTWeights("/exp/uboone/app/users/nlane/NeutralKaonAnalysis/TMVA/AnalysisMVA/dataset/weights");

    //M.SetBeamMode(kFHC);
    M.SetBeamMode(kRHC);
    
    M.SetPOT(POT);
    M.UseFluxWeight(false);
    M.UseGenWeight(false);
    
     //////// RHC!!!

    SampleNames.push_back("GENIE kaon");
    SampleTypes.push_back("Kaon");
    SampleFiles.push_back("analysisOutputRHC_GENIE_Overlay_Kaon_cthorpe_make_k0s_events_numi_rhc_reco2_REAL_reco2_reco2.root");

    SampleNames.push_back("GENIE Background");
    SampleTypes.push_back("Background");
    SampleFiles.push_back("analysisOutputRHC_GENIE_Overlay_Background_prodgenie_numi_uboone_overlay_rhc_mcc9_run3b_v28_v2_sample0.root");

    SampleNames.push_back("GENIE Dirt");
    SampleTypes.push_back("Dirt");
    SampleFiles.push_back("analysisOutputRHC_GENIE_Overlay_Dirt_prodgenie_numi_uboone_overlay_dirt_rhc_mcc9_run3b_v28_sample0.root");

    SampleNames.push_back("EXT run3");
    SampleTypes.push_back("EXT");
    SampleFiles.push_back("analysisOutputEXT_cthorpe_prod_extnumi_mcc9_v08_00_00_45_run3_run3b_reco2_all_reco2_pt1.root");

    SampleNames.push_back("EXT run1");
    SampleTypes.push_back("EXT");
    SampleFiles.push_back("analysisOutputEXT_cthorpe_prod_mcc9_v08_00_00_45_extnumi_reco2_run1_all_reco2_pt1.root");


    /////// FHC!!!!!

    /*SampleNames.push_back("GENIE kaon");
    SampleTypes.push_back("Kaon");
    SampleFiles.push_back("analysisOutputFHC_Overlay_GENIE_Kaon_cthorpe_make_k0s_events_numi_fhc_reco2_reco2_reco2.root");

    SampleNames.push_back("GENIE Background");
    SampleTypes.push_back("Background");
    SampleFiles.push_back("analysisOutputFHC_GENIE_Overlay_Background_prodgenie_numi_uboone_overlay_fhc_mcc9_run1_v28_v2_sample0.root");

    SampleNames.push_back("GENIE Dirt");
    SampleTypes.push_back("Dirt");
    SampleFiles.push_back("analysisOutputRHC_GENIE_Overlay_Dirt_prodgenie_numi_uboone_overlay_dirt_rhc_mcc9_run3b_v28_sample0.root");

    SampleNames.push_back("EXT run3");
    SampleTypes.push_back("EXT");
    SampleFiles.push_back("analysisOutputEXT_cthorpe_prod_extnumi_mcc9_v08_00_00_45_run3_run3b_reco2_all_reco2_pt1.root");

    SampleNames.push_back("EXT run1");
    SampleTypes.push_back("EXT");
    SampleFiles.push_back("analysisOutputEXT_cthorpe_prod_mcc9_v08_00_00_45_extnumi_reco2_run1_all_reco2_pt1.root");*/

    int count = 0;

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
            if(!M.ChooseMuonCandidate(e)) continue;

            // Sort through list of candiadate tracks
            for(size_t i_tr=0;i_tr<e.TracklikePrimaryDaughters.size();i_tr++){
                for(size_t j_tr=0;j_tr<e.TracklikePrimaryDaughters.size();j_tr++){

                    if(i_tr == j_tr) continue;

                    double score = M.GetSelectorBDTScore(e.TracklikePrimaryDaughters.at(i_tr), e.TracklikePrimaryDaughters.at(j_tr));

                    // If these tracks are the correct pair of decay tracks, fill signal tree 
                    if(e.GoodReco && e.TracklikePrimaryDaughters.at(i_tr).Index == e.TrueDecayPionPlusIndex && e.TracklikePrimaryDaughters.at(j_tr).Index == e.TrueDecayPionMinusIndex)
                        t_Signal->Fill();         
                    else t_Background->Fill();

                }
            }
            
        }
    }

    M.PrintAllCuts();

    std::cout << count << std::endl;

    E.Close();

}