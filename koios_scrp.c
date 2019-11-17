/*===============================[[ beg-code ]]===============================*/
#include    "koios.h"        /* LOCAL  : main header                          */



static  int   s_ditto    = -1;
static  char  s_dittoing = '-';
static  FILE *s_file_save;
static  FILE *s_file_ditto;
static  int   s_lineno   =   0;

static  int   s_dittos [26] = { -1 };

tVERB       g_verbs [MAX_VERB] = {
   /* --------------   ---------------------------------------   -  */
   { "PREP"         , "preparation before testing"            , '2',  0,  0 },
   { "incl"         , "c header inclusion"                    , '3',  0,  0 },
   { "#>"           , "script internal comments"              , 'c',  0,  0 },
   /* --------------   --------------------------------------- */
   { "SECT"         , "grouping of scripts"                   , '2',  0,  0 },
   { "SCRP"         , "test script"                           , '3',  0,  0 },
   { "SHARED"       , "shared code between scripts"           , '2',  0,  0 },
   /* --------------   --------------------------------------- */
   { "GROUP"        , "grouping of conditions"                , '2',  0,  0 },
   { "COND"         , "test condition"                        , '2',  0,  0 },
   { "DITTO"        , "repeated test condition"               , '1',  0,  0 },
   { "USE_SHARE"    , "inclusion of shared code"              , '2',  0,  0 },
   /* --------------   --------------------------------------- */
   { "exec"         , "function execution"                    , 'f',  0,  0 },
   { "get"          , "unit test accessor retrieval"          , 'f',  0,  0 },
   { "echo"         , "test a variable directly"              , 'f',  0,  0 },
   /* --------------   --------------------------------------- */
   { "mode"         , "set pass or forced_fail mode"          , 'p',  0,  0 },
   { "code"         , "insert c code"                         , 'p',  0,  0 },
   { "load"         , "place data into stdin"                 , 'P',  0,  0 },
   { "sys"          , "execute shell code"                    , 'p',  0,  0 },
   /* --------------   --------------------------------------- */
   { "----"         , "end-of-entries"                        , '-',  0,  0 },
   /* --------------   --------------------------------------- */
};



/*====================------------------------------------====================*/
/*===----                    for ditting lines                         ----===*/
/*====================------------------------------------====================*/
static void      o___DITTOING________________o (void) {;}

char
SCRP_ditto__clear       (void)
{
   int         i           =    0;
   for (i = 0; i < 26; ++i) {
      s_dittos [i] = -1;
   }
   return 0;
}

char
SCRP_ditto__set         (char a_mark)
{
   char        rce         =  -10;
   --rce;  if (s_file_ditto != NULL)          return rce;
   --rce;  if (a_mark < 'A' || a_mark > 'Z')  return rce;
   s_dittos [a_mark - 'A'] = my.n_line;
   return 0;
}

char
SCRP_ditto__beg         (char *a_verb)
{
   /*---(locals)-----------+-----------+-*/
   char        rce         =  -10;
   char       *p           = NULL;
   /*---(header)-------------------------*/
   DEBUG_INPT   yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   DEBUG_INPT   yLOG_spoint  (a_verb);
   --rce;  if (a_verb == NULL) {
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(parse ditto line)---------------*/
   p = strstr (a_verb, "DITTO (");
   DEBUG_INPT   yLOG_spoint  (p);
   --rce;  if (p == NULL) {
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_INPT   yLOG_sint    (p - a_verb);
   --rce;  if (p - a_verb > 20) {
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(save mark)----------------------*/
   --rce;  if (p [7] < 'A' || p [7] > 'Z') {
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   --rce;  if (s_dittos [p [7] - 'A'] < 1) {
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   s_ditto      = p [7] - 'A';
   /*---(reopen file)--------------------*/
   s_file_ditto = fopen (my.name_scrp, "r");
   DEBUG_INPT   yLOG_point   ("refile*"   , s_file_ditto);
   --rce;  if (my.file_scrp == NULL) {
      DEBUG_TOPS   yLOG_fatal   ("scrp file, can not open script file");
      DEBUG_TOPS   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(swap files)---------------------*/
   DEBUG_INPT   yLOG_note    ("swap file for script");
   s_file_save  = my.file_scrp;
   my.file_scrp = s_file_ditto;
   s_lineno     = 0;
   s_dittoing   = 'y';
   /*---(complete)-----------------------*/
   DEBUG_INPT   yLOG_exit    (__FUNCTION__);
   return 0;
}

char
SCRP_ditto__check       (char *a_verb)
{
   /*---(locals)-----------+-----------+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char       *p           = NULL;
   /*---(header)-------------------------*/
   DEBUG_INPT   yLOG_senter  (__FUNCTION__);
   /*---(defense)------------------------*/
   DEBUG_INPT   yLOG_spoint  (a_verb);
   --rce;  if (a_verb == NULL) {
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(find cond lines)----------------*/
   p = strstr (a_verb, "COND (");
   DEBUG_INPT   yLOG_spoint  (p);
   --rce;  if (p == NULL) {
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_INPT   yLOG_sint    (p - a_verb);
   --rce;  if (p - a_verb > 20) {
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(find our cond)------------------*/
   DEBUG_INPT   yLOG_schar   (p [6]);
   rc = SCRP_ditto__set (p [6]);
   /*---(complete)-----------------------*/
   DEBUG_INPT   yLOG_sexit   (__FUNCTION__);
   return rc;
}

char
SCRP_ditto__end         (void)
{
   /*---(locals)-----------+-----------+-*/
   char        rce         =  -10;
   char        rc          =    0;
   /*---(header)-------------------------*/
   DEBUG_INPT   yLOG_enter   (__FUNCTION__);
   /*---(reset ditto)--------------------*/
   s_ditto    = -1;
   s_dittoing = '-';
   /*---(swap files)---------------------*/
   DEBUG_INPT   yLOG_note    ("swap file for script");
   my.file_scrp = s_file_save;
   /*---(close detail report)------------*/
   DEBUG_INPT   yLOG_point   ("file_ditto", s_file_ditto);
   rc = fclose (s_file_ditto);
   --rce;  if (rc != 0) {
      DEBUG_TOPS   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(null closed pointers)-----------*/
   s_file_ditto = NULL;
   s_file_save  = NULL;
   s_lineno     = 0;
   /*---(complete)-----------------------*/
   DEBUG_INPT   yLOG_exit    (__FUNCTION__);
   return 0;
}



/*====================------------------------------------====================*/
/*===----                      reading the file                        ----===*/
/*====================------------------------------------====================*/
static void      o___READING_________________o (void) {;}

char         /*--> open script file ----------------------[ leaf   [ ------ ]-*/
SCRP_open          (void)
{
   /*---(locals)-----------+-----------+-*/
   char        rce         = -10;           /* return code for errors         */
   /*---(header)-------------------------*/
   DEBUG_TOPS   yLOG_enter   (__FUNCTION__);
   /*---(open configuration)-------------*/
   DEBUG_INPT   yLOG_point   ("name"      , my.name_scrp);
   my.file_scrp = fopen (my.name_scrp, "r");
   DEBUG_INPT   yLOG_point   ("file*"     , my.file_scrp);
   --rce;  if (my.file_scrp == NULL) {
      DEBUG_TOPS   yLOG_fatal   ("scrp file, can not open script file");
      DEBUG_TOPS   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_INPT   yLOG_note    ("script file open");
   my.n_line = 0;
   SCRP_ditto__clear ();
   /*---(complete)-----------------------*/
   DEBUG_TOPS   yLOG_exit    (__FUNCTION__);
   return 0;
}

char         /*--> clean a script record -----------------[ leaf   [ ------ ]-*/
SCRP_clear         (void)
{
   /*---(header)-------------------------*/
   DEBUG_INPT   yLOG_senter  (__FUNCTION__);
   /*---(save value)---------------------*/
   strlcpy (my.last, my.verb, LEN_LABEL);
   /*---(input vars)---------------------*/
   my.verb        [0] = '\0';
   my.spec            = '-';
   my.status          = '-';
   my.vers        [0] = '\0';
   my.desc        [0] = '\0';
   my.meth        [0] = '\0';
   my.args        [0] = '\0';
   my.test        [0] = '\0';
   my.expe        [0] = '\0';
   my.type            = '-';
   my.retn        [0] = '\0';
   my.code        [0] = '\0';
   my.refn        [0] = '\0';
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
SCRP_read          (void)
{
   /*---(locals)-----------+-----------+-*/
   int         rc          = 0;             /* generic return code            */
   char        rce         = -10;           /* return code for errors         */
   char        x_recd      [LEN_RECD];
   int         x_len       = 0;             /* input record length            */
   char        x_temp      [20];
   /*---(header)-------------------------*/
   DEBUG_INPT   yLOG_enter   (__FUNCTION__);
   DEBUG_INPT   yLOG_point   ("*scrp"     , my.file_scrp);
   /*---(defense)------------------------*/
   --rce;  if (my.file_scrp == NULL) {
      DEBUG_INPT   yLOG_fatal   ("scrp file, file not open");
      DEBUG_INPT   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   --rce;  if (feof (my.file_scrp)) {
      DEBUG_INPT   yLOG_note    ("already at end of file");
      DEBUG_INPT   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   /*---(initialize)---------------------*/
   DEBUG_INPT   yLOG_note    ("initialize my.recd");
   my.recd [0] = '\0';
   /*---(read for a good record)---------*/
   --rce;
   while (1) {
      /*---(read next)-------------------*/
      DEBUG_INPT   yLOG_note    ("read script file");
      fgets (x_recd, LEN_RECD, my.file_scrp);
      if (feof (my.file_scrp)) {
         DEBUG_INPT   yLOG_note    ("hit end of file");
         DEBUG_INPT   yLOG_exit    (__FUNCTION__);
         return rce;
      }
      if (s_dittoing == '-') ++my.n_line;
      else  {
         ++s_lineno;
         if (s_lineno <  s_dittos [s_ditto]) continue;
      }
      DEBUG_INPT   yLOG_value   ("line#"     , my.n_line);
      /*---(filter)----------------------*/
      x_len = strllen (x_recd, LEN_RECD);
      x_recd [--x_len] = '\0';
      if (x_recd [0] == '\0') {
         DEBUG_INPT   yLOG_note    ("empty, skipping");
         if (s_dittoing != '-')  SCRP_ditto__end ();
         else                    ++my.n_empty;
         continue;
      }
      if (x_recd [0] == '#' && x_recd [1] != '>') {
         DEBUG_INPT   yLOG_note    ("comment, skipping");
         if (s_dittoing != '-')  SCRP_ditto__end ();
         else                    ++my.n_comment;
         continue;
      }
      DEBUG_INPT   yLOG_value   ("length"    , x_len);
      if (x_len <= 10)  {
         DEBUG_INPT   yLOG_note    ("too short, skipping");
         if (s_dittoing != '-')  SCRP_ditto__end ();
         else                    ++my.n_short;
         continue;
      }
      /*---(translate delayed chars)-----*/
      strlundelay (x_recd, LEN_RECD);
      /*---(copy)------------------------*/
      DEBUG_INPT   yLOG_note    ("save copy of source record");
      strlcpy (my.recd, x_recd, LEN_RECD);
      my.len   = x_len;
      ++my.n_recd;
      break;
   }
   DEBUG_INPT   yLOG_note    ("got a good record");
   /*---(complete)-----------------------*/
   DEBUG_INPT   yLOG_exit    (__FUNCTION__);
   return 0;
}

char         /*--> parse out current records -------------[ leaf   [ ------ ]-*/
SCRP__current      (char *a_first)
{
   /*---(locals)-----------+-----------+-*/
   int         rc          = 0;             /* generic return code            */
   char        rce         = -10;           /* return code for errors         */
   int         i           = 0;
   char       *p;
   char       *q           = "\x1F";
   /*---(read fields)--------------------*/
   if (my.spec == '1')  return 0;  /* ditto type */
   p = a_first;
   for (i = 2; i < 20; ++i) {
      /*---(clear spacer bars)-----------*/
      if (p[0] == '-') {  /* begin careful to avoid negative numbers ;)) */
         switch (p[1]) {
         case ' '  :   /* catches "- - - - - - -" lines */
         case '-'  :   /* catches "-------------" lines */
         case '\0' :   /* catches "-" placeholder lines */
            p[0] = '\0';
            break;
         }
      }
      /*---(handle fields)---------------*/
      switch (i) {
      case  2 :   strlcpy (my.desc      , p, LEN_DESC );
                  DEBUG_INPT   yLOG_info    ("desc"      , my.desc);
                  break;
      case  3 :   if (my.spec != 'p') {
                     strlcpy (my.meth      , p, LEN_DESC );
                     DEBUG_INPT   yLOG_info    ("meth"      , my.meth);
                  }
                  break;
      case  4 :   if (my.spec == 'P' || my.spec == 'p') {
                     strlcpy (my.code      , p, LEN_RECD);
                     DEBUG_INPT   yLOG_info    ("code"      , my.code);
                  } else {
                     strlcpy (my.args      , p, LEN_STR);
                     strlcpy (my.code      , p, LEN_STR);
                     DEBUG_INPT   yLOG_info    ("args"      , my.args);
                  }
                  break;
      case  5 :   strlcpy (my.test      , p, LEN_LABEL);
                  DEBUG_INPT   yLOG_info    ("test"      , my.test);
                  break;
      case  6 :   strlcpy (my.expe      , p, LEN_OUT  );
                  DEBUG_INPT   yLOG_info    ("expe"      , my.expe);
                  break;
      case  7 :   my.type      = p [0];
                  if (my.type == '\0')  my.type = '-';
                  DEBUG_INPT   yLOG_char    ("type"      , my.type);
                  break;
      case  8 :   strlcpy (my.retn      , p, LEN_STR);
                  DEBUG_INPT   yLOG_info    ("retn"      , my.retn);
                  break;
      }
      /*---(stop parsing summ records)---*/
      if (i >  2 && my.spec == '2')  break;  /* organization types  */
      if (i >  3 && my.spec == '3')  break;  /* organization types  */
      if (i >= 4 && my.spec == 'P')  break;  /* load type           */
      if (i >= 4 && my.spec == 'p')  break;  /* code/sys types      */
      /*---(next record)-----------------*/
      DEBUG_INPT   yLOG_note    ("read next field");
      p = strtok (NULL  , q);
      --rce;  if (p == NULL) {
         DEBUG_INPT   yLOG_note    ("strtok came up empty");
         DEBUG_INPT   yLOG_exit    (__FUNCTION__);
         break;
      }
      strltrim (p, ySTR_BOTH, LEN_RECD);
   } 
   return 0;
}

char         /*--> parse out a v21 records ---------------[ leaf   [ ------ ]-*/
SCRP_vers21        (void)
{
   /*---(design notes)-------------------*/
   /*
    *   version 21 of the script fields moved the code/load/sys payload to
    *   the 4th field (from the 3rd) for strictly ascetheic reasons so it
    *   would be easier to read and edit the scrits.
    *
    */
   /*---(locals)-----------+-----------+-*/
   int         rc          = 0;             /* generic return code            */
   char        rce         = -10;           /* return code for errors         */
   int         i           = 0;
   char       *p;
   char       *q           = "\x1F";
   /*---(read fields)--------------------*/
   for (i = 2; i < 20; ++i) {
      DEBUG_INPT   yLOG_note    ("read next field");
      p = strtok (NULL  , q);
      --rce;  if (p == NULL) {
         DEBUG_INPT   yLOG_note    ("strtok came up empty");
         DEBUG_INPT   yLOG_exit    (__FUNCTION__);
         break;
      }
      strltrim (p, ySTR_BOTH, LEN_RECD);
      /*---(clear spacer bars)-----------*/
      if (p[0] == '-') {  /* begin careful to avoid negative numbers ;)) */
         switch (p[1]) {
         case ' '  :   /* catches "- - - - - - -" lines */
         case '-'  :   /* catches "-------------" lines */
         case '\0' :   /* catches "-" placeholder lines */
            p[0] = '\0';
            break;
         }
      }
      /*---(handle fields)---------------*/
      switch (i) {
      case  2 :   strlcpy (my.desc      , p, LEN_DESC );
                  DEBUG_INPT   yLOG_info    ("desc"      , my.desc);
                  break;
      case  3 :   if (my.spec != 'p') {
                     strlcpy (my.meth      , p, LEN_DESC );
                     DEBUG_INPT   yLOG_info    ("meth"      , my.meth);
                  }
                  break;
      case  4 :   if (my.spec == 'P' || my.spec == 'p') {
                     strlcpy (my.code      , p, LEN_RECD);
                     DEBUG_INPT   yLOG_info    ("code"      , my.code);
                  } else {
                     strlcpy (my.args      , p, LEN_STR);
                     strlcpy (my.code      , p, LEN_STR);
                     DEBUG_INPT   yLOG_info    ("args"      , my.args);
                  }
                  break;
      case  5 :   strlcpy (my.test      , p, LEN_LABEL);
                  DEBUG_INPT   yLOG_info    ("test"      , my.test);
                  break;
      case  6 :   strlcpy (my.expe      , p, LEN_OUT  );
                  DEBUG_INPT   yLOG_info    ("expe"      , my.expe);
                  break;
      case  7 :   my.type      = p [0];
                  if (my.type == '\0')  my.type = '-';
                  DEBUG_INPT   yLOG_char    ("type"      , my.type);
                  break;
      case  8 :   strlcpy (my.retn      , p, LEN_STR);
                  DEBUG_INPT   yLOG_info    ("retn"      , my.retn);
                  break;
      }
      /*---(stop parsing summ records)---*/
      if (i >= 2 && my.spec == '2')  break;  /* organization types  */
      if (i >= 3 && my.spec == '-')  break;  /* organization types  */
      if (i >= 4 && my.spec == 'P')  break;  /* load type           */
      if (i >= 4 && my.spec == 'p')  break;  /* code/sys types      */
   } 
   return 0;
}

char         /*--> parse out a v20 records ---------------[ leaf   [ ------ ]-*/
SCRP_vers20        (void)
{
   /*---(design notes)-------------------*/
   /*
    *   version 20 of the script fields added a version number to the records
    *   to allow easier conversion and more flexible updating.  i decided to
    *   put this field up front to make paring much easier.
    *
    */
   /*---(locals)-----------+-----------+-*/
   int         rc          = 0;             /* generic return code            */
   char        rce         = -10;           /* return code for errors         */
   int         i           = 0;
   char       *p;
   char       *q           = "\x1F";
   /*---(read fields)--------------------*/
   for (i = 2; i < 20; ++i) {
      /*---(read field)------------------*/
      DEBUG_INPT   yLOG_note    ("read next field");
      p = strtok (NULL  , q);
      --rce;  if (p == NULL) {
         DEBUG_INPT   yLOG_note    ("strtok came up empty");
         DEBUG_INPT   yLOG_exit    (__FUNCTION__);
         break;
      }
      strltrim (p, ySTR_BOTH, LEN_RECD);
      /*---(clear spacer bars)-----------*/
      if (p[0] == '-') {
         switch (p[1]) {
         case ' '  :   /* catches "- - - - - - -" lines */
         case '-'  :   /* catches "-------------" lines */
         case '\0' :   /* catches "-" placeholder lines */
            p[0] = '\0';
            break;
         }
      }
      /*---(handle fields)---------------*/
      switch (i) {
      case  2 :   strlcpy (my.desc      , p, LEN_DESC );
                  DEBUG_INPT   yLOG_info    ("desc"      , my.desc);
                  break;
      case  3 :   if (my.spec == 'p') {
                     strlcpy (my.code      , p, LEN_RECD);
                     DEBUG_INPT   yLOG_info    ("code"      , my.code);
                  } else {
                     strlcpy (my.meth      , p, LEN_DESC );
                     DEBUG_INPT   yLOG_info    ("meth"      , my.meth);
                  }
                  break;
      case  4 :   strlcpy (my.args      , p, LEN_STR);
                  strlcpy (my.code      , p, LEN_STR);
                  DEBUG_INPT   yLOG_info    ("args"      , my.args);
                  break;
      case  5 :   strlcpy (my.test      , p, LEN_LABEL);
                  DEBUG_INPT   yLOG_info    ("test"      , my.test);
                  break;
      case  6 :   strlcpy (my.expe      , p, LEN_OUT  );
                  DEBUG_INPT   yLOG_info    ("expe"      , my.expe);
                  break;
      case  7 :   my.type      = p [0];
                  if (my.type == '\0')  my.type = '-';
                  DEBUG_INPT   yLOG_char    ("type"      , my.type);
                  break;
      case  8 :   strlcpy (my.retn      , p, LEN_STR);
                  DEBUG_INPT   yLOG_info    ("retn"      , my.retn);
                  break;
      }
      /*---(stop parsing summ records)---*/
      if (i >= 3 && my.spec == '-')  break;  /* organization types  */
      if (i >= 3 && my.spec == 'p')  break;  /* code/load/sys types */
   } 
   return 0;
}

char         /*--> parse out original records ------------[ leaf   [ ------ ]-*/
SCRP_vers19        (void)
{
   /*---(design notes)-------------------*/
   /*
    *   version 19, and before, of the script fields had no version number
    *
    */
   /*---(locals)-----------+-----------+-*/
   int         rc          = 0;             /* generic return code            */
   char        rce         = -10;           /* return code for errors         */
   int         i           = 0;
   char       *p;
   char       *q           = "\x1F";
   /*---(read fields)--------------------*/
   for (i = 2; i < 20; ++i) {
      DEBUG_INPT   yLOG_note    ("read next field");
      p = strtok (NULL  , q);
      --rce;  if (p == NULL) {
         DEBUG_INPT   yLOG_note    ("strtok came up empty");
         DEBUG_INPT   yLOG_exit    (__FUNCTION__);
         break;
      }
      strltrim (p, ySTR_BOTH, LEN_RECD);
      /*---(clear spacer bars)-----------*/
      if (p[0] == '-') {
         switch (p[1]) {
         case ' '  :   /* catches "- - - - - - -" lines */
         case '-'  :   /* catches "-------------" lines */
         case '\0' :   /* catches "-" placeholder lines */
            p[0] = '\0';
            break;
         }
      }
      /*---(handle fields)---------------*/
      switch (i) {
      case  2 :   if (my.spec == 'p') {
                     strlcpy (my.code      , p, LEN_RECD);
                     DEBUG_INPT   yLOG_info    ("code"      , my.code);
                  } else {
                     strlcpy (my.meth      , p, LEN_DESC );
                     DEBUG_INPT   yLOG_info    ("meth"      , my.meth);
                  }
                  break;
      case  3 :   strlcpy (my.args      , p, LEN_STR);
                  strlcpy (my.code      , p, LEN_STR);
                  DEBUG_INPT   yLOG_info    ("args"      , my.args);
                  break;
      case  4 :   strlcpy (my.test      , p, LEN_LABEL);
                  DEBUG_INPT   yLOG_info    ("test"      , my.test);
                  break;
      case  5 :   strlcpy (my.expe      , p, LEN_OUT  );
                  DEBUG_INPT   yLOG_info    ("expe"      , my.expe);
                  break;
      }
      if (i >= 2 && my.spec == '-')  break;  /* organization types  */
      if (i >= 2 && my.spec == 'p')  break;  /* code/load/sys types */
   } 
   return 0;
}

char         /*--> parse out a script record -------------[ leaf   [ ------ ]-*/
SCRP_parse         (void)
{
   /*---(locals)-----------+-----------+-*/
   int         rc          = 0;             /* generic return code            */
   char        rce         = -10;           /* return code for errors         */
   char        x_recd      [LEN_RECD];
   int         x_len       = 0;             /* input record length            */
   char       *p;
   char       *q           = "\x1F";
   char       *r           = NULL;
   char        x_temp      [20];
   int         i           = 0;
   /*---(header)-------------------------*/
   DEBUG_INPT   yLOG_enter   (__FUNCTION__);
   /*---(prepare)---------------------*/
   SCRP_clear      ();
   /*---(defense)------------------------*/
   --rce;  if (my.file_scrp == NULL) {
      DEBUG_INPT   yLOG_fatal   ("scrp file, file not open");
      DEBUG_INPT   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   --rce;  if (my.recd [0] == '\0') {
      DEBUG_INPT   yLOG_note    ("NULL record in my.recd");
      DEBUG_INPT   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   DEBUG_INPT   yLOG_info    ("record"    , my.recd);
   DEBUG_INPT   yLOG_value   ("length"    , my.len);
   --rce;  if (my.len <  5 && my.recd [0] != '#') {
      DEBUG_INPT   yLOG_note    ("my.len too short");
      DEBUG_INPT   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   /*---(create a copy of recd)----------*/
   DEBUG_INPT   yLOG_note    ("create a copy of source record");
   strlcpy (x_recd, my.recd, LEN_RECD);
   DEBUG_INPT   yLOG_info    ("x_recd"    , x_recd);
   if (x_recd [0] == '#' && x_recd [1] == '>') {
      DEBUG_INPT   yLOG_note    ("found saved record/comment");
      strlcpy (my.verb, "#>", LEN_LABEL);
      return 0;
   }
   /*---(get recd type)------------------*/
   p = strtok (x_recd, q);
   DEBUG_INPT   yLOG_point   ("*p"        , p);
   --rce;  if (p == NULL) {
      DEBUG_INPT   yLOG_note    ("strtok came up empty");
      DEBUG_INPT   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   strltrim (p, ySTR_BOTH, LEN_STR);
   x_len = strlen (p);
   DEBUG_INPT   yLOG_value   ("x_len"     , x_len);
   --rce;  if (x_len <= 2) {
      DEBUG_INPT   yLOG_note    ("verb is too short");
      DEBUG_INPT   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   DEBUG_INPT   yLOG_point   ("verb"      , p);
   DEBUG_INPT   yLOG_info    ("verb"      , p);
   sprintf (x_temp, " %s ", p);
   --rce;  if (p [0] == '#' && p [1] != '>') {
      DEBUG_INPT   yLOG_note    ("comment not in column one");
      DEBUG_INPT   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   DEBUG_INPT   yLOG_note    ("search for verb");
   my.indx = -1;
   for (i = 0; i < MAX_VERB; ++i) {
      if (g_verbs [i].name [0] == '-') {
         DEBUG_INPT   yLOG_note    ("end of verbs");
         break;
      }
      if (g_verbs [i].name [0] != p[0])          continue;
      if (strncmp (g_verbs [i].name, p, 4) != 0) continue;
      DEBUG_INPT   yLOG_note    ("verb found, save");
      strlcpy (my.verb, g_verbs [i].name, LEN_LABEL);
      my.indx    = i;
      ++g_verbs [i].count;
      ++g_verbs [i].total;
      my.spec    = g_verbs [i].spec;
      break;
   }
   --rce;  if (my.indx == -1) {
      DEBUG_INPT   yLOG_note    ("verb not found");
      DEBUG_INPT   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(check for ditto)----------------*/
   if (my.run_type == G_RUN_CREATE) {
      if (strcmp ("SCRP" , g_verbs [i].name) == 0) {
         DEBUG_INPT   yLOG_note    ("clear ditto marks");
         SCRP_ditto__clear ();
      } else if (strcmp ("COND", g_verbs [i].name) == 0 && p [5] == '(' && p [7] == ')') {
         DEBUG_INPT   yLOG_note    ("found a ditto condition");
         rc = SCRP_ditto__check (p);
      } else if (strcmp ("DITTO", g_verbs [i].name) == 0) {
         DEBUG_INPT   yLOG_note    ("found a ditto verb");
         rc = SCRP_ditto__beg (p);
         DEBUG_INPT   yLOG_exit    (__FUNCTION__);
         return rc;
      }
   } else {
      if (strcmp ("COND", g_verbs [i].name) == 0 && p [5] == '(' && p [7] == ')') {
         DEBUG_INPT   yLOG_note    ("found a ditto condition");
         my.mark = p [6];
      } else if (strcmp ("DITTO", g_verbs [i].name) == 0) {
         DEBUG_INPT   yLOG_note    ("found a ditto verb");
         my.mark = p [7];
      }
   }
   /*---(read version)-------------------*/
   p = strtok (NULL  , q);
   --rce;  if (p == NULL && my.spec != 'c') {
      DEBUG_INPT   yLOG_note    ("strtok came up empty");
      DEBUG_INPT   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   strltrim (p, ySTR_BOTH, LEN_RECD);
   x_len = strlen (p);
   if (p[0] == '-')  p[0] = '\0';
   if      (x_len != 3 || p [0] != 'v') {
      if (my.spec != 'c')  SCRP__current (p);
   } else if (strcmp (p, "v21") == 0) {
      strlcpy (my.vers      , p    , LEN_LABEL);
      DEBUG_INPT   yLOG_info    ("vers"      , my.vers);
      if (my.spec != 'c')  SCRP_vers21  ();
   } else if (strcmp (p, "v20") == 0) {
      strlcpy (my.vers      , p    , LEN_LABEL);
      DEBUG_INPT   yLOG_info    ("vers"      , my.vers);
      SCRP_vers20  ();
   } else                             {
      strlcpy (my.vers      , "v19", LEN_LABEL);
      DEBUG_INPT   yLOG_info    ("vers"      , my.vers);
      strlcpy (my.desc      , p    , LEN_DESC );
      DEBUG_INPT   yLOG_info    ("desc"      , my.desc);
      SCRP_vers19  ();
   }
   /*---(complete)-----------------------*/
   DEBUG_INPT   yLOG_exit    (__FUNCTION__);
   return 0;
}


char         /*--> close script file ---------------------[ ------ [ ------ ]-*/
SCRP_close         (void)
{
   /*---(locals)-----------+-----------+-*/
   char        rc          = 0;
   char        rce         = -10;
   /*---(header)-------------------------*/
   DEBUG_TOPS   yLOG_enter   (__FUNCTION__);
   /*---(close detail report)------------*/
   DEBUG_INPT   yLOG_point   ("*file_scrp", my.file_scrp);
   --rce;  if (my.file_scrp == NULL) {
      DEBUG_TOPS   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   rc = fclose (my.file_scrp);
   --rce;  if (rc != 0) {
      DEBUG_TOPS   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   my.file_scrp = NULL;
   /*---(terminate logging)--------------*/
   DEBUG_TOPS   yLOG_exit    (__FUNCTION__);
   /*---(complete)-----------------------*/
   return 0;
}

char         /*--> close script file ---------------------[ ------ [ ------ ]-*/
SCRP_verbs         (void)
{
   int         i           = 0;
   int         c           = 0;
   printf ("verb counts...\n");
   for (i = 0; i < MAX_VERB; ++i) {
      printf  ("   %-10s  %4d\n", g_verbs [i].name, g_verbs [i].total);
      c += g_verbs [i].total;
      if (g_verbs [i].name [0] == '-') break;
   }
   printf  ("   %-10s  %4d\n", "TOTAL"   , c);
   printf  ("   %-10s  %4d\n", "concerns", my.n_recd - c);
   return 0;
}

char         /*--> close script file ---------------------[ ------ [ ------ ]-*/
SCRP_verbcode      (void)
{
   int         i           = 0;
   int         c           = 0;
   fprintf (my.file_code, "char\n");
   fprintf (my.file_code, "UNIT_stats (void)\n");
   fprintf (my.file_code, "{\n");
   fprintf (my.file_code, "   printf (\"koios, record type summary\\n\");\n");
   for (i = 0; i < MAX_VERB; ++i) {
      fprintf (my.file_code, "   printf (\"%-10.10s = %5d   %s\\n\");\n", g_verbs [i].name, g_verbs [i].total, g_verbs [i].desc);
      c += g_verbs [i].total;
      if (g_verbs [i].name [0] == '-') break;
   }
   fprintf (my.file_code, "   printf (\"%-10.10s = %5d   %s\\n\");\n", "TOTAL"         , c                , "sum of all verbs");
   fprintf (my.file_code, "   printf (\"%-10.10s = %5d   %s\\n\");\n", "concerns"      , my.n_recd - c    , "records with troubles");
   fprintf (my.file_code, "   exit (0);\n");
   fprintf (my.file_code, "}\n");
   return 0;
}



/*====================------------------------------------====================*/
/*===----                         unit testing                         ----===*/
/*====================------------------------------------====================*/
static void      o___UNITTEST________________o (void) {;};

char*      /*----: unit testing accessor for clean validation interface ------*/
SCRP__unit              (char *a_question, int a_num)
{
   /*---(locals)-----------+-----+-----+-*/
   int         i           =    0;
   char        s           [LEN_LABEL];
   char        t           [LEN_RECD ];
   /*---(preprare)-----------------------*/
   strlcpy  (my.answer, "SCRP unit      : question not understood", LEN_STR);
   if      (strcmp (a_question, "file"      ) == 0) {
      sprintf (my.answer, "SCRP file      : %-35.35s %p", my.name_scrp, my.file_scrp);
   }
   else if (strcmp (a_question, "recd"      ) == 0) {
      strlcpy    (t, my.recd, LEN_RECD);
      strlencode (t, ySTR_NONE, LEN_RECD);
      sprintf (my.answer, "SCRP recd      : %2d %3d[%.40s]", my.n_line, strlen (t), t);
   }
   else if (strcmp (a_question, "verb"      ) == 0) {
      sprintf (my.answer, "SCRP verb      : %-10.10s %3d[%.30s]", my.verb, strlen (my.desc), my.desc);
   }
   else if (strcmp (a_question, "call"      ) == 0) {
      sprintf (t, "[%.20s]", my.meth);
      sprintf (my.answer, "SCRP call      : %3d%-22.22s %3d[%.20s]", strlen (my.meth), t, strlen (my.args), my.args);
   }
   else if (strcmp (a_question, "test"      ) == 0) {
      sprintf (my.answer, "SCRP test      : %-10.10s %3d[%.30s]", my.test, strlen (my.expe), my.expe);
   }
   else if (strcmp (a_question, "retn"      ) == 0) {
      sprintf (my.answer, "SCRP retn      : %c          %3d[%.30s]", my.type, strlen (my.retn), my.retn);
   }
   else if (strcmp (a_question, "code"      ) == 0) {
      strlcpy    (t, my.code, LEN_RECD);
      strlencode (t, ySTR_NONE, LEN_RECD);
      sprintf (my.answer, "SCRP code      : %3d[%.40s]", strlen (t), t);
   }
   else if (strcmp (a_question, "mark"      ) == 0) {
      sprintf (my.answer, "SCRP mark      : %c", my.mark);
   }
   else if (strcmp (a_question, "ditto"     ) == 0) {
      sprintf (my.answer, "SCRP ditto     : %2d  %c  %-10p  %-10p  %3d", s_ditto, s_dittoing, s_file_save, s_file_ditto, s_lineno);
   }
   else if (strcmp (a_question, "dittos"    ) == 0) {
      strlcpy (t, "", LEN_RECD);
      for (i = 0; i < 15; ++i) {
         if (s_dittos [i] > 0)  sprintf (s, " %2d", s_dittos [i]);
         else                   sprintf (s, "  -");
         strlcat (t, s, LEN_RECD);
      }
      sprintf (my.answer, "SCRP dittos A-O:%s", t);
   }
   /*---(complete)-----------------------*/
   return my.answer;
}

/*===============================[[ end code ]]===============================*/
