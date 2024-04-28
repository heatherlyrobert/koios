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
   int         line;
   char        desc    [LEN_LONG];
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
      s_dittos [i].line = -1;
      strcpy (s_dittos [i].desc, "");
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
   s_dittos [i].line = a_line;
   if (a_desc != NULL)  strlcpy (s_dittos [i].desc, a_desc, LEN_LONG);
   else                 strcpy  (s_dittos [i].desc, "");
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
   x_line = s_dittos [i].line;
   if (r_desc != NULL)  strlcpy (r_desc, s_dittos [i].desc, LEN_LONG);
   /*---(complete)-----------------------*/
   return x_line;
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
char         /*->  --------------------------------------------[ ´········· ]-*/ /*-ågcg´·Bá551á21·´K45´37·´1·D2Cá·æ¬å5á14··´#Z1á·1·····´···´····æ¬å>li··´4·2···2´····´····æ-*/
DITTO_beg               (FILE **b_scrp, cchar a_nscrp [LEN_TITLE], int a_line, char a_runtype, char a_mark, int a_ditto, char *r_dittoing, char *r_mark, char *r_dmark, int *r_ditto, int *r_dline)
{
   /*---(locals)-----------+-----------+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char       *p           = NULL;
   /*---(header)-------------------------*/
   DEBUG_UVER   yLOG_uenter  (__FUNCTION__);
   /*---(defense)------------------------*/
   DEBUG_UVER   yLOG_upoint  ("b_scrp"    , b_scrp);
   --rce;  if (b_scrp       == NULL) {
      DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_UVER   yLOG_upoint  ("a_nscrp"    , a_nscrp);
   --rce;  if (a_nscrp       == NULL) {
      DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_UVER   yLOG_upoint  ("r_dittoing", r_dittoing);
   --rce;  if (r_dittoing   == NULL) {
      DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_UVER   yLOG_upoint  ("r_mark"    , r_mark);
   --rce;  if (r_mark       == NULL) {
      DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_UVER   yLOG_upoint  ("r_dmark"   , r_dmark);
   --rce;  if (r_dmark      == NULL) {
      DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_UVER   yLOG_upoint  ("r_ditto"   , r_ditto);
   --rce;  if (r_ditto      == NULL) {
      DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_UVER   yLOG_upoint  ("r_dline"   , r_dline);
   --rce;  if (r_dline      == NULL) {
      DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(quick-out)----------------------*/
   DEBUG_UVER   yLOG_uchar   ("*r_dittoing", *r_dittoing);
   --rce;  if (*r_dittoing  == 'y') {
      yLOGS_err ("%s:%d:0: error: DITTO '%c' can not start as dittoing already active", a_nscrp, a_line, a_mark);
      DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(check mark)---------------------*/
   DEBUG_UVER   yLOG_uvalue  ("a_ditto"    , a_ditto);
   --rce;  if (a_ditto < 1) {
      DEBUG_UVER   yLOG_unote   ("unset identifier");
      yLOGS_err ("%s:%d:0: error: DITTO '%c' not set by previous COND", a_nscrp, a_line, a_mark);
      DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(handle runtype)-----------------*/
   if (a_runtype != G_RUN_CREATE && a_runtype != G_RUN_DEBUG) {
      DEBUG_UVER   yLOG_unote   ("create/debug mode, ditto_beg processing done");
      *r_ditto = a_ditto;
      *r_mark  = a_mark;
      DEBUG_UVER   yLOG_uexit   (__FUNCTION__);
      return 0;
   }
   /*---(check files)--------------------*/
   DEBUG_UVER   yLOG_upoint  ("*b_scrp"   , *b_scrp);
   --rce;  if (*b_scrp      == NULL) {
      DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_UVER   yLOG_upoint  ("s_fditto"  , s_fditto);
   --rce;  if (s_fditto     != NULL) {
      DEBUG_UVER   yLOG_unote   ("already have second version open");
      DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(reopen file)--------------------*/
   rc = READ_open (a_nscrp, 'r', &s_fditto, r_dline);
   DEBUG_UVER   yLOG_uvalue  ("open"      , rc);
   DEBUG_UVER   yLOG_upoint  ("s_fditto"  , s_fditto);
   --rce;  if (rc < 0 || s_fditto == NULL) {
      DEBUG_UVER   yLOG_unote   ("scrp file, can not re-open script file");
      DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(swap files)---------------------*/
   DEBUG_UVER   yLOG_unote   ("swap file for script");
   s_fmain      = *b_scrp;
   *b_scrp      = s_fditto;
   *r_ditto     = a_ditto;
   *r_mark      = a_mark;
   *r_dmark     = a_mark;
   *r_dline     = 0;
   *r_dittoing  = 'y';
   /*---(complete)-----------------------*/
   DEBUG_UVER   yLOG_uexit   (__FUNCTION__);
   return 1;
}

char
DITTO_end               (FILE **b_scrp, char *r_dittoing, char *r_dmark, int *r_ditto, int *r_dline)
{
   /*---(locals)-----------+-----------+-*/
   char        rce         =  -10;
   char        rc          =    0;
   /*---(header)-------------------------*/
   DEBUG_UVER   yLOG_uenter  (__FUNCTION__);
   /*---(defense)------------------------*/
   DEBUG_UVER   yLOG_upoint  ("b_scrp"    , b_scrp);
   --rce;  if (b_scrp       == NULL) {
      DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_UVER   yLOG_upoint  ("r_dittoing", r_dittoing);
   --rce;  if (r_dittoing   == NULL) {
      DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_UVER   yLOG_upoint  ("r_dmark"   , r_dmark);
   --rce;  if (r_dmark      == NULL) {
      DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_UVER   yLOG_upoint  ("r_ditto"   , r_ditto);
   --rce;  if (r_ditto      == NULL) {
      DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_UVER   yLOG_upoint  ("r_dline"   , r_dline);
   --rce;  if (r_dline      == NULL) {
      DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(quick-out)----------------------*/
   DEBUG_UVER   yLOG_uchar   ("dittoing"  , *r_dittoing);
   if (*r_dittoing  != 'y') {
      DEBUG_UVER   yLOG_uexit   (__FUNCTION__);
      return 0;
   }
   DEBUG_UVER   yLOG_upoint  ("s_file_sav", s_fmain);
   --rce;  if (s_fmain == NULL) {
      DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_UVER   yLOG_upoint  ("s_file_dit", s_fditto);
   --rce;  if (s_fditto == NULL) {
      DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(reset ditto)--------------------*/
   *r_dittoing = '-';
   *r_dmark    = '-';
   *r_ditto    = -1;
   /*---(swap files)---------------------*/
   DEBUG_UVER   yLOG_unote   ("swap file for script");
   *b_scrp     = s_fmain;
   /*---(close detail report)------------*/
   DEBUG_UVER   yLOG_upoint  ("file_ditto", s_fditto);
   /*> rc = fclose (s_fditto);                                                        <*/
   rc = READ_close (&s_fditto);
   DEBUG_UVER   yLOG_uvalue  ("close"     , rc);
   --rce;  if (rc < 0 || s_fditto != NULL) {
      DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(null closed pointers)-----------*/
   s_fditto    = NULL;
   s_fmain     = NULL;
   *r_dline    = -1;
   /*---(complete)-----------------------*/
   DEBUG_UVER   yLOG_uexit   (__FUNCTION__);
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
   DEBUG_UVER   yLOG_uenter  (__FUNCTION__);
   /*---(defense)------------------------*/
   DEBUG_UVER   yLOG_upoint  ("r_nline"   , r_nline);
   --rce;  if (r_nline == NULL) {
      DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_UVER   yLOG_upoint  ("r_dline"   , r_dline);
   --rce;  if (r_dline == NULL) {
      DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(check for no ditto)-------------*/
   DEBUG_UVER   yLOG_uchar   ("a_dittoing", a_dittoing);
   if (a_dittoing != 'y') {
      DEBUG_UVER   yLOG_unote   ("not dittoing");
      ++(*r_nline);
      DEBUG_UVER   yLOG_uvalue  ("*r_nline"  , *r_nline);
      DEBUG_UVER   yLOG_uexit   (__FUNCTION__);
      return 0;
   }
   /*---(update ditto line)--------------*/
   ++(*r_dline);
   DEBUG_UVER   yLOG_uvalue  ("*rdline"  , *r_dline);
   DEBUG_UVER   yLOG_uvalue  ("a_ditto"  , a_ditto);
   /*---(check for pre-ditto)------------*/
   if (*r_dline <   a_ditto) {
      DEBUG_UVER   yLOG_unote   ("pre-ditto source line (or original COND)");
      DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, 2);
      return 2;
   }
   /*---(dittoing)-----------------------*/
   DEBUG_UVER   yLOG_unote   ("in sweet spot");
   DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, 1);
   return 1;
}



/*====================------------------------------------====================*/
/*===----                    record parsing support                    ----===*/
/*====================------------------------------------====================*/
static void  o___PARSING_________o () { return; }

char
DITTO_parse_handler     (FILE **b_scrp, cchar a_nscrp [LEN_TITLE], int a_line, char a_runtype, char a_verb [LEN_LABEL], char a_vers, char a_recd [LEN_RECD], char *a_field, char r_desc [LEN_LONG], char *r_dittoing, char *r_mark, char *r_dmark, int *r_ditto, int *r_dline)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char       *q           = NULL;
   char        m           =  '-';
   int         n           =   -1;
   char        t           [LEN_LABEL] = "";
   char        x_desc      [LEN_LONG]  = "";
   /*---(header)-------------------------*/
   DEBUG_UVER   yLOG_uenter  (__FUNCTION__);
   /*---(defense)------------------------*/
   DEBUG_UVER   yLOG_upoint  ("a_nscrp"    , a_nscrp);
   --rce;  if (a_nscrp     == NULL) {
      DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_UVER   yLOG_uinfo   ("a_nscrp"    , a_nscrp);
   DEBUG_UVER   yLOG_upoint  ("a_verb"    , a_verb);
   --rce;  if (a_verb     == NULL) {
      DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_UVER   yLOG_upoint  ("a_field"   , a_field);
   --rce;  if (a_field    == NULL) {
      DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_UVER   yLOG_upoint  ("r_dittoing", r_dittoing);
   --rce;  if (r_dittoing == NULL) {
      DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(default)------------------------*/
   if (r_mark != NULL)  *r_mark = '-';
   /*---(defense)------------------------*/
   DEBUG_UVER   yLOG_upoint  ("a_field"   , a_field);
   --rce;  if (a_field == NULL) {
      yLOGS_err ("%s:%d:1: error: COND/DITTO called with a null string", a_nscrp, a_line);
      DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_UVER   yLOG_uinfo   ("a_field"   , a_field);
   /*---(check for reset)----------------*/
   strcpy (t, a_verb);
   if (strstr (" SCRP SHARED " , t) != NULL) {
      DEBUG_UVER   yLOG_unote   ("found SCRP/SHARED, resetting dittos");
      DITTO_purge ();
      DEBUG_UVER   yLOG_uexit   (__FUNCTION__);
      return 0;
   }
   /*---(quick-out)----------------------*/
   if (strstr (" COND DITTO " , t) == NULL) {
      DEBUG_UVER   yLOG_unote   ("this only applies to COND/DITTO");
      DEBUG_UVER   yLOG_uexit   (__FUNCTION__);
      return 0;
   }
   /*---(check for marker)---------------*/
   q = strchr (a_field, '(');
   DEBUG_UVER   yLOG_upoint  ("q"         , q);
   --rce;  if (q == NULL) {
      if (strcmp (t, "DITTO") == 0) {
         yLOGS_err ("%s:%d:1: error: DITTO missing a valid identifier string (?)", a_nscrp, a_line);
         DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
         return rce;
      }
      DEBUG_UVER   yLOG_unote   ("no openning marker");
      DEBUG_UVER   yLOG_uexit   (__FUNCTION__);
      return 0;
   }
   --rce;  if (q [1] == NULL) {
      yLOGS_err ("%s:%d:1: error: %s identifier did not follow ( marker", a_nscrp, a_line, t);
      DEBUG_UVER   yLOG_unote   ("no identifer");
      DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   --rce;  if (q [1] == ')') {
      yLOGS_err ("%s:%d:1: error: %s no identifier within () markers", a_nscrp, a_line, t);
      DEBUG_UVER   yLOG_unote   ("no identifer");
      DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   m = q [1];
   DEBUG_UVER   yLOG_uchar   ("m"          , m);
   --rce;  if (q [2] != ')') {
      yLOGS_err ("%s:%d:1: error: %s identifier å%cæ not followed by ) marker", a_nscrp, a_line, t, m);
      DEBUG_UVER   yLOG_unote   ("no close marker");
      DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(validate marker)----------------*/
   n  = DITTO__get (m, x_desc);
   DEBUG_UVER   yLOG_uvalue  ("n"         , n);
   if (n < -1) {
      DEBUG_UVER   yLOG_unote   ("invalid identifier");
      yLOGS_err ("%s:%d:1: error: %s identifier å%cæ not valid [0-9]", a_nscrp, a_line, t, m);
      DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(handle condition)---------------*/
   --rce;  if (strcmp ("COND" , a_verb) == 0) {
      if (*r_dittoing != 'y') {
         DEBUG_UVER   yLOG_unote   ("handle cond");
         if (n > 0) {
            DEBUG_UVER   yLOG_unote   ("already set identifier (hidding)");
            yLOGS_err ("%s:%d:1: warning: COND identifier å%cæ already set, now overwritten", a_nscrp, a_line, m);
         }
         rc = DITTO__set_recd (m, a_line, a_vers, a_recd);
         DEBUG_UVER   yLOG_uvalue  ("saving"    , rc);
         DEBUG_UVER   yLOG_uinfo   ("SET"       , DITTO__used ());
         if (r_mark != NULL)  *r_mark = m;
      } else {
         DEBUG_UVER   yLOG_unote   ("cond () inside ditto, ignored");
      }
      if (r_mark != NULL) {
         DEBUG_UVER   yLOG_uchar   ("*r_mark"   , *r_mark);
      }
      DEBUG_UVER   yLOG_uvalue  ("a_line"    , a_line);
   }
   /*---(handle ditto)-------------------*/
   --rce;  if (strcmp ("DITTO" , a_verb) == 0) {
      DEBUG_UVER   yLOG_unote   ("handle ditto");
      DEBUG_UVER   yLOG_uinfo   ("DITTO"     , DITTO__used ());
      if (n == -1) {
         DEBUG_UVER   yLOG_unote   ("unset identifier");
         yLOGS_err ("%s:%d:1: error: DITTO identifier å%cæ not set by previous COND", a_nscrp, a_line, m);
         DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
         return rce;
      }
      if (r_desc  != NULL)  snprintf (r_desc, LEN_LONG, "[ %-.70s ]", x_desc);  /* nice stand-out formatting */
      if (r_mark  != NULL)  *r_mark  = m;
      if (a_runtype == G_RUN_CREATE || a_runtype == G_RUN_DEBUG) {
         DEBUG_UVER   yLOG_unote   ("begin ditto processing");
         DEBUG_UVER   yLOG_uexit   (__FUNCTION__);
         if (r_ditto != NULL)  *r_ditto = n;
         if (r_dmark != NULL)  *r_dmark = m;
         rc = DITTO_beg (b_scrp, a_nscrp, a_line, a_runtype, m, n, r_dittoing, r_mark, r_dmark, r_ditto, r_dline);
         if (rc >= 0)  rc = 1;
         return rc;
      }
      DEBUG_UVER   yLOG_unote   ("using position");
      if (r_mark != NULL) {
         DEBUG_UVER   yLOG_uchar   ("*r_mark"   , *r_mark);
      }
      DEBUG_UVER   yLOG_uvalue  ("a_line"    , a_line);
      DEBUG_UVER   yLOG_uexit   (__FUNCTION__);
      return 1;
   }
   /*---(complete)-----------------------*/
   DEBUG_UVER   yLOG_uexit   (__FUNCTION__);
   return 0;
}



/*====================------------------------------------====================*/
/*===----                        debugging support                     ----===*/
/*====================------------------------------------====================*/
static void  o___DEBUGGING_______o () { return; }

char*
DITTO__used             (void)
{
   /*---(locals)-------------------------*/
   int         i           =    0;
   /*---(dittos)-------------------------*/
   for (i = 0; i < MAX_DITTO; ++i) {
      if (s_dittos [i].line < 0)    g_print [i] = '-';
      else                          g_print [i] = '0' + i;
   }
   g_print [i] = '\0';
   /*---(complete)-----------------------*/
   return g_print;
}


