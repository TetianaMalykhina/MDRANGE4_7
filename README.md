

  The source code:  MDRANGE3,   https://gitlab.com/acclab/MDRANGE
  
  http://beam.helsinki.fi/~knordlun/mdh/mdh_program_nolinks.html
  
  http://beam.helsinki.fi/~knordlun/mdh/mdh_captions.ps
  
  
  Authors of the program V1.0 - V1.83b
  Kai Nordlund
  Accelerator Laboratory, University of Helsinki, P.O. BOX 43, FIN-00014 Helsinki, Finland
  (email kai.nordlund@helsinki.fi)

  Author of the user interface & some minor modifications
  Jussi Sillanpää, jksillan@vesuri.helsinki.fi
  September 1, 1994
 

  Author of the program development from V1.X -> V3.0
  Jarkko Peltola, jypeltol@beam.helsinki.fi
 
  Last major update: Jarkko Peltola and Kai Nordlund, August 2003. Minor update (-recspec option) Kai Nordlund, July 28, 2003.


//--------------------------------------
  Some minor modifications (2022-2023) : 
  
   Tetiana Malykhina,  
   
   September, 2022 - May 2023  (options:  -BS   -fullTrajectories  and some other options )
        
         tetiana.malykhina@aalto.fi                
                    

   	     MDRANGE4_7
 
 
New features have been added 
	16Nov2022:  1) - 3) 
	22Dec2022:  4)
	April 2023  5)

1) Information about backscattered ions can be printed in a separate file    (Tetiana)
   "BackscatteredIons.txt"
   
   
2) Full trajectories of backscattered ions are stored in *.txt files   (Tetiana)
 
    The file names have the following format: 
                  BS_ion.XXX 
    where XXX is the serial number of the backscattered ion. 

   You have to use following command line to start calculation :
 
                    mdh  -BS
                    
 (other options are possible if you need additional information provided by MDRANGE3 ) 



3)  02 Nov  2022  (Tetiana):
   The total nuclear deposited energy  (FDn) and electronic deposited energy (FDe)  for backscattered ions 
   were added to output file for the stopped ions in case they stopped before the target, i.e., they were backscattered.
   
   The current  ion number  was also added.
   
 
   TotFD    FDn    FDe    are  the Total deposited energy,  Nuclear deposited energy and Electronic deposited energy 

   
   


4) 22 Dec 2022  -  "the embarrassed parallelism"  was added

   4.01) The possibility to use the program for calculations on the Triton cluster has been added.
   A delay of 1 or 2 seconds (sleep 1)  or (sleep 2) for starting jobs at different times was in rel. 0.1beta.
   You need a bash script for calculating using "the embarrassed parallelism", i.e., different tasks in different directories,
   and stert these tasks with sleep(1)  delay.
   The seed for a random number generator was calculated usint time(NULL).
   
   Unzip MDRANGE4_16Nov.zip  and use it instead of MDRANGE4,  it works! 
   But you have to use sleep(1)  and check if results are unique. Use a Python script (uniq_MD.py based on Dictionary in Python)
    
   
   
   4.02)
   Now we have a possibility to use "the embarrassed parallelism"  with another random seed.
   I use the copy number (the number of tmp* directory)  as a seed for the random number generator.
   I also use a bash script to create a command line parameter for the mdh program. 




5)   April 2023  ( ~  +- )
     The possibility to save (or not to save) whole trajectories  (using   -fullTrajectories  option)     was added
     
     $HOME/MDRANGE4_7/bin/mdh -BS -FD -fullTrajectories -o out


     How to run on  the Triton cluster:
	use bash scripts to start your calculation:


 	5.1.  Bash scripts    "myParallelStartOnTriton.sh" ,   "myTask1ForArrayJobs.sh" ,   "myAllResultFilesMerging.sh"   will be useful.
 	      (or you can use your own scripts)
 	
 	
 	      ./myParallelStartOnTriton.sh       ( asks you a number of tasks. Please, use not more than 500 )
 	                                              use 
 	                                                     slurm queue
 	                                              to check your tasks
 	                                              
 	     myTask1ForArrayJobs.sh      starts one task
 	     mymyAllResultFilesMerging.sh    merges all results (from different directories)
 	     
 	     
	
            



     Please, read  "How_to_start.txt" file

       Download from gitlab    (github)

2) Unpack
    now you have:
        /mdrange/bin        (pre-compiled executables)
        /mdrange/data       (data files needed for zbl96 and mdsetup)
        /mdrange/examples   (examples)
        /mdrange/documentation
        /mdrange/mdh        (source files)

        ...
        
        
3) /mdrange readme.install   tell us about the installation process,

    You have to edit 'config'-file, i.e.,   $HOME/MDRANGE4/config
    (if you unpacked *.zip archive into $HOME directory)

    nano $HOME/MDRANGE4.config

   You should use the following:
   #
   COMPILER=cc
   FLADG = -DLinux -fPIE
   # (for dynamicaly linked library)
   # it has been done  by default  in MDRANGE4


4)      cd $HOME/MDRANGE4
        chmod +x writeheader


5)      make clean


6)      make

wait, and
 check $HOME/MDRANGE4/bin  directory 
 It contains new files:
        zbl96
        mdsetup
        mdhreed
        mdh


NOTE :
This version, MDRANGE4_7,  is implemented for the Triton HPC cluster to run in a "pseudo-parallel" mode using some bash scripts.





