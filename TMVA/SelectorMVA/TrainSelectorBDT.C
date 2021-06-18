#include "TChain.h"
#include "TFile.h"
#include "TTree.h"
#include "TString.h"
#include "TObjString.h"
#include "TSystem.h"
#include "TROOT.h"

#include "TMVA/Factory.h"
#include "TMVA/DataLoader.h"
#include "TMVA/Tools.h"
#include "TMVA/TMVAGui.h"



void TrainSelectorBDT(){

//get input trees

TFile *f_in = TFile::Open("SelectorMVA/Trees.root");

//set output file
TString outfileName( "TMVA.root" );
TFile* outputFile = TFile::Open( outfileName, "RECREATE" );


//grab the trees

TTree* t_signal;
TTree* t_background;

f_in->GetObject("SignalTree",t_signal);
f_in->GetObject("BackgroundTree",t_background);


 std::map<std::string,int> Use;
Use["LD"]              = 1;
Use["BDT"] = 1;
Use["BDTG"] = 1;
Use["KNN"] = 1;
Use["Likelihood"] = 1;
Use["MLPBNN"] = 1;

TMVA::Tools::Instance();




//setup factory
TMVA::Factory *factory = new TMVA::Factory( "TMVAClassification", outputFile,
                                               "!V:!Silent:Color:DrawProgressBar:Transformations=I;D;P;G,D:AnalysisType=Classification" );


TMVA::DataLoader *dataloader=new TMVA::DataLoader("dataset");

dataloader->AddVariable("separation","Track Start Separation","cm",'F');
dataloader->AddVariable("proton_trkscore","Proton Candidate Track/Shower Score",'F');
dataloader->AddVariable("pion_trkscore","Pion Candidate Track/Shower Score",'F');
dataloader->AddVariable("proton_dEdX","Proton Candidate Mean dE/dX",'F');
dataloader->AddVariable("pion_dEdX","Pion Candidate Mean dE/dX",'F');
dataloader->AddVariable("proton_LLR","Proton LLR PID Score",'F');
dataloader->AddVariable("pion_LLR","Pion LLR PID Score",'F');


dataloader->AddSignalTree( t_signal , 1.0 );
dataloader->AddBackgroundTree( t_background , 1.0 );

TCut mycuts = "";

TCut mycutb = "";

dataloader->PrepareTrainingAndTestTree( mycuts, mycutb,"nTrain_Signal=2000:nTrain_Background=1000:SplitMode=Random:NormMode=NumEvents:!V" );


if (Use["LD"]) factory->BookMethod( dataloader, TMVA::Types::kLD, "LD", "H:!V:VarTransform=None:CreateMVAPdfs:PDFInterpolMVAPdf=Spline2:NbinsMVAPdf=50:NsmoothMVAPdf=10" );

if(Use["BDT"]) factory->BookMethod( dataloader, TMVA::Types::kBDT, "BDT","!H:!V:NTrees=850:MinNodeSize=2.5%:MaxDepth=3:BoostType=AdaBoost:AdaBoostBeta=0.5:UseBaggedBoost:BaggedSampleFraction=0.5:SeparationType=GiniIndex:nCuts=20" );

if(Use["BDTG"]) factory->BookMethod( dataloader, TMVA::Types::kBDT, "BDTG","!H:!V:NTrees=1000:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=0.10:UseBaggedBoost:BaggedSampleFraction=0.5:nCuts=20:MaxDepth=2" );

if (Use["KNN"]) factory->BookMethod( dataloader, TMVA::Types::kKNN, "KNN","H:nkNN=20:ScaleFrac=0.8:SigmaFact=1.0:Kernel=Gaus:UseKernel=F:UseWeight=T:!Trim" );

   if (Use["Likelihood"]) factory->BookMethod( dataloader, TMVA::Types::kLikelihood, "Likelihood","H:!V:TransformOutput:PDFInterpol=Spline2:NSmoothSig[0]=20:NSmoothBkg[0]=20:NSmoothBkg[1]=10:NSmooth=1:NAvEvtPerBin=50" );

   if (Use["MLPBNN"]) factory->BookMethod( dataloader, TMVA::Types::kMLP, "MLPBNN", "H:!V:NeuronType=tanh:VarTransform=N:NCycles=60:HiddenLayers=N+5:TestRate=5:TrainingMethod=BFGS:UseRegulator" ); // BFGS training with bayesian regulators


 factory->TrainAllMethods();
factory->TestAllMethods();
factory->EvaluateAllMethods();

   outputFile->Close();

   std::cout << "==> Wrote root file: " << outputFile->GetName() << std::endl;
   std::cout << "==> TMVAClassification is done!" << std::endl;


 delete factory;
 delete dataloader;


//launch GUI
 if (!gROOT->IsBatch()) TMVA::TMVAGui( outfileName );


}



