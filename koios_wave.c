/*===============================[[ beg-code ]]===============================*/
#include    "koios.h"        /* LOCAL  : main header                          */



char
WAVE_parse              (char a_scrp [LEN_TITLE], int a_line, char a_verb [LEN_LABEL], char a_field [LEN_LABEL], char r_stage [LEN_SHORT])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   int         x_len       =    0;
   char        t           [LEN_LABEL] = "";
   char       *q           = NULL;
   char        x_beg       =    0;
   char        x_pos       =    0;
   char        x_wave      =  '∑';
   char        x_stage     =  '∑';
   /*---(header)-------------------------*/
   DEBUG_INPT   yLOG_senter  (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_stage != NULL)  ystrlcpy  (r_stage, "", LEN_SHORT);
   /*---(defense)------------------------*/
   DEBUG_INPT   yLOG_spoint  (a_scrp);
   --rce;  if (a_scrp == NULL) {
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_INPT   yLOG_spoint  (a_verb);
   --rce;  if (a_verb == NULL) {
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_INPT   yLOG_spoint  (a_field);
   --rce;  if (a_field == NULL) {
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(ward-off)-----------------------*/
   if (strcmp ("SCRP" , a_verb) != 0) {
      DEBUG_INPT   yLOG_snote   ("only applies to scripts");
      DEBUG_INPT   yLOG_sexit   (__FUNCTION__);
      return 0;
   }
   /*---(prepare)------------------------*/
   ystrlcpy  (t, a_field, LEN_LABEL);
   ystrltrim (t, ySTR_BOTH, LEN_LABEL);
   DEBUG_INPT   yLOG_note    (t);
   x_len = strlen (t);
   DEBUG_INPT   yLOG_sint    (x_len);
   --rce;  if (x_len <  4) {
      DEBUG_INPT   yLOG_snote   ("incomplete and bad");
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   if (x_len == 4) {
      DEBUG_INPT   yLOG_snote   ("only the verb, nothing to do");
      DEBUG_INPT   yLOG_sexit   (__FUNCTION__);
      return 0;
   }
   ystrlcpy  (t, a_field + 4, LEN_LABEL);
   ystrltrim (t, ySTR_BOTH, LEN_LABEL);
   /*---(check begin marker)-------------*/
   x_pos = 0;
   DEBUG_INPT   yLOG_schar   (t [x_pos]);
   --rce;  if (t [x_pos] != '[') {
      /*> yURG_err (YURG_FATAL, "%s:%d:%d: error: %s identifier, illegal char '%c' after verb, maybe stage, e.g., [¡Ï]", a_scrp, a_line, x_pos, a_verb, t [x_pos]);   <*/
      DEBUG_INPT   yLOG_snote   ("meaningless junk found after SCRP verb");
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   q = strchr (a_field, '[');
   x_beg = q - a_field;
   DEBUG_INPT   yLOG_sint    (x_beg);
   /*---(check begin marker)-------------*/
   x_pos = 0;
   x_len = strlen (t);
   DEBUG_INPT   yLOG_sint    (x_len);
   --rce;  if (x_len != 4) {
      /*> yURG_err (YURG_FATAL, "%s:%d:%d: error: %s identifier, stage ∂%s∂ must be exactly 4 characters, e.g., [¡Ï]", a_scrp, a_line, x_beg + x_pos, a_verb, t);   <*/
      DEBUG_INPT   yLOG_snote   ("stage identifier must be 4 characters");
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(check end marker)---------------*/
   x_pos = 3;
   DEBUG_INPT   yLOG_schar   (q [x_pos]);
   --rce;  if (q [x_pos] != ']') {
      /*> yURG_err (YURG_FATAL, "%s:%d:%d: error: %s identifier, stage uses wrong end bracket '%c' vs ']', e.g., [¡Ï]", a_scrp, a_line, x_beg + x_pos, a_verb, q [x_pos]);   <*/
      DEBUG_INPT   yLOG_snote   ("no end stage ']' marker found");
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(check wave)---------------------*/
   x_pos = 1;
   DEBUG_INPT   yLOG_schar   (q [x_pos]);
   --rce;  if (strchr (YSTR_NUMBER, q [x_pos]) == NULL) {
      /*> yURG_err (YURG_FATAL, "%s:%d:%d: error: %s identifier, wave (%c) not a number, e.g., [1a]", a_scrp, a_line, x_beg + x_pos, a_verb, q [x_pos]);   <*/
      DEBUG_INPT   yLOG_snote   ("stage is not a number");
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   x_wave  = q [x_pos];
   /*---(check stage)--------------------*/
   x_pos = 2;
   DEBUG_INPT   yLOG_schar   (q [x_pos]);
   --rce;  if (strchr (YSTR_LOWER, q [x_pos]) == NULL) {
      /*> yURG_err (YURG_FATAL, "%s:%d:%d: error: %s identifier, stage (%c) not a lower-case letter, e.g., [1a]", a_scrp, a_line, x_beg + x_pos, a_verb, q [x_pos]);   <*/
      DEBUG_INPT   yLOG_snote   ("does not end with greek letter");
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   x_stage = q [x_pos];
   /*---(save)---------------------------*/
   if (r_stage != NULL)  sprintf (r_stage, "%c%c", x_wave, x_stage);
   /*---(complete)-----------------------*/
   DEBUG_INPT   yLOG_sexit   (__FUNCTION__);
   return 0;
}

char
WAVE_entry              (FILE *a_wave, char a_stageid, char a_waveid, char a_nscrp [LEN_TITLE], char a_seq, char a_desc [LEN_HUND])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   /*---(header)-------------------------*/
   DEBUG_PROG   yLOG_senter  (__FUNCTION__);
   /*---(already open)-------------------*/
   DEBUG_OUTP   yLOG_spoint  (a_wave);
   --rce;  if (a_wave == NULL) {
      DEBUG_PROG   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(write)--------------------------*/
   fprintf (a_wave, "%c  %c  %-30.30s  %2d  %-65.65s \n", a_stageid, a_waveid, a_nscrp, a_seq, a_desc);
   fflush  (a_wave);
   /*---(complete)-----------------------*/
   DEBUG_PROG   yLOG_sexit   (__FUNCTION__);
   return 0;
}

/*>                                                                                                                                                                                                                                                                                                 <* 
 *> WAVE ß 24.04.09.04.37.46.2.15.100 ß 1234567890 ß koios                ß koios_code.unit                ß  2 ß (CODE) verify handling of script verbs                            ß script               ß 1 ß a ß   0 ß   1 ß  12 ß 105 ß 12s ß    12 ß F ß  97 ß   6 ß   2 ß   1 ß     9 ß     <* 
 *> ß 1 ß a ß   0 ß   1 ß  12 ß 105 ß 12s ß    12 ß F ß  97 ß   6 ß   2 ß   1 ß     9 ß     <* 
 *>                                                                                                                                                                                                                                                                                                 <*/

char
WAVE_entry_new          (FILE *f, char a_proj [LEN_LABEL], char a_unit [LEN_TITLE], char a_scrp, char a_desc [LEN_LONG], char a_terse [LEN_LABEL], char a_wave, char a_stage, char a_nunit, char a_nscrp, short a_ncond, short a_nstep, char a_expe [LEN_SHORT], short a_expect, char a_result, short a_npass, short a_nfail, short a_nbadd, short a_nvoid, short a_actual)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   long        x_now       =    0;
   tTIME      *x_broke     = NULL;
   char        t           [LEN_TITLE] = "";
   /*---(header)-------------------------*/
   DEBUG_PROG   yLOG_senter  (__FUNCTION__);
   /*---(already open)-------------------*/
   DEBUG_OUTP   yLOG_spoint  (f);
   --rce;  if (f == NULL) {
      DEBUG_PROG   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   x_now  = time (NULL);
   strftime (t, LEN_TITLE, "%y.%m.%d.%H.%M.%S.%u.%W.%j", x_broke);
   /*---(write)--------------------------*/
   fprintf (f, "WAVE  %-26.26s  %10ld  %-20.20s  %-30.30s  %2d  %-70.70s  %-20.20s  %3d  %3d  %3d  %3d  %-3.3s  %3d  %c  %3d  %3d  %3d  %3d  %3d ", t, x_now, a_proj, a_unit, a_scrp, a_desc, a_terse, a_wave, a_stage, a_nunit, a_nscrp, a_ncond, a_nstep, a_expe, a_expect, a_result, a_npass, a_nfail, a_nbadd, a_nvoid, a_actual);
   fflush  (f);
   /*---(complete)-----------------------*/
   DEBUG_PROG   yLOG_sexit   (__FUNCTION__);
   return 0;
}

char
WAVE_to_code            (FILE *a_main, cchar a_nwave [LEN_TITLE])
{
}


