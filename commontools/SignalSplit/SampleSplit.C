#define SampleSplit_cxx
#include<iostream>
#include "SampleSplit.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include "TH1F.h"
#include <map>

//using namespace std;

void SampleSplit::Loop()
{ 
std::cout<<"Starting"<<std::endl;
   if (fChain == 0) return;
   //--Instantiate roots
     TFile *ifile             = new TFile(SampleName+".root","recreate");//"update");
     
     TDirectory *lldj = ifile->mkdir("lldjNtuple");
     lldj->cd();
     TH1F *hTTSF              = new TH1F("hTTSF",      "TTbar scalefactors",   200,  0,   2);
     TH1F *hEvents            = new TH1F("hEvents",    "total processed events",   1,  0,   2);
     TH1F *hGenEventWeightSum = new TH1F("hGenEventWeightSum",    "Sum of GenEventWeights",   1,  0,   2);
     TTree* EventTree_ = new TTree("EventTree", "Event data");
     ifile->Write();
     delete ifile;

   //--main Loop
   Long64_t nentries = fChain->GetEntries();
   int N = nentries;
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<N;jentry++) {
     Long64_t ientry = LoadTree(jentry);
     if (ientry < 0) break;
     nb = fChain->GetEntry(jentry);   nbytes += nb;
      //--Check SampleName and fill tree
      if(*model==SampleName){
        TFile *file = new TFile(SampleName+".root","update");
        TTree *oldtree = (TTree*) file->Get("lldjNtuple/EventTree");
        TH1F *hTTSF_              = (TH1F *)file->Get("lldjNtuple/hTTSF");
        TH1F *hEvents_            = (TH1F *)file->Get("lldjNtuple/hEvents");
        TH1F *hGenEventWeightSum_ = (TH1F *)file->Get("lldjNtuple/hGenEventWeightSum");
        file->cd("lldjNtuple");
        hTTSF_             ->Fill(1.);
        hEvents_           ->Fill(1.);
        hGenEventWeightSum_->Fill(1,AODGenEventWeight);
        
        TTree *newTree = fChain->CloneTree(0);
        newTree->Fill();

        TList *list = new TList;
        list->Add(oldtree);
        list->Add(newTree);

        TTree *finalTree = TTree::MergeTrees(list);
        file->Write("",TObject::kOverwrite);
        delete list;
        delete file;
      }
   }//for jentry
std::cout<<"Ending"<<std::endl;
}
