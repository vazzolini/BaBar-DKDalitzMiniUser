#include "TH2.h"
#include "TStyle.h"
#include "TCanvas.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <TLine.h>
#include <TLegend.h>
#include <TLegendEntry.h>
#include <TFile.h>
#include <THStack.h>

int main ( int argc, char** argv )
{
  gROOT->SetStyle("Plain");
  gStyle->SetStatColor(10);
  gStyle->SetOptStat(0);
  gStyle->SetOptFit(0);

  gStyle->SetOptStat(00000);
  gROOT->SetStyle("Plain");
  gStyle->SetOptFit(0000000);

//   double lumiOn      = 350.5726;
//   double lumiSig     = 6326.847;
//   double lumiCHB     = 1010.1309;
//   double lumiB0B0bar = 1004.3891;
//   double lumiUds     = 337.02201;
//   double lumiCCbar   = 454.7677;

  double lumiOn      = 425.472;
  double lumiSig     = 117608.482;
  double lumiCHB     = 1288.6582;
  double lumiB0B0bar = 1305.4454;
  double lumiUds     = 780.385;
  double lumiCCbar   = 868.1107;


  //  std::string head = "data/btdkpi_d0k_kspipi_";
  std::string head = "ASCII//btdkpi_d0k_kspipi_";
  std::string tail = "_Bbest_Cut" + std::string( argv[ 1 ] ) + ".root";

  TString filename1 = head + "btdk" + tail;
  TFile* file1 = new TFile(filename1,"read");
  TH1F* his1 = (TH1F*)file1->Get( "fisherDK" );
  his1->Scale( lumiOn / lumiSig );

  TString filename2 = head + "chb" + tail;
  TFile* file2 = new TFile(filename2,"read");
  TH1F* his2 = (TH1F*)file2->Get("fisherDK");
  his2->Scale( lumiOn / lumiCHB );

  TString filename3 = head + "b0b0bar" + tail;
  TFile* file3 = new TFile(filename3,"read");
  TH1F* his3 = (TH1F*)file3->Get("fisherDK");
  his3->Scale( lumiOn / lumiB0B0bar );

  TString filename4 = head + "ccbar" + tail;
  TFile* file4 = new TFile(filename4,"read");
  TH1F* his4 = (TH1F*)file4->Get("fisherDK");
  his4->Scale( lumiOn / lumiCCbar );

  TString filename5 = head + "uds" + tail;
  TFile* file5 = new TFile(filename5,"read");
  TH1F* his5 = (TH1F*)file5->Get("fisherDK");
  his5->Scale( lumiOn / lumiUds );


  //std::string title = "Fisher discriminant for no cut on cos#theta";
  std::string title = "Fisher discriminant";
  std::string label = "Fisher discriminant (Cut " + std::string( argv[ 1 ] ) + ");Counts / 0.05";

  THStack* stack1 = new THStack( "stack1", ( title + ";" + label ).c_str() );
  THStack* stack2 = new THStack( "stack2", title.c_str() );

  stack1->Add( his1 );
  stack1->Add( his2 );
  stack1->Add( his3 );
  stack2->Add( his4 );
  stack2->Add( his5 );

  TCanvas* canvas = new TCanvas( "c", "Canvas" );

  if ( atoi( argv[ 1 ] ) == 100 )
    {
      stack1->Draw();
      stack2->Draw( "SAME" );
    }
  else
    {
      stack2->Draw();
      stack1->Draw( "SAME" );
    }

  canvas->Print( "fisherDK.png" );
}
