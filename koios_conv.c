/*===============================[[ beg-code ]]===============================*/
#include    "koios.h"        /* LOCAL  : main header                          */


static char s_shared      = '-';         /* flag for shared code or not    */


/*====================------------------------------------====================*/
/*===----                       general functions                      ----===*/
/*====================------------------------------------====================*/
static void  o___OVERALL_________o () { return; }

char         /*--> open output script file ---------------[ leaf   [ ------ ]-*/
CONV_open          (void)
{
   /*---(locals)-----------+-----------+-*/
   char        rce         = -10;           /* return code for errors         */
   /*---(header)-------------------------*/
   DEBUG_TOPS   yLOG_enter   (__FUNCTION__);
   /*---(open configuration)-------------*/
   DEBUG_OUTP   yLOG_point   ("name"      , my.name_conv);
   my.file_conv = fopen (my.name_conv, "w");
   DEBUG_OUTP   yLOG_point   ("file*"     , my.file_conv);
   --rce;  if (my.file_conv == NULL) {
      DEBUG_TOPS   yLOG_fatal   ("scrp file, can not open output script file");
      DEBUG_TOPS   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   DEBUG_OUTP   yLOG_note    ("output script file open");
   /*---(complete)-----------------------*/
   DEBUG_TOPS   yLOG_exit    (__FUNCTION__);
   return 0;
}

char
CONV_begin         (void)
{
   fprintf (my.file_conv, "#!/usr/local/bin/koios\n");
   fprintf (my.file_conv, "#   koios-polos (north star) -- customized c unit testing meta-program and mini-language\n");
   fprintf (my.file_conv, "#   program under test  : %s\n", my.name_base);
   fprintf (my.file_conv, "#   auto-generated script file converted from a previous script version\n");
   my.nscrp = my.cscrp = 0;
   my.ncond = my.ccond = 0;
   my.nstep = my.cstep = 0;
   return 0;
}

char
CONV_end           (void)
{
   fprintf (my.file_conv, "\n\n\n");
   fprintf (my.file_conv, "# end-of-file\n");
   return 0;
}

char         /*--> close output script file --------------[ ------ [ ------ ]-*/
CONV_close         (void)
{
   /*---(locals)-----------+-----------+-*/
   char        rc          = 0;
   char        rce         = -10;
   /*---(header)-------------------------*/
   DEBUG_TOPS   yLOG_enter   (__FUNCTION__);
   /*---(close detail report)------------*/
   DEBUG_OUTP   yLOG_point   ("*file_conv", my.file_conv);
   --rce;  if (my.file_conv == NULL) {
      DEBUG_TOPS   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   rc = fclose (my.file_conv);
   --rce;  if (rc != 0) {
      DEBUG_TOPS   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   my.file_conv = NULL;
   /*---(complete)-----------------------*/
   DEBUG_TOPS   yLOG_exit    (__FUNCTION__);
   return 0;
}

char
CONV_header        (void)
{
   /*---(output)-------------------------*/
   fprintf (my.file_conv, "\n\n\n");
   fprintf (my.file_conv, "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  -  123456789-123456789- \n");
   fprintf (my.file_conv, "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  t  ========(var)======= \n");
   return 0;
}

char
CONV_prep          (void)
{
   CONV_header ();
   sprintf (my.updated  , "PREP          %-65.65s  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ", my.desc);
   fprintf (my.file_conv, "%s\n", my.updated);
   return 0;
}

char
CONV_incl          (void)
{
   sprintf (my.updated  , "   incl       %-35.35s  %-26.26s  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ", my.desc, my.meth);
   fprintf (my.file_conv, "%s\n", my.updated);
   return 0;
}

char
CONV_comment       (void)
{
   sprintf (my.updated  , "%s", my.recd);
   fprintf (my.file_conv, "%s\n", my.updated);
   return 0;
}



/*====================------------------------------------====================*/
/*===----                        script level                          ----===*/
/*====================------------------------------------====================*/
static void  o___SCRIPT__________o () { return; }

char         /*--> write a script entry ------------------[--------[--------]-*/
CONV_scrp          (void)
{
   /*---(counters)-----------------------*/
   ++(my.nscrp);
   my.ncond = 0;
   s_shared = '-';
   /*---(output)-------------------------*/
   CONV_header ();
   sprintf (my.updated  , "SCRP    %-4.4s  %-65.65s  %-100.100s  ((%02d.---))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ", my.stage, my.desc, my.meth, my.nscrp);
   fprintf (my.file_conv, "%s\n", my.updated);
   /*---(complete)-----------------------*/
   return 0;
}

char         /*--> write a section entry -----------------[--------[--------]-*/
CONV_sect          (void)
{
   /*---(counters)-----------------------*/
   my.ncond = 0;
   s_shared = '-';
   /*---(output)-------------------------*/
   CONV_header ();
   sprintf (my.updated  , "SECT          %-65.65s  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ", my.desc);
   fprintf (my.file_conv, "%s\n", my.updated);
   /*---(complete)-----------------------*/
   return 0;
}

char         /*-> write a shared entry -----------------[ ------ [----------]-*/
CONV_shared        (void)
{
   /*---(counters)-----------------------*/
   my.ncond = 0;
   s_shared = my.desc [1];
   /*---(output)-------------------------*/
   CONV_header ();
   sprintf (my.updated  , "SHARED        %-65.65s  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((%c%c.---))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ", my.desc, s_shared, s_shared);
   fprintf (my.file_conv, "%s\n", my.updated);
   /*---(complete)-----------------------*/
   return 0;
}



/*====================------------------------------------====================*/
/*===----                      condition level                         ----===*/
/*====================------------------------------------====================*/
static void  o___CONDITION_______o () { return; }

char         /*--> write a group entry -------------------[--------[--------]-*/
CONV_group         (void)
{
   /*---(output)-------------------------*/
   fprintf (my.file_conv, "\n");
   sprintf (my.updated  , "   GROUP      %-65.65s  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ", my.desc);
   fprintf (my.file_conv, "%s\n", my.updated);
   /*---(complete)-----------------------*/
   return 0;
}

char         /*--> write a condition entry ---------------[--------[--------]-*/
CONV_cond          (void)
{
   char        t           [LEN_RECD ] = "   ";
   /*---(counters)-----------------------*/
   ++(my.ncond);
   /*---(output)-------------------------*/
   fprintf (my.file_conv, "\n");
   if (my.mark != '-')   sprintf (t, "(%c)", my.mark);
   if (s_shared == '-') {
      sprintf (my.updated  , "   COND %3s   %-65.65s  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((%02d.%03d))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ", t, my.desc, my.nscrp, my.ncond);
   } else {
      sprintf (my.updated  , "   COND %3s   %-65.65s  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((%c%c.%03d))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ", t, my.desc, s_shared, s_shared, my.ncond);
   }
   fprintf (my.file_conv, "%s\n", my.updated);
   /*---(complete)-----------------------*/
   return 0;
}

char         /*--> write a ditto entry -------------------[--------[--------]-*/
CONV_ditto         (void)
{
   /*---(counters)-----------------------*/
   ++(my.ncond);
   /*---(output)-------------------------*/
   fprintf (my.file_conv, "\n");
   if (s_shared == '-') {
   sprintf (my.updated  , "   DITTO (%c)  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((%02d.%03d))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ", my.mark, my.nscrp, my.ncond);
   } else {
   sprintf (my.updated  , "   DITTO (%c)  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((%c%c.%03d))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ", my.mark, s_shared, s_shared, my.ncond);
   }
   fprintf (my.file_conv, "%s\n", my.updated);
   return 0;
}

char         /*--> write a condition entry ---------------[--------[--------]-*/
CONV_use           (void)
{
   /*---(output)-------------------------*/
   fprintf (my.file_conv, "\n");
   sprintf (my.updated  , "   USE_SHARE  %c  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ", my.desc [0]);
   fprintf (my.file_conv, "%s\n", my.updated);
   /*---(complete)-----------------------*/
   return 0;
}



/*====================------------------------------------====================*/
/*===----                         step level                           ----===*/
/*====================------------------------------------====================*/
static void  o___STEPS___________o () { return; }

char
CONV_exec          (void)
{
   char        t           [LEN_RECD ] = "";
   sprintf (my.updated  , "     %-4.4s     %-35.35s  %-26.26s  %-100s  %-10.10s  %-100s ", my.verb, my.desc, my.meth, my.args, my.test, my.expe);
   if (strcmp (my.retn, "") != 0) {
      sprintf (t           , " %c  %-20s ", my.type, my.retn); 
      strlcat (my.updated, t, LEN_RECD);
   }
   fprintf (my.file_conv, "%s\n", my.updated);
   return 0;
}

char
CONV_load          (void)
{
   sprintf (my.updated  , "     %-4.4s     %-35.35s  %-26.26s  %-218s ", my.verb, my.desc, my.meth, my.code);
   fprintf (my.file_conv, "%s\n", my.updated);
   return 0;
}

char
CONV_code          (void)
{
   sprintf (my.updated  , "     %-4.4s     %-35.35s  - - - - - - - - - - - - -   %-218s ", my.verb, my.desc, my.code);
   fprintf (my.file_conv, "%s\n", my.updated);
   return 0;
}

char
CONV_echo          (void)
{
   sprintf (my.updated  , "     %-4.4s     %-35.35s  - - - - - - - - - - - - -   %-100s  %-10.10s  %-100s ", my.verb, my.desc, my.args, my.test, my.expe);
   fprintf (my.file_conv, "%s\n", my.updated);
   return 0;
}



/*====================------------------------------------====================*/
/*===----                          main driver                         ----===*/
/*====================------------------------------------====================*/
static void  o___DRIVER__________o () { return; }

char
CONV_write         (void)
{
   DEBUG_TOPS   yLOG_enter   (__FUNCTION__);
   switch (my.verb [0]) {
   case 'P'  :  if      (strcmp (my.verb, "PREP"     ) == 0) {
                   CONV_prep   ();
                }
                break;
   case 'i'  :  if      (strcmp (my.verb, "incl"     ) == 0) {
                   CONV_incl   ();
                }
                break;
   case 'S'  :  if      (strcmp (my.verb, "SCRP"     ) == 0) {
                   CONV_scrp   ();
                }
                else if (strcmp (my.verb, "SECT"     ) == 0) {
                   CONV_sect   ();
                }
                else if (strcmp (my.verb, "SHARED"   ) == 0) {
                   CONV_shared ();
                }
                break;
   case 'G'  :  if      (strcmp (my.verb, "GROUP"    ) == 0) {
                   CONV_group  ();
                }
                break;
   case 'C'  :  if      (strcmp (my.verb, "COND"     ) == 0) {
                   CONV_cond   ();
                }
                break;
   case 'D'  :  if      (strcmp (my.verb, "DITTO"    ) == 0) {
                   CONV_ditto  ();
                }
                break;
   case 'U'  :  if      (strcmp (my.verb, "USE_SHARE") == 0) {
                   CONV_use    ();
                }
                break;
   case 'e'  :  if      (strcmp (my.verb, "exec"     ) == 0) {
                   CONV_exec   ();
                }
                else if (strcmp (my.verb, "echo"     ) == 0) {
                   CONV_echo   ();
                }
                break;
   case 'g'  :  if      (strcmp (my.verb, "get"      ) == 0) {
                   CONV_exec   ();
                }
                break;
   case 'c'  :  if      (strcmp (my.verb, "code"     ) == 0) {
                   CONV_code   ();
                }
                break;
   case 'l'  :  if      (strcmp (my.verb, "load"     ) == 0) {
                   CONV_load   ();
                }
                break;
   case 's'  :  if      (strcmp (my.verb, "sys"      ) == 0) {
                   CONV_code   ();
                }
                break;
   case 'm'  :  if      (strcmp (my.verb, "mode"     ) == 0) {
                   CONV_code   ();
                }
                break;
   case '#'  :  CONV_comment ();
                break;
   }
   /*---(complete)-----------------------*/
   DEBUG_TOPS   yLOG_exit    (__FUNCTION__);
   return 0;
}



/*====================------------------------------------====================*/
/*===----                         unit testing                         ----===*/
/*====================------------------------------------====================*/
static void      o___UNITTEST________________o (void) {;};

char*      /*----: unit testing accessor for clean validation interface ------*/
CONV__unit              (char *a_question, int a_num)
{
   /*---(locals)-----------+-----+-----+-*/
   int         i           =    0;
   char        t           [LEN_RECD ];
   /*---(preprare)-----------------------*/
   strlcpy  (my.answer, "CONV unit      : question not understood", LEN_STR);
   if      (strcmp (a_question, "file"      ) == 0) {
      sprintf (my.answer, "CONV file      : %-35.35s %p", my.name_conv, my.file_conv);
   }
   else if (strcmp (a_question, "recd"      ) == 0) {
      strlcpy    (t, my.updated, LEN_RECD);
      strlencode (t, ySTR_NONE, LEN_RECD);
      sprintf (my.answer, "CONV recd      : %3d[%s]", strlen (t), t);
   }
   /*---(complete)-----------------------*/
   return my.answer;
}


/*===============================[[ end code ]]===============================*/
