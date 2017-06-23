
Double_t CrystalBall(Double_t *x,Double_t *par) ;
Double_t CrystalBallPol(Double_t *x,Double_t *par) ;
void plots(){
//////////////////////////////////////////////////////////
//   This file has been automatically generated 
//     (Thu May  5 18:28:37 2016 by ROOT version6.07/03)
//   from TTree nt/nt
//   found on file: jpsihistos.root
//////////////////////////////////////////////////////////


//Reset ROOT and connect tree file
   gROOT->Reset();
  gROOT->ProcessLine(".x ~/Documents/LHCb/Data/lhcbStyle.C");
   TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("histos.root");
   if (!f) {
      f = new TFile("histos.root");
   }
  
  TTree *nt = (TTree*) f->Get("nt");

//Declaration of leaves types
  Float_t         MM;
  Float_t         PT;
  Float_t         Y;
  Float_t         Z;
  Float_t         DIRA;
  Float_t         plusPIDK;
  Float_t         minusPIDK;
  Float_t         Hcal;
  Float_t         Ecal;
  Float_t         Velo;

  // Set branch addresses.
  nt->SetBranchAddress("MM",&MM);
  nt->SetBranchAddress("PT",&PT);
  nt->SetBranchAddress("Y",&Y);
  nt->SetBranchAddress("Z",&Z);
  nt->SetBranchAddress("DIRA",&DIRA);
  nt->SetBranchAddress("KplusPIDK",&plusPIDK);
  nt->SetBranchAddress("piminusPIDK",&minusPIDK);
  nt->SetBranchAddress("Hcal",&Hcal);
  nt->SetBranchAddress("Ecal",&Ecal);
  nt->SetBranchAddress("Velo",&Velo);

//    This is the loop skeleton
//      To read only selected branches, Insert statements like:
//nt->SetBranchStatus("*",0);  // disable all branches
//TTreePlayer->SetBranchStatus("branchname",1);  // activate branchname

  Int_t bins[] =    { 25, 10, 130 };
  Double_t lbin[] = { 1770., 0., 0. };
  Double_t ubin[] = { 1970., 6.986e+07, 1.3e4 };

  THnSparseD *hn = new THnSparseD("hn","hn",3,bins,lbin,ubin);
  hn->GetAxis(0)->SetTitle("M(K#pi) [MeV/c^{2}]");
  hn->GetAxis(2)->SetTitle("Velo Clusters");

  Double_t ecalbins[] = {
  0,
  252009.    ,
  688341.    ,
  1.56095e+06,
  3.11045e+06,
  5.61206e+06,
  9.42711e+06,
  1.49825e+07,
  2.2778e+07,
  3.39965e+07,
  6.986e+07
  };

  hn->GetAxis(1)->Set(10,ecalbins);

  Long64_t nentries = nt->GetEntries();
  Long64_t nbytes = 0;
  for (Long64_t i=0; i<nentries;i++) {
    nbytes += nt->GetEntry(i);
    if( ! (Y > 2. && Y < 4.5) ) continue; 
    //if( plusPIDK  < 10. ) continue;
    //if( minusPIDK  > -5. ) continue;
    if( PT  < 1000. ) continue;
    Double_t data[] = {MM,Ecal,Velo};
    hn->Fill( data);
  }

  new TCanvas;
  hn->Projection(0)->Draw();

  TLatex latex;
  int binL, binU;
  for( int i = 2; i <=5; i+=2){
    binL = i; binU = i+1;
    hn->GetAxis(1)->SetRange(i,i);
    TCanvas *c = new TCanvas;
    //c->Divide(2,1);
    c->cd(1);
    TH1F *tmp = (TH1F*) hn->Projection(0);
    tmp->SetName( Form("MM_%d",i ) );
    tmp->SetTitle( Form("MM_%d",i ) );
    tmp->GetYaxis()->SetRangeUser(0.01,1.32*tmp->GetMaximum());
    tmp->GetYaxis()->SetTitle(Form("Candidates per %.1f MeV/c^{2}",tmp->GetXaxis()->GetBinWidth(1) ));
    tmp->Draw("e");
    TF1 *cballpol = new TF1("cballpol",CrystalBallPol,2900.0, 3300.0,8);

    cballpol->SetParameter(0,2.0);//alpha
    cballpol->SetParameter(1,1.0);//n
    cballpol->SetParameter(2, 1860);//mean
    cballpol->SetParameter(3, 10);//width
    cballpol->SetParameter(4, tmp->Integral()/tmp->GetXaxis()->GetBinWidth(1));//normalization
    cballpol->SetParameter(5,  4.0);//2.30442e+03); 
    cballpol->SetParameter(6, -0.01);
    cballpol->SetParameter(7, 7.76718e-04);
    cballpol->SetLineColor(kRed);
    cballpol->SetNpx(500);

    tmp->Fit("cballpol");

    latex.DrawLatex(1865,0.9*tmp->GetMaximum(),Form("%d%%<Event Activity<%d%%",100-10*binU,100-10*(binL-1)));
    latex.DrawLatex(1780,0.9*tmp->GetMaximum(),"LHCb preliminary");
    latex.DrawLatex(1780,0.8*tmp->GetMaximum(),"#sqrt{s_{NN}} = 5 TeV");
    //c->cd(2);
    //hn->Projection(2)->Draw();
    c->SaveAs(Form("plots/d0_ecalbin_%d_%d.pdf",100-10*(binL-1),100-10*binU));
    c->SaveAs(Form("plots/d0_ecalbin_%d_%d.C",100-10*(binL-1),100-10*binU));
  }
  

  
}
//Crystal ball function, parameters are 0:alpha, 1:n, 2:mean, 3:sigma, 4:normalization;

Double_t CrystalBall(Double_t *x,Double_t *par) {
  Double_t t = (x[0]-par[2])/par[3];
  if (par[0] < 0) t = -t;
  Double_t absAlpha = fabs((Double_t)par[0]);
  if (t >= -absAlpha) {
    return par[4]*exp(-0.5*t*t);
  }
  else {
    Double_t a =  TMath::Power(par[1]/absAlpha,par[1])*exp(-0.5*absAlpha*absAlpha);
    Double_t b= par[1]/absAlpha - absAlpha;
    return par[4]*(a/TMath::Power(b - t, par[1]));
  }
}

Double_t CrystalBallPol(Double_t *x,Double_t *par) {
  Double_t t = (x[0]-par[2])/par[3];
  if (par[0] < 0) t = -t;
  Double_t absAlpha = fabs((Double_t)par[0]);
  if (t >= -absAlpha) {
    return par[4]*exp(-0.5*t*t) + par[5]+par[6]*(x[0]-par[2])+par[7]*(x[0]-par[2])*(x[0]-par[2]);
  }
  else {
    Double_t a =  TMath::Power(par[1]/absAlpha,par[1])*exp(-0.5*absAlpha*absAlpha);
    Double_t b= par[1]/absAlpha - absAlpha;
    return par[4]*(a/TMath::Power(b - t, par[1])) + par[5]+par[6]*(x[0]-par[2])+par[7]*(x[0]-par[2])*(x[0]-par[2]);
  }
}

