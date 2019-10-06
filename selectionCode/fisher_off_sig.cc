#include "TH2.h"
#include "TStyle.h"
#include "TCanvas.h"
#include <iostream.h>
#include <iomanip.h>
#include <fstream.h>
#include <strstream.h>
#include <TLine.h>
#include <TLegend.h>
#include <TLegendEntry.h>
#include <TFile.h>

void prova(TString channel="D0K", TString dstar0mode="d0", TString d0mode="kspipi",Int_t cut=-999)
{
  gROOT->SetStyle("Plain");
  gStyle->SetStatColor(10);
  gStyle->SetOptStat(0);
  gStyle->SetOptFit(0);

  gStyle->SetOptStat(00000);
  gROOT->SetStyle("Plain");
  gStyle->SetOptFit(0000000);

  enum cutvar {mes,demk,fisherDK};
  cutvar type;
  TH1F* his[20];  
  TString sig_type;
  char typeStr[10];
  char cut_code_str[10];
 
  TString filename1="ASCII/btdkpi_d0pi_kspipi_off_Bbest_Cut1.root";
  TFile* file1 = new TFile(filename1,"read");
  TH1F* his1 = (TH1F*)file1->Get( "fisherDK" );
  his1->SetTitle( "Fisher discriminant for no cut on cos#theta" );
  his1->GetXaxis()->SetTitle( "Fisher discriminant (Cut 1)" );
  his1->GetYaxis()->SetTitle( "Counts / 0.05" );
  his1->SetFillColor(0);
  his1->SetLineColor(1);

  TString filename2="ASCII/btdkpi_d0pi_kspipi_btdpi_Bbest_Cut1.root";
  TFile* file2 = new TFile(filename2,"read");
  TH1F* his2 = (TH1F*)file2->Get("fisherDK");
  his2->Scale( 0.0055 );
  his2->SetFillColor(0);
  his2->SetLineColor(2);

  TCanvas *canvas=new TCanvas;

  his1->Draw();
  his2->Draw( "SAME" );

  TString name_plot="ASCII/queFuncioni";
  canvas->Print(TString(name_plot)+".gif");
  canvas->Print(TString(name_plot)+".eps");
}
