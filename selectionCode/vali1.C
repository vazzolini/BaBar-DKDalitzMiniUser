#define vali1_cxx
#include "vali1.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void vali1::Loop(Int_t nentries)
{
//   In a ROOT session, you can do:
//      Root > .L vali1.C
//      Root > vali1 t
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
   


if (fChain == 0) return;

//  Long64_t nentries = fChain->GetEntriesFast();
//   Long64_t nbytes = 0, nb = 0;
  
 if (nentries<=0 || nentries>fChain->GetEntries()) nentries = Int_t(fChain->GetEntries());
    //  cout << "Outside Loop, nentries=" << nentries << endl;
   cout<<"nentries(18)= "<<nentries<<endl;


   
   //NEW R18 TTree
   TString newrootfile_name="./vali1/kskk4/valireducednew18_"+_dtype+"_"+_d0mode+"_"+_sample+".root";  
   TFile *file = new TFile(newrootfile_name,"RECREATE","Reduced root file");
   TString name="R18new"+_dtype;
   TTree *treenew = new TTree(name,"Reduced Dstar NEW R18 tree"); 

   //copy all variables into R18new!!!
   treenew->Branch("event",&event,"event/I");
   treenew->Branch("runNumber",&runNumber,"runNumber/I");
   treenew->Branch("FoxWol2Neu",&FoxWol2Neu,"FoxWol2Neu/F");
   treenew->Branch("lowerID", &lowerID, "lowerID/I");
   treenew->Branch("upperID", &upperID, "upperID/I");
   treenew->Branch("pxUps",&pxUps,"pxUps/F");
   treenew->Branch("pyUps",&pyUps,"pyUps/F");
   treenew->Branch("pzUps",&pzUps,"pzUps/F");
   treenew->Branch("eUps", &eUps, "eUps/F");

   //Mc info
   treenew->Branch("nMc",&nMc,"nMc/I");
   treenew->Branch("idMc",idMc,"idMc[nMc]/I");
   treenew->Branch("mothMc",mothMc,"mothMc[nMc]/I");
   treenew->Branch("nDauMc",nDauMc,"nDauMc[nMc]/I");
   treenew->Branch("pMc",pMc,"pMc[nMc]/F");
   treenew->Branch("thetaMc",thetaMc,"thetaMc[nMc]/F");
   treenew->Branch("phiMc",phiMc,"phiMc[nMc]/F");
   treenew->Branch("McEvtType",&McEvtType,"McEvtType/I");


   //ChB
   treenew->Branch("demk",&demk,"demk/F");
   treenew->Branch("demk2",&demk2,"demk2/F");//original deltaE in ntuples
   treenew->Branch("mes",&mes,"mes/F");
   treenew->Branch("pxChB",&pxChB,"pxChB/F");
   treenew->Branch("pyChB",&pyChB,"pyChB/F");
   treenew->Branch("pzChB",&pzChB,"pzChB/F");
   treenew->Branch("xChB",&xChB,"xChB/F");
   treenew->Branch("yChB",&yChB,"yChB/F");
   treenew->Branch("zChB",&zChB,"zChB/F");
   treenew->Branch("cosChBCM",&cosChBCM,"cosChBCM/F");
   treenew->Branch("m0ChB",&m0ChB,"m0ChB/F");
   treenew->Branch("massChB",&massChB,"massChB/F");
   treenew->Branch("chi2ChB",&chi2ChB,"chi2ChB/F");
   treenew->Branch("dofChB",&dofChB,"dofChB/F");
   treenew->Branch("indexMcChB",&indexMcChB,"indexMcChB/I");
   treenew->Branch("legendrep0",&legendrep0,"legendrep0/F");
   treenew->Branch("legendrep2",&legendrep2,"legendrep2/F");
   treenew->Branch("fisher",&fisher,"fisher/F");
   treenew->Branch("costhrust",&costhrust,"costhrust/F");

   //Dstar0
   treenew->Branch("m0Dstar0",&m0Dstar0,"m0Dstar0/F");
   treenew->Branch("massDstar0",&massDstar0,"massDstar0/F");
   treenew->Branch("pxDstar0",&pxDstar0,"pxDstar0/F");
   treenew->Branch("pyDstar0",&pyDstar0,"pyDstar0/F");
   treenew->Branch("pzDstar0",&pzDstar0,"pzDstar0/F");
   treenew->Branch("eDstar0",&eDstar0,"eDstar0/F");
   treenew->Branch("chi2Dstar0",&chi2Dstar0,"chi2Dstar0/F");
   treenew->Branch("dofDstar0",&dofDstar0,"dofDstar0/F");
   treenew->Branch("flagD0Pi0",&flagD0Pi0,"flagD0Pi0/I");
   treenew->Branch("indexMcDstar0",&indexMcDstar0,"indexMcDstar0/I");
   treenew->Branch("isMcDstar0Gam",&isMcDstar0Gam,"isMcDstar0Gam/I");
   treenew->Branch("isMcDstar0Pi0",&isMcDstar0Pi0,"isMcDstar0Pi0/I");

   //Dstar0 dau Pi0
   treenew->Branch("m0Dstar0Pi0",&m0Dstar0Pi0,"m0Dstar0Pi0/F");
   treenew->Branch("pxDstar0Pi0",&pxDstar0Pi0,"pxDstar0Pi0/F");
   treenew->Branch("pyDstar0Pi0",&pyDstar0Pi0,"pyDstar0Pi0/F");
   treenew->Branch("pzDstar0Pi0",&pzDstar0Pi0,"pzDstar0Pi0/F");
   treenew->Branch("eDstar0Pi0",&eDstar0Pi0,"eDstar0Pi0/F");
   treenew->Branch("chi2Dstar0Pi0",&chi2Dstar0Pi0,"chi2Dstar0Pi0/F");
   treenew->Branch("dofDstar0Pi0",&dofDstar0Pi0,"dofDstar0Pi0/F");
   treenew->Branch("indexMcDstar0Pi0",&indexMcDstar0Pi0,"indexMcDstar0Pi0/I");

   //Pi0 dau1 Pi0g1
   treenew->Branch("ecalDstar0Pi0g1",&ecalDstar0Pi0g1,"ecalDstar0Pi0g1/F");
   treenew->Branch("ecalxDstar0Pi0g1",&ecalxDstar0Pi0g1,"ecalxDstar0Pi0g1/F");
   treenew->Branch("ecalyDstar0Pi0g1",&ecalyDstar0Pi0g1,"ecalyDstar0Pi0g1/F");
   treenew->Branch("ecalzDstar0Pi0g1",&ecalzDstar0Pi0g1,"ecalzDstar0Pi0g1/F");
   treenew->Branch("pxDstar0Pi0g1",&pxDstar0Pi0g1,"pxDstar0Pi0g1/F");
   treenew->Branch("pyDstar0Pi0g1",&pyDstar0Pi0g1,"pyDstar0Pi0g1/F");
   treenew->Branch("pzDstar0Pi0g1",&pzDstar0Pi0g1,"pzyDstar0Pi0g1/F");
   treenew->Branch("lmomDstar0Pi0g1",&lmomDstar0Pi0g1,"lmomDstar0Pi0g1/F");
   treenew->Branch("ncryDstar0Pi0g1",&ncryDstar0Pi0g1,"ncryDstar0Pi0g1/I");
   treenew->Branch("indexMcDstar0Pi0g1",&indexMcDstar0Pi0g1,"indexMcDstar0Pi0g1/I");

   //Pi0 dau2 Pi0g2
   treenew->Branch("ecalDstar0Pi0g2",&ecalDstar0Pi0g2,"ecalDstar0Pi0g2/F");
   treenew->Branch("ecalxDstar0Pi0g2",&ecalxDstar0Pi0g2,"ecalxDstar0Pi0g2/F");
   treenew->Branch("ecalyDstar0Pi0g2",&ecalyDstar0Pi0g2,"ecalyDstar0Pi0g2/F");
   treenew->Branch("ecalzDstar0Pi0g2",&ecalzDstar0Pi0g2,"ecalzDstar0Pi0g2/F");
   treenew->Branch("pxDstar0Pi0g2",&pxDstar0Pi0g2,"pxDstar0Pi0g2/F");
   treenew->Branch("pyDstar0Pi0g2",&pyDstar0Pi0g2,"pyDstar0Pi0g2/F");
   treenew->Branch("pzDstar0Pi0g2",&pzDstar0Pi0g2,"pzyDstar0Pi0g2/F");
   treenew->Branch("lmomDstar0Pi0g2",&lmomDstar0Pi0g2,"lmomDstar0Pi0g2/F");
   treenew->Branch("ncryDstar0Pi0g2",&ncryDstar0Pi0g2,"ncryDstar0Pi0g2/I");
   treenew->Branch("indexMcDstar0Pi0g2",&indexMcDstar0Pi0g2,"indexMcDstar0Pi0g2/I");

   //Dstar0 dau Gam
   treenew->Branch("ecalDstar0Gam",&ecalDstar0Gam,"ecalDstar0Gam/F");
   treenew->Branch("ecalxDstar0Gam",&ecalxDstar0Gam,"ecalxDstar0Gam/F");
   treenew->Branch("ecalyDstar0Gam",&ecalyDstar0Gam,"ecalyDstar0Gam/F");
   treenew->Branch("ecalzDstar0Gam",&ecalzDstar0Gam,"ecalzDstar0Gam/F");
   treenew->Branch("pxDstar0Gam",&pxDstar0Gam,"pxDstar0Gam/F");
   treenew->Branch("pyDstar0Gam",&pyDstar0Gam,"pyDstar0Gam/F");
   treenew->Branch("pzDstar0Gam",&pzDstar0Gam,"pzyDstar0Gam/F");
   treenew->Branch("lmomDstar0Gam",&lmomDstar0Gam,"lmomDstar0Gam/F");
   treenew->Branch("ncryDstar0Gam",&ncryDstar0Gam,"ncryDstar0Gam/I");
   treenew->Branch("indexMcDstar0Gam",&indexMcDstar0Gam,"indexMcDstar0Gam/I");

   //D0
   treenew->Branch("m0D0",&m0D0,"m0D0/F");
   treenew->Branch("massD0",&massD0,"massD0/F");
   treenew->Branch("pxD0",&pxD0,"pxD0/F");
   treenew->Branch("pyD0",&pyD0,"pyD0/F");
   treenew->Branch("pzD0",&pzD0,"pzD0/F");
   treenew->Branch("eD0",&eD0,"eD0/F");
   treenew->Branch("pcmsD0",&pcmsD0,"pcmsD0/F");
   treenew->Branch("chi2D0",&chi2D0,"chi2D0/F");
   treenew->Branch("dofD0",&dofD0,"dofD0/F");
   treenew->Branch("xD0",&xD0,"xD0/F");
   treenew->Branch("yD0",&yD0,"yD0/F");
   treenew->Branch("zD0",&zD0,"zD0/F");
   treenew->Branch("indexMcD0",&indexMcD0,"indexMcD0/I");
   treenew->Branch("isMcD0",&isMcD0,"isMcD0/I");
   treenew->Branch("m2pDalitzD0", &m2pDalitzD0, "m2pDalitzD0/F");
   treenew->Branch("m2mDalitzD0", &m2mDalitzD0, "m2mDalitzD0/F");
   treenew->Branch("m2zDalitzD0", &m2zDalitzD0, "m2zDalitzD0/F");
   treenew->Branch("stDalitzD0", &stDalitzD0, "stDalitzD0/I");
   treenew->Branch("mTotDalitzD0", &mTotDalitzD0, "mTotDalitzD0/F");
   treenew->Branch("chi2DalitzD0", &chi2DalitzD0, "chi2DalitzD0/F");
   treenew->Branch("dofDalitzD0", &dofDalitzD0, "dofDalitzD0/I");
	 
   //pr
   treenew->Branch("pxpr",&pxpr,"pxpr/F");
   treenew->Branch("pypr",&pypr,"pypr/F");
   treenew->Branch("pzpr",&pzpr,"pzpr/F");
   treenew->Branch("cthepr",&cthepr,"cthepr/F");
   treenew->Branch("deltadrcmompr",&deltadrcmompr,"deltadrcmompr/F");
   treenew->Branch("lundpr",&lundpr,"lundpr/I");
   treenew->Branch("kaonidpr",&kaonidpr,"kaonidpr/I");
   treenew->Branch("ndchpr",&ndchpr,"ndchpr/I");
   treenew->Branch("nphotpr",&nphotpr,"nphotpr/I");
   treenew->Branch("lundMcpr",&lundMcpr,"lundMcpr/I");
   treenew->Branch("indexMcpr",&indexMcpr,"indexMcpr/I");
   treenew->Branch("effCorMcpr",&effCorMcpr,"effCorMcpr/F");
   treenew->Branch("sEffCorMcpr",&sEffCorMcpr,"sEffCorMcpr/F");

   //Ks (from D0)
   treenew->Branch("massKs",&massKs,"massKs/F");
   treenew->Branch("pxKs",&pxKs,"pxKs/F");
   treenew->Branch("pyKs",&pyKs,"pyKs/F");
   treenew->Branch("pzKs",&pzKs,"pzKs/F");
   treenew->Branch("xKs",&xKs,"xKs/F");
   treenew->Branch("yKs",&yKs,"yKs/F");
   treenew->Branch("zKs",&zKs,"zKs/F");
   treenew->Branch("chi2Ks",&chi2Ks,"chi2Ks/F");
   treenew->Branch("dofKs",&dofKs,"dofKs/I");
   treenew->Branch("cosKs",&cosKs,"cosKs/F");
   treenew->Branch("isMcKs",&isMcKs,"isMcKs/I");
   treenew->Branch("indexMcKs",&indexMcKs,"indexMcKs/I");

   //KsPi1  (1st pi from Ks from D0)
   treenew->Branch("pxKsPi1",&pxKsPi1,"pxKsPi1/F");
   treenew->Branch("pyKsPi1",&pyKsPi1,"pyKsPi1/F");
   treenew->Branch("pzKsPi1",&pzKsPi1,"pzKsPi1/F");
   treenew->Branch("lundMcKsPi1",&lundMcKsPi1,"lundMcKsPi1/I");
   treenew->Branch("lundKsPi1",&lundKsPi1,"lundKsPi1/I");
   treenew->Branch("kaonidKsPi1",&kaonidKsPi1,"kaonidKsPi1/I");
   treenew->Branch("ndchKsPi1",&ndchKsPi1,"ndchKsPi1/I");
   treenew->Branch("indexMcD0KsPi1",&indexMcD0KsPi1,"indexMcD0KsPi1/I");
   treenew->Branch("effCorMcD0KsPi1",&effCorMcD0KsPi1,"effCorMcD0KsPi1/F");
   treenew->Branch("sEffCorMcD0KsPi1",&sEffCorMcD0KsPi1,"sEffCorMcD0KsPi1/F");

   //KsPi2 (2nd pi from Ks from D0)
   treenew->Branch("pxKsPi2",&pxKsPi2,"pxKsPi2/F");
   treenew->Branch("pyKsPi2",&pyKsPi2,"pyKsPi2/F");
   treenew->Branch("pzKsPi2",&pzKsPi2,"pzKsPi2/F");
   treenew->Branch("lundMcKsPi2",&lundMcKsPi2,"lundMcKsPi2/I");   
   treenew->Branch("lundKsPi2",&lundKsPi2,"lundKsPi2/I");
   treenew->Branch("kaonidKsPi2",&kaonidKsPi2,"kaonidKsPi2/I");
   treenew->Branch("ndchKsPi2",&ndchKsPi2,"ndchKsPi2/I"); 
   treenew->Branch("indexMcD0KsPi2",&indexMcD0KsPi2,"indexMcD0KsPi2/I");
   treenew->Branch("effCorMcD0KsPi2",&effCorMcD0KsPi2,"effCorMcD0KsPi2/F");
   treenew->Branch("sEffCorMcD0KsPi2",&sEffCorMcD0KsPi2,"sEffCorMcD0KsPi2/F");

   //D0Pi1 (1st pi from D0)
   treenew->Branch("pxD0Pi1",&pxD0Pi1,"pxD0Pi1/F");
   treenew->Branch("pyD0Pi1",&pyD0Pi1,"pyD0Pi1/F");
   treenew->Branch("pzD0Pi1",&pzD0Pi1,"pzD0Pi1/F");
   treenew->Branch("lundMcD0Pi1",&lundMcD0Pi1,"lundMcD0Pi1/I");
   treenew->Branch("lundD0Pi1",&lundD0Pi1,"lundD0Pi1/I");
   treenew->Branch("kaonidD0Pi1",&kaonidD0Pi1,"kaonidD0Pi1/I");
   treenew->Branch("ndchD0Pi1",&ndchD0Pi1,"ndchD0Pi1/I");
   treenew->Branch("indexMcD0Pi1",&indexMcD0Pi1,"indexMcD0Pi1/I");
   treenew->Branch("effCorMcD0Pi1",&effCorMcD0Pi1,"effCorMcD0Pi1/F");
   treenew->Branch("sEffCorMcD0Pi1",&sEffCorMcD0Pi1,"sEffCorMcD0Pi1/F");

   //D0Pi2 (2nd pi from D0)
   treenew->Branch("pxD0Pi2",&pxD0Pi2,"pxD0Pi2/F");
   treenew->Branch("pyD0Pi2",&pyD0Pi2,"pyD0Pi2/F");
   treenew->Branch("pzD0Pi2",&pzD0Pi2,"pzD0Pi2/F");
   treenew->Branch("lundMcD0Pi2",&lundMcD0Pi2,"lundMcD0Pi2/I");
   treenew->Branch("lundD0Pi2",&lundD0Pi2,"lundD0Pi2/I");
   treenew->Branch("kaonidD0Pi2",&kaonidD0Pi2,"kaonidD0Pi2/I");
   treenew->Branch("ndchD0Pi2",&ndchD0Pi2,"ndchD0Pi2/I");
   treenew->Branch("indexMcD0Pi2",&indexMcD0Pi2,"indexMcD0Pi2/I");
   treenew->Branch("effCorMcD0Pi2",&effCorMcD0Pi2,"effCorMcD0Pi2/F");
   treenew->Branch("sEffCorMcD0Pi2",&sEffCorMcD0Pi2,"sEffCorMcD0Pi2/F");






   // TTree R24
   //   TChain* chain= new TChain("D0");
   TChain* chain= new TChain(_dtype);
   TString filename;   
   TString filename_root="./validation-rel24/DK/reduced/";
   filename_root += "btdkpi_"+_d0mode+"_";    
   if (_sample=="on1"){
     filename=filename_root+"on1.root";
     cout << "filename : " << filename << endl;
     chain->Add(filename);}
   if (_sample=="on2"){
     filename=filename_root+"on2.root";
     cout << "filename : " << filename << endl;
     chain->Add(filename);}
   if (_sample=="on3"){
     filename=filename_root+"on3.root";
     cout << "filename : " << filename << endl;
     chain->Add(filename);}
   if (_sample=="on4"){
     filename=filename_root+"on4.root";
     cout << "filename : " << filename << endl;
     chain->Add(filename);}
   if (_sample=="on5"){
     filename=filename_root+"on5.root";
     cout << "filename : " << filename << endl;
     chain->Add(filename);}
   

   Int_t   runNumbernew;
   Int_t   upperIDnew;
   Int_t   lowerIDnew;
   chain->SetBranchAddress("runNumber",&runNumbernew);    
   chain->SetBranchAddress("upperID",&upperIDnew);
   chain->SetBranchAddress("lowerID",&lowerIDnew);
    
   chain->SetBranchStatus("*",0); 
   chain->SetBranchStatus("runNumber",1);    
   chain->SetBranchStatus("upperID",1);
   chain->SetBranchStatus("lowerID",1);
    
  
   Int_t nentriesnew=chain->GetEntries();  
   cout<<"nentriesnew(24)= "<<nentriesnew<<endl;


   Int_t runNumberarray[2000];

   Int_t runNumbernewprev=0;
   Int_t k=1;
   Int_t cont=0;


   for(Int_t i=0;i<nentriesnew;i++){
  //   for(Int_t i=0;i<3;i++){
     Int_t entrytree = LoadTree(i);
     if (entrytree < 0) break;
     chain->GetEntry(i);
     // cout<<"runNumbernew= "<<runNumbernew<<"  runNumbernewprev= "<<runNumbernewprev<< endl;


     if(runNumbernew!=runNumbernewprev){
       runNumberarray[k]=runNumbernew;
       //cout<<"runNumberarray["<<k<<"]= "<<runNumberarray[k]<<endl;
       k=k+1;
       //cout<<"kdins= "<<k<<endl;
       runNumbernewprev=runNumbernew;

   

     }  else{ 
       cont=cont+1;
       //cout<<"contador de iguales= "<<cont<<endl;
       continue; }
      
   }


   cout<<"k= "<<k<<endl;
   cout<<"Total iguales= "<<cont<<endl;

   runNumberarray[0]=k-1;
   cout<<"Total distintos: runNumberarray[0]="<<runNumberarray[0]<<endl;

   Int_t nb = 0;
   Int_t nbytes = 0; 
   Int_t control;
   Int_t cont24=0;
   Int_t cont18=0;
   Int_t conteq=0;
   Int_t jentry;

   //   Int_t totarray=runNumberarray[0];

   //cout<<"totarray"<<totarray<<endl;   

   for(Int_t j=1;j<runNumberarray[0];j++){      
   
     control=0;
     //cout<<"runNumberarray["<<j<<"]="<<runNumberarray[j]<<endl;
   
   if ( (j%100) == 0) {
	 cout << "Processed event number " << j << '\n';
       }


     cont24=cont24+1;

     for (jentry=0; jentry<nentries;jentry++) {
       Int_t ientry = LoadTree(jentry);
       if (ientry < 0) break;
       nb = fChain->GetEntry(jentry);   nbytes += nb;
       
       //      if(jentry==(nentries-1))break;
       //        if(runNumberarray[j]!=runNumber)continue;
       //        else { treenew->Fill(); 
       //        }
  
       //cout<<"runNumber= "<<runNumber<<endl;
       
 
       cont18=cont18+1;

       if(runNumberarray[j]!=runNumber){ 

	 if(control!=0)break;
	 else continue;
       } else { 
	 //cout<<"runNumberarray["<<j<<"]="<<runNumberarray[j]<<"  runNumber= "<<runNumber<<endl;
	 //cout<<"******************  FILL ****************************************************"<<endl;
	 treenew->Fill(); 
	 control=1;
       }
      
     }
     if(control==1) {
       conteq=conteq+1; 
       //cout<<"conteq= "<<conteq<<endl;
       //cout<<"bloc de runs iguals en (ultima jentry)[j,jentry] = "<<"["<<j<<","<<jentry<<"]"<<endl;
     }   
     continue;
   }
   file->Write();

   cout<<"cont24= "<<cont24<<endl;
   cout<<"cont18= "<<cont18<<endl;
   cout<<"conteq= "<<conteq<<endl;

}




