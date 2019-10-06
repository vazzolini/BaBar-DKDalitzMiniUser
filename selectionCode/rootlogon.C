{
//
printf("\nExecuting selectionCode/rootlogon.C\n");
gSystem->Load("libCore.so");
//gSystem->Load("libProof.so");
gSystem->Load("libTreePlayer.so");
gSystem->Load("libPhysics.so");
gSystem->Load("libMinuit.so");
//
// load RooFitCore and RooFitModels
gSystem->Load("../../RooFitCore/tmp/libRooFitCore.so");
gSystem->Load("../../RooFitModels/tmp/libRooFitModels.so");
TString pwd = gSystem->Getenv("PWD");
//TString rootsys = gSystem->Getenv("ROOTSYS");
TString include;
//include =" -I"+rootsys+"/include "; gSystem->SetIncludePath(include); cout << include << endl;
include =" -I"+pwd+" "; gSystem->AddIncludePath(include); cout << include << endl;
include =" -I"+pwd+"/../../RooFitCore/tmp"; gSystem->AddIncludePath(include); cout << include << endl;
include =" -I"+pwd+"/../../RooFitModels/tmp "; gSystem->AddIncludePath(include); cout << include << endl;
printf("\nRooFit General shared libraries loaded \n");
//
//
gEnv->SetValue("Unix.*.Root.MacroPath",".:$(ROOTSYS)/macros:$(ROOTSYS)/tutorials:$(PWD)/../../../");  
//
printf("\nRooFit Loading RooAlias.C ... \n");
gROOT->ProcessLine(".L RooAlias.C");
printf("\nRooFit Executing RooLogon.C ... \n");
gROOT->ProcessLine(".x RooLogon.C");
}

