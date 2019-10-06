#define inclDstar_cxx
#include "inclDstar.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void inclDstar::Loop(Int_t nentries)
{
//   In a ROOT session, you can do:
//      Root > .L inclDstar.C
//      Root > inclDstar t
//      Root > t.GetEntry(12); // Fill t data members with entry number 12
//      Root > t.Show();       // Show values of entry 12
//      Root > t.Show(16);     // Read and show values of entry 16
//      Root > t.Loop();       // Loop on all entries
//
  
//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
    
  //cout<<"in LOOP"<<endl;
  //start timer
  TStopwatch timer;
  timer.Start();
  //cout <<"test cout"<<endl;  
   if (fChain == 0) return;
  
  //
  //define output root file
  //
   //  TString rootfile_name = "./root/inclDstar_"+_d0mode+"_"+_sig_type+".root";
  TString rootfile_name = "~/myScratch/prod-32/test/inclDstar_"+_d0mode+"_"+_sig_type+".root";
  TFile *hfile = new TFile(rootfile_name,"RECREATE","Reduced root file");
  
  cout<<"in LOOP"<<endl;
  //
  //define output tree with its branches
  const char* name = "Dstar";
  TTree *tree = new TTree(name,"Reduced ROOT tree"); 
  // getchar();
  
  //general info
  Int_t lundD0Trk(-999);
  if (_d0mode=="kspipi"){
    lundD0Trk=211;
  } else if (_d0mode=="kskk") {
    lundD0Trk=321;
  } else assert(0);
  //
  tree->Branch("event",&event,"event/I");
  tree->Branch("runNumber",&runNumber,"runNumber/F");
  tree->Branch("upperID",&upperID,"upperID/I");
  tree->Branch("lowerID",&upperID,"lowerID/I");
  //
  tree->Branch("pxUps",&pxUps,"pxUps/F");
  tree->Branch("pyUps",&pyUps,"pyUps/F");
  tree->Branch("pzUps",&pzUps,"pzUps/F");
  tree->Branch("eUps", &eUps, "eUps/F");
  
  Int_t McEvtType;
  tree->Branch("nMc",&nMc,"nMc/I");
  tree->Branch("idMc",idMc,"idMc[nMc]/I");
  tree->Branch("mothMc",mothMc,"mothMc[nMc]/I");
  tree->Branch("nDauMc",nDauMc,"nDauMc[nMc]/I");
  tree->Branch("pMc",pMc,"pMc[nMc]/F");
  tree->Branch("thetaMc",thetaMc,"thetaMc[nMc]/F");
  tree->Branch("phiMc",phiMc,"phiMc[nMc]/F");
  tree->Branch("McEvtType",&McEvtType,"McEvtType/I");

  //Analysis variables
  Float_t deltamDstarmD0,deltamDstarmD0BS,mydeltaMDstarBS,cosDstarCM,mymassDstarBS,mychi2DstarBS,mydofDstarBS;
  tree->Branch("deltamDstarmD0",&deltamDstarmD0,"deltamDstarmD0/F");
  tree->Branch("deltamDstarmD0BS",&deltamDstarmD0BS,"deltamDstarmD0BS/F");
  tree->Branch("deltaMDstarBS",&mydeltaMDstarBS,"deltaMDstarBS/F");

  //Dstar Beam Spot constrain    
  tree->Branch("massDstarBS",&mymassDstarBS,"massDstarBS/F");
  tree->Branch("chi2DstarBS",&mychi2DstarBS,"chi2DstarBS/F");
  tree->Branch("dofDstarBS",&mydofDstarBS,"dofDstarBS/F");
  tree->Branch("cosDstarCM",&cosDstarCM,"cosDstarCM/F");

  //Dstar
  Float_t mymassDstar,pxDstar,pyDstar,pzDstar,mym0Dstar,mychi2Dstar,mydofDstar,myxDstar,myyDstar,myzDstar;
  Int_t indexMcDstar;
  tree->Branch("massDstar",&mymassDstar,"massDstar/F");
  tree->Branch("pxDstar",&pxDstar,"pxDstar/F");
  tree->Branch("pyDstar",&pyDstar,"pyDstar/F");
  tree->Branch("pzDstar",&pzDstar,"pzDstar/F");
  tree->Branch("m0Dstar",&mym0Dstar,"m0Dstar/F");
  tree->Branch("chi2Dstar",&mychi2Dstar,"chi2Dstar/F");
  tree->Branch("dofDstar",&mydofDstar,"dofDstar/F");
  tree->Branch("xDstar",&myxDstar,"xDstar/F");
  tree->Branch("yDstar",&myyDstar,"yDstar/F");
  tree->Branch("zDstar",&myzDstar,"zDstar/F");
  tree->Branch("indexMcDstar",&indexMcDstar,"indexMcDstar/F");
  
  //D0
  Float_t mym0D0,mymassD0,pxD0,pyD0,pzD0,eD0,pcmsD0,mychi2D0,mydofD0,myxD0,myyD0,myzD0;
  Float_t mym2pDalitzD0,mym2mDalitzD0,mym2zDalitzD0,mymTotDalitzD0,mychi2DalitzD0;
  Int_t mystDalitzD0,mydofDalitzD0;
  Int_t indexMcD0,isMcD0;
  tree->Branch("m0D0",&mym0D0,"m0D0/F");
  tree->Branch("massD0",&mymassD0,"massD0/F");
  tree->Branch("pxD0",&pxD0,"pxD0/F");
  tree->Branch("pyD0",&pyD0,"pyD0/F");
  tree->Branch("pzD0",&pzD0,"pzD0/F");
  tree->Branch("eD0",&eD0,"eD0/F");
  tree->Branch("pcmsD0",&pcmsD0,"pcmsD0/F");
  tree->Branch("chi2D0",&mychi2D0,"chi2D0/F");
  tree->Branch("dofD0",&mydofD0,"dofD0/F");
  tree->Branch("xD0",&myxD0,"xD0/F");
  tree->Branch("yD0",&myyD0,"yD0/F");
  tree->Branch("zD0",&myzD0,"zD0/F");
  tree->Branch("indexMcD0",&indexMcD0,"indexMcD0/I");
  tree->Branch("isMcD0",&isMcD0,"isMcD0/I");
  tree->Branch("m2pDalitzD0", &mym2pDalitzD0, "m2pDalitzD0/F");
  tree->Branch("m2mDalitzD0", &mym2mDalitzD0, "m2mDalitzD0/F");
  tree->Branch("m2zDalitzD0", &mym2zDalitzD0, "m2zDalitzD0/F");
  tree->Branch("stDalitzD0", &mystDalitzD0, "stDalitzD0/I");
  tree->Branch("mTotDalitzD0", &mymTotDalitzD0, "mTotDalitzD0/F");
  tree->Branch("chi2DalitzD0", &mychi2DalitzD0, "chi2DalitzD0/F");
  tree->Branch("dofDalitzD0", &mydofDalitzD0, "dofDalitzD0/I");


  //Pi track
  Float_t pxPi,pyPi,pzPi,cthePi,deltadrcmomPi;
  Int_t lundPi,kaonidPi,ndchPi,nphotPi,lundMcPi,indexMcPi;
  Float_t effCorMcPi,sEffCorMcPi;
  tree->Branch("pxPi",&pxPi,"pxPi/F");
  tree->Branch("pyPi",&pyPi,"pyPi/F");
  tree->Branch("pzPi",&pzPi,"pzPi/F");
  tree->Branch("cthePi",&cthePi,"cthePi/F");
  tree->Branch("deltadrcmomPi",&deltadrcmomPi,"deltadrcmomPi/F");
  tree->Branch("lundPi",&lundPi,"lundPi/I");
  tree->Branch("kaonidPi",&kaonidPi,"kaonidPi/I");
  tree->Branch("ndchPi",&ndchPi,"ndchPi/I");
  tree->Branch("nphotPi",&nphotPi,"nphotPi/I");
  tree->Branch("lundMcPi",&lundMcPi,"lundMcPi/I");
  tree->Branch("indexMcPi",&indexMcPi,"indexMcPi/I");
  tree->Branch("effCorMcPi",&effCorMcPi,"effCorMcPi/F");
  tree->Branch("sEffCorMcPi",&sEffCorMcPi,"sEffCorMcPi/F");

  //pi momenta
  Float_t pPiDstarBS;
  tree->Branch("spixDstarBS",&spixDstarBS,"spixDstarBS/F");
  tree->Branch("spiyDstarBS",&spiyDstarBS,"spiyDstarBS/F");
  tree->Branch("spizDstarBS",&spizDstarBS,"spizDstarBS/F");
  tree->Branch("pPiDstarBS",&pPiDstarBS,"pPiDstarBS/F");



  //Ks (from D0)
  Float_t mymassKs,pxKs,pyKs,pzKs,myxKs,myyKs,myzKs,mychi2Ks,cosKs;
  Int_t mydofKs,indexMcKs;
  Int_t isMcKs;       
  tree->Branch("massKs",&mymassKs,"massKs/F");
  tree->Branch("pxKs",&pxKs,"pxKs/F");
  tree->Branch("pyKs",&pyKs,"pyKs/F");
  tree->Branch("pzKs",&pzKs,"pzKs/F");
  tree->Branch("xKs",&myxKs,"xKs/F");
  tree->Branch("yKs",&myyKs,"yKs/F");
  tree->Branch("zKs",&myzKs,"zKs/F");
  tree->Branch("chi2Ks",&mychi2Ks,"chi2Ks/F");
  tree->Branch("dofKs",&mydofKs,"dofKs/I");
  tree->Branch("cosKs",&cosKs,"cosKs/F");
  tree->Branch("isMcKs",&isMcKs,"isMcKs/I");
  tree->Branch("indexMcKs",&indexMcKs,"indexMcKs/I");
  
  //KsPi1  (1st pi from Ks from D0)
  Float_t pxKsPi1,pyKsPi1,pzKsPi1;
  Int_t lundKsPi1,kaonidKsPi1,ndchKsPi1,indexMcD0KsPi1;
  Int_t lundMcKsPi1;
  Float_t effCorMcD0KsPi1,sEffCorMcD0KsPi1;
  tree->Branch("pxKsPi1",&pxKsPi1,"pxKsPi1/F");
  tree->Branch("pyKsPi1",&pyKsPi1,"pyKsPi1/F");
  tree->Branch("pzKsPi1",&pzKsPi1,"pzKsPi1/F");
  tree->Branch("lundMcKsPi1",&lundMcKsPi1,"lundMcKsPi1/I");
  tree->Branch("lundKsPi1",&lundKsPi1,"lundKsPi1/I");
  tree->Branch("kaonidKsPi1",&kaonidKsPi1,"kaonidKsPi1/I");
  tree->Branch("ndchKsPi1",&ndchKsPi1,"ndchKsPi1/I");
  tree->Branch("indexMcD0KsPi1",&indexMcD0KsPi1,"indexMcD0KsPi1/I");
  tree->Branch("effCorMcD0KsPi1",&effCorMcD0KsPi1,"effCorMcD0KsPi1/F");
  tree->Branch("sEffCorMcD0KsPi1",&sEffCorMcD0KsPi1,"sEffCorMcD0KsPi1/F");
  
  //KsPi2 (2nd pi from Ks from D0)
  Float_t pxKsPi2,pyKsPi2,pzKsPi2;
  Int_t lundKsPi2,kaonidKsPi2,ndchKsPi2,indexMcD0KsPi2;
  Int_t lundMcKsPi2;
  Float_t effCorMcD0KsPi2,sEffCorMcD0KsPi2;
  tree->Branch("pxKsPi2",&pxKsPi2,"pxKsPi2/F");
  tree->Branch("pyKsPi2",&pyKsPi2,"pyKsPi2/F");
  tree->Branch("pzKsPi2",&pzKsPi2,"pzKsPi2/F");
  tree->Branch("lundMcKsPi2",&lundMcKsPi2,"lundMcKsPi2/I");   
  tree->Branch("lundKsPi2",&lundKsPi2,"lundKsPi2/I");
  tree->Branch("kaonidKsPi2",&kaonidKsPi2,"kaonidKsPi2/I");
  tree->Branch("ndchKsPi2",&ndchKsPi2,"ndchKsPi2/I"); 
  tree->Branch("indexMcD0KsPi2",&indexMcD0KsPi2,"indexMcD0KsPi2/I");
  tree->Branch("effCorMcD0KsPi2",&effCorMcD0KsPi2,"effCorMcD0KsPi2/F");
  tree->Branch("sEffCorMcD0KsPi2",&sEffCorMcD0KsPi2,"sEffCorMcD0KsPi2/F");
  
  //D0Pi1 (1st pi from D0)
  Float_t pxD0Pi1,pyD0Pi1,pzD0Pi1;
  Int_t lundMcD0Pi1,lundD0Pi1,kaonidD0Pi1,ndchD0Pi1,indexMcD0Pi1;
  Float_t effCorMcD0Pi1,sEffCorMcD0Pi1;
  tree->Branch("pxD0Pi1",&pxD0Pi1,"pxD0Pi1/F");
  tree->Branch("pyD0Pi1",&pyD0Pi1,"pyD0Pi1/F");
  tree->Branch("pzD0Pi1",&pzD0Pi1,"pzD0Pi1/F");
  tree->Branch("lundMcD0Pi1",&lundMcD0Pi1,"lundMcD0Pi1/I");
  tree->Branch("lundD0Pi1",&lundD0Pi1,"lundD0Pi1/I");
  tree->Branch("kaonidD0Pi1",&kaonidD0Pi1,"kaonidD0Pi1/I");
  tree->Branch("ndchD0Pi1",&ndchD0Pi1,"ndchD0Pi1/I");
  tree->Branch("indexMcD0Pi1",&indexMcD0Pi1,"indexMcD0Pi1/I");
  tree->Branch("effCorMcD0Pi1",&effCorMcD0Pi1,"effCorMcD0Pi1/F");
  tree->Branch("sEffCorMcD0Pi1",&sEffCorMcD0Pi1,"sEffCorMcD0Pi1/F");
  
  //D0Pi2 (2nd pi from D0)
  Float_t pxD0Pi2,pyD0Pi2,pzD0Pi2;
  Int_t lundMcD0Pi2,lundD0Pi2,kaonidD0Pi2,ndchD0Pi2,indexMcD0Pi2;
  Float_t effCorMcD0Pi2,sEffCorMcD0Pi2;
  tree->Branch("pxD0Pi2",&pxD0Pi2,"pxD0Pi2/F");
  tree->Branch("pyD0Pi2",&pyD0Pi2,"pyD0Pi2/F");
  tree->Branch("pzD0Pi2",&pzD0Pi2,"pzD0Pi2/F");
  tree->Branch("lundMcD0Pi2",&lundMcD0Pi2,"lundMcD0Pi2/I");
  tree->Branch("lundD0Pi2",&lundD0Pi2,"lundD0Pi2/I");
  tree->Branch("kaonidD0Pi2",&kaonidD0Pi2,"kaonidD0Pi2/I");
  tree->Branch("ndchD0Pi2",&ndchD0Pi2,"ndchD0Pi2/I");
  tree->Branch("indexMcD0Pi2",&indexMcD0Pi2,"indexMcD0Pi2/I");
  tree->Branch("effCorMcD0Pi2",&effCorMcD0Pi2,"effCorMcD0Pi2/F");
  tree->Branch("sEffCorMcD0Pi2",&sEffCorMcD0Pi2,"sEffCorMcD0Pi2/F");
  
  //(Control) histo's definition
  
  TH1F* Tdelta=new TH1F("Tdelta","deltaM",60,0.135,0.150);
  TH1F* TdeltaBS=new TH1F("TdeltaBS","deltaM-BS",60,0.135,0.150);
  TH1F* Tmassd0=new TH1F("Tmass","massD0",60,1.770,1.970);
  TH2F* Tdalitz = new TH2F("Tdalitz","Dalitz plot q+:q-",100,0,4.,100,0,4.);
  TH1F* Tdalitz_qp = new TH1F("Tdalitz_qp","Dalitz plot q+",100,0,4.);
  TH1F* Tdalitz_qm = new TH1F("Tdalitz_qm","Dalitz plot q-",100,0,4.);
  TH1F* Tdalitz_qz = new TH1F("Tdalitz_qz","Dalitz plot q0",100,0,4.);
  TH1F* Tpd0 = new TH1F("Tpd0","pD0",60,0.,5.);
  TH1F* Tpcmsd0 = new TH1F("Tpcmsd0","pcmsD0",60,0.,5.);
  
  TCanvas* cControl = new TCanvas("cControl","Canvas Control",1);
  if (nentries<=0 || nentries>fChain->GetEntries()) nentries = Int_t(fChain->GetEntries());
  //  cout << "Outside Loop, nentries=" << nentries << endl;

  Int_t nbytes = 0; 
  Int_t nb = 0;
  
  for (Int_t jentry=0; jentry<nentries;jentry++) {
    
    Int_t ientry = LoadTree(jentry);
    
    if (ientry < 0) break;
    
    nb = fChain->GetEntry(jentry);  
    
    // cout << "Inside Loop, jentry=" << jentry << " Inside Loop, ientry=" << " nb=" << nb << endl;
    nbytes += nb;
    
    for (Int_t i=0;i<nDstar;i++){
      //	cout << "Inside Loop on nChB, i="   << i   << endl;
      
      if (!isDstartoD0Pi(lundD0Trk,421,211,i)) continue;
      //	assert(0);
      //	cout<<"after isBtoDK"<<endl;
     
      McEvtType = 0;
      //if(_sig_type=="data") cout<<"processing data. jentry = "<<jentry<<endl;
      if (_sig_type=="ccbar" || _sig_type=="signal" || _sig_type=="signalPHSP" || _sig_type=="signalm" || _sig_type=="signalp") {
	
	Bool_t isResonantD0;
	McEvtType =isSignalEvt(lundD0Trk,421,i,isResonantD0);
	
	//cout << "isSignalEvt=" << McEvtType<< " jentry = " << jentry << endl;
	//cout << _sig_type << endl;
	//if (isResonantD0) cout << "Resonant D0" << endl; // else cout << "Non Resonant D0" << endl;
	
	// skip events not consistent with signal type
	if (_sig_type=="signal") {
	  if ( (McEvtType&1)==1 || (McEvtType&2)==2) { 
	    //cout << "D* signal event found and accepted. jentry = " << jentry << " isSignalEvt= " << McEvtType << endl;
	  } else
	    continue;
	} 
	
	// skip events not consistent with signal type
	if (_sig_type=="signalPHSP" || _sig_type=="signalm" || _sig_type=="signalp") {
	  if ( ( (McEvtType&1)==1 || (McEvtType&2)==2 ) && !isResonantD0) {
	    //cout << "D* signal PHPS event found and accepted. jentry = " << jentry << " isSignalEvt= " << McEvtType << endl;
	  } else
	    continue;
	} 
	
	//generic ccbar background (excludide D* signal)
	if (_sig_type=="ccbar") {
	  if ( (McEvtType&1)==1 || (McEvtType&2)==2) {
	    //cout << "D* signal event found and rejected. jentry = " << jentry << " isSignalEvt= " << McEvtType << endl;
	    continue;
	  }
	} 
      }	                  
      
      //define particle indexes
      Int_t i_Pi;
      Int_t i_D0(-999),i_D0Ks,i_D0Pi1,i_D0Pi2,i_D0KsPi1,i_D0KsPi2;
      
      i_D0=d1DstarIndex[i]-1;
      i_Pi=d2DstarIndex[i]-1;
      
      //define D0 dau
      if (d1D0Lund[i_D0]==310) {
	assert( (abs(d2D0Lund[i_D0])==lundD0Trk) && (abs(d3D0Lund[i_D0])==lundD0Trk) ); 
	i_D0Ks=d1D0Index[i_D0]-1;
	i_D0Pi1=d2D0Index[i_D0]-1;
	i_D0Pi2=d3D0Index[i_D0]-1;
      } else {
	assert( (abs(d1D0Lund[i_D0])==lundD0Trk) && (abs(d2D0Lund[i_D0])==lundD0Trk) ); 
	i_D0Ks=d3D0Index[i_D0]-1;
	i_D0Pi1=d1D0Index[i_D0]-1;
	i_D0Pi2=d2D0Index[i_D0]-1;
      }
      
      //define Ks's dau (from D0)
      i_D0KsPi1=d1KsIndex[i_D0Ks]-1;
      i_D0KsPi2=d2KsIndex[i_D0Ks]-1;
      
      //define Dstar info
      Float_t mypDstar=pDstar[i];
      pxDstar=mypDstar*sin(thDstar[i])*cos(phiDstar[i]);
      pyDstar=mypDstar*sin(thDstar[i])*sin(phiDstar[i]);
      pzDstar=mypDstar*cos(thDstar[i]);
      
      pPiDstarBS=sqrt(spizDstarBS[i]*spizDstarBS[i]+spiyDstarBS[i]*spiyDstarBS[i]+spizDstarBS[i]*spizDstarBS[i]);
      //see after for CM quantities
      
      mym0Dstar=m0Dstar[i];
      mymassDstar=massDstar[i];
      mymassDstarBS=massDstarBS[i];
      mychi2Dstar=chi2Dstar[i];
      mychi2DstarBS=chi2DstarBS[i];
      mydeltaMDstarBS=deltaMDstarBS[i];
      mydofDstar=dofDstar[i];
      mydofDstarBS=dofDstarBS[i];
      myxDstar=xDstar[i];
      myyDstar=yDstar[i];
      myzDstar=zDstar[i];
      TVector3 VDstar(myxDstar,myyDstar,myzDstar);//per a calcul de Alpha.
      
      indexMcDstar=MCDstar[i]-1;
      //indexMcChB = (indexMcDstar0>=0)? mothMc[indexMcDstar0]-1 : -999 ;
      //      legendrep0=LegendreP0ChB[i];
      //  	legendrep2=LegendreP2ChB[i];
      //  	fisher=FisherChB[i];
      //  	costhrust=cosTBChB[i];
      
      
      //define D0 info
      Float_t mypD0=pD0[i_D0];
      pxD0=mypD0*sin(thD0[i_D0])*cos(phiD0[i_D0]);
      pyD0=mypD0*sin(thD0[i_D0])*sin(phiD0[i_D0]);
      pzD0=mypD0*cos(thD0[i_D0]);
      myxD0=xD0[i_D0];
      myyD0=yD0[i_D0];
      myzD0=zD0[i_D0];
      TVector3 VD0(myxD0,myyD0,myzD0);
      eD0=sqrt(mypD0*mypD0+massD0[i_D0]*massD0[i_D0]);
      mychi2D0=chi2D0[i_D0];
      mydofD0=dofD0[i_D0];
      mym0D0=m0D0[i_D0];
      mymassD0=massD0[i_D0];
      mym2pDalitzD0=m2pDalitzD0[i_D0];
      mym2mDalitzD0=m2mDalitzD0[i_D0];
      mym2zDalitzD0=m2zDalitzD0[i_D0];
      mystDalitzD0=stDalitzD0[i_D0];
      mymTotDalitzD0=mTotDalitzD0[i_D0];
      mychi2DalitzD0=chi2DalitzD0[i_D0];
      mydofDalitzD0=dofDalitzD0[i_D0];
      indexMcD0=MCD0[i_D0]-1;
      //indexMcD0 = isMcD0? mothMc[indexMcD0Pi1]-1 : -999 ;
      //
      // D0 momentum in CMS frame
      TLorentzVector p4cmsD0(pxD0,pyD0,pzD0,eD0);
      TVector3 boostVector(pxUps/eUps,pyUps/eUps,pzUps/eUps);
      p4cmsD0.Boost(-boostVector);
      pcmsD0=sqrt(p4cmsD0.Px()*p4cmsD0.Px()+p4cmsD0.Py()*p4cmsD0.Py()+p4cmsD0.Pz()*p4cmsD0.Pz());
      
      //define pion track info
      Float_t pPi=momentumTrk[i_Pi];
      pxPi=pPi*sin(thetaTrk[i_Pi])*cos(phiTrk[i_Pi]);
      pyPi=pPi*sin(thetaTrk[i_Pi])*sin(phiTrk[i_Pi]);
      pzPi=pPi*cos(thetaTrk[i_Pi]);
      kaonidPi=kaonIdTrk[i_Pi];
      //	cout<<"kaonidPi ="<<kaonidPi<<endl;
      ndchPi=ndchTrk[i_Pi];
      //	deltadrcmomPi=deltadrcmomTrk[i_Pi];
      lundPi=d2DstarLund[i];
      cthePi=cTheTrk[i_Pi];
      nphotPi=nPhotTrk[i_Pi];
      indexMcPi = (!_isData)? IndexTrk[i_Pi]-1 : -999;
      effCorMcPi = (!_isData)? effCorTrk[i_Pi]-1 : -999;
      sEffCorMcPi = (!_isData)? sEffCorTrk[i_Pi]-1 : -999;
      
      // Calculate Dstar CM quantities
      Float_t eDstar(0.);
      //Float_t mk=0.49368;
      Float_t mnomPi=0.13957;
      eDstar =eD0 + sqrt(pPi*pPi+mnomPi*mnomPi);
      
      
      TLorentzVector p4Dstar(pxDstar,pyDstar,pzDstar,eDstar);
      TLorentzVector p4LabDstar(p4Dstar);
      TVector3 betaChB=p4Dstar.BoostVector();
      TLorentzVector p4Labups(pxUps,pyUps,pzUps,eUps);
      TVector3 betaups=p4Labups.BoostVector();
      p4Dstar.Boost(-betaups);
      cosDstarCM=p4Dstar.CosTheta();
      
      
      //define Ks info
      mymassKs=massKs[i_D0Ks];
      Float_t mypKs=pKs[i_D0Ks];
      pxKs=mypKs*sin(thKs[i_D0Ks])*cos(phiKs[i_D0Ks]);
      pyKs=mypKs*sin(thKs[i_D0Ks])*sin(phiKs[i_D0Ks]);
      pzKs=mypKs*cos(thKs[i_D0Ks]);
      TVector3 PKs(pxKs,pyKs,pzKs);
      myxKs=xKs[i_D0Ks];
      myyKs=yKs[i_D0Ks];
      myzKs=zKs[i_D0Ks];
      TVector3 VKs(myxKs,myyKs,myzKs);
      Float_t A_Ks = Alpha(VD0,VKs,PKs);
      cosKs = cos(A_Ks);
      mychi2Ks=chi2Ks[i_D0Ks];
      mydofKs=dofKs[i_D0Ks];
      indexMcKs=MCKs[i_D0Ks]-1;
      //indexMcKs = isMcKs? mothMc[indexMcD0KsPi1]-1 : -999 ;
      
      //define KsPi1 track info
      Float_t pKsPi1=momentumTrk[i_D0KsPi1];
      pxKsPi1=pKsPi1*sin(thetaTrk[i_D0KsPi1])*cos(phiTrk[i_D0KsPi1]);
      pyKsPi1=pKsPi1*sin(thetaTrk[i_D0KsPi1])*sin(phiTrk[i_D0KsPi1]);
      pzKsPi1=pKsPi1*cos(thetaTrk[i_D0KsPi1]);
      kaonidKsPi1=kaonIdTrk[i_D0KsPi1];
      ndchKsPi1=ndchTrk[i_D0KsPi1];
      lundMcKsPi1=idTrk[i_D0KsPi1];
      lundKsPi1=d1KsLund[i_D0Ks];
      indexMcD0KsPi1=IndexTrk[i_D0KsPi1]-1;
      effCorMcD0KsPi1 = (!_isData)? effCorTrk[i_D0KsPi1]-1 : -999;
      sEffCorMcD0KsPi1 = (!_isData)? sEffCorTrk[i_D0KsPi1]-1 : -999;
      
      //define KsPi2 track info
      Float_t pKsPi2=momentumTrk[i_D0KsPi2];
      pxKsPi2=pKsPi2*sin(thetaTrk[i_D0KsPi2])*cos(phiTrk[i_D0KsPi2]);
      pyKsPi2=pKsPi2*sin(thetaTrk[i_D0KsPi2])*sin(phiTrk[i_D0KsPi2]);
      pzKsPi2=pKsPi2*cos(thetaTrk[i_D0KsPi2]);
      kaonidKsPi2=kaonIdTrk[i_D0KsPi2];
      ndchKsPi2=ndchTrk[i_D0KsPi2];
      lundKsPi2=d2KsLund[i_D0Ks];
      lundMcKsPi2=idTrk[i_D0KsPi2];
      indexMcD0KsPi2=IndexTrk[i_D0KsPi2]-1;
      effCorMcD0KsPi2 = (!_isData)? effCorTrk[i_D0KsPi2]-1 : -999;
      sEffCorMcD0KsPi2 = (!_isData)? sEffCorTrk[i_D0KsPi2]-1 : -999;
      
      //define D0Pi1 track info
      Float_t pD0Pi1=momentumTrk[i_D0Pi1];
      pxD0Pi1=pD0Pi1*sin(thetaTrk[i_D0Pi1])*cos(phiTrk[i_D0Pi1]);
      pyD0Pi1=pD0Pi1*sin(thetaTrk[i_D0Pi1])*sin(phiTrk[i_D0Pi1]);
      pzD0Pi1=pD0Pi1*cos(thetaTrk[i_D0Pi1]);
      kaonidD0Pi1=kaonIdTrk[i_D0Pi1];
      ndchD0Pi1=ndchTrk[i_D0Pi1];
      lundMcD0Pi1=idTrk[i_D0Pi1];
      if (d1D0Lund[i_D0]==310) {
	assert( (abs(d2D0Lund[i_D0])==lundD0Trk) && (abs(d3D0Lund[i_D0])==lundD0Trk) ); 
	lundD0Pi1=d2D0Lund[i_D0];
      } else {
	assert( (abs(d1D0Lund[i_D0])==lundD0Trk) && (abs(d2D0Lund[i_D0])==lundD0Trk) ); 
	lundD0Pi1=d1D0Lund[i_D0];
      }
      indexMcD0Pi1=IndexTrk[i_D0Pi1]-1;
      effCorMcD0Pi1 = (!_isData)? effCorTrk[i_D0Pi1]-1 : -999;
      sEffCorMcD0Pi1 = (!_isData)? sEffCorTrk[i_D0Pi1]-1 : -999;
      
      //define D0Pi2 track info
      Float_t pD0Pi2=momentumTrk[i_D0Pi2];
      pxD0Pi2=pD0Pi2*sin(thetaTrk[i_D0Pi2])*cos(phiTrk[i_D0Pi2]);
      pyD0Pi2=pD0Pi2*sin(thetaTrk[i_D0Pi2])*sin(phiTrk[i_D0Pi2]);
      pzD0Pi2=pD0Pi2*cos(thetaTrk[i_D0Pi2]);
      kaonidD0Pi2=kaonIdTrk[i_D0Pi2];
      ndchD0Pi2=ndchTrk[i_D0Pi2];
      if (d1D0Lund[i_D0]==310) {
	lundD0Pi2=d3D0Lund[i_D0];
      } else {
	lundD0Pi2=d2D0Lund[i_D0];
      }
      lundMcD0Pi2=idTrk[i_D0Pi2]; 
      indexMcD0Pi2=IndexTrk[i_D0Pi2]-1;
      effCorMcD0Pi2 = (!_isData)? effCorTrk[i_D0Pi2]-1 : -999;
      sEffCorMcD0Pi2 = (!_isData)? sEffCorTrk[i_D0Pi2]-1 : -999;
      
      //	cout<<"after all info"<<endl;
      
      // calculate isMc
      isMcD0 = isD0true(lundD0Trk,indexMcD0Pi1,indexMcD0Pi2,indexMcD0KsPi1,indexMcD0KsPi2); 
      isMcKs = isKstrue(indexMcD0KsPi1,indexMcD0KsPi2);
      
      
      //mydeltaMDstarBS=deltaMDstarBS[i];
      deltamDstarmD0=mymassDstar-mymassD0;
      deltamDstarmD0BS=mymassDstarBS-mymassD0;

      
      //cout<<"isMcD0= "<<isMcD0<<endl;
      
      //	cout<< "before calculate mes"<<endl;
      // if(mym2pDalitzD0<3.2335 && mym2pDalitzD0>3.2333 && mym2mDalitzD0<1.3070 && mym2mDalitzD0>1.3068)// continue;
      //apply preliminary selection cut
      //   if (fabs(deltamDstarmD0-0.14212)<=0.011 && fabs(mymassD0-1.8645)<0.035)
	// && abs(mym0D0-1.8645)<0.035&&  	  
	// && abs(mymassD0-1.8645)<0.035&&  	  
      //	{
	  // cout<<"mes="<<mes<<endl;
	  Tdelta->Fill(mydeltaMDstarBS);
	  TdeltaBS->Fill(deltamDstarmD0BS);
	  Tmassd0->Fill(mymassD0);
	  Tdalitz->Fill(mym2pDalitzD0,mym2mDalitzD0);
	  Tdalitz_qp->Fill(mym2pDalitzD0);
	  Tdalitz_qm->Fill(mym2mDalitzD0);
	  Tdalitz_qz->Fill(mym2zDalitzD0);
	  Tpd0->Fill(mypD0);
	  Tpcmsd0->Fill(pcmsD0);
	  
	  //  cout<<" IndexTrk[i_D0KsPi1]="<<IndexTrk[i_D0KsPi1] <<endl;
	  // if (indexMcD0KsPi1>=0){
	  // Treso->Fill(pKsPi1-pMc[indexMcD0KsPi1]);
	  // }
	  //fill tree with selected event
	  tree->Fill();
	  //	}
    }//end nChB for loop
  }//end jentry for loop
  
  cControl->Divide(3,3);
  cControl->cd(1);
  Tdelta->Draw();
  cControl->cd(2);
  TdeltaBS->Draw();
  cControl->cd(3); 
  Tpcmsd0->Draw();
  cControl->cd(4);
  Tmassd0->Draw();
  cControl->cd(5); 
  Tdalitz->Draw("BOX");
  cControl->cd(6); 
  Tdalitz_qp->Draw();
  cControl->cd(7); 
  Tdalitz_qm->Draw();
  cControl->cd(8); 
  Tdalitz_qz->Draw();
  TString namehist = "HIST/inclDstar_"+_d0mode+"_"+_sig_type+"_";
  namehist+="inclusiveDstar.ps";
  cControl->Print(namehist);
  
  hfile->Write();
    
  //stop timer
  timer.Stop();
  Double_t realtime=timer.RealTime();
  Double_t cputime=timer.CpuTime();
  cout<<"Real time = "<<realtime<<endl<<"CPU time = "<<cputime<<endl;
}//end Loop



Bool_t inclDstar::isDstartoD0Pi(Int_t lundD0Trk,Int_t Dlund,Int_t Pilund,Int_t i){
  // cout<<"going to isBtoDK"<<endl;
  //  cout<<"Dlund"<<Dlund<<endl;
  assert(Dlund==421);
  assert(lundD0Trk==211 || lundD0Trk==321);
  
  Int_t i_D0 = d1DstarIndex[i]-1;
  //Int_t i_Pi = d2DstarIndex[i]-1;
  if (i_D0>=nD0) return false; 
  
  Bool_t out=true;
  
  // cout<<"d1ChBLund["<<i<<"] = "<<d1D0Lund[i]<<endl;

  // check the Dstar
  out=out&&(abs(d1DstarLund[i])==Dlund);
  out=out&&(abs(d2DstarLund[i])==Pilund);
  out=out&&(ndauDstar[i]==2); 
  //if(ndauChB[i]==2) {cout<<"ndauchb="<<ndauChB[i]<<endl;}
  //  cout<<"out ="<<out<<endl;
  if (!out) return out;

  // check the D0
  out=out&&(ndauD0[i_D0]==3);
  out=out&& ( ((abs(d1D0Lund[i_D0])==310) && (abs(d2D0Lund[i_D0])==lundD0Trk) && (abs(d3D0Lund[i_D0])==lundD0Trk)) ||
	      ((abs(d3D0Lund[i_D0])==310) && (abs(d1D0Lund[i_D0])==lundD0Trk) && (abs(d2D0Lund[i_D0])==lundD0Trk)) );

  //cout<<"d1D0Lund["<<i_D0<<"] = "<<d1D0Lund[i_D0]<<endl;
  //cout<<"d2D0Lund["<<i_D0<<"] = "<<d2D0Lund[i_D0]<< "    "<<"lundD0Trk= "<<lundD0Trk<<endl;
  //cout<<"d3D0Lund["<<i_D0<<"] = "<<d3D0Lund[i_D0]<< "    "<<"lundD0Trk= "<<lundD0Trk<<endl;

  return out;

}//end isDstartoD0Pi



Int_t inclDstar::isSignalEvt(Int_t lundD0Trk,Int_t Dlund,Int_t i_Dstar,Bool_t& isResonantD0){
  //  cout<<"enter in isSignalEvt"<<endl;
  assert(Dlund==421);
  assert(lundD0Trk==321 || lundD0Trk==211);

  Int_t out=0;
  Int_t* Dstardau=new Int_t[30];//Dstar dau's
  Int_t* D0dau=new Int_t[30];//D0 dau's
  Int_t* D0k0dau=new Int_t[30];//K0 dau's
  Int_t* D0Ksdau=new Int_t[30];//Ks dau's 
  Int_t* D0resdau  =new Int_t[30]; //D0 res dau's (when the D0 decays to Ks + two body resonance)
  
  isResonantD0=kFALSE;

  // cout<<"Dlund = "<<Dlund<<endl;   
  if (_sig_type=="ccbar" || _sig_type=="signal" || _sig_type=="signalPHSP"||  _sig_type=="signalm" || _sig_type=="signalp"){
    
    for (Int_t i=0;i<nMc;i++){      // Loop on Mc-truth particles
      
      for (Int_t k=0;k<30;k++) Dstardau[k]=D0dau[k]=D0k0dau[k]=D0Ksdau[k]=D0resdau[k]=-9;
      //   cout<<"i nMc ="<<i<<"     nMc ="<<nMc<<endl;
      // cout<<"abs(idMc[i]) ="<<abs(idMc[i])<<endl;	     
      if (abs(idMc[i])==413){
	
	//Dstar's daughters
	giveMeDau(i,Dstardau);
	//	cout<<"Dstardau ="<<Dstardau[0]<<endl;
	if (Dstardau[0]==0) continue;
	//	cout<<"bdau..."<<endl; printInfo(bdau);

	//if (bdau[0]==2 &&  abs(idMc[bdau[1]])==421 && abs(idMc[bdau[2]])==211) {cout<<"bdau..."<<endl; printInfo(bdau);}
	
	// D0's daughters
	if (Dlund==421) giveMeDau(Dstardau,421,D0dau);
	if (D0dau[0]==0) continue;
	//   change ordering to have first K0/Ks, and 2nd and 3rd charged tracKs
	Int_t id1 = D0dau[1];
	Int_t id2 = D0dau[2];
	Int_t id3 = D0dau[3];
	//cout << id1 << " " << id2 << " " << id3 << endl;
	if (id1>=0 && id2>=0 && id3>=0) {
	  if ( (abs(idMc[id3])==311 || abs(idMc[id3])==310) && abs(idMc[id2])==lundD0Trk && abs(idMc[id1])==lundD0Trk) {
	    D0dau[1]=id3;
	    D0dau[2]=id1;
	    D0dau[3]=id2;
	  }
	}
	//if (D0dau[0]==3) {cout<<"D0dau ="<<D0dau[0]<<endl; printInfo(D0dau);}

	//   Ks's daugthers  (from K0)
	giveMeDau(D0dau,311,D0k0dau);
	if(D0k0dau[0]==0) giveMeDau(D0dau,310,D0Ksdau);
	else giveMeDau(D0k0dau,310,D0Ksdau);
	if(D0Ksdau[0]==0) continue;
	
	//cout<<"D0k0dau..."<<endl; printInfo(D0k0dau);
	//cout<<"D0Ksdau..."<<endl; printInfo(D0Ksdau);
	// get resonance (omega,phi) (from D0) daughters (if any)



	giveMeDau(D0dau,223,D0resdau); //omega
	if (D0resdau[0]==0) giveMeDau(D0dau,333,D0resdau); // phi
	//if (D0resdau[0]!=0) giveMeDau(D0dau,323,D0resdau); // K*-(892)
	//if (D0resdau[0]!=0) giveMeDau(D0dau,113,D0resdau); // rho0(770)
	if (D0resdau[0]!=0) isResonantD0=kTRUE;
	//if(D0resdau[0]!=0) cout<<"ALERT!!! Resonant event found"<<endl;
	//assert(!isResonantD0);
	
	  //{
	  //cout<<"D0resdau1 = "<<abs(idMc[D0resdau[1]])<<",  D0resdau2 = "<<abs(idMc[D0resdau[2]])<<endl;
	  //}
	//	cout<<"D0resdau..."<<endl; printInfo(D0resdau);
	//if (D0resdau[0]!=0 && _sig_type=="signalPHSP") continue;
	//if (bdau[0]==2 &&  abs(idMc[bdau[1]])==421 && abs(idMc[bdau[2]])==211) 
	//  {cout<<"bdau..."<<endl; printInfo(bdau); cout<<"D0dau..."<<endl; printInfo(D0dau); cout<<"D0Ksdau..."<<endl; printInfo(D0Ksdau);}
	

	//####################################################################
	//####################     Dstar condition     ###################
	//####################################################################  

	Bool_t truth = abs(idMc[Dstardau[1]])==421 && //D0 
	  (abs(idMc[Dstardau[2]])==211); 
	
	//no other Dstar's dau, apart from eventual Gamma
	truth = truth &&  (Dstardau[0]==2 || (Dstardau[0]==3 && idMc[Dstardau[3]]==22) || (Dstardau[0]==4 && idMc[Dstardau[3]]==22 && idMc[Dstardau[4]]==22));
	

	//D0 -> Ks lundTrk lundTrk 
	truth = truth &&  ( ( (D0dau[0]==3 || (D0dau[0]==4 && idMc[D0dau[4]]==22) || (D0dau[0]==5 && idMc[D0dau[4]]==22 && idMc[D0dau[5]]==22)) &&
			      D0Ksdau[0]>=2 && abs(idMc[D0Ksdau[1]])==211 && abs(idMc[D0Ksdau[2]])==211 &&  
			      abs(idMc[D0dau[2]])==lundD0Trk &&
			      abs(idMc[D0dau[3]])==lundD0Trk )
			    
			    ||  
			    
			    //D0 -> Ks res(lundTrk lundTrk) 
			    ( (D0dau[0]==2 || (D0dau[0]==3 && idMc[D0dau[3]]==22) || (D0dau[0]==4 && idMc[D0dau[3]]==22 && idMc[D0dau[4]]==22)) &&
			      D0Ksdau[0]>=2 && abs(idMc[D0Ksdau[1]])==211 && abs(idMc[D0Ksdau[2]])==211 &&
			      (D0resdau[0]==2 || (D0resdau[0]==3 && D0resdau[3]==22)) &&
			      abs(idMc[D0resdau[1]])==lundD0Trk &&
			      abs(idMc[D0resdau[2]])==lundD0Trk ) );
	
	if (truth) {
	  
	  if (D0resdau[0]==2 || (D0resdau[0]==3 && idMc[D0resdau[3]]==22) ) 
	    { 
	      //cout << "ATTENTION: resonance (omega/phi/Kstar-/rho0) from D0 decay found..." << endl; printInfo(D0resdau); 
	    }
	  
	  //if (abs(idMc[bdau[2]])==321) out = 1;
	  out = 1;
	  //if (abs(idMc[Dstardau[2]])==211) out = 1;
	  //cout << "ATTENTION: Signal event was found" << endl;
	  //cout << idMc[bdau[2]] << " " << out << endl;

	  if ( (Dstardau[0]>=3 && idMc[Dstardau[3]]==22 ) || 
	       (D0dau[0]>=4 && idMc[D0dau[4]]==22 ) || 
	       (D0resdau[0]>=3 && idMc[D0resdau[3]]==22 ) ||
	       (D0k0dau[0]>=2 && idMc[D0k0dau[2]]==22 ) ||
	       (D0Ksdau[0]>=3 && idMc[D0Ksdau[3]]==22 ) ){
	    
	    //if (abs(idMc[bdau[2]])==321) out=2;   // A Radiative decay somewhere
	    out=2;  // A Radiative decay somewhere
	    //if (abs(idMc[Dstardau[2]])==211) out = 2;
	    
	    //cout << "ATTENTION: Radiative decay in isSignalEvt. Event = " << event << endl; 
	  }
	        	  
	  break;
	  //the search is completed
	  
	} // else { for (Int_t k=0;k<30;k++) bdau[k]=Dstar0dau[k]=D0dau[k]=Pi0dau[k]=D0k0dau[k]=D0Ksdau[k]=D0resdau[k]=-9; }
	
      }//end idMc==413
    }//end for nMc   
    
      
    // Reco particles
    // cout<<"reco particles"<<endl;
    // cout<<"i_chb ="<<i_chb<<endl;	   

    Int_t i_D0 = d1DstarIndex[i_Dstar]-1 ;
    Int_t i_Pi = d2DstarIndex[i_Dstar]-1;

    // cout<<"d1D0Index ="<<d1D0Index[50]<<endl;
      
    Int_t i_D0Ks,i_D0Pi1,i_D0Pi2;
    if (d1D0Lund[i_D0]==310) {
      assert( (abs(d2D0Lund[i_D0])==lundD0Trk) && (abs(d3D0Lund[i_D0])==lundD0Trk) ); 
      i_D0Ks=d1D0Index[i_D0]-1;
      i_D0Pi1=d2D0Index[i_D0]-1;
      i_D0Pi2=d3D0Index[i_D0]-1;
    } else {
      assert( (abs(d1D0Lund[i_D0])==lundD0Trk) && (abs(d2D0Lund[i_D0])==lundD0Trk) ); 
      i_D0Ks=d3D0Index[i_D0]-1;
      i_D0Pi1=d1D0Index[i_D0]-1;
      i_D0Pi2=d2D0Index[i_D0]-1;
    }
    Int_t i_D0KsPi1=d1KsIndex[i_D0Ks]-1;
    // cout<<"i_D0KsPi1 ="<<i_D0KsPi1<<endl;
    // cout<<"i_D0KsPi1 ="<<d1KsIndex[51]<<endl;
    Int_t i_D0KsPi2=d2KsIndex[i_D0Ks]-1;
    // cout<<"i_D0KsPi2 ="<<i_D0KsPi2<<endl;
    
    Int_t indexMcPi=(i_Pi >=0) ? IndexTrk[i_Pi]-1 : -999;
    Int_t indexMcD0Pi1=(i_D0Pi1 >=0) ? IndexTrk[i_D0Pi1]-1 : -999;
    Int_t indexMcD0Pi2=(i_D0Pi2 >=0) ? IndexTrk[i_D0Pi2]-1 : -999;
    
    Int_t indexMcD0KsPi1=(i_D0KsPi1 >=0) ? IndexTrk[i_D0KsPi1]-1 : -999;
    Int_t indexMcD0KsPi2=(i_D0KsPi2 >=0) ? IndexTrk[i_D0KsPi2]-1 : -999;
    
 
    // match pion track    
    if (indexMcPi==Dstardau[2] || indexMcPi==Dstardau[1]) out+=4; 

  
    //match D0    
    if ( indexMcD0Pi1==D0dau[2] || indexMcD0Pi1==D0dau[3] || indexMcD0Pi1==D0resdau[1] || indexMcD0Pi1==D0resdau[2])  {
      //cout << "indexMcD0Pi1 = " << indexMcD0Pi1 << endl;
      //cout << "D0dau[1] = " << D0dau[1] << endl;
      //cout << "D0dau[2] = " << D0dau[2] << endl;
      out+=256;  //pi from D0
      //cout << "out+ = 256 "<<endl;
    }
    if ( indexMcD0Pi2==D0dau[3] || indexMcD0Pi2==D0dau[2] || indexMcD0Pi2==D0resdau[2] || indexMcD0Pi2==D0resdau[1] )  {
      //cout << "indexMcD0Pi2 = " << indexMcD0Pi2 << endl;
      //cout << "D0dau[1] = " << D0dau[1] << endl;
      //cout << "D0dau[2] = " << D0dau[2] << endl;
      out+=512;  //pi from D0
      //cout << "out+ = 512 "<<endl;
    }
   
    if ( (indexMcD0KsPi1==D0Ksdau[1]) || (indexMcD0KsPi1==D0Ksdau[2])) out+=1024; //pi dal K0
    if ( (indexMcD0KsPi2==D0Ksdau[2]) || (indexMcD0KsPi2==D0Ksdau[1]) ) out+=2048; //pi dal K0
    
    
    //**********************************************************************************************
    //****************************BIT MAP***********************************************************
    //**********************************************************************************************
  
    
    //full match D*->D0pi+: 1+4+256+512+1024+2048=3845
    //full match (brem) : 2+4+256+512+1024+2048=3846
    
    //D0 match:  1+256+512+1024+2048=3841
    //D0 match (brem): 2+256+512+1024+2048=3842

    //K0 match (from D0): 1+1024+2048=3073
    //K0 match (from D0) (brem): 2+1024+2048=3074

    //pi match: 1+4=5
    //pi match (brem): 2+4=6

    
  }//end if Dstar or signal
  
  delete[] Dstardau;
  delete[] D0dau;
  delete[] D0k0dau;
  delete[] D0Ksdau;
  delete[] D0resdau;

  //  cout<<"exit from isSignalEvt"<<endl;
  // cout <<"out = " << out << endl;
  return out; 
  
}//end isSignalEvt



void inclDstar::giveMeDau(Int_t index,Int_t* dauarray){
  Int_t ndau=0;
  if (index>=0) {
    for (Int_t j=0;j<nMc;j++){
      if ((mothMc[j]-1)==index){ 
	dauarray[++ndau]=j; 
      }
    }
  }
  dauarray[0]=ndau;
  // ordering from higher to lower abs(lundId)
  for (Int_t j=1;j<=ndau;j++) {
    Int_t tmp=dauarray[j];
    Int_t j_max=j;
    for (Int_t k=j+1;k<=ndau;k++) if (abs(idMc[dauarray[j_max]])<abs(idMc[dauarray[k]])) j_max=k;
    dauarray[j]=dauarray[j_max];
    dauarray[j_max]=tmp;
  }
  return;
}//end giveMeDau


void inclDstar::giveMeDau(Int_t* motharray, Int_t id, Int_t* dauarray){
  Int_t j(1);
  while  ( j<=motharray[0] && abs(idMc[motharray[j]])!=abs(id) ) j++;
  if (j>motharray[0]) j=-1;
  Int_t index = (j<=motharray[0])? motharray[j] : -1;
  giveMeDau(index,dauarray);
}//end giveMeDau



void inclDstar::printInfo(Int_t* array){
  cout<<"array[0] = "<<array[0]<<endl;
  for (Int_t i=1;i<=array[0];i++) {
    cout<<"array["<<i<<"] = "<<array[i]<<" idMc[array["<<i<<"]] = "<<idMc[array[i]]<<endl;
  }
}//end printInfo



Int_t inclDstar::isD0true(Int_t lundD0Trk,Int_t iMc_D0Pi1,Int_t iMc_D0Pi2,Int_t iMc_KsPi1,Int_t iMc_KsPi2)
{
  //  cout<<"inside isD0true"<<endl;
  Int_t isD0=0;
  
  if (iMc_D0Pi1<0 || iMc_D0Pi2<0 || iMc_KsPi1<0 || iMc_KsPi2<0){
    // cout<<"WARNING: iMc_D0Pi1 = "<<iMc_D0Pi1<<" iMc_D0Pi2 = "<<iMc_D0Pi2<<" iMc_KsPi1 = "<<iMc_KsPi1<<" iMc_KsPi2 = "<<iMc_KsPi2<<endl;
    return 0;
  }
  
  if ( (abs(idMc[iMc_D0Pi1]) != lundD0Trk) || (abs(idMc[iMc_D0Pi2]) != lundD0Trk) ||  
       (abs(idMc[iMc_KsPi1]) != 211) || (abs(idMc[iMc_KsPi2]) != 211) ) return 0;
  
  if (mothMc[iMc_D0Pi1] != mothMc[iMc_D0Pi2]) return 0;
  if (mothMc[iMc_KsPi1] != mothMc[iMc_KsPi2]) return 0;
  
  if (abs(idMc[mothMc[iMc_D0Pi1]-1])!=421) return 0;
  if (abs(idMc[mothMc[iMc_KsPi1]-1])!=310) return 0;
  
  Int_t iMc_Ks=mothMc[iMc_KsPi1]-1;
  Int_t iMc_D0=mothMc[iMc_D0Pi1]-1;
  
  //if (_sig_type=="btdsk" && mothMc[iMc_Ks] != mothMc[iMc_D0Pi1] ) return 0;
  //if (_sig_type!="btdsk" && mothMc[mothMc[iMc_Ks]-1] != mothMc[iMc_D0Pi1]) return 0;
  
  Int_t* D0dau_true=new Int_t[30];//D0 dau's
  Int_t* D0Ksdau_true=new Int_t[30];//Ks dau's
  
  for (Int_t k=0;k<10;k++) D0dau_true[k]=D0Ksdau_true[k]=0;
  
  giveMeDau(iMc_D0,D0dau_true);
  giveMeDau(iMc_Ks,D0Ksdau_true); 
  
  if (  (((abs(idMc[D0dau_true[1]])==310 || abs(idMc[D0dau_true[1]])==311) &&
	  abs(idMc[D0dau_true[2]])==lundD0Trk && abs(idMc[D0dau_true[3]])==lundD0Trk) ||
	 ((abs(idMc[D0dau_true[3]])==310 || abs(idMc[D0dau_true[3]])==311) &&
	  abs(idMc[D0dau_true[1]])==lundD0Trk && abs(idMc[D0dau_true[2]])==lundD0Trk))  &&
	abs(idMc[D0Ksdau_true[1]])==211 && abs(idMc[D0Ksdau_true[2]])==211 )  { 
    if (D0dau_true[0]==3) isD0 = 1;
    else if ( (D0dau_true[0]==4 && idMc[D0dau_true[4]]==22) || (D0dau_true[0]==5 && idMc[D0dau_true[4]]==22 && idMc[D0dau_true[5]]==22) ) isD0 = 2;
    if ( (D0Ksdau_true[0]==3 && idMc[D0Ksdau_true[3]]==22) || (D0Ksdau_true[0]==4 && idMc[D0Ksdau_true[3]]==22 && idMc[D0Ksdau_true[4]]==22) ) isD0 += 4;   
  }
  
  delete[] D0dau_true;
  delete[] D0Ksdau_true;

  return isD0;
}//end isD0true


Int_t inclDstar::isKstrue(Int_t iMc_KsPi1,Int_t iMc_KsPi2)
{
  // the Mc truth particle indexes are the argument

  Int_t isKs=0;
  
  if (iMc_KsPi1<0 || iMc_KsPi2<0){

    //cout<<"WARNING: iMc_KsPi1 = "<<iMc_KsPi1<<" iMc_KsPi2 = "<<iMc_KsPi2<<endl;
    //cout<<"jentry = "<<myjentry<<" event = "<<event<<" runNumber = "<<runNumber<<endl;
    return 0; 
  }

  if (mothMc[iMc_KsPi1] != mothMc[iMc_KsPi2]) return 0;

  if (abs(idMc[mothMc[iMc_KsPi1]-1])!=310)   return 0; 

  Int_t iMc_Ks  =mothMc[iMc_KsPi1]-1;

  Int_t* Ksdau_true=new Int_t[30];//Ks dau's

  for (Int_t k=0;k<30;k++) Ksdau_true[k]=0;

  giveMeDau(iMc_Ks,Ksdau_true);
  
  if (abs(idMc[Ksdau_true[1]])==211       &&
      abs(idMc[Ksdau_true[2]])==211){
    
    if (Ksdau_true[0]==2)                           isKs =1;
    if ( (Ksdau_true[0]==3 && idMc[Ksdau_true[3]]==22) || (Ksdau_true[0]==4 && idMc[Ksdau_true[3]]==22 && idMc[Ksdau_true[4]]==22)) isKs =2;
  }
  //if (isKs>0) {cout << "isKs = " << isKs << endl; printInfo(Ksdau_true);}

  delete[] Ksdau_true;
  //  
  return isKs;
}//end isKstrue



Float_t inclDstar::Alpha(const TVector3 & P1,const TVector3 & P2,const TVector3 & Q)
{
  // returns the angle (in rad.) between the vector P1->P2 and Q
  Float_t out=-999;

  TVector3 P1P2;

  P1P2=P2-P1;

  if(P1P2.Mag2()==0) return out;
  if(Q.Mag2()==0)    return out;

  out = P1P2.Angle(Q);
  
  return out;

} // Alpha





















  
