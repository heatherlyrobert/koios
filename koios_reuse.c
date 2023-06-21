/*===============================[[ beg-code ]]===============================*/
#include    "koios.h"        /* LOCAL  : main header                          */

/*
 *  PURPOSE : allows code to be written once and reused (REUSE) in several
 *  places, either globally (GLOBAL) or within a file (SHARED)
 *
 *  creates separate function and calls when needed
 *
 */



#define   MAX_SHARE   26
typedef struct cSHARE tSHARE;
struct cSHARE {
   int         line;
   char        desc    [LEN_LONG];
};
static tSHARE  s_master [MAX_SHARE];
static tSHARE  s_shares [MAX_SHARE];



/*====================------------------------------------====================*/
/*===----                        script level                          ----===*/
/*====================------------------------------------====================*/
static void  o___PROGRAM_________o () { return; }

char
REUSE_purge             (cchar a_type)
{
   /*---(locals)-------------------------*/
   int         i           =    0;
   /*---(set defaults)-------------------*/
   for (i = 0; i < MAX_SHARE; ++i) {
      switch (a_type) {
      case T_MASTER :
         s_master [i].line = -1;
         strcpy (s_master [i].desc, "");
         break;
      case T_SHARES :
         s_shares [i].line = -1;
         strcpy (s_shares [i].desc, "");
         break;
      }
   }
   /*---(complete)-----------------------*/
   return 0;
}

char REUSE_init              (void)  { REUSE_purge (T_MASTER) ;REUSE_purge (T_SHARES); return 0; }
char REUSE_wrap              (void)  { REUSE_purge (T_MASTER) ;REUSE_purge (T_SHARES); return 0; }



/*====================------------------------------------====================*/
/*===----                      getting and setting                     ----===*/
/*====================------------------------------------====================*/
static void  o___USAGE___________o () { return; }

char
REUSE__index            (cchar a_type, cchar a_mark)
{
   /*---(locals)-------------------------*/
   char        rce         =  -10;
   char        x_valid     [LEN_TITLE] = YSTR_UPPER;
   char        i           =  -10;
   /*---(defense)------------------------*/
   switch (a_type) {
   case T_MASTER :  strcpy (x_valid, YSTR_UPPER);   break;
   case T_SHARES :  strcpy (x_valid, YSTR_LOWER);   break;
   }
   --rce;  if (a_mark == 0)                        return rce;
   --rce;  if (strchr (x_valid , a_mark) == NULL)  return rce;
   /*---(update list)--------------------*/
   i = a_mark - x_valid [0];
   /*---(complete)-----------------------*/
   return i;
}

char
REUSE__set              (cchar a_type, cchar a_mark, int a_line, char a_desc [LEN_LONG])
{
   /*---(locals)-------------------------*/
   char        i           =  -10;
   /*---(get index)----------------------*/
   i = REUSE__index (a_type, a_mark);
   if (i < 0) return i;
   /*---(update list)--------------------*/
   switch (a_type) {
   case T_MASTER :
      s_master [i].line = a_line;
      if (a_desc != NULL)  strlcpy (s_master [i].desc, a_desc, LEN_LONG);
      else                 strcpy  (s_master [i].desc, "");
      break;
   case T_SHARES :
      s_shares [i].line = a_line;
      if (a_desc != NULL)  strlcpy (s_shares [i].desc, a_desc, LEN_LONG);
      else                 strcpy  (s_shares [i].desc, "");
      break;
   }
   /*---(complete)-----------------------*/
   return 0;
}

char
REUSE__set_recd         (cchar a_type, cchar a_mark, int a_line, char a_recd [LEN_RECD])
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
   strltrim (p, ySTR_BOTH, LEN_LONG);
   /*---(complete)-----------------------*/
   return REUSE__set (a_type, a_mark, a_line, p);
}

int
REUSE__get              (cchar a_type, cchar a_mark, char r_desc [LEN_LONG])
{
   /*---(locals)-------------------------*/
   char        i           =  -10;
   int         x_line      =   -1;
   /*---(default)------------------------*/
   if (r_desc != NULL)   strcpy  (r_desc, "");
   /*---(get index)----------------------*/
   i = REUSE__index (a_type, a_mark);
   if (i < 0) return i;
   /*---(update list)--------------------*/
   switch (a_type) {
   case T_MASTER :
      x_line = s_master [i].line;
      if (r_desc != NULL)  strlcpy (r_desc, s_master [i].desc, LEN_LONG);
      break;
   case T_SHARES :
      x_line = s_shares [i].line;
      if (r_desc != NULL)  strlcpy (r_desc, s_shares [i].desc, LEN_LONG);
      break;
   }
   /*---(complete)-----------------------*/
   return x_line;
}



/*====================------------------------------------====================*/
/*===----                    record parsing support                    ----===*/
/*====================------------------------------------====================*/
static void  o___PARSING_________o () { return; }

char
REUSE_parse             (cchar a_scrp [LEN_TITLE], int a_line, char a_verb [LEN_LABEL], char a_recd [LEN_RECD], char a_cshare, char *r_share)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        x_recd      [LEN_RECD]  = "";
   char       *p           = NULL;
   char        m           =  '-';
   int         n           =   -1;
   int         o           =   -1;
   char        x_check     =   -1;
   char        x_label     [LEN_LABEL] = "";
   char        x_desc      [LEN_LONG]  = "";
   char        x_ex        [LEN_SHORT] = "-A-";
   /*---(header)-------------------------*/
   DEBUG_INPT   yLOG_senter  (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_share != NULL)  *r_share = '-';
   /*---(defense)------------------------*/
   DEBUG_INPT   yLOG_point   ("a_scrp"    , a_scrp);
   --rce;  if (a_scrp     == NULL) {
      DEBUG_INPT   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_INPT   yLOG_point   ("a_verb"    , a_verb);
   --rce;  if (a_verb     == NULL) {
      DEBUG_INPT   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_INPT   yLOG_point   ("a_recd"    , a_recd);
   --rce;  if (a_recd     == NULL) {
      yURG_err (YURG_FATAL, "%s:%d:0: error: GLOBAL/SHARED/REUSE called with a null string", a_scrp, a_line);
      DEBUG_INPT   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(check for right verbs)----------*/
   if      (strcmp (a_verb, "GLOBAL") == 0)  strcpy (x_ex, "-A-");
   else if (strcmp (a_verb, "SHARED") == 0)  strcpy (x_ex, "-a-");
   else if (strcmp (a_verb, "REUSE" ) == 0)  strcpy (x_ex, "-a-");
   else {
      DEBUG_INPT   yLOG_snote   ("this only applies to GLOBAL/SHARED/REUSE");
      DEBUG_INPT   yLOG_sexit   (__FUNCTION__);
      return 0;
   }
   /*---(check for marker)---------------*/
   strlcpy (x_recd, a_recd, LEN_RECD);
   p = strchr (x_recd, '');
   --rce;  if (p == NULL) {
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   p [0] = '\0';
   strltrim (x_recd, ySTR_BOTH, LEN_LABEL);
   p = strchr (x_recd, '-');
   DEBUG_INPT   yLOG_spoint  (p);
   --rce;  if (p == NULL) {
      yURG_err (YURG_FATAL, "%s:%d:0: error: ¶%s¶ missing valid identifier string, e.g., %s", a_scrp, a_line, x_recd, x_ex);
      DEBUG_INPT   yLOG_snote   ("no openning marker");
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   strlcpy  (x_label, p, LEN_LABEL);
   strltrim (x_label, ySTR_BOTH, LEN_LABEL);
   m = x_label [1];
   DEBUG_INPT   yLOG_schar   (m);
   --rce;  if (x_label [2] != '-') {
      yURG_err (YURG_FATAL, "%s:%d:0: error: ¶%s¶ identifier ¶%s¶ does not end with -, e.g., %s", a_scrp, a_line, x_recd, x_label, x_ex);
      DEBUG_INPT   yLOG_snote   ("no close marker");
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(find indexes)-------------------*/
   n  = REUSE__get (T_MASTER, m, NULL);
   DEBUG_INPT   yLOG_sint    (n);
   o  = REUSE__get (T_SHARES, m, NULL);
   DEBUG_INPT   yLOG_sint    (o);
   /*---(handle global)------------------*/
   --rce;  if (strcmp ("GLOBAL" , a_verb) == 0) {
      DEBUG_INPT   yLOG_snote   ("handle global");
      if (strstr (a_scrp, "master.unit") == NULL) {
         DEBUG_INPT   yLOG_snote   ("GLOBAL only allowed in master.unit");
         yURG_err (YURG_FATAL, "%s:%d:0: error: GLOBAL verb not allowed outside master.unit", a_scrp, a_line);
         DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
         return rce;
      }
      if (strchr (YSTR_UPPER, m) == NULL) {
         DEBUG_INPT   yLOG_snote   ("global identifier must be A-Z");
         yURG_err (YURG_FATAL, "%s:%d:0: error: ¶%s¶ identifier ¶%c¶ not valid å%sæ", a_scrp, a_line, x_recd, m, YSTR_UPPER);
         DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
         return rce;
      }
      if (n >= 0) {
         DEBUG_INPT   yLOG_snote   ("already set");
         yURG_err (YURG_FATAL, "%s:%d:0: error: ¶%s¶ identifier ¶%c¶ already in use", a_scrp, a_line, x_recd, m);
         DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
         return rce;
      }
      rc = REUSE__set_recd (T_MASTER, m, a_line, a_recd);
      *r_share = m;
   }
   /*---(handle shared)------------------*/
   --rce;  if (strcmp ("SHARED" , a_verb) == 0) {
      DEBUG_INPT   yLOG_snote   ("handle shared");
      if (strstr (a_scrp, "master.unit") != NULL) {
         DEBUG_INPT   yLOG_snote   ("SHARED verb not allowed in master.unit");
         yURG_err (YURG_FATAL, "%s:%d:0: error: SHARED verb not allowed inside master.unit", a_scrp, a_line);
         DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
         return rce;
      }
      if (strchr (YSTR_LOWER, m) == NULL) {
         DEBUG_INPT   yLOG_snote   ("shared identifier must be a-z");
         yURG_err (YURG_FATAL, "%s:%d:0: error: ¶%s¶ identifier ¶%c¶ not valid å%sæ", a_scrp, a_line, x_recd, m, YSTR_LOWER);
         DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
         return rce;
      }
      if (o >= 0) {
         DEBUG_INPT   yLOG_snote   ("already set");
         yURG_err (YURG_FATAL, "%s:%d:0: error: ¶%s¶ identifier ¶%c¶ already in use", a_scrp, a_line, x_recd, m);
         DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
         return rce;
      }
      rc = REUSE__set_recd (T_SHARES, m, a_line, a_recd);
      *r_share = m;
   }
   /*---(handle reuses)------------------*/
   --rce;  if (strcmp ("REUSE" , a_verb) == 0) {
      DEBUG_INPT   yLOG_snote   ("handle reuse");
      if (strchr (YSTR_UPPER YSTR_LOWER, m) == NULL) {
         DEBUG_INPT   yLOG_snote   ("not set");
         yURG_err (YURG_FATAL, "%s:%d:0: error: REUSE identifier å%cæ not valid [a-zA-Z]", a_scrp, a_line, m);
         DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
         return rce;
      }
      if (strchr (YSTR_UPPER, m) == NULL && n < 0) {
         DEBUG_INPT   yLOG_snote   ("not set");
         yURG_err (YURG_FATAL, "%s:%d:0: error: REUSE identifier å%cæ never set by GLOBAL", a_scrp, a_line, m);
         DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
         return rce;
      }
      if (strchr (YSTR_LOWER, m) == NULL && m < 0) {
         DEBUG_INPT   yLOG_snote   ("not set");
         yURG_err (YURG_FATAL, "%s:%d:0: error: REUSE identifier å%cæ never set by SHARED", a_scrp, a_line, m);
         DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
         return rce;
      }
      if (m == a_cshare) {
         DEBUG_INPT   yLOG_snote   ("reuse is recursive");
         yURG_err (YURG_FATAL, "%s:%d:0: error: REUSE identifier å%cæ called inside itself, recursive", a_scrp, a_line, m);
         DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
         return rce;
      }
      *r_share = m;
   }
   /*---(complete)-----------------------*/
   DEBUG_INPT   yLOG_sexit   (__FUNCTION__);
   return 1;
}



/*====================------------------------------------====================*/
/*===----                        debugging support                     ----===*/
/*====================------------------------------------====================*/
static void  o___DEBUG___________o () { return; }

char*
REUSE__used             (void)
{
   /*---(locals)-------------------------*/
   int         i           =    0;
   /*---(dittos)-------------------------*/
   strcpy (g_print, "´-----´-----´-----´-----´-   ´-----´-----´-----´-----´-");
   for (i = 0; i < MAX_SHARE; ++i) {
      if (s_master [i].line >= 0)   g_print [i +  0] = 'A' + i;
   }
   for (i = 0; i < MAX_SHARE; ++i) {
      if (s_shares [i].line >= 0)   g_print [i + 29] = 'a' + i;
   }
   /*---(complete)-----------------------*/
   return g_print;
}



