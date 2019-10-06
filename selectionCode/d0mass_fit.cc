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


void d0mass_fit(char* sample="MC",char* decay="kspi",char* d0mode="kspipi",char* selection="m0d0_demk30/",Int_t opt1=1, Int_t opt2=1){

     gROOT->SetStyle("Plain");
    //---riscalo gli istogrammi per le rispettive luminosita'
    //definisco il numero di eventi dei vari campioni
    
    Float_t Evt1=710000000;  //#events uds   no cut
    Float_t Evt2=393000000; //#events ccbar no cut                     
    Float_t Evt3=542037448;  //#events B0B0bar   no cut
    Float_t Evt4=542459186; //#events Bch   no cut

    //luminosita' nominale degli eventi adronici nell'accentanza geometrica    
    Float_t sigmauds=2.09; //sigmauds=0.35+0.35+1.39=2.09 nb
    Float_t sigmaccbar=1.30; //sigmaccbar=1.30 nb
    Float_t sigmabbar=1.1;  //sigmabbar=1.1 nb

    //definisco la luminosita' dei vari campioni: fb-1 unita' di misura
    Float_t convfb=pow(10,6); 
    Float_t lumi0= (d0mode==TString("kspipi")) ? 1450.0 : 1450.0;
    Float_t lumi1= Evt1/(sigmauds*convfb); //sigmauds=0.35+0.35+1.39=2.09 nb
    Float_t lumi2= Evt2/(sigmaccbar*convfb);
    Float_t lumi3= 2*Evt3/(sigmabbar*convfb);
    Float_t lumi4= 2*Evt4/(sigmabbar*convfb);
    Float_t lumi5= 204;

//definisco la luminosita' di riferimento e i fattori di scala per gli istogrammi
    Float_t lumi=204;
    Float_t sc0=lumi/lumi0;
    Float_t sc01=lumi/lumi4;
    Float_t sc1=lumi/lumi1;
    Float_t sc2=lumi/lumi2;
    Float_t sc3=lumi/lumi3;
    Float_t sc4=lumi/lumi4;
    Float_t sc5=lumi/lumi5;
    
    cout<<"lumi Signal= "<<lumi0<<"     scale factor= "<<sc0<< endl;
    cout<<"lumi D*0Pi= "<<lumi4<<"     scale factor= "<<sc01<< endl;
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
    
    
    

    Int_t nbin=15;
    Float_t low=1.84;
    Float_t high=1.89;
//    TH1F* his0=new TH1F("histo0","",nbin,low,high);
//     TH1F* his1=new TH1F("histo1","",nbin,low,high);
//     TH1F* his2=new TH1F("histo2","",nbin,low,high);
//     TH1F* his3=new TH1F("histo3","",nbin,low,high);
//     TH1F* his4=new TH1F("histo4","",nbin,low,high);
//     TH1F* his5=new TH1F("histo5","",nbin,low,high);
    
    char name_sigm0d0[120];     
    char name_sigpim0d0[120];     
    char name_datam0d0[120];     
    char name_chbm0d0[120];     
    char name_bneum0d0[120];     
    char name_ccbarm0d0[120];     
    char name_udsm0d0[120];     
    char name_gif[120];

    //    sprintf(name_sigm0d0,"Prod2/HIST/%s/%s_%s_btdsk_m0d0.root",selection,decay,d0mode);
    //    cout<<"name_sigm0d0= "<<name_sigm0d0<<endl;
    //    TFile* file_sigm0d0 = new TFile(name_sigm0d0);
    //    TH1F* his0 = (TH1F*)file_sigm0d0->Get("Tm0d0");

    if (sample=="data") {
    sprintf(name_datam0d0,"HIST/bkg_study/%s/Finalcut_%s_%s_on_m0d0.root",selection,decay,d0mode);
    cout<<"name_datam0d0= "<<name_datam0d0<<endl;
    TFile* file_datam0d0 = new TFile(name_datam0d0);
    TH1F* his5 = (TH1F*)file_datam0d0->Get("m0d0");
    }

    if (sample=="MC") {
    sprintf(name_sigpim0d0,"HIST/bkg_study/%s/Finalcut_%s_%s_NR_m0d0.root",selection,decay,d0mode);
    cout<<"name_sigpim0d0= "<<name_sigpim0d0<<endl;
    TFile* file_sigpim0d0 = new TFile(name_sigpim0d0);
    TH1F* his01 = (TH1F*)file_sigpim0d0->Get("m0d0");

    
    sprintf(name_chbm0d0,"HIST/bkg_study/%s/Finalcut_%s_%s_chb_m0d0.root",selection,decay,d0mode);
    cout<<"name_chbm0d0= "<<name_chbm0d0<<endl;
    TFile* file_chbm0d0 = new TFile(name_chbm0d0);
    TH1F* his4 = (TH1F*)file_chbm0d0->Get("m0d0");


    sprintf(name_bneum0d0,"HIST/bkg_study/%s/Finalcut_%s_%s_b0b0bar_m0d0.root",selection,decay,d0mode);
    cout<<"name_bneum0d0= "<<name_bneum0d0<<endl;
    TFile* file_bneum0d0 = new TFile(name_bneum0d0);
    TH1F* his3 = (TH1F*)file_bneum0d0->Get("m0d0");

    sprintf(name_udsm0d0,"HIST/bkg_study/%s/Finalcut_%s_%s_uds_m0d0.root",selection,decay,d0mode);
    cout<<"name_udsm0d0= "<<name_udsm0d0<<endl;
    TFile* file_udsm0d0 = new TFile(name_udsm0d0);
    TH1F* his1 = (TH1F*)file_udsm0d0->Get("m0d0");

    sprintf(name_ccbarm0d0,"HIST/bkg_study/%s/Finalcut_%s_%s_ccbar_m0d0.root",selection,decay,d0mode);
    cout<<"name_ccbarm0d0= "<<name_ccbarm0d0<<endl;
    TFile* file_ccbarm0d0 = new TFile(name_ccbarm0d0);
    TH1F* his2 = (TH1F*)file_ccbarm0d0->Get("m0d0");

    }
    


    //    TCanvas *canvas=new TCanvas;
    //    canvas->cd();
    //riscalo gli histo secondo le luminosita' relative

    //    his0->Scale(sc0);
//     his01->Scale(sc01);
//     his1->Scale(sc1);
//     his2->Scale(sc2);
//     his3->Scale(sc3);
//     his4->Scale(sc4);
//     his5->Scale(sc5);

    if (sample=="data") {
    TH1F* data=new TH1F("data","m0d0 distribution",15,1.840,1.890);
    his5->SetMarkerSize(1);
    his5->SetMarkerStyle(8);
    data->Add(his5);
    Float_t data_max=data->GetMaximum();
    Int_t sum_data= his5->GetSum();
    }

    if (sample=="MC") {
    TH1F* stack=new TH1F("m0d0 MC","m0d0 distribution",15,1.840,1.890);
    stack->Add(his1,sc1);
    stack->Add(his2,sc2);
    stack->Add(his3,sc3);
    stack->Add(his4,sc4);
    stack->Add(his01,sc01);
    Float_t sum=0.0;

    for (Int_t i=1;i<=stack->GetNbinsX();i++){
      sum=sum + stack->GetBinContent(i);
    }
    //    cout << "bin 1= "<<stack->GetBinContent(1)<<endl;
    cout << "sum = "<<sum<<endl;
    //    stack->Add(his0,sc0);
    //
    }

    if (sample=="data")  data->Draw();
    else stack->Draw();
    //data->Draw("E1same");



    RooRealVar m0d0reco("m0d0reco","mass_{D^{0}}",1.84,1.89,"GeV/c^{2}"),
      d0mass("d0mass","Valore medio della massa fittata",1.8645,"GeV/c^{2}"),
      d0resn("d0resn","risoluzione massa D0",0.006,"GeV/c^{2}"),
      f("f","frazione di segnale",0.2,0.0,1.0),
      //f("f","frazione di segnale",0.2),
      //c1("c1","parametro della funzione polinomiale",0.0,-100.0,100.0),
      c1("c1","parametro della funzione polinomiale",0.0),
      //      c2("c2","parametro della funzione polinomiale",0.0,-100.0,100.0),
      c2("c2","parametro della funzione polinomiale",0.0);
	  

    //introduco le pdf per signal, bkg e total
    RooPolynomial bg("bg","funzione di background polinomiale",m0d0reco,RooArgList(c1,c2),1);
    RooGaussian signal("signal","Segnale",m0d0reco,d0mass,d0resn);
    RooAddPdf model("model","Segnale+Background",RooArgList(signal,bg),RooArgList(f));


    if (sample=="data") RooDataHist bdata("bdata","m0d0 MC distribution",m0d0reco,data);
    else RooDataHist bdata("bdata","m0d0 MC distribution",m0d0reco,stack);

    model.fitTo(bdata,"M");
    Int_t nbin=15;
    RooPlot* m0d0frame=m0d0reco.frame(nbin);
    
    //data plot
    bdata.plotOn(m0d0frame);
    m0d0frame->getAttMarker()->SetMarkerStyle(20);
    m0d0frame->getAttMarker()->SetMarkerSize(0.8);
    //model plot
    model.plotOn(m0d0frame);
    m0d0frame->getAttLine()->SetLineColor(kBlack);
    m0d0frame->getAttLine()->SetLineStyle(1);//continuous
    m0d0frame->getAttLine()->SetLineWidth(2);
    //argus plot
    model.plotCompOn(m0d0frame,bg);
    m0d0frame->getAttLine()->SetLineColor(kBlack);
    m0d0frame->getAttLine()->SetLineStyle(2);//dashed
    m0d0frame->getAttLine()->SetLineWidth(2);
    
    //caratterizzo il frame
    m0d0frame->SetTitleOffset(1.2,"X");
    m0d0frame->SetTitleOffset(1.2,"Y");//per babar style
    m0d0frame->SetTitle();
    
    //disegno il frame
    //    model->paramOn(m0d0frame,&bdata);
    m0d0frame->Draw();



    //---disegna le linee della zona-segnale
    Float_t m0d0sigma=0.06;
    //    TLine* line1=new TLine(1.8645-2*m0d0sigma,0,1.8645-2*m0d0sigma,data_max*0.8);
    TLine* line1=new TLine(1.8645-2*m0d0sigma,0,1.8645-2*m0d0sigma,100);
    line1->SetLineWidth(3);
    line1->SetLineColor(2);
    line1->Draw();
    //    TLine* line2=new TLine(1.8645+2*m0d0sigma,0,1.8645+2*m0d0sigma,data_max*0.8);
    TLine* line2=new TLine(1.8645+2*m0d0sigma,0,1.8645+2*m0d0sigma,100);
    line2->SetLineWidth(3);
    line2->SetLineColor(2);
    line2->Draw();


  //calcolo il num tot di eventi di segnale e bkg
    //  Int_t num_tot=bdata.numEntries();     // i tre metodi sotto danno risultati errati
    //Int_t num_tot=bdata.GetEntries();
    //    Float_t num_tot=stack->GetEntries();
    Float_t num_tot=(sample=="data") ? sum_data : sum;   // utilizzo la variabile sum che mi sono costruito per il MC
    Float_t num_sig_tot=num_tot*f.getVal();
    Float_t num_bkg_tot=num_tot*(1-f.getVal());
    Float_t f_error=f.getError();
    Float_t err_num_sig_tot=num_tot*f_error;
    Float_t err_num_bkg_tot=num_tot*f_error;
  
    cout<<"Num tot entries = "<<num_tot<<endl;
    cout<<"Num tot sig = "<<num_sig_tot<<endl;
    cout<<"Num tot bkg = "<<num_bkg_tot<<endl;

  //calcolo il num di eventi sig e bkg sotto il picco
  Float_t nsigma=2;
  Float_t m0d0mean=d0mass.getVal();
  Float_t m0d0sigma=d0resn.getVal();
  Float_t m0d0low=m0d0mean-nsigma*m0d0sigma;
  Float_t m0d0high=m0d0mean+nsigma*m0d0sigma;
  
  RooRealIntegral sigint("sigint","prova",signal,RooArgSet(m0d0reco));
  RooRealIntegral bkgint("bkgint","prova",bg,RooArgSet(m0d0reco));
  Float_t valsigtot=sigint.getVal();
  Float_t valbkgtot=bkgint.getVal();
  m0d0reco.setFitRange(m0d0low,m0d0high);
  Float_t valsig=sigint.getVal();
  Float_t valbkg=bkgint.getVal();

  Float_t sigratio=(valsigtot!=0?valsig/valsigtot:-1);
  Float_t bkgratio=(valbkgtot!=0?valbkg/valbkgtot:-1);
  
  Float_t num_sig=sigratio*num_sig_tot;
  Float_t num_bkg=bkgratio*num_bkg_tot;
  //  Float_t err_num_sig=err_num_sig_tot*sqrt(sigratio);//sqrt(sigratio) invece di sigratio
  Float_t err_num_sig=sqrt(err_num_sig_tot*err_num_sig_tot*sigratio*sigratio+num_sig);
  //  Float_t err_num_bkg=err_num_bkg_tot*sqrt(bkgratio);//sqrt(bkgratio) invece di sigratio
  Float_t err_num_bkg=sqrt(err_num_bkg_tot*err_num_bkg_tot*bkgratio*bkgratio+num_bkg);
  Float_t purity= ((num_sig+num_bkg)!=0)? num_sig/(num_sig+num_bkg) :0 ;
  cout<<"S = "<<num_sig<<" +- "<<err_num_sig<<endl;
  cout<<"B = "<<num_bkg<<" +- "<<err_num_bkg<<endl;
  cout<<"S/(S+B) = "<<purity<< " +- "<< sqrt((err_num_sig*err_num_sig)*((num_bkg/((num_sig+num_bkg)*(num_sig+num_bkg)))*(num_bkg/((num_sig+num_bkg)*(num_sig+num_bkg))))+(err_num_bkg*err_num_bkg)*((num_sig/((num_sig+num_bkg)*(num_sig+num_bkg))*(num_sig/((num_sig+num_bkg)*(num_sig+num_bkg)))))) <<endl;  //considero S,B due variabili scorrelate per il calcolo dell'errore.
  cout<<"S/sqrt(S+B) = "<<num_sig/sqrt(num_sig+num_bkg)<<endl;
  cout<<"S*S/(S+B) = "<<num_sig*num_sig/(num_sig+num_bkg)<<endl;
  
  cout<<"sigratio = "<<sigratio<<endl;
  cout<<"bkgratio = "<<bkgratio<<endl;
  

    sprintf(name_gif,"plot/bkg_study/%s/Finalcut_%s_%s_m0d0",selection,sample,decay,d0mode);
    cout<<"name_gif= "<<name_gif<<endl;    
    gPad->Print(TString(name_gif)+".eps");
    gPad->Print(TString(name_gif)+".gif");
    Float_t lowx=0.20;
    Float_t lowy=0.54;
    Float_t highx=0.5;
    Float_t highy=0.94;

    /*    
    TPaveStats *pt = new TPaveStats(lowx,lowy,highx,highy,"brNDC");
    pt->SetBorderSize(0);
    pt->SetFillColor(10);
    pt->SetTextAlign(12);
    pt->SetTextFont(132);

    char* frase1 = new char[50];
    sprintf(frase1,"S(3#sigma) = %.1f #pm %.1f\n",num_sig,err_num_sig);
    pt->AddText(frase1);
    delete[] frase1;
    char* frase2 = new char[50];
    sprintf(frase2,"S/(S+B) = %.2f\n",num_sig/(num_sig+num_bkg));
    pt->AddText(frase2);
    delete[] frase2;
    char* frase3 = new char[50];
    sprintf(frase3,"S^{2}/(S+B) = %.2f\n",num_sig*num_sig/(num_sig+num_bkg));
    pt->AddText(frase3);
    delete[] frase3;
    char* frase4 = new char[50];
    sprintf(frase4,"mean = %.1f #pm %.1f\n",1000*d0mass.getVal(),1000*d0mass.getError());
    pt->AddText(frase4);
    delete[] frase4;
    char* frase5 = new char[50];
    sprintf(frase5,"sigma = %.1f #pm %.1f\n",1000*d0resn.getVal(),1000*d0resn.getError());
    pt->AddText(frase5);
    delete[] frase5;
    char* frase6 = new char[50];
    sprintf(frase6,"csi = %.1f #pm %.1f\n",c1.getVal(),c1.getError());
    pt->AddText(frase6);
    delete[] frase6;
    
    pt->Draw();
    */


    }
