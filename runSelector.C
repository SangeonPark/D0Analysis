{

TChain *chain = new TChain("D0/DecayTree");
//TChain *chain = new TChain("DecayTreeTuple/DecayTree");


ifstream inf("tuplefiles.txt");
TString line;

while( inf >> line ){
  if( line.BeginsWith("#") ) continue;
  if( inf.eof() ) break;
  cout << line << endl;
  chain->Add(line.Data());

}

//chain->Draw("runNumber>>h(200,161050,161250)","nCandidate==0");

TProof *p = TProof::Open("workers=30");
////p->SetParallel(2);
chain->SetProof();
//////
//chain->Process("d0Selector.C+");
chain->Process("/sps/lhcb/bossu/Scripts/Analysis/Data/PbPb/D0/ntuples/d0Selector.C+");

}


