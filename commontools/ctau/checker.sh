Finished="Normal termination"
sum=0
for file in log/*
do
  if  grep -qs $Finished ${file}; then
    ((sum += 1))
  fi
  #echo $file 
done
echo $sum
