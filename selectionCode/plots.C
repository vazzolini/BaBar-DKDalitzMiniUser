
{

 TStyle *babarStyle= new TStyle("BABAR","BaBar approved plots style");

  // use plain black on white colors
  babarStyle->SetFrameBorderMode(0);
  babarStyle->SetCanvasBorderMode(0);
  babarStyle->SetPadBorderMode(0);

  babarStyle->SetCanvasColor(0);
  // babarStyle->SetTitleColor(0);
  babarStyle->SetStatColor(0);
  babarStyle->SetTitleFillColor(0);

  // set the paper & margin sizes
  babarStyle->SetPaperSize(21.,29.7);
  babarStyle->SetPadTopMargin(0.10);
  babarStyle->SetPadRightMargin(0.15);
  babarStyle->SetPadBottomMargin(0.16);
  babarStyle->SetPadLeftMargin(0.10);

  // use large Times-Roman fonts
  babarStyle->SetTitleFont(132,"xyz");  // set the all 3 axes title font
  babarStyle->SetTitleFont(132," ");    // set the pad title font
  babarStyle->SetTitleSize(0.04,"xyz"); // set the 3 axes title size
  babarStyle->SetTitleSize(0.04," ");   // set the pad title size
  babarStyle->SetTitleYOffset(1.4);
  babarStyle->SetTitleXOffset(1.2);
  babarStyle->SetLabelFont(132,"xyz");
  babarStyle->SetLabelSize(0.04,"xyz");
  babarStyle->SetTextFont(132);
  babarStyle->SetTextSize(0.09);
  babarStyle->SetStatFont(132);
  
  // use bold lines and markers
  babarStyle->SetMarkerStyle(20);
  babarStyle->SetMarkerSize(1.);
  babarStyle->SetHistLineWidth(2);
  // babarStyle->SetHistMinimumZero(kTRUE);
  babarStyle->SetLineStyleString(2,"[12 12]"); // postscript dashes
  babarStyle->SetPalette(1);
  //..Get rid of X error bars
  // babarStyle->SetErrorX(0.001);

   // do not display any of the standard histogram decorations
  babarStyle->SetOptTitle(0);
  babarStyle->SetOptStat(1111111);
  babarStyle->SetOptFit(0);

  // put tick marks on top and RHS of plots
  babarStyle->SetPadTickX(1);
  babarStyle->SetPadTickY(1);

  cout << endl << "    For approved plots use: gROOT->SetStyle(\"BABAR\");"
       << endl << "  To add a BABAR label use: BABARLabel();"
       << endl << "  To add a better-scaling BABAR label use: BABARSmartLabel();"
       << endl << "    type \"BABARSmartLabel(-2);\" for options"
       << endl << "  BaBar Style has been loaded" 
       << endl << endl;


  // Make all histograms use this style...
  gROOT->ForceStyle();
  // restore the plain style
  gROOT->SetStyle("BABAR");
}
