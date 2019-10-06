#include "TCanvas.h"
#include "TStyle.h"
#include "TH1.h"
#include "TGaxis.h"
#include "TRandom.h"
#include "TLegend.h"
#include "TCut.h"
#include "TString.h"
#include "TChain.h"
#include "THStack.h"
#include <iostream.h>
#include "/home/users/bettarin/r1work/myc/isbatch.h"


void Cut_Optimize_make_sb(){

  TCanvas *c1 = new TCanvas("c1","Optimize Cut",1);

  //   Int_t num_evts = 1000;
  //
  //   Int_t num_evts = 10000;
  //   Int_t num_evtb = 1000;
  //   Int_t max_bins = 10;
  //   Double_t xmin=-5.0;
  //   Double_t xmax= 5.0;

  Int_t num_evts = 10000;
  Int_t num_evtb = 10000;
  Int_t max_bins = 11;
  Double_t xmin=-5.5;
  Double_t xmax= 5.5;

  gStyle->SetOptStat(kFALSE);
  gStyle->SetOptTitle(kFALSE);
  
  // create/fill draw sgn histo
  TH1F *hsgn = new TH1F("hsgn","SGN",max_bins,xmin,xmax);
  for (Int_t i=0;i<num_evts;i++) hsgn->Fill(gRandom->Gaus(0,2.0));
  hsgn->SetLineColor(kGreen);
  hsgn->Draw();
  c1->Update();  
  
  // create/fill draw bkg histo
  TH1F *hbkg = new TH1F("hbkg","BKG",max_bins,xmin,xmax);
  for (Int_t j=0;j<num_evtb;j++) hbkg->Fill(gRandom->Gaus(0,1.0));
  hbkg->SetLineColor(kRed);
  hbkg->Draw("same");
  c1->Update();  
  c1->SaveAs("sgnbkg.gif");
  c1->SaveAs("sgnbkg.eps");
}


void Cut_Optimize_signif_sb(TH1F *hsgn, TH1F *hbkg, 
			    const Int_t Accept, const Double_t x0, const Int_t part, const Int_t AccBetween, 
			    const char *filename, Double_t *SelInfo, Int_t swap=0,Int_t lox=0,Int_t loy=0)
{
  // Accept: -1 sx
  // Accept:  1 dx
  // Accept:  0 -> see x0   
  //                       part:  0 simmetric cut see AccBetween (1,0)
  //                       part: -1 sx            see AccBetween (1,0)
  //                       part:  1 dx            see AccBetween (1,0)
  // AccBetween:  1 accept events in the interval between (cut and x0)
  // AccBetween:  0 accept events in the interval outside (cut and x0)

  // swap:0 plot first sgn and then bkg

  //  SelInfo[0] = OptimumCut 
  //  SelInfo[1] = Significativity;
  //  SelInfo[2] = Efficiency;
  //  SelInfo[3] = Purity;
  //  SelInfo[4] = Efficiency on BKG;

   // Propagated (binomial) errors on effi = sqrt(n(1-epsilon)) / N
  
  SelInfo[0]=-1;
  SelInfo[1]=-1;
  SelInfo[2]=-1;
  SelInfo[3]=-1;
  SelInfo[4]=-1;

  TCanvas *c4 = new TCanvas("c4","Optimize Cut",1);
  c4->Divide(2,2);

  c4->cd(1);
  hsgn->SetLineColor(kGreen);
  if(lox==1) gPad->SetLogx(kTRUE);
  if(loy==1) gPad->SetLogy(kTRUE);
  hsgn->Draw();
  c4->cd(2);
  hbkg->SetLineColor(kRed);
  if(lox==1) gPad->SetLogx(kTRUE);
  if(loy==1) gPad->SetLogy(kTRUE);
  hbkg->Draw();
  c4->Update();  

  // create hsignif filled with the significativity = sgn/sqrt(sgn+bkg)  

  Int_t max_bins   = hsgn->GetNbinsX();
  Double_t xmin    = hsgn->GetXaxis()->GetXmin();
  Double_t xmax    = hsgn->GetXaxis()->GetXmax();

  Int_t max_bins1  = hbkg->GetNbinsX();
  Double_t xmin1   = hbkg->GetXaxis()->GetXmin();
  Double_t xmax1   = hbkg->GetXaxis()->GetXmax();

  if( (max_bins1 != max_bins) || (xmin1 !=xmin) || (xmax1 !=xmax) ){
    cout << "sgn and bkg histos are not alike" << endl ;
    assert(0);
  }

  TH1F *hsignif = new TH1F("hsignif","hsignif",max_bins,xmin,xmax);
  TH1F *heff    = new TH1F("heff"   ,"heff"   ,max_bins,xmin,xmax);
  TH1F *hpur    = new TH1F("hpur"   ,"hpur"   ,max_bins,xmin,xmax);

  Double_t sgntot = 0.0;
  Double_t bkgtot = 0.0;
  Double_t bin_w  = 999;
  Int_t bin_x0   = 0;
  Int_t bin_dx   = 0;
  Int_t bin_sx   = 0;
  Int_t max_simm_bins = 0;

  if ((Accept)==0) {
    bin_w  = (xmax-xmin)/max_bins;
    bin_x0 = hsgn->FindBin(x0);
    //  cout << "bin_x0=" << bin_x0 << endl;
    bin_dx = max_bins-bin_x0; 
    bin_sx = bin_x0-1; 
    max_simm_bins = (bin_dx>=bin_sx) ? bin_dx : bin_sx;
  }

  //  cout << "bin_x0=" << bin_x0 << endl;
  
  if (abs(Accept)==1||((Accept==0)&&(part==0))) {
      for (Int_t i=0;i<=(max_bins+1);++i) {
      sgntot += hsgn->GetBinContent(i); 
      bkgtot += hbkg->GetBinContent(i);
    }
  }
  else if ((Accept)==0 && (abs(part)==1)) {
    if (part==1) {
      for (Int_t i=bin_x0;i<=(max_bins+1);++i) {
	sgntot += hsgn->GetBinContent(i); 
	bkgtot += hbkg->GetBinContent(i);
      }
    }
    else if (part==-1) {
      for (Int_t i=(bin_x0-1);i>=0;--i) {
	sgntot += hsgn->GetBinContent(i); 
	bkgtot += hbkg->GetBinContent(i);
      }
    }
  }
  else {
    cout << "Error" << endl;
    assert(0);
  }

  cout << "sgntot=" << sgntot << endl;
  cout << "bkgtot=" << bkgtot << endl;

  Double_t sum_sgn = 0;
  Double_t sum_bkg = 0;
    
  if (Accept==-1) {
    for (Int_t i=0;i<=(max_bins+1);++i) {
      sum_sgn += hsgn->GetBinContent(i); 
      sum_bkg += hbkg->GetBinContent(i);
      Double_t sum = sum_sgn + sum_bkg;
      Double_t signif= 0.0;
      Double_t eff   = 0.0;
      Double_t pur   = 0.0;
      //      Double_t esignif= 0.0;
      Double_t eeff   = 0.0;
      //      Double_t epur   = 0.0;

      if (sum>0) {
	signif = sum_sgn/sqrt(sum); 
	//	esignif = sqrt( ( sum_sgn*(sum_bkg-0.5*sum_sgn)*(sum_bkg-0.5*sum_sgn) + 
	//			 0.25*(sum_sgn*sum_sgn*sum_bkg) )/(sum*sum*sum) ); 
	if (sgntot>0) {
	  eff = sum_sgn/sgntot;
	  eeff = sqrt(sum_sgn*(1-eff))/sgntot;
	}
	pur    = sum_sgn/sum;
	//	epur   = sqrt((sum_sgn*sum_bkg)/(sum*sum*sum));
      }

      hsignif->SetBinContent(i,signif);
      //      hsignif->SetBinError(i,esignif);
      heff->SetBinContent(i,eff);
      heff->SetBinError(i,eeff);
      hpur->SetBinContent(i,pur);
      //      hpur->SetBinError(i,epur);
    }
  }
  else if (Accept==1) {
    for (Int_t i=(max_bins+1);i>=0;--i) {
      sum_sgn += hsgn->GetBinContent(i); 
      sum_bkg += hbkg->GetBinContent(i);
      Double_t sum = sum_sgn + sum_bkg;
      Double_t signif= 0.0;
      Double_t eff   = 0.0;
      Double_t pur   = 0.0;
      //      Double_t esignif= 0.0;
      Double_t eeff   = 0.0;
      //      Double_t epur   = 0.0;

      if (sum>0) {
	signif = sum_sgn/sqrt(sum); 
	//	esignif = sqrt( ( sum_sgn*(sum_bkg-0.5*sum_sgn)*(sum_bkg-0.5*sum_sgn) + 
	//			  0.25*(sum_sgn*sum_sgn*sum_bkg) )/(sum*sum*sum) ); 

	if (sgntot>0) {
	  eff = sum_sgn/sgntot;
	  eeff = sqrt(sum_sgn*(1-eff))/sgntot;
	}
	pur    = sum_sgn/sum;
	//	epur   = sqrt((sum_sgn*sum_bkg)/(sum*sum*sum));
      }
      hsignif->SetBinContent(i,signif);
      //      hsignif->SetBinError(i,esignif);
      heff->SetBinContent(i,eff);
      heff->SetBinError(i,eeff);
      hpur->SetBinContent(i,pur);
      //      hpur->SetBinError(i,epur);
    }
  }
  //
  else if (Accept==0) {
    // see x0    
    if (part==1) {
      if (AccBetween==1) {
	for (Int_t i=bin_x0;i<=(max_bins+1);++i) {
	  sum_sgn += hsgn->GetBinContent(i); 
	  sum_bkg += hbkg->GetBinContent(i);
	  Double_t sum = sum_sgn + sum_bkg;
	  Double_t signif= 0.0;
	  Double_t eff   = 0.0;
	  Double_t pur   = 0.0;
	  //	  Double_t esignif= 0.0;
	  Double_t eeff   = 0.0;
	  //	  Double_t epur   = 0.0;

	  if (sum>0) {
	    signif = sum_sgn/sqrt(sum); 
	    //	    esignif = sqrt( ( sum_sgn*(sum_bkg-0.5*sum_sgn)*(sum_bkg-0.5*sum_sgn) + 
	    //			 0.25*(sum_sgn*sum_sgn*sum_bkg) )/(sum*sum*sum) ); 
	    if (sgntot>0) {
	      eff = sum_sgn/sgntot;
	      eeff = sqrt(sum_sgn*(1-eff))/sgntot;
	    }
	    pur    = sum_sgn/sum;
	    //	    epur   = sqrt((sum_sgn*sum_bkg)/(sum*sum*sum));
	  }
	  
	  hsignif->SetBinContent(i,signif);
	  //	  hsignif->SetBinError(i,esignif);
	  heff->SetBinContent(i,eff);
	  heff->SetBinError(i,eeff);
	  hpur->SetBinContent(i,pur);
	  //	  hpur->SetBinError(i,epur);
	}
      }
      else if (AccBetween==0) {      
	for (Int_t i=(max_bins+1);i>=bin_x0;--i) {
	  sum_sgn += hsgn->GetBinContent(i); 
	  sum_bkg += hbkg->GetBinContent(i);
	  Double_t sum = sum_sgn + sum_bkg;
	  Double_t signif= 0.0;
	  Double_t eff   = 0.0;
	  Double_t pur   = 0.0;
	  //	  Double_t esignif= 0.0;
	  Double_t eeff   = 0.0;
	  //	  Double_t epur   = 0.0;

	  if (sum>0) {
	    signif = sum_sgn/sqrt(sum); 
	    //	    esignif = sqrt( ( sum_sgn*(sum_bkg-0.5*sum_sgn)*(sum_bkg-0.5*sum_sgn) + 
	    //			 0.25*(sum_sgn*sum_sgn*sum_bkg) )/(sum*sum*sum) ); 

	    if (sgntot>0) {
	      eff = sum_sgn/sgntot;
	      eeff = sqrt(sum_sgn*(1-eff))/sgntot;
	    }
	    pur    = sum_sgn/sum;
	    //	    epur   = sqrt((sum_sgn*sum_bkg)/(sum*sum*sum));
	  }
	  
	  hsignif->SetBinContent(i,signif);
	  //	  hsignif->SetBinError(i,esignif);
	  heff->SetBinContent(i,eff);
	  heff->SetBinError(i,eeff);
	  hpur->SetBinContent(i,pur);
	  //	  hpur->SetBinError(i,epur);
	}

      }
      else {
	cout << "Error on AccBetween" << endl ; 
	assert(0);
      }
    }
    else if (part==-1) {
      if (AccBetween==1) {
	for (Int_t i=(bin_x0-1);i>=0;--i) {
	  sum_sgn += hsgn->GetBinContent(i); 
	  sum_bkg += hbkg->GetBinContent(i);
	  Double_t sum = sum_sgn + sum_bkg;
	  Double_t signif= 0.0;
	  Double_t eff   = 0.0;
	  Double_t pur   = 0.0;
	  //	  Double_t esignif= 0.0;
	  Double_t eeff   = 0.0;
	  //	  Double_t epur   = 0.0;

	  if (sum>0) {
	    signif = sum_sgn/sqrt(sum); 
	    //	    esignif = sqrt( ( sum_sgn*(sum_bkg-0.5*sum_sgn)*(sum_bkg-0.5*sum_sgn) + 
	    //			 0.25*(sum_sgn*sum_sgn*sum_bkg) )/(sum*sum*sum) ); 

	    if (sgntot>0) {
	      eff = sum_sgn/sgntot;
	      eeff = sqrt(sum_sgn*(1-eff))/sgntot;
	    }
	    pur    = sum_sgn/sum;
	    //	    epur   = sqrt((sum_sgn*sum_bkg)/(sum*sum*sum));
	  }
	  
	  hsignif->SetBinContent(i,signif);
	  //	  hsignif->SetBinError(i,esignif);
	  heff->SetBinContent(i,eff);
	  heff->SetBinError(i,eeff);
	  hpur->SetBinContent(i,pur);
	  //	  hpur->SetBinError(i,epur);
	}
      }
      else if (AccBetween==0) {      
	for (Int_t i=0;i<=bin_x0-1;++i) {
	  sum_sgn += hsgn->GetBinContent(i); 
	  sum_bkg += hbkg->GetBinContent(i);
	  Double_t sum = sum_sgn + sum_bkg;
	  Double_t signif= 0.0;
	  Double_t eff   = 0.0;
	  Double_t pur   = 0.0;
	  //	  Double_t esignif= 0.0;
	  Double_t eeff   = 0.0;
	  //	  Double_t epur   = 0.0;

	  if (sum>0) {
	    signif = sum_sgn/sqrt(sum); 
	    //	    esignif = sqrt( ( sum_sgn*(sum_bkg-0.5*sum_sgn)*(sum_bkg-0.5*sum_sgn) + 
	    //			 0.25*(sum_sgn*sum_sgn*sum_bkg) )/(sum*sum*sum) ); 

	    if (sgntot>0) {
	      eff = sum_sgn/sgntot;
	      eeff = sqrt(sum_sgn*(1-eff))/sgntot;
	    }
	    pur    = sum_sgn/sum;
	    //	    epur   = sqrt((sum_sgn*sum_bkg)/(sum*sum*sum));
	  }
	  
	  hsignif->SetBinContent(i,signif);
	  //	  hsignif->SetBinError(i,esignif);
	  heff->SetBinContent(i,eff);
	  heff->SetBinError(i,eeff);
	  hpur->SetBinContent(i,pur);
	  //	  hpur->SetBinError(i,epur);
	}
      }
      else {
	cout << "Error on AccBetween" << endl ; 
      }
    }
    else if (part==0) {
      if (AccBetween==1) {
	for (Int_t i=0;i<=(max_simm_bins+1);++i) {
	  if(i==0){
	    sum_sgn += hsgn->GetBinContent(bin_x0);
	    sum_bkg += hbkg->GetBinContent(bin_x0);
	  }
	  else{ 
	    sum_sgn += hsgn->GetBinContent(bin_x0+i); 
	    sum_sgn += hsgn->GetBinContent(bin_x0-i); 
	    sum_bkg += hbkg->GetBinContent(bin_x0+i);
	    sum_bkg += hbkg->GetBinContent(bin_x0-i);
	  }
	  Double_t sum = sum_sgn + sum_bkg;
	  Double_t signif= 0.0;
	  Double_t eff   = 0.0;
	  Double_t pur   = 0.0;
	  //	  Double_t esignif= 0.0;
	  Double_t eeff   = 0.0;
	  //	  Double_t epur   = 0.0;

	  if (sum>0) {
	    signif = sum_sgn/sqrt(sum); 
	    //	    esignif = sqrt( ( sum_sgn*(sum_bkg-0.5*sum_sgn)*(sum_bkg-0.5*sum_sgn) + 
	    //			 0.25*(sum_sgn*sum_sgn*sum_bkg) )/(sum*sum*sum) ); 

	    if (sgntot>0) {
	      eff = sum_sgn/sgntot;
	      eeff = sqrt(sum_sgn*(1-eff))/sgntot;
	    }
	    pur    = sum_sgn/sum;
	    //	    epur   = sqrt((sum_sgn*sum_bkg)/(sum*sum*sum));
	  }
	  
	  if (i==0) {
	    hsignif->SetBinContent(bin_x0,signif);
	    //	    hsignif->SetBinError(bin_x0,esignif);
	    heff->SetBinContent(bin_x0,eff);
	    heff->SetBinError(bin_x0,eeff);
	    hpur->SetBinContent(bin_x0,pur);
	    //	    hpur->SetBinError(bin_x0,epur);
	  }
	  else{
	    hsignif->SetBinContent(bin_x0+i,signif);
	    //	    hsignif->SetBinError(bin_x0+i,esignif);
	    heff->SetBinContent(bin_x0+i,eff);
	    heff->SetBinError(bin_x0+i,eeff);
	    hpur->SetBinContent(bin_x0+i,pur);
	    //	    hpur->SetBinError(bin_x0+i,epur);
	    hsignif->SetBinContent(bin_x0-i,signif);
	    //	    hsignif->SetBinError(bin_x0-i,esignif);
	    heff->SetBinContent(bin_x0-i,eff);
	    heff->SetBinError(bin_x0-i,eeff);
	    hpur->SetBinContent(bin_x0-i,pur);
	    //	    hpur->SetBinError(bin_x0-i,epur);
	  }
	}
      }
      else if (AccBetween==0) {
	for (Int_t i=0;i<=(max_simm_bins+1);++i) {
	  if(i==0){
	    sum_sgn += hsgn->GetBinContent(bin_x0);
	    sum_bkg += hbkg->GetBinContent(bin_x0);
	  }
	  else{ 
	    sum_sgn += hsgn->GetBinContent(bin_x0+i); 
	    sum_sgn += hsgn->GetBinContent(bin_x0-i); 
	    sum_bkg += hbkg->GetBinContent(bin_x0+i);
	    sum_bkg += hbkg->GetBinContent(bin_x0-i);
	  }
	  Double_t sum   = (sgntot + bkgtot)-(sum_sgn + sum_bkg);
	  Double_t signif= 0.0;
	  Double_t eff   = 0.0;
	  Double_t pur   = 0.0;
	  //	  Double_t esignif= 0.0;
	  Double_t eeff   = 0.0;
	  //	  Double_t epur   = 0.0;

	  if (sum>0) {
	    signif = (sgntot-sum_sgn)/sqrt(sum); 
	    //	    esignif = sqrt( ( (sgntot-sum_sgn)*((bkgtot-sum_bkg)-0.5*(sgntot-sum_sgn))*((bkgtot-sum_bkg)-0.5*(sgntot-sum_sgn)) + 
	    //			 0.25*((sgntot-sum_sgn)*(sgntot-sum_sgn)*(bkgtot-sum_bkg)) )/(sum*sum*sum) ); 

	    if (sgntot>0) {
	      eff = (sgntot-sum_sgn)/sgntot;
	      eeff = sqrt(sum_sgn*(1-eff))/sgntot;
	    }
	    pur    = (sgntot-sum_sgn)/sum;
	    //	    epur   = sqrt(((sgntot-sum_sgn)*(bkgtot-sum_bkg))/(sum*sum*sum));
	  }
	  
	  if (i==0) {
	    hsignif->SetBinContent(bin_x0,signif);
	    //	    hsignif->SetBinError(bin_x0,esignif);
	    heff->SetBinContent(bin_x0,eff);
	    heff->SetBinError(bin_x0,eeff);
	    hpur->SetBinContent(bin_x0,pur);
	    //	    hpur->SetBinError(bin_x0,epur);
	  }
	  else{
	    hsignif->SetBinContent(bin_x0+i,signif);
	    //	    hsignif->SetBinError(bin_x0+i,esignif);
	    heff->SetBinContent(bin_x0+i,eff);
	    heff->SetBinError(bin_x0+i,eeff);
	    hpur->SetBinContent(bin_x0+i,pur);
	    //	    hpur->SetBinError(bin_x0+i,epur);
	    hsignif->SetBinContent(bin_x0-i,signif);
	    //	    hsignif->SetBinError(bin_x0-i,esignif);
	    heff->SetBinContent(bin_x0-i,eff);
	    heff->SetBinError(bin_x0-i,eeff);
	    hpur->SetBinContent(bin_x0-i,pur);
	    //	    hpur->SetBinError(bin_x0-i,epur);
	  }
	}
      }
      else {
	cout << "Error on AccBetween" << endl ; 
	assert(0);
      }
    }
  }
  
  //hsignif ->scale to adapt to the pad coordinates
  Int_t binmax =0;
  Double_t xcut=0;
  binmax  = hsignif->GetMaximumBin();
  //
  //casi

  if (Accept==-1) {
    xcut    = hsignif->GetBinLowEdge(binmax+1);  
  }
  else if (Accept==+1) {
    xcut    = hsignif->GetBinLowEdge(binmax);  
  }
  else if (Accept==0) {
    if (part==-1) {
      xcut    = hsignif->GetBinLowEdge(binmax+1);  
    }
    else if (part==+1) {
    xcut    = hsignif->GetBinLowEdge(binmax);  
    }
    else if (part==0){
      if (AccBetween==1){
	if(binmax<bin_x0){
	  Double_t xc   = hsignif->GetBinLowEdge(binmax);  
	  Double_t xl0  = hsignif->GetBinLowEdge(bin_x0);
	  Double_t xh0  = hsignif->GetBinLowEdge(bin_x0+1);
	  xcut = xl0-xc+xh0;
	}
	else if(binmax>bin_x0){
	  xcut    = hsignif->GetBinLowEdge(binmax+1);  
	}
	else if(binmax==bin_x0){
	  xcut    = hsignif->GetBinLowEdge(binmax+1);  
	}
      } 
      else if (AccBetween==0){
	if(binmax<bin_x0){
	  Double_t xc   = hsignif->GetBinLowEdge(binmax+1);  
	  Double_t xl0  = hsignif->GetBinLowEdge(bin_x0);
	  Double_t xh0  = hsignif->GetBinLowEdge(bin_x0+1);
	  xcut = xl0-xc+xh0;
	}
	else if(binmax>bin_x0){
	  xcut    = hsignif->GetBinLowEdge(binmax);  
	}
	else if(binmax==bin_x0){
	  xcut    = hsignif->GetBinLowEdge(binmax+1);  	  
	}
      } 
    }
  }
  else{
    assert(0);
  }

  Double_t OptimumCut      = xcut;
  Double_t Significativity = hsignif->GetBinContent(binmax);
  Double_t Efficiency      = heff->GetBinContent(binmax);
  Double_t Purity          = hpur->GetBinContent(binmax);
  Double_t BKG_Efficiency  = sgntot*Efficiency*(1.0/Purity-1.0)/bkgtot;

  cout << "OptimumCut      = " << OptimumCut << endl;
  cout << "Significativity = " << Significativity << endl;
  cout << "Efficiency      = " << Efficiency << endl;
  cout << "Purity          = " << Purity << endl;
  cout << "BKG_Efficiency  = " << BKG_Efficiency << endl;

  SelInfo[0] = OptimumCut;
  SelInfo[1] = Significativity;
  SelInfo[2] = Efficiency;
  SelInfo[3] = Purity;
  SelInfo[4] = BKG_Efficiency;

  c4->cd(3);
  gStyle->SetOptTitle(kFALSE);
  hsgn->SetStats(kFALSE);
  hbkg->SetStats(kFALSE);

  hbkg->SetLineColor(kRed);
  hsgn->SetLineColor(kGreen);

  if (swap==1) {
    if(lox==1) gPad->SetLogx(kTRUE);
    if(loy==1) gPad->SetLogy(kTRUE);
    hbkg->DrawNormalized();  
    hsgn->DrawNormalized("same");
  }
  else {
    if(lox==1) gPad->SetLogx(kTRUE);
    if(loy==1) gPad->SetLogy(kTRUE);
    hsgn->DrawNormalized();
    hbkg->DrawNormalized("same");  
  }

  c4->Update(); 
  Double_t symax     = hsignif->GetMaximum();
  Double_t srightmax = 1.2*symax;
  Double_t sscale    = gPad->GetUymax()/srightmax;

  hsignif->SetLineColor(kBlue);
  hsignif->Scale(sscale);
  
  if(lox==1) gPad->SetLogx(kTRUE);
  if(loy==1) gPad->SetLogy(kTRUE);
  hsignif->Draw("same");
  
  //draw an axis on the right side
  if (loy!=1) {
    TGaxis *axis = new TGaxis(gPad->GetUxmax(),gPad->GetUymin(),
			      gPad->GetUxmax(),gPad->GetUymax(),
			      0,srightmax,20,"+L");
  }
  else {
    TGaxis *axis = new TGaxis(gPad->GetUxmax(),gPad->GetUymin(),
			      gPad->GetUxmax(),gPad->GetUymax(),
			      0,srightmax,20,"+G");
    //NB no log from 0
  }
  axis->SetLineColor(kBlue);
  axis->SetLabelColor(kBlue);
  axis->Draw();
  c4->Update();  
  
  // Legend
  TLegend *leg_hist = new TLegend(0.1,0.85,0.3,0.99);
  //  leg_hist->SetHeader(" Set Cut: ");
  leg_hist->AddEntry(hsgn,"S","l");
  leg_hist->AddEntry(hbkg,"B","l");
  leg_hist->AddEntry(hsignif,"S/#sqrt{S+B}","l");
  leg_hist->Draw();

  c4->cd(4);
  heff->SetStats(kFALSE);
  if(lox==1) gPad->SetLogx(kTRUE);
  if(loy==1) gPad->SetLogy(kTRUE);
  heff->Draw();
  //scale hpur to the pad coordinates
  Double_t pymax     = hpur->GetMaximum();
  Double_t prightmax = 1.2*pymax;
  Double_t pscale    = gPad->GetUymax()/prightmax;
  hpur->SetLineColor(kBlue);
  hpur->Scale(pscale);
  if(lox==1) gPad->SetLogx(kTRUE);
  if(loy==1) gPad->SetLogy(kTRUE);
  hpur->Draw("same");
  
  c4->Update();  

  //draw an axis on the right side
  if (loy!=1) {
  TGaxis *paxis = new TGaxis(gPad->GetUxmax(),gPad->GetUymin(),
                             gPad->GetUxmax(),gPad->GetUymax(),
                             0,prightmax,20,"+L");
  }
  else {
  TGaxis *paxis = new TGaxis(gPad->GetUxmax(),gPad->GetUymin(),
                             gPad->GetUxmax(),gPad->GetUymax(),
                             0,prightmax,20,"+G");
    //NB no log from 0
  }

  paxis->SetLineColor(kBlue);
  paxis->SetLabelColor(kBlue);
  paxis->Draw();
  c4->Update();  
  
  // Legend
  TLegend *pleg_hist = new TLegend(0.1,0.85,0.3,0.99);
  //  pleg_hist->SetHeader("Set Cut:");
  pleg_hist->AddEntry(heff,"Efficiency","l");
  pleg_hist->AddEntry(hpur,"#frac{S}{S+B}","l");
  pleg_hist->Draw();

  TString myf=filename;

  TString giff=myf+".gif";
  TString epsf=myf+".eps";

  c4->SaveAs(giff);
  c4->SaveAs(epsf);
  if (!BATCH)  c4->WaitPrimitive();

  delete c4;
  delete hsignif;
  delete heff;
  delete hpur;
  delete axis;
  delete leg_hist;
  delete paxis;
  delete pleg_hist;

}


void Cut_Optimize_on_MC (TString variable,
			 TCut CurCUT,
			 TCut MatchOnSgn,
			 const Int_t nbins,
			 const Double_t xmin, const Double_t xmax,
			 TChain *MyChains[], Double_t * Norm, 
			 const Int_t Accept, const Double_t x0, const Int_t part, const Int_t AccBetween,
			 TString filcut, Double_t * Info,Int_t swap=0,Int_t lox=0,Int_t loy=0)
{
  TString what[6];
  what[0]="sgn";
  what[1]="Bch";
  what[2]="B0";
  what[3]="uds";
  what[4]="c";
  what[5]="bkg";

  TString histos[6];

  for(Int_t i=0;i<6;++i) histos[i]=what[i];

  for(Int_t i=0;i<6;++i) cout << histos[i] << endl;
  for(Int_t i=0;i<6;++i) cout << Norm[i] << endl;

  TH1F *h_sgn    = new TH1F(histos[0],what[0],nbins,xmin,xmax);
  TH1F *h_Bch    = new TH1F(histos[1],what[1],nbins,xmin,xmax);
  TH1F *h_B0     = new TH1F(histos[2],what[2],nbins,xmin,xmax);
  TH1F *h_uds    = new TH1F(histos[3],what[3],nbins,xmin,xmax);
  TH1F *h_c      = new TH1F(histos[4],what[4],nbins,xmin,xmax);
  TH1F *h_bkg    = new TH1F(histos[5],what[5],nbins,xmin,xmax);
  //

  TCanvas *c1 = new TCanvas(variable,variable,1);
  c1->Divide(2,3);

  c1->cd(1);
  
  TString argum[6]; 
  for(Int_t i=0;i<6;++i) {
    argum[i] = variable + ">>" + histos[i];
  }

  //  gStyle->SetOptTitle(kTRUE);

  cout << argum[0] << endl;
  MyChains[0]->Draw(argum[0], CurCUT && MatchOnSgn );
  Double_t Normsgn = Norm[0];
  h_sgn->Scale(Normsgn);
  if(lox==1) gPad->SetLogx(kTRUE);
  if(loy==1) gPad->SetLogy(kTRUE);
  gStyle->SetOptStat(kFALSE);
  //  h_sgn->SetTitleSize(0.8);
  h_sgn->Draw();

  c1->cd(2);
  cout << argum[1] << endl;
  MyChains[1]->Draw(argum[1], CurCUT);
  Double_t NormBch = Norm[1];
  h_Bch->Scale(NormBch);
  if(lox==1) gPad->SetLogx(kTRUE);
  if(loy==1) gPad->SetLogy(kTRUE);
  gStyle->SetOptStat(kFALSE);
  //  h_Bch->SetTitleSize(0.08);
  h_Bch->Draw();

  c1->cd(3);
  cout << argum[2] << endl;
  MyChains[2]->Draw(argum[2], CurCUT);
  Double_t NormB0 = Norm[2];
  h_B0->Scale(NormB0);
  if(lox==1) gPad->SetLogx(kTRUE);
  if(loy==1) gPad->SetLogy(kTRUE);
  gStyle->SetOptStat(kFALSE);
  //  h_B0->SetTitleSize(0.08);
  h_B0->Draw();

  c1->cd(4);
  cout << argum[3] << endl;
  MyChains[3]->Draw(argum[3], CurCUT);
  Double_t Normuds = Norm[3];
  h_uds->Scale(Normuds);
  if(lox==1) gPad->SetLogx(kTRUE);
  if(loy==1) gPad->SetLogy(kTRUE);
  gStyle->SetOptStat(kFALSE);
  //  h_uds->SetTitleSize(0.08);
  h_uds->Draw();

  c1->cd(5);
  cout << argum[4] << endl;
  MyChains[4]->Draw(argum[4], CurCUT);
  Double_t Normc = Norm[4];
  h_c->Scale(Normc);
  if(lox==1) gPad->SetLogx(kTRUE);
  if(loy==1) gPad->SetLogy(kTRUE);
  gStyle->SetOptStat(kFALSE);
  //  h_c->SetTitleSize(0.08);
  h_c->Draw();
  
  c1->cd(6);
  h_bkg->Add(h_Bch);
  h_bkg->Add(h_B0);
  h_bkg->Add(h_uds);
  h_bkg->Add(h_c);
  if(lox==1) gPad->SetLogx(kTRUE);
  if(loy==1) gPad->SetLogy(kTRUE);
  gStyle->SetOptStat(kFALSE);
  //  h_bkg->SetTitleSize(0.04);
  h_bkg->Draw();
  
  c1->Update();
  TString filegif = variable+".gif";
  TString fileps  = variable+".eps";
  c1->SaveAs(filegif);
  c1->SaveAs(fileps);
  if (!BATCH)  c1->WaitPrimitive();

  Cut_Optimize_signif_sb(h_sgn,h_bkg,Accept,x0,part,AccBetween,filcut,Info,swap,lox,loy);
  for (Int_t i=0; i<=4 ;i++){ cout << Info[i] << endl;}

  delete c1;
  delete h_sgn;
  delete h_Bch;
  delete h_B0; 
  delete h_uds;
  delete h_c;  
  delete h_bkg;

}

void See_signif_sb(TH1F *hsgn, TH1F *hbkg, Int_t sgntot,  Int_t bkgtot,  
			    const char *filename, Double_t *SelInfo, Int_t swap=0, Int_t lox=0,Int_t loy=0)
{

  // sgntot: # sgn evts before cut 
  // bkgtot: # bkg evts before cut 

  // swap:0 plot first sgn and then bkg

  //  SelInfo[0] = OptimumCut 
  //  SelInfo[1] = Significativity;
  //  SelInfo[2] = Efficiency;
  //  SelInfo[3] = Purity;
  //  SelInfo[4] = Efficiency on BKG;

  // Propagated (binomial) errors on effi = sqrt(n(1-epsilon)) / N
  
  SelInfo[0]=-1;
  SelInfo[1]=-1;
  SelInfo[2]=-1;
  SelInfo[3]=-1;
  SelInfo[4]=-1;

  TCanvas *c1 = new TCanvas("c1","Optimize Cut",1);
  c1->Divide(2,2);

  c1->cd(1);
  hsgn->SetLineColor(kGreen);
  if(lox==1) gPad->SetLogx(kTRUE);
  if(loy==1) gPad->SetLogy(kTRUE);
  hsgn->Draw();
  c1->cd(2);
  hbkg->SetLineColor(kRed);
  if(lox==1) gPad->SetLogx(kTRUE);
  if(loy==1) gPad->SetLogy(kTRUE);
  hbkg->Draw();
  c1->Update();  

  // create hsignif filled with the significativity = sgn/sqrt(sgn+bkg)  
  Int_t max_bins  = hsgn->GetNbinsX();
  Double_t xmin    = hsgn->GetXaxis()->GetXmin();
  Double_t xmax    = hsgn->GetXaxis()->GetXmax();

  Int_t max_bins1 = hbkg->GetNbinsX();
  Double_t xmin1   = hbkg->GetXaxis()->GetXmin();
  Double_t xmax1   = hbkg->GetXaxis()->GetXmax();

  if( (max_bins1 != max_bins) || (xmin1 !=xmin) || (xmax1 !=xmax) ){
    cout << "sgn and bkg histos are not alike" << endl ;
  }

  TH1F *hsignif = new TH1F("hsignif","hsignif",max_bins,xmin,xmax);
  TH1F *heff    = new TH1F("heff"   ,"heff"   ,max_bins,xmin,xmax);
  TH1F *hpur    = new TH1F("hpur"   ,"hpur"   ,max_bins,xmin,xmax);

  for (Int_t i=0;i<=(max_bins+1);++i) {

    Double_t sum_sgn;
    Double_t sum_bkg;
    sum_sgn = hsgn->GetBinContent(i); 
    sum_bkg = hbkg->GetBinContent(i);

    Double_t sum    = sum_sgn + sum_bkg;
    Double_t signif = 0.0;
    Double_t eff    = 0.0;
    Double_t pur    = 0.0;
    //    Double_t esignif= 0.0;
    Double_t eeff   = 0.0;
    //    Double_t epur   = 0.0;
    
    if (sum>0) {
      signif = sum_sgn/sqrt(sum); 
      //      esignif = sqrt( ( sum_sgn*(sum_bkg-0.5*sum_sgn)*(sum_bkg-0.5*sum_sgn) + 
      //			0.25*(sum_sgn*sum_sgn*sum_bkg) )/(sum*sum*sum) ); 
      if (sgntot>0) {
	if (sgntot>0) eff = sum_sgn/sgntot;
	eeff = sqrt(sum_sgn*(1-eff))/sgntot;
      }
      pur    = sum_sgn/sum;
      //      epur   = sqrt((sum_sgn*sum_bkg)/(sum*sum*sum));
    }
    
    hsignif->SetBinContent(i,signif);
    //    hsignif->SetBinError(i,esignif);
    heff->SetBinContent(i,eff);
    heff->SetBinError(i,eeff);
    hpur->SetBinContent(i,pur);
    //    hpur->SetBinError(i,epur);
  }


  //scale hsignif to the pad coordinates

  Int_t binmax=0;

  binmax  = hsignif->GetMaximumBin();
  
  Int_t OptimumBin        = binmax;
  Double_t Significativity = hsignif->GetBinContent(binmax);
  Double_t Efficiency      =0;
  if (sgntot>0) Efficiency = heff->GetBinContent(binmax);
  Double_t Purity = hpur->GetBinContent(binmax);
  Double_t BKG_Efficiency  =0;
  if (bkgtot>0) BKG_Efficiency  = sgntot*Efficiency*(1.0/Purity-1.0)/bkgtot;

  cout << "OptimumBin      = " << OptimumBin << endl;
  cout << "Significativity = " << Significativity << endl;
  if (sgntot>0)  cout << "Efficiency      = " << Efficiency << endl;
  cout << "Purity          = " << Purity << endl;
  if (bkgtot>0)  cout << "BKG_Efficiency  = " << BKG_Efficiency << endl;

  SelInfo[0] = OptimumBin;
  SelInfo[1] = Significativity;
  SelInfo[2] = Efficiency;
  SelInfo[3] = Purity;
  SelInfo[4] = BKG_Efficiency;

  c1->cd(3);
  gStyle->SetOptTitle(kFALSE);
  hsgn->SetStats(kFALSE);
  hbkg->SetStats(kFALSE);

  if (swap==1) {
    hbkg->SetLineColor(kRed);
    if(lox==1) gPad->SetLogx(kTRUE);
    if(loy==1) gPad->SetLogy(kTRUE);
    hbkg->Draw();  
    hsgn->SetLineColor(kGreen);
    hsgn->Draw("same");
  }
  else {
    hsgn->SetLineColor(kGreen);
    if(lox==1) gPad->SetLogx(kTRUE);
    if(loy==1) gPad->SetLogy(kTRUE);
    hsgn->Draw();
    hbkg->SetLineColor(kRed);
    hbkg->Draw("same");  
  }

  c1->Update(); 
  Double_t symax    = hsignif->GetMaximum();
  Double_t srightmax = 1.2*symax;
  Double_t sscale    = gPad->GetUymax()/srightmax;
  hsignif->SetLineColor(kBlue);
  hsignif->Scale(sscale);
  if(lox==1) gPad->SetLogx(kTRUE);
  if(loy==1) gPad->SetLogy(kTRUE);
  hsignif->Draw("same");
  
  //draw an axis on the right side
  if (loy!=1) {
    TGaxis *axis = new TGaxis(gPad->GetUxmax(),gPad->GetUymin(),
			      gPad->GetUxmax(),gPad->GetUymax(),
			      0,srightmax,20,"+L");
  }
  else {
    TGaxis *axis = new TGaxis(gPad->GetUxmax(),gPad->GetUymin(),
			      gPad->GetUxmax(),gPad->GetUymax(),
			      0,srightmax,20,"+G");
    
    //NB no log from 0
  }
  
  axis->SetLineColor(kBlue);
  axis->SetLabelColor(kBlue);
  axis->Draw();
  c1->Update();  
  
  // Legend
  TLegend *leg_hist = new TLegend(0.1,0.85,0.3,0.99);
  //  leg_hist->SetHeader(" Set Cut: ");
  leg_hist->AddEntry(hsgn,"S","l");
  leg_hist->AddEntry(hbkg,"B","l");
  leg_hist->AddEntry(hsignif,"S/#sqrt{S+B}","l");
  leg_hist->Draw();

  c1->cd(4);
  heff->SetStats(kFALSE);
  if(lox==1) gPad->SetLogx(kTRUE);
  if(loy==1) gPad->SetLogy(kTRUE);
  heff->Draw();
  //scale hpur to the pad coordinates
  Double_t pymax     = hpur->GetMaximum();
  Double_t prightmax = 1.2*pymax;
  Double_t pscale    = gPad->GetUymax()/prightmax;
  hpur->SetLineColor(kBlue);
  hpur->Scale(pscale);
  if(lox==1) gPad->SetLogx(kTRUE);
  if(loy==1) gPad->SetLogy(kTRUE);
  hpur->Draw("same");
  c1->Update();  
  
//draw an axis on the right side
  if (loy!=1) {
  TGaxis *paxis = new TGaxis(gPad->GetUxmax(),gPad->GetUymin(),
                             gPad->GetUxmax(),gPad->GetUymax(),
                             0,prightmax,20,"+L");
  }
  else {
  TGaxis *paxis = new TGaxis(gPad->GetUxmax(),gPad->GetUymin(),
                             gPad->GetUxmax(),gPad->GetUymax(),
                             0,prightmax,20,"+G");
    //NB no log from 0
  }

  paxis->SetLineColor(kBlue);
  paxis->SetLabelColor(kBlue);
  paxis->Draw();
  c1->Update();  
  
  // Legend
  TLegend *pleg_hist = new TLegend(0.1,0.85,0.3,0.99);
  //  pleg_hist->SetHeader("Set Cut:");
  pleg_hist->AddEntry(heff,"Efficiency","l");
  pleg_hist->AddEntry(hpur,"#frac{S}{S+B}","l");
  pleg_hist->Draw();

  /* Dump
  cout << "heff->GetBinContent(0) " << heff->GetBinContent(0)<<endl ;
  cout << "heff->GetBinContent(10)" << heff->GetBinContent(10)<<endl;
  cout << "hsgn->GetBinContent(0) " << hsgn->GetBinContent(0)<<endl;
  cout << "hsgn->GetBinContent(10)" << hsgn->GetBinContent(10)<<endl;
  cout << "hbkg->GetBinContent(0) " << hbkg->GetBinContent(0)<<endl;
  cout << "hbkg->GetBinContent(10)" << hbkg->GetBinContent(10)<<endl;
  */

  TString myf(filename);
  TString filegif = myf+".gif";
  TString fileps  = myf+".eps";
  c1->SaveAs(filegif);
  c1->SaveAs(fileps);

  if (!BATCH)  c1->WaitPrimitive();

  delete c1;
  delete hsignif;
  delete heff;
  delete hpur;
  delete axis;
  delete leg_hist;
  delete paxis;
  delete pleg_hist;
}

void See_Optimize_on_MC(TString variable,
			TCut CurCUT,
			TCut MatchOnSgn,
			const Int_t nbins,
			const Double_t xmin, const Double_t xmax,
			TChain *MyChains[], Double_t * Norm,Int_t lox=0,Int_t loy=0, Int_t withdata=1)
{
  TString what[8];

  what[0]="sgn";
  what[1]="Bch";
  what[2]="B0";
  what[3]="uds";
  what[4]="c";
  what[5]="bkg";
  what[6]="Tot";
  what[7]="Data";

  TString histos[8];

  for(Int_t i=0;i<8;++i) histos[i]=what[i];

  TH1F *h_sgn    = new TH1F(histos[0],what[0],nbins,xmin,xmax);
  TH1F *h_Bch    = new TH1F(histos[1],what[1],nbins,xmin,xmax);
  TH1F *h_B0     = new TH1F(histos[2],what[2],nbins,xmin,xmax);
  TH1F *h_uds    = new TH1F(histos[3],what[3],nbins,xmin,xmax);
  TH1F *h_c      = new TH1F(histos[4],what[4],nbins,xmin,xmax);
  TH1F *h_bkg    = new TH1F(histos[5],what[5],nbins,xmin,xmax);
  TH1F *h_tot    = new TH1F(histos[6],what[6],nbins,xmin,xmax);
  TH1F *h_Data   = new TH1F(histos[7],what[7],nbins,xmin,xmax);

  //
  THStack *hs = new THStack("hs","Events");
  //
  TCanvas *c10 = new TCanvas(variable,variable,1);
  c10->Divide(2,3);

  TString argum[8]; 
  for(Int_t i=0;i<8;++i) {
    argum[i] = variable + ">>";
    argum[i] += histos[i];
  }

  gStyle->SetOptStat(kFALSE);
  //  gStyle->SetOptTitle(kFALSE);

  c10->cd(1);
  cout << argum[0] << endl;
  MyChains[0]->Draw(argum[0], CurCUT && MatchOnSgn );
  Double_t Normsgn = Norm[0];
  h_sgn->Scale(Normsgn);
  if(lox==1) gPad->SetLogx(kTRUE);
  if(loy==1) gPad->SetLogy(kTRUE);
  h_sgn->SetFillColor(kGreen);
  h_sgn->SetLineColor(kGreen);
  h_sgn->Draw();

  c10->cd(2);
  cout << argum[1] << endl;
  MyChains[1]->Draw(argum[1], CurCUT);
  Double_t NormBch = Norm[1];
  h_Bch->Scale(NormBch);
  if(lox==1) gPad->SetLogx(kTRUE);
  if(loy==1) gPad->SetLogy(kTRUE);
  h_Bch->SetFillColor(4);
  h_Bch->SetLineColor(4);
  h_Bch->Draw();

  c10->cd(3);
  cout << argum[2] << endl;
  MyChains[2]->Draw(argum[2], CurCUT);
  Double_t NormB0 = Norm[2];
  h_B0->Scale(NormB0);
  if(lox==1)  gPad->SetLogx(kTRUE);
  if(loy==1)  gPad->SetLogy(kTRUE);
  h_B0->SetFillColor(5);
  h_B0->SetLineColor(5);
  h_B0->Draw();

  c10->cd(4);
  cout << argum[3] << endl;
  MyChains[3]->Draw(argum[3], CurCUT);
  Double_t Normuds = Norm[3];
  h_uds->Scale(Normuds);
  if(lox==1)  gPad->SetLogx(kTRUE);
  if(loy==1) gPad->SetLogy(kTRUE);
  h_uds->SetFillColor(6);
  h_uds->SetLineColor(6);
  h_uds->Draw();

  c10->cd(5);
  cout << argum[4] << endl;
  MyChains[4]->Draw(argum[4], CurCUT);
  Double_t Normc = Norm[4];
  h_c->Scale(Normc);
  if(lox==1) gPad->SetLogx(kTRUE);
  if(loy==1) gPad->SetLogy(kTRUE);
  h_c->SetFillColor(7);
  h_c->SetLineColor(7);
  h_c->Draw();

  if(withdata==1) {
    cout << argum[7] << endl;
    MyChains[5]->Draw(argum[7], CurCUT);
    if(lox==1) gPad->SetLogx(kTRUE);
    if(loy==1) gPad->SetLogy(kTRUE);
    h_Data->Draw();
  }

  c10->cd(6);
  h_bkg->Add(h_Bch);
  h_bkg->Add(h_B0);
  h_bkg->Add(h_uds);
  h_bkg->Add(h_c);
  Double_t Normbkg = 1.0;
  h_bkg->Scale(Normbkg);
  if(lox==1)  gPad->SetLogx(kTRUE);
  if(loy==1)  gPad->SetLogy(kTRUE);
  h_bkg->Draw();

  Double_t SGN= h_sgn->Integral();
  cout << "SGN=" << SGN << endl;
  Double_t BKG= h_bkg->Integral();
  cout << "BKG=" << BKG << endl;

  c10->Update();
  TString filegif10 = variable+"_stack_comp.gif";
  TString fileps10  = variable+"_stack_comp.eps";
  c10->SaveAs(filegif10);
  c10->SaveAs(fileps10);

  if (!BATCH)  c10->WaitPrimitive();

  TCanvas *c20 = new TCanvas("stack","stack",1);

  hs->Add(h_uds);
  hs->Add(h_c);
  hs->Add(h_B0);
  hs->Add(h_Bch);
  hs->Add(h_sgn);
  if(lox==1)  gPad->SetLogx(kTRUE);
  if(loy==1)  gPad->SetLogy(kTRUE);
  
  gStyle->SetOptTitle(kFALSE);
  gStyle->SetOptStat(kFALSE);
  
  if(withdata==0) {
    hs->Draw();
  }
  else if(withdata==1) {
    Double_t Datamax = h_Data->GetMaximum();
    Double_t MCmax   = hs->GetMaximum();
    Double_t MAX =(Datamax>=MCmax) ? Datamax : MCmax;

    hs->SetMaximum(MAX*1.2);

    hs->Draw();
    h_Data->SetMarkerSize(1);
    h_Data->SetMarkerStyle(8);
    h_Data->Draw("Esame");
  }
  
  //---disegna legenda
  TLegend *leg=new TLegend(0.15,0.60,0.40,0.85);
  leg->SetBorderSize(0);
  leg->SetTextFont(132);
  leg->SetHeader("Legenda:");
  leg->SetFillColor(10);// Per avere il bianco si mette 10.
  
  leg->AddEntry(h_uds,"uds","f");
  leg->AddEntry(h_c,"c#bar{c}","f");
  leg->AddEntry(h_B0,"B^{0}#bar{B^{0}}","f");
  leg->AddEntry(h_Bch,"B^{+}B^{-}","f");
  leg->AddEntry(h_sgn,"SGN","f");
  if(withdata==1) leg->AddEntry(h_Data,"Data","P");
  leg->Draw();
  
  c20->Update();
  TString filegif = variable+"_stack.gif";
  TString fileps  = variable+"_stack.eps";

  c20->SaveAs(filegif);
  c20->SaveAs(fileps);
  
  if (!BATCH)  c20->WaitPrimitive();

  h_tot->Add(h_uds);
  h_tot->Add(h_c);
  h_tot->Add(h_B0);
  h_tot->Add(h_Bch);
  h_tot->Add(h_sgn);

  // Don't delete histos, I want them

  delete c10;
  delete c20;
  //  delete h_sgn;
  //  delete h_Bch;
  //  delete h_B0; 
  //  delete h_uds;
  //  delete h_c;  
  //  delete h_bkg;
  //  delete h_tot;
  delete hs;
  delete leg;
}

void Cut_Optimize_debug()
{
  Cut_Optimize_make_sb();

  Double_t Info[5];

  Int_t Accept= 0;
  Double_t x0  = 0.0;
  Int_t part  = 0; 
  //  Int_t AccBetween= 1;
  Int_t AccBetween= 0;

  // Int_t Accept= 1;
  // Int_t Accept= -1;

  TString filcut = "provacut";

  TH1F *hns=(TH1F*)gDirectory->Get("hsgn");
  TH1F *hnb=(TH1F*)gDirectory->Get("hbkg");

  Cut_Optimize_signif_sb(hns, hnb, Accept, x0, part, AccBetween, filcut, Info);

			 
}
