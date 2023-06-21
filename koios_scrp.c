/*===============================[[ beg-code ]]===============================*/
#include    "koios.h"        /* LOCAL  : main header                          */



char    g_print     [LEN_LABEL] = "";


static  FILE *s_file_save;
static  FILE *s_file_ditto;

static  int   s_master [26] = { -1 };
static  int   s_reuses [26] = { -1 };
static  int   s_dittos [26] = { -1 };

/*> tVERB       g_verbs [MAX_VERB] = {                                                                                   <* 
 *>    /+ --global------   ---desc-------------------------------- spec file cnt tot  ---conv------   ---code------ +/   <* 
 *>    { "GLOBAL"       , "shared code between units"             , 's', 'm',  0,  0, CONV_global   , CODE_global   },   <* 
 *>    /+ --units-------   ---------------------------------------   -  +/                                               <* 
 *>    { "PREP"         , "preparation before testing"            , '2', '-',  0,  0, CONV_prep     , CODE_prep     },   <* 
 *>    { "incl"         , "c header inclusion"                    , '3', '-',  0,  0, CONV_incl     , CODE_incl     },   <* 
 *>    { "#>"           , "script internal comments"              , 'c', '-',  0,  0, CONV_comment  , NULL          },   <* 
 *>    /+ --scrps-------   --------------------------------------- +/                                                    <* 
 *>    { "SCRP"         , "test script"                           , 's', 'n',  0,  0, CONV_scrp     , CODE_scrp     },   <* 
 *>    { "SECT"         , "grouping of scripts"                   , '2', 'n',  0,  0, CONV_sect     , CODE_sect     },   <* 
 *>    { "SHARED"       , "shared code between scripts"           , 's', 'n',  0,  0, CONV_shared   , CODE_shared   },   <* 
 *>    /+ --conds-------   --------------------------------------- +/                                                    <* 
 *>    { "GROUP"        , "grouping of conditions"                , '2', '-',  0,  0, CONV_group    , CODE_group    },   <* 
 *>    { "COND"         , "test condition"                        , '2', '-',  0,  0, CONV_cond     , CODE_cond     },   <* 
 *>    { "DITTO"        , "repeated test condition"               , '1', '-',  0,  0, CONV_ditto    , NULL          },   <* 
 *>    { "REUSE"        , "inclusion of shared code"              , 'r', '-',  0,  0, CONV_reuse    , CODE_reuse    },   <* 
 *>    /+ --steps-------   --------------------------------------- +/                                                    <* 
 *>    { "exec"         , "function execution"                    , 'f', '-',  0,  0, CONV_exec     , CODE_exec     },   <* 
 *>    { "get"          , "unit test accessor retrieval"          , 'f', '-',  0,  0, CONV_exec     , CODE_exec     },   <* 
 *>    /+ --specialty---   --------------------------------------- +/                                                    <* 
 *>    { "global"       , "global/unit variable definition"       , 'p', '-',  0,  0, CONV_gvar     , CODE_gvar     },   <* 
 *>    { "local"        , "local/script variable deinition"       , 'p', '-',  0,  0, CONV_code     , CODE_lvar     },   <* 
 *>    { "code"         , "insert c code"                         , 'p', '-',  0,  0, CONV_code     , CODE_code     },   <* 
 *>    { "echo"         , "test a variable directly"              , 'f', '-',  0,  0, CONV_echo     , CODE_echo     },   <* 
 *>    { "system"       , "execute shell code"                    , 'p', '-',  0,  0, CONV_code     , CODE_system   },   <* 
 *>    { "load"         , "place data into stdin"                 , 'P', '-',  0,  0, CONV_load     , CODE_load     },   <* 
 *>    { "file"         , "create a temporary file"               , 'p', '-',  0,  0, CONV_file     , CODE_file     },   <* 
 *>    { "append"       , "append data to temporary file"         , 'p', '-',  0,  0, CONV_append   , CODE_append   },   <* 
 *>    { "mode"         , "set pass or forced_fail mode"          , '2', '-',  0,  0, CONV_mode     , CODE_mode     },   <* 
 *>    /+ --ouroboros---   --------------------------------------- +/                                                    <* 
 *>    { "WAVE"         , "testing wave"                          , '2', 'm',  0,  0, NULL          , NULL          },   <* 
 *>    { "stage"        , "testing stage"                         , '2', 'm',  0,  0, NULL          , NULL          },   <* 
 *>    /+ --sentinal----   --------------------------------------- +/                                                    <* 
 *>    { "----"         , "end-of-entries"                        , '-', '-',  0,  0, NULL          , NULL          },   <* 
 *>    /+ --done--------   --------------------------------------- +/                                                    <* 
 *> };                                                                                                                   <*/



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
      case T_SHARES : s_reuses [i] = -1;              break;
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
   SCRP__shared_clear (T_SHARES);
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
   case T_SHARES : x_valid = YSTR_LOWER;   break;
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
SCRP__shared_set        (cchar a_type, cchar a_mark, int a_line)
{
   /*---(locals)-------------------------*/
   char        i           =  -10;
   /*---(get index)----------------------*/
   i = SCRP__shared_index (a_type, a_mark);
   if (i < 0) return i;
   /*---(update list)--------------------*/
   switch (a_type) {
   case T_MASTER : s_master [i] = a_line;   break;
   case T_SHARES : s_reuses [i] = a_line;   break;
   case T_DITTOS : s_dittos [i] = a_line;   break;
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
   case T_SHARES : x_line = s_reuses [i];   break;
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
SCRP_ditto__handler     (char a_dittoing, int a_ditto, int *r_nline, int *r_dline)
{
   /*---(locals)-----------+-----------+-*/
   char        rce         =  -10;
   /*---(header)-------------------------*/
   DEBUG_INPT   yLOG_senter  (__FUNCTION__);
   /*---(defense)------------------------*/
   DEBUG_INPT   yLOG_spoint  (r_nline);
   --rce;  if (r_nline == NULL) {
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_INPT   yLOG_spoint  (r_dline);
   --rce;  if (r_dline == NULL) {
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(check for no ditto)-------------*/
   DEBUG_INPT   yLOG_schar   (a_dittoing);
   if (a_dittoing != 'y') {
      DEBUG_INPT   yLOG_snote   ("not dittoing");
      ++(*r_nline);
      DEBUG_INPT   yLOG_sint    (*r_nline);
      DEBUG_INPT   yLOG_sexit   (__FUNCTION__);
      return 0;
   }
   /*---(update ditto line)--------------*/
   ++(*r_dline);
   DEBUG_INPT   yLOG_sint    (*r_dline);
   DEBUG_INPT   yLOG_sint    (a_ditto);
   /*---(check for pre-ditto)------------*/
   if (*r_dline <  a_ditto) {
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
SCRP__reuses_check      (cchar a_scrp [LEN_TITLE], int a_line, char a_indx, char *p, char a_cshare, char *r_share, char *r_dittoing, char *r_dmark, char *r_mark, int *r_ditto, int *r_dline)
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
      yURG_err (YURG_FATAL, "%s:%d:1: error: GLOBAL/SHARED/REUSE called with a null string", a_scrp, a_line);
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_INPT   yLOG_snote   (p);
   /*---(check for right verbs)----------*/
   strcpy (t, g_verbs [a_indx].name);
   if (strstr (" GLOBAL SHARED REUSE " , t) == NULL) {
      DEBUG_INPT   yLOG_snote   ("this only applies to GLOBAL/SHARED/REUSE");
      DEBUG_INPT   yLOG_sexit   (__FUNCTION__);
      return 0;
   }
   /*---(check for marker)---------------*/
   q = strchr (p, '-');
   DEBUG_INPT   yLOG_spoint  (q);
   --rce;  if (q == NULL) {
      yURG_err (YURG_FATAL, "%s:%d:1: error: %s missing a valid identifier string -?-", a_scrp, a_line, t);
      DEBUG_INPT   yLOG_snote   ("no openning marker");
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   --rce;  if (q [1] == NULL) {
      yURG_err (YURG_FATAL, "%s:%d:1: error: %s identifier did not follow - marker", a_scrp, a_line, t);
      DEBUG_INPT   yLOG_snote   ("no identifer");
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   --rce;  if (q [1] == '-') {
      yURG_err (YURG_FATAL, "%s:%d:1: error: %s no identifier within -- markers", a_scrp, a_line, t);
      DEBUG_INPT   yLOG_snote   ("no identifer inside");
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   m = q [1];
   DEBUG_INPT   yLOG_schar   (m);
   --rce;  if (q [2] != '-') {
      yURG_err (YURG_FATAL, "%s:%d:1: error: %s identifier å%cæ not followed by - marker", a_scrp, a_line, t, m);
      DEBUG_INPT   yLOG_snote   ("no close marker");
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(validate marker)----------------*/
   n  = SCRP__shared_get (T_MASTER, m);
   DEBUG_INPT   yLOG_sint    (n);
   o  = SCRP__shared_get (T_SHARES, m);
   DEBUG_INPT   yLOG_sint    (o);
   /*---(handle global)------------------*/
   --rce;  if (strcmp ("GLOBAL" , g_verbs [a_indx].name) == 0) {
      DEBUG_INPT   yLOG_snote   ("handle global");
      IF_NORMAL {
         DEBUG_INPT   yLOG_snote   ("GLOBAL only allowed in master.unit");
         yURG_err (YURG_FATAL, "%s:%d:1: error: GLOBAL not allowed outside master.unit", a_scrp, a_line);
         DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
         return rce;
      }
      if (n < -1) {
         DEBUG_INPT   yLOG_snote   ("global identifier must be A-Z");
         yURG_err (YURG_FATAL, "%s:%d:1: error: GLOBAL identifier å%cæ not valid [A-Z]", a_scrp, a_line, m);
         DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
         return rce;
      }
      if (n >= 0) {
         DEBUG_INPT   yLOG_snote   ("already set");
         yURG_err (YURG_FATAL, "%s:%d:1: error: GLOBAL identifier å%cæ already in use", a_scrp, a_line, m);
         DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
         return rce;
      }
      rc = SCRP__shared_set (T_MASTER, m, a_line);
      my.share = m;
   }
   /*---(handle shared)------------------*/
   --rce;  if (strcmp ("SHARED" , g_verbs [a_indx].name) == 0) {
      DEBUG_INPT   yLOG_snote   ("handle shared");
      IF_MASTER {
         DEBUG_INPT   yLOG_snote   ("SHARED verb not allowed in master.unit");
         yURG_err (YURG_FATAL, "%s:%d:1: error: SHARED verb not allowed in master.unit", a_scrp, a_line);
         DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
         return rce;
      }
      if (o < -1) {
         DEBUG_INPT   yLOG_snote   ("shared identifier must be a-z");
         yURG_err (YURG_FATAL, "%s:%d:1: error: SHARED identifier å%cæ not valid [a-z]", a_scrp, a_line, m);
         DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
         return rce;
      }
      if (o >= 0) {
         DEBUG_INPT   yLOG_snote   ("already set");
         yURG_err (YURG_FATAL, "%s:%d:1: error: SHARED identifier å%cæ already in use", a_scrp, a_line, m);
         DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
         return rce;
      }
      rc = SCRP__shared_set (T_SHARES, m, a_line);
      my.share = m;
   }
   /*---(handle reuses)------------------*/
   --rce;  if (strcmp ("REUSE" , g_verbs [a_indx].name) == 0) {
      DEBUG_INPT   yLOG_snote   ("handle reuse");
      /*> IF_MASTER {                                                                                                <* 
       *>    DEBUG_INPT   yLOG_snote   ("REUSE not allowed in master.unit");                                         <* 
       *>    yURG_err (YURG_FATAL, "%s:%d:1: error: REUSE verb not allowed in master.unit", a_scrp, a_line);   <* 
       *>    DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);                                                          <* 
       *>    return rce;                                                                                             <* 
       *> }                                                                                                          <*/
      if (n < -1 && o < -1) {
         DEBUG_INPT   yLOG_snote   ("not set");
         yURG_err (YURG_FATAL, "%s:%d:1: error: REUSE identifier å%cæ not valid [a-zA-Z]", a_scrp, a_line, m);
         DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
         return rce;
      }
      if (n == -1) {
         DEBUG_INPT   yLOG_snote   ("not set");
         yURG_err (YURG_FATAL, "%s:%d:1: error: REUSE identifier å%cæ never set by GLOBAL", a_scrp, a_line, m);
         DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
         return rce;
      }
      if (o == -1) {
         DEBUG_INPT   yLOG_snote   ("not set");
         yURG_err (YURG_FATAL, "%s:%d:1: error: REUSE identifier å%cæ never set by SHARED", a_scrp, a_line, m);
         DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
         return rce;
      }
      if (m == my.cshare) {
         DEBUG_INPT   yLOG_snote   ("reuse is recursive");
         yURG_err (YURG_FATAL, "%s:%d:1: error: REUSE identifier å%cæ called inside itself, recursive", a_scrp, a_line, m);
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
SCRP__ditto_check       (cchar a_scrp [LEN_TITLE], int a_line, char a_indx, char *p)
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
      yURG_err (YURG_FATAL, "%s:%d:1: error: COND/DITTO called with a null string", a_scrp, a_line);
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_INPT   yLOG_snote   (p);
   /*---(check for script)---------------*/
   strcpy (t, g_verbs [a_indx].name);
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
         yURG_err (YURG_FATAL, "%s:%d:1: error: DITTO missing a valid identifier string (?)", a_scrp, a_line);
         DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
         return rce;
      }
      DEBUG_INPT   yLOG_snote   ("no openning marker");
      DEBUG_INPT   yLOG_sexit   (__FUNCTION__);
      return 0;
   }
   --rce;  if (q [1] == NULL) {
      yURG_err (YURG_FATAL, "%s:%d:1: error: %s identifier did not follow ( marker", a_scrp, a_line, t);
      DEBUG_INPT   yLOG_snote   ("no identifer");
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   --rce;  if (q [1] == ')') {
      yURG_err (YURG_FATAL, "%s:%d:1: error: %s no identifier within () markers", a_scrp, a_line, t);
      DEBUG_INPT   yLOG_snote   ("no identifer");
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   m = q [1];
   DEBUG_INPT   yLOG_schar   (m);
   --rce;  if (q [2] != ')') {
      yURG_err (YURG_FATAL, "%s:%d:1: error: %s identifier å%cæ not followed by ) marker", a_scrp, a_line, t, m);
      DEBUG_INPT   yLOG_snote   ("no close marker");
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(validate marker)----------------*/
   n  = SCRP__shared_get (T_DITTOS, m);
   DEBUG_INPT   yLOG_sint    (n);
   if (n < -1) {
      DEBUG_INPT   yLOG_snote   ("invalid identifier");
      yURG_err (YURG_FATAL, "%s:%d:1: error: %s identifier å%cæ not valid [0-9]", a_scrp, a_line, t, m);
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(handle condition)---------------*/
   --rce;  if (strcmp ("COND" , g_verbs [a_indx].name) == 0) {
      if (my.dittoing != 'y') {
         DEBUG_INPT   yLOG_snote   ("handle cond");
         if (n > 0) {
            DEBUG_INPT   yLOG_snote   ("already set identifier (hidding)");
            yURG_err (YURG_WARN, "%s:%d:1: warning: COND identifier å%cæ already set, now overwritten", a_scrp, a_line, m);
         }
         rc = SCRP__shared_set (T_DITTOS, m, a_line);
         my.mark = m;
      } else {
         DEBUG_INPT   yLOG_snote   ("cond () inside ditto, ignored");
      }
      DEBUG_INPT   yLOG_snote   ("saving position");
      DEBUG_INPT   yLOG_schar   (my.mark);
      DEBUG_INPT   yLOG_sint    (a_line);
   }
   /*---(handle ditto)-------------------*/
   if (strcmp ("DITTO" , g_verbs [a_indx].name) == 0) {
      DEBUG_INPT   yLOG_snote   ("handle ditto");
      if (n == -1) {
         DEBUG_INPT   yLOG_snote   ("unset identifier");
         yURG_err (YURG_FATAL, "%s:%d:1: error: DITTO identifier å%cæ not set by previous COND", a_scrp, a_line, m);
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
      DEBUG_INPT   yLOG_sint    (a_line);
   }
   /*---(complete)-----------------------*/
   DEBUG_INPT   yLOG_sexit   (__FUNCTION__);
   return 0;
}



/*====================------------------------------------====================*/
/*===----                      reading the file                        ----===*/
/*====================------------------------------------====================*/
static void      o___READING_________________o (void) {;}

char
SCRP_open               (cchar a_name [LEN_RECD], FILE **r_file, int *r_line)
{
   /*---(locals)-----------+-----------+-*/
   char        rce         = -10;           /* return code for errors         */
   /*---(header)-------------------------*/
   DEBUG_PROG   yLOG_enter   (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_line != NULL)  *r_line = 0;
   /*---(defense)------------------------*/
   DEBUG_OUTP   yLOG_point   ("a_name"    , a_name);
   --rce;  if (a_name  == NULL || a_name [0] == '\0') {
      DEBUG_PROG   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_OUTP   yLOG_info    ("a_name"    , a_name);
   DEBUG_OUTP   yLOG_point   ("r_file"    , r_file);
   --rce;  if (r_file  == NULL) {
      DEBUG_PROG   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_OUTP   yLOG_point   ("*r_file"   , *r_file);
   --rce;  if (*r_file != NULL) {
      DEBUG_PROG   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(open)---------------------------*/
   *r_file = fopen (a_name, "rt");
   DEBUG_OUTP   yLOG_point   ("*r_file"   , *r_file);
   --rce;  if (*r_file == NULL) {
      yURG_err (YURG_FATAL, "file ¶%s¶ could not be openned", a_name);
      DEBUG_PROG   yLOG_fatal   ("can not open script file");
      DEBUG_PROG   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_INPT   yLOG_note    ("script file open");
   /*---(default)------------------------*/
   SCRP__ditto_clear ();
   /*---(complete)-----------------------*/
   DEBUG_PROG   yLOG_exit    (__FUNCTION__);
   return 0;
}

char         /*--> close script file ---------------------[ ------ [ ------ ]-*/
SCRP_close         (FILE **b_file)
{
   /*---(locals)-----------+-----------+-*/
   char        rc          = 0;
   char        rce         = -10;
   /*---(header)-------------------------*/
   DEBUG_PROG   yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   DEBUG_OUTP   yLOG_point   ("b_file"    , b_file);
   --rce;  if (b_file  == NULL) {
      DEBUG_PROG   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_OUTP   yLOG_point   ("*b_file"   , *b_file);
   --rce;  if (*b_file == NULL) {
      DEBUG_PROG   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(close)--------------------------*/
   rc = fclose (*b_file);
   DEBUG_OUTP   yLOG_value   ("rc"        , rc);
   --rce;  if (rc < 0) {
      DEBUG_PROG   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(default)------------------------*/
   *b_file = NULL;
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
SCRP_read               (FILE *a_file, int *r_nline, char a_dittoing, int a_ditto, int *r_dline, int *r_nrecd, int *r_len, char r_recd [LEN_RECD])
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
   /*---(default)------------------------*/
   SCRP_clear  ();
   if (r_recd != NULL)  strcpy (r_recd, "");
   if (r_len  != NULL)  *r_len = 0;
   /*---(defense)------------------------*/
   DEBUG_INPT   yLOG_point   ("a_file"    , a_file);
   --rce;  if (a_file == NULL) {
      DEBUG_INPT   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   if (feof (a_file)) {
      DEBUG_INPT   yLOG_note    ("already at end of file");
      DEBUG_INPT   yLOG_exit    (__FUNCTION__);
      return 0;
   }
   DEBUG_INPT   yLOG_point   ("r_nline"   , r_nline);
   --rce;  if (r_nline == NULL) {
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_INPT   yLOG_point   ("r_dline"   , r_dline);
   --rce;  if (r_dline == NULL) {
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_INPT   yLOG_point   ("r_nrecd"   , r_nrecd);
   --rce;  if (r_nrecd == NULL) {
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(read for a good record)---------*/
   --rce; while (1) {
      /*---(read next)-------------------*/
      DEBUG_INPT   yLOG_note    ("read script file");
      fgets (x_recd, LEN_RECD, a_file);
      if (feof (a_file)) {
         DEBUG_INPT   yLOG_note    ("hit end of file");
         DEBUG_INPT   yLOG_exit    (__FUNCTION__);
         return 0;
      }
      /*---(handle line numbers)---------*/
      DEBUG_INPT   yLOG_complex ("line#"     , "%4d nline, %c, %4d dline", *r_nline, a_dittoing, *r_dline);
      rc = DITTO_read_numbering (a_dittoing, a_ditto, r_nline, r_dline);
      DEBUG_INPT   yLOG_value   ("ditto prep", rc);
      if (rc < 0)  continue;
      /*---(prepare)---------------------*/
      x_len = strllen (x_recd, LEN_RECD);
      if (x_len > 0)  x_recd [--x_len] = '\0';
      /*---(filter)----------------------*/
      if (x_recd [0] == '\0') {
         DEBUG_INPT   yLOG_note    ("SKIP, empty");
         if (a_dittoing == 'y')  SCRP_ditto__end ();
         continue;
      }
      if (x_len > 1 && x_recd [0] == '#' && x_recd [1] != '>') {
         DEBUG_INPT   yLOG_note    ("SKIP, comment");
         if (a_dittoing == 'y')  SCRP_ditto__end ();
         continue;
      }
      DEBUG_INPT   yLOG_value   ("length"    , x_len);
      if (x_len <=  5)  {
         DEBUG_INPT   yLOG_note    ("SKIP, too short");
         if (a_dittoing == 'y')  SCRP_ditto__end ();
         continue;
      }
      /*---(check other end ditto)-------*/
      if (a_dittoing == 'y' && *r_dline != a_ditto)  {
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
      /*---(translate delayed chars)-----*/
      strlundelay (x_recd, LEN_RECD);
      /*---(copy)------------------------*/
      DEBUG_INPT   yLOG_note    ("save copy of source record");
      if (r_recd != NULL)  strlcpy (r_recd, x_recd, LEN_RECD);
      if (r_len  != NULL)  *r_len   = x_len;
      ++(*r_nrecd);
      break;
   }
   DEBUG_INPT   yLOG_note    ("got a good record");
   /*---(complete)-----------------------*/
   DEBUG_INPT   yLOG_exit    (__FUNCTION__);
   return 1;
}

char
SCRP__limits            (char a_spec, char *r_min, char *r_max)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   /*---(defaults)-----------------------*/
   if (r_min != NULL)  *r_min = 0;
   if (r_max != NULL)  *r_max = 0;
   /*---(defense)------------------------*/
   --rce;  if (r_min == NULL)  return rce;
   --rce;  if (r_max == NULL)  return rce;
   /*---(process)------------------------*/
   --rce;  switch (a_spec) {
   case '1' :  *r_min = 1;  *r_max = 1;    break;
   case 'c' :  *r_min = 1;  *r_max = 1;    break;
   case 'r' :  *r_min = 1;  *r_max = 2;    break;
   case '2' :  *r_min = 2;  *r_max = 2;    break;
   case '3' :  *r_min = 3;  *r_max = 3;    break;
   case 'F' :  *r_min = 3;  *r_max = 3;    break;
   case 's' :  *r_min = 3;  *r_max = 5;    break;
   case 'P' :  *r_min = 4;  *r_max = 4;    break;
   case 'p' :  *r_min = 4;  *r_max = 4;    break;
   case 'f' :  *r_min = 6;  *r_max = 8;    break;
   default  :  return rce;                 break;
   }
   /*---(complete)-----------------------*/
   return 0;
}

char
SCRP__current      (cchar a_scrp [LEN_TITLE], int a_line, cchar a_verb [LEN_LABEL], char a_spec, char *a_first, char r_desc [LEN_LONG], char r_meth [LEN_HUND], char r_args [LEN_FULL], char r_test [LEN_LABEL], char r_expe [LEN_RECD], char r_retn [LEN_FULL], char r_coding [LEN_RECD])
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
   char        x_desc      [LEN_LONG]  = "";     /* descriptive text               */
   char        x_meth      [LEN_HUND]  = "";     /* function/method name           */
   char        x_args      [LEN_FULL]  = "";     /* function/method args           */
   char        x_test      [LEN_LABEL] = "";     /* test type for yVAR             */
   char        x_expe      [LEN_RECD]  = "";     /* expected results               */
   char        x_retn      [LEN_FULL]  = "";     /* return variable                */
   char        x_coding    [LEN_RECD]  = "";     /* code/load/sys string           */
   /*---(header)-------------------------*/
   DEBUG_INPT   yLOG_enter   (__FUNCTION__);
   /*---(default)---------------------*/
   if (r_desc   != NULL)  strcpy (r_desc  , "");
   if (r_meth   != NULL)  strcpy (r_meth  , "");
   if (r_args   != NULL)  strcpy (r_args  , "");
   if (r_test   != NULL)  strcpy (r_test  , "");
   if (r_expe   != NULL)  strcpy (r_expe  , "");
   if (r_retn   != NULL)  strcpy (r_retn  , "");
   if (r_coding != NULL)  strcpy (r_coding, "");
   /*---(read limits)--------------------*/
   DEBUG_INPT   yLOG_char    ("spec"      , a_spec);
   rc = SCRP__limits (a_spec, &x_min, &x_max);
   DEBUG_INPT   yLOG_complex ("limits"    , "%4d rc, %d min, %d max", rc, x_min, x_max);
   --rce;  if (rc < 0) {
      yURG_err (YURG_FATAL, "%s:%d:0: error: can not identify verb ¶%s¶ with '%c' spec limits", a_scrp, a_line, a_verb, a_spec);
      DEBUG_INPT   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(quick-out)----------------------*/
   if (a_spec == '1') {
      DEBUG_INPT   yLOG_note    ("one field required and already read as verb");
      DEBUG_INPT   yLOG_exit    (__FUNCTION__);
      return 0;  /* ditto type */
   }
   /*---(prepare)------------------------*/
   p = a_first;
   if (p != NULL)  l = strlen (a_first);
   /*---(walk-fields)--------------------*/
   for (i = 2; i < 20; ++i) {
      /*---(clear spacer bars)-----------*/
      if (p [0] == '-' && i != 6) {
         if (strncmp (p, "- - -", 5) == 0)    p [0] = '\0';
         if (strncmp (p, "-----", 5) == 0)    p [0] = '\0';
         if (p [1] == '\0')                   p [0] = '\0';
      }
      /*---(handle fields)---------------*/
      switch (i) {
      case  2 : strlcpy  (x_desc, p        , LEN_LONG);
                strltrim (x_desc, ySTR_BOTH, LEN_LONG);
                break;
      case  3 :   if (a_spec == 's') {
                     if (l == 0 || l > 10)  {
                        strlcpy (x_meth      , p, LEN_HUND );
                        DEBUG_INPT   yLOG_info    ("focus"     , x_meth);
                        x_max = 3;
                     } else {
                        strlcpy (x_test      , p, LEN_LABEL);
                        DEBUG_INPT   yLOG_info    ("duration"  , x_test);
                     }
                  } else if (a_spec != 'p') {
                     strlcpy (x_meth      , p, LEN_HUND );
                     DEBUG_INPT   yLOG_info    ("meth"      , x_meth);
                  }
                  break;
      case  4 :   if      (a_spec == 's') {
                     strlcpy (x_retn      , p, LEN_FULL);
                     DEBUG_INPT   yLOG_info    ("terse tag" , x_retn);
                  } else if (a_spec == 'P' || a_spec == 'p') {
                     strlcpy (x_coding    , p, LEN_RECD);
                     DEBUG_INPT   yLOG_info    ("code"      , x_coding);
                  } else {
                     strlcpy (x_args      , p, LEN_FULL);
                     strlcpy (x_coding    , p, LEN_RECD);
                     DEBUG_INPT   yLOG_info    ("args"      , x_args);
                  }
                  break;
      case  5 :   if (a_spec == 's') {
                     strlcpy (x_meth      , p, LEN_HUND );
                     DEBUG_INPT   yLOG_info    ("focus"     , x_meth);
                  } else {
                     strlcpy (x_test      , p, LEN_LABEL);
                     DEBUG_INPT   yLOG_info    ("test"      , x_test);
                  }
                  break;
      case  6 :   strlcpy (x_expe      , p, LEN_RECD);
                  DEBUG_INPT   yLOG_info    ("expe"      , x_expe);
                  break;
      case  7 :   strlcpy (x_retn      , p, LEN_FULL);
                  DEBUG_INPT   yLOG_info    ("retn"      , x_retn);
                  break;
      }
      /*---(stop parsing summ records)---*/
      if (i >= x_max)    break;
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
      yURG_err (YURG_FATAL, "%s:%d:0: error: verb ¶%s¶ included %d fields, requires at least %d", a_scrp, a_line, a_verb, i, x_min);
      DEBUG_INPT   yLOG_complex ("too few"   , "%d actual < %d min", i, x_min);
      DEBUG_INPT   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(save-back)-------------------*/
   if (r_desc   != NULL)  strlcpy (r_desc  , x_desc  , LEN_LONG);
   if (r_meth   != NULL)  strlcpy (r_meth  , x_meth  , LEN_HUND);
   if (r_args   != NULL)  strlcpy (r_args  , x_args  , LEN_FULL);
   if (r_test   != NULL)  strlcpy (r_test  , x_test  , LEN_LABEL);
   if (r_expe   != NULL)  strlcpy (r_expe  , x_expe  , LEN_RECD);
   if (r_retn   != NULL)  strlcpy (r_retn  , x_retn  , LEN_FULL);
   if (r_coding != NULL)  strlcpy (r_coding, x_coding, LEN_RECD);
   /*---(complete)--------------------*/
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
SCRP__parse_defense     (cchar a_scrp [LEN_TITLE], int a_line, cchar a_recd [LEN_RECD], char r_verb [LEN_LABEL], char *r_indx, char *r_spec, char **r_conv, char **r_code, char r_stage [LEN_TERSE], char r_vers [LEN_TERSE], char r_desc [LEN_LONG], char r_meth [LEN_HUND], char r_args [LEN_FULL], char r_test [LEN_LABEL], char r_expe [LEN_RECD], char r_retn [LEN_FULL], char r_coding [LEN_RECD])
{
   /*---(locals)-----------+-----------+-*/
   char        rce         = -10;           /* return code for errors         */
   int         l           =   0;
   /*---(header)-------------------------*/
   DEBUG_INPT   yLOG_senter  (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_verb   != NULL)  strcpy (r_verb  , "");
   if (r_indx   != NULL)  *r_indx = -1;
   if (r_spec   != NULL)  *r_spec = '-';
   if (r_conv   != NULL)  *r_conv = NULL;
   if (r_code   != NULL)  *r_code = NULL;
   if (r_stage  != NULL)  strcpy (r_stage , "");
   if (r_vers   != NULL)  strcpy (r_vers  , "");
   if (r_desc   != NULL)  strcpy (r_desc  , "");
   if (r_meth   != NULL)  strcpy (r_meth  , "");
   if (r_args   != NULL)  strcpy (r_args  , "");
   if (r_test   != NULL)  strcpy (r_test  , "");
   if (r_expe   != NULL)  strcpy (r_expe  , "");
   if (r_retn   != NULL)  strcpy (r_retn  , "");
   if (r_coding != NULL)  strcpy (r_coding, "");
   /*---(feeder fields)------------------*/
   DEBUG_INPT   yLOG_spoint  (a_scrp);
   --rce;  if (a_scrp == NULL) {
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_INPT   yLOG_spoint  (a_recd);
   --rce;  if (a_recd == NULL) {
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_INPT   yLOG_schar   (a_recd [0]);
   --rce;  if (a_recd [0] == '\0') {
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   l = strlen (a_recd);
   DEBUG_INPT   yLOG_sint    (l);
   --rce;  if (l <  5 && a_recd [0] != '#') {
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(return fields)------------------*/
   DEBUG_INPT   yLOG_spoint  (r_verb);
   --rce;  if (r_verb == NULL) {
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_INPT   yLOG_spoint  (r_indx);
   --rce;  if (r_indx == NULL) {
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_INPT   yLOG_spoint  (r_spec);
   --rce;  if (r_spec == NULL) {
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_INPT   yLOG_spoint  (r_conv);
   --rce;  if (r_conv == NULL) {
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_INPT   yLOG_spoint  (r_code);
   --rce;  if (r_code == NULL) {
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_INPT   yLOG_spoint  (r_stage);
   --rce;  if (r_stage == NULL) {
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_INPT   yLOG_spoint  (r_vers);
   --rce;  if (r_vers == NULL) {
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(complete)-----------------------*/
   DEBUG_INPT   yLOG_sexit   (__FUNCTION__);
   return 0;
}

char
SCRP__parse_comment     (cchar a_recd [LEN_RECD], char r_verb [LEN_LABEL], char *r_indx, char *r_spec, char **r_conv, char **r_code)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   int         i           =    0;
   char        x_recd      [LEN_RECD]  = "";
   int         x_len       =    0;
   char        x_verb      [LEN_LABEL] = "";
   char        x_indx      =   -1;
   char        x_spec      =  '-';
   char      (*x_conv) (void)  = NULL;
   char      (*x_code) (void)  = NULL;
   /*---(header)-------------------------*/
   DEBUG_INPT   yLOG_senter  (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_verb  != NULL)  strlcpy  (r_verb , "", LEN_LABEL);
   if (r_indx  != NULL)  *r_indx = -1;
   if (r_spec  != NULL)  *r_spec = '-';
   if (r_conv  != NULL)  *r_conv = NULL;
   if (r_code  != NULL)  *r_code = NULL;
   /*---(defense)------------------------*/
   DEBUG_INPT   yLOG_spoint  (a_recd);
   --rce;  if (a_recd == NULL) {
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   x_len = strlen (a_recd);
   /*---(ward-off)-----------------------*/
   DEBUG_INPT   yLOG_sint    (x_len);
   if (x_len < 2) {
      DEBUG_INPT   yLOG_snote   ("too short");
      DEBUG_INPT   yLOG_sexit   (__FUNCTION__);
      return 0;
   }
   if (strncmp (a_recd, "#>", 2) != 0) {
      DEBUG_INPT   yLOG_snote   ("not prefixed with #>");
      DEBUG_INPT   yLOG_sexit   (__FUNCTION__);
      return 0;
   }
   /*---(check for marker)---------------*/
   DEBUG_INPT   yLOG_snote   ("saved record/comment");
   for (i = 0; i < MAX_VERB; ++i) {
      if (strcmp (g_verbs [i].name, "#>") != 0) continue;
      strlcpy (x_verb, g_verbs [i].name, LEN_LABEL);
      x_indx  = i;
      x_spec  = g_verbs [i].spec;
      x_conv  = g_verbs [i].conv;
      x_code  = g_verbs [i].code;
      ++g_verbs [i].count;
      ++g_verbs [i].total;
      DEBUG_INPT   yLOG_sint    (g_verbs [i].count);
   }
   /*---(save-back)----------------------*/
   if (r_verb  != NULL)  strlcpy (r_verb, x_verb, LEN_LABEL);
   if (r_indx  != NULL)  *r_indx = x_indx;
   if (r_spec  != NULL)  *r_spec = x_spec;
   if (r_conv  != NULL)  *r_conv = x_conv;
   if (r_code  != NULL)  *r_code = x_code;
   /*---(complete)-----------------------*/
   DEBUG_INPT   yLOG_sexit   (__FUNCTION__);
   return 1;
}

char
SCRP__parse_verb        (char a_scrp [LEN_TITLE], int a_line, char a_field [LEN_LABEL], char r_verb [LEN_LABEL], char *r_indx, char *r_spec, char **r_conv, char **r_code)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char       *p           = NULL;
   int         i           =    0;
   int         x_len       =    0;
   char        x_word      [LEN_LABEL] = "";
   char        x_verb      [LEN_LABEL] = "";
   char        x_indx      =   -1;
   char        x_spec      =  '-';
   char      (*x_conv) (void)  = NULL;
   char      (*x_code) (void)  = NULL;
   /*---(header)-------------------------*/
   DEBUG_INPT   yLOG_senter  (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_verb  != NULL)  strlcpy  (r_verb , "", LEN_LABEL);
   if (r_indx  != NULL)  *r_indx = -1;
   if (r_spec  != NULL)  *r_spec = '-';
   if (r_conv  != NULL)  *r_conv = NULL;
   if (r_code  != NULL)  *r_code = NULL;
   /*---(defense)------------------------*/
   DEBUG_INPT   yLOG_spoint  (a_scrp);
   --rce;  if (a_scrp == NULL) {
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_INPT   yLOG_spoint  (a_field);
   --rce;  if (a_field == NULL || strlen (a_field) <= 0) {
      yURG_err (YURG_FATAL, "%s:%d:0: error: no verb found (empty or null)", a_scrp, a_line);
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(prepare)------------------------*/
   strlcpy  (x_word, a_field, LEN_FULL);
   strltrim (x_word, ySTR_BOTH, LEN_FULL);
   p = strchr (x_word, ' ');
   if (p != NULL)  p [0] = '\0';
   x_len = strlen (x_word);
   DEBUG_INPT   yLOG_sint    (x_len);
   --rce;  if (x_len <= 2) {
      yURG_err (YURG_FATAL, "%s:%d:0: error: verb ¶%s¶ is too short (less than 3 chars)", a_scrp, a_line, x_word);
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_INPT   yLOG_snote   (x_word);
   /*---(filter comments)----------------*/
   --rce;  if (x_word [0] == '#') {
      yURG_err (YURG_FATAL, "%s:%d:0: error: comment symbol ¶%s¶, but not in column one", a_scrp, a_line, x_word);
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(find verb)----------------------*/
   for (i = 0; i < MAX_VERB; ++i) {
      if (g_verbs [i].name [0] == '-')                break;
      if (g_verbs [i].name [0] != x_word[0])          continue;
      if (strcmp (g_verbs [i].name, x_word) != 0)     continue;
      /*---(save values)-----------------*/
      DEBUG_INPT   yLOG_snote   ("verb found");
      strlcpy (x_verb, g_verbs [i].name, LEN_LABEL);
      x_indx  = i;
      x_spec  = g_verbs [i].spec;
      x_conv  = g_verbs [i].conv;
      x_code  = g_verbs [i].code;
      ++g_verbs [i].count;
      ++g_verbs [i].total;
      DEBUG_INPT   yLOG_sint    (g_verbs [i].count);
      break;
      /*---(done)------------------------*/
   }
   /*---(failure)------------------------*/
   --rce;  if (x_indx == -1) {
      yURG_err (YURG_FATAL, "%s:%d:0: error: verb ¶%s¶ not recognized/found", a_scrp, a_line, x_word);
      DEBUG_INPT   yLOG_snote   ("verb not found");
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(file limitations)---------------*/
   --rce;  IF_MASTER {
      if (g_verbs [x_indx].files == 'n') {
         DEBUG_INPT   yLOG_snote   ("verb not allowed in master.unit");
         yURG_err (YURG_FATAL, "%s:%d:0: error: verb ¶%s¶ good, but not allowed inside master.unit", a_scrp, a_line, x_verb);
         DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
         return rce;
      }
   }
   --rce;  IF_NORMAL {
      if (g_verbs [x_indx].files == 'm') {
         DEBUG_INPT   yLOG_snote   ("verb not allowed outside master.unit");
         yURG_err (YURG_FATAL, "%s:%d:0: error: verb ¶%s¶ good, but not allowed outside master.unit", a_scrp, a_line, x_verb);
         DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
         return rce;
      }
   }
   /*---(save-back)----------------------*/
   if (r_verb  != NULL)  strlcpy (r_verb, x_verb, LEN_LABEL);
   if (r_indx  != NULL)  *r_indx = x_indx;
   if (r_spec  != NULL)  *r_spec = x_spec;
   if (r_conv  != NULL)  *r_conv = x_conv;
   if (r_code  != NULL)  *r_code = x_code;
   /*---(complete)-----------------------*/
   DEBUG_INPT   yLOG_sexit   (__FUNCTION__);
   return 0;
}

char
SCRP__parse_save        (char a_verb [LEN_LABEL], char a_indx, char a_spec, char *a_conv, char *a_code, char a_stage [LEN_TERSE], char a_vers [LEN_TERSE])
{
   /*> strlcpy (my.verb    , a_verb   , LEN_LABEL);                                   <* 
    *> my.indx   = a_indx;                                                            <* 
    *> my.spec   = a_spec;                                                            <* 
    *> my.p_conv = a_conv;                                                            <* 
    *> my.p_code = a_code;                                                            <* 
    *> strlcpy (my.stage   , a_stage  , LEN_TERSE);                                   <* 
    *> strlcpy (my.vers    , a_vers   , LEN_TERSE);                                   <*/
   return 0;
}

#define   SCRP_SAVE  if (r_verb  != NULL)  strlcpy (r_verb , x_verb , LEN_LABEL); \
                     if (r_indx  != NULL)  *r_indx  = x_indx; \
                     if (r_spec  != NULL)  *r_spec  = x_spec; \
                     if (r_conv  != NULL)  *r_conv  = x_conv; \
                     if (r_code  != NULL)  *r_code  = x_code; \
                     if (r_stage != NULL)  strlcpy (r_stage, x_stage, LEN_TERSE); \
                     if (r_vers  != NULL)  strlcpy (r_vers , x_vers , LEN_TERSE);

char
SCRP_parse              (cchar a_scrp [LEN_TITLE], int a_line, cchar a_recd [LEN_RECD], char r_verb [LEN_LABEL], char *r_indx, char *r_spec, char **r_conv, char **r_code, char r_stage [LEN_TERSE], char r_vers [LEN_TERSE], char r_desc [LEN_LONG], char r_meth [LEN_HUND], char r_args [LEN_FULL], char r_test [LEN_LABEL], char r_expe [LEN_RECD], char r_retn [LEN_FULL], char r_coding [LEN_RECD])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   int         rc          = 0;             /* generic return code            */
   char        x_recd      [LEN_RECD];
   int         x_len       = 0;             /* input record length            */
   char       *p;
   char       *q           = "";
   char       *r           = NULL;
   char        x_verb      [LEN_LABEL] = "";
   char        x_indx      = -1;
   char        x_spec      = '-';
   void       *x_conv      = NULL;
   void       *x_code      = NULL;
   char        x_stage     [LEN_TERSE] = "";
   char        x_vers      [LEN_TERSE] = "";
   int         i           = 0;
   /*---(header)-------------------------*/
   DEBUG_INPT   yLOG_enter   (__FUNCTION__);
   /*---(defaults)--------------------*/
   SCRP__parse_save (x_verb, x_indx, x_spec, x_conv, x_code, x_stage, x_vers);
   /*---(defense)---------------------*/
   rc = SCRP__parse_defense (a_scrp, a_line, a_recd, r_verb, r_indx, r_spec, r_conv, r_code, r_stage, r_vers, r_desc, r_meth, r_args, r_test, r_expe, r_retn, r_coding);
   DEBUG_INPT   yLOG_value   ("defense"   , rc);
   --rce;  if (rc < 0) {
      DEBUG_INPT   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   SCRP_SAVE
   /*> SCRP__parse_save (x_verb, x_indx, x_spec, x_conv, x_code, x_stage, x_vers);    <*/
   /*---(saved comments)-----------------*/
   rc = SCRP__parse_comment (a_recd, x_verb, &x_indx, &x_spec, &x_conv, &x_code);
   DEBUG_INPT   yLOG_value   ("comment"   , rc);
   --rce;  if (rc != 0) {
      if (rc == 1) {
         SCRP_SAVE
         /*> SCRP__parse_save (x_verb, x_indx, x_spec, x_conv, x_code, x_stage, x_vers);   <*/
      }
      DEBUG_INPT   yLOG_exit    (__FUNCTION__);
      return 0;
   }
   /*---(create a copy of recd)----------*/
   strlcpy (x_recd, a_recd, LEN_RECD);
   DEBUG_INPT   yLOG_info    ("x_recd"    , x_recd);
   p  = strtok (x_recd, q);
   /*---(get verb)-----------------------*/
   rc = SCRP__parse_verb (a_scrp, a_line, p, x_verb, &x_indx, &x_spec, &x_conv, &x_code);
   DEBUG_INPT   yLOG_value   ("verb"      , rc);
   --rce;  if (rc < 0) {
      DEBUG_INPT   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(check for shares)---------------*/
   rc = SCRP__reuses_check (a_scrp, a_line, p, my.indx, &(my.cshare), &(my.share), &(my.dittoing), &(my.dmark), &(my.mark), &(my.ditto), &(my.dline));
   DEBUG_INPT   yLOG_value   ("reuses"    , rc);
   --rce;  if (rc < 0) {
      DEBUG_INPT   yLOG_exitr   (__FUNCTION__, rc);
      return rce;
   }
   /*---(check for ditto)----------------*/
   rc = DITTO_parse_handler (a_scrp, a_line, my.run_type, x_verb, p, &(my.cshare), &(my.share), &(my.dittoing), &(my.dmark), &(my.mark), &(my.ditto), &(my.dline));
   DEBUG_INPT   yLOG_value   ("ditto"     , rc);
   --rce;  if (rc < 0) {
      DEBUG_INPT   yLOG_exitr   (__FUNCTION__, rc);
      return rce;
   }
   if (rc >  0) {
      DEBUG_INPT   yLOG_note    ("FOUND DITTO, back to reading");
      SCRP_SAVE
      /*> SCRP__parse_save (x_verb, x_indx, x_spec, x_conv, x_code, x_stage, x_vers);   <*/
      DEBUG_INPT   yLOG_exit    (__FUNCTION__);
      return 0;
   }
   /*---(check for stage marker)---------*/
   rc = WAVE_parse (a_scrp, a_line, x_indx, x_verb, p, x_stage) ;
   DEBUG_INPT   yLOG_value   ("stage"     , rc);
   --rce;  if (rc < 0) {
      DEBUG_INPT   yLOG_exitr   (__FUNCTION__, rc);
      return rce;
   }
   /*---(read version)-------------------*/
   p = strtok (NULL  , q);
   --rce;  if (p == NULL && x_spec != 'c') {
      yURG_err (YURG_FATAL, "%s:%d:1: error: verb only, %s requires more fields", a_scrp, a_line, x_verb);
      DEBUG_INPT   yLOG_note    ("strtok came up empty");
      DEBUG_INPT   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   x_len = strlen (p);
   strltrim (p, ySTR_BOTH, x_len);
   x_len = strlen (p);
   if (p[0] == '-')  p[0] = '\0';
   rc = 0;
   /*---(handle version)-----------------*/
   if      (x_len != 3 || p [0] != 'v') {
      if (x_spec!= 'c')  rc = SCRP__current (a_scrp, a_line, x_verb, x_spec, p, my.desc, my.meth, my.args, my.test, my.expe, my.retn, my.code);
   } else if (strcmp (p, "v21") == 0) {
      strlcpy (x_vers       , p    , LEN_LABEL);
      DEBUG_INPT   yLOG_info    ("vers"      , x_vers );
      if (x_spec!= 'c')  rc = SCRP_vers21  ();
   } else if (strcmp (p, "v20") == 0) {
      strlcpy (x_vers       , p    , LEN_LABEL);
      DEBUG_INPT   yLOG_info    ("vers"      , x_vers );
      if (x_spec!= 'c')  rc = SCRP_vers20  ();
   } else                             {
      strlcpy (x_vers       , "v19", LEN_LABEL);
      DEBUG_INPT   yLOG_info    ("vers"      , x_vers );
      strlcpy (my.desc      , p    , LEN_LONG );
      DEBUG_INPT   yLOG_info    ("desc"      , my.desc);
      if (x_spec!= 'c')  rc = SCRP_vers19  ();
   }
   /*---(check for trouble)--------------*/
   if (rc < 0) {
      DEBUG_INPT   yLOG_note    ("trouble parsing");
      DEBUG_INPT   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   /*---(save-back)----------------------*/
   SCRP_SAVE
   /*> SCRP__parse_save (x_verb, x_indx, x_spec, x_conv, x_code, x_stage, x_vers);    <*/
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
