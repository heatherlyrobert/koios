/*===============================[[ beg-code ]]===============================*/
#include    "koios.h"        /* LOCAL  : main header                          */



#include    <yLOG_uver.h>
#include    <ySTR_uver.h>
#include    <yENV_uver.h>
#include    <yEXEC_uver.h>



tGLOBALS    my;
tLOC        my_loc;
tCUR        my_cur;
tRUN        my_run;


char    g_print     [LEN_RECD] = "";


/*====================------------------------------------====================*/
/*===----                        identity functions                    ----===*/
/*====================------------------------------------====================*/
static void  o___IDENTITY________o () { return; }


char*      /* ---- : return library versioning information -------------------*/
PROG_version       (void)
{
   char    t [20] = "";
#if    __TINYC__ > 0
   strncpy (t, "[tcc built  ]", 15);
#elif  __GNUC__  > 0
   strncpy (t, "[gnu gcc    ]", 15);
#elif  __CBANG__  > 0
   strncpy (t, "[cbang      ]", 15);
#else
   strncpy (t, "[unknown    ]", 15);
#endif
   snprintf (my.version, LEN_FULL, "%s   %s : %s", t, P_VERNUM, P_VERTXT);
   return my.version;
}



/*====================------------------------------------====================*/
/*===----                       pre-initialization                     ----===*/
/*====================------------------------------------====================*/
static void      o___PREINIT_________________o (void) {;}

char       /*----: very first setup ------------------s-----------------------*/
PROG__header            (void)
{
   /*---(header)----------------------*/
   UDEBUG_KOIOS   ylog_uenter   (__FUNCTION__);
   /*---(versioning)------------------*/
   UDEBUG_KOIOS   ylog_uinfo    ("koios"   , PROG_version      ());
   UDEBUG_KOIOS   ylog_uinfo    ("purpose" , P_PURPOSE);
   UDEBUG_KOIOS   ylog_uinfo    ("namesake", P_NAMESAKE);
   UDEBUG_KOIOS   ylog_uinfo    ("heritage", P_HERITAGE);
   UDEBUG_KOIOS   ylog_uinfo    ("imagery" , P_IMAGERY);
   UDEBUG_KOIOS   ylog_unote    ("custom core");
   UDEBUG_KOIOS   ylog_uinfo    ("yUNIT"   , yUNIT_version     ());
   /*---(complete)-----------------------*/
   UDEBUG_KOIOS   ylog_uexit (__FUNCTION__);
   return 0;
}

char
PROG_urgents            (int a_argc, char *a_argv [])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   /*---(start logger)-------------------*/
   my.debug = '-';
   /*> printf ("program   %s\n", a_argv [0]);                                         <*/
   if (strcmp (a_argv [0], "koios_debug") == 0) {
      /*> printf ("handle debug...\n");                                               <*/
      rc = ylog_uopen  ();
      rc = yerr_uopen  ();
      my.debug = 'y';
      yUNIT_debugging ();
      yenv_udebugging ();
   } else if (strcmp (a_argv [0], "koios_unit") == 0) {
      /*> printf ("handle unit...\n");                                                <*/
      rc = ylog_uopen  ();
      rc = yerr_uopen  ();
      my.debug = '-';
   } else {
      /*> printf ("handle normal...\n");                                              <*/
      yerr_ustderr ();
   }
   /*---(process urgents)----------------*/
   rc = PROG__header ();
   UDEBUG_KOIOS   ylog_uvalue   ("header"    , rc);
   --rce;  if (rc < 0) {
      UDEBUG_KOIOS   ylog_uexitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(complete)-----------------------*/
   return rc;
}



/*====================------------------------------------====================*/
/*===----                        startup functions                     ----===*/
/*====================------------------------------------====================*/
static void  o___STARTUP_________o () { return; }

char         /*--> shutdown program ----------------------[ ------ [ ------ ]-*/
PROG__init              (void)
{
   /*---(header)-------------------------*/
   UDEBUG_KOIOS   ylog_uenter  (__FUNCTION__);
   /*---(incomming file)-----------------*/
   strlcpy  (my_loc.l_dir , "", LEN_TITLE);
   strlcpy  (my_loc.l_file, "", LEN_TITLE);
   strlcpy  (my_loc.l_full, "", LEN_TITLE);
   strlcpy  (my_loc.l_proj, "", LEN_TITLE);
   strlcpy  (my_loc.l_extn, "", LEN_TITLE);
   strlcpy  (my_loc.l_base, "", LEN_TITLE);
   my_loc.l_quality = '-';
   strlcpy  (my.util      , "", LEN_LABEL);
   /*---(outgoing files)-----------------*/
   strlcpy  (my_loc.l_scrp, "", LEN_TITLE);  my_loc.l_SCRP = NULL;
   strlcpy  (my_loc.l_main, "", LEN_TITLE);  my_loc.l_MAIN = NULL;
   strlcpy  (my_loc.l_head, "", LEN_TITLE);  my_loc.l_HEAD = NULL;
   strlcpy  (my_loc.l_code, "", LEN_TITLE);  my_loc.l_CODE = NULL;
   strlcpy  (my_loc.l_wave, "", LEN_TITLE);  my_loc.l_WAVE = NULL;
   strlcpy  (my_loc.l_conv, "", LEN_TITLE);  my_loc.l_CONV = NULL;
   strlcpy  (my_run.r_last, "", LEN_LABEL);
   /*---(globals)------------------------*/
   my.run_type    = '-';
   my.replace     = '-';
   my.noise       = '-';
   my_run.r_under = '-';
   getcwd (my.cwd, LEN_PATH);
   /*---(initialization)-----------------*/
   VERB_init  ();
   DITTO_init ();
   REUSE_init ();
   CODE_init  ();
   CONV_init  ();
   /*---(complete)-----------------------*/
   UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
   return 0;
}

char
PROG__args              (int a_argc, char *a_argv [])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        x_name      [LEN_FULL]  = "";
   int         i           =    0;
   char       *a           = NULL;
   int         x_total     =    0;
   int         x_args      =    0;
   int         l           =    0;
   /*---(begin)--------------------------*/
   UDEBUG_KOIOS  ylog_uenter  (__FUNCTION__);
   /*---(defenses)-----------------------*/
   UDEBUG_KOIOS  ylog_upoint  ("a_argv" , a_argv);
   --rce;  if (a_argv == NULL) {
      UDEBUG_KOIOS    ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(process)------------------------*/
   --rce;  for (i = 1; i < a_argc; ++i) {
      a = a_argv[i];
      ++x_total;
      if (a[0] == '@')  continue;
      UDEBUG_KOIOS  ylog_uinfo   ("cli arg", a);
      ++x_args;
      /*---(better testing)--------------*/
      if      (strncmp (a, "--verify"     , 10) == 0)  { my.run_type = G_RUN_UPDATE;  my.noise = '-'; }
      else if (strncmp (a, "--cverify"    , 10) == 0)  { my.run_type = G_RUN_UPDATE;  my.noise = 'c'; }
      else if (strncmp (a, "--everify"    , 10) == 0)  { my.run_type = G_RUN_UPDATE;  my.noise = 'e'; }
      else if (strncmp (a, "--Everify"    , 10) == 0)  { my.run_type = G_RUN_UPDATE;  my.noise = 'E'; }
      else if (strncmp (a, "--vverify"    , 10) == 0)  { my.run_type = G_RUN_UPDATE;  my.noise = 'v'; }
      /*---(better conversion)-----------*/
      else if (strncmp (a, "--conv"       , 10) == 0)  { my.run_type = G_RUN_UPDATE;  my.replace = G_AND_REPLACE;  my.noise = '-'; }
      else if (strncmp (a, "--cconv"      , 10) == 0)  { my.run_type = G_RUN_UPDATE;  my.replace = G_AND_REPLACE;  my.noise = 'c'; }
      else if (strncmp (a, "--econv"      , 10) == 0)  { my.run_type = G_RUN_UPDATE;  my.replace = G_AND_REPLACE;  my.noise = 'e'; }
      else if (strncmp (a, "--Econv"      , 10) == 0)  { my.run_type = G_RUN_UPDATE;  my.replace = G_AND_REPLACE;  my.noise = 'E'; }
      else if (strncmp (a, "--vconv"      , 10) == 0)  { my.run_type = G_RUN_UPDATE;  my.replace = G_AND_REPLACE;  my.noise = 'v'; }
      /*---(better code/create)----------*/
      else if (strncmp (a, "--code"       , 10) == 0)  { my.run_type = G_RUN_CREATE;  my.noise = '-'; }
      else if (strncmp (a, "--ccode"      , 10) == 0)  { my.run_type = G_RUN_CREATE;  my.noise = 'c'; }
      else if (strncmp (a, "--ecode"      , 10) == 0)  { my.run_type = G_RUN_CREATE;  my.noise = 'e'; }
      else if (strncmp (a, "--Ecode"      , 10) == 0)  { my.run_type = G_RUN_CREATE;  my.noise = 'E'; }
      else if (strncmp (a, "--vcode"      , 10) == 0)  { my.run_type = G_RUN_CREATE;  my.noise = 'v'; }
      /*---(better code/debug)-----------*/
      else if (strncmp (a, "--debug"      , 10) == 0)  { my.run_type = G_RUN_DEBUG;   my.noise = '-'; }
      else if (strncmp (a, "--cdebug"     , 10) == 0)  { my.run_type = G_RUN_DEBUG;   my.noise = 'c'; }
      else if (strncmp (a, "--edebug"     , 10) == 0)  { my.run_type = G_RUN_DEBUG;   my.noise = 'e'; }
      else if (strncmp (a, "--Edebug"     , 10) == 0)  { my.run_type = G_RUN_DEBUG;   my.noise = 'E'; }
      else if (strncmp (a, "--vdebug"     , 10) == 0)  { my.run_type = G_RUN_DEBUG;   my.noise = 'v'; }
      /*---(utility unit tests)----------*/
      else if (strncmp (a, "--util="      ,  7) == 0)  { strlcpy (my.util, a + 7, LEN_LABEL); }
      /*---(old args)--------------------*/
      /*> else if (strncmp (a, "--create"     , 10) == 0)    my.run_type = G_RUN_CREATE;   <*/
      /*> else if (strncmp (a, "--compile"    , 10) == 0)    my.run_type = G_RUN_CREATE;   <*/
      /*> else if (strncmp (a, "--debug"      , 10) == 0)    my.run_type = G_RUN_DEBUG;   <*/
      /*> else if (strncmp (a, "--validate"   , 10) == 0)    my.run_type = G_RUN_UPDATE;   <*/
      /*> else if (strncmp (a, "--convert"    , 10) == 0)    my.run_type = G_RUN_UPDATE;   <*/
      /*> else if (strncmp (a, "--update"     , 10) == 0)  { my.run_type = G_RUN_UPDATE;  my.replace = G_AND_REPLACE; }   <*/
      /*---(unknown arg)-----------------*/
      else if (strncmp (a, "-"            ,  1) == 0)  {
         yerr_uerror ("argument ¶%s¶ is not recognized", a);
         UDEBUG_KOIOS  ylog_uexitr (__FUNCTION__, rce);
         return rce;
      }
      /*---(file name)-------------------*/
      else {
         /*---(fix extension)------------*/
         if (strstr (a, ".unit") == NULL)  sprintf (x_name, "%s.unit", a);
         else                              strcpy  (x_name, a);
         UDEBUG_KOIOS  ylog_uinfo  ("x_name"    , x_name);
         rc = yenv_uname    (my.cwd, x_name, NULL, my_loc.l_full);
         UDEBUG_KOIOS  ylog_uvalue ("name"      , rc);
         if (rc < 0) {
            UDEBUG_KOIOS  ylog_uexitr (__FUNCTION__, rce);
            return rce;
         }
         /*---(get directory details)----*/
         UDEBUG_KOIOS  ylog_uinfo  ("l_full"    , my_loc.l_full);
         rc = yenv_udetail (my_loc.l_full, NULL, my_loc.l_dir, my_loc.l_file, my_loc.l_proj, my_loc.l_base, my_loc.l_extn, NULL, &(my_loc.l_quality));
         UDEBUG_KOIOS  ylog_uvalue ("detail"    , rc);
         if (rc < 0) {
            UDEBUG_KOIOS  ylog_uexitr (__FUNCTION__, rce);
            return rce;
         }
         /*---(check extension)----------*/
         UDEBUG_KOIOS  ylog_uinfo  ("l_extn"    , my_loc.l_extn);
         if (strcmp (my_loc.l_extn, ".unit") != 0) {
            UDEBUG_KOIOS  ylog_unote  ("can only be used on .unit files");
            UDEBUG_KOIOS  ylog_uexitr (__FUNCTION__, rce);
            return rce;
         }
         /*---(check for normal)---------*/
         UDEBUG_KOIOS  ylog_uinfo  ("l_proj"    , my_loc.l_proj);
         l = strlen (my_loc.l_proj);
         UDEBUG_KOIOS  ylog_uvalue ("l"         , l);
         UDEBUG_KOIOS  ylog_uinfo  ("l_base"    , my_loc.l_base);
         if (strncmp (my_loc.l_base, my_loc.l_proj, l) == 0) {
            UDEBUG_KOIOS  ylog_unote  ("prefix matches project name, good to go");
         }
         /*---(check for utility)--------*/
         else if (strcmp (my.util, "") != 0) {
            l = strlen (my.util);
            UDEBUG_KOIOS  ylog_uinfo  ("l"         , l);
            if (strncmp (my_loc.l_base, my.util      , l) == 0) {
               UDEBUG_KOIOS  ylog_unote  ("prefix matches utility name, good to go");
            }
         }
         /*---(check for shares)---------*/
         else if (strcmp (my_loc.l_base, "unit_head"     ) == 0  ||
               strcmp  (my_loc.l_base, "unit_wide"     ) == 0  ||
               strcmp  (my_loc.l_base, "unit_data"     ) == 0) {
            UDEBUG_KOIOS  ylog_unote  ("name matches a share -- unit_head, unit_wide, or unit_data, good to go");
         }
         /*---(handle trouble)-----------*/
         else {
            UDEBUG_KOIOS  ylog_unote  ("all units must start with proj/util or be unit_head, unit_wide, or unit_data");
            UDEBUG_KOIOS  ylog_uexitr (__FUNCTION__, rce);
            return rce;
         }
      }
      /*---(done)------------------------*/
   }
   /*---(check zero entries)-------------*/
   UDEBUG_KOIOS  ylog_uvalue ("entries"   , x_total);
   UDEBUG_KOIOS  ylog_uvalue ("arguments" , x_args);
   if (x_args == 0) {
      UDEBUG_KOIOS  ylog_unote  ("no arguments identified");
   }
   /*---(name feedback)------------------*/
   UDEBUG_KOIOS  ylog_uchar  ("run_type"  , my.run_type);
   --rce;  if (my.run_type == '-') {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(name feedback)------------------*/
   UDEBUG_KOIOS  ylog_uinfo  ("l_dir"     , my_loc.l_dir);
   UDEBUG_KOIOS  ylog_uinfo  ("l_file"    , my_loc.l_file);
   UDEBUG_KOIOS  ylog_uinfo  ("l_full"    , my_loc.l_full);
   UDEBUG_KOIOS  ylog_uinfo  ("l_proj"    , my_loc.l_proj);
   UDEBUG_KOIOS  ylog_uinfo  ("l_base"    , my_loc.l_base);
   UDEBUG_KOIOS  ylog_uinfo  ("l_extn"    , my_loc.l_extn);
   UDEBUG_KOIOS  ylog_uchar  ("l_quality" , my_loc.l_quality);
   /*---(defense)------------------------*/
   UDEBUG_KOIOS   ylog_uinfo   ("basename"  , my_loc.l_base);
   --rce;  if (strcmp (my_loc.l_base, "") == 0) {
      yerr_uerror ("script name/base was not provided on command line");
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(defense)------------------------*/
   --rce;  if (strcmp (my_loc.l_extn, ".sunit") == 0) {
      if (my.run_type != G_RUN_UPDATE) {
         yerr_uerror ("can not compile ¶%s¶ as .sunit, must compile in linked .unit location", my_loc.l_base);
         UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
         return rce;
      }
   }
   /*---(set noise)----------------------*/
   if (my.noise != '-')   yerr_uopen ();
   /*---(complete)-----------------------*/
   UDEBUG_KOIOS  ylog_uexit (__FUNCTION__);
   return 0;
}

char
PROG__begin             (void)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   /*---(header)-------------------------*/
   UDEBUG_KOIOS   ylog_uenter  (__FUNCTION__);
   /*---(create names)-------------------*/
   snprintf (my_loc.l_scrp, LEN_TITLE, "%s%s"            , my_loc.l_base, my_loc.l_extn);
   snprintf (my_loc.l_main, LEN_TITLE, "%s_unit.tmp"     , my_loc.l_base);
   snprintf (my_loc.l_code, LEN_TITLE, "%s_unit.cs"      , my_loc.l_base);
   snprintf (my_loc.l_wave, LEN_TITLE, "%s.wave"         , my_loc.l_base);
   snprintf (my_loc.l_conv, LEN_TITLE, "%s%s.new"        , my_loc.l_base, my_loc.l_extn);
   /*---(special for debug)--------------*/
   if (my.run_type == G_RUN_DEBUG)   snprintf (my_loc.l_code, LEN_TITLE, "%s_unit.c"      , my_loc.l_base);
   /*---(special for unit_head)----------*/
   IF_SHARED {
      snprintf (my_loc.l_main, LEN_TITLE, "%s.tmp"       , my_loc.l_base);
      if (strcmp (my_loc.l_base, "unit_head") != 0)  snprintf (my_loc.l_head, LEN_TITLE, "%s.h"         , my_loc.l_base);
      snprintf (my_loc.l_code, LEN_TITLE, "%s.cs"        , my_loc.l_base);
   }
   /*---(initialize)---------------------*/
   my_run.r_nline    = 0;
   my_run.r_nrecd    = 0;
   my_run.r_dittoing = '-';
   my_run.r_dtarget  = '-';
   my_run.r_dstart   = -1;
   /*---(complete)-----------------------*/
   UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
   return 0;
}

char
PROG_startup            (int a_argc, char *a_argv [])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   /*---(header)----------------------*/
   UDEBUG_KOIOS  ylog_uenter  (__FUNCTION__);
   /*---(initialize)---------------------*/
   rc = PROG__init   ();
   UDEBUG_KOIOS   ylog_uvalue   ("init"      , rc);
   --rce;  if (rc < 0) {
      UDEBUG_KOIOS   ylog_uexitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(arguments)----------------------*/
   rc = PROG__args   (a_argc, a_argv);
   UDEBUG_KOIOS   ylog_uvalue   ("args"      , rc);
   --rce;  if (rc < 0) {
      UDEBUG_KOIOS   ylog_uexitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(begin)--------------------------*/
   rc = PROG__begin  ();
   UDEBUG_KOIOS   ylog_uvalue   ("begin"     , rc);
   --rce;  if (rc < 0) {
      UDEBUG_KOIOS   ylog_uexitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(complete)-----------------------*/
   UDEBUG_KOIOS  ylog_uexit (__FUNCTION__);
   return rc;
}



/*====================------------------------------------====================*/
/*===----                        program execution                     ----===*/
/*====================------------------------------------====================*/
static void      o___EXECUTION_______________o (void) {;}

char
PROG_dawn                (char a_runtype, char a_nscrp [LEN_TITLE], FILE **r_scrp, int *r_line, char a_nmain [LEN_TITLE], FILE **r_main, char a_nhead [LEN_TITLE], FILE **r_head, char a_ncode [LEN_TITLE], FILE **r_code, char a_nwave [LEN_TITLE], FILE **r_wave, char a_nconv [LEN_TITLE], FILE **r_conv, char *r_share, char *r_select)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        x_ftype     =  '-';
   /*---(header)-------------------------*/
   UDEBUG_KOIOS   ylog_uenter  (__FUNCTION__);
   /*---(open incomming script)----------*/
   if (r_line != NULL)  *r_line = 0;
   rc = yenv_uopen_detail (__FILE__, __FUNCTION__, __LINE__, a_nscrp, 'r', r_scrp);
   UDEBUG_KOIOS   ylog_uvalue  ("script"    , rc);
   --rce;  if (rc < 0) {
      PROG_shutdown ();
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(open output files)--------------*/
   --rce;  switch (a_runtype) {
   case G_RUN_CREATE : case G_RUN_DEBUG :
      rc = CODE_header (a_nscrp, a_nmain, r_main, a_nhead, r_head, a_ncode, r_code, a_nwave, r_wave, r_share, r_select);
      break;
   case G_RUN_UPDATE :
      rc = CONV_header  (a_nconv, r_conv, r_share, r_select);
      break;
   default  :
      yenv_uclose_detail (__FILE__, __FUNCTION__, __LINE__, a_nscrp, r_scrp);
      PROG_shutdown ();
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
      break;
   }
   UDEBUG_KOIOS   ylog_uvalue  ("output"    , rc);
   --rce;  if (rc <  0) {
      yenv_uclose_detail (__FILE__, __FUNCTION__, __LINE__, a_nscrp, r_scrp);
      PROG_shutdown ();
      return rc;
   }
   /*---(open output files)--------------*/
   UDEBUG_KOIOS   ylog_unote   ("importing globals");
   rc = yUNIT_reuse_purge  ('*');
   UDEBUG_KOIOS   ylog_uvalue  ("purge"     , rc);
   UDEBUG_KOIOS   ylog_uinfo   ("used"      , yUNIT_reuse_used ());
   UDEBUG_KOIOS   ylog_uchar   ("exists"    , yenv_uexists (KOIOS_GLOBALS));
   if (yenv_uexists (KOIOS_GLOBALS) == 'r') {
      rc = yUNIT_reuse_import (KOIOS_GLOBALS);
      UDEBUG_KOIOS   ylog_uvalue  ("import"    , rc);
      UDEBUG_KOIOS   ylog_uinfo   ("used"      , yUNIT_reuse_used ());
      x_ftype = yUNIT_reuse_ftype (a_nscrp, NULL);
      UDEBUG_KOIOS   ylog_uchar   ("x_ftype"   , x_ftype);
      rc = yUNIT_reuse_purge  (x_ftype);
      UDEBUG_KOIOS   ylog_uvalue  ("purge"     , rc);
      UDEBUG_KOIOS   ylog_uinfo   ("used"      , yUNIT_reuse_used ());
   }
   /*---(complete)-----------------------*/
   UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
   return 0;
}

char
PROG_terminate           (FILE **r_scrp, FILE **r_main, FILE **r_code, FILE **r_wave, FILE **r_conv)
{
   UDEBUG_KOIOS   ylog_uenter  (__FUNCTION__);
   yenv_uclose_detail (__FILE__, __FUNCTION__, __LINE__, "???", r_scrp);
   yenv_uclose_detail (__FILE__, __FUNCTION__, __LINE__, "???", r_main);
   yenv_uclose_detail (__FILE__, __FUNCTION__, __LINE__, "???", r_code);
   yenv_uclose_detail (__FILE__, __FUNCTION__, __LINE__, "???", r_wave);
   UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
   PROG_shutdown ();
   return 0;
}

char
PROG__defaults           (void)
{
   /*---(read in)------------------------*/
   strcpy (my_cur.c_recd  , "");
   strcpy (my_cur.c_verb  , "");
   my_cur.c_conv   = NULL;
   my_cur.c_code   = NULL;
   my_cur.c_spec   = '-';
   my_cur.c_vers   =  -1;
   strcpy (my_cur.c_desc  , "");
   strcpy (my_cur.c_method, "");
   strcpy (my_cur.c_args  , "");
   strcpy (my_cur.c_test  , "");
   strcpy (my_cur.c_expect, "");
   strcpy (my_cur.c_return, "");
   /*---(parsed out)---------------------*/
   strcpy (my_cur.c_stage , "");
   my_cur.c_ditto  = '-';
   my_cur.c_major  = '-';
   my_cur.c_minor  = '-';
   strcpy (my_cur.c_which , "");
   /*---(working)------------------------*/
   strcpy (my_cur.c_disp  , "");
   strcpy (my_cur.c_syst  , "");
   strcpy (my_cur.c_load  , "");
   /*---(done)---------------------------*/
   return 0;
}

char
PROG__save_back          (char a_recd [LEN_RECD], char a_verb [LEN_LABEL], void *a_conv, void *a_code, char a_spec, char a_vers, char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_LABEL], char a_ditto, char a_major, char a_minor, char a_which [LEN_TITLE])
{
   /*---(read in)------------------------*/
   strlcpy (my_cur.c_recd  , a_recd    , LEN_RECD);
   strlcpy (my_cur.c_verb  , a_verb    , LEN_LABEL);
   my_cur.c_conv   = a_conv;
   my_cur.c_code   = a_code;
   my_cur.c_spec   = a_spec;
   my_cur.c_vers   = a_vers;
   strlcpy (my_cur.c_desc  , a_desc    , LEN_LONG);
   strlcpy (my_cur.c_method, a_method  , LEN_HUND);
   strlcpy (my_cur.c_args  , a_args    , LEN_FULL);
   strlcpy (my_cur.c_test  , a_test    , LEN_LABEL);
   strlcpy (my_cur.c_expect, a_expect  , LEN_RECD);
   strlcpy (my_cur.c_return, a_return  , LEN_FULL);
   /*---(parsed out)---------------------*/
   strlcpy (my_cur.c_stage , a_stage   , LEN_LABEL);
   my_cur.c_ditto  = a_ditto;
   my_cur.c_major  = a_major;
   my_cur.c_minor  = a_minor;
   strlcpy (my_cur.c_which , a_which   , LEN_TITLE);
   /*---(done)---------------------------*/
   return 0;
}

char
PROG_driver              (char a_good, char a_runtype, char a_nscrp [LEN_TITLE], int *r_nline, FILE **b_scrp, FILE *a_main, FILE *a_head, FILE *a_code, FILE *a_wave, FILE *a_conv, char b_last [LEN_LABEL], int *r_nrecd, char *r_under, char *r_ditto, char *r_dittoing, char *r_dtarget, int *r_dstart, int *r_dline, char *r_major, char *r_minor, char *r_share, char *r_select)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        x_recd      [LEN_RECD]  = "";
   char        x_verb      [LEN_LABEL] = "";
   char      (*p_conv) (void);
   char      (*p_code) (void);
   char        x_spec      =  '-';
   char        x_vers      =    0;
   char        x_desc      [LEN_LONG]  = "";
   char        x_meth      [LEN_HUND]  = "";
   char        x_args      [LEN_FULL]  = "";
   char        x_test      [LEN_LABEL] = "";
   char        x_expe      [LEN_RECD]  = "";
   char        x_retn      [LEN_FULL]  = "";
   char        x_stage     [LEN_SHORT] = "";
   char        x_which     [LEN_TITLE] = "";
   char        x_ftype     =  '-';
   /*---(header)-------------------------*/
   UDEBUG_KOIOS   ylog_uenter  (__FUNCTION__);
   /*---(defaulting)------------------*/
   if (r_ditto     != NULL)  *r_ditto    = '-';
   if (r_major     != NULL)  *r_major    = '-';
   if (r_minor     != NULL)  *r_minor    = '-';
   PROG__defaults ();
   /*---(check file)---------------------*/
   x_ftype = yUNIT_reuse_ftype (a_nscrp, NULL);
   UDEBUG_KOIOS   ylog_uchar   ("x_ftype"   , x_ftype);
   /*---(read next)-------------------*/
   rc = READ_next     (b_scrp, r_nline, r_dittoing, r_dtarget, r_dstart, r_dline, r_nrecd, x_recd);
   UDEBUG_KOIOS   ylog_uvalue  ("read"      , rc);
   if (rc == 0) {
      UDEBUG_KOIOS   ylog_unote   ("end of file");
      UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
      return 0;
   }
   --rce;  if (rc < 0)  {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(check flow)------------------*/
   UDEBUG_KOIOS   ylog_uinfo   ("x_recd"    , x_recd);
   rc = PARSE_prep    (b_scrp, a_nscrp, *r_nline, a_runtype, x_recd, x_verb, r_under, &x_spec, &p_conv, &p_code, x_stage, &x_vers, x_desc, x_expe, r_ditto, r_dittoing, r_dtarget, r_dstart, r_dline, r_major, r_minor, r_share, r_select);
   UDEBUG_KOIOS   ylog_uvalue  ("flow"      , rc);
   --rce;  if (rc < 0)  {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   UDEBUG_KOIOS   ylog_uchar   ("x_spec"    , x_spec);
   /*---(parse)-----------------------*/
   rc = PARSE_driver  (a_nscrp, *r_nline, x_vers, x_verb, x_spec, x_recd, x_desc, x_meth, x_args, x_test, x_expe, x_retn, x_which);
   UDEBUG_KOIOS   ylog_uvalue  ("parse"     , rc);
   --rce;  if (rc < 0)  {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(shared update)---------------*/
   UDEBUG_KOIOS   ylog_upoint  ("r_major"   , r_major);
   --rce;  if (x_spec == KOIOS_SSHAR && r_major != NULL) {
      UDEBUG_KOIOS   ylog_unote   ("handling populating a share");
      UDEBUG_KOIOS   ylog_uchar   ("*r_major"  , *r_major);
      rc = yUNIT_reuse_populate (*r_major, x_ftype, *r_nline, x_desc, x_meth, x_expe);
      UDEBUG_KOIOS   ylog_uvalue  ("reuse"     , rc);
      if (rc < 0)  {
         UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
         return rce;
      }
   }
   /*---(write output)----------------*/
   if (a_good == 'y') {
      switch (a_runtype) {
      case G_RUN_UPDATE :
         rc = CONV_driver (p_conv, a_conv, x_verb, x_desc, x_meth, x_args, x_test, x_expe, x_retn, x_stage, x_which, *r_ditto, *r_major, *r_minor, r_share, r_select);
         break;
      case G_RUN_CREATE:  case  G_RUN_DEBUG :
         rc = CODE_driver (p_code, a_nscrp, a_main, a_head, a_code, a_wave, a_runtype, b_last, *r_nline, x_verb, x_desc, x_meth, x_args, x_test, x_expe, x_retn, x_stage, x_which, *r_ditto, *r_dittoing, *r_dtarget, *r_dline, *r_major, *r_minor, r_share, r_select);
         break;
      }
      UDEBUG_KOIOS   ylog_uvalue  ("output"    , rc);
      --rce;  if (rc < 0)  {
         UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
         return rce;
      }
   }
   /*---(save last)-------------------*/
   if (strcmp (x_verb, "DITTO") != 0)  strlcpy (b_last, x_verb, LEN_LABEL);
   /*---(save-back)-------------------*/
   PROG__save_back (x_recd, x_verb, p_conv, p_code, x_spec, x_vers, x_desc, x_meth, x_args, x_test, x_expe, x_retn, x_stage, *r_ditto, *r_major, *r_minor, x_which);
   /*---(complete)-----------------------*/
   UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
   return 1;
}

char
PROG_dusk                (char a_good, char a_runtype, char a_replace, char a_nscrp [LEN_TITLE], FILE **r_scrp, int a_nline, char a_nmain [LEN_TITLE], FILE **r_main, char a_nhead [LEN_TITLE], FILE **r_head, char a_ncode [LEN_TITLE], FILE **r_code, char a_nwave [LEN_TITLE], FILE **r_wave, char a_nconv [LEN_TITLE], FILE **r_conv, char a_share, char a_select)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        t           [LEN_RECD]  = "";
   /*---(header)-------------------------*/
   UDEBUG_KOIOS   ylog_uenter  (__FUNCTION__);
   /*---(close files)--------------------*/
   rc = yenv_uclose_detail (__FILE__, __FUNCTION__, __LINE__, a_nscrp, r_scrp);
   --rce;  switch (a_runtype) {
   case G_RUN_CREATE : case G_RUN_DEBUG :
      rc = CODE_footer  (a_good, a_nscrp, a_nmain, r_main, a_nhead, r_head, a_ncode, r_code, a_nwave, r_wave, a_nline, a_share, a_select, '-');
      break;
   case G_RUN_UPDATE :
      rc = CONV_footer  (a_good, r_conv, a_nscrp, a_nconv);
      break;
   default  :
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   UDEBUG_KOIOS   ylog_uvalue  ("footer"    , rc);
   --rce;  if (rc <  0) {
      PROG_shutdown ();
      return rc;
   }
   /*---(handle replace)-----------------*/
   if (a_good == 'y' && a_replace == G_AND_REPLACE) {
      sprintf (t, "cp -f %s %s.old", a_nscrp, a_nscrp);
      system  (t);
      if (my.debug == 'y')  ylog_unote  ("replacing script with update, saved original in .old");
      else                  printf ("replacing script with update, saved original in .old\n");
      sprintf (t, "mv -f %s %s"   , a_nconv, a_nscrp);
      system  (t);
   }
   else if (a_good != 'y') {
      if (my.debug == 'y')  ylog_unote  ("trouble found in script during update");
      else                  printf ("trouble found in script during update\n");
   }
   /*---(complete)-----------------------*/
   UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
   return 0;
}

char
PROG_pseudo        (int a_argc, char *a_argv [])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        x_good      =  'y';
   int         x_error     =    0;
   /*---(debugging)----------------------*/
   rc = PROG_urgents (a_argc, a_argv);
   UDEBUG_KOIOS   ylog_uvalue   ("urgents"   , rc);
   --rce;  if (rc <  0) { 
      PROG_shutdown ();
      return rce;
   }
   /*---(initialization)-----------------*/
   rc = PROG_startup (a_argc, a_argv);
   UDEBUG_KOIOS   ylog_uvalue   ("startup"   , rc);
   --rce;  if (rc <  0) {
      PROG_shutdown ();
      return rce;
   }
   /*---(main-loop)----------------------*/
   rc = PROG_dawn  (my.run_type, my_loc.l_scrp, &(my_loc.l_SCRP), &(my_run.r_nline), my_loc.l_main, &(my_loc.l_MAIN), my_loc.l_head, &(my_loc.l_HEAD), my_loc.l_code, &(my_loc.l_CODE), my_loc.l_wave, &(my_loc.l_WAVE), my_loc.l_conv, &(my_loc.l_CONV), &(my_run.r_share), &(my_run.r_select));
   UDEBUG_KOIOS   ylog_uvalue   ("dawn"      , rc);
   --rce;  if (rc <  0) {
      PROG_shutdown ();
      return rce;
   }
   /*---(begin-main)---------------------*/
   UDEBUG_KOIOS   ylog_uenter  (__FUNCTION__);
   UDEBUG_KOIOS   ylog_unote   ("entering main processing loop");
   /*---(main)---------------------------*/
   while (1) {
      UDEBUG_KOIOS   ylog_uchar   ("x_good"    , x_good);
      rc = PROG_driver (x_good, my.run_type, my_loc.l_scrp, &(my_run.r_nline), &(my_loc.l_SCRP), my_loc.l_MAIN, my_loc.l_HEAD, my_loc.l_CODE, my_loc.l_WAVE, my_loc.l_CONV, my_run.r_last, &(my_run.r_nrecd), &(my_run.r_under), &(my_cur.c_ditto), &(my_run.r_dittoing), &(my_run.r_dtarget), &(my_run.r_dstart), &(my_run.r_dline), &(my_cur.c_major), &(my_cur.c_minor), &(my_run.r_share), &(my_run.r_select));
      UDEBUG_KOIOS   ylog_uvalue  ("driver"    , rc);
      if (rc == 0)  break;  /* end-of-file */
      if (rc <  0) {
         x_good = '-';
         ++x_error;
      }
   }
   /*---(end-main)-----------------------*/
   UDEBUG_KOIOS   ylog_unote   ("exiting main processing loop");
   UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
   /*---(dusk)---------------------------*/
   rc = PROG_dusk  (x_good, my.run_type, my.replace, my_loc.l_scrp, &(my_loc.l_SCRP), my_run.r_nline, my_loc.l_main, &(my_loc.l_MAIN), my_loc.l_head, &(my_loc.l_HEAD), my_loc.l_code, &(my_loc.l_CODE), my_loc.l_wave, &(my_loc.l_WAVE), my_loc.l_conv, &(my_loc.l_CONV), my_run.r_share, my_run.r_select);
   UDEBUG_KOIOS   ylog_uvalue   ("dusk"      , rc);
   --rce;  if (rc <  0) {
      PROG_shutdown ();
      return rce;
   }
   /*---(complete)-----------------------*/
   PROG_shutdown ();
   return -x_error;
}



/*====================------------------------------------====================*/
/*===----                        wrapup functions                      ----===*/
/*====================------------------------------------====================*/
static void  o___WRAPUP__________o () { return; }


char                /* PURPOSE : shutdown program and free memory ------------*/
PROG__end          (void)
{
   UDEBUG_KOIOS   ylog_uenter  (__FUNCTION__);
   UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
   return 0;
}

char             /* [------] drive the program closure activities ------------*/
PROG_shutdown           (void)
{
   /*---(stage-check)--------------------*/
   /*> yURG_stage_check (YURG_END);                                                   <*/
   /*---(header)-------------------------*/
   UDEBUG_KOIOS   ylog_uenter   (__FUNCTION__);
   ylog_uclose  ();
   yerr_uclose  ();
   PROG__end    ();
   /*---(complete)-----------------------*/
   UDEBUG_KOIOS   ylog_uexit    (__FUNCTION__);
   return 0;
}



/*====================------------------------------------====================*/
/*===----                       string versions                        ----===*/
/*====================------------------------------------====================*/
static void  o___STRING__________o () { return; }

char
PROG__args_string       (char a_string [LEN_FULL])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        x_argc      =    0;
   char       *x_argv      [LEN_TERSE];
   char        x_disp      [LEN_FULL]  = "";
   /*---(header)-------------------------*/
   UDEBUG_KOIOS  ylog_uenter   (__FUNCTION__);
   /*---(defense)------------------------*/
   UDEBUG_KOIOS    ylog_upoint   ("a_string"     , a_string);
   --rce;  if (a_string == NULL) {
      UDEBUG_KOIOS  ylog_uexitr   (__FUNCTION__, rce);
      return rce;
   }
   UDEBUG_KOIOS    ylog_uinfo    ("a_string"     , a_string);
   /*---(parse)--------------------------*/
   rc = yexec_uparse (a_string, &x_argc, x_argv, x_disp);
   UDEBUG_KOIOS  ylog_uvalue   ("config"    , rc);
   --rce;  if (rc <  0) {
      UDEBUG_KOIOS  ylog_uexitr   (__FUNCTION__, rce);
      return rce;
   }
   UDEBUG_KOIOS    ylog_uinfo    ("x_disp"       , x_disp);
   /*---(startup)------------------------*/
   rc = PROG__args   (x_argc, x_argv);
   UDEBUG_KOIOS  ylog_uvalue     ("startup"   , rc);
   --rce;  if (rc < 0) {
      UDEBUG_KOIOS    ylog_uexitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(complete)-----------------------*/
   UDEBUG_KOIOS  ylog_uexit  (__FUNCTION__);
   return 0;
}

char
PROG_startup_string     (char a_string [LEN_FULL])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        x_argc      =    0;
   char       *x_argv      [LEN_TERSE];
   char        x_disp      [LEN_FULL]  = "";
   /*---(header)-------------------------*/
   UDEBUG_KOIOS  ylog_uenter   (__FUNCTION__);
   /*---(defense)------------------------*/
   UDEBUG_KOIOS    ylog_upoint   ("a_string"     , a_string);
   --rce;  if (a_string == NULL) {
      UDEBUG_KOIOS  ylog_uexitr   (__FUNCTION__, rce);
      return rce;
   }
   UDEBUG_KOIOS    ylog_uinfo    ("a_string"     , a_string);
   /*---(parse)--------------------------*/
   rc = yexec_uparse (a_string, &x_argc, x_argv, x_disp);
   UDEBUG_KOIOS  ylog_uvalue   ("config"    , rc);
   --rce;  if (rc <  0) {
      UDEBUG_KOIOS  ylog_uexitr   (__FUNCTION__, rce);
      return rce;
   }
   UDEBUG_KOIOS    ylog_uinfo    ("x_disp"       , x_disp);
   /*---(startup)------------------------*/
   rc = PROG_startup   (x_argc, x_argv);
   UDEBUG_KOIOS  ylog_uvalue     ("startup"   , rc);
   --rce;  if (rc < 0) {
      UDEBUG_KOIOS    ylog_uexitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(complete)-----------------------*/
   UDEBUG_KOIOS  ylog_uexit  (__FUNCTION__);
   return 0;
}

char
PROG_pseudo_string      (char a_string [LEN_FULL])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        x_argc      =    0;
   char       *x_argv      [LEN_TERSE];
   char        x_disp      [LEN_FULL]  = "";
   /*---(header)-------------------------*/
   UDEBUG_KOIOS  ylog_uenter   (__FUNCTION__);
   /*---(defense)------------------------*/
   UDEBUG_KOIOS    ylog_upoint   ("a_string"     , a_string);
   --rce;  if (a_string == NULL) {
      UDEBUG_KOIOS  ylog_uexitr   (__FUNCTION__, rce);
      return rce;
   }
   UDEBUG_KOIOS    ylog_uinfo    ("a_string"     , a_string);
   /*---(parse)--------------------------*/
   rc = yexec_uparse (a_string, &x_argc, x_argv, x_disp);
   UDEBUG_KOIOS  ylog_uvalue   ("config"    , rc);
   --rce;  if (rc <  0) {
      UDEBUG_KOIOS  ylog_uexitr   (__FUNCTION__, rce);
      return rce;
   }
   UDEBUG_KOIOS    ylog_uinfo    ("x_disp"       , x_disp);
   /*---(startup)------------------------*/
   rc = PROG_pseudo    (x_argc, x_argv);
   UDEBUG_KOIOS  ylog_uvalue     ("main"      , rc);
   --rce;  if (rc < 0) {
      UDEBUG_KOIOS    ylog_uexitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(complete)-----------------------*/
   UDEBUG_KOIOS  ylog_uexit  (__FUNCTION__);
   return rc;
}



/*====================------------------------------------====================*/
/*===----                   helpers for unit testing                   ----===*/
/*====================------------------------------------====================*/
static void      o___UNITTEST________________o (void) {;}

char
PROG__unit_bigclean     (void)
{
   /*---(unit related)-------------------*/
   system ("rm    -f /tmp/apate.unit         > /dev/null   2>&1");
   system ("rm    -f /tmp/apate.sunit        > /dev/null   2>&1");
   system ("rm    -f /tmp/apatey.sunit       > /dev/null   2>&1");
   system ("rm    -f /tmp/linked.unit        > /dev/null   2>&1");
   system ("rm    -f /tmp/linked.sunit       > /dev/null   2>&1");
   system ("rm    -f /tmp/apate-a.unit       > /dev/null   2>&1");
   system ("rm    -f /tmp/apate_a.unit       > /dev/null   2>&1");
   system ("rmdir -f /tmp/apate_dir.unit     > /dev/null   2>&1");
   system ("rm    -f /tmp/khaos.unit         > /dev/null   2>&1");
   system ("rm    -f /tmp/gyges.unit         > /dev/null   2>&1");
   system ("rm    -f /tmp/hestia.unit        > /dev/null   2>&1");
   /*---(code related)-------------------*/
   system ("rm    -f /tmp/apate.h            > /dev/null   2>&1");
   system ("rm    -f /tmp/apate.c            > /dev/null   2>&1");
   system ("rm    -f /tmp/apate_unit.c       > /dev/null   2>&1");
   system ("rm    -f /tmp/apate_unit.cs      > /dev/null   2>&1");
   system ("rm    -f /tmp/apate_unit.o       > /dev/null   2>&1");
   system ("rm    -f /tmp/apate_unit.tmp     > /dev/null   2>&1");
   system ("rm    -f /tmp/apate.unit.old     > /dev/null   2>&1");
   system ("rm    -f /tmp/apate.wave         > /dev/null   2>&1");
   /*---(master related)-----------------*/
   system ("rm    -f /tmp/unit_head.h        > /dev/null   2>&1");
   system ("rm    -f /tmp/unit_head.c        > /dev/null   2>&1");
   system ("rm    -f /tmp/unit_code.h        > /dev/null   2>&1");
   system ("rm    -f /tmp/unit_code.c        > /dev/null   2>&1");
   system ("rm    -f /tmp/unit_wide.h        > /dev/null   2>&1");
   system ("rm    -f /tmp/unit_wide.c        > /dev/null   2>&1");
   system ("rm    -f /tmp/unit_head.unit     > /dev/null   2>&1");
   system ("rm    -f /tmp/unit_head.unit.old > /dev/null   2>&1");
   /*> system ("rm    -f /tmp/unit.globals       > /dev/null   2>&1");                <*/
   /*---(output)-------------------------*/
   system ("rm    -f /tmp/apate.urun         > /dev/null   2>&1");
   system ("rm    -f /tmp/apate_errors.txt   > /dev/null   2>&1");
   system ("rm    -f /tmp/apate_unit         > /dev/null   2>&1");
   /*---(done)---------------------------*/
   return 0;
}

char       /*----: set up program urgents/debugging --------------------------*/
PROG__unit_quiet   (void)
{
   char        rce         =  -10;
   char        rc          =    0;
   char        x_argc      =    3;
   char       *x_argv [3]  = { "koios_unit", "--verify", "koios_zzzz" };
   /*---(header)-------------------------*/
   UDEBUG_KOIOS  ylog_uenter   (__FUNCTION__);
   /*---(prepare)------------------------*/
   system ("touch /tmp/koios.unit_testing_marvel/koios_zzzz.unit           2> /dev/null");
   /*---(debugging)----------------------*/
   rc = PROG_urgents (x_argc, x_argv);
   UDEBUG_KOIOS   ylog_uvalue   ("urgents"   , rc);
   --rce;  if (rc <  0) { 
      PROG_shutdown ();
      UDEBUG_KOIOS   ylog_uexitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(initialization)-----------------*/
   rc = PROG_startup (x_argc, x_argv);
   UDEBUG_KOIOS   ylog_uvalue   ("startup"   , rc);
   --rce;  if (rc <  0) {
      PROG_shutdown ();
      UDEBUG_KOIOS   ylog_uexitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(clean-up)-----------------------*/
   system ("rm -f /tmp/koios.unit_testing_marvel/koios_zzzz.unit           2> /dev/null");
   /*---(complete)-----------------------*/
   UDEBUG_KOIOS   ylog_uexit (__FUNCTION__);
   return 0;
}

char       /*----: set up program urgents/debugging --------------------------*/
PROG__unit_loud    (void)
{
   char        rce         =  -10;
   char        rc          =    0;
   char        x_argc      =    5;
   char       *x_argv [5]  = { "koios_debug", "@@kitchen" , "@@koios" , "--verify", "koios_zzzz"};
   /*---(header)-------------------------*/
   UDEBUG_KOIOS  ylog_uenter   (__FUNCTION__);
   /*---(prepare)------------------------*/
   system ("touch /tmp/koios.unit_testing_marvel/koios_zzzz.unit           2> /dev/null");
   /*---(debugging)----------------------*/
   rc = PROG_urgents (x_argc, x_argv);
   UDEBUG_KOIOS   ylog_uvalue   ("urgents"   , rc);
   --rce;  if (rc <  0) { 
      PROG_shutdown ();
      UDEBUG_KOIOS   ylog_uexitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(initialization)-----------------*/
   rc = PROG_startup (x_argc, x_argv);
   UDEBUG_KOIOS   ylog_uvalue   ("startup"   , rc);
   --rce;  if (rc <  0) {
      PROG_shutdown ();
      UDEBUG_KOIOS   ylog_uexitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(clean-up)-----------------------*/
   system ("rm -f /tmp/koios.unit_testing_marvel/koios_zzzz.unit           2> /dev/null");
   /*---(debug)--------------------------*/
   /*> printf ("which !!  %s\n", ylog_uwhich ());                                     <* 
    *> printf ("which !!  %s\n", mylog_lstd);                                         <* 
    *> printf ("my.debug  %c\n", my.debug);                                           <* 
    *> printf ("ulines    %d\n", ylog_ulines());                                      <*/
   /*---(complete)-----------------------*/
   UDEBUG_KOIOS   ylog_uexit (__FUNCTION__);
   return 0;
}

char       /*----: set up program urgents/debugging --------------------------*/
PROG__unit_end     (void)
{
   /*---(header)-------------------------*/
   UDEBUG_KOIOS  ylog_uenter   (__FUNCTION__);
   PROG_shutdown   ();
   UDEBUG_KOIOS  ylog_uexit    (__FUNCTION__);
   return 0;
}







/*===============================[[ end code ]]===============================*/
