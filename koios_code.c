/*===============================[[ beg-code ]]===============================*/
#include    "koios.h"        /* LOCAL  : main header                          */


tTEST       g_tests [MAX_TEST] = {
   /*---- ----- --------------------- --------------------- ----------------------------------------- */
   { 'v' , 'v' , "void (pure)"       , "yUNIT_void      (" , "no return at all, not even void*"       },
   { 's' , 's' , "string (pure)"     , "yUNIT_string    (" , "literal string comparison, char-by-char"},
   { 'i' , 'i' , "integer"           , "yUNIT_int       (" , ""                                       },
   { '-' , '-' , "end-of-tests"      , ""                  , ""                                       },
   /*---- ----- --------------------- --------------------- ----------------------------------------- */
};



char        CODE_cond_end      (void);

static char s_shared      = '-';         /* flag for shared code or not    */
static int  s_share_cnt   [26];          /* count of cond in each share    */

/*====================------------------------------------====================*/
/*===----                       general functions                      ----===*/
/*====================------------------------------------====================*/
static void  o___OVERALL_________o () { return; }

char         /*--> open code file ------------------------[ leaf   [ ------ ]-*/
CODE_open          (void)
{
   /*---(locals)-----------+-----------+-*/
   char        rce         = -10;           /* return code for errors         */
   /*---(header)-------------------------*/
   DEBUG_TOPS   yLOG_enter   (__FUNCTION__);
   /*---(open output file)---------------*/
   DEBUG_OUTP   yLOG_point   ("name"      , my.n_code);
   my.f_code = fopen (my.n_code, "wt");
   DEBUG_OUTP   yLOG_point   ("file*"     , my.f_code);
   --rce;  if (my.f_code == NULL) {
      DEBUG_TOPS   yLOG_fatal   ("scrp file, can not open script file");
      DEBUG_TOPS   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   DEBUG_OUTP   yLOG_note    ("script file open");
   /*---(open main file)-----------------*/
   DEBUG_OUTP   yLOG_point   ("main"      , my.n_main);
   my.f_main = fopen (my.n_main, "w");
   DEBUG_OUTP   yLOG_point   ("file*"     , my.f_main);
   --rce;  if (my.f_main == NULL) {
      DEBUG_TOPS   yLOG_fatal   ("scrp file, can not open main file");
      DEBUG_TOPS   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   DEBUG_OUTP   yLOG_note    ("script file open");
   /*---(complete)-----------------------*/
   DEBUG_TOPS   yLOG_exit    (__FUNCTION__);
   return 0;
}

char         /*--> close code file -----------------------[ ------ [ ------ ]-*/
CODE_close         (void)
{
   /*---(locals)-----------+-----------+-*/
   char        rc          = 0;
   char        rce         = -10;
   /*---(header)-------------------------*/
   DEBUG_TOPS   yLOG_enter   (__FUNCTION__);
   /*---(close detail report)------------*/
   DEBUG_OUTP   yLOG_point   ("*f_code", my.f_code);
   rc = fclose (my.f_code);
   --rce;  if (rc != 0) {
      return rce;
   }
   /*---(terminate logging)--------------*/
   DEBUG_TOPS   yLOG_exit    (__FUNCTION__);
   /*---(complete)-----------------------*/
   return 0;
}

char
CODE_begin         (void)
{
   int         i           = 0;
   /*---(create header)------------------*/
   /*> fprintf (my.f_code, "/+============================================================================+/\n");          <* 
    *> fprintf (my.f_code, "/+=========================== beginning-of-file ==============================+/\n");          <* 
    *> fprintf (my.f_code, "/+============================================================================+/\n");          <* 
    *> fprintf (my.f_code, "\n");                                                                                          <* 
    *> fprintf (my.f_code, "\n");                                                                                          <* 
    *> fprintf (my.f_code, "\n");                                                                                          <* 
    *> fprintf (my.f_code, "/+==========================---------------------=============================+/\n");          <* 
    *> fprintf (my.f_code, "/+===----                  unit testing preparation                    ----===+/\n");          <* 
    *> fprintf (my.f_code, "/+==========================---------------------=============================+/\n");          <* 
    *> fprintf (my.f_code, "\n\n\n");                                                                                      <* 
    *> fprintf (my.f_code, "/+---(standard headers)---------------+/\n");                                                  <* 
    *> fprintf (my.f_code, "#include    <stdio.h>\n");                                                                     <* 
    *> fprintf (my.f_code, "#include    <string.h>\n");                                                                    <* 
    *> fprintf (my.f_code, "#include    <stdlib.h>                   /+ exit,atoi                                +/\n");   <* 
    *> fprintf (my.f_code, "#include    <unistd.h>                   /+ sleep                                    +/\n");   <* 
    *> fprintf (my.f_code, "/+---(custom headers)-----------------+/\n");                                                  <* 
    *> fprintf (my.f_code, "#include    <yUNIT.h>                    /+ unit testing functions                   +/\n");   <* 
    *> fprintf (my.f_code, "#include    <yVAR.h>                     /+ complex comparison functions             +/\n");   <* 
    *> fprintf (my.f_code, "\n\n\n");                                                                                      <* 
    *> fprintf (my.f_code, "/+---(globals)----------+-----+-----+-+/\n");                                                  <* 
    *> fprintf (my.f_code, "char        eterm       =  'y';          /+ handle console vs eterm                  +/\n");   <* 
    *> fprintf (my.f_code, "int         g_noisy     =    0;          /+ how loud things should be                +/\n");   <* 
    *> fprintf (my.f_code, "int         g_exec      =    1;          /+ run scripts                              +/\n");   <* 
    *> fprintf (my.f_code, "int         g_scrp      =    0;          /+ script selected for focus                +/\n");   <* 
    *> fprintf (my.f_code, "int         g_cond      =    0;          /+ condition selected for focus             +/\n");   <* 
    *> fprintf (my.f_code, "int         g_offset    =    0;          /+ shared code condition offset             +/\n");   <* 
    *> fprintf (my.f_code, "int         g_origin    =    0;          /+ shared code scription offset             +/\n");   <* 
    *> fprintf (my.f_code, "char        g_debug     [100];           /+ display debugging info                   +/\n");   <* 
    *> fprintf (my.f_code, "char        CUSTOM      [2000];          /+ holder for custom expect strings         +/\n");   <* 
    *> fprintf (my.f_code, "\n\n\n");                                                                                      <* 
    *> fprintf (my.f_code, "/+---(prototypes)---------------------+/\n");                                                  <* 
    *> fprintf (my.f_code, "char        UNIT_usage        (void);\n");                                                     <* 
    *> fprintf (my.f_code, "char        UNIT_args         (int   a_argc, char *a_argv[]);\n");                             <* 
    *> fprintf (my.f_code, "char        UNIT_stats        (void);\n");                                                     <* 
    *> fprintf (my.f_code, "\n\n\n");                                                                                      <*/
   /*---(initialize variables)-----------*/
   my.nscrp  = my.cscrp = 0;
   my.ncond  = my.ccond = 0;
   my.nstep  = my.cstep = 0;
   s_shared = '-';
   for (i = 0; i < 26; ++i)  s_share_cnt [i] = 0;
   /*---(open main function)-------------*/
   fprintf (my.f_main, "int¦");
   fprintf (my.f_main, "main (int a_argc, char *a_argv[])¦");
   fprintf (my.f_main, "{¦");
   fprintf (my.f_main, "   /*---(locals)-----------+-----+-----+-*/¦");
   fprintf (my.f_main, "   int         rc          =    0;     /* generic return code     */¦");
   fprintf (my.f_main, "   /*---(prepare)------------------------*/¦");
   fprintf (my.f_main, "   rc = UNIT_args (a_argc, a_argv);¦");
   fprintf (my.f_main, "   if (rc < 0)  return -1;¦");
   fprintf (my.f_main, "   yUNIT_unit(¶%s¶, g_noisy, eterm);¦", my.n_base);
   fprintf (my.f_main, "   /*---(scripts)------------------------*/¦");
   return 0;
}

char
CODE_main          (void)
{
   /*---(locals)-----------+-----+-----+-*/
   if (my.driver == 'y')  return 0;
   /*> fprintf (my.f_code, "¦¦");                                                                                 <* 
    *> fprintf (my.f_code, "char¦");                                                                               <* 
    *> fprintf (my.f_code, "UNIT_usage (void)¦");                                                                  <* 
    *> fprintf (my.f_code, "{¦");                                                                                  <* 
    *> fprintf (my.f_code, "   printf(¶yUNIT -- heatherly unit testing frameworkµn¶);¦");                       <* 
    *> fprintf (my.f_code, "   printf(¶   #---(scope)--------------------#µn¶);¦");                             <* 
    *> fprintf (my.f_code, "   printf(¶   --all         = run all scripts and conditionsµn¶);¦");               <* 
    *> fprintf (my.f_code, "   printf(¶   <nn>          = only run script <nn>µn¶);¦");                         <* 
    *> fprintf (my.f_code, "   printf(¶   <nn>.<nnn>    = only show detail on condition <nnn>µn¶);¦");          <* 
    *> fprintf (my.f_code, "   printf(¶   #---(verbosity)----------------#µn¶);¦");                             <* 
    *> fprintf (my.f_code, "   printf(¶   --quiet       = just returns a rcµn¶);¦");                            <* 
    *> fprintf (my.f_code, "   printf(¶   --none        = just returns a rcµn¶);¦");                            <* 
    *> fprintf (my.f_code, "   printf(¶   --test        = one line of summary statisticsµn¶);¦");               <* 
    *> fprintf (my.f_code, "   printf(¶   --scrp        = script level statistics onlyµn¶);¦");                 <* 
    *> fprintf (my.f_code, "   printf(¶   --cond        = condition level statistics onlyµn¶);¦");              <* 
    *> fprintf (my.f_code, "   printf(¶   --step        = step header level statistics onlyµn¶);¦");            <* 
    *> fprintf (my.f_code, "   printf(¶   --full        = full detailµn¶);¦");                                  <* 
    *> fprintf (my.f_code, "   printf(¶   --loud        = full detailµn¶);¦");                                  <* 
    *> fprintf (my.f_code, "   printf(¶   #---(information)--------------#µn¶);¦");                             <* 
    *> fprintf (my.f_code, "   printf(¶   --scrps       = script level statistics onlyµn¶);¦");                 <* 
    *> fprintf (my.f_code, "   printf(¶   --conds       = condition level statistics onlyµn¶);¦");              <* 
    *> fprintf (my.f_code, "   printf(¶   --steps       = step header level statistics onlyµn¶);¦");            <* 
    *> fprintf (my.f_code, "   printf(¶   --stats       = display conversion statisticsµn¶);¦");                <* 
    *> fprintf (my.f_code, "   printf(¶   #---(color)--------------------#µn¶);¦");                             <* 
    *> fprintf (my.f_code, "   printf(¶   --console     = no terminal color codesµn¶);¦");                      <* 
    *> fprintf (my.f_code, "   printf(¶   --eterm       = add terminal color codesµn¶);¦");                     <* 
    *> fprintf (my.f_code, "   printf(¶   #---(other)--------------------#µn¶);¦");                             <* 
    *> fprintf (my.f_code, "   printf(¶   --help        = usage informationµn¶);¦");                            <* 
    *> fprintf (my.f_code, "   exit(0);¦");                                                                        <* 
    *> fprintf (my.f_code, "}¦");                                                                                  <* 
    *> fprintf (my.f_code, "¦");                                                                                   <* 
    *> fprintf (my.f_code, "char¦");                                                                               <* 
    *> fprintf (my.f_code, "UNIT_args (int argc, char *argv[])¦");                                                 <* 
    *> fprintf (my.f_code, "{¦");                                                                                  <* 
    *> fprintf (my.f_code, "   /+---(locals)-----------+-----+-----+-+/¦");                                        <* 
    *> fprintf (my.f_code, "   int         i           =    0;     /+ loop iterator -- args   +/¦");               <* 
    *> fprintf (my.f_code, "   char       *a           = NULL;     /+ cli argument holder     +/¦");               <* 
    *> fprintf (my.f_code, "   int         v           =    5;     /+ verbosity level         +/¦");               <* 
    *> fprintf (my.f_code, "   int         l           =    0;     /+ length of argument      +/¦");               <* 
    *> fprintf (my.f_code, "   int         x_bad       =    0;     /+ number of bad arguments +/¦");               <* 
    *> fprintf (my.f_code, "   char        x_temp      [10] = ¶¶;  /+ temp string             +/¦");             <* 
    *> fprintf (my.f_code, "   /+---(process args)-------------------+/¦");                                        <* 
    *> fprintf (my.f_code, "   for (i = 1; i < argc; ++i) {¦");                                                    <* 
    *> fprintf (my.f_code, "      a = argv[i];¦");                                                                 <* 
    *> fprintf (my.f_code, "      l = strlen(a);¦");                                                               <* 
    *> fprintf (my.f_code, "      /+---(verbosity)--------------------+/¦");                                       <* 
    *> fprintf (my.f_code, "      if      (strcmp (a, ¶--quiet¶     )  == 0)      v = 0;¦");                     <* 
    *> fprintf (my.f_code, "      else if (strcmp (a, ¶--none¶      )  == 0)      v = 0;¦");                     <* 
    *> fprintf (my.f_code, "      else if (strcmp (a, ¶--test¶      )  == 0)      v = 1;¦");                     <* 
    *> fprintf (my.f_code, "      else if (strcmp (a, ¶--scrp¶      )  == 0)      v = 2;¦");                     <* 
    *> fprintf (my.f_code, "      else if (strcmp (a, ¶--cond¶      )  == 0)      v = 3;¦");                     <* 
    *> fprintf (my.f_code, "      else if (strcmp (a, ¶--step¶      )  == 0)      v = 4;¦");                     <* 
    *> fprintf (my.f_code, "      else if (strcmp (a, ¶--full¶      )  == 0)      v = 5;¦");                     <* 
    *> fprintf (my.f_code, "      else if (strcmp (a, ¶--loud¶      )  == 0)      v = 5;¦");                     <* 
    *> fprintf (my.f_code, "      /+---(information)------------------+/¦");                                       <* 
    *> fprintf (my.f_code, "      else if (strcmp (a, ¶--scrps¶     )  == 0)    { g_exec = 0; v = 2; }¦");       <* 
    *> fprintf (my.f_code, "      else if (strcmp (a, ¶--conds¶     )  == 0)    { g_exec = 0; v = 3; }¦");       <* 
    *> fprintf (my.f_code, "      else if (strcmp (a, ¶--steps¶     )  == 0)    { g_exec = 0; v = 4; }¦");       <* 
    *> fprintf (my.f_code, "      else if (strcmp (a, ¶--stats¶     )  == 0)      UNIT_stats ();¦");             <* 
    *> fprintf (my.f_code, "      /+---(help)-------------------------+/¦");                                       <* 
    *> fprintf (my.f_code, "      else if (strcmp (a, ¶--help¶      )  == 0)      UNIT_usage ();¦");             <* 
    *> fprintf (my.f_code, "      /+---(fomatting)--------------------+/¦");                                       <* 
    *> fprintf (my.f_code, "      else if (strcmp (a, ¶--console¶   )  == 0)      eterm = '-';¦");               <* 
    *> fprintf (my.f_code, "      else if (strcmp (a, ¶--eterm¶     )  == 0)      eterm = 'y';¦");               <* 
    *> fprintf (my.f_code, "      /+---(scope)------------------------+/¦");                                       <* 
    *> fprintf (my.f_code, "      else if (strcmp (a, ¶--all¶       )  == 0)      { g_scrp = g_cond = 0; }¦");   <* 
    *> fprintf (my.f_code, "      else if (l == 2) {¦");                                                           <* 
    *> fprintf (my.f_code, "          g_scrp = atoi(a);¦");                                                        <* 
    *> fprintf (my.f_code, "      }¦");                                                                            <* 
    *> fprintf (my.f_code, "      else if (l == 6 && (a[2] == '.' || a[2] == '-'))    {¦");                        <* 
    *> fprintf (my.f_code, "          sprintf (x_temp, ¶%%c%%c¶, a[0], a[1]);¦");                                <* 
    *> fprintf (my.f_code, "          g_scrp = atoi (x_temp);¦");                                                  <* 
    *> fprintf (my.f_code, "          sprintf (x_temp, ¶%%c%%c%%c¶, a[3], a[4], a[5]);¦");                       <* 
    *> fprintf (my.f_code, "          g_cond = atoi (x_temp);¦");                                                  <* 
    *> fprintf (my.f_code, "          v = 3;¦");                                                                   <* 
    *> fprintf (my.f_code, "      }¦");                                                                            <* 
    *> fprintf (my.f_code, "      else {¦");                                                                       <* 
    *> fprintf (my.f_code, "         printf(¶option not understood <<%%s>>µn¶, a);¦");                          <* 
    *> fprintf (my.f_code, "         ++x_bad;¦");                                                                  <* 
    *> fprintf (my.f_code, "      }¦");                                                                            <* 
    *> fprintf (my.f_code, "      /+---(done)-------------------------+/¦");                                       <* 
    *> fprintf (my.f_code, "   }¦");                                                                               <* 
    *> fprintf (my.f_code, "   /+---(check results)------------------+/¦");                                        <* 
    *> fprintf (my.f_code, "   if (x_bad > 0) {¦");                                                                <* 
    *> fprintf (my.f_code, "         printf(¶FATAL, exitingµn¶);¦");                                            <* 
    *> fprintf (my.f_code, "         exit (-1);¦");                                                                <* 
    *> fprintf (my.f_code, "   }¦");                                                                               <* 
    *> fprintf (my.f_code, "   g_noisy = v;¦");                                                                    <* 
    *> fprintf (my.f_code, "   /+---(complete)-----------------------+/¦");                                        <* 
    *> fprintf (my.f_code, "   return 0;¦");                                                                       <* 
    *> fprintf (my.f_code, "}¦");                                                                                  <* 
    *> fprintf (my.f_code, "¦");                                                                                   <*/
   my.driver = 'y';
   return 0;
}

char
CODE_prep          (void)
{
   fprintf (my.f_code, "/*---(program headers)----------------*/¦");
   return 0;
}

char
CODE_incl          (void)
{
   fprintf (my.f_code, "#include    ¶%s¶   /* %4i, %s */¦",
         my.meth, my.n_line, my.desc);
   fprintf (my.f_code, "¦");
   return 0;
}



/*====================------------------------------------====================*/
/*===----                      script level verbs                      ----===*/
/*====================------------------------------------====================*/
static void  o___SCRP____________o () { return; }

char
CODE_scrp_end        (void)
{
   /*---(close final condition)----------*/
   if (s_shared != '-' || my.cscrp >  0) {
      CODE_cond_end ();
   }
   /*---(end share)----------------------*/
   if (s_shared != '-') {
      s_share_cnt [s_shared] = my.ccond;
   }
   /*---(close script/share)-------------*/
   if (s_shared != '-' || my.cscrp >  0) {
      if (s_shared != '-') {
         fprintf (my.f_code, "   /*---(shared done)---------------------*/¦");
         fprintf (my.f_code, "   if (g_exec == 1)  yUNIT_erahs ('%c');¦", s_shared);
      }
      if (s_shared == '-') {
         fprintf (my.f_code, "   /*---(script done)---------------------*/¦");
         fprintf (my.f_code, "   if (g_exec == 1)  yUNIT_prcs    ();¦");
      }
      fprintf (my.f_code, "   /*---(complete)-----------------------*/¦");
      fprintf (my.f_code, "   return 0;¦");
      fprintf (my.f_code, "}¦");
      fprintf (my.f_code, "¦");
   }
   /*---(initialize vars)----------------*/
   s_shared = '-';
   my.ccond  = 0;
   my.cstep  = 0;
   /*---(complete)-----------------------*/
   return 0;
}

char
CODE_scrp          (void)
{
   /*---(end last script)----------------*/
   CODE_scrp_end ();
   /*---(counters)-----------------------*/
   ++(my.nscrp);
   ++(my.cscrp);
   /*---(open script function)-----------*/
   fprintf (my.f_code, "char¦");
   fprintf (my.f_code, "UNIT_script%02d (void)¦", my.cscrp);
   fprintf (my.f_code, "{¦");
   fprintf (my.f_code, "   /*---(locals)-----------+-----+-----+-*/¦");
   fprintf (my.f_code, "   g_offset  = 0;¦");
   fprintf (my.f_code, "   g_origin  = %d;¦", my.cscrp);
   fprintf (my.f_code, "¦");
   fprintf (my.f_code, "   /*---(script header)------------------*/¦");
   fprintf (my.f_code, "   yUNIT_scrp    (%4i, %3i, ¶%s¶, ¶%s¶);¦", my.n_line, my.cscrp, my.meth, my.desc);
   fprintf (my.f_code, "   if (g_exec ==  0 && g_noisy == 2)  return 0;¦");
   /*---(function call to main)----------*/
   fprintf (my.f_main, "   if (g_scrp ==  0 || g_scrp == %2i)  UNIT_script%02d ();¦", my.cscrp, my.cscrp);
   /*---(complete)-----------------------*/
   return 0;
}

char         /*-> common shared code between scripts ---[ ------ [----------]-*/
CODE_shared          (void)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   /*---(end last script)----------------*/
   CODE_scrp_end ();
   /*---(defense)------------------------*/
   --rce;  if (my.desc [0] != '(')  return rce;
   --rce;  if (my.desc [2] != ')')  return rce;
   --rce;  if (strchr ("ABCDEFGHIJZLMNOPQRSTUVWXYZ", my.desc [1]) == NULL)  return rce;
   /*---(counters)-----------------------*/
   s_shared = my.desc [1];
   s_share_cnt [s_shared] = 0;
   /*---(open script function)-----------*/
   fprintf (my.f_code, "char¦");
   fprintf (my.f_code, "UNIT_shared_%c (void)¦", my.desc [1]);
   fprintf (my.f_code, "{¦");
   fprintf (my.f_code, "    yUNIT_share ('%c', ¶%s¶);¦", my.desc [1], my.desc);
   fprintf (my.f_code, "¦");
   /*---(complete)-----------------------*/
   return 0;
}

char
CODE_sect          (void)
{
   /*---(add section)--------------------*/
   fprintf (my.f_main, "   if (g_scrp ==  0)  yUNIT_sect    (¶%s¶);¦", my.desc);
   /*---(complete)-----------------------*/
   return 0;
}

char
CODE_group         (void)
{
   CODE_cond_end ();
   fprintf (my.f_code, "   /*---(group)---------------------------*/¦");
   fprintf (my.f_code, "   yUNIT_group   (¶%s¶);¦", my.desc);
   return 0;
}



/*====================------------------------------------====================*/
/*===----                       condition level                        ----===*/
/*====================------------------------------------====================*/
static void  o___COND____________o () { return; }

char
CODE_cond_end      (void)
{
   /*---(header)-------------------------*/
   DEBUG_OUTP   yLOG_enter   (__FUNCTION__);
   DEBUG_OUTP   yLOG_complex ("counters"  , "%-10.10p, %-10.10s, %4dn, %4dc", my.f_code, my.last, my.ncond, my.ccond);
   if (strcmp (my.last, "GROUP") != 0 && strcmp (my.last, "USE_SHARE") != 0) {
      if (my.ccond > 0) {
         fprintf (my.f_code, "      /*---(done)------------------------*/¦");
         fprintf (my.f_code, "   if (g_exec == 1)  yUNIT_dnoc    ();¦");
         fprintf (my.f_code, "   yUNIT_level  (g_noisy, 'y');¦");
      }
   }
   fprintf (my.f_code, "¦");
   /*---(complete)-----------------------*/
   DEBUG_OUTP   yLOG_exit    (__FUNCTION__);
   return 0;
}

char
CODE_cond          (void)
{
   /*---(header)-------------------------*/
   DEBUG_OUTP   yLOG_enter   (__FUNCTION__);
   CODE_cond_end ();
   ++(my.ncond);
   ++(my.ccond);
   DEBUG_OUTP   yLOG_complex ("counters"  , "%-10.10p, %-10.10s, %4dn, %4dc", my.f_code, my.last, my.ncond, my.ccond);
   fprintf (my.f_code, "   /*---(cond #%03d)-----------------------*/¦", my.ccond);
   fprintf (my.f_code, "   if (g_cond == g_offset + %i) yUNIT_level  (5, 'y');¦", my.ccond);
   if (my.run_type == G_RUN_DEBUG) {
      fprintf (my.f_code, "   %sUG_TOPS    %sOG_unitcond (g_origin, g_offset + %d, %d, ¶%s¶);¦", "DEB", "yL", my.ccond, my.n_line, my.desc);
   }
   sprintf (my.compiled , "   yUNIT_cond    (%4i, g_offset + %3i, \"%s\");", my.n_line, my.ccond, my.desc);
   DEBUG_OUTP   yLOG_complex ("output"    , "%3d:%s", strlen (my.compiled), my.compiled);
   fprintf (my.f_code, "%s¦", my.compiled);
   my.cstep = 0;
   /*---(complete)-----------------------*/
   DEBUG_OUTP   yLOG_exit    (__FUNCTION__);
   return 0;
}

char
CODE_use           (void)
{
   char        rce         =  -10;
   /*---(header)-------------------------*/
   DEBUG_OUTP   yLOG_enter   (__FUNCTION__);
   CODE_cond_end ();
   --rce;  if (strchr ("ABCDEFGHIJZLMNOPQRSTUVWXYZ", my.desc [0]) == NULL)  return rce;
   fprintf (my.f_code, "   /*---(shared code)-----------------------*/¦");
   fprintf (my.f_code, "   g_offset = %d;¦", my.ccond);
   fprintf (my.f_code, "   UNIT_shared_%c ();¦", my.desc [0]);
   fprintf (my.f_code, "   g_offset = 0;¦");
   my.ncond += s_share_cnt [my.desc [0]];
   my.ccond += s_share_cnt [my.desc [0]];
   /*---(complete)-----------------------*/
   DEBUG_OUTP   yLOG_exit    (__FUNCTION__);
   return 0;
}



/*====================------------------------------------====================*/
/*===----                       step level verbs                       ----===*/
/*====================------------------------------------====================*/
static void  o___STEP____________o () { return; }

char
CODE_mode          (void)
{
   ++(my.nstep);
   ++(my.cstep);
   fprintf (my.f_code, "      /*---(mode)-------------------------*/¦");
   fprintf (my.f_code, "      if (g_exec == 1)  yUNIT_mode    (%4i, %3i, %s);¦", my.n_line, my.cstep, my.args);
   return 0;
}

char
CODE_display       (void)
{
   /*---(locals)-----------+-----------+-*/
   int         i           = 0;
   int         x_len       = 0;
   char        t           [10]        = "";
   /*---(fix delimiters)-----------------*/
   printf ("CODE_display ------------------------------\n");
   printf ("my.code <<%s>>\n", my.code);
   x_len = strlen (my.code);
   printf ("length  %d\n", x_len);
   /*---(prepare)------------------------*/
   x_len = strlen (my.code);
   printf ("length  %d\n", x_len);
   strlcpy (my.disp, my.code , LEN_RECD);
   strlcpy (my.syst, ""     , LEN_RECD);
   strlcpy (my.load, ""     , LEN_RECD);
   /*---(cleanse)------------------------*/
   for (i = 0; i < x_len; ++i) {
      switch ((unsigned char) my.code [i]) {
      case  G_CHAR_FIELD  :
      case  G_KEY_FIELD   :
         my.disp [i]  = G_CHAR_FIELD;
         sprintf (t, "%c", G_KEY_FIELD);
         strlcat (my.syst, t, 2000);
         strlcat (my.load, t, 2000);
         break;
      case  G_CHAR_GROUP  :
      case  G_KEY_GROUP   :
         my.disp [i]  = G_CHAR_GROUP;
         sprintf (t, "%c", G_KEY_FIELD);
         strlcat (my.syst, t, 2000);
         strlcat (my.load, t, 2000);
         break;
      case  G_KEY_DQUOTE  :
         my.disp [i]  = G_KEY_TILDA;
         sprintf (t, "%c", G_KEY_DQUOTE);
         strlcat (my.syst, t, 2000);
         sprintf (t, "%c", G_KEY_TILDA);
         strlcat (my.load, t, 2000);
         break;
      case  G_CHAR_RETURN :
         sprintf (t, "\\n");
         strlcat (my.syst, t, 2000);
         strlcat (my.load, t, 2000);
         break;
      case  G_CHAR_ESCAPE :
         sprintf (t, "\\e");
         strlcat (my.syst, t, 2000);
         strlcat (my.load, t, 2000);
         break;
      default  :
         my.disp [i]  = my.code [i];
         sprintf (t, "%c", my.code [i]);
         strlcat (my.syst, t, 2000);
         strlcat (my.load, t, 2000);
         break;
      }
   }
   /*---(display)------------------------*/
   printf ("my.disp <<%s>>\n", my.disp);
   printf ("my.syst <<%s>>\n", my.syst);
   printf ("my.load <<%s>>\n", my.load);
   /*---(complete)-----------------------*/
   return 0;
}

char
CODE_code          (void)
{
   /*---(counters)-----------------------*/
   ++(my.nstep);
   ++(my.cstep);
   /*---(fix strings)--------------------*/
   CODE_display ();
   /*---(write)--------------------------*/
   fprintf (my.f_code, "      /*---(code)------------------------*/¦");
   fprintf (my.f_code, "      %s¦",  my.syst);
   fprintf (my.f_code, "      if (g_exec == 1)  yUNIT_code    (%4i, %3i, ¶%s¶, ¶%s¶);¦", my.n_line, my.cstep, my.desc, my.disp);
   /*---(complete)-----------------------*/
   return 0;
}

char
CODE_load          (void)
{
   /*---(locals)-----------+-----------+-*/
   int         x_len       = 0;
   char       *p           = NULL;
   char       *q           = " ";
   char       *r           = NULL;
   char        x_temp      [LEN_FULL];
   char       *x_var       = NULL;
   /*---(counters)-----------------------*/
   ++(my.nstep);
   ++(my.cstep);
   /*---(fix strings)--------------------*/
   CODE_display ();
   fprintf (my.f_code, "      /*---(load)------------------------*/¦");
   fprintf (my.f_code, "      if (g_exec == 1)  yUNIT_load    (%4i, %3i, ¶%s¶, ¶%s¶, ", my.n_line, my.cstep, my.desc, my.meth);
   /*---(check for var)------------------*/
   x_len = strlen (my.load);
   if        (x_len <= 7) {
      /*> printf ("small one\n");                                                     <*/
      fprintf (my.f_code, "¶%s¶", my.load);
   } else if (strncmp (my.code, "[[ ", 3) != 0) {
      /*> printf ("longer, not-variable one\n");                                      <*/
      fprintf (my.f_code, "¶%s¶", my.load);
   } else {
      /*> printf ("variable one\n");                                                  <*/
      strlcpy (x_temp, my.load + 3, LEN_FULL);
      x_var = x_temp;
      p = strtok_r (x_temp, q, &r);
      if (p == NULL) fprintf (my.f_code, "¶%s¶" , "unknown");
      else           fprintf (my.f_code, "%s" , x_var);
   }
   /*---(write)--------------------------*/
   fprintf (my.f_code, ");¦");
   /*---(complete)-----------------------*/
   return 0;
}

char
CODE_sys           (void)
{
   /*---(counters)-----------------------*/
   ++(my.nstep);
   ++(my.cstep);
   /*---(fix strings)--------------------*/
   CODE_display ();
   /*---(write)--------------------------*/
   fprintf (my.f_code, "      /*---(sys)-------------------------*/¦");
   fprintf (my.f_code, "      if (g_exec == 1)  yUNIT_sys     (%4i, %3i, ¶%s¶, ¶%s¶);¦", my.n_line, my.cstep, my.desc, my.disp);
   /*---(complete)-----------------------*/
   return 0;
}

void
VOID_void          (char *a_one, int a_two)
{
   return;
}

char
CODE_prefix        (char a_test)
{
   /*---(locals)-----------+-----------+-*/
   char        x_func      [LEN_FULL]   = "";
   /*---(pre-work for void)--------------*/
   if (a_test == 'v') {
      fprintf (my.f_code, "      if (g_exec == 1)  ");
      fprintf (my.f_code, "%-13s (%s);¦"     , my.meth , my.args);
   }
   /*---(determine function)-------------*/
   switch (a_test) {
   case 'v'  : strlcpy (x_func, "yUNIT_void"     , LEN_FULL);    break;
   case 's'  : strlcpy (x_func, "yUNIT_string"   , LEN_FULL);    break;
   case 'u'  : strlcpy (x_func, "yUNIT_round"    , LEN_FULL);    break;
   case 'i'  : strlcpy (x_func, "yUNIT_int"      , LEN_FULL);    break;
   case 'r'  : strlcpy (x_func, "yUNIT_real"     , LEN_FULL);    break;
   case 'p'  : strlcpy (x_func, "yUNIT_point"    , LEN_FULL);    break;
   default   : strlcpy (x_func, "yUNIT_unknown"  , LEN_FULL);    break;
   }
   /*---(write prefix)-------------------*/
   fprintf (my.f_code, "      if (g_exec == 1)  ");
   fprintf (my.f_code, "%-13s ("              , x_func);
   fprintf (my.f_code, "%4i, %3i, "           , my.n_line, my.cstep);
   fprintf (my.f_code, "¶%s¶, "             , my.desc);
   fprintf (my.f_code, "¶%s¶, ¶%s¶, "     , my.meth  , my.disp);
   /*---(write test)---------------------*/
   switch (a_test) {
   case 'v' :    /* pure void        */
      fprintf (my.f_code, "¶%s¶);¦"        , my.test);
      break;
   default  :    /* all others       */
      fprintf (my.f_code, "¶%s¶, "          , my.test);
      break;
      return 0;
   }
   /*---(complete)-----------------------*/
   return 0;
}

char
CODE_unknown       (void)
{
   CODE_prefix  ('-');
   fprintf (my.f_code, "¶%s¶, "           , my.expe);
   fprintf (my.f_code, "¶¶);¦"           );
   fprintf (my.f_code, "¦");
   return 0;
}

char
CODE_expe_var      (char a_test)
{
   /*---(locals)-----------+-----------+-*/
   char       *p           = NULL;
   char       *q           = " ";
   char       *r           = NULL;
   char        x_var       [LEN_FULL ];
   char       *x_expe      = NULL;
   /*---(defense)------------------------*/
   if (a_test == 'v')    return 0;
   /*---(normal)-------------------------*/
   if (strncmp (my.expe, "[[ ", 3) != 0) {
      switch (a_test) {
      case 's' : case 'u' :                 /* stringish   */
         fprintf (my.f_code, "¶%s¶, " , my.expe);
         break;
      case 'i' : case 'p' : case 'r' :      /* numberish   */
         fprintf (my.f_code, "%s, "     , my.expe);
         break;
      default  :
         fprintf (my.f_code, "¶%s¶);¦"         , my.expe);
         break;
      }
      return 0;
   }
   /*---(check for var)------------------*/
   else {
      strlcpy (x_var, my.expe + 3, LEN_RECD);
      x_expe = x_var;
      p = strtok_r (x_var, q, &r);
      if (p == NULL) fprintf (my.f_code, "¶%s¶, " , "unknown");
      else           fprintf (my.f_code, "%s, "     , x_expe);
   }
   /*---(complete)-----------------------*/
   return 0;
}

char
CODE_suffix        (char a_test)
{
   /*---(defense)------------------------*/
   if (a_test == 'v')    return 0;
   /*---(handle echos)-------------------*/
   if (strcmp (my.meth, "echo") == 0) {
      fprintf (my.f_code, "%s);¦"      , my.syst);
   }
   /*---(check for simple end)-----------*/
   else if (strcmp (my.retn, "") == 0) {
      fprintf (my.f_code, "%s (%s));¦" , my.meth, my.syst);
   }
   /*---(handle return variables)--------*/
   else {
      switch (my.type) {
      case 'i' : case 'p' : case 'r' :
         fprintf (my.f_code, "%s = %s (%s));¦", my.retn, my.meth, my.syst);
         break;
      case 's' : case 'u' :
         fprintf (my.f_code, "%s (%s));¦"     , my.meth, my.syst);
         fprintf (my.f_code, "         if (g_exec == 1)  strcpy (%s, %s);¦", my.retn, yUNIT_s_rc);
         break;
      default  :
         fprintf (my.f_code, "%s (%s));¦"     , my.meth, my.syst);
         break;
      }
   }
   /*---(complete)-----------------------*/
   return 0;
}

char
CODE_echo          (void)
{
   char        x_test      = '-';
   /*---(counters)-----------------------*/
   ++(my.nstep);
   ++(my.cstep);
   /*---(fix strings)--------------------*/
   CODE_display ();
   /*---(handle return values)-----------*/
   fprintf (my.f_code, "      /*---(step)------------------------*/¦");
   strlcpy (my.meth, "echo", LEN_DESC );
   x_test = my.test [0];
   CODE_prefix    (x_test);
   CODE_expe_var  (x_test);
   CODE_suffix    (x_test);
   /*---(finish)-------------------------*/
   /*> fprintf (my.f_code, "¦");                                                  <*/
   /*---(complete)-----------------------*/
   return 0;
}

char
CODE_exec          (void)
{
   /*---(design notes)-------------------*/
   /*
    * maintained/kept
    *   v_   = void
    *   s_   = string
    *   i_   = integer
    *   r_   = real
    *   p_   = pointer
    *
    * rejected/removed
    *   e_   = echo variable contents (use getter)
    *   c_   = custom (better to make expect field indicate this)
    *   m_   = macro to show complier macro values (NO)
    *
    *
    */
   char        x_test      = '-';
   /*---(counters)-----------------------*/
   ++(my.nstep);
   ++(my.cstep);
   /*---(fix strings)--------------------*/
   CODE_display ();
   /*---(debugging)----------------------*/
   fprintf (my.f_code, "      /*---(step)------------------------*/¦");
   if (my.run_type == G_RUN_DEBUG) {
      fprintf (my.f_code, "      %sUG_TOPS    %sOG_unitstep (g_origin, g_offset + %d, %d, %d, ¶%s¶);¦", "DEB", "yL", my.ccond, my.cstep, my.n_line, my.desc);
   }
   /*---(handle return values)-----------*/
   x_test = my.test [0];
   CODE_prefix    (x_test);
   CODE_expe_var  (x_test);
   CODE_suffix    (x_test);
   /*---(finish)-------------------------*/
   /*> fprintf (my.f_code, "¦");                                                  <*/
   /*---(complete)-----------------------*/
   return 0;
}

char
CODE_end           (void)
{
   char        x_recd      [LEN_RECD];
   int         x_len       = 0;             /* input record length            */
   CODE_scrp_end ();
   fprintf (my.f_code, "¦");
   SCRP_verbcode ();
   fprintf (my.f_main, "   /*---(complete)-----------------------*/¦");
   fprintf (my.f_main, "   if (g_exec ==  1)  return yUNIT_tinu ();¦");
   fprintf (my.f_main, "   return 0;¦");
   fprintf (my.f_main, "}¦");
   fprintf (my.f_main, "¦¦¦");
   fprintf (my.f_main, "/*============================== end-of-file =================================*/¦");
   /*---(open main file)-----------------*/
   fprintf (my.f_code, "¦");
   fclose (my.f_main);
   my.f_main = fopen (my.n_main, "r");
   while (1) {
      fgets (x_recd, LEN_RECD, my.f_main);
      if (feof (my.f_main)) break;
      fprintf  (my.f_code, x_recd);
   }
   fclose (my.f_main);
   return 0;
}

char
CODE_write         (void)
{
   /*---(header)-------------------------*/
   DEBUG_OUTP   yLOG_enter   (__FUNCTION__);
   /*---(switch)-------------------------*/
   strlcpy (my.compiled, "", LEN_RECD);
   DEBUG_OUTP   yLOG_info    ("my.verb"   , my.verb);
   switch (my.verb [0]) {
   case 'P'  :  if      (strcmp (my.verb, "PREP"     ) == 0) {
                   CODE_prep   ();
                }
                break;
   case 'i'  :  if      (strcmp (my.verb, "incl"     ) == 0) {
                   CODE_incl   ();
                }
                break;
   case 'S'  :  if      (strcmp (my.verb, "SCRP"     ) == 0) {
                   CODE_main   ();
                   CODE_scrp   ();
                }
                else if (strcmp (my.verb, "SECT"     ) == 0) {
                   CODE_main   ();
                   CODE_sect   ();
                }
                else if (strcmp (my.verb, "SHARED"   ) == 0) {
                   CODE_main   ();
                   CODE_shared ();
                }
                break;
   case 'G'  :  if      (strcmp (my.verb, "GROUP"    ) == 0) {
                   CODE_group  ();
                }
                break;
   case 'C'  :  if      (strcmp (my.verb, "COND"     ) == 0) {
                   CODE_cond   ();
                }
                break;
   case 'D'  : 
                DEBUG_OUTP   yLOG_note    ("nothing to write");
                break;
   case 'U'  :  if      (strcmp (my.verb, "USE_SHARE") == 0) {
                   CODE_use    ();
                }
                break;
   case 'm'  :  if      (strcmp (my.verb, "mode"     ) == 0) {
                   CODE_mode   ();
                }
                break;
   case 'c'  :  if      (strcmp (my.verb, "code"     ) == 0) {
                   CODE_code   ();
                }
                break;
   case 'l'  :  if      (strcmp (my.verb, "load"     ) == 0) {
                   CODE_load   ();
                }
                break;
   case 's'  :  if      (strcmp (my.verb, "sys"      ) == 0) {
                   /*> CODE_exec   ();                                                <*/
                }
                break;
   case 'e'  :  if      (strcmp (my.verb, "exec"     ) == 0) {
                   CODE_exec   ();
                }
                else if (strcmp (my.verb, "echo"     ) == 0) {
                   CODE_echo   ();
                }
                break;
   case 'g'  :  if      (strcmp (my.verb, "get"      ) == 0) {
                   CODE_exec   ();
                }
                break;
   case '#'  :  break;
   default   :  CODE_unknown ();
                break;
   }
   /*---(complete)-----------------------*/
   DEBUG_OUTP   yLOG_exit    (__FUNCTION__);
   return 0;
}


/*===============================[[ end code ]]===============================*/
