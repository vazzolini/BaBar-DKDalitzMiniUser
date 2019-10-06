#ifndef btdkstarc_h
#define btdkstarc_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

//addition
#include <iostream.h>    
#include <TStopwatch.h>  
#include "TLorentzVector.h"  


class btdkstarc {
  TString        _sig_type; //addition
  TString        _super_sig_type; //addition
  TString        _d0mode;   //addition
  Bool_t         _isData;   //addition
  TString        _release;  //addition
  Bool_t         _isCS;     //addition isCS = is control sample



 public:
  TTree          *fChain;   //!pointer to the analyzed TTree or TChain
  Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leave types
   Int_t           event;
   Int_t           runNumber;
   Int_t           platform;
   Int_t           partition;
   Int_t           upperID;
   Int_t           lowerID;

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
   // Mc
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
   // ChB
   Int_t           nChB;
   Float_t         massChB[300];   //[nChB]
   Float_t         pChB[300];   //[nChB]
   Float_t         thChB[300];   //[nChB]
   Float_t         phiChB[300];   //[nChB]
   Float_t         errMassChB[300];   //[nChB]
   Float_t         m0ChB[300];   //[nChB]
   Float_t         xChB[300];   //[nChB]
   Float_t         yChB[300];   //[nChB]
   Float_t         zChB[300];   //[nChB]
   Float_t         s2xChB[300];   //[nChB]
   Float_t         s2yChB[300];   //[nChB]
   Float_t         s2zChB[300];   //[nChB]
   Float_t         chi2ChB[300];   //[nChB]
   Int_t           dofChB[300];   //[nChB]
   Int_t           stChB[300];   //[nChB]
   Int_t           ndauChB[300];   //[nChB]
   Int_t           MCChB[300];   //[nChB]
   Float_t         mseChB[300];   //[nChB]
   Float_t         mHatChB[300];   //[nChB]
   Float_t         deltaeChB[300];   //[nChB]
   Float_t         ThruChB[300];   //[nChB]
   Float_t         thThruChB[300];   //[nChB]
   Float_t         phiThruChB[300];   //[nChB]
   Float_t         cosTBChB[300];   //[nChB]
   Int_t           d1ChBIndex[300];   //[nChB]
   Int_t           d1ChBLund[300];   //[nChB]
   Int_t           d2ChBIndex[300];   //[nChB]
   Int_t           d2ChBLund[300];   //[nChB]
   Float_t         CosTsphChB[300];   //[nChB]
   Float_t         SphericityChB[300];   //[nChB]
   Float_t         LegendreP0ChB[300];   //[nChB]
   Float_t         LegendreP2ChB[300];   //[nChB]
   Float_t         FisherChB[300];   //[nChB]
   Float_t         AustralChChB[300];   //[nChB]
   Float_t         BorealChChB[300];   //[nChB]
   Float_t         maxEnergyChB[300];   //[nChB]
   Float_t         thetaMaxChB[300];   //[nChB]
   Float_t         chargeMaxChB[300];   //[nChB]
  
   //D0
   Int_t           nD0;
   Float_t         massD0[300];   //[nD0]
   Float_t         pD0[300];   //[nD0]
   Float_t         thD0[300];   //[nD0]
   Float_t         phiD0[300];   //[nD0]
   Float_t         errMassD0[300];   //[nD0]
   Float_t         m0D0[300];   //[nD0]
   Float_t         xD0[300];   //[nD0]
   Float_t         yD0[300];   //[nD0]
   Float_t         zD0[300];   //[nD0]
   Float_t         s2xD0[300];   //[nD0]
   Float_t         s2yD0[300];   //[nD0]
   Float_t         s2zD0[300];   //[nD0]
   Float_t         chi2D0[300];   //[nD0]
   Int_t           dofD0[300];   //[nD0]
   Int_t           stD0[300];   //[nD0]
   Int_t           ndauD0[300];   //[nD0]
   Int_t           MCD0[300];   //[nD0]
   Int_t           d1D0Index[300];   //[nD0]
   Int_t           d1D0Lund[300];   //[nD0]
   Int_t           d2D0Index[300];   //[nD0]
   Int_t           d2D0Lund[300];   //[nD0]
   Int_t           d3D0Index[300];   //[nD0]
   Int_t           d3D0Lund[300];   //[nD0]
   Int_t           d4D0Index[300];   //[nD0]
   Int_t           d4D0Lund[300];   //[nD0]
   Float_t         m2pDalitzD0[300];   //[nD0]
   Float_t         m2mDalitzD0[300];   //[nD0]
   Float_t         m2zDalitzD0[300];   //[nD0]
   Int_t           stDalitzD0[300];
   Float_t         mTotDalitzD0[300];
   Float_t         chi2DalitzD0[300];
   Int_t           dofDalitzD0[300];
   //K*
   Int_t           nKstarc;
   Float_t         massKstarc[300];   //[nKstarc]
   Float_t         pKstarc[300];   //[nKstarc]
   Float_t         thKstarc[300];   //[nKstarc]
   Float_t         phiKstarc[300];   //[nKstarc]
   Float_t         errMassKstarc[300];   //[nKstarc]
   Float_t         m0Kstarc[300];   //[nKstarc]
   Float_t         xKstarc[300];   //[nKstarc]
   Float_t         yKstarc[300];   //[nKstarc]
   Float_t         zKstarc[300];   //[nKstarc]
   Float_t         s2xKstarc[300];   //[nKstarc]
   Float_t         s2yKstarc[300];   //[nKstarc]
   Float_t         s2zKstarc[300];   //[nKstarc]
   Float_t         chi2Kstarc[300];   //[nKstarc]
   Int_t           dofKstarc[300];   //[nKstarc]
   Int_t           stKstarc[300];   //[nKstarc]
   Int_t           ndauKstarc[300];   //[nKstarc]
   Int_t           MCKstarc[300];   //[nKstarc]
   Int_t           d1KstarcIndex[300];   //[nKstarc]
   Int_t           d1KstarcLund[300];   //[nKstarc]
   Int_t           d2KstarcIndex[300];   //[nKstarc]
   Int_t           d2KstarcLund[300];   //[nKstarc]
   //Ks   
   Int_t           nKs;
   Float_t         massKs[300];   //[nKs]
   Float_t         pKs[300];   //[nKs]
   Float_t         thKs[300];   //[nKs]
   Float_t         phiKs[300];   //[nKs]
   Float_t         errMassKs[300];   //[nKs]
   Float_t         m0Ks[300];   //[nKs]
   Float_t         xKs[300];   //[nKs]
   Float_t         yKs[300];   //[nKs]
   Float_t         zKs[300];   //[nKs]
   Float_t         s2xKs[300];   //[nKs]
   Float_t         s2yKs[300];   //[nKs]
   Float_t         s2zKs[300];   //[nKs]
   Float_t         chi2Ks[300];   //[nKs]
   Int_t           dofKs[300];   //[nKs]
   Int_t           stKs[300];   //[nKs]
   Int_t           ndauKs[300];   //[nKs]
   Int_t           MCKs[300];   //[nKs]
   Int_t           d1KsIndex[300];   //[nKs]
   Int_t           d1KsLund[300];   //[nKs]
   Int_t           d2KsIndex[300];   //[nKs]
   Int_t           d2KsLund[300];   //[nKs]
   //Pi0   
   Int_t           nPi0;
   Float_t         massPi0[300];   //[nPi0]
   Float_t         pPi0[300];   //[nPi0]
   Float_t         thPi0[300];   //[nPi0]
   Float_t         phiPi0[300];   //[nPi0]
   Float_t         errMassPi0[300];   //[nPi0]
   Float_t         m0Pi0[300];   //[nPi0]
   Float_t         xPi0[300];   //[nPi0]
   Float_t         yPi0[300];   //[nPi0]
   Float_t         zPi0[300];   //[nPi0]
   Float_t         s2xPi0[300];   //[nPi0]
   Float_t         s2yPi0[300];   //[nPi0]
   Float_t         s2zPi0[300];   //[nPi0]
   Float_t         chi2Pi0[300];   //[nPi0]
   Int_t           dofPi0[300];   //[nPi0]
   Int_t           stPi0[300];   //[nPi0]
   Int_t           ndauPi0[300];   //[nPi0]
   Int_t           MCPi0[300];   //[nPi0]
   Int_t           d1Pi0Index[300];   //[nPi0]
   Int_t           d1Pi0Lund[300];   //[nPi0]
   Int_t           d2Pi0Index[300];   //[nPi0]
   Int_t           d2Pi0Lund[300];   //[nPi0]
   //Trk   
   Int_t           nTrk;

   Float_t         cTheTrk[300];   //[nTrk]
   Float_t         sTheTrk[300];   //[nTrk]
   Int_t           nPhotTrk[300];   //[nTrk]
   Int_t           nexPhot0Trk[300];   //[nTrk]
   Int_t           nexPhot1Trk[300];   //[nTrk]
   Int_t           nexPhot2Trk[300];   //[nTrk]
   Int_t           nexPhot3Trk[300];   //[nTrk]
   Int_t           nexPhot4Trk[300];   //[nTrk]
   Int_t           nbgPhotTrk[300];   //[nTrk]
   Int_t           drcInBarTrk[300];   //[nTrk]
   Int_t           drcExitBarTrk[300];   //[nTrk]
   Float_t         drcXposTrk[300];   //[nTrk]
   Float_t         deltadrcmomTrk[300];   //[nTrk]
   Float_t         lMomTrk[300];   //[nTrk]
   Float_t         ZMom42Trk[300];   //[nTrk]
   Float_t         ecalTrk[300];   //[nTrk]
   Float_t         ecalXTrk[300];   //[nTrk]
   Float_t         ecalYTrk[300];   //[nTrk]
   Float_t         ecalZTrk[300];   //[nTrk]
   Int_t           nCryTrk[300];   //[nTrk]
   Int_t           nBumpTrk[300];   //[nTrk]
   Int_t           isvtTrk[300];   //[nTrk]
   Int_t           nsvtTrk[300];   //[nTrk]
   Int_t           fhitTrk[300];   //[nTrk]
   Int_t           ndchTrk[300];   //[nTrk]
   Int_t           lhitTrk[300];   //[nTrk]
   Float_t         tLenTrk[300];   //[nTrk]
   Float_t         teffTrk[300];   //[nTrk]
   Int_t           chargeTrk[300];   //[nTrk]
   Float_t         momentumTrk[300];   //[nTrk]
   Float_t         thetaTrk[300];   //[nTrk]
   Float_t         phiTrk[300];   //[nTrk]
   Int_t           muonIdTrk[300];   //[nTrk]
   Int_t           elecIdTrk[300];   //[nTrk]
   Int_t           kaonIdTrk[300];   //[nTrk]
   Int_t           pionIdTrk[300];   //[nTrk]
   Int_t           protonIdTrk[300];   //[nTrk]
   Int_t           idTrk[300];   //[nTrk]
   Int_t           IndexTrk[300];   //[nTrk]
   Int_t           IndexNtTrk[300];   //[nTrk]
   Int_t           effCorTrk[300];   //[nTrk]    
   Int_t           sEffCorTrk[300];   //[nTrk]
   //Gam
   Int_t           nGam;
   Float_t         lMomGam[300];   //[nGam]
   Float_t         ZMom42Gam[300];   //[nGam]
   Float_t         ecalGam[300];   //[nGam]
   Float_t         ecalXGam[300];   //[nGam]
   Float_t         ecalYGam[300];   //[nGam]
   Float_t         ecalZGam[300];   //[nGam]
   Int_t           nCryGam[300];   //[nGam]
   Int_t           nBumpGam[300];   //[nGam]
   Float_t         thetaGam[300];   //[nGam]
   Float_t         phiGam[300];   //[nGam]
   Float_t         energyGam[300];   //[nGam]
   Int_t           idGam[300];   //[nGam]
   Int_t           IndexGam[300];   //[nGam]
   Int_t           IndexNtGam[300];   //[nGam]
   Float_t         vetoloGam[300];   //[nGam]
   Float_t         vetohiGam[300];   //[nGam]
   Float_t         vetoeloGam[300];   //[nGam]
   Float_t         vetoehiGam[300];   //[nGam]
   Float_t         minCaloAngleGam[300];   //[nGam]
   Float_t         minCaloDistGam[300];   //[nGam]


   // we add the B- -> D0 a1- variables
 
   Float_t         mMissChB[300];   //[nChB]
   Float_t         mMissErrChB[300];   //[nChB]
   
   Int_t           nA1c;
   Float_t         massA1c[300];   //[nA1c]
   Float_t         pA1c[300];   //[nA1c]
   Float_t         thA1c[300];   //[nA1c]
   Float_t         phiA1c[300];   //[nA1c]
   Float_t         errMassA1c[300];   //[nA1c]
   Float_t         m0A1c[300];   //[nA1c]
   Float_t         xA1c[300];   //[nA1c]
   Float_t         yA1c[300];   //[nA1c]
   Float_t         zA1c[300];   //[nA1c]
   Float_t         s2xA1c[300];   //[nA1c]
   Float_t         s2yA1c[300];   //[nA1c]
   Float_t         s2zA1c[300];   //[nA1c]
   Float_t         chi2A1c[300];   //[nA1c]
   Int_t           dofA1c[300];   //[nA1c]
   Int_t           stA1c[300];   //[nA1c]
   Int_t           ndauA1c[300];   //[nA1c]
   Int_t           MCA1c[300];   //[nA1c]
   Int_t           d1A1cIndex[300];   //[nA1c]
   Int_t           d1A1cLund[300];   //[nA1c]
   Int_t           d2A1cIndex[300];   //[nA1c]
   Int_t           d2A1cLund[300];   //[nA1c]

   Int_t           nRho0;
   Float_t         massRho0[300];   //[nRho0]
   Float_t         pRho0[300];   //[nRho0]
   Float_t         thRho0[300];   //[nRho0]
   Float_t         phiRho0[300];   //[nRho0]
   Float_t         errMassRho0[300];   //[nRho0]
   Float_t         m0Rho0[300];   //[nRho0]
   Float_t         xRho0[300];   //[nRho0]
   Float_t         yRho0[300];   //[nRho0]
   Float_t         zRho0[300];   //[nRho0]
   Float_t         s2xRho0[300];   //[nRho0]
   Float_t         s2yRho0[300];   //[nRho0]
   Float_t         s2zRho0[300];   //[nRho0]
   Float_t         chi2Rho0[300];   //[nRho0]
   Int_t           dofRho0[300];   //[nRho0]
   Int_t           stRho0[300];   //[nRho0]
   Int_t           ndauRho0[300];   //[nRho0]
   Int_t           MCRho0[300];   //[nRho0]
   Int_t           d1Rho0Index[300];   //[nRho0]
   Int_t           d1Rho0Lund[300];   //[nRho0]
   Int_t           d2Rho0Index[300];   //[nRho0]
   Int_t           d2Rho0Lund[300];   //[nRho0]




   // List of branches
   TBranch        *b_event;   //!
   TBranch        *b_runNumber;   //!
   TBranch        *b_platform;   //!
   TBranch        *b_partition;   //!
   TBranch        *b_upperID;   //!
   TBranch        *b_lowerID;   //!

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
   //Mc
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
   TBranch        *b_CosTsphChB;   //!
   TBranch        *b_SphericityChB;   //!
   TBranch        *b_LegendreP0ChB;   //!
   TBranch        *b_LegendreP2ChB;   //!
   TBranch        *b_FisherChB;   //!
   TBranch        *b_AustralChChB;   //!
   TBranch        *b_BorealChChB;   //!
   TBranch        *b_maxEnergyChB;   //!
   TBranch        *b_thetaMaxChB;   //!
   TBranch        *b_chargeMaxChB;   //!

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
   //K*
   TBranch        *b_nKstarc;   //!
   TBranch        *b_massKstarc;   //!
   TBranch        *b_pKstarc;   //!
   TBranch        *b_thKstarc;   //!
   TBranch        *b_phiKstarc;   //!
   TBranch        *b_errMassKstarc;   //!
   TBranch        *b_m0Kstarc;   //!
   TBranch        *b_xKstarc;   //!
   TBranch        *b_yKstarc;   //!
   TBranch        *b_zKstarc;   //!
   TBranch        *b_s2xKstarc;   //!
   TBranch        *b_s2yKstarc;   //!
   TBranch        *b_s2zKstarc;   //!
   TBranch        *b_chi2Kstarc;   //!
   TBranch        *b_dofKstarc;   //!
   TBranch        *b_stKstarc;   //!
   TBranch        *b_ndauKstarc;   //!
   TBranch        *b_MCKstarc;   //!
   TBranch        *b_d1KstarcIndex;   //!
   TBranch        *b_d1KstarcLund;   //!
   TBranch        *b_d2KstarcIndex;   //!
   TBranch        *b_d2KstarcLund;   //!
   //Ks
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
   //Pi0
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
 
   TBranch        *b_cTheTrk;   //!
   TBranch        *b_sTheTrk;   //!
   TBranch        *b_nPhotTrk;   //!
   TBranch        *b_nexPhot0Trk;   //!
   TBranch        *b_nexPhot1Trk;   //!
   TBranch        *b_nexPhot2Trk;   //!
   TBranch        *b_nexPhot3Trk;   //!
   TBranch        *b_nexPhot4Trk;   //!
   TBranch        *b_nbgPhotTrk;   //!
   TBranch        *b_drcInBarTrk;   //!
   TBranch        *b_drcExitBarTrk;   //!
   TBranch        *b_drcXposTrk;   //!
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
   //Gam
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


   // we add the B- -> D0 a1- braches


   TBranch        *b_mMissChB;   //!
   TBranch        *b_mMissErrChB;   //!
 
   TBranch        *b_nA1c;   //!
   TBranch        *b_massA1c;   //!
   TBranch        *b_pA1c;   //!
   TBranch        *b_thA1c;   //!
   TBranch        *b_phiA1c;   //!
   TBranch        *b_errMassA1c;   //!
   TBranch        *b_m0A1c;   //!
   TBranch        *b_xA1c;   //!
   TBranch        *b_yA1c;   //!
   TBranch        *b_zA1c;   //!
   TBranch        *b_s2xA1c;   //!
   TBranch        *b_s2yA1c;   //!
   TBranch        *b_s2zA1c;   //!
   TBranch        *b_chi2A1c;   //!
   TBranch        *b_dofA1c;   //!
   TBranch        *b_stA1c;   //!
   TBranch        *b_ndauA1c;   //!
   TBranch        *b_MCA1c;   //!
   TBranch        *b_d1A1cIndex;   //!
   TBranch        *b_d1A1cLund;   //!
   TBranch        *b_d2A1cIndex;   //!
   TBranch        *b_d2A1cLund;   //!

   TBranch        *b_nRho0;   //!
   TBranch        *b_massRho0;   //!
   TBranch        *b_pRho0;   //!
   TBranch        *b_thRho0;   //!
   TBranch        *b_phiRho0;   //!
   TBranch        *b_errMassRho0;   //!
   TBranch        *b_m0Rho0;   //!
   TBranch        *b_xRho0;   //!
   TBranch        *b_yRho0;   //!
   TBranch        *b_zRho0;   //!
   TBranch        *b_s2xRho0;   //!
   TBranch        *b_s2yRho0;   //!
   TBranch        *b_s2zRho0;   //!
   TBranch        *b_chi2Rho0;   //!
   TBranch        *b_dofRho0;   //!
   TBranch        *b_stRho0;   //!
   TBranch        *b_ndauRho0;   //!
   TBranch        *b_MCRho0;   //!
   TBranch        *b_d1Rho0Index;   //!
   TBranch        *b_d1Rho0Lund;   //!
   TBranch        *b_d2Rho0Index;   //!
   TBranch        *b_d2Rho0Lund;   //!



  //btdkstarc(TTree *tree=0);
  btdkstarc(TString type,TString dmode="kspipi",const char* dir=0, const char* release="analysis-30", Bool_t isCS = kFALSE); 
  ~btdkstarc();

  Bool_t isBtoDVectorc(Int_t lundD0Trk,Int_t i,Bool_t isCS);     
  Int_t  isSignalEvt(Int_t lundD0Trk,Int_t idKstar,Int_t i_ChB);  
  Int_t  isSignalEvtControlSample(Int_t lundD0Trk,Int_t idVector,Int_t i_ChB);  
  Int_t  isNRSignalEvt(Int_t lundD0Trk,Int_t i_ChB);  
  Int_t  isNRSignalEvtControlSample(Int_t lundD0Trk,Int_t i_ChB);  
  Int_t  Cut(Int_t entry);
  Int_t  GetEntry(Int_t entry);
  Int_t  LoadTree(Int_t entry);
  Int_t  isD0true(Int_t lundD0Trk,Int_t iMc_D0Pi1,Int_t iMc_D0Pi2,Int_t iMc_KsPi1,Int_t iMc_KsPi2);
  Int_t  isKstarcKspictrue(Int_t iMc_Kstarcpic,Int_t iMc_KstarcKsPi1,Int_t iMc_KstarcKsPi2,Int_t idKstar=323);
  Int_t  isVectorcResopictrue(Int_t iMc_Vectorcpic,Int_t iMc_VectorcResoPi1,Int_t iMc_VectorcResoPi2,Int_t idVectorc=20213);
  Int_t  isKstarcKcPi0true(Int_t iMc_Kstarckc,Int_t iMc_KstarcPi0g1,Int_t iMc_KstarcPi0g1,Int_t idKstar=323);
  Int_t  isKstrue(Int_t iMc_KsPi1,Int_t iMc_KsPi2);
  Int_t  isResotrue(Int_t iMc_ResoPi1,Int_t iMc_ResoPi2);
  Int_t  isPi0true(Int_t iMc_KstarcPi0g1,Int_t iMc_KstarcPi0g1);
  Float_t CosHely(const TLorentzVector & P,const TLorentzVector & Q, const TLorentzVector & D);
  Float_t DeltaE(const TLorentzVector & P4Ups,const TLorentzVector & P4B);
  Float_t Mes(const TLorentzVector & P4Ups,const TLorentzVector & P4B); 
  Float_t Alpha(const TVector3 & P1,const TVector3 & P2,const TVector3 & Q); 
  void   giveMeDau(Int_t index,Int_t* dauarray); 
  void   giveMeDau(Int_t* motharray, Int_t id, Int_t* dauarray);
  void   printInfo(Int_t* array); 
  void   Init(TTree *tree);
  void   Loop(Int_t nentries=0);
  Bool_t Notify();
  void   Show(Int_t entry = -1);
};

#endif

#ifdef btdkstarc_cxx


btdkstarc::btdkstarc(TString type,TString dmode,const char* dir,const char* release,Bool_t isCS)
{
  TChain* tree=new TChain("ntp6");
  _sig_type    =type;
  _super_sig_type    =type; // default value
  _d0mode      =dmode;
  _isData = kFALSE;
  _isCS = isCS;
  _release=release;
  
  TString filename;
  TString filename1;

  if (dir) {
    filename.Append(dir);
    filename.Append("/");
  } else filename="";

  cout<<"reading event of type: "<<_sig_type<<endl;

  assert(_d0mode=="kspipi");
     
  if (_release=="analysis-26") {

    //////////////////////////////////////////////////////////
    //......  release-26

  } else if (_release=="analysis-30") {
    
    //////////////////////////////////////////////////////////
    //......  release-30
    
    // Signal

    if (_sig_type=="btdkstarc1234"){
      _super_sig_type="btdkstarc";
      if (dir==0) filename+="./prod-32-skim18c/DK/MC/Signal/";    
      filename1=filename+"SP-6364-Run1-*.root";    
      cout<<"loading root file " << filename << endl;
      tree->Add(filename1);
      filename1=filename+"SP-6364-Run2-*.root";    
      cout<<"loading root file " << filename << endl;
      tree->Add(filename1);
      filename1=filename+"SP-6364-Run3-*.root";    
      cout<<"loading root file " << filename << endl;
      tree->Add(filename1);
      filename1=filename+"SP-6364-Run4-*.root";    
      cout<<"loading root file " << filename << endl;
      tree->Add(filename1);
    }    
    else if(_sig_type=="btdkstarc"){
      filename+="./prod-32-skim18c/DK/MC/Signal/";
      filename+="SP-6364-BchToD0KstarAll-R18c-*.root";
      cout<<"loading root file " << filename << endl;
      tree->Add(filename);
    }
    else if (_sig_type=="btdkstarc1"){
      _super_sig_type="btdkstarc";
      if (dir==0) filename+="./prod-32-skim18c/DK/MC/Signal/";
      filename+="SP-6364-Run1-*.root";
      cout<<"loading root file " << filename << endl;
      tree->Add(filename);

    }
    else if (_sig_type=="btdkstarc2"){
      _super_sig_type="btdkstarc";
      if (dir==0) filename+="./prod-32-skim18c/DK/MC/Signal/";
      filename+="SP-6364-Run2-*.root";
      cout<<"loading root file " << filename << endl;
      tree->Add(filename);

    }
    else if (_sig_type=="btdkstarc3"){
      _super_sig_type="btdkstarc";
      if (dir==0) filename+="./prod-32-skim18c/DK/MC/Signal/";    
      filename+="SP-6364-Run3-*.root";    
      cout<<"loading root file " << filename << endl;
      tree->Add(filename);
      
    }
    else if (_sig_type=="btdkstarc4"){
      _super_sig_type="btdkstarc";
      if (dir==0) filename+="./prod-32-skim18c/DK/MC/Signal/";
      filename+="SP-6364-Run4-*.root";
      cout<<"loading root file " << filename << endl;
      tree->Add(filename);

    }
    else if (_sig_type=="btdkstarc5"){
      _super_sig_type="btdkstarc";
      if (dir==0) filename+="./prod-32-skim18c/DK/MC/Signal/";
      filename+="SP-6364-Run5-*.root";
      cout<<"loading root file " << filename << endl;
      tree->Add(filename);

    }

    else if (_sig_type=="btda1"){
      _isCS = kTRUE;
      if (dir==0) filename+="./prod-32-skim18c/DK/MC/Signal/";  
      filename+="SP-6340-BRecoToDDstar-R18b-*.root";        
      cout<<"loading root file " << filename << endl;
      tree->Add(filename);
    }

    // Signal (R and NR) from generic MC
    else if (_sig_type=="chbR1" || _sig_type=="chbNR1"){
      _super_sig_type=(_sig_type=="chbR1")? "chbR" : "chbNR";
      if (dir==0) filename+="./prod-32-skim18c/DK/MC/B+B-/";
      filename+=(_isCS==kFALSE)? "BchToD0KstarAll/SP-1235-BchToD0KstarAll-Run1-*.root" : "BRecoToDDstar/SP-1235-BRecoToDDstar-Run1-*.root";
      cout<<"loading root file " << filename << endl;
      tree->Add(filename);
    } 
    else if (_sig_type=="chbR2" || _sig_type=="chbNR2"){
      _super_sig_type=(_sig_type=="chbR2")? "chbR" : "chbNR";
      if (dir==0) filename+="./prod-32-skim18c/DK/MC/B+B-/";
      filename+=(_isCS==kFALSE)? "BchToD0KstarAll/SP-1235-BchToD0KstarAll-Run2-*.root" : "BRecoToDDstar/SP-1235-BRecoToDDstar-Run2-*.root";
      cout<<"loading root file " << filename << endl;
      tree->Add(filename);
    } 
    else if (_sig_type=="chbR3" || _sig_type=="chbNR3"){
      _super_sig_type=(_sig_type=="chbR3")? "chbR" : "chbNR";
      if (dir==0) filename+="./prod-32-skim18c/DK/MC/B+B-/";
      filename+=(_isCS==kFALSE)? "BchToD0KstarAll/SP-1235-BchToD0KstarAll-Run3-*.root" : "BRecoToDDstar/SP-1235-BRecoToDDstar-Run3-*.root";      
      cout<<"loading root file " << filename << endl;
      tree->Add(filename);
    } 
    else if (_sig_type=="chbR4" || _sig_type=="chbNR4"){
      _super_sig_type=(_sig_type=="chbR4")? "chbR" : "chbNR";
      if (dir==0) filename+="./prod-32-skim18c/DK/MC/B+B-/";
      filename+=(_isCS==kFALSE)? "BchToD0KstarAll/SP-1235-BchToD0KstarAll-Run4-*.root" : "BRecoToDDstar/SP-1235-BRecoToDDstar-Run4-*.root";      
      cout<<"loading root file " << filename << endl;
      tree->Add(filename);
    } 
    else if (_sig_type=="chbR5" || _sig_type=="chbNR5"){
      _super_sig_type=(_sig_type=="chbR5")? "chbR" : "chbNR";
      if (dir==0) filename+="./prod-32-skim18c/DK/MC/B+B-/";
      filename+=(_isCS==kFALSE)? "BchToD0KstarAll/SP-1235-BchToD0KstarAll-Run5-*.root" : "BRecoToDDstar/SP-1235-BRecoToDDstar-Run5-*.root";
      cout<<"loading root file " << filename << endl;
      tree->Add(filename);
    }

    // Generic MC
    else if (_sig_type=="b0b0bar1"){
      _super_sig_type="b0b0bar";
      if (dir==0) filename+="./prod-32-skim18c/DK/MC/B0B0bar/";
      filename+=(_isCS==kFALSE)? "BchToD0KstarAll/SP-1237-BchToD0KstarAll-Run1-*.root" : "BRecoToDDstar/SP-1237-BRecoToDDstar-Run1-*.root";
      cout<<"loading root file " << filename << endl;
      tree->Add(filename);
    }
    else if (_sig_type=="b0b0bar2"){
      _super_sig_type="b0b0bar";
      if (dir==0) filename+="./prod-32-skim18c/DK/MC/B0B0bar/";
      filename+=(_isCS==kFALSE)? "BchToD0KstarAll/SP-1237-BchToD0KstarAll-Run2-*.root" : "BRecoToDDstar/SP-1237-BRecoToDDstar-Run2-*.root";
      cout<<"loading root file " << filename << endl;
      tree->Add(filename);
    }
    else if (_sig_type=="b0b0bar3"){
      _super_sig_type="b0b0bar";
      if (dir==0) filename+="./prod-32-skim18c/DK/MC/B0B0bar/";
      filename+=(_isCS==kFALSE)? "BchToD0KstarAll/SP-1237-BchToD0KstarAll-Run3-*.root" : "BRecoToDDstar/SP-1237-BRecoToDDstar-Run3-*.root";
      cout<<"loading root file " << filename << endl;
      tree->Add(filename);
    }
    else if (_sig_type=="b0b0bar4"){
      _super_sig_type="b0b0bar";
      if (dir==0) filename+="./prod-32-skim18c/DK/MC/B0B0bar/";
      filename+=(_isCS==kFALSE)? "BchToD0KstarAll/SP-1237-BchToD0KstarAll-Run4-*.root" : "BRecoToDDstar/SP-1237-BRecoToDDstar-Run4-*.root";
      cout<<"loading root file " << filename << endl;
      tree->Add(filename);
    }
    else if (_sig_type=="b0b0bar5"){
      _super_sig_type="b0b0bar";
      if (dir==0) filename+="./prod-32-skim18c/DK/MC/B0B0bar/";
      filename+=(_isCS==kFALSE)? "BchToD0KstarAll/SP-1237-BchToD0KstarAll-Run5-*.root" : "BRecoToDDstar/SP-1237-BRecoToDDstar-Run5-*.root";
      cout<<"loading root file " << filename << endl;
      tree->Add(filename);
    }
    //    
    else if (_sig_type=="ccbar1"){
      _super_sig_type="ccbar";
      if (dir==0) filename+="./prod-32-skim18c/DK/MC/ccbar/"; 
      filename+=(_isCS==kFALSE)? "BchToD0KstarAll/SP-1005-BchToD0KstarAll-Run1-*.root" : "BRecoToDDstar/SP-1005-BRecoToDDstar-Run1-*.root";
      cout<<"loading root file " << filename << endl;
      tree->Add(filename);
    }
    else if (_sig_type=="ccbar2"){
      _super_sig_type="ccbar";
      if (dir==0) filename+="./prod-32-skim18c/DK/MC/ccbar/";        
      filename+=(_isCS==kFALSE)? "BchToD0KstarAll/SP-1005-BchToD0KstarAll-Run2-*.root" : "BRecoToDDstar/SP-1005-BRecoToDDstar-Run2-*.root";
      cout<<"loading root file " << filename << endl;
      tree->Add(filename);
    }
    else if (_sig_type=="ccbar3"){
      _super_sig_type="ccbar";
      if (dir==0) filename+="./prod-32-skim18c/DK/MC/ccbar/";        
      filename+=(_isCS==kFALSE)? "BchToD0KstarAll/SP-1005-BchToD0KstarAll-Run3-*.root" : "BRecoToDDstar/SP-1005-BRecoToDDstar-Run3-*.root";
      cout<<"loading root file " << filename << endl;
      tree->Add(filename);
    }
    else if (_sig_type=="ccbar4"){
      _super_sig_type="ccbar";
      if (dir==0) filename+="./prod-32-skim18c/DK/MC/ccbar/";        
      filename+=(_isCS==kFALSE)? "BchToD0KstarAll/SP-1005-BchToD0KstarAll-Run4-*.root" : "BRecoToDDstar/SP-1005-BRecoToDDstar-Run4-*.root";
      cout<<"loading root file " << filename << endl;
      tree->Add(filename);
    }
    else if (_sig_type=="ccbar5"){
      _super_sig_type="ccbar";
      if (dir==0) filename+="./prod-32-skim18c/DK/MC/ccbar/";        
      filename+=(_isCS==kFALSE)? "BchToD0KstarAll/SP-1005-BchToD0KstarAll-Run5-*.root" : "BRecoToDDstar/SP-1005-BRecoToDDstar-Run5-*.root";
      cout<<"loading root file " << filename << endl;
      tree->Add(filename);
    }
    //
    else if (_sig_type=="uds1"){
      _super_sig_type="uds";
      if (dir==0) filename+="./prod-32-skim18c/DK/MC/uds/";
      filename+=(_isCS==kFALSE)? "BchToD0KstarAll/SP-998-BchToD0KstarAll-Run1-*.root" : "BRecoToDDstar/SP-998-BRecoToDDstar-Run1-*.root";
      cout<<"loading root file " << filename << endl;
      tree->Add(filename);
    }
    else if (_sig_type=="uds2"){
      _super_sig_type="uds";
      if (dir==0) filename+="./prod-32-skim18c/DK/MC/uds/";
      filename+=(_isCS==kFALSE)? "BchToD0KstarAll/SP-998-BchToD0KstarAll-Run2-*.root" : "BRecoToDDstar/SP-998-BRecoToDDstar-Run2-*.root";
      cout<<"loading root file " << filename << endl;
      tree->Add(filename);
    }
    else if (_sig_type=="uds3"){
      _super_sig_type="uds";
      if (dir==0) filename+="./prod-32-skim18c/DK/MC/uds/";
      filename+=(_isCS==kFALSE)? "BchToD0KstarAll/SP-998-BchToD0KstarAll-Run3-*.root" : "BRecoToDDstar/SP-998-BRecoToDDstar-Run3-*.root";
      cout<<"loading root file " << filename << endl;
      tree->Add(filename);
    }
    else if (_sig_type=="uds4"){
      _super_sig_type="uds";
      if (dir==0) filename+="./prod-32-skim18c/DK/MC/uds/";
      filename+=(_isCS==kFALSE)? "BchToD0KstarAll/SP-998-BchToD0KstarAll-Run4-*.root" : "BRecoToDDstar/SP-998-BRecoToDDstar-Run4-*.root";
      cout<<"loading root file " << filename << endl;
      tree->Add(filename);
    }
    else if (_sig_type=="uds5"){
      _super_sig_type="uds";
      if (dir==0) filename+="./prod-32-skim18c/DK/MC/uds/";
      filename+=(_isCS==kFALSE)? "BchToD0KstarAll/SP-998-BchToD0KstarAll-Run5-*.root" : "BRecoToDDstar/SP-998-BRecoToDDstar-Run5-*.root";
      cout<<"loading root file " << filename << endl;
      tree->Add(filename);
    }
    //
    else if (_sig_type=="chb1"){
      _super_sig_type="chb";
      if (dir==0) filename+="./prod-32-skim18c/DK/MC/B+B-/";
      filename+=(_isCS==kFALSE)? "BchToD0KstarAll/SP-1235-BchToD0KstarAll-Run1-*.root" : "BRecoToDDstar/SP-1235-BRecoToDDstar-Run1-*.root";
      cout<<"loading root file " << filename << endl;
      tree->Add(filename);
    } 
    else if (_sig_type=="chb2" ){
      _super_sig_type="chb";
      if (dir==0) filename+="./prod-32-skim18c/DK/MC/B+B-/";
      filename+=(_isCS==kFALSE)? "BchToD0KstarAll/SP-1235-BchToD0KstarAll-Run2-*.root" : "BRecoToDDstar/SP-1235-BRecoToDDstar-Run2-*.root";
      cout<<"loading root file " << filename << endl;
      tree->Add(filename);
    } 
    else if (_sig_type=="chb3" ){
      _super_sig_type="chb";
      if (dir==0) filename+="./prod-32-skim18c/DK/MC/B+B-/";
      filename+=(_isCS==kFALSE)? "BchToD0KstarAll/SP-1235-BchToD0KstarAll-Run3-*.root" : "BRecoToDDstar/SP-1235-BRecoToDDstar-Run3-*.root";      
      cout<<"loading root file " << filename << endl;
      tree->Add(filename);
    } 
    else if (_sig_type=="chb4" ){
      _super_sig_type="chb";
      if (dir==0) filename+="./prod-32-skim18c/DK/MC/B+B-/";
      filename+=(_isCS==kFALSE)? "BchToD0KstarAll/SP-1235-BchToD0KstarAll-Run4-*.root" : "BRecoToDDstar/SP-1235-BRecoToDDstar-Run4-*.root";      
      cout<<"loading root file " << filename << endl;
      tree->Add(filename);
    } 
    else if (_sig_type=="chb5" ){
      _super_sig_type="chb";
      if (dir==0) filename+="./prod-32-skim18c/DK/MC/B+B-/";
      filename+=(_isCS==kFALSE)? "BchToD0KstarAll/SP-1235-BchToD0KstarAll-Run5-*.root" : "BRecoToDDstar/SP-1235-BRecoToDDstar-Run5-*.root";
      cout<<"loading root file " << filename << endl;
      tree->Add(filename);
    }

    // On data    
    else if (_sig_type=="On1"){
      _super_sig_type="On";
      _isData = kTRUE;
      if (dir==0) filename+="./prod-32-skim18c/DK/DATA/";
      filename+=(_isCS==kFALSE)? "BchToD0KstarAll/BchToD0KstarAll-Run1-OnPeak-*.root": "BRecoToDDstar/BRecoToDDstar-Run1-OnPeak-*.root";
      cout<<"loading root file " << filename << endl;
      tree->Add(filename);
    } 
    else if (_sig_type=="On2"){
      _super_sig_type="On";
      _isData = kTRUE;
      if (dir==0) filename+="./prod-32-skim18c/DK/DATA/";
      filename+=(_isCS==kFALSE)? "BchToD0KstarAll/BchToD0KstarAll-Run2-OnPeak-*.root": "BRecoToDDstar/BRecoToDDstar-Run2-OnPeak-*.root";
      cout<<"loading root file " << filename << endl;
      tree->Add(filename);
    } 
    else if (_sig_type=="On3"){
      _super_sig_type="On";
      _isData = kTRUE;
      if (dir==0) filename+="./prod-32-skim18c/DK/DATA/";
      filename+=(_isCS==kFALSE)? "BchToD0KstarAll/BchToD0KstarAll-Run3-OnPeak-*.root": "BRecoToDDstar/BRecoToDDstar-Run3-OnPeak-*.root";
      cout<<"loading root file " << filename << endl;
      tree->Add(filename);
    } 
    else if (_sig_type=="On4"){
      _super_sig_type="On";
      _isData = kTRUE;
      if (dir==0) filename+="./prod-32-skim18c/DK/DATA/";
      filename+=(_isCS==kFALSE)? "BchToD0KstarAll/BchToD0KstarAll-Run4-OnPeak-*.root": "BRecoToDDstar/BRecoToDDstar-Run4-OnPeak-*.root";
      cout<<"loading root file " << filename << endl;
      tree->Add(filename);
    } 
    else if (_sig_type=="On5"){
      _super_sig_type="On";
      _isData = kTRUE;
      if (dir==0) filename+="./prod-32-skim18c/DK/DATA/";
      filename+=(_isCS==kFALSE)? "BchToD0KstarAll/BchToD0KstarAll-Run5-OnPeak-*.root": "BRecoToDDstar/BRecoToDDstar-Run5-OnPeak-*.root";
      cout<<"loading root file " << filename << endl;
      tree->Add(filename);
    }
    
    // Off data    
    else if (_sig_type=="Off1234"){
      _super_sig_type="Off";
      _isData = kTRUE;
      if (dir==0) filename+="./prod-32-skim18c/DK/DATA/BchToD0KstarAll/";
      filename1=filename+"BchToD0KstarAll-Run1-OffPeak-*.root";
      cout<<"loading root file " << filename1 << endl;
      tree->Add(filename1);
      filename1=filename+"BchToD0KstarAll-Run2-OffPeak-*.root";
      cout<<"loading root file " << filename1 << endl;
      tree->Add(filename1);
      filename1=filename+"BchToD0Kccbar4starAll-Run3-OffPeak-*.root";
      cout<<"loading root file " << filename1 << endl;
      tree->Add(filename1);
      filename1=filename+"BchToD0KstarAll-Run4-OffPeak-*.root";
      cout<<"loading root file " << filename1 << endl;
      tree->Add(filename1);
    } 
    else if (_sig_type=="Off1"){
      _super_sig_type="Off";
      _isData = kTRUE;
      if (dir==0) filename+="./prod-32-skim18c/DK/DATA/BchToD0KstarAll/";
      filename+="AllEventsSkim-Run1-OffPeak-*.root";
      cout<<"loading root file " << filename << endl;
      tree->Add(filename);
    }
    else if (_sig_type=="Off2"){
      _super_sig_type="Off";
      _isData = kTRUE;
      if (dir==0) filename+="./prod-32-skim18c/DK/DATA/BchToD0KstarAll/";
      filename+="AllEventsSkim-Run2-OffPeak-*.root";
      cout<<"loading root file " << filename << endl;
      tree->Add(filename);
    }
    else if (_sig_type=="Off3"){
      _super_sig_type="Off";
      _isData = kTRUE;
      if (dir==0) filename+="./prod-32-skim18c/DK/DATA/BchToD0KstarAll/";
      filename+="AllEventsSkim-Run3-OffPeak-*.root";
      cout<<"loading root file " << filename << endl;
      tree->Add(filename);
    }
    else if (_sig_type=="Off4"){
      _super_sig_type="Off";
      _isData = kTRUE;
      if (dir==0) filename+="./prod-32-skim18c/DK/DATA/BchToD0KstarAll/";
      filename+="AllEventsSkim-Run4-OffPeak-*.root";
      cout<<"loading root file " << filename << endl;
      tree->Add(filename);
    }
    else if (_sig_type=="Off5"){
      _super_sig_type="Off";
      _isData = kTRUE;
      if (dir==0) filename+="./prod-32-skim18c/DK/DATA/BchToD0KstarAll/";
      filename+="AllEventsSkim-Run5-OffPeak-*.root";
      cout<<"loading root file " << filename << endl;
      tree->Add(filename);
    }
    
    else {
      assert(0);
    }

  }   

  cout<<_super_sig_type<<"   done"<<endl;
  Init(tree);
}

btdkstarc::~btdkstarc()
{
  if (!fChain) return;
  delete fChain->GetCurrentFile();
}

Int_t btdkstarc::GetEntry(Int_t entry)
{
  // Read contents of entry.
  if (!fChain) return 0;
  return fChain->GetEntry(entry);
}
Int_t btdkstarc::LoadTree(Int_t entry)
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

void btdkstarc::Init(TTree *tree)
{
  //   Set branch addresses
  if (tree == 0) return;
  fChain    = tree;
  fCurrent  = -1;
  fChain->SetMakeClass(1);
  
  fChain->SetBranchAddress("event",&event);
  fChain->SetBranchAddress("runNumber",&runNumber);
  fChain->SetBranchAddress("platform",&platform);
  fChain->SetBranchAddress("partition",&partition);
  fChain->SetBranchAddress("upperID",&upperID);
  fChain->SetBranchAddress("lowerID",&lowerID);

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
  if (!_isData) {
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
  if (!_isData) 
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
  fChain->SetBranchAddress("CosTsphChB",CosTsphChB);
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
  if (!_isData) 
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
  //Kstarc
  if(_isCS==kFALSE){
    fChain->SetBranchAddress("nKstarc",&nKstarc);
    fChain->SetBranchAddress("massKstarc",massKstarc);
    fChain->SetBranchAddress("pKstarc",pKstarc);
    fChain->SetBranchAddress("thKstarc",thKstarc);
    fChain->SetBranchAddress("phiKstarc",phiKstarc);
    fChain->SetBranchAddress("errMassKstarc",errMassKstarc);
    fChain->SetBranchAddress("m0Kstarc",m0Kstarc);
    fChain->SetBranchAddress("xKstarc",xKstarc);
    fChain->SetBranchAddress("yKstarc",yKstarc);
    fChain->SetBranchAddress("zKstarc",zKstarc);
    fChain->SetBranchAddress("s2xKstarc",s2xKstarc);
    fChain->SetBranchAddress("s2yKstarc",s2yKstarc);
    fChain->SetBranchAddress("s2zKstarc",s2zKstarc);
    fChain->SetBranchAddress("chi2Kstarc",chi2Kstarc);
    fChain->SetBranchAddress("dofKstarc",dofKstarc);
    fChain->SetBranchAddress("stKstarc",stKstarc);
    fChain->SetBranchAddress("ndauKstarc",ndauKstarc);
    if (!_isData) 
      fChain->SetBranchAddress("MCKstarc",MCKstarc);
    fChain->SetBranchAddress("d1KstarcIndex",d1KstarcIndex);
    fChain->SetBranchAddress("d1KstarcLund",d1KstarcLund);
    fChain->SetBranchAddress("d2KstarcIndex",d2KstarcIndex);
    fChain->SetBranchAddress("d2KstarcLund",d2KstarcLund);
  }
  //Ks
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
  if (!_isData) 
    fChain->SetBranchAddress("MCKs",MCKs);
  fChain->SetBranchAddress("d1KsIndex",d1KsIndex);
  fChain->SetBranchAddress("d1KsLund",d1KsLund);
  fChain->SetBranchAddress("d2KsIndex",d2KsIndex);
  fChain->SetBranchAddress("d2KsLund",d2KsLund);
  if(_isCS==kFALSE){
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
    if (!_isData) 
      fChain->SetBranchAddress("MCPi0",MCPi0);
    fChain->SetBranchAddress("d1Pi0Index",d1Pi0Index);
    fChain->SetBranchAddress("d1Pi0Lund",d1Pi0Lund);
    fChain->SetBranchAddress("d2Pi0Index",d2Pi0Index);
    fChain->SetBranchAddress("d2Pi0Lund",d2Pi0Lund);
  }
  //Trk

  fChain->SetBranchAddress("nTrk",&nTrk);

  fChain->SetBranchAddress("cTheTrk",cTheTrk);
  fChain->SetBranchAddress("sTheTrk",sTheTrk);
  fChain->SetBranchAddress("nPhotTrk",nPhotTrk);
  fChain->SetBranchAddress("nexPhot0Trk",nexPhot0Trk);
  fChain->SetBranchAddress("nexPhot1Trk",nexPhot1Trk);
  fChain->SetBranchAddress("nexPhot2Trk",nexPhot2Trk);
  fChain->SetBranchAddress("nexPhot3Trk",nexPhot3Trk);
  fChain->SetBranchAddress("nexPhot4Trk",nexPhot4Trk);
  fChain->SetBranchAddress("nbgPhotTrk",nbgPhotTrk);
  fChain->SetBranchAddress("drcInBarTrk",drcInBarTrk);
  fChain->SetBranchAddress("drcExitBarTrk",drcExitBarTrk);
  fChain->SetBranchAddress("drcXposTrk",drcXposTrk);
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
  if (!_isData) {
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
  if (!_isData) {
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

  if (_isCS==kTRUE){
    fChain->SetBranchAddress("mMissChB",mMissChB);
    fChain->SetBranchAddress("mMissErrChB",mMissErrChB);
   
    fChain->SetBranchAddress("nA1c",&nA1c);
    fChain->SetBranchAddress("massA1c",massA1c);
    fChain->SetBranchAddress("pA1c",pA1c);
    fChain->SetBranchAddress("thA1c",thA1c);
    fChain->SetBranchAddress("phiA1c",phiA1c);
    fChain->SetBranchAddress("errMassA1c",errMassA1c);
    fChain->SetBranchAddress("m0A1c",m0A1c);
    fChain->SetBranchAddress("xA1c",xA1c);
    fChain->SetBranchAddress("yA1c",yA1c);
    fChain->SetBranchAddress("zA1c",zA1c);
    fChain->SetBranchAddress("s2xA1c",s2xA1c);
    fChain->SetBranchAddress("s2yA1c",s2yA1c);
    fChain->SetBranchAddress("s2zA1c",s2zA1c);
    fChain->SetBranchAddress("chi2A1c",chi2A1c);
    fChain->SetBranchAddress("dofA1c",dofA1c);
    fChain->SetBranchAddress("stA1c",stA1c);
    fChain->SetBranchAddress("ndauA1c",ndauA1c);
    if(!_isData)
      fChain->SetBranchAddress("MCA1c",MCA1c);
    fChain->SetBranchAddress("d1A1cIndex",d1A1cIndex);
    fChain->SetBranchAddress("d1A1cLund",d1A1cLund);
    fChain->SetBranchAddress("d2A1cIndex",d2A1cIndex);
    fChain->SetBranchAddress("d2A1cLund",d2A1cLund);
    fChain->SetBranchAddress("nRho0",&nRho0);
    fChain->SetBranchAddress("massRho0",massRho0);
    fChain->SetBranchAddress("pRho0",pRho0);
    fChain->SetBranchAddress("thRho0",thRho0);
    fChain->SetBranchAddress("phiRho0",phiRho0);
    fChain->SetBranchAddress("errMassRho0",errMassRho0);
    fChain->SetBranchAddress("m0Rho0",m0Rho0);
    fChain->SetBranchAddress("xRho0",xRho0);
    fChain->SetBranchAddress("yRho0",yRho0);
    fChain->SetBranchAddress("zRho0",zRho0);
    fChain->SetBranchAddress("s2xRho0",s2xRho0);
    fChain->SetBranchAddress("s2yRho0",s2yRho0);
    fChain->SetBranchAddress("s2zRho0",s2zRho0);
    fChain->SetBranchAddress("chi2Rho0",chi2Rho0);
    fChain->SetBranchAddress("dofRho0",dofRho0);
    fChain->SetBranchAddress("stRho0",stRho0);
    fChain->SetBranchAddress("ndauRho0",ndauRho0);
    if(!_isData)
      fChain->SetBranchAddress("MCRho0",MCRho0);
    fChain->SetBranchAddress("d1Rho0Index",d1Rho0Index);
    fChain->SetBranchAddress("d1Rho0Lund",d1Rho0Lund);
    fChain->SetBranchAddress("d2Rho0Index",d2Rho0Index);
    fChain->SetBranchAddress("d2Rho0Lund",d2Rho0Lund);
  }
  Notify();
}

Bool_t btdkstarc::Notify()
{
  // Called when loading a new file.

  // Get branch pointers
  b_event = fChain->GetBranch("event");
  b_runNumber = fChain->GetBranch("runNumber");
  b_platform = fChain->GetBranch("platform");
  b_partition = fChain->GetBranch("partition");
  b_upperID = fChain->GetBranch("upperID");
  b_lowerID = fChain->GetBranch("lowerID");

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
  if (!_isData) {
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
  b_CosTsphChB = fChain->GetBranch("CosTsphChB");
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
  //Kstarc
  if(_isCS==kFALSE){
    b_nKstarc = fChain->GetBranch("nKstarc");
    b_massKstarc = fChain->GetBranch("massKstarc");
    b_pKstarc = fChain->GetBranch("pKstarc");
    b_thKstarc = fChain->GetBranch("thKstarc");
    b_phiKstarc = fChain->GetBranch("phiKstarc");
    b_errMassKstarc = fChain->GetBranch("errMassKstarc");
    b_m0Kstarc = fChain->GetBranch("m0Kstarc");
    b_xKstarc = fChain->GetBranch("xKstarc");
    b_yKstarc = fChain->GetBranch("yKstarc");
    b_zKstarc = fChain->GetBranch("zKstarc");
    b_s2xKstarc = fChain->GetBranch("s2xKstarc");
    b_s2yKstarc = fChain->GetBranch("s2yKstarc");
    b_s2zKstarc = fChain->GetBranch("s2zKstarc");
    b_chi2Kstarc = fChain->GetBranch("chi2Kstarc");
    b_dofKstarc = fChain->GetBranch("dofKstarc");
    b_stKstarc = fChain->GetBranch("stKstarc");
    b_ndauKstarc = fChain->GetBranch("ndauKstarc");
    if (!_isData) 
      b_MCKstarc = fChain->GetBranch("MCKstarc");
    b_d1KstarcIndex = fChain->GetBranch("d1KstarcIndex");
    b_d1KstarcLund = fChain->GetBranch("d1KstarcLund");
    b_d2KstarcIndex = fChain->GetBranch("d2KstarcIndex");
    b_d2KstarcLund = fChain->GetBranch("d2KstarcLund");
  } 
  //Ks
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
  if (!_isData) 
    b_MCKs = fChain->GetBranch("MCKs");
  b_d1KsIndex = fChain->GetBranch("d1KsIndex");
  b_d1KsLund = fChain->GetBranch("d1KsLund");
  b_d2KsIndex = fChain->GetBranch("d2KsIndex");
  b_d2KsLund = fChain->GetBranch("d2KsLund");
  if(_isCS==kFALSE){  
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
  }
  //Trk
  b_nTrk = fChain->GetBranch("nTrk");
 
  b_cTheTrk = fChain->GetBranch("cTheTrk");
  b_sTheTrk = fChain->GetBranch("sTheTrk");
  b_nPhotTrk = fChain->GetBranch("nPhotTrk");
  b_nexPhot0Trk = fChain->GetBranch("nexPhot0Trk");
  b_nexPhot1Trk = fChain->GetBranch("nexPhot1Trk");
  b_nexPhot2Trk = fChain->GetBranch("nexPhot2Trk");
  b_nexPhot3Trk = fChain->GetBranch("nexPhot3Trk");
  b_nexPhot4Trk = fChain->GetBranch("nexPhot4Trk");
  b_nbgPhotTrk = fChain->GetBranch("nbgPhotTrk");
  b_drcInBarTrk = fChain->GetBranch("drcInBarTrk");
  b_drcExitBarTrk = fChain->GetBranch("drcExitBarTrk");
  b_drcXposTrk = fChain->GetBranch("drcXposTrk");
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
  if (!_isData) {
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
  if (!_isData) {
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

  if(_isCS==kTRUE){

    b_mMissChB = fChain->GetBranch("mMissChB");
    b_mMissErrChB = fChain->GetBranch("mMissErrChB");
  
    b_nA1c = fChain->GetBranch("nA1c");
    b_massA1c = fChain->GetBranch("massA1c");
    b_pA1c = fChain->GetBranch("pA1c");
    b_thA1c = fChain->GetBranch("thA1c");
    b_phiA1c = fChain->GetBranch("phiA1c");
    b_errMassA1c = fChain->GetBranch("errMassA1c");
    b_m0A1c = fChain->GetBranch("m0A1c");
    b_xA1c = fChain->GetBranch("xA1c");
    b_yA1c = fChain->GetBranch("yA1c");
    b_zA1c = fChain->GetBranch("zA1c");
    b_s2xA1c = fChain->GetBranch("s2xA1c");
    b_s2yA1c = fChain->GetBranch("s2yA1c");
    b_s2zA1c = fChain->GetBranch("s2zA1c");
    b_chi2A1c = fChain->GetBranch("chi2A1c");
    b_dofA1c = fChain->GetBranch("dofA1c");
    b_stA1c = fChain->GetBranch("stA1c");
    b_ndauA1c = fChain->GetBranch("ndauA1c");
    if(!_isData)
      b_MCA1c = fChain->GetBranch("MCA1c");
    b_d1A1cIndex = fChain->GetBranch("d1A1cIndex");
    b_d1A1cLund = fChain->GetBranch("d1A1cLund");
    b_d2A1cIndex = fChain->GetBranch("d2A1cIndex");
    b_d2A1cLund = fChain->GetBranch("d2A1cLund");
    b_nRho0 = fChain->GetBranch("nRho0");
    b_massRho0 = fChain->GetBranch("massRho0");
    b_pRho0 = fChain->GetBranch("pRho0");
    b_thRho0 = fChain->GetBranch("thRho0");
   b_phiRho0 = fChain->GetBranch("phiRho0");
   b_errMassRho0 = fChain->GetBranch("errMassRho0");
   b_m0Rho0 = fChain->GetBranch("m0Rho0");
   b_xRho0 = fChain->GetBranch("xRho0");
   b_yRho0 = fChain->GetBranch("yRho0");
   b_zRho0 = fChain->GetBranch("zRho0");
   b_s2xRho0 = fChain->GetBranch("s2xRho0");
   b_s2yRho0 = fChain->GetBranch("s2yRho0");
   b_s2zRho0 = fChain->GetBranch("s2zRho0");
   b_chi2Rho0 = fChain->GetBranch("chi2Rho0");
   b_dofRho0 = fChain->GetBranch("dofRho0");
   b_stRho0 = fChain->GetBranch("stRho0");
   b_ndauRho0 = fChain->GetBranch("ndauRho0");
   if(!_isData)
     b_MCRho0 = fChain->GetBranch("MCRho0");
   b_d1Rho0Index = fChain->GetBranch("d1Rho0Index");
   b_d1Rho0Lund = fChain->GetBranch("d1Rho0Lund");
   b_d2Rho0Index = fChain->GetBranch("d2Rho0Index");
   b_d2Rho0Lund = fChain->GetBranch("d2Rho0Lund");
  
  }
  return kTRUE;
}

void btdkstarc::Show(Int_t entry)
{
  // Print contents of entry.
  // If entry is not specified, print current entry
  if (!fChain) return;
  fChain->Show(entry);
}
Int_t btdkstarc::Cut(Int_t entry)
{
  // This function may be called from Loop.
  // returns  1 if entry is accepted.
  // returns -1 otherwise.
  // These 2 lines of code avoid the warning
  Int_t nentry;
  nentry = entry;

  return 1;
}
#endif // #ifdef btdkstarc_cxx

