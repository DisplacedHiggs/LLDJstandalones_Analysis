#ifndef analyzer_base_h
#define analyzer_base_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TH1F.h>
#include <TH2F.h>

#include <iostream>  /* cout */

#include <stdlib.h>  /* getenv */

#include "vector"

//#include "DataFormats/Math/interface/deltaR.h"

class analyzer_base {
public :
   TChain          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // global variables
   Bool_t makelog;
   Bool_t isMC;
   FILE * logfile;
   FILE * edmfile;
   Float_t event_weight;
   Float_t w_eleID, w_muonID, w_muonISO, w_LeptonSF, w_Lumi, w_PU, w_GenEvent, w_other, w_tot = 1.;
   Float_t PUweight_DoubleEG;
   Float_t PUweight_DoubleMu;
   Float_t PUweight_MuonEG;
   Float_t PUweight_SinglePhoton;
   Float_t fullweight;

   //\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\//
   // MC and Data
   //\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\//
   // Declaration of leaf types
   Int_t           run;
   Long64_t        event;
   Int_t           lumis;
   Bool_t          isData;
   Int_t           AODnTruePU;
   Int_t           AODnVtx;
   Int_t           AODnGoodVtx;
   Int_t           AODnTrksPV;
   Bool_t          AODisPVGood;
   Float_t         ctauEventWeight;
   Float_t         AODGenEventWeight;
   ULong64_t       AOD_HLT_DoubleEle33;
   ULong64_t       AOD_HLT_Ele23Ele12;
   ULong64_t       AOD_HLT_Ele23Ele12_noDZ;
   ULong64_t       AOD_HLT_Mu17Mu8;
   ULong64_t       AOD_HLT_Mu17Mu8_Mass8;
   ULong64_t       AOD_HLT_Mu17Mu8_Mass3p8;
   ULong64_t       AOD_HLT_Mu17Mu8_noDZ;
   ULong64_t       AOD_HLT_Mu8Ele23_DZ;
   ULong64_t       AOD_HLT_Mu8Ele23_noDZ;
   ULong64_t       AOD_HLT_Mu23Ele12_DZ;
   ULong64_t       AOD_HLT_Mu23Ele12_noDZ;
   ULong64_t       AOD_HLT_Mu12Ele23_DZ;
   ULong64_t       AOD_HLT_Mu12Ele23_noDZ;
   ULong64_t       AOD_HLT_DoubleEle33_isPS;
   ULong64_t       AOD_HLT_Ele23Ele12_isPS;
   ULong64_t       AOD_HLT_Ele23Ele12_noDZ_isPS;
   ULong64_t       AOD_HLT_Mu17Mu8_isPS;
   ULong64_t       AOD_HLT_Mu17Mu8_Mass8_isPS;
   ULong64_t       AOD_HLT_Mu17Mu8_Mass3p8_isPS;
   ULong64_t       AOD_HLT_Mu17Mu8_noDZ_isPS;
   ULong64_t       AOD_HLT_Mu8Ele23_DZ_isPS;
   ULong64_t       AOD_HLT_Mu8Ele23_noDZ_isPS;
   ULong64_t       AOD_HLT_Mu23Ele12_DZ_isPS;
   ULong64_t       AOD_HLT_Mu23Ele12_noDZ_isPS;
   ULong64_t       AOD_HLT_Mu12Ele23_DZ_isPS;
   ULong64_t       AOD_HLT_Mu12Ele23_noDZ_isPS;
   Int_t           AODnCaloJet;
   std::vector<float>   *AODCaloJetPt;
   std::vector<float>   *AODCaloJetPt_JECUp;
   std::vector<float>   *AODCaloJetPt_JECDown;
   std::vector<float>   *AODCaloJetEta;
   std::vector<float>   *AODCaloJetPhi;
   std::vector<float>   *AODCaloJetAlphaMax;
   std::vector<float>   *AODCaloJetAlphaMax2;
   std::vector<float>   *AODCaloJetAlphaMaxPrime;
   std::vector<float>   *AODCaloJetAlphaMaxPrime2;
   std::vector<float>   *AODCaloJetBeta;
   std::vector<float>   *AODCaloJetBeta2;
   std::vector<float>   *AODCaloJetSumIP;
   std::vector<float>   *AODCaloJetSumIPSig;
   std::vector<float>   *AODCaloJetMedianIP;
   std::vector<float>   *AODCaloJetMedianLog10IPSig;
   std::vector<float>   *AODCaloJetTrackAngle;
   std::vector<float>   *AODCaloJetLogTrackAngle;
   std::vector<float>   *AODCaloJetMedianLog10TrackAngle;
   std::vector<float>   *AODCaloJetTotalTrackAngle;
   std::vector<float>   *AODCaloJetAvfVx;
   std::vector<float>   *AODCaloJetAvfVy;
   std::vector<float>   *AODCaloJetAvfVz;
   std::vector<float>   *AODCaloJetAvfVertexTotalChiSquared;
   std::vector<float>   *AODCaloJetAvfVertexDegreesOfFreedom;
   std::vector<float>   *AODCaloJetAvfVertexChi2NDoF;
   std::vector<float>   *AODCaloJetAvfVertexDistanceToBeam;
   std::vector<float>   *AODCaloJetAvfVertexTransverseError;
   std::vector<float>   *AODCaloJetAvfVertexTransverseSig;
   std::vector<float>   *AODCaloJetAvfVertexDeltaEta;
   std::vector<float>   *AODCaloJetAvfVertexDeltaPhi;
   std::vector<float>   *AODCaloJetAvfVertexRecoilPt;
   std::vector<float>   *AODCaloJetAvfVertexTrackMass;
   std::vector<float>   *AODCaloJetAvfVertexTrackEnergy;
   std::vector<float>   *AODCaloJetAvfBeamSpotDeltaPhi;
   std::vector<float>   *AODCaloJetAvfBeamSpotRecoilPt;
   std::vector<float>   *AODCaloJetAvfBeamSpotMedianDeltaPhi;
   std::vector<float>   *AODCaloJetAvfBeamSpotLog10MedianDeltaPhi;
   std::vector<int>     *AODCaloJetNCleanMatchedTracks;
   std::vector<int>     *AODCaloJetNMatchedTracks;
   std::vector<int>     *AODCaloJetSumHitsInFrontOfVert;
   std::vector<int>     *AODCaloJetSumMissHitsAfterVert;
   std::vector<int>     *AODCaloJetHitsInFrontOfVertPerTrack;
   std::vector<int>     *AODCaloJetMissHitsAfterVertPerTrack;
   std::vector<float>   *AODCaloJetAvfDistToPV;
   std::vector<float>   *AODCaloJetAvfVertexDeltaZtoPV;
   std::vector<float>   *AODCaloJetAvfVertexDeltaZtoPV2;
   Int_t           nAODMu;
   std::vector<float>   *AOD_muPt;
   std::vector<float>   *AOD_muEn;
   std::vector<float>   *AOD_muEta;
   std::vector<float>   *AOD_muPhi;
   std::vector<int>     *AOD_muCharge;
   std::vector<int>     *AOD_muType;
   std::vector<bool>    *AOD_muIsGlobalMuon;
   std::vector<bool>    *AOD_muIsPFMuon;
   std::vector<bool>    *AOD_muPassLooseID;
   std::vector<bool>    *AOD_muPassMediumBCDEFID;
   std::vector<bool>    *AOD_muPassMediumGHID;
   std::vector<bool>    *AOD_muPassTightID;
   std::vector<float>   *AOD_muPFdBetaIsolation;
   std::vector<float>   *AOD_muDxy;
   std::vector<float>   *AOD_muDxyErr;
   std::vector<float>   *AOD_muDB_BS2D;
   std::vector<float>   *AOD_muDB_PV2D;
   Int_t           nAODPho;
   std::vector<float>   *AOD_phoPt;
   std::vector<float>   *AOD_phoEn;
   std::vector<float>   *AOD_phoEta;
   std::vector<float>   *AOD_phoPhi;
   std::vector<float>   *AOD_phoSCEn;
   std::vector<float>   *AOD_phoSCEta;
   std::vector<float>   *AOD_phoSCPhi;
   Int_t           nAODEle;
   std::vector<float>   *AOD_elePt;
   std::vector<float>   *AOD_eleEn;
   std::vector<float>   *AOD_eleEta;
   std::vector<float>   *AOD_elePhi;
   std::vector<float>   *AOD_eled0;
   std::vector<float>   *AOD_eledz;
   std::vector<int>     *AOD_eleCharge;
   std::vector<int>     *AOD_eleChargeConsistent;
   std::vector<unsigned short> *AOD_eleIDbit;
   std::vector<int>     *AOD_elePassConversionVeto;
   Float_t         AOD_CaloMET_pt;
   Float_t         AOD_CaloMET_phi;

   // List of branches
   TBranch        *b_run;   //!
   TBranch        *b_event;   //!
   TBranch        *b_lumis;   //!
   TBranch        *b_isData;   //!
   TBranch        *b_AODnTruePU;   //!
   TBranch        *b_AODnVtx;   //!
   TBranch        *b_AODnGoodVtx;   //!
   TBranch        *b_AODnTrksPV;   //!
   TBranch        *b_AODisPVGood;   //!
   TBranch        *b_ctauEventWeight;   //!
   TBranch        *b_AODGenEventWeight;   //!
   TBranch        *b_AOD_HLT_DoubleEle33;   //!
   TBranch        *b_AOD_HLT_Ele23Ele12;   //!
   TBranch        *b_AOD_HLT_Ele23Ele12_noDZ;   //!
   TBranch        *b_AOD_HLT_Mu17Mu8;   //!
   TBranch        *b_AOD_HLT_Mu17Mu8_Mass8;   //!
   TBranch        *b_AOD_HLT_Mu17Mu8_Mass3p8;   //!
   TBranch        *b_AOD_HLT_Mu17Mu8_noDZ;   //!
   TBranch        *b_AOD_HLT_Mu8Ele23_DZ;   //!
   TBranch        *b_AOD_HLT_Mu8Ele23_noDZ;   //!
   TBranch        *b_AOD_HLT_Mu23Ele12_DZ;   //!
   TBranch        *b_AOD_HLT_Mu23Ele12_noDZ;   //!
   TBranch        *b_AOD_HLT_Mu12Ele23_DZ;   //!
   TBranch        *b_AOD_HLT_Mu12Ele23_noDZ;   //!
   TBranch        *b_AOD_HLT_DoubleEle33_isPS;   //!
   TBranch        *b_AOD_HLT_Ele23Ele12_isPS;   //!
   TBranch        *b_AOD_HLT_Ele23Ele12_noDZ_isPS;   //!
   TBranch        *b_AOD_HLT_Mu17Mu8_isPS;   //!
   TBranch        *b_AOD_HLT_Mu17Mu8_Mass8_isPS;   //!
   TBranch        *b_AOD_HLT_Mu17Mu8_Mass3p8_isPS;   //!
   TBranch        *b_AOD_HLT_Mu17Mu8_noDZ_isPS;   //!
   TBranch        *b_AOD_HLT_Mu8Ele23_DZ_isPS;   //!
   TBranch        *b_AOD_HLT_Mu8Ele23_noDZ_isPS;   //!
   TBranch        *b_AOD_HLT_Mu23Ele12_DZ_isPS;   //!
   TBranch        *b_AOD_HLT_Mu23Ele12_noDZ_isPS;   //!
   TBranch        *b_AOD_HLT_Mu12Ele23_DZ_isPS;   //!
   TBranch        *b_AOD_HLT_Mu12Ele23_noDZ_isPS;   //!
   TBranch        *b_AODnCaloJet;   //!
   TBranch        *b_AODCaloJetPt;   //!
   TBranch        *b_AODCaloJetPt_JECUp;   //!
   TBranch        *b_AODCaloJetPt_JECDown;   //!
   TBranch        *b_AODCaloJetEta;   //!
   TBranch        *b_AODCaloJetPhi;   //!
   TBranch        *b_AODCaloJetAlphaMax;   //!
   TBranch        *b_AODCaloJetAlphaMax2;   //!
   TBranch        *b_AODCaloJetAlphaMaxPrime;   //!
   TBranch        *b_AODCaloJetAlphaMaxPrime2;   //!
   TBranch        *b_AODCaloJetBeta;   //!
   TBranch        *b_AODCaloJetBeta2;   //!
   TBranch        *b_AODCaloJetSumIP;   //!
   TBranch        *b_AODCaloJetSumIPSig;   //!
   TBranch        *b_AODCaloJetMedianIP;   //!
   TBranch        *b_AODCaloJetMedianLog10IPSig;   //!
   TBranch        *b_AODCaloJetTrackAngle;   //!
   TBranch        *b_AODCaloJetLogTrackAngle;   //!
   TBranch        *b_AODCaloJetMedianLog10TrackAngle;   //!
   TBranch        *b_AODCaloJetTotalTrackAngle;   //!
   TBranch        *b_AODCaloJetAvfVx;   //!
   TBranch        *b_AODCaloJetAvfVy;   //!
   TBranch        *b_AODCaloJetAvfVz;   //!
   TBranch        *b_AODCaloJetAvfVertexTotalChiSquared;   //!
   TBranch        *b_AODCaloJetAvfVertexDegreesOfFreedom;   //!
   TBranch        *b_AODCaloJetAvfVertexChi2NDoF;   //!
   TBranch        *b_AODCaloJetAvfVertexDistanceToBeam;   //!
   TBranch        *b_AODCaloJetAvfVertexTransverseError;   //!
   TBranch        *b_AODCaloJetAvfVertexTransverseSig;   //!
   TBranch        *b_AODCaloJetAvfVertexDeltaEta;   //!
   TBranch        *b_AODCaloJetAvfVertexDeltaPhi;   //!
   TBranch        *b_AODCaloJetAvfVertexRecoilPt;   //!
   TBranch        *b_AODCaloJetAvfVertexTrackMass;   //!
   TBranch        *b_AODCaloJetAvfVertexTrackEnergy;   //!
   TBranch        *b_AODCaloJetAvfBeamSpotDeltaPhi;   //!
   TBranch        *b_AODCaloJetAvfBeamSpotRecoilPt;   //!
   TBranch        *b_AODCaloJetAvfBeamSpotMedianDeltaPhi;   //!
   TBranch        *b_AODCaloJetAvfBeamSpotLog10MedianDeltaPhi;   //!
   TBranch        *b_AODCaloJetNCleanMatchedTracks;   //!
   TBranch        *b_AODCaloJetNMatchedTracks;   //!
   TBranch        *b_AODCaloJetSumHitsInFrontOfVert;   //!
   TBranch        *b_AODCaloJetSumMissHitsAfterVert;   //!
   TBranch        *b_AODCaloJetHitsInFrontOfVertPerTrack;   //!
   TBranch        *b_AODCaloJetMissHitsAfterVertPerTrack;   //!
   TBranch        *b_AODCaloJetAvfDistToPV;   //!
   TBranch        *b_AODCaloJetAvfVertexDeltaZtoPV;   //!
   TBranch        *b_AODCaloJetAvfVertexDeltaZtoPV2;   //!
   TBranch        *b_nAODMu;   //!
   TBranch        *b_AOD_muPt;   //!
   TBranch        *b_AOD_muEn;   //!
   TBranch        *b_AOD_muEta;   //!
   TBranch        *b_AOD_muPhi;   //!
   TBranch        *b_AOD_muCharge;   //!
   TBranch        *b_AOD_muType;   //!
   TBranch        *b_AOD_muIsGlobalMuon;   //!
   TBranch        *b_AOD_muIsPFMuon;   //!
   TBranch        *b_AOD_muPassLooseID;   //!
   TBranch        *b_AOD_muPassMediumBCDEFID;   //!
   TBranch        *b_AOD_muPassMediumGHID;   //!
   TBranch        *b_AOD_muPassTightID;   //!
   TBranch        *b_AOD_muPFdBetaIsolation;   //!
   TBranch        *b_AOD_muDxy;   //!
   TBranch        *b_AOD_muDxyErr;   //!
   TBranch        *b_AOD_muDB_BS2D;   //!
   TBranch        *b_AOD_muDB_PV2D;   //!
   TBranch        *b_nAODPho;   //!
   TBranch        *b_AOD_phoPt;   //!
   TBranch        *b_AOD_phoEn;   //!
   TBranch        *b_AOD_phoEta;   //!
   TBranch        *b_AOD_phoPhi;   //!
   TBranch        *b_AOD_phoSCEn;   //!
   TBranch        *b_AOD_phoSCEta;   //!
   TBranch        *b_AOD_phoSCPhi;   //!
   TBranch        *b_nAODEle;   //!
   TBranch        *b_AOD_elePt;   //!
   TBranch        *b_AOD_eleEn;   //!
   TBranch        *b_AOD_eleEta;   //!
   TBranch        *b_AOD_elePhi;   //!
   TBranch        *b_AOD_eled0;   //!
   TBranch        *b_AOD_eledz;   //!
   TBranch        *b_AOD_eleCharge;   //!
   TBranch        *b_AOD_eleChargeConsistent;   //!
   TBranch        *b_AOD_eleIDbit;   //!
   TBranch        *b_AOD_elePassConversionVeto;   //!
   TBranch        *b_AOD_CaloMET_pt;   //!
   TBranch        *b_AOD_CaloMET_phi;   //!


   //analyzer_base(TTree *tree=0);
   analyzer_base();
   virtual ~analyzer_base();
   virtual void     Init(TChain *tree, Bool_t isitMC, Bool_t domakelog, TString Tsample);
   virtual Long64_t LoadTree(Long64_t entry);
   
};

#endif
