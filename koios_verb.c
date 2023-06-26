/*===============================[[ beg-code ]]===============================*/
#include    "koios.h"        /* LOCAL  : main header                          */



tVERB       g_verbs [MAX_VERB] = {
   /* --global------   ---desc-------------------------------- spec file cnt tot  ---conv------   ---code------ , ditto */
   { "GLOBAL"       , "shared code between units"             , 's', 'm',  0,  0, CONV_global   , CODE_global   ,  '-'  },
   /* --units-------   ---------------------------------------   -  */
   { "PREP"         , "preparation before testing"            , '2', '-',  0,  0, CONV_prep     , CODE_prep     ,  '-'  },
   { "incl"         , "c header inclusion"                    , '3', '-',  0,  0, CONV_incl     , CODE_incl     ,  '-'  },
   { "#>"           , "script internal comments"              , 'c', '-',  0,  0, CONV_comment  , NULL          ,  '-'  },
   /* --scrps-------   --------------------------------------- */
   { "SCRP"         , "test script"                           , 's', 'n',  0,  0, CONV_scrp     , CODE_scrp     ,  '-'  },
   { "SECT"         , "grouping of scripts"                   , '2', 'n',  0,  0, CONV_sect     , CODE_sect     ,  '-'  },
   { "SHARED"       , "shared code between scripts"           , 's', 'n',  0,  0, CONV_shared   , CODE_shared   ,  '-'  },
   /* --conds-------   --------------------------------------- */
   { "GROUP"        , "grouping of conditions"                , '2', '-',  0,  0, CONV_group    , CODE_group    ,  '-'  },
   { "COND"         , "test condition"                        , '2', '-',  0,  0, CONV_cond     , CODE_cond     ,  '-'  },
   { "DITTO"        , "repeated test condition"               , '1', '-',  0,  0, CONV_ditto    , NULL          ,  '-'  },
   { "REUSE"        , "inclusion of shared code"              , '1', '-',  0,  0, CONV_reuse    , CODE_reuse    ,  '-'  },
   /* --variables---   --------------------------------------- */
   { "global"       , "global/unit variable definition"       , 'p', '-',  0,  0, CONV_gvar     , CODE_gvar     ,  '-'  },
   { "local"        , "local/script variable deinition"       , 'p', '-',  0,  0, CONV_code     , CODE_lvar     ,  '-'  },
   /* --steps-------   --------------------------------------- */
   { "exec"         , "function execution"                    , 'f', '-',  0,  0, CONV_exec     , CODE_exec     ,  'y'  },
   { "get"          , "unit test accessor retrieval"          , 'f', '-',  0,  0, CONV_exec     , CODE_exec     ,  'y'  },
   { "echo"         , "test a variable directly"              , 'f', '-',  0,  0, CONV_echo     , CODE_echo     ,  'y'  },
   /* --specialty---   --------------------------------------- */
   { "code"         , "insert c code"                         , 'p', '-',  0,  0, CONV_code     , CODE_code     ,  'y'  },
   { "system"       , "execute shell code"                    , 'p', '-',  0,  0, CONV_code     , CODE_system   ,  'y'  },
   { "load"         , "place data into stdin"                 , 'P', '-',  0,  0, CONV_load     , CODE_load     ,  'y'  },
   { "mode"         , "set pass or forced_fail mode"          , '2', '-',  0,  0, CONV_mode     , CODE_mode     ,  'y'  },
   /* --support-----   --------------------------------------- */
   { "file"         , "create a temporary file"               , 'p', '-',  0,  0, CONV_file     , CODE_file     ,  'y'  },
   { "append"       , "append data to temporary file"         , 'p', '-',  0,  0, CONV_append   , CODE_append   ,  'y'  },
   /* --ouroboros---   --------------------------------------- */
   { "WAVE"         , "testing wave"                          , '2', 'm',  0,  0, NULL          , NULL          ,  '-'  },
   { "stage"        , "testing stage"                         , '2', 'm',  0,  0, NULL          , NULL          ,  '-'  },
   /* --sentinal----   --------------------------------------- */
   { "----"         , "end-of-entries"                        , '-', '-',  0,  0, NULL          , NULL          ,  '-'  },
   /* --done--------   --------------------------------------- */
};

char
VERB_dittoable          (char a_verb [LEN_LABEL])
{
   /*---(locals)-----------+-----+-----+-*/
   int         i           =    0;
   /*---(header)-------------------------*/
   DEBUG_INPT   yLOG_senter  (__FUNCTION__);
   /*---(defense)------------------------*/
   DEBUG_INPT   yLOG_spoint  (a_verb);
   if (a_verb == NULL) {
      DEBUG_INPT   yLOG_sexit   (__FUNCTION__);
      return 0;
   }
   /*---(find verb)----------------------*/
   for (i = 0; i < MAX_VERB; ++i) {
      if (g_verbs [i].name [0] == '-')                break;
      if (g_verbs [i].name [0] != a_verb [0])         continue;
      if (strcmp (g_verbs [i].name, a_verb) != 0)     continue;
      /*---(save values)-----------------*/
      DEBUG_INPT   yLOG_snote   ("verb found");
      if (g_verbs [i].ditto == 'y') {
         DEBUG_INPT   yLOG_sexit   (__FUNCTION__);
         return 1;
      }
      break;
      /*---(done)------------------------*/
   }
   /*---(complete)-----------------------*/
   DEBUG_INPT   yLOG_sexit   (__FUNCTION__);
   return 0;
}

char
VERB_parse              (char a_scrp [LEN_TITLE], int a_line, char a_field [LEN_LABEL], char r_verb [LEN_LABEL], char *r_indx, char *r_spec, char *r_locn, char **r_conv, char **r_code)
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
   DEBUG_INPT   yLOG_senter  (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_verb  != NULL)  strlcpy  (r_verb , "", LEN_LABEL);
   if (r_indx  != NULL)  *r_indx = -1;
   if (r_spec  != NULL)  *r_spec = '-';
   if (r_locn  != NULL)  *r_locn = '-';
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
   DEBUG_INPT   yLOG_snote   (x_word);
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
      x_locn  = g_verbs [i].files;
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
      if (x_locn == 'n') {
         DEBUG_INPT   yLOG_snote   ("verb not allowed in master.unit");
         yURG_err (YURG_FATAL, "%s:%d:0: error: verb ¶%s¶ good, but not allowed inside master.unit", a_scrp, a_line, x_verb);
         DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
         return rce;
      }
   }
   --rce;  IF_NORMAL {
      if (x_locn == 'm') {
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
   if (r_locn  != NULL)  *r_locn = x_locn;
   if (r_conv  != NULL)  *r_conv = x_conv;
   if (r_code  != NULL)  *r_code = x_code;
   /*---(complete)-----------------------*/
   DEBUG_INPT   yLOG_sexit   (__FUNCTION__);
   return 0;
}
