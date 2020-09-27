
#ifndef analyzer_createobjects_h
#define analyzer_createobjects_h

#include "analyzer_config.h"

class analyzer_createobjects : public analyzer_config {


public :

                  analyzer_createobjects();
   virtual        ~analyzer_createobjects(); 

 // object IDs and selections
 std::vector<int>     electron_passID   ( int bitnr, Float_t elePtCut1, Float_t elePtCut2, Float_t eleEtaCut, TString sysbinname="");
 std::vector<int>     muon_passID       ( int bitnr, Float_t muPtCut1 , Float_t muPtCut2 , Float_t muEtaCut , TString sysbinname="");
 std::vector<int>     jet_passID        ( int bitnr, TString jettype, Float_t jetPtCut, Float_t jetEtaCut, TString sysbinname="");
 std::vector<int>     jet_passTagger       ();
 std::vector<int>     jet_passTagger_L1PF  ();
 std::vector<int>     jet_passTaggerSB1    ();
 std::vector<int>     jet_passTaggerSB2    ();
 std::vector<int>     jet_passTaggerSB3    ();
 std::vector<int>     jet_passTaggerSB4    ();
 std::vector<int>     jet_passTaggerSB5    ();
 std::vector<int>     jet_passTaggerSB6    ();
 std::vector<int>     jet_passTaggerSB7    ();
 std::vector<int>     jet_passTaggerSBL1    ();
 std::vector<int>     jet_passTaggerSBL2    ();
 std::vector<int>     jet_passTaggerSBL3    ();
 std::vector<int>     jet_passTaggerSBL4    ();
 std::vector<int>     jet_passTaggerSBL5    ();
 std::vector<int>     jet_passTaggerSBL6    ();
 std::vector<int>     jet_passTaggerSBL7    ();

 std::vector<int>     jet_passTaggerSB2a    ();
 std::vector<int>     jet_passTaggerSB2b    ();
 std::vector<int>     jet_passTaggerSB2c    ();
 std::vector<int>     jet_passTaggerIP      ();
 std::vector<int>     jet_passTaggerSBIPa    ();
 std::vector<int>     jet_passTaggerSBIPb    ();
 std::vector<int>     jet_passTaggerSBIPc    ();

 bool AL_SB(int i);
 bool IP_SB(int i);
 bool IP_SBa(int i);
 bool IP_SBb(int i);
 bool IP_SBc(int i);
 bool TA_SB(int i);
 bool AL_SBL(int i);
 bool IP_SBL(int i);
 bool TA_SBL(int i);
 bool AL_SG(int i);
 bool IP_SG(int i);
 bool TA_SG(int i);

 std::vector<float>     jet_minDR              ();

 // make dilepton pair, pass by reference
 virtual void     makeDilep(TLorentzVector *fv_1, TLorentzVector *fv_2,
                            TLorentzVector *fv_ee, TLorentzVector *fv_mm);
 virtual void     makeDilep(TLorentzVector *fv_1, TLorentzVector *fv_2, TLorentzVector *fv_em);
 double        dR(double eta1, double phi1, double eta2, double phi2);
 double        DeltaPhi(double phi1, double phi2);

 // get (smeared) object pt
 Float_t       getElectronPt(int i, TString sysbinname);
 Float_t       getMuonPt(int i, TString sysbinname);

// Float_t       getMET();

 virtual void  shiftCollections(TString uncbin);
 virtual void  calculateHT();
 virtual void  makeDiLepton();
};

#endif
