#ifndef _EventType_h_
#define _EventType_h_

#include "Event.h"

namespace EventType {
	
    const std::vector<std::string> KaonProductionTypes = {
        "DIRECT", "HYPERON_DECAY_LAMBDA", "HYPERON_DECAY_SIGMA", "ASSOCIATED", "SECONDARY", "EXT", "DIRT"
    };
    const std::vector<std::string> KaonProductionCaption = {
        "Direct", "Lambda Decay", "Sigma Decay", "Associated", "Secondary", "Cosmic", "Dirt"
    };
    const std::vector<int> KaonProductionColours = {
        8, 46, 38, 30, 15, 0, 2, 3
    };

    const std::vector<std::string> NeutrinoInteractionTypes = {
        "CCQE", "NCQE", "CCRES", "NCRES", "CCDIS", "NCDIS", "CCMEC", "NCMEC", "CCCOH", "NCCOH", "NC", "EXT", "DIRT", "NEUTRON", "OTHER"
    };
    const std::vector<std::string> NeutrinoInteractionCaptions = {
        "Charged Current Quasi-Elastic", "Neutral Current Quasi-Elastic",
        "Charged Current Resonance", "Neutral Current Resonance",
        "Charged Current Deep Inelastic Scattering", "Neutral Current Deep Inelastic Scattering",
        "Charged Current Meson Exchange Current", "Neutral Current Meson Exchange Current",
        "Charged Current Coherent", "Neutral Current Coherent",
        "Neutral Current", "External", "Dirt", "Neutron Interaction", "Other"
    };
    
    const std::vector<int> NeutrinoInteractionColors = {
        kBlue, kAzure, // Colors for CCQE, NCQE
        kGreen, kSpring, // Colors for CCRES, NCRES
        kRed, kOrange, // Colors for CCDIS, NCDIS
        kMagenta, kViolet, // Colors for CCMEC, NCMEC
        kYellow, kTeal, // Colors for CCCOH, NCCOH
        kGray, // Color for NC
        kBlack, // Color for EXT
        kBrown, // Color for DIRT
        kCyan, // Color for NEUTRON
        kPink // Color for OTHER
    };

///////////////////////////////////////////////////////////////////////////////////////////////

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

////////////////
//

	std::string GetKaonType(const Event &e){
		
		std::string type;
		
		if(e.EventHasKaonShort) return "KaonSHORT";
		else if(e.EventHasKaonLong) return "KaonLONG";
		else return "Other";
	
		return type;
	}
};	
		
#endif
