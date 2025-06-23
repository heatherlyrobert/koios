/*===============================[[ beg-code ]]===============================*/
#include    "koios.h"        /* LOCAL  : main header                          */



#include    <ySTR_uver.h>
#include    <yENV_uver.h>
#include    <yLOG_uver.h>



tGLOBALS    my;
tLOC        my_loc;
tCUR        my_cur;
tRUN        my_run;


char    g_print     [LEN_RECD] = "";


/*====================------------------------------------====================*/
/*===----                        identipy functions                    ----===*/
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
   debug_uver   ylog_uenter   (__FUNCTION__);
   /*---(versioning)------------------*/
   debug_uver   ylog_uinfo    ("gregg"   , PROG_version      ());
   debug_uver   ylog_uinfo    ("purpose" , P_PURPOSE);
   debug_uver   ylog_uinfo    ("namesake", P_NAMESAKE);
   debug_uver   ylog_uinfo    ("heritage", P_HERITAGE);
   debug_uver   ylog_uinfo    ("imagery" , P_IMAGERY);
   debug_uver   ylog_unote    ("custom core");
   debug_uver   ylog_uinfo    ("yUNIT"   , yUNIT_version     ());
   /*---(complete)-----------------------*/
   debug_uver   ylog_uexit (__FUNCTION__);
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
   debug_uver   ylog_uvalue   ("header"    , rc);
   --rce;  if (rc < 0) {
      debug_uver   ylog_uexitr   (__FUNCTION__, rce);
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
   debug_uver   ylog_uenter  (__FUNCTION__);
   /*---(files)--------------------------*/
   strlcpy  (my_loc.l_scrp, "", LEN_TITLE);  my_loc.l_SCRP = NULL;
   strlcpy  (my_loc.l_main, "", LEN_TITLE);  my_loc.l_MAIN = NULL;
   strlcpy  (my_loc.l_code, "", LEN_TITLE);  my_loc.l_CODE = NULL;
   strlcpy  (my_loc.l_wave, "", LEN_TITLE);  my_loc.l_WAVE = NULL;
   strlcpy  (my_loc.l_conv, "", LEN_TITLE);  my_loc.l_CONV = NULL;
   strlcpy  (my_run.r_last, "", LEN_LABEL);
   my_run.r_under = '-';
   my.noise = '-';
   VERB_init  ();
   DITTO_init ();
   REUSE_init ();
   CODE_init  ();
   CONV_init  ();
   getcwd (my.cwd, LEN_PATH);
   /*---(complete)-----------------------*/
   debug_uver   ylog_uexit   (__FUNCTION__);
   return 0;
}

char
PROG__file              (char a_name [LEN_TITLE], char r_base [LEN_TITLE], char r_proj [LEN_LABEL], char r_ext [LEN_TERSE])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        x_proj      [LEN_LABEL]  = "";
   char        x_base      [LEN_TITLE]  = "";
   char        x_unit      [LEN_TITLE]  = "";
   char        x_ext       [LEN_TERSE] = "";
   int         l           =    0;
   int         i           =    0;
   tSTAT       s;
   char       *p           = NULL;
   tSTAT       r;
   char        t           [LEN_FULL]  = "";
   /*---(header)-------------------------*/
   debug_uver   ylog_uenter  (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_base != NULL)  strcpy (r_base, "");
   if (r_proj != NULL)  strcpy (r_proj, "");
   if (r_ext  != NULL)  strcpy (r_ext , "");
   /*---(defense)------------------------*/
   debug_uver  ylog_upoint  ("a_name"    , a_name);
   --rce;  if (a_name == NULL) {
      yerr_uerror ("script name can not be null");
      debug_uver  ylog_uexitr(__FUNCTION__, rce);
      return rce;
   }
   debug_uver  ylog_uinfo   ("a_name"    , a_name);
   /*---(check length)-------------------*/
   l = strlen (a_name);
   debug_uver  ylog_uvalue  ("l"         , l);
   --rce;  if (l <= 0) {
      yerr_uerror ("script name can not be blank/empty");
      debug_uver  ylog_uexitr(__FUNCTION__, rce);
      return rce;
   }
   /*---(check for path)-----------------*/
   --rce;  if (strchr (a_name, '/') != NULL) {
      yerr_uerror ("script name ¶%s¶ can not include a path (abs or rel)", a_name);
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(check for hidden)---------------*/
   --rce;  if (a_name [0] == '.') {
      yerr_uerror ("script name ¶%s¶ can not be hidden file (.)", a_name);
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(check characters)---------------*/
   --rce;  for (i = 0; i < l; ++i) {
      if (strchr (YSTR_ALNUM "_.", a_name [i]) != NULL)  continue;
      yerr_uerror ("script name ¶%s¶ can not have a '%c' as character %d", a_name, a_name [i], i);
      debug_uver  ylog_uchar ("bad char"  , a_name [i]);
      debug_uver  ylog_uexitr(__FUNCTION__, rce);
      return rce;
   }
   /*---(check for extentions)-----------*/
   strcpy (x_base, a_name);
   p = strstr (x_base, ".unit");
   if (p != NULL)   p [0] = '\0';
   p = strstr (x_base, ".sunit");
   if (p != NULL)   p [0] = '\0';
   /*---(check unit file)----------------*/
   sprintf (x_unit, "%s.unit", x_base);
   debug_uver    ylog_uvalue  ("x_unit"    , rc);
   rc = lstat (x_unit, &s);
   debug_uver    ylog_uvalue  ("stat"      , rc);
   --rce;  if (rc < 0) {
      sprintf (x_unit, "%s.sunit", x_base);
      debug_uver    ylog_uvalue  ("x_unit"    , rc);
      rc = lstat (x_unit, &s);
      debug_uver    ylog_uvalue  ("stat"      , rc);
      if (rc < 0) {
         yerr_uerror ("script name ¶%s¶ can not be found as .unit or .sunit", a_name);
         debug_uver    ylog_unote   ("can not find source either .unit or .sunit");
         debug_uver    ylog_uexitr (__FUNCTION__, rce);
         return rce;
      } else {
         strcpy (x_ext, ".sunit");
      }
   } else {
      strcpy (x_ext, ".unit");
   }
   --rce;  if (S_ISDIR (s.st_mode))  {
      yerr_uerror ("script name ¶%s¶ refers to a directory, illegal", a_name);
      debug_uver    ylog_unote   ("can not use a directory");
      debug_uver    ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   --rce;  if (S_ISLNK (s.st_mode))  {
      debug_uver    ylog_unote   ("is a link, figure it out");
      if (strcmp (x_ext, ".sunit") == 0) {
         yerr_uerror ("script name ¶%s¶ is a .sunit can can not be a symlink", a_name);
         if (my.debug == 'y')  ylog_unote ("FATAL, .sunit can not be a symlink");
         else                  printf ("FATAL, .sunit can not be a symlink\n");
         debug_uver    ylog_unote   ("can not use a symlink");
         debug_uver    ylog_uexitr  (__FUNCTION__, rce);
         return rce;
      } else {
         rc = readlink (x_unit, t, LEN_FULL);
         debug_uver    ylog_uvalue  ("readlink"  , rc);
         if (rc < 0) {
            debug_uver    ylog_uexitr (__FUNCTION__, rce);
            return rce;
         }
         debug_uver  ylog_uinfo   ("t"         , t);
         l = strlen (t);
         debug_uver  ylog_uvalue  ("l"         , l);
         if (l < 7) {
            debug_uver    ylog_uexitr (__FUNCTION__, rce);
            return rce;
         }
         debug_uver  ylog_uinfo   ("suffix"    , t + l - 6);
         if (strcmp (t + l - 6, ".sunit") != 0) {
            yerr_uerror ("script name ¶%s¶ is a symlink to ¶%s¶, only .sunit is legal", a_name, t);
            debug_uver    ylog_uexitr (__FUNCTION__, rce);
            return rce;
         }
         rc = stat (t, &r);
         debug_uver    ylog_uvalue  ("stat"      , rc);
         if (rc < 0) {
            yerr_uerror ("script name ¶%s¶ is a symlink to .sunit ¶%s¶, but source does not exist", a_name, t);
            debug_uver    ylog_uexitr (__FUNCTION__, rce);
            return rce;
         }
      }
   }
   else if (!S_ISREG (s.st_mode)) {
      yerr_uerror ("script name ¶%s¶ is not a regular file, illegal", a_name);
      debug_uver    ylog_unote   ("can only use regular file");
      debug_uver    ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(get project name)---------------*/
   p = strchr (x_base, '_');
   if (p == NULL)  strcpy (x_proj, x_base);
   else {
      l = p - x_base;
      strncpy (x_proj, x_base, l);
   }
   /*---(check master.h)-----------------*/
   rc = lstat ("master.h", &s);
   debug_uver    ylog_uvalue  ("stat"      , rc);
   if (rc < 0)   system  ("touch master.h");
   /*---(save back)----------------------*/
   if (r_base != NULL) {
      strncpy (r_base, x_base, LEN_TITLE);
      debug_uver  ylog_uinfo   ("r_base"    , r_base);
   }
   if (r_proj != NULL) {
      strncpy (r_proj, x_proj, LEN_LABEL);
      debug_uver  ylog_uinfo   ("r_proj"    , r_proj);
   }
   if (r_ext  != NULL) {
      strncpy (r_ext , x_ext , LEN_TERSE);
      debug_uver  ylog_uinfo   ("r_ext"     , r_ext);
   }
   /*---(complete)-----------------------*/
   debug_uver   ylog_uexit   (__FUNCTION__);
   return 0;
}

char
PROG__args              (int a_argc, char *a_argv [], char *r_runtype, char *r_noise, char *r_replace, char r_base [LEN_TITLE], char r_proj [LEN_LABEL], char r_ext [LEN_SHORT])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        x_runtype   = G_RUN_CREATE;
   char        x_noise     = G_RUN_DEFAULT;
   char        x_replace   = G_RUN_DEFAULT;
   char        x_base      [LEN_TITLE]  = "";
   char        x_proj      [LEN_LABEL]  = "";
   char        x_ext       [LEN_TERSE] = "";
   int         i           =    0;
   char       *a           = NULL;
   int         x_total     =    0;
   int         x_args      =    0;
   /*---(begin)--------------------------*/
   debug_uver  ylog_uenter  (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_runtype != NULL)  *r_runtype = '·';
   if (r_noise   != NULL)  *r_noise   = '·';
   if (r_replace != NULL)  *r_replace = '·';
   if (r_base    != NULL)  strcpy (r_base, "");
   if (r_proj    != NULL)  strcpy (r_proj, "");
   if (r_ext     != NULL)  strcpy (r_ext , "");
   /*---(defenses)-----------------------*/
   debug_uver  ylog_upoint  ("a_argv" , a_argv);
   --rce;  if (a_argv == NULL) {
      debug_uver    ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(process)------------------------*/
   --rce;  for (i = 1; i < a_argc; ++i) {
      a = a_argv[i];
      ++x_total;
      if (a[0] == '@')  continue;
      debug_uver  ylog_uinfo   ("cli arg", a);
      ++x_args;
      /*---(better testing)--------------*/
      if      (strncmp (a, "--verify"     , 10) == 0)  { x_runtype = G_RUN_UPDATE;  x_noise = '-'; }
      else if (strncmp (a, "--cverify"    , 10) == 0)  { x_runtype = G_RUN_UPDATE;  x_noise = 'c'; }
      else if (strncmp (a, "--everify"    , 10) == 0)  { x_runtype = G_RUN_UPDATE;  x_noise = 'e'; }
      else if (strncmp (a, "--Everify"    , 10) == 0)  { x_runtype = G_RUN_UPDATE;  x_noise = 'E'; }
      else if (strncmp (a, "--vverify"    , 10) == 0)  { x_runtype = G_RUN_UPDATE;  x_noise = 'v'; }
      /*---(better conversion)-----------*/
      else if (strncmp (a, "--conv"       , 10) == 0)  { x_runtype = G_RUN_UPDATE;  x_replace = G_AND_REPLACE;  x_noise = '-'; }
      else if (strncmp (a, "--cconv"      , 10) == 0)  { x_runtype = G_RUN_UPDATE;  x_replace = G_AND_REPLACE;  x_noise = 'c'; }
      else if (strncmp (a, "--econv"      , 10) == 0)  { x_runtype = G_RUN_UPDATE;  x_replace = G_AND_REPLACE;  x_noise = 'e'; }
      else if (strncmp (a, "--Econv"      , 10) == 0)  { x_runtype = G_RUN_UPDATE;  x_replace = G_AND_REPLACE;  x_noise = 'E'; }
      else if (strncmp (a, "--vconv"      , 10) == 0)  { x_runtype = G_RUN_UPDATE;  x_replace = G_AND_REPLACE;  x_noise = 'v'; }
      /*---(better code/create)----------*/
      else if (strncmp (a, "--code"       , 10) == 0)  { x_runtype = G_RUN_CREATE;  x_noise = '-'; }
      else if (strncmp (a, "--ccode"      , 10) == 0)  { x_runtype = G_RUN_CREATE;  x_noise = 'c'; }
      else if (strncmp (a, "--ecode"      , 10) == 0)  { x_runtype = G_RUN_CREATE;  x_noise = 'e'; }
      else if (strncmp (a, "--Ecode"      , 10) == 0)  { x_runtype = G_RUN_CREATE;  x_noise = 'E'; }
      else if (strncmp (a, "--vcode"      , 10) == 0)  { x_runtype = G_RUN_CREATE;  x_noise = 'v'; }
      /*---(better code/debug)-----------*/
      else if (strncmp (a, "--debug"      , 10) == 0)  { x_runtype = G_RUN_DEBUG;   x_noise = '-'; }
      else if (strncmp (a, "--cdebug"     , 10) == 0)  { x_runtype = G_RUN_DEBUG;   x_noise = 'c'; }
      else if (strncmp (a, "--edebug"     , 10) == 0)  { x_runtype = G_RUN_DEBUG;   x_noise = 'e'; }
      else if (strncmp (a, "--Edebug"     , 10) == 0)  { x_runtype = G_RUN_DEBUG;   x_noise = 'E'; }
      else if (strncmp (a, "--vdebug"     , 10) == 0)  { x_runtype = G_RUN_DEBUG;   x_noise = 'v'; }
      /*---(old args)--------------------*/
      else if (strncmp (a, "--create"     , 10) == 0)    x_runtype = G_RUN_CREATE;
      else if (strncmp (a, "--compile"    , 10) == 0)    x_runtype = G_RUN_CREATE;
      else if (strncmp (a, "--debug"      , 10) == 0)    x_runtype = G_RUN_DEBUG;
      else if (strncmp (a, "--validate"   , 10) == 0)    x_runtype = G_RUN_UPDATE;
      else if (strncmp (a, "--convert"    , 10) == 0)    x_runtype = G_RUN_UPDATE;
      else if (strncmp (a, "--update"     , 10) == 0)  { x_runtype = G_RUN_UPDATE;  x_replace = G_AND_REPLACE; }
      /*---(unknown arg)-----------------*/
      else if (strncmp (a, "-"            ,  1) == 0)  {
         yerr_uerror ("argument ¶%s¶ is not recognized", a);
         debug_uver  ylog_uexitr (__FUNCTION__, rce);
         return rce;
      }
      /*---(file name)-------------------*/
      else {
         rc = PROG__file (a, x_base, x_proj, x_ext);
         if (rc < 0) {
            debug_uver  ylog_unote  ("base name is invalid or not found");
            debug_uver  ylog_uexitr (__FUNCTION__, rce);
            return rce;
         }
      }
      /*---(done)------------------------*/
   }
   /*---(check zero entries)-------------*/
   debug_uver  ylog_uvalue ("entries"   , x_total);
   debug_uver  ylog_uvalue ("arguments" , x_args);
   if (x_args == 0) {
      debug_uver  ylog_unote  ("no arguments identified");
   }
   debug_uver  ylog_uchar  ("run_type"  , x_runtype);
   debug_uver  ylog_uinfo  ("basename"  , x_base);
   /*---(defense)------------------------*/
   debug_uver   ylog_uinfo   ("basename"  , x_base);
   --rce;  if (strcmp (x_base, "") == 0) {
      yerr_uerror ("script name/base was not provided on command line");
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(defense)------------------------*/
   --rce;  if (strcmp (x_ext, ".sunit") == 0) {
      if (x_runtype != G_RUN_UPDATE) {
         yerr_uerror ("can not compile ¶%s¶ as .sunit, must compile in linked .unit location", x_base);
         debug_uver   ylog_uexitr  (__FUNCTION__, rce);
         return rce;
      }
   }
   /*---(set noise)----------------------*/
   if (x_noise != '-')   yerr_uopen ();
   /*---(save-back)----------------------*/
   if (r_runtype != NULL)  *r_runtype = x_runtype;
   if (r_noise   != NULL)  *r_noise   = x_noise;
   if (r_replace != NULL)  *r_replace = x_replace;
   if (r_base    != NULL)  strlcpy (r_base, x_base, LEN_TITLE);
   if (r_proj    != NULL)  strlcpy (r_proj, x_proj, LEN_LABEL);
   if (r_ext     != NULL)  strlcpy (r_ext , x_ext , LEN_TERSE);
   /*---(complete)-----------------------*/
   debug_uver  ylog_uexit (__FUNCTION__);
   return 0;
}

char
PROG__begin             (void)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   /*---(header)-------------------------*/
   debug_uver   ylog_uenter  (__FUNCTION__);
   /*---(create names)-------------------*/
   snprintf (my_loc.l_scrp, LEN_TITLE, "%s%s"            , my_loc.l_base, my_loc.l_extn);
   snprintf (my_loc.l_main, LEN_TITLE, "%s_unit.tmp"     , my_loc.l_base);
   snprintf (my_loc.l_code, LEN_TITLE, "%s_unit.cs"      , my_loc.l_base);
   snprintf (my_loc.l_wave, LEN_TITLE, "%s.wave"         , my_loc.l_base);
   snprintf (my_loc.l_conv, LEN_TITLE, "%s%s.new"        , my_loc.l_base, my_loc.l_extn);
   /*---(special for debug)--------------*/
   if (my.run_type == G_RUN_DEBUG)   snprintf (my_loc.l_code, LEN_TITLE, "%s_unit.c"      , my_loc.l_base);
   /*---(initialize)---------------------*/
   my_run.r_nline    = 0;
   my_run.r_nrecd    = 0;
   my_run.r_dittoing = '-';
   my_run.r_dtarget  = '-';
   my_run.r_dstart   = -1;
   /*---(complete)-----------------------*/
   debug_uver   ylog_uexit   (__FUNCTION__);
   return 0;
}

char
PROG_startup            (int a_argc, char *a_argv [])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   /*---(header)----------------------*/
   debug_uver  ylog_uenter  (__FUNCTION__);
   /*---(initialize)---------------------*/
   rc = PROG__init   ();
   debug_uver   ylog_uvalue   ("init"      , rc);
   --rce;  if (rc < 0) {
      debug_uver   ylog_uexitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(arguments)----------------------*/
   rc = PROG__args   (a_argc, a_argv, &(my.run_type), &(my.noise), &(my.replace), my_loc.l_base, my_loc.l_proj, my_loc.l_extn);
   debug_uver   ylog_uvalue   ("args"      , rc);
   --rce;  if (rc < 0) {
      debug_uver   ylog_uexitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(begin)--------------------------*/
   rc = PROG__begin  ();
   debug_uver   ylog_uvalue   ("begin"     , rc);
   --rce;  if (rc < 0) {
      debug_uver   ylog_uexitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(complete)-----------------------*/
   debug_uver  ylog_uexit (__FUNCTION__);
   return rc;
}



/*====================------------------------------------====================*/
/*===----                        program execution                     ----===*/
/*====================------------------------------------====================*/
static void      o___EXECUTION_______________o (void) {;}

char
PROG_dawn                (char a_runtype, char a_nscrp [LEN_TITLE], FILE **r_scrp, int *r_line, char a_nmain [LEN_TITLE], FILE **r_main, char a_ncode [LEN_TITLE], FILE **r_code, char a_nwave [LEN_TITLE], FILE **r_wave, char a_nconv [LEN_TITLE], FILE **r_conv, char *r_share, char *r_select)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   /*---(header)-------------------------*/
   debug_uver   ylog_uenter  (__FUNCTION__);
   /*---(open incomming script)----------*/
   rc = READ_open      (__FILE__, __FUNCTION__, __LINE__, my.cwd, a_nscrp, 'r', r_scrp, r_line);
   debug_uver   ylog_uvalue  ("script"    , rc);
   --rce;  if (rc < 0) {
      PROG_shutdown ();
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(open output files)--------------*/
   --rce;  switch (a_runtype) {
   case G_RUN_CREATE : case G_RUN_DEBUG :
      rc = CODE_header (a_nscrp, a_nmain, r_main, a_ncode, r_code, a_nwave, r_wave, r_share, r_select);
      break;
   case G_RUN_UPDATE :
      rc = CONV_header  (a_nconv, r_conv, r_share, r_select);
      break;
   default  :
      READ_close (__FILE__, __FUNCTION__, __LINE__, a_nscrp, r_scrp);
      PROG_shutdown ();
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
      break;
   }
   debug_uver   ylog_uvalue  ("output"    , rc);
   --rce;  if (rc <  0) {
      READ_close (__FILE__, __FUNCTION__, __LINE__, a_nscrp, r_scrp);
      PROG_shutdown ();
      return rc;
   }
   /*---(open output files)--------------*/
   if (strcmp (a_nscrp, "master.unit") != 0) {
      rc = REUSE_import  ("master.globals");
      debug_uver   ylog_uvalue  ("globals"   , rc);
   }
   /*---(complete)-----------------------*/
   debug_uver   ylog_uexit   (__FUNCTION__);
   return 0;
}

char
PROG_terminate           (FILE **r_scrp, FILE **r_main, FILE **r_code, FILE **r_wave, FILE **r_conv)
{
   debug_uver   ylog_uenter  (__FUNCTION__);
   READ_close (__FILE__, __FUNCTION__, __LINE__, "???", r_scrp);
   READ_close (__FILE__, __FUNCTION__, __LINE__, "???", r_main);
   READ_close (__FILE__, __FUNCTION__, __LINE__, "???", r_code);
   READ_close (__FILE__, __FUNCTION__, __LINE__, "???", r_wave);
   debug_uver   ylog_uexit   (__FUNCTION__);
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
PROG_driver              (char a_good, char a_runtype, char a_nscrp [LEN_TITLE], int *r_nline, FILE **b_scrp, FILE *a_main, FILE *a_code, FILE *a_wave, FILE *a_conv, char b_last [LEN_LABEL], int *r_nrecd, char *r_under, char *r_ditto, char *r_dittoing, char *r_dtarget, int *r_dstart, int *r_dline, char *r_major, char *r_minor, char *r_share, char *r_select)
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
   /*---(header)-------------------------*/
   debug_uver   ylog_uenter  (__FUNCTION__);
   /*---(defaulting)------------------*/
   if (r_ditto     != NULL)  *r_ditto    = '-';
   if (r_major     != NULL)  *r_major    = '-';
   if (r_minor     != NULL)  *r_minor    = '-';
   PROG__defaults ();
   /*---(read next)-------------------*/
   rc = READ_next     (b_scrp, r_nline, r_dittoing, r_dtarget, r_dstart, r_dline, r_nrecd, x_recd);
   debug_uver   ylog_uvalue  ("read"      , rc);
   if (rc == 0) {
      debug_uver   ylog_unote   ("end of file");
      debug_uver   ylog_uexit   (__FUNCTION__);
      return 0;
   }
   --rce;  if (rc < 0)  {
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(check flow)------------------*/
   debug_uver   ylog_uinfo   ("x_recd"    , x_recd);
   rc = PARSE_prep    (b_scrp, a_nscrp, *r_nline, a_runtype, x_recd, x_verb, r_under, &x_spec, &p_conv, &p_code, x_stage, &x_vers, x_desc, x_expe, r_ditto, r_dittoing, r_dtarget, r_dstart, r_dline, r_major, r_minor, r_share, r_select);
   debug_uver   ylog_uvalue  ("flow"      , rc);
   --rce;  if (rc < 0)  {
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(parse)-----------------------*/
   rc = PARSE_driver  (a_nscrp, *r_nline, x_vers, x_verb, x_spec, x_recd, x_desc, x_meth, x_args, x_test, x_expe, x_retn, x_which);
   debug_uver   ylog_uvalue  ("parse"     , rc);
   --rce;  if (rc < 0)  {
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(write output)----------------*/
   if (a_good == 'y') {
      switch (a_runtype) {
      case G_RUN_UPDATE :
         rc = CONV_driver (p_conv, a_conv, x_verb, x_desc, x_meth, x_args, x_test, x_expe, x_retn, x_stage, x_which, *r_ditto, *r_major, *r_minor, r_share, r_select);
         break;
      case G_RUN_CREATE:  case  G_RUN_DEBUG :
         rc = CODE_driver (p_code, a_nscrp, a_main, a_code, a_wave, a_runtype, b_last, *r_nline, x_verb, x_desc, x_meth, x_args, x_test, x_expe, x_retn, x_stage, x_which, *r_ditto, *r_dittoing, *r_dtarget, *r_dline, *r_major, *r_minor, r_share, r_select);
         break;
      }
      debug_uver   ylog_uvalue  ("output"    , rc);
      --rce;  if (rc < 0)  {
         debug_uver   ylog_uexitr  (__FUNCTION__, rce);
         return rce;
      }
   }
   /*---(save last)-------------------*/
   if (strcmp (x_verb, "DITTO") != 0)  strlcpy (b_last, x_verb, LEN_LABEL);
   /*---(save-back)-------------------*/
   PROG__save_back (x_recd, x_verb, p_conv, p_code, x_spec, x_vers, x_desc, x_meth, x_args, x_test, x_expe, x_retn, x_stage, *r_ditto, *r_major, *r_minor, x_which);
   /*---(complete)-----------------------*/
   debug_uver   ylog_uexit   (__FUNCTION__);
   return 1;
}

char
PROG_dusk                (char a_good, char a_runtype, char a_replace, char a_nscrp [LEN_TITLE], FILE **r_scrp, int a_nline, char a_nmain [LEN_TITLE], FILE **r_main, char a_ncode [LEN_TITLE], FILE **r_code, char a_nwave [LEN_TITLE], FILE **r_wave, char a_nconv [LEN_TITLE], FILE **r_conv, char a_share, char a_select)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        t           [LEN_RECD]  = "";
   /*---(header)-------------------------*/
   debug_uver   ylog_uenter  (__FUNCTION__);
   /*---(close files)--------------------*/
   rc = READ_close (__FILE__, __FUNCTION__, __LINE__, a_nscrp, r_scrp);
   --rce;  switch (a_runtype) {
   case G_RUN_CREATE : case G_RUN_DEBUG :
      rc = CODE_footer  (a_good, a_nscrp, a_nmain, r_main, a_ncode, r_code, a_nwave, r_wave, a_nline, a_share, a_select, '-');
      break;
   case G_RUN_UPDATE :
      rc = CONV_footer  (a_good, r_conv, a_nscrp, a_nconv);
      break;
   default  :
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   debug_uver   ylog_uvalue  ("footer"    , rc);
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
   debug_uver   ylog_uexit   (__FUNCTION__);
   return 0;
}

char
PROG_loop               (int a_argc, char *a_argv [])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        x_good      =  'y';
   int         x_error     =    0;
   /*---(header)-------------------------*/
   debug_uver   ylog_uenter  (__FUNCTION__);
   /*---(debugging)----------------------*/
   rc = PROG_urgents (a_argc, a_argv);
   debug_uver   ylog_uvalue   ("urgents"   , rc);
   --rce;  if (rc <  0) { 
      PROG_shutdown ();
      return rce;
   }
   /*---(initialization)-----------------*/
   rc = PROG_startup (a_argc, a_argv);
   debug_uver   ylog_uvalue   ("startup"   , rc);
   --rce;  if (rc <  0) {
      PROG_shutdown ();
      return rce;
   }
   /*---(main-loop)----------------------*/
   rc = PROG_dawn  (my.run_type, my_loc.l_scrp, &(my_loc.l_SCRP), &(my_run.r_nline), my_loc.l_main, &(my_loc.l_MAIN), my_loc.l_code, &(my_loc.l_CODE), my_loc.l_wave, &(my_loc.l_WAVE), my_loc.l_conv, &(my_loc.l_CONV), &(my_run.r_share), &(my_run.r_select));
   debug_uver   ylog_uvalue   ("dawn"      , rc);
   --rce;  if (rc <  0) {
      PROG_shutdown ();
      return rce;
   }
   /*---(main-loop)----------------------*/
   debug_uver   ylog_uenter  (__FUNCTION__);
   debug_uver   ylog_unote   ("entering main processing loop");
   /*---(main)---------------------------*/
   while (1) {
      debug_uver   ylog_uchar   ("x_good"    , x_good);
      rc = PROG_driver (x_good, my.run_type, my_loc.l_scrp, &(my_run.r_nline), &(my_loc.l_SCRP), my_loc.l_MAIN, my_loc.l_CODE, my_loc.l_WAVE, my_loc.l_CONV, my_run.r_last, &(my_run.r_nrecd), &(my_run.r_under), &(my_cur.c_ditto), &(my_run.r_dittoing), &(my_run.r_dtarget), &(my_run.r_dstart), &(my_run.r_dline), &(my_cur.c_major), &(my_cur.c_minor), &(my_run.r_share), &(my_run.r_select));
      debug_uver   ylog_uvalue  ("driver"    , rc);
      if (rc == 0)  break;  /* end-of-file */
      if (rc <  0) {
         x_good = '-';
         ++x_error;
      }
   }
   debug_uver   ylog_unote   ("exiting main processing loop");
   debug_uver   ylog_uexit   (__FUNCTION__);
   /*---(dusk)---------------------------*/
   rc = PROG_dusk  (x_good, my.run_type, my.replace, my_loc.l_scrp, &(my_loc.l_SCRP), my_run.r_nline, my_loc.l_main, &(my_loc.l_MAIN), my_loc.l_code, &(my_loc.l_CODE), my_loc.l_wave, &(my_loc.l_WAVE), my_loc.l_conv, &(my_loc.l_CONV), my_run.r_share, my_run.r_select);
   debug_uver   ylog_uvalue   ("dusk"      , rc);
   --rce;  if (rc <  0) {
      PROG_shutdown ();
      return rce;
   }
   /*---(complete)-----------------------*/
   debug_uver   ylog_uexit   (__FUNCTION__);
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
   debug_uver   ylog_uenter  (__FUNCTION__);
   debug_uver   ylog_uexit   (__FUNCTION__);
   return 0;
}

char             /* [------] drive the program closure activities ------------*/
PROG_shutdown           (void)
{
   /*---(stage-check)--------------------*/
   /*> yURG_stage_check (YURG_END);                                                   <*/
   /*---(header)-------------------------*/
   debug_uver   ylog_uenter   (__FUNCTION__);
   ylog_uclose  ();
   yerr_uclose  ();
   PROG__end    ();
   /*---(complete)-----------------------*/
   debug_uver   ylog_uexit    (__FUNCTION__);
   return 0;
}



/*====================------------------------------------====================*/
/*===----                   helpers for unit testing                   ----===*/
/*====================------------------------------------====================*/
static void      o___UNITTEST________________o (void) {;}

char
PROG__unit_bigclean     (void)
{
   /*---(unit related)-------------------*/
   system ("rm    -f /tmp/apate.unit        > /dev/null   2>&1");
   system ("rm    -f /tmp/apate.sunit       > /dev/null   2>&1");
   system ("rm    -f /tmp/apatey.sunit      > /dev/null   2>&1");
   system ("rm    -f /tmp/linked.unit       > /dev/null   2>&1");
   system ("rm    -f /tmp/linked.sunit      > /dev/null   2>&1");
   system ("rm    -f /tmp/apate-a.unit      > /dev/null   2>&1");
   system ("rm    -f /tmp/apate_a.unit      > /dev/null   2>&1");
   system ("rmdir -f /tmp/apate_dir.unit    > /dev/null   2>&1");
   system ("rm    -f /tmp/khaos.unit        > /dev/null   2>&1");
   system ("rm    -f /tmp/gyges.unit        > /dev/null   2>&1");
   system ("rm    -f /tmp/hestia.unit       > /dev/null   2>&1");
   /*---(code related)-------------------*/
   system ("rm    -f /tmp/apate.h           > /dev/null   2>&1");
   system ("rm    -f /tmp/apate.c           > /dev/null   2>&1");
   system ("rm    -f /tmp/apate_unit.c      > /dev/null   2>&1");
   system ("rm    -f /tmp/apate_unit.cs     > /dev/null   2>&1");
   system ("rm    -f /tmp/apate_unit.o      > /dev/null   2>&1");
   system ("rm    -f /tmp/apate_unit.tmp    > /dev/null   2>&1");
   system ("rm    -f /tmp/apate.unit.old    > /dev/null   2>&1");
   system ("rm    -f /tmp/apate.wave        > /dev/null   2>&1");
   /*---(master related)-----------------*/
   system ("rm    -f /tmp/master.h          > /dev/null   2>&1");
   system ("rm    -f /tmp/master.unit       > /dev/null   2>&1");
   system ("rm    -f /tmp/master.unit.old   > /dev/null   2>&1");
   system ("rm    -f /tmp/master.globals    > /dev/null   2>&1");
   /*---(output)-------------------------*/
   system ("rm    -f /tmp/apate.urun        > /dev/null   2>&1");
   system ("rm    -f /tmp/apate_errors.txt  > /dev/null   2>&1");
   system ("rm    -f /tmp/apate_unit        > /dev/null   2>&1");
   /*---(done)---------------------------*/
   return 0;
}

char       /*----: set up program urgents/debugging --------------------------*/
PROG__unit_quiet   (void)
{
   char        rce         =  -10;
   char        rc          =    0;
   char        x_argc      =    3;
   char       *x_argv [3]  = { "koios_unit", "--verify", "apate" };
   /*---(prepare)------------------------*/
   system ("touch /tmp/apate.unit           2> /dev/null");
   /*---(debugging)----------------------*/
   rc = PROG_urgents (x_argc, x_argv);
   debug_uver   ylog_uvalue   ("urgents"   , rc);
   --rce;  if (rc <  0) { 
      PROG_shutdown ();
      return rce;
   }
   /*---(initialization)-----------------*/
   rc = PROG_startup (x_argc, x_argv);
   debug_uver   ylog_uvalue   ("startup"   , rc);
   --rce;  if (rc <  0) {
      PROG_shutdown ();
      return rce;
   }
   /*---(complete)-----------------------*/
   system ("rm    /tmp/apate.unit           2> /dev/null");
   return 0;
}

char       /*----: set up program urgents/debugging --------------------------*/
PROG__unit_loud    (void)
{
   char        rce         =  -10;
   char        rc          =    0;
   char        x_argc      =    4;
   char       *x_argv [4]  = { "koios_debug", "@@kitchen" , "--verify", "apate"};
   /*---(prepare)------------------------*/
   system ("touch /tmp/apate.unit           2> /dev/null");
   /*---(debugging)----------------------*/
   rc = PROG_urgents (x_argc, x_argv);
   debug_uver   ylog_uvalue   ("urgents"   , rc);
   --rce;  if (rc <  0) { 
      PROG_shutdown ();
      return rce;
   }
   /*---(initialization)-----------------*/
   rc = PROG_startup (x_argc, x_argv);
   debug_uver   ylog_uvalue   ("startup"   , rc);
   --rce;  if (rc <  0) {
      PROG_shutdown ();
      return rce;
   }
   /*---(debug)--------------------------*/
   /*> printf ("which !!  %s\n", ylog_uwhich ());                                     <* 
    *> printf ("which !!  %s\n", mylog_lstd);                                         <* 
    *> printf ("my.debug  %c\n", my.debug);                                           <* 
    *> printf ("ulines    %d\n", ylog_ulines());                                      <*/
   /*> system ("rm    /tmp/apate.unit           2> /dev/null");                       <*/
   /*---(complete)-----------------------*/
   return 0;
}

char       /*----: set up program urgents/debugging --------------------------*/
PROG__unit_end     (void)
{
   PROG_shutdown   ();
   return 0;
}







/*===============================[[ end code ]]===============================*/
