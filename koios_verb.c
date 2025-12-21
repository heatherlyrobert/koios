/*===============================[[ beg-code ]]===============================*/
#include    "koios.h"        /* LOCAL  : main header                          */

/*
 *
 * make all tables findable by
 *    abbr/name
 *    cursor
 *    index
 * these focus testing and allow many other applications
 *
 * make all tables display
 *    detail line for unit testing
 *    inventory for checking
 *
 *
 *
 */

/*>                                                                                                                                                                                                                                                                                                                                         <* 
 *> #==(verb)===  ==========(description)============  =========(label)==========  ==(legal)===  =========(selection labels)=======================================================================================================================================================================================================    <* 
 *> GLOBAL   -A-  unsorted animal species dataset      species                     abcdef······  a=empty··········, b=one············, c=two············, d=four···········, e=nine···········, f=thirty-nine····, g=···············, h=···············, i=···············, j=···············, k=···············, l=···············    <* 
 *> CONFIG   -é-  unsorted animal species dataset      species                     abcdef······  a=empty··········, b=one············, c=two············, d=four···········, e=nine···········, f=thirty-nine····, g=···············, h=···············, i=···············, j=···············, k=···············, l=···············    <* 
 *> SHARED   -c-  unsorted animal species dataset      species                     abcdef······  a=empty··········, b=one············, c=two············, d=four···········, e=nine···········, f=thirty-nine····, g=···············, h=···············, i=···············, j=···············, k=···············, l=···············    <* 
 *>                                                                                                                                                                                                                                                                                                                                         <* 
 *>                                                                                                                                                                                                                                                                                                                                         <*/
/*===[[ INFORMATIONAL TABLES ]]===============================================*/

struct cSPEC {
   char        s_spec;
   char        s_min;
   char        s_max;
   char        s_desc      [LEN_DESC];
} static s_specs [LEN_LABEL] = {
   /*-----min--max----description----------------------------*/
   { KOIOS_SSCRP ,  1 ,  5 , "åSCRPæ script header"                  },   /* can just be a placeholder */
   { KOIOS_SDOC  ,  1 ,  1 , "å#>æ internal comments"                },
   { KOIOS_SONE  ,  1 ,  1 , "åDITTOæ and åREUSEæ w/one field"       },
   { KOIOS_STWO  ,  1 ,  2 , "åPREPæ, åCONDæ, etc w/descripion"      },   /* can omit description */
   { KOIOS_STHR  ,  3 ,  3 , "åinclæ and åmodeæ w/three fields"      },
   { KOIOS_SSHAR ,  1 ,  5 , "åSHAREDæ global, config, shared"       },
   { KOIOS_SEXEC ,  6 ,  7 , "åexecæ function call"                  },
   { KOIOS_SEKOH ,  6 ,  7 , "åechoæ function call"                  },
   { KOIOS_SCODE ,  4 ,  4 , "all non-exec except load"              },
   { KOIOS_SLOAD ,  4 ,  4 , "åloadæ input loading"                  },
   { KOIOS_SAUDT ,  0 ,  0 , "åPRCSæ all statistic footers"          },
   /*-----min--max----description----------------------------*/
   {  0          ,  0 ,  0 , "end-of-list"                           },
};

char
VERB_limits             (char a_spec, char *r_min, char *r_max, char r_desc [LEN_DESC])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        i           =    0;
   /*---(defaults)-----------------------*/
   if (r_min  != NULL)  *r_min = 0;
   if (r_max  != NULL)  *r_max = 0;
   if (r_desc != NULL)  strcpy (r_desc, "");
   /*---(process)------------------------*/
   for (i = 0; i < LEN_LABEL; ++i) {
      if (s_specs [i].s_spec == 0)       break;
      if (s_specs [i].s_spec != a_spec)  continue;
      if (r_min  != NULL)  *r_min = s_specs [i].s_min;
      if (r_max  != NULL)  *r_max = s_specs [i].s_max;
      if (r_desc != NULL)  strlcpy (r_desc, s_specs [i].s_desc, LEN_DESC);
      return 1;
   }
   /*---(complete)-----------------------*/
   return --rce;
}

struct cLOCN {
   char        s_locn;
   char        s_desc      [LEN_DESC];
} static s_locns [LEN_TERSE] = {
   { '-' , "anywhere"                            },
   { 'n' , "normal unit test files only"         },
   { 'm' , "unit_wide or unit_data only"         },
   {  0  , "end-of-list"                         },
};

struct cTYPE {
   char        s_type;
   char        s_desc      [LEN_DESC];
} static s_types [LEN_LABEL] = {
   { '-' , "nothing"                             },
   { '*' , "anything (under only"                },
   { 'P' , "prep header"                         },
   { '#' , "comment"                             },
   { 'S' , "script header"                       },
   { 'C' , "condition header"                    },
   { '´' , "all other verbs"                     },
   { 'W' , "wave definition"                     },
   { 'W' , "wave definition"                     },
   {  0  , "end-of-list"                         },
};



/*===[[ VERB DEFINITION TABLE ]]==============================================*/

#define     MAX_VERB         50
typedef     struct cVERB    tVERB;
struct cVERB {
   char        v_abbr;                      /* unique identifier              */
   char        v_name      [LEN_LABEL];     /* verb                           */
   char        v_indent;                    /* expected indentation           */
   char        v_desc      [LEN_DESC];      /* description                    */
   char        v_spec;                      /* verb type for parsing          */
   char        v_locn;                      /* master vs normal vs both       */
   char        v_is;                        /* type of this structure         */
   char        v_under;                     /* type of larger structure       */
   int         v_count;                     /* number found in script         */
   int         v_total;                     /* number found in unit test      */
   char      (*v_conv) (void);              /* conversion function            */ 
   char      (*v_code) (void);              /* code function                  */ 
   char        v_ditto;                     /* can be within a DITTO          */
   char        v_select;                    /* selective execution in shares  */
} static s_verbs [MAX_VERB] = {
   /*---  ---overall-----  ind   ----------description------------------  ---spec----    -loc- --is- -un--    cnt tot ----conv----    ----code----    --dit-  --sel- */
   { '·' , ""             ,  0 , "overall"                               , '-'          , '-' , '-' , '-' ,     0,  0, NULL          , NULL          ,  '-'  ,  '-'  },
   { PREP, "PREP"         ,  0 , "preparation before testing"            , KOIOS_STWO   , '-' , PREP, '-' ,     0,  0, CONV__prep    , NULL          ,  '-'  ,  '-'  },
   { INCL, "incl"         , 3  , "c header inclusion"                    , KOIOS_STHR   , '-' , '-' , PREP,     0,  0, CONV__incl    , CODE__incl    ,  '-'  ,  '-'  },
   { DOCM, "#>"           ,  0 , "script internal comments"              , KOIOS_SDOC   , '-' , DOCM, ANYT,     0,  0, CONV__comment , NULL          ,  '-'  ,  '-'  },
   /*---  ---scrps------- ind   -----------description------------------  ---spec----    -loc- --is- -un--    cnt tot ----conv----    ----code----    --dit-  --sel-  */
   { '·' , ""             ,  0 , "scripts"                               , '-'          , '-' , '-' , '-' ,     0,  0, NULL          , NULL          ,  '-'  ,  '-'  },
   { SCRP, "SCRP"         ,  0 , "test script header"                    , KOIOS_SSCRP  , NORM, SCRP, '-' ,     0,  0, CONV__scrp    , CODE__scrp    ,  '-'  ,  '-'  },
   { GLOB, "GLOBAL"       ,  0 , "shared code between units"             , KOIOS_SSHAR  , UNIT, SCRP, '-' ,     0,  0, CONV__shared  , CODE__shared  ,  '-'  ,  '-'  },
   { CONF, "CONFIG"       ,  0 , "shared code between units"             , KOIOS_SSHAR  , UNIT, SCRP, '-' ,     0,  0, CONV__shared  , CODE__shared  ,  '-'  ,  '-'  },
   { SHAR, "SHARED"       ,  0 , "shared code between scripts"           , KOIOS_SSHAR  , NORM, SCRP, '-' ,     0,  0, CONV__shared  , CODE__shared  ,  '-'  ,  '-'  },
   { SECT, "SECT"         ,  0 , "grouping of scripts"                   , KOIOS_STWO   , NORM, SCRP, '-' ,     0,  0, CONV__sect    , CODE__sect    ,  '-'  ,  '-'  },
   /*---  ---conds------- ind   -----------description------------------  ---spec----    -loc- --is- -un--    cnt tot ----conv----    ----code----    --dit-  --sel-  */
   { '·' , ""             ,  0 , "conditions"                            , '-'          , '-' , '-' , '-' ,     0,  0, NULL          , NULL          ,  '-'  ,  '-'  },
   { COND, "COND"         , 3  , "test condition"                        , KOIOS_STWO   , '-' , COND, SCRP,     0,  0, CONV__cond    , CODE__cond    ,  '-'  ,  'y'  },
   { DITT, "DITTO"        , 3  , "repeated test condition"               , KOIOS_SONE   , '-' , COND, SCRP,     0,  0, CONV__ditto   , NULL          ,  '-'  ,  'y'  },
   { RUSE, "REUSE"        , 3  , "inclusion of shared code"              , KOIOS_SONE   , '-' , COND, SCRP,     0,  0, CONV__reuse   , CODE__reuse   ,  '-'  ,  'y'  },
   { GROP, "GROUP"        , 3  , "grouping of conditions"                , KOIOS_STWO   , '-' , COND, SCRP,     0,  0, CONV__group   , CODE__group   ,  '-'  ,  'y'  },
   /*---  ---variables--- ind   -----------description------------------  ---spec----    -loc- --is- -un--    cnt tot ----conv----    ----code----    --dit-  --sel-  */
   { '·' , ""             ,  0 , "variables"                             , '-'          , '-' , '-' , '-' ,     0,  0, NULL          , NULL          ,  '-'  ,  '-'  },
   { GVAR, "global"       , 3  , "global/unit variable defn"             , KOIOS_SCODE  , '-' , '-' , PREP,     0,  0, CONV__gvar    , CODE__gvar    ,  '-'  ,  '-'  },
   { LVAR, "local"        , 3  , "local/script variable defn"            , KOIOS_SCODE  , '-' , '-' , SCRP,     0,  0, CONV__gvar    , CODE__lvar    ,  '-'  ,  '-'  },
   /*---  ---steps------- ind   -----------description------------------  ---spec----    -loc- --is- -un--    cnt tot ----conv----    ----code----    --dit-  --sel-  */
   { '·' , ""             ,  0 , "steps"                                 , '-'          , '-' , '-' , '-' ,     0,  0, NULL          , NULL          ,  '-'  ,  '-'  },
   { EXEC, "exec"         , 5  , "function execution"                    , KOIOS_SEXEC  , '-' , '-' , COND,     0,  0, CONV__exec    , CODE__exec    ,  'y'  ,  'y'  },
   { GETT, "get"          , 5  , "unit test accessor retrieval"          , KOIOS_SEXEC  , '-' , '-' , COND,     0,  0, CONV__exec    , CODE__exec    ,  'y'  ,  'y'  },
   { EKOH, "echo"         , 5  , "test a variable directly"              , KOIOS_SEKOH  , '-' , '-' , COND,     0,  0, CONV__echo    , CODE__exec    ,  'y'  ,  'y'  },
   /*---  ---specialty--- ind   -----------description------------------  ---spec----    -loc- --is- -un--    cnt tot ----conv----    ----code----    --dit-  --sel-  */
   { '·' , ""             ,  0 , "specialty"                             , '-'          , '-' , '-' , '-' ,     0,  0, NULL          , NULL          ,  '-'  ,  '-'  },
   { CODE, "code"         , 5  , "insert c code"                         , KOIOS_SCODE  , '-' , '-' , COND,     0,  0, CONV__code    , CODE__code    ,  'y'  ,  'y'  },
   { SYST, "system"       , 5  , "execute shell code"                    , KOIOS_SCODE  , '-' , '-' , COND,     0,  0, CONV__code    , CODE__system  ,  'y'  ,  'y'  },
   { LOAD, "load"         , 5  , "place data into input"                 , KOIOS_SLOAD  , '-' , '-' , COND,     0,  0, CONV__load    , CODE__load    ,  'y'  ,  'y'  },
   { MODE, "mode"         , 5  , "set pass or forced_fail mode"          , KOIOS_STHR   , '-' , '-' , COND,     0,  0, CONV__mode    , CODE__mode    ,  'y'  ,  'y'  },
   /*---  ---support----- ind   -----------description------------------  ---spec----    -loc- --is- -un--    cnt tot ----conv----    ----code----    --dit-  --sel-  */
   { '·' , ""             ,  0 , "support"                               , '-'          , '-' , '-' , '-' ,     0,  0, NULL          , NULL          ,  '-'  ,  '-'  },
   { FDEF, "file"         , 5  , "create a temporary file"               , KOIOS_SCODE  , '-' , '-' , COND,     0,  0, CONV__file    , CODE__file    ,  'y'  ,  'y'  },
   { APPD, "append"       , 5  , "append data to temporary file"         , KOIOS_SCODE  , '-' , '-' , COND,     0,  0, CONV__append  , CODE__append  ,  'y'  ,  'y'  },
   { APPV, "appvis"       , 5  , "append data as visible characters"     , KOIOS_SCODE  , '-' , '-' , COND,     0,  0, CONV__append  , CODE__append  ,  'y'  ,  'y'  },
   /*---  ---statistics-- ind   -----------description------------------  ---spec----    -loc- --is- -un--    cnt tot ----conv----    ----code----    --dit-  --sel-  */
   { '·' , ""             ,  0 , "statistics"                            , '-'          , '-' , '-' , '-' ,     0,  0, NULL          , NULL          ,  '-'  ,  '-'  },
   { PRCS, "PRCS"         , 3  , "script ending"                         , KOIOS_SAUDT  , NORM, AUDT, ANYT,     0,  0, NULL          , NULL          ,  '-'  ,  '-'  },
   { RAHS, "DERAHS"       , 3  , "local shared code ending"              , KOIOS_SAUDT  , NORM, AUDT, ANYT,     0,  0, NULL          , NULL          ,  '-'  ,  '-'  },
   { BOLG, "LABOLG"       , 3  , "global shared code ending"             , KOIOS_SAUDT  , UNIT, AUDT, ANYT,     0,  0, NULL          , NULL          ,  '-'  ,  '-'  },
   { FNOC, "GIFNOC"       , 3  , "global shared code ending"             , KOIOS_SAUDT  , UNIT, AUDT, ANYT,     0,  0, NULL          , NULL          ,  '-'  ,  '-'  },
   { TINU, "TINU"         ,  0 , "full unit test ending"                 , KOIOS_SAUDT  , NORM, AUDT, ANYT,     0,  0, NULL          , NULL          ,  '-'  ,  '-'  },
   { AUDT, "RETSAM"       ,  0 , "master file ending"                    , KOIOS_SAUDT  , UNIT, AUDT, ANYT,     0,  0, NULL          , NULL          ,  '-'  ,  '-'  },
   { ENDG, "#========"    ,  0 , "ending comment"                        , KOIOS_SAUDT  , '-' , AUDT, ANYT,     0,  0, NULL          , NULL          ,  '-'  ,  '-'  },
   /*---  ---ouroboros--- ind   -----------description------------------  ---spec----    -loc- --is- -un--    cnt tot ----conv----    ----code----    --dit-  --sel-  */
   { '·' , ""             ,  0 , "oroboros"                              , '-'          , '-' , '-' , '-' ,     0,  0, NULL          , NULL          ,  '-'  ,  '-'  },
   { WAVE, "WAVE"         ,  0 , "testing wave definition"               , KOIOS_STWO   , UNIT, WAVE, '-' ,     0,  0, NULL          , NULL          ,  '-'  ,  '-'  },
   { STAG, "stage"        , 3  , "testing stage definition"              , KOIOS_STWO   , UNIT, '-' , WAVE,     0,  0, NULL          , NULL          ,  '-'  ,  '-'  },
   /*---  ---sentinal---- ind   -----------description------------------  ---spec----    -loc- --is- -un--    cnt tot ----conv----    ----code----    --dit-  --sel-  */
   {  0  , "----"         ,  0 , "end-of-entries"                        , '-'          , '-' , '-' , '-' ,     0,  0, NULL          , NULL          ,  '-'  ,  '-'  },
   /*---  ---done-------- ind   -----------description------------------  ---spec----    -loc- --is- -un--    cnt tot ----conv----    ----code----    --dit-  --sel-  */
};
static char  s_nverb    =  -1;



char
VERB_init               (void)
{
   /*---(locals)-----------+-----+-----+-*/
   int         i           =    0;
   /*---(find verb)----------------------*/
   for (i = 0; i < MAX_VERB; ++i) {
      if (s_verbs [i].v_name [0] == '-')                break;
      s_verbs [i].v_count = 0;
      s_verbs [i].v_total = 0;
   }
   s_nverb = i;
   return 0;
}

char
VERB_script_reset       (void)
{
   /*---(locals)-----------+-----+-----+-*/
   int         i           =    0;
   /*---(find verb)----------------------*/
   for (i = 0; i < MAX_VERB; ++i) {
      if (s_verbs [i].v_name [0] == '-')                break;
      s_verbs [i].v_count = 0;
   }
   return 0;
}

char
VERB__by_name           (char a_verb [LEN_LABEL], char *r_indent, char r_desc [LEN_DESC], char *r_spec, char *r_locn, char *r_is, char *r_under, int *r_count, int *r_total, void **r_conv, void **r_code, char *r_ditto, char *r_select)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   int         i           =    0;
   /*---(header)-------------------------*/
   UDEBUG_KOIOS   ylog_uenter  (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_desc   != NULL)  strcpy (r_desc, "");
   if (r_indent != NULL)  *r_indent =    0;
   if (r_spec   != NULL)  *r_spec   =  '-';
   if (r_locn   != NULL)  *r_locn   =  '-';
   if (r_is     != NULL)  *r_is     =  '-';
   if (r_under  != NULL)  *r_under  =  '-';
   if (r_count  != NULL)  *r_count  =    0;
   if (r_total  != NULL)  *r_total  =    0;
   if (r_conv   != NULL)  *r_conv   = NULL;
   if (r_code   != NULL)  *r_code   = NULL;
   if (r_ditto  != NULL)  *r_ditto  =  '-';
   if (r_select != NULL)  *r_select =  '-';
   /*---(defense)------------------------*/
   UDEBUG_KOIOS   ylog_upoint  ("a_verb"    , a_verb);
   --rce;  if (a_verb == NULL || a_verb [0] == '\0') {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(prepare)------------------------*/
   if (s_nverb < 0)  VERB_init ();
   /*---(find verb)----------------------*/
   for (i = 0; i < MAX_VERB; ++i) {
      /*---(filter)----------------------*/
      if (s_verbs [i].v_name [0] == '-')                break;
      if (s_verbs [i].v_name [0] != a_verb [0])         continue;
      if (strcmp (s_verbs [i].v_name, a_verb) != 0)     continue;
      /*---(save-back)-------------------*/
      UDEBUG_KOIOS   ylog_uvalue  ("FOUND"     , i);
      if (r_indent != NULL)  *r_indent = s_verbs [i].v_indent;
      if (r_desc   != NULL)  strcpy (r_desc, s_verbs [i].v_desc);
      if (r_spec   != NULL)  *r_spec   = s_verbs [i].v_spec;
      if (r_locn   != NULL)  *r_locn   = s_verbs [i].v_locn;
      if (r_is     != NULL)  *r_is     = s_verbs [i].v_is;
      if (r_under  != NULL)  *r_under  = s_verbs [i].v_under;
      if (r_count  != NULL)  *r_count  = s_verbs [i].v_count;
      if (r_total  != NULL)  *r_total  = s_verbs [i].v_total;
      if (r_conv   != NULL)  *r_conv   = s_verbs [i].v_conv;
      if (r_code   != NULL)  *r_code   = s_verbs [i].v_code;
      if (r_ditto  != NULL)  *r_ditto  = s_verbs [i].v_ditto;
      if (r_select != NULL)  *r_select = s_verbs [i].v_select;
      /*---(complete)--------------------*/
      UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
      return i;
      /*---(done)------------------------*/
   }
   /*---(complete)-----------------------*/
   --rce;
   UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
   return rce;
}

char
VERB__by_cursor         (char a_scope, char a_dir, char r_verb [LEN_LABEL], char *r_indent, char r_desc [LEN_DESC], char *r_spec, char *r_locn, char *r_is, char *r_under, int *r_count, int *r_total, void **r_conv, void **r_code, char *r_ditto, char *r_select)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   int         i           =    0;
   static int  x_last      =   -1;
   int         x_curr      =   -1;
   char        x_found     =  '-';
   int         c           =   -1;  /* position holder in case of non-global scope */
   /*---(default)------------------------*/
   if (r_verb   != NULL)  strcpy (r_verb, "");
   if (r_indent != NULL)  *r_indent =    0;
   if (r_desc   != NULL)  strcpy (r_desc, "");
   if (r_spec   != NULL)  *r_spec   =  '-';
   if (r_locn   != NULL)  *r_locn   =  '-';
   if (r_is     != NULL)  *r_is     =  '-';
   if (r_under  != NULL)  *r_under  =  '-';
   if (r_count  != NULL)  *r_count  =    0;
   if (r_total  != NULL)  *r_total  =    0;
   if (r_conv   != NULL)  *r_conv   = NULL;
   if (r_code   != NULL)  *r_code   = NULL;
   if (r_ditto  != NULL)  *r_ditto  =  '-';
   if (r_select != NULL)  *r_select =  '-';
   /*---(prepare)------------------------*/
   if (s_nverb < 0)  VERB_init ();
   /*---(check cursoring)----------------*/
   x_curr = x_last;
   --rce;  switch (a_dir) {
   case YDLST_HEAD : case YDLST_DHEAD : case  0 :
      x_curr = 0;
      break;
   case YDLST_PREV : case YDLST_DPREV :
      if (x_curr > 0)  --x_curr;
      else             return rce;
      break;
   case YDLST_CURR : case YDLST_DCURR :
      break;
   case YDLST_NEXT : case YDLST_DNEXT : case '·' :  /* · means default */
      ++x_curr;
      break;
   case YDLST_TAIL : case YDLST_DTAIL :
      x_curr = 999;
      break;
   default :
      return rce;
      break;
   }
   /*---(find verb)----------------------*/
   for (i = 0; i < MAX_VERB; ++i) {
      /*---(filter)----------------------*/
      /*> printf ("looking at %2d, %s\n", c, s_verbs [i].v_name);                     <*/
      if (s_verbs [i].v_name [0] == '-')                    break;
      if (s_verbs [i].v_name [0] == '\0' && a_scope != '*') continue;
      ++c;
      if (c != x_curr && x_curr != 999)                     continue;
      /*> printf ("found      %2d, %s\n", c, s_verbs [i].v_name);                     <*/
      /*---(complete)--------------------*/
      if (x_curr == 999)  x_found = 'Y';
      else                x_found = 'y';
      x_last  = c;
      if (x_curr == 999)  continue;
      UDEBUG_KOIOS   ylog_uvalue  ("FOUND"     , c);
      break;
      /*---(done)------------------------*/
   }
   /*---(tuning)-------------------------*/
   if (x_found == 'Y') { --i; x_found = 'y'; }
   /*---(trouble)------------------------*/
   --rce;  if (x_found != 'y') {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(save-back)-------------------*/
   if (r_verb   != NULL)  strcpy (r_verb, s_verbs [i].v_name);
   if (r_indent != NULL)  *r_indent = s_verbs [i].v_indent;
   if (r_desc   != NULL)  strcpy (r_desc, s_verbs [i].v_desc);
   if (r_spec   != NULL)  *r_spec   = s_verbs [i].v_spec;
   if (r_locn   != NULL)  *r_locn   = s_verbs [i].v_locn;
   if (r_is     != NULL)  *r_is     = s_verbs [i].v_is;
   if (r_under  != NULL)  *r_under  = s_verbs [i].v_under;
   if (r_count  != NULL)  *r_count  = s_verbs [i].v_count;
   if (r_total  != NULL)  *r_total  = s_verbs [i].v_total;
   if (r_conv   != NULL)  *r_conv   = s_verbs [i].v_conv;
   if (r_code   != NULL)  *r_code   = s_verbs [i].v_code;
   if (r_ditto  != NULL)  *r_ditto  = s_verbs [i].v_ditto;
   if (r_select != NULL)  *r_select = s_verbs [i].v_select;
   /*---(complete)-----------------------*/
   UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
   return i;
}

char
VERB__by_index          (char n, char r_verb [LEN_LABEL], char *r_indent, char r_desc [LEN_DESC], char *r_spec, char *r_locn, char *r_is, char *r_under, int *r_count, int *r_total, void **r_conv, void **r_code, char *r_ditto, char *r_select)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   /*---(header)-------------------------*/
   UDEBUG_KOIOS   ylog_uenter  (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_verb   != NULL)  strcpy (r_verb, "");
   if (r_indent != NULL)  *r_indent =    0;
   if (r_desc   != NULL)  strcpy (r_desc, "");
   if (r_spec   != NULL)  *r_spec   =  '-';
   if (r_locn   != NULL)  *r_locn   =  '-';
   if (r_is     != NULL)  *r_is     =  '-';
   if (r_under  != NULL)  *r_under  =  '-';
   if (r_count  != NULL)  *r_count  =    0;
   if (r_total  != NULL)  *r_total  =    0;
   if (r_conv   != NULL)  *r_conv   = NULL;
   if (r_code   != NULL)  *r_code   = NULL;
   if (r_ditto  != NULL)  *r_ditto  =  '-';
   if (r_select != NULL)  *r_select =  '-';
   /*---(prepare)------------------------*/
   if (s_nverb < 0)  VERB_init ();
   /*---(defense)------------------------*/
   UDEBUG_KOIOS   ylog_uvalue  ("s_nverb"   , s_nverb);
   --rce;  if (n < 0 || n >= s_nverb) {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(save-back)----------------------*/
   if (r_verb   != NULL)  strcpy (r_verb, s_verbs [n].v_name);
   if (r_desc   != NULL)  strcpy (r_desc, s_verbs [n].v_desc);
   if (r_indent != NULL)  *r_indent = s_verbs [n].v_indent;
   if (r_spec   != NULL)  *r_spec   = s_verbs [n].v_spec;
   if (r_locn   != NULL)  *r_locn   = s_verbs [n].v_locn;
   if (r_is     != NULL)  *r_is     = s_verbs [n].v_is;
   if (r_under  != NULL)  *r_under  = s_verbs [n].v_under;
   if (r_count  != NULL)  *r_count  = s_verbs [n].v_count;
   if (r_total  != NULL)  *r_total  = s_verbs [n].v_total;
   if (r_conv   != NULL)  *r_conv   = s_verbs [n].v_conv;
   if (r_code   != NULL)  *r_code   = s_verbs [n].v_code;
   if (r_ditto  != NULL)  *r_ditto  = s_verbs [n].v_ditto;
   if (r_select != NULL)  *r_select = s_verbs [n].v_select;
   /*---(complete)-----------------------*/
   UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
   return n;
}

char VERB__index (char a_verb [LEN_LABEL]) { return VERB__by_name (a_verb, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL); }
char VERB__count (void)                    { if (s_nverb < 0)  VERB_init ();  return s_nverb; }

char*
VERB__detail            (char n, char a_verb [LEN_LABEL])
{
   /*---(locals)-----------+-----+-----+-*/
   char        x_CONV      [LEN_TERSE] = "-conv-";
   char        x_CODE      [LEN_TERSE] = "-code-";
   char        x_count     [LEN_SHORT] = "  ·";
   char        x_total     [LEN_SHORT] = "  ·";
   /*---(prepare)------------------------*/
   strcpy (g_print, "");
   if (s_nverb < 0)  VERB_init ();
   if (a_verb != NULL && a_verb [0] != '\0')   n = VERB__index (a_verb);
   /*---(too small)----------------------*/
   if (n < 0 || n >= s_nverb) {
      sprintf (g_print, "--) ······  ·  ······························  · · · ·  ··· ···  ······ ······  · ·  Ï");
      return g_print;
   }
   /*---(in bounds)----------------------*/
   if (s_verbs [n].v_conv  == NULL)  strcpy (x_CONV, "(null)");
   if (s_verbs [n].v_code  == NULL)  strcpy (x_CODE, "(null)");
   if (s_verbs [n].v_count >  0   )  sprintf (x_count, "%3d", s_verbs [n].v_count);
   if (s_verbs [n].v_total >  0   )  sprintf (x_total, "%3d", s_verbs [n].v_total);
   sprintf (g_print, "%02d) %-6.6s  %1d  %-30.30s  %c %c %c %c  %-3.3s %-3.3s  %-6.6s %-6.6s  %c %c  Ï", n, s_verbs [n].v_name, s_verbs [n].v_indent, s_verbs [n].v_desc, s_verbs [n].v_spec, s_verbs [n].v_locn, s_verbs [n].v_is, s_verbs [n].v_under, x_count, x_total, x_CONV, x_CODE, s_verbs [n].v_ditto, s_verbs [n].v_select);
   /*---(complete)-----------------------*/
   return g_print;
}

char
VERB_dittoable          (char a_verb [LEN_LABEL])
{
   char        x_ditto     =  '-';
   VERB__by_name (a_verb, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, &x_ditto, NULL);
   if (x_ditto != 'y')  return 0;
   return 1;
}

char
VERB_selectable         (char a_verb [LEN_LABEL])
{
   char        x_select    =  '-';
   VERB__by_name (a_verb, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, &x_select);
   if (x_select != 'y')  return 0;
   return 1;
}

char
VERB__addto             (char n)
{
   char        rce         =  -10;
   --rce;  if (n < 0 || n >= s_nverb)  return rce;
   ++(s_verbs [n].v_count);
   ++(s_verbs [n].v_total);
   return 1;
}

char
VERB__parse_under       (char a_nscrp [LEN_TITLE], int a_line, char a_verb [LEN_LABEL], char a_is, char a_under, char *b_under)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   /*---(DEBUGGING)----------------------*/
   /*> /+ TEMP_DEBUG +/ printf ("line %4d, %-10.10s, is (%c), under (%c), b_under (%c)\n", a_line, a_verb, a_is, a_under, *b_under);   <*/
   /*---(ANYWHERE)-----------------------*/
   if (a_is == DOCM)                          return 7;
   /*---(AUDIT/TOTALS)-------------------*/
   if (a_is == AUDT)                          { *b_under = NONE;  return 6; }
   /*---(script always good"-------------*/
   if (a_is == SCRP)                          { *b_under = a_is;  return 2; }
   /*---(script always good)-------------*/
   if (a_is == ANYT && *b_under == a_under)   return 4;
   /*---(condition-level)----------------*/
   if (a_is == COND && *b_under == COND)      return 3;
   /*---(step-level)---------------------*/
   if (a_is == NONE && *b_under == a_under)   return 4;
   /*---(wave-level)---------------------*/
   if (a_is == WAVE)                         { *b_under = a_is;  return 5; }
   /*---(trouble check)------------------*/
   --rce;  if (a_under  != *b_under) {
      UDEBUG_KOIOS   ylog_unote   ("wrong line ownership (dangerous)");
      yerr_uerror ("%s:%d:0: error: verb å%sæ is good; BUT, under (%c) while needs to be under (%c)", a_nscrp, a_line, a_verb, *b_under, a_under);
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(save-back)----------------------*/
   if (a_is != NONE)  *b_under = a_is;
   /*---(ocmplete)-----------------------*/
   return 1;
}

char
VERB_parse              (char a_nscrp [LEN_TITLE], int a_line, char a_field [LEN_LABEL], char *b_under, char r_verb [LEN_LABEL], char *r_indx, char *r_spec, char *r_locn, char **r_conv, char **r_code)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char       *p           = NULL;
   int         i           =    0;
   int         l           =    0;
   int         c           =    0;
   char        x_word      [LEN_LABEL] = "";
   char        x_verb      [LEN_LABEL] = "";
   char        x_indx      =   -1;
   char        x_spec      =  '-';
   char        x_locn      =  '-';
   char        x_is        =  '-';
   char        x_under     =  '-';
   char      (*x_conv) (void)  = NULL;
   char      (*x_code) (void)  = NULL;
   /*---(header)-------------------------*/
   UDEBUG_KOIOS   ylog_uenter  (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_verb  != NULL)  strlcpy  (r_verb , "", LEN_LABEL);
   if (r_indx  != NULL)  *r_indx  = -1;
   if (r_spec  != NULL)  *r_spec  = '-';
   if (r_locn  != NULL)  *r_locn  = '-';
   if (r_conv  != NULL)  *r_conv  = NULL;
   if (r_code  != NULL)  *r_code  = NULL;
   /*---(defense)------------------------*/
   UDEBUG_KOIOS   ylog_upoint  ("a_nscrp"   , a_nscrp);
   --rce;  if (a_nscrp == NULL) {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   UDEBUG_KOIOS   ylog_upoint  ("a_field"   , a_field);
   --rce;  if (a_field == NULL || strlen (a_field) <= 0) {
      yerr_uerror ("%s:%d:0: error: no verb found (empty or null)", a_nscrp, a_line);
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   UDEBUG_KOIOS   ylog_upoint  ("b_under"   , b_under);
   --rce;  if (b_under == NULL) {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(prepare)------------------------*/
   strlcpy  (x_word, a_field, LEN_FULL);
   /*---(get indentation)----------------*/
   l = strlen (x_word);;
   for (i < 0; i < l; ++i) {
      if (x_word [i] != ' ') break;
      ++c;
   }
   /*---(clean up)-----------------------*/
   ystrutrim (x_word, LEN_FULL);
   p = strchr (x_word, ' ');
   if (p != NULL)  p [0] = '\0';
   UDEBUG_KOIOS   ylog_unote   (x_word);
   /*---(find verb)----------------------*/
   x_indx = VERB__by_name (x_word, NULL, NULL, &x_spec, &x_locn, &x_is, &x_under, NULL, NULL, &x_conv, &x_code, NULL, NULL);
   UDEBUG_KOIOS   ylog_uvalue  ("x_indx"    , x_indx);
   --rce;  if (x_indx < 0) {
      UDEBUG_KOIOS   ylog_unote   ("verb not found");
      rc = yerr_uerror ("%s:%d:0: error: verb å%sæ not recognized/found", a_nscrp, a_line, x_word);
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   strlcpy (x_verb, x_word, LEN_LABEL);
   /*---(failure)------------------------*/
   --rce;  if (x_indx == -1) {
      yerr_uerror ("%s:%d:0: error: verb å%sæ not recognized/found", a_nscrp, a_line, x_word);
      UDEBUG_KOIOS   ylog_unote   ("verb not found");
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(file limitations)---------------*/
   --rce;  IF_GLOBAL_A {
      if (x_locn == 'n') {
         UDEBUG_KOIOS   ylog_unote   ("verb not allowed in unit_head.unit, unit_wide.unit, or unit_data.unit");
         yerr_uerror ("%s:%d:0: error: verb å%sæ good; BUT, not allowed inside unit_head.unit, unit_wide.unit, or unit_data.unit", a_nscrp, a_line, x_verb);
         UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
         return rce;
      }
   } else {
      if (x_locn == 'm') {
         UDEBUG_KOIOS   ylog_unote   ("verb not allowed outside unit_head.unit, unit_wide.unit, or unit_data.unit");
         yerr_uerror ("%s:%d:0: error: verb å%sæ good; BUT, not allowed outside unit_head.unit, unit_wide.unit, or unit_data.unit", a_nscrp, a_line, x_verb);
         UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
         return rce;
      }
   }
   /*---(underneath problem)-------------*/
   rc = VERB__parse_under (a_nscrp, a_line, x_verb, x_is, x_under, b_under);
   --rce;  if (rc < 0) {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(save-back)----------------------*/
   if (r_verb  != NULL)  strlcpy (r_verb, x_verb, LEN_LABEL);
   if (r_indx  != NULL)  *r_indx  = x_indx;
   if (r_spec  != NULL)  *r_spec  = x_spec;
   if (r_locn  != NULL)  *r_locn  = x_locn;
   if (r_conv  != NULL)  *r_conv  = x_conv;
   if (r_code  != NULL)  *r_code  = x_code;
   /*---(complete)-----------------------*/
   UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
   return 1;
}

char
VERB_inventory     (FILE *a_main)
{
   int         i           = 0;
   int         c           = 0;
   CONV_printf (a_main, "\n");
   CONV_printf (a_main, "static char\n");
   CONV_printf (a_main, "yUNIT_verbs (void)\n");
   CONV_printf (a_main, "{\n");
   CONV_printf (a_main, "   printf (\"koios, record type summary\\n\");\n");
   for (i = 0; i < MAX_VERB; ++i) {
      if (s_verbs [i].v_name [0] == '\0' || s_verbs [i].v_name [0] == '-') {
         CONV_printf (a_main, "   printf (\"\\n%s...\\n\");\n", s_verbs [i].v_desc);
      } else {
         CONV_printf (a_main, "   printf (\"  %-10.10s = %5d   %s\\n\");\n", s_verbs [i].v_name, s_verbs [i].v_total, s_verbs [i].v_desc);
         c += s_verbs [i].v_total;
      }
      if (s_verbs [i].v_name [0] == '-') break;
   }
   CONV_printf (a_main, "   printf (\"%-10.10s   = %5d   %s\\n\");\n", "TOTAL"         , c                 , "count of all verb use");
   CONV_printf (a_main, "   printf (\"%-10.10s   = %5d   %s\\n\");\n", "concerns"      , my_run.r_nrecd - c, "records with troubles");
   CONV_printf (a_main, "   return 0;\n");
   CONV_printf (a_main, "}\n");
   CONV_printf (a_main, "\n");
   return 0;
}

