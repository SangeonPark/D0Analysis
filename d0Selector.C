#define d0Selector_cxx
// The class definition in d0Selector.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.


// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// root> T->Process("d0Selector.C")
// root> T->Process("d0Selector.C","some options")
// root> T->Process("d0Selector.C+")
//


#include "d0Selector.h"
#include <TH2.h>
#include <TStyle.h>
#include <THnSparse.h>
#include <TFile.h>
#include <TH1D.h>
#include <TH1F.h>
#include <TMath.h>
#include <Riostream.h>
#include <TNtuple.h>
#include <TLorentzVector.h>


void d0Selector::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();
}

void d0Selector::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

  fStrHlt = new TString[knVarHlt]; 
  TString listHlt[] ={
    "D0_Candidates_all" 
  };
  for( int i=0;i<knVarHlt;i++) fStrHlt[i] = listHlt[i];

  fVarHlt = new Bool_t*[knVarHlt];
  Bool_t D0ALLCAND = kTRUE;
  Bool_t *varHlt[] = {
    &D0ALLCAND                              // always true
  };
  for( int i=0;i<knVarHlt;i++) fVarHlt[i] = varHlt[i];
  // #################################################
  // Histograms
  // #################################################

  // MM
  Int_t nBins_MM       = 75;
  Double_t MM_low_edge = 1600.;
  Double_t MM_up_edge  = 2200.;
  hMM = new TH1D*[knVarHlt];
  for( int j=0; j< knVarHlt;j++){
    hMM[j] = new TH1D(Form("hMM_%s_BC%d", fStrHlt[j].Data(),3),
                      Form("MM - %s - BC%d", fStrHlt[j].Data(),3),
                      nBins_MM, MM_low_edge, MM_up_edge);
    hMM[j]->GetXaxis()->SetTitle("#pi K invariant mass (MeV/c^{2})");
    hMM[j]->GetYaxis()->SetTitle(Form("Events / %.1f MeV/c^{2}",(MM_up_edge-MM_low_edge)/nBins_MM));
    
    GetOutputList()->Add( hMM[ j ] );  
  }

  Int_t nBins_PT        = 10;
  Double_t PT_low_edge = 0.;
  Double_t PT_up_edge  = 1e4;
  
  Int_t nBins_Y       = 2;
  Double_t Y_low_edge = 2.;
  Double_t Y_up_edge  = 4.5;

  Int_t nBins_OWNPV_Z        = 100;
  Double_t OWNPV_Z_low_edge = -200.;
  Double_t OWNPV_Z_up_edge  =  200.;

  Int_t nBins_OWNPV_R        = 80;
  Double_t OWNPV_R_low_edge =  0.25;
  Double_t OWNPV_R_up_edge  =  1.05;

  Int_t nBins_nVeloClusters        = 20;
  Double_t nVeloClusters_low_edge =  0.;
  Double_t nVeloClusters_up_edge  =  20000.;

  enum {                   kMMaxis,      kPTaxis,     kYaxis,           kZaxis,            kRaxis,          kVeloClusters, kNaxis};
  Int_t bins[]  = {       nBins_MM,     nBins_PT,    nBins_Y,    nBins_OWNPV_Z,     nBins_OWNPV_R,    nBins_nVeloClusters    }; 
  Double_t lbins[] = { MM_low_edge,  PT_low_edge, Y_low_edge, OWNPV_Z_low_edge,  OWNPV_R_low_edge, nVeloClusters_low_edge    }; 
  Double_t hbins[] = {  MM_up_edge,   PT_up_edge,  Y_up_edge,  OWNPV_Z_up_edge,   OWNPV_R_up_edge,  nVeloClusters_up_edge    }; 

  hSparse = new THnSparseD*[knVarHlt];
  for( int j=0; j< knVarHlt;j++){
    hSparse[j] = new THnSparseD( Form("hSparse_%s_BC%d",fStrHlt[j].Data(),3),
                            Form("hSparse_%s_BC%d",fStrHlt[j].Data(),3),
                            kNaxis, bins, lbins,hbins);
     hSparse[j]->GetAxis( kMMaxis )->SetTitle( "MM (D^{0}#rightarrow K #pi) (MeV/c^{2})");
     hSparse[j]->GetAxis( kPTaxis )->SetTitle( "PT (D^{0}#rightarrow K #pi) (MeV/c)");
     hSparse[j]->GetAxis( kYaxis )->SetTitle( "rapidity (D^{0}#rightarrow K #pi)");
     hSparse[j]->GetAxis( kZaxis )->SetTitle( "OWNPV_Z (D^{0}#rightarrow K #pi) (mm)");
     hSparse[j]->GetAxis( kVeloClusters )->SetTitle( "nVeloClusters (D^{0}#rightarrow K #pi)");
     
    GetOutputList()->Add( hSparse[ j ] );  
  }

  TNtuple *nt = new TNtuple("nt","nt","MM:PT:Y:Z:DIRA:KplusPIDK:piminusPIDK:Hcal:Ecal:Velo");
  GetOutputList()->Add(nt); 
  // general plots
  Int_t nBins_Time = 5206;
  Double_t Time_low_edge = 1448453220;
  Double_t Time_up_edge  = 1450015074;
  TH1D *hTime = new TH1D("hTime","Time", nBins_Time, Time_low_edge, Time_up_edge);

  hTime->GetXaxis()->SetTitle("time (s)"); 
  hTime->GetYaxis()->SetTitle(Form("entries/(%.0f s)",(Time_up_edge - Time_low_edge)/nBins_Time)); 
  GetOutputList()->Add( hTime );  

  TH1D *hInvMass = new TH1D("hInvMass",";m_{K_{+}#pi_{-}}[MeV];Candidates",100,1800,2000);
  GetOutputList()->Add( hInvMass );  


  Int_t nBins_Candidates = 100;
  Double_t Candidates_low_edge = 0;
  Double_t Candidates_up_edge  = 100;
  TH2D *hCandidates = new TH2D("hCandidates_vs_VeloClusters","Candidates vs Velo",
                                nBins_nVeloClusters, nVeloClusters_low_edge, nVeloClusters_up_edge,
                                nBins_Candidates, Candidates_low_edge, Candidates_up_edge
                        );
  GetOutputList()->Add( hCandidates );  

  TH1F *hruns = new TH1F("hruns","runs",169618-168487,168487,169618);
  GetOutputList()->Add( hruns );  
  
}

Bool_t d0Selector::Process(Long64_t entry)
{
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // When processing keyed objects with PROOF, the object is already loaded
   // and is available via the fObject pointer.
   //
   // This function should contain the \"body\" of the analysis. It can contain
   // simple or elaborate selection criteria, run algorithms on the data
   // of the event and typically fill histograms.
   //
   // The processing can be stopped by calling Abort().
   //
   // Use fStatus to set the return value of TTree::Process().
   //
   // The return value is currently not used.

  TNtuple *nt  = static_cast<TNtuple*>(GetOutputList()->FindObject("nt")); 

    TH1D *hInvMass = dynamic_cast<TH1D*>( GetOutputList()->FindObject("hInvMass") );

   fReader.SetEntry(entry);

  if( entry%5000 == 0) Printf( "%lld", entry);
  *fVarHlt[kD0CANDALL] = kTRUE; // just to be sure that is always true

  if(*nLongTracks !=2 ) return kFALSE;
  // if not a BCType3 skip
  //
  if( *BCType != 3 ) return kFALSE;

  // ----------------------------------
  // General plots before the cuts, only filled for the first candidate
  if( *nCandidate == 0 ){
    TH1D *hTime = dynamic_cast<TH1D*>( GetOutputList()->FindObject("hTime") );
    hTime->Fill( *GpsTime/1000000 );

    TH1F *hruns = dynamic_cast<TH1F*>( GetOutputList()->FindObject("hruns") );
    hruns->Fill( *runNumber );

    TH2D *hCandidates = dynamic_cast<TH2D*>( GetOutputList()->FindObject("hCandidates_vs_VeloClusters") );
    hCandidates->Fill( *nVeloClusters, *totCandidates );
    //for( int j=0; j< knVarHlt;j++){
      //hnSPDHits[GetHPos(j,BCType-1)]->Fill( nSPDHits );
      //hnVeloTracks[GetHPos(j,BCType-1)]->Fill( nVeloTracks );
    //}
  }
  
  // SELECT RUN: TODO make it more general... please :)
  //
  //if( runNumber < 161108 || runNumber > 161123 ) return 0; // 0x00FD024F
  //if( runNumber < 161189 || runNumber > 161204 ) return 0;   // 0x00FF024F
  //Printf(" yeah");

  // ----------------------------------
  // CUTS
  //cut on daughters' pT

  /*
  if( *piminus_PT < 400. ) return 0;
  if( *Kplus_PT < 400. ) return 0;

  if( *piminus_PIDK > -1. ) return 0;
  if( *Kplus_PIDK < 6. ) return 0;

  if( *piminus_IPCHI2_OWNPV<9 ) return 0;
  if( *Kplus_IPCHI2_OWNPV<9 ) return 0;

  if( *piminus_IP_OWNPV > 3. ) return 0;
  if( *Kplus_IP_OWNPV > 3. ) return 0;
  // cut on the D0
  //if( *D0_DIRA_OWNPV < .9999 ) return 0;
  if( *D0_TAU*1000 < 0.5  ) return 0;

  // cut on nPV
  if( *D0_ENDVERTEX_CHI2>4 ) return 0;
  if( *D0_IPCHI2_OWNPV >4 ) return 0;

  */



  double d0_ownpv_r = TMath::Sqrt( (*D0_OWNPV_X)*(*D0_OWNPV_X)+(*D0_OWNPV_Y)*(*D0_OWNPV_Y) );
  Double_t d0var[] = {
      *D0_MM, 
      *D0_PT,*D0_Y, 
      *D0_OWNPV_Z, 
      d0_ownpv_r, 
      static_cast<Double_t>(*nVeloClusters) };

  //Printf(" ok %d ", BCType);
  *fVarHlt[kD0CANDALL] = kTRUE; // just to be sure that is always true
  for( int j=0; j< knVarHlt;j++){
    if( *fVarHlt[j] == kTRUE ){
        hMM[j]->Fill( *D0_MM );
        hSparse[j]->Fill(d0var );
    }
  }
  nt->Fill( 
      *D0_MM,
      *D0_PT,
      *D0_Y,
      *D0_OWNPV_Z,
      *D0_DIRA_OWNPV,
      *Kplus_PIDK,
      *piminus_PIDK,
      *eHcal, *eEcal, *nVeloClusters );

  TLorentzVector* vec = new TLorentzVector(*piminus_PX+*Kplus_PX,*piminus_PY+*Kplus_PY,*piminus_PZ+*Kplus_PZ,*piminus_PE+*Kplus_PE);
  hInvMass->Fill(vec->M());


   return kTRUE;
}

void d0Selector::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void d0Selector::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

  TString strHlt[] ={
    "D0_Candidates_all" 
  };
  

  TNtuple *nt  = static_cast<TNtuple*>(GetOutputList()->FindObject("nt")); 
  // +++++++++++++++++++++++++++++++++++++++++++++++++
  // prepare for saving histos in a file
  TFile *outfile = TFile::Open("histos.root","recreate");

  nt->SetDirectory( outfile );
  nt->Write(); 
  // write histos
  // ------------

  for( Int_t j = 0;j<knVarHlt;j++){
    TH1D *tmp = dynamic_cast<TH1D*>( GetOutputList()->FindObject(Form("hMM_%s_BC%d", strHlt[j].Data(),3))->Clone() );
    tmp->SetDirectory( outfile );
    tmp->Write();
  
    THnSparse *tS = dynamic_cast<THnSparse*>( GetOutputList()->FindObject(Form("hSparse_%s_BC%d", strHlt[j].Data(),3))->Clone() );
    //tS->SetDirectory( outfile );
    tS->Write();
  }
  outfile->cd();

  TH1D *hTime = dynamic_cast<TH1D*>( GetOutputList()->FindObject("hTime")->Clone() );
  hTime->SetDirectory( outfile );
  hTime->Write();

  TH2D *hCandidates = dynamic_cast<TH2D*>( GetOutputList()->FindObject("hCandidates_vs_VeloClusters")->Clone() );
  hCandidates->SetDirectory( outfile );
  hCandidates->Write();

  TH1D *hInvMass = dynamic_cast<TH1D*>( GetOutputList()->FindObject("hInvMass")->Clone() );
  hInvMass->SetDirectory( outfile );
  hInvMass->Write();

  TH1F *hruns = dynamic_cast<TH1F*>( GetOutputList()->FindObject("hruns") );
  hruns->SetDirectory( outfile );
  hruns->Write();
  hruns->Draw();

  ofstream runs("runs.out");
  for( int i=0;i<=hruns->GetNbinsX();i++){
    if( hruns->GetBinContent( i ) > 0 ){
      runs << hruns->GetXaxis()->GetBinLowEdge(i)<< endl;
    }
  }
  runs.close();
}
