/*===============================[[ beg-code ]]===============================*/
#include    "koios.h"        /* LOCAL  : main header                          */



static  char  s_ditto    = '-';
static  char  s_dittoing = '-';
static  FILE *s_file_save;
static  FILE *s_file_ditto;
static  int   s_lineno   =   0;


tVERB       g_verbs [MAX_VERB] = {
   /* --------------   ---------------------------------------   -  */
   { "PREP"         , "preparation before testing"            , '-',  0,  0 },
   { "incl"         , "c header inclusion"                    , '-',  0,  0 },
   { "#>"           , "script internal comments"              , 'c',  0,  0 },
   /* --------------   --------------------------------------- */
   { "SECT"         , "grouping of scripts"                   , '-',  0,  0 },
   { "SCRP"         , "test script"                           , '-',  0,  0 },
   { "SHARED"       , "shared code between scripts"           , '-',  0,  0 },
   /* --------------   --------------------------------------- */
   { "GROUP"        , "grouping of conditions"                , '-',  0,  0 },
   { "COND"         , "test condition"                        , '-',  0,  0 },
   { "DITTO"        , "repeated test condition"               , '-',  0,  0 },
   { "USE_SHARE"    , "inclusion of shared code"              , '-',  0,  0 },
   /* --------------   --------------------------------------- */
   { "exec"         , "function execution"                    , 'f',  0,  0 },
   { "get"          , "unit test getter call"                 , 'f',  0,  0 },
   { "set"          , "unit test setter call"                 , 'f',  0,  0 },
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
SCRP_ditto_beg     (char a_mark)
{
   /*---(locals)-----------+-----------+-*/
   char        rce         = -10;           /* return code for errors         */
   /*---(header)-------------------------*/
   DEBUG_INPT   yLOG_enter   (__FUNCTION__);
   /*---(save mark)----------------------*/
   s_ditto      = a_mark;
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
   /*---(complete)-----------------------*/
   DEBUG_INPT   yLOG_exit    (__FUNCTION__);
   return 0;
}

char
SCRP_ditto_check   (char *a_recd)
{
   /*---(locals)-----------+-----------+-*/
   char        rce         =  -10;
   char       *p           = NULL;
   /*---(header)-------------------------*/
   DEBUG_INPT   yLOG_senter  (__FUNCTION__);
   /*---(find cond lines)----------------*/
   p = strstr (a_recd, "COND (");
   DEBUG_INPT   yLOG_spoint  (p);
   --rce;  if (p == NULL) {
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_INPT   yLOG_sint    (p - a_recd);
   --rce;  if (p - a_recd > 5) {
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(find our cond)------------------*/
   DEBUG_INPT   yLOG_schar   (s_ditto);
   DEBUG_INPT   yLOG_schar   (p [6]);
   --rce;  if (p [6] != s_ditto) {
      DEBUG_INPT   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(complete)-----------------------*/
   DEBUG_INPT   yLOG_sexit   (__FUNCTION__);
   return 1;
}

char
SCRP_ditto_end     (void)
{
   /*---(locals)-----------+-----------+-*/
   char        rce         =  -10;
   char        rc          =    0;
   /*---(header)-------------------------*/
   DEBUG_INPT   yLOG_enter   (__FUNCTION__);
   /*---(reset ditto)--------------------*/
   s_ditto = '-';
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
      if (s_ditto == '-') ++my.n_line;
      else                ++s_lineno;
      DEBUG_INPT   yLOG_value   ("line#"     , my.n_line);
      /*---(filter)----------------------*/
      x_len = strllen (x_recd, LEN_RECD);
      x_recd [--x_len] = '\0';
      if (x_recd [0] == '\0') {
         DEBUG_INPT   yLOG_note    ("empty, skipping");
         if (s_ditto != '-')  SCRP_ditto_end ();
         else                 ++my.n_empty;
         continue;
      }
      if (x_recd [0] == '#' && x_recd [1] != '>') {
         DEBUG_INPT   yLOG_note    ("comment, skipping");
         if (s_ditto != '-')  SCRP_ditto_end ();
         else                 ++my.n_comment;
         continue;
      }
      DEBUG_INPT   yLOG_value   ("length"    , x_len);
      if (x_len <= 10)  {
         DEBUG_INPT   yLOG_note    ("too short, skipping");
         if (s_ditto != '-')  SCRP_ditto_end ();
         else                 ++my.n_short;
         continue;
      }
      /*---(handle ditto)----------------*/
      if (s_ditto != '-' && s_dittoing == '-') {
         rc = SCRP_ditto_check (x_recd);
         if (rc < 1)  continue;
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
   --rce;  if (my.recd [0] == '\0') {
      DEBUG_INPT   yLOG_note    ("NULL record in my.recd");
      DEBUG_INPT   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   DEBUG_INPT   yLOG_info    ("record"    , my.recd);
   DEBUG_INPT   yLOG_value   ("length"    , my.len);
   --rce;  if (my.len < 50 && my.recd [0] != '#') {
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
         my.indx    = i;
         ++g_verbs [i].count;
         ++g_verbs [i].total;
         printf ("VERB? : %s <<%s>>\n", p, my.recd);
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
      printf ("VERB? : %s <<%s>>\n", p, my.recd);
      return rce;
   }
   /*---(check for ditto)----------------*/
   --rce;  if (strcmp ("DITTO", g_verbs [i].name) == 0) {
      DEBUG_INPT   yLOG_note    ("found a ditto condition");
      x_len = strlen (p);
      if (p != 9) {
         DEBUG_INPT   yLOG_exitr   (__FUNCTION__, rce);
         return rce;
      }
      SCRP_ditto_beg (p [7]);
      DEBUG_INPT   yLOG_exit    (__FUNCTION__);
      return 0;
   }
   /*---(read version)-------------------*/
   p = strtok (NULL  , q);
   --rce;  if (p == NULL && my.spec != 'c') {
      DEBUG_INPT   yLOG_note    ("strtok came up empty");
      DEBUG_INPT   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   strltrim (p, ySTR_BOTH, LEN_RECD);
   if (p[0] == '-')  p[0] = '\0';
   if      (strcmp (p, "v21") == 0) {
      strlcpy (my.vers      , p    , LEN_LABEL);
      DEBUG_INPT   yLOG_info    ("vers"      , my.vers);
      if (my.spec != 'c')  SCRP_vers21  ();
   }
   else if (strcmp (p, "v20") == 0) {
      strlcpy (my.vers      , p    , LEN_LABEL);
      DEBUG_INPT   yLOG_info    ("vers"      , my.vers);
      SCRP_vers20  ();
   }
   else                             {
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
      sprintf (my.answer, "SCRP verb      : %-10.10s/%.30s", my.verb, my.desc);
   }
   else if (strcmp (a_question, "call"      ) == 0) {
      sprintf (my.answer, "SCRP call      : %-20.20s (%.20s)", my.meth, my.args);
   }
   else if (strcmp (a_question, "test"      ) == 0) {
      sprintf (my.answer, "SCRP test      : %-10.10s/%.30s", my.test, my.retn);
   }
   else if (strcmp (a_question, "retn"      ) == 0) {
      sprintf (my.answer, "SCRP retn      : %c         /%.30s", my.type, my.retn);
   }
   else if (strcmp (a_question, "code"      ) == 0) {
      strlcpy    (t, my.code, LEN_RECD);
      strlencode (t, ySTR_NONE, LEN_RECD);
      sprintf (my.answer, "SCRP code      : %3d[%.40s]", strlen (t), t);
   }
   /*---(complete)-----------------------*/
   return my.answer;
}

/*===============================[[ end code ]]===============================*/
