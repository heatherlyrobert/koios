/*===============================[[ beg-code ]]===============================*/
#include    "koios.h"



char
WAVE_parse              (char a_scrp [LEN_TITLE], int a_line, char a_verb [LEN_LABEL], char a_field [LEN_LABEL], char r_stage [LEN_SHORT])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   int         l           =    0;
   char        t           [LEN_LABEL] = "";
   char       *q           = NULL;
   char        x_beg       =    0;
   char        x_pos       =    0;
   char        x_wave      =  '·';
   char        x_stage     =  '·';
   char        x_rating    =  '·';
   /*---(header)-------------------------*/
   debug_uver   ylog_uenter  (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_stage != NULL)  strlcpy  (r_stage, "··/·", LEN_SHORT);
   /*---(defense)------------------------*/
   debug_uver   ylog_upoint  ("a_scrp"    , a_scrp);
   --rce;  if (a_scrp == NULL) {
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   debug_uver   ylog_upoint  ("a_verb"    , a_verb);
   --rce;  if (a_verb == NULL) {
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   debug_uver   ylog_upoint  ("a_field"   , a_field);
   --rce;  if (a_field == NULL) {
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(ward-off)-----------------------*/
   if (strcmp ("SCRP" , a_verb) != 0) {
      debug_uver   ylog_unote   ("only applies to scripts");
      debug_uver   ylog_uexit   (__FUNCTION__);
      return 0;
   }
   /*---(prepare)------------------------*/
   strlcpy  (t, a_field, LEN_LABEL);
   ystrutrim (t, LEN_LABEL);
   debug_uver   ylog_unote   (t);
   l = strlen (t);
   debug_uver   ylog_uvalue  ("l"         , l);
   --rce;  if (l <  4) {
      debug_uver   ylog_unote   ("incomplete and bad");
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   if (l == 4) {
      debug_uver   ylog_unote   ("only the verb, nothing to do");
      debug_uver   ylog_uexit   (__FUNCTION__);
      return 0;
   }
   strlcpy  (t, a_field + 4, LEN_LABEL);
   ystrutrim (t, LEN_LABEL);
   /*---(check begin marker)-------------*/
   x_pos = 0;
   debug_uver   ylog_uchar   ("t[x_pos]"  , t [x_pos]);
   --rce;  if (t [x_pos] != '[') {
      yerr_uerror ("%s:%d:%d: error: %s identifier, illegal char '%c' after verb, maybe stage, e.g., [1a]", a_scrp, a_line, x_pos, a_verb, t [x_pos]);
      debug_uver   ylog_unote   ("meaningless junk found after SCRP verb");
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   q = strchr (a_field, '[');
   x_beg = q - a_field;
   debug_uver   ylog_uvalue  ("x_beg"     , x_beg);
   /*---(check begin marker)-------------*/
   x_pos = 0;
   l = strlen (t);
   debug_uver   ylog_uvalue  ("l"         , l);
   --rce;  if (l == 4) {
      debug_uver   ylog_unote   ("short form");
   } else if  (l == 6) {
      debug_uver   ylog_unote   ("long form");
   } else {
      yerr_uerror ("%s:%d:%d: error: %s identifier, stage ¶%s¶ must be 4c ¶[1a]¶ or 6c ¶[1a/B]", a_scrp, a_line, x_beg + x_pos, a_verb, t);
      debug_uver   ylog_unote   ("stage identifier must be 4 or 6 characters");
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(check end marker)---------------*/
   if (l == 4)  x_pos = 3;
   else         x_pos = 5;
   debug_uver   ylog_uchar   ("q[x_pos]"  , q [x_pos]);
   --rce;  if (q [x_pos] != ']') {
      yerr_uerror ("%s:%d:%d: error: %s identifier, stage uses wrong end bracket '%c' vs ']', e.g., [1a]", a_scrp, a_line, x_beg + x_pos, a_verb, q [x_pos]);
      debug_uver   ylog_unote   ("no end stage ']' marker found");
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(check wave)---------------------*/
   x_pos = 1;
   debug_uver   ylog_uchar   ("q[x_pos]"  , q [x_pos]);
   --rce;  if (strchr ("·" YSTR_NUMBER, q [x_pos]) == NULL) {
      yerr_uerror ("%s:%d:%d: error: %s identifier, wave (%c) not a number, e.g., [1a]", a_scrp, a_line, x_beg + x_pos, a_verb, q [x_pos]);
      debug_uver   ylog_unote   ("wave is not a number");
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   x_wave   = q [x_pos];
   /*---(check stage)--------------------*/
   x_pos = 2;
   debug_uver   ylog_uchar   ("q[x_pos]"  , q [x_pos]);
   --rce;  if (strchr ("·" YSTR_LOWER, q [x_pos]) == NULL) {
      yerr_uerror ("%s:%d:%d: error: %s identifier, stage (%c) not a lower-case letter, e.g., [1a]", a_scrp, a_line, x_beg + x_pos, a_verb, q [x_pos]);
      debug_uver   ylog_unote   ("stage is not lower-case");
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   x_stage  = q [x_pos];
   /*---(check rating)-------------------*/
   if (l == 6) {
      debug_uver   ylog_unote   ("long-form");
      x_pos = 3;
      debug_uver   ylog_uchar   ("t[x_pos]"  , t [x_pos]);
      --rce;  if (t [x_pos] != '/') {
         yerr_uerror ("%s:%d:%d: error: %s identifier, illegal char '%c' within long form, e.g., [1a/K]", a_scrp, a_line, x_pos, a_verb, t [x_pos]);
         debug_uver   ylog_unote   ("meaningless junk found after SCRP verb");
         debug_uver   ylog_uexitr  (__FUNCTION__, rce);
         return rce;
      }
      x_pos = 4;
      debug_uver   ylog_uchar   ("q[x_pos]"  , q [x_pos]);
      --rce;  if (strchr ("·" YSTR_UPLOW, q [x_pos]) == NULL) {
         yerr_uerror ("%s:%d:%d: error: %s identifier, rating (%c) not a upper-case letter, e.g., [1a/K]", a_scrp, a_line, x_beg + x_pos, a_verb, q [x_pos]);
         debug_uver   ylog_unote   ("rating is not upper-case");
         debug_uver   ylog_uexitr  (__FUNCTION__, rce);
         return rce;
      }
      x_rating = q [x_pos];
   }
   /*> printf ("%c %c %c\n", x_wave, x_stage, x_rating);                              <*/
   /*---(save)---------------------------*/
   if (r_stage != NULL)  sprintf (r_stage, "%c%c/%c", x_wave, x_stage, x_rating);
   /*---(complete)-----------------------*/
   debug_uver   ylog_uexit   (__FUNCTION__);
   return 1;
}


