
void inclDstar_final_production()
{
  for(Int_t i=1; i<=4; i++){
    for(Int_t j=1; i<=2; j++){
      inclDstar_final_production_sample(i,j);
    }
  } 
  gROOT->ProcessLine(".q");

}


void inclDstar_final_production_sample(Int_t sample_code, Int_t d0mode_code)
{
 
  //gSystem->Load("libPhysics");
  gROOT->ProcessLine(".L inclDstar_final.C+");
  
  TString sample;
  TString d0mode;
  if (sample_code==1) sample="data5";
  else if (sample_code==2) sample="data1234";
  else if (sample_code==3) sample="data";
  else if (sample_code==4) sample="signal";
  d0mode = (d0mode_code==1)? "kspipi": "kskk";

  else assert(0);
  
  cout << sample << endl;

  inclDstar_final t(d0mode,sample);
  for(Int_t i=1;i<=112;i++){
    if(i>2 && i!=112)continue;
    t.LoopBest(i);
    t.Fits(i);
  }
}


 
