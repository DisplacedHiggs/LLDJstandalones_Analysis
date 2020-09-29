#!/bin/bash 

echo "TEST"
voms-proxy-info --all
ls -l
echo "DONE"

outDir="root://cmseos.fnal.gov//store/user/ddiaz/OPT/Results_Sep2020/"

#export SCRAM_ARCH=slc6_amd64_gcc481; export CRAB_RUNTIME_TARBALL=local; export CRAB_TASKMANAGER_TARBALL=local; export _CONDOR_JOB_AD=Job.${1}.submit
#export CRAB3_RUNTIME_DEBUG=True
#tar xzmf CMSRunAnalysis.tar.gz
#cp Job.submit Job.${1}.submit
##source /cvmfs/cms.cern.ch/cmsset_default.sh
##export SCRAM_ARCH=slc6_amd64_gcc530
##tar -zxvf cms_setup.tar.gz
##cd CMSSW_8_1_0/src
##eval `scram runtime -sh`
##mkdir -p Results
##cp ../../taggerMicro.C .


#source /cvmfs/cms.cern.ch/cmsset_default.sh 
#scramv1 project CMSSW CMSSW_10_6_4 # cmsrel is an alias not on the workers
#ls -alrth
#cd CMSSW_10_6_4/src/
#eval `scramv1 runtime -sh` # cmsenv is an alias not on the workers
#echo $CMSSW_BASE "is the CMSSW we created on the local worker node"
#pwd
#mkdir -p Results
#cp ../../taggerMicro.C .


source /cvmfs/cms.cern.ch/cmsset_default.sh
export SCRAM_ARCH=slc7_amd64_gcc700
tar -zxvf cms_setup.tar.gz
cd CMSSW_10_6_4/src
eval `scram runtime -sh`
mkdir -p Results
cp ../../taggerMicro.C .

#root -l -b -q 'taggerSlim.C(0.4, -1.45, "2016", "DYJetsToLL_M-10to50_OPTtree.root")'
root -l -b -q "taggerMicro.C($1, $2, "'"'"$3"'"'", "'"'"$4"'"'")"

for FILE in *.txt
do
  echo "xrdcp -f ${FILE} ${outDir}/${FILE}"
  echo "${FILE}" 
  echo "${outDir}"
  xrdcp -f ${FILE} ${outDir}/${1}_${FILE} 2>&1
  XRDEXIT=$?
  if [[ $XRDEXIT -ne 0 ]]; then
    rm *.txt
    echo "exit code $XRDEXIT, failure in xrdcp"
    exit $XRDEXIT
  fi
  rm ${FILE}
done


#gfal-copy -f *.txt /uscms/home/ddiaz/nobackup/ANComments/OPT/Condor/FromCristian/Results/
#gfal-copy -f *.txt gsiftp://cmseos-gridftp.fnal.gov//store/user/ddiaz/OPT/Results_tf/.

#cp *.txt root://cmseos.fnal.gov//store/user/ddiaz/OPT/Results_Sep2020/.


