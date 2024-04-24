/*===============================[[ beg-code ]]===============================*/
#include    "koios.h"        /* LOCAL  : main header                          */
#include    <yUNIT_solo.h>        /* CUSTOM : heatherly unit testing               */







static int  s_master_cond   [26];          /* count of cond in each share    */
static int  s_master_step   [26];          /* count of step in each share    */
static int  s_reuses_cond   [26];          /* count of cond in each share    */
static int  s_reuses_step   [26];          /* count of step in each share    */



static int  s_nscrp  = 0;
static int  s_ncond  = 0;
static int  s_nstep  = 0;

static int  s_uscrp  = 0;
static int  s_ucond  = 0;
static int  s_ustep  = 0;

static int  s_scond  = 0;
static int  s_sstep  = 0;

static int  s_cstep  = 0;

static int  s_dcond  = 0;
static int  s_dstep  = 0;



/*====================------------------------------------====================*/
/*===----                         program level                        ----===*/
/*====================------------------------------------====================*/
static void  o___PROGRAM_________o () { return; }

char
CODE_init               (void)
{
   s_nscrp  = s_ncond = s_nstep = 0;
   s_uscrp  = s_ucond = s_ustep = 0;
   s_scond  = s_sstep = 0;
   s_cstep  = 0;
   return 0;
}

char
CODE__defense           (char a_nscrp [LEN_TITLE], FILE *a_main, FILE *a_code, FILE *a_wave, cchar a_runtype, cchar a_last [LEN_LABEL], cchar a_verb [LEN_LABEL], cchar a_desc [LEN_LONG], cchar a_meth [LEN_HUND], cchar a_args [LEN_FULL], cchar a_test [LEN_LABEL], cchar a_expe [LEN_RECD], cchar a_retn [LEN_FULL], cchar a_stage [LEN_SHORT], char *r_cshare)
{
   char        rce         =  -10;
   --rce;  if (a_nscrp  == NULL)  return rce;
   --rce;  if (a_main   == NULL)  return rce;
   --rce;  if (a_code   == NULL)  return rce;
   --rce;  if (a_last   == NULL)  return rce;
   --rce;  if (a_verb   == NULL)  return rce;
   --rce;  if (a_desc   == NULL)  return rce;
   --rce;  if (a_meth   == NULL)  return rce;
   --rce;  if (a_args   == NULL)  return rce;
   --rce;  if (a_test   == NULL)  return rce;
   --rce;  if (a_expe   == NULL)  return rce;
   --rce;  if (a_retn   == NULL)  return rce;
   --rce;  if (a_stage  == NULL)  return rce;
   --rce;  if (r_cshare == NULL)  return rce;
   return 0;
}

int
CODE__line              (char a_dittoing, int a_nline, int a_dline)
{
   /*> printf ("dittoing %c, a_nline %4d, a_dline %4d\n", a_dittoing, a_nline, a_dline);   <*/
   if (a_dittoing == 'y') return a_dline;
   return a_nline;
}



/*====================------------------------------------====================*/
/*===----                         preparations                         ----===*/
/*====================------------------------------------====================*/
static void  o___PREP____________o () { return; }

char
CODE__code_beg          (cchar a_nscrp [LEN_TITLE], FILE *a_code)
{
   CONV_printf (a_code, "/*================================= beg-code =================================*/\n");
   CONV_printf (a_code, "/* /usr/local/bin/koios                                                       */\n");
   CONV_printf (a_code, "/*   autogen by %-60.60s  */\n", P_ONELINE);
   if (strcmp (a_nscrp, "master.unit") != 0) { 
      CONV_printf (a_code, "\n");
      CONV_printf (a_code, "/*---(standard support functions)----*/\n");
      CONV_printf (a_code, "#include    <yUNIT_unit.h>\n");
      CONV_printf (a_code, "#include    \"master.h\"\n");
      CONV_printf (a_code, "\n");
      CONV_printf (a_code, "/*================================ beg-script ================================*/\n");
   } else {
      CONV_printf (a_code, "\n");
      CONV_printf (a_code, "/*================================ beg-global ================================*/\n");
   }
   /*---(complete)-----------------------*/
   return 0;
}

char
CODE__code_stats        (FILE *a_code)
{
   CONV_printf (a_code, "\n");
   CONV_printf (a_code, "char\n");
   CONV_printf (a_code, "yUNIT_stats     (void)\n");
   CONV_printf (a_code, "{\n");
   /*> CONV_printf (a_code, "   yUNIT_unique (%d, %d, %d, %d, %d, %d);\n", s_nscrp, s_ncond, s_nstep, s_uscrp, s_ucond - s_dcond, s_ustep - s_dstep);   <*/
   CONV_printf (a_code, "   yUNIT_unique (%d, %d, %d, %d, %d, %d);\n", s_nscrp, s_ncond, s_nstep, s_nscrp, s_ncond - s_dcond, s_nstep - s_dstep);
   CONV_printf (a_code, "   return 0;\n");
   CONV_printf (a_code, "}\n");
   CONV_printf (a_code, "\n");
   return 0;
}

char
CODE__code_end          (cchar a_nscrp [LEN_TITLE], FILE *a_code)
{
   CONV_printf (a_code, "\n");
   if (strcmp (a_nscrp, "master.unit") != 0) {
      CONV_printf (a_code, "/*================================ end-script ================================*/\n");
   } else {
      CONV_printf (a_code, "/*================================ end-global ================================*/\n");
   }
   return 0;
}

char
CODE__main_beg          (FILE *a_main, char a_nscrp [LEN_TITLE])
{
   char        x_urun      [LEN_TITLE] = "";
   int         l           =    0;
   strlcpy (x_urun, a_nscrp, LEN_TITLE);
   l = strlen (x_urun);
   if (strcmp (x_urun + l - 5, ".unit") == 0)  x_urun [l - 5] = '\0';
   CONV_printf (a_main, "\n\n\n");
   CONV_printf (a_main, "int\n");
   CONV_printf (a_main, "main                    (int a_argc, char *a_argv[])\n");
   CONV_printf (a_main, "{\n");
   CONV_printf (a_main, "   /*---(locals)-----------+-----+-----+-*/\n");
   CONV_printf (a_main, "   int         rc          =    0;\n");
   CONV_printf (a_main, "   /*---(prepare)------------------------*/\n");
   CONV_printf (a_main, "   rc = yUNIT_init ();\n");
   CONV_printf (a_main, "   rc = yUNIT_args (a_argc, a_argv);\n");
   CONV_printf (a_main, "   if (rc < 0)  return -1;\n");
   CONV_printf (a_main, "   yUNIT_unit (\"%s\", cyUNIT.level, cyUNIT.eterm, cyUNIT.exec);\n", x_urun);
   CONV_printf (a_main, "   /*---(beg scripts)--------------------*/\n");
   return 0;
}

char
CODE__main_end          (FILE *a_main)
{
   CONV_printf (a_main, "   /*---(end scripts)--------------------*/\n");
   CONV_printf (a_main, "   rc = yUNIT_tinu (cyUNIT.exec);\n");
   CONV_printf (a_main, "   /*---(complete)-----------------------*/\n");
   CONV_printf (a_main, "   return rc;\n");
   CONV_printf (a_main, "}\n");
   CONV_printf (a_main, "\n\n\n");
   CONV_printf (a_main, "/* end-of-file.  done, finito, completare, whimper [Ï´···                     */\n");
   CONV_printf (a_main, "/*================================= end-code =================================*/\n");
   return 0;
}

char
CODE_header             (char a_nscrp [LEN_TITLE], cchar a_nmain [LEN_TITLE], FILE **r_main, cchar a_ncode [LEN_TITLE], FILE **r_code, cchar a_nwave [LEN_TITLE], FILE **r_wave, char *r_cshare)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   FILE       *x_main      = NULL;
   FILE       *x_code      = NULL;
   FILE       *x_wave      = NULL;
   /*---(open main)----------------------*/
   rc = READ_open       (a_nmain, 'w', &x_main, NULL);
   if (rc < 0 || x_main == NULL)  return rce;
   /*---(open code)----------------------*/
   rc = READ_open       (a_ncode, 'w', &x_code, NULL);
   if (rc < 0 || x_code == NULL) {
      READ_close (&x_main);
      return rce;
   }
   /*---(open wave)----------------------*/
   rc = READ_open       (a_nwave, 'w', &x_wave, NULL);
   if (rc < 0 || x_wave == NULL) {
      READ_close (&x_main);
      READ_close (&x_code);
      return rce;
   }
   /*---(add headers)--------------------*/
   CODE__main_beg (x_main, a_nscrp);
   CODE__code_beg (a_nscrp, x_code);
   /*---(default globals)----------------*/
   s_nscrp  = s_ncond = s_nstep = 0;
   s_uscrp  = s_ucond = s_ustep = 0;
   s_scond  = s_sstep = 0;
   s_cstep  = 0;
   s_dcond  = s_dstep = 0;
   if (r_cshare != NULL)  *r_cshare = '-';
   /*---(save-back)----------------------*/
   if (r_main   != NULL)  *r_main   = x_main;
   if (r_code   != NULL)  *r_code   = x_code;
   if (r_wave   != NULL)  *r_wave   = x_wave;
   /*---(complete)-----------------------*/
   return 0;
}

char
CODE_footer             (char a_good, cchar a_nscrp [LEN_TITLE], cchar a_nmain [LEN_TITLE], FILE **r_main, cchar a_ncode [LEN_TITLE], FILE **r_code, cchar a_nwave [LEN_TITLE], FILE **r_wave, cchar a_cshare)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        x_recd      [LEN_RECD]  = "";
   char        t           [LEN_HUND]  = "";
   /*---(header)-------------------------*/
   DEBUG_UVER   yLOG_uenter  (__FUNCTION__);
   DEBUG_UVER   yLOG_uchar   ("a_good"    , a_good);
   /*---(polish off scripts)-------------*/
   if (s_nscrp >  0 && a_cshare == '-')   yUNIT_wave_end (my.f_wave, 0, 1, s_scond, s_sstep);
   CODE__scrp_end          (*r_code, "----", "-----", a_cshare);
   /*---(code endings)-------------------*/
   if (a_good == 'y') {
      CODE__main_end   (*r_main);
      CODE__code_end   (a_nscrp, *r_code);
   }
   /*---(informational)------------------*/
   if (a_good == 'y' && strcmp (a_nscrp, "master.unit") != 0) {
      CODE__code_stats (*r_code);
      VERB_inventory   (*r_code);
   }
   /*---(append main)--------------------*/
   if (a_good == 'y') {
      /*---(append main)-----------------*/
      if (strcmp (a_nscrp, "master.unit") != 0) {
         READ_close (r_main);
         READ_open  (a_nmain, 'r', r_main, NULL);
         /*> printf ("MAIN------------------------------------------\n");                <*/
         while (1) {
            fgets (x_recd, LEN_RECD, *r_main);
            if (feof (*r_main)) break;
            /*> printf ("MAIN    %s", x_recd);                                           <*/
            CONV_printf (*r_code, x_recd);
         }
         /*> printf ("MAIN------------------------------------------\n");                <*/
      }
      /*---(export globals)--------------*/
      else {
         printf ("handling master.unit\n");
         REUSE_export ("master.globals");
      }
   }
   /*---(write wave footer)--------------*/
   if (r_wave != NULL && *r_wave != NULL)  fprintf (*r_wave, "\n");
   /*---(close files)--------------------*/
   rc = READ_close (r_main);
   rc = READ_close (r_code);
   rc = READ_close (r_wave);
   /*---(transfer master.h)--------------*/
   if (a_good == 'y' &&strcmp (a_nscrp, "master.unit") == 0) {
      system  ("mv -f master_unit.cs master.h");
   }
   /*---(clean-up)-----------------------*/
   sprintf (t, "rm -f %s", a_nmain); system  (t);
   if (a_good != 'y') {
      sprintf (t, "rm -f %s", a_ncode); system  (t);
      sprintf (t, "rm -f %s", a_nwave); system  (t);
   }
   /*---(complete)-----------------------*/
   DEBUG_UVER   yLOG_uexit   (__FUNCTION__);
   return 0;
}

char
CODE_incl               (char a_nscrp [LEN_TITLE], FILE *a_main, FILE *a_code, FILE *a_wave, cchar a_runtype, cchar a_last [LEN_LABEL], cchar a_verb [LEN_LABEL], cchar a_desc [LEN_LONG], cchar a_method [LEN_HUND], cchar a_args [LEN_FULL], cchar a_test [LEN_LABEL], cchar a_expect [LEN_RECD], cchar a_return [LEN_FULL], cchar a_stage [LEN_SHORT], char a_dittoing, char a_mark, char a_dmark, int a_nline, int a_dline, char a_share, char *r_cshare)
{
   char        t           [LEN_HUND]  = "";
   if (a_method [0] == '<')   strcpy  (t, a_method);
   else                       sprintf (t, "\"%s\"", a_method);
   CONV_printf (a_code, "#include    %-22.22s  /* %4i, %-32.32s */\n", t, CODE__line (a_dittoing, a_nline, a_dline), a_desc);
   return 0;
}



/*====================------------------------------------====================*/
/*===----                      script level verbs                      ----===*/
/*====================------------------------------------====================*/
static void  o___SCRP____________o () { return; }

char
CODE__scrp_end          (FILE *a_code, cchar a_last [LEN_LABEL], cchar a_verb [LEN_LABEL], cchar a_cshare)
{
   /*---(reset verb counts)--------------*/
   VERB_script_reset ();
   /*---(quick out)----------------------*/
   if (strcmp (a_last, "SECT") == 0)    return 0;
   /*---(wrap last cond)-----------------*/
   CODE__cond_end (a_code, a_last, a_verb);
   /*---(end share)----------------------*/
   if (a_cshare != '-')   REUSE_update (a_cshare, s_scond, s_sstep);
   /*---(close script/share)-------------*/
   if (s_nscrp >  0 || a_cshare != '-') {
      if (a_cshare == '-') {
         CONV_printf (a_code, "   /*===[[ script done ]]==========================*/\n");
         CONV_printf (a_code, "   yUNIT_prcs    (cyUNIT.exec);\n");
         /*> CONV_printf (a_code, "   cyUNIT.offset  = 0;\n");                        <*/
      }
      else if (a_cshare == tolower (a_cshare)) {
         CONV_printf (a_code, "   /*===[[ shared done ]]==========================*/\n");
         CONV_printf (a_code, "   yUNIT_erahs ('%c');\n", a_cshare);
         /*> CONV_printf (a_code, "   cyUNIT.offset  = 0;\n");                        <*/
         s_ucond -= s_scond;
         s_ustep -= s_sstep;
      }
      else {
         CONV_printf (a_code, "   /*===[[ global done ]]==========================*/\n");
         CONV_printf (a_code, "   yUNIT_labolg ('%c');\n", a_cshare);
         /*> CONV_printf (a_code, "   cyUNIT.offset  = 0;\n");                        <*/
         s_ucond -= s_scond;
         s_ustep -= s_sstep;
      }
      CONV_printf (a_code, "   /*---(complete)-----------------------*/\n");
      CONV_printf (a_code, "   return 0;\n");
      CONV_printf (a_code, "}\n");
   }
   /*---(initialize vars)----------------*/
   s_scond  = 0;
   s_sstep  = s_cstep  = 0;
   /*---(complete)-----------------------*/
   return 0;
}

char
CODE_scrp               (char a_nscrp [LEN_TITLE], FILE *a_main, FILE *a_code, FILE *a_wave, cchar a_runtype, cchar a_last [LEN_LABEL], cchar a_verb [LEN_LABEL], cchar a_desc [LEN_LONG], cchar a_method [LEN_HUND], cchar a_args [LEN_FULL], cchar a_test [LEN_LABEL], cchar a_expect [LEN_RECD], cchar a_return [LEN_FULL], cchar a_stage [LEN_SHORT], char a_dittoing, char a_mark, char a_dmark, int a_nline, int a_dline, char a_share, char *r_cshare)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rc          =    0;
   char        l           =    0;
   char        x_stage     =  '·';
   char        x_wave      =  '·';
   char        x_rating    =  '·';
   /*---(header)-------------------------*/
   DEBUG_UVER   yLOG_uenter  (__FUNCTION__);
   /*---(defense)------------------------*/
   rc = CODE__defense (a_nscrp, a_main, a_code, a_wave, a_runtype, a_last, a_verb, a_desc, a_method, a_args, a_test, a_expect, a_return, a_stage, r_cshare);
   if (rc < 0)  return rc;
   /*---(wrap last script)---------------*/
   if (s_nscrp >  0 && *r_cshare == '-')   yUNIT_wave_end (a_wave, 0, 1, s_scond, s_sstep);
   CODE__scrp_end (a_code, a_last, a_verb, *r_cshare);
   *r_cshare = '-';
   /*---(counters)-----------------------*/
   ++(s_nscrp);
   ++(s_uscrp);
   s_scond  = 0;
   s_sstep  = s_cstep  = 0;
   /*---(open script function)-----------*/
   CONV_printf (a_code, "\n");
   CONV_printf (a_code, "char\n");
   CONV_printf (a_code, "yUNIT_script_%02d          (void)\n", s_nscrp);
   CONV_printf (a_code, "{\n");
   CONV_printf (a_code, "   /*===[[ script header ]]========================*/\n");
   CONV_printf (a_code, "   cyUNIT.offset  = 0;\n");
   CONV_printf (a_code, "   cyUNIT.origin  = %d;\n", s_nscrp);
   CONV_printf (a_code, "   yUNIT_mode_reset ();\n");
   CONV_printf (a_code, "   yUNIT_scrp    (%4i, %3i, \"%s\", \"%s\", \"%s\", \"%s\", \"%s\");\n", CODE__line (a_dittoing, a_nline, a_dline), s_nscrp, a_stage, a_desc, a_test, a_return, a_method);
   /*---(function call to main)----------*/
   CONV_printf (a_main, "   if (yUNIT_run_scrp (%2i) == 1)  yUNIT_script_%02d ();\n", s_nscrp, s_nscrp);
   /*---(script entry in wave)-----------*/
   DEBUG_UVER   yLOG_uinfo   ("a_stage"   , a_stage);
   l = strlen (a_stage);
   DEBUG_UVER   yLOG_uvalue  ("l"         , l);
   if (l > 0)   x_wave   = a_stage [0];
   if (l > 1)   x_stage  = a_stage [1];
   if (l > 3)   x_rating = a_stage [3];
   DEBUG_UVER   yLOG_ucomplex("stage"     , "%d %c %c %c", l, x_wave, x_stage, x_rating);
   yUNIT_wave_beg (my.n_proj, my.n_base, s_nscrp, a_desc, a_return, x_wave, x_stage, x_rating, a_test);
   /*---(complete)-----------------------*/
   DEBUG_UVER   yLOG_uexit   (__FUNCTION__);
   return 0;
}

char
CODE_shared             (char a_nscrp [LEN_TITLE], FILE *a_main, FILE *a_code, FILE *a_wave, cchar a_runtype, cchar a_last [LEN_LABEL], cchar a_verb [LEN_LABEL], cchar a_desc [LEN_LONG], cchar a_method [LEN_HUND], cchar a_args [LEN_FULL], cchar a_test [LEN_LABEL], cchar a_expect [LEN_RECD], cchar a_return [LEN_FULL], cchar a_stage [LEN_SHORT], char a_dittoing, char a_mark, char a_dmark, int a_nline, int a_dline, char a_share, char *r_cshare)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   /*---(defense)------------------------*/
   rc = CODE__defense (a_nscrp, a_main, a_code, a_wave, a_runtype, a_last, a_verb, a_desc, a_method, a_args, a_test, a_expect, a_return, a_stage, r_cshare);
   if (rc < 0)  return rc;
   /*---(end last script)----------------*/
   if (s_nscrp >  0 && *r_cshare == '-')   yUNIT_wave_end (a_wave, 0, 1, s_scond, s_sstep);
   CODE__scrp_end (a_code, a_last, a_verb, *r_cshare);
   /*---(counters)-----------------------*/
   *r_cshare = a_share;
   REUSE_update (a_share,  0,  0);
   /*---(open script function)-----------*/
   CONV_printf (a_code, "\n");
   CONV_printf (a_code, "char\n");
   CONV_printf (a_code, "yUNIT_shared_%c           (void)\n", a_share);
   CONV_printf (a_code, "{\n");
   CONV_printf (a_code, "   /*===[[ shared header ]]========================*/\n");
   CONV_printf (a_code, "   yUNIT_share ('%c', \"%s\");\n", a_share, a_desc);
   /*---(complete)-----------------------*/
   return 0;
}

char
CODE_global             (char a_nscrp [LEN_TITLE], FILE *a_main, FILE *a_code, FILE *a_wave, cchar a_runtype, cchar a_last [LEN_LABEL], cchar a_verb [LEN_LABEL], cchar a_desc [LEN_LONG], cchar a_method [LEN_HUND], cchar a_args [LEN_FULL], cchar a_test [LEN_LABEL], cchar a_expect [LEN_RECD], cchar a_return [LEN_FULL], cchar a_stage [LEN_SHORT], char a_dittoing, char a_mark, char a_dmark, int a_nline, int a_dline, char a_share, char *r_cshare)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   /*---(defense)------------------------*/
   rc = CODE__defense (a_nscrp, a_main, a_code, a_wave, a_runtype, a_last, a_verb, a_desc, a_method, a_args, a_test, a_expect, a_return, a_stage, r_cshare);
   if (rc < 0)  return rc;
   /*---(end last script)----------------*/
   if (s_nscrp >  0 && *r_cshare == '-')   yUNIT_wave_end (a_wave, 0, 1, s_scond, s_sstep);
   CODE__scrp_end (a_code, a_last, a_verb, *r_cshare);
   /*---(counters)-----------------------*/
   *r_cshare = a_share;
   REUSE_update (a_share,  0,  0);
   /*---(open script function)-----------*/
   CONV_printf (a_code, "\n");
   CONV_printf (a_code, "char\n");
   CONV_printf (a_code, "yUNIT_shared_%c           (void)\n", a_share);
   CONV_printf (a_code, "{\n");
   CONV_printf (a_code, "   /*===[[ global header ]]========================*/\n");
   CONV_printf (a_code, "   yUNIT_global ('%c', \"%s\");\n", a_share, a_desc);
   /*---(complete)-----------------------*/
   return 0;
}

char
CODE_sect               (char a_nscrp [LEN_TITLE], FILE *a_main, FILE *a_code, FILE *a_wave, cchar a_runtype, cchar a_last [LEN_LABEL], cchar a_verb [LEN_LABEL], cchar a_desc [LEN_LONG], cchar a_method [LEN_HUND], cchar a_args [LEN_FULL], cchar a_test [LEN_LABEL], cchar a_expect [LEN_RECD], cchar a_return [LEN_FULL], cchar a_stage [LEN_SHORT], char a_dittoing, char a_mark, char a_dmark, int a_nline, int a_dline, char a_share, char *r_cshare)
{
   /*---(end last script)----------------*/
   if (s_nscrp >  0 && *r_cshare == '-')   yUNIT_wave_end (a_wave, 0, 1, s_scond, s_sstep);
   CODE__scrp_end (a_code, a_last, a_verb, *r_cshare);
   /*---(add section)--------------------*/
   CONV_printf (a_main, "   if (cyUNIT.all          == 1)  yUNIT_sect      (\"%s\");\n", a_desc);
   /*---(complete)-----------------------*/
   return 0;
}



/*====================------------------------------------====================*/
/*===----                       condition level                        ----===*/
/*====================------------------------------------====================*/
static void  o___COND____________o () { return; }

char
CODE__cond_end          (FILE *a_code, cchar a_last [LEN_LABEL], cchar a_verb [LEN_LABEL])
{
   /*---(header)-------------------------*/
   DEBUG_UVER   yLOG_uenter  (__FUNCTION__);
   DEBUG_UVER   yLOG_ucomplex("counters"  , "%-10.10s, %-10.10s, %4dn, %4dc", a_last, a_verb, s_ncond, s_scond);
   /*---(quick-out)----------------------*/
   if (strstr ("GROUP REUSE", a_last) != NULL) {
      DEBUG_UVER   yLOG_uexit   (__FUNCTION__);
      return 0;
   }
   /*---(end condition)------------------*/
   if (s_scond > 0) {
      CONV_printf (a_code, "      /*---(summary)---------------------*/\n");
      CONV_printf (a_code, "      yUNIT_dnoc    (cyUNIT.exec);\n");
      CONV_printf (a_code, "      /*---(done)------------------------*/\n");
   }
   /*---(reset step counter)-------------*/
   s_cstep  = 0;
   /*---(complete)-----------------------*/
   DEBUG_UVER   yLOG_uexit   (__FUNCTION__);
   return 0;
}

char
CODE_cond               (char a_nscrp [LEN_TITLE], FILE *a_main, FILE *a_code, FILE *a_wave, cchar a_runtype, cchar a_last [LEN_LABEL], cchar a_verb [LEN_LABEL], cchar a_desc [LEN_LONG], cchar a_method [LEN_HUND], cchar a_args [LEN_FULL], cchar a_test [LEN_LABEL], cchar a_expect [LEN_RECD], cchar a_return [LEN_FULL], cchar a_stage [LEN_SHORT], char a_dittoing, char a_mark, char a_dmark, int a_nline, int a_dline, char a_share, char *r_cshare)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rc          =    0;
   char        a           =    0;
   /*---(header)-------------------------*/
   DEBUG_UVER   yLOG_uenter  (__FUNCTION__);
   /*---(defense)------------------------*/
   rc = CODE__defense (a_nscrp, a_main, a_code, a_wave, a_runtype, a_last, a_verb, a_desc, a_method, a_args, a_test, a_expect, a_return, a_stage, r_cshare);
   if (rc < 0)  return rc;
   /*---(wrap last cond)-----------------*/
   CODE__cond_end (a_code, a_last, a_verb);
   /*---(increment)----------------------*/
   s_cstep = 0;
   ++(s_ncond);
   ++(s_ucond);
   ++(s_scond);
   if (a_dittoing == 'y')  ++(s_dcond);
   DEBUG_UVER   yLOG_ucomplex("counters"  , "%-10.10s, %4dn, %4dc", a_last, s_ncond, s_scond);
   /*---(initial comment)----------------*/
   CONV_printf (a_code, "   /*===[[ COND #%03i ]]============================*/\n", s_scond);
   /*---(debugging)----------------------*/
   if (a_runtype == G_RUN_DEBUG) {
      CONV_printf (a_code, "   %sUG_PROG    %sOG_unitcond (cyUNIT.origin, cyUNIT.offset + %3i, %4i, \"%s\");\n", "DEB", "yL", s_scond, CODE__line (a_dittoing, a_nline, a_dline), a_desc);
   }
   /*---(debugging)----------------------*/
   if (a_dittoing == 'y') {
      CONV_printf (a_code, "   yUNIT_cond    (%4i, cyUNIT.offset + %3i, '%c', \"[ %s ]\");\n", a_nline, s_scond, a_dmark , a_desc);
   } else if (a_mark != '-') {
      a = a_mark - '0' + ' ';
      CONV_printf (a_code, "   yUNIT_cond    (%4i, cyUNIT.offset + %3i, '%c', \"%s\");\n",     a_nline, s_scond, a        , a_desc);
   } else {
      CONV_printf (a_code, "   yUNIT_cond    (%4i, cyUNIT.offset + %3i, '%c', \"%s\");\n",     a_nline, s_scond, *r_cshare, a_desc);
   }
   /*---(complete)-----------------------*/
   DEBUG_UVER   yLOG_uexit   (__FUNCTION__);
   return 0;
}

char
CODE_group              (char a_nscrp [LEN_TITLE], FILE *a_main, FILE *a_code, FILE *a_wave, cchar a_runtype, cchar a_last [LEN_LABEL], cchar a_verb [LEN_LABEL], cchar a_desc [LEN_LONG], cchar a_method [LEN_HUND], cchar a_args [LEN_FULL], cchar a_test [LEN_LABEL], cchar a_expect [LEN_RECD], cchar a_return [LEN_FULL], cchar a_stage [LEN_SHORT], char a_dittoing, char a_mark, char a_dmark, int a_nline, int a_dline, char a_share, char *r_cshare)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rc          =    0;
   /*---(header)-------------------------*/
   DEBUG_UVER   yLOG_uenter  (__FUNCTION__);
   /*---(defense)------------------------*/
   rc = CODE__defense (a_nscrp, a_main, a_code, a_wave, a_runtype, a_last, a_verb, a_desc, a_method, a_args, a_test, a_expect, a_return, a_stage, r_cshare);
   if (rc < 0)  return rc;
   /*---(wrap last cond)-----------------*/
   CODE__cond_end (a_code, a_last, a_verb);
   /*---(create)-------------------------*/
   CONV_printf (a_code, "   /*---(group)--------------------------*/\n");
   CONV_printf (a_code, "   yUNIT_group   (\"%s\");\n", a_desc);
   /*---(complete)-----------------------*/
   return 0;
}

char
CODE_reuse              (char a_nscrp [LEN_TITLE], FILE *a_main, FILE *a_code, FILE *a_wave, cchar a_runtype, cchar a_last [LEN_LABEL], cchar a_verb [LEN_LABEL], cchar a_desc [LEN_LONG], cchar a_method [LEN_HUND], cchar a_args [LEN_FULL], cchar a_test [LEN_LABEL], cchar a_expect [LEN_RECD], cchar a_return [LEN_FULL], cchar a_stage [LEN_SHORT], char a_dittoing, char a_mark, char a_dmark, int a_nline, int a_dline, char a_share, char *r_cshare)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rc          =    0;
   char        rce         =  -10;
   /*---(header)-------------------------*/
   DEBUG_UVER   yLOG_uenter  (__FUNCTION__);
   /*---(defense)------------------------*/
   rc = CODE__defense (a_nscrp, a_main, a_code, a_wave, a_runtype, a_last, a_verb, a_desc, a_method, a_args, a_test, a_expect, a_return, a_stage, r_cshare);
   if (rc < 0)  return rc;
   --rce;  if (strchr (YSTR_CHARS, a_share) == NULL)  return rce;
   /*---(wrap last cond)-----------------*/
   CODE__cond_end (a_code, a_last, a_verb);
   /*---(create)-------------------------*/
   CONV_printf (a_code, "   /*---(shared code)--------------------*/\n");
   CONV_printf (a_code, "   cyUNIT.offset = %d;\n", s_scond);
   CONV_printf (a_code, "   yUNIT_shared_%c ();\n", a_share);
   CONV_printf (a_code, "   cyUNIT.offset = 0;\n");
   REUSE_add (a_share, &(s_scond), &(s_sstep));
   s_cstep = s_sstep;
   /*---(complete)-----------------------*/
   DEBUG_UVER   yLOG_uexit   (__FUNCTION__);
   return 0;
}



/*====================------------------------------------====================*/
/*===----                         step support                         ----===*/
/*====================------------------------------------====================*/
static void  o___STEP_SUPPORT____o () { return; }

static char   s_disp       [LEN_RECD]  = "";
static char   s_syst       [LEN_RECD]  = "";
static char   s_load       [LEN_RECD]  = "";

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
         /*> case  G_CHAR_RETURN :                                                       <*/
         x_disp [i]  = G_CHAR_RETURN;
         sprintf (t, "\\n");
         strlcat (x_syst, t, LEN_RECD);
         strlcat (x_load, t, LEN_RECD);
         break;
      case  G_KEY_ESCAPE :
         /*> case  G_CHAR_ESCAPE :                                                       <*/
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
CODE__prefix            (FILE *a_code, cchar a_verb [LEN_LABEL], cchar a_desc [LEN_LONG], cchar a_method [LEN_HUND], cchar a_test [LEN_LABEL], cchar a_display [LEN_RECD], cchar a_system [LEN_RECD], char a_dittoing, int a_nline, int a_dline)
{
   /*---(locals)-----------+-----------+-*/
   char        x_func      [LEN_FULL]   = "";
   /*---(run function)-------------------*/
   if (strcmp (a_verb, "echo") != 0) {
      CONV_printf (a_code, "      yUNIT_reset_rc ();\n");
      switch (a_test [0]) {
      case 'v'  :
         CONV_printf (a_code, "      if (cyUNIT.exec)  %s (%s);\n", a_method , a_system);
         break;
      case 's'  : case 'u'  : case 'w'  :
         CONV_printf (a_code, "      if (cyUNIT.exec)  cyUNIT.s_rc = %s (%s);\n", a_method , a_system);
         break;
      case 'i'  : case 'c'  :
         CONV_printf (a_code, "      if (cyUNIT.exec)  cyUNIT.i_rc = %s (%s);\n", a_method , a_system);
         break;
      case 'r'  :
         CONV_printf (a_code, "      if (cyUNIT.exec)  cyUNIT.r_rc = %s (%s);\n", a_method , a_system);
         break;
      case 'p'  :
         CONV_printf (a_code, "      if (cyUNIT.exec)  cyUNIT.p_rc = %s (%s);\n", a_method , a_system);
         break;
      }
   }
   /*---(determine function)-------------*/
   switch (a_test [0]) {
   case 'v'  : strlcpy (x_func, "yUNIT_void"     , LEN_FULL);    break;
   case 's'  : strlcpy (x_func, "yUNIT_string"   , LEN_FULL);    break;
   case 'w'  : strlcpy (x_func, "yUNIT_wrap"     , LEN_FULL);    break;
   case 'u'  : strlcpy (x_func, "yUNIT_round"    , LEN_FULL);    break;
   case 'c'  : strlcpy (x_func, "yUNIT_char"     , LEN_FULL);    break;
   case 'i'  : strlcpy (x_func, "yUNIT_int"      , LEN_FULL);    break;
   case 'r'  : strlcpy (x_func, "yUNIT_real"     , LEN_FULL);    break;
   case 'p'  : strlcpy (x_func, "yUNIT_point"    , LEN_FULL);    break;
   default   : strlcpy (x_func, "yUNIT_unknown"  , LEN_FULL);    break;
   }
   /*---(write prefix)-------------------*/
   CONV_printf (a_code, "      ");
   CONV_printf (a_code, "%-13s ("              , x_func);
   CONV_printf (a_code, "%4i, %3i, "           , CODE__line (a_dittoing, a_nline, a_dline), s_cstep);
   CONV_printf (a_code, "\"%s\", "             , a_desc);
   CONV_printf (a_code, "\"%s\", \"%s\", "     , a_method  , a_display);
   /*---(write test)---------------------*/
   switch (a_test [0]) {
   case 'v' :    /* pure void        */
      CONV_printf (a_code, "\"%s\", cyUNIT.exec);\n", a_test);
      break;
   default  :    /* all others       */
      CONV_printf (a_code, "\"%s\", "          , a_test);
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
         CONV_printf (a_code, "\"%s\", " , a_expect);
         break;
      case 'c' :                            /* character   */
         CONV_printf (a_code, "%s, "     , a_expect);
         break;
      case 'i' : case 'p' : case 'r' :      /* numberish   */
         CONV_printf (a_code, "%s, "     , a_expect);
         break;
      default  :
         CONV_printf (a_code, "\"%s\", cyUNIT.exec);\n"         , a_expect);
         break;
      }
      return 1;
   }
   /*---(check for var)------------------*/
   else {
      strlcpy (x_var, a_expect + 3, LEN_RECD);
      x_expe = x_var;
      p = strtok_r (x_var, q, &r);
      if (p == NULL) CONV_printf (a_code, "\"%s\", " , "unknown");
      else           CONV_printf (a_code, "%s, "     , x_expe);
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
      CONV_printf (a_code, "%s, cyUNIT.exec);\n"      , a_system);
   }
   /*---(check for simple end)-----------*/
   else {
      switch (a_test [0]) {
      case 's'  : case 'u'  : case 'w'  :
         CONV_printf (a_code, "cyUNIT.s_rc, cyUNIT.exec);\n");
         break;
      case 'i'  : case 'c'  :
         CONV_printf (a_code, "cyUNIT.i_rc, cyUNIT.exec);\n");
         break;
      case 'r'  :
         CONV_printf (a_code, "cyUNIT.r_rc, cyUNIT.exec);\n");
         break;
      case 'p'  :
         CONV_printf (a_code, "cyUNIT.p_rc, cyUNIT.exec);\n");
         break;
      }
   }
   /*---(handle return variables)--------*/
   if (strcmp (a_return, "") != 0) {
      switch (a_test [0]) {
      case 's'  : case 'u'  : case 'w'  :
         CONV_printf (a_code, "      if (cyUNIT.exec) { if (cyUNIT.s_rc != NULL)  strcpy (%s, cyUNIT.s_rc); else strcpy (x_str, \"\"); }\n", a_return);
         break;
      case 'i'  : case 'c'  :
         CONV_printf (a_code, "      if (cyUNIT.exec)  %s = cyUNIT.i_rc;\n", a_return);
         break;
      case 'r'  :
         CONV_printf (a_code, "      if (cyUNIT.exec)  %s = cyUNIT.r_rc;\n", a_return);
         break;
      case 'p'  :
         CONV_printf (a_code, "      if (cyUNIT.exec)  %s = cyUNIT.p_rc;\n", a_return);
         break;
      }
   }
   /*---(complete)-----------------------*/
   return 1;
}

char
CODE__specialty         (FILE *a_code, cchar a_load [LEN_RECD])
{
   /*---(locals)-----------+-----+-----+-*/
   char       *p           = NULL;
   char       *q           =  " ";
   char       *r           = NULL;
   char        x_temp      [LEN_FULL];
   char       *x_var       = NULL;
   /*---(parse)--------------------------*/
   if (strncmp (a_load, "[[ ", 3) != 0) {
      CONV_printf (a_code, "\"%s\"", a_load);
   } else {
      strlcpy (x_temp, a_load + 3, LEN_FULL);
      x_var = x_temp;
      p = strtok_r (x_temp, q, &r);
      if (p == NULL) CONV_printf (a_code, "\"%s\"" , "unknown");
      else           CONV_printf (a_code, "%s" , x_var);
   }
   /*---(finish)-------------------------*/
   CONV_printf (a_code, ", cyUNIT.exec);\n");
   /*---(complete)-----------------------*/
   return 0;
}



/*====================------------------------------------====================*/
/*===----                       step level verbs                       ----===*/
/*====================------------------------------------====================*/
static void  o___STEP____________o () { return; }

char
CODE__step_add          (FILE *a_code, cchar a_runtype, cchar a_verb [LEN_LABEL], cchar a_desc [LEN_LONG], char a_dittoing, int a_nline, int a_dline)
{
   /*---(increment)----------------------*/
   ++(s_nstep);
   ++(s_ustep);
   ++(s_sstep);
   ++(s_cstep);
   if (a_dittoing == 'y')  ++(s_dstep);
   /*---(comment for code)---------------*/
   switch (a_verb [0]) {
   case  'e'  :
      if      (a_verb [1] == 'x')   CONV_printf (a_code, "      /*---(run step)--------------------*/\n");
      else if (a_verb [1] == 'c')   CONV_printf (a_code, "      /*---(echo to verify)--------------*/\n");
      break;
   case  'l'  :
      if      (a_verb [2] == 'a')   CONV_printf (a_code, "      /*---(load input)------------------*/\n");
      else if (a_verb [2] == 'c')   CONV_printf (a_code, "      /*---(local variable)--------------*/\n");
      break;
   case  'm'  :
      CONV_printf (a_code, "      /*---(unit test mode)--------------*/\n");
      break;
   case  'c'  :
      CONV_printf (a_code, "      /*---(inject code)-----------------*/\n");
      break;
   case  'f'  :
      CONV_printf (a_code, "      /*---(create test file)------------*/\n");
      break;
   case  'a'  :
      CONV_printf (a_code, "      /*---(append test file)------------*/\n");
      break;
   case  'g'  :
      if      (a_verb [2] == 'o')   CONV_printf (a_code, "/*---(global variable)-------------*/\n");
      else if (a_verb [2] == 't')   CONV_printf (a_code, "      /*---(check result)----------------*/\n");
      break;
   case  's'  :
      CONV_printf (a_code, "      /*---(system command)--------------*/\n");
      break;
   }
   /*---(debugging)----------------------*/
   if (a_runtype == G_RUN_DEBUG && strcmp (a_verb, "global") != 0) {
      CONV_printf (a_code, "      %sUG_PROG    %sOG_unitstep (cyUNIT.origin, cyUNIT.offset + %3i, %3i, %4i, \"%s\");\n", "DEB", "yL", s_scond, s_cstep, CODE__line (a_dittoing, a_nline, a_dline), a_desc);
   }
   /*---(complete)-----------------------*/
   return 0;
}

char
CODE_exec               (char a_nscrp [LEN_TITLE], FILE *a_main, FILE *a_code, FILE *a_wave, cchar a_runtype, cchar a_last [LEN_LABEL], cchar a_verb [LEN_LABEL], cchar a_desc [LEN_LONG], cchar a_method [LEN_HUND], cchar a_args [LEN_FULL], cchar a_test [LEN_LABEL], cchar a_expect [LEN_RECD], cchar a_return [LEN_FULL], cchar a_stage [LEN_SHORT], char a_dittoing, char a_mark, char a_dmark, int a_nline, int a_dline, char a_share, char *r_cshare)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rc          =    0;
   char        x_display   [LEN_RECD]  = "";
   char        x_system    [LEN_RECD]  = "";
   /*---(defense)------------------------*/
   rc = CODE__defense (a_nscrp, a_main, a_code, a_wave, a_runtype, a_last, a_verb, a_desc, a_method, a_args, a_test, a_expect, a_return, a_stage, r_cshare);
   if (rc < 0)  return rc;
   /*---(prepare)------------------------*/
   CODE__step_add  (a_code, a_runtype, a_verb, a_desc, a_dittoing, a_nline, a_dline);
   CODE__display   (a_args, x_display, x_system, NULL);
   /*---(create)-------------------------*/
   CODE__prefix    (a_code, a_verb, a_desc, a_method, a_test, x_display, x_system, a_dittoing, a_nline, a_dline);
   CODE__expect    (a_code, a_test, a_expect);
   CODE__suffix    (a_code, a_verb, a_test, x_system, a_return);
   /*---(complete)-----------------------*/
   return 0;
}

char
CODE_load               (char a_nscrp [LEN_TITLE], FILE *a_main, FILE *a_code, FILE *a_wave, cchar a_runtype, cchar a_last [LEN_LABEL], cchar a_verb [LEN_LABEL], cchar a_desc [LEN_LONG], cchar a_method [LEN_HUND], cchar a_args [LEN_FULL], cchar a_test [LEN_LABEL], cchar a_expect [LEN_RECD], cchar a_return [LEN_FULL], cchar a_stage [LEN_SHORT], char a_dittoing, char a_mark, char a_dmark, int a_nline, int a_dline, char a_share, char *r_cshare)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rc          =    0;
   char        x_display   [LEN_RECD]  = "";
   char        x_load      [LEN_RECD]  = "";
   /*---(defense)------------------------*/
   rc = CODE__defense (a_nscrp, a_main, a_code, a_wave, a_runtype, a_last, a_verb, a_desc, a_method, a_args, a_test, a_expect, a_return, a_stage, r_cshare);
   if (rc < 0)  return rc;
   /*---(prepare)------------------------*/
   CODE__step_add  (a_code, a_runtype, a_verb, a_desc, a_dittoing, a_nline, a_dline);
   CODE__display   (a_expect, x_display, NULL, x_load);
   /*---(create)-------------------------*/
   CONV_printf     (a_code, "      yUNIT_load    (%4i, %3i, \"%s\", \"%s\", ", CODE__line (a_dittoing, a_nline, a_dline), s_cstep, a_desc, a_method);
   CODE__specialty (a_code, x_load);
   /*---(complete)-----------------------*/
   return 0;
}

char
CODE_file               (char a_nscrp [LEN_TITLE], FILE *a_main, FILE *a_code, FILE *a_wave, cchar a_runtype, cchar a_last [LEN_LABEL], cchar a_verb [LEN_LABEL], cchar a_desc [LEN_LONG], cchar a_method [LEN_HUND], cchar a_args [LEN_FULL], cchar a_test [LEN_LABEL], cchar a_expect [LEN_RECD], cchar a_return [LEN_FULL], cchar a_stage [LEN_SHORT], char a_dittoing, char a_mark, char a_dmark, int a_nline, int a_dline, char a_share, char *r_cshare)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rc          =    0;
   char        x_display   [LEN_RECD]  = "";
   char        x_system    [LEN_RECD]  = "";
   /*---(defense)------------------------*/
   rc = CODE__defense (a_nscrp, a_main, a_code, a_wave, a_runtype, a_last, a_verb, a_desc, a_method, a_args, a_test, a_expect, a_return, a_stage, r_cshare);
   if (rc < 0)  return rc;
   /*---(prepare)------------------------*/
   CODE__step_add  (a_code, a_runtype, a_verb, a_desc, a_dittoing, a_nline, a_dline);
   CODE__display   (a_expect, x_display, x_system, NULL);
   /*---(create)-------------------------*/
   CONV_printf     (a_code, "      yUNIT_file    (%4i, %3i, \"%s\", ", CODE__line (a_dittoing, a_nline, a_dline), s_cstep, a_desc);
   CODE__specialty (a_code, x_system);
   /*---(complete)-----------------------*/
   return 0;
}

char
CODE_append             (char a_nscrp [LEN_TITLE], FILE *a_main, FILE *a_code, FILE *a_wave, cchar a_runtype, cchar a_last [LEN_LABEL], cchar a_verb [LEN_LABEL], cchar a_desc [LEN_LONG], cchar a_method [LEN_HUND], cchar a_args [LEN_FULL], cchar a_test [LEN_LABEL], cchar a_expect [LEN_RECD], cchar a_return [LEN_FULL], cchar a_stage [LEN_SHORT], char a_dittoing, char a_mark, char a_dmark, int a_nline, int a_dline, char a_share, char *r_cshare)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rc          =    0;
   char        x_display   [LEN_RECD]  = "";
   char        x_system    [LEN_RECD]  = "";
   /*---(defense)------------------------*/
   rc = CODE__defense (a_nscrp, a_main, a_code, a_wave, a_runtype, a_last, a_verb, a_desc, a_method, a_args, a_test, a_expect, a_return, a_stage, r_cshare);
   if (rc < 0)  return rc;
   /*---(prepare)------------------------*/
   CODE__step_add  (a_code, a_runtype, a_verb, a_desc, a_dittoing, a_nline, a_dline);
   CODE__display   (a_expect, x_display, x_system, NULL);
   /*---(create)-------------------------*/
   CONV_printf     (a_code, "      yUNIT_append  (%4i, %3i, \"%s\", ", CODE__line (a_dittoing, a_nline, a_dline), s_cstep, a_desc);
   CODE__specialty (a_code, x_system);
   /*---(complete)-----------------------*/
   return 0;
}

char
CODE_mode               (char a_nscrp [LEN_TITLE], FILE *a_main, FILE *a_code, FILE *a_wave, cchar a_runtype, cchar a_last [LEN_LABEL], cchar a_verb [LEN_LABEL], cchar a_desc [LEN_LONG], cchar a_method [LEN_HUND], cchar a_args [LEN_FULL], cchar a_test [LEN_LABEL], cchar a_expect [LEN_RECD], cchar a_return [LEN_FULL], cchar a_stage [LEN_SHORT], char a_dittoing, char a_mark, char a_dmark, int a_nline, int a_dline, char a_share, char *r_cshare)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rc          =    0;
   /*---(defense)------------------------*/
   rc = CODE__defense (a_nscrp, a_main, a_code, a_wave, a_runtype, a_last, a_verb, a_desc, a_method, a_args, a_test, a_expect, a_return, a_stage, r_cshare);
   if (rc < 0)  return rc;
   /*---(prepare)------------------------*/
   CODE__step_add  (a_code, a_runtype, a_verb, a_desc, a_dittoing, a_nline, a_dline);
   /*---(create)-------------------------*/
   CONV_printf     (a_code, "      yUNIT_mode    (%4i, %3i, \"%s\", cyUNIT.exec);\n", CODE__line (a_dittoing, a_nline, a_dline), s_cstep, a_desc);
   /*---(complete)-----------------------*/
   return 0;
}

char
CODE_code               (char a_nscrp [LEN_TITLE], FILE *a_main, FILE *a_code, FILE *a_wave, cchar a_runtype, cchar a_last [LEN_LABEL], cchar a_verb [LEN_LABEL], cchar a_desc [LEN_LONG], cchar a_method [LEN_HUND], cchar a_args [LEN_FULL], cchar a_test [LEN_LABEL], cchar a_expect [LEN_RECD], cchar a_return [LEN_FULL], cchar a_stage [LEN_SHORT], char a_dittoing, char a_mark, char a_dmark, int a_nline, int a_dline, char a_share, char *r_cshare)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rc          =    0;
   char        x_display   [LEN_RECD]  = "";
   char        x_system    [LEN_RECD]  = "";
   /*---(defense)------------------------*/
   rc = CODE__defense (a_nscrp, a_main, a_code, a_wave, a_runtype, a_last, a_verb, a_desc, a_method, a_args, a_test, a_expect, a_return, a_stage, r_cshare);
   if (rc < 0)  return rc;
   /*---(prepare)------------------------*/
   CODE__step_add  (a_code, a_runtype, a_verb, a_desc, a_dittoing, a_nline, a_dline);
   CODE__display   (a_expect, x_display, x_system, NULL);
   /*---(create)-------------------------*/
   CONV_printf     (a_code, "      yUNIT_code    (%4i, %3i, \"%s\", \"%s\", cyUNIT.exec);\n", CODE__line (a_dittoing, a_nline, a_dline), s_cstep, a_desc, x_display);
   CONV_printf     (a_code, "      if (cyUNIT.exec) { %s }\n",  x_system);
   /*---(complete)-----------------------*/
   return 0;
}

char
CODE_gvar               (char a_nscrp [LEN_TITLE], FILE *a_main, FILE *a_code, FILE *a_wave, cchar a_runtype, cchar a_last [LEN_LABEL], cchar a_verb [LEN_LABEL], cchar a_desc [LEN_LONG], cchar a_method [LEN_HUND], cchar a_args [LEN_FULL], cchar a_test [LEN_LABEL], cchar a_expect [LEN_RECD], cchar a_return [LEN_FULL], cchar a_stage [LEN_SHORT], char a_dittoing, char a_mark, char a_dmark, int a_nline, int a_dline, char a_share, char *r_cshare)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rc          =    0;
   char        x_display   [LEN_RECD]  = "";
   char        x_system    [LEN_RECD]  = "";
   /*---(defense)------------------------*/
   rc = CODE__defense (a_nscrp, a_main, a_code, a_wave, a_runtype, a_last, a_verb, a_desc, a_method, a_args, a_test, a_expect, a_return, a_stage, r_cshare);
   if (rc < 0)  return rc;
   /*---(prepare)------------------------*/
   CODE__step_add  (a_code, a_runtype, a_verb, a_desc, a_dittoing, a_nline, a_dline);
   CODE__display   (a_expect, x_display, x_system, NULL);
   /*---(create)-------------------------*/
   CONV_printf     (a_code, "%s\n",  x_system);
   /*---(complete)-----------------------*/
   return 0;
}

char
CODE_lvar               (char a_nscrp [LEN_TITLE], FILE *a_main, FILE *a_code, FILE *a_wave, cchar a_runtype, cchar a_last [LEN_LABEL], cchar a_verb [LEN_LABEL], cchar a_desc [LEN_LONG], cchar a_method [LEN_HUND], cchar a_args [LEN_FULL], cchar a_test [LEN_LABEL], cchar a_expect [LEN_RECD], cchar a_return [LEN_FULL], cchar a_stage [LEN_SHORT], char a_dittoing, char a_mark, char a_dmark, int a_nline, int a_dline, char a_share, char *r_cshare)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rc          =    0;
   char        x_display   [LEN_RECD]  = "";
   char        x_system    [LEN_RECD]  = "";
   /*---(defense)------------------------*/
   rc = CODE__defense (a_nscrp, a_main, a_code, a_wave, a_runtype, a_last, a_verb, a_desc, a_method, a_args, a_test, a_expect, a_return, a_stage, r_cshare);
   if (rc < 0)  return rc;
   /*---(prepare)------------------------*/
   CODE__step_add  (a_code, a_runtype, a_verb, a_desc, a_dittoing, a_nline, a_dline);
   CODE__display   (a_expect, x_display, x_system, NULL);
   /*---(create)-------------------------*/
   CONV_printf     (a_code, "      yUNIT_local   (%4i, %3i, \"%s\", \"%s\", cyUNIT.exec);\n", CODE__line (a_dittoing, a_nline, a_dline), s_cstep, a_desc, x_display);
   CONV_printf     (a_code, "      %s\n",  x_system);
   /*---(complete)-----------------------*/
   return 0;
}

char
CODE_system             (char a_nscrp [LEN_TITLE], FILE *a_main, FILE *a_code, FILE *a_wave, cchar a_runtype, cchar a_last [LEN_LABEL], cchar a_verb [LEN_LABEL], cchar a_desc [LEN_LONG], cchar a_method [LEN_HUND], cchar a_args [LEN_FULL], cchar a_test [LEN_LABEL], cchar a_expect [LEN_RECD], cchar a_return [LEN_FULL], cchar a_stage [LEN_SHORT], char a_dittoing, char a_mark, char a_dmark, int a_nline, int a_dline, char a_share, char *r_cshare)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rc          =    0;
   char        x_display   [LEN_RECD]  = "";
   char        x_system    [LEN_RECD]  = "";
   /*---(defense)------------------------*/
   rc = CODE__defense (a_nscrp, a_main, a_code, a_wave, a_runtype, a_last, a_verb, a_desc, a_method, a_args, a_test, a_expect, a_return, a_stage, r_cshare);
   if (rc < 0)  return rc;
   /*---(prepare)------------------------*/
   CODE__step_add  (a_code, a_runtype, a_verb, a_desc, a_dittoing, a_nline, a_dline);
   CODE__display   (a_expect, x_display, x_system, NULL);
   /*---(create)-------------------------*/
   CONV_printf     (a_code, "      yUNIT_system  (%4i, %3i, \"%s\", \"%s\", \"%s\", cyUNIT.exec);\n", CODE__line (a_dittoing, a_nline, a_dline), s_cstep, a_desc, x_display, x_system);
   /*---(complete)-----------------------*/
   return 0;
}



/*====================------------------------------------====================*/
/*===----                          main driver                         ----===*/
/*====================------------------------------------====================*/
static void  o___DRIVER__________o () { return; }

char
CODE_driver             (void f_call (), char a_nscrp [LEN_TITLE], FILE *a_main, FILE *a_code, FILE *a_wave, cchar a_runtype, cchar a_last [LEN_LABEL], cchar a_verb [LEN_LABEL], cchar a_desc [LEN_LONG], cchar a_method [LEN_HUND], cchar a_args [LEN_FULL], cchar a_test [LEN_LABEL], cchar a_expect [LEN_RECD], cchar a_return [LEN_FULL], cchar a_stage [LEN_SHORT], char a_dittoing, char a_mark, char a_dmark, int a_nline, int a_dline, char a_share, char *r_cshare)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char      (*x_func) (char a_nscrp [LEN_TITLE], FILE *a_main, FILE *a_code, FILE *a_wave, cchar a_runtype, cchar a_last [LEN_LABEL], cchar a_verb [LEN_LABEL], cchar a_desc [LEN_LONG], cchar a_method [LEN_HUND], cchar a_args [LEN_FULL], cchar a_test [LEN_LABEL], cchar a_expect [LEN_RECD], cchar a_return [LEN_FULL], cchar a_stage [LEN_SHORT], char a_dittoing, char a_mark, char a_dmark, int a_nline, int a_dline, char a_share, char *r_cshare);
   /*---(header)-------------------------*/
   DEBUG_UVER   yLOG_uenter  (__FUNCTION__);
   /*---(defense)------------------------*/
   DEBUG_UVER   yLOG_upoint  ("f_call"    , f_call);
   if (f_call == NULL) {
      DEBUG_UVER   yLOG_unote   ("nothing to do");
      DEBUG_UVER   yLOG_uexit   (__FUNCTION__);
      return 0;
   }
   /*---(prepare)------------------------*/
   x_func = f_call;
   /*---(call function)------------------*/
   rc = x_func (a_nscrp, a_main, a_code, a_wave, a_runtype, a_last, a_verb, a_desc, a_method, a_args, a_test, a_expect, a_return, a_stage, a_dittoing, a_mark, a_dmark, a_nline, a_dline, a_share, r_cshare);
   DEBUG_UVER   yLOG_uvalue  ("call"      , rc);
   --rce;  if (rc < 0) {
      DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(complete)-----------------------*/
   DEBUG_UVER   yLOG_uexit   (__FUNCTION__);
   return 0;
}



/*====================------------------------------------====================*/
/*===----                    unit testing helpers                      ----===*/
/*====================------------------------------------====================*/
static void  o___UNITEST_________o () { return; }

char
CODE_force              (int a_scrps, int  a_conds)
{
   CODE_init ();
   s_nscrp = a_scrps;
   s_ncond = a_conds;
   return 0;
}



/*===============================[[ end code ]]===============================*/
