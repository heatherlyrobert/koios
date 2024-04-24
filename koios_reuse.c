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
   short       conds;
   short       steps;
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
         s_master [i].line  = -1;
         strcpy (s_master [i].desc, "");
         s_master [i].conds =  0;
         s_master [i].steps =  0;
         break;
      case T_SHARES :
         s_shares [i].line  = -1;
         strcpy (s_shares [i].desc, "");
         s_shares [i].conds =  0;
         s_shares [i].steps =  0;
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
      s_master [i].conds =  0;
      s_master [i].steps =  0;
      break;
   case T_SHARES :
      s_shares [i].line = a_line;
      if (a_desc != NULL)  strlcpy (s_shares [i].desc, a_desc, LEN_LONG);
      else                 strcpy  (s_shares [i].desc, "");
      s_shares [i].conds =  0;
      s_shares [i].steps =  0;
      break;
   }
   /*---(complete)-----------------------*/
   return 0;
}

char
REUSE__set_recd         (cchar a_type, cchar a_mark, int a_line, char a_vers, char a_recd [LEN_RECD])
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
   koios_ystr_trim (p, LEN_LONG);
   /*---(complete)-----------------------*/
   return REUSE__set (a_type, a_mark, a_line, p);
}

int
REUSE__get              (cchar a_type, cchar a_mark, char r_desc [LEN_LONG], int *r_conds, int *r_steps)
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
      if (r_desc  != NULL)  strlcpy (r_desc, s_master [i].desc, LEN_LONG);
      if (r_conds != NULL)  *r_conds = s_master [i].conds;
      if (r_steps != NULL)  *r_steps = s_master [i].steps;
      break;
   case T_SHARES :
      x_line = s_shares [i].line;
      if (r_desc  != NULL)  strlcpy (r_desc, s_shares [i].desc, LEN_LONG);
      if (r_conds != NULL)  *r_conds = s_shares [i].conds;
      if (r_steps != NULL)  *r_steps = s_shares [i].steps;
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
REUSE_parse             (cchar a_nscrp [LEN_TITLE], int a_line, char a_verb [LEN_LABEL], char a_vers, char a_recd [LEN_RECD], char r_desc [LEN_LONG], char a_cshare, char *r_share)
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
   DEBUG_UVER   yLOG_uenter  (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_share != NULL)  *r_share = '-';
   /*---(defense)------------------------*/
   DEBUG_UVER   yLOG_upoint  ("a_nscrp"   , a_nscrp);
   --rce;  if (a_nscrp     == NULL) {
      DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_UVER   yLOG_upoint  ("a_verb"    , a_verb);
   --rce;  if (a_verb     == NULL) {
      DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_UVER   yLOG_upoint  ("a_recd"    , a_recd);
   --rce;  if (a_recd     == NULL) {
      /*> yURG_err (YURG_FATAL, "%s:%d:0: error: GLOBAL/SHARED/REUSE called with a null string", a_nscrp, a_line);   <*/
      DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_UVER   yLOG_upoint  ("r_share"   , r_share);
   --rce;  if (r_share    == NULL) {
      DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(check for right verbs)----------*/
   DEBUG_UVER   yLOG_unote   ("check examples");
   if      (strcmp (a_verb, "GLOBAL") == 0)  strcpy (x_ex, "-A-");
   else if (strcmp (a_verb, "SHARED") == 0)  strcpy (x_ex, "-a-");
   else if (strcmp (a_verb, "REUSE" ) == 0)  strcpy (x_ex, "-a-");
   else {
      DEBUG_UVER   yLOG_unote   ("this only applies to GLOBAL/SHARED/REUSE");
      DEBUG_UVER   yLOG_uexit   (__FUNCTION__);
      return 0;
   }
   DEBUG_UVER   yLOG_uinfo   ("x_ex"      , x_ex);
   /*---(check for marker)---------------*/
   strlcpy (x_recd, a_recd, LEN_RECD);
   DEBUG_UVER   yLOG_uinfo   ("x_recd"    , x_recd);
   p = strchr (x_recd, '');
   DEBUG_UVER   yLOG_upoint  ("p"         , p);
   --rce;  if (p == NULL) {
      DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   p [0] = '\0';
   koios_ystr_trim (x_recd, LEN_LABEL);
   DEBUG_UVER   yLOG_uinfo   ("x_recd"    , x_recd);
   p = strchr (x_recd, '-');
   DEBUG_UVER   yLOG_upoint  ("p"         , p);
   --rce;  if (p == NULL) {
      /*> yURG_err (YURG_FATAL, "%s:%d:0: error: ¶%s¶ missing valid identifier string, e.g., %s", a_nscrp, a_line, x_recd, x_ex);   <*/
      DEBUG_UVER   yLOG_unote   ("no openning marker");
      DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   strlcpy  (x_label, p, LEN_LABEL);
   koios_ystr_trim (x_label, LEN_LABEL);
   m = x_label [1];
   DEBUG_UVER   yLOG_uchar   ("m"         , m);
   --rce;  if (x_label [2] != '-') {
      /*> yURG_err (YURG_FATAL, "%s:%d:0: error: ¶%s¶ identifier ¶%s¶ does not end with -, e.g., %s", a_nscrp, a_line, x_recd, x_label, x_ex);   <*/
      DEBUG_UVER   yLOG_unote   ("no close marker");
      DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(find indexes)-------------------*/
   n  = REUSE__get (T_MASTER, m, NULL, NULL, NULL);
   DEBUG_UVER   yLOG_uvalue  ("n"         , n);
   o  = REUSE__get (T_SHARES, m, NULL, NULL, NULL);
   DEBUG_UVER   yLOG_uvalue  ("o"         , o);
   /*---(handle global)------------------*/
   --rce;  if (strcmp ("GLOBAL" , a_verb) == 0) {
      DEBUG_UVER   yLOG_unote   ("handle global");
      if (strstr (a_nscrp, "master.unit") == NULL) {
         DEBUG_UVER   yLOG_unote   ("GLOBAL only allowed in master.unit");
         /*> yURG_err (YURG_FATAL, "%s:%d:0: error: GLOBAL verb not allowed outside master.unit", a_nscrp, a_line);   <*/
         DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
         return rce;
      }
      if (strchr (YSTR_UPPER, m) == NULL) {
         DEBUG_UVER   yLOG_unote   ("global identifier must be A-Z");
         /*> yURG_err (YURG_FATAL, "%s:%d:0: error: ¶%s¶ identifier ¶%c¶ not valid å%sæ", a_nscrp, a_line, x_recd, m, YSTR_UPPER);   <*/
         DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
         return rce;
      }
      if (n >= 0) {
         DEBUG_UVER   yLOG_unote   ("already set");
         /*> yURG_err (YURG_FATAL, "%s:%d:0: error: ¶%s¶ identifier ¶%c¶ already in use", a_nscrp, a_line, x_recd, m);   <*/
         DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
         return rce;
      }
      rc = REUSE__set_recd (T_MASTER, m, a_line, a_vers, a_recd);
      DEBUG_UVER   yLOG_uvalue  ("set global", rc);
      *r_share = m;
   }
   /*---(handle shared)------------------*/
   --rce;  if (strcmp ("SHARED" , a_verb) == 0) {
      DEBUG_UVER   yLOG_unote   ("handle shared");
      if (strstr (a_nscrp, "master.unit") != NULL) {
         DEBUG_UVER   yLOG_unote   ("SHARED verb not allowed in master.unit");
         /*> yURG_err (YURG_FATAL, "%s:%d:0: error: SHARED verb not allowed inside master.unit", a_nscrp, a_line);   <*/
         DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
         return rce;
      }
      if (strchr (YSTR_LOWER, m) == NULL) {
         DEBUG_UVER   yLOG_unote   ("shared identifier must be a-z");
         /*> yURG_err (YURG_FATAL, "%s:%d:0: error: ¶%s¶ identifier ¶%c¶ not valid å%sæ", a_nscrp, a_line, x_recd, m, YSTR_LOWER);   <*/
         DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
         return rce;
      }
      if (o >= 0) {
         DEBUG_UVER   yLOG_unote   ("already set");
         /*> yURG_err (YURG_FATAL, "%s:%d:0: error: ¶%s¶ identifier ¶%c¶ already in use", a_nscrp, a_line, x_recd, m);   <*/
         DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
         return rce;
      }
      rc = REUSE__set_recd (T_SHARES, m, a_line, a_vers, a_recd);
      DEBUG_UVER   yLOG_uvalue  ("set share" , rc);
      *r_share = m;
   }
   /*---(handle reuses)------------------*/
   --rce;  if (strcmp ("REUSE" , a_verb) == 0) {
      DEBUG_UVER   yLOG_unote   ("handle reuse");
      if (strchr (YSTR_UPPER, m) != NULL) {
         if (n <= 0) {
            DEBUG_UVER   yLOG_unote   ("not set");
            /*> yURG_err (YURG_FATAL, "%s:%d:0: error: ¶%s¶ verb identifier ¶%c¶ never set by GLOBAL", a_nscrp, a_line, x_recd, m);   <*/
            DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
            return rce;
         }
         REUSE__get (T_MASTER, m, x_desc, NULL, NULL);
      }
      else if (strchr (YSTR_LOWER, m) != NULL) {
         if (strstr (a_nscrp, "master.unit") != NULL) {
            DEBUG_UVER   yLOG_unote   ("shared identifiers not allowed in master.unit");
            /*> yURG_err (YURG_FATAL, "%s:%d:0: error: REUSE verb on ¶%c¶ SHARED identifier not allowed inside master.unit", a_nscrp, a_line, m, a_line);   <*/
            DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
            return rce;
         }
         if (o <= 0) {
            DEBUG_UVER   yLOG_unote   ("not set");
            /*> yURG_err (YURG_FATAL, "%s:%d:0: error: ¶%s¶ verb identifier ¶%c¶ never set by SHARED", a_nscrp, a_line, x_recd, m);   <*/
            DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
            return rce;
         }
         REUSE__get (T_SHARES, m, x_desc, NULL, NULL);
      } else {
         DEBUG_UVER   yLOG_unote   ("not set");
         /*> yURG_err (YURG_FATAL, "%s:%d:0: error: ¶%s¶ verb identifier ¶%c¶ not valid [a-zA-Z]", a_nscrp, a_line, x_recd, m);   <*/
         DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
         return rce;
      }
      if (m == a_cshare) {
         DEBUG_UVER   yLOG_unote   ("reuse is recursive");
         /*> yURG_err (YURG_FATAL, "%s:%d:0: error: ¶%s¶ verb identifier ¶%c¶ called inside itself, recursive", a_nscrp, a_line, x_recd, m);   <*/
         DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
         return rce;
      }
      *r_share = m;
      if (r_desc  != NULL)  snprintf (r_desc, LEN_LONG, "[ %-.70s ]", x_desc);  /* nice stand-out formatting */
   }
   /*---(complete)-----------------------*/
   DEBUG_UVER   yLOG_uexit   (__FUNCTION__);
   return 1;
}



/*====================------------------------------------====================*/
/*===----                        code/conv use                         ----===*/
/*====================------------------------------------====================*/
static void  o___IN_USE__________o () { return; }

char
REUSE_update            (cchar a_mark, int a_conds, int a_steps)
{
   /*---(locals)-------------------------*/
   char        i           =  -10;
   char        x_type      =  '-';
   /*---(pick type)----------------------*/
   if (a_mark == tolower (a_mark))  x_type = T_SHARES;
   else                             x_type = T_MASTER;
   /*---(get index)----------------------*/
   i = REUSE__index (x_type, a_mark);
   if (i < 0) return i;
   /*---(update list)--------------------*/
   switch (x_type) {
   case T_MASTER :
      if (s_master [i].line < 0)   return -1;
      s_master [i].conds = a_conds;
      s_master [i].steps = a_steps;
      break;
   case T_SHARES :
      if (s_shares [i].line < 0)   return -2;
      s_shares [i].conds = a_conds;
      s_shares [i].steps = a_steps;
      break;
   }
   /*---(complete)-----------------------*/
   return 0;
}

char
REUSE_export            (cchar a_name [LEN_PATH])
{
   char        rce         =  -10;
   FILE       *f           = NULL;
   int         i           =    0;
   char        x_desc      [LEN_LONG]  = "";
   --rce;  if (a_name == NULL)   return rce;
   /*> f = fopen (a_name, "wt");                                                      <*/
   READ_open (a_name, 'w', &f, NULL);
   --rce;  if (f == NULL)  return rce;
   for (i = 0; i < 26; ++i) {
      strlcpy    (x_desc, s_master [i].desc, LEN_LONG);
      koios_ystr_encode (x_desc);
      fprintf (f, "%c %4d %-75.75s %4d %4d\n", i + 'A', s_master [i].line, x_desc, s_master [i].conds, s_master [i].steps);
   }
   /*> fclose (f);                                                                    <*/
   READ_close (&f);
   return 0;
}

char
REUSE_import            (cchar a_name [LEN_PATH])
{
   char        rce         =  -10;
   char        rc          =    0;
   FILE       *f           = NULL;
   int         i           =    0;
   char        x_recd      [LEN_RECD]  = "";
   int         l           =    0;
   char        x_abbr      =  '-';
   int         x_line      =    0;
   char        x_desc      [LEN_LONG]  = "";
   int         x_conds     =    0;
   int         x_steps     =    0;
   --rce;  if (a_name == NULL)   return rce;
   /*> f = fopen (a_name, "rt");                                                      <*/
   READ_open (a_name, 'r', &f, NULL);
   --rce;  if (f == NULL)  return rce;
   for (i = 0; i < 26; ++i) {
      fgets   (x_recd, LEN_RECD, f);
      if (feof (f))  break;
      l = strlen (x_recd);
      if (x_recd [l - 1] == '\n')   x_recd [--l] = '\0';
      rc = sscanf  (x_recd, "%c %4d %s %4d %4d", &x_abbr, &x_line, x_desc, &x_conds, &x_steps);
      if (x_line < 1)  continue;
      koios_ystr_decode (x_desc);
      rc = REUSE__set   (T_MASTER, 'A' + i, x_line, x_desc);
      rc = REUSE_update ('A' + i, x_conds, x_steps);
   }
   /*> fclose (f);                                                                    <*/
   READ_close (&f);
   return 0;
}

char
REUSE_add               (cchar a_mark, int *b_conds, int *b_steps)
{
   /*---(locals)-------------------------*/
   char        rce         =  -10;
   char        i           =  -10;
   char        x_type      =  '-';
   /*---(pick type)----------------------*/
   if (a_mark == tolower (a_mark))  x_type = T_SHARES;
   else                             x_type = T_MASTER;
   /*---(get index)----------------------*/
   i = REUSE__index (x_type, a_mark);
   if (i < 0) return i;
   /*---(update list)--------------------*/
   switch (x_type) {
   case T_MASTER : 
      if (b_conds != NULL)  *b_conds += s_master [i].conds;
      if (b_steps != NULL)  *b_steps += s_master [i].steps;
      break;
   case T_SHARES :
      if (b_conds != NULL)  *b_conds += s_shares [i].conds;
      if (b_steps != NULL)  *b_steps += s_shares [i].steps;
      break;
   }
   /*---(complete)-----------------------*/
   return 0;
}



/*====================------------------------------------====================*/
/*===----                        debugging support                     ----===*/
/*====================------------------------------------====================*/
static void  o___DEBUGGING_______o () { return; }

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



