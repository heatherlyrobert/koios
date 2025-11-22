/*===============================[[ beg-code ]]===============================*/
#include    "koios.h"        /* LOCAL  : main header                          */

/*
 *  PURPOSE : allows code to be written once (COND) and copied in several
 *  places (DITTO) within a single script (SCRP)
 *
 *  code is repeated in-line whenever called
 *
 */



#define   MAX_DITTO   10
typedef struct cDITTO tDITTO;
struct cDITTO {
   int         d_line;
   char        d_desc    [LEN_LONG];
   char        d_called;
};
static tDITTO  s_dittos [MAX_DITTO];



/*====================------------------------------------====================*/
/*===----                        script level                          ----===*/
/*====================------------------------------------====================*/
static void  o___PROGRAM_________o () { return; }

char
DITTO_purge             (void)
{
   /*---(locals)-------------------------*/
   int         i           =    0;
   /*---(set defaults)-------------------*/
   for (i = 0; i < MAX_DITTO; ++i) {
      s_dittos [i].d_line   = -1;
      strcpy (s_dittos [i].d_desc, "");
      s_dittos [i].d_called =  0;
   }
   /*---(complete)-----------------------*/
   return 0;
}

char DITTO_init              (void)  { return DITTO_purge (); }
char DITTO_wrap              (void)  { return DITTO_purge (); }



/*====================------------------------------------====================*/
/*===----                      getting and setting                     ----===*/
/*====================------------------------------------====================*/
static void  o___USAGE___________o () { return; }

char
DITTO__index            (cchar a_mark)
{
   /*---(locals)-------------------------*/
   char        rce         =  -10;
   char       *x_valid     = YSTR_NUMBER;
   char        i           =  -10;
   /*---(defense)------------------------*/
   --rce;  if (a_mark == 0)                        return rce;
   --rce;  if (strchr (x_valid , a_mark) == NULL)  return rce;
   /*---(update list)--------------------*/
   i = a_mark - x_valid [0];
   /*---(complete)-----------------------*/
   return i;
}

char
DITTO__set              (cchar a_mark, int a_line, char a_desc [LEN_LONG])
{
   /*---(locals)-------------------------*/
   char        i           =  -10;
   /*---(get index)----------------------*/
   i = DITTO__index (a_mark);
   if (i < 0) return i;
   /*---(update list)--------------------*/
   s_dittos [i].d_line = a_line;
   if (a_desc != NULL)  strlcpy (s_dittos [i].d_desc, a_desc, LEN_LONG);
   else                 strcpy  (s_dittos [i].d_desc, "");
   /*---(complete)-----------------------*/
   return 0;
}

char
DITTO__set_recd         (cchar a_mark, int a_line, char a_vers, char a_recd [LEN_RECD])
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
   return DITTO__set (a_mark, a_line, p);
}

int
DITTO__get              (cchar a_mark, char r_desc [LEN_LONG])
{
   /*---(locals)-------------------------*/
   char        i           =  -10;
   int         x_line      =   -1;
   /*---(default)------------------------*/
   if (r_desc != NULL)   strcpy  (r_desc, "");
   /*---(get index)----------------------*/
   i = DITTO__index (a_mark);
   if (i < 0) return i;
   /*---(update list)--------------------*/
   x_line = s_dittos [i].d_line;
   if (r_desc != NULL)  strlcpy (r_desc, s_dittos [i].d_desc, LEN_LONG);
   /*---(complete)-----------------------*/
   return x_line;
}

char
DITTO_called            (char a_mark)
{
   /*---(locals)-------------------------*/
   char        i           =   -1;
   /*---(get index)----------------------*/
   i = DITTO__index (a_mark);
   if (i < 0) return i;
   /*---(update list)--------------------*/
   ++(s_dittos [i].d_called);
   /*---(complete)-----------------------*/
   return 1;
}



/*====================------------------------------------====================*/
/*===----                   turning dittoing on/off                    ----===*/
/*====================------------------------------------====================*/
static void  o___TOGGLE__________o () { return; }

static  FILE *s_fmain  = NULL;   /* script file being read                    */
static  FILE *s_fditto = NULL;   /* re-opened version to process the ditto    */

/*
 *
 *  complexity orig  (20)  [fcC##g·L44·27-·E-2D1-]
 *             long  (28)  [fcg·C66--21·L44·227--·1-E2D-]
 *
 * this will show in the tag window for the requested function
 *
 * 123456789-123456789-
 *
 * COMPLEXITY
 * ´· ´···········scope
 * file scope 
 * char return
 * global prototype
 * ´· ´··········params
 * 12 total
 * 6  incomming-only
 * 6  return-only
 * ·  both directions
 * ·  function pointer
 * 2  number pointer
 * 1  double pointer
 * ´· ´···········lines
 * L  100-105 lines
 * 4  40% debugging
 * 4  40% actual code
 * ´· ´············vars
 * 2  local
 * 2  file   ( 7 refs)
 * ·  global ( - refs)
 * ´· ´···········logic
 * 1  indent level
 * ·  loops
 * 15 choices
 * 2  normal ends
 * 14 error returns
 * ·  memory alloc
 * ´· ´·············end
 */

/*
 * o                                                   w      c  F G X r  c                            n   w     D                                L          
 * n          p p           p      %           i   c r ´  m   a  c c c e  a D R  F G     v O m    o s  c o i y   a D D D    m    g     v          s        s 
 * e   s r p  a a      p    m p  t d %  L F G  n   h e e  e   l  a a a c  l f f  f f     i f y  i u y  u p n g   c s m m D  a    l     i o  V M F t  u s s t 
 * l   c t r  u r    p b  p u f  o e c  v v v  d l o t r  m   l  l l l u  l u u  u u c y k u s  n t s  r e d r   t t a a w  c  f o c y k t  m m m a  n c t r 
 * i   o y o  d a  p o o  n l u  t b o  a a a  e o i u r  o   ´  l l l r  ´ n n  n n s l e n t  p p t  s n o a   i y c t a  r  i b s l e h  a a a t  i r e i 
 * n   p p t  i m  i u t  u t n  a u d  r r r  n o c r o  r   b  e e e s  t c c  c c t i y c r  u u e  e g w p   v l r c r  o  l a t i y e  s s s i  t p p n 
 * e   e e o  t s  n t h  m i c  l g e  s s s  t p e n r  y   y  r r r e  o s s  s s d b s s y  t t m  s l s h   e e o h n  s  e l d b s r  k k k c  s s s g 
 * á  å---------------------complexity---------------------æ å-------------------integration------------------æ å----------------watch-points---------------æ
 * ·   g c g  ´ B  5 5 1  2 1 ·  K 4 5  3 7 ·  1 · D 2 C  á   5  1 4 · ·  # Z 1  á 1 · · · · ·  ´ · ·  ´ · · ·   > l i · ·  4  á 2 · · · 2  ´ · · ·  ´ · · ·
 *
 * å´         æ  å 179æ  åæ
 */
             /*-> 123456789-123456789-123456789-123456789--[ ······ [·Ï·Ï·Ï·]-*/
char         /*->  --------------------------------------------[ ´········· ]-*/ /*-ågcg´·Bá551á21·´K45´37·´1·D2Cá·æ¬å5á14··´#Z1á·1·····´···´····æ¬å>li··´4·2···2´····´····æ-*/
DITTO_beg               (FILE **b_scrp, cchar a_nscrp [LEN_TITLE], int a_line, char a_runtype, char a_mark, int a_ditto, char *r_dittoing, char *r_mark, char *r_dmark, int *r_dstart, int *r_dline)
{
   /*---(locals)-----------+-----------+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char       *p           = NULL;
   /*---(header)-------------------------*/
   UDEBUG_KOIOS   ylog_uenter  (__FUNCTION__);
   /*---(defense)------------------------*/
   UDEBUG_KOIOS   ylog_upoint  ("b_scrp"    , b_scrp);
   --rce;  if (b_scrp       == NULL) {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   UDEBUG_KOIOS   ylog_upoint  ("a_nscrp"    , a_nscrp);
   --rce;  if (a_nscrp       == NULL) {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   UDEBUG_KOIOS   ylog_upoint  ("r_dittoing", r_dittoing);
   --rce;  if (r_dittoing   == NULL) {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   UDEBUG_KOIOS   ylog_upoint  ("r_mark"    , r_mark);
   --rce;  if (r_mark       == NULL) {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   UDEBUG_KOIOS   ylog_upoint  ("r_dmark"   , r_dmark);
   --rce;  if (r_dmark      == NULL) {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   UDEBUG_KOIOS   ylog_upoint  ("r_dstart"   , r_dstart);
   --rce;  if (r_dstart      == NULL) {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   UDEBUG_KOIOS   ylog_upoint  ("r_dline"   , r_dline);
   --rce;  if (r_dline      == NULL) {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(quick-out)----------------------*/
   UDEBUG_KOIOS   ylog_uchar   ("*r_dittoing", *r_dittoing);
   --rce;  if (*r_dittoing  == 'y') {
      yerr_uerror ("%s:%d:0: error: DITTO '%c' can not start as dittoing already active", a_nscrp, a_line, a_mark);
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(check mark)---------------------*/
   UDEBUG_KOIOS   ylog_uvalue  ("a_ditto"    , a_ditto);
   --rce;  if (a_ditto < 1) {
      UDEBUG_KOIOS   ylog_unote   ("unset identifier");
      yerr_uerror ("%s:%d:0: error: DITTO '%c' not set by previous COND", a_nscrp, a_line, a_mark);
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(handle runtype)-----------------*/
   if (a_runtype != G_RUN_CREATE && a_runtype != G_RUN_DEBUG) {
      UDEBUG_KOIOS   ylog_unote   ("create/debug mode, ditto_beg processing done");
      *r_mark   = a_mark;
      *r_dstart = a_ditto;
      UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
      return 0;
   }
   /*---(check files)--------------------*/
   UDEBUG_KOIOS   ylog_upoint  ("*b_scrp"   , *b_scrp);
   --rce;  if (*b_scrp      == NULL) {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   UDEBUG_KOIOS   ylog_upoint  ("s_fditto"  , s_fditto);
   --rce;  if (s_fditto     != NULL) {
      UDEBUG_KOIOS   ylog_unote   ("already have second version open");
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(reopen file)--------------------*/
   rc = yenv_uopen_detail (__FILE__, __FUNCTION__, __LINE__, a_nscrp, 'r', &s_fditto);
   UDEBUG_KOIOS   ylog_uvalue  ("open"      , rc);
   UDEBUG_KOIOS   ylog_upoint  ("s_fditto"  , s_fditto);
   --rce;  if (rc < 0 || s_fditto == NULL) {
      UDEBUG_KOIOS   ylog_unote   ("scrp file, can not re-open script file");
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(swap files)---------------------*/
   UDEBUG_KOIOS   ylog_unote   ("swap file for script");
   s_fmain      = *b_scrp;
   *b_scrp      = s_fditto;
   *r_mark      = a_mark;
   *r_dittoing  = 'y';
   *r_dmark     = a_mark;
   *r_dstart    = a_ditto;
   *r_dline     = 0;
   /*---(complete)-----------------------*/
   UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
   return 1;
}

char
DITTO_end               (FILE **b_scrp, char *r_dittoing, char *r_dmark, int *r_ditto, int *r_dline)
{
   /*---(locals)-----------+-----------+-*/
   char        rce         =  -10;
   char        rc          =    0;
   /*---(header)-------------------------*/
   UDEBUG_KOIOS   ylog_uenter  (__FUNCTION__);
   /*---(defense)------------------------*/
   UDEBUG_KOIOS   ylog_upoint  ("b_scrp"    , b_scrp);
   --rce;  if (b_scrp       == NULL) {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   UDEBUG_KOIOS   ylog_upoint  ("r_dittoing", r_dittoing);
   --rce;  if (r_dittoing   == NULL) {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   UDEBUG_KOIOS   ylog_upoint  ("r_dmark"   , r_dmark);
   --rce;  if (r_dmark      == NULL) {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   UDEBUG_KOIOS   ylog_upoint  ("r_ditto"   , r_ditto);
   --rce;  if (r_ditto      == NULL) {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   UDEBUG_KOIOS   ylog_upoint  ("r_dline"   , r_dline);
   --rce;  if (r_dline      == NULL) {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(quick-out)----------------------*/
   UDEBUG_KOIOS   ylog_uchar   ("dittoing"  , *r_dittoing);
   if (*r_dittoing  != 'y') {
      UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
      return 0;
   }
   UDEBUG_KOIOS   ylog_upoint  ("s_file_sav", s_fmain);
   --rce;  if (s_fmain == NULL) {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   UDEBUG_KOIOS   ylog_upoint  ("s_file_dit", s_fditto);
   --rce;  if (s_fditto == NULL) {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(reset ditto)--------------------*/
   *r_dittoing = '-';
   *r_dmark    = '-';
   *r_ditto    = -1;
   /*---(swap files)---------------------*/
   UDEBUG_KOIOS   ylog_unote   ("swap file for script");
   *b_scrp     = s_fmain;
   /*---(close detail report)------------*/
   UDEBUG_KOIOS   ylog_upoint  ("file_ditto", s_fditto);
   /*> rc = fclose (s_fditto);                                                        <*/
   rc = yenv_uclose_detail (__FILE__, __FUNCTION__, __LINE__, "???", &s_fditto);
   UDEBUG_KOIOS   ylog_uvalue  ("close"     , rc);
   --rce;  if (rc < 0 || s_fditto != NULL) {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(null closed pointers)-----------*/
   s_fditto    = NULL;
   s_fmain     = NULL;
   *r_dline    = -1;
   /*---(complete)-----------------------*/
   UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
   return 1;
}



/*====================------------------------------------====================*/
/*===----                    record reading support                    ----===*/
/*====================------------------------------------====================*/
static void  o___READING_________o () { return; }

char         /*-> handle line number updates ------------------------[ leaf --*/
DITTO_read_numbering    (char a_dittoing, int a_ditto, int *r_nline, int *r_dline)
{  /*---(return codes)-------------------*/
   /*
    *    <0  error
    *     0  not dittoing, parse normally
    *     1  dittoing, and parse normally
    *     2  dittoing, but no parsing, immediately read next line
    */
   /*---(locals)-----------+-----------+-*/
   char        rce         =  -10;
   /*---(header)-------------------------*/
   UDEBUG_KOIOS   ylog_uenter  (__FUNCTION__);
   /*---(defense)------------------------*/
   UDEBUG_KOIOS   ylog_upoint  ("r_nline"   , r_nline);
   --rce;  if (r_nline == NULL) {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   UDEBUG_KOIOS   ylog_upoint  ("r_dline"   , r_dline);
   --rce;  if (r_dline == NULL) {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(check for no ditto)-------------*/
   UDEBUG_KOIOS   ylog_uchar   ("a_dittoing", a_dittoing);
   if (a_dittoing != 'y') {
      UDEBUG_KOIOS   ylog_unote   ("not dittoing");
      ++(*r_nline);
      UDEBUG_KOIOS   ylog_uvalue  ("*r_nline"  , *r_nline);
      UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
      return 0;
   }
   /*---(update ditto line)--------------*/
   ++(*r_dline);
   UDEBUG_KOIOS   ylog_uvalue  ("*rdline"  , *r_dline);
   UDEBUG_KOIOS   ylog_uvalue  ("a_ditto"  , a_ditto);
   /*---(check for pre-ditto)------------*/
   if (*r_dline <   a_ditto) {
      UDEBUG_KOIOS   ylog_unote   ("pre-ditto source line (or original COND)");
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, 2);
      return 2;
   }
   /*---(dittoing)-----------------------*/
   UDEBUG_KOIOS   ylog_unote   ("in sweet spot");
   UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, 1);
   return 1;
}



/*====================------------------------------------====================*/
/*===----                    record parsing support                    ----===*/
/*====================------------------------------------====================*/
static void  o___PARSING_________o () { return; }

char
DITTO_parse__desc       (char a_prev [LEN_LONG], char r_desc [LEN_LONG])
{
   char        rce         =  -10;
   int         l           =    0;
   int         i           =    0;
   char        x_desc      [LEN_LONG]  = "[  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ";
   if (r_desc  == NULL)  return rce;
   l = strlen (a_prev);
   for (i = 0; i < l; ++i)  x_desc [i + 2] = a_prev [i];
   x_desc [l + 2] = ' ';
   x_desc [l + 3] = ']';
   strlcpy (r_desc, x_desc, LEN_LONG);
   return 0;
}

char
DITTO_parse__group      (char a_prev [LEN_LONG], char r_desc [LEN_LONG])
{
   char        rce         =  -10;
   int         l           =    0;
   int         i           =    0;
   char        x_desc      [LEN_LONG]  = "===[[ ===============================================================";
   if (a_prev  == NULL)  return rce;
   if (r_desc  == NULL)  return rce;
   if (strncmp (a_prev, "===[[ ", 6) == 0) {
      strlcpy (r_desc, a_prev, LEN_LONG);
      return 0;
   }
   l = strlen (a_prev);
   for (i = 0; i < l; ++i)  x_desc [i + 6] = a_prev [i];
   x_desc [l + 6] = ' ';
   x_desc [l + 7] = ']';
   x_desc [l + 8] = ']';
   strlcpy (r_desc, x_desc, LEN_LONG);
   return 1;
}

char
DITTO_parse_handler     (FILE **b_scrp, cchar a_nscrp [LEN_TITLE], int a_line, char a_runtype, char a_verb [LEN_LABEL], char a_vers, char a_recd [LEN_RECD], char *a_field, char r_desc [LEN_LONG], char *r_ditto, char *r_dittoing, char *r_dtarget, int *r_dstart, int *r_dline)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char       *q           = NULL;
   char        x_mark      =  '-';
   int         x_line      =   -1;
   char        t           [LEN_LABEL] = "";
   char        x_desc      [LEN_LONG]  = "";
   /*---(header)-------------------------*/
   UDEBUG_KOIOS   ylog_uenter  (__FUNCTION__);
   /*---(defense)------------------------*/
   UDEBUG_KOIOS   ylog_upoint  ("a_nscrp"    , a_nscrp);
   --rce;  if (a_nscrp     == NULL) {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   UDEBUG_KOIOS   ylog_uinfo   ("a_nscrp"    , a_nscrp);
   UDEBUG_KOIOS   ylog_upoint  ("a_verb"    , a_verb);
   --rce;  if (a_verb     == NULL) {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   UDEBUG_KOIOS   ylog_upoint  ("a_field"   , a_field);
   --rce;  if (a_field    == NULL) {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   UDEBUG_KOIOS   ylog_upoint  ("r_dittoing", r_dittoing);
   --rce;  if (r_dittoing == NULL) {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(default)------------------------*/
   if (r_ditto != NULL)  *r_ditto = '-';
   /*---(defense)------------------------*/
   UDEBUG_KOIOS   ylog_upoint  ("a_field"   , a_field);
   --rce;  if (a_field == NULL) {
      yerr_uerror ("%s:%d:0: error: COND/DITTO called with a null string", a_nscrp, a_line);
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   UDEBUG_KOIOS   ylog_uinfo   ("a_field"   , a_field);
   /*---(check for reset)----------------*/
   strcpy (t, a_verb);
   if (strstr (" SCRP SHARED " , t) != NULL) {
      UDEBUG_KOIOS   ylog_unote   ("found SCRP/SHARED, resetting dittos");
      DITTO_purge ();
      UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
      return 0;
   }
   /*---(quick-out)----------------------*/
   if (strstr (" COND DITTO " , t) == NULL) {
      UDEBUG_KOIOS   ylog_unote   ("this only applies to COND/DITTO");
      UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
      return 0;
   }
   /*---(check for marker)---------------*/
   q = strchr (a_field, '(');
   UDEBUG_KOIOS   ylog_upoint  ("q"         , q);
   --rce;  if (q == NULL) {
      if (strcmp (t, "DITTO") == 0) {
         yerr_uerror ("%s:%d:0: error: DITTO missing a valid identifier string (?)", a_nscrp, a_line);
         UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
         return rce;
      }
      UDEBUG_KOIOS   ylog_unote   ("no openning marker");
      UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
      return 0;
   }
   --rce;  if (q [1] == NULL) {
      yerr_uerror ("%s:%d:0: error: %s identifier did not follow ( marker", a_nscrp, a_line, t);
      UDEBUG_KOIOS   ylog_unote   ("no identifer");
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   --rce;  if (q [1] == ')') {
      yerr_uerror ("%s:%d:0: error: %s no identifier within () markers", a_nscrp, a_line, t);
      UDEBUG_KOIOS   ylog_unote   ("no identifer");
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   x_mark = q [1];
   UDEBUG_KOIOS   ylog_uchar   ("x_mark"     , x_mark);
   --rce;  if (q [2] != ')') {
      yerr_uerror ("%s:%d:0: error: %s identifier (%c) not followed by ) marker", a_nscrp, a_line, t, x_mark);
      UDEBUG_KOIOS   ylog_unote   ("no close marker");
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(validate marker)----------------*/
   x_line = DITTO__get (x_mark, x_desc);
   UDEBUG_KOIOS   ylog_uvalue  ("x_line"    , x_line);
   if (x_line < -1) {
      UDEBUG_KOIOS   ylog_unote   ("invalid identifier");
      yerr_uerror ("%s:%d:0: error: %s identifier (%c) not valid [0-9]", a_nscrp, a_line, t, x_mark);
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(handle condition)---------------*/
   --rce;  if (strcmp ("COND" , a_verb) == 0) {
      if (*r_dittoing != 'y') {
         UDEBUG_KOIOS   ylog_unote   ("handle cond");
         if (x_line > 0) {
            UDEBUG_KOIOS   ylog_unote   ("already set identifier (hidding)");
            yerr_uerror ("%s:%d:0: warning: COND identifier (%c) already set, now overwritten", a_nscrp, a_line, x_mark);
         }
         rc = DITTO__set_recd (x_mark, a_line, a_vers, a_recd);
         UDEBUG_KOIOS   ylog_uvalue  ("saving"    , rc);
         UDEBUG_KOIOS   ylog_uinfo   ("SET"       , DITTO__used ());
         if (r_ditto != NULL)  *r_ditto = x_mark;
      } else {
         UDEBUG_KOIOS   ylog_unote   ("cond () inside ditto, ignored");
      }
      if (r_ditto != NULL) {
         UDEBUG_KOIOS   ylog_uchar   ("*r_ditto"   , *r_ditto);
      }
      UDEBUG_KOIOS   ylog_uvalue  ("a_line"    , a_line);
   }
   /*---(handle ditto)-------------------*/
   --rce;  if (strcmp ("DITTO" , a_verb) == 0) {
      UDEBUG_KOIOS   ylog_unote   ("handle ditto");
      UDEBUG_KOIOS   ylog_uinfo   ("DITTO"     , DITTO__used ());
      if (x_line == -1) {
         UDEBUG_KOIOS   ylog_unote   ("unset identifier");
         yerr_uerror ("%s:%d:0: error: DITTO identifier (%c) not set by previous COND in current SCRP/SHARE", a_nscrp, a_line, x_mark);
         UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
         return rce;
      }
      /*> if (r_desc  != NULL)  snprintf (r_desc, LEN_LONG, "[ %-.70s ]", x_desc);  /+ nice stand-out formatting +/   <*/
      if (r_desc  != NULL)  DITTO_parse__desc (x_desc, r_desc);                 /* nice stand-out formatting */
      if (r_ditto  != NULL)  *r_ditto  = x_mark;
      if (a_runtype == G_RUN_CREATE || a_runtype == G_RUN_DEBUG) {
         UDEBUG_KOIOS   ylog_unote   ("begin ditto processing");
         UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
         if (r_dtarget != NULL)  *r_dtarget = x_mark;
         if (r_dstart  != NULL)  *r_dstart  = x_line;
         rc = DITTO_beg (b_scrp, a_nscrp, a_line, a_runtype, x_mark, x_line, r_dittoing, r_ditto, r_dtarget, r_dstart, r_dline);
         if (rc >= 0)  rc = 1;
         return rc;
      }
      UDEBUG_KOIOS   ylog_unote   ("using position");
      if (r_ditto != NULL) {
         UDEBUG_KOIOS   ylog_uchar   ("*r_ditto"   , *r_ditto);
      }
      UDEBUG_KOIOS   ylog_uvalue  ("a_line"    , a_line);
      UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
      return 1;
   }
   /*---(complete)-----------------------*/
   UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
   return 0;
}



/*====================------------------------------------====================*/
/*===----                        debugging support                     ----===*/
/*====================------------------------------------====================*/
static void  o___DEBUGGING_______o () { return; }

char*
DITTO__actuals          (void)
{
   /*---(locals)-------------------------*/
   int         i           =    0;
   /*---(dittos)-------------------------*/
   strcpy (g_print, "");
   for (i = 0; i < MAX_DITTO; ++i) {
      if      (s_dittos [i].d_called == 0)  g_print [i] = '·';
      else if (s_dittos [i].d_called >  9)  g_print [i] = '*';
      else                                  g_print [i] = '0' + s_dittos [i].d_called;
   }
   g_print [i] = '\0';
   /*---(complete)-----------------------*/
   return g_print;
}

char*
DITTO__used             (void)
{
   /*---(locals)-------------------------*/
   int         i           =    0;
   /*---(dittos)-------------------------*/
   strcpy (g_print, "");
   for (i = 0; i < MAX_DITTO; ++i) {
      if (s_dittos [i].d_line < 0)    g_print [i] = '-';
      else                            g_print [i] = '0' + i;
   }
   g_print [i] = '\0';
   /*---(complete)-----------------------*/
   return g_print;
}


