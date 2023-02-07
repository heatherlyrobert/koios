/*===============================[[ beg-code ]]===============================*/
#include    "koios.h"        /* LOCAL  : main header                          */





static  FILE *s_file_save;
static  FILE *s_file_ditto;

static  int   s_master [26] = { -1 };
static  int   s_reuses [26] = { -1 };
static  int   s_dittos [26] = { -1 };

tVERB       g_verbs [MAX_VERB] = {
   /* --global------   ---------------------------------------   -  */
   { "GLOBAL"       , "shared code between units"             , 's', 'm',  0,  0, CONV_global   , CODE_global   },
   /* --units-------   ---------------------------------------   -  */
   { "PREP"         , "preparation before testing"            , '2', '-',  0,  0, CONV_prep     , CODE_prep     },
   { "incl"         , "c header inclusion"                    , '3', '-',  0,  0, CONV_incl     , CODE_incl     },
   { "#>"           , "script internal comments"              , 'c', '-',  0,  0, CONV_comment  , NULL          },
   /* --scrps-------   --------------------------------------- */
   { "SCRP"         , "test script"                           , 's', 'n',  0,  0, CONV_scrp     , CODE_scrp     },
   { "SECT"         , "grouping of scripts"                   , '2', 'n',  0,  0, CONV_sect     , CODE_sect     },
   { "SHARED"       , "shared code between scripts"           , 's', 'n',  0,  0, CONV_shared   , CODE_shared   },
   /* --conds-------   --------------------------------------- */
   { "GROUP"        , "grouping of conditions"                , '2', '-',  0,  0, CONV_group    , CODE_group    },
   { "COND"         , "test condition"                        , '2', '-',  0,  0, CONV_cond     , CODE_cond     },
   { "DITTO"        , "repeated test condition"               , '1', '-',  0,  0, CONV_ditto    , NULL          },
   { "REUSE"        , "inclusion of shared code"              , 'r', '-',  0,  0, CONV_reuse    , CODE_reuse    },
   /* --steps-------   --------------------------------------- */
   { "exec"         , "function execution"                    , 'f', '-',  0,  0, CONV_exec     , CODE_exec     },
   { "get"          , "unit test accessor retrieval"          , 'f', '-',  0,  0, CONV_exec     , CODE_exec     },
   /* --specialty---   --------------------------------------- */
   { "global"       , "global/unit variable definition"       , 'p', '-',  0,  0, CONV_gvar     , CODE_gvar     },
   { "local"        , "local/script variable deinition"       , 'p', '-',  0,  0, CONV_code     , CODE_lvar     },
   { "code"         , "insert c code"                         , 'p', '-',  0,  0, CONV_code     , CODE_code     },
   { "echo"         , "test a variable directly"              , 'f', '-',  0,  0, CONV_echo     , CODE_echo     },
   { "system"       , "execute shell code"                    , 'p', '-',  0,  0, CONV_code     , CODE_system   },
   { "load"         , "place data into stdin"                 , 'P', '-',  0,  0, CONV_load     , CODE_load     },
   { "file"         , "create a temporary file"               , 'p', '-',  0,  0, CONV_file     , CODE_file     },
   { "append"       , "append data to temporary file"         , 'p', '-',  0,  0, CONV_append   , CODE_append   },
   { "mode"         , "set pass or forced_fail mode"          , '2', '-',  0,  0, CONV_mode     , CODE_mode     },
   /* --ouroboros---   --------------------------------------- */
   { "WAVE"         , "testing wave"                          , '2', 'm',  0,  0, NULL          , NULL          },
   { "stage"        , "testing stage"                         , '2', 'm',  0,  0, NULL          , NULL          },
   /* --sentinal----   --------------------------------------- */
   { "----"         , "end-of-entries"                        , '-', '-',  0,  0, NULL          , NULL          },
   /* --done--------   --------------------------------------- */
};



/*====================------------------------------------====================*/
/*===----                    for shared lines                          ----===*/
/*====================------------------------------------====================*/
static void      o___SHARED__________________o (void) {;}

char
SCRP__shared_clear      (cchar a_type)
{
   /*---(locals)-------------------------*/
   int         i           =    0;
   /*---(set defaults)-------------------*/
   for (i = 0; i < 26; ++i) {
      switch (a_type) {
      case T_MASTER : s_master [i] = -1;              break;
      case T_REUSES : s_reuses [i] = -1;              break;
      case T_DITTOS : s_dittos [i] = -1;              break;
      }
   }
   /*---(complete)-----------------------*/
   return 0;
}

char
SCRP__shared_purge      (void)
{
   SCRP__shared_clear (T_MASTER);
   SCRP__shared_clear (T_REUSES);
   SCRP__shared_clear (T_DITTOS);
   return 0;
}

char
SCRP__shared_index      (cchar a_type, cchar a_mark)
{
   /*---(locals)-------------------------*/
   char        rce         =  -10;
   char       *x_valid     = NULL;
   char        i           =  -10;
   /*---(set type)-----------------------*/
   --rce;  switch (a_type) {
   case T_MASTER : x_valid = YSTR_UPPER;   break;
   case T_REUSES : x_valid = YSTR_LOWER;   break;
   case T_DITTOS : x_valid = YSTR_NUMBER;  break;
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
SCRP__shared_set        (cchar a_type, cchar a_mark)
{
   /*---(locals)-------------------------*/
   char        i           =  -10;
   /*---(get index)----------------------*/
   i = SCRP__shared_index (a_type, a_mark);
   if (i < 0) return i;
   /*---(update list)--------------------*/
   switch (a_type) {
   case T_MASTER : s_master [i] = my.n_line;   break;
   case T_REUSES : s_reuses [i] = my.n_line;   break;
   case T_DITTOS : s_dittos [i] = my.n_line;   break;
   }
   /*---(complete)-----------------------*/
   return 0;
}

int
SCRP__shared_get        (cchar a_type, cchar a_mark)
{
   /*---(locals)-------------------------*/
   char        i           =  -10;
   int         x_line      =   -1;
   /*---(get index)----------------------*/
   i = SCRP__shared_index (a_type, a_mark);
   if (i < 0) return i;
   /*---(update list)--------------------*/
   switch (a_type) {
   case T_MASTER : x_line = s_master [i];   break;
   case T_REUSES : x_line = s_reuses [i];   break;
   case T_DITTOS : x_line = s_dittos [i];   break;
   }
   /*---(complete)-----------------------*/
   return x_line;
}

char*
SCRP__shared_used       (void)
{
   /*---(locals)-------------------------*/
   int         i           =    0;
   /*---(default)------------------------*/
   for (i = 0; i < (26 + 3 + 26 + 3 + 10); ++i) {
      my.d_used [i] = ' ';
   }
   my.d_used [i] = '\0';
   /*---(master)-------------------------*/
   for (i = 0; i < 26; ++i) {
      if (s_master [i] < 0)    my.d_used [i +  0] = '-';
      else                     my.d_used [i +  0] = 'A' + i;
   }
   /*---(reuses)-------------------------*/
   for (i = 0; i < 26; ++i) {
      if (s_reuses [i] < 0)    my.d_used [i + 29] = '-';
      else                     my.d_used [i + 29] = 'a' + i;
   }
   /*---(dittos)-------------------------*/
   for (i = 0; i < 10; ++i) {
      if (s_dittos [i] < 0)    my.d_used [i + 58] = '-';
      else                     my.d_used [i + 58] = '0' + i;
   }
   /*---(complete)-----------------------*/
   return my.d_used;
}



/*====================------------------------------------====================*/
/*===----                    for ditting lines                         ----===*/
/*====================------------------------------------====================*/
static void      o___DITTOING________________o (void) {;}

char SCRP__ditto_clear  (void)        { return SCRP__shared_clear (T_DITTOS); }

char
SCRP_ditto__beg         (char *a_verb)
{
   /*---(locals)-----------+-----------+-*/
   char        rce         =  -10;
   char       *p           = NULL;
   /*---(header)-------------------------*/
   DEBUG_INPT   yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   DEBUG_INPT   yLOG_spoint  (a_verb);
   --rce;  if (a_verb == NULL) {
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(reopen file)--------------------*/
   s_file_ditto = fopen (my.n_scrp, "r");
   DEBUG_INPT   yLOG_point   ("refile*"   , s_file_ditto);
   --rce;  if (my.f_scrp == NULL) {
      DEBUG_PROG   yLOG_fatal   ("scrp file, can not open script file");
      DEBUG_PROG   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(swap files)---------------------*/
   DEBUG_INPT   yLOG_note    ("swap file for script");
   /*> printf ("START DITTO ----------------------------------------\n");             <*/
   s_file_save  = my.f_scrp;
   my.f_scrp    = s_file_ditto;
   my.dline     = 0;
   my.dittoing  = 'y';
   /*---(complete)-----------------------*/
   DEBUG_INPT   yLOG_exit    (__FUNCTION__);
   return 0;
}

char
SCRP_ditto__handler     (void)
{
   DEBUG_INPT   yLOG_senter  (__FUNCTION__);
   /*---(check for no ditto)-------------*/
   DEBUG_INPT   yLOG_schar   (my.dittoing);
   if (my.dittoing != 'y') {
      DEBUG_INPT   yLOG_snote   ("not dittoing");
      ++my.n_line;
      DEBUG_INPT   yLOG_sint    (my.n_line);
      DEBUG_INPT   yLOG_sexit   (__FUNCTION__);
      return 0;
   }
   /*---(update ditto line)--------------*/
   ++my.dline;
   DEBUG_INPT   yLOG_sint    (my.dline);
   DEBUG_INPT   yLOG_sint    (my.ditto);
   /*---(check for pre-ditto)------------*/
   if (my.dline <  my.ditto) {
      DEBUG_INPT   yLOG_snote   ("pre-ditto source line");
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, -1);
      return -1;
   }
   /*---(dittoing)-----------------------*/
   DEBUG_INPT   yLOG_snote   ("in sweet spot");
   DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, 1);
   return 1;
}

char
SCRP_ditto__end         (void)
{
   /*---(locals)-----------+-----------+-*/
   char        rce         =  -10;
   char        rc          =    0;
   /*---(header)-------------------------*/
   DEBUG_INPT   yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   DEBUG_INPT   yLOG_char    ("dittoing"  , my.dittoing);
   --rce;  if (my.dittoing != 'y') {
      DEBUG_INPT   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_INPT   yLOG_point   ("s_file_sav", s_file_save);
   --rce;  if (s_file_save == NULL) {
      DEBUG_INPT   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_INPT   yLOG_point   ("s_file_dit", s_file_ditto);
   --rce;  if (s_file_ditto == NULL) {
      DEBUG_INPT   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(reset ditto)--------------------*/
   /*> printf ("STOP DITTO -----------------------------------------\n");             <*/
   my.dittoing = '-';
   my.dmark    = '-';
   my.ditto    = -1;
   /*---(swap files)---------------------*/
   DEBUG_INPT   yLOG_note    ("swap file for script");
   my.f_scrp = s_file_save;
   /*---(close detail report)------------*/
   DEBUG_INPT   yLOG_point   ("file_ditto", s_file_ditto);
   rc = fclose (s_file_ditto);
   --rce;  if (rc != 0) {
      DEBUG_PROG   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(null closed pointers)-----------*/
   s_file_ditto = NULL;
   s_file_save  = NULL;
   my.dline     = 0;
   /*---(complete)-----------------------*/
   DEBUG_INPT   yLOG_exit    (__FUNCTION__);
   return 0;
}

char
SCRP__reuses_check      (char *p)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char       *q           = NULL;
   char        m           =  '-';
   int         n           =   -1;
   int         o           =   -1;
   char        t           [LEN_LABEL] = "";
   /*---(header)-------------------------*/
   DEBUG_INPT   yLOG_senter  (__FUNCTION__);
   /*---(default)------------------------*/
   my.share = '-';
   /*---(defense)------------------------*/
   DEBUG_INPT   yLOG_spoint  (p);
   --rce;  if (p == NULL) {
      yURG_err (YURG_FATAL, "%s:%d:1: error: GLOBAL/SHARED/REUSE called with a null string", my.n_scrp, my.n_line);
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_INPT   yLOG_snote   (p);
   /*---(check for right verbs)----------*/
   strcpy (t, g_verbs [my.indx].name);
   if (strstr (" GLOBAL SHARED REUSE " , t) == NULL) {
      DEBUG_INPT   yLOG_snote   ("this only applies to GLOBAL/SHARED/REUSE");
      DEBUG_INPT   yLOG_sexit   (__FUNCTION__);
      return 0;
   }
   /*---(check for marker)---------------*/
   q = strchr (p, '-');
   DEBUG_INPT   yLOG_spoint  (q);
   --rce;  if (q == NULL) {
      yURG_err (YURG_FATAL, "%s:%d:1: error: %s missing a valid identifier string -?-", my.n_scrp, my.n_line, t);
      DEBUG_INPT   yLOG_snote   ("no openning marker");
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   --rce;  if (q [1] == NULL) {
      yURG_err (YURG_FATAL, "%s:%d:1: error: %s identifier did not follow - marker", my.n_scrp, my.n_line, t);
      DEBUG_INPT   yLOG_snote   ("no identifer");
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   --rce;  if (q [1] == '-') {
      yURG_err (YURG_FATAL, "%s:%d:1: error: %s no identifier within -- markers", my.n_scrp, my.n_line, t);
      DEBUG_INPT   yLOG_snote   ("no identifer inside");
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   m = q [1];
   DEBUG_INPT   yLOG_schar   (m);
   --rce;  if (q [2] != '-') {
      yURG_err (YURG_FATAL, "%s:%d:1: error: %s identifier å%cæ not followed by - marker", my.n_scrp, my.n_line, t, m);
      DEBUG_INPT   yLOG_snote   ("no close marker");
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(validate marker)----------------*/
   n  = SCRP__shared_get (T_MASTER, m);
   DEBUG_INPT   yLOG_sint    (n);
   o  = SCRP__shared_get (T_REUSES, m);
   DEBUG_INPT   yLOG_sint    (o);
   /*---(handle global)------------------*/
   --rce;  if (strcmp ("GLOBAL" , g_verbs [my.indx].name) == 0) {
      DEBUG_INPT   yLOG_snote   ("handle global");
      IF_NORMAL {
         DEBUG_INPT   yLOG_snote   ("GLOBAL only allowed in master.unit");
         yURG_err (YURG_FATAL, "%s:%d:1: error: GLOBAL not allowed outside master.unit", my.n_scrp, my.n_line);
         DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
         return rce;
      }
      if (n < -1) {
         DEBUG_INPT   yLOG_snote   ("global identifier must be A-Z");
         yURG_err (YURG_FATAL, "%s:%d:1: error: GLOBAL identifier å%cæ not valid [A-Z]", my.n_scrp, my.n_line, m);
         DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
         return rce;
      }
      if (n >= 0) {
         DEBUG_INPT   yLOG_snote   ("already set");
         yURG_err (YURG_FATAL, "%s:%d:1: error: GLOBAL identifier å%cæ already in use", my.n_scrp, my.n_line, m);
         DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
         return rce;
      }
      rc = SCRP__shared_set (T_MASTER, m);
      my.share = m;
   }
   /*---(handle shared)------------------*/
   --rce;  if (strcmp ("SHARED" , g_verbs [my.indx].name) == 0) {
      DEBUG_INPT   yLOG_snote   ("handle shared");
      IF_MASTER {
         DEBUG_INPT   yLOG_snote   ("SHARED verb not allowed in master.unit");
         yURG_err (YURG_FATAL, "%s:%d:1: error: SHARED verb not allowed in master.unit", my.n_scrp, my.n_line);
         DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
         return rce;
      }
      if (o < -1) {
         DEBUG_INPT   yLOG_snote   ("shared identifier must be a-z");
         yURG_err (YURG_FATAL, "%s:%d:1: error: SHARED identifier å%cæ not valid [a-z]", my.n_scrp, my.n_line, m);
         DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
         return rce;
      }
      if (o >= 0) {
         DEBUG_INPT   yLOG_snote   ("already set");
         yURG_err (YURG_FATAL, "%s:%d:1: error: SHARED identifier å%cæ already in use", my.n_scrp, my.n_line, m);
         DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
         return rce;
      }
      rc = SCRP__shared_set (T_REUSES, m);
      my.share = m;
   }
   /*---(handle reuses)------------------*/
   --rce;  if (strcmp ("REUSE" , g_verbs [my.indx].name) == 0) {
      DEBUG_INPT   yLOG_snote   ("handle reuse");
      IF_MASTER {
         DEBUG_INPT   yLOG_snote   ("REUSE not allowed in master.unit");
         yURG_err (YURG_FATAL, "%s:%d:1: error: REUSE verb not allowed in master.unit", my.n_scrp, my.n_line);
         DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
         return rce;
      }
      if (n < -1 && o < -1) {
         DEBUG_INPT   yLOG_snote   ("not set");
         yURG_err (YURG_FATAL, "%s:%d:1: error: REUSE identifier å%cæ not valid [a-zA-Z]", my.n_scrp, my.n_line, m);
         DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
         return rce;
      }
      if (n == -1) {
         DEBUG_INPT   yLOG_snote   ("not set");
         yURG_err (YURG_FATAL, "%s:%d:1: error: REUSE identifier å%cæ never set by GLOBAL", my.n_scrp, my.n_line, m);
         DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
         return rce;
      }
      if (o == -1) {
         DEBUG_INPT   yLOG_snote   ("not set");
         yURG_err (YURG_FATAL, "%s:%d:1: error: REUSE identifier å%cæ never set by SHARED", my.n_scrp, my.n_line, m);
         DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
         return rce;
      }
      if (m == my.cshare) {
         DEBUG_INPT   yLOG_snote   ("reuse is recursive");
         yURG_err (YURG_FATAL, "%s:%d:1: error: REUSE identifier å%cæ called inside itself, recursive", my.n_scrp, my.n_line, m);
         DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
         return rce;
      }
      my.share = m;
   }
   /*---(complete)-----------------------*/
   DEBUG_INPT   yLOG_sexit   (__FUNCTION__);
   return 0;
}

char
SCRP__ditto_check       (char *p)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char       *q           = NULL;
   char        m           =  '-';
   int         n           =   -1;
   char        t           [LEN_LABEL] = "";
   /*---(header)-------------------------*/
   DEBUG_INPT   yLOG_senter  (__FUNCTION__);
   /*---(default)------------------------*/
   my.mark = '-';
   /*---(defense)------------------------*/
   DEBUG_INPT   yLOG_spoint  (p);
   --rce;  if (p == NULL) {
      yURG_err (YURG_FATAL, "%s:%d:1: error: COND/DITTO called with a null string", my.n_scrp, my.n_line);
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_INPT   yLOG_snote   (p);
   /*---(check for script)---------------*/
   strcpy (t, g_verbs [my.indx].name);
   if (strstr (" SCRP SHARED " , t) != NULL) {
      DEBUG_INPT   yLOG_snote   ("found SCRP/SHARED, resetting dittos");
      SCRP__ditto_clear ();
      DEBUG_INPT   yLOG_sexit   (__FUNCTION__);
      return 0;
   }
   if (strstr (" COND DITTO " , t) == NULL) {
      DEBUG_INPT   yLOG_snote   ("this only applies to COND/DITTO");
      DEBUG_INPT   yLOG_sexit   (__FUNCTION__);
      return 0;
   }
   /*---(check for marker)---------------*/
   q = strchr (p, '(');
   DEBUG_INPT   yLOG_spoint  (q);
   --rce;  if (q == NULL) {
      if (strcmp (t, "DITTO") == 0) {
         yURG_err (YURG_FATAL, "%s:%d:1: error: DITTO missing a valid identifier string (?)", my.n_scrp, my.n_line);
         DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
         return rce;
      }
      DEBUG_INPT   yLOG_snote   ("no openning marker");
      DEBUG_INPT   yLOG_sexit   (__FUNCTION__);
      return 0;
   }
   --rce;  if (q [1] == NULL) {
      yURG_err (YURG_FATAL, "%s:%d:1: error: %s identifier did not follow ( marker", my.n_scrp, my.n_line, t);
      DEBUG_INPT   yLOG_snote   ("no identifer");
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   --rce;  if (q [1] == ')') {
      yURG_err (YURG_FATAL, "%s:%d:1: error: %s no identifier within () markers", my.n_scrp, my.n_line, t);
      DEBUG_INPT   yLOG_snote   ("no identifer");
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   m = q [1];
   DEBUG_INPT   yLOG_schar   (m);
   --rce;  if (q [2] != ')') {
      yURG_err (YURG_FATAL, "%s:%d:1: error: %s identifier å%cæ not followed by ) marker", my.n_scrp, my.n_line, t, m);
      DEBUG_INPT   yLOG_snote   ("no close marker");
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(validate marker)----------------*/
   n  = SCRP__shared_get (T_DITTOS, m);
   DEBUG_INPT   yLOG_sint    (n);
   if (n < -1) {
      DEBUG_INPT   yLOG_snote   ("invalid identifier");
      yURG_err (YURG_FATAL, "%s:%d:1: error: %s identifier å%cæ not valid [0-9]", my.n_scrp, my.n_line, t, m);
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(handle condition)---------------*/
   --rce;  if (strcmp ("COND" , g_verbs [my.indx].name) == 0) {
      if (my.dittoing != 'y') {
         DEBUG_INPT   yLOG_snote   ("handle cond");
         if (n > 0) {
            DEBUG_INPT   yLOG_snote   ("already set identifier (hidding)");
            yURG_err (YURG_WARN, "%s:%d:1: warning: COND identifier å%cæ already set, now overwritten", my.n_scrp, my.n_line, m);
         }
         rc = SCRP__shared_set (T_DITTOS, m);
         my.mark = m;
      } else {
         DEBUG_INPT   yLOG_snote   ("cond () inside ditto, ignored");
      }
      DEBUG_INPT   yLOG_snote   ("saving position");
      DEBUG_INPT   yLOG_schar   (my.mark);
      DEBUG_INPT   yLOG_sint    (my.n_line);
   }
   /*---(handle ditto)-------------------*/
   if (strcmp ("DITTO" , g_verbs [my.indx].name) == 0) {
      DEBUG_INPT   yLOG_snote   ("handle ditto");
      if (n == -1) {
         DEBUG_INPT   yLOG_snote   ("unset identifier");
         yURG_err (YURG_FATAL, "%s:%d:1: error: DITTO identifier å%cæ not set by previous COND", my.n_scrp, my.n_line, m);
         DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
         return rce;
      }
      my.mark  = m;
      my.ditto = n;
      if (my.run_type == G_RUN_CREATE || my.run_type == G_RUN_DEBUG) {
         DEBUG_INPT   yLOG_snote   ("begin ditto processing");
         DEBUG_INPT   yLOG_sexit   (__FUNCTION__);
         my.dmark = m;
         rc = SCRP_ditto__beg (p);
         if (rc >= 0)  rc = 1;
         return rc;
      }
      DEBUG_INPT   yLOG_snote   ("using position");
      DEBUG_INPT   yLOG_schar   (my.mark);
      DEBUG_INPT   yLOG_sint    (my.n_line);
   }
   /*---(complete)-----------------------*/
   DEBUG_INPT   yLOG_sexit   (__FUNCTION__);
   return 0;
}



/*====================------------------------------------====================*/
/*===----                      reading the file                        ----===*/
/*====================------------------------------------====================*/
static void      o___READING_________________o (void) {;}

char         /*--> open script file ----------------------[ leaf   [ ------ ]-*/
SCRP_open          (void)
{
   /*---(locals)-----------+-----------+-*/
   char        rce         = -10;           /* return code for errors         */
   /*---(header)-------------------------*/
   DEBUG_PROG   yLOG_enter   (__FUNCTION__);
   /*---(already open)-------------------*/
   DEBUG_OUTP   yLOG_info    ("n_scrp"    , my.n_scrp);
   DEBUG_OUTP   yLOG_point   ("f_scrp"    , my.f_scrp);
   --rce;  if (my.f_scrp != NULL) {
      DEBUG_PROG   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_OUTP   yLOG_info    ("n_wave"    , my.n_wave);
   DEBUG_OUTP   yLOG_point   ("f_wave"    , my.f_wave);
   --rce;  if (my.f_wave != NULL) {
      DEBUG_PROG   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(open configuration)-------------*/
   DEBUG_INPT   yLOG_point   ("name"      , my.n_scrp);
   my.f_scrp = fopen (my.n_scrp, "rt");
   DEBUG_INPT   yLOG_point   ("file*"     , my.f_scrp);
   --rce;  if (my.f_scrp == NULL) {
      DEBUG_PROG   yLOG_fatal   ("scrp file, can not open script file");
      DEBUG_PROG   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_INPT   yLOG_note    ("script file open");
   my.n_line = 0;
   SCRP__ditto_clear ();
   /*---(open wave file)-----------------*/
   /*> printf ("n_wave = [%s]\n", my.n_wave);                                         <*/
   my.f_wave = fopen (my.n_wave, "wt");
   DEBUG_OUTP   yLOG_point   ("f_wave"    , my.f_wave);
   --rce;  if (my.f_wave == NULL) {
      DEBUG_PROG   yLOG_fatal   ("can not open wave file");
      fclose (my.f_scrp);
      my.f_scrp = NULL;
      DEBUG_PROG   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   DEBUG_OUTP   yLOG_note    ("wave file open");
   /*---(complete)-----------------------*/
   DEBUG_PROG   yLOG_exit    (__FUNCTION__);
   return 0;
}

char
WAVE_printf             (char *a_format, ...)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   va_list     x_vlist;
   /*---(defense)------------------------*/
   --rce;  if (my.f_wave == NULL)    return rce;
   --rce;  if (a_format  == NULL)    return rce;
   /*---(write)--------------------------*/
   va_start (x_vlist, a_format);
   vfprintf (my.f_wave, a_format, x_vlist);
   va_end   (x_vlist);
   fflush   (my.f_wave);
   /*---(complete)-------------------------*/
   return 0;
}

char         /*--> close script file ---------------------[ ------ [ ------ ]-*/
SCRP_close         (void)
{
   /*---(locals)-----------+-----------+-*/
   char        rc          = 0;
   char        rce         = -10;
   /*---(header)-------------------------*/
   DEBUG_PROG   yLOG_enter   (__FUNCTION__);
   /*---(close detail report)------------*/
   DEBUG_INPT   yLOG_point   ("*f_scrp", my.f_scrp);
   --rce;  if (my.f_scrp == NULL) {
      DEBUG_PROG   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   rc = fclose (my.f_scrp);
   --rce;  if (rc != 0) {
      DEBUG_PROG   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(close wave file)----------------*/
   DEBUG_INPT   yLOG_point   ("*f_wave", my.f_wave);
   --rce;  if (my.f_wave == NULL) {
      DEBUG_PROG   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   rc = fclose (my.f_wave);
   --rce;  if (rc != 0) {
      DEBUG_PROG   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(ground pointer)-----------------*/
   my.f_scrp = NULL;
   my.f_wave = NULL;
   /*---(complete)-----------------------*/
   DEBUG_PROG   yLOG_exit    (__FUNCTION__);
   return 0;
}

char         /*--> clean a script record -----------------[ leaf   [ ------ ]-*/
SCRP_clear         (void)
{
   /*---(header)-------------------------*/
   DEBUG_INPT   yLOG_senter  (__FUNCTION__);
   /*---(save value)---------------------*/
   if (strcmp (my.verb, "DITTO") != 0)  strlcpy (my.last, my.verb, LEN_LABEL);
   /*---(input vars)---------------------*/
   my.verb        [0] = '\0';
   my.p_conv          = NULL;
   my.p_code          = NULL;
   my.verb        [0] = '\0';
   my.spec            = '-';
   my.status          = '-';
   my.vers        [0] = '\0';
   my.desc        [0] = '\0';
   my.meth        [0] = '\0';
   my.args        [0] = '\0';
   my.test        [0] = '\0';
   my.expe        [0] = '\0';
   my.retn        [0] = '\0';
   my.code        [0] = '\0';
   my.refn        [0] = '\0';
   /*---(special marking)----------------*/
   my.stage       [0] = '\0';
   my.share           = '-';
   my.mark            = '-';
   /*---(working vars)-------------------*/
   my.syst        [0] = '\0';
   my.disp        [0] = '\0';
   my.load        [0] = '\0';
   /*---(complete)-----------------------*/
   DEBUG_INPT   yLOG_sexit   (__FUNCTION__);
   return 0;
}

char         /*--> read script record --------------------[ leaf   [ ------ ]-*/
SCRP_read          (void)
{
   /*---(locals)-----------+-----------+-*/
   int         rc          = 0;             /* generic return code            */
   char        rce         = -10;           /* return code for errors         */
   char        x_recd      [LEN_RECD];
   int         x_len       = 0;             /* input record length            */
   char        t           [LEN_LABEL];
   char       *p           = NULL;
   char       *r           = NULL;
   /*---(header)-------------------------*/
   DEBUG_INPT   yLOG_enter   (__FUNCTION__);
   DEBUG_INPT   yLOG_point   ("*scrp"     , my.f_scrp);
   /*> printf ("SCRP_read enter ------------------------------\n");                   <*/
   /*---(default)------------------------*/
   SCRP_clear  ();
   strcpy (my.recd, "");
   /*---(defense)------------------------*/
   /*> printf ("   my.f_scrp   = %p\n", my.f_scrp);                                   <*/
   --rce;  if (my.f_scrp == NULL) {
      DEBUG_INPT   yLOG_fatal   ("scrp file, file not open");
      DEBUG_INPT   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   /*> printf ("   feof ()     = %d\n", feof (my.f_scrp));                            <*/
   if (feof (my.f_scrp)) {
      DEBUG_INPT   yLOG_note    ("already at end of file");
      DEBUG_INPT   yLOG_exit    (__FUNCTION__);
      return 0;
   }
   /*---(initialize)---------------------*/
   DEBUG_INPT   yLOG_note    ("initialize my.recd");
   my.recd [0] = '\0';
   /*---(read for a good record)---------*/
   --rce;
   while (1) {
      /*---(read next)-------------------*/
      DEBUG_INPT   yLOG_note    ("read script file");
      fgets (x_recd, LEN_RECD, my.f_scrp);
      /*> printf ("   x_recd      = å%sæ\n", x_recd);                                 <*/
      /*> printf ("record = %2d[%s]\n", strlen (x_recd), x_recd);                     <*/
      /*> printf ("   feof ()     = %d\n", feof (my.f_scrp));                         <*/
      if (feof (my.f_scrp)) {
         DEBUG_INPT   yLOG_note    ("hit end of file");
         DEBUG_INPT   yLOG_exit    (__FUNCTION__);
         return 0;
      }
      DEBUG_INPT   yLOG_complex ("line#"     , "%4d my.n_line, %c, %4d my.dline", my.n_line, my.dittoing, my.dline);
      /*> printf ("   SCRP_ditto__handler -- beg\n");                                 <*/
      rc = SCRP_ditto__handler ();
      DEBUG_INPT   yLOG_value   ("handler"   , rc);
      /*> printf ("   rc = %d\n", rc);                                                <*/
      /*> printf ("   SCRP_ditto__handler -- end\n");                                 <*/
      if (rc < 0)  continue;
      /*---(filter)----------------------*/
      x_len = strllen (x_recd, LEN_RECD);
      /*> printf ("   x_len = %d\n", x_len);                                          <*/
      if (x_len > 0)  x_recd [--x_len] = '\0';
      /*> printf ("   check empty\n");                                                <*/
      if (x_recd [0] == '\0') {
         /*> printf ("   -- FOUND empty\n");                                          <*/
         DEBUG_INPT   yLOG_note    ("SKIP, empty");
         /*> printf ("   -- handle ditto if going, %d %c\n", my.dittoing, my.dittoing);   <*/
         if (my.dittoing == 'y')  SCRP_ditto__end ();
         else                      ++my.n_empty;
         /*> printf ("   -- continue to next line\n");                                <*/
         continue;
      }
      /*> printf ("   check comment\n");                                              <*/
      if (x_len > 1 && x_recd [0] == '#' && x_recd [1] != '>') {
         DEBUG_INPT   yLOG_note    ("SKIP, comment");
         if (my.dittoing == 'y')  SCRP_ditto__end ();
         else                     ++my.n_comment;
         continue;
      }
      DEBUG_INPT   yLOG_value   ("length"    , x_len);
      /*> printf ("   check length\n");                                               <*/
      if (x_len <=  5)  {
         DEBUG_INPT   yLOG_note    ("SKIP, too short");
         if (my.dittoing == 'y')  SCRP_ditto__end ();
         else                     ++my.n_short;
         continue;
      }
      /*---(check other end ditto)-------*/
      /*> printf ("   check in-ditto -- beg\n");                                      <*/
      if (my.dittoing == 'y' && my.dline != my.ditto)  {
         strlcpy (t, x_recd, LEN_LABEL);
         p = strtok (t, "");
         p = strtok (p, " ");
         DEBUG_INPT   yLOG_point   ("p"         , p);
         if (p != NULL) {
            strltrim (p, ySTR_BOTH, LEN_LABEL);
            DEBUG_INPT   yLOG_info    ("p"         , p);
            if (strstr ("PREP SCRP SECT SHARED GLOBAL COND GROUP DITTO REUSE", p) != NULL) {
               SCRP_ditto__end ();
               continue;
            }
            if (strstr ("DITTO GROUP REUSE", p) != NULL) {
               continue;
            }
         }
      }
      /*> printf ("   in-ditto -- end\n");                                            <*/
      /*---(translate delayed chars)-----*/
      strlundelay (x_recd, LEN_RECD);
      /*---(copy)------------------------*/
      DEBUG_INPT   yLOG_note    ("save copy of source record");
      strlcpy (my.recd, x_recd, LEN_RECD);
      my.len   = x_len;
      ++my.n_recd;
      break;
   }
   DEBUG_INPT   yLOG_note    ("got a good record");
   /*---(complete)-----------------------*/
   /*> printf ("SCRP_read exit -------------------------------\n");                   <*/
   DEBUG_INPT   yLOG_exit    (__FUNCTION__);
   return 1;
}

char
SCRP__limits            (char *a_min, char *a_max)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   /*---(defense)------------------------*/
   --rce;  if (a_min == NULL)  return rce;
   --rce;  if (a_max == NULL)  return rce;
   /*---(defaults)-----------------------*/
   *a_min = 0;
   *a_max = 0;
   /*---(process)------------------------*/
   --rce;  switch (my.spec) {
   case '1' :  *a_min = 1;  *a_max = 1;    break;
   case 'c' :  *a_min = 1;  *a_max = 1;    break;
   case 'r' :  *a_min = 1;  *a_max = 2;    break;
   case '2' :  *a_min = 2;  *a_max = 2;    break;
   case '3' :  *a_min = 3;  *a_max = 3;    break;
   case 'F' :  *a_min = 3;  *a_max = 3;    break;
   case 's' :  *a_min = 3;  *a_max = 5;    break;
   case 'P' :  *a_min = 4;  *a_max = 4;    break;
   case 'p' :  *a_min = 4;  *a_max = 4;    break;
   case 'f' :  *a_min = 6;  *a_max = 8;    break;
   default  :  return rce;                 break;
   }
   /*---(complete)-----------------------*/
   return 0;
}

char         /*--> parse out current records -------------[ leaf   [ ------ ]-*/
SCRP__current      (char *a_first)
{
   /*---(locals)-----------+-----------+-*/
   int         rc          = 0;             /* generic return code            */
   char        rce         = -10;           /* return code for errors         */
   int         i           = 0;
   char       *p;
   char       *q           = "";
   char        x_min       =    0;
   char        x_max       =    0;
   int         l           =    0;
   /*---(header)-------------------------*/
   DEBUG_INPT   yLOG_enter   (__FUNCTION__);
   /*---(read fields)--------------------*/
   DEBUG_INPT   yLOG_char    ("spec"      , my.spec);
   rc = SCRP__limits (&x_min, &x_max);
   DEBUG_INPT   yLOG_complex ("limits"    , "%4d rc, %d min, %d max", rc, x_min, x_max);
   --rce;  if (rc < 0) {
      yURG_err (YURG_FATAL, "%s:%d:1: error: can not identify %s spec limits", my.n_scrp, my.n_line, my.verb);
      DEBUG_INPT   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   if (my.spec == '1') {
      DEBUG_INPT   yLOG_note    ("one field required and already read as verb");
      DEBUG_INPT   yLOG_exit    (__FUNCTION__);
      return 0;  /* ditto type */
   }
   p = a_first;
   if (p != NULL)  l = strlen (a_first);
   for (i = 2; i < 20; ++i) {
      /*---(clear spacer bars)-----------*/
      if (p [0] == '-' && i != 6) {
         if (strncmp (p, "- - -", 5) == 0)    p [0] = '\0';
         if (strncmp (p, "-----", 5) == 0)    p [0] = '\0';
         if (p [1] == '\0')                   p [0] = '\0';
      }
      /*---(handle fields)---------------*/
      switch (i) {
      case  2 : strlcpy  (my.desc, p        , LEN_FULL);
                strltrim (my.desc, ySTR_BOTH, LEN_FULL);
                break;
      case  3 :   if (my.spec == 's') {
                     if (l == 0 || l > 10)  {
                        strlcpy (my.meth      , p, LEN_HUND );
                        DEBUG_INPT   yLOG_info    ("focus"     , my.meth);
                        x_max = 3;
                     } else {
                        strlcpy (my.test      , p, LEN_LABEL);
                        DEBUG_INPT   yLOG_info    ("duration"  , my.test);
                     }
                  } else if (my.spec != 'p') {
                     strlcpy (my.meth      , p, LEN_HUND );
                     DEBUG_INPT   yLOG_info    ("meth"      , my.meth);
                  }
                  break;
      case  4 :   if      (my.spec == 's') {
                     strlcpy (my.retn      , p, LEN_FULL);
                     DEBUG_INPT   yLOG_info    ("terse tag" , my.retn);
                  } else if (my.spec == 'P' || my.spec == 'p') {
                     strlcpy (my.code      , p, LEN_RECD);
                     DEBUG_INPT   yLOG_info    ("code"      , my.code);
                  } else {
                     strlcpy (my.args      , p, LEN_FULL);
                     strlcpy (my.code      , p, LEN_FULL);
                     DEBUG_INPT   yLOG_info    ("args"      , my.args);
                  }
                  break;
      case  5 :   if (my.spec == 's') {
                     strlcpy (my.meth      , p, LEN_HUND );
                     DEBUG_INPT   yLOG_info    ("focus"     , my.meth);
                  } else {
                     strlcpy (my.test      , p, LEN_LABEL);
                     DEBUG_INPT   yLOG_info    ("test"      , my.test);
                  }
                  break;
      case  6 :   strlcpy (my.expe      , p, LEN_RECD);
                  DEBUG_INPT   yLOG_info    ("expe"      , my.expe);
                  break;
      case  7 :   strlcpy (my.retn      , p, LEN_FULL);
                  DEBUG_INPT   yLOG_info    ("retn"      , my.retn);
                  break;
      }
      /*---(stop parsing summ records)---*/
      if (i >= x_max)    break;
      /*> if (i >= 2 && my.spec == '2')  break;  /+ organization types  +/            <* 
       *> if (i >= 3 && my.spec == '3')  break;  /+ organization types  +/            <* 
       *> if (i >= 4 && my.spec == 'P')  break;  /+ load type           +/            <* 
       *> if (i >= 4 && my.spec == 'p')  break;  /+ code/sys types      +/            <*/
      /*---(next record)-----------------*/
      DEBUG_INPT   yLOG_note    ("read next field");
      p = strtok (NULL  , q);
      --rce;  if (p == NULL) {
         DEBUG_INPT   yLOG_note    ("strtok came up empty");
         break;
      }
      l = strlen (p);
      strltrim (p, ySTR_BOTH, LEN_RECD);
   } 
   /*---(stop parsing summ records)---*/
   if (i < x_min) {
      yURG_err (YURG_FATAL, "%s:%d:1: error: too few fields (%d) for %s, requires %d", my.n_scrp, my.n_line, i, my.verb, x_min);
      DEBUG_INPT   yLOG_complex ("too few"   , "%d actual < %d min", i, x_min);
      DEBUG_INPT   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }

   /*> switch (my.spec) {                                                             <* 
    *> case '1' : if (i <  1)  rc = rce;  break;                                      <* 
    *> case 'c' : if (i <  1)  rc = rce;  break;                                      <* 
    *> case '2' : if (i <  2)  rc = rce;  break;                                      <* 
    *> case '3' : if (i <  3)  rc = rce;  break;                                      <* 
    *> case 'P' : if (i <  4)  rc = rce;  break;                                      <* 
    *> case 'p' : if (i <  4)  rc = rce;  break;                                      <* 
    *> case 'f' : if (i <  6)  rc = rce;  break;                                      <* 
    *> }                                                                              <*/
   DEBUG_INPT   yLOG_exit    (__FUNCTION__);
   return 0;
}

char         /*--> parse out a v21 records ---------------[ leaf   [ ------ ]-*/
SCRP_vers21        (void)
{
   /*---(design notes)-------------------*/
   /*
    *   version 21 of the script fields moved the code/load/sys payload to
    *   the 4th field (from the 3rd) for strictly ascetheic reasons so it
    *   would be easier to read and edit the scrits.
    *
    */
   /*---(locals)-----------+-----------+-*/
   int         rc          = 0;             /* generic return code            */
   char        rce         = -10;           /* return code for errors         */
   int         i           = 0;
   char       *p;
   char       *q           = "";
   /*---(read fields)--------------------*/
   for (i = 2; i < 20; ++i) {
      DEBUG_INPT   yLOG_note    ("read next field");
      p = strtok (NULL  , q);
      --rce;  if (p == NULL) {
         DEBUG_INPT   yLOG_note    ("strtok came up empty");
         DEBUG_INPT   yLOG_exit    (__FUNCTION__);
         break;
      }
      strltrim (p, ySTR_BOTH, LEN_RECD);
      /*---(clear spacer bars)-----------*/
      if (p[0] == '-') {  /* begin careful to avoid negative numbers ;)) */
         switch (p[1]) {
         case ' '  :   /* catches "- - - - - - -" lines */
         case '-'  :   /* catches "-------------" lines */
         case '\0' :   /* catches "-" placeholder lines */
            p[0] = '\0';
            break;
         }
      }
      /*---(handle fields)---------------*/
      switch (i) {
      case  2 :   strlcpy (my.desc      , p, LEN_LONG );
                  DEBUG_INPT   yLOG_info    ("desc"      , my.desc);
                  break;
      case  3 :   if (my.spec != 'p') {
                     strlcpy (my.meth      , p, LEN_HUND );
                     DEBUG_INPT   yLOG_info    ("meth"      , my.meth);
                  }
                  break;
      case  4 :   if (my.spec == 'P' || my.spec == 'p') {
                     strlcpy (my.code      , p, LEN_RECD);
                     DEBUG_INPT   yLOG_info    ("code"      , my.code);
                  } else {
                     strlcpy (my.args      , p, LEN_FULL);
                     strlcpy (my.code      , p, LEN_FULL);
                     DEBUG_INPT   yLOG_info    ("args"      , my.args);
                  }
                  break;
      case  5 :   strlcpy (my.test      , p, LEN_LABEL);
                  DEBUG_INPT   yLOG_info    ("test"      , my.test);
                  break;
      case  6 :   strlcpy (my.expe      , p, LEN_RECD);
                  DEBUG_INPT   yLOG_info    ("expe"      , my.expe);
                  break;
      case  7 :   strlcpy (my.retn      , p, LEN_FULL);
                  DEBUG_INPT   yLOG_info    ("retn"      , my.retn);
                  break;
      }
      /*---(stop parsing summ records)---*/
      if (i >= 2 && my.spec == '2')  break;  /* organization types  */
      if (i >= 3 && my.spec == '-')  break;  /* organization types  */
      if (i >= 4 && my.spec == 'P')  break;  /* load type           */
      if (i >= 4 && my.spec == 'p')  break;  /* code/sys types      */
   } 
   return 0;
}

char         /*--> parse out a v20 records ---------------[ leaf   [ ------ ]-*/
SCRP_vers20        (void)
{
   /*---(design notes)-------------------*/
   /*
    *   version 20 of the script fields added a version number to the records
    *   to allow easier conversion and more flexible updating.  i decided to
    *   put this field up front to make paring much easier.
    *
    */
   /*---(locals)-----------+-----------+-*/
   int         rc          = 0;             /* generic return code            */
   char        rce         = -10;           /* return code for errors         */
   int         i           = 0;
   char       *p;
   char       *q           = "";
   /*---(read fields)--------------------*/
   for (i = 2; i < 20; ++i) {
      /*---(read field)------------------*/
      DEBUG_INPT   yLOG_note    ("read next field");
      p = strtok (NULL  , q);
      --rce;  if (p == NULL) {
         DEBUG_INPT   yLOG_note    ("strtok came up empty");
         DEBUG_INPT   yLOG_exit    (__FUNCTION__);
         break;
      }
      strltrim (p, ySTR_BOTH, LEN_RECD);
      /*---(clear spacer bars)-----------*/
      if (p[0] == '-' && i != 6) {
         switch (p[1]) {
         case ' '  :   /* catches "- - - - - - -" lines */
         case '-'  :   /* catches "-------------" lines */
         case '\0' :   /* catches "-" placeholder lines */
            p[0] = '\0';
            break;
         }
      }
      /*---(handle fields)---------------*/
      switch (i) {
      case  2 :   strlcpy (my.desc      , p, LEN_LONG );
                  DEBUG_INPT   yLOG_info    ("desc"      , my.desc);
                  break;
      case  3 :   if (my.spec == 'p') {
                     strlcpy (my.code      , p, LEN_RECD);
                     DEBUG_INPT   yLOG_info    ("code"      , my.code);
                  } else {
                     strlcpy (my.meth      , p, LEN_HUND );
                     DEBUG_INPT   yLOG_info    ("meth"      , my.meth);
                  }
                  break;
      case  4 :   strlcpy (my.args      , p, LEN_FULL);
                  strlcpy (my.code      , p, LEN_FULL);
                  DEBUG_INPT   yLOG_info    ("args"      , my.args);
                  break;
      case  5 :   strlcpy (my.test      , p, LEN_LABEL);
                  DEBUG_INPT   yLOG_info    ("test"      , my.test);
                  break;
      case  6 :   strlcpy (my.expe      , p, LEN_RECD);
                  DEBUG_INPT   yLOG_info    ("expe"      , my.expe);
                  break;
      case  7 :   strlcpy (my.retn      , p, LEN_FULL);
                  DEBUG_INPT   yLOG_info    ("retn"      , my.retn);
                  break;
      }
      /*---(stop parsing summ records)---*/
      if (i >= 3 && my.spec == '-')  break;  /* organization types  */
      if (i >= 3 && my.spec == 'p')  break;  /* code/load/sys types */
   } 
   return 0;
}

char         /*--> parse out original records ------------[ leaf   [ ------ ]-*/
SCRP_vers19        (void)
{
   /*---(design notes)-------------------*/
   /*
    *   version 19, and before, of the script fields had no version number
    *
    */
   /*---(locals)-----------+-----------+-*/
   int         rc          = 0;             /* generic return code            */
   char        rce         = -10;           /* return code for errors         */
   int         i           = 0;
   char       *p;
   char       *q           = "";
   /*---(read fields)--------------------*/
   for (i = 2; i < 20; ++i) {
      DEBUG_INPT   yLOG_note    ("read next field");
      p = strtok (NULL  , q);
      --rce;  if (p == NULL) {
         DEBUG_INPT   yLOG_note    ("strtok came up empty");
         DEBUG_INPT   yLOG_exit    (__FUNCTION__);
         break;
      }
      strltrim (p, ySTR_BOTH, LEN_RECD);
      /*---(clear spacer bars)-----------*/
      if (p [0] == '-') {
         if (strncmp (p, "- - -", 5) == 0)    p [0] = '\0';
         if (strncmp (p, "-----", 5) == 0)    p [0] = '\0';
         if (p [1] == '\0')                   p [0] = '\0';
      }
      /*---(handle fields)---------------*/
      switch (i) {
      case  2 :   if (my.spec == 'p') {
                     strlcpy (my.code      , p, LEN_RECD);
                     DEBUG_INPT   yLOG_info    ("code"      , my.code);
                  } else {
                     strlcpy (my.meth      , p, LEN_HUND );
                     DEBUG_INPT   yLOG_info    ("meth"      , my.meth);
                  }
                  break;
      case  3 :   strlcpy (my.args      , p, LEN_FULL);
                  strlcpy (my.code      , p, LEN_FULL);
                  DEBUG_INPT   yLOG_info    ("args"      , my.args);
                  break;
      case  4 :   strlcpy (my.test      , p, LEN_LABEL);
                  DEBUG_INPT   yLOG_info    ("test"      , my.test);
                  break;
      case  5 :   strlcpy (my.expe      , p, LEN_RECD);
                  DEBUG_INPT   yLOG_info    ("expe"      , my.expe);
                  break;
      }
      if (i >= 2 && my.spec == '-')  break;  /* organization types  */
      if (i >= 2 && my.spec == 'p')  break;  /* code/load/sys types */
   } 
   return 0;
}

char
SCRP_parse_defense   (void)
{
   /*---(locals)-----------+-----------+-*/
   char        rce         = -10;           /* return code for errors         */
   /*---(header)-------------------------*/
   DEBUG_INPT   yLOG_senter  (__FUNCTION__);
   DEBUG_INPT   yLOG_spoint  (my.f_scrp);
   --rce;  if (my.f_scrp == NULL) {
      DEBUG_INPT   yLOG_snote   ("file not open");
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_INPT   yLOG_sint    (my.recd [0]);
   --rce;  if (my.recd [0] == '\0') {
      DEBUG_INPT   yLOG_snote   ("null record in my.recd");
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_INPT   yLOG_sint    (my.len);
   --rce;  if (my.len <  5 && my.recd [0] != '#') {
      DEBUG_INPT   yLOG_snote   ("my.len too short");
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_INPT   yLOG_sexit   (__FUNCTION__);
   return 0;
}

char
SCRP_parse_comment      (void)
{
   /*---(locals)-----------+-----+-----+-*/
   int         i           =    0;
   /*---(header)-------------------------*/
   DEBUG_INPT   yLOG_senter  (__FUNCTION__);
   /*---(ward-off)-----------------------*/
   DEBUG_INPT   yLOG_sint    (my.len);
   if (my.len < 2) {
      DEBUG_INPT   yLOG_snote   ("too short");
      DEBUG_INPT   yLOG_sexit   (__FUNCTION__);
      return 0;
   }
   if (strncmp (my.recd, "#>", 2) != 0) {
      DEBUG_INPT   yLOG_snote   ("not prefixed with #>");
      DEBUG_INPT   yLOG_sexit   (__FUNCTION__);
      return 0;
   }
   /*---(check for marker)---------------*/
   DEBUG_INPT   yLOG_snote   ("saved record/comment");
   for (i = 0; i < MAX_VERB; ++i) {
      if (strcmp (g_verbs [i].name, "#>") != 0) continue;
      strlcpy (my.verb, g_verbs [i].name, LEN_LABEL);
      my.indx    = i;
      ++g_verbs [i].count;
      ++g_verbs [i].total;
      my.spec    = g_verbs [i].spec;
      DEBUG_INPT   yLOG_sint    (g_verbs [i].count);
   }
   /*---(complete)-----------------------*/
   DEBUG_INPT   yLOG_sexit   (__FUNCTION__);
   return 1;
}

char
SCRP_parse_verb         (char *p)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   int         i           =    0;
   int         x_len       =    0;
   char        x_verb      [LEN_LABEL] = "";
   char       *q           = NULL;
   /*---(header)-------------------------*/
   DEBUG_INPT   yLOG_senter  (__FUNCTION__);
   /*---(defaults)-----------------------*/
   strlcpy  (my.verb , "", LEN_LABEL);
   my.p_conv = NULL;
   my.p_code = NULL;
   my.indx   = -1;
   /*---(defense)------------------------*/
   DEBUG_INPT   yLOG_spoint  (p);
   --rce;  if (p == NULL || strlen (p) <= 0) {
      yURG_err (YURG_FATAL, "%s:%d:1: error: no verb found", my.n_scrp, my.n_line);
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   strlcpy  (x_verb, p, LEN_FULL);
   strltrim (x_verb, ySTR_BOTH, LEN_FULL);
   q = strchr (x_verb, ' ');
   if (q != NULL)  q [0] = '\0';
   x_len = strlen (x_verb);
   DEBUG_INPT   yLOG_sint    (x_len);
   --rce;  if (x_len <= 2) {
      yURG_err (YURG_FATAL, "%s:%d:1: error: verb <%s> is too short (%d <= 2)", my.n_scrp, my.n_line, x_verb, x_len);
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_INPT   yLOG_snote   (x_verb);
   /*---(filter comments)----------------*/
   --rce;  if (x_verb [0] == '#') {
      yURG_err (YURG_FATAL, "%s:%d:1: error: comment not in column one", my.n_scrp, my.n_line);
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(find verb)----------------------*/
   my.indx = -1;
   for (i = 0; i < MAX_VERB; ++i) {
      if (g_verbs [i].name [0] == '-')                break;
      if (g_verbs [i].name [0] != x_verb[0])          continue;
      if (strcmp (g_verbs [i].name, x_verb) != 0)     continue;
      /*---(save values)-----------------*/
      DEBUG_INPT   yLOG_snote   ("verb found");
      strlcpy (my.verb, g_verbs [i].name, LEN_LABEL);
      my.indx    = i;
      my.p_conv  = g_verbs [i].conv;
      my.p_code  = g_verbs [i].code;
      ++g_verbs [i].count;
      ++g_verbs [i].total;
      my.spec    = g_verbs [i].spec;
      DEBUG_INPT   yLOG_sint    (g_verbs [i].count);
      break;
      /*---(done)------------------------*/
   }
   /*---(failure)------------------------*/
   --rce;  if (my.indx == -1) {
      yURG_err (YURG_FATAL, "%s:%d:1: error: verb <%s> not recognized/found", my.n_scrp, my.n_line, x_verb);
      DEBUG_INPT   yLOG_snote   ("verb not found");
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(file limitations)---------------*/
   --rce;  IF_MASTER {
      if (g_verbs [my.indx].files == 'n') {
         DEBUG_INPT   yLOG_snote   ("verb not allowed in master.unit");
         yURG_err (YURG_FATAL, "%s:%d:1: error: %s verb not allowed inside master.unit", my.n_scrp, my.n_line, my.verb);
         DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
         return rce;
      }
   }
   --rce;  IF_NORMAL {
      if (g_verbs [my.indx].files == 'm') {
         DEBUG_INPT   yLOG_snote   ("verb not allowed outside master.unit");
         yURG_err (YURG_FATAL, "%s:%d:1: error: %s verb not allowed outside master.unit", my.n_scrp, my.n_line, my.verb);
         DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
         return rce;
      }
   }
   /*---(complete)-----------------------*/
   DEBUG_INPT   yLOG_sexit   (__FUNCTION__);
   return 0;
}

char
SCRP_parse_stage        (char *p)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   int         x_len       =    0;
   char        t           [LEN_LABEL] = "";
   char       *q           = NULL;
   /*---(header)-------------------------*/
   DEBUG_INPT   yLOG_senter  (__FUNCTION__);
   /*---(defaults)-----------------------*/
   strlcpy  (my.stage, "", LEN_LABEL);
   /*---(ward-off)-----------------------*/
   if (my.indx < 0 || strcmp ("SCRP" , my.verb) != 0) {
      DEBUG_INPT   yLOG_snote   ("only applies to scripts");
      DEBUG_INPT   yLOG_sexit   (__FUNCTION__);
      return 0;
   }
   /*---(prepare)------------------------*/
   strlcpy  (t, p, LEN_LABEL);
   strltrim (t, ySTR_BOTH, LEN_LABEL);
   x_len = strlen (t);
   /*---(check markers)------------------*/
   q = strchr (t, '[');
   if (q == NULL && x_len == 4) {
      DEBUG_INPT   yLOG_snote   ("no brackets, ok");
      DEBUG_INPT   yLOG_sexit   (__FUNCTION__);
      return 0;
   }
   --rce;  if (q == NULL || q [3] != ']') {
      yURG_err (YURG_FATAL, "%s:%d:3: error: %s identifier, uses wrong brackets, e.g., [´ì]", my.n_scrp, my.n_line, my.verb);
      DEBUG_INPT   yLOG_snote   ("does not begin right");
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(positions)----------------------*/
   --rce;  if (strchr ("·´ Ï¬°", q [1]) == NULL) {
      yURG_err (YURG_FATAL, "%s:%d:1: error: %s identifier, ·´ Ï¬° wave, e.g., [´ì]", my.n_scrp, my.n_line, my.verb);
      DEBUG_INPT   yLOG_snote   ("does not lead with symbol");
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   --rce;  if (strchr (YSTR_GREEK "-", q [2]) == NULL) {
      yURG_err (YURG_FATAL, "%s:%d:2: error: %s identifier, not greek letter for stage, e.g., [´ì]", my.n_scrp, my.n_line, my.verb);
      DEBUG_INPT   yLOG_snote   ("does not end with greek letter");
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(save)---------------------------*/
   q [3] = '\0';
   strlcpy (my.stage, q + 1, LEN_LABEL);
   /*---(complete)-----------------------*/
   DEBUG_INPT   yLOG_sexit   (__FUNCTION__);
   return 0;
}

char
SCRP_write_wave         (void)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        x_stage     = '-';
   char        x_wave      = '-';
   static char x_scrp      =   0;
   /*---(header)-------------------------*/
   DEBUG_INPT   yLOG_senter  (__FUNCTION__);
   /*---(ward-off)-----------------------*/
   --rce;  if (my.indx < 0 || strcmp ("SCRP" , g_verbs [my.indx].name) != 0) {
      DEBUG_INPT   yLOG_snote   ("only applies to scripts");
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(script entry in wave)-----------*/
   ++x_scrp;
   if (strlen (my.stage) == 2) {
      x_stage = my.stage [0];
      x_wave  = my.stage [1];
   }
   WAVE_printf ("%c  %c  %-25.25s  %2d  %-65.65s \n", x_stage, x_wave, my.n_base, x_scrp, my.desc);
   /*---(complete)-----------------------*/
   DEBUG_INPT   yLOG_sexit   (__FUNCTION__);
   return 0;
}

char         /*--> parse out a script record -------------[ leaf   [ ------ ]-*/
SCRP_parse         (void)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   int         rc          = 0;             /* generic return code            */
   char        x_recd      [LEN_RECD];
   int         x_len       = 0;             /* input record length            */
   char       *p;
   char       *q           = "";
   char       *r           = NULL;
   int         i           = 0;
   /*---(header)-------------------------*/
   DEBUG_INPT   yLOG_enter   (__FUNCTION__);
   /*---(prepare)---------------------*/
   /*> SCRP_clear  ();                                                                <*/
   /*---(defense)---------------------*/
   rc = SCRP_parse_defense ();
   DEBUG_INPT   yLOG_value   ("defense"   , rc);
   /*> printf ("defense %d\n", rc);                                                   <*/
   --rce;  if (rc < 0) {
      DEBUG_INPT   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(saved comments)-----------------*/
   rc = SCRP_parse_comment ();
   /*> printf ("comment %d\n", rc);                                                   <*/
   DEBUG_INPT   yLOG_value   ("comment"   , rc);
   --rce;  if (rc != 0) {
      DEBUG_INPT   yLOG_exit    (__FUNCTION__);
      return 0;
   }
   /*---(create a copy of recd)----------*/
   strlcpy (x_recd, my.recd, LEN_RECD);
   DEBUG_INPT   yLOG_info    ("x_recd"    , x_recd);
   /*---(get verb)-----------------------*/
   p = strtok (x_recd, q);
   rc = SCRP_parse_verb (p);
   /*> printf ("verb %d\n", rc);                                                      <*/
   DEBUG_INPT   yLOG_value   ("verb"      , rc);
   --rce;  if (rc < 0) {
      DEBUG_INPT   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(check for shares)---------------*/
   rc = SCRP__reuses_check (p);
   DEBUG_INPT   yLOG_value   ("reuses"    , rc);
   --rce;  if (rc < 0) {
      DEBUG_INPT   yLOG_exitr   (__FUNCTION__, rc);
      return rce;
   }
   /*---(check for ditto)----------------*/
   rc = SCRP__ditto_check (p);
   DEBUG_INPT   yLOG_value   ("ditto"     , rc);
   --rce;  if (rc < 0) {
      DEBUG_INPT   yLOG_exitr   (__FUNCTION__, rc);
      return rce;
   }
   if (rc >  0) {
      DEBUG_INPT   yLOG_note    ("FOUND DITTO, back to reading");
      DEBUG_INPT   yLOG_exit    (__FUNCTION__);
      return 0;
   }
   /*---(check for ditto)----------------*/
   rc = SCRP_parse_stage (p);
   DEBUG_INPT   yLOG_value   ("stage"     , rc);
   --rce;  if (rc < 0) {
      DEBUG_INPT   yLOG_exitr   (__FUNCTION__, rc);
      return rce;
   }
   /*---(read version)-------------------*/
   p = strtok (NULL  , q);
   --rce;  if (p == NULL && my.spec != 'c') {
      yURG_err (YURG_FATAL, "%s:%d:1: error: verb only, %s requires more fields", my.n_scrp, my.n_line, my.verb);
      DEBUG_INPT   yLOG_note    ("strtok came up empty");
      DEBUG_INPT   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   strltrim (p, ySTR_BOTH, LEN_RECD);
   x_len = strlen (p);
   if (p[0] == '-')  p[0] = '\0';
   rc = 0;
   if      (x_len != 3 || p [0] != 'v') {
      if (my.spec != 'c')  rc = SCRP__current (p);
   } else if (strcmp (p, "v21") == 0) {
      strlcpy (my.vers      , p    , LEN_LABEL);
      DEBUG_INPT   yLOG_info    ("vers"      , my.vers);
      if (my.spec != 'c')  rc = SCRP_vers21  ();
   } else if (strcmp (p, "v20") == 0) {
      strlcpy (my.vers      , p    , LEN_LABEL);
      DEBUG_INPT   yLOG_info    ("vers"      , my.vers);
      if (my.spec != 'c')  rc = SCRP_vers20  ();
   } else                             {
      strlcpy (my.vers      , "v19", LEN_LABEL);
      DEBUG_INPT   yLOG_info    ("vers"      , my.vers);
      strlcpy (my.desc      , p    , LEN_LONG );
      DEBUG_INPT   yLOG_info    ("desc"      , my.desc);
      if (my.spec != 'c')  rc = SCRP_vers19  ();
   }
   if (rc < 0) {
      DEBUG_INPT   yLOG_note    ("trouble parsing");
      DEBUG_INPT   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   /*---(complete)-----------------------*/
   DEBUG_INPT   yLOG_exit    (__FUNCTION__);
   return 0;
}


char         /*--> close script file ---------------------[ ------ [ ------ ]-*/
SCRP_verbs         (void)
{
   int         i           = 0;
   int         c           = 0;
   printf ("verb counts...\n");
   for (i = 0; i < MAX_VERB; ++i) {
      printf  ("   %-10s  %4d\n", g_verbs [i].name, g_verbs [i].total);
      c += g_verbs [i].total;
      if (g_verbs [i].name [0] == '-') break;
   }
   printf  ("   %-10s  %4d\n", "TOTAL"   , c);
   printf  ("   %-10s  %4d\n", "concerns", my.n_recd - c);
   return 0;
}

char         /*--> close script file ---------------------[ ------ [ ------ ]-*/
SCRP_verbcode      (void)
{
   int         i           = 0;
   int         c           = 0;
   CODE_printf ("\n");
   CODE_printf ("char\n");
   CODE_printf ("UNIT_verbs (void)\n");
   CODE_printf ("{\n");
   CODE_printf ("   printf (\"koios, record type summary\\n\");\n");
   for (i = 0; i < MAX_VERB; ++i) {
      CODE_printf ("   printf (\"%-10.10s = %5d   %s\\n\");\n", g_verbs [i].name, g_verbs [i].total, g_verbs [i].desc);
      c += g_verbs [i].total;
      if (g_verbs [i].name [0] == '-') break;
   }
   CODE_printf ("   printf (\"%-10.10s = %5d   %s\\n\");\n", "TOTAL"         , c                , "sum of all verbs");
   CODE_printf ("   printf (\"%-10.10s = %5d   %s\\n\");\n", "concerns"      , my.n_recd - c    , "records with troubles");
   CODE_printf ("   return 0;\n");
   CODE_printf ("}\n");
   CODE_printf ("\n");
   return 0;
}



/*====================------------------------------------====================*/
/*===----                         unit testing                         ----===*/
/*====================------------------------------------====================*/
static void      o___UNITTEST________________o (void) {;};

char*      /*----: unit testing accessor for clean validation interface ------*/
SCRP__unit              (char *a_question, int a_num)
{
   /*---(locals)-----------+-----+-----+-*/
   int         i           =    0;
   char        s           [LEN_LABEL];
   char        t           [LEN_RECD ];
   /*---(preprare)-----------------------*/
   strlcpy  (my.answer, "SCRP unit      : question not understood", LEN_FULL);
   if      (strcmp (a_question, "file"      ) == 0) {
      sprintf (my.answer, "SCRP file      : %-35.35s %p", my.n_scrp, my.f_scrp);
   }
   else if (strcmp (a_question, "recd"      ) == 0) {
      strlcpy    (t, my.recd, LEN_RECD);
      strlencode (t, ySTR_NONE, LEN_RECD);
      sprintf (my.answer, "SCRP recd      : %2d %3d[%.40s]", my.n_line, strlen (t), t);
   }
   else if (strcmp (a_question, "verb"      ) == 0) {
      sprintf (my.answer, "SCRP verb      : %-10.10s %3d[%.30s]", my.verb, strlen (my.desc), my.desc);
   }
   else if (strcmp (a_question, "call"      ) == 0) {
      sprintf (t, "[%.20s]", my.meth);
      sprintf (my.answer, "SCRP call      : %3d%-22.22s %3d[%.20s]", strlen (my.meth), t, strlen (my.args), my.args);
   }
   else if (strcmp (a_question, "test"      ) == 0) {
      sprintf (my.answer, "SCRP test      : %-10.10s %3d[%.30s]", my.test, strlen (my.expe), my.expe);
   }
   else if (strcmp (a_question, "retn"      ) == 0) {
      sprintf (my.answer, "SCRP retn      : %c          %3d[%.30s]", my.test [0], strlen (my.retn), my.retn);
   }
   else if (strcmp (a_question, "code"      ) == 0) {
      strlcpy    (t, my.code, LEN_RECD);
      strlencode (t, ySTR_NONE, LEN_RECD);
      sprintf (my.answer, "SCRP code      : %3d[%.40s]", strlen (t), t);
   }
   else if (strcmp (a_question, "mark"      ) == 0) {
      sprintf (my.answer, "SCRP mark      : %c", my.mark);
   }
   else if (strcmp (a_question, "ditto"     ) == 0) {
      sprintf (my.answer, "SCRP ditto     : %2d  %c  %-10p  %-10p  %3d", my.ditto, my.dittoing, s_file_save, s_file_ditto, my.dline);
   }
   else if (strcmp (a_question, "dittos"    ) == 0) {
      strlcpy (t, "", LEN_RECD);
      for (i = 0; i < 15; ++i) {
         if (s_dittos [i] > 0)  sprintf (s, " %2d", s_dittos [i]);
         else                   sprintf (s, "  -");
         strlcat (t, s, LEN_RECD);
      }
      sprintf (my.answer, "SCRP dittos A-O:%s", t);
   }
   /*---(complete)-----------------------*/
   return my.answer;
}

/*===============================[[ end code ]]===============================*/
