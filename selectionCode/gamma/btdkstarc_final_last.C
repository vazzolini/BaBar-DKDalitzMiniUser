#define btdkstarc_final_cxx
#include "btdkstarc_final.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iomanip.h>
#include <fstream.h>
//#include <strstream.h>
#include <TLorentzVector.h>
#include <TMath.h>

#include "RooFitCore/RooGlobalFunc.hh"
using namespace RooFit;

void btdkstarc_final::Loop(Int_t cut_code, Long64_t nentries)
{
   if (fChain == 0) return;

   TCanvas* canvas= new TCanvas;

   TH1F  *vect[17];
   TFile *f[17];
   
   Double_t massVcResoRange_min = (_isCS==kFALSE)? 0.470 : 0.6;
   Double_t massVcResoRange_max = (_isCS==kFALSE)? 0.520 : 0.9;

   // first histograms for cuts, and in the same order as cut_code
   Int_t nbins(50);
   TH1F* Tmes = new TH1F("mes","mES distribution",nbins,5.20,5.30); 
   vect[0]=Tmes; 
   TH1F* Tdemk = new TH1F("demk","DeltaE distribution",nbins,-0.12,0.12); 
   vect[1]=Tdemk;
   TH1F* TmassD0 = new TH1F("massD0","D0 mass distribution",nbins,1.840,1.890); 
   vect[2]=TmassD0;
   TH1F* TmassKs = new TH1F("massKs","Ks mass distribution",nbins,0.470,0.520);
   vect[3]=TmassKs; 
   TH1F* TcosKs = new TH1F("cosKs","CosthetaKs distribution",nbins,-1,1); 
   vect[4]=TcosKs;
   TH1F* TcosKstarKs = new TH1F("cosKstarKs","CosthetaKs distribution",nbins,-1,1); 
   vect[5]=TcosKstarKs;
   TH1F* Tkaonid = new TH1F("kaonid","kaonid distribution",12,0,11);
   vect[6]=Tkaonid; 
   TH1F* Tcosthrust = new TH1F("costhrust","costhrust distribution",nbins,-1.0,1.0);
   vect[7]=Tcosthrust; 
   TH1F* Tcoshel = new TH1F("coshel","Cos Hel distribution",nbins,-1.1,1.1); 
   vect[8]=Tcoshel;
   TH1F* TmassVectorc = new TH1F("massVectorc","Kstarc mass distribution",nbins,0.742,1.042);
   vect[9]=TmassVectorc; 
   TH1F* TmassVectorcReso = new TH1F("massVectorcReso","VectorcReso mass distribution",nbins,massVcResoRange_min,massVcResoRange_max); 
   vect[10]=TmassVectorcReso; 
   TH1F* Tm0KstarcPi0 = new TH1F("m0KstarcPi0","KstarcPi0 mass distribution",nbins,0.115,0.150);
   vect[11]=Tm0KstarcPi0;
   TH1F* Tprobchi2D0 =new TH1F("probchi2D0","probabilitat del chi2 per a D0",40,0,1);
   vect[12]= Tprobchi2D0;
   TH1F* Tprobchi2ChB =new TH1F("probchi2ChB","probabilitat del chi2 per a Bch",40,0,1);
   vect[13]= Tprobchi2ChB;
   TH1F* Tmulti_cand = new TH1F("multi_cand","Multiple Candidate distribution",10,1,10);
   vect[14]=Tmulti_cand; 
   TH1F* TFisherDK = new TH1F("fisherDK","Fisher Distribution",nbins,-2,2);
   vect[15]=TFisherDK; 
   TH1F* TSigdlKs = new TH1F("TSigdlKs","SigdlKs distribution",nbins,-300,4000);
   vect[16]=TSigdlKs;


   if (nentries<=0 || nentries>fChain->GetEntries()) nentries = Int_t(fChain->GetEntriesFast());
   cout<< "Number of Entries = " <<nentries<<endl; 
   
   Int_t nbytes(0), nb(0);
   //Float_t mPi0_nom(0.135);
   Int_t ncand(1);
   Int_t runNumber_temp(0);
   Int_t event_temp(0);
   
   TString sel("Precut");
   if (cut_code!=0) {
     sel="Finalcut";
     if (cut_code!=100) sel.Append(vect[cut_code-1]->GetName());
   }
   
   Int_t ncreco=0;
   Int_t ncrecomatch=0;
   Int_t nereco=0;
   Int_t nerecomatch=0;
   TFile* rootfile= new TFile("ASCII/"+sel+"_"+_Kstarc_decay+"_"+_d0mode+"_"+_sig_type+".root","recreate");
   for (Long64_t jentry=0; jentry<nentries;jentry++) {

     Long64_t ientry = LoadTree(jentry);
     if (ientry < 0) break;
     nb = fChain->GetEntry(jentry);   nbytes += nb;
     // codes for B decay code (ASCII file)
     Int_t ddecay_code = (_d0mode=="kspipi")? 1 : 2 ;   // 1=kspipi, 2=kskk
     Int_t bdecay_type_code = (_isCS==kFALSE)? 1000 : 2000 ; // 1000=DK*, 2000=DA1/rho
     
     
     //Float_t fisherDK=0.6565-0.9160*fabs(costhrust)+0.0210*legendrep0-0.1186*legendrep2-0.3828*fabs(cosChBCM);
     //   Float_t fisherDK=0.93416-0.939082*fabs(costhrust)+0.0322243*legendrep0-0.207507*legendrep2-0.272079*fabs(cosChBCM);//an-32
     Float_t fisherDK=0.968912-0.943614*fabs(costhrust)+0.0161328*legendrep0-0.176824*legendrep2-0.279403*fabs(cosChBCM); //an-51

     SigdlKs=decayLengthD0/sqrt(mydecayLengthCovD0);

     if (Cut(cut_code,kFALSE,fisherDK) < 0) continue;
     
     ncreco++; //contador despres del cut
     if(McEvtType==McEvt || McEvtType==McEvt2) ncrecomatch++; //contador candidats match
     
     //   cout<<"kaonidKstarckc despres tall="<<kaonidKstarckc<<endl;
     // cout<<"probchi2ChB DESPRES="<<probchi2ChB<<endl;
     
    
     
     // multiple candidates number definition
     //if ( (runNumber_temp==runNumber) && (event_temp==event))
     // cncand++; //contador de multipli candidati
     if ( (runNumber_temp==runNumber) && (event_temp==event)){ //same event
       ncand++;
       //  cout << "n cand = " << ncand<<endl;
     }
     else {
       Tmulti_cand->Fill(ncand);
       ncand=1;
       runNumber_temp=runNumber;
       event_temp=event;
       nereco++; //contador de multipli candidati
       if(McEvtType==McEvt || McEvtType==McEvt2) nerecomatch++;
     }
     
     //
     // fill histograms
     Tmes->Fill(mes); 
     Tdemk->Fill(demk2); 
     TmassD0->Fill(massD0); 
     TmassKs->Fill(massKs); 
     TcosKs->Fill(cosKs); 
     TcosKstarKs->Fill(cosVectorcReso); 
     TSigdlKs->Fill(SigdlKs);
      // Kaon ID bitmap
      if ((int(kaonidKstarckc)&16)==16) Tkaonid->Fill(1);
      else if ((int(kaonidKstarckc)&1)==1) Tkaonid->Fill(2);
      else if ((int(kaonidKstarckc)&2)==2) Tkaonid->Fill(3);
      else if ((int(kaonidKstarckc)&4)==4) Tkaonid->Fill(4);
      else if ((int(kaonidKstarckc)&8)==8) Tkaonid->Fill(5);
      else if ((int(kaonidKstarckc)&1024)==1024) Tkaonid->Fill(6);
      else if ((int(kaonidKstarckc)&2048)==2048) Tkaonid->Fill(7);
      else if ((int(kaonidKstarckc)&4096)==4096) Tkaonid->Fill(8);
      else if ((int(kaonidKstarckc)&8192)==8192) Tkaonid->Fill(9);
      else if ((int(kaonidKstarckc)&16384)==16384) Tkaonid->Fill(10);
      else Tkaonid->Fill(0);
     Tcosthrust->Fill(costhrust);
     Tcoshel->Fill(coseliVectorc);
     //if (coseliVectorc<0.) Tcoshel->Fill(coseliVectorc); 
     TmassVectorc->Fill(massVectorc); 
     TmassVectorcReso->Fill(massVectorcReso); 
     Tm0KstarcPi0->Fill(m0KstarcPi0); 
     Tprobchi2ChB->Fill(probchi2ChB);
     Tprobchi2D0->Fill(probchi2D0);


     TFisherDK->Fill(fisherDK);
   }

   cout<<"Reco Candidates counter = "<<ncreco<<endl;
   cout<<"Reco Match Candidates counter = "<<ncrecomatch<<endl;
   cout<<"Multiples Candidates number = "<<nereco<<endl;
   cout<<"Multiples Candidates Match number = "<<nerecomatch<<endl;
   cout<<"Candidates Multeplicity = "<<Double_t(ncreco)/Double_t(nereco)<<endl;
   if (ncrecomatch==0) nerecomatch=1;
   cout<<"Candidates Multeplicity Match = "<<Double_t(ncrecomatch)/Double_t(nerecomatch)<<endl;
   //  Double_t ef(0.);
   //  ef=Double_t(ncreco)/6580.;//kPi0
   //  ef=Double_t(ncreco)/4600.;//Kspi
   //  cout<<"efficiency = "<<ef<<endl;
 
   canvas->cd();
      
   Int_t style(1);
   if (_sig_type=="btdkstarc" || _sig_type=="btda1") style=(_Kstarc_decay=="kspi") ? 2:3;
   if (_sig_type=="chb") style=4;
   if (_sig_type=="b0b0bar") style=5;
   if (_sig_type=="bbbar") style=4;
   if (_sig_type=="uds")  style=6;
   if (_sig_type=="ccbar")  style=7;
   if (_sig_type=="udsccbar")  style=7;
   if (_sig_type=="chbNR") style=8;
   cout << "Making histograms with style = " << style << endl;

   gStyle->SetOptFit(0);
   gStyle->SetOptStat(111);

   TString d0mode_l(_d0mode);
   TString sig_type_l(_sig_type);

   if  (cut_code > 100) {

     for (Int_t j=0;j<=15;j++){
       vect[j]->SetLineWidth(style);
       vect[j]->SetLineColor(style);
       vect[j]->SetFillColor(style);
       vect[j]->Draw();
       TString filename="ASCII/"+sel+"_"+_Kstarc_decay+"_"+d0mode_l+"_"+sig_type_l+".ps";
       canvas->SaveAs(filename);
       f[j]= new TFile("ASCII/"+sel+"_"+_Kstarc_decay+"_"+d0mode_l+"_"+sig_type_l+".root","recreate");
       f[j]->cd();
       vect[j]->Write();
       f[j]->Close();
       delete f[j]; 
     }
     
   } else if(cut_code==0){

     for (Int_t j=0;j<=15;j++){
       vect[j]->SetLineWidth(style);
       vect[j]->SetLineColor(style);
       vect[j]->SetFillColor(style);
       vect[j]->Draw();
       //TString filename="ASCII/"+sel+"_"+_Kstarc_decay+"_"+d0mode_l+"_"+sig_type_l+".ps";
       //canvas->SaveAs(filename);
       //f[j]= new TFile("ASCII/"+sel+"_"+_Kstarc_decay+"_"+d0mode_l+"_"+sig_type_l+".root","recreate");
       //f[j]->cd();
       vect[j]->Write();
       //f[j]->Close();
       //delete f[j]; 
     }
     
   } else if (cut_code == 100) {

     vect[14]->SetLineWidth(style);
     vect[14]->SetLineColor(style);
     vect[14]->SetFillColor(style);
     vect[14]->Draw();
     TString filename="ASCII/"+sel+"multi_cand_"+_Kstarc_decay+"_"+d0mode_l+"_"+sig_type_l+".ps";
     canvas->SaveAs(filename);
     f[14]= new TFile("ASCII/"+sel+"multi_cand_"+_Kstarc_decay+"_"+d0mode_l+"_"+sig_type_l+".root","recreate");
     f[14]->cd();
     vect[14]->Write();
     f[14]->Close();
     delete f[14]; 
 
   } else {
     
     vect[cut_code-1]->SetLineWidth(style);
     vect[cut_code-1]->SetLineColor(style);
     vect[cut_code-1]->SetFillColor(style);
     vect[cut_code-1]->Draw();
     TString filename="ASCII/"+sel+"_"+_Kstarc_decay+"_"+d0mode_l+"_"+sig_type_l+".ps";
     canvas->SaveAs(filename);
     f[cut_code-1]= new TFile("ASCII/"+sel+"_"+_Kstarc_decay+"_"+d0mode_l+"_"+sig_type_l+".root","recreate");
     f[cut_code-1]->cd();
     vect[cut_code-1]->Write();
     f[cut_code-1]->Close();
     delete f[cut_code-1]; 
   }
   rootfile->Close();
}


//This gives you the Chi-square inverse value calculated using  massD0 and  massVectorc (m0Pi0). 
//This gives you the Chi-square inverse value in a way that the best candidate would be the one with the highest 1/chi2 value.

Double_t btdkstarc_final::getchi(Float_t mPi0,Float_t mKstar, Float_t mD0)
{
  //mD0 = massD0 mKstar=massVectorc  mPi0 = m0KstarcPi0
  Double_t Kstar_width=(_isCS==kTRUE)? (0.25+0.6)/2 :0.050;
  Double_t massD0m,massD0s,massKstarm,massKstars,m0Pi0m,m0Pi0s;
  // from signal MC
  massD0m=1.8645;
  massD0s=0.0073;
  massKstarm=(_isCS==kTRUE)? 1.230 : 0.892;
  massKstars=(_isCS==kTRUE)? 0.040 : 0.015;
  m0Pi0m=0.135;
  m0Pi0s=0.0075;
   Double_t chi2= 
  (mD0-massD0m)*(mD0-massD0m)/(massD0s*massD0s) +   // chi2 D0 contibution 
  (mKstar-massKstarm)*(mKstar-massKstarm)/(massKstars*massKstars+Kstar_width*Kstar_width); //chi2 Kstar contribution 
  //Double_t chi2= 
  //(mD0-massD0m)*(mD0-massD0m)/(2.35*2.35*massD0s*massD0s) +   // chi2 D0 contibution 
  //(mKstar-massKstarm)*(mKstar-massKstarm)/(2.35*2.35*massKstars*massKstars+Kstar_width*Kstar_width); //chi2 Kstar contribution 
  if (_Kstarc_decay == "kpi0" )  chi2 += (mPi0-m0Pi0m)*(mPi0-m0Pi0m)/(m0Pi0s*m0Pi0s);
  //cout<<"chi2 ="<<chi2<<endl;
  Double_t invchi2=1./chi2;  
  return invchi2;  
}//end getchi


void btdkstarc_final::LoopBest(Int_t cut_code, Long64_t nentries, Int_t opt)
{


  //cut 500 for cut only in particular_cut cut
  // opt: 1=dump ascii file, 2=do not dump ascii file

  gROOT->SetStyle("Plain");
  if (fChain == 0) return;

  char cut_code_str[10];
  sprintf(cut_code_str,"Cut%i",cut_code);

  TString sdec= (_isCS==kFALSE)? "btdkstarc_" :"btda1_";
  TString outname="ASCII/"+sdec+_Kstarc_decay+"_"+_d0mode+"_"+_sig_type+"_Bbest_"+TString(cut_code_str)+".dat";
  TString outname_fakeD0="ASCII/"+sdec+_Kstarc_decay+"_"+_d0mode+"_"+_sig_type+"_Bbest_"+TString(cut_code_str)+"_fakeD0.dat";
  TString outname_matched="ASCII/"+sdec+_Kstarc_decay+"_"+_d0mode+"_"+_sig_type+"_Bbest_"+TString(cut_code_str)+"_matched.dat";
  TString outname_kappa="ASCII/"+sdec+_Kstarc_decay+"_"+_d0mode+"_"+_sig_type+"_Bbest_"+TString(cut_code_str)+"_kappa.dat";

  //TString testname="ASCII/"+sdec+_Kstarc_decay+"_"+TString(_d0mode)+"_"+_sig_type+"_mesdemk_"+TString(cut_code_str)+".dat";
  cout<< "file dat = "<< outname <<endl;
  ofstream outfile(outname);
  ofstream outfile_fakeD0(outname_fakeD0);
  ofstream outfile_matched(outname_matched);
  ofstream outfile_kappa(outname_kappa);

  //ofstream outtest(testname);

  TString outfile_name="ASCII/bkg_"+_Kstarc_decay+"_"+_d0mode+"_"+_sig_type+".study";
  ofstream outfile2(outfile_name);
  cout<<"outfile name "<<_sig_type<<" "<<_Kstarc_decay<<" = " <<outfile_name<<endl;

  //Float_t mD0_nom=1.8645;
  Float_t mKs_nom=0.4977;
  Float_t mpi_nom=0.1396;
  
  Int_t nbins(50);
  TH1F* Tm12 = new TH1F("Tm12","delta q12-m12 distribution",nbins,-0.04,0.04);
  TH1F* Tm13 = new TH1F("Tm13","delta q13-m13 distribution",nbins,-0.04,0.04);
  TH1F* Tm23 = new TH1F("Tm23","delta q23-m23 distribution",nbins,-0.04,0.04);
  TH2F* Tdalitz = new TH2F("Tdalitz","Dalitz plot q12:q13",nbins*2,0,4.,nbins*2,0,4.);
  TH1F* Tmulti_cand = new TH1F("Tmulti_cand","Multiple Candidate distribution",10,1.0,10);
  TH2F* Tmesdemk = new TH2F("Tmesdemk","mES-DeltaE distribution",nbins,roomes->getMin(),roomes->getMax(),nbins,roodemk->getMin(),roodemk->getMax()); 
  //
  TH1F  *vect[10];
  TH1F* Tmes = new TH1F("mes","mES distribution",nbins,roomes->getMin(),roomes->getMax()); 
  vect[0]=Tmes;
  TH1F* Tdemk = new TH1F("demk","DeltaE distribution",nbins,roodemk->getMin(),roodemk->getMax()); 
  vect[1]=Tdemk;
  TH1F* TfisherDK = new TH1F("fisherDK","fisher distribution",nbins,roofisherDK->getMin(),roofisherDK->getMax()); 
  vect[2]=TfisherDK;
  TH1F* TmassVectorcReso = new TH1F("massVectorcReso","massVectorcReso distribution",nbins,0.75,1.05); 
  vect[3]=TmassVectorcReso;
  TH1F* TmassVectorc = new TH1F("massVectorc","massKstar distribution",nbins,0.8,1.); 
  vect[4]=TmassVectorc;
  TH1F* TmassD0matched = new TH1F("massD0matched","massD0 distribution",nbins,roomassD0->getMin(),roomassD0->getMax()); 
  vect[5]=TmassD0matched;
  TH1F* TcoseliVectorc = new TH1F("CosHely","CosHely distribution",nbins,-1,1); 
  vect[6]=TcoseliVectorc;
  TH1F* TControl = new TH1F("control","control",nbins,-1.,1.);
  TH1F* TSigdlKs = new TH1F("TSigdlKs","SigdlKs distribution",nbins,-300,4000);
  vect[7]=TSigdlKs;
  TH1F* TmassD0fake = new TH1F("massD0fake","massD0 distribution",nbins,roomassD0->getMin(),roomassD0->getMax()); 
  vect[8]=TmassD0fake;
  TmassD0fake->SetMinimum(0.);
  TH1F* TmassD0 = new TH1F("massD0","massD0 distribution",nbins,roomassD0->getMin(),roomassD0->getMax()); 
  vect[9]=TmassD0;




  RooDataSet* dataset = new RooDataSet("dataset","dataset",roovars);
  
  //############################################################3
  Int_t prevrun=0;
  Int_t prevev=0;
  Int_t debug=0;
  
  Bool_t isfirst=true;
  Int_t mul=0;      // event multeplicity
  Int_t istrue=0;   // true event multeplicity
  Int_t num1=0;     // mult=1 ev # 
  Int_t num1t=0;    // true  mult=1 cand # 
  Int_t num1f=0;    // false mult=1 cand #  
  Int_t numtrue=0;  // mul>1 ev # with a  true cand
  Int_t numfalse=0; // mul>1 ev # with no true cand 
  Int_t totcand=0;  // tot cand #
  Int_t totevt=0;   // tot ev #
  Int_t num_right_choice=0;// mul>1 ev # where it has been choose a true cand
  Int_t num_wrong_choice=0;// mul>1 ev # where it has been choose a false cand
  Int_t ntot=0;//
  
  Double_t multiplicity(0);

  Double_t actualprob(0);
  Int_t actualevent(0);
  Int_t actualrunNumber(0);
  Float_t actualmassVectorcReso(0);
  Float_t actualmassVectorc(0);

  Double_t actualSigdlKs(0);

  Int_t actualupperID(0);
  Int_t actuallowerID(0);

  Double_t actualmassD0(0);
  Double_t actualmes(0);
  Double_t actualdemk(0);
  Int_t actualChBtruth(0);
  Float_t actualm12(0);    
  Float_t actualm13(0);    
  Float_t actualm23(0);    
  Float_t actualfisherDK(0);
  Float_t actualppr(0);

  Float_t actualcoseliVectorc(0);
  Float_t actualbeta_Gamma(0);
  Int_t actualchargeb(0);
  Float_t actualq12(0);
  Float_t actualq13(0);
  Float_t actualq23(0);
  Int_t actualMcEvtType(0);

  Int_t actualisMcD0(0);
  Int_t actualisMcD0Matched(0);
  Int_t actualisMcD0id(0);
  Int_t totD0bc=0;               //total number of best candidates with matched D0
  Int_t actuallundVectorc(0);
  Int_t totKstarRSbc(0);         //total number of best candidates with matched D0 and a K*-, or matched anti-D0 and a K*+
  
  Int_t totD0=0;                 //total number of candidates with matched D0, w/o bc choice
  Int_t totKstarRS(0);           //total number of candidates with matched D0 and a K*-, or matched anti-D0 and a K*+
  Int_t totSigWSbc(0);           //total number of best candidates WS signal
  Int_t totSigWS(0);             //total number of candidates WS signal

  Int_t actualjentry(0);


  Int_t totSignalWSbc(0);
  Int_t totSignalRSbc(0);
  Int_t totRSWSignal(0);
  Int_t actualindexMcVectorc(0);
  Float_t actualq12_truth(0);    
  Float_t actualq13_truth(0);    
  Float_t actualq23_truth(0);  
  Int_t actualchargeB_truth(0);  

  Float_t actualpxD0(0.),actualpyD0(0.),actualpzD0(0.);
  Float_t actualpxVectorcReso(0.),actualpyVectorcReso(0.),actualpzVectorcReso(0.);
  Float_t actualpxVectorcpic(0.),actualpyVectorcpic(0.),actualpzVectorcpic(0.),actualmassVectorcpic(0.);
  Float_t actualpxChB(0.),actualpyChB(0.),actualpzChB(0.),actualmassChB(0.);

  //####################################################
  
  if (fChain == 0) return;
  
  if (nentries<=0 || nentries>fChain->GetEntries()) nentries = Int_t(fChain->GetEntries());
  cout<< "Number of Entries = " <<nentries<<endl; 

  // codes for B decay code (ASCII file)
  Int_t ddecay_code = (_d0mode=="kspipi")? 1 : 2 ;   // 1=kspipi, 2=kskk
  Int_t bdecay_type_code = (_isCS==kFALSE)? 1000 : 2000 ; // 1000=DK*, 2000=DA1/rho
  
  Int_t nbytes = 0, nb = 0;

  for (Int_t jentry=0; jentry<nentries;jentry++) {

    Int_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    nb = fChain->GetEntry(jentry);   
    nbytes += nb;

    //Float_t fisherDK=(0.595+0.1372*cosChBCM-0.2983*legendrep2+0.1172*legendrep0-1.6151*fabs(costhrust));
    //Float_t fisherDK=0.6565-0.9160*fabs(costhrust)+0.0210*legendrep0-0.1186*legendrep2-0.3828*fabs(cosChBCM);
    //   Float_t fisherDK=0.93416-0.939082*fabs(costhrust)+0.0322243*legendrep0-0.207507*legendrep2-0.272079*fabs(cosChBCM);//an-32
    Float_t fisherDK=0.968912-0.943614*fabs(costhrust)+0.0161328*legendrep0-0.176824*legendrep2-0.279403*fabs(cosChBCM); //an-51

    //Significancia del dl del KS
    SigdlKs=decayLengthD0/sqrt(mydecayLengthCovD0);
    
    
    if (Cut(cut_code,kFALSE,fisherDK) < 0) continue;
    //cout<<"aprobado el corte"<<endl;
    //Float_t pD0=sqrt(pxD0*pxD0+pyD0*pyD0+pzD0*pzD0);
    //Float_t pD0CM=pcmsD0;

    // if event accepted, calculate relevant variables for the fit (data members)
    Int_t ChBtruth= (McEvtType==McEvt || McEvtType==McEvt2) ? 1 : 0;
    Int_t chargeb= (lundVectorc>0) ? 1 : 0;
    Float_t eD0Pi1=sqrt(pxD0Pi1*pxD0Pi1+pyD0Pi1*pyD0Pi1+pzD0Pi1*pzD0Pi1+mpi_nom*mpi_nom);
    Float_t eD0Pi2=sqrt(pxD0Pi2*pxD0Pi2+pyD0Pi2*pyD0Pi2+pzD0Pi2*pzD0Pi2+mpi_nom*mpi_nom);
    Float_t eKs=sqrt(pxKs*pxKs+pyKs*pyKs+pzKs*pzKs+mKs_nom*mKs_nom);
    TLorentzVector vKs,vPi1,vPi2;
    vKs.SetPxPyPzE(pxKs,pyKs,pzKs,eKs);
    vPi1.SetPxPyPzE(pxD0Pi1,pyD0Pi1,pzD0Pi1,eD0Pi1);
    vPi2.SetPxPyPzE(pxD0Pi2,pyD0Pi2,pzD0Pi2,eD0Pi2);
    Float_t m12=(lundD0Pi1>0)? (vKs+vPi1).Mag2() : (vKs+vPi2).Mag2() ;  // m2p
    Float_t m13=(lundD0Pi1<0)? (vKs+vPi1).Mag2() : (vKs+vPi2).Mag2() ;  // m2m
    Float_t m23=(vPi1+vPi2).Mag2();  // m2z

    Float_t ppr=0.;
    //Float_t ppr=sqrt(pxpr*pxpr+pypr*pypr+pzpr*pzpr);
    Float_t beta_Gamma=pzUps/sqrt(eUps*eUps-pxUps*pxUps-pyUps*pyUps-pzUps*pzUps);
    Float_t q12(0.),q13(0.),q23(0.);
    Float_t massVectorcpic = mpi_nom;

    // evaluate and apply scaling factor
    //TLorentzVector vKsscal(vKs),vPi1scal(vPi1),vPi2scal(vPi2);
    //Double_t alpha;
    //alpha = Rescaling(vKsscal,vPi1scal,vPi2scal,mD0_nom,vKs.Mag(),vPi1.Mag(),vPi2.Mag());
    //q12 = (vKsscal+vPi1scal).Mag2();
    //q13 = (vKsscal+vPi2scal).Mag2();
    //q23 = (vPi1scal+vPi2scal).Mag2();  
    q12 = m2pDalitzD0;
    q13 = m2mDalitzD0;
    q23 = m2zDalitzD0;
 
    //assert(q12>0 && q23>0 && q13>0);       
  
    Float_t* dalVarsTruthInfo = new Float_t[4];
    for(Int_t i=0;i<4;i++) dalVarsTruthInfo[i]=-999;
    dalVarsTruth(ChBtruth,dalVarsTruthInfo);
    Int_t chargeB_truth = (Int_t) dalVarsTruthInfo[0];
    Float_t q12_truth = dalVarsTruthInfo[1];
    Float_t q13_truth = dalVarsTruthInfo[2];
    Float_t q23_truth = dalVarsTruthInfo[3];


    // counting w/o bc choice
    Int_t isMcD0id = idMc[mothMc[indexMcD0Pi1]-1];
    if (isMcD0) {
      totD0++;
      //assert(abs(isMcD0id)==421 && ((_sig_type!="btda1" && abs(lundVectorc)==323)||(_sig_type=="btda1" && abs(lundVectorc)==20213)) );
      if ( (isMcD0id==421 && ((_isCS==kFALSE && lundVectorc==-323)||(_isCS==kTRUE && lundVectorc==-20213))) || (isMcD0id==-421 && ((_isCS==kFALSE && lundVectorc==323)||(_isCS==kTRUE && lundVectorc==20213))) ) totKstarRS++;
    } 
    if  ( (McEvtType&3841==3841 || McEvtType&3842==3842) && 
	  ((isMcD0id==-421 && ((_isCS==kFALSE && lundVectorc==-323)||(_isCS==kTRUE && lundVectorc==-20213))) || (isMcD0id==421 && ((_isCS==kFALSE && lundVectorc==323)||(_isCS==kTRUE && lundVectorc==20213)))) ) totSigWS++;
    


    //if it passes the selection--> fill the histos
    
    //################################################################
    //################    best candidate choice   ####################
    //################################################################
    
    if (event==prevev && runNumber==prevrun){
      // SAME EVENT

      Double_t thisprob=getchi(m0KstarcPi0,massVectorc,massD0);
      
      if (debug){
	cout<<"This ev is identical to the previous"<<endl;
	cout<<"event="<<event<<endl;
	cout<<"mes="<<mes<<endl;
	cout<<"massD0="<<massD0<<endl;
	cout<<"massVectorc="<<massVectorc<<endl;
	cout<<"thisprob="<<thisprob<<endl;
      }

      if (thisprob>actualprob){
	if (debug) cout<<"this cand probability is  > the previous ones"<<endl;
	actualevent=event;
	actualrunNumber=runNumber;
	actualupperID=upperID;
	actuallowerID=lowerID;

	actualSigdlKs=SigdlKs;
	actualmassD0=massD0;
	actualmes=mes;
	//	    actualthcpr=thcpr;
	//	    actualthcerrpr=thcerrpr;
	//	    actualdeltadrcmompr=deltadrcmompr;
	actualdemk=demk2;
	actualChBtruth=ChBtruth;	    
	actualfisherDK=fisherDK;
	actualppr=ppr;
	actualcoseliVectorc=coseliVectorc;
	actualbeta_Gamma=beta_Gamma;
	actualchargeb=chargeb;
	actualq12=q12;
	actualq13=q13;
	actualq23=q23;
	actualq12_truth=q12_truth;
	actualq13_truth=q13_truth;
	actualq23_truth=q23_truth;
	actualchargeB_truth=chargeB_truth;
	actualMcEvtType=McEvtType;
	actualm12=m12;
	actualm13=m13;
	actualm23=m23;
	actualprob=thisprob;
	actualmassVectorcReso=massVectorcReso;
	actualmassVectorc=massVectorc;

	actualisMcD0=isMcD0;
	actualisMcD0Matched=isMcD0Matched;
        actualisMcD0id=idMc[mothMc[indexMcD0Pi1]-1];
	actuallundVectorc=lundVectorc;
	actualindexMcVectorc=indexMcVectorc;
	actualjentry=jentry;

	actualpxD0=pxD0;actualpyD0=pyD0;actualpzD0=pzD0;actualmassD0=massD0;
	actualpxVectorcReso=pxVectorcReso;actualpyVectorcReso=pyVectorcReso;actualpzVectorcReso=pzVectorcReso;actualmassVectorcReso=massVectorcReso;
	actualpxVectorcpic=pxVectorcpic;actualpyVectorcpic=pyVectorcpic;actualpzVectorcpic=pzVectorcpic;actualmassVectorcpic=massVectorcpic;
	actualpxChB=pxChB;actualpyChB=pyChB;actualpzChB=pzChB;actualmassChB=massChB;

      } else {
	//leave everything like it is
      }

      //end probability evaluation
      mul++;
      prevev=event;
      prevrun=prevrun;
      // mul>1 events truepart
      if (ChBtruth==1) istrue++;

    }// (event==prevev && ....

    else {
      // EVENT CHANGED

      if (!isfirst){

	// now it is working on the previous event
	//          evaluating the probability 
	if (debug){
	  cout<<endl<<"previous event probability  is:  "<<actualprob<<endl;
	  cout<<"previous event actualdemk is:  "<<actualdemk<<endl;
	}	
	if (opt==1){	    

	  //outtest << actualdemk<<"     "<< actualmes<<"     " << actualmassD0<<"     " << actualfisherDK<<endl;

	  outfile<<"1"<<" "<< bdecay_type_code+200+100*_Kstarc_decay_code+ddecay_code <<" "<< actualchargeb<<" " 
		 << actualq12  << " " << actualq13 << " " << actualq23     << " " 
		 <<"0" << " " <<"0" << " " << "0"<< " " << "0"<< " " 
		 <<actualdemk << " " << actualppr << " "     << actualbeta_Gamma<< " " 
		 <<actualmes << " " << actualmassD0 << " " << actualfisherDK<< " " 
		 <<actualrunNumber << " "<<actualupperID<<" "<<actuallowerID<<endl;
	  
	  //if (actualisMcD0==0)
	  if(!(actualMcEvtType&3841==3841 || actualMcEvtType&3842==3842))
	    outfile_fakeD0<<"1"<<" "<< bdecay_type_code+200+100*_Kstarc_decay_code+ddecay_code <<" "<< actualchargeb<<" " 
			  << actualq12  << " " << actualq13 << " " << actualq23     << " " 
			  <<"0" << " " <<"0" << " " << "0"<< " " << "0"<< " " 
			  <<actualdemk << " " << actualppr << " "     << actualbeta_Gamma<< " " 
			  <<actualmes << " " << actualmassD0 << " " << actualfisherDK<< " " 
			  <<actualrunNumber <<" "<<actualupperID<<" "<<actuallowerID<<endl;
	  //if((actualMcEvtType==McEvt || actualMcEvtType==McEvt2) && (actualisMcD0id==-421 &&actuallundVectorc==-323))
	  //if((actualMcEvtType==McEvt || actualMcEvtType==McEvt2) && 
	  // ((actualisMcD0id==-421 && actuallundVectorc==323) ||
	  // (actualisMcD0id==421 && actuallundVectorc==-323)) )
	  if((actualMcEvtType&3841==3841 || actualMcEvtType&3842==3842) &&
	     ((actualisMcD0id==421 && ((_isCS==kFALSE && actuallundVectorc==-323)||(_isCS==kTRUE && actuallundVectorc==-20213))) || 
	      (actualisMcD0id==-421 && ((_isCS==kFALSE && actuallundVectorc==323)||(_isCS==kTRUE && actuallundVectorc==20213))))) 
	    outfile_matched <<"1"<<" "<< bdecay_type_code+200+100*_Kstarc_decay_code+ddecay_code <<" "<< actualchargeb<<" " 
			    << actualq12  << " " << actualq13 << " " << actualq23 << " " 
			    <<actualchargeB_truth << " " <<actualq12_truth << " " << actualq13_truth<< " " << actualq23_truth<< " "
			    <<actualdemk << " " << actualppr << " " << actualbeta_Gamma<< " " 
			    <<actualmes << " " << actualmassD0 << " " <<" " << actualfisherDK<< " " 
			    <<actualrunNumber <<" "<<actuallowerID<< " "<<actualupperID<<endl; 
	  outfile_kappa<<actualchargeb<<" "
		       <<actualpxD0<<" "<<actualpyD0<<" "<<actualpzD0<<" "<<actualmassD0<<" "
		       <<actualpxVectorcReso<<" "<<actualpyVectorcReso<<" "<<actualpzVectorcReso<<" "<<actualmassVectorcReso<<" "
		       <<actualpxVectorcpic<<" "<<actualpyVectorcpic<<" "<<actualpzVectorcpic<<" "<<actualmassVectorcpic<<" "
		       <<actualpxChB<<" "<<actualpyChB<<" "<<actualpzChB<<" "<<actualmassChB<<endl;

	  roomes->setVal(actualmes);
	  roodemk->setVal(actualdemk);
	  roomassD0->setVal(actualmassD0);
	  roofisherDK->setVal(actualfisherDK);
	  dataset->add(roovars);
	  
	  TfisherDK->Fill(actualfisherDK);
	  Tmes->Fill(actualmes);
	  Tdemk->Fill(actualdemk);
	  Tm12->Fill(actualq12-actualm12);
	  Tm13->Fill(actualq13-actualm13);
	  Tm23->Fill(actualq23-actualm23);
	  Tdalitz->Fill(actualq12,actualq13);
	  Tmesdemk->Fill(actualmes,actualdemk);



	  //	  TmassD0->Fill(actualmassD0);
	  //fake D0
	  if(isMcD0Matchedfunction(actualisMcD0Matched))  TmassD0matched->Fill(actualmassD0);
	  if(!isMcD0Matchedfunction(actualisMcD0Matched))  TmassD0fake->Fill(actualmassD0);
	  TmassD0->Fill(actualmassD0);


	  TmassVectorcReso->Fill(actualmassVectorcReso);
	  TmassVectorc->Fill(actualmassVectorc);
	  TSigdlKs->Fill(actualSigdlKs);

	  TcoseliVectorc->Fill(actualcoseliVectorc);
	  if (cut_code==100) {
	    // get actualjentry
	    ientry = LoadTree(actualjentry);
	    if (ientry < 0) break;
	    nb = fChain->GetEntry(actualjentry); 
	    bkg_tree(outfile2);
	    // retrieve jentry
	    ientry = LoadTree(jentry);
	    if (ientry < 0) break;
	    nb = fChain->GetEntry(jentry); 
	  }

	} else if (opt==2){
	  //	      outfile<<mul<<endl;
	} else assert(0);
	
	totcand+=mul;
	totevt++;


	//NEW fractions

        if (isMcD0Matchedfunction(actualisMcD0Matched)) {
	  totD0bc++;
	  if ( (actualisMcD0id==421 &&((_isCS==kFALSE && actuallundVectorc==-323)||( _isCS==kTRUE && actuallundVectorc==-20213)) ) || (actualisMcD0id==-421 && ((_isCS==kFALSE && actuallundVectorc==323)||(_isCS==kTRUE && actuallundVectorc==20213))) ) totKstarRSbc++;
	}

	// old stuff .  ??
	//	if  ( (actualMcEvtType&3841==3841 || actualMcEvtType&3842==3842) && 
	//     ((actualisMcD0id==-421 && ((_isCS==kFALSE && actuallundVectorc==-323)||(_isCS==kTRUE && actuallundVectorc==-20213))) || (actualisMcD0id==421 && ((_isCS==kFALSE && actuallundVectorc==323)||(_isCS==kTRUE && actuallundVectorc==20213)))) ) totSigWSbc++;


  //Nou! ########################### per la càlcul de right sign in wrong signal

	if (isMcD0Matchedfunction(actualisMcD0Matched)) {
	  if(isMcprMatchedfunction(actualMcEvtType))
	    totSignalRSbc++;
	  else{
	    totSignalWSbc++;
	    if ( (actualisMcD0id==421 &&((_isCS==kFALSE && actuallundVectorc==-323)||( _isCS==kTRUE && actuallundVectorc==-20213)) ) || (actualisMcD0id==-421 && ((_isCS==kFALSE && actuallundVectorc==323)||(_isCS==kTRUE && actuallundVectorc==20213))) ) totRSWSignal++;
	  }
	}



	//old bad stuff 
	
// 	if  ( actualisMcD0 && ((actualMcEvtType&3841)==3841 || (actualMcEvtType&3842)==3842) 
// 	      && ((actualMcEvtType&29)!=29 && (actualMcEvtType&30)!=30)  
// 	      && ((actualisMcD0id==-421 && ((_isCS==kFALSE && actuallundVectorc==323)||(_isCS==kTRUE && actuallundVectorc==20213))) || (actualisMcD0id==421 && ((_isCS==kFALSE && actuallundVectorc==-323)||(_isCS==kTRUE && actuallundVectorc==-20213)))) ) totRSWSignal++;
// 	if  ( actualisMcD0 && (actualMcEvtType&3841==3841 || actualMcEvtType&3842==3842) 
// 	      &&  ((actualMcEvtType&29)!=29 && (actualMcEvtType&30)!=30) 
// 	      )totSignalWSbc++;
// 	if  ( actualisMcD0 && (actualMcEvtType&3869==3869 || actualMcEvtType&3870==3870))totSignalRSbc++;
	     


	


	//se la molteplicita' dell'evento precedente e'>1, valuta numtrue e numfalse
	if (mul>1) {(istrue>0)? numtrue++ : numfalse++;}
	//se mul>1, calcola il numero di volte in cui la scelta sel. il cand vero o falso
	if (mul>1 && istrue>0 && actualChBtruth==1)num_right_choice++;
	if (mul>1 && istrue>0 && actualChBtruth==0)num_wrong_choice++;
	
	//---
	//if the previous ev multeplicity is =1 --> evaluate num1t e num1f
	if (mul==1) num1++;
	if (mul==1) {(istrue>0)? num1t++ : num1f++;}
	//---

	
	// now it is working on the NEW event
	//          evaluating the probability 

	Double_t thisprob=getchi(m0KstarcPi0,massVectorc,massD0);
	actualevent=event;
	actualrunNumber=runNumber;
	actualupperID=upperID;
	actuallowerID=lowerID;

	actualmassD0=massD0;	 
	actualmes=mes;
	// 	    actualthcpr=thcpr;
	// 	    actualthcerrpr=thcerrpr;
	// 	    actualdeltadrcmompr=deltadrcmompr;
	actualdemk=demk2;
	actualChBtruth=ChBtruth;
	actualfisherDK=fisherDK;
	actualppr=ppr;
	actualcoseliVectorc=coseliVectorc;
	actualbeta_Gamma=beta_Gamma;
	actualchargeb=chargeb;
	actualq12_truth=q12_truth;
	actualq13_truth=q13_truth;
	actualq23_truth=q23_truth;
	actualchargeB_truth=chargeB_truth;
	actualq12=q12;
	actualq13=q13;
	actualq23=q23;
	actualMcEvtType=McEvtType;
	actualm12=m12;
	actualm13=m13;
	actualm23=m23;	
	actualprob=thisprob;
	actualmassVectorcReso=massVectorcReso;
	actualmassVectorc=massVectorc;

	actualSigdlKs=SigdlKs;
	actualisMcD0=isMcD0; 
	actualisMcD0Matched=isMcD0Matched; 
        actualisMcD0id=idMc[mothMc[indexMcD0Pi1]-1];
	actuallundVectorc=lundVectorc; 
	actualindexMcVectorc=indexMcVectorc;
	actualjentry=jentry;

	actualpxD0=pxD0;actualpyD0=pyD0;actualpzD0=pzD0;actualmassD0=massD0;
	actualpxVectorcReso=pxVectorcReso;actualpyVectorcReso=pyVectorcReso;actualpzVectorcReso=pzVectorcReso;actualmassVectorcReso=massVectorcReso;
	actualpxVectorcpic=pxVectorcpic;actualpyVectorcpic=pyVectorcpic;actualpzVectorcpic=pzVectorcpic;actualmassVectorcpic=massVectorcpic;
	actualpxChB=pxChB;actualpyChB=pyChB;actualpzChB=pzChB;actualmassChB=massChB;

	if (debug){
	  cout<<"event="<<event<<endl;
	  cout<<"mes="<<mes<<endl;
	  cout<<"massD0="<<massD0<<endl;
	  cout<<"massVectorc="<<massVectorc<<endl;
	  cout<<"la probab di questo evento e' "<<actualprob<<endl;
	  cout<<"actualdemk di questo evento e' "<<actualdemk<<endl;
	}
	Tmulti_cand->Fill(mul);
	//if (istrue>0) Tmulti_cand_truth->Fill(mul);
	mul=1;
	istrue=0;
	prevev=event;
	prevrun=runNumber;
	//parte di verita' in eventi con mul>1
	if (ChBtruth==1) istrue++;

      }//end !ifirst cond

      else { // start ifirst cond

	//evaluating the first event probability
	Double_t thisprob=getchi(m0KstarcPi0,massVectorc,massD0);
	actualevent=event;
	actualrunNumber=runNumber;
	actualupperID=upperID;
	actuallowerID=lowerID;
	actualmassD0=massD0;
	actualmes=mes;
	// 	    actualthcpr=thcpr;
	// 	    actualthcerrpr=thcerrpr;
	// 	    actualdeltadrcmompr=deltadrcmompr;
	actualdemk=demk2;
	actualChBtruth=ChBtruth;
	actualfisherDK=fisherDK;
	actualppr=ppr;
	actualcoseliVectorc=coseliVectorc;
	actualbeta_Gamma=beta_Gamma;
	actualchargeb=chargeb;
	actualq12=q12;
	actualq13=q13;
	actualq23=q23;
	actualq12_truth=q12_truth;
	actualq13_truth=q13_truth;
	actualq23_truth=q23_truth;
	actualchargeB_truth=chargeB_truth;
	actualMcEvtType=McEvtType;
	actualm12=m12;
	actualm13=m13;
	actualm23=m23;
	actualprob=thisprob;
	actualmassVectorcReso=massVectorcReso;
	actualmassVectorc=massVectorc;

	actualSigdlKs=SigdlKs;
	actualisMcD0=isMcD0;
	actualisMcD0Matched=isMcD0Matched; 
        actualisMcD0id=idMc[mothMc[indexMcD0Pi1]-1];
	actuallundVectorc=lundVectorc; 
	actualindexMcVectorc=indexMcVectorc;
      	actualjentry=jentry;

	actualpxD0=pxD0;actualpyD0=pyD0;actualpzD0=pzD0;actualmassD0=massD0;
	actualpxVectorcReso=pxVectorcReso;actualpyVectorcReso=pyVectorcReso;actualpzVectorcReso=pzVectorcReso;actualmassVectorcReso=massVectorcReso;
	actualpxVectorcpic=pxVectorcpic;actualpyVectorcpic=pyVectorcpic;actualpzVectorcpic=pzVectorcpic;actualmassVectorcpic=massVectorcpic;
	actualpxChB=pxChB;actualpyChB=pyChB;actualpzChB=pzChB;actualmassChB=massChB;

	if (debug) {
	  cout<<"Questo e' il primo evento"<<endl;
	  cout<<"event="<<event<<endl;
	  cout<<"mes="<<mes<<endl;
	  cout<<"massD0="<<massD0<<endl;
	  cout<<"massVectorc="<<massVectorc<<endl;
	  cout<<"thisprob="<<thisprob<<endl;
	}
	//end probability evalu
	
	//set to false the isfirst flag
	isfirst=false;
	mul=1;
	istrue=0;
	prevev=event;
	prevrun=runNumber;
	//true part with mul>1
	if (ChBtruth==1) istrue++;
	
      }//end isfirst cond
      
    }//end else
    
    ntot++;
    
  } // end loop 
  
  
  //###################################################################################
  
  //###################################################################################
  
  //end loop and make a check on last loop event, that , for construction, has escaped to the check
  totcand+=mul;
  totevt++;


  //new fractions

 if (isMcD0Matchedfunction(actualisMcD0Matched)) {
	  totD0bc++;
	  if ( (actualisMcD0id==421 &&((_isCS==kFALSE && actuallundVectorc==-323)||( _isCS==kTRUE && actuallundVectorc==-20213)) ) || (actualisMcD0id==-421 && ((_isCS==kFALSE && actuallundVectorc==323)||(_isCS==kTRUE && actuallundVectorc==20213))) ) totKstarRSbc++;
	}

	if (isMcD0Matchedfunction(actualisMcD0Matched)) {
	  if(isMcprMatchedfunction(actualMcEvtType))
	    totSignalRSbc++;
	  else{
	    totSignalWSbc++;
	    if ( (actualisMcD0id==421 &&((_isCS==kFALSE && actuallundVectorc==-323)||( _isCS==kTRUE && actuallundVectorc==-20213)) ) || (actualisMcD0id==-421 && ((_isCS==kFALSE && actuallundVectorc==323)||(_isCS==kTRUE && actuallundVectorc==20213))) ) totRSWSignal++;
	  }
	}





  //old stuff

//   if (actualisMcD0) {
//     totD0bc++;
//     //cout << actualisMcD0id << " " << actuallundVectorc << endl;
//     //assert(abs(actualisMcD0id)==421 && ((_sig_type!="btda1" && abs(actuallundVectorc==323))||(_sig_type=="btda1" && abs(actuallundVectorc)==20213)));
//     if ( (actualisMcD0id==421 &&((_isCS==kFALSE && actuallundVectorc==-323)||(_isCS==kTRUE && actuallundVectorc==-20213)) ) || (actualisMcD0id==-421 && ((_isCS==kFALSE && actuallundVectorc==323)||(_isCS==kTRUE && actuallundVectorc==20213))) ) totKstarRSbc++;
//   }
//   if((actualMcEvtType&3841==3841 || actualMcEvtType&3842==3842) &&
//     ((actualisMcD0id==-421 && ((_isCS==kFALSE && actuallundVectorc==-323)||(_isCS==kTRUE && actuallundVectorc==-20213))) || (actualisMcD0id==421 && ((_isCS==kFALSE && actuallundVectorc==323)||(_isCS==kTRUE && actuallundVectorc==20213))))) totSigWSbc++;




//   if  ( actualisMcD0 && ((actualMcEvtType&3841)==3841 || (actualMcEvtType&3842)==3842) 
// 	&& ((actualMcEvtType&29)!=29 && (actualMcEvtType&30)!=30)  
// 	&& ((actualisMcD0id==-421 && ((_isCS==kFALSE && actuallundVectorc==323)||(_isCS==kTRUE && actuallundVectorc==20213))) || (actualisMcD0id==421 && ((_isCS==kFALSE && actuallundVectorc==-323)||(_isCS==kTRUE && actuallundVectorc==-20213)))) ) totRSWSignal++;
//   if  ( actualisMcD0 && (actualMcEvtType&3841==3841 || actualMcEvtType&3842==3842) 
// 	&&  ((actualMcEvtType&29)!=29 && (actualMcEvtType&30)!=30) 
// 	)totSignalWSbc++;
//   if  ( actualisMcD0 && (actualMcEvtType&3869==3869 || actualMcEvtType&3870==3870))totSignalRSbc++;
  
  
  



 //se la molteplicita' dell'evento precedente e'>1, valuta numtrue e numfalse
 if (mul>1) {(istrue>0)?numtrue++:numfalse++;}
 //se mul>1, calcola il numero di volte in cui la scelta sel. il cand vero o falso
 if (mul>1 && istrue>0 && actualChBtruth==1)num_right_choice++;
 if (mul>1 && istrue>0 && actualChBtruth==0)num_wrong_choice++;
 //---
 //if the multeplicity is =1 --> evaluate  num1t e num1f
 if (mul==1) num1++;
	if (mul==1){(istrue>0)? num1t++ : num1f++;}
	//---
	Tmulti_cand->Fill(mul); 
	//if (istrue>0) Tmulti_cand_truth->Fill(mul);
	
	//if (mul>1)
	
	if (opt==1){
	  
	  //outtest << actualdemk<<"     "<< actualmes<<"     " <<actualmassD0<<endl;
	  
	  outfile<<"1"<<" "<< bdecay_type_code+200+100*_Kstarc_decay_code+ddecay_code <<" "<< actualchargeb<<" " 
		 << actualq12  << " " << actualq13 << " " << actualq23  << " " 
		 <<"0" << " " <<"0" << " " << "0"<< " " << "0"<< " " 
		 <<actualdemk << " " << actualppr << " " << actualbeta_Gamma<< " " 
		 <<actualmes << " " << actualmassD0 << " " << actualfisherDK<< " " 
		 <<actualrunNumber <<" "<<actualupperID<<" "<<actuallowerID<<endl;
	  
	  // if (actualisMcD0==0)
	  if(!(actualMcEvtType&3841==3841 || actualMcEvtType&3842==3842))
	    outfile_fakeD0<<"1"<<" "<< bdecay_type_code+200+100*_Kstarc_decay_code+ddecay_code <<" "<< actualchargeb<<" " 
			  << actualq12  << " " << actualq13 << " " << actualq23     << " " 
			  <<"0" << " " <<"0" << " " << "0"<< " " << "0"<< " " 
			  <<actualdemk << " " << actualppr << " "  << actualbeta_Gamma<< " " 
			  <<actualmes << " " << actualmassD0 << " " << actualfisherDK<< " " 
			  <<actualrunNumber <<" "<<actualupperID<<" "<<actuallowerID<<endl;
	  
	  //if(actualMcEvtType==McEvt || actualMcEvtType==McEvt2)
	  //if((actualMcEvtType==McEvt || actualMcEvtType==McEvt2) && 
	  // ((actualisMcD0id==-421 && actuallundVectorc==323) ||
	  // (actualisMcD0id==421 && actuallundVectorc==-323)) )
	  if((actualMcEvtType&3841==3841 || actualMcEvtType&3842==3842) &&
	     ((actualisMcD0id==421 && ((_isCS==kFALSE && actuallundVectorc==-323)||(_isCS==kTRUE && actuallundVectorc==-20213))) || 
	      (actualisMcD0id==-421 && ((_isCS==kFALSE && actuallundVectorc==323)||(_isCS==kTRUE && actuallundVectorc==20213))))) 
	    outfile_matched <<"1"<<" "<< bdecay_type_code+200+100*_Kstarc_decay_code+ddecay_code <<" "<< actualchargeb<<" " 
			    << actualq12  << " " << actualq13 << " " << actualq23     << " " 
			    <<actualchargeB_truth << " " <<actualq12_truth << " " << actualq13_truth<< " " << actualq23_truth<< " "
			    <<actualdemk << " " << actualppr << " " << actualbeta_Gamma<< " " 
			    <<actualmes << " " << actualmassD0 << " " <<" " << actualfisherDK<< " " 
			    <<actualrunNumber <<" "<<actuallowerID<< " "<<actualupperID<<endl; 
	  
	  outfile_kappa<<actualchargeb<<" "
		       <<actualpxD0<<" "<<actualpyD0<<" "<<actualpzD0<<" "<<actualmassD0<<" "
		       <<actualpxVectorcReso<<" "<<actualpyVectorcReso<<" "<<actualpzVectorcReso<<" "<<actualmassVectorcReso<<" "
		       <<actualpxVectorcpic<<" "<<actualpyVectorcpic<<" "<<actualpzVectorcpic<<" "<<actualmassVectorcpic<<" "
		       <<actualpxChB<<" "<<actualpyChB<<" "<<actualpzChB<<" "<<actualmassChB<<endl;
	  
	  roomes->setVal(actualmes);
	  roodemk->setVal(actualdemk);
	  roomassD0->setVal(actualmassD0);
	  roofisherDK->setVal(actualfisherDK);
	  dataset->add(roovars);
	  
	  TfisherDK->Fill(actualfisherDK);
	  Tmes->Fill(actualmes);
	  Tdemk->Fill(actualdemk);
	  Tm12->Fill(actualq12-actualm12);
	  Tm13->Fill(actualq13-actualm13);
	  Tm23->Fill(actualq23-actualm23);
	  Tdalitz->Fill(actualq12,actualq13);
	  Tmesdemk->Fill(actualmes,actualdemk);
	  TmassVectorcReso->Fill(actualmassVectorcReso);
	  TmassVectorc->Fill(actualmassVectorc);
	  TSigdlKs->Fill(actualSigdlKs);
	  TmassD0->Fill(actualmassD0);
	  TcoseliVectorc->Fill(actualcoseliVectorc);
	  // get actualjentry
	  Int_t ientry = LoadTree(actualjentry);
	  nb = fChain->GetEntry(actualjentry); 
	  bkg_tree(outfile2);
	  // retrieve jentry
	  ientry = LoadTree(nentries-1);
	  nb = fChain->GetEntry(nentries-1); 
	  
	} else if (opt==2){
    //      outfile<<mul<<endl;
	} else assert(0);
	
	cout<<endl;
	cout<<"Summary of candidate multiplicity"<<endl;
	cout<<"totcand = "<<totcand<<endl;
	cout<<"totevt = "<<totevt<<endl;
	cout<<"num1 = "<<num1<<endl;
	cout<<"num1t = "<<num1t<<endl;
	cout<<"num1f = "<<num1f<<endl;
	cout<<"numtrue = "<<numtrue<<endl;
	cout<<"numfalse = "<<numfalse<<endl;
	cout<<"num_right_choice = "<<num_right_choice<<endl;
	cout<<"num_wrong_choice = "<<num_wrong_choice<<endl;
	cout<<"fraction correct choice = "<<(Double_t)num_right_choice/(num_right_choice+num_wrong_choice)<<endl;
	multiplicity=(Double_t)totcand/totevt;
	cout<<"multiplicity = "<<multiplicity<<endl;
	
	cout<<"totD0bc = "<<totD0bc<<endl;
	cout<<"fraction real D0s bc = "<<(Double_t)totD0bc/totevt<<" +/- "<<sqrt(Double_t(totD0bc)*(1-(Double_t)totD0bc/totevt))/totevt<<endl;
	cout<<"totKstarRSbc = "<<totKstarRSbc<<endl;
	cout<<"fraction RS D0s bc = "<<(Double_t)totKstarRSbc/totD0bc<<" +/- "
	    <<sqrt(Double_t(totKstarRSbc)*(1-(Double_t)totKstarRSbc/totD0bc))/totD0bc<<endl;//(D0K*- + anti-D0K*+)/all real D0s
	cout<<"fraction WS D0s bc = "<<(Double_t)(totD0bc-totKstarRSbc)/Double_t(totD0bc)<<" +/- "
	    << sqrt((Double_t)(totD0bc-totKstarRSbc)*(1-(Double_t)(totD0bc-totKstarRSbc)/Double_t(totD0bc)))/Double_t(totD0bc) <<endl;//(anti-D0K*- + D0K*+)/all real D0s
	cout<<"totSigWSbc = "<<totSigWSbc<<endl;
	cout<<"fraction WS signal bc = " << (Double_t)totSigWSbc/(Double_t)totevt<<" +/- "
	    << sqrt((Double_t)totSigWSbc*(1-(Double_t)totSigWSbc/(Double_t)totevt))/(Double_t)totevt << endl; 
	cout<<endl;
	cout<<"totD0 w/o bc = "<<totD0<<endl;
	cout<<"fraction real D0s w/o bc = "<<(Double_t)totD0/totcand<<" +/- "
	    <<sqrt(Double_t(totD0)*(1-(Double_t)totD0/(Double_t)totcand))/totcand<<endl;
	cout<<"totKstarRS w/o bc = "<<totKstarRS<<endl;
	cout<<"fraction RS D0s w/o bc = "<<(Double_t)totKstarRS/(Double_t)totD0 
	    <<" +/- "<<sqrt(Double_t(totKstarRS)*(1-(Double_t)totKstarRS/(Double_t)totD0))/totD0<<endl;//(D0K*- + anti-D0K*+)/all real D0s
	cout<<"totSigWS = "<<totSigWS<<endl;
	cout<<"fraction WS signal w/o bc = "<< (Double_t)totSigWS/(Double_t)totcand<<" +/- "
	    << sqrt((Double_t)totSigWS*(1-(Double_t)totSigWS/(Double_t)totcand))/(Double_t)totcand << endl; 

	cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
	cout<<"RightSignalbc = "<<totSignalRSbc<<endl;
	cout<<"WSignalbc = "<<totSignalWSbc<<endl;
	cout<<"RSignWSignalbc = "<<totRSWSignal<<endl;
	cout<<"fraction of WS over RS = "<< (Double_t)totSignalWSbc/(Double_t)totSignalRSbc <<" +/- "
	    << sqrt((Double_t)totSignalWSbc*(1-(Double_t)totSignalWSbc/(Double_t)totSignalRSbc))/(Double_t)totSignalRSbc<<endl; 
	cout<<"fraction of right sign over WS = "<< (Double_t)totRSWSignal/(Double_t)totSignalWSbc <<" +/- "
	    << sqrt((Double_t)totRSWSignal*(1-(Double_t)totRSWSignal/(Double_t)totSignalWSbc))/(Double_t)totSignalWSbc<<endl; 
	cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;






	cout<<endl; 

	
	
	//########################################################
	// make histograms and save in root file
	// save dataset in same root file
	
	Int_t style(1);
	if (_sig_type=="btdkstarc") style=(_Kstarc_decay=="kspi") ? 2:3;
	if (_sig_type=="chb") style=4; 
	if (_sig_type=="b0b0bar") style=5;
	if (_sig_type=="bbbar") style=4;
	if (_sig_type=="uds")  style=6;
	if (_sig_type=="ccbar")  style=7;
	if (_sig_type=="udsccbar")  style=7;
	if (_sig_type=="chbNR") style=8; 
	cout << "Making histograms with style = " << style << endl;
	
	TString filename_ASCII="ASCII/"+sdec+_Kstarc_decay+"_"+_d0mode+"_"+_sig_type+"_Bbest_"+cut_code_str;
	
	TFile* file = new TFile(filename_ASCII+".root","recreate");
	file->cd();
	
	TCanvas* canvas= new TCanvas("canvas","canvas",500,500);
	
	canvas->Divide(3,2);
	//draw dalitz plot
	canvas->cd(1);
	gStyle->SetPalette(1);
	Tdalitz->Draw("colZ");
	Tdalitz->Write();
	gStyle->SetOptStat(1);
	//draw q12-m12 control check
	canvas->cd(2); //Tm12->Fit("gaus","V");
	Tm12->Draw();
	Tm12->Write();
	//draw q13-m13 control check
	canvas->cd(3); //Tm13->Fit("gaus","V");
	Tm13->Draw();
	Tm13->Write();
	//draw q23-m23 control check
	canvas->cd(4); //Tm23->Fit("gaus","V");
	Tm23->Draw();
	Tm23->Write();
	// draw mES vs DeltaE
	canvas->cd(5); 
	//Tmesdemk->Draw("COLZ");
	Tmesdemk->Draw();
	Tmesdemk->Write();
	// draw multiplicity
	canvas->cd(6);
	gPad->SetLogy(1);
	Tmulti_cand->GetXaxis()->SetTitle("N candidates per event");
	Tmulti_cand->GetXaxis()->SetTitleSize(0.05);
	Tmulti_cand->SetTitleOffset(1.1,"X");
	Tmulti_cand->SetFillColor(style);
	Tmulti_cand->SetLineColor(style);
	Tmulti_cand->Draw();
	Tmulti_cand->Write();
	canvas->Print(filename_ASCII+".eps");
	//canvas->Print(filename_ASCII+".gif");
	
	canvas->Divide(1);
	for (Int_t j=0;j<=8;j++){
	  canvas->cd();
	  vect[j]->SetLineColor(style);
	  vect[j]->SetFillColor(style);
	  vect[j]->Draw();
	  vect[j]->Write();
	  TString name(vect[j]->GetName());
	  //     if (name=="demk") vect[j]->Fit("gaus","L");
	  canvas->Print(filename_ASCII+"_"+name+".eps");
	  canvas->Print(filename_ASCII+"_"+name+".gif");
	}
	
	dataset->Write("dataset");
	delete dataset;
	
	file->Close();
	delete file;
	canvas->cd(1);
	TControl->Draw();
}


void btdkstarc_final::Fits(Int_t cut_code, TString varname)
{
  TString sdec= (_isCS==kFALSE)? "btdkstarc_" :"btda1_";
  char cut_code_str[10];
  sprintf(cut_code_str,"Cut%i",cut_code);

  TString filename_ASCII="ASCII/"+sdec+_Kstarc_decay+"_"+_d0mode+"_"+_sig_type+"_Bbest_"+cut_code_str;
  TFile* file = new TFile(filename_ASCII+".root","read");
  if (file->IsZombie()) {
    cout << "Error opening file: " << filename_ASCII+".root" << endl;
    return;
  } else {
    cout << "File read succesfully: " << filename_ASCII+".root" << endl;
  }

  Double_t demk_lo_old = roodemk->getMin();
  Double_t demk_hi_old = roodemk->getMax();
  Double_t demk_hi =  0.120 ;
  Double_t demk_lo = -0.080 ;
  //Double_t demk_hi =  0.060 ;
  //Double_t demk_lo = -0.060 ;
  if (cut_code!=2) roodemk->setRange(demk_lo,demk_hi);

  RooDataSet* dataset = (RooDataSet*)file->Get("dataset");
  RooDataSet* dataset_reduced = (RooDataSet*)dataset->reduce(roovars);
  delete dataset;
  dataset = dataset_reduced;
  Int_t nevts = dataset->numEntries();
  cout << "dataset has " << nevts << " entries " << endl;

  TCanvas* canvas= new TCanvas("canvas","canvas",500,500);

  Int_t style(1);
  if (_sig_type=="btdkstarc") style=(_Kstarc_decay=="kspi") ? 2:3;
  if (_sig_type=="chb") style=4;
  if (_sig_type=="b0b0bar") style=5;
  if (_sig_type=="bbbar") style=4;
  if (_sig_type=="uds")  style=6;
  if (_sig_type=="ccbar")  style=7;
  if (_sig_type=="udsccbar")  style=6;
  if (_sig_type=="chbNR") style=8;
  cout << "Making histograms with style = " << style << endl;

  Int_t nbins(50);
  roovars.Print("v");
  TIterator* iter = roovars.createIterator();
  RooRealVar* var;
  while ((var = (RooRealVar*)iter->Next())) {
    TString name(var->GetName());
    RooAbsPdf* pdf(0);
    if (varname=="" || varname==name) {
      if (name=="mes") {
	if (cut_code==1 || cut_code==112) pdf = getPdf(*var);
      } else if (name=="demk") {      
	if (cut_code==2 || cut_code==112) pdf = getPdf(*var);
      } else if (name=="fisherDK") {
	pdf = getPdf(*var);
      } else if (name=="massD0") {
	if (cut_code==3) pdf = getPdf(*var);
      } //else assert(0);
    }

    if (pdf) {
      Double_t lo = (name=="demk")? demk_lo : var->getMin();
      Double_t hi = (name=="demk")? demk_hi : var->getMax();
      RooPlot* xframe = var->frame(lo,hi,nbins);
      TString title(name); title+=" d0k* "; title+=_Kstarc_decay; title+=" "; title+=_d0mode;
      xframe->SetTitle(title);
      dataset->plotOn(xframe);
      xframe->getAttLine()->SetLineColor(style);
      xframe->getAttFill()->SetFillColor(style);
      xframe->getAttMarker()->SetMarkerColor(style);
      dataset->statOn(xframe,Layout(0.15,0.4,0.9),What("N"));
      xframe->getAttText()->SetTextSize(0.02);
      pdf->fitTo(*dataset,"mh");

      if(name=="massD0"){
	RooRealIntegral pdfInt("pdfInt","pdfInt",*pdf,*roomassD0);
	//	massD0->setRange(massD_min_signalRegion,massD_max_signalRegion);
	roomassD0->setRange(1.8645-0.012,1.8645+0.012);
	Double_t f_signalRegion = pdfInt.getVal();
	roomassD0->setRange(1.8645-0.040,1.8645+0.040);
	//	massD0->setRange(massD_min_allRegion,massD_max_allRegion);
	Double_t f_allRegion = pdfInt.getVal();
	Double_t scale = f_allRegion/f_signalRegion;
	cout<<"#############################################################################################################"<<endl;
	cout<<"#############################################################################################################"<<endl;
	cout<<"#############################################################################################################"<<endl;
	cout<<"scale="<<scale<<endl;
	cout<<"f_signalRegion = "<<f_signalRegion<<endl;
	cout<<"f_allRegion = "<<f_allRegion<<endl;
	cout<<"#############################################################################################################"<<endl;
	cout<<"#############################################################################################################"<<endl;
	cout<<"#############################################################################################################"<<endl;
      }
      //RooArgSet projDeps;
      //pdf->plotOn(xframe,ProjWData(projDeps,*dataset));
      pdf->plotOn(xframe);
      xframe->getAttLine()->SetLineColor(style);
      pdf->paramOn(xframe);
      xframe->getAttText()->SetTextSize(0.02);
      xframe->Draw();
      canvas->Print(filename_ASCII+"_"+name+"_fit.eps");
      canvas->Print(filename_ASCII+"_"+name+"_fit.gif");
      if (pdf) delete pdf;
    }
  }
  delete iter;

  //file->Close();
  //delete file;

  roodemk->setRange(demk_lo_old,demk_hi_old);

}

	   
RooAbsPdf* btdkstarc_final::getPdf(RooRealVar& var)
{
  TString varname(var.GetName());
  
  if (varname=="mes") {
    RooRealVar* mesGMean = new RooRealVar("mesGMean","mES Gaussian mean",5.28,5.25,5.30,"GeV") ;
    RooRealVar* mesGWidth = new RooRealVar("mesGWidth","mES Gaussian width",0.0026,0.001,0.015,"GeV") ;
    RooAbsPdf* mesGPdf = new RooGaussian("mesGPdf","mES Gauss PDF",var,*mesGMean,*mesGWidth) ;      
    //
    RooRealVar* mesGWidthL = new RooRealVar("mesGWidthL","mES Gaussian width left",0.0026,0.001,0.015,"GeV") ;
    RooRealVar* mesGWidthR = new RooRealVar("mesGWidthR","mES Gaussian width right",0.0026,0.001,0.015,"GeV") ;
    RooAbsPdf* mesBGPdf  = new RooBifurGauss("mesBGPdf","mES Bifurcated Gauss PDF",var,*mesGMean,*mesGWidthL,*mesGWidthR) ;
    //
    RooRealVar* mesArgMax = new RooRealVar("mesArgMax","mES Argus cutoff",5.290,"GeV") ;
    RooRealVar* mesArgPar = new RooRealVar("mesArgPar","mES Argus slope",-122.0,-1000.0,0.0) ;    
    RooAbsPdf* mesArgPdf = new RooArgusBG("mesArgPdf","mES Argus PDF",var,*mesArgMax,*mesArgPar) ;
    //
    RooRealVar* mesCBalpha = new RooRealVar("mesCBalpha","mES CB alpha",-0.69,-100.,0.) ;
    RooRealVar* mesCBn = new RooRealVar("mesCBn","mES CB n",5.) ;
    RooAbsPdf* mesCBPdf = new RooCBShape("mesCBPdf", "mES CB PDF",var,*mesGMean,*mesGWidth,*mesCBalpha,*mesCBn);
    //
    RooRealVar* fmesG = new RooRealVar("fmesG","mES Gaussian fraction",0.2,0,1) ;  
    RooAbsPdf* mesPdf = new RooAddPdf("mesPdf","mES PDF",RooArgList(*mesGPdf,*mesArgPdf),*fmesG) ;
    RooAbsPdf* mesPdfBG = new RooAddPdf("mesPdfBG","mES PDF BG",RooArgList(*mesBGPdf,*mesArgPdf),*fmesG) ;
    RooAbsPdf* mesPdfCB = new RooAddPdf("mesPdfCB","mES PDF CB",RooArgList(*mesCBPdf,*mesArgPdf),*fmesG) ;
    
    if (_sig_type=="bbbar") {
      if (!_isCS) {
	//mesGWidthL->setVal(0.0046); mesGWidthR->setVal(0.0024);
	//mesGWidthL->setConstant(); mesGWidthR->setConstant();
      }
      //return mesPdf;      
      return mesPdfBG;
      //return mesPdfCB;
    }
    if (_sig_type=="b0b0bar") {
      return mesArgPdf;      
    }
    
    if (_sig_type=="btdkstarc" || _sig_type=="chb" || _sig_type=="chbNR" || 
	_sig_type=="b0b0bar" || _sig_type=="bbbar" || _sig_type=="On1234"|| _sig_type=="On5"|| _sig_type=="On" ||
	_sig_type=="btda1" || _sig_type=="chbR") {
      //if (_sig_type=="chb" || _sig_type=="b0b0bar" || _sig_type=="bbbar") { mesGWidth->setVal(0.0038); mesGWidth->setConstant(); }
      return mesPdf;
    } else if (_sig_type=="uds" || _sig_type=="ccbar" || _sig_type=="udsccbar" || _sig_type=="Off1234" || _sig_type=="Off5" || _sig_type=="Off") {
      return mesArgPdf;
    } else assert(0);  
  } // mes
  
  if (varname=="demk") {
    RooRealVar* deGMean  = new RooRealVar("deGMean","DeltaE Gaussian mean",0.,-0.12,0.12,"GeV") ;
    RooRealVar* deGWidth = new RooRealVar("deGWidth","DeltaE Gaussian width",0.012,0.001,0.12,"GeV") ;
    RooAbsPdf* deGPdf = new RooGaussian("deGPdf","DeltaE Gauss PDF",var,*deGMean,*deGWidth) ;
    RooRealVar* dePolyC1 = new RooRealVar("dePolyC1","DeltaE polynomial coefficient C1",0.,-1e1,1e2) ;
    RooRealVar* dePolyC2 = new RooRealVar("dePolyC2","DeltaE polynomial coefficient C2",0.,-1e2,1e2) ; 
    dePolyC2->setConstant();
    RooAbsPdf* dePolyPdf = new RooPolynomial("dePolyPdf","DeltaE polynomial PDF",var,RooArgList(*dePolyC1,*dePolyC2));
    RooRealVar* fdeG = new RooRealVar("fdeG","DeltaE Gaussian fraction",0.1,0.001,1) ;  
    RooAbsPdf* dePdf = new RooAddPdf("dePdf","DeltaE PDF",RooArgList(*deGPdf,*dePolyPdf),*fdeG) ;

    if (_sig_type=="btdkstarc" || _sig_type=="On1234" || _sig_type=="On5"|| _sig_type=="On"|| _sig_type=="chb" || 
	_sig_type=="chbNR" || _sig_type=="bbbar" || _sig_type=="btda1" || _sig_type=="chbR") {
      if (_sig_type=="chb" || _sig_type=="bbbar") deGMean->setConstant(0.); 
      dePolyC2->setConstant(kFALSE);
      if (_sig_type=="btdkstarc" || _sig_type=="btda1" || _sig_type=="chbR") dePolyC2->setConstant();
      if (_sig_type=="bbbar") {
	if (!_isCS) {
	  deGMean->setConstant();
	  deGWidth->setConstant();
	  deGWidth->setVal(0.011);
	}
      }
      return dePdf;
    } else if (_sig_type=="uds" || _sig_type=="ccbar" || _sig_type=="udsccbar" || _sig_type=="b0b0bar" || _sig_type=="Off1234" || 
	       _sig_type=="Off5"|| _sig_type=="Off") {
      return dePolyPdf;
    } else assert(0);  
  } // demk


  if (varname=="fisherDK") {
    RooRealVar* fiG1Mean   = new RooRealVar("fiG1Mean","Fisher 1st Gaussian mean",-0.4,-6,6) ;
    RooRealVar* fiG1WidthL  = new RooRealVar("fiG1WidthL","Fisher 1st Gaussian width left",0.26,0.01,6) ;
    RooRealVar* fiG1WidthR  = new RooRealVar("fiG1WidthR","Fisher 1st Gaussian width right",0.55,0.01,6) ;
    RooRealVar* fiG2Mean   = new RooRealVar("fiG2Mean","Fisher 2nd Gaussian mean",0.6,-6,6) ;
    RooRealVar* fiG2WidthL  = new RooRealVar("fiG2WidthL","Fisher 2nd Gaussian width left",0.50,0.01,6) ;
    RooRealVar* fiG2WidthR  = new RooRealVar("fiG2WidthR","Fisher 2nd Gaussian width right",0.25,0.01,6) ;
    RooAbsPdf* fiG1Pdf    = new RooGaussian("fiG1Pdf","Fisher 1st Gaussian",var,*fiG1Mean,*fiG1WidthL) ;
    RooAbsPdf* fiG2Pdf    = new RooGaussian("fiG2Pdf","Fisher 2nd Gaussian",var,*fiG2Mean,*fiG2WidthL) ;
    RooAbsPdf* fiBG1Pdf     = new RooBifurGauss("fiG1Pdf","Fisher 1st Gaussian",var,*fiG1Mean,*fiG1WidthL,*fiG1WidthR) ;
    RooAbsPdf* fiBG2Pdf     = new RooBifurGauss("fiG2Pdf","Fisher 2nd Gaussian",var,*fiG2Mean,*fiG2WidthL,*fiG2WidthR) ;
    RooRealVar* fiG1Frac   = new RooRealVar("fiG1Frac","Fisher fraction of 1st Gaussian",0.5,0,1) ;
    RooAbsPdf* fiPdf(0);
    if (_sig_type=="btda1" || _sig_type=="btdkstarc" || _sig_type=="chbR" || _sig_type=="on" || _sig_type=="chb" || 
	_sig_type=="b0b0bar" || _sig_type=="bbbar") {
      fiPdf = new RooAddPdf("fiPdf","Fisher PDF",RooArgList(*fiBG1Pdf,*fiBG2Pdf),*fiG1Frac) ;
    } else {
      fiPdf = new RooAddPdf("fiPdf","Fisher PDF",RooArgList(*fiG1Pdf,*fiG2Pdf),*fiG1Frac) ;
    }
    return fiPdf;
  } // fisherDK
  if(varname=="massD0"){
    RooRealVar* massD0GMean  = new RooRealVar("massD0GMean","MassD0 Gaussian mean",1.8645,"GeV") ;
    
    RooRealVar* massD0GWidth;
    if(_d0mode=="kspipi")  massD0GWidth= new RooRealVar("massD0GWidth","MassD0 Gaussian width",0.00644,"GeV") ;
    else if(_d0mode=="kskk") massD0GWidth= new RooRealVar("massD0GWidth","MassD0 Gaussian width",0.00421,"GeV") ;
 
    RooAbsPdf* massD0GPdf    = new RooGaussian("massD0GPdf","MassD0 Gauss PDF",var,*massD0GMean,*massD0GWidth) ;  
    RooRealVar* fmassD0G     = new RooRealVar("fmassD0G","MassD0 Gaussian fraction",0.,0,1) ;  
    RooRealVar* massD0Poly = new RooRealVar("massD0Poly","massD0 primer coef",0.) ;
    RooAbsPdf* massD0PolyPdf = new RooPolynomial("massD0PolyPdf","massD0 polynomial PDF",var,*massD0Poly); 
    RooAbsPdf* massD0Pdf = new RooAddPdf("massD0Pdf","mES PDF CB",RooArgList(*massD0GPdf,*massD0PolyPdf),*fmassD0G) ;
        
    return massD0Pdf;
  }
  
  return 0;
}


void btdkstarc_final::bkg_tree(ofstream& outfile2)
{
  //  cout<<"inside bkg_tree"<<endl;
  
  //defining the Trk mothers and composition
  Int_t gmVectorcResoPi1(0);
  Int_t gmVectorcResoPi2(0);
  Int_t gmVectorcpic(0);
  Int_t gmKstarckc(0);
  Int_t gmKstarcPi0g1(0);
  Int_t gmKstarcPi0g2(0);
  Int_t gmD0Pi1(0);
  Int_t gmD0Pi2(0);
  Int_t gmD0KsPi1(0);
  Int_t gmD0KsPi2(0);

  Int_t lD0(0);
  //Int_t lVectorcpic(0);
  Int_t lKstarckc(0);
  Bool_t check=kTRUE;
 

  //##################################################
  Int_t dec= _Kstarc_decay_code;

  outfile2<<endl<<endl;
  if (dec==1) outfile2<<"event number:"<<event<<" flagKspi="<<flagKspi<<" McNREvtType="<<McNREvtType
		      <<" D0="<<isMcD0<<" D0Ks="<<isMcKs
		      <<" VectorcReso="<<isMcVectorcReso<<" KstarcPic="<< isMcVectorcResopic<< " lundKstarPi="
		      << idMc[indexMcVectorcpic] << endl;      
  
  else      outfile2<<"event number:"<<event<<" flagKspi="<<flagKspi<<" McNREvtType="<<McNREvtType
		    <<" D0="<<isMcD0<<" D0Ks="<<isMcKs
		    <<" KstarcPi0="<<isMcKstarcPi0 << " lundKstarK="<< idMc[indexMcKstarckc] << endl;
  
  
  //##############Kstarc candidate   ####################################
  
  if (dec==1){
    //##############Kstarc Pion candidate   ####################################
    
    if (indexMcVectorcpic>0 && indexMcVectorcpic<110){
      //cout <<"lundMcKstarcPic = "<<idMc[indexMcVectorcpic]<< endl; 
      outfile2<<"KstarcPic candidate: ";
      outfile2<<idMc[indexMcVectorcpic]<<" ";
      gmVectorcpic=indexMcVectorcpic;
      check=kTRUE;
      while ( (abs(idMc[gmVectorcpic]) != 70553) && (abs(idMc[gmVectorcpic]) != 521) && (abs(idMc[gmVectorcpic]) != 10022) && (abs(idMc[gmVectorcpic]) != 511) && gmVectorcpic>0 && gmVectorcpic<110 && check) {
	
	check=kFALSE;
	// cout<< "gmVectorcpic = "<<gmVectorcpic<<" idMc[gmVectorcpic]= "<<idMc[gmVectorcpic]<<endl;
	if (  ((mothMc[gmVectorcpic]-1)>0) && ((mothMc[gmVectorcpic]-1)<110) ){
	  gmVectorcpic=mothMc[gmVectorcpic]-1;
	  outfile2<<idMc[gmVectorcpic]<<" ";
	  check=kTRUE;
	}
	//	  else  break;
      }
      outfile2<<endl;
    }
    if (abs(idMc[gmVectorcpic])==521 || abs(idMc[gmVectorcpic])==511) outfile2<< "# B dau = "<<nDauMc[gmVectorcpic]<<endl; 
    //cout<<"sono qui "<< gmVectorcpic << " "<<idMc[gmVectorcpic]<<" # B dau = "<<nDauMc[gmVectorcpic]<<endl;
    
    //      break;
    
    
    //##############Kstarc  KS daughters####################################
    outfile2<<"VectorcReso daughter KstarcPi1 candidate: ";
    if (indexMcVectorcResoPi1>0 && indexMcVectorcResoPi1<110){
      outfile2<<idMc[indexMcVectorcResoPi1]<<" "; 
      gmVectorcResoPi1=indexMcVectorcResoPi1;
      check=kTRUE;
      while ( (abs(idMc[gmVectorcResoPi1]) != 70553) && (abs(idMc[gmVectorcResoPi1]) != 521) && (abs(idMc[gmVectorcResoPi1]) != 10022) && (abs(idMc[gmVectorcResoPi1]) != 511) && gmVectorcResoPi1>0 && gmVectorcResoPi1<110 && check) {
	
	check=kFALSE;
	if (  ((mothMc[gmVectorcResoPi1]-1)>0) && ((mothMc[gmVectorcResoPi1]-1)<110) ){
	  gmVectorcResoPi1=mothMc[gmVectorcResoPi1]-1;
	  outfile2<<idMc[gmVectorcResoPi1]<<" ";
	  check=kTRUE;
	}
	//	else  break;
      }
      outfile2<<endl;
    }
    
    outfile2<<"VectorcReso daughter KstarcPi2 candidate: ";
    if (indexMcVectorcResoPi2>0 && indexMcVectorcResoPi2<110){
      outfile2<<idMc[indexMcVectorcResoPi2]<<" "; 
      gmVectorcResoPi2=indexMcVectorcResoPi2;
      check=kTRUE;
      while ( (abs(idMc[gmVectorcResoPi2]) != 70553) && (abs(idMc[gmVectorcResoPi2]) != 521) && (abs(idMc[gmVectorcResoPi2]) != 10022) && (abs(idMc[gmVectorcResoPi2]) != 511) && gmVectorcResoPi2>0 && gmVectorcResoPi2<110 && check) {
	
	check=kFALSE;
	if (  ((mothMc[gmVectorcResoPi2]-1)>0) && ((mothMc[gmVectorcResoPi2]-1)<110) ){
	  gmVectorcResoPi2=mothMc[gmVectorcResoPi2]-1;
	  outfile2<<idMc[gmVectorcResoPi2]<<" ";
	  check=kTRUE;
	}
	//	else  break;
	
      }
      outfile2<<endl;
    }
    
    
  }//if (dec==1)
  
  else if (dec==2){
    
    //##############  Kstarc Pi0 candidate  ####################################
    outfile2<<"KstarcPi0 g1 candidate: ";
    if (indexMcKstarcPi0g1>0 && indexMcKstarcPi0g1<110){
      check=kTRUE;
      outfile2<<idMc[indexMcKstarcPi0g1]<<" "; 
      gmKstarcPi0g1=indexMcKstarcPi0g1;
      while ( (abs(idMc[gmKstarcPi0g1]) != 521) && (abs(idMc[gmKstarcPi0g1]) != 10022) && (abs(idMc[gmKstarcPi0g1]) != 511) && gmKstarcPi0g1>0 && gmKstarcPi0g1<110 && check) {
	check=kFALSE;
	if (  ((mothMc[gmKstarcPi0g1]-1)>0) && ((mothMc[gmKstarcPi0g1]-1)<110) ){
	  gmKstarcPi0g1=mothMc[gmKstarcPi0g1]-1;
	  outfile2<<idMc[gmKstarcPi0g1]<<" ";
	  check=kTRUE;
	}
	//	else  break;
      }
      
      outfile2<<endl;
    }
    
    outfile2<<"KstarcPi0 g2 candidate: ";
    if (indexMcKstarcPi0g2>0 && indexMcKstarcPi0g2<110){
      check=kTRUE;
      outfile2<<idMc[indexMcKstarcPi0g2]<<" "; 
      gmKstarcPi0g2=indexMcKstarcPi0g2;
      while ( (abs(idMc[gmKstarcPi0g2]) != 521) && (abs(idMc[gmKstarcPi0g2]) != 10022) && (abs(idMc[gmKstarcPi0g2]) != 511) && gmKstarcPi0g2>0 && gmKstarcPi0g2<110 && check) {
	
	check=kFALSE;
	if (  ((mothMc[gmKstarcPi0g1]-1)>0) && ((mothMc[gmKstarcPi0g1]-1)<110) ){
	  gmKstarcPi0g1=mothMc[gmKstarcPi0g1]-1;
	  outfile2<<idMc[gmKstarcPi0g1]<<" ";
	  check=kTRUE;
	}
	//	else  break;
	
      }
      outfile2<<endl;
    }
    
    
    //##############  Kstarc Kaon candidate   ####################################
    
    if (indexMcKstarckc>0 && indexMcKstarckc<110){
      check=kTRUE;
      outfile2<<"lundMcKstarcKc = "<<idMc[indexMcKstarckc]<< endl; 
      outfile2<<"KstarcKc candidate: ";
      outfile2<<idMc[indexMcKstarckc]<<" "; 
      lKstarckc = idMc[indexMcKstarckc];
      gmKstarckc=indexMcKstarckc;
      while ( (abs(idMc[gmKstarckc]) != 70553) && (abs(idMc[gmKstarckc]) != 521) && (abs(idMc[gmKstarckc]) != 10022) && (abs(idMc[gmKstarckc]) != 511) && gmKstarckc>0 && gmKstarckc<110 && check) {
	
	// cout<< "gmKstarckc = "<<gmKstarckc<<" idMc[gmKstarckc]= "<<idMc[gmKstarckc]<<endl;
	check=kFALSE;
	if (  ((mothMc[gmKstarckc]-1)>0) && ((mothMc[gmKstarckc]-1)<110) ){
	  gmKstarckc=mothMc[gmKstarckc]-1;
	  outfile2<<idMc[gmKstarckc]<<" ";
	  check=kTRUE;
	}
	//	else  break;
	
      }
      outfile2<<endl;
    }
    if (abs(idMc[gmKstarckc])==521 || abs(idMc[gmKstarckc])==511) outfile2<< "# B dau = "<<nDauMc[gmKstarckc]<<endl; 
    // cout<<"sono qui "<<idMc[gmKstarckc]<<endl;
    
    //      break;
    
  } //else if(dec==2)
  
  //##############  D0 candidate tracKs  ####################################
  outfile2<<"D0 daughter D0Pi1 candidate: ";
  if (indexMcD0Pi1>0 && indexMcD0Pi1<110){
    check=kTRUE;
    outfile2<<idMc[indexMcD0Pi1]<<" "; 
    gmD0Pi1=indexMcD0Pi1;
    while ( (abs(idMc[gmD0Pi1]) != 70553) && (abs(idMc[gmD0Pi1]) != 521) && (abs(idMc[gmD0Pi1]) != 10022) && (abs(idMc[gmD0Pi1]) != 511) && gmD0Pi1>0 && gmD0Pi1<110 && check) {
      check=kFALSE;
      if (  ((mothMc[gmD0Pi1]-1)>0) && ((mothMc[gmD0Pi1]-1)<110) ){
	gmD0Pi1=mothMc[gmD0Pi1]-1;
	outfile2<<idMc[gmD0Pi1]<<" ";
	check=kTRUE;
      }
      //	else  break;
      
      if (abs(idMc[gmD0Pi1])==421) lD0=idMc[gmD0Pi1];
    }
    outfile2<<endl;
  }
  
  outfile2<<"D0 daughter D0Pi2 candidate: ";
  if (indexMcD0Pi2>0 && indexMcD0Pi2<110){
    check=kTRUE;
    outfile2<<idMc[indexMcD0Pi2]<<" "; 
    gmD0Pi2=indexMcD0Pi2;
    while ( (abs(idMc[gmD0Pi2]) != 70553) && (abs(idMc[gmD0Pi2]) != 521) && (abs(idMc[gmD0Pi2]) != 10022) && (abs(idMc[gmD0Pi2]) != 511) && gmD0Pi2>0 && gmD0Pi2<110 && check) {
      
      check=kFALSE;
      if (  ((mothMc[gmD0Pi2]-1)>0) && ((mothMc[gmD0Pi2]-1)<110) ){
	gmD0Pi2=mothMc[gmD0Pi2]-1;
	outfile2<<idMc[gmD0Pi2]<<" ";
	check=kTRUE;
      }
      //	else  break;
    }
    outfile2<<endl;
  }
  
  //##############  D0 candidate tracKs:  KS daughters  ####################################
  outfile2<<"D0 daughter KsPi1 candidate: ";
  if (indexMcD0KsPi1>0 && indexMcD0KsPi1<110){
    check=kTRUE;
    outfile2<<idMc[indexMcD0KsPi1]<<" "; 
    gmD0KsPi1=indexMcD0KsPi1;
    while ( (abs(idMc[gmD0KsPi1]) != 70553) && (abs(idMc[gmD0KsPi1]) != 521) && (abs(idMc[gmD0KsPi1]) != 10022) && (abs(idMc[gmD0KsPi1]) != 511) && gmD0KsPi1>0 && gmD0KsPi1<110 && check) {
      
      check=kFALSE;
      if (  ((mothMc[gmD0KsPi1]-1)>0) && ((mothMc[gmD0KsPi1]-1)<110) ){
	gmD0KsPi1=mothMc[gmD0KsPi1]-1;
	outfile2<<idMc[gmD0KsPi1]<<" ";
	check=kTRUE;
      }
      //	else  break;
      
    }
    outfile2<<endl;
  }
  
  outfile2<<"D0 daughter KsPi2 candidate: ";
  if (indexMcD0KsPi2>0 && indexMcD0KsPi2<110){
    check=kTRUE;
    outfile2<<idMc[indexMcD0KsPi2]<<" "; 
    gmD0KsPi2=indexMcD0KsPi2;
    while ( (abs(idMc[gmD0KsPi2]) != 70553) && (abs(idMc[gmD0KsPi2]) != 521) && (abs(idMc[gmD0KsPi2]) != 10022) && (abs(idMc[gmD0KsPi2]) != 511) && gmD0KsPi2>0 && gmD0KsPi2<110 && check ) {
      
      check=kFALSE;
      if (  ((mothMc[gmD0KsPi2]-1)>0) && ((mothMc[gmD0KsPi2]-1)<110) ){
	gmD0KsPi2=mothMc[gmD0KsPi2]-1;
	outfile2<<idMc[gmD0KsPi2]<<" ";
	check=kTRUE;
      }
      //	else  break;
    }
    outfile2<<endl;
  }
  
  outfile2<<endl;
  //      outfile2<<"D0flag="<<isMcD0<<" lpr ="<<lpr<<" lD0 ="<<lD0<<endl;
  outfile2<<endl;
  
}

void btdkstarc_final::dalVarsTruth(Int_t mcTruth,Float_t* dalVars)
{
  if(!mcTruth) return;

  Int_t recState = (idMc[indexMcVectorc]>0)? 1 : 0;

  Float_t mD0_nom = 1.8645;
  Float_t mKs_nom = 0.49767;
  Float_t mPi_nom = 0.13957;
  Float_t mK_nom = 0.49368;
  Float_t mTrk_nom = (_d0mode=="kspipi")? mPi_nom : mK_nom;

  Float_t pPi1x = pMc[indexMcD0Pi1]*sin(thetaMc[indexMcD0Pi1])*cos(phiMc[indexMcD0Pi1]);
  Float_t pPi1y = pMc[indexMcD0Pi1]*sin(thetaMc[indexMcD0Pi1])*sin(phiMc[indexMcD0Pi1]);
  Float_t pPi1z = pMc[indexMcD0Pi1]*cos(thetaMc[indexMcD0Pi1]);
  Float_t ePi1 = sqrt(pPi1x*pPi1x+pPi1y*pPi1y+pPi1z*pPi1z+mTrk_nom*mTrk_nom);

  Float_t pPi2x = pMc[indexMcD0Pi2]*sin(thetaMc[indexMcD0Pi2])*cos(phiMc[indexMcD0Pi2]);
  Float_t pPi2y = pMc[indexMcD0Pi2]*sin(thetaMc[indexMcD0Pi2])*sin(phiMc[indexMcD0Pi2]);
  Float_t pPi2z = pMc[indexMcD0Pi2]*cos(thetaMc[indexMcD0Pi2]);
  Float_t ePi2 = sqrt(pPi2x*pPi2x+pPi2y*pPi2y+pPi2z*pPi2z+mTrk_nom*mTrk_nom);

  Float_t pKsx = pMc[indexMcKs]*sin(thetaMc[indexMcKs])*cos(phiMc[indexMcKs]);
  Float_t pKsy = pMc[indexMcKs]*sin(thetaMc[indexMcKs])*sin(phiMc[indexMcKs]);
  Float_t pKsz = pMc[indexMcKs]*cos(thetaMc[indexMcKs]);
  Float_t eKs = sqrt(pKsx*pKsx+pKsy*pKsy+pKsz*pKsz+mKs_nom*mKs_nom);

  TLorentzVector pPi1(pPi1x,pPi1y,pPi1z,ePi1);
  TLorentzVector pPi2(pPi2x,pPi2y,pPi2z,ePi2);
  TLorentzVector pKs(pKsx,pKsy,pKsz,eKs);

  Float_t q12 = pPi1*pPi1+pKs*pKs+2.*pPi1*pKs;
  Float_t q13 = pPi2*pPi2+pKs*pKs+2.*pPi2*pKs;
  Float_t q23 = pPi1*pPi1+pPi2*pPi2+2.*pPi1*pPi2;
  
  dalVars[0]= recState;
  dalVars[1]= q12;
  dalVars[2]= q13;
  dalVars[3]= q23;

  return;
}

Bool_t btdkstarc_final::isMcD0Matchedfunction(Int_t a)
{
  Int_t out(0);
  if(
     (a&BIT_ON(0) || a&BIT_ON(1)) &&
     (a&BIT_ON(8) || a&BIT_ON(20)) &&
     (a&BIT_ON(9) || a&BIT_ON(21)) &&
     (a&BIT_ON(10) || a&BIT_ON(22)) &&
     (a&BIT_ON(11) || a&BIT_ON(23))
     ) out=1;
  else out=0;
  return out;
}

Bool_t btdkstarc_final::isMcprMatchedfunction(Int_t a)
{
  Int_t out(0);
  if(
     (a&BIT_ON(0) || a&BIT_ON(1)) &&
     (a&BIT_ON(2) || a&BIT_ON(25))&&
     (a&BIT_ON(3) || a&BIT_ON(26))&&
     (a&BIT_ON(4) || a&BIT_ON(27))
     )out=1;
  else out=0;
  return out;
}
