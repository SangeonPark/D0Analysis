//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Sun Nov 26 04:00:03 2017 by ROOT version 6.10/06
// from TTree MCDecayTree/MCDecayTree
// found on file: Tuple_d0_simu_Pbp.root
//////////////////////////////////////////////////////////

#ifndef MCGenSelector_h
#define MCGenSelector_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TTreeReader.h>
#include <TTreeReaderValue.h>
#include <TTreeReaderArray.h>

// Headers needed by this particular selector


class MCGenSelector : public TSelector {
public :
   TTreeReader     fReader;  //!the tree reader
   TTree          *fChain = 0;   //!pointer to the analyzed TTree or TChain

   // Readers to access the data (delete the ones you do not need).
   TTreeReaderValue<Double_t> D0_TRUECosTheta = {fReader, "D0_TRUECosTheta"};
   TTreeReaderValue<Int_t> D0_MC_MOTHER_ID = {fReader, "D0_MC_MOTHER_ID"};
   TTreeReaderValue<Int_t> D0_MC_MOTHER_KEY = {fReader, "D0_MC_MOTHER_KEY"};
   TTreeReaderValue<Int_t> D0_MC_GD_MOTHER_ID = {fReader, "D0_MC_GD_MOTHER_ID"};
   TTreeReaderValue<Int_t> D0_MC_GD_MOTHER_KEY = {fReader, "D0_MC_GD_MOTHER_KEY"};
   TTreeReaderValue<Int_t> D0_MC_GD_GD_MOTHER_ID = {fReader, "D0_MC_GD_GD_MOTHER_ID"};
   TTreeReaderValue<Int_t> D0_MC_GD_GD_MOTHER_KEY = {fReader, "D0_MC_GD_GD_MOTHER_KEY"};
   TTreeReaderValue<Double_t> D0_TRUEP_E = {fReader, "D0_TRUEP_E"};
   TTreeReaderValue<Double_t> D0_TRUEP_X = {fReader, "D0_TRUEP_X"};
   TTreeReaderValue<Double_t> D0_TRUEP_Y = {fReader, "D0_TRUEP_Y"};
   TTreeReaderValue<Double_t> D0_TRUEP_Z = {fReader, "D0_TRUEP_Z"};
   TTreeReaderValue<Double_t> D0_TRUEPT = {fReader, "D0_TRUEPT"};
   TTreeReaderValue<Double_t> D0_TRUEORIGINVERTEX_X = {fReader, "D0_TRUEORIGINVERTEX_X"};
   TTreeReaderValue<Double_t> D0_TRUEORIGINVERTEX_Y = {fReader, "D0_TRUEORIGINVERTEX_Y"};
   TTreeReaderValue<Double_t> D0_TRUEORIGINVERTEX_Z = {fReader, "D0_TRUEORIGINVERTEX_Z"};
   TTreeReaderValue<Double_t> D0_TRUEENDVERTEX_X = {fReader, "D0_TRUEENDVERTEX_X"};
   TTreeReaderValue<Double_t> D0_TRUEENDVERTEX_Y = {fReader, "D0_TRUEENDVERTEX_Y"};
   TTreeReaderValue<Double_t> D0_TRUEENDVERTEX_Z = {fReader, "D0_TRUEENDVERTEX_Z"};
   TTreeReaderValue<Bool_t> D0_TRUEISSTABLE = {fReader, "D0_TRUEISSTABLE"};
   TTreeReaderValue<Double_t> D0_TRUETAU = {fReader, "D0_TRUETAU"};
   TTreeReaderValue<Int_t> D0_Reconstructible = {fReader, "D0_Reconstructible"};
   TTreeReaderValue<Int_t> D0_Reconstructed = {fReader, "D0_Reconstructed"};
   TTreeReaderValue<Int_t> D0_ProtoParticles = {fReader, "D0_ProtoParticles"};
   TTreeReaderArray<Float_t> D0_PP_PX = {fReader, "D0_PP_PX"};
   TTreeReaderArray<Float_t> D0_PP_PY = {fReader, "D0_PP_PY"};
   TTreeReaderArray<Float_t> D0_PP_PZ = {fReader, "D0_PP_PZ"};
   TTreeReaderArray<Float_t> D0_PP_Weight = {fReader, "D0_PP_Weight"};
   TTreeReaderArray<Float_t> D0_PP_tr_pchi2 = {fReader, "D0_PP_tr_pchi2"};
   TTreeReaderArray<Float_t> D0_PP_DLLe = {fReader, "D0_PP_DLLe"};
   TTreeReaderArray<Float_t> D0_PP_DLLk = {fReader, "D0_PP_DLLk"};
   TTreeReaderArray<Float_t> D0_PP_DLLp = {fReader, "D0_PP_DLLp"};
   TTreeReaderArray<Float_t> D0_PP_DLLmu = {fReader, "D0_PP_DLLmu"};
   TTreeReaderValue<Double_t> Kp_TRUECosTheta = {fReader, "Kp_TRUECosTheta"};
   TTreeReaderValue<Int_t> Kp_MC_MOTHER_ID = {fReader, "Kp_MC_MOTHER_ID"};
   TTreeReaderValue<Int_t> Kp_MC_MOTHER_KEY = {fReader, "Kp_MC_MOTHER_KEY"};
   TTreeReaderValue<Int_t> Kp_MC_GD_MOTHER_ID = {fReader, "Kp_MC_GD_MOTHER_ID"};
   TTreeReaderValue<Int_t> Kp_MC_GD_MOTHER_KEY = {fReader, "Kp_MC_GD_MOTHER_KEY"};
   TTreeReaderValue<Int_t> Kp_MC_GD_GD_MOTHER_ID = {fReader, "Kp_MC_GD_GD_MOTHER_ID"};
   TTreeReaderValue<Int_t> Kp_MC_GD_GD_MOTHER_KEY = {fReader, "Kp_MC_GD_GD_MOTHER_KEY"};
   TTreeReaderValue<Double_t> Kp_TRUEP_E = {fReader, "Kp_TRUEP_E"};
   TTreeReaderValue<Double_t> Kp_TRUEP_X = {fReader, "Kp_TRUEP_X"};
   TTreeReaderValue<Double_t> Kp_TRUEP_Y = {fReader, "Kp_TRUEP_Y"};
   TTreeReaderValue<Double_t> Kp_TRUEP_Z = {fReader, "Kp_TRUEP_Z"};
   TTreeReaderValue<Double_t> Kp_TRUEPT = {fReader, "Kp_TRUEPT"};
   TTreeReaderValue<Double_t> Kp_TRUEORIGINVERTEX_X = {fReader, "Kp_TRUEORIGINVERTEX_X"};
   TTreeReaderValue<Double_t> Kp_TRUEORIGINVERTEX_Y = {fReader, "Kp_TRUEORIGINVERTEX_Y"};
   TTreeReaderValue<Double_t> Kp_TRUEORIGINVERTEX_Z = {fReader, "Kp_TRUEORIGINVERTEX_Z"};
   TTreeReaderValue<Double_t> Kp_TRUEENDVERTEX_X = {fReader, "Kp_TRUEENDVERTEX_X"};
   TTreeReaderValue<Double_t> Kp_TRUEENDVERTEX_Y = {fReader, "Kp_TRUEENDVERTEX_Y"};
   TTreeReaderValue<Double_t> Kp_TRUEENDVERTEX_Z = {fReader, "Kp_TRUEENDVERTEX_Z"};
   TTreeReaderValue<Bool_t> Kp_TRUEISSTABLE = {fReader, "Kp_TRUEISSTABLE"};
   TTreeReaderValue<Double_t> Kp_TRUETAU = {fReader, "Kp_TRUETAU"};
   TTreeReaderValue<Int_t> Kp_Reconstructible = {fReader, "Kp_Reconstructible"};
   TTreeReaderValue<Int_t> Kp_Reconstructed = {fReader, "Kp_Reconstructed"};
   TTreeReaderValue<Int_t> Kp_ProtoParticles = {fReader, "Kp_ProtoParticles"};
   TTreeReaderArray<Float_t> Kp_PP_PX = {fReader, "Kp_PP_PX"};
   TTreeReaderArray<Float_t> Kp_PP_PY = {fReader, "Kp_PP_PY"};
   TTreeReaderArray<Float_t> Kp_PP_PZ = {fReader, "Kp_PP_PZ"};
   TTreeReaderArray<Float_t> Kp_PP_Weight = {fReader, "Kp_PP_Weight"};
   TTreeReaderArray<Float_t> Kp_PP_tr_pchi2 = {fReader, "Kp_PP_tr_pchi2"};
   TTreeReaderArray<Float_t> Kp_PP_DLLe = {fReader, "Kp_PP_DLLe"};
   TTreeReaderArray<Float_t> Kp_PP_DLLk = {fReader, "Kp_PP_DLLk"};
   TTreeReaderArray<Float_t> Kp_PP_DLLp = {fReader, "Kp_PP_DLLp"};
   TTreeReaderArray<Float_t> Kp_PP_DLLmu = {fReader, "Kp_PP_DLLmu"};
   TTreeReaderValue<Double_t> Hm_TRUECosTheta = {fReader, "Hm_TRUECosTheta"};
   TTreeReaderValue<Int_t> Hm_MC_MOTHER_ID = {fReader, "Hm_MC_MOTHER_ID"};
   TTreeReaderValue<Int_t> Hm_MC_MOTHER_KEY = {fReader, "Hm_MC_MOTHER_KEY"};
   TTreeReaderValue<Int_t> Hm_MC_GD_MOTHER_ID = {fReader, "Hm_MC_GD_MOTHER_ID"};
   TTreeReaderValue<Int_t> Hm_MC_GD_MOTHER_KEY = {fReader, "Hm_MC_GD_MOTHER_KEY"};
   TTreeReaderValue<Int_t> Hm_MC_GD_GD_MOTHER_ID = {fReader, "Hm_MC_GD_GD_MOTHER_ID"};
   TTreeReaderValue<Int_t> Hm_MC_GD_GD_MOTHER_KEY = {fReader, "Hm_MC_GD_GD_MOTHER_KEY"};
   TTreeReaderValue<Double_t> Hm_TRUEP_E = {fReader, "Hm_TRUEP_E"};
   TTreeReaderValue<Double_t> Hm_TRUEP_X = {fReader, "Hm_TRUEP_X"};
   TTreeReaderValue<Double_t> Hm_TRUEP_Y = {fReader, "Hm_TRUEP_Y"};
   TTreeReaderValue<Double_t> Hm_TRUEP_Z = {fReader, "Hm_TRUEP_Z"};
   TTreeReaderValue<Double_t> Hm_TRUEPT = {fReader, "Hm_TRUEPT"};
   TTreeReaderValue<Double_t> Hm_TRUEORIGINVERTEX_X = {fReader, "Hm_TRUEORIGINVERTEX_X"};
   TTreeReaderValue<Double_t> Hm_TRUEORIGINVERTEX_Y = {fReader, "Hm_TRUEORIGINVERTEX_Y"};
   TTreeReaderValue<Double_t> Hm_TRUEORIGINVERTEX_Z = {fReader, "Hm_TRUEORIGINVERTEX_Z"};
   TTreeReaderValue<Double_t> Hm_TRUEENDVERTEX_X = {fReader, "Hm_TRUEENDVERTEX_X"};
   TTreeReaderValue<Double_t> Hm_TRUEENDVERTEX_Y = {fReader, "Hm_TRUEENDVERTEX_Y"};
   TTreeReaderValue<Double_t> Hm_TRUEENDVERTEX_Z = {fReader, "Hm_TRUEENDVERTEX_Z"};
   TTreeReaderValue<Bool_t> Hm_TRUEISSTABLE = {fReader, "Hm_TRUEISSTABLE"};
   TTreeReaderValue<Double_t> Hm_TRUETAU = {fReader, "Hm_TRUETAU"};
   TTreeReaderValue<Int_t> Hm_Reconstructible = {fReader, "Hm_Reconstructible"};
   TTreeReaderValue<Int_t> Hm_Reconstructed = {fReader, "Hm_Reconstructed"};
   TTreeReaderValue<Int_t> Hm_ProtoParticles = {fReader, "Hm_ProtoParticles"};
   TTreeReaderArray<Float_t> Hm_PP_PX = {fReader, "Hm_PP_PX"};
   TTreeReaderArray<Float_t> Hm_PP_PY = {fReader, "Hm_PP_PY"};
   TTreeReaderArray<Float_t> Hm_PP_PZ = {fReader, "Hm_PP_PZ"};
   TTreeReaderArray<Float_t> Hm_PP_Weight = {fReader, "Hm_PP_Weight"};
   TTreeReaderArray<Float_t> Hm_PP_tr_pchi2 = {fReader, "Hm_PP_tr_pchi2"};
   TTreeReaderArray<Float_t> Hm_PP_DLLe = {fReader, "Hm_PP_DLLe"};
   TTreeReaderArray<Float_t> Hm_PP_DLLk = {fReader, "Hm_PP_DLLk"};
   TTreeReaderArray<Float_t> Hm_PP_DLLp = {fReader, "Hm_PP_DLLp"};
   TTreeReaderArray<Float_t> Hm_PP_DLLmu = {fReader, "Hm_PP_DLLmu"};
   TTreeReaderValue<UInt_t> nCandidate = {fReader, "nCandidate"};
   TTreeReaderValue<ULong64_t> totCandidates = {fReader, "totCandidates"};
   TTreeReaderValue<ULong64_t> EventInSequence = {fReader, "EventInSequence"};
   TTreeReaderValue<UInt_t> EVT_Int__I = {fReader, "EVT_Int__I"};
   TTreeReaderValue<Double_t> EVT_Int__Mean = {fReader, "EVT_Int__Mean"};
   TTreeReaderValue<Double_t> EVT_Int__Prob = {fReader, "EVT_Int__Prob"};
   TTreeReaderValue<Int_t> MCPVs = {fReader, "MCPVs"};
   TTreeReaderArray<Float_t> MCPVX = {fReader, "MCPVX"};
   TTreeReaderArray<Float_t> MCPVY = {fReader, "MCPVY"};
   TTreeReaderArray<Float_t> MCPVZ = {fReader, "MCPVZ"};
   TTreeReaderArray<Float_t> MCPVT = {fReader, "MCPVT"};
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


   MCGenSelector(TTree * /*tree*/ =0) { }
   virtual ~MCGenSelector() { }
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

   ClassDef(MCGenSelector,0);

};

#endif

#ifdef MCGenSelector_cxx
void MCGenSelector::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the reader is initialized.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   fReader.SetTree(tree);
}

Bool_t MCGenSelector::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}


#endif // #ifdef MCGenSelector_cxx
