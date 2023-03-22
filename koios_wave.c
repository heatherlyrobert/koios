/*===============================[[ beg-code ]]===============================*/
#include    "koios.h"        /* LOCAL  : main header                          */


static char  w_name [LEN_HUND] = "";
static FILE *w_file  = NULL;



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


