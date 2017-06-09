#include "TH1.h"
#include "TMath.h"
#include "TF1.h"
#include "TLegend.h"
#include "TCanvas.h"
#include "TLatex.h"
#include "TLorentzVector.h"


void InvMass(){

  using std::cout;
  using std::endl;



  TChain* T = new TChain("D0/DecayTree");

  for (int i = 0; i < 259; ++i)
  {
   T->Add(Form("/st100-gr1/manca/PbPbData/229/%d/output/PbPb_D0_Jpsi.root",i));
 }

// Event* event = new Event();
// T->SetBranchAddress("event", &event);
    //  TFile *f = TFile::Open("/st100-gr1/manca/PbPbData/229/0/output/PbPb_D0_Jpsi.root");
    //TTree *T = (TTree*)f->Get("D0/DecayTree");

 TH1F *h1 = new TH1F("h1",";m_{K_{+}#pi_{-}}[MeV];Candidates",100,500,2500);
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
   T->GetEvent(i);


   TLorentzVector* vec = new TLorentzVector(Piminus_px+Kplus_px,Piminus_py+Kplus_py,Piminus_pz+Kplus_pz,Piminus_E+Kplus_E);
   h1->Fill(vec->M());

 }

 h1->SetMarkerStyle(21);
 h1->SetMarkerSize(0.8);
 h1->SetStats(0);
 h1->Draw();



}
