#include "common.h"

/*
   Subroutines to create uniform and gaussian distributed random numbers
   The routines are taken from old MOLDY fortran subroutines (thus the goto).
   The subroutine should first once be called with a seed number, after
   that with the value zero as the argument.

   Kai N: as of mdh V3.04 Mar 15 2009 replaced ancient bad RNG with Mersenne
   twister, only modifying calling routine to be similar to before.


*/

/* A C-program for MT19937: Real number version                */
/*   genrand() generates one pseudorandom real number (double) */
/* which is uniformly distributed on [0,1]-interval, for each  */
/* call. sgenrand(seed) set initial values to the working area */
/* of 624 words. Before genrand(), sgenrand(seed) must be      */
/* called once. (seed is any 32-bit integer except for 0).     */
/* Integer generator is obtained by modifying two lines.       */
/*   Coded by Takuji Nishimura, considering the suggestions by */
/* Topher Cooper and Marc Rieffel in July-Aug. 1997.           */

/* This library is free software; you can redistribute it and/or   */
/* modify it under the terms of the GNU Library General Public     */
/* License as published by the Free Software Foundation; either    */
/* version 2 of the License, or (at your option) any later         */
/* version.                                                        */
/* This library is distributed in the hope that it will be useful, */
/* but WITHOUT ANY WARRANTY; without even the implied warranty of  */
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.            */
/* See the GNU Library General Public License for more details.    */
/* You should have received a copy of the GNU Library General      */
/* Public License along with this library; if not, write to the    */
/* Free Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA   */
/* 02111-1307  USA                                                 */

/* Copyright (C) 1997 Makoto Matsumoto and Takuji Nishimura.       */
/* Any feedback is very welcome. For any question, comments,       */
/* see http://www.math.keio.ac.jp/matumoto/emt.html or email       */
/* matumoto@math.keio.ac.jp                                        */

#include<stdio.h>


#define N 624
#define M 397
#define MATRIX_A 0x9908b0df   /* constant vector a */
#define UPPER_MASK 0x80000000 /* most significant w-r bits */
#define LOWER_MASK 0x7fffffff /* least significant r bits */

/* Tempering parameters */
#define TEMPERING_MASK_B 0x9d2c5680
#define TEMPERING_MASK_C 0xefc60000
#define TEMPERING_SHIFT_U(y)  (y >> 11)
#define TEMPERING_SHIFT_S(y)  (y << 7)
#define TEMPERING_SHIFT_T(y)  (y << 15)
#define TEMPERING_SHIFT_L(y)  (y >> 18)

static unsigned long mt[N]; /* the array for the state vector  */
static int mti=N+1; /* mti==N+1 means mt[N] is not initialized */

/* initializing the array with a NONZERO seed */
void
sgenrand(seed, gen)     // Tetiana
unsigned long seed;
struct gen *gen;        // Tetiana
{
    /* setting initial seeds to mt[N] using         */
    /* the generator Line 25 of Table 1 in          */
    /* [KNUTH 1981, The Art of Computer Programming */
    /*    Vol. 2 (2nd Ed.), pp102]                  */
    mt[0]= seed & 0xffffffff;
    for (mti=1; mti<N; mti++)
        // mt[mti] = (69069 * mt[mti-1]) & 0xffffffff;

    //+++++ Tetiana
    if (gen->useTriton == True)
        mt[mti] = ( gen->seed * mt[mti-1] ) & 0xffffffff;  // gen->seed was received from the command line and bash script
    else
        mt[mti] = ( time(NULL) * mt[mti-1] ) & 0xffffffff; // Please, don#t use the total amount of seconds on Triton !!!!!
}

real unirand(seed,gen)  // Tetiana
int seed;
struct gen *gen;        // Tetiana
{
    unsigned long y;
    static unsigned long mag01[2]={0x0, MATRIX_A};
    /* mag01[x] = x * MATRIX_A  for x=0,1 */

    /* mdh compatibility interface */

    if (seed==0) ; /* Do nothing  here, go to normal Mersenne twister */
    if (seed==-1) { fprintf(fpdebug,"unirand.c mersenne twister mt[0] %lud N %d\n",mt[0],N); }
    if (seed>0) { sgenrand( (unsigned long) seed ); }

    if (mti >= N) { /* generate N words at one time */
        int kk;

        if (mti == N+1)   /* if sgenrand() has not been called, */


          if (gen->useTriton == True)
                    sgenrand(gen->seed);
          else
                    sgenrand( time(NULL)  );

       //+++++


        for (kk=0;kk<N-M;kk++) {
            y = (mt[kk]&UPPER_MASK)|(mt[kk+1]&LOWER_MASK);
            mt[kk] = mt[kk+M] ^ (y >> 1) ^ mag01[y & 0x1];
        }
        for (;kk<N-1;kk++) {
            y = (mt[kk]&UPPER_MASK)|(mt[kk+1]&LOWER_MASK);
            mt[kk] = mt[kk+(M-N)] ^ (y >> 1) ^ mag01[y & 0x1];
        }
        y = (mt[N-1]&UPPER_MASK)|(mt[0]&LOWER_MASK);
        mt[N-1] = mt[M-1] ^ (y >> 1) ^ mag01[y & 0x1];

        mti = 0;
    }

    y = mt[mti++];
    y ^= TEMPERING_SHIFT_U(y);
    y ^= TEMPERING_SHIFT_S(y) & TEMPERING_MASK_B;
    y ^= TEMPERING_SHIFT_T(y) & TEMPERING_MASK_C;
    y ^= TEMPERING_SHIFT_L(y);

    return ( (double)y / (unsigned long)0xffffffff ); /* reals */
    /* return y; */ /* for integer generation */
}




real oldunirand(seed)
int seed;
{
   static int seedstore;

   static int ii=127773,jj=2147483647;
   static int i1=16807,i2=2836;
   static double p=4.656612875e-10;
   int k1;

   if (seed==0) seed=seedstore;
   if (seed==-1) { fprintf(fpdebug,"unirand.c seed and seedstore for next call %d %d\n",seed,seedstore); return; }

   k1 = seed/ii;
   seed = i1*( seed - k1*ii) - k1 * i2;
   if (seed<0) seed = seed + jj;

   seedstore=seed;
   return ((real)(seed * p));
}


real gaussianrand()
{
   static int iset=0;
   static real gset;

   real v1,v2,r,fac;

   if (iset==0) {
l1:   v1 = 2*unirand(0)-1;
      v2 = 2*unirand(0)-1;
      r = v1*v1+v2*v2;
      if (r>1) goto l1;
      fac = sqrt(-2.*log(r)/r);
      gset = v1*fac;
      iset = 1;
      return (v2*fac);
   }
   else {
      iset = 0;
      return(gset);
    }
}













