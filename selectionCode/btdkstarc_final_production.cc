//CHECK SAMPLE and CUTS
void btdkstarc_final_production()
{
  for(Int_t i=1; i<=13; i++){
    for(Int_t j=1; j<=3; j++){
      for(Int_t k=0; k<=1;k++){
	if(i!=7) continue;  //sample
	if(j!=3) continue;   //decay
	if(k!=1) continue;   //CS
	btdkstarc_final_production_sample(i,j,k);
      }
    } 
  }
  // gROOT->ProcessLine(".q");

}


void btdkstarc_final_production_sample(Int_t sample_code, Int_t decay_code, Int_t isCS)
{
 
  //gSystem->Load("libPhysics");
  gROOT->ProcessLine(".L  btdkstarc_final.C+");
  
  TString sample;
  TString decay;
  Bool_t CS;

  if (sample_code==1) sample="btdkstarc";
  else if (sample_code==2) sample="chb";
  else if (sample_code==3) sample="b0b0bar";
  else if (sample_code==4) sample="ccbar";
  else if (sample_code==5) sample="uds";
  else if (sample_code==6) sample="On";
  else if (sample_code==7) sample="On1234";
  else if (sample_code==8) sample="On5";
  else if (sample_code==9) sample="Off";
  else if (sample_code==10) sample="Off1234";
  else if (sample_code==11) sample="Off5";
  else if (sample_code==12) sample="chbNR";
  else if (sample_code==13) sample="btda1";
 

  if (decay_code==1) decay="kspi";
  else if (decay_code==2) decay="kpi0";
  else if (decay_code==3) decay="rho0pi";

  if(isCS==0) CS=kFALSE;
  else if(isCS==1) CS=kTRUE;

  cout << sample << endl;

  btdkstarc_final t(decay,"kspipi",sample,"analysis-30",CS);
  for(Int_t i=1;i<=112;i++){
    if(i!=1 && i!=2 && i!=112 && i!=100) continue; //usual
    // if(i!=100) continue;

    t.LoopBest(i);
    if(i!=100) t.Fits(i);
  }
}


 
