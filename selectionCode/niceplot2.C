
dibuja(TH1 *h1_data, TH1 *h1_mc, Float_t ymax, TString xtitle, TString labelpos, TString plot){ 

  gStyle->SetOptStat(0);
  gStyle->SetPadRightMargin(0.1);
  gStyle->SetPadBottomMargin(0.16);
  gStyle->SetPadLeftMargin(0.20);
  gStyle->SetPadTopMargin(0.20);
  gStyle->SetTitleSize(0.06,"xyz");
  gStyle->SetLabelFont(132,"xyz");
  gStyle->SetLabelSize(0.04,"xyz");
  gStyle->SetTextFont(132);
  gStyle->SetTextSize(0.05);
  gStyle->SetTitleXOffset(0.8);
  gStyle->SetTitleYOffset(0.8);

Float_t r=0.25;

Float_t s1 = 1./(1-r);
Float_t sr = 1./r;

TCanvas *c1 = new TCanvas("c1","c1",500,600);
c1->Divide(1,2);
c1->SetBottomMargin(0.25);

// get the TPad pointers
  //

  TPad* p1 = (TPad*)c1->FindObject("c1_1");
  TPad* p2 = (TPad*)c1->FindObject("c1_2");

  // modify the TPad sizes
  p1->SetPad(0.,r, 1.,1.);
  p2->SetPad(0., 0., 1.,r);
  p1->SetBottomMargin(0.0);
  p2->SetTopMargin(0.0);
  p2->SetBottomMargin(0.5);
  p2->SetLeftMargin(0.2);
  p1->SetLeftMargin(0.2);
  
 
c1->cd(1);
 
 TAxis* x1 = h1_mc->GetXaxis();
 TAxis* y1 = h1_mc->GetYaxis();
 x1->SetTitleSize(x1->GetTitleSize()*s1); 
 x1->SetLabelSize(x1->GetLabelSize()*s1); 
 y1->SetTitleSize(y1->GetTitleSize()*s1); 
 y1->SetLabelSize(y1->GetLabelSize()*s1); 
 y1->SetTitleOffset(0.85);

 h1_mc->SetMaximum(ymax); 
 h1_mc->SetMinimum(0); 
 h1_mc->SetXTitle(xtitle); 
 h1_mc->SetYTitle("Entries"); 
 h1_mc->SetLineColor(kRed);
 h1_mc->SetMarkerStyle(0);
 h1_mc->Draw("ah");
 h1_data->Draw("e0same");


 TLegend *legend;
 if (labelpos=="R") legend = new TLegend(0.72,0.65,0.85,0.75);
 if (labelpos=="L") legend = new TLegend(0.25,0.65,0.40,0.75);

  legend->SetFillColor(kWhite);
  legend->AddEntry(h1_data,"Data", "p");
  legend->AddEntry(h1_mc,"MC", "L");
  legend->Draw();

 c1->cd(2);

 TH1D *dh1=(TH1D*)h1_data->Clone();

 dh1->SetMaximum(2.);
 dh1->SetMinimum(0.);
 dh1->Divide(h1_mc);
 dh1->SetXTitle(xtitle); 
 dh1->SetYTitle("data/MC");

 TAxis* dx1 = dh1->GetXaxis();
 TAxis* dy1 = dh1->GetYaxis();

 dx1->SetTitleSize(dx1->GetTitleSize()*sr); 
 dx1->SetLabelSize(dx1->GetLabelSize()*sr); 

 dy1->SetTitleSize(dy1->GetTitleSize()*sr*0.75); 
 dy1->SetLabelSize(dy1->GetLabelSize()*sr*0.8); 
 dx1->SetTickLength(dx1->GetTickLength()*sr);
 dy1->SetTitleOffset(0.3);

 dx1->SetNdivisions(805);
 dy1->SetNdivisions(805);

 dh1->Draw("e0");
 
  dh1->Fit("pol1");

  Float_t xi = dx1->GetXmin();
  Float_t xf = dx1->GetXmax();

 TLine *ldh1 = new TLine(xi,1.,xf,1.); 
 ldh1->Draw("same"); 
 
c1->Print(plot);

return();

}
//-----------------------------------------------------------------------------------------------


//Compara dos plots-> Sideband signal region
dibuja2(TH1 *h1_sr, TH1 *h1_or, Float_t ymax, TString xtitle, TString labelpos, TString plot){ 

  gStyle->SetOptStat(0);
  gStyle->SetPadRightMargin(0.1);
  gStyle->SetPadBottomMargin(0.16);
  gStyle->SetPadLeftMargin(0.20);
  gStyle->SetPadTopMargin(0.20);
  gStyle->SetTitleSize(0.06,"xyz");
  gStyle->SetMarkerStyle(0);
  gStyle->SetLabelFont(132,"xyz");
  gStyle->SetLabelSize(0.04,"xyz");
  gStyle->SetTextFont(132);
  gStyle->SetTextSize(0.05);
  gStyle->SetTitleXOffset(0.8);
  gStyle->SetTitleYOffset(0.8);


Float_t r=0.25;

Float_t s1 = 1./(1-r);
Float_t sr = 1./r;

TCanvas *c1 = new TCanvas("c1","c1",500,600);
c1->Divide(1,2);
c1->SetBottomMargin(0.25);

// get the TPad pointers
  //

  TPad* p1 = (TPad*)c1->FindObject("c1_1");
  TPad* p2 = (TPad*)c1->FindObject("c1_2");

  // modify the TPad sizes
  p1->SetPad(0.,r, 1.,1.);
  p2->SetPad(0., 0., 1.,r);
  p1->SetBottomMargin(0.0);
  p2->SetTopMargin(0.0);
  p2->SetBottomMargin(0.5);
  p2->SetLeftMargin(0.2);
  p1->SetLeftMargin(0.2);
  
 
c1->cd(1);
 
 TAxis* x1 = h1_or->GetXaxis();
 TAxis* y1 = h1_or->GetYaxis();
 x1->SetTitleSize(x1->GetTitleSize()*s1); 
 x1->SetLabelSize(x1->GetLabelSize()*s1); 
 y1->SetTitleSize(y1->GetTitleSize()*s1); 
 y1->SetLabelSize(y1->GetLabelSize()*s1); 
 y1->SetTitleOffset(0.85);

 h1_or->SetMaximum(ymax); 
 h1_or->SetMinimum(0); 
 h1_or->SetXTitle(xtitle); 
 h1_or->SetYTitle("Entries"); 
 h1_or->SetLineColor(kRed);
 h1_or->SetMarkerStyle(0);
 h1_or->Draw("ah");
 h1_sr->Draw("ahsame");
 h1_or->SetLineColor(kBlue);


 TLegend *legend;
 if (labelpos=="R") legend = new TLegend(0.72,0.65,0.85,0.75);
 if (labelpos=="L") legend = new TLegend(0.25,0.65,0.40,0.75);

  legend->SetFillColor(kWhite);
  legend->AddEntry(h1_sr,"#delta m signal (SR)", "L");
  legend->AddEntry(h1_or,"Sideband (BR)", "L");
  legend->Draw();

 c1->cd(2);

 TH1D *dh1=(TH1D*)h1_sr->Clone();

 dh1->SetMaximum(2.);
 dh1->SetMinimum(0.);
 dh1->Divide(h1_or);
 dh1->SetXTitle(xtitle); 
 dh1->SetYTitle("SR/BR");

 TAxis* dx1 = dh1->GetXaxis();
 TAxis* dy1 = dh1->GetYaxis();

 dx1->SetTitleSize(dx1->GetTitleSize()*sr); 
 dx1->SetLabelSize(dx1->GetLabelSize()*sr); 

 dy1->SetTitleSize(dy1->GetTitleSize()*sr*0.75); 
 dy1->SetLabelSize(dy1->GetLabelSize()*sr*0.8); 
 dx1->SetTickLength(dx1->GetTickLength()*sr);
 dy1->SetTitleOffset(0.3);

 dx1->SetNdivisions(805);
 dy1->SetNdivisions(805);

 dh1->Draw("e0");
 
 //  dh1->Fit("pol1");

  Float_t xi = dx1->GetXmin();
  Float_t xf = dx1->GetXmax();

 TLine *ldh1 = new TLine(xi,1.,xf,1.); 
 ldh1->Draw("same"); 
 
c1->Print(plot);

return();

}



