

02 Nov  2022  (Tetiana):
   The total nuclear deposited energy  (FDn) and electronic deposited energy (FDe)  for backscattered ions were added to output file for the stopped ions in case they stopped before the target, i.e., they were backscattered.
The current  ion number  was also added.

Output file format:
N_Ion      X  Y  Z     Theta  Phii    Efinal  Rtotal     vx  vy  vz   TotFD   FDn  FDe

N_Ion   is the current number of ion (from 0 to Ntot-1)
X Y Z      =  the last position  (position in which this ion stops)
Theta  Phii    are the initial direction of this ion    
TotFD    FDn    FDe    are  the Total deposited energy,  Nuclear deposited energy and Electronic deposited energy  
Rtotal  is the total range of current ion along the trajectory  (it is Sum of small dx )
vx  vy  vz    are components of the velocity vector of the ion
