 
 

void btdkstarc_production()
{
  for(Int_t i=2; i<=10; i++){
    for(Int_t k=1; k<=2; k++){
      if(i!=7) continue;   //sample
      if(k!=2) continue;   //CS
      btdkstarc_production_sample(i,k);
    } 
  }
  gROOT->ProcessLine(".q");

}


void btdkstarc_production_sample(Int_t sample_code,Int_t isCS)
{
 
  //gSystem->Load("libPhysics");
  gROOT->ProcessLine(".L  btdkstarc.C+");
  
  TString sample;
  Bool_t CS;
  if (sample_code==1) sample="btdkstarc";
  else if (sample_code==2) sample="chb";
  else if (sample_code==3) sample="b0b0bar";
  else if (sample_code==4) sample="ccbar";
  else if (sample_code==5) sample="uds";
  else if (sample_code==6) sample="On5";
  else if (sample_code==7) sample="On1234";
  else if (sample_code==8) sample="Off5";
  else if (sample_code==9) sample="Off1234";
  else if (sample_code==10) sample="btda1";
  else assert(0);
  if(isCS==1) CS=kFALSE;
  else if(isCS==2) CS=kTRUE;  

  //  TString dmode = (dmode_code==1)? "kspipi" : "kskk";
  //TString anal  = (rel==26) ? "analysis-26" : "analysis-30";

  cout << sample << endl;
  btdkstarc t(sample,"kspipi",0,"analysis-30",CS);
  t.Loop();

}


 
