//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Nov 16 10:41:02 2005 by ROOT version 4.04/02g
// from TTree D0/Reduced ROOT tree
// found on file: inclDstar_kspipi_ccbar.root
//////////////////////////////////////////////////////////

#ifndef inclDstar_final_h
#define inclDstar_final_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <iostream.h>
#include <TLorentzVector.h>
#include <iomanip.h>
#include <fstream.h>

#include "RooFitCore/RooRealVar.hh"
#include "RooFitCore/RooDataSet.hh"
#include "RooFitCore/RooPlot.hh"
#include "RooFitCore/RooAbsPdf.hh"
#include "RooFitCore/RooArgSet.hh"
#include "RooFitModels/RooGaussian.hh"
#include "RooFitModels/RooArgusBG.hh"
#include "RooFitCore/RooAddPdf.hh"
#include "RooFitModels/RooPolynomial.hh"
#include "RooFitCore/RooGenericPdf.hh"
#include "RooFitModels/RooDstD0BG.hh"
#include "RooFitModels/RooCBShape.hh"

class inclDstar_final {

  TString _d0mode; //datamembers
  TString _sig_type;
 
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain
 
   Double_t        probChi2DstarBS;
   Double_t        probChi2D0;
   Double_t        probChi2Ks;
   Int_t           McEvt,McEvt2; 
   
   
   RooRealVar *roomassD0,*roodeltaMDstarBS;
   RooArgSet roovars; 
  

   // Declaration of leave types
   Int_t           event;
   Float_t         runNumber;
   Int_t     upperID;
   Int_t      lowerID;
   Float_t         pxUps;
   Float_t         pyUps;
   Float_t         pzUps;
   Float_t         eUps;
   Int_t           nMc;
   Int_t           idMc[67];   //[nMc]
   Int_t           mothMc[67];   //[nMc]
   Int_t           nDauMc[67];   //[nMc]
   Float_t         pMc[67];   //[nMc]
   Float_t         thetaMc[67];   //[nMc]
   Float_t         phiMc[67];   //[nMc]
   Int_t           McEvtType;
   Float_t         deltamDstarmD0;
   Float_t         deltamDstarmD0BS;
   Float_t         deltaMDstarBS;
   Float_t         massDstarBS;
   Float_t         chi2DstarBS;
   Float_t         dofDstarBS;
   Float_t         cosDstarCM;
   Float_t         spixDstarBS;
   Float_t         spiyDstarBS;
   Float_t         spizDstarBS;
   Float_t         pPiDstarBS;
   Float_t         massDstar;
   Float_t         pxDstar;
   Float_t         pyDstar;
   Float_t         pzDstar;
   Float_t         m0Dstar;
   Float_t         chi2Dstar;
   Float_t         dofDstar;
   Float_t         xDstar;
   Float_t         yDstar;
   Float_t         zDstar;
   Float_t         indexMcDstar;
   Float_t         m0D0;
   Float_t         massD0;
   Float_t         pcmsD0;
   Float_t         pxD0;
   Float_t         pyD0;
   Float_t         pzD0;
   Float_t         eD0;
   Float_t         chi2D0;
   Float_t         dofD0;
   Float_t         xD0;
   Float_t         yD0;
   Float_t         zD0;
   Int_t           indexMcD0;
   Int_t           isMcD0;
   Float_t         m2pDalitzD0;
   Float_t         m2mDalitzD0;
   Float_t         m2zDalitzD0;
   Int_t           stDalitzD0;
   Float_t         mTotDalitzD0;
   Float_t         chi2DalitzD0;   
   Int_t           dofDalitzD0;
   Float_t         pxPi;
   Float_t         pyPi;
   Float_t         pzPi;
   Float_t         cthePi;
   Float_t         deltadrcmomPi;
   Int_t           lundPi;
   Int_t           kaonidPi;
   Int_t           ndchPi;
   Int_t           nphotPi;
   Int_t           lundMcPi;
   Int_t           indexMcPi;
   Float_t         massKs;
   Float_t         pxKs;
   Float_t         pyKs;
   Float_t         pzKs;
   Float_t         xKs;
   Float_t         yKs;
   Float_t         zKs;
   Float_t         chi2Ks;
   Int_t           dofKs;
   Float_t         cosKs;
   Int_t           isMcKs;
   Int_t           indexMcKs;
   Float_t         pxKsPi1;
   Float_t         pyKsPi1;
   Float_t         pzKsPi1;
   Int_t           lundMcKsPi1;
   Int_t           lundKsPi1;
   Int_t           kaonidKsPi1;
   Int_t           ndchKsPi1;
   Int_t           indexMcD0KsPi1;
   Float_t         pxKsPi2;
   Float_t         pyKsPi2;
   Float_t         pzKsPi2;
   Int_t           lundMcKsPi2;
   Int_t           lundKsPi2;
   Int_t           kaonidKsPi2;
   Int_t           ndchKsPi2;
   Int_t           indexMcD0KsPi2;
   Float_t         pxD0Pi1;
   Float_t         pyD0Pi1;
   Float_t         pzD0Pi1;
   Int_t           lundMcD0Pi1;
   Int_t           lundD0Pi1;
   Int_t           kaonidD0Pi1;
   Int_t           ndchD0Pi1;
   Int_t           indexMcD0Pi1;
   Float_t         pxD0Pi2;
   Float_t         pyD0Pi2;
   Float_t         pzD0Pi2;
   Int_t           lundMcD0Pi2;
   Int_t           lundD0Pi2;
   Int_t           kaonidD0Pi2;
   Int_t           ndchD0Pi2;
   Int_t           indexMcD0Pi2;

   // List of branches
   TBranch        *b_event;   //!
   TBranch        *b_runNumber;   //!
   TBranch        *b_upperID;   //!
   TBranch        *b_lowerID;   //!

   TBranch        *b_pxUps;   //!
   TBranch        *b_pyUps;   //!
   TBranch        *b_pzUps;   //!
   TBranch        *b_eUps;   //!
   TBranch        *b_nMc;   //!
   TBranch        *b_idMc;   //!
   TBranch        *b_mothMc;   //!
   TBranch        *b_nDauMc;   //!
   TBranch        *b_pMc;   //!
   TBranch        *b_thetaMc;   //!
   TBranch        *b_phiMc;   //!
   TBranch        *b_McEvtType;   //!
   TBranch        *b_deltamDstarD0;   //!
   TBranch        *b_deltamDstarD0BS;   //!
   TBranch        *b_deltaMDstarBS;   //!
   TBranch        *b_massDstarBS;   //!
   TBranch        *b_chi2DstarBS;   //!
   TBranch        *b_dofDstarBS;   //!
   TBranch        *b_cosDstarCM;   //!
   TBranch       *b_spixDstarBS;
   TBranch       *b_spiyDstarBS;
   TBranch       *b_spizDstarBS;
   TBranch       *b_pPiDstarBS;
   TBranch        *b_massDstar;   //!
   TBranch        *b_pxDstar;   //!
   TBranch        *b_pyDstar;   //!
   TBranch        *b_pzDstar;   //!
   TBranch        *b_m0Dstar;   //!
   TBranch        *b_chi2Dstar;   //!
   TBranch        *b_dofDstar;   //!
   TBranch        *b_xDstar;   //!
   TBranch        *b_yDstar;   //!
   TBranch        *b_zDstar;   //!
   TBranch        *b_indexMcDstar;   //!
   TBranch        *b_m0D0;   //!
   TBranch        *b_massD0;   //!
   TBranch        *b_pcmsD0;  //!
   TBranch        *b_pxD0;   //!
   TBranch        *b_pyD0;   //!
   TBranch        *b_pzD0;   //!
   TBranch        *b_eD0;   //!
   TBranch        *b_chi2D0;   //!
   TBranch        *b_dofD0;   //!
   TBranch        *b_xD0;   //!
   TBranch        *b_yD0;   //!
   TBranch        *b_zD0;   //!
   TBranch        *b_indexMcD0;   //!
   TBranch        *b_isMcD0;   //!
   TBranch        *b_m2pDalitzD0;   //!
   TBranch        *b_m2mDalitzD0;   //!
   TBranch        *b_m2zDalitzD0;   //!
   TBranch        *b_stDalitzD0;   //!
   TBranch        *b_mTotDalitzD0;   //!
   TBranch        *b_chi2DalitzD0;   //!
   TBranch        *b_dofDalitzD0;   //!
   TBranch        *b_pxPi;   //!
   TBranch        *b_pyPi;   //!
   TBranch        *b_pzPi;   //!
   TBranch        *b_cthePi;   //!
   TBranch        *b_deltadrcmomPi;   //!
   TBranch        *b_lundPi;   //!
   TBranch        *b_kaonidPi;   //!
   TBranch        *b_ndchPi;   //!
   TBranch        *b_nphotPi;   //!
   TBranch        *b_lundMcPi;   //!
   TBranch        *b_indexMcPi;   //!
   TBranch        *b_massKs;   //!
   TBranch        *b_pxKs;   //!
   TBranch        *b_pyKs;   //!
   TBranch        *b_pzKs;   //!
   TBranch        *b_xKs;   //!
   TBranch        *b_yKs;   //!
   TBranch        *b_zKs;   //!
   TBranch        *b_chi2Ks;   //!
   TBranch        *b_dofKs;   //!
   TBranch        *b_cosKs;   //!
   TBranch        *b_isMcKs;   //!
   TBranch        *b_indexMcKs;   //!
   TBranch        *b_pxKsPi1;   //!
   TBranch        *b_pyKsPi1;   //!
   TBranch        *b_pzKsPi1;   //!
   TBranch        *b_lundMcKsPi1;   //!
   TBranch        *b_lundKsPi1;   //!
   TBranch        *b_kaonidKsPi1;   //!
   TBranch        *b_ndchKsPi1;   //!
   TBranch        *b_indexMcD0KsPi1;   //!
   TBranch        *b_pxKsPi2;   //!
   TBranch        *b_pyKsPi2;   //!
   TBranch        *b_pzKsPi2;   //!
   TBranch        *b_lundMcKsPi2;   //!
   TBranch        *b_lundKsPi2;   //!
   TBranch        *b_kaonidKsPi2;   //!
   TBranch        *b_ndchKsPi2;   //!
   TBranch        *b_indexMcD0KsPi2;   //!
   TBranch        *b_pxD0Pi1;   //!
   TBranch        *b_pyD0Pi1;   //!
   TBranch        *b_pzD0Pi1;   //!
   TBranch        *b_lundMcD0Pi1;   //!
   TBranch        *b_lundD0Pi1;   //!
   TBranch        *b_kaonidD0Pi1;   //!
   TBranch        *b_ndchD0Pi1;   //!
   TBranch        *b_indexMcD0Pi1;   //!
   TBranch        *b_pxD0Pi2;   //!
   TBranch        *b_pyD0Pi2;   //!
   TBranch        *b_pzD0Pi2;   //!
   TBranch        *b_lundMcD0Pi2;   //!
   TBranch        *b_lundD0Pi2;   //!
   TBranch        *b_kaonidD0Pi2;   //!
   TBranch        *b_ndchD0Pi2;   //!
   TBranch        *b_indexMcD0Pi2;   //!

   inclDstar_final(TString d0mode, TString sig_type);
   virtual  ~inclDstar_final();
   
   virtual Int_t    Cut(Int_t cut_code, Bool_t mctruth=kFALSE);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop(Int_t cut_code, Long64_t nentries=0);
   virtual void     LoopBest(Int_t cut_code, Long64_t nentries=0, Int_t opt=1, TString myString="");
   
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
   
   virtual void     Fits(Int_t cut_code,Long64_t nentries=0, TString myString="");
   virtual RooAbsPdf* getPdf(RooRealVar& var);
   virtual void     bkg_tree(ofstream& outfile2);
   virtual Double_t getchi(Float_t mD0);

   virtual void     LoopPWA(TString _ref_frame ,Int_t coshOpt=1, Int_t cut_code=100, Long64_t nentries=0, Int_t Dflavour=0);
   virtual Double_t  CosHelBoostGJ(TLorentzVector vp1,TLorentzVector vp2, TLorentzVector vp3);
   virtual Double_t  CosHelInvar(Double_t _m1, Double_t _m2, Double_t _m3,
				 Double_t _m2_13, Double_t _m2_12, Double_t _m2_23, 
				 Int_t method) ; 
   
   inline Double_t lKallen(Double_t x, Double_t y, Double_t z){return (x*x+y*y+z*z-2*x*y-2*x*z-2*y*z);}
};

#endif

#ifdef inclDstar_final_cxx


inclDstar_final::inclDstar_final(TString d0mode, TString sig_type)
{
  _d0mode=d0mode;
  _sig_type=sig_type;
  
  assert(_d0mode=="kspipi" || _d0mode=="kskk");
  
  TChain *tree= new TChain("Dstar");
  
  cout<<"reading event of type: "<<_sig_type<<"; D0 mode: "<<_d0mode<< endl;
  
  TString filename;
  TString filename_root="./prod-32-skim18c/inclDst/reduced/inclDstar_"+d0mode+"_";
  
  assert( _sig_type=="chb"|| _sig_type=="b0b0bar" || _sig_type=="ccbar" || _sig_type=="uds" || _sig_type=="udsccbar" || _sig_type=="bbbar" || 
	  _sig_type=="on"  || _sig_type=="off" || _sig_type=="signal" || _sig_type=="signalm" || _sig_type=="signalp" || _sig_type=="On" || _sig_type=="On1234" || _sig_type=="On5");
  //
  if (_sig_type=="udsccbar") {
    filename=filename_root+"uds.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);
    filename=filename_root+"ccbar.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);
  } else if (_sig_type=="bbbar") {
    filename=filename_root+"chb.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);
    filename=filename_root+"b0b0bar.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);
  } else if (_sig_type=="signal") {
    filename=filename_root+"signalm.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);
    filename=filename_root+"signalp.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);
  } else if (_sig_type=="signalm") {
    filename=filename_root+"signalm.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);
  } else if (_sig_type=="signalp") {
    filename=filename_root+"signalp.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);
  } else if (_sig_type=="On") {
        filename=filename_root+"On1234.root";
        cout << "filename : " << filename << endl;
        tree->Add(filename);
        filename=filename_root+"On5.root";
        cout << "filename : " << filename << endl;
        tree->Add(filename);
    
  } else {
    filename=filename_root+_sig_type+".root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);
    //    filename=filename_root+sig_type+"_1.root";
    //    cout << "filename : " << filename << endl;
    //    tree->Add(filename);
  }
  //
cout<<"done"<<endl;


   Init(tree);

  roomassD0 = new RooRealVar("massD0","massD0",1.8645-0.040,1.8645+0.040);
  //roodeltamDstarmD0 = new RooRealVar("deltamDstarmD0","deltamDstarmD0",0.135,0.150);
  roodeltaMDstarBS= new RooRealVar("deltaMDstarBS","deltaMDstarBS",0.1395,0.150);
  roovars.addOwned(RooArgSet(*roomassD0,*roodeltaMDstarBS));

}

inclDstar_final::~inclDstar_final()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t inclDstar_final::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t inclDstar_final::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->IsA() != TChain::Class()) return centry;
   TChain *chain = (TChain*)fChain;
   if (chain->GetTreeNumber() != fCurrent) {
      fCurrent = chain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void inclDstar_final::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses of the tree
   // will be set. It is normaly not necessary to make changes to the
   // generated code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running with PROOF.

   // Set branch addresses
   if (tree == 0) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("event",&event);
   fChain->SetBranchAddress("runNumber",&runNumber);
   fChain->SetBranchAddress("upperID",&upperID);
   fChain->SetBranchAddress("lowerID",&lowerID);

   fChain->SetBranchAddress("pxUps",&pxUps);
   fChain->SetBranchAddress("pyUps",&pyUps);
   fChain->SetBranchAddress("pzUps",&pzUps);
   fChain->SetBranchAddress("eUps",&eUps);
   fChain->SetBranchAddress("nMc",&nMc);
   fChain->SetBranchAddress("idMc",idMc);
   fChain->SetBranchAddress("mothMc",mothMc);
   fChain->SetBranchAddress("nDauMc",nDauMc);
   fChain->SetBranchAddress("pMc",pMc);
   fChain->SetBranchAddress("thetaMc",thetaMc);
   fChain->SetBranchAddress("phiMc",phiMc);
   fChain->SetBranchAddress("McEvtType",&McEvtType);
   fChain->SetBranchAddress("deltamDstarmD0",&deltamDstarmD0);
   fChain->SetBranchAddress("deltamDstarmD0BS",&deltamDstarmD0BS);
   fChain->SetBranchAddress("deltaMDstarBS",&deltaMDstarBS);
   fChain->SetBranchAddress("massDstarBS",&massDstarBS);
   fChain->SetBranchAddress("chi2DstarBS",&chi2DstarBS);
   fChain->SetBranchAddress("dofDstarBS",&dofDstarBS);
   fChain->SetBranchAddress("cosDstarCM",&cosDstarCM);
   fChain->SetBranchAddress("spixDstarBS",&spixDstarBS);
   fChain->SetBranchAddress("spiyDstarBS",&spiyDstarBS);
   fChain->SetBranchAddress("spizDstarBS",&spizDstarBS);
   fChain->SetBranchAddress("pPiDstarBS",&pPiDstarBS);
   fChain->SetBranchAddress("massDstar",&massDstar);
   fChain->SetBranchAddress("pxDstar",&pxDstar);
   fChain->SetBranchAddress("pyDstar",&pyDstar);
   fChain->SetBranchAddress("pzDstar",&pzDstar);
   fChain->SetBranchAddress("m0Dstar",&m0Dstar);
   fChain->SetBranchAddress("chi2Dstar",&chi2Dstar);
   fChain->SetBranchAddress("dofDstar",&dofDstar);
   fChain->SetBranchAddress("xDstar",&xDstar);
   fChain->SetBranchAddress("yDstar",&yDstar);
   fChain->SetBranchAddress("zDstar",&zDstar);
   fChain->SetBranchAddress("indexMcDstar",&indexMcDstar);
   fChain->SetBranchAddress("m0D0",&m0D0);
   fChain->SetBranchAddress("massD0",&massD0);
   fChain->SetBranchAddress("pcmsD0",&pcmsD0);
   fChain->SetBranchAddress("pxD0",&pxD0);
   fChain->SetBranchAddress("pyD0",&pyD0);
   fChain->SetBranchAddress("pzD0",&pzD0);
   fChain->SetBranchAddress("eD0",&eD0);
   fChain->SetBranchAddress("chi2D0",&chi2D0);
   fChain->SetBranchAddress("dofD0",&dofD0);
   fChain->SetBranchAddress("xD0",&xD0);
   fChain->SetBranchAddress("yD0",&yD0);
   fChain->SetBranchAddress("zD0",&zD0);
   fChain->SetBranchAddress("indexMcD0",&indexMcD0);
   fChain->SetBranchAddress("isMcD0",&isMcD0);
   fChain->SetBranchAddress("m2pDalitzD0",&m2pDalitzD0);
   fChain->SetBranchAddress("m2mDalitzD0",&m2mDalitzD0);
   fChain->SetBranchAddress("m2zDalitzD0",&m2zDalitzD0);
   fChain->SetBranchAddress("stDalitzD0",&stDalitzD0);
   fChain->SetBranchAddress("mTotDalitzD0",&mTotDalitzD0);
   fChain->SetBranchAddress("chi2DalitzD0",&chi2DalitzD0);
   fChain->SetBranchAddress("dofDalitzD0",&dofDalitzD0);
   fChain->SetBranchAddress("pxPi",&pxPi);
   fChain->SetBranchAddress("pyPi",&pyPi);
   fChain->SetBranchAddress("pzPi",&pzPi);
   fChain->SetBranchAddress("cthePi",&cthePi);
   fChain->SetBranchAddress("deltadrcmomPi",&deltadrcmomPi);
   fChain->SetBranchAddress("lundPi",&lundPi);
   fChain->SetBranchAddress("kaonidPi",&kaonidPi);
   fChain->SetBranchAddress("ndchPi",&ndchPi);
   fChain->SetBranchAddress("nphotPi",&nphotPi);
   fChain->SetBranchAddress("lundMcPi",&lundMcPi);
   fChain->SetBranchAddress("indexMcPi",&indexMcPi);
   fChain->SetBranchAddress("massKs",&massKs);
   fChain->SetBranchAddress("pxKs",&pxKs);
   fChain->SetBranchAddress("pyKs",&pyKs);
   fChain->SetBranchAddress("pzKs",&pzKs);
   fChain->SetBranchAddress("xKs",&xKs);
   fChain->SetBranchAddress("yKs",&yKs);
   fChain->SetBranchAddress("zKs",&zKs);
   fChain->SetBranchAddress("chi2Ks",&chi2Ks);
   fChain->SetBranchAddress("dofKs",&dofKs);
   fChain->SetBranchAddress("cosKs",&cosKs);
   fChain->SetBranchAddress("isMcKs",&isMcKs);
   fChain->SetBranchAddress("indexMcKs",&indexMcKs);
   fChain->SetBranchAddress("pxKsPi1",&pxKsPi1);
   fChain->SetBranchAddress("pyKsPi1",&pyKsPi1);
   fChain->SetBranchAddress("pzKsPi1",&pzKsPi1);
   fChain->SetBranchAddress("lundMcKsPi1",&lundMcKsPi1);
   fChain->SetBranchAddress("lundKsPi1",&lundKsPi1);
   fChain->SetBranchAddress("kaonidKsPi1",&kaonidKsPi1);
   fChain->SetBranchAddress("ndchKsPi1",&ndchKsPi1);
   fChain->SetBranchAddress("indexMcD0KsPi1",&indexMcD0KsPi1);
   fChain->SetBranchAddress("pxKsPi2",&pxKsPi2);
   fChain->SetBranchAddress("pyKsPi2",&pyKsPi2);
   fChain->SetBranchAddress("pzKsPi2",&pzKsPi2);
   fChain->SetBranchAddress("lundMcKsPi2",&lundMcKsPi2);
   fChain->SetBranchAddress("lundKsPi2",&lundKsPi2);
   fChain->SetBranchAddress("kaonidKsPi2",&kaonidKsPi2);
   fChain->SetBranchAddress("ndchKsPi2",&ndchKsPi2);
   fChain->SetBranchAddress("indexMcD0KsPi2",&indexMcD0KsPi2);
   fChain->SetBranchAddress("pxD0Pi1",&pxD0Pi1);
   fChain->SetBranchAddress("pyD0Pi1",&pyD0Pi1);
   fChain->SetBranchAddress("pzD0Pi1",&pzD0Pi1);
   fChain->SetBranchAddress("lundMcD0Pi1",&lundMcD0Pi1);
   fChain->SetBranchAddress("lundD0Pi1",&lundD0Pi1);
   fChain->SetBranchAddress("kaonidD0Pi1",&kaonidD0Pi1);
   fChain->SetBranchAddress("ndchD0Pi1",&ndchD0Pi1);
   fChain->SetBranchAddress("indexMcD0Pi1",&indexMcD0Pi1);
   fChain->SetBranchAddress("pxD0Pi2",&pxD0Pi2);
   fChain->SetBranchAddress("pyD0Pi2",&pyD0Pi2);
   fChain->SetBranchAddress("pzD0Pi2",&pzD0Pi2);
   fChain->SetBranchAddress("lundMcD0Pi2",&lundMcD0Pi2);
   fChain->SetBranchAddress("lundD0Pi2",&lundD0Pi2);
   fChain->SetBranchAddress("kaonidD0Pi2",&kaonidD0Pi2);
   fChain->SetBranchAddress("ndchD0Pi2",&ndchD0Pi2);
   fChain->SetBranchAddress("indexMcD0Pi2",&indexMcD0Pi2);
   Notify();
}

Bool_t inclDstar_final::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. Typically here the branch pointers
   // will be retrieved. It is normaly not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed.

   // Get branch pointers
   b_event = fChain->GetBranch("event");
   b_runNumber = fChain->GetBranch("runNumber");
   b_upperID = fChain->GetBranch("upperID");
   b_lowerID = fChain->GetBranch("lowerID");

   b_pxUps = fChain->GetBranch("pxUps");
   b_pyUps = fChain->GetBranch("pyUps");
   b_pzUps = fChain->GetBranch("pzUps");
   b_eUps = fChain->GetBranch("eUps");
   b_nMc = fChain->GetBranch("nMc");
   b_idMc = fChain->GetBranch("idMc");
   b_mothMc = fChain->GetBranch("mothMc");
   b_nDauMc = fChain->GetBranch("nDauMc");
   b_pMc = fChain->GetBranch("pMc");
   b_thetaMc = fChain->GetBranch("thetaMc");
   b_phiMc = fChain->GetBranch("phiMc");
   b_McEvtType = fChain->GetBranch("McEvtType");
   b_deltamDstarD0 = fChain->GetBranch("deltamDstarmD0");
   b_deltamDstarD0BS = fChain->GetBranch("deltamDstarmD0BS");
   b_deltaMDstarBS = fChain->GetBranch("deltaMDstarBS");
   b_massDstarBS = fChain->GetBranch("massDstarBS");
   b_chi2DstarBS = fChain->GetBranch("chi2DstarBS");
   b_dofDstarBS = fChain->GetBranch("dofDstarBS");
   b_cosDstarCM = fChain->GetBranch("cosDstarCM");
   b_spixDstarBS = fChain->GetBranch("spixDstarBS");
   b_spiyDstarBS = fChain->GetBranch("spiyDstarBS");
   b_spizDstarBS = fChain->GetBranch("spizDstarBS");
   b_pPiDstarBS = fChain->GetBranch("pPiDstarBS");
   b_massDstar = fChain->GetBranch("massDstar");
   b_pxDstar = fChain->GetBranch("pxDstar");
   b_pyDstar = fChain->GetBranch("pyDstar");
   b_pzDstar = fChain->GetBranch("pzDstar");
   b_m0Dstar = fChain->GetBranch("m0Dstar");
   b_chi2Dstar = fChain->GetBranch("chi2Dstar");
   b_dofDstar = fChain->GetBranch("dofDstar");
   b_xDstar = fChain->GetBranch("xDstar");
   b_yDstar = fChain->GetBranch("yDstar");
   b_zDstar = fChain->GetBranch("zDstar");
   b_indexMcDstar = fChain->GetBranch("indexMcDstar");
   b_m0D0 = fChain->GetBranch("m0D0");
   b_massD0 = fChain->GetBranch("massD0");
   b_pcmsD0 = fChain->GetBranch("pcmsD0");
   b_pxD0 = fChain->GetBranch("pxD0");
   b_pyD0 = fChain->GetBranch("pyD0");
   b_pzD0 = fChain->GetBranch("pzD0");
   b_eD0 = fChain->GetBranch("eD0");
   b_chi2D0 = fChain->GetBranch("chi2D0");
   b_dofD0 = fChain->GetBranch("dofD0");
   b_xD0 = fChain->GetBranch("xD0");
   b_yD0 = fChain->GetBranch("yD0");
   b_zD0 = fChain->GetBranch("zD0");
   b_indexMcD0 = fChain->GetBranch("indexMcD0");
   b_isMcD0 = fChain->GetBranch("isMcD0");
   b_m2pDalitzD0 = fChain->GetBranch("m2pDalitzD0");
   b_m2mDalitzD0 = fChain->GetBranch("m2mDalitzD0");
   b_m2zDalitzD0 = fChain->GetBranch("m2zDalitzD0");
   b_stDalitzD0 = fChain->GetBranch("stDalitzD0");
   b_mTotDalitzD0 = fChain->GetBranch("mTotDalitzD0");
   b_chi2DalitzD0 = fChain->GetBranch("chi2DalitzD0");
   b_dofDalitzD0 = fChain->GetBranch("dofDalitzD0");
   b_pxPi = fChain->GetBranch("pxPi");
   b_pyPi = fChain->GetBranch("pyPi");
   b_pzPi = fChain->GetBranch("pzPi");
   b_cthePi = fChain->GetBranch("cthePi");
   b_deltadrcmomPi = fChain->GetBranch("deltadrcmomPi");
   b_lundPi = fChain->GetBranch("lundPi");
   b_kaonidPi = fChain->GetBranch("kaonidPi");
   b_ndchPi = fChain->GetBranch("ndchPi");
   b_nphotPi = fChain->GetBranch("nphotPi");
   b_lundMcPi = fChain->GetBranch("lundMcPi");
   b_indexMcPi = fChain->GetBranch("indexMcPi");
   b_massKs = fChain->GetBranch("massKs");
   b_pxKs = fChain->GetBranch("pxKs");
   b_pyKs = fChain->GetBranch("pyKs");
   b_pzKs = fChain->GetBranch("pzKs");
   b_xKs = fChain->GetBranch("xKs");
   b_yKs = fChain->GetBranch("yKs");
   b_zKs = fChain->GetBranch("zKs");
   b_chi2Ks = fChain->GetBranch("chi2Ks");
   b_dofKs = fChain->GetBranch("dofKs");
   b_cosKs = fChain->GetBranch("cosKs");
   b_isMcKs = fChain->GetBranch("isMcKs");
   b_indexMcKs = fChain->GetBranch("indexMcKs");
   b_pxKsPi1 = fChain->GetBranch("pxKsPi1");
   b_pyKsPi1 = fChain->GetBranch("pyKsPi1");
   b_pzKsPi1 = fChain->GetBranch("pzKsPi1");
   b_lundMcKsPi1 = fChain->GetBranch("lundMcKsPi1");
   b_lundKsPi1 = fChain->GetBranch("lundKsPi1");
   b_kaonidKsPi1 = fChain->GetBranch("kaonidKsPi1");
   b_ndchKsPi1 = fChain->GetBranch("ndchKsPi1");
   b_indexMcD0KsPi1 = fChain->GetBranch("indexMcD0KsPi1");
   b_pxKsPi2 = fChain->GetBranch("pxKsPi2");
   b_pyKsPi2 = fChain->GetBranch("pyKsPi2");
   b_pzKsPi2 = fChain->GetBranch("pzKsPi2");
   b_lundMcKsPi2 = fChain->GetBranch("lundMcKsPi2");
   b_lundKsPi2 = fChain->GetBranch("lundKsPi2");
   b_kaonidKsPi2 = fChain->GetBranch("kaonidKsPi2");
   b_ndchKsPi2 = fChain->GetBranch("ndchKsPi2");
   b_indexMcD0KsPi2 = fChain->GetBranch("indexMcD0KsPi2");
   b_pxD0Pi1 = fChain->GetBranch("pxD0Pi1");
   b_pyD0Pi1 = fChain->GetBranch("pyD0Pi1");
   b_pzD0Pi1 = fChain->GetBranch("pzD0Pi1");
   b_lundMcD0Pi1 = fChain->GetBranch("lundMcD0Pi1");
   b_lundD0Pi1 = fChain->GetBranch("lundD0Pi1");
   b_kaonidD0Pi1 = fChain->GetBranch("kaonidD0Pi1");
   b_ndchD0Pi1 = fChain->GetBranch("ndchD0Pi1");
   b_indexMcD0Pi1 = fChain->GetBranch("indexMcD0Pi1");
   b_pxD0Pi2 = fChain->GetBranch("pxD0Pi2");
   b_pyD0Pi2 = fChain->GetBranch("pyD0Pi2");
   b_pzD0Pi2 = fChain->GetBranch("pzD0Pi2");
   b_lundMcD0Pi2 = fChain->GetBranch("lundMcD0Pi2");
   b_lundD0Pi2 = fChain->GetBranch("lundD0Pi2");
   b_kaonidD0Pi2 = fChain->GetBranch("kaonidD0Pi2");
   b_ndchD0Pi2 = fChain->GetBranch("ndchD0Pi2");
   b_indexMcD0Pi2 = fChain->GetBranch("indexMcD0Pi2");

   return kTRUE;
}

void inclDstar_final::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}


Int_t inclDstar_final::Cut(Int_t cut_code, Bool_t mctruth)
{
  probChi2DstarBS = TMath::Prob(chi2DstarBS,(Int_t)dofDstarBS);
  probChi2D0 = TMath::Prob(chi2D0,(Int_t)dofD0);
  probChi2Ks = TMath::Prob(chi2Ks,(Int_t)dofKs);
    
  //
  // cout<<"probchi2chb="<<probchi2chb<<" y chi2chb="<<chi2chb<<endl;
  
  // LH
  // 1024: LH not a pion
  // 2048: LH very loose
  // 4096: LH loose
  // 8192: LH tight
  // 16384: LH very tight
  // SMS
  // 16: SMS not a pion
  // 1: SMS very loose
  // 2: SMS loose
  // 4: SMS tight
  // 8: SMS very tight

  Float_t deltamD0_cut = 0;
  Float_t deltadeltamd_cut = 0;//

  if(_d0mode=="kspipi"){
    deltamD0_cut = 2*0.0067404;
    //deltamD0_cut = 2*0.0053984;//luca
    
    deltadeltamd_cut = 2*0.000320540576;
    //deltadeltamd_cut = 0.0005;//luca

  }else if(_d0mode=="kskk"){
    deltamD0_cut = 2*0.00385165;
    deltadeltamd_cut = 2*0.00030548052;
  }else{
    deltamD0_cut = 0.0014;
    deltadeltamd_cut = 0.012;
  }
  Float_t deltamKs_cut = 0.009 ;
  //Float_t deltamKs_cut = 0.01 ;//luca

  Float_t cosKs_cut = 0.99 ;
  Float_t mD0_nom=1.8645;
  //Float_t mD0_nom=1.8647;//luca

  //Float_t mKs_nom=0.497855;//luca
  Float_t mKs_nom=0.4976;
  Float_t probChi2D0_cut =  0.;    
  Float_t probChi2Dstar_cut = 0. ; 
  //Float_t chi2Dstar_cut = 0. ; 
  //  Int_t pid_cut_pi = 16 ; 
  Float_t deltamd_nom = 0.1454;
  //Float_t deltamd_nom = 0.14543;//luca
  //
  Float_t mD0_low = 1.8645-0.040;
  Float_t mD0_high = 1.8645+0.040;
  Float_t deltaM_low = roodeltaMDstarBS->getMin();
  Float_t deltaM_high = roodeltaMDstarBS->getMax();

  
  Int_t pid_cut_k_kskk_1k = 1024;
  Int_t pid_cut_k_kskk_2k = 1024;
  

  // ... on the matching of D*->D0pi
  Int_t McEvt_base = 4+256+512+1024+2048;

  McEvt=0;  
  McEvt2=0;
  if (_sig_type=="signal" || _sig_type=="signalm" || _sig_type=="signalp" ||_sig_type=="ccbar") {
    McEvt = McEvt_base + 1  ;
    McEvt2 = McEvt_base + 2 ;
  }
  
  //    cout << mcEvtType << " " << mcEvt << " " << mcEvt2 << " " << mctruth << endl;
  
  if (mctruth && McEvtType!=McEvt && McEvtType!=McEvt2) 
    {
      cout<<"mcEvtType diferente de mcEvt 1 y 2"<<endl;
      return -1;
    }
  
  // Preselection 
  if (cut_code==0) {
    if ((massD0>=mD0_low && massD0<=mD0_high) &&
	(deltaMDstarBS>=deltaM_low && deltaMDstarBS<=deltaM_high))	 
      return 1;
    else return -1;
  } 
  //
  //The implementation of all the cuts
  //
  if(pcmsD0<2.2) return -1;

  if(stDalitzD0!=0 || fabs(mTotDalitzD0-mD0_nom)!=0. || chi2DalitzD0<0.) return -1;
  if(chi2DstarBS<0. || dofDstarBS<0. || probChi2DstarBS<probChi2Dstar_cut) return -1;


  if(((cut_code==1 || cut_code==112)? (massD0>mD0_low && massD0<mD0_high) : (fabs(massD0-mD0_nom)<deltamD0_cut)) &&
     (cut_code==7? kTRUE : fabs(massKs-mKs_nom)<deltamKs_cut) &&
     (cut_code==3? kTRUE : cosKs>cosKs_cut) &&
     ((cut_code==2 || cut_code==112)? (deltaMDstarBS>deltaM_low && deltaMDstarBS<deltaM_high) :(fabs(deltaMDstarBS-deltamd_nom)<deltadeltamd_cut)) &&
     (cut_code==5? kTRUE : (chi2D0>0. && chi2Ks>0. && probChi2D0>probChi2D0_cut)) &&
     //(_d0mode=="kspipi"? kTRUE :  (int(kaonidD0Pi1)&pid_cut_k_kskk_2k)==pid_cut_k_kskk_2k && (int(kaonidD0Pi2)&pid_cut_k_kskk_2k)==pid_cut_k_kskk_2k) && //PID in both kaons
     (_d0mode=="kspipi"? kTRUE :  (int(kaonidD0Pi1)&pid_cut_k_kskk_1k)==pid_cut_k_kskk_1k || (int(kaonidD0Pi2)&pid_cut_k_kskk_1k)==pid_cut_k_kskk_1k) && //PID in some kaon
     //(cut_code==4? kTRUE :!((int(kaonidPi)&pid_cut_pi)==pid_cut_pi)) &&
     //(cut_code==8? kTRUE : (chi2Ks/dofKs)>0.001) &&
     (cut_code==6? kTRUE: (chi2DstarBS>0. && probChi2DstarBS>probChi2Dstar_cut) ) 
     )
    return 1;
  //
  return -1;
} 

#endif // #ifdef inclDstar_final_cxx












