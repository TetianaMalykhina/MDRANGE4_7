
     MDRANGE4.04
22 November 2022
(Release 03   MDRANGE4)

New features have been added 
	16Nov2022:  1) - 3) 
	22Dec2022:  4)

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
   

Output file format:
 N_Ion      X  Y  Z     Theta  Phii    Efinal  Rtotal     vx  vy  vz   TotFD   FDn  FDe

   N_Ion   is the current ion number (from 0 to Ntot-1)
   X Y Z   coordinates represent the last position of the ion (position in which this ion stops)
   Theta  Phii    are the initial direction of this ion  
   Efinal is the final ion's energy  
   Rtotal  is the total range of current ion along the trajectory  (it is Sum of small dx )

   TotFD    FDn    FDe    are  the Total deposited energy,  Nuclear deposited energy and Electronic deposited energy  

   vx  vy  vz    are components of the velocity vector of the ion
   
 
 HOW TO START:
   
   You have to use following command line to start calculation :
 
                    mdh  -BS -FD   



4) 22 Dec 2022  -  "the embarrassed parallelism"  was added 

   01) The possibility to use the program for calculations on the Triton cluster has been added.
   A delay of 1 or 2 seconds (sleep 1)  or (sleep 2) for starting jobs at different times was in rel. 0.1beta.
   You need a bash script for calculating using "the embarrassed parallelism", i.e., different tasks in different directories,
   and stert these tasks with sleep(1)  delay.
   The seed for a random number generator was calculated usint time(NULL).
   
   Unzip MDRANGE4_16Nov.zip  and use it instead of MDRANGE4,  it works!  
   But you have to use sleep(1)  and check if results are unique. Use a Python script (uniq_MD.py based on Dictionary in Python)
    
   
   
   02)
   Now we have a possibility to use "the embarrassed parallelism"  with another random seed.
   I use the copy number (the number of tmp* directory)  as a seed for the random number generator.
   I also use a bash script to create a command line parameter for the mdh program. 



