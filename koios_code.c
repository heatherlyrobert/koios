/*===============================[[ beg-code ]]===============================*/
#include    "koios.h"        /* LOCAL  : main header                          */




char        CODE_cond_end      (void);



static int  s_master_cond   [26];          /* count of cond in each share    */
static int  s_master_step   [26];          /* count of step in each share    */
static int  s_reuses_cond   [26];          /* count of cond in each share    */
static int  s_reuses_step   [26];          /* count of step in each share    */



static int  s_nscrp  = 0;
static int  s_ncond  = 0;
static int  s_nstep  = 0;

static int  s_scond  = 0;
static int  s_sstep  = 0;

static int  s_cstep  = 0;




char
CODE__defense           (FILE *a_code, cchar a_runtype, cchar a_verb [LEN_LABEL], cchar a_desc [LEN_LONG], cchar a_meth [LEN_HUND], cchar a_args [LEN_FULL], cchar a_test [LEN_LABEL], cchar a_expe [LEN_RECD], cchar a_retn [LEN_FULL], cchar a_stage [LEN_SHORT])
{
   char        rce         =  -10;
   --rce;  if (a_code   == NULL)  return rce;
   --rce;  if (a_verb   == NULL)  return rce;
   --rce;  if (a_desc   == NULL)  return rce;
   --rce;  if (a_meth   == NULL)  return rce;
   --rce;  if (a_args   == NULL)  return rce;
   --rce;  if (a_test   == NULL)  return rce;
   --rce;  if (a_expe   == NULL)  return rce;
   --rce;  if (a_retn   == NULL)  return rce;
   --rce;  if (a_stage  == NULL)  return rce;
   return 0;
}



/*====================------------------------------------====================*/
/*===----                      statistics handling                     ----===*/
/*====================------------------------------------====================*/
static void  o___STATS___________o () { return; }

char
CODE__stats_debug       (char *a_called)
{
   /*> printf ("%-10.10s  %-4d  %-10.10s   %3d   %3d %3d   %3d %3d %3d\n",            <* 
    *>       a_called,                                                                <* 
    *>       my.n_line, my.verb,                                                      <* 
    *>       s_nscrp,                                                                <* 
    *>       s_ncond, s_scond,                                                      <* 
    *>       s_nstep, s_sstep, s_cstep);                                           <*/
   return 0;
}

char
CODE__stats_purge       (void)
{
   s_nscrp  = 0;
   s_ncond  = s_scond = 0;
   s_nstep  = s_sstep = s_cstep = 0;
   CODE__stats_debug ("purge"    );
   return 0;
}

char
CODE__stats_scrp_beg    (void)
{
   ++(s_nscrp);
   CODE__stats_debug ("scrp_beg" );
   return 0;
}

char
CODE__stats_scrp_end    (void)
{
   s_scond  = 0;
   s_sstep  = s_cstep  = 0;
   CODE__stats_debug ("scrp_end" );
   /*> printf ("\n");                                                                 <*/
   return 0;
}

char
CODE__stats_cond_beg    (void)
{
   ++(s_ncond);
   ++(s_scond);
   CODE__stats_debug ("cond_beg" );
   return 0;
}

char
CODE__stats_cond_end    (void)
{
   s_cstep  = 0;
   CODE__stats_debug ("cond_end" );
   return 0;
   return 0;
}

char
CODE__stats_step        (void)
{
   ++(s_nstep);
   ++(s_sstep);
   ++(s_cstep);
   CODE__stats_debug ("step"     );
   return 0;
}




/*====================------------------------------------====================*/
/*===----                       shared data                            ----===*/
/*====================------------------------------------====================*/
static void  o___SHARED__________o () { return; }

char
CODE__shared_clear       (cchar a_type)
{
   /*---(locals)-------------------------*/
   int         i           =    0;
   /*---(set defaults)-------------------*/
   for (i = 0; i < 26; ++i) {
      switch (a_type) {
      case T_MASTER :
         s_master_cond [i] = 0;
         s_master_step [i] = 0;
         break;
      case T_SHARES :
         s_reuses_cond [i] = 0;
         s_reuses_step [i] = 0;
         break;
      }
   }
   /*---(complete)-----------------------*/
   return 0;
}

char
CODE__shared_purge       (void)
{
   CODE__shared_clear (T_MASTER);
   CODE__shared_clear (T_SHARES);
   return 0;
}

char
CODE__shared_index       (cchar a_type, cchar a_mark)
{
   /*---(locals)-------------------------*/
   char        rce         =  -10;
   char       *x_valid     = NULL;
   char        i           =  -10;
   /*---(set type)-----------------------*/
   --rce;  switch (a_type) {
   case T_MASTER : x_valid = YSTR_UPPER;   break;
   case T_SHARES : x_valid = YSTR_LOWER;   break;
   default       : return rce;             break;
   }
   /*---(defense)------------------------*/
   --rce;  if (a_mark == 0)                        return rce;
   --rce;  if (strchr (x_valid , a_mark) == NULL)  return rce;
   /*---(update list)--------------------*/
   i = a_mark - x_valid [0];
   /*---(complete)-----------------------*/
   return i;
}

char
CODE__shared_set         (cchar a_type, cchar a_mark, int a_cond, int a_step)
{
   /*---(locals)-------------------------*/
   char        i           =  -10;
   /*---(get index)----------------------*/
   i = CODE__shared_index (a_type, a_mark);
   if (i < 0) return i;
   /*---(update list)--------------------*/
   switch (a_type) {
   case T_MASTER :
      s_master_cond [i] = a_cond;
      s_master_step [i] = a_step;
      break;
   case T_SHARES :
      s_reuses_cond [i] = a_cond;
      s_reuses_step [i] = a_step;
      break;
   }
   /*---(complete)-----------------------*/
   return 0;
}

char
CODE__shared_add         (cchar a_type, cchar a_mark, int *a_cond, int *a_step)
{
   /*---(locals)-------------------------*/
   char        rce         =  -10;
   char        i           =  -10;
   /*---(get index)----------------------*/
   i = CODE__shared_index (a_type, a_mark);
   if (i < 0) return i;
   /*---(update list)--------------------*/
   switch (a_type) {
   case T_MASTER : 
      if (a_cond != NULL)  *a_cond += s_master_cond [i];
      if (a_step != NULL)  *a_step += s_master_step [i];
      break;
   case T_SHARES :
      if (a_cond != NULL)  *a_cond += s_reuses_cond [i];
      if (a_step != NULL)  *a_step += s_reuses_step [i];
      break;
   }
   /*---(complete)-----------------------*/
   return 0;
}

char*
CODE__shared_used        (void)
{
   /*---(locals)-------------------------*/
   int         i           =    0;
   /*---(default)------------------------*/
   for (i = 0; i < (26 + 3 + 26); ++i) {
      my.d_used [i] = ' ';
   }
   my.d_used [i] = '\0';
   /*---(master)-------------------------*/
   for (i = 0; i < 26; ++i) {
      if      (s_master_cond [i] <=  0)    my.d_used [i +  0] = '-';
      else if (s_master_cond [i] >  62)    my.d_used [i +  0] = '*';
      else                                 my.d_used [i +  0] = YSTR_CHARS [s_master_step [i]];
   }
   /*---(reuses)-------------------------*/
   for (i = 0; i < 26; ++i) {
      if      (s_reuses_cond [i] <=  0)    my.d_used [i + 29] = '-';
      else if (s_reuses_cond [i] >  62)    my.d_used [i + 29] = '*';
      else                                 my.d_used [i + 29] = YSTR_CHARS [s_reuses_step [i]];
   }
   /*---(complete)-----------------------*/
   return my.d_used;
}

char
CODE_shared_out         (void)
{
   char        rce         =  -10;
   FILE       *f           = NULL;
   int         i           =    0;
   f = fopen ("master.stats", "wt");
   --rce;  if (f == NULL)  return rce;
   for (i = 0; i < 26; ++i) {
      fprintf (f, "%4d %4d\n", s_master_cond [i], s_master_step [i]);
   }
   fclose (f);
   return 0;
}

char
CODE_shared_in          (void)
{
   char        rce         =  -10;
   char        rc          =    0;
   FILE       *f           = NULL;
   int         i           =    0;
   int         x_cond      =    0;
   int         x_step      =    0;
   f = fopen ("master.stats", "rt");
   --rce;  if (f == NULL)  return rce;
   for (i = 0; i < 26; ++i) {
      fscanf  (f, "%4d %4d\n", &x_cond, &x_step);
      rc = CODE__shared_set (T_MASTER, 'A' + i, x_cond, x_step);
      rc = SCRP__shared_set (T_MASTER, 'A' + i, 0);
   }
   fclose (f);
   return 0;
}



/*====================------------------------------------====================*/
/*===----                       file handling                          ----===*/
/*====================------------------------------------====================*/
static void  o___FILES___________o () { return; }

char         /*--> open code file ------------------------[ leaf   [ ------ ]-*/
CODE_open          (void)
{
   /*---(locals)-----------+-----------+-*/
   char        rce         = -10;           /* return code for errors         */
   /*---(header)-------------------------*/
   DEBUG_PROG   yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   DEBUG_OUTP   yLOG_info    ("n_code"    , my.n_code);
   DEBUG_OUTP   yLOG_point   ("f_code"    , my.f_code);
   --rce;  if (my.f_code != NULL) {
      DEBUG_PROG   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_OUTP   yLOG_info    ("n_main"    , my.n_main);
   DEBUG_OUTP   yLOG_point   ("f_main"    , my.f_main);
   --rce;  if (my.f_main != NULL) {
      DEBUG_PROG   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*> DEBUG_OUTP   yLOG_info    ("n_wave"    , my.n_wave);                           <*/
   /*> DEBUG_OUTP   yLOG_point   ("f_wave"    , my.f_wave);                           <*/
   /*> --rce;  if (my.f_wave != NULL) {                                               <* 
    *>    DEBUG_PROG   yLOG_exitr   (__FUNCTION__, rce);                              <* 
    *>    return rce;                                                                 <* 
    *> }                                                                              <*/
   /*---(open output file)---------------*/
   my.f_code = fopen (my.n_code, "wt");
   DEBUG_OUTP   yLOG_point   ("f_code"    , my.f_code);
   --rce;  if (my.f_code == NULL) {
      DEBUG_PROG   yLOG_fatal   ("can not open code file");
      DEBUG_PROG   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   DEBUG_OUTP   yLOG_note    ("code file open");
   /*---(open main file)-----------------*/
   my.f_main = fopen (my.n_main, "wt");
   DEBUG_OUTP   yLOG_point   ("f_main"    , my.f_main);
   --rce;  if (my.f_main == NULL) {
      DEBUG_PROG   yLOG_fatal   ("can not open main file");
      CODE_close (my.f_code);
      DEBUG_PROG   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   DEBUG_OUTP   yLOG_note    ("main file open");
   /*---(open wave file)-----------------*/
   /*> printf ("n_wave = [%s]\n", my.n_wave);                                         <*/
   /*> my.f_wave = fopen (my.n_wave, "wt");                                           <* 
    *> DEBUG_OUTP   yLOG_point   ("f_wave"    , my.f_wave);                           <* 
    *> --rce;  if (my.f_wave == NULL) {                                               <* 
    *>    DEBUG_PROG   yLOG_fatal   ("can not open main file");                       <* 
    *>    CODE_close (my.f_code);                                                     <* 
    *>    CODE_close (my.f_main);                                                     <* 
    *>    DEBUG_PROG   yLOG_exit    (__FUNCTION__);                                   <* 
    *>    return rce;                                                                 <* 
    *> }                                                                              <*/
   /*> DEBUG_OUTP   yLOG_note    ("wave file open");                                  <*/
   /*---(complete)-----------------------*/
   DEBUG_PROG   yLOG_exit    (__FUNCTION__);
   return 0;
}

char
CODE_printf             (char *a_format, ...)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   va_list     x_vlist;
   /*---(defense)------------------------*/
   --rce;  if (my.f_code == NULL)    return rce;
   --rce;  if (a_format  == NULL)    return rce;
   /*---(write)--------------------------*/
   va_start (x_vlist, a_format);
   vfprintf (my.f_code, a_format, x_vlist);
   /*> printf   ("%s", a_format);                                                     <*/
   va_end   (x_vlist);
   fflush   (my.f_code);
   /*---(complete)-------------------------*/
   return 0;
}

char
MAIN_printf             (char *a_format, ...)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   va_list     x_vlist;
   /*---(defense)------------------------*/
   --rce;  if (my.f_main == NULL)    return rce;
   --rce;  if (a_format  == NULL)    return rce;
   /*---(write)--------------------------*/
   va_start (x_vlist, a_format);
   vfprintf (my.f_main, a_format, x_vlist);
   va_end   (x_vlist);
   fflush   (my.f_main);
   /*---(complete)-------------------------*/
   return 0;
}

char         /*--> close code file -----------------------[ ------ [ ------ ]-*/
CODE_close         (FILE *a_file)
{
   /*---(locals)-----------+-----------+-*/
   char        rce         =  -10;
   char        rc          =    0;
   /*---(header)-------------------------*/
   DEBUG_PROG   yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   DEBUG_OUTP   yLOG_point   ("a_file"    , a_file);
   --rce;  if (a_file == NULL) {
      DEBUG_PROG   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(close)--------------------------*/
   if (a_file == my.f_code)   rc = fclose (my.f_code);
   if (a_file == my.f_main)   rc = fclose (my.f_main);
   /*> if (a_file == my.f_wave)   rc = fclose (my.f_wave);                            <*/
   --rce;  if (rc != 0) {
      DEBUG_PROG   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(ground)-------------------------*/
   if (a_file == my.f_code)   my.f_code = NULL;
   if (a_file == my.f_main)   my.f_main = NULL;
   /*> if (a_file == my.f_wave)   my.f_wave = NULL;                                   <*/
   /*---(complete)-----------------------*/
   DEBUG_PROG   yLOG_exit    (__FUNCTION__);
   return 0;
}

char
CODE_cycle              (void)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        t           [LEN_RECD]  = "";
   /*---(defense)------------------------*/
   --rce;  if (my.f_code == NULL)    return rce;
   --rce;  if (my.f_main == NULL)    return rce;
   /*> --rce;  if (my.f_wave == NULL)    return rce;                                  <*/
   /*---(write)--------------------------*/
   CODE_close  (my.f_code);
   CODE_close  (my.f_main);
   /*> CODE_close  (my.f_wave);                                                       <*/
   sprintf (t, "rm -f %s 2> /dev/null", my.n_code);
   system  (t);
   sprintf (t, "rm -f %s 2> /dev/null", my.n_main);
   system  (t);
   /*> sprintf (t, "rm -f %s 2> /dev/null", my.n_wave);                               <* 
    *> system  (t);                                                                   <*/
   CODE_open   ();
   /*---(complete)-------------------------*/
   return 0;
}



/*====================------------------------------------====================*/
/*===----                     beginnings and endings                   ----===*/
/*====================------------------------------------====================*/
static void  o___ENDS____________o () { return; }

char
CODE_beg                (void)
{
   int         i           = 0;
   CODE_printf ("/*================================= beg-code =================================*/\n");
   CODE_printf ("/* /usr/local/bin/koios                                                       */\n");
   CODE_printf ("/*   autogen by %-60.60s  */\n", P_ONELINE);
   IF_NORMAL {
      CODE_printf ("\n");
      CODE_printf ("/*---(standard support functions)----*/\n");
      CODE_printf ("#include    <yUNIT_unit.h>\n");
      CODE_printf ("#include    \"master.h\"\n");
      CODE_printf ("\n");
      CODE_printf ("/*================================ beg-script ================================*/\n");
   } else {
      CODE_printf ("\n");
      CODE_printf ("/*================================ beg-global ================================*/\n");
   }
   /*---(initialize variables)-----------*/
   CODE__stats_purge  ();
   my.cshare = '-';
   return 0;
}

char
CODE_end           (void)
{
   strcpy (my.verb, "EOF");
   if (s_nscrp > 0 || my.cshare != '-') {
      strlcpy (my.last, my.verb, LEN_LABEL);
      CODE_scrp_end ();
   }
   IF_NORMAL {
      CODE_printf ("/*================================ end-script ================================*/\n");
   } else {
      CODE_printf ("/*================================ end-global ================================*/\n");
   }
   return 0;
}

char
MAIN_beg                (void)
{
   int         i           = 0;
   MAIN_printf ("\n\n\n");
   MAIN_printf ("int\n");
   MAIN_printf ("main                    (int a_argc, char *a_argv[])\n");
   MAIN_printf ("{\n");
   MAIN_printf ("   /*---(locals)-----------+-----+-----+-*/\n");
   MAIN_printf ("   int         rc          =    0;\n");
   MAIN_printf ("   /*---(prepare)------------------------*/\n");
   MAIN_printf ("   rc = yUNIT_init ();\n");
   MAIN_printf ("   rc = yUNIT_args (a_argc, a_argv);\n");
   MAIN_printf ("   if (rc < 0)  return -1;\n");
   MAIN_printf ("   yUNIT_unit (\"%s\", cyUNIT.level, cyUNIT.eterm, cyUNIT.exec);\n", my.n_base);
   MAIN_printf ("   /*---(beg scripts)--------------------*/\n");
   return 0;
}

char
MAIN_end           (void)
{
   MAIN_printf ("   /*---(end scripts)--------------------*/\n");
   MAIN_printf ("   rc = yUNIT_tinu (cyUNIT.exec);\n");
   MAIN_printf ("   /*---(complete)-----------------------*/\n");
   MAIN_printf ("   return rc;\n");
   MAIN_printf ("}\n");
   MAIN_printf ("\n\n\n");
   MAIN_printf ("/* end-of-file.  done, finito, completare, whimper [Ï´···                     */\n");
   MAIN_printf ("/*================================= end-code =================================*/\n");
   return 0;
}

char
CODE_stats         (void)
{
   CODE_printf ("\n");
   CODE_printf ("char\n");
   CODE_printf ("yUNIT_stats     (void)\n");
   CODE_printf ("{\n");
   CODE_printf ("   yUNIT_unique (%d, %d, %d);\n", s_nscrp, s_ncond, s_nstep);
   CODE_printf ("   return 0;\n");
   CODE_printf ("}\n");
   CODE_printf ("\n");
   return 0;
}

char
MAIN_append        (void)
{
   char        x_recd      [LEN_RECD];
   CODE_stats     ();
   SCRP_verbcode  ();
   CODE_close (my.f_main);
   my.f_main = fopen (my.n_main, "rt");
   while (1) {
      fgets (x_recd, LEN_RECD, my.f_main);
      if (feof (my.f_main)) break;
      CODE_printf (x_recd);
   }
   CODE_close (my.f_main);
   return 0;
}

char
CODE_prep          (void)
{
   return 0;
}

char
CODE_incl          (void)
{
   char        t           [LEN_HUND]  = "";
   sprintf (t, "\"%s\"", my.meth);
   CODE_printf ("#include    %-22.22s  /* %4i, %-32.32s */\n", t, my.n_line, my.desc);
   return 0;
}



/*====================------------------------------------====================*/
/*===----                      script level verbs                      ----===*/
/*====================------------------------------------====================*/
static void  o___SCRP____________o () { return; }

char
CODE_scrp_end        (void)
{
   if (strcmp (my.last, "SECT") == 0)    return 0;
   /*---(close final condition)----------*/
      if (s_cstep > 0)  CODE_cond_end ();
   /*> printf ("s_cstep %4d, my.verb å%sæ\n", s_cstep, my.verb);                    <*/
   /*---(end share)----------------------*/
   if (my.cshare != '-') {
      if (my.cshare == tolower (my.cshare))  CODE__shared_set (T_SHARES, my.cshare, s_scond, s_sstep);
      else                                   CODE__shared_set (T_MASTER, my.cshare, s_scond, s_sstep);
   }
   /*---(close script/share)-------------*/
   if (s_nscrp >  0 || my.cshare != '-') {
      if (my.cshare == '-') {
         CODE_printf ("   /*===[[ script done ]]==========================*/\n");
         CODE_printf ("   yUNIT_prcs    (cyUNIT.exec);\n");
      }
      else if (my.cshare == tolower (my.cshare)) {
         CODE_printf ("   /*===[[ shared done ]]==========================*/\n");
         CODE_printf ("   yUNIT_erahs ('%c');\n", my.cshare);
         s_ncond -= s_scond;
         s_nstep -= s_sstep;
      }
      else {
         CODE_printf ("   /*===[[ global done ]]==========================*/\n");
         CODE_printf ("   yUNIT_labolg ('%c');\n", my.cshare);
         s_ncond -= s_scond;
         s_nstep -= s_sstep;
      }
      CODE_printf ("   /*---(complete)-----------------------*/\n");
      CODE_printf ("   return 0;\n");
      CODE_printf ("}\n");
   }
   /*---(initialize vars)----------------*/
   CODE__stats_scrp_end ();
   /*---(complete)-----------------------*/
   return 0;
}

/*> char                                                                                                                                                                                                                                                    <* 
 *> CODE_scrp               (char a_nscrp, int a_line, char r_stage [LEN_TERSE], char r_desc [LEN_LONG], char r_meth [LEN_HUND], char r_args [LEN_FULL], char r_test [LEN_LABEL], char r_expe [LEN_RECD], char r_retn [LEN_FULL], char r_code [LEN_RECD])   <*/
char
CODE_scrp          (void)
{
   char        t           [LEN_HUND]  = "";
   char        s           [LEN_HUND]  = "";
   char        x_stage     = '-';
   char        x_wave      = '-';
   /*---(end last script)----------------*/
   CODE_scrp_end ();
   my.cshare = '-';
   if (strlen (my.test)  == 0)  strcpy (my.test, "0s");
   if (strlen (my.retn)  == 0)  strcpy (my.retn, "tbd");
   /*---(counters)-----------------------*/
   CODE__stats_scrp_beg ();
   /*---(open script function)-----------*/
   CODE_printf ("\n");
   CODE_printf ("char\n");
   CODE_printf ("yUNIT_script_%02d          (void)\n", s_nscrp);
   CODE_printf ("{\n");
   CODE_printf ("   /*===[[ script header ]]========================*/\n");
   CODE_printf ("   cyUNIT.offset  = 0;\n");
   CODE_printf ("   cyUNIT.origin  = %d;\n", s_nscrp);
   CODE_printf ("   yUNIT_mode_reset ();\n");
   CODE_printf ("   yUNIT_scrp    (%4i, %3i, \"%s\", \"%s\", \"%s\", \"%s\", \"%s\");\n", my.n_line, s_nscrp, my.stage, my.desc, my.test, my.retn, my.meth);
   /*---(function call to main)----------*/
   /*> MAIN_printf ("   if (cyUNIT.scrp == YUNIT_ALL  || cyUNIT.scrp == %2i)  yUNIT_script_%02d ();\n", s_nscrp, s_nscrp);   <*/
   MAIN_printf ("   if (yUNIT_run_scrp (%2i) == 1)  yUNIT_script_%02d ();\n", s_nscrp, s_nscrp);
   /*---(script entry in wave)-----------*/
   if (strlen (my.stage) == 2) {
      x_stage = my.stage [0];
      x_wave  = my.stage [1];
   }
   WAVE_scrp   (x_stage, x_wave, my.n_base, s_nscrp, my.desc);
   /*---(complete)-----------------------*/
   return 0;
}

char         /*-> common shared code between scripts ---[ ------ [----------]-*/
CODE_shared          (void)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   /*---(end last script)----------------*/
   /*> printf ("CODE_shared     my line %4d, my verb å%sæ, my.share å%cæ\n", my.n_line, my.verb, my.share);   <*/
   CODE_scrp_end ();
   /*---(counters)-----------------------*/
   my.cshare = my.share;
   CODE__shared_set (T_SHARES, my.cshare,  0,  0);
   /*---(open script function)-----------*/
   CODE_printf ("\n");
   CODE_printf ("char\n");
   CODE_printf ("yUNIT_shared_%c           (void)\n", my.cshare);
   CODE_printf ("{\n");
   CODE_printf ("   /*===[[ shared header ]]========================*/\n");
   CODE_printf ("   yUNIT_share ('%c', \"%s\");\n", my.cshare, my.desc);
   /*---(complete)-----------------------*/
   return 0;
}

char
CODE_sect          (void)
{
   /*---(end last script)----------------*/
   CODE_scrp_end ();
   /*---(add section)--------------------*/
   MAIN_printf ("   if (cyUNIT.all  ==  1)                  yUNIT_sect      (\"%s\");\n", my.desc);
   /*---(complete)-----------------------*/
   return 0;
}

char         /*-> common shared code between units -----[ ------ [----------]-*/
CODE_global          (void)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   /*---(end last script)----------------*/
   CODE_scrp_end ();
   /*---(counters)-----------------------*/
   my.cshare = my.share;
   CODE__shared_set (T_MASTER, my.cshare,  0,  0);
   /*---(open script function)-----------*/
   CODE_printf ("\n");
   CODE_printf ("char\n");
   CODE_printf ("yUNIT_shared_%c           (void)\n", my.cshare);
   CODE_printf ("{\n");
   CODE_printf ("   /*===[[ global header ]]========================*/\n");
   CODE_printf ("   yUNIT_global ('%c', \"%s\");\n", my.cshare, my.desc);
   /*---(complete)-----------------------*/
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
   DEBUG_OUTP   yLOG_complex ("counters"  , "%-10.10p, %-10.10s, %4dn, %4dc", my.f_code, my.last, s_ncond, s_scond);
   if (strstr ("GROUP REUSE", my.last) == NULL) {
      if (s_scond > 0) {
         /*> printf ("   writing yUNIT_dnoc\n\n");                                    <*/
         CODE_printf ("      /*---(summary)---------------------*/\n");
         CODE_printf ("      yUNIT_dnoc    (cyUNIT.exec);\n");
         CODE_printf ("      /*---(done)------------------------*/\n");
      }
   }
   CODE__stats_cond_end ();
   /*---(complete)-----------------------*/
   DEBUG_OUTP   yLOG_exit    (__FUNCTION__);
   return 0;
}

char
CODE_cond          (void)
{
   char        a           =    0;
   char        t           [LEN_RECD]  = "";
   /*---(header)-------------------------*/
   DEBUG_OUTP   yLOG_enter   (__FUNCTION__);
   CODE_cond_end ();
   CODE__stats_cond_beg ();
   DEBUG_OUTP   yLOG_complex ("counters"  , "%-10.10p, %-10.10s, %4dn, %4dc", my.f_code, my.last, s_ncond, s_scond);
   CODE_printf ("   /*===[[ COND #%03i ]]============================*/\n", s_scond);
   /*> CODE_printf ("   if (cyUNIT.cond == cyUNIT.offset + %3i)  yUNIT_level (YUNIT_FULL, 'y'); else yUNIT_level (cyUNIT.level, 'y');\n", s_scond);   <*/
   if (my.run_type == G_RUN_DEBUG) {
      CODE_printf ("   %sUG_PROG    %sOG_unitcond (cyUNIT.origin, cyUNIT.offset + %3i, %4i, \"%s\");\n", "DEB", "yL", s_scond, my.n_line, my.desc);
   }
   if (my.dittoing == 'y') {
      /*> printf ("inside a ditto (%c)\n", my.dmark);                                 <*/
      /*> sprintf (my.compiled , "   yUNIT_cond    (%4i, cyUNIT.offset + %3i, '%c', \"%s\");", my.n_line, s_scond, my.mark      , my.desc);   <*/
      sprintf (my.compiled , "   yUNIT_cond    (%4i, cyUNIT.offset + %3i, '%c', \"%s\");", my.n_line, s_scond, my.dmark , my.desc);
   } else if (my.mark != '-') {
      /*> printf ("found a cond (%c)\n", my.mark);                                    <*/
      a = my.mark - '0' + ' ';
      sprintf (my.compiled , "   yUNIT_cond    (%4i, cyUNIT.offset + %3i, '%c', \"%s\");", my.n_line, s_scond, a        , my.desc);
   } else {
      sprintf (my.compiled , "   yUNIT_cond    (%4i, cyUNIT.offset + %3i, '%c', \"%s\");", my.n_line, s_scond, my.cshare, my.desc);
   }
   DEBUG_OUTP   yLOG_complex ("output"    , "%3d:%s", strlen (my.compiled), my.compiled);
   CODE_printf ("%s\n", my.compiled);
   /*---(complete)-----------------------*/
   DEBUG_OUTP   yLOG_exit    (__FUNCTION__);
   return 0;
}

char
CODE_group         (void)
{
   /*> printf ("CODE_group      my line %4d, my verb å%sæ, my last å%sæ\n", my.n_line, my.verb, my.last);   <*/
   CODE_cond_end ();
   CODE_printf ("   /*---(group)--------------------------*/\n");
   CODE_printf ("   yUNIT_group   (\"%s\");\n", my.desc);
   return 0;
}

char
CODE_reuse         (void)
{
   char        rce         =  -10;
   /*---(header)-------------------------*/
   DEBUG_OUTP   yLOG_enter   (__FUNCTION__);
   /*> printf ("CODE_reuse      my line %4d, my verb å%sæ, my.share å%cæ\n", my.n_line, my.verb, my.share);   <*/
   CODE_cond_end ();
   --rce;  if (strchr (YSTR_CHARS, my.share) == NULL)  return rce;
   CODE_printf ("   /*---(shared code)-----------------------*/\n");
   CODE_printf ("   cyUNIT.offset = %3i;\n", s_scond);
   CODE_printf ("   yUNIT_shared_%c ();\n", my.share);
   CODE_printf ("   cyUNIT.offset = 0;\n");
   if (tolower (my.share) == my.share) {
      CODE__shared_add (T_SHARES, my.share, &(s_ncond), &(s_nstep));
      CODE__shared_add (T_SHARES, my.share, &(s_scond), &(s_sstep));
      s_cstep = s_sstep;
   } else {
      CODE__shared_add (T_MASTER, my.share, &(s_ncond), &(s_nstep));
      CODE__shared_add (T_MASTER, my.share, &(s_scond), &(s_sstep));
      s_cstep = s_sstep;
   }
   /*---(complete)-----------------------*/
   DEBUG_OUTP   yLOG_exit    (__FUNCTION__);
   return 0;
}



/*====================------------------------------------====================*/
/*===----                         step support                         ----===*/
/*====================------------------------------------====================*/
static void  o___STEP_SUPPORT____o () { return; }

static char   s_disp       [LEN_RECD]  = "";
static char   s_syst       [LEN_RECD]  = "";
static char   s_load       [LEN_RECD]  = "";

int
CODE__myline            (void)
{
   if (my.dittoing == 'y') return my.dline;
   return my.n_line;
}

char
CODE__display           (cchar a_code [LEN_RECD], char r_display [LEN_RECD], char r_system [LEN_RECD], char r_load [LEN_RECD])
{
   /*---(locals)-----------+-----------+-*/
   char        rce         =  -10;
   int         i           =    0;
   int         x_len       =    0;
   char        t           [LEN_TERSE] = "";
   char        x_disp      [LEN_RECD]  = "";
   char        x_syst      [LEN_RECD]  = "";
   char        x_load      [LEN_RECD]  = "";
   /*---(default)------------------------*/
   if (r_display  != NULL)  strcpy (r_display, "");
   if (r_system   != NULL)  strcpy (r_system , "");
   if (r_load     != NULL)  strcpy (r_load   , "");
   /*---(defense)------------------------*/
   --rce;  if (a_code == NULL)  return rce;
   /*---(prepare)------------------------*/
   x_len = strlen (a_code);
   strlcpy (x_disp, a_code , LEN_RECD);
   strlcpy (x_syst, ""     , LEN_RECD);
   strlcpy (x_load, ""     , LEN_RECD);
   /*---(cleanse)------------------------*/
   for (i = 0; i < x_len; ++i) {
      switch ((unsigned char) a_code [i]) {
      case  G_CHAR_FIELD  : case  G_KEY_FIELD   :
         x_disp [i]  = G_CHAR_FIELD;
         sprintf (t, "%c", G_KEY_FIELD);
         strlcat (x_syst, t, LEN_RECD);
         strlcat (x_load, t, LEN_RECD);
         break;
      case  G_CHAR_GROUP  : case  G_KEY_GROUP   :
         x_disp [i]  = G_CHAR_GROUP;
         sprintf (t, "%c", G_KEY_FIELD);
         strlcat (x_syst, t, LEN_RECD);
         strlcat (x_load, t, LEN_RECD);
         break;
      case  G_KEY_DQUOTE  :
         x_disp [i]  = G_CHAR_DDQUOTE;
         sprintf (t, "%c", G_KEY_DQUOTE);
         strlcat (x_syst, t, LEN_RECD);
         sprintf (t, "%c", G_KEY_TILDA);
         strlcat (x_load, t, LEN_RECD);
         break;
      case  G_KEY_RETURN :
         x_disp [i]  = G_CHAR_RETURN;
         sprintf (t, "\\n");
         strlcat (x_syst, t, LEN_RECD);
         strlcat (x_load, t, LEN_RECD);
         break;
      case  G_KEY_ESCAPE :
         x_disp [i]  = G_CHAR_ESCAPE;
         sprintf (t, "\\e");
         strlcat (x_syst, t, LEN_RECD);
         strlcat (x_load, t, LEN_RECD);
         break;
      default  :
         x_disp [i]  = a_code [i];
         sprintf (t, "%c", a_code [i]);
         strlcat (x_syst, t, LEN_RECD);
         strlcat (x_load, t, LEN_RECD);
         break;
      }
   }
   /*---(save-back)----------------------*/
   if (r_display  != NULL)  strlcpy (r_display, x_disp, LEN_RECD);
   if (r_system   != NULL)  strlcpy (r_system , x_syst, LEN_RECD);
   if (r_load     != NULL)  strlcpy (r_load   , x_load, LEN_RECD);
   /*---(complete)-----------------------*/
   return 0;
}

char
CODE__prefix            (FILE *a_code, cchar a_verb [LEN_LABEL], cchar a_desc [LEN_LONG], cchar a_method [LEN_HUND], cchar a_test [LEN_LABEL], cchar a_display [LEN_RECD], cchar a_system [LEN_RECD])
{
   /*---(locals)-----------+-----------+-*/
   char        x_func      [LEN_FULL]   = "";
   /*---(run function)-------------------*/
   if (strcmp (a_verb, "echo") != 0) {
      CONV_printf_new (a_code, "      yUNIT_reset_rc ();\n");
      switch (a_test [0]) {
      case 'v'  :
         CONV_printf_new (a_code, "      if (cyUNIT.exec)  %s (%s);\n", a_method , a_system);
         break;
      case 's'  : case 'u'  : case 'w'  :
         CONV_printf_new (a_code, "      if (cyUNIT.exec)  cyUNIT.s_rc = %s (%s);\n", a_method , a_system);
         break;
      case 'i'  :
         CONV_printf_new (a_code, "      if (cyUNIT.exec)  cyUNIT.i_rc = %s (%s);\n", a_method , a_system);
         break;
      case 'r'  :
         CONV_printf_new (a_code, "      if (cyUNIT.exec)  cyUNIT.r_rc = %s (%s);\n", a_method , a_system);
         break;
      case 'p'  :
         CONV_printf_new (a_code, "      if (cyUNIT.exec)  cyUNIT.p_rc = %s (%s);\n", a_method , a_system);
         break;
      }
   }
   /*---(determine function)-------------*/
   switch (a_test [0]) {
   case 'v'  : strlcpy (x_func, "yUNIT_void"     , LEN_FULL);    break;
   case 's'  : strlcpy (x_func, "yUNIT_string"   , LEN_FULL);    break;
   case 'w'  : strlcpy (x_func, "yUNIT_wrap"     , LEN_FULL);    break;
   case 'u'  : strlcpy (x_func, "yUNIT_round"    , LEN_FULL);    break;
   case 'i'  : strlcpy (x_func, "yUNIT_int"      , LEN_FULL);    break;
   case 'r'  : strlcpy (x_func, "yUNIT_real"     , LEN_FULL);    break;
   case 'p'  : strlcpy (x_func, "yUNIT_point"    , LEN_FULL);    break;
   default   : strlcpy (x_func, "yUNIT_unknown"  , LEN_FULL);    break;
   }
   /*---(write prefix)-------------------*/
   CONV_printf_new (a_code, "      ");
   CONV_printf_new (a_code, "%-13s ("              , x_func);
   CONV_printf_new (a_code, "%4i, %3i, "           , CODE__myline (), s_cstep);
   CONV_printf_new (a_code, "\"%s\", "             , a_desc);
   CONV_printf_new (a_code, "\"%s\", \"%s\", "     , a_method  , a_display);
   /*---(write test)---------------------*/
   switch (a_test [0]) {
   case 'v' :    /* pure void        */
      CONV_printf_new (a_code, "\"%s\", cyUNIT.exec);\n", a_test);
      break;
   default  :    /* all others       */
      CONV_printf_new (a_code, "\"%s\", "          , a_test);
      break;
      return 0;
   }
   /*---(complete)-----------------------*/
   return 0;
}

char
CODE__expect            (FILE *a_code, cchar a_test [LEN_LABEL], cchar a_expect [LEN_RECD])
{
   /*---(locals)-----------+-----------+-*/
   char       *p           = NULL;
   char       *q           = " ";
   char       *r           = NULL;
   char        x_var       [LEN_FULL ];
   char       *x_expe      = NULL;
   /*---(defense)------------------------*/
   if (a_test [0] == 'v')    return 0;
   /*---(normal)-------------------------*/
   if (strncmp (a_expect, "[[ ", 3) != 0) {
      switch (a_test [0]) {
      case 's' : case 'u' : case 'w' :      /* stringish   */
         CONV_printf_new (a_code, "\"%s\", " , a_expect);
         break;
      case 'i' : case 'p' : case 'r' :      /* numberish   */
         CONV_printf_new (a_code, "%s, "     , a_expect);
         break;
      default  :
         CONV_printf_new (a_code, "\"%s\", cyUNIT.exec);\n"         , a_expect);
         break;
      }
      return 1;
   }
   /*---(check for var)------------------*/
   else {
      strlcpy (x_var, a_expect + 3, LEN_RECD);
      x_expe = x_var;
      p = strtok_r (x_var, q, &r);
      if (p == NULL) CONV_printf_new (a_code, "\"%s\", " , "unknown");
      else           CONV_printf_new (a_code, "%s, "     , x_expe);
      return 2;
   }
   /*---(complete)-----------------------*/
   return -1;
}

char
CODE__suffix            (FILE *a_code, cchar a_verb [LEN_LABEL], cchar a_test [LEN_LABEL], cchar a_system [LEN_RECD], cchar a_return [LEN_FULL])
{
   /*---(defense)------------------------*/
   if (a_test [0] == 'v')    return 0;
   /*---(handle echos)-------------------*/
   if (strcmp (a_verb, "echo") == 0) {
      CONV_printf_new (a_code, "%s  , cyUNIT.exec);\n"      , a_system);
   }
   /*---(check for simple end)-----------*/
   else {
      switch (a_test [0]) {
      case 's'  : case 'u'  : case 'w'  :
         CONV_printf_new (a_code, "cyUNIT.s_rc, cyUNIT.exec);\n");
         break;
      case 'i'  :
         CONV_printf_new (a_code, "cyUNIT.i_rc, cyUNIT.exec);\n");
         break;
      case 'r'  :
         CONV_printf_new (a_code, "cyUNIT.r_rc, cyUNIT.exec);\n");
         break;
      case 'p'  :
         CONV_printf_new (a_code, "cyUNIT.p_rc, cyUNIT.exec);\n");
         break;
      }
   }
   /*---(handle return variables)--------*/
   if (strcmp (a_return, "") != 0) {
      switch (a_test [0]) {
      case 's'  : case 'u'  : case 'w'  :
         CONV_printf_new (a_code, "         if (cyUNIT.exec) { if (cyUNIT.s_rc != NULL)  strcpy (%s, cyUNIT.s_rc); else strcpy (x_str, ""); }\n", a_return);
         break;
      case 'i'  :
         CONV_printf_new (a_code, "         if (cyUNIT.exec)  %s = cyUNIT.i_rc;\n", a_return);
         break;
      case 'r'  :
         CONV_printf_new (a_code, "         if (cyUNIT.exec)  %s = cyUNIT.r_rc;\n", a_return);
         break;
      case 'p'  :
         CONV_printf_new (a_code, "         if (cyUNIT.exec)  %s = cyUNIT.p_rc;\n", a_return);
         break;
      }
   }
   /*---(complete)-----------------------*/
   return 1;
}



/*====================------------------------------------====================*/
/*===----                       step level verbs                       ----===*/
/*====================------------------------------------====================*/
static void  o___STEP____________o () { return; }

char
CODE_display       (void)
{
   /*---(locals)-----------+-----------+-*/
   int         i           = 0;
   int         x_len       = 0;
   char        t           [10]        = "";
   /*---(fix delimiters)-----------------*/
   /*> printf ("CODE_display ------------------------------\n");                      <*/
   /*> printf ("my.code <<%s>>\n", my.code);                                          <*/
   x_len = strlen (my.code);
   /*> printf ("length  %d\n", x_len);                                                <*/
   /*---(prepare)------------------------*/
   x_len = strlen (my.code);
   /*> printf ("length  %d\n", x_len);                                                <*/
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
         my.disp [i]  = G_CHAR_DDQUOTE;
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
   /*> printf ("my.disp <<%s>>\n", my.disp);                                          <*/
   /*> printf ("my.syst <<%s>>\n", my.syst);                                          <*/
   /*> printf ("my.load <<%s>>\n", my.load);                                          <*/
   /*---(complete)-----------------------*/
   return 0;
}

char
CODE__step_add     (FILE *a_code, cchar a_runtype, cchar a_desc [LEN_LONG])
{
   /*---(increment)----------------------*/
   ++(s_nstep);
   ++(s_sstep);
   ++(s_cstep);
   /*---(debugging)----------------------*/
   CONV_printf_new (a_code, "      /*---(run step)--------------------*/\n");
   if (my.run_type == G_RUN_DEBUG) {
      CONV_printf_new (a_code, "      %sUG_PROG    %sOG_unitstep (cyUNIT.origin, cyUNIT.offset + %3i, %3i, %4i, \"%s\");\n", "DEB", "yL", s_scond, s_cstep, CODE__myline (), a_desc);
   }
   /*---(complete)-----------------------*/
   return 0;
}

char
CODE_exec_new      (FILE *a_code, cchar a_runtype, cchar a_verb [LEN_LABEL], cchar a_desc [LEN_LONG], cchar a_method [LEN_HUND], cchar a_args [LEN_FULL], cchar a_test [LEN_LABEL], cchar a_expect [LEN_RECD], cchar a_return [LEN_FULL], cchar a_stage [LEN_SHORT])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rc          =    0;
   char        x_display   [LEN_RECD]  = "";
   char        x_system    [LEN_RECD]  = "";
   /*---(defense)------------------------*/
   rc = CODE__defense (a_code, a_runtype, a_verb, a_desc, a_method, a_args, a_test, a_expect, a_return, a_stage);
   if (rc < 0)  return rc;
   /*---(prepare)------------------------*/
   CODE__step_add  (a_code, a_runtype, a_desc);
   CODE__display   (a_expect, NULL, x_system, NULL);
   /*---(create)-------------------------*/
   CODE__prefix    (a_code, a_verb, a_desc, a_method, a_test, x_display, x_system);
   CODE__expect    (a_code, a_test, a_expect);
   CODE__suffix    (a_code, a_verb, a_test, x_system, a_return);
   /*---(complete)-----------------------*/
   return 0;
}

char
CODE_mode          (void)
{
   CODE__stats_step ();
   CODE_printf ("      /*---(mode)------------------------*/\n");
   CODE_printf ("      yUNIT_mode    (%4i, %3i, \"%s\", cyUNIT.exec);\n", CODE__myline (), s_cstep, my.desc);
   return 0;
}

char
CODE_gvar          (void)
{
   CODE_display ();
   CODE_printf ("/*---(global variables)------------*/\n");
   CODE_printf ("%s\n",  my.syst);
   return 0;
}

char
CODE_lvar          (void)
{
   /*---(counters)-----------------------*/
   CODE__stats_step ();
   /*---(fix strings)--------------------*/
   CODE_display ();
   /*---(write)--------------------------*/
   CODE_printf ("      /*---(setup local)-----------------*/\n");
   CODE_printf ("      %s\n",  my.syst);
   CODE_printf ("      yUNIT_local   (%4i, %3i, \"%s\", \"%s\", cyUNIT.exec);\n", CODE__myline (), s_cstep, my.desc, my.disp);
   /*---(complete)-----------------------*/
   return 0;
}

char
CODE_code          (void)
{
   /*---(counters)-----------------------*/
   CODE__stats_step ();
   /*---(fix strings)--------------------*/
   CODE_display ();
   /*---(write)--------------------------*/
   CODE_printf ("      /*---(inject code)-----------------*/\n");
   CODE_printf ("      if (cyUNIT.exec) { %s }\n",  my.syst);
   CODE_printf ("      yUNIT_code    (%4i, %3i, \"%s\", \"%s\", cyUNIT.exec);\n", CODE__myline (), s_cstep, my.desc, my.disp);
   /*---(complete)-----------------------*/
   return 0;
}

char
CODE_load          (void)
{
   /*---(locals)-----------+-----+-----+-*/
   int         x_len       =    0;
   char       *p           = NULL;
   char       *q           =  " ";
   char       *r           = NULL;
   char        x_temp      [LEN_FULL];
   char       *x_var       = NULL;
   /*---(counters)-----------------------*/
   CODE__stats_step ();
   /*---(fix strings)--------------------*/
   CODE_display ();
   CODE_printf ("      /*---(load input)------------------*/\n");
   CODE_printf ("      yUNIT_load    (%4i, %3i, \"%s\", \"%s\", ", CODE__myline (), s_cstep, my.desc, my.meth);
   /*---(check for var)------------------*/
   x_len = strlen (my.load);
   if        (x_len <= 7) {
      /*> printf ("small one\n");                                                     <*/
      CODE_printf ("\"%s\"", my.load);
   } else if (strncmp (my.code, "[[ ", 3) != 0) {
      /*> printf ("longer, not-variable one\n");                                      <*/
      CODE_printf ("\"%s\"", my.load);
   } else {
      /*> printf ("variable one\n");                                                  <*/
      strlcpy (x_temp, my.load + 3, LEN_FULL);
      x_var = x_temp;
      p = strtok_r (x_temp, q, &r);
      if (p == NULL) CODE_printf ("\"%s\"" , "unknown");
      else           CODE_printf ("%s" , x_var);
   }
   /*---(write)--------------------------*/
   CODE_printf (", cyUNIT.exec);\n");
   /*---(complete)-----------------------*/
   return 0;
}

char
CODE_file          (void)
{
   /*---(locals)-----------+-----+-----+-*/
   int         x_len       =    0;
   char       *p           = NULL;
   char       *q           =  " ";
   char       *r           = NULL;
   char        x_temp      [LEN_FULL];
   char       *x_var       = NULL;
   /*---(counters)-----------------------*/
   CODE__stats_step ();
   /*---(fix strings)--------------------*/
   CODE_display ();
   /*---(write)--------------------------*/
   CODE_printf ("      /*---(create file)-----------------*/\n");
   CODE_printf ("      yUNIT_file    (%4i, %3i, \"%s\", ", CODE__myline (), s_cstep, my.desc);
   /*---(check for var)------------------*/
   x_len = strlen (my.load);
   if        (strncmp (my.code, "[[ ", 3) != 0) {
      CODE_printf ("\"%s\"", my.code);
   } else {
      /*> printf ("variable one\n");                                                  <*/
      strlcpy (x_temp, my.code + 3, LEN_FULL);
      x_var = x_temp;
      p = strtok_r (x_temp, q, &r);
      if (p == NULL) CODE_printf ("\"%s\"" , "unknown");
      else           CODE_printf ("%s" , p);
   }
   /*---(write)--------------------------*/
   CODE_printf (", cyUNIT.exec);\n");
   /*---(complete)-----------------------*/
   return 0;
}

char
CODE_append        (void)
{
   /*---(locals)-----------+-----+-----+-*/
   int         x_len       =    0;
   char       *p           = NULL;
   char       *q           =  " ";
   char       *r           = NULL;
   char        x_temp      [LEN_FULL];
   char       *x_var       = NULL;
   /*---(counters)-----------------------*/
   CODE__stats_step ();
   /*---(fix strings)--------------------*/
   CODE_display ();
   /*---(write)--------------------------*/
   CODE_printf ("      /*---(create file)-----------------*/\n");
   CODE_printf ("      yUNIT_append  (%4i, %3i, \"%s\", ", CODE__myline (), s_cstep, my.desc);
   /*---(check for var)------------------*/
   x_len = strlen (my.load);
   if        (strncmp (my.code, "[[ ", 3) != 0) {
      CODE_printf ("\"%s\"", my.code);
   } else {
      /*> printf ("variable one\n");                                                  <*/
      strlcpy (x_temp, my.code + 3, LEN_FULL);
      x_var = x_temp;
      p = strtok_r (x_temp, q, &r);
      if (p == NULL) CODE_printf ("\"%s\"" , "unknown");
      else           CODE_printf ("%s" , p);
   }
   /*---(write)--------------------------*/
   CODE_printf (", cyUNIT.exec);\n");
   /*---(complete)-----------------------*/
   return 0;
}

char
CODE_system        (void)
{
   /*---(locals)-----------+-----------+-*/
   char        x_cmd       [LEN_RECD]  = "";
   int         l           =    0;
   int         i           =    0;
   /*---(counters)-----------------------*/
   CODE__stats_step ();
   /*---(fix strings)--------------------*/
   CODE_display ();
   /*> strcpy (x_cmd, my.disp);                                                       <* 
    *> l = strlen (x_cmd);                                                            <* 
    *> for (i = 0; i < l; ++i) {                                                      <* 
    *>    switch (x_cmd [i]) {                                                        <* 
    *>    case '§'  : x_cmd [i] = '';  break;                                        <* 
    *>    }                                                                           <* 
    *> }                                                                              <*/
   /*---(write)--------------------------*/
   CODE_printf ("      /*---(system/execute)--------------*/\n");
   CODE_printf ("      yUNIT_system  (%4i, %3i, \"%s\", \"%s\", \"%s\", cyUNIT.exec);\n", CODE__myline (), s_cstep, my.desc, my.disp, my.syst);
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
   /*---(run function)-------------------*/
   if (strcmp (my.meth, "echo") != 0) {
      CODE_printf ("      yUNIT_reset_rc ();\n");
      switch (a_test) {
      case 'v'  :
         CODE_printf ("      if (cyUNIT.exec)  %-13s (%s);\n", my.meth , my.syst);
         break;
      case 's'  : case 'u'  : case 'w'  :
         CODE_printf ("      if (cyUNIT.exec)  cyUNIT.s_rc = %s (%s);\n", my.meth , my.syst);
         break;
      case 'i'  :
         CODE_printf ("      if (cyUNIT.exec)  cyUNIT.i_rc = %s (%s);\n", my.meth , my.syst);
         break;
      case 'r'  :
         CODE_printf ("      if (cyUNIT.exec)  cyUNIT.r_rc = %s (%s);\n", my.meth , my.syst);
         break;
      case 'p'  :
         CODE_printf ("      if (cyUNIT.exec)  cyUNIT.p_rc = %s (%s);\n", my.meth , my.syst);
         break;
      }
   }
   /*---(determine function)-------------*/
   switch (a_test) {
   case 'v'  : strlcpy (x_func, "yUNIT_void"     , LEN_FULL);    break;
   case 's'  : strlcpy (x_func, "yUNIT_string"   , LEN_FULL);    break;
   case 'w'  : strlcpy (x_func, "yUNIT_wrap"     , LEN_FULL);    break;
   case 'u'  : strlcpy (x_func, "yUNIT_round"    , LEN_FULL);    break;
   case 'i'  : strlcpy (x_func, "yUNIT_int"      , LEN_FULL);    break;
   case 'r'  : strlcpy (x_func, "yUNIT_real"     , LEN_FULL);    break;
   case 'p'  : strlcpy (x_func, "yUNIT_point"    , LEN_FULL);    break;
   default   : strlcpy (x_func, "yUNIT_unknown"  , LEN_FULL);    break;
   }
   /*---(write prefix)-------------------*/
   CODE_printf ("      ");
   CODE_printf ("%-13s ("              , x_func);
   CODE_printf ("%4i, %3i, "           , CODE__myline (), s_cstep);
   CODE_printf ("\"%s\", "             , my.desc);
   CODE_printf ("\"%s\", \"%s\", "     , my.meth  , my.disp);
   /*---(write test)---------------------*/
   switch (a_test) {
   case 'v' :    /* pure void        */
      CODE_printf ("\"%s\", cyUNIT.exec);\n", my.test);
      break;
   default  :    /* all others       */
      CODE_printf ("\"%s\", "          , my.test);
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
   CODE_printf ("\"%s\", "           , my.expe);
   CODE_printf ("\"\", cyUNIT.exec);\n"   );
   CODE_printf ("\n");
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
      case 's' : case 'u' : case 'w' :      /* stringish   */
         CODE_printf ("\"%s\", " , my.expe);
         break;
      case 'i' : case 'p' : case 'r' :      /* numberish   */
         CODE_printf ("%s, "     , my.expe);
         break;
      default  :
         CODE_printf ("\"%s\", cyUNIT.exec);\n"         , my.expe);
         break;
      }
      return 0;
   }
   /*---(check for var)------------------*/
   else {
      strlcpy (x_var, my.expe + 3, LEN_RECD);
      x_expe = x_var;
      p = strtok_r (x_var, q, &r);
      if (p == NULL) CODE_printf ("\"%s\", " , "unknown");
      else           CODE_printf ("%s, "     , x_expe);
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
      CODE_printf ("%s  , cyUNIT.exec);\n"      , my.syst);
   }
   /*---(check for simple end)-----------*/
   else {
      switch (a_test) {
      case 's'  : case 'u'  : case 'w'  :
         CODE_printf ("cyUNIT.s_rc, cyUNIT.exec);\n");
         break;
      case 'i'  :
         CODE_printf ("cyUNIT.i_rc, cyUNIT.exec);\n");
         break;
      case 'r'  :
         CODE_printf ("cyUNIT.r_rc, cyUNIT.exec);\n");
         break;
      case 'p'  :
         CODE_printf ("cyUNIT.p_rc, cyUNIT.exec);\n");
         break;
      }
   }
   /*---(handle return variables)--------*/
   if (strcmp (my.retn, "") != 0) {
      switch (a_test) {
      case 's'  : case 'u'  : case 'w'  :
         CODE_printf ("         if (cyUNIT.exec && cyUNIT.s_rc != NULL)  strcpy (%s, cyUNIT.s_rc);\n", my.retn);
         break;
      case 'i'  :
         CODE_printf ("         if (cyUNIT.exec)  %s = cyUNIT.i_rc;\n", my.retn);
         break;
      case 'r'  :
         CODE_printf ("         if (cyUNIT.exec)  %s = cyUNIT.r_rc;\n", my.retn);
         break;
      case 'p'  :
         CODE_printf ("         if (cyUNIT.exec)  %s = cyUNIT.p_rc;\n", my.retn);
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
   CODE__stats_step ();
   /*---(fix strings)--------------------*/
   CODE_display ();
   /*---(handle return values)-----------*/
   CODE_printf ("      /*---(echo/verify)-----------------*/\n");
   strlcpy (my.meth, "echo", LEN_DESC );
   x_test = my.test [0];
   CODE_prefix    (x_test);
   CODE_expe_var  (x_test);
   CODE_suffix    (x_test);
   /*---(finish)-------------------------*/
   /*> CODE_printf ("\n");                                                  <*/
   /*---(complete)-----------------------*/
   return 0;
}

char
CODE_exec          (void)
{
   char        x_test      = '-';
   /*---(counters)-----------------------*/
   CODE__stats_step ();
   /*---(fix strings)--------------------*/
   CODE_display ();
   /*---(debugging)----------------------*/
   CODE_printf ("      /*---(run step)--------------------*/\n");
   if (my.run_type == G_RUN_DEBUG) {
      CODE_printf ("      %sUG_PROG    %sOG_unitstep (cyUNIT.origin, cyUNIT.offset + %3i, %3i, %4i, \"%s\");\n", "DEB", "yL", s_scond, s_cstep, my.n_line, my.desc);
   }
   /*---(handle return values)-----------*/
   x_test = my.test [0];
   CODE_prefix    (x_test);
   CODE_expe_var  (x_test);
   CODE_suffix    (x_test);
   /*---(finish)-------------------------*/
   /*> CODE_printf ("\n");                                                  <*/
   /*---(complete)-----------------------*/
   return 0;
}

char
CODE_write         (void)
{
   char        rc          =    0;
   /*---(header)-------------------------*/
   DEBUG_OUTP   yLOG_enter   (__FUNCTION__);
   /*---(switch)-------------------------*/
   if (my.p_code == NULL) {
      DEBUG_OUTP   yLOG_note    ("code handler NULL, likely DITTO or #>");
      DEBUG_OUTP   yLOG_exit    (__FUNCTION__);
      return 0;
   }
   /*> printf ("CODE_write      my line %4d, my verb å%sæ, my last å%sæ\n", my.n_line, my.verb, my.last);   <*/
   rc = my.p_code ();
   /*---(complete)-----------------------*/
   DEBUG_OUTP   yLOG_exit    (__FUNCTION__);
   return 0;
}


/*===============================[[ end code ]]===============================*/
