#include "analyzer_config.h"

//----------------------------analyzer_config
analyzer_config::analyzer_config() 
{
}

//----------------------------~analyzer_config
analyzer_config::~analyzer_config()
{
}


//----------------------------analyzer_config
void analyzer_config::setConfiguration() 
{
 //set TTOC in config.h
 if(TTOC){            // loggit
  pho_minPt  = 1.;    // loggit
  pho_maxEta = 3.;    // loggit
  ele_minPt1 = 2.;    // loggit
  ele_minPt2 = 1.;    // loggit
  ele_maxEta = 3.;    // loggit
  mu_minPt1  = 2.;    // loggit
  mu_minPt2  = 1.;    // loggit
  mu_maxEta  = 3.;    // loggit
  jet_minPt  = 25.;   // loggit
  jet_maxEta = 2.4;   // loggit
 }                    // loggit
 else{                // loggit
  pho_minPt  = 175.;  // loggit
  pho_maxEta = 1.4442;// loggit
  ele_minPt1 = 25.;   // loggit
  ele_minPt2 = 15.;   // loggit
  ele_maxEta = 2.5;   // loggit
  mu_minPt1  = 25.;   // loggit
  mu_minPt2  = 12.;   // loggit
  mu_maxEta  = 2.4;   // loggit
  jet_minPt  = 25.;   // loggit
  jet_maxEta = 2.4;   // loggit    
 }                    // loggit

 // tagging variables   // loggit
 //%TF unc WP   80        70     60     100    80     ZD_WP1 // loggit                
 tag_maxAmax  = 0.9 ; //  0.5 ;  0.5 ;  0.6 ;  0.9 ;  0.4;   // loggit
 tag_minIPsig = 1.15; //  0.5 ;  0.5 ;  1.15;  1.15;  1.25;  // loggit
 tag_minTA    =-1.5 ; // -1.5 ; -1.5 ; -1.5 ; -1.5 ; -1.75;  // loggit

 // shifted tagging variables              // loggit
 // %TF unc WP         80         70       60       100      80      ZD_WP1                
 tag_shiftmaxAmax   =  0.909; //  0.505 ;  0.505 ;  0.606 ;  0.909 ; 0.404;    // loggit
 tag_shiftminIPsig  =  1.238; //  0.538 ;  0.538 ;  1.238 ;  1.238 ; 1.346;    // loggit
 tag_shiftminTA     = -1.516; // -1.516 ; -1.516 ; -1.516 ; -1.516 ;-1.769;    // loggit

 // set which collections                          // loggit 
// phoid = "Medium"; // "Tight"; "Loose"; //Medium"; // loggit 
 eleid = "Loose";  // "Tight"; "Loose"; //Medium"; // loggit 
 muoid = "Loose";  // "Tight"; "Loose"; //Medium"; // loggit 
 jetid = "Loose";  // "Tight"; "Loose";            // loggit 

 jetmatchdRcut = 0.4; // loggit
 objcleandRcut = 0.4; // loggit

// if (phoid = "Loose")  phoidbit=0;
// if (phoid = "Medium") phoidbit=1;
// if (phoid = "Tight")  phoidbit=2;

 if (eleid == "Loose")  eleidbit=0;
 if (eleid == "Medium") eleidbit=1;
 if (eleid == "Tight")  eleidbit=2;

 if (jetid == "Loose")  aodcalojetidbit=0;
 if (jetid == "Tight")  aodcalojetidbit=1;

 //printf("setting config\n");

}

void analyzer_config::initSelectionCategories( ){

  // Make sure that the numbers in here  match
  // static const int SELBINNAMESIZE  = 20;
  // static const int JETMULTNAMESIZE = 5; 
  // static const int LEPBINNAMESIZE  = 3;
  // initialize names
  jetmultnames.clear();
  jetmultnames.push_back("LeadingJet");
  jetmultnames.push_back("SubleadingJet");
  jetmultnames.push_back("ThirdJet");
  jetmultnames.push_back("FourthJet");
  jetmultnames.push_back("AllJets");

  tagmultnames.clear();
  tagmultnames.push_back("LeadingTag");
  tagmultnames.push_back("SubleadingTag");
  tagmultnames.push_back("ThirdTag");
  tagmultnames.push_back("FourthTag");
  tagmultnames.push_back("AllTags");

  selbinnames.clear();
  selbinnames.push_back("OneEleSig");
  selbinnames.push_back("TwoEleSig");
  selbinnames.push_back("OneMuSig");
  selbinnames.push_back("TwoMuSig");
  selbinnames.push_back("OneEleDY");
  selbinnames.push_back("TwoEleDY");
  selbinnames.push_back("OneMuDY");
  selbinnames.push_back("TwoMuDY");
  selbinnames.push_back("OneEleZH");
  selbinnames.push_back("TwoEleZH");
  selbinnames.push_back("OneMuZH");
  selbinnames.push_back("TwoMuZH");
  selbinnames.push_back("OneEleOffZ");
  selbinnames.push_back("TwoEleOffZ");
  selbinnames.push_back("OneMuOffZ");
  selbinnames.push_back("TwoMuOffZ");
  selbinnames.push_back("OneEleNoPair");
  selbinnames.push_back("OneMuNoPair");
  selbinnames.push_back("EleMuOSOF");
  selbinnames.push_back("OnePho");
  selbinnames.push_back("EleMuOSOFL");

}

Bool_t analyzer_config::doTTOC(){
  return TTOC;
}
