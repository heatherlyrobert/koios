/*===============================[[ beg-code ]]===============================*/
#include    "koios.h"        /* LOCAL  : main header                          */



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
PARSE__field            (char n, char a_field [LEN_RECD], cchar a_spec, char *r_max, char r_desc [LEN_LONG], char r_meth [LEN_HUND], char r_args [LEN_FULL], char r_test [LEN_LABEL], char r_expe [LEN_RECD], char r_retn [LEN_FULL])
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
   strlcpy (x_field, a_field, LEN_RECD);
   DEBUG_INPT   yLOG_info    ("x_field"   , x_field);
   /*---(clear spacer bars)--------------*/
   if (x_field [0] == '-' && n != 6) {
      if (strncmp (x_field, "- - -", 5) == 0)    x_field [0] = '\0';
      if (strncmp (x_field, "-----", 5) == 0)    x_field [0] = '\0';
      if (x_field [1] == '\0')                   x_field [0] = '\0';
   }
   DEBUG_INPT   yLOG_info    ("x_field"   , x_field);
   l = strlen (x_field);
   /*---(handle fields)------------------*/
   switch (n) {
   case  2 :  /*=== always desc ===============*/
      if (r_desc != NULL) {
         strlcpy  (r_desc, x_field        , LEN_LONG);
         strltrim (r_desc, ySTR_BOTH, LEN_LONG);
      }
      break;
   case  3 :  /*=== typically, method =========*/
      /*---(script types)----------------*/
      if (a_spec == 's') {
         if (l == 0 || l > 10)  {
            if (r_meth != NULL) {
               strlcpy (r_meth, x_field, LEN_HUND );
               DEBUG_INPT   yLOG_info    ("focus"     , r_meth);
            }
            if (r_max != NULL)  *r_max = 3;
         } else {
            if (r_test != NULL) {
               strlcpy (r_test, x_field, LEN_LABEL);
               DEBUG_INPT   yLOG_info    ("duration"  , r_test);
            }
         }
      }
      /*---(others, except sepciality)---*/
      else if (a_spec != 'p') {
         if (r_meth != NULL) {
            strlcpy (r_meth, x_field, LEN_HUND );
            DEBUG_INPT   yLOG_info    ("meth"      , r_meth);
         }
      }
      break;
   case  4 :  /*=== typically, argument =======*/
      /*---(script types)----------------*/
      if      (a_spec == 's') {
         if (r_retn != NULL) {
            strlcpy (r_retn, x_field, LEN_FULL);
            DEBUG_INPT   yLOG_info    ("terse tag" , r_retn);
         }
      }
      /*---(specialty types)-------------*/
      else if (a_spec == 'P' || a_spec == 'p') {
         if (r_expe != NULL) {
            strlcpy (r_expe, x_field, LEN_RECD);
            DEBUG_INPT   yLOG_info    ("expe"      , r_expe);
         }
      }
      /*---(all others)------------------*/
      else {
         if (r_args != NULL) {
            strlcpy (r_args, x_field, LEN_FULL);
            DEBUG_INPT   yLOG_info    ("args"      , r_args);
         }
      }
      break;
   case  5 :  /*=== typically, test ===========*/
      /*---(script types)----------------*/
      if (a_spec == 's') {
         if (r_meth != NULL) {
            strlcpy (r_meth, x_field, LEN_HUND );
            DEBUG_INPT   yLOG_info    ("focus"     , r_meth);
         }
      }
      /*---(all others)------------------*/
      else {
         if (r_test != NULL) {
            strlcpy (r_test, x_field, LEN_LABEL);
            DEBUG_INPT   yLOG_info    ("test"      , r_test);
         }
      }
      break;
   case  6 :  /*=== expected result ===========*/
      if (r_expe != NULL) {
         strlcpy (r_expe, x_field, LEN_RECD);
         DEBUG_INPT   yLOG_info    ("expe"      , r_expe);
      }
      break;
   case  7 :  /*=== return variable ===========*/
      if (r_retn != NULL) {
         strlcpy (r_retn, x_field, LEN_FULL);
         DEBUG_INPT   yLOG_info    ("retn"      , r_retn);
      }
      break;
   }
   /*---(complete)--------------------*/
   DEBUG_INPT   yLOG_exit    (__FUNCTION__);
   return 0;
}

char
PARSE_current           (cchar a_scrp [LEN_TITLE], int a_line, cchar a_verb [LEN_LABEL], char a_spec, cchar a_recd [LEN_RECD], char r_desc [LEN_LONG], char r_meth [LEN_HUND], char r_args [LEN_FULL], char r_test [LEN_LABEL], char r_expe [LEN_RECD], char r_retn [LEN_FULL])
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
   /*---(default)---------------------*/
   PARSE__default  (r_desc, r_meth, r_args, r_test, r_expe, r_retn);
   /*---(defense)------------------------*/
   DEBUG_INPT   yLOG_point   ("a_recd"    , a_recd);
   --rce;  if (a_recd == NULL) {
      DEBUG_INPT   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   strlcpy (x_recd, a_recd, LEN_RECD);
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
   p = strtok_r (x_recd, q, &r);
   p = strtok_r (NULL  , q, &r);
   --rce;  if (p == NULL) {
      DEBUG_INPT   yLOG_note    ("only one field provided");
      DEBUG_INPT   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   /*---(walk-fields)--------------------*/
   for (i = 2; i < 20; ++i) {
      /*---(parse field)-----------------*/
      PARSE__field  (i, p, a_spec, &(x_max), x_desc, x_meth, x_args, x_test, x_expe, x_retn);
      if (i >= x_max)    break;
      /*---(next record)-----------------*/
      DEBUG_INPT   yLOG_note    ("read next field");
      p = strtok_r (NULL  , q, &r);
      --rce;  if (p == NULL) {
         DEBUG_INPT   yLOG_note    ("strtok came up empty");
         break;
      }
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
   /*---(complete)--------------------*/
   DEBUG_INPT   yLOG_exit    (__FUNCTION__);
   return 0;
}


