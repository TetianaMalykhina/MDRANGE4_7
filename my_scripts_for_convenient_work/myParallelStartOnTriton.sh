#!/bin/bash -l

###  (C) Tetiana Malykhina, 01 Apr 2023, tetiana.malykhina@aalto.fi

date
#sleep 1

echo "Start from  /scratch/work/malykht1/MD_calculations/Parallel/MD_4_7"
pwd
sleep 1

echo "How many parallel tasks do you need?"
read HowMany

for (( i=1; i <= $HowMany; i++ ))
     do
          echo "a new dir is tmp$i"
          mkdir tmp$i
          cp coords*  elstop*  myTask1ForArrayJobs.sh  param.in tmp$i
          cd tmp$i
          echo "start myTask1ForArrayJobs.sh  at $i node" 		
          sbatch myTask1ForArrayJobs.sh $i   	# (at Triton)
               ### ./myTask1ForArrayJobs.sh $i   	#  at local comp, for testing
                  
          cd ..
          
     done


#
ls -l
#

