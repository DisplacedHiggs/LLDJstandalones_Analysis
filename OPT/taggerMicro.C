#include <iostream>
#include "TString.h"
#include "TH1F.h"
#include "TCanvas.h"
#include "THStack.h"
#include "TLegend.h"
#include "TPad.h"
#include "TStyle.h"
//#include "TTreeReader.h"
#include "TText.h"
#include <fstream>
#include "TFile.h"
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <cstdlib> /* mkdir */
#include <stdlib.h>     /* getenv */

using namespace std;

float ZPtSF (float ZPt, TString year, TString sample){
  float evt_wt = 1.0; 
if( sample.Contains("DYJetsToLL") ){
  if( year == "2016"){
    //std::cout<<"Year: "<<year<<"  ZPt: "<<ZPt<<" evt_wt: "<<evt_wt<<std::endl;
    if     (ZPt<10.)evt_wt*=1.05817;
    else if(ZPt<20.)evt_wt*=0.994488;
    else if(ZPt<30.)evt_wt*=0.930056;
    else if(ZPt<40.)evt_wt*=0.925206;
    else if(ZPt<50.)evt_wt*=0.946403;
    else if(ZPt<60.)evt_wt*=0.962136;
    else if(ZPt<70.)evt_wt*= 0.965316;
    else if(ZPt<80.)evt_wt*=0.978209;
    else if(ZPt<100.)evt_wt*=0.988761;
    else if(ZPt<150.)evt_wt*=0.982497;
    else if(ZPt<200.)evt_wt*= 0.971749;
    else if(ZPt<1000.)evt_wt*=0.914429;
  }
  else if (year == "2017" || year == "2018" ){
    //std::cout<<"Year: "<<year<<"  ZPt: "<<ZPt<<" evt_wt: "<<evt_wt<<std::endl;
    if     (ZPt<10.)evt_wt*=0.910385;
    else if(ZPt<20.)evt_wt*=1.13543;
    else if(ZPt<30.)evt_wt*=1.10441;
    else if(ZPt<40.)evt_wt*=1.01315;
    else if(ZPt<50.)evt_wt*=0.982598;
    else if(ZPt<60.)evt_wt*=0.980697;
    else if(ZPt<70.)evt_wt*= 0.972673;
    else if(ZPt<80.)evt_wt*=0.972325;
    else if(ZPt<100.)evt_wt*=0.966127;
    else if(ZPt<150.)evt_wt*=0.953262;
    else if(ZPt<200.)evt_wt*= 0.933403;
    else if(ZPt<1000.)evt_wt*=0.904518;
  }
  else evt_wt*=1.0;
}
  //std::cout<<"Year: "<<year<<"  ZPt: "<<ZPt<<" Final evt__wt: "<<evt_wt<<std::endl;
  return evt_wt;
}


void taggerMicro(Double_t c_ip, Double_t c_ta, TString year, TString sample){

  Double_t c_al;
  Double_t c_Zpt;
  //cout <<"(c_Zpt, c_ip, c_ta, c_al)=  "<<"("<<c_Zpt<<","<<c_ip<<","<<c_ta<<","<<c_al<<","<<")"<<endl;
  //cout <<"sample: "<<year+"_"+sample<<endl;
  
  TString nt, s_c_ip, s_c_ta, s_c_al, s_c_Zpt;
 
  s_c_ip.Form("%1.2f",c_ip);
  s_c_ta.Form("%1.2f",c_ta);
  const int N_Z = 1;
  const int N_AL = 11;
  double a_c_al[N_AL] = {0.0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0};
  double a_c_Zpt[N_Z] = {100.0};
  
  double MCSF = 1.0;
  double lumiSF = 1.0;
  // lumi 2016: 16226.2
  // lumi 2017: 41500.
  // lumi 2018: 59700.

  //------------------------
  //TTJETS SF
  //------------------------
  if (year == "2016" && ( sample.Contains("TTJets") || sample.Contains("TTtoLL") ) ) MCSF *= 1.0; // apply TTJets SF 2016
  if (year == "2017" && ( sample.Contains("TTJets") || sample.Contains("TTtoLL") ) ) MCSF *= 1.0; // apply TTJets SF 2017
  if (year == "2018" && ( sample.Contains("TTJets") || sample.Contains("TTtoLL") ) ) MCSF *= 1.0; // apply TTJets SF 2018
  //------------------------
  //Z->ee/mumu SF
  //------------------------
  if (year == "2016" && (sample.Contains("DYJetsToLL") || sample.Contains("HToSSTobbbb")) ) MCSF *= 1.05; // 0.8789170;    // apply DY SF 2016
  if (year == "2017" && (sample.Contains("DYJetsToLL") || sample.Contains("HToSSTobbbb")) ) MCSF *= 0.95; // 0.7388745;     // apply DY SF 2017
  if (year == "2018" && (sample.Contains("DYJetsToLL") || sample.Contains("HToSSTobbbb")) ) MCSF *= 0.95; // 0.7341290;        // apply DY SF 2018

  int Nbins = 6;
  TH1F* h_ntags      = new TH1F("h_ntags"      , "h_ntags"      , Nbins, -0.5, (float)(Nbins)-0.5);
  h_ntags->Sumw2();

  TString Path;
  if     (year=="2016") {lumiSF=(16165.4/20000.); Path = "root://cmsxrootd.fnal.gov///store/group/lpchbb/LLDJntuples/2016_LLDJ_V2p0/analyzed/2016JECV2p0_PreApp_JetPt35_MuTkTrigs/";  }
  else if(year=="2017") {lumiSF=(41544.3/20000.); Path = "root://cmsxrootd.fnal.gov///store/group/lpchbb/LLDJntuples/2017_LLDJ_V3p0/analyzed/2017JECV3p0_PreApp_JetPt35_OPT_kim/";  }
  else if(year=="2018") {lumiSF=(59697.1/20000.); Path = "root://cmsxrootd.fnal.gov///store/group/lpchbb/LLDJntuples/2018_LLDJ_V3p0/analyzed/2018JECV3p0_PreApp_JetPt35_OPT/";  }
  else if(year=="local"){ lumiSF=(/*20000.*/ 41500./20000.); Path = "./";}
  else std::cout <<"Bad Year"<<std::endl;
  std::cout <<"samples: "<<sample <<"   MCSF: "<< MCSF << " lumiSF: "  << lumiSF << std::endl;

  TString sampleName= sample;
  if(sampleName.Length()>10) sampleName.Remove(sampleName.Length()-5, sampleName.Length());
  ofstream ResFile;
  ResFile.open(year+"_"+sampleName+"_"+s_c_ip+"_"+s_c_ta+"_Results.txt");
  
  //----------
  //high_z_pt
  //----------
  vector<float> NTags          (Nbins,0);
  vector<float> NTagsError     (Nbins,0);
  vector<float> NTags_bare     (Nbins,0);
  //----------
  //low_z_pt
  //----------
  vector<float> NTags_low          (Nbins,0);
  vector<float> NTagsError_low     (Nbins,0);
  vector<float> NTags_bare_low     (Nbins,0);
      

  TString FileName = Path+sampleName+".root";
  TFile file;
  TFile* f2 = TFile::Open(FileName);
  
  for(int zz=0; zz<N_Z; zz++){//loop Zpt
    c_Zpt = a_c_Zpt[zz]; 
    for(int jj=0; jj<N_AL; jj++){//loopAlpha
      c_al = a_c_al[jj];
      
      double EW_2p = 0.0, EW_E2p = 0.0;
      double EW_2p_low = 0.0, EW_E2p_low = 0.0;
      NTags          .assign(Nbins,0.0);
      NTagsError     .assign(Nbins,0.0);
      NTags_bare     .assign(Nbins,0.0);
      //low-z-pt
      NTags_low          .assign(Nbins,0.0);
      NTagsError_low     .assign(Nbins,0.0);
      NTags_bare_low     .assign(Nbins,0.0);
  
      h_ntags->Reset();

 
      TTreeReader reader("MiniTree",f2);
      TTreeReaderValue<vector<int>>    Event(reader,       "Mini_Event"); // template type must match datatype
      TTreeReaderValue<vector<float>>  ZPt(reader,         "Mini_ZPt"); 
      TTreeReaderValue<vector<float>>  W_DEG(reader,       "Mini_FullWeightDEG"); 
      TTreeReaderValue<vector<float>>  W_DMu(reader,       "Mini_FullWeightDMu"); 
      TTreeReaderValue<vector<float>>  IP(reader,          "Mini_AODCaloJetMedianLog10IPSig");
      TTreeReaderValue<vector<float>>  TA(reader,          "Mini_AODCaloJetMedianLog10TrackAngle");
      TTreeReaderValue<vector<float>>  Alpha(reader,       "Mini_AODCaloJetAlphaMax");
      //int count = 0;
      while (reader.Next()) {
        for(int i = 0; i<Event->size(); i++){
          int tags = 0;
	  int ntag_low_zpt = 0;
          float ZSF = ZPtSF(ZPt->at(i), year, sample);

          for (int j=0; j<TA->size(); j++)
	    {
	      if(Alpha->at(j)<=c_al && IP->at(j)>=c_ip && TA->at(j)>=c_ta && Alpha->at(j)>=0.0 && ZPt->at(i)>=c_Zpt ) tags = tags + 1;
	      if(Alpha->at(j)<=c_al && IP->at(j)>=c_ip && TA->at(j)>=c_ta && Alpha->at(j)>=0.0 && ZPt->at(i) < c_Zpt ) ntag_low_zpt = ntag_low_zpt+1;
	    }
	  double full_weight     = ZSF*lumiSF*W_DEG->at(i)*W_DMu->at(i);//full-weight;

          if(tags<Nbins && ZPt->at(i)>=c_Zpt)//avoid o-tag bing to always count regardless of Z-pt
	    {
	      NTags_bare      [tags]   = NTags_bare[tags]      + 1;                     //count raw mc events
	      NTags           [tags]   = NTags[tags]           + full_weight;           //full weight
	      NTagsError      [tags]   = NTagsError[tags]      + pow(full_weight,2.0);  //full weight
	    }

	  if(ntag_low_zpt<Nbins && ZPt->at(i) < c_Zpt)//avoid o-tag bing to always count regardless of Z-pt
	    {
	      NTags_bare_low      [ntag_low_zpt]   = NTags_bare_low[ntag_low_zpt]      + 1;                   //count raw mc events
              NTags_low           [ntag_low_zpt]   = NTags_low[ntag_low_zpt]           + full_weight;         //full weight
              NTagsError_low      [ntag_low_zpt]   = NTagsError_low[ntag_low_zpt]      + pow(full_weight,2.0);//full weight
	    }
        }
        
      //count = count +1;
      //      if (count ==10) break;
      }//end event loop

      for(int nn =0; nn<NTags_bare.size(); nn++){
	h_ntags->SetBinContent(nn+1,NTags_bare[nn]);
      }
      for (int l = 2; l<Nbins; l++){
        EW_2p           += NTags[l];         //full weight
        EW_E2p          += NTagsError[l];    //full weight
	EW_2p_low       += NTags_low[l];     //full weight
        EW_E2p_low      += NTagsError_low[l];//full weight
     }
  
      s_c_al.Form("%1.2f",c_al);
      s_c_Zpt.Form("%1.2f",c_Zpt);
     
  
      //-----------------
      //comput generic TF
      //-----------------
      double tf[3];
      double tf_err[3];
      for(int i_tf = 0; i_tf < 3; i_tf++)
	{
	  tf[i_tf] = NTags[i_tf]/NTags_low[i_tf];
	  tf_err[i_tf]   = sqrt(pow(tf[i_tf],2.0)*(NTagsError[i_tf]/pow(NTags[i_tf],2.0)+NTagsError_low[i_tf]/pow(NTags_low[i_tf],2.0)));
	  if( i_tf == 2 )
	    {
	      tf[i_tf] = EW_2p/EW_2p_low;
	      tf_err[i_tf]   = sqrt(pow(tf[i_tf],2.0)*(EW_E2p/pow(EW_2p,2.0)+EW_E2p_low/pow(EW_2p_low,2.0)));
	    }
	}


      ResFile <<FileName<<"  "<<c_Zpt<<"  "<<" "<<c_ip<<" "<<c_ta<<" "<<c_al<<" "<< NTags_bare[0] << " " 
	      <<NTags     [0]<<" "<<sqrt(NTagsError[0])       <<" "
	      <<NTags_low [0]<<" "<<sqrt(NTagsError_low[0])       <<" "
	      <<NTags     [1]<<" "<<sqrt(NTagsError[1])       <<" "
	      <<NTags_low [1]<<" "<<sqrt(NTagsError_low[1])       <<" "
	      <<EW_2p        <<" "<<sqrt(EW_E2p)              <<" "
	      <<EW_2p_low    <<" "<<sqrt(EW_E2p_low)              <<" "
	      <<tf [0]       <<" "<< tf_err[0]                <<" "
	      <<tf [1]       <<" "<< tf_err[1]                <<" "
	      <<tf [2]       <<" "<< tf_err[2]                <<" "
	      <<endl;
    }//c_al loop
  }//c_ZPt loop
  
  f2->Close();
  ResFile.close();
}


//./taggerMicro.exe 1.1  -1.2 2016 2017_DYJetsToLL_M-50_OPTtree.root
//int main (int argc, char *argv[]){
//	std::cout<<argv[0]<<std::endl;
//	std::cout<<argv[1]<<std::endl;
//	std::cout<<argv[2]<<std::endl;
//	std::cout<<argv[3]<<std::endl;
//	std::cout<<argv[4]<<std::endl;
//
//	return 0;
//}
