#ifndef btdkstarc_final_h
#define btdkstarc_final_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <iostream>
#include <TLorentzVector.h>
#include <iomanip.h>
#include <fstream.h>
//#include <strstream.h>

#include "RooFitCore/RooRealVar.hh"
#include "RooFitCore/RooDataSet.hh"
#include "RooFitCore/RooPlot.hh"
#include "RooFitCore/RooAbsPdf.hh"
#include "RooFitCore/RooArgSet.hh"
#include "RooFitModels/RooGaussian.hh"
#include "RooFitModels/RooBifurGauss.hh"
#include "RooFitModels/RooCBShape.hh"
#include "RooFitModels/RooArgusBG.hh"
#include "RooFitCore/RooAddPdf.hh"
#include "RooFitModels/RooPolynomial.hh"

class btdkstarc_final {
  TString _sig_type;
  TString _d0mode;
  TString _Kstarc_decay;
  Int_t _Kstarc_decay_code;
  Bool_t _isCS;


public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain
   
   Double_t        probchi2ChB;
   Double_t        probchi2D0;
   Double_t        probchi2Pi0;
   Double_t        probChi2Ks;
   Double_t        probchi2Vectorc;
   Double_t        probchi2VectorcReso;

   Int_t           McEvt,McEvt2; 

   RooRealVar *roomes,*roodemk,*roomassD0,*roofisherDK;
   RooArgSet roovars; 

   // Declaration of leave types
   Int_t           event;
   Int_t           runNumber;
   Int_t           upperID;
   Int_t           lowerID;


   Float_t         FoxWol2Neu;
   Float_t         pxUps;
   Float_t         pyUps;
   Float_t         pzUps;
   Float_t         eUps;
   Int_t           nMc;
   Float_t         pMc[300];   //[nMc]
   Float_t         thetaMc[300];   //[nMc]
   Float_t         phiMc[300];   //[nMc]
   Int_t           idMc[300];   //[nMc]
   Int_t           mothMc[300];   //[nMc]
   Int_t           nDauMc[300];   //[nMc]
   Int_t           McEvtType;
   Int_t           McNREvtType;
   Float_t         demk;
   Float_t         demk2;
   Float_t         mes;
   Float_t         pxChB;
   Float_t         pyChB;
   Float_t         pzChB;
   Float_t         cosChBCM;
   Float_t         m0ChB;
   Float_t         massChB;
   Float_t         chi2ChB;
   Float_t         dofChB;
   Float_t         xChB;
   Float_t         yChB;
   Float_t         zChB;
   Int_t           indexMcChB;
   Float_t         legendrep0;
   Float_t         legendrep2;
   Float_t         fisher;
   Float_t         costhrust;
   Float_t         m0D0;
   Float_t         massD0;
   Float_t         pcmsD0;
   Float_t         pxD0;
   Float_t         pyD0;
   Float_t         pzD0;
   Float_t         eD0;
   Float_t         xD0;
   Float_t         yD0;
   Float_t         zD0;
   Float_t         chi2D0;
   Float_t         dofD0;
   Float_t         m2pDalitzD0;
   Float_t         m2mDalitzD0;
   Float_t         m2zDalitzD0;
   Int_t           stDalitzD0;
   Float_t         mTotDalitzD0;
   Float_t         chi2DalitzD0;
   Int_t           dofDalitzD0;
   Int_t           indexMcD0;
   Int_t           isMcD0;
   Int_t           lundVectorc;
   Float_t         m0Vectorc;
   Float_t         massVectorc;
   Float_t         pxVectorc;
   Float_t         pyVectorc;
   Float_t         pzVectorc;
   Float_t         eVectorc;
   Float_t         xVectorc;
   Float_t         yVectorc;
   Float_t         zVectorc;
   Float_t         chi2Vectorc;
   Float_t         dofVectorc;
   Int_t           indexMcVectorc;
   Int_t           flagKspi;
   Int_t           isMcVectorcResopic;
   Int_t           isMcKstarckcPi0;
   Float_t         coseliVectorc;
   Float_t         m0KstarcPi0;
   Float_t         pxKstarcPi0;
   Float_t         pyKstarcPi0;
   Float_t         pzKstarcPi0;
   Float_t         eKstarcPi0;
   Float_t         chi2KstarcPi0;
   Float_t         dofKstarcPi0;
   Int_t           indexMcKstarcPi0;
   Int_t           isMcKstarcPi0;
   Float_t         ecalKstarcPi0g1;
   Float_t         ecalxKstarcPi0g1;
   Float_t         ecalyKstarcPi0g1;
   Float_t         ecalzKstarcPi0g1;
   Float_t         pxKstarcPi0g1;
   Float_t         pyKstarcPi0g1;
   Float_t         pzKstarcPi0g1;
   Float_t         lmomKstarcPi0g1;
   Int_t           ncryKstarcPi0g1;
   Int_t           indexMcKstarcPi0g1;
   Float_t         ecalKstarcPi0g2;
   Float_t         ecalxKstarcPi0g2;
   Float_t         ecalyKstarcPi0g2;
   Float_t         ecalzKstarcPi0g2;
   Float_t         pxKstarcPi0g2;
   Float_t         pyKstarcPi0g2;
   Float_t         pzKstarcPi0g2;
   Float_t         lmomKstarcPi0g2;
   Int_t           ncryKstarcPi0g2;
   Int_t           indexMcKstarcPi0g2;
   Float_t         pxKstarckc;
   Float_t         pyKstarckc;
   Float_t         pzKstarckc;
   Float_t         ctheKstarckc;
   Float_t         deltadrcmomKstarckc;
   Int_t           lundMcKstarckc;
   Int_t           kaonidKstarckc;
   Int_t           ndchKstarckc;
   Int_t           nphotKstarckc;
   Int_t           indexMcKstarckc;
   Float_t         massVectorcReso;
   Float_t         pxVectorcReso;
   Float_t         pyVectorcReso;
   Float_t         pzVectorcReso;
   Float_t         eVectorcReso;
   Float_t         xVectorcReso;
   Float_t         yVectorcReso;
   Float_t         zVectorcReso;
   Float_t         chi2VectorcReso;
   Int_t           dofVectorcReso;
   Float_t         cosVectorcReso;
   Int_t           isMcVectorcReso;
   Int_t           indexMcVectorcReso;
   Float_t         pxVectorcResoPi1;
   Float_t         pyVectorcResoPi1;
   Float_t         pzVectorcResoPi1;
   Int_t           lundMcVectorcResoPi1;
   Int_t           kaonidVectorcResoPi1;
   Int_t           ndchVectorcResoPi1;
   Int_t           indexMcVectorcResoPi1;
   Float_t         pxVectorcResoPi2;
   Float_t         pyVectorcResoPi2;
   Float_t         pzVectorcResoPi2;
   Int_t           lundMcVectorcResoPi2;
   Int_t           kaonidVectorcResoPi2;
   Int_t           ndchVectorcResoPi2;
   Int_t           indexMcVectorcResoPi2;
   Float_t         pxVectorcpic;
   Float_t         pyVectorcpic;
   Float_t         pzVectorcpic;
   Float_t         ctheVectorcpic;
   Float_t         deltadrcmomVectorcpic;
   Int_t           lundMcVectorcpic;
   Int_t           kaonidVectorcpic;
   Int_t           ndchVectorcpic;
   Int_t           nphotVectorcpic;
   Int_t           indexMcVectorcpic;
   Float_t         massKs;
   Float_t         pxKs;
   Float_t         pyKs;
   Float_t         pzKs;
   Float_t         xKs;
   Float_t         yKs;
   Float_t         zKs;
   Float_t         cosKs;
   Float_t         chi2Ks;
   Int_t           dofKs;
   Int_t           isMcKs;
   Int_t           indexMcKs;
   Float_t         pxKsPi1;
   Float_t         pyKsPi1;
   Float_t         pzKsPi1;
   Int_t           lundMcKsPi1;
   Int_t           kaonidKsPi1;
   Int_t           ndchKsPi1;
   Int_t           indexMcD0KsPi1;
   Float_t         pxKsPi2;
   Float_t         pyKsPi2;
   Float_t         pzKsPi2;
   Int_t           lundMcKsPi2;
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


   TBranch        *b_FoxWol2Neu;   //!
   TBranch        *b_pxUps;   //!
   TBranch        *b_pyUps;   //!
   TBranch        *b_pzUps;   //!
   TBranch        *b_eUps;   //!
   TBranch        *b_nMc;   //!
   TBranch        *b_pMc;   //!
   TBranch        *b_thetaMc;   //!
   TBranch        *b_phiMc;   //!
   TBranch        *b_idMc;   //!
   TBranch        *b_mothMc;   //!
   TBranch        *b_nDauMc;   //!
   TBranch        *b_McEvtType;   //!
   TBranch        *b_McNREvtType;   //!
   TBranch        *b_demk;   //!
   TBranch        *b_demk2;   //!
   TBranch        *b_mes;   //!
   TBranch        *b_pxChB;   //!
   TBranch        *b_pyChB;   //!
   TBranch        *b_pzChB;   //!
   TBranch        *b_cosChBCM;   //!
   TBranch        *b_m0ChB;   //!
   TBranch        *b_massChB;   //!
   TBranch        *b_chi2ChB;   //!
   TBranch        *b_dofChB;   //!
   TBranch        *b_xChB;   //!
   TBranch        *b_yChB;   //!
   TBranch        *b_zChB;   //!
   TBranch        *b_indexMcChB;   //!
   TBranch        *b_legendrep0;   //!
   TBranch        *b_legendrep2;   //!
   TBranch        *b_fisher;   //!
   TBranch        *b_costhrust;   //!
   TBranch        *b_m0D0;   //!
   TBranch        *b_massD0;   //!
   TBranch        *b_pcmsD0;  //!
   TBranch        *b_pxD0;   //!
   TBranch        *b_pyD0;   //!
   TBranch        *b_pzD0;   //!
   TBranch        *b_eD0;   //!
   TBranch        *b_xD0;   //!
   TBranch        *b_yD0;   //!
   TBranch        *b_zD0;   //!
   TBranch        *b_chi2D0;   //!
   TBranch        *b_dofD0;   //!
   TBranch        *b_m2pDalitzD0;   //!
   TBranch        *b_m2mDalitzD0;   //!
   TBranch        *b_m2zDalitzD0; 
   TBranch        *b_stDalitzD0;   //!
   TBranch        *b_mTotDalitzD0;   //!
   TBranch        *b_chi2DalitzD0;   //!
   TBranch        *b_dofDalitzD0;   //!
   TBranch        *b_indexMcD0;   //!
   TBranch        *b_isMcD0;   //!
   TBranch        *b_lundVectorc;   //!
   TBranch        *b_m0Vectorc;   //!
   TBranch        *b_massVectorc;   //!
   TBranch        *b_pxVectorc;   //!
   TBranch        *b_pyVectorc;   //!
   TBranch        *b_pzVectorc;   //!
   TBranch        *b_eVectorc;   //!
   TBranch        *b_xVectorc;   //!
   TBranch        *b_yVectorc;   //!
   TBranch        *b_zVectorc;   //!
   TBranch        *b_chi2Vectorc;   //!
   TBranch        *b_dofVectorc;   //!
   TBranch        *b_indexMcVectorc;   //!
   TBranch        *b_flagKspi;   //!
   TBranch        *b_isMcVectorcResopic;   //!
   TBranch        *b_isMcKstarckcPi0;   //!
   TBranch        *b_coseliVectorc;   //!
   TBranch        *b_m0KstarcPi0;   //!
   TBranch        *b_pxKstarcPi0;   //!
   TBranch        *b_pyKstarcPi0;   //!
   TBranch        *b_pzKstarcPi0;   //!
   TBranch        *b_eKstarcPi0;   //!
   TBranch        *b_chi2KstarcPi0;   //!
   TBranch        *b_dofKstarcPi0;   //!
   TBranch        *b_indexMcKstarcPi0;   //!
   TBranch        *b_isMcKstarcPi0;   //!
   TBranch        *b_ecalKstarcPi0g1;   //!
   TBranch        *b_ecalxKstarcPi0g1;   //!
   TBranch        *b_ecalyKstarcPi0g1;   //!
   TBranch        *b_ecalzKstarcPi0g1;   //!
   TBranch        *b_pxKstarcPi0g1;   //!
   TBranch        *b_pyKstarcPi0g1;   //!
   TBranch        *b_pzyKstarcPi0g1;   //!
   TBranch        *b_lmomKstarcPi0g1;   //!
   TBranch        *b_ncryKstarcPi0g1;   //!
   TBranch        *b_indexMcKstarcPi0g1;   //!
   TBranch        *b_ecalKstarcPi0g2;   //!
   TBranch        *b_ecalxKstarcPi0g2;   //!
   TBranch        *b_ecalyKstarcPi0g2;   //!
   TBranch        *b_ecalzKstarcPi0g2;   //!
   TBranch        *b_pxKstarcPi0g2;   //!
   TBranch        *b_pyKstarcPi0g2;   //!
   TBranch        *b_pzyKstarcPi0g2;   //!
   TBranch        *b_lmomKstarcPi0g2;   //!
   TBranch        *b_ncryKstarcPi0g2;   //!
   TBranch        *b_indexMcKstarcPi0g2;   //!
   TBranch        *b_pxKstarckc;   //!
   TBranch        *b_pyKstarckc;   //!
   TBranch        *b_pzKstarckc;   //!
   TBranch        *b_ctheKstarckc;   //!
   TBranch        *b_deltadrcmomKstarckc;   //!
   TBranch        *b_lundMcKstarckc;   //!
   TBranch        *b_kaonidKstarckc;   //!
   TBranch        *b_ndchKstarckc;   //!
   TBranch        *b_nphotKstarckc;   //!
   TBranch        *b_indexMcKstarckc;   //!
   TBranch        *b_massVectorcReso;   //!
   TBranch        *b_pxVectorcReso;   //!
   TBranch        *b_pyVectorcReso;   //!
   TBranch        *b_pzVectorcReso;   //!
   TBranch        *b_eVectorcReso;   //!
   TBranch        *b_xVectorcReso;   //!
   TBranch        *b_yVectorcReso;   //!
   TBranch        *b_zVectorcReso;   //!
   TBranch        *b_chi2VectorcReso;   //!
   TBranch        *b_dofVectorcReso;   //!
   TBranch        *b_cosVectorcReso;   //!
   TBranch        *b_isMcVectorcReso;   //!
   TBranch        *b_indexMcVectorcReso; //!
   TBranch        *b_pxVectorcResoPi1;  //!
   TBranch        *b_pyVectorcResoPi1;   //!
   TBranch        *b_pzVectorcResoPi1;   //!
   TBranch        *b_lundMcVectorcResoPi1;   //!
   TBranch        *b_kaonidVectorcResoPi1;   //!
   TBranch        *b_ndchVectorcResoPi1;   //!
   TBranch        *b_indexMcVectorcResoPi1;   //!
   TBranch        *b_pxVectorcResoPi2;   //!
   TBranch        *b_pyVectorcResoPi2;   //!
   TBranch        *b_pzVectorcResoPi2;   //!
   TBranch        *b_lundMcVectorcResoPi2;   //!
   TBranch        *b_kaonidVectorcResoPi2;   //!
   TBranch        *b_ndchVectorcResoPi2;   //!
   TBranch        *b_indexMcVectorcResoPi2;   //!
   TBranch        *b_pxVectorcpic;   //!
   TBranch        *b_pyVectorcpic;   //!
   TBranch        *b_pzVectorcpic;   //!
   TBranch        *b_ctheVectorcpic;   //!
   TBranch        *b_deltadrcmomVectorcpic;   //!
   TBranch        *b_lundMcVectorcpic;   //!
   TBranch        *b_kaonidVectorcpic;   //!
   TBranch        *b_ndchVectorcpic;   //!
   TBranch        *b_nphotVectorcpic;   //!
   TBranch        *b_indexMcVectorcpic;   //!
   TBranch        *b_massKs;   //!
   TBranch        *b_pxKs;   //!
   TBranch        *b_pyKs;   //!
   TBranch        *b_pzKs;   //!
   TBranch        *b_xKs;   //!
   TBranch        *b_yKs;   //!
   TBranch        *b_zKs;   //!
   TBranch        *b_cosKs;   //!
   TBranch        *b_chi2Ks;   //!
   TBranch        *b_dofKs;   //!
   TBranch        *b_isMcKs;   //!
   TBranch        *b_indexMcKs;   //!
   TBranch        *b_pxKsPi1;   //!
   TBranch        *b_pyKsPi1;   //!
   TBranch        *b_pzKsPi1;   //!
   TBranch        *b_lundMcKsPi1;   //!
   TBranch        *b_kaonidKsPi1;   //!
   TBranch        *b_ndchKsPi1;   //!
   TBranch        *b_indexMcD0KsPi1;   //!
   TBranch        *b_pxKsPi2;   //!
   TBranch        *b_pyKsPi2;   //!
   TBranch        *b_pzKsPi2;   //!
   TBranch        *b_lundMcKsPi2;   //!
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

   //btdkstarc_final(TTree *tree=0);
   btdkstarc_final(TString Kstarc_decay, TString d0mode, TString sig_type, TString release="analysis-30", Bool_t isCS=kFALSE, Bool_t doReadRootuples=kTRUE);
   virtual ~btdkstarc_final();

   virtual Int_t    Cut(Int_t cut_code, Bool_t Mctruth=kFALSE, Float_t fisher=0);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     LoopBest(Int_t cut_code, Long64_t nentries=0, Int_t opt1=1);
   virtual void     Loop(Int_t cut_code, Long64_t nentries=0);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
   //virtual Double_t Rescaling(TLorentzVector& vKs, TLorentzVector& vPi1, TLorentzVector& vPi2, Double_t M, Double_t mass1, Double_t mass2, Double_t mass3);
   virtual void     Fits(Int_t cut_code, TString varname="");
   virtual RooAbsPdf* getPdf(RooRealVar& var);
   virtual void     bkg_tree(ofstream& outfile2);
   virtual Double_t getchi(Float_t mPi0,Float_t mVectorc, Float_t mD0);
   virtual void     dalVarsTruth(Int_t mcTruth,Float_t* dalVars);

};

#endif

#ifdef btdkstarc_final_cxx


btdkstarc_final::btdkstarc_final(TString Kstarc_decay, TString d0mode, TString sig_type, TString release, Bool_t isCS, Bool_t doReadRootuples)
{
  /////////////////////////////////////////////////////////////////
  //// Kstarc_decay = kspi, kpi0                               ////
  //// d0mode = kspipi                                         ////
  //// sig_type = uds, ccbar, ....                             ////   
  /////////////////////////////////////////////////////////////////

  _sig_type = sig_type;
  _isCS = isCS;
  _d0mode = d0mode;
  _Kstarc_decay = Kstarc_decay;
  _Kstarc_decay_code = (Kstarc_decay=="kspi"|| Kstarc_decay=="rho0pi")? 1 : 2;
  
  if(_sig_type=="btda1" && Kstarc_decay!="rho0pi") assert(0);


  assert(_Kstarc_decay=="kspi" || _Kstarc_decay=="kpi0" || _Kstarc_decay=="rho0pi");
  assert(_d0mode=="kspipi");

  cout<<"reading event of type: "<<_sig_type<<"; D0 mode: "<<_d0mode<<endl;

  TChain* tree=new TChain("T");

  TString filename;
  TString filename_root;
  if (release=="analysis-26") filename_root="./prod-26/DK/reduced/";
  //  if (release=="analysis-30") filename_root="./prod-32-skim18c/DK/reduced/";
  if (release=="analysis-30") filename_root="./root/";
  //filename_root += (_isCS==kFALSE)? "BchToD0KstarAll/btdkstarc_"+_d0mode+"_" : "BchToD0KstarAll/btda1_"+_d0mode+"_";
  filename_root += (_isCS==kFALSE)? "btdkstarc_"+_d0mode+"_" : "btda1_"+_d0mode+"_";
  
  if (doReadRootuples) {
    
  if (_sig_type=="uds") {

    filename=filename_root+"uds1.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);
    filename=filename_root+"uds2.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);
    filename=filename_root+"uds3.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);
    filename=filename_root+"uds4.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);
    filename=filename_root+"uds5.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);

  } else if (_sig_type=="ccbar") {

    filename=filename_root+"ccbar1.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);
    filename=filename_root+"ccbar2*.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);
    filename=filename_root+"ccbar3.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);
    filename=filename_root+"ccbar4*.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);
    filename=filename_root+"ccbar5.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);

  } else if (_sig_type=="udsccbar") {

    filename=filename_root+"uds1.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);
/*     filename=filename_root+"uds2.root"; */
/*     cout << "filename : " << filename << endl; */
/*     tree->Add(filename); */
/*     filename=filename_root+"uds3.root"; */
/*     cout << "filename : " << filename << endl; */
/*     tree->Add(filename); */
/*     filename=filename_root+"uds4.root"; */
/*     cout << "filename : " << filename << endl; */
/*     tree->Add(filename); */
/*     filename=filename_root+"uds5.root"; */
/*     cout << "filename : " << filename << endl; */
/*     tree->Add(filename); */

    filename=filename_root+"ccbar1.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);
/*     filename=filename_root+"ccbar2*.root"; */
/*     cout << "filename : " << filename << endl; */
/*     tree->Add(filename); */
/*     filename=filename_root+"ccbar3.root"; */
/*     cout << "filename : " << filename << endl; */
/*     tree->Add(filename); */
/*     filename=filename_root+"ccbar4*.root"; */
/*     cout << "filename : " << filename << endl; */
/*     tree->Add(filename); */
/*     filename=filename_root+"ccbar5.root"; */
/*     cout << "filename : " << filename << endl; */
/*     tree->Add(filename); */

  } else if (_sig_type=="chb") {

    filename=filename_root+"chb1.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);
    filename=filename_root+"chb2.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);
    filename=filename_root+"chb3.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);
    filename=filename_root+"chb4*.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);
    filename=filename_root+"chb5.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);

  }  else if (_sig_type=="chbNR") {

    filename=filename_root+"chbNR1.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);
    filename=filename_root+"chbNR2.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);
    filename=filename_root+"chbNR3.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);
    filename=filename_root+"chbNR4.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);
    filename=filename_root+"chbNR5.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);

  }else if (_sig_type=="chbR") {

    filename=filename_root+"chbR1.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);
    filename=filename_root+"chbR2.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);
    filename=filename_root+"chbR3.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);
    filename=filename_root+"chbR4.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);
    filename=filename_root+"chbR5.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);

  }else if (_sig_type=="b0b0bar") {

    filename=filename_root+"b0b0bar1.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);
    filename=filename_root+"b0b0bar2.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);
    filename=filename_root+"b0b0bar3.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);
    filename=filename_root+"b0b0bar4*.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);
    filename=filename_root+"b0b0bar5.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);

  } else if (_sig_type=="bbbar") {

    filename=filename_root+"chb1.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);
    filename=filename_root+"chb2.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);
    filename=filename_root+"chb3.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);
    filename=filename_root+"chb4*.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);
    filename=filename_root+"chb5.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);

    filename=filename_root+"b0b0bar1.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);
    filename=filename_root+"b0b0bar2.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);
    filename=filename_root+"b0b0bar3.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);
    filename=filename_root+"b0b0bar4*.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);
    filename=filename_root+"b0b0bar5.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);

  } else if (_sig_type=="On") {

    filename=filename_root+"On1.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);
    filename=filename_root+"On2.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);
    filename=filename_root+"On3.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);
    filename=filename_root+"On4*.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);
    filename=filename_root+"On5.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);

  }else if (_sig_type=="Off") {

    filename=filename_root+"Off1.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);
    filename=filename_root+"Off2.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);
    filename=filename_root+"Off3.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);
    filename=filename_root+"Off4.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);
    filename=filename_root+"Off5.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);

  } else if (_sig_type=="On1234") {

    filename=filename_root+"On1.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);
    filename=filename_root+"On2.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);
    filename=filename_root+"On3.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);
    filename=filename_root+"On4*.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);

  } else if ((_sig_type=="btdkstarc")) {

    filename=filename_root+_sig_type+"1.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);
     filename=filename_root+_sig_type+"2.root";
     cout << "filename : " << filename << endl;
    tree->Add(filename);
    filename=filename_root+_sig_type+"3.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);
    filename=filename_root+_sig_type+"4.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);
    filename=filename_root+_sig_type+"5.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);

  } else {

    filename=filename_root+_sig_type+".root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);

  }

  } // end doReadRootuples

  cout<<"done"<<endl;
  Init(tree);

  //roomes = new RooRealVar("mes","mes",5.2,5.272);
  roomes = new RooRealVar("mes","mes",5.2,5.30);
  //roodemk = new RooRealVar("demk","demk",-0.060,0.100);
  roodemk = new RooRealVar("demk","demk",-0.120,0.120);
  roomassD0 = new RooRealVar("massD0","massD0",1.8645-0.040,1.8645+0.040);
  //roomassD0 = new RooRealVar("massD0","massD0",1.8645-0.012,1.8645+0.012);
  //roofisherDK = new RooRealVar("fisherDK","fisherDK",-2.1,2.1);
  roofisherDK = new RooRealVar("fisherDK","fisherDK",-1.0,1.0);
  roovars.addOwned(RooArgSet(*roomes,*roodemk,*roomassD0,*roofisherDK));

}


btdkstarc_final::~btdkstarc_final()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
   roovars.removeAll();
}

Int_t btdkstarc_final::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t btdkstarc_final::LoadTree(Long64_t entry)
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

void btdkstarc_final::Init(TTree *tree)
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

   fChain->SetBranchAddress("FoxWol2Neu",&FoxWol2Neu);
   fChain->SetBranchAddress("pxUps",&pxUps);
   fChain->SetBranchAddress("pyUps",&pyUps);
   fChain->SetBranchAddress("pzUps",&pzUps);
   fChain->SetBranchAddress("eUps",&eUps);
   fChain->SetBranchAddress("nMc",&nMc);
   fChain->SetBranchAddress("pMc",pMc);
   fChain->SetBranchAddress("thetaMc",thetaMc);
   fChain->SetBranchAddress("phiMc",phiMc);
   fChain->SetBranchAddress("idMc",idMc);
   fChain->SetBranchAddress("mothMc",mothMc);
   fChain->SetBranchAddress("nDauMc",nDauMc);
   fChain->SetBranchAddress("McEvtType",&McEvtType);
   fChain->SetBranchAddress("McNREvtType",&McNREvtType);
   fChain->SetBranchAddress("demk",&demk);
   fChain->SetBranchAddress("demk2",&demk2);
   fChain->SetBranchAddress("mes",&mes);
   fChain->SetBranchAddress("pxChB",&pxChB);
   fChain->SetBranchAddress("pyChB",&pyChB);
   fChain->SetBranchAddress("pzChB",&pzChB);
   fChain->SetBranchAddress("cosChBCM",&cosChBCM);
   fChain->SetBranchAddress("m0ChB",&m0ChB);
   fChain->SetBranchAddress("massChB",&massChB);
   fChain->SetBranchAddress("chi2ChB",&chi2ChB);
   fChain->SetBranchAddress("dofChB",&dofChB);
   fChain->SetBranchAddress("xChB",&xChB);
   fChain->SetBranchAddress("yChB",&yChB);
   fChain->SetBranchAddress("zChB",&zChB);
   fChain->SetBranchAddress("indexMcChB",&indexMcChB);
   fChain->SetBranchAddress("legendrep0",&legendrep0);
   fChain->SetBranchAddress("legendrep2",&legendrep2);
   fChain->SetBranchAddress("fisher",&fisher);
   fChain->SetBranchAddress("costhrust",&costhrust);
   fChain->SetBranchAddress("m0D0",&m0D0);
   fChain->SetBranchAddress("massD0",&massD0);
   fChain->SetBranchAddress("pcmsD0",&pcmsD0);
   fChain->SetBranchAddress("pxD0",&pxD0);
   fChain->SetBranchAddress("pyD0",&pyD0);
   fChain->SetBranchAddress("pzD0",&pzD0);
   fChain->SetBranchAddress("eD0",&eD0);
   fChain->SetBranchAddress("xD0",&xD0);
   fChain->SetBranchAddress("yD0",&yD0);
   fChain->SetBranchAddress("zD0",&zD0);
   fChain->SetBranchAddress("chi2D0",&chi2D0);
   fChain->SetBranchAddress("dofD0",&dofD0);
   fChain->SetBranchAddress("m2pDalitzD0",&m2pDalitzD0);
   fChain->SetBranchAddress("m2mDalitzD0",&m2mDalitzD0);
   fChain->SetBranchAddress("m2zDalitzD0",&m2zDalitzD0);
   fChain->SetBranchAddress("stDalitzD0",&stDalitzD0);
   fChain->SetBranchAddress("mTotDalitzD0",&mTotDalitzD0);
   fChain->SetBranchAddress("chi2DalitzD0",&chi2DalitzD0);
   fChain->SetBranchAddress("dofDalitzD0",&dofDalitzD0);
   fChain->SetBranchAddress("indexMcD0",&indexMcD0);
   fChain->SetBranchAddress("isMcD0",&isMcD0);
   fChain->SetBranchAddress("lundVectorc",&lundVectorc);
   fChain->SetBranchAddress("m0Vectorc",&m0Vectorc);
   fChain->SetBranchAddress("massVectorc",&massVectorc);
   fChain->SetBranchAddress("pxVectorc",&pxVectorc);
   fChain->SetBranchAddress("pyVectorc",&pyVectorc);
   fChain->SetBranchAddress("pzVectorc",&pzVectorc);
   fChain->SetBranchAddress("eVectorc",&eVectorc);
   fChain->SetBranchAddress("xVectorc",&xVectorc);
   fChain->SetBranchAddress("yVectorc",&yVectorc);
   fChain->SetBranchAddress("zVectorc",&zVectorc);
   fChain->SetBranchAddress("chi2Vectorc",&chi2Vectorc);
   fChain->SetBranchAddress("dofVectorc",&dofVectorc);
   fChain->SetBranchAddress("indexMcVectorc",&indexMcVectorc);
   fChain->SetBranchAddress("flagKspi",&flagKspi);
   fChain->SetBranchAddress("isMcVectorcResopic",&isMcVectorcResopic);
   fChain->SetBranchAddress("isMcKstarckcPi0",&isMcKstarckcPi0);
   fChain->SetBranchAddress("coseliVectorc",&coseliVectorc);
   fChain->SetBranchAddress("m0KstarcPi0",&m0KstarcPi0);
   fChain->SetBranchAddress("pxKstarcPi0",&pxKstarcPi0);
   fChain->SetBranchAddress("pyKstarcPi0",&pyKstarcPi0);
   fChain->SetBranchAddress("pzKstarcPi0",&pzKstarcPi0);
   fChain->SetBranchAddress("eKstarcPi0",&eKstarcPi0);
   fChain->SetBranchAddress("chi2KstarcPi0",&chi2KstarcPi0);
   fChain->SetBranchAddress("dofKstarcPi0",&dofKstarcPi0);
   fChain->SetBranchAddress("indexMcKstarcPi0",&indexMcKstarcPi0);
   fChain->SetBranchAddress("isMcKstarcPi0",&isMcKstarcPi0);
   fChain->SetBranchAddress("ecalKstarcPi0g1",&ecalKstarcPi0g1);
   fChain->SetBranchAddress("ecalxKstarcPi0g1",&ecalxKstarcPi0g1);
   fChain->SetBranchAddress("ecalyKstarcPi0g1",&ecalyKstarcPi0g1);
   fChain->SetBranchAddress("ecalzKstarcPi0g1",&ecalzKstarcPi0g1);
   fChain->SetBranchAddress("pxKstarcPi0g1",&pxKstarcPi0g1);
   fChain->SetBranchAddress("pyKstarcPi0g1",&pyKstarcPi0g1);
   fChain->SetBranchAddress("pzKstarcPi0g1",&pzKstarcPi0g1);
   fChain->SetBranchAddress("lmomKstarcPi0g1",&lmomKstarcPi0g1);
   fChain->SetBranchAddress("ncryKstarcPi0g1",&ncryKstarcPi0g1);
   fChain->SetBranchAddress("indexMcKstarcPi0g1",&indexMcKstarcPi0g1);
   fChain->SetBranchAddress("ecalKstarcPi0g2",&ecalKstarcPi0g2);
   fChain->SetBranchAddress("ecalxKstarcPi0g2",&ecalxKstarcPi0g2);
   fChain->SetBranchAddress("ecalyKstarcPi0g2",&ecalyKstarcPi0g2);
   fChain->SetBranchAddress("ecalzKstarcPi0g2",&ecalzKstarcPi0g2);
   fChain->SetBranchAddress("pxKstarcPi0g2",&pxKstarcPi0g2);
   fChain->SetBranchAddress("pyKstarcPi0g2",&pyKstarcPi0g2);
   fChain->SetBranchAddress("pzKstarcPi0g2",&pzKstarcPi0g2);
   fChain->SetBranchAddress("lmomKstarcPi0g2",&lmomKstarcPi0g2);
   fChain->SetBranchAddress("ncryKstarcPi0g2",&ncryKstarcPi0g2);
   fChain->SetBranchAddress("indexMcKstarcPi0g2",&indexMcKstarcPi0g2);
   fChain->SetBranchAddress("pxKstarckc",&pxKstarckc);
   fChain->SetBranchAddress("pyKstarckc",&pyKstarckc);
   fChain->SetBranchAddress("pzKstarckc",&pzKstarckc);
   fChain->SetBranchAddress("ctheKstarckc",&ctheKstarckc);
   fChain->SetBranchAddress("deltadrcmomKstarckc",&deltadrcmomKstarckc);
   fChain->SetBranchAddress("lundMcKstarckc",&lundMcKstarckc);
   fChain->SetBranchAddress("kaonidKstarckc",&kaonidKstarckc);
   fChain->SetBranchAddress("ndchKstarckc",&ndchKstarckc);
   fChain->SetBranchAddress("nphotKstarckc",&nphotKstarckc);
   fChain->SetBranchAddress("indexMcKstarckc",&indexMcKstarckc);
   fChain->SetBranchAddress("massVectorcReso",&massVectorcReso);
   fChain->SetBranchAddress("pxVectorcReso",&pxVectorcReso);
   fChain->SetBranchAddress("pyVectorcReso",&pyVectorcReso);
   fChain->SetBranchAddress("pzVectorcReso",&pzVectorcReso);
   fChain->SetBranchAddress("eVectorcReso",&eVectorcReso);
   fChain->SetBranchAddress("xVectorcReso",&xVectorcReso);
   fChain->SetBranchAddress("yVectorcReso",&yVectorcReso);
   fChain->SetBranchAddress("zVectorcReso",&zVectorcReso);
   fChain->SetBranchAddress("chi2VectorcReso",&chi2VectorcReso);
   fChain->SetBranchAddress("dofVectorcReso",&dofVectorcReso);
   fChain->SetBranchAddress("cosVectorcReso",&cosVectorcReso);
   fChain->SetBranchAddress("isMcVectorcReso",&isMcVectorcReso);
   fChain->SetBranchAddress("indexMcVectorcReso",&indexMcVectorcReso);
   fChain->SetBranchAddress("pxVectorcResoPi1",&pxVectorcResoPi1);
   fChain->SetBranchAddress("pyVectorcResoPi1",&pyVectorcResoPi1);
   fChain->SetBranchAddress("pzVectorcResoPi1",&pzVectorcResoPi1);
   fChain->SetBranchAddress("lundMcVectorcResoPi1",&lundMcVectorcResoPi1);
   fChain->SetBranchAddress("kaonidVectorcResoPi1",&kaonidVectorcResoPi1);
   fChain->SetBranchAddress("ndchVectorcResoPi1",&ndchVectorcResoPi1);
   fChain->SetBranchAddress("indexMcVectorcResoPi1",&indexMcVectorcResoPi1);
   fChain->SetBranchAddress("pxVectorcResoPi2",&pxVectorcResoPi2);
   fChain->SetBranchAddress("pyVectorcResoPi2",&pyVectorcResoPi2);
   fChain->SetBranchAddress("pzVectorcResoPi2",&pzVectorcResoPi2);
   fChain->SetBranchAddress("lundMcVectorcResoPi2",&lundMcVectorcResoPi2);
   fChain->SetBranchAddress("kaonidVectorcResoPi2",&kaonidVectorcResoPi2);
   fChain->SetBranchAddress("ndchVectorcResoPi2",&ndchVectorcResoPi2);
   fChain->SetBranchAddress("indexMcVectorcResoPi2",&indexMcVectorcResoPi2);
   fChain->SetBranchAddress("pxVectorcpic",&pxVectorcpic);
   fChain->SetBranchAddress("pyVectorcpic",&pyVectorcpic);
   fChain->SetBranchAddress("pzVectorcpic",&pzVectorcpic);
   fChain->SetBranchAddress("ctheVectorcpic",&ctheVectorcpic);
   fChain->SetBranchAddress("deltadrcmomVectorcpic",&deltadrcmomVectorcpic);
   fChain->SetBranchAddress("lundMcVectorcpic",&lundMcVectorcpic);
   fChain->SetBranchAddress("kaonidVectorcpic",&kaonidVectorcpic);
   fChain->SetBranchAddress("ndchVectorcpic",&ndchVectorcpic);
   fChain->SetBranchAddress("nphotVectorcpic",&nphotVectorcpic);
   fChain->SetBranchAddress("indexMcVectorcpic",&indexMcVectorcpic);
   fChain->SetBranchAddress("massKs",&massKs);
   fChain->SetBranchAddress("pxKs",&pxKs);
   fChain->SetBranchAddress("pyKs",&pyKs);
   fChain->SetBranchAddress("pzKs",&pzKs);
   fChain->SetBranchAddress("xKs",&xKs);
   fChain->SetBranchAddress("yKs",&yKs);
   fChain->SetBranchAddress("zKs",&zKs);
   fChain->SetBranchAddress("cosKs",&cosKs);
   fChain->SetBranchAddress("chi2Ks",&chi2Ks);
   fChain->SetBranchAddress("dofKs",&dofKs);
   fChain->SetBranchAddress("isMcKs",&isMcKs);
   fChain->SetBranchAddress("indexMcKs",&indexMcKs);
   fChain->SetBranchAddress("pxKsPi1",&pxKsPi1);
   fChain->SetBranchAddress("pyKsPi1",&pyKsPi1);
   fChain->SetBranchAddress("pzKsPi1",&pzKsPi1);
   fChain->SetBranchAddress("lundMcKsPi1",&lundMcKsPi1);
   fChain->SetBranchAddress("kaonidKsPi1",&kaonidKsPi1);
   fChain->SetBranchAddress("ndchKsPi1",&ndchKsPi1);
   fChain->SetBranchAddress("indexMcD0KsPi1",&indexMcD0KsPi1);
   fChain->SetBranchAddress("pxKsPi2",&pxKsPi2);
   fChain->SetBranchAddress("pyKsPi2",&pyKsPi2);
   fChain->SetBranchAddress("pzKsPi2",&pzKsPi2);
   fChain->SetBranchAddress("lundMcKsPi2",&lundMcKsPi2);
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

Bool_t btdkstarc_final::Notify()
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

   b_FoxWol2Neu = fChain->GetBranch("FoxWol2Neu");
   b_pxUps = fChain->GetBranch("pxUps");
   b_pyUps = fChain->GetBranch("pyUps");
   b_pzUps = fChain->GetBranch("pzUps");
   b_eUps = fChain->GetBranch("eUps");
   b_nMc = fChain->GetBranch("nMc");
   b_pMc = fChain->GetBranch("pMc");
   b_thetaMc = fChain->GetBranch("thetaMc");
   b_phiMc = fChain->GetBranch("phiMc");
   b_idMc = fChain->GetBranch("idMc");
   b_mothMc = fChain->GetBranch("mothMc");
   b_nDauMc = fChain->GetBranch("nDauMc");
   b_McEvtType = fChain->GetBranch("McEvtType");
   b_McNREvtType = fChain->GetBranch("McNREvtType");
   b_demk = fChain->GetBranch("demk");
   b_demk2 = fChain->GetBranch("demk2");
   b_mes = fChain->GetBranch("mes");
   b_pxChB = fChain->GetBranch("pxChB");
   b_pyChB = fChain->GetBranch("pyChB");
   b_pzChB = fChain->GetBranch("pzChB");
   b_cosChBCM = fChain->GetBranch("cosChBCM");
   b_m0ChB = fChain->GetBranch("m0ChB");
   b_massChB = fChain->GetBranch("massChB");
   b_chi2ChB = fChain->GetBranch("chi2ChB");
   b_dofChB = fChain->GetBranch("dofChB");
   b_xChB = fChain->GetBranch("xChB");
   b_yChB = fChain->GetBranch("yChB");
   b_zChB = fChain->GetBranch("zChB");
   b_indexMcChB = fChain->GetBranch("indexMcChB");
   b_legendrep0 = fChain->GetBranch("legendrep0");
   b_legendrep2 = fChain->GetBranch("legendrep2");
   b_fisher = fChain->GetBranch("fisher");
   b_costhrust = fChain->GetBranch("costhrust");
   b_m0D0 = fChain->GetBranch("m0D0");
   b_massD0 = fChain->GetBranch("massD0");
   b_pcmsD0 = fChain->GetBranch("pcmsD0");
   b_pxD0 = fChain->GetBranch("pxD0");
   b_pyD0 = fChain->GetBranch("pyD0");
   b_pzD0 = fChain->GetBranch("pzD0");
   b_eD0 = fChain->GetBranch("eD0");
   b_xD0 = fChain->GetBranch("xD0");
   b_yD0 = fChain->GetBranch("yD0");
   b_zD0 = fChain->GetBranch("zD0");
   b_chi2D0 = fChain->GetBranch("chi2D0");
   b_dofD0 = fChain->GetBranch("dofD0");
   b_m2pDalitzD0 = fChain->GetBranch("m2pDalitzD0");
   b_m2mDalitzD0 = fChain->GetBranch("m2mDalitzD0");
   b_m2zDalitzD0 = fChain->GetBranch("m2zDalitzD0");
   b_stDalitzD0 = fChain->GetBranch("stDalitzD0");
   b_mTotDalitzD0 = fChain->GetBranch("mTotDalitzD0");
   b_chi2DalitzD0 = fChain->GetBranch("chi2DalitzD0");
   b_dofDalitzD0 = fChain->GetBranch("dofDalitzD0");
   b_indexMcD0 = fChain->GetBranch("indexMcD0");
   b_isMcD0 = fChain->GetBranch("isMcD0");
   b_lundVectorc = fChain->GetBranch("lundVectorc");
   b_m0Vectorc = fChain->GetBranch("m0Vectorc");
   b_massVectorc = fChain->GetBranch("massVectorc");
   b_pxVectorc = fChain->GetBranch("pxVectorc");
   b_pyVectorc = fChain->GetBranch("pyVectorc");
   b_pzVectorc = fChain->GetBranch("pzVectorc");
   b_eVectorc = fChain->GetBranch("eVectorc");
   b_xVectorc = fChain->GetBranch("xVectorc");
   b_yVectorc = fChain->GetBranch("yVectorc");
   b_zVectorc = fChain->GetBranch("zVectorc");
   b_chi2Vectorc = fChain->GetBranch("chi2Vectorc");
   b_dofVectorc = fChain->GetBranch("dofVectorc");
   b_indexMcVectorc = fChain->GetBranch("indexMcVectorc");
   b_flagKspi = fChain->GetBranch("flagKspi");
   b_isMcVectorcResopic = fChain->GetBranch("isMcVectorcResopic");
   b_isMcKstarckcPi0 = fChain->GetBranch("isMcKstarckcPi0");
   b_coseliVectorc = fChain->GetBranch("coseliVectorc");
   b_m0KstarcPi0 = fChain->GetBranch("m0KstarcPi0");
   b_pxKstarcPi0 = fChain->GetBranch("pxKstarcPi0");
   b_pyKstarcPi0 = fChain->GetBranch("pyKstarcPi0");
   b_pzKstarcPi0 = fChain->GetBranch("pzKstarcPi0");
   b_eKstarcPi0 = fChain->GetBranch("eKstarcPi0");
   b_chi2KstarcPi0 = fChain->GetBranch("chi2KstarcPi0");
   b_dofKstarcPi0 = fChain->GetBranch("dofKstarcPi0");
   b_indexMcKstarcPi0 = fChain->GetBranch("indexMcKstarcPi0");
   b_isMcKstarcPi0 = fChain->GetBranch("isMcKstarcPi0");
   b_ecalKstarcPi0g1 = fChain->GetBranch("ecalKstarcPi0g1");
   b_ecalxKstarcPi0g1 = fChain->GetBranch("ecalxKstarcPi0g1");
   b_ecalyKstarcPi0g1 = fChain->GetBranch("ecalyKstarcPi0g1");
   b_ecalzKstarcPi0g1 = fChain->GetBranch("ecalzKstarcPi0g1");
   b_pxKstarcPi0g1 = fChain->GetBranch("pxKstarcPi0g1");
   b_pyKstarcPi0g1 = fChain->GetBranch("pyKstarcPi0g1");
   b_pzyKstarcPi0g1 = fChain->GetBranch("pzKstarcPi0g1");
   b_lmomKstarcPi0g1 = fChain->GetBranch("lmomKstarcPi0g1");
   b_ncryKstarcPi0g1 = fChain->GetBranch("ncryKstarcPi0g1");
   b_indexMcKstarcPi0g1 = fChain->GetBranch("indexMcKstarcPi0g1");
   b_ecalKstarcPi0g2 = fChain->GetBranch("ecalKstarcPi0g2");
   b_ecalxKstarcPi0g2 = fChain->GetBranch("ecalxKstarcPi0g2");
   b_ecalyKstarcPi0g2 = fChain->GetBranch("ecalyKstarcPi0g2");
   b_ecalzKstarcPi0g2 = fChain->GetBranch("ecalzKstarcPi0g2");
   b_pxKstarcPi0g2 = fChain->GetBranch("pxKstarcPi0g2");
   b_pyKstarcPi0g2 = fChain->GetBranch("pyKstarcPi0g2");
   b_pzyKstarcPi0g2 = fChain->GetBranch("pzKstarcPi0g2");
   b_lmomKstarcPi0g2 = fChain->GetBranch("lmomKstarcPi0g2");
   b_ncryKstarcPi0g2 = fChain->GetBranch("ncryKstarcPi0g2");
   b_indexMcKstarcPi0g2 = fChain->GetBranch("indexMcKstarcPi0g2");
   b_pxKstarckc = fChain->GetBranch("pxKstarckc");
   b_pyKstarckc = fChain->GetBranch("pyKstarckc");
   b_pzKstarckc = fChain->GetBranch("pzKstarckc");
   b_ctheKstarckc = fChain->GetBranch("ctheKstarckc");
   b_deltadrcmomKstarckc = fChain->GetBranch("deltadrcmomKstarckc");
   b_lundMcKstarckc = fChain->GetBranch("lundMcKstarckc");
   b_kaonidKstarckc = fChain->GetBranch("kaonidKstarckc");
   b_ndchKstarckc = fChain->GetBranch("ndchKstarckc");
   b_nphotKstarckc = fChain->GetBranch("nphotKstarckc");
   b_indexMcKstarckc = fChain->GetBranch("indexMcKstarckc");
   b_massVectorcReso = fChain->GetBranch("massVectorcReso");
   b_pxVectorcReso = fChain->GetBranch("pxVectorcReso");
   b_pyVectorcReso = fChain->GetBranch("pyVectorcReso");
   b_pzVectorcReso = fChain->GetBranch("pzVectorcReso");
   b_eVectorcReso = fChain->GetBranch("eVectorcReso");
   b_xVectorcReso = fChain->GetBranch("xVectorcReso");
   b_yVectorcReso = fChain->GetBranch("yVectorcReso");
   b_zVectorcReso = fChain->GetBranch("zVectorcReso");
   b_chi2VectorcReso = fChain->GetBranch("chi2VectorcReso");
   b_dofVectorcReso = fChain->GetBranch("dofVectorcReso");
   b_cosVectorcReso = fChain->GetBranch("cosVectorcReso");
   b_isMcVectorcReso = fChain->GetBranch("isMcVectorcReso");
   b_indexMcVectorcReso = fChain->GetBranch("indexMcVectorcReso");
   b_pxVectorcResoPi1 = fChain->GetBranch("pxVectorcResoPi1");
   b_pyVectorcResoPi1 = fChain->GetBranch("pyVectorcResoPi1");
   b_pzVectorcResoPi1 = fChain->GetBranch("pzVectorcResoPi1");
   b_lundMcVectorcResoPi1 = fChain->GetBranch("lundMcVectorcResoPi1");
   b_kaonidVectorcResoPi1 = fChain->GetBranch("kaonidVectorcResoPi1");
   b_ndchVectorcResoPi1 = fChain->GetBranch("ndchVectorcResoPi1");
   b_indexMcVectorcResoPi1 = fChain->GetBranch("indexMcVectorcResoPi1");
   b_pxVectorcResoPi2 = fChain->GetBranch("pxVectorcResoPi2");
   b_pyVectorcResoPi2 = fChain->GetBranch("pyVectorcResoPi2");
   b_pzVectorcResoPi2 = fChain->GetBranch("pzVectorcResoPi2");
   b_lundMcVectorcResoPi2 = fChain->GetBranch("lundMcVectorcResoPi2");
   b_kaonidVectorcResoPi2 = fChain->GetBranch("kaonidVectorcResoPi2");
   b_ndchVectorcResoPi2 = fChain->GetBranch("ndchVectorcResoPi2");
   b_indexMcVectorcResoPi2 = fChain->GetBranch("indexMcVectorcResoPi2");
   b_pxVectorcpic = fChain->GetBranch("pxVectorcpic");
   b_pyVectorcpic = fChain->GetBranch("pyVectorcpic");
   b_pzVectorcpic = fChain->GetBranch("pzVectorcpic");
   b_ctheVectorcpic = fChain->GetBranch("ctheVectorcpic");
   b_deltadrcmomVectorcpic = fChain->GetBranch("deltadrcmomVectorcpic");
   b_lundMcVectorcpic = fChain->GetBranch("lundMcVectorcpic");
   b_kaonidVectorcpic = fChain->GetBranch("kaonidVectorcpic");
   b_ndchVectorcpic = fChain->GetBranch("ndchVectorcpic");
   b_nphotVectorcpic = fChain->GetBranch("nphotVectorcpic");
   b_indexMcVectorcpic = fChain->GetBranch("indexMcVectorcpic");
   b_massKs = fChain->GetBranch("massKs");
   b_pxKs = fChain->GetBranch("pxKs");
   b_pyKs = fChain->GetBranch("pyKs");
   b_pzKs = fChain->GetBranch("pzKs");
   b_xKs = fChain->GetBranch("xKs");
   b_yKs = fChain->GetBranch("yKs");
   b_zKs = fChain->GetBranch("zKs");
   b_cosKs = fChain->GetBranch("cosKs");
   b_chi2Ks = fChain->GetBranch("chi2Ks");
   b_dofKs = fChain->GetBranch("dofKs");
   b_isMcKs = fChain->GetBranch("isMcKs");
   b_indexMcKs = fChain->GetBranch("indexMcKs");
   b_pxKsPi1 = fChain->GetBranch("pxKsPi1");
   b_pyKsPi1 = fChain->GetBranch("pyKsPi1");
   b_pzKsPi1 = fChain->GetBranch("pzKsPi1");
   b_lundMcKsPi1 = fChain->GetBranch("lundMcKsPi1");
   b_kaonidKsPi1 = fChain->GetBranch("kaonidKsPi1");
   b_ndchKsPi1 = fChain->GetBranch("ndchKsPi1");
   b_indexMcD0KsPi1 = fChain->GetBranch("indexMcD0KsPi1");
   b_pxKsPi2 = fChain->GetBranch("pxKsPi2");
   b_pyKsPi2 = fChain->GetBranch("pyKsPi2");
   b_pzKsPi2 = fChain->GetBranch("pzKsPi2");
   b_lundMcKsPi2 = fChain->GetBranch("lundMcKsPi2");
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

void btdkstarc_final::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}


Int_t btdkstarc_final::Cut(Int_t cut_code, Bool_t Mctruth, Float_t fisher)
{
  // This function may be called from Loop.
  // returns  1 if entry is accepted.
  // returns -1 otherwise.

  //  Defining the code ..depending on signal type  and cut
  // cut_code =    0     Pre-Selection Cuts      100     All Cuts
  // cut_code =    1     2      3         4       5       6           7       8         9        10          11         12           13          14
  //              mes   demk   massD0  massKs    cosKs   cosKstarKs  kaonid  costhrust coshel massKstarc massVectorcReso m0KstarcPi0  probchi2D0  probchi2ChB
  //               
  // cut_code =   112 (mes and demk)

  probchi2ChB = TMath::Prob(chi2ChB,(Int_t)dofChB);
  probchi2D0 = TMath::Prob(chi2D0,(Int_t)dofD0);
  probchi2Vectorc = TMath::Prob(chi2Vectorc,(Int_t)dofVectorc);
  probchi2VectorcReso = TMath::Prob(chi2VectorcReso,(Int_t)dofVectorcReso);

  // cout<<"probchi2ChB="<<probchi2ChB<<endl;
  Float_t demk_cut = (_Kstarc_decay_code==1) ? 0.025 : 0.036;   // resolution: 0.011 : 0.018
  Float_t demk_lo = roodemk->getMin();
  Float_t demk_hi = roodemk->getMax();
  Float_t coshel_cut = (_Kstarc_decay_code==1) ? 0.35 : 0.4;   
  Float_t costhrust_cut = (_isCS==kFALSE) ? 0.8: 0.7;
  Float_t deltamVectorc_cut = (_Kstarc_decay_code==1) ? 0.055 : 0.060;  
  Float_t deltamD0_cut = (_Kstarc_decay_code==1 && _isCS==kFALSE)? 0.012 : (_Kstarc_decay_code!=1 && _isCS==kFALSE)? 0.012 : (_isCS==kTRUE)? 0.012: 0.; 
                           // we expect never have a cero value
  Float_t deltamKs_cut = (_Kstarc_decay_code==1) ? 0.009 : 0.009 ;
  Float_t deltamVectorcReso_cut = (_isCS==kFALSE) ? 0.009 : 0.150 ;
  Float_t deltamPi0_cut = 0.012 ;
  Float_t cosKs_cut = 0.99;
  Float_t cosVectorcReso_cut = 0.997;
  Float_t mes_cut = 5.272;
  Float_t mes_lo = roomes->getMin();
  Float_t mes_hi = roomes->getMax();
  Float_t mD0_nom=1.8645;
  Float_t mKs_nom= 0.4977;
  Float_t mVectorcReso_nom=(_isCS==kFALSE) ? 0.4977: 0.770;
  Float_t mVectorc_nom=(_isCS==kFALSE) ? 0.89166: 1.230;
  Float_t mVectorc_low =1.0;
  Float_t mVectorc_high =1.6;
  Float_t mPi0_nom=0.135;
  Float_t probchi2D0_cut = (_Kstarc_decay_code==1) ? 0. : 0.001 ;    
  Float_t probchi2ChB_cut = (_Kstarc_decay_code==1) ? 0. : 0.001 ;  // 0.001 : 0.10 stefano  // . : 0.001: my
  Float_t probchi2VectorcReso_cut = 0.01;  // only for control sample
  Float_t probchi2Vectorc_cut = 0.01; // only for control sample

  Float_t pGamma_cut = 0.050;
  Int_t pid_cut = 16384;

  Float_t fisher_cut = -0.1;

  //Float_t pVectorc = sqrt(pxVectorc*pxVectorc+pyVectorc*pyVectorc+pzVectorc*pzVectorc);

  // 1024: LH not a pion
  // 2048: LH very loose
  // 4096: LH loose
  // 8192: LH tight
  // 16384: LH very tight
  
  McEvt=(_sig_type==TString("btdkstarc") || _sig_type==TString("btda1") || _sig_type==TString("chb") || _sig_type==TString("chbNR") || _sig_type==TString("bbbar")) ? 
    (3673+196*_Kstarc_decay_code) : 0;
  McEvt2=(_sig_type==TString("btdkstarc") || _sig_type==TString("btda1") || _sig_type==TString("chb") || _sig_type==TString("chbNR") || _sig_type==TString("bbbar")) ? 
    (3673+196*_Kstarc_decay_code+1) : 0;

  //cout << McEvtType << " " << McEvt << " " << McEvt2 << endl;
  
  Bool_t isNREvt(kFALSE);
  if ( ((McNREvtType&1)==1) || ((McNREvtType&2)==2) ) isNREvt=kTRUE;
  //if (isNREvt) cout << "Non resonant signal event found..." << endl;
  if (_sig_type=="chbNR" && !isNREvt) return -1;
  if (_sig_type!="chbNR" && isNREvt) return -1;

  if (Mctruth && McEvtType!=McEvt && McEvtType!=McEvt2) return -1;
  
  if (cut_code==0) {  
    if ( fabs(costhrust)<costhrust_cut &&
	 (mes>=mes_lo && mes<=mes_hi) &&
	 (demk2>=demk_lo && demk2<=demk_hi)
	 )
      return 1;
    else return -1;
  } 
  //
  //The implementation of all the cuts
  //
  if (stDalitzD0!=0 || fabs(mTotDalitzD0-mD0_nom)!=0. || chi2DalitzD0<0.) return -1;
  
  Float_t pKstarcPi0g1(0.),pKstarcPi0g2(0.); 
  if (_Kstarc_decay_code==2 && flagKspi==0) {
    pKstarcPi0g1 = sqrt(pxKstarcPi0g1*pxKstarcPi0g1+pyKstarcPi0g1*pyKstarcPi0g1+pzKstarcPi0g1*pzKstarcPi0g1);
    pKstarcPi0g2 = sqrt(pxKstarcPi0g2*pxKstarcPi0g2+pyKstarcPi0g2*pyKstarcPi0g2+pzKstarcPi0g2*pzKstarcPi0g2);
    probchi2Pi0 = TMath::Prob(chi2KstarcPi0,(Int_t)dofKstarcPi0);
  }
  
  //Control Sample cuts
  if (
      (_isCS==kTRUE) &&
      //((cut_code==8)? kTRUE : fabs(costhrust)<costhrust_cut) &&
      ((cut_code==3)?  kTRUE : (cut_code==113)? ((massD0>(mD0_nom-0.040) && massD0<(mD0_nom-0.020)) || (massD0>(mD0_nom+0.020) && massD0<(mD0_nom+0.040))): fabs(massD0-mD0_nom)<deltamD0_cut) &&
      ((cut_code==4)? kTRUE : fabs(massKs-mKs_nom)<deltamKs_cut) &&
      ((cut_code==11)? kTRUE : fabs(massVectorcReso-mVectorcReso_nom)<deltamVectorcReso_cut) &&
      ((cut_code==5)? kTRUE : cosKs>cosKs_cut) &&
      ((cut_code==10)? kTRUE : (massVectorc>mVectorc_low && massVectorc<mVectorc_high)) &&
      //(cut_code==9? kTRUE : fabs(coseliVectorc)>coshel_cut) &&
      ((cut_code==2 || cut_code==112 || cut_code==113)? (demk2>=demk_lo && demk2<=demk_hi) : fabs(demk2)<demk_cut) &&
      ((cut_code==14)? kTRUE: (chi2ChB>=0 && probchi2ChB>probchi2ChB_cut))&&
      ((cut_code==13)? kTRUE: (chi2D0>=0 && probchi2D0>probchi2D0_cut))&&
      ((cut_code==15)? kTRUE: (chi2Vectorc>=0 && probchi2Vectorc > probchi2Vectorc_cut))&& 
      ((cut_code==16)? kTRUE: (chi2VectorcReso>=0 && probchi2VectorcReso > probchi2VectorcReso_cut))&& 
      ((cut_code==1 || cut_code==112 || cut_code==113)? (mes>=mes_lo && mes<=mes_hi) : mes>mes_cut) &&
      ((cut_code==111 || cut_code==112)? kTRUE : fisher>=fisher_cut)
      )
    return 1;

  //if(_isCS==kTRUE)
  //{
  //  switch(cut_code){
 //	
  //     case 1001:
 //	if(
 //	   fabs(costhrust)<costhrust_cut
 //	   )return 1;
 //	break;
   //    case 1002:
 //	if(
 //	   fabs(costhrust)<costhrust_cut &&
 //	   fabs(massKs-mKs_nom)<deltamKs_cut
 //	   )return 1;
 //	break;
    //   case 1003:
 //	if(
  //   fabs(costhrust)<costhrust_cut &&
  //   fabs(massKs-mKs_nom)<deltamKs_cut &&
  //  fabs(massD0-mD0_nom)<deltamD0_cut
	//   )return 1;
  //	break;
  //  case 1004:
  //if(
  //   fabs(costhrust)<costhrust_cut &&
  //   fabs(massKs-mKs_nom)<deltamKs_cut &&
  //   fabs(massD0-mD0_nom)<deltamD0_cut &&
  //   cosKs>cosKs_cut
  //   )return 1;
  //break;
  //  case 1005:
  //if(
  //   fabs(costhrust)<costhrust_cut &&
  //   fabs(massKs-mKs_nom)<deltamKs_cut &&
  //   fabs(massD0-mD0_nom)<deltamD0_cut &&
  //   cosKs>cosKs_cut &&
  //   fabs(massVectorcReso-mVectorcReso_nom)<deltamVectorcReso_cut
  //   )return 1;
  //break;
  //  case 1006:
  //if(
  //   fabs(costhrust)<costhrust_cut &&
  //   fabs(massKs-mKs_nom)<deltamKs_cut &&
  //   fabs(massD0-mD0_nom)<deltamD0_cut &&
  //   cosKs>cosKs_cut &&
  //   fabs(massVectorcReso-mVectorcReso_nom)<deltamVectorcReso_cut &&
  //   (massVectorc>mVectorc_low && massVectorc<mVectorc_high)
  //   )return 1;
  //break;
  //  case 1007:
  //if(
  //   fabs(costhrust)<costhrust_cut &&
  //   fabs(massKs-mKs_nom)<deltamKs_cut &&
  //   fabs(massD0-mD0_nom)<deltamD0_cut &&
  //   cosKs>cosKs_cut &&
  //   fabs(massVectorcReso-mVectorcReso_nom)<deltamVectorcReso_cut &&
  //   (massVectorc>mVectorc_low && massVectorc<mVectorc_high) &&
  //   (chi2D0>=0 && probchi2D0>probchi2D0_cut)
  //   )return 1;
  //break;
  //  case 1008:
  //if(
  //   fabs(costhrust)<costhrust_cut &&
  //   fabs(massKs-mKs_nom)<deltamKs_cut &&
  //   fabs(massD0-mD0_nom)<deltamD0_cut &&
  //   cosKs>cosKs_cut &&
  //   fabs(massVectorcReso-mVectorcReso_nom)<deltamVectorcReso_cut &&
  //   (massVectorc>mVectorc_low && massVectorc<mVectorc_high) &&
  //   (chi2D0>=0 && probchi2D0>probchi2D0_cut) &&
  //   (chi2VectorcReso>=0 && probchi2VectorcReso > probchi2VectorcReso_cut) 
  //   )return 1;
  //break;
  //  case 1009:
  //if(
  //   fabs(costhrust)<costhrust_cut &&
  //   fabs(massKs-mKs_nom)<deltamKs_cut &&
  //   fabs(massD0-mD0_nom)<deltamD0_cut &&
  //   cosKs>cosKs_cut &&
  //   fabs(massVectorcReso-mVectorcReso_nom)<deltamVectorcReso_cut &&
  //   (massVectorc>mVectorc_low && massVectorc<mVectorc_high) &&
  //   (chi2D0>=0 && probchi2D0>probchi2D0_cut) &&
  //   (chi2VectorcReso>=0 && probchi2VectorcReso > probchi2VectorcReso_cut) &&
  //   (chi2Vectorc>=0 && probchi2Vectorc > probchi2Vectorc_cut)
  //   )return 1;
  //break;
  //  case 1010:
  //if(
  //   fabs(costhrust)<costhrust_cut &&
  //   fabs(massKs-mKs_nom)<deltamKs_cut &&
  //   fabs(massD0-mD0_nom)<deltamD0_cut &&
  //   cosKs>cosKs_cut &&
  //   fabs(massVectorcReso-mVectorcReso_nom)<deltamVectorcReso_cut &&
  //   (massVectorc>mVectorc_low && massVectorc<mVectorc_high) &&
  //   (chi2D0>=0 && probchi2D0>probchi2D0_cut) &&
  //   (chi2VectorcReso>=0 && probchi2VectorcReso > probchi2VectorcReso_cut) &&
  //   (chi2Vectorc>=0 && probchi2Vectorc > probchi2Vectorc_cut) &&
  //   (chi2ChB>=0 && probchi2ChB>probchi2ChB_cut)
  //   )return 1;
  //break;
  //  case 1011:
  //if(
  //   fabs(costhrust)<costhrust_cut &&
  //   fabs(massKs-mKs_nom)<deltamKs_cut &&
  //   fabs(massD0-mD0_nom)<deltamD0_cut &&
  //   cosKs>cosKs_cut &&
  //   fabs(massVectorcReso-mVectorcReso_nom)<deltamVectorcReso_cut &&
  //   (massVectorc>mVectorc_low && massVectorc<mVectorc_high) &&
  //   (chi2D0>=0 && probchi2D0>probchi2D0_cut) &&
  //   (chi2VectorcReso>=0 && probchi2VectorcReso > probchi2VectorcReso_cut) &&
  //   (chi2Vectorc>=0 && probchi2Vectorc > probchi2Vectorc_cut) &&
  //   (chi2ChB>=0 && probchi2ChB>probchi2ChB_cut) &&
  //   fabs(demk2)<demk_cut
  //   )return 1;
  //break;
  //  case 1012:
  //if(
  //   fabs(costhrust)<costhrust_cut &&
  //   fabs(massKs-mKs_nom)<deltamKs_cut &&
  //   fabs(massD0-mD0_nom)<deltamD0_cut &&
  //   cosKs>cosKs_cut &&
  //   fabs(massVectorcReso-mVectorcReso_nom)<deltamVectorcReso_cut &&
  //   (massVectorc>mVectorc_low && massVectorc<mVectorc_high) &&
  //   (chi2D0>=0 && probchi2D0>probchi2D0_cut) &&
  //   (chi2VectorcReso>=0 && probchi2VectorcReso > probchi2VectorcReso_cut) &&
  //   (chi2Vectorc>=0 && probchi2Vectorc > probchi2Vectorc_cut) &&
  //   (chi2ChB>=0 && probchi2ChB>probchi2ChB_cut) &&
  //   fabs(demk2)<demk_cut &&
  //   mes>mes_cut
  //   )return 1;
  //break;
  //  }
  //  return -1;
  //}
 
    // decay Kspi
  if ( (_Kstarc_decay_code==1 && flagKspi==1 && _isCS==kFALSE) &&
       //(cut_code==8? kTRUE : fabs(costhrust)<costhrust_cut) &&
       //((cut_code==3 || cut_code==113)? kTRUE : fabs(massD0-mD0_nom)<deltamD0_cut) &&
       ((cut_code==113)? ((massD0>(mD0_nom-0.040) && massD0<(mD0_nom-0.020)) || (massD0>(mD0_nom+0.020) && massD0<(mD0_nom+0.040))): kTRUE) &&
       //(cut_code==4? kTRUE : fabs(massKs-mKs_nom)<deltamKs_cut) &&
       (cut_code==11? kTRUE : fabs(massVectorcReso-mVectorcReso_nom)<deltamVectorcReso_cut) &&
       (cut_code==5? kTRUE : cosKs>cosKs_cut) &&
       (cut_code==6? kTRUE : cosVectorcReso>cosVectorcReso_cut) &&
       (cut_code==10? kTRUE : fabs(massVectorc-mVectorc_nom)<deltamVectorc_cut) &&
       (cut_code==9? kTRUE : fabs(coseliVectorc)>coshel_cut) &&
       ((cut_code==2 || cut_code==112 || cut_code==113)? (demk2>=demk_lo && demk2<=demk_hi) : fabs(demk2)<demk_cut) &&
       (cut_code==14? kTRUE: (chi2ChB>=0 && probchi2ChB>probchi2ChB_cut))&&
       (cut_code==13?	kTRUE: (chi2D0>=0 && probchi2D0>probchi2D0_cut))&&
       ((cut_code==1 || cut_code==112 || cut_code==113 || cut_code==114)? (mes>=mes_lo && mes<=mes_hi) : mes>mes_cut)&&
       ((cut_code==111 || cut_code==112 || cut_code==113 || cut_code==114)? kTRUE : fisher>=fisher_cut)
       //(cut_code==3? (mes>=mes_lo && mes<=mes_hi) : mes>mes_cut)
       ) 
    return 1;



  // decay kPi0
  if ( (_Kstarc_decay_code==2 && flagKspi==0 && _isCS==kFALSE) &&
       (pKstarcPi0g1>pGamma_cut && pKstarcPi0g2>pGamma_cut) &&
       //(cut_code==8? kTRUE : fabs(costhrust)<costhrust_cut) &&
       (cut_code==3? kTRUE : fabs(massD0-mD0_nom)<deltamD0_cut) &&
       (cut_code==4? kTRUE : fabs(massKs-mKs_nom)<deltamKs_cut) &&
       (cut_code==12? kTRUE : fabs(m0KstarcPi0-mPi0_nom)<deltamPi0_cut) &&
       //(cut_code==12? kTRUE : probchi2Pi0>0.001) &&
       (cut_code==5? kTRUE : cosKs>cosKs_cut) &&
       (cut_code==7? kTRUE :((int(kaonidKstarckc)&pid_cut)==pid_cut)) && 
       (cut_code==10? kTRUE : fabs(massVectorc-mVectorc_nom)<deltamVectorc_cut) &&
       (cut_code==9? kTRUE : fabs(coseliVectorc)>coshel_cut) &&
       ((cut_code==2 || cut_code==112)? (demk2>=demk_lo && demk2<=demk_hi) : fabs(demk2)<demk_cut) &&
       (cut_code==14? kTRUE: (chi2ChB>=0 && probchi2ChB>probchi2ChB_cut))&&
       (cut_code==13?	kTRUE: (chi2D0>=0 && probchi2D0>probchi2D0_cut))&&
       ((cut_code==1 || cut_code==112)? (mes>=mes_lo && mes<=mes_hi) : mes>mes_cut )&&
       ((cut_code==111 || cut_code==112)? kTRUE : fisher>=fisher_cut)
       )
    return 1;
  return -1;
}



#endif // #ifdef btdkstarc_final_cxx
