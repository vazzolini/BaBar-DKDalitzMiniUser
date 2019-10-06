//#define vali2_cxx
//#include <TH2.h>
//#include <TStyle.h>
//#include <TCanvas.h>
//#include <TChain.h>
//#include <TFile.h>
//#include <iostream.h>   
//#include niceplot_cxx 

//void vali2()
{
  gROOT->ProcessLine(".x plots.C");
  gROOT->ProcessLine(".L niceplot.C");

 

  TCanvas* canvas1= new TCanvas("canvas1","canvas1",500,500);
  TCanvas* canvas2= new TCanvas("canvas2","canvas2",500,500);
  TCanvas* canvas3= new TCanvas("canvas3","canvas3",500,500);
  
  
  TH1F* hmes=new TH1F("mes","mES 24",60,5.200,5.300);
  TH1F* hDe=new TH1F("de","deltaE 24",60,-0.300,0.300);
  
  TH1F* hmesnew=new TH1F("mes18","mES 18",60,5.200,5.300);
  TH1F* hDenew=new TH1F("De18","deltaE 18",60,-0.300,0.300);
  
  TH1F* hDm=new TH1F("mes18-mes24","Dmes",60,-0.05,0.06);
   TH1F* hDDe=new TH1F("De18-De24","DDe",60,-0.06,0.06);
   
   
   //   TString sdec="final_valireduced_";
   // TString name2="ASCII/"+sdec+_dstar0mode+KorPi+"_"+_d0mode+"_"+_sig_type+"_Bbest_"+cut_code_str+"_"+release+".root";


 // TTree R24
  Int_t   runNumber;
  Int_t   upperID;
  Int_t   lowerID;
  Double_t demk;
  Double_t mes;
  
  TChain* tree= new TChain("treevali");
  TString filename="./vali1/ASCII/final_valireduced_d0pi0k_kspipi_on_Bbest_Cut1_rel-24.root";
  cout << "filename : " << filename << endl;
  tree->Add(filename);
   
  tree->SetBranchAddress("actualrunNumber",&runNumber);    
  tree->SetBranchAddress("actualupperID",&upperID);
  tree->SetBranchAddress("actuallowerID",&lowerID);
  tree->SetBranchAddress("actualdemk",&demk);
  tree->SetBranchAddress("actualmes",&mes);



  Int_t nentries=tree->GetEntries();  
  cout<<"nentries(24)= "<<nentries<<endl;

    // TTree R18
  Int_t   runNumbernew;
  Int_t   upperIDnew;
  Int_t   lowerIDnew;
  Double_t demknew;
  Double_t mesnew;
  



  TChain* treenew= new TChain("treevali");
  TString filenamenew="./vali1/ASCII/final_valireduced_d0pi0k_kspipi_on_Bbest_Cut1_rel-18new.root";
  cout << "filenamenew : " << filenamenew << endl;
  treenew->Add(filenamenew);
  
  treenew->SetBranchAddress("actualrunNumber",&runNumbernew);    
  treenew->SetBranchAddress("actualupperID",&upperIDnew);
  treenew->SetBranchAddress("actuallowerID",&lowerIDnew);
  treenew->SetBranchAddress("actualdemk",&demknew);
  treenew->SetBranchAddress("actualmes",&mesnew);
 


 
  Int_t nentriesnew=treenew->GetEntries();  
  cout<<"nentries(18)= "<<nentriesnew<<endl;

      
  for(Int_t i=0;i<nentries;i++){
  
    tree->GetEntry(i);
  
    for (Int_t j=0; j<nentriesnew;j++) {
      treenew->GetEntry(j); 
       
      if(runNumbernew==runNumber && lowerIDnew==lowerID && upperIDnew==upperID){ 
	//	cout<<"holaa"<<endl;
	hmesnew->Fill(mesnew);
	hDenew->Fill(demknew);
	hmes->Fill(mes);
	hDe->Fill(demk);
	
	hDm->Fill(mesnew-mes);
	hDDe->Fill(demknew-demk);
		 
		 
      } else continue;
    }
    
    
  }

  //  dibuja(hmes,hmesnew,130,"mes","L","mesdiffd0pi.gif") ;
  //  dibuja(hmes,hmesnew,45,"mes","L","mesdiffd0pi0pi.gif") ;
  // dibuja(hmes,hmesnew,35,"mes","L","mesdiffd0gampi.gif") ;
  //dibuja(hmes,hmesnew,15,"mes","L","mesdiffd0pi.gif") ;
  //  dibuja(hmes,hmesnew,6,"mes","L","mesdiffd0gamk.gif") ;
  dibuja(hmes,hmesnew,8,"mes","L","mesdiffd0pi0k.gif") ;
  canvas1->Divide(1,2);
  canvas1->cd(1);
  hmesnew->Draw();
  canvas1->cd(2);
  hmes->Draw();
  canvas1->Print("mesd0pi0k.gif");
  
  canvas2->Divide(1,2);
  canvas2->cd(1);
  hDenew->Draw();
  canvas2->cd(2);
  hDenew->Draw();
  canvas2->Print("ded0pi0k.gif");

//  mode = iourmen  (default = 0001111)
//    n = 1;  name of histogram is printed
//    e = 1;  number of entries printed
//    m = 1;  mean value printed
//    r = 1;  rms printed
//    u = 1;  number of underflows printed
//    o = 1;  number of overflows printed
//    i = 1;  integral of bins printed
//
  //  k :  kurtosis printed
//     K :  kurtosis and kurtosis error printed
//     s :  skewness printed
//     S :  skewness and skewness error printed
//     i :  integral of bins printed
//     o :  number of overflows printed
//     u :  number of underflows printed
//     r :  rms printed
//     R :  rms and rms error printed
//     m :  mean value printed
//     M :  mean value mean error values printed
//     e :  number of entries printed
//     n :  name of histogram is printed


  gROOT->SetStyle("Plain");
  gROOT->ForceStyle();
  gStyle->SetHistLineWidth(1);

  //  gStyle->SetOptStat(0111111);
  gStyle->SetOptStat("nemruo");
  gStyle->SetStatFontSize(0.1);
  gStyle->SetStatX(0.9); 
  //gStyle->SetStatY(0.9);
  gStyle->SetStatH(0.002);
  //  gStyle->SetStatW(0.01);
  canvas3->Divide(1,2);
  canvas3->cd(1);

  hDm->Draw();
  canvas3->cd(2);
  hDDe->Draw();
  canvas3->Print("diffd0pi0k.gif");
  
}


// gStyle->SetOptStat(1111111);
// // Set stat options
// gStyle->SetStatY(0.9);                
// // Set y-position (fraction of pad size)
// gStyle->SetStatX(0.9);                
// // Set x-position (fraction of pad size)
// gStyle->SetStatW(0.4);                
// // Set width of stat-box (fraction of pad size)
// gStyle->SetStatH(0.2);                
// // Set height of stat-box (fraction of pad size)

  
