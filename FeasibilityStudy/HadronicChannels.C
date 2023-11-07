R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so);
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so);

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

void HadronicChannels(){

  double POT = 1.0e21; // POT to scale samples to

  BuildTunes();
  SelectionParameters P = P_FHC_Tune_325_NoBDT;

  std::string label = "test";

  EventAssembler E(false);

  std::unordered_map<std::string, TH1D*> primaryParticlesCombinationHistograms;

  E.SetFile("analysisOutputRHC_GENIE_Overlay_Kaon_TEST.root","Background");

  for(int ievent = 0; ievent < E.GetNEvents(); ievent++){
	Event e = E.GetEvent(ievent);
	
	std::vector<SimParticle> allPrimaryParticles; 
	if(!e.Lepton.empty()) {
		if(!e.Hyperon.empty()) {
			allPrimaryParticles.insert(allPrimaryParticles.end(), e.Lepton.begin(), e.Lepton.end());
			allPrimaryParticles.insert(allPrimaryParticles.end(), e.Hyperon.begin(), e.Hyperon.end());
		}
	}
	//allPrimaryParticles.insert(allPrimaryParticles.end(), e.PrimaryNucleon.begin(), e.PrimaryNucleon.end());

	std::sort(allPrimaryParticles.begin(), allPrimaryParticles.end(),
		[](const SimParticle& a, const SimParticle& b) {
			return a.PDG < b.PDG;
		});
	
	std::string primaryParticlesCombination;	
	for(const SimParticle& particle : allPrimaryParticles) {
		if(!primaryParticlesCombination.empty()) {
			primaryParticlesCombination += "_";
		}
		primaryParticlesCombination += std::to_string(particle.PDG);
	}

	if(primaryParticlesCombination.empty() || primaryParticlesCombination[0] == '_') {
		continue;
	}
	std::cout << primaryParticlesCombination << std::endl;
	
	if(primaryParticlesCombinationHistograms.find(primaryParticlesCombination) == primaryParticlesCombinationHistograms.end()) {
		primaryParticlesCombinationHistograms[primaryParticlesCombination] = new TH1D(primaryParticlesCombination.c_str(), primaryParticlesCombination.c_str(), 10, 0, 10);
	}
	
  	if(ievent % 10000 == 0) std::cout << ievent << "/" << E.GetNEvents() << std::endl;

	double nuEnergy = e.Neutrino.at(0).E;
	
	primaryParticlesCombinationHistograms[primaryParticlesCombination]->Fill(nuEnergy);
    }

    // Draw histograms
    /*
    TH1D* hErrors = new TH1D("", "", 25, 0, 10);
    TH1D* hData = nullptr;

    std::vector<string> captionVec = {};
    string plotDir = ".";
    std::vector<int> modeVec = {};
    std::vector<int> runVec = {};
    std::vector<double> POTVec = {};
    double signalScale = 1.0;
    bool hasdata = hData != nullptr;
    std::vector<std::string> binlabels = {};
    std::vector<int> colors = {};
    std::pair<double, int> chi2ndof = std::make_pair(0,0);

    std::vector<TH1D*> histVec;
    int colorIndex = 0;
    for(const auto& pair : primaryParticlesCombinationHistograms) {
        captionVec.push_back(pair.first);
        histVec.push_back(pair.second);
        modeVec.push_back(kFHC);
        runVec.push_back(1);
        POTVec.push_back(POT);
	colors.push_back(chosenColours[colorIndex]);
	colorIndex += 1;
    }

    HypPlot::DrawHistogram(histVec, hErrors, hData, captionVec, plotDir, label, modeVec, runVec, POTVec, signalScale, hasdata, colors, binlabels, chi2ndof);
    */
  	
	THStack *hs = new THStack("hs", "hs");
	std::vector<Color_t> colors = {kRed+1, kBlue+1, kGreen+2, kMagenta+1, kCyan+1, kOrange+1, kYellow+1, kAzure+4, kSpring+5, kPink+7};

	int colorIndex = 0;
  	for (const auto& pair : primaryParticlesCombinationHistograms) {
    		TH1D* h = pair.second;
   		h->SetFillColor(colors[colorIndex % colors.size()]);
    		h->SetLineColor(kBlack); // Use black for line color for visibility
    		hs->Add(h);
    		colorIndex++;
  	}

  	TCanvas *c = new TCanvas("c", "canvas", 800, 600);
  	gPad->SetLogy(); // Set logarithmic scale
  	hs->Draw("hist");
  	hs->GetXaxis()->SetTitle("Neutrino Energy [GeV]");
  	hs->GetYaxis()->SetTitle("Counts");
  	hs->GetXaxis()->SetTitleSize(0.05);
  	hs->GetYaxis()->SetTitleSize(0.05);

  	auto legend = new TLegend(0.7, 0.7, 0.9, 0.9);
  	legend->SetTextSize(0.03); // Increase legend text size

	auto PDGToLatex = [](const std::string& pdgCode) -> std::string {
std::unordered_map<std::string, std::string> pdgToSymbol = {
    {"13", "#mu^{-}"}, // Muon
    {"-13", "#mu^{+}"}, // Anti-muon
    {"211", "#pi^{+}"}, // Positive pion
    {"-211", "#pi^{-}"}, // Negative pion
    {"2212", "p"}, // Proton
    {"-2212", "#bar{p}"}, // Anti-proton
    {"2112", "n"}, // Neutron
    {"-2112", "#bar{n}"}, // Anti-neutron
    {"11", "e^{-}"}, // Electron
    {"-11", "e^{+}"}, // Positron
    {"321", "K^{+}"}, // Kaon plus
    {"-321", "K^{-}"}, // Kaon minus
    {"310", "K_{S}^{0}"}, // K Short
    {"130", "K_{L}^{0}"}, // K Long
    {"3122", "#Lambda"}, // Lambda
    {"-3122", "#bar{#Lambda}"}, // Anti-Lambda
    {"3222", "#Sigma^{+}"}, // Sigma plus
    {"-3222", "#bar{#Sigma}^{-}"}, // Anti-Sigma minus
    {"3112", "#Sigma^{-}"}, // Sigma minus
    {"-3112", "#bar{#Sigma}^{+}"}, // Anti-Sigma plus
    {"3322", "#Xi^{0}"}, // Xi zero
    {"-3322", "#bar{#Xi}^{0}"}, // Anti-Xi zero
    {"3312", "#Xi^{-}"}, // Xi minus
    {"-3312", "#bar{#Xi}^{+}"}, // Anti-Xi plus
    {"3334", "#Omega^{-}"}, // Omega minus
    {"-3334", "#bar{#Omega}^{+}"}, // Anti-Omega plus
    // Add other mappings as needed...
    		};
    		std::string result;
    		std::istringstream iss(pdgCode);
    		std::string token;
    		while (std::getline(iss, token, '_')) {
      			if (!result.empty()) result += "_";
      			result += pdgToSymbol.count(token) ? pdgToSymbol[token] : token;
    		}
    		return result;
  	};

  	for (const auto& pair : primaryParticlesCombinationHistograms) {
    		std::string legendLabel = PDGToLatex(pair.first);
    		legend->AddEntry(pair.second, legendLabel.c_str(), "f");
  	}

  	legend->Draw();
  	c->Update();
  	c->SaveAs("stacked_hist.png");

    E.Close();

}
