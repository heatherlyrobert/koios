/*===============================[[ beg-code ]]===============================*/
#include    "koios.h"        /* LOCAL  : main header                          */




#define   SCRP_SAVE  if (r_verb  != NULL)  strlcpy (r_verb , x_verb , LEN_LABEL); \
                     if (r_indx  != NULL)  *r_indx  = x_indx; \
                     if (r_spec  != NULL)  *r_spec  = x_spec; \
                     if (r_conv  != NULL)  *r_conv  = x_conv; \
                     if (r_code  != NULL)  *r_code  = x_code; \
                     if (r_stage != NULL)  strlcpy (r_stage, x_stage, LEN_TERSE); \
                     if (r_vers  != NULL)  strlcpy (r_vers , x_vers , LEN_TERSE);


char
FLOW__defense           (cchar a_scrp [LEN_TITLE], int a_line, cchar a_recd [LEN_RECD], char r_verb [LEN_LABEL], char *r_indx, char *r_spec, char **r_conv, char **r_code, char r_stage [LEN_TERSE], char r_vers [LEN_TERSE])
{
   /*---(locals)-----------+-----------+-*/
   char        rce         = -10;           /* return code for errors         */
   int         l           =   0;
   /*---(header)-------------------------*/
   DEBUG_INPT   yLOG_senter  (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_verb   != NULL)  strcpy (r_verb  , "");
   if (r_indx   != NULL)  *r_indx = -1;
   if (r_spec   != NULL)  *r_spec = '-';
   if (r_conv   != NULL)  *r_conv = NULL;
   if (r_code   != NULL)  *r_code = NULL;
   if (r_stage  != NULL)  strcpy (r_stage , "");
   if (r_vers   != NULL)  strcpy (r_vers  , "");
   /*---(feeder fields)------------------*/
   DEBUG_INPT   yLOG_spoint  (a_scrp);
   --rce;  if (a_scrp == NULL) {
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_INPT   yLOG_sint    (a_line);
   /*---(record)-------------------------*/
   DEBUG_INPT   yLOG_spoint  (a_recd);
   --rce;  if (a_recd == NULL) {
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_INPT   yLOG_schar   (a_recd [0]);
   --rce;  if (a_recd [0] == '\0') {
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   l = strlen (a_recd);
   DEBUG_INPT   yLOG_sint    (l);
   --rce;  if (l <  5 && a_recd [0] != '#') {
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(return fields)------------------*/
   DEBUG_INPT   yLOG_spoint  (r_verb);
   --rce;  if (r_verb == NULL) {
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_INPT   yLOG_spoint  (r_indx);
   --rce;  if (r_indx == NULL) {
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_INPT   yLOG_spoint  (r_spec);
   --rce;  if (r_spec == NULL) {
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_INPT   yLOG_spoint  (r_conv);
   --rce;  if (r_conv == NULL) {
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_INPT   yLOG_spoint  (r_code);
   --rce;  if (r_code == NULL) {
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_INPT   yLOG_spoint  (r_stage);
   --rce;  if (r_stage == NULL) {
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_INPT   yLOG_spoint  (r_vers);
   --rce;  if (r_vers == NULL) {
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(complete)-----------------------*/
   DEBUG_INPT   yLOG_sexit   (__FUNCTION__);
   return 0;
}

char
FLOW__comment           (cchar a_scrp [LEN_TITLE], int a_line, cchar a_recd [LEN_RECD], char r_verb [LEN_LABEL], char *r_indx, char *r_spec, char **r_conv, char **r_code)
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
   DEBUG_INPT   yLOG_senter  (__FUNCTION__);
   /*---(defense)------------------------*/
   DEBUG_INPT   yLOG_spoint  (a_scrp);
   --rce;  if (a_scrp == NULL) {
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_INPT   yLOG_spoint  (a_recd);
   --rce;  if (a_recd == NULL) {
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   x_len = strlen (a_recd);
   /*---(ward-off)-----------------------*/
   DEBUG_INPT   yLOG_sint    (x_len);
   if (x_len < 2) {
      DEBUG_INPT   yLOG_snote   ("too short");
      DEBUG_INPT   yLOG_sexit   (__FUNCTION__);
      return 0;
   }
   if (strncmp (a_recd, "#>", 2) != 0) {
      DEBUG_INPT   yLOG_snote   ("not prefixed with #>");
      DEBUG_INPT   yLOG_sexit   (__FUNCTION__);
      return 0;
   }
   /*---(check for marker)---------------*/
   DEBUG_INPT   yLOG_snote   ("saved record/comment");
   rc = VERB_parse (a_scrp, a_line, "#>", x_verb, &(x_indx), &(x_spec), NULL, &(x_conv), &(x_code));
   DEBUG_INPT   yLOG_sint    (rc);
   --rce;  if (rc < 0) {
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(save-back)----------------------*/
   if (r_verb  != NULL)  strlcpy (r_verb, x_verb, LEN_LABEL);
   if (r_indx  != NULL)  *r_indx = x_indx;
   if (r_spec  != NULL)  *r_spec = x_spec;
   if (r_conv  != NULL)  *r_conv = x_conv;
   if (r_code  != NULL)  *r_code = x_code;
   /*---(complete)-----------------------*/
   DEBUG_INPT   yLOG_sexit   (__FUNCTION__);
   return 1;
}

char
FLOW_driver             (cchar a_scrp [LEN_TITLE], int a_line, cchar a_recd [LEN_RECD], char r_verb [LEN_LABEL], char *r_indx, char *r_spec, char **r_conv, char **r_code, char r_stage [LEN_TERSE], char r_vers [LEN_TERSE])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   int         rc          = 0;             /* generic return code            */
   char        x_recd      [LEN_RECD];
   int         x_len       = 0;             /* input record length            */
   char       *p;
   char       *q           = "";
   char       *r           = NULL;
   char        x_verb      [LEN_LABEL] = "";
   char        x_indx      = -1;
   char        x_spec      = '-';
   void       *x_conv      = NULL;
   void       *x_code      = NULL;
   char        x_stage     [LEN_TERSE] = "";
   char        x_vers      [LEN_TERSE] = "";
   int         i           = 0;
   /*---(header)-------------------------*/
   DEBUG_INPT   yLOG_enter   (__FUNCTION__);
   /*---(defense)---------------------*/
   rc = FLOW__defense (a_scrp, a_line, a_recd, r_verb, r_indx, r_spec, r_conv, r_code, r_stage, r_vers);
   DEBUG_INPT   yLOG_value   ("defense"   , rc);
   --rce;  if (rc < 0) {
      DEBUG_INPT   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(saved comments)-----------------*/
   rc = SCRP__parse_comment (a_recd, x_verb, &x_indx, &x_spec, &x_conv, &x_code);
   DEBUG_INPT   yLOG_value   ("comment"   , rc);
   --rce;  if (rc <= 0) {
      DEBUG_INPT   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   if (rc == 1) {
      DEBUG_INPT   yLOG_exit    (__FUNCTION__);
      return 1;
   }
   /*---(create a copy of recd)----------*/
   strlcpy (x_recd, a_recd, LEN_RECD);
   DEBUG_INPT   yLOG_info    ("x_recd"    , x_recd);
   p  = strtok (x_recd, q);
   /*---(get verb)-----------------------*/
   rc = SCRP__parse_verb (a_scrp, a_line, p, x_verb, &x_indx, &x_spec, &x_conv, &x_code);
   DEBUG_INPT   yLOG_value   ("verb"      , rc);
   --rce;  if (rc < 0) {
      DEBUG_INPT   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(check for shares)---------------*/
   rc = SCRP__reuses_check (a_scrp, a_line, p, my.indx, &(my.cshare), &(my.share), &(my.dittoing), &(my.dmark), &(my.mark), &(my.ditto), &(my.dline));
   DEBUG_INPT   yLOG_value   ("reuses"    , rc);
   --rce;  if (rc < 0) {
      DEBUG_INPT   yLOG_exitr   (__FUNCTION__, rc);
      return rce;
   }
   /*---(check for ditto)----------------*/
   rc = SCRP__ditto_check (a_scrp, a_line, p, my.indx);
   DEBUG_INPT   yLOG_value   ("ditto"     , rc);
   --rce;  if (rc < 0) {
      DEBUG_INPT   yLOG_exitr   (__FUNCTION__, rc);
      return rce;
   }
   if (rc >  0) {
      DEBUG_INPT   yLOG_note    ("FOUND DITTO, back to reading");
      SCRP_SAVE
      /*> SCRP__parse_save (x_verb, x_indx, x_spec, x_conv, x_code, x_stage, x_vers);   <*/
      DEBUG_INPT   yLOG_exit    (__FUNCTION__);
      return 0;
   }
   /*---(check for stage marker)---------*/
   rc = WAVE_parse (a_scrp, a_line, x_indx, x_verb, p, x_stage) ;
   DEBUG_INPT   yLOG_value   ("stage"     , rc);
   --rce;  if (rc < 0) {
      DEBUG_INPT   yLOG_exitr   (__FUNCTION__, rc);
      return rce;
   }
   /*---(read version)-------------------*/
   p = strtok (NULL  , q);
   --rce;  if (p == NULL && x_spec != 'c') {
      yURG_err (YURG_FATAL, "%s:%d:1: error: verb only, %s requires more fields", a_scrp, a_line, x_verb);
      DEBUG_INPT   yLOG_note    ("strtok came up empty");
      DEBUG_INPT   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   x_len = strlen (p);
   strltrim (p, ySTR_BOTH, x_len);
   x_len = strlen (p);
   if (p[0] == '-')  p[0] = '\0';
   rc = 0;
   /*---(handle version)-----------------*/
   if      (x_len != 3 || p [0] != 'v') {
      if (x_spec!= 'c')  rc = SCRP__current (a_scrp, a_line, x_verb, x_spec, p, my.desc, my.meth, my.args, my.test, my.expe, my.retn, my.code);
   } else if (strcmp (p, "v21") == 0) {
      strlcpy (x_vers       , p    , LEN_LABEL);
      DEBUG_INPT   yLOG_info    ("vers"      , x_vers );
      if (x_spec!= 'c')  rc = SCRP_vers21  ();
   } else if (strcmp (p, "v20") == 0) {
      strlcpy (x_vers       , p    , LEN_LABEL);
      DEBUG_INPT   yLOG_info    ("vers"      , x_vers );
      if (x_spec!= 'c')  rc = SCRP_vers20  ();
   } else                             {
      strlcpy (x_vers       , "v19", LEN_LABEL);
      DEBUG_INPT   yLOG_info    ("vers"      , x_vers );
      strlcpy (my.desc      , p    , LEN_LONG );
      DEBUG_INPT   yLOG_info    ("desc"      , my.desc);
      if (x_spec!= 'c')  rc = SCRP_vers19  ();
   }
   /*---(check for trouble)--------------*/
   if (rc < 0) {
      DEBUG_INPT   yLOG_note    ("trouble parsing");
      DEBUG_INPT   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   /*---(save-back)----------------------*/
   SCRP_SAVE
   /*> SCRP__parse_save (x_verb, x_indx, x_spec, x_conv, x_code, x_stage, x_vers);    <*/
   /*---(complete)-----------------------*/
   DEBUG_INPT   yLOG_exit    (__FUNCTION__);
   return 0;
}
