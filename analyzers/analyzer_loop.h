#ifndef analyzer_loop_h
#define analyzer_loop_h

#include "analyzer_tree.h"
#include <iostream>
#include <TROOT.h>
#include <TH1.h>
#include <TH2.h>
#include <TGraph.h>
#include <TMath.h>
#include "TTree.h"
#include "TChain.h"
#include "TBranch.h"
#include <stdlib.h> 
class analyzer_loop : public analyzer_tree {

public :
 // basic functions
               analyzer_loop();
 virtual       ~analyzer_loop();
 virtual void  Loop(TString outfilename, 
                    Float_t lumi, Float_t nrEvents,
                    Float_t crossSec, Int_t nevts, 
                    TFile *optfile, TString uncbin);
 static const int  width = 8;
};

#endif
