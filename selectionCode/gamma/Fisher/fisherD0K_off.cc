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
#include <TROOT.h>

int main ( int argc, char** argv )
{
  gROOT->SetStyle("Plain");
  gStyle->SetStatColor(0);
  gStyle->SetOptStat(0);
  gStyle->SetOptFit(0);

  //  std::string head = "data/btdkpi_d0k_kspipi_";
  std::string head = "ASCII/btdkpi_d0k_kspipi_";
  std::string tail = "_Cut0.root";

  TString filename1 = head + "btdk" + tail;
  TFile* file1 = new TFile(filename1,"read");
  TH1F* his1 = (TH1F*)file1->Get( "fisherDK" );
  his1->SetLineColor( 2 );
  his1->Scale( 1. / his1->Integral() );

  TString filename2 = head + "chb" + tail;
  TFile* file2 = new TFile(filename2,"read");
  TH1F* his2 = (TH1F*)file2->Get("fisherDK");
  his2->SetLineColor( 3 );
  his2->Scale( 1. / his2->Integral() );

  TString filename3 = head + "b0b0bar" + tail;
  TFile* file3 = new TFile(filename3,"read");
  TH1F* his3 = (TH1F*)file3->Get("fisherDK");
  his3->SetLineColor( 4 );
  his3->Scale( 1. / his3->Integral() );

  TString filename4 = head + "ccbar" + tail;
  TFile* file4 = new TFile(filename4,"read");
  TH1F* his4 = (TH1F*)file4->Get("fisherDK");
  his4->SetLineColor( 6 );
  his4->Scale( 1. / his4->Integral() );

  TString filename5 = head + "uds" + tail;
  TFile* file5 = new TFile(filename5,"read");
  TH1F* his5 = (TH1F*)file5->Get("fisherDK");
  his5->SetLineColor( 7 );
  his5->Scale( 1. / his5->Integral() );

  std::string title = "Fisher discriminant for no cut on cos#theta";
  std::string label = "Fisher discriminant (Cut 0);Area = 1";

  THStack* stack = new THStack( "stack", ( title + ";" + label ).c_str() );

  TLegend* legend = new TLegend( .65, .70, .95, .95 );

  legend->AddEntry( his1, "Signal" );
  legend->AddEntry( his2, "B+B-" );
  legend->AddEntry( his3, "B0B0bar" );
  legend->AddEntry( his4, "ccbar" );
  legend->AddEntry( his5, "uds" );

  stack->Add( his1 );
  stack->Add( his2 );
  stack->Add( his3 );
  stack->Add( his4 );
  stack->Add( his5 );

  TCanvas* canvas = new TCanvas( "c", "Canvas" );

  stack->Draw( "nostack" );
  legend->Draw();

  canvas->Print( "fisherDk.png" );
}
