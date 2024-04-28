/*===============================[[ beg-code ]]===============================*/
#include    "koios.h"        /* LOCAL  : main header                          */

/*
 * location -- what type of unit test file can it appear in...
 *    m  master.unit only
 *    n  non-master.unit only
 *    -  any and all
 *
 *
 *
 *
 *
 *
 */


tVERB       g_verbs [MAX_VERB] = {
   /* --overall-----   --------------------------------------- ---- ---- cnt tot ----conv----    ----code----    ----- */
   { ""             , "overall"                               , '-', '-',  0,  0, NULL          , NULL          ,  '-'  },
   { "PREP"         , "preparation before testing"            , '2', '-',  0,  0, CONV_prep     , NULL          ,  '-'  },
   { "incl"         , "c header inclusion"                    , '3', '-',  0,  0, CONV_incl     , CODE_incl     ,  '-'  },
   { "#>"           , "script internal comments"              , 'c', '-',  0,  0, CONV_comment  , NULL          ,  '-'  },
   /* --scrps-------   --------------------------------------- */
   { ""             , "scripts"                               , '-', '-',  0,  0, NULL          , NULL          ,  '-'  },
   { "SCRP"         , "test script header"                    , 's', 'n',  0,  0, CONV_scrp     , CODE_scrp     ,  '-'  },
   { "SHARED"       , "shared code between scripts"           , 's', 'n',  0,  0, CONV_shared   , CODE_shared   ,  '-'  },
   { "GLOBAL"       , "shared code between units"             , 's', 'm',  0,  0, CONV_global   , CODE_global   ,  '-'  },
   { "SECT"         , "grouping of scripts"                   , '2', 'n',  0,  0, CONV_sect     , CODE_sect     ,  '-'  },
   /* --conds-------   --------------------------------------- */
   { ""             , "conditions"                            , '-', '-',  0,  0, NULL          , NULL          ,  '-'  },
   { "COND"         , "test condition"                        , '2', '-',  0,  0, CONV_cond     , CODE_cond     ,  '-'  },
   { "DITTO"        , "repeated test condition"               , '1', '-',  0,  0, CONV_ditto    , NULL          ,  '-'  },
   { "REUSE"        , "inclusion of shared code"              , '1', '-',  0,  0, CONV_reuse    , CODE_reuse    ,  '-'  },
   { "GROUP"        , "grouping of conditions"                , '2', '-',  0,  0, CONV_group    , CODE_group    ,  '-'  },
   /* --variables---   --------------------------------------- */
   { ""             , "variables"                             , '-', '-',  0,  0, NULL          , NULL          ,  '-'  },
   { "global"       , "global/unit variable definition"       , 'p', '-',  0,  0, CONV_gvar     , CODE_gvar     ,  '-'  },
   { "local"        , "local/script variable definition"      , 'p', '-',  0,  0, CONV_code     , CODE_lvar     ,  '-'  },
   /* --steps-------   --------------------------------------- */
   { ""             , "steps"                                 , '-', '-',  0,  0, NULL          , NULL          ,  '-'  },
   { "exec"         , "function execution"                    , 'f', '-',  0,  0, CONV_exec     , CODE_exec     ,  'y'  },
   { "get"          , "unit test accessor retrieval"          , 'f', '-',  0,  0, CONV_exec     , CODE_exec     ,  'y'  },
   { "echo"         , "test a variable directly"              , 'f', '-',  0,  0, CONV_echo     , CODE_exec     ,  'y'  },
   /* --specialty---   --------------------------------------- */
   { ""             , "specialty"                             , '-', '-',  0,  0, NULL          , NULL          ,  '-'  },
   { "code"         , "insert c code"                         , 'p', '-',  0,  0, CONV_code     , CODE_code     ,  'y'  },
   { "system"       , "execute shell code"                    , 'p', '-',  0,  0, CONV_code     , CODE_system   ,  'y'  },
   { "load"         , "place data into input"                 , 'P', '-',  0,  0, CONV_load     , CODE_load     ,  'y'  },
   { "mode"         , "set pass or forced_fail mode"          , '2', '-',  0,  0, CONV_mode     , CODE_mode     ,  'y'  },
   /* --support-----   --------------------------------------- */
   { ""             , "support"                               , '-', '-',  0,  0, NULL          , NULL          ,  '-'  },
   { "file"         , "create a temporary file"               , 'p', '-',  0,  0, CONV_file     , CODE_file     ,  'y'  },
   { "append"       , "append data to temporary file"         , 'p', '-',  0,  0, CONV_append   , CODE_append   ,  'y'  },
   /* --ouroboros---   --------------------------------------- */
   { ""             , "oroboros"                              , '-', '-',  0,  0, NULL          , NULL          ,  '-'  },
   { "WAVE"         , "testing wave definition"               , '2', 'm',  0,  0, NULL          , NULL          ,  '-'  },
   { "stage"        , "testing stage definition"              , '2', 'm',  0,  0, NULL          , NULL          ,  '-'  },
   /* --sentinal----   --------------------------------------- */
   { "----"         , "end-of-entries"                        , '-', '-',  0,  0, NULL          , NULL          ,  '-'  },
   /* --done--------   --------------------------------------- */
};

char
VERB_init               (void)
{
   /*---(locals)-----------+-----+-----+-*/
   int         i           =    0;
   /*---(find verb)----------------------*/
   for (i = 0; i < MAX_VERB; ++i) {
      if (g_verbs [i].name [0] == '-')                break;
      g_verbs [i].count = 0;
      g_verbs [i].total = 0;
   }
   return 0;
}

char
VERB_script_reset       (void)
{
   /*---(locals)-----------+-----+-----+-*/
   int         i           =    0;
   /*---(find verb)----------------------*/
   for (i = 0; i < MAX_VERB; ++i) {
      if (g_verbs [i].name [0] == '-')                break;
      g_verbs [i].count = 0;
   }
   return 0;
}

char
VERB_dittoable          (char a_verb [LEN_LABEL])
{
   /*---(locals)-----------+-----+-----+-*/
   int         i           =    0;
   /*---(header)-------------------------*/
   DEBUG_UVER   yLOG_uenter  (__FUNCTION__);
   /*---(defense)------------------------*/
   DEBUG_UVER   yLOG_upoint  ("a_verb"    , a_verb);
   if (a_verb == NULL || a_verb [0] == '\0') {
      DEBUG_UVER   yLOG_uexit   (__FUNCTION__);
      return 0;
   }
   /*---(find verb)----------------------*/
   for (i = 0; i < MAX_VERB; ++i) {
      if (g_verbs [i].name [0] == '-')                break;
      if (g_verbs [i].name [0] != a_verb [0])         continue;
      if (strcmp (g_verbs [i].name, a_verb) != 0)     continue;
      /*---(save values)-----------------*/
      DEBUG_UVER   yLOG_unote   ("verb found");
      if (g_verbs [i].ditto == 'y') {
         DEBUG_UVER   yLOG_uexit   (__FUNCTION__);
         return 1;
      }
      break;
      /*---(done)------------------------*/
   }
   /*---(complete)-----------------------*/
   DEBUG_UVER   yLOG_uexit   (__FUNCTION__);
   return 0;
}

char
VERB_parse              (char a_nscrp [LEN_TITLE], int a_line, char a_field [LEN_LABEL], char r_verb [LEN_LABEL], char *r_indx, char *r_spec, char *r_locn, char **r_conv, char **r_code)
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
   char        x_locn      =  '-';
   char      (*x_conv) (void)  = NULL;
   char      (*x_code) (void)  = NULL;
   /*---(header)-------------------------*/
   DEBUG_UVER   yLOG_uenter  (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_verb  != NULL)  strlcpy  (r_verb , "", LEN_LABEL);
   if (r_indx  != NULL)  *r_indx = -1;
   if (r_spec  != NULL)  *r_spec = '-';
   if (r_locn  != NULL)  *r_locn = '-';
   if (r_conv  != NULL)  *r_conv = NULL;
   if (r_code  != NULL)  *r_code = NULL;
   /*---(defense)------------------------*/
   DEBUG_UVER   yLOG_upoint  ("a_nscrp"   , a_nscrp);
   --rce;  if (a_nscrp == NULL) {
      DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_UVER   yLOG_upoint  ("a_field"   , a_field);
   --rce;  if (a_field == NULL || strlen (a_field) <= 0) {
      yLOGS_err ("%s:%d:0: error: no verb found (empty or null)", a_nscrp, a_line);
      DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(prepare)------------------------*/
   strlcpy  (x_word, a_field, LEN_FULL);
   ystrutrim (x_word, LEN_FULL);
   p = strchr (x_word, ' ');
   if (p != NULL)  p [0] = '\0';
   DEBUG_UVER   yLOG_unote   (x_word);
   /*---(find verb)----------------------*/
   for (i = 0; i < MAX_VERB; ++i) {
      if (g_verbs [i].name [0] == '-')                break;
      if (g_verbs [i].name [0] == '\0')               continue;
      if (g_verbs [i].name [0] != x_word[0])          continue;
      if (strcmp (g_verbs [i].name, x_word) != 0)     continue;
      /*---(save values)-----------------*/
      DEBUG_UVER   yLOG_unote   ("verb found");
      strlcpy (x_verb, g_verbs [i].name, LEN_LABEL);
      x_indx  = i;
      x_spec  = g_verbs [i].spec;
      x_locn  = g_verbs [i].files;
      x_conv  = g_verbs [i].conv;
      x_code  = g_verbs [i].code;
      ++g_verbs [i].count;
      ++g_verbs [i].total;
      DEBUG_UVER   yLOG_uvalue  ("count"     , g_verbs [i].count);
      break;
      /*---(done)------------------------*/
   }
   /*---(failure)------------------------*/
   --rce;  if (x_indx == -1) {
      yLOGS_err ("%s:%d:0: error: verb ¶%s¶ not recognized/found", a_nscrp, a_line, x_word);
      DEBUG_UVER   yLOG_unote   ("verb not found");
      DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(file limitations)---------------*/
   --rce;  if (strcmp (a_nscrp, "master.unit") == 0) {
      if (x_locn == 'n') {
         DEBUG_UVER   yLOG_unote   ("verb not allowed in master.unit");
         yLOGS_err ("%s:%d:0: error: verb ¶%s¶ good, but not allowed inside master.unit", a_nscrp, a_line, x_verb);
         DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
         return rce;
      }
   }
   --rce;  if (strcmp (a_nscrp, "master.unit") != 0) {
      if (x_locn == 'm') {
         DEBUG_UVER   yLOG_unote   ("verb not allowed outside master.unit");
         yLOGS_err ("%s:%d:0: error: verb ¶%s¶ good, but not allowed outside master.unit", a_nscrp, a_line, x_verb);
         DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
         return rce;
      }
   }
   /*---(save-back)----------------------*/
   if (r_verb  != NULL)  strlcpy (r_verb, x_verb, LEN_LABEL);
   if (r_indx  != NULL)  *r_indx = x_indx;
   if (r_spec  != NULL)  *r_spec = x_spec;
   if (r_locn  != NULL)  *r_locn = x_locn;
   if (r_conv  != NULL)  *r_conv = x_conv;
   if (r_code  != NULL)  *r_code = x_code;
   /*---(complete)-----------------------*/
   DEBUG_UVER   yLOG_uexit   (__FUNCTION__);
   return 1;
}

char
VERB_inventory     (FILE *a_main)
{
   int         i           = 0;
   int         c           = 0;
   CONV_printf (a_main, "\n");
   CONV_printf (a_main, "char\n");
   CONV_printf (a_main, "yUNIT_verbs (void)\n");
   CONV_printf (a_main, "{\n");
   CONV_printf (a_main, "   printf (\"koios, record type summary\\n\");\n");
   for (i = 0; i < MAX_VERB; ++i) {
      if (g_verbs [i].name [0] == '\0' || g_verbs [i].name [0] == '-') {
         CONV_printf (a_main, "   printf (\"\\n%s...\\n\");\n", g_verbs [i].desc);
      } else {
         CONV_printf (a_main, "   printf (\"  %-10.10s = %5d   %s\\n\");\n", g_verbs [i].name, g_verbs [i].total, g_verbs [i].desc);
         c += g_verbs [i].total;
      }
      if (g_verbs [i].name [0] == '-') break;
   }
   CONV_printf (a_main, "   printf (\"%-10.10s   = %5d   %s\\n\");\n", "TOTAL"         , c                , "count of all verb use");
   CONV_printf (a_main, "   printf (\"%-10.10s   = %5d   %s\\n\");\n", "concerns"      , my.n_recd - c    , "records with troubles");
   CONV_printf (a_main, "   return 0;\n");
   CONV_printf (a_main, "}\n");
   CONV_printf (a_main, "\n");
   return 0;
}

