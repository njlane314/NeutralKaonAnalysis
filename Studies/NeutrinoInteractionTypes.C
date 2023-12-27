R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so)
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so)

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

void NeutrinoInteractionTypes(){

    std::string label = "neutrino_interaction_types";
    double POT = 1.0e21; 

    BuildTunes();

    SampleNames.push_back("GENIE Kaon");
    SampleTypes.push_back("Kaon");
    SampleFiles.push_back("analysisOutputFHC_GENIE_Overlay_Kaon.root");

    SelectionParameters P = P_FHC_Tune_325_NoBDT;

    EventAssembler E;
    SelectionManager M(P);

    M.SetPOT(POT);
    M.UseFluxWeight(false);
    M.UseGenWeight(false);

    M.SetupHistograms(20,0,10.0,";Neutrino Energy (GeV);Events/bin");
    //M.SetupHistograms(10,0,10.0,";Number of Primary Daughter Showers;Events");
    //M.SetupHistograms(25,0.25,0.75,";Invariant Mass of Pion Pair (GeV);Events");
    //M.SetupHistograms(20,-1,1,";Angular Deviation (deg);Events");
    //M.SetupHistograms(50,0,20,";Reconstructed Decay Length (cm);Events");

    TH2F *hPionMomenta = new TH2F("hPionMomenta", ";#pi^{+} Momentum (GeV/c);#pi^{-} Momentum (GeV/c)", 
                      15, 0, 1.5, 15, 0, 1.5);
    TH2F *hPionPlusRecoMomenta = new TH2F("hPionPlusRecoMomenta", ";#pi^{+} True Momentum (GeV/c);#pi^{+} Reconstructed Momentum (GeV/c)", 
                      150, 0, 1.5, 150, 0, 1.5);
    TH2F *hPionMinusRecoMomenta = new TH2F("hPionMinusRecoMomenta", ";#pi^{-} True Momentum (GeV/c);#pi^{-} Reconstructed Momentum (GeV/c)", 
                      150, 0, 1.5, 150, 0, 1.5);
    TH2F *hReconDecayLength = new TH2F("hReconDecayLength", ";True #pi^{+} Travel (cm);Reconstructed #pi^{0} Travel (cm);",
                        1000, 0.1, 100, 1000, 0.1, 100);

    TH1F *hFracDecayLength = new TH1F("hFracDecayLength", ";Frac;Events", 1000, -1, 5);

    TEfficiency* pEff = new TEfficiency("eff", ";cos(#theta_{opn}); Events/bin", 10, -1, 1);
    TEfficiency* pEnuEff = new TEfficiency("pEnuEFf", ";Neutrino Energy (GeV); Events/bin", 20, 0, 10);

    for(size_t i_s=0;i_s<SampleNames.size();i_s++){

        E.SetFile(SampleFiles.at(i_s), SampleTypes.at(i_s));
        if(SampleTypes.at(i_s) != "EXT" && SampleTypes.at(i_s) != "Data") M.AddSample(SampleNames.at(i_s),SampleTypes.at(i_s),E.GetPOT());
        else if(SampleTypes.at(i_s) == "Data") M.AddSample(SampleNames.at(i_s),SampleTypes.at(i_s),Data_POT);
        else if(SampleTypes.at(i_s) == "EXT") M.AddSample(SampleNames.at(i_s),SampleTypes.at(i_s),EXT_POT);

        for(int evt_itr = 0; evt_itr < E.GetNEvents(); evt_itr++){

            if(evt_itr % 10000 == 0) std::cout << evt_itr << "/" << E.GetNEvents() << std::endl;

            Event e = E.GetEvent(evt_itr);

            M.SetSignal(e);                
            M.AddEvent(e);

            if(!M.FiducialVolumeCut(e)) continue;
            //if(!M.TrackCut(e)) continue;
            //if(!M.ShowerCut(e)) continue;
            //if(!M.ChooseMuonCandidate(e)) continue;
            //if(!M.ChoosePionPairCandidates(e, true)) continue;
    
            double Enu = e.Neutrino.at(0).E;
            Int_t NTracks = e.NPrimaryTrackDaughters;
            Int_t NShowers = e.NPrimaryShowerDaughters;

            std::string temp = EventType::GetNeutralKaonDecayType(e);

            //if (EventType::GetKaonFinalStates(e) == "nu_mu_CC-13_311" || EventType::GetKaonFinalStates(e) == "nu_bar_mu_CC--13_311") {
                M.FillHistograms(e, Enu, e.Weight);  
                //M.FillHistograms(e, NShowers);
            //}  

            double openingAngle = -1;
            if (EventType::GetNeutralKaonDecayType(e) == "-211_211") {
                double piplusmom = 0;
                double piminusmom = 0;

                TVector3 Momentum1;
                TVector3 Momentum2;

                double invariantMass;

                if (e.KaonDecay.size() == 2) {
                    TVector3 TrueDecayVertex;
                    for (const auto& decayProduct : e.KaonDecay) {
                        if (decayProduct.PDG == -211) {
                            piminusmom = decayProduct.ModMomentum;
                            TrueDecayVertex.SetX(decayProduct.StartX); TrueDecayVertex.SetY(decayProduct.StartY); TrueDecayVertex.SetZ(decayProduct.StartZ);
                            hPionMinusRecoMomenta->Fill(piminusmom, PionMomentum(decayProduct.Travel));
                            Momentum1.SetX(decayProduct.Px); Momentum1.SetY(decayProduct.Py); Momentum1.SetZ(decayProduct.Pz);
                            hReconDecayLength->Fill(decayProduct.Travel, decayProduct.TrackTrueLength);
                        } else if (decayProduct.PDG == 211) {
                            piplusmom = decayProduct.ModMomentum;
                            hPionPlusRecoMomenta->Fill(piplusmom, PionMomentum(decayProduct.Travel));
                            Momentum2.SetX(decayProduct.Px); Momentum2.SetY(decayProduct.Py); Momentum2.SetZ(decayProduct.Pz);
                        }
                    }

                    hPionMomenta->Fill(piplusmom, piminusmom);
                    openingAngle = Momentum1.Angle(Momentum2);

                    bool bPassed = M.ChoosePionPairCandidates(e, true);
                    if(bPassed) {
                        invariantMass = PionPairInvariantMass(e.DecayPionPlusCandidate, e.DecayPionMinusCandidate);
                        
                        //M.FillHistograms(e, invariantMass, e.Weight); 

                        ///////////

                        SecondaryVertexFitter a_SecondaryVertexFitter(5);
                        SecondaryVertex V = a_SecondaryVertexFitter.MakeVertex(e.DecayPionPlusCandidate, e.DecayPionMinusCandidate);

                        TVector3 GapVector = V.Vertex - e.RecoPrimaryVertex;
                        double RecoDecayLength = (V.Vertex - e.RecoPrimaryVertex).Mag();
                        //M.FillHistograms(e, RecoDecayLength, e.Weight);

                        double TrueDecayLength = (TrueDecayVertex - e.DecayVertex.at(0)).Mag();
                        //hReconDecayLength->Fill(TrueDecayLength, RecoDecayLength);
                        
                        TLorentzVector NeutralKaon4Momentum = PionPair4Momentum(e.DecayPionPlusCandidate, e.DecayPionMinusCandidate);

                        TVector3 NeutralKaonDirection(NeutralKaon4Momentum.X(), NeutralKaon4Momentum.Y(), NeutralKaon4Momentum.Z());
                        double alpha = (180/3.1415) * NeutralKaonDirection.Angle(GapVector);

                        //M.FillHistograms(e, cos(alpha), e.Weight);
                    }

                    pEff->FillWeighted(bPassed, e.Weight, cos(openingAngle));
                    pEnuEff->FillWeighted(bPassed, e.Weight, Enu);
                }
                
            }
 
        }

        E.Close();
    }

    TCanvas *canvas = new TCanvas("", "", 800, 600);
    hPionMomenta->Draw("COLZ");
    hPionMomenta->SetStats(0);
    canvas->SaveAs("output.png");
    canvas->Close();

    TCanvas *canvas2 = new TCanvas("", "", 800, 600);
    hPionPlusRecoMomenta->Draw("COLZ");
    hPionPlusRecoMomenta->SetStats(0);
    canvas2->SaveAs("pionplusreco.png");
    canvas2->Close();

    TCanvas *canvas3 = new TCanvas("", "", 800, 600);
    hPionMinusRecoMomenta->Draw("COLZ");
    hPionMinusRecoMomenta->SetStats(0);
    canvas3->SaveAs("pionminusreco.png");
    canvas3->Close();

    TCanvas *canvas4 = new TCanvas("", "", 800, 600);
    hReconDecayLength->SetMarkerStyle(2); // Set marker style (20 is usually a full dot)
    hReconDecayLength->SetMarkerSize(1); // Increase the marker size

    hReconDecayLength->Draw("SCAT"); // SCAT for scatter plot
    hReconDecayLength->SetStats(0); // Turn off statistics box
    canvas4->SetLogy();
    canvas4->SetLogx();
    TF1 *line = new TF1("line", "x", 0, 100); // Replace xmin and xmax with your range
    line->SetLineColor(kRed); // Set line color to red
    line->Draw("SAME"); // Draw on the same canvas
    canvas4->SaveAs("decaylength.png");
    canvas4->Close();

    TCanvas *canvas5 = new TCanvas("", "", 800, 600);
    hFracDecayLength->SetLineColor(kBlack);
    hFracDecayLength->Draw();

    canvas5->SetGrid();
    hFracDecayLength->GetXaxis()->SetTitle("(Reconstructed - True)/True");
    hFracDecayLength->GetYaxis()->SetTitle("Arb. Units");

    // Save the canvas.
    canvas5->SaveAs("frac.png");

    M.DrawHistograms(label);

    HypPlot::DrawEfficiencyPlot(pEff, "open", "open", {kFHC}, {POT});
    HypPlot::DrawEfficiencyPlot(pEnuEff, "energy", "energy", {kFHC}, {POT});

}