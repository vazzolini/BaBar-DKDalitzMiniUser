void btdkpi_production(Int_t sample_code, Int_t dmode_code,const char* dir=0,Int_t rel)
{
  btdkpi_production_sample(sample_code,dmode_code,dir,rel);
  gROOT->ProcessLine(".q");
}


void btdkpi_production_sample(Int_t sample_code, Int_t dmode_code=1,const char* dir=0,Int_t rel)
{
  // sample_code: 1) btdk,    2) btdsk,  3) btdpi,   4) btdspi,   
  //              5) chb,     6) chbk,   7) chbpi, 
  //              8) b0b0bar,
  //              9) ccbar1, 10) ccbar2, 11)ccbar34, 12) ccbar5
  //              13)uds12,   14)uds34,    15)uds5
  //              16) on1,    17) on2,  18) on3,  19) on4,  20) on5, 21) on  22) off    
  // dmode_code:  1) kspipi,  2) kskk 
  //
  //gSystem->Load("libPhysics");
  gROOT->ProcessLine(".L  btdkpi.C+");
  
  TString sample;
  if (sample_code==1) sample="btdk";
  else if (sample_code==2) sample="btdsk";
  else if (sample_code==3) sample="btdpi";
  else if (sample_code==4) sample="btdspi";
  else if (sample_code==5) sample="chb";
  else if (sample_code==6) sample="chbk";
  else if (sample_code==7) sample="chbpi";
  else if (sample_code==8) sample="b0b0bar";
  else if (sample_code==9) sample="ccbar1";
  else if (sample_code==10) sample="ccbar2";
  else if (sample_code==11) sample="ccbar34";
  else if (sample_code==12) sample="ccbar5";
  else if (sample_code==13) sample="uds12";
  else if (sample_code==14) sample="uds4";
  else if (sample_code==15) sample="uds5";
  else if (sample_code==16) sample="on1";
  else if (sample_code==17) sample="on2";
  else if (sample_code==18) sample="on3";
  else if (sample_code==19) sample="on4";
  else if (sample_code==20) sample="on5";
  else if (sample_code==20) sample="on6";
  else if (sample_code==20) sample="on7";
  else if (sample_code==21) sample="on";
  else if (sample_code==22) sample="off";
  else assert(0);
  
  TString dmode = (dmode_code==1)? "kspipi" : "kskk";
  const char* rela  = (rel==26) ? "analysis-26" : "analysis-30";
  cout << sample << " " << dmode << " " << dir << " " << rela<< endl;

  btdkpi t(sample,dmode,dir,rela);
  t.Loop();
  
}


 
