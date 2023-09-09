/*===============================[[ beg-code ]]===============================*/
#include    "koios.h"        /* LOCAL  : main header                          */



/*====================------------------------------------====================*/
/*===----                         file level                           ----===*/
/*====================------------------------------------====================*/
static void  o___FILE____________o () { return; }

char
READ_open               (cchar a_name [LEN_RECD], cchar a_dir, FILE **r_file, int *r_line)
{
   /*---(locals)-----------+-----------+-*/
   char        rce         = -10;           /* return code for errors         */
   char        x_mode      [LEN_SHORT] = "";
   char        x_name      [LEN_PATH]  = "";
   /*---(header)-------------------------*/
   DEBUG_PROG   yLOG_enter   (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_line != NULL)  *r_line = 0;
   /*---(defense)------------------------*/
   DEBUG_OUTP   yLOG_point   ("a_name"    , a_name);
   --rce;  if (a_name  == NULL || a_name [0] == '\0') {
      DEBUG_PROG   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_OUTP   yLOG_info    ("a_name"    , a_name);
   DEBUG_OUTP   yLOG_point   ("r_file"    , r_file);
   --rce;  if (r_file  == NULL) {
      DEBUG_PROG   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_OUTP   yLOG_point   ("*r_file"   , *r_file);
   --rce;  if (*r_file != NULL) {
      DEBUG_PROG   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(mode)---------------------------*/
   DEBUG_OUTP   yLOG_char    ("a_dir"     , a_dir);
   --rce;  switch (a_dir) {
   case 'r'  :
      strcpy (x_mode, "rt");
      break;
   case 'w'  :
      strcpy (x_mode, "wt");
      break;
   default   :
      DEBUG_PROG   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
      break;
   }
   DEBUG_OUTP   yLOG_info    ("x_mode"    , x_mode);
   /*---(full name)----------------------*/
   snprintf (x_name, LEN_PATH, "%s/%s", my.cwd, a_name);
   DEBUG_OUTP   yLOG_info    ("x_name"    , x_name);
   /*---(open)---------------------------*/
   *r_file = fopen (a_name, x_mode);
   DEBUG_OUTP   yLOG_point   ("*r_file"   , *r_file);
   --rce;  if (*r_file == NULL) {
      yURG_err (YURG_FATAL, "file å%sæ could not be openned", a_name);
      DEBUG_PROG   yLOG_fatal   ("can not open script file");
      DEBUG_PROG   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_INPT   yLOG_note    ("script file open");
   /*---(complete)-----------------------*/
   DEBUG_PROG   yLOG_exit    (__FUNCTION__);
   return 0;
}

char         /*--> close script file ---------------------[ ------ [ ------ ]-*/
READ_close              (FILE **b_file)
{
   /*---(locals)-----------+-----------+-*/
   char        rc          = 0;
   char        rce         = -10;
   /*---(header)-------------------------*/
   DEBUG_PROG   yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   DEBUG_OUTP   yLOG_point   ("b_file"    , b_file);
   --rce;  if (b_file  == NULL) {
      DEBUG_PROG   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_OUTP   yLOG_point   ("*b_file"   , *b_file);
   --rce;  if (*b_file == NULL) {
      DEBUG_PROG   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(close)--------------------------*/
   rc = fclose (*b_file);
   DEBUG_OUTP   yLOG_value   ("rc"        , rc);
   --rce;  if (rc < 0) {
      DEBUG_PROG   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(default)------------------------*/
   *b_file = NULL;
   /*---(complete)-----------------------*/
   DEBUG_PROG   yLOG_exit    (__FUNCTION__);
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
   DEBUG_INPT   yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   DEBUG_INPT   yLOG_point   ("a_scrp"    , a_scrp);
   --rce;  if (a_scrp == NULL) {
      DEBUG_INPT   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   DEBUG_INPT   yLOG_point   ("*a_scrp"   , *a_scrp);
   --rce;  if (*a_scrp == NULL) {
      DEBUG_INPT   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   DEBUG_INPT   yLOG_point   ("r_nline"   , r_nline);
   --rce;  if (r_nline == NULL) {
      DEBUG_INPT   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_INPT   yLOG_point   ("r_dittoing", r_dittoing);
   --rce;  if (r_dittoing == NULL) {
      DEBUG_INPT   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_INPT   yLOG_point   ("r_dmark"   , r_dmark);
   --rce;  if (r_dmark == NULL) {
      DEBUG_INPT   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_INPT   yLOG_point   ("r_ditto"   , r_ditto);
   --rce;  if (r_ditto == NULL) {
      DEBUG_INPT   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_INPT   yLOG_point   ("r_dline"   , r_dline);
   --rce;  if (r_dline == NULL) {
      DEBUG_INPT   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_INPT   yLOG_point   ("r_nrecd"   , r_nrecd);
   --rce;  if (r_nrecd == NULL) {
      DEBUG_INPT   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_INPT   yLOG_point   ("r_recd"    , r_recd);
   --rce;  if (r_recd == NULL) {
      DEBUG_INPT   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(complete)-----------------------*/
   DEBUG_INPT   yLOG_exit    (__FUNCTION__);
   return 0;
}

char         /*--> clean a script record -----------------[ leaf   [ ------ ]-*/
READ__clear             (void)
{
   /*---(header)-------------------------*/
   DEBUG_INPT   yLOG_senter  (__FUNCTION__);
   /*---(save value)---------------------*/
   if (strcmp (my.verb, "DITTO") != 0)  ystrlcpy (my.last, my.verb, LEN_LABEL);
   /*---(input vars)---------------------*/
   my.verb        [0] = '\0';
   my.p_conv          = NULL;
   my.p_code          = NULL;
   my.spec            =  '-';
   my.status          =  '-';
   my.vers            =   -1;
   my.desc        [0] = '\0';
   my.meth        [0] = '\0';
   my.args        [0] = '\0';
   my.test        [0] = '\0';
   my.expe        [0] = '\0';
   my.retn        [0] = '\0';
   my.code        [0] = '\0';
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
   DEBUG_INPT   yLOG_enter   (__FUNCTION__);
   /*---(default)---------------------*/
   if (r_recd != NULL)  strcpy (r_recd, "");
   /*---(read next)-------------------*/
   DEBUG_INPT   yLOG_note    ("read script file");
   fgets (x_recd, LEN_RECD, *b_scrp);
   if (feof (*b_scrp)) {
      DEBUG_INPT   yLOG_note    ("hit end of file");
      DEBUG_INPT   yLOG_exit    (__FUNCTION__);
      return 0;
   }
   /*---(handle line numbers)---------*/
   DEBUG_INPT   yLOG_complex ("line#"     , "%4d nline, %c, %4d dline", *r_nline, *r_dittoing, *r_dline);
   rc = DITTO_read_numbering (*r_dittoing, *r_ditto, r_nline, r_dline);
   DEBUG_INPT   yLOG_value   ("ditto prep", rc);
   if (rc == 2) {
      DEBUG_INPT   yLOG_note    ("quickly to next record");
      DEBUG_INPT   yLOG_exitr   (__FUNCTION__, 2);
      return 2;
   }
   /*---(prepare)---------------------*/
   x_len = ystrllen (x_recd, LEN_RECD);
   if (x_len > 0)  x_recd [--x_len] = '\0';
   DEBUG_INPT   yLOG_complex ("x_recd"    , "%3då%sæ", x_len, x_recd);
   /*---(filter)----------------------*/
   if (x_recd [0] == '\0') {
      DEBUG_INPT   yLOG_note    ("SKIP, empty");
      if (*r_dittoing == 'y')  DITTO_end (b_scrp, r_dittoing, r_dmark, r_ditto, r_dline);
      DEBUG_INPT   yLOG_exitr   (__FUNCTION__, 2);
      return 2;
   }
   if (x_len > 1 && x_recd [0] == '#' && x_recd [1] != '>') {
      DEBUG_INPT   yLOG_note    ("SKIP, comment");
      if (*r_dittoing == 'y')  DITTO_end (b_scrp, r_dittoing, r_dmark, r_ditto, r_dline);
      DEBUG_INPT   yLOG_exitr   (__FUNCTION__, 2);
      return 2;
   }
   DEBUG_INPT   yLOG_value   ("length"    , x_len);
   if (x_len <=  5)  {
      DEBUG_INPT   yLOG_note    ("SKIP, too short");
      if (*r_dittoing == 'y')  DITTO_end (b_scrp, r_dittoing, r_dmark, r_ditto, r_dline);
      DEBUG_INPT   yLOG_exitr   (__FUNCTION__, 2);
      return 2;
   }
   /*---(check other end ditto)-------*/
   if (*r_dittoing == 'y' && *r_dline != *r_ditto)  {
      ystrlcpy (t, x_recd, LEN_LABEL);
      p = strtok (t, "");
      p = strtok (p, " ");
      DEBUG_INPT   yLOG_point   ("p"         , p);
      if (p != NULL) {
         ystrltrim (p, ySTR_BOTH, LEN_LABEL);
         DEBUG_INPT   yLOG_info    ("p"         , p);
         rc = VERB_dittoable (p);
         DEBUG_INPT   yLOG_value   ("dittoable" , rc);
         if (rc != 1) {
            DITTO_end (b_scrp, r_dittoing, r_dmark, r_ditto, r_dline);
            DEBUG_INPT   yLOG_exitr   (__FUNCTION__, 2);
            return 2;
         }
      }
   }
   /*---(save-back)-------------------*/
   DEBUG_INPT   yLOG_note    ("save copy of source record");
   ystrlundelay (x_recd, LEN_RECD);
   ++(*r_nrecd);
   if (r_recd != NULL)  ystrlcpy (r_recd, x_recd, LEN_RECD);
   /*---(complete)-----------------------*/
   DEBUG_INPT   yLOG_exit    (__FUNCTION__);
   return 1;
}

char         /*--> read script record --------------------[ leaf   [ ------ ]-*/
READ_next               (FILE **b_scrp, int *r_nline, char *r_dittoing, char *r_dmark, int *r_ditto, int *r_dline, int *r_nrecd, char r_recd [LEN_RECD])
{
   /*---(locals)-----------+-----------+-*/
   int         rc          = 0;             /* generic return code            */
   char        rce         = -10;           /* return code for errors         */
   /*---(header)-------------------------*/
   DEBUG_INPT   yLOG_enter   (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_recd != NULL)  strcpy (r_recd, "");
   /*---(defense)------------------------*/
   rc = READ__defense (b_scrp, r_nline, r_dittoing, r_dmark, r_ditto, r_dline, r_nrecd, r_recd);
   DEBUG_INPT   yLOG_value   ("defense"   , rc);
   --rce;  if (rc < 0) {
      DEBUG_INPT   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   /*---(prepare)------------------------*/
   /*> READ__clear  ();                                                               <*/
   DEBUG_INPT   yLOG_value   ("feof"      , feof (*b_scrp));
   if (feof (*b_scrp)) {
      DEBUG_INPT   yLOG_note    ("already at end of file");
      DEBUG_INPT   yLOG_exit    (__FUNCTION__);
      return 0;
   }
   /*---(read for a good record)---------*/
   DEBUG_INPT   yLOG_note    ("read loop");
   while (1) {
      rc = READ__single (b_scrp, r_nline, r_dittoing, r_dmark, r_ditto, r_dline, r_nrecd, r_recd);
      DEBUG_INPT   yLOG_value   ("single"    , rc);
      if (rc <= 0) {
         DEBUG_INPT   yLOG_note    ("reached end of file");
         DEBUG_INPT   yLOG_exit    (__FUNCTION__);
         return 0;
      }
      if (rc == 2)  continue;
      DEBUG_INPT   yLOG_note    ("got a good record");
      break;
   }
   /*---(complete)-----------------------*/
   DEBUG_INPT   yLOG_exitr   (__FUNCTION__, 1);
   return 1;
}


