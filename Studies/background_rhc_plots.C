R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so)
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so)

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

void background_rhc_plots(){

    double POT = 1.5e21;

    BuildTunes();
    SelectionParameters P = P_RHC_Tune_397_NoBDT;

    std::string label = "background_rhc_track_multi";
    std::string SampleType = "background";

    EventAssembler E(false);
    SelectionManager M(P);

    M.SetBeamMode(kRHC);
    
    M.SetPOT(POT);
    M.UseFluxWeight(false);
    M.UseGenWeight(false);

    /*SampleNames.push_back("GENIE Background");
    SampleTypes.push_back("Background");
    SampleFiles.push_back("analysisOutputRHC_GENIE_Overlay_Background_prodgenie_numi_uboone_overlay_rhc_mcc9_run3b_v28_v2_sample0.root");

    SampleNames.push_back("GENIE Dirt");
    SampleTypes.push_back("Dirt");
    SampleFiles.push_back("analysisOutputRHC_GENIE_Overlay_Dirt_prodgenie_numi_uboone_overlay_dirt_rhc_mcc9_run3b_v28_sample0.root");

    SampleNames.push_back("GENIE Dirt");
    SampleTypes.push_back("Dirt");
    SampleFiles.push_back("analysisOutputRHC_GENIE_Overlay_Dirt_prodgenie_numi_uboone_overlay_dirt_rhc_mcc9_run3b_v28_sample0.root");*/

    SampleNames.push_back("GENIE kaon");
    SampleTypes.push_back("Kaon");
    SampleFiles.push_back("analysisOutputRHC_GENIE_Overlay_Kaon_cthorpe_make_k0s_events_numi_rhc_reco2_REAL_reco2_reco2.root");

    //M.SetupHistograms(10,0,10.0,";Track Multiplicity; Events/bin"); 
    M.SetupHistograms(8,0,8.0,";Shower Multiplicity; Events/bin"); 

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

            bool passed_FV = false;
            bool passed_muon = false;

            passed_FV = M.FiducialVolumeCut(e);
            if(!passed_FV) continue;

            //M.FillHistograms(e,e.NPrimaryTrackDaughters); 
            M.FillHistograms(e,e.NPrimaryShowerDaughters);        
        }
    }

    std::cout << "Drawing histograms" << std::endl;
    M.DrawHistograms(label);
    
    E.Close();
}