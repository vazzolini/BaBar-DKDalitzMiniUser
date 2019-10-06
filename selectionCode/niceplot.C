
dibuja(TH1 *h1_data, TH1 *h1_mc, Float_t ymax, TString xtitle, TString labelpos, TString plot){ 
  //h1_data=24, h_mc=18


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
 h1_mc->SetMinimum(0.); 
 h1_mc->SetXTitle(xtitle); 
 h1_mc->SetYTitle("Entries"); 
 // h1_mc->SetLineColor(kRed);
 h1_mc->SetLineColor(2);
 // h1_mc->Draw("ah");
 h1_mc->Draw();
 h1_data->SetLineColor(8);
 h1_data->Draw("same");


 TLegend *legend;
 if (labelpos=="R") legend = new TLegend(0.72,0.65,0.85,0.75);
 if (labelpos=="L") legend = new TLegend(0.25,0.65,0.40,0.75);

  legend->SetFillColor(kWhite);
  legend->AddEntry(h1_data,"R24", "L");
  legend->AddEntry(h1_mc,"R18", "L");
  legend->Draw();


  /////////////////////////////////////////////////////////////////////////////////////////


  c1->cd(2);
   // h1_data->SetLineColor(1);  
  TH1D *dh1=(TH1D*)h1_data->Clone();
  
 dh1->SetMaximum(2.);
 dh1->SetMinimum(0.);
 // dh1->Divide(h1_mc);
 dh1->Add(h1_mc,-1);//dh1=dh1-h1_mc  24-18
 dh1->SetXTitle(xtitle); 
 dh1->SetYTitle("R24-R18");

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

 // dh1->Draw("e0");

 //http://root.cern.ch/root/html/TAttMarker.html
 //http://root.cern.ch/root/html/THistPainter.html
 
 dh1->SetMarkerStyle(1);
 //dh1->SetMarkerColor(1);
 dh1->SetMarkerSize(0.01);
 dh1->SetLineColor(1);

 dh1->Draw("e0");
 
 //  dh1->Fit("pol1");

  Float_t xi = dx1->GetXmin();
  Float_t xf = dx1->GetXmax();

 TLine *ldh1 = new TLine(xi,0.,xf,0.); 
 ldh1->Draw("same"); 
 
 c1->Print(plot);

return();

}



