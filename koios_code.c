/*===============================[[ beg-code ]]===============================*/
#include    "koios.h"        /* LOCAL  : main header                          */




char        CODE_cond_end      (void);



static int  s_master_cond   [26];          /* count of cond in each share    */
static int  s_master_step   [26];          /* count of step in each share    */
static int  s_reuses_cond   [26];          /* count of cond in each share    */
static int  s_reuses_step   [26];          /* count of step in each share    */



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
    *>       my.nscrp,                                                                <* 
    *>       my.ncond, my.scond,                                                      <* 
    *>       my.nstep, my.sstep, my.cstep);                                           <*/
   return 0;
}

char
CODE__stats_purge       (void)
{
   my.nscrp  = 0;
   my.ncond  = my.scond = 0;
   my.nstep  = my.sstep = my.cstep = 0;
   CODE__stats_debug ("purge"    );
   return 0;
}

char
CODE__stats_scrp_beg    (void)
{
   ++(my.nscrp);
   CODE__stats_debug ("scrp_beg" );
   return 0;
}

char
CODE__stats_scrp_end    (void)
{
   my.scond  = 0;
   my.sstep  = my.cstep  = 0;
   CODE__stats_debug ("scrp_end" );
   /*> printf ("\n");                                                                 <*/
   return 0;
}

char
CODE__stats_cond_beg    (void)
{
   ++(my.ncond);
   ++(my.scond);
   CODE__stats_debug ("cond_beg" );
   return 0;
}

char
CODE__stats_cond_end    (void)
{
   my.cstep  = 0;
   CODE__stats_debug ("cond_end" );
   return 0;
   return 0;
}

char
CODE__stats_step        (void)
{
   ++(my.nstep);
   ++(my.sstep);
   ++(my.cstep);
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
      case T_REUSES :
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
   CODE__shared_clear (T_REUSES);
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
   case T_MASTER : x_valid = LTRS_UPPER;   break;
   case T_REUSES : x_valid = LTRS_LOWER;   break;
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
   case T_REUSES :
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
   case T_REUSES :
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
      else                                 my.d_used [i +  0] = LTRS_CHARS [s_master_step [i]];
   }
   /*---(reuses)-------------------------*/
   for (i = 0; i < 26; ++i) {
      if      (s_reuses_cond [i] <=  0)    my.d_used [i + 29] = '-';
      else if (s_reuses_cond [i] >  62)    my.d_used [i + 29] = '*';
      else                                 my.d_used [i + 29] = LTRS_CHARS [s_reuses_step [i]];
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
      rc = SCRP__shared_set (T_MASTER, 'A' + i);

      /*> printf ("%c %4d %4d  (%d)\n", 'A' + i, x_cond, x_step, rc);                 <*/
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
   DEBUG_TOPS   yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   DEBUG_OUTP   yLOG_info    ("n_code"    , my.n_code);
   DEBUG_OUTP   yLOG_point   ("f_code"    , my.f_code);
   --rce;  if (my.f_code != NULL) {
      DEBUG_TOPS   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_OUTP   yLOG_info    ("n_main"    , my.n_main);
   DEBUG_OUTP   yLOG_point   ("f_main"    , my.f_main);
   --rce;  if (my.f_main != NULL) {
      DEBUG_TOPS   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*> DEBUG_OUTP   yLOG_info    ("n_wave"    , my.n_wave);                           <*/
   /*> DEBUG_OUTP   yLOG_point   ("f_wave"    , my.f_wave);                           <*/
   /*> --rce;  if (my.f_wave != NULL) {                                               <* 
    *>    DEBUG_TOPS   yLOG_exitr   (__FUNCTION__, rce);                              <* 
    *>    return rce;                                                                 <* 
    *> }                                                                              <*/
   /*---(open output file)---------------*/
   my.f_code = fopen (my.n_code, "wt");
   DEBUG_OUTP   yLOG_point   ("f_code"    , my.f_code);
   --rce;  if (my.f_code == NULL) {
      DEBUG_TOPS   yLOG_fatal   ("can not open code file");
      DEBUG_TOPS   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   DEBUG_OUTP   yLOG_note    ("code file open");
   /*---(open main file)-----------------*/
   my.f_main = fopen (my.n_main, "wt");
   DEBUG_OUTP   yLOG_point   ("f_main"    , my.f_main);
   --rce;  if (my.f_main == NULL) {
      DEBUG_TOPS   yLOG_fatal   ("can not open main file");
      CODE_close (my.f_code);
      DEBUG_TOPS   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   DEBUG_OUTP   yLOG_note    ("main file open");
   /*---(open wave file)-----------------*/
   /*> printf ("n_wave = [%s]\n", my.n_wave);                                         <*/
   /*> my.f_wave = fopen (my.n_wave, "wt");                                           <* 
    *> DEBUG_OUTP   yLOG_point   ("f_wave"    , my.f_wave);                           <* 
    *> --rce;  if (my.f_wave == NULL) {                                               <* 
    *>    DEBUG_TOPS   yLOG_fatal   ("can not open main file");                       <* 
    *>    CODE_close (my.f_code);                                                     <* 
    *>    CODE_close (my.f_main);                                                     <* 
    *>    DEBUG_TOPS   yLOG_exit    (__FUNCTION__);                                   <* 
    *>    return rce;                                                                 <* 
    *> }                                                                              <*/
   /*> DEBUG_OUTP   yLOG_note    ("wave file open");                                  <*/
   /*---(complete)-----------------------*/
   DEBUG_TOPS   yLOG_exit    (__FUNCTION__);
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
   DEBUG_TOPS   yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   DEBUG_OUTP   yLOG_point   ("a_file"    , a_file);
   --rce;  if (a_file == NULL) {
      DEBUG_TOPS   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(close)--------------------------*/
   if (a_file == my.f_code)   rc = fclose (my.f_code);
   if (a_file == my.f_main)   rc = fclose (my.f_main);
   /*> if (a_file == my.f_wave)   rc = fclose (my.f_wave);                            <*/
   --rce;  if (rc != 0) {
      DEBUG_TOPS   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(ground)-------------------------*/
   if (a_file == my.f_code)   my.f_code = NULL;
   if (a_file == my.f_main)   my.f_main = NULL;
   /*> if (a_file == my.f_wave)   my.f_wave = NULL;                                   <*/
   /*---(complete)-----------------------*/
   DEBUG_TOPS   yLOG_exit    (__FUNCTION__);
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
   if (my.nscrp > 0 || my.cshare != '-') {
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
   CODE_printf ("   yUNIT_unique (%d, %d, %d);\n", my.nscrp, my.ncond, my.nstep);
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
   if (my.nscrp >  0) {
      CODE_cond_end ();
   }
   /*> printf ("my.cstep %4d, my.verb å%sæ\n", my.cstep, my.verb);                    <*/
   IF_MASTER {
      if (my.cstep > 0)  CODE_cond_end ();
   }
   /*---(end share)----------------------*/
   if (my.cshare != '-') {
      if (my.cshare == tolower (my.cshare))  CODE__shared_set (T_REUSES, my.cshare, my.scond, my.sstep);
      else                                   CODE__shared_set (T_MASTER, my.cshare, my.scond, my.sstep);
   }
   /*---(close script/share)-------------*/
   if (my.nscrp >  0 || my.cshare != '-') {
      if (my.cshare == '-') {
         CODE_printf ("   /*===[[ script done ]]==========================*/\n");
         CODE_printf ("   yUNIT_prcs    (cyUNIT.exec);\n");
      }
      else if (my.cshare == tolower (my.cshare)) {
         CODE_printf ("   /*===[[ shared done ]]==========================*/\n");
         CODE_printf ("   yUNIT_erahs ('%c');\n", my.cshare);
         my.ncond -= my.scond;
         my.nstep -= my.sstep;
      }
      else {
         CODE_printf ("   /*===[[ global done ]]==========================*/\n");
         CODE_printf ("   yUNIT_labolg ('%c');\n", my.cshare);
         my.ncond -= my.scond;
         my.nstep -= my.sstep;
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
   /*---(counters)-----------------------*/
   CODE__stats_scrp_beg ();
   /*---(open script function)-----------*/
   CODE_printf ("\n");
   CODE_printf ("char\n");
   CODE_printf ("yUNIT_script_%02d          (void)\n", my.nscrp);
   CODE_printf ("{\n");
   CODE_printf ("   /*===[[ script header ]]========================*/\n");
   CODE_printf ("   cyUNIT.offset  = 0;\n");
   CODE_printf ("   cyUNIT.origin  = %d;\n", my.nscrp);
   CODE_printf ("   yUNIT_mode_reset ();\n");
   CODE_printf ("   yUNIT_scrp    (%4i, %3i, \"%s\", \"%s\", \"%s\");\n", my.n_line, my.nscrp, my.stage, my.desc, my.meth);
   /*---(function call to main)----------*/
   MAIN_printf ("   if (cyUNIT.scrp == YUNIT_ALL  || cyUNIT.scrp == %2i)  yUNIT_script_%02d ();\n", my.nscrp, my.nscrp);
   /*---(script entry in wave)-----------*/
   if (strlen (my.stage) == 2) {
      x_stage = my.stage [0];
      x_wave  = my.stage [1];
   }
   WAVE_printf ("%c  %c  %-25.25s  %2d  %-65.65s \n", x_stage, x_wave, my.n_base, my.nscrp, my.desc);
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
   CODE__shared_set (T_REUSES, my.cshare,  0,  0);
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
   MAIN_printf ("   if (cyUNIT.scrp ==  0)                  yUNIT_sect      (\"%s\");\n", my.desc);
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
   DEBUG_OUTP   yLOG_complex ("counters"  , "%-10.10p, %-10.10s, %4dn, %4dc", my.f_code, my.last, my.ncond, my.scond);
   if (strstr ("GROUP REUSE", my.last) == NULL) {
      if (my.scond > 0) {
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
   DEBUG_OUTP   yLOG_complex ("counters"  , "%-10.10p, %-10.10s, %4dn, %4dc", my.f_code, my.last, my.ncond, my.scond);
   CODE_printf ("   /*===[[ COND #%03i ]]============================*/\n", my.scond);
   CODE_printf ("   if (cyUNIT.cond == cyUNIT.offset + %3i)  yUNIT_level (YUNIT_FULL, 'y'); else yUNIT_level (cyUNIT.level, 'y');\n", my.scond);
   if (my.run_type == G_RUN_DEBUG) {
      CODE_printf ("   %sUG_TOPS    %sOG_unitcond (cyUNIT.origin, cyUNIT.offset + %3i, %4i, \"%s\");\n", "DEB", "yL", my.scond, my.n_line, my.desc);
   }
   if (my.dittoing == 'y') {
      /*> printf ("inside a ditto (%c)\n", my.dmark);                                 <*/
      /*> sprintf (my.compiled , "   yUNIT_cond    (%4i, cyUNIT.offset + %3i, '%c', \"%s\");", my.n_line, my.scond, my.mark      , my.desc);   <*/
      sprintf (my.compiled , "   yUNIT_cond    (%4i, cyUNIT.offset + %3i, '%c', \"%s\");", my.n_line, my.scond, my.dmark , my.desc);
   } else if (my.mark != '-') {
      /*> printf ("found a cond (%c)\n", my.mark);                                    <*/
      a = my.mark - '0' + ' ';
      sprintf (my.compiled , "   yUNIT_cond    (%4i, cyUNIT.offset + %3i, '%c', \"%s\");", my.n_line, my.scond, a        , my.desc);
   } else {
      sprintf (my.compiled , "   yUNIT_cond    (%4i, cyUNIT.offset + %3i, '%c', \"%s\");", my.n_line, my.scond, my.cshare, my.desc);
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
   --rce;  if (strchr (LTRS_CHARS, my.share) == NULL)  return rce;
   CODE_printf ("   /*---(shared code)-----------------------*/\n");
   CODE_printf ("   cyUNIT.offset = %3i;\n", my.scond);
   CODE_printf ("   yUNIT_shared_%c ();\n", my.share);
   CODE_printf ("   cyUNIT.offset = 0;\n");
   if (tolower (my.share) == my.share) {
      CODE__shared_add (T_REUSES, my.share, &(my.ncond), &(my.nstep));
      CODE__shared_add (T_REUSES, my.share, &(my.scond), &(my.sstep));
      my.cstep = my.sstep;
   } else {
      CODE__shared_add (T_MASTER, my.share, &(my.ncond), &(my.nstep));
      CODE__shared_add (T_MASTER, my.share, &(my.scond), &(my.sstep));
      my.cstep = my.sstep;
   }
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
   CODE__stats_step ();
   CODE_printf ("      /*---(mode)------------------------*/\n");
   CODE_printf ("      yUNIT_mode    (%4i, %3i, \"%s\", cyUNIT.exec);\n", my.n_line, my.cstep, my.desc);
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
   CODE_printf ("      yUNIT_local   (%4i, %3i, \"%s\", \"%s\", cyUNIT.exec);\n", my.n_line, my.cstep, my.desc, my.disp);
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
   CODE_printf ("      yUNIT_code    (%4i, %3i, \"%s\", \"%s\", cyUNIT.exec);\n", my.n_line, my.cstep, my.desc, my.disp);
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
   CODE__stats_step ();
   /*---(fix strings)--------------------*/
   CODE_display ();
   CODE_printf ("      /*---(load input)------------------*/\n");
   CODE_printf ("      yUNIT_load    (%4i, %3i, \"%s\", \"%s\", ", my.n_line, my.cstep, my.desc, my.meth);
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
   CODE_printf ("      yUNIT_system  (%4i, %3i, \"%s\", \"%s\", \"%s\", cyUNIT.exec);\n", my.n_line, my.cstep, my.desc, my.disp, my.syst);
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
      case 's'  : case 'u'  :
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
   case 'u'  : strlcpy (x_func, "yUNIT_round"    , LEN_FULL);    break;
   case 'i'  : strlcpy (x_func, "yUNIT_int"      , LEN_FULL);    break;
   case 'r'  : strlcpy (x_func, "yUNIT_real"     , LEN_FULL);    break;
   case 'p'  : strlcpy (x_func, "yUNIT_point"    , LEN_FULL);    break;
   default   : strlcpy (x_func, "yUNIT_unknown"  , LEN_FULL);    break;
   }
   /*---(write prefix)-------------------*/
   CODE_printf ("      ");
   CODE_printf ("%-13s ("              , x_func);
   CODE_printf ("%4i, %3i, "           , my.n_line, my.cstep);
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
      case 's' : case 'u' :                 /* stringish   */
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
      CODE_printf ("%s, cyUNIT.exec);\n"      , my.syst);
   }
   /*---(check for simple end)-----------*/
   else {
      switch (a_test) {
      case 's'  : case 'u'  :
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
      case 's'  : case 'u'  :
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
      CODE_printf ("      %sUG_TOPS    %sOG_unitstep (cyUNIT.origin, cyUNIT.offset + %3i, %3i, %4i, \"%s\");\n", "DEB", "yL", my.scond, my.cstep, my.n_line, my.desc);
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
