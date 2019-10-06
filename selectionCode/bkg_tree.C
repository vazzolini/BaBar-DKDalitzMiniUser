#define bkg_tree_cxx
#include "bkg_tree.h"
#include "TH2.h"
#include "TStyle.h"
#include "TCanvas.h"
#include <iomanip.h>
#include <fstream.h>
#include <strstream.h>



///RUNNING COMMAND
//.L bkg_tree.C+
// bkg_tree c("chb","kspipi")
// c.Loop("kspi")
//
//.L bkg_tree.C+
// bkg_tree c("chb","kspipi")
// c.Loop("kpi0")
//

void bkg_tree::Loop(char* decay)
{
//   In a ROOT session, you can do:
//      Root > .L bkg_tree.C
//      Root > bkg_tree t
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

//#####################################

//define output file 
  TString outfile_name="./study/SigBox3sigma/bkg_"+TString(decay)+"_"+d0model+"_"+sig_type+".study";
  ofstream outfile(outfile_name);
  cout<<"outfile name "<<sig_type<<" "<<decay<<" = " <<outfile_name<<endl;
//definisco le candidate madri delle tracce e compositi
  Int_t gmkstarckspi1(0);
  Int_t gmkstarckspi2(0);
  Int_t gmkstarcpic(0);
  Int_t gmkstarckc(0);
  Int_t gmkstarcpi0g1(0);
  Int_t gmkstarcpi0g2(0);
  Int_t gmd0pi1(0);
  Int_t gmd0pi2(0);
  Int_t gmd0kspi1(0);
  Int_t gmd0kspi2(0);

  Int_t ld0(0);
  Int_t lkstarcpic(0);
  Int_t lkstarckc(0);
  Bool_t check=kTRUE;
  if (fChain == 0) return;
   
   Int_t nentries = Int_t(fChain->GetEntries());
   cout<<"numero di entries: "<<nentries<<endl;

   Int_t dec= (decay==TString("kspi")) ? 1 : 2;
   Int_t nbytes = 0, nb = 0;
   for (Int_t jentry=0; jentry<nentries;jentry++) {
//#############definisco le quantita' per le risonanze########
      Int_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      if (Cut(ientry,dec) < 0) continue;
      
//##################################################
      outfile<<endl<<endl;
      if (dec==1) outfile<<"event number:"<<event<<" flagkspi="<<flagkspi<<" mcNREvtType="<<mcNREvtType
			 <<" D0="<<ismcd0<<" D0Ks="<<ismcd0ks
			 <<" KstarcKs="<<ismckstarcks<<" KstarcPic="<< ismckstarckspic<< " lundKstarPi="
			 << idMc[indexmckstarcpic] << endl;      

      else      outfile<<"event number:"<<event<<" flagkspi="<<flagkspi<<" mcNREvtType="<<mcNREvtType
		       <<" D0="<<ismcd0<<" D0Ks="<<ismcd0ks
		       <<" KstarcPi0="<<ismckstarcpi0 << " lundKstarK="<< idMc[indexmckstarckc] << endl;


//##############Kstarc candidate   ####################################

      if (dec==1){
//##############Kstarc Pion candidate   ####################################

      if (indexmckstarcpic>0 && indexmckstarcpic<110){
	cout <<"lundmcKstarcPic = "<<idMc[indexmckstarcpic]<< endl; 
	outfile<<"KstarcPic candidate: ";
	outfile<<idMc[indexmckstarcpic]<<" ";
	gmkstarcpic=indexmckstarcpic;
	check=kTRUE;
	while ( (abs(idMc[gmkstarcpic]) != 70553) && (abs(idMc[gmkstarcpic]) != 521) && (abs(idMc[gmkstarcpic]) != 10022) && (abs(idMc[gmkstarcpic]) != 511) && gmkstarcpic>0 && gmkstarcpic<110 && check) {
	  
	  check=kFALSE;
	  cout<< "gmkstarcpic = "<<gmkstarcpic<<" idMc[gmkstarcpic]= "<<idMc[gmkstarcpic]<<endl;
	  if (  ((mothMc[gmkstarcpic]-1)>0) && ((mothMc[gmkstarcpic]-1)<110) ){
	  gmkstarcpic=mothMc[gmkstarcpic]-1;
	  outfile<<idMc[gmkstarcpic]<<" ";
	  check=kTRUE;
	  }
	  //	  else  break;
	}
	outfile<<endl;
      }
      if (abs(idMc[gmkstarcpic])==521 || abs(idMc[gmkstarcpic])==511) outfile<< "# B dau = "<<nDauMc[gmkstarcpic]<<endl; 
      cout<<"sono qui "<< gmkstarcpic << " "<<idMc[gmkstarcpic]<<" # B dau = "<<nDauMc[gmkstarcpic]<<endl;
      
      //      break;


//##############Kstarc  KS daughters####################################
      outfile<<"KstarcKs daughter KstarcPi1 candidate: ";
      if (indexmckstarckspi1>0 && indexmckstarckspi1<110){
      outfile<<idMc[indexmckstarckspi1]<<" "; 
      gmkstarckspi1=indexmckstarckspi1;
      check=kTRUE;
      while ( (abs(idMc[gmkstarckspi1]) != 70553) && (abs(idMc[gmkstarckspi1]) != 521) && (abs(idMc[gmkstarckspi1]) != 10022) && (abs(idMc[gmkstarckspi1]) != 511) && gmkstarckspi1>0 && gmkstarckspi1<110 && check) {

	check=kFALSE;
	if (  ((mothMc[gmkstarckspi1]-1)>0) && ((mothMc[gmkstarckspi1]-1)<110) ){
	  gmkstarckspi1=mothMc[gmkstarckspi1]-1;
	  outfile<<idMc[gmkstarckspi1]<<" ";
	  check=kTRUE;
	}
	//	else  break;
      }
      outfile<<endl;
      }

      outfile<<"KstarcKs daughter KstarcPi2 candidate: ";
      if (indexmckstarckspi2>0 && indexmckstarckspi2<110){
      outfile<<idMc[indexmckstarckspi2]<<" "; 
      gmkstarckspi2=indexmckstarckspi2;
      check=kTRUE;
      while ( (abs(idMc[gmkstarckspi2]) != 70553) && (abs(idMc[gmkstarckspi2]) != 521) && (abs(idMc[gmkstarckspi2]) != 10022) && (abs(idMc[gmkstarckspi2]) != 511) && gmkstarckspi2>0 && gmkstarckspi2<110 && check) {
	
	check=kFALSE;
	if (  ((mothMc[gmkstarckspi2]-1)>0) && ((mothMc[gmkstarckspi2]-1)<110) ){
	  gmkstarckspi2=mothMc[gmkstarckspi2]-1;
	  outfile<<idMc[gmkstarckspi2]<<" ";
	  check=kTRUE;
	}
	//	else  break;

      }
      outfile<<endl;
      }


      }//if (dec==1)

      else if (dec==2){

//##############Kstarc Pi0 candidate####################################
      outfile<<"KstarcPi0 g1 candidate: ";
      if (indexmckstarcpi0g1>0 && indexmckstarcpi0g1<110){
	check=kTRUE;
	outfile<<idMc[indexmckstarcpi0g1]<<" "; 
	gmkstarcpi0g1=indexmckstarcpi0g1;
	while ( (abs(idMc[gmkstarcpi0g1]) != 521) && (abs(idMc[gmkstarcpi0g1]) != 10022) && (abs(idMc[gmkstarcpi0g1]) != 511) && gmkstarcpi0g1>0 && gmkstarcpi0g1<110 && check) {
	  check=kFALSE;
	  if (  ((mothMc[gmkstarcpi0g1]-1)>0) && ((mothMc[gmkstarcpi0g1]-1)<110) ){
	    gmkstarcpi0g1=mothMc[gmkstarcpi0g1]-1;
	    outfile<<idMc[gmkstarcpi0g1]<<" ";
	    check=kTRUE;
	  }
	//	else  break;
      }
      
      outfile<<endl;
      }

      outfile<<"KstarcPi0 g2 candidate: ";
      if (indexmckstarcpi0g2>0 && indexmckstarcpi0g2<110){
	check=kTRUE;
      outfile<<idMc[indexmckstarcpi0g2]<<" "; 
      gmkstarcpi0g2=indexmckstarcpi0g2;
      while ( (abs(idMc[gmkstarcpi0g2]) != 521) && (abs(idMc[gmkstarcpi0g2]) != 10022) && (abs(idMc[gmkstarcpi0g2]) != 511) && gmkstarcpi0g2>0 && gmkstarcpi0g2<110 && check) {

	check=kFALSE;
	if (  ((mothMc[gmkstarcpi0g1]-1)>0) && ((mothMc[gmkstarcpi0g1]-1)<110) ){
	  gmkstarcpi0g1=mothMc[gmkstarcpi0g1]-1;
	  outfile<<idMc[gmkstarcpi0g1]<<" ";
	  check=kTRUE;
	}
	//	else  break;

      }
      outfile<<endl;
      }


//##############Kstarc Kaon candidate   ####################################

      if (indexmckstarckc>0 && indexmckstarckc<110){
	check=kTRUE;
	outfile<<"lundmcKstarcKc = "<<idMc[indexmckstarckc]<< endl; 
	outfile<<"KstarcKc candidate: ";
	outfile<<idMc[indexmckstarckc]<<" "; 
	lkstarckc = idMc[indexmckstarckc];
	gmkstarckc=indexmckstarckc;
	while ( (abs(idMc[gmkstarckc]) != 70553) && (abs(idMc[gmkstarckc]) != 521) && (abs(idMc[gmkstarckc]) != 10022) && (abs(idMc[gmkstarckc]) != 511) && gmkstarckc>0 && gmkstarckc<110 && check) {
	  
	  cout<< "gmkstarckc = "<<gmkstarckc<<" idMc[gmkstarckc]= "<<idMc[gmkstarckc]<<endl;
	  check=kFALSE;
	if (  ((mothMc[gmkstarckc]-1)>0) && ((mothMc[gmkstarckc]-1)<110) ){
	  gmkstarckc=mothMc[gmkstarckc]-1;
	  outfile<<idMc[gmkstarckc]<<" ";
	  check=kTRUE;
	}
	//	else  break;
	
	}
	outfile<<endl;
      }
      if (abs(idMc[gmkstarckc])==521 || abs(idMc[gmkstarckc])==511) outfile<< "# B dau = "<<nDauMc[gmkstarckc]<<endl; 
      cout<<"sono qui "<<idMc[gmkstarckc]<<endl;
      
      //      break;
      
      } //else if(dec==2)

//##############D0 candidate tracks####################################
      outfile<<"D0 daughter D0Pi1 candidate: ";
      if (indexmcd0pi1>0 && indexmcd0pi1<110){
	check=kTRUE;
      outfile<<idMc[indexmcd0pi1]<<" "; 
      gmd0pi1=indexmcd0pi1;
      while ( (abs(idMc[gmd0pi1]) != 70553) && (abs(idMc[gmd0pi1]) != 521) && (abs(idMc[gmd0pi1]) != 10022) && (abs(idMc[gmd0pi1]) != 511) && gmd0pi1>0 && gmd0pi1<110 && check) {
	check=kFALSE;
	if (  ((mothMc[gmd0pi1]-1)>0) && ((mothMc[gmd0pi1]-1)<110) ){
	  gmd0pi1=mothMc[gmd0pi1]-1;
	  outfile<<idMc[gmd0pi1]<<" ";
	  check=kTRUE;
	}
	//	else  break;

	if (abs(idMc[gmd0pi1])==421) ld0=idMc[gmd0pi1];
      }
      outfile<<endl;
      }
      
      outfile<<"D0 daughter D0Pi2 candidate: ";
      if (indexmcd0pi2>0 && indexmcd0pi2<110){
	check=kTRUE;
      outfile<<idMc[indexmcd0pi2]<<" "; 
      gmd0pi2=indexmcd0pi2;
      while ( (abs(idMc[gmd0pi2]) != 70553) && (abs(idMc[gmd0pi2]) != 521) && (abs(idMc[gmd0pi2]) != 10022) && (abs(idMc[gmd0pi2]) != 511) && gmd0pi2>0 && gmd0pi2<110 && check) {

        check=kFALSE;
	if (  ((mothMc[gmd0pi2]-1)>0) && ((mothMc[gmd0pi2]-1)<110) ){
	  gmd0pi2=mothMc[gmd0pi2]-1;
	  outfile<<idMc[gmd0pi2]<<" ";
	  check=kTRUE;
	}
	//	else  break;
      }
      outfile<<endl;
      }
      
//##############D0 candidate tracks:  KS daughters####################################
      outfile<<"D0 daughter KsPi1 candidate: ";
      if (indexmcd0kspi1>0 && indexmcd0kspi1<110){
	check=kTRUE;
      outfile<<idMc[indexmcd0kspi1]<<" "; 
      gmd0kspi1=indexmcd0kspi1;
      while ( (abs(idMc[gmd0kspi1]) != 70553) && (abs(idMc[gmd0kspi1]) != 521) && (abs(idMc[gmd0kspi1]) != 10022) && (abs(idMc[gmd0kspi1]) != 511) && gmd0kspi1>0 && gmd0kspi1<110 && check) {

	check=kFALSE;
	if (  ((mothMc[gmd0kspi1]-1)>0) && ((mothMc[gmd0kspi1]-1)<110) ){
	  gmd0kspi1=mothMc[gmd0kspi1]-1;
	  outfile<<idMc[gmd0kspi1]<<" ";
	  check=kTRUE;
	}
	//	else  break;

      }
      outfile<<endl;
      }

      outfile<<"D0 daughter KsPi2 candidate: ";
      if (indexmcd0kspi2>0 && indexmcd0kspi2<110){
	check=kTRUE;
	outfile<<idMc[indexmcd0kspi2]<<" "; 
	gmd0kspi2=indexmcd0kspi2;
      while ( (abs(idMc[gmd0kspi2]) != 70553) && (abs(idMc[gmd0kspi2]) != 521) && (abs(idMc[gmd0kspi2]) != 10022) && (abs(idMc[gmd0kspi2]) != 511) && gmd0kspi2>0 && gmd0kspi2<110 && check ) {

	check=kFALSE;
	if (  ((mothMc[gmd0kspi2]-1)>0) && ((mothMc[gmd0kspi2]-1)<110) ){
	  gmd0kspi2=mothMc[gmd0kspi2]-1;
	  outfile<<idMc[gmd0kspi2]<<" ";
	  check=kTRUE;
	}
	//	else  break;
      }
      outfile<<endl;
      }

      outfile<<endl;
      //      outfile<<"d0flag="<<isMcd0<<" lpr ="<<lpr<<" ld0 ="<<ld0<<endl;
      outfile<<endl;
	
   }
}	   
