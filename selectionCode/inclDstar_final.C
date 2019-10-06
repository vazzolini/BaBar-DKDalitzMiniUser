#define inclDstar_final_cxx
#include "inclDstar_final.h"
#include <TH2.h>
#include <TH3.h>
#include <TF1.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iomanip.h>
#include <fstream.h>
//#include <strstream.h>
#include <TLorentzVector.h>
#include <TMath.h>
#include "RooFitCore/RooGlobalFunc.hh"


using namespace RooFit;

void inclDstar_final::Loop(Int_t cut_code, Long64_t nentries)
{
//   In a ROOT session, you can do:
//      Root > .L inclDstar_final.C
//      Root > inclDstar_final t
//      Root > t.GetEntry(12); // Fill t data members with entry number 12
//      Root > t.Show();       // Show values of entry 12
//      Root > t.Show(16);     // Read and show values of entry 16
//      Root > t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;
   TCanvas* canvas= new TCanvas;

  TH1F  *vect[8];
  TFile *f[8];
  
  Int_t nbins(50);
 
  TH1F* TmassD0 = new TH1F("massD0","D0 mass distribution",nbins,1.840,1.890); 
  vect[0]=TmassD0;
  TH1F* TmassKs = new TH1F("massKs","Ks mass distribution",nbins,0.470,0.520);
  vect[1]=TmassKs; 
  TH1F* TcosKs = new TH1F("cosKs","CosthetaKs distribution",nbins,-1,1); 
  vect[2]=TcosKs;
  TH1F* TkaonidPi = new TH1F("kaonidPi","kaonid Pi track distribution",12,0,11);
  vect[3]=TkaonidPi;
  TH1F* TprobChi2D0 = new TH1F("probChi2D0","D0 chi2 probability",40,0,1);
  vect[4]= TprobChi2D0;
  TH1F* TprobChi2Dstar = new TH1F("probChi2Dstar","Dstar chi2 probability",40,0,1);
  vect[5]= TprobChi2Dstar;
  TH1F* TdeltamDstarmD0 = new TH1F("deltamDstarmD0","DeltamDstarmD0 districution",nbins,0.135,0.150);
  vect[6]= TdeltamDstarmD0;
  TH1F* Tmulti_cand = new TH1F("multi_cand","Multiple Candidate distribution",10,1,10);
  vect[7]=Tmulti_cand; 
  
  if (nentries<=0 || nentries>fChain->GetEntries()) nentries = Int_t(fChain->GetEntriesFast());
  cout<< "Number of Entries = " <<nentries<<endl; 
  
  Int_t nbytes(0), nb(0);
  Int_t ncand(1);
  Int_t runNumber_temp(0);
  Int_t event_temp(0);

  TString sel;
  if(cut_code==0) sel="Precut";
  if(cut_code!=0) {
    sel="Finalcut";
    if (cut_code!=100) {
      sel.Append(vect[cut_code-1]->GetName());
    }
  }
  Int_t ncreco=0;
  Int_t ncrecomatch=0;
  Int_t nereco=0;
  Int_t nerecomatch=0;
  
  for (Long64_t jentry=0; jentry<nentries;jentry++) 
    {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) 
	break;

      nb = fChain->GetEntry(jentry);   
      nbytes += nb;
      
      if(Cut(cut_code,kFALSE)<0) continue;

      ncreco++; // counter after the cut
      if(McEvtType==McEvt || McEvtType==McEvt2) 
	ncrecomatch++; // counts candidats matched
      
      //definisco il numero di multipli candidati
      //if ( (runnumber_temp==int(runnumber)) && (event_temp==int(event)))
      // cncand++; //contador de multipli candidati

      if ( (runNumber_temp==int(runNumber)) && (event_temp==int(event)))
	//same event
	ncand++;
      //  cout << "n cand = " << ncand<<endl;
      else {
	Tmulti_cand->Fill(ncand);
	ncand=1;
	runNumber_temp=Int_t(runNumber);
	event_temp=event;
	nereco++; //contador de multipli candidati
	if(McEvtType==McEvt || McEvtType==McEvt2) nerecomatch++;
      }
      //
      // fill histograms

      TmassD0->Fill(massD0); 
      TmassKs->Fill(massKs); 
      TcosKs->Fill(cosKs); 
     
      // Kaon ID bitmap
      if ((int(kaonidPi)&16)==16) TkaonidPi->Fill(1);
      else if ((int(kaonidPi)&1)==1) TkaonidPi->Fill(2);
      else if ((int(kaonidPi)&2)==2) TkaonidPi->Fill(3);
      else if ((int(kaonidPi)&4)==4) TkaonidPi->Fill(4);
      else if ((int(kaonidPi)&8)==8) TkaonidPi->Fill(5);
      else if ((int(kaonidPi)&1024)==1024) TkaonidPi->Fill(6);
      else if ((int(kaonidPi)&2048)==2048) TkaonidPi->Fill(7);
      else if ((int(kaonidPi)&4096)==4096) TkaonidPi->Fill(8);
      else if ((int(kaonidPi)&8192)==8192) TkaonidPi->Fill(9);
      else if ((int(kaonidPi)&16384)==16384) TkaonidPi->Fill(10);
      else TkaonidPi->Fill(0);
    
      TprobChi2Dstar->Fill(probChi2DstarBS);
      TprobChi2D0->Fill(probChi2D0);
      TdeltamDstarmD0->Fill(deltamDstarmD0);
    }  
  
  
  cout<<"contador candidatos reconstruidos="<<ncreco<<endl;
  cout<<"contador candidatos reconstruidos y matched ="<<ncrecomatch<<endl;
  cout<<"numero de multiples candidatos="<<nereco<<endl;
  cout<<"numero de multiples candidatos matchados="<<nerecomatch<<endl;
  cout<<"multiplicitat candidates="<<Double_t(ncreco)/Double_t(nereco)<<endl;
  
  if (ncrecomatch==0) nerecomatch=1;
  cout<<"multiplicitat candidates match="<<Double_t(ncrecomatch)/Double_t(nerecomatch)<<endl;
  // Double_t ef(0.);
  // ef=Double_t(ncreco)/6580.;//kpi0
  // ef=Double_t(ncreco)/4600.;//kspi
  // cout<<"eficiencia="<<ef<<endl; 
  canvas->cd();
  Int_t style(1);
  if (_sig_type=="signal" || _sig_type=="signalm" || _sig_type=="signalp") style=2;
  if (_sig_type=="chb") style=3;
  if (_sig_type=="b0b0bar") style=5;
  if (_sig_type=="bbbar") style=3;
  if (_sig_type=="uds")  style=6;
  if (_sig_type=="ccbar")  style=7;
  if (_sig_type=="udsccbar")  style=6;
  cout << "Making histograms with style = " << style << endl;
  
  gStyle->SetOptFit(0);
  gStyle->SetOptStat(111);

  if (sel == TString("Precut") || cut_code > 100) 
    { 
      for (Int_t j=0;j<=10;j++)
	{
	  vect[j]->SetLineWidth(style);
	  vect[j]->SetLineColor(style);
	  vect[j]->SetFillColor(style);
	  vect[j]->Draw();
	  TString filename="HIST/"+sel+"_"+_d0mode+"_"+_sig_type+".ps";
	  canvas->SaveAs(filename);
	  f[j]= new TFile("HIST/"+sel+"_"+_d0mode+"_"+_sig_type+".root","recreate");
	  f[j]->cd();
	  vect[j]->Write();
	  f[j]->Close();
	  delete f[j]; 
	}
    } 
  else if (cut_code == 100)
    {
      vect[10]->SetLineWidth(style);
      vect[10]->SetLineColor(style);
      vect[10]->SetFillColor(style);
      vect[10]->Draw();
      TString filename="HIST/"+sel+"multi_cand_"+_d0mode+"_"+_sig_type+".ps";
      canvas->SaveAs(filename);
      f[10]= new TFile("HIST/"+sel+"multi_cand_"+_d0mode+"_"+_sig_type+".root","recreate");
      f[10]->cd();
      vect[10]->Write();
      f[10]->Close();
      delete f[10]; 
    }
  else 
    {
      vect[cut_code-1]->SetLineWidth(style);
      vect[cut_code-1]->SetLineColor(style);
      vect[cut_code-1]->SetFillColor(style);
      vect[cut_code-1]->Draw();
      TString name(vect[cut_code-1]->GetName());
      TString filename="HIST/"+sel+"_"+_d0mode+"_"+_sig_type+".ps";
      canvas->SaveAs(filename);    
      f[cut_code-1]= new TFile("HIST/"+sel+"_"+_d0mode+"_"+_sig_type+".root","recreate");
      f[cut_code-1]->cd();
      vect[cut_code-1]->Write();
      f[cut_code-1]->Close();
      delete f[cut_code-1]; 
    }
  /*
  delete Tmes;
  delete Tdemk;
  delete TmassD0;
  delete TmassKs;
  delete TcosKs;
  delete Tkaonidpr;
  delete Tcosthrust;
  delete TprobChi2D0;
  delete TprobChi2ChB;
  delete Tmulti_cand;
  */
}


// it returns the inverse of chi-square using massD0 and massDstar0 (m0Dstar0Pi0).  
// It returns the inverse of the chi-square in way that best the candidates are that one with 1/chi2 GREATER!!!!
Double_t inclDstar_final::getchi(Float_t mD0)
{
  Double_t massD0m, massD0s;
  // from signal MC
  massD0m=1.8645;
  massD0s=0.0073;
  Double_t chi2(0.);
  chi2 = pow((mD0-massD0m),2)/pow(massD0s,2);
  // creo que faltan mas contribuciones
  //cout<<"chi2 ="<<chi2<<endl;
  Double_t invchi2 = 1./chi2;  
  return invchi2;  
}


void inclDstar_final::LoopBest(Int_t cut_code, Long64_t nentries, Int_t opt, TString myString)
{
  //
  // opt: 1=dump ascii file, 2=do not dump ascii file
  //
  gROOT->SetStyle("Plain");
  if (fChain == 0) return;

  char cut_code_str[10];
  sprintf(cut_code_str,"Cut%i",cut_code);
  char nentries_str[20];
  sprintf(nentries_str,"Nentries_%i",nentries);

  TString sdec="inclDstar_";
  TString outname="ASCII/"+sdec+_d0mode+"_"+_sig_type+"_Bbest_"+cut_code_str+"_"+nentries_str+myString+".dat";
  TString outname_fakeD0="ASCII/"+sdec+_d0mode+"_"+_sig_type+"_Bbest_"+cut_code_str+"_"+nentries_str+"_fakeD0"+myString+".dat";
  cout<< "file dat = "<< outname <<endl;
  ofstream outfile(outname);
  ofstream outfile_fakeD0(outname_fakeD0);
  //
  TString outfile_name="ASCII/bkg_"+sdec+_d0mode+"_"+_sig_type+"_"+nentries_str+myString+".study";
  ofstream outfile2(outfile_name);
  cout<<"outfile name = " <<outfile_name<<endl;




  //  Float_t mdstar0_nom = 2.0067; 
  //Float_t mD0_nom=1.8645;
  Float_t mKs_nom=0.49767;
  Float_t mPi_nom=0.139570;
  //Float_t mpi0_nom=0.13498;
  Float_t mK_nom=0.49368;
  Float_t mTrk_nom = (_d0mode=="kspipi")? mPi_nom : mK_nom ;
  //
  Int_t nbins(50);
  TCanvas *testcanv = new TCanvas();
  TH1F* Tdeltamtest = new TH1F("test_deltamDstarmD0","test_deltaM distribution",nbins,0.144,0.147); 

  TH1F* Tm12 = new TH1F("Tm12","delta q12-m12 distribution",nbins,-0.04,0.04);
  TH1F* Tm13 = new TH1F("Tm13","delta q13-m13 distribution",nbins,-0.04,0.04);
  TH1F* Tm23 = new TH1F("Tm23","delta q23-m23 distribution",nbins,-0.04,0.04);
  TH1F* Tmulti_cand = new TH1F("Tmulti_cand","Multiple Candidate distribution",10,1.0,10);

  TH1F  *vect[4];
  TH1F* TmassD0 = new TH1F("massD0","massD0 distribution",nbins,roomassD0->getMin(),roomassD0->getMax()); 
  vect[0]=TmassD0;
  TH1F* TdeltamDstarmD0 = new TH1F("deltamDstarmD0","deltaM distribution",nbins,0.135,0.15); 
  vect[1]=TdeltamDstarmD0;
  TH1F* TdeltaMDstarBS = new TH1F("deltaMDstarBS","deltaMBS distribution",nbins,roodeltaMDstarBS->getMin(),roodeltaMDstarBS->getMax()); 
  vect[2]=TdeltaMDstarBS;
  TH2F* Tdalitz = new TH2F("Tdalitz","Dalitz plot q12:q13",nbins*2,0.,4.,nbins*2,0.,4.);
  TH1F* TpD0 = new TH1F("TpD0","pD0 distribution",nbins,0,7.);
  TH1F* TpD0CM = new TH1F("TpD0CM","pD0CM distribution",nbins,0,7.);
  vect[3]=TpD0CM;
  RooDataSet* dataset = new RooDataSet("dataset","dataset",roovars);

  //########################################
  Int_t prevrun(0);
  Int_t prevev(0);
  Int_t debug(0);
  //
  Bool_t isfirst=true;
  Int_t mul(0);// event multiplicity
  Int_t istrue(0);// multiplicity for true events
  Int_t num1(0);// number of events with mul=1
  Int_t num1t(0);//number of candidats true with  mul=1
  Int_t num1f(0);//number of false candidates with mul=1
  Int_t numtrue(0);//number of events with mul>1 and a true candidate
  Int_t numfalse(0);//number of events with mul>1 and none true candidates
  Int_t totcand(0);//total number of candidates
  Int_t totevt(0);//total number of events
  Int_t num_right_choice(0);// number of events with mul>1 in wich it was choosen a true candidate. 
  Int_t num_wrong_choice(0);// number of events with mul>1 in wich it was choosen a false candidate. 
  Int_t ntot(0);//

  Double_t multiplicity(0);

  Double_t actualprob(0);
  Int_t actualevent(0);
  Int_t actualrunNumber(0);
  Int_t actualupperID(0);
  Int_t actuallowerID(0);

  Double_t actualmassD0(0);
  Int_t actualDstartruth(0);
  Float_t actualm12(0);    
  Float_t actualm13(0);    
  Float_t actualm23(0);    
 
  Float_t actualpPi(0);
  Float_t actualbeta_gamma(0);
  Int_t actualchargeDstar(0);
  Float_t actualq12(0);
  Float_t actualq13(0);
  Float_t actualq23(0);
  Int_t actualMcEvtType(0);
  Float_t actualpD0(0);
  Float_t actualpD0CM(0);
  Float_t actualdeltamDstarmD0(0);
  Float_t actualdeltaMDstarBS(0);

  Int_t actualisMcD0(0);
  Int_t actualisMcD0id(0);
  Int_t totD0bc(0);//total number of best candidates with matched D0
  Int_t actuallundPi(0);
  Int_t totPiRSbc(0);//total number of best candidates with matched D0 and a K-/pi-, or matched anti-D0 and a K+/pi+

  Int_t totD0(0);//total number of candidates with matched D0, w/o bc choice
  Int_t totPiRS(0); 
  Int_t totSigWSbc(0); //total number of best candidates WS signal
  Int_t totSigWS(0); //total number of candidates WS signal

  Int_t actualjentry(0);
  //##############################################
  //
  //
  if (fChain == 0) return;
  
  if (nentries<=0 || nentries>fChain->GetEntries()) nentries = Int_t(fChain->GetEntries());
  cout<< "Number of Entries = " <<nentries<<endl; 
  
  // codes for B decay code (ASCII file)
  Int_t ddecay_code = (_d0mode=="kspipi")? 1 : 2 ;   // 1=kspipi, 2=kskk
  Int_t nbytes = 0, nb = 0;
  
  for (Int_t jentry=0; jentry<nentries;jentry++) 

    {
      
      Int_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   
      nbytes += nb;
      
      if(Cut(cut_code,kFALSE)<0) continue;
   
      Float_t pD0=sqrt(pxD0*pxD0+pyD0*pyD0+pzD0*pzD0);
      Float_t pD0CM=pcmsD0;
      //TLorentzVector p4cmsD0(pxD0,pyD0,pzD0,eD0);
      //TVector3 boostVector(pxUps/eUps,pyUps/eUps,pzUps/eUps);
      //p4cmsD0.Boost(-boostVector);
      //Float_t pD0CM=sqrt(p4cmsD0.Px()*p4cmsD0.Px()+p4cmsD0.Py()*p4cmsD0.Py()+p4cmsD0.Pz()*p4cmsD0.Pz());
      
      // if event accepted, calculate relevant variables for the fit (data members)
      Int_t Dstartruth= (McEvtType==McEvt || McEvtType==McEvt2) ? 1 : 0;
      Int_t chargeDstar= (lundPi>0) ? 1 : 0;
      Float_t eD0Pi1=sqrt(pxD0Pi1*pxD0Pi1+pyD0Pi1*pyD0Pi1+pzD0Pi1*pzD0Pi1+mTrk_nom*mTrk_nom);
      Float_t eD0Pi2=sqrt(pxD0Pi2*pxD0Pi2+pyD0Pi2*pyD0Pi2+pzD0Pi2*pzD0Pi2+mTrk_nom*mTrk_nom);
      Float_t eKs=sqrt(pxKs*pxKs+pyKs*pyKs+pzKs*pzKs+mKs_nom*mKs_nom);
      TLorentzVector vKs,vPi1,vPi2;
      vKs.SetPxPyPzE(pxKs,pyKs,pzKs,eKs);
      vPi1.SetPxPyPzE(pxD0Pi1,pyD0Pi1,pzD0Pi1,eD0Pi1);
      vPi2.SetPxPyPzE(pxD0Pi2,pyD0Pi2,pzD0Pi2,eD0Pi2);
      Float_t m12=(lundD0Pi1>0)? (vKs+vPi1).Mag2() : (vKs+vPi2).Mag2() ;  // m2p
      Float_t m13=(lundD0Pi1<0)? (vKs+vPi1).Mag2() : (vKs+vPi2).Mag2() ;  // m2m
      Float_t m23=(vPi1+vPi2).Mag2();  // m2z
      // Float_t fisherDK=(0.595+0.1372*cosDstarCM-0.2983*legendrep2+0.1172*legendrep0-1.6151*fabs(costhrust));
      Float_t pPi=sqrt(pxPi*pxPi+pyPi*pyPi+pzPi*pzPi); // cm del prompt
      //cout << lundmcd0pi1 << " " << lundmcd0pi2 << endl;
      Float_t beta_gamma=pzUps/sqrt(eUps*eUps-pxUps*pxUps-pyUps*pyUps-pzUps*pzUps); // boost
      Float_t q12(0.),q13(0.),q23(0.);
      // evaluate and apply scaling factor
      //TLorentzVector vKsscal(vKs),vPi1scal(vPi1),vPi2scal(vPi2);
      //Double_t alpha;
      //alpha = Rescaling(vKsscal,vpi1scal,vpi2scal,md0_nom,vks.Mag(),vpi1.Mag(),vpi2.Mag());
      //      q12 = (vksscal+vpi1scal).Mag2();
      //q13 = (vksscal+vpi2scal).Mag2();
      //q23 = (vpi1scal+vpi2scal).Mag2(); 
      //
      //without mass constraint
      /*
	if(_d0mode == "kspipi"){
	q12 = (vKs+vPi2).Mag2();
	q13 = (vKs+vPi1).Mag2();
	q23 = (vPi1+vPi2).Mag2();
	}else if(_d0mode == "kskk"){
	q12 = (vKs+vPi1).Mag2();
	q13 = (vKs+vPi2).Mag2();
	q23 = (vPi1+vPi2).Mag2();
      }
      */
      // get Dalitz variables from rootuple, with mass constraint
      q12 = m2pDalitzD0;
      q13 = m2mDalitzD0;
      q23 = m2zDalitzD0;

      //assert(q12>0 && q23>0 && q13>0);

      Float_t DalCut = (_d0mode=="kskk")? 2. : 3.1;
      Float_t mD0trk =  (_d0mode=="kskk")? 0.493677 : 0.13957018;

      if(q12>DalCut || q13>DalCut){
	//cout<<jentry<<" "<<q12<<" "<<q13<< " "<<q23<<" "<<massD0-1.8645<<" "<<deltamDstarmD0-0.1454<<" "<<deltaMDstarBS-0.1454<<"           "<<fabs(sqrt(q12+q13+q23-(0.497648*0.497648)-(2*mD0trk*mD0trk))-1.8645)<<"           "<<fabs(sqrt(q12+q13+q23-(massKs*massKs)-(2*mD0trk*mD0trk))-1.8645)<<endl;
      }
      //cout<<jentry<<" "<<mTotDalitzD0<<" "<< pD0CM <<endl;
      // counting w/o bc choice
      Int_t isMcD0id = idMc[mothMc[indexMcD0Pi1]-1];
      if (isMcD0) {
	totD0++;
	if ( (isMcD0id==421 && lundPi==-211) || (isMcD0id==-421 && lundPi==211) ) totPiRS++;
      }
      if ( ( (isMcD0id==-421 && lundPi==-211) || (isMcD0id==421 && lundPi==211) ) && 
	   ( ((McEvtType&3845==3845 || McEvtType&3846==3846)) ) ) totSigWS++;
     
      
      //################################################################
      //################### best candidate selection ###################
      //################################################################
      if(event==prevev && runNumber==prevrun)
	{
	  //cout<<"same event"<<endl;
	  // SAME EVENT

	  Double_t thisprob=getchi(massD0);
	  if (debug) {
	      cout<<"Questo evento e' uguale al precedente"<<endl;
	      cout<<"event="<<event<<endl;
	      cout<<"massD0="<<massD0<<endl;
	      cout<<"massDstar="<<massDstar<<endl;
	      cout<<"thisprob="<<thisprob<<endl;
	  }

	  if (thisprob>actualprob) {
	    if (debug) cout<<"la prob di questo cand e' > del precedente cand"<<endl;
	    actualevent=event;
	    actualrunNumber=int(runNumber);
	    actualupperID=int(upperID);
	    actuallowerID=int(lowerID);

	    actualmassD0=massD0;
	    actualDstartruth=Dstartruth;	    
	    //actualfisherDK=fisherDK;
	    actualpPi=pPi;
	    actualbeta_gamma=beta_gamma;
	    actualchargeDstar=chargeDstar;
	    actualMcEvtType=McEvtType;
	    actualq12=q12;
	    actualq13=q13;
	    actualq23=q23;
	    actualm12=m12;
	    actualm13=m13;
	    actualm23=m23;
	    actualprob=thisprob;
	    actualdeltamDstarmD0=deltamDstarmD0;
	    actualdeltaMDstarBS=deltaMDstarBS;
	    actualisMcD0=isMcD0;
	    actualpD0=pD0;
	    actualpD0CM=pD0CM;
	    actuallundPi=lundPi;
	
	    actualisMcD0id=idMc[mothMc[indexMcD0Pi1]-1];
	
	    actualjentry=jentry;
	  }
	  else {
	    //cout<<"getchi"<<thisprob<<endl;  //lascia tutto invariato
	  }

	  //fine valutazione probabilita'
	  //
	  mul++;
	  prevev=event;
	  prevrun=prevrun;
	  //parte di verita' in eventi con mul>1
	  if (Dstartruth==1) istrue++;
	}

      else {
	// EVENT CHANGED
	
	//cout<<"event changed"<<endl;
	if (!isfirst)
	  {
	    //ORA SI OCCUPA DELL'EVENTO PRECEDENTE
	    //valuta la probabilita' dell'evento precedente
	    if (debug) {
	      cout<<endl<<"La probabilita' dell'ev precedente e' "<<actualprob<<endl;
	      //  cout<<"actualdemk dell'ev precedente = "<<actualdemk<<endl;
	    }
	    if (opt==1) {
	      //BAD899 appendix A
	      outfile<<"1"<<" "<<9000+ddecay_code<< " " <<" " <<actualchargeDstar<<" "
		     << actualq12 << " " << actualq13 << " " << actualq23 << " " 
		     <<"0" << " " <<"0" << " " << "0"<< " " << "0"<< " "
		     <<"0" << " " << actualpPi << " " << actualbeta_gamma<< " " 
		     <<"5.25" << " " << actualmassD0 << " " <<"0"<<" "  
		     <<actualrunNumber<<" "<<actualupperID<<" "<<actuallowerID<<endl; 
	      
	      if ( actualisMcD0==0 )
		outfile_fakeD0<<"1"<<" "<<9000+ddecay_code<< " " <<" " <<actualchargeDstar<<" "
		     << actualq12 << " " << actualq13 << " " << actualq23 << " " 
		     <<"0" << " " <<"0" << " " << "0"<< " " << "0"<< " "
		     <<"0" << " " << actualpPi << " " << actualbeta_gamma<< " " 
		     <<"5.25" << " " << actualmassD0 << " " <<"0"<<" "  
		     <<actualrunNumber <<" "<<actualupperID<<" "<<actuallowerID<<endl;
	      
	      //roodeltamDstarmD0->setVal(actualdeltamDstarmD0);
	      roodeltaMDstarBS->setVal(actualdeltaMDstarBS);
	      roomassD0->setVal(actualmassD0);
	      //  roofisherDK->setVal(actualfisherDK);
	      dataset->add(roovars);
	      //
	      // TfisherDK->Fill(actualfisherDK);
	      TmassD0->Fill(actualmassD0);
	      Tm12->Fill(actualq12-actualm12);
	      Tm13->Fill(actualq13-actualm13);
	      Tm23->Fill(actualq23-actualm23);
	      Tdalitz->Fill(actualq12,actualq13);
	      TdeltamDstarmD0->Fill(actualdeltamDstarmD0);
	      TdeltaMDstarBS->Fill(actualdeltaMDstarBS);
	      Tdeltamtest->Fill(actualdeltaMDstarBS);
	      TpD0->Fill(actualpD0);
	      TpD0CM->Fill(actualpD0CM);

	      //cout << actualmcEvtType << endl;
	      
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
	      
	    } else if (opt==2) {
	      outfile<<mul<<endl; 
	    } else assert(0);
	    
	    totcand+=mul;
	    totevt++;

	    if (actualisMcD0) {
	      totD0bc++;
	      if ( (actualisMcD0id==421 && actuallundPi==-211) || (actualisMcD0id==-421 && actuallundPi==211) ) totPiRSbc++;
	    }
	    if ( ( (actualisMcD0id==-421 && actuallundPi==-211) || (actualisMcD0id==421 && actuallundPi==211) ) && ( ((actualMcEvtType&3845==3845 || actualMcEvtType&3846==3846)) ) ) totSigWSbc++;
	    
	    //
	    if (mul>1) ((istrue>0)?numtrue++:numfalse++);
	    if (mul>1 && istrue>0 && actualDstartruth==1) num_right_choice++;	
	    if (mul>1 && istrue>0 && actualDstartruth==0) num_wrong_choice++;
	    if (mul==1) num1++;
	    if (mul==1) ((istrue>0)? num1t++:num1f++);
	    
	    
	    //ORA SI OCCUPA DEL NUOVO EVENTO: 
	    //valuta la probabilita' di questo evento
	    
	    Double_t thisprob=getchi(massD0);
	    //	      
	    actualevent=event;
	    actualrunNumber=Int_t(runNumber);
	    actualupperID=upperID;
	    actuallowerID=lowerID;

	    actualmassD0=massD0;	
	    actualDstartruth=Dstartruth;
	    // actualfisherDK=fisherDK;
	    actualpPi=pPi;
	    actualbeta_gamma=beta_gamma;
	    actualchargeDstar=chargeDstar;
	    actualMcEvtType=McEvtType;
	    actualm12=m12;
	    actualm13=m13;
	    actualm23=m23;
	    actualq12=q12;
	    actualq13=q13;
	    actualq23=q23;	
	    actualprob=thisprob;
	    actualisMcD0=isMcD0; 
	    actualpD0=pD0;
	    actualpD0CM=pD0CM;
	    actualisMcD0id=idMc[mothMc[indexMcD0Pi1]-1];
	
	    actuallundPi=lundPi; 
	    actualjentry=jentry;
	  
	    actualdeltamDstarmD0=deltamDstarmD0;
  	    actualdeltaMDstarBS=deltaMDstarBS;

	    if (debug) {
	      cout<<"event="<<event<<endl;
	      cout<<"massD0="<<massD0<<endl;
	      cout<<"la probab di questo evento e' "<<actualprob<<endl;
	    }
	    Tmulti_cand->Fill(mul);
	    mul=1;
	    istrue=0;
	    prevev=event;
	    prevrun=Int_t(runNumber);
	    //parte di verita' in eventi con mul>1
	    if (Dstartruth==1) istrue++;
	  }//end !isfirst
	
	else {// start ifirst cond

	  Double_t thisprob=getchi(massD0);
	  //	      
	  //cout<<"probabilidad = "<<thisprob<<endl;
	  actualevent=event;
	  actualrunNumber=Int_t(runNumber);
	  actualupperID=upperID;
	  actuallowerID=lowerID;
	  actualmassD0=massD0;	
	  actualDstartruth=Dstartruth;
	  //actualfisherDK=fisherDK;
	  actualpPi=pPi;
	  actualbeta_gamma=beta_gamma;
	  actualchargeDstar=chargeDstar;
	  actualMcEvtType=McEvtType;
	  actualm12=m12;
	  actualm13=m13;
	  actualm23=m23;	
	  actualq12=q12;
	  actualq13=q13;
	  actualq23=q23;
	  actualprob=thisprob;
	  actualisMcD0=isMcD0; 
	  actualisMcD0id=idMc[mothMc[indexMcD0Pi1]-1];
	
	  actuallundPi=lundPi; 
	  actualjentry=jentry;

	  actualdeltamDstarmD0=deltamDstarmD0;
	  actualdeltaMDstarBS=deltaMDstarBS;
	  //	
	  if (debug) {
	    cout<<"event="<<event<<endl;
	    cout<<"massD0="<<massD0<<endl;
	    cout<<"thisprob="<<thisprob<<endl;
	  }
	  //fine valutazione probabilita'
	  
	  //setta a false il flag isfirst
	  isfirst=false;
	  mul=1;
	  istrue=0;
	  prevev=event;
	  prevrun=Int_t(runNumber);
	  //parte di verita' in eventi con mul>1
	  if (Dstartruth==1) istrue++;
	}
	
      }//**** end else

      ntot++;

    }  // esco dal loop sugli entries nella rootupla

  //###################################################################################
  
  //###################################################################################
  
  //una volta uscito dal loop, effettua il controllo sull'ultimo evento del loop, che per costruzione e' sfuggito al controllo
  
  totcand+=mul;
  totevt++;
  //
  //
  
  if (actualisMcD0) {
    totD0bc++;
    if ( (actualisMcD0id==421 && actuallundPi==-211) || (actualisMcD0id==-421 && actuallundPi==211) ) totPiRSbc++;
  }
  if ( ( (actualisMcD0id==-421 && actuallundPi==-211) || (actualisMcD0id==421 && actuallundPi==211) ) && (((actualMcEvtType&3845==3845 || actualMcEvtType&3846==3846)) ) ) totSigWSbc++;
   
  //
  //
  //
  if (mul>1) ((istrue>0)?numtrue++:numfalse++);
  if (mul>1 && istrue>0 && actualDstartruth==1)num_right_choice++;
  if (mul>1 && istrue>0 && actualDstartruth==0)num_wrong_choice++;
  if (mul==1) num1++;
  if (mul==1) ((istrue>0)?num1t++:num1f++);
  Tmulti_cand->Fill(mul); 
  //
  if (opt==1) {
    
    outfile<<"1"<<" "<<9000+ddecay_code<< " " <<" " <<actualchargeDstar<<" "
	   << actualq12 << " " << actualq13 << " " << actualq23 << " " 
	   <<"0" << " " <<"0" << " " << "0"<< " " << "0"<< " "
	   <<"0" << " " << actualpPi << " " << actualbeta_gamma<< " " 
	   <<"5.25" << " " << actualmassD0 << " " <<"0"<<" "  
	   <<actualrunNumber <<" "<<actualupperID<<" "<<actuallowerID<<endl;
    
    
    if ( actualisMcD0==0 )
      outfile_fakeD0 <<"1"<<" "<<9000+ddecay_code<< " " <<" " <<actualchargeDstar<<" "
	   << actualq12 << " " << actualq13 << " " << actualq23 << " " 
	   <<"0" << " " <<"0" << " " << "0"<< " " << "0"<< " "
	   <<"0" << " " << actualpPi << " " << actualbeta_gamma<< " " 
	   <<"5.25" << " " << actualmassD0 << " " <<"0"<<" "  
	   <<actualrunNumber <<" "<<actualupperID<<" "<<actuallowerID<<endl;
    
    
    //roodeltamDstarmD0->setVal(actualdeltamDstarmD0);
    roodeltaMDstarBS->setVal(actualdeltaMDstarBS);
    roomassD0->setVal(actualmassD0);
    
    // roofisherDK->setVal(actualfisherDK);
    dataset->add(roovars);
    //
    TmassD0->Fill(actualmassD0);
    Tm12->Fill(actualq12-actualm12);
    Tm13->Fill(actualq13-actualm13);
    Tm23->Fill(actualq23-actualm23);
    Tdalitz->Fill(actualq12,actualq13);
    TdeltamDstarmD0->Fill(actualdeltamDstarmD0);
    TdeltaMDstarBS->Fill(actualdeltaMDstarBS);
    Tdeltamtest->Fill(actualdeltaMDstarBS);
    TpD0->Fill(actualpD0);
    TpD0CM->Fill(actualpD0CM);

    
    
    // get actualjentry
    Int_t ientry = LoadTree(actualjentry);
    nb = fChain->GetEntry(actualjentry); 
    bkg_tree(outfile2);
    // retrieve jentry
    ientry = LoadTree(nentries-1);
    nb = fChain->GetEntry(nentries-1); 
  } else if (opt==2) {    
    outfile<<mul<<endl;
  } else assert(0);

  cout<<endl;
  cout<<"CONTADORES IMPORTANTES"<<endl;
  cout<<"totD0="<<totD0<<endl;
  //cout<<"totdstar0pi0="<<totdstar0pi0<<endl;
  //cout<<"totdstar0gam="<<totdstar0gam<<endl;
  cout<<"totPiRS="<<totPiRS<<endl;
  cout<<"totSigWS="<<totSigWS<<endl;
  cout<<"totD0bc="<<totD0bc<<endl;
  //cout<<"totdstar0pi0bc="<<totdstar0pi0bc<<endl;
  //cout<<"totdstar0gambc="<<totdstar0gambc<<endl;
  cout<<"totPiRSbc="<<totPiRSbc<<endl;
  cout<<"totSigWSbc="<<totSigWSbc<<endl;
  cout<<"#############################"<<endl;  
  cout<<endl;
  cout<<"Summary of candidate multiplicity"<<endl;
  cout<<"totcand="<<totcand<<endl;
  cout<<"totevt="<<totevt<<endl;
  cout<<"num1="<<num1<<endl;
  cout<<"num1t="<<num1t<<endl;
  cout<<"num1f="<<num1f<<endl;
  cout<<"numtrue="<<numtrue<<endl;
  cout<<"numfalse="<<numfalse<<endl;
  cout<<"num_right_choice="<<num_right_choice<<endl;
  cout<<"num_wrong_choice="<<num_wrong_choice<<endl;
  cout<<"fraction correct choice="<<(Double_t) num_right_choice/(num_right_choice+num_wrong_choice)<<endl;
  multiplicity=(Double_t)totcand/totevt;
  cout<<"multiplicity="<<multiplicity<<endl;
  //
  cout<<"totD0bc="<<totD0bc<<endl;
  cout<<"fraction real D0s bc="<<(Double_t)totD0bc/totevt<<"+/-"
      <<sqrt(Double_t(totD0bc)*(1-(Double_t)totD0bc/totevt))/totevt<<endl;
  cout<<"fraction RS D0s bc="<<(Double_t)totPiRSbc/totD0bc<<"+/-"
      <<sqrt(Double_t(totPiRSbc)*(1-(Double_t)totPiRSbc/totD0bc))/totD0bc<<endl;
  cout<<"fraction WS D0s bc="<<(Double_t)(totD0bc-totPiRSbc)/Double_t(totD0bc)
      <<"+/-" << sqrt((Double_t)(totD0bc-totPiRSbc)*(1-(Double_t)(totD0bc-totPiRSbc)/Double_t(totD0bc)))/Double_t(totD0bc) <<endl;
  cout<<"totD0 w/o bc="<<totD0<<endl;
  cout<<"fraction real D0s w/o bc="<<(Double_t)totD0/totcand<<"+/-"
      <<sqrt(Double_t(totD0)*(1-(Double_t)totD0/(Double_t)totcand))/totcand<<endl;
  cout<<"fraction RS D0s w/o bc="<<(Double_t)totPiRS/(Double_t)totD0
      <<"+/-"<<sqrt(Double_t(totPiRS)*(1-(Double_t)totPiRS/(Double_t)totD0))/totD0<<endl;  

  cout<<"totPiRSbc="<<totPiRSbc<<endl;
  cout<<"totSigWSbc="<<totSigWSbc<<endl;

  cout<<"fraction WS signal bc= "<< (Double_t)totSigWSbc/(Double_t)totevt<<"+/-"
      << sqrt((Double_t)totSigWSbc*(1-(Double_t)totSigWSbc/(Double_t)totevt))/(Double_t)totevt << endl; 
  cout<<"totPiRS w/o bc="<<totPiRS<<endl;
  cout<< "totSigWS= " << totSigWS << endl;
  cout<< "fraction WS signal w/o bc=" << (Double_t)totSigWS/(Double_t)totcand<<"+/-"
      << sqrt((Double_t)totSigWS*(1-(Double_t)totSigWS/(Double_t)totcand))/(Double_t)totcand << endl; 
  cout<<endl;
  //  
  //
  //
  // make histograms and save in root file
  // save dataset in same root file
  //
  //
  //
  Int_t style(1);
  if (_sig_type=="signal" || _sig_type=="signalm" || _sig_type=="signalp") style=2;
  if (_sig_type=="chb") style=3;
  if (_sig_type=="b0b0bar") style=5;
  if (_sig_type=="bbbar") style=3;
  if (_sig_type=="uds")  style=6;
  if (_sig_type=="ccbar")  style=7;
  if (_sig_type=="udsccbar")  style=6;
  cout << "Making histograms with style = " << style << endl;
  
  TString filename_ASCII="ASCII/"+sdec+_d0mode+"_"+_sig_type+"_Bbest_"+cut_code_str+"_"+nentries_str+myString;

  TFile* file = new TFile(filename_ASCII+".root","recreate");
  file->cd();
  
  testcanv->Divide(1);
  testcanv->cd(1);
  Tdeltamtest->Draw();


  TCanvas* canvas= new TCanvas("canvas","canvas",500,500);  
  canvas->Divide(3,2);
  //draw dalitz plot
  canvas->cd(1);
  gStyle->SetPalette(1);
  Tdalitz->Draw("colZ");
  Tdalitz->Write();
  canvas->cd(2);
  gStyle->SetPalette(1);
  TmassD0->Draw();
  TmassD0->Write();
  canvas->cd(3);
  gStyle->SetPalette(1);
  TdeltamDstarmD0->Draw();
  TdeltamDstarmD0->Write();
  canvas->cd(4);
  gStyle->SetPalette(1);
  TdeltaMDstarBS->Draw();
  TdeltaMDstarBS->Write();
  gStyle->SetOptStat(1);
  canvas->cd(5);
  gStyle->SetPalette(1);
  TpD0->Draw();
  TpD0->Write();
  gStyle->SetOptStat(1);
  canvas->cd(6);
  gStyle->SetPalette(1);
  TpD0CM->Draw();
  TpD0CM->Write();
  gStyle->SetOptStat(1);
 
 //   canvas->cd(5);
//    gPad->SetLogy(1);
//    Tmulti_cand->GetXaxis()->SetTitle("N candidates per event");
//    Tmulti_cand->GetXaxis()->SetTitleSize(0.05);
//    Tmulti_cand->SetTitleOffset(1.1,"X");
//    Tmulti_cand->SetFillColor(style);
//    Tmulti_cand->SetLineColor(style);
//    Tmulti_cand->Draw();
//    Tmulti_cand->Write();

  canvas->Print(filename_ASCII+".eps");
  //canvas->Print(filename_ASCII+".gif");

  canvas->Divide(1);
  //for (Int_t j=0;j<=3;j++){
  for (Int_t j=0;j<=2;j++){
    canvas->cd();
    vect[j]->SetLineColor(style);
    vect[j]->SetFillColor(style);
    vect[j]->Draw();
    vect[j]->Write();
    TString name(vect[j]->GetName());
    //     if (name=="demk") vect[j]->Fit("gaus","L");
    canvas->Print(filename_ASCII+"_"+name+".eps");
    canvas->Print(filename_ASCII+"_"+name+".gif");
    cout<<"inside the for"<<endl;
  }
  cout<<"end loopbest"<<endl;
  dataset->Write("dataset");
  delete dataset;

  file->Close();
  delete file;
 

//
  // cout<<"end loopbest"<<endl;
  //
}  // end loopbest



void inclDstar_final::Fits(Int_t cut_code,Long64_t nentries,TString myString) {
 
  TString sdec=  "inclDstar_";
  char cut_code_str[10]; 
  sprintf(cut_code_str,"Cut%i",cut_code); 
  char nentries_str[20];
  sprintf(nentries_str,"Nentries_%i",nentries);
  
  TString filename_ASCII="ASCII/"+sdec+_d0mode+"_"+_sig_type+"_Bbest_"+cut_code_str+"_"+nentries_str+myString;
  TFile* file = new TFile(filename_ASCII+".root","read"); 
  if (file->IsZombie()) { 
    cout << "Error opening file: " << filename_ASCII+".root" << endl; 
    return;  
  } else { 
    cout << "File read succesfully: " << filename_ASCII+".root" << endl; 
  }
  RooDataSet* dataset = (RooDataSet*)file->Get("dataset");
  Int_t nevts = dataset->numEntries();
  cout << "dataset has " << nevts << " entries " << endl;
  
  TCanvas* canvas= new TCanvas("canvas","canvas",500,500);
  //
  Int_t style(1);
  if (_sig_type=="signal" || _sig_type=="signalm" || _sig_type=="signalp") style=2;
  if (_sig_type=="data") style=3;
  if (_sig_type=="chb") style=3;
  if (_sig_type=="b0b0bar") style=5;
  if (_sig_type=="bbbar") style=3;
  if (_sig_type=="uds")  style=6;
  if (_sig_type=="ccbar")  style=7;
  if (_sig_type=="udsccbar")  style=6;
 
  cout << "Making histograms with style = " << style << endl;
  //
  Int_t nbins(50);
  roovars.Print("v");//print roorealvars names saved in roovars.
  TIterator* iter = roovars.createIterator();
  RooRealVar* var;
  while ((var = (RooRealVar*)iter->Next())) 
    { 
      TString name(var->GetName());
      RooAbsPdf* pdf(0);
      if (name=="massD0") {
	if (cut_code==1 || cut_code==112) pdf = getPdf(*var);
      } else if (name=="deltaMDstarBS") { 
  	if (cut_code==2 || cut_code==112) pdf = getPdf(*var);
      } else assert(0);
      
      if (pdf) { 
	RooPlot* xframe = var->frame(nbins); 
	dataset->plotOn(xframe); 
	xframe->getAttLine()->SetLineColor(style); 
	xframe->getAttFill()->SetFillColor(style); 
	xframe->getAttMarker()->SetMarkerColor(style); 
	dataset->statOn(xframe,Layout(0.15,0.4,0.8),What("N")); 
	xframe->getAttText()->SetTextSize(0.015); 
	pdf->fitTo(*dataset,"mh"); 
	//RooArgSet projDeps; 
	//pdf->plotOn(xframe,ProjWData(projDeps,*dataset)); 
	pdf->plotOn(xframe); 
	xframe->getAttLine()->SetLineColor(style); 
	pdf->paramOn(xframe); 
	xframe->getAttText()->SetTextSize(0.015); 
	xframe->Draw(); 
	//	pdf->GetParameters(&parameters[0]);
	//cout<<"pdf values  "<<pdf->getVal()<<endl;
	canvas->Print(filename_ASCII+"_"+name+"_fit.eps"); 
	canvas->Print(filename_ASCII+"_"+name+"_fit.gif"); 
	if (pdf) delete pdf; 
      } 
    }//end while
  delete iter;  
  //file->Close(); 
  //delete file; 
}//end Fits 
 

RooAbsPdf* inclDstar_final::getPdf(RooRealVar& var) {
  TString varname(var.GetName());
  if (varname=="massD0") {

    //the first gaussian
    RooRealVar* massD0G1Mean = new RooRealVar("massD0G1Mean","massD0 Gaussian1 mean",1.86,1.87,"GeV") ;
    RooRealVar* massD0G1Width = new RooRealVar("massD0G1Width","massD0 Gaussian1 width",0.003,0.,0.05,"GeV") ;
    RooAbsPdf* massD0G1Pdf = new RooGaussian("massD0G1Pdf","massD0 Gauss1 PDF",var,*massD0G1Mean,*massD0G1Width);     
    //the second gaussian
    //   RooRealVar* massD0G2Mean = new RooRealVar("massD0G2Mean","massD0 Gaussian2 mean",1.865,1.84,1.89,"GeV") ;

    RooRealVar* massD0G2Width = new RooRealVar("massD0G2Width","massD0 Gaussian2 width",0.008,0.,0.05,"GeV") ;
    RooAbsPdf* massD0G2Pdf = new RooGaussian("massD0G2Pdf","massD0 Gauss2 PDF",var,*massD0G1Mean,*massD0G2Width) ;
    // sum of two gaussians 
    RooRealVar* fmassD0G = new RooRealVar("fmassD0G","massD0 1st Gaussian fraction",0.,1.) ;
    RooAbsPdf* massD0SignalPdf = new RooAddPdf("massD0SignalPdf","massD0 Signal Gaussian PDF",RooArgList(*massD0G1Pdf,*massD0G2Pdf),RooArgList(*fmassD0G));
    //a polynomial for background
    RooRealVar* massD0PolyC0 = new RooRealVar("massD0PolyC0","massD0 polynomial coefficient C0",0.,-100.,100.) ;
    //  RooRealVar* massD0PolyC2 = new RooRealVar("massD0PolyC2","massD0 polynomial coefficient C2",-1.,1) ; 
   
    RooAbsPdf* massD0PolyPdf = new RooPolynomial("massD0PolyPdf","massD0 polynomial PDF",var,RooArgList(*massD0PolyC0));
    // the pdf
    RooRealVar* fmassD0SignalG = new RooRealVar("fmassD0SignalG","massD0 Signal Gaussian fraction",0.,1.) ;
    RooAbsPdf* massD0Pdf = new RooAddPdf("massD0Pdf","massD0 PDF",RooArgList(*massD0SignalPdf,*massD0PolyPdf),RooArgList(*fmassD0SignalG));

    // RooRealVar* massD0ArgMax = new RooRealVar("massD0ArgMax","massD0 Argus cutoff of massD0",1.9,"GeV") ;
    // RooRealVar* massD0ArgPar = new RooRealVar("massD0ArgPar","massD0 Argus slope",-122.0,-1000.0,0.0) ;    
    // RooAbsPdf* massD0ArgPdf = new RooArgusBG("massD0ArgPdf","massD0 Argus PDF",var,*massD0ArgMax,*massD0ArgPar) ;
   
    if (_sig_type=="signal" || _sig_type=="signalm" || _sig_type=="signalp" || _sig_type=="On" || _sig_type=="ccbar" || _sig_type=="On1234" || _sig_type=="On5") {
      //if (_sig_type=="chb" || _sig_type=="b0b0bar") {
      //  massD0GWidth->setVal(0.0038); massD0GWidth->setConstant(); 
      //}
      return massD0Pdf;
    } else if (_sig_type=="chb" || _sig_type=="b0b0bar" || _sig_type=="uds") {
      // return massD0ArgPdf;
    }  else assert(0);       
  }//end massD0 if  
  // 
  if (varname=="deltaMDstarBS") {
    //The first gauss distribution
    RooRealVar* deltaMDstarBSG1Mean   = new RooRealVar("deltaMDstarBSG1Mean","DeltamDstarmD0BS 1st Gaussian mean",0.14542310,0.145,0.146) ;
    RooRealVar* deltaMDstarBSG1Width  = new RooRealVar("deltaMDstarBSG1Width","DeltamDstarmD0BS 1st Gaussian width",0.0002007,0.0001,0.01) ;
    RooAbsPdf* deltaMDstarBSG1Pdf    = new RooGaussian("deltaMDstarBSG1Pdf","DeltamDstarmD0BS 1st Gaussian",var,*deltaMDstarBSG1Mean,*deltaMDstarBSG1Width) ;
    
    //the second one
    RooRealVar* deltaMDstarBSG2Mean   = new RooRealVar("deltaMDstarBSG2Mean","DeltamDstarmD0BS 2st Gaussian mean",0.14535,0.145,0.146) ;
    RooRealVar* deltaMDstarBSG2Width  = new RooRealVar("deltaMDstarBSG2Width","DeltamDstarmD0BS 2st Gaussian width",0.001406,0.0001,0.01) ;
    //RooAbsPdf* deltaMDstarBSG2Pdf = new RooGaussian("deltaMDstarBSG2Pdf","DeltamDstarmD0BS 2st Gaussian",var,*deltaMDstarBSG2Mean,*deltaMDstarBSG2Width) ;
    RooAbsPdf* deltaMDstarBSG2Pdf = new RooGaussian("deltaMDstarBSG2Pdf","DeltamDstarmD0BS 2st Gaussian",var,*deltaMDstarBSG1Mean,*deltaMDstarBSG2Width) ;

    //fractions
    RooRealVar* gaussG1Frac = new RooRealVar("gaussG1frac","DeltamDstarmD0BS fraction of 1st Gaussian",0.6435,0.,1.);
    RooRealVar* signalFrac = new RooRealVar("signalFrac","DeltamDstarmD0BS signal fraction",0.6622,0.,1.);
    //the BKG function
    // parameters value fixed as BAD1237
    RooRealVar* aBKG =  new RooRealVar("aBKG","aBKG",0.034,-100,100);//-0.56557,-20.,20.);
    RooRealVar* bBKG =  new RooRealVar("bBKG","bBKG",3.63,0,100);//0.19706,0.,10.);
    RooRealVar* cBKG =  new RooRealVar("cBKG","cBKG",0.000351,0,1);//0.25464,0.,1.5);
    RooRealVar* dmBKG =  new RooRealVar("dmBKG","dmBKG",0.13950);
    RooAbsPdf* bkgpdf = new RooDstD0BG("bkgpdf","bkgpdf",var,*dmBKG,*cBKG,*aBKG,*bBKG) ;

    //the pdf
    RooAbsPdf* gaussSum = new RooAddPdf("signalpdf","signalpdf",RooArgList(*deltaMDstarBSG1Pdf,*deltaMDstarBSG2Pdf),RooArgList(*gaussG1Frac));
    RooAbsPdf* alternativeDeltaMPdf = new RooAddPdf("alternativeDeltaMPdf","DeltamDstarmD0BS PDF",RooArgList(*gaussSum,*bkgpdf),RooArgList(*signalFrac)) ; 
    // RooAbsPdf* alternativeDeltaMPdf = new RooAddPdf("alternativeDeltaMPdf","DeltamDstarmD0BS PDF",RooArgList(*deltaMDstarBSG1Pdf,*bkgpdf),RooArgList(*signalFrac)) ; 

    if(_sig_type=="signal") return alternativeDeltaMPdf;
    //if(_sig_type=="signal") return gaussSum;
    //if(_sig_type=="signal") return deltaMDstarBSG1Pdf;
    else if(_sig_type=="On" || _sig_type=="On1234" ||_sig_type=="On5") return alternativeDeltaMPdf;
  } // end  deltaMDstarBSDK
  
   return 0;
  
}//end getpdf 



void inclDstar_final::bkg_tree(ofstream& outfile2)
{
  //cout<<"start bkg_tree"<<endl;
  
  //defining the mothers of the traces candidates 

  Int_t gmD0Pi1(0);
  Int_t gmD0Pi2(0);
  Int_t gmD0KsPi1(0);
  Int_t gmD0KsPi2(0);
  
  Int_t gmPi(0);
  
 
  
  //Int_t lpr(0);
  Int_t lD0(0);
  
  Bool_t check=kTRUE;
    
  outfile2<<endl<<endl;
  
  //if(signal_code==1) outfile2<<"event number:"<<event<<" D0 o D*0 : "<<_dtype<<" D0 ="<<isMcD0/*<<"D0Ks="<<isMcD0k*/<<" D0mode ="<<D0_decay_code<<endl;

  //else outfile2<<"event number :"<<event<<" D0 o D*0 :"<<signal_code<<" D0 ="<<isMcD0/*<<"D0Ks="<<isMcD0k*/<<" Dstar0Gam ="<<isMcDstar0Gam<<" DstarPi0 ="<< isMcDstar0Pi0<< " D0mode="<<D0mode<<endl;
  
  //#############################
  //###########  Pi track    ####
  //#############################
  
   if (indexMcPi>0 && indexMcPi<110){
     outfile2<<idMc[indexMcPi]<<" "; 
     gmPi=indexMcPi;
     check=kTRUE;
     while ( (abs(idMc[gmPi]) != 70553) && (abs(idMc[gmPi]) != 413) && (abs(idMc[gmPi]) != 10022) && gmPi>0 && gmPi<110 && check) {
       check=kFALSE;
       if (  ((mothMc[gmPi]-1)>0) && ((mothMc[gmPi]-1)<110) ){
	 gmPi=mothMc[gmPi]-1;
	 outfile2<<idMc[gmPi]<<" ";
	 check=kTRUE;
       }
       //	else  break;
       
     }
     outfile2<<endl;
   }	
   
   
   //##########################################
   //##############D0 candidate tracKs########
   //#########################################
   
   outfile2<<"D0 daughter D0Pi1 candidate: ";
   if (indexMcD0Pi1>0 && indexMcD0Pi1<110)
     {
    
       outfile2<<idMc[indexMcD0Pi1]<<" "; 
       gmD0Pi1=indexMcD0Pi1;
       check=kTRUE;
       while ( (abs(idMc[gmD0Pi1]) != 70553) && (abs(idMc[gmD0Pi1]) != 413) && (abs(idMc[gmD0Pi1]) != 10022) && gmD0Pi1>0 && gmD0Pi1<110 && check) 
	 {
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
   if (indexMcD0Pi2>0 && indexMcD0Pi2<110)
     {
       
       outfile2<<idMc[indexMcD0Pi2]<<" "; 
       gmD0Pi2=indexMcD0Pi2;
       check=kTRUE;
       while ( (abs(idMc[gmD0Pi2]) != 70553) && (abs(idMc[gmD0Pi2]) != 413) && (abs(idMc[gmD0Pi2]) != 10022) && gmD0Pi2>0 && gmD0Pi2<110 && check) 
	 {
	   
	   check=kFALSE;
	   if (  ((mothMc[gmD0Pi2]-1)>0) && ((mothMc[gmD0Pi2]-1)<110) )
	     {
	       gmD0Pi2=mothMc[gmD0Pi2]-1;
	       outfile2<<idMc[gmD0Pi2]<<" ";
	       check=kTRUE;
	     }
	   //	else  break;
	 }
       outfile2<<endl;
     }
   
   //##############D0 candidate tracks:  KS daughters   ####################################
   outfile2<<"D0 daughter KsPi1 candidate: ";
   if (indexMcD0KsPi1>0 && indexMcD0KsPi1<110)
     {
      
       outfile2<<idMc[indexMcD0KsPi1]<<" "; 
       gmD0KsPi1=indexMcD0KsPi1;
       check=kTRUE;
       while ( (abs(idMc[gmD0KsPi1]) != 70553) && (abs(idMc[gmD0KsPi1]) != 413) && (abs(idMc[gmD0KsPi1]) != 10022) && gmD0KsPi1>0 && gmD0KsPi1<110 && check) 
	 {
	   
	   check=kFALSE;
	   if (  ((mothMc[gmD0KsPi1]-1)>0) && ((mothMc[gmD0KsPi1]-1)<110) ) 
	     {
	       gmD0KsPi1=mothMc[gmD0KsPi1]-1;
	       outfile2<<idMc[gmD0KsPi1]<<" ";
	       check=kTRUE;
	     }
	   //	else  break;
	   
	 }
       outfile2<<endl;
     }
   
   outfile2<<"D0 daughter KsPi2 candidate: ";
   if (indexMcD0KsPi2>0 && indexMcD0KsPi2<110)
     {
      
       outfile2<<idMc[indexMcD0KsPi2]<<" "; 
       gmD0KsPi2=indexMcD0KsPi2;
       check=kTRUE;
       while ( (abs(idMc[gmD0KsPi2]) != 70553) && (abs(idMc[gmD0KsPi2]) != 521) && (abs(idMc[gmD0KsPi2]) != 10022) && (abs(idMc[gmD0KsPi2]) != 511) && gmD0KsPi2>0 && gmD0KsPi2<110 && check ) 
	 {
	   
	   check=kFALSE;
	   if (  ((mothMc[gmD0KsPi2]-1)>0) && ((mothMc[gmD0KsPi2]-1)<110) )
	     {
	       gmD0KsPi2=mothMc[gmD0KsPi2]-1;
	       outfile2<<idMc[gmD0KsPi2]<<" ";
	       check=kTRUE;
	     }
	   //	else  break;
	 }
       outfile2<<endl;
     }
   
   outfile2<<endl;
   outfile2<<endl;
   
}

void inclDstar_final::LoopPWA(TString ref_frame,Int_t coshOpt,Int_t cut_code,Long64_t nentries, Int_t Dflavour) {

  ////////////////////////////////////////////////////
  ////// ref_frame = m2z,   h+h- rest frame  /////////
  ////// ref_frame = m2p,   h+Ks rest frame  /////////
  ////// ref_frame = m2m,   h-Ks rest frame  /////////
  ////////////////////////////////////////////////////
  //   coshOpt=0 (boost),  coshOpt=1 (invariant)
  ////////////////////////////////////////////////////
  // Dflavour is -1 for \barD^0, 1 for D^0 and 0 for both. It was tagged with the charge of the soft pion
  ///////////////////////////////////////////////////

  gROOT->SetStyle("Plain");
  if (fChain == 0) return;

  assert(ref_frame=="m2p" || ref_frame=="m2m" || ref_frame=="m2z");
  assert(coshOpt==1 || coshOpt==0); // 1 for calculation using invariants and 0 for boosting.
  assert(Dflavour==-1 || Dflavour==1 || Dflavour==0);// -1 for Dbar, 0 for D and Dbar and 1 for Dbar

  Double_t mD0trk =  (_d0mode=="kskk")? 0.49368 : 0.139570;
  Double_t m0Ks = 0.49767;
  Double_t mD0nom = 1.8645;
  // histos 
  TCanvas* canvasPWA = new TCanvas;
  TCanvas* canvastest = new TCanvas;

  // PDF for the signal and background
  ////////////////////////////////////////////////////////////////////////
  ///////the values for the parameters have been set by Fits method. Do not change this values wich represent the best fit for massD0!!!!
  Double_t massD0GMean = (_d0mode=="kskk")? 1.8647794 : 1.8650125;
  Double_t massD0G1Width = (_d0mode=="kskk")? 0.0031132 : 0.005033;
  Double_t massD0G2Width = (_d0mode=="kskk")? 0.008085 : 0.0103;
  Double_t fmassD0G = (_d0mode=="kskk")? 0.8338 : 0.7762;
  Double_t massD0PolyC1 = (_d0mode=="kskk")? -0.3602 : -0.510526;
  Double_t fmassD0SignalG =(_d0mode=="kskk")? 0.95871 : 0.93292;
  TF1* Gauss = new TF1("gauss","exp(-(x-y)*(x-y)/(2.*z*z))");
  //////////////////////////////////////////////////////////////////////
  Int_t nbins(30);
  Double_t min_value = (ref_frame=="m2z")? 2*mD0trk : m0Ks+mD0trk;
  Double_t max_value = (ref_frame=="m2z")? mD0nom-m0Ks : mD0nom-mD0trk;

  TH1F* TcoshBoost = new TH1F("coshBoost","Cos of helicity distribution with Boost",nbins,-1.,1.); 
  TH1F* TcoshInv = new TH1F("coshInv","Cos of helicity distribution with invariants",nbins,-1.,1.); 
  TH1F* TPWAmom0 = new TH1F("P0","PWA moment 0",nbins,min_value,max_value); 
  TH1F* TPWAmom1 = new TH1F("P1","PWA moment 1",nbins,min_value,max_value); 
  TH1F* TPWAmom2 = new TH1F("P2","PWA moment 2",nbins,min_value,max_value); 
  TH1F* TPWAmom3 = new TH1F("P3","PWA moment 3",nbins,min_value,max_value); 
  TH1F* TPWAmom4 = new TH1F("P4","PWA moment 4",nbins,min_value,max_value); 
  TH2F* TdalitzPlot = new TH2F("TdalitzPlot","DalitzPlot noRefFrame",nbins*2,0.,4.,nbins*2,0.,4.);
  TH1F* Tm2_13 = new TH1F("m2_13_var","m2_13_var",nbins*3,0.,3.5); 
  TH1F* Tm2_23 = new TH1F("m2_23_var","m2_23_var",nbins*3,0.,3.5);
  TH1F* Tm2_12 = new TH1F("m2_12_var","m2_12_var",nbins*3,0.,3.5);
  TH1F* TmassD0 = new TH1F("massD0","massD0 distribution",nbins*2,roomassD0->getMin(),roomassD0->getMax()); 

  // The error per bin will be computed as sqrt(sum of squares of weight) for each bin.
  TPWAmom0->Sumw2();
  TPWAmom1->Sumw2();
  TPWAmom2->Sumw2();
  TPWAmom3->Sumw2();
  TPWAmom4->Sumw2();
  //
  if (nentries<=0 || nentries>fChain->GetEntries()) nentries = Int_t(fChain->GetEntries());
  cout<< "Number of Entries = " <<nentries<<endl; 
  Int_t nbytes(0),nb(0);
  Int_t d0s(0),d0bars(0);
  //
  //
  for (Int_t jentry=0; jentry<nentries;jentry++) 
    {
      Int_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   
      nbytes += nb;
      //
      if(Dflavour>0 && lundPi<0) continue;
      if(Dflavour<0 && lundPi>0) continue;
      if(Cut(cut_code,kFALSE)<0) continue;
      //

      //
      Double_t m1(0.), m2(0.), m3(0.);
      Double_t m2_13(0.), m2_23(0.), m2_12(0.);
      // Calculated with the nominal values for the masses
      Double_t eD0Pi1 = sqrt(mD0trk*mD0trk+pxD0Pi1*pxD0Pi1+pyD0Pi1*pyD0Pi1+pzD0Pi1*pzD0Pi1);
      Double_t eD0Pi2 = sqrt(mD0trk*mD0trk+pxD0Pi2*pxD0Pi2+pyD0Pi2*pyD0Pi2+pzD0Pi2*pzD0Pi2);
      Double_t eD0Ks = sqrt(m0Ks*m0Ks+pxKs*pxKs+pyKs*pyKs+pzKs*pzKs);
      //
      TLorentzVector cvD0Pi1(pxD0Pi1,pyD0Pi1,pzD0Pi1,eD0Pi1);
      TLorentzVector cvD0Pi2(pxD0Pi2,pyD0Pi2,pzD0Pi2,eD0Pi2);
      TLorentzVector cvD0Ks(pxKs,pyKs,pzKs,eD0Ks);
      
      TLorentzVector cvp1, cvp2, cvp3;
      if(lundPi>0) d0s++;
      else d0bars++;

      // These conventions appear in "P-wave in B0->kskk" talk at babar.coll.meet.dec.2005.
      /////////////////
      if(_d0mode=="kskk"){
	cvp1 = ((ref_frame=="m2m")||(ref_frame=="m2z" && lundPi<0))? cvD0Pi1 : cvD0Pi2;
	cvp2 = (ref_frame=="m2z")? cvD0Ks : (ref_frame=="m2p")? cvD0Pi1 : cvD0Pi2;
	cvp3= (ref_frame=="m2z" && lundPi>0)? cvD0Pi1 : (ref_frame=="m2z" && lundPi<0)? cvD0Pi2 : cvD0Ks;
      }else{
	cvp1 = ((ref_frame=="m2m")||(ref_frame=="m2z" && lundPi<0))? cvD0Pi2 : cvD0Pi1;
	cvp2 = (ref_frame=="m2z")? cvD0Ks : (ref_frame=="m2p")? cvD0Pi2 : cvD0Pi1;
	cvp3= (ref_frame=="m2z" && lundPi>0)? cvD0Pi2 : (ref_frame=="m2z" && lundPi<0)? cvD0Pi1 : cvD0Ks;
      }
      m1 = mD0trk;
      m2 = (ref_frame=="m2z")? m0Ks : mD0trk;
      m3 = (ref_frame=="m2z")? mD0trk : m0Ks;
      m2_13 = (ref_frame=="m2z")? m2zDalitzD0 : (ref_frame=="m2p")? m2pDalitzD0 : m2mDalitzD0;
      m2_23 = ((ref_frame=="m2p")||(ref_frame=="m2z" && lundPi>0))? m2mDalitzD0 : m2pDalitzD0;
      m2_12 = (ref_frame=="m2z" && lundPi>0)? m2pDalitzD0 : (ref_frame=="m2z" && lundPi<0)? m2mDalitzD0 : m2zDalitzD0;
      ////////////////////////////////////////////////////////////////////

      Double_t mRef = sqrt(m2_13);
      Double_t CosHelGJ =  CosHelBoostGJ(cvp1,cvp2,cvp3);   
      Double_t CosHelInv = CosHelInvar(m1,m2,m3,m2_13,m2_12,m2_23,1);
      //      cout << "m1, m2, m3 = " << m1 << " " << m2 << " " << m3 << endl;

      Double_t cosHel = (coshOpt==1)? CosHelInv : CosHelGJ;
      
      if(fabs(cosHel)>=1.){
      	cout<<jentry<<" "<<cosHel<<"----ATTENTION----ERROR IN COSHEL CALCULATION"<<endl;
	continue;
      }
      // weight and pdf evaluation
      Double_t gauss1 = Gauss->Eval(massD0,massD0GMean,massD0G1Width);
      Double_t gauss2 = Gauss->Eval(massD0,massD0GMean,massD0G2Width);
      Double_t SignalPDF = (Double_t) fmassD0SignalG*(fmassD0G*gauss1+(1.-fmassD0G)*gauss2);
      Double_t TotalPDF = (Double_t) fmassD0SignalG*(fmassD0G*gauss1+(1.-fmassD0G)*gauss2)+(1.-fmassD0SignalG)*(1+massD0PolyC1*massD0);
      Double_t weight = (Double_t) SignalPDF/TotalPDF;
      assert(weight<=1. && weight>=0.);
      //
      Double_t LP_0 = sqrt(0.5)*weight; // W_i = Vsig,i pdf_sig ... a la sPlot?
      Double_t LP_1 = sqrt(3./2.)*cosHel*weight;
      Double_t LP_2 = sqrt(5./2.)*0.5*(3*cosHel*cosHel-1)*weight;
      Double_t LP_3 = sqrt(7./2.)*0.5*(5*cosHel*cosHel*cosHel-3*cosHel)*weight;
      Double_t LP_4 = sqrt(9./2.)*(1./8.)*(35*cosHel*cosHel*cosHel*cosHel-30*cosHel*cosHel+3)*weight;
      
      // cout<<jentry<<" "<<LP_0<<" "<<LP_1<<" "<<LP_2<<endl;
      // Filling histos
      TcoshBoost->Fill(CosHelGJ);
      TcoshInv->Fill(CosHelInv);
      TPWAmom0->Fill(mRef,LP_0);
      TPWAmom1->Fill(mRef,LP_1);
      TPWAmom2->Fill(mRef,LP_2);
      TPWAmom3->Fill(mRef,LP_3);
      TPWAmom4->Fill(mRef,LP_4);
      TdalitzPlot->Fill(m2_23,m2_12);    
      //
      Tm2_13->Fill(m2_13);
      Tm2_23->Fill(m2_23);
      Tm2_12->Fill(m2_12);
      TmassD0->Fill(massD0);
     
    }//end for

  //number of D0 and D0bar respectively
  
  cout<<d0s<<" "<<d0bars<<endl;

  //plot and store histos
  TFile* myfile = new TFile("HIST/PWA_"+ref_frame+" "+_d0mode+"_"+_sig_type+""".root","recreate");
  myfile->cd();

  canvasPWA->Divide(4,2);
  canvasPWA->cd(1);  
  TcoshBoost->Draw("E");
  TcoshBoost->Write();
  canvasPWA->cd(2);  
  TcoshInv->Draw("E");
  TcoshInv->Write();
  canvasPWA->cd(3);  
  TPWAmom0->Draw("E");
  TPWAmom0->Write();
  canvasPWA->cd(4);  
  TPWAmom1->Draw("E");
  TPWAmom1->Write();
  canvasPWA->cd(5);  
  TPWAmom2->Draw("E");
  TPWAmom2->Write();
  canvasPWA->cd(6);  
  TPWAmom3->Draw("E");
  TPWAmom3->Write();
  canvasPWA->cd(7);  
  TPWAmom4->Draw("E");
  TPWAmom4->Write();
  canvasPWA->cd(8);
  TdalitzPlot->Draw("colZ");
  TdalitzPlot->Write();
  //
  canvastest->Divide(2,2);
  canvastest->cd(1);
  Tm2_13->Draw();
  Tm2_13->Write();
  canvastest->cd(2);
  Tm2_23->Draw();
  Tm2_23->Write();
  canvastest->cd(3);
  Tm2_12->Draw();
  Tm2_12->Write();
  canvastest->cd(4);
  TmassD0->Draw();
  TmassD0->Write();
  //
  // canvasPWA->Print("ASCII/inclDstar_PWA_"+ref_frame+"_"+_d0mode+"_"+_sig_type+".eps");
  myfile->Close();
  //
}//end PWA








Double_t inclDstar_final::CosHelBoostGJ(TLorentzVector vp1, 
					TLorentzVector vp2,
					TLorentzVector vp3) 
{
  Int_t flag = 1;
  Double_t out = -999;

  TLorentzVector pRef = vp1+vp3;
 
  TVector3 boostVector(pRef.Px()/pRef.E(),pRef.Py()/pRef.E(),pRef.Pz()/pRef.E());
  TLorentzVector vpD0(pxD0,pyD0,pzD0,eD0);
  
  vpD0.Boost(-boostVector);
  vp1.Boost(-boostVector);
  vp2.Boost(-boostVector);
  vp3.Boost(-boostVector);

  TVector3 p0GJ(vpD0.Px(),vpD0.Py(),vpD0.Pz());
  TVector3 p1GJ(vp1.Px(),vp1.Py(),vp1.Pz());
  TVector3 p2GJ(vp2.Px(),vp2.Py(),vp2.Pz());
  TVector3 p3GJ(vp3.Px(),vp3.Py(),vp3.Pz());      

  Double_t CosHel = cos(p2GJ.Angle(p1GJ));
  Double_t CosHel2 = cos(p0GJ.Angle(p1GJ));
  Double_t CosHel3 = p1GJ*p2GJ/(p1GJ.Mag()*p2GJ.Mag());
  out = (flag==1)? CosHel : (flag==2)? CosHel2 : CosHel3;
  return out;  
}


Double_t inclDstar_final::CosHelInvar(Double_t m1, Double_t m2, Double_t m3, 
				      Double_t m2_13, Double_t m2_12, Double_t m2_23, 
				      Int_t method) 
{
  assert(method>=0 && method<=4);
  Double_t out = -999;

  // Calculation of the energy of the particles in the 13 rest frame
  Double_t Energy0 = (mTotDalitzD0*mTotDalitzD0+m2_13-m2*m2)/(2*sqrt(m2_13));
  Double_t Energy1 = (m2_13-m3*m3+m1*m1)/(2*sqrt(m2_13));
  Double_t Energy2 = (mTotDalitzD0*mTotDalitzD0-m2_13-m2*m2)/(2*sqrt(m2_13));
  Double_t Energy3 = (m2_13+m3*m3-m1*m1)/(2*sqrt(m2_13));
  // 3-momenta calculation in 13 rest frame
  Double_t mag2P0 = Energy0*Energy0-mTotDalitzD0*mTotDalitzD0;
  Double_t mag2P1 = Energy1*Energy1-m1*m1;
  Double_t mag2P2 = Energy2*Energy2-m2*m2;
  Double_t mag2P3 = Energy3*Energy3-m3*m3;

  if(mag2P1<=0. || mag2P2<=0. || mag2P3<=0. || mag2P0<=0.){
    cout<<"WARNING: LOW MOMENTUM PARTICLE FOUND"<<endl;
    return -999;
  }
  //different (but equivalent) calculations for coshel
  Double_t CosHel_0 = ((mTotDalitzD0*mTotDalitzD0-m2_13-m2*m2)*(m2_13+m1*m1-m3*m3)+2*m2_13*(m1*m1+m2*m2-m2_12))/(sqrt(lKallen(m2_13,m1*m1,m3*m3))*sqrt(lKallen(mTotDalitzD0*mTotDalitzD0,m2_13,m2*m2)));
  Double_t CosHel_1 = (m1*m1+m2*m2+2*Energy1*Energy2-m2_12)/(2*sqrt(mag2P1*mag2P2));
  Double_t CosHel_2 = (m2_23-m2*m2-m3*m3-2*Energy2*Energy3)/(2*sqrt(mag2P3*mag2P2));
  Double_t CosHel_3 = (mTotDalitzD0*mTotDalitzD0+m3*m3-m2_12-2*Energy0*Energy3)/(2*sqrt(mag2P0*mag2P3));
  Double_t CosHel_4 = (m2_23-mTotDalitzD0*mTotDalitzD0-m1*m1+2*Energy0*Energy1)/(2*sqrt(mag2P0*mag2P1));

  //cout<<CosHel_0<<" "<<CosHel_1<<" "<<CosHel_2<<" "<<CosHel_3<<" "<<CosHel_4<<endl;
  //
  Double_t CosHel = (method==0)? CosHel_0 : (method==1)? CosHel_1 : (method==2)? CosHel_2 : (method==3)? CosHel_3 : CosHel_4;
  
  out = CosHel;

  return out;  
}


