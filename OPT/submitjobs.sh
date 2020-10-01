
doSubmit=true

c_ip=(0.5 0.75 0.9 1.0 1.15 1.25 1.5 1.75 2.0 2.5 2.75)
c_ta=(-3.0 -2.5 -2.25 -2.10 -2.0 -1.9 -1.75 -1.5 -1.25 -1.0 -0.75)

samples_16=( \ 
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-1000_OPTtree.root"   \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-100_OPTtree.root"   \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-10_OPTtree.root"   \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-1_OPTtree.root"   \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-1000_OPTtree.root"   \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-100_OPTtree.root"   \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-10_OPTtree.root"   \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-1_OPTtree.root"   \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-1000_OPTtree.root"   \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-100_OPTtree.root"   \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-10_OPTtree.root"   \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-1_OPTtree.root"   \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-1000_OPTtree.root"   \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-100_OPTtree.root"   \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-10_OPTtree.root"   \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-1_OPTtree.root"   \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-1000_OPTtree.root"   \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-100_OPTtree.root"   \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-10_OPTtree.root"   \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-1_OPTtree.root"   \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-1000_OPTtree.root"   \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-100_OPTtree.root"   \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-10_OPTtree.root"   \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-1_OPTtree.root"   \
 "DYJetsToLL_M-50_OPTtree.root"   \
 "QCD_HT1000to1500_OPTtree.root"   \
 "QCD_HT100to200_OPTtree.root"   \
 "QCD_HT1500to2000_OPTtree.root"   \
 "QCD_HT2000toInf_OPTtree.root"   \
 "QCD_HT200to300_OPTtree.root"   \
 "QCD_HT300to500_OPTtree.root"   \
 "QCD_HT500to700_OPTtree.root"   \
 "QCD_HT700to1000_OPTtree.root"   \
 "ST_s-channel_4f_leptonDecays_OPTtree.root"   \
 "ST_t-channel_antitop_4f_inclusiveDecays_OPTtree.root"   \
 "ST_t-channel_top_4f_inclusiveDecays_OPTtree.root"   \
 "ST_tW_antitop_5f_NoFullyHadronicDecays_OPTtree.root"   \
 "ST_tW_top_5f_NoFullyHadronicDecays_OPTtree.root"   \
 "TTJets_OPTtree.root"   \
 "TTtoLL_OPTtree.root"   \
 "TTtoLfromT_OPTtree.root"   \
 "TTtoLfromTbar_OPTtree.root"   \
 "WGToLNuG_OPTtree.root"   \
 "WJetsToLNu_OPTtree.root"   \
 "WW_OPTtree.root"   \
 "WZ_OPTtree.root"   \
 "ZGTo2LG_OPTtree.root"   \
 "ZH_HToBB_ZToLL_OPTtree.root"   \
 "ZZ_OPTtree.root"   \
 "ggZH_HToBB_ZToLL_OPTtree.root"   \
 #"mad_DYJetsToLL_M-50_OPTtree.root"  \
# "ZZTo2L2Nu_OPTtree.root"   \
# "ZZTo2L2Q_OPTtree.root"   \
# "ZZTo2Q2Nu_OPTtree.root"   \
# "ZZTo4L_OPTtree.root"   \
# "WZTo1L3Nu_OPTtree.root"   \
# "WZTo3LNu_OPTtree.root"   \
# "WZToLNu2QorQQ2L_OPTtree.root"   \
# "WWTo2L2Nu_OPTtree.root"   \
# "WWToLNuQQ_OPTtree.root"   \
) 

samples_17=( \ 
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-1000_OPTtree.root"   \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-100_OPTtree.root"   \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-10_OPTtree.root"   \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-1_OPTtree.root"   \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-1000_OPTtree.root"   \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-100_OPTtree.root"   \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-10_OPTtree.root"   \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-1_OPTtree.root"   \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-1000_OPTtree.root"   \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-100_OPTtree.root"   \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-10_OPTtree.root"   \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-1_OPTtree.root"   \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-1000_OPTtree.root"   \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-100_OPTtree.root"   \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-10_OPTtree.root"   \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-1_OPTtree.root"   \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-1000_OPTtree.root"   \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-100_OPTtree.root"   \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-10_OPTtree.root"   \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-1_OPTtree.root"   \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-1000_OPTtree.root"   \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-100_OPTtree.root"   \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-10_OPTtree.root"   \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-1_OPTtree.root"   \
 "DYJetsToLL_M-50_OPTtree.root"   \
 "QCD_HT100to200_OPTtree.root"   \
 "QCD_HT1500to2000_OPTtree.root"   \
 "QCD_HT2000toInf_OPTtree.root"   \
 "QCD_HT200to300_OPTtree.root"   \
 "QCD_HT300to500_OPTtree.root"   \
 "QCD_HT500to700_OPTtree.root"   \
 "QCD_HT700to1000_OPTtree.root"   \
 "ST_s-channel_4f_leptonDecays_OPTtree.root"   \
 "ST_t-channel_antitop_4f_inclusiveDecays_OPTtree.root"   \
 "ST_t-channel_top_4f_inclusiveDecays_OPTtree.root"   \
 "ST_tW_antitop_5f_NoFullyHadronicDecays_OPTtree.root"   \
 "ST_tW_top_5f_NoFullyHadronicDecays_OPTtree.root"   \
 "TTJets_OPTtree.root"   \
 "TTtoLL_OPTtree.root"   \
 "WGToLNuG_OPTtree.root"   \
 "WJetsToLNu_OPTtree.root"   \
 "WW_OPTtree.root"   \
 "WZ_OPTtree.root"   \
 "ZGTo2LG_OPTtree.root"   \
 "ZH_HToBB_ZToLL_OPTtree.root"   \
 "ZZ_OPTtree.root"   \
 "ggZH_HToBB_ZToLL_OPTtree.root"   \
) 

samples_18=( \ 
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-1000_OPTtree.root"   \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-100_OPTtree.root"   \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-10_OPTtree.root"   \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-1_OPTtree.root"   \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-1000_OPTtree.root"   \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-100_OPTtree.root"   \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-10_OPTtree.root"   \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-1_OPTtree.root"   \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-1000_OPTtree.root"   \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-100_OPTtree.root"   \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-10_OPTtree.root"   \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-1_OPTtree.root"   \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-1000_OPTtree.root"   \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-100_OPTtree.root"   \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-10_OPTtree.root"   \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-1_OPTtree.root"   \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-1000_OPTtree.root"   \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-100_OPTtree.root"   \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-10_OPTtree.root"   \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-1_OPTtree.root"   \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-1000_OPTtree.root"   \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-100_OPTtree.root"   \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-10_OPTtree.root"   \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-1_OPTtree.root"   \
 "DYJetsToLL_M-50_OPTtree.root"   \
 "QCD_HT1000to1500_OPTtree.root"   \
 "QCD_HT100to200_OPTtree.root"   \
 "QCD_HT1500to2000_OPTtree.root"   \
 "QCD_HT2000toInf_OPTtree.root"   \
 "QCD_HT200to300_OPTtree.root"   \
 "QCD_HT300to500_OPTtree.root"   \
 "QCD_HT500to700_OPTtree.root"   \
 "QCD_HT700to1000_OPTtree.root"   \
 "ST_s-channel_4f_leptonDecays_OPTtree.root"   \
 "ST_t-channel_antitop_4f_inclusiveDecays_OPTtree.root"   \
 "ST_t-channel_top_4f_inclusiveDecays_OPTtree.root"   \
 "ST_tW_antitop_5f_NoFullyHadronicDecays_OPTtree.root"   \
 "ST_tW_top_5f_NoFullyHadronicDecays_OPTtree.root"   \
 "TTJets_OPTtree.root"   \
 "TTtoLL_OPTtree.root"   \
 "WGToLNuG_OPTtree.root"   \
 "WJetsToLNu_OPTtree.root"   \
 "WW_OPTtree.root"   \
 "WZ_OPTtree.root"   \
 "ZGTo2LG_OPTtree.root"   \
 "ZH_HToBB_ZToLL_OPTtree.root"   \
 "ZZ_OPTtree.root"   \
 "ggZH_HToBB_ZToLL_OPTtree.root"   \
 #"mad_DYJetsToLL_M-50_OPTtree.root"   \
 #"TTtoLL_mad_OPTtree.root"   \
 #"mad_TTJets_OPTtree.root"   \
) 
#make directories
#rm -rf err
#rm -rf out
#rm -rf log
mkdir -p err
mkdir -p out
mkdir -p log

for y in {0..2} #Loop through years
do
  #echo Year $y
  if [ $y == 0 ]
  then
    year="2016"
    samples=("${samples_16[@]}")
  elif [ $y == 1 ] 
  then
    samples=("${samples_17[@]}")
    year="2017"
  else  
    samples=("${samples_18[@]}")
    year="2018"
  fi

  for sample in ${samples[@]} 
  do
     # write base for submit file
     printf "Universe = vanilla\n" > submitfile
     printf "Executable = run_job.sh\n" >> submitfile
     printf "Should_Transfer_Files = YES \n" >> submitfile
     #printf "Transfer_Output_Files = *.txt\n" >> submitfile
     printf "WhenToTransferOutput = ON_EXIT\n" >> submitfile
     printf "Transfer_Input_Files = taggerMicro.C, cms_setup.tar.gz\n" >> submitfile
     printf "notify_user = $(whoami)@cern.ch\n" >> submitfile
     printf "x509userproxy = \$ENV(X509_USER_PROXY)\n" >> submitfile
     printf "\n" >> submitfile
     printf "Output = out/OPT.\$(Cluster)_\$(Process).stdout\n" >> submitfile
     printf "Error  = err/OPT.\$(Cluster)_\$(Process).stderr\n" >> submitfile
     printf "Log    = log/OPT.\$(Cluster)_\$(Process).log\n" >> submitfile
     printf "\n" >> submitfile
     printf "RequestMemory = 2000\n" >> submitfile
    for i in {0..10} #c_ip
    do
      for j in {0..10} #c_ta
      do
         printf "\n" >> submitfile
         printf "Arguments = ${c_ip[i]} ${c_ta[j]} ${year} ${sample}\n" >>submitfile
         printf "Queue\n">>submitfile
      done
    done
    echo made file for ${year} ${sample}    
    #submit job
    if [ ${doSubmit} = true ]
    then
     condor_submit submitfile
    fi
  done
done

