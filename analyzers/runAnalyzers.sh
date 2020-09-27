#!/bin/bash

year="2016"
listDir=""
 if [[ $year == "2016" ]]; then
    listDir="/2016_lists"
 elif [[ $year == "2017" ]]; then
    listDir="/2017_lists"
 elif [[ $year == "2018" ]]; then
    listDir="/2018_lists"
 else
    listDir=""
 fi

for sample in \
 "DYJetsToLL_M-50"  \
 #"2017_DYJetsToLL_M-50"  \

do
##  ./runanalyzer.exe -s ${sample} -l "20000" -x "" -e "-1" -i "../lists" -o "junk" -n 999999999 -a 1 -d -m
  ./runanalyzer.exe -s ${sample} -l "20000" -x "" -e "5000" -i "../lists"$listDir -o "junk" -n 1 -a 1 -y $year -d -m

done #for sample in DY50..

for sample in \
"Data_DoubleMu_H"    \
#"Data_EGamma_D"    \
#"Data_DoubleMuon_A_short"    \
 #"2016_Data_DoubleMuon_H"    \
 #"2016_Data_DoubleEG_H"    \

do
  ./runanalyzer.exe -s ${sample} -l "20000" -x "" -e "1000" -i "../lists"$listDir -o "junk" -n 1 -a 1 -y $year -d
done # for datasample               
