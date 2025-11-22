/*===============================[[ beg-code ]]===============================*/
#include    "koios.h"        /* LOCAL  : main header                          */

/*
 *  ZERO globals referenced in file
 */

/*
 *  PURPOSE : allows code to be written once and reused (REUSE) in several
 *  places, either globally (GLOBAL) or within a file (SHARED)
 *
 *  creates separate function and calls when needed
 *
 */
/*> f(a__FILE__, __FUNCTION__, __SLINE__, €ý5n                                     <*/



/*====================------------------------------------====================*/
/*===----                        script level                          ----===*/
/*====================------------------------------------====================*/
static void  o___PROGRAM_________o () { return; }

char REUSE_init              (void)  { yUNIT_reuse_purge ('*'); }
char REUSE_wrap              (void)  { yUNIT_reuse_purge ('*'); }



/*====================------------------------------------====================*/
/*===----                      getting and setting                     ----===*/
/*====================------------------------------------====================*/
static void  o___USAGE___________o () { return; }

char
REUSE__set_recd         (char a_abbr, char a_ftype, int a_line, char a_vers, char a_recd [LEN_RECD])
{
   /*---(locals)-------------------------*/
   char        rce         =  -10;
   char        rc          =    0;
   char       *p           = NULL;
   char       *r           = NULL;
   char        x_recd      [LEN_RECD]  = "";
   /*---(header)-------------------------*/
   UDEBUG_KOIOS   ylog_uenter  (__FUNCTION__);
   /*---(defense)------------------------*/
   UDEBUG_KOIOS   ylog_upoint  ("a_recd"    , a_recd);
   --rce;  if (a_recd == NULL || a_recd [0] == '\0') {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   strlcpy (x_recd, a_recd, LEN_RECD);
   /*---(parse verb, no action)----------*/
   p = strtok_r (x_recd, "", &r);
   UDEBUG_KOIOS   ylog_upoint  ("p"         , p);
   --rce;  if (p      == NULL) {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(parse description)--------------*/
   p = strtok_r (NULL  , "", &r);
   UDEBUG_KOIOS   ylog_upoint  ("p"         , p);
   --rce;  if (p      == NULL) {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(if, versioned, parse again)-----*/
   --rce; if (a_vers > 0) {
      p = strtok_r (NULL  , "", &r);
      UDEBUG_KOIOS   ylog_upoint  ("p"         , p);
      if (p      == NULL) {
         UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
         return rce;
      }
   }
   /*---(clean-up)-----------------------*/
   UDEBUG_KOIOS   ylog_uinfo   ("p"         , p);
   ystrutrim (p, LEN_LONG);
   /*---(set)----------------------------*/
   UDEBUG_KOIOS   ylog_uchar   ("a_ftype"   , a_ftype);
   rc = yUNIT_reuse_set (a_abbr, a_ftype, a_line, p);
   UDEBUG_KOIOS   ylog_uvalue  ("set"       , rc);
   --rce; if (rc < 0) {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   UDEBUG_KOIOS   ylog_unote   (yUNIT_reuse_show   (a_abbr));
   /*---(complete)-----------------------*/
   UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
   return rc;
}



/*====================------------------------------------====================*/
/*===----                    record parsing support                    ----===*/
/*====================------------------------------------====================*/
static void  o___PARSING_________o () { return; }

char
REUSE__parse_delimit    (char a_func [LEN_LABEL], char a_nscrp [LEN_TITLE], int a_line, char a_verb [LEN_LABEL], char a_prefix [LEN_RECD], char a_label [LEN_SHORT], char a_pos, char a_char, char a_example [LEN_SHORT])
{
   char        rce         =  -10;
   char        c           =  '?';
   char        x_label     [LEN_LABEL] = "";
   /*---(prepare)------------------------*/
   switch (a_pos) {
   case 0  :  c = a_label [0];  strcpy (x_label, "leading");   break;
   case 1  :  c = a_label [1];  strcpy (x_label, "middle");    break;
   case 2  :  c = a_label [1];  strcpy (x_label, "trailing");  break;
   default :  return rce;
   }
   /*---(check)--------------------------*/
   UDEBUG_KOIOS   ylog_uchar   (x_label     , c);
   if (c != a_char) {
      yerr_uerror ("%s:%d:0: error: verb å%sæ from prefix å%sæ with label å%sæ has %s (%c) instead of (%c), e.g., å%sæ", a_nscrp, a_line, a_verb, a_prefix, a_label, x_label, c, a_char, a_example);
      UDEBUG_KOIOS   ylog_uexitr  (a_func, rce);
      return rce;
   }
   /*---(complete)-----------------------*/
   return 0;
}

char
REUSE__parse_global     (char a_nscrp [LEN_TITLE], char a_ftype, int a_line, char a_verb [LEN_LABEL], char a_recd [LEN_LABEL], char a_prefix [LEN_RECD], char a_label [LEN_LABEL], char a_example [LEN_SHORT], char a_vers, char *r_major)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        x_label     =  '?';
   char        c           =  '?';
   int         n           =   -1;
   char        x_type      =  '?';
   /*---(header)-------------------------*/
   UDEBUG_KOIOS   ylog_uenter  (__FUNCTION__);
   /*---(quick-out)----------------------*/
   UDEBUG_KOIOS   ylog_uinfo   ("a_verb"    , a_verb);
   if (strcmp ("GLOBAL" , a_verb) == 0)  x_type = 'G';
   if (strcmp ("CONFIG" , a_verb) == 0)  x_type = 'F';
   if (x_type == '?') {
      UDEBUG_KOIOS   ylog_unote   ("not a GLOBAL/CONFIG");
      UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
      return 0;
   }
   UDEBUG_KOIOS   ylog_uchar   ("a_ftype"   , a_ftype);
   UDEBUG_KOIOS   ylog_uchar   ("x_type"    , x_type);
   /*---(check label)--------------------*/
   rc = REUSE__parse_delimit (__FUNCTION__, a_nscrp, a_line, a_verb, a_prefix, a_label, 0, '-', a_example);
   --rce;  if (rc < 0)  return rce;
   x_label = a_label [1];
   UDEBUG_KOIOS   ylog_uchar   ("x_label"   , x_label);
   --rce;  if (x_type == 'G' && strchr (YSTR_UPPER, x_label) == NULL) {
      UDEBUG_KOIOS   ylog_unote   ("GLOBAL identifier must be A-Z");
      yerr_uerror ("%s:%d:0: error: ¶%s¶ identifier ¶%c¶ not valid å%sæ", a_nscrp, a_line, a_prefix, x_label, YSTR_UPPER);
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   --rce;  if (x_type == 'F' && strchr (YSTR_GREEK, x_label) == NULL) {
      UDEBUG_KOIOS   ylog_unote   ("CONFIG identifier must be è-ÿ");
      yerr_uerror ("%s:%d:0: error: ¶%s¶ identifier ¶%c¶ not valid å%sæ", a_nscrp, a_line, a_prefix, x_label, YSTR_GREEK);
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   c = a_label [2];
   UDEBUG_KOIOS   ylog_uchar   ("pre 2"     , c);
   --rce;  if (c != '-') {
      yerr_uerror ("%s:%d:0: error: ¶%s¶ identifier ¶%c¶ does not end with dash (-), e.g., %s", a_nscrp, a_line, a_prefix, x_label, a_example);
      UDEBUG_KOIOS   ylog_unote   ("no close marker");
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(prepare)------------------------*/
   if (x_type == 'G')  n  = yUNIT_reuse_line (x_label);
   if (x_type == 'F')  n  = yUNIT_reuse_line (x_label);
   UDEBUG_KOIOS   ylog_uvalue  ("n"         , n);
   /*---(defense)------------------------*/
   --rce;  IF_LOCAL {
      UDEBUG_KOIOS   ylog_unote   ("GLOBAL/CONFIG only allowed in unit_head.unit, unit_wide.unit, or unit_data.unit");
      yerr_uerror ("%s:%d:0: error: åGLOBAL/CONFIGæ verbs not allowed outside unit_head.unit, unit_wide.unit, or unit_data.unit", a_nscrp, a_line);
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   --rce;  if (n >= 0) {
      UDEBUG_KOIOS   ylog_unote   ("already set");
      yerr_uerror ("%s:%d:0: error: ¶%s¶ identifier ¶%c¶ already in use", a_nscrp, a_line, a_prefix, x_label);
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(handle)-------------------------*/
   if (x_type == 'G')  rc = REUSE__set_recd (x_label, a_ftype, a_line, a_vers, a_recd);
   if (x_type == 'F')  rc = REUSE__set_recd (x_label, a_ftype, a_line, a_vers, a_recd);
   UDEBUG_KOIOS   ylog_uvalue  ("set"       , rc);
   if (r_major != NULL)  *r_major = x_label;
   /*---(complete)-----------------------*/
   UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
   return 1;
}

char
REUSE__parse_shared     (char a_nscrp [LEN_TITLE], char a_ftype, int a_line, char a_verb [LEN_LABEL], char a_recd [LEN_LABEL], char a_prefix [LEN_RECD], char a_label [LEN_LABEL], char a_example [LEN_SHORT], char a_vers, char *r_major)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        x_label     =  '?';
   char        c           =  '?';
   int         n           =   -1;
   /*---(header)-------------------------*/
   UDEBUG_KOIOS   ylog_uenter  (__FUNCTION__);
   /*---(quick-out)----------------------*/
   UDEBUG_KOIOS   ylog_uinfo   ("a_verb"    , a_verb);
   if (strcmp ("SHARED" , a_verb) != 0) {
      UDEBUG_KOIOS   ylog_unote   ("not a SHARED");
      UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
      return 0;
   }
   UDEBUG_KOIOS   ylog_uchar   ("a_ftype"   , a_ftype);
   /*---(check label)--------------------*/
   c = a_label [0];
   UDEBUG_KOIOS   ylog_uchar   ("pre 0"     , c);
   --rce;  if (c != '-') {
      yerr_uerror ("%s:%d:0: error: å%sæ missing valid identifier string, e.g., å%sæ", a_nscrp, a_line, a_prefix, a_example);
      UDEBUG_KOIOS   ylog_unote   ("no openning marker");
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   x_label = a_label [1];
   UDEBUG_KOIOS   ylog_uchar   ("x_label"   , x_label);
   --rce;  if (strchr (YSTR_LOWER, x_label) == NULL) {
      UDEBUG_KOIOS   ylog_unote   ("SHARED identifier must be A-Zè-ÿ");
      yerr_uerror ("%s:%d:0: error: å%sæ identifier (%c) not valid å%sæ", a_nscrp, a_line, a_prefix, x_label, YSTR_UPPER);
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   c = a_label [2];
   UDEBUG_KOIOS   ylog_uchar   ("pre 2"     , c);
   --rce;  if (c != '-') {
      yerr_uerror ("%s:%d:0: error: å%sæ identifier (%c) does not end with dash (-) , e.g., å%sæ", a_nscrp, a_line, a_prefix, x_label, a_example);
      UDEBUG_KOIOS   ylog_unote   ("no close marker");
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(prepare)------------------------*/
   n  = yUNIT_reuse_line (x_label);
   UDEBUG_KOIOS   ylog_uvalue  ("n"         , n);
   /*---(defense)------------------------*/
   --rce;  IF_GLOBAL {
      UDEBUG_KOIOS   ylog_unote   ("SHARED not allowed inside unit_head.unit, unit_wide.unit, or unit_data.unit");
      yerr_uerror ("%s:%d:0: error: åSHAREDæ verb not allowed inside unit_head.unit, unit_wide.unit, or unit_data.unit", a_nscrp, a_line);
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   --rce;  if (n >= 0) {
      UDEBUG_KOIOS   ylog_unote   ("already set");
      yerr_uerror ("%s:%d:0: error: å%sæ identifier (%c) already in use", a_nscrp, a_line, a_prefix, x_label);
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(handle)-------------------------*/
   rc = REUSE__set_recd (x_label, a_ftype, a_line, a_vers, a_recd);
   UDEBUG_KOIOS   ylog_uvalue  ("set"       , rc);
   if (r_major != NULL)  *r_major = x_label;
   /*---(complete)-----------------------*/
   UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
   return 1;
}

char
REUSE__parse_reuse_old  (char a_nscrp [LEN_TITLE], int a_line, char a_prefix [LEN_RECD], char a_label [LEN_LABEL], char *r_major, char *r_minor)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        x_label     =  '?';
   char        c           =  '?';
   /*---(header)-------------------------*/
   UDEBUG_KOIOS   ylog_uenter  (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_major != NULL)  *r_major = '-';
   if (r_minor != NULL)  *r_minor = '-';
   /*---(quick-out)----------------------*/
   UDEBUG_KOIOS   ylog_uinfo   ("a_label"   , a_label);
   c = a_label [0];
   if (c != '-') {
      UDEBUG_KOIOS   ylog_unote   ("not a old-style reuse");
      UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
      return 0;
   }
   /*---(check label)--------------------*/
   x_label = a_label [1];
   UDEBUG_KOIOS   ylog_uchar   ("x_label"   , x_label);
   --rce;  if (strchr (YSTR_LOWER YSTR_UPPER YSTR_GREEK, x_label) == NULL) {
      UDEBUG_KOIOS   ylog_unote   ("REUSE identifier must be A-Za-zè-ÿ");
      yerr_uerror ("%s:%d:0: error: ¶%s¶ identifier ¶%c¶ not valid å%sæ", a_nscrp, a_line, a_prefix, x_label, YSTR_UPPER YSTR_LOWER YSTR_GREEK);
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(check trailer)------------------*/
   c = a_label [2];
   UDEBUG_KOIOS   ylog_uchar   ("pre 2"     , c);
   --rce;  if (c != '-') {
      yerr_uerror ("%s:%d:0: error: ¶%s¶ identifier ¶%c¶ does not end with dash (-) , e.g., å-A-æ", a_nscrp, a_line, a_prefix, x_label);
      UDEBUG_KOIOS   ylog_unote   ("no close marker");
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(save-back)----------------------*/
   if (r_major != NULL)  *r_major = x_label;
   if (r_minor != NULL)  *r_minor = '*';
   /*---(complete)-----------------------*/
   UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
   return 1;
}

char
REUSE__parse_reuse_new  (char a_nscrp [LEN_TITLE], int a_line, char a_prefix [LEN_RECD], char a_label [LEN_LABEL], char *r_major, char *r_minor)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        x_major     =  '?';
   char        x_minor     =  '?';
   char        c           =  '?';
   /*---(header)-------------------------*/
   UDEBUG_KOIOS   ylog_uenter  (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_major != NULL)  *r_major = '-';
   if (r_minor != NULL)  *r_minor = '-';
   /*---(quick-out)----------------------*/
   UDEBUG_KOIOS   ylog_uinfo   ("a_label"   , a_label);
   c = a_label [1];
   if (c != '/') {
      UDEBUG_KOIOS   ylog_unote   ("not a new-style reuse");
      UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
      return 0;
   }
   /*---(check label)--------------------*/
   x_major = a_label [0];
   UDEBUG_KOIOS   ylog_uchar   ("x_major"   , x_major);
   --rce;  if (strchr (YSTR_LOWER YSTR_UPPER YSTR_GREEK, x_major) == NULL) {
      UDEBUG_KOIOS   ylog_unote   ("REUSE identifier must be A-Za-zè-ÿ");
      yerr_uerror ("%s:%d:0: error: ¶%s¶ identifier ¶%c¶ not valid å%sæ", a_nscrp, a_line, a_prefix, x_major, YSTR_UPPER YSTR_LOWER YSTR_GREEK);
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(check trailer)------------------*/
   x_minor = a_label [2];
   UDEBUG_KOIOS   ylog_uchar   ("pre 2"     , x_minor);
   --rce;  if (strchr ("*" YSTR_ALLCHAR, x_minor) == NULL) {
      yerr_uerror ("%s:%d:0: error: ¶%s¶ identifier ¶%c¶ does not end with å*a-zA-Z0-9è-ÿæ, e.g., åA/aæ", a_nscrp, a_line, a_prefix, x_minor);
      UDEBUG_KOIOS   ylog_unote   ("no close marker");
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(save-back)----------------------*/
   if (r_major != NULL)  *r_major = x_major;
   if (r_minor != NULL)  *r_minor = x_minor;
   /*---(complete)-----------------------*/
   UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
   return 1;
}

char
REUSE__parse_reuse      (char a_nscrp [LEN_TITLE], char a_ftype, int a_line, char a_verb [LEN_LABEL], char a_recd [LEN_LABEL], char a_prefix [LEN_RECD], char a_label [LEN_LABEL], char a_share, char r_desc [LEN_LONG], char *r_major, char *r_minor)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        x_major     =  '-';
   char        x_minor     =  '-';
   char        c           =  '?';
   int         n           =   -1;
   char        x_tdesc     [LEN_TERSE] = "";
   char        x_desc      [LEN_LONG]  = "";
   int         l           =    0;
   /*---(header)-------------------------*/
   UDEBUG_KOIOS   ylog_uenter  (__FUNCTION__);
   /*---(quick-out)----------------------*/
   UDEBUG_KOIOS   ylog_upoint  ("a_verb"    , a_verb);
   if (a_verb == NULL || strcmp ("REUSE"  , a_verb) != 0) {
      UDEBUG_KOIOS   ylog_unote   ("not a REUSE");
      UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
      return 0;
   }
   /*---(default)------------------------*/
   if (r_desc  != NULL)  strcpy (r_desc, "");
   if (r_major != NULL)  *r_major = '-';
   if (r_minor != NULL)  *r_minor = '-';
   /*---(defense)------------------------*/
   --rce;  IF_GLOBAL {
      UDEBUG_KOIOS   ylog_unote   ("REUSE not allowed inside unit_head.unit, unit_wide.unit, or unit_data.unit");
      yerr_uerror ("%s:%d:0: error: åREUSEæ verb not allowed inside unit_head.unit, unit_wide.unit, or unit_data.unit", a_nscrp, a_line);
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   l = strlen (a_label);
   --rce;  if (l != 3) {
      UDEBUG_KOIOS   ylog_unote   ("REUSE label is not three characters");
      yerr_uerror ("%s:%d:0: error: ¶%s¶ label is %då%sæ chars, not 3", a_nscrp, a_line, a_prefix, l, a_label);
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(quick-out)----------------------*/
   rc = REUSE__parse_reuse_old (a_nscrp, a_line, a_prefix, a_label, &x_major, &x_minor);
   --rce;  if (rc < 0) {
      yerr_uerror ("%s:%d:0: error: ¶%s¶ failed on old-style reuse label å-A-æ", a_nscrp, a_line, a_prefix);
      UDEBUG_KOIOS   ylog_unote   ("not a valid REUSE label");
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   --rce;  if (rc == 0) {
      rc = REUSE__parse_reuse_new (a_nscrp, a_line, a_prefix, a_label, &x_major, &x_minor);
      if (rc <= 0) {
         yerr_uerror ("%s:%d:0: error: ¶%s¶ failed on new-style reuse label åA/aæ", a_nscrp, a_line, a_prefix);
         UDEBUG_KOIOS   ylog_unote   ("not a valid REUSE label");
         UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
         return rce;
      }
   }
   /*---(global)-------------------------*/
   --rce;  if (strchr (YSTR_UPPER, x_major) != NULL) {
      n  = yUNIT_reuse_desc (x_major, x_tdesc, x_desc);
      UDEBUG_KOIOS   ylog_uvalue  ("n"         , n);
      if (n < 0) {
         UDEBUG_KOIOS   ylog_unote   ("not set");
         yerr_uerror ("%s:%d:0: error: ¶%s¶ verb identifier ¶%c¶ never set by GLOBAL", a_nscrp, a_line, a_prefix, x_major);
         UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
         return rce;
      }
   }
   /*---(config)-------------------------*/
   else if (strchr (YSTR_GREEK, x_major) != NULL) {
      n  = yUNIT_reuse_desc (x_major, x_tdesc, x_desc);
      UDEBUG_KOIOS   ylog_uvalue  ("n"         , n);
      if (n < 0) {
         UDEBUG_KOIOS   ylog_unote   ("not set");
         yerr_uerror ("%s:%d:0: error: ¶%s¶ verb identifier ¶%c¶ never set by CONFIG", a_nscrp, a_line, a_prefix, x_major);
         UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
         return rce;
      }
   }
   /*---(shared)-------------------------*/
   else if (strchr (YSTR_LOWER, x_major) != NULL) {
      n  = yUNIT_reuse_desc (x_major, x_tdesc, x_desc);
      UDEBUG_KOIOS   ylog_uvalue  ("n"         , n);
      if (n < 0) {
         UDEBUG_KOIOS   ylog_unote   ("not set");
         yerr_uerror ("%s:%d:0: error: ¶%s¶ verb identifier ¶%c¶ never set by SHARED", a_nscrp, a_line, a_prefix, x_major);
         UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
         return rce;
      }
   }
   /*---(nobody)-------------------------*/
   else {
      UDEBUG_KOIOS   ylog_unote   ("not set");
      yerr_uerror ("%s:%d:0: error: ¶%s¶ verb identifier ¶%c¶ not valid [a-zA-Z]", a_nscrp, a_line, a_prefix, x_major);
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(check recursion)----------------*/
   if (x_major == a_share) {
      UDEBUG_KOIOS   ylog_unote   ("reuse is recursive");
      yerr_uerror ("%s:%d:0: error: ¶%s¶ verb identifier ¶%c¶ called inside itself, recursive", a_nscrp, a_line, a_prefix, x_major);
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(save-back)----------------------*/
   if (r_desc  != NULL)  DITTO_parse__desc (x_desc, r_desc);  /* nice stand-out formatting */
   if (r_major != NULL)  *r_major = x_major;
   if (r_minor != NULL)  *r_minor = x_minor;
   /*---(complete)-----------------------*/
   UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
   return 1;
}

char
REUSE_parse             (char a_nscrp [LEN_TITLE], int a_line, char a_verb [LEN_LABEL], char a_vers, char a_recd [LEN_RECD], char a_share, char r_desc [LEN_LONG], char *r_major, char *r_minor)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        x_ftype     =  '·';
   char        x_prefix    [LEN_RECD]  = "";
   char       *p           = NULL;
   char        m           =  '-';
   int         o           =   -1;
   int         c           =   -1;
   char        x_check     =   -1;
   char        x_label     [LEN_LABEL] = "";
   char        x_desc      [LEN_LONG]  = "";
   char        x_ex        [LEN_SHORT] = "-A-";
   int         l           =    0;
   /*---(header)-------------------------*/
   UDEBUG_KOIOS   ylog_uenter  (__FUNCTION__);
   /*---(existing)-----------------------*/
   UDEBUG_KOIOS ylog_uinfo    ("used"      , yUNIT_reuse_used ());
   /*---(default)------------------------*/
   if (r_desc  != NULL)  strcpy (r_desc, "");
   if (r_major != NULL)  *r_major = '-';
   if (r_minor != NULL)  *r_minor = '-';
   /*---(defense)------------------------*/
   UDEBUG_KOIOS   ylog_upoint  ("a_nscrp"   , a_nscrp);
   --rce;  if (a_nscrp     == NULL) {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   UDEBUG_KOIOS   ylog_upoint  ("a_verb"    , a_verb);
   --rce;  if (a_verb     == NULL) {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   UDEBUG_KOIOS   ylog_upoint  ("a_recd"    , a_recd);
   --rce;  if (a_recd     == NULL) {
      yerr_uerror ("%s:%d:0: error: GLOBAL/SHARED/REUSE called with a null string", a_nscrp, a_line);
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(check file)---------------------*/
   if      (strcmp (a_nscrp, "unit_head.unit") == 0)  x_ftype = 'h';
   else if (strcmp (a_nscrp, "unit_wide.unit") == 0)  x_ftype = 'w';
   else if (strcmp (a_nscrp, "unit_data.unit") == 0)  x_ftype = 'd';
   else                                               x_ftype = '-';
   UDEBUG_KOIOS   ylog_uchar   ("x_ftype"   , x_ftype);
   /*---(check for right verbs)----------*/
   UDEBUG_KOIOS   ylog_unote   ("check examples");
   if      (strcmp (a_verb, "GLOBAL") == 0)  strcpy (x_ex, "-A-");
   else if (strcmp (a_verb, "SHARED") == 0)  strcpy (x_ex, "-a-");
   else if (strcmp (a_verb, "CONFIG") == 0)  strcpy (x_ex, "-ò-");
   else if (strcmp (a_verb, "REUSE" ) == 0)  strcpy (x_ex, "A/a");
   else {
      UDEBUG_KOIOS   ylog_unote   ("this only applies to GLOBAL/SHARED/CONFIG/REUSE");
      UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
      return 0;
   }
   UDEBUG_KOIOS   ylog_uinfo   ("x_ex"      , x_ex);
   /*---(check for marker)---------------*/
   strlcpy (x_prefix, a_recd, LEN_RECD);
   UDEBUG_KOIOS   ylog_uinfo   ("x_prefix"  , x_prefix);
   p = strchr (x_prefix, '');
   UDEBUG_KOIOS   ylog_upoint  ("p"         , p);
   --rce;  if (p == NULL) {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   p [0] = '\0';
   ystrutrim (x_prefix, LEN_LABEL);
   UDEBUG_KOIOS   ylog_uinfo   ("x_prefix"  , x_prefix);
   l = strlen (x_prefix);
   strlcpy (x_label, x_prefix + l - 3, LEN_LABEL);
   /*---(handle global)------------------*/
   rc = REUSE__parse_global (a_nscrp, x_ftype, a_line, a_verb, a_recd, x_prefix, x_label, x_ex, a_vers, r_major);
   UDEBUG_KOIOS   ylog_uvalue  ("global"    , rc);
   --rce;  if (rc < 0) {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(handle shared)------------------*/
   --rce;  if (rc == 0) {
      rc = REUSE__parse_shared (a_nscrp, x_ftype, a_line, a_verb, a_recd, x_prefix, x_label, x_ex, a_vers, r_major);
      UDEBUG_KOIOS   ylog_uvalue  ("shared"    , rc);
      if (rc < 0) {
         UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
         return rce;
      }
   }
   /*---(handle reuses)------------------*/
   --rce;  if (rc == 0) {
      rc = REUSE__parse_reuse  (a_nscrp, x_ftype, a_line, a_verb, a_recd, x_prefix, x_label, a_share, r_desc, r_major, r_minor);
      UDEBUG_KOIOS   ylog_uvalue  ("reuse"     , rc);
      if (rc < 0) {
         UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
         return rce;
      }
   }
   /*---(existing)-----------------------*/
   UDEBUG_KOIOS ylog_uinfo    ("used"      , yUNIT_reuse_used ());
   /*---(complete)-----------------------*/
   UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
   return rc;
}



/*====================------------------------------------====================*/
/*===----                        export/import                         ----===*/
/*====================------------------------------------====================*/
static void  o___EXIM____________o () { return; }




/*====================------------------------------------====================*/
/*===----                        debugging support                     ----===*/
/*====================------------------------------------====================*/
static void  o___DEBUGGING_______o () { return; }

char
REUSE_totals         (char a_verb [LEN_LABEL], char a_recd [LEN_RECD])
{
   char        rce         =  -10;
   char        rc          =    0;
   char        x_good      =  '-';
   /*---(defense)------------------------*/
   --rce;  if (a_verb == NULL)  return rce;
   --rce;  if (a_recd == NULL)  return rce;
   /*---(quick-out)----------------------*/
   if      (strcmp (a_verb, "DERAHS") == 0)  x_good = 'y';
   else if (strcmp (a_verb, "LABOLG") == 0)  x_good = 'y';
   else if (strcmp (a_verb, "GIFNOC") == 0)  x_good = 'y';
   if (x_good != 'y')  return 0;
   /*---(parse)--------------------------*/
   rc = yUNIT_reuse_parse ('u', a_recd);
   /*---(complete)-----------------------*/
   return 1;
}




