//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Jul 20 13:28:13 2017 by ROOT version 6.08/06
// from TTree EventTuple/EventTuple
// found on file: /st100-gr1/manca/PbPbData/71/0/output/DstSummary.root
//////////////////////////////////////////////////////////

#ifndef MBselector_h
#define MBselector_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TTreeReader.h>
#include <TTreeReaderValue.h>
#include <TTreeReaderArray.h>

// Headers needed by this particular selector


class MBselector : public TSelector {
public :
   TTreeReader     fReader;  //!the tree reader
   TTree          *fChain = 0;   //!pointer to the analyzed TTree or TChain

   // Readers to access the data (delete the ones you do not need).
   TTreeReaderValue<ULong64_t> EventInSequence = {fReader, "EventInSequence"};
   TTreeReaderValue<UInt_t> runNumber = {fReader, "runNumber"};
   TTreeReaderValue<ULong64_t> eventNumber = {fReader, "eventNumber"};
   TTreeReaderValue<UInt_t> BCID = {fReader, "BCID"};
   TTreeReaderValue<Int_t> BCType = {fReader, "BCType"};
   TTreeReaderValue<UInt_t> OdinTCK = {fReader, "OdinTCK"};
   TTreeReaderValue<UInt_t> L0DUTCK = {fReader, "L0DUTCK"};
   TTreeReaderValue<UInt_t> HLT1TCK = {fReader, "HLT1TCK"};
   TTreeReaderValue<UInt_t> HLT2TCK = {fReader, "HLT2TCK"};
   TTreeReaderValue<ULong64_t> GpsTime = {fReader, "GpsTime"};
   TTreeReaderValue<Short_t> Polarity = {fReader, "Polarity"};
   TTreeReaderValue<Double_t> eSPD = {fReader, "eSPD"};
   TTreeReaderValue<Double_t> fSPD = {fReader, "fSPD"};
   TTreeReaderValue<Double_t> ePrs = {fReader, "ePrs"};
   TTreeReaderValue<Double_t> fPrs = {fReader, "fPrs"};
   TTreeReaderValue<Double_t> eEcal = {fReader, "eEcal"};
   TTreeReaderValue<Double_t> etEcal = {fReader, "etEcal"};
   TTreeReaderValue<Double_t> fEcal = {fReader, "fEcal"};
   TTreeReaderValue<Double_t> eHcal = {fReader, "eHcal"};
   TTreeReaderValue<Double_t> etHcal = {fReader, "etHcal"};
   TTreeReaderValue<Double_t> fHcal = {fReader, "fHcal"};
   TTreeReaderValue<Int_t> nPVs = {fReader, "nPVs"};
   TTreeReaderValue<Int_t> nTracks = {fReader, "nTracks"};
   TTreeReaderValue<Int_t> nLongTracks = {fReader, "nLongTracks"};
   TTreeReaderValue<Int_t> nDownstreamTracks = {fReader, "nDownstreamTracks"};
   TTreeReaderValue<Int_t> nUpstreamTracks = {fReader, "nUpstreamTracks"};
   TTreeReaderValue<Int_t> nVeloTracks = {fReader, "nVeloTracks"};
   TTreeReaderValue<Int_t> nTTracks = {fReader, "nTTracks"};
   TTreeReaderValue<Int_t> nBackTracks = {fReader, "nBackTracks"};
   TTreeReaderValue<Int_t> nRich1Hits = {fReader, "nRich1Hits"};
   TTreeReaderValue<Int_t> nRich2Hits = {fReader, "nRich2Hits"};
   TTreeReaderValue<Int_t> nVeloClusters = {fReader, "nVeloClusters"};
   TTreeReaderValue<Int_t> nITClusters = {fReader, "nITClusters"};
   TTreeReaderValue<Int_t> nTTClusters = {fReader, "nTTClusters"};
   TTreeReaderValue<Int_t> nOTClusters = {fReader, "nOTClusters"};
   TTreeReaderValue<Int_t> nSPDHits = {fReader, "nSPDHits"};
   TTreeReaderValue<Int_t> nMuonCoordsS0 = {fReader, "nMuonCoordsS0"};
   TTreeReaderValue<Int_t> nMuonCoordsS1 = {fReader, "nMuonCoordsS1"};
   TTreeReaderValue<Int_t> nMuonCoordsS2 = {fReader, "nMuonCoordsS2"};
   TTreeReaderValue<Int_t> nMuonCoordsS3 = {fReader, "nMuonCoordsS3"};
   TTreeReaderValue<Int_t> nMuonCoordsS4 = {fReader, "nMuonCoordsS4"};
   TTreeReaderValue<Int_t> nMuonTracks = {fReader, "nMuonTracks"};
   TTreeReaderValue<Int_t> nPV = {fReader, "nPV"};
   TTreeReaderArray<Float_t> PVX = {fReader, "PVX"};
   TTreeReaderArray<Float_t> PVY = {fReader, "PVY"};
   TTreeReaderArray<Float_t> PVZ = {fReader, "PVZ"};
   TTreeReaderArray<Float_t> PVXERR = {fReader, "PVXERR"};
   TTreeReaderArray<Float_t> PVYERR = {fReader, "PVYERR"};
   TTreeReaderArray<Float_t> PVZERR = {fReader, "PVZERR"};
   TTreeReaderArray<Float_t> PVCHI2 = {fReader, "PVCHI2"};
   TTreeReaderArray<Float_t> PVNDOF = {fReader, "PVNDOF"};
   TTreeReaderArray<Float_t> PVNTRACKS = {fReader, "PVNTRACKS"};
   TTreeReaderValue<Int_t> rVeloClusters = {fReader, "rVeloClusters"};
   TTreeReaderValue<Int_t> rPUClusters = {fReader, "rPUClusters"};
   TTreeReaderArray<Float_t> rClustersPerSensor = {fReader, "rClustersPerSensor"};
   TTreeReaderValue<Int_t> B00 = {fReader, "B00"};
   TTreeReaderValue<Int_t> B00ref = {fReader, "B00ref"};
   TTreeReaderValue<Int_t> B01 = {fReader, "B01"};
   TTreeReaderValue<Int_t> B01ref = {fReader, "B01ref"};
   TTreeReaderValue<Int_t> B02 = {fReader, "B02"};
   TTreeReaderValue<Int_t> B02ref = {fReader, "B02ref"};
   TTreeReaderValue<Int_t> B03 = {fReader, "B03"};
   TTreeReaderValue<Int_t> B03ref = {fReader, "B03ref"};
   TTreeReaderValue<Int_t> B10 = {fReader, "B10"};
   TTreeReaderValue<Int_t> B10ref = {fReader, "B10ref"};
   TTreeReaderValue<Int_t> B11 = {fReader, "B11"};
   TTreeReaderValue<Int_t> B11ref = {fReader, "B11ref"};
   TTreeReaderValue<Int_t> B12 = {fReader, "B12"};
   TTreeReaderValue<Int_t> B12ref = {fReader, "B12ref"};
   TTreeReaderValue<Int_t> B13 = {fReader, "B13"};
   TTreeReaderValue<Int_t> B13ref = {fReader, "B13ref"};
   TTreeReaderValue<Int_t> B20 = {fReader, "B20"};
   TTreeReaderValue<Int_t> B20ref = {fReader, "B20ref"};
   TTreeReaderValue<Int_t> B21 = {fReader, "B21"};
   TTreeReaderValue<Int_t> B21ref = {fReader, "B21ref"};
   TTreeReaderValue<Int_t> B22 = {fReader, "B22"};
   TTreeReaderValue<Int_t> B22ref = {fReader, "B22ref"};
   TTreeReaderValue<Int_t> B23 = {fReader, "B23"};
   TTreeReaderValue<Int_t> B23ref = {fReader, "B23ref"};
   TTreeReaderValue<Int_t> F10 = {fReader, "F10"};
   TTreeReaderValue<Int_t> F10ref = {fReader, "F10ref"};
   TTreeReaderValue<Int_t> F11 = {fReader, "F11"};
   TTreeReaderValue<Int_t> F11ref = {fReader, "F11ref"};
   TTreeReaderValue<Int_t> F12 = {fReader, "F12"};
   TTreeReaderValue<Int_t> F12ref = {fReader, "F12ref"};
   TTreeReaderValue<Int_t> F13 = {fReader, "F13"};
   TTreeReaderValue<Int_t> F13ref = {fReader, "F13ref"};
   TTreeReaderValue<Int_t> F20 = {fReader, "F20"};
   TTreeReaderValue<Int_t> F20ref = {fReader, "F20ref"};
   TTreeReaderValue<Int_t> F21 = {fReader, "F21"};
   TTreeReaderValue<Int_t> F21ref = {fReader, "F21ref"};
   TTreeReaderValue<Int_t> F22 = {fReader, "F22"};
   TTreeReaderValue<Int_t> F22ref = {fReader, "F22ref"};
   TTreeReaderValue<Int_t> F23 = {fReader, "F23"};
   TTreeReaderValue<Int_t> F23ref = {fReader, "F23ref"};
   TTreeReaderValue<Int_t> L0Global = {fReader, "L0Global"};
   TTreeReaderValue<UInt_t> Hlt1Global = {fReader, "Hlt1Global"};
   TTreeReaderValue<UInt_t> Hlt2Global = {fReader, "Hlt2Global"};
   TTreeReaderValue<Int_t> L0MUONDecision = {fReader, "L0MUONDecision"};
   TTreeReaderValue<Int_t> L0CALODecision = {fReader, "L0CALODecision"};
   TTreeReaderValue<Int_t> L0SPDDecision = {fReader, "L0SPDDecision"};
   TTreeReaderValue<Int_t> L0PUDecisionHlt1DiMuonHighMassDecision = {fReader, "L0PUDecisionHlt1DiMuonHighMassDecision"};
   TTreeReaderValue<UInt_t> L0nSelections = {fReader, "L0nSelections"};
   TTreeReaderValue<Int_t> Hlt1CalibMuonAlignJpsiDecision = {fReader, "Hlt1CalibMuonAlignJpsiDecision"};
   TTreeReaderValue<Int_t> Hlt1BBHighMultDecision = {fReader, "Hlt1BBHighMultDecision"};
   TTreeReaderValue<Int_t> Hlt1BBL0CALODecision = {fReader, "Hlt1BBL0CALODecision"};
   TTreeReaderValue<Int_t> Hlt1BBL0MUONDecision = {fReader, "Hlt1BBL0MUONDecision"};
   TTreeReaderValue<Int_t> Hlt1BBL0PUDecision = {fReader, "Hlt1BBL0PUDecision"};
   TTreeReaderValue<Int_t> Hlt1BBL0SPDDecision = {fReader, "Hlt1BBL0SPDDecision"};
   TTreeReaderValue<Int_t> Hlt1BBL0SPDLowMultDecision = {fReader, "Hlt1BBL0SPDLowMultDecision"};
   TTreeReaderValue<Int_t> Hlt1BBMicroBiasVeloDecision = {fReader, "Hlt1BBMicroBiasVeloDecision"};
   TTreeReaderValue<UInt_t> Hlt1nSelections = {fReader, "Hlt1nSelections"};
   TTreeReaderValue<UInt_t> Hlt2nSelections = {fReader, "Hlt2nSelections"};
   TTreeReaderValue<Int_t> MaxRoutingBits = {fReader, "MaxRoutingBits"};
   TTreeReaderArray<Float_t> RoutingBits = {fReader, "RoutingBits"};


   MBselector(TTree * /*tree*/ =0) { }
   virtual ~MBselector() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   ClassDef(MBselector,0);

};

#endif

#ifdef MBselector_cxx
void MBselector::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the reader is initialized.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   fReader.SetTree(tree);
}

Bool_t MBselector::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}


#endif // #ifdef MBselector_cxx
