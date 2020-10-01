
#ifndef analyzer_tree_h
#define analyzer_tree_h

#include "analyzer_histograms.h"
#include <TLorentzVector.h>

class analyzer_tree : public analyzer_histograms {


public :

                  analyzer_tree();
   virtual        ~analyzer_tree(); 

   virtual void clearOPTtree();
   virtual void setOPTtree();
  
   //Keep for general purpose 
//------------------------------OPT Tree
   // output TTree to be filled (slimmed vars/selections)
   TTree *OPTtree = new TTree("OPTtree","Optimization Variables");
  
   // vectors to be filled in optional tree
   std::vector<int>   OPT_Event;
   std::vector<int>   OPT_Run;
   std::vector<int>   OPT_Lumis;

   std::vector<float> OPT_EventWeight;
   std::vector<float> OPT_lumi_weight;
   std::vector<float> OPT_ele_weight;
   std::vector<float> OPT_mu_weight;
   std::vector<float> OPT_PU_weight;

   std::vector<float> OPT_ZPt;
   std::vector<float> OPT_ZMass;

   std::vector<int>   OPT_nJets;
   std::vector<float> OPT_AODCaloJetMedianLog10IPSig;
   std::vector<float> OPT_AODCaloJetMedianLog10TrackAngle;
   std::vector<float> OPT_AODCaloJetAlphaMax;
   std::vector<float> OPT_AODCaloJetPt;
   std::vector<float> OPT_AODCaloJetEta;
   std::vector<float> OPT_AODCaloJetPhi;
   std::vector<float> OPT_AODCaloJet_emEnergyFraction;
   std::vector<float> OPT_AODCaloJet_energyFractionHadronic;
   std::vector<bool>  OPT_AODCaloJetID;
  
   std::vector<int>   OPT_nAODEle;
   std::vector<float> OPT_AOD_elePt;
   std::vector<float> OPT_AOD_eleEta;
   std::vector<float> OPT_AOD_elePhi;

   // link vectors to branches
   TBranch* bEvent       = OPTtree->Branch("OPT_Event"                              , &OPT_Event); 
   TBranch* bRun         = OPTtree->Branch("OPT_Run"                                , &OPT_Run); 
   TBranch* bLumis       = OPTtree->Branch("OPT_Lumis"                              , &OPT_Lumis); 
   
   TBranch* bEventWeight = OPTtree->Branch("OPT_EventWeight"                        , &OPT_EventWeight); 
   TBranch* blumi_weight = OPTtree->Branch("OPT_lumi_weight"                        , &OPT_lumi_weight); 
   TBranch* bele_weight  = OPTtree->Branch("OPT_ele_weight"                         , &OPT_ele_weight); 
   TBranch* bmu_weight   = OPTtree->Branch("OPT_mu_weight"                          , &OPT_mu_weight); 
   TBranch* bPU_weight   = OPTtree->Branch("OPT_PU_weight"                          , &OPT_PU_weight); 
   
   TBranch* bZPt         = OPTtree->Branch("OPT_ZPt"                                , &OPT_ZPt); 
   TBranch* bZMass       = OPTtree->Branch("OPT_ZMass"                              , &OPT_ZMass); 
   
   TBranch* bnJets       = OPTtree->Branch("OPT_nJets"                              , &OPT_nJets); 
   TBranch* bIP          = OPTtree->Branch("OPT_AODCaloJetMedianLog10IPSig"         , &OPT_AODCaloJetMedianLog10IPSig); 
   TBranch* bTA          = OPTtree->Branch("OPT_AODCaloJetMedianLog10TrackAngle"    , &OPT_AODCaloJetMedianLog10TrackAngle); 
   TBranch* bAlpha       = OPTtree->Branch("OPT_AODCaloJetAlphaMax"                 , &OPT_AODCaloJetAlphaMax); 
   TBranch* bPt          = OPTtree->Branch("OPT_AODCaloJetPt"                       , &OPT_AODCaloJetPt); 
   TBranch* bEta         = OPTtree->Branch("OPT_AODCaloJetEta"                      , &OPT_AODCaloJetEta); 
   TBranch* bPhi         = OPTtree->Branch("OPT_AODCaloJetPhi"                      , &OPT_AODCaloJetPhi); 
   TBranch* bemEnFrac    = OPTtree->Branch("OPT_AODCaloJet_emEnergyFraction"        , &OPT_AODCaloJet_emEnergyFraction); 
   TBranch* bhadEnFrac   = OPTtree->Branch("OPT_energyFractionHadronic"             , &OPT_AODCaloJet_energyFractionHadronic); 
   TBranch* bID          = OPTtree->Branch("OPT_AODCaloJetID"                       , &OPT_AODCaloJetID); 
 
   TBranch* b_nAODEle    = OPTtree->Branch("OPT_nAODEle"                , &OPT_nAODEle); 
   TBranch* b_AOD_elePt  = OPTtree->Branch("OPT_AOD_elePt"              , &OPT_AOD_elePt); 
   TBranch* b_AOD_eleEta = OPTtree->Branch("OPT_AOD_eleEta"             , &OPT_AOD_eleEta); 
   TBranch* b_AOD_elePhi = OPTtree->Branch("OPT_AOD_elePhi"             , &OPT_AOD_elePhi); 

};

#endif
