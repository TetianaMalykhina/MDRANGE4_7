/*
   This file contains global variables.
   Ideally, it should be empty, and all data contained in program structures.

*/
#define DEBUG(var) if (debug) fprintf(fpdebug, #var " = %g\n",(double) (var)); oflush();
#define MAXDEBUG(var) if (maxdebug) fprintf(fpdebug, #var " = %g\n",(double) (var)); oflush();
#define DEBUGS(str) if (debug) fprintf(fpdebug,str); oflush();
#define MAXDEBUGS(str) if (maxdebug) fprintf(fpdebug,str); oflush();
#define DEBUGSR(str,var) if (debug) fprintf(fpdebug, "%s " #var " = %g\n",str,(double) (var)); oflush();
#define MAXDEBUGSR(str,var) if (maxdebug) fprintf(fpdebug, "%s " #var " = %g\n",(str),((double) (var))); oflush();
#define DEBUGSRR(str,var,var2) if (debug) fprintf(fpdebug, "%s " #var " = %g " #var2 " = %g\n",str,(double) (var),(double) (var2)); oflush();
#define MAXDEBUGSRR(str,var,var2) if (maxdebug) fprintf(fpdebug, "%s " #var " = %g " #var2 " = %g\n",(str),((double) (var)),((double) (var2))); oflush();
#define DEBUGSRRR(str,var,var2,var3) if (debug) fprintf(fpdebug, "%s " #var " = %g " #var2 " = %g " #var3 " = %g\n",str,(double) (var),(double) (var2),(double) (var3)); oflush();
#define DEBUGSRRRR(str,var,var2,var3,var4) if (debug) fprintf(fpdebug, "%s " #var " = %g " #var2 " = %g " #var3 " = %g " #var4 " = %g\n",str,(double) (var),(double) (var2),(double) (var3),(double) (var4)); oflush();
#define DEBUGSRRRRR(str,var,var2,var3,var4,var5) if (debug) fprintf(fpdebug, "%s " #var " = %g " #var2 " = %g " #var3 " = %g " #var4 " = %g " #var5 " = %g\n",str,(double) (var),(double) (var2),(double) (var3),(double) (var4),(double) (var5)); oflush();
#define MAXDEBUGSRRR(str,var,var2,var3) if (maxdebug) fprintf(fpdebug, "%s " #var " = %g " #var2 " = %g " #var3 " = %g\n",str,(double) (var),(double) (var2),(double) (var3)); oflush();
#define MAXDEBUGSRRRR(str,var,var2,var3,var4) if (maxdebug) fprintf(fpdebug, "%s " #var " = %g " #var2 " = %g " #var3 " = %g " #var4 " = %g\n",str,(double) (var),(double) (var2),(double) (var3),(double) (var4)); oflush();
#define MAXDEBUGSRRRRR(str,var,var2,var3,var4,var5) if (maxdebug) fprintf(fpdebug, "%s " #var " = %g " #var2 " = %g " #var3 " = %g " #var4 " = %g " #var5 " = %g\n",str,(double) (var),(double) (var2),(double) (var3),(double) (var4),(double) (var5)); oflush();


   FILE *fpdebug;        /* Same as fpdb in struct file */
   logical debug;      /* debug to file stdout */
   logical maxdebug;   /* maximum depug to stdout */












