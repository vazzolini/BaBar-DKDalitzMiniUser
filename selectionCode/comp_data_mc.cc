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

void comp_data_mc(char* decay="kspi",char* d0mode="kspipi",char* selection="Finalcut",Int_t flag=1,Int_t opt1=1, Int_t opt2=1){
  
  Int_t col_style= (decay=="kspi") ? 2:3;

  gStyle->SetOptStat(00000);
  gROOT->SetStyle("Plain");

  gStyle->SetOptFit(0000000);
  
    //---riscalo gli istogrammi per le rispettive luminosita'
    //definisco il numero di eventi dei vari campioni

    Float_t Evt1=710670526;  //#events uds   no cut
    Float_t Evt2=417920626; //#events ccbar no cut    
    Float_t Evt3=546502225;  //#events B0B0bar   no cut
    Float_t Evt4=546502225; //#events Bch   no cut

    //luminosita' nominale degli eventi adronici nell'accentanza geometrica    
    Float_t sigmauds=2.09; //sigmauds=0.35+0.35+1.39=2.09 nb
    Float_t sigmaccbar=1.30; //sigmaccbar=1.30 nb
    Float_t sigmabbar=1.1;  //sigmabbar=1.1 nb
    //definisco la luminosita' dei vari campioni: fb-1 unita' di misura
    Float_t convfb=pow(10,6); 
    lumi0= (d0mode==TString("kspipi")) ? 1450 : 1450;
    Float_t lumi1= Evt1/(sigmauds*convfb); //sigmauds=0.35+0.35+1.39=2.09 nb
    Float_t lumi2= Evt2/(sigmaccbar*convfb);
    Float_t lumi3= 2*Evt3/(sigmabbar*convfb);
    Float_t lumi4= 2*Evt4/(sigmabbar*convfb);
    Float_t lumi5= 19.7;

//definisco la luminosita' di riferimento e i fattori di scala per gli istogrammi
    Float_t lumi=211.0;
    Float_t sc0=lumi/lumi0;
    Float_t sc01=lumi/lumi4;
    Float_t sc1=lumi/lumi1;
    Float_t sc2=lumi/lumi2;
    Float_t sc3=lumi/lumi3;
    Float_t sc4=lumi/lumi4;
    Float_t sc5=lumi/lumi5;
    
    cout<<"lumi Signal= "<<lumi0<<"     scale factor= "<<sc0<< endl;
    //    cout<<"lumi D*0Pi= "<<lumi4<<"     scale factor= "<<sc01<< endl;
    cout<<"lumi uds   = "<<lumi1<<" scale factor= "<<sc1<<endl;
    cout<<"lumi ccbar = "<<lumi2<<" scale factor= "<<sc2<<endl;
    cout<<"lumi B0    = "<<lumi3<<" scale factor= "<<sc3<<endl;
    cout<<"lumi Bch   = "<<lumi4<<" scale factor= "<<sc4<<endl;
    cout<<"lumi DATA   = "<<lumi5<<" scale factor= "<<sc5<<endl;



    //gStyle->Reset();
    
    //gPad->SetFillColor(10);
    //gPad->SetBorderMode(0);
    gStyle->SetStatColor(10);
    gStyle->SetOptStat(0);
    gStyle->SetOptFit(0);

    enum cutvar {mes,demk,multi_cand,m0d0,m0Ks,cosKs,cosKstarKs,kaonid,costhrust,fisherDK,coshel,m0KstarcPi0,m0KstarcKs,m0Kstarc};
    cutvar type;
    TH1F* his[20];  
  for (type=mes;type<=multi_cand;type++){

    if ((decay=="kspi" && (type==kaonid || type==m0KstarcPi0)) || 
	(decay=="kpi0" && (type==cosKstarKs || type==m0KstarcKs)) ) continue;

    char filename[255];
    char name_sig[255];
    char name_treesig[255];
    char name_sigpi[255];
    char name_treesigpi[255];
    char name_chb[255];
    char name_treechb[255];
    char name_bneu[255];
    char name_treebneu[255];
    char name_uds[255];
    char name_treeuds[255];
    char name_ccbar[255];
    char name_treeccbar[255];
    char name_data[255];
    char name_treedata[255];
    char typeStr[10];
    char name_gif[255];
    if (type==costhrust)
       sprintf(typeStr,"costhrust");
    if (type==fisherDK)
       sprintf(typeStr,"fisherDK");
    else if (type==m0d0)
       sprintf(typeStr,"m0d0");
    else if (type==m0Ks)
       sprintf(typeStr,"m0Ks");
    else if (type==demk)
       sprintf(typeStr,"demk");
    else if (type==multi_cand)
       sprintf(typeStr,"multi_cand");
    else if (type==kaonid)
       sprintf(typeStr,"kaonid");
    else if (type==cosKs)
       sprintf(typeStr,"cosKs");
    else if (type==cosKstarKs)
       sprintf(typeStr,"cosKstarKs");
    else if (type==mes)
       sprintf(typeStr,"mes");
    else if (type==coshel)
       sprintf(typeStr,"coshel");
    else if (type==m0Kstarc)
       sprintf(typeStr,"m0Kstarc");
    else if (type==m0KstarcKs)
       sprintf(typeStr,"m0KstarcKs");
    else if (type==m0KstarcPi0)
      sprintf(typeStr,"m0KstarcPi0");

    sprintf(name_sig,"HIST/%s%s_%s_%s_btdkstarc_%s.root",selection,typeStr,decay,d0mode,typeStr);
    sprintf(name_treesig,"%s",typeStr);
    cout<<"name_sig= "<<name_sig<<endl;
    cout<<"name_treesig= "<<name_treesig<<endl;
    TFile* file_sig = new TFile(name_sig);
    TH1F* his0 = (TH1F*)file_sig->Get(name_treesig);
    his0->SetLineColor(col_style);
    his0->SetFillColor(col_style);


    sprintf(name_chb,"HIST//%s%s_%s_%s_chb_%s.root",selection,typeStr,decay,d0mode,typeStr);
    sprintf(name_treechb,"%s",typeStr);
    cout<<"name_chb= "<<name_chb<<endl;
    cout<<"name_treechb= "<<name_treechb<<endl;
    TFile* file_chb = new TFile(name_chb);
    TH1F* his4 = (TH1F*)file_chb->Get(name_treechb);
    his4->SetLineColor(4);
    his4->SetFillColor(4);

    sprintf(name_bneu,"HIST//%s%s_%s_%s_b0b0bar_%s.root",selection,typeStr,decay,d0mode,typeStr);
    sprintf(name_treebneu,"%s",typeStr);
    cout<<"name_bneu= "<<name_bneu<<endl;
    cout<<"name_treebneu= "<<name_treebneu<<endl;
    TFile* file_bneu = new TFile(name_bneu);
    TH1F* his3 = (TH1F*)file_bneu->Get(name_treebneu);
    his3->SetLineColor(5);
    his3->SetFillColor(5);
    /*
    sprintf(name_data,"HIST//%s%s_%s_%s_on1_%s.root",selection,typeStr,decay,d0mode,typeStr);
    sprintf(name_treedata,"%s",typeStr);
    cout<<"name_data= "<<name_data<<endl;
    cout<<"name_treedata= "<<name_treedata<<endl;
    TFile* file_data = new TFile(name_data);
    TH1F* his5 = (TH1F*)file_data->Get(name_treedata);
    */

    sprintf(name_uds,"HIST//%s%s_%s_%s_uds_%s.root",selection,typeStr,decay,d0mode,typeStr);
    sprintf(name_treeuds,"%s",typeStr);
    cout<<"name_uds= "<<name_uds<<endl;
    cout<<"name_treeuds= "<<name_treeuds<<endl;
    TFile* file_uds = new TFile(name_uds);
    TH1F* his1 = (TH1F*)file_uds->Get(name_treeuds);

    sprintf(name_ccbar,"HIST//%s%s_%s_%s_ccbar_%s.root",selection,typeStr,decay,d0mode,typeStr);
    sprintf(name_treeccbar,"%s",typeStr);
    cout<<"name_ccbar= "<<name_ccbar<<endl;
    cout<<"name_treeccbar= "<<name_treeccbar<<endl;
    TFile* file_ccbar = new TFile(name_ccbar);
    TH1F* his2 = (TH1F*)file_ccbar->Get(name_treeccbar);


    char xtitle[40];    
    sprintf(xtitle,"%s GeV/c^{2}",typeStr);
    if (typeStr==costhrust || typeStr==cosKs || typeStr==kaonid ) sprintf(xtitle,"A.U.",typeStr);
    cout << "titolo X = "<< xtitle<<endl; 
    //    his0->SetXTitle(xtitle);
    //    his1->SetXTitle(xtitle);
    //    his2->SetXTitle(xtitle);
    //    his3->SetXTitle(xtitle);
    his4->SetXTitle(xtitle);
    //    his5->SetXTitle(xtitle);




    TCanvas *canvas=new TCanvas;
    canvas->cd();
    //riscalo gli histo secondo le luminosita' relative

    his0->Scale(sc0);
    his1->Scale(sc1);
    his2->Scale(sc2);
    his3->Scale(sc3);
    his4->Scale(sc4);
    //    his5->Scale(sc5);
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
    stack->Add(his1);
    stack->Add(his2);
    stack->Add(his3);
    stack->Add(his4);
    stack->Add(his0);
    //
    stack->Draw();
    if (type==coshel){  stack->GetXaxis()->SetTitle("cos #theta_{Hel}");
    stack->GetYaxis()->SetTitle("Events/0.07333");
    }
    if (type==demk){  stack->GetXaxis()->SetTitle(" #DeltaE (GeV)");
    stack->GetYaxis()->SetTitle("Events/0.00334 GeV");
    }
    if (type==mes){  stack->GetXaxis()->SetTitle("m_{ES} (GeV/c^{2})");
    stack->GetYaxis()->SetTitle("Events/0.001667 GeV/c^{2}");
    }
    if (type==mes){  stack->GetXaxis()->SetTitle(" m_{ES} (GeV/c^{2})");
    stack->GetYaxis()->SetTitle("Events/0.001667 GeV/c^{2}");
    }
    if (type==multi_cand){  
      stack->GetXaxis()->SetTitle("#Candidates/Event");
      canvas->SetLogy();
    }
    


    //    data->Draw("E1same");

    //---disegna legenda
    TLegend *leg=new TLegend(0.15,0.60,0.40,0.90);
    if (type==multi_cand){  
      stack->GetXaxis()->SetTitle("#Candidates/Event");
      canvas->SetLogy();
      leg->SetX1(0.50);
      leg->SetY1(0.60);
      leg->SetX2(0.75);
      leg->SetY2(0.90);
    }

    //    TLegend *leg=new TLegend(0.12,0.65,0.37,0.90);
    //    leg->SetMargin();
    leg->SetBorderSize(0);
    leg->SetTextFont(132);
    leg->SetHeader("Legenda:");
    leg->SetFillColor(10);//e' il colore del bkg della box. lo zero(trasparente?) si comporta come 1(nero). Per avere il bianco si mette 10.

    leg->AddEntry(his1,"uds","f");
    leg->AddEntry(his2,"c#bar{c}","f");
    leg->AddEntry(his3,"B^{0}#bar{B^{0}}","f");
    leg->AddEntry(his4,"B^{+}B^{-}","f");
    if (decay==TString("kspi")&&d0mode==TString("kspipi")) leg->AddEntry(his0,"B^{+}#rightarrowD^{0}K^{*+}  K_{S}#pi^{+}","f");
    else if (decay==TString("kpi0")&&d0mode==TString("kspipi")) leg->AddEntry(his0,"B^{+}#rightarrowD^{0}K^{*+}  K_{+}#pi^{0}","f");


    //    leg->AddEntry(his5,"DATA","f");


    leg->Draw();

    sprintf(name_gif,"plot/%s%s_%s_%s",selection,decay,d0mode,typeStr);
    cout<<"name_gif= "<<name_gif<<endl;    
    gPad->Print(TString(name_gif)+".eps");
    gPad->Print(TString(name_gif)+".gif");
    getchar();

  }
}
   
