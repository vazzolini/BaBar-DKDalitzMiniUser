//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Apr  6 15:24:04 2005 by ROOT version 4.02/00
// from TTree T/Reduced ROOT tree
// found on file: reduced/DKstar/btdkstarc_kspipi_btdkstarc.root
//////////////////////////////////////////////////////////

#ifndef bkg_tree_h
#define bkg_tree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <iostream.h>

class bkg_tree {
   TString sig_type;
   TString d0model;
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leave types
   Int_t           event;
   Int_t           runNumber;
   Float_t         FoxWol2Neu;
   Float_t         pxUps;
   Float_t         pyUps;
   Float_t         pzUps;
   Float_t         eUps;
   Int_t           nMc;
   Float_t         pMc[110];   //[nMc]
   Float_t         thetaMc[110];   //[nMc]
   Float_t         phiMc[110];   //[nMc]
   Int_t           idMc[110];   //[nMc]
   Int_t           mothMc[110];   //[nMc]
   Int_t           nDauMc[110];   //[nMc]
   Int_t           mcEvtType;
   Int_t           mcNREvtType;
   Float_t         demk;
   Float_t         demk2;
   Float_t         mes;
   Float_t         pxchb;
   Float_t         pychb;
   Float_t         pzchb;
   Float_t         coschbCM;
   Float_t         m0chb;
   Float_t         chi2chb;
   Float_t         dofchb;
   Int_t           indexmcchb;
   Float_t         legendrep0;
   Float_t         legendrep2;
   Float_t         fisher;
   Float_t         costhrust;
/*    Float_t         cone0; */
/*    Float_t         cone1; */
/*    Float_t         cone2; */
/*    Float_t         cone3; */
/*    Float_t         cone4; */
/*    Float_t         cone5; */
/*    Float_t         cone6; */
/*    Float_t         cone7; */
/*    Float_t         cone8; */
   Float_t         m0d0;
   Float_t         pxd0;
   Float_t         pyd0;
   Float_t         pzd0;
   Float_t         ed0;
   Float_t         xd0;
   Float_t         yd0;
   Float_t         zd0;
   Float_t         chi2d0;
   Float_t         dofd0;
   Int_t           indexmcd0;
   Int_t           ismcd0;
   Float_t         m0kstarc;
   Float_t         pxkstarc;
   Float_t         pykstarc;
   Float_t         pzkstarc;
   Float_t         ekstarc;
   Float_t         xkstarc;
   Float_t         ykstarc;
   Float_t         zkstarc;
   Float_t         chi2kstarc;
   Float_t         dofkstarc;
   Int_t           indexmckstarc;
   Int_t           flagkspi;
   Int_t           ismckstarckspic;
   Int_t           ismckstarckcpi0;
   Float_t         coselikstarc;
   Float_t         m0kstarcpi0;
   Float_t         pxkstarcpi0;
   Float_t         pykstarcpi0;
   Float_t         pzkstarcpi0;
   Float_t         ekstarcpi0;
   Float_t         chi2kstarcpi0;
   Float_t         dofkstarcpi0;
   Int_t           indexmckstarcpi0;
   Int_t           ismckstarcpi0;
   Float_t         ecalkstarcpi0g1;
   Float_t         ecalxkstarcpi0g1;
   Float_t         ecalykstarcpi0g1;
   Float_t         ecalzkstarcpi0g1;
   Float_t         pxkstarcpi0g1;
   Float_t         pykstarcpi0g1;
   Float_t         pzkstarcpi0g1;
   Float_t         lmomkstarcpi0g1;
   Int_t           ncrykstarcpi0g1;
   Int_t           indexmckstarcpi0g1;
   Float_t         ecalkstarcpi0g2;
   Float_t         ecalxkstarcpi0g2;
   Float_t         ecalykstarcpi0g2;
   Float_t         ecalzkstarcpi0g2;
   Float_t         pxkstarcpi0g2;
   Float_t         pykstarcpi0g2;
   Float_t         pzkstarcpi0g2;
   Float_t         lmomkstarcpi0g2;
   Int_t           ncrykstarcpi0g2;
   Int_t           indexmckstarcpi0g2;
   Float_t         pxkstarckc;
   Float_t         pykstarckc;
   Float_t         pzkstarckc;
   Float_t         cthekstarckc;
   Float_t         deltadrcmomkstarckc;
   Int_t           lundmckstarckc;
   Int_t           kaonidkstarckc;
   Int_t           ndchkstarckc;
   Int_t           nphotkstarckc;
   Int_t           indexmckstarckc;
   Float_t         masskstarcks;
   Float_t         pxkstarcks;
   Float_t         pykstarcks;
   Float_t         pzkstarcks;
   Float_t         ekstarcks;
   Float_t         xkstarcks;
   Float_t         ykstarcks;
   Float_t         zkstarcks;
   Float_t         chi2kstarcks;
   Int_t           dofkstarcks;
   Float_t         coskstarcks;
   Int_t           ismckstarcks;
   Int_t           indexmckstarcks;
   Float_t         pxkstarckspi1;
   Float_t         pykstarckspi1;
   Float_t         pzkstarckspi1;
   Int_t           lundmckstarckspi1;
   Int_t           kaonidkstarckspi1;
   Int_t           ndchkstarckspi1;
   Int_t           indexmckstarckspi1;
   Float_t         pxkstarckspi2;
   Float_t         pykstarckspi2;
   Float_t         pzkstarckspi2;
   Int_t           lundmckstarckspi2;
   Int_t           kaonidkstarckspi2;
   Int_t           ndchkstarckspi2;
   Int_t           indexmckstarckspi2;
   Float_t         pxkstarcpic;
   Float_t         pykstarcpic;
   Float_t         pzkstarcpic;
   Float_t         cthekstarcpic;
   Float_t         deltadrcmomkstarcpic;
   Int_t           lundmckstarcpic;
   Int_t           kaonidkstarcpic;
   Int_t           ndchkstarcpic;
   Int_t           nphotkstarcpic;
   Int_t           indexmckstarcpic;
   Float_t         massks;
   Float_t         pxks;
   Float_t         pyks;
   Float_t         pzks;
   Float_t         xks;
   Float_t         yks;
   Float_t         zks;
   Float_t         cosks;
   Float_t         chi2ks;
   Int_t           dofks;
   Int_t           ismcd0ks;
   Int_t           indexmcks;
   Float_t         pxkspi1;
   Float_t         pykspi1;
   Float_t         pzkspi1;
   Int_t           lundmckspi1;
   Int_t           kaonidkspi1;
   Int_t           ndchkspi1;
   Int_t           indexmcd0kspi1;
   Float_t         pxkspi2;
   Float_t         pykspi2;
   Float_t         pzkspi2;
   Int_t           lundmckspi2;
   Int_t           kaonidkspi2;
   Int_t           ndchkspi2;
   Int_t           indexmcd0kspi2;
   Float_t         pxd0pi1;
   Float_t         pyd0pi1;
   Float_t         pzd0pi1;
   Int_t           lundmcd0pi1;
   Int_t           kaonidd0pi1;
   Int_t           ndchd0pi1;
   Int_t           indexmcd0pi1;
   Float_t         pxd0pi2;
   Float_t         pyd0pi2;
   Float_t         pzd0pi2;
   Int_t           lundmcd0pi2;
   Int_t           kaonidd0pi2;
   Int_t           ndchd0pi2;
   Int_t           indexmcd0pi2;

   // List of branches
   TBranch        *b_event;   //!
   TBranch        *b_runNumber;   //!
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
   TBranch        *b_mcEvtType;   //!
   TBranch        *b_mcNREvtType;   //!
   TBranch        *b_demk;   //!
   TBranch        *b_demk2;   //!
   TBranch        *b_mes;   //!
   TBranch        *b_pxchb;   //!
   TBranch        *b_pychb;   //!
   TBranch        *b_pzchb;   //!
   TBranch        *b_coschbCM;   //!
   TBranch        *b_m0chb;   //!
   TBranch        *b_chi2chb;   //!
   TBranch        *b_dofchb;   //!
   TBranch        *b_indexmcchb;   //!
   TBranch        *b_legendrep0;   //!
   TBranch        *b_legendrep2;   //!
   TBranch        *b_fisher;   //!
   TBranch        *b_costhrust;   //!
/*    TBranch        *b_cone0;   //! */
/*    TBranch        *b_cone1;   //! */
/*    TBranch        *b_cone2;   //! */
/*    TBranch        *b_cone3;   //! */
/*    TBranch        *b_cone4;   //! */
/*    TBranch        *b_cone5;   //! */
/*    TBranch        *b_cone6;   //! */
/*    TBranch        *b_cone7;   //! */
/*    TBranch        *b_cone8;   //! */
   TBranch        *b_m0d0;   //!
   TBranch        *b_pxd0;   //!
   TBranch        *b_pyd0;   //!
   TBranch        *b_pzd0;   //!
   TBranch        *b_ed0;   //!
   TBranch        *b_xd0;   //!
   TBranch        *b_yd0;   //!
   TBranch        *b_zd0;   //!
   TBranch        *b_chi2d0;   //!
   TBranch        *b_dofd0;   //!
   TBranch        *b_indexmcd0;   //!
   TBranch        *b_ismcd0;   //!
   TBranch        *b_m0kstarc;   //!
   TBranch        *b_pxkstarc;   //!
   TBranch        *b_pykstarc;   //!
   TBranch        *b_pzkstarc;   //!
   TBranch        *b_ekstarc;   //!
   TBranch        *b_xkstarc;   //!
   TBranch        *b_ykstarc;   //!
   TBranch        *b_zkstarc;   //!
   TBranch        *b_chi2kstarc;   //!
   TBranch        *b_dofkstarc;   //!
   TBranch        *b_indexmckstarc;   //!
   TBranch        *b_flagkspi;   //!
   TBranch        *b_ismckstarckspic;   //!
   TBranch        *b_ismckstarckcpi0;   //!
   TBranch        *b_coselikstarc;   //!
   TBranch        *b_m0kstarcpi0;   //!
   TBranch        *b_pxkstarcpi0;   //!
   TBranch        *b_pykstarcpi0;   //!
   TBranch        *b_pzkstarcpi0;   //!
   TBranch        *b_ekstarcpi0;   //!
   TBranch        *b_chi2kstarcpi0;   //!
   TBranch        *b_dofkstarcpi0;   //!
   TBranch        *b_indexmckstarcpi0;   //!
   TBranch        *b_ismckstarcpi0;   //!
   TBranch        *b_ecalkstarcpi0g1;   //!
   TBranch        *b_ecalxkstarcpi0g1;   //!
   TBranch        *b_ecalykstarcpi0g1;   //!
   TBranch        *b_ecalzkstarcpi0g1;   //!
   TBranch        *b_pxkstarcpi0g1;   //!
   TBranch        *b_pykstarcpi0g1;   //!
   TBranch        *b_pzykstarcpi0g1;   //!
   TBranch        *b_lmomkstarcpi0g1;   //!
   TBranch        *b_ncrykstarcpi0g1;   //!
   TBranch        *b_indexmckstarcpi0g1;   //!
   TBranch        *b_ecalkstarcpi0g2;   //!
   TBranch        *b_ecalxkstarcpi0g2;   //!
   TBranch        *b_ecalykstarcpi0g2;   //!
   TBranch        *b_ecalzkstarcpi0g2;   //!
   TBranch        *b_pxkstarcpi0g2;   //!
   TBranch        *b_pykstarcpi0g2;   //!
   TBranch        *b_pzykstarcpi0g2;   //!
   TBranch        *b_lmomkstarcpi0g2;   //!
   TBranch        *b_ncrykstarcpi0g2;   //!
   TBranch        *b_indexmckstarcpi0g2;   //!
   TBranch        *b_pxkstarckc;   //!
   TBranch        *b_pykstarckc;   //!
   TBranch        *b_pzkstarckc;   //!
   TBranch        *b_cthekstarckc;   //!
   TBranch        *b_deltadrcmomkstarckc;   //!
   TBranch        *b_lundmckstarckc;   //!
   TBranch        *b_kaonidkstarckc;   //!
   TBranch        *b_ndchkstarckc;   //!
   TBranch        *b_nphotkstarckc;   //!
   TBranch        *b_indexmckstarckc;   //!
   TBranch        *b_masskstarcks;   //!
   TBranch        *b_pxkstarcks;   //!
   TBranch        *b_pykstarcks;   //!
   TBranch        *b_pzkstarcks;   //!
   TBranch        *b_ekstarcks;   //!
   TBranch        *b_xkstarcks;   //!
   TBranch        *b_ykstarcks;   //!
   TBranch        *b_zkstarcks;   //!
   TBranch        *b_chi2kstarcks;   //!
   TBranch        *b_dofkstarcks;   //!
   TBranch        *b_coskstarcks;   //!
   TBranch        *b_ismckstarcks;   //!
   TBranch        *b_indexmckstarcks;   //!
   TBranch        *b_pxkstarckspi1;   //!
   TBranch        *b_pykstarckspi1;   //!
   TBranch        *b_pzkstarckspi1;   //!
   TBranch        *b_lundmckstarckspi1;   //!
   TBranch        *b_kaonidkstarckspi1;   //!
   TBranch        *b_ndchkstarckspi1;   //!
   TBranch        *b_indexmckstarckspi1;   //!
   TBranch        *b_pxkstarckspi2;   //!
   TBranch        *b_pykstarckspi2;   //!
   TBranch        *b_pzkstarckspi2;   //!
   TBranch        *b_lundmckstarckspi2;   //!
   TBranch        *b_kaonidkstarckspi2;   //!
   TBranch        *b_ndchkstarckspi2;   //!
   TBranch        *b_indexmckstarckspi2;   //!
   TBranch        *b_pxkstarcpic;   //!
   TBranch        *b_pykstarcpic;   //!
   TBranch        *b_pzkstarcpic;   //!
   TBranch        *b_cthekstarcpic;   //!
   TBranch        *b_deltadrcmomkstarcpic;   //!
   TBranch        *b_lundmckstarcpic;   //!
   TBranch        *b_kaonidkstarcpic;   //!
   TBranch        *b_ndchkstarcpic;   //!
   TBranch        *b_nphotkstarcpic;   //!
   TBranch        *b_indexmckstarcpic;   //!
   TBranch        *b_massks;   //!
   TBranch        *b_pxks;   //!
   TBranch        *b_pyks;   //!
   TBranch        *b_pzks;   //!
   TBranch        *b_xks;   //!
   TBranch        *b_yks;   //!
   TBranch        *b_zks;   //!
   TBranch        *b_cosks;   //!
   TBranch        *b_chi2ks;   //!
   TBranch        *b_dofks;   //!
   TBranch        *b_ismcd0ks;   //!
   TBranch        *b_indexmcks;   //!
   TBranch        *b_pxkspi1;   //!
   TBranch        *b_pykspi1;   //!
   TBranch        *b_pzkspi1;   //!
   TBranch        *b_lundmckspi1;   //!
   TBranch        *b_kaonidkspi1;   //!
   TBranch        *b_ndchkspi1;   //!
   TBranch        *b_indexmcd0kspi1;   //!
   TBranch        *b_pxkspi2;   //!
   TBranch        *b_pykspi2;   //!
   TBranch        *b_pzkspi2;   //!
   TBranch        *b_lundmckspi2;   //!
   TBranch        *b_kaonidkspi2;   //!
   TBranch        *b_ndchkspi2;   //!
   TBranch        *b_indexmcd0kspi2;   //!
   TBranch        *b_pxd0pi1;   //!
   TBranch        *b_pyd0pi1;   //!
   TBranch        *b_pzd0pi1;   //!
   TBranch        *b_lundmcd0pi1;   //!
   TBranch        *b_kaonidd0pi1;   //!
   TBranch        *b_ndchd0pi1;   //!
   TBranch        *b_indexmcd0pi1;   //!
   TBranch        *b_pxd0pi2;   //!
   TBranch        *b_pyd0pi2;   //!
   TBranch        *b_pzd0pi2;   //!
   TBranch        *b_lundmcd0pi2;   //!
   TBranch        *b_kaonidd0pi2;   //!
   TBranch        *b_ndchd0pi2;   //!
   TBranch        *b_indexmcd0pi2;   //!

   bkg_tree(TTree *tree=0);
   bkg_tree(TString type,TString d0mode);
   virtual ~bkg_tree();

   virtual Int_t    Cut(Long64_t entry,Int_t dec_flag);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop(char* decay);
   //   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef bkg_tree_cxx
bkg_tree::bkg_tree(TTree *tree)
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("reduced/DKstar/btdkstarc_kspipi_btdkstarc.root");
      if (!f) {
         f = new TFile("reduced/DKstar/btdkstarc_kspipi_btdkstarc.root");
      }
      tree = (TTree*)gDirectory->Get("T");

   }
   Init(tree);
}


bkg_tree::bkg_tree(TString type,TString d0mode)
{
  TChain* tree=new TChain("T");
  sig_type=type;
  d0model=d0mode;
  TString filename;
  TString filename1;
  cout<<"reading event of type: "<<type<<endl;

  if (type=="btdkstarc"){
    filename="/home/blacks/Analisi/workdir/summer05/reduced/DKstar/btdkstarc_"+d0mode+"_btdkstarc_TreeFitter.root";
    tree->Add(filename);
  }

  if (type=="chb"){
    filename="/home/blacks/Analisi/workdir/summer05/reduced/reduced_mc/btdkstarc_"+d0mode+"_chb_mc.root";
    tree->Add(filename);
  }

  if (type=="b0b0bar"){
    filename="/home/blacks/Analisi/workdir/summer05/reduced/reduced_mc/btdkstarc_"+d0mode+"_b0b0bar_mc.root";
    tree->Add(filename);
  }

  if (type=="ccbar"){
    filename="/home/blacks/Analisi/workdir/summer05/reduced/reduced_mc/btdkstarc_"+d0mode+"_ccbar_mc.root";
    tree->Add(filename);
  }

  if (type=="uds"){
    filename="/home/blacks/Analisi/workdir/summer05/reduced/reduced_mc/btdkstarc_"+d0mode+"_uds_mc.root";
    tree->Add(filename);
  }


  cout<<"done"<<endl;
  Init(tree);
}


bkg_tree::~bkg_tree()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t bkg_tree::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t bkg_tree::LoadTree(Long64_t entry)
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

void bkg_tree::Init(TTree *tree)
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
   fChain->SetBranchAddress("mcEvtType",&mcEvtType);
   fChain->SetBranchAddress("mcNREvtType",&mcNREvtType);
   fChain->SetBranchAddress("demk",&demk);
   fChain->SetBranchAddress("demk2",&demk2);
   fChain->SetBranchAddress("mes",&mes);
   fChain->SetBranchAddress("pxchb",&pxchb);
   fChain->SetBranchAddress("pychb",&pychb);
   fChain->SetBranchAddress("pzchb",&pzchb);
   fChain->SetBranchAddress("coschbCM",&coschbCM);
   fChain->SetBranchAddress("m0chb",&m0chb);
   fChain->SetBranchAddress("chi2chb",&chi2chb);
   fChain->SetBranchAddress("dofchb",&dofchb);
   fChain->SetBranchAddress("indexmcchb",&indexmcchb);
   fChain->SetBranchAddress("legendrep0",&legendrep0);
   fChain->SetBranchAddress("legendrep2",&legendrep2);
   fChain->SetBranchAddress("fisher",&fisher);
   fChain->SetBranchAddress("costhrust",&costhrust);
/*    fChain->SetBranchAddress("cone0",&cone0); */
/*    fChain->SetBranchAddress("cone1",&cone1); */
/*    fChain->SetBranchAddress("cone2",&cone2); */
/*    fChain->SetBranchAddress("cone3",&cone3); */
/*    fChain->SetBranchAddress("cone4",&cone4); */
/*    fChain->SetBranchAddress("cone5",&cone5); */
/*    fChain->SetBranchAddress("cone6",&cone6); */
/*    fChain->SetBranchAddress("cone7",&cone7); */
/*    fChain->SetBranchAddress("cone8",&cone8); */
   fChain->SetBranchAddress("m0d0",&m0d0);
   fChain->SetBranchAddress("pxd0",&pxd0);
   fChain->SetBranchAddress("pyd0",&pyd0);
   fChain->SetBranchAddress("pzd0",&pzd0);
   fChain->SetBranchAddress("ed0",&ed0);
   fChain->SetBranchAddress("xd0",&xd0);
   fChain->SetBranchAddress("yd0",&yd0);
   fChain->SetBranchAddress("zd0",&zd0);
   fChain->SetBranchAddress("chi2d0",&chi2d0);
   fChain->SetBranchAddress("dofd0",&dofd0);
   fChain->SetBranchAddress("indexmcd0",&indexmcd0);
   fChain->SetBranchAddress("ismcd0",&ismcd0);
   fChain->SetBranchAddress("m0kstarc",&m0kstarc);
   fChain->SetBranchAddress("pxkstarc",&pxkstarc);
   fChain->SetBranchAddress("pykstarc",&pykstarc);
   fChain->SetBranchAddress("pzkstarc",&pzkstarc);
   fChain->SetBranchAddress("ekstarc",&ekstarc);
   fChain->SetBranchAddress("xkstarc",&xkstarc);
   fChain->SetBranchAddress("ykstarc",&ykstarc);
   fChain->SetBranchAddress("zkstarc",&zkstarc);
   fChain->SetBranchAddress("chi2kstarc",&chi2kstarc);
   fChain->SetBranchAddress("dofkstarc",&dofkstarc);
   fChain->SetBranchAddress("indexmckstarc",&indexmckstarc);
   fChain->SetBranchAddress("flagkspi",&flagkspi);
   fChain->SetBranchAddress("ismckstarckspic",&ismckstarckspic);
   fChain->SetBranchAddress("ismckstarckcpi0",&ismckstarckcpi0);
   fChain->SetBranchAddress("coselikstarc",&coselikstarc);
   fChain->SetBranchAddress("m0kstarcpi0",&m0kstarcpi0);
   fChain->SetBranchAddress("pxkstarcpi0",&pxkstarcpi0);
   fChain->SetBranchAddress("pykstarcpi0",&pykstarcpi0);
   fChain->SetBranchAddress("pzkstarcpi0",&pzkstarcpi0);
   fChain->SetBranchAddress("ekstarcpi0",&ekstarcpi0);
   fChain->SetBranchAddress("chi2kstarcpi0",&chi2kstarcpi0);
   fChain->SetBranchAddress("dofkstarcpi0",&dofkstarcpi0);
   fChain->SetBranchAddress("indexmckstarcpi0",&indexmckstarcpi0);
   fChain->SetBranchAddress("ismckstarcpi0",&ismckstarcpi0);
   fChain->SetBranchAddress("ecalkstarcpi0g1",&ecalkstarcpi0g1);
   fChain->SetBranchAddress("ecalxkstarcpi0g1",&ecalxkstarcpi0g1);
   fChain->SetBranchAddress("ecalykstarcpi0g1",&ecalykstarcpi0g1);
   fChain->SetBranchAddress("ecalzkstarcpi0g1",&ecalzkstarcpi0g1);
   fChain->SetBranchAddress("pxkstarcpi0g1",&pxkstarcpi0g1);
   fChain->SetBranchAddress("pykstarcpi0g1",&pykstarcpi0g1);
   fChain->SetBranchAddress("pzkstarcpi0g1",&pzkstarcpi0g1);
   fChain->SetBranchAddress("lmomkstarcpi0g1",&lmomkstarcpi0g1);
   fChain->SetBranchAddress("ncrykstarcpi0g1",&ncrykstarcpi0g1);
   fChain->SetBranchAddress("indexmckstarcpi0g1",&indexmckstarcpi0g1);
   fChain->SetBranchAddress("ecalkstarcpi0g2",&ecalkstarcpi0g2);
   fChain->SetBranchAddress("ecalxkstarcpi0g2",&ecalxkstarcpi0g2);
   fChain->SetBranchAddress("ecalykstarcpi0g2",&ecalykstarcpi0g2);
   fChain->SetBranchAddress("ecalzkstarcpi0g2",&ecalzkstarcpi0g2);
   fChain->SetBranchAddress("pxkstarcpi0g2",&pxkstarcpi0g2);
   fChain->SetBranchAddress("pykstarcpi0g2",&pykstarcpi0g2);
   fChain->SetBranchAddress("pzkstarcpi0g2",&pzkstarcpi0g2);
   fChain->SetBranchAddress("lmomkstarcpi0g2",&lmomkstarcpi0g2);
   fChain->SetBranchAddress("ncrykstarcpi0g2",&ncrykstarcpi0g2);
   fChain->SetBranchAddress("indexmckstarcpi0g2",&indexmckstarcpi0g2);
   fChain->SetBranchAddress("pxkstarckc",&pxkstarckc);
   fChain->SetBranchAddress("pykstarckc",&pykstarckc);
   fChain->SetBranchAddress("pzkstarckc",&pzkstarckc);
   fChain->SetBranchAddress("cthekstarckc",&cthekstarckc);
   fChain->SetBranchAddress("deltadrcmomkstarckc",&deltadrcmomkstarckc);
   fChain->SetBranchAddress("lundmckstarckc",&lundmckstarckc);
   fChain->SetBranchAddress("kaonidkstarckc",&kaonidkstarckc);
   fChain->SetBranchAddress("ndchkstarckc",&ndchkstarckc);
   fChain->SetBranchAddress("nphotkstarckc",&nphotkstarckc);
   fChain->SetBranchAddress("indexmckstarckc",&indexmckstarckc);
   fChain->SetBranchAddress("masskstarcks",&masskstarcks);
   fChain->SetBranchAddress("pxkstarcks",&pxkstarcks);
   fChain->SetBranchAddress("pykstarcks",&pykstarcks);
   fChain->SetBranchAddress("pzkstarcks",&pzkstarcks);
   fChain->SetBranchAddress("ekstarcks",&ekstarcks);
   fChain->SetBranchAddress("xkstarcks",&xkstarcks);
   fChain->SetBranchAddress("ykstarcks",&ykstarcks);
   fChain->SetBranchAddress("zkstarcks",&zkstarcks);
   fChain->SetBranchAddress("chi2kstarcks",&chi2kstarcks);
   fChain->SetBranchAddress("dofkstarcks",&dofkstarcks);
   fChain->SetBranchAddress("coskstarcks",&coskstarcks);
   fChain->SetBranchAddress("ismckstarcks",&ismckstarcks);
   fChain->SetBranchAddress("indexmckstarcks",&indexmckstarcks);
   fChain->SetBranchAddress("pxkstarckspi1",&pxkstarckspi1);
   fChain->SetBranchAddress("pykstarckspi1",&pykstarckspi1);
   fChain->SetBranchAddress("pzkstarckspi1",&pzkstarckspi1);
   fChain->SetBranchAddress("lundmckstarckspi1",&lundmckstarckspi1);
   fChain->SetBranchAddress("kaonidkstarckspi1",&kaonidkstarckspi1);
   fChain->SetBranchAddress("ndchkstarckspi1",&ndchkstarckspi1);
   fChain->SetBranchAddress("indexmckstarckspi1",&indexmckstarckspi1);
   fChain->SetBranchAddress("pxkstarckspi2",&pxkstarckspi2);
   fChain->SetBranchAddress("pykstarckspi2",&pykstarckspi2);
   fChain->SetBranchAddress("pzkstarckspi2",&pzkstarckspi2);
   fChain->SetBranchAddress("lundmckstarckspi2",&lundmckstarckspi2);
   fChain->SetBranchAddress("kaonidkstarckspi2",&kaonidkstarckspi2);
   fChain->SetBranchAddress("ndchkstarckspi2",&ndchkstarckspi2);
   fChain->SetBranchAddress("indexmckstarckspi2",&indexmckstarckspi2);
   fChain->SetBranchAddress("pxkstarcpic",&pxkstarcpic);
   fChain->SetBranchAddress("pykstarcpic",&pykstarcpic);
   fChain->SetBranchAddress("pzkstarcpic",&pzkstarcpic);
   fChain->SetBranchAddress("cthekstarcpic",&cthekstarcpic);
   fChain->SetBranchAddress("deltadrcmomkstarcpic",&deltadrcmomkstarcpic);
   fChain->SetBranchAddress("lundmckstarcpic",&lundmckstarcpic);
   fChain->SetBranchAddress("kaonidkstarcpic",&kaonidkstarcpic);
   fChain->SetBranchAddress("ndchkstarcpic",&ndchkstarcpic);
   fChain->SetBranchAddress("nphotkstarcpic",&nphotkstarcpic);
   fChain->SetBranchAddress("indexmckstarcpic",&indexmckstarcpic);
   fChain->SetBranchAddress("massks",&massks);
   fChain->SetBranchAddress("pxks",&pxks);
   fChain->SetBranchAddress("pyks",&pyks);
   fChain->SetBranchAddress("pzks",&pzks);
   fChain->SetBranchAddress("xks",&xks);
   fChain->SetBranchAddress("yks",&yks);
   fChain->SetBranchAddress("zks",&zks);
   fChain->SetBranchAddress("cosks",&cosks);
   fChain->SetBranchAddress("chi2ks",&chi2ks);
   fChain->SetBranchAddress("dofks",&dofks);
   fChain->SetBranchAddress("ismcd0ks",&ismcd0ks);
   fChain->SetBranchAddress("indexmcks",&indexmcks);
   fChain->SetBranchAddress("pxkspi1",&pxkspi1);
   fChain->SetBranchAddress("pykspi1",&pykspi1);
   fChain->SetBranchAddress("pzkspi1",&pzkspi1);
   fChain->SetBranchAddress("lundmckspi1",&lundmckspi1);
   fChain->SetBranchAddress("kaonidkspi1",&kaonidkspi1);
   fChain->SetBranchAddress("ndchkspi1",&ndchkspi1);
   fChain->SetBranchAddress("indexmcd0kspi1",&indexmcd0kspi1);
   fChain->SetBranchAddress("pxkspi2",&pxkspi2);
   fChain->SetBranchAddress("pykspi2",&pykspi2);
   fChain->SetBranchAddress("pzkspi2",&pzkspi2);
   fChain->SetBranchAddress("lundmckspi2",&lundmckspi2);
   fChain->SetBranchAddress("kaonidkspi2",&kaonidkspi2);
   fChain->SetBranchAddress("ndchkspi2",&ndchkspi2);
   fChain->SetBranchAddress("indexmcd0kspi2",&indexmcd0kspi2);
   fChain->SetBranchAddress("pxd0pi1",&pxd0pi1);
   fChain->SetBranchAddress("pyd0pi1",&pyd0pi1);
   fChain->SetBranchAddress("pzd0pi1",&pzd0pi1);
   fChain->SetBranchAddress("lundmcd0pi1",&lundmcd0pi1);
   fChain->SetBranchAddress("kaonidd0pi1",&kaonidd0pi1);
   fChain->SetBranchAddress("ndchd0pi1",&ndchd0pi1);
   fChain->SetBranchAddress("indexmcd0pi1",&indexmcd0pi1);
   fChain->SetBranchAddress("pxd0pi2",&pxd0pi2);
   fChain->SetBranchAddress("pyd0pi2",&pyd0pi2);
   fChain->SetBranchAddress("pzd0pi2",&pzd0pi2);
   fChain->SetBranchAddress("lundmcd0pi2",&lundmcd0pi2);
   fChain->SetBranchAddress("kaonidd0pi2",&kaonidd0pi2);
   fChain->SetBranchAddress("ndchd0pi2",&ndchd0pi2);
   fChain->SetBranchAddress("indexmcd0pi2",&indexmcd0pi2);
   Notify();
}

Bool_t bkg_tree::Notify()
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
   b_pMc = fChain->GetBranch("pMc");
   b_thetaMc = fChain->GetBranch("thetaMc");
   b_phiMc = fChain->GetBranch("phiMc");
   b_idMc = fChain->GetBranch("idMc");
   b_mothMc = fChain->GetBranch("mothMc");
   b_nDauMc = fChain->GetBranch("nDauMc");
   b_mcEvtType = fChain->GetBranch("mcEvtType");
   b_mcNREvtType = fChain->GetBranch("mcNREvtType");
   b_demk = fChain->GetBranch("demk");
   b_demk2 = fChain->GetBranch("demk2");
   b_mes = fChain->GetBranch("mes");
   b_pxchb = fChain->GetBranch("pxchb");
   b_pychb = fChain->GetBranch("pychb");
   b_pzchb = fChain->GetBranch("pzchb");
   b_coschbCM = fChain->GetBranch("coschbCM");
   b_m0chb = fChain->GetBranch("m0chb");
   b_chi2chb = fChain->GetBranch("chi2chb");
   b_dofchb = fChain->GetBranch("dofchb");
   b_indexmcchb = fChain->GetBranch("indexmcchb");
   b_legendrep0 = fChain->GetBranch("legendrep0");
   b_legendrep2 = fChain->GetBranch("legendrep2");
   b_fisher = fChain->GetBranch("fisher");
   b_costhrust = fChain->GetBranch("costhrust");
/*    b_cone0 = fChain->GetBranch("cone0"); */
/*    b_cone1 = fChain->GetBranch("cone1"); */
/*    b_cone2 = fChain->GetBranch("cone2"); */
/*    b_cone3 = fChain->GetBranch("cone3"); */
/*    b_cone4 = fChain->GetBranch("cone4"); */
/*    b_cone5 = fChain->GetBranch("cone5"); */
/*    b_cone6 = fChain->GetBranch("cone6"); */
/*    b_cone7 = fChain->GetBranch("cone7"); */
/*    b_cone8 = fChain->GetBranch("cone8"); */
   b_m0d0 = fChain->GetBranch("m0d0");
   b_pxd0 = fChain->GetBranch("pxd0");
   b_pyd0 = fChain->GetBranch("pyd0");
   b_pzd0 = fChain->GetBranch("pzd0");
   b_ed0 = fChain->GetBranch("ed0");
   b_xd0 = fChain->GetBranch("xd0");
   b_yd0 = fChain->GetBranch("yd0");
   b_zd0 = fChain->GetBranch("zd0");
   b_chi2d0 = fChain->GetBranch("chi2d0");
   b_dofd0 = fChain->GetBranch("dofd0");
   b_indexmcd0 = fChain->GetBranch("indexmcd0");
   b_ismcd0 = fChain->GetBranch("ismcd0");
   b_m0kstarc = fChain->GetBranch("m0kstarc");
   b_pxkstarc = fChain->GetBranch("pxkstarc");
   b_pykstarc = fChain->GetBranch("pykstarc");
   b_pzkstarc = fChain->GetBranch("pzkstarc");
   b_ekstarc = fChain->GetBranch("ekstarc");
   b_xkstarc = fChain->GetBranch("xkstarc");
   b_ykstarc = fChain->GetBranch("ykstarc");
   b_zkstarc = fChain->GetBranch("zkstarc");
   b_chi2kstarc = fChain->GetBranch("chi2kstarc");
   b_dofkstarc = fChain->GetBranch("dofkstarc");
   b_indexmckstarc = fChain->GetBranch("indexmckstarc");
   b_flagkspi = fChain->GetBranch("flagkspi");
   b_ismckstarckspic = fChain->GetBranch("ismckstarckspic");
   b_ismckstarckcpi0 = fChain->GetBranch("ismckstarckcpi0");
   b_coselikstarc = fChain->GetBranch("coselikstarc");
   b_m0kstarcpi0 = fChain->GetBranch("m0kstarcpi0");
   b_pxkstarcpi0 = fChain->GetBranch("pxkstarcpi0");
   b_pykstarcpi0 = fChain->GetBranch("pykstarcpi0");
   b_pzkstarcpi0 = fChain->GetBranch("pzkstarcpi0");
   b_ekstarcpi0 = fChain->GetBranch("ekstarcpi0");
   b_chi2kstarcpi0 = fChain->GetBranch("chi2kstarcpi0");
   b_dofkstarcpi0 = fChain->GetBranch("dofkstarcpi0");
   b_indexmckstarcpi0 = fChain->GetBranch("indexmckstarcpi0");
   b_ismckstarcpi0 = fChain->GetBranch("ismckstarcpi0");
   b_ecalkstarcpi0g1 = fChain->GetBranch("ecalkstarcpi0g1");
   b_ecalxkstarcpi0g1 = fChain->GetBranch("ecalxkstarcpi0g1");
   b_ecalykstarcpi0g1 = fChain->GetBranch("ecalykstarcpi0g1");
   b_ecalzkstarcpi0g1 = fChain->GetBranch("ecalzkstarcpi0g1");
   b_pxkstarcpi0g1 = fChain->GetBranch("pxkstarcpi0g1");
   b_pykstarcpi0g1 = fChain->GetBranch("pykstarcpi0g1");
   b_pzykstarcpi0g1 = fChain->GetBranch("pzkstarcpi0g1");
   b_lmomkstarcpi0g1 = fChain->GetBranch("lmomkstarcpi0g1");
   b_ncrykstarcpi0g1 = fChain->GetBranch("ncrykstarcpi0g1");
   b_indexmckstarcpi0g1 = fChain->GetBranch("indexmckstarcpi0g1");
   b_ecalkstarcpi0g2 = fChain->GetBranch("ecalkstarcpi0g2");
   b_ecalxkstarcpi0g2 = fChain->GetBranch("ecalxkstarcpi0g2");
   b_ecalykstarcpi0g2 = fChain->GetBranch("ecalykstarcpi0g2");
   b_ecalzkstarcpi0g2 = fChain->GetBranch("ecalzkstarcpi0g2");
   b_pxkstarcpi0g2 = fChain->GetBranch("pxkstarcpi0g2");
   b_pykstarcpi0g2 = fChain->GetBranch("pykstarcpi0g2");
   b_pzykstarcpi0g2 = fChain->GetBranch("pzkstarcpi0g2");
   b_lmomkstarcpi0g2 = fChain->GetBranch("lmomkstarcpi0g2");
   b_ncrykstarcpi0g2 = fChain->GetBranch("ncrykstarcpi0g2");
   b_indexmckstarcpi0g2 = fChain->GetBranch("indexmckstarcpi0g2");
   b_pxkstarckc = fChain->GetBranch("pxkstarckc");
   b_pykstarckc = fChain->GetBranch("pykstarckc");
   b_pzkstarckc = fChain->GetBranch("pzkstarckc");
   b_cthekstarckc = fChain->GetBranch("cthekstarckc");
   b_deltadrcmomkstarckc = fChain->GetBranch("deltadrcmomkstarckc");
   b_lundmckstarckc = fChain->GetBranch("lundmckstarckc");
   b_kaonidkstarckc = fChain->GetBranch("kaonidkstarckc");
   b_ndchkstarckc = fChain->GetBranch("ndchkstarckc");
   b_nphotkstarckc = fChain->GetBranch("nphotkstarckc");
   b_indexmckstarckc = fChain->GetBranch("indexmckstarckc");
   b_masskstarcks = fChain->GetBranch("masskstarcks");
   b_pxkstarcks = fChain->GetBranch("pxkstarcks");
   b_pykstarcks = fChain->GetBranch("pykstarcks");
   b_pzkstarcks = fChain->GetBranch("pzkstarcks");
   b_ekstarcks = fChain->GetBranch("ekstarcks");
   b_xkstarcks = fChain->GetBranch("xkstarcks");
   b_ykstarcks = fChain->GetBranch("ykstarcks");
   b_zkstarcks = fChain->GetBranch("zkstarcks");
   b_chi2kstarcks = fChain->GetBranch("chi2kstarcks");
   b_dofkstarcks = fChain->GetBranch("dofkstarcks");
   b_coskstarcks = fChain->GetBranch("coskstarcks");
   b_ismckstarcks = fChain->GetBranch("ismckstarcks");
   b_indexmckstarcks = fChain->GetBranch("indexmckstarcks");
   b_pxkstarckspi1 = fChain->GetBranch("pxkstarckspi1");
   b_pykstarckspi1 = fChain->GetBranch("pykstarckspi1");
   b_pzkstarckspi1 = fChain->GetBranch("pzkstarckspi1");
   b_lundmckstarckspi1 = fChain->GetBranch("lundmckstarckspi1");
   b_kaonidkstarckspi1 = fChain->GetBranch("kaonidkstarckspi1");
   b_ndchkstarckspi1 = fChain->GetBranch("ndchkstarckspi1");
   b_indexmckstarckspi1 = fChain->GetBranch("indexmckstarckspi1");
   b_pxkstarckspi2 = fChain->GetBranch("pxkstarckspi2");
   b_pykstarckspi2 = fChain->GetBranch("pykstarckspi2");
   b_pzkstarckspi2 = fChain->GetBranch("pzkstarckspi2");
   b_lundmckstarckspi2 = fChain->GetBranch("lundmckstarckspi2");
   b_kaonidkstarckspi2 = fChain->GetBranch("kaonidkstarckspi2");
   b_ndchkstarckspi2 = fChain->GetBranch("ndchkstarckspi2");
   b_indexmckstarckspi2 = fChain->GetBranch("indexmckstarckspi2");
   b_pxkstarcpic = fChain->GetBranch("pxkstarcpic");
   b_pykstarcpic = fChain->GetBranch("pykstarcpic");
   b_pzkstarcpic = fChain->GetBranch("pzkstarcpic");
   b_cthekstarcpic = fChain->GetBranch("cthekstarcpic");
   b_deltadrcmomkstarcpic = fChain->GetBranch("deltadrcmomkstarcpic");
   b_lundmckstarcpic = fChain->GetBranch("lundmckstarcpic");
   b_kaonidkstarcpic = fChain->GetBranch("kaonidkstarcpic");
   b_ndchkstarcpic = fChain->GetBranch("ndchkstarcpic");
   b_nphotkstarcpic = fChain->GetBranch("nphotkstarcpic");
   b_indexmckstarcpic = fChain->GetBranch("indexmckstarcpic");
   b_massks = fChain->GetBranch("massks");
   b_pxks = fChain->GetBranch("pxks");
   b_pyks = fChain->GetBranch("pyks");
   b_pzks = fChain->GetBranch("pzks");
   b_xks = fChain->GetBranch("xks");
   b_yks = fChain->GetBranch("yks");
   b_zks = fChain->GetBranch("zks");
   b_cosks = fChain->GetBranch("cosks");
   b_chi2ks = fChain->GetBranch("chi2ks");
   b_dofks = fChain->GetBranch("dofks");
   b_ismcd0ks = fChain->GetBranch("ismcd0ks");
   b_indexmcks = fChain->GetBranch("indexmcks");
   b_pxkspi1 = fChain->GetBranch("pxkspi1");
   b_pykspi1 = fChain->GetBranch("pykspi1");
   b_pzkspi1 = fChain->GetBranch("pzkspi1");
   b_lundmckspi1 = fChain->GetBranch("lundmckspi1");
   b_kaonidkspi1 = fChain->GetBranch("kaonidkspi1");
   b_ndchkspi1 = fChain->GetBranch("ndchkspi1");
   b_indexmcd0kspi1 = fChain->GetBranch("indexmcd0kspi1");
   b_pxkspi2 = fChain->GetBranch("pxkspi2");
   b_pykspi2 = fChain->GetBranch("pykspi2");
   b_pzkspi2 = fChain->GetBranch("pzkspi2");
   b_lundmckspi2 = fChain->GetBranch("lundmckspi2");
   b_kaonidkspi2 = fChain->GetBranch("kaonidkspi2");
   b_ndchkspi2 = fChain->GetBranch("ndchkspi2");
   b_indexmcd0kspi2 = fChain->GetBranch("indexmcd0kspi2");
   b_pxd0pi1 = fChain->GetBranch("pxd0pi1");
   b_pyd0pi1 = fChain->GetBranch("pyd0pi1");
   b_pzd0pi1 = fChain->GetBranch("pzd0pi1");
   b_lundmcd0pi1 = fChain->GetBranch("lundmcd0pi1");
   b_kaonidd0pi1 = fChain->GetBranch("kaonidd0pi1");
   b_ndchd0pi1 = fChain->GetBranch("ndchd0pi1");
   b_indexmcd0pi1 = fChain->GetBranch("indexmcd0pi1");
   b_pxd0pi2 = fChain->GetBranch("pxd0pi2");
   b_pyd0pi2 = fChain->GetBranch("pyd0pi2");
   b_pzd0pi2 = fChain->GetBranch("pzd0pi2");
   b_lundmcd0pi2 = fChain->GetBranch("lundmcd0pi2");
   b_kaonidd0pi2 = fChain->GetBranch("kaonidd0pi2");
   b_ndchd0pi2 = fChain->GetBranch("ndchd0pi2");
   b_indexmcd0pi2 = fChain->GetBranch("indexmcd0pi2");

   return kTRUE;
}

void bkg_tree::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}

Int_t bkg_tree::Cut(Long64_t entry,Int_t dec_flag)
{
   //   if (entry<100) cout <<"deltam ="<< deltam_ref_sigma<<endl; 
  //  Int_t mcEvt=(sig_type==TString("btdkstarc")) ? (3673+196*dec_flag) : 0;
  Float_t deltam_kstar = (dec_flag==1) ? 0.060 : 0.050;
  Float_t demk_cut = (dec_flag==1) ? 0.021 : 0.050;
  Float_t coshel_cut = (dec_flag==1) ? 0.37 : -0.3;
  Float_t costhrust_cut = 0.9;
  Float_t fisher4=(-1.17778+0.285605*coschbCM+0.948404*costhrust+0.0558082*legendrep0+0.125878*legendrep2);
  Float_t fisher4_cut=0.2;

	  if (1&&
	      //	      (mcEvtType==mcEvt)&&
	     // decay kspi
	     ((dec_flag==1 && flagkspi==1)&&
	      //	      fisher4<fisher4_cut&&
	      fabs(costhrust)<0.8&&
	      fabs(m0d0-1.8645)<0.012&&
	      (fabs(massks-0.4977)<0.009)&&
	      (fabs(masskstarcks-0.4977)<0.009)&&
	      cosks>0.99&&
	      fabs(coskstarcks)>0.99&&
	      (fabs(m0kstarc-0.89166)<deltam_kstar)&&
	      fabs(coselikstarc)>coshel_cut&&
	      (fabs(demk)<demk_cut)&&
	      TMath::Prob(chi2d0,4)>0&&
	      TMath::Prob(chi2chb,11)>1.0E-3&&
	      mes>5.271&&
	      1)
	     ||// decay kpi0
	     ((dec_flag==2 && flagkspi==0)&&
	      //	      fisher4<fisher4_cut&&
	      fabs(costhrust)<0.8&&
	      fabs(m0d0-1.8645)<0.012&&
	      (fabs(massks-0.4977)<0.009)&&
	      (fabs(m0kstarcpi0-0.135)<0.012)&&
	      cosks>0.99&&
	      ((int(kaonidkstarckc)&16384==16384))&&
	      (fabs(m0kstarc-0.89166)<deltam_kstar)&&
	      coselikstarc>coshel_cut&&   // note!!!  asymmetric cut
	      TMath::Prob(chi2d0,4)>0&&
	      TMath::Prob(chi2chb,11)>1.0E-1&&
	      (fabs(demk)<demk_cut)&&
	      mes>5.271)&&
	      1) return 1;
	 else return -1;
      
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
}

#endif // #ifdef bkg_tree_cxx
