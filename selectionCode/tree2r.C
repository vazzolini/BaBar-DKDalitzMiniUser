void tree2r(char* opt="c") {
  TFile *f = new TFile("SP-4851-AllEventsSkim-R16a-1.root");
  TTree *t1 = (TTree*)f->Get("ntp7");
  cout << f << " " << t1 << endl;

  t1->Draw("m2mDalitzD0:m2pDalitzD0");

  /*
  Float_t m2mDalitzD0;
  Float_t m2pDalitzD0;
  Float_t m2zDalitzD0;
  TBranch *b_m2mDalitzD0;
  TBranch *b_m2pDalitzD0;
  TBranch *b_m2zDalitzD0;
  t1->SetBranchAddress("m2mDalitzD0",&m2mDalitzD0);
  t1->SetBranchAddress("m2pDalitzD0",&m2pDalitzD0);
  t1->SetBranchAddress("m2zDalitzD0",&m2zDalitzD0);
  b_m2mDalitzD0 = t1->GetBranch("m2mDalitzD0");
  b_m2pDalitzD0 = t1->GetBranch("m2pDalitzD0");
  b_m2zDalitzD0 = t1->GetBranch("m2zDalitzD0");
  
  TH2* h2 = new TH2F("h2","m2p vs m2m",50,0.,4.,50,0.,4.);
  
  Int_t nentries = (Int_t)t1->GetEntries();
  cout << nentries << endl;
  for (Int_t i=0; i<1000; i++) {
    //b_m2mDalitzD0->GetEntry(i);
    //b_m2pDalitzD0->GetEntry(i);
    //b_m2zDalitzD0->GetEntry(i);
    t1->GetEntry(i);
    h2->Fill(m2mDalitzD0,m2pDalitzD0);
    cout << m2mDalitzD0 << " " << m2pDalitzD0 << endl;
  }
  h2->Draw();
  */
}
