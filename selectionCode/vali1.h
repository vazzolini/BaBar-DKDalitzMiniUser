//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed May 14 07:43:25 2008 by ROOT version 5.10/00f
// from TTree D0/Reduced ROOT tree
// found on file: btdkpi_kspipi_on1.root
//////////////////////////////////////////////////////////

#ifndef vali1_h
#define vali1_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

//addition
#include <iostream.h>    


class vali1 {

 TString _d0mode;
 TString _sample;
 TString _dtype;


public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leave types
   Int_t           event;
   Int_t           runNumber;
   Float_t         FoxWol2Neu;
   Int_t           lowerID;
   Int_t           upperID;
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
   Float_t         pxD0;
   Float_t         pyD0;
   Float_t         pzD0;
   Float_t         eD0;
   Float_t         pcmsD0;
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
   Float_t         effCorMcpr;
   Float_t         sEffCorMcpr;
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
   Float_t         effCorMcD0KsPi1;
   Float_t         sEffCorMcD0KsPi1;
   Float_t         pxKsPi2;
   Float_t         pyKsPi2;
   Float_t         pzKsPi2;
   Int_t           lundMcKsPi2;
   Int_t           lundKsPi2;
   Int_t           kaonidKsPi2;
   Int_t           ndchKsPi2;
   Int_t           indexMcD0KsPi2;
   Float_t         effCorMcD0KsPi2;
   Float_t         sEffCorMcD0KsPi2;
   Float_t         pxD0Pi1;
   Float_t         pyD0Pi1;
   Float_t         pzD0Pi1;
   Int_t           lundMcD0Pi1;
   Int_t           lundD0Pi1;
   Int_t           kaonidD0Pi1;
   Int_t           ndchD0Pi1;
   Int_t           indexMcD0Pi1;
   Float_t         effCorMcD0Pi1;
   Float_t         sEffCorMcD0Pi1;
   Float_t         pxD0Pi2;
   Float_t         pyD0Pi2;
   Float_t         pzD0Pi2;
   Int_t           lundMcD0Pi2;
   Int_t           lundD0Pi2;
   Int_t           kaonidD0Pi2;
   Int_t           ndchD0Pi2;
   Int_t           indexMcD0Pi2;
   Float_t         effCorMcD0Pi2;
   Float_t         sEffCorMcD0Pi2;

   // List of branches
   TBranch        *b_event;   //!
   TBranch        *b_runNumber;   //!
   TBranch        *b_FoxWol2Neu;   //!
   TBranch        *b_lowerID;   //!
   TBranch        *b_upperID;   //!
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
   TBranch        *b_pxD0;   //!
   TBranch        *b_pyD0;   //!
   TBranch        *b_pzD0;   //!
   TBranch        *b_eD0;   //!
   TBranch        *b_pcmsD0;   //!
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
   TBranch        *b_effCorMcpr;   //!
   TBranch        *b_sEffCorMcpr;   //!
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
   TBranch        *b_effCorMcD0KsPi1;   //!
   TBranch        *b_sEffCorMcD0KsPi1;   //!
   TBranch        *b_pxKsPi2;   //!
   TBranch        *b_pyKsPi2;   //!
   TBranch        *b_pzKsPi2;   //!
   TBranch        *b_lundMcKsPi2;   //!
   TBranch        *b_lundKsPi2;   //!
   TBranch        *b_kaonidKsPi2;   //!
   TBranch        *b_ndchKsPi2;   //!
   TBranch        *b_indexMcD0KsPi2;   //!
   TBranch        *b_effCorMcD0KsPi2;   //!
   TBranch        *b_sEffCorMcD0KsPi2;   //!
   TBranch        *b_pxD0Pi1;   //!
   TBranch        *b_pyD0Pi1;   //!
   TBranch        *b_pzD0Pi1;   //!
   TBranch        *b_lundMcD0Pi1;   //!
   TBranch        *b_lundD0Pi1;   //!
   TBranch        *b_kaonidD0Pi1;   //!
   TBranch        *b_ndchD0Pi1;   //!
   TBranch        *b_indexMcD0Pi1;   //!
   TBranch        *b_effCorMcD0Pi1;   //!
   TBranch        *b_sEffCorMcD0Pi1;   //!
   TBranch        *b_pxD0Pi2;   //!
   TBranch        *b_pyD0Pi2;   //!
   TBranch        *b_pzD0Pi2;   //!
   TBranch        *b_lundMcD0Pi2;   //!
   TBranch        *b_lundD0Pi2;   //!
   TBranch        *b_kaonidD0Pi2;   //!
   TBranch        *b_ndchD0Pi2;   //!
   TBranch        *b_indexMcD0Pi2;   //!
   TBranch        *b_effCorMcD0Pi2;   //!
   TBranch        *b_sEffCorMcD0Pi2;   //!

   //vali1(TTree *tree=0);
   
   vali1(TString d0mode,TString dtype, TString sample);
   ~vali1();
   Int_t    Cut(Long64_t entry);
   Int_t    GetEntry(Long64_t entry);
   Long64_t LoadTree(Long64_t entry);
   void     Init(TTree *tree);
   void     Loop(Int_t nentries=0);
   Bool_t   Notify();
   void     Show(Long64_t entry = -1);
};

#endif

#ifdef vali1_cxx

//vali1::vali1(TTree *tree)
//{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
//  if (tree == 0) {
//     TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("btdkpi_kspipi_on1.root");
//     if (!f) {
//        f = new TFile("btdkpi_kspipi_on1.root");
//     }
//     tree = (TTree*)gDirectory->Get("D0");

// }
//  Init(tree);
//}

vali1::vali1(TString d0mode,TString dtype,TString sample)
{
 _d0mode=d0mode;
 _sample=sample;
 _dtype=dtype;

  TChain* tree=new TChain(_dtype);
  TString filename="./prod-32-skim18c/DK/reduced/btdkpi_"+d0mode+"_";
  if(sample=="on1"){
    filename+="on1.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);
  }
  if(sample=="on2"){
    filename+="on2.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);
  }
  if(sample=="on3"){
    filename+="on3.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);
  }
  if(sample=="on4"){
    filename+="on4.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);
  }
  if(sample=="on5"){
    filename+="on5.root";
    cout << "filename : " << filename << endl;
    tree->Add(filename);
  }
  cout<<"loading root file " << filename << endl;
  cout<<"done"<<endl;
  
  Init(tree);

}


vali1::~vali1()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t vali1::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t vali1::LoadTree(Long64_t entry)
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

void vali1::Init(TTree *tree)
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
   fChain->SetBranchAddress("FoxWol2Neu",&FoxWol2Neu);
   fChain->SetBranchAddress("lowerID",&lowerID);
   fChain->SetBranchAddress("upperID",&upperID);
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
   fChain->SetBranchAddress("pxD0",&pxD0);
   fChain->SetBranchAddress("pyD0",&pyD0);
   fChain->SetBranchAddress("pzD0",&pzD0);
   fChain->SetBranchAddress("eD0",&eD0);
   fChain->SetBranchAddress("pcmsD0",&pcmsD0);
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
   fChain->SetBranchAddress("effCorMcpr",&effCorMcpr);
   fChain->SetBranchAddress("sEffCorMcpr",&sEffCorMcpr);
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
   fChain->SetBranchAddress("effCorMcD0KsPi1",&effCorMcD0KsPi1);
   fChain->SetBranchAddress("sEffCorMcD0KsPi1",&sEffCorMcD0KsPi1);
   fChain->SetBranchAddress("pxKsPi2",&pxKsPi2);
   fChain->SetBranchAddress("pyKsPi2",&pyKsPi2);
   fChain->SetBranchAddress("pzKsPi2",&pzKsPi2);
   fChain->SetBranchAddress("lundMcKsPi2",&lundMcKsPi2);
   fChain->SetBranchAddress("lundKsPi2",&lundKsPi2);
   fChain->SetBranchAddress("kaonidKsPi2",&kaonidKsPi2);
   fChain->SetBranchAddress("ndchKsPi2",&ndchKsPi2);
   fChain->SetBranchAddress("indexMcD0KsPi2",&indexMcD0KsPi2);
   fChain->SetBranchAddress("effCorMcD0KsPi2",&effCorMcD0KsPi2);
   fChain->SetBranchAddress("sEffCorMcD0KsPi2",&sEffCorMcD0KsPi2);
   fChain->SetBranchAddress("pxD0Pi1",&pxD0Pi1);
   fChain->SetBranchAddress("pyD0Pi1",&pyD0Pi1);
   fChain->SetBranchAddress("pzD0Pi1",&pzD0Pi1);
   fChain->SetBranchAddress("lundMcD0Pi1",&lundMcD0Pi1);
   fChain->SetBranchAddress("lundD0Pi1",&lundD0Pi1);
   fChain->SetBranchAddress("kaonidD0Pi1",&kaonidD0Pi1);
   fChain->SetBranchAddress("ndchD0Pi1",&ndchD0Pi1);
   fChain->SetBranchAddress("indexMcD0Pi1",&indexMcD0Pi1);
   fChain->SetBranchAddress("effCorMcD0Pi1",&effCorMcD0Pi1);
   fChain->SetBranchAddress("sEffCorMcD0Pi1",&sEffCorMcD0Pi1);
   fChain->SetBranchAddress("pxD0Pi2",&pxD0Pi2);
   fChain->SetBranchAddress("pyD0Pi2",&pyD0Pi2);
   fChain->SetBranchAddress("pzD0Pi2",&pzD0Pi2);
   fChain->SetBranchAddress("lundMcD0Pi2",&lundMcD0Pi2);
   fChain->SetBranchAddress("lundD0Pi2",&lundD0Pi2);
   fChain->SetBranchAddress("kaonidD0Pi2",&kaonidD0Pi2);
   fChain->SetBranchAddress("ndchD0Pi2",&ndchD0Pi2);
   fChain->SetBranchAddress("indexMcD0Pi2",&indexMcD0Pi2);
   fChain->SetBranchAddress("effCorMcD0Pi2",&effCorMcD0Pi2);
   fChain->SetBranchAddress("sEffCorMcD0Pi2",&sEffCorMcD0Pi2);
   Notify();
}

Bool_t vali1::Notify()
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
   b_lowerID = fChain->GetBranch("lowerID");
   b_upperID = fChain->GetBranch("upperID");
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
   b_pxD0 = fChain->GetBranch("pxD0");
   b_pyD0 = fChain->GetBranch("pyD0");
   b_pzD0 = fChain->GetBranch("pzD0");
   b_eD0 = fChain->GetBranch("eD0");
   b_pcmsD0 = fChain->GetBranch("pcmsD0");
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
   b_effCorMcpr = fChain->GetBranch("effCorMcpr");
   b_sEffCorMcpr = fChain->GetBranch("sEffCorMcpr");
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
   b_effCorMcD0KsPi1 = fChain->GetBranch("effCorMcD0KsPi1");
   b_sEffCorMcD0KsPi1 = fChain->GetBranch("sEffCorMcD0KsPi1");
   b_pxKsPi2 = fChain->GetBranch("pxKsPi2");
   b_pyKsPi2 = fChain->GetBranch("pyKsPi2");
   b_pzKsPi2 = fChain->GetBranch("pzKsPi2");
   b_lundMcKsPi2 = fChain->GetBranch("lundMcKsPi2");
   b_lundKsPi2 = fChain->GetBranch("lundKsPi2");
   b_kaonidKsPi2 = fChain->GetBranch("kaonidKsPi2");
   b_ndchKsPi2 = fChain->GetBranch("ndchKsPi2");
   b_indexMcD0KsPi2 = fChain->GetBranch("indexMcD0KsPi2");
   b_effCorMcD0KsPi2 = fChain->GetBranch("effCorMcD0KsPi2");
   b_sEffCorMcD0KsPi2 = fChain->GetBranch("sEffCorMcD0KsPi2");
   b_pxD0Pi1 = fChain->GetBranch("pxD0Pi1");
   b_pyD0Pi1 = fChain->GetBranch("pyD0Pi1");
   b_pzD0Pi1 = fChain->GetBranch("pzD0Pi1");
   b_lundMcD0Pi1 = fChain->GetBranch("lundMcD0Pi1");
   b_lundD0Pi1 = fChain->GetBranch("lundD0Pi1");
   b_kaonidD0Pi1 = fChain->GetBranch("kaonidD0Pi1");
   b_ndchD0Pi1 = fChain->GetBranch("ndchD0Pi1");
   b_indexMcD0Pi1 = fChain->GetBranch("indexMcD0Pi1");
   b_effCorMcD0Pi1 = fChain->GetBranch("effCorMcD0Pi1");
   b_sEffCorMcD0Pi1 = fChain->GetBranch("sEffCorMcD0Pi1");
   b_pxD0Pi2 = fChain->GetBranch("pxD0Pi2");
   b_pyD0Pi2 = fChain->GetBranch("pyD0Pi2");
   b_pzD0Pi2 = fChain->GetBranch("pzD0Pi2");
   b_lundMcD0Pi2 = fChain->GetBranch("lundMcD0Pi2");
   b_lundD0Pi2 = fChain->GetBranch("lundD0Pi2");
   b_kaonidD0Pi2 = fChain->GetBranch("kaonidD0Pi2");
   b_ndchD0Pi2 = fChain->GetBranch("ndchD0Pi2");
   b_indexMcD0Pi2 = fChain->GetBranch("indexMcD0Pi2");
   b_effCorMcD0Pi2 = fChain->GetBranch("effCorMcD0Pi2");
   b_sEffCorMcD0Pi2 = fChain->GetBranch("sEffCorMcD0Pi2");

   return kTRUE;
}

void vali1::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t vali1::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef vali1_cxx
