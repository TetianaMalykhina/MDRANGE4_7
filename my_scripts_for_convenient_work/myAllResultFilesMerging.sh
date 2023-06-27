#!/bin/bash -l

echo "merging *.txt results. Please, check directory names, and use this script"
###  (C) Tetiana Malykhina, 01 Apr 2023, tetiana.malykhina@aalto.fi
echo "How many parallel tasks did you run?"
read HowMany

touch All_ions.txt
touch BS_ions.txt
touch Max_Z_allBS.txt

echo "check  all *.txt filenames in tmp1 directory (for example)"
sleep 3

for (( i=1; i <= $HowMany; i++ ))
     do
          cat All_ions.txt tmp$i/ALL_sx_sy_sz_E_r.txt  >>  All_ions.txt
          cat BS_ions.txt tmp$i/BackScatteredIons.txt  >>  BS_ions.txt
          cat MaxZ_for_all_BS.txt tmp$i/MaxZ_for_all_BS.txt  >>  Max_Z_allBS.txt      
     done
#
#ls -l
# sleep $(($interval5))


