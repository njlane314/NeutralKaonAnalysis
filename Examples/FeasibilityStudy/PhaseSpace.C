R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so);
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so);

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

void PhaseSpace(){

	const double POT = 1.0e21;
	const int Mode = kFHC;

	std::string label = "effic";

  	BuildTunes();
  	EventAssembler E;
	
	SampleNames.push_back("GENIE Background");
	SampleTypes.push_back("Background");
	SampleFiles.push_back("analysisOutputFHC_GENIE_Overlay_Kaon.root");

	SelectionParameters P = P_FHC_Tune_325_NoBDT;
	SelectionManager M(P);
	M.SetPOT(POT);
	M.UseFluxWeight(false);
	M.UseGenWeight(false);

	TEfficiency* effic_OpeningAngleSelected = new TEfficiency("effic_OpeningAngleSelected", ";Opening Angle (deg); Events", 18, 0, 180);

	for(size_t s_itr = 0; s_itr < SampleNames.size(); s_itr++){
		
		E.SetFile(SampleFiles.at(s_itr), SampleTypes.at(s_itr));
		if(SampleTypes.at(s_itr) != "EXT" && SampleTypes.at(s_itr) != "Data") M.AddSample(SampleNames.at(s_itr), SampleTypes.at(s_itr), E.GetPOT());  		
		for(int evt_itr = 0; evt_itr < E.GetNEvents(); evt_itr++){

    			if(evt_itr % 10000 == 0) std::cout << evt_itr << "/" << E.GetNEvents() << std::endl;

    			Event evt = E.GetEvent(evt_itr);
			M.SetSignal(evt);
			M.AddEvent(evt);
			
			if(!evt.EventIsSignal) continue;

			double openingAngle = -1.;
			double decayPionPlusMomentum = -1.;
			double decayPionMinusMomentum = -1.;

			if(evt.Decay.size() == 2) {
				if(evt.Decay.at(0).PDG == +211) decayPionPlusMomentum = evt.Decay.at(0).ModMomentum;
				if(evt.Decay.at(0).PDG == -211) decayPionMinusMomentum = evt.Decay.at(0).ModMomentum;

				if(evt.Decay.at(1).PDG == +211) decayPionPlusMomentum = evt.Decay.at(1).ModMomentum;
				if(evt.Decay.at(1).PDG == -211) decayPionMinusMomentum = evt.Decay.at(1).ModMomentum;
			
				TVector3 Momentum1(evt.Decay.at(0).Px, evt.Decay.at(0).Py, evt.Decay.at(0).Pz);
				TVector3 Momentum2(evt.Decay.at(1).Px, evt.Decay.at(1).Py, evt.Decay.at(1).Pz);

				openingAngle = (180/3.1415) * Momentum1.Angle(Momentum2);
			}
			
			bool passedFV = false;
			bool passedTracks = false;
			bool passedShowers = false;

			passedFV = M.FiducialVolumeCut(evt);
			if(passedFV) passedTracks = M.TrackCut(evt);
			if(passedTracks) passedShowers = M.ShowerCut(evt);
			
			std::cout << "Opening angle " << openingAngle << std::endl;
			
			if(openingAngle != -1.) effic_OpeningAngleSelected->Fill(passedShowers, openingAngle);
		}   

  		E.Close();
	}

	HypPlot::DrawEfficiencyPlot(effic_OpeningAngleSelected, "", "openingangle", {Mode}, {POT});
}
