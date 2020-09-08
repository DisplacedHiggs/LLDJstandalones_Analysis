#!/bin/bash 

echo "TEST"
voms-proxy-info --all
ls -l
echo "DONE"
outDir="root://cmseos.fnal.gov//store/group/lpchbb/LLDJntuples/2018_LLDJ_V3p0/SignalSplit/"
#outDir="root://cmseos.fnal.gov//store/group/lpchbb/LLDJntuples/2017_ctauReweightTest/"
#outDir="root://cmseos.fnal.gov//store/group/lpchbb/LLDJntuples/2018_ctauReweightTest/"
echo output directory, $outDir

source /cvmfs/cms.cern.ch/cmsset_default.sh
export SCRAM_ARCH=slc7_amd64_gcc700
tar -zxvf cms_setup.tar.gz
cd CMSSW_10_6_4/src
eval `scram runtime -sh`
cp ../../SignalSplit.exe .
cp ../../*.list .

echo "doing pwd"
pwd
echo "doing ls"
ls
echo "doing ls ../../"
ls ../../
echo "now run"
echo ./SignalSplit.exe --input_list=$1 --name=$2
./SignalSplit.exe --input_list=$1 --name=$2
echo "after run ls"
ls

for FILE in *.root
do
  echo "xrdcp -f ${FILE} ${outDir}/${FILE}"
  echo "${FILE}" 
  echo "${outDir}"
  xrdcp -f ${FILE} ${outDir}/${1}_${FILE} 2>&1
  XRDEXIT=$?
  if [[ $XRDEXIT -ne 0 ]]; then
    rm *.root
    echo "exit code $XRDEXIT, failure in xrdcp"
    exit $XRDEXIT
  fi
  rm ${FILE}
done


#gfal-copy -f *.txt /uscms/home/ddiaz/nobackup/ANComments/OPT/Condor/FromCristian/Results/
#gfal-copy -f *.txt gsiftp://cmseos-gridftp.fnal.gov//store/user/ddiaz/OPT/Results_tf/.



