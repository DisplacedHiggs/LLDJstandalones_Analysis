#include "analyzer_histograms.h"
#include <iostream>

//----------------------------analyzer_histograms


analyzer_histograms::analyzer_histograms() 
{

}

//----------------------------~analyzer_histograms
analyzer_histograms::~analyzer_histograms()
{

}




//----------------------------fillSelectedHistograms
Bool_t analyzer_histograms::fillSelectedHistograms(Float_t weight, int selbin)
{
 /// Decide here which histograms to get filled
 fillEleHistograms               ( weight, selbin );
 fillMuHistograms                ( weight, selbin );
 fillLepHistograms               ( weight, selbin );
 fillMETHTHistograms             ( weight, selbin );
 //fillWeightHistograms            ( weight, selbin );
 fillAODCaloJetMultHistograms    ( weight, selbin );
 fillAODCaloJetTagMultHistograms ( weight, selbin );
 fillExtraHistograms             ( weight, selbin );
}

//----------------------------writeSelectedHistograms
Bool_t analyzer_histograms::writeSelectedHistograms(int selbin)
{
 /// Decide here which histograms to get written
 writeEleHistograms               ( selbin );
 writeMuHistograms                ( selbin );
 writeLepHistograms               ( selbin );
 writeMETHTHistograms             ( selbin );
 //writeWeightHistograms             ( selbin );
 writeAODCaloJetMultHistograms    ( selbin );
 writeAODCaloJetTagMultHistograms ( selbin );
 writeExtraHistograms             ( selbin );
}

//----------------------------fillSelectedJetHistograms
Bool_t analyzer_histograms::fillSelectedJetHistograms(Float_t weight, int selbin, int jetbin )
{
 /// Decide here which jet histograms to get filled
  fillAODCaloJetBasicHistograms( weight, selbin, jetbin );
  fillAODCaloJet_L1PFHistograms( weight, selbin, jetbin );
  fillAODCaloJetExtraHistograms( weight, selbin, jetbin );
}

//----------------------------writeSelectedJetHistograms
Bool_t analyzer_histograms::writeSelectedJetHistograms(int selbin, int jetbin)
{
 /// Decide here which jet histograms to get written
 writeAODCaloJetBasicHistograms( selbin, jetbin );
 writeAODCaloJet_L1PFHistograms( selbin, jetbin );
 writeAODCaloJetExtraHistograms( selbin, jetbin );
}

//----------------------------fillSelectedTagHistograms
Bool_t analyzer_histograms::fillSelectedTagHistograms(Float_t weight, int selbin, int tagbin )
{
 /// Decide here which tag histograms to get filled
  fillAODCaloJetTagHistograms( weight, selbin, tagbin );
}

//----------------------------writeSelectedTagHistograms
Bool_t analyzer_histograms::writeSelectedTagHistograms(int selbin, int tagbin)
{
 /// Decide here which tag histograms to get written
  writeAODCaloJetTagHistograms( selbin, tagbin );
}


//----------------------------initSingleHistogramTH1F
TH1F* analyzer_histograms::initSingleHistogramTH1F(TString hname, TString htitle, Int_t nbins, Float_t xmin, Float_t xmax)
{

 TH1F* histoTH1F = new TH1F( hname , htitle , nbins , xmin , xmax );
 histoTH1F->Sumw2();

 return histoTH1F;

}

//Overload for variable binning
TH1F* analyzer_histograms::initSingleHistogramTH1F(TString hname, TString htitle, int nbins, Float_t xbins[])
{

  TH1F* histoTH1F = new TH1F( hname , htitle , nbins , xbins );
  histoTH1F->Sumw2();

  return histoTH1F;

}



//----------------------------initSingleHistogramTH2F
TH2F* analyzer_histograms::initSingleHistogramTH2F(TString hname, TString htitle,
                                   Int_t nbinsx, Float_t xmin, Float_t xmax,
                                   Int_t nbinsy, Float_t ymin, Float_t ymax)
{

 TH2F* histoTH2F = new TH2F( hname , htitle , nbinsx , xmin , xmax  , nbinsy , ymin , ymax );
 histoTH2F->Sumw2();

 return histoTH2F;

}


TH2F* analyzer_histograms::initSingleHistogramTH2F(TString hname, TString htitle,
						  int nbinsx, Float_t xbins[],
						  int nbinsy, Float_t ybins[])
{

 TH2F* histoTH2F = new TH2F( hname , htitle , nbinsx , xbins , nbinsy , ybins );
 histoTH2F->Sumw2();

 return histoTH2F;

}

//----------------------------init2DHistograms
Bool_t analyzer_histograms::init2DHistograms( TString uncbin )
{
 
 // loop through jets and selections to initialize histograms in parllel (series)
 // for(unsigned int i=0; i<selbinnames.size(); ++i){

 //   TString hname_nvertnjets = "h_"+selbinnames[i]+"_NGOODVERTICES_v_NJets";
 //   TString htitle_nvertnjets = "Nr. Good Vertices (x) vs. Nr. Jets (y)" ;
 //   h_nvertnjets[i] = initSingleHistogramTH2F( hname_nvertnjets, htitle_nvertnjets, 50, 0, 50, 50, 0, 50 ); 

 //  for(unsigned int j=0; j<jetmultnames.size(); ++j){
 //   // for histograms that are jet specific
 //  }
 // }

 return kTRUE;
}


//----------------------------fill2DHistograms
Bool_t analyzer_histograms::fill2DHistograms(Float_t weight, int selbin)
{
  // //printf("fill2DHistograms\n");
  //
  //  if( NGOODVERTICES->size()>0 && JetNJets->size()>0 ) 
  //   { h_nvertnjets[selbin]->Fill( NGOODVERTICES->at(0), JetNJets->at(0), weight ); }
  //
 return kTRUE;
}


//----------------------------write2DHistograms
Bool_t analyzer_histograms::write2DHistograms(int selbin)
{
 ////printf("write2DtHistograms\n");
 //h_nvertnjets[selbin].Write(); 
 //for(unsigned int j=0; j<jetmultnames.size(); ++j){
 //  // for histograms that are jet specific
 //}

 return kTRUE;
}


//----------------------------initEleHistograms
Bool_t analyzer_histograms::initEleHistograms( TString uncbin ){
 for(unsigned int i=0; i<selbinnames.size(); ++i){
   hist_file_out[i]->cd();
   //deleteEleHistograms(i);
   
   TString hname_AOD_nEle                    = "h_"+selbinnames[i]+"_AOD_nEle"        +uncbin; 
   TString hname_AOD_nSelectedEle            = "h_"+selbinnames[i]+"_AOD_nSelectedEle"+uncbin;
   TString hname_AOD_elePt                   = "h_"+selbinnames[i]+"_AOD_elePt"       +uncbin; 
   TString hname_AOD_eleEn                   = "h_"+selbinnames[i]+"_AOD_eleEn"       +uncbin; 
   TString hname_AOD_eleEta                  = "h_"+selbinnames[i]+"_AOD_eleEta"      +uncbin; 
   TString hname_AOD_elePhi                  = "h_"+selbinnames[i]+"_AOD_elePhi"      +uncbin; 
   TString hname_AOD_subLead_elePt           = "h_"+selbinnames[i]+"_AOD_subLead_elePt"       +uncbin; 
   TString hname_AOD_subLead_eleEn           = "h_"+selbinnames[i]+"_AOD_subLead_eleEn"       +uncbin; 
   TString hname_AOD_subLead_eleEta          = "h_"+selbinnames[i]+"_AOD_subLead_eleEta"      +uncbin; 
   TString hname_AOD_subLead_elePhi          = "h_"+selbinnames[i]+"_AOD_subLead_elePhi"      +uncbin; 
   TString hname_AOD_eleCharge               = "h_"+selbinnames[i]+"_AOD_eleCharge"   +uncbin; 
   
   h_AOD_nEle                     [i]= initSingleHistogramTH1F( hname_AOD_nEle                    , "AOD_nEle                   ", 6,  0, 6) ;  
   h_AOD_nSelectedEle             [i]= initSingleHistogramTH1F( hname_AOD_nSelectedEle            , "AOD_nSelectedEle           ", 10,0,10);
   h_AOD_elePt                    [i]= initSingleHistogramTH1F( hname_AOD_elePt                   , "AOD_elePt                  ", 50, 0, 500) ;  
   h_AOD_eleEn                    [i]= initSingleHistogramTH1F( hname_AOD_eleEn                   , "AOD_eleEn                  ", 50, 0, 500) ;  
   h_AOD_eleEta                   [i]= initSingleHistogramTH1F( hname_AOD_eleEta                  , "AOD_eleEta                 ", 30, -5, 5); 
   h_AOD_elePhi                   [i]= initSingleHistogramTH1F( hname_AOD_elePhi                  , "AOD_elePhi                 ", 30, -5, 5); 
   h_AOD_subLead_elePt            [i]= initSingleHistogramTH1F( hname_AOD_subLead_elePt           , "AOD_subLead_elePt          ", 50, 0, 500) ;  
   h_AOD_subLead_eleEn            [i]= initSingleHistogramTH1F( hname_AOD_subLead_eleEn           , "AOD_subLead_eleEn          ", 50, 0, 500) ;  
   h_AOD_subLead_eleEta           [i]= initSingleHistogramTH1F( hname_AOD_subLead_eleEta          , "AOD_subLead_eleEta         ", 30, -5, 5); 
   h_AOD_subLead_elePhi           [i]= initSingleHistogramTH1F( hname_AOD_subLead_elePhi          , "AOD_subLead_elePhi         ", 30, -5, 5); 
   h_AOD_eleCharge                [i]= initSingleHistogramTH1F( hname_AOD_eleCharge               , "AOD_eleCharge              ", 3, -1, 1); 
 }

 return kTRUE;
}

//----------------------------fillEleHistograms
Bool_t analyzer_histograms::fillEleHistograms(Float_t weight, int selbin )
{
  hist_file_out[selbin]->cd();

  h_AOD_nEle            [selbin] ->Fill( float(nAODEle), weight );
  h_AOD_nSelectedEle    [selbin] ->Fill( float(electron_list.size()), weight );

  // fill leading electron in vector
  if(electron_list.size() > 0){
   int eleindex = electron_list[0];
   h_AOD_elePt               [selbin] ->Fill( Shifted_elePt            .at(eleindex), weight );  
   h_AOD_eleEn               [selbin] ->Fill( AOD_eleEn               ->at(eleindex), weight );  
   h_AOD_eleEta              [selbin] ->Fill( AOD_eleEta              ->at(eleindex), weight );  
   h_AOD_elePhi              [selbin] ->Fill( AOD_elePhi              ->at(eleindex), weight );  
   h_AOD_eleCharge           [selbin] ->Fill( AOD_eleCharge           ->at(eleindex), weight );  
  }
  // fill sub-leading electron in vector
  if(electron_list.size() > 1){
   int eleindex2 = electron_list[1];
   h_AOD_subLead_elePt       [selbin] ->Fill( Shifted_elePt            .at(eleindex2), weight );  
   h_AOD_subLead_eleEn       [selbin] ->Fill( AOD_eleEn               ->at(eleindex2), weight );  
   h_AOD_subLead_eleEta      [selbin] ->Fill( AOD_eleEta              ->at(eleindex2), weight );  
   h_AOD_subLead_elePhi      [selbin] ->Fill( AOD_elePhi              ->at(eleindex2), weight );  
  }
 return kTRUE;
}

//----------------------------writeEleHistograms
Bool_t analyzer_histograms::writeEleHistograms(int selbin)
{
  hist_file_out[selbin]->cd();
  
  h_AOD_nEle            [selbin] ->Write();
  h_AOD_nSelectedEle    [selbin] ->Write();
  h_AOD_elePt           [selbin] ->Write();
  h_AOD_eleEn           [selbin] ->Write();
  h_AOD_eleEta          [selbin] ->Write();
  h_AOD_elePhi          [selbin] ->Write();
  h_AOD_subLead_elePt   [selbin] ->Write();
  h_AOD_subLead_eleEn   [selbin] ->Write();
  h_AOD_subLead_eleEta  [selbin] ->Write();
  h_AOD_subLead_elePhi  [selbin] ->Write();
  h_AOD_eleCharge       [selbin] ->Write();
  return kTRUE;
}

//----------------------------deleteEleHistograms
Bool_t analyzer_histograms::deleteEleHistograms(int selbin)
{
  //printf("deleteEleHistograms\n");
  hist_file_out[selbin]->cd();
  if(h_AOD_nEle[selbin]!=NULL)            h_AOD_nEle            [selbin] ->Delete();
  if(h_AOD_nSelectedEle[selbin]!=NULL)    h_AOD_nSelectedEle    [selbin] ->Delete();
  if(h_AOD_elePt[selbin]!=NULL)           h_AOD_elePt           [selbin] ->Delete();
  if(h_AOD_eleEn[selbin]!=NULL)           h_AOD_eleEn           [selbin] ->Delete();
  if(h_AOD_eleEta[selbin]!=NULL)          h_AOD_eleEta          [selbin] ->Delete();
  if(h_AOD_elePhi[selbin]!=NULL)          h_AOD_elePhi          [selbin] ->Delete();
  if(h_AOD_subLead_elePt[selbin]!=NULL)   h_AOD_subLead_elePt   [selbin] ->Delete();
  if(h_AOD_subLead_eleEn[selbin]!=NULL)   h_AOD_subLead_eleEn   [selbin] ->Delete();
  if(h_AOD_subLead_eleEta[selbin]!=NULL)  h_AOD_subLead_eleEta  [selbin] ->Delete();
  if(h_AOD_subLead_elePhi[selbin]!=NULL)  h_AOD_subLead_elePhi  [selbin] ->Delete();
  if(h_AOD_eleCharge[selbin]!=NULL)       h_AOD_eleCharge       [selbin] ->Delete();
 return kTRUE;
}


//----------------------------initMuHistograms
Bool_t analyzer_histograms::initMuHistograms( TString uncbin ){

 for(unsigned int i=0; i<selbinnames.size(); ++i){
  hist_file_out[i]->cd();
  //deleteMuHistograms(i);
  TString hname_AOD_nMu                     = "h_"+selbinnames[i]+"_AOD_nMu"                +uncbin; 
  TString hname_AOD_nSelectedMu             = "h_"+selbinnames[i]+"_AOD_nSelectedMu"        +uncbin;
  TString hname_AOD_muPt                    = "h_"+selbinnames[i]+"_AOD_muPt"               +uncbin; 
  TString hname_AOD_muEn                    = "h_"+selbinnames[i]+"_AOD_muEn"               +uncbin; 
  TString hname_AOD_muEta                   = "h_"+selbinnames[i]+"_AOD_muEta"              +uncbin; 
  TString hname_AOD_muPhi                   = "h_"+selbinnames[i]+"_AOD_muPhi"              +uncbin; 
  TString hname_AOD_subLead_muPt            = "h_"+selbinnames[i]+"_AOD_subLead_muPt"       +uncbin; 
  TString hname_AOD_subLead_muEn            = "h_"+selbinnames[i]+"_AOD_subLead_muEn"       +uncbin; 
  TString hname_AOD_subLead_muEta           = "h_"+selbinnames[i]+"_AOD_subLead_muEta"      +uncbin; 
  TString hname_AOD_subLead_muPhi           = "h_"+selbinnames[i]+"_AOD_subLead_muPhi"      +uncbin; 
  TString hname_AOD_muCharge                = "h_"+selbinnames[i]+"_AOD_muCharge"           +uncbin; 
  TString hname_AOD_muPFdBetaIsolation      = "h_"+selbinnames[i]+"_AOD_muPFdBetaIsolation" +uncbin; 

  h_AOD_nMu                      [i] = initSingleHistogramTH1F( hname_AOD_nMu                     , "AOD_nMu                    ", 6,  0, 6) ;  
  h_AOD_nSelectedMu              [i] = initSingleHistogramTH1F( hname_AOD_nSelectedMu             , "AOD_nSelectedMu            ", 10,0,10);
  h_AOD_muPt                     [i] = initSingleHistogramTH1F( hname_AOD_muPt                    , "AOD_muPt                   ", 50, 0, 500) ;  
  h_AOD_muEn                     [i] = initSingleHistogramTH1F( hname_AOD_muEn                    , "AOD_muEn                   ", 50, 0, 500) ;  
  h_AOD_muEta                    [i] = initSingleHistogramTH1F( hname_AOD_muEta                   , "AOD_muEta                  ", 30, -5, 5); 
  h_AOD_muPhi                    [i] = initSingleHistogramTH1F( hname_AOD_muPhi                   , "AOD_muPhi                  ", 30, -5, 5); 
  h_AOD_subLead_muPt             [i] = initSingleHistogramTH1F( hname_AOD_subLead_muPt            , "AOD_subLead_muPt           ", 50, 0, 500) ;  
  h_AOD_subLead_muEn             [i] = initSingleHistogramTH1F( hname_AOD_subLead_muEn            , "AOD_subLead_muEn           ", 50, 0, 500) ;  
  h_AOD_subLead_muEta            [i] = initSingleHistogramTH1F( hname_AOD_subLead_muEta           , "AOD_subLead_muEta          ", 30, -5, 5); 
  h_AOD_subLead_muPhi            [i] = initSingleHistogramTH1F( hname_AOD_subLead_muPhi           , "AOD_subLead_muPhi          ", 30, -5, 5); 
  h_AOD_muCharge                 [i] = initSingleHistogramTH1F( hname_AOD_muCharge                , "AOD_muCharge               ", 3, -1, 1); 
  h_AOD_muPFdBetaIsolation       [i] = initSingleHistogramTH1F( hname_AOD_muPFdBetaIsolation      , "AOD_muPFdBetaIsolation     ", 30, -5, 5); 
 }
 return kTRUE;
}

//----------------------------fillMuHistograms
Bool_t analyzer_histograms::fillMuHistograms(Float_t weight, int selbin)
{
  hist_file_out[selbin]->cd();
  h_AOD_nMu            [selbin] ->Fill( float(nAODMu), weight );
  h_AOD_nSelectedMu    [selbin] ->Fill( float(muon_list.size()), weight );
  // fill leading muon in vector
  if(muon_list.size() > 0){
   int muindex = muon_list[0];
   h_AOD_muPt               [selbin]->Fill( Shifted_muPt            .at(muindex), weight );  
   h_AOD_muEn               [selbin]->Fill( AOD_muEn               ->at(muindex), weight );  
   h_AOD_muEta              [selbin]->Fill( AOD_muEta              ->at(muindex), weight );  
   h_AOD_muPhi              [selbin]->Fill( AOD_muPhi              ->at(muindex), weight );  
   h_AOD_muCharge           [selbin]->Fill( AOD_muCharge           ->at(muindex), weight );  
   h_AOD_muPFdBetaIsolation [selbin]->Fill( AOD_muPFdBetaIsolation ->at(muindex), weight );  
  }
  if(muon_list.size() > 1){
   int muindex2 = muon_list[1];
   h_AOD_subLead_muPt               [selbin]->Fill( Shifted_muPt            .at(muindex2), weight );  
   h_AOD_subLead_muEn               [selbin]->Fill( AOD_muEn               ->at(muindex2), weight );  
   h_AOD_subLead_muEta              [selbin]->Fill( AOD_muEta              ->at(muindex2), weight );  
   h_AOD_subLead_muPhi              [selbin]->Fill( AOD_muPhi              ->at(muindex2), weight );  
  }
 return kTRUE;
}

//----------------------------writeMuHistograms
Bool_t analyzer_histograms::writeMuHistograms(int selbin)
{
  hist_file_out[selbin]->cd();
 h_AOD_nMu                     [selbin]->Write();
 h_AOD_nSelectedMu             [selbin]->Write();
 h_AOD_muPt                    [selbin]->Write();
 h_AOD_muEn                    [selbin]->Write();
 h_AOD_muEta                   [selbin]->Write();
 h_AOD_muPhi                   [selbin]->Write(); 
 h_AOD_subLead_muPt            [selbin]->Write();
 h_AOD_subLead_muEn            [selbin]->Write();
 h_AOD_subLead_muEta           [selbin]->Write();
 h_AOD_subLead_muPhi           [selbin]->Write(); 
 h_AOD_muCharge                [selbin]->Write(); 
 h_AOD_muPFdBetaIsolation      [selbin]->Write(); 
 return kTRUE;
}

//----------------------------deleteMuHistograms
Bool_t analyzer_histograms::deleteMuHistograms(int selbin)
{
  //printf("deleteMuHistograms\n");
  hist_file_out[selbin]->cd();
  if(h_AOD_nMu[selbin]!=NULL)                 h_AOD_nMu                     [selbin]->Delete();
  if(h_AOD_nSelectedMu[selbin]!=NULL)         h_AOD_nSelectedMu             [selbin]->Delete();
  if(h_AOD_muPt[selbin]!=NULL)                h_AOD_muPt                    [selbin]->Delete();
  if(h_AOD_muEn[selbin]!=NULL)                h_AOD_muEn                    [selbin]->Delete();
  if(h_AOD_muEta[selbin]!=NULL)               h_AOD_muEta                   [selbin]->Delete();
  if(h_AOD_muPhi[selbin]!=NULL)               h_AOD_muPhi                   [selbin]->Delete(); 
  if(h_AOD_subLead_muPt[selbin]!=NULL)        h_AOD_subLead_muPt            [selbin]->Delete();
  if(h_AOD_subLead_muEn[selbin]!=NULL)        h_AOD_subLead_muEn            [selbin]->Delete();
  if(h_AOD_subLead_muEta[selbin]!=NULL)       h_AOD_subLead_muEta           [selbin]->Delete();
  if(h_AOD_subLead_muPhi[selbin]!=NULL)       h_AOD_subLead_muPhi           [selbin]->Delete(); 
  if(h_AOD_muCharge[selbin]!=NULL)            h_AOD_muCharge                [selbin]->Delete(); 
  if(h_AOD_muPFdBetaIsolation[selbin]!=NULL)  h_AOD_muPFdBetaIsolation      [selbin]->Delete(); 
  return kTRUE;
}


//----------------------------initLepHistograms
Bool_t analyzer_histograms::initLepHistograms( TString uncbin ){

 for(unsigned int i=0; i<selbinnames.size(); ++i){
  hist_file_out[i]->cd();
  //deleteLepHistograms(i);
  TString hname_AOD_dilepton_Mass = "h_"+selbinnames[i]+"_AOD_dilepton_Mass"+uncbin; 
  TString hname_AOD_dilepton_Pt   = "h_"+selbinnames[i]+"_AOD_dilepton_Pt"  +uncbin; 
  TString hname_AOD_dileptonNewB_Pt   = "h_"+selbinnames[i]+"_AOD_dileptonNewB_Pt"  +uncbin; 
  TString hname_AOD_OSOFdilepton_Mass = "h_"+selbinnames[i]+"_AOD_OSOFdilepton_Mass"+uncbin; 
  TString hname_AOD_OSOFdilepton_Pt   = "h_"+selbinnames[i]+"_AOD_OSOFdilepton_Pt"  +uncbin; 
  TString hname_AOD_OSOFdileptonNewB_Pt   = "h_"+selbinnames[i]+"_AOD_OSOFdileptonNewB_Pt"  +uncbin; 

  h_AOD_dilepton_Mass[i] = initSingleHistogramTH1F( hname_AOD_dilepton_Mass, "AOD_dilepton_Mass", 30,  60, 120) ;  
  h_AOD_dileptonNewB_Pt  [i] = initSingleHistogramTH1F( hname_AOD_dileptonNewB_Pt  , "AOD_dileptonNewB_Pt  ", 50,   0, 500) ;  
  h_AOD_dilepton_Pt  [i] = initSingleHistogramTH1F( hname_AOD_dilepton_Pt  , "AOD_dilepton_Pt  ", 24, x_bins);
  
  h_AOD_OSOFdilepton_Mass[i] = initSingleHistogramTH1F( hname_AOD_OSOFdilepton_Mass, "AOD_OSOFdilepton_Mass", 30,  60, 120) ;  
  h_AOD_OSOFdileptonNewB_Pt  [i] = initSingleHistogramTH1F( hname_AOD_OSOFdileptonNewB_Pt  , "AOD_OSOFdileptonNewB_Pt  ", 50,   0, 500) ;  
  h_AOD_OSOFdilepton_Pt  [i] = initSingleHistogramTH1F( hname_AOD_OSOFdilepton_Pt  , "AOD_OSOFdilepton_Pt  ", 24,x_bins);  
 }
 return kTRUE;
}

//----------------------------fillLepHistograms
Bool_t analyzer_histograms::fillLepHistograms(Float_t weight, int selbin )
{
  hist_file_out[selbin]->cd();
  h_AOD_dilepton_Mass  [selbin]->Fill( dilep_mass, weight );
  h_AOD_dilepton_Pt    [selbin]->Fill( dilep_pt, weight );
  h_AOD_dileptonNewB_Pt    [selbin]->Fill( dilep_pt, weight );
  h_AOD_OSOFdilepton_Mass  [selbin]->Fill( OSOF_mass, weight );
  h_AOD_OSOFdilepton_Pt    [selbin]->Fill( OSOF_pt, weight );
  h_AOD_OSOFdileptonNewB_Pt    [selbin]->Fill( OSOF_pt, weight );
  return kTRUE;
}

//----------------------------writeLepHistograms
Bool_t analyzer_histograms::writeLepHistograms(int selbin)
{
  hist_file_out[selbin]->cd();
 h_AOD_dilepton_Mass           [selbin]->Write();
 h_AOD_dilepton_Pt             [selbin]->Write();
 h_AOD_dileptonNewB_Pt             [selbin]->Write();
 h_AOD_OSOFdilepton_Mass       [selbin]->Write();
 h_AOD_OSOFdilepton_Pt         [selbin]->Write();
 h_AOD_OSOFdileptonNewB_Pt         [selbin]->Write();
 return kTRUE;
}

//----------------------------deleteLepHistograms
Bool_t analyzer_histograms::deleteLepHistograms(int selbin)
{
  //printf("deleteLepHistograms\n");
  hist_file_out[selbin]->cd();
  if(h_AOD_dilepton_Mass    [selbin]!=NULL)   h_AOD_dilepton_Mass           [selbin]->Delete();
  if(h_AOD_dilepton_Pt      [selbin]!=NULL)   h_AOD_dilepton_Pt             [selbin]->Delete();
  if(h_AOD_dileptonNewB_Pt      [selbin]!=NULL)   h_AOD_dileptonNewB_Pt             [selbin]->Delete();
  if(h_AOD_OSOFdilepton_Mass[selbin]!=NULL)   h_AOD_OSOFdilepton_Mass       [selbin]->Delete();
  if(h_AOD_OSOFdilepton_Pt  [selbin]!=NULL)   h_AOD_OSOFdilepton_Pt         [selbin]->Delete();  
  if(h_AOD_OSOFdileptonNewB_Pt  [selbin]!=NULL)   h_AOD_OSOFdileptonNewB_Pt         [selbin]->Delete();  
  return kTRUE;
}


//----------------------------initMETHTHistograms
Bool_t analyzer_histograms::initMETHTHistograms( TString uncbin ){
  
  for(unsigned int i=0; i<selbinnames.size(); ++i){
    hist_file_out[i]->cd();
    //deleteMETHTHistograms(i);
//    TString hname_AOD_MET_phi                 = "h_"+selbinnames[i]+"_AOD_MET_phi"  +uncbin ; 
//    TString hname_AOD_MET_pt                  = "h_"+selbinnames[i]+"_AOD_MET_pt"   +uncbin ; 
    TString hname_htall                       = "h_"+selbinnames[i]+"_htall"        +uncbin ;
    TString hname_htaodcalojets               = "h_"+selbinnames[i]+"_htaodcalojets"+uncbin ;
    TString hname_AODnGoodVtx                 = "h_"+selbinnames[i]+"_AODnGoodVtx"+uncbin ;
    TString hname_AODnVtx                     = "h_"+selbinnames[i]+"_AODnVtx"+uncbin ;
    TString hname_AODnTruePU                  = "h_"+selbinnames[i]+"_AODnTruePU"+uncbin ;
    TString hname_AOD0thnPU                   = "h_"+selbinnames[i]+"_AOD0thnPU"+uncbin ;
    
//    h_AOD_MET_phi    [i] = initSingleHistogramTH1F( hname_AOD_MET_phi   , "AOD_MET_phi  " , 30, -5, 5); 
//    h_AOD_MET_pt     [i] = initSingleHistogramTH1F( hname_AOD_MET_pt    , "AOD_MET_pt   " , 50, 0, 500); 
    h_htall          [i] = initSingleHistogramTH1F( hname_htall         , "htall        " , 50,0,1000) ; 
    h_htaodcalojets  [i] = initSingleHistogramTH1F( hname_htaodcalojets , "htaodcalojets" , 50,0,1000) ; 
    h_AODnGoodVtx    [i] = initSingleHistogramTH1F( hname_AODnGoodVtx , "AODnGoodVtx" , 150,0,150) ; 
    h_AODnVtx        [i] = initSingleHistogramTH1F( hname_AODnVtx , "AODnVtx" , 150,0,150) ; 
    h_AODnTruePU     [i] = initSingleHistogramTH1F( hname_AODnTruePU , "AODnTruePU" , 150,0,150) ; 
    h_AOD0thnPU      [i] = initSingleHistogramTH1F( hname_AOD0thnPU , "AOD0thnPU" , 150,0,150) ; 
  }
  
  return kTRUE;
}

//----------------------------fillMETHTHistograms
Bool_t analyzer_histograms::fillMETHTHistograms(Float_t weight, int selbin)
{
  hist_file_out[selbin]->cd();
// h_AOD_MET_phi             [selbin]->Fill( themephi       , weight);  
// h_AOD_MET_pt              [selbin]->Fill( themet         , weight);  
 h_htall                   [selbin]->Fill( htall          , weight); 
 h_htaodcalojets           [selbin]->Fill( htaodcalojets  , weight); 
 h_AODnGoodVtx             [selbin]->Fill( AODnGoodVtx  , weight); 
 h_AODnVtx                 [selbin]->Fill( AODnVtx  , weight); 
 h_AODnTruePU              [selbin]->Fill( AODnTruePU  , weight); 
 h_AOD0thnPU               [selbin]->Fill( AOD0thnPU  , weight); 
 return kTRUE;
}

//----------------------------writeMETHTHistograms
Bool_t analyzer_histograms::writeMETHTHistograms(int selbin)
{
  hist_file_out[selbin]->cd();
//  h_AOD_MET_phi             [selbin]->Write(); 
//  h_AOD_MET_pt              [selbin]->Write(); 
  h_htall                   [selbin]->Write(); 
  h_htaodcalojets           [selbin]->Write(); 
  h_AODnGoodVtx             [selbin]->Write(); 
  h_AODnVtx                 [selbin]->Write(); 
  h_AODnTruePU              [selbin]->Write(); 
  h_AOD0thnPU               [selbin]->Write(); 
  return kTRUE;
}

//----------------------------deleteMETHTHistograms
Bool_t analyzer_histograms::deleteMETHTHistograms(int selbin)
{
  //printf("deleteMETHTHistograms\n");
  hist_file_out[selbin]->cd();
//  if(h_AOD_MET_phi  [selbin]!=NULL)   h_AOD_MET_phi             [selbin]->Delete(); 
//  if(h_AOD_MET_pt   [selbin]!=NULL)   h_AOD_MET_pt              [selbin]->Delete(); 
  if(h_htall        [selbin]!=NULL)   h_htall                   [selbin]->Delete(); 
  if(h_htaodcalojets[selbin]!=NULL)   h_htaodcalojets           [selbin]->Delete(); 
  if(h_AODnGoodVtx[selbin]!=NULL)     h_AODnGoodVtx             [selbin]->Delete(); 
  if(h_AODnVtx[selbin]!=NULL)         h_AODnVtx                 [selbin]->Delete(); 
  if(h_AODnTruePU[selbin]!=NULL)      h_AODnTruePU              [selbin]->Delete(); 
  if(h_AOD0thnPU[selbin]!=NULL)       h_AOD0thnPU               [selbin]->Delete(); 
  return kTRUE;
}

//----------------------------initWeightHistograms
Bool_t analyzer_histograms::initWeightHistograms( TString uncbin ){
  
  for(unsigned int i=0; i<selbinnames.size(); ++i){
    hist_file_out[i]->cd();
    //deleteWeightHistograms(i);
    TString hname_eleReco                       = "h_"+selbinnames[i]+"_eleReco"  +uncbin ; 
    TString hname_eleID                       = "h_"+selbinnames[i]+"_eleID"  +uncbin ; 
    TString hname_muonID                      = "h_"+selbinnames[i]+"_muonID"  +uncbin ; 
    TString hname_muonISO                     = "h_"+selbinnames[i]+"_muonISO"  +uncbin ; 
    TString hname_LeptonSF                    = "h_"+selbinnames[i]+"_LeptonSF"  +uncbin ; 

    TString hname_eleReco_Unc              = "h_"+selbinnames[i]+"_eleReco_Unc"  +uncbin ; 
    TString hname_eleID_Unc              = "h_"+selbinnames[i]+"_eleID_Unc"  +uncbin ; 
    TString hname_muonID_Unc              = "h_"+selbinnames[i]+"_muonID_Unc"  +uncbin ; 
    TString hname_muonISO_Unc              = "h_"+selbinnames[i]+"_muonISO_Unc"  +uncbin ; 
    TString hname_LeptonSF_Unc              = "h_"+selbinnames[i]+"_LeptonSF_Unc"  +uncbin ; 

    //TString hname_LumiWeight                  = "h_"+selbinnames[i]+"_LumiWeight"  +uncbin ; 
    //TString hname_PUWeight                    = "h_"+selbinnames[i]+"_PUWeight"  +uncbin ; 
    //TString hname_GenEventWeight              = "h_"+selbinnames[i]+"_GenEventWeight"  +uncbin ; 
    //TString hname_OtherWeight              = "h_"+selbinnames[i]+"_OtherWeight"  +uncbin ; 
    TString hname_FullWeight              = "h_"+selbinnames[i]+"_FullWeight"  +uncbin ; 

    
    h_eleReco          [i] = initSingleHistogramTH2F( hname_eleReco   , "eleReco  " , 10, 0.96, 1.01, 10, 0.96, 1.01); 
    h_eleID          [i] = initSingleHistogramTH2F( hname_eleID   , "eleID  " , 10, 0.96, 1.01, 10, 0.96, 1.01); 
    h_muonID          [i] = initSingleHistogramTH2F( hname_muonID   , "muonID  " , 20, 0.985, 1.005, 20, 0.985, 1.005); 
    h_muonISO          [i] = initSingleHistogramTH2F( hname_muonISO   , "muonISO  " , 20, 0.985, 1.005, 20, 0.985, 1.005); 
    h_LeptonSF          [i] = initSingleHistogramTH1F( hname_LeptonSF   , "LeptonSF  " , 100, 0.7, 1.1); 

    h_eleReco_Unc          [i] = initSingleHistogramTH1F( hname_eleReco_Unc   , "eleReco_Unc  " , 100, 0, .1);
    h_eleID_Unc          [i] = initSingleHistogramTH1F( hname_eleID_Unc   , "eleID_Unc  " , 100, 0, .1);
    h_muonID_Unc          [i] = initSingleHistogramTH1F( hname_muonID_Unc   , "muonID_Unc  " , 100, 0, .1); 
    h_muonISO_Unc          [i] = initSingleHistogramTH1F( hname_muonISO_Unc   , "muonISO_Unc  " , 100, 0, .1); 
    h_LeptonSF_Unc          [i] = initSingleHistogramTH1F( hname_LeptonSF_Unc   , "LeptonSF_Unc  " , 100, 0, .1); 

    //h_LumiWeight          [i] = initSingleHistogramTH1F( hname_LumiWeight   , "LumiWeight  " , 200, 0, 10); 
    //h_PUWeight          [i] = initSingleHistogramTH1F( hname_PUWeight   , "PUWeight  " , 200, 0, 10); 
    //h_GenEventWeight          [i] = initSingleHistogramTH1F( hname_GenEventWeight   , "GenEventWeight  " , 200, 0, 10); 
    //h_OtherWeight          [i] = initSingleHistogramTH1F( hname_OtherWeight   , "OtherWeight  " , 200, 0, 10); 
    h_FullWeight          [i] = initSingleHistogramTH1F( hname_FullWeight   , "FullWeight  " , 100, -5, 5); 
  }
  
  return kTRUE;
}

//----------------------------fillWeightHistograms
Bool_t analyzer_histograms::fillWeightHistograms(Float_t weight, int selbin)
{
  hist_file_out[selbin]->cd();
 if(isMC){
 if (dofillselbin[5]||dofillselbin[9]||dofillselbin[13]){
 h_eleReco             [selbin]->Fill(eleReco_ind[0], eleReco_ind[1]); 
 h_eleReco_Unc         [selbin]->Fill(eleReco_Unc);  
 h_eleID             [selbin]->Fill(eleID_ind[0], eleID_ind[1]); 
 h_eleID_Unc         [selbin]->Fill(eleID_Unc);  
} 
 if (dofillselbin[7]||dofillselbin[11]||dofillselbin[15]){
 h_muonID             [selbin]->Fill(muonID_ind[0], muonID_ind[1]);  
 h_muonISO             [selbin]->Fill(muonISO_ind[0], muonISO_ind[1]);  
 h_muonID_Unc         [selbin]->Fill(muonID_Unc);  
 h_muonISO_Unc         [selbin]->Fill(muonISO_Unc);  
}
 h_LeptonSF         [selbin]->Fill(w_LeptonSF);  
 h_LeptonSF_Unc         [selbin]->Fill(LeptonSF_Unc);  
 
 //h_LumiWeight         [selbin]->Fill(w_Lumi);  
 //h_PUWeight         [selbin]->Fill(w_PU);  
 //h_GenEventWeight         [selbin]->Fill(w_GenEvent);  
 //h_OtherWeight         [selbin]->Fill(w_other);  
 }
 h_FullWeight         [selbin]->Fill(weight);  
 
 return kTRUE;
}

//----------------------------writeWeightHistograms
Bool_t analyzer_histograms::writeWeightHistograms(int selbin)
{
  hist_file_out[selbin]->cd();
  h_eleReco                  [selbin]->Write(); 
  h_eleID                  [selbin]->Write(); 
  h_muonID                 [selbin]->Write(); 
  h_muonISO                [selbin]->Write(); 
  h_LeptonSF               [selbin]->Write(); 

  h_eleReco_Unc         [selbin]->Write(); 
  h_eleID_Unc         [selbin]->Write(); 
  h_muonID_Unc         [selbin]->Write(); 
  h_muonISO_Unc         [selbin]->Write(); 
  h_LeptonSF_Unc         [selbin]->Write(); 

  //h_LumiWeight             [selbin]->Write(); 
  //h_PUWeight               [selbin]->Write(); 
  //h_GenEventWeight         [selbin]->Write(); 
  //h_OtherWeight         [selbin]->Write(); 
  h_FullWeight         [selbin]->Write(); 
  return kTRUE;
}

//----------------------------deleteWeightHistograms
Bool_t analyzer_histograms::deleteWeightHistograms(int selbin)
{
  //printf("deleteWeightHistograms\n");
  hist_file_out[selbin]->cd();
  if(h_eleReco         [selbin]!=NULL)   h_eleReco                    [selbin]->Delete(); 
  if(h_eleID         [selbin]!=NULL)   h_eleID                    [selbin]->Delete(); 
  if(h_muonID        [selbin]!=NULL)   h_muonID                   [selbin]->Delete(); 
  if(h_muonISO       [selbin]!=NULL)   h_muonISO                  [selbin]->Delete(); 
  if(h_LeptonSF      [selbin]!=NULL)   h_LeptonSF                 [selbin]->Delete(); 

  if(h_eleReco_Unc[selbin]!=NULL)   h_eleReco_Unc           [selbin]->Delete(); 
  if(h_eleID_Unc[selbin]!=NULL)   h_eleID_Unc           [selbin]->Delete(); 
  if(h_muonID_Unc[selbin]!=NULL)   h_muonID_Unc           [selbin]->Delete(); 
  if(h_muonISO_Unc[selbin]!=NULL)   h_muonISO_Unc           [selbin]->Delete(); 
  if(h_LeptonSF_Unc[selbin]!=NULL)   h_LeptonSF_Unc           [selbin]->Delete(); 

  //if(h_LumiWeight    [selbin]!=NULL)   h_LumiWeight               [selbin]->Delete(); 
  //if(h_PUWeight      [selbin]!=NULL)   h_PUWeight                 [selbin]->Delete(); 
  //if(h_GenEventWeight[selbin]!=NULL)   h_GenEventWeight           [selbin]->Delete(); 
  //if(h_OtherWeight[selbin]!=NULL)   h_OtherWeight           [selbin]->Delete(); 
  if(h_FullWeight[selbin]!=NULL)   h_FullWeight           [selbin]->Delete(); 
  return kTRUE;
}


///// Jet Histograms
//----------------------------initAODCaloJetBasicHistograms
Bool_t analyzer_histograms::initAODCaloJetBasicHistograms( TString uncbin )
{

  // loop through jets and selections to initialize histograms in parllel (series)
  for(unsigned int i=0; i<selbinnames.size(); ++i){
  hist_file_out[i]->cd(); 
  //deleteAODCaloJetBasicHistograms(i);
      TString hname_nCaloJet                 = "h_"+selbinnames[i]+"_nCaloJet" +uncbin;
//      TString hname_nPFJet                   = "h_"+selbinnames[i]+"_nPFJet"   +uncbin;
//      TString hname_nPFchsJet                = "h_"+selbinnames[i]+"_nPFchsJet"+uncbin;
      h_nCaloJet                 [i] = initSingleHistogramTH1F( hname_nCaloJet  , "nCaloJet",  10,0,10);
//      h_nPFJet                   [i] = initSingleHistogramTH1F( hname_nPFJet    , "nPFJet",    10,0,10);
//      h_nPFchsJet                [i] = initSingleHistogramTH1F( hname_nPFchsJet , "nPFchsJet", 10,0,10);
      unsigned int k; if(jetMultOn) k=0; else k=jetmultnames.size()-1;
      for(k; k<jetmultnames.size(); ++k){
        //deleteAODCaloJetBasicHistograms(i,k);
	TString hname_AODCaloJet_emEnergyFraction             = "h_"+selbinnames[i]+"_"+jetmultnames[k]+"_AODCaloJet_emEnergyFraction"    +uncbin; 
	TString hname_AODCaloJet_energyFractionHadronic       = "h_"+selbinnames[i]+"_"+jetmultnames[k]+"_AODCaloJet_energyFractionHadronic" +uncbin; 
	TString hname_AODCaloJetPt                            = "h_"+selbinnames[i]+"_"+jetmultnames[k]+"_AODCaloJetPt"                   +uncbin; 
	TString hname_AODCaloJetPtVar                         = "h_"+selbinnames[i]+"_"+jetmultnames[k]+"_AODCaloJetPtVar"                +uncbin; 
	TString hname_AODCaloJetEta                           = "h_"+selbinnames[i]+"_"+jetmultnames[k]+"_AODCaloJetEta"                  +uncbin; 
	TString hname_AODCaloJetPhi                           = "h_"+selbinnames[i]+"_"+jetmultnames[k]+"_AODCaloJetPhi"                  +uncbin; 
	TString hname_AODCaloJetAlphaMax                      = "h_"+selbinnames[i]+"_"+jetmultnames[k]+"_AODCaloJetAlphaMax"             +uncbin; 
	TString hname_AODCaloJetAlphaMax_FineBin              = "h_"+selbinnames[i]+"_"+jetmultnames[k]+"_AODCaloJetAlphaMax_FineBin"     +uncbin; 
	TString hname_AODCaloJetAlphaMax2                     = "h_"+selbinnames[i]+"_"+jetmultnames[k]+"_AODCaloJetAlphaMax2"            +uncbin; 
	TString hname_AODCaloJetAlphaMaxPrime                 = "h_"+selbinnames[i]+"_"+jetmultnames[k]+"_AODCaloJetAlphaMaxPrime"        +uncbin; 
	TString hname_AODCaloJetAlphaMaxPrime2                = "h_"+selbinnames[i]+"_"+jetmultnames[k]+"_AODCaloJetAlphaMaxPrime2"       +uncbin; 
	TString hname_AODCaloJetBeta                          = "h_"+selbinnames[i]+"_"+jetmultnames[k]+"_AODCaloJetBeta"                 +uncbin; 
	TString hname_AODCaloJetBeta2                         = "h_"+selbinnames[i]+"_"+jetmultnames[k]+"_AODCaloJetBeta2"                +uncbin; 
	TString hname_AODCaloJetSumIP                         = "h_"+selbinnames[i]+"_"+jetmultnames[k]+"_AODCaloJetSumIP"                +uncbin; 
	TString hname_AODCaloJetSumIPSig                      = "h_"+selbinnames[i]+"_"+jetmultnames[k]+"_AODCaloJetSumIPSig"             +uncbin; 
	TString hname_AODCaloJetMedianIP                      = "h_"+selbinnames[i]+"_"+jetmultnames[k]+"_AODCaloJetMedianIP"             +uncbin; 
	TString hname_AODCaloJetMedianLog10IPSig              = "h_"+selbinnames[i]+"_"+jetmultnames[k]+"_AODCaloJetMedianLog10IPSig"     +uncbin; 
	TString hname_AODCaloJetMedianLog10IPSig_FineBin      = "h_"+selbinnames[i]+"_"+jetmultnames[k]+"_AODCaloJetMedianLog10IPSig_FineBin"+uncbin; 
	TString hname_AODCaloJetTrackAngle                    = "h_"+selbinnames[i]+"_"+jetmultnames[k]+"_AODCaloJetTrackAngle"           +uncbin; 
	TString hname_AODCaloJetLogTrackAngle                 = "h_"+selbinnames[i]+"_"+jetmultnames[k]+"_AODCaloJetLogTrackAngle"        +uncbin; 
	TString hname_AODCaloJetMedianLog10TrackAngle         = "h_"+selbinnames[i]+"_"+jetmultnames[k]+"_AODCaloJetMedianLog10TrackAngle"+uncbin; 
	TString hname_AODCaloJetMedianLog10TrackAngle_FineBin = "h_"+selbinnames[i]+"_"+jetmultnames[k]+"_AODCaloJetMedianLog10TrackAngle_FineBin"+uncbin; 
	TString hname_AODCaloJetTotalTrackAngle               = "h_"+selbinnames[i]+"_"+jetmultnames[k]+"_AODCaloJetTotalTrackAngle"      +uncbin; 
	TString hname_AODCaloJetMinDR                         = "h_"+selbinnames[i]+"_"+jetmultnames[k]+"_AODCaloJetMinDR"                +uncbin; 
//	TString hname_AODCaloJetCSV                           = "h_"+selbinnames[i]+"_"+jetmultnames[k]+"_AODCaloJetCSV"                  +uncbin; 
//	TString hname_AODCaloJetPartonFlavour                 = "h_"+selbinnames[i]+"_"+jetmultnames[k]+"_AODCaloJetPartonFlavour"        +uncbin; 
        TString hname_AODCaloJetAbsEta                        = "h_"+selbinnames[i]+"_"+jetmultnames[k]+"_AODCaloJetAbsEta"               +uncbin; 
	TString hname_AODCaloJetPtVarAbsEtaVar                = "h_"+selbinnames[i]+"_"+jetmultnames[k]+"_AODCaloJetPtVarAbsEtaVar"       +uncbin; 
	TString hname_AODCaloJetEtaVsPhi                      = "h_"+selbinnames[i]+"_"+jetmultnames[k]+"_AODCaloJetEtaVsPhi"             +uncbin; 
	h_AODCaloJet_emEnergyFraction      [i][k] = initSingleHistogramTH1F( hname_AODCaloJet_emEnergyFraction      , "AODCaloJet_emEnergyFraction             ", 101,0.,1.01); 
	h_AODCaloJet_energyFractionHadronic[i][k] = initSingleHistogramTH1F( hname_AODCaloJet_energyFractionHadronic, "AODCaloJet_energyFractionHadronic       ", 101,0.,1.01); 
	h_AODCaloJetPt                     [i][k] = initSingleHistogramTH1F( hname_AODCaloJetPt                     , "AODCaloJetPt                            ", 50,0,500  ); 
	h_AODCaloJetEta                    [i][k] = initSingleHistogramTH1F( hname_AODCaloJetEta                    , "AODCaloJetEta                           ", 30,-5,5   ); 
	h_AODCaloJetPhi                    [i][k] = initSingleHistogramTH1F( hname_AODCaloJetPhi                    , "AODCaloJetPhi                           ", 30,-5,5   ); 
	h_AODCaloJetAlphaMax               [i][k] = initSingleHistogramTH1F( hname_AODCaloJetAlphaMax               , "AODCaloJetAlphaMax                      ", 60, 0, 1.2  ); 
	h_AODCaloJetAlphaMax_FineBin       [i][k] = initSingleHistogramTH1F( hname_AODCaloJetAlphaMax_FineBin       , "AODCaloJetAlphaMax_Finebin              ", 300, 0, 1.1  ); 
	h_AODCaloJetAlphaMax2              [i][k] = initSingleHistogramTH1F( hname_AODCaloJetAlphaMax2              , "AODCaloJetAlphaMax2                     ", 50, 0, 1  ); 
	h_AODCaloJetAlphaMaxPrime          [i][k] = initSingleHistogramTH1F( hname_AODCaloJetAlphaMaxPrime          , "AODCaloJetAlphaMaxPrime                 ", 50, 0, 1  ); 
	h_AODCaloJetAlphaMaxPrime2         [i][k] = initSingleHistogramTH1F( hname_AODCaloJetAlphaMaxPrime2         , "AODCaloJetAlphaMaxPrime2                ", 50, 0, 1  ); 
	h_AODCaloJetBeta                   [i][k] = initSingleHistogramTH1F( hname_AODCaloJetBeta                   , "AODCaloJetBeta                          ", 50, 0, 1  ); 
	h_AODCaloJetBeta2                  [i][k] = initSingleHistogramTH1F( hname_AODCaloJetBeta2                  , "AODCaloJetBeta2                         ", 50, 0, 1  ); 
	h_AODCaloJetSumIP                  [i][k] = initSingleHistogramTH1F( hname_AODCaloJetSumIP                  , "AODCaloJetSumIP                         ", 50, -3, 3 ); 
	h_AODCaloJetSumIPSig               [i][k] = initSingleHistogramTH1F( hname_AODCaloJetSumIPSig               , "AODCaloJetSumIPSig                      ", 50, -3, 3 ); 
	h_AODCaloJetMedianIP               [i][k] = initSingleHistogramTH1F( hname_AODCaloJetMedianIP               , "AODCaloJetMedianIP                      ", 50, -3, 3 ); 
	h_AODCaloJetMedianLog10IPSig       [i][k] = initSingleHistogramTH1F( hname_AODCaloJetMedianLog10IPSig       , "AODCaloJetMedianLog10IPSig              ", 50, -3, 4 ); 
	h_AODCaloJetMedianLog10IPSig_FineBin[i][k] = initSingleHistogramTH1F( hname_AODCaloJetMedianLog10IPSig_FineBin, "AODCaloJetMedianLog10IPSig_FineBin    ", 500, -3, 4 ); 
	h_AODCaloJetTrackAngle             [i][k] = initSingleHistogramTH1F( hname_AODCaloJetTrackAngle             , "AODCaloJetTrackAngle                    ", 50, -3, 3 ); 
	h_AODCaloJetLogTrackAngle          [i][k] = initSingleHistogramTH1F( hname_AODCaloJetLogTrackAngle          , "AODCaloJetLogTrackAngle                 ", 50, -3, 3 ); 
	h_AODCaloJetMedianLog10TrackAngle  [i][k] = initSingleHistogramTH1F( hname_AODCaloJetMedianLog10TrackAngle  , "AODCaloJetMedianLog10TrackAngle         ", 50, -5, 2 ); 
	h_AODCaloJetMedianLog10TrackAngle_FineBin  [i][k] = initSingleHistogramTH1F( hname_AODCaloJetMedianLog10TrackAngle_FineBin  , "AODCaloJetMedianLog10TrackAngle_FineBin", 500, -5, 2 ); 
	h_AODCaloJetTotalTrackAngle        [i][k] = initSingleHistogramTH1F( hname_AODCaloJetTotalTrackAngle        , "AODCaloJetTotalTrackAngle               ", 50, -3, 3 ); 
	h_AODCaloJetMinDR                  [i][k] = initSingleHistogramTH1F( hname_AODCaloJetMinDR                  , "AODCaloJetMinDR                         ", 30, 0, 5 ); 
//	h_AODCaloJetCSV                    [i][k] = initSingleHistogramTH1F( hname_AODCaloJetCSV                    , "AODCaloJetCSV                           ", 24, -.1, 1.1 ); 
//	h_AODCaloJetPartonFlavour          [i][k] = initSingleHistogramTH1F( hname_AODCaloJetPartonFlavour          , "AODCaloJetPartonFlavour                 ", 35, -10, 25 ); 
        h_AODCaloJetAbsEta                 [i][k] = initSingleHistogramTH1F( hname_AODCaloJetAbsEta                 , "AODCaloJetAbsEta                        ", 4, 0, 3 );

	const int Pt_n_xbins = 10;
	float Pt_xbins[Pt_n_xbins+1] = {0, 10, 20, 30, 40, 50, 75, 100, 150, 250, 500};
	h_AODCaloJetPtVar  [i][k] = initSingleHistogramTH1F( hname_AODCaloJetPtVar , "AODCaloJetPtVar",  Pt_n_xbins, Pt_xbins );

	const int AbsEta_n_bins = 2;
	float AbsEta_bins[AbsEta_n_bins+1] = {0, 1.5, 2.4};
	h_AODCaloJetPtVarAbsEtaVar [i][k] = initSingleHistogramTH2F( hname_AODCaloJetPtVarAbsEtaVar, "AODCaloJetPtVarAbsEtaVar", Pt_n_xbins, Pt_xbins, AbsEta_n_bins, AbsEta_bins );
	h_AODCaloJetEtaVsPhi [i][k]       = initSingleHistogramTH2F( hname_AODCaloJetEtaVsPhi, "AODCaloJetEtaVsPhi", 30, -2.8, 2.8, 30, -3.2,3.2 );

      }
  }
  return kTRUE;
}

//----------------------------fillAODCaloJetBasicHistograms
Bool_t analyzer_histograms::fillAODCaloJetBasicHistograms(Float_t weight, int selbin, int jetbin)
{
  hist_file_out[selbin]->cd();
  if(jetmultnames.at(jetbin) == "AllJets"){
    // only fill these once (no jet multiplicity)
    h_nCaloJet                 [selbin]->Fill ( aodcalojet_list.size() , weight );
//    h_nPFJet                   [selbin]->Fill ( 1 , weight ); // dummy values 
//    h_nPFchsJet                [selbin]->Fill ( 1 , weight ); // dummy values 
    for(unsigned int i =0; i<aodcalojet_list.size(); i++){
      int aodcalojetindex = aodcalojet_list[i];
      if( AODCaloJet_emEnergyFraction->at( aodcalojetindex)>1.0 || AODCaloJet_emEnergyFraction->at(aodcalojetindex)<0.0   ){
        h_AODCaloJet_emEnergyFraction            [selbin][jetbin]->Fill( h_AODCaloJet_emEnergyFraction[selbin][jetbin]->GetBinCenter(101), weight );
        //std::cout<<"BinCenter: "<<h_AODCaloJet_emEnergyFraction[selbin][jetbin]->GetBinCenter(101)<<"  Value:"<<AODCaloJet_emEnergyFraction->at(aodcalojetindex)<<std::endl; 
      } 
      else
        h_AODCaloJet_emEnergyFraction            [selbin][jetbin]->Fill( AODCaloJet_emEnergyFraction              ->at( aodcalojetindex ), weight );  
      if( AODCaloJet_energyFractionHadronic->at( aodcalojetindex )>1.0 || AODCaloJet_energyFractionHadronic->at( aodcalojetindex )<0.0 ){
        h_AODCaloJet_energyFractionHadronic      [selbin][jetbin]->Fill( h_AODCaloJet_energyFractionHadronic[selbin][jetbin]->GetBinCenter(101), weight );  }
      else
        h_AODCaloJet_energyFractionHadronic      [selbin][jetbin]->Fill( AODCaloJet_energyFractionHadronic        ->at( aodcalojetindex ), weight );  
      h_AODCaloJetPt                             [selbin][jetbin]->Fill( AODCaloJetPt                             ->at( aodcalojetindex ), weight );  
      h_AODCaloJetPtVar                          [selbin][jetbin]->Fill( AODCaloJetPt                             ->at( aodcalojetindex ), weight );  
      h_AODCaloJetEta                            [selbin][jetbin]->Fill( AODCaloJetEta                            ->at( aodcalojetindex ), weight );  
      h_AODCaloJetPhi                            [selbin][jetbin]->Fill( AODCaloJetPhi                            ->at( aodcalojetindex ), weight );  
      h_AODCaloJetAlphaMax                       [selbin][jetbin]->Fill( Shifted_CaloJetAlphaMax                   .at( aodcalojetindex ), weight );  
      h_AODCaloJetAlphaMax_FineBin               [selbin][jetbin]->Fill( Shifted_CaloJetAlphaMax                   .at( aodcalojetindex ), weight );  
      h_AODCaloJetAlphaMax2                      [selbin][jetbin]->Fill( AODCaloJetAlphaMax2                      ->at( aodcalojetindex ), weight );  
      h_AODCaloJetAlphaMaxPrime                  [selbin][jetbin]->Fill( AODCaloJetAlphaMaxPrime                  ->at( aodcalojetindex ), weight );  
      h_AODCaloJetAlphaMaxPrime2                 [selbin][jetbin]->Fill( AODCaloJetAlphaMaxPrime2                 ->at( aodcalojetindex ), weight );  
      h_AODCaloJetBeta                           [selbin][jetbin]->Fill( AODCaloJetBeta                           ->at( aodcalojetindex ), weight );  
      h_AODCaloJetBeta2                          [selbin][jetbin]->Fill( AODCaloJetBeta2                          ->at( aodcalojetindex ), weight );  
      h_AODCaloJetSumIP                          [selbin][jetbin]->Fill( AODCaloJetSumIP                          ->at( aodcalojetindex ), weight );  
      h_AODCaloJetSumIPSig                       [selbin][jetbin]->Fill( AODCaloJetSumIPSig                       ->at( aodcalojetindex ), weight );  
      h_AODCaloJetMedianIP                       [selbin][jetbin]->Fill( AODCaloJetMedianIP                       ->at( aodcalojetindex ), weight );  
      h_AODCaloJetMedianLog10IPSig               [selbin][jetbin]->Fill( Shifted_CaloJetMedianLog10IPSig           .at( aodcalojetindex ), weight );  
      h_AODCaloJetMedianLog10IPSig_FineBin       [selbin][jetbin]->Fill( Shifted_CaloJetMedianLog10IPSig           .at( aodcalojetindex ), weight );  
      h_AODCaloJetMedianLog10TrackAngle          [selbin][jetbin]->Fill( Shifted_CaloJetMedianLog10TrackAngle      .at( aodcalojetindex ), weight );  
      h_AODCaloJetMedianLog10TrackAngle_FineBin  [selbin][jetbin]->Fill( Shifted_CaloJetMedianLog10TrackAngle      .at( aodcalojetindex ), weight );  
      h_AODCaloJetTotalTrackAngle                [selbin][jetbin]->Fill( AODCaloJetTotalTrackAngle                ->at( aodcalojetindex ), weight );  
      h_AODCaloJetMinDR                          [selbin][jetbin]->Fill( aodcalojet_minDR_list                     .at( aodcalojetindex ), weight );  
//      h_AODCaloJetCSV                            [selbin][jetbin]->Fill( aodcalojet_matchedCSV_list                .at( aodcalojetindex ), weight );  
//      h_AODCaloJetPartonFlavour                  [selbin][jetbin]->Fill( aodcalojet_matchedPartonFlavour_list      .at( aodcalojetindex ), weight );  
      h_AODCaloJetAbsEta                         [selbin][jetbin]->Fill( fabs(AODCaloJetEta                       ->at( aodcalojetindex )), weight );
      h_AODCaloJetPtVarAbsEtaVar                 [selbin][jetbin]->Fill( AODCaloJetPt->at(aodcalojetindex), fabs(AODCaloJetEta->at(aodcalojetindex)), weight );  
      h_AODCaloJetEtaVsPhi                       [selbin][jetbin]->Fill( AODCaloJetEta->at(aodcalojetindex), fabs(AODCaloJetPhi->at(aodcalojetindex)), weight );  
    }    
  }
  else{
    if( jetbin < (int)aodcalojet_list.size() ){
      int aodcalojetindex = aodcalojet_list[jetbin];
      if( AODCaloJet_emEnergyFraction->at( aodcalojetindex)>1.0 || AODCaloJet_emEnergyFraction->at(aodcalojetindex)<0.0   ){
        h_AODCaloJet_emEnergyFraction            [selbin][jetbin]->Fill( h_AODCaloJet_emEnergyFraction[selbin][jetbin]->GetBinCenter(101), weight );
        //std::cout<<"BinCenter: "<<h_AODCaloJet_emEnergyFraction[selbin][jetbin]->GetBinCenter(101)<<"  Value:"<<AODCaloJet_emEnergyFraction->at(aodcalojetindex)<<std::endl; 
      } 
      else
        h_AODCaloJet_emEnergyFraction            [selbin][jetbin]->Fill( AODCaloJet_emEnergyFraction              ->at( aodcalojetindex ), weight );  
      if( AODCaloJet_energyFractionHadronic->at( aodcalojetindex )>1.0 || AODCaloJet_energyFractionHadronic->at( aodcalojetindex )<0.0 ){
        h_AODCaloJet_energyFractionHadronic      [selbin][jetbin]->Fill( h_AODCaloJet_energyFractionHadronic[selbin][jetbin]->GetBinCenter(101), weight );  }
      else
        h_AODCaloJet_energyFractionHadronic      [selbin][jetbin]->Fill( AODCaloJet_energyFractionHadronic        ->at( aodcalojetindex ), weight );  
      h_AODCaloJetPt                             [selbin][jetbin]->Fill( AODCaloJetPt                             ->at( aodcalojetindex ), weight );  
      h_AODCaloJetPtVar                          [selbin][jetbin]->Fill( AODCaloJetPt                             ->at( aodcalojetindex ), weight );  
      h_AODCaloJetEta                            [selbin][jetbin]->Fill( AODCaloJetEta                            ->at( aodcalojetindex ), weight );  
      h_AODCaloJetPhi                            [selbin][jetbin]->Fill( AODCaloJetPhi                            ->at( aodcalojetindex ), weight );  
      h_AODCaloJetAlphaMax                       [selbin][jetbin]->Fill( Shifted_CaloJetAlphaMax                   .at( aodcalojetindex ), weight );  
      h_AODCaloJetAlphaMax_FineBin               [selbin][jetbin]->Fill( Shifted_CaloJetAlphaMax                   .at( aodcalojetindex ), weight );  
      h_AODCaloJetAlphaMax2                      [selbin][jetbin]->Fill( AODCaloJetAlphaMax2                      ->at( aodcalojetindex ), weight );  
      h_AODCaloJetAlphaMaxPrime                  [selbin][jetbin]->Fill( AODCaloJetAlphaMaxPrime                  ->at( aodcalojetindex ), weight );  
      h_AODCaloJetAlphaMaxPrime2                 [selbin][jetbin]->Fill( AODCaloJetAlphaMaxPrime2                 ->at( aodcalojetindex ), weight );  
      h_AODCaloJetBeta                           [selbin][jetbin]->Fill( AODCaloJetBeta                           ->at( aodcalojetindex ), weight );  
      h_AODCaloJetBeta2                          [selbin][jetbin]->Fill( AODCaloJetBeta2                          ->at( aodcalojetindex ), weight );  
      h_AODCaloJetSumIP                          [selbin][jetbin]->Fill( AODCaloJetSumIP                          ->at( aodcalojetindex ), weight );  
      h_AODCaloJetSumIPSig                       [selbin][jetbin]->Fill( AODCaloJetSumIPSig                       ->at( aodcalojetindex ), weight );  
      h_AODCaloJetMedianIP                       [selbin][jetbin]->Fill( AODCaloJetMedianIP                       ->at( aodcalojetindex ), weight );  
      h_AODCaloJetMedianLog10IPSig               [selbin][jetbin]->Fill( Shifted_CaloJetMedianLog10IPSig           .at( aodcalojetindex ), weight );  
      h_AODCaloJetMedianLog10IPSig_FineBin       [selbin][jetbin]->Fill( Shifted_CaloJetMedianLog10IPSig           .at( aodcalojetindex ), weight );  
      h_AODCaloJetMedianLog10TrackAngle          [selbin][jetbin]->Fill( Shifted_CaloJetMedianLog10TrackAngle      .at( aodcalojetindex ), weight );  
      h_AODCaloJetMedianLog10TrackAngle_FineBin  [selbin][jetbin]->Fill( Shifted_CaloJetMedianLog10TrackAngle      .at( aodcalojetindex ), weight );  
      h_AODCaloJetTotalTrackAngle                [selbin][jetbin]->Fill( AODCaloJetTotalTrackAngle                ->at( aodcalojetindex ), weight );  
      h_AODCaloJetMinDR                          [selbin][jetbin]->Fill( aodcalojet_minDR_list                     .at( aodcalojetindex ), weight );  
//      h_AODCaloJetCSV                            [selbin][jetbin]->Fill( aodcalojet_matchedCSV_list                .at( aodcalojetindex ), weight );  
//      h_AODCaloJetPartonFlavour                  [selbin][jetbin]->Fill( aodcalojet_matchedPartonFlavour_list      .at( aodcalojetindex ), weight );  
      h_AODCaloJetAbsEta                         [selbin][jetbin]->Fill( fabs(AODCaloJetEta                       ->at( aodcalojetindex )), weight );
      h_AODCaloJetPtVarAbsEtaVar                 [selbin][jetbin]->Fill( AODCaloJetPt->at(aodcalojetindex), fabs(AODCaloJetEta->at(aodcalojetindex)), weight );  
      h_AODCaloJetEtaVsPhi                       [selbin][jetbin]->Fill( AODCaloJetEta->at(aodcalojetindex), AODCaloJetPhi->at(aodcalojetindex), weight );  
    }
  }
  
  return kTRUE;
} //end fill histograms

//----------------------------writeAODCaloJetHistograms
Bool_t analyzer_histograms::writeAODCaloJetBasicHistograms(int selbin, int jetbin)
{
  hist_file_out[selbin]->cd();
  //printf("writeAODCaloJetHistograms\n");
  if(jetbin==0){
   h_nCaloJet                 [selbin]->Write();
//   h_nPFJet                   [selbin]->Write();
//   h_nPFchsJet                [selbin]->Write();
  }
  h_AODCaloJet_emEnergyFraction              [selbin][jetbin]->Write(); 
  h_AODCaloJet_energyFractionHadronic        [selbin][jetbin]->Write(); 
  h_AODCaloJetPt                             [selbin][jetbin]->Write(); 
  h_AODCaloJetPtVar                          [selbin][jetbin]->Write(); 
  h_AODCaloJetEta                            [selbin][jetbin]->Write(); 
  h_AODCaloJetPhi                            [selbin][jetbin]->Write(); 
  h_AODCaloJetAlphaMax                       [selbin][jetbin]->Write(); 
  h_AODCaloJetAlphaMax_FineBin               [selbin][jetbin]->Write(); 
  h_AODCaloJetAlphaMax2                      [selbin][jetbin]->Write(); 
  h_AODCaloJetAlphaMaxPrime                  [selbin][jetbin]->Write(); 
  h_AODCaloJetAlphaMaxPrime2                 [selbin][jetbin]->Write(); 
  h_AODCaloJetBeta                           [selbin][jetbin]->Write(); 
  h_AODCaloJetBeta2                          [selbin][jetbin]->Write(); 
  h_AODCaloJetSumIP                          [selbin][jetbin]->Write(); 
  h_AODCaloJetSumIPSig                       [selbin][jetbin]->Write(); 
  h_AODCaloJetMedianIP                       [selbin][jetbin]->Write(); 
  h_AODCaloJetMedianLog10IPSig               [selbin][jetbin]->Write(); 
  h_AODCaloJetMedianLog10IPSig_FineBin       [selbin][jetbin]->Write(); 
  h_AODCaloJetTrackAngle                     [selbin][jetbin]->Write(); 
  h_AODCaloJetLogTrackAngle                  [selbin][jetbin]->Write(); 
  h_AODCaloJetMedianLog10TrackAngle          [selbin][jetbin]->Write(); 
  h_AODCaloJetMedianLog10TrackAngle_FineBin  [selbin][jetbin]->Write(); 
  h_AODCaloJetTotalTrackAngle                [selbin][jetbin]->Write(); 
  h_AODCaloJetMinDR                          [selbin][jetbin]->Write(); 
//  h_AODCaloJetCSV                            [selbin][jetbin]->Write(); 
//  h_AODCaloJetPartonFlavour                  [selbin][jetbin]->Write(); 
  h_AODCaloJetAbsEta                         [selbin][jetbin]->Write();
  h_AODCaloJetPtVarAbsEtaVar                 [selbin][jetbin]->Write(); 
  h_AODCaloJetEtaVsPhi                       [selbin][jetbin]->Write(); 
 return kTRUE;
}

Bool_t analyzer_histograms::deleteAODCaloJetBasicHistograms(int selbin)
{
  //printf("deleteAODCaloJetBasicHistograms\n");
  hist_file_out[selbin]->cd();
  if(h_nCaloJet  [selbin]!=NULL)    h_nCaloJet                 [selbin]->Delete();
//  if(h_nPFJet    [selbin]!=NULL)    h_nPFJet                   [selbin]->Delete();
//  if(h_nPFchsJet [selbin]!=NULL)    h_nPFchsJet                [selbin]->Delete();
 return kTRUE;
}

//----------------------------deleteAODCaloJetHistograms
Bool_t analyzer_histograms::deleteAODCaloJetBasicHistograms(int selbin, int jetbin)
{
  hist_file_out[selbin]->cd();
  //printf("deleteAODCaloJetHistograms\n");
  if(h_AODCaloJet_emEnergyFraction    [selbin][jetbin]!=NULL)    h_AODCaloJet_emEnergyFraction              [selbin][jetbin]->Delete(); 
  if(h_AODCaloJet_energyFractionHadronic [selbin][jetbin]!=NULL) h_AODCaloJet_energyFractionHadronic        [selbin][jetbin]->Delete(); 
  if(h_AODCaloJetPt                   [selbin][jetbin]!=NULL)    h_AODCaloJetPt                             [selbin][jetbin]->Delete(); 
  if(h_AODCaloJetPtVar                [selbin][jetbin]!=NULL)    h_AODCaloJetPtVar                          [selbin][jetbin]->Delete(); 
  if(h_AODCaloJetEta                  [selbin][jetbin]!=NULL)    h_AODCaloJetEta                            [selbin][jetbin]->Delete(); 
  if(h_AODCaloJetPhi                  [selbin][jetbin]!=NULL)    h_AODCaloJetPhi                            [selbin][jetbin]->Delete(); 
  if(h_AODCaloJetAlphaMax             [selbin][jetbin]!=NULL)    h_AODCaloJetAlphaMax                       [selbin][jetbin]->Delete(); 
  if(h_AODCaloJetAlphaMax_FineBin     [selbin][jetbin]!=NULL)    h_AODCaloJetAlphaMax_FineBin               [selbin][jetbin]->Delete(); 
  if(h_AODCaloJetAlphaMax2            [selbin][jetbin]!=NULL)    h_AODCaloJetAlphaMax2                      [selbin][jetbin]->Delete(); 
  if(h_AODCaloJetAlphaMaxPrime        [selbin][jetbin]!=NULL)    h_AODCaloJetAlphaMaxPrime                  [selbin][jetbin]->Delete(); 
  if(h_AODCaloJetAlphaMaxPrime2       [selbin][jetbin]!=NULL)    h_AODCaloJetAlphaMaxPrime2                 [selbin][jetbin]->Delete(); 
  if(h_AODCaloJetBeta                 [selbin][jetbin]!=NULL)    h_AODCaloJetBeta                           [selbin][jetbin]->Delete(); 
  if(h_AODCaloJetBeta2                [selbin][jetbin]!=NULL)    h_AODCaloJetBeta2                          [selbin][jetbin]->Delete(); 
  if(h_AODCaloJetSumIP                [selbin][jetbin]!=NULL)    h_AODCaloJetSumIP                          [selbin][jetbin]->Delete(); 
  if(h_AODCaloJetSumIPSig             [selbin][jetbin]!=NULL)    h_AODCaloJetSumIPSig                       [selbin][jetbin]->Delete(); 
  if(h_AODCaloJetMedianIP             [selbin][jetbin]!=NULL)    h_AODCaloJetMedianIP                       [selbin][jetbin]->Delete(); 
  if(h_AODCaloJetMedianLog10IPSig     [selbin][jetbin]!=NULL)    h_AODCaloJetMedianLog10IPSig               [selbin][jetbin]->Delete(); 
  if(h_AODCaloJetMedianLog10IPSig_FineBin[selbin][jetbin]!=NULL)    h_AODCaloJetMedianLog10IPSig_FineBin    [selbin][jetbin]->Delete(); 
  if(h_AODCaloJetTrackAngle           [selbin][jetbin]!=NULL)    h_AODCaloJetTrackAngle                     [selbin][jetbin]->Delete(); 
  if(h_AODCaloJetLogTrackAngle        [selbin][jetbin]!=NULL)    h_AODCaloJetLogTrackAngle                  [selbin][jetbin]->Delete(); 
  if(h_AODCaloJetMedianLog10TrackAngle[selbin][jetbin]!=NULL)    h_AODCaloJetMedianLog10TrackAngle          [selbin][jetbin]->Delete(); 
  if(h_AODCaloJetMedianLog10TrackAngle_FineBin[selbin][jetbin]!=NULL)    h_AODCaloJetMedianLog10TrackAngle_FineBin          [selbin][jetbin]->Delete(); 
  if(h_AODCaloJetTotalTrackAngle      [selbin][jetbin]!=NULL)    h_AODCaloJetTotalTrackAngle                [selbin][jetbin]->Delete(); 
  if(h_AODCaloJetMinDR                [selbin][jetbin]!=NULL)    h_AODCaloJetMinDR                          [selbin][jetbin]->Delete(); 
//  if(h_AODCaloJetCSV                  [selbin][jetbin]!=NULL)    h_AODCaloJetCSV                            [selbin][jetbin]->Delete(); 
//  if(h_AODCaloJetPartonFlavour        [selbin][jetbin]!=NULL)    h_AODCaloJetPartonFlavour                  [selbin][jetbin]->Delete(); 
  if(h_AODCaloJetAbsEta               [selbin][jetbin]!=NULL)    h_AODCaloJetAbsEta                         [selbin][jetbin]->Delete();
  if(h_AODCaloJetPtVarAbsEtaVar       [selbin][jetbin]!=NULL)    h_AODCaloJetPtVarAbsEtaVar                 [selbin][jetbin]->Delete(); 
  if(h_AODCaloJetEtaVsPhi             [selbin][jetbin]!=NULL)    h_AODCaloJetEtaVsPhi                       [selbin][jetbin]->Delete(); 
 return kTRUE;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
///                         For L1 Pre-firing test                                                 ////
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////

///// Jet Histograms
//----------------------------initAODCaloJet_L1PFBasicHistograms
Bool_t analyzer_histograms::initAODCaloJet_L1PFHistograms( TString uncbin )
{
  // loop through jets and selections to initialize histograms in parllel (series)
  for(unsigned int i=0; i<selbinnames.size(); ++i){
      hist_file_out[i]->cd();
      //deleteAODCaloJet_L1PFHistograms(i);
      TString hname_nCaloJet_L1PF = "h_"+selbinnames[i]+"_nCaloJet_L1PF" +uncbin;
      h_nCaloJet_L1PF        [i] = initSingleHistogramTH1F( hname_nCaloJet_L1PF, "nCaloJet_L1PF",  10,0,10);
      
      TString hname_nSelectedAODCaloJet_L1PFTag  = "h_"+selbinnames[i]+"_nSelectedAODCaloJet_L1PFTag"+uncbin;
      h_nSelectedAODCaloJet_L1PFTag         [i] = initSingleHistogramTH1F( hname_nSelectedAODCaloJet_L1PFTag, "nSelectedAODCaloJet_L1PFTag", 6, -0.5, 5.5);
      unsigned int k; if(jetMultOn) k=0; else k=jetmultnames.size()-1;
      for(k; k<jetmultnames.size(); ++k){
        //deleteAODCaloJet_L1PFHistograms(i,k);
        TString hname_AODCaloJet_L1PFPt                            = "h_"+selbinnames[i]+"_"+jetmultnames[k]+"_AODCaloJet_L1PFPt"                   +uncbin;                                  
        //TString hname_AODCaloJet_L1PFPtVar                         = "h_"+selbinnames[i]+"_"+jetmultnames[k]+"_AODCaloJet_L1PFPtVar"                +uncbin;                                                            
        //TString hname_AODCaloJet_L1PFEta                           = "h_"+selbinnames[i]+"_"+jetmultnames[k]+"_AODCaloJet_L1PFEta"                  +uncbin;                                      
        //TString hname_AODCaloJet_L1PFPhi                           = "h_"+selbinnames[i]+"_"+jetmultnames[k]+"_AODCaloJet_L1PFPhi"                  +uncbin;                                      
        TString hname_AODCaloJet_L1PFAlphaMax                      = "h_"+selbinnames[i]+"_"+jetmultnames[k]+"_AODCaloJet_L1PFAlphaMax"             +uncbin;                                      
        //TString hname_AODCaloJet_L1PFAlphaMax2                     = "h_"+selbinnames[i]+"_"+jetmultnames[k]+"_AODCaloJet_L1PFAlphaMax2"            +uncbin;                                      
        //TString hname_AODCaloJet_L1PFAlphaMaxPrime                 = "h_"+selbinnames[i]+"_"+jetmultnames[k]+"_AODCaloJet_L1PFAlphaMaxPrime"        +uncbin;                                      
        //TString hname_AODCaloJet_L1PFAlphaMaxPrime2                = "h_"+selbinnames[i]+"_"+jetmultnames[k]+"_AODCaloJet_L1PFAlphaMaxPrime2"       +uncbin;                                      
        //TString hname_AODCaloJet_L1PFBeta                          = "h_"+selbinnames[i]+"_"+jetmultnames[k]+"_AODCaloJet_L1PFBeta"                 +uncbin;                                      
        //TString hname_AODCaloJet_L1PFBeta2                         = "h_"+selbinnames[i]+"_"+jetmultnames[k]+"_AODCaloJet_L1PFBeta2"                +uncbin;                                      
        //TString hname_AODCaloJet_L1PFSumIP                         = "h_"+selbinnames[i]+"_"+jetmultnames[k]+"_AODCaloJet_L1PFSumIP"                +uncbin;                                      
        //TString hname_AODCaloJet_L1PFSumIPSig                      = "h_"+selbinnames[i]+"_"+jetmultnames[k]+"_AODCaloJet_L1PFSumIPSig"             +uncbin;                                      
        //TString hname_AODCaloJet_L1PFMedianIP                      = "h_"+selbinnames[i]+"_"+jetmultnames[k]+"_AODCaloJet_L1PFMedianIP"             +uncbin;                                      
        TString hname_AODCaloJet_L1PFMedianLog10IPSig              = "h_"+selbinnames[i]+"_"+jetmultnames[k]+"_AODCaloJet_L1PFMedianLog10IPSig"     +uncbin;                                      
        //TString hname_AODCaloJet_L1PFTrackAngle                    = "h_"+selbinnames[i]+"_"+jetmultnames[k]+"_AODCaloJet_L1PFTrackAngle"           +uncbin;                                      
        //TString hname_AODCaloJet_L1PFLogTrackAngle                 = "h_"+selbinnames[i]+"_"+jetmultnames[k]+"_AODCaloJet_L1PFLogTrackAngle"        +uncbin;                                      
        TString hname_AODCaloJet_L1PFMedianLog10TrackAngle         = "h_"+selbinnames[i]+"_"+jetmultnames[k]+"_AODCaloJet_L1PFMedianLog10TrackAngle"+uncbin;                                      
        //TString hname_AODCaloJet_L1PFTotalTrackAngle               = "h_"+selbinnames[i]+"_"+jetmultnames[k]+"_AODCaloJet_L1PFTotalTrackAngle"      +uncbin;                                      
        //  TString hname_AODCaloJet_L1PFAbsEta                        = "h_"+selbinnames[i]+"_"+jetmultnames[k]+"_AODCaloJet_L1PFAbsEta"               +uncbin;             
        //TString hname_AODCaloJet_L1PFPtVarAbsEtaVar                = "h_"+selbinnames[i]+"_"+jetmultnames[k]+"_AODCaloJet_L1PFPtVarAbsEtaVar"       +uncbin;                                                  
        //
        h_AODCaloJet_L1PFPt                             [i][k] = initSingleHistogramTH1F( hname_AODCaloJet_L1PFPt                             , "AODCaloJet_L1PFPt                            ", 50,0,500  ); 
        //h_AODCaloJet_L1PFEta                            [i][k] = initSingleHistogramTH1F( hname_AODCaloJet_L1PFEta                            , "AODCaloJet_L1PFEta                           ", 30,-5,5   ); 
        //h_AODCaloJet_L1PFPhi                            [i][k] = initSingleHistogramTH1F( hname_AODCaloJet_L1PFPhi                            , "AODCaloJet_L1PFPhi                           ", 30,-5,5   ); 
        h_AODCaloJet_L1PFAlphaMax                       [i][k] = initSingleHistogramTH1F( hname_AODCaloJet_L1PFAlphaMax                       , "AODCaloJet_L1PFAlphaMax                      ", 30, 0, 1  ); 
        //h_AODCaloJet_L1PFAlphaMax2                      [i][k] = initSingleHistogramTH1F( hname_AODCaloJet_L1PFAlphaMax2                      , "AODCaloJet_L1PFAlphaMax2                     ", 30, 0, 1  ); 
        //h_AODCaloJet_L1PFAlphaMaxPrime                  [i][k] = initSingleHistogramTH1F( hname_AODCaloJet_L1PFAlphaMaxPrime                  , "AODCaloJet_L1PFAlphaMaxPrime                 ", 30, 0, 1  ); 
        //h_AODCaloJet_L1PFAlphaMaxPrime2                 [i][k] = initSingleHistogramTH1F( hname_AODCaloJet_L1PFAlphaMaxPrime2                 , "AODCaloJet_L1PFAlphaMaxPrime2                ", 30, 0, 1  ); 
        //h_AODCaloJet_L1PFBeta                           [i][k] = initSingleHistogramTH1F( hname_AODCaloJet_L1PFBeta                           , "AODCaloJet_L1PFBeta                          ", 30, 0, 1  ); 
        //h_AODCaloJet_L1PFBeta2                          [i][k] = initSingleHistogramTH1F( hname_AODCaloJet_L1PFBeta2                          , "AODCaloJet_L1PFBeta2                         ", 30, 0, 1  ); 
        //h_AODCaloJet_L1PFSumIP                          [i][k] = initSingleHistogramTH1F( hname_AODCaloJet_L1PFSumIP                          , "AODCaloJet_L1PFSumIP                         ", 30, -3, 3 ); 
        //h_AODCaloJet_L1PFSumIPSig                       [i][k] = initSingleHistogramTH1F( hname_AODCaloJet_L1PFSumIPSig                       , "AODCaloJet_L1PFSumIPSig                      ", 30, -3, 3 ); 
        //h_AODCaloJet_L1PFMedianIP                       [i][k] = initSingleHistogramTH1F( hname_AODCaloJet_L1PFMedianIP                       , "AODCaloJet_L1PFMedianIP                      ", 30, -3, 3 ); 
        h_AODCaloJet_L1PFMedianLog10IPSig               [i][k] = initSingleHistogramTH1F( hname_AODCaloJet_L1PFMedianLog10IPSig               , "AODCaloJet_L1PFMedianLog10IPSig              ", 30, -3, 3 ); 
        //h_AODCaloJet_L1PFTrackAngle                     [i][k] = initSingleHistogramTH1F( hname_AODCaloJet_L1PFTrackAngle                     , "AODCaloJet_L1PFTrackAngle                    ", 30, -3, 3 ); 
        //h_AODCaloJet_L1PFLogTrackAngle                  [i][k] = initSingleHistogramTH1F( hname_AODCaloJet_L1PFLogTrackAngle                  , "AODCaloJet_L1PFLogTrackAngle                 ", 30, -3, 3 ); 
        h_AODCaloJet_L1PFMedianLog10TrackAngle          [i][k] = initSingleHistogramTH1F( hname_AODCaloJet_L1PFMedianLog10TrackAngle          , "AODCaloJet_L1PFMedianLog10TrackAngle         ", 30, -5, 1 ); 
        //h_AODCaloJet_L1PFTotalTrackAngle                [i][k] = initSingleHistogramTH1F( hname_AODCaloJet_L1PFTotalTrackAngle                , "AODCaloJet_L1PFTotalTrackAngle               ", 30, -3, 3 ); 
        //  h_AODCaloJet_L1PFAbsEta                         [i][k] = initSingleHistogramTH1F( hname_AODCaloJet_L1PFAbsEta                         , "AODCaloJet_L1PFAbsEta                        ", 4, 0, 3 );

	//const int Pt_n_xbins = 10;
	//float Pt_xbins[Pt_n_xbins+1] = {0, 10, 20, 30, 40, 50, 75, 100, 150, 250, 500};
	//h_AODCaloJet_L1PFPtVar  [i][k] = initSingleHistogramTH1F( hname_AODCaloJet_L1PFPtVar , "AODCaloJet_L1PFPtVar",  Pt_n_xbins, Pt_xbins );
	
	//const int AbsEta_n_bins = 2;
	//float AbsEta_bins[AbsEta_n_bins+1] = {0, 1.5, 2.4};
	//h_AODCaloJet_L1PFPtVarAbsEtaVar [i][k] = initSingleHistogramTH2F( hname_AODCaloJet_L1PFPtVarAbsEtaVar, "AODCaloJet_L1PFPtVarAbsEtaVar", Pt_n_xbins, Pt_xbins, AbsEta_n_bins, AbsEta_bins );

      }
  }
  return kTRUE;
}

//----------------------------fillAODCaloJet_L1PFHistograms
Bool_t analyzer_histograms::fillAODCaloJet_L1PFHistograms(Float_t weight, int selbin, int jetbin)
{
  hist_file_out[selbin]->cd();
  if(jetmultnames.at(jetbin) == "AllJets"){
    // only fill these once (no jet multiplicity)
    h_nCaloJet_L1PF                 [selbin]->Fill ( aodcalojet_L1PF_list.size() , weight );
    if(!L1PFremoved)  h_nSelectedAODCaloJet_L1PFTag       [selbin] ->Fill( float(taggedjet_list_L1PF.size()), weight );
    for(unsigned int i =0; i<aodcalojet_L1PF_list.size(); i++){
      int aodcalojet_L1PFindex = aodcalojet_L1PF_list[i];
      h_AODCaloJet_L1PFPt                             [selbin][jetbin]->Fill( AODCaloJetPt                             ->at( aodcalojet_L1PFindex ), weight );  
      //h_AODCaloJet_L1PFPtVar                          [selbin][jetbin]->Fill( AODCaloJetPt                             ->at( aodcalojet_L1PFindex ), weight );  
      //h_AODCaloJet_L1PFEta                            [selbin][jetbin]->Fill( AODCaloJetEta                            ->at( aodcalojet_L1PFindex ), weight );  
      //h_AODCaloJet_L1PFPhi                            [selbin][jetbin]->Fill( AODCaloJetPhi                            ->at( aodcalojet_L1PFindex ), weight );  
      h_AODCaloJet_L1PFAlphaMax                       [selbin][jetbin]->Fill( AODCaloJetAlphaMax                       ->at( aodcalojet_L1PFindex ), weight );  
      //h_AODCaloJet_L1PFAlphaMax2                      [selbin][jetbin]->Fill( AODCaloJetAlphaMax2                      ->at( aodcalojet_L1PFindex ), weight );  
      //h_AODCaloJet_L1PFAlphaMaxPrime                  [selbin][jetbin]->Fill( AODCaloJetAlphaMaxPrime                  ->at( aodcalojet_L1PFindex ), weight );  
      //h_AODCaloJet_L1PFAlphaMaxPrime2                 [selbin][jetbin]->Fill( AODCaloJetAlphaMaxPrime2                 ->at( aodcalojet_L1PFindex ), weight );  
      //h_AODCaloJet_L1PFBeta                           [selbin][jetbin]->Fill( AODCaloJetBeta                           ->at( aodcalojet_L1PFindex ), weight );  
      //h_AODCaloJet_L1PFBeta2                          [selbin][jetbin]->Fill( AODCaloJetBeta2                          ->at( aodcalojet_L1PFindex ), weight );  
      //h_AODCaloJet_L1PFSumIP                          [selbin][jetbin]->Fill( AODCaloJetSumIP                          ->at( aodcalojet_L1PFindex ), weight );  
      //h_AODCaloJet_L1PFSumIPSig                       [selbin][jetbin]->Fill( AODCaloJetSumIPSig                       ->at( aodcalojet_L1PFindex ), weight );  
      //h_AODCaloJet_L1PFMedianIP                       [selbin][jetbin]->Fill( AODCaloJetMedianIP                       ->at( aodcalojet_L1PFindex ), weight );  
      h_AODCaloJet_L1PFMedianLog10IPSig               [selbin][jetbin]->Fill( AODCaloJetMedianLog10IPSig               ->at( aodcalojet_L1PFindex ), weight );  
      h_AODCaloJet_L1PFMedianLog10TrackAngle          [selbin][jetbin]->Fill( AODCaloJetMedianLog10TrackAngle          ->at( aodcalojet_L1PFindex ), weight );  
      //h_AODCaloJet_L1PFTotalTrackAngle                [selbin][jetbin]->Fill( AODCaloJetTotalTrackAngle                ->at( aodcalojet_L1PFindex ), weight );  
      //h_AODCaloJet_L1PFPtVarAbsEtaVar                 [selbin][jetbin]->Fill( AODCaloJetPt->at(aodcalojet_L1PFindex), fabs(AODCaloJetEta->at(aodcalojet_L1PFindex)), weight );  
    }    
  }
  else{
    if( jetbin < (int)aodcalojet_L1PF_list.size() ){
      int aodcalojet_L1PFindex = aodcalojet_L1PF_list[jetbin];
      h_AODCaloJet_L1PFPt                             [selbin][jetbin]->Fill( AODCaloJetPt                             ->at( aodcalojet_L1PFindex ), weight );  
      //h_AODCaloJet_L1PFPtVar                          [selbin][jetbin]->Fill( AODCaloJetPt                             ->at( aodcalojet_L1PFindex ), weight );  
      //h_AODCaloJet_L1PFEta                            [selbin][jetbin]->Fill( AODCaloJetEta                            ->at( aodcalojet_L1PFindex ), weight );  
      //h_AODCaloJet_L1PFPhi                            [selbin][jetbin]->Fill( AODCaloJetPhi                            ->at( aodcalojet_L1PFindex ), weight );  
      h_AODCaloJet_L1PFAlphaMax                       [selbin][jetbin]->Fill( AODCaloJetAlphaMax                       ->at( aodcalojet_L1PFindex ), weight );  
      //h_AODCaloJet_L1PFAlphaMax2                      [selbin][jetbin]->Fill( AODCaloJetAlphaMax2                      ->at( aodcalojet_L1PFindex ), weight );  
      //h_AODCaloJet_L1PFAlphaMaxPrime                  [selbin][jetbin]->Fill( AODCaloJetAlphaMaxPrime                  ->at( aodcalojet_L1PFindex ), weight );  
      //h_AODCaloJet_L1PFAlphaMaxPrime2                 [selbin][jetbin]->Fill( AODCaloJetAlphaMaxPrime2                 ->at( aodcalojet_L1PFindex ), weight );  
      //h_AODCaloJet_L1PFBeta                           [selbin][jetbin]->Fill( AODCaloJetBeta                           ->at( aodcalojet_L1PFindex ), weight );  
      //h_AODCaloJet_L1PFBeta2                          [selbin][jetbin]->Fill( AODCaloJetBeta2                          ->at( aodcalojet_L1PFindex ), weight );  
      //h_AODCaloJet_L1PFSumIP                          [selbin][jetbin]->Fill( AODCaloJetSumIP                          ->at( aodcalojet_L1PFindex ), weight );  
      //h_AODCaloJet_L1PFSumIPSig                       [selbin][jetbin]->Fill( AODCaloJetSumIPSig                       ->at( aodcalojet_L1PFindex ), weight );  
      //h_AODCaloJet_L1PFMedianIP                       [selbin][jetbin]->Fill( AODCaloJetMedianIP                       ->at( aodcalojet_L1PFindex ), weight );  
      h_AODCaloJet_L1PFMedianLog10IPSig               [selbin][jetbin]->Fill( AODCaloJetMedianLog10IPSig               ->at( aodcalojet_L1PFindex ), weight );  
      h_AODCaloJet_L1PFMedianLog10TrackAngle          [selbin][jetbin]->Fill( AODCaloJetMedianLog10TrackAngle          ->at( aodcalojet_L1PFindex ), weight );  
      //h_AODCaloJet_L1PFTotalTrackAngle                [selbin][jetbin]->Fill( AODCaloJetTotalTrackAngle                ->at( aodcalojet_L1PFindex ), weight );  
      //h_AODCaloJet_L1PFAbsEta                         [selbin][jetbin]->Fill( fabs(AODCaloJetEta                       ->at( aodcalojet_L1PFindex )), weight );
      //h_AODCaloJet_L1PFPtVarAbsEtaVar                 [selbin][jetbin]->Fill( AODCaloJetPt->at(aodcalojet_L1PFindex), fabs(AODCaloJetEta->at(aodcalojet_L1PFindex)), weight );  
    }
  }
  
  return kTRUE;
} //end fill histograms

//----------------------------writeAODCaloJet_L1PFHistograms
Bool_t analyzer_histograms::writeAODCaloJet_L1PFHistograms(int selbin, int jetbin)
{
  hist_file_out[selbin]->cd();
  //printf("writeAODCaloJet_L1PFHistograms\n");
  if(jetbin==0){
   h_nCaloJet_L1PF                 [selbin]->Write();
   h_nSelectedAODCaloJet_L1PFTag   [selbin]->Write();
  }
  h_AODCaloJet_L1PFPt                             [selbin][jetbin]->Write(); 
  //h_AODCaloJet_L1PFPtVar                          [selbin][jetbin]->Write(); 
  //h_AODCaloJet_L1PFEta                            [selbin][jetbin]->Write(); 
  //h_AODCaloJet_L1PFPhi                            [selbin][jetbin]->Write(); 
  h_AODCaloJet_L1PFAlphaMax                       [selbin][jetbin]->Write(); 
  //h_AODCaloJet_L1PFAlphaMax2                      [selbin][jetbin]->Write(); 
  //h_AODCaloJet_L1PFAlphaMaxPrime                  [selbin][jetbin]->Write(); 
  //h_AODCaloJet_L1PFAlphaMaxPrime2                 [selbin][jetbin]->Write(); 
  //h_AODCaloJet_L1PFBeta                           [selbin][jetbin]->Write(); 
  //h_AODCaloJet_L1PFBeta2                          [selbin][jetbin]->Write(); 
  //h_AODCaloJet_L1PFSumIP                          [selbin][jetbin]->Write(); 
  //h_AODCaloJet_L1PFSumIPSig                       [selbin][jetbin]->Write(); 
  //h_AODCaloJet_L1PFMedianIP                       [selbin][jetbin]->Write(); 
  h_AODCaloJet_L1PFMedianLog10IPSig               [selbin][jetbin]->Write(); 
  //h_AODCaloJet_L1PFTrackAngle                     [selbin][jetbin]->Write(); 
  //h_AODCaloJet_L1PFLogTrackAngle                  [selbin][jetbin]->Write(); 
  h_AODCaloJet_L1PFMedianLog10TrackAngle          [selbin][jetbin]->Write(); 
  //h_AODCaloJet_L1PFTotalTrackAngle                [selbin][jetbin]->Write(); 
  //h_AODCaloJet_L1PFAbsEta                         [selbin][jetbin]->Write();
  //h_AODCaloJet_L1PFPtVarAbsEtaVar                 [selbin][jetbin]->Write(); 
 return kTRUE;
}

//----------------------------deleteAODCaloJet_L1PFHistograms
Bool_t analyzer_histograms::deleteAODCaloJet_L1PFHistograms(int selbin)
{
  //printf("deleteAODCaloJet_L1PFHistograms\n");
  hist_file_out[selbin]->cd();
  if(h_nCaloJet_L1PF              [selbin]!=NULL)   h_nCaloJet_L1PF              [selbin]->Delete();
  if(h_nSelectedAODCaloJet_L1PFTag[selbin]!=NULL)   h_nSelectedAODCaloJet_L1PFTag[selbin] ->Delete();
  return kTRUE;
}

//----------------------------deleteAODCaloJet_L1PFHistograms
Bool_t analyzer_histograms::deleteAODCaloJet_L1PFHistograms(int selbin, int jetbin)
{
  //printf("deleteAODCaloJet_L1PFHistograms\n");
  hist_file_out[selbin]->cd();

  if(h_AODCaloJet_L1PFPt                    [selbin][jetbin]!=NULL)   h_AODCaloJet_L1PFPt                             [selbin][jetbin]->Delete(); 
  ///if(h_AODCaloJet_L1PFPtVar               [selbin][jetbin]!=NULL)   //h_AODCaloJet_L1PFPtVar                          [selbin][jetbin]->Delete(); 
  ///if(h_AODCaloJet_L1PFEta                 [selbin][jetbin]!=NULL)   //h_AODCaloJet_L1PFEta                            [selbin][jetbin]->Delete(); 
  ///if(h_AODCaloJet_L1PFPhi                 [selbin][jetbin]!=NULL)   //h_AODCaloJet_L1PFPhi                            [selbin][jetbin]->Delete(); 
  if(h_AODCaloJet_L1PFAlphaMax              [selbin][jetbin]!=NULL)   h_AODCaloJet_L1PFAlphaMax                       [selbin][jetbin]->Delete(); 
  ///if(h_AODCaloJet_L1PFAlphaMax2           [selbin][jetbin]!=NULL)   //h_AODCaloJet_L1PFAlphaMax2                      [selbin][jetbin]->Delete(); 
  ///if(h_AODCaloJet_L1PFAlphaMaxPrime       [selbin][jetbin]!=NULL)   //h_AODCaloJet_L1PFAlphaMaxPrime                  [selbin][jetbin]->Delete(); 
  ///if(h_AODCaloJet_L1PFAlphaMaxPrime2      [selbin][jetbin]!=NULL)   //h_AODCaloJet_L1PFAlphaMaxPrime2                 [selbin][jetbin]->Delete(); 
  ///if(h_AODCaloJet_L1PFBeta                [selbin][jetbin]!=NULL)   //h_AODCaloJet_L1PFBeta                           [selbin][jetbin]->Delete(); 
  ///if(h_AODCaloJet_L1PFBeta2               [selbin][jetbin]!=NULL)   //h_AODCaloJet_L1PFBeta2                          [selbin][jetbin]->Delete(); 
  ///if(h_AODCaloJet_L1PFSumIP               [selbin][jetbin]!=NULL)   //h_AODCaloJet_L1PFSumIP                          [selbin][jetbin]->Delete(); 
  ///if(h_AODCaloJet_L1PFSumIPSig            [selbin][jetbin]!=NULL)   //h_AODCaloJet_L1PFSumIPSig                       [selbin][jetbin]->Delete(); 
  ///if(h_AODCaloJet_L1PFMedianIP            [selbin][jetbin]!=NULL)   //h_AODCaloJet_L1PFMedianIP                       [selbin][jetbin]->Delete(); 
  if(h_AODCaloJet_L1PFMedianLog10IPSig      [selbin][jetbin]!=NULL)   h_AODCaloJet_L1PFMedianLog10IPSig               [selbin][jetbin]->Delete(); 
  ///if(h_AODCaloJet_L1PFTrackAngle          [selbin][jetbin]!=NULL)   //h_AODCaloJet_L1PFTrackAngle                     [selbin][jetbin]->Delete(); 
  ///if(h_AODCaloJet_L1PFLogTrackAngle       [selbin][jetbin]!=NULL)   //h_AODCaloJet_L1PFLogTrackAngle                  [selbin][jetbin]->Delete(); 
  if(h_AODCaloJet_L1PFMedianLog10TrackAngle [selbin][jetbin]!=NULL)   h_AODCaloJet_L1PFMedianLog10TrackAngle          [selbin][jetbin]->Delete(); 
  ///if(h_AODCaloJet_L1PFTotalTrackAngle     [selbin][jetbin]!=NULL)   //h_AODCaloJet_L1PFTotalTrackAngle                [selbin][jetbin]->Delete(); 
  ///if(h_AODCaloJetAbsEta                   [selbin][jetbin]!=NULL)   //h_AODCaloJetAbsEta                         [selbin][jetbin]->Delete();
  ///if(h_AODCaloJetPtVarAbsEtaVar           [selbin][jetbin]!=NULL)   //h_AODCaloJetPtVarAbsEtaVar                 [selbin][jetbin]->Delete(); 
  
  return kTRUE;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
///                         For L1 Pre-firing test    END                                          ////
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////



//----------------------------initAODCaloJetExtraHistograms
Bool_t analyzer_histograms::initAODCaloJetExtraHistograms( TString uncbin )
{

 // loop through jets and selections to initialize histograms in parllel (series)
 for(unsigned int i=0; i<selbinnames.size(); ++i){
  hist_file_out[i]->cd();
  unsigned int j; if(jetMultOn) j=0; else j=jetmultnames.size()-1;
  for(j; j<jetmultnames.size(); ++j){
    //deleteAODCaloJetExtraHistograms(i,j);
    //TString hname_AODCaloJetAvfVx                         = "h_"+selbinnames[i]+"_"+jetmultnames[j]+"_AODCaloJetAvfVx"                          + uncbin ;                          
    //TString hname_AODCaloJetAvfVy                         = "h_"+selbinnames[i]+"_"+jetmultnames[j]+"_AODCaloJetAvfVy"                          + uncbin ;                          
    //TString hname_AODCaloJetAvfVz                         = "h_"+selbinnames[i]+"_"+jetmultnames[j]+"_AODCaloJetAvfVz"                          + uncbin ;                          
    TString hname_AODCaloJetAvfVertexTotalChiSquared      = "h_"+selbinnames[i]+"_"+jetmultnames[j]+"_AODCaloJetAvfVertexTotalChiSquared"       + uncbin ;       
    TString hname_AODCaloJetAvfVertexDegreesOfFreedom     = "h_"+selbinnames[i]+"_"+jetmultnames[j]+"_AODCaloJetAvfVertexDegreesOfFreedom"      + uncbin ;      
    TString hname_AODCaloJetAvfVertexChi2NDoF             = "h_"+selbinnames[i]+"_"+jetmultnames[j]+"_AODCaloJetAvfVertexChi2NDoF"              + uncbin ;              
    TString hname_AODCaloJetAvfVertexDistanceToBeam       = "h_"+selbinnames[i]+"_"+jetmultnames[j]+"_AODCaloJetAvfVertexDistanceToBeam"        + uncbin ;        
    TString hname_AODCaloJetAvfVertexTransverseError      = "h_"+selbinnames[i]+"_"+jetmultnames[j]+"_AODCaloJetAvfVertexTransverseError"       + uncbin ;       
    TString hname_AODCaloJetAvfVertexTransverseSig        = "h_"+selbinnames[i]+"_"+jetmultnames[j]+"_AODCaloJetAvfVertexTransverseSig"         + uncbin ;         
    TString hname_AODCaloJetAvfVertexDeltaEta             = "h_"+selbinnames[i]+"_"+jetmultnames[j]+"_AODCaloJetAvfVertexDeltaEta"              + uncbin ;              
    TString hname_AODCaloJetAvfVertexDeltaPhi             = "h_"+selbinnames[i]+"_"+jetmultnames[j]+"_AODCaloJetAvfVertexDeltaPhi"              + uncbin ;              
    TString hname_AODCaloJetAvfVertexRecoilPt             = "h_"+selbinnames[i]+"_"+jetmultnames[j]+"_AODCaloJetAvfVertexRecoilPt"              + uncbin ;              
    TString hname_AODCaloJetAvfVertexTrackMass            = "h_"+selbinnames[i]+"_"+jetmultnames[j]+"_AODCaloJetAvfVertexTrackMass"             + uncbin ;             
    TString hname_AODCaloJetAvfVertexTrackEnergy          = "h_"+selbinnames[i]+"_"+jetmultnames[j]+"_AODCaloJetAvfVertexTrackEnergy"           + uncbin ;           
    TString hname_AODCaloJetAvfBeamSpotDeltaPhi           = "h_"+selbinnames[i]+"_"+jetmultnames[j]+"_AODCaloJetAvfBeamSpotDeltaPhi"            + uncbin ;            
    TString hname_AODCaloJetAvfBeamSpotRecoilPt           = "h_"+selbinnames[i]+"_"+jetmultnames[j]+"_AODCaloJetAvfBeamSpotRecoilPt"            + uncbin ;            
    TString hname_AODCaloJetAvfBeamSpotMedianDeltaPhi     = "h_"+selbinnames[i]+"_"+jetmultnames[j]+"_AODCaloJetAvfBeamSpotMedianDeltaPhi"      + uncbin ;      
    TString hname_AODCaloJetAvfBeamSpotLog10MedianDeltaPhi= "h_"+selbinnames[i]+"_"+jetmultnames[j]+"_AODCaloJetAvfBeamSpotLog10MedianDeltaPhi" + uncbin ; 
    TString hname_AODCaloJetNCleanMatchedTracks           = "h_"+selbinnames[i]+"_"+jetmultnames[j]+"_AODCaloJetNCleanMatchedTracks"            + uncbin ;            
    TString hname_AODCaloJetSumHitsInFrontOfVert          = "h_"+selbinnames[i]+"_"+jetmultnames[j]+"_AODCaloJetSumHitsInFrontOfVert"           + uncbin ;           
    TString hname_AODCaloJetSumMissHitsAfterVert          = "h_"+selbinnames[i]+"_"+jetmultnames[j]+"_AODCaloJetSumMissHitsAfterVert"           + uncbin ;           
    TString hname_AODCaloJetHitsInFrontOfVertPerTrack     = "h_"+selbinnames[i]+"_"+jetmultnames[j]+"_AODCaloJetHitsInFrontOfVertPerTrack"      + uncbin ;      
    TString hname_AODCaloJetMissHitsAfterVertPerTrack     = "h_"+selbinnames[i]+"_"+jetmultnames[j]+"_AODCaloJetMissHitsAfterVertPerTrack"      + uncbin ;      
    TString hname_AODCaloJetAvfDistToPV                   = "h_"+selbinnames[i]+"_"+jetmultnames[j]+"_AODCaloJetAvfDistToPV"                    + uncbin ;                    
    TString hname_AODCaloJetAvfVertexDeltaZtoPV           = "h_"+selbinnames[i]+"_"+jetmultnames[j]+"_AODCaloJetAvfVertexDeltaZtoPV"            + uncbin ;            
    TString hname_AODCaloJetAvfVertexDeltaZtoPV2          = "h_"+selbinnames[i]+"_"+jetmultnames[j]+"_AODCaloJetAvfVertexDeltaZtoPV2"           + uncbin ;           

    //h_AODCaloJetAvfVx                          [i][j] = initSingleHistogramTH1F( hname_AODCaloJetAvfVx                          , "AODCaloJetAvfVx                         ", 30, -3, 3 ); 
    //h_AODCaloJetAvfVy                          [i][j] = initSingleHistogramTH1F( hname_AODCaloJetAvfVy                          , "AODCaloJetAvfVy                         ", 30, -3, 3 ); 
    //h_AODCaloJetAvfVz                          [i][j] = initSingleHistogramTH1F( hname_AODCaloJetAvfVz                          , "AODCaloJetAvfVz                         ", 30, -3, 3 ); 
    h_AODCaloJetAvfVertexTotalChiSquared       [i][j] = initSingleHistogramTH1F( hname_AODCaloJetAvfVertexTotalChiSquared       , "AODCaloJetAvfVertexTotalChiSquared      ", 30, -3, 3 ); 
    h_AODCaloJetAvfVertexDegreesOfFreedom      [i][j] = initSingleHistogramTH1F( hname_AODCaloJetAvfVertexDegreesOfFreedom      , "AODCaloJetAvfVertexDegreesOfFreedom     ", 30, -3, 3 ); 
    h_AODCaloJetAvfVertexChi2NDoF              [i][j] = initSingleHistogramTH1F( hname_AODCaloJetAvfVertexChi2NDoF              , "AODCaloJetAvfVertexChi2NDoF             ", 30, -3, 3 ); 
    h_AODCaloJetAvfVertexDistanceToBeam        [i][j] = initSingleHistogramTH1F( hname_AODCaloJetAvfVertexDistanceToBeam        , "AODCaloJetAvfVertexDistanceToBeam       ", 30, -3, 3 ); 
    h_AODCaloJetAvfVertexTransverseError       [i][j] = initSingleHistogramTH1F( hname_AODCaloJetAvfVertexTransverseError       , "AODCaloJetAvfVertexTransverseError      ", 30, -3, 3 ); 
    h_AODCaloJetAvfVertexTransverseSig         [i][j] = initSingleHistogramTH1F( hname_AODCaloJetAvfVertexTransverseSig         , "AODCaloJetAvfVertexTransverseSig        ", 30, -3, 3 ); 
    h_AODCaloJetAvfVertexDeltaEta              [i][j] = initSingleHistogramTH1F( hname_AODCaloJetAvfVertexDeltaEta              , "AODCaloJetAvfVertexDeltaEta             ", 30, -3, 3 ); 
    h_AODCaloJetAvfVertexDeltaPhi              [i][j] = initSingleHistogramTH1F( hname_AODCaloJetAvfVertexDeltaPhi              , "AODCaloJetAvfVertexDeltaPhi             ", 30, -3, 3 ); 
    h_AODCaloJetAvfVertexRecoilPt              [i][j] = initSingleHistogramTH1F( hname_AODCaloJetAvfVertexRecoilPt              , "AODCaloJetAvfVertexRecoilPt             ", 30, -3, 3 ); 
    h_AODCaloJetAvfVertexTrackMass             [i][j] = initSingleHistogramTH1F( hname_AODCaloJetAvfVertexTrackMass             , "AODCaloJetAvfVertexTrackMass            ", 30, -3, 3 ); 
    h_AODCaloJetAvfVertexTrackEnergy           [i][j] = initSingleHistogramTH1F( hname_AODCaloJetAvfVertexTrackEnergy           , "AODCaloJetAvfVertexTrackEnergy          ", 30, -3, 3 ); 
    h_AODCaloJetAvfBeamSpotDeltaPhi            [i][j] = initSingleHistogramTH1F( hname_AODCaloJetAvfBeamSpotDeltaPhi            , "AODCaloJetAvfBeamSpotDeltaPhi           ", 30, -3, 3 ); 
    h_AODCaloJetAvfBeamSpotRecoilPt            [i][j] = initSingleHistogramTH1F( hname_AODCaloJetAvfBeamSpotRecoilPt            , "AODCaloJetAvfBeamSpotRecoilPt           ", 30, -3, 3 ); 
    h_AODCaloJetAvfBeamSpotMedianDeltaPhi      [i][j] = initSingleHistogramTH1F( hname_AODCaloJetAvfBeamSpotMedianDeltaPhi      , "AODCaloJetAvfBeamSpotMedianDeltaPhi     ", 30, -3, 3 ); 
    h_AODCaloJetAvfBeamSpotLog10MedianDeltaPhi [i][j] = initSingleHistogramTH1F( hname_AODCaloJetAvfBeamSpotLog10MedianDeltaPhi , "AODCaloJetAvfBeamSpotLog10MedianDeltaPhi", 30, -3, 3 ); 
    h_AODCaloJetNCleanMatchedTracks            [i][j] = initSingleHistogramTH1F( hname_AODCaloJetNCleanMatchedTracks            , "AODCaloJetNCleanMatchedTracks           ", 20, 0, 20 ); 
    h_AODCaloJetSumHitsInFrontOfVert           [i][j] = initSingleHistogramTH1F( hname_AODCaloJetSumHitsInFrontOfVert           , "AODCaloJetSumHitsInFrontOfVert          ", 30, -3, 3 ); 
    h_AODCaloJetSumMissHitsAfterVert           [i][j] = initSingleHistogramTH1F( hname_AODCaloJetSumMissHitsAfterVert           , "AODCaloJetSumMissHitsAfterVert          ", 30, -3, 3 ); 
    h_AODCaloJetHitsInFrontOfVertPerTrack      [i][j] = initSingleHistogramTH1F( hname_AODCaloJetHitsInFrontOfVertPerTrack      , "AODCaloJetHitsInFrontOfVertPerTrack     ", 30, -3, 3 ); 
    h_AODCaloJetMissHitsAfterVertPerTrack      [i][j] = initSingleHistogramTH1F( hname_AODCaloJetMissHitsAfterVertPerTrack      , "AODCaloJetMissHitsAfterVertPerTrack     ", 30, -3, 3 ); 
    h_AODCaloJetAvfDistToPV                    [i][j] = initSingleHistogramTH1F( hname_AODCaloJetAvfDistToPV                    , "AODCaloJetAvfDistToPV                   ", 30, -3, 3 ); 
    h_AODCaloJetAvfVertexDeltaZtoPV            [i][j] = initSingleHistogramTH1F( hname_AODCaloJetAvfVertexDeltaZtoPV            , "AODCaloJetAvfVertexDeltaZtoPV           ", 30, -3, 3 ); 
    h_AODCaloJetAvfVertexDeltaZtoPV2           [i][j] = initSingleHistogramTH1F( hname_AODCaloJetAvfVertexDeltaZtoPV2           , "AODCaloJetAvfVertexDeltaZtoPV2          ", 30, -3, 3 ); 

   } //   for(unsigned int i=0; i<selbinnames.size(); ++i){
  } //  for(unsigned int j=0; j<jetmultnames.size(); ++j){
 return kTRUE;
} //initAODCaloJetHistograms

//----------------------------fillAODCaloJetExtraHistograms
Bool_t analyzer_histograms::fillAODCaloJetExtraHistograms(Float_t weight, int selbin, int jetbin)
{

  hist_file_out[selbin]->cd();

  if(jetmultnames.at(jetbin) == "AllJets"){
    for(unsigned int i =0; i<aodcalojet_list.size(); i++){
      int aodcalojetindex = aodcalojet_list[i];
      //h_AODCaloJetAvfVx                          [selbin][jetbin]->Fill( AODCaloJetAvfVx                          ->at( aodcalojetindex ), weight );  
      //h_AODCaloJetAvfVy                          [selbin][jetbin]->Fill( AODCaloJetAvfVy                          ->at( aodcalojetindex ), weight );  
      //h_AODCaloJetAvfVz                          [selbin][jetbin]->Fill( AODCaloJetAvfVz                          ->at( aodcalojetindex ), weight );  
      h_AODCaloJetAvfVertexTotalChiSquared       [selbin][jetbin]->Fill( AODCaloJetAvfVertexTotalChiSquared       ->at( aodcalojetindex ), weight );  
      h_AODCaloJetAvfVertexDegreesOfFreedom      [selbin][jetbin]->Fill( AODCaloJetAvfVertexDegreesOfFreedom      ->at( aodcalojetindex ), weight );  
      h_AODCaloJetAvfVertexChi2NDoF              [selbin][jetbin]->Fill( AODCaloJetAvfVertexChi2NDoF              ->at( aodcalojetindex ), weight );  
      h_AODCaloJetAvfVertexDistanceToBeam        [selbin][jetbin]->Fill( AODCaloJetAvfVertexDistanceToBeam        ->at( aodcalojetindex ), weight );  
      h_AODCaloJetAvfVertexTransverseError       [selbin][jetbin]->Fill( AODCaloJetAvfVertexTransverseError       ->at( aodcalojetindex ), weight );  
      h_AODCaloJetAvfVertexTransverseSig         [selbin][jetbin]->Fill( AODCaloJetAvfVertexTransverseSig         ->at( aodcalojetindex ), weight );  
      h_AODCaloJetAvfVertexDeltaEta              [selbin][jetbin]->Fill( AODCaloJetAvfVertexDeltaEta              ->at( aodcalojetindex ), weight );  
      h_AODCaloJetAvfVertexDeltaPhi              [selbin][jetbin]->Fill( AODCaloJetAvfVertexDeltaPhi              ->at( aodcalojetindex ), weight );  
      h_AODCaloJetAvfVertexRecoilPt              [selbin][jetbin]->Fill( AODCaloJetAvfVertexRecoilPt              ->at( aodcalojetindex ), weight );  
      h_AODCaloJetAvfVertexTrackMass             [selbin][jetbin]->Fill( AODCaloJetAvfVertexTrackMass             ->at( aodcalojetindex ), weight );  
      h_AODCaloJetAvfVertexTrackEnergy           [selbin][jetbin]->Fill( AODCaloJetAvfVertexTrackEnergy           ->at( aodcalojetindex ), weight );  
      h_AODCaloJetAvfBeamSpotDeltaPhi            [selbin][jetbin]->Fill( AODCaloJetAvfBeamSpotDeltaPhi            ->at( aodcalojetindex ), weight );  
      h_AODCaloJetAvfBeamSpotRecoilPt            [selbin][jetbin]->Fill( AODCaloJetAvfBeamSpotRecoilPt            ->at( aodcalojetindex ), weight );  
      h_AODCaloJetAvfBeamSpotMedianDeltaPhi      [selbin][jetbin]->Fill( AODCaloJetAvfBeamSpotMedianDeltaPhi      ->at( aodcalojetindex ), weight );  
      h_AODCaloJetAvfBeamSpotLog10MedianDeltaPhi [selbin][jetbin]->Fill( AODCaloJetAvfBeamSpotLog10MedianDeltaPhi ->at( aodcalojetindex ), weight );  
      h_AODCaloJetNCleanMatchedTracks            [selbin][jetbin]->Fill( AODCaloJetNCleanMatchedTracks            ->at( aodcalojetindex ), weight );  
//      h_AODCaloJetSumHitsInFrontOfVert           [selbin][jetbin]->Fill( AODCaloJetSumHitsInFrontOfVert           ->at( aodcalojetindex ), weight );  
//      h_AODCaloJetSumMissHitsAfterVert           [selbin][jetbin]->Fill( AODCaloJetSumMissHitsAfterVert           ->at( aodcalojetindex ), weight );  
//      h_AODCaloJetHitsInFrontOfVertPerTrack      [selbin][jetbin]->Fill( AODCaloJetHitsInFrontOfVertPerTrack      ->at( aodcalojetindex ), weight );  
//      h_AODCaloJetMissHitsAfterVertPerTrack      [selbin][jetbin]->Fill( AODCaloJetMissHitsAfterVertPerTrack      ->at( aodcalojetindex ), weight );  
      h_AODCaloJetAvfDistToPV                    [selbin][jetbin]->Fill( AODCaloJetAvfDistToPV                    ->at( aodcalojetindex ), weight );  
      h_AODCaloJetAvfVertexDeltaZtoPV            [selbin][jetbin]->Fill( AODCaloJetAvfVertexDeltaZtoPV            ->at( aodcalojetindex ), weight );  
      h_AODCaloJetAvfVertexDeltaZtoPV2           [selbin][jetbin]->Fill( AODCaloJetAvfVertexDeltaZtoPV2           ->at( aodcalojetindex ), weight );  
    }
  }
  else{
    if( jetbin < (int)aodcalojet_list.size() ){
      int aodcalojetindex = aodcalojet_list[jetbin];
      //h_AODCaloJetAvfVx                          [selbin][jetbin]->Fill( AODCaloJetAvfVx                          ->at( aodcalojetindex ), weight );  
      //h_AODCaloJetAvfVy                          [selbin][jetbin]->Fill( AODCaloJetAvfVy                          ->at( aodcalojetindex ), weight );  
      //h_AODCaloJetAvfVz                          [selbin][jetbin]->Fill( AODCaloJetAvfVz                          ->at( aodcalojetindex ), weight );  
      h_AODCaloJetAvfVertexTotalChiSquared       [selbin][jetbin]->Fill( AODCaloJetAvfVertexTotalChiSquared       ->at( aodcalojetindex ), weight );  
      h_AODCaloJetAvfVertexDegreesOfFreedom      [selbin][jetbin]->Fill( AODCaloJetAvfVertexDegreesOfFreedom      ->at( aodcalojetindex ), weight );  
      h_AODCaloJetAvfVertexChi2NDoF              [selbin][jetbin]->Fill( AODCaloJetAvfVertexChi2NDoF              ->at( aodcalojetindex ), weight );  
      h_AODCaloJetAvfVertexDistanceToBeam        [selbin][jetbin]->Fill( AODCaloJetAvfVertexDistanceToBeam        ->at( aodcalojetindex ), weight );  
      h_AODCaloJetAvfVertexTransverseError       [selbin][jetbin]->Fill( AODCaloJetAvfVertexTransverseError       ->at( aodcalojetindex ), weight );  
      h_AODCaloJetAvfVertexTransverseSig         [selbin][jetbin]->Fill( AODCaloJetAvfVertexTransverseSig         ->at( aodcalojetindex ), weight );  
      h_AODCaloJetAvfVertexDeltaEta              [selbin][jetbin]->Fill( AODCaloJetAvfVertexDeltaEta              ->at( aodcalojetindex ), weight );  
      h_AODCaloJetAvfVertexDeltaPhi              [selbin][jetbin]->Fill( AODCaloJetAvfVertexDeltaPhi              ->at( aodcalojetindex ), weight );  
      h_AODCaloJetAvfVertexRecoilPt              [selbin][jetbin]->Fill( AODCaloJetAvfVertexRecoilPt              ->at( aodcalojetindex ), weight );  
      h_AODCaloJetAvfVertexTrackMass             [selbin][jetbin]->Fill( AODCaloJetAvfVertexTrackMass             ->at( aodcalojetindex ), weight );  
      h_AODCaloJetAvfVertexTrackEnergy           [selbin][jetbin]->Fill( AODCaloJetAvfVertexTrackEnergy           ->at( aodcalojetindex ), weight );  
      h_AODCaloJetAvfBeamSpotDeltaPhi            [selbin][jetbin]->Fill( AODCaloJetAvfBeamSpotDeltaPhi            ->at( aodcalojetindex ), weight );  
      h_AODCaloJetAvfBeamSpotRecoilPt            [selbin][jetbin]->Fill( AODCaloJetAvfBeamSpotRecoilPt            ->at( aodcalojetindex ), weight );  
      h_AODCaloJetAvfBeamSpotMedianDeltaPhi      [selbin][jetbin]->Fill( AODCaloJetAvfBeamSpotMedianDeltaPhi      ->at( aodcalojetindex ), weight );  
      h_AODCaloJetAvfBeamSpotLog10MedianDeltaPhi [selbin][jetbin]->Fill( AODCaloJetAvfBeamSpotLog10MedianDeltaPhi ->at( aodcalojetindex ), weight );  
      h_AODCaloJetNCleanMatchedTracks            [selbin][jetbin]->Fill( AODCaloJetNCleanMatchedTracks            ->at( aodcalojetindex ), weight );  
//      h_AODCaloJetSumHitsInFrontOfVert           [selbin][jetbin]->Fill( AODCaloJetSumHitsInFrontOfVert           ->at( aodcalojetindex ), weight );  
//      h_AODCaloJetSumMissHitsAfterVert           [selbin][jetbin]->Fill( AODCaloJetSumMissHitsAfterVert           ->at( aodcalojetindex ), weight );  
//      h_AODCaloJetHitsInFrontOfVertPerTrack      [selbin][jetbin]->Fill( AODCaloJetHitsInFrontOfVertPerTrack      ->at( aodcalojetindex ), weight );  
//      h_AODCaloJetMissHitsAfterVertPerTrack      [selbin][jetbin]->Fill( AODCaloJetMissHitsAfterVertPerTrack      ->at( aodcalojetindex ), weight );  
      h_AODCaloJetAvfDistToPV                    [selbin][jetbin]->Fill( AODCaloJetAvfDistToPV                    ->at( aodcalojetindex ), weight );  
      h_AODCaloJetAvfVertexDeltaZtoPV            [selbin][jetbin]->Fill( AODCaloJetAvfVertexDeltaZtoPV            ->at( aodcalojetindex ), weight );  
      h_AODCaloJetAvfVertexDeltaZtoPV2           [selbin][jetbin]->Fill( AODCaloJetAvfVertexDeltaZtoPV2           ->at( aodcalojetindex ), weight );  
    }
  }

 return kTRUE;
} //end fill histograms


//----------------------------writeAODCaloJetExtraHistograms
Bool_t analyzer_histograms::writeAODCaloJetExtraHistograms(int selbin, int jetbin)
{
 //printf("writeAODCaloJetHistograms\n");
  hist_file_out[selbin]->cd();
  //h_AODCaloJetAvfVx                          [selbin][jetbin]->Write(); 
  //h_AODCaloJetAvfVy                          [selbin][jetbin]->Write(); 
  //h_AODCaloJetAvfVz                          [selbin][jetbin]->Write(); 
  h_AODCaloJetAvfVertexTotalChiSquared       [selbin][jetbin]->Write(); 
  h_AODCaloJetAvfVertexDegreesOfFreedom      [selbin][jetbin]->Write(); 
  h_AODCaloJetAvfVertexChi2NDoF              [selbin][jetbin]->Write(); 
  h_AODCaloJetAvfVertexDistanceToBeam        [selbin][jetbin]->Write(); 
  h_AODCaloJetAvfVertexTransverseError       [selbin][jetbin]->Write(); 
  h_AODCaloJetAvfVertexTransverseSig         [selbin][jetbin]->Write(); 
  h_AODCaloJetAvfVertexDeltaEta              [selbin][jetbin]->Write(); 
  h_AODCaloJetAvfVertexDeltaPhi              [selbin][jetbin]->Write(); 
  h_AODCaloJetAvfVertexRecoilPt              [selbin][jetbin]->Write(); 
  h_AODCaloJetAvfVertexTrackMass             [selbin][jetbin]->Write(); 
  h_AODCaloJetAvfVertexTrackEnergy           [selbin][jetbin]->Write(); 
  h_AODCaloJetAvfBeamSpotDeltaPhi            [selbin][jetbin]->Write(); 
  h_AODCaloJetAvfBeamSpotRecoilPt            [selbin][jetbin]->Write(); 
  h_AODCaloJetAvfBeamSpotMedianDeltaPhi      [selbin][jetbin]->Write(); 
  h_AODCaloJetAvfBeamSpotLog10MedianDeltaPhi [selbin][jetbin]->Write(); 
  h_AODCaloJetNCleanMatchedTracks            [selbin][jetbin]->Write(); 
  h_AODCaloJetSumHitsInFrontOfVert           [selbin][jetbin]->Write(); 
  h_AODCaloJetSumMissHitsAfterVert           [selbin][jetbin]->Write(); 
  h_AODCaloJetHitsInFrontOfVertPerTrack      [selbin][jetbin]->Write(); 
  h_AODCaloJetMissHitsAfterVertPerTrack      [selbin][jetbin]->Write(); 
  h_AODCaloJetAvfDistToPV                    [selbin][jetbin]->Write(); 
  h_AODCaloJetAvfVertexDeltaZtoPV            [selbin][jetbin]->Write(); 
  return kTRUE;
}


//----------------------------deleteAODCaloJetExtraHistograms
Bool_t analyzer_histograms::deleteAODCaloJetExtraHistograms(int selbin, int jetbin)
{
  std::cout << "selbin " << selbin << " jetbin " << jetbin << std::endl;
  //printf("deleteAODCaloJetExtraHistograms\n");
  hist_file_out[selbin]->cd();
  //if(h_AODCaloJetAvfVx                         [selbin][jetbin]!=NULL)    h_AODCaloJetAvfVx                          [selbin][jetbin]->Delete(); 
  //if(h_AODCaloJetAvfVy                         [selbin][jetbin]!=NULL)    h_AODCaloJetAvfVy                          [selbin][jetbin]->Delete(); 
  //if(h_AODCaloJetAvfVz                         [selbin][jetbin]!=NULL)    h_AODCaloJetAvfVz                          [selbin][jetbin]->Delete(); 
  if(h_AODCaloJetAvfVertexTotalChiSquared      [selbin][jetbin]!=NULL)    h_AODCaloJetAvfVertexTotalChiSquared       [selbin][jetbin]->Delete(); 
  if(h_AODCaloJetAvfVertexDegreesOfFreedom     [selbin][jetbin]!=NULL)    h_AODCaloJetAvfVertexDegreesOfFreedom      [selbin][jetbin]->Delete(); 
  if(h_AODCaloJetAvfVertexChi2NDoF             [selbin][jetbin]!=NULL)    h_AODCaloJetAvfVertexChi2NDoF              [selbin][jetbin]->Delete(); 
  if(h_AODCaloJetAvfVertexDistanceToBeam       [selbin][jetbin]!=NULL)    h_AODCaloJetAvfVertexDistanceToBeam        [selbin][jetbin]->Delete(); 
  if(h_AODCaloJetAvfVertexTransverseError      [selbin][jetbin]!=NULL)    h_AODCaloJetAvfVertexTransverseError       [selbin][jetbin]->Delete(); 
  if(h_AODCaloJetAvfVertexTransverseSig        [selbin][jetbin]!=NULL)    h_AODCaloJetAvfVertexTransverseSig         [selbin][jetbin]->Delete(); 
  if(h_AODCaloJetAvfVertexDeltaEta             [selbin][jetbin]!=NULL)    h_AODCaloJetAvfVertexDeltaEta              [selbin][jetbin]->Delete(); 
  if(h_AODCaloJetAvfVertexDeltaPhi             [selbin][jetbin]!=NULL)    h_AODCaloJetAvfVertexDeltaPhi              [selbin][jetbin]->Delete(); 
  if(h_AODCaloJetAvfVertexRecoilPt             [selbin][jetbin]!=NULL)    h_AODCaloJetAvfVertexRecoilPt              [selbin][jetbin]->Delete(); 
  if(h_AODCaloJetAvfVertexTrackMass            [selbin][jetbin]!=NULL)    h_AODCaloJetAvfVertexTrackMass             [selbin][jetbin]->Delete(); 
  if(h_AODCaloJetAvfVertexTrackEnergy          [selbin][jetbin]!=NULL)    h_AODCaloJetAvfVertexTrackEnergy           [selbin][jetbin]->Delete(); 
  if(h_AODCaloJetAvfBeamSpotDeltaPhi           [selbin][jetbin]!=NULL)    h_AODCaloJetAvfBeamSpotDeltaPhi            [selbin][jetbin]->Delete(); 
  if(h_AODCaloJetAvfBeamSpotRecoilPt           [selbin][jetbin]!=NULL)    h_AODCaloJetAvfBeamSpotRecoilPt            [selbin][jetbin]->Delete(); 
  if(h_AODCaloJetAvfBeamSpotMedianDeltaPhi     [selbin][jetbin]!=NULL)    h_AODCaloJetAvfBeamSpotMedianDeltaPhi      [selbin][jetbin]->Delete(); 
  if(h_AODCaloJetAvfBeamSpotLog10MedianDeltaPhi[selbin][jetbin]!=NULL)    h_AODCaloJetAvfBeamSpotLog10MedianDeltaPhi [selbin][jetbin]->Delete(); 
  if(h_AODCaloJetNCleanMatchedTracks           [selbin][jetbin]!=NULL)    h_AODCaloJetNCleanMatchedTracks            [selbin][jetbin]->Delete(); 
  if(h_AODCaloJetSumHitsInFrontOfVert          [selbin][jetbin]!=NULL)    h_AODCaloJetSumHitsInFrontOfVert           [selbin][jetbin]->Delete(); 
  if(h_AODCaloJetSumMissHitsAfterVert          [selbin][jetbin]!=NULL)    h_AODCaloJetSumMissHitsAfterVert           [selbin][jetbin]->Delete(); 
  if(h_AODCaloJetHitsInFrontOfVertPerTrack     [selbin][jetbin]!=NULL)    h_AODCaloJetHitsInFrontOfVertPerTrack      [selbin][jetbin]->Delete(); 
  if(h_AODCaloJetMissHitsAfterVertPerTrack     [selbin][jetbin]!=NULL)    h_AODCaloJetMissHitsAfterVertPerTrack      [selbin][jetbin]->Delete(); 
  if(h_AODCaloJetAvfDistToPV                   [selbin][jetbin]!=NULL)    h_AODCaloJetAvfDistToPV                    [selbin][jetbin]->Delete(); 
  if(h_AODCaloJetAvfVertexDeltaZtoPV           [selbin][jetbin]!=NULL)    h_AODCaloJetAvfVertexDeltaZtoPV            [selbin][jetbin]->Delete(); 
  return kTRUE;
}



//----------------------------initAODCaloJetTagHistograms
Bool_t analyzer_histograms::initAODCaloJetTagHistograms( TString uncbin )
{

 // loop through jets and selections to initialize histograms in parallel (series)
 for(unsigned int i=0; i<selbinnames.size(); ++i){
   hist_file_out[i]->cd();

  for(unsigned int j=0; j<tagmultnames.size(); ++j){
   //deleteAODCaloJetTagHistograms(i,j);
   TString hname_AODCaloJetPt_Tag0                      = "h_"+selbinnames[i]+"_"+tagmultnames[j]+"_AODCaloJetPt_Tag0"                  + uncbin ;
   TString hname_AODCaloJetPtVar_Tag0                   = "h_"+selbinnames[i]+"_"+tagmultnames[j]+"_AODCaloJetPtVar_Tag0"               + uncbin ;
   TString hname_AODCaloJetMinDR_Tag0                   = "h_"+selbinnames[i]+"_"+tagmultnames[j]+"_AODCaloJetMinDR_Tag0"               + uncbin ;
//   TString hname_AODCaloJetCSV_Tag0                     = "h_"+selbinnames[i]+"_"+tagmultnames[j]+"_AODCaloJetCSV_Tag0"                 + uncbin ;
//   TString hname_AODCaloJetPartonFlavour_Tag0           = "h_"+selbinnames[i]+"_"+tagmultnames[j]+"_AODCaloJetPartonFlavour_Tag0"       + uncbin ;
   TString hname_AODCaloJetAbsEta_Tag0                  = "h_"+selbinnames[i]+"_"+tagmultnames[j]+"_AODCaloJetAbsEta_Tag0"              + uncbin ;
   TString hname_AODCaloJetNCleanMatchedTracks_Tag0     = "h_"+selbinnames[i]+"_"+tagmultnames[j]+"_AODCaloJetNCleanMatchedTracks_Tag0" + uncbin ;
   TString hname_AODCaloJetPtVarAbsEtaVar_Tag0          = "h_"+selbinnames[i]+"_"+tagmultnames[j]+"_AODCaloJetPtVarAbsEtaVar_Tag0"      + uncbin ;

   h_AODCaloJetPt_Tag0                       [i][j] = initSingleHistogramTH1F( hname_AODCaloJetPt_Tag0                       , "AODCaloJetPt_Tag0                      ", 50, 0, 500); 
   h_AODCaloJetMinDR_Tag0                    [i][j] = initSingleHistogramTH1F( hname_AODCaloJetMinDR_Tag0                    , "AODCaloJetMinDR_Tag0                   ", 30, 0, 5); 
//   h_AODCaloJetCSV_Tag0                      [i][j] = initSingleHistogramTH1F( hname_AODCaloJetCSV_Tag0                      , "AODCaloJetCSV_Tag0                     ", 24, -.1, 1.1); 
//   h_AODCaloJetPartonFlavour_Tag0            [i][j] = initSingleHistogramTH1F( hname_AODCaloJetPartonFlavour_Tag0            , "AODCaloJetPartonFlavour_Tag0           ", 35, -10, 25); 
   h_AODCaloJetAbsEta_Tag0                   [i][j] = initSingleHistogramTH1F( hname_AODCaloJetAbsEta_Tag0                   , "AODCaloJetAbsEta_Tag0                  ", 4, 0, 3);
   h_AODCaloJetNCleanMatchedTracks_Tag0      [i][j] = initSingleHistogramTH1F( hname_AODCaloJetNCleanMatchedTracks_Tag0      , "AODCaloJetNCleanMatchedTracks_Tag0     ", 20, 0, 20); 

   const int Pt_n_xbins = 10;
   float Pt_xbins[Pt_n_xbins+1] = {0, 10, 20, 30, 40, 50, 75, 100, 150, 250, 500};
   h_AODCaloJetPtVar_Tag0                    [i][j] = initSingleHistogramTH1F( hname_AODCaloJetPtVar_Tag0 , "AODCaloJetPtVar_Tag0", Pt_n_xbins, Pt_xbins);

   const int AbsEta_n_bins = 2;
   float AbsEta_bins[AbsEta_n_bins+1] = {0, 1.5, 2.4};
   h_AODCaloJetPtVarAbsEtaVar_Tag0           [i][j] = initSingleHistogramTH2F(hname_AODCaloJetPtVarAbsEtaVar_Tag0, "AODCaloJetPtVarAbsEtaVar_Tag0", Pt_n_xbins, Pt_xbins, AbsEta_n_bins, AbsEta_bins );

  } //   for(unsigned int i=0; i<selbinnames.size(); ++i){
 } //  for(unsigned int j=0; j<tagmultnames.size(); ++j){
 return kTRUE;
} //initAODCaloJetTagHistograms



//----------------------------fillAODCaloJetTagHistograms
Bool_t analyzer_histograms::fillAODCaloJetTagHistograms(Float_t weight, int selbin, int tagbin)
{
  hist_file_out[selbin]->cd();

  if(tagmultnames.at(tagbin) == "AllTags"){
    for(unsigned int i =0; i<taggedjet_list.size(); i++){
      int tagindex = taggedjet_list[i];
      h_AODCaloJetPt_Tag0                            [selbin][tagbin]->Fill( AODCaloJetPt->at(                        tagindex ), weight );  
      h_AODCaloJetPtVar_Tag0                         [selbin][tagbin]->Fill( AODCaloJetPt->at(                        tagindex ), weight );  
      h_AODCaloJetMinDR_Tag0                         [selbin][tagbin]->Fill( aodcalojet_minDR_list.at(                tagindex ), weight );  
//      h_AODCaloJetCSV_Tag0                           [selbin][tagbin]->Fill( aodcalojet_matchedCSV_list.at(           tagindex ), weight );  
//      h_AODCaloJetPartonFlavour_Tag0                 [selbin][tagbin]->Fill( aodcalojet_matchedPartonFlavour_list.at( tagindex ), weight );  
      h_AODCaloJetAbsEta_Tag0                        [selbin][tagbin]->Fill( fabs(AODCaloJetEta->at(                  tagindex )), weight );
      h_AODCaloJetNCleanMatchedTracks_Tag0           [selbin][tagbin]->Fill( AODCaloJetNCleanMatchedTracks->at(       tagindex ), weight );  
      h_AODCaloJetPtVarAbsEtaVar_Tag0                [selbin][tagbin]->Fill( AODCaloJetPt->at(tagindex), fabs(AODCaloJetEta->at( tagindex )), weight );  
    }
  }
  else {
    if( tagbin < (int)taggedjet_list.size() ){
      int tagindex = taggedjet_list[tagbin];
      h_AODCaloJetPt_Tag0                            [selbin][tagbin]->Fill( AODCaloJetPt->at(                        tagindex ), weight );  
      h_AODCaloJetPtVar_Tag0                         [selbin][tagbin]->Fill( AODCaloJetPt->at(                        tagindex ), weight );  
      h_AODCaloJetMinDR_Tag0                         [selbin][tagbin]->Fill( aodcalojet_minDR_list.at(                tagindex ), weight );  
//      h_AODCaloJetCSV_Tag0                           [selbin][tagbin]->Fill( aodcalojet_matchedCSV_list.at(           tagindex ), weight );  
//      h_AODCaloJetPartonFlavour_Tag0                 [selbin][tagbin]->Fill( aodcalojet_matchedPartonFlavour_list.at( tagindex ), weight );  
      h_AODCaloJetAbsEta_Tag0                        [selbin][tagbin]->Fill( fabs( AODCaloJetEta->at(                 tagindex ) ), weight );
      h_AODCaloJetNCleanMatchedTracks_Tag0           [selbin][tagbin]->Fill( AODCaloJetNCleanMatchedTracks->at(       tagindex ), weight );  
      h_AODCaloJetPtVarAbsEtaVar_Tag0                [selbin][tagbin]->Fill( AODCaloJetPt->at(tagindex), fabs(AODCaloJetEta->at( tagindex )), weight );  
    }
  }
  
  return kTRUE;
} //end fill histograms


//----------------------------writeAODCaloJetTagHistograms
Bool_t analyzer_histograms::writeAODCaloJetTagHistograms(int selbin, int tagbin)
{
  hist_file_out[selbin]->cd();

  //printf("writeAODCaloJetTagHistograms\n");
  h_AODCaloJetPt_Tag0                       [selbin][tagbin]->Write(); 
  h_AODCaloJetPtVar_Tag0                    [selbin][tagbin]->Write(); 
  h_AODCaloJetMinDR_Tag0                    [selbin][tagbin]->Write(); 
//  h_AODCaloJetCSV_Tag0                      [selbin][tagbin]->Write(); 
//  h_AODCaloJetPartonFlavour_Tag0            [selbin][tagbin]->Write(); 
  h_AODCaloJetAbsEta_Tag0                   [selbin][tagbin]->Write(); 
  h_AODCaloJetNCleanMatchedTracks_Tag0      [selbin][tagbin]->Write(); 
  h_AODCaloJetPtVarAbsEtaVar_Tag0           [selbin][tagbin]->Write(); 

 return kTRUE;
}


//----------------------------deleteAODCaloJetTagHistograms
Bool_t analyzer_histograms::deleteAODCaloJetTagHistograms(int selbin, int tagbin)
{
  std::cout << "selbin " << selbin << " tagbin " << tagbin << std::endl;
  hist_file_out[selbin]->cd();
  //printf("deleteAODCaloJetTagHistograms\n");
  if(h_AODCaloJetPt_Tag0                  [selbin][tagbin]!=NULL)    h_AODCaloJetPt_Tag0                       [selbin][tagbin]->Delete(); 
  if(h_AODCaloJetPtVar_Tag0               [selbin][tagbin]!=NULL)    h_AODCaloJetPtVar_Tag0                    [selbin][tagbin]->Delete(); 
  if(h_AODCaloJetMinDR_Tag0               [selbin][tagbin]!=NULL)    h_AODCaloJetMinDR_Tag0                    [selbin][tagbin]->Delete(); 
//  if(h_AODCaloJetCSV_Tag0                 [selbin][tagbin]!=NULL)    h_AODCaloJetCSV_Tag0                      [selbin][tagbin]->Delete(); 
//  if(h_AODCaloJetPartonFlavour_Tag0       [selbin][tagbin]!=NULL)    h_AODCaloJetPartonFlavour_Tag0            [selbin][tagbin]->Delete(); 
  if(h_AODCaloJetAbsEta_Tag0              [selbin][tagbin]!=NULL)    h_AODCaloJetAbsEta_Tag0                   [selbin][tagbin]->Delete(); 
  if(h_AODCaloJetNCleanMatchedTracks_Tag0 [selbin][tagbin]!=NULL)    h_AODCaloJetNCleanMatchedTracks_Tag0      [selbin][tagbin]->Delete(); 
  if(h_AODCaloJetPtVarAbsEtaVar_Tag0      [selbin][tagbin]!=NULL)    h_AODCaloJetPtVarAbsEtaVar_Tag0           [selbin][tagbin]->Delete(); 
  return kTRUE;
}


// Cutflow section

//----------------------------initCutflowHistograms
Bool_t analyzer_histograms::initCutflowHistograms( TString uncbin ){

 for(unsigned int i=0; i<selbinnames.size(); ++i){

  //deleteCutflowHistograms(i);
  TString hname_Cutflow    = "h_"+selbinnames[i]+"_Cutflow"   +uncbin; 
  TString hname_Onecut     = "h_"+selbinnames[i]+"_Onecut"    +uncbin; 
  TString hname_NMinus     = "h_"+selbinnames[i]+"_NMinus"    +uncbin; 
  TString hname_RawCutflow = "h_"+selbinnames[i]+"_RawCutflow"+uncbin; 
  TString hname_RawOnecut  = "h_"+selbinnames[i]+"_RawOnecut" +uncbin; 
  TString hname_RawNMinus  = "h_"+selbinnames[i]+"_RawNMinus" +uncbin; 

  h_Cutflow    [i] = initSingleHistogramTH1F( hname_Cutflow , "Cutflow", 10,0,10);
  h_Onecut     [i] = initSingleHistogramTH1F( hname_Onecut  , "Onecut ", 10,0,10);
  h_NMinus     [i] = initSingleHistogramTH1F( hname_NMinus  , "NMinus ", 10,0,10); 
  h_RawCutflow [i] = initSingleHistogramTH1F( hname_RawCutflow , "RawCutflow", 10,0,10);
  h_RawOnecut  [i] = initSingleHistogramTH1F( hname_RawOnecut  , "RawOnecut ", 10,0,10);
  h_RawNMinus  [i] = initSingleHistogramTH1F( hname_RawNMinus  , "RawNMinus ", 10,0,10); 
 }
 return kTRUE;
}

//----------------------------fillCutflowHistograms
Bool_t analyzer_histograms::fillCutflowHistograms(Float_t weight, int selbin, Int_t localselint, Int_t localselkey)
{

 h_Cutflow[selbin] ->Fill( 1, weight );
 h_Onecut[selbin]  ->Fill( 1, weight );
 h_NMinus[selbin]  ->Fill( 1, weight );
 h_RawCutflow[selbin] ->Fill( 1 );
 h_RawOnecut[selbin]  ->Fill( 1 );
 h_RawNMinus[selbin]  ->Fill( 1 );

 Bool_t notdead = kTRUE;
 Int_t nmbits = 0;

 // for now all selections are less than 8 long
 // selection integers (bitset) start with 1/0 if pass all cuts
 // then 1/0 for each individual cut
 for( unsigned int i=1; i<8; ++i){
  // ignore the first bit, then keep checking if we ever get 0
  notdead = notdead && ( localselint>>(i) & 1 ) ;

  // bit i and all preceding bits it pass
  if( notdead ){
   h_Cutflow[selbin]    ->Fill( 1+i, weight );
   h_RawCutflow[selbin] ->Fill( 1+i );
  }
  // just bit i passes
  if( localselint>>(i) & 1 ){
   h_Onecut[selbin]    ->Fill( 1+i, weight );
   h_RawOnecut[selbin] ->Fill( 1+i );
  }
  // everything other than bit i passes
   // bit structure is (passAll)(sel1)(sel2)(sel3)(sel4)(sel5)000
   // nmbits is 011111000 ( localselkey ) except flip bit i to 0
   // then AND this with selection bitset to get comparison bitset
   // then if comp bitset == nmbits we know
   // selection bitset passed all cuts, ignoring cut i
  nmbits = localselkey;
  nmbits &= ~(1 << i);
  Int_t compbits = localselint & nmbits;

  //std::cout<<"\n";
  //std::cout<<" nmbits: "<<nmbits<<" =    "; 
  //for(unsigned int i=0; i<8; ++i){
  // std::cout<< ( (nmbits>>i)&1 );
  //}
  //std::cout<<"\n";
  //std::cout<<" localselint: "<<localselint<<" =    "; 
  //for(unsigned int i=0; i<8; ++i){
  // std::cout<< ( (localselint>>i)&1 );
  //}
  //std::cout<<"\n";
  //std::cout<<" cmpbit: "<<compbits<<" =    "; 
  //for(unsigned int i=0; i<8; ++i){
  // std::cout<< ( (compbits>>i)&1 );
  //}
  //std::cout<<"\n";

  if( nmbits==compbits ){
   h_NMinus[selbin]    ->Fill( 1+i, weight );
   h_RawNMinus[selbin] ->Fill( 1+i );
  }

 }

 return kTRUE;
}

//----------------------------writeCutflowHistograms
Bool_t analyzer_histograms::writeCutflowHistograms(int selbin)
{
 h_Cutflow    [selbin]->Write();
 h_Onecut     [selbin]->Write();
 h_RawCutflow [selbin]->Write();
 h_RawOnecut  [selbin]->Write();
 h_NMinus     [selbin]->Write();
 h_RawNMinus  [selbin]->Write();
 return kTRUE;
}

//----------------------------deleteCutflowHistograms
Bool_t analyzer_histograms::deleteCutflowHistograms(int selbin)
{
  //printf("deleteCutflowHistograms\n");
  if(h_Cutflow   [selbin]!=NULL)  h_Cutflow    [selbin]->Delete();
  if(h_Onecut    [selbin]!=NULL)  h_Onecut     [selbin]->Delete();
  if(h_RawCutflow[selbin]!=NULL)  h_RawCutflow [selbin]->Delete();
  if(h_RawOnecut [selbin]!=NULL)  h_RawOnecut  [selbin]->Delete();
  if(h_NMinus    [selbin]!=NULL)  h_NMinus     [selbin]->Delete();
  if(h_RawNMinus [selbin]!=NULL)  h_RawNMinus  [selbin]->Delete();
  return kTRUE;
}

//----------------------------initExtraHistograms
Bool_t analyzer_histograms::initExtraHistograms( TString uncbin ){

  //for(unsigned int i=0; i<selbinnames.size(); ++i){
  //deleteExtraHistograms(i);
  //}
 return kTRUE;
}

//----------------------------fillExtraHistograms
Bool_t analyzer_histograms::fillExtraHistograms(Float_t weight, int selbin)
{ 
  return kTRUE;
}

//----------------------------writeExtraHistograms
Bool_t analyzer_histograms::writeExtraHistograms(int selbin)
{
 return kTRUE;
}


//----------------------------deleteExtraHistograms
Bool_t analyzer_histograms::deleteExtraHistograms(int selbin)
{
 return kTRUE;
}

//---------------------------scaleVariableBinHistograms
Bool_t analyzer_histograms::scaleVariableBinHistograms(int selbin)
{

  hist_file_out[selbin]->cd();

  unsigned int j; if(jetMultOn) j=0; else j=jetmultnames.size()-1;
  for(j; j<jetmultnames.size(); ++j){
    h_AODCaloJetPtVar                      [selbin][j]->Scale(1, "width");
  }
  for(unsigned int j=0; j<tagmultnames.size(); ++j){
    h_AODCaloJetPtVar_Tag0                 [selbin][j]->Scale(1, "width");
  }
  
  return kTRUE;
}


//----------------------------initAODCaloJetMultHistograms
Bool_t analyzer_histograms::initAODCaloJetMultHistograms( TString uncbin )
{
  for(unsigned int i=0; i<selbinnames.size(); ++i){
    hist_file_out[i]->cd();

    //deleteAODCaloJetMultHistograms(i);
    TString hname_nSelectedAODCaloJet          = "h_"+selbinnames[i]+"_nSelectedAODCaloJet"+uncbin;
    h_nSelectedAODCaloJet                  [i] = initSingleHistogramTH1F( hname_nSelectedAODCaloJet         , "nSelectedAODCaloJet"      , 10, -0.5, 9.5);
  }//sel                                                                                                                                                                                
}

//----------------------------fillAODCaloJetMultHistograms
Bool_t analyzer_histograms::fillAODCaloJetMultHistograms(Float_t weight, int selbin)
{
  hist_file_out[selbin]->cd();

  h_nSelectedAODCaloJet    [selbin] ->Fill( float(aodcalojet_list.size()), weight );
}

//----------------------------writeAODCaloJetMultHistograms
Bool_t analyzer_histograms::writeAODCaloJetMultHistograms(int selbin)
{
  hist_file_out[selbin]->cd();
  h_nSelectedAODCaloJet    [selbin] ->Write();
}

//----------------------------deleteAODCaloJetMultHistograms
Bool_t analyzer_histograms::deleteAODCaloJetMultHistograms(int selbin)
{
  //printf("deleteAODCaloJetMultHistograms\n");
  hist_file_out[selbin]->cd();
  if(h_nSelectedAODCaloJet[selbin]!=NULL) h_nSelectedAODCaloJet    [selbin] ->Delete();
}


//----------------------------initAODCaloJetTagMultHistograms
Bool_t analyzer_histograms::initAODCaloJetTagMultHistograms( TString uncbin )
{
  for(unsigned int i=0; i<selbinnames.size(); ++i){
    hist_file_out[i]->cd();

      //deleteAODCaloJetTagMultHistograms(i);
      TString hname_nSelectedAODCaloJetTag        = "h_"+selbinnames[i]+"_nSelectedAODCaloJetTag"+uncbin;
      TString hname_nSelectedAODCaloJetTag_orig   = "h_"+selbinnames[i]+"_nSelectedAODCaloJetTag_orig"+uncbin;
      TString hname_nSelectedAODCaloJetTagSB1     = "h_"+selbinnames[i]+"_nSelectedAODCaloJetTagSB1"+uncbin;
      TString hname_nSelectedAODCaloJetTagSB2     = "h_"+selbinnames[i]+"_nSelectedAODCaloJetTagSB2"+uncbin;
      TString hname_nSelectedAODCaloJetTagSB3     = "h_"+selbinnames[i]+"_nSelectedAODCaloJetTagSB3"+uncbin;
      TString hname_nSelectedAODCaloJetTagSB4     = "h_"+selbinnames[i]+"_nSelectedAODCaloJetTagSB4"+uncbin;
      TString hname_nSelectedAODCaloJetTagSB5     = "h_"+selbinnames[i]+"_nSelectedAODCaloJetTagSB5"+uncbin;
      TString hname_nSelectedAODCaloJetTagSB6     = "h_"+selbinnames[i]+"_nSelectedAODCaloJetTagSB6"+uncbin;
      TString hname_nSelectedAODCaloJetTagSB7     = "h_"+selbinnames[i]+"_nSelectedAODCaloJetTagSB7"+uncbin;
      TString hname_nSelectedAODCaloJetTagSBL1     = "h_"+selbinnames[i]+"_nSelectedAODCaloJetTagSBL1"+uncbin;
      TString hname_nSelectedAODCaloJetTagSBL2     = "h_"+selbinnames[i]+"_nSelectedAODCaloJetTagSBL2"+uncbin;
      TString hname_nSelectedAODCaloJetTagSBL3     = "h_"+selbinnames[i]+"_nSelectedAODCaloJetTagSBL3"+uncbin;
      TString hname_nSelectedAODCaloJetTagSBL4     = "h_"+selbinnames[i]+"_nSelectedAODCaloJetTagSBL4"+uncbin;
      TString hname_nSelectedAODCaloJetTagSBL5     = "h_"+selbinnames[i]+"_nSelectedAODCaloJetTagSBL5"+uncbin;
      TString hname_nSelectedAODCaloJetTagSBL6     = "h_"+selbinnames[i]+"_nSelectedAODCaloJetTagSBL6"+uncbin;
      TString hname_nSelectedAODCaloJetTagSBL7     = "h_"+selbinnames[i]+"_nSelectedAODCaloJetTagSBL7"+uncbin;
      TString hname_nSelectedAODCaloJetTagSB2a     = "h_"+selbinnames[i]+"_nSelectedAODCaloJetTagSB2a"+uncbin;
      TString hname_nSelectedAODCaloJetTagSB2b     = "h_"+selbinnames[i]+"_nSelectedAODCaloJetTagSB2b"+uncbin;
      TString hname_nSelectedAODCaloJetTagSB2c     = "h_"+selbinnames[i]+"_nSelectedAODCaloJetTagSB2c"+uncbin;
      TString hname_nSelectedAODCaloJetTagIP       = "h_"+selbinnames[i]+"_nSelectedAODCaloJetTagIP"+uncbin;
      TString hname_nSelectedAODCaloJetTagSBIPa     = "h_"+selbinnames[i]+"_nSelectedAODCaloJetTagSBIPa"+uncbin;
      TString hname_nSelectedAODCaloJetTagSBIPb     = "h_"+selbinnames[i]+"_nSelectedAODCaloJetTagSBIPb"+uncbin;
      TString hname_nSelectedAODCaloJetTagSBIPc     = "h_"+selbinnames[i]+"_nSelectedAODCaloJetTagSBIPc"+uncbin;

      TString hname_nSelectedAODCaloJetTag_0b        = "h_"+selbinnames[i]+"_nSelectedAODCaloJetTag_0b"+uncbin;
      TString hname_nSelectedAODCaloJetTagSB1_0b     = "h_"+selbinnames[i]+"_nSelectedAODCaloJetTagSB1_0b"+uncbin;
      TString hname_nSelectedAODCaloJetTagSB2_0b     = "h_"+selbinnames[i]+"_nSelectedAODCaloJetTagSB2_0b"+uncbin;
      TString hname_nSelectedAODCaloJetTagSB3_0b     = "h_"+selbinnames[i]+"_nSelectedAODCaloJetTagSB3_0b"+uncbin;
      TString hname_nSelectedAODCaloJetTag_1b        = "h_"+selbinnames[i]+"_nSelectedAODCaloJetTag_1b"+uncbin;
      TString hname_nSelectedAODCaloJetTagSB1_1b     = "h_"+selbinnames[i]+"_nSelectedAODCaloJetTagSB1_1b"+uncbin;
      TString hname_nSelectedAODCaloJetTagSB2_1b     = "h_"+selbinnames[i]+"_nSelectedAODCaloJetTagSB2_1b"+uncbin;
      TString hname_nSelectedAODCaloJetTagSB3_1b     = "h_"+selbinnames[i]+"_nSelectedAODCaloJetTagSB3_1b"+uncbin;
      TString hname_nSelectedAODCaloJetTag_2b        = "h_"+selbinnames[i]+"_nSelectedAODCaloJetTag_2b"+uncbin;
      TString hname_nSelectedAODCaloJetTagSB1_2b     = "h_"+selbinnames[i]+"_nSelectedAODCaloJetTagSB1_2b"+uncbin;
      TString hname_nSelectedAODCaloJetTagSB2_2b     = "h_"+selbinnames[i]+"_nSelectedAODCaloJetTagSB2_2b"+uncbin;
      TString hname_nSelectedAODCaloJetTagSB3_2b     = "h_"+selbinnames[i]+"_nSelectedAODCaloJetTagSB3_2b"+uncbin;

      h_nSelectedAODCaloJetTag                [i] = initSingleHistogramTH1F( hname_nSelectedAODCaloJetTag            , "nSelectedAODCaloJetTag"         , 6, -0.5, 5.5);
      h_nSelectedAODCaloJetTag_orig           [i] = initSingleHistogramTH1F( hname_nSelectedAODCaloJetTag_orig       , "nSelectedAODCaloJetTag_orig"    , 6, -0.5, 5.5);
      h_nSelectedAODCaloJetTagSB1             [i] = initSingleHistogramTH1F( hname_nSelectedAODCaloJetTagSB1         , "nSelectedAODCaloJetTagSB1"      , 6, -0.5, 5.5);
      h_nSelectedAODCaloJetTagSB2             [i] = initSingleHistogramTH1F( hname_nSelectedAODCaloJetTagSB2         , "nSelectedAODCaloJetTagSB2"      , 6, -0.5, 5.5);
      h_nSelectedAODCaloJetTagSB3             [i] = initSingleHistogramTH1F( hname_nSelectedAODCaloJetTagSB3         , "nSelectedAODCaloJetTagSB3"      , 6, -0.5, 5.5);
      h_nSelectedAODCaloJetTagSB4             [i] = initSingleHistogramTH1F( hname_nSelectedAODCaloJetTagSB4         , "nSelectedAODCaloJetTagSB4"      , 6, -0.5, 5.5);
      h_nSelectedAODCaloJetTagSB5             [i] = initSingleHistogramTH1F( hname_nSelectedAODCaloJetTagSB5         , "nSelectedAODCaloJetTagSB5"      , 6, -0.5, 5.5);
      h_nSelectedAODCaloJetTagSB6             [i] = initSingleHistogramTH1F( hname_nSelectedAODCaloJetTagSB6         , "nSelectedAODCaloJetTagSB6"      , 6, -0.5, 5.5);
      h_nSelectedAODCaloJetTagSB7             [i] = initSingleHistogramTH1F( hname_nSelectedAODCaloJetTagSB7         , "nSelectedAODCaloJetTagSB7"      , 6, -0.5, 5.5);
      h_nSelectedAODCaloJetTagSBL1             [i] = initSingleHistogramTH1F( hname_nSelectedAODCaloJetTagSBL1         , "nSelectedAODCaloJetTagSBL1"      , 6, -0.5, 5.5);
      h_nSelectedAODCaloJetTagSBL2             [i] = initSingleHistogramTH1F( hname_nSelectedAODCaloJetTagSBL2         , "nSelectedAODCaloJetTagSBL2"      , 6, -0.5, 5.5);
      h_nSelectedAODCaloJetTagSBL3             [i] = initSingleHistogramTH1F( hname_nSelectedAODCaloJetTagSBL3         , "nSelectedAODCaloJetTagSBL3"      , 6, -0.5, 5.5);
      h_nSelectedAODCaloJetTagSBL4             [i] = initSingleHistogramTH1F( hname_nSelectedAODCaloJetTagSBL4         , "nSelectedAODCaloJetTagSBL4"      , 6, -0.5, 5.5);
      h_nSelectedAODCaloJetTagSBL5             [i] = initSingleHistogramTH1F( hname_nSelectedAODCaloJetTagSBL5         , "nSelectedAODCaloJetTagSBL5"      , 6, -0.5, 5.5);
      h_nSelectedAODCaloJetTagSBL6             [i] = initSingleHistogramTH1F( hname_nSelectedAODCaloJetTagSBL6         , "nSelectedAODCaloJetTagSBL6"      , 6, -0.5, 5.5);
      h_nSelectedAODCaloJetTagSBL7             [i] = initSingleHistogramTH1F( hname_nSelectedAODCaloJetTagSBL7         , "nSelectedAODCaloJetTagSBL7"      , 6, -0.5, 5.5);

      h_nSelectedAODCaloJetTagSB2a             [i] = initSingleHistogramTH1F( hname_nSelectedAODCaloJetTagSB2a         , "nSelectedAODCaloJetTagSB2a"      , 6, -0.5, 5.5);
      h_nSelectedAODCaloJetTagSB2b             [i] = initSingleHistogramTH1F( hname_nSelectedAODCaloJetTagSB2b         , "nSelectedAODCaloJetTagSB2b"      , 6, -0.5, 5.5);
      h_nSelectedAODCaloJetTagSB2c             [i] = initSingleHistogramTH1F( hname_nSelectedAODCaloJetTagSB2c         , "nSelectedAODCaloJetTagSB2c"      , 6, -0.5, 5.5);
      h_nSelectedAODCaloJetTagIP               [i] = initSingleHistogramTH1F( hname_nSelectedAODCaloJetTagIP           , "nSelectedAODCaloJetTagIP"        , 6, -0.5, 5.5);
      h_nSelectedAODCaloJetTagSBIPa            [i] = initSingleHistogramTH1F( hname_nSelectedAODCaloJetTagSBIPa        , "nSelectedAODCaloJetTagSBIPa"     , 6, -0.5, 5.5);
      h_nSelectedAODCaloJetTagSBIPb            [i] = initSingleHistogramTH1F( hname_nSelectedAODCaloJetTagSBIPb        , "nSelectedAODCaloJetTagSBIPb"     , 6, -0.5, 5.5);
      h_nSelectedAODCaloJetTagSBIPc            [i] = initSingleHistogramTH1F( hname_nSelectedAODCaloJetTagSBIPc        , "nSelectedAODCaloJetTagSBIPc"     , 6, -0.5, 5.5);


      h_nSelectedAODCaloJetTag_0b                [i] = initSingleHistogramTH1F( hname_nSelectedAODCaloJetTag_0b            , "nSelectedAODCaloJetTag_0b"         , 6, -0.5, 5.5);
      h_nSelectedAODCaloJetTagSB1_0b             [i] = initSingleHistogramTH1F( hname_nSelectedAODCaloJetTagSB1_0b         , "nSelectedAODCaloJetTagSB1_0b"      , 6, -0.5, 5.5);
      h_nSelectedAODCaloJetTagSB2_0b             [i] = initSingleHistogramTH1F( hname_nSelectedAODCaloJetTagSB2_0b         , "nSelectedAODCaloJetTagSB2_0b"      , 6, -0.5, 5.5);
      h_nSelectedAODCaloJetTagSB3_0b             [i] = initSingleHistogramTH1F( hname_nSelectedAODCaloJetTagSB3_0b         , "nSelectedAODCaloJetTagSB3_0b"      , 6, -0.5, 5.5);
      h_nSelectedAODCaloJetTag_1b                [i] = initSingleHistogramTH1F( hname_nSelectedAODCaloJetTag_1b            , "nSelectedAODCaloJetTag_1b"         , 6, -0.5, 5.5);
      h_nSelectedAODCaloJetTagSB1_1b             [i] = initSingleHistogramTH1F( hname_nSelectedAODCaloJetTagSB1_1b         , "nSelectedAODCaloJetTagSB1_1b"      , 6, -0.5, 5.5);
      h_nSelectedAODCaloJetTagSB2_1b             [i] = initSingleHistogramTH1F( hname_nSelectedAODCaloJetTagSB2_1b         , "nSelectedAODCaloJetTagSB2_1b"      , 6, -0.5, 5.5);
      h_nSelectedAODCaloJetTagSB3_1b             [i] = initSingleHistogramTH1F( hname_nSelectedAODCaloJetTagSB3_1b         , "nSelectedAODCaloJetTagSB3_1b"      , 6, -0.5, 5.5);
      h_nSelectedAODCaloJetTag_2b                [i] = initSingleHistogramTH1F( hname_nSelectedAODCaloJetTag_2b            , "nSelectedAODCaloJetTag_2b"         , 6, -0.5, 5.5);
      h_nSelectedAODCaloJetTagSB1_2b             [i] = initSingleHistogramTH1F( hname_nSelectedAODCaloJetTagSB1_2b         , "nSelectedAODCaloJetTagSB1_2b"      , 6, -0.5, 5.5);
      h_nSelectedAODCaloJetTagSB2_2b             [i] = initSingleHistogramTH1F( hname_nSelectedAODCaloJetTagSB2_2b         , "nSelectedAODCaloJetTagSB2_2b"      , 6, -0.5, 5.5);
      h_nSelectedAODCaloJetTagSB3_2b             [i] = initSingleHistogramTH1F( hname_nSelectedAODCaloJetTagSB3_2b         , "nSelectedAODCaloJetTagSB3_2b"      , 6, -0.5, 5.5);
  }//sel                                                                                                                                                                                
}

//----------------------------fillAODCaloJetTagMultHistograms
Bool_t analyzer_histograms::fillAODCaloJetTagMultHistograms(Float_t weight, int selbin)
{
  hist_file_out[selbin]->cd();
  if(taggedjet_list.size()<2)    h_nSelectedAODCaloJetTag       [selbin] ->Fill( float(taggedjet_list.size()), weight );
  else                           h_nSelectedAODCaloJetTag       [selbin] ->Fill( 2.                          , weight );
  h_nSelectedAODCaloJetTag_orig  [selbin] ->Fill( float(taggedjet_list.size()), weight );
  h_nSelectedAODCaloJetTagSB1    [selbin] ->Fill( float(taggedjetSB1_list.size()), weight );
  h_nSelectedAODCaloJetTagSB2    [selbin] ->Fill( float(taggedjetSB2_list.size()), weight );
  h_nSelectedAODCaloJetTagSB3    [selbin] ->Fill( float(taggedjetSB3_list.size()), weight );
  h_nSelectedAODCaloJetTagSB4    [selbin] ->Fill( float(taggedjetSB4_list.size()), weight );
  h_nSelectedAODCaloJetTagSB5    [selbin] ->Fill( float(taggedjetSB5_list.size()), weight );
  h_nSelectedAODCaloJetTagSB6    [selbin] ->Fill( float(taggedjetSB6_list.size()), weight );
  h_nSelectedAODCaloJetTagSB7    [selbin] ->Fill( float(taggedjetSB7_list.size()), weight );
  h_nSelectedAODCaloJetTagSBL1    [selbin] ->Fill( float(taggedjetSBL1_list.size()), weight );
  h_nSelectedAODCaloJetTagSBL2    [selbin] ->Fill( float(taggedjetSBL2_list.size()), weight );
  h_nSelectedAODCaloJetTagSBL3    [selbin] ->Fill( float(taggedjetSBL3_list.size()), weight );
  h_nSelectedAODCaloJetTagSBL4    [selbin] ->Fill( float(taggedjetSBL4_list.size()), weight );
  h_nSelectedAODCaloJetTagSBL5    [selbin] ->Fill( float(taggedjetSBL5_list.size()), weight );
  h_nSelectedAODCaloJetTagSBL6    [selbin] ->Fill( float(taggedjetSBL6_list.size()), weight );
  h_nSelectedAODCaloJetTagSBL7    [selbin] ->Fill( float(taggedjetSBL7_list.size()), weight );

  h_nSelectedAODCaloJetTagSB2a    [selbin] ->Fill( float(taggedjetSB2a_list.size()), weight );
  h_nSelectedAODCaloJetTagSB2b    [selbin] ->Fill( float(taggedjetSB2b_list.size()), weight );
  h_nSelectedAODCaloJetTagSB2c    [selbin] ->Fill( float(taggedjetSB2c_list.size()), weight );
  h_nSelectedAODCaloJetTagIP      [selbin] ->Fill( float(taggedjetIP_list.size()), weight );
  h_nSelectedAODCaloJetTagSBIPa    [selbin] ->Fill( float(taggedjetSBIPa_list.size()), weight );
  h_nSelectedAODCaloJetTagSBIPb    [selbin] ->Fill( float(taggedjetSBIPb_list.size()), weight );
  h_nSelectedAODCaloJetTagSBIPc    [selbin] ->Fill( float(taggedjetSBIPc_list.size()), weight );

//  if(nBPartonFlavour==0){
//    h_nSelectedAODCaloJetTag_0b       [selbin] ->Fill( float(taggedjet_list.size()), weight );
//    h_nSelectedAODCaloJetTagSB1_0b    [selbin] ->Fill( float(taggedjetSB1_list.size()), weight );
//    h_nSelectedAODCaloJetTagSB2_0b    [selbin] ->Fill( float(taggedjetSB2_list.size()), weight );
//    h_nSelectedAODCaloJetTagSB3_0b    [selbin] ->Fill( float(taggedjetSB3_list.size()), weight );
//  }
//  else if(nBPartonFlavour==1){
//    h_nSelectedAODCaloJetTag_1b       [selbin] ->Fill( float(taggedjet_list.size()), weight );
//    h_nSelectedAODCaloJetTagSB1_1b    [selbin] ->Fill( float(taggedjetSB1_list.size()), weight );
//    h_nSelectedAODCaloJetTagSB2_1b    [selbin] ->Fill( float(taggedjetSB2_list.size()), weight );
//    h_nSelectedAODCaloJetTagSB3_1b    [selbin] ->Fill( float(taggedjetSB3_list.size()), weight );
//  }
//  else if(nBPartonFlavour>=2){
//    h_nSelectedAODCaloJetTag_2b       [selbin] ->Fill( float(taggedjet_list.size()), weight );
//    h_nSelectedAODCaloJetTagSB1_2b    [selbin] ->Fill( float(taggedjetSB1_list.size()), weight );
//    h_nSelectedAODCaloJetTagSB2_2b    [selbin] ->Fill( float(taggedjetSB2_list.size()), weight );
//    h_nSelectedAODCaloJetTagSB3_2b    [selbin] ->Fill( float(taggedjetSB3_list.size()), weight );
//  }

}

//----------------------------writeAODCaloJetTagMultHistograms
Bool_t analyzer_histograms::writeAODCaloJetTagMultHistograms(int selbin)
{
  hist_file_out[selbin]->cd();

  h_nSelectedAODCaloJetTag       [selbin] ->Write();
  h_nSelectedAODCaloJetTag_orig  [selbin] ->Write();
  h_nSelectedAODCaloJetTagSB1    [selbin] ->Write();
  h_nSelectedAODCaloJetTagSB2    [selbin] ->Write();
  h_nSelectedAODCaloJetTagSB3    [selbin] ->Write();
  h_nSelectedAODCaloJetTagSB4    [selbin] ->Write();
  h_nSelectedAODCaloJetTagSB5    [selbin] ->Write();
  h_nSelectedAODCaloJetTagSB6    [selbin] ->Write();
  h_nSelectedAODCaloJetTagSB7    [selbin] ->Write();
  h_nSelectedAODCaloJetTagSBL1    [selbin] ->Write();
  h_nSelectedAODCaloJetTagSBL2    [selbin] ->Write();
  h_nSelectedAODCaloJetTagSBL3    [selbin] ->Write();
  h_nSelectedAODCaloJetTagSBL4    [selbin] ->Write();
  h_nSelectedAODCaloJetTagSBL5    [selbin] ->Write();
  h_nSelectedAODCaloJetTagSBL6    [selbin] ->Write();
  h_nSelectedAODCaloJetTagSBL7    [selbin] ->Write();

  h_nSelectedAODCaloJetTagSB2a    [selbin] ->Write();
  h_nSelectedAODCaloJetTagSB2b    [selbin] ->Write();
  h_nSelectedAODCaloJetTagSB2c    [selbin] ->Write();
  h_nSelectedAODCaloJetTagIP      [selbin] ->Write();
  h_nSelectedAODCaloJetTagSBIPa    [selbin] ->Write();
  h_nSelectedAODCaloJetTagSBIPb    [selbin] ->Write();
  h_nSelectedAODCaloJetTagSBIPc    [selbin] ->Write();

  h_nSelectedAODCaloJetTag_0b       [selbin] ->Write();
  h_nSelectedAODCaloJetTagSB1_0b    [selbin] ->Write();
  h_nSelectedAODCaloJetTagSB2_0b    [selbin] ->Write();
  h_nSelectedAODCaloJetTagSB3_0b    [selbin] ->Write();
  h_nSelectedAODCaloJetTag_1b       [selbin] ->Write();
  h_nSelectedAODCaloJetTagSB1_1b    [selbin] ->Write();
  h_nSelectedAODCaloJetTagSB2_1b    [selbin] ->Write();
  h_nSelectedAODCaloJetTagSB3_1b    [selbin] ->Write();
  h_nSelectedAODCaloJetTag_2b       [selbin] ->Write();
  h_nSelectedAODCaloJetTagSB1_2b    [selbin] ->Write();
  h_nSelectedAODCaloJetTagSB2_2b    [selbin] ->Write();
  h_nSelectedAODCaloJetTagSB3_2b    [selbin] ->Write();
}

//----------------------------deleteAODCaloJetTagMultHistograms
Bool_t analyzer_histograms::deleteAODCaloJetTagMultHistograms(int selbin)
{
  //printf("deleteAODCaloJetTagMultHistograms\n");
  hist_file_out[selbin]->cd();

  if(h_nSelectedAODCaloJetTag      [selbin]!=NULL)    h_nSelectedAODCaloJetTag       [selbin] ->Delete();
  if(h_nSelectedAODCaloJetTag_orig [selbin]!=NULL)    h_nSelectedAODCaloJetTag_orig  [selbin] ->Delete();
  if(h_nSelectedAODCaloJetTagSB1   [selbin]!=NULL)    h_nSelectedAODCaloJetTagSB1    [selbin] ->Delete();
  if(h_nSelectedAODCaloJetTagSB2   [selbin]!=NULL)    h_nSelectedAODCaloJetTagSB2    [selbin] ->Delete();
  if(h_nSelectedAODCaloJetTagSB3   [selbin]!=NULL)    h_nSelectedAODCaloJetTagSB3    [selbin] ->Delete();
  if(h_nSelectedAODCaloJetTagSB4   [selbin]!=NULL)    h_nSelectedAODCaloJetTagSB4    [selbin] ->Delete();
  if(h_nSelectedAODCaloJetTagSB5   [selbin]!=NULL)    h_nSelectedAODCaloJetTagSB5    [selbin] ->Delete();
  if(h_nSelectedAODCaloJetTagSB6   [selbin]!=NULL)    h_nSelectedAODCaloJetTagSB6    [selbin] ->Delete();
  if(h_nSelectedAODCaloJetTagSB7   [selbin]!=NULL)    h_nSelectedAODCaloJetTagSB7    [selbin] ->Delete();
  if(h_nSelectedAODCaloJetTagSBL1  [selbin]!=NULL)    h_nSelectedAODCaloJetTagSBL1    [selbin] ->Delete();
  if(h_nSelectedAODCaloJetTagSBL2  [selbin]!=NULL)    h_nSelectedAODCaloJetTagSBL2    [selbin] ->Delete();
  if(h_nSelectedAODCaloJetTagSBL3  [selbin]!=NULL)    h_nSelectedAODCaloJetTagSBL3    [selbin] ->Delete();
  if(h_nSelectedAODCaloJetTagSBL4  [selbin]!=NULL)    h_nSelectedAODCaloJetTagSBL4    [selbin] ->Delete();
  if(h_nSelectedAODCaloJetTagSBL5  [selbin]!=NULL)    h_nSelectedAODCaloJetTagSBL5    [selbin] ->Delete();
  if(h_nSelectedAODCaloJetTagSBL6  [selbin]!=NULL)    h_nSelectedAODCaloJetTagSBL6    [selbin] ->Delete();
  if(h_nSelectedAODCaloJetTagSBL7  [selbin]!=NULL)    h_nSelectedAODCaloJetTagSBL7    [selbin] ->Delete();
  
  if(h_nSelectedAODCaloJetTagSB2a  [selbin]!=NULL)    h_nSelectedAODCaloJetTagSB2a    [selbin] ->Delete();
  if(h_nSelectedAODCaloJetTagSB2b  [selbin]!=NULL)    h_nSelectedAODCaloJetTagSB2b    [selbin] ->Delete();
  if(h_nSelectedAODCaloJetTagSB2c  [selbin]!=NULL)    h_nSelectedAODCaloJetTagSB2c    [selbin] ->Delete();
  if(h_nSelectedAODCaloJetTagIP    [selbin]!=NULL)    h_nSelectedAODCaloJetTagIP      [selbin] ->Delete();
  if(h_nSelectedAODCaloJetTagSBIPa [selbin]!=NULL)    h_nSelectedAODCaloJetTagSBIPa    [selbin] ->Delete();
  if(h_nSelectedAODCaloJetTagSBIPb [selbin]!=NULL)    h_nSelectedAODCaloJetTagSBIPb    [selbin] ->Delete();
  if(h_nSelectedAODCaloJetTagSBIPc [selbin]!=NULL)    h_nSelectedAODCaloJetTagSBIPc    [selbin] ->Delete();
  
  if(h_nSelectedAODCaloJetTag_0b   [selbin]!=NULL)    h_nSelectedAODCaloJetTag_0b       [selbin] ->Delete();
  if(h_nSelectedAODCaloJetTagSB1_0b[selbin]!=NULL)    h_nSelectedAODCaloJetTagSB1_0b    [selbin] ->Delete();
  if(h_nSelectedAODCaloJetTagSB2_0b[selbin]!=NULL)    h_nSelectedAODCaloJetTagSB2_0b    [selbin] ->Delete();
  if(h_nSelectedAODCaloJetTagSB3_0b[selbin]!=NULL)    h_nSelectedAODCaloJetTagSB3_0b    [selbin] ->Delete();
  if(h_nSelectedAODCaloJetTag_1b   [selbin]!=NULL)    h_nSelectedAODCaloJetTag_1b       [selbin] ->Delete();
  if(h_nSelectedAODCaloJetTagSB1_1b[selbin]!=NULL)    h_nSelectedAODCaloJetTagSB1_1b    [selbin] ->Delete();
  if(h_nSelectedAODCaloJetTagSB2_1b[selbin]!=NULL)    h_nSelectedAODCaloJetTagSB2_1b    [selbin] ->Delete();
  if(h_nSelectedAODCaloJetTagSB3_1b[selbin]!=NULL)    h_nSelectedAODCaloJetTagSB3_1b    [selbin] ->Delete();
  if(h_nSelectedAODCaloJetTag_2b   [selbin]!=NULL)    h_nSelectedAODCaloJetTag_2b       [selbin] ->Delete();
  if(h_nSelectedAODCaloJetTagSB1_2b[selbin]!=NULL)    h_nSelectedAODCaloJetTagSB1_2b    [selbin] ->Delete();
  if(h_nSelectedAODCaloJetTagSB2_2b[selbin]!=NULL)    h_nSelectedAODCaloJetTagSB2_2b    [selbin] ->Delete();
  if(h_nSelectedAODCaloJetTagSB3_2b[selbin]!=NULL)    h_nSelectedAODCaloJetTagSB3_2b    [selbin] ->Delete();
}
