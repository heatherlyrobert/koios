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



static char      *x_marks     = YSTR_UPPER YSTR_LOWER YSTR_GREEK;
#define   MAX_MARKS   76
typedef struct cMARKS tMARKS;
struct cMARKS {
   char        m_abbr;
   char        m_type;
   int         m_line;
   char        m_desc    [LEN_LONG];
   short       m_conds;
   short       m_steps;
   char        m_called;
};
static tMARKS  s_marks   [MAX_MARKS];



/*====================------------------------------------====================*/
/*===----                        script level                          ----===*/
/*====================------------------------------------====================*/
static void  o___PROGRAM_________o () { return; }

/*> char                                                                              <* 
 *> REUSE__type             (char a_abbr)                                             <* 
 *> {                                                                                 <* 
 *>    if      (a_abbr == 0)                          return '-';                     <* 
 *>    else if (strchr (YSTR_UPPER, a_abbr) != NULL)  return T_MASTER;                <* 
 *>    else if (strchr (YSTR_LOWER, a_abbr) != NULL)  return T_SHARES;                <* 
 *>    else if (strchr (YSTR_GREEK, a_abbr) != NULL)  return T_CONFIG;                <* 
 *>    return '-';                                                                    <* 
 *> }                                                                                 <*/

/*> int                                                                               <* 
 *> REUSE__index            (char a_abbr)                                             <* 
 *> {                                                                                 <* 
 *>    int         i           =    0;                                                <* 
 *>    for (i = 0; i < MAX_MARKS; ++i) {                                              <* 
 *>       if (s_marks [i].m_abbr == a_abbr)  return i;                                <* 
 *>    }                                                                              <* 
 *>    /+---(trouble)------------------------+/                                       <* 
 *>    return -1;                                                                     <* 
 *> }                                                                                 <*/

/*> char                                                                                                                                                                 <* 
 *> REUSE__data             (char a_abbr, char *r_type, char r_tdesc [LEN_TERSE], int *r_line, char r_desc [LEN_LONG], short *r_conds, short *r_steps, char *r_called)   <* 
 *> {                                                                                                                                                                    <* 
 *>    char        rce         =  -10;                                                                                                                                   <* 
 *>    int         n           =    0;                                                                                                                                   <* 
 *>    if (r_type  != NULL)  *r_type   = '-';                                                                                                                            <* 
 *>    if (r_line  != NULL)  *r_line   =  -1;                                                                                                                            <* 
 *>    if (r_tdesc != NULL)  strcpy (r_tdesc, "");                                                                                                                       <* 
 *>    if (r_desc  != NULL)  strcpy (r_desc , "");                                                                                                                       <* 
 *>    if (r_conds != NULL)  *r_conds  =  -1;                                                                                                                            <* 
 *>    if (r_steps != NULL)  *r_steps  =  -1;                                                                                                                            <* 
 *>    n = REUSE__index (a_abbr);                                                                                                                                        <* 
 *>    --rce;  if (n < 0)  return rce;                                                                                                                                   <* 
 *>    if (r_type  != NULL)  *r_type   = s_marks [n].m_type;                                                                                                             <* 
 *>    if (r_tdesc != NULL) {                                                                                                                                            <* 
 *>       switch (s_marks [n].m_type) {                                                                                                                                  <* 
 *>       case T_MASTER : strlcpy (r_tdesc, "GLOBAL" , LEN_TERSE);  break;                                                                                               <* 
 *>       case T_SHARES : strlcpy (r_tdesc, "SHARED" , LEN_TERSE);  break;                                                                                               <* 
 *>       case T_CONFIG : strlcpy (r_tdesc, "CONFIG" , LEN_TERSE);  break;                                                                                               <* 
 *>       default       : strlcpy (r_tdesc, "(error)", LEN_TERSE);  break;                                                                                               <* 
 *>       }                                                                                                                                                              <* 
 *>    }                                                                                                                                                                 <* 
 *>    if (r_line  != NULL)  *r_line   = s_marks [n].m_line;                                                                                                             <* 
 *>    if (r_desc  != NULL)  strlcpy (r_desc, s_marks [n].m_desc, LEN_LONG);                                                                                             <* 
 *>    if (r_conds != NULL)  *r_conds  = s_marks [n].m_conds;                                                                                                            <* 
 *>    if (r_steps != NULL)  *r_steps  = s_marks [n].m_steps;                                                                                                            <* 
 *>    return 1;                                                                                                                                                         <* 
 *> }                                                                                                                                                                    <*/

/*> char                                                                                        <* 
 *> REUSE_purge             (void)                                                              <* 
 *> {                                                                                           <* 
 *>    yUNIT_reuse_purge ('*');                                                                 <* 
 *>    /+> /+---(locals)-------------------------+/                                       <*    <* 
 *>     *> int         i           =    0;                                                <*    <* 
 *>     *> /+---(set defaults)-------------------+/                                       <*    <* 
 *>     *> for (i = 0; i < MAX_MARKS; ++i) {                                              <*    <* 
 *>     *>    s_marks [i].m_abbr   = x_marks [i];                                         <*    <* 
 *>     *>    s_marks [i].m_type   = REUSE__type (s_marks [i].m_abbr);                    <*    <* 
 *>     *>    s_marks [i].m_line   = -1;                                                  <*    <* 
 *>     *>    strcpy (s_marks [i].m_desc, "");                                            <*    <* 
 *>     *>    s_marks [i].m_conds  =  0;                                                  <*    <* 
 *>     *>    s_marks [i].m_steps  =  0;                                                  <*    <* 
 *>     *>    s_marks [i].m_called =  0;                                                  <*    <* 
 *>     *> }                                                                              <*    <* 
 *>     *> /+---(complete)-----------------------+/                                       <+/   <* 
 *>    return 0;                                                                                <* 
 *> }                                                                                           <*/

char REUSE_init              (void)  { yUNIT_reuse_purge ('*'); }
char REUSE_wrap              (void)  { yUNIT_reuse_purge ('*'); }



/*====================------------------------------------====================*/
/*===----                      getting and setting                     ----===*/
/*====================------------------------------------====================*/
static void  o___USAGE___________o () { return; }

/*> char                                                                              <* 
 *> REUSE__set              (char a_abbr, int a_line, char a_desc [LEN_LONG])         <* 
 *> {                                                                                 <* 
 *>    /+---(locals)-------------------------+/                                       <* 
 *>    char        n           =   -1;                                                <* 
 *>    /+---(get index)----------------------+/                                       <* 
 *>    n = REUSE__index (a_abbr);                                                     <* 
 *>    if (n < 0) return n;                                                           <* 
 *>    /+---(update list)--------------------+/                                       <* 
 *>    s_marks [n].m_line = a_line;                                                   <* 
 *>    if (a_desc != NULL)  strlcpy (s_marks [n].m_desc, a_desc, LEN_LONG);           <* 
 *>    else                 strcpy  (s_marks [n].m_desc, "");                         <* 
 *>    /+---(default counts)-----------------+/                                       <* 
 *>    s_marks [n].m_conds =  0;                                                      <* 
 *>    s_marks [n].m_steps =  0;                                                      <* 
 *>    /+---(complete)-----------------------+/                                       <* 
 *>    return 1;                                                                      <* 
 *> }                                                                                 <*/

char
REUSE__set_recd         (char a_abbr, int a_line, char a_vers, char a_recd [LEN_RECD])
{
   /*---(locals)-------------------------*/
   char        rce         =  -10;
   char       *p           = NULL;
   char       *r           = NULL;
   char        x_recd      [LEN_RECD]  = "";
   /*---(defense)------------------------*/
   --rce;  if (a_recd == NULL)                     return rce;
   strlcpy (x_recd, a_recd, LEN_RECD);
   /*---(parse desc)---------------------*/
   p = strtok_r (x_recd, "", &r);
   --rce;  if (p      == NULL)                     return rce;
   p = strtok_r (NULL  , "", &r);
   --rce;  if (p      == NULL)                     return rce;
   --rce; if (a_vers > 0) {
      p = strtok_r (NULL  , "", &r);
      if (p      == NULL)                     return rce;
   }
   ystrutrim (p, LEN_LONG);
   /*---(complete)-----------------------*/
   return yUNIT_reuse_set (a_abbr, a_line, p);
}

/*> int                                                                                             <* 
 *> REUSE__get              (char a_abbr, char r_desc [LEN_LONG], short *r_conds, short *r_steps)   <* 
 *> {                                                                                               <* 
 *>    int         x_line      =   -1;                                                              <* 
 *>    yUNIT_reuse_data (a_abbr, NULL, NULL, &x_line, r_desc, r_conds, r_steps, NULL);              <* 
 *>    return x_line;                                                                               <* 
 *> }                                                                                               <*/

/*> int                                                                               <* 
 *> REUSE__get_line         (char a_abbr)                                             <* 
 *> {                                                                                 <* 
 *>    int         x_line      =   -1;                                                <* 
 *>    yUNIT_reuse_data (a_abbr, NULL, NULL, &x_line, NULL, NULL, NULL, NULL);        <* 
 *>    return x_line;                                                                 <* 
 *> }                                                                                 <*/

/*> int                                                                                       <* 
 *> REUSE__get_desc         (char a_abbr, char r_tdesc [LEN_TERSE], char r_desc [LEN_LONG])   <* 
 *> {                                                                                         <* 
 *>    int         x_line      =   -1;                                                        <* 
 *>    yUNIT_reuse_data (a_abbr, NULL, r_tdesc, &x_line, r_desc, NULL, NULL, NULL);           <* 
 *>    return x_line;                                                                         <* 
 *> }                                                                                         <*/

/*> char                                                                              <* 
 *> REUSE_called            (char a_abbr)                                             <* 
 *> {                                                                                 <* 
 *>    /+---(locals)-------------------------+/                                       <* 
 *>    char        n           =   -1;                                                <* 
 *>    /+---(get index)----------------------+/                                       <* 
 *>    n = REUSE__index (a_abbr);                                                     <* 
 *>    if (n < 0) return n;                                                           <* 
 *>    /+---(update list)--------------------+/                                       <* 
 *>    ++(s_marks [n].m_called);                                                      <* 
 *>    /+---(complete)-----------------------+/                                       <* 
 *>    return 1;                                                                      <* 
 *> }                                                                                 <*/



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
   debug_uver   ylog_uchar   (x_label     , c);
   if (c != a_char) {
      yerr_uerror ("%s:%d:0: error: verb å%sæ from prefix å%sæ with label å%sæ has %s (%c) instead of (%c), e.g., å%sæ", a_nscrp, a_line, a_verb, a_prefix, a_label, x_label, c, a_char, a_example);
      debug_uver   ylog_uexitr  (a_func, rce);
      return rce;
   }
   /*---(complete)-----------------------*/
   return 0;
}

char
REUSE__parse_global     (char a_nscrp [LEN_TITLE], int a_line, char a_verb [LEN_LABEL], char a_recd [LEN_LABEL], char a_prefix [LEN_RECD], char a_label [LEN_LABEL], char a_example [LEN_SHORT], char a_vers, char *r_major)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        x_label     =  '?';
   char        c           =  '?';
   int         n           =   -1;
   char        x_type      =  '?';
   /*---(header)-------------------------*/
   debug_uver   ylog_uenter  (__FUNCTION__);
   /*---(quick-out)----------------------*/
   debug_uver   ylog_uinfo   ("a_verb"    , a_verb);
   if (strcmp ("GLOBAL" , a_verb) == 0)  x_type = 'G';
   if (strcmp ("CONFIG" , a_verb) == 0)  x_type = 'F';
   if (x_type == '?') {
      debug_uver   ylog_unote   ("not a GLOBAL/CONFIG");
      debug_uver   ylog_uexit   (__FUNCTION__);
      return 0;
   }
   debug_uver   ylog_uchar   ("x_type"    , x_type);
   /*---(check label)--------------------*/
   rc = REUSE__parse_delimit (__FUNCTION__, a_nscrp, a_line, a_verb, a_prefix, a_label, 0, '-', a_example);
   --rce;  if (rc < 0)  return rce;
   /*> debug_uver   ylog_uchar   ("pre 0"     , c);                                   <*/
   /*> --rce;  if (c != '-') {                                                                                                  <* 
    *>    yerr_uerror ("%s:%d:0: error: ¶%s¶ missing valid identifier string, e.g., %s", a_nscrp, a_line, a_prefix, a_example);   <* 
    *>    debug_uver   ylog_unote   ("no openning marker");                                                                     <* 
    *>    debug_uver   ylog_uexitr  (__FUNCTION__, rce);                                                                        <* 
    *>    return rce;                                                                                                           <* 
    *> }                                                                                                                        <*/
   x_label = a_label [1];
   debug_uver   ylog_uchar   ("x_label"   , x_label);
   --rce;  if (x_type == 'G' && strchr (YSTR_UPPER, x_label) == NULL) {
      debug_uver   ylog_unote   ("GLOBAL identifier must be A-Z");
      yerr_uerror ("%s:%d:0: error: ¶%s¶ identifier ¶%c¶ not valid å%sæ", a_nscrp, a_line, a_prefix, x_label, YSTR_UPPER);
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   --rce;  if (x_type == 'F' && strchr (YSTR_GREEK, x_label) == NULL) {
      debug_uver   ylog_unote   ("CONFIG identifier must be è-ÿ");
      yerr_uerror ("%s:%d:0: error: ¶%s¶ identifier ¶%c¶ not valid å%sæ", a_nscrp, a_line, a_prefix, x_label, YSTR_GREEK);
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   c = a_label [2];
   debug_uver   ylog_uchar   ("pre 2"     , c);
   --rce;  if (c != '-') {
      yerr_uerror ("%s:%d:0: error: ¶%s¶ identifier ¶%c¶ does not end with dash (-), e.g., %s", a_nscrp, a_line, a_prefix, x_label, a_example);
      debug_uver   ylog_unote   ("no close marker");
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(prepare)------------------------*/
   if (x_type == 'G')  n  = yUNIT_reuse_line (x_label);
   if (x_type == 'F')  n  = yUNIT_reuse_line (x_label);
   debug_uver   ylog_uvalue  ("n"         , n);
   /*---(defense)------------------------*/
   --rce;  IF_LOCAL {
      debug_uver   ylog_unote   ("GLOBAL/CONFIG only allowed in unit_head.unit, unit_comp.unit, or unit_data.unit");
      yerr_uerror ("%s:%d:0: error: åGLOBAL/CONFIGæ verbs not allowed outside unit_head.unit, unit_comp.unit, or unit_data.unit", a_nscrp, a_line);
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   --rce;  if (n >= 0) {
      debug_uver   ylog_unote   ("already set");
      yerr_uerror ("%s:%d:0: error: ¶%s¶ identifier ¶%c¶ already in use", a_nscrp, a_line, a_prefix, x_label);
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(handle)-------------------------*/
   if (x_type == 'G')  rc = REUSE__set_recd (x_label, a_line, a_vers, a_recd);
   if (x_type == 'F')  rc = REUSE__set_recd (x_label, a_line, a_vers, a_recd);
   debug_uver   ylog_uvalue  ("set"       , rc);
   if (r_major != NULL)  *r_major = x_label;
   /*---(complete)-----------------------*/
   debug_uver   ylog_uexit   (__FUNCTION__);
   return 1;
}

char
REUSE__parse_shared     (char a_nscrp [LEN_TITLE], int a_line, char a_verb [LEN_LABEL], char a_recd [LEN_LABEL], char a_prefix [LEN_RECD], char a_label [LEN_LABEL], char a_example [LEN_SHORT], char a_vers, char *r_major)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        x_label     =  '?';
   char        c           =  '?';
   int         n           =   -1;
   /*---(header)-------------------------*/
   debug_uver   ylog_uenter  (__FUNCTION__);
   /*---(quick-out)----------------------*/
   debug_uver   ylog_uinfo   ("a_verb"    , a_verb);
   if (strcmp ("SHARED" , a_verb) != 0) {
      debug_uver   ylog_unote   ("not a SHARED");
      debug_uver   ylog_uexit   (__FUNCTION__);
      return 0;
   }
   /*---(check label)--------------------*/
   c = a_label [0];
   debug_uver   ylog_uchar   ("pre 0"     , c);
   --rce;  if (c != '-') {
      yerr_uerror ("%s:%d:0: error: å%sæ missing valid identifier string, e.g., å%sæ", a_nscrp, a_line, a_prefix, a_example);
      debug_uver   ylog_unote   ("no openning marker");
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   x_label = a_label [1];
   debug_uver   ylog_uchar   ("x_label"   , x_label);
   --rce;  if (strchr (YSTR_LOWER, x_label) == NULL) {
      debug_uver   ylog_unote   ("SHARED identifier must be A-Zè-ÿ");
      yerr_uerror ("%s:%d:0: error: å%sæ identifier (%c) not valid å%sæ", a_nscrp, a_line, a_prefix, x_label, YSTR_UPPER);
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   c = a_label [2];
   debug_uver   ylog_uchar   ("pre 2"     , c);
   --rce;  if (c != '-') {
      yerr_uerror ("%s:%d:0: error: å%sæ identifier (%c) does not end with dash (-) , e.g., å%sæ", a_nscrp, a_line, a_prefix, x_label, a_example);
      debug_uver   ylog_unote   ("no close marker");
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(prepare)------------------------*/
   n  = yUNIT_reuse_line (x_label);
   debug_uver   ylog_uvalue  ("n"         , n);
   /*---(defense)------------------------*/
   --rce;  IF_GLOBAL {
      debug_uver   ylog_unote   ("SHARED not allowed inside unit_head.unit, unit_comp.unit, or unit_data.unit");
      yerr_uerror ("%s:%d:0: error: åSHAREDæ verb not allowed inside unit_head.unit, unit_comp.unit, or unit_data.unit", a_nscrp, a_line);
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   --rce;  if (n >= 0) {
      debug_uver   ylog_unote   ("already set");
      yerr_uerror ("%s:%d:0: error: å%sæ identifier (%c) already in use", a_nscrp, a_line, a_prefix, x_label);
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(handle)-------------------------*/
   rc = REUSE__set_recd (x_label, a_line, a_vers, a_recd);
   debug_uver   ylog_uvalue  ("set"       , rc);
   if (r_major != NULL)  *r_major = x_label;
   /*---(complete)-----------------------*/
   debug_uver   ylog_uexit   (__FUNCTION__);
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
   debug_uver   ylog_uenter  (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_major != NULL)  *r_major = '-';
   if (r_minor != NULL)  *r_minor = '-';
   /*---(quick-out)----------------------*/
   debug_uver   ylog_uinfo   ("a_label"   , a_label);
   c = a_label [0];
   if (c != '-') {
      debug_uver   ylog_unote   ("not a old-style reuse");
      debug_uver   ylog_uexit   (__FUNCTION__);
      return 0;
   }
   /*---(check label)--------------------*/
   x_label = a_label [1];
   debug_uver   ylog_uchar   ("x_label"   , x_label);
   --rce;  if (strchr (YSTR_LOWER YSTR_UPPER YSTR_GREEK, x_label) == NULL) {
      debug_uver   ylog_unote   ("REUSE identifier must be A-Za-zè-ÿ");
      yerr_uerror ("%s:%d:0: error: ¶%s¶ identifier ¶%c¶ not valid å%sæ", a_nscrp, a_line, a_prefix, x_label, YSTR_UPPER YSTR_LOWER YSTR_GREEK);
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(check trailer)------------------*/
   c = a_label [2];
   debug_uver   ylog_uchar   ("pre 2"     , c);
   --rce;  if (c != '-') {
      yerr_uerror ("%s:%d:0: error: ¶%s¶ identifier ¶%c¶ does not end with dash (-) , e.g., å-A-æ", a_nscrp, a_line, a_prefix, x_label);
      debug_uver   ylog_unote   ("no close marker");
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(save-back)----------------------*/
   if (r_major != NULL)  *r_major = x_label;
   if (r_minor != NULL)  *r_minor = '*';
   /*---(complete)-----------------------*/
   debug_uver   ylog_uexit   (__FUNCTION__);
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
   debug_uver   ylog_uenter  (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_major != NULL)  *r_major = '-';
   if (r_minor != NULL)  *r_minor = '-';
   /*---(quick-out)----------------------*/
   debug_uver   ylog_uinfo   ("a_label"   , a_label);
   c = a_label [1];
   if (c != '/') {
      debug_uver   ylog_unote   ("not a new-style reuse");
      debug_uver   ylog_uexit   (__FUNCTION__);
      return 0;
   }
   /*---(check label)--------------------*/
   x_major = a_label [0];
   debug_uver   ylog_uchar   ("x_major"   , x_major);
   --rce;  if (strchr (YSTR_LOWER YSTR_UPPER YSTR_GREEK, x_major) == NULL) {
      debug_uver   ylog_unote   ("REUSE identifier must be A-Za-zè-ÿ");
      yerr_uerror ("%s:%d:0: error: ¶%s¶ identifier ¶%c¶ not valid å%sæ", a_nscrp, a_line, a_prefix, x_major, YSTR_UPPER YSTR_LOWER YSTR_GREEK);
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(check trailer)------------------*/
   x_minor = a_label [2];
   debug_uver   ylog_uchar   ("pre 2"     , x_minor);
   --rce;  if (strchr ("*" YSTR_ALLCHAR, x_minor) == NULL) {
      yerr_uerror ("%s:%d:0: error: ¶%s¶ identifier ¶%c¶ does not end with å*a-zA-Z0-9è-ÿæ, e.g., åA/aæ", a_nscrp, a_line, a_prefix, x_minor);
      debug_uver   ylog_unote   ("no close marker");
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(save-back)----------------------*/
   if (r_major != NULL)  *r_major = x_major;
   if (r_minor != NULL)  *r_minor = x_minor;
   /*---(complete)-----------------------*/
   debug_uver   ylog_uexit   (__FUNCTION__);
   return 1;
}

char
REUSE__parse_reuse      (char a_nscrp [LEN_TITLE], int a_line, char a_verb [LEN_LABEL], char a_recd [LEN_LABEL], char a_prefix [LEN_RECD], char a_label [LEN_LABEL], char a_share, char r_desc [LEN_LONG], char *r_major, char *r_minor)
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
   debug_uver   ylog_uenter  (__FUNCTION__);
   /*---(quick-out)----------------------*/
   debug_uver   ylog_upoint  ("a_verb"    , a_verb);
   if (a_verb == NULL || strcmp ("REUSE"  , a_verb) != 0) {
      debug_uver   ylog_unote   ("not a REUSE");
      debug_uver   ylog_uexit   (__FUNCTION__);
      return 0;
   }
   /*---(default)------------------------*/
   if (r_desc  != NULL)  strcpy (r_desc, "");
   if (r_major != NULL)  *r_major = '-';
   if (r_minor != NULL)  *r_minor = '-';
   /*---(defense)------------------------*/
   --rce;  IF_GLOBAL {
      debug_uver   ylog_unote   ("REUSE not allowed inside unit_head.unit, unit_comp.unit, or unit_data.unit");
      yerr_uerror ("%s:%d:0: error: åREUSEæ verb not allowed inside unit_head.unit, unit_comp.unit, or unit_data.unit", a_nscrp, a_line);
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   l = strlen (a_label);
   --rce;  if (l != 3) {
      debug_uver   ylog_unote   ("REUSE label is not three characters");
      yerr_uerror ("%s:%d:0: error: ¶%s¶ label is %då%sæ chars, not 3", a_nscrp, a_line, a_prefix, l, a_label);
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(quick-out)----------------------*/
   rc = REUSE__parse_reuse_old (a_nscrp, a_line, a_prefix, a_label, &x_major, &x_minor);
   --rce;  if (rc < 0) {
      yerr_uerror ("%s:%d:0: error: ¶%s¶ failed on old-style reuse label å-A-æ", a_nscrp, a_line, a_prefix);
      debug_uver   ylog_unote   ("not a valid REUSE label");
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   --rce;  if (rc == 0) {
      rc = REUSE__parse_reuse_new (a_nscrp, a_line, a_prefix, a_label, &x_major, &x_minor);
      if (rc <= 0) {
         yerr_uerror ("%s:%d:0: error: ¶%s¶ failed on new-style reuse label åA/aæ", a_nscrp, a_line, a_prefix);
         debug_uver   ylog_unote   ("not a valid REUSE label");
         debug_uver   ylog_uexitr  (__FUNCTION__, rce);
         return rce;
      }
   }
   /*---(global)-------------------------*/
   --rce;  if (strchr (YSTR_UPPER, x_major) != NULL) {
      n  = yUNIT_reuse_desc (x_major, x_tdesc, x_desc);
      debug_uver   ylog_uvalue  ("n"         , n);
      if (n < 0) {
         debug_uver   ylog_unote   ("not set");
         yerr_uerror ("%s:%d:0: error: ¶%s¶ verb identifier ¶%c¶ never set by GLOBAL", a_nscrp, a_line, a_prefix, x_major);
         debug_uver   ylog_uexitr  (__FUNCTION__, rce);
         return rce;
      }
   }
   /*---(config)-------------------------*/
   else if (strchr (YSTR_GREEK, x_major) != NULL) {
      n  = yUNIT_reuse_desc (x_major, x_tdesc, x_desc);
      debug_uver   ylog_uvalue  ("n"         , n);
      if (n < 0) {
         debug_uver   ylog_unote   ("not set");
         yerr_uerror ("%s:%d:0: error: ¶%s¶ verb identifier ¶%c¶ never set by CONFIG", a_nscrp, a_line, a_prefix, x_major);
         debug_uver   ylog_uexitr  (__FUNCTION__, rce);
         return rce;
      }
   }
   /*---(shared)-------------------------*/
   else if (strchr (YSTR_LOWER, x_major) != NULL) {
      n  = yUNIT_reuse_desc (x_major, x_tdesc, x_desc);
      debug_uver   ylog_uvalue  ("n"         , n);
      if (n < 0) {
         debug_uver   ylog_unote   ("not set");
         yerr_uerror ("%s:%d:0: error: ¶%s¶ verb identifier ¶%c¶ never set by SHARED", a_nscrp, a_line, a_prefix, x_major);
         debug_uver   ylog_uexitr  (__FUNCTION__, rce);
         return rce;
      }
   }
   /*---(nobody)-------------------------*/
   else {
      debug_uver   ylog_unote   ("not set");
      yerr_uerror ("%s:%d:0: error: ¶%s¶ verb identifier ¶%c¶ not valid [a-zA-Z]", a_nscrp, a_line, a_prefix, x_major);
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(check recursion)----------------*/
   if (x_major == a_share) {
      debug_uver   ylog_unote   ("reuse is recursive");
      yerr_uerror ("%s:%d:0: error: ¶%s¶ verb identifier ¶%c¶ called inside itself, recursive", a_nscrp, a_line, a_prefix, x_major);
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(save-back)----------------------*/
   if (r_desc  != NULL)  DITTO_parse__desc (x_desc, r_desc);  /* nice stand-out formatting */
   if (r_major != NULL)  *r_major = x_major;
   if (r_minor != NULL)  *r_minor = x_minor;
   /*---(complete)-----------------------*/
   debug_uver   ylog_uexit   (__FUNCTION__);
   return 1;
}

char
REUSE_parse             (char a_nscrp [LEN_TITLE], int a_line, char a_verb [LEN_LABEL], char a_vers, char a_recd [LEN_RECD], char a_share, char r_desc [LEN_LONG], char *r_major, char *r_minor)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
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
   debug_uver   ylog_uenter  (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_desc  != NULL)  strcpy (r_desc, "");
   if (r_major != NULL)  *r_major = '-';
   if (r_minor != NULL)  *r_minor = '-';
   /*---(defense)------------------------*/
   debug_uver   ylog_upoint  ("a_nscrp"   , a_nscrp);
   --rce;  if (a_nscrp     == NULL) {
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   debug_uver   ylog_upoint  ("a_verb"    , a_verb);
   --rce;  if (a_verb     == NULL) {
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   debug_uver   ylog_upoint  ("a_recd"    , a_recd);
   --rce;  if (a_recd     == NULL) {
      yerr_uerror ("%s:%d:0: error: GLOBAL/SHARED/REUSE called with a null string", a_nscrp, a_line);
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(check for right verbs)----------*/
   debug_uver   ylog_unote   ("check examples");
   if      (strcmp (a_verb, "GLOBAL") == 0)  strcpy (x_ex, "-A-");
   else if (strcmp (a_verb, "SHARED") == 0)  strcpy (x_ex, "-a-");
   else if (strcmp (a_verb, "CONFIG") == 0)  strcpy (x_ex, "-ò-");
   else if (strcmp (a_verb, "REUSE" ) == 0)  strcpy (x_ex, "A/a");
   else {
      debug_uver   ylog_unote   ("this only applies to GLOBAL/SHARED/CONFIG/REUSE");
      debug_uver   ylog_uexit   (__FUNCTION__);
      return 0;
   }
   debug_uver   ylog_uinfo   ("x_ex"      , x_ex);
   /*---(check for marker)---------------*/
   strlcpy (x_prefix, a_recd, LEN_RECD);
   debug_uver   ylog_uinfo   ("x_prefix"  , x_prefix);
   p = strchr (x_prefix, '');
   debug_uver   ylog_upoint  ("p"         , p);
   --rce;  if (p == NULL) {
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   p [0] = '\0';
   ystrutrim (x_prefix, LEN_LABEL);
   debug_uver   ylog_uinfo   ("x_prefix"  , x_prefix);
   l = strlen (x_prefix);
   strlcpy (x_label, x_prefix + l - 3, LEN_LABEL);
   /*---(handle global)------------------*/
   rc = REUSE__parse_global (a_nscrp, a_line, a_verb, a_recd, x_prefix, x_label, x_ex, a_vers, r_major);
   debug_uver   ylog_uvalue  ("global"    , rc);
   --rce;  if (rc < 0) {
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(handle shared)------------------*/
   --rce;  if (rc == 0) {
      rc = REUSE__parse_shared (a_nscrp, a_line, a_verb, a_recd, x_prefix, x_label, x_ex, a_vers, r_major);
      debug_uver   ylog_uvalue  ("shared"    , rc);
      if (rc < 0) {
         debug_uver   ylog_uexitr  (__FUNCTION__, rce);
         return rce;
      }
   }
   /*---(handle reuses)------------------*/
   --rce;  if (rc == 0) {
      rc = REUSE__parse_reuse  (a_nscrp, a_line, a_verb, a_recd, x_prefix, x_label, a_share, r_desc, r_major, r_minor);
      debug_uver   ylog_uvalue  ("reuse"     , rc);
      if (rc < 0) {
         debug_uver   ylog_uexitr  (__FUNCTION__, rce);
         return rce;
      }
   }
   /*---(complete)-----------------------*/
   debug_uver   ylog_uexit   (__FUNCTION__);
   return rc;
}



/*====================------------------------------------====================*/
/*===----                        code/conv use                         ----===*/
/*====================------------------------------------====================*/
static void  o___IN_USE__________o () { return; }

char
REUSE_update            (char a_abbr, int a_conds, int a_steps)
{
   /*---(locals)-------------------------*/
   char        rce         =  -10;
   int         n           =  -10;
   /*---(lookup)-------------------------*/
   n = yUNIT_reuse_index (a_abbr);
   --rce;  if (n < 0)                   return rce;
   --rce;  if (s_marks [n].m_line < 0)  return rce;
   /*---(update list)--------------------*/
   s_marks [n].m_conds = a_conds;
   s_marks [n].m_steps = a_steps;
   /*---(complete)-----------------------*/
   return 1;
}

char
REUSE_addback           (char a_abbr, int *b_conds, int *b_steps)
{
   /*---(locals)-------------------------*/
   char        rce         =  -10;
   int         n           =  -10;
   /*---(lookup)-------------------------*/
   n = yUNIT_reuse_index (a_abbr);
   --rce;  if (n < 0)                     return rce;
   --rce;  if (s_marks [n].m_line  <  0)  return rce;
   --rce;  if (s_marks [n].m_conds <= 0)  return rce;
   /*---(update list)--------------------*/
   if (b_conds != NULL)  *b_conds += s_marks [n].m_conds;
   if (b_steps != NULL)  *b_steps += s_marks [n].m_steps;
   /*---(complete)-----------------------*/
   return 1;
}



/*====================------------------------------------====================*/
/*===----                     export/import                            ----===*/
/*====================------------------------------------====================*/
static void  o___EXIM____________o () { return; }

char
REUSE_export            (cchar a_name [LEN_PATH])
{
   char        rce         =  -10;
   FILE       *f           = NULL;
   int         c           =    0;
   --rce;  if (a_name == NULL)   return rce;
   READ_open (__FILE__, __FUNCTION__, __LINE__, my.cwd, a_name, 'w', &f, NULL);
   --rce;  if (f == NULL)  return rce;
   c = yUNIT_reuse_export (f);
   READ_close (__FILE__, __FUNCTION__, __LINE__, "???", &f);
   return c;
}

char
REUSE_import            (cchar a_name [LEN_PATH])
{
   char        rce         =  -10;
   FILE       *f           = NULL;
   int         c           =    0;
   --rce;  if (a_name == NULL)   return rce;
   READ_open (__FILE__, __FUNCTION__, __LINE__, my.cwd, a_name, 'r', &f, NULL);
   --rce;  if (f == NULL)  return rce;
   c = yUNIT_reuse_import (f);
   READ_close (__FILE__, __FUNCTION__, __LINE__, "???", &f);
   /*> yUNIT_reuse_list ();                                                           <*/
   return c;
}



/*====================------------------------------------====================*/
/*===----                        debugging support                     ----===*/
/*====================------------------------------------====================*/
static void  o___DEBUGGING_______o () { return; }

char*
REUSE__actuals          (void)
{
   /*---(locals)-------------------------*/
   int         i           =    0;
   int         x_off       =    0;
   /*---(dittos)-------------------------*/
   strcpy (g_print, "GL                              SH                              CO                            Ï");
   /*---(global)-------------------------*/
   x_off = 3;
   for (i = 0; i < MAX_MARKS; ++i) {
      if (s_marks [i].m_type == T_MASTER) {
         if      (s_marks [i].m_called >= 10)   g_print [i + x_off] = '*';
         else if (s_marks [i].m_called >   0)   g_print [i + x_off] = '0' + s_marks [i].m_called;
         else if (s_marks [i].m_line   >=  0)   g_print [i + x_off] = '´';
      }
   }
   /*---(shared)-------------------------*/
   x_off += 6;
   for (i = 0; i < MAX_MARKS; ++i) {
      if (s_marks [i].m_type == T_SHARES) {
         if      (s_marks [i].m_called >= 10)   g_print [i + x_off] = '*';
         else if (s_marks [i].m_called >   0)   g_print [i + x_off] = '0' + s_marks [i].m_called;
         else if (s_marks [i].m_line   >=  0)   g_print [i + x_off] = '´';
      }
   }
   /*---(config)-------------------------*/
   x_off += 6;
   for (i = 0; i < MAX_MARKS - 2; ++i) {
      if (s_marks [i].m_type == T_CONFIG) {
         if      (s_marks [i].m_called >= 10)   g_print [i + x_off] = '*';
         else if (s_marks [i].m_called >   0)   g_print [i + x_off] = '0' + s_marks [i].m_called;
         else if (s_marks [i].m_line   >=  0)   g_print [i + x_off] = '´';
      }
   }
   /*---(complete)-----------------------*/
   return g_print;
}

char*
REUSE__used             (void)
{
   /*---(locals)-------------------------*/
   int         i           =    0;
   int         x_off       =    0;
   /*---(dittos)-------------------------*/
   strcpy (g_print, "GL ´-----´-----´-----´-----´-   SH ´-----´-----´-----´-----´-   CO ´-----´-----´-----´-----   Ï");
   /*---(global)-------------------------*/
   x_off = 3;
   for (i = 0; i < MAX_MARKS; ++i) {
      if (s_marks [i].m_type == T_MASTER) {
         if (s_marks [i].m_line >= 0)   g_print [i + x_off] = s_marks [i].m_abbr;
      }
   }
   /*---(shared)-------------------------*/
   x_off += 6;
   for (i = 0; i < MAX_MARKS; ++i) {
      if (s_marks [i].m_type == T_SHARES) {
         if (s_marks [i].m_line >= 0)   g_print [i + x_off] = s_marks [i].m_abbr;
      }
   }
   /*---(config)-------------------------*/
   x_off += 6;
   for (i = 0; i < MAX_MARKS - 2; ++i) {
      if (s_marks [i].m_type == T_CONFIG) {
         if (s_marks [i].m_line >= 0)   g_print [i + x_off] = s_marks [i].m_abbr;
      }
   }
   /*---(complete)-----------------------*/
   return g_print;
}

char*
REUSE__detail         (char a_abbr)
{
   char        rce         =  -10;
   char        rc          =    0;
   char        x_type      =  '-';
   char        x_tdesc     [LEN_TERSE] = "";
   int         x_line      =  '-';
   char        x_desc      [LEN_LONG]  = "";
   short       x_conds     =    0;
   short       x_steps     =    0;
   strcpy (g_print, "");
   rc = yUNIT_reuse_data (a_abbr, &x_type, x_tdesc, &x_line, x_desc, &x_conds, &x_steps, NULL);
   if (rc <= 0) {
      sprintf (g_print, "- · ····  ´ · · · · ´ · · · · ´ · · · · ´ · · · · ´ · · · · ´  ···· ····  ·········  Ï");
   } else if (x_conds > 0) {
      ystruencode (x_desc);
      sprintf (g_print, "%c %c %4d  %-51.51s  %4d %4d  %-9.9s  Ï", a_abbr, x_type, x_line, x_desc, x_conds, x_steps, x_tdesc);
   } else if (x_line  > 0) {
      ystruencode (x_desc);
      sprintf (g_print, "%c %c %4d  %-51.51s  ···· ····  %-9.9s  Ï", a_abbr, x_type, x_line, x_desc, x_tdesc);
   } else {
      sprintf (g_print, "%c %c ····  ´ · · · · ´ · · · · ´ · · · · ´ · · · · ´ · · · · ´  ···· ····  %-9.9s  Ï", a_abbr, x_type, x_tdesc);
   }
   return g_print;
}

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




