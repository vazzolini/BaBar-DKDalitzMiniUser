void makePdfFitsKst(TString varname)
{
  gROOT->ProcessLine(".L btdkstarc_final.C+");

  Int_t cut_code(0);
  assert(varname=="mes" || varname=="demk" || varname=="fisherDK");

  makeFits("kspipi",kFALSE,"signal",varname);
  makeFits("kspipi",kFALSE,"udsccbar",varname);
  if (varname=="mes" || varname=="demk") 
    makeFits("kspipi",kFALSE,"bbbar",varname);
  //
  makeFits("kspipi",kTRUE,"signal",varname);
  makeFits("kspipi",kTRUE,"udsccbar",varname);
  if (varname=="mes" || varname=="demk") 
    makeFits("kspipi",kTRUE,"bbbar",varname);
  
  gROOT->ProcessLine(".q");
}


void makeFits(TString d0mode, Bool_t isCS, TString sig_type, TString varname)
{
  TString _sig_type(sig_type);
  Int_t cut_code(0);
  if (varname=="mes") cut_code = (sig_type=="signal")? 1 : 112 ;
  else if (varname=="demk") cut_code = (sig_type=="signal")? 2 : 112 ;
  else if (varname=="fisherDK") cut_code=1;
  else assert(0);

  TString kstarmode = isCS? "rho0pi" : "kspi";
  if (!isCS && sig_type=="signal") _sig_type="btdkstarc"; 
  if ( isCS && sig_type=="signal") _sig_type="chbR";
  
  btdkstarc_final t(kstarmode,d0mode,_sig_type,"analysis-30",isCS,kFALSE);
  t.Fits(cut_code,varname); 
}
