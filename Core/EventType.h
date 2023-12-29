#ifndef _EventType_h_
#define _EventType_h_

#include "Event.h"

namespace EventType {
	
    const std::vector<std::string> Types = {"Signal",/*"OtherHYP",*/"OtherNu","Dirt","EXT"/*,"Data","All"*/};
    const std::vector<std::string> Captions = {"Signal",/*"Other HYP",*/"Other #nu","Dirt","Cosmic"/*,"Data"*/};
    const std::vector<int> Colors = {8,/*46,*/38,30,15,0};

    //const std::vector<std::string> Types2 = {"DirectLambda","RESLambda","DISLambda","DirectHYP","RESHYP","DISHYP","Neutron","Other","Dirt","EXT","Data","All"};
    const std::vector<std::string> Types2 = {"DirectLambda","DirectHYP","Neutron","Dirt","RESLambda","RESHYP","Other","EXT","DISLambda","DISHYP"/*,"Data"*/};
    const std::vector<std::string> Captions2 = {"Direct #Lambda","Direct Hyp","Neutron","Dirt","RES #Lambda","RES Hyp","Other #nu","Cosmic","DIS #Lambda","DIS Hyp"/*,"Data"*/};
    const std::vector<int> Colors2 = {8,kBlue-7,kRed-7,kCyan+3,kGreen+3,kBlue-10,kRed-10,kMagenta-7,30,15,0};

    const std::vector<std::string> Procs = {"Signal","OtherHYP","EXT","Dirt","CCQEL","CCRES","CCDIS","CCMEC","CCCOH","NC","Other"/*,"Data"*/};
    const std::vector<std::string> Captions3 = {"Signal","Other HYP","Cosmic","Dirt","CCQEL","CCRES","CCDIS","CCMEC","CCCOH","NC","Other"/*,"Data"*/};
    const std::vector<int> Colors3 = {8,46,2,3,4,5,6,7,9,11,12,30,15,0};

    const std::vector<std::string> KaonFinalStates = {
        "nu_mu_CC-13_311_3222",
        "nu_mu_NC-14_311_3122",
        "nu_mu_CC-13_311_3122",
        "nu_bar_mu_CC--13_311_3122",
        "nu_bar_mu_CC--13_311_3112",
        "nu_mu_CC-13_311_-311",
        "nu_bar_mu_NC--14_311_3122",

        "nu_mu_NC-14_311_3222",
        "nu_mu_NC-14_311_-311",

        "nu_mu_NC-14_311_3112",  
        "nu_bar_mu_CC--13_311_-311",   
        "nu_bar_mu_NC--14_311_3212",      
        "nu_bar_mu_NC--14_311_3222",
        "nu_mu_CC-13_311",
        "nu_bar_mu_CC--13_311",
        "" 
    };

    const std::vector<std::string> KaonFinalStatesCaptions = {
        "#nu_{#mu}CC-#mu^{-}K^{0}#Sigma^{+}X_{h}",
        "#nu_{#mu}NC-#nu_{#mu}K^{0}#Lambda X_{h}",
        "#nu_{#mu}CC-#mu^{-}K^{0}#Lambda X_{h}",
        "#bar{#nu}_{#mu}CC-#mu^{+}K^{0}#Lambda X_{h}",
        "#bar{#nu}_{#mu}CC-#mu^{+}K^{0}#Sigma^{-}X_{h}",
        "#nu_{#mu}CC-#mu^{-}K^{0}#bar{K}^{0}X_{h}",
        "#bar{#nu}_{#mu}NC-#bar{#nu}_{#mu}K^{0}#Lambda X_{h}",
        "#nu_{#mu}NC-#nu_{#mu}K^{0}#Sigma^{+}X_{h}",
        "#nu_{#mu}NC-#nu_{#mu}K^{0}#bar{K}^{0}X_{h}",
        "#nu_{#mu}NC-#nu_{#mu}K^{0}#Sigma^{-}X_{h}",
        "#nu_{#mu}NC-#nu_{#mu}K^{0}#bar{K}^{0}X_{h}",
        "#bar{#nu}_{#mu}NC-#mu^{+}K^{0}#Sigma^{0}X_{h}",
        "#bar{#nu}_{#mu}NC-#mu^{+}K^{0}#Sigma^{+}X_{h}",
        "#nu_{#mu}CC-#mu^{-}K^{0}X_{h}",
        "#bar{#nu}_{#mu}CC-#mu^{+}K^{0}X_{h}",
        "Other"
    };

    const std::vector<int> KaonFinalStatesColors = {
        596, // kGreen
        800, // kOrange
        616, // kMagenta
        432, // kCyan
        860, // kAzure +2 (lighter blue)
        900, // kPink
        820, // kSpring (greenish-yellow)
        880, // kViolet
        602, // kAzure -2 (darker blue)
        632, // kRed +1 (darker red)
        416, // kYellow +2 (darker yellow)
        807, // kOrange +2 (darker orange)
        617, // kMagenta +1 (darker magenta)
        433, // kCyan +1 (darker cyan)
        861, // kAzure +3 (even lighter blue)
        901, // kPink +1 (darker pink)
        634, // kRed
        400, // kYellow
    };

    std::string GetKaonFinalStates(const Event &e) {
        std::string neutrinoAndInteractionType;

        if (e.Neutrino.at(0).PDG == 14) neutrinoAndInteractionType = "nu_mu_";
        else if (e.Neutrino.at(0).PDG == -14) neutrinoAndInteractionType = "nu_bar_mu_";
        else return ""; 

        if (e.CCNC.at(0) == "CC" || e.CCNC.at(0) == "NC") {
            neutrinoAndInteractionType += e.CCNC.at(0) + "-";
        } else {
            return ""; 
        }

        std::vector<int> primaryParticlePDGs;
        if (!e.PrimaryKaon.empty()) { 
            for (const auto& lepton : e.Lepton) {
                primaryParticlePDGs.push_back(lepton.PDG);
            }
            for (const auto& hyperon : e.Hyperon) {
                primaryParticlePDGs.push_back(hyperon.PDG);
            }
            for (const auto& kaon : e.PrimaryKaon) {
                primaryParticlePDGs.push_back(kaon.PDG);
            }
        }

        std::sort(primaryParticlePDGs.begin(), primaryParticlePDGs.end());

        std::string finalState;
        for (int PDG : primaryParticlePDGs) {
            if (!finalState.empty()) {
                finalState += "_";
            }
            finalState += std::to_string(PDG);
        }

        std::unordered_set<std::string> dominantFinalStates = {
            "13_311_3222", "14_311_3122", "13_311_3122", "-13_311_3122", "-13_311_3112", "13_311_-311", 
            "-14_311_3122", "14_311_3222", "14_311_-311", "14_311_3112", "-13_311_-311", "-14_311_3212", "-14_311_3222",
            "13_311", "-13_311"
        };

        if (dominantFinalStates.find(finalState) != dominantFinalStates.end()) {
            return neutrinoAndInteractionType + finalState;
        }

        return ""; 
    }

    const std::vector<std::string> KaonDecayChannels = {
        "-211_211", "111_111",
        ""
    };

    const std::vector<std::string> KaonDecayCaption = {
        "#pi^{-}#pi^{+}", "#pi^{0}#pi^{0}",
        "Other"
    };

    const std::vector<int> KaonDecayColours = {
        596, 800,
        616
    };

    std::string GetNeutralKaonDecayType(const Event &e) {

        std::vector<int> neutralKaonDecayPDGs;
        if (!e.KaonDecay.empty()) {
            for (const auto& decayProduct : e.KaonDecay) {
                neutralKaonDecayPDGs.push_back(decayProduct.PDG);
            }
        }

        std::sort(neutralKaonDecayPDGs.begin(), neutralKaonDecayPDGs.end());

        std::string decayChannel;
        for (int PDG : neutralKaonDecayPDGs) {
            if (!decayChannel.empty()) {
                decayChannel += "_";
            }
            decayChannel += std::to_string(PDG);
        }

        auto it = std::find(KaonDecayChannels.begin(), KaonDecayChannels.end(), decayChannel);
        if (it != KaonDecayChannels.end()) { 
            return decayChannel;
        }

        return "";
    }
    
    std::string GetHyperonFinalStates(const Event &e) {
        bool isSigmaPlus = false;
        bool isLambda = false;
        bool isSigmaMinus = false;

        for (const auto& hyperon : e.Hyperon) {
            if (hyperon.PDG == 3222) {
                isSigmaPlus = true;
            } else if (hyperon.PDG == 3122) {
                isLambda = true;
            } else if (hyperon.PDG == 3112) {
                isSigmaMinus = true;
            }
        }

        const std::string& mode = e.Mode.at(0);
        if (isSigmaPlus) {
            return "SigmaPlus";
        } else if (isLambda) {
            return "Lambda";
        } else if (isSigmaMinus) {
            return "SigmaMinus";
        }

        if (!e.Hyperon.size()) {
            return "Kaon";
        }
        
        return "Other";
    }

    const std::vector<std::string> HyperonFinalStateProc = {"SigmaPlus", "Lambda", "SigmaMinus", "Kaon",  "Other"};
    const std::vector<std::string> HyperonFinalStateCaptions = {"K^{0} #Sigma^{+} X_{hd}", " K^{0} #Lambda X_{hd}", "K^{0} #Sigma^{-} X_{hd}", "K^{0} X_{hd}", "Other"};
    const std::vector<int> HyperonFinalStateColors = {
        596, 800,
        616,
        433, // kCyan +1 (darker cyan)
        901, // kPink +1 (darker pink)
        880,
    };

    ////////////////
    
    const std::vector<std::string> PureKaonProc = {"SignalSingle", "SignalAssociated", "Other", "NeutralCurrent"};
    const std::vector<std::string> PureKaonCaptions = {"Signal (#Delta S = 1)", "Signal (#Delta S = 0)", "Other CC", "NC"};
    const std::vector<int> PureKaonColors = {
        kGreen,
        kGreen + 1,
        30,
        15,
    };

    std::string GetPureKaonType(const Event &e){
        if(e.CCNC.at(0) == "CC"){
            if(e.EventIsSignal && e.EventIsSingleStrangeProduction){
                return "SignalSingle";
            }
            else if(e.EventIsSignal && e.EventIsAssociatedStrangeProduction){
                return "SignalAssociated";
            }
            else{
                return "Other";
            }
        }
        else{
            return "NeutralCurrent";
        }
    }

//
// Get the event category 

    std::string GetType(const Event &e){

        if(!e.Mode.size()) throw std::invalid_argument("GetType: Event has Mode.size() = 0, should be at least 1");

        if(e.Mode.at(0) == "Data") return "Data";
        else if(e.Mode.at(0) == "EXT") return "EXT";
        else if(e.Mode.at(0) == "Dirt") return "Dirt";
        else if(e.EventIsSignal) return "Signal";
        //else if(e.Mode.at(0) == "HYP") return "OtherHYP";

        return "OtherNu";
    }

///////////////////////////////////////////////////////////////////////////////////////////////

// Get the event category using different labelling convention

    std::string GetType2(const Event &e, int tr=-1){

        if(!e.Mode.size()) throw std::invalid_argument("GetType2: Event has Mode.size() = 0, should be at least 1");

        std::string type;

        if(e.Mode.at(0) == "Data") return "Data";
        else if(e.Mode.at(0) == "EXT") return "EXT";
        else if(e.Mode.at(0) == "Dirt") return "Dirt";

        bool islambdacharged = std::find(e.IsLambdaCharged.begin(), e.IsLambdaCharged.end(), true) != e.IsLambdaCharged.end();
        
        if(e.EventIsSignal) return "DirectLambda";
        else if(e.Mode.at(0) == "HYP") return "DirectHYP"; 
        else if(e.Mode.at(0) == "RES" && islambdacharged) return "RESLambda";
        else if(e.Mode.at(0) == "RES" && e.Hyperon.size()) return "RESHYP"; 
        else if(e.Mode.at(0) == "DIS" && islambdacharged) return "DISLambda";
        else if(e.Mode.at(0) == "DIS" && e.Hyperon.size()) return "DISHYP"; 
        else if(e.EventHasNeutronScatter) return "Neutron";
        else return "Other";

        return type;
    }
 
///////////////////////////////////////////////////////////////////////////////////////////////

// Get the neutrino interaction process

    std::string GetProc(const Event &e){

        if(!e.Mode.size()) throw std::invalid_argument("GetType: Event has Mode.size() = 0, should be at least 1");

        std::string mode,ccnc;

        if(e.Mode.at(0) == "Data") return "Data";
        else if(e.Mode.at(0) == "EXT") return "EXT";
        else if(e.Mode.at(0) == "Dirt") return "Dirt";
        else if(e.EventIsSignal) return "Signal";
        else if(e.Mode.at(0) == "HYP") return "OtherHYP";      

        ccnc = e.CCNC.at(0);
        mode = e.Mode.at(0); 

        if(mode == "Diffractive" || mode == "ElectronScattering") return "Other";
        else if(ccnc == "CC") return ccnc + mode;
        else return "NC";

        return "Other";
    }

///////////////////////////////////////////////////////////////////////////////////////////////

// Get the event category using different labelling convention for a specific MCTruth

    std::string GetType2ForTruth(const Event &e, int tr){

        if(!e.Mode.size()) throw std::invalid_argument("GetType2: Event has Mode.size() = 0, should be at least 1");

        if(tr > e.NMCTruths-1) 
            throw std::invalid_argument("GetType2: Trying to get type for truth " + std::to_string(tr) + " in event with " + std::to_string(e.NMCTruths));

        std::string type;

        if(e.Mode.at(tr) == "Data") return "Data";
        else if(e.Mode.at(tr) == "EXT") return "EXT";
        else if(e.Mode.at(tr) == "Dirt") return "Dirt";

        // TODO: Try changing this to only look at the MC truth being inspected
        
        bool islambdacharged = e.IsLambdaCharged.at(tr);
        
        if(e.EventIsSignal) return "DirectLambda";
        else if(e.Mode.at(tr) == "HYP") return "DirectHYP"; 
        else if(e.Mode.at(tr) == "RES" && e.IsLambdaCharged.at(tr)) return "RESLambda";
        else if(e.Mode.at(tr) == "RES" && e.IsHyperon.at(tr)) return "RESHYP"; 
        else if(e.Mode.at(tr) == "DIS" && e.IsLambdaCharged.at(tr)) return "DISLambda";
        else if(e.Mode.at(tr) == "DIS" && e.IsHyperon.at(tr)) return "DISHYP"; 
        else if(e.EventHasNeutronScatter) return "Neutron";
        else return "Other";

        return type;
    }

};	
		
#endif