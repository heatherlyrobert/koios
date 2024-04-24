/*===============================[[ beg-code ]]===============================*/
#include    "koios.h"        /* LOCAL  : main header                          */

#include    <yLOG_uver.h>

/*> tDEBUG      debug;                                                                <*/
tGLOBALS    my;


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
   DEBUG_UVER   yLOG_uenter(__FUNCTION__);
   /*---(versioning)------------------*/
   DEBUG_UVER   yLOG_uinfo    ("gregg"   , PROG_version      ());
   DEBUG_UVER   yLOG_uinfo    ("purpose" , P_PURPOSE);
   DEBUG_UVER   yLOG_uinfo    ("namesake", P_NAMESAKE);
   DEBUG_UVER   yLOG_uinfo    ("heritage", P_HERITAGE);
   DEBUG_UVER   yLOG_uinfo    ("imagery" , P_IMAGERY);
   DEBUG_UVER   yLOG_unote    ("custom core");
   DEBUG_UVER   yLOG_uinfo    ("yUNIT"   , yUNIT_version     ());
   /*---(complete)-----------------------*/
   DEBUG_UVER   yLOG_uexit (__FUNCTION__);
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
   if (strcmp (a_argv [0], "koios_debug") == 0) {
      my.debug = 'y';
   }
   /*---(process urgents)----------------*/
   rc = PROG__header ();
   DEBUG_UVER   yLOG_uvalue   ("header"    , rc);
   --rce;  if (rc < 0) {
      DEBUG_UVER   yLOG_uexitr   (__FUNCTION__, rce);
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
   DEBUG_UVER   yLOG_uenter  (__FUNCTION__);
   /*---(files)--------------------------*/
   strlcpy  (my.n_scrp, "", LEN_TITLE);  my.f_scrp = NULL;
   strlcpy  (my.n_code, "", LEN_TITLE);  my.f_code = NULL;
   strlcpy  (my.n_main, "", LEN_TITLE);  my.f_main = NULL;
   strlcpy  (my.n_wave, "", LEN_TITLE);  my.f_wave = NULL;
   strlcpy  (my.n_conv, "", LEN_TITLE);  my.f_conv = NULL;
   my.driver = '-';
   strlcpy  (my.last     , "", LEN_LABEL);
   my.noise = '-';
   VERB_init  ();
   DITTO_init ();
   REUSE_init ();
   CODE_init  ();
   CONV_init  ();
   getcwd (my.cwd, LEN_PATH);
   /*---(complete)-----------------------*/
   DEBUG_UVER   yLOG_uexit   (__FUNCTION__);
   return 0;
}

char
PROG__file              (char a_name [LEN_TITLE], char r_base [LEN_TITLE], char r_ext [LEN_TERSE])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        x_proj      [LEN_LABEL]  = "";
   char        x_base      [LEN_TITLE]  = "";
   char        x_unit      [LEN_TITLE]  = "";
   char        x_ext       [LEN_TERSE] = "";
   int         l           =    0;
   char       *x_valid     = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789_.";
   int         i           =    0;
   tSTAT       s;
   char       *p           = NULL;
   tSTAT       r;
   char        t           [LEN_FULL]  = "";
   /*---(header)-------------------------*/
   DEBUG_UVER   yLOG_uenter  (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_base != NULL)  strcpy (r_base, "");
   if (r_ext  != NULL)  strcpy (r_ext , "");
   /*---(defense)------------------------*/
   DEBUG_UVER  yLOG_upoint  ("a_name"    , a_name);
   --rce;  if (a_name == NULL) {
      /*> yURG_err ('f', "script name can not be null");                              <*/
      DEBUG_UVER  yLOG_uexitr(__FUNCTION__, rce);
      return rce;
   }
   DEBUG_UVER  yLOG_uinfo   ("a_name"    , a_name);
   DEBUG_UVER  yLOG_upoint  ("r_base"    , r_base);
   --rce;  if (r_base == NULL) {
      DEBUG_UVER  yLOG_uexitr(__FUNCTION__, rce);
      return rce;
   }
   DEBUG_UVER  yLOG_upoint  ("r_ext"     , r_ext);
   --rce;  if (r_ext  == NULL) {
      DEBUG_UVER  yLOG_uexitr(__FUNCTION__, rce);
      return rce;
   }
   /*---(check length)-------------------*/
   l = strlen (a_name);
   DEBUG_UVER  yLOG_uvalue  ("l"         , l);
   --rce;  if (l <= 0) {
      /*> yURG_err ('f', "script name can not be blank/empty");                       <*/
      DEBUG_UVER  yLOG_uexitr(__FUNCTION__, rce);
      return rce;
   }
   /*---(check for path)-----------------*/
   --rce;  if (strchr (a_name, '/') != NULL) {
      /*> yURG_err ('f', "script name ¶%s¶ can not include a path (abs or rel)", a_name);   <*/
      DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(check for hidden)---------------*/
   --rce;  if (a_name [0] == '.') {
      /*> yURG_err ('f', "script name ¶%s¶ can not be hidden file (.)", a_name);      <*/
      DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(check characters)---------------*/
   --rce;  for (i = 0; i < l; ++i) {
      if (strchr (YSTR_ALNUM "_.", a_name [i]) != NULL)  continue;
      /*> yURG_err ('f', "script name ¶%s¶ can not have a '%c' as character %d", a_name, a_name [i], i);   <*/
      DEBUG_UVER  yLOG_uchar ("bad char"  , a_name [i]);
      DEBUG_UVER  yLOG_uexitr(__FUNCTION__, rce);
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
   DEBUG_UVER    yLOG_uvalue  ("x_unit"    , rc);
   rc = lstat (x_unit, &s);
   DEBUG_UVER    yLOG_uvalue  ("stat"      , rc);
   --rce;  if (rc < 0) {
      sprintf (x_unit, "%s.sunit", x_base);
      DEBUG_UVER    yLOG_uvalue  ("x_unit"    , rc);
      rc = lstat (x_unit, &s);
      DEBUG_UVER    yLOG_uvalue  ("stat"      , rc);
      if (rc < 0) {
         /*> yURG_err ('f', "script name ¶%s¶ can not be found as .unit or .sunit", a_name);   <*/
         DEBUG_UVER    yLOG_unote   ("can not find source either .unit or .sunit");
         DEBUG_UVER    yLOG_uexitr (__FUNCTION__, rce);
         return rce;
      } else {
         strcpy (x_ext, ".sunit");
      }
   } else {
      strcpy (x_ext, ".unit");
   }
   --rce;  if (S_ISDIR (s.st_mode))  {
      /*> yURG_err ('f', "script name ¶%s¶ refers to a directory, illegal", a_name);   <*/
      DEBUG_UVER    yLOG_unote   ("can not use a directory");
      DEBUG_UVER    yLOG_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   --rce;  if (S_ISLNK (s.st_mode))  {
      DEBUG_UVER    yLOG_unote   ("is a link, figure it out");
      if (strcmp (x_ext, ".sunit") == 0) {
         /*> yURG_err ('f', "script name ¶%s¶ is a .sunit can can not be a symlink", a_name);   <*/
         printf ("FATAL, .sunit can not be a symlink\n");
         DEBUG_UVER    yLOG_unote   ("can not use a symlink");
         DEBUG_UVER    yLOG_uexitr  (__FUNCTION__, rce);
         return rce;
      } else {
         rc = readlink (x_unit, t, LEN_FULL);
         DEBUG_UVER    yLOG_uvalue  ("readlink"  , rc);
         if (rc < 0) {
            DEBUG_UVER    yLOG_uexitr (__FUNCTION__, rce);
            return rce;
         }
         DEBUG_UVER  yLOG_uinfo   ("t"         , t);
         l = strlen (t);
         DEBUG_UVER  yLOG_uvalue  ("l"         , l);
         if (l < 7) {
            DEBUG_UVER    yLOG_uexitr (__FUNCTION__, rce);
            return rce;
         }
         DEBUG_UVER  yLOG_uinfo   ("suffix"    , t + l - 6);
         if (strcmp (t + l - 6, ".sunit") != 0) {
            /*> yURG_err ('f', "script name ¶%s¶ is a symlink to ¶%s¶, only .sunit is legal", a_name, t);   <*/
            DEBUG_UVER    yLOG_uexitr (__FUNCTION__, rce);
            return rce;
         }
         rc = stat (t, &r);
         DEBUG_UVER    yLOG_uvalue  ("stat"      , rc);
         if (rc < 0) {
            /*> yURG_err ('f', "script name ¶%s¶ is a symlink to .sunit ¶%s¶, but source does not exist", a_name, t);   <*/
            DEBUG_UVER    yLOG_uexitr (__FUNCTION__, rce);
            return rce;
         }
      }
   }
   else if (!S_ISREG (s.st_mode)) {
      /*> yURG_err ('f', "script name ¶%s¶ is not a regular file, illegal", a_name);   <*/
      DEBUG_UVER    yLOG_unote   ("can only use regular file");
      DEBUG_UVER    yLOG_uexitr  (__FUNCTION__, rce);
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
   DEBUG_UVER    yLOG_uvalue  ("stat"      , rc);
   if (rc < 0)   system  ("touch master.h");
   /*---(save back)----------------------*/
   strncpy (my.n_proj, x_proj, LEN_LABEL);
   /*> printf ("%s\n", my.n_proj);                                                    <*/
   DEBUG_UVER  yLOG_uinfo   ("n_proj"    , my.n_proj);
   strncpy (r_base, x_base, LEN_TITLE);
   DEBUG_UVER  yLOG_uinfo   ("n_base"    , r_base);
   strncpy (r_ext , x_ext , LEN_TERSE);
   DEBUG_UVER  yLOG_uinfo   ("n_ext"     , r_ext);
   /*---(complete)-----------------------*/
   DEBUG_UVER   yLOG_uexit   (__FUNCTION__);
   return 0;
}

char
PROG__args              (int a_argc, char *a_argv [], char *r_runtype, char *r_noise, char *r_replace, char r_base [LEN_TITLE], char r_ext [LEN_SHORT])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        x_runtype   = G_RUN_CREATE;
   char        x_noise     =  '-';
   char        x_replace   = G_RUN_DEFAULT;
   char        x_proj      [LEN_LABEL]  = "";
   char        x_base      [LEN_TITLE]  = "";
   char        x_ext       [LEN_TERSE] = "";
   int         i           =    0;
   char       *a           = NULL;
   int         x_total     =    0;
   int         x_args      =    0;
   /*---(begin)--------------------------*/
   DEBUG_UVER  yLOG_uenter  (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_runtype != NULL)  *r_runtype = '·';
   if (r_replace != NULL)  *r_replace = '·';
   if (r_base    != NULL)  strcpy (r_base, "");
   if (r_ext     != NULL)  strcpy (r_ext , "");
   /*> yURG_all_off ();                                                               <*/
   /*---(defenses)-----------------------*/
   DEBUG_UVER  yLOG_upoint  ("a_argv" , a_argv);
   --rce;  if (a_argv == NULL) {
      DEBUG_UVER    yLOG_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(process)------------------------*/
   --rce;  for (i = 1; i < a_argc; ++i) {
      a = a_argv[i];
      ++x_total;
      if (a[0] == '@')  continue;
      DEBUG_UVER  yLOG_uinfo   ("cli arg", a);
      ++x_args;
      /*---(better testing)--------------*/
      if      (strncmp (a, "--verify"     , 10) == 0)  { x_runtype = G_RUN_UPDATE;  x_noise = '-'; }
      else if (strncmp (a, "--cverify"    , 10) == 0)  { x_runtype = G_RUN_UPDATE;  x_noise = 'c'; }
      else if (strncmp (a, "--everify"    , 10) == 0)  { x_runtype = G_RUN_UPDATE;  x_noise = 'e'; }
      else if (strncmp (a, "--Everify"    , 10) == 0)  { x_runtype = G_RUN_UPDATE;  x_noise = 'E'; }
      else if (strncmp (a, "--vverify"    , 10) == 0)  { x_runtype = G_RUN_UPDATE;  x_noise = 'v'; }
      /*---(better conversion)-----------*/
      else if (strncmp (a, "--conv"       , 10) == 0)  { x_runtype = G_RUN_UPDATE;  x_replace = G_RUN_REPLACE;  x_noise = '-'; }
      else if (strncmp (a, "--cconv"      , 10) == 0)  { x_runtype = G_RUN_UPDATE;  x_replace = G_RUN_REPLACE;  x_noise = 'c'; }
      else if (strncmp (a, "--econv"      , 10) == 0)  { x_runtype = G_RUN_UPDATE;  x_replace = G_RUN_REPLACE;  x_noise = 'e'; }
      else if (strncmp (a, "--Econv"      , 10) == 0)  { x_runtype = G_RUN_UPDATE;  x_replace = G_RUN_REPLACE;  x_noise = 'E'; }
      else if (strncmp (a, "--vconv"      , 10) == 0)  { x_runtype = G_RUN_UPDATE;  x_replace = G_RUN_REPLACE;  x_noise = 'v'; }
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
      else if (strncmp (a, "--update"     , 10) == 0)  { x_runtype = G_RUN_UPDATE;  x_replace = G_RUN_REPLACE; }
      /*---(unknown arg)-----------------*/
      else if (strncmp (a, "-"            ,  1) == 0)  {
         /*> yURG_err ('f', "argument ¶%s¶ is not recognized", a);                    <*/
         DEBUG_UVER  yLOG_uexitr (__FUNCTION__, rce);
         return rce;
      }
      /*---(file name)-------------------*/
      else {
         rc = PROG__file (a, x_base, x_ext);
         if (rc < 0) {
            DEBUG_UVER  yLOG_unote  ("base name is invalid or not found");
            DEBUG_UVER  yLOG_uexitr (__FUNCTION__, rce);
            return rce;
         }
      }
      /*---(set noise)----------------------*/
      switch (x_noise) {
      case 'E' : 
         /*> yURG_err_tmp  (); yURG_err_live (); yURG_err_clear ();                   <*/
         break;
      case 'e' : 
         /*> yURG_err_std  (); yURG_err_live (); yURG_err_clear ();                   <*/
         break;
      case 'v' : 
         /*> yURG_msg_std  (); yURG_msg_live (); yURG_msg_clear ();                   <*/
         /*> yURG_err_std  (); yURG_err_live (); yURG_err_clear ();                   <*/
         break;
      }
      /*---(done)------------------------*/
   }
   DEBUG_UVER  yLOG_uvalue ("entries"   , x_total);
   DEBUG_UVER  yLOG_uvalue ("arguments" , x_args);
   if (x_args == 0) {
      DEBUG_UVER  yLOG_unote  ("no arguments identified");
   }
   DEBUG_UVER  yLOG_uchar  ("run_type"  , x_runtype);
   DEBUG_UVER  yLOG_uinfo  ("basename"  , x_base);
   /*---(defense)------------------------*/
   DEBUG_UVER   yLOG_uinfo   ("basename"  , x_base);
   --rce;  if (strcmp (x_base, "") == 0) {
      /*> yURG_err ('f', "script name/base was not provided on command line");        <*/
      DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(defense)------------------------*/
   --rce;  if (strcmp (x_ext, ".sunit") == 0) {
      if (x_runtype != G_RUN_UPDATE) {
         /*> yURG_err ('f', "can not compile ¶%s¶ as .sunit, must compile in linked .unit location", x_base);   <*/
         DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
         return rce;
      }
   }
   /*---(save-back)----------------------*/
   if (r_runtype != NULL)  *r_runtype = x_runtype;
   if (r_noise   != NULL)  *r_noise   = x_noise;
   if (r_replace != NULL)  *r_replace = x_replace;
   if (r_base    != NULL)  strlcpy (r_base, x_base, LEN_TITLE);
   if (r_base    != NULL)  strlcpy (r_base, x_base, LEN_TITLE);
   if (r_ext     != NULL)  strlcpy (r_ext , x_ext , LEN_TERSE);
   /*---(complete)-----------------------*/
   DEBUG_UVER  yLOG_uexit (__FUNCTION__);
   return 0;
}

char
PROG__begin             (void)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   /*---(header)-------------------------*/
   DEBUG_UVER   yLOG_uenter  (__FUNCTION__);
   /*---(create names)-------------------*/
   snprintf (my.n_scrp, LEN_TITLE, "%s%s"            , my.n_base, my.n_ext);
   snprintf (my.n_main, LEN_TITLE, "%s_unit.tmp"     , my.n_base);
   snprintf (my.n_code, LEN_TITLE, "%s_unit.cs"      , my.n_base);
   snprintf (my.n_wave, LEN_TITLE, "%s.wave"         , my.n_base);
   snprintf (my.n_conv, LEN_TITLE, "%s%s.new"        , my.n_base, my.n_ext);
   /*---(special for debug)--------------*/
   if (my.run_type == G_RUN_DEBUG)   snprintf (my.n_code, LEN_TITLE, "%s_unit.c"      , my.n_base);
   /*---(initialize)---------------------*/
   my.n_line    = 0;
   my.n_recd    = 0;
   my.dittoing  = '-';
   my.dmark     = '-';
   my.ditto     = -1;
   /*---(complete)-----------------------*/
   DEBUG_UVER   yLOG_uexit   (__FUNCTION__);
   return 0;
}

char
PROG_startup            (int a_argc, char *a_argv [])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   /*---(header)----------------------*/
   /*> yURG_stage_check (YURG_BEG);                                                   <*/
   DEBUG_UVER  yLOG_uenter  (__FUNCTION__);
   /*---(initialize)---------------------*/
   rc = PROG__init   ();
   DEBUG_UVER   yLOG_uvalue   ("init"      , rc);
   --rce;  if (rc < 0) {
      DEBUG_UVER   yLOG_uexitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(arguments)----------------------*/
   rc = PROG__args   (a_argc, a_argv, &(my.run_type), &(my.noise), &(my.replace), my.n_base, my.n_ext);
   DEBUG_UVER   yLOG_uvalue   ("args"      , rc);
   --rce;  if (rc < 0) {
      DEBUG_UVER   yLOG_uexitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(begin)--------------------------*/
   rc = PROG__begin  ();
   DEBUG_UVER   yLOG_uvalue   ("begin"     , rc);
   --rce;  if (rc < 0) {
      DEBUG_UVER   yLOG_uexitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(complete)-----------------------*/
   DEBUG_UVER  yLOG_uexit (__FUNCTION__);
   /*> yURG_stage_check (YURG_MID);                                                   <*/
   return rc;
}



/*====================------------------------------------====================*/
/*===----                        program execution                     ----===*/
/*====================------------------------------------====================*/
static void      o___EXECUTION_______________o (void) {;}

char
PROG_dawn                (cchar a_runtype, cchar a_nscrp [LEN_TITLE], FILE **r_scrp, int *r_line, cchar a_nmain [LEN_TITLE], FILE **r_main, cchar a_ncode [LEN_TITLE], FILE **r_code, cchar a_nwave [LEN_TITLE], FILE **r_wave, cchar a_nconv [LEN_TITLE], FILE **r_conv, char *r_cshare)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   /*---(header)-------------------------*/
   DEBUG_UVER   yLOG_uenter  (__FUNCTION__);
   /*---(open incomming script)----------*/
   rc = READ_open      (a_nscrp, 'r', r_scrp, r_line);
   DEBUG_UVER   yLOG_uvalue  ("script"    , rc);
   --rce;  if (rc < 0) {
      PROG_shutdown ();
      DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(open output files)--------------*/
   --rce;  switch (a_runtype) {
   case G_RUN_CREATE : case G_RUN_DEBUG :
      rc = CODE_header (a_nscrp, a_nmain, r_main, a_ncode, r_code, a_nwave, r_wave, r_cshare);
      break;
   case G_RUN_UPDATE :
      rc = CONV_header  (a_nconv, r_conv, r_cshare);
      break;
   default  :
      READ_close (r_scrp);
      PROG_shutdown ();
      DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
      return rce;
      break;
   }
   DEBUG_UVER   yLOG_uvalue  ("output"    , rc);
   --rce;  if (rc <  0) {
      READ_close (r_scrp);
      PROG_shutdown ();
      return rc;
   }
   /*---(open output files)--------------*/
   if (strcmp (a_nscrp, "master.unit") != 0) {
      rc = REUSE_import  ("master.globals");
      DEBUG_UVER   yLOG_uvalue  ("globals"   , rc);
      /*> --rce;  if (rc <  0) {                                                      <* 
       *>    READ_close (r_scrp);                                                     <* 
       *>    READ_close (r_main);                                                     <* 
       *>    READ_close (r_code);                                                     <* 
       *>    READ_close (r_wave);                                                     <* 
       *>    PROG_shutdown ();                                                        <* 
       *>    return rc;                                                               <* 
       *> }                                                                           <*/
   }
   /*---(complete)-----------------------*/
   DEBUG_UVER   yLOG_uexit   (__FUNCTION__);
   return 0;
}

char
PROG_terminate           (FILE **r_scrp, FILE **r_main, FILE **r_code, FILE **r_wave, FILE **r_conv)
{
   DEBUG_UVER   yLOG_uenter  (__FUNCTION__);
   READ_close (r_scrp);
   READ_close (r_main);
   READ_close (r_code);
   READ_close (r_wave);
   DEBUG_UVER   yLOG_uexit   (__FUNCTION__);
   PROG_shutdown ();
   return 0;
}

char
PROG_driver              (char a_good, cchar a_runtype, cchar a_nscrp [LEN_TITLE], int *r_nline, FILE **b_scrp, FILE *a_main, FILE *a_code, FILE *a_wave, FILE *a_conv, char b_last [LEN_LABEL], int *r_nrecd, char *r_dittoing, char *r_mark, char *r_dmark, int *r_ditto, int *r_dline, char *r_share, char *r_cshare)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        x_recd      [LEN_RECD]  = "";
   char        x_spec      =  '-';
   char        x_vers      =    0;
   char        x_verb      [LEN_LABEL] = "";
   char        x_desc      [LEN_LONG]  = "";
   char        x_meth      [LEN_HUND]  = "";
   char        x_args      [LEN_FULL]  = "";
   char        x_test      [LEN_LABEL] = "";
   char        x_expe      [LEN_RECD]  = "";
   char        x_retn      [LEN_FULL]  = "";
   char        x_stage     [LEN_SHORT] = "";
   char      (*p_conv) (void);
   char      (*p_code) (void);
   /*---(header)-------------------------*/
   DEBUG_UVER   yLOG_uenter  (__FUNCTION__);
   /*---(defaulting)------------------*/
   rc = PARSE_default (my.verb, &(my.spec), &(my.p_conv), &(my.p_code), my.stage, &(my.vers), my.desc, my.meth, my.args, my.test, my.expe, my.retn, &(my.mark), &(my.share));
   /*---(read next)-------------------*/
   rc = READ_next     (b_scrp, r_nline, r_dittoing, r_dmark, r_ditto, r_dline, r_nrecd, x_recd);
   DEBUG_UVER   yLOG_uvalue  ("read"      , rc);
   if (rc == 0) {
      DEBUG_UVER   yLOG_unote   ("end of file");
      DEBUG_UVER   yLOG_uexit   (__FUNCTION__);
      return 0;
   }
   --rce;  if (rc < 0)  {
      DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(check flow)------------------*/
   rc = PARSE_prep    (b_scrp, a_nscrp, *r_nline, a_runtype, x_recd, x_verb, &x_spec, &p_conv, &p_code, x_stage, &x_vers, x_desc, x_expe, r_dittoing, r_mark, r_dmark, r_ditto, r_dline, r_share, r_cshare);
   DEBUG_UVER   yLOG_uvalue  ("flow"      , rc);
   --rce;  if (rc < 0)  {
      DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(parse)-----------------------*/
   rc = PARSE_driver  (a_nscrp, *r_nline, x_vers, x_verb, x_spec, x_recd, x_desc, x_meth, x_args, x_test, x_expe, x_retn);
   DEBUG_UVER   yLOG_uvalue  ("parse"     , rc);
   --rce;  if (rc < 0)  {
      DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(write output)----------------*/
   if (a_good == 'y') {
      switch (a_runtype) {
      case G_RUN_UPDATE :
         rc = CONV_driver (p_conv, a_conv, x_verb, x_desc, x_meth, x_args, x_test, x_expe, x_retn, *r_share, *r_mark, x_stage, r_cshare);
         break;
      case G_RUN_CREATE:  case  G_RUN_DEBUG :
         rc = CODE_driver (p_code, a_nscrp, a_main, a_code, a_wave, a_runtype, b_last, x_verb, x_desc, x_meth, x_args, x_test, x_expe, x_retn, x_stage, *r_dittoing, *r_mark, *r_dmark, *r_nline, *r_dline, *r_share, r_cshare);
         break;
      }
      DEBUG_UVER   yLOG_uvalue  ("output"    , rc);
      --rce;  if (rc < 0)  {
         DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
         return rce;
      }
   }
   /*---(save last)-------------------*/
   if (strcmp (x_verb, "DITTO") != 0)  strlcpy (b_last, x_verb, LEN_LABEL);
   /*---(save-back)-------------------*/
   strlcpy (my.recd  , x_recd    , LEN_RECD);
   strlcpy (my.verb  , x_verb    , LEN_LABEL);
   my.spec     = x_spec;
   my.p_conv   = p_conv;
   my.p_code   = p_code;
   strlcpy (my.stage , x_stage   , LEN_LABEL);
   my.vers     = x_vers;
   strlcpy (my.desc  , x_desc    , LEN_LONG);
   strlcpy (my.meth  , x_meth    , LEN_HUND);
   strlcpy (my.args  , x_args    , LEN_FULL);
   strlcpy (my.test  , x_test    , LEN_LABEL);
   strlcpy (my.expe  , x_expe    , LEN_RECD);
   strlcpy (my.retn  , x_retn    , LEN_FULL);
   /*---(complete)-----------------------*/
   DEBUG_UVER   yLOG_uexit   (__FUNCTION__);
   return 1;
}

char
PROG_dusk                (char a_good, cchar a_runtype, cchar a_replace, cchar a_nscrp [LEN_TITLE], FILE **r_scrp, cchar a_nmain [LEN_TITLE], FILE **r_main, cchar a_ncode [LEN_TITLE], FILE **r_code, cchar a_nwave [LEN_TITLE], FILE **r_wave, cchar a_nconv [LEN_TITLE], FILE **r_conv, cchar a_cshare)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        t           [LEN_RECD]  = "";
   /*---(header)-------------------------*/
   DEBUG_UVER   yLOG_uenter  (__FUNCTION__);
   /*---(close files)--------------------*/
   rc = READ_close     (r_scrp);
   switch (a_runtype) {
   case G_RUN_CREATE : case G_RUN_DEBUG :
      rc = CODE_footer  (a_good, a_nscrp, a_nmain, r_main, a_ncode, r_code, a_nwave, r_wave, a_cshare);
      break;
   case G_RUN_UPDATE :
      rc = CONV_footer  (a_good, r_conv, a_nscrp, a_nconv);
      break;
   }
   DEBUG_UVER   yLOG_uvalue  ("footer"    , rc);
   --rce;  if (rc <  0) {
      PROG_shutdown ();
      return rc;
   }
   /*---(handle replace)-----------------*/
   if (a_good == 'y' && a_replace == G_RUN_REPLACE) {
      sprintf (t, "cp -f %s %s.old", a_nscrp, a_nscrp);
      system  (t);
      printf  ("replacing script with update, saved original in .old\n");
      sprintf (t, "mv -f %s %s"   , a_nconv, a_nscrp);
      system  (t);
   }
   /*---(complete)-----------------------*/
   DEBUG_UVER   yLOG_uexit   (__FUNCTION__);
   return 0;
}



/*====================------------------------------------====================*/
/*===----                        wrapup functions                      ----===*/
/*====================------------------------------------====================*/
static void  o___WRAPUP__________o () { return; }


char                /* PURPOSE : shutdown program and free memory ------------*/
PROG__end          (void)
{
   DEBUG_UVER   yLOG_uenter  (__FUNCTION__);
   DEBUG_UVER   yLOG_uexit   (__FUNCTION__);
   return 0;
}

char             /* [------] drive the program closure activities ------------*/
PROG_shutdown           (void)
{
   /*---(stage-check)--------------------*/
   /*> yURG_stage_check (YURG_END);                                                   <*/
   /*---(header)-------------------------*/
   DEBUG_UVER   yLOG_uenter   (__FUNCTION__);
   PROG__end ();
   /*---(complete)-----------------------*/
   DEBUG_UVER   yLOG_uexit    (__FUNCTION__);
   DEBUG_UVER   yLOGS_end    ();
   return 0;
}



/*====================------------------------------------====================*/
/*===----                   helpers for unit testing                   ----===*/
/*====================------------------------------------====================*/
static void      o___UNITTEST________________o (void) {;}

char       /*----: set up program urgents/debugging --------------------------*/
PROG__unit_quiet   (void)
{
   char        rce         =  -10;
   char        rc          =    0;
   char        x_argc      =    3;
   char       *x_argv [3]  = { "koios", "--verify", "apate" };
   /*---(prepare)------------------------*/
   system ("touch apate.unit           2> /dev/null");
   /*---(debugging)----------------------*/
   rc = PROG_urgents (x_argc, x_argv);
   DEBUG_UVER   yLOG_uvalue   ("urgents"   , rc);
   --rce;  if (rc <  0) { 
      PROG_shutdown ();
      return rce;
   }
   /*---(initialization)-----------------*/
   rc = PROG_startup (x_argc, x_argv);
   DEBUG_UVER   yLOG_uvalue   ("startup"   , rc);
   --rce;  if (rc <  0) {
      PROG_shutdown ();
      return rce;
   }
   /*---(complete)-----------------------*/
   return 0;
}

char       /*----: set up program urgents/debugging --------------------------*/
PROG__unit_loud    (void)
{
   char        rce         =  -10;
   char        rc          =    0;
   char        x_argc      =    4;
   char       *x_argv [4]  = { "koios_unit", "@@kitchen" , "--verify", "apate"};
   /*---(prepare)------------------------*/
   system ("touch apate.unit           2> /dev/null");
   /*---(debugging)----------------------*/
   rc = PROG_urgents (x_argc, x_argv);
   DEBUG_UVER   yLOG_uvalue   ("urgents"   , rc);
   --rce;  if (rc <  0) { 
      PROG_shutdown ();
      return rce;
   }
   /*---(initialization)-----------------*/
   rc = PROG_startup (x_argc, x_argv);
   DEBUG_UVER   yLOG_uvalue   ("startup"   , rc);
   --rce;  if (rc <  0) {
      PROG_shutdown ();
      return rce;
   }
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
