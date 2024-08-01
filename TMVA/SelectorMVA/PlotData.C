#include <TFile.h>
#include <TTree.h>
#include <TH1.h>
#include <TCanvas.h>

void CreateAndDrawHistogram(TTree* treeTrain, TTree* treeTest, const char* variableName, const char* title, int bins, float min, float max) {
    TH1F* hTrainCorrect = new TH1F(Form("hTrainCorrect_%s", variableName), Form("; %s;", title), bins, min, max);
    TH1F* hTrainIncorrect = new TH1F(Form("hTrainIncorrect_%s", variableName), Form("; %s;", title), bins, min, max);
    TH1F* hTestCorrect = new TH1F(Form("hTestCorrect_%s", variableName), Form("; %s;", title), bins, min, max);
    TH1F* hTestIncorrect = new TH1F(Form("hTestIncorrect_%s", variableName), Form("; %s;", title), bins, min, max);

    float value;
    int classID;
    treeTrain->SetBranchAddress(variableName, &value);
    treeTrain->SetBranchAddress("classID", &classID);

    Long64_t nEntries = treeTrain->GetEntries();
    for (Long64_t i = 0; i < nEntries; ++i) {
        treeTrain->GetEntry(i);
        if (classID == 0) { 
            hTrainCorrect->Fill(value);
        } else {
            hTrainIncorrect->Fill(value);
        }
    }

    treeTest->SetBranchAddress(variableName, &value);
    treeTest->SetBranchAddress("classID", &classID);

    nEntries = treeTest->GetEntries();
    for (Long64_t i = 0; i < nEntries; ++i) {
        treeTest->GetEntry(i);
        if (classID == 0) { 
            hTestCorrect->Fill(value);
        } else {
            hTestIncorrect->Fill(value);
        }
    }

    TCanvas *c = new TCanvas("", "", 800, 600);

    hTrainCorrect->Scale(1.0 / hTrainCorrect->Integral());
    hTrainIncorrect->Scale(1.0 / hTrainIncorrect->Integral());
    hTestCorrect->Scale(1.0 / hTestCorrect->Integral());
    hTestIncorrect->Scale(1.0 / hTestIncorrect->Integral());

    hTrainCorrect->SetLineColor(kBlue);
    hTrainCorrect->SetLineWidth(2);
    hTrainIncorrect->SetLineColor(kGreen);
    hTrainIncorrect->SetLineWidth(2);
    hTestCorrect->SetLineColor(kRed);
    hTestCorrect->SetLineWidth(2);
    hTestIncorrect->SetLineColor(kMagenta);
    hTestIncorrect->SetLineWidth(2);

    hTrainCorrect->Draw("HIST E");
    hTrainIncorrect->Draw("HIST E SAME");
    hTestCorrect->Draw("HIST E SAME");
    hTestIncorrect->Draw("HIST E SAME");

    hTrainCorrect->SetMaximum(std::max({hTrainCorrect->GetMaximum(), hTrainIncorrect->GetMaximum(), hTestCorrect->GetMaximum(), hTestIncorrect->GetMaximum()}) * 1.2);

    TLegend *leg = new TLegend(0.1, 0.91, 0.9, 0.99);
    leg->SetNColumns(4); 
    leg->AddEntry(hTrainCorrect, "Train Correct", "l");
    leg->AddEntry(hTrainIncorrect, "Train Incorrect", "l");
    leg->AddEntry(hTestCorrect, "Test Correct", "l");
    leg->AddEntry(hTestIncorrect, "Test Incorrect", "l");
    leg->Draw();

    c->SaveAs(Form("%s.png", variableName));

    delete hTrainCorrect;
    delete hTrainIncorrect;
    delete hTestCorrect;
    delete hTestIncorrect;
    delete c;
}

void PlotData() {
    gStyle->SetOptStat(0);

    TFile* file = TFile::Open("TMVA.root");
    TDirectory* dir = (TDirectory*)file->Get("dataset");
    TTree* treeTrain = (TTree*)dir->Get("TrainTree");
    TTree* treeTest = (TTree*)dir->Get("TestTree");

    if (!file || !file->IsOpen() || !treeTrain || !treeTest) {
        std::cerr << "Error opening file or retrieving tree." << std::endl;
        return;
    }

    CreateAndDrawHistogram(treeTrain, treeTest, "separation", "Separation (cm)", 10, 0, 10);
    CreateAndDrawHistogram(treeTrain, treeTest, "pion1_trkscore", "Track/Shower Score", 20, 0, 1);
    CreateAndDrawHistogram(treeTrain, treeTest, "BDT", "BDT Response", 20, -0.4, 0.1);
    CreateAndDrawHistogram(treeTrain, treeTest, "pion2_dEdX", "dE/dX", 20, 0, 1);
    CreateAndDrawHistogram(treeTrain, treeTest, "pion1_LLR", "LLR", 20, -1, 1);
}
