/*===============================[[ beg-code ]]===============================*/
#include    "koios.h"        /* LOCAL  : main header                          */



static  int   s_ditto    = -1;
static  char  s_dittoing = '-';
static  FILE *s_file_save;
static  FILE *s_file_ditto;
static  int   s_lineno   =   0;

static  int   s_dittos [26] = { -1 };

tVERB       g_verbs [MAX_VERB] = {
   /* --------------   ---------------------------------------   -  */
   { "PREP"         , "preparation before testing"            , '2',  0,  0, CONV_prep     , CODE_prep     },
   { "incl"         , "c header inclusion"                    , '3',  0,  0, CONV_incl     , CODE_incl     },
   { "#>"           , "script internal comments"              , 'c',  0,  0, CONV_comment  , NULL          },
   /* --------------   --------------------------------------- */
   { "SCRP"         , "test script"                           , '3',  0,  0, CONV_scrp     , CODE_scrp     },
   { "SECT"         , "grouping of scripts"                   , '2',  0,  0, CONV_sect     , CODE_sect     },
   { "SHARED"       , "shared code between scripts"           , '2',  0,  0, CONV_shared   , CODE_shared   },
   /* --------------   --------------------------------------- */
   { "GROUP"        , "grouping of conditions"                , '2',  0,  0, CONV_group    , CODE_group    },
   { "COND"         , "test condition"                        , '2',  0,  0, CONV_cond     , CODE_cond     },
   { "DITTO"        , "repeated test condition"               , '1',  0,  0, CONV_ditto    , NULL          },
   { "REUSE"        , "inclusion of shared code"              , '1',  0,  0, CONV_reuse    , CODE_reuse    },
   /* --------------   --------------------------------------- */
   { "exec"         , "function execution"                    , 'f',  0,  0, CONV_exec     , CODE_exec     },
   { "get"          , "unit test accessor retrieval"          , 'f',  0,  0, CONV_exec     , CODE_exec     },
   { "echo"         , "test a variable directly"              , 'f',  0,  0, CONV_echo     , CODE_echo     },
   /* --------------   --------------------------------------- */
   { "mode"         , "set pass or forced_fail mode"          , '2',  0,  0, CONV_mode     , CODE_mode     },
   { "code"         , "insert c code"                         , 'p',  0,  0, CONV_code     , CODE_code     },
   { "load"         , "place data into stdin"                 , 'P',  0,  0, CONV_load     , CODE_load     },
   { "system"       , "execute shell code"                    , 'p',  0,  0, CONV_code     , CODE_system   },
   /* --------------   --------------------------------------- */
   { "WAVE"         , "testing wave"                          , '2',  0,  0, NULL          , NULL          },
   { "stage"        , "testing stage"                         , '2',  0,  0, NULL          , NULL          },
   /* --------------   --------------------------------------- */
   { "----"         , "end-of-entries"                        , '-',  0,  0, NULL          , NULL          },
   /* --------------   --------------------------------------- */
};



/*====================------------------------------------====================*/
/*===----                    for ditting lines                         ----===*/
/*====================------------------------------------====================*/
static void      o___DITTOING________________o (void) {;}

char
SCRP_ditto__clear       (void)
{
   int         i           =    0;
   for (i = 0; i < 26; ++i) {
      s_dittos [i] = -1;
   }
   return 0;
}

char
SCRP_ditto__set         (char a_mark)
{
   char        rce         =  -10;
   --rce;  if (s_file_ditto != NULL)          return rce;
   --rce;  if (a_mark < 'A' || a_mark > 'Z')  return rce;
   s_dittos [a_mark - 'A'] = my.n_line;
   return 0;
}

char
SCRP_ditto__check       (char *p, char a_set)
{
   /*---(locals)-----------+-----------+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char       *q           = NULL;
   /*---(header)-------------------------*/
   DEBUG_INPT   yLOG_senter  (__FUNCTION__);
   /*---(default)------------------------*/
   my.mark = '-';
   /*---(defense)------------------------*/
   DEBUG_INPT   yLOG_spoint  (p);
   --rce;  if (strcmp ("COND", g_verbs [my.indx].name) != 0) {
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(find cond lines)----------------*/
   q = strchr (p, '(');
   DEBUG_INPT   yLOG_spoint  (q);
   --rce;  if (q == NULL) {
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   --rce;  if (q [2] != ')') {
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   --rce;  if (strchr ("ABCDEFGHIJKLMNOPQRSTUVWXYZ", q [1]) == NULL) {
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(find our cond)------------------*/
   DEBUG_INPT   yLOG_schar   (q [1]);
   if (a_set == 'y')  rc = SCRP_ditto__set (q [1]);
   my.mark = q [1];
   /*---(complete)-----------------------*/
   DEBUG_INPT   yLOG_sexit   (__FUNCTION__);
   return rc;
}

char
SCRP_ditto__beg         (char *a_verb)
{
   /*---(locals)-----------+-----------+-*/
   char        rce         =  -10;
   char       *p           = NULL;
   /*---(header)-------------------------*/
   DEBUG_INPT   yLOG_enter   (__FUNCTION__);
   /*---(default)------------------------*/
   my.mark = '-';
   /*---(defense)------------------------*/
   DEBUG_INPT   yLOG_spoint  (a_verb);
   --rce;  if (a_verb == NULL) {
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(parse ditto line)---------------*/
   p = strstr (a_verb, "DITTO (");
   DEBUG_INPT   yLOG_spoint  (p);
   --rce;  if (p == NULL) {
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_INPT   yLOG_sint    (p - a_verb);
   --rce;  if (p - a_verb > 20) {
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(save mark)----------------------*/
   --rce;  if (p [7] < 'A' || p [7] > 'Z') {
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   --rce;  if (s_dittos [p [7] - 'A'] < 1) {
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   s_ditto = p [7] - 'A';
   my.mark = p [7];
   /*---(reopen file)--------------------*/
   s_file_ditto = fopen (my.n_scrp, "r");
   DEBUG_INPT   yLOG_point   ("refile*"   , s_file_ditto);
   --rce;  if (my.f_scrp == NULL) {
      DEBUG_TOPS   yLOG_fatal   ("scrp file, can not open script file");
      DEBUG_TOPS   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(swap files)---------------------*/
   DEBUG_INPT   yLOG_note    ("swap file for script");
   s_file_save  = my.f_scrp;
   my.f_scrp = s_file_ditto;
   s_lineno     = 0;
   s_dittoing   = 'y';
   /*---(complete)-----------------------*/
   DEBUG_INPT   yLOG_exit    (__FUNCTION__);
   return 0;
}

char
SCRP_ditto__end         (void)
{
   /*---(locals)-----------+-----------+-*/
   char        rce         =  -10;
   char        rc          =    0;
   /*---(header)-------------------------*/
   DEBUG_INPT   yLOG_enter   (__FUNCTION__);
   /*---(reset ditto)--------------------*/
   s_ditto    = -1;
   s_dittoing = '-';
   /*---(swap files)---------------------*/
   DEBUG_INPT   yLOG_note    ("swap file for script");
   my.f_scrp = s_file_save;
   /*---(close detail report)------------*/
   DEBUG_INPT   yLOG_point   ("file_ditto", s_file_ditto);
   rc = fclose (s_file_ditto);
   --rce;  if (rc != 0) {
      DEBUG_TOPS   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(null closed pointers)-----------*/
   s_file_ditto = NULL;
   s_file_save  = NULL;
   s_lineno     = 0;
   /*---(complete)-----------------------*/
   DEBUG_INPT   yLOG_exit    (__FUNCTION__);
   return 0;
}

char*
SCRP_ditto_used         (void)
{
   int         i           =    0;
   for (i = 0; i < 26; ++i) {
      if (s_dittos [i] < 0)    my.d_used [i] = '-';
      else                     my.d_used [i] = 'A' + i;
   }
   my.d_used [i] = '\0';
   return my.d_used;
}



/*====================------------------------------------====================*/
/*===----                      reading the file                        ----===*/
/*====================------------------------------------====================*/
static void      o___READING_________________o (void) {;}

char         /*--> open script file ----------------------[ leaf   [ ------ ]-*/
SCRP_open          (void)
{
   /*---(locals)-----------+-----------+-*/
   char        rce         = -10;           /* return code for errors         */
   /*---(header)-------------------------*/
   DEBUG_TOPS   yLOG_enter   (__FUNCTION__);
   /*---(already open)-------------------*/
   DEBUG_OUTP   yLOG_info    ("n_scrp"    , my.n_scrp);
   DEBUG_OUTP   yLOG_point   ("f_scrp"    , my.f_scrp);
   --rce;  if (my.f_scrp != NULL) {
      DEBUG_TOPS   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_OUTP   yLOG_info    ("n_wave"    , my.n_wave);
   DEBUG_OUTP   yLOG_point   ("f_wave"    , my.f_wave);
   --rce;  if (my.f_wave != NULL) {
      DEBUG_TOPS   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(open configuration)-------------*/
   DEBUG_INPT   yLOG_point   ("name"      , my.n_scrp);
   my.f_scrp = fopen (my.n_scrp, "rt");
   DEBUG_INPT   yLOG_point   ("file*"     , my.f_scrp);
   --rce;  if (my.f_scrp == NULL) {
      DEBUG_TOPS   yLOG_fatal   ("scrp file, can not open script file");
      DEBUG_TOPS   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_INPT   yLOG_note    ("script file open");
   my.n_line = 0;
   SCRP_ditto__clear ();
   /*---(open wave file)-----------------*/
   /*> printf ("n_wave = [%s]\n", my.n_wave);                                         <*/
   my.f_wave = fopen (my.n_wave, "wt");
   DEBUG_OUTP   yLOG_point   ("f_wave"    , my.f_wave);
   --rce;  if (my.f_wave == NULL) {
      DEBUG_TOPS   yLOG_fatal   ("can not open wave file");
      fclose (my.f_scrp);
      my.f_scrp = NULL;
      DEBUG_TOPS   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   DEBUG_OUTP   yLOG_note    ("wave file open");
   /*---(complete)-----------------------*/
   DEBUG_TOPS   yLOG_exit    (__FUNCTION__);
   return 0;
}

char
WAVE_printf             (char *a_format, ...)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   va_list     x_vlist;
   /*---(defense)------------------------*/
   --rce;  if (my.f_wave == NULL)    return rce;
   --rce;  if (a_format  == NULL)    return rce;
   /*---(write)--------------------------*/
   va_start (x_vlist, a_format);
   vfprintf (my.f_wave, a_format, x_vlist);
   va_end   (x_vlist);
   fflush   (my.f_wave);
   /*---(complete)-------------------------*/
   return 0;
}

char         /*--> close script file ---------------------[ ------ [ ------ ]-*/
SCRP_close         (void)
{
   /*---(locals)-----------+-----------+-*/
   char        rc          = 0;
   char        rce         = -10;
   /*---(header)-------------------------*/
   DEBUG_TOPS   yLOG_enter   (__FUNCTION__);
   /*---(close detail report)------------*/
   DEBUG_INPT   yLOG_point   ("*f_scrp", my.f_scrp);
   --rce;  if (my.f_scrp == NULL) {
      DEBUG_TOPS   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   rc = fclose (my.f_scrp);
   --rce;  if (rc != 0) {
      DEBUG_TOPS   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(close wave file)----------------*/
   DEBUG_INPT   yLOG_point   ("*f_wave", my.f_wave);
   --rce;  if (my.f_wave == NULL) {
      DEBUG_TOPS   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   rc = fclose (my.f_wave);
   --rce;  if (rc != 0) {
      DEBUG_TOPS   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(ground pointer)-----------------*/
   my.f_scrp = NULL;
   my.f_wave = NULL;
   /*---(complete)-----------------------*/
   DEBUG_TOPS   yLOG_exit    (__FUNCTION__);
   return 0;
}

char         /*--> clean a script record -----------------[ leaf   [ ------ ]-*/
SCRP_clear         (void)
{
   /*---(header)-------------------------*/
   DEBUG_INPT   yLOG_senter  (__FUNCTION__);
   /*---(save value)---------------------*/
   strlcpy (my.last, my.verb, LEN_LABEL);
   /*---(input vars)---------------------*/
   my.verb        [0] = '\0';
   my.p_conv          = NULL;
   my.p_code          = NULL;
   my.verb        [0] = '\0';
   my.spec            = '-';
   my.status          = '-';
   my.vers        [0] = '\0';
   my.desc        [0] = '\0';
   my.meth        [0] = '\0';
   my.args        [0] = '\0';
   my.test        [0] = '\0';
   my.expe        [0] = '\0';
   my.type            = '-';
   my.retn        [0] = '\0';
   my.code        [0] = '\0';
   my.refn        [0] = '\0';
   /*---(special marking)----------------*/
   my.stage       [0] = '\0';
   my.share           = '-';
   my.mark            = '-';
   /*---(working vars)-------------------*/
   my.syst        [0] = '\0';
   my.disp        [0] = '\0';
   my.load        [0] = '\0';
   /*---(complete)-----------------------*/
   DEBUG_INPT   yLOG_sexit   (__FUNCTION__);
   return 0;
}

char         /*--> read script record --------------------[ leaf   [ ------ ]-*/
SCRP_read          (void)
{
   /*---(locals)-----------+-----------+-*/
   int         rc          = 0;             /* generic return code            */
   char        rce         = -10;           /* return code for errors         */
   char        x_recd      [LEN_RECD];
   int         x_len       = 0;             /* input record length            */
   char        x_temp      [20];
   /*---(header)-------------------------*/
   DEBUG_INPT   yLOG_enter   (__FUNCTION__);
   DEBUG_INPT   yLOG_point   ("*scrp"     , my.f_scrp);
   /*---(default)------------------------*/
   strcpy (my.recd, "");
   /*---(defense)------------------------*/
   --rce;  if (my.f_scrp == NULL) {
      DEBUG_INPT   yLOG_fatal   ("scrp file, file not open");
      DEBUG_INPT   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   if (feof (my.f_scrp)) {
      DEBUG_INPT   yLOG_note    ("already at end of file");
      DEBUG_INPT   yLOG_exit    (__FUNCTION__);
      return 0;
   }
   /*---(initialize)---------------------*/
   DEBUG_INPT   yLOG_note    ("initialize my.recd");
   my.recd [0] = '\0';
   /*---(read for a good record)---------*/
   --rce;
   while (1) {
      /*---(read next)-------------------*/
      DEBUG_INPT   yLOG_note    ("read script file");
      fgets (x_recd, LEN_RECD, my.f_scrp);
      /*> printf ("record = %2d[%s]\n", strlen (x_recd), x_recd);                     <*/
      if (feof (my.f_scrp)) {
         DEBUG_INPT   yLOG_note    ("hit end of file");
         DEBUG_INPT   yLOG_exit    (__FUNCTION__);
         return 0;
      }
      if (s_dittoing == '-') ++my.n_line;
      else  {
         ++s_lineno;
         if (s_lineno <  s_dittos [s_ditto]) continue;
      }
      DEBUG_INPT   yLOG_value   ("line#"     , my.n_line);
      /*---(filter)----------------------*/
      x_len = strllen (x_recd, LEN_RECD);
      x_recd [--x_len] = '\0';
      if (x_recd [0] == '\0') {
         DEBUG_INPT   yLOG_note    ("empty, skipping");
         if (s_dittoing != '-')  SCRP_ditto__end ();
         else                    ++my.n_empty;
         continue;
      }
      if (x_recd [0] == '#' && x_recd [1] != '>') {
         DEBUG_INPT   yLOG_note    ("comment, skipping");
         if (s_dittoing != '-')  SCRP_ditto__end ();
         else                    ++my.n_comment;
         continue;
      }
      DEBUG_INPT   yLOG_value   ("length"    , x_len);
      if (x_len <=  5)  {
         DEBUG_INPT   yLOG_note    ("too short, skipping");
         if (s_dittoing != '-')  SCRP_ditto__end ();
         else                    ++my.n_short;
         continue;
      }
      /*---(translate delayed chars)-----*/
      strlundelay (x_recd, LEN_RECD);
      /*---(copy)------------------------*/
      DEBUG_INPT   yLOG_note    ("save copy of source record");
      strlcpy (my.recd, x_recd, LEN_RECD);
      my.len   = x_len;
      ++my.n_recd;
      break;
   }
   DEBUG_INPT   yLOG_note    ("got a good record");
   /*---(complete)-----------------------*/
   DEBUG_INPT   yLOG_exit    (__FUNCTION__);
   return 1;
}

char
SCRP__limits            (char *a_min, char *a_max)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   /*---(defense)------------------------*/
   --rce;  if (a_min == NULL)  return rce;
   --rce;  if (a_max == NULL)  return rce;
   /*---(defaults)-----------------------*/
   *a_min = 0;
   *a_max = 0;
   /*---(process)------------------------*/
   --rce;  switch (my.spec) {
   case '1' :  *a_min = 1;  *a_max = 1;    break;
   case 'c' :  *a_min = 1;  *a_max = 1;    break;
   case '2' :  *a_min = 2;  *a_max = 2;    break;
   case '3' :  *a_min = 3;  *a_max = 3;    break;
   case 'P' :  *a_min = 4;  *a_max = 4;    break;
   case 'p' :  *a_min = 4;  *a_max = 4;    break;
   case 'f' :  *a_min = 6;  *a_max = 8;    break;
   default  :  return rce;                 break;
   }
   /*---(complete)-----------------------*/
   return 0;
}

char         /*--> parse out current records -------------[ leaf   [ ------ ]-*/
SCRP__current      (char *a_first)
{
   /*---(locals)-----------+-----------+-*/
   int         rc          = 0;             /* generic return code            */
   char        rce         = -10;           /* return code for errors         */
   int         i           = 0;
   char       *p;
   char       *q           = "";
   char        x_min       =    0;
   char        x_max       =    0;
   /*---(header)-------------------------*/
   DEBUG_INPT   yLOG_enter   (__FUNCTION__);
   /*---(read fields)--------------------*/
   DEBUG_INPT   yLOG_char    ("spec"      , my.spec);
   rc = SCRP__limits (&x_min, &x_max);
   DEBUG_INPT   yLOG_complex ("limits"    , "%4d rc, %d min, %d max", rc, x_min, x_max);
   --rce;  if (rc < 0) {
      yURG_error ("%s:%d:1: error: can not identify %s spec limits", my.n_scrp, my.n_line, my.verb);
      DEBUG_INPT   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   if (my.spec == '1') {
      DEBUG_INPT   yLOG_note    ("one field required and already read as verb");
      DEBUG_INPT   yLOG_exit    (__FUNCTION__);
      return 0;  /* ditto type */
   }
   p = a_first;
   for (i = 2; i < 20; ++i) {
      /*---(clear spacer bars)-----------*/
      if (p [0] == '-') {
         if (strncmp (p, "- - -", 5) == 0)    p [0] = '\0';
         if (strncmp (p, "-----", 5) == 0)    p [0] = '\0';
         if (p [1] == '\0')                   p [0] = '\0';
      }
      /*---(handle fields)---------------*/
      switch (i) {
      case  2 :   strlcpy (my.desc      , p, LEN_LONG );
                  DEBUG_INPT   yLOG_info    ("desc"      , my.desc);
                  strltrim (my.desc, ySTR_SINGLE, LEN_LONG);
                  break;
      case  3 :   if (my.spec != 'p') {
                     strlcpy (my.meth      , p, LEN_DESC );
                     DEBUG_INPT   yLOG_info    ("meth"      , my.meth);
                  }
                  break;
      case  4 :   if (my.spec == 'P' || my.spec == 'p') {
                     strlcpy (my.code      , p, LEN_RECD);
                     DEBUG_INPT   yLOG_info    ("code"      , my.code);
                  } else {
                     strlcpy (my.args      , p, LEN_FULL);
                     strlcpy (my.code      , p, LEN_FULL);
                     DEBUG_INPT   yLOG_info    ("args"      , my.args);
                  }
                  break;
      case  5 :   strlcpy (my.test      , p, LEN_LABEL);
                  DEBUG_INPT   yLOG_info    ("test"      , my.test);
                  break;
      case  6 :   strlcpy (my.expe      , p, LEN_RECD);
                  DEBUG_INPT   yLOG_info    ("expe"      , my.expe);
                  break;
      case  7 :   my.type      = p [0];
                  if (my.type == '\0')  my.type = '-';
                  DEBUG_INPT   yLOG_char    ("type"      , my.type);
                  break;
      case  8 :   strlcpy (my.retn      , p, LEN_FULL);
                  DEBUG_INPT   yLOG_info    ("retn"      , my.retn);
                  break;
      }
      /*---(stop parsing summ records)---*/
      if (i >= x_max)    break;
      /*> if (i >= 2 && my.spec == '2')  break;  /+ organization types  +/            <* 
       *> if (i >= 3 && my.spec == '3')  break;  /+ organization types  +/            <* 
       *> if (i >= 4 && my.spec == 'P')  break;  /+ load type           +/            <* 
       *> if (i >= 4 && my.spec == 'p')  break;  /+ code/sys types      +/            <*/
      /*---(next record)-----------------*/
      DEBUG_INPT   yLOG_note    ("read next field");
      p = strtok (NULL  , q);
      --rce;  if (p == NULL) {
         DEBUG_INPT   yLOG_note    ("strtok came up empty");
         break;
      }
      strltrim (p, ySTR_BOTH, LEN_RECD);
   } 
   /*---(stop parsing summ records)---*/
   if (i < x_min) {
      yURG_error ("%s:%d:1: error: too few fields (%d) for %s, requires %d", my.n_scrp, my.n_line, i, my.verb, x_min);
      DEBUG_INPT   yLOG_complex ("too few"   , "%d actual < %d min", i, x_min);
      DEBUG_INPT   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }

   /*> switch (my.spec) {                                                             <* 
    *> case '1' : if (i <  1)  rc = rce;  break;                                      <* 
    *> case 'c' : if (i <  1)  rc = rce;  break;                                      <* 
    *> case '2' : if (i <  2)  rc = rce;  break;                                      <* 
    *> case '3' : if (i <  3)  rc = rce;  break;                                      <* 
    *> case 'P' : if (i <  4)  rc = rce;  break;                                      <* 
    *> case 'p' : if (i <  4)  rc = rce;  break;                                      <* 
    *> case 'f' : if (i <  6)  rc = rce;  break;                                      <* 
    *> }                                                                              <*/
   DEBUG_INPT   yLOG_exit    (__FUNCTION__);
   return 0;
}

char         /*--> parse out a v21 records ---------------[ leaf   [ ------ ]-*/
SCRP_vers21        (void)
{
   /*---(design notes)-------------------*/
   /*
    *   version 21 of the script fields moved the code/load/sys payload to
    *   the 4th field (from the 3rd) for strictly ascetheic reasons so it
    *   would be easier to read and edit the scrits.
    *
    */
   /*---(locals)-----------+-----------+-*/
   int         rc          = 0;             /* generic return code            */
   char        rce         = -10;           /* return code for errors         */
   int         i           = 0;
   char       *p;
   char       *q           = "";
   /*---(read fields)--------------------*/
   for (i = 2; i < 20; ++i) {
      DEBUG_INPT   yLOG_note    ("read next field");
      p = strtok (NULL  , q);
      --rce;  if (p == NULL) {
         DEBUG_INPT   yLOG_note    ("strtok came up empty");
         DEBUG_INPT   yLOG_exit    (__FUNCTION__);
         break;
      }
      strltrim (p, ySTR_BOTH, LEN_RECD);
      /*---(clear spacer bars)-----------*/
      if (p[0] == '-') {  /* begin careful to avoid negative numbers ;)) */
         switch (p[1]) {
         case ' '  :   /* catches "- - - - - - -" lines */
         case '-'  :   /* catches "-------------" lines */
         case '\0' :   /* catches "-" placeholder lines */
            p[0] = '\0';
            break;
         }
      }
      /*---(handle fields)---------------*/
      switch (i) {
      case  2 :   strlcpy (my.desc      , p, LEN_LONG );
                  DEBUG_INPT   yLOG_info    ("desc"      , my.desc);
                  break;
      case  3 :   if (my.spec != 'p') {
                     strlcpy (my.meth      , p, LEN_DESC );
                     DEBUG_INPT   yLOG_info    ("meth"      , my.meth);
                  }
                  break;
      case  4 :   if (my.spec == 'P' || my.spec == 'p') {
                     strlcpy (my.code      , p, LEN_RECD);
                     DEBUG_INPT   yLOG_info    ("code"      , my.code);
                  } else {
                     strlcpy (my.args      , p, LEN_FULL);
                     strlcpy (my.code      , p, LEN_FULL);
                     DEBUG_INPT   yLOG_info    ("args"      , my.args);
                  }
                  break;
      case  5 :   strlcpy (my.test      , p, LEN_LABEL);
                  DEBUG_INPT   yLOG_info    ("test"      , my.test);
                  break;
      case  6 :   strlcpy (my.expe      , p, LEN_RECD);
                  DEBUG_INPT   yLOG_info    ("expe"      , my.expe);
                  break;
      case  7 :   my.type      = p [0];
                  if (my.type == '\0')  my.type = '-';
                  DEBUG_INPT   yLOG_char    ("type"      , my.type);
                  break;
      case  8 :   strlcpy (my.retn      , p, LEN_FULL);
                  DEBUG_INPT   yLOG_info    ("retn"      , my.retn);
                  break;
      }
      /*---(stop parsing summ records)---*/
      if (i >= 2 && my.spec == '2')  break;  /* organization types  */
      if (i >= 3 && my.spec == '-')  break;  /* organization types  */
      if (i >= 4 && my.spec == 'P')  break;  /* load type           */
      if (i >= 4 && my.spec == 'p')  break;  /* code/sys types      */
   } 
   return 0;
}

char         /*--> parse out a v20 records ---------------[ leaf   [ ------ ]-*/
SCRP_vers20        (void)
{
   /*---(design notes)-------------------*/
   /*
    *   version 20 of the script fields added a version number to the records
    *   to allow easier conversion and more flexible updating.  i decided to
    *   put this field up front to make paring much easier.
    *
    */
   /*---(locals)-----------+-----------+-*/
   int         rc          = 0;             /* generic return code            */
   char        rce         = -10;           /* return code for errors         */
   int         i           = 0;
   char       *p;
   char       *q           = "";
   /*---(read fields)--------------------*/
   for (i = 2; i < 20; ++i) {
      /*---(read field)------------------*/
      DEBUG_INPT   yLOG_note    ("read next field");
      p = strtok (NULL  , q);
      --rce;  if (p == NULL) {
         DEBUG_INPT   yLOG_note    ("strtok came up empty");
         DEBUG_INPT   yLOG_exit    (__FUNCTION__);
         break;
      }
      strltrim (p, ySTR_BOTH, LEN_RECD);
      /*---(clear spacer bars)-----------*/
      if (p[0] == '-') {
         switch (p[1]) {
         case ' '  :   /* catches "- - - - - - -" lines */
         case '-'  :   /* catches "-------------" lines */
         case '\0' :   /* catches "-" placeholder lines */
            p[0] = '\0';
            break;
         }
      }
      /*---(handle fields)---------------*/
      switch (i) {
      case  2 :   strlcpy (my.desc      , p, LEN_LONG );
                  DEBUG_INPT   yLOG_info    ("desc"      , my.desc);
                  break;
      case  3 :   if (my.spec == 'p') {
                     strlcpy (my.code      , p, LEN_RECD);
                     DEBUG_INPT   yLOG_info    ("code"      , my.code);
                  } else {
                     strlcpy (my.meth      , p, LEN_DESC );
                     DEBUG_INPT   yLOG_info    ("meth"      , my.meth);
                  }
                  break;
      case  4 :   strlcpy (my.args      , p, LEN_FULL);
                  strlcpy (my.code      , p, LEN_FULL);
                  DEBUG_INPT   yLOG_info    ("args"      , my.args);
                  break;
      case  5 :   strlcpy (my.test      , p, LEN_LABEL);
                  DEBUG_INPT   yLOG_info    ("test"      , my.test);
                  break;
      case  6 :   strlcpy (my.expe      , p, LEN_RECD);
                  DEBUG_INPT   yLOG_info    ("expe"      , my.expe);
                  break;
      case  7 :   my.type      = p [0];
                  if (my.type == '\0')  my.type = '-';
                  DEBUG_INPT   yLOG_char    ("type"      , my.type);
                  break;
      case  8 :   strlcpy (my.retn      , p, LEN_FULL);
                  DEBUG_INPT   yLOG_info    ("retn"      , my.retn);
                  break;
      }
      /*---(stop parsing summ records)---*/
      if (i >= 3 && my.spec == '-')  break;  /* organization types  */
      if (i >= 3 && my.spec == 'p')  break;  /* code/load/sys types */
   } 
   return 0;
}

char         /*--> parse out original records ------------[ leaf   [ ------ ]-*/
SCRP_vers19        (void)
{
   /*---(design notes)-------------------*/
   /*
    *   version 19, and before, of the script fields had no version number
    *
    */
   /*---(locals)-----------+-----------+-*/
   int         rc          = 0;             /* generic return code            */
   char        rce         = -10;           /* return code for errors         */
   int         i           = 0;
   char       *p;
   char       *q           = "";
   /*---(read fields)--------------------*/
   for (i = 2; i < 20; ++i) {
      DEBUG_INPT   yLOG_note    ("read next field");
      p = strtok (NULL  , q);
      --rce;  if (p == NULL) {
         DEBUG_INPT   yLOG_note    ("strtok came up empty");
         DEBUG_INPT   yLOG_exit    (__FUNCTION__);
         break;
      }
      strltrim (p, ySTR_BOTH, LEN_RECD);
      /*---(clear spacer bars)-----------*/
      if (p [0] == '-') {
         if (strncmp (p, "- - -", 5) == 0)    p [0] = '\0';
         if (strncmp (p, "-----", 5) == 0)    p [0] = '\0';
         if (p [1] == '\0')                   p [0] = '\0';
      }
      /*---(handle fields)---------------*/
      switch (i) {
      case  2 :   if (my.spec == 'p') {
                     strlcpy (my.code      , p, LEN_RECD);
                     DEBUG_INPT   yLOG_info    ("code"      , my.code);
                  } else {
                     strlcpy (my.meth      , p, LEN_DESC );
                     DEBUG_INPT   yLOG_info    ("meth"      , my.meth);
                  }
                  break;
      case  3 :   strlcpy (my.args      , p, LEN_FULL);
                  strlcpy (my.code      , p, LEN_FULL);
                  DEBUG_INPT   yLOG_info    ("args"      , my.args);
                  break;
      case  4 :   strlcpy (my.test      , p, LEN_LABEL);
                  DEBUG_INPT   yLOG_info    ("test"      , my.test);
                  break;
      case  5 :   strlcpy (my.expe      , p, LEN_RECD);
                  DEBUG_INPT   yLOG_info    ("expe"      , my.expe);
                  break;
      }
      if (i >= 2 && my.spec == '-')  break;  /* organization types  */
      if (i >= 2 && my.spec == 'p')  break;  /* code/load/sys types */
   } 
   return 0;
}

char
SCRP_parse_defense   (void)
{
   /*---(locals)-----------+-----------+-*/
   char        rce         = -10;           /* return code for errors         */
   /*---(header)-------------------------*/
   DEBUG_INPT   yLOG_senter  (__FUNCTION__);
   DEBUG_INPT   yLOG_spoint  (my.f_scrp);
   --rce;  if (my.f_scrp == NULL) {
      DEBUG_INPT   yLOG_snote   ("file not open");
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_INPT   yLOG_sint    (my.recd [0]);
   --rce;  if (my.recd [0] == '\0') {
      DEBUG_INPT   yLOG_snote   ("null record in my.recd");
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_INPT   yLOG_sint    (my.len);
   --rce;  if (my.len <  5 && my.recd [0] != '#') {
      DEBUG_INPT   yLOG_snote   ("my.len too short");
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_INPT   yLOG_sexit   (__FUNCTION__);
   return 0;
}

char
SCRP_parse_comment      (void)
{
   /*---(locals)-----------+-----+-----+-*/
   int         i           =    0;
   /*---(header)-------------------------*/
   DEBUG_INPT   yLOG_senter  (__FUNCTION__);
   /*---(ward-off)-----------------------*/
   DEBUG_INPT   yLOG_sint    (my.len);
   if (my.len < 2) {
      DEBUG_INPT   yLOG_snote   ("too short");
      DEBUG_INPT   yLOG_sexit   (__FUNCTION__);
      return 0;
   }
   if (strncmp (my.recd, "#>", 2) != 0) {
      DEBUG_INPT   yLOG_snote   ("not prefixed with #>");
      DEBUG_INPT   yLOG_sexit   (__FUNCTION__);
      return 0;
   }
   /*---(check for marker)---------------*/
   DEBUG_INPT   yLOG_snote   ("saved record/comment");
   for (i = 0; i < MAX_VERB; ++i) {
      if (strcmp (g_verbs [i].name, "#>") != 0) continue;
      strlcpy (my.verb, g_verbs [i].name, LEN_LABEL);
      my.indx    = i;
      ++g_verbs [i].count;
      ++g_verbs [i].total;
      my.spec    = g_verbs [i].spec;
      DEBUG_INPT   yLOG_sint    (g_verbs [i].count);
   }
   /*---(complete)-----------------------*/
   DEBUG_INPT   yLOG_sexit   (__FUNCTION__);
   return 1;
}

char
SCRP_parse_verb         (char *p)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   int         i           =    0;
   int         x_len       =    0;
   char        x_verb      [LEN_LABEL] = "";
   char       *q           = NULL;
   /*---(header)-------------------------*/
   DEBUG_INPT   yLOG_senter  (__FUNCTION__);
   /*---(defaults)-----------------------*/
   strlcpy  (my.verb , "", LEN_LABEL);
   my.p_conv = NULL;
   my.p_code = NULL;
   my.indx   = -1;
   /*---(defense)------------------------*/
   DEBUG_INPT   yLOG_spoint  (p);
   --rce;  if (p == NULL || strlen (p) <= 0) {
      yURG_error ("%s:%d:1: error: no verb found", my.n_scrp, my.n_line);
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   strlcpy  (x_verb, p, LEN_FULL);
   strltrim (x_verb, ySTR_BOTH, LEN_FULL);
   q = strchr (x_verb, ' ');
   if (q != NULL)  q [0] = '\0';
   x_len = strlen (x_verb);
   DEBUG_INPT   yLOG_sint    (x_len);
   --rce;  if (x_len <= 2) {
      yURG_error ("%s:%d:1: error: verb <%s> is too short (%d <= 2)", my.n_scrp, my.n_line, x_verb, x_len);
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_INPT   yLOG_snote   (x_verb);
   /*---(filter comments)----------------*/
   --rce;  if (x_verb [0] == '#') {
      yURG_error ("%s:%d:1: error: comment not in column one", my.n_scrp, my.n_line);
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(find verb)----------------------*/
   my.indx = -1;
   for (i = 0; i < MAX_VERB; ++i) {
      if (g_verbs [i].name [0] == '-')                break;
      if (g_verbs [i].name [0] != x_verb[0])          continue;
      if (strcmp (g_verbs [i].name, x_verb) != 0)     continue;
      /*---(save values)-----------------*/
      DEBUG_INPT   yLOG_snote   ("verb found");
      strlcpy (my.verb, g_verbs [i].name, LEN_LABEL);
      my.indx    = i;
      my.p_conv  = g_verbs [i].conv;
      my.p_code  = g_verbs [i].code;
      ++g_verbs [i].count;
      ++g_verbs [i].total;
      my.spec    = g_verbs [i].spec;
      DEBUG_INPT   yLOG_sint    (g_verbs [i].count);
      break;
      /*---(done)------------------------*/
   }
   /*---(failure)------------------------*/
   --rce;  if (my.indx == -1) {
      yURG_error ("%s:%d:1: error: verb <%s> not recognized/found", my.n_scrp, my.n_line, x_verb);
      DEBUG_INPT   yLOG_snote   ("verb not found");
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(complete)-----------------------*/
   DEBUG_INPT   yLOG_sexit   (__FUNCTION__);
   return 0;
}

char
SCRP_parse_shared       (char *p)
{
}


char
SCRP_parse_ditto        (char *p)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char       *q           = NULL;
   /*---(header)-------------------------*/
   DEBUG_INPT   yLOG_enter   (__FUNCTION__);
   my.mark = '-';
   if (my.run_type == G_RUN_CREATE || my.run_type == G_RUN_DEBUG) {
      if (strcmp ("SCRP" , g_verbs [my.indx].name) == 0) {
         DEBUG_INPT   yLOG_note    ("clear ditto marks (create)");
         SCRP_ditto__clear ();
      } else if (strcmp ("COND", g_verbs [my.indx].name) == 0) {
         DEBUG_INPT   yLOG_note    ("found a ditto condition (create)");
         SCRP_ditto__check (p, 'y');
      } else if (strcmp ("DITTO", g_verbs [my.indx].name) == 0) {
         DEBUG_INPT   yLOG_note    ("found a ditto verb (create)");
         rc = SCRP_ditto__beg (p);
         if (rc >= 0)  rc = 1;
      }
   } else {
      if (strcmp ("COND", g_verbs [my.indx].name) == 0 && p [5] == '(' && p [7] == ')') {
         DEBUG_INPT   yLOG_note    ("found a ditto condition (update)");
         my.mark = p [6];
      } else if (strcmp ("DITTO", g_verbs [my.indx].name) == 0) {
         DEBUG_INPT   yLOG_note    ("found a ditto verb (update)");
         my.mark = p [7];
      }
   }
   --rce;  if (strcmp ("SHARED" , my.verb) == 0 || strcmp ("REUSE" , my.verb) == 0) {
      q = strchr (p, '-');
      if (q == NULL || strlen (q) < 3 || q [2] != '-') {
         yURG_error ("%s:%d:1: error: %s identifier not properly formatted -?-", my.n_scrp, my.n_line, my.verb);
         return rce;
      }
      if (strchr (LTRS_CHARS, q [1]) == NULL) {
         yURG_error ("%s:%d:1: error: %s identifier (%c) not legal", my.n_scrp, my.n_line, my.verb, q [1]);
         return rce;
      }
      my.share = q [1];
   }
   /*---(complete)-----------------------*/
   DEBUG_INPT   yLOG_exit    (__FUNCTION__);
   return rc;
}

char
SCRP_parse_stage        (char *p)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   int         x_len       =    0;
   char        t           [LEN_LABEL] = "";
   char       *q           = NULL;
   /*---(header)-------------------------*/
   DEBUG_INPT   yLOG_senter  (__FUNCTION__);
   /*---(defaults)-----------------------*/
   strlcpy  (my.stage, "", LEN_LABEL);
   /*---(ward-off)-----------------------*/
   if (my.indx < 0 || strcmp ("SCRP" , my.verb) != 0) {
      DEBUG_INPT   yLOG_snote   ("only applies to scripts");
      DEBUG_INPT   yLOG_sexit   (__FUNCTION__);
      return 0;
   }
   /*---(prepare)------------------------*/
   strlcpy  (t, p, LEN_LABEL);
   strltrim (t, ySTR_BOTH, LEN_LABEL);
   x_len = strlen (t);
   /*---(check markers)------------------*/
   q = strchr (t, '[');
   if (q == NULL && x_len == 4) {
      DEBUG_INPT   yLOG_snote   ("no brackets, ok");
      DEBUG_INPT   yLOG_sexit   (__FUNCTION__);
      return 0;
   }
   --rce;  if (q == NULL || q [3] != ']') {
      yURG_error ("%s:%d:1: error: %s identifier, uses wrong brackets, e.g., [ì4]", my.n_scrp, my.n_line, my.verb);
      DEBUG_INPT   yLOG_snote   ("does not begin right");
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(positions)----------------------*/
   --rce;  if (strchr (LTRS_GREEK "-", q [1]) == NULL) {
      yURG_error ("%s:%d:1: error: %s identifier, not greek letter for wave, e.g., [ì4]", my.n_scrp, my.n_line, my.verb);
      DEBUG_INPT   yLOG_snote   ("does not lead with greek letter");
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   --rce;  if (strchr ("123456789-", q [2]) == NULL) {
      yURG_error ("%s:%d:1: error: %s identifier, not number for stage, e.g., [ì4]", my.n_scrp, my.n_line, my.verb);
      DEBUG_INPT   yLOG_snote   ("does not end with number");
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(save)---------------------------*/
   q [3] = '\0';
   strlcpy (my.stage, q + 1, LEN_LABEL);
   /*---(complete)-----------------------*/
   DEBUG_INPT   yLOG_sexit   (__FUNCTION__);
   return 0;
}

char
SCRP_write_wave         (void)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        x_stage     = '-';
   char        x_wave      = '-';
   static char x_scrp      =   0;
   /*---(header)-------------------------*/
   DEBUG_INPT   yLOG_senter  (__FUNCTION__);
   /*---(ward-off)-----------------------*/
   --rce;  if (my.indx < 0 || strcmp ("SCRP" , g_verbs [my.indx].name) != 0) {
      DEBUG_INPT   yLOG_snote   ("only applies to scripts");
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(script entry in wave)-----------*/
   ++x_scrp;
   if (strlen (my.stage) == 2) {
      x_stage = my.stage [0];
      x_wave  = my.stage [1];
   }
   WAVE_printf ("%c  %c  %-25.25s  %2d  %-65.65s \n", x_stage, x_wave, my.n_base, x_scrp, my.desc);
   /*---(complete)-----------------------*/
   DEBUG_INPT   yLOG_sexit   (__FUNCTION__);
   return 0;
}

char         /*--> parse out a script record -------------[ leaf   [ ------ ]-*/
SCRP_parse         (void)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   int         rc          = 0;             /* generic return code            */
   char        x_recd      [LEN_RECD];
   int         x_len       = 0;             /* input record length            */
   char       *p;
   char       *q           = "";
   char       *r           = NULL;
   int         i           = 0;
   /*---(header)-------------------------*/
   DEBUG_INPT   yLOG_enter   (__FUNCTION__);
   /*---(prepare)---------------------*/
   SCRP_clear  ();
   /*---(defense)---------------------*/
   rc = SCRP_parse_defense ();
   DEBUG_INPT   yLOG_value   ("defense"   , rc);
   /*> printf ("defense %d\n", rc);                                                   <*/
   --rce;  if (rc < 0) {
      DEBUG_INPT   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(saved comments)-----------------*/
   rc = SCRP_parse_comment ();
   /*> printf ("comment %d\n", rc);                                                   <*/
   DEBUG_INPT   yLOG_value   ("comment"   , rc);
   --rce;  if (rc != 0) {
      DEBUG_INPT   yLOG_exit    (__FUNCTION__);
      return 0;
   }
   /*---(create a copy of recd)----------*/
   strlcpy (x_recd, my.recd, LEN_RECD);
   DEBUG_INPT   yLOG_info    ("x_recd"    , x_recd);
   /*---(get verb)-----------------------*/
   p = strtok (x_recd, q);
   rc = SCRP_parse_verb (p);
   /*> printf ("verb %d\n", rc);                                                      <*/
   DEBUG_INPT   yLOG_value   ("verb"      , rc);
   --rce;  if (rc < 0) {
      DEBUG_INPT   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(check for ditto)----------------*/
   rc = SCRP_parse_ditto (p);
   DEBUG_INPT   yLOG_value   ("ditto"     , rc);
   --rce;  if (rc < 0) {
      DEBUG_INPT   yLOG_exitr   (__FUNCTION__, rc);
      return rce;
   }
   if (rc >  0) {
      DEBUG_INPT   yLOG_exit    (__FUNCTION__);
      return 0;
   }
   /*---(check for ditto)----------------*/
   rc = SCRP_parse_stage (p);
   DEBUG_INPT   yLOG_value   ("stage"     , rc);
   --rce;  if (rc < 0) {
      DEBUG_INPT   yLOG_exitr   (__FUNCTION__, rc);
      return rce;
   }
   /*---(read version)-------------------*/
   p = strtok (NULL  , q);
   --rce;  if (p == NULL && my.spec != 'c') {
      yURG_error ("%s:%d:1: error: verb only, %s requires more fields", my.n_scrp, my.n_line, my.verb);
      DEBUG_INPT   yLOG_note    ("strtok came up empty");
      DEBUG_INPT   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   strltrim (p, ySTR_BOTH, LEN_RECD);
   x_len = strlen (p);
   if (p[0] == '-')  p[0] = '\0';
   rc = 0;
   if      (x_len != 3 || p [0] != 'v') {
      if (my.spec != 'c')  rc = SCRP__current (p);
   } else if (strcmp (p, "v21") == 0) {
      strlcpy (my.vers      , p    , LEN_LABEL);
      DEBUG_INPT   yLOG_info    ("vers"      , my.vers);
      if (my.spec != 'c')  rc = SCRP_vers21  ();
   } else if (strcmp (p, "v20") == 0) {
      strlcpy (my.vers      , p    , LEN_LABEL);
      DEBUG_INPT   yLOG_info    ("vers"      , my.vers);
      if (my.spec != 'c')  rc = SCRP_vers20  ();
   } else                             {
      strlcpy (my.vers      , "v19", LEN_LABEL);
      DEBUG_INPT   yLOG_info    ("vers"      , my.vers);
      strlcpy (my.desc      , p    , LEN_LONG );
      DEBUG_INPT   yLOG_info    ("desc"      , my.desc);
      if (my.spec != 'c')  rc = SCRP_vers19  ();
   }
   if (rc < 0) {
      DEBUG_INPT   yLOG_note    ("trouble parsing");
      DEBUG_INPT   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   /*---(complete)-----------------------*/
   DEBUG_INPT   yLOG_exit    (__FUNCTION__);
   return 0;
}


char         /*--> close script file ---------------------[ ------ [ ------ ]-*/
SCRP_verbs         (void)
{
   int         i           = 0;
   int         c           = 0;
   printf ("verb counts...\n");
   for (i = 0; i < MAX_VERB; ++i) {
      printf  ("   %-10s  %4d\n", g_verbs [i].name, g_verbs [i].total);
      c += g_verbs [i].total;
      if (g_verbs [i].name [0] == '-') break;
   }
   printf  ("   %-10s  %4d\n", "TOTAL"   , c);
   printf  ("   %-10s  %4d\n", "concerns", my.n_recd - c);
   return 0;
}

char         /*--> close script file ---------------------[ ------ [ ------ ]-*/
SCRP_verbcode      (void)
{
   int         i           = 0;
   int         c           = 0;
   CODE_printf ("\n");
   CODE_printf ("char\n");
   CODE_printf ("UNIT_verbs (void)\n");
   CODE_printf ("{\n");
   CODE_printf ("   printf (\"koios, record type summary\\n\");\n");
   for (i = 0; i < MAX_VERB; ++i) {
      CODE_printf ("   printf (\"%-10.10s = %5d   %s\\n\");\n", g_verbs [i].name, g_verbs [i].total, g_verbs [i].desc);
      c += g_verbs [i].total;
      if (g_verbs [i].name [0] == '-') break;
   }
   CODE_printf ("   printf (\"%-10.10s = %5d   %s\\n\");\n", "TOTAL"         , c                , "sum of all verbs");
   CODE_printf ("   printf (\"%-10.10s = %5d   %s\\n\");\n", "concerns"      , my.n_recd - c    , "records with troubles");
   CODE_printf ("   return 0;\n");
   CODE_printf ("}\n");
   CODE_printf ("\n");
   return 0;
}



/*====================------------------------------------====================*/
/*===----                         unit testing                         ----===*/
/*====================------------------------------------====================*/
static void      o___UNITTEST________________o (void) {;};

char*      /*----: unit testing accessor for clean validation interface ------*/
SCRP__unit              (char *a_question, int a_num)
{
   /*---(locals)-----------+-----+-----+-*/
   int         i           =    0;
   char        s           [LEN_LABEL];
   char        t           [LEN_RECD ];
   /*---(preprare)-----------------------*/
   strlcpy  (my.answer, "SCRP unit      : question not understood", LEN_FULL);
   if      (strcmp (a_question, "file"      ) == 0) {
      sprintf (my.answer, "SCRP file      : %-35.35s %p", my.n_scrp, my.f_scrp);
   }
   else if (strcmp (a_question, "recd"      ) == 0) {
      strlcpy    (t, my.recd, LEN_RECD);
      strlencode (t, ySTR_NONE, LEN_RECD);
      sprintf (my.answer, "SCRP recd      : %2d %3d[%.40s]", my.n_line, strlen (t), t);
   }
   else if (strcmp (a_question, "verb"      ) == 0) {
      sprintf (my.answer, "SCRP verb      : %-10.10s %3d[%.30s]", my.verb, strlen (my.desc), my.desc);
   }
   else if (strcmp (a_question, "call"      ) == 0) {
      sprintf (t, "[%.20s]", my.meth);
      sprintf (my.answer, "SCRP call      : %3d%-22.22s %3d[%.20s]", strlen (my.meth), t, strlen (my.args), my.args);
   }
   else if (strcmp (a_question, "test"      ) == 0) {
      sprintf (my.answer, "SCRP test      : %-10.10s %3d[%.30s]", my.test, strlen (my.expe), my.expe);
   }
   else if (strcmp (a_question, "retn"      ) == 0) {
      sprintf (my.answer, "SCRP retn      : %c          %3d[%.30s]", my.type, strlen (my.retn), my.retn);
   }
   else if (strcmp (a_question, "code"      ) == 0) {
      strlcpy    (t, my.code, LEN_RECD);
      strlencode (t, ySTR_NONE, LEN_RECD);
      sprintf (my.answer, "SCRP code      : %3d[%.40s]", strlen (t), t);
   }
   else if (strcmp (a_question, "mark"      ) == 0) {
      sprintf (my.answer, "SCRP mark      : %c", my.mark);
   }
   else if (strcmp (a_question, "ditto"     ) == 0) {
      sprintf (my.answer, "SCRP ditto     : %2d  %c  %-10p  %-10p  %3d", s_ditto, s_dittoing, s_file_save, s_file_ditto, s_lineno);
   }
   else if (strcmp (a_question, "dittos"    ) == 0) {
      strlcpy (t, "", LEN_RECD);
      for (i = 0; i < 15; ++i) {
         if (s_dittos [i] > 0)  sprintf (s, " %2d", s_dittos [i]);
         else                   sprintf (s, "  -");
         strlcat (t, s, LEN_RECD);
      }
      sprintf (my.answer, "SCRP dittos A-O:%s", t);
   }
   /*---(complete)-----------------------*/
   return my.answer;
}

/*===============================[[ end code ]]===============================*/
