class OptVar{

private:
  TString _dmode, _sigType, _basePath, _outPath, _cut;
  double _variable, _variableMin, _variableMax;
  TString _files[10];
  TString _mcTypes[10];
  int _numMcTypes, _nbins;
  TH1F* _histos[10];
  double _scfa[10];
  TH1F* _bkg;
  TH1F* _sig;
  TH1F* _S;
  TH1F* _sigE;
  TH1F* _bkgE;
  TString _thevariable;
  double _mycut;

  TCanvas* _c;
  TString _option;

public:
  void SetConditions( TString sigType, int cut , TString thevariable, double mycut);
  void LoadFiles( int cut );
  TString itostr( int ival );
  TString dtostr( double ival );
  void FillHistograms( int i );
  void Loop();
  void InitHistos();
  void Print();
  void BuildSignificance( );
  void BuildEfficiency( );
  double giveMeSig( );
  double giveMeEff( );
  void OpenOutput( );
  void CloseOutput( );
  void PlotHistos(int i);

};

void OptVar::SetConditions( TString sigType, int cut, TString thevariable, double mycut, TString option){
  _option=option;
  _mycut=mycut;
  _thevariable=thevariable;  
  _dmode    = "kspipi";
  _sigType  = sigType;
  _basePath = "/u/br/neus/gamma09/workspace/DKDalitzMiniUser/selectionCode/gamma/ASCII_nocutSigdlKs/";
  _cut      = itostr( cut );
  _outPath  = "results/OptVar_"+_thevariable+"_"+ _sigType + "_" + _dmode + "_" + _cut +"_"+_option+".ps";
  //_nbins = 500;
  _nbins = 8000;
 
  if(_thevariable=="Fisher"){
  _variableMin = -1.5;
  _variableMax = 1.5;

  }else if (_thevariable =="SigdlKs"){
    //OK igual que -1000, 4000
    //  _variableMin = -10.;
    //_variableMax = 1000.;
  _variableMin = -100.;
  _variableMax = 3000.;

  }else cout<<"Wrong variable"<<endl;

  double lumiOn      = 425.472;
  double lumiSig     = 117608.482;
  double lumiChb     = 1288.6582;
  double lumiB0b0bar = 1305.4454;
  double lumiUds     = 778.863;
  double lumiCCbar   = 868.1107;

  _mcTypes[0] = "uds"    ; _scfa[0] = lumiOn/lumiUds    ;
  _mcTypes[1] = "ccbar"  ; _scfa[1] = lumiOn/lumiCCbar  ;
  _mcTypes[2] = "chb"    ; _scfa[2] = lumiOn/lumiChb    ;
  _mcTypes[3] = "b0b0bar"; _scfa[3] = lumiOn/lumiB0b0bar;
  _mcTypes[4] = _sigType ; _scfa[4] = lumiOn/lumiSig    ;
  _numMcTypes = 5;


  LoadFiles( );
  InitHistos( );

  //Print();
}

void OptVar::Print( )
{
  cout<< "Dmode -- " << _dmode << endl;
  cout<< "sigType -- " << _sigType << endl;
  cout<< "cut -- " << _cut << endl;
  for ( int i = 0; i<_numMcTypes ; i++ ){
    cout<< "mytypes -- " << _mcTypes[i] << endl;
    cout<< "files -- " << _files[i] << endl;
  }

}

void OptVar::LoadFiles( ){
  for ( int i = 0; i<_numMcTypes ; i++ )
    if(_thevariable=="Fisher")    _files[i] = _basePath + "btdkpi_d0k_" + _dmode + "_" + _mcTypes[i] + "_Bbest_Cut" + _cut + ".dat";
    else if(_thevariable=="SigdlKs") _files[i] = _basePath + "btdkpi_d0k_" + _dmode + "_" + _mcTypes[i] + "_Bbest_Cut" + _cut + "_SigEfi.dat";
}

TString OptVar::itostr( int ival ) 
{
  char buffer[20];
  sprintf( buffer, "%i" , ival );
  return TString( buffer );
}

TString OptVar::dtostr( double ival ) 
{
  char buffer[20];
  sprintf( buffer, "%f" , ival );
  return TString( buffer );
}

void OptVar::FillHistograms( int i )
{
  ifstream infile;
  infile.open ( _files[i], ios::in );
  if( infile.fail() ) {
    cout << "Error opening the file " << _files[i] <<endl;
    return;
  }
  cout << "Reading file: " << _files[i] << endl;
  double tmp(0.);
  TString tmp2 = ""; 
  int count(0); 

  if(_thevariable=="Fisher"){
    while(!infile.eof()){ 
      
      infile >> tmp >> tmp;
      infile >> tmp >> tmp >> tmp >> tmp;
      infile >> tmp >> tmp >> tmp >> tmp; 
      infile >> tmp >> tmp >> tmp >> tmp;
      infile >> tmp ;
      infile >> _variable >> tmp >> tmp >> tmp ; 
      infile >> tmp >> tmp2 >> tmp;
      
      _histos[i] -> Fill( _variable );
      count++;
    }
  }else if(_thevariable=="SigdlKs"){
    while(!infile.eof()){ 
      infile >> _variable;
      
      _histos[i] -> Fill( _variable );
      count++;
    }
  }

  infile.close();
}

void OptVar::InitHistos( )
{
  for( int i = 0; i<_numMcTypes ; i++ )
    _histos[i] = new TH1F( _thevariable+"_" + _mcTypes[i], _thevariable+" " + _mcTypes[i], _nbins, _variableMin, _variableMax );
}

void OptVar::PlotHistos(int i )
{
  gStyle->SetOptStat("nemruo");
     _c=new TCanvas();
     _c->cd();
     _histos[i]->Draw("");
     _c->Print(_outPath);
}

void OptVar::Loop( )
{
  OpenOutput();
  
  for( int i = 0; i< _numMcTypes ; i++ )
    FillHistograms( i );

  for( int i = 0; i< _numMcTypes ; i++ )
    PlotHistos( i );

  _bkg = new TH1F( _thevariable+"-Bkg", _thevariable+" bkg", _nbins, _variableMin, _variableMax );
  _sig = new TH1F( _thevariable+"-Sig", _thevariable+" sig", _nbins, _variableMin, _variableMax );
  _S = new TH1F( "Significance", "Significance", _nbins, _variableMin, _variableMax );
  _sigE = new TH1F( "sigEfficiency", "Efficiency", _nbins, _variableMin, _variableMax );
  _bkgE = new TH1F( "bkgEfficiency", "Efficiency", _nbins, _variableMin, _variableMax );

  _bkg -> Add( _histos[0], _scfa[0] );
  _bkg -> Add( _histos[1], _scfa[1] );
  _bkg -> Add( _histos[2], _scfa[2] );
  _bkg -> Add( _histos[3], _scfa[3] );
  _sig -> Add( _histos[4], _scfa[4] );

  BuildSignificance();
  BuildEfficiency();

  _c = new TCanvas();
  _c -> cd();
  gPad -> SetLogy( false );
  gPad -> Modified( );
  _S -> Draw("");
  _c -> Print( _outPath );
  delete _c;

  _c = new TCanvas();
  _c -> cd();
  gPad -> SetLogy( false );
  gPad -> Modified( );
  _sigE -> SetLineColor(2);
  _bkgE -> SetLineColor(3);
  _sigE -> Draw("");
  _bkgE -> Draw("SAME");
  TLine sigmax( _S -> GetBinCenter( _S -> GetMaximumBin( ) ), 1.,_S -> GetBinCenter( _S -> GetMaximumBin( ) ), 0. );
  sigmax . Draw("SAME");
  _c -> Print( _outPath );
  delete _c;

  _c = new TCanvas();
  _c -> cd();
  gPad -> SetLogy( true );
  gPad -> Modified( );
  _sig -> SetLineColor(2);
  _bkg -> SetLineColor(3);
  _bkg -> Draw("");
  _sig -> Draw("SAME");
  _c -> Print( _outPath );
  delete _c;

  cout << "El maximo de significancia esta en " << _S -> GetBinCenter( _S -> GetMaximumBin( ) ) << endl;
  cout << "La eficiencia de señal en el maximo de significancia es " << _sigE -> GetBinContent( _S -> GetMaximumBin( ) ) << endl;
  cout << "La eficiencia de bkg en el maximo de significancia es " << _bkgE -> GetBinContent( _S -> GetMaximumBin( ) ) << endl;

  double sigcut=giveMeSig(_mycut);
  double effcut= giveMeEff(_mycut,"sig");

  cout<<"La Sig para el corte "+dtostr(_mycut)+" es:" <<sigcut<<endl;
  cout<<"La efi para el corte "+dtostr(_mycut)+" es:" <<effcut<<endl;

  for( int i = 0; i<_numMcTypes ; i++ )
    delete _histos[i];

  delete _bkg;
  delete _sig;
  delete _S;
  delete _sigE;

  CloseOutput();
}

void OptVar::BuildSignificance()
{
  for( int i = 1; i <= _nbins; i++ )
    _S -> SetBinContent( i, giveMeSig( i ) );
}

void OptVar::BuildEfficiency()
{
  for( int i = 1; i <= _nbins; i++ ){
    _sigE -> SetBinContent( i, giveMeEff( i, "sig" ) );
    _bkgE -> SetBinContent( i, giveMeEff( i, "bkg" ) );
  }
}

double OptVar::giveMeSig( int j )
{
  double sigArea = 0.;
  double bkgArea = 0.;
  for( int i = j; i <= _nbins; i++ ){
    sigArea += ( double ) _sig -> GetBinContent( i );
    bkgArea += ( double ) _bkg -> GetBinContent( i );
  }

  if ( sigArea == 0. && bkgArea == 0.) return 0.;
  else return sigArea / sqrt( sigArea + bkgArea );
}


double OptVar::giveMeEff( int j, TString type )
{
  if( type == "sig" ){
    double sigArea  = 0.;
    double sigArea2 = 0.;
    for( int i = 1; i <= _nbins; i++ )
      sigArea += ( double ) _sig -> GetBinContent( i );
    
    for( int i = j; i <= _nbins; i++ )
      sigArea2 += ( double ) _sig -> GetBinContent( i );
    
    return sigArea2 / sigArea;
  }
  else{
    double bkgArea  = 0.;
    double bkgArea2 = 0.;
    for( int i = 1; i <= _nbins; i++ )
      bkgArea += ( double ) _bkg -> GetBinContent( i );
    
    for( int i = j; i <= _nbins; i++ )
      bkgArea2 += ( double ) _bkg -> GetBinContent( i );
    
    return bkgArea2 / bkgArea;
  }
}


void OptVar::OpenOutput( )
{
  _c = new TCanvas();
  _c -> Print( _outPath + "[");
  delete _c;
}

void OptVar::CloseOutput( )
{
  _c = new TCanvas();
  _c -> Print( _outPath + "]");
  delete _c;
}

//exec
void OptVar(int thecut, TString variable, double mycut, TString option)
{
  OptVar var;
  var . SetConditions( "btdk",thecut , variable, mycut, option);
  var. Loop();
 
}
