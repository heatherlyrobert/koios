/*===============================[[ beg-code ]]===============================*/
#include    "koios.h"        /* LOCAL  : main header                          */

/*> tDEBUG      debug;                                                                <*/
tGLOBALS    my;



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
/*===----                        startup functions                     ----===*/
/*====================------------------------------------====================*/
static void  o___STARTUP_________o () { return; }

char         /*--> shutdown program ----------------------[ ------ [ ------ ]-*/
PROG_init          (void)
{
   /*---(header)-------------------------*/
   DEBUG_PROG   yLOG_enter   (__FUNCTION__);
   /*---(files)--------------------------*/
   strlcpy  (my.n_base, "", LEN_PATH);
   strlcpy  (my.n_scrp, "", LEN_PATH);
   strlcpy  (my.n_code, "", LEN_PATH);
   strlcpy  (my.n_main, "", LEN_PATH);
   strlcpy  (my.n_wave, "", LEN_PATH);
   strlcpy  (my.n_conv, "", LEN_PATH);
   my.driver    = '-';
   my.run_type  = G_RUN_CREATE;
   my.replace   = G_RUN_DEFAULT;
   strlcpy  (my.last     , "", LEN_LABEL);
   yURG_err_std ();
   SCRP__shared_purge ();
   CODE__shared_purge ();
   /*---(complete)-----------------------*/
   DEBUG_PROG   yLOG_exit    (__FUNCTION__);
   return 0;
}

char
PROG_file               (char *a_name)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        x_base      [LEN_PATH]  = "";
   char        x_unit      [LEN_PATH]  = "";
   int         l           =    0;
   char       *x_valid     = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789_/.";
   int         i           =    0;
   tSTAT       s;
   char       *p           = NULL;
   tSTAT       r;
   char        t           [LEN_FULL]  = "";
   /*---(header)-------------------------*/
   DEBUG_ARGS   yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   DEBUG_ARGS  yLOG_point   ("a_name"    , a_name);
   --rce;  if (a_name == NULL) {
      yURG_err ('f', "<name>, name can not be null");
      DEBUG_ARGS  yLOG_exitr (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_ARGS  yLOG_info    ("a_name"    , a_name);
   /*---(check length)-------------------*/
   l = strlen (a_name);
   DEBUG_ARGS  yLOG_value   ("l"         , l);
   --rce;  if (l <= 0) {
      yURG_err ('f', "<name>, name can not be blank/empty");
      DEBUG_ARGS  yLOG_exitr (__FUNCTION__, rce);
      return rce;
   }
   /*---(check characters)---------------*/
   --rce;  for (i = 0; i < l; ++i) {
      if (strchr (x_valid, a_name [i]) != NULL)  continue;
      yURG_err ('f', "<name>, name can not have a <%c> at character %d", a_name [i], i);
      DEBUG_ARGS  yLOG_char  ("bad char"  , a_name [i]);
      DEBUG_ARGS  yLOG_exitr (__FUNCTION__, rce);
      return rce;
   }
   /*---(check for extention)------------*/
   strcpy (x_base, a_name);
   p = strstr (x_base, ".unit");
   if (p != NULL)   p [0] = '\0';
   /*---(check unit file)----------------*/
   sprintf (x_unit, "%s.unit", x_base);
   DEBUG_ARGS    yLOG_value   ("x_unit"    , rc);
   rc = lstat (x_unit, &s);
   DEBUG_ARGS    yLOG_value   ("stat"      , rc);
   --rce;  if (rc < 0) {
      sprintf (x_unit, "%s.sunit", x_base);
      DEBUG_ARGS    yLOG_value   ("x_unit"    , rc);
      rc = lstat (x_unit, &s);
      DEBUG_ARGS    yLOG_value   ("stat"      , rc);
      if (rc < 0) {
         printf ("FATAL, can not find source either .unit or .sunit\n");
         DEBUG_ARGS    yLOG_note    ("can not find source either .unit or .sunit");
         DEBUG_ARGS    yLOG_exitr  (__FUNCTION__, rce);
         return rce;
      } else {
         strcpy (my.n_ext, ".sunit");
      }
   } else {
      strcpy (my.n_ext, ".unit");
   }
   --rce;  if (S_ISDIR (s.st_mode))  {
      printf ("FATAL, can not use a directory as a source\n");
      DEBUG_ARGS    yLOG_note    ("can not use a directory");
      DEBUG_ARGS    yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   --rce;  if (S_ISLNK (s.st_mode))  {
      DEBUG_ARGS    yLOG_note    ("is a link, figure it out");
      if (strcmp (my.n_ext, ".sunit") == 0) {
         printf ("FATAL, .sunit can not be a symlink\n");
         DEBUG_ARGS    yLOG_note    ("can not use a symlink");
         DEBUG_ARGS    yLOG_exitr   (__FUNCTION__, rce);
         return rce;
      } else {
         rc = readlink (x_unit, t, LEN_FULL);
         DEBUG_ARGS    yLOG_value   ("readlink"  , rc);
         if (rc < 0) {
            DEBUG_ARGS    yLOG_exitr  (__FUNCTION__, rce);
            return rce;
         }
         DEBUG_ARGS  yLOG_info    ("t"         , t);
         l = strlen (t);
         DEBUG_ARGS  yLOG_value   ("l"         , l);
         if (l < 7) {
            DEBUG_ARGS    yLOG_exitr  (__FUNCTION__, rce);
            return rce;
         }
         DEBUG_ARGS  yLOG_info    ("suffix"    , t + l - 6);
         if (strcmp (t + l - 6, ".sunit") != 0) {
            DEBUG_ARGS    yLOG_exitr  (__FUNCTION__, rce);
            return rce;
         }
         rc = stat (t, &r);
         DEBUG_ARGS    yLOG_value   ("stat"      , rc);
         if (rc < 0) {
            DEBUG_ARGS    yLOG_exitr  (__FUNCTION__, rce);
            return rce;
         }
      }
   }
   else if (!S_ISREG (s.st_mode)) {
      DEBUG_ARGS    yLOG_note    ("can only use regular file");
      DEBUG_ARGS    yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(check master.h)-----------------*/
   rc = lstat ("master.h", &s);
   DEBUG_ARGS    yLOG_value   ("stat"      , rc);
   if (rc < 0)   system  ("touch master.h");
   /*---(save back)----------------------*/
   strncpy (my.n_base, a_name, LEN_PATH);
   DEBUG_ARGS  yLOG_info    ("n_base"    , my.n_base);
   /*---(complete)-----------------------*/
   DEBUG_ARGS   yLOG_exit    (__FUNCTION__);
   return 0;
}

char               /* PURPOSE : process the command line arguments            */
PROG_args          (int argc, char *argv[])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   int         i           =    0;
   char       *a           = NULL;
   int         x_total     =    0;
   int         x_args      =    0;
   /*---(begin)--------------------------*/
   DEBUG_PROG  yLOG_enter   (__FUNCTION__);
   /*---(process)------------------------*/
   for (i = 1; i < argc; ++i) {
      a = argv[i];
      ++x_total;
      if (a[0] == '@')  continue;
      DEBUG_ARGS  yLOG_info    ("cli arg", a);
      ++x_args;
      if      (strncmp (a, "--create"     , 10) == 0)    my.run_type = G_RUN_CREATE;
      else if (strncmp (a, "--compile"    , 10) == 0)    my.run_type = G_RUN_CREATE;
      else if (strncmp (a, "--debug"      , 10) == 0)    my.run_type = G_RUN_DEBUG;
      else if (strncmp (a, "--convert"    , 10) == 0)    my.run_type = G_RUN_UPDATE;
      else if (strncmp (a, "--update"     , 10) == 0)  { my.run_type = G_RUN_UPDATE;  my.replace = G_RUN_REPLACE; }
      else if (strncmp (a, "-"            ,  1) == 0)  { printf ("FATAL, arg <<%s>> not understood¦", a); DEBUG_PROG  yLOG_exitr  (__FUNCTION__, rce); return rce; }
      else {
         rc = PROG_file (a);
         if (rc < 0) {
            DEBUG_PROG  yLOG_note   ("base name is invalid or not found");
            DEBUG_PROG  yLOG_exitr  (__FUNCTION__, rce);
            return rce;
         }
      }
   }
   DEBUG_ARGS  yLOG_value  ("entries"   , x_total);
   DEBUG_ARGS  yLOG_value  ("arguments" , x_args);
   if (x_args == 0) {
      DEBUG_ARGS  yLOG_note   ("no arguments identified");
   }
   DEBUG_ARGS  yLOG_char   ("run_type"  , my.run_type);
   DEBUG_ARGS  yLOG_info   ("basename"  , my.n_base);
   /*---(complete)-----------------------*/
   DEBUG_PROG  yLOG_exit  (__FUNCTION__);
   return 0;
}

char                /* PURPOSE : initialize program and key variables --------*/
PROG_begin         (void)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   /*---(header)-------------------------*/
   DEBUG_PROG   yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   DEBUG_PROG   yLOG_info    ("basename"  , my.n_base);
   --rce;  if (strcmp (my.n_base, "") == 0) {
      printf ("FATAL, no base file name provided\n");
      DEBUG_PROG   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(defense)------------------------*/
   --rce;  if (strcmp (my.n_ext, ".sunit") == 0) {
      if (my.run_type != G_RUN_UPDATE) {
         printf ("FATAL, can not compile/debug .sunit files\n");
         DEBUG_PROG   yLOG_exitr   (__FUNCTION__, rce);
         return rce;
      }
   }
   /*---(create names)-------------------*/
   snprintf (my.n_scrp, LEN_PATH, "%s%s", my.n_base, my.n_ext);
   snprintf (my.n_wave, LEN_PATH, "%s.wave"        , my.n_base);
   switch (my.run_type) {
   case G_RUN_UPDATE  :
      snprintf (my.n_conv, LEN_PATH, "%s%s.new"       , my.n_base, my.n_ext);
      break;
   case G_RUN_CREATE  :
      snprintf (my.n_code, LEN_PATH, "%s_unit.cs"     , my.n_base);
      snprintf (my.n_main, LEN_PATH, "%s_unit.tmp"    , my.n_base);
      snprintf (my.n_wave, LEN_PATH, "%s.wave"        , my.n_base);
      break;
   case G_RUN_DEBUG   :
      snprintf (my.n_code, LEN_PATH, "%s_unit.c"      , my.n_base);
      snprintf (my.n_main, LEN_PATH, "%s_unit.tmp"    , my.n_base);
      break;
   }
   /*---(initialize)---------------------*/
   my.n_line    = 0;
   my.n_comment = 0;
   my.n_empty   = 0;
   my.n_short   = 0;
   my.n_recd    = 0;
   my.dittoing  = '-';
   my.dmark     = '-';
   my.ditto     = -1;
   /*---(complete)-----------------------*/
   DEBUG_PROG   yLOG_exit    (__FUNCTION__);
   return 0;
}



/*====================------------------------------------====================*/
/*===----                        wrapup functions                      ----===*/
/*====================------------------------------------====================*/
static void  o___WRAPUP__________o () { return; }

char                /* PURPOSE : shutdown program and free memory ------------*/
PROG_end           (void)
{
   DEBUG_PROG   yLOG_enter   (__FUNCTION__);
   DEBUG_PROG   yLOG_exit    (__FUNCTION__);
   yLOGS_end     ();
   return 0;
}



/*====================------------------------------------====================*/
/*===----                   helpers for unit testing                   ----===*/
/*====================------------------------------------====================*/
static void      o___UNITTEST________________o (void) {;}

char       /*----: set up program urgents/debugging --------------------------*/
PROG__unit_quiet   (void)
{
   char       *x_args [1]  = { "koios" };
   yURG_logger    (1, x_args);
   PROG_init      ();
   yURG_urgs      (1, x_args);
   PROG_args      (1, x_args);
   PROG_begin     ();
   return 0;
}

char       /*----: set up program urgents/debugging --------------------------*/
PROG__unit_loud    (void)
{
   char       *x_args [2]  = { "koios_unit", "@@kitchen"    };
   yURG_logger    (1, x_args);
   PROG_init      ();
   yURG_urgs      (2, x_args);
   PROG_args      (2, x_args);
   PROG_begin     ();
   return 0;
}

char       /*----: set up program urgents/debugging --------------------------*/
PROG__unit_end     (void)
{
   PROG_end       ();
   return 0;
}







/*===============================[[ end code ]]===============================*/
