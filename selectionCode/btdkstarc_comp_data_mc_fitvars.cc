////LEGENDA :
////flag=1 plot dei vari contributi di bkg a mES
////flag=2: generic MC deltae bkg contribution
////flag=3: plot di massa del D0(gauss+p1)  //modified
////flag=5: Dalitz plot
//#include "NStack.cc"
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

void btdkstarc_comp_data_mc_fitvars(Int_t cut_code=-999,Int_t isCS=1,Int_t isPrecut=0){
  char* kstarc_decay=(isCS==0)? "kspi" : "rho0pi";
  char* d0mode="kspipi";
  //isCS = 1 (kTRUE), 0(kFALSE)
  //  char* kstarc_decay="kspi"; 
  //char* d0mode="kspipi";

  Int_t col_style= (kstarc_decay=="kspi") ? 2:3;

  gStyle->SetOptStat(00000);
  gROOT->SetStyle("Plain");

  gStyle->SetOptFit(0000000);
  
 
  // Float_t lumi0=44917.24; // Br=6.1x10^-4 (central) 
  //Float_t lumi_signal= 44917.24; // Br=6.1x10^-4 (central) 
  //Float_t lumi_signal= (isCS==0)? 306000./(100.*0.023366974) : 172.67329; // Br=6.1x10^-4 (central) 
  //Float_t lumi_signal= 250954.0551; // Br=6.1x10^-4 (central) 
  //Float_t lumi_signal= (isCS==0)? 306000./(100.*0.023366974) : 203.5106; // Br=6.1x10^-4 (central) 
  Float_t lumi_signal= (isCS==0)? 306000./(100.*0.023) : 814.0; // Br=6.1x10^-4 (central) 
  //  Float_t lumi_signal= (isCS==0)? 306000./(100.*0.023) : 814.0; // Br=6.1x10^-4 (central) 
  Float_t lumi_uds=(isCS==0)? 165.3 : 163.1;
  Float_t lumi_ccbar=(isCS==0)? 356.1 : 357.0;
  Float_t lumi_b0b0bar=(isCS==0)? 865.5 : 842.1 ;
  Float_t lumi_chb=(isCS==0)? 815.4 : 814.0 ;
  Float_t lumi_data=288.50;
  //

  Float_t sc0=lumi_data/lumi_signal;
  Float_t sc1=lumi_data/lumi_uds;
  Float_t sc2=lumi_data/lumi_ccbar;
  Float_t sc3=lumi_data/lumi_b0b0bar;
  Float_t sc4=lumi_data/lumi_chb;
  Float_t sc5=lumi_data/lumi_data;
  
  cout<<"lumi Signal= "<<lumi_signal<< " scale factor= "<<sc0<< endl;
  cout<<"lumi uds   = "<<lumi_uds<<" scale factor= "<<sc1<<endl;
  cout<<"lumi ccbar = "<<lumi_ccbar<<" scale factor= "<<sc2<<endl;
  cout<<"lumi B0    = "<<lumi_b0b0bar<<" scale factor= "<<sc3<<endl;
  cout<<"lumi Bch   = "<<lumi_chb<<" scale factor= "<<sc4<<endl;
  cout<<"lumi DATA  = "<<lumi_data<<" scale factor= "<<sc5<<endl;
    
  //gStyle->Reset();
  
  //gPad->SetFillColor(10);
  //gPad->SetBorderMode(0);
  gStyle->SetStatColor(10);
  gStyle->SetOptStat(0);
  gStyle->SetOptFit(0);
  
  enum cutvar {mes,demk,fisherDK,massVectorcReso};
  cutvar type;
  TH1F* his[20];  
  for (type=mes;type<=massVectorcReso;type++){
        
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
      } else if (type==massVectorcReso) {
	sprintf(typeStr,"massVectorcReso");
	sprintf(cut_code_str,"Cut1");
      }
	else assert(0);
    }
    else if (cut_code==0){
      if (type==fisherDK) {
	sprintf(typeStr,"fisherDK");
	sprintf(cut_code_str,"Cut0");
      } else if (type==demk) {
	sprintf(typeStr,"demk");
	sprintf(cut_code_str,"Cut0");
      } else if (type==mes) {
	sprintf(typeStr,"mes");
	sprintf(cut_code_str,"Cut0");
      } else if (type==massVectorcReso) {
	sprintf(typeStr,"massVectorcReso");
	sprintf(cut_code_str,"Cut0");
      } else assert(0);
    }
    TString sdec=(isCS==0)? "btdkstarc_" : "btda1_";
    
    TString name=(isCS==0 && isPrecut==0)? "ASCII/"+sdec+TString(kstarc_decay)+"_"+d0mode+"_btdkstarc_Bbest_"+cut_code_str+".root" : (isCS==1 && isPrecut==0)? "ASCII/"+sdec+TString(kstarc_decay)+"_"+d0mode+"_chbR_Bbest_"+cut_code_str+".root" : (isCS==0 && isPrecut==1)? "ASCII/Precut_"+TString(kstarc_decay)+"_"+d0mode+"_btdkstarc.root" : (isCS==1 && isPrecut==1)? "ASCII/Precut_"+TString(kstarc_decay)+"_"+d0mode+"_chbR.root" : "out";
    TFile* file = new TFile(name,"read");
    cout<<"name_signal = "<<name<<endl;
    TH1F* his0 = (TH1F*)file->Get(typeStr);
    his0->SetLineColor(14);
    his0->SetFillColor(14);
    his0->SetLineColor(col_style);
    his0->SetFillColor(col_style);

    TString name_chb=(isPrecut==0)? "ASCII/"+sdec+TString(kstarc_decay)+"_"+d0mode+"_chb_Bbest_"+cut_code_str+".root" : "ASCII/Precut_"+TString(kstarc_decay)+"_"+d0mode+"_chb.root" ;
    TFile* file_chb = new TFile(name_chb,"read");
    cout<<"name_chb = "<<name_chb<<endl;
    TH1F* his4 = (TH1F*)file_chb->Get(typeStr);
    //his4->SetLineColor(4);
    //his4->SetFillColor(4);

    //TString name_chbNR=(isPrecut==0)? "ASCII/"+sdec+TString(kstarc_decay)+"_"+d0mode+"_chbNR_Bbest_"+cut_code_str+".root" : ;
    //TFile* file_chbNR = new TFile(name_chbNR,"read");
    //cout<<"name_chbNR = "<<name_chbNR<<endl;
    //TH1F* his4nr = (TH1F*)file_chbNR->Get(typeStr);
    
    TString name_bneu=(isPrecut==0)? "ASCII/"+sdec+TString(kstarc_decay)+"_"+d0mode+"_b0b0bar_Bbest_"+cut_code_str+".root" : "ASCII/Precut_"+TString(kstarc_decay)+"_"+d0mode+"_b0b0bar.root";
    TFile* file_bneu = new TFile(name_bneu,"read");
    cout<<"name_bneu = "<<name_bneu<<endl;
    TH1F* his3 = (TH1F*)file_bneu->Get(typeStr);
    //his3->SetLineColor(5);
    //his3->SetFillColor(5);

    TString name_uds=(isPrecut==0)? "ASCII/"+sdec+TString(kstarc_decay)+"_"+d0mode+"_uds_Bbest_"+cut_code_str+".root" : "ASCII/Precut_"+TString(kstarc_decay)+"_"+d0mode+"_uds.root";
    TFile* file_uds = new TFile(name_uds,"read");
    cout<<"name_uds = "<<name_uds<<endl;
    TH1F* his1 = (TH1F*)file_uds->Get(typeStr);

    TString name_ccbar=(isPrecut==0)? "ASCII/"+sdec+TString(kstarc_decay)+"_"+d0mode+"_ccbar_Bbest_"+cut_code_str+".root" : "ASCII/Precut_"+TString(kstarc_decay)+"_"+d0mode+"_ccbar.root";
    TFile* file_ccbar = new TFile(name_ccbar,"read");
    cout<<"name_ccbar = "<<name_ccbar<<endl;
    TH1F* his2 = (TH1F*)file_ccbar->Get(typeStr);

    TString name_data=(isPrecut==0)? "ASCII/"+sdec+TString(kstarc_decay)+"_"+d0mode+"_On_Bbest_"+cut_code_str+".root" : "ASCII/Precut_"+TString(kstarc_decay)+"_"+d0mode+"_On.root";
    TFile* file_data = new TFile(name_data,"read");
    cout<<"name_data = "<<name_data<<endl;
    TH1F* his5 = (TH1F*)file_data->Get(typeStr);

    char xtitle[40];    
    sprintf(xtitle,"%s GeV/c^{2}",typeStr);
    cout << "titolo X = "<< xtitle<<endl; 

    TCanvas *canvas=new TCanvas;
    canvas->cd();
 

    his0->Scale(sc0);
    his1->Scale(sc1);
    his2->Scale(sc2);
    his3->Scale(sc3);
    his4->Scale(sc4);
    //his4nr->Scale(sc4);
    his5->Scale(sc5);
    
    his5->SetMinimum(0.);
      //hist5->SetRange(demk,-1.2,1.2);
    
    
    
    
    char title[255];
    sprintf(title,"%s distribution DATA vs MC",typeStr);
    cout << "title = " << title<<endl;
  
    THStack* stack=new THStack("data_mc",title);
  
    stack->Add(his1);
    stack->Add(his2);
    stack->Add(his3);
    stack->Add(his4);
    //stack->Add(his4nr);
    stack->Add(his0);
    //
    his5->Draw("E1");
    stack->Draw("SAME");
    his5->SetMarkerStyle(20); 
    his5->SetMarkerSize(0.8); 
    his5->SetLineWidth(2); 
    his5->Draw("E1SAME");
    

    if (type==fisherDK){  
      stack->GetXaxis()->SetTitle(" Fisher");
      //stack->GetYaxis()->SetTitle("Events/0.084");
    }
    if (type==demk){  
      stack->GetXaxis()->SetTitle(" #DeltaE (GeV)");
      //stack->GetYaxis()->SetTitle("Events/0.0032 GeV");
    }
    if (type==mes){  
      stack->GetXaxis()->SetTitle("m_{ES} (GeV/c^{2})");
      //stack->GetYaxis()->SetTitle("Events/0.002 GeV/c^{2}");
    }
    if (type==massVectorcReso){  
      stack->GetXaxis()->SetTitle("m_{ES} (GeV/c^{2})");
      //stack->GetYaxis()->SetTitle("Events/0.002 GeV/c^{2}");
    }
   
    //    data->Draw("E1same");

    //---disegna legenda
    TLegend *leg;
    //if (type==mes) leg = new TLegend(0.15,0.60,0.40,0.90);
    //else leg = new TLegend(0.65,0.7,1,1) ;
    leg = new TLegend(0.75,0.8,1,1) ;

    //    TLegend *leg=new TLegend(0.12,0.65,0.37,0.90);
    //    leg->SetMargin();
    leg->SetBorderSize(0);
    leg->SetTextFont(132);
    leg->SetHeader("Legenda:");
    leg->SetFillColor(10);
    
    leg->AddEntry(his1,"uds","f");
    leg->AddEntry(his2,"c#bar{c}","f");
    leg->AddEntry(his3,"B^{0}#bar{B^{0}}","f");
    leg->AddEntry(his4,"B^{+}B^{-}","f");
    //leg->AddEntry(his4nr,"B^{+}B^{-}, NR","f");

    if (kstarc_decay==TString("kspi")&&d0mode==TString("kspipi")) {
      //leg->AddEntry(his4nr,"B^{+}#rightarrowD^{0}K^{*+}  K_{S}#pi^{+} NR","f");
      leg->AddEntry(his0,"B^{+}#rightarrowD^{0}K^{*+}  K_{S}#pi^{+}","f");
    }
    else if (kstarc_decay==TString("kpi0")&&d0mode==TString("kspipi")) {
      //leg->AddEntry(his4nr,"B^{+}#rightarrowD^{0}K^{*+}  K_{+}#pi^{0} NR","f");
      leg->AddEntry(his0,"B^{+}#rightarrowD^{0}K^{*+}  K_{+}#pi^{0}","f");
    }
    else if (kstarc_decay==TString("rho0pi")&&d0mode==TString("kspipi")) {
      //leg->AddEntry(his4nr,"B^{+}#rightarrowD^{0}K^{*+}  K_{+}#pi^{0} NR","f");
      leg->AddEntry(his0,"B^{+}#rightarrowD^{0}a1^{*+}  #rho^{0}#pi^{+}","f");
    }

    //    leg->AddEntry(his5,"DATA","f");

    leg->Draw();

    TString name_plot="ASCII/stack_"+sdec+TString(kstarc_decay)+"_"+d0mode+"_Bbest_"+cut_code_str+"_"+typeStr;
    name_plot += "_Br_central";
    //name_plot += "_Br_-0.5sigma";
    //name_plot += "_Br_-1sigma";
    cout<<"name_plot= "<<name_plot<<endl;    
    gPad->Print(TString(name_plot)+".eps");
    gPad->Print(TString(name_plot)+".gif");
    //getchar();

  }

}
   
