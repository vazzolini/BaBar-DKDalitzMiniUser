void makePdfFits(TString varname)
{
  gROOT->ProcessLine(".L btdkpi_final.C+");

  Int_t cut_code(0);
  assert(varname=="mes" || varname=="demk" || varname=="fisherDK");

  makeFits("kspipi","k","signalk",varname);
  makeFits("kspipi","k","udsccbar",varname);
  if (varname=="mes" || varname=="demk") 
    makeFits("kspipi","k","bbbar",varname);
  //
  makeFits("kspipi","pi","signalpi",varname);
  makeFits("kspipi","pi","udsccbar",varname);
  if (varname=="mes" || varname=="demk") 
    makeFits("kspipi","pi","bbbar",varname);
  //
  makeFits("kskk","k","signalk",varname);
  makeFits("kskk","k","udsccbar",varname);
  if (varname=="mes" || varname=="demk") 
    makeFits("kskk","k","bbbar",varname);
  //
  makeFits("kskk","pi","signalpi",varname);
  makeFits("kskk","pi","udsccbar",varname);
  if (varname=="mes" || varname=="demk") 
    makeFits("kskk","pi","bbbar",varname);
  
  gROOT->ProcessLine(".q");
}


void makeFits(TString d0mode, TString KorPi, TString sig_type, TString varname)
{
  TString _sig_type(sig_type);
  Int_t cut_code(0);
  if (varname=="mes") cut_code = sig_type.BeginsWith("signal")? 1 : 112 ;
  else if (varname=="demk") cut_code = sig_type.BeginsWith("signal")? 2 : 112 ;
  else if (varname=="fisherDK") cut_code=1;
  else assert(0);

  if (sig_type=="signalk") _sig_type="btdk"; else if (sig_type=="signalpi") _sig_type="btdpi";
  btdkpi_final t("D0","d0",d0mode,_sig_type,"analysis-30",kFALSE); 
  t.Fits(KorPi,cut_code,varname); 
  if (sig_type=="signalk") _sig_type="btdsk"; else if (sig_type=="signalpi") _sig_type="btdspi";
  btdkpi_final t("Dstar0","d0pi0",d0mode,_sig_type,"analysis-30",kFALSE); 
  t.Fits(KorPi,cut_code,varname); 
  btdkpi_final t("Dstar0","d0gam",d0mode,_sig_type,"analysis-30",kFALSE); 
  t.Fits(KorPi,cut_code,varname); 
}
