
     MDRANGE4.03
16 November 2022
(Release 03   MDRANGE4)

New features have been added

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



