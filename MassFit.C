//#define CSelected_cxx
//#include "CSelected.h"

#include "TStyle.h"
#include "TSystem.h"

#include "TString.h"
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TObject.h>
#include <TNtuple.h>
#include <TDirectory.h>
#include "RooFit.h"
#include "TCut.h"
#include "RooRealVar.h"
#include "RooArgSet.h"
#include "RooDataSet.h"
#include "RooArgList.h"
#include "RooAddPdf.h"
#include "RooDataHist.h"
#include "RooGaussModel.h"
#include "RooKeysPdf.h"
#include "RooDecay.h"
#include "RooCBShape.h"
#include "RooGaussian.h"
#include "RooPolynomial.h"
#include "RooHistPdf.h"
#include "RooAddModel.h"
#include "RooProdPdf.h"
#include "TMath.h"
#include "RooAbsData.h"
#include "RooGlobalFunc.h"
#include "RooMinuit.h"
#include "RooFitResult.h"
#include "TCanvas.h"
#include "RooPlot.h"
#include "TRandom3.h"
#include "TH1.h"
#include "TCanvas.h"
#include "RooMCStudy.h"
#include "RooNovosibirsk.h"
#include "RooBifurGauss.h"
#include "RooLandau.h"
#include "RooFormulaVar.h"
#include "RooNumConvPdf.h"
#include "RooFFTConvPdf.h"
#include "RooAbsReal.h"
#include "RooNLLVar.h"
#include "RooMinimizer.h"
#include "RooChebychev.h"
#include "RooExponential.h"

using namespace RooFit;

void MassFit(){
  gROOT->ProcessLine(".x /home/bossu/Documents/LHCb/Data/lhcbStyle.C");
  gStyle->SetPalette(1);

  // get histogram
  // ==================================
  TFile *file = TFile::Open("hmm.root");
  TH1D *hh = (TH1D*) file->Get("hmm"); 

   double MM = 1865;
   double WM = 75;
   double DM = 15;
   RooRealVar x("D0_MM","M(D^{0})",MM-WM,MM+WM,"MeV/c^{2}");

  RooRealVar m("m","M(#mu^{+}#mu^{-})",1860,1800,1940);
  m.setBins((m.getMax()-m.getMin())/hh->GetBinWidth(1));
  //RooRealVar p("p","Momentum",0,500e3);
  //RooRealVar pt("pt","pt",2000,5000);
  //RooRealVar y("y","y",2,2.5);
  //RooRealVar tz("tz","tz",-1,1);
  ////RooRealVar etz2("etz2","etz2",0,0.3);
  //RooDataSet data("data","data",realdata,RooArgSet(m,p,pt,y,tz));

  RooDataHist data("data","data",m,Import(*hh));

  //RooRealVar *mass_mean = new RooRealVar("mass_mean","mass_mean", 1862,1810,1910,"MeV");
  //RooRealVar *mass_sigma = new RooRealVar("mass_sigma","mass_sigma",7.,1.,30,"MeV");

  ////RooRealVar a0("a0","a0",1.975);
  ////RooRealVar a1("a1","a1",0.011);
  ////RooRealVar a2("a2","a2",-0.00018);
  ////RooFormulaVar* mass_alpha = new RooFormulaVar("mass_alpha","mass_alpha",
  ////"a0 + a1*sqrt(mass_sigma*mass_sigma) + a2*mass_sigma*mass_sigma", 
  ////RooArgSet(a0,a1,a2,*mass_sigma));
  //RooRealVar *mass_n = new RooRealVar("mass_n","mass_n",1.0,0.1,50.);
  //RooRealVar *mass_alpha = new RooRealVar("mass_alpha","mass_alpha",2.0,1.0,6.7);
  ////RooCBShape *sig_mass = new RooCBShape("sig_mass","sig_mass", m, *mass_mean, *mass_sigma, *mass_alpha, *mass_n);
  //RooRealVar a0("a0","a0",1862.,1700, 2000);
  //RooRealVar a1("a1","a1",500,0,1e4);
  //RooRealVar a2("a2","a2", 0.1,0.,1);
  //RooCBShape *BB_mass = new RooCBShape("BB_mass","sig_mass", m, *mass_mean, *mass_sigma, *mass_alpha, *mass_n);
  //RooAbsPdf *AA_mass=new RooGaussian("AA_mass","AA_mass",m, a0, a1);
  //RooAbsPdf *sig_mass = new RooAddPdf("sig_mass","sig_pdf",RooArgList(*BB_mass,*AA_mass),RooArgList(a2));
   
  ////fake Jpsi pdf
  //RooRealVar *p0=new RooRealVar("p0","p0",-0.,-2,2,"MeV/c^{2}");
  //RooAbsPdf *pol1_mass=new RooExponential("pol1_mass","pol1_mass",m,*p0);
   
  //RooRealVar nsig("nsig","nsig",hh->GetEntries()*0.7,0,hh->GetEntries());
  //RooRealVar nbkg("nbkg","nbkg",hh->GetEntries()*0.3,0,hh->GetEntries());

  //RooAbsPdf *mass_pdf=new RooAddPdf("mass_pdf","mass_pdf",RooArgList(*sig_mass,*pol1_mass),RooArgList(nsig,nbkg));

         //////////////////////////////// //////////////////////////////// //////////////////////////////// ////////////////////////////////
         RooRealVar Mean("Mean","",MM,MM-DM,MM+DM);
         RooRealVar CBS("CBS","CBS",DM/2.,4.,DM,"MeV/c^{2}");
         RooRealVar n("n","n",1.);
         RooRealVar a("a","a",2.,1.,5.);
         RooCBShape sig1("cb", "Signal",m,Mean,CBS,a,n);

         //RooRealVar Sigma("Sigma","",DM/2.,0,DM*2);
         RooFormulaVar Sigma("Sigma","1.8*CBS",RooArgSet(CBS));
         RooGaussian gaus("gaus","",m,Mean,Sigma);
         RooRealVar f("f","",0.1,0.,0.999);

         f.setVal(0.85);f.setConstant();
         a.setVal(2.35);a.setConstant();
         RooAddPdf sig("sig","gau1+gau2",RooArgSet(sig1,gaus),RooArgSet(f));

         RooRealVar ns("ns","nSignal",hh->GetEntries()/2.,0.,hh->GetEntries()*1.2);
         RooExtendPdf sign("sign","sign",sig,ns);

         //BKG component
         RooRealVar p("p","p",-0.,-1./(MM+WM),1./(MM+WM));
         RooPolynomial bkg("bkg","bkg",m,RooArgSet(p));
         RooRealVar nb("nb","nBKG",hh->GetEntries()/2.,0.,hh->GetEntries());
         RooExtendPdf bkgn("bkgn","bkgn",bkg,nb);

         //sig+bkg
         RooAddPdf *mass_pdf = new RooAddPdf("mass_pdf","sig+bkg",RooArgSet(bkgn,sign));
         //////////////////////////////// //////////////////////////////// //////////////////////////////// ////////////////////////////////
      
  mass_pdf->fitTo(data,Extended(),Strategy(2));
  //mass_pdf->fitTo(data,Extended(),Minos(true),Strategy(2));
   TCanvas *c = new TCanvas;
  gPad->SetLeftMargin( 0.16);
  gPad->SetTopMargin( 0.06);
  //RooPlot* MassPlot = m.frame(Title(""));
  RooPlot* MassPlot = m.frame(Title("")); 
  //RooPlot* MassPlot = m.frame(Title(""));
  //RooPlot* MassPlot = m.frame(Range(3000,3200), Title(""));
  //RooPlot* MassPlot = m.frame(Range(3000,3200), Title(""),Bins(44));
  MassPlot->SetTitle("");
  MassPlot->GetXaxis()->SetTitle("Mass(#pi^{+}K^{-}) (MeV/c^{2})");
  MassPlot->GetYaxis()->SetTitle(Form("Events / %.0f MeV/c^{2}",MassPlot->GetXaxis()->GetBinWidth(2)));
  data.plotOn(MassPlot); 
  //mass_pdf->plotOn(MassPlot,Components(bkgn.GetName()), LineColor(kBlue), LineStyle(3));
  //mass_pdf->plotOn(MassPlot,Components(sign.GetName()), LineColor(kBlue), LineStyle(1));
  //mass_pdf->plotOn(MassPlot, LineColor(kRed));
  MassPlot->Draw();
  TLatex latex;
  cout << MassPlot->GetYaxis()->GetXmax() << endl;
  latex.DrawLatexNDC(0.6,0.87,"LHCb preliminary");
  latex.DrawLatexNDC(0.6,0.8,"p-Pb, #sqrt{s_{NN}} = 8 TeV");
  latex.DrawLatexNDC(0.6,0.72,"~13 nb^{-1}");

  c->SaveAs( "d0.pdf");

}
