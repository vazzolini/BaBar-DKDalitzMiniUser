#define btdkpi_cxx
//#include <stdlib.h> 
//#include <math.h>
#include "btdkpi.h"
#include "TH2.h"
#include "TStyle.h"
#include "TCanvas.h"
//#include "TVector3.h"


void btdkpi::Loop(Int_t nentries)
{

  //   In a ROOT session, you can do:
  //      Root > .L btdkpi.C
  //      Root > btdkpi t
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
  
  
  //start timer
  TStopwatch timer;
  timer.Start();
  // getchar();
  if (fChain == 0) return;
  
  //
  //define output root file
  //
  TString rootfile_name;
  if (_release=="analysis-51") 
    rootfile_name="./root/btdkpi_"+_d0mode+"_"+_sig_type+".root";  
  else  if (_release=="rel-24") 
    rootfile_name="./reduced/btdkpi_"+_d0mode+"_"+_sig_type+".root";  
  else if (_release=="analysis-32") 
    rootfile_name="./root/btdkpi_"+_d0mode+"_"+_sig_type+".root";  
  else if (_release=="analysis-30") 
    rootfile_name="./root/btdkpi_"+_d0mode+"_"+_sig_type+".root";  
  else if (_release=="analysis-26") 
    rootfile_name="./root/btdkpi_"+_d0mode+"_"+_sig_type+".root";  
  else 
    assert(0);
  
  TFile *hfile = new TFile(rootfile_name,"RECREATE","Reduced root file");
  Int_t contaoor=0;
  Int_t contaoor2=0;
  Int_t contaoor3=0;


  //define output tree with its branches
  for(Int_t Dentry=0;Dentry<=1;Dentry++){
    //for(Int_t Dentry=1;Dentry>=0;Dentry--){
    //cout<<"Dentry"<<Dentry<<endl;   
    Int_t Dlund = (Dentry==0)? 421 : 423 ; // D0 or D*0
    const char* name = (Dentry==0)? "D0" : "Dstar0";

    TTree *tree = new TTree(name,"Reduced ROOT tree"); 
              
    // getchar();
    
    //general info
    Int_t lundD0Trk(-999);
    if (_d0mode=="kspipi"){
      lundD0Trk=211;
    } else if (_d0mode=="kskk") {
      lundD0Trk=321;
    } else assert(0);
    //  cout<<"lundD0Trk ="<<lundD0Trk<<endl;  
    
    tree->Branch("event",&event,"event/I");
    tree->Branch("runNumber",&runNumber,"runNumber/F");
    tree->Branch("FoxWol2Neu",&FoxWol2Neu,"FoxWol2Neu/F");
    tree->Branch("lowerID", &lowerID, "lowerID/I");
    tree->Branch("upperID", &upperID, "upperID/I");
    tree->Branch("pxUps",&pxUps,"pxUps/F");
    tree->Branch("pyUps",&pyUps,"pyUps/F");
    tree->Branch("pzUps",&pzUps,"pzUps/F");
    tree->Branch("eUps", &eUps, "eUps/F");

    //Mc info
    Int_t McEvtType;

    tree->Branch("nMc",&nMc,"nMc/I");
    tree->Branch("idMc",idMc,"idMc[nMc]/I");
    tree->Branch("mothMc",mothMc,"mothMc[nMc]/I");
    tree->Branch("nDauMc",nDauMc,"nDauMc[nMc]/I");
    tree->Branch("pMc",pMc,"pMc[nMc]/F");
    tree->Branch("thetaMc",thetaMc,"thetaMc[nMc]/F");
    tree->Branch("phiMc",phiMc,"phiMc[nMc]/F");
    tree->Branch("McEvtType",&McEvtType,"McEvtType/I");
    //tree->Branch("nTrk",&nTrk,"nTrk/I"); // VIR
    //tree->Branch("IndexTrk",&IndexTrk,"IndexTrk[nMc]/I"); // VIR


    //ChB
    Float_t legendrep0,legendrep2,fisher,costhrust;
    Float_t demk,demk2,mes,pxChB,pyChB,pzChB,cosChBCM,mym0ChB,mymassChB;
    //Float_t demp;
    Float_t mychi2ChB,mydofChB,myxChB,myyChB,myzChB;
    Int_t indexMcChB;
    tree->Branch("demk",&demk,"demk/F");
    tree->Branch("demk2",&demk2,"demk2/F");//original deltaE in ntuples
    //tree->Branch("demp",&demp,"demp/F");
    tree->Branch("mes",&mes,"mes/F");
    tree->Branch("pxChB",&pxChB,"pxChB/F");
    tree->Branch("pyChB",&pyChB,"pyChB/F");
    tree->Branch("pzChB",&pzChB,"pzChB/F");
    tree->Branch("xChB",&myxChB,"xChB/F");
    tree->Branch("yChB",&myyChB,"yChB/F");
    tree->Branch("zChB",&myzChB,"zChB/F");
    tree->Branch("cosChBCM",&cosChBCM,"cosChBCM/F");
    tree->Branch("m0ChB",&mym0ChB,"m0ChB/F");
    tree->Branch("massChB",&mymassChB,"massChB/F");
    tree->Branch("chi2ChB",&mychi2ChB,"chi2ChB/F");
    tree->Branch("dofChB",&mydofChB,"dofChB/F");
    tree->Branch("indexMcChB",&indexMcChB,"indexMcChB/I");
    tree->Branch("legendrep0",&legendrep0,"legendrep0/F");
    tree->Branch("legendrep2",&legendrep2,"legendrep2/F");
    tree->Branch("fisher",&fisher,"fisher/F");
    tree->Branch("costhrust",&costhrust,"costhrust/F");

    //Dstar0
    Float_t mym0Dstar0,mymassDstar0,pxDstar0,pyDstar0,pzDstar0,eDstar0,mychi2Dstar0,mydofDstar0;
    Int_t indexMcDstar0,isMcDstar0Gam,isMcDstar0Pi0,flagD0Pi0;
    tree->Branch("m0Dstar0",&mym0Dstar0,"m0Dstar0/F");
    tree->Branch("massDstar0",&mymassDstar0,"massDstar0/F");
    tree->Branch("pxDstar0",&pxDstar0,"pxDstar0/F");
    tree->Branch("pyDstar0",&pyDstar0,"pyDstar0/F");
    tree->Branch("pzDstar0",&pzDstar0,"pzDstar0/F");
    tree->Branch("eDstar0",&eDstar0,"eDstar0/F");
    tree->Branch("chi2Dstar0",&mychi2Dstar0,"chi2Dstar0/F");
    tree->Branch("dofDstar0",&mydofDstar0,"dofDstar0/F");
    tree->Branch("flagD0Pi0",&flagD0Pi0,"flagD0Pi0/I");
    tree->Branch("indexMcDstar0",&indexMcDstar0,"indexMcDstar0/I");
    tree->Branch("isMcDstar0Gam",&isMcDstar0Gam,"isMcDstar0Gam/I");
    tree->Branch("isMcDstar0Pi0",&isMcDstar0Pi0,"isMcDstar0Pi0/I");

    //Dstar0 dau Pi0
    Float_t m0Dstar0Pi0,pxDstar0Pi0,pyDstar0Pi0,pzDstar0Pi0,eDstar0Pi0,chi2Dstar0Pi0,dofDstar0Pi0;
    Int_t indexMcDstar0Pi0;
    tree->Branch("m0Dstar0Pi0",&m0Dstar0Pi0,"m0Dstar0Pi0/F");
    tree->Branch("pxDstar0Pi0",&pxDstar0Pi0,"pxDstar0Pi0/F");
    tree->Branch("pyDstar0Pi0",&pyDstar0Pi0,"pyDstar0Pi0/F");
    tree->Branch("pzDstar0Pi0",&pzDstar0Pi0,"pzDstar0Pi0/F");
    tree->Branch("eDstar0Pi0",&eDstar0Pi0,"eDstar0Pi0/F");
    tree->Branch("chi2Dstar0Pi0",&chi2Dstar0Pi0,"chi2Dstar0Pi0/F");
    tree->Branch("dofDstar0Pi0",&dofDstar0Pi0,"dofDstar0Pi0/F");
    tree->Branch("indexMcDstar0Pi0",&indexMcDstar0Pi0,"indexMcDstar0Pi0/I");

    //Pi0 dau1 Pi0g1
    Float_t ecalDstar0Pi0g1,ecalxDstar0Pi0g1,ecalyDstar0Pi0g1,ecalzDstar0Pi0g1,pxDstar0Pi0g1,pyDstar0Pi0g1,pzDstar0Pi0g1,lmomDstar0Pi0g1,ncryDstar0Pi0g1;
    Int_t indexMcDstar0Pi0g1;
    tree->Branch("ecalDstar0Pi0g1",&ecalDstar0Pi0g1,"ecalDstar0Pi0g1/F");
    tree->Branch("ecalxDstar0Pi0g1",&ecalxDstar0Pi0g1,"ecalxDstar0Pi0g1/F");
    tree->Branch("ecalyDstar0Pi0g1",&ecalyDstar0Pi0g1,"ecalyDstar0Pi0g1/F");
    tree->Branch("ecalzDstar0Pi0g1",&ecalzDstar0Pi0g1,"ecalzDstar0Pi0g1/F");
    tree->Branch("pxDstar0Pi0g1",&pxDstar0Pi0g1,"pxDstar0Pi0g1/F");
    tree->Branch("pyDstar0Pi0g1",&pyDstar0Pi0g1,"pyDstar0Pi0g1/F");
    tree->Branch("pzDstar0Pi0g1",&pzDstar0Pi0g1,"pzyDstar0Pi0g1/F");
    tree->Branch("lmomDstar0Pi0g1",&lmomDstar0Pi0g1,"lmomDstar0Pi0g1/F");
    tree->Branch("ncryDstar0Pi0g1",&ncryDstar0Pi0g1,"ncryDstar0Pi0g1/I");
    tree->Branch("indexMcDstar0Pi0g1",&indexMcDstar0Pi0g1,"indexMcDstar0Pi0g1/I");

    //Pi0 dau2 Pi0g2
    Float_t ecalDstar0Pi0g2,ecalxDstar0Pi0g2,ecalyDstar0Pi0g2,ecalzDstar0Pi0g2,pxDstar0Pi0g2,pyDstar0Pi0g2,pzDstar0Pi0g2,lmomDstar0Pi0g2,ncryDstar0Pi0g2;
    Int_t indexMcDstar0Pi0g2;
    tree->Branch("ecalDstar0Pi0g2",&ecalDstar0Pi0g2,"ecalDstar0Pi0g2/F");
    tree->Branch("ecalxDstar0Pi0g2",&ecalxDstar0Pi0g2,"ecalxDstar0Pi0g2/F");
    tree->Branch("ecalyDstar0Pi0g2",&ecalyDstar0Pi0g2,"ecalyDstar0Pi0g2/F");
    tree->Branch("ecalzDstar0Pi0g2",&ecalzDstar0Pi0g2,"ecalzDstar0Pi0g2/F");
    tree->Branch("pxDstar0Pi0g2",&pxDstar0Pi0g2,"pxDstar0Pi0g2/F");
    tree->Branch("pyDstar0Pi0g2",&pyDstar0Pi0g2,"pyDstar0Pi0g2/F");
    tree->Branch("pzDstar0Pi0g2",&pzDstar0Pi0g2,"pzyDstar0Pi0g2/F");
    tree->Branch("lmomDstar0Pi0g2",&lmomDstar0Pi0g2,"lmomDstar0Pi0g2/F");
    tree->Branch("ncryDstar0Pi0g2",&ncryDstar0Pi0g2,"ncryDstar0Pi0g2/I");
    tree->Branch("indexMcDstar0Pi0g2",&indexMcDstar0Pi0g2,"indexMcDstar0Pi0g2/I");

    //Dstar0 dau Gam
    Float_t ecalDstar0Gam,ecalxDstar0Gam,ecalyDstar0Gam,ecalzDstar0Gam,pxDstar0Gam,pyDstar0Gam,pzDstar0Gam,lmomDstar0Gam,ncryDstar0Gam;
    Int_t indexMcDstar0Gam;
    tree->Branch("ecalDstar0Gam",&ecalDstar0Gam,"ecalDstar0Gam/F");
    tree->Branch("ecalxDstar0Gam",&ecalxDstar0Gam,"ecalxDstar0Gam/F");
    tree->Branch("ecalyDstar0Gam",&ecalyDstar0Gam,"ecalyDstar0Gam/F");
    tree->Branch("ecalzDstar0Gam",&ecalzDstar0Gam,"ecalzDstar0Gam/F");
    tree->Branch("pxDstar0Gam",&pxDstar0Gam,"pxDstar0Gam/F");
    tree->Branch("pyDstar0Gam",&pyDstar0Gam,"pyDstar0Gam/F");
    tree->Branch("pzDstar0Gam",&pzDstar0Gam,"pzyDstar0Gam/F");
    tree->Branch("lmomDstar0Gam",&lmomDstar0Gam,"lmomDstar0Gam/F");
    tree->Branch("ncryDstar0Gam",&ncryDstar0Gam,"ncryDstar0Gam/I");
    tree->Branch("indexMcDstar0Gam",&indexMcDstar0Gam,"indexMcDstar0Gam/I");

    //D0
    Float_t mym0D0,mymassD0,pxD0,pyD0,pzD0,eD0,pcmsD0,mychi2D0,mydofD0,myxD0,myyD0,myzD0;
    Float_t mym2pDalitzD0,mym2mDalitzD0,mym2zDalitzD0,mymTotDalitzD0,mychi2DalitzD0;
    Int_t mystDalitzD0,mydofDalitzD0;
    Int_t indexMcD0,isMcD0,isMcD0Matched;
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
    tree->Branch("isMcD0Matched",&isMcD0Matched,"isMcD0Matched/I");
    tree->Branch("m2pDalitzD0", &mym2pDalitzD0, "m2pDalitzD0/F");
    tree->Branch("m2mDalitzD0", &mym2mDalitzD0, "m2mDalitzD0/F");
    tree->Branch("m2zDalitzD0", &mym2zDalitzD0, "m2zDalitzD0/F");
    tree->Branch("stDalitzD0", &mystDalitzD0, "stDalitzD0/I");
    tree->Branch("mTotDalitzD0", &mymTotDalitzD0, "mTotDalitzD0/F");
    tree->Branch("chi2DalitzD0", &mychi2DalitzD0, "chi2DalitzD0/F");
    tree->Branch("dofDalitzD0", &mydofDalitzD0, "dofDalitzD0/I");
	 
    //pr
    Float_t pxpr,pypr,pzpr,cthepr,deltadrcmompr;
    Int_t lundpr,kaonidpr,ndchpr,nphotpr,lundMcpr,indexMcpr;
    Float_t effCorMcpr,sEffCorMcpr;
    tree->Branch("pxpr",&pxpr,"pxpr/F");
    tree->Branch("pypr",&pypr,"pypr/F");
    tree->Branch("pzpr",&pzpr,"pzpr/F");
    tree->Branch("cthepr",&cthepr,"cthepr/F");
    tree->Branch("deltadrcmompr",&deltadrcmompr,"deltadrcmompr/F");
    tree->Branch("lundpr",&lundpr,"lundpr/I");
    tree->Branch("kaonidpr",&kaonidpr,"kaonidpr/I");
    tree->Branch("ndchpr",&ndchpr,"ndchpr/I");
    tree->Branch("nphotpr",&nphotpr,"nphotpr/I");
    tree->Branch("lundMcpr",&lundMcpr,"lundMcpr/I");
    tree->Branch("indexMcpr",&indexMcpr,"indexMcpr/I");
    tree->Branch("effCorMcpr",&effCorMcpr,"effCorMcpr/F");
    tree->Branch("sEffCorMcpr",&sEffCorMcpr,"sEffCorMcpr/F");

    //Ks (from D0)
    Float_t mydecayLengthD0, mydecayLengthCovD0;
    Float_t mymassKs,pxKs,pyKs,pzKs,myxKs,myyKs,myzKs,mychi2Ks,cosKs;
    Int_t mydofKs,indexMcKs;
    Int_t isMcKs;       
    tree->Branch("mydecayLengthCovD0",&mydecayLengthCovD0,"mydecayLengthCovD0/F");
    tree->Branch("decayLengthD0",&mydecayLengthD0,"decayLengthD0/F");
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
    TH1F* Tmes=new TH1F("Tmes","mES",60,5.200,5.300);
    TH1F* Tde=new TH1F("Tde","deltaE",60,-0.300,0.300);
    TH1F* Tde_orig=new TH1F("Tde_orig","Original DeltaE",60,-0.300,0.300);
    TH1F* Tm0d0=new TH1F("Tm0d0","m0D0",60,1.770,1.970);
    TH1F* Tmassd0=new TH1F("Tmassd0","massD0",60,1.770,1.970);
    TH1F* Treso=new TH1F("Treso","reso",60,-0.1,0.1);
    TH2F* Tdalitz = new TH2F("Tdalitz","Dalitz plot q+:q-",100,0,4.,100,0,4.);
    TH1F* Tdalitz_qp = new TH1F("Tdalitz_qp","Dalitz plot q+",100,0,4.);
    TH1F* Tdalitz_qm = new TH1F("Tdalitz_qm","Dalitz plot q-",100,0,4.);
    TH1F* Tdalitz_qz = new TH1F("Tdalitz_qz","Dalitz plot q0",100,0,4.);
    TH1F* Tpd0 = new TH1F("Tpd0","pD0",60,0.,5.);
    TH1F* Tpcmsd0 = new TH1F("Tpcmsd0","pcmsD0",60,0.,5.);

    TCanvas* cControl = new TCanvas("cControl","Canvas Control",1);
    
    if (nentries<=0 || nentries>fChain->GetEntries()) nentries = Int_t(fChain->GetEntries());
    cout << "Outside Loop, nentries=" << nentries << endl;

    Int_t nbytes = 0; 
    Int_t nb = 0;



    for (Int_t jentry=0; jentry<nentries;jentry++) {

      Int_t ientry = LoadTree(jentry);

      if (ientry < 0) break;

      nb = fChain->GetEntry(jentry);  

   
      // cout << "Inside Loop, jentry=" << jentry << " Inside Loop, ientry=" << " nb=" << nb << endl;

      nbytes += nb;

      //cout << endl << "jentry = " << jentry << " ientry = " << ientry << " Event = " << event << " nChB = "   << nChB   << endl;
	   
      //if((_super_sig_type==TString("on"))&&abs(sqrt(eUps*eUps-pxUps*pxUps-pyUps*pyUps-pzUps*pzUps)-10.580)>0.010) continue; 
      // cout<<"m upsilon ="<<sqrt(eUps*eUps-pxUps*pxUps-pyUps*pyUps-pzUps*pzUps)<<endl;     
      //if((_super_sig_type==TString("off"))&&abs(sqrt(eUps*eUps-pxUps*pxUps-pyUps*pyUps-pzUps*pzUps)-10.580)<0.010) continue;
    

      //   cout<<"runNumber= "<<runNumber<<endl;


      for (Int_t i=0;i<nChB;i++){
	//	cout << "Inside Loop on nChB, i="   << i   << endl;

	if ( !isBtoDK(lundD0Trk,Dlund,211,i) && !isBtoDK(lundD0Trk,Dlund,321,i) ) continue;
	//	assert(0);
      	//cout<<"after isBtoDK"<<endl;
       
	McEvtType = 0;
	
	if (_super_sig_type=="chb" || _super_sig_type=="chbk" || _super_sig_type=="chbpi" ||  _super_sig_type=="ccbar" ||
	    _super_sig_type=="btdk" || _super_sig_type=="btdsk" || _super_sig_type=="btdpi" || _super_sig_type=="btdspi") {
	  
	  McEvtType =isSignalEvt(lundD0Trk,Dlund,i);

	  //	  cout << "isSignalEvt=" << McEvtType<< " jentry = " << jentry << endl;
	  //cout << _super_sig_type << endl;

 // 	  if( ( McEvtType & 3846 )== 3846 || ( McEvtType & 3845 )== 3845) contaoor++;
//  	  if( ( McEvtType & ( BIT_ON(1) + BIT_ON(2) +  BIT_ON(8) + BIT_ON(9) + BIT_ON(10) +  BIT_ON(11) ) )
// 	      ==( BIT_ON(1) + BIT_ON(2) +  BIT_ON(8) + BIT_ON(9) + BIT_ON(10) +  BIT_ON(11) ) || 
//  	      ( McEvtType & ( BIT_ON(0) + BIT_ON(2) +  BIT_ON(8) + BIT_ON(9) + BIT_ON(10) +  BIT_ON(11) ) )== (BIT_ON(0) + BIT_ON(2) +  BIT_ON(8) + BIT_ON(9) + BIT_ON(10) +  BIT_ON(11) ) ) contaoor2++;
//  	  if( ( McEvtType & ( BIT_ON(1) + BIT_ON(24) +  BIT_ON(8) + BIT_ON(9) + BIT_ON(10) +  BIT_ON(11) ) ) ==( BIT_ON(1) + BIT_ON(24) +  BIT_ON(8) + BIT_ON(9) + BIT_ON(10) +  BIT_ON(11) ) || 
//  	      ( McEvtType & ( BIT_ON(0) + BIT_ON(24) +  BIT_ON(8) + BIT_ON(9) + BIT_ON(10) +  BIT_ON(11) ) ) == ( BIT_ON(0) + BIT_ON(24) +  BIT_ON(8) + BIT_ON(9) + BIT_ON(10) +  BIT_ON(11) ) ) contaoor3++;
	  

	  //skip events dk,dpi signal (for Dlund=421) and dsk,dspi signal (for Dlund=423) from generic Bch (includes D0->Ks res(hh)
	  //generic B+B- background
	  if (_super_sig_type=="chb") {
	    if ( (McEvtType&1)==1 || (McEvtType&2)==2 || (McEvtType&8192)==8192 || (McEvtType&16384)==16384 ) {
	    
	      //	      cout << "ATTENTION: dk,dpi (dsk,dspi) signal event found in chb Mc (rejected). jentry = " << jentry 
	      // << " isSignalEvt= " << McEvtType << endl;
	       continue;
	    }
	  }
	 
	  
	  //skip events which are not dpi signal (for Dlund=421) and dspi signal (for Dlund=423) from generic Bch (includes D0->Ks res(hh)
	  //dpi background 
	  if (_super_sig_type=="chbpi") {
	    if ( (McEvtType&8192)==8192 || (McEvtType&16384)==16384 ) {
	      //cout << "ATTENTION: dpi (dspi) event found in chb Mc (accepted). jentry = " << jentry << " isSignalEvt= " << McEvtType << endl;
	    } else
	      continue;
	  }
	  
	  //skip events which are not dk signal (for Dlund=421) and dsk signal (for Dlund=423) from generic Bch (includes D0->Ks res(hh)
	  //dk background 
	  if (_super_sig_type=="chbk") {
	    if ( (McEvtType&1)==1 || (McEvtType&2)==2 ) {
	      cout << "ATTENTION: dk (dsk) event found in chb Mc (accepted). jentry = " << jentry << " isSignalEvt= " << McEvtType << endl;
	    } else
	      continue;
	  }
	  
	  
	  // skip events not consistent with signal type
	  if ( _super_sig_type=="btdk" ) {
	    if ( Dlund!=421 ) continue;
	    if (!( (McEvtType&1)==1 || (McEvtType&2)==2 )) {
	      //	      cout << "***************************  ATTENTION: dk,not signal event found in"<<endl;
	      contaoor++;		
	      continue;}	
	  }
	  if ( _super_sig_type=="btdsk" ) {
	    if ( Dlund!=423 ) continue;
	    if (!( (McEvtType&1)==1 || (McEvtType&2)==2 )) continue;
	  }
	  if ( _super_sig_type=="btdpi" ) {
	    if ( Dlund!=421 ) continue;
	    if (!( (McEvtType&8192)==8192 || (McEvtType&16384)==16384 )) continue;
	  }
	  if ( _super_sig_type=="btdspi" ) {
	    if ( Dlund!=423 ) continue;
	    if (!( (McEvtType&8192)==8192 || (McEvtType&16384)==16384 )) continue;
	  }

	}                    
	
	//define particle indexes
	Int_t i_Dstar0(-999),i_Dstar0d2,i_Pi0,i_Pi0g1,i_Pi0g2,i_g;
	Int_t i_pr;
	Int_t i_D0(-999),i_D0Ks,i_D0Pi1,i_D0Pi2,i_D0KsPi1,i_D0KsPi2;
	
	//define B dau
	//cout<<"d1ChBLund ="<<d1ChBLund[i]<<endl;
	if(Dlund==421){
	  i_D0=d1ChBIndex[i]-1;
	} else if(Dlund==423){
	  i_Dstar0=d1ChBIndex[i]-1;
	  i_D0=d1Dstar0Index[i_Dstar0]-1;
	  i_Dstar0d2=d2Dstar0Index[i_Dstar0]-1;
	}
	i_pr=d2ChBIndex[i]-1;
	
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

	//define Bch info
	Float_t mypChB=pChB[i];
	pxChB=mypChB*sin(thChB[i])*cos(phiChB[i]);
	pyChB=mypChB*sin(thChB[i])*sin(phiChB[i]);
	pzChB=mypChB*cos(thChB[i]);
	
	//see after for CM quantities
	
	mym0ChB=m0ChB[i];
	mymassChB=massChB[i];
	mychi2ChB=chi2ChB[i];
	mydofChB=dofChB[i];
	myxChB=xChB[i];
	myyChB=yChB[i];
	myzChB=zChB[i];
	TVector3 VBch(myxChB,myyChB,myzChB);//per a calcul de Alpha.
	
	indexMcChB=MCChB[i]-1;
	//indexMcChB = (indexMcDstar0>=0)? mothMc[indexMcDstar0]-1 : -999 ;
	legendrep0=LegendreP0ChB[i];
	legendrep2=LegendreP2ChB[i];
	fisher=FisherChB[i];
	costhrust=cosTBChB[i];

	//define D*0 info
	pxDstar0=-999;
	pyDstar0=-999;
	pzDstar0=-999;
	eDstar0=-999;
	mychi2Dstar0=-999;
	mydofDstar0=-999;
	mym0Dstar0=-999;
	mymassDstar0=-999;
	flagD0Pi0=-999;
	indexMcDstar0=-999;
	if(Dlund==423){
	  Float_t mypDstar0=pDstar0[i_Dstar0];
	  pxDstar0=mypDstar0*sin(thDstar0[i_Dstar0])*cos(phiDstar0[i_Dstar0]);
	  pyDstar0=mypDstar0*sin(thDstar0[i_Dstar0])*sin(phiDstar0[i_Dstar0]);
	  pzDstar0=mypDstar0*cos(thDstar0[i_Dstar0]);
	  eDstar0=sqrt(mypDstar0*mypDstar0+massDstar0[i_Dstar0]*massDstar0[i_Dstar0]);
	  mychi2Dstar0=chi2Dstar0[i_Dstar0];
	  mydofDstar0=dofDstar0[i_Dstar0];
	  mym0Dstar0=m0Dstar0[i_Dstar0];
	  mymassDstar0=massDstar0[i_Dstar0];
	  flagD0Pi0= (d2Dstar0Lund[i_Dstar0]==111) ? 1 : 0;        
	  // cout<< "flagD0Pi0 = "<< flagD0Pi0<<" d2Dstar0Lund["<<i_Dstar0<<"] = " << d2Dstar0Lund[i_Dstar0] <<endl;
	  indexMcDstar0=MCDstar0[i_Dstar0]-1;
	}

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
	
	//define Pi0 info 
	if(Dlund==423){	  
	  if (flagD0Pi0){
	    //  cout<<"inside flagD0Pi0"<<endl;
	    i_Pi0=(d2Dstar0Lund[i_Dstar0]==111) ? d2Dstar0Index[i_Dstar0]-1 : -999;
	    Float_t mypPi0=pPi0[i_Pi0];
	    pxDstar0Pi0=mypPi0*sin(thPi0[i_Pi0])*cos(phiPi0[i_Pi0]);
	    pyDstar0Pi0=mypPi0*sin(thPi0[i_Pi0])*sin(phiPi0[i_Pi0]);
	    pzDstar0Pi0=mypPi0*cos(thPi0[i_Pi0]);
	    eDstar0Pi0=sqrt(mypPi0*mypPi0+massPi0[i_Pi0]*massPi0[i_Pi0]);
	    chi2Dstar0Pi0=chi2Pi0[i_Pi0];
	    dofDstar0Pi0=dofPi0[i_Pi0];
	    m0Dstar0Pi0=m0Pi0[i_Pi0];
	    i_Pi0g1=d1Pi0Index[i_Pi0]-1; 
	    //	 cout << "i_Pi0g1 = "<< i_Pi0g1<<endl;
	    i_Pi0g2=d2Pi0Index[i_Pi0]-1;
	    //	 cout << "i_Pi0g2= "<< i_Pi0g2<<endl;
	    indexMcDstar0Pi0=MCPi0[i_Pi0]-1;
	    if (!_isData) {
	      indexMcDstar0Pi0g1=IndexGam[i_Pi0g1]-1;   //!_isData
	      indexMcDstar0Pi0g2=IndexGam[i_Pi0g2]-1;
	    }
	    //define Gamma g1 info
	    ecalDstar0Pi0g1=ecalGam[i_Pi0g1];
	    pxDstar0Pi0g1=ecalDstar0Pi0g1*sin(thetaGam[i_Pi0g1])*cos(phiGam[i_Pi0g1]);
	    pyDstar0Pi0g1=ecalDstar0Pi0g1*sin(thetaGam[i_Pi0g1])*sin(phiGam[i_Pi0g1]);
	    pzDstar0Pi0g1=ecalDstar0Pi0g1*cos(thetaGam[i_Pi0g1]);
	    ecalxDstar0Pi0g1=ecalXGam[i_Pi0g1];
	    ecalyDstar0Pi0g1=ecalYGam[i_Pi0g1];
	    ecalzDstar0Pi0g1=ecalZGam[i_Pi0g1];
	    lmomDstar0Pi0g1=lMomGam[i_Pi0g1];
	    ncryDstar0Pi0g1=nCryGam[i_Pi0g1];
	    //define Gamma g2 info
	    ecalDstar0Pi0g2=ecalGam[i_Pi0g2];
	    pxDstar0Pi0g2=ecalDstar0Pi0g2*sin(thetaGam[i_Pi0g2])*cos(phiGam[i_Pi0g2]);
	    pyDstar0Pi0g2=ecalDstar0Pi0g2*sin(thetaGam[i_Pi0g2])*sin(phiGam[i_Pi0g2]);
	    pzDstar0Pi0g2=ecalDstar0Pi0g2*cos(thetaGam[i_Pi0g2]);
	    ecalxDstar0Pi0g2=ecalXGam[i_Pi0g2];
	    ecalyDstar0Pi0g2=ecalYGam[i_Pi0g2];
	    ecalzDstar0Pi0g2=ecalZGam[i_Pi0g2];
	    lmomDstar0Pi0g2=lMomGam[i_Pi0g2];
	    ncryDstar0Pi0g2=nCryGam[i_Pi0g2];
	    //define Gamma default info
	    ecalDstar0Gam=-999;
	    ecalxDstar0Gam=-999;
	    ecalyDstar0Gam=-999;
	    ecalzDstar0Gam=-999;
	    pxDstar0Gam=-999;
	    pyDstar0Gam=-999;
	    pzDstar0Gam=-999;
	    lmomDstar0Gam=-999;
	    ncryDstar0Gam=-999;
	    i_g=-999;
	    indexMcDstar0Gam = -999;
	  } else {
	    //   cout<<"in else de flagD0pi"<<endl;
	    pxDstar0Pi0=-999;
	    pyDstar0Pi0=-999;
	    pzDstar0Pi0=-999;
	    eDstar0Pi0=-999;
	    chi2Dstar0Pi0=-999;
	    dofDstar0Pi0=-999;
	    m0Dstar0Pi0=-999;
	    i_Pi0=-999;
	    i_Pi0g1=-999;
	    i_Pi0g2=-999;
	    indexMcDstar0Pi0=-999;
	    //define default Pi0g1 info
	    ecalDstar0Pi0g1=-999;
	    ecalxDstar0Pi0g1=-999;
	    ecalyDstar0Pi0g1=-999;
	    ecalzDstar0Pi0g1=-999;
	    pxDstar0Pi0g1=-999;
	    pyDstar0Pi0g1=-999;
	    pzDstar0Pi0g1=-999;
	    lmomDstar0Pi0g1=-999;
	    ncryDstar0Pi0g1=-999;
	    indexMcDstar0Pi0g1=-999;  //!_isData
	    //define default Pi0g2 info
	    ecalDstar0Pi0g2=-999;
	    ecalxDstar0Pi0g2=-999;
	    ecalyDstar0Pi0g2=-999;
	    ecalzDstar0Pi0g2=-999;
	    pxDstar0Pi0g2=-999;
	    pyDstar0Pi0g2=-999;
	    pzDstar0Pi0g2=-999;
	    lmomDstar0Pi0g2=-999;
	    ncryDstar0Pi0g2=-999;
	    indexMcDstar0Pi0g2=-999;//!_isData
	    //define Gamma info
	    i_g=(d2Dstar0Lund[i_Dstar0]==22) ? d2Dstar0Index[i_Dstar0]-1 : -999;
	    ecalDstar0Gam=ecalGam[i_g];
	    ecalxDstar0Gam=ecalXGam[i_g];
	    ecalyDstar0Gam=ecalYGam[i_g];
	    ecalzDstar0Gam=ecalZGam[i_g];
	    pxDstar0Gam=ecalDstar0Gam*sin(thetaGam[i_g])*cos(phiGam[i_g]);
	    pyDstar0Gam=ecalDstar0Gam*sin(thetaGam[i_g])*sin(phiGam[i_g]);
	    pzDstar0Gam=ecalDstar0Gam*cos(thetaGam[i_g]);
	    lmomDstar0Gam=lMomGam[i_g];
	    ncryDstar0Gam=nCryGam[i_g];
	    indexMcDstar0Gam = (!_isData)? IndexGam[i_g]-1 : -999;
	  }
	}//end 423
	//		cout<<"after flagD0Pi0"<<endl;

	//define prompt track info
	Float_t ppr=momentumTrk[i_pr];
	pxpr=ppr*sin(thetaTrk[i_pr])*cos(phiTrk[i_pr]);
	pypr=ppr*sin(thetaTrk[i_pr])*sin(phiTrk[i_pr]);
	pzpr=ppr*cos(thetaTrk[i_pr]);
	kaonidpr=kaonIdTrk[i_pr];
	//	cout<<"kaonidpr ="<<kaonidpr<<endl;
	ndchpr=ndchTrk[i_pr];
	deltadrcmompr=deltadrcmomTrk[i_pr];
	lundpr=d2ChBLund[i];
	cthepr=cTheTrk[i_pr];
	nphotpr=nPhotTrk[i_pr];
	indexMcpr = (!_isData)? IndexTrk[i_pr]-1 : -999;
	effCorMcpr = (!_isData)? effCorTrk[i_pr]-1 : -999;
	sEffCorMcpr = (!_isData)? sEffCorTrk[i_pr]-1 : -999;

	// Calculate Bch CM quantities
	Float_t eChB(0.);
	Float_t mk=0.49368;
	if(Dlund==421){	
	  eChB =eD0 + sqrt(ppr*ppr+mk*mk);
	}else if(Dlund==423){
	  eChB =eDstar0 + sqrt(ppr*ppr+mk*mk);;
	}
	//	cout<<"eChB"<<eChB<<endl;
	TLorentzVector p4ChB(pxChB,pyChB,pzChB,eChB);
	TLorentzVector p4LabChB(p4ChB);
	TVector3 betaChB=p4ChB.BoostVector();
	TLorentzVector p4Labups(pxUps,pyUps,pzUps,eUps);
	TVector3 betaups=p4Labups.BoostVector();
	p4ChB.Boost(-betaups);
	cosChBCM=p4ChB.CosTheta();
	  

	//define Ks info
	mydecayLengthCovD0=decayLengthCovD0[i_D0Ks];
	mydecayLengthD0=decayLengthD0[i_D0Ks];
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
	Float_t A_Ks    = Alpha(VD0,VKs,PKs);
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

	//calculates generated and matched d0 (same bitmap)
	isMcD0Matched =isSignalEvt2(lundD0Trk,Dlund,i);
	//	cout   << " holaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa  isSignalEvt= " << isMcD0Matched  << endl;


	// calculate isMc
	isMcD0 = isD0true(lundD0Trk,indexMcD0Pi1,indexMcD0Pi2,indexMcD0KsPi1,indexMcD0KsPi2); 
	isMcKs = isKstrue(indexMcD0KsPi1,indexMcD0KsPi2);
	isMcDstar0Pi0 = 0;
	isMcDstar0Gam = 0;
	if(Dlund==423){
	  isMcDstar0Pi0=isDstar0D0Pi0true(indexMcD0Pi1,indexMcDstar0Pi0g1,indexMcDstar0Pi0g2);
	  isMcDstar0Gam=isDstar0D0Gamtrue(indexMcD0Pi1,indexMcDstar0Gam);
	}
	//cout<<"isMcD0= "<<isMcD0<<endl;

	//	cout<< "before calculate mes"<<endl;
	
	// //
	// 	//define demp,demk,mes
	// 	mk=0.49368;y
	// 	Float_t mpi=0.13957;
	// 	Float_t ebeam=sqrt(eUps*eUps-pxUps*pxUps-pyUps*pyUps-pzUps*pzUps)/2;
	// 	if(Dlund==421){
	// 	//demk=(2*( eUps*(eD0+sqrt(ppr*ppr+mk*mk))-pxUps*(pxD0+pxpr)-pyUps*(pyD0+pypr) -pzUps*(pzD0+pzpr))-4*ebeam*ebeam)/(4*ebeam);
	// 	demp=(2*( eUps*(eD0+sqrt(ppr*ppr+mpi*mpi))-pxUps*(pxD0+pxpr)-pyUps*(pyD0+pypr) -pzUps*(pzD0+pzpr))-4*ebeam*ebeam)/(4*ebeam);
	// 	} else if(Dlund==423){
	// 	//demk=(2*( eUps*(eDstar0+sqrt(ppr*ppr+mk*mk))-pxUps*(pxDstar0+pxpr)-pyUps*(pyDstar0+pypr)-pzUps*(pzDstar0+pzpr))-4*ebeam*ebeam)/(4*ebeam);
	// 	demp=(2*( eUps*(eDstar0+sqrt(ppr*ppr+mpi*mpi))-pxUps*(pxDstar0+pxpr)-pyUps*(pyDstar0+pypr)-pzUps*(pzDstar0+pzpr))-4*ebeam*ebeam)/(4*ebeam);
	// 	}
	// 	//mes=sqrt( pow((2*ebeam*ebeam+pxUps*pxChB+pyUps*pyChB+pzUps*pzChB),2)/(eUps*eUps)-mypChB*mypChB );
	// 	

	demk2=deltaeChB[i];  // Original DeltaE 
	
	// Using TLorentzVectors
	
	Float_t myDeltaE = DeltaE(p4Labups, p4LabChB);
	Float_t myMes    = Mes(p4Labups, p4LabChB);
	//cout<<"myDeltaE="<< myDeltaE<<endl;

	mes = myMes;
       	demk= myDeltaE;

	//
	//  cout << "mes       =" << mes      << endl;
	// cout << "myMes     =" << myMes    << endl;
	//	cout << "demk      =" << demk     << endl;
	// cout << "demk2     =" << demk2    << endl;
	// cout << "myDeltaE  =" << myDeltaE << endl;
	
	//	mes = myMes;
	//	demk= myDeltaE;
	
	//      cout << "event    =" << event     << endl;
	//      cout << "iChB     =" << i         << endl;
	//      cout << "McEvtType=" << McEvtType << endl;


	//apply preliminary selection cut
	if (demk2>-0.200 && demk2<0.200 &&
	    mes>5.200)
	  // && abs(mym0D0-1.8645)<0.035&&  	  
	  // && abs(mymassD0-1.8645)<0.035&&  	  
	  {
	    // cout<<"mes="<<mes<<endl;
	    Tmes->Fill(mes);
	    Tde->Fill(demk2);
	    Tde_orig->Fill(demk);
	    Tm0d0->Fill(mym0D0);
	    Tmassd0->Fill(mymassD0);
	    Tdalitz->Fill(mym2pDalitzD0,mym2mDalitzD0);
	    Tdalitz_qp->Fill(mym2pDalitzD0);
	    Tdalitz_qm->Fill(mym2mDalitzD0);
	    Tdalitz_qz->Fill(mym2zDalitzD0);
	    Tpd0->Fill(mypD0);
	    Tpcmsd0->Fill(pcmsD0);
	 
	    //  cout<<" IndexTrk[i_D0KsPi1]="<<IndexTrk[i_D0KsPi1] <<endl;
	    if (indexMcD0KsPi1>=0){
	      Treso->Fill(pKsPi1-pMc[indexMcD0KsPi1]);
	    }
	    //fill tree with selected event
	    tree->Fill();
	  }
      }//end nChB for loop
   //  cout<<"contaoooooooorr ="<<contaoor<<endl;
//     cout<<"contaoooooooorr2 ="<<contaoor2<<endl;
//     cout<<"contaoooooooorr3 ="<<contaoor3<<endl;

    }//end jentry for loop
  
    cControl->Divide(3,3);
    cControl->cd(1);
    Tmes->Draw();
    cControl->cd(2);
    Tde->Draw();
    cControl->cd(3); 
    Tde_orig->Draw();
    cControl->cd(4);
    //Tm0d0->Draw();
    //Tpd0->Draw();
    Tpcmsd0->Draw();
    cControl->cd(5);
    Tmassd0->Draw();
    cControl->cd(6); 
    //Treso->Draw();
    Tdalitz->Draw("BOX");
    cControl->cd(7); 
    Tdalitz_qp->Draw();
    cControl->cd(8); 
    Tdalitz_qm->Draw();
    cControl->cd(9); 
    Tdalitz_qz->Draw();
    TString namehist;
    if (_release=="analysis-51")  
      namehist = "HIST-51/btdkpi_"+_d0mode+"_"+_sig_type+"_"; // rel-51
    else if (_release=="rel-24")  
      namehist = "HIST-24/btdkpi_"+_d0mode+"_"+_sig_type+"_"; // rel-24
    else if (_release=="analysis-32")  
      namehist = "HIST-32/btdkpi_"+_d0mode+"_"+_sig_type+"_"; // rel-32
    else if (_release=="analysis-26")  
      namehist = "HIST/btdkpi_"+_d0mode+"_"+_sig_type+"_"; // rel-26
    else if (_release=="analysis-30")
      namehist = "HIST-30/btdkpi_"+_d0mode+"_"+_sig_type+"_"; // rel-30
    else if (_release=="analysis-50")
      namehist = "HIST-50/btdkpi_"+_d0mode+"_"+_sig_type+"_"; // rel-50
    else assert(0);

    if (Dlund==423) namehist+="Dstar0.ps"; else namehist+="D0.ps";
    cControl->Print(namehist);
 
    hfile->Write();
  
  }//end Dentry

  //stop timer
  timer.Stop();
  Double_t realtime=timer.RealTime();
  Double_t cputime=timer.CpuTime();
  cout<<"Real time = "<<realtime<<endl<<"CPU time = "<<cputime<<endl;
  cout<<"contaoooooooorr final="<<contaoor<<endl;
//   cout<<"contaoooooooorr final2="<<contaoor2<<endl;
//   cout<<"contaoooooooorr final3="<<contaoor3<<endl;

}//end Loop



Bool_t btdkpi::isBtoDK(Int_t lundD0Trk,Int_t Dlund,Int_t prlund,Int_t i){
  // cout<<"going to isBtoDK"<<endl;
  //  cout<<"Dlund"<<Dlund<<endl;
  assert(Dlund==421 || Dlund==423);
  assert(prlund==321 || prlund==211);
  assert(lundD0Trk==321 || lundD0Trk==211);

  Int_t i_Dstar0 = (Dlund==423)? d1ChBIndex[i]-1 : -999;
  Int_t i_D0 = (Dlund==423)? d1Dstar0Index[i_Dstar0]-1 : d1ChBIndex[i]-1 ;
  if (i_Dstar0>=nDstar0 || i_D0>=nD0) return false; 
  
  Bool_t out=true;
  
  // cout<<"d1ChBLund["<<i<<"] = "<<d1D0Lund[i]<<endl;

  // check the B 
  out=out&&(abs(d1ChBLund[i])==Dlund);
  out=out&&(abs(d2ChBLund[i])==prlund);
  out=out&&(ndauChB[i]==2); 
  //if(ndauChB[i]==2) {cout<<"ndauchb="<<ndauChB[i]<<endl;}
  //  cout<<"out ="<<out<<endl;
  if (!out) return out;

  // check the D*0
  if (i_Dstar0>=0) {
    out=out&&(ndauDstar0[i_Dstar0]==2);
    out=out&&(abs(d1Dstar0Lund[i_Dstar0])==421);
    out=out&&(abs(d2Dstar0Lund[i_Dstar0])==111 || abs(d2Dstar0Lund[i_Dstar0])==22);
    if (!out) return out;
  }
 
  // check the D0
  out=out&&(ndauD0[i_D0]==3);
  out=out&& ( ((abs(d1D0Lund[i_D0])==310) && (abs(d2D0Lund[i_D0])==lundD0Trk) && (abs(d3D0Lund[i_D0])==lundD0Trk)) ||
	      ((abs(d3D0Lund[i_D0])==310) && (abs(d1D0Lund[i_D0])==lundD0Trk) && (abs(d2D0Lund[i_D0])==lundD0Trk)) );

  //cout<<"d1D0Lund["<<i_D0<<"] = "<<d1D0Lund[i_D0]<<endl;
  //cout<<"d2D0Lund["<<i_D0<<"] = "<<d2D0Lund[i_D0]<< "    "<<"lundD0Trk= "<<lundD0Trk<<endl;
  //cout<<"d3D0Lund["<<i_D0<<"] = "<<d3D0Lund[i_D0]<< "    "<<"lundD0Trk= "<<lundD0Trk<<endl;

  return out;

}//end isBtoDK

Int_t btdkpi::isSignalEvt(Int_t lundD0Trk,Int_t Dlund,Int_t i_chb)  {
  //  cout<<"enter in isSignalEvt"<<endl;
  assert(Dlund==421 || Dlund==423);
  assert(lundD0Trk==321 || lundD0Trk==211);

  Int_t out=0;
  Int_t* bdau=new Int_t[30];//B dau's
  Int_t* Dstar0dau=new Int_t[30];//Dstar0 dau's
  Int_t* Pi0dau=new Int_t[30];//Pi0 dau's
  Int_t* D0dau=new Int_t[30];//D0 dau's
  Int_t* D0k0dau=new Int_t[30];//K0 dau's
  Int_t* D0Ksdau=new Int_t[30];//Ks dau's 
  Int_t* D0resdau  =new Int_t[30]; //D0 res dau's (when the D0 decays to Ks + two body resonance)
  
  // cout<<"Dlund = "<<Dlund<<endl;   
  if (_super_sig_type=="chb" || _super_sig_type=="chbk" || _super_sig_type=="chbpi" || _super_sig_type=="ccbar" ||
      _super_sig_type=="btdk" || _super_sig_type=="btdsk" || _super_sig_type=="btdpi" || _super_sig_type=="btdspi"){
    
   Int_t i_Dstar0 = (abs(d1ChBLund[i_chb])==423)? d1ChBIndex[i_chb]-1 : -999;
    Int_t i_D0 = (i_Dstar0>=0)? d1Dstar0Index[i_Dstar0]-1 : d1ChBIndex[i_chb]-1 ;
    Int_t i_pr = d2ChBIndex[i_chb]-1;

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
    
    Int_t i_Pi0= (i_Dstar0 >= 0 && d2Dstar0Lund[i_Dstar0]==111) ? d2Dstar0Index[i_Dstar0]-1 : -999;
    Int_t i_Pi0g1=(i_Pi0 >= 0 ) ? d1Pi0Index[i_Pi0]-1 : -999;
    Int_t i_Pi0g2=(i_Pi0 >= 0 ) ? d2Pi0Index[i_Pi0]-1 : -999;
    //    Int_t i_Gam= (idMc[Dstar0dau[2]]==22)  ? d2Dstar0Index[i_Dstar0]-1 : -999;
    Int_t i_Gam= (i_Dstar0 >= 0 && d2Dstar0Lund[i_Dstar0]==22)  ? d2Dstar0Index[i_Dstar0]-1 : -999;
  
    Int_t indexMcpr=(i_pr >=0) ? IndexTrk[i_pr]-1 : -999;
    Int_t indexMcD0Pi1=(i_D0Pi1 >=0) ? IndexTrk[i_D0Pi1]-1 : -999;
    Int_t indexMcD0Pi2=(i_D0Pi2 >=0) ? IndexTrk[i_D0Pi2]-1 : -999;
    
    Int_t indexMcD0KsPi1=(i_D0KsPi1 >=0) ? IndexTrk[i_D0KsPi1]-1 : -999;
    Int_t indexMcD0KsPi2=(i_D0KsPi2 >=0) ? IndexTrk[i_D0KsPi2]-1 : -999;
    
    Int_t indexMcPi0g1=(i_Pi0g1>=0) ? IndexGam[i_Pi0g1]-1 : -999;
    Int_t indexMcPi0g2=(i_Pi0g2>=0) ? IndexGam[i_Pi0g2]-1 : -999;
    Int_t indexMcGam=(i_Gam>=0) ? IndexGam[i_Gam]-1 : -999;

    for (Int_t i=0;i<nMc;i++){      // Loop on Mc-truth particles
      
      for (Int_t k=0;k<30;k++) bdau[k]=Dstar0dau[k]=D0dau[k]=Pi0dau[k]=D0k0dau[k]=D0Ksdau[k]=D0resdau[k]=-9;
     //  cout<<"i nMc ="<<i<<"     nMc ="<<nMc<<endl;
//       cout<<"abs(idMc[i]) ="<<abs(idMc[i])<<endl;
      
      if (abs(idMc[i])==521){
	
	//B's daughters
	giveMeDau(i,bdau);
	//	cout<<"bdau ="<<bdau[0]<<endl;
	if (bdau[0]==0) continue;
	//	cout<<"bdau..."<<endl; printInfo(bdau);
	
	//if (bdau[0]==2 &&  abs(idMc[bdau[1]])==421 && abs(idMc[bdau[2]])==211) {cout<<"bdau..."<<endl; printInfo(bdau);}
	
	//Dstar0's daughters
	if (Dlund==423) {
	  giveMeDau(bdau,Dlund,Dstar0dau);
	  if(Dstar0dau[0]==0)continue;
	} 

	// D0's daughters
	if (Dlund==421) giveMeDau(bdau,421,D0dau);
	else giveMeDau(Dstar0dau,421,D0dau);
	if (D0dau[0]==0) continue;
	//   change ordering to have first K0/Ks, and 2nd and 3rd charged tracKs
	Int_t id1 = D0dau[1];
	Int_t id2 = D0dau[2];
	Int_t id3 = D0dau[3];
	//cout << id1 << " " << id2 << " " << id3 << endl;
	if (id1>=0 && id2>=0 && id3>=0) {
	  if ( (abs(idMc[id3])==311 || abs(idMc[id3])==310) && abs(idMc[id2])==lundD0Trk && abs(idMc[id1])==lundD0Trk ) {
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
	giveMeDau(D0dau,223,D0resdau);  // omega
	if (D0resdau[0]==0) giveMeDau(D0dau,333,D0resdau); // phi
	//	cout<<"bdau1 ="<<abs(idMc[bdau[1]])<<"bdau2 ="<<abs(idMc[bdau[2]])<<endl;
	//	cout<<"D0resdau..."<<endl; printInfo(D0resdau);
	
	//   Pi0 daughters
	if (Dlund==423) giveMeDau(Dstar0dau,111,Pi0dau);
	

	//if (bdau[0]==2 &&  abs(idMc[bdau[1]])==421 && abs(idMc[bdau[2]])==211) 
	//  {cout<<"bdau..."<<endl; printInfo(bdau); cout<<"D0dau..."<<endl; printInfo(D0dau); cout<<"D0Ksdau..."<<endl; printInfo(D0Ksdau);}
	

	//####################################################################
	//####################     D0/Dstar0 condition     ###################
	//####################################################################  
	
	Bool_t truth = abs(idMc[bdau[1]])==Dlund && //D0 or Dstar0
	  (abs(idMc[bdau[2]])==321 || abs(idMc[bdau[2]])==211); 
	
	//no other B's dau, apart from eventual Gamma
	truth = truth && ( bdau[0]==2 || ( bdau[0]==3 && idMc[bdau[3]]==22) || (bdau[0]==4 && idMc[bdau[3]]==22 && idMc[bdau[4]]==22));
	
	// Dstar0 (if Dlund=423)
	truth = truth && ( Dlund==421 || ( Dlund==423 &&
					   abs(idMc[Dstar0dau[1]])==421 && //D0
					   ( (abs(idMc[Dstar0dau[2]])==111 && ( idMc[Pi0dau[1]]==22 && idMc[Pi0dau[2]]==22)) || 
					     abs(idMc[Dstar0dau[2]])==22) ) ); //Pi0 or Gamma
	
	//no other Dstar0's dau, apart from eventual Gamma
	truth = truth && ( Dlund==421  || ( Dlund==423 &&
					    (Dstar0dau[0]==2 || (Dstar0dau[0]==3 && idMc[Dstar0dau[3]]==22 || 
								 (Dstar0dau[0]==4 && idMc[Dstar0dau[3]]==22 && idMc[Dstar0dau[4]]==22)) ) ) );
	
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
	
	if (truth)  {
	  
	  // out |= ( 1 << 0 );
	 
	  out=1;

	  //if ( abs(idMc[bdau[2]])==211 ) out |= ( 1 << 13 );  //bad!!!!! perque estan encesos el 0 i el 1!!! entren tots els pions en chbk!!
	  if ( abs(idMc[bdau[2]])==211 ) out= 8192;
	  
	  //cout<<"out="<<out<<endl;
	  if ( (bdau[0]>=3 && idMc[bdau[3]]==22 ) || 
	       (Dstar0dau[0]>=3 && idMc[Dstar0dau[3]]==22 ) || 
	       (D0dau[0]>=4 && idMc[D0dau[4]]==22 ) || 
	       (D0resdau[0]>=3 && idMc[D0resdau[3]]==22 ) ||
	       (D0k0dau[0]>=2 && idMc[D0k0dau[2]]==22 ) ||
	       (D0Ksdau[0]>=3 && idMc[D0Ksdau[3]]==22 ) ){
	    
	    //out |= ( 1 << 1 );  // A Radiative decay somewhere
	    out=2;

	    //if (abs(idMc[bdau[2]])==211) out |= ( 1 << 14 );  // BUGG!!!!!!
	    
	    if (abs(idMc[bdau[2]])==211) out = 16384;
	    
	    //cout << "ATTENTION: Radiative decay in isSignalEvt. Event = " << event << endl; 
	  }
	   
	  // match prompt track    
	  if (indexMcpr==bdau[2] || indexMcpr==bdau[1]) 
	    out |= (1 << 2); 
	  else // See if the pion decays to nu mu.
	    if (  matchAMuon( indexMcpr, bdau[ 2 ] ) )
	    out |= (1 << 24); 

	  // match Pi0 from D*0
	  if (indexMcPi0g1== Pi0dau[1] || indexMcPi0g1==Pi0dau[2]) out |= (1 << 3); //Pi0g1 
	  if ((indexMcPi0g2== Pi0dau[2] || indexMcPi0g2==Pi0dau[1]) && (Pi0dau[2]!=Pi0dau[1])) out |= (1 << 4); //Pi0g2 
	  
	  // match Gamma from D*0
	  if (indexMcGam==Dstar0dau[2] || indexMcGam==Dstar0dau[1]) out |= (1 << 5); //Gam 
	  
 	  //match D0
	  if ( indexMcD0Pi1==D0dau[2] || indexMcD0Pi1==D0dau[3] || 
	       indexMcD0Pi1==D0resdau[1] || indexMcD0Pi1==D0resdau[2])
	    out |= ( 1 << 8);  //pi from D0
	  else
	    if( matchAMuon( indexMcD0Pi1, D0dau   [ 2 ] ) ||
		matchAMuon( indexMcD0Pi1, D0dau   [ 3 ] ) ||
		matchAMuon( indexMcD0Pi1, D0resdau[ 1 ] ) ||
		matchAMuon( indexMcD0Pi1, D0resdau[ 2 ] ) )
	      out |= ( 1 << 20 );

	  if ( indexMcD0Pi2==D0dau[3] || indexMcD0Pi2==D0dau[2] || 
	       indexMcD0Pi2==D0resdau[2] || indexMcD0Pi2==D0resdau[1] )
	    out |= ( 1 << 9 );  //pi from D0
	  else // See if the pion decays to nu mu.
	    if ( matchAMuon( indexMcD0Pi2, D0dau   [ 2 ] ) ||
		 matchAMuon( indexMcD0Pi2, D0dau   [ 3 ] ) ||
		 matchAMuon( indexMcD0Pi2, D0resdau[ 1 ] ) ||
		 matchAMuon( indexMcD0Pi2, D0resdau[ 2 ] ) )
	      out |= ( 1 << 21 );

	  if ( (indexMcD0KsPi1==D0Ksdau[1]) || (indexMcD0KsPi1==D0Ksdau[2]) )
	    out |= ( 1 << 10 ); //pi dal K0
	  else // See if the pion decays to nu mu.
	    if ( matchAMuon( indexMcD0KsPi1, D0Ksdau[ 1 ] ) ||
		 matchAMuon( indexMcD0KsPi1, D0Ksdau[ 2 ] ) )
	      out |= ( 1 << 22 );
	  
	  if ( (indexMcD0KsPi2==D0Ksdau[2]) || (indexMcD0KsPi2==D0Ksdau[1]) )
	    out |= ( 1 << 11 ); //pi dal K0
	  else // See if the pion decays to nu mu.
	    if ( matchAMuon( indexMcD0KsPi2, D0Ksdau[ 1 ] ) ||
		 matchAMuon( indexMcD0KsPi2, D0Ksdau[ 2 ] ) )
	      out |= ( 1 << 23 );
	  	  
	 break;  
	}
          // else { for (Int_t k=0;k<30;k++) bdau[k]=Dstar0dau[k]=D0dau[k]=Pi0dau[k]=D0k0dau[k]=D0Ksdau[k]=D0resdau[k]=-9; }
      
    }//end idMc==521
    
    
  }//end for nMc   
  
  
    //**********************************************************************************************
    //****************************BIT MAP***********************************************************
    //**********************************************************************************************
    /////////WITH K:
    
    //full match B->D0K: 1+4+256+512+1024+2048=3845
    //full match (brem) : 2+4+256+512+1024+2048=3846
    
    //full match B->D*0(D0Pi0)K: 1+4+8+16+256+512+1024+2048=3869
    //full match (brem) : 2+4+8+16+256+512+1024+2048=3870
    
    //full match B->D*0(D0Gam)K: 1+4+32+256+512+1024+2048=3877
    //full match (brem) : 2+4+32+256+512+1024+2048=3878

    //D0 match: 1+256+512+1024+2048=3841
    //D0 match (brem): 2+256+512+1024+2048=3842

    //K0 match (from D0): 1+1024+2048=3073
    //K0 match (from D0) (brem): 2+1024+2048=3074

    //D*0(D0Pi0) match: 1+8+16+256+512+1024+2048=3865
    //D*0(D0Pi0) match(brem): 2+8+16+256+512+1024+2048=3866

    //D*0(D0Gam) match: 1+32+256+512+1024+2048=3873
    //D*0(D0Gam) match (brem): 2+32+256+512+1024+2048=3874

    //prompt match: 1+4=5
    //prompt match (brem): 2+4=6

 
    ////////WITH PI:
    
    //full match B->D0K: 8192+4+256+512+1024+2048=12036
    //full match (brem) : 16384+4+256+512+1024+2048=20228
    
    //full match B->D*0(D0Pi0)K: 8192+4+8+16+256+512+1024+2048=12060
    //full match (brem) : 16384+4+8+16+256+512+1024+2048=20252
    
    //full match B->D*0(D0Gam)K: 8192+4+32+256+512+1024+2048=12068
    //full match (brem) : 16384+4+32+256+512+1024+2048=20260
    
    //D0 match: 8192+256+512+1024+2048=12032
    //D0 match (brem): 16384+256+512+1024+2048=20224

    //K0 match (from D0): 8192+1024+2048=11264
    //K0 match (from D0) (brem): 16384+1024+2048=19456

    //D*0(D0Pi0) match: 8192+8+16+256+512+1024+2048=12056
    //D*0(D0Pi0) match(brem): 16384+8+16+256+512+1024+2048=20248

    //D*0(D0Gam) match: 8192+32+256+512+1024+2048=12064
    //D*0(D0Gam) match (brem): 16384+32+256+512+1024+2048=20256

    //prompt match: 8192+4=8196
    //prompt match (brem): 16384+4=16388
    
     }//end if ChB or signal
  
  delete[] Dstar0dau;
  delete[] Pi0dau;
  delete[] bdau;
  delete[] D0dau;
  delete[] D0k0dau;
  delete[] D0Ksdau;
  delete[] D0resdau;

  //  cout<<"exit from isSignalEvt"<<endl;
  //  cout <<"out = " << out << endl;

return out; 
  
}
//end isSignalEvt



void btdkpi::giveMeDau(Int_t index,Int_t* dauarray){
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


void btdkpi::giveMeDau(Int_t* motharray, Int_t id, Int_t* dauarray){
  Int_t j(1);
  while  ( j<=motharray[0] && abs(idMc[motharray[j]])!=abs(id) ) j++;
  if (j>motharray[0]) j=-1;
  Int_t index = (j<=motharray[0])? motharray[j] : -1;
  giveMeDau(index,dauarray);
}//end giveMeDau



void btdkpi::printInfo(Int_t* array){
  cout<<"array[0] = "<<array[0]<<endl;
  for (Int_t i=1;i<=array[0];i++) {
    cout<<"array["<<i<<"] = "<<array[i]<<" idMc[array["<<i<<"]] = "<<idMc[array[i]]<<endl;
  }
}//end printInfo



Int_t btdkpi::isD0true(Int_t lundD0Trk,Int_t iMc_D0Pi1,Int_t iMc_D0Pi2,Int_t iMc_KsPi1,Int_t iMc_KsPi2)
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
  
  //if (_super_sig_type=="btdsk" && mothMc[iMc_Ks] != mothMc[iMc_D0Pi1] ) return 0;
  //if (_super_sig_type!="btdsk" && mothMc[mothMc[iMc_Ks]-1] != mothMc[iMc_D0Pi1]) return 0;
  
  Int_t* D0dau_true=new Int_t[30];//D0 dau's
  Int_t* D0Ksdau_true=new Int_t[30];//Ks dau's
  Int_t* D0resdau_true  =new Int_t[30]; //D0 res dau's 

 for (Int_t k=0;k<10;k++) D0dau_true[k]=D0Ksdau_true[k]=D0resdau_true[k]=-9;
  
  giveMeDau(iMc_D0,D0dau_true);
  giveMeDau(iMc_Ks,D0Ksdau_true);
  giveMeDau(D0dau_true,223,D0resdau_true);  // omega
  if (D0resdau_true[0]==0) giveMeDau(D0dau_true,333,D0resdau_true); // phi


  
  if (  ((((abs(idMc[D0dau_true[1]])==310 || abs(idMc[D0dau_true[1]])==311) &&
	  abs(idMc[D0dau_true[2]])==lundD0Trk && abs(idMc[D0dau_true[3]])==lundD0Trk) ||

	 ((abs(idMc[D0dau_true[3]])==310 || abs(idMc[D0dau_true[3]])==311) &&
	  abs(idMc[D0dau_true[1]])==lundD0Trk && abs(idMc[D0dau_true[2]])==lundD0Trk))  &&
	abs(idMc[D0Ksdau_true[1]])==211 && abs(idMc[D0Ksdau_true[2]])==211)  

	||//omega i phi

	((((abs(idMc[D0dau_true[1]])==310 || abs(idMc[D0dau_true[1]])==311) &&
	   (abs(idMc[D0dau_true[2]])==223 || abs(idMc[D0dau_true[2]])==333))  ||

	  ((abs(idMc[D0dau_true[2]])==310 || abs (idMc[D0dau_true[2]])==311)  &&
	   (abs(idMc[D0dau_true[1]])==223 ||abs(idMc[D0dau_true[1]])==333) ))  &&
	 abs(idMc[D0Ksdau_true[1]])==211 && abs(idMc[D0Ksdau_true[2]])==211 &&
	 abs(idMc[D0resdau_true[1]])==lundD0Trk && abs(idMc[D0resdau_true[2]])==lundD0Trk) 
	
	)
	
    { 
    if ((D0dau_true[0]==3) || (D0dau_true[0]==2)) isD0 = 1;
    else if ( (D0dau_true[0]==3 && idMc[D0dau_true[3]==22])||(D0dau_true[0]==4 && idMc[D0dau_true[4]]==22) || (D0dau_true[0]==5 && idMc[D0dau_true[4]]==22 && idMc[D0dau_true[5]]==22) ) isD0 = 2;
    if ( (D0Ksdau_true[0]==3 && idMc[D0Ksdau_true[3]]==22) || (D0Ksdau_true[0]==4 && idMc[D0Ksdau_true[3]]==22 && idMc[D0Ksdau_true[4]]==22) ) isD0 += 4;   
  }
  
  delete[] D0dau_true;
  delete[] D0Ksdau_true;
  delete[] D0resdau_true;
  return isD0;
}//end isD0true


Int_t btdkpi::isKstrue(Int_t iMc_KsPi1,Int_t iMc_KsPi2)
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


Int_t btdkpi::ispi0true(Int_t iMc_Pi0g1,Int_t iMc_Pi0g2)
{
  // the Mc truth particle indexes are the argument
  
  Int_t isPi0true=0;
  
  Int_t im1  =-1;
  Int_t im2  =-1;
  
  if (iMc_Pi0g1<0 || iMc_Pi0g2<0){
    
    //cout<<"WARNING: iMc_Pi0g1 = "<<iMc_Pi0g1 <<" iMc_Pi0g2 = "<<iMc_Pi0g2 << endl;
    //cout<<" event = "<<event<<" runNumber = "<<runNumber<<endl;
    return 0; 
  }
  
  if ((abs(idMc[iMc_Pi0g1])!=22) || (abs(idMc[iMc_Pi0g2])!=22)) return 0;

  im1 = mothMc[iMc_Pi0g1]-1;
  im2 = mothMc[iMc_Pi0g2]-1;
  
  if (im1 < 0 || im2 < 0) return 0;
  if (im1 != im2)         return 0;

  if (abs(idMc[im1])==111) isPi0true=1;

  //if (isPi0true>0) cout << "isPi0true = " << isPi0true << endl;

  //  
  return isPi0true;

}//end isPi0true

         
     
Int_t btdkpi::isDstar0D0Pi0true(Int_t iMc_D0Pi1,Int_t iMc_Pi0g1,Int_t iMc_Pi0g2)
{
  Int_t isDstar0D0Pi0=0;
  if (iMc_D0Pi1<0 || iMc_Pi0g1<0 || iMc_Pi0g2<0 || iMc_Pi0g2==iMc_Pi0g1 || mothMc[iMc_Pi0g1]<=0 || mothMc[iMc_Pi0g2]<=0){
    return 0; 
  }
  //  cout << " ###Entro da idDstar0Pi0### "<<isDstar0D0Pi0 <<endl;
  if (abs(idMc[mothMc[iMc_D0Pi1]-1])!=421) return 0;
  Int_t iMc_D0=mothMc[iMc_D0Pi1]-1;
  if (abs(idMc[mothMc[iMc_D0]-1])!=423) return 0;
  if (idMc[iMc_Pi0g1] != 22) return 0;
  if (idMc[iMc_Pi0g2] != 22) return 0;
  if (idMc[mothMc[iMc_Pi0g1]-1]!=111) return 0;
  if (idMc[mothMc[iMc_Pi0g2]-1]!=111) return 0;
  if ( mothMc[iMc_Pi0g1] != mothMc[iMc_Pi0g2]) return 0;
  
  Int_t iMc_Pi0=mothMc[iMc_Pi0g1]-1;
  if (abs(idMc[mothMc[iMc_Pi0]-1])!=423) return 0;
  if (mothMc[iMc_Pi0] != mothMc[iMc_D0]) return 0;
  Int_t iMc_Dstar0=mothMc[iMc_D0]-1;

  Int_t* Dstar0dau=new Int_t[30];//Dstar0 dau's
  Int_t* Pi0dau=new Int_t[30];//Pi0 dau's
  for (Int_t k=0;k<10;k++) Dstar0dau[k]=Pi0dau[k]=0;
  giveMeDau(iMc_Dstar0,Dstar0dau);
  giveMeDau(iMc_Pi0,Pi0dau);

  if (abs(idMc[Dstar0dau[1]])==421 &&
      idMc[Dstar0dau[2]]==111 &&
      idMc[Pi0dau[1]]==22 &&
      idMc[Pi0dau[2]]==22 &&
      (idMc[Dstar0dau[3]]==22 || Dstar0dau[3]==0) && (idMc[Dstar0dau[4]]==22 || Dstar0dau[4]==0)){
    isDstar0D0Pi0=1;
    if (Dstar0dau[0]!=2 && Pi0dau[0]==2) isDstar0D0Pi0=2; 
    if (Dstar0dau[0]==2 && Pi0dau[0]!=2) isDstar0D0Pi0=3; 
    if (Dstar0dau[0]!=2 && Pi0dau[0]!=2) isDstar0D0Pi0=4; 
    if (isDstar0D0Pi0>1) 
      cout<< " isDtar0Pi0 isDstar0D0Pi0=" << isDstar0D0Pi0<<endl;
    else {
      //	cout << " isDstar0D0Pi0true isDstar0D0Pi0=" << isDstar0D0Pi0<<endl;
      //	cout << " Pi0dau[1] = " << Pi0dau[1] <<endl;
      //	cout << " Pi0dau[2] = " << Pi0dau[2] <<endl;
    }
  }
  
  delete[] Dstar0dau;
  delete[] Pi0dau;
  //  cout << " ###Esco da idDstar0Pi0### "<<isDstar0D0Pi0 <<endl;
  return isDstar0D0Pi0;
}//end isDstar0D0Pi0true


Int_t btdkpi::isDstar0D0Gamtrue(Int_t iMc_D0Pi1,Int_t iMc_Gam)
{
  Int_t isDstar0D0Gam=0;
  if (iMc_D0Pi1<0 || iMc_Gam<0 || mothMc[iMc_Gam]<=0){
    return 0; 
  }
  //  cout << " $$$Entro da idDstar0Gam$$$ "<<isDstar0D0Gam <<endl;
  if (abs(idMc[mothMc[iMc_D0Pi1]-1])!=421) return 0;
  Int_t iMc_D0=mothMc[iMc_D0Pi1]-1;
  if (abs(idMc[mothMc[iMc_D0]-1])!=423) return 0;
  if (abs(idMc[mothMc[iMc_Gam]-1])!=423) return 0;
  if ( mothMc[iMc_D0] != mothMc[iMc_Gam]) return 0;
  Int_t iMc_Dstar0=mothMc[iMc_D0]-1;
  if (iMc_Dstar0<=0 ){
    cout<<"WARNING: iMc_Dstar0 = "<<iMc_Dstar0<<endl;
    //    cout<<" event = "<<event<<" runNumber = "<<runNumber<<endl;
    return 0; 
  }
  
  Int_t* Dstar0dau=new Int_t[30];//Dstar0 dau's
  for (Int_t k=0;k<10;k++) Dstar0dau[k]=0;
  giveMeDau(iMc_Dstar0,Dstar0dau);
  
  if (abs(idMc[Dstar0dau[1]])==421 &&
      idMc[Dstar0dau[2]]==22 &&
      (Dstar0dau[3]==0 || idMc[Dstar0dau[3]]==22)){
    isDstar0D0Gam=1;
    if (Dstar0dau[0]!=2) {isDstar0D0Gam=2; cout<< " isDstar0D0Gamtrue isDstar0D0Gam=" << isDstar0D0Gam<<endl;}
    else {
      //	cout << " isDstar0D0Gamtrue isDstar0D0Gam=" << isDstar0D0Gam<<endl;
      //	cout << " Dstar0dau[2] = " << Dstar0dau[2] <<endl;
    }
  }

  delete[] Dstar0dau;
  //  cout << " $$$Esco da idDstar0Gam$$$ "<<isDstar0D0Gam <<endl;
  return isDstar0D0Gam;

}//end isDstar0D0Gamtrue


 
Float_t btdkpi::DeltaE(const TLorentzVector & P4Ups,const TLorentzVector & P4B) 
{
  //  cout<<"inside DeltaE"<<endl;
  Float_t out=-999;
  Float_t S = P4Ups.Mag2();   

  if (S > 0)   out = (2*(P4Ups*P4B)-S)/(2*sqrt(S));

  return out;

} // DeltaE


Float_t btdkpi::Mes(const TLorentzVector & P4Ups,const TLorentzVector & P4B) 
{
  Float_t out=-999;

  Float_t S = P4Ups.Mag2();

  TVector3 P3Ups = P4Ups.Vect();
  TVector3 P3B   = P4B.Vect();

  if (S <= 0) return out;
  
  Float_t out2 = (S/2 + P3Ups*P3B)*(S/2 + P3Ups*P3B)/(P4Ups.E()*P4Ups.E()) - P3B.Mag2();

  if (out2 < 0) return out;    

  out = sqrt(out2);

 
  
  //   /////////////////////////////////////////////
  //   TLorentzVector P4B_2(P4B);
  //   TLorentzVector P4B_minus(0,0,0,0);
  //   Float_t p(0.2);
  //   //Float_t p(0.6);
  //   //P4B_minus.SetPx(p/sqrt(3));
  //   //P4B_minus.SetPy(p/sqrt(3));
  //   //P4B_minus.SetPz(p/sqrt(3));
  //   P4B_minus.SetPx(p/sqrt(2));
  //   P4B_minus.SetPy(p/sqrt(2));
  //   P4B_minus.SetPz(0);
  //   Float_t m(0.13957);
  //   //Float_t m(0.493677);
  //   P4B_minus.SetE(sqrt(p*p+m*m));
  //   P4B_2 = P4B_2 - P4B_minus;
  //   TVector3 P3B_2   = P4B_2.Vect();
  //   Float_t out3 = (S/2 + P3Ups*P3B_2)*(S/2 + P3Ups*P3B_2)/(P4Ups.E()*P4Ups.E()) - P3B_2.Mag2();
  //   out3 = (out3>=0)? sqrt(out3) : out3;
  //   cout << "mES="<<out<<" "<<out3<<" " << out-out3 << endl;
  //   return out3
  //   /////////////////////////////////////////////
  

  return out;    

} // Mes


Float_t btdkpi::Alpha(const TVector3 & P1,const TVector3 & P2,const TVector3 & Q)
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

Int_t btdkpi::isSignalEvt2(Int_t lundD0Trk,Int_t Dlund,Int_t i_chb){
  //  cout<<"enter in isSignalEvt"<<endl;
  assert(Dlund==421 || Dlund==423);
  assert(lundD0Trk==321 || lundD0Trk==211);

  Int_t out=0;

  Int_t* D0dau=new Int_t[30];//D0 dau's
  Int_t* D0k0dau=new Int_t[30];//K0 dau's
  Int_t* D0Ksdau=new Int_t[30];//Ks dau's 
  Int_t* D0resdau  =new Int_t[30]; //D0 res dau's (when the D0 decays to Ks + two body resonance)
  
  // cout<<"Dlund = "<<Dlund<<endl;   
   if (_super_sig_type==("btdk") || _super_sig_type==("btdpi") || 
       _super_sig_type==("btdsk") || _super_sig_type==("btdspi") || 
       _super_sig_type==("chb") || _super_sig_type==("b0b0bar") || 
       _super_sig_type==("chbk") || _super_sig_type==("chbpi") || 
       _super_sig_type==("ccbar") || _super_sig_type==("uds") ){
 
    Int_t i_Dstar0 = (abs(d1ChBLund[i_chb])==423)? d1ChBIndex[i_chb]-1 : -999;
    Int_t i_D0 = (i_Dstar0>=0)? d1Dstar0Index[i_Dstar0]-1 : d1ChBIndex[i_chb]-1 ;
    Int_t i_pr = d2ChBIndex[i_chb]-1;
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
    Int_t i_D0KsPi2=d2KsIndex[i_D0Ks]-1;
  
    Int_t indexMcD0Pi1=(i_D0Pi1 >=0) ? IndexTrk[i_D0Pi1]-1 : -999;
    Int_t indexMcD0Pi2=(i_D0Pi2 >=0) ? IndexTrk[i_D0Pi2]-1 : -999;
    
    Int_t indexMcD0KsPi1=(i_D0KsPi1 >=0) ? IndexTrk[i_D0KsPi1]-1 : -999;
    Int_t indexMcD0KsPi2=(i_D0KsPi2 >=0) ? IndexTrk[i_D0KsPi2]-1 : -999;
    
 


    for (Int_t i=0;i<nMc;i++){      // Loop on Mc-truth particles
      
      for (Int_t k=0;k<30;k++) D0dau[k]=D0k0dau[k]=D0Ksdau[k]=D0resdau[k]=-9;
      //  cout<<"i nMc ="<<i<<"     nMc ="<<nMc<<endl;
      //       cout<<"abs(idMc[i]) ="<<abs(idMc[i])<<endl;
      
      if (abs(idMc[i])==421){
	
	//D0's daughters
	giveMeDau(i,D0dau);
	if (D0dau[0]==0) continue;

	//   change ordering to have first K0/Ks, and 2nd and 3rd charged tracKs
	Int_t id1 = D0dau[1];
	Int_t id2 = D0dau[2];
	Int_t id3 = D0dau[3];

	if (id1>=0 && id2>=0 && id3>=0) {
	  if ( (abs(idMc[id3])==311 || abs(idMc[id3])==310) && abs(idMc[id2])==lundD0Trk && abs(idMc[id1])==lundD0Trk ) {
	    D0dau[1]=id3;
	    D0dau[2]=id1;
	    D0dau[3]=id2;
	  }
	}
	//   Ks's daugthers  (from K0)
	giveMeDau(D0dau,311,D0k0dau);
	if(D0k0dau[0]==0) giveMeDau(D0dau,310,D0Ksdau);
	else giveMeDau(D0k0dau,310,D0Ksdau);
	if(D0Ksdau[0]==0) continue;
	
	//cout<<"D0k0dau..."<<endl; printInfo(D0k0dau);
	//cout<<"D0Ksdau..."<<endl; printInfo(D0Ksdau);
	
	// get resonance (omega,phi) (from D0) daughters (if any)
	giveMeDau(D0dau,223,D0resdau);  // omega
	if (D0resdau[0]==0) giveMeDau(D0dau,333,D0resdau); // phi
	//	cout<<"bdau1 ="<<abs(idMc[bdau[1]])<<"bdau2 ="<<abs(idMc[bdau[2]])<<endl;
	//	cout<<"D0resdau..."<<endl; printInfo(D0resdau);
	

	//####################################################################
	//####################     D0/Dstar0 condition     ###################
	//####################################################################  
	

	
	//no other B's dau, apart from eventual Gamma

	//D0 -> Ks lundTrk lundTrk 
	Bool_t truth = ( ( (D0dau[0]==3 || (D0dau[0]==4 && idMc[D0dau[4]]==22) || (D0dau[0]==5 && idMc[D0dau[4]]==22 && idMc[D0dau[5]]==22)) &&
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
	  
	  if (D0resdau[0]==2 || (D0resdau[0]==3 && idMc[D0resdau[3]]==22) ) { 
	    //cout << "ATTENTION: resonance (omega/phi) from D0 decay found..." << endl; printInfo(D0resdau); 
	  }
	  
	  //if (abs(idMc[bdau[2]])==321) out = 1;
	  out |= ( 1 << 0 );
	  //cout << "ATTENTION: Signal event was found" << endl;
	  //cout << idMc[bdau[2]] << " " << out << endl;

	  if ( 	       (D0dau[0]>=4 && idMc[D0dau[4]]==22 ) || 
		       (D0resdau[0]>=3 && idMc[D0resdau[3]]==22 ) ||
		       (D0k0dau[0]>=2 && idMc[D0k0dau[2]]==22 ) ||
		       (D0Ksdau[0]>=3 && idMc[D0Ksdau[3]]==22 ) ){
	    
	    //if (abs(idMc[bdau[2]])==321) out=2;   // A Radiative decay somewhere
	    out |= ( 1 << 1);  // A Radiative decay somewhere

	  }
		
  	  //match D0
	  if ( indexMcD0Pi1==D0dau[2] || indexMcD0Pi1==D0dau[3] || 
	       indexMcD0Pi1==D0resdau[1] || indexMcD0Pi1==D0resdau[2])
	    out |= ( 1 << 8);  //pi from D0
	  else
	    if( matchAMuon( indexMcD0Pi1, D0dau   [ 2 ] ) ||
		matchAMuon( indexMcD0Pi1, D0dau   [ 3 ] ) ||
		matchAMuon( indexMcD0Pi1, D0resdau[ 1 ] ) ||
		matchAMuon( indexMcD0Pi1, D0resdau[ 2 ] ) )
	      out |= ( 1 << 20 );

	  if ( indexMcD0Pi2==D0dau[3] || indexMcD0Pi2==D0dau[2] || 
	       indexMcD0Pi2==D0resdau[2] || indexMcD0Pi2==D0resdau[1] )
	    out |= ( 1 << 9 );  //pi from D0
	  else // See if the pion decays to nu mu.
	    if ( matchAMuon( indexMcD0Pi2, D0dau   [ 2 ] ) ||
		 matchAMuon( indexMcD0Pi2, D0dau   [ 3 ] ) ||
		 matchAMuon( indexMcD0Pi2, D0resdau[ 1 ] ) ||
		 matchAMuon( indexMcD0Pi2, D0resdau[ 2 ] ) )
	      out |= ( 1 << 21 );

	  if ( (indexMcD0KsPi1==D0Ksdau[1]) || (indexMcD0KsPi1==D0Ksdau[2]) )
	    out |= ( 1 << 10 ); //pi dal K0
	  else // See if the pion decays to nu mu.
	    if ( matchAMuon( indexMcD0KsPi1, D0Ksdau[ 1 ] ) ||
		 matchAMuon( indexMcD0KsPi1, D0Ksdau[ 2 ] ) )
	      out |= ( 1 << 22 );
	  
	  if ( (indexMcD0KsPi2==D0Ksdau[2]) || (indexMcD0KsPi2==D0Ksdau[1]) )
	    out |= ( 1 << 11 ); //pi dal K0
	  else // See if the pion decays to nu mu.
	    if ( matchAMuon( indexMcD0KsPi2, D0Ksdau[ 1 ] ) ||
		 matchAMuon( indexMcD0KsPi2, D0Ksdau[ 2 ] ) )
	      out |= ( 1 << 23 );
	  
	 
	  //the search is completed
	  
	} // else { for (Int_t k=0;k<30;k++) bdau[k]=Dstar0dau[k]=D0dau[k]=Pi0dau[k]=D0k0dau[k]=D0Ksdau[k]=D0resdau[k]=-9; }
	
      }//end idMc==521
    }//end for nMc   
    
      
    // Reco particles
    // cout<<"reco particles"<<endl;
    // cout<<"i_chb ="<<i_chb<<endl;	   
      
    // cout<<"d1D0Index ="<<d1D0Index[50]<<endl;
 






    //   cout<<"holaaaaaaa"<<endl;
    //**********************************************************************************************
    //****************************BIT MAP***********************************************************
    //**********************************************************************************************
    /////////WITH K:
    

    //D0 match: 1+256+512+1024+2048=3841
    //D0 match (brem): 2+256+512+1024+2048=3842

    //K0 match (from D0): 1+1024+2048=3073
    //K0 match (from D0) (brem): 2+1024+2048=3074

    //D*0(D0Pi0) match: 1+8+16+256+512+1024+2048=3865
    //D*0(D0Pi0) match(brem): 2+8+16+256+512+1024+2048=3866

    //D*0(D0Gam) match: 1+32+256+512+1024+2048=3873
    //D*0(D0Gam) match (brem): 2+32+256+512+1024+2048=3874

    //prompt match: 1+4=5
    //prompt match (brem): 2+4=6

 
    ////////WITH PI:
    
    //full match B->D0K: 8192+4+256+512+1024+2048=12036
    //full match (brem) : 16384+4+256+512+1024+2048=20228
    
    //full match B->D*0(D0Pi0)K: 8192+4+8+16+256+512+1024+2048=12060
    //full match (brem) : 16384+4+8+16+256+512+1024+2048=20252
    
    //full match B->D*0(D0Gam)K: 8192+4+32+256+512+1024+2048=12068
    //full match (brem) : 16384+4+32+256+512+1024+2048=20260
    
    //D0 match: 8192+256+512+1024+2048=12032
    //D0 match (brem): 16384+256+512+1024+2048=20224

    //K0 match (from D0): 8192+1024+2048=11264
    //K0 match (from D0) (brem): 16384+1024+2048=19456

    //D*0(D0Pi0) match: 8192+8+16+256+512+1024+2048=12056
    //D*0(D0Pi0) match(brem): 16384+8+16+256+512+1024+2048=20248

    //D*0(D0Gam) match: 8192+32+256+512+1024+2048=12064
    //D*0(D0Gam) match (brem): 16384+32+256+512+1024+2048=20256

    //prompt match: 8192+4=8196
    //prompt match (brem): 16384+4=16388
    
   }//end if ChB or signal
  

  delete[] D0dau;
  delete[] D0k0dau;
  delete[] D0Ksdau;
  delete[] D0resdau;

  //  cout<<"exit from isSignalEvt2"<<endl;
  //  cout <<"*******************************   out = " << out << endl;

return out; 
  
}


// Return true if the associated particle matches a daughter muon of the given MC particle.
Bool_t btdkpi::matchAMuon( Int_t matchedIndex, Int_t mcIndex )
{
  int dau = indexMuonDaughter( mcIndex );

  if ( dau && ( matchedIndex == dau ) )
    return true;

  return false;
}

// Check if a particle (pion in particular), decays to mu, and
//    return the index of the muon (zero if not found).
Int_t btdkpi::indexMuonDaughter( Int_t index )
{
  Int_t auxDau[30];

  for( int dau = 0; dau < 30; dau++ )
    auxDau[ dau ] = 0;

  giveMeDau( index, auxDau );
  int dau = 1;
  if ( auxDau[ 0 ] )
    {
      // Find a muon in the list of daughters of the pion.
      while( ( dau <= auxDau[ 0 ] ) && ( abs( idMc[ auxDau[ dau ] ] ) != 13 ) )
	dau++;

      // If we went through the whole vector and didn't find a mu,
      //    set dau to zero.
      if ( dau > auxDau[ 0 ] )
	return 0;
    }

  return auxDau[ dau ];
}

