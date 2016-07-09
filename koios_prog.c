/*===============================[[ beg-code ]]===============================*/
#include    "koios.h"        /* LOCAL  : main header                          */

tDEBUG      debug;
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
/*===----                      debugging functions                     ----===*/
/*====================------------------------------------====================*/
static void  o___DEBUG___________o () { return; }

char         /*--: evaluate logger needs early -----------[ leaf   [ ------ ]-*/
PROG_logger        (int a_argc, char *a_argv[])
{
   /*---(locals)-------------------------*/
   int         rc          = 0;             /* generic return code            */
   int         i           = 0;             /* loop iterator -- arguments     */
   char       *a           = NULL;          /* current argument               */
   int         x_log       = '-';           /* logging flag                   */
   /*---(default urgents)----------------*/
   PROG_urgsmass ('-', 'y');   /* turn everything off */
   debug.logger   = -1;
   /*---(test for normal version)--------*/
   if        (strcmp (a_argv[0], "koios"        ) == 0)  return 0;
   x_log          = 'y';
   debug.tops     = 'y';
   /*---(logger preprocessing)-----------*/
   for (i = 1; i < a_argc; ++i) {
      a = a_argv[i];
      if (a[0] != '@')  continue;
      x_log          = 'y';
   }
   /*---(startup logging)----------------*/
   if (x_log == 'y') {
      if (strcmp (a_argv[0], "koios_debug"  ) == 0)  {
         debug.logger = yLOG_begin ("koios"      , yLOG_SYSTEM    , yLOG_NOISE);
      } else {
         debug.logger = yLOG_begin (a_argv [0]   , yLOG_SYSTEM    , yLOG_NOISE);
      }
   }
   /*---(log header)------------------*/
   DEBUG_TOPS   yLOG_info     ("purpose" , "unit testing metaprogram and mini-language");
   DEBUG_TOPS   yLOG_info     ("namesake", "titan of inquisitive mind and questioning");
   DEBUG_TOPS   yLOG_info     ("koios"   , PROG_version   ());
   DEBUG_TOPS   yLOG_info     ("ySTR"    , ySTR_version   ());
   DEBUG_TOPS   yLOG_info     ("yLOG"    , yLOG_version   ());
   /*---(complete)-----------------------*/
   return 0;
}

char         /*--: wholesale urgents change --------------[ leaf   [ ------ ]-*/
PROG_urgsmass      (char a_set, char a_extra)
{
   /*---(overall)------------------------*/
   debug.tops     = a_set;
   debug.summ     = a_set;
   /*---(startup/shutdown)---------------*/
   debug.args     = a_set;
   debug.conf     = a_set;
   debug.prog     = a_set;
   /*---(file processing)----------------*/
   debug.inpt     = a_set;
   debug.inpt_mas = a_set;
   debug.outp     = a_set;
   debug.outp_mas = a_set;
   /*---(event handling)-----------------*/
   debug.loop     = a_set;
   debug.loop_mas = a_set;
   debug.user     = a_set;
   debug.apis     = a_set;
   debug.sign     = a_set;
   debug.scrp     = a_set;
   debug.hist     = a_set;
   /*---(program)------------------------*/
   debug.graf     = a_set;
   debug.data     = a_set;
   debug.envi     = a_set;
   debug.envi_mas = a_set;
   /*---(specific)-----------------------*/
   if (a_extra == 'y') {
      ;;
   }
   /*---(complete)-----------------------*/
   return 0;
}

char         /*--: evaluate command line urgents ---------[ leaf   [ ------ ]-*/
PROG_urgs          (int a_argc, char *a_argv[])
{
   /*---(locals)-------------------------*/
   int         rc          = 0;             /* generic return code            */
   int         i           = 0;             /* loop iterator -- arguments     */
   char       *a           = NULL;          /* current argument               */
   int         x_len       = 0;             /* argument length                */
   int         x_total     = 0;             /* total argument count           */
   int         x_urgs      = 0;             /* urgent count                   */
   /*---(default urgents)----------------*/
   DEBUG_TOPS   yLOG_enter   (__FUNCTION__);
   /*---(check for normal version)-------*/
   if (strcmp (a_argv[0], "themis"       ) == 0)  return 0;
   /*---(walk through urgents)-----------*/
   for (i = 1; i < a_argc; ++i) {
      /*---(prepare)---------------------*/
      a        = a_argv [i];
      x_len    = strllen (a, LEN_RECD);
      ++x_total;
      /*---(filter)----------------------*/
      if (a[0] != '@')  continue;
      ++x_urgs;
      DEBUG_ARGS  yLOG_info  ("urgent"    , a);
      /*---(overall)---------------------*/
      if      (strncmp(a, "@t"           ,10) == 0)  debug.tops = 'y';
      else if (strncmp(a, "@@tops"       ,10) == 0)  debug.tops = 'y';
      else if (strncmp(a, "@s"           ,10) == 0)  debug.tops = debug.summ  = 'y';
      else if (strncmp(a, "@@summ"       ,10) == 0)  debug.tops = debug.summ  = 'y';
      /*---(startup/shutdown)------------*/
      else if (strncmp(a, "@a"           ,10) == 0)  debug.tops = debug.args  = 'y';
      else if (strncmp(a, "@@args"       ,10) == 0)  debug.tops = debug.args  = 'y';
      else if (strncmp(a, "@c"           ,10) == 0)  debug.tops = debug.conf  = 'y';
      else if (strncmp(a, "@@conf"       ,10) == 0)  debug.tops = debug.conf  = 'y';
      else if (strncmp(a, "@p"           ,10) == 0)  debug.tops = debug.prog  = 'y';
      else if (strncmp(a, "@@prog"       ,10) == 0)  debug.tops = debug.prog  = 'y';
      /*---(file processing)-------------*/
      else if (strncmp(a, "@i"           ,10) == 0)  debug.tops = debug.inpt  = 'y';
      else if (strncmp(a, "@@inpt"       ,10) == 0)  debug.tops = debug.inpt  = 'y';
      else if (strncmp(a, "@I"           ,10) == 0)  debug.tops = debug.inpt  = debug.inpt_mas = 'y';
      else if (strncmp(a, "@@INPT"       ,10) == 0)  debug.tops = debug.inpt  = debug.inpt_mas = 'y';
      else if (strncmp(a, "@o"           ,10) == 0)  debug.tops = debug.outp  = 'y';
      else if (strncmp(a, "@@outp"       ,10) == 0)  debug.tops = debug.outp  = 'y';
      else if (strncmp(a, "@O"           ,10) == 0)  debug.tops = debug.outp  = debug.outp_mas = 'y';
      else if (strncmp(a, "@@OUTP"       ,10) == 0)  debug.tops = debug.outp  = debug.outp_mas = 'y';
      /*---(processing)------------------*/
      else if (strncmp(a, "@l"           ,10) == 0)  debug.tops = debug.loop  = 'y';
      else if (strncmp(a, "@@loop"       ,10) == 0)  debug.tops = debug.loop  = 'y';
      else if (strncmp(a, "@L"           ,10) == 0)  debug.tops = debug.loop  = debug.loop_mas =  'y';
      else if (strncmp(a, "@@LOOP"       ,10) == 0)  debug.tops = debug.loop  = debug.loop_mas =  'y';
      else if (strncmp(a, "@u"           ,10) == 0)  debug.tops = debug.user  = 'y';
      else if (strncmp(a, "@@user"       ,10) == 0)  debug.tops = debug.user  = 'y';
      else if (strncmp(a, "@z"           ,10) == 0)  debug.tops = debug.apis  = 'y';
      else if (strncmp(a, "@@apis"       ,10) == 0)  debug.tops = debug.apis  = 'y';
      else if (strncmp(a, "@x"           ,10) == 0)  debug.tops = debug.sign  = 'y';
      else if (strncmp(a, "@@sign"       ,10) == 0)  debug.tops = debug.sign  = 'y';
      else if (strncmp(a, "@b"           ,10) == 0)  debug.tops = debug.scrp  = 'y';
      else if (strncmp(a, "@@scrp"       ,10) == 0)  debug.tops = debug.scrp  = 'y';
      else if (strncmp(a, "@h"           ,10) == 0)  debug.tops = debug.hist  = 'y';
      else if (strncmp(a, "@@hist"       ,10) == 0)  debug.tops = debug.hist  = 'y';
      /*---(program)---------------------*/
      else if (strncmp(a, "@g"           ,10) == 0)  debug.tops = debug.graf  = 'y';
      else if (strncmp(a, "@@graf"       ,10) == 0)  debug.tops = debug.graf  = 'y';
      else if (strncmp(a, "@d"           ,10) == 0)  debug.tops = debug.data  = 'y';
      else if (strncmp(a, "@@data"       ,10) == 0)  debug.tops = debug.data  = 'y';
      else if (strncmp(a, "@e"           ,10) == 0)  debug.tops = debug.envi  = 'y';
      else if (strncmp(a, "@@envi"       ,10) == 0)  debug.tops = debug.envi  = 'y';
      else if (strncmp(a, "@E"           ,10) == 0)  debug.tops = debug.envi  = debug.envi_mas = 'y';
      else if (strncmp(a, "@@ENVI"       ,10) == 0)  debug.tops = debug.envi  = debug.envi_mas = 'y';
      /*---(complex)---------------------*/
      else if (strncmp(a, "@q"           ,10) == 0)  PROG_urgsmass ('n', 'n');
      else if (strncmp(a, "@@quiet"      ,10) == 0)  PROG_urgsmass ('n', 'n');
      else if (strncmp(a, "@f"           ,10) == 0)  PROG_urgsmass ('y', '-');
      else if (strncmp(a, "@@full"       ,10) == 0)  PROG_urgsmass ('y', '-');
      else if (strncmp(a, "@k"           ,10) == 0)  PROG_urgsmass ('y', 'y');
      else if (strncmp(a, "@@kitchen"    ,10) == 0)  PROG_urgsmass ('y', 'y');
      /*---(specific)--------------------*/
      /*---(unknown)--------------------*/
      else {
         DEBUG_ARGS  yLOG_note    ("urgent not understood");
      }
      /*---(done)-----------------------*/
   }
   /*---(display urgents)----------------*/
   DEBUG_ARGS   yLOG_note    ("summarization of urgent processing");
   DEBUG_ARGS   yLOG_value   ("entries"   , x_total);
   DEBUG_ARGS   yLOG_value   ("urgents"   , x_urgs);
   DEBUG_ARGS   yLOG_note    ("standard urgents");
   DEBUG_ARGS   yLOG_char    ("tops"      , debug.tops);
   DEBUG_ARGS   yLOG_char    ("summ"      , debug.summ);
   DEBUG_ARGS   yLOG_char    ("args"      , debug.args);
   DEBUG_ARGS   yLOG_char    ("conf"      , debug.conf);
   DEBUG_ARGS   yLOG_char    ("prog"      , debug.prog);
   DEBUG_ARGS   yLOG_char    ("inpt"      , debug.inpt);
   DEBUG_ARGS   yLOG_char    ("INPT"      , debug.inpt_mas);
   DEBUG_ARGS   yLOG_char    ("outp"      , debug.outp);
   DEBUG_ARGS   yLOG_char    ("OUTP"      , debug.outp_mas);
   DEBUG_ARGS   yLOG_char    ("loop"      , debug.loop);
   DEBUG_ARGS   yLOG_char    ("LOOP"      , debug.loop_mas);
   DEBUG_ARGS   yLOG_char    ("user"      , debug.user);
   DEBUG_ARGS   yLOG_char    ("apis"      , debug.apis);
   DEBUG_ARGS   yLOG_char    ("sign"      , debug.sign);
   DEBUG_ARGS   yLOG_char    ("scrp"      , debug.scrp);
   DEBUG_ARGS   yLOG_char    ("hist"      , debug.hist);
   DEBUG_ARGS   yLOG_char    ("graf"      , debug.graf);
   DEBUG_ARGS   yLOG_char    ("data"      , debug.data);
   DEBUG_ARGS   yLOG_char    ("envi"      , debug.envi);
   DEBUG_ARGS   yLOG_char    ("ENVI"      , debug.envi_mas);
   DEBUG_ARGS   yLOG_note    ("no specialty urgents");
   /*---(complete)-----------------------*/
   DEBUG_TOPS   yLOG_exit    (__FUNCTION__);
   return 0;
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
   strlcpy  (my.name_conv, "", LEN_FILE);
   my.driver    = '-';
   my.run_type  = 'u';
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
      if      (strncmp (a, "--conv"    ,10) == 0) {
         my.run_type = 'c';
      }
      else if (strncmp (a, "--unit"    ,10) == 0) {
         my.run_type = 'u';
      }
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
   snprintf (my.name_scrp, LEN_FILE, "%s.unit"      , my.name_base);
   snprintf (my.name_code, LEN_FILE, "%s_unit.c"    , my.name_base);
   snprintf (my.name_conv, LEN_FILE, "%s.unit.new"  , my.name_base);
   /*> snprintf (my.name_code, LEN_FILE, "%s_unit.c.new", my.name_base);              <*/
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
   PROG_logger    (1, x_args);
   PROG_init      ();
   PROG_urgs      (1, x_args);
   PROG_args      (1, x_args);
   PROG_begin     ();
   return 0;
}

char       /*----: set up program urgents/debugging --------------------------*/
PROG_testloud      (void)
{
   char       *x_args [2]  = { "koios_unit", "@@kitchen"    };
   PROG_logger    (1, x_args);
   PROG_init      ();
   PROG_urgs      (2, x_args);
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
