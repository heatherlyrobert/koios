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
   DEBUG_UVER   yLOG_uenter  (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_stage != NULL)  strlcpy  (r_stage, "··/·", LEN_SHORT);
   /*---(defense)------------------------*/
   DEBUG_UVER   yLOG_upoint  ("a_scrp"    , a_scrp);
   --rce;  if (a_scrp == NULL) {
      DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_UVER   yLOG_upoint  ("a_verb"    , a_verb);
   --rce;  if (a_verb == NULL) {
      DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_UVER   yLOG_upoint  ("a_field"   , a_field);
   --rce;  if (a_field == NULL) {
      DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(ward-off)-----------------------*/
   if (strcmp ("SCRP" , a_verb) != 0) {
      DEBUG_UVER   yLOG_unote   ("only applies to scripts");
      DEBUG_UVER   yLOG_uexit   (__FUNCTION__);
      return 0;
   }
   /*---(prepare)------------------------*/
   strlcpy  (t, a_field, LEN_LABEL);
   ystrutrim (t, LEN_LABEL);
   DEBUG_UVER   yLOG_unote   (t);
   l = strlen (t);
   DEBUG_UVER   yLOG_uvalue  ("l"         , l);
   --rce;  if (l <  4) {
      DEBUG_UVER   yLOG_unote   ("incomplete and bad");
      DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   if (l == 4) {
      DEBUG_UVER   yLOG_unote   ("only the verb, nothing to do");
      DEBUG_UVER   yLOG_uexit   (__FUNCTION__);
      return 0;
   }
   strlcpy  (t, a_field + 4, LEN_LABEL);
   ystrutrim (t, LEN_LABEL);
   /*---(check begin marker)-------------*/
   x_pos = 0;
   DEBUG_UVER   yLOG_uchar   ("t[x_pos]"  , t [x_pos]);
   --rce;  if (t [x_pos] != '[') {
      yLOGS_err ("%s:%d:%d: error: %s identifier, illegal char '%c' after verb, maybe stage, e.g., [1a]", a_scrp, a_line, x_pos, a_verb, t [x_pos]);
      DEBUG_UVER   yLOG_unote   ("meaningless junk found after SCRP verb");
      DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   q = strchr (a_field, '[');
   x_beg = q - a_field;
   DEBUG_UVER   yLOG_uvalue  ("x_beg"     , x_beg);
   /*---(check begin marker)-------------*/
   x_pos = 0;
   l = strlen (t);
   DEBUG_UVER   yLOG_uvalue  ("l"         , l);
   --rce;  if (l == 4) {
      DEBUG_UVER   yLOG_unote   ("short form");
   } else if  (l == 6) {
      DEBUG_UVER   yLOG_unote   ("long form");
   } else {
      yLOGS_err ("%s:%d:%d: error: %s identifier, stage ¶%s¶ must be 4c ¶[1a]¶ or 6c ¶[1a/B]", a_scrp, a_line, x_beg + x_pos, a_verb, t);
      DEBUG_UVER   yLOG_unote   ("stage identifier must be 4 or 6 characters");
      DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(check end marker)---------------*/
   if (l == 4)  x_pos = 3;
   else         x_pos = 5;
   DEBUG_UVER   yLOG_uchar   ("q[x_pos]"  , q [x_pos]);
   --rce;  if (q [x_pos] != ']') {
      yLOGS_err ("%s:%d:%d: error: %s identifier, stage uses wrong end bracket '%c' vs ']', e.g., [1a]", a_scrp, a_line, x_beg + x_pos, a_verb, q [x_pos]);
      DEBUG_UVER   yLOG_unote   ("no end stage ']' marker found");
      DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(check wave)---------------------*/
   x_pos = 1;
   DEBUG_UVER   yLOG_uchar   ("q[x_pos]"  , q [x_pos]);
   --rce;  if (strchr ("·" YSTR_NUMBER, q [x_pos]) == NULL) {
      yLOGS_err ("%s:%d:%d: error: %s identifier, wave (%c) not a number, e.g., [1a]", a_scrp, a_line, x_beg + x_pos, a_verb, q [x_pos]);
      DEBUG_UVER   yLOG_unote   ("wave is not a number");
      DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   x_wave   = q [x_pos];
   /*---(check stage)--------------------*/
   x_pos = 2;
   DEBUG_UVER   yLOG_uchar   ("q[x_pos]"  , q [x_pos]);
   --rce;  if (strchr ("·" YSTR_LOWER, q [x_pos]) == NULL) {
      yLOGS_err ("%s:%d:%d: error: %s identifier, stage (%c) not a lower-case letter, e.g., [1a]", a_scrp, a_line, x_beg + x_pos, a_verb, q [x_pos]);
      DEBUG_UVER   yLOG_unote   ("stage is not lower-case");
      DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   x_stage  = q [x_pos];
   /*---(check rating)-------------------*/
   if (l == 6) {
      DEBUG_UVER   yLOG_unote   ("long-form");
      x_pos = 3;
      DEBUG_UVER   yLOG_uchar   ("t[x_pos]"  , t [x_pos]);
      --rce;  if (t [x_pos] != '/') {
         yLOGS_err ("%s:%d:%d: error: %s identifier, illegal char '%c' within long form, e.g., [1a/K]", a_scrp, a_line, x_pos, a_verb, t [x_pos]);
         DEBUG_UVER   yLOG_unote   ("meaningless junk found after SCRP verb");
         DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
         return rce;
      }
      x_pos = 4;
      DEBUG_UVER   yLOG_uchar   ("q[x_pos]"  , q [x_pos]);
      --rce;  if (strchr ("·" YSTR_UPLOW, q [x_pos]) == NULL) {
         yLOGS_err ("%s:%d:%d: error: %s identifier, rating (%c) not a upper-case letter, e.g., [1a/K]", a_scrp, a_line, x_beg + x_pos, a_verb, q [x_pos]);
         DEBUG_UVER   yLOG_unote   ("rating is not upper-case");
         DEBUG_UVER   yLOG_uexitr  (__FUNCTION__, rce);
         return rce;
      }
      x_rating = q [x_pos];
   }
   /*> printf ("%c %c %c\n", x_wave, x_stage, x_rating);                              <*/
   /*---(save)---------------------------*/
   if (r_stage != NULL)  sprintf (r_stage, "%c%c/%c", x_wave, x_stage, x_rating);
   /*---(complete)-----------------------*/
   DEBUG_UVER   yLOG_uexit   (__FUNCTION__);
   return 1;
}


