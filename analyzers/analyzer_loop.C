#define analyzer_loop_cxx
#include "analyzer_loop.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <iomanip>

using namespace std;

analyzer_loop::analyzer_loop()
{
}

analyzer_loop::~analyzer_loop()
{
}

void analyzer_loop::Loop(TString outfilename, 
                       Float_t lumi, Float_t nrEvents,
                       Float_t crossSec,
                       Int_t nevts, TFile *optfile, TString uncbin)
{


 if(makelog){
  logfile = fopen( outfilename+".txt", "w"); 
 }

 if (fChain == 0) return;

 Long64_t nentries = fChain->GetEntriesFast();
 if(nevts>0){ 
  nentries = Long64_t(nevts);
 }
 
 clearglobalcounters();

 if(isMC) loadPUWeight();
 if(isMC) loadElectronReco();
 if(isMC) loadElectronWeight( eleid );
 if(isMC) loadMuonWeight( muoid );
 if(isMC) loadMuonIso( muoid );

 std::cout<<"uncbin: "<<uncbin<<std::endl;

 TH1F* h_sum_AODGenEventWeight = new TH1F("h_sum_AODGenEventWeight","h_sum_AODGenEventWeight", 5,0.,5.);
// TFile *outfile_nPU = 0;
// outfile_nPU = TFile::Open(outfilename+"_AOD0thnPU.root","RECREATE");
// TH1F* h_sum_AOD0thnPU = new TH1F("h_sum_AOD0thnPU","h_sum_AOD0thnPU", 120,0.00,120.00);

 // start looping over entries
 Long64_t nbytes = 0, nb = 0;
 for (Long64_t jentry=0; jentry<nentries;jentry++) {

  L1PFremoved=kFALSE;
  cleareventcounters();

//  if( uncbin.EqualTo("") ){
//   optfile->cd();
//   clearOPTtree(); 
//   clearOPTCRHeavytree(); 
//   clearOPTCRLighttree(); 
//   clearOPTMuZHtree(); 
//   clearOPTEleZHtree(); 
//  }

  //printf(" Event %lld\n", event);
  Long64_t ientry = LoadTree(jentry);
  if (ientry < 0) break;
  nb = fChain->GetEntry(jentry);   nbytes += nb;
  if (jentry%10000 == 0){ std::cout << " entry " << jentry << std::endl; }

  shiftCollections(uncbin);
  n_tot++;
  sum_AODGenEventWeight+=AODGenEventWeight;
  h_sum_AODGenEventWeight->Fill(2, AODGenEventWeight);
  //h_sum_AOD0thnPU->Fill(AOD0thnPU);
  // get lists of "good" electrons, jets idbit, pt, eta, sysbinname
  electron_list    = electron_passID  ( eleidbit,        ele_minPt1, ele_minPt2, ele_maxEta, "");
  muon_list        = muon_passID      ( muoidbit,        mu_minPt1,  mu_minPt2,  mu_maxEta,  ""); 
  aodcalojet_list  = jet_passID       ( aodcalojetidbit, "calo",  jet_minPt, jet_maxEta, "" ); 
  taggedjet_list   = jet_passTagger   ();
  taggedjetSB1_list   = jet_passTaggerSB1   ();
  taggedjetSB2_list   = jet_passTaggerSB2   ();
  taggedjetSB3_list   = jet_passTaggerSB3   ();
  taggedjetSB4_list   = jet_passTaggerSB4   ();
  taggedjetSB5_list   = jet_passTaggerSB5   ();
  taggedjetSB6_list   = jet_passTaggerSB6   ();
  taggedjetSB7_list   = jet_passTaggerSB7   ();
  taggedjetSBL1_list   = jet_passTaggerSBL1   ();
  taggedjetSBL2_list   = jet_passTaggerSBL2   ();
  taggedjetSBL3_list   = jet_passTaggerSBL3   ();
  taggedjetSBL4_list   = jet_passTaggerSBL4   ();
  taggedjetSBL5_list   = jet_passTaggerSBL5   ();
  taggedjetSBL6_list   = jet_passTaggerSBL6   ();
  taggedjetSBL7_list   = jet_passTaggerSBL7   ();
  taggedjetSB2a_list   = jet_passTaggerSB2a   ();
  taggedjetSB2b_list   = jet_passTaggerSB2b   ();
  taggedjetSB2c_list   = jet_passTaggerSB2c   ();
  taggedjetIP_list   = jet_passTaggerIP   ();
  taggedjetSBIPa_list   = jet_passTaggerSBIPa   ();
  taggedjetSBIPb_list   = jet_passTaggerSBIPb   ();
  taggedjetSBIPc_list   = jet_passTaggerSBIPc   ();  


  //save jets list for L1PF test clear list if does not pass
  aodcalojet_L1PF_list  = jet_passID       ( aodcalojetidbit, "calo",  jet_minPt, jet_maxEta, "" ); 
  bool pass_L1PF = true;
  //checks for L1PF test
  for(int i=0; i<aodcalojet_list.size(); i++){
    int jetindex = aodcalojet_list[i];
    if(AODCaloJetPt->at(jetindex)>100.0 && (fabs(AODCaloJetEta->at(jetindex))<3.0 && fabs(AODCaloJetEta->at(jetindex))>2.25)) pass_L1PF = false;
  }
  // remove event from jet based tagging variables for comparisons
  if(!pass_L1PF){aodcalojet_L1PF_list.clear(); L1PFremoved = kTRUE;}
  taggedjet_list_L1PF = jet_passTagger_L1PF ();

  n_totalCalo        += aodcalojet_list.size()        ; 
  aodcalojet_minDR_list = jet_minDR();
  
  // colisions happen @LHC at a given rate, use event_weight
  // to make the simulation match the rate seen in data
  // = lum * cross-section / nrEvents generated
  event_weight = makeEventWeight(crossSec,lumi,nrEvents);
  // for MC, simulated pileup is different from observed
  // in commontools/pileup we make a ratio for scaling MC
  if(isMC) PUweight_DoubleEG     = makePUWeight("DoubleEG"    ) ;
  if(isMC) PUweight_DoubleMu     = makePUWeight("DoubleMu"    ) ;
  if(isMC) PUweight_MuonEG       = makePUWeight("MuonEG"      ) ;

  
  base_weight = event_weight; ///.7323;
  ele_weight = 1.0;
  if(isMC) ele_weight  = makeElectronWeight( electron_list, eleID_Unc, eleID_ind);
  if(isMC) mu_weight   = makeMuonWeight(muon_list, muonID_Unc, muonID_ind);
  if(isMC) event_weight *= ctauEventWeight;
  if(isMC){ 
    w_eleReco = makeElectronReco(electron_list, eleReco_Unc, eleReco_ind);
    w_eleID   = ele_weight;
    w_muonID  = mu_weight;
    w_muonISO = makeMuonIso(muon_list, muonISO_Unc, muonISO_ind);
  }

  calculateHT();

  makeDiLepton();

  // set booleans if pass selections 
  passOSSF = (dilep_mass>20.);
  passOSOF = (OSOF_mass>20.);
  passPTOSOF     = (OSOF_pt>dilepPt_split);
  passPTOSOFL    = (OSOF_pt>dilepPt_min && OSOF_pt<dilepPt_split);

  passPTOSSF     = (dilep_pt>=dilepPt_split);
  passPTOSSFL    = (dilep_pt>=dilepPt_min && dilep_pt<dilepPt_split);
  passPTOSSFL_2  = (dilep_pt>=dilepPt_min);

  passZWindow = (dilep_mass>ZMass_min && dilep_mass<ZMass_max);
  passZWinOSOF= (OSOF_mass >ZMass_min && OSOF_mass <ZMass_max);


  passGoodVtx = AODnGoodVtx>0; 
  passOneJet  = false; if (aodcalojet_list.size()>0) passOneJet=true;  
  passOneTag  = false; if (taggedjet_list.size()>0) passOneTag=true;  
  passTwoTag  = false; if (taggedjet_list.size()>1) passTwoTag=true;  
  
  passSingleEle = askPassSingleEle();
  passSingleMu  = askPassSingleMu();
  passDoubleEle = askPassDoubleEle();
  passDoubleMu  = askPassDoubleMu();
  passMuEG      = askPassMuEG();

  // clear then reset selection vectors
  clearSelections();
  setSelections();

  // set bits if pass various selections, increment counters
  bitsPassOneEleSig    = setSelBits( selvecOneEleSig    , n_passOneEleSig    );   
  bitsPassTwoEleSig    = setSelBits( selvecTwoEleSig    , n_passTwoEleSig    );   
  bitsPassOneMuSig     = setSelBits( selvecOneMuSig     , n_passOneMuSig     );   
  bitsPassTwoMuSig     = setSelBits( selvecTwoMuSig     , n_passTwoMuSig     );   
  bitsPassOneEleDY     = setSelBits( selvecOneEleDY     , n_passOneEleDY     );   
  bitsPassTwoEleDY     = setSelBits( selvecTwoEleDY     , n_passTwoEleDY     );   
  bitsPassOneMuDY      = setSelBits( selvecOneMuDY      , n_passOneMuDY      );   
  bitsPassTwoMuDY      = setSelBits( selvecTwoMuDY      , n_passTwoMuDY      );   
  bitsPassOneEleZH     = setSelBits( selvecOneEleZH     , n_passOneEleZH     );   
  bitsPassTwoEleZH     = setSelBits( selvecTwoEleZH     , n_passTwoEleZH     );   
  bitsPassOneMuZH      = setSelBits( selvecOneMuZH      , n_passOneMuZH      );   
  bitsPassTwoMuZH      = setSelBits( selvecTwoMuZH      , n_passTwoMuZH      );   
  bitsPassOneEleOffZ   = setSelBits( selvecOneEleOffZ   , n_passOneEleOffZ   );   
  bitsPassTwoEleOffZ   = setSelBits( selvecTwoEleOffZ   , n_passTwoEleOffZ   );   
  bitsPassOneMuOffZ    = setSelBits( selvecOneMuOffZ    , n_passOneMuOffZ    );   
  bitsPassTwoMuOffZ    = setSelBits( selvecTwoMuOffZ    , n_passTwoMuOffZ    );   
  bitsPassOneEleNoPair = setSelBits( selvecOneEleNoPair , n_passOneEleNoPair ); 
  bitsPassOneMuNoPair  = setSelBits( selvecOneMuNoPair  , n_passOneMuNoPair  );   
  bitsPassEleMuOSOF    = setSelBits( selvecEleMuOSOF    , n_passEleMuOSOF    );   
  bitsPassEleMuOSOFL   = setSelBits( selvecEleMuOSOFL   , n_passEleMuOSOFL   );   

  keyPassOneEleSig    = setSelKey( selvecOneEleSig    ); 
  keyPassTwoEleSig    = setSelKey( selvecTwoEleSig    ); 
  keyPassOneMuSig     = setSelKey( selvecOneMuSig     ); 
  keyPassTwoMuSig     = setSelKey( selvecTwoMuSig     ); 
  keyPassOneEleDY     = setSelKey( selvecOneEleDY     ); 
  keyPassTwoEleDY     = setSelKey( selvecTwoEleDY     ); 
  keyPassOneMuDY      = setSelKey( selvecOneMuDY      ); 
  keyPassTwoMuDY      = setSelKey( selvecTwoMuDY      ); 
  keyPassOneEleZH     = setSelKey( selvecOneEleZH     ); 
  keyPassTwoEleZH     = setSelKey( selvecTwoEleZH     ); 
  keyPassOneMuZH      = setSelKey( selvecOneMuZH      ); 
  keyPassTwoMuZH      = setSelKey( selvecTwoMuZH      ); 
  keyPassOneEleOffZ   = setSelKey( selvecOneEleOffZ   ); 
  keyPassTwoEleOffZ   = setSelKey( selvecTwoEleOffZ   ); 
  keyPassOneMuOffZ    = setSelKey( selvecOneMuOffZ    ); 
  keyPassTwoMuOffZ    = setSelKey( selvecTwoMuOffZ    ); 
  keyPassOneEleNoPair = setSelKey( selvecOneEleNoPair ); 
  keyPassOneMuNoPair  = setSelKey( selvecOneMuNoPair  ); 
  keyPassEleMuOSOF    = setSelKey( selvecEleMuOSOF    ); 
  keyPassEleMuOSOFL   = setSelKey( selvecEleMuOSOFL   ); 

  //debug_printbitset(); // this is a big printout
  //debug_printbitkeys(); // this is a big printout

  // put into array for looping in Cutflow histograms
  selvec[0]  = bitsPassOneEleSig    ; 
  selvec[1]  = bitsPassTwoEleSig    ; 
  selvec[2]  = bitsPassOneMuSig     ; 
  selvec[3]  = bitsPassTwoMuSig     ; 
  selvec[4]  = bitsPassOneEleDY     ; 
  selvec[5]  = bitsPassTwoEleDY     ; 
  selvec[6]  = bitsPassOneMuDY      ; 
  selvec[7]  = bitsPassTwoMuDY      ; 
  selvec[8]  = bitsPassOneEleZH     ; 
  selvec[9]  = bitsPassTwoEleZH     ; 
  selvec[10] = bitsPassOneMuZH      ; 
  selvec[11] = bitsPassTwoMuZH      ; 
  selvec[12] = bitsPassOneEleOffZ   ; 
  selvec[13] = bitsPassTwoEleOffZ   ; 
  selvec[14] = bitsPassOneMuOffZ    ; 
  selvec[15] = bitsPassTwoMuOffZ    ; 
  selvec[16] = bitsPassOneEleNoPair ; 
  selvec[17] = bitsPassOneMuNoPair  ; 
  selvec[18] = bitsPassEleMuOSOF    ; 
  selvec[19] = bitsPassEleMuOSOFL   ; 

  selkey[0]  = keyPassOneEleSig    ; 
  selkey[1]  = keyPassTwoEleSig    ; 
  selkey[2]  = keyPassOneMuSig     ; 
  selkey[3]  = keyPassTwoMuSig     ; 
  selkey[4]  = keyPassOneEleDY     ; 
  selkey[5]  = keyPassTwoEleDY     ; 
  selkey[6]  = keyPassOneMuDY      ; 
  selkey[7]  = keyPassTwoMuDY      ; 
  selkey[8]  = keyPassOneEleZH     ; 
  selkey[9]  = keyPassTwoEleZH     ; 
  selkey[10] = keyPassOneMuZH      ; 
  selkey[11] = keyPassTwoMuZH      ; 
  selkey[12] = keyPassOneEleOffZ   ; 
  selkey[13] = keyPassTwoEleOffZ   ; 
  selkey[14] = keyPassOneMuOffZ    ; 
  selkey[15] = keyPassTwoMuOffZ    ; 
  selkey[16] = keyPassOneEleNoPair ; 
  selkey[17] = keyPassOneMuNoPair  ; 
  selkey[18] = keyPassEleMuOSOF    ; 
  selkey[19] = keyPassEleMuOSOFL   ; 

  dofillselbin[0]  = ( ( bitsPassOneEleSig    >> 0) &1) ; 
  dofillselbin[1]  = ( ( bitsPassTwoEleSig    >> 0) &1) ; 
  dofillselbin[2]  = ( ( bitsPassOneMuSig     >> 0) &1) ; 
  dofillselbin[3]  = ( ( bitsPassTwoMuSig     >> 0) &1) ; 
  dofillselbin[4]  = ( ( bitsPassOneEleDY     >> 0) &1) ; 
  dofillselbin[5]  = ( ( bitsPassTwoEleDY     >> 0) &1) ; 
  dofillselbin[6]  = ( ( bitsPassOneMuDY      >> 0) &1) ; 
  dofillselbin[7]  = ( ( bitsPassTwoMuDY      >> 0) &1) ; 
  dofillselbin[8]  = ( ( bitsPassOneEleZH     >> 0) &1) ; 
  dofillselbin[9]  = ( ( bitsPassTwoEleZH     >> 0) &1) ; 
  dofillselbin[10] = ( ( bitsPassOneMuZH      >> 0) &1) ; 
  dofillselbin[11] = ( ( bitsPassTwoMuZH      >> 0) &1) ; 
  dofillselbin[12] = ( ( bitsPassOneEleOffZ   >> 0) &1) ; 
  dofillselbin[13] = ( ( bitsPassTwoEleOffZ   >> 0) &1) ; 
  dofillselbin[14] = ( ( bitsPassOneMuOffZ    >> 0) &1) ; 
  dofillselbin[15] = ( ( bitsPassTwoMuOffZ    >> 0) &1) ; 
  dofillselbin[16] = ( ( bitsPassOneEleNoPair >> 0) &1) ; 
  dofillselbin[17] = ( ( bitsPassOneMuNoPair  >> 0) &1) ; 
  dofillselbin[18] = ( ( bitsPassEleMuOSOF    >> 0) &1) ; 
  dofillselbin[19] = ( ( bitsPassEleMuOSOFL   >> 0) &1) ; 

  if ( (( bitsPassTwoMuOffZ      >> 0) &1) ){PU_weight = PUweight_DoubleMu; } 
  if ( (( bitsPassTwoEleOffZ     >> 0) &1) ){PU_weight = PUweight_DoubleEG; }
  // fill the histograms
  for(unsigned int i=0; i<selbinnames.size(); ++i){
    //if(!isMC && run>=319077){/*std::cout<<"HEM Failure, run: "<<run<<std::endl;*/ continue;} // skips HEM Failure, saves prior to problem
    //if(!isMC && run<319077 && run>0){/*std::cout<<"Before HEM Failure, run: "<<run<<std::endl;*/ continue;} //skips Before HEM Failure, saves HEM Failure
    w_LeptonSF=1.;
   if(isMC){
     if(i==0||i==1||i==4||i==5||i==8||i==9||i==12||i==13)  
	{
	fullweight = event_weight*PUweight_DoubleEG;  	
	w_LeptonSF = w_eleReco;
	w_LeptonSF *= w_eleID;
	ESF_Unc = TMath::Sqrt(eleID_Unc*eleID_Unc+eleReco_Unc*eleReco_Unc);	
	}
     if(i==2||i==3||i==6||i==7||i==10||i==11||i==14||i==15||i==17) 
	{
	fullweight = event_weight*PUweight_DoubleMu;    
	w_LeptonSF=w_muonID;
	w_LeptonSF*=w_muonISO; 
	MSF_Unc = TMath::Sqrt(muonID_Unc*muonID_Unc+muonISO_Unc*muonISO_Unc);	
	}
     if(i==18||i==19) 
	{
	fullweight = event_weight * PUweight_MuonEG; 
	w_LeptonSF=w_eleReco*w_eleID*w_muonID*w_muonISO; 
	ESF_Unc = TMath::Sqrt(eleID_Unc*eleID_Unc+eleReco_Unc*eleReco_Unc);	
	MSF_Unc = TMath::Sqrt(muonID_Unc*muonID_Unc+muonISO_Unc*muonISO_Unc);	
	}
     if(uncbin.Contains("ESFUp")){w_LeptonSF += ESF_Unc;}
     if(uncbin.Contains("ESFDown")){w_LeptonSF -= ESF_Unc;}
     if(uncbin.Contains("MSFUp")){w_LeptonSF += MSF_Unc;}
     if(uncbin.Contains("MSFDown")){w_LeptonSF -=MSF_Unc;}
     fullweight*=w_LeptonSF;
   }
   else{
     fullweight = event_weight;
   }
   /// quick hack to only write phase spaces we care about
   if(i==1 || i==3 || i==5 || i==7 || i==9 || i==11 || i==13 || i==15 || i==18 || i==19 ){
    fillCutflowHistograms( fullweight, i, selvec[i], selkey[i] );
    if( dofillselbin[i] ){
     fillSelectedHistograms( fullweight, i );

     //jets
     if(jetMultOn){
     for( unsigned int k=0; k<jetmultnames.size(); ++k){
      fillSelectedJetHistograms( fullweight, i, k );
     }  }
     else{
     fillSelectedJetHistograms( fullweight, i, (jetmultnames.size()-1) );
     }

     //tagged jets
     for( unsigned int k=0; k<tagmultnames.size(); ++k){
      fillSelectedTagHistograms( fullweight, i, k );
     }  
    } // if( dofillselbin[i] ){
   } // if i== one of the phase spaces we want to write
  } // for(unsigned int i=0; i<selbinnames.size(); ++i){

  // tagging variable optimization tree
/////  if( ( (( bitsPassTwoMuOffZ      >> 0) &1) || (( bitsPassTwoEleOffZ      >> 0) &1))  && uncbin.EqualTo("") ){// TwoMuZH or TwoEleZH 
/////   optfile->cd();
/////   setOPTtree(); 
/////   OPTtree->Fill();
/////  }
  //debug_printobjects();   // helpful printout (turn off when submitting!!!)

  //Print objects in backgroundMC with >=2 tags
  //if(taggedjet_list.size()>=2 && isMC && !outfilename.Contains("HToSS")) debug_printobjects();
  //printf("make log: %0.i\n",makelog);
  
 } // end loop over entries

 std::cout << std::endl;
 std::cout << std::endl;
 std::cout << " Summary     cleaning dR=" << objcleandRcut << std::endl;

 std::cout << " Total events processed  " << n_tot << std::endl;

 std::cout<<" n_passOneEleSig    " << setw(width) << left << n_passOneEleSig    << setw(width) << left << (float) n_passOneEleSig   / (float) n_tot << std::endl;   
 std::cout<<" n_passTwoEleSig    " << setw(width) << left << n_passTwoEleSig    << setw(width) << left << (float) n_passTwoEleSig   / (float) n_tot << std::endl;   
 std::cout<<" n_passOneMuSig     " << setw(width) << left << n_passOneMuSig     << setw(width) << left << (float) n_passOneMuSig    / (float) n_tot << std::endl;   
 std::cout<<" n_passTwoMuSig     " << setw(width) << left << n_passTwoMuSig     << setw(width) << left << (float) n_passTwoMuSig    / (float) n_tot << std::endl;   
 std::cout<<" n_passOneEleDY     " << setw(width) << left << n_passOneEleDY     << setw(width) << left << (float) n_passOneEleDY    / (float) n_tot << std::endl;   
 std::cout<<" n_passTwoEleDY     " << setw(width) << left << n_passTwoEleDY     << setw(width) << left << (float) n_passTwoEleDY    / (float) n_tot << std::endl;   
 std::cout<<" n_passOneMuDY      " << setw(width) << left << n_passOneMuDY      << setw(width) << left << (float) n_passOneMuDY     / (float) n_tot << std::endl;   
 std::cout<<" n_passTwoMuDY      " << setw(width) << left << n_passTwoMuDY      << setw(width) << left << (float) n_passTwoMuDY     / (float) n_tot << std::endl;   
 std::cout<<" n_passOneEleZH     " << setw(width) << left << n_passOneEleZH     << setw(width) << left << (float) n_passOneEleZH    / (float) n_tot << std::endl;   
 std::cout<<" n_passTwoEleZH     " << setw(width) << left << n_passTwoEleZH     << setw(width) << left << (float) n_passTwoEleZH    / (float) n_tot << std::endl;   
 std::cout<<" n_passOneMuZH      " << setw(width) << left << n_passOneMuZH      << setw(width) << left << (float) n_passOneMuZH     / (float) n_tot << std::endl;   
 std::cout<<" n_passTwoMuZH      " << setw(width) << left << n_passTwoMuZH      << setw(width) << left << (float) n_passTwoMuZH     / (float) n_tot << std::endl;   
 std::cout<<" n_passOneEleOffZ   " << setw(width) << left << n_passOneEleOffZ   << setw(width) << left << (float) n_passOneEleOffZ  / (float) n_tot << std::endl;   
 std::cout<<" n_passTwoEleOffZ   " << setw(width) << left << n_passTwoEleOffZ   << setw(width) << left << (float) n_passTwoEleOffZ  / (float) n_tot << std::endl;   
 std::cout<<" n_passOneMuOffZ    " << setw(width) << left << n_passOneMuOffZ    << setw(width) << left << (float) n_passOneMuOffZ   / (float) n_tot << std::endl;   
 std::cout<<" n_passTwoMuOffZ    " << setw(width) << left << n_passTwoMuOffZ    << setw(width) << left << (float) n_passTwoMuOffZ   / (float) n_tot << std::endl;   
 std::cout<<" n_passOneEleNoPair " << setw(width) << left << n_passOneEleNoPair << setw(width) << left << (float) n_passOneEleNoPair/ (float) n_tot << std::endl;   
 std::cout<<" n_passOneMuNoPair  " << setw(width) << left << n_passOneMuNoPair  << setw(width) << left << (float) n_passOneMuNoPair / (float) n_tot << std::endl;   
 std::cout<<" n_passEleMuOSOF    " << setw(width) << left << n_passEleMuOSOF    << setw(width) << left << (float) n_passEleMuOSOF   / (float) n_tot << std::endl;   
 std::cout<<" n_passEleMuOSOFL   " << setw(width) << left << n_passEleMuOSOFL   << setw(width) << left << (float) n_passEleMuOSOFL  / (float) n_tot << std::endl;   
 std::cout<<std::endl;

 std::cout<<" Jet Matching "<<std::endl;
 std::cout<<"  n_totalCalo        "<< n_totalCalo        <<std::endl;
 std::cout<<std::endl<<std::endl;

 TFile *outfile_GEW = 0;
 outfile_GEW = TFile::Open(outfilename+"_AODGenEventWeight.root","RECREATE");
 outfile_GEW->cd();
 h_sum_AODGenEventWeight->Write();
 h_sum_AODGenEventWeight->Delete();
 outfile_GEW->Close();
 
// outfile_nPU->cd();
// h_sum_AOD0thnPU->Write();
// h_sum_AOD0thnPU->Delete();
// outfile_nPU->Close();
 
 if( uncbin.EqualTo("") ){
  optfile->cd();
  OPTtree->CloneTree()->Write();
  optfile->Close();
 }


 // make outfile and save histograms
 // write the histograms
 for(unsigned int i=0; i<selbinnames.size(); ++i){
  if(i==1 || i==3 || i==5 || i==7 || i==9 || i==11 || i==13 || i==15 || i==18 || i==19 ){
    //Normalize variable binned histograms by bin width
    //Could put this in its own loop for clarity
    //scaleVariableBinHistograms( i ); //broken
    
    writeSelectedHistograms( i );
    writeCutflowHistograms( i );

    //jet
    if(jetMultOn){
    for( unsigned int k=0; k<jetmultnames.size(); ++k){
      writeSelectedJetHistograms( i, k );
    } }
    else{
    writeSelectedJetHistograms( i, (jetmultnames.size()-1));
    }

    //tag
    for( unsigned int k=0; k<tagmultnames.size(); ++k){
      writeSelectedTagHistograms( i, k );
    }
  } 
 } // if i== one of the phase spaces we want to write
} // end analyzer_loop::Loop()

