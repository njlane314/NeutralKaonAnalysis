#ifndef _SelectionManager_cxx_
#define _SelectionManager_cxx_

#include "SelectionManager.h"

// Default constructor


SelectionManager::SelectionManager() : 
    a_FluxWeightCalc(0) ,
    a_GenG4WeightCalc() ,
    a_FiducialVolume(1,0.0) ,
    a_MuonID(0.9,200.0,0.0) ,
    a_TrackLengthCutManager(1000.0,1000.0) , 
    a_SelectorBDTManager("Test") ,
    a_AnalysisBDTManager("Test") ,
    a_EventListFilter() ,
    a_SecondaryVertexFitter(5) , 
    a_CTTest_Plane0(0) ,
    a_CTTest_Plane1(1) ,
    a_CTTest_Plane2(2) 
{

    std::cout << "Calling default constructor for SelectionManager" << std::endl;
    DeclareCuts();

}

// Destructor

SelectionManager::~SelectionManager(){}

// Constructor that loads selection parameters

SelectionManager::SelectionManager(SelectionParameters p) :
    a_FluxWeightCalc(p.p_BeamMode) ,
    a_GenG4WeightCalc() ,
    a_FiducialVolume(p.p_FV,p.p_Padding) ,
    a_MuonID(p.p_PID_Cut,p.p_Minimum_MIP_Length,p.p_Max_Displacement) ,
    a_TrackLengthCutManager(p.p_SecondaryTrackLengthCut,p.p_SecondaryTrackLengthCut) ,
    a_SelectorBDTManager("Test") , 
    a_AnalysisBDTManager("Test") ,
    a_EventListFilter() ,
    a_SecondaryVertexFitter(p.p_VertexPull) , 
    a_CTTest_Plane0(0) ,
    a_CTTest_Plane1(1) ,
    a_CTTest_Plane2(2) 
{

    std::cout << "Building SelectionManager" << std::endl;

    if(!p.HasBeenSetup)
        throw std::invalid_argument("SelectionManager: Selection parameters " + p.Name + " have not been loaded. Run BuildTunes() first");

    // Set the selection parameters
    TheParams = p;
    DeclareCuts();
    a_SelectorBDTManager.SetCuts(-0.1,5);
    a_AnalysisBDTManager.SetPull(p.p_VertexPull);

}

void SelectionManager::TuneMuonID(double PIDCut,double MinLength,double MaxSeparation){
    a_MuonID.SetTune(PIDCut, MinLength, MaxSeparation);

    a_MuonID.Print();
}

// Close selection manager

void SelectionManager::Close(){

    if(f_Hists != nullptr) f_Hists->Close();

}

// Set the beam being used

void SelectionManager::SetBeamMode(int mode){

    assert(mode == kFHC || mode == kRHC || mode == kBNB);

    BeamMode = mode;

}

// Return the selection parameters loaded

SelectionParameters SelectionManager::GetParams(){

    return TheParams;

}

double SelectionManager::GetSelectorBDTScore(RecoParticle DecayProtonCandidate,RecoParticle DecayPionCandidate){
    return a_SelectorBDTManager.GetScore(DecayProtonCandidate, DecayPionCandidate);
}

// Load a sample of events, specify name, type and POT. Can also load list of selected events
// if using the event list cut

void SelectionManager::AddSample(std::string Name, std::string Type, double SamplePOT, std::string EventList){

    std::cout << "Processing Sample " << Name << " of type " << Type << " and POT " << SamplePOT <<  std::endl;

    if(Type != "Data") thisSampleWeight = POT/SamplePOT;
    else thisSampleWeight = 1.0;

    thisSampleName = Name;
    thisSampleType = Type;

    if(thisSampleType != "Data" && thisSampleType != "EXT"){
        if (thisSampleName.find("GENIE") != std::string::npos) thisSampleGenerator = kGENIE;
        else if (thisSampleName.find("NuWro") != std::string::npos) thisSampleGenerator = kNuWro;      
        else thisSampleGenerator = -1;
    }

    if(Type == "Data") fHasData = true;

    TString DataDir = getenv("DATA_DIR");         

    TString file = DataDir + TString("/EventLists/") +  TString(EventList);  

    if(EventList != ""){
        std::cout << "Adding event list " << EventList << std::endl;
        a_EventListFilter.SetList(file); 
    }

}


// Load an event, normalise its weight using the POT of the current sample

void SelectionManager::AddEvent(Event &e){

    // Sample Orthogonality
    //if(thisSampleType == "Neutron" && !e.EventHasNeutronScatter){ e.Weight = 0.0; return; }
    //if(thisSampleType != "Neutron" && e.EventHasNeutronScatter){ e.Weight = 0.0; return; }
    /*if(thisSampleType != "Hyperon" &&  e.EventHasHyperon){ e.Weight = 0.0; return; }
    if(thisSampleType == "Hyperon" &&  !e.EventHasHyperon){ e.Weight = 0.0; return; }*/
    if(thisSampleType == "Kaon" && !e.EventHasK0S){ e.Weight = 0.0; return; }
    if(thisSampleType != "Kaon" && e.EventHasK0S){ e.Weight = 0.0; return; }

    // Set flux weight if setup
    if(thisSampleType != "Data" && thisSampleType != "EXT"){
        if(fUseFluxWeight) e.Weight *= a_FluxWeightCalc.GetFluxWeight(e);        
        if(fUseGenWeight) {
            a_GenG4WeightCalc.LoadEvent(e);
            e.Weight *= a_GenG4WeightCalc.GetCVWeight();
        }
    }

    if(thisSampleType != "Data") e.Weight *= thisSampleWeight;

    for(size_t i_c=0;i_c<Cuts.size();i_c++){
        Cuts[i_c].fTotalEvents += e.Weight;    
        if(e.EventIsSignal) Cuts[i_c].fSignalEvents += e.Weight;
        if(e.GoodReco) Cuts[i_c].fGoodRecoEvents += e.Weight;

        Cuts[i_c].fTotalEventsVar += e.Weight*e.Weight;    
        if(e.EventIsSignal) Cuts[i_c].fSignalEventsVar += e.Weight*e.Weight;
        if(e.GoodReco) Cuts[i_c].fGoodRecoEventsVar += e.Weight*e.Weight;
    }

}

void SelectionManager::UseFluxWeight(bool usefluxweight){

    fUseFluxWeight = usefluxweight;

}

void SelectionManager::UseGenWeight(bool usegenweight){

    fUseGenWeight = usegenweight;

} 

// Apply the signal definition

void SelectionManager::SetSignal(Event &e){
    e.GoodReco = false;
    e.EventIsSignal = false;
    e.EventInFV = false;

    if(e.Neutrino.empty()) return;

    int abs_nu_pdg = std::abs(e.Neutrino.at(0).PDG);
    bool is_nu = (abs_nu_pdg == 12 || abs_nu_pdg == 14);
    if(!is_nu) return;

    e.EventInFV = a_FiducialVolume.InFiducialVolume(e.TruePrimaryVertex.at(0));
    bool nu_is_numu = (abs_nu_pdg == 14); 
    std::string ccnc = e.CCNC.at(0);

    if(!e.EventInFV) return;
    if(ccnc != "CC") return;
    if(!nu_is_numu) return;

    bool muon_in_mom_range = false;
    bool has_fs_hyperons = false;
    bool has_charged_pi_pair_above_threshold = false;

    for(const auto lepton : e.Lepton){
        if(lepton.PDG == 13){
            if(lepton.ModMomentum >= 0.1){
                muon_in_mom_range = true;
            }
        }
    }

    has_fs_hyperons = !e.Hyperon.empty();

    for(size_t i_tr = 0; i_tr < e.NMCTruths; i_tr++){
        bool found_pion_plus = false;
        bool found_pion_minus = false;

        e.InActiveTPC.at(i_tr) = a_FiducialVolume.InFiducialVolume(e.TruePrimaryVertex.at(i_tr)); 
        if(!e.InActiveTPC.at(i_tr)) continue;
        
        if(e.IsK0SCharged.at(i_tr)){
            for(size_t i_d = 0; i_d < e.KaonDecay.size(); i_d++){
                int parent_index = e.KaonDecay.at(i_d).MCTruthIndex;
                int decay_pdg = e.KaonDecay.at(i_d).PDG;
                double decay_momentum = e.KaonDecay.at(i_d).ModMomentum;
                //TVector3 decay_start(e.KaonDecay.at(i_d).StartX, e.KaonDecay.at(i_d).StartY, e.KaonDecay.at(i_d).StartZ);
                //double decay_displacement = (e.TruePrimaryVertex.at(0) - decay_start).Mag();

                if(parent_index == i_tr && decay_momentum > 0.1){
                    if(decay_pdg == +211){
                        found_pion_plus = true;
                    }
                    else if(decay_pdg == -211){
                        found_pion_minus = true;
                    }
                }
            }   
        }

        if(found_pion_minus && found_pion_plus){
            has_charged_pi_pair_above_threshold = true;
        }
    }

    if(muon_in_mom_range && has_charged_pi_pair_above_threshold){
            e.EventIsSignal = true;
            e.EventIsAssociatedProduction = has_fs_hyperons;
            e.EventIsSingleProduction = !has_fs_hyperons;
    }
    
    
    if(!e.EventIsSignal) return; 
    
	bool found_pion_plus = false;
	bool found_pion_minus = false;

    std::vector<RecoParticle> PionPlusCandidatesVector;
    std::vector<RecoParticle> PionMinusCandidatesVector;
	for(size_t i_tr = 0; i_tr < e.TracklikePrimaryDaughters.size(); i_tr++){
        bool has_truth = e.TracklikePrimaryDaughters.at(i_tr).HasTruth;
        int track_pdg = e.TracklikePrimaryDaughters.at(i_tr).TrackTruePDG;
        int track_origin = e.TracklikePrimaryDaughters.at(i_tr).TrackTrueOrigin;
        double track_momentum = e.TracklikePrimaryDaughters.at(i_tr).TrackTrueModMomentum;
        double track_displacement = e.TracklikePrimaryDaughters.at(i_tr).Displacement;
        if(has_truth && track_origin == 7 && track_momentum > 0.1){
            if(track_pdg == +211) {
                found_pion_plus = true;
                PionPlusCandidatesVector.push_back(e.TracklikePrimaryDaughters.at(i_tr));
            }
            else if(track_pdg == -211){
                found_pion_minus = true;
                PionMinusCandidatesVector.push_back(e.TracklikePrimaryDaughters.at(i_tr));
            }
        }
    }

    if(found_pion_plus && found_pion_minus) {
        std::sort(PionPlusCandidatesVector.begin(), PionPlusCandidatesVector.end(), [](const RecoParticle& a, const RecoParticle& b) {
            return a.Displacement < b.Displacement; 
        });
        std::sort(PionMinusCandidatesVector.begin(), PionMinusCandidatesVector.end(), [](const RecoParticle& a, const RecoParticle& b){ 
            return a.Displacement < b.Displacement; 
        });

        double min_diff = std::numeric_limits<double>::max();
        std::pair<RecoParticle, RecoParticle> closest_pair;

        for (const auto& pion_plus : PionPlusCandidatesVector) {
            for (const auto& pion_minus : PionMinusCandidatesVector) {
                double diff = std::abs(pion_plus.Displacement - pion_minus.Displacement);
                if (diff < min_diff) {
                    min_diff = diff;
                    closest_pair = {pion_plus, pion_minus};
                }
            }
        }

        e.TrueDecayPionPlusIndex = closest_pair.first.Index;
        e.TrueDecayPionMinusIndex = closest_pair.second.Index;
    }

   	e.GoodReco = e.EventIsSignal && found_pion_plus && found_pion_minus;
}

/*void SelectionManager::SetSignal(Event &e){

    e.GoodReco = false;

    if(e.CCNC.at(0) == "CC"){
        bool found_muon = false;

        for(size_t i_l = 0; i_l < e.Lepton.size(); i_l++){
            int parent_index = e.Lepton.at(i_l).MCTruthIndex;
            if(!a_FiducialVolume.InFiducialVolume(e.TruePrimaryVertex.at(parent_index))) continue;

            int lepton_pdg = abs(e.Lepton.at(i_l).PDG);
            double lepton_momentum = e.Lepton.at(i_l).ModMomentum;

            if(parent_index == 0 && lepton_pdg == 13 && lepton_momentum > 0.1){
                found_muon = true;
            }
        }      

        if(!found_muon) return;

        bool found_pion_plus = false;
        bool found_pion_minus = false;

        for(size_t i_tr = 0; i_tr < e.NMCTruths; i_tr++){
            e.InActiveTPC.at(i_tr) = a_FiducialVolume.InFiducialVolume(e.TruePrimaryVertex.at(i_tr)); 
            if(!e.InActiveTPC.at(i_tr)) continue;

            if(e.IsK0SCharged.at(i_tr)){
                for(size_t i_d = 0; i_d < e.KaonDecay.size(); i_d++){
                    int parent_index = e.KaonDecay.at(i_d).MCTruthIndex;
                    int decay_pdg = e.KaonDecay.at(i_d).PDG;
                    double decay_momentum = e.KaonDecay.at(i_d).ModMomentum;
                    TVector3 decay_start(e.KaonDecay.at(i_d).StartX, e.KaonDecay.at(i_d).StartY, e.KaonDecay.at(i_d).StartZ);
                    double decay_displacement = (e.TruePrimaryVertex.at(0) - decay_start).Mag();

                    if(parent_index == i_tr && decay_momentum > 0.1 && decay_displacement > 1){
                        if(decay_pdg == +211){
                            found_pion_plus = true;
                        }
                        else if(decay_pdg == -211){
                            found_pion_minus = true;
                        }
                    }

                }   
            }
        }

        if(found_pion_minus && found_pion_plus){
            e.EventIsSignal = true;
            e.EventIsAssociatedStrangeProduction = !e.Hyperon.empty();
            e.EventIsSingleStrangeProduction = e.Hyperon.empty();
        }
    }

    if(!e.EventIsSignal) return; 

    
	bool found_pion_plus = false;
	bool found_pion_minus = false;

    std::vector<RecoParticle> PionPlusCandidatesVector;
    std::vector<RecoParticle> PionMinusCandidatesVector;
	for(size_t i_tr = 0; i_tr < e.TracklikePrimaryDaughters.size(); i_tr++){
        bool has_truth = e.TracklikePrimaryDaughters.at(i_tr).HasTruth;
        int track_pdg = e.TracklikePrimaryDaughters.at(i_tr).TrackTruePDG;
        int track_origin = e.TracklikePrimaryDaughters.at(i_tr).TrackTrueOrigin;
        double track_momentum = e.TracklikePrimaryDaughters.at(i_tr).TrackTrueModMomentum;
        double track_displacement = e.TracklikePrimaryDaughters.at(i_tr).Displacement;
        if(has_truth && track_origin == 7 && track_momentum > 0.1 && track_momentum < 0.3 && track_displacement > 1){
            if(track_pdg == +211) {
                found_pion_plus = true;
                PionPlusCandidatesVector.push_back(e.TracklikePrimaryDaughters.at(i_tr));
            }
            else if(track_pdg == -211){
                found_pion_minus = true;
                PionMinusCandidatesVector.push_back(e.TracklikePrimaryDaughters.at(i_tr));
            }
        }
  	}

    if(found_pion_plus && found_pion_minus) {
        std::sort(PionPlusCandidatesVector.begin(), PionPlusCandidatesVector.end(), [](const RecoParticle& a, const RecoParticle& b) {
            return a.Displacement < b.Displacement; 
        });
        std::sort(PionMinusCandidatesVector.begin(), PionMinusCandidatesVector.end(), [](const RecoParticle& a, const RecoParticle& b){ 
            return a.Displacement < b.Displacement; 
        });

        double min_diff = std::numeric_limits<double>::max();
        std::pair<RecoParticle, RecoParticle> closest_pair;

        for (const auto& pion_plus : PionPlusCandidatesVector) {
            for (const auto& pion_minus : PionMinusCandidatesVector) {
                double diff = std::abs(pion_plus.Displacement - pion_minus.Displacement);
                if (diff < min_diff) {
                    min_diff = diff;
                    closest_pair = {pion_plus, pion_minus};
                }
            }
        }

        e.TrueDecayPionPlusIndex = closest_pair.first.Index;
        e.TrueDecayPionMinusIndex = closest_pair.second.Index;
    }

   	e.GoodReco = e.EventIsSignal && found_pion_plus && found_pion_minus;
}*/

// Load the list of cuts

void SelectionManager::DeclareCuts(){

    for(size_t i_c = 0;i_c < CutTypes.size(); i_c++){
        Cut c;
        c.fName = CutTypes.at(i_c);
        Cuts.push_back(c);
    }

}

// Add an event to a cut

void SelectionManager::UpdateCut(const Event &e, bool Passed, std::string CutName){

    for(size_t i_c = 0; i_c < Cuts.size(); i_c++){

        if(Cuts.at(i_c).fName == CutName){
            Cuts[i_c].fEventsIn += e.Weight;
            if(e.EventIsSignal) Cuts[i_c].fSignalEventsIn += e.Weight;
            if(e.GoodReco) Cuts[i_c].fGoodRecoEventsIn += e.Weight;

            Cuts[i_c].fEventsInVar += e.Weight*e.Weight;
            if(e.EventIsSignal) Cuts[i_c].fSignalEventsInVar += e.Weight*e.Weight;
            if(e.GoodReco) Cuts[i_c].fGoodRecoEventsInVar += e.Weight*e.Weight;

            if(Passed){

                Cuts[i_c].fEventsOut += e.Weight;
                if(e.EventIsSignal) Cuts[i_c].fSignalEventsOut += e.Weight;
                if(e.GoodReco) Cuts[i_c].fGoodRecoEventsOut += e.Weight;

                Cuts[i_c].fEventsOutVar += e.Weight*e.Weight;
                if(e.EventIsSignal) Cuts[i_c].fSignalEventsOutVar += e.Weight*e.Weight;
                if(e.GoodReco) Cuts[i_c].fGoodRecoEventsOutVar += e.Weight*e.Weight;
            }       
        }
    }

}

// Retrieve the results from a cut

Cut SelectionManager::GetCut(std::string CutName){

   for(size_t i_c = 0; i_c < Cuts.size(); i_c++)
      if(Cuts.at(i_c).fName == CutName) return Cuts.at(i_c);

   std::cout << "Cut " << CutName << " not found" << std::endl;

   Cut c;
   return c;

}

// Reset the data in the cuts

void SelectionManager::Reset(){

   for(size_t i_c = 0; i_c < Cuts.size(); i_c++) Cuts[i_c].Reset();  

}

// Load the track selector BDT weights

void SelectionManager::ImportSelectorBDTWeights(std::string WeightDir){

    std::cout << "SelectionManager: Importing Selector BDT Weights from " << WeightDir << std::endl;
    a_SelectorBDTManager.SetupSelectorBDT(WeightDir);
        
}

// Load the analysis BDT weights

void SelectionManager::ImportAnalysisBDTWeights(std::string WeightDir){

    std::cout << "SelectionManager: Importing Analysis BDT Weights from " << WeightDir << std::endl;
    a_AnalysisBDTManager.SetupAnalysisBDT(WeightDir);

}

// Apply the fiducial volume cut

bool SelectionManager::FiducialVolumeCut(const Event &e){

    bool passed = a_FiducialVolume.InFiducialVolume(e.RecoPrimaryVertex);

    UpdateCut(e,passed,"FV");

    return passed;

}

// Apply the three track cut

bool SelectionManager::TrackCut(const Event &e){

    bool passed = e.NPrimaryTrackDaughters >= 3; 

    UpdateCut(e,passed,"Tracks");

    return passed;

}

// Apply the zero shower cut

bool SelectionManager::ShowerCut(const Event &e){

    bool passed = e.NPrimaryShowerDaughters >= 0; 

    UpdateCut(e,passed,"Showers");

    return passed;

}

// Select the muon candidate

bool SelectionManager::ChooseMuonCandidate(Event &e){

    int i_muon = a_MuonID.SelectCandidate(e.TracklikePrimaryDaughters);

    if(i_muon == -1){
        UpdateCut(e,false,"MuonID");
        return false;
    }

    RecoParticle theMuonCandidate = e.TracklikePrimaryDaughters.at(i_muon);
    e.MuonCandidate = theMuonCandidate;
    e.TracklikePrimaryDaughters.erase(e.TracklikePrimaryDaughters.begin()+i_muon);

    UpdateCut(e,true,"MuonID");

    return true;

}

// Apply the secondary track length cut

bool SelectionManager::TrackLengthCut(const Event &e){

    bool passed = a_TrackLengthCutManager.ApplyCut(e.TracklikePrimaryDaughters);

    UpdateCut(e,passed,"SubleadingTracks");

    return passed;

}


// Select pion pair tracks. If cheat is selected uses truth information instead of BDT 

bool SelectionManager::ChoosePionPairCandidates(Event &e, bool cheat){

    std::pair<int,int> candidates; // <pion_plus_index, pion_minus_index>

    if(cheat) candidates = a_SelectorBDTManager.NominateTracksCheat(e);
    else candidates = a_SelectorBDTManager.NominateTracks(e);

    bool passed = candidates.first != -1 && candidates.second != -1;
    
    if(!passed){
        UpdateCut(e, passed, "DecaySelector");
        return false;
    }

    for (size_t i_tr=0; i_tr<e.TracklikePrimaryDaughters.size(); i_tr++){
        if (candidates.first == e.TracklikePrimaryDaughters.at(i_tr).Index) {
            e.DecayPionPlusCandidate = e.TracklikePrimaryDaughters.at(i_tr);
        }
        else if (candidates.second == e.TracklikePrimaryDaughters.at(i_tr).Index) {
            e.DecayPionMinusCandidate = e.TracklikePrimaryDaughters.at(i_tr);
        }
    }

    // Erase from track vector
    std::vector<RecoParticle> TracklikePrimaryDaughters_tmp;

    for(size_t i_tr=0; i_tr<e.TracklikePrimaryDaughters.size(); i_tr++) {
        if (candidates.first == e.TracklikePrimaryDaughters.at(i_tr).Index) {
            TracklikePrimaryDaughters_tmp.push_back(e.TracklikePrimaryDaughters.at(i_tr));
        }
        else if (candidates.second == e.TracklikePrimaryDaughters.at(i_tr).Index) {
            TracklikePrimaryDaughters_tmp.push_back(e.TracklikePrimaryDaughters.at(i_tr));
        }
    }

    e.TracklikePrimaryDaughters = TracklikePrimaryDaughters_tmp;

    UpdateCut(e,passed,"DecaySelector");

    return true;

}

bool SelectionManager::PionPairSelector(const Event &e){
            
    double track_LLR_PID = e.DecayPionPlusCandidate.Track_LLR_PID+e.DecayPionMinusCandidate.Track_LLR_PID;   
    double track_shower_score = e.DecayPionPlusCandidate.TrackShowerScore+e.DecayPionMinusCandidate.TrackShowerScore;  
    double separation = abs(e.DecayPionMinusCandidate.Displacement-e.DecayPionPlusCandidate.Displacement);

    bool passed = track_LLR_PID > -0.1 && track_shower_score > 1.4 && separation < 6;

    UpdateCut(e,passed,"PionPairSelector");

    return passed;
}

// Calculate decay analysis BDT score and apply cut

bool SelectionManager::AnalysisBDTCut(Event &e){

    bool passed = a_AnalysisBDTManager.CalculateScore(e) > TheParams.p_AnalysisBDT_Cut; 

    UpdateCut(e,passed,"DecayAnalysis");

    return passed;

}

// Select events in the list already loaded

bool SelectionManager::EventListCut(const Event &e){

    bool passed = a_EventListFilter.EventPassed(e.run, e.subrun, e.event); 

    UpdateCut(e, passed, "Connectedness");

    return passed;

}

// Apply the connectedness test


bool SelectionManager::ConnectednessTest(const Event &e, int nplanes){

    int muon_index = e.MuonCandidate.Index;
    int pion_plus_index = e.DecayPionPlusCandidate.Index;
    int pion_minus_index = e.DecayPionMinusCandidate.Index;

    a_CTTest_Plane0.LoadInfo(e.ConnSeedIndexes_Plane0, e.ConnOutputIndexes_Plane0, e.ConnOutputSizes_Plane0, e.ConnSeedChannels_Plane0);
    a_CTTest_Plane1.LoadInfo(e.ConnSeedIndexes_Plane1, e.ConnOutputIndexes_Plane1, e.ConnOutputSizes_Plane1, e.ConnSeedChannels_Plane1);
    a_CTTest_Plane2.LoadInfo(e.ConnSeedIndexes_Plane2, e.ConnOutputIndexes_Plane2, e.ConnOutputSizes_Plane2, e.ConnSeedChannels_Plane2);

    int npassed = 0;
    if(a_CTTest_Plane0.DoTest(muon_index, pion_plus_index, pion_minus_index)) npassed++;
    if(a_CTTest_Plane1.DoTest(muon_index, pion_plus_index, pion_minus_index)) npassed++;
    if(a_CTTest_Plane2.DoTest(muon_index, pion_plus_index, pion_minus_index)) npassed++;

    bool passed = npassed >= nplanes; 

    UpdateCut(e,passed,"Connectedness");

    return passed;

}


// Apply the invariant mass cut

bool SelectionManager::WCut(const Event &e){

    double W = PionPairInvariantMass(e.DecayPionPlusCandidate, e.DecayPionMinusCandidate); 
    bool passed = W > TheParams.p_W_Min && W < TheParams.p_W_Max;

    UpdateCut(e,passed,"InvariantMass");

    return passed;

}


// Apply the angle cut

bool SelectionManager::AngleCut(const Event &e){

    SecondaryVertex V = a_SecondaryVertexFitter.MakeVertex(e.DecayPionPlusCandidate, e.DecayPionMinusCandidate);

    TVector3 GapVector = V.Vertex - e.RecoPrimaryVertex;
    double Reco_DecayLength = (V.Vertex - e.RecoPrimaryVertex).Mag();

    TLorentzVector NeutralKaon4Momentum = PionPair4Momentum(e.DecayPionPlusCandidate, e.DecayPionMinusCandidate);

    TVector3 NeutralKaonDirection(NeutralKaon4Momentum.X(), NeutralKaon4Momentum.Y(), NeutralKaon4Momentum.Z());
    double alpha = (180/3.1415) * NeutralKaonDirection.Angle(GapVector);

    bool passed = alpha < TheParams.p_Alpha_Cut;

    UpdateCut(e, passed, "AlphaAngle");
    
    return passed;
}

// Setup histograms, vector with bin boundaries and string containing axis titles (same format
// as Root TH1 titles).

void SelectionManager::SetupHistograms(std::vector<double> boundaries, std::string title){

    if(boundaries.size() < 2)
        throw std::invalid_argument("Require at least 2 bin boundaries"); 

    fTitle = title;
    fHistNBins = boundaries.size()-1;
    fHistLow = boundaries.front();
    fHistHigh = boundaries.back();
    fHistBoundaries = boundaries;

    const int arr_n = boundaries.size();
    Double_t arr_boundaries[arr_n];
    for(size_t i=0;i<arr_n;i++) arr_boundaries[i] = boundaries.at(i);

    for(size_t i_type = 0; i_type < EventType::PureKaonSampleTypes.size(); i_type++){
        std::string histname = "h_PureKaon" + EventType::PureKaonSampleTypes.at(i_type);
        Hists_ByPureKaonTypes[EventType::PureKaonSampleTypes.at(i_type)] = new TH1D(histname.c_str(), fTitle.c_str(), fHistNBins, arr_boundaries);
    }

    for(size_t i_type = 0; i_type < EventType::BackgroundTypes.size(); i_type++){
        std::string histname = "h_Background" + EventType::BackgroundTypes.at(i_type);
        Hists_ByBackgroundTypes[EventType::BackgroundTypes.at(i_type)] = new TH1D(histname.c_str(), fTitle.c_str(), fHistNBins, arr_boundaries);
    }

    Hist_All = new TH1D("All", fTitle.c_str(), fHistNBins, arr_boundaries);
    Hist_Data = new TH1D("Data", fTitle.c_str(), fHistNBins, arr_boundaries);
}

// Setup histograms. Give bin boundaries and number of bins. String containing axis titles 
// (same format as Root TH1 titles).

void SelectionManager::SetupHistograms(int n, double low, double high, std::string title){

   fTitle = title;

   fHistNBins = n;
   fHistLow = low;
   fHistHigh = high;

    for(size_t i_type = 0; i_type < EventType::PureKaonSampleTypes.size(); i_type++){
        std::string histname = "h_PureKaon" + EventType::PureKaonSampleTypes.at(i_type);
        Hists_ByPureKaonTypes[EventType::PureKaonSampleTypes.at(i_type)] = new TH1D(histname.c_str(), fTitle.c_str(), n, low, high);
    }

   for(size_t i_type = 0; i_type < EventType::BackgroundTypes.size(); i_type++){
        std::string histname = "h_Background" + EventType::BackgroundTypes.at(i_type);
        Hists_ByBackgroundTypes[EventType::BackgroundTypes.at(i_type)] = new TH1D(histname.c_str(), fTitle.c_str(), n, low, high);
   }

   Hist_All = new TH1D("All", fTitle.c_str(), n, low, high);
   Hist_Data = new TH1D("Data", fTitle.c_str(), n, low, high);

   double width = (high-low)/n;
   for(int i = 0; i < n+1; i++) fHistBoundaries.push_back(low + (width * i)); 
}

// Setup histograms for a systematic. Give the type (multisim, single unisim or dual unisim),
// the number of universes and name

void SelectionManager::AddSystematic(int systype, int universes, std::string name){

    /*std::cout << "Setting up systematic " << name << " with " << universes << " universes" << std::endl;

    const int arr_n = fHistBoundaries.size();
    Double_t arr_boundaries[arr_n];
    for(size_t i = 0; i < arr_n; i++) arr_boundaries[i] = fHistBoundaries.at(i);

    if(systype == kMultisim){
        for(size_t i_type = 0; i_type < EventType::Types.size(); i_type++){
            Multisim_Sys_Hists[EventType::Types.at(i_type)][name].resize(universes);
            
            for(size_t i = 0; i < universes; i++) {
                Multisim_Sys_Hists[EventType::Types.at(i_type)][name].at(i) = new TH1D(("h_" + EventType::Types.at(i_type) + "_" + name + "_u_" + std::to_string(i)).c_str(), fTitle.c_str(), fHistNBins,arr_boundaries);
            }
        }
        
        for(size_t i_type = 0; i_type < EventType::Types2.size(); i_type++){
            if(std::find(EventType::Types.begin(), EventType::Types.end(), EventType::Types2.at(i_type)) != EventType::Types.end()) continue;
            Multisim_Sys_Hists[EventType::Types2.at(i_type)][name].resize(universes);
            
            for(size_t i = 0; i < universes; i++) {
                Multisim_Sys_Hists[EventType::Types2.at(i_type)][name].at(i) = new TH1D(("h_" + EventType::Types2.at(i_type) + "_" + name + "_u_" + std::to_string(i)).c_str(), fTitle.c_str(), fHistNBins, arr_boundaries);
            }
        }

        Multisim_Sys_Hists_All[name].resize(universes);
        
        for(size_t i=0;i<universes;i++) {
            Multisim_Sys_Hists_All[name].at(i) = new TH1D(("h_All_" + name + "_u_" + std::to_string(i)).c_str(), fTitle.c_str(), fHistNBins, arr_boundaries);
        }
   }    
   else if(systype == kSingleUnisim){
        for(size_t i_type = 0; i_type < EventType::Types.size(); i_type++){

            SingleUnisim_Sys_Hists[EventType::Types.at(i_type)][name].resize(1);

            for(size_t i = 0; i < 1; i++) {
                SingleUnisim_Sys_Hists[EventType::Types.at(i_type)][name][i] = new TH1D(("h_" + EventType::Types.at(i_type) + "_" + name + "_u_" + std::to_string(i)).c_str(), fTitle.c_str(), fHistNBins, arr_boundaries);
            }
        }

        for(size_t i_type = 0; i_type < EventType::Types2.size(); i_type++){
            if(std::find(EventType::Types.begin(), EventType::Types.end(), EventType::Types2.at(i_type)) != EventType::Types.end()) continue;
            
            SingleUnisim_Sys_Hists[EventType::Types2.at(i_type)][name].resize(1);
            
            for(size_t i = 0; i < 1; i++) {
                SingleUnisim_Sys_Hists[EventType::Types2.at(i_type)][name][i] = new TH1D(("h_" + EventType::Types2.at(i_type) + "_" + name + "_u_" + std::to_string(i)).c_str(), fTitle.c_str(), fHistNBins, arr_boundaries);
            }
        }
      
        SingleUnisim_Sys_Hists_All[name].resize(1);

        for(size_t i = 0; i < 1; i++) {
            SingleUnisim_Sys_Hists_All[name].at(i) = new TH1D(("h_All_" + name + "_u_" + std::to_string(i)).c_str(), fTitle.c_str(), fHistNBins, arr_boundaries);
        }
    }
    else if(systype == kDualUnisim){
        for(size_t i_type=0;i_type<EventType::Types.size();i_type++){
            DualUnisim_Sys_Hists[EventType::Types.at(i_type)][name].resize(2);
        
            for(size_t i=0;i<2;i++) {
                DualUnisim_Sys_Hists[EventType::Types.at(i_type)][name].at(i) = new TH1D(("h_" + EventType::Types.at(i_type) + "_" + name + "_u_" + std::to_string(i)).c_str(), fTitle.c_str(), fHistNBins, arr_boundaries);
            }
        }
        
        for(size_t i_type = 0; i_type < EventType::Types2.size(); i_type++){
            if(std::find(EventType::Types.begin(), EventType::Types.end(), EventType::Types2.at(i_type)) != EventType::Types.end()) continue;
            
            DualUnisim_Sys_Hists[EventType::Types2.at(i_type)][name].resize(2);
            
            for(size_t i = 0; i < 2; i++) { 
                DualUnisim_Sys_Hists[EventType::Types2.at(i_type)][name].at(i) = new TH1D(("h_" + EventType::Types2.at(i_type) + "_" + name + "_u_" + std::to_string(i)).c_str(), fTitle.c_str(), fHistNBins, arr_boundaries);
            }
        }

        DualUnisim_Sys_Hists_All[name].resize(2);
        
        for(size_t i = 0; i < 2; i++) {
            DualUnisim_Sys_Hists_All[name].at(i) = new TH1D(("h_All_" + name + "_u_" + std::to_string(i)).c_str(), fTitle.c_str(), fHistNBins, arr_boundaries);
        }
    }*/

}

// Fill the histograms

void SelectionManager::FillHistograms(const Event &e, double variable, double weight){
    std::string purekaonsampletype;
    std::string backgroundtype;

    purekaonsampletype = EventType::GetPureKaonType(e);
    backgroundtype = EventType::GetBackgroundType(e);

    Hist_All->Fill(variable, weight*e.Weight);
    Hists_ByPureKaonTypes[purekaonsampletype]->Fill(variable, weight*e.Weight);
    Hists_ByBackgroundTypes[backgroundtype]->Fill(variable, weight*e.Weight);

    /*if(mode != "Data"){
        Hist_All->Fill(variable, weight*e.Weight);
        Hists_ByPureKaonTypes[purekaonsampletype]->Fill(variable, weight*e.Weight);
    }
    else Hist_Data->Fill(variable, weight*e.Weight);*/
}

// Fill systematics histogram for a single universe with a single weight

void SelectionManager::FillHistogramsSys(const Event &e, double variable, std::string name, int universe, double weight){

    /*if(e.Mode.at(0) == "Data") return;

    if(std::isnan(e.Weight) || std::isnan(weight) || std::isinf(e.Weight) || std::isinf(weight)){
        //std::cout << "Nan weight detected for dial " << name << "  event " << e.run << " " << e.subrun << " " << e.event << " skipping" << std::endl;
        return;
    }

    std::string mode = EventType::GetType(e);
    std::string mode2 = EventType::GetType2(e);
    bool fill2 = std::find(EventType::Types.begin(), EventType::Types.end(),mode2) == EventType::Types.end();

    if (Multisim_Sys_Hists[mode].find(name) != Multisim_Sys_Hists[mode].end()){
        Multisim_Sys_Hists[mode][name].at(universe)->Fill(variable,weight*e.Weight);

        if(fill2) Multisim_Sys_Hists[mode2][name].at(universe)->Fill(variable,weight*e.Weight);

        Multisim_Sys_Hists_All[name].at(universe)->Fill(variable,weight*e.Weight);

        return;
    }
    else if (SingleUnisim_Sys_Hists[mode].find(name) != SingleUnisim_Sys_Hists[mode].end()){
        SingleUnisim_Sys_Hists[mode][name].at(universe)->Fill(variable,weight*e.Weight);

        if(fill2) SingleUnisim_Sys_Hists[mode2][name].at(universe)->Fill(variable,weight*e.Weight);

        SingleUnisim_Sys_Hists_All[name].at(universe)->Fill(variable,weight*e.Weight);

        return;
    }
    else if (DualUnisim_Sys_Hists[mode].find(name) != DualUnisim_Sys_Hists[mode].end()){
        DualUnisim_Sys_Hists[mode][name].at(universe)->Fill(variable,weight*e.Weight);

        if(fill2) DualUnisim_Sys_Hists[mode2][name].at(universe)->Fill(variable,weight*e.Weight);

        DualUnisim_Sys_Hists_All[name].at(universe)->Fill(variable,weight*e.Weight);

        return;
    }*/

}

// Fill systematics histogram for all universes. Supply vector containing weights for different
// universes

void SelectionManager::FillHistogramsSys(const Event &e, double variable, std::string name, std::vector<double> weights){

    /*for(size_t i = 0; i < weights.size(); i++) {
        FillHistogramsSys(e, variable, name, i, weights.at(i)); 
    }*/
}

// Draw the histograms

void SelectionManager::DrawHistograms(std::string label, double Scale, double SignalScale){

    OpenHistFile(label);

    system(("mkdir -p " + PlotDir).c_str());

    // Create weight sums
    for(size_t i_type = 0; i_type < EventType::PureKaonSampleTypes.size(); i_type++){
        Hists_ByPureKaonTypes[EventType::PureKaonSampleTypes.at(i_type)]->Scale(Scale);
        Hists_ByPureKaonTypes[EventType::PureKaonSampleTypes.at(i_type)]->Sumw2();
    }

    for(size_t i_type = 0; i_type < EventType::BackgroundTypes.size(); i_type++){
        Hists_ByBackgroundTypes[EventType::BackgroundTypes.at(i_type)]->Scale(Scale);
        Hists_ByBackgroundTypes[EventType::BackgroundTypes.at(i_type)]->Sumw2();
    }

    Hists_ByBackgroundTypes["Signal"]->Scale(SignalScale);

    Hist_All->Sumw2();   

    TH1D* h_errors = (TH1D*)Hist_All->Clone("h_errors");

    std::vector<TH1D*> Hists_ByPureKaonTypes_v;
    std::vector<TH1D*> Hists_ByBackgroundTypes_v;

    for(size_t i_t = 0; i_t < EventType::PureKaonSampleTypes.size(); i_t++) Hists_ByPureKaonTypes_v.push_back(Hists_ByPureKaonTypes[EventType::PureKaonSampleTypes.at(i_t)]); 
    for(size_t i_t = 0; i_t < EventType::BackgroundTypes.size(); i_t++) Hists_ByBackgroundTypes_v.push_back(Hists_ByBackgroundTypes[EventType::BackgroundTypes.at(i_t)]);

    HypPlot::DrawHistogram(Hists_ByPureKaonTypes_v, h_errors, Hist_Data, EventType::PureKaonSampleCaptions, PlotDir, label+"_ByPureKaonType", {BeamMode}, {Run}, {POT}, SignalScale, fHasData, EventType::PureKaonSampleColours, BinLabels, std::make_pair(0,0));
    HypPlot::DrawHistogram(Hists_ByBackgroundTypes_v, h_errors, Hist_Data, EventType::BackgroundCaptions, PlotDir, label+"_ByBackground", {BeamMode}, {Run}, {POT}, SignalScale, fHasData, EventType::BackgroundColours, BinLabels, std::make_pair(0, 0));

    /*std::map<std::string,TH1D*>::iterator it;
    for (it = Hists_ByType.begin(); it != Hists_ByType.end(); it++) it->second->Write(it->first.c_str());

    for (it = Hists_ByType2.begin(); it != Hists_ByType2.end(); it++){ 
        if(it->first == "EXT" || it->first == "Dirt") continue;

        it->second->Write(it->first.c_str());
    }*/

    Hist_All->Write("All");
    Hist_Data->Write("Data");
    h_errors->Write("ErrorBand");

}

// Draw the systematics histograms

void SelectionManager::DrawHistogramsSys(std::string label, std::string name, std::string type){

    /*std::cout << "Drawing systematic histograms for dial " << name << " and event type " << type << std::endl;

    system(("mkdir -p " + PlotDir).c_str());
    system(("mkdir -p " + RootfileDir).c_str());

    // Select which histograms to draw
    int systype=-1;
    std::vector<TH1D*> ToDraw;

    if(type == "All"){
        if(Multisim_Sys_Hists_All.find(name) != Multisim_Sys_Hists_All.end()){
            ToDraw = Multisim_Sys_Hists_All[name];
            systype = kMultisim;
        }
        else if(SingleUnisim_Sys_Hists_All.find(name) != SingleUnisim_Sys_Hists_All.end()){
            ToDraw = SingleUnisim_Sys_Hists_All[name];
            systype = kSingleUnisim;
        }
        else if(DualUnisim_Sys_Hists_All.find(name) != DualUnisim_Sys_Hists_All.end()){
            ToDraw = DualUnisim_Sys_Hists_All[name];
            systype = kDualUnisim;
        }
    }
    else if (Multisim_Sys_Hists[type].find(name) != Multisim_Sys_Hists[type].end()){
        ToDraw = Multisim_Sys_Hists[type][name]; 
        systype = kMultisim;
    }
    else if (SingleUnisim_Sys_Hists[type].find(name) != SingleUnisim_Sys_Hists[type].end()){
        ToDraw = SingleUnisim_Sys_Hists[type][name];
        systype = kSingleUnisim;
    }
    else if (DualUnisim_Sys_Hists[type].find(name) != DualUnisim_Sys_Hists[type].end()){
        ToDraw = DualUnisim_Sys_Hists[type][name];
        systype = kDualUnisim;
    }

    if(!ToDraw.size()){
        std::cout << "Can't find systematic name=" << name << " type=" << type << std::endl;
        return;
    }

    TH1D* h_CV = nullptr;
    if(type == "All") h_CV = Hist_All;
    else if(std::find(EventType::Types.begin(), EventType::Types.end(), type) != EventType::Types.end()) h_CV = Hists_ByType[type];
    else if(std::find(EventType::Types2.begin(), EventType::Types2.end(), type) != EventType::Types2.end()) h_CV = Hists_ByType2[type];   
    else throw std::invalid_argument("Trying to draw systematics histograms for unknown event type " + type + ", exiting");  

    HypPlot::DrawHistogramSys(ToDraw, h_CV, PlotDir, label, type, name, {BeamMode}, {Run}, {POT}, BinLabels);

    // Write everything to file
    if(!f_Hists->GetDirectory(name.c_str())) f_Hists->mkdir(name.c_str()); 

    f_Hists->GetDirectory(name.c_str())->cd();

    for(size_t i = 0; i < ToDraw.size(); i++){
        ToDraw.at(i)->SetDirectory(new TDirectory(name.c_str(), name.c_str()));      
        ToDraw.at(i)->Write();
    }

    f_Hists->cd();*/

}

// Get the covariace matrix for systematic dial

TMatrixD SelectionManager::GetCovarianceMatrix(std::string label, std::string name, std::string type){

    /*system(("mkdir -p " + PlotDir).c_str());

    int systype=-1;

    std::cout << "Getting Covariance Matrix for " << name << std::endl;

    OpenHistFile(label);

    std::vector<TH1D*> ToUse;

    if(type == "All"){
        if(Multisim_Sys_Hists_All.find(name) != Multisim_Sys_Hists_All.end()){
            ToUse = Multisim_Sys_Hists_All[name];
            systype = kMultisim;
        }
        else if(SingleUnisim_Sys_Hists_All.find(name) != SingleUnisim_Sys_Hists_All.end()){
            ToUse = SingleUnisim_Sys_Hists_All[name];
            systype = kSingleUnisim;
        }
        else if(DualUnisim_Sys_Hists_All.find(name) != DualUnisim_Sys_Hists_All.end()){
            ToUse = DualUnisim_Sys_Hists_All[name];
            systype = kDualUnisim;
        }
    }
    else if(Multisim_Sys_Hists[type].find(name) != Multisim_Sys_Hists[type].end()){
        ToUse = Multisim_Sys_Hists[type][name];
        systype = kMultisim;
    }
    else if(SingleUnisim_Sys_Hists[type].find(name) != SingleUnisim_Sys_Hists[type].end()){
        ToUse = SingleUnisim_Sys_Hists[type][name];
        systype = kSingleUnisim;
    }
    else if(DualUnisim_Sys_Hists[type].find(name) != DualUnisim_Sys_Hists[type].end()){
        ToUse = DualUnisim_Sys_Hists[type][name];
        systype = kDualUnisim;
    }

    TH1D* h_CV = nullptr;
    if(type == "All") h_CV = Hist_All;
    else if(std::find(EventType::Types.begin(), EventType::Types.end(),type) != EventType::Types.end()) h_CV = Hists_ByType[type];
    else if(std::find(EventType::Types2.begin(), EventType::Types2.end(),type) != EventType::Types2.end()) h_CV = Hists_ByType2[type];   
    else throw std::invalid_argument("Trying to calculate covariance matrix for unknown event type " + type + ", exiting");  

    const int arr_n = fHistBoundaries.size();
    Double_t arr_boundaries[arr_n];
    for(size_t i=0;i<arr_n;i++) arr_boundaries[i] = fHistBoundaries.at(i);

    std::string title = ";" + std::string(Hist_All->GetXaxis()->GetTitle()) + ";" + std::string(Hist_All->GetXaxis()->GetTitle());

    TMatrixD Cov(fHistNBins, fHistNBins);
    TH2D *h_Cov = new TH2D("h_Cov",title.c_str(), fHistNBins, arr_boundaries, fHistNBins, arr_boundaries);

    TMatrixD frac_Cov(fHistNBins,fHistNBins);
    TH2D *h_frac_Cov = new TH2D("h_frac_Cov", title.c_str(), fHistNBins, arr_boundaries, fHistNBins, arr_boundaries);

    if(BinLabels.size()){
        for(int i = 1; i < fHistNBins+1; i++){
            h_Cov->GetXaxis()->SetBinLabel(i, BinLabels.at(i-1).c_str());
            h_Cov->GetYaxis()->SetBinLabel(i, BinLabels.at(i-1).c_str());
            h_frac_Cov->GetXaxis()->SetBinLabel(i, BinLabels.at(i-1).c_str());
            h_frac_Cov->GetYaxis()->SetBinLabel(i, BinLabels.at(i-1).c_str());
        }

        h_Cov->GetXaxis()->SetLabelSize(0.07);
        h_Cov->GetYaxis()->SetLabelSize(0.07);
        h_frac_Cov->GetXaxis()->SetLabelSize(0.07);
        h_frac_Cov->GetYaxis()->SetLabelSize(0.07);
    }

    for(int i_b = 1; i_b < fHistNBins+1; i_b++){
        for(int j_b = 1; j_b < fHistNBins+1; j_b++){

            if(!(h_CV->GetBinContent(i_b) > 0 && h_CV->GetBinContent(j_b) > 0)) continue;

            Cov[i_b-1][j_b-1] = 0.0;        
            frac_Cov[i_b-1][j_b-1] = 0.0; 

            double Cov_ij = 0.0;
            double Mean_i = 0.0;
            double Mean_j = 0.0;

            if(systype == kMultisim){
                for(size_t i_u=0;i_u<ToUse.size();i_u++) Mean_i += ToUse.at(i_u)->GetBinContent(i_b)/ToUse.size();
                for(size_t i_u=0;i_u<ToUse.size();i_u++) Mean_j += ToUse.at(i_u)->GetBinContent(j_b)/ToUse.size();
                for(size_t i_u=0;i_u<ToUse.size();i_u++) Cov_ij += (ToUse.at(i_u)->GetBinContent(i_b) - Mean_i)*(ToUse.at(i_u)->GetBinContent(j_b) - Mean_j)/(ToUse.size()-1);
            }
            if(systype == kSingleUnisim){
                Mean_i = h_CV->GetBinContent(i_b);
                Mean_j = h_CV->GetBinContent(j_b);
                Cov_ij = (ToUse.at(0)->GetBinContent(i_b) - Mean_i)*(ToUse.at(0)->GetBinContent(j_b) - Mean_j);
            } 
            if(systype == kDualUnisim){
                Mean_i = h_CV->GetBinContent(i_b);
                Mean_j = h_CV->GetBinContent(j_b);
                Cov_ij = (ToUse.at(1)->GetBinContent(i_b) - ToUse.at(0)->GetBinContent(i_b))*(ToUse.at(1)->GetBinContent(j_b) - ToUse.at(0)->GetBinContent(j_b))/4;
            } 
            frac_Cov[i_b-1][j_b-1] = Cov_ij/Mean_i/Mean_j; 
            Cov[i_b-1][j_b-1] = Cov_ij;
            h_Cov->SetBinContent(i_b,j_b,Cov_ij);
            h_frac_Cov->SetBinContent(i_b,j_b,Cov_ij/Mean_i/Mean_j);
        }
    }

    std::string plottitle = label + "_CovMatrix_Sys_" + type + "_" + name;
    HypPlot::DrawMatrix(h_Cov, h_Cov, plottitle, PlotDir, BinLabels.size(), fUseText);

    plottitle = label + "_FCovMatrix_Sys_" + type + "_" + name;
    HypPlot::DrawMatrix(h_frac_Cov, h_frac_Cov, plottitle, PlotDir, BinLabels.size(), fUseText);

    h_Cov->Write(("Cov_" + type + "_" + name).c_str());
    h_frac_Cov->Write(("FCov_" + type + "_" + name).c_str());

    return Cov;*/

}

// Get the predicted number of events in a bin for a given event category

double SelectionManager::GetPrediction(int bin, std::string type){

    if(type == "" || type == "All") return Hist_All->GetBinContent(bin);
    else if(type == "Data") return Hist_Data->GetBinContent(bin);
    else if(Hists_ByPureKaonTypes.find(type) != Hists_ByPureKaonTypes.end()) return Hists_ByPureKaonTypes[type]->GetBinContent(bin);
    else if(Hists_ByBackgroundTypes.find(type) != Hists_ByBackgroundTypes.end()) return Hists_ByBackgroundTypes[type]->GetBinContent(bin);

    std::cout << "Type/Proc " << type << " not found, returning -1" << std::endl;
    return -1;

}

// Reopen the file containing the histograms

void SelectionManager::OpenHistFile(std::string label){

    if(f_Hists == nullptr){
        system(("mkdir -p " +  RootfileDir).c_str());
        f_Hists = TFile::Open((RootfileDir + label + "_Histograms.root").c_str(),"RECREATE");
    }

}

// Set the labels on the bins

void SelectionManager::SetBinLabels(std::vector<std::string> binlabels){

   if(binlabels.size() != fHistNBins) 
      throw std::invalid_argument("Set of bin labels does not match number of bins!"); 

   BinLabels = binlabels;

}

// Divide bins by bin widths

void SelectionManager::WidthScaleHistograms(){

    /*std::map<std::string,TH1D*>::iterator it1;

    for (it1 = Hists_ByType.begin(); it1 != Hists_ByType.end(); it1++){
        for(size_t i_b = 1; i_b < it1->second->GetNbinsX()+1; i_b++){        
            it1->second->SetBinContent(i_b, it1->second->GetBinContent(i_b)/it1->second->GetBinWidth(i_b));
            it1->second->SetBinError(i_b, it1->second->GetBinError(i_b)/it1->second->GetBinWidth(i_b));
        }
    }

    for (it1 = Hists_ByType2.begin(); it1 != Hists_ByType2.end(); it1++){
        for(size_t i_b = 1;i_b < it1->second->GetNbinsX()+1; i_b++){        
            it1->second->SetBinContent(i_b, it1->second->GetBinContent(i_b)/it1->second->GetBinWidth(i_b));
            it1->second->SetBinError(i_b, it1->second->GetBinError(i_b)/it1->second->GetBinWidth(i_b));
        }
    }

    for (it1 = Hists_ByPureKaonTypes.begin(); it1 != Hists_ByPureKaonTypes.end();it1++){
        for(size_t i_b=1; i_b < it1->second->GetNbinsX()+1; i_b++){
            it1->second->SetBinContent(i_b, it1->second->GetBinContent(i_b)/it1->second->GetBinWidth(i_b));
            it1->second->SetBinError(i_b, it1->second->GetBinError(i_b)/it1->second->GetBinWidth(i_b));
        }
    }

    std::map<std::string,std::map<std::string,std::vector<TH1D*>>>::iterator it2;

    for (it2 = Multisim_Sys_Hists.begin(); it2 != Multisim_Sys_Hists.end(); it2++){
        std::map<std::string,std::vector<TH1D*>>::iterator it22;
        for (it22 = it2->second.begin(); it22 != it2->second.end(); it22++){
            for(size_t i = 0; i < it22->second.size(); i++){
                for(size_t i_b = 1; i_b < it22->second.at(i)->GetNbinsX()+1; i_b++){        
                    it22->second.at(i)->SetBinContent(i_b, it22->second.at(i)->GetBinContent(i_b)/it22->second.at(i)->GetBinWidth(i_b));
                    it22->second.at(i)->SetBinError(i_b, it22->second.at(i)->GetBinError(i_b)/it22->second.at(i)->GetBinWidth(i_b));
                }
            }
        }
    }

   for (it2 = SingleUnisim_Sys_Hists.begin(); it2 != SingleUnisim_Sys_Hists.end(); it2++){
        std::map<std::string,std::vector<TH1D*>>::iterator it22;
        for (it22 = it2->second.begin(); it22 != it2->second.end(); it22++){
            for(size_t i = 0; i < it22->second.size(); i++){
                for(size_t i_b = 1; i_b < it22->second.at(i)->GetNbinsX()+1; i_b++){        
                    it22->second.at(i)->SetBinContent(i_b, it22->second.at(i)->GetBinContent(i_b)/it22->second.at(i)->GetBinWidth(i_b));
                    it22->second.at(i)->SetBinError(i_b, it22->second.at(i)->GetBinError(i_b)/it22->second.at(i)->GetBinWidth(i_b));
                }
            }
        }
   }

   for (it2 = DualUnisim_Sys_Hists.begin(); it2 != DualUnisim_Sys_Hists.end(); it2++){
      std::map<std::string,std::vector<TH1D*>>::iterator it22;
      for (it22 = it2->second.begin(); it22 != it2->second.end(); it22++){
         for(size_t i = 0; i < it22->second.size(); i++){
            for(size_t i_b = 1; i_b < it22->second.at(i)->GetNbinsX()+1; i_b++){        
               it22->second.at(i)->SetBinContent(i_b, it22->second.at(i)->GetBinContent(i_b)/it22->second.at(i)->GetBinWidth(i_b));
               it22->second.at(i)->SetBinError(i_b, it22->second.at(i)->GetBinError(i_b)/it22->second.at(i)->GetBinWidth(i_b));
            }
         }
      }
   }

   for(size_t i_b = 1; i_b<Hist_Data->GetNbinsX()+1; i_b++) Hist_Data->SetBinContent(i_b,Hist_Data->GetBinContent(i_b)/Hist_Data->GetBinWidth(i_b));
   for(size_t i_b = 1; i_b<Hist_All->GetNbinsX()+1; i_b++) Hist_All->SetBinContent(i_b,Hist_All->GetBinContent(i_b)/Hist_All->GetBinWidth(i_b));*/

}

// Retrieve the vector containing bin boundaries

std::vector<double> SelectionManager::GetBinBoundaries(){

   return fHistBoundaries; 

}

#endif
