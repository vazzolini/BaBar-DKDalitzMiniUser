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

void compdataMC(char* d0mode="kspipi",Int_t cut_code=-999, TString flag="normal"){

  char* kstarc_decay = "kspi" ;
  //char* d0mode = "kspipi" ;
  //  char* d0mode = "kskk" ;
  Int_t col_style = 2 ;

  gStyle->SetOptStat(00000) ;
  gROOT->SetStyle("Plain") ;
  gStyle->SetOptFit(0000000) ;


     //Float_t lumi_signal = (54000.+156000.+83000.+252000.+333000.)/2.378e-6 ;  //mal calculada la seccio eficac,
//   Float_t lumi_uds = (83946000.+122700000.+66894000.+209150000.+221686000.)/2.09 ;
//   Float_t lumi_ccbar = (82226000.+156242000.+77184000.+147144000.+128402000.)/1.3 ;
//   Float_t lumi_b0b0bar = (69238000.+103164000.+50556000.+163084000.+166372000.)/0.55 ;
//   Float_t lumi_chb = (69596000.+102142000.+46698000.+168312000.+168824000.)/0.55 ;
//   Float_t lumi_data = 20816.5e3+60769.2e3+32150.6e3+101843.3e3+133805.4e3 ;


  Float_t lumi_uds = 780.3847;
  Float_t lumi_ccbar =868.1108;
  Float_t lumi_b0b0bar = 1 305.4454;
  Float_t lumi_chb = 1 288.6581;
  Float_t lumi_data =428.991;

  //kspipi
  if(d0mode=="kspipi") Float_t lumi_signal =387093.7024;
  else if(d0mode=="kskk")   Float_t lumi_signal =2452140.191;




  Float_t sc0=lumi_data/lumi_signal ;
  Float_t sc1=lumi_data/lumi_uds ;
  Float_t sc2=lumi_data/lumi_ccbar ;
  Float_t sc3=lumi_data/lumi_b0b0bar ;
  Float_t sc4=lumi_data/lumi_chb ;
  Float_t sc5=lumi_data/lumi_data ;

  cout<<"lumi Signal= "<<lumi_signal<< " scale factor= "<<sc0<<endl ;
  cout<<"lumi uds   = "<<lumi_uds<<" scale factor= "<<sc1<<endl ;
  cout<<"lumi ccbar = "<<lumi_ccbar<<" scale factor= "<<sc2<<endl ;
  cout<<"lumi B0    = "<<lumi_b0b0bar<<" scale factor= "<<sc3<<endl ;
  cout<<"lumi Bch   = "<<lumi_chb<<" scale factor= "<<sc4<<endl ;
  cout<<"lumi DATA  = "<<lumi_data<<" scale factor= "<<sc5<<endl ;

  gStyle->SetStatColor(10) ;
  gStyle->SetOptStat(0) ;
  gStyle->SetOptFit(0) ;
  
  enum cutvar {mes,demk,fisherDK,massVectorc,massVectorcReso,end} ;
  cutvar type ;

  TH1F* his[20];  

    for (type=massVectorc;type<=massVectorc;type++){
  //  for (type=demk;type<=demk;type++){
    
    char typeStr[10];
    char cut_code_str[10];

    if(cut_code<0){
      if (type==fisherDK) {
	sprintf(typeStr,"fisherDK");
	sprintf(cut_code_str,"Cut1");
      } else if (type==demk) {
	sprintf(typeStr,"demk");
	sprintf(cut_code_str,"Cut2");
      } else if (type==mes) {
	sprintf(typeStr,"mes");
	sprintf(cut_code_str,"Cut1");	
      } else if (type==massVectorc) {
	sprintf(typeStr,"massVectorc");
	sprintf(cut_code_str,"Cut100");
      }
      else assert(0);
    }
    else if (cut_code==0){
      sprintf(cut_code_str,"Cut0");
      if (type==fisherDK) {
	sprintf(typeStr,"fisherDK");
      } else if (type==demk) {
	sprintf(typeStr,"demk");
      } else if (type==mes) {
	sprintf(typeStr,"mes");
      } else if (type==massVectorcReso) {
	sprintf(typeStr,"massVectorcReso");
      } else assert(0);
    }
 
    TString sdec = "btdkstarc_" ;

    TString name = "ASCII/"+sdec+TString(kstarc_decay)+"_"+d0mode+"_btdkstarc_Bbest_"+cut_code_str+".root" ;
    TFile* file = new TFile(name,"read");
    cout<<"name_signal = "<<name<<endl;
    TH1F* his0 = (TH1F*)file->Get(typeStr);
    his0->SetLineColor(14);
    his0->SetFillColor(14);
    his0->SetLineColor(col_style);
    his0->SetFillColor(col_style);

    TString name_chb = "ASCII/"+sdec+TString(kstarc_decay)+"_"+d0mode+"_chb_Bbest_"+cut_code_str+".root" ;
    TFile* file_chb = new TFile(name_chb,"read");
    cout<<"name_chb = "<<name_chb<<endl;
    TH1F* his4 = (TH1F*)file_chb->Get(typeStr);

    TString name_bneu = "ASCII/"+sdec+TString(kstarc_decay)+"_"+d0mode+"_b0b0bar_Bbest_"+cut_code_str+".root" ;
    TFile* file_bneu = new TFile(name_bneu,"read");
    cout<<"name_bneu = "<<name_bneu<<endl;
    TH1F* his3 = (TH1F*)file_bneu->Get(typeStr);

    TString name_uds = "ASCII/"+sdec+TString(kstarc_decay)+"_"+d0mode+"_uds_Bbest_"+cut_code_str+".root" ;
    TFile* file_uds = new TFile(name_uds,"read");
    cout<<"name_uds = "<<name_uds<<endl;
    TH1F* his1 = (TH1F*)file_uds->Get(typeStr);

    TString name_ccbar = "ASCII/"+sdec+TString(kstarc_decay)+"_"+d0mode+"_ccbar_Bbest_"+cut_code_str+".root" ;
    TFile* file_ccbar = new TFile(name_ccbar,"read");
    cout<<"name_ccbar = "<<name_ccbar<<endl;
    TH1F* his2 = (TH1F*)file_ccbar->Get(typeStr);

    TString name_data = "ASCII/"+sdec+TString(kstarc_decay)+"_"+d0mode+"_On_Bbest_"+cut_code_str+".root" ;
    TFile* file_data = new TFile(name_data,"read");
    cout<<"name_data = "<<name_data<<endl;
    TH1F* his5 = (TH1F*)file_data->Get(typeStr);
     
    his0->Scale(sc0);
    his1->Scale(sc1);
    his2->Scale(sc2);
    his3->Scale(sc3);
    his4->Scale(sc4);
    his5->Scale(sc5);
    
    his5->SetMinimum(0.);

    char title[255];
    sprintf(title,"%s distribution DATA vs MC",typeStr);
    cout << "title = " << title<<endl;

    THStack* stack = new THStack("data_mc",title);

    TCanvas *canvas = new TCanvas;
    canvas->cd();

    his5->SetMarkerStyle(20); 
    his5->SetMarkerSize(0.8); 
    his5->SetLineWidth(2); 
    his5->Draw("E1");

    stack->Add(his1);
    stack->Add(his2);
    stack->Add(his3);
    stack->Add(his4);
    stack->Add(his0);
    stack->Draw("SAME");
  
    his5->Draw("E1SAME");

  //   his5->SetMarkerStyle(20); 
//     his5->SetMarkerSize(0.8); 
//     his5->SetLineWidth(2); 
//     his5->Draw("");
//     stack->Add(his1);
//     stack->Add(his2);
//     stack->Add(his3);
//     stack->Add(his4);
//     stack->Add(his0);
//     stack->Draw("E1SAME");
 

 
    if (type==fisherDK){  
      stack->GetXaxis()->SetTitle(" Fisher");
    }else if (type==demk){  
      stack->GetXaxis()->SetTitle(" #DeltaE (GeV)");
    }else if (type==mes){  
      stack->GetXaxis()->SetTitle("m_{ES} (GeV/c^{2})");
    }else if (type==massVectorcReso){  
      stack->GetXaxis()->SetTitle("m_{ES} (GeV/c^{2})");
    }else if (type==massVectorc){  
      stack->GetXaxis()->SetTitle("m_{K*} (GeV/c^{2})");
    }

    cout<<"LOOPING"<<endl;
    
    TLegend *leg;
    
    leg = new TLegend(0.75,0.8,1,1) ;
    
    leg->SetBorderSize(0);
    leg->SetTextFont(132);
    leg->SetHeader("Legenda:");
    leg->SetFillColor(10);
    
    leg->AddEntry(his1,"uds","f");
    leg->AddEntry(his2,"c#bar{c}","f");
    leg->AddEntry(his3,"B^{0}#bar{B^{0}}","f");
    leg->AddEntry(his4,"B^{+}B^{-}","f");

    if (kstarc_decay==TString("kspi") && d0mode==TString("kspipi")) {
      leg->AddEntry(his0,"B^{+}#rightarrowD^{0}K^{*+}  K_{S}#pi^{+}","f");
    } else if (kstarc_decay==TString("kpi0")&&d0mode==TString("kspipi")) {
      leg->AddEntry(his0,"B^{+}#rightarrowD^{0}K^{*+}  K_{+}#pi^{0}","f");
    } else if (kstarc_decay==TString("rho0pi")&&d0mode==TString("kspipi")) {
      leg->AddEntry(his0,"B^{+}#rightarrowD^{0}a1^{*+}  #rho^{0}#pi^{+}","f");
    }

    leg->Draw("SAME");

    TString name_plot = "ASCII/stack_"+sdec+TString(kstarc_decay)+"_"+d0mode+"_Bbest_"+typeStr+"_"+flag+".eps" ;
    cout<<"name_plot = "<<name_plot<<endl;
    canvas->Print(name_plot);
    // delete canvas[j];
  }
}
