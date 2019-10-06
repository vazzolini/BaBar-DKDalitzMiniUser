// -- calculate Fisher coefficients
// -- Dieter Best (best@slac.stanford.edu) 30.April.2001

#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <math.h>
//#include <strstream.h>
#include <string>
using namespace std;

#include "TROOT.h"
#include "TRint.h"
#include "TChain.h"
#include "TCanvas.h"
#include "TStyle.h"
#include "TF1.h"
#include "TH1.h"
#include "TH2.h"
#include "TFile.h"
#include "TTree.h"
#include "TString.h"
#include "TSystem.h"
#include "TDirectory.h"
#include "TVectorD.h"
#include "TMatrixD.h"
#include "TFormula.h"
#include "TTreeFormula.h"


void usage(char * name);

void usage(char * name) { 
  cerr << "Usage: " << name << " -S <signalfile> -B <backgroundfile> -T <treename> -V <branchnames> -E <#events> -D <debug>" << endl;
  exit (2);
} 


TH1F * getFisherValue(TTree * , TString, TObjArray & , TVectorD &, Double_t ) ;

TH1F * getFisherValue(TTree * ntp, TString name , TObjArray & inForm, TVectorD & w, Double_t w0) {
  TTreeFormula* ttf;

  TH1F F1hist(name,"Fisher",100,-2,2);
  Int_t nbytes = 0;
  for (Int_t i = 0; i< ntp->GetEntries(); i++) {
    nbytes = ntp->GetEntry(i);
    Float_t F1 = w0 ; 
    for ( Int_t j=0; j< w.GetNoElements() ; j++) { 
      ttf = ( TTreeFormula* ) inForm[ j ];
      ttf->UpdateFormulaLeaves();
      F1 += w(j)*fabs( (Double_t)( ttf->EvalInstance(0) ) );
    }
    F1hist.Fill(F1);
  }
  return new TH1F(F1hist);
}


Int_t getMean(TTree *, Int_t, TObjArray & , TVectorD &, TMatrixD & );

Int_t getMean(TTree * ntp, Int_t nEvents, TObjArray & inForm, TVectorD & x, TMatrixD & c){
  Int_t bytes = 0;

  x.Zero();

  TTreeFormula* ttf;

  Int_t ncandidates = 0 ;
  for (Int_t n = 0; n < nEvents; n++)
    {
      bytes = ntp->GetEntry(n);

      ncandidates++;
      for (Int_t i = 0; i < x.GetNoElements(); i++) { 
	ttf = ( TTreeFormula* ) inForm[ i ];
	ttf->UpdateFormulaLeaves();
	x(i) +=( fabs( (Double_t)( ttf->EvalInstance(0) ) ) - x(i) ) / Double_t(ncandidates);
      }
    }
  c.Zero();

  TTreeFormula* ttfK;
  TTreeFormula* ttfL;

  ncandidates=0;
  for (Int_t n = 0; n < nEvents; n++) {

    bytes = ntp->GetEntry(n);

    ncandidates++;
    for ( Int_t k = 0; k < x.GetNoElements(); k++ ) { 
      for ( Int_t l = 0; l < x.GetNoElements(); l++ ) {
	ttfK = ( TTreeFormula* ) inForm[ k ];
	ttfL = ( TTreeFormula* ) inForm[ l ];
	ttfK->UpdateFormulaLeaves();
	ttfL->UpdateFormulaLeaves();
	c(k,l) += ( ( fabs( (Double_t)( ttfK->EvalInstance(0) ) ) - x(k) ) *
		    ( fabs( (Double_t)( ttfL->EvalInstance(0) ) ) - x(l) ) - c(k,l) ) / Double_t(ncandidates) ;
      }
    }
  }

  return 0;
}



TROOT root("Fisher","Determine Fisher discriminant coefficients");

int main(int argc, char *argv[]){

  Int_t opt     =  0 ;
  Int_t errflg  =  0 ;
  extern char * optarg;

  TString signalfile = "";
  TString backgroundfile = "";
  TString treename = "";
  TString branchnames = "";
  Int_t debug = 0 ;
  Int_t nEvents1 = 0 ; 
  Int_t nEvents2 = 0 ; 
  Int_t nEvents  = 0 ; 

  while ((opt = getopt(argc, argv, "S:B:T:V:E:D:")) != EOF){
    switch (opt) {
    case 'S':
      signalfile = optarg;      
      break;
    case 'B':
      backgroundfile = optarg;      
      break;
    case 'T':
      treename = optarg;      
      break;
    case 'V':
      branchnames = optarg;      
      break;
    case 'D':
      debug = atoi(optarg);      
      break;
    case 'E':
      nEvents = atoi(optarg);      
      break;
    default:
      errflg++;
      break;
    };
  };

  if ( errflg != 0 || signalfile == "" || backgroundfile == "" ) usage(argv[0]);

  std::string file;

  // read signal
  signalfile.ReplaceAll(":"," ");
  TChain* ntp1 = new TChain( treename );
  std::stringstream sigFilesStream( signalfile.Data() );
  while ( sigFilesStream >> file )
    ntp1->Add( file.c_str() );

  //TFile signal(signalfile);
  //TTree * ntp1 = (TTree*)signal.Get(treename);
  if ( ntp1 <= 0 ) { 
    cout << " signal: cannot find tree " << treename << endl;
    return 1;
  } 

  // read background
  backgroundfile.ReplaceAll(":"," ");
  TChain* ntp2 = new TChain( treename );
  std::stringstream bkgFilesStream( backgroundfile.Data() );
  while ( bkgFilesStream >> file )
    ntp2->Add( file.c_str() );

  //TFile background(backgroundfile);
  //TTree * ntp2 = (TTree*)background.Get(treename);
  if ( ntp2 <= 0 ) { 
    cout << " background: cannot find tree " << treename << endl;
    return 1;
  } 

  if( nEvents > 0 ) {
    nEvents1 = nEvents;
    nEvents2 = nEvents;
  } else {
    nEvents1 = (Int_t)ntp1->GetEntries();
    nEvents2 = (Int_t)ntp2->GetEntries();
  }

  // get branchnames
  branchnames.ReplaceAll(":"," "); branchnames += " ";
  std::istringstream inStream((char *) branchnames.Data());
  TObjArray inForm1, inForm2;
  TString inName;
  while ( inStream >> inName ){
    inForm1.Add( new TTreeFormula("Signal"    ,inName.Data(),ntp1) );
    inForm2.Add( new TTreeFormula("Background",inName.Data(),ntp2) );
    //cout << inName.Data() << endl;
  }

  Int_t nInputs = inForm1.GetEntries();
  if ( nInputs <= 0 ) { 
    cout << " number of inputs has to be > 0, is " << nInputs << endl;
    return 1;
  } 

  // get mean and covariance matrix
  TVectorD xm1(nInputs);
  TMatrixD cm1(nInputs, nInputs);
  getMean(ntp1, nEvents1, inForm1, xm1, cm1);

  TVectorD xm2(nInputs);
  TMatrixD cm2(nInputs, nInputs);
  getMean(ntp2, nEvents2, inForm2, xm2, cm2);

  TVectorD d = xm2; d -= xm1; 
  TMatrixD V = cm1; V += cm2;
  TMatrixD W = V.Invert();
  TVectorD w = d; w *=W;

  //Double_t max = w.NormInf();
  Double_t wLength = sqrt(w.Norm2Sqr());
  w *= 1./wLength;

  //  determine constant offset such that mean F = 0 
  Double_t w0 = 0;
  for ( Int_t i = 0 ; i < nInputs; i++ ) { 
    w0 -= w(i)*(xm1(i)+xm2(i))/2.;
    //w0 -= w(i)*xm1(i);
    //w0 -= w(i)*xm2(i);
  } 

  // print
  cout << endl;
  cout << " signalvector of means     = " ;
  for ( Int_t i = 0 ; i<nInputs; i++) cout << xm1(i) << " " ; cout<< endl;

  cout << " backgroundvector of means = " ;
  for ( Int_t i = 0 ; i<nInputs; i++) cout << xm2(i) << " " ; cout<< endl;

  cout << " differences between mean  = " ;
  for ( Int_t i = 0 ; i<nInputs; i++) cout << d(i) << " " ; cout<< endl;

  //cout << " the Fisher coefficients   = " ; 
  //for ( Int_t i = 0 ; i<nInputs; i++) cout << w(i) << " " ; cout<< endl;
  //for ( Int_t i = 0 ; i<nInputs; i++) cout << sqrt(W(i,i)) << " " ; cout<< endl;

  cout << " Fisher offset             = " << w0 << endl;
  cout << " normalized Fisher coeff   = " ;
  for ( Int_t i = 0 ; i<nInputs; i++) cout << w(i) << " " ; cout << endl;
  cout << endl;

  // store
  ofstream FisherCoeff("FisherCoeff.txt");
  FisherCoeff << w0 << " " ;
  for ( Int_t i = 0 ; i<nInputs; i++) FisherCoeff << w(i) << " " ; 
  FisherCoeff.close();

  // make and store Fisher histograms
  TH1F * F1Hist = getFisherValue(ntp1, "ntp1", inForm1, w, w0);
  TH1F * F2Hist = getFisherValue(ntp2, "ntp2", inForm2, w, w0);

  TFile out("FisherCoeff.root","recreate");
  F1Hist->Write();
  F2Hist->Write();
  out.Close();

  return 0;
}
