#include "analyzer_base.h"

//----------------------------analyzer_base
analyzer_base::analyzer_base() 
{
}

//----------------------------~analyzer_base
analyzer_base::~analyzer_base()
{
}

//----------------------------LoadTree
Long64_t analyzer_base::LoadTree(Long64_t entry)
{
 // Set the environment to read one entry
 if (!fChain) return -5;
 Long64_t centry = fChain->LoadTree(entry);
 if (centry < 0) return centry;
 if (fChain->GetTreeNumber() != fCurrent) {
  fCurrent = fChain->GetTreeNumber();
 }
 return centry;
}

//----------------------------Init
void analyzer_base::Init(TChain *tree, Bool_t isitMC, Bool_t domakelog, TString Tsample, TString uncbin)
{

   isMC = isitMC;
   makelog = domakelog;

   //\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\//
   // MC and Data
   //\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\//
   // set object pointers
   AODGenEventWeight = 1.;
   ctauEventWeight = 1.;
   
   AODnGoodVtx = 0;
   AODnVtx = 0;
   AODnTruePU = 0;
   AOD0thnPU = 0;
   AODCaloJetPt = 0;
   AODCaloJetEta = 0;
   AODCaloJetPhi = 0;
   AODCaloJetID = 0;
   AODCaloJet_emEnergyFraction = 0;
   AODCaloJet_energyFractionHadronic = 0;
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
   AOD_elePt = 0;
   AOD_eleEn = 0;
   AOD_eleEta = 0;
   AOD_elePhi = 0;
   AOD_eleCharge = 0;
   AOD_eleChargeConsistent = 0;
   AOD_eleIDbit = 0;
   AOD_elePassConversionVeto = 0;
   AOD_eled0 = 0;
   AOD_eledz = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("event", &event, &b_event);
   fChain->SetBranchAddress("lumis", &lumis, &b_lumis);
   fChain->SetBranchAddress("isData", &isData, &b_isData);
   fChain->SetBranchAddress("AODGenEventWeight", &AODGenEventWeight, &b_AODGenEventWeight);
   fChain->SetBranchAddress("ctau_eventweight", &ctauEventWeight, &b_ctauEventWeight);
   fChain->SetBranchAddress("AODnVtx", &AODnVtx, &b_AODnVtx);
   fChain->SetBranchAddress("AODnGoodVtx", &AODnGoodVtx, &b_AODnGoodVtx);
   fChain->SetBranchAddress("AODnTrksPV", &AODnTrksPV, &b_AODnTrksPV);
   fChain->SetBranchAddress("AODisPVGood", &AODisPVGood, &b_AODisPVGood);
   fChain->SetBranchAddress("AODfixedGridRhoFastjetAll", &AODfixedGridRhoFastjetAll, &b_AODfixedGridRhoFastjetAll);
   fChain->SetBranchAddress("AODnBunchXing", &AODnBunchXing, &b_AODnBunchXing);
   fChain->SetBranchAddress("AODBunchXing", &AODBunchXing, &b_AODBunchXing);
   fChain->SetBranchAddress("AODnPU", &AODnPU, &b_AODnPU);
   fChain->SetBranchAddress("AODnPUmean", &AODnPUmean, &b_AODnPUmean);
   fChain->SetBranchAddress("AODnTruePU", &AODnTruePU, &b_AODnTruePU);
   fChain->SetBranchAddress("AOD0thnPU", &AOD0thnPU, &b_AOD0thnPU);
   fChain->SetBranchAddress("model", &model, &b_model);
   fChain->SetBranchAddress("llpId", &llpId           , &b_llpId           );
   fChain->SetBranchAddress("llpStatus", &llpStatus       , &b_llpStatus       );
   fChain->SetBranchAddress("llpPt", &llpPt           , &b_llpPt           );
   fChain->SetBranchAddress("llpEta", &llpEta          , &b_llpEta          );
   fChain->SetBranchAddress("llpPhi", &llpPhi          , &b_llpPhi          );
   fChain->SetBranchAddress("llpMass", &llpMass         , &b_llpMass         );
   fChain->SetBranchAddress("llpDaughterId", &llpDaughterId   , &b_llpDaughterId   );
   fChain->SetBranchAddress("llpDaughterStatus", &llpDaughterStatus, &b_llpDaughterStatus);
   fChain->SetBranchAddress("llpDaughterPt", &llpDaughterPt   , &b_llpDaughterPt   );
   fChain->SetBranchAddress("llpDaughterEta", &llpDaughterEta  , &b_llpDaughterEta  );
   fChain->SetBranchAddress("llpDaughterPhi", &llpDaughterPhi  , &b_llpDaughterPhi  );
   fChain->SetBranchAddress("llpDaughterMass", &llpDaughterMass , &b_llpDaughterMass );
   fChain->SetBranchAddress("llpvX", &llpvX            , &b_llpvX            );
   fChain->SetBranchAddress("llpvY", &llpvY            , &b_llpvY            );
   fChain->SetBranchAddress("llpvZ", &llpvZ            , &b_llpvZ            );
   fChain->SetBranchAddress("llpDaughtervX", &llpDaughtervX    , &b_llpDaughtervX    );
   fChain->SetBranchAddress("llpDaughtervY", &llpDaughtervY    , &b_llpDaughtervY    );
   fChain->SetBranchAddress("llpDaughtervZ", &llpDaughtervZ    , &b_llpDaughtervZ    );
   fChain->SetBranchAddress("gen_Z_mass", &gen_Z_mass       , &b_gen_Z_mass       );
   fChain->SetBranchAddress("gen_Z_energy", &gen_Z_energy     , &b_gen_Z_energy     );
   fChain->SetBranchAddress("gen_Z_pt", &gen_Z_pt         , &b_gen_Z_pt         );
   fChain->SetBranchAddress("gen_Z_eta", &gen_Z_eta        , &b_gen_Z_eta        );
   fChain->SetBranchAddress("gen_Z_phi", &gen_Z_phi        , &b_gen_Z_phi        );
   fChain->SetBranchAddress("gen_Z_dauther1_Id", &gen_Z_dauther1_Id, &b_gen_Z_dauther1_Id);
   fChain->SetBranchAddress("gen_Z_dauther2_Id", &gen_Z_dauther2_Id, &b_gen_Z_dauther2_Id);
   fChain->SetBranchAddress("gen_lep_energy", &gen_lep_energy   , &b_gen_lep_energy   );
   fChain->SetBranchAddress("gen_lep_pt", &gen_lep_pt       , &b_gen_lep_pt       );
   fChain->SetBranchAddress("gen_lep_eta", &gen_lep_eta      , &b_gen_lep_eta      );
   fChain->SetBranchAddress("gen_lep_phi", &gen_lep_phi      , &b_gen_lep_phi      );
   fChain->SetBranchAddress("gen_lep_Id", &gen_lep_Id       , &b_gen_lep_Id       );
   fChain->SetBranchAddress("gen_lep_momId", &gen_lep_momId    , &b_gen_lep_momId    );
   fChain->SetBranchAddress("toppts", &toppts, &b_toppts);
   //ele ele
   fChain->SetBranchAddress("AOD_HLT_DoubleEle33", &AOD_HLT_DoubleEle33         , &b_AOD_HLT_DoubleEle33         );
   fChain->SetBranchAddress("AOD_HLT_Ele23Ele12", &AOD_HLT_Ele23Ele12          , &b_AOD_HLT_Ele23Ele12          );
   fChain->SetBranchAddress("AOD_HLT_Ele23Ele12_noDZ", &AOD_HLT_Ele23Ele12_noDZ     , &b_AOD_HLT_Ele23Ele12_noDZ     );
   fChain->SetBranchAddress("AOD_HLT_DoubleEle33_isPS", &AOD_HLT_DoubleEle33_isPS    , &b_AOD_HLT_DoubleEle33_isPS    );
   fChain->SetBranchAddress("AOD_HLT_Ele23Ele12_isPS", &AOD_HLT_Ele23Ele12_isPS     , &b_AOD_HLT_Ele23Ele12_isPS     );
   fChain->SetBranchAddress("AOD_HLT_Ele23Ele12_noDZ_isPS", &AOD_HLT_Ele23Ele12_noDZ_isPS, &b_AOD_HLT_Ele23Ele12_noDZ_isPS);
   //mu mu
   fChain->SetBranchAddress("AOD_HLT_Mu17Mu8", &AOD_HLT_Mu17Mu8              , &b_AOD_HLT_Mu17Mu8              );
   fChain->SetBranchAddress("AOD_HLT_Mu17TkMu8", &AOD_HLT_Mu17TkMu8            , &b_AOD_HLT_Mu17TkMu8            );
   fChain->SetBranchAddress("AOD_HLT_TkMu17TkMu8", &AOD_HLT_TkMu17TkMu8          , &b_AOD_HLT_TkMu17TkMu8          );
   fChain->SetBranchAddress("AOD_HLT_Mu17Mu8_noDZ", &AOD_HLT_Mu17Mu8_noDZ         , &b_AOD_HLT_Mu17Mu8_noDZ         );
   fChain->SetBranchAddress("AOD_HLT_Mu17TkMu8_noDZ", &AOD_HLT_Mu17TkMu8_noDZ       , &b_AOD_HLT_Mu17TkMu8_noDZ       );
   fChain->SetBranchAddress("AOD_HLT_TkMu17TkMu8_noDZ", &AOD_HLT_TkMu17TkMu8_noDZ     , &b_AOD_HLT_TkMu17TkMu8_noDZ     );
   fChain->SetBranchAddress("AOD_HLT_Mu17Mu8_Mass8", &AOD_HLT_Mu17Mu8_Mass8        , &b_AOD_HLT_Mu17Mu8_Mass8        );
   fChain->SetBranchAddress("AOD_HLT_Mu17Mu8_Mass3p8", &AOD_HLT_Mu17Mu8_Mass3p8      , &b_AOD_HLT_Mu17Mu8_Mass3p8      );
   fChain->SetBranchAddress("AOD_HLT_Mu17Mu8_isPS", &AOD_HLT_Mu17Mu8_isPS         , &b_AOD_HLT_Mu17Mu8_isPS         );
   fChain->SetBranchAddress("AOD_HLT_Mu17Mu8_Mass8_isPS", &AOD_HLT_Mu17Mu8_Mass8_isPS   , &b_AOD_HLT_Mu17Mu8_Mass8_isPS   );
   fChain->SetBranchAddress("AOD_HLT_Mu17Mu8_Mass3p8_isPS", &AOD_HLT_Mu17Mu8_Mass3p8_isPS , &b_AOD_HLT_Mu17Mu8_Mass3p8_isPS );
   fChain->SetBranchAddress("AOD_HLT_Mu17Mu8_noDZ_isPS", &AOD_HLT_Mu17Mu8_noDZ_isPS    , &b_AOD_HLT_Mu17Mu8_noDZ_isPS    );
   fChain->SetBranchAddress("AOD_HLT_Mu17TkMu8_isPS", &AOD_HLT_Mu17TkMu8_isPS       , &b_AOD_HLT_Mu17TkMu8_isPS       );
   fChain->SetBranchAddress("AOD_HLT_TkMu17TkMu8_isPS", &AOD_HLT_TkMu17TkMu8_isPS     , &b_AOD_HLT_TkMu17TkMu8_isPS     );
   fChain->SetBranchAddress("AOD_HLT_Mu17TkMu8_noDZ_isPS", &AOD_HLT_Mu17TkMu8_noDZ_isPS  , &b_AOD_HLT_Mu17TkMu8_noDZ_isPS  );
   fChain->SetBranchAddress("AOD_HLT_TkMu17TkMu8_noDZ_isPS", &AOD_HLT_TkMu17TkMu8_noDZ_isPS, &b_AOD_HLT_TkMu17TkMu8_noDZ_isPS);
   //mu ele
   fChain->SetBranchAddress("AOD_HLT_Mu8Ele23_DZ", &AOD_HLT_Mu8Ele23_DZ        , &b_AOD_HLT_Mu8Ele23_DZ        );
   fChain->SetBranchAddress("AOD_HLT_Mu8Ele23_noDZ", &AOD_HLT_Mu8Ele23_noDZ      , &b_AOD_HLT_Mu8Ele23_noDZ      );
   fChain->SetBranchAddress("AOD_HLT_Mu23Ele12_DZ", &AOD_HLT_Mu23Ele12_DZ       , &b_AOD_HLT_Mu23Ele12_DZ       );
   fChain->SetBranchAddress("AOD_HLT_Mu23Ele12_noDZ", &AOD_HLT_Mu23Ele12_noDZ     , &b_AOD_HLT_Mu23Ele12_noDZ     );
   fChain->SetBranchAddress("AOD_HLT_Mu12Ele23_DZ", &AOD_HLT_Mu12Ele23_DZ       , &b_AOD_HLT_Mu12Ele23_DZ       );
   fChain->SetBranchAddress("AOD_HLT_Mu12Ele23_noDZ", &AOD_HLT_Mu12Ele23_noDZ     , &b_AOD_HLT_Mu12Ele23_noDZ     );
   fChain->SetBranchAddress("AOD_HLT_Mu8Ele23_DZ_isPS", &AOD_HLT_Mu8Ele23_DZ_isPS   , &b_AOD_HLT_Mu8Ele23_DZ_isPS   );
   fChain->SetBranchAddress("AOD_HLT_Mu8Ele23_noDZ_isPS", &AOD_HLT_Mu8Ele23_noDZ_isPS , &b_AOD_HLT_Mu8Ele23_noDZ_isPS );
   fChain->SetBranchAddress("AOD_HLT_Mu23Ele12_DZ_isPS", &AOD_HLT_Mu23Ele12_DZ_isPS  , &b_AOD_HLT_Mu23Ele12_DZ_isPS  );
   fChain->SetBranchAddress("AOD_HLT_Mu23Ele12_noDZ_isPS", &AOD_HLT_Mu23Ele12_noDZ_isPS, &b_AOD_HLT_Mu23Ele12_noDZ_isPS);
   fChain->SetBranchAddress("AOD_HLT_Mu12Ele23_DZ_isPS", &AOD_HLT_Mu12Ele23_DZ_isPS  , &b_AOD_HLT_Mu12Ele23_DZ_isPS  );
   fChain->SetBranchAddress("AOD_HLT_Mu12Ele23_noDZ_isPS", &AOD_HLT_Mu12Ele23_noDZ_isPS, &b_AOD_HLT_Mu12Ele23_noDZ_isPS);

   fChain->SetBranchAddress("AODnCaloJet", &AODnCaloJet, &b_AODnCaloJet);
   fChain->SetBranchAddress("AODCaloJetEnergy", &AODCaloJetEnergy, &b_AODCaloJetEnergy);
   fChain->SetBranchAddress("AODCaloJetEnergyUncorrected", &AODCaloJetEnergyUncorrected, &b_AODCaloJetEnergyUncorrected);
   fChain->SetBranchAddress("AODCaloJetPtUncorrected", &AODCaloJetPtUncorrected, &b_AODCaloJetPtUncorrected);
   if (uncbin.Contains("_JESUp")){fChain->SetBranchAddress("AODCaloJetPt_JECUp", &AODCaloJetPt, &b_AODCaloJetPt);}
   else if (uncbin.Contains("_JESDown")){fChain->SetBranchAddress("AODCaloJetPt_JECDown", &AODCaloJetPt, &b_AODCaloJetPt);}
   else {fChain->SetBranchAddress("AODCaloJetPt", &AODCaloJetPt, &b_AODCaloJetPt);}
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
   fChain->SetBranchAddress("nAODEle", &nAODEle, &b_nAODEle);
   fChain->SetBranchAddress("AOD_elePt", &AOD_elePt, &b_AOD_elePt);
   fChain->SetBranchAddress("AOD_eleEn", &AOD_eleEn, &b_AOD_eleEn);
   fChain->SetBranchAddress("AOD_eleEta", &AOD_eleEta, &b_AOD_eleEta);
   fChain->SetBranchAddress("AOD_elePhi", &AOD_elePhi, &b_AOD_elePhi);
   fChain->SetBranchAddress("AOD_eleCharge", &AOD_eleCharge, &b_AOD_eleCharge);
   fChain->SetBranchAddress("AOD_eleChargeConsistent", &AOD_eleChargeConsistent, &b_AOD_eleChargeConsistent);
   fChain->SetBranchAddress("AOD_eleIDbit", &AOD_eleIDbit, &b_AOD_eleIDbit);
   fChain->SetBranchAddress("AOD_elePassConversionVeto", &AOD_elePassConversionVeto, &b_AOD_elePassConversionVeto);
   fChain->SetBranchAddress("AOD_eled0", &AOD_eled0, &b_AOD_eled0);
   fChain->SetBranchAddress("AOD_eledz", &AOD_eledz, &b_AOD_eledz);
   fChain->SetBranchAddress("AOD_CaloMET_pt", &AOD_CaloMET_pt, &b_AOD_CaloMET_pt);
   fChain->SetBranchAddress("AOD_CaloMET_phi", &AOD_CaloMET_phi, &b_AOD_CaloMET_phi);

}
