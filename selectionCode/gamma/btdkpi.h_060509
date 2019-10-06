#ifndef btdkpi_h
#define btdkpi_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>


//addition
#include <iostream.h>    
#include <TStopwatch.h>  
#include "TLorentzVector.h"  

#include <iomanip>
#include <string>
#include <cstring>

class btdkpi {
  //addition
  TString        _sig_type;
  TString        _super_sig_type;
  TString        _d0mode;
  Bool_t         _isData;  
  TString        _release;
  //addition
  public :
    TTree          *fChain;   //!pointer to the analyzed TTree or TChain
  Int_t           fCurrent; //!current Tree number in a TChain
  //Declaration of leaves types
  Int_t           event;
  Int_t           runNumber;
  Int_t           platform;
  Int_t           partition;       
  Int_t           upperID;
  Int_t           lowerID;
   // Float_t         primVtxX;
   // Float_t         primVtxY;
   // Float_t         primVtxZ;
   // Float_t         primVtxCovXX;
   // Float_t         primVtxCovYY;
   // Float_t         primVtxCovZZ;
   // Float_t         primVtxCovXY;
   // Float_t         primVtxCovYZ;
   // Float_t         primVtxCovXZ;
   // Float_t         primVtxChi2;
   // Int_t           primVtxNdof;
   // UChar_t         BCountFilter;
   // UChar_t         DchTrig;
   // UChar_t         EmcTrig;
   // Float_t         R2All;
   // Int_t           nGTLFid;
   // Int_t           nChgFid;
   // Float_t         eTotFid;
   // Float_t         PrimVtxdr;
   // Float_t         PrimVtxdz;
   // Float_t         VtxProb;
   // Float_t         beamSX;
   // Float_t         beamSY;
   // Float_t         beamSZ;
   // Float_t         beamSCovXX;
   // Float_t         beamSCovYY;
   // Float_t         beamSCovZZ;
   // Float_t         beamSCovXZ;
  Float_t         pxUps;
  Float_t         pyUps;
  Float_t         pzUps;
  Float_t         eUps;
  Int_t           nTrkTot;
  Float_t         W2;
  Float_t         FoxWol2;
  Float_t         FoxWol2Neu;
  Float_t         thrust;
  Float_t         thrustNeu;
  //Mc
  Int_t           nMc;
  Float_t         pMc[300];   //[nMc]
  Float_t         massMc[300];   //[nMc]
  Float_t         thetaMc[300];   //[nMc]
  Float_t         phiMc[300];   //[nMc]
  Int_t           idMc[300];   //[nMc]
  Int_t           mothMc[300];   //[nMc]
  UInt_t          nDauMc[300];   //[nMc]
  Float_t         xMc[300];   //[nMc]
  Float_t         yMc[300];   //[nMc]
  Float_t         zMc[300];   //[nMc]
  //ChB
  Int_t           nChB;
  Float_t         massChB[100];   //[nChB]
  Float_t         pChB[100];   //[nChB]
  Float_t         thChB[100];   //[nChB]
  Float_t         phiChB[100];   //[nChB]
  Float_t         errMassChB[100];   //[nChB]
  Float_t         m0ChB[100];   //[nChB]
  Float_t         xChB[100];   //[nChB]
  Float_t         yChB[100];   //[nChB]
  Float_t         zChB[100];   //[nChB]
  Float_t         s2xChB[100];   //[nChB]
  Float_t         s2yChB[100];   //[nChB]
  Float_t         s2zChB[100];   //[nChB]
  Float_t         chi2ChB[100];   //[nChB]
  Int_t           dofChB[100];   //[nChB]
  Int_t           stChB[100];   //[nChB]
  Int_t           ndauChB[100];   //[nChB]
  Int_t           MCChB[300];   //[nChB]
  Float_t         mseChB[100];   //[nChB]
  Float_t         mHatChB[100];   //[nChB]
  Float_t         deltaeChB[100];   //[nChB]
  Float_t         ThruChB[100];   //[nChB]
  Float_t         thThruChB[100];   //[nChB]
  Float_t         phiThruChB[100];   //[nChB]
  Float_t         cosTBChB[100];   //[nChB]
  Int_t           d1ChBIndex[100];   //[nChB]
  Int_t           d1ChBLund[100];   //[nChB]
  Int_t           d2ChBIndex[100];   //[nChB]
  Int_t           d2ChBLund[100];   //[nChB]
  Float_t         SphericityChB[100];   //[nChB]
  Float_t         CosTsphChB[100];   //[nChB]
  Float_t         LegendreP0ChB[100];   //[nChB]
  Float_t         LegendreP2ChB[100];   //[nChB]
  Float_t         FisherChB[100];   //[nChB]
  Float_t         AustralChChB[100];   //[nChB]
  Float_t         BorealChChB[100];   //[nChB]
  Float_t         maxEnergyChB[100];   //[nChB]
  Float_t         thetaMaxChB[100];   //[nChB]
  Float_t         chargeMaxChB[100];   //[nChB]
  //  Float_t         vtxChi2ChB[100];   //[nChB]
  //  Float_t         vtxNdofChB[100];   //[nChB]
  //  Float_t         vtxDeltaZChB[100];   //[nChB]
  //  Float_t         vtxSigmaZ2ChB[100];   //[nChB]
  //  Float_t         probChi2ChB[100];   //[nChB]
  //  Float_t         BtgBTaggerTagChB[100];   //[nChB]
  //  Float_t         BtgBTaggerCatChB[100];   //[nChB]
  //Dstar0
  Int_t           nDstar0;
  Float_t         massDstar0[100];   //[nDstar0]
  Float_t         pDstar0[100];   //[nDstar0]
  Float_t         thDstar0[100];   //[nDstar0]
  Float_t         phiDstar0[100];   //[nDstar0]
  Float_t         errMassDstar0[100];   //[nDstar0]
  Float_t         m0Dstar0[100];   //[nDstar0]
  Float_t         xDstar0[100];   //[nDstar0]
  Float_t         yDstar0[100];   //[nDstar0]
  Float_t         zDstar0[100];   //[nDstar0]
  Float_t         s2xDstar0[100];   //[nDstar0]
  Float_t         s2yDstar0[100];   //[nDstar0]
  Float_t         s2zDstar0[100];   //[nDstar0]
  Float_t         chi2Dstar0[100];   //[nDstar0]
  Int_t           dofDstar0[100];   //[nDstar0]
  Int_t           stDstar0[100];   //[nDstar0]
  Int_t           ndauDstar0[100];   //[nDstar0]
  Int_t           MCDstar0[100];   //[nDstar0]
  Int_t           d1Dstar0Index[100];   //[nDstar0]
  Int_t           d1Dstar0Lund[100];   //[nDstar0]
  Int_t           d2Dstar0Index[100];   //[nDstar0]
  Int_t           d2Dstar0Lund[100];   //[nDstar0]
  //D0
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
  //Ks
  Int_t           nKs;
  Float_t         decayLengthCovD0[100];//[nKs]
  Float_t         decayLengthD0[100];//[nKs]
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
  //pi0   
  Int_t           nPi0;
  Float_t         massPi0[100];   //[nPi0]
  Float_t         pPi0[100];   //[nPi0]
  Float_t         thPi0[100];   //[nPi0]
  Float_t         phiPi0[100];   //[nPi0]
  Float_t         errMassPi0[100];   //[nPi0]
  Float_t         m0Pi0[100];   //[nPi0]
  Float_t         xPi0[100];   //[nPi0]
  Float_t         yPi0[100];   //[nPi0]
  Float_t         zPi0[100];   //[nPi0]
  Float_t         s2xPi0[100];   //[nPi0]
  Float_t         s2yPi0[100];   //[nPi0]
  Float_t         s2zPi0[100];   //[nPi0]
  Float_t         chi2Pi0[100];   //[nPi0]
  Int_t           dofPi0[100];   //[nPi0]
  Int_t           stPi0[100];   //[nPi0]
  Int_t           ndauPi0[100];   //[nPi0]
  Int_t           MCPi0[100];   //[nPi0]
  Int_t           d1Pi0Index[100];   //[nPi0]
  Int_t           d1Pi0Lund[100];   //[nPi0]
  Int_t           d2Pi0Index[100];   //[nPi0]
  Int_t           d2Pi0Lund[100];   //[nPi0]
  //Trk
  Int_t           nTrk;
  // Int_t           IfrLayTrk[100];   //[nTrk]
  // Int_t           IfrNsTrk[100];   //[nTrk]
  // UChar_t         IfrInnerTrk[100];   //[nTrk]
  // UChar_t         IfrBarrelTrk[100];   //[nTrk]
  // UChar_t         IfrFWDTrk[100];   //[nTrk]
  // UChar_t         IfrBWDTrk[100];   //[nTrk]
  // Float_t         IfrMeasIntLenTrk[100];   //[nTrk]
  // Int_t           IfrFirstHitTrk[100];   //[nTrk]
  // Int_t           IfrLastHitTrk[100];   //[nTrk]
  Float_t         cTheTrk[100];   //[nTrk]
  Float_t         sTheTrk[100];   //[nTrk]
  Int_t           nPhotTrk[100];   //[nTrk]
  Int_t           nexPhot0Trk[100];   //[nTrk]
  Int_t           nexPhot1Trk[100];   //[nTrk]
  Int_t           nexPhot2Trk[100];   //[nTrk]
  Int_t           nexPhot3Trk[100];   //[nTrk]
  Int_t           nexPhot4Trk[100];   //[nTrk]
  Float_t         deltadrcmomTrk[100];   //[nTrk]
  Float_t         lMomTrk[100];   //[nTrk]
  Float_t         ZMom42Trk[100];   //[nTrk]
  Float_t         ecalTrk[100];   //[nTrk]
  Float_t         ecalXTrk[100];   //[nTrk]
  Float_t         ecalYTrk[100];   //[nTrk]
  Float_t         ecalZTrk[100];   //[nTrk]
  Int_t           nCryTrk[100];   //[nTrk]
  Int_t           nBumpTrk[100];   //[nTrk]
  Int_t           isvtTrk[100];   //[nTrk]
  Int_t           nsvtTrk[100];   //[nTrk]
  Int_t           fhitTrk[100];   //[nTrk]
  Int_t           ndchTrk[100];   //[nTrk]
  Int_t           lhitTrk[100];   //[nTrk]
  Float_t         tLenTrk[100];   //[nTrk]
  Float_t         teffTrk[11];   //[nTrk]
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
  //Gam
  Int_t           nGam;
  Float_t         lMomGam[100];   //[nGam]
  Float_t         ZMom42Gam[100];   //[nGam]
  Float_t         ecalGam[100];   //[nGam]
  Float_t         ecalXGam[100];   //[nGam]
  Float_t         ecalYGam[100];   //[nGam]
  Float_t         ecalZGam[100];   //[nGam]
  Int_t           nCryGam[100];   //[nGam]
  Int_t           nBumpGam[100];   //[nGam]
  Float_t         thetaGam[100];   //[nGam]
  Float_t         phiGam[100];   //[nGam]
  Float_t         energyGam[100];   //[nGam]
  Int_t           idGam[100];   //[nGam]
  Int_t           IndexGam[100];   //[nGam]
  Int_t           IndexNtGam[100];   //[nGam]
  Float_t         vetoloGam[9];   //[nGam]
  Float_t         vetohiGam[9];   //[nGam]
  Float_t         vetoeloGam[9];   //[nGam]
  Float_t         vetoehiGam[9];   //[nGam]
  Float_t         minCaloAngleGam[9];   //[nGam]
  Float_t         minCaloDistGam[9];   //[nGam]


  //List of branches
  TBranch        *b_event;   //!
  TBranch        *b_runNumber;   //!
  TBranch        *b_platform;   //!
  TBranch        *b_partition;   //!
  TBranch        *b_upperID;   //!
  TBranch        *b_lowerID;   //!
   // TBranch        *b_primVtxX;   //!
   // TBranch        *b_primVtxY;   //!
   // TBranch        *b_primVtxZ;   //!
   // TBranch        *b_primVtxCovXX;   //!
   // TBranch        *b_primVtxCovYY;   //!
   // TBranch        *b_primVtxCovZZ;   //!
   // TBranch        *b_primVtxCovXY;   //!
   // TBranch        *b_primVtxCovYZ;   //!
   // TBranch        *b_primVtxCovXZ;   //!
   // TBranch        *b_primVtxChi2;   //!
   // TBranch        *b_primVtxNdof;   //!
   // TBranch        *b_BCountFilter;   //!
   // TBranch        *b_DchTrig;   //!
   // TBranch        *b_EmcTrig;   //!
   // TBranch        *b_R2All;   //!
   // TBranch        *b_nGTLFid;   //!
   // TBranch        *b_nChgFid;   //!
   // TBranch        *b_eTotFid;   //!
   // TBranch        *b_PrimVtxdr;   //!
   // TBranch        *b_PrimVtxdz;   //!
   // TBranch        *b_VtxProb;   //!
   // TBranch        *b_beamSX;   //!
   // TBranch        *b_beamSY;   //!
   // TBranch        *b_beamSZ;   //!
   // TBranch        *b_beamSCovXX;   //!
   // TBranch        *b_beamSCovYY;   //!
   // TBranch        *b_beamSCovZZ;   //!
   // TBranch        *b_beamSCovXZ;   //!
  TBranch        *b_pxUps;   //!
  TBranch        *b_pyUps;   //!
  TBranch        *b_pzUps;   //!
  TBranch        *b_eUps;   //!
  TBranch        *b_nTrkTot;   //!
  TBranch        *b_W2;   //!
  TBranch        *b_FoxWol2;   //!
  TBranch        *b_FoxWol2Neu;   //!
  TBranch        *b_thrust;   //!
  TBranch        *b_thrustNeu;   //!
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
  TBranch        *b_zMc;   //
  //ChB
  TBranch        *b_nChB;   //!
  TBranch        *b_massChB;   //!
  TBranch        *b_pChB;   //!
  TBranch        *b_thChB;   //!
  TBranch        *b_phiChB;   //!
  TBranch        *b_errMassChB;   //!
  TBranch        *b_m0ChB;   //!
  TBranch        *b_xChB;   //!
  TBranch        *b_yChB;   //!
  TBranch        *b_zChB;   //!
  TBranch        *b_s2xChB;   //!
  TBranch        *b_s2yChB;   //!
  TBranch        *b_s2zChB;   //!
  TBranch        *b_chi2ChB;   //!
  TBranch        *b_dofChB;   //!
  TBranch        *b_stChB;   //!
  TBranch        *b_ndauChB;   //!
  TBranch        *b_MCChB;   //!
  TBranch        *b_mseChB;   //!
  TBranch        *b_mHatChB;   //!
  TBranch        *b_deltaeChB;   //!
  TBranch        *b_ThruChB;   //!
  TBranch        *b_thThruChB;   //!
  TBranch        *b_phiThruChB;   //!
  TBranch        *b_cosTBChB;   //!
  TBranch        *b_d1ChBIndex;   //!
  TBranch        *b_d1ChBLund;   //!
  TBranch        *b_d2ChBIndex;   //!
  TBranch        *b_d2ChBLund;   //!
  TBranch        *b_SphericityChB;   //!
  TBranch        *b_CosTsphChB;   //!
  TBranch        *b_LegendreP0ChB;   //!
  TBranch        *b_LegendreP2ChB;   //!
  TBranch        *b_FisherChB;   //!
  TBranch        *b_AustralChChB;   //!
  TBranch        *b_BorealChChB;   //!
  TBranch        *b_maxEnergyChB;   //!
  TBranch        *b_thetaMaxChB;   //!
  TBranch        *b_chargeMaxChB;   //!
  //  TBranch        *b_vtxChi2ChB;   //!
  //  TBranch        *b_vtxNdofChB;   //!
  //  TBranch        *b_vtxDeltaZChB;   //!
  //  TBranch        *b_vtxSigmaZ2ChB;   //!
  //  TBranch        *b_probChi2ChB;   //!
  //  TBranch        *b_BtgBTaggerTagChB;   //!
  //  TBranch        *b_BtgBTaggerCatChB;   //!
  //Dstar0
  TBranch        *b_nDstar0;   //!
  TBranch        *b_massDstar0;   //!
  TBranch        *b_pDstar0;   //!
  TBranch        *b_thDstar0;   //!
  TBranch        *b_phiDstar0;   //!
  TBranch        *b_errMassDstar0;   //!
  TBranch        *b_m0Dstar0;   //!
  TBranch        *b_xDstar0;   //!
  TBranch        *b_yDstar0;   //!
  TBranch        *b_zDstar0;   //!
  TBranch        *b_s2xDstar0;   //!
  TBranch        *b_s2yDstar0;   //!
  TBranch        *b_s2zDstar0;   //!
  TBranch        *b_chi2Dstar0;   //!
  TBranch        *b_dofDstar0;   //!
  TBranch        *b_stDstar0;   //!
  TBranch        *b_ndauDstar0;   //!
  TBranch        *b_MCDstar0;   //!
  TBranch        *b_d1Dstar0Index;   //!
  TBranch        *b_d1Dstar0Lund;   //!
  TBranch        *b_d2Dstar0Index;   //!
  TBranch        *b_d2Dstar0Lund;   //!
  //D0
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
  TBranch        *b_m2pDalitzD0;
  TBranch        *b_m2mDalitzD0;
  TBranch        *b_m2zDalitzD0;
  TBranch        *b_stDalitzD0;   //!
  TBranch        *b_mTotDalitzD0;   //!
  TBranch        *b_chi2DalitzD0;   //!
  TBranch        *b_dofDalitzD0;   //!
  //Ks
  TBranch        *b_nKs;   //!
  TBranch        *b_decayLengthCovD0;   //!
  TBranch        *b_decayLengthD0;   //!
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
  TBranch        *b_nPi0;   //!
  TBranch        *b_massPi0;   //!
  TBranch        *b_pPi0;   //!
  TBranch        *b_thPi0;   //!
  TBranch        *b_phiPi0;   //!
  TBranch        *b_errMassPi0;   //!
  TBranch        *b_m0Pi0;   //!
  TBranch        *b_xPi0;   //!
  TBranch        *b_yPi0;   //!
  TBranch        *b_zPi0;   //!
  TBranch        *b_s2xPi0;   //!
  TBranch        *b_s2yPi0;   //!
  TBranch        *b_s2zPi0;   //!
  TBranch        *b_chi2Pi0;   //!
  TBranch        *b_dofPi0;   //!
  TBranch        *b_stPi0;   //!
  TBranch        *b_ndauPi0;   //!
  TBranch        *b_MCPi0;   //!
  TBranch        *b_d1Pi0Index;   //!
  TBranch        *b_d1Pi0Lund;   //!
  TBranch        *b_d2Pi0Index;   //!
  TBranch        *b_d2Pi0Lund;   //!
  //Trk
  TBranch        *b_nTrk;   //!
  //  TBranch        *b_IfrLayTrk;   //!
  //  TBranch        *b_IfrNsTrk;   //!
  //  TBranch        *b_IfrInnerTrk;   //!
  //  TBranch        *b_IfrBarrelTrk;   //!
  //  TBranch        *b_IfrFWDTrk;   //!
  //  TBranch        *b_IfrBWDTrk;   //!
  //  TBranch        *b_IfrMeasIntLenTrk;   //!
  //  TBranch        *b_IfrFirstHitTrk;   //!
  //  TBranch        *b_IfrLastHitTrk;   //!
  TBranch        *b_cTheTrk;   //!
  TBranch        *b_sTheTrk;   //!
  TBranch        *b_nPhotTrk;   //!
  TBranch        *b_nexPhot0Trk;   //!
  TBranch        *b_nexPhot1Trk;   //!
  TBranch        *b_nexPhot2Trk;   //!
  TBranch        *b_nexPhot3Trk;   //!
  TBranch        *b_nexPhot4Trk;   //!
  TBranch        *b_deltadrcmomTrk;   //!
  TBranch        *b_lMomTrk;   //!
  TBranch        *b_ZMom42Trk;   //!
  TBranch        *b_ecalTrk;   //!
  TBranch        *b_ecalXTrk;   //!
  TBranch        *b_ecalYTrk;   //!
  TBranch        *b_ecalZTrk;   //!
  TBranch        *b_nCryTrk;   //!
  TBranch        *b_nBumpTrk;   //!
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
  //nGam
  TBranch        *b_nGam;   //!
  TBranch        *b_lMomGam;   //!
  TBranch        *b_ZMom42Gam;   //!
  TBranch        *b_ecalGam;   //!
  TBranch        *b_ecalXGam;   //!
  TBranch        *b_ecalYGam;   //!
  TBranch        *b_ecalZGam;   //!
  TBranch        *b_nCryGam;   //!
  TBranch        *b_nBumpGam;   //!
  TBranch        *b_thetaGam;   //!
  TBranch        *b_phiGam;   //!
  TBranch        *b_energyGam;   //!
  TBranch        *b_idGam;   //!
  TBranch        *b_IndexGam;   //!
  TBranch        *b_IndexNtGam;   //!
  TBranch        *b_vetoloGam;   //!
  TBranch        *b_vetohiGam;   //!
  TBranch        *b_vetoeloGam;   //!
  TBranch        *b_vetoehiGam;   //!
  TBranch        *b_minCaloAngleGam;   //!
  TBranch        *b_minCaloDistGam;   //!

  //  btdkpi(TTree *tree=0);
  //  btdkpi(TString type,TString dmode,const char* dir=0,const char* release="rel-24");
  //    btdkpi(TString type,TString dmode,const char* dir=0,const char* release="analysis-32");
  //  btdkpi(TString type,TString dmode,const char* dir=0,const char* release="analysis-30");
  btdkpi(TString type,TString dmode,const char* dir=0,const char* release="analysis-51");
  ~btdkpi();
  
  Int_t  Cut(Int_t entry);
  Int_t  GetEntry(Int_t entry);
  Int_t  LoadTree(Int_t entry);
  void   Init(TTree *tree);
  void   Loop(Int_t nentries=0);
  Bool_t Notify();
  void   Show(Int_t entry = -1);
   
  Bool_t isBtoDK(Int_t,Int_t,Int_t,Int_t);
  Int_t isSignalEvt(Int_t,Int_t,Int_t);
   
  void giveMeDau(Int_t index,Int_t* dauarray); 
  void giveMeDau(Int_t* motharray, Int_t id, Int_t* dauarray);
  void printInfo(Int_t*);
   
  Int_t isD0true(Int_t,Int_t,Int_t,Int_t,Int_t);
  Int_t isKstrue(Int_t imc_kspi1,Int_t imc_kspi2);
  Int_t ispi0true(Int_t imc_Pi0g1,Int_t imc_Pi0g1);
  Int_t isDstar0D0Pi0true(Int_t ,Int_t,Int_t);
  Int_t isDstar0D0Gamtrue(Int_t,Int_t);
   
  Float_t DeltaE(const TLorentzVector & P4Ups,const TLorentzVector & P4B);
  Float_t Mes(const TLorentzVector & P4Ups,const TLorentzVector & P4B); 
  Float_t Alpha(const TVector3 & P1,const TVector3 & P2,const TVector3 & Q); 
};

#endif

#ifdef btdkpi_cxx

//   btdkpi::btdkpi(TTree *tree)
//   {
//   // if parameter tree is not specified (or zero), connect the file
//   // used to generate this class and read the Tree.
//   if (tree == 0) {
//   TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("DATA_HHHK-308.root");
//   if (!f) {
//   f = new TFile("DATA_HHHK-308.root");
//   }
//   tree = (TTree*)gDirectory->Get("h2");
  
//   }
//   Init(tree);
//   }



 
btdkpi::btdkpi(TString type,TString dmode,const char* dir,const char* release)
{

  _sig_type=type;
  _super_sig_type=type; // default value
  _d0mode=dmode;
  _isData=kFALSE;
  _release=release;
  TString filename;
  
  TChain* tree(0);
 if (_release=="analysis-51") 
   tree = new TChain("ntp5"); // an-51
 else if (_release=="rel-24") 
    tree = new TChain("ntp5"); // 
  else if (_release=="analysis-32") 
    tree = new TChain("ntp6"); // rel-32
  else if (_release=="analysis-30") 
    tree = new TChain("ntp6"); // rel-30
  else if (_release=="analysis-26")
    tree = new TChain("ntp7"); // rel-26
  else
    assert(0);
  
  if (dir) {
    filename.Append(dir);
    filename.Append("/");
  } else filename="";

  cout<<"reading event of type: "<<_sig_type<<endl;

  char mystring[15];
 

  if (_release=="analysis-51") {

    TString filename_root;

    //************************************************************************************
    //*******************************  Signal  *******************************************
    //*************************************************************************************
 
    //*******************************  DK   *****************

    //*************************Kspipi

    if(_sig_type=="btdk1" && _d0mode=="kspipi"){
      _super_sig_type="btdk";
      //      if (dir==0) filename_root="./rootuples/rootSigMC/";
      if (dir==0) filename_root="./rootuples/rootSigMC/";
      filename=filename_root+"SP-4851-Run1-*.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    }else if(_sig_type=="btdk2" && _d0mode=="kspipi"){
      _super_sig_type="btdk";
      if (dir==0) filename_root="./rootuples/rootSigMC/";
      filename=filename_root+"SP-4851-Run2-*.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    }else if(_sig_type=="btdk3" && _d0mode=="kspipi"){
      _super_sig_type="btdk";
      if (dir==0) filename_root="./rootuples/rootSigMC/";
      filename=filename_root+"SP-4851-Run3-*.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    }else if(_sig_type=="btdk4" && _d0mode=="kspipi"){
      _super_sig_type="btdk";
      if (dir==0) filename_root="./rootuples/rootSigMC/";
      filename=filename_root+"SP-4851-Run4-*.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    }else if(_sig_type=="btdk5" && _d0mode=="kspipi"){
      _super_sig_type="btdk";
      if (dir==0) filename_root="./rootuples/rootSigMC/";
      filename=filename_root+"SP-4851-Run5-*.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    }else if(_sig_type=="btdk6" && _d0mode=="kspipi"){
      _super_sig_type="btdk";
      if (dir==0) filename_root="./rootuples/rootSigMC/";
      filename=filename_root+"SP-4851-Run6-*.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
  
      //*******************************  KsKK
      
    }else if(_sig_type=="btdk1" && _d0mode=="kskk"){   
      _super_sig_type="btdk";
      if (dir==0) filename_root="./rootuples/rootSigMC/";
      filename=filename_root+"SP-4852-Run1-*.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    }else if(_sig_type=="btdk2" && _d0mode=="kskk"){   
      _super_sig_type="btdk";
      if (dir==0) filename_root="./rootuples/rootSigMC/";
      filename=filename_root+"SP-4852-Run2-*.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    }else if(_sig_type=="btdk3" && _d0mode=="kskk"){   
      _super_sig_type="btdk";
      if (dir==0) filename_root="./rootuples/rootSigMC/";
      filename=filename_root+"SP-4852-Run3-*.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    }else if(_sig_type=="btdk4" && _d0mode=="kskk"){   
      _super_sig_type="btdk";
      if (dir==0) filename_root="./rootuples/rootSigMC/";
      filename=filename_root+"SP-4852-Run4-*.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    }else if(_sig_type=="btdk5" && _d0mode=="kskk"){   
      _super_sig_type="btdk";
      if (dir==0) filename_root="./rootuples/rootSigMC/";
      filename=filename_root+"SP-4852-Run5-*.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    }else if(_sig_type=="btdk6" && _d0mode=="kskk"){   
      _super_sig_type="btdk";
      if (dir==0) filename_root="./rootuples/rootSigMC/";
      filename=filename_root+"SP-4852-Run6-*.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    }
    
    //*****************************  DSTAR  K
    //**********  KSpipi
    
    else if(_sig_type=="btdsk1" && _d0mode=="kspipi"){
      _super_sig_type="btdsk";
      if (dir==0) filename_root="./rootuples/rootSigMC/";
      filename=filename_root+"SP-4855-Run1-*.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    }else if(_sig_type=="btdsk2" && _d0mode=="kspipi"){
      _super_sig_type="btdsk";
      if (dir==0) filename_root="./rootuples/rootSigMC/";
      filename=filename_root+"SP-4855-Run2-*.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    }else if(_sig_type=="btdsk3" && _d0mode=="kspipi"){
      _super_sig_type="btdsk";
      if (dir==0) filename_root="./rootuples/rootSigMC/";
      filename=filename_root+"SP-4855-Run3-*.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    }else if(_sig_type=="btdsk4" && _d0mode=="kspipi"){
      _super_sig_type="btdsk";
      if (dir==0) filename_root="./rootuples/rootSigMC/";
      filename=filename_root+"SP-4855-Run4-*.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    }else if(_sig_type=="btdsk5" && _d0mode=="kspipi"){
      _super_sig_type="btdsk";
      if (dir==0) filename_root="./rootuples/rootSigMC/";
      filename=filename_root+"SP-4855-Run5-*.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    }else if(_sig_type=="btdsk6" && _d0mode=="kspipi"){
      _super_sig_type="btdsk";
      if (dir==0) filename_root="./rootuples/rootSigMC/";
      filename=filename_root+"SP-4855-Run6-*.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
  
      //*******************************  KsKK
      
    }else if(_sig_type=="btdsk1" && _d0mode=="kskk"){   
      _super_sig_type="btdsk";
      if (dir==0) filename_root="./rootuples/rootSigMC/";
      filename=filename_root+"SP-4856-Run1-*.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    }else if(_sig_type=="btdsk2" && _d0mode=="kskk"){   
      _super_sig_type="btdsk";
      if (dir==0) filename_root="./rootuples/rootSigMC/";
      filename=filename_root+"SP-4856-Run2-*.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    }else if(_sig_type=="btdsk3" && _d0mode=="kskk"){   
      _super_sig_type="btdsk";
      if (dir==0) filename_root="./rootuples/rootSigMC/";
      filename=filename_root+"SP-4856-Run3-*.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    }else if(_sig_type=="btdsk4" && _d0mode=="kskk"){   
      _super_sig_type="btdsk";
      if (dir==0) filename_root="./rootuples/rootSigMC/";
      filename=filename_root+"SP-4856-Run4-*.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    }else if(_sig_type=="btdsk5" && _d0mode=="kskk"){   
      _super_sig_type="btdsk";
      if (dir==0) filename_root="./rootuples/rootSigMC/";
      filename=filename_root+"SP-4856-Run5-*.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    }else if(_sig_type=="btdsk6" && _d0mode=="kskk"){   
      _super_sig_type="btdsk";
      if (dir==0) filename_root="./rootuples/rootSigMC/";
      filename=filename_root+"SP-4856-Run6-*.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    }


    //************************************ D Pi

    //****************************  Kspipi

    else if(_sig_type=="btdpi1" && _d0mode=="kspipi"){
      _super_sig_type="btdpi";
      if (dir==0) filename_root="./rootuples/rootSigMC/";
      filename=filename_root+"SP-6360-Run1-*.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    }
    else if(_sig_type=="btdpi2" && _d0mode=="kspipi"){
      _super_sig_type="btdpi";
      if (dir==0) filename_root="./rootuples/rootSigMC/";
      filename=filename_root+"SP-6360-Run2-*.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    }
    else if(_sig_type=="btdpi3" && _d0mode=="kspipi"){
      _super_sig_type="btdpi";
      if (dir==0) filename_root="./rootuples/rootSigMC/";
      filename=filename_root+"SP-6360-Run3-*.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    }
    else if(_sig_type=="btdpi4" && _d0mode=="kspipi"){
      _super_sig_type="btdpi";
      if (dir==0) filename_root="./rootuples/rootSigMC/";
      filename=filename_root+"SP-6360-Run4-*.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    }
    else if (_sig_type=="btdpi5" && _d0mode=="kspipi"){
      _super_sig_type="btdpi";
      if (dir==0) filename_root="./rootuples/rootSigMC/";
      filename=filename_root+"SP-6360-Run5-*.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    } else if (_sig_type=="btdpi6" && _d0mode=="kspipi"){
      _super_sig_type="btdpi";
      if (dir==0) filename_root="./rootuples/rootSigMC/";
      filename=filename_root+"SP-6360-Run6-*.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    } 



    //*****************************  KSKK

    else if(_sig_type=="btdpi1" && _d0mode=="kskk"){
      _super_sig_type="btdpi";
      if (dir==0) filename_root="./rootuples/rootSigMC/";
      filename=filename_root+"SP-6361-Run1-*.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    }
    else if(_sig_type=="btdpi2" && _d0mode=="kskk"){
      _super_sig_type="btdpi";
      if (dir==0) filename_root="./rootuples/rootSigMC/";
      filename=filename_root+"SP-6361-Run2-*.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    }
    else if(_sig_type=="btdpi3" && _d0mode=="kskk"){
      _super_sig_type="btdpi";
      if (dir==0) filename_root="./rootuples/rootSigMC/";
      filename=filename_root+"SP-6361-Run3-*.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    }
    else if(_sig_type=="btdpi4" && _d0mode=="kskk"){
      _super_sig_type="btdpi";
      if (dir==0) filename_root="./rootuples/rootSigMC/";
      filename=filename_root+"SP-6361-Run4-*.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    }
    else if (_sig_type=="btdpi5" && _d0mode=="kskk"){
      _super_sig_type="btdpi";
      if (dir==0) filename_root="./rootuples/rootSigMC/";
      filename=filename_root+"SP-6361-Run5-*.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    }  else if (_sig_type=="btdpi6" && _d0mode=="kskk"){
      _super_sig_type="btdpi";
      if (dir==0) filename_root="./rootuples/rootSigMC/";
      filename=filename_root+"SP-6361-Run6-*.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    }


    //********************************   D* PI

    //*********************** Kspipi

    else if(_sig_type=="btdspi1" && _d0mode=="kspipi"){
      _super_sig_type="btdspi";
      if (dir==0) filename_root="./rootuples/rootSigMC/";
      filename=filename_root+"SP-6362-Run1-*.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    }
    else if(_sig_type=="btdspi2" && _d0mode=="kspipi"){
      _super_sig_type="btdspi";
      if (dir==0) filename_root="./rootuples/rootSigMC/";
      filename=filename_root+"SP-6362-Run2-*.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    }
    else if(_sig_type=="btdspi3" && _d0mode=="kspipi"){
      _super_sig_type="btdspi";
      if (dir==0) filename_root="./rootuples/rootSigMC/";
      filename=filename_root+"SP-6362-Run3-*.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    }
    else if(_sig_type=="btdspi4" && _d0mode=="kspipi"){
      _super_sig_type="btdspi";
      if (dir==0) filename_root="./rootuples/rootSigMC/";
      filename=filename_root+"SP-6362-Run4-*.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    }
    else if(_sig_type=="btdspi5" && _d0mode=="kspipi"){
      _super_sig_type="btdspi";
      if (dir==0) filename_root="./rootuples/rootSigMC/";
      filename=filename_root+"SP-6362-Run5-*.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    } else if(_sig_type=="btdspi6" && _d0mode=="kspipi"){
      _super_sig_type="btdspi";
      if (dir==0) filename_root="./rootuples/rootSigMC/";
      filename=filename_root+"SP-6362-Run6-*.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    }

    //**************************************  KsKK

    else if(_sig_type=="btdspi1" && _d0mode=="kskk"){
      _super_sig_type="btdspi";
      if (dir==0) filename_root="./rootuples/rootSigMC/";
      filename=filename_root+"SP-6363-Run1-*.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    }
    else if(_sig_type=="btdspi2" && _d0mode=="kskk"){
      _super_sig_type="btdspi";
      if (dir==0) filename_root="./rootuples/rootSigMC/";
      filename=filename_root+"SP-6363-Run2-*.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    }
    else if(_sig_type=="btdspi3" && _d0mode=="kskk"){
      _super_sig_type="btdspi";
      if (dir==0) filename_root="./rootuples/rootSigMC/";
      filename=filename_root+"SP-6363-Run3-*.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    }
    else if(_sig_type=="btdspi4" && _d0mode=="kskk"){
      _super_sig_type="btdspi";
      if (dir==0) filename_root="./rootuples/rootSigMC/";
      filename=filename_root+"SP-6363-Run4-*.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    }
    else if(_sig_type=="btdspi5" && _d0mode=="kskk"){
      _super_sig_type="btdspi";
      if (dir==0) filename_root="./rootuples/rootSigMC/";
      filename=filename_root+"SP-6363-Run5-*.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    }  else if(_sig_type=="btdspi6" && _d0mode=="kskk"){
      _super_sig_type="btdspi";
      if (dir==0) filename_root="./rootuples/rootSigMC/";
      filename=filename_root+"SP-6363-Run6-*.root";
      cout << "filename : " << filename << endl;
      tree->Add(filename);
    } 


    //************************************************************

    //******************************   Generic MC  ******************************

    //********************************************************************************


    //****************************************  998

    else if (_sig_type=="uds1"){
      _super_sig_type="uds";
      if (dir==0) filename_root="./rootuples/root998/";
      filename=filename_root+"SP-998-BchToD0KAll-Run1-R24a1-v0*.root";
      tree->Add(filename);
      cout << "filename : " << filename << endl;
    }
    else if (_sig_type=="uds2"){
      _super_sig_type="uds";
      if (dir==0) filename_root="./rootuples/root998/";
      filename=filename_root+"SP-998-BchToD0KAll-Run2-R24a1-v0*.root";
      tree->Add(filename);
      cout << "filename : " << filename << endl;
    }
    else if (_sig_type=="uds3"){
      _super_sig_type="uds";
      if (dir==0) filename_root="./rootuples/root998/";
      filename=filename_root+"SP-998-BchToD0KAll-Run3-R24a1-v0*.root";
      tree->Add(filename);
      cout << "filename : " << filename << endl;
    }
    else if (_sig_type=="uds4_v02"){
      _super_sig_type="uds";
      if (dir==0) filename_root="./rootuples/root998/";
      filename=filename_root+"SP-998-BchToD0KAll-Run4-R24a1-v02-*.root";
      tree->Add(filename);
      cout << "filename : " << filename << endl;
    }
    else if (_sig_type=="uds4_v03"){
      _super_sig_type="uds";
      if (dir==0) filename_root="./rootuples/root998/";
      filename=filename_root+"SP-998-BchToD0KAll-Run4-R24a1-v03-*.root";
      tree->Add(filename);
      cout << "filename : " << filename << endl;
    }
    else if (_sig_type=="uds5_v02"){
      _super_sig_type="uds";
      if (dir==0) filename_root="./rootuples/root998/";
      filename=filename_root+"SP-998-BchToD0KAll-Run5-R24a1-v02-*.root";
      tree->Add(filename);
      cout << "filename : " << filename << endl;
    } 
    else if (_sig_type=="uds5_v03"){
      _super_sig_type="uds";
      if (dir==0) filename_root="./rootuples/root998/";
      filename=filename_root+"SP-998-BchToD0KAll-Run5-R24a1-v03-*.root";
      tree->Add(filename);
      cout << "filename : " << filename << endl;
    } 
    else if (_sig_type=="uds6"){
      _super_sig_type="uds";
      if (dir==0) filename_root="./rootuples/root998/";
      filename=filename_root+"SP-998-BchToD0KAll-Run6-R24a1-v0*.root";
      tree->Add(filename);
      cout << "filename : " << filename << endl;
    }
 

   //*************************************  1005


    else if (_sig_type=="ccbar1"){
      _super_sig_type="ccbar";
     if (dir==0) filename_root="./rootuples/root1005/";
     filename=filename_root+"SP-1005-BchToD0KAll-Run1-R24a1-v02-*.root";
     tree->Add(filename);
     cout << "filename : " << filename << endl;
    }
    else if (_sig_type=="ccbar2"){
      _super_sig_type="ccbar";
      if (dir==0) filename_root="./rootuples/root1005/";
      filename=filename_root+"SP-1005-BchToD0KAll-Run2-R24a1-v02-*.root";
      tree->Add(filename);
      cout << "filename : " << filename << endl;
    }
    else if (_sig_type=="ccbar3"){
      _super_sig_type="ccbar";
      if (dir==0) filename_root="./rootuples/root1005/";
      filename=filename_root+"SP-1005-BchToD0KAll-Run3-R24a1-v02-*.root";
      tree->Add(filename);
      cout << "filename : " << filename << endl;
    }
    else if (_sig_type=="ccbar4_1"){
      _super_sig_type="ccbar";
     if (dir==0) filename_root="./rootuples/root1005/";
      filename=filename_root+"SP-1005-BchToD0KAll-Run4-R24a1-v02-1*.root";
      tree->Add(filename);
      cout << "filename : " << filename << endl;
            
    }else if(_sig_type== "ccbar4_29"){
      _super_sig_type="ccbar";
      if (dir==0) filename_root="./rootuples/root1005/";
      for(Int_t i=2; i<10;i++){
	sprintf(mystring,"%i",i);
	filename=filename_root+"SP-1005-BchToD0KAll-Run4-R24a1-v02-"+mystring+"*.root";
	tree->Add(filename);
	cout << "filename : " << filename << endl;}
    }
    else if (_sig_type=="ccbar5_1"){
      _super_sig_type="ccbar";
      if (dir==0) filename_root="./rootuples/root1005/";
      filename=filename_root+"SP-1005-BchToD0KAll-Run5-R24a1-v02-1*.root";
      tree->Add(filename);
      cout << "filename : " << filename << endl;
    }
    else if (_sig_type=="ccbar5_29"){
      _super_sig_type="ccbar";
      if (dir==0) filename_root="./rootuples/root1005/";
      for(Int_t i=2; i<10;i++){
	sprintf(mystring,"%i",i);
	filename=filename_root+"SP-1005-BchToD0KAll-Run5-R24a1-v02-"+mystring+"*.root";
	tree->Add(filename);
	cout << "filename : " << filename << endl;}
      
    }else if (_sig_type=="ccbar6"){
      _super_sig_type="ccbar";
      if (dir==0) filename_root="./rootuples/root1005/";
      filename=filename_root+"SP-1005-BchToD0KAll-Run6-R24a1-v02-*.root";
      tree->Add(filename);
      cout << "filename : " << filename << endl;
    }


    //********************************************************  1235

    else if (_sig_type=="chb1"){
      _super_sig_type="chb";
      if (dir==0)filename_root="./rootuples/root1235/";
      filename=filename_root+"SP-1235-BchToD0KAll-Run1-*.root";
      tree->Add(filename);
      cout << "filename : " << filename << endl;      
    }
    else if (_sig_type=="chb2"){
      _super_sig_type="chb";
      if (dir==0)filename_root="./rootuples/root1235/";
      filename=filename_root+"SP-1235-BchToD0KAll-Run2-*.root";
      tree->Add(filename);
      cout << "filename : " << filename << endl;      
    } 
    else if (_sig_type=="chb3"){
      _super_sig_type="chb";
      if (dir==0)filename_root="./rootuples/root1235/";
      filename=filename_root+"SP-1235-BchToD0KAll-Run3-*.root";
      tree->Add(filename);
      cout << "filename : " << filename << endl;      
    } 
    else if (_sig_type=="chb4"){
      _super_sig_type="chb";
      if (dir==0)filename_root="./rootuples/root1235/";
      filename=filename_root+"SP-1235-BchToD0KAll-Run4-*.root";
      tree->Add(filename);
      cout << "filename : " << filename << endl;      
    } 
    else if (_sig_type=="chb5"){
      _super_sig_type="chb";
      if (dir==0)filename_root="./rootuples/root1235/";
      filename=filename_root+"SP-1235-BchToD0KAll-Run5-*.root";
      tree->Add(filename);
      cout << "filename : " << filename << endl;      
    } else if (_sig_type=="chb6"){
      _super_sig_type="chb";
      if (dir==0)filename_root="./rootuples/root1235/";
      filename=filename_root+"SP-1235-BchToD0KAll-Run6-*.root";
      tree->Add(filename);
      cout << "filename : " << filename << endl;      
    }

    //************** 1235 **** chbk chbpi


    else if(_sig_type=="chbk1"){
      _super_sig_type="chbk";
       if (dir==0)filename_root="./rootuples/root1235/";
      filename=filename_root+"SP-1235-BchToD0KAll-Run1-*.root";
      tree->Add(filename);
      cout << "filename : " << filename << endl;      
    }
    else if(_sig_type=="chbpi1"){
      _super_sig_type="chbpi";
      if (dir==0)filename+="./rootuples/root1235/";
      filename+="SP-1235-BchToD0KAll-Run1-*.root";
      tree->Add(filename);
      cout << "filename : " << filename << endl;      
    }
    else if (_sig_type=="chbk1234" || _sig_type=="chbpi1234"){
      _super_sig_type=(_sig_type=="chbk1234")? "chbk" : "chbpi";
    
      if (dir==0)filename_root="./rootuples/root1235/";
      filename=filename_root+"SP-1235-BchToD0KAll-Run1-*.root";
      tree->Add(filename);
      cout << "filename : " << filename << endl;
      
      if (dir==0)filename_root="./rootuples/root1235/";
      filename=filename_root+"SP-1235-BchToD0KAll-Run2-*.root";
      tree->Add(filename);
      
      if (dir==0)filename_root="./rootuples/root1235/";
      filename=filename_root+"SP-1235-BchToD0KAll-Run3-*.root";
      tree->Add(filename);
      
      if (dir==0)filename_root="./rootuples/root1235/";
      filename=filename_root+"SP-1235-BchToD0KAll-Run4-*.root";
      tree->Add(filename);
      cout << "filename : " << filename << endl;
    } 
    else if (_sig_type=="chbk56" || _sig_type=="chbpi56"){
      _super_sig_type=(_sig_type=="chbk56")? "chbk" : "chbpi";
     
      if (dir==0)filename_root="./rootuples/root1235/";
      filename=filename_root+"SP-1235-BchToD0KAll-Run5-*.root";
      cout << "filename : " << filename << endl; 
    
      if (dir==0)filename_root="./rootuples/root1235/";
      filename=filename_root+"SP-1235-BchToD0KAll-Run6-*.root";
      tree->Add(filename);
      cout << "filename : " << filename << endl;
    }    

    //******************************************************************  1237


    else if (_sig_type=="b0b0bar1"){
      _super_sig_type="b0b0bar";
      if (dir==0)filename_root="./rootuples/root1237/";
      filename=filename_root+"SP-1237-BchToD0KAll-Run1-*.root";
      tree->Add(filename);
      cout << "filename : " << filename << endl;
    }
    else if (_sig_type=="b0b0bar2"){
      _super_sig_type="b0b0bar";
      if (dir==0)filename_root="./rootuples/root1237/";
      filename=filename_root+"SP-1237-BchToD0KAll-Run2-*.root";
      tree->Add(filename);
      cout << "filename : " << filename << endl;
    } 
    else if (_sig_type=="b0b0bar3"){
      _super_sig_type="b0b0bar";
      if (dir==0)filename_root="./rootuples/root1237/";
      filename=filename_root+"SP-1237-BchToD0KAll-Run3-*.root";
      tree->Add(filename);
      cout << "filename : " << filename << endl;
    } 
    else if (_sig_type=="b0b0bar4"){
      _super_sig_type="b0b0bar";
      if (dir==0)filename_root="./rootuples/root1237/";
      filename=filename_root+"SP-1237-BchToD0KAll-Run4-*.root";
      tree->Add(filename);
      cout << "filename : " << filename << endl;
    } 
    else if (_sig_type=="b0b0bar5"){
      _super_sig_type="b0b0bar";
      if (dir==0)filename_root="./rootuples/root1237/";
      filename=filename_root+"SP-1237-BchToD0KAll-Run5-*.root";
      tree->Add(filename);
      cout << "filename : " << filename << endl;
       }
    else if(_sig_type=="b0b0bar6"){
      _super_sig_type="b0b0bar";
      if (dir==0)filename_root="./rootuples/root1237/";
      filename=filename_root+"SP-1237-BchToD0KAll-Run6-*.root";
      tree->Add(filename);
      cout << "filename : " << filename << endl;
    }
    
    //*********************************************************************************************
    
    //******************************* On data  *******************************
    
    //*********************************************************************************************
    
    
    else if (_sig_type=="on1"){
      _super_sig_type="on";
      _isData=kTRUE;
      if (dir==0) filename_root="./rootuples/rootOn1/";
      filename=filename_root+"BchToD0KAll-Run1-OnPeak-R24a1-v03-*.root";
      cout << "filename : " << filename << endl;
      //      if (dir==0) filename+="./validation-rel24/DK/DATA/BchToD0KAll/";
      //filename+="BchToD0KAll-Run1-OnPeak-60ifbR24a1-*.root";
      tree->Add(filename);
    }
    else if (_sig_type=="on2"){
      _super_sig_type="on";
      _isData=kTRUE; 
      if (dir==0) filename_root="./rootuples/rootOn2/";
      filename=filename_root+"BchToD0KAll-Run2-OnPeak-R24a1-v03-*.root";
      //      if (dir==0) filename+="./validation-rel24/DK/DATA/BchToD0KAll/";
      //filename+="BchToD0KAll-Run2-OnPeak-60ifbR24a1-*.root";
      tree->Add(filename);
    } 
    else if (_sig_type=="on3"){
      _super_sig_type="on";
      _isData=kTRUE;
      if (dir==0) filename_root="./rootuples/rootOn3/";
      filename=filename_root+"BchToD0KAll-Run3-OnPeak-R24a1-v03-*.root";
      //      if (dir==0) filename+="./validation-rel24/DK/DATA/BchToD0KAll/";
      //filename+="BchToD0KAll-Run3-OnPeak-60ifbR24a1-*.root";
      tree->Add(filename);
    } 
    else if (_sig_type=="on4"){
      _super_sig_type="on";
      _isData=kTRUE;
      if (dir==0) filename_root="./rootuples/rootOn4/";
      filename=filename_root+"BchToD0KAll-Run4-OnPeak-R24a1-v03-*.root";
      //   if (dir==0) filename+="./validation-rel24/DK/DATA/BchToD0KAll/";
      //filename+="BchToD0KAll-Run4-OnPeak-60ifbR24a1-*.root";
      tree->Add(filename);
    }
    else if (_sig_type=="on5"){
      _super_sig_type="on";
      _isData=kTRUE;
      if (dir==0) filename_root="./rootuples/rootOn5/";
      filename=filename_root+"BchToD0KAll-Run5-OnPeak-R24a1-v03-*.root";
      //      if (dir==0) filename+="./validation-rel24/DK/DATA/BchToD0KAll/";
      //filename+="BchToD0KAll-Run5-OnPeak-60ifbR24a1-*.root";
      tree->Add(filename);
    }    
    else if (_sig_type=="on6"){
      _super_sig_type="on";
      _isData=kTRUE;
      if (dir==0) filename_root="./rootuples/rootOn6/";
      filename=filename_root+"BchToD0KAll-Run6-OnPeak-R24a1-v03-*.root";
      //      if (dir==0) filename+="./validation-rel24/DK/DATA/BchToD0KAll/";
      //filename+="BchToD0KAll-Run6-OnPeak-60ifbR24a1-*.root";
      tree->Add(filename);

      //////////////////////////////////////////////////////  OFF
    } else if (_sig_type=="off1"){
      _super_sig_type="off";
      _isData=kTRUE;
      if (dir==0) filename_root="./rootuples/rootOff1/";
      filename=filename_root+"BchToD0KAll-Run1-OffPeak-R24a1-v03-*.root";
      cout << "filename : " << filename << endl;
      //      if (dir==0) filename+="./validation-rel24/DK/DATA/BchToD0KAll/";
      //filename+="BchToD0KAll-Run1-OffPeak-60ifbR24a1-*.root";
      tree->Add(filename);
    }
    else if (_sig_type=="off2"){
      _super_sig_type="off";
      _isData=kTRUE; 
      if (dir==0) filename_root="./rootuples/rootOff2/";
      filename=filename_root+"BchToD0KAll-Run2-OffPeak-R24a1-v03-*.root";
      //      if (dir==0) filename+="./validation-rel24/DK/DATA/BchToD0KAll/";
      //filename+="BchToD0KAll-Run2-OffPeak-60ifbR24a1-*.root";
      tree->Add(filename);
    } 
    else if (_sig_type=="off3"){
      _super_sig_type="off";
      _isData=kTRUE;
      if (dir==0) filename_root="./rootuples/rootOff3/";
      filename=filename_root+"BchToD0KAll-Run3-OffPeak-R24a1-v03-*.root";
      //      if (dir==0) filename+="./validation-rel24/DK/DATA/BchToD0KAll/";
      //filename+="BchToD0KAll-Run3-OffPeak-60ifbR24a1-*.root";
      tree->Add(filename);
    } 
    else if (_sig_type=="off4"){
      _super_sig_type="off";
      _isData=kTRUE;
      if (dir==0) filename_root="./rootuples/rootOff4/";
      filename=filename_root+"BchToD0KAll-Run4-OffPeak-R24a1-v03-*.root";
      //   if (dir==0) filename+="./validation-rel24/DK/DATA/BchToD0KAll/";
      //filename+="BchToD0KAll-Run4-OffPeak-60ifbR24a1-*.root";
      tree->Add(filename);
    }
    else if (_sig_type=="off5"){
      _super_sig_type="off";
      _isData=kTRUE;
      if (dir==0) filename_root="./rootuples/rootOff5/";
      filename=filename_root+"BchToD0KAll-Run5-OffPeak-R24a1-v03-*.root";
      //      if (dir==0) filename+="./validation-rel24/DK/DATA/BchToD0KAll/";
      //filename+="BchToD0KAll-Run5-OffPeak-60ifbR24a1-*.root";
      tree->Add(filename);
    }    
    else if (_sig_type=="off6"){
      _super_sig_type="off";
      _isData=kTRUE;
      if (dir==0) filename_root="./rootuples/rootOff6/";
      filename=filename_root+"BchToD0KAll-Run6-OffPeak-R24a1-v03-*.root";
      //      if (dir==0) filename+="./validation-rel24/DK/DATA/BchToD0KAll/";
      //filename+="BchToD0KAll-Run6-OffPeak-60ifbR24a1-*.root";
      tree->Add(filename);
    }else {
      cout << _sig_type << " for " << _d0mode << " not defined. Abort. " << endl;
      assert(0);
    }
    
  }  
  cout<<"loading root file " << filename << endl;
  cout<<"done"<<endl;
  
  Init(tree);
}

btdkpi::~btdkpi()
{
  if (!fChain) return;
  delete fChain->GetCurrentFile();
}

Int_t btdkpi::GetEntry(Int_t entry)
{
  // Read contents of entry.
  if (!fChain) return 0;
  return fChain->GetEntry(entry);
}

Int_t btdkpi::LoadTree(Int_t entry)
{
  // Set the environment to read one entry
  if (!fChain) return -5;
  Int_t centry = fChain->LoadTree(entry);
  if (centry < 0) return centry;
  if (fChain->IsA() != TChain::Class()) return centry;
  TChain *chain = (TChain*)fChain;
  if (chain->GetTreeNumber() != fCurrent) {
    fCurrent = chain->GetTreeNumber();
    Notify();
  }
  return centry;
}

void btdkpi::Init(TTree *tree)
{
  //   Set branch addresses
  if (tree == 0) return;
  fChain    = tree;
  fCurrent = -1;
  fChain->SetMakeClass(1);

  fChain->SetBranchAddress("event",&event);
  fChain->SetBranchAddress("runNumber",&runNumber);
  fChain->SetBranchAddress("platform",&platform);
  fChain->SetBranchAddress("partition",&partition);
  fChain->SetBranchAddress("upperID",&upperID);
  fChain->SetBranchAddress("lowerID",&lowerID);
  //  fChain->SetBranchAddress("primVtxX",&primVtxX);
  //  fChain->SetBranchAddress("primVtxY",&primVtxY);
  //  fChain->SetBranchAddress("primVtxZ",&primVtxZ);
  //  fChain->SetBranchAddress("primVtxCovXX",&primVtxCovXX);
  //  fChain->SetBranchAddress("primVtxCovYY",&primVtxCovYY);
  //  fChain->SetBranchAddress("primVtxCovZZ",&primVtxCovZZ);
  //  fChain->SetBranchAddress("primVtxCovXY",&primVtxCovXY);
  //  fChain->SetBranchAddress("primVtxCovYZ",&primVtxCovYZ);
  //  fChain->SetBranchAddress("primVtxCovXZ",&primVtxCovXZ);
  //  fChain->SetBranchAddress("primVtxChi2",&primVtxChi2);
  //  fChain->SetBranchAddress("primVtxNdof",&primVtxNdof);
  //  fChain->SetBranchAddress("BCountFilter",&BCountFilter);
  //  fChain->SetBranchAddress("DchTrig",&DchTrig);
  //  fChain->SetBranchAddress("EmcTrig",&EmcTrig);
  //  fChain->SetBranchAddress("R2All",&R2All);
  //  fChain->SetBranchAddress("nGTLFid",&nGTLFid);
  //  fChain->SetBranchAddress("nChgFid",&nChgFid);
  //  fChain->SetBranchAddress("eTotFid",&eTotFid);
  //  fChain->SetBranchAddress("PrimVtxdr",&PrimVtxdr);
  //  fChain->SetBranchAddress("PrimVtxdz",&PrimVtxdz);
  //  fChain->SetBranchAddress("VtxProb",&VtxProb);
  //  fChain->SetBranchAddress("beamSX",&beamSX);
  //  fChain->SetBranchAddress("beamSY",&beamSY);
  //  fChain->SetBranchAddress("beamSZ",&beamSZ);
  //  fChain->SetBranchAddress("beamSCovXX",&beamSCovXX);
  //  fChain->SetBranchAddress("beamSCovYY",&beamSCovYY);
  //  fChain->SetBranchAddress("beamSCovZZ",&beamSCovZZ);
  //  fChain->SetBranchAddress("beamSCovXZ",&beamSCovXZ);
  fChain->SetBranchAddress("pxUps",&pxUps);
  fChain->SetBranchAddress("pyUps",&pyUps);
  fChain->SetBranchAddress("pzUps",&pzUps);
  fChain->SetBranchAddress("eUps",&eUps);
  fChain->SetBranchAddress("nTrkTot",&nTrkTot);
  fChain->SetBranchAddress("W2",&W2);
  fChain->SetBranchAddress("FoxWol2",&FoxWol2);
  fChain->SetBranchAddress("FoxWol2Neu",&FoxWol2Neu);
  fChain->SetBranchAddress("thrust",&thrust);
  fChain->SetBranchAddress("thrustNeu",&thrustNeu);
  //Mc
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
  //ChB
  fChain->SetBranchAddress("nChB",&nChB);
  fChain->SetBranchAddress("massChB",massChB);
  fChain->SetBranchAddress("pChB",pChB);
  fChain->SetBranchAddress("thChB",thChB);
  fChain->SetBranchAddress("phiChB",phiChB);
  fChain->SetBranchAddress("errMassChB",errMassChB);
  fChain->SetBranchAddress("m0ChB",m0ChB);
  fChain->SetBranchAddress("xChB",xChB);
  fChain->SetBranchAddress("yChB",yChB);
  fChain->SetBranchAddress("zChB",zChB);
  fChain->SetBranchAddress("s2xChB",s2xChB);
  fChain->SetBranchAddress("s2yChB",s2yChB);
  fChain->SetBranchAddress("s2zChB",s2zChB);
  fChain->SetBranchAddress("chi2ChB",chi2ChB);
  fChain->SetBranchAddress("dofChB",dofChB);
  fChain->SetBranchAddress("stChB",stChB);
  fChain->SetBranchAddress("ndauChB",ndauChB);
  if(!_isData)
    fChain->SetBranchAddress("MCChB",MCChB);
  fChain->SetBranchAddress("mseChB",mseChB);
  fChain->SetBranchAddress("mHatChB",mHatChB);
  fChain->SetBranchAddress("deltaeChB",deltaeChB);
  fChain->SetBranchAddress("ThruChB",ThruChB);
  fChain->SetBranchAddress("thThruChB",thThruChB);
  fChain->SetBranchAddress("phiThruChB",phiThruChB);
  fChain->SetBranchAddress("cosTBChB",cosTBChB);
  fChain->SetBranchAddress("d1ChBIndex",d1ChBIndex);
  fChain->SetBranchAddress("d1ChBLund",d1ChBLund);
  fChain->SetBranchAddress("d2ChBIndex",d2ChBIndex);
  fChain->SetBranchAddress("d2ChBLund",d2ChBLund);
  fChain->SetBranchAddress("SphericityChB",SphericityChB);
  fChain->SetBranchAddress("CosTsphChB",CosTsphChB);
  fChain->SetBranchAddress("LegendreP0ChB",LegendreP0ChB);
  fChain->SetBranchAddress("LegendreP2ChB",LegendreP2ChB);
  fChain->SetBranchAddress("FisherChB",FisherChB);
  fChain->SetBranchAddress("AustralChChB",AustralChChB);
  fChain->SetBranchAddress("BorealChChB",BorealChChB);
  fChain->SetBranchAddress("maxEnergyChB",maxEnergyChB);
  fChain->SetBranchAddress("thetaMaxChB",thetaMaxChB);
  fChain->SetBranchAddress("chargeMaxChB",chargeMaxChB);
   //  fChain->SetBranchAddress("vtxChi2ChB",vtxChi2ChB);
   //  fChain->SetBranchAddress("vtxNdofChB",vtxNdofChB);
   //  fChain->SetBranchAddress("vtxDeltaZChB",vtxDeltaZChB);
   //  fChain->SetBranchAddress("vtxSigmaZ2ChB",vtxSigmaZ2ChB);
   //  fChain->SetBranchAddress("probChi2ChB",probChi2ChB);
   //  fChain->SetBranchAddress("BtgBTaggerTagChB",BtgBTaggerTagChB);
   //  fChain->SetBranchAddress("BtgBTaggerCatChB",BtgBTaggerCatChB);
  //Dstar0
  fChain->SetBranchAddress("nDstar0",&nDstar0);
  fChain->SetBranchAddress("massDstar0",massDstar0);
  fChain->SetBranchAddress("pDstar0",pDstar0);
  fChain->SetBranchAddress("thDstar0",thDstar0);
  fChain->SetBranchAddress("phiDstar0",phiDstar0);
  fChain->SetBranchAddress("errMassDstar0",errMassDstar0);
  fChain->SetBranchAddress("m0Dstar0",m0Dstar0);
  fChain->SetBranchAddress("xDstar0",xDstar0);
  fChain->SetBranchAddress("yDstar0",yDstar0);
  fChain->SetBranchAddress("zDstar0",zDstar0);
  fChain->SetBranchAddress("s2xDstar0",s2xDstar0);
  fChain->SetBranchAddress("s2yDstar0",s2yDstar0);
  fChain->SetBranchAddress("s2zDstar0",s2zDstar0);
  fChain->SetBranchAddress("chi2Dstar0",chi2Dstar0);
  fChain->SetBranchAddress("dofDstar0",dofDstar0);
  fChain->SetBranchAddress("stDstar0",stDstar0);
  fChain->SetBranchAddress("ndauDstar0",ndauDstar0);
  if(!_isData)
    fChain->SetBranchAddress("MCDstar0",MCDstar0);
  fChain->SetBranchAddress("d1Dstar0Index",d1Dstar0Index);
  fChain->SetBranchAddress("d1Dstar0Lund",d1Dstar0Lund);
  fChain->SetBranchAddress("d2Dstar0Index",d2Dstar0Index);
  fChain->SetBranchAddress("d2Dstar0Lund",d2Dstar0Lund);
  //D0
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
  //Ks
  fChain->SetBranchAddress("nKs",&nKs);
  fChain->SetBranchAddress("decayLengthCovD0",decayLengthCovD0);
  fChain->SetBranchAddress("decayLengthD0",decayLengthD0);
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
  //Pi0
  fChain->SetBranchAddress("nPi0",&nPi0);
  fChain->SetBranchAddress("massPi0",massPi0);
  fChain->SetBranchAddress("pPi0",pPi0);
  fChain->SetBranchAddress("thPi0",thPi0);
  fChain->SetBranchAddress("phiPi0",phiPi0);
  fChain->SetBranchAddress("errMassPi0",errMassPi0);
  fChain->SetBranchAddress("m0Pi0",m0Pi0);
  fChain->SetBranchAddress("xPi0",xPi0);
  fChain->SetBranchAddress("yPi0",yPi0);
  fChain->SetBranchAddress("zPi0",zPi0);
  fChain->SetBranchAddress("s2xPi0",s2xPi0);
  fChain->SetBranchAddress("s2yPi0",s2yPi0);
  fChain->SetBranchAddress("s2zPi0",s2zPi0);
  fChain->SetBranchAddress("chi2Pi0",chi2Pi0);
  fChain->SetBranchAddress("dofPi0",dofPi0);
  fChain->SetBranchAddress("stPi0",stPi0);
  fChain->SetBranchAddress("ndauPi0",ndauPi0);
  if(!_isData)
    fChain->SetBranchAddress("MCPi0",MCPi0);
  fChain->SetBranchAddress("d1Pi0Index",d1Pi0Index);
  fChain->SetBranchAddress("d1Pi0Lund",d1Pi0Lund);
  fChain->SetBranchAddress("d2Pi0Index",d2Pi0Index);
  fChain->SetBranchAddress("d2Pi0Lund",d2Pi0Lund);
  //Trk
  fChain->SetBranchAddress("nTrk",&nTrk);
  // fChain->SetBranchAddress("IfrLayTrk",IfrLayTrk);
  // fChain->SetBranchAddress("IfrNsTrk",IfrNsTrk);
  // fChain->SetBranchAddress("IfrInnerTrk",IfrInnerTrk);
  // fChain->SetBranchAddress("IfrBarrelTrk",IfrBarrelTrk);
  // fChain->SetBranchAddress("IfrFWDTrk",IfrFWDTrk);
  // fChain->SetBranchAddress("IfrBWDTrk",IfrBWDTrk);
  // fChain->SetBranchAddress("IfrMeasIntLenTrk",IfrMeasIntLenTrk);
  // fChain->SetBranchAddress("IfrFirstHitTrk",IfrFirstHitTrk);
  // fChain->SetBranchAddress("IfrLastHitTrk",IfrLastHitTrk);
  fChain->SetBranchAddress("cTheTrk",cTheTrk);
  fChain->SetBranchAddress("sTheTrk",sTheTrk);
  fChain->SetBranchAddress("nPhotTrk",nPhotTrk);
  fChain->SetBranchAddress("nexPhot0Trk",nexPhot0Trk);
  fChain->SetBranchAddress("nexPhot1Trk",nexPhot1Trk);
  fChain->SetBranchAddress("nexPhot2Trk",nexPhot2Trk);
  fChain->SetBranchAddress("nexPhot3Trk",nexPhot3Trk);
  fChain->SetBranchAddress("nexPhot4Trk",nexPhot4Trk);
  fChain->SetBranchAddress("deltadrcmomTrk",deltadrcmomTrk);
  fChain->SetBranchAddress("lMomTrk",lMomTrk);
  fChain->SetBranchAddress("ZMom42Trk",ZMom42Trk);
  fChain->SetBranchAddress("ecalTrk",ecalTrk);
  fChain->SetBranchAddress("ecalXTrk",ecalXTrk);
  fChain->SetBranchAddress("ecalYTrk",ecalYTrk);
  fChain->SetBranchAddress("ecalZTrk",ecalZTrk);
  fChain->SetBranchAddress("nCryTrk",nCryTrk);
  fChain->SetBranchAddress("nBumpTrk",nBumpTrk);
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
  //Gam
  fChain->SetBranchAddress("nGam",&nGam);
  fChain->SetBranchAddress("lMomGam",lMomGam);
  fChain->SetBranchAddress("ZMom42Gam",ZMom42Gam);
  fChain->SetBranchAddress("ecalGam",ecalGam);
  fChain->SetBranchAddress("ecalXGam",ecalXGam);
  fChain->SetBranchAddress("ecalYGam",ecalYGam);
  fChain->SetBranchAddress("ecalZGam",ecalZGam);
  fChain->SetBranchAddress("nCryGam",nCryGam);
  fChain->SetBranchAddress("nBumpGam",nBumpGam);
  fChain->SetBranchAddress("thetaGam",thetaGam);
  fChain->SetBranchAddress("phiGam",phiGam);
  fChain->SetBranchAddress("energyGam",energyGam);
  if(!_isData){
    fChain->SetBranchAddress("idGam",idGam);
    fChain->SetBranchAddress("IndexGam",IndexGam);
    fChain->SetBranchAddress("IndexNtGam",IndexNtGam);
  }
  fChain->SetBranchAddress("vetoloGam",vetoloGam);
  fChain->SetBranchAddress("vetohiGam",vetohiGam);
  fChain->SetBranchAddress("vetoeloGam",vetoeloGam);
  fChain->SetBranchAddress("vetoehiGam",vetoehiGam);
  fChain->SetBranchAddress("minCaloAngleGam",minCaloAngleGam);
  fChain->SetBranchAddress("minCaloDistGam",minCaloDistGam);

  Notify();
}

Bool_t btdkpi::Notify()
{
  // Called when loading a new file.
  // Get branch pointers.

  b_event = fChain->GetBranch("event");
  b_runNumber = fChain->GetBranch("runNumber");
  b_platform = fChain->GetBranch("platform");
  b_partition = fChain->GetBranch("partition");
  b_upperID = fChain->GetBranch("upperID");
  b_lowerID = fChain->GetBranch("lowerID");
  //  b_primVtxX = fChain->GetBranch("primVtxX");
  //  b_primVtxY = fChain->GetBranch("primVtxY");
  //  b_primVtxZ = fChain->GetBranch("primVtxZ");
  //  b_primVtxCovXX = fChain->GetBranch("primVtxCovXX");
  //  b_primVtxCovYY = fChain->GetBranch("primVtxCovYY");
  //  b_primVtxCovZZ = fChain->GetBranch("primVtxCovZZ");
  //  b_primVtxCovXY = fChain->GetBranch("primVtxCovXY");
  //  b_primVtxCovYZ = fChain->GetBranch("primVtxCovYZ");
  //  b_primVtxCovXZ = fChain->GetBranch("primVtxCovXZ");
  //  b_primVtxChi2 = fChain->GetBranch("primVtxChi2");
  //  b_primVtxNdof = fChain->GetBranch("primVtxNdof");
  //  b_BCountFilter = fChain->GetBranch("BCountFilter");
  //  b_DchTrig = fChain->GetBranch("DchTrig");
  //  b_EmcTrig = fChain->GetBranch("EmcTrig");
  //  b_R2All = fChain->GetBranch("R2All");
  //  b_nGTLFid = fChain->GetBranch("nGTLFid");
  //  b_nChgFid = fChain->GetBranch("nChgFid");
  //  b_eTotFid = fChain->GetBranch("eTotFid");
  //  b_PrimVtxdr = fChain->GetBranch("PrimVtxdr");
  //  b_PrimVtxdz = fChain->GetBranch("PrimVtxdz");
  //  b_VtxProb = fChain->GetBranch("VtxProb");
  //  b_beamSX = fChain->GetBranch("beamSX");
  //  b_beamSY = fChain->GetBranch("beamSY");
  //  b_beamSZ = fChain->GetBranch("beamSZ");
  //  b_beamSCovXX = fChain->GetBranch("beamSCovXX");
  //  b_beamSCovYY = fChain->GetBranch("beamSCovYY");
  //  b_beamSCovZZ = fChain->GetBranch("beamSCovZZ");
  //  b_beamSCovXZ = fChain->GetBranch("beamSCovXZ");
  b_pxUps = fChain->GetBranch("pxUps");
  b_pyUps = fChain->GetBranch("pyUps");
  b_pzUps = fChain->GetBranch("pzUps");
  b_eUps = fChain->GetBranch("eUps");
  b_nTrkTot = fChain->GetBranch("nTrkTot");
  b_W2 = fChain->GetBranch("W2");
  b_FoxWol2 = fChain->GetBranch("FoxWol2");
  b_FoxWol2Neu = fChain->GetBranch("FoxWol2Neu");
  b_thrust = fChain->GetBranch("thrust");
  b_thrustNeu = fChain->GetBranch("thrustNeu");
  //Mc
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
  //ChB
  b_nChB = fChain->GetBranch("nChB");
  b_massChB = fChain->GetBranch("massChB");
  b_pChB = fChain->GetBranch("pChB");
  b_thChB = fChain->GetBranch("thChB");
  b_phiChB = fChain->GetBranch("phiChB");
  b_errMassChB = fChain->GetBranch("errMassChB");
  b_m0ChB = fChain->GetBranch("m0ChB");
  b_xChB = fChain->GetBranch("xChB");
  b_yChB = fChain->GetBranch("yChB");
  b_zChB = fChain->GetBranch("zChB");
  b_s2xChB = fChain->GetBranch("s2xChB");
  b_s2yChB = fChain->GetBranch("s2yChB");
  b_s2zChB = fChain->GetBranch("s2zChB");
  b_chi2ChB = fChain->GetBranch("chi2ChB");
  b_dofChB = fChain->GetBranch("dofChB");
  b_stChB = fChain->GetBranch("stChB");
  b_ndauChB = fChain->GetBranch("ndauChB");
  if (!_isData)
    b_MCChB = fChain->GetBranch("MCChB");
  b_mseChB = fChain->GetBranch("mseChB");
  b_mHatChB = fChain->GetBranch("mHatChB");
  b_deltaeChB = fChain->GetBranch("deltaeChB");
  b_ThruChB = fChain->GetBranch("ThruChB");
  b_thThruChB = fChain->GetBranch("thThruChB");
  b_phiThruChB = fChain->GetBranch("phiThruChB");
  b_cosTBChB = fChain->GetBranch("cosTBChB");
  b_d1ChBIndex = fChain->GetBranch("d1ChBIndex");
  b_d1ChBLund = fChain->GetBranch("d1ChBLund");
  b_d2ChBIndex = fChain->GetBranch("d2ChBIndex");
  b_d2ChBLund = fChain->GetBranch("d2ChBLund");
  b_SphericityChB = fChain->GetBranch("SphericityChB");
  b_CosTsphChB = fChain->GetBranch("CosTsphChB");
  b_LegendreP0ChB = fChain->GetBranch("LegendreP0ChB");
  b_LegendreP2ChB = fChain->GetBranch("LegendreP2ChB");
  b_FisherChB = fChain->GetBranch("FisherChB");
  b_AustralChChB = fChain->GetBranch("AustralChChB");
  b_BorealChChB = fChain->GetBranch("BorealChChB");
  b_maxEnergyChB = fChain->GetBranch("maxEnergyChB");
  b_thetaMaxChB = fChain->GetBranch("thetaMaxChB");
  b_chargeMaxChB = fChain->GetBranch("chargeMaxChB");
  // b_vtxChi2ChB = fChain->GetBranch("vtxChi2ChB");
  // b_vtxNdofChB = fChain->GetBranch("vtxNdofChB");
  // b_vtxDeltaZChB = fChain->GetBranch("vtxDeltaZChB");
  // b_vtxSigmaZ2ChB = fChain->GetBranch("vtxSigmaZ2ChB");
  // b_probChi2ChB = fChain->GetBranch("probChi2ChB");
  // b_BtgBTaggerTagChB = fChain->GetBranch("BtgBTaggerTagChB");
  // b_BtgBTaggerCatChB = fChain->GetBranch("BtgBTaggerCatChB");
  //Dstar0
  b_nDstar0 = fChain->GetBranch("nDstar0");
  b_massDstar0 = fChain->GetBranch("massDstar0");
  b_pDstar0 = fChain->GetBranch("pDstar0");
  b_thDstar0 = fChain->GetBranch("thDstar0");
  b_phiDstar0 = fChain->GetBranch("phiDstar0");
  b_errMassDstar0 = fChain->GetBranch("errMassDstar0");
  b_m0Dstar0 = fChain->GetBranch("m0Dstar0");
  b_xDstar0 = fChain->GetBranch("xDstar0");
  b_yDstar0 = fChain->GetBranch("yDstar0");
  b_zDstar0 = fChain->GetBranch("zDstar0");
  b_s2xDstar0 = fChain->GetBranch("s2xDstar0");
  b_s2yDstar0 = fChain->GetBranch("s2yDstar0");
  b_s2zDstar0 = fChain->GetBranch("s2zDstar0");
  b_chi2Dstar0 = fChain->GetBranch("chi2Dstar0");
  b_dofDstar0 = fChain->GetBranch("dofDstar0");
  b_stDstar0 = fChain->GetBranch("stDstar0");
  b_ndauDstar0 = fChain->GetBranch("ndauDstar0");
  if (!_isData)
    b_MCDstar0 = fChain->GetBranch("MCDstar0");
  b_d1Dstar0Index = fChain->GetBranch("d1Dstar0Index");
  b_d1Dstar0Lund = fChain->GetBranch("d1Dstar0Lund");
  b_d2Dstar0Index = fChain->GetBranch("d2Dstar0Index");
  b_d2Dstar0Lund = fChain->GetBranch("d2Dstar0Lund");
  //D0
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
  if (!_isData)
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
  //Ks
  b_nKs = fChain->GetBranch("nKs");
  b_decayLengthCovD0 = fChain->GetBranch("decayLengthCovD0");
  b_decayLengthD0 = fChain->GetBranch("decayLengthD0");
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
  if (!_isData)
    b_MCKs = fChain->GetBranch("MCKs");
  b_d1KsIndex = fChain->GetBranch("d1KsIndex");
  b_d1KsLund = fChain->GetBranch("d1KsLund");
  b_d2KsIndex = fChain->GetBranch("d2KsIndex");
  b_d2KsLund = fChain->GetBranch("d2KsLund");
  //Pi0
  b_nPi0 = fChain->GetBranch("nPi0");
  b_massPi0 = fChain->GetBranch("massPi0");
  b_pPi0 = fChain->GetBranch("pPi0");
  b_thPi0 = fChain->GetBranch("thPi0");
  b_phiPi0 = fChain->GetBranch("phiPi0");
  b_errMassPi0 = fChain->GetBranch("errMassPi0");
  b_m0Pi0 = fChain->GetBranch("m0Pi0");
  b_xPi0 = fChain->GetBranch("xPi0");
  b_yPi0 = fChain->GetBranch("yPi0");
  b_zPi0 = fChain->GetBranch("zPi0");
  b_s2xPi0 = fChain->GetBranch("s2xPi0");
  b_s2yPi0 = fChain->GetBranch("s2yPi0");
  b_s2zPi0 = fChain->GetBranch("s2zPi0");
  b_chi2Pi0 = fChain->GetBranch("chi2Pi0");
  b_dofPi0 = fChain->GetBranch("dofPi0");
  b_stPi0 = fChain->GetBranch("stPi0");
  b_ndauPi0 = fChain->GetBranch("ndauPi0");
  if (!_isData)
    b_MCPi0 = fChain->GetBranch("MCPi0");
  b_d1Pi0Index = fChain->GetBranch("d1Pi0Index");
  b_d1Pi0Lund = fChain->GetBranch("d1Pi0Lund");
  b_d2Pi0Index = fChain->GetBranch("d2Pi0Index");
  b_d2Pi0Lund = fChain->GetBranch("d2Pi0Lund");
  //Trk
  b_nTrk = fChain->GetBranch("nTrk");
  // b_IfrLayTrk = fChain->GetBranch("IfrLayTrk");
  // b_IfrNsTrk = fChain->GetBranch("IfrNsTrk");
  // b_IfrInnerTrk = fChain->GetBranch("IfrInnerTrk");
  // b_IfrBarrelTrk = fChain->GetBranch("IfrBarrelTrk");
  // b_IfrFWDTrk = fChain->GetBranch("IfrFWDTrk");
  // b_IfrBWDTrk = fChain->GetBranch("IfrBWDTrk");
  // b_IfrMeasIntLenTrk = fChain->GetBranch("IfrMeasIntLenTrk");
  // b_IfrFirstHitTrk = fChain->GetBranch("IfrFirstHitTrk");
  // b_IfrLastHitTrk = fChain->GetBranch("IfrLastHitTrk");
  b_cTheTrk = fChain->GetBranch("cTheTrk");
  b_sTheTrk = fChain->GetBranch("sTheTrk");
  b_nPhotTrk = fChain->GetBranch("nPhotTrk");
  b_nexPhot0Trk = fChain->GetBranch("nexPhot0Trk");
  b_nexPhot1Trk = fChain->GetBranch("nexPhot1Trk");
  b_nexPhot2Trk = fChain->GetBranch("nexPhot2Trk");
  b_nexPhot3Trk = fChain->GetBranch("nexPhot3Trk");
  b_nexPhot4Trk = fChain->GetBranch("nexPhot4Trk");
  b_deltadrcmomTrk = fChain->GetBranch("deltadrcmomTrk");
  b_lMomTrk = fChain->GetBranch("lMomTrk");
  b_ZMom42Trk = fChain->GetBranch("ZMom42Trk");
  b_ecalTrk = fChain->GetBranch("ecalTrk");
  b_ecalXTrk = fChain->GetBranch("ecalXTrk");
  b_ecalYTrk = fChain->GetBranch("ecalYTrk");
  b_ecalZTrk = fChain->GetBranch("ecalZTrk");
  b_nCryTrk = fChain->GetBranch("nCryTrk");
  b_nBumpTrk = fChain->GetBranch("nBumpTrk");
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
  //Gam
  b_nGam = fChain->GetBranch("nGam");
  b_lMomGam = fChain->GetBranch("lMomGam");
  b_ZMom42Gam = fChain->GetBranch("ZMom42Gam");
  b_ecalGam = fChain->GetBranch("ecalGam");
  b_ecalXGam = fChain->GetBranch("ecalXGam");
  b_ecalYGam = fChain->GetBranch("ecalYGam");
  b_ecalZGam = fChain->GetBranch("ecalZGam");
  b_nCryGam = fChain->GetBranch("nCryGam");
  b_nBumpGam = fChain->GetBranch("nBumpGam");
  b_thetaGam = fChain->GetBranch("thetaGam");
  b_phiGam = fChain->GetBranch("phiGam");
  b_energyGam = fChain->GetBranch("energyGam");
  if(!_isData){
    b_idGam = fChain->GetBranch("idGam");
    b_IndexGam = fChain->GetBranch("IndexGam");
    b_IndexNtGam = fChain->GetBranch("IndexNtGam");
  }
  b_vetoloGam = fChain->GetBranch("vetoloGam");
  b_vetohiGam = fChain->GetBranch("vetohiGam");
  b_vetoeloGam = fChain->GetBranch("vetoeloGam");
  b_vetoehiGam = fChain->GetBranch("vetoehiGam");
  b_minCaloAngleGam = fChain->GetBranch("minCaloAngleGam");
  b_minCaloDistGam = fChain->GetBranch("minCaloDistGam");
   
  return kTRUE;
}

void btdkpi::Show(Int_t entry)
{
  // Print contents of entry.
  // If entry is not specified, print current entry
  if (!fChain) return;
  fChain->Show(entry);
}
Int_t btdkpi::Cut(Int_t entry)
{
  // This function may be called from Loop.
  // returns  1 if entry is accepted.
  // returns -1 otherwise.
  return 1;
}
#endif // #ifdef btdkpi_cxx

