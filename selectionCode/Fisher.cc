// -- calculate Fisher coefficients
// -- Dieter Best (best@slac.stanford.edu) 30.April.2001

#include <iostream.h>
#include <fstream.h>
#include <iomanip.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

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

void usage(char * name);
void usage(char * name) { 
  cerr << "Usage: " << name << "-S <signalfile> -B <backgroundfile>" << endl;
  exit (2);
} 

TROOT root("Fisher","Determine Fisher discriminant coefficients");

int main(int argc, char *argv[]){

  const Int_t nVars = 4;
  Float_t v[8];

  Int_t opt     =  0 ;
  Int_t errflg  =  0 ;
  extern char * optarg;
  TString signalfile = "";
  TString backgroundfile = "";
  while ((opt = getopt(argc, argv, "S:B:")) != EOF){
    switch (opt) {
    case 'S':
      signalfile = optarg;      
      break;
    case 'B':
      backgroundfile = optarg;      
      break;
    default:
      errflg++;
      break;
    };
  };
  if (errflg!=0) usage(argv[0]);
  
  if ( signalfile == "" || backgroundfile == "" ) usage(argv[0]);

  TFile signal(signalfile);
  TTree *ntp1 = (TTree*)signal.Get("filter");
  if ( ntp1 <= 0 ) { 
    cout << " no filter object in signal file ..." << endl;
    return 1;
  } 
  ntp1->SetBranchAddress("variables",v);

  TFile background(backgroundfile);
  TTree *ntp2 = (TTree*)background.Get("filter2");
  if ( ntp2 <= 0 ) { 
    cout << " no filter object in background file ..." << endl;
    return 1;
  } 

  Float_t v[7];
  TTree * filteredTree = new TTree("filter","store candidates after preselection");
  filteredTree->Branch("variables",v,"R2/F:cosT/F:cosB/F:cosQ/F:dE/F:mB/F:Cat/I");

  ntp2->SetBranchAddress("variables",v);

  Int_t nbytes = 0;

  signal.cd();

  TVectorD xm1(nVars);
  TMatrixD cm1(nVars,nVars);
  for ( Int_t i=0; i<nVars; i++) {
    xm1(i)=0.0;
    for ( Int_t j=0; j<nVars; j++) {
      cm1(i,j)=0.0;
    }
  }
  Int_t ncandidates1 = 0 ;
  for (Int_t i=0; i< ntp1->GetEntries(); i++) {
    nbytes = ntp1->GetEntry(i);
    ncandidates1++;
    for ( Int_t k=0; k<nVars; k++ ) {
      xm1(k) = xm1(k) + (v[k]-xm1(k))/Float_t(ncandidates1); 
    }
  }
  ncandidates1 = 0 ; 
  for (Int_t i=0; i< ntp1->GetEntries(); i++) {
    nbytes = ntp1->GetEntry(i); // -- Fetch data from ntuple
    ncandidates1++;
    for ( Int_t l=0; l<nVars; l++ ) {
      for ( Int_t k=0; k<nVars; k++ ) {
	cm1(k,l) = cm1(k,l) + ( (v[k]-xm1(k))*(v[l]-xm1(l)) - cm1(k,l) ) / Float_t(ncandidates1);
      }
    }
  }

  background.cd();

  TVectorD xm2(nVars);
  TMatrixD cm2(nVars,nVars);
  for ( Int_t i=0; i<nVars; i++) {
    xm2(i)=0.0;
    for ( Int_t j=0; j<nVars; j++) {
      cm2(j,i)=0.0;
    }
  }

  Int_t ncandidates2 = 0 ; 
  for (Int_t i=0; i< ntp2->GetEntries(); i++) {
    nbytes = ntp2->GetEntry(i); // -- Fetch data from ntuple
    ncandidates2++;
    for ( Int_t k=0; k<nVars; k++ ) {
      xm2(k) = xm2(k) + (v[k]-xm2(k))/Float_t(ncandidates2); 
    }
  }
  ncandidates2 = 0 ; 
  for (Int_t i=0; i< ntp2->GetEntries(); i++) {
    nbytes = ntp2->GetEntry(i);
    ncandidates2++;
    for ( Int_t l=0; l<nVars; l++ ) {
      for ( Int_t k=0; k<nVars; k++ ) {
	cm2(k,l) = cm2(k,l) + ( (v[k]-xm2(k))*(v[l]-xm2(l)) - cm2(k,l) ) / Float_t(ncandidates2);
      }
    }
  }

  TVectorD d = xm2; d -= xm1; 
  TMatrixD V = cm1; V += cm2;
  TMatrixD W = V.Invert();
  TVectorD w = d; w *=W;

  cout << " signalvector of means     = " ;
  for ( int i = 0 ; i<nVars; i++) cout << xm1(i) << " " ; cout<< endl;

  cout << " backgroundvector of means = " ;
  for ( int i = 0 ; i<nVars; i++) cout << xm2(i) << " " ; cout<< endl;

  cout << " differences between mean  = " ;
  for ( int i = 0 ; i<nVars; i++) cout << d(i) << " " ; cout<< endl;

  cout << " the Fisher coefficients   = " ; 
  for ( int i = 0 ; i<nVars; i++) cout << w(i) << " " ; cout<< endl;
  //for ( int i = 0 ; i<nVars; i++) cout << sqrt(W(i,i)) << " " ; cout<< endl;

  Float_t max = w.NormInf();
  Float_t wLength = sqrt(w.Norm2Sqr());
  w *= 1./wLength;

  //  determine constant offset such that mean F = 0 
  Float_t w0 = 0;
  for ( Int_t i = 0 ; i < nVars; i++ ) { 
    w0 -= w(i)*(xm1(i)+xm2(i))/2.;
    //w0 -= w(i)*xm1(i);
    //w0 -= w(i)*xm2(i);
  } 

  cout << " Fisher offset                  = " << w0 << endl;
  cout << " normalized Fisher coefficients = " ;
  for ( int i = 0 ; i<nVars; i++) cout << w(i) << " " ; cout << endl;

  ofstream FisherCoeff("FisherCoeff.txt");
  FisherCoeff << w0 << " " ;
  for ( int i = 0 ; i<nVars; i++) FisherCoeff << w(i) << " " ; 
  FisherCoeff.close();

  TH1F * F1hist = new TH1F("F1","F1",100,-2,2);
  for (Int_t i=0; i< ntp1->GetEntries(); i++) {
    nbytes = ntp1->GetEntry(i);
    Float_t F1 = w0 ; 
    for ( Int_t j=0; j<nVars ; j++) { 
      F1 += w(j)*v[j];
    }
    F1hist->Fill(F1);
  }

  TH1F * F2hist = new TH1F("F2","F2",100,-2,2);
  for (Int_t i=0; i< ntp2->GetEntries(); i++) {
    nbytes = ntp2->GetEntry(i);
    Float_t F2 = w0 ; 
    for ( Int_t j=0; j<nVars ; j++) { 
      F2 += w(j)*v[j];
    }
    F2hist->Fill(F2);
  }

  TFile out("FisherCoeff.root","recreate");
  F1hist->Write();
  F2hist->Write();
  out.Close();

  return 0;
}
