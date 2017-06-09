#include "TH1.h"
#include "TMath.h"
#include "TF1.h"
#include "TLegend.h"
#include "TCanvas.h"
#include "TLatex.h"
#include "TLorentzVector.h"


// fourth order background function 
Double_t background(Double_t *x, Double_t *par){


    return par[0]+par[1]*x[0]+par[2]*x[0]*x[0]+par[3]*x[0]*x[0]*x[0]+par[4]*x[0]*x[0]*x[0]*x[0];

}


//Gaussian fit function


Double_t doubleGaussian(Double_t *x, Double_t *par){

    Double_t PDF = 0.0;
    Double_t g1 = 0.0;
    Double_t g2 = 0.0;

    //calculate the exponents of the Gaussians

    Double_t arg1 = (par[2] != 0.0) ? (x[0] - par[1])/(par[2]) : 0.0;
    Double_t arg2 = (par[3] != 0.0) ? (x[0] - par[1])/(par[3]) : 0.0;

    //add each Gaussian contribution to the PDF

    g1 = exp(-0.5*arg1*arg1)/(par[2]*sqrt(2.0*TMath::Pi()));
    g2 = exp(-0.5*arg2*arg2)/(par[3]*sqrt(2.0*TMath::Pi()));

    PDF = par[0]*(par[4]*g1 + (1-par[4])*g2);
    
    return PDF;

}


Double_t Gaussian(Double_t *x, Double_t *par){

    Double_t PDF = 0.0;
    Double_t g = 0.0;

    Double_t arg = (par[2] != 0.0) ? (x[0] - par[1])/(par[2]) : 0.0;

    g = exp(-0.5*arg*arg)/(par[2]*sqrt(2.0*TMath::Pi()));

    PDF = par[0]*g;
    
    return PDF;
}




//sum of background and peak function

Double_t fitFunction(Double_t *x, Double_t *par){

    return background(x,par)+doubleGaussian(x,&par[5]);    

}

void InvMass_test(){

    using std::cout;
    using std::endl;



    //TChain* T = new TChain("test_chain");

    TFile *f = TFile::Open("/st100-gr1/manca/PbPbData/229/0/output/PbPb_D0_Jpsi.root");
    TTree *T = (TTree*)f->Get("D0/DecayTree");

    TH1F *h1 = new TH1F("h1","Double Gaussian on Fourth Order Background;m_{p#pi}[GeV];Candidates",100,500,2500);
    TBranch *b_mass;

    TCanvas *c1 = new TCanvas("c1","c1",50,50,800,600);

    double Kplus_mass;
    double Piminus_mass;
    double Kplus_E;
    double Piminus_E;
    double Kplus_px,Kplus_py,Kplus_pz;
    double Piminus_px,Piminus_py,Piminus_pz;


    Int_t i,nentries,nbytes;
    long signalCand=0;

    const double_t peak = 1900;
    const double_t sigma = 0.00279288;
    const double_t binsize = (1.166-1.077)/100;

    c1->SetFillColor(33);
    c1->SetFrameFillColor(41);
    c1->SetGrid();

    T->SetBranchAddress("piminus_PX",&Piminus_px);
    T->SetBranchAddress("piminus_PY",&Piminus_py);
    T->SetBranchAddress("piminus_PZ",&Piminus_pz);
    T->SetBranchAddress("piminus_PE",&Piminus_E);

    T->SetBranchAddress("Kplus_PX",&Kplus_px);
    T->SetBranchAddress("Kplus_PY",&Kplus_py);
    T->SetBranchAddress("Kplus_PZ",&Kplus_pz);
    T->SetBranchAddress("Kplus_PE",&Kplus_E);


    nentries=(Int_t) T->GetEntries();


    for(i=0;i<nentries;i++){
       T->GetEntry(i);
       TLorentzVector* vec = new TLorentzVector(Piminus_px+Kplus_px,Piminus_py+Kplus_py,Piminus_pz+Kplus_pz,Piminus_E+Kplus_E);
       h1->Fill(vec->M());

   }

   h1->SetMarkerStyle(21);
   h1->SetMarkerSize(0.8);
   h1->SetStats(0);
   h1->Draw();


/*
   TF1 *fitFcn = new TF1("fitFcn",fitFunction,1.077,1.166,10);
   fitFcn->SetNpx(500);
   fitFcn->SetLineWidth(4);
   fitFcn->SetLineColor(kMagenta);

    //place limits on each parameter
   fitFcn->SetParLimits(9,0.0,1.0);
   fitFcn->SetParLimits(6,0.0,1.16);          
   fitFcn->SetParLimits(7,0.0,10);     
   fitFcn->SetParLimits(8,0.0,10);

   fitFcn->SetParameters(1,1,1,1,1,1,1,1,1,1);


   h1->Fit("fitFcn","0");

    //place initial values 
   fitFcn->SetParameter(6,1.116);
   fitFcn->SetParameter(7,0.004);
   fitFcn->SetParameter(8,0.004);

   h1->Fit("fitFcn","0");
   h1->Fit("fitFcn","0");
   h1->Fit("fitFcn","0");
   h1->Fit("fitFcn","0");
   h1->Fit("fitFcn","0");
   h1->Fit("fitFcn","0");
   h1->Fit("fitFcn","V+","ep");
*/

    //  improve the picture:



/*
   TF1 *backFcn = new TF1("backFcn",background,1.077,1.166,5);
   backFcn->SetLineColor(kRed);
   TF1 *signalFcn = new TF1("signalFcn",doubleGaussian,1.077,1.166,6);
   signalFcn->SetLineColor(kBlue);
   signalFcn->SetNpx(500);
   Double_t par[10];

   TF1 *g1 = new TF1("g1",Gaussian,-1000,1000,3);
   TF1 *g2 = new TF1("g2",Gaussian,-1000,1000,3);
   g1->SetLineColor(kGreen+2);
   g2->SetLineColor(kGreen+2);

    // writes the fit results into the par array
   fitFcn->GetParameters(par);

   backFcn->SetParameters(par);
   backFcn->Draw("same");

   signalFcn->SetParameters(&par[5]);
   signalFcn->Draw("same");

    //calculate the yield & average deviation
   g1->SetParameters(par[5]*par[9],par[6],par[7]);

   g2->SetParameters(par[5]*(1-par[9]),par[6],par[8]);



   g1->Draw("same");
   g2->Draw("same");



   Double_t y1 = g1->Integral(1,2);
   Double_t y2 = g2->Integral(1,2);




   Double_t sigma_avg = sqrt((y1/(y1+y2))*par[7]*par[7]+(y2/(y1+y2))*par[8]*par[8]);

   Double_t peak_sig = signalFcn->Integral(par[6]-2*sigma_avg,par[6]+2*sigma_avg);
   Double_t peak_bkg = backFcn->Integral(par[6]-2*sigma_avg,par[6]+2*sigma_avg);
   Double_t sideband1 = backFcn->Integral(1.077,par[6]-3*sigma_avg);
   Double_t sideband2_bkg = backFcn->Integral(par[6]+3*sigma_avg,1.166);
   Double_t sideband2_sig = signalFcn->Integral(par[6]+3*sigma_avg,1.166);






   std::cout << "average sigma : " << sigma_avg << std::endl;
   std::cout << "peak : " << par[6] << std::endl;

*/
    // draw the legend

/*   
   TLegend *legend=new TLegend(0.6,0.65,0.88,0.88);
   legend->SetTextFont(72);
   legend->SetTextSize(0.04);
   legend->AddEntry(h1,"Data","lpe"); 
   legend->AddEntry(backFcn,"Background(4th order)","l");
   legend->AddEntry(signalFcn,"Double Gaussian","l");
   legend->AddEntry(fitFcn,"Global Fit","l");
   legend->AddEntry(g1,"Underlying Gaussian","l");
   legend->Draw();
*/

    //PRINT SOME RESULTS
//   TLatex *latex=new TLatex(1.082,80000,Form("#splitline{#sigma_{avg} : %g}{peak : %g}",sigma_avg,par[6]));
//   latex->SetTextSize(0.045);
//   latex->DrawClone();
//   c1->Print("Mass_distribution_v4.bmp");



/*
    //Now do the signal fraction
   TAxis *axis = h1->GetXaxis();
   double_t xmin = par[6]-2*sigma_avg;
   double_t xmax = par[6]+2*sigma_avg;

   Int_t bmin = axis ->FindBin(xmin);
   Int_t bmax = axis ->FindBin(xmax);

   double_t width = h1->GetXaxis()->GetBinWidth(bmax);



   double integral = h1->Integral(bmin,bmax);
   integral -= h1->GetBinContent(bmin)*(xmin-axis->GetBinLowEdge(bmin))/axis->GetBinWidth(bmin);
   integral -= h1->GetBinContent(bmax)*(axis->GetBinUpEdge(bmax)-xmax)/axis->GetBinWidth(bmax);

   Double_t candidates = integral * binsize; 


   Double_t fraction = (candidates - peak_sig)/(sideband2_bkg);
   Double_t f_sig = (peak_sig)/(peak_sig+peak_bkg);

   cout<< candidates  << endl;
   cout<< peak_sig << endl;
   cout<< sideband2_bkg << endl;
   cout << peak_bkg << endl;
   cout << f_sig << endl;




   std::cout<< "fraction is " << fraction << std::endl;

*/

}
