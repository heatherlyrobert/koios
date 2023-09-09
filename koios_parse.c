/*===============================[[ beg-code ]]===============================*/
#include    "koios.h"        /* LOCAL  : main header                          */


char
PARSE_default           (char r_verb [LEN_LABEL], char *r_spec, char **r_conv, char **r_code, char r_stage [LEN_SHORT], char *r_vers, char r_desc [LEN_LONG], char r_meth [LEN_HUND], char r_args [LEN_FULL], char r_test [LEN_LABEL], char r_expe [LEN_RECD], char r_retn [LEN_FULL], char *r_mark, char *r_share)
{
   if (r_verb   != NULL)  strcpy (r_verb  , "");
   if (r_spec   != NULL)  *r_spec  =  '-';
   if (r_conv   != NULL)  *r_conv  = NULL;
   if (r_code   != NULL)  *r_code  = NULL;
   if (r_stage  != NULL)  strcpy (r_stage , "");
   if (r_vers   != NULL)  *r_vers  =   -1;
   if (r_desc   != NULL)  strcpy (r_desc  , "");
   if (r_meth   != NULL)  strcpy (r_meth  , "");
   if (r_args   != NULL)  strcpy (r_args  , "");
   if (r_test   != NULL)  strcpy (r_test  , "");
   if (r_expe   != NULL)  strcpy (r_expe  , "");
   if (r_retn   != NULL)  strcpy (r_retn  , "");
   if (r_mark   != NULL)  *r_mark  =  '-';
   if (r_share  != NULL)  *r_share =  '-';
   return 0;
}

char
PARSE__defense          (cchar a_nscrp [LEN_TITLE], int a_line, cchar a_recd [LEN_RECD], char r_verb [LEN_LABEL], char *r_spec, char **r_conv, char **r_code, char r_stage [LEN_SHORT], char *r_vers)
{
   /*---(locals)-----------+-----------+-*/
   char        rce         = -10;           /* return code for errors         */
   int         l           =   0;
   /*---(header)-------------------------*/
   DEBUG_INPT   yLOG_senter  (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_verb   != NULL)  strcpy (r_verb  , "");
   if (r_spec   != NULL)  *r_spec =  '-';
   if (r_conv   != NULL)  *r_conv = NULL;
   if (r_code   != NULL)  *r_code = NULL;
   if (r_stage  != NULL)  strcpy (r_stage , "");
   if (r_vers   != NULL)  *r_vers =   -1;
   /*---(feeder fields)------------------*/
   DEBUG_INPT   yLOG_spoint  (a_nscrp);
   --rce;  if (a_nscrp == NULL) {
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_INPT   yLOG_sint    (a_line);
   /*---(record)-------------------------*/
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
PARSE__comment          (cchar a_nscrp [LEN_TITLE], int a_line, cchar a_recd [LEN_RECD], char r_verb [LEN_LABEL], char *r_spec, char **r_conv, char **r_code, char r_expe [LEN_RECD])
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
   DEBUG_INPT   yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   DEBUG_INPT   yLOG_point   ("a_nscrp"   , a_nscrp);
   --rce;  if (a_nscrp == NULL) {
      DEBUG_INPT   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_INPT   yLOG_point   ("a_recd"    , a_recd);
   --rce;  if (a_recd == NULL) {
      DEBUG_INPT   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   x_len = strlen (a_recd);
   /*---(ward-off)-----------------------*/
   DEBUG_INPT   yLOG_value   ("x_len"     , x_len);
   if (x_len < 2) {
      DEBUG_INPT   yLOG_note    ("too short");
      DEBUG_INPT   yLOG_exit    (__FUNCTION__);
      return 0;
   }
   if      (strncmp (a_recd, "#> "     , 3) == 0) ;
   else if (strncmp (a_recd, "   #> "  , 6) == 0) ;
   else if (strncmp (a_recd, "     #> ", 8) == 0) ;
   else {
      DEBUG_INPT   yLOG_note    ("not prefixed with #>");
      DEBUG_INPT   yLOG_exit    (__FUNCTION__);
      return 0;
   }
   /*---(check for marker)---------------*/
   DEBUG_INPT   yLOG_note    ("saved record/comment");
   rc = VERB_parse (a_nscrp, a_line, "#>", x_verb, &x_indx, &x_spec, NULL, &x_conv, &x_code);
   DEBUG_INPT   yLOG_value   ("verb"      , rc);
   --rce;  if (rc < 0) {
      DEBUG_INPT   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(save-back)----------------------*/
   if (r_verb  != NULL)  ystrlcpy (r_verb, x_verb, LEN_LABEL);
   if (r_spec  != NULL)  *r_spec = x_spec;
   if (r_conv  != NULL)  *r_conv = x_conv;
   if (r_code  != NULL)  *r_code = x_code;
   if (r_expe  != NULL)  ystrlcpy (r_expe, a_recd, LEN_RECD);
   /*---(complete)-----------------------*/
   DEBUG_INPT   yLOG_exit    (__FUNCTION__);
   return 1;
}

char
PARSE__version          (cchar *a_field, char *r_vers)
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
   ystrlcpy  (x_field, a_field, LEN_TERSE);
   ystrltrim (x_field, ySTR_BOTH, LEN_TERSE);
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
PARSE_prep              (FILE **b_scrp, cchar a_nscrp [LEN_TITLE], int a_line, char a_runtype, cchar a_recd [LEN_RECD], char r_verb [LEN_LABEL], char *r_spec, char **r_conv, char **r_code, char r_stage [LEN_SHORT], char *r_vers, char r_desc [LEN_LONG], char r_expe [LEN_RECD], char *r_dittoing, char *r_mark, char *r_dmark, int *r_ditto, int *r_dline, char *r_share, char *r_cshare)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   int         rc          = 0;             /* generic return code            */
   char        x_recd      [LEN_RECD];
   int         x_len       = 0;             /* input record length            */
   char       *p;
   char       *q           = "";
   char       *r           = NULL;
   char       *v           = NULL;
   /*---(header)-------------------------*/
   DEBUG_INPT   yLOG_enter   (__FUNCTION__);
   /*---(saved comments)-----------------*/
   rc = PARSE__comment (a_nscrp, a_line, a_recd, r_verb, r_spec, r_conv, r_code, r_expe);
   DEBUG_INPT   yLOG_value   ("comment"   , rc);
   --rce;  if (rc <  0) {
      DEBUG_INPT   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   if (rc == 1) {
      DEBUG_INPT   yLOG_exit    (__FUNCTION__);
      return 1;
   }
   /*---(create a copy of recd)----------*/
   ystrlcpy (x_recd, a_recd, LEN_RECD);
   DEBUG_INPT   yLOG_info    ("x_recd"    , x_recd);
   p  = strtok_r (x_recd, q, &r);
   DEBUG_INPT   yLOG_point   ("p"         , p);
   if (p == NULL) {
      DEBUG_INPT   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(get verb)-----------------------*/
   rc = VERB_parse     (a_nscrp, a_line, p, r_verb, NULL, r_spec, NULL, r_conv, r_code);
   DEBUG_INPT   yLOG_value   ("verb"      , rc);
   --rce;  if (rc < 0) {
      DEBUG_INPT   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_INPT   yLOG_info    ("r_verb"    , r_verb);
   /*---(read version)-------------------*/
   v = strtok_r (NULL  , q, &r);
   --rce;  if (v == NULL && *r_spec != 'c') {
      yURG_err (YURG_FATAL, "%s:%d:1: error: verb only, %s requires more fields", a_nscrp, a_line, r_verb);
      DEBUG_INPT   yLOG_note    ("strtok came up empty");
      DEBUG_INPT   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   rc = PARSE__version (v, r_vers);
   /*---(check for shares)---------------*/
   rc = REUSE_parse    (a_nscrp, a_line, r_verb, *r_vers, a_recd, r_desc, *r_cshare, r_share);
   DEBUG_INPT   yLOG_value   ("reuses"    , rc);
   --rce;  if (rc < 0) {
      DEBUG_INPT   yLOG_exitr   (__FUNCTION__, rc);
      return rce;
   }
   /*---(check for ditto)----------------*/
   rc = DITTO_parse_handler (b_scrp, a_nscrp, a_line, a_runtype, r_verb, *r_vers, a_recd, p, r_desc, r_dittoing, r_mark, r_dmark, r_ditto, r_dline);
   DEBUG_INPT   yLOG_value   ("ditto"     , rc);
   --rce;  if (rc < 0) {
      DEBUG_INPT   yLOG_exitr   (__FUNCTION__, rc);
      return rce;
   }
   if (rc == 1) {
      DEBUG_INPT   yLOG_exit    (__FUNCTION__);
      return 1;
   }
   /*---(check for stage marker)---------*/
   rc = WAVE_parse (a_nscrp, a_line, r_verb, p, r_stage) ;
   DEBUG_INPT   yLOG_value   ("stage"     , rc);
   --rce;  if (rc < 0) {
      DEBUG_INPT   yLOG_exitr   (__FUNCTION__, rc);
      return rce;
   }
   /*---(complete)-----------------------*/
   DEBUG_INPT   yLOG_exit    (__FUNCTION__);
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
PARSE__current          (char n, char a_field [LEN_RECD], cchar a_spec, char *r_max, char r_desc [LEN_LONG], char r_meth [LEN_HUND], char r_args [LEN_FULL], char r_test [LEN_LABEL], char r_expe [LEN_RECD], char r_retn [LEN_FULL])
{
   char        rce         =  -10;
   int         l           =    0;
   char        x_field     [LEN_RECD]  = "";
   /*---(header)-------------------------*/
   DEBUG_INPT   yLOG_enter   (__FUNCTION__);
   /*---(quick out)----------------------*/
   if (r_max != NULL) {
      DEBUG_INPT   yLOG_value   ("r_max"     , *r_max);
      --rce;  if (n < 2 || n > *r_max) {
         DEBUG_INPT   yLOG_exitr   (__FUNCTION__, rce);
         return rce;
      }
   }
   /*---(defense)------------------------*/
   DEBUG_INPT   yLOG_point   ("a_field"   , a_field);
   --rce;  if (a_field == NULL) {
      DEBUG_INPT   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(clear spacer bars)--------------*/
   ystrlcpy (x_field, a_field, LEN_RECD);
   if (x_field [0] == '-' && n != 6) {
      if (strncmp (x_field, "- - -", 5) == 0)    x_field [0] = '\0';
      if (strncmp (x_field, "-----", 5) == 0)    x_field [0] = '\0';
      if (x_field [1] == '\0')                   x_field [0] = '\0';
   }
   ystrltrim (x_field, ySTR_BOTH, LEN_RECD);
   l = strlen (x_field);
   DEBUG_INPT   yLOG_info    ("x_field"   , x_field);
   /*---(handle fields)------------------*/
   switch (n) {
   case  2 :  /*=== always desc ===============*/
      if (r_desc != NULL) {
         ystrlcpy  (r_desc, x_field        , LEN_LONG);
         ystrltrim (r_desc, ySTR_BOTH, LEN_LONG);
      }
      break;
   case  3 :  /*=== typically, method =========*/
      /*---(script types)----------------*/
      if (a_spec == 's') {
         if (l == 0 || l > 10)  {
            if (r_meth != NULL) {
               ystrlcpy (r_meth, x_field, LEN_HUND );
               DEBUG_INPT   yLOG_info    ("focus"     , r_meth);
            }
            if (r_max != NULL)  *r_max = 3;
         } else {
            if (r_test != NULL) {
               ystrlcpy (r_test, x_field, LEN_LABEL);
               DEBUG_INPT   yLOG_info    ("duration"  , r_test);
            }
         }
      }
      /*---(others, except sepciality)---*/
      else if (a_spec != 'p') {
         if (r_meth != NULL) {
            ystrlcpy (r_meth, x_field, LEN_HUND );
            DEBUG_INPT   yLOG_info    ("meth"      , r_meth);
         }
      }
      break;
   case  4 :  /*=== typically, argument =======*/
      /*---(script types)----------------*/
      if      (a_spec == 's') {
         if (r_retn != NULL) {
            ystrlcpy (r_retn, x_field, LEN_FULL);
            DEBUG_INPT   yLOG_info    ("terse tag" , r_retn);
         }
      }
      /*---(specialty types)-------------*/
      else if (a_spec == 'P' || a_spec == 'p') {
         if (r_expe != NULL) {
            ystrlcpy (r_expe, x_field, LEN_RECD);
            DEBUG_INPT   yLOG_info    ("expe"      , r_expe);
         }
      }
      /*---(all others)------------------*/
      else {
         if (r_args != NULL) {
            ystrlcpy (r_args, x_field, LEN_FULL);
            DEBUG_INPT   yLOG_info    ("args"      , r_args);
         }
      }
      break;
   case  5 :  /*=== typically, test ===========*/
      /*---(script types)----------------*/
      if (a_spec == 's') {
         if (r_meth != NULL) {
            ystrlcpy (r_meth, x_field, LEN_HUND );
            DEBUG_INPT   yLOG_info    ("focus"     , r_meth);
         }
      }
      /*---(all others)------------------*/
      else {
         if (r_test != NULL) {
            ystrlcpy (r_test, x_field, LEN_LABEL);
            DEBUG_INPT   yLOG_info    ("test"      , r_test);
         }
      }
      break;
   case  6 :  /*=== expected result ===========*/
      if (r_expe != NULL) {
         ystrlcpy (r_expe, x_field, LEN_RECD);
         DEBUG_INPT   yLOG_info    ("expe"      , r_expe);
      }
      break;
   case  7 :  /*=== return variable ===========*/
      if (r_retn != NULL) {
         ystrlcpy (r_retn, x_field, LEN_FULL);
         DEBUG_INPT   yLOG_info    ("retn"      , r_retn);
      }
      break;
   }
   /*---(complete)--------------------*/
   DEBUG_INPT   yLOG_exit    (__FUNCTION__);
   return 0;
}

char
PARSE_driver            (cchar a_nscrp [LEN_TITLE], int a_line, char a_vers, cchar a_verb [LEN_LABEL], char a_spec, cchar a_recd [LEN_RECD], char r_desc [LEN_LONG], char r_meth [LEN_HUND], char r_args [LEN_FULL], char r_test [LEN_LABEL], char r_expe [LEN_RECD], char r_retn [LEN_FULL])
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
   /*---(header)-------------------------*/
   DEBUG_INPT   yLOG_enter   (__FUNCTION__);
   /*---(quick-out)----------------------*/
   if (strchr ("1c", a_spec) != NULL) {
      DEBUG_INPT   yLOG_note    ("one field required and already read as verb");
      DEBUG_INPT   yLOG_exit    (__FUNCTION__);
      return 0;  /* ditto type */
   }
   /*---(default)---------------------*/
   PARSE__default  (r_desc, r_meth, r_args, r_test, r_expe, r_retn);
   /*---(defense)------------------------*/
   DEBUG_INPT   yLOG_point   ("a_recd"    , a_recd);
   --rce;  if (a_recd == NULL) {
      DEBUG_INPT   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   ystrlcpy (x_recd, a_recd, LEN_RECD);
   /*---(read limits)--------------------*/
   DEBUG_INPT   yLOG_char    ("spec"      , a_spec);
   rc = PARSE__limits (a_spec, &x_min, &x_max);
   DEBUG_INPT   yLOG_complex ("limits"    , "%4d rc, %d min, %d max", rc, x_min, x_max);
   --rce;  if (rc < 0) {
      yURG_err (YURG_FATAL, "%s:%d:0: error: can not identify verb ¶%s¶ with '%c' spec limits", a_nscrp, a_line, a_verb, a_spec);
      DEBUG_INPT   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(prepare)------------------------*/
   p = strtok_r (x_recd, q, &r);
   p = strtok_r (NULL  , q, &r);
   --rce;  if (p == NULL) {
      DEBUG_INPT   yLOG_note    ("only one field provided");
      DEBUG_INPT   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   --rce;  if (a_vers > 0) {
      p = strtok_r (NULL  , q, &r);
      if (p == NULL) {
         DEBUG_INPT   yLOG_note    ("adjusted to having version number");
         DEBUG_INPT   yLOG_exit    (__FUNCTION__);
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
         break;
      default : 
         DEBUG_INPT   yLOG_note    ("version not recognized");
         DEBUG_INPT   yLOG_exit    (__FUNCTION__);
         return rce;
         break;
      }
      if (i >= x_max)    break;
      /*---(next record)-----------------*/
      DEBUG_INPT   yLOG_note    ("read next field");
      p = strtok_r (NULL  , q, &r);
      --rce;  if (p == NULL) {
         DEBUG_INPT   yLOG_note    ("strtok came up empty");
         break;
      }
      /*---(done)------------------------*/
   } 
   /*---(stop parsing summ records)---*/
   if (i < x_min) {
      yURG_err (YURG_FATAL, "%s:%d:0: error: verb ¶%s¶ included %d fields, requires at least %d", a_nscrp, a_line, a_verb, i, x_min);
      DEBUG_INPT   yLOG_complex ("too few"   , "%d actual < %d min", i, x_min);
      DEBUG_INPT   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(save-back)-------------------*/
   if (r_desc   != NULL)  ystrlcpy (r_desc  , x_desc  , LEN_LONG);
   if (r_meth   != NULL)  ystrlcpy (r_meth  , x_meth  , LEN_HUND);
   if (r_args   != NULL)  ystrlcpy (r_args  , x_args  , LEN_FULL);
   if (r_test   != NULL)  ystrlcpy (r_test  , x_test  , LEN_LABEL);
   if (r_expe   != NULL)  ystrlcpy (r_expe  , x_expe  , LEN_RECD);
   if (r_retn   != NULL)  ystrlcpy (r_retn  , x_retn  , LEN_FULL);
   /*---(complete)--------------------*/
   DEBUG_INPT   yLOG_exit    (__FUNCTION__);
   return 0;
}


