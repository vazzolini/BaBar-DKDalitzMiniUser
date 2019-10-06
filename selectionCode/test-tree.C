{
TFile f("SP-2262-Run4-1-b.root");
f.ls();
TTree* t = ntp2;
TCanvas* c = new TCanvas();
c->Divide(2,2);
c->cd(1);
t->Draw("massD0");
c->cd(2);
t->Draw("massDstar");
c->cd(3);
//t->Draw("chi2DstarBS");
t->Draw("deltaMDstarBS","deltaMDstarBSBS>0.135 && deltaMDstarBSBS<0.16 && chi2DstarBS>0.");
c->cd(4);
t->Draw("deltaMDstarBS","deltaMDstarBSBS>0.14 && deltaMDstarBSBS<0.15 && chi2DstarBS>0.");
}
