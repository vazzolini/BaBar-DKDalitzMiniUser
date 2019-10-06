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

void btdkpi_comp_data_off(TString channel="D0K", TString dstar0mode="d0", TString d0mode="kspipi",Int_t cut=-999)
{
  // channel = D0K, D*0K, D0Pi, D*0Pi
  // dstar0mode = d0, d0pi0, d0gam
  // d0mode = kspipi, kskk  

  //gStyle->Reset();
  gROOT->SetStyle("Plain");
  gStyle->SetStatColor(10);
  gStyle->SetOptStat(0);
  gStyle->SetOptFit(0);

  TString dtype = channel.BeginsWith("D0")? "D0" : "Dstar0" ;
  TString KorPi = channel.EndsWith("K")? "k" : "pi" ;

  gStyle->SetOptStat(00000);
  gROOT->SetStyle("Plain");
  gStyle->SetOptFit(0000000);
   
  //luminosita' nominale degli eventi adronici nell'accentanza geometrica    
  Float_t sigmauds=2.09; //sigmauds=0.35+0.35+1.39=2.09 nb
  Float_t sigmaccbar=1.30; //sigmaccbar=1.30 nb
  Float_t sigmabbar=1.1;  //sigmabbar=1.1 nb

  //definisco la luminosita' dei vari campioni: fb-1 unita' di misura
  // Float_t lumi_sig(86.9);
 Float_t lumi_sig;


 if (dtype=="D0" && KorPi=="k" && d0mode=="kspipi") lumi_sig = 117608.482;
 else if (dtype=="D0" && KorPi=="k" && d0mode=="kskk") lumi_sig =745152.355;
 else if (dtype=="Dstar0"  && dstar0mode=="d0pi0" && KorPi=="k" && d0mode=="kspipi") lumi_sig = 226975.073;
 else if (dtype=="Dstar0"  && dstar0mode=="d0pi0" && KorPi=="k" && d0mode=="kskk") lumi_sig = 1438 420.348;
 else if (dtype=="Dstar0"  && dstar0mode=="d0gam" && KorPi=="k" && d0mode=="kspipi") lumi_sig = 226975.073;
 else if (dtype=="Dstar0"  && dstar0mode=="d0gam" && KorPi=="k" && d0mode=="kskk") lumi_sig = 1438 420.348;
 
 else if (dtype=="D0" && dstar0mode=="d0" &&KorPi=="pi"&& d0mode=="kspipi") lumi_sig =9767.7880;
 else if (dtype=="D0" && dstar0mode=="d0" &&KorPi=="pi"&& d0mode=="kskk") lumi_sig = 61878.199;
 else if (dtype=="Dstar0"  && dstar0mode=="d0pi0" && KorPi=="pi"&& d0mode=="kspipi") lumi_sig =  18192.746;
 else if (dtype=="Dstar0"  && dstar0mode=="d0pi0" && KorPi=="pi"&& d0mode=="kskk") lumi_sig = 115246.420;
 else if (dtype=="Dstar0"  && dstar0mode=="d0gam" && KorPi=="pi"&& d0mode=="kspipi") lumi_sig =18192.746;
 else if (dtype=="Dstar0"  && dstar0mode=="d0gam" && KorPi=="pi"&& d0mode=="kskk") lumi_sig =115246.420;




 cout<<"lumi_sig="<<lumi_sig<<endl;

//   Float_t lumi_uds= 165.2622;
//   Float_t lumi_ccbar=356.1677;
//   //  Float_t lumi_bneu=843.9273;
//  Float_t lumi_bneu=773.6;
//  //  Float_t lumi_chb=824.0509;
//   Float_t lumi_chb=773.6;
//   Float_t lumi_on= 288.50;
  


  Float_t lumi_uds= 778.863;
  Float_t lumi_ccbar=868.1107;
  Float_t lumi_bneu=1305.4454;
  Float_t lumi_chb=1288.6582;

  //  Float_t lumi_on=425.472;
  Float_t lumi_off= 44.480;

  //definisco la luminosita' di riferimento e i fattori di scala per gli istogrammi

  Float_t lumi=425.472;
  Float_t sc_sig=lumi/lumi_sig;
  Float_t sc_uds=lumi/lumi_uds;
  Float_t sc_ccbar=lumi/lumi_ccbar;
  Float_t sc_bneu=lumi/lumi_bneu;
  Float_t sc_chb=lumi/lumi_chb;
  //  Float_t sc_on=lumi/lumi_on;
  Float_t sc_off=lumi/lumi_off;



  
  cout<<"lumi signal= "<<lumi_sig<<" scale factor= "<<sc_sig<< endl;
  cout<<"lumi uds   = "<<lumi_uds<<" scale factor= "<<sc_uds<<endl;
  cout<<"lumi ccbar = "<<lumi_ccbar<<" scale factor= "<<sc_ccbar<<endl;
  cout<<"lumi B0    = "<<lumi_bneu<<" scale factor= "<<sc_bneu<<endl;
  cout<<"lumi Bch   = "<<lumi_chb<<" scale factor= "<<sc_chb<<endl;
  //cout<<"lumi ON    = "<<lumi_on<<" scale factor= "<<sc_on<<endl;
  cout<<"lumi OFF   = "<<lumi_off<<" scale factor= "<<sc_off<<endl;
      
  //gPad->SetFillColor(0);
  //gPad->SetBorderMode(0);
  //gStyle->SetStatColor(10);
  //gStyle->SetOptStat(0);
  //gStyle->SetOptFit(0);
  
  enum cutvar {mes,demk,fisherDK,massKs,massD0,deltadeltamd };
  cutvar type;
  TH1F* his[20];  
  TString sig_type;

  // for (type=mes;type<=mes;type++){
  //  for (type=mes;type<=demk;type++){
  //for (type=massD0;type<=massD0;type++){
  //      for (type=massD0;type<=massD0;type++){
  //  for (type=massKs;type<=massKs;type++){
  for (type=fisherDK;type<=fisherDK;type++){
    //for (type=deltadeltamd;type<=deltadeltamd;type++){
  //  for (type=mes;type<=mes;type++){
    if(cut<0){        
    char typeStr[10];
    char cut_code_str[10];
    if (type==fisherDK) {
      sprintf(typeStr,"fisherDK");
      sprintf(cut_code_str,"Cut1");
    } else if (type==demk) {
      sprintf(typeStr,"demk");
      sprintf(cut_code_str,"Cut2");
    } else if (type==mes) {
      sprintf(typeStr,"mes");
      sprintf(cut_code_str,"Cut100");
    } else if(type==massD0){
      sprintf(typeStr,"massD0");
      sprintf(cut_code_str,"Cut100");
    } else if(type==massKs){
      sprintf(typeStr,"massKs");
      sprintf(cut_code_str,"Cut100");
    }  else if(type==deltadeltamd){
      sprintf(typeStr,"deltadeltamd");
      sprintf(cut_code_str,"Cut100");
    }
    else assert(0);}
    else if(cut==4){
      if (type==fisherDK) {
	sprintf(typeStr,"fisherDK");
	sprintf(cut_code_str,"Cut4");
      } else if (type==demk) {
	sprintf(typeStr,"demk");
	sprintf(cut_code_str,"Cut4");
      } else if (type==mes) {
	sprintf(typeStr,"mes");
	sprintf(cut_code_str,"Cut4");
      }else if(type==massKs){
	sprintf(typeStr,"massKs");      
	sprintf(cut_code_str,"Cut4");
      }
      else assert(0);}
    else if(cut==3){
      if (type==fisherDK) {
	sprintf(typeStr,"fisherDK");
	sprintf(cut_code_str,"Cut3");
      } else if (type==demk) {
	sprintf(typeStr,"demk");
	sprintf(cut_code_str,"Cut3");
      } else if (type==mes) {
	sprintf(typeStr,"mes");
	sprintf(cut_code_str,"Cut3");
      }else if(type==massKs){
	sprintf(typeStr,"massKs");      
	sprintf(cut_code_str,"Cut3");
      }else if(type==massD0){
	sprintf(typeStr,"massD0");      
	sprintf(cut_code_str,"Cut3");
      }
      else assert(0);}
    else if(cut==10){
      if (type==fisherDK) {
	sprintf(typeStr,"fisherDK");
	sprintf(cut_code_str,"Cut10");
      } else if (type==demk) {
	sprintf(typeStr,"demk");
	sprintf(cut_code_str,"Cut10");
      } else if (type==mes) {
	sprintf(typeStr,"mes");
	sprintf(cut_code_str,"Cut10");
      }else if(type==massKs){
	sprintf(typeStr,"massKs");      
	sprintf(cut_code_str,"Cut10");
      }else if(type==massD0){
	sprintf(typeStr,"massD0");      
	sprintf(cut_code_str,"Cut10");
      }
     //  else if(type==deltadeltamd){
// 	sprintf(typeStr,"deltadeltamd");      
// 	sprintf(cut_code_str,"Cut10");
//       }
      else assert(0);}
    else if(cut==0){
      if (type==fisherDK) {
	sprintf(typeStr,"fisherDK");
	sprintf(cut_code_str,"Cut0");
      } else if (type==demk) {
	sprintf(typeStr,"demk");
	sprintf(cut_code_str,"Cut0");
      } else if (type==mes) {
	sprintf(typeStr,"mes");
	sprintf(cut_code_str,"Cut0");
      }else if(type==massKs){
	sprintf(typeStr,"massKs");      
	sprintf(cut_code_str,"Cut0");
      }else if(type==massD0){
	sprintf(typeStr,"massD0");      
	sprintf(cut_code_str,"Cut0");
      }
      else assert(0);}
      // else if(type==deltadeltamd){
// 	sprintf(typeStr,"deltadeltamd");      
// 	sprintf(cut_code_str,"Cut0");
//       }
   

    char xtitle[40];    
    //sprintf(xtitle,"%s GeV/c^{2}",typeStr);
    sprintf(xtitle,"%s",typeStr);
    //cout << "titolo X = "<< xtitle<<endl; 
    char title[255];
    sprintf(title,"%s distribution DATA vs MC",typeStr);
    cout << endl << "title = " << title<<endl;

    TString sdec="btdkpi_";
 
//     // sig
//     if (dtype=="D0" && KorPi=="k") sig_type="btdk";
//     else if (dtype=="Dstar0" && KorPi=="k") sig_type="btdsk";
//     else if (dtype=="D0" && KorPi=="pi") sig_type="btdpi";
//     else if (dtype=="Dstar0" && KorPi=="pi") sig_type="btdspi";
//     else assert(0);
//     TString name_sig="ASCII/"+sdec+dstar0mode+KorPi+"_"+d0mode+"_"+sig_type+"_"+cut_code_str+".root";
//     TFile* file_sig = new TFile(name_sig,"read");
//     cout<<"name_sig = "<<name_sig<<endl;
//     TH1F* his_sig = (TH1F*)file_sig->Get(typeStr);
//     his_sig->SetLineColor(2);
//     his_sig->SetFillColor(2);

    // chb
  //   sig_type = "chb"; 
//     TString name_chb="ASCII/"+sdec+dstar0mode+KorPi+"_"+d0mode+"_"+sig_type+"_"+cut_code_str+".root";
//     TFile* file_chb = new TFile(name_chb,"read");
//     cout<<"file_chb = "<<file_chb<<endl;
//     TH1F* his_chb = (TH1F*)file_chb->Get(typeStr);
//     his_chb->SetLineColor(3);
//     his_chb->SetFillColor(3);

//     // chbk or chbpi
//     sig_type = (KorPi=="k")? "chbpi" : "chbk";
//     TString name_chbkpi="ASCII/"+sdec+dstar0mode+KorPi+"_"+d0mode+"_"+sig_type+"_"+cut_code_str+".root";
//     TFile* file_chbkpi = new TFile(name_chbkpi,"read");
//     cout<<"file_chbkpi = "<<file_chbkpi<<endl;
//     TH1F* his_chbkpi = (TH1F*)file_chbkpi->Get(typeStr);
//     his_chbkpi->SetLineColor(4);
//     his_chbkpi->SetFillColor(4);


//     // b0b0bar
//     sig_type = "b0b0bar";
//     TString name_bneu="ASCII/"+sdec+dstar0mode+KorPi+"_"+d0mode+"_"+sig_type+"_Bbest_"+cut_code_str+".root";
//     TFile* file_bneu = new TFile(name_bneu,"read");
//     cout<<"name_bneu = "<<name_bneu<<endl;
//     TH1F* his_bneu = (TH1F*)file_bneu->Get(typeStr);
//     his_bneu->SetLineColor(5);
//     his_bneu->SetFillColor(5);

    // uds
    sig_type = "uds";
    TString name_uds="ASCII/"+sdec+dstar0mode+KorPi+"_"+d0mode+"_"+sig_type+"_Bbest_"+cut_code_str+".root";
    TFile* file_uds = new TFile(name_uds,"read");
    cout<<"name_uds = "<<name_uds<<endl;
    TH1F* his_uds = (TH1F*)file_uds->Get(typeStr);
    his_uds->SetLineColor(6);
    his_uds->SetFillColor(6);

    // ccbar
    sig_type = "ccbar";
    TString name_ccbar="ASCII/"+sdec+dstar0mode+KorPi+"_"+d0mode+"_"+sig_type+"_Bbest_"+cut_code_str+".root";
    TFile* file_ccbar = new TFile(name_ccbar,"read");
    cout<<"name_ccbar = "<<name_ccbar<<endl;
    TH1F* his_ccbar = (TH1F*)file_ccbar->Get(typeStr);
    his_ccbar->SetLineColor(7);
    his_ccbar->SetFillColor(7);

   //  // on
//     sig_type = "on";
//     TString name_on="ASCII/"+sdec+dstar0mode+KorPi+"_"+d0mode+"_"+sig_type+"_Bbest_"+cut_code_str+".root";
//     TFile* file_on = new TFile(name_on,"read");
//     cout<<"name_on = "<<name_on<<endl;
//     TH1F* his_on = (TH1F*)file_on->Get(typeStr);

  // off
    sig_type = "off";
    TString name_off="ASCII/"+sdec+dstar0mode+KorPi+"_"+d0mode+"_"+sig_type+"_Bbest_"+cut_code_str+".root";
    TFile* file_off = new TFile(name_off,"read");
    cout<<"name_ = "<<name_off<<endl;
    TH1F* his_off = (TH1F*)file_off->Get(typeStr);


    TCanvas *canvas=new TCanvas;
    canvas->cd();
    //riscalo gli histo secondo le luminosita' relative

    his_uds->Scale(sc_uds);
    his_ccbar->Scale(sc_ccbar);
    //his_on->Scale(sc_on);
    his_off->Scale(sc_off);
    char title[255];
    sprintf(title,"%s distribution DATA vs MC",typeStr);
    cout << "title = " << title<<endl;
    //    THStack* data=new THStack("data_mc","DATA MC comparison");
    //    THStack* data=new THStack("data_mc",title);
    //    his5->SetMarkerSize(1);
    //    his5->SetMarkerStyle(8);
    //    data->Add(his5);
    //    Float_t data_max=data->GetMaximum();

    //THStack* stack=new THStack("data_mc","DATA MC comparison");
    THStack* stack=new THStack("data_mc",title);
    //    stack->SetMaximum(data_max*1.5);

    stack->Add(his_uds);
    stack->Add(his_ccbar);
   
    //
    //his_on->Draw("E1");
    //his_on->SetMinimum(0);
    
    stack->Draw("");
    //    stack->SetMaximum(1600.);    
    stack->GetYaxis()->SetRangeUser(0.,1000.);
    his_off->SetMarkerStyle(20); 
    his_off->SetMarkerSize(0.8); 
    his_off->SetLineWidth(2); 
    his_off->Draw("E1SAME");


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
   

    //---disegna legenda
    TLegend *leg;
    if (type==mes || type==demk) leg = new TLegend(0.15,0.60,0.40,0.90);
    else leg = new TLegend(0.55,0.60,0.90,0.90) ;
    
    //    TLegend *leg=new TLegend(0.12,0.65,0.37,0.90);
    //    leg->SetMargin();
    leg->SetBorderSize(0);
    leg->SetTextFont(132);
    leg->SetHeader("Legenda:");
    leg->SetFillColor(10);//e' il colore del bkg della box. lo zero(trasparente?) si comporta come 1(nero). Per avere il bianco si mette 10.
    
    leg->AddEntry(his_uds,"uds","f");
    leg->AddEntry(his_ccbar,"c#bar{c}","f");
//     leg->AddEntry(his_bneu,"B^{0}#bar{B^{0}}","f");
//     leg->AddEntry(his_chb,"B^{+}B^{-}","f");
//     if (KorPi=="k" && dtype=="D0") {
//       leg->AddEntry(his_chbkpi,"B^{-}#rightarrowD^{0}#pi^{-}","f");
//       leg->AddEntry(his_sig,"B^{-}#rightarrowD^{0}K^{-}","f");
//     } else if (KorPi=="k" &&d type=="Dstar0") {
//       leg->AddEntry(his_chbkpi,"B^{-}#rightarrowD^{*0}#pi^{-}","f");
//       leg->AddEntry(his_sig,"B^{-}#rightarrowD^{*0}K^{-}","f");
//     } else if (KorPi=="pi" && dtype=="D0") {
//       leg->AddEntry(his_chbkpi,"B^{-}#rightarrowD^{0}K^{-}","f");
//       leg->AddEntry(his_sig,"B^{-}#rightarrowD^{0}#pi^{-}","f");
//     }  else if (KorPi=="pi" && dtype=="Dstar0") {
//       leg->AddEntry(his_chbkpi,"B^{-}#rightarrowD^{*0}K^{-}","f");
//       leg->AddEntry(his_sig,"B^{-}#rightarrowD^{*0}#pi^{-}","f");
//     }

    //    leg->AddEntry(his5,"DATA","f");
    
    leg->Draw();

    
    TString name_plot="ASCII/stack_"+sdec+dstar0mode+KorPi+"_"+d0mode+"_"+cut_code_str+"_"+typeStr;
    //name_plot += "_Br_central";
    //name_plot += "_Br_-0.5sigma";
    //name_plot += "_Br_-1sigma";
    cout<<"name_plot= "<<name_plot<<endl;    
    gPad->Print(TString(name_plot)+".eps");
    //  gPad->Print(TString(name_plot)+".gif");
    //getchar();

  }

}


