/*===============================[[ beg-code ]]===============================*/
#include    "koios.h"        /* LOCAL  : main header                          */


static char  w_name [LEN_HUND] = "";
/*> static FILE *w_file  = NULL;                                                      <*/



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
   char        x_wave      =  '·';
   char        x_stage     =  '·';
   /*---(header)-------------------------*/
   DEBUG_INPT   yLOG_senter  (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_stage != NULL)  strlcpy  (r_stage, "", LEN_SHORT);
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
   strlcpy  (t, a_field, LEN_LABEL);
   strltrim (t, ySTR_BOTH, LEN_LABEL);
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
   strlcpy  (t, a_field + 4, LEN_LABEL);
   strltrim (t, ySTR_BOTH, LEN_LABEL);
   /*---(check begin marker)-------------*/
   x_pos = 0;
   DEBUG_INPT   yLOG_schar   (t [x_pos]);
   --rce;  if (t [x_pos] != '[') {
      yURG_err (YURG_FATAL, "%s:%d:%d: error: %s identifier, illegal char '%c' after verb, maybe stage, e.g., [Áì]", a_scrp, a_line, x_pos, a_verb, t [x_pos]);
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
      yURG_err (YURG_FATAL, "%s:%d:%d: error: %s identifier, stage ¶%s¶ must be exactly 4 characters, e.g., [Áì]", a_scrp, a_line, x_beg + x_pos, a_verb, t);
      DEBUG_INPT   yLOG_snote   ("stage identifier must be 4 characters");
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(check end marker)---------------*/
   x_pos = 3;
   DEBUG_INPT   yLOG_schar   (q [x_pos]);
   --rce;  if (q [x_pos] != ']') {
      yURG_err (YURG_FATAL, "%s:%d:%d: error: %s identifier, stage uses wrong end bracket '%c' vs ']', e.g., [Áì]", a_scrp, a_line, x_beg + x_pos, a_verb, q [x_pos]);
      DEBUG_INPT   yLOG_snote   ("no end stage ']' marker found");
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(check wave)---------------------*/
   x_pos = 1;
   DEBUG_INPT   yLOG_schar   (q [x_pos]);
   --rce;  if (strchr (YSTR_SUBS, q [x_pos]) == NULL) {
      yURG_err (YURG_FATAL, "%s:%d:%d: error: %s identifier, wave (%c) not a subscript (%s), e.g., [Áì]", a_scrp, a_line, x_beg + x_pos, a_verb, q [x_pos], YSTR_SUBS);
      DEBUG_INPT   yLOG_snote   ("stage is not a number");
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   x_wave  = q [x_pos];
   /*---(check stage)--------------------*/
   x_pos = 2;
   DEBUG_INPT   yLOG_schar   (q [x_pos]);
   --rce;  if (strchr (YSTR_GREEK, q [x_pos]) == NULL) {
      yURG_err (YURG_FATAL, "%s:%d:%d: error: %s identifier, stage (%c) not a greek letter (%s), e.g., [Áì]", a_scrp, a_line, x_beg + x_pos, a_verb, q [x_pos], YSTR_GREEK);
      DEBUG_INPT   yLOG_snote   ("does not end with greek letter");
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   x_stage = q [x_pos];
   /*---(integrated)---------------------*/
   x_pos = 1;
   --rce;  if (x_wave == 'À' && strchr ("èéêë", x_stage) != NULL)  ;
   else    if (x_wave == 'Á' && strchr ("ìíîï", x_stage) != NULL)  ;
   else    if (x_wave == 'Â' && strchr ("ðñòó", x_stage) != NULL)  ;
   else    if (x_wave == 'Ã' && strchr ("ôõö÷", x_stage) != NULL)  ;
   else    if (x_wave == 'Ä' && strchr ("øùúû", x_stage) != NULL)  ;
   else    if (x_wave == 'Å' && strchr ("üýþÿ", x_stage) != NULL)  ;
   else {
      yURG_err (YURG_FATAL, "%s:%d:%d: error: %s identifier, wave (%c) and stage (%c) mismatched, e.g., [Áì]", a_scrp, a_line, x_beg + x_pos, a_verb, x_wave, x_stage);
      DEBUG_INPT   yLOG_snote   ("wave and stage combination not legal");
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(save)---------------------------*/
   if (r_stage != NULL)  sprintf (r_stage, "%c%c", x_wave, x_stage);
   /*---(complete)-----------------------*/
   DEBUG_INPT   yLOG_sexit   (__FUNCTION__);
   return 0;
}

/*> char                                                                              <* 
 *> WAVE_open          (char a_name [LEN_HUND])                                       <* 
 *> {                                                                                 <* 
 *>    /+---(locals)-----------+-----+-----+-+/                                       <* 
 *>    char        rce         =  -10;                                                <* 
 *>    /+---(header)-------------------------+/                                       <* 
 *>    DEBUG_PROG   yLOG_senter  (__FUNCTION__);                                      <* 
 *>    /+---(already open)-------------------+/                                       <* 
 *>    DEBUG_OUTP   yLOG_snote   (a_name);                                            <* 
 *>    --rce;  if (a_name == NULL) {                                                  <* 
 *>       DEBUG_PROG   yLOG_sexitr  (__FUNCTION__, rce);                              <* 
 *>       return rce;                                                                 <* 
 *>    }                                                                              <* 
 *>    DEBUG_OUTP   yLOG_spoint  (w_file);                                            <* 
 *>    --rce;  if (w_file != NULL) {                                                  <* 
 *>       DEBUG_PROG   yLOG_sexitr  (__FUNCTION__, rce);                              <* 
 *>       return rce;                                                                 <* 
 *>    }                                                                              <* 
 *>    /+---(open wave file)-----------------+/                                       <* 
 *>    w_file = fopen (a_name, "wt");                                                 <* 
 *>    DEBUG_OUTP   yLOG_spoint  (w_file);                                            <* 
 *>    --rce;  if (w_file == NULL) {                                                  <* 
 *>       DEBUG_PROG   yLOG_sexitr  (__FUNCTION__, rce);                              <* 
 *>       return rce;                                                                 <* 
 *>    }                                                                              <* 
 *>    DEBUG_OUTP   yLOG_snote   ("open");                                            <* 
 *>    /+---(save name)----------------------+/                                       <* 
 *>    strlcpy (w_name, a_name, LEN_HUND);                                            <* 
 *>    /+---(complete)-----------------------+/                                       <* 
 *>    DEBUG_PROG   yLOG_sexit   (__FUNCTION__);                                      <* 
 *>    return 0;                                                                      <* 
 *> }                                                                                 <*/

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

/*> char         /+--> close script file ---------------------[ ------ [ ------ ]-+/   <* 
 *> WAVE_close         (void)                                                          <* 
 *> {                                                                                  <* 
 *>    /+---(locals)-----------+-----------+-+/                                        <* 
 *>    char        rc          = 0;                                                    <* 
 *>    char        rce         = -10;                                                  <* 
 *>    /+---(header)-------------------------+/                                        <* 
 *>    DEBUG_PROG   yLOG_senter  (__FUNCTION__);                                       <* 
 *>    /+---(close wave file)----------------+/                                        <* 
 *>    DEBUG_INPT   yLOG_spoint  (w_file);                                             <* 
 *>    --rce;  if (w_file == NULL) {                                                   <* 
 *>       DEBUG_PROG   yLOG_snote   ("already open");                                  <* 
 *>       DEBUG_PROG   yLOG_sexitr  (__FUNCTION__, rce);                               <* 
 *>       return rce;                                                                  <* 
 *>    }                                                                               <* 
 *>    rc = fclose (w_file);                                                           <* 
 *>    --rce;  if (rc != 0) {                                                          <* 
 *>       DEBUG_PROG   yLOG_snote   ("can not close");                                 <* 
 *>       DEBUG_PROG   yLOG_sexitr  (__FUNCTION__, rce);                               <* 
 *>       return rce;                                                                  <* 
 *>    }                                                                               <* 
 *>    /+---(ground pointer)-----------------+/                                        <* 
 *>    strlcpy (w_name, "", LEN_HUND);                                                 <* 
 *>    w_file = NULL;                                                                  <* 
 *>    /+---(complete)-----------------------+/                                        <* 
 *>    DEBUG_PROG   yLOG_exit    (__FUNCTION__);                                       <* 
 *>    return 0;                                                                       <* 
 *> }                                                                                  <*/


