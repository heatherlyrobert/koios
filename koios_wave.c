/*===============================[[ beg-code ]]===============================*/
#include    "koios.h"        /* LOCAL  : main header                          */


static char  w_name [LEN_HUND] = "";
static FILE *w_file  = NULL;

char
WAVE_parse              (char *p)
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
      yURG_err (YURG_FATAL, "%s:%d:3: error: %s identifier, uses wrong brackets, e.g., [Àë]", my.n_scrp, my.n_line, my.verb);
      DEBUG_INPT   yLOG_snote   ("does not begin right");
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(positions)----------------------*/
   --rce;  if (strchr (YSTR_SUBS , q [1]) == NULL) {
      yURG_err (YURG_FATAL, "%s:%d:1: error: %s identifier, not a subscript (%s) for wave, e.g., [Àë]", my.n_scrp, my.n_line, my.verb, YSTR_SUBS);
      DEBUG_INPT   yLOG_snote   ("does not lead with symbol");
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   --rce;  if (strchr (YSTR_GREEK, q [2]) == NULL) {
      yURG_err (YURG_FATAL, "%s:%d:2: error: %s identifier, not a greek letter (%s) for stage, e.g., [Àë]", my.n_scrp, my.n_line, my.verb, YSTR_GREEK);
      DEBUG_INPT   yLOG_snote   ("does not end with greek letter");
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(integrated)---------------------*/
   --rce;  if (q [1] == 'À' && strchr ("èéêë", q [2]) != NULL)  ;
   else    if (q [1] == 'Á' && strchr ("ìíîï", q [2]) != NULL)  ;
   else    if (q [1] == 'Â' && strchr ("ðñòó", q [2]) != NULL)  ;
   else    if (q [1] == 'Ã' && strchr ("ôõö÷", q [2]) != NULL)  ;
   else    if (q [1] == 'Ä' && strchr ("øùúû", q [2]) != NULL)  ;
   else    if (q [1] == 'Å' && strchr ("üýþÿ", q [2]) != NULL)  ;
   else {
      yURG_err (YURG_FATAL, "%s:%d:1: error: %s identifier, wave (%c) and stage (%c) combination are not legal", my.n_scrp, my.n_line, my.verb, q [1], q [2]);
      DEBUG_INPT   yLOG_snote   ("does not lead with symbol");
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
WAVE_open          (char a_name [LEN_HUND])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   /*---(header)-------------------------*/
   DEBUG_PROG   yLOG_senter  (__FUNCTION__);
   /*---(already open)-------------------*/
   DEBUG_OUTP   yLOG_snote   (a_name);
   --rce;  if (a_name == NULL) {
      DEBUG_PROG   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_OUTP   yLOG_spoint  (w_file);
   --rce;  if (w_file != NULL) {
      DEBUG_PROG   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(open wave file)-----------------*/
   w_file = fopen (a_name, "wt");
   DEBUG_OUTP   yLOG_spoint  (w_file);
   --rce;  if (w_file == NULL) {
      DEBUG_PROG   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_OUTP   yLOG_snote   ("open");
   /*---(save name)----------------------*/
   strlcpy (w_name, a_name, LEN_HUND);
   /*---(complete)-----------------------*/
   DEBUG_PROG   yLOG_sexit   (__FUNCTION__);
   return 0;
}

char
WAVE_scrp               (char a_stage, char a_wave, char a_base [LEN_TITLE], char a_scrp, char a_desc [LEN_HUND])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   /*---(header)-------------------------*/
   DEBUG_PROG   yLOG_senter  (__FUNCTION__);
   /*---(already open)-------------------*/
   DEBUG_OUTP   yLOG_spoint  (w_file);
   --rce;  if (w_file == NULL) {
      DEBUG_PROG   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(write)--------------------------*/
   fprintf (w_file, "%c  %c  %-25.25s  %2d  %-65.65s \n", a_stage, a_wave, a_base, a_scrp, a_desc);
   /*---(complete)-----------------------*/
   DEBUG_PROG   yLOG_sexit   (__FUNCTION__);
   return 0;
}

char         /*--> close script file ---------------------[ ------ [ ------ ]-*/
WAVE_close         (void)
{
   /*---(locals)-----------+-----------+-*/
   char        rc          = 0;
   char        rce         = -10;
   /*---(header)-------------------------*/
   DEBUG_PROG   yLOG_senter  (__FUNCTION__);
   /*---(close wave file)----------------*/
   DEBUG_INPT   yLOG_spoint  (w_file);
   --rce;  if (w_file == NULL) {
      DEBUG_PROG   yLOG_snote   ("already open");
      DEBUG_PROG   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   rc = fclose (w_file);
   --rce;  if (rc != 0) {
      DEBUG_PROG   yLOG_snote   ("can not close");
      DEBUG_PROG   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(ground pointer)-----------------*/
   strlcpy (w_name, "", LEN_HUND);
   w_file = NULL;
   /*---(complete)-----------------------*/
   DEBUG_PROG   yLOG_exit    (__FUNCTION__);
   return 0;
}


