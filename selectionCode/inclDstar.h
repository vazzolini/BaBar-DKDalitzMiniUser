//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Nov  8 15:01:38 2005 by ROOT version 4.04/02g
// from TTree ntp4/DstarDalitzRootuple
// found on file: SP-1005-AllEventsSkim-Run4-R16a-1.root
//////////////////////////////////////////////////////////

#ifndef inclDstar_h
#define inclDstar_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
//addition
#include <iostream.h>    
#include <TStopwatch.h>  
#include "TLorentzVector.h"  

class inclDstar {
 //addition
   TString        _sig_type;
   TString        _d0mode;
   Bool_t         _isData;  
   
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leave types
   Int_t           event;
   Int_t           runNumber;
   Int_t           platform;
   Int_t           partition;
   Int_t           upperID;
   Int_t           lowerID;
   Float_t         primVtxX;
   Float_t         primVtxY;
   Float_t         primVtxZ;
   Float_t         primVtxCovXX;
   Float_t         primVtxCovYY;   
   Float_t         primVtxCovZZ;   
   Float_t         primVtxCovXY;
   Float_t         primVtxCovYZ;
   Float_t         primVtxCovXZ;
   Float_t         primVtxChi2;
   Int_t           primVtxNdof;
   /*
   UChar_t         BCountFilter;
   UChar_t         DchTrig;
   UChar_t         EmcTrig;
   Float_t         R2All;
   Int_t           nGTLFid;
   Int_t           nChgFid;
   Float_t         eTotFid;
   Float_t         PrimVtxdr;
   Float_t         PrimVtxdz;
   Float_t         VtxProb;
   */
   Float_t         beamSX;
   Float_t         beamSY;
   Float_t         beamSZ;
   Float_t         beamSCovXX;
   Float_t         beamSCovYY;
   Float_t         beamSCovZZ;
   Float_t         beamSCovXZ;
   Float_t         pxUps;
   Float_t         pyUps;
   Float_t         pzUps;
   Float_t         eUps;
   Int_t           nMc;
   Float_t         pMc[300];   //[nMc]
   Float_t         massMc[300];   //[nMc]
   Float_t         thetaMc[300];   //[nMc]
   Float_t         phiMc[300];   //[nMc]
   Int_t           idMc[300];   //[nMc]
   Int_t           mothMc[300];   //[nMc]
   Int_t           nDauMc[300];   //[nMc]
   Float_t         xMc[300];   //[nMc]
   Float_t         yMc[300];   //[nMc]
   Float_t         zMc[300];   //[nMc]
   Int_t           nDstar;
   Float_t         massDstar[100];   //[nDstar]
   Float_t         pDstar[100];   //[nDstar]
   Float_t         thDstar[100];   //[nDstar]
   Float_t         phiDstar[100];   //[nDstar]
   Float_t         errMassDstar[100];   //[nDstar]
   Float_t         m0Dstar[100];   //[nDstar]
   Float_t         xDstar[100];   //[nDstar]
   Float_t         yDstar[100];   //[nDstar]
   Float_t         zDstar[100];   //[nDstar]
   Float_t         s2xDstar[100];   //[nDstar]
   Float_t         s2yDstar[100];   //[nDstar]
   Float_t         s2zDstar[100];   //[nDstar]
   Float_t         chi2Dstar[100];   //[nDstar]
   Int_t           dofDstar[100];   //[nDstar]
   Int_t           stDstar[100];   //[nDstar]
   Int_t           ndauDstar[100];   //[nDstar]
   Int_t           MCDstar[100];   //[nDstar]
   Int_t           nDstarBS;
   Float_t         massDstarBS[100];   //[nDstarBS]
   Float_t         chi2DstarBS[100];   //[nDstarBS]
   Int_t           dofDstarBS[100];   //[nDstarBS]
   Float_t         spixDstarBS[100];   //[nDstarBS]
   Float_t         spiyDstarBS[100];   //[nDstarBS]
   Float_t         spizDstarBS[100];   //[nDstarBS]
   Float_t         deltaMDstarBS[100];   //[nDstarBS]

   Int_t           d1DstarIndex[100];   //[nDstar]
   Int_t           d1DstarLund[100];   //[nDstar]
   Int_t           d2DstarIndex[100];   //[nDstar]
   Int_t           d2DstarLund[100];   //[nDstar]
   Int_t           nD0;
   Float_t         massD0[100];   //[nD0]
   Float_t         pD0[100];   //[nD0]
   Float_t         thD0[100];   //[nD0]
   Float_t         phiD0[100];   //[nD0]
   Float_t         errMassD0[100];   //[nD0]
   Float_t         m0D0[100];   //[nD0]
   Float_t         xD0[100];   //[nD0]
   Float_t         yD0[100];   //[nD0]
   Float_t         zD0[100];   //[nD0]
   Float_t         s2xD0[100];   //[nD0]
   Float_t         s2yD0[100];   //[nD0]
   Float_t         s2zD0[100];   //[nD0]
   Float_t         chi2D0[100];   //[nD0]
   Int_t           dofD0[100];   //[nD0]
   Int_t           stD0[100];   //[nD0]
   Int_t           ndauD0[100];   //[nD0]
   Int_t           MCD0[100];   //[nD0]
   Int_t           d1D0Index[100];   //[nD0]
   Int_t           d1D0Lund[100];   //[nD0]
   Int_t           d2D0Index[100];   //[nD0]
   Int_t           d2D0Lund[100];   //[nD0]
   Int_t           d3D0Index[100];   //[nD0]
   Int_t           d3D0Lund[100];   //[nD0]
   Int_t           d4D0Index[100];   //[nD0]
   Int_t           d4D0Lund[100];   //[nD0]
   Float_t         m2pDalitzD0[100];   //[nD0]
   Float_t         m2mDalitzD0[100];   //[nD0]
   Float_t         m2zDalitzD0[100];   //[nD0]
   Int_t           stDalitzD0[100];
   Float_t         mTotDalitzD0[100];
   Float_t         chi2DalitzD0[100];
   Int_t           dofDalitzD0[100];
   Int_t           nKs;
   Float_t         massKs[100];   //[nKs]
   Float_t         pKs[100];   //[nKs]
   Float_t         thKs[100];   //[nKs]
   Float_t         phiKs[100];   //[nKs]
   Float_t         errMassKs[100];   //[nKs]
   Float_t         m0Ks[100];   //[nKs]
   Float_t         xKs[100];   //[nKs]
   Float_t         yKs[100];   //[nKs]
   Float_t         zKs[100];   //[nKs]
   Float_t         s2xKs[100];   //[nKs]
   Float_t         s2yKs[100];   //[nKs]
   Float_t         s2zKs[100];   //[nKs]
   Float_t         chi2Ks[100];   //[nKs]
   Int_t           dofKs[100];   //[nKs]
   Int_t           stKs[100];   //[nKs]
   Int_t           ndauKs[100];   //[nKs]
   Int_t           MCKs[100];   //[nKs]
   Int_t           d1KsIndex[100];   //[nKs]
   Int_t           d1KsLund[100];   //[nKs]
   Int_t           d2KsIndex[100];   //[nKs]
   Int_t           d2KsLund[100];   //[nKs]
   Int_t           nTrk;
   Float_t         cTheTrk[100];   //[nTrk]
   Float_t         sTheTrk[100];   //[nTrk]
   Int_t           nPhotTrk[100];   //[nTrk]
   Int_t           nexPhot0Trk[100];   //[nTrk]
   Int_t           nexPhot1Trk[100];   //[nTrk]
   Int_t           nexPhot2Trk[100];   //[nTrk]
   Int_t           nexPhot3Trk[100];   //[nTrk]
   Int_t           nexPhot4Trk[100];   //[nTrk]
   Int_t           isvtTrk[100];   //[nTrk]
   Int_t           nsvtTrk[100];   //[nTrk]
   Int_t           fhitTrk[100];   //[nTrk]
   Int_t           ndchTrk[100];   //[nTrk]
   Int_t           lhitTrk[100];   //[nTrk]
   Float_t         tLenTrk[100];   //[nTrk]
   Float_t         teffTrk[100];   //[nTrk]
   Int_t           chargeTrk[100];   //[nTrk]
   Float_t         momentumTrk[100];   //[nTrk]
   Float_t         thetaTrk[100];   //[nTrk]
   Float_t         phiTrk[100];   //[nTrk]
   Int_t           muonIdTrk[100];   //[nTrk]
   Int_t           elecIdTrk[100];   //[nTrk]
   Int_t           kaonIdTrk[100];   //[nTrk]
   Int_t           pionIdTrk[100];   //[nTrk]
   Int_t           protonIdTrk[100];   //[nTrk]
   Int_t           idTrk[100];   //[nTrk]  
   Int_t           IndexTrk[100];   //[nTrk]
   Int_t           IndexNtTrk[100];   //[nTrk]
   Int_t           effCorTrk[100];   //[nTrk]    
   Int_t           sEffCorTrk[100];   //[nTrk]

   // List of branches
   TBranch        *b_event;   //!
   TBranch        *b_runNumber;   //!
   TBranch        *b_platform;   //!
   TBranch        *b_partition;   //!
   TBranch        *b_upperID;   //!
   TBranch        *b_lowerID;   //!
   TBranch        *b_primVtxX;   //!
   TBranch        *b_primVtxY;   //!
   TBranch        *b_primVtxZ;   //!
   TBranch        *b_primVtxCovXX;   //!
   TBranch        *b_primVtxCovYY;   //!
   TBranch        *b_primVtxCovZZ;   //!
   TBranch        *b_primVtxCovXY;   //!
   TBranch        *b_primVtxCovYZ;   //!
   TBranch        *b_primVtxCovXZ;   //!
   TBranch        *b_primVtxChi2;   //!
   TBranch        *b_primVtxNdof;   //!
   /*
   TBranch        *b_BCountFilter;   //!
   TBranch        *b_DchTrig;   //!
   TBranch        *b_EmcTrig;   //!
   TBranch        *b_R2All;   //!
   TBranch        *b_nGTLFid;   //!
   TBranch        *b_nChgFid;   //!
   TBranch        *b_eTotFid;   //!
   TBranch        *b_PrimVtxdr;   //!
   TBranch        *b_PrimVtxdz;   //!
   TBranch        *b_VtxProb;   //!
   */
   TBranch        *b_beamSX;   //!
   TBranch        *b_beamSY;   //!
   TBranch        *b_beamSZ;   //!
   TBranch        *b_beamSCovXX;   //!
   TBranch        *b_beamSCovYY;   //!
   TBranch        *b_beamSCovZZ;   //!
   TBranch        *b_beamSCovXZ;   //!
   TBranch        *b_pxUps;   //!
   TBranch        *b_pyUps;   //!
   TBranch        *b_pzUps;   //!
   TBranch        *b_eUps;   //!
   TBranch        *b_nMc;   //!
   TBranch        *b_pMc;   //!
   TBranch        *b_massMc;   //!
   TBranch        *b_thetaMc;   //!
   TBranch        *b_phiMc;   //!
   TBranch        *b_idMc;   //!
   TBranch        *b_mothMc;   //!
   TBranch        *b_nDauMc;   //!
   TBranch        *b_xMc;   //!
   TBranch        *b_yMc;   //!
   TBranch        *b_zMc;   //!
   TBranch        *b_nDstar;   //!
   TBranch        *b_massDstar;   //!
   TBranch        *b_pDstar;   //!
   TBranch        *b_thDstar;   //!
   TBranch        *b_phiDstar;   //!
   TBranch        *b_errMassDstar;   //!
   TBranch        *b_m0Dstar;   //!
   TBranch        *b_xDstar;   //!
   TBranch        *b_yDstar;   //!
   TBranch        *b_zDstar;   //!
   TBranch        *b_s2xDstar;   //!
   TBranch        *b_s2yDstar;   //!
   TBranch        *b_s2zDstar;   //!
   TBranch        *b_chi2Dstar;   //!
   TBranch        *b_dofDstar;   //!
   TBranch        *b_stDstar;   //!
   TBranch        *b_ndauDstar;   //!
   TBranch        *b_MCDstar;   //!
   TBranch        *b_nDstarBS;   //!
   TBranch        *b_massDstarBS;   //!
   TBranch        *b_chi2DstarBS;   //!
   TBranch        *b_dofDstarBS;   //!
   TBranch        *b_spixDstarBS;   //!
   TBranch        *b_spiyDstarBS;   //!
   TBranch        *b_spizDstarBS;   //!
   TBranch        *b_deltaMDstarBS;   //!
   TBranch        *b_d1DstarIndex;   //!
   TBranch        *b_d1DstarLund;   //!
   TBranch        *b_d2DstarIndex;   //!
   TBranch        *b_d2DstarLund;   //!
   TBranch        *b_nD0;   //!
   TBranch        *b_massD0;   //!
   TBranch        *b_pD0;   //!
   TBranch        *b_thD0;   //!
   TBranch        *b_phiD0;   //!
   TBranch        *b_errMassD0;   //!
   TBranch        *b_m0D0;   //!
   TBranch        *b_xD0;   //!
   TBranch        *b_yD0;   //!
   TBranch        *b_zD0;   //!
   TBranch        *b_s2xD0;   //!
   TBranch        *b_s2yD0;   //!
   TBranch        *b_s2zD0;   //!
   TBranch        *b_chi2D0;   //!
   TBranch        *b_dofD0;   //!
   TBranch        *b_stD0;   //!
   TBranch        *b_ndauD0;   //!
   TBranch        *b_MCD0;   //!
   TBranch        *b_d1D0Index;   //!
   TBranch        *b_d1D0Lund;   //!
   TBranch        *b_d2D0Index;   //!
   TBranch        *b_d2D0Lund;   //!
   TBranch        *b_d3D0Index;   //!
   TBranch        *b_d3D0Lund;   //!
   TBranch        *b_d4D0Index;   //!
   TBranch        *b_d4D0Lund;   //!
   TBranch        *b_m2pDalitzD0;   //!
   TBranch        *b_m2mDalitzD0;   //!
   TBranch        *b_m2zDalitzD0;   //!
   TBranch        *b_stDalitzD0;   //!
   TBranch        *b_mTotDalitzD0;   //!
   TBranch        *b_chi2DalitzD0;   //!
   TBranch        *b_dofDalitzD0;   //!
   TBranch        *b_nKs;   //!
   TBranch        *b_massKs;   //!
   TBranch        *b_pKs;   //!
   TBranch        *b_thKs;   //!
   TBranch        *b_phiKs;   //!
   TBranch        *b_errMassKs;   //!
   TBranch        *b_m0Ks;   //!
   TBranch        *b_xKs;   //!
   TBranch        *b_yKs;   //!
   TBranch        *b_zKs;   //!
   TBranch        *b_s2xKs;   //!
   TBranch        *b_s2yKs;   //!
   TBranch        *b_s2zKs;   //!
   TBranch        *b_chi2Ks;   //!
   TBranch        *b_dofKs;   //!
   TBranch        *b_stKs;   //!
   TBranch        *b_ndauKs;   //!
   TBranch        *b_MCKs;   //!
   TBranch        *b_d1KsIndex;   //!
   TBranch        *b_d1KsLund;   //!
   TBranch        *b_d2KsIndex;   //!
   TBranch        *b_d2KsLund;   //!
   TBranch        *b_nTrk;   //!
   TBranch        *b_cTheTrk;   //!
   TBranch        *b_sTheTrk;   //!
   TBranch        *b_nPhotTrk;   //!
   TBranch        *b_nexPhot0Trk;   //!
   TBranch        *b_nexPhot1Trk;   //!
   TBranch        *b_nexPhot2Trk;   //!
   TBranch        *b_nexPhot3Trk;   //!
   TBranch        *b_nexPhot4Trk;   //!
   TBranch        *b_isvtTrk;   //!
   TBranch        *b_nsvtTrk;   //!
   TBranch        *b_fhitTrk;   //!
   TBranch        *b_ndchTrk;   //!
   TBranch        *b_lhitTrk;   //!
   TBranch        *b_tLenTrk;   //!
   TBranch        *b_teffTrk;   //!
   TBranch        *b_chargeTrk;   //!
   TBranch        *b_momentumTrk;   //!
   TBranch        *b_thetaTrk;   //!
   TBranch        *b_phiTrk;   //!
   TBranch        *b_muonIdTrk;   //!
   TBranch        *b_elecIdTrk;   //!
   TBranch        *b_kaonIdTrk;   //!
   TBranch        *b_pionIdTrk;   //!
   TBranch        *b_protonIdTrk;   //!
   TBranch        *b_idTrk;   //!
   TBranch        *b_IndexTrk;   //!
   TBranch        *b_IndexNtTrk;   //!
   TBranch        *b_effCorTrk;   //!
   TBranch        *b_sEffCorTrk;   //!

   inclDstar(TString type,TString dmode,const char* dir=0);
   ~inclDstar();
   Int_t    Cut(Long64_t entry);
   Int_t    GetEntry(Long64_t entry);
   Long64_t LoadTree(Long64_t entry);
   void     Init(TTree *tree);
   void     Loop(Int_t nentries=0);
   Bool_t   Notify();
   void     Show(Long64_t entry = -1);
   //
   Bool_t isDstartoD0Pi(Int_t,Int_t,Int_t,Int_t);
   Int_t isSignalEvt(Int_t,Int_t,Int_t,Bool_t&);
   
   void giveMeDau(Int_t index,Int_t* dauarray); 
   void giveMeDau(Int_t* motharray, Int_t id, Int_t* dauarray);
   void printInfo(Int_t*);
   
   Int_t isD0true(Int_t,Int_t,Int_t,Int_t,Int_t);
   Int_t isKstrue(Int_t iMc_KsPi1,Int_t iMc_KsPi2);
  
   Float_t Alpha(const TVector3 & P1,const TVector3 & P2,const TVector3 & Q);
};

#endif

#ifdef inclDstar_cxx


inclDstar::inclDstar(TString type,TString dmode,const char* dir)
{
  TString ntp2;
  _sig_type=type;
  _d0mode=dmode;
  _isData=kFALSE;
  TString filename;
  TString filename1;
  

  assert(_sig_type=="ccbar" || _sig_type=="signalp" || _sig_type=="signalm"|| _sig_type=="On" ||_sig_type=="On1234" ||_sig_type=="On5");
  TChain* tree=new TChain("ntp2");
  
  if (dir) {
    filename.Append(dir);
     filename.Append("/");
  } else filename="./";
  
  cout<<"reading event of type: "<<type<<endl;
  
  if (type=="ccbar"){
    if (dir==0) filename+="./prod-32-skim18c/inclDst/MC/ccbar/";
    filename+="SP-1005-AllEventsSkim-R14-*.root";
    tree->Add(filename);
  }
  else if (type=="On"){
    if (dir==0) filename+="./prod-32-skim18c/inclDst/DATA/";
    _isData=kTRUE;
    filename+="DstD0ToKsHpHm-Run*.root";
    tree->Add(filename);
  }
  else if (type=="On5"){
    if (dir==0) filename+="./prod-32-skim18c/inclDst/DATA/";
    _isData=kTRUE;
    filename+="DstD0ToKsHpHm-Run5*.root";
    tree->Add(filename);
  }
  else if (type=="On1234"){
    if (dir==0) filename+="./prod-32-skim18c/inclDst/DATA/";
    _isData=kTRUE;
    filename1=filename+"DstD0ToKsHpHm-Run1*.root";
    tree->Add(filename1);
    filename1=filename+"DstD0ToKsHpHm-Run2*.root";
    tree->Add(filename1);
    filename1=filename+"DstD0ToKsHpHm-Run3*.root";
    tree->Add(filename1);
    filename1=filename+"DstD0ToKsHpHm-Run4*.root";
    tree->Add(filename1);
  }
  else if (type=="signalm" && dmode=="kspipi"){
    if (dir==0) filename+="./prod-32-skim18c/inclDst/MC/Signal/";
    filename+="SP-2269-*.root";
    tree->Add(filename);
  }
  else if (type=="signalp" && dmode=="kspipi"){
    //if (dir==0) filename+="./prod-32-skim18c/inclDst/MC/Signal/";
    if (dir==0) filename+="d0mix/";
    filename+="SP-2262-*.root";
    tree->Add(filename);
  }
  else if (type=="signalm" && dmode=="kskk"){
    if (dir==0) filename+="./prod-32-skim18c/inclDst/MC/Signal/";
    filename+="SP-2261-*.root";
    tree->Add(filename);
  }
  else if (type=="signalp" && dmode=="kskk"){
    if (dir==0) filename+="./prod-32-skim18c/inclDst/MC/Signal/";
    filename+="SP-2272-*.root";
    tree->Add(filename);
  }
  cout<<"loading root file " << filename << endl;
  cout<<"done"<<endl;
  
  Init(tree);
}
  
  
inclDstar::~inclDstar()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t inclDstar::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t inclDstar::LoadTree(Long64_t entry)
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

void inclDstar::Init(TTree *tree)
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
   fChain->SetBranchAddress("platform",&platform);
   fChain->SetBranchAddress("partition",&partition);
   fChain->SetBranchAddress("upperID",&upperID);
   fChain->SetBranchAddress("lowerID",&lowerID);
   fChain->SetBranchAddress("primVtxX",&primVtxX);
   fChain->SetBranchAddress("primVtxY",&primVtxY);
   fChain->SetBranchAddress("primVtxZ",&primVtxZ);
   fChain->SetBranchAddress("primVtxCovXX",&primVtxCovXX);
   fChain->SetBranchAddress("primVtxCovYY",&primVtxCovYY);
   fChain->SetBranchAddress("primVtxCovZZ",&primVtxCovZZ);
   fChain->SetBranchAddress("primVtxCovXY",&primVtxCovXY);
   fChain->SetBranchAddress("primVtxCovYZ",&primVtxCovYZ);
   fChain->SetBranchAddress("primVtxCovXZ",&primVtxCovXZ);
   fChain->SetBranchAddress("primVtxChi2",&primVtxChi2);
   fChain->SetBranchAddress("primVtxNdof",&primVtxNdof);
   /*
   fChain->SetBranchAddress("BCountFilter",&BCountFilter);
   fChain->SetBranchAddress("DchTrig",&DchTrig);
   fChain->SetBranchAddress("EmcTrig",&EmcTrig);
   fChain->SetBranchAddress("R2All",&R2All);
   fChain->SetBranchAddress("nGTLFid",&nGTLFid);
   fChain->SetBranchAddress("nChgFid",&nChgFid);
   fChain->SetBranchAddress("eTotFid",&eTotFid);
   fChain->SetBranchAddress("PrimVtxdr",&PrimVtxdr);
   fChain->SetBranchAddress("PrimVtxdz",&PrimVtxdz);
   fChain->SetBranchAddress("VtxProb",&VtxProb);
   */
   fChain->SetBranchAddress("beamSX",&beamSX);
   fChain->SetBranchAddress("beamSY",&beamSY);
   fChain->SetBranchAddress("beamSZ",&beamSZ);
   fChain->SetBranchAddress("beamSCovXX",&beamSCovXX);
   fChain->SetBranchAddress("beamSCovYY",&beamSCovYY);
   fChain->SetBranchAddress("beamSCovZZ",&beamSCovZZ);
   fChain->SetBranchAddress("beamSCovXZ",&beamSCovXZ);
   fChain->SetBranchAddress("pxUps",&pxUps);
   fChain->SetBranchAddress("pyUps",&pyUps);
   fChain->SetBranchAddress("pzUps",&pzUps);
   fChain->SetBranchAddress("eUps",&eUps);
   //mc
   if(!_isData){
     cout<<"in if(!_isdata)"<<endl;
     fChain->SetBranchAddress("nMc",&nMc);
     fChain->SetBranchAddress("pMc",pMc);
     fChain->SetBranchAddress("massMc",massMc);
     fChain->SetBranchAddress("thetaMc",thetaMc);
     fChain->SetBranchAddress("phiMc",phiMc);
     fChain->SetBranchAddress("idMc",idMc);
     fChain->SetBranchAddress("mothMc",mothMc);
     fChain->SetBranchAddress("nDauMc",nDauMc);
     fChain->SetBranchAddress("xMc",xMc);
     fChain->SetBranchAddress("yMc",yMc);
     fChain->SetBranchAddress("zMc",zMc);
   }  
   fChain->SetBranchAddress("nDstar",&nDstar);
   fChain->SetBranchAddress("massDstar",massDstar);
   fChain->SetBranchAddress("pDstar",pDstar);
   fChain->SetBranchAddress("thDstar",thDstar);
   fChain->SetBranchAddress("phiDstar",phiDstar);
   fChain->SetBranchAddress("errMassDstar",errMassDstar);
   fChain->SetBranchAddress("m0Dstar",m0Dstar);
   fChain->SetBranchAddress("xDstar",xDstar);
   fChain->SetBranchAddress("yDstar",yDstar);
   fChain->SetBranchAddress("zDstar",zDstar);
   fChain->SetBranchAddress("s2xDstar",s2xDstar);
   fChain->SetBranchAddress("s2yDstar",s2yDstar);
   fChain->SetBranchAddress("s2zDstar",s2zDstar);
   fChain->SetBranchAddress("chi2Dstar",chi2Dstar);
   fChain->SetBranchAddress("dofDstar",dofDstar);
   fChain->SetBranchAddress("stDstar",stDstar);
   fChain->SetBranchAddress("ndauDstar",ndauDstar);
   if(!_isData)
     fChain->SetBranchAddress("MCDstar",MCDstar);
   fChain->SetBranchAddress("nDstarBS",&nDstarBS);
   fChain->SetBranchAddress("massDstarBS",massDstarBS);
   fChain->SetBranchAddress("chi2DstarBS",chi2DstarBS);
   fChain->SetBranchAddress("dofDstarBS",dofDstarBS);
   fChain->SetBranchAddress("spixDstarBS",spixDstarBS);
   fChain->SetBranchAddress("spiyDstarBS",spiyDstarBS);
   fChain->SetBranchAddress("spizDstarBS",spizDstarBS);
   fChain->SetBranchAddress("deltaMDstarBS",deltaMDstarBS);
   fChain->SetBranchAddress("d1DstarIndex",d1DstarIndex);
   fChain->SetBranchAddress("d1DstarLund",d1DstarLund);
   fChain->SetBranchAddress("d2DstarIndex",d2DstarIndex);
   fChain->SetBranchAddress("d2DstarLund",d2DstarLund);
   fChain->SetBranchAddress("nD0",&nD0);
   fChain->SetBranchAddress("massD0",massD0);
   fChain->SetBranchAddress("pD0",pD0);
   fChain->SetBranchAddress("thD0",thD0);
   fChain->SetBranchAddress("phiD0",phiD0);
   fChain->SetBranchAddress("errMassD0",errMassD0);
   fChain->SetBranchAddress("m0D0",m0D0);
   fChain->SetBranchAddress("xD0",xD0);
   fChain->SetBranchAddress("yD0",yD0);
   fChain->SetBranchAddress("zD0",zD0);
   fChain->SetBranchAddress("s2xD0",s2xD0);
   fChain->SetBranchAddress("s2yD0",s2yD0);
   fChain->SetBranchAddress("s2zD0",s2zD0);
   fChain->SetBranchAddress("chi2D0",chi2D0);
   fChain->SetBranchAddress("dofD0",dofD0);
   fChain->SetBranchAddress("stD0",stD0);
   fChain->SetBranchAddress("ndauD0",ndauD0);
   if(!_isData)
     fChain->SetBranchAddress("MCD0",MCD0);
   fChain->SetBranchAddress("d1D0Index",d1D0Index);
   fChain->SetBranchAddress("d1D0Lund",d1D0Lund);
   fChain->SetBranchAddress("d2D0Index",d2D0Index);
   fChain->SetBranchAddress("d2D0Lund",d2D0Lund);
   fChain->SetBranchAddress("d3D0Index",d3D0Index);
   fChain->SetBranchAddress("d3D0Lund",d3D0Lund);
   fChain->SetBranchAddress("d4D0Index",d4D0Index);
   fChain->SetBranchAddress("d4D0Lund",d4D0Lund);
   fChain->SetBranchAddress("m2pDalitzD0",m2pDalitzD0);
   fChain->SetBranchAddress("m2mDalitzD0",m2mDalitzD0);
   fChain->SetBranchAddress("m2zDalitzD0",m2zDalitzD0);
   fChain->SetBranchAddress("stDalitzD0",stDalitzD0);
   fChain->SetBranchAddress("mTotDalitzD0",mTotDalitzD0);
   fChain->SetBranchAddress("chi2DalitzD0",chi2DalitzD0);
   fChain->SetBranchAddress("dofDalitzD0",dofDalitzD0);
   fChain->SetBranchAddress("nKs",&nKs);
   fChain->SetBranchAddress("massKs",massKs);
   fChain->SetBranchAddress("pKs",pKs);
   fChain->SetBranchAddress("thKs",thKs);
   fChain->SetBranchAddress("phiKs",phiKs);
   fChain->SetBranchAddress("errMassKs",errMassKs);
   fChain->SetBranchAddress("m0Ks",m0Ks);
   fChain->SetBranchAddress("xKs",xKs);
   fChain->SetBranchAddress("yKs",yKs);
   fChain->SetBranchAddress("zKs",zKs);
   fChain->SetBranchAddress("s2xKs",s2xKs);
   fChain->SetBranchAddress("s2yKs",s2yKs);
   fChain->SetBranchAddress("s2zKs",s2zKs);
   fChain->SetBranchAddress("chi2Ks",chi2Ks);
   fChain->SetBranchAddress("dofKs",dofKs);
   fChain->SetBranchAddress("stKs",stKs);
   fChain->SetBranchAddress("ndauKs",ndauKs);
   if(!_isData)
     fChain->SetBranchAddress("MCKs",MCKs);
   fChain->SetBranchAddress("d1KsIndex",d1KsIndex);
   fChain->SetBranchAddress("d1KsLund",d1KsLund);
   fChain->SetBranchAddress("d2KsIndex",d2KsIndex);
   fChain->SetBranchAddress("d2KsLund",d2KsLund);
   fChain->SetBranchAddress("nTrk",&nTrk);
   fChain->SetBranchAddress("cTheTrk",cTheTrk);
   fChain->SetBranchAddress("sTheTrk",sTheTrk);
   fChain->SetBranchAddress("nPhotTrk",nPhotTrk);
   fChain->SetBranchAddress("nexPhot0Trk",nexPhot0Trk);
   fChain->SetBranchAddress("nexPhot1Trk",nexPhot1Trk);
   fChain->SetBranchAddress("nexPhot2Trk",nexPhot2Trk);
   fChain->SetBranchAddress("nexPhot3Trk",nexPhot3Trk);
   fChain->SetBranchAddress("nexPhot4Trk",nexPhot4Trk);
   fChain->SetBranchAddress("isvtTrk",isvtTrk);
   fChain->SetBranchAddress("nsvtTrk",nsvtTrk);
   fChain->SetBranchAddress("fhitTrk",fhitTrk);
   fChain->SetBranchAddress("ndchTrk",ndchTrk);
   fChain->SetBranchAddress("lhitTrk",lhitTrk);
   fChain->SetBranchAddress("tLenTrk",tLenTrk);
   fChain->SetBranchAddress("teffTrk",teffTrk);
   fChain->SetBranchAddress("chargeTrk",chargeTrk);
   fChain->SetBranchAddress("momentumTrk",momentumTrk);
   fChain->SetBranchAddress("thetaTrk",thetaTrk);
   fChain->SetBranchAddress("phiTrk",phiTrk);
   fChain->SetBranchAddress("muonIdTrk",muonIdTrk);
   fChain->SetBranchAddress("elecIdTrk",elecIdTrk);
   fChain->SetBranchAddress("kaonIdTrk",kaonIdTrk);
   fChain->SetBranchAddress("pionIdTrk",pionIdTrk);
   fChain->SetBranchAddress("protonIdTrk",protonIdTrk);
   if(!_isData){
     fChain->SetBranchAddress("idTrk",idTrk);
     fChain->SetBranchAddress("IndexTrk",IndexTrk);
     fChain->SetBranchAddress("IndexNtTrk",IndexNtTrk);
     fChain->SetBranchAddress("effCorTrk",effCorTrk);
     fChain->SetBranchAddress("sEffCorTrk",sEffCorTrk);
   }
   Notify();
}

Bool_t inclDstar::Notify()
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
   b_platform = fChain->GetBranch("platform");
   b_partition = fChain->GetBranch("partition");
   b_upperID = fChain->GetBranch("upperID");
   b_lowerID = fChain->GetBranch("lowerID");
   b_primVtxX = fChain->GetBranch("primVtxX");
   b_primVtxY = fChain->GetBranch("primVtxY");
   b_primVtxZ = fChain->GetBranch("primVtxZ");
   b_primVtxCovXX = fChain->GetBranch("primVtxCovXX");
   b_primVtxCovYY = fChain->GetBranch("primVtxCovYY");
   b_primVtxCovZZ = fChain->GetBranch("primVtxCovZZ");
   b_primVtxCovXY = fChain->GetBranch("primVtxCovXY");
   b_primVtxCovYZ = fChain->GetBranch("primVtxCovYZ");
   b_primVtxCovXZ = fChain->GetBranch("primVtxCovXZ");
   b_primVtxChi2 = fChain->GetBranch("primVtxChi2");
   b_primVtxNdof = fChain->GetBranch("primVtxNdof");
   /*
   b_BCountFilter = fChain->GetBranch("BCountFilter");
   b_DchTrig = fChain->GetBranch("DchTrig");
   b_EmcTrig = fChain->GetBranch("EmcTrig");
   b_R2All = fChain->GetBranch("R2All");
   b_nGTLFid = fChain->GetBranch("nGTLFid");
   b_nChgFid = fChain->GetBranch("nChgFid");
   b_eTotFid = fChain->GetBranch("eTotFid");
   b_PrimVtxdr = fChain->GetBranch("PrimVtxdr");
   b_PrimVtxdz = fChain->GetBranch("PrimVtxdz");
   b_VtxProb = fChain->GetBranch("VtxProb");
   */
   b_beamSX = fChain->GetBranch("beamSX");
   b_beamSY = fChain->GetBranch("beamSY");
   b_beamSZ = fChain->GetBranch("beamSZ");
   b_beamSCovXX = fChain->GetBranch("beamSCovXX");
   b_beamSCovYY = fChain->GetBranch("beamSCovYY");
   b_beamSCovZZ = fChain->GetBranch("beamSCovZZ");
   b_beamSCovXZ = fChain->GetBranch("beamSCovXZ");
   b_pxUps = fChain->GetBranch("pxUps");
   b_pyUps = fChain->GetBranch("pyUps");
   b_pzUps = fChain->GetBranch("pzUps");
   b_eUps = fChain->GetBranch("eUps");
   if(!_isData){
     b_nMc = fChain->GetBranch("nMc");
     b_pMc = fChain->GetBranch("pMc");
     b_massMc = fChain->GetBranch("massMc");
     b_thetaMc = fChain->GetBranch("thetaMc");
     b_phiMc = fChain->GetBranch("phiMc");
     b_idMc = fChain->GetBranch("idMc");
     b_mothMc = fChain->GetBranch("mothMc");
     b_nDauMc = fChain->GetBranch("nDauMc");
     b_xMc = fChain->GetBranch("xMc");
     b_yMc = fChain->GetBranch("yMc");
     b_zMc = fChain->GetBranch("zMc");
   }
   b_nDstar = fChain->GetBranch("nDstar");
   b_massDstar = fChain->GetBranch("massDstar");
   b_pDstar = fChain->GetBranch("pDstar");
   b_thDstar = fChain->GetBranch("thDstar");
   b_phiDstar = fChain->GetBranch("phiDstar");
   b_errMassDstar = fChain->GetBranch("errMassDstar");
   b_m0Dstar = fChain->GetBranch("m0Dstar");
   b_xDstar = fChain->GetBranch("xDstar");
   b_yDstar = fChain->GetBranch("yDstar");
   b_zDstar = fChain->GetBranch("zDstar");
   b_s2xDstar = fChain->GetBranch("s2xDstar");
   b_s2yDstar = fChain->GetBranch("s2yDstar");
   b_s2zDstar = fChain->GetBranch("s2zDstar");
   b_chi2Dstar = fChain->GetBranch("chi2Dstar");
   b_dofDstar = fChain->GetBranch("dofDstar");
   b_stDstar = fChain->GetBranch("stDstar");
   b_ndauDstar = fChain->GetBranch("ndauDstar");
   if(!_isData)
     b_MCDstar = fChain->GetBranch("MCDstar");
   b_nDstarBS = fChain->GetBranch("nDstarBS");
   b_massDstarBS = fChain->GetBranch("massDstarBS");
   b_chi2DstarBS = fChain->GetBranch("chi2DstarBS");
   b_dofDstarBS = fChain->GetBranch("dofDstarBS");
   b_spixDstarBS = fChain->GetBranch("spixDstarBS");
   b_spiyDstarBS = fChain->GetBranch("spiyDstarBS");
   b_spizDstarBS = fChain->GetBranch("spizDstarBS");
   b_deltaMDstarBS = fChain->GetBranch("deltaMDstarBS");
   b_d1DstarIndex = fChain->GetBranch("d1DstarIndex");
   b_d1DstarLund = fChain->GetBranch("d1DstarLund");
   b_d2DstarIndex = fChain->GetBranch("d2DstarIndex");
   b_d2DstarLund = fChain->GetBranch("d2DstarLund");
   b_nD0 = fChain->GetBranch("nD0");
   b_massD0 = fChain->GetBranch("massD0");
   b_pD0 = fChain->GetBranch("pD0");
   b_thD0 = fChain->GetBranch("thD0");
   b_phiD0 = fChain->GetBranch("phiD0");
   b_errMassD0 = fChain->GetBranch("errMassD0");
   b_m0D0 = fChain->GetBranch("m0D0");
   b_xD0 = fChain->GetBranch("xD0");
   b_yD0 = fChain->GetBranch("yD0");
   b_zD0 = fChain->GetBranch("zD0");
   b_s2xD0 = fChain->GetBranch("s2xD0");
   b_s2yD0 = fChain->GetBranch("s2yD0");
   b_s2zD0 = fChain->GetBranch("s2zD0");
   b_chi2D0 = fChain->GetBranch("chi2D0");
   b_dofD0 = fChain->GetBranch("dofD0");
   b_stD0 = fChain->GetBranch("stD0");
   b_ndauD0 = fChain->GetBranch("ndauD0");
   if(!_isData)
     b_MCD0 = fChain->GetBranch("MCD0");
   b_d1D0Index = fChain->GetBranch("d1D0Index");
   b_d1D0Lund = fChain->GetBranch("d1D0Lund");
   b_d2D0Index = fChain->GetBranch("d2D0Index");
   b_d2D0Lund = fChain->GetBranch("d2D0Lund");
   b_d3D0Index = fChain->GetBranch("d3D0Index");
   b_d3D0Lund = fChain->GetBranch("d3D0Lund");
   b_d4D0Index = fChain->GetBranch("d4D0Index");
   b_d4D0Lund = fChain->GetBranch("d4D0Lund");
   b_m2pDalitzD0 = fChain->GetBranch("m2pDalitzD0");
   b_m2mDalitzD0 = fChain->GetBranch("m2mDalitzD0");
   b_m2zDalitzD0 = fChain->GetBranch("m2zDalitzD0");
   b_stDalitzD0 = fChain->GetBranch("stDalitzD0");
   b_mTotDalitzD0 = fChain->GetBranch("mTotDalitzD0");
   b_chi2DalitzD0 = fChain->GetBranch("chi2DalitzD0");
   b_dofDalitzD0 = fChain->GetBranch("dofDalitzD0");
   b_nKs = fChain->GetBranch("nKs");
   b_massKs = fChain->GetBranch("massKs");
   b_pKs = fChain->GetBranch("pKs");
   b_thKs = fChain->GetBranch("thKs");
   b_phiKs = fChain->GetBranch("phiKs");
   b_errMassKs = fChain->GetBranch("errMassKs");
   b_m0Ks = fChain->GetBranch("m0Ks");
   b_xKs = fChain->GetBranch("xKs");
   b_yKs = fChain->GetBranch("yKs");
   b_zKs = fChain->GetBranch("zKs");
   b_s2xKs = fChain->GetBranch("s2xKs");
   b_s2yKs = fChain->GetBranch("s2yKs");
   b_s2zKs = fChain->GetBranch("s2zKs");
   b_chi2Ks = fChain->GetBranch("chi2Ks");
   b_dofKs = fChain->GetBranch("dofKs");
   b_stKs = fChain->GetBranch("stKs");
   b_ndauKs = fChain->GetBranch("ndauKs");
   if(!_isData)
     b_MCKs = fChain->GetBranch("MCKs");
   b_d1KsIndex = fChain->GetBranch("d1KsIndex");
   b_d1KsLund = fChain->GetBranch("d1KsLund");
   b_d2KsIndex = fChain->GetBranch("d2KsIndex");
   b_d2KsLund = fChain->GetBranch("d2KsLund");
   b_nTrk = fChain->GetBranch("nTrk");
   b_cTheTrk = fChain->GetBranch("cTheTrk");
   b_sTheTrk = fChain->GetBranch("sTheTrk");
   b_nPhotTrk = fChain->GetBranch("nPhotTrk");
   b_nexPhot0Trk = fChain->GetBranch("nexPhot0Trk");
   b_nexPhot1Trk = fChain->GetBranch("nexPhot1Trk");
   b_nexPhot2Trk = fChain->GetBranch("nexPhot2Trk");
   b_nexPhot3Trk = fChain->GetBranch("nexPhot3Trk");
   b_nexPhot4Trk = fChain->GetBranch("nexPhot4Trk");
   b_isvtTrk = fChain->GetBranch("isvtTrk");
   b_nsvtTrk = fChain->GetBranch("nsvtTrk");
   b_fhitTrk = fChain->GetBranch("fhitTrk");
   b_ndchTrk = fChain->GetBranch("ndchTrk");
   b_lhitTrk = fChain->GetBranch("lhitTrk");
   b_tLenTrk = fChain->GetBranch("tLenTrk");
   b_teffTrk = fChain->GetBranch("teffTrk");
   b_chargeTrk = fChain->GetBranch("chargeTrk");
   b_momentumTrk = fChain->GetBranch("momentumTrk");
   b_thetaTrk = fChain->GetBranch("thetaTrk");
   b_phiTrk = fChain->GetBranch("phiTrk");
   b_muonIdTrk = fChain->GetBranch("muonIdTrk");
   b_elecIdTrk = fChain->GetBranch("elecIdTrk");
   b_kaonIdTrk = fChain->GetBranch("kaonIdTrk");
   b_pionIdTrk = fChain->GetBranch("pionIdTrk");
   b_protonIdTrk = fChain->GetBranch("protonIdTrk");
   if(!_isData){
     b_idTrk = fChain->GetBranch("idTrk");
     b_IndexTrk = fChain->GetBranch("IndexTrk");
     b_IndexNtTrk = fChain->GetBranch("IndexNtTrk");
     b_effCorTrk = fChain->GetBranch("effCorTrk");
     b_sEffCorTrk = fChain->GetBranch("sEffCorTrk");
   }
   return kTRUE;
}

void inclDstar::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t inclDstar::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef inclDstar_cxx











