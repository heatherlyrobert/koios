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
   snprintf (my.version, LEN_STR, "%s   %s : %s", t, KOIOS_VER_NUM, KOIOS_VER_TXT);
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
   DEBUG_TOPS   yLOG_enter   (__FUNCTION__);
   /*---(files)--------------------------*/
   strlcpy  (my.name_scrp, "", LEN_FILE);
   strlcpy  (my.name_code, "", LEN_FILE);
   strlcpy  (my.name_main, "", LEN_FILE);
   strlcpy  (my.name_conv, "", LEN_FILE);
   my.driver    = '-';
   my.run_type  = G_RUN_CREATE;
   strlcpy  (my.last     , "", LEN_FILE);
   /*---(complete)-----------------------*/
   DEBUG_TOPS   yLOG_exit    (__FUNCTION__);
   return 0;
}

char               /* PURPOSE : process the command line arguments            */
PROG_args          (int argc, char *argv[])
{
   /*---(locals)-------------------------*/
   int         i           = 0;
   char       *a           = NULL;
   int         x_total     = 0;
   int         x_args      = 0;
   /*---(begin)--------------------------*/
   DEBUG_TOPS  yLOG_enter   (__FUNCTION__);
   /*---(process)------------------------*/
   for (i = 1; i < argc; ++i) {
      a = argv[i];
      ++x_total;
      if (a[0] == '@')  continue;
      DEBUG_ARGS  yLOG_info    ("cli arg", a);
      ++x_args;
      strncpy (my.name_base, argv[i], LEN_FILE);
      if      (strncmp (a, "--create"     , 10) == 0)    my.run_type = G_RUN_CREATE;
      else if (strncmp (a, "--compile"    , 10) == 0)    my.run_type = G_RUN_CREATE;
      else if (strncmp (a, "--update"     , 10) == 0)    my.run_type = G_RUN_UPDATE;
      else if (strncmp (a, "--convert"    , 10) == 0)    my.run_type = G_RUN_UPDATE;
   }
   DEBUG_ARGS  yLOG_value  ("entries"   , x_total);
   DEBUG_ARGS  yLOG_value  ("arguments" , x_args);
   if (x_args == 0) {
      DEBUG_ARGS  yLOG_note   ("no arguments identified");
   }
   DEBUG_ARGS  yLOG_char   ("run_type"  , my.run_type);
   DEBUG_ARGS  yLOG_info   ("basename"  , my.name_base);
   /*---(complete)-----------------------*/
   DEBUG_TOPS  yLOG_exit  (__FUNCTION__);
   return 0;
}

char                /* PURPOSE : initialize program and key variables --------*/
PROG_begin         (void)
{
   DEBUG_TOPS   yLOG_enter   (__FUNCTION__);
   /*---(file names)---------------------*/
   DEBUG_TOPS   yLOG_info    ("basename"  , my.name_base);
   if (strcmp (my.name_base, "") == 0) {
      printf ("no base file name provided, FATAL\n");
      DEBUG_TOPS   yLOG_exit    (__FUNCTION__);
      return -1;
   }
   snprintf (my.name_scrp, LEN_FILE, "%s.unit"        , my.name_base);
   snprintf (my.name_code, LEN_FILE, "%s_unit.c"      , my.name_base);
   snprintf (my.name_main, LEN_FILE, "%s_main_unit.c" , my.name_base);
   snprintf (my.name_conv, LEN_FILE, "%s.unit.new"    , my.name_base);
   my.n_line    = 0;
   my.n_comment = 0;
   my.n_empty   = 0;
   my.n_short   = 0;
   my.n_recd    = 0;
   /*---(complete)-----------------------*/
   DEBUG_TOPS   yLOG_exit    (__FUNCTION__);
   return 0;
}



/*====================------------------------------------====================*/
/*===----                        wrapup functions                      ----===*/
/*====================------------------------------------====================*/
static void  o___WRAPUP__________o () { return; }

char                /* PURPOSE : shutdown program and free memory ------------*/
PROG_end           (void)
{
   DEBUG_TOPS   yLOG_enter   (__FUNCTION__);
   DEBUG_TOPS   yLOG_exit    (__FUNCTION__);
   yLOG_end     ();
   return 0;
}



/*====================------------------------------------====================*/
/*===----                   helpers for unit testing                   ----===*/
/*====================------------------------------------====================*/
static void      o___UNITTEST________________o (void) {;}

char       /*----: set up program test file locations ------------------------*/
PROG_testfiles     (void)
{
   /*> snprintf (my.name_root   , LEN_FILE, "%s"    , DIR_TEST);                           <* 
    *> snprintf (my.name_conf   , LEN_FILE, "%s%s%s", DIR_TEST , DIR_ETC  , FILE_CONF );   <* 
    *> snprintf (my.name_full   , LEN_FILE, "%s%s%s", DIR_TEST , DIR_YHIST, FILE_FULL );   <* 
    *> snprintf (my.name_summ   , LEN_FILE, "%s%s%s", DIR_TEST , DIR_YHIST, FILE_SUMM );   <* 
    *> snprintf (my.name_warn   , LEN_FILE, "%s%s%s", DIR_TEST , DIR_YHIST, FILE_WARN );   <*/
   return 0;
}

char       /*----: set up program urgents/debugging --------------------------*/
PROG_testquiet     (void)
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
PROG_testloud      (void)
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
PROG_testend       (void)
{
   PROG_end       ();
   return 0;
}







/*===============================[[ end code ]]===============================*/
