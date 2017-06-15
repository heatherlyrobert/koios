/*===============================[[ beg-code ]]===============================*/
#include    "koios.h"        /* LOCAL  : main header                          */



tVERB       g_verbs [MAX_VERB] = {
   /* --------------   ---------------------------------------   -  */
   { "PREP"         , "preparation before testing"            , '-',  0,  0 },
   { "incl"         , "c header inclusion"                    , '-',  0,  0 },
   /* --------------   --------------------------------------- */
   { "SECT"         , "grouping of scripts"                   , '-',  0,  0 },
   { "SCRP"         , "test script"                           , '-',  0,  0 },
   /* --------------   --------------------------------------- */
   { "GROUP"        , "grouping of conditions"                , '-',  0,  0 },
   { "COND"         , "test condition"                        , '-',  0,  0 },
   /* --------------   --------------------------------------- */
   { "exec"         , "function execution"                    , 'f',  0,  0 },
   { "get"          , "unit test getter call"                 , 'f',  0,  0 },
   { "set"          , "unit test setter call"                 , 'f',  0,  0 },
   { "echo"         , "test a variable directly"              , 'f',  0,  0 },
   /* --------------   --------------------------------------- */
   { "mode"         , "set pass or forced_fail mode"          , 'p',  0,  0 },
   { "code"         , "insert c code"                         , 'p',  0,  0 },
   { "load"         , "place data into stdin"                 , 'p',  0,  0 },
   { "sys"          , "execute shell code"                    , 'p',  0,  0 },
   /* --------------   --------------------------------------- */
   { "----"         , "end-of-entries"                        , '-',  0,  0 },
   /* --------------   --------------------------------------- */
};



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
      DEBUG_TOPS   yLOG_fatal   ("scrp file" , "can not open script file");
      DEBUG_TOPS   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   DEBUG_INPT   yLOG_note    ("script file open");
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
   strlcpy (my.last, my.verb, LEN_STR);
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
   int         i           = 0;
   /*---(header)-------------------------*/
   DEBUG_INPT   yLOG_enter   (__FUNCTION__);
   DEBUG_INPT   yLOG_point   ("*scrp"     , my.file_scrp);
   /*---(defense)------------------------*/
   --rce;  if (my.file_scrp == NULL) {
      DEBUG_INPT   yLOG_fatal   ("scrp file" , "file not open");
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
      ++my.n_line;
      DEBUG_INPT   yLOG_value   ("line#"     , my.n_line);
      /*---(filter)----------------------*/
      x_len = strlen (x_recd);
      x_recd [--x_len] = '\0';
      if (x_recd [0] == '#') {
         DEBUG_INPT   yLOG_note    ("comment, skipping");
         ++my.n_comment;
         continue;
      }
      if (x_recd [0] == '\0') {
         DEBUG_INPT   yLOG_note    ("empyt, skipping");
         ++my.n_empty;
         continue;
      }
      DEBUG_INPT   yLOG_value   ("length"    , x_len);
      if (x_len <= 10)  {
         DEBUG_INPT   yLOG_note    ("too short, skipping");
         ++my.n_short;
         printf ("SHORT : <<%s>>\n", x_recd);
         continue;
      }
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
      case  2 :   strncpy (my.desc      , p, LEN_STR);
                  DEBUG_INPT   yLOG_info    ("desc"      , my.desc);
                  break;
      case  3 :   if (my.spec != 'p') {
                     strncpy (my.meth      , p, LEN_STR);
                     DEBUG_INPT   yLOG_info    ("meth"      , my.meth);
                  }
                  break;
      case  4 :   if (my.spec == 'p') {
                     strncpy (my.code      , p, LEN_RECD);
                     DEBUG_INPT   yLOG_info    ("code"      , my.code);
                  } else {
                     strncpy (my.args      , p, LEN_STR);
                     strncpy (my.code      , p, LEN_STR);
                     DEBUG_INPT   yLOG_info    ("args"      , my.args);
                  }
                  break;
      case  5 :   strncpy (my.test      , p, LEN_STR);
                  DEBUG_INPT   yLOG_info    ("test"      , my.test);
                  break;
      case  6 :   strncpy (my.expe      , p, LEN_STR);
                  DEBUG_INPT   yLOG_info    ("expe"      , my.expe);
                  break;
      case  7 :   my.type      = p [0];
                  if (my.type == '\0')  my.type = '-';
                  DEBUG_INPT   yLOG_char    ("type"      , my.type);
                  break;
      case  8 :   strncpy (my.retn      , p, LEN_STR);
                  DEBUG_INPT   yLOG_info    ("retn"      , my.retn);
                  break;
      }
      /*---(stop parsing summ records)---*/
      if (i >= 3 && my.spec == '-')  break;  /* organization types  */
      if (i >= 4 && my.spec == 'p')  break;  /* code/load/sys types */
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
      case  2 :   strncpy (my.desc      , p, LEN_STR);
                  DEBUG_INPT   yLOG_info    ("desc"      , my.desc);
                  break;
      case  3 :   if (my.spec == 'p') {
                     strncpy (my.code      , p, LEN_RECD);
                     DEBUG_INPT   yLOG_info    ("code"      , my.code);
                  } else {
                     strncpy (my.meth      , p, LEN_STR);
                     DEBUG_INPT   yLOG_info    ("meth"      , my.meth);
                  }
                  break;
      case  4 :   strncpy (my.args      , p, LEN_STR);
                  strncpy (my.code      , p, LEN_STR);
                  DEBUG_INPT   yLOG_info    ("args"      , my.args);
                  break;
      case  5 :   strncpy (my.test      , p, LEN_STR);
                  DEBUG_INPT   yLOG_info    ("test"      , my.test);
                  break;
      case  6 :   strncpy (my.expe      , p, LEN_STR);
                  DEBUG_INPT   yLOG_info    ("expe"      , my.expe);
                  break;
      case  7 :   my.type      = p [0];
                  if (my.type == '\0')  my.type = '-';
                  DEBUG_INPT   yLOG_char    ("type"      , my.type);
                  break;
      case  8 :   strncpy (my.retn      , p, LEN_STR);
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
                     strncpy (my.code      , p, LEN_RECD);
                     DEBUG_INPT   yLOG_info    ("code"      , my.code);
                  } else {
                     strncpy (my.meth      , p, LEN_STR);
                     DEBUG_INPT   yLOG_info    ("meth"      , my.meth);
                  }
                  break;
      case  3 :   strncpy (my.args      , p, LEN_STR);
                  strncpy (my.code      , p, LEN_STR);
                  DEBUG_INPT   yLOG_info    ("args"      , my.args);
                  break;
      case  4 :   strncpy (my.test      , p, LEN_STR);
                  DEBUG_INPT   yLOG_info    ("test"      , my.test);
                  break;
      case  5 :   strncpy (my.expe      , p, LEN_STR);
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
   --rce;  if (my.len      <   50) {
      DEBUG_INPT   yLOG_note    ("my.len too short");
      DEBUG_INPT   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   /*---(create a copy of recd)----------*/
   DEBUG_INPT   yLOG_note    ("create a copy of source record");
   strlcpy (x_recd, my.recd, LEN_RECD);
   DEBUG_INPT   yLOG_info    ("x_recd"    , x_recd);
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
   DEBUG_INPT   yLOG_value   ("verb"      , p);
   sprintf (x_temp, " %s ", p);
   DEBUG_INPT   yLOG_note    ("search for verb");
   my.indx = -1;
   for (i = 0; i < MAX_VERB; ++i) {
      if (g_verbs [i].name [0] == '-') {
         my.indx    = i;
         ++g_verbs [i].count;
         ++g_verbs [i].total;
         printf ("VERB? : <<%s>>\n", my.recd);
         break;
      }
      if (g_verbs [i].name [0] != p[0])          continue;
      if (strcmp (g_verbs [i].name, p) != 0)     continue;
      DEBUG_INPT   yLOG_note    ("verb found, save");
      strcpy (my.verb, g_verbs [i].name);
      my.indx    = i;
      ++g_verbs [i].count;
      ++g_verbs [i].total;
      my.spec    = g_verbs [i].spec;
      break;
   }
   --rce;  if (p [0] == '#') {
      DEBUG_INPT   yLOG_note    ("comment not in column one");
      DEBUG_INPT   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   --rce;  if (my.indx == -1 || p [0] == '#') {
      DEBUG_INPT   yLOG_note    ("verb not found");
      DEBUG_INPT   yLOG_exit    (__FUNCTION__);
      printf ("VERB? : <<%s>>\n", my.recd);
      return rce;
   }
   /*---(read version)-------------------*/
   p = strtok (NULL  , q);
   --rce;  if (p == NULL) {
      DEBUG_INPT   yLOG_note    ("strtok came up empty");
      DEBUG_INPT   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   strltrim (p, ySTR_BOTH, LEN_RECD);
   if (p[0] == '-')  p[0] = '\0';
   if      (strcmp (p, "v21") == 0) {
      strncpy (my.vers      , p    , LEN_STR);
      DEBUG_INPT   yLOG_info    ("vers"      , my.vers);
      SCRP_vers21  ();
   }
   else if (strcmp (p, "v20") == 0) {
      strncpy (my.vers      , p    , LEN_STR);
      DEBUG_INPT   yLOG_info    ("vers"      , my.vers);
      SCRP_vers20  ();
   }
   else                             {
      strncpy (my.vers      , "v19", LEN_STR);
      DEBUG_INPT   yLOG_info    ("vers"      , my.vers);
      strncpy (my.desc      , p    , LEN_STR);
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
   rc = fclose (my.file_scrp);
   --rce;  if (rc != 0) {
      return rce;
   }
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
   fprintf (my.file_code, "\n\n\n");
   fprintf (my.file_code, "char\n");
   fprintf (my.file_code, "stats ()\n");
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
/*===----                    unit testing accessor                     ----===*/
/*====================------------------------------------====================*/
static void      o___UNITTEST________________o (void) {;}

/*> char             /+ [------] unit test setter --------------------------------+/   <* 
 *> SCRP_setter        (char *a_variable, char *a_value)                               <* 
 *> {                                                                                  <* 
 *> }                                                                                  <*/

/*> char*            /+ [------] unit test accessor ------------------------------+/                                             <* 
 *> SCRP_getter        (char *a_question, int a_num)                                                                             <* 
 *> {                                                                                                                            <* 
 *>    /+---(prepare)------------------------+/                                                                                  <* 
 *>    strlcpy  (my.answer, "SCRP_unit        : question not understood", LEN_UNIT);                                             <* 
 *>    /+---(fields)-------------------------+/                                                                                  <* 
 *>    if        (strncmp (a_question, "record"         , 20)   == 0) {                                                          <* 
 *>       snprintf (my.answer, LEN_UNIT, "SCRP_record      : %3d:%.35s"     , my.len                , my.recd      );            <* 
 *>    } else if (strncmp (a_question, "verb"           , 20)   == 0) {                                                          <* 
 *>       snprintf (my.answer, LEN_UNIT, "SCRP_verb        : %3d:%.35s (%c)", strlen (my.verb      ), my.verb      , my.abbr);   <* 
 *>    } else if (strncmp (a_question, "desc"           , 20)   == 0) {                                                          <* 
 *>       snprintf (my.answer, LEN_UNIT, "SCRP_desc        : %3d:%.35s"     , strlen (my.desc      ), my.desc      );            <* 
 *>    } else if (strncmp (a_question, "machine"        , 20)   == 0) {                                                          <* 
 *>       snprintf (my.answer, LEN_UNIT, "SCRP_machine     : %3d:%.35s"     , strlen (my.machine   ), my.machine   );            <* 
 *>    } else if (strncmp (a_question, "target"         , 20)   == 0) {                                                          <* 
 *>       snprintf (my.answer, LEN_UNIT, "SCRP_target      : %3d:%.35s"     , strlen (my.target    ), my.target    );            <* 
 *>    } else if (strncmp (a_question, "importance"     , 20)   == 0) {                                                          <* 
 *>       snprintf (my.answer, LEN_UNIT, "SCRP_importance  : %3d:%.35s"     , strlen (my.importance), my.importance);            <* 
 *>    } else if (strncmp (a_question, "users"          , 20)   == 0) {                                                          <* 
 *>       snprintf (my.answer, LEN_UNIT, "SCRP_users       : %3d:%.35s"     , strlen (my.users     ), my.users     );            <* 
 *>    } else if (strncmp (a_question, "own"            , 20)   == 0) {                                                          <* 
 *>       snprintf (my.answer, LEN_UNIT, "SCRP_own         : %3d:%.35s"     , strlen (my.own       ), my.own       );            <* 
 *>    } else if (strncmp (a_question, "grp"            , 20)   == 0) {                                                          <* 
 *>       snprintf (my.answer, LEN_UNIT, "SCRP_grp         : %3d:%.35s"     , strlen (my.grp       ), my.grp       );            <* 
 *>    } else if (strncmp (a_question, "perms"          , 20)   == 0) {                                                          <* 
 *>       snprintf (my.answer, LEN_UNIT, "SCRP_perms       : %3d:%.35s"     , strlen (my.perms     ), my.perms     );            <* 
 *>    } else if (strncmp (a_question, "test"           , 20)   == 0) {                                                          <* 
 *>       snprintf (my.answer, LEN_UNIT, "SCRP_test        : %3d:%.35s"     , strlen (my.test      ), my.test      );            <* 
 *>    } else if (strncmp (a_question, "source"         , 20)   == 0) {                                                          <* 
 *>       snprintf (my.answer, LEN_UNIT, "SCRP_source      : %3d:%.35s"     , strlen (my.source    ), my.source    );            <* 
 *>    }                                                                                                                         <* 
 *>    /+---(complete)-----------------------+/                                                                                  <* 
 *>    return my.answer;                                                                                                         <* 
 *> }                                                                                                                            <*/

/*===============================[[ end code ]]===============================*/
