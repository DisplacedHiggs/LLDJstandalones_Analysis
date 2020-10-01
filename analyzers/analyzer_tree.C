#include "analyzer_tree.h"

//----------------------------analyzer_tree
analyzer_tree::analyzer_tree() 
{
}

//----------------------------~analyzer_tree
analyzer_tree::~analyzer_tree()
{
}


//----------------------------setOPTtree
void analyzer_tree::setOPTtree(){

  OPT_Event  .push_back(event);
  OPT_Run    .push_back(run);
  OPT_Lumis  .push_back(lumis);
  
  OPT_EventWeight.push_back(event_weight);
  OPT_lumi_weight.push_back(base_weight);
  OPT_ele_weight .push_back(ele_weight);
  OPT_mu_weight  .push_back(mu_weight);
  OPT_PU_weight  .push_back(PU_weight);
  
  OPT_nJets.push_back(aodcalojet_list.size());
  OPT_nAODEle.push_back(electron_list.size());
  
  OPT_ZPt.push_back(dilep_pt);
  OPT_ZMass.push_back(dilep_mass);
  if(aodcalojet_list.size()>0){
    for(int i = 0; i<aodcalojet_list.size(); i++){
      int aodcalojetindex = aodcalojet_list[i]; 
      OPT_AODCaloJetMedianLog10IPSig      .push_back(Shifted_CaloJetMedianLog10IPSig      .at(aodcalojetindex));
      OPT_AODCaloJetMedianLog10TrackAngle .push_back(Shifted_CaloJetMedianLog10TrackAngle .at(aodcalojetindex));
      OPT_AODCaloJetAlphaMax              .push_back(Shifted_CaloJetAlphaMax              .at(aodcalojetindex));
      
      OPT_AODCaloJetPt                     .push_back(AODCaloJetPt                     ->at(aodcalojetindex));
      OPT_AODCaloJetEta                    .push_back(AODCaloJetEta                    ->at(aodcalojetindex));
      OPT_AODCaloJetPhi                    .push_back(AODCaloJetPhi                    ->at(aodcalojetindex));
      OPT_AODCaloJet_emEnergyFraction      .push_back(AODCaloJet_emEnergyFraction      ->at(aodcalojetindex));
      OPT_AODCaloJet_energyFractionHadronic.push_back(AODCaloJet_energyFractionHadronic->at(aodcalojetindex));
      OPT_AODCaloJetID                     .push_back(AODCaloJetID                     ->at(aodcalojetindex));
     }}
  else{
    OPT_AODCaloJetMedianLog10IPSig       .push_back(-999);
    OPT_AODCaloJetMedianLog10TrackAngle  .push_back(-999);
    OPT_AODCaloJetAlphaMax               .push_back(-999);
    OPT_AODCaloJetPt                     .push_back(-999);
    OPT_AODCaloJetEta                    .push_back(-999);
    OPT_AODCaloJetPhi                    .push_back(-999);
    OPT_AODCaloJet_emEnergyFraction      .push_back(-999);   
    OPT_AODCaloJet_energyFractionHadronic.push_back(-999);
    OPT_AODCaloJetID                     .push_back(-999);
  } 
  if(electron_list.size()>0){
    for(int j = 0; j<electron_list.size(); j++){
      int ele_index = electron_list[j]; 
      OPT_AOD_elePt .push_back( AOD_elePt    ->at(ele_index)); 
      OPT_AOD_eleEta.push_back( AOD_eleEta   ->at(ele_index));  
      OPT_AOD_elePhi.push_back( AOD_elePhi   ->at(ele_index)); 
    }}
    else{
      OPT_AOD_elePt  .push_back(-999); 
      OPT_AOD_eleEta .push_back(-999);
      OPT_AOD_elePhi .push_back(-999); 
    }
}
//----------------------------clearOPTtree
void analyzer_tree::clearOPTtree(){

  //clear optimization arrays each new event
  OPT_Event                           .clear();
  OPT_Run                             .clear();
  OPT_Lumis                           .clear();

  OPT_EventWeight                     .clear();
  OPT_lumi_weight                     .clear();
  OPT_ele_weight                      .clear();
  OPT_mu_weight                       .clear();
  OPT_PU_weight                       .clear();
  
  OPT_ZPt                             .clear();
  
  OPT_nJets                           .clear();
  OPT_AODCaloJetMedianLog10IPSig      .clear();
  OPT_AODCaloJetMedianLog10TrackAngle .clear();
  OPT_AODCaloJetAlphaMax              .clear();
  OPT_AODCaloJetEta                   .clear();
  OPT_AODCaloJetPt                    .clear();
  OPT_AODCaloJetEta                   .clear();
  OPT_AODCaloJetPhi                   .clear();
  OPT_AODCaloJet_emEnergyFraction     .clear();
  OPT_AODCaloJet_energyFractionHadronic.clear();
  OPT_AODCaloJetID                    .clear();
  
  OPT_nAODEle                         .clear();
  OPT_AOD_elePt                       .clear();
  OPT_AOD_eleEta                      .clear();
  OPT_AOD_elePhi                      .clear();
}
