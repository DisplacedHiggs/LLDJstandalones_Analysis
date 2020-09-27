#include "analyzer_scalefactors.h"
#include <iostream>
#include <numeric>

//----------------------------analyzer_scalefactors
analyzer_scalefactors::analyzer_scalefactors() 
{
}

//----------------------------~analyzer_scalefactors
analyzer_scalefactors::~analyzer_scalefactors()
{
}

//----------------------------makeEventWeight
Float_t analyzer_scalefactors::makeEventWeight(Float_t crossSec,
                                        Float_t lumi,
                                        Float_t nrEvents)
{
  // 1.0 for real data
  event_weight=1.0;
  Float_t crossSecScl = crossSec;
  if(isMC){ event_weight=lumi*crossSecScl*AODGenEventWeight/nrEvents; }
  return event_weight;
}

//----------------------------makePUWeight
Float_t analyzer_scalefactors::makePUWeight( TString dataset ){
 Int_t tmpbin;
 Float_t tmpweight;
 if( dataset.EqualTo("DoubleEG") ){
  tmpbin    = PUWeights_DoubleEG->GetBin(AODnTruePU);//AOD0thnPU);
  tmpweight = PUWeights_DoubleEG->GetBinContent(tmpbin);
 }
 else if( dataset.EqualTo("DoubleMu") ){
  tmpbin    = PUWeights_DoubleMu->GetBin(AODnTruePU);//AOD0thnPU);
  tmpweight = PUWeights_DoubleMu->GetBinContent(tmpbin);
 }
 else if( dataset.EqualTo("MuonEG") ){
  tmpbin    = PUWeights_MuonEG->GetBin(AODnTruePU);//AOD0thnPU);
  tmpweight = PUWeights_MuonEG->GetBinContent(tmpbin);
 }
 return tmpweight;
}



//----------------------------makeElectronReco
Float_t analyzer_scalefactors::makeElectronReco( std::vector<int> &electron_list, float &eleReco_Unc, std::vector<float> &eleReco_ind ){
 Float_t eleReco = 1.;
 eleReco_Unc=0.;
 eleReco_ind.clear();

 std::vector<float> eleReco_Unc_ind;
 eleReco_Unc_ind.clear();

 if(electron_list.size()>0){
  for(int d=0; d<electron_list.size(); ++d){
   int eleindex = electron_list[d];
   Float_t eeta = AOD_eleEta->at(eleindex);//<------changed; don't have SCEta right now
   Float_t ept  = AOD_elePt->at(eleindex);
   if(ept<20){ept=20.1;}//SF root files lowest bin is 20. Our ePt cut is 15 for lagging lepton. Bincontent is 0 for pT<20
   Int_t tmpbinx       = EleRecos->GetXaxis()->FindBin( eeta );
   Int_t tmpbiny       = EleRecos->GetYaxis()->FindBin( ept  );
   Int_t tmpbin        = EleRecos->GetBin( tmpbinx, tmpbiny );
   eleReco_ind.push_back(EleRecos->GetBinContent(tmpbin));
   eleReco_Unc_ind.push_back(EleRecos->GetBinError(tmpbin));
  }//end electrons
  eleReco = std::accumulate( eleReco_ind.begin(), eleReco_ind.end(), 1., std::multiplies<float>());
  eleReco_Unc = TMath::Sqrt(std::inner_product( eleReco_Unc_ind.begin(), eleReco_Unc_ind.end(), eleReco_Unc_ind.begin(), 0.));
 } // if electrons

 return eleReco;
}



//----------------------------makeElectronWeight
Float_t analyzer_scalefactors::makeElectronWeight( std::vector<int> &electron_list, float &eleID_Unc, std::vector<float> &eleID_ind ){
 Float_t eleID = 1.;
 eleID_Unc=0.;
 eleID_ind.clear();

 std::vector<float> eleID_Unc_ind;
 eleID_Unc_ind.clear();

 //check overlap with electrons
 if(electron_list.size()>0){
  for(int d=0; d<electron_list.size(); ++d){
   int eleindex = electron_list[d];
   Float_t eeta = AOD_eleEta->at(eleindex);//<------changed; don't have SCEta right now
   Float_t ept  = AOD_elePt->at(eleindex);
   Int_t tmpbinx       = EleWeights->GetXaxis()->FindBin( eeta );
   Int_t tmpbiny       = EleWeights->GetYaxis()->FindBin( ept  );
   Int_t tmpbin        = EleWeights->GetBin( tmpbinx, tmpbiny );
   eleID_ind.push_back(EleWeights->GetBinContent(tmpbin));
   eleID_Unc_ind.push_back(EleWeights->GetBinError(tmpbin));
  }//end electrons
  eleID = std::accumulate( eleID_ind.begin(), eleID_ind.end(), 1., std::multiplies<float>());
  eleID_Unc = TMath::Sqrt(std::inner_product( eleID_Unc_ind.begin(), eleID_Unc_ind.end(), eleID_Unc_ind.begin(), 0.));
 } // if electrons

 return eleID;
}

//----------------------------makeMuonWeight ----MuonID weight
Float_t analyzer_scalefactors::makeMuonWeight( std::vector<int> &muon_list, float &muonID_Unc, std::vector<float> &muonID_ind ){
 Float_t muonID = 1.;
 muonID_Unc=0.;
 muonID_ind.clear();

 std::vector<float> muonID_Unc_ind;
 muonID_Unc_ind.clear();

 //check overlap with electrons
 if(muon_list.size()>0){
  for(int d=0; d<muon_list.size(); ++d){
   int muindex = muon_list[d];
   Float_t mueta = AOD_muEta->at(muindex);//<------changed; don't have SCEta right now
   Float_t mupt  = AOD_muPt->at(muindex);
   if(mupt<20){mupt=20.1;}//SF root files lowest bin is 20. Our muPt cut is 12 for lagging lepton. Bincontent is 0 pT<20
   if(mupt>120){mupt=119.9;}//SF root files highest bin is 120. Bincontent is 0 pT>120
   Int_t tmpbinx       = MuonWeights->GetXaxis()->FindBin( mupt );
   Int_t tmpbiny       = MuonWeights->GetYaxis()->FindBin( abs(mueta)  );
   //printf(" bins %i %i\n",tmpbinx,tmpbiny);
   Int_t tmpbin        = MuonWeights->GetBin( tmpbinx, tmpbiny );
   muonID_ind.push_back(MuonWeights->GetBinContent(tmpbin));
   muonID_Unc_ind.push_back(MuonWeights->GetBinError(tmpbin));
  }//end Muons
  muonID = std::accumulate( muonID_ind.begin(), muonID_ind.end(), 1., std::multiplies<float>());
  muonID_Unc = TMath::Sqrt(std::inner_product( muonID_Unc_ind.begin(), muonID_Unc_ind.end(), muonID_Unc_ind.begin(), 0.));
 } // if Muons
 return muonID;
}

//----------------------------makeMuonIso ----MuonISO weight
Float_t analyzer_scalefactors::makeMuonIso( std::vector<int> &muon_list, float &muonISO_Unc, std::vector<float> &muonISO_ind ){
 Float_t muonISO = 1.;
 muonISO_Unc=0.;
 muonISO_ind.clear();

 std::vector<float> muonISO_Unc_ind;
 muonISO_Unc_ind.clear();

 //check overlap with electrons
 if(muon_list.size()>0){
  for(int d=0; d<muon_list.size(); ++d){
   int muindex = muon_list[d];
   Float_t mueta = AOD_muEta->at(muindex);//<------changed; don't have SCEta right now
   Float_t mupt  = AOD_muPt->at(muindex);
   if(mupt<20){mupt=20.1;}//SF root files lowest bin is 20. Our muPt cut is 12 for lagging lepton. Bincontent is 0 pT<20
   if(mupt>120){mupt=119.9;}//SF root files highest bin is 120. Bincontent is 0 pT>120
   Int_t tmpbinx       = MuonIso->GetXaxis()->FindBin( mupt );
   Int_t tmpbiny       = MuonIso->GetYaxis()->FindBin( abs(mueta)  );
   //printf(" bins %i %i\n",tmpbinx,tmpbiny);
   Int_t tmpbin        = MuonIso->GetBin( tmpbinx, tmpbiny );
   muonISO_ind.push_back(MuonIso->GetBinContent(tmpbin));
   muonISO_Unc_ind.push_back(MuonIso->GetBinError(tmpbin));
  }//end Muons
  muonISO = std::accumulate( muonISO_ind.begin(), muonISO_ind.end(), 1., std::multiplies<float>());
  muonISO_Unc = TMath::Sqrt(std::inner_product( muonISO_Unc_ind.begin(), muonISO_Unc_ind.end(), muonISO_Unc_ind.begin(), 0.));
 } // if Muons
 return muonISO;
}

//----------------------------loadPUWeight
void analyzer_scalefactors::loadPUWeight(){
 std::cout << "loading PU weight" << std::endl;
 TString filename_DoubleEG;
 TString filename_DoubleMu;
 TString filename_MuonEG;  
 if     (analysisYear=="2018"){
   filename_DoubleEG     = "weights/2018_puWeights_EGamma_69200.root" ;
   filename_DoubleMu     = "weights/2018_puWeights_DoubleMuon_69200.root" ;
   filename_MuonEG       = "weights/2018_puWeights_MuonEG_69200.root" ;
 }
 else if(analysisYear=="2017"){
   filename_DoubleEG     = "weights/2017_puWeights_DoubleEG_69200.root" ;
   filename_DoubleMu     = "weights/2017_puWeights_DoubleMuon_69200.root" ;
   filename_MuonEG       = "weights/2017_puWeights_MuonEG_69200.root" ;
 }
 else if(analysisYear=="2016"){
   filename_DoubleEG     = "weights/2016_puWeights_DoubleEG_69200.root" ;
   filename_DoubleMu     = "weights/2016_puWeights_DoubleMuon_69200.root" ;
   filename_MuonEG       = "weights/2016_puWeights_MuonEG_69200.root" ;
 }
 else std::cout<<"No PU weight files found"<<std::endl;
 TFile* file_puweights_DoubleEG     = new TFile( filename_DoubleEG     ) ;
 TFile* file_puweights_DoubleMu     = new TFile( filename_DoubleMu     ) ;
 TFile* file_puweights_MuonEG       = new TFile( filename_MuonEG       ) ;
 PUWeights_DoubleEG     = (TH1F*)file_puweights_DoubleEG    ->Get("h_PUweight")->Clone("PUWeights_DoubleEG"    );
 PUWeights_DoubleMu     = (TH1F*)file_puweights_DoubleMu    ->Get("h_PUweight")->Clone("PUWeights_DoubleMu"    );
 PUWeights_MuonEG       = (TH1F*)file_puweights_MuonEG      ->Get("h_PUweight")->Clone("PUWeights_MuonEG"      );
 return ;
}


//----------------------------loadElectronReco
void analyzer_scalefactors::loadElectronReco(){
 std::cout << "loading Electron Reco" << std::endl;
 TString filename;
 if     (analysisYear=="2018")  filename = "weights/2018_egammaReco_EGM2D.root" ;
 else if(analysisYear=="2017")  filename = "weights/2017_egammaReco_EGM2D.root" ;
 else if(analysisYear=="2016")  filename = "weights/2016_egammaReco_EGM2D.root" ;
 else std::cout<<"No EG Reco weight files found" <<std::endl;
 TFile* file_eleweights = new TFile( filename ) ;
 std::cout << " filename: " << filename << std::endl;
 EleRecos = (TH2F*)file_eleweights->Get("EGamma_SF2D")->Clone("EleRecos");
 return ;
}


//----------------------------loadElectronWeight
void analyzer_scalefactors::loadElectronWeight(TString eleid){
 std::cout << "loading Electron weight" << std::endl;
 TString filename;
      if(analysisYear=="2018") filename= "weights/2018_Electron"+eleid+".root" ;
 else if(analysisYear=="2017") filename= "weights/2017_Electron"+eleid+".root" ;
 else if(analysisYear=="2016") filename= "weights/2016_Electron"+eleid+".root" ;
 else std::cout<<"No Ele ID weight files found"<<std::endl;
 TFile* file_eleweights = new TFile( filename ) ;
 std::cout << " filename: " << filename << std::endl;
 EleWeights = (TH2F*)file_eleweights->Get("EGamma_SF2D")->Clone("EleWeights");
 return ;
}

//----------------------------loadMuonWeight
void analyzer_scalefactors::loadMuonWeight(TString muoid){
 std::cout << "loading Muon weight" << std::endl;
 TString filename;
 TString histname;
 if     (analysisYear=="2018") {
   filename = "weights/2018_RunABCD_SF_ID.root" ; 
   histname ="NUM_"+muoid+"ID_DEN_TrackerMuons_pt_abseta";
 }
 else if(analysisYear=="2017") {
   filename = "weights/2017_RunBCDEF_SF_ID.root" ;
   histname = "NUM_"+muoid+"ID_DEN_genTracks_pt_abseta" ;
 }
 else if(analysisYear=="2016") {
   filename = "weights/2016_Run_SF_ID.root" ;
   histname = "NUM_"+muoid+"ID_DEN_genTracks_eta_pt" ;
 }
 else std::cout<<"no MUON ID SF files found"<<std::endl;
 TFile* file_muonweights = new TFile( filename ) ;
 std::cout << " filename: " << filename << std::endl;
 MuonWeights = (TH2F*)file_muonweights->Get(histname)->Clone("MuonWeights");
 return ;
}

//----------------------------loadMuonIso
void analyzer_scalefactors::loadMuonIso(TString muoid){
 std::cout << "loading Muon Iso" << std::endl;
 TString filename;
 TString histname;
 if     (analysisYear=="2018") {
   filename = "weights/2018_RunABCD_SF_ISO.root" ;
   if (muoid.EqualTo("Loose")) histname = "NUM_LooseRelIso_DEN_LooseID_pt_abseta" ; //ISO criteria always given as Loose
   if (muoid.EqualTo("Medium")) histname = "NUM_LooseRelIso_DEN_MediumID_pt_abseta" ;
   if (muoid.EqualTo("Tight")) histname = "NUM_LooseRelIso_DEN_TightIDandIPCut_pt_abseta" ;
 }  
 else if(analysisYear=="2017") {
   filename = "weights/2017_RunBCDEF_SF_ISO.root" ;
   if (muoid.EqualTo("Loose")) histname = "NUM_LooseRelIso_DEN_LooseID_pt_abseta" ; //ISO criteria always given as Loose
   if (muoid.EqualTo("Medium")) histname = "NUM_LooseRelIso_DEN_MediumID_pt_abseta" ;
   if (muoid.EqualTo("Tight")) histname = "NUM_LooseRelIso_DEN_TightIDandIPCut_pt_abseta" ;
 }
 else if(analysisYear=="2016") {
   filename = "weights/2016_Run_SF_ISO.root" ;
   if (muoid.EqualTo("Loose")) histname = "NUM_LooseRelIso_DEN_LooseID_eta_pt" ; //ISO criteria always given as Loose
   if (muoid.EqualTo("Medium")) histname = "NUM_LooseRelIso_DEN_MediumID_eta_pt" ;
   if (muoid.EqualTo("Tight")) histname = "NUM_LooseRelIso_DEN_TightIDandIPCut_eta_pt" ;
 }
 else std::cout<<"no MUON ISO SF files found"<<std::endl;
 std::cout<<"got MuISO "<<std::endl;
 TFile* file_muoniso = new TFile( filename ) ;
 std::cout << " filename: " << filename << std::endl;
 MuonIso = (TH2F*)file_muoniso->Get(histname)->Clone("MuonIso");
 return ;
}
