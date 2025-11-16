/*===============================[[ beg-code ]]===============================*/
#include    "koios.h"        /* LOCAL  : main header                          */

/*
 *  ZERO globals referenced in file
 */


char
PARSE_default           (char r_verb [LEN_LABEL], char *r_spec, char **r_conv, char **r_code, char r_stage [LEN_SHORT], char *r_vers, char r_desc [LEN_LONG], char r_meth [LEN_HUND], char r_args [LEN_FULL], char r_test [LEN_LABEL], char r_expe [LEN_RECD], char r_retn [LEN_FULL], char *r_ditto, char *r_major, char *r_minor, char r_which [LEN_TITLE])
{
   if (r_verb   != NULL)  strcpy (r_verb  , "");
   if (r_spec   != NULL)  *r_spec   =  '-';
   if (r_conv   != NULL)  *r_conv   = NULL;
   if (r_code   != NULL)  *r_code   = NULL;
   if (r_stage  != NULL)  strcpy (r_stage , "");
   if (r_vers   != NULL)  *r_vers   =   -1;
   if (r_desc   != NULL)  strcpy (r_desc  , "");
   if (r_meth   != NULL)  strcpy (r_meth  , "");
   if (r_args   != NULL)  strcpy (r_args  , "");
   if (r_test   != NULL)  strcpy (r_test  , "");
   if (r_expe   != NULL)  strcpy (r_expe  , "");
   if (r_retn   != NULL)  strcpy (r_retn  , "");
   if (r_ditto  != NULL)  *r_ditto  =  '-';
   if (r_major  != NULL)  *r_major  =  '-';
   if (r_minor  != NULL)  *r_minor  =  '-';
   if (r_which  != NULL)  strcpy (r_which , "");
   return 0;
}

char
PARSE__defense          (char a_nscrp [LEN_TITLE], int a_line, char a_recd [LEN_RECD], char r_verb [LEN_LABEL], char *r_spec, char **r_conv, char **r_code, char r_stage [LEN_SHORT], char *r_vers)
{
   /*---(locals)-----------+-----------+-*/
   char        rce         = -10;           /* return code for errors         */
   int         l           =   0;
   /*---(header)-------------------------*/
   debug_uver   ylog_uenter  (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_verb   != NULL)  strcpy (r_verb  , "");
   if (r_spec   != NULL)  *r_spec =  '-';
   if (r_conv   != NULL)  *r_conv = NULL;
   if (r_code   != NULL)  *r_code = NULL;
   if (r_stage  != NULL)  strcpy (r_stage , "");
   if (r_vers   != NULL)  *r_vers =   -1;
   /*---(feeder fields)------------------*/
   debug_uver   ylog_upoint  ("a_ncrp"    , a_nscrp);
   --rce;  if (a_nscrp == NULL) {
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   debug_uver   ylog_uvalue  ("a_line"    , a_line);
   /*---(record)-------------------------*/
   debug_uver   ylog_upoint  ("a_recd"    , a_recd);
   --rce;  if (a_recd == NULL) {
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   debug_uver   ylog_uchar   ("a_recd [0]", a_recd [0]);
   --rce;  if (a_recd [0] == '\0') {
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   l = strlen (a_recd);
   debug_uver   ylog_uvalue  ("l"         , l);
   --rce;  if (l <  5 && a_recd [0] != '#') {
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(return fields)------------------*/
   debug_uver   ylog_upoint  ("r_verb"    , r_verb);
   --rce;  if (r_verb == NULL) {
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   debug_uver   ylog_upoint  ("r_spec"    , r_spec);
   --rce;  if (r_spec == NULL) {
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   debug_uver   ylog_upoint  ("r_conv"    , r_conv);
   --rce;  if (r_conv == NULL) {
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   debug_uver   ylog_upoint  ("r_code"    , r_code);
   --rce;  if (r_code == NULL) {
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   debug_uver   ylog_upoint  ("r_stage"   , r_stage);
   --rce;  if (r_stage == NULL) {
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   debug_uver   ylog_upoint  ("r_vers"    , r_vers);
   --rce;  if (r_vers == NULL) {
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(complete)-----------------------*/
   debug_uver   ylog_uexit   (__FUNCTION__);
   return 0;
}

char
PARSE__comment          (char a_nscrp [LEN_TITLE], int a_line, char a_recd [LEN_RECD], char r_verb [LEN_LABEL], char *r_under, char *r_spec, char **r_conv, char **r_code, char r_expe [LEN_RECD])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   int         i           =    0;
   char        x_recd      [LEN_RECD]  = "";
   int         x_len       =    0;
   char        x_verb      [LEN_LABEL] = "";
   char        x_indx      =   -1;
   char        x_spec      =  '-';
   char      (*x_conv) (void)  = NULL;
   char      (*x_code) (void)  = NULL;
   /*---(header)-------------------------*/
   debug_uver   ylog_uenter  (__FUNCTION__);
   /*---(defense)------------------------*/
   debug_uver   ylog_upoint  ("a_nscrp"   , a_nscrp);
   --rce;  if (a_nscrp == NULL) {
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   debug_uver   ylog_upoint  ("a_recd"    , a_recd);
   --rce;  if (a_recd == NULL) {
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   x_len = strlen (a_recd);
   /*---(ward-off)-----------------------*/
   debug_uver   ylog_uvalue  ("x_len"     , x_len);
   if (x_len < 2) {
      debug_uver   ylog_unote   ("too short");
      debug_uver   ylog_uexit   (__FUNCTION__);
      return 0;
   }
   if      (strncmp (a_recd, "#>"     , 2) == 0) ;
   else if (strncmp (a_recd, "   #>"  , 5) == 0) ;
   else if (strncmp (a_recd, "     #>", 7) == 0) ;
   else {
      debug_uver   ylog_unote   ("not prefixed with #>");
      debug_uver   ylog_uexit   (__FUNCTION__);
      return 0;
   }
   /*---(check for marker)---------------*/
   debug_uver   ylog_unote   ("saved record/comment");
   rc = VERB_parse (a_nscrp, a_line, "#>", r_under, x_verb, &x_indx, &x_spec, NULL, &x_conv, &x_code);
   debug_uver   ylog_uvalue  ("verb"      , rc);
   --rce;  if (rc < 0) {
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(save-back)----------------------*/
   if (r_verb  != NULL)  strlcpy (r_verb, x_verb, LEN_LABEL);
   if (r_spec  != NULL)  *r_spec = x_spec;
   if (r_conv  != NULL)  *r_conv = x_conv;
   if (r_code  != NULL)  *r_code = x_code;
   if (r_expe  != NULL)  strlcpy (r_expe, a_recd, LEN_RECD);
   /*---(complete)-----------------------*/
   debug_uver   ylog_uexit   (__FUNCTION__);
   return 1;
}

char
PARSE__version          (char *a_field, char *r_vers)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        x_field     [LEN_TERSE] = "";
   int         l           =    0;
   char        x_vers      =   -1;
   /*---(default)------------------------*/
   if (r_vers != NULL)  *r_vers = -1;
   /*---(defense)------------------------*/
   --rce;  if (a_field == NULL)  return rce;
   --rce;  if (r_vers  == NULL)  return rce;
   /*---(prepare)------------------------*/
   strlcpy  (x_field, a_field, LEN_TERSE);
   ystrutrim (x_field, LEN_TERSE);
   l = strlen (x_field);
   /*---(assign version)-----------------*/
   if      (l != 3)                            *r_vers =  0;   /* current */
   else if (x_field [0] != 'v')                *r_vers =  0;   /* current */
   else if (strcmp (x_field, "v21") == 0)      *r_vers = 21;
   else if (strcmp (x_field, "v20") == 0)      *r_vers = 20;
   else if (strcmp (x_field, "v19") == 0)      *r_vers = 19;
   /*---(handle trouble)-----------------*/
   --rce;  if (*r_vers < 0)  return rce;
   /*---(complete)-----------------------*/
   return 0;
}

char
PARSE_prep              (FILE **b_scrp, char a_nscrp [LEN_TITLE], int a_line, char a_runtype, char a_recd [LEN_RECD], char r_verb [LEN_LABEL], char *r_under, char *r_spec, char **r_conv, char **r_code, char r_stage [LEN_SHORT], char *r_vers, char r_desc [LEN_LONG], char r_expe [LEN_RECD], char *r_ditto, char *r_dittoing, char *r_dtarget, int *r_dstart, int *r_dline, char *r_major, char *r_minor, char *r_share, char *r_select)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   int         rc          = 0;             /* generic return code            */
   char        x_recd      [LEN_RECD]  = "";
   int         x_len       = 0;             /* input record length            */
   char       *p           = NULL;
   char       *q           = "";
   char       *r           = NULL;
   char       *v           = NULL;
   /*---(header)-------------------------*/
   debug_uver   ylog_uenter  (__FUNCTION__);
   /*---(saved comments)-----------------*/
   rc = PARSE__comment (a_nscrp, a_line, a_recd, r_verb, r_under, r_spec, r_conv, r_code, r_expe);
   debug_uver   ylog_uvalue  ("comment"   , rc);
   --rce;  if (rc <  0) {
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   if (rc == 1) {
      debug_uver   ylog_uexit   (__FUNCTION__);
      return 1;
   }
   /*---(create a copy of recd)----------*/
   debug_uver   ylog_upoint  ("a_recd"    , a_recd);
   --rce;  if (a_recd == NULL) {
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   debug_uver   ylog_uinfo   ("a_recd"    , a_recd);
   strlcpy (x_recd, a_recd, LEN_RECD);
   debug_uver   ylog_uinfo   ("x_recd"    , x_recd);
   debug_uver   ylog_upoint  ("p"         , p);
   p  = strtok_r (x_recd, q, &r);
   debug_uver   ylog_upoint  ("p"         , p);
   debug_uver   ylog_upoint  ("p"         , p);
   debug_uver   ylog_upoint  ("p"         , p);
   debug_uver   ylog_upoint  ("p"         , p);
   if (p == NULL) {
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(get verb)-----------------------*/
   rc = VERB_parse     (a_nscrp, a_line, p, r_under, r_verb, NULL, r_spec, NULL, r_conv, r_code);
   debug_uver   ylog_uvalue  ("verb"      , rc);
   --rce;  if (rc < 0) {
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   debug_uver   ylog_uinfo   ("r_verb"    , r_verb);
   /*---(read version)-------------------*/
   v = strtok_r (NULL  , q, &r);
   --rce;  if (v == NULL && *r_spec != 'c') {
      yerr_uerror ("%s:%d:1: error: verb only, %s requires more fields", a_nscrp, a_line, r_verb);
      debug_uver   ylog_unote   ("strtok came up empty");
      debug_uver   ylog_uexit   (__FUNCTION__);
      return rce;
   }
   rc = PARSE__version (v, r_vers);
   /*---(check for shares)---------------*/
   rc = REUSE_parse    (a_nscrp, a_line, r_verb, *r_vers, a_recd, *r_share, r_desc, r_major, r_minor);
   debug_uver   ylog_uvalue  ("reuses"    , rc);
   --rce;  if (rc < 0) {
      debug_uver   ylog_uexitr  (__FUNCTION__, rc);
      return rce;
   }
   /*---(check for totals)---------------*/
   rc = REUSE_totals  (r_verb, a_recd);
   debug_uver   ylog_uvalue  ("totals"    , rc);
   if (rc == 1) {
      debug_uver   ylog_uexit   (__FUNCTION__);
      return 1;
   }
   /*---(check for ditto)----------------*/
   rc = DITTO_parse_handler (b_scrp, a_nscrp, a_line, a_runtype, r_verb, *r_vers, a_recd, p, r_desc, r_ditto, r_dittoing, r_dtarget, r_dstart, r_dline);
   debug_uver   ylog_uvalue  ("ditto"     , rc);
   --rce;  if (rc < 0) {
      debug_uver   ylog_uexitr  (__FUNCTION__, rc);
      return rce;
   }
   if (rc == 1) {
      debug_uver   ylog_uexit   (__FUNCTION__);
      return 1;
   }
   /*---(check for stage marker)---------*/
   rc = WAVE_parse (a_nscrp, a_line, r_verb, p, r_stage) ;
   debug_uver   ylog_uvalue  ("stage"     , rc);
   --rce;  if (rc < 0) {
      debug_uver   ylog_uexitr  (__FUNCTION__, rc);
      return rce;
   }
   /*---(complete)-----------------------*/
   debug_uver   ylog_uexit   (__FUNCTION__);
   return 0;
}

char
PARSE__default          (char r_desc [LEN_LONG], char r_meth [LEN_HUND], char r_args [LEN_FULL], char r_test [LEN_LABEL], char r_expe [LEN_RECD], char r_retn [LEN_FULL])
{
   if (r_desc   != NULL)  strcpy (r_desc  , "");
   if (r_meth   != NULL)  strcpy (r_meth  , "");
   if (r_args   != NULL)  strcpy (r_args  , "");
   if (r_test   != NULL)  strcpy (r_test  , "");
   if (r_expe   != NULL)  strcpy (r_expe  , "");
   if (r_retn   != NULL)  strcpy (r_retn  , "");
   return 0;
}

char
PARSE__limits           (char a_spec, char *r_min, char *r_max)
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
PARSE__which            (char a_nscrp [LEN_TITLE], int a_line, char a_desc [LEN_LONG], char r_which [LEN_TITLE])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char       *p           = NULL;
   char        t           [LEN_LONG]  = "";
   char        x_which     [LEN_TITLE] = "";
   int         l           =    0;
   int         i           =    0;
   /*---(header)-------------------------*/
   debug_uver   ylog_uenter  (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_which != NULL)  strcpy (r_which, "");
   /*---(defense)------------------------*/
   debug_uver   ylog_upoint  ("a_desc"    , a_desc);
   --rce;  if (a_desc == NULL) {
      yerr_uerror ("%s:%d:0: error: full description field is NULL", a_nscrp, a_line);
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(find start)---------------------*/
   p = strchr (a_desc, 'å');
   debug_uver   ylog_upoint  ("p"         , p);
   if (p == NULL) {
      debug_uver   ylog_uexit   (__FUNCTION__);
      return 0;
   }
   strlcpy (t, p + 1, LEN_LONG);
   debug_uver   ylog_uinfo   ("t"         , t);
   /*---(find end)-----------------------*/
   p = strchr (t, 'æ');
   debug_uver   ylog_upoint  ("p"         , p);
   --rce;  if (p == NULL) {
      yerr_uerror ("%s:%d:0: error: description \"%s\" starts selectable, but does not cloce, i.e., åabc··d··æ", a_nscrp, a_line, a_desc);
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   p [0] = '\0';
   debug_uver   ylog_uinfo   ("t"         , t);
   l = strlen (t);
   debug_uver   ylog_uvalue  ("l"         , l);
   /*---(check valid)--------------------*/
   --rce;  for (i = 0; i < l; ++i) {
      if (strchr (YSTR_ALLCHAR "-·", t [i]) != NULL)  continue;
      yerr_uerror ("%s:%d:0: error: which string å%sæ contains illegal char (%c) at pos (%d), only allow [A-Za-z0-9è-ÿ·-]", a_nscrp, a_line, t, t [i], i);
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(save-back)----------------------*/
   if (r_which != NULL)  strlcpy (r_which, t, LEN_TITLE);
   /*---(complete)-----------------------*/
   debug_uver   ylog_uexit   (__FUNCTION__);
   return 1;
}

char
PARSE__current          (char n, char a_field [LEN_RECD], char a_spec, char *r_max, char r_desc [LEN_LONG], char r_meth [LEN_HUND], char r_args [LEN_FULL], char r_test [LEN_LABEL], char r_expe [LEN_RECD], char r_retn [LEN_FULL])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   int         l           =    0;
   char        x_field     [LEN_RECD]  = "";
   /*---(header)-------------------------*/
   debug_uver   ylog_uenter  (__FUNCTION__);
   /*---(quick out)----------------------*/
   if (r_max != NULL) {
      debug_uver   ylog_uvalue  ("r_max"     , *r_max);
      --rce;  if (n < 2 || n > *r_max) {
         debug_uver   ylog_uexitr  (__FUNCTION__, rce);
         return rce;
      }
   }
   /*---(defense)------------------------*/
   debug_uver   ylog_upoint  ("a_field"   , a_field);
   --rce;  if (a_field == NULL) {
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(clear spacer bars)--------------*/
   strlcpy (x_field, a_field, LEN_RECD);
   if (x_field [0] == '-' && n != 6) {
      if (strncmp (x_field, "- - -", 5) == 0)    x_field [0] = '\0';
      if (strncmp (x_field, "-----", 5) == 0)    x_field [0] = '\0';
      if (x_field [1] == '\0')                   x_field [0] = '\0';
   }
   ystrutrim (x_field, LEN_RECD);
   l = strlen (x_field);
   debug_uver   ylog_uinfo   ("x_field"   , x_field);
   /*---(handle fields)------------------*/
   switch (n) {
   case  2 :  /*=== always desc ===============*/
      if (r_desc != NULL) {
         strlcpy  (r_desc, x_field        , LEN_LONG);
         ystrutrim (r_desc, LEN_LONG);
         if (r_desc [0] == '\0')  strlcpy (r_desc, "[ - - - - - - (empty) - - - - - - ]", LEN_LONG);
      }
      break;
   case  3 :  /*=== typically, method =========*/
      /*---(script types)----------------*/
      if (a_spec == 's') {
         if (r_test != NULL) {
            strlcpy (r_test, x_field, LEN_LABEL);
            debug_uver   ylog_uinfo   ("duration"  , r_test);
         }
      }
      /*---(others, except sepciality)---*/
      else if (a_spec != 'p') {
         if (r_meth != NULL) {
            strlcpy (r_meth, x_field, LEN_HUND );
            debug_uver   ylog_uinfo   ("meth"      , r_meth);
         }
      }
      break;
   case  4 :  /*=== typically, argument =======*/
      /*---(script types)----------------*/
      if      (a_spec == 's') {
         if (r_retn != NULL) {
            strlcpy (r_retn, x_field, LEN_FULL);
            debug_uver   ylog_uinfo   ("terse tag" , r_retn);
         }
      }
      /*---(specialty types)-------------*/
      else if (a_spec == 'P' || a_spec == 'p') {
         if (r_expe != NULL) {
            strlcpy (r_expe, x_field, LEN_RECD);
            debug_uver   ylog_uinfo   ("expe"      , r_expe);
         }
      }
      /*---(all others)------------------*/
      else {
         if (r_args != NULL) {
            strlcpy (r_args, x_field, LEN_FULL);
            debug_uver   ylog_uinfo   ("args"      , r_args);
         }
      }
      break;
   case  5 :  /*=== typically, test ===========*/
      /*---(script types)----------------*/
      if (a_spec == 's') {
         if (r_meth != NULL) {
            strlcpy (r_meth, x_field, LEN_HUND );
            debug_uver   ylog_uinfo   ("focus"     , r_meth);
         }
      }
      /*---(all others)------------------*/
      else {
         if (r_test != NULL) {
            strlcpy (r_test, x_field, LEN_LABEL);
            debug_uver   ylog_uinfo   ("test"      , r_test);
         }
      }
      break;
   case  6 :  /*=== expected result ===========*/
      if (r_expe != NULL) {
         strlcpy (r_expe, x_field, LEN_RECD);
         debug_uver   ylog_uinfo   ("expe"      , r_expe);
      }
      break;
   case  7 :  /*=== return variable ===========*/
      if (r_retn != NULL) {
         strlcpy (r_retn, x_field, LEN_FULL);
         debug_uver   ylog_uinfo   ("retn"      , r_retn);
      }
      break;
   }
   /*---(fill-in)---------------------*/
   if (a_spec == 's') {
      if (strcmp (r_desc, "") == 0)  strlcpy (r_desc, "-"  , LEN_LONG);
      if (strcmp (r_test, "") == 0)  strlcpy (r_test, "0s" , LEN_LABEL);
      if (strcmp (r_retn, "") == 0)  strlcpy (r_retn, "tbd", LEN_FULL);
      if (strcmp (r_meth, "") == 0)  strlcpy (r_meth, "-"  , LEN_HUND);
   }
   /*---(complete)--------------------*/
   debug_uver   ylog_uexit   (__FUNCTION__);
   return 0;
}

char
PARSE_driver            (char a_nscrp [LEN_TITLE], int a_line, char a_vers, char a_verb [LEN_LABEL], char a_spec, char a_recd [LEN_RECD], char r_desc [LEN_LONG], char r_meth [LEN_HUND], char r_args [LEN_FULL], char r_test [LEN_LABEL], char r_expe [LEN_RECD], char r_retn [LEN_FULL], char r_which [LEN_TITLE])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   int         rc          =    0;
   char        x_recd      [LEN_RECD]  = "";     /* incomming record               */
   int         i           = 0;
   char       *p           = NULL;
   char       *q           = "";
   char       *r           = NULL;
   char        x_min       =    0;
   char        x_max       =    0;
   char        x_desc      [LEN_LONG]  = "";     /* descriptive text               */
   char        x_meth      [LEN_HUND]  = "";     /* function/method name           */
   char        x_args      [LEN_FULL]  = "";     /* function/method args           */
   char        x_test      [LEN_LABEL] = "";     /* test type for yVAR             */
   char        x_expe      [LEN_RECD]  = "";     /* expected results               */
   char        x_retn      [LEN_FULL]  = "";     /* return variable                */
   char        x_which     [LEN_TITLE] = "";     /* which/selective execution      */
   /*---(header)-------------------------*/
   debug_uver   ylog_uenter  (__FUNCTION__);
   /*---(quick-out)----------------------*/
   if (strchr ("1cU", a_spec) != NULL) {
      debug_uver   ylog_unote   ("one field required and already read as verb");
      debug_uver   ylog_uexit   (__FUNCTION__);
      return 0;  /* ditto type */
   }
   /*---(default)---------------------*/
   PARSE__default  (r_desc, r_meth, r_args, r_test, r_expe, r_retn);
   /*---(defense)------------------------*/
   debug_uver   ylog_upoint  ("a_recd"    , a_recd);
   --rce;  if (a_recd == NULL) {
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   strlcpy (x_recd, a_recd, LEN_RECD);
   /*---(read limits)--------------------*/
   debug_uver   ylog_uchar   ("spec"      , a_spec);
   rc = PARSE__limits (a_spec, &x_min, &x_max);
   debug_uver   ylog_ucomplex("limits"    , "%4d rc, %d min, %d max", rc, x_min, x_max);
   --rce;  if (rc < 0) {
      yerr_uerror ("%s:%d:0: error: can not identify verb ¶%s¶ with '%c' spec limits", a_nscrp, a_line, a_verb, a_spec);
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(prepare)------------------------*/
   p = strtok_r (x_recd, q, &r);
   p = strtok_r (NULL  , q, &r);
   --rce;  if (p == NULL) {
      debug_uver   ylog_unote   ("only one field provided");
      debug_uver   ylog_uexit   (__FUNCTION__);
      return rce;
   }
   --rce;  if (a_vers > 0) {
      p = strtok_r (NULL  , q, &r);
      if (p == NULL) {
         debug_uver   ylog_unote   ("adjusted to having version number");
         debug_uver   ylog_uexit   (__FUNCTION__);
         return rce;
      }
      a_vers = 0;
   }
   /*---(walk-fields)--------------------*/
   for (i = 2; i < 20; ++i) {
      /*---(parse field)-----------------*/
      switch (a_vers) {
      case  0 :
         rc = PARSE__current  (i, p, a_spec, &(x_max), x_desc, x_meth, x_args, x_test, x_expe, x_retn);
         if (rc < 0) {
            debug_uver   ylog_unote   ("could not parse successfully");
            debug_uver   ylog_uexit   (__FUNCTION__);
            return rce;
         }
         break;
      default : 
         debug_uver   ylog_unote   ("version not recognized");
         debug_uver   ylog_uexit   (__FUNCTION__);
         return rce;
         break;
      }
      /*---(check which)-----------------*/
      if (i == 2) {
         rc = PARSE__which (a_nscrp, a_line, x_desc, x_which);
         debug_uver   ylog_unote   ("could not extract which/select successfully");
         if (rc < 0) {
            debug_uver   ylog_uexit   (__FUNCTION__);
            return rce;
         }
      }
      /*---(drop at max)-----------------*/
      if (i >= x_max)    break;
      /*---(next record)-----------------*/
      debug_uver   ylog_unote   ("read next field");
      p = strtok_r (NULL  , q, &r);
      --rce;  if (p == NULL) {
         debug_uver   ylog_unote   ("strtok came up empty");
         break;
      }
      /*---(done)------------------------*/
   } 
   /*---(stop parsing summ records)---*/
   if (i < x_min) {
      yerr_uerror ("%s:%d:0: error: verb ¶%s¶ included %d fields, requires at least %d", a_nscrp, a_line, a_verb, i, x_min);
      debug_uver   ylog_ucomplex("too few"   , "%d actual < %d min", i, x_min);
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(save-back)-------------------*/
   if (r_desc   != NULL)  strlcpy (r_desc  , x_desc  , LEN_LONG);
   if (r_meth   != NULL)  strlcpy (r_meth  , x_meth  , LEN_HUND);
   if (r_args   != NULL)  strlcpy (r_args  , x_args  , LEN_FULL);
   if (r_test   != NULL)  strlcpy (r_test  , x_test  , LEN_LABEL);
   if (r_expe   != NULL)  strlcpy (r_expe  , x_expe  , LEN_RECD);
   if (r_retn   != NULL)  strlcpy (r_retn  , x_retn  , LEN_FULL);
   if (r_which  != NULL)  strlcpy (r_which , x_which , LEN_TITLE);
   /*---(complete)--------------------*/
   debug_uver   ylog_uexit   (__FUNCTION__);
   return 0;
}


