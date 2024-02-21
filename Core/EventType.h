#ifndef _EventType_h_
#define _EventType_h_

#include "Event.h"

namespace EventType {

    const std::vector<std::string> PureKaonSampleTypes = {"SignalNuMuCCKaon", "SignalNuMuCCKaonMultiPion", "SignalNuMuCCKaonHyperon", "SignalNuMuCCKaonHyperonMultiPion", "OtherNuMuCC", "NuECC", "NC", "OutFV","BeamOff", "Other"};
    const std::vector<std::string> PureKaonSampleCaptions = {"#nu_{#mu}CCK^{0}0#pi", "#nu_{#mu}CCK^{0}N#pi", "#nu_{#mu}CCK^{0}Y0#pi", "#nu_{#mu}CCK^{0}YN#pi", "Other #nu_{#mu}CC", "#nu_{e}CC", "NC", "Out FV", "Beam-Off", "Other"};
    const std::vector<int> PureKaonSampleColours = {kGreen, kGreen + 1, kGreen + 2, kGreen + 3, 30, kViolet - 2, kOrange, kGray, kBlack, kRed + 1};

    std::string GetPureKaonType(const Event &e){
        if(e.Neutrino.empty()) return "Other";

        int abs_nu_pdg = std::abs(e.Neutrino.at(0).PDG);
        bool is_nu = (abs_nu_pdg == 12 || abs_nu_pdg == 14);
        bool nu_is_numu = (abs_nu_pdg == 14);
        std::string nu_ccnc = e.CCNC.at(0);

        if(e.Mode.at(0) == "EXT" || e.Mode.at(0) == "Dirt"){
            return "BeamOff";
        } 
        else if(!e.EventInFV){
            return "OutFV";
        }
        else if(nu_ccnc == "NC"){
            return "NC";
        }
        else if(e.EventIsSignal && !e.PrimaryPion.empty() && e.EventIsSingleProduction){
            return "SignalNuMuCCKaonMultiPion";
        }
        else if(e.EventIsSignal && !e.PrimaryPion.empty() && e.EventIsAssociatedProduction){
            return "SignalNuMuCCKaonHyperonMultiPion";
        }
        else if(e.EventIsSignal && e.EventIsSingleProduction){
            return "SignalNuMuCCKaon";
        }
        else if(e.EventIsSignal && e.EventIsAssociatedProduction){
            return "SignalNuMuCCKaonHyperon";
        }
        else if(!e.EventIsSignal && abs_nu_pdg == 14 && nu_ccnc == "CC"){
            return "OtherNuMuCC";
        }
        else if(!e.EventIsSignal && abs_nu_pdg == 12 && nu_ccnc == "CC"){
            return "NuECC";
        }
        else{
            return "Other";
        }
    }

    const std::vector<std::string> BackgroundTypes = {"Signal", "Other", "Dirt", "Cosmic" };
    const std::vector<std::string> BackgroundCaptions = {"Signal", "Other #nu", "Dirt", "Cosmic" };
    const std::vector<int> BackgroundColours = {8,30,38,15};

    std::string GetBackgroundType(const Event &e){

        if(!e.Mode.size()) throw std::invalid_argument("GetType: Event has Mode.size() = 0, should be at least 1");

        if(e.Mode.at(0) == "EXT") return "Cosmic";
        else if(e.Mode.at(0) == "Dirt") return "Dirt";
        else if(e.EventIsSignal) return "Signal";

        return "Other";
    }

};	
		
#endif