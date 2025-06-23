/*===============================[[ beg-code ]]===============================*/
#include    "koios.h"        /* LOCAL  : main header                          */



/*====================------------------------------------====================*/
/*===----                         file level                           ----===*/
/*====================------------------------------------====================*/
static void  o___FILE____________o () { return; }

char
READ_open               (char a_sfile [LEN_TITLE], char a_sfunc [LEN_TITLE], int a_sline, char a_dir [LEN_PATH], char a_name [LEN_TITLE], char a_mode, FILE **r_file, int *r_line)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        x_mode      [LEN_SHORT] = "";
   char        x_name      [LEN_PATH]  = "";
   int         l           =    0;
   char        a           =  '-';
   char        b           =  '-';
   FILE       *f           = NULL;
   /*---(header)-------------------------*/
   debug_uver   ylog_uenter  (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_line != NULL)  *r_line = 0;
   /*---(defense)------------------------*/
   debug_uver   ylog_upoint  ("a_dir"     , a_dir);
   --rce;  if (a_dir   == NULL) {
      yerr_uerror ("%s/%s:%d:0: error: directory name requested for openning is NULL", a_sfile, a_sfunc, a_sline);
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   debug_uver   ylog_uinfo   ("a_dir"     , a_dir);
   debug_uver   ylog_upoint  ("a_name"    , a_name);
   --rce;  if (a_name  == NULL || a_name [0] == '\0') {
      yerr_uerror ("%s/%s:%d:0: error: file name requested for openning is NULL/empty", a_sfile, a_sfunc, a_sline);
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   debug_uver   ylog_uinfo   ("a_name"    , a_name);
   debug_uver   ylog_upoint  ("r_file"    , r_file);
   --rce;  if (r_file  == NULL) {
      yerr_uerror ("%s/%s:%d:0: error: file å%sæ passed with NULL file pointer return", a_sfile, a_sfunc, a_sline, a_name);
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   debug_uver   ylog_upoint  ("*r_file"   , *r_file);
   --rce;  if (*r_file != NULL) {
      yerr_uerror ("%s/%s:%d:0: error: file å%sæ passed with already used file pointer", a_sfile, a_sfunc, a_sline, a_name);
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(mode)---------------------------*/
   debug_uver   ylog_uchar   ("a_mode"     , a_mode);
   --rce;  switch (a_mode) {
   case 'r'  :
      strcpy (x_mode, "rt");
      break;
   case 'w'  :
      strcpy (x_mode, "wt");
      break;
   default   :
      yerr_uerror ("%s/%s:%d:0: error: file å%sæ passed for (%c) when direction can only be årwæ", a_sfile, a_sfunc, a_sline, a_name, a_mode);
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
      break;
   }
   debug_uver   ylog_uinfo   ("x_mode"    , x_mode);
   /*---(full name)----------------------*/
   l = strlen (a_dir);
   debug_uver   ylog_uvalue  ("l"         , l);
   if (l > 0)  a = a_dir  [l - 1];
   b = a_name [0];
   if (l == 0 || b == '/')    snprintf (x_name, LEN_PATH, "%s"   , a_name);
   else if (a != '/')         snprintf (x_name, LEN_PATH, "%s/%s", a_dir, a_name);
   else                       snprintf (x_name, LEN_PATH, "%s%s" , a_dir, a_name);
   debug_uver   ylog_uinfo   ("x_name"    , x_name);
   /*---(open)---------------------------*/
   f = fopen (x_name, x_mode);
   debug_uver   ylog_upoint  ("f"         , f);
   --rce;  if (f == NULL) {
      yerr_uerror ("%s/%s:%d:0: error: file å%sæ could not be found/openned for (%c)", a_sfile, a_sfunc, a_sline, x_name, a_mode);
      debug_uver   ylog_unote   ("can not open script file");
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   debug_uver   ylog_unote   ("script file open");
   /*---(save-back)----------------------*/
   if (r_file  != NULL)  *r_file = f;
   /*---(complete)-----------------------*/
   debug_uver   ylog_uexit   (__FUNCTION__);
   return 0;
}

char         /*--> close script file ---------------------[ ------ [ ------ ]-*/
READ_close              (char a_sfile [LEN_TITLE], char a_sfunc [LEN_TITLE], int a_sline, char a_name [LEN_TITLE], FILE **b_file)
{
   /*---(locals)-----------+-----------+-*/
   char        rc          = 0;
   char        rce         = -10;
   /*---(header)-------------------------*/
   debug_uver   ylog_uenter  (__FUNCTION__);
   /*---(defense)------------------------*/
   debug_uver   ylog_upoint  ("b_file"    , b_file);
   --rce;  if (b_file  == NULL) {
      yerr_uerror ("%s/%s:%d:0: error: file å%sæ passed with NULL file pointer return", a_sfile, a_sfunc, a_sline, a_name);
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   debug_uver   ylog_upoint  ("*b_file"   , *b_file);
   --rce;  if (*b_file == NULL) {
      yerr_uerror ("%s/%s:%d:0: error: file å%sæ passed with already grounded file pointer", a_sfile, a_sfunc, a_sline, a_name);
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(close)--------------------------*/
   fflush (*b_file);
   rc = fclose (*b_file);
   debug_uver   ylog_uvalue  ("rc"        , rc);
   --rce;  if (rc < 0) {
      yerr_uerror ("%s/%s:%d:0: error: file å%sæ could not be closed", a_sfile, a_sfunc, a_sline, a_name);
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(default)------------------------*/
   *b_file = NULL;
   /*---(complete)-----------------------*/
   debug_uver   ylog_uexit   (__FUNCTION__);
   return 0;
}



/*====================------------------------------------====================*/
/*===----                        record level                          ----===*/
/*====================------------------------------------====================*/
static void  o___RECORD__________o () { return; }

char         /*--> read script record --------------------[ leaf   [ ------ ]-*/
READ__defense           (FILE **a_scrp, int *r_nline, char *r_dittoing, char *r_dmark, int *r_ditto, int *r_dline, int *r_nrecd, char r_recd [LEN_RECD])
{
   /*---(locals)-----------+-----------+-*/
   char        rce         = -10;           /* return code for errors         */
   /*---(header)-------------------------*/
   debug_uver   ylog_uenter  (__FUNCTION__);
   /*---(defense)------------------------*/
   debug_uver   ylog_upoint  ("a_scrp"    , a_scrp);
   --rce;  if (a_scrp == NULL) {
      debug_uver   ylog_uexit   (__FUNCTION__);
      return rce;
   }
   debug_uver   ylog_upoint  ("*a_scrp"   , *a_scrp);
   --rce;  if (*a_scrp == NULL) {
      debug_uver   ylog_uexit   (__FUNCTION__);
      return rce;
   }
   debug_uver   ylog_upoint  ("r_nline"   , r_nline);
   --rce;  if (r_nline == NULL) {
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   debug_uver   ylog_upoint  ("r_dittoing", r_dittoing);
   --rce;  if (r_dittoing == NULL) {
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   debug_uver   ylog_upoint  ("r_dmark"   , r_dmark);
   --rce;  if (r_dmark == NULL) {
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   debug_uver   ylog_upoint  ("r_ditto"   , r_ditto);
   --rce;  if (r_ditto == NULL) {
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   debug_uver   ylog_upoint  ("r_dline"   , r_dline);
   --rce;  if (r_dline == NULL) {
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   debug_uver   ylog_upoint  ("r_nrecd"   , r_nrecd);
   --rce;  if (r_nrecd == NULL) {
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   debug_uver   ylog_upoint  ("r_recd"    , r_recd);
   --rce;  if (r_recd == NULL) {
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(complete)-----------------------*/
   debug_uver   ylog_uexit   (__FUNCTION__);
   return 0;
}

char         /*--> clean a script record -----------------[ leaf   [ ------ ]-*/
READ__clear             (void)
{
   /*---(header)-------------------------*/
   debug_uver   ylog_uenter  (__FUNCTION__);
   /*---(save value)---------------------*/
   if (strcmp (my_cur.c_verb, "DITTO") != 0)  strlcpy (my_run.r_last, my_cur.c_verb, LEN_LABEL);
   /*---(input vars)---------------------*/
   my_cur.c_verb      [0] = '\0';
   my_cur.c_conv          = NULL;
   my_cur.c_code          = NULL;
   my_cur.c_spec          =  '-';
   my_cur.c_vers          =   -1;
   my_cur.c_desc      [0] = '\0';
   my_cur.c_method    [0] = '\0';
   my_cur.c_args      [0] = '\0';
   my_cur.c_test      [0] = '\0';
   my_cur.c_expect    [0] = '\0';
   my_cur.c_return    [0] = '\0';
   /*---(special marking)----------------*/
   my_cur.c_stage     [0] = '\0';
   my_cur.c_ditto         = '-';
   my_cur.c_major         = '-';
   my_cur.c_minor         = '-';
   my_cur.c_which     [0] = '\0';
   /*---(working vars)-------------------*/
   my_cur.c_syst      [0] = '\0';
   my_cur.c_disp      [0] = '\0';
   my_cur.c_load      [0] = '\0';
   /*---(complete)-----------------------*/
   debug_uver   ylog_uexit   (__FUNCTION__);
   return 0;
}

char         /*--> read script record --------------------[ leaf   [ ------ ]-*/
READ__single            (FILE **b_scrp, int *r_nline, char *r_dittoing, char *r_dmark, int *r_ditto, int *r_dline, int *r_nrecd, char r_recd [LEN_RECD])
{
   /*---(locals)-----------+-----------+-*/
   int         rc          = 0;             /* generic return code            */
   char        rce         = -10;           /* return code for errors         */
   char        x_recd      [LEN_RECD];
   int         x_len       = 0;             /* input record length            */
   char        t           [LEN_LABEL];
   char       *p           = NULL;
   char       *r           = NULL;
   /*---(header)-------------------------*/
   debug_uver   ylog_uenter  (__FUNCTION__);
   /*---(default)---------------------*/
   if (r_recd != NULL)  strcpy (r_recd, "");
   /*---(read next)-------------------*/
   debug_uver   ylog_unote   ("read script file");
   fgets (x_recd, LEN_RECD, *b_scrp);
   if (feof (*b_scrp)) {
      debug_uver   ylog_unote   ("hit end of file");
      debug_uver   ylog_uexit   (__FUNCTION__);
      return 0;
   }
   /*---(handle line numbers)---------*/
   debug_uver   ylog_ucomplex("line#"     , "%4d nline, %c, %4d dline", *r_nline, *r_dittoing, *r_dline);
   rc = DITTO_read_numbering (*r_dittoing, *r_ditto, r_nline, r_dline);
   debug_uver   ylog_uvalue  ("ditto prep", rc);
   if (rc == 2) {
      debug_uver   ylog_unote   ("quickly to next record");
      debug_uver   ylog_uexitr  (__FUNCTION__, 2);
      return 2;
   }
   /*---(prepare)---------------------*/
   x_len = strlen (x_recd);
   if (x_len > 0)  x_recd [--x_len] = '\0';
   debug_uver   ylog_ucomplex("x_recd"    , "%3då%sæ", x_len, x_recd);
   /*---(filter)----------------------*/
   if (x_recd [0] == '\0') {
      debug_uver   ylog_unote   ("SKIP, empty");
      if (*r_dittoing == 'y')  DITTO_end (b_scrp, r_dittoing, r_dmark, r_ditto, r_dline);
      debug_uver   ylog_uexitr  (__FUNCTION__, 2);
      return 2;
   }
   if (x_len > 1 && x_recd [0] == '#' && x_recd [1] != '>') {
      debug_uver   ylog_unote   ("SKIP, comment");
      if (*r_dittoing == 'y')  DITTO_end (b_scrp, r_dittoing, r_dmark, r_ditto, r_dline);
      debug_uver   ylog_uexitr  (__FUNCTION__, 2);
      return 2;
   }
   debug_uver   ylog_uvalue  ("length"    , x_len);
   if (x_len <=  5 && strncmp (x_recd, "#>", 2) != 0)  {
      debug_uver   ylog_unote   ("SKIP, too short");
      if (*r_dittoing == 'y')  DITTO_end (b_scrp, r_dittoing, r_dmark, r_ditto, r_dline);
      debug_uver   ylog_uexitr  (__FUNCTION__, 2);
      return 2;
   }
   debug_uver   ylog_uinfo   ("x_recd"    , x_recd);
   x_len = strlen (x_recd);
   debug_uver   ylog_ucomplex("x_recd"    , "%3då%sæ", x_len, x_recd);
   /*---(check other end ditto)-------*/
   if (*r_dittoing == 'y' && *r_dline != *r_ditto)  {
      debug_uver   ylog_unote   ("in dittoing logic");
      strlcpy (t, x_recd, LEN_LABEL);
      debug_uver   ylog_uinfo   ("t"         , t);
      p = strtok (t, "");
      debug_uver   ylog_upoint  ("p"         , p);
      p = strtok (p, " ");
      debug_uver   ylog_upoint  ("p"         , p);
      if (p != NULL) {
         ystrutrim (p, LEN_LABEL);
         debug_uver   ylog_uinfo   ("p"         , p);
         rc = VERB_dittoable (p);
         debug_uver   ylog_uvalue  ("dittoable" , rc);
         if (rc != 1) {
            DITTO_end (b_scrp, r_dittoing, r_dmark, r_ditto, r_dline);
            debug_uver   ylog_uexitr  (__FUNCTION__, 2);
            return 2;
         }
      }
   }
   /*---(save-back)-------------------*/
   debug_uver   ylog_uinfo   ("x_recd"    , x_recd);
   debug_uver   ylog_unote   ("save copy of source record");
   ystruundelay (x_recd, LEN_RECD);
   debug_uver   ylog_uinfo   ("x_recd"    , x_recd);
   ++(*r_nrecd);
   if (r_recd != NULL)  strlcpy (r_recd, x_recd, LEN_RECD);
   /*---(complete)-----------------------*/
   debug_uver   ylog_uexit   (__FUNCTION__);
   return 1;
}

char         /*--> read script record --------------------[ leaf   [ ------ ]-*/
READ_next               (FILE **b_scrp, int *r_nline, char *r_dittoing, char *r_dmark, int *r_ditto, int *r_dline, int *r_nrecd, char r_recd [LEN_RECD])
{
   /*---(locals)-----------+-----------+-*/
   int         rc          = 0;             /* generic return code            */
   char        rce         = -10;           /* return code for errors         */
   /*---(header)-------------------------*/
   debug_uver   ylog_uenter  (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_recd != NULL)  strcpy (r_recd, "");
   /*---(defense)------------------------*/
   rc = READ__defense (b_scrp, r_nline, r_dittoing, r_dmark, r_ditto, r_dline, r_nrecd, r_recd);
   debug_uver   ylog_uvalue  ("defense"   , rc);
   --rce;  if (rc < 0) {
      debug_uver   ylog_uexit   (__FUNCTION__);
      return rce;
   }
   /*---(prepare)------------------------*/
   /*> READ__clear  ();                                                               <*/
   debug_uver   ylog_uvalue  ("feof"      , feof (*b_scrp));
   if (feof (*b_scrp)) {
      debug_uver   ylog_unote   ("already at end of file");
      debug_uver   ylog_uexit   (__FUNCTION__);
      return 0;
   }
   /*---(read for a good record)---------*/
   debug_uver   ylog_unote   ("read loop");
   while (1) {
      rc = READ__single (b_scrp, r_nline, r_dittoing, r_dmark, r_ditto, r_dline, r_nrecd, r_recd);
      debug_uver   ylog_uvalue  ("single"    , rc);
      if (rc <= 0) {
         debug_uver   ylog_unote   ("reached end of file");
         debug_uver   ylog_uexit   (__FUNCTION__);
         return 0;
      }
      if (rc == 2)  continue;
      debug_uver   ylog_unote   ("got a good record");
      break;
   }
   debug_uver   ylog_uinfo   ("r_recd"    , r_recd);
   /*---(complete)-----------------------*/
   debug_uver   ylog_uexitr  (__FUNCTION__, 1);
   return 1;
}


