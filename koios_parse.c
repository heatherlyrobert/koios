/*===============================[[ beg-code ]]===============================*/
#include    "koios.h"        /* LOCAL  : main header                          */

/*
 *  ZERO globals referenced in file
 */

/*     a_spec    field    id    min   max   allowed  */
struct cPARSE {
   char        p_spec;
   char        p_col;
   char        p_field     [LEN_TERSE];
   char        p_min;
   short       p_max;
   char        p_allowed   [LEN_FULL];
   char        p_dest;
   char        p_place     [LEN_SHORT];
   char        p_def       [LEN_PATH];
} static s_parse [LEN_DESC] = {

   { KOIOS_STWO   ,  2,  "desc"      ,   0, LEN_LONG  , YSTR_SEVEN " "                           , KOIOS_FDESC , "·", "---(empty)-------------------------"   },

   { KOIOS_STHR   ,  2,  "desc"      ,   0, LEN_LONG  , YSTR_SEVEN " "                           , KOIOS_FDESC , "·", "---(empty)-------------------------"   },
   { KOIOS_STHR   ,  3,  "config"    ,   1, LEN_TITLE , YSTR_UPPER YSTR_LOWER YSTR_NUMBER "_."   , KOIOS_FFUNC , "·", "·"   },

   { KOIOS_SSCRP  ,  2,  "desc"      ,   0, LEN_LONG  , YSTR_SEVEN " "                           , KOIOS_FDESC , "·", "---(empty)-------------------------"   },
   { KOIOS_SSCRP  ,  3,  "duration"  ,   0, 4         , YSTR_NUMBER YSTR_LOWER "·"               , KOIOS_FTEST , "·", "0s"  },
   { KOIOS_SSCRP  ,  4,  "label"     ,   0, 15        , YSTR_UPPER YSTR_LOWER "·_"               , KOIOS_FRETN , "·", "tbd" },
   { KOIOS_SSCRP  ,  5,  "tested"    ,   0, LEN_HUND  , YSTR_UPPER YSTR_LOWER YSTR_NUMBER "· ,_" , KOIOS_FFUNC , "·", "·"   },

   { KOIOS_SSHAR  ,  2,  "desc"      ,   0, LEN_LONG  , YSTR_SEVEN " "                           , KOIOS_FDESC , "·", "---(empty)-------------------------"   },
   { KOIOS_SSHAR  ,  3,  "label"     ,   0, 14        , YSTR_UPPER YSTR_LOWER "·_"               , KOIOS_FRETN , "·", "tbd" },
   { KOIOS_SSHAR  ,  4,  "select"    ,   0, 15        , YSTR_ALLCHAR "·åæ"                       , KOIOS_FFUNC , "·", "å············æ" },
   { KOIOS_SSHAR  ,  5,  "subtitle"  ,   0, LEN_RECD  , YSTR_ALLCHAR "Ï· ,= -_"                  , KOIOS_FEXPE , "·", "Ï=·············, Ï=·············, Ï=·············, Ï=·············, Ï=·············, Ï=·············, Ï=·············, Ï=·············, Ï=·············, Ï=·············, Ï=·············, Ï=·············" },

   { KOIOS_SEXEC  ,  2,  "desc"      ,   0, LEN_LONG  , YSTR_SEVEN " "                           , KOIOS_FDESC , "·", "---(empty)-------------------------"   },
   { KOIOS_SEXEC  ,  3,  "function"  ,   1, LEN_TITLE , YSTR_UPPER YSTR_LOWER YSTR_NUMBER "_"    , KOIOS_FFUNC , "·", ""    },
   { KOIOS_SEXEC  ,  4,  "args"      ,   0, LEN_FULL  , YSTR_SEVEN " "                           , KOIOS_FARGS , "·", ""    },
   { KOIOS_SEXEC  ,  5,  "test"      ,   5, LEN_LABEL , YSTR_LOWER "_"                           , KOIOS_FTEST , "·", ""    },
   { KOIOS_SEXEC  ,  6,  "expect"    ,   1, LEN_RECD  , YSTR_SEVEN " "                           , KOIOS_FEXPE , "·", ""    },
   { KOIOS_SEXEC  ,  7,  "return"    ,   0, LEN_LABEL , YSTR_UPPER YSTR_LOWER YSTR_NUMBER "_"    , KOIOS_FRETN , "·", ""    },

   { KOIOS_SEKOH  ,  2,  "desc"      ,   0, LEN_LONG  , YSTR_SEVEN " "                           , KOIOS_FDESC , "·", "---(empty)-------------------------"   },
   { KOIOS_SEKOH  ,  3,  "SKIP"      ,   0, LEN_TITLE , YSTR_UPPER YSTR_LOWER YSTR_NUMBER "_"    , KOIOS_FFUNC , "·", "·"   },
   { KOIOS_SEKOH  ,  4,  "args"      ,   1, LEN_FULL  , YSTR_SEVEN " "                           , KOIOS_FARGS , "·", ""    },
   { KOIOS_SEKOH  ,  5,  "test"      ,   5, LEN_LABEL , YSTR_LOWER "_"                           , KOIOS_FTEST , "·", ""    },
   { KOIOS_SEKOH  ,  6,  "expect"    ,   1, LEN_RECD  , YSTR_SEVEN " "                           , KOIOS_FEXPE , "·", "·"   },
   { KOIOS_SEKOH  ,  7,  "return"    ,   0, LEN_LABEL , YSTR_UPPER YSTR_LOWER YSTR_NUMBER "_"    , KOIOS_FRETN , "·", "·"   },

   { KOIOS_SCODE  ,  2,  "desc"      ,   0, LEN_LONG  , YSTR_SEVEN " "                           , KOIOS_FDESC , "·", "---(empty)-------------------------"   },
   { KOIOS_SCODE  ,  3,  "SKIP"      ,   0, LEN_TITLE , YSTR_SEVEN " "                           , KOIOS_FFUNC , "·", "·"   },
   { KOIOS_SCODE  ,  4,  "content"   ,   1, LEN_RECD  , YSTR_SEVEN " "                           , KOIOS_FEXPE , "·", ""    },

   { KOIOS_SLOAD  ,  2,  "desc"      ,   0, LEN_LONG  , YSTR_SEVEN " "                           , KOIOS_FDESC , "·", "---(empty)-------------------------"   },
   { KOIOS_SLOAD  ,  3,  "config"    ,   1, LEN_TITLE , YSTR_SEVEN " "                           , KOIOS_FFUNC , "·", "·"   },
   { KOIOS_SLOAD  ,  4,  "content"   ,   0, LEN_RECD  , YSTR_SEVEN " "                           , KOIOS_FEXPE , "·", ""    },

   { 0            ,  0,  "end-list"  ,   0, 0         , ""                                       , '-'         , "" , ""    },
};

char
PARSE__select           (char a_nscrp [LEN_TITLE], int a_line, char a_verb [LEN_LABEL], char a_field [LEN_RECD], char r_field [LEN_LABEL])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        x_work      [LEN_LABEL] = "";
   char        x_final     [LEN_LABEL] = "å············æ";
   int         l            =   0;
   int         i            =   0;
   int         c            =   0;
   /*---(header)-------------------------*/
   UDEBUG_KOIOS   ylog_uenter  (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_field != NULL)  strcpy (r_field, "");
   /*---(null/empty)---------------------*/
   UDEBUG_KOIOS   ylog_upoint  ("a_field"   , a_field);
   --rce;  if (a_field == NULL || a_field [0] == '\0') {
      if (r_field != NULL)  strlcpy (r_field, x_final, LEN_RECD);
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(placeholder)--------------------*/
   UDEBUG_KOIOS   ylog_uinfo   ("a_field"   , a_field);
   if (strcmp (a_field, "·") == 0) {
      if (r_field != NULL)  strlcpy (r_field, x_final, LEN_RECD);
      UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
      return 0;
   }
   /*---(collect)------------------------*/
   l = strlen (a_field);
   --rce;  for (i = 0; i < l; ++i) {
      if (a_field [i] == 'å')   continue;
      if (a_field [i] == '·')   continue;
      if (a_field [i] == 'æ')   continue;
      if (strchr (x_work, a_field [i]) != NULL) {
         yerr_uerror ("%s:%d:0: error: å%sæ select (%c) already exists in %då%sæ duplicate", a_nscrp, a_line, a_verb, a_field [i], strlen (x_work), x_work);
         UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
         return rce;
      }
      x_work [c]   = a_field [i];
      x_work [++c] = '\0';
   }
   /*---(check length)-------------------*/
   l = strlen (x_work);
   --rce;  if (l > 12) {
      yerr_uerror ("%s:%d:0: error: å%sæ select contents %då%sæ longer than 12 chars", a_nscrp, a_line, a_verb, l, x_work);
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(fill out)-----------------------*/
   snprintf (x_final, 14, "å%s···················", x_work);
   strlcat (x_final, "æ", LEN_LABEL);
   /*---(save-back)----------------------*/
   if (r_field != NULL)  strlcpy (r_field, x_final, 15);
   /*---(complete)-----------------------*/
   UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
   return 1;
}

char
PARSE__subtitles        (char a_nscrp [LEN_TITLE], int a_line, char a_verb [LEN_LABEL], char a_select [LEN_LABEL], char a_field [LEN_RECD], char r_field [LEN_RECD])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char       *p           = NULL;
   char       *q           =  " ";
   char       *r           = NULL;
   int         l           =    0;
   int         c           =   -1;
   int         n           =    0;
   int         i           =    0;
   char        x_work      [LEN_LABEL] = "";
   char        x_field     [LEN_RECD]  = "";
   char        x_single    [LEN_LABEL] = "";
   char        x_final     [LEN_RECD]  = "Ï=·············, Ï=·············, Ï=·············, Ï=·············, Ï=·············, Ï=·············, Ï=·············, Ï=·············, Ï=·············, Ï=·············, Ï=·············, Ï=·············";
   /*---(header)-------------------------*/
   UDEBUG_KOIOS   ylog_uenter  (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_field != NULL)  strcpy (r_field, "");
   /*---(null/empty)---------------------*/
   UDEBUG_KOIOS   ylog_upoint  ("a_field"   , a_field);
   --rce;  if (a_field == NULL || a_field [0] == '\0') {
      if (r_field != NULL)  strlcpy (r_field, x_final, LEN_RECD);
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(placeholder)--------------------*/
   UDEBUG_KOIOS   ylog_uinfo   ("a_field"   , a_field);
   if (strcmp (a_field, "·") == 0) {
      if (r_field != NULL)  strlcpy (r_field, x_final, LEN_RECD);
      UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
      return 0;
   }
   /*---(collect)------------------------*/
   strcpy  (x_final, "");
   strlcpy (x_field, a_field, LEN_RECD);
   p = strtok_r (x_field, q, &r);
   --rce;  while (p != NULL) {
      ++c;
      /*---(empty)-----------------------*/
      l = strlen (p);
      if ((p [l - 1] == ',' && l <  4) ||
            (p [l - 1] != ',' && l <  3)) {
         yerr_uerror ("%s:%d:0: error: å%sæ subtitle (%d) %då%sæ less than minimum of 3 chars", a_nscrp, a_line, a_verb, c, l, p);
         UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
         return rce;
      }
      /*---(skip placeholders)-----------*/
      if (strchr ("Ï´·", p [0]) != NULL) {
         p = strtok_r (NULL, q, &r);
         continue;
      }
      /*---(check select)----------------*/
      if (strchr (YSTR_ALLCHAR "Ï´·", p [0]) == NULL) {
         yerr_uerror ("%s:%d:0: error: å%sæ subtitle (%d) %då%sæ starts with illegal select char åa-zA-Z0-9è-ÿÏ´·æ", a_nscrp, a_line, a_verb, c, l, p);
         UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
         return rce;
      }
      /*---(check exists)----------------*/
      if (strchr (a_select, p [0]) == NULL) {
         yerr_uerror ("%s:%d:0: error: å%sæ subtitle (%d) %då%sæ does not exist in select %s", a_nscrp, a_line, a_verb, c, l, p, a_select);
         UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
         return rce;
      }
      /*---(check equal)-----------------*/
      if (p [1] != '=') {
         yerr_uerror ("%s:%d:0: error: å%sæ subtitle (%d) %då%sæ does not have equal (=) in pos 2", a_nscrp, a_line, a_verb, c, l, p);
         UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
         return rce;
      }
      /*---(check duplicate)-------------*/
      if (strchr (x_work, p [0]) != NULL) {
         yerr_uerror ("%s:%d:0: error: å%sæ subtitle (%d) (%c) already exists in %då%sæ duplicate", a_nscrp, a_line, a_verb, c, p [0], strlen (x_work), x_work);
         UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
         return rce;
      }
      /*---(add to work)-----------------*/
      x_work [n]   = p [0];
      x_work [++n] = '\0';
      /*---(handle)----------------------*/
      for (i = l - 1; i >= 2; --i)   if (p [i] == '·' || p [i] == ',')  p [i] = '\0';
      snprintf (x_single, 16, "%s··················", p);
      strlcat (x_final, x_single, LEN_RECD);
      strlcat (x_final, ", "    , LEN_RECD);
      /*---(next)------------------------*/
      p = strtok_r (NULL, q, &r);
      /*---(done)------------------------*/
   }
   /*---(fill in)------------------------*/
   for (i = n; i < 12; ++i) strlcat (x_final, "Ï=·············, ", LEN_RECD);
   l = strlen (x_final);
   x_final [l - 2] = '\0';
   /*---(save-back)----------------------*/
   if (r_field != NULL)  strlcpy (r_field, x_final, LEN_RECD);
   /*---(complete)-----------------------*/
   UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
   return 1;
}

char
PARSE__field            (char a_nscrp [LEN_TITLE], int a_line, char a_verb [LEN_LABEL], char a_spec, char a_col, char a_field [LEN_RECD], char r_desc [LEN_LONG], char r_meth [LEN_HUND], char r_args [LEN_FULL], char r_test [LEN_LABEL], char r_expe [LEN_RECD], char r_retn [LEN_FULL], char r_which [LEN_TITLE])
{
   /*---(locals)-----------+-----------+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        x_nscrp     [LEN_TITLE] = "(n/a)";
   char        x_verb      [LEN_LABEL] = "(n/a)";
   int         i           =    0;
   char        n           =   -1;
   int         l           =    0;
   char        x_work      [LEN_RECD]  = "";
   char        x_field     [LEN_RECD]  = "";
   char        x_display   [LEN_RECD]  = "";
   int         c           =    0;
   /*---(header)-------------------------*/
   UDEBUG_KOIOS   ylog_uenter  (__FUNCTION__);
   /*---(defense)------------------------*/
   --rce;  if (a_nscrp != NULL)    strlcpy (x_nscrp, a_nscrp, LEN_TITLE);
   --rce;  if (a_verb  != NULL)    strlcpy (x_verb , a_verb , LEN_LABEL);
   /*---(search)-------------------------*/
   UDEBUG_KOIOS   ylog_uchar   ("a_spec"    , a_spec);
   UDEBUG_KOIOS   ylog_uvalue  ("a_col"     , a_col);
   for (i = 0; i < LEN_DESC; ++i) {
      if (s_parse [i].p_spec == 0)   break;
      if (s_parse [i].p_spec != a_spec)   continue;
      if (s_parse [i].p_col  != a_col)    continue;
      n = i;
      break;
   }
   UDEBUG_KOIOS   ylog_uvalue  ("n"         , n);
   /*---(handle miss)--------------------*/
   --rce;  if (n < 0) {
      yerr_uerror ("%s:%d:0: error: å%sæ spec (%c) col (%d) not legal/defined", x_nscrp, a_line, x_verb, a_spec, a_col);
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(skips)--------------------------*/
   UDEBUG_KOIOS   ylog_uinfo   ("p_field"   , s_parse [n].p_field);
   if (strcmp (s_parse [n].p_field, "SKIP") == 0) {
      UDEBUG_KOIOS   ylog_unote   ("field marked as skip");
      UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
      return 0;
   }
   /*---(prepare)------------------------*/
   --rce;  if (a_field == NULL) {
      yerr_uerror ("%s:%d:0: error: å%sæ spec (%c) field å%sæ is null", x_nscrp, a_line, x_verb, a_spec, s_parse [n].p_field);
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   strlcpy (x_field, a_field, LEN_RECD);
   UDEBUG_KOIOS   ylog_uinfo   ("x_field"   , x_field);
   l = strlen (x_field);
   UDEBUG_KOIOS   ylog_uvalue  ("l"         , l);
   /*---(length)-------------------------*/
   --rce;  if (l < s_parse [n].p_min) {
      yerr_uerror ("%s:%d:0: error: å%sæ spec (%c) field å%sæ contents %då%sæ < (%d)", x_nscrp, a_line, x_verb, a_spec, s_parse [n].p_field, l, x_field, s_parse [n].p_min);
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   --rce;  if (l >= s_parse [n].p_max) {
      yerr_uerror ("%s:%d:0: error: å%sæ spec (%c) field å%sæ contents %då%sæ >= (%d)", x_nscrp, a_line, x_verb, a_spec, s_parse [n].p_field, l, x_field, s_parse [n].p_min);
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(check valid)--------------------*/
   strlcpy (x_display, x_field, LEN_RECD);
   --rce;  for (i = 0; i < l; ++i) {
      if (strchr (s_parse [n].p_allowed, x_display [i]) != NULL)  continue;
      x_display [i] = '°';
      ++c;
   }
   /*---(warning)------------------------*/
   --rce;  if (c > 0) {
      yerr_uerror ("%s:%d:0: error: å%sæ spec (%c) field å%sæ contains (%d) illegal chars å%sæ", x_nscrp, a_line, x_verb, a_spec, s_parse [n].p_field, c, x_display);
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(default)------------------------*/
   if (x_field [0] == '\0' || strcmp (x_field, s_parse [n].p_place) == 0) {
      strlcpy (x_field, s_parse [n].p_def, LEN_RECD);
      UDEBUG_KOIOS   ylog_uinfo   ("x_field"   , x_field);
   }
   /*---(specialty select)---------------*/
   UDEBUG_KOIOS   ylog_uchar   ("a_spec"    , a_spec);
   --rce;  if (a_spec == KOIOS_SSHAR) {
      UDEBUG_KOIOS   ylog_unote   ("handling shared details");
      strlcpy (x_work, x_field, LEN_RECD);
      UDEBUG_KOIOS   ylog_uvalue  ("a_col"     , a_col);
      if (a_col == 4)  rc = PARSE__select     (a_nscrp, a_line, a_verb, x_work, x_field);
      if (a_col == 5)  rc = PARSE__subtitles  (a_nscrp, a_line, a_verb, r_meth, x_work, x_field);
      UDEBUG_KOIOS   ylog_uvalue  ("result"    , rc);
      if (rc < 0) {
         UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
         return rce;
      }
   }
   /*---(placement)----------------------*/
   --rce;  switch (s_parse [n].p_dest) {
   case KOIOS_FDESC : strlcpy (r_desc, x_field, s_parse [n].p_max);   break;
   case KOIOS_FFUNC : strlcpy (r_meth, x_field, s_parse [n].p_max);   break;
   case KOIOS_FARGS : strlcpy (r_args, x_field, s_parse [n].p_max);   break;
   case KOIOS_FTEST : strlcpy (r_test, x_field, s_parse [n].p_max);   break;
   case KOIOS_FEXPE : strlcpy (r_expe, x_field, s_parse [n].p_max);   break;
   case KOIOS_FRETN : strlcpy (r_retn, x_field, s_parse [n].p_max);   break;
   default   :
                      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
                      return rce;
   }
   /*---(which)--------------------------*/
   --rce;  if (s_parse [n].p_dest == KOIOS_FDESC) {
      rc = PARSE__which  (x_nscrp, a_line, x_verb, x_field, r_which);
      UDEBUG_KOIOS   ylog_uchar   ("which"     , rc);
      --rce; if (rc < 0) {
         UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
         return rce;
      }
   }
   /*---(complete)-----------------------*/
   UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
   return 1;
}

char
PARSE_default           (char r_verb [LEN_LABEL], char *r_spec, char **r_conv, char **r_code, char r_stage [LEN_SHORT], char *r_vers, char r_desc [LEN_LONG], char r_meth [LEN_HUND], char r_args [LEN_FULL], char r_test [LEN_LABEL], char r_expe [LEN_RECD], char r_retn [LEN_FULL], char *r_ditto, char *r_major, char *r_minor, char r_which [LEN_TITLE])
{
   if (r_verb   != NULL)  strcpy (r_verb  , "");
   if (r_spec   != NULL)  *r_spec   =  '-';
   if (r_conv   != NULL)  *r_conv   = NULL;
   if (r_code   != NULL)  *r_code   = NULL;
   if (r_stage  != NULL)  strcpy (r_stage , "");
   if (r_vers   != NULL)  *r_vers   =   -1;
   if (r_desc   != NULL)  strcpy (r_desc  , "");
   if (r_meth   != NULL)  strcpy (r_meth  , "");
   if (r_args   != NULL)  strcpy (r_args  , "");
   if (r_test   != NULL)  strcpy (r_test  , "");
   if (r_expe   != NULL)  strcpy (r_expe  , "");
   if (r_retn   != NULL)  strcpy (r_retn  , "");
   if (r_ditto  != NULL)  *r_ditto  =  '-';
   if (r_major  != NULL)  *r_major  =  '-';
   if (r_minor  != NULL)  *r_minor  =  '-';
   if (r_which  != NULL)  strcpy (r_which , "");
   return 0;
}

char
PARSE__defense          (char a_nscrp [LEN_TITLE], int a_line, char a_recd [LEN_RECD], char r_verb [LEN_LABEL], char *r_spec, char **r_conv, char **r_code, char r_stage [LEN_SHORT], char *r_vers)
{
   /*---(locals)-----------+-----------+-*/
   char        rce         = -10;           /* return code for errors         */
   int         l           =   0;
   /*---(header)-------------------------*/
   UDEBUG_KOIOS   ylog_uenter  (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_verb   != NULL)  strcpy (r_verb  , "");
   if (r_spec   != NULL)  *r_spec =  '-';
   if (r_conv   != NULL)  *r_conv = NULL;
   if (r_code   != NULL)  *r_code = NULL;
   if (r_stage  != NULL)  strcpy (r_stage , "");
   if (r_vers   != NULL)  *r_vers =   -1;
   /*---(feeder fields)------------------*/
   UDEBUG_KOIOS   ylog_upoint  ("a_ncrp"    , a_nscrp);
   --rce;  if (a_nscrp == NULL) {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   UDEBUG_KOIOS   ylog_uvalue  ("a_line"    , a_line);
   /*---(record)-------------------------*/
   UDEBUG_KOIOS   ylog_upoint  ("a_recd"    , a_recd);
   --rce;  if (a_recd == NULL) {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   UDEBUG_KOIOS   ylog_uchar   ("a_recd [0]", a_recd [0]);
   --rce;  if (a_recd [0] == '\0') {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   l = strlen (a_recd);
   UDEBUG_KOIOS   ylog_uvalue  ("l"         , l);
   --rce;  if (l <  5 && a_recd [0] != '#') {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(return fields)------------------*/
   UDEBUG_KOIOS   ylog_upoint  ("r_verb"    , r_verb);
   --rce;  if (r_verb == NULL) {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   UDEBUG_KOIOS   ylog_upoint  ("r_spec"    , r_spec);
   --rce;  if (r_spec == NULL) {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   UDEBUG_KOIOS   ylog_upoint  ("r_conv"    , r_conv);
   --rce;  if (r_conv == NULL) {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   UDEBUG_KOIOS   ylog_upoint  ("r_code"    , r_code);
   --rce;  if (r_code == NULL) {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   UDEBUG_KOIOS   ylog_upoint  ("r_stage"   , r_stage);
   --rce;  if (r_stage == NULL) {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   UDEBUG_KOIOS   ylog_upoint  ("r_vers"    , r_vers);
   --rce;  if (r_vers == NULL) {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(complete)-----------------------*/
   UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
   return 0;
}

char
PARSE__comment          (char a_nscrp [LEN_TITLE], int a_line, char a_recd [LEN_RECD], char r_verb [LEN_LABEL], char *r_under, char *r_spec, char **r_conv, char **r_code, char r_expe [LEN_RECD])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   int         i           =    0;
   char        x_recd      [LEN_RECD]  = "";
   int         x_len       =    0;
   char        x_verb      [LEN_LABEL] = "";
   char        x_indx      =   -1;
   char        x_spec      =  '-';
   char      (*x_conv) (void)  = NULL;
   char      (*x_code) (void)  = NULL;
   /*---(header)-------------------------*/
   UDEBUG_KOIOS   ylog_uenter  (__FUNCTION__);
   /*---(defense)------------------------*/
   UDEBUG_KOIOS   ylog_upoint  ("a_nscrp"   , a_nscrp);
   --rce;  if (a_nscrp == NULL) {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   UDEBUG_KOIOS   ylog_upoint  ("a_recd"    , a_recd);
   --rce;  if (a_recd == NULL) {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   x_len = strlen (a_recd);
   /*---(ward-off)-----------------------*/
   UDEBUG_KOIOS   ylog_uvalue  ("x_len"     , x_len);
   if (x_len < 2) {
      UDEBUG_KOIOS   ylog_unote   ("too short");
      UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
      return 0;
   }
   if      (strncmp (a_recd, "#>"     , 2) == 0) ;
   else if (strncmp (a_recd, "   #>"  , 5) == 0) ;
   else if (strncmp (a_recd, "     #>", 7) == 0) ;
   else {
      UDEBUG_KOIOS   ylog_unote   ("not prefixed with #>");
      UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
      return 0;
   }
   /*---(check for marker)---------------*/
   UDEBUG_KOIOS   ylog_unote   ("saved record/comment");
   rc = VERB_parse (a_nscrp, a_line, "#>", r_under, x_verb, &x_indx, &x_spec, NULL, &x_conv, &x_code);
   UDEBUG_KOIOS   ylog_uvalue  ("verb"      , rc);
   --rce;  if (rc < 0) {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(save-back)----------------------*/
   if (r_verb  != NULL)  strlcpy (r_verb, x_verb, LEN_LABEL);
   if (r_spec  != NULL)  *r_spec = x_spec;
   if (r_conv  != NULL)  *r_conv = x_conv;
   if (r_code  != NULL)  *r_code = x_code;
   if (r_expe  != NULL)  strlcpy (r_expe, a_recd, LEN_RECD);
   /*---(complete)-----------------------*/
   UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
   return 1;
}

char
PARSE__version          (char *a_field, char *r_vers)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        x_field     [LEN_TERSE] = "";
   int         l           =    0;
   char        x_vers      =   -1;
   /*---(default)------------------------*/
   if (r_vers != NULL)  *r_vers = -1;
   /*---(defense)------------------------*/
   --rce;  if (a_field == NULL)  return rce;
   --rce;  if (r_vers  == NULL)  return rce;
   /*---(prepare)------------------------*/
   strlcpy  (x_field, a_field, LEN_TERSE);
   ystrutrim (x_field, LEN_TERSE);
   l = strlen (x_field);
   /*---(assign version)-----------------*/
   if      (l != 3)                            *r_vers =  0;   /* current */
   else if (x_field [0] != 'v')                *r_vers =  0;   /* current */
   else if (strcmp (x_field, "v21") == 0)      *r_vers = 21;
   else if (strcmp (x_field, "v20") == 0)      *r_vers = 20;
   else if (strcmp (x_field, "v19") == 0)      *r_vers = 19;
   /*---(handle trouble)-----------------*/
   --rce;  if (*r_vers < 0)  return rce;
   /*---(complete)-----------------------*/
   return 0;
}

char
PARSE_prep              (FILE **b_scrp, char a_nscrp [LEN_TITLE], int a_line, char a_runtype, char a_recd [LEN_RECD], char r_verb [LEN_LABEL], char *r_under, char *r_spec, char **r_conv, char **r_code, char r_stage [LEN_SHORT], char *r_vers, char r_desc [LEN_LONG], char r_expe [LEN_RECD], char *r_ditto, char *r_dittoing, char *r_dtarget, int *r_dstart, int *r_dline, char *r_major, char *r_minor, char *r_share, char *r_select)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   int         rc          = 0;             /* generic return code            */
   char        x_recd      [LEN_RECD]  = "";
   int         x_len       = 0;             /* input record length            */
   char       *p           = NULL;
   char       *q           = "";
   char       *r           = NULL;
   char       *v           = NULL;
   char        x_prefix    [LEN_LABEL] = "";
   /*---(header)-------------------------*/
   UDEBUG_KOIOS   ylog_uenter  (__FUNCTION__);
   /*---(saved comments)-----------------*/
   rc = PARSE__comment (a_nscrp, a_line, a_recd, r_verb, r_under, r_spec, r_conv, r_code, r_expe);
   UDEBUG_KOIOS   ylog_uvalue  ("comment"   , rc);
   --rce;  if (rc <  0) {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   if (rc == 1) {
      UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
      return 1;
   }
   /*---(create a copy of recd)----------*/
   UDEBUG_KOIOS   ylog_upoint  ("a_recd"    , a_recd);
   --rce;  if (a_recd == NULL) {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   UDEBUG_KOIOS   ylog_uinfo   ("a_recd"    , a_recd);
   strlcpy (x_recd, a_recd, LEN_RECD);
   UDEBUG_KOIOS   ylog_uinfo   ("x_recd"    , x_recd);
   p  = strtok_r (x_recd, q, &r);
   UDEBUG_KOIOS   ylog_upoint  ("p"         , p);
   if (p == NULL) {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(save prefix)--------------------*/
   strlcpy (x_prefix, p, LEN_LABEL);
   UDEBUG_KOIOS   ylog_upoint  ("x_prefix"  , x_prefix);
   /*---(get verb)-----------------------*/
   rc = VERB_parse     (a_nscrp, a_line, x_prefix, r_under, r_verb, NULL, r_spec, NULL, r_conv, r_code);
   UDEBUG_KOIOS   ylog_uvalue  ("verb"      , rc);
   --rce;  if (rc < 0) {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   UDEBUG_KOIOS   ylog_uinfo   ("r_verb"    , r_verb);
   /*---(read version)-------------------*/
   v = strtok_r (NULL  , q, &r);
   --rce;  if (v == NULL && *r_spec != 'c') {
      yerr_uerror ("%s:%d:1: error: verb only, %s requires more fields", a_nscrp, a_line, r_verb);
      UDEBUG_KOIOS   ylog_unote   ("strtok came up empty");
      UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
      return rce;
   }
   rc = PARSE__version (v, r_vers);
   /*---(check for shares)---------------*/
   rc = REUSE_parse    (a_nscrp, a_line, r_verb, x_prefix, *r_share, r_major, r_minor);
   UDEBUG_KOIOS   ylog_uvalue  ("reuses"    , rc);
   --rce;  if (rc < 0) {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rc);
      return rce;
   }
   /*---(check for totals)---------------*/
   rc = REUSE_totals  (r_verb, a_recd);
   UDEBUG_KOIOS   ylog_uvalue  ("totals"    , rc);
   if (rc == 1) {
      UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
      return 1;
   }
   /*---(check for ditto)----------------*/
   rc = DITTO_parse_handler (b_scrp, a_nscrp, a_line, a_runtype, r_verb, *r_vers, a_recd, p, r_desc, r_ditto, r_dittoing, r_dtarget, r_dstart, r_dline);
   UDEBUG_KOIOS   ylog_uvalue  ("ditto"     , rc);
   --rce;  if (rc < 0) {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rc);
      return rce;
   }
   if (rc == 1) {
      UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
      return 1;
   }
   /*---(check for stage marker)---------*/
   rc = WAVE_parse (a_nscrp, a_line, r_verb, p, r_stage) ;
   UDEBUG_KOIOS   ylog_uvalue  ("stage"     , rc);
   --rce;  if (rc < 0) {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rc);
      return rce;
   }
   /*---(complete)-----------------------*/
   UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
   return 0;
}

char
PARSE__default          (char r_desc [LEN_LONG], char r_meth [LEN_HUND], char r_args [LEN_FULL], char r_test [LEN_LABEL], char r_expe [LEN_RECD], char r_retn [LEN_FULL])
{
   if (r_desc   != NULL)  strcpy (r_desc  , "");
   if (r_meth   != NULL)  strcpy (r_meth  , "");
   if (r_args   != NULL)  strcpy (r_args  , "");
   if (r_test   != NULL)  strcpy (r_test  , "");
   if (r_expe   != NULL)  strcpy (r_expe  , "");
   if (r_retn   != NULL)  strcpy (r_retn  , "");
   return 0;
}

/*> char                                                                              <* 
 *> PARSE__limits           (char a_spec, char *r_min, char *r_max)                   <* 
 *> {                                                                                 <* 
 *>    /+---(locals)-----------+-----+-----+-+/                                       <* 
 *>    char        rce         =  -10;                                                <* 
 *>    /+---(defaults)-----------------------+/                                       <* 
 *>    if (r_min != NULL)  *r_min = 0;                                                <* 
 *>    if (r_max != NULL)  *r_max = 0;                                                <* 
 *>    /+---(defense)------------------------+/                                       <* 
 *>    --rce;  if (r_min == NULL)  return rce;                                        <* 
 *>    --rce;  if (r_max == NULL)  return rce;                                        <* 
 *>    /+---(process)------------------------+/                                       <* 
 *>    --rce;  switch (a_spec) {                                                      <* 
 *>    case '1' :  *r_min = 1;  *r_max = 1;    break;                                 <* 
 *>    case 'c' :  *r_min = 1;  *r_max = 1;    break;                                 <* 
 *>    case 'r' :  *r_min = 1;  *r_max = 2;    break;                                 <* 
 *>    case '2' :  *r_min = 2;  *r_max = 2;    break;                                 <* 
 *>    case '3' :  *r_min = 3;  *r_max = 3;    break;                                 <* 
 *>    case 'F' :  *r_min = 3;  *r_max = 3;    break;                                 <* 
 *>    case KOIOS_SSCRP   :  *r_min = 3;  *r_max = 5;    break;                       <* 
 *>    case 'P' :  *r_min = 4;  *r_max = 4;    break;                                 <* 
 *>    case 'p' :  *r_min = 4;  *r_max = 4;    break;                                 <* 
 *>    case 'f' :  *r_min = 6;  *r_max = 8;    break;                                 <* 
 *>    default  :  return rce;                 break;                                 <* 
 *>    }                                                                              <* 
 *>    /+---(complete)-----------------------+/                                       <* 
 *>    return 0;                                                                      <* 
 *> }                                                                                 <*/

char
PARSE__allowed_chars    (char a_nscrp [LEN_TITLE], int a_line, char a_verb [LEN_LABEL], char a_label [LEN_TERSE], char a_allowed [LEN_FULL], char a_field [LEN_RECD])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        x_field     [LEN_RECD]  = "";
   int         l           =    0;
   int         i           =    0;
   int         c           =    0;
   /*---(header)-------------------------*/
   UDEBUG_KOIOS   ylog_uenter  (__FUNCTION__);
   /*---(prepare)------------------------*/
   strlcpy (x_field, a_field, LEN_RECD);
   UDEBUG_KOIOS   ylog_uinfo   ("x_field"   , x_field);
   l = strlen (x_field);
   UDEBUG_KOIOS   ylog_uvalue  ("l"         , l);
   /*---(check valid)--------------------*/
   --rce;  for (i = 0; i < l; ++i) {
      if (strchr (a_allowed, x_field [i]) != NULL)  continue;
      x_field [i] = '°';
      ++c;
   }
   /*---(warning)------------------------*/
   --rce;  if (c > 0) {
      yerr_uerror ("%s:%d:0: error: å%sæ field å%sæ contains (%d) illegal chars å%sæ", a_nscrp, a_line, a_verb, a_label, c, x_field);
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(complete)-----------------------*/
   UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
   return 1;
}

char
PARSE__which            (char a_nscrp [LEN_TITLE], int a_line, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char r_which [LEN_TITLE])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        x_select    =    0;
   char       *p           = NULL;
   char        t           [LEN_LONG]  = "";
   char        x_which     [LEN_TITLE] = "";
   int         l           =    0;
   int         i           =    0;
   /*---(header)-------------------------*/
   UDEBUG_KOIOS   ylog_uenter  (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_which != NULL)  strcpy (r_which, "");
   /*---(quick-out)----------------------*/
   UDEBUG_KOIOS   ylog_upoint  ("a_verb"    , a_verb);
   --rce;  if (a_verb == NULL) {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   UDEBUG_KOIOS   ylog_uinfo   ("a_verb"    , a_verb);
   x_select = VERB_selectable (a_verb);
   UDEBUG_KOIOS   ylog_uvalue  ("x_select"  , x_select);
   if (x_select != 1) {
      UDEBUG_KOIOS   ylog_unote   ("not a selectable verb");
      UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
      return 0;
   }
   /*---(defense)------------------------*/
   UDEBUG_KOIOS   ylog_upoint  ("a_desc"    , a_desc);
   --rce;  if (a_desc == NULL) {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   UDEBUG_KOIOS   ylog_uinfo   ("a_desc"    , a_desc);
   /*---(find start)---------------------*/
   p = strchr (a_desc, 'å');
   UDEBUG_KOIOS   ylog_upoint  ("p"         , p);
   if (p == NULL) {
      UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
      return 0;
   }
   strlcpy (t, p + 1, LEN_LONG);
   UDEBUG_KOIOS   ylog_uinfo   ("t"         , t);
   /*---(find end)-----------------------*/
   p = strchr (t, 'æ');
   UDEBUG_KOIOS   ylog_upoint  ("p"         , p);
   --rce;  if (p == NULL) {
      yerr_uerror ("%s:%d:0: error: å%sæ description \"%s\" starts selectable, but does not close, i.e., åabc··d··æ", a_nscrp, a_line, a_verb, a_desc);
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   p [0] = '\0';
   UDEBUG_KOIOS   ylog_uinfo   ("t"         , t);
   l = strlen (t);
   UDEBUG_KOIOS   ylog_uvalue  ("l"         , l);
   /*---(check valid)--------------------*/
   --rce;  for (i = 0; i < l; ++i) {
      if (strchr (YSTR_ALLCHAR "-·", t [i]) != NULL)  continue;
      yerr_uerror ("%s:%d:0: error: å%sæ select string å%sæ contains illegal char (%c) at pos (%d), only allow [A-Za-z0-9è-ÿ·-]", a_nscrp, a_line, a_verb, t, t [i], i);
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(save-back)----------------------*/
   if (r_which != NULL)  strlcpy (r_which, t, LEN_TITLE);
   /*---(complete)-----------------------*/
   UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
   return 1;
}

char
PARSE__desc             (char a_nscrp [LEN_TITLE], int a_line, char a_verb [LEN_LABEL], char a_spec, char a_max, char a_field [LEN_RECD], char r_desc [LEN_LONG], char r_which [LEN_TITLE])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   int         l           =    0;
   /*---(header)-------------------------*/
   UDEBUG_KOIOS   ylog_uenter  (__FUNCTION__);
   /*---(quick-out)----------------------*/
   UDEBUG_KOIOS   ylog_uvalue  ("a_max"     , a_max);
   --rce; if (a_max < 2) {
      UDEBUG_KOIOS   ylog_unote   ("verb does not require 2nd/desc field");
      UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
      return 0;
   }
   /*---(defense)------------------------*/
   UDEBUG_KOIOS   ylog_uchar   ("a_spec"    , a_spec);
   --rce; if (a_spec == 0) {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(null)---------------------------*/
   --rce;  if (a_field == NULL)  {
      if (r_desc  != NULL)  strlcpy (r_desc , "[ - - - - - - (null)- - - - - - - ]", LEN_LONG);
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   UDEBUG_KOIOS   ylog_uinfo   ("a_field"   , a_field);
   l = strlen (a_field);
   UDEBUG_KOIOS   ylog_uvalue  ("l"         , l);
   /*---(placeholder)--------------------*/
   if (l <= 1) {
      switch (a_field [0]) {
      case '\0' : case '·' : case  '-' : case '´' :
         if (r_desc  != NULL)  strlcpy (r_desc, "·", LEN_LONG);
         UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
         return 0;
      }
   }
   /*---(save-back)----------------------*/
   if (r_desc  != NULL)  strlcpy (r_desc , a_field, LEN_LONG);
   /*---(check on the which)-------------*/
   rc = PARSE__which  (a_nscrp, a_line, a_spec, a_field, r_which);
   UDEBUG_KOIOS   ylog_uchar   ("which"     , rc);
   --rce; if (rc < 0) {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(complete)-----------------------*/
   UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
   return 1;
}

/*     a_spec    field    id    min   max   allowed */

char
PARSE__function         (char a_nscrp [LEN_TITLE], int a_line, char a_verb [LEN_LABEL], char a_spec, char a_max, char a_field [LEN_RECD], char r_meth [LEN_HUND], char r_test [LEN_LABEL], char r_retn [LEN_FULL])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   /*---(header)-------------------------*/
   UDEBUG_KOIOS   ylog_uenter  (__FUNCTION__);
   /*---(defense)------------------------*/
   UDEBUG_KOIOS   ylog_uchar   ("a_spec"    , a_spec);
   --rce; if (a_spec == 0) {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(quick-out)----------------------*/
   UDEBUG_KOIOS   ylog_uvalue  ("a_max"     , a_max);
   --rce; if (a_max < 3) {
      UDEBUG_KOIOS   ylog_unote   ("verb does not require 3rd/function field");
      UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
      return 0;
   }
   /*---(script = duration)--------------*/
   if (a_spec == KOIOS_SSCRP) {
      UDEBUG_KOIOS   ylog_unote   ("handle script");
      if (r_test != NULL) {
         strlcpy (r_test, a_field, LEN_LABEL);
         UDEBUG_KOIOS   ylog_uinfo   ("duration"  , r_test);
      }
   }
   /*---(shares = label)------------------*/
   else if    (a_spec == KOIOS_SSHAR) {
      UDEBUG_KOIOS   ylog_unote   ("handle global, config, shared");
      /*---(check valid)--------------------*/
      rc = PARSE__allowed_chars (a_nscrp, a_line, a_verb, "label", YSTR_UPPER YSTR_LOWER "·_", a_field);
      if (rc < 0) {
         UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
         return rce;
      }
      /*---(save-back)----------------------*/
      if (r_retn != NULL) {
         strlcpy (r_retn, a_field, LEN_FULL);
         UDEBUG_KOIOS   ylog_uinfo   ("terse tag" , r_retn);
      }
   }
   /*---(some = blank)----------------*/
   else if (strchr (KOIOS_SFUNCS, a_spec) == NULL) {
      UDEBUG_KOIOS   ylog_unote   ("this type skips this field");
      UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
      return 0;
   }
   /*---(function name)---------------*/
   else {
      UDEBUG_KOIOS   ylog_unote   ("handle function or mode");
      /*---(check valid)--------------------*/
      rc = PARSE__allowed_chars (a_nscrp, a_line, a_verb, "function", YSTR_UPPER YSTR_LOWER YSTR_NUMBER "_", a_field);
      if (rc < 0) {
         UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
         return rce;
      }
      /*---(save-back)----------------------*/
      if (r_meth != NULL) {
         strlcpy (r_meth, a_field, LEN_HUND );
         UDEBUG_KOIOS   ylog_uinfo   ("meth"      , r_meth);
      }
   }
   /*---(complete)-----------------------*/
   UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
   return 1;
}

/*> #23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-123456789-    <* 
 *> #==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  ========(var)=======    <*/

char
PARSE__current          (char n, char a_field [LEN_RECD], char a_spec, char *r_max, char r_desc [LEN_LONG], char r_meth [LEN_HUND], char r_args [LEN_FULL], char r_test [LEN_LABEL], char r_expe [LEN_RECD], char r_retn [LEN_FULL])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   int         l           =    0;
   char        x_field     [LEN_RECD]  = "";
   /*---(header)-------------------------*/
   UDEBUG_KOIOS   ylog_uenter  (__FUNCTION__);
   /*---(quick out)----------------------*/
   if (r_max != NULL) {
      UDEBUG_KOIOS   ylog_uvalue  ("r_max"     , *r_max);
      --rce;  if (n < 2 || n > *r_max) {
         UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
         return rce;
      }
   }
   /*---(defense)------------------------*/
   UDEBUG_KOIOS   ylog_upoint  ("a_field"   , a_field);
   --rce;  if (a_field == NULL) {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(clear spacer bars)--------------*/
   strlcpy (x_field, a_field, LEN_RECD);
   if (x_field [0] == '-' && n != 6) {
      if (strncmp (x_field, "- - -", 5) == 0)    x_field [0] = '\0';
      if (strncmp (x_field, "-----", 5) == 0)    x_field [0] = '\0';
      if (x_field [1] == '\0')                   x_field [0] = '\0';
   }
   ystrutrim (x_field, LEN_RECD);
   l = strlen (x_field);
   UDEBUG_KOIOS   ylog_uinfo   ("x_field"   , x_field);
   /*---(handle fields)------------------*/
   switch (n) {
   case  2 :  /*=== always desc ===============*/
      if (r_desc != NULL) {
         strlcpy  (r_desc, x_field        , LEN_LONG);
         ystrutrim (r_desc, LEN_LONG);
         if (r_desc [0] == '\0')  strlcpy (r_desc, "[ - - - - - - (empty) - - - - - - ]", LEN_LONG);
      }
      break;
   case  3 :  /*=== typically, method =========*/
      /*---(script types)----------------*/
      if (a_spec == KOIOS_SSCRP) {
         if (r_test != NULL) {
            strlcpy (r_test, x_field, LEN_LABEL);
            UDEBUG_KOIOS   ylog_uinfo   ("duration"  , r_test);
         }
      }
      /*---(others, except sepciality)---*/
      else if (a_spec != 'p') {
         if (r_meth != NULL) {
            strlcpy (r_meth, x_field, LEN_HUND );
            UDEBUG_KOIOS   ylog_uinfo   ("meth"      , r_meth);
         }
      }
      break;
   case  4 :  /*=== typically, argument =======*/
      /*---(script types)----------------*/
      if      (a_spec == KOIOS_SSCRP) {
         if (r_retn != NULL) {
            strlcpy (r_retn, x_field, LEN_FULL);
            UDEBUG_KOIOS   ylog_uinfo   ("terse tag" , r_retn);
         }
      }
      /*---(specialty types)-------------*/
      else if (a_spec == 'P' || a_spec == 'p') {
         if (r_expe != NULL) {
            strlcpy (r_expe, x_field, LEN_RECD);
            UDEBUG_KOIOS   ylog_uinfo   ("expe"      , r_expe);
         }
      }
      /*---(all others)------------------*/
      else {
         if (r_args != NULL) {
            strlcpy (r_args, x_field, LEN_FULL);
            UDEBUG_KOIOS   ylog_uinfo   ("args"      , r_args);
         }
      }
      break;
   case  5 :  /*=== typically, test ===========*/
      /*---(script types)----------------*/
      if (a_spec == KOIOS_SSCRP) {
         if (r_meth != NULL) {
            strlcpy (r_meth, x_field, LEN_HUND );
            UDEBUG_KOIOS   ylog_uinfo   ("focus"     , r_meth);
         }
      }
      /*---(all others)------------------*/
      else {
         if (r_test != NULL) {
            strlcpy (r_test, x_field, LEN_LABEL);
            UDEBUG_KOIOS   ylog_uinfo   ("test"      , r_test);
         }
      }
      break;
   case  6 :  /*=== expected result ===========*/
      if (r_expe != NULL) {
         strlcpy (r_expe, x_field, LEN_RECD);
         UDEBUG_KOIOS   ylog_uinfo   ("expe"      , r_expe);
      }
      break;
   case  7 :  /*=== return variable ===========*/
      if (r_retn != NULL) {
         strlcpy (r_retn, x_field, LEN_FULL);
         UDEBUG_KOIOS   ylog_uinfo   ("retn"      , r_retn);
      }
      break;
   }
   /*---(fill-in)---------------------*/
   if (a_spec == KOIOS_SSCRP) {
      if (strcmp (r_desc, "") == 0)  strlcpy (r_desc, "-"  , LEN_LONG);
      if (strcmp (r_test, "") == 0)  strlcpy (r_test, "0s" , LEN_LABEL);
      if (strcmp (r_retn, "") == 0)  strlcpy (r_retn, "tbd", LEN_FULL);
      if (strcmp (r_meth, "") == 0)  strlcpy (r_meth, "-"  , LEN_HUND);
   }
   /*---(complete)--------------------*/
   UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
   return 0;
}

char
PARSE_driver_OLD        (char a_nscrp [LEN_TITLE], int a_line, char a_vers, char a_verb [LEN_LABEL], char a_spec, char a_recd [LEN_RECD], char r_desc [LEN_LONG], char r_meth [LEN_HUND], char r_args [LEN_FULL], char r_test [LEN_LABEL], char r_expe [LEN_RECD], char r_retn [LEN_FULL], char r_which [LEN_TITLE])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   int         rc          =    0;
   char        x_recd      [LEN_RECD]  = "";     /* incomming record               */
   int         i           = 0;
   char       *p           = NULL;
   char       *q           = "";
   char       *r           = NULL;
   char        x_min       =    0;
   char        x_max       =    0;
   char        x_desc      [LEN_LONG]  = "";     /* descriptive text               */
   char        x_meth      [LEN_HUND]  = "";     /* function/method name           */
   char        x_args      [LEN_FULL]  = "";     /* function/method args           */
   char        x_test      [LEN_LABEL] = "";     /* test type for yVAR             */
   char        x_expe      [LEN_RECD]  = "";     /* expected results               */
   char        x_retn      [LEN_FULL]  = "";     /* return variable                */
   char        x_which     [LEN_TITLE] = "";     /* which/selective execution      */
   /*---(header)-------------------------*/
   UDEBUG_KOIOS   ylog_uenter  (__FUNCTION__);
   /*---(quick-out)----------------------*/
   if (strchr ("1cU", a_spec) != NULL) {
      UDEBUG_KOIOS   ylog_unote   ("one field required and already read as verb");
      UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
      return 0;  /* ditto type */
   }
   /*---(default)---------------------*/
   PARSE__default  (r_desc, r_meth, r_args, r_test, r_expe, r_retn);
   /*---(defense)------------------------*/
   UDEBUG_KOIOS   ylog_upoint  ("a_recd"    , a_recd);
   --rce;  if (a_recd == NULL) {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   strlcpy (x_recd, a_recd, LEN_RECD);
   /*---(read limits)--------------------*/
   UDEBUG_KOIOS   ylog_uchar   ("spec"      , a_spec);
   rc = VERB_limits (a_spec, &x_min, &x_max, NULL);
   UDEBUG_KOIOS   ylog_ucomplex("limits"    , "%4d rc, %d min, %d max", rc, x_min, x_max);
   --rce;  if (rc < 0) {
      yerr_uerror ("%s:%d:0: error: can not identify verb ¶%s¶ with '%c' spec limits", a_nscrp, a_line, a_verb, a_spec);
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(prepare)------------------------*/
   p = strtok_r (x_recd, q, &r);
   p = strtok_r (NULL  , q, &r);
   --rce;  if (p == NULL) {
      UDEBUG_KOIOS   ylog_unote   ("only one field provided");
      UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
      return rce;
   }
   --rce;  if (a_vers > 0) {
      p = strtok_r (NULL  , q, &r);
      if (p == NULL) {
         UDEBUG_KOIOS   ylog_unote   ("adjusted to having version number");
         UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
         return rce;
      }
      a_vers = 0;
   }
   /*---(walk-fields)--------------------*/
   for (i = 2; i < 20; ++i) {
      /*---(parse field)-----------------*/
      switch (a_vers) {
      case  0 :
         rc = PARSE__current  (i, p, a_spec, &(x_max), x_desc, x_meth, x_args, x_test, x_expe, x_retn);
         if (rc < 0) {
            UDEBUG_KOIOS   ylog_unote   ("could not parse successfully");
            UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
            return rce;
         }
         break;
      default : 
         UDEBUG_KOIOS   ylog_unote   ("version not recognized");
         UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
         return rce;
         break;
      }
      /*---(check which)-----------------*/
      if (i == 2) {
         rc = PARSE__which (a_nscrp, a_line, a_spec, x_desc, x_which);
         UDEBUG_KOIOS   ylog_unote   ("could not extract which/select successfully");
         if (rc < 0) {
            UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
            return rce;
         }
      }
      /*---(drop at max)-----------------*/
      if (i >= x_max)    break;
      /*---(next record)-----------------*/
      UDEBUG_KOIOS   ylog_unote   ("read next field");
      p = strtok_r (NULL  , q, &r);
      --rce;  if (p == NULL) {
         UDEBUG_KOIOS   ylog_unote   ("strtok came up empty");
         break;
      }
      /*---(done)------------------------*/
   } 
   /*---(stop parsing summ records)---*/
   if (i < x_min) {
      yerr_uerror ("%s:%d:0: error: verb ¶%s¶ included %d fields, requires at least %d", a_nscrp, a_line, a_verb, i, x_min);
      UDEBUG_KOIOS   ylog_ucomplex("too few"   , "%d actual < %d min", i, x_min);
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(save-back)-------------------*/
   if (r_desc   != NULL)  strlcpy (r_desc  , x_desc  , LEN_LONG);
   if (r_meth   != NULL)  strlcpy (r_meth  , x_meth  , LEN_HUND);
   if (r_args   != NULL)  strlcpy (r_args  , x_args  , LEN_FULL);
   if (r_test   != NULL)  strlcpy (r_test  , x_test  , LEN_LABEL);
   if (r_expe   != NULL)  strlcpy (r_expe  , x_expe  , LEN_RECD);
   if (r_retn   != NULL)  strlcpy (r_retn  , x_retn  , LEN_FULL);
   if (r_which  != NULL)  strlcpy (r_which , x_which , LEN_TITLE);
   /*---(complete)--------------------*/
   UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
   return 0;
}

char
PARSE_driver            (char a_nscrp [LEN_TITLE], int a_line, char a_vers, char a_verb [LEN_LABEL], char a_spec, char a_recd [LEN_RECD], char r_desc [LEN_LONG], char r_meth [LEN_HUND], char r_args [LEN_FULL], char r_test [LEN_LABEL], char r_expe [LEN_RECD], char r_retn [LEN_FULL], char r_which [LEN_TITLE])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   int         rc          =    0;
   char        x_recd      [LEN_RECD]  = "";     /* incomming record               */
   int         i           = 0;
   char       *p           = NULL;
   char       *q           = "";
   char       *r           = NULL;
   char        x_min       =    0;
   char        x_max       =    0;
   char        x_field     [LEN_RECD]  = "";
   int         l           =    0;
   char        x_desc      [LEN_LONG]  = "";     /* descriptive text               */
   char        x_meth      [LEN_HUND]  = "";     /* function/method name           */
   char        x_args      [LEN_FULL]  = "";     /* function/method args           */
   char        x_test      [LEN_LABEL] = "";     /* test type for yVAR             */
   char        x_expe      [LEN_RECD]  = "";     /* expected results               */
   char        x_retn      [LEN_FULL]  = "";     /* return variable                */
   char        x_which     [LEN_TITLE] = "";     /* which/selective execution      */
   char       *x_empty     = "";
   /*---(header)-------------------------*/
   UDEBUG_KOIOS   ylog_uenter  (__FUNCTION__);
   /*---(quick-out)----------------------*/
   if (strchr ("#1A", a_spec) != NULL) {
      UDEBUG_KOIOS   ylog_unote   ("one field required and already read as verb");
      UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
      return 0;  /* ditto type */
   }
   /*---(default)---------------------*/
   PARSE__default  (r_desc, r_meth, r_args, r_test, r_expe, r_retn);
   /*---(defense)------------------------*/
   UDEBUG_KOIOS   ylog_upoint  ("a_recd"    , a_recd);
   --rce;  if (a_recd == NULL) {
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   strlcpy (x_recd, a_recd, LEN_RECD);
   /*---(read limits)--------------------*/
   UDEBUG_KOIOS   ylog_uchar   ("spec"      , a_spec);
   rc = VERB_limits (a_spec, &x_min, &x_max, NULL);
   UDEBUG_KOIOS   ylog_ucomplex("limits"    , "%4d rc, %d min, %d max", rc, x_min, x_max);
   --rce;  if (rc < 0) {
      yerr_uerror ("%s:%d:0: error: can not identify verb ¶%s¶ with '%c' spec limits", a_nscrp, a_line, a_verb, a_spec);
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(prepare)------------------------*/
   p = strtok_r (x_recd, q, &r);  /* toss verb, already handled */
   p = strtok_r (NULL  , q, &r);
   --rce;  if (p == NULL) {
      p = x_empty;
      /*> UDEBUG_KOIOS   ylog_unote   ("only one field provided");                    <*/
      /*> UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);                                 <*/
      /*> return rce;                                                                 <*/
   }
   /*---(walk-fields)--------------------*/
   for (i = 2; i < 20; ++i) {
      /*---(prepare field)------------------*/
      strlcpy (x_field, p, LEN_RECD);
      if (x_field [0] == '-' && i != 6) {  /* all but expect field */
         if (strncmp (x_field, "- - -", 5) == 0)    x_field [0] = '\0';
         if (strncmp (x_field, "-----", 5) == 0)    x_field [0] = '\0';
         if (x_field [1] == '\0')                   x_field [0] = '\0';
      }
      ystrutrim (x_field, LEN_RECD);
      l = strlen (x_field);
      UDEBUG_KOIOS   ylog_uinfo   ("x_field"   , x_field);
      /*---(drop at end)-----------------*/
      /*> if (strcmp (x_field, "") == 0 && i > x_min) {                               <* 
       *>    UDEBUG_KOIOS   ylog_unote   ("hit empty after min fields read");         <* 
       *>    break;                                                                   <* 
       *> }                                                                           <*/
      /*---(parse field)-----------------*/
      rc = PARSE__field  (a_nscrp, a_line, a_verb, a_spec, i, x_field, x_desc, x_meth, x_args, x_test, x_expe, x_retn, x_which);
      if (rc < 0) {
         UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
         return rce;
      }
      /*---(drop at max)-----------------*/
      if (i >= x_max)    break;
      /*---(next record)-----------------*/
      UDEBUG_KOIOS   ylog_unote   ("read next field");
      p = strtok_r (NULL  , q, &r);
      --rce;  if (p == NULL) {
         p = x_empty;
         /*> UDEBUG_KOIOS   ylog_unote   ("strtok came up empty");                    <*/
         /*> break;                                                                   <*/
      }
      /*---(done)------------------------*/
   } 
   /*---(stop parsing summ records)---*/
   if (i < x_min) {
      yerr_uerror ("%s:%d:0: error: verb ¶%s¶ included %d fields, requires at least %d", a_nscrp, a_line, a_verb, i, x_min);
      UDEBUG_KOIOS   ylog_ucomplex("too few"   , "%d actual < %d min", i, x_min);
      UDEBUG_KOIOS   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(save-back)-------------------*/
   if (r_desc   != NULL)  strlcpy (r_desc  , x_desc  , LEN_LONG);
   if (r_meth   != NULL)  strlcpy (r_meth  , x_meth  , LEN_HUND);
   if (r_args   != NULL)  strlcpy (r_args  , x_args  , LEN_FULL);
   if (r_test   != NULL)  strlcpy (r_test  , x_test  , LEN_LABEL);
   if (r_expe   != NULL)  strlcpy (r_expe  , x_expe  , LEN_RECD);
   if (r_retn   != NULL)  strlcpy (r_retn  , x_retn  , LEN_FULL);
   if (r_which  != NULL)  strlcpy (r_which , x_which , LEN_TITLE);
   /*---(complete)--------------------*/
   UDEBUG_KOIOS   ylog_uexit   (__FUNCTION__);
   return 0;
}


