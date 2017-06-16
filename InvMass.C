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

 TH1F *h1 = new TH1F("h1",";m_{K_{+}#pi_{-}}[MeV];Candidates",100,1800,2000);
 TBranch *b_mass;

 TCanvas *c1 = new TCanvas("c1","c1",50,50,800,600);

 double piminus_PX;
 double piminus_PY;
 double piminus_PZ;
 double piminus_PE;
 double piminus_PT;
 double piminus_PIDK;
 double piminus_IPCHI2_OWNPV;
 double piminus_IP_OWNPV;
 double Kplus_PX;
 double Kplus_PY;
 double Kplus_PZ;
 double Kplus_PE;
 double Kplus_PT;
 double Kplus_PIDK;
 double Kplus_IPCHI2_OWNPV;
 double Kplus_IP_OWNPV;
 double D0_TAU;
 double D0_ENDVERTEX_CHI2;
 double D0_IPCHI2_OWNPV;
 double D0_PT;

 Int_t i,nentries,nbytes;
 long signalCand=0;

 const double_t peak = 1900;
 const double_t sigma = 0.00279288;
 const double_t binsize = (1.166-1.077)/100;

// c1->SetFillColor(33);
// c1->SetFrameFillColor(41);
 c1->SetGrid();

 T->SetBranchAddress("piminus_PX",&piminus_PX);
 T->SetBranchAddress("piminus_PY",&piminus_PY);
 T->SetBranchAddress("piminus_PZ",&piminus_PZ);
 T->SetBranchAddress("piminus_PE",&Piminus_PE);
 T->SetBranchAddress("piminus_PT",&Piminus_PT);

 T->SetBranchAddress("piminus_PIDK",&piminus_PIDK);
 T->SetBranchAddress("piminus_IPCHI2_OWNPV",&piminus_IPCHI2_OWNPV);
 T->SetBranchAddress("piminus_IP_OWNPV",&piminus_IP_OWNPV);


 T->SetBranchAddress("Kplus_PX",&Kplus_PX);
 T->SetBranchAddress("Kplus_PY",&Kplus_PY);
 T->SetBranchAddress("Kplus_PZ",&Kplus_PZ);
 T->SetBranchAddress("Kplus_PE",&Kplus_PE);
 T->SetBranchAddress("Kplus_PT",&Kplus_PT);

 T->SetBranchAddress("Kplus_PIDK",&Kplus_PIDK);

 T->SetBranchAddress("Kplus_IPCHI2_OWNPV",&Kplus_IPCHI2_OWNPV);

 T->SetBranchAddress("Kplus_IP_OWNPV",&Kplus_IP_OWNPV);



 T->SetBranchAddress("D0_TAU",&D0_TAU);

 T->SetBranchAddress("D0_ENDVERTEX_CHI2",&D0_ENDVERTEX_CHI2);
 T->SetBranchAddress("D0_IPCHI2_OWNPV",&D0_IPCHI2_OWNPV);




 T->SetBranchAddress("D0_PT",&D0_PT);







 nentries=(Int_t) T->GetEntries();


 for(i=0;i<nentries;i++){
   T->GetEvent(i);

   if( *piminus_PT < 400. ) return ;
   if( *Kplus_PT < 400. ) return ;

   if( *piminus_PIDK > -1. ) return ;
   if( *Kplus_PIDK < 6. ) return ;

   if( *piminus_IPCHI2_OWNPV<9 ) return ;
   if( *Kplus_IPCHI2_OWNPV<9 ) return ;

  if( *piminus_IP_OWNPV > 3. ) return ;
   if( *Kplus_IP_OWNPV > 3. ) return ;
  // cut on the D0
  //if( *D0_DIRA_OWNPV < .9999 ) return 0;
   if( *D0_TAU*1000 < 0.5  ) return ;

  // cut on nPV
   if( *D0_ENDVERTEX_CHI2>4 ) return ;
   if( *D0_IPCHI2_OWNPV >4 ) return ;



   TLorentzVector* vec = new TLorentzVector(piminus_PX+Kplus_PX,piminus_PY+Kplus_PY,piminus_PZ+Kplus_PZ,piminus_PE+Kplus_PE);
   

   h1->Fill(vec->M());

 }

 h1->SetMarkerStyle(21);
 h1->SetMarkerSize(0.8);
 h1->SetStats(0);
 h1->Draw();



}
