#ifndef btdkpi_final_h
#define btdkpi_final_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <iostream>
#include <TLorentzVector.h>
#include <iomanip.h>
#include <fstream.h>
//#include <strstream.h>
#define BIT_ON( num ) ( 1 << num )

#include <map>
using std::map;

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
#include "RooFitModels/RooExponential.hh"

class btdkpi_final {
  TString _dtype;
  TString _dstar0mode;
  TString _d0mode;
  TString _sig_type;
  TString _super_sig_type;
  public :
    TTree          *fChain;   //!pointer to the analyzed TTree or TChain
  Int_t           fCurrent; //!current Tree number in a TChain
  
  
  Double_t        probChi2ChB;
  Double_t        probChi2D0;
  Double_t        probChi2Pi0;
  Double_t        probChi2Ks;
  Double_t        probChi2Dstar0;
  Double_t        deltadeltamd;
  Int_t           McEvt,McEvt2; 
  
  
  RooRealVar *roomes,*roodemk,*roomassD0,*roomassDstar0,*roofisherDK;
  RooArgSet roovars; 
  
  map< Int_t,TString > _map_pname;
  map< TString,Int_t > _map_stdhepid;
  map< Int_t,Int_t > _map_chg3; 
  map< Int_t,double > _map_ctau;

  // Declaration of leave types
   Int_t           event;
   Int_t           runNumber;
   Int_t           upperID;
   Int_t           lowerID;
   //Int_t           platform;
   //Int_t           partition;
   Float_t         FoxWol2Neu;
   Float_t         pxUps;
   Float_t         pyUps;
   Float_t         pzUps;
   Float_t         eUps;
   Int_t           nMc;  
   Int_t           idMc[300];   //[nMc]
   Int_t           mothMc[300];   //[nMc]
   Int_t           nDauMc[300];   //[nMc]
   Float_t         pMc[300];   //[nMc]
   Float_t         thetaMc[300];   //[nMc]
   Float_t         phiMc[300];   //[nMc]
   Int_t           McEvtType;
   Float_t         demk;
   Float_t         demk2;
   //Float_t         demp;
   Float_t         mes;
   Float_t         pxChB;
   Float_t         pyChB;
   Float_t         pzChB;
   Float_t         xChB;
   Float_t         yChB;
   Float_t         zChB;
   Float_t         cosChBCM;
   Float_t         m0ChB;
   Float_t         massChB;
   Float_t         chi2ChB;
   Float_t         dofChB;
   Int_t           indexMcChB;
   Float_t         legendrep0;
   Float_t         legendrep2;
   Float_t         fisher;
   Float_t         costhrust;
   Float_t         m0Dstar0;
   Float_t         massDstar0;
   Float_t         pxDstar0;
   Float_t         pyDstar0;
   Float_t         pzDstar0;
   Float_t         eDstar0;
   Float_t         chi2Dstar0;
   Float_t         dofDstar0;
   Int_t           flagD0Pi0;
   Int_t           indexMcDstar0;
   Int_t           isMcDstar0Gam;
   Int_t           isMcDstar0Pi0;
   Float_t         m0Dstar0Pi0;
   Float_t         pxDstar0Pi0;
   Float_t         pyDstar0Pi0;
   Float_t         pzDstar0Pi0;
   Float_t         eDstar0Pi0;
   Float_t         chi2Dstar0Pi0;
   Float_t         dofDstar0Pi0;
   Int_t           indexMcDstar0Pi0;
   Float_t         ecalDstar0Pi0g1;
   Float_t         ecalxDstar0Pi0g1;
   Float_t         ecalyDstar0Pi0g1;
   Float_t         ecalzDstar0Pi0g1;
   Float_t         pxDstar0Pi0g1;
   Float_t         pyDstar0Pi0g1;
   Float_t         pzDstar0Pi0g1;
   Float_t         lmomDstar0Pi0g1;
   Int_t           ncryDstar0Pi0g1;
   Int_t           indexMcDstar0Pi0g1;
   Float_t         ecalDstar0Pi0g2;
   Float_t         ecalxDstar0Pi0g2;
   Float_t         ecalyDstar0Pi0g2;
   Float_t         ecalzDstar0Pi0g2;
   Float_t         pxDstar0Pi0g2;
   Float_t         pyDstar0Pi0g2;
   Float_t         pzDstar0Pi0g2;
   Float_t         lmomDstar0Pi0g2;
   Int_t           ncryDstar0Pi0g2;
   Int_t           indexMcDstar0Pi0g2;
   Float_t         ecalDstar0Gam;
   Float_t         ecalxDstar0Gam;
   Float_t         ecalyDstar0Gam;
   Float_t         ecalzDstar0Gam;
   Float_t         pxDstar0Gam;
   Float_t         pyDstar0Gam;
   Float_t         pzDstar0Gam;
   Float_t         lmomDstar0Gam;
   Int_t           ncryDstar0Gam;
   Int_t           indexMcDstar0Gam;
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
   Float_t         m2pDalitzD0;
   Float_t         m2mDalitzD0;
   Float_t         m2zDalitzD0;
   Int_t           stDalitzD0;
   Float_t         mTotDalitzD0;
   Float_t         chi2DalitzD0;
   Int_t           dofDalitzD0;
   Int_t           indexMcD0;
   Int_t           isMcD0;
   Int_t           isMcD0Matched;
   Float_t         pxpr;
   Float_t         pypr;
   Float_t         pzpr;
   Float_t         cthepr;
   Float_t         deltadrcmompr;
   Int_t           lundpr;
   Int_t           kaonidpr;
   Int_t           ndchpr;
   Int_t           nphotpr;
   Int_t           lundMcpr;
   Int_t           indexMcpr;
   Float_t         decayLengthD0;  
   Float_t         mydecayLengthCovD0;
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
   UInt_t          kaonidKsPi1;
   UInt_t          ndchKsPi1;
   UInt_t          indexMcD0KsPi1;
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

   Float_t         fisherDK; // feb-2007
   Float_t SigdlKs; //mar-2009

   // List of branches
   TBranch        *b_event;   //!
   TBranch        *b_runNumber;   //!
   TBranch        *b_upperID;   //! */
   TBranch        *b_lowerID;   //! */
   //TBranch        *b_platform;   //! */
   //TBranch        *b_partition;   //! */
   TBranch        *b_FoxWol2Neu;   //!
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
   TBranch        *b_demk;   //!
   TBranch        *b_demk2;   //!
   //TBranch        *b_demp;   //!
   TBranch        *b_mes;   //!
   TBranch        *b_pxChB;   //!
   TBranch        *b_pyChB;   //!
   TBranch        *b_pzChB;   //!
   TBranch        *b_xChB;   //!
   TBranch        *b_yChB;   //!
   TBranch        *b_zChB;   //!
   TBranch        *b_cosChBCM;   //!
   TBranch        *b_m0ChB;   //!
   TBranch        *b_massChB;   //!
   TBranch        *b_chi2ChB;   //!
   TBranch        *b_dofChB;   //!
   TBranch        *b_indexMcChB;   //!
   TBranch        *b_legendrep0;   //!
   TBranch        *b_legendrep2;   //!
   TBranch        *b_fisher;   //!
   TBranch        *b_costhrust;   //!
   TBranch        *b_m0Dstar0;   //!
   TBranch        *b_massDstar0;   //!
   TBranch        *b_pxDstar0;   //!
   TBranch        *b_pyDstar0;   //!
   TBranch        *b_pzDstar0;   //!
   TBranch        *b_eDstar0;   //!
   TBranch        *b_chi2Dstar0;   //!
   TBranch        *b_dofDstar0;   //!
   TBranch        *b_flagD0Pi0;   //!
   TBranch        *b_indexMcDstar0;   //!
   TBranch        *b_isMcDstar0Gam;   //!
   TBranch        *b_isMcDstar0Pi0;   //!
   TBranch        *b_m0Dstar0Pi0;   //!
   TBranch        *b_pxDstar0Pi0;   //!
   TBranch        *b_pyDstar0Pi0;   //!
   TBranch        *b_pzDstar0Pi0;   //!
   TBranch        *b_eDstar0Pi0;   //!
   TBranch        *b_chi2Dstar0Pi0;   //!
   TBranch        *b_dofDstar0Pi0;   //!
   TBranch        *b_indexMcDstar0Pi0;   //!
   TBranch        *b_ecalDstar0Pi0g1;   //!
   TBranch        *b_ecalxDstar0Pi0g1;   //!
   TBranch        *b_ecalyDstar0Pi0g1;   //!
   TBranch        *b_ecalzDstar0Pi0g1;   //!
   TBranch        *b_pxDstar0Pi0g1;   //!
   TBranch        *b_pyDstar0Pi0g1;   //!
   TBranch        *b_pzyDstar0Pi0g1;   //!
   TBranch        *b_lmomDstar0Pi0g1;   //!
   TBranch        *b_ncryDstar0Pi0g1;   //!
   TBranch        *b_indexMcDstar0Pi0g1;   //!
   TBranch        *b_ecalDstar0Pi0g2;   //!
   TBranch        *b_ecalxDstar0Pi0g2;   //!
   TBranch        *b_ecalyDstar0Pi0g2;   //!
   TBranch        *b_ecalzDstar0Pi0g2;   //!
   TBranch        *b_pxDstar0Pi0g2;   //!
   TBranch        *b_pyDstar0Pi0g2;   //!
   TBranch        *b_pzyDstar0Pi0g2;   //!
   TBranch        *b_lmomDstar0Pi0g2;   //!
   TBranch        *b_ncryDstar0Pi0g2;   //!
   TBranch        *b_indexMcDstar0Pi0g2;   //!
   TBranch        *b_ecalDstar0Gam;   //!
   TBranch        *b_ecalxDstar0Gam;   //!
   TBranch        *b_ecalyDstar0Gam;   //!
   TBranch        *b_ecalzDstar0Gam;   //!
   TBranch        *b_pxDstar0Gam;   //!
   TBranch        *b_pyDstar0Gam;   //!
   TBranch        *b_pzyDstar0Gam;   //!
   TBranch        *b_lmomDstar0Gam;   //!
   TBranch        *b_ncryDstar0Gam;   //!
   TBranch        *b_indexMcDstar0Gam;   //!
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
   TBranch        *b_m2pDalitzD0;   //!
   TBranch        *b_m2mDalitzD0;   //!
   TBranch        *b_m2zDalitzD0; //!
   TBranch        *b_stDalitzD0;   //!
   TBranch        *b_mTotDalitzD0;   //!
   TBranch        *b_chi2DalitzD0;   //!
   TBranch        *b_dofDalitzD0;   //!
   TBranch        *b_indexMcD0;   //!
   TBranch        *b_isMcD0;   //!
   TBranch        *b_isMcD0Matched;   //!
   TBranch        *b_pxpr;   //!
   TBranch        *b_pypr;   //!
   TBranch        *b_pzpr;   //!
   TBranch        *b_cthepr;   //!
   TBranch        *b_deltadrcmompr;   //!
   TBranch        *b_lundpr;   //!
   TBranch        *b_kaonidpr;   //!
   TBranch        *b_ndchpr;   //!
   TBranch        *b_nphotpr;   //!
   TBranch        *b_lundMcpr;   //!
   TBranch        *b_indexMcpr;   //!
   TBranch        *b_mydecayLengthCovD0;//
   TBranch        *b_decayLengthD0;
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
  ////////////////////////////////////////////////////////////////
  
  //btdkpi_final(TString dtype, TString dstar0mode, TString d0mode, TString sig_type, TString release="analysis-30", Bool_t doReadRootuples=kTRUE);
   //  btdkpi_final(TString dtype, TString dstar0mode, TString d0mode, TString sig_type, TString release="analysis-32", Bool_t doReadRootuples=kTRUE);
   //  btdkpi_final(TString dtype, TString dstar0mode, TString d0mode, TString sig_type, TString release="rel-24", Bool_t doReadRootuples=kTRUE);
   //  btdkpi_final(TString dtype, TString dstar0mode, TString d0mode, TString sig_type, TString release="rel-18new", Bool_t doReadRootuples=kTRUE);
  btdkpi_final(TString dtype, TString dstar0mode, TString d0mode, TString sig_type, TString release="analysis-51", Bool_t doReadRootuples=kTRUE);
  virtual ~btdkpi_final();
  
  virtual Int_t    Cut(TString KorPi, Int_t cut_code, Bool_t mctruth=kFALSE);
  virtual Int_t    GetEntry(Long64_t entry);
  virtual Long64_t LoadTree(Long64_t entry);
  virtual void     Init(TTree *tree);
  virtual void     Loop(TString KorPi, Int_t cut_code, Long64_t nentries=0);
  virtual void     LoopBest(TString KorPi, Int_t cut_code, Long64_t nentries=0, Int_t opt=1);
  
  virtual Bool_t   Notify();
  virtual void     Show(Long64_t entry = -1);
  
  //virtual Double_t Rescaling(TLorentzVector& vks, TLorentzVector& vpi1, TLorentzVector& vpi2, Double_t M, Double_t mass1, Double_t mass2, Double_t mass3);
  virtual void     Fits(TString KorPi, Int_t cut_code, TString varname="");
  virtual RooAbsPdf* getPdf(TString KorPi, RooRealVar& var);

  // virtual void     bkg_tree(TString KorPi, ofstream& outfile2,Int_t ientry);              // OLD
  virtual void     bkg_tree(TString KorPi, ofstream& outfile2,Int_t ientry,Int_t index_B[]);
  virtual Int_t    bkg_tree_MC(TString KorPi, 
			       Int_t* chargedDauFirstB, Int_t* neutralDauFirstB, Int_t* chargedDauSoftFirstB, Int_t* neutralDauSoftFirstB,
			       Int_t* chargedDauSecondB, Int_t* neutralDauSecondB, Int_t* chargedDauSoftSecondB, Int_t* neutralDauSoftSecondB, 
			       ofstream& outfile,Int_t ientry);
  virtual void     giveMeDauVisible(Int_t indexMother, Int_t* chargedDau, Int_t* neutralDau, Int_t* chargedDauSoft, Int_t* neutralDauSoft); 
  virtual void     writeDecay(Int_t indexMother, ofstream& outfile);
  virtual Bool_t   indexExists(Int_t index, Int_t* listOfIndex);
  virtual Bool_t   isMcMother(Int_t indexMcMother, Int_t indexMcDau); 
  virtual Bool_t   isIdMcMother(Int_t idMcMother, Int_t indexMcDau); 
  virtual Bool_t   isIdMcMother(Int_t idMcMother1, Int_t idMcMother2, Int_t indexMcDau); 
  //virtual Int_t    bkg_tree_number(Int_t number, Int_t lundid, ofstream& outfile4, Int_t ientry);

  virtual void     giveMeDau(Int_t index,Int_t* dauarray);
  virtual void     giveMeDau(Int_t* motharray, Int_t id, Int_t* dauarray);
  virtual Double_t getchi(Float_t mPi0,Float_t mDstar0, Float_t mD0);
  Float_t CosHely(const TLorentzVector & P,const TLorentzVector & Q, const TLorentzVector & D);
  virtual void     dalVarsTruth(Int_t mcTruth,Float_t* dalVars);

  // read the PDT table
  void readPDT(const std::string fname);
  const char* getName(Int_t stdhepid);
  Int_t getStdhepid(const char* pname);
  Int_t getChg3(Int_t stdhepid);
  double getCtau(Int_t stdhepid);
  
};

#endif

#ifdef btdkpi_final_cxx

/*
  btdkpi_final::btdkpi_final(TTree *tree) {
  // if parameter tree is not specified (or zero), connect the file
  // used to generate this class and read the Tree.
  if (tree == 0) {
  TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/l/milanesd/work1/DK/reduced/btdkpi_kspipi_ccbar.root");
  if (!f) {
  f = new TFile("/l/milanesd/work1/DK/reduced/btdkpi_kspipi_ccbar.root");
  }
  tree = (TTree*)gDirectory->Get("T");  
  }
  Init(tree);
  }
*/

btdkpi_final::btdkpi_final(TString dtype, TString dstar0mode, TString d0mode, TString sig_type, TString release, Bool_t doReadRootuples)
{
  
  /////////////////////////////////////////////////////////////////
  //// dtype = Dstar0 or D0                                    ////
  //// dstar0mode  = d0gam, d0pi0, d0                          ////
  //// d0mode = kspipi, kskk                                   ////
  //// sig_type = uds, ccbar, ....                             ////   
  /////////////////////////////////////////////////////////////////
  
  _dtype=dtype;
  _dstar0mode=dstar0mode;
  _d0mode=d0mode;
  _sig_type=sig_type;
  _super_sig_type=_sig_type; // default value
  
  assert(_dtype=="Dstar0" || _dtype=="D0");
  assert( (_dtype=="D0" && _dstar0mode=="d0") || (_dtype=="Dstar0" && (_dstar0mode=="d0pi0"||_dstar0mode=="d0gam")) );
  assert(_d0mode=="kspipi" || _d0mode=="kskk");

  TChain* tree;
  if(release=="rel-18new"){tree= new TChain("R18new");}
  else{tree= new TChain(_dtype);}

  
  cout<<"reading event of type: "<<_sig_type<<"; for D type: "<<_dtype<<"; D*0 mode: "<<_dstar0mode<<"; D0 mode: "<<_d0mode<< endl;
  
  TString filename;
  TString filename_root;
  if (release=="analysis-26") filename_root="./prod-26/DK/reduced/";
  else if (release=="analysis-30") filename_root="./prod-31-skim18b/DK/reduced/";
  else if (release=="analysis-32") filename_root="./prod-32-skim18c/DK/reduced/";
  else if (release=="rel-24") filename_root="./validation-rel24/DK/reduced/";
  else if (release=="rel-18new") filename_root="./vali1/";
  // else if (release=="analysis-51") filename_root="./reduced/";
  else if (release=="analysis-51") filename_root="./root/";

  //filename_root += "AllEventsSkim/btdkpi_"+d0mode+"_";
  if(release=="rel-18new"){filename_root +="valireducednew18_"+d0mode+"_";} 
  else{filename_root += "btdkpi_"+d0mode+"_";}
  assert(_sig_type == "btdk"      || _sig_type == "btdsk"      ||
	 _sig_type == "btdk1234"  || 
	 _sig_type == "btdk1"     || _sig_type == "btdsk1"     ||
	 _sig_type == "btdk2"     || _sig_type == "btdsk2"     ||
	 _sig_type == "btdk3"     || _sig_type == "btdsk3"     ||
	 _sig_type == "btdk4"     || _sig_type == "btdsk4"     ||
	 _sig_type == "btdk5"     || _sig_type == "btdsk5"     ||
	 _sig_type == "btdk6"     || _sig_type == "btdsk6"     ||
	 _sig_type == "btdsk1234" || 
	 _sig_type == "btdpi"     || _sig_type == "btdspi"     ||
	 _sig_type == "btdpi1234" || _sig_type == "btdspi1234" ||
	 _sig_type == "btdpi1"    || _sig_type == "btdspi1"    ||
	 _sig_type == "btdpi2"    || _sig_type == "btdspi2"    ||
	 _sig_type == "btdpi3"    || _sig_type == "btdspi3"    ||
	 _sig_type == "btdpi4"    || _sig_type == "btdspi4"    ||
	 _sig_type == "btdpi5"    || _sig_type == "btdspi5"    ||
	 _sig_type == "btdpi6"    || _sig_type == "btdspi6"    ||
	 _sig_type == "chb"       ||
	 _sig_type == "chbk"      || _sig_type == "chbpi"      ||
	 _sig_type == "chbk1"     || _sig_type == "chbpi1"     ||
	 _sig_type == "b0b0bar"   || _sig_type == "ccbar"      ||
	 _sig_type=="uds"         || _sig_type == "udsccbar"   ||
	 _sig_type == "bbbar"     ||
	 _sig_type == "bbbarpi"   || _sig_type=="bbbark"       ||
	 _sig_type == "on"        || _sig_type == "off");


  if (doReadRootuples) {

    if (_sig_type=="on") {
      
      filename=filename_root+"on1.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
      filename=filename_root+"on2.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
      filename=filename_root+"on3.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
      filename=filename_root+"on4.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
      filename=filename_root+"on5.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
      filename=filename_root+"on6.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
      
      
    }if (_sig_type=="off") {
      
      filename=filename_root+"off1.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
      filename=filename_root+"off2.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
      filename=filename_root+"off3.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
      filename=filename_root+"off4.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
      filename=filename_root+"off5.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
      filename=filename_root+"off6.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
      
      
      // } else if (_sig_type=="off") {
      //filename=filename_root+"off1234.root";
      //cout << "filename : " << filename << endl;
      //tree->Add(filename);
      //filename=filename_root+"off5.root";
      //cout << "filename : " << filename << endl;
      //tree->Add(filename);
      
    } else if(_sig_type=="ccbar") {
      
      filename=filename_root+"ccbar1.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
      filename=filename_root+"ccbar2.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
      filename=filename_root+"ccbar3.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
      filename=filename_root+"ccbar4*.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
      filename=filename_root+"ccbar5*.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
      filename=filename_root+"ccbar6.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);

    } else if(_sig_type=="uds") {

      filename=filename_root+"uds1.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
      filename=filename_root+"uds2.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
      filename=filename_root+"uds3.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
      //run4 run5 v02 & v03
      filename=filename_root+"uds4_*.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
      filename=filename_root+"uds5_*.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
      filename=filename_root+"uds6.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);

    } else if(_sig_type=="b0b0bar"){

      filename=filename_root+"b0b0bar1.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
      filename=filename_root+"b0b0bar2.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
      filename=filename_root+"b0b0bar3.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
      filename=filename_root+"b0b0bar4.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
      filename=filename_root+"b0b0bar5.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
      filename=filename_root+"b0b0bar6.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);

    }else if(_sig_type=="chb"){

      filename=filename_root+"chb1.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
      filename=filename_root+"chb2.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
      filename=filename_root+"chb3.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
      filename=filename_root+"chb4.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
      filename=filename_root+"chb5.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
      filename=filename_root+"chb6.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);

    }else if(_sig_type=="chbk"){

      filename=filename_root+"chbk1234.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
      filename=filename_root+"chbk56.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);

    }else if(_sig_type=="chbpi"){

      filename=filename_root+"chbpi1234.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
      filename=filename_root+"chbpi56.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);

    } else if (_sig_type=="udsccbar") {

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

      filename=filename_root+"uds6.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);

      filename=filename_root+"ccbar1.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
      filename=filename_root+"ccbar2.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
      filename=filename_root+"ccbar3.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
      filename=filename_root+"ccbar4.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
      filename=filename_root+"ccbar5.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
      filename=filename_root+"ccbar6.root";
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
      filename=filename_root+"chb4.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
      filename=filename_root+"chb5.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
      filename=filename_root+"chb6.root";
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
      filename=filename_root+"b0b0bar4.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
      filename=filename_root+"b0b0bar5.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
      filename=filename_root+"b0b0bar6.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);


 /*    } else if ((_sig_type=="btdk")||(_sig_type=="btdsk")||(_sig_type=="btdpi")||(_sig_type=="btdspi")) { */
    
/*       filename=filename_root+_sig_type+"1234.root"; */
/*       cout << "filename : " << filename << endl; */
/*       tree->Add(filename); */
/*       filename=filename_root+_sig_type+"5.root"; */
/*       cout << "filename : " << filename << endl; */
/*       tree->Add(filename); */

/*     }else if(_sig_type=="btdk1234"){ */
/*       _super_sig_type="btdk"; */
/*       filename=filename_root+_sig_type+".root"; */
/*       cout << "filename : " << filename << endl; */
/*       tree->Add(filename); */
/*     }else if(_sig_type=="btdsk1234"){ */
/*       _super_sig_type="btdsk"; */
/*       filename=filename_root+_sig_type+".root"; */
/*       cout << "filename : " << filename << endl; */
/*       tree->Add(filename); */
/*     }else if(_sig_type=="btdpi1234"){ */
/*       _super_sig_type="btdpi"; */
/*       filename=filename_root+_sig_type+".root"; */
/*       cout << "filename : " << filename << endl; */
/*       tree->Add(filename); */


      //*******************************************************************************************
      
      //**************  An-51  ****************************************************

      //*******************************************************************************************
    
    }else if(_sig_type=="btdk"){
      _super_sig_type="btdk";
      filename=filename_root+"btdk1.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
      filename=filename_root+"btdk2.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
      filename=filename_root+"btdk3.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
      filename=filename_root+"btdk4.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
      filename=filename_root+"btdk5.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
      filename=filename_root+"btdk6.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    
    }else if(_sig_type=="btdsk"){
      _super_sig_type="btdsk";
      filename=filename_root+"btdsk1.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
      filename=filename_root+"btdsk2.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
      filename=filename_root+"btdsk3.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
      filename=filename_root+"btdsk4.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
      filename=filename_root+"btdsk5.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
      filename=filename_root+"btdsk6.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    
    }else if(_sig_type=="btdpi"){
      _super_sig_type="btdpi";
      filename=filename_root+"btdpi1.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
      filename=filename_root+"btdpi2.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
      filename=filename_root+"btdpi3.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
      filename=filename_root+"btdpi4.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
      filename=filename_root+"btdpi5.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
      filename=filename_root+"btdpi6.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    
    }else if(_sig_type=="btdspi"){
      _super_sig_type="btdspi";
      filename=filename_root+"btdspi1.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
      filename=filename_root+"btdspi2.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
      filename=filename_root+"btdspi3.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
      filename=filename_root+"btdspi4.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
      filename=filename_root+"btdspi5.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
      filename=filename_root+"btdspi6.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    
    }else if(_sig_type=="btdk1"){
      _super_sig_type="btdk";
      filename=filename_root+"btdk1.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    }else if(_sig_type=="btdk2"){
      _super_sig_type="btdk";
      filename=filename_root+"btdk2.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    }else if(_sig_type=="btdk3"){
      _super_sig_type="btdk";
      filename=filename_root+"btdk3.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    }else if(_sig_type=="btdk4"){
      _super_sig_type="btdk";
      filename=filename_root+"btdk4.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    }else if(_sig_type=="btdk5"){
      _super_sig_type="btdk";
      filename=filename_root+"btdk5.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    }else if(_sig_type=="btdk6"){
      _super_sig_type="btdk";
      filename=filename_root+"btdk6.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);

    }else if(_sig_type=="btdsk1"){
      _super_sig_type="btdsk";
      filename=filename_root+"btdsk1.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    }else if(_sig_type=="btdsk2"){
      _super_sig_type="btdsk";
      filename=filename_root+"btdsk2.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    }else if(_sig_type=="btdsk3"){
      _super_sig_type="btdsk";
      filename=filename_root+"btdsk3.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    }else if(_sig_type=="btdsk4"){
      _super_sig_type="btdsk";
      filename=filename_root+"btdsk4.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    }else if(_sig_type=="btdsk5"){
      _super_sig_type="btdsk";
      filename=filename_root+"btdsk5.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    }else if(_sig_type=="btdsk6"){
      _super_sig_type="btdsk";
      filename=filename_root+"btdsk6.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);

    } else if(_sig_type=="btdpi1"){
      _super_sig_type="btdpi";
      filename=filename_root+_sig_type+".root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    } else if(_sig_type=="btdpi2"){
      _super_sig_type="btdpi";
      filename=filename_root+_sig_type+".root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    } else if(_sig_type=="btdpi3"){
      _super_sig_type="btdpi";
      filename=filename_root+_sig_type+".root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    } else if(_sig_type=="btdpi4"){
      _super_sig_type="btdpi";
      filename=filename_root+_sig_type+".root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    } else if(_sig_type=="btdpi5"){
      _super_sig_type="btdpi";
      filename=filename_root+_sig_type+".root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    } else if(_sig_type=="btdpi6"){
      _super_sig_type="btdpi";
      filename=filename_root+_sig_type+".root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);

    }else if(_sig_type=="btdspi1"){
      _super_sig_type="btdspi";
      filename=filename_root+_sig_type+".root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    }else if(_sig_type=="btdspi2"){
      _super_sig_type="btdspi";
      filename=filename_root+_sig_type+".root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    }else if(_sig_type=="btdspi3"){
      _super_sig_type="btdspi";
      filename=filename_root+_sig_type+".root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    }else if(_sig_type=="btdspi4"){
      _super_sig_type="btdspi";
      filename=filename_root+_sig_type+".root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    }else if(_sig_type=="btdspi5"){
      _super_sig_type="btdspi";
      filename=filename_root+_sig_type+".root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    }else if(_sig_type=="btdspi6"){
      _super_sig_type="btdspi";
      filename=filename_root+_sig_type+".root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    }

      //********************************************************************************************************
      //*********************************************** END SIGNAL an-50 ***********************************************
      //********************************************************************************************************

    
/*     }else if(_sig_type=="btdk"){ */
/*       _super_sig_type="btdk"; */
/*       filename=filename_root+"btdk1234.root"; */
/*       cout << "filename : " << filename << endl; */
/*       tree->Add(filename); */
/*       filename=filename_root+"btdk5.root"; */
/*       cout << "filename : " << filename << endl; */
/*       tree->Add(filename); */
/*     }else if(_sig_type=="btdk1234"){ */
/*       _super_sig_type="btdk"; */
/*       filename=filename_root+_sig_type+".root"; */
/*       cout << "filename : " << filename << endl; */
/*       tree->Add(filename); */
/*     }else if(_sig_type=="btdsk1234"){ */
/*       _super_sig_type="btdsk"; */
/*       filename=filename_root+_sig_type+".root"; */
/*       cout << "filename : " << filename << endl; */
/*       tree->Add(filename); */
/*     }else if(_sig_type=="btdpi1234"){ */
/*       _super_sig_type="btdpi"; */
/*       filename=filename_root+_sig_type+".root"; */
/*       cout << "filename : " << filename << endl; */
/*       tree->Add(filename); */
/*     }else if(_sig_type=="btdspi1234"){ */
/*       _super_sig_type="btdspi"; */
/*       filename=filename_root+_sig_type+".root"; */
/*       cout << "filename : " << filename << endl; */
/*       tree->Add(filename); */
/*     }     */
    
    
    
    cout<<"done"<<endl;
    Init(tree);
    
    roomes = new RooRealVar("mes","mes",5.20,5.30);
    //roodemk = new RooRealVar("demk","demk",-0.080,0.120);
    roodemk = new RooRealVar("demk","demk",-0.120,0.120);
    roomassD0 = new RooRealVar("massD0","massD0",1.8645-0.040,1.8645+0.040);
    roomassDstar0 = new RooRealVar("massDstar0","massDstar0",1.980,2.030);
    //  roofisherDK = new RooRealVar("fisherDK","fisherDK",-2.1,2.1);
    //roofisherDK = new RooRealVar("fisherDK","fisherDK",-1.0,1.0);
    roofisherDK = new RooRealVar("fisherDK","fisherDK",-1.4,1.4); //an-51 (not imp, as all the range is dumped in the .dat file)
    roovars.addOwned(RooArgSet(*roomes,*roodemk,*roomassD0,*roomassDstar0,*roofisherDK));
    
    // load PDT table
    readPDT("evt.pdl");
  }
  
}
btdkpi_final::~btdkpi_final()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
   roovars.removeAll();
}

Int_t btdkpi_final::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}

Long64_t btdkpi_final::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->IsA() != TChain::Class()) return centry;
   TChain *chain = (TChain*)fChain;
   if (chain->GetTreeNumber() != fCurrent) 
     {
       fCurrent = chain->GetTreeNumber();
       Notify();
     }
   return centry;
}

void btdkpi_final::Init(TTree *tree)
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
   // fChain->SetBranchAddress("platform",&platform); 
   // fChain->SetBranchAddress("partition",&partition); 
   fChain->SetBranchAddress("FoxWol2Neu",&FoxWol2Neu);
   fChain->SetBranchAddress("pxUps",&pxUps);
   fChain->SetBranchAddress("pyUps",&pyUps);
   fChain->SetBranchAddress("pzUps",&pzUps);
   fChain->SetBranchAddress("eUps",&eUps);
   fChain->SetBranchAddress("nMc",&nMc);
   fChain->SetBranchAddress("idMc",&idMc);
   fChain->SetBranchAddress("mothMc",&mothMc);
   fChain->SetBranchAddress("nDauMc",&nDauMc);
   fChain->SetBranchAddress("pMc",&pMc);
   fChain->SetBranchAddress("thetaMc",&thetaMc);
   fChain->SetBranchAddress("phiMc",&phiMc);
   fChain->SetBranchAddress("McEvtType",&McEvtType);
   fChain->SetBranchAddress("demk",&demk);
   fChain->SetBranchAddress("demk2",&demk2);
   //fChain->SetBranchAddress("demp",&demp);
   fChain->SetBranchAddress("mes",&mes);
   fChain->SetBranchAddress("pxChB",&pxChB);
   fChain->SetBranchAddress("pyChB",&pyChB);
   fChain->SetBranchAddress("pzChB",&pzChB);
   fChain->SetBranchAddress("xChB",&xChB);
   fChain->SetBranchAddress("yChB",&yChB);
   fChain->SetBranchAddress("zChB",&zChB);
   fChain->SetBranchAddress("cosChBCM",&cosChBCM);
   fChain->SetBranchAddress("m0ChB",&m0ChB);
   fChain->SetBranchAddress("massChB",&massChB);
   fChain->SetBranchAddress("chi2ChB",&chi2ChB);
   fChain->SetBranchAddress("dofChB",&dofChB);
   fChain->SetBranchAddress("indexMcChB",&indexMcChB);
   fChain->SetBranchAddress("legendrep0",&legendrep0);
   fChain->SetBranchAddress("legendrep2",&legendrep2);
   fChain->SetBranchAddress("fisher",&fisher);
   fChain->SetBranchAddress("costhrust",&costhrust);
   fChain->SetBranchAddress("m0Dstar0",&m0Dstar0);
   fChain->SetBranchAddress("massDstar0",&massDstar0);
   fChain->SetBranchAddress("pxDstar0",&pxDstar0);
   fChain->SetBranchAddress("pyDstar0",&pyDstar0);
   fChain->SetBranchAddress("pzDstar0",&pzDstar0);
   fChain->SetBranchAddress("eDstar0",&eDstar0);
   fChain->SetBranchAddress("chi2Dstar0",&chi2Dstar0);
   fChain->SetBranchAddress("dofDstar0",&dofDstar0);
   fChain->SetBranchAddress("flagD0Pi0",&flagD0Pi0);
   fChain->SetBranchAddress("indexMcDstar0",&indexMcDstar0);
   fChain->SetBranchAddress("isMcDstar0Gam",&isMcDstar0Gam);
   fChain->SetBranchAddress("isMcDstar0Pi0",&isMcDstar0Pi0);
   fChain->SetBranchAddress("m0Dstar0Pi0",&m0Dstar0Pi0);
   fChain->SetBranchAddress("pxDstar0Pi0",&pxDstar0Pi0);
   fChain->SetBranchAddress("pyDstar0Pi0",&pyDstar0Pi0);
   fChain->SetBranchAddress("pzDstar0Pi0",&pzDstar0Pi0);
   fChain->SetBranchAddress("eDstar0Pi0",&eDstar0Pi0);
   fChain->SetBranchAddress("chi2Dstar0Pi0",&chi2Dstar0Pi0);
   fChain->SetBranchAddress("dofDstar0Pi0",&dofDstar0Pi0);
   fChain->SetBranchAddress("indexMcDstar0Pi0",&indexMcDstar0Pi0);
   fChain->SetBranchAddress("ecalDstar0Pi0g1",&ecalDstar0Pi0g1);
   fChain->SetBranchAddress("ecalxDstar0Pi0g1",&ecalxDstar0Pi0g1);
   fChain->SetBranchAddress("ecalyDstar0Pi0g1",&ecalyDstar0Pi0g1);
   fChain->SetBranchAddress("ecalzDstar0Pi0g1",&ecalzDstar0Pi0g1);
   fChain->SetBranchAddress("pxDstar0Pi0g1",&pxDstar0Pi0g1);
   fChain->SetBranchAddress("pyDstar0Pi0g1",&pyDstar0Pi0g1);
   fChain->SetBranchAddress("pzDstar0Pi0g1",&pzDstar0Pi0g1);
   fChain->SetBranchAddress("lmomDstar0Pi0g1",&lmomDstar0Pi0g1);
   fChain->SetBranchAddress("ncryDstar0Pi0g1",&ncryDstar0Pi0g1);
   fChain->SetBranchAddress("indexMcDstar0Pi0g1",&indexMcDstar0Pi0g1);
   fChain->SetBranchAddress("ecalDstar0Pi0g2",&ecalDstar0Pi0g2);
   fChain->SetBranchAddress("ecalxDstar0Pi0g2",&ecalxDstar0Pi0g2);
   fChain->SetBranchAddress("ecalyDstar0Pi0g2",&ecalyDstar0Pi0g2);
   fChain->SetBranchAddress("ecalzDstar0Pi0g2",&ecalzDstar0Pi0g2);
   fChain->SetBranchAddress("pxDstar0Pi0g2",&pxDstar0Pi0g2);
   fChain->SetBranchAddress("pyDstar0Pi0g2",&pyDstar0Pi0g2);
   fChain->SetBranchAddress("pzDstar0Pi0g2",&pzDstar0Pi0g2);
   fChain->SetBranchAddress("lmomDstar0Pi0g2",&lmomDstar0Pi0g2);
   fChain->SetBranchAddress("ncryDstar0Pi0g2",&ncryDstar0Pi0g2);
   fChain->SetBranchAddress("indexMcDstar0Pi0g2",&indexMcDstar0Pi0g2);
   fChain->SetBranchAddress("ecalDstar0Gam",&ecalDstar0Gam);
   fChain->SetBranchAddress("ecalxDstar0Gam",&ecalxDstar0Gam);
   fChain->SetBranchAddress("ecalyDstar0Gam",&ecalyDstar0Gam);
   fChain->SetBranchAddress("ecalzDstar0Gam",&ecalzDstar0Gam);
   fChain->SetBranchAddress("pxDstar0Gam",&pxDstar0Gam);
   fChain->SetBranchAddress("pyDstar0Gam",&pyDstar0Gam);
   fChain->SetBranchAddress("pzDstar0Gam",&pzDstar0Gam);
   fChain->SetBranchAddress("lmomDstar0Gam",&lmomDstar0Gam);
   fChain->SetBranchAddress("ncryDstar0Gam",&ncryDstar0Gam);
   fChain->SetBranchAddress("indexMcDstar0Gam",&indexMcDstar0Gam);
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
   fChain->SetBranchAddress("m2pDalitzD0",&m2pDalitzD0);
   fChain->SetBranchAddress("m2mDalitzD0",&m2mDalitzD0);
   fChain->SetBranchAddress("m2zDalitzD0",&m2zDalitzD0);
   fChain->SetBranchAddress("stDalitzD0",&stDalitzD0);
   fChain->SetBranchAddress("mTotDalitzD0",&mTotDalitzD0);
   fChain->SetBranchAddress("chi2DalitzD0",&chi2DalitzD0);
   fChain->SetBranchAddress("dofDalitzD0",&dofDalitzD0);
   fChain->SetBranchAddress("indexMcD0",&indexMcD0);
   fChain->SetBranchAddress("isMcD0",&isMcD0);
   fChain->SetBranchAddress("isMcD0Matched",&isMcD0Matched);
   fChain->SetBranchAddress("pxpr",&pxpr);
   fChain->SetBranchAddress("pypr",&pypr);
   fChain->SetBranchAddress("pzpr",&pzpr);
   fChain->SetBranchAddress("cthepr",&cthepr);
   fChain->SetBranchAddress("deltadrcmompr",&deltadrcmompr);
   fChain->SetBranchAddress("lundpr",&lundpr);
   fChain->SetBranchAddress("kaonidpr",&kaonidpr);
   fChain->SetBranchAddress("ndchpr",&ndchpr);
   fChain->SetBranchAddress("nphotpr",&nphotpr);
   fChain->SetBranchAddress("lundMcpr",&lundMcpr);
   fChain->SetBranchAddress("indexMcpr",&indexMcpr);
   fChain->SetBranchAddress("decayLengthD0",&decayLengthD0);
   fChain->SetBranchAddress("mydecayLengthCovD0",&mydecayLengthCovD0);
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

Bool_t btdkpi_final::Notify()
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
   b_FoxWol2Neu = fChain->GetBranch("FoxWol2Neu");
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
   b_demk = fChain->GetBranch("demk");
   b_demk2 = fChain->GetBranch("demk2");
   //b_demp = fChain->GetBranch("demp");
   b_mes = fChain->GetBranch("mes");
   b_pxChB = fChain->GetBranch("pxChB");
   b_pyChB = fChain->GetBranch("pyChB");
   b_pzChB = fChain->GetBranch("pzChB");
   b_xChB = fChain->GetBranch("xChB");
   b_yChB = fChain->GetBranch("yChB");
   b_zChB = fChain->GetBranch("zChB");
   b_cosChBCM = fChain->GetBranch("cosChBCM");
   b_m0ChB = fChain->GetBranch("m0ChB");
   b_massChB = fChain->GetBranch("massChB");
   b_chi2ChB = fChain->GetBranch("chi2ChB");
   b_dofChB = fChain->GetBranch("dofChB");
   b_indexMcChB = fChain->GetBranch("indexMcChB");
   b_legendrep0 = fChain->GetBranch("legendrep0");
   b_legendrep2 = fChain->GetBranch("legendrep2");
   b_fisher = fChain->GetBranch("fisher");
   b_costhrust = fChain->GetBranch("costhrust");
   b_m0Dstar0 = fChain->GetBranch("m0Dstar0");
   b_massDstar0 = fChain->GetBranch("massDstar0");
   b_pxDstar0 = fChain->GetBranch("pxDstar0");
   b_pyDstar0 = fChain->GetBranch("pyDstar0");
   b_pzDstar0 = fChain->GetBranch("pzDstar0");
   b_eDstar0 = fChain->GetBranch("eDstar0");
   b_chi2Dstar0 = fChain->GetBranch("chi2Dstar0");
   b_dofDstar0 = fChain->GetBranch("dofDstar0");
   b_flagD0Pi0 = fChain->GetBranch("flagD0Pi0");
   b_indexMcDstar0 = fChain->GetBranch("indexMcDstar0");
   b_isMcDstar0Gam = fChain->GetBranch("isMcDstar0Gam");
   b_isMcDstar0Pi0 = fChain->GetBranch("isMcDstar0Pi0");
   b_m0Dstar0Pi0 = fChain->GetBranch("m0Dstar0Pi0");
   b_pxDstar0Pi0 = fChain->GetBranch("pxDstar0Pi0");
   b_pyDstar0Pi0 = fChain->GetBranch("pyDstar0Pi0");
   b_pzDstar0Pi0 = fChain->GetBranch("pzDstar0Pi0");
   b_eDstar0Pi0 = fChain->GetBranch("eDstar0Pi0");
   b_chi2Dstar0Pi0 = fChain->GetBranch("chi2Dstar0Pi0");
   b_dofDstar0Pi0 = fChain->GetBranch("dofDstar0Pi0");
   b_indexMcDstar0Pi0 = fChain->GetBranch("indexMcDstar0Pi0");
   b_ecalDstar0Pi0g1 = fChain->GetBranch("ecalDstar0Pi0g1");
   b_ecalxDstar0Pi0g1 = fChain->GetBranch("ecalxDstar0Pi0g1");
   b_ecalyDstar0Pi0g1 = fChain->GetBranch("ecalyDstar0Pi0g1");
   b_ecalzDstar0Pi0g1 = fChain->GetBranch("ecalzDstar0Pi0g1");
   b_pxDstar0Pi0g1 = fChain->GetBranch("pxDstar0Pi0g1");
   b_pyDstar0Pi0g1 = fChain->GetBranch("pyDstar0Pi0g1");
   b_pzyDstar0Pi0g1 = fChain->GetBranch("pzDstar0Pi0g1");
   b_lmomDstar0Pi0g1 = fChain->GetBranch("lmomDstar0Pi0g1");
   b_ncryDstar0Pi0g1 = fChain->GetBranch("ncryDstar0Pi0g1");
   b_indexMcDstar0Pi0g1 = fChain->GetBranch("indexMcDstar0Pi0g1");
   b_ecalDstar0Pi0g2 = fChain->GetBranch("ecalDstar0Pi0g2");
   b_ecalxDstar0Pi0g2 = fChain->GetBranch("ecalxDstar0Pi0g2");
   b_ecalyDstar0Pi0g2 = fChain->GetBranch("ecalyDstar0Pi0g2");
   b_ecalzDstar0Pi0g2 = fChain->GetBranch("ecalzDstar0Pi0g2");
   b_pxDstar0Pi0g2 = fChain->GetBranch("pxDstar0Pi0g2");
   b_pyDstar0Pi0g2 = fChain->GetBranch("pyDstar0Pi0g2");
   b_pzyDstar0Pi0g2 = fChain->GetBranch("pzDstar0Pi0g2");
   b_lmomDstar0Pi0g2 = fChain->GetBranch("lmomDstar0Pi0g2");
   b_ncryDstar0Pi0g2 = fChain->GetBranch("ncryDstar0Pi0g2");
   b_indexMcDstar0Pi0g2 = fChain->GetBranch("indexMcDstar0Pi0g2");
   b_ecalDstar0Gam = fChain->GetBranch("ecalDstar0Gam");
   b_ecalxDstar0Gam = fChain->GetBranch("ecalxDstar0Gam");
   b_ecalyDstar0Gam = fChain->GetBranch("ecalyDstar0Gam");
   b_ecalzDstar0Gam = fChain->GetBranch("ecalzDstar0Gam");
   b_pxDstar0Gam = fChain->GetBranch("pxDstar0Gam");
   b_pyDstar0Gam = fChain->GetBranch("pyDstar0Gam");
   b_pzyDstar0Gam = fChain->GetBranch("pzDstar0Gam");
   b_lmomDstar0Gam = fChain->GetBranch("lmomDstar0Gam");
   b_ncryDstar0Gam = fChain->GetBranch("ncryDstar0Gam");
   b_indexMcDstar0Gam = fChain->GetBranch("indexMcDstar0Gam");
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
   b_m2pDalitzD0 = fChain->GetBranch("m2pDalitzD0");
   b_m2mDalitzD0 = fChain->GetBranch("m2mDalitzD0");
   b_m2zDalitzD0 = fChain->GetBranch("m2zDalitzD0");
   b_stDalitzD0 = fChain->GetBranch("stDalitzD0");
   b_mTotDalitzD0 = fChain->GetBranch("mTotDalitzD0");
   b_chi2DalitzD0 = fChain->GetBranch("chi2DalitzD0");
   b_dofDalitzD0 = fChain->GetBranch("dofDalitzD0");
   b_indexMcD0 = fChain->GetBranch("indexMcD0");
   b_isMcD0 = fChain->GetBranch("isMcD0");
   b_isMcD0Matched = fChain->GetBranch("isMcD0Matched");
   b_pxpr = fChain->GetBranch("pxpr");
   b_pypr = fChain->GetBranch("pypr");
   b_pzpr = fChain->GetBranch("pzpr");
   b_cthepr = fChain->GetBranch("cthepr");
   b_deltadrcmompr = fChain->GetBranch("deltadrcmompr");
   b_lundpr = fChain->GetBranch("lundpr");
   b_kaonidpr = fChain->GetBranch("kaonidpr");
   b_ndchpr = fChain->GetBranch("ndchpr");
   b_nphotpr = fChain->GetBranch("nphotpr");
   b_lundMcpr = fChain->GetBranch("lundMcpr");
   b_indexMcpr = fChain->GetBranch("indexMcpr");
   b_mydecayLengthCovD0 = fChain->GetBranch("mydecayLengthCovD0");
   b_decayLengthD0 = fChain->GetBranch("decayLengthD0");
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
   b_indexMcD0Pi1 = fChain->GetBranch("indexMcD0Pi");
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


void btdkpi_final::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}


//##################Cuts#####################

Int_t btdkpi_final::Cut(TString KorPi, Int_t cut_code, Bool_t mctruth)
{  
  // select channel
  if (_dstar0mode=="d0pi0" && !flagD0Pi0) return -1;
  if (_dstar0mode=="d0gam" && flagD0Pi0) return -1;
  if (_d0mode=="kspipi" && (abs(lundD0Pi1)!=211 || abs(lundD0Pi2)!=211)) return -1; // not really needed, but to make sure
  if (_d0mode=="kskk" && (abs(lundD0Pi1)!=321 || abs(lundD0Pi2)!=321)) return -1; // not really needed, but to make sure

  // This function may be called from Loop.
  // returns  1 if entry is accepted.
  // returns -1 otherwise.
  
  probChi2ChB = TMath::Prob(chi2ChB,(Int_t)dofChB);
  probChi2D0 = TMath::Prob(chi2D0,(Int_t)dofD0);
  probChi2Ks = TMath::Prob(chi2Ks,(Int_t)dofKs);
  probChi2Dstar0 = TMath::Prob(chi2Dstar0,(Int_t)dofDstar0);
  probChi2Pi0 = TMath::Prob(chi2Dstar0Pi0,(Int_t)dofDstar0Pi0);
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

  
 
  Float_t fisherDK_cut=-0.1; 

  Float_t demk_lo_cut = (KorPi=="k")? -0.030 : 0.020 ;   
  Float_t demk_hi_cut = (KorPi=="k")?  0.030 : 0.080 ;  
  Float_t demk_lo = roodemk->getMin();
  Float_t demk_hi = roodemk->getMax();
  Float_t costhrust_cut = 0.8;
  //Float_t costhrust_cut = 1.0; 

  Float_t deltamD0_cut = (_d0mode=="kspipi")? 0.012 : 0.012 ;
  //Float_t deltamD0_cut = (_d0mode=="kspipi")? 0.012 : 0.008 ;
  Float_t deltamKs_cut = 0.009 ;
  Float_t cosKs_cut = 0.99 ;
  Float_t mes_cut = 5.272 ;
  //Float_t mes_cut = 5.269 ;
  Float_t mes_lo = roomes->getMin();
  Float_t mes_hi = roomes->getMax();
  Float_t mD0_nom=1.8645;
  Float_t mKs_nom=0.4976;
  Float_t probChi2D0_cut =  0.;    
  Float_t probChi2ChB_cut = (_dtype=="D0")? 0. : 0. ; 
  Float_t chi2ChB_cut = (_dtype=="D0")? 0. : 0. ; 

  Float_t SigdlKs_cut= 10.; 
  

  //****************   PID with SMS
  //Int_t pid_cut_k = 8;
  //Int_t pid_cut_k_kskk_1k = 8;
  //Int_t pid_cut_k_kskk_2k = 16;
  //Int_t pid_cut_pi = 16 ; 
 // *************   PID with LH
 // Int_t pid_cut_pi = 1024 ;  
  //Int_t pid_cut_k = 16384;
  //Int_t pid_cut_k_kskk_2k = 1024;
 //old
  ////Int_t pid_cut_k_kskk_1k = 16384;
  ////Int_t pid_cut_k_kskk_1k = 1024;
  ////Int_t pid_cut_k_kskk_2k = 16384;
  //../old
  
  //***************  PID KM selector
   // SL 16777216
 // VT 268435456 
 // ST 536870912
  //    Int_t pid_cut_k = 536870912;
  //  Int_t pid_cut_k_kskk_2k = 16777216;
  //  Int_t pid_cut_pi = 16777216;



  //***************  PID BDT selector
 

  Int_t pid_cut_pi =524288; 
  Int_t pid_cut_k = 8388608;
  Int_t pid_cut_k_kskk_2k = 524288;
  
  
  Float_t deltadeltamd_cut = (_dstar0mode=="d0pi0") ? 0.0025 : 0.010;
  Float_t deltamd_nom = 0.14212; // PDG 2004, 2008
    
  // ... on the matching of D*0K/pi (D0pi0, D0gam)
  Int_t McEvt_base = 4+256+512+1024+2048;
  if (_dtype=="Dstar0") {
    if (_dstar0mode=="d0pi0") McEvt_base += 8+16;
    else if (_dstar0mode=="d0gam") McEvt_base += 32;
    else assert(0);
  }
  
  McEvt=0;
  McEvt2=0;
  if (_super_sig_type==TString("btdk")     || _super_sig_type==TString("btdsk")  ||
      _super_sig_type==TString("btdpi")    || _super_sig_type==TString("btdspi") || 
      _super_sig_type==TString("chb")      ||
      _super_sig_type==TString("chbk")     || _super_sig_type==TString("chbpi")  || 
      _super_sig_type==TString("bbbar")    ||
      _super_sig_type==TString("bbbarpi") || _super_sig_type==TString("bbbark"))
    {
      McEvt = McEvt_base + ((KorPi=="k")? 1 : 8192) ;
      McEvt2 = McEvt_base + ((KorPi=="k")? 2 : 16384) ;
    }
  
  //    cout << mcEvtType << " " << mcEvt << " " << mcEvt2 << " " << mctruth << endl;
  
  if (mctruth && McEvtType!=McEvt && McEvtType!=McEvt2) 
    {
      cout<<"mcEvtType diferente de mcEvt 1 y 2"<<endl;
      return -1;
    }
  
  // Selection

  deltadeltamd = (massDstar0-massD0) - deltamd_nom; 
  
  if (cut_code==0) {
    if (
	//(fabs(costhrust)<costhrust_cut) 
	//&&
	(mes>=mes_lo && mes<=mes_hi) &&
	(demk2>=demk_lo && demk2<=demk_hi))	 
      return 1;
    else return -1;
  } 




  //
  //The implementation of all the cuts
  //
  
  //cout << stDalitzD0 << " " << mTotDalitzD0 << " " << chi2DalitzD0 << endl;
  if (stDalitzD0!=0 || fabs(mTotDalitzD0-mD0_nom)!=0. || chi2DalitzD0<0.) return -1;

  //Float_t ppi0g1(0.),ppi0g2(0.); 
  //if (_dtype=="Dstar0" && _dstar0mode=="d0pi0") {
  //ppi0g1 = sqrt(pxdstar0pi0g1*pxdstar0pi0g1+pydstar0pi0g1*pydstar0pi0g1+pzdstar0pi0g1*pzdstar0pi0g1);
  //ppi0g2 = sqrt(pxdstar0pi0g2*pxdstar0pi0g2+pydstar0pi0g2*pydstar0pi0g2+pzdstar0pi0g2*pzdstar0pi0g2);
  //}

  //CUT114 for final fitting: all cuts except fisher and mes
  //CTU112 pdfshapes: all cuts except F,mes,DE
  //CUT113 bkg shapes extraction:  all cuts except F,mes,DE, nominalDmass, select sideband regions

  if   ( 
     
	// (cut_code==7? kTRUE : fabs(costhrust)<costhrust_cut)
	//&&
     (cut_code==4? kTRUE : fabs(massKs-mKs_nom)<deltamKs_cut)
     &&
     ((cut_code==3 || cut_code==113)? kTRUE : fabs(massD0-mD0_nom)<deltamD0_cut)
     &&
     ((cut_code==113 && _d0mode=="kspipi")? ((massD0>(mD0_nom-0.040) && massD0<(mD0_nom-0.020)) || (massD0>(mD0_nom+0.020) && massD0<(mD0_nom+0.040))): kTRUE)
     &&
      ((cut_code==113 && _d0mode=="kskk")? ((massD0>(mD0_nom-0.040) && massD0<(mD0_nom-0.014)) || (massD0>(mD0_nom+0.014) && massD0<(mD0_nom+0.040))): kTRUE)
     &&
     (_d0mode=="kspipi"? kTRUE :  (int(kaonidD0Pi1)&pid_cut_k_kskk_2k)==pid_cut_k_kskk_2k && (int(kaonidD0Pi2)&pid_cut_k_kskk_2k)==pid_cut_k_kskk_2k)
     &&
     (cut_code==5? kTRUE : cosKs>cosKs_cut)
      &&
     (cut_code==8? kTRUE : (chi2D0>=0. && probChi2D0>probChi2D0_cut))
     &&
     ( (_dtype=="D0" || (_dtype=="Dstar0"&&cut_code==10))? kTRUE : (fabs(deltadeltamd)<deltadeltamd_cut) )
     &&
     ( ( KorPi=="k" && (cut_code==6? kTRUE :((int(kaonidpr)&pid_cut_k)==pid_cut_k) ) ) ||
       ( KorPi=="pi" && (cut_code==6? kTRUE :!((int(kaonidpr)&pid_cut_pi)==pid_cut_pi)) ) )
     &&
     (cut_code==9? kTRUE: (chi2ChB>=chi2ChB_cut && probChi2ChB>probChi2ChB_cut) )
     &&
     (cut_code == 7? kTRUE: (SigdlKs>= SigdlKs_cut))
     &&
     ((cut_code==111 || cut_code==112 || cut_code==113 || cut_code==114 )? kTRUE : fisherDK>fisherDK_cut)
     &&
     ((cut_code==2 || cut_code==112 || cut_code==113 )? (demk2>=demk_lo && demk2<=demk_hi) : (demk2>=demk_lo_cut && demk2<=demk_hi_cut))
     &&
     ((cut_code==1 || cut_code==112 || cut_code==113 || cut_code==114 )? (mes>=mes_lo && mes<=mes_hi) : mes>mes_cut)

     )
    




/*   if( (mes>mes_cut) */
/*       && (demk2>=demk_lo_cut && demk2<=demk_hi_cut) */
/*       && (fisherDK>fisherDK_cut) */
/*       && (SigdlKs>= SigdlKs_cut) */
/*       && ((int(kaonidpr)&pid_cut_k)==pid_cut_k) */
/*       && (chi2ChB>=chi2ChB_cut && probChi2ChB>probChi2ChB_cut) */
/*       && (chi2D0>=0. && probChi2D0>probChi2D0_cut) */
/*       && (demk2>=demk_lo && demk2<=demk_hi)  */
/*       &&(mes>=mes_lo && mes<=mes_hi) */
/*       &&((int(kaonidD0Pi1)&pid_cut_k_kskk_2k)==pid_cut_k_kskk_2k && (int(kaonidD0Pi2)&pid_cut_k_kskk_2k)==pid_cut_k_kskk_2k) */
/*       && (cosKs>cosKs_cut) */
/*       && (fabs(massD0-mD0_nom)<deltamD0_cut) */
/*       && (fabs(massKs-mKs_nom)<deltamKs_cut)) */







    //   if /* (   */
/*      ((_d0mode=="kskk" && cut_code!=101 && cut_code!=102 && cut_code!=103)? ((int(kaonidD0Pi1)&pid_cut_k_kskk_2k)==pid_cut_k_kskk_2k && (int(kaonidD0Pi2)&pid_cut_k_kskk_2k)==pid_cut_k_kskk_2k) :kTRUE) */
/*      && */
/*      ((_dtype=="Dstar0" && cut_code!=101 && cut_code!=102 && cut_code!=103 && cut_code!=104 && cut_code!=105 && cut_code!=106 && cut_code!=1000)? (fabs(deltadeltamd)<deltadeltamd_cut): kTRUE) */
/*       && */
/*      (demk2>=demk_lo && demk2<=demk_hi) */
/*      && */
/*      (mes>=mes_lo && mes<=mes_hi) */
/*      && */
/*      (cut_code==101? fabs(massKs-mKs_nom)<deltamKs_cut */
/*       : kTRUE) */
/*      && */
/*      (cut_code==102? (fabs(massD0-mD0_nom)<deltamD0_cut */
/* 		      && fabs(massKs-mKs_nom)<deltamKs_cut) */
/*       : kTRUE) */
/*      && */
/*      (_d0mode=="kskk" && cut_code==103? (((int(kaonidD0Pi1)&pid_cut_k_kskk_2k)==pid_cut_k_kskk_2k && (int(kaonidD0Pi2)&pid_cut_k_kskk_2k)==pid_cut_k_kskk_2k) */
/* 					 &&fabs(massD0-mD0_nom)<deltamD0_cut */
/* 					 && fabs(massKs-mKs_nom)<deltamKs_cut) */
/*       : kTRUE) */
/*      && */
/*      (cut_code==104? (cosKs>cosKs_cut */
/* 		      && (fabs(massD0-mD0_nom)<deltamD0_cut) */
/* 		      && (fabs(massKs-mKs_nom)<deltamKs_cut)) */
/*       : kTRUE) */
/*      && */
/*       (cut_code==105? ((chi2D0>=0. && probChi2D0>probChi2D0_cut) */
/* 		       && cosKs>cosKs_cut */
/* 		       && (fabs(massD0-mD0_nom)<deltamD0_cut) */
/* 		       && (fabs(massKs-mKs_nom)<deltamKs_cut)) */
/*        : kTRUE) */
/*      && */
/*      (cut_code==106? ((chi2ChB>=chi2ChB_cut && probChi2ChB>probChi2ChB_cut) */
/* 		      && (chi2D0>=0. && probChi2D0>probChi2D0_cut) */
/* 		      && cosKs>cosKs_cut */
/* 		      && (fabs(massD0-mD0_nom)<deltamD0_cut) */
/* 		      && (fabs(massKs-mKs_nom)<deltamKs_cut)) */
/*       : kTRUE) */
/*      && */
/*      (cut_code==1000? ((fabs(deltadeltamd)<deltadeltamd_cut) */
/* 		       &&(chi2ChB>=chi2ChB_cut && probChi2ChB>probChi2ChB_cut) */
/* 		       && (chi2D0>=0. && probChi2D0>probChi2D0_cut) */
/* 		       && cosKs>cosKs_cut */
/* 		       && (fabs(massD0-mD0_nom)<deltamD0_cut) */
/* 		       && (fabs(massKs-mKs_nom)<deltamKs_cut)) */
/*       : kTRUE) */
/*      && */
/*      ( ( KorPi=="k" && (cut_code==107 ? ( ((int(kaonidpr)&pid_cut_k)==pid_cut_k) */
/* 					  && (chi2ChB>=chi2ChB_cut && probChi2ChB>probChi2ChB_cut) */
/* 					  && (chi2D0>=0. && probChi2D0>probChi2D0_cut) */
/* 					  && cosKs>cosKs_cut */
/* 					  && (fabs(massD0-mD0_nom)<deltamD0_cut) */
/* 					  && (fabs(massKs-mKs_nom)<deltamKs_cut)) */
/* 			: kTRUE) */
/* 	 )|| */
/*        ( KorPi=="pi" && (cut_code==107 ? (!((int(kaonidpr)&pid_cut_pi)==pid_cut_pi) */
/* 					  && (chi2ChB>=chi2ChB_cut && probChi2ChB>probChi2ChB_cut) */
/* 					  && (chi2D0>=0. && probChi2D0>probChi2D0_cut) */
/* 					  && cosKs>cosKs_cut */
/* 					  && (fabs(massD0-mD0_nom)<deltamD0_cut) */
/* 					  && (fabs(massKs-mKs_nom)<deltamKs_cut)) */
/* 			 : kTRUE) */
/* 	 ) ) */
/*      && */
/*      ( ( KorPi=="k" && (cut_code==108 ? ( SigdlKs>= SigdlKs_cut */
/* 					  && ((int(kaonidpr)&pid_cut_k)==pid_cut_k) */
/* 					  && (chi2ChB>=chi2ChB_cut && probChi2ChB>probChi2ChB_cut) */
/* 					  && (chi2D0>=0. && probChi2D0>probChi2D0_cut) */
/* 					  && cosKs>cosKs_cut */
/* 					  && (fabs(massD0-mD0_nom)<deltamD0_cut) */
/* 					  && (fabs(massKs-mKs_nom)<deltamKs_cut)) */
/* 			: kTRUE) */
/* 	 )|| */
/*        ( KorPi=="pi" && (cut_code==108 ? (SigdlKs>= SigdlKs_cut */
/* 					  && !((int(kaonidpr)&pid_cut_pi)==pid_cut_pi) */
/* 					  && (chi2ChB>=chi2ChB_cut && probChi2ChB>probChi2ChB_cut) */
/* 					  && (chi2D0>=0. && probChi2D0>probChi2D0_cut) */
/* 					  && cosKs>cosKs_cut */
/* 					  && (fabs(massD0-mD0_nom)<deltamD0_cut) */
/* 					  && (fabs(massKs-mKs_nom)<deltamKs_cut)) */
/* 			 : kTRUE) */
/* 	 ) ) */
/*        && */
/*      ( ( KorPi=="k" && (cut_code==109 ? ( fisherDK>fisherDK_cut */
/* 					  && SigdlKs>= SigdlKs_cut */
/* 					  && ((int(kaonidpr)&pid_cut_k)==pid_cut_k) */
/* 					  && (chi2ChB>=chi2ChB_cut && probChi2ChB>probChi2ChB_cut) */
/* 					  && (chi2D0>=0. && probChi2D0>probChi2D0_cut) */
/* 					  && cosKs>cosKs_cut */
/* 					  && (fabs(massD0-mD0_nom)<deltamD0_cut) */
/* 					    && (fabs(massKs-mKs_nom)<deltamKs_cut)) */
/* 			: kTRUE) */
/* 	 )|| */
/*        ( KorPi=="pi" && (cut_code==109 ? (fisherDK>fisherDK_cut */
/* 					  && SigdlKs>= SigdlKs_cut */
/* 					  && !((int(kaonidpr)&pid_cut_pi)==pid_cut_pi) */
/* 					  && (chi2ChB>=chi2ChB_cut && probChi2ChB>probChi2ChB_cut) */
/* 					  && (chi2D0>=0. && probChi2D0>probChi2D0_cut) */
/* 					  && cosKs>cosKs_cut */
/* 					    && (fabs(massD0-mD0_nom)<deltamD0_cut) */
/* 					  && (fabs(massKs-mKs_nom)<deltamKs_cut)) */
/* 			 : kTRUE) */
/* 	 ) ) */
/*      && */
/*      ( ( KorPi=="k" && (cut_code==110 ? ( (demk2>=demk_lo_cut && demk2<=demk_hi_cut) */
/* 					  && fisherDK>fisherDK_cut */
/* 					  && SigdlKs>= SigdlKs_cut */
/* 					  && ((int(kaonidpr)&pid_cut_k)==pid_cut_k) */
/* 					  && (chi2ChB>=chi2ChB_cut && probChi2ChB>probChi2ChB_cut) */
/* 					  && (chi2D0>=0. && probChi2D0>probChi2D0_cut) */
/* 					  && cosKs>cosKs_cut */
/* 					  && (fabs(massD0-mD0_nom)<deltamD0_cut) */
/* 					  && (fabs(massKs-mKs_nom)<deltamKs_cut)) */
/* 			: kTRUE) */
/* 	 )|| */
/*        ( KorPi=="pi" && (cut_code==110 ? ((demk2>=demk_lo_cut && demk2<=demk_hi_cut) */
/* 					  && fisherDK>fisherDK_cut */
/* 					  && SigdlKs>= SigdlKs_cut */
/* 					  && !((int(kaonidpr)&pid_cut_pi)==pid_cut_pi) */
/* 					  && (chi2ChB>=chi2ChB_cut && probChi2ChB>probChi2ChB_cut) */
/* 					  && (chi2D0>=0. && probChi2D0>probChi2D0_cut) */
/* 					  && cosKs>cosKs_cut */
/* 					  && (fabs(massD0-mD0_nom)<deltamD0_cut) */
/* 					  && (fabs(massKs-mKs_nom)<deltamKs_cut)) */
/* 			 : kTRUE) */
/* 	 ) ) */
/*      && */
/*        ( ( KorPi=="k" && (cut_code==111 ? ( mes>mes_cut */
/* 					     && (demk2>=demk_lo_cut && demk2<=demk_hi_cut) */
/* 					     && fisherDK>fisherDK_cut */
/* 					     && SigdlKs>= SigdlKs_cut */
/* 					     && ((int(kaonidpr)&pid_cut_k)==pid_cut_k) */
/* 					     && (chi2ChB>=chi2ChB_cut && probChi2ChB>probChi2ChB_cut) */
/* 					     && (chi2D0>=0. && probChi2D0>probChi2D0_cut) */
/* 					     && cosKs>cosKs_cut */
/* 					     && (fabs(massD0-mD0_nom)<deltamD0_cut) */
/* 					     && (fabs(massKs-mKs_nom)<deltamKs_cut) */
/* 					    //&&(fabs(costhrust)<costhrust_cut) */
/* 					    ) */
/* 			  : kTRUE) */
/* 	   )|| */
/* 	 ( KorPi=="pi" && (cut_code==111 ? ( mes>mes_cut */
/* 					     && (demk2>=demk_lo_cut && demk2<=demk_hi_cut) */
/* 					     && fisherDK>fisherDK_cut */
/* 					     && SigdlKs>= SigdlKs_cut */
/* 					     && !((int(kaonidpr)&pid_cut_pi)==pid_cut_pi) */
/* 					     && (chi2ChB>=chi2ChB_cut && probChi2ChB>probChi2ChB_cut) */
/* 					     && (chi2D0>=0. && probChi2D0>probChi2D0_cut) */
/* 					     && cosKs>cosKs_cut */
/* 					     && (fabs(massD0-mD0_nom)<deltamD0_cut) */
/* 					     && (fabs(massKs-mKs_nom)<deltamKs_cut) */
/* 					     //  &&(fabs(costhrust)<costhrust_cut) */
/* 					     ) */
/* 			   : kTRUE) */
/* 	   ) ) */
/*      ) */
    
    


    


    return 1;
  return -1;
} 
//

/*
// evaluate and apply momentum rescaling. The method in invasive in vks, vpi1, vpi2
Double_t btdkpi_final::Rescaling(TLorentzVector& vks, TLorentzVector& vpi1, TLorentzVector& vpi2, Double_t M, Double_t mass1, Double_t mass2, Double_t mass3) { 
  // cout<<"en el rescaling"<<endl; 
  //cout << mass1 << " " << mass2 << " " << mass3 << endl; 
  Double_t alpha(1.); 
  Double_t m1=mass1; 
  Double_t m2=mass2; 
  Double_t m3=mass3; 
  Double_t p1=vks.Vect().Mag(); 
  Double_t p2=vpi1.Vect().Mag(); 
  Double_t p3=vpi2.Vect().Mag(); 
  Double_t E1p=sqrt(m1*m1+alpha*alpha*p1*p1); 
  Double_t E2p=sqrt(m2*m2+alpha*alpha*p2*p2); 
  Double_t E3p=sqrt(m3*m3+alpha*alpha*p3*p3); 
  Double_t sumEp=E1p+E2p+E3p; 
  Double_t sumPx=vks.Px()+vpi1.Px()+vpi2.Px(); 
  Double_t sumPy=vks.Py()+vpi1.Py()+vpi2.Py(); 
  Double_t sumPz=vks.Pz()+vpi1.Pz()+vpi2.Pz(); 
  Double_t nominalMass=M; 
  Double_t lo(0.5),hi(1.5),me(1.0); 
  Double_t c_lo(-1e10),c_hi(1e10),c_me(0); 
  Double_t eps(1e-6); 
  Int_t iter(0); 
  while (fabs(c_lo-c_hi)>=eps) {   
    alpha = lo; 
    E1p=sqrt(m1*m1+alpha*alpha*p1*p1); 
    E2p=sqrt(m2*m2+alpha*alpha*p2*p2); 
    E3p=sqrt(m3*m3+alpha*alpha*p3*p3); 
    sumEp=E1p+E2p+E3p; 
    c_lo = sumEp*sumEp-alpha*alpha*(sumPx*sumPx+sumPy*sumPy+sumPz*sumPz)-nominalMass*nominalMass;  
    //if(c_lo>0.) cout<<"PANIC in btdkpi_final::Rescaling: c_lo>0. = "<<c_lo<<endl; 
    //assert(c_lo<=0.); 
    alpha = hi; 
    E1p=sqrt(m1*m1+alpha*alpha*p1*p1); 
    E2p=sqrt(m2*m2+alpha*alpha*p2*p2); 
    E3p=sqrt(m3*m3+alpha*alpha*p3*p3); 
    sumEp=E1p+E2p+E3p; 
    c_hi = sumEp*sumEp-alpha*alpha*(sumPx*sumPx+sumPy*sumPy+sumPz*sumPz)-nominalMass*nominalMass;  
    //if(c_hi<0.) cout<<"PANIC in btdkpi_final::Rescaling: c_hi<0. = "<<c_hi<<endl; 
    //assert(c_hi>=0.); 
    alpha = me;E1p=sqrt(m1*m1+alpha*alpha*p1*p1); 
    E2p=sqrt(m2*m2+alpha*alpha*p2*p2); 
    E3p=sqrt(m3*m3+alpha*alpha*p3*p3); 
    sumEp=E1p+E2p+E3p; 
    c_me = sumEp*sumEp-alpha*alpha*(sumPx*sumPx+sumPy*sumPy+sumPz*sumPz)-nominalMass*nominalMass;  
    (c_me<=0.)? lo=me : hi=me; 
    me=lo+0.5*(hi-lo); 
    iter++; 
    //cout<<iter<<endl; 
  } 
  Double_t alphaVal = alpha; 
  //cout << " Converged in " << iter << " iterations. Scaling factor = " << alphaVal << endl; 
  TVector3 vksVect(alphaVal*vks.Px(),alphaVal*vks.Py(),alphaVal*vks.Pz()); 
  vks.SetVect(vksVect); 
  vks.SetE(sqrt(m1*m1+vksVect.Mag2())); 
  TVector3 vpi1Vect(alphaVal*vpi1.Px(),alphaVal*vpi1.Py(),alphaVal*vpi1.Pz()); 
  vpi1.SetVect(vpi1Vect); 
  vpi1.SetE(sqrt(m2*m2+vpi1Vect.Mag2())); 
  TVector3 vpi2Vect(alphaVal*vpi2.Px(),alphaVal*vpi2.Py(),alphaVal*vpi2.Pz()); 
  vpi2.SetVect(vpi2Vect); 
  vpi2.SetE(sqrt(m3*m3+vpi2Vect.Mag2())); 
  return alphaVal; 
} 
*/

#endif // #ifdef btdkpi_final_cxx 
