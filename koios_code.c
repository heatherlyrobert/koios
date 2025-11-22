/*===============================[[ beg-code ]]===============================*/
#include    "koios.h"        /* LOCAL  : main header                          */
#include    <yUNIT_solo.h>        /* CUSTOM : heatherly unit testing               */




static int  s_cunit  = 0;
static int  s_cscrp  = 0;
static int  s_ccond  = 0;
static int  s_cstep  = 0;



static int  s_master_cond   [26];          /* count of cond in each share    */
static int  s_master_step   [26];          /* count of step in each share    */
static int  s_reuses_cond   [26];          /* count of cond in each share    */
static int  s_reuses_step   [26];          /* count of step in each share    */



static char s_in_cond  = '-';


/*> static int  s_nscrp  = 0;                                                         <*/
/*> static int  s_ncond  = 0;                                                         <*/
/*> static int  s_nstep  = 0;                                                         <*/

/*> static int  s_uscrp  = 0;                                                         <*/
/*> static int  s_ucond  = 0;                                                         <*/
/*> static int  s_ustep  = 0;                                                         <*/

/*> static int  s_scond  = 0;                                                         <*/
/*> static int  s_sstep  = 0;                                                         <*/

/*> static int  s_cstep  = 0;                                                         <*/

static int  s_dcond  = 0;
static int  s_dstep  = 0;



/*====================------------------------------------====================*/
/*===----                         program level                        ----===*/
/*====================------------------------------------====================*/
static void  o___PROGRAM_________o () { return; }

char
CODE_init               (void)
{
   /*> s_nscrp  = s_ncond = s_nstep = 0;                                              <* 
    *> s_uscrp  = s_ucond = s_ustep = 0;                                              <* 
    *> s_scond  = s_sstep = 0;                                                        <* 
    *> s_cstep  = 0;                                                                  <*/
   s_in_cond = '-';
   yUNIT_stats_purge (YUNIT_BUILD  , &s_cunit, &s_cscrp, &s_ccond, &s_cstep);
   return 0;
}

char
CODE__defense           (char a_nscrp [LEN_TITLE], FILE *a_main, FILE *a_head, FILE *a_code, FILE *a_wave, char a_runtype, char a_last [LEN_LABEL], char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_meth [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expe [LEN_RECD], char a_retn [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_major, char a_minor, char *b_share, char *b_select)
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
   --rce;  if (a_which  == NULL)  return rce;
   --rce;  if (a_major  == 0)     return rce;
   --rce;  if (a_minor  == 0)     return rce;
   --rce;  if (b_share  == NULL)  return rce;
   --rce;  if (b_select == NULL)  return rce;
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
/*===----                     selectable execution                     ----===*/
/*====================------------------------------------====================*/
static void  o___SELECT__________o () { return; }

char
CODE__select_beg        (FILE* a_code, char a_verb [LEN_TERSE], char a_which [LEN_TITLE], char a_share, char r_pre [LEN_TERSE])
{
   /*---(only cond/step level)-----------*/
   if (r_pre != NULL)  strcpy (r_pre, "");
   /*---(in scripts)---------------------*/
   if (a_share == '-' || VERB_selectable (a_verb) == 0)  {
      if (strchr ("CGR", a_verb [0]) != NULL)  { CONV_printf (a_code, "   {  ++mykoios_ncond;\n");  return 0; }
      else                                     { CONV_printf (a_code, "      ++mykoios_nstep;\n");  return 0; }
   }
   /*---(share selectable)---------------*/
   if (strcmp (a_which, "") != 0) {
      if      (strchr ("CGR", a_verb [0]) != NULL)   CONV_printf (a_code, "   if (strchr (\"*%s\", a_select) != NULL) {  ++mykoios_ncond;\n"   , a_which);
      else                                           CONV_printf (a_code, "      if (strchr (\"*%s\", a_select) != NULL) {  ++mykoios_nstep;\n", a_which);
      if (r_pre != NULL)  strcpy (r_pre, "   ");
   }
   /*---(share always)-------------------*/
   else {
      if (strchr ("CGR", a_verb [0]) != NULL)   CONV_printf (a_code, "   {  ++mykoios_ncond;\n");
      else                                      CONV_printf (a_code, "      ++mykoios_nstep;\n");
   }
   /*---(complete)-----------------------*/
   return 1;
}

char
CODE__select_end        (FILE* a_code, char a_verb [LEN_TERSE], char a_which [LEN_TITLE], char a_share)
{
   if (a_share == '-')                 { if (strchr ("CGR", a_verb [0]) != NULL)   CONV_printf (a_code, "   }\n");  return 0;  }
   if (VERB_selectable (a_verb) == 0)  { if (strchr ("CGR", a_verb [0]) != NULL)   CONV_printf (a_code, "   }\n");  return 0;  }
   if      (strchr ("CGR", a_verb [0]) != NULL)   CONV_printf (a_code, "   }\n");
   else if (strcmp (a_which, "") != 0)            CONV_printf (a_code, "      }\n");
   return 1;
}



/*====================------------------------------------====================*/
/*===----                         preparations                         ----===*/
/*====================------------------------------------====================*/
static void  o___PREP____________o () { return; }

char
CODE__code_beg          (char a_nscrp [LEN_TITLE], FILE *a_code)
{
   /*---(header)-------------------------*/
   UDEBUG_KOIOS   ylog_uenter  (__FUNCTION__);
   CONV_printf (a_code, "/*================================= beg-code =================================*/\n");
   CONV_printf (a_code, "/* /usr/local/bin/koios                                                       */\n");
   CONV_printf (a_code, "/*   autogen by %-60.60s  */\n", P_ONELINE);
   IF_NOT_HEAD {
      CONV_printf (a_code, "\n");
      CONV_printf (a_code, "/*---(standard support functions)----*/\n");
      CONV_printf (a_code, "#include    <yURG.h>\n");
      CONV_printf (a_code, "#include    <yUNIT_unit.h>\n");
      if (yenv_uexists ("unit_code.h") == 'r')  CONV_printf (a_code, "#include    \"unit_code.h\"\n");
      if (yenv_uexists ("unit_head.h") == 'r')  CONV_printf (a_code, "#include    \"unit_head.h\"\n");
      IF_LOCAL {
         if (yenv_uexists ("unit_wide.h") == 'r')  CONV_printf (a_code, "#include    \"unit_wide.h\"\n");
         if (yenv_uexists ("unit_data.h") == 'r')  CONV_printf (a_code, "#include    \"unit_data.h\"\n");
      }
      CONV_printf (a_code, "\n");
      CONV_printf (a_code, "/*================================ beg-script ================================*/\n");
   } else {
      CONV_printf (a_code, "\n");
      CONV_printf (a_code, "/*================================ beg-global ================================*/\n");
   }
   /*---(complete)-----------------------*/
   UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
   return 0;
}

char
CODE__code_stats        (FILE *a_code)
{
   /*---(header)-------------------------*/
   UDEBUG_KOIOS   ylog_uenter  (__FUNCTION__);
   CONV_printf (a_code, "\n");
   CONV_printf (a_code, "char\n");
   CONV_printf (a_code, "yUNIT_stats     (void)\n");
   CONV_printf (a_code, "{\n");
   CONV_printf (a_code, "   yUNIT_unique (%d, %d, %d, %d, %d, %d);\n", s_cscrp, s_ccond, s_cstep, s_cscrp, s_ccond - s_dcond, s_cstep - s_dstep);
   CONV_printf (a_code, "   return 0;\n");
   CONV_printf (a_code, "}\n");
   CONV_printf (a_code, "\n");
   UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
   return 0;
}

char
CODE__code_end          (char a_nscrp [LEN_TITLE], FILE *a_code)
{
   /*---(header)-------------------------*/
   UDEBUG_KOIOS   ylog_uenter  (__FUNCTION__);
   CONV_printf (a_code, "\n");
   IF_NOT_HEAD {
      CONV_printf (a_code, "/*================================ end-script ================================*/\n");
   } else {
      CONV_printf (a_code, "/*================================ end-global ================================*/\n");
   }
   UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
   return 0;
}

char
CODE__main_beg          (FILE *a_main, char a_nscrp [LEN_TITLE])
{
   char        x_urun      [LEN_TITLE] = "";
   int         l           =    0;
   /*---(header)-------------------------*/
   UDEBUG_KOIOS   ylog_uenter  (__FUNCTION__);
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
   UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
   return 0;
}

char
CODE__main_end          (FILE *a_main)
{
   /*---(header)-------------------------*/
   UDEBUG_KOIOS   ylog_uenter  (__FUNCTION__);
   CONV_printf (a_main, "   /*---(end scripts)--------------------*/\n");
   CONV_printf (a_main, "   rc = yUNIT_tinu (cyUNIT.exec);\n");
   CONV_printf (a_main, "   /*---(complete)-----------------------*/\n");
   CONV_printf (a_main, "   return rc;\n");
   CONV_printf (a_main, "}\n");
   CONV_printf (a_main, "\n\n\n");
   CONV_printf (a_main, "/* end-of-file.  done, finito, completare, whimper [Ï´···                     */\n");
   CONV_printf (a_main, "/*================================= end-code =================================*/\n");
   UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
   return 0;
}

char
CODE_header             (char a_nscrp [LEN_TITLE], char a_nmain [LEN_TITLE], FILE **r_main, char a_nhead [LEN_TITLE], FILE **r_head, char a_ncode [LEN_TITLE], FILE **r_code, char a_nwave [LEN_TITLE], FILE **r_wave, char *b_share, char *b_select)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   FILE       *x_main      = NULL;
   FILE       *x_head      = NULL;
   FILE       *x_code      = NULL;
   FILE       *x_wave      = NULL;
   /*---(header)-------------------------*/
   UDEBUG_KOIOS   ylog_uenter  (__FUNCTION__);
   /*---(show args)----------------------*/
   UDEBUG_KOIOS   ylog_uinfo   ("a_nmain"   , a_nmain);
   UDEBUG_KOIOS   ylog_uinfo   ("a_nhead"   , a_nhead);
   UDEBUG_KOIOS   ylog_uinfo   ("a_ncode"   , a_ncode);
   UDEBUG_KOIOS   ylog_uinfo   ("a_nwave"   , a_nwave);
   /*---(open main)----------------------*/
   rc = yenv_uopen_detail (__FILE__, __FUNCTION__, __LINE__, a_nmain, 'w', &x_main);
   UDEBUG_KOIOS   ylog_uvalue  ("main"      , rc);
   --rce;  if (rc < 0 || x_main == NULL) {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(open header)--------------------*/
   --rce;  if (a_nhead == NULL || strcmp (a_nhead, "") != 0) {
      rc = yenv_uopen_detail (__FILE__, __FUNCTION__, __LINE__, a_nhead, 'w', &x_head);
      UDEBUG_KOIOS   ylog_uvalue  ("head"      , rc);
      if (rc < 0 || x_head == NULL) {
         yenv_uclose_detail (__FILE__, __FUNCTION__, __LINE__, a_nhead, &x_head);
         UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
         return rce;
      }
   }
   /*---(open code)----------------------*/
   rc = yenv_uopen_detail (__FILE__, __FUNCTION__, __LINE__, a_ncode, 'w', &x_code);
   UDEBUG_KOIOS   ylog_uvalue  ("code"      , rc);
   --rce;  if (rc < 0 || x_code == NULL) {
      yenv_uclose_detail (__FILE__, __FUNCTION__, __LINE__, a_nmain, &x_main);
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(open wave)----------------------*/
   --rce;  if (a_nwave == NULL || strcmp (a_nwave, "") != 0) {
      rc = yenv_uopen_detail (__FILE__, __FUNCTION__, __LINE__, a_nwave, 'w', &x_wave);
      UDEBUG_KOIOS   ylog_uvalue  ("wave"      , rc);
      if (rc < 0 || x_wave == NULL) {
         yenv_uclose_detail (__FILE__, __FUNCTION__, __LINE__, a_nmain, &x_main);
         yenv_uclose_detail (__FILE__, __FUNCTION__, __LINE__, a_ncode, &x_code);
         UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
         return rce;
      }
   }
   /*---(add headers)--------------------*/
   CODE__main_beg (x_main, a_nscrp);
   CODE__code_beg (a_nscrp, x_code);
   /*---(default globals)----------------*/
   yUNIT_stats_purge (YUNIT_BUILD  , &s_cunit, &s_cscrp, &s_ccond, &s_cstep);
   if (b_share  != NULL)  *b_share  = '-';
   if (b_select != NULL)  *b_select = '-';
   /*---(save-back)----------------------*/
   if (r_main   != NULL)  *r_main   = x_main;
   if (r_head   != NULL)  *r_head   = x_head;
   if (r_code   != NULL)  *r_code   = x_code;
   if (r_wave   != NULL)  *r_wave   = x_wave;
   /*---(complete)-----------------------*/
   UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
   return 0;
}

char
CODE_footer             (char a_good, char a_nscrp [LEN_TITLE], char a_nmain [LEN_TITLE], FILE **r_main, char a_nhead [LEN_TITLE], FILE **r_head, char a_ncode [LEN_TITLE], FILE **r_code, char a_nwave [LEN_TITLE], FILE **r_wave, int a_nline, char a_share, char a_select, char a_unit)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        x_recd      [LEN_RECD]  = "";
   char        t           [LEN_HUND]  = "";
   char        x_ftype     =  '-';
   char        x_header    [LEN_TITLE] = "";
   /*---(header)-------------------------*/
   UDEBUG_KOIOS   ylog_uenter  (__FUNCTION__);
   /*---(show args)----------------------*/
   UDEBUG_KOIOS   ylog_uchar   ("a_good"    , a_good);
   UDEBUG_KOIOS   ylog_uinfo   ("a_nscrp"   , a_nscrp);
   UDEBUG_KOIOS   ylog_uinfo   ("a_nmain"   , a_nmain);
   UDEBUG_KOIOS   ylog_uinfo   ("a_nhead"   , a_nhead);
   UDEBUG_KOIOS   ylog_uinfo   ("a_ncode"   , a_ncode);
   UDEBUG_KOIOS   ylog_uinfo   ("a_nwave"   , a_nwave);
   /*---(polish off scripts)-------------*/
   if (s_cscrp >  0 && a_share == '-')   yUNIT_wave_end (my_loc.l_WAVE);
   CODE__scrp_end          (*r_code, "----", a_nline, "----", a_share);
   /*---(code endings)-------------------*/
   if (a_good == 'y') {
      CODE__main_end   (*r_main);
      CODE__code_end   (a_nscrp, *r_code);
   }
   /*---(informational)------------------*/
   if (a_good == 'y') {
      IF_NOT_HEAD {
         CODE__code_stats (*r_code);
         VERB_inventory   (*r_code);
      }
   }
   /*---(append main)--------------------*/
   if (a_good == 'y') {
      UDEBUG_KOIOS   ylog_unote   ("handle good/passed units");
      /*---(append main)-----------------*/
      IF_NOT_HEAD {
         if (*r_main != NULL)  yenv_uclose_detail (__FILE__, __FUNCTION__, __LINE__, a_nmain, r_main);
         yenv_uopen_detail  (__FILE__, __FUNCTION__, __LINE__, a_nmain, 'r', r_main);
         /*> printf ("MAIN------------------------------------------\n");                <*/
         while (1) {
            fgets (x_recd, LEN_RECD, *r_main);
            if (feof (*r_main)) break;
            CONV_printf (*r_code, x_recd);
         }
         /*> printf ("MAIN------------------------------------------\n");                <*/
      }
   }
   /*---(export globals)--------------*/
   if (a_good == 'y') {
      IF_GLOBAL {
         UDEBUG_KOIOS   ylog_unote   ("export globals (code)");
         rc = yUNIT_reuse_export (KOIOS_GLOBALS);
         UDEBUG_KOIOS   ylog_uvalue  ("export"    , rc);
         IF_NOT_HEAD {
            x_ftype = yUNIT_reuse_ftype (a_nscrp, x_header);
            UDEBUG_KOIOS   ylog_uchar   ("x_ftype"   , x_ftype);
            UDEBUG_KOIOS   ylog_uinfo   ("x_header"  , x_header);
            rc = yUNIT_reuse_header (x_ftype, x_header);
            UDEBUG_KOIOS   ylog_uvalue  ("headers"   , rc);
         }
         UDEBUG_KOIOS   ylog_uinfo   ("used"      , yUNIT_reuse_used ());
      }
   }
   /*---(write wave footer)--------------*/
   if (r_wave != NULL && *r_wave != NULL)  fprintf (*r_wave, "\n");
   /*---(close files)--------------------*/
   if (*r_main != NULL)  rc = yenv_uclose_detail (__FILE__, __FUNCTION__, __LINE__, a_nmain, r_main);
   if (*r_head != NULL)  rc = yenv_uclose_detail (__FILE__, __FUNCTION__, __LINE__, a_nhead, r_head);
   if (*r_code != NULL)  rc = yenv_uclose_detail (__FILE__, __FUNCTION__, __LINE__, a_ncode, r_code);
   if (*r_wave != NULL)  rc = yenv_uclose_detail (__FILE__, __FUNCTION__, __LINE__, a_nwave, r_wave);
   /*---(transfer master.h)--------------*/
   if (a_good == 'y') {
      IF_HEAD   system  ("mv -f unit_head.cs unit_head.h");
   }
   /*---(clean-up)-----------------------*/
   if (a_unit != 'y') {
      sprintf (t, "rm -f %s", a_nmain); system  (t);
      if (a_good != 'y') {
         sprintf (t, "rm -f %s", a_ncode); system  (t);
         sprintf (t, "rm -f %s", a_nwave); system  (t);
      }
   }
   /*---(complete)-----------------------*/
   UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
   return 0;
}

char
CODE__incl              (char a_nscrp [LEN_TITLE], FILE *a_main, FILE *a_head, FILE *a_code, FILE *a_wave, char a_runtype, char a_last [LEN_LABEL], int a_nline, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_dittoing, char a_dtarget, int a_dline, char a_major, char a_minor, char *b_share, char *b_select)
{
   char        t           [LEN_HUND]  = "";
   /*---(header)-------------------------*/
   UDEBUG_KOIOS   ylog_uenter  (__FUNCTION__);
   if (a_method [0] == '<')   strcpy  (t, a_method);
   else                       sprintf (t, "\"%s\"", a_method);
   CONV_printf (a_code, "#include    %-22.22s               /* %4i, %-32.32s */\n", t, CODE__line (a_dittoing, a_nline, a_dline), a_desc);
   UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
   return 0;
}



/*====================------------------------------------====================*/
/*===----                      script level verbs                      ----===*/
/*====================------------------------------------====================*/
static void  o___SCRP____________o () { return; }

char
CODE__scrp_end          (FILE *a_code, char a_last [LEN_LABEL], char a_nline, char a_verb [LEN_LABEL], char a_share)
{
   short       x_conds     =    0;
   short       x_steps     =    0;
   /*---(header)-------------------------*/
   UDEBUG_KOIOS   ylog_uenter  (__FUNCTION__);
   /*---(reset verb counts)--------------*/
   VERB_script_reset ();
   /*---(quick out)----------------------*/
   if (strcmp (a_last, "SECT") == 0) {
      UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
      return 0;
   }
   /*---(wrap last cond)-----------------*/
   CODE__cond_end (a_code, a_last, a_verb, a_nline, a_share);
   /*---(end share)----------------------*/
   /*> if (a_share != '-')   yUNIT_reuse_update (a_share, s_ccond, s_cstep);                <*/
   /*---(close script/share)-------------*/
   if (s_cscrp >  0 || a_share != '-') {
      if (a_share == '-') {
         CONV_printf (a_code, "   /*===[[ script done ]]==========================*/\n");
         CONV_printf (a_code, "   yUNIT_prcs    (cyUNIT.exec);                   /* %4d */\n", a_nline);
      }
      else if (strchr (YSTR_LOWER, a_share) != NULL)  {
         yUNIT_reuse_data (a_share, NULL, NULL, NULL, NULL, NULL, NULL, NULL, &x_conds, &x_steps, NULL);
         CONV_printf (a_code, "   /*===[[ shared done ]]==========================*/\n");
         CONV_printf (a_code, "   yUNIT_rahs   ('%c', a_select, %3d, %3d, mykoios_ncond, mykoios_nstep);   /* %4d */\n", a_share, x_conds, x_steps, a_nline);
         /*> s_ucond -= s_scond;                                                      <* 
          *> s_ustep -= s_sstep;                                                      <*/
      }
      else if (strchr (YSTR_UPPER, a_share) != NULL)  {
         yUNIT_reuse_data (a_share, NULL, NULL, NULL, NULL, NULL, NULL, NULL, &x_conds, &x_steps, NULL);
         CONV_printf (a_code, "   /*===[[ global done ]]==========================*/\n");
         CONV_printf (a_code, "   yUNIT_bolg   ('%c', a_select, %3d, %3d, mykoios_ncond, mykoios_nstep);   /* %4d */\n", a_share, x_conds, x_steps, a_nline);
         /*> s_ucond -= s_scond;                                                      <* 
          *> s_ustep -= s_sstep;                                                      <*/
      }
      else if (strchr (YSTR_GREEK, a_share) != NULL)  {
         yUNIT_reuse_data (a_share, NULL, NULL, NULL, NULL, NULL, NULL, NULL, &x_conds, &x_steps, NULL);
         CONV_printf (a_code, "   /*===[[ config done ]]==========================*/\n");
         CONV_printf (a_code, "   yUNIT_fnoc   ('%c', a_select, %3d, %3d, mykoios_ncond, mykoios_nstep);   /* %4d */\n", a_share, x_conds, x_steps, a_nline);
         /*> s_ucond -= s_scond;                                                      <* 
          *> s_ustep -= s_sstep;                                                      <*/
      }
      CONV_printf (a_code, "   /*---(complete)-----------------------*/\n");
      CONV_printf (a_code, "   return mykoios_ncond;\n");
      CONV_printf (a_code, "}\n");
   }
   /*---(complete)-----------------------*/
   UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
   return 0;
}

char
CODE__scrp              (char a_nscrp [LEN_TITLE], FILE *a_main, FILE *a_head, FILE *a_code, FILE *a_wave, char a_runtype, char a_last [LEN_LABEL], int a_nline, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_dittoing, char a_dtarget, int a_dline, char a_major, char a_minor, char *b_share, char *b_select)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rc          =    0;
   char        l           =    0;
   char        x_stage     =  '·';
   char        x_wave      =  '·';
   char        x_rating    =  '·';
   /*---(header)-------------------------*/
   UDEBUG_KOIOS   ylog_uenter  (__FUNCTION__);
   /*---(defense)------------------------*/
   /*> rc = CODE__defense (a_nscrp, a_main, a_head, a_code, a_wave, a_runtype, a_last, a_verb, a_desc, a_method, a_args, a_test, a_expect, a_return, a_stage, a_which, a_major, a_minor, b_share, b_select);   <* 
    *> UDEBUG_KOIOS   ylog_uvalue  ("defense"   , rc);                                                                                                                                                           <* 
    *> if (rc < 0) {                                                                                                                                                                                           <* 
    *>    UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rc);                                                                                                                                                        <* 
    *>    return rc;                                                                                                                                                                                           <* 
    *> }                                                                                                                                                                                                       <*/
   /*---(wrap last script)---------------*/
   if (s_cscrp >  0 && *b_share == '-')   yUNIT_wave_end (a_wave);
   CODE__scrp_end (a_code, a_last, a_nline, a_verb, *b_share);
   *b_share  = '-';
   *b_select = '-';
   /*---(statistics)---------------------*/
   yUNIT_stats_scrp  (YUNIT_BUILD  , NULL, "", YUNIT_IS_SCRP, a_verb, a_major, &s_cunit, &s_cscrp, &s_ccond, &s_cstep);
   /*---(open script function)-----------*/
   CONV_printf (a_code, "\n");
   CONV_printf (a_code, "int\n");
   CONV_printf (a_code, "yUNIT_script_%02d          (void)\n", s_cscrp);
   CONV_printf (a_code, "{\n");
   CONV_printf (a_code, "   /*===[[ script header ]]========================*/\n");
   CONV_printf (a_code, "   cyUNIT.offset  = 0;\n");
   CONV_printf (a_code, "   cyUNIT.origin  = %d;\n", s_cscrp);
   CONV_printf (a_code, "   yUNIT_mode_reset ();\n");
   CONV_printf (a_code, "   yUNIT_scrp    (%4i, %3i, \"%s\", \"%s\", \"%s\", \"%s\", \"%s\");\n", CODE__line (a_dittoing, a_nline, a_dline), s_cscrp, a_stage, a_desc, a_test, a_return, a_method);
   CONV_printf (a_code, "   int mykoios_ncond  = 0;\n");
   CONV_printf (a_code, "   int mykoios_nstep  = 0;\n");
   CONV_printf (a_code, "   int mykoios_ncurr  = 0;\n");
   CONV_printf (a_code, "   int mykoios_nshar  = 0;\n");
   /*---(function call to main)----------*/
   CONV_printf (a_main, "   if (yUNIT_run_scrp (%2i) == 1)  yUNIT_script_%02d ();\n", s_cscrp, s_cscrp);
   /*---(script entry in wave)-----------*/
   UDEBUG_KOIOS   ylog_uinfo   ("a_stage"   , a_stage);
   l = strlen (a_stage);
   UDEBUG_KOIOS   ylog_uvalue  ("l"         , l);
   if (l > 0)   x_wave   = a_stage [0];
   if (l > 1)   x_stage  = a_stage [1];
   if (l > 3)   x_rating = a_stage [3];
   UDEBUG_KOIOS   ylog_ucomplex("stage"     , "%d %c %c %c", l, x_wave, x_stage, x_rating);
   yUNIT_wave_beg (my_loc.l_proj, my_loc.l_base, s_cscrp, a_desc, a_return, x_wave, x_stage, x_rating, a_test);
   /*---(complete)-----------------------*/
   UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
   return 0;
}

char
CODE__shared            (char a_nscrp [LEN_TITLE], FILE *a_main, FILE *a_head, FILE *a_code, FILE *a_wave, char a_runtype, char a_last [LEN_LABEL], int a_nline, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_dittoing, char a_dtarget, int a_dline, char a_major, char a_minor, char *b_share, char *b_select)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        t           [LEN_TERSE] = "";
   uchar       x_char      =  '-';
   char        x_ftype     =  '-';
   /*---(header)-------------------------*/
   UDEBUG_KOIOS   ylog_uenter  (__FUNCTION__);
   /*---(defense)------------------------*/
   /*> rc = CODE__defense (a_nscrp, a_main, a_head, a_code, a_wave, a_runtype, a_last, a_verb, a_desc, a_method, a_args, a_test, a_expect, a_return, a_stage, a_which, a_major, a_minor, b_share, b_select);   <* 
    *> UDEBUG_KOIOS   ylog_uvalue  ("defense"   , rc);                                                                                                                                                           <* 
    *> if (rc < 0) {                                                                                                                                                                                           <* 
    *>    UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rc);                                                                                                                                                        <* 
    *>    return rc;                                                                                                                                                                                           <* 
    *> }                                                                                                                                                                                                       <*/
   /*> CONV_printf ("CODE__shared (%c) %d\n", a_major, a_nline);                      <*/
   /*---(end last script)----------------*/
   if (s_cscrp >  0 && *b_share == '-')   yUNIT_wave_end (a_wave);
   CODE__scrp_end (a_code, a_last, a_nline, a_verb, *b_share);
   /*---(statistics)---------------------*/
   yUNIT_stats_scrp  (YUNIT_BUILD  , NULL, "", YUNIT_IS_SHAR, a_verb, a_major, &s_cunit, &s_cscrp, &s_ccond, &s_cstep);
   /*---(counters)-----------------------*/
   *b_share  = a_major;
   *b_select = a_minor;
   /*> yUNIT_reuse_update (a_major,  0,  0);                                                <*/
   /*---(prepare)------------------------*/
   switch (a_verb [0]) {
   case 'G'  :  strcpy (t, "global");  x_char = a_major;  break;
   case 'S'  :  strcpy (t, "shared");  x_char = a_major;  break;
   case 'C'  :  strcpy (t, "config");  x_char  = a_major; x_char -= (uchar) 'è'; x_char += 'a';  break;
   }
   x_ftype = yUNIT_reuse_ftype (a_nscrp, NULL);
   /*---(open script function)-----------*/
   CONV_printf (a_code, "\n");
   CONV_printf (a_code, "int\n");
   CONV_printf (a_code, "yUNIT_%-6.6s_%c           (char a_select)         /* %4d, %c, %-32.32s */\n", t, x_char, a_nline, a_major, a_desc);
   CONV_printf (a_code, "{\n");
   CONV_printf (a_code, "   /*===[[ %-6.6s header ]]========================*/\n", t);
   CONV_printf (a_code, "   yUNIT_%-4.4s ('%c', '%c', %d, a_select, \"%s\");\n", t, a_major, x_ftype, a_nline, a_desc);
   CONV_printf (a_code, "   int mykoios_ncond  = 0;\n");
   CONV_printf (a_code, "   int mykoios_nstep  = 0;\n");
   /*---(complete)-----------------------*/
   UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
   return 0;
}

char
CODE__sect              (char a_nscrp [LEN_TITLE], FILE *a_main, FILE *a_head, FILE *a_code, FILE *a_wave, char a_runtype, char a_last [LEN_LABEL], int a_nline, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_dittoing, char a_dtarget, int a_dline, char a_major, char a_minor, char *b_share, char *b_select)
{
   /*---(header)-------------------------*/
   UDEBUG_KOIOS   ylog_uenter  (__FUNCTION__);
   /*---(end last script)----------------*/
   if (s_cscrp >  0 && *b_share == '-')   yUNIT_wave_end (a_wave);
   CODE__scrp_end (a_code, a_last, a_nline, a_verb, *b_share);
   /*---(statistics)---------------------*/
   yUNIT_stats_scrp  (YUNIT_BUILD  , NULL, "", YUNIT_IS_SECT, a_verb, a_major, &s_cunit, &s_cscrp, &s_ccond, &s_cstep);
   /*---(add section)--------------------*/
   CONV_printf (a_main, "   if (cyUNIT.all          == 1)  yUNIT_sect      (\"%s\");\n", a_desc);
   /*---(complete)-----------------------*/
   UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
   return 0;
}



/*====================------------------------------------====================*/
/*===----                       condition level                        ----===*/
/*====================------------------------------------====================*/
static void  o___COND____________o () { return; }

char
CODE__cond_end          (FILE *a_code, char a_last [LEN_LABEL], char a_verb [LEN_LABEL], char a_nline, char a_share)
{
   char        x_pre       [LEN_TERSE] = "";
   /*---(header)-------------------------*/
   UDEBUG_KOIOS   ylog_uenter  (__FUNCTION__);
   UDEBUG_KOIOS   ylog_ucomplex("counters"  , "%-10.10s, %-10.10s, %4dn, %4dc", a_last, a_verb, s_ccond, s_ccond);
   /*---(quick-out)----------------------*/
   if (strstr ("GROUP REUSE", a_last) != NULL) {
      UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
      return 0;
   }
   /*> CONV_printf      (a_code, "   /+ cond_end w/s_in_cond = %c +/\n", s_in_cond);   <*/
   /*---(end condition)------------------*/
   /*> if (strcmp (a_last, "----") != 0 && s_ccond > 0) {                             <*/
   /*> if (s_ccond > 0) {                                                             <*/
   if (s_in_cond == 'y') {
      /*> CONV_printf (a_code, "      /+ last = å%sæ, verb = å%sæ+/\n", a_last, a_verb);   <*/
      CONV_printf (a_code, "      /*---(summary)---------------------*/\n");
      CONV_printf (a_code, "      yUNIT_dnoc    (cyUNIT.exec);                /* %4d */\n", a_nline);
      CONV_printf (a_code, "      /*---(done)------------------------*/\n");
      CODE__select_end (a_code, "COND", "", a_share);
      s_in_cond = '-';
   }
   /*---(complete)-----------------------*/
   UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
   return 0;
}

char
CODE__cond              (char a_nscrp [LEN_TITLE], FILE *a_main, FILE *a_head, FILE *a_code, FILE *a_wave, char a_runtype, char a_last [LEN_LABEL], int a_nline, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_dittoing, char a_dtarget, int a_dline, char a_major, char a_minor, char *b_share, char *b_select)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rc          =    0;
   char        x_pre       [LEN_TERSE] = "";
   char        a           =    0;
   /*---(header)-------------------------*/
   UDEBUG_KOIOS   ylog_uenter  (__FUNCTION__);
   /*---(defense)------------------------*/
   /*> rc = CODE__defense (a_nscrp, a_main, a_head, a_code, a_wave, a_runtype, a_last, a_verb, a_desc, a_method, a_args, a_test, a_expect, a_return, a_stage, a_which, a_major, a_minor, b_share, b_select);   <* 
    *> UDEBUG_KOIOS   ylog_uvalue  ("defense"   , rc);                                                                                                                                                           <* 
    *> if (rc < 0) {                                                                                                                                                                                           <* 
    *>    UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rc);                                                                                                                                                        <* 
    *>    return rc;                                                                                                                                                                                           <* 
    *> }                                                                                                                                                                                                       <*/
   /*---(wrap last cond)-----------------*/
   CODE__cond_end (a_code, a_last, a_verb, a_nline, *b_share);
   /*> CONV_printf      (a_code, "   /+ COND = %4d, s_in_cond = %c +/\n", s_ccond, s_in_cond);   <*/
   s_in_cond = 'y';
   /*---(statistics)---------------------*/
   rc = yUNIT_stats_cond  (YUNIT_BUILD  , NULL, "", YUNIT_IS_COND, a_verb, a_desc, a_dittoing, a_ditto, a_major, *b_share, &s_cunit, &s_cscrp, &s_ccond, &s_cstep);
   /*> printf ("rc = %4d, %4du, %4ds, %4dc, %4ds\n", rc, s_cunit, s_cscrp, s_ccond, s_cstep);   <*/
   UDEBUG_KOIOS   ylog_ucomplex("counters"  , "%-10.10s, %4dn, %4dc", a_last, s_ccond, s_ccond);
   /*---(initial comment)----------------*/
   /*> CONV_printf      (a_code, "   /+ cond = %4d, s_in_cond = %c +/\n", s_ccond, s_in_cond);   <*/
   CONV_printf      (a_code, "   /*===[[ COND #%03d ]]============================*/\n", s_ccond);
   CODE__select_beg (a_code, a_verb, a_which, *b_share, x_pre);
   /*---(debugging)----------------------*/
   if (a_runtype == G_RUN_DEBUG) {
      CONV_printf (a_code, "      %sUG_UNIT    %sOG_unitcond (cyUNIT.origin, cyUNIT.offset + mykoios_ncond, %4i, \"%s\");\n", "DEB", "yL", CODE__line (a_dittoing, a_nline, a_dline), a_desc);
   }
   /*---(code)---------------------------*/
   /*> CONV_printf (a_code, "      yUNIT_printf  (\"DEBUG  %%4d offset, %%4d ncond, %%4d nstep\\n\", cyUNIT.offset, mykoios_ncond, mykoios_nstep);\n");   <*/
   /*> printf ("%5d %c %c %c %c\n", a_nline, a_dittoing, a_ditto, a_dtarget, a_major);   <*/
   /*> CONV_printf (a_code, "      yUNIT_cond    (%4i, cyUNIT.offset + %3i, '%c', '%c', '%c', '%c', \"%s\");\n", a_nline, s_ccond, a_dittoing, a_ditto, a_dtarget, *b_share, a_desc);   <*/
   CONV_printf (a_code, "      yUNIT_cond    (%4i, cyUNIT.offset + mykoios_ncond, '%c', '%c', '%c', '%c', \"%s\");\n", a_nline, a_dittoing, a_ditto, a_dtarget, *b_share, a_desc);
   /*---(complete)-----------------------*/
   UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
   return 0;
}

char
CODE__group             (char a_nscrp [LEN_TITLE], FILE *a_main, FILE *a_head, FILE *a_code, FILE *a_wave, char a_runtype, char a_last [LEN_LABEL], int a_nline, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_dittoing, char a_dtarget, int a_dline, char a_major, char a_minor, char *b_share, char *b_select)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rc          =    0;
   char        t           [LEN_FULL]  = "";
   int         l           =    0;
   char        x_desc      [LEN_FULL]  = "";
   char       *p           = NULL;
   /*---(header)-------------------------*/
   UDEBUG_KOIOS   ylog_uenter  (__FUNCTION__);
   /*---(defense)------------------------*/
   /*> rc = CODE__defense (a_nscrp, a_main, a_head, a_code, a_wave, a_runtype, a_last, a_verb, a_desc, a_method, a_args, a_test, a_expect, a_return, a_stage, a_which, a_major, a_minor, b_share, b_select);   <* 
    *> UDEBUG_KOIOS   ylog_uvalue  ("defense"   , rc);                                                                                                                                                           <* 
    *> if (rc < 0) {                                                                                                                                                                                           <* 
    *>    UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rc);                                                                                                                                                        <* 
    *>    return rc;                                                                                                                                                                                           <* 
    *> }                                                                                                                                                                                                       <*/
   /*---(wrap last cond)-----------------*/
   CODE__cond_end (a_code, a_last, a_verb, a_nline, *b_share);
   /*---(create)-------------------------*/
   CONV_printf (a_code, "   /*===[[ GROUP ]]================================*/\n");
   /*> CODE__select_beg (a_code, a_verb, a_which, *b_share, NULL);                    <*/
   if (strncmp (a_desc, "===[[ ", 6) == 0) {
      strlcpy (x_desc, a_desc + 6, LEN_FULL);
      p = strstr (x_desc, " ]]=");
      if (p != NULL)  p [0] = '\0';
   } else {
      strlcpy (x_desc, a_desc, LEN_FULL);
   }
   sprintf (t     , "(\"%s\");", x_desc);
   l = strlen (t);
   if (l <= 29)  CONV_printf (a_code, "   yUNIT_group   %-29.29s /* %4d, %-32.32s */\n", t, a_nline, x_desc); 
   else          CONV_printf (a_code, "   yUNIT_group   %s /* %4d, %-32.32s */\n", t, a_nline, x_desc); 
   /*> CODE__select_end (a_code, a_verb, a_which, *b_share);                          <*/
   /*---(complete)-----------------------*/
   UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
   return 0;
}

char
CODE__reuse             (char a_nscrp [LEN_TITLE], FILE *a_main, FILE *a_head, FILE *a_code, FILE *a_wave, char a_runtype, char a_last [LEN_LABEL], int a_nline, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_dittoing, char a_dtarget, int a_dline, char a_major, char a_minor, char *b_share, char *b_select)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rc          =    0;
   char        rce         =  -10;
   char        x_type      =  '-';
   uchar       x_char      =  '-';
   /*---(header)-------------------------*/
   UDEBUG_KOIOS   ylog_uenter  (__FUNCTION__);
   /*---(defense)------------------------*/
   /*> rc = CODE__defense (a_nscrp, a_main, a_head, a_code, a_wave, a_runtype, a_last, a_verb, a_desc, a_method, a_args, a_test, a_expect, a_return, a_stage, a_which, a_major, a_minor, b_share, b_select);   <* 
    *> UDEBUG_KOIOS   ylog_uvalue  ("defense"   , rc);                                                                                                                                                           <* 
    *> if (rc < 0) {                                                                                                                                                                                           <* 
    *>    UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rc);                                                                                                                                                        <* 
    *>    return rc;                                                                                                                                                                                           <* 
    *> }                                                                                                                                                                                                       <*/
   /*---(wrap last cond)-----------------*/
   CODE__cond_end (a_code, a_last, a_verb, a_nline, *b_share);
   /*---(statistics)---------------------*/
   yUNIT_stats_cond  (YUNIT_BUILD  , NULL, "", YUNIT_IS_REUS, a_verb, a_desc, a_dittoing, a_ditto, a_major, *b_share, &s_cunit, &s_cscrp, &s_ccond, &s_cstep);
   /*> CONV_printf (a_code, "   /+ cond = %4d +/", s_ccond);                          <*/
   /*---(create)-------------------------*/
   CONV_printf (a_code, "   /*===[[ REUSE SHARE ]]==========================*/\n");
   CODE__select_beg (a_code, a_verb, a_which, *b_share, NULL);
   CONV_printf (a_code, "      cyUNIT.offset = mykoios_ncond - 1;\n");
   if      (strchr (YSTR_UPPER, a_major) != NULL)  x_type = 'g';
   else if (strchr (YSTR_LOWER, a_major) != NULL)  x_type = 's';
   else if (strchr (YSTR_GREEK, a_major) != NULL)  x_type = 'c';
   switch (x_type) {
   case 'g'  :
      CONV_printf (a_code, "      mykoios_ncurr = yUNIT_global_%c ('%c');                       /* %4d, %-32.32s */\n", a_major, a_minor, a_nline, a_desc);
      break;
   case 's'  :
      CONV_printf (a_code, "      mykoios_ncurr = yUNIT_shared_%c ('%c');                       /* %4d, %-32.32s */\n", a_major, a_minor, a_nline, a_desc);
      break;
   case 'c'  :
      x_char  = a_major;
      x_char -= 'è';
      x_char += 'a';
      CONV_printf (a_code, "      mykoios_ncurr = yUNIT_config_%c ('%c');     /* %c */           /* %4d, %-32.32s */\n", x_char, a_minor, a_major, a_nline, a_desc);
      break;
   }
   CONV_printf (a_code, "      mykoios_ncond += mykoios_ncurr - 1;\n");
   CONV_printf (a_code, "      mykoios_nshar += mykoios_ncurr - 1;\n");
   CONV_printf (a_code, "      cyUNIT.offset  = 0;\n");
   CODE__select_end (a_code, a_verb, a_which, *b_share);
   yUNIT_reuse_called (a_major);
   /*> yUNIT_reuse_addback (a_major, &(s_ccond), &(s_cstep));                               <*/
   /*---(complete)-----------------------*/
   UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
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
CODE__display           (char a_code [LEN_RECD], char r_display [LEN_RECD], char r_system [LEN_RECD], char r_load [LEN_RECD])
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
CODE__prefix            (FILE *a_code, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_test [LEN_LABEL], char a_display [LEN_RECD], char a_system [LEN_RECD], char a_dittoing, int a_nline, int a_dline, char a_pre [LEN_TERSE], char a_share)
{
   /*---(locals)-----------+-----------+-*/
   char        x_func      [LEN_FULL]   = "";
   /*---(run function)-------------------*/
   if (strcmp (a_verb, "echo") != 0) {
      CONV_printf (a_code, "%s      yUNIT_reset_rc ();\n", a_pre);
      switch (a_test [0]) {
      case 'v'  :
         CONV_printf (a_code, "%s      if (cyUNIT.exec)  %s (%s);\n", a_pre, a_method , a_system);
         break;
      case 's'  : case 'u'  : case 'w'  :
         CONV_printf (a_code, "%s      if (cyUNIT.exec)  cyUNIT.s_rc = %s (%s);\n", a_pre, a_method , a_system);
         break;
      case 'i'  : case 'c'  : case 'z'  :
         CONV_printf (a_code, "%s      if (cyUNIT.exec)  cyUNIT.i_rc = %s (%s);\n", a_pre, a_method , a_system);
         break;
      case 'r'  :
         CONV_printf (a_code, "%s      if (cyUNIT.exec)  cyUNIT.r_rc = %s (%s);\n", a_pre, a_method , a_system);
         break;
      case 'p'  :
         CONV_printf (a_code, "%s      if (cyUNIT.exec)  cyUNIT.p_rc = %s (%s);\n", a_pre, a_method , a_system);
         break;
      }
   }
   /*---(determine function)-------------*/
   switch (a_test [0]) {
   case 'v'  : strlcpy (x_func, "yUNIT_void"     , LEN_FULL);    break;
   case 's'  : strlcpy (x_func, "yUNIT_string"   , LEN_FULL);    break;
   case 'w'  : strlcpy (x_func, "yUNIT_wrap"     , LEN_FULL);    break;
   case 'u'  : strlcpy (x_func, "yUNIT_round"    , LEN_FULL);    break;
   case 'z'  : strlcpy (x_func, "yUNIT_num"      , LEN_FULL);    break;
   case 'c'  : strlcpy (x_func, "yUNIT_char"     , LEN_FULL);    break;
   case 'i'  : strlcpy (x_func, "yUNIT_int"      , LEN_FULL);    break;
   case 'r'  : strlcpy (x_func, "yUNIT_real"     , LEN_FULL);    break;
   case 'p'  : strlcpy (x_func, "yUNIT_point"    , LEN_FULL);    break;
   default   : strlcpy (x_func, "yUNIT_unknown"  , LEN_FULL);    break;
   }
   /*---(write prefix)-------------------*/
   CONV_printf (a_code, "%s      "             , a_pre);
   CONV_printf (a_code, "%-13s ("              , x_func);
   CONV_printf (a_code, "%4i, %3i, "           , CODE__line (a_dittoing, a_nline, a_dline), s_cstep);
   CONV_printf (a_code, "\"%s\", "             , a_desc);
   CONV_printf (a_code, "\"%s\", \"%s\", "     , a_method  , a_display);
   /*---(write test)---------------------*/
   switch (a_test [0]) {
   case 'v' :    /* pure void        */
      CONV_printf (a_code, "\"%s\", cyUNIT.exec, '%c', '%c');\n", a_test, a_dittoing, a_share);
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
CODE__expect            (FILE *a_code, char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_dittoing)
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
      case 'i' : case 'p' : case 'r' :      /* numberish   */
      case 'c' : case 'z' :                 /* character   */
         CONV_printf (a_code, "%s, "     , a_expect);
         break;
      default  :
         CONV_printf (a_code, "\"%s\", cyUNIT.exec, '%c');\n"         , a_expect, a_dittoing);
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
CODE__suffix            (FILE *a_code, char a_verb [LEN_LABEL], char a_test [LEN_LABEL], char a_system [LEN_RECD], char a_return [LEN_FULL], char a_pre [LEN_TERSE], char a_dittoing, char a_share)
{
   /*---(defense)------------------------*/
   if (a_test [0] == 'v')    return 0;
   /*---(handle echos)-------------------*/
   if (strcmp (a_verb, "echo") == 0) {
      CONV_printf (a_code, "%s, cyUNIT.exec, '%c', '%c');\n"      , a_system, a_dittoing, a_share);
   }
   /*---(check for simple end)-----------*/
   else {
      switch (a_test [0]) {
      case 's'  : case 'u'  : case 'w'  :
         CONV_printf (a_code, "cyUNIT.s_rc, cyUNIT.exec, '%c', '%c');\n", a_dittoing, a_share);
         break;
      case 'i'  : case 'c'  : case 'z'  :
         CONV_printf (a_code, "cyUNIT.i_rc, cyUNIT.exec, '%c', '%c');\n", a_dittoing, a_share);
         break;
      case 'r'  :
         CONV_printf (a_code, "cyUNIT.r_rc, cyUNIT.exec, '%c', '%c');\n", a_dittoing, a_share);
         break;
      case 'p'  :
         CONV_printf (a_code, "cyUNIT.p_rc, cyUNIT.exec, '%c', '%c');\n", a_dittoing, a_share);
         break;
      }
   }
   /*---(handle return variables)--------*/
   if (strcmp (a_return, "") != 0) {
      switch (a_test [0]) {
      case 's'  : case 'u'  : case 'w'  :
         CONV_printf (a_code, "%s      if (cyUNIT.exec) { if (cyUNIT.s_rc != NULL)  strcpy (%s, cyUNIT.s_rc); }\n", a_pre, a_return);
         break;
      case 'i'  : case 'c'  : case 'z'  :
         CONV_printf (a_code, "%s      if (cyUNIT.exec)  %s = cyUNIT.i_rc;\n", a_pre, a_return);
         break;
      case 'r'  :
         CONV_printf (a_code, "%s      if (cyUNIT.exec)  %s = cyUNIT.r_rc;\n", a_pre, a_return);
         break;
      case 'p'  :
         CONV_printf (a_code, "%s      if (cyUNIT.exec)  %s = cyUNIT.p_rc;\n", a_pre, a_return);
         break;
      }
   }
   /*---(complete)-----------------------*/
   return 1;
}

char
CODE__specialty         (FILE *a_code, char a_load [LEN_RECD], char a_dittoing, char a_share)
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
   CONV_printf (a_code, ", cyUNIT.exec, '%c', '%c');\n", a_dittoing, a_share);
   /*---(complete)-----------------------*/
   return 0;
}



/*====================------------------------------------====================*/
/*===----                       step level verbs                       ----===*/
/*====================------------------------------------====================*/
static void  o___STEP____________o () { return; }

char
CODE__step_add          (FILE *a_code, char a_runtype, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_dittoing, int a_nline, int a_dline)
{
   /*---(header)-------------------------*/
   UDEBUG_KOIOS   ylog_uenter  (__FUNCTION__);
   /*---(comment for code)---------------*/
   switch (a_verb [0]) {
   case  'e'  :
      if      (a_verb [1] == 'x')   CONV_printf (a_code, "      /*---(run step)--------------------*/\n");
      else if (a_verb [1] == 'c')   CONV_printf (a_code, "      /*---(echo to verify)--------------*/\n");
      break;
   case  'l'  :
      if      (a_verb [2] == 'a')   CONV_printf (a_code, "      /*---(load input)------------------*/\n");
      else if (a_verb [2] == 'c')   CONV_printf (a_code, "   /*---(local variable)--------------*/\n");
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
      CONV_printf (a_code, "      %sUG_UNIT    %sOG_unitstep (cyUNIT.origin, cyUNIT.offset + mykoios_ncond, %3i, %4i, \"%s\");\n", "DEB", "yL", s_cstep, CODE__line (a_dittoing, a_nline, a_dline), a_desc);
   }
   /*---(complete)-----------------------*/
   UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
   return 0;
}

char
CODE__exec              (char a_nscrp [LEN_TITLE], FILE *a_main, FILE *a_head, FILE *a_code, FILE *a_wave, char a_runtype, char a_last [LEN_LABEL], int a_nline, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_dittoing, char a_dtarget, int a_dline, char a_major, char a_minor, char *b_share, char *b_select)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rc          =    0;
   char        x_pre       [LEN_TERSE] = "";
   char        x_display   [LEN_RECD]  = "";
   char        x_system    [LEN_RECD]  = "";
   /*---(header)-------------------------*/
   UDEBUG_KOIOS   ylog_uenter  (__FUNCTION__);
   /*---(defense)------------------------*/
   /*> rc = CODE__defense (a_nscrp, a_main, a_head, a_code, a_wave, a_runtype, a_last, a_verb, a_desc, a_method, a_args, a_test, a_expect, a_return, a_stage, a_which, a_major, a_minor, b_share, b_select);   <* 
    *> UDEBUG_KOIOS   ylog_uvalue  ("defense"   , rc);                                                                                                                                                           <* 
    *> if (rc < 0) {                                                                                                                                                                                           <* 
    *>    UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rc);                                                                                                                                                        <* 
    *>    return rc;                                                                                                                                                                                           <* 
    *> }                                                                                                                                                                                                       <*/
   /*---(statistics)---------------------*/
   yUNIT_stats_step  (YUNIT_BUILD  , NULL, "", YUNIT_IS_EXEC, a_verb, a_desc, a_dittoing, a_ditto, a_major, *b_share, &s_cunit, &s_cscrp, &s_ccond, &s_cstep);
   /*---(prepare)------------------------*/
   CODE__step_add   (a_code, a_runtype, a_verb, a_desc, a_dittoing, a_nline, a_dline);
   CODE__display    (a_args, x_display, x_system, NULL);
   /*---(create)-------------------------*/
   CODE__select_beg (a_code, a_verb, a_which, *b_share, x_pre);
   CODE__prefix     (a_code, a_verb, a_desc, a_method, a_test, x_display, x_system, a_dittoing, a_nline, a_dline, x_pre, *b_share);
   CODE__expect     (a_code, a_test, a_expect, a_dittoing);
   CODE__suffix     (a_code, a_verb, a_test, x_system, a_return, x_pre, a_dittoing, *b_share);
   CODE__select_end (a_code, a_verb, a_which, *b_share);
   /*---(complete)-----------------------*/
   UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
   return 0;
}

char
CODE__load              (char a_nscrp [LEN_TITLE], FILE *a_main, FILE *a_head, FILE *a_code, FILE *a_wave, char a_runtype, char a_last [LEN_LABEL], int a_nline, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_dittoing, char a_dtarget, int a_dline, char a_major, char a_minor, char *b_share, char *b_select)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rc          =    0;
   char        x_pre       [LEN_TERSE] = "";
   char        x_display   [LEN_RECD]  = "";
   char        x_load      [LEN_RECD]  = "";
   /*---(header)-------------------------*/
   UDEBUG_KOIOS   ylog_uenter  (__FUNCTION__);
   /*---(defense)------------------------*/
   /*> rc = CODE__defense (a_nscrp, a_main, a_head, a_code, a_wave, a_runtype, a_last, a_verb, a_desc, a_method, a_args, a_test, a_expect, a_return, a_stage, a_which, a_major, a_minor, b_share, b_select);   <* 
    *> UDEBUG_KOIOS   ylog_uvalue  ("defense"   , rc);                                                                                                                                                           <* 
    *> if (rc < 0) {                                                                                                                                                                                           <* 
    *>    UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rc);                                                                                                                                                        <* 
    *>    return rc;                                                                                                                                                                                           <* 
    *> }                                                                                                                                                                                                       <*/
   /*---(statistics)---------------------*/
   yUNIT_stats_step  (YUNIT_BUILD  , NULL, "", YUNIT_IS_VOID, a_verb, a_desc, a_dittoing, a_ditto, a_major, *b_share, &s_cunit, &s_cscrp, &s_ccond, &s_cstep);
   /*---(prepare)------------------------*/
   CODE__step_add   (a_code, a_runtype, a_verb, a_desc, a_dittoing, a_nline, a_dline);
   CODE__display    (a_expect, x_display, NULL, x_load);
   /*---(create)-------------------------*/
   CODE__select_beg (a_code, a_verb, a_which, *b_share, x_pre);
   CONV_printf      (a_code, "%s      yUNIT_load    (%4i, %3i, \"%s\", \"%s\", ", x_pre, CODE__line (a_dittoing, a_nline, a_dline), s_cstep, a_desc, a_method);
   CODE__specialty  (a_code, x_load, a_dittoing, *b_share);
   CODE__select_end (a_code, a_verb, a_which, *b_share);
   /*---(complete)-----------------------*/
   UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
   return 0;
}

char
CODE__file              (char a_nscrp [LEN_TITLE], FILE *a_main, FILE *a_head, FILE *a_code, FILE *a_wave, char a_runtype, char a_last [LEN_LABEL], int a_nline, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_dittoing, char a_dtarget, int a_dline, char a_major, char a_minor, char *b_share, char *b_select)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rc          =    0;
   char        x_pre       [LEN_TERSE] = "";
   char        x_display   [LEN_RECD]  = "";
   char        x_system    [LEN_RECD]  = "";
   /*---(header)-------------------------*/
   UDEBUG_KOIOS   ylog_uenter  (__FUNCTION__);
   /*---(defense)------------------------*/
   /*> rc = CODE__defense (a_nscrp, a_main, a_head, a_code, a_wave, a_runtype, a_last, a_verb, a_desc, a_method, a_args, a_test, a_expect, a_return, a_stage, a_which, a_major, a_minor, b_share, b_select);   <* 
    *> UDEBUG_KOIOS   ylog_uvalue  ("defense"   , rc);                                                                                                                                                           <* 
    *> if (rc < 0) {                                                                                                                                                                                           <* 
    *>    UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rc);                                                                                                                                                        <* 
    *>    return rc;                                                                                                                                                                                           <* 
    *> }                                                                                                                                                                                                       <*/
   /*---(statistics)---------------------*/
   yUNIT_stats_step  (YUNIT_BUILD  , NULL, "", YUNIT_IS_EXEC, a_verb, a_desc, a_dittoing, a_ditto, a_major, *b_share, &s_cunit, &s_cscrp, &s_ccond, &s_cstep);
   /*---(prepare)------------------------*/
   CODE__step_add  (a_code, a_runtype, a_verb, a_desc, a_dittoing, a_nline, a_dline);
   CODE__display   (a_expect, x_display, x_system, NULL);
   /*---(create)-------------------------*/
   CODE__select_beg (a_code, a_verb, a_which, *b_share, x_pre);
   CONV_printf     (a_code, "%s      yUNIT_file    (%4i, %3i, \"%s\", ", x_pre, CODE__line (a_dittoing, a_nline, a_dline), s_cstep, a_desc);
   CODE__specialty (a_code, x_system, a_dittoing, *b_share);
   CODE__select_end (a_code, a_verb, a_which, *b_share);
   /*---(complete)-----------------------*/
   UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
   return 0;
}

char
CODE__append            (char a_nscrp [LEN_TITLE], FILE *a_main, FILE *a_head, FILE *a_code, FILE *a_wave, char a_runtype, char a_last [LEN_LABEL], int a_nline, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_dittoing, char a_dtarget, int a_dline, char a_major, char a_minor, char *b_share, char *b_select)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rc          =    0;
   char        x_pre       [LEN_TERSE] = "";
   char        x_display   [LEN_RECD]  = "";
   char        x_system    [LEN_RECD]  = "";
   /*---(header)-------------------------*/
   UDEBUG_KOIOS   ylog_uenter  (__FUNCTION__);
   /*---(defense)------------------------*/
   /*> rc = CODE__defense (a_nscrp, a_main, a_head, a_code, a_wave, a_runtype, a_last, a_verb, a_desc, a_method, a_args, a_test, a_expect, a_return, a_stage, a_which, a_major, a_minor, b_share, b_select);   <* 
    *> UDEBUG_KOIOS   ylog_uvalue  ("defense"   , rc);                                                                                                                                                           <* 
    *> if (rc < 0) {                                                                                                                                                                                           <* 
    *>    UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rc);                                                                                                                                                        <* 
    *>    return rc;                                                                                                                                                                                           <* 
    *> }                                                                                                                                                                                                       <*/
   /*---(statistics)---------------------*/
   yUNIT_stats_step  (YUNIT_BUILD  , NULL, "", YUNIT_IS_EXEC, a_verb, a_desc, a_dittoing, a_ditto, a_major, *b_share, &s_cunit, &s_cscrp, &s_ccond, &s_cstep);
   /*---(prepare)------------------------*/
   CODE__step_add  (a_code, a_runtype, a_verb, a_desc, a_dittoing, a_nline, a_dline);
   CODE__display   (a_expect, x_display, x_system, NULL);
   /*---(create)-------------------------*/
   CODE__select_beg (a_code, a_verb, a_which, *b_share, x_pre);
   CONV_printf     (a_code, "%s      yUNIT_append  (%4i, %3i, \"%s\", ", x_pre, CODE__line (a_dittoing, a_nline, a_dline), s_cstep, a_desc);
   if (strcmp (a_verb, "append") == 0)  CODE__specialty (a_code, x_system , a_dittoing, *b_share);
   else                                 CODE__specialty (a_code, x_display, a_dittoing, *b_share);
   CODE__select_end (a_code, a_verb, a_which, *b_share);
   /*---(complete)-----------------------*/
   UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
   return 0;
}

char
CODE__mode              (char a_nscrp [LEN_TITLE], FILE *a_main, FILE *a_head, FILE *a_code, FILE *a_wave, char a_runtype, char a_last [LEN_LABEL], int a_nline, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_dittoing, char a_dtarget, int a_dline, char a_major, char a_minor, char *b_share, char *b_select)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rc          =    0;
   char        x_pre       [LEN_TERSE] = "";
   /*---(header)-------------------------*/
   UDEBUG_KOIOS   ylog_uenter  (__FUNCTION__);
   /*---(defense)------------------------*/
   /*> rc = CODE__defense (a_nscrp, a_main, a_head, a_code, a_wave, a_runtype, a_last, a_verb, a_desc, a_method, a_args, a_test, a_expect, a_return, a_stage, a_which, a_major, a_minor, b_share, b_select);   <* 
    *> UDEBUG_KOIOS   ylog_uvalue  ("defense"   , rc);                                                                                                                                                           <* 
    *> if (rc < 0) {                                                                                                                                                                                           <* 
    *>    UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rc);                                                                                                                                                        <* 
    *>    return rc;                                                                                                                                                                                           <* 
    *> }                                                                                                                                                                                                       <*/
   /*---(statistics)---------------------*/
   yUNIT_stats_step  (YUNIT_BUILD  , NULL, "", YUNIT_IS_VOID, a_verb, a_desc, a_dittoing, a_ditto, a_major, *b_share, &s_cunit, &s_cscrp, &s_ccond, &s_cstep);
   /*---(prepare)------------------------*/
   CODE__step_add  (a_code, a_runtype, a_verb, a_desc, a_dittoing, a_nline, a_dline);
   /*---(create)-------------------------*/
   CODE__select_beg (a_code, a_verb, a_which, *b_share, x_pre);
   CONV_printf     (a_code, "%s      yUNIT_mode    (%4i, %3i, \"%s\", \"%s\", cyUNIT.exec, '%c', '%c');\n", x_pre, CODE__line (a_dittoing, a_nline, a_dline), s_cstep, a_desc, a_method, a_dittoing, *b_share);
   CODE__select_end (a_code, a_verb, a_which, *b_share);
   /*---(complete)-----------------------*/
   UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
   return 0;
}

char
CODE__code              (char a_nscrp [LEN_TITLE], FILE *a_main, FILE *a_head, FILE *a_code, FILE *a_wave, char a_runtype, char a_last [LEN_LABEL], int a_nline, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_dittoing, char a_dtarget, int a_dline, char a_major, char a_minor, char *b_share, char *b_select)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rc          =    0;
   char        x_pre       [LEN_TERSE] = "";
   char        x_display   [LEN_RECD]  = "";
   char        x_system    [LEN_RECD]  = "";
   /*---(header)-------------------------*/
   UDEBUG_KOIOS   ylog_uenter  (__FUNCTION__);
   /*---(defense)------------------------*/
   /*> rc = CODE__defense (a_nscrp, a_main, a_head, a_code, a_wave, a_runtype, a_last, a_verb, a_desc, a_method, a_args, a_test, a_expect, a_return, a_stage, a_which, a_major, a_minor, b_share, b_select);   <* 
    *> UDEBUG_KOIOS   ylog_uvalue  ("defense"   , rc);                                                                                                                                                           <* 
    *> if (rc < 0) {                                                                                                                                                                                           <* 
    *>    UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rc);                                                                                                                                                        <* 
    *>    return rc;                                                                                                                                                                                           <* 
    *> }                                                                                                                                                                                                       <*/
   /*---(statistics)---------------------*/
   yUNIT_stats_step  (YUNIT_BUILD  , NULL, "", YUNIT_IS_VOID, a_verb, a_desc, a_dittoing, a_ditto, a_major, *b_share, &s_cunit, &s_cscrp, &s_ccond, &s_cstep);
   /*---(prepare)------------------------*/
   CODE__step_add   (a_code, a_runtype, a_verb, a_desc, a_dittoing, a_nline, a_dline);
   CODE__display    (a_expect, x_display, x_system, NULL);
   /*---(create)-------------------------*/
   CODE__select_beg (a_code, a_verb, a_which, *b_share, x_pre);
   CONV_printf      (a_code, "%s      yUNIT_code    (%4i, %3i, \"%s\", \"%s\", cyUNIT.exec, '%c', '%c');\n", x_pre, CODE__line (a_dittoing, a_nline, a_dline), s_cstep, a_desc, x_display, a_dittoing, *b_share);
   CONV_printf      (a_code, "%s      if (cyUNIT.exec) { %s }\n", x_pre, x_system);
   CODE__select_end (a_code, a_verb, a_which, *b_share);
   /*---(complete)-----------------------*/
   UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
   return 0;
}

char
CODE__gvar              (char a_nscrp [LEN_TITLE], FILE *a_main, FILE *a_head, FILE *a_code, FILE *a_wave, char a_runtype, char a_last [LEN_LABEL], int a_nline, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_dittoing, char a_dtarget, int a_dline, char a_major, char a_minor, char *b_share, char *b_select)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rc          =    0;
   char        x_display   [LEN_RECD]  = "";
   char        x_system    [LEN_RECD]  = "";
   int         l           =    0;
   /*---(header)-------------------------*/
   UDEBUG_KOIOS   ylog_uenter  (__FUNCTION__);
   /*---(defense)------------------------*/
   /*> rc = CODE__defense (a_nscrp, a_main, a_head, a_code, a_wave, a_runtype, a_last, a_verb, a_desc, a_method, a_args, a_test, a_expect, a_return, a_stage, a_which, a_major, a_minor, b_share, b_select);   <* 
    *> UDEBUG_KOIOS   ylog_uvalue  ("defense"   , rc);                                                                                                                                                           <* 
    *> if (rc < 0) {                                                                                                                                                                                           <* 
    *>    UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rc);                                                                                                                                                        <* 
    *>    return rc;                                                                                                                                                                                           <* 
    *> }                                                                                                                                                                                                       <*/
   /*---(statistics)---------------------*/
   /*> yUNIT_stats_step  (YUNIT_BUILD  , NULL, "", YUNIT_IS_VARS, a_verb, a_desc, a_dittoing, a_ditto, a_major, *b_share, &s_cunit, &s_cscrp, &s_ccond, &s_cstep);   <*/
   /*---(prepare)------------------------*/
   CODE__step_add  (a_code, a_runtype, a_verb, a_desc, a_dittoing, a_nline, a_dline);
   CODE__display   (a_expect, x_display, x_system, NULL);
   /*---(create)-------------------------*/
   l = strlen (x_system);
   if (l < 48)  CONV_printf     (a_code, "%-48.48s  /* %4i, %-32.32s */\n", x_system, CODE__line (a_dittoing, a_nline, a_dline), a_desc);
   else         CONV_printf     (a_code, "%s  /* %4i, %-32.32s */\n"      , x_system, CODE__line (a_dittoing, a_nline, a_dline), a_desc);
   /*---(complete)-----------------------*/
   UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
   return 0;
}

char
CODE__lvar              (char a_nscrp [LEN_TITLE], FILE *a_main, FILE *a_head, FILE *a_code, FILE *a_wave, char a_runtype, char a_last [LEN_LABEL], int a_nline, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_dittoing, char a_dtarget, int a_dline, char a_major, char a_minor, char *b_share, char *b_select)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rc          =    0;
   char        x_pre       [LEN_TERSE] = "";
   char        x_display   [LEN_RECD]  = "";
   char        x_system    [LEN_RECD]  = "";
   int         l           =    0;
   /*---(header)-------------------------*/
   UDEBUG_KOIOS   ylog_uenter  (__FUNCTION__);
   /*---(defense)------------------------*/
   /*> rc = CODE__defense (a_nscrp, a_main, a_head, a_code, a_wave, a_runtype, a_last, a_verb, a_desc, a_method, a_args, a_test, a_expect, a_return, a_stage, a_which, a_major, a_minor, b_share, b_select);   <* 
    *> UDEBUG_KOIOS   ylog_uvalue  ("defense"   , rc);                                                                                                                                                           <* 
    *> if (rc < 0) {                                                                                                                                                                                           <* 
    *>    UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rc);                                                                                                                                                        <* 
    *>    return rc;                                                                                                                                                                                           <* 
    *> }                                                                                                                                                                                                       <*/
   /*---(statistics)---------------------*/
   yUNIT_stats_step  (YUNIT_BUILD  , NULL, "", YUNIT_IS_VARS, a_verb, a_desc, a_dittoing, a_ditto, a_major, *b_share, &s_cunit, &s_cscrp, &s_ccond, &s_cstep);
   /*---(prepare)------------------------*/
   CODE__step_add  (a_code, a_runtype, a_verb, a_desc, a_dittoing, a_nline, a_dline);
   CODE__display   (a_expect, x_display, x_system, NULL);
   /*---(create)-------------------------*/
   CONV_printf     (a_code, "   ++mykoios_nstep;\n");
   CONV_printf     (a_code, "   yUNIT_local   (%4i, %3i, \"%s\", \"%s\", cyUNIT.exec, '%c', '%c');\n", CODE__line (a_dittoing, a_nline, a_dline), s_cstep, a_desc, x_display, a_dittoing, *b_share);
   l = strlen (x_system);
   if (l < 48)  CONV_printf     (a_code, "   %-48.48s  /* %4i, %-32.32s */\n", x_system, CODE__line (a_dittoing, a_nline, a_dline), a_desc);
   else         CONV_printf     (a_code, "   %s  /* %4i, %-32.32s */\n"      , x_system, CODE__line (a_dittoing, a_nline, a_dline), a_desc);
   /*---(complete)-----------------------*/
   UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
   return 0;
}

char
CODE__system            (char a_nscrp [LEN_TITLE], FILE *a_main, FILE *a_head, FILE *a_code, FILE *a_wave, char a_runtype, char a_last [LEN_LABEL], int a_nline, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_dittoing, char a_dtarget, int a_dline, char a_major, char a_minor, char *b_share, char *b_select)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rc          =    0;
   char        x_pre       [LEN_TERSE] = "";
   char        x_display   [LEN_RECD]  = "";
   char        x_system    [LEN_RECD]  = "";
   char        x_type      =  '-';
   /*---(header)-------------------------*/
   UDEBUG_KOIOS   ylog_uenter  (__FUNCTION__);
   /*---(statistics)---------------------*/
   if (strcmp (a_verb, "system") == 0)  x_type = YUNIT_IS_EXEC;
   else                                 x_type = YUNIT_IS_VOID;
   yUNIT_stats_step  (YUNIT_BUILD  , NULL, "", x_type, a_verb, a_desc, a_dittoing, a_ditto, a_major, *b_share, &s_cunit, &s_cscrp, &s_ccond, &s_cstep);
   /*---(prepare)------------------------*/
   CODE__step_add  (a_code, a_runtype, a_verb, a_desc, a_dittoing, a_nline, a_dline);
   CODE__display   (a_expect, x_display, x_system, NULL);
   /*---(create)-------------------------*/
   CODE__select_beg (a_code, a_verb, a_which, *b_share, x_pre);
   CONV_printf     (a_code, "%s      yUNIT_system  (%4i, %3i, \"%s\", \"%s\", \"%s\", cyUNIT.exec, '%c', '%c');\n", x_pre, CODE__line (a_dittoing, a_nline, a_dline), s_cstep, a_desc, x_display, x_system, a_dittoing, *b_share);
   CODE__select_end (a_code, a_verb, a_which, *b_share);
   /*---(complete)-----------------------*/
   UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
   return 0;
}



/*====================------------------------------------====================*/
/*===----                          main driver                         ----===*/
/*====================------------------------------------====================*/
static void  o___DRIVER__________o () { return; }

char
CODE_driver             (void f_call (), char a_nscrp [LEN_TITLE], FILE *a_main, FILE *a_head, FILE *a_code, FILE *a_wave, char a_runtype, char a_last [LEN_LABEL], int a_nline, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_dittoing, char a_dtarget, int a_dline, char a_major, char a_minor, char *b_share, char *b_select)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char      (*x_func) (char a_nscrp [LEN_TITLE], FILE *a_main, FILE *a_head, FILE *a_code, FILE *a_wave, char a_runtype, char a_last [LEN_LABEL], int a_nline, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_dittoing, char a_dtarget, int a_dline, char a_major, char a_minor, char *b_share, char *b_select);
   /*---(header)-------------------------*/
   UDEBUG_KOIOS   ylog_uenter  (__FUNCTION__);
   /*---(defense)------------------------*/
   rc = CODE__defense (a_nscrp, a_main, a_head, a_code, a_wave, a_runtype, a_last, a_verb, a_desc, a_method, a_args, a_test, a_expect, a_return, a_stage, a_which, a_major, a_minor, b_share, b_select);
   UDEBUG_KOIOS   ylog_uvalue  ("defense"   , rc);
   if (rc < 0) {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rc);
      return rc;
   }
   /*---(prepare)------------------------*/
   UDEBUG_KOIOS   ylog_upoint  ("f_call"    , f_call);
   if (f_call == NULL) {
      UDEBUG_KOIOS   ylog_unote   ("nothing to do");
      UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
      return 0;
   }
   x_func = f_call;
   /*---(call function)------------------*/
   rc = x_func (a_nscrp, a_main, a_head, a_code, a_wave, a_runtype, a_last, a_nline, a_verb, a_desc, a_method, a_args, a_test, a_expect, a_return, a_stage, a_which, a_ditto, a_dittoing, a_dtarget, a_dline, a_major, a_minor, b_share, b_select);
   UDEBUG_KOIOS   ylog_uvalue  ("call"      , rc);
   --rce;  if (rc < 0) {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(complete)-----------------------*/
   UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
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
   s_cscrp = a_scrps;
   s_ccond = a_conds;
   return 0;
}



/*===============================[[ end code ]]===============================*/
