//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Jan  8 15:24:19 2020 by ROOT version 6.12/07
// from TTree EventTree/Event data
// found on file: lldjntuple_mc_AOD.root
//////////////////////////////////////////////////////////

#ifndef SampleSplit_h
#define SampleSplit_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <map>

// Header file for the classes stored in the TTree if any.
#include "TString.h"
#include "vector"
#include <vector>

class SampleSplit {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain
   TString         SampleName;
// Fixed size dimensions of array or collections stored in the TTree if any.
   
   // Declaration of leaf types
   Int_t           run;
   Long64_t        event;
   Int_t           lumis;
   Bool_t          isData;
   Int_t           AODnTruePU;
   Int_t           AOD0thnPU;
   Int_t           AODnVtx;
   Int_t           AODnGoodVtx;
   Int_t           AODnTrksPV;
   Bool_t          AODisPVGood;
   Float_t         AODGenEventWeight;
   Float_t         AODfixedGridRhoFastjetAll;
   Int_t           AODnBunchXing;
   std::vector<int>     *AODBunchXing;
   std::vector<int>     *AODnPU;
   std::vector<float>   *AODnPUmean;
   TString         *model;
   std::vector<int>     *llpId;
   std::vector<int>     *llpStatus;
   std::vector<float>   *llpPt;
   std::vector<float>   *llpEta;
   std::vector<float>   *llpPhi;
   std::vector<float>   *llpMass;
   std::vector<int>     *llpDaughterId;
   std::vector<int>     *llpDaughterStatus;
   std::vector<float>   *llpDaughterPt;
   std::vector<float>   *llpDaughterEta;
   std::vector<float>   *llpDaughterPhi;
   std::vector<float>   *llpDaughterMass;
   std::vector<float>   *toppts;
   Float_t         gen_Z_mass;
   Float_t         gen_Z_energy;
   Float_t         gen_Z_pt;
   Float_t         gen_Z_eta;
   Float_t         gen_Z_phi;
   Float_t         gen_Z_dauther1_Id;
   Float_t         gen_Z_dauther2_Id;
   std::vector<float>   *gen_lep_energy;
   std::vector<float>   *gen_lep_pt;
   std::vector<float>   *gen_lep_eta;
   std::vector<float>   *gen_lep_phi;
   std::vector<int>     *gen_lep_Id;
   std::vector<int>     *gen_lep_momId;
   std::vector<float>   *llpvX;
   std::vector<float>   *llpvY;
   std::vector<float>   *llpvZ;
   std::vector<float>   *llpDaughtervX;
   std::vector<float>   *llpDaughtervY;
   std::vector<float>   *llpDaughtervZ;
   ULong64_t       AOD_HLT_DoubleEle33;
   ULong64_t       AOD_HLT_Ele23Ele12;
   ULong64_t       AOD_HLT_Ele23Ele12_noDZ;
   ULong64_t       AOD_HLT_Mu17Mu8;
   ULong64_t       AOD_HLT_Mu17Mu8_Mass8;
   ULong64_t       AOD_HLT_Mu17Mu8_Mass3p8;
   ULong64_t       AOD_HLT_Mu17TkMu8;
   ULong64_t       AOD_HLT_TkMu17TkMu8;
   ULong64_t       AOD_HLT_Mu17Mu8_noDZ;
   ULong64_t       AOD_HLT_Mu17TkMu8_noDZ;
   ULong64_t       AOD_HLT_TkMu17TkMu8_noDZ;
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
   ULong64_t       AOD_HLT_Mu17TkMu8_isPS;
   ULong64_t       AOD_HLT_TkMu17TkMu8_isPS;
   ULong64_t       AOD_HLT_Mu17Mu8_noDZ_isPS;
   ULong64_t       AOD_HLT_Mu17TkMu8_noDZ_isPS;
   ULong64_t       AOD_HLT_TkMu17TkMu8_noDZ_isPS;
   ULong64_t       AOD_HLT_Mu8Ele23_DZ_isPS;
   ULong64_t       AOD_HLT_Mu8Ele23_noDZ_isPS;
   ULong64_t       AOD_HLT_Mu23Ele12_DZ_isPS;
   ULong64_t       AOD_HLT_Mu23Ele12_noDZ_isPS;
   ULong64_t       AOD_HLT_Mu12Ele23_DZ_isPS;
   ULong64_t       AOD_HLT_Mu12Ele23_noDZ_isPS;
   Int_t           AODnCaloJet;
   std::vector<float>   *AODCaloJetEnergy;
   std::vector<float>   *AODCaloJetPt;
   std::vector<float>   *AODCaloJetEnergyUncorrected;
   std::vector<float>   *AODCaloJetPtUncorrected;
   std::vector<float>   *AODCaloJetPt_JECUp;
   std::vector<float>   *AODCaloJetPt_JECDown;
   std::vector<float>   *AODCaloJetEta;
   std::vector<float>   *AODCaloJetPhi;
   std::vector<bool>    *AODCaloJetID;
   std::vector<float>   *AODCaloJet_emEnergyFraction;
   std::vector<float>   *AODCaloJet_energyFractionHadronic;
   std::vector<float>   *AODCaloJetMass;
   std::vector<float>   *AODCaloJetArea;
   std::vector<float>   *AODCaloJetPileup;
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
   TBranch        *b_AOD0thnPU;   //!
   TBranch        *b_AODnVtx;   //!
   TBranch        *b_AODnGoodVtx;   //!
   TBranch        *b_AODnTrksPV;   //!
   TBranch        *b_AODisPVGood;   //!
   TBranch        *b_AODGenEventWeight;   //!
   TBranch        *b_AODfixedGridRhoFastjetAll;   //!
   TBranch        *b_AODnBunchXing;   //!
   TBranch        *b_AODBunchXing;   //!
   TBranch        *b_AODnPU;   //!
   TBranch        *b_AODnPUmean;   //!
   TBranch        *b_model;   //!
   TBranch        *b_llpId;   //!
   TBranch        *b_llpStatus;   //!
   TBranch        *b_llpPt;   //!
   TBranch        *b_llpEta;   //!
   TBranch        *b_llpPhi;   //!
   TBranch        *b_llpMass;   //!
   TBranch        *b_llpDaughterId;   //!
   TBranch        *b_llpDaughterStatus;   //!
   TBranch        *b_llpDaughterPt;   //!
   TBranch        *b_llpDaughterEta;   //!
   TBranch        *b_llpDaughterPhi;   //!
   TBranch        *b_llpDaughterMass;   //!
   TBranch        *b_toppts;   //!
   TBranch        *b_gen_Z_mass;   //!
   TBranch        *b_gen_Z_energy;   //!
   TBranch        *b_gen_Z_pt;   //!
   TBranch        *b_gen_Z_eta;   //!
   TBranch        *b_gen_Z_phi;   //!
   TBranch        *b_gen_Z_dauther1_Id;   //!
   TBranch        *b_gen_Z_dauther2_Id;   //!
   TBranch        *b_gen_lep_energy;   //!
   TBranch        *b_gen_lep_pt;   //!
   TBranch        *b_gen_lep_eta;   //!
   TBranch        *b_gen_lep_phi;   //!
   TBranch        *b_gen_lep_Id;   //!
   TBranch        *b_gen_lep_momId;   //!
   TBranch        *b_llpvX;   //!
   TBranch        *b_llpvY;   //!
   TBranch        *b_llpvZ;   //!
   TBranch        *b_llpDaughtervX;   //!
   TBranch        *b_llpDaughtervY;   //!
   TBranch        *b_llpDaughtervZ;   //!
   TBranch        *b_AOD_HLT_DoubleEle33;   //!
   TBranch        *b_AOD_HLT_Ele23Ele12;   //!
   TBranch        *b_AOD_HLT_Ele23Ele12_noDZ;   //!
   TBranch        *b_AOD_HLT_Mu17Mu8;   //!
   TBranch        *b_AOD_HLT_Mu17Mu8_Mass8;   //!
   TBranch        *b_AOD_HLT_Mu17Mu8_Mass3p8;   //!
   TBranch        *b_AOD_HLT_Mu17TkMu8;   //!
   TBranch        *b_AOD_HLT_TkMu17TkMu8;   //!
   TBranch        *b_AOD_HLT_Mu17Mu8_noDZ;   //!
   TBranch        *b_AOD_HLT_Mu17TkMu8_noDZ;   //!
   TBranch        *b_AOD_HLT_TkMu17TkMu8_noDZ;   //!
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
   TBranch        *b_AOD_HLT_Mu17TkMu8_isPS;   //!
   TBranch        *b_AOD_HLT_TkMu17TkMu8_isPS;   //!
   TBranch        *b_AOD_HLT_Mu17Mu8_noDZ_isPS;   //!
   TBranch        *b_AOD_HLT_Mu17TkMu8_noDZ_isPS;   //!
   TBranch        *b_AOD_HLT_TkMu17TkMu8_noDZ_isPS;   //!
   TBranch        *b_AOD_HLT_Mu8Ele23_DZ_isPS;   //!
   TBranch        *b_AOD_HLT_Mu8Ele23_noDZ_isPS;   //!
   TBranch        *b_AOD_HLT_Mu23Ele12_DZ_isPS;   //!
   TBranch        *b_AOD_HLT_Mu23Ele12_noDZ_isPS;   //!
   TBranch        *b_AOD_HLT_Mu12Ele23_DZ_isPS;   //!
   TBranch        *b_AOD_HLT_Mu12Ele23_noDZ_isPS;   //!
   TBranch        *b_AODnCaloJet;   //!
   TBranch        *b_AODCaloJetEnergy;   //!
   TBranch        *b_AODCaloJetPt;   //!
   TBranch        *b_AODCaloJetEnergyUncorrected;   //!
   TBranch        *b_AODCaloJetPtUncorrected;   //!
   TBranch        *b_AODCaloJetPt_JECUp;   //!
   TBranch        *b_AODCaloJetPt_JECDown;   //!
   TBranch        *b_AODCaloJetEta;   //!
   TBranch        *b_AODCaloJetPhi;   //!
   TBranch        *b_AODCaloJetID;   //!
   TBranch        *b_AODCaloJet_emEnergyFraction;   //!
   TBranch        *b_AODCaloJet_energyFractionHadronic;   //!
   TBranch        *b_AODCaloJetMass;   //!
   TBranch        *b_AODCaloJetArea;   //!
   TBranch        *b_AODCaloJetPileup;   //!
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


   SampleSplit(TTree *tree=0);
   virtual ~SampleSplit();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef SampleSplit_cxx
SampleSplit::SampleSplit(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   //TString Path="root://cmsxrootd.fnal.gov///store/group/lpchbb/LLDJntuples/2017lldj_NoJEC/ZH_HToSSTobbbb_ZToLL_MH-125_TuneCP5_13TeV-powheg-pythia8/crab_ZH_Sig/200120_175234/0000/";
   TString Path="/eos/uscms/store/group/lpchbb/LLDJntuples/2017lldj_NoJEC/ZH_HToSSTobbbb_ZToLL_MH-125_TuneCP5_13TeV-powheg-pythia8/crab_ZH_Sig/200120_175234/0000/";
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject(Path+"lldjntuple_mc_AOD_1-10.root");
      if (!f || !f->IsOpen()) {
         f = new TFile(Path+"lldjntuple_mc_AOD_1-10.root");
      }
      TDirectory * dir = (TDirectory*)f->Get(Path+"lldjntuple_mc_AOD_1-10.root:/lldjNtuple");
      dir->GetObject("EventTree",tree);

   }
//// if parameter tree is not specified (or zero), connect the file
//// used to generate this class and read the Tree.
//   if (tree == 0) {
//      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("lldjntuple_mc_AOD.root");
//      if (!f || !f->IsOpen()) {
//         f = new TFile("lldjntuple_mc_AOD.root");
//      }
//      TDirectory * dir = (TDirectory*)f->Get("lldjntuple_mc_AOD.root:/lldjNtuple");
//      dir->GetObject("EventTree",tree);
//
//   }
   Init(tree);
}

SampleSplit::~SampleSplit()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t SampleSplit::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t SampleSplit::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void SampleSplit::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).
   

   // Set object pointer
   AODBunchXing = 0;
   AODnPU = 0;
   AODnPUmean = 0;
   model = 0;
   llpId = 0;
   llpStatus = 0;
   llpPt = 0;
   llpEta = 0;
   llpPhi = 0;
   llpMass = 0;
   llpDaughterId = 0;
   llpDaughterStatus = 0;
   llpDaughterPt = 0;
   llpDaughterEta = 0;
   llpDaughterPhi = 0;
   llpDaughterMass = 0;
   toppts = 0;
   gen_lep_energy = 0;
   gen_lep_pt = 0;
   gen_lep_eta = 0;
   gen_lep_phi = 0;
   gen_lep_Id = 0;
   gen_lep_momId = 0;
   llpvX = 0;
   llpvY = 0;
   llpvZ = 0;
   llpDaughtervX = 0;
   llpDaughtervY = 0;
   llpDaughtervZ = 0;
   AODCaloJetEnergy = 0;
   AODCaloJetPt = 0;
   AODCaloJetEnergyUncorrected = 0;
   AODCaloJetPtUncorrected = 0;
   AODCaloJetPt_JECUp = 0;
   AODCaloJetPt_JECDown = 0;
   AODCaloJetEta = 0;
   AODCaloJetPhi = 0;
   AODCaloJetID = 0;
   AODCaloJet_emEnergyFraction = 0;
   AODCaloJet_energyFractionHadronic = 0;
   AODCaloJetMass = 0;
   AODCaloJetArea = 0;
   AODCaloJetPileup = 0;
   AODCaloJetAlphaMax = 0;
   AODCaloJetAlphaMax2 = 0;
   AODCaloJetAlphaMaxPrime = 0;
   AODCaloJetAlphaMaxPrime2 = 0;
   AODCaloJetBeta = 0;
   AODCaloJetBeta2 = 0;
   AODCaloJetSumIP = 0;
   AODCaloJetSumIPSig = 0;
   AODCaloJetMedianIP = 0;
   AODCaloJetMedianLog10IPSig = 0;
   AODCaloJetTrackAngle = 0;
   AODCaloJetLogTrackAngle = 0;
   AODCaloJetMedianLog10TrackAngle = 0;
   AODCaloJetTotalTrackAngle = 0;
   AODCaloJetAvfVx = 0;
   AODCaloJetAvfVy = 0;
   AODCaloJetAvfVz = 0;
   AODCaloJetAvfVertexTotalChiSquared = 0;
   AODCaloJetAvfVertexDegreesOfFreedom = 0;
   AODCaloJetAvfVertexChi2NDoF = 0;
   AODCaloJetAvfVertexDistanceToBeam = 0;
   AODCaloJetAvfVertexTransverseError = 0;
   AODCaloJetAvfVertexTransverseSig = 0;
   AODCaloJetAvfVertexDeltaEta = 0;
   AODCaloJetAvfVertexDeltaPhi = 0;
   AODCaloJetAvfVertexRecoilPt = 0;
   AODCaloJetAvfVertexTrackMass = 0;
   AODCaloJetAvfVertexTrackEnergy = 0;
   AODCaloJetAvfBeamSpotDeltaPhi = 0;
   AODCaloJetAvfBeamSpotRecoilPt = 0;
   AODCaloJetAvfBeamSpotMedianDeltaPhi = 0;
   AODCaloJetAvfBeamSpotLog10MedianDeltaPhi = 0;
   AODCaloJetNCleanMatchedTracks = 0;
   AODCaloJetNMatchedTracks = 0;
   AODCaloJetSumHitsInFrontOfVert = 0;
   AODCaloJetSumMissHitsAfterVert = 0;
   AODCaloJetHitsInFrontOfVertPerTrack = 0;
   AODCaloJetMissHitsAfterVertPerTrack = 0;
   AODCaloJetAvfDistToPV = 0;
   AODCaloJetAvfVertexDeltaZtoPV = 0;
   AODCaloJetAvfVertexDeltaZtoPV2 = 0;
   AOD_muPt = 0;
   AOD_muEn = 0;
   AOD_muEta = 0;
   AOD_muPhi = 0;
   AOD_muCharge = 0;
   AOD_muType = 0;
   AOD_muIsGlobalMuon = 0;
   AOD_muIsPFMuon = 0;
   AOD_muPassLooseID = 0;
   AOD_muPassMediumBCDEFID = 0;
   AOD_muPassMediumGHID = 0;
   AOD_muPassTightID = 0;
   AOD_muPFdBetaIsolation = 0;
   AOD_muDxy = 0;
   AOD_muDxyErr = 0;
   AOD_muDB_BS2D = 0;
   AOD_muDB_PV2D = 0;
   AOD_phoPt = 0;
   AOD_phoEn = 0;
   AOD_phoEta = 0;
   AOD_phoPhi = 0;
   AOD_phoSCEn = 0;
   AOD_phoSCEta = 0;
   AOD_phoSCPhi = 0;
   AOD_elePt = 0;
   AOD_eleEn = 0;
   AOD_eleEta = 0;
   AOD_elePhi = 0;
   AOD_eled0 = 0;
   AOD_eledz = 0;
   AOD_eleCharge = 0;
   AOD_eleChargeConsistent = 0;
   AOD_eleIDbit = 0;
   AOD_elePassConversionVeto = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("event", &event, &b_event);
   fChain->SetBranchAddress("lumis", &lumis, &b_lumis);
   fChain->SetBranchAddress("isData", &isData, &b_isData);
   fChain->SetBranchAddress("AODnTruePU", &AODnTruePU, &b_AODnTruePU);
   fChain->SetBranchAddress("AOD0thnPU", &AOD0thnPU, &b_AOD0thnPU);
   fChain->SetBranchAddress("AODnVtx", &AODnVtx, &b_AODnVtx);
   fChain->SetBranchAddress("AODnGoodVtx", &AODnGoodVtx, &b_AODnGoodVtx);
   fChain->SetBranchAddress("AODnTrksPV", &AODnTrksPV, &b_AODnTrksPV);
   fChain->SetBranchAddress("AODisPVGood", &AODisPVGood, &b_AODisPVGood);
   fChain->SetBranchAddress("AODGenEventWeight", &AODGenEventWeight, &b_AODGenEventWeight);
   fChain->SetBranchAddress("AODfixedGridRhoFastjetAll", &AODfixedGridRhoFastjetAll, &b_AODfixedGridRhoFastjetAll);
   fChain->SetBranchAddress("AODnBunchXing", &AODnBunchXing, &b_AODnBunchXing);
   fChain->SetBranchAddress("AODBunchXing", &AODBunchXing, &b_AODBunchXing);
   fChain->SetBranchAddress("AODnPU", &AODnPU, &b_AODnPU);
   fChain->SetBranchAddress("AODnPUmean", &AODnPUmean, &b_AODnPUmean);
   fChain->SetBranchAddress("model", &model, &b_model);
   fChain->SetBranchAddress("llpId", &llpId, &b_llpId);
   fChain->SetBranchAddress("llpStatus", &llpStatus, &b_llpStatus);
   fChain->SetBranchAddress("llpPt", &llpPt, &b_llpPt);
   fChain->SetBranchAddress("llpEta", &llpEta, &b_llpEta);
   fChain->SetBranchAddress("llpPhi", &llpPhi, &b_llpPhi);
   fChain->SetBranchAddress("llpMass", &llpMass, &b_llpMass);
   fChain->SetBranchAddress("llpDaughterId", &llpDaughterId, &b_llpDaughterId);
   fChain->SetBranchAddress("llpDaughterStatus", &llpDaughterStatus, &b_llpDaughterStatus);
   fChain->SetBranchAddress("llpDaughterPt", &llpDaughterPt, &b_llpDaughterPt);
   fChain->SetBranchAddress("llpDaughterEta", &llpDaughterEta, &b_llpDaughterEta);
   fChain->SetBranchAddress("llpDaughterPhi", &llpDaughterPhi, &b_llpDaughterPhi);
   fChain->SetBranchAddress("llpDaughterMass", &llpDaughterMass, &b_llpDaughterMass);
   fChain->SetBranchAddress("toppts", &toppts, &b_toppts);
   fChain->SetBranchAddress("gen_Z_mass", &gen_Z_mass, &b_gen_Z_mass);
   fChain->SetBranchAddress("gen_Z_energy", &gen_Z_energy, &b_gen_Z_energy);
   fChain->SetBranchAddress("gen_Z_pt", &gen_Z_pt, &b_gen_Z_pt);
   fChain->SetBranchAddress("gen_Z_eta", &gen_Z_eta, &b_gen_Z_eta);
   fChain->SetBranchAddress("gen_Z_phi", &gen_Z_phi, &b_gen_Z_phi);
   fChain->SetBranchAddress("gen_Z_dauther1_Id", &gen_Z_dauther1_Id, &b_gen_Z_dauther1_Id);
   fChain->SetBranchAddress("gen_Z_dauther2_Id", &gen_Z_dauther2_Id, &b_gen_Z_dauther2_Id);
   fChain->SetBranchAddress("gen_lep_energy", &gen_lep_energy, &b_gen_lep_energy);
   fChain->SetBranchAddress("gen_lep_pt", &gen_lep_pt, &b_gen_lep_pt);
   fChain->SetBranchAddress("gen_lep_eta", &gen_lep_eta, &b_gen_lep_eta);
   fChain->SetBranchAddress("gen_lep_phi", &gen_lep_phi, &b_gen_lep_phi);
   fChain->SetBranchAddress("gen_lep_Id", &gen_lep_Id, &b_gen_lep_Id);
   fChain->SetBranchAddress("gen_lep_momId", &gen_lep_momId, &b_gen_lep_momId);
   fChain->SetBranchAddress("llpvX", &llpvX, &b_llpvX);
   fChain->SetBranchAddress("llpvY", &llpvY, &b_llpvY);
   fChain->SetBranchAddress("llpvZ", &llpvZ, &b_llpvZ);
   fChain->SetBranchAddress("llpDaughtervX", &llpDaughtervX, &b_llpDaughtervX);
   fChain->SetBranchAddress("llpDaughtervY", &llpDaughtervY, &b_llpDaughtervY);
   fChain->SetBranchAddress("llpDaughtervZ", &llpDaughtervZ, &b_llpDaughtervZ);
   fChain->SetBranchAddress("AOD_HLT_DoubleEle33", &AOD_HLT_DoubleEle33, &b_AOD_HLT_DoubleEle33);
   fChain->SetBranchAddress("AOD_HLT_Ele23Ele12", &AOD_HLT_Ele23Ele12, &b_AOD_HLT_Ele23Ele12);
   fChain->SetBranchAddress("AOD_HLT_Ele23Ele12_noDZ", &AOD_HLT_Ele23Ele12_noDZ, &b_AOD_HLT_Ele23Ele12_noDZ);
   fChain->SetBranchAddress("AOD_HLT_Mu17Mu8", &AOD_HLT_Mu17Mu8, &b_AOD_HLT_Mu17Mu8);
   fChain->SetBranchAddress("AOD_HLT_Mu17Mu8_Mass8", &AOD_HLT_Mu17Mu8_Mass8, &b_AOD_HLT_Mu17Mu8_Mass8);
   fChain->SetBranchAddress("AOD_HLT_Mu17Mu8_Mass3p8", &AOD_HLT_Mu17Mu8_Mass3p8, &b_AOD_HLT_Mu17Mu8_Mass3p8);
   fChain->SetBranchAddress("AOD_HLT_Mu17TkMu8", &AOD_HLT_Mu17TkMu8, &b_AOD_HLT_Mu17TkMu8);
   fChain->SetBranchAddress("AOD_HLT_TkMu17TkMu8", &AOD_HLT_TkMu17TkMu8, &b_AOD_HLT_TkMu17TkMu8);
   fChain->SetBranchAddress("AOD_HLT_Mu17Mu8_noDZ", &AOD_HLT_Mu17Mu8_noDZ, &b_AOD_HLT_Mu17Mu8_noDZ);
   fChain->SetBranchAddress("AOD_HLT_Mu17TkMu8_noDZ", &AOD_HLT_Mu17TkMu8_noDZ, &b_AOD_HLT_Mu17TkMu8_noDZ);
   fChain->SetBranchAddress("AOD_HLT_TkMu17TkMu8_noDZ", &AOD_HLT_TkMu17TkMu8_noDZ, &b_AOD_HLT_TkMu17TkMu8_noDZ);
   fChain->SetBranchAddress("AOD_HLT_Mu8Ele23_DZ", &AOD_HLT_Mu8Ele23_DZ, &b_AOD_HLT_Mu8Ele23_DZ);
   fChain->SetBranchAddress("AOD_HLT_Mu8Ele23_noDZ", &AOD_HLT_Mu8Ele23_noDZ, &b_AOD_HLT_Mu8Ele23_noDZ);
   fChain->SetBranchAddress("AOD_HLT_Mu23Ele12_DZ", &AOD_HLT_Mu23Ele12_DZ, &b_AOD_HLT_Mu23Ele12_DZ);
   fChain->SetBranchAddress("AOD_HLT_Mu23Ele12_noDZ", &AOD_HLT_Mu23Ele12_noDZ, &b_AOD_HLT_Mu23Ele12_noDZ);
   fChain->SetBranchAddress("AOD_HLT_Mu12Ele23_DZ", &AOD_HLT_Mu12Ele23_DZ, &b_AOD_HLT_Mu12Ele23_DZ);
   fChain->SetBranchAddress("AOD_HLT_Mu12Ele23_noDZ", &AOD_HLT_Mu12Ele23_noDZ, &b_AOD_HLT_Mu12Ele23_noDZ);
   fChain->SetBranchAddress("AOD_HLT_DoubleEle33_isPS", &AOD_HLT_DoubleEle33_isPS, &b_AOD_HLT_DoubleEle33_isPS);
   fChain->SetBranchAddress("AOD_HLT_Ele23Ele12_isPS", &AOD_HLT_Ele23Ele12_isPS, &b_AOD_HLT_Ele23Ele12_isPS);
   fChain->SetBranchAddress("AOD_HLT_Ele23Ele12_noDZ_isPS", &AOD_HLT_Ele23Ele12_noDZ_isPS, &b_AOD_HLT_Ele23Ele12_noDZ_isPS);
   fChain->SetBranchAddress("AOD_HLT_Mu17Mu8_isPS", &AOD_HLT_Mu17Mu8_isPS, &b_AOD_HLT_Mu17Mu8_isPS);
   fChain->SetBranchAddress("AOD_HLT_Mu17Mu8_Mass8_isPS", &AOD_HLT_Mu17Mu8_Mass8_isPS, &b_AOD_HLT_Mu17Mu8_Mass8_isPS);
   fChain->SetBranchAddress("AOD_HLT_Mu17Mu8_Mass3p8_isPS", &AOD_HLT_Mu17Mu8_Mass3p8_isPS, &b_AOD_HLT_Mu17Mu8_Mass3p8_isPS);
   fChain->SetBranchAddress("AOD_HLT_Mu17TkMu8_isPS", &AOD_HLT_Mu17TkMu8_isPS, &b_AOD_HLT_Mu17TkMu8_isPS);
   fChain->SetBranchAddress("AOD_HLT_TkMu17TkMu8_isPS", &AOD_HLT_TkMu17TkMu8_isPS, &b_AOD_HLT_TkMu17TkMu8_isPS);
   fChain->SetBranchAddress("AOD_HLT_Mu17Mu8_noDZ_isPS", &AOD_HLT_Mu17Mu8_noDZ_isPS, &b_AOD_HLT_Mu17Mu8_noDZ_isPS);
   fChain->SetBranchAddress("AOD_HLT_Mu17TkMu8_noDZ_isPS", &AOD_HLT_Mu17TkMu8_noDZ_isPS, &b_AOD_HLT_Mu17TkMu8_noDZ_isPS);
   fChain->SetBranchAddress("AOD_HLT_TkMu17TkMu8_noDZ_isPS", &AOD_HLT_TkMu17TkMu8_noDZ_isPS, &b_AOD_HLT_TkMu17TkMu8_noDZ_isPS);
   fChain->SetBranchAddress("AOD_HLT_Mu8Ele23_DZ_isPS", &AOD_HLT_Mu8Ele23_DZ_isPS, &b_AOD_HLT_Mu8Ele23_DZ_isPS);
   fChain->SetBranchAddress("AOD_HLT_Mu8Ele23_noDZ_isPS", &AOD_HLT_Mu8Ele23_noDZ_isPS, &b_AOD_HLT_Mu8Ele23_noDZ_isPS);
   fChain->SetBranchAddress("AOD_HLT_Mu23Ele12_DZ_isPS", &AOD_HLT_Mu23Ele12_DZ_isPS, &b_AOD_HLT_Mu23Ele12_DZ_isPS);
   fChain->SetBranchAddress("AOD_HLT_Mu23Ele12_noDZ_isPS", &AOD_HLT_Mu23Ele12_noDZ_isPS, &b_AOD_HLT_Mu23Ele12_noDZ_isPS);
   fChain->SetBranchAddress("AOD_HLT_Mu12Ele23_DZ_isPS", &AOD_HLT_Mu12Ele23_DZ_isPS, &b_AOD_HLT_Mu12Ele23_DZ_isPS);
   fChain->SetBranchAddress("AOD_HLT_Mu12Ele23_noDZ_isPS", &AOD_HLT_Mu12Ele23_noDZ_isPS, &b_AOD_HLT_Mu12Ele23_noDZ_isPS);
   fChain->SetBranchAddress("AODnCaloJet", &AODnCaloJet, &b_AODnCaloJet);
   fChain->SetBranchAddress("AODCaloJetEnergy", &AODCaloJetEnergy, &b_AODCaloJetEnergy);
   fChain->SetBranchAddress("AODCaloJetPt", &AODCaloJetPt, &b_AODCaloJetPt);
   fChain->SetBranchAddress("AODCaloJetEnergyUncorrected", &AODCaloJetEnergyUncorrected, &b_AODCaloJetEnergyUncorrected);
   fChain->SetBranchAddress("AODCaloJetPtUncorrected", &AODCaloJetPtUncorrected, &b_AODCaloJetPtUncorrected);
   fChain->SetBranchAddress("AODCaloJetPt_JECUp", &AODCaloJetPt_JECUp, &b_AODCaloJetPt_JECUp);
   fChain->SetBranchAddress("AODCaloJetPt_JECDown", &AODCaloJetPt_JECDown, &b_AODCaloJetPt_JECDown);
   fChain->SetBranchAddress("AODCaloJetEta", &AODCaloJetEta, &b_AODCaloJetEta);
   fChain->SetBranchAddress("AODCaloJetPhi", &AODCaloJetPhi, &b_AODCaloJetPhi);
   fChain->SetBranchAddress("AODCaloJetID", &AODCaloJetID, &b_AODCaloJetID);
   fChain->SetBranchAddress("AODCaloJet_emEnergyFraction", &AODCaloJet_emEnergyFraction, &b_AODCaloJet_emEnergyFraction);
   fChain->SetBranchAddress("AODCaloJet_energyFractionHadronic", &AODCaloJet_energyFractionHadronic, &b_AODCaloJet_energyFractionHadronic);
   fChain->SetBranchAddress("AODCaloJetMass", &AODCaloJetMass, &b_AODCaloJetMass);
   fChain->SetBranchAddress("AODCaloJetArea", &AODCaloJetArea, &b_AODCaloJetArea);
   fChain->SetBranchAddress("AODCaloJetPileup", &AODCaloJetPileup, &b_AODCaloJetPileup);
   fChain->SetBranchAddress("AODCaloJetAlphaMax", &AODCaloJetAlphaMax, &b_AODCaloJetAlphaMax);
   fChain->SetBranchAddress("AODCaloJetAlphaMax2", &AODCaloJetAlphaMax2, &b_AODCaloJetAlphaMax2);
   fChain->SetBranchAddress("AODCaloJetAlphaMaxPrime", &AODCaloJetAlphaMaxPrime, &b_AODCaloJetAlphaMaxPrime);
   fChain->SetBranchAddress("AODCaloJetAlphaMaxPrime2", &AODCaloJetAlphaMaxPrime2, &b_AODCaloJetAlphaMaxPrime2);
   fChain->SetBranchAddress("AODCaloJetBeta", &AODCaloJetBeta, &b_AODCaloJetBeta);
   fChain->SetBranchAddress("AODCaloJetBeta2", &AODCaloJetBeta2, &b_AODCaloJetBeta2);
   fChain->SetBranchAddress("AODCaloJetSumIP", &AODCaloJetSumIP, &b_AODCaloJetSumIP);
   fChain->SetBranchAddress("AODCaloJetSumIPSig", &AODCaloJetSumIPSig, &b_AODCaloJetSumIPSig);
   fChain->SetBranchAddress("AODCaloJetMedianIP", &AODCaloJetMedianIP, &b_AODCaloJetMedianIP);
   fChain->SetBranchAddress("AODCaloJetMedianLog10IPSig", &AODCaloJetMedianLog10IPSig, &b_AODCaloJetMedianLog10IPSig);
   fChain->SetBranchAddress("AODCaloJetTrackAngle", &AODCaloJetTrackAngle, &b_AODCaloJetTrackAngle);
   fChain->SetBranchAddress("AODCaloJetLogTrackAngle", &AODCaloJetLogTrackAngle, &b_AODCaloJetLogTrackAngle);
   fChain->SetBranchAddress("AODCaloJetMedianLog10TrackAngle", &AODCaloJetMedianLog10TrackAngle, &b_AODCaloJetMedianLog10TrackAngle);
   fChain->SetBranchAddress("AODCaloJetTotalTrackAngle", &AODCaloJetTotalTrackAngle, &b_AODCaloJetTotalTrackAngle);
   fChain->SetBranchAddress("AODCaloJetAvfVx", &AODCaloJetAvfVx, &b_AODCaloJetAvfVx);
   fChain->SetBranchAddress("AODCaloJetAvfVy", &AODCaloJetAvfVy, &b_AODCaloJetAvfVy);
   fChain->SetBranchAddress("AODCaloJetAvfVz", &AODCaloJetAvfVz, &b_AODCaloJetAvfVz);
   fChain->SetBranchAddress("AODCaloJetAvfVertexTotalChiSquared", &AODCaloJetAvfVertexTotalChiSquared, &b_AODCaloJetAvfVertexTotalChiSquared);
   fChain->SetBranchAddress("AODCaloJetAvfVertexDegreesOfFreedom", &AODCaloJetAvfVertexDegreesOfFreedom, &b_AODCaloJetAvfVertexDegreesOfFreedom);
   fChain->SetBranchAddress("AODCaloJetAvfVertexChi2NDoF", &AODCaloJetAvfVertexChi2NDoF, &b_AODCaloJetAvfVertexChi2NDoF);
   fChain->SetBranchAddress("AODCaloJetAvfVertexDistanceToBeam", &AODCaloJetAvfVertexDistanceToBeam, &b_AODCaloJetAvfVertexDistanceToBeam);
   fChain->SetBranchAddress("AODCaloJetAvfVertexTransverseError", &AODCaloJetAvfVertexTransverseError, &b_AODCaloJetAvfVertexTransverseError);
   fChain->SetBranchAddress("AODCaloJetAvfVertexTransverseSig", &AODCaloJetAvfVertexTransverseSig, &b_AODCaloJetAvfVertexTransverseSig);
   fChain->SetBranchAddress("AODCaloJetAvfVertexDeltaEta", &AODCaloJetAvfVertexDeltaEta, &b_AODCaloJetAvfVertexDeltaEta);
   fChain->SetBranchAddress("AODCaloJetAvfVertexDeltaPhi", &AODCaloJetAvfVertexDeltaPhi, &b_AODCaloJetAvfVertexDeltaPhi);
   fChain->SetBranchAddress("AODCaloJetAvfVertexRecoilPt", &AODCaloJetAvfVertexRecoilPt, &b_AODCaloJetAvfVertexRecoilPt);
   fChain->SetBranchAddress("AODCaloJetAvfVertexTrackMass", &AODCaloJetAvfVertexTrackMass, &b_AODCaloJetAvfVertexTrackMass);
   fChain->SetBranchAddress("AODCaloJetAvfVertexTrackEnergy", &AODCaloJetAvfVertexTrackEnergy, &b_AODCaloJetAvfVertexTrackEnergy);
   fChain->SetBranchAddress("AODCaloJetAvfBeamSpotDeltaPhi", &AODCaloJetAvfBeamSpotDeltaPhi, &b_AODCaloJetAvfBeamSpotDeltaPhi);
   fChain->SetBranchAddress("AODCaloJetAvfBeamSpotRecoilPt", &AODCaloJetAvfBeamSpotRecoilPt, &b_AODCaloJetAvfBeamSpotRecoilPt);
   fChain->SetBranchAddress("AODCaloJetAvfBeamSpotMedianDeltaPhi", &AODCaloJetAvfBeamSpotMedianDeltaPhi, &b_AODCaloJetAvfBeamSpotMedianDeltaPhi);
   fChain->SetBranchAddress("AODCaloJetAvfBeamSpotLog10MedianDeltaPhi", &AODCaloJetAvfBeamSpotLog10MedianDeltaPhi, &b_AODCaloJetAvfBeamSpotLog10MedianDeltaPhi);
   fChain->SetBranchAddress("AODCaloJetNCleanMatchedTracks", &AODCaloJetNCleanMatchedTracks, &b_AODCaloJetNCleanMatchedTracks);
   fChain->SetBranchAddress("AODCaloJetNMatchedTracks", &AODCaloJetNMatchedTracks, &b_AODCaloJetNMatchedTracks);
   fChain->SetBranchAddress("AODCaloJetSumHitsInFrontOfVert", &AODCaloJetSumHitsInFrontOfVert, &b_AODCaloJetSumHitsInFrontOfVert);
   fChain->SetBranchAddress("AODCaloJetSumMissHitsAfterVert", &AODCaloJetSumMissHitsAfterVert, &b_AODCaloJetSumMissHitsAfterVert);
   fChain->SetBranchAddress("AODCaloJetHitsInFrontOfVertPerTrack", &AODCaloJetHitsInFrontOfVertPerTrack, &b_AODCaloJetHitsInFrontOfVertPerTrack);
   fChain->SetBranchAddress("AODCaloJetMissHitsAfterVertPerTrack", &AODCaloJetMissHitsAfterVertPerTrack, &b_AODCaloJetMissHitsAfterVertPerTrack);
   fChain->SetBranchAddress("AODCaloJetAvfDistToPV", &AODCaloJetAvfDistToPV, &b_AODCaloJetAvfDistToPV);
   fChain->SetBranchAddress("AODCaloJetAvfVertexDeltaZtoPV", &AODCaloJetAvfVertexDeltaZtoPV, &b_AODCaloJetAvfVertexDeltaZtoPV);
   fChain->SetBranchAddress("AODCaloJetAvfVertexDeltaZtoPV2", &AODCaloJetAvfVertexDeltaZtoPV2, &b_AODCaloJetAvfVertexDeltaZtoPV2);
   fChain->SetBranchAddress("nAODMu", &nAODMu, &b_nAODMu);
   fChain->SetBranchAddress("AOD_muPt", &AOD_muPt, &b_AOD_muPt);
   fChain->SetBranchAddress("AOD_muEn", &AOD_muEn, &b_AOD_muEn);
   fChain->SetBranchAddress("AOD_muEta", &AOD_muEta, &b_AOD_muEta);
   fChain->SetBranchAddress("AOD_muPhi", &AOD_muPhi, &b_AOD_muPhi);
   fChain->SetBranchAddress("AOD_muCharge", &AOD_muCharge, &b_AOD_muCharge);
   fChain->SetBranchAddress("AOD_muType", &AOD_muType, &b_AOD_muType);
   fChain->SetBranchAddress("AOD_muIsGlobalMuon", &AOD_muIsGlobalMuon, &b_AOD_muIsGlobalMuon);
   fChain->SetBranchAddress("AOD_muIsPFMuon", &AOD_muIsPFMuon, &b_AOD_muIsPFMuon);
   fChain->SetBranchAddress("AOD_muPassLooseID", &AOD_muPassLooseID, &b_AOD_muPassLooseID);
   fChain->SetBranchAddress("AOD_muPassMediumBCDEFID", &AOD_muPassMediumBCDEFID, &b_AOD_muPassMediumBCDEFID);
   fChain->SetBranchAddress("AOD_muPassMediumGHID", &AOD_muPassMediumGHID, &b_AOD_muPassMediumGHID);
   fChain->SetBranchAddress("AOD_muPassTightID", &AOD_muPassTightID, &b_AOD_muPassTightID);
   fChain->SetBranchAddress("AOD_muPFdBetaIsolation", &AOD_muPFdBetaIsolation, &b_AOD_muPFdBetaIsolation);
   fChain->SetBranchAddress("AOD_muDxy", &AOD_muDxy, &b_AOD_muDxy);
   fChain->SetBranchAddress("AOD_muDxyErr", &AOD_muDxyErr, &b_AOD_muDxyErr);
   fChain->SetBranchAddress("AOD_muDB_BS2D", &AOD_muDB_BS2D, &b_AOD_muDB_BS2D);
   fChain->SetBranchAddress("AOD_muDB_PV2D", &AOD_muDB_PV2D, &b_AOD_muDB_PV2D);
   fChain->SetBranchAddress("nAODPho", &nAODPho, &b_nAODPho);
   fChain->SetBranchAddress("AOD_phoPt", &AOD_phoPt, &b_AOD_phoPt);
   fChain->SetBranchAddress("AOD_phoEn", &AOD_phoEn, &b_AOD_phoEn);
   fChain->SetBranchAddress("AOD_phoEta", &AOD_phoEta, &b_AOD_phoEta);
   fChain->SetBranchAddress("AOD_phoPhi", &AOD_phoPhi, &b_AOD_phoPhi);
   fChain->SetBranchAddress("AOD_phoSCEn", &AOD_phoSCEn, &b_AOD_phoSCEn);
   fChain->SetBranchAddress("AOD_phoSCEta", &AOD_phoSCEta, &b_AOD_phoSCEta);
   fChain->SetBranchAddress("AOD_phoSCPhi", &AOD_phoSCPhi, &b_AOD_phoSCPhi);
   fChain->SetBranchAddress("nAODEle", &nAODEle, &b_nAODEle);
   fChain->SetBranchAddress("AOD_elePt", &AOD_elePt, &b_AOD_elePt);
   fChain->SetBranchAddress("AOD_eleEn", &AOD_eleEn, &b_AOD_eleEn);
   fChain->SetBranchAddress("AOD_eleEta", &AOD_eleEta, &b_AOD_eleEta);
   fChain->SetBranchAddress("AOD_elePhi", &AOD_elePhi, &b_AOD_elePhi);
   fChain->SetBranchAddress("AOD_eled0", &AOD_eled0, &b_AOD_eled0);
   fChain->SetBranchAddress("AOD_eledz", &AOD_eledz, &b_AOD_eledz);
   fChain->SetBranchAddress("AOD_eleCharge", &AOD_eleCharge, &b_AOD_eleCharge);
   fChain->SetBranchAddress("AOD_eleChargeConsistent", &AOD_eleChargeConsistent, &b_AOD_eleChargeConsistent);
   fChain->SetBranchAddress("AOD_eleIDbit", &AOD_eleIDbit, &b_AOD_eleIDbit);
   fChain->SetBranchAddress("AOD_elePassConversionVeto", &AOD_elePassConversionVeto, &b_AOD_elePassConversionVeto);
   fChain->SetBranchAddress("AOD_CaloMET_pt", &AOD_CaloMET_pt, &b_AOD_CaloMET_pt);
   fChain->SetBranchAddress("AOD_CaloMET_phi", &AOD_CaloMET_phi, &b_AOD_CaloMET_phi);

   Notify();
}

Bool_t SampleSplit::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void SampleSplit::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t SampleSplit::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef SampleSplit_cxx
