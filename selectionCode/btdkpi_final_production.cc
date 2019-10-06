#include <iostream.h>

void btdkpi_final_production(Int_t init_sample=1,Int_t final_sample=16,Int_t dmode=0,Int_t rel_code)
{
  for (Int_t sample_code=init_sample;sample_code<=final_sample;sample_code++) {
    //if (sample_code==9) continue;
    //if (sample_code==10) continue;
    //if (sample_code==11) continue;
    //if (sample_code==14) continue;
    //if (sample_code==16) continue;
    if (dmode==0) {
      for (Int_t idmode=1;idmode<=2;idmode++) {
	for (Int_t iddstarmode=1;iddstarmode<=3;iddstarmode++) { 
	  //if (iddstarmode==2 || iddstarmode==3) continue;
	
	  if(iddstarmode==1 && (sample_code==2 || sample_code==4)) continue;
	  if(iddstarmode==2 && (sample_code==1 || sample_code==3)) continue;
	  if(iddstarmode==3 && (sample_code==1 || sample_code==3)) continue;
	  btdkpi_final_production_sample(sample_code,idmode,iddstarmode,rel);
	}
      }
    } else {
      for (Int_t iddstarmode=1;iddstarmode<=3;iddstarmode++) { 
	//if (iddstarmode==2 || iddstarmode==3) continue;
	  if(iddstarmode==1 && (sample_code==2 || sample_code==4)) continue;
	  if(iddstarmode==2 && (sample_code==1 || sample_code==3)) continue;
	  if(iddstarmode==3 && (sample_code==1 || sample_code==3)) continue;
	btdkpi_final_production_sample(sample_code,dmode,iddstarmode,rel_code);
      }
    }
  }
  gROOT->ProcessLine(".q");
}


void btdkpi_final_production_sample(Int_t sample_code, Int_t dmode_code=1, Int_t ddstarmode_code=1, Int_t rel_code=1)
{
  // sample_code: 1) btdk, 2) btdsk, 3) btdpi, 4) btdspi,   
  //              5) chb, 6) chbk, 7) chbpi, 
  //              8) b0b0bar, 
  //              9) bbbar, 10) bbbark, 11) bbbarpi,
  //              12) ccbar, 13) uds, 14) udsccbar, 15) on, 16) off 
  // dmode_code:  1) kspipi, 2) kskk
  // ddstarmode_code: 1) D0, 2) D*0(D0pi0), 3) D*0(D0gam)

  //gSystem->Load("libPhysics");
  gROOT->ProcessLine(".L  btdkpi_final.C+");
  TString korpi;
  TString sample;
  if (sample_code==1) sample="btdk";
  else if (sample_code==2) sample="btdsk";
  else if (sample_code==3) sample="btdpi";
  else if (sample_code==4) sample="btdspi";
  else if (sample_code==5) sample="chb";
  else if (sample_code==6) sample="chbk";
  else if (sample_code==7) sample="chbpi";
  else if (sample_code==8) sample="b0b0bar";
  else if (sample_code==9) sample="bbbar";
  else if (sample_code==10) sample="bbbark";
  else if (sample_code==11) sample="bbbarpi";
  else if (sample_code==12) sample="ccbar";
  else if (sample_code==13) sample="uds";
  else if (sample_code==14) sample="udsccbar";
  else if (sample_code==15) sample="on";
  else if (sample_code==16) sample="off";
  else assert(0);
  
  TString dmode = (dmode_code==1)? "kspipi" : "kskk";

  TString dtype = (ddstarmode_code==1)? "D0" : "Dstar0";
  TString dstar0mode = (ddstarmode_code==2)? "d0pi0" : ( (ddstarmode_code==3)? "d0gam" : "d0" ) ; 

  TString rel=(rel_code==1)? "analysis-26" : "analysis-30";

  cout << "Processing sample : "<< sample << " for dmode: " << dmode << endl;

  if (dtype=="D0" && dstar0mode!="d0") return;
  
  for (Int_t i=1;i<=112;i++){
    //  if (i>2 && i!=100) continue;
    //  if (i>2 && i!=100 && i!=112) continue;
    // if (i!=100 ) continue;
    //   if (i>1) continue;
     if (i>2) continue;
    
    char num[10];
    sprintf(num,"%d",i);
    cout << "num cut = " << num << endl;
    
    btdkpi_final* t = new btdkpi_final(dtype,dstar0mode,dmode,sample,rel);
    for(Int_t j=1; j<=2;j++){
    
      if(j==1 && (sample_code==3 || sample_code==4 || sample_code==6))continue;
      if(j==2 && (sample_code==1 || sample_code==2 || sample_code==7))continue;
      korpi=(j==1)? "k" : "pi";
      t->LoopBest(korpi,i);
      t->Fits("pi",i);    
      t->Fits("k",i);  
      ////  to evaluate D0 mass
      // t->Loop("k",3);
      // t->Loop("pi",3);
      
    
    }  
    delete t;
  }
  
}

