{

	TChain *chain = new TChain("mct/MCDecayTree");
    //TChain *chain = new TChain("DecayTreeTuple/DecayTree");

	ifstream inf("tuplefilesMC.txt");
	TString line;

	while( inf >> line ){
		if( line.BeginsWith("#") ) continue;
		if( inf.eof() ) break;
		cout << line << endl;
		chain->Add(line.Data());

	}

//okay
/*
  for (int i = 0; i < 259; ++i)
  {
   chain->Add(Form("/st100-gr1/manca/PbPbData/229/%d/output/PbPb_D0_Jpsi.root",i));
 }
*/

//chain->Draw("runNumber>>h(200,161050,161250)","nCandidate==0");

 TProof *p = TProof::Open("workers=30");
////p->SetParallel(2);
 chain->SetProof();
//////
//chain->Process("d0Selector.C+");
 chain->Process("/home/saepark/D0Analysis/MCGenSelector.C+");

}


