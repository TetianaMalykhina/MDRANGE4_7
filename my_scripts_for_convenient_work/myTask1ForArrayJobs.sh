#!/bin/bash -l
#SBATCH --time=119:00:00
#SBATCH --mem-per-cpu=2G
###  (C) Tetiana Malykhina, 01 Apr 2023, tetiana.malykhina@aalto.fi  
~/NuME/MDRANGE4_7/bin/mdh -BS -FD  -o outSerial -Triton $1 	# $1 is the first parameter in a command line for start "myTask1ForArrayJobs.sh"  , 
                                                                # it comes from "myParallelStartOnTriton.sh"  script

### ~/NuME/MDRANGE4_7/bin/mdh -BS -FD  -fullTrajectories  -o outSerial  -Triton $1  	### if we need whole trajectories stored in a *.txt files 


### ~/NuMElab/MDRANGE4/bin/mdh -BS -FD -o outSerial -Triton $1     # for local testing (using comp in my office)
