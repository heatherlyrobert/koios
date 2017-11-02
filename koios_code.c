/*===============================[[ beg-code ]]===============================*/
#include    "koios.h"        /* LOCAL  : main header                          */


tTEST       g_tests [MAX_TEST] = {
   /*---- ----- --------------------- --------------------- ----------------------------------------- */
   { 'v' , 'v' , "void (pure)"       , "yUNIT_void      (" , "no return at all, not even void*"       },
   { 's' , 's' , "string (pure)"     , "yUNIT_string    (" , "literal string comparison, char-by-char"},
   { 'i' , 'i' , "integer"           , "yUNIT_int       (" , ""                                       },
   { '-' , '-' , "end-of-tests"      , ""                  , ""                                       },
   /*---- ----- --------------------- --------------------- ----------------------------------------- */
};



char        CODE_cond_end      (void);

char        s_shared      = '-';         /* flag for shared code or not    */
int         s_share_cnt   [26];          /* count of cond in each share    */

/*====================------------------------------------====================*/
/*===----                       general functions                      ----===*/
/*====================------------------------------------====================*/
static void  o___OVERALL_________o () { return; }

char         /*--> open code file ------------------------[ leaf   [ ------ ]-*/
CODE_open          (void)
{
   /*---(locals)-----------+-----------+-*/
   char        rce         = -10;           /* return code for errors         */
   /*---(header)-------------------------*/
   DEBUG_TOPS   yLOG_enter   (__FUNCTION__);
   /*---(open output file)---------------*/
   DEBUG_OUTP   yLOG_point   ("name"      , my.name_code);
   my.file_code = fopen (my.name_code, "w");
   DEBUG_OUTP   yLOG_point   ("file*"     , my.file_code);
   --rce;  if (my.file_code == NULL) {
      DEBUG_TOPS   yLOG_fatal   ("scrp file" , "can not open script file");
      DEBUG_TOPS   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   DEBUG_OUTP   yLOG_note    ("script file open");
   /*---(open main file)-----------------*/
   DEBUG_OUTP   yLOG_point   ("main"      , my.name_main);
   my.file_main = fopen (my.name_main, "w");
   DEBUG_OUTP   yLOG_point   ("file*"     , my.file_main);
   --rce;  if (my.file_main == NULL) {
      DEBUG_TOPS   yLOG_fatal   ("scrp file" , "can not open main file");
      DEBUG_TOPS   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   DEBUG_OUTP   yLOG_note    ("script file open");
   /*---(complete)-----------------------*/
   DEBUG_TOPS   yLOG_exit    (__FUNCTION__);
   return 0;
}

char         /*--> close code file -----------------------[ ------ [ ------ ]-*/
CODE_close         (void)
{
   /*---(locals)-----------+-----------+-*/
   char        rc          = 0;
   char        rce         = -10;
   /*---(header)-------------------------*/
   DEBUG_TOPS   yLOG_enter   (__FUNCTION__);
   /*---(close detail report)------------*/
   DEBUG_OUTP   yLOG_point   ("*file_code", my.file_code);
   rc = fclose (my.file_code);
   --rce;  if (rc != 0) {
      return rce;
   }
   /*---(terminate logging)--------------*/
   DEBUG_TOPS   yLOG_exit    (__FUNCTION__);
   /*---(complete)-----------------------*/
   return 0;
}

char
CODE_begin         (void)
{
   int         i           = 0;
   /*---(create header)------------------*/
   fprintf (my.file_code, "/*============================================================================*/\n");
   fprintf (my.file_code, "/*=========================== beginning-of-file ==============================*/\n");
   fprintf (my.file_code, "/*============================================================================*/\n");
   fprintf (my.file_code, "\n");
   fprintf (my.file_code, "\n");
   fprintf (my.file_code, "\n");
   fprintf (my.file_code, "/*==========================---------------------=============================*/\n");
   fprintf (my.file_code, "/*===----                  unit testing preparation                    ----===*/\n");
   fprintf (my.file_code, "/*==========================---------------------=============================*/\n");
   fprintf (my.file_code, "\n\n\n");
   fprintf (my.file_code, "/*---(standard headers)---------------*/\n");
   fprintf (my.file_code, "#include    <stdio.h>\n");
   fprintf (my.file_code, "#include    <string.h>\n");
   fprintf (my.file_code, "#include    <stdlib.h>                   /* exit,atoi                                */\n");
   fprintf (my.file_code, "#include    <unistd.h>                   /* sleep                                    */\n");
   fprintf (my.file_code, "/*---(custom headers)-----------------*/\n");
   fprintf (my.file_code, "#include    <yUNIT.h>                    /* unit testing functions                   */\n");
   fprintf (my.file_code, "#include    <yVAR.h>                     /* complex comparison functions             */\n");
   fprintf (my.file_code, "\n\n\n");
   fprintf (my.file_code, "/*---(globals)----------+-----+-----+-*/\n");
   fprintf (my.file_code, "void       *my_unit     = NULL;          /* set up for the unit test                 */\n");
   fprintf (my.file_code, "char        eterm       =  'y';          /* handle console vs eterm                  */\n");
   fprintf (my.file_code, "int         g_noisy     =    0;          /* how loud things should be                */\n");
   fprintf (my.file_code, "int         g_exec      =    1;          /* run scripts                              */\n");
   fprintf (my.file_code, "int         g_scrp      =    0;          /* script selected for focus                */\n");
   fprintf (my.file_code, "int         g_cond      =    0;          /* condition selected for focus             */\n");
   fprintf (my.file_code, "int         g_offset    =    0;          /* shared code condition offset             */\n");
   fprintf (my.file_code, "char        g_debug     [100];           /* display debugging info                   */\n");
   fprintf (my.file_code, "char        CUSTOM      [2000];          /* holder for custom expect strings         */\n");
   fprintf (my.file_code, "\n\n\n");
   fprintf (my.file_code, "/*---(prototypes)---------------------*/\n");
   fprintf (my.file_code, "char        UNIT_usage        (void);\n");
   fprintf (my.file_code, "char        UNIT_args         (int   a_argc, char *a_argv[]);\n");
   fprintf (my.file_code, "char        UNIT_stats        (void);\n");
   fprintf (my.file_code, "\n\n\n");
   /*---(initialize variables)-----------*/
   my.nscrp  = my.cscrp = 0;
   my.ncond  = my.ccond = 0;
   my.nstep  = my.cstep = 0;
   s_shared = '-';
   for (i = 0; i < 26; ++i)  s_share_cnt [i] = 0;
   /*---(open main function)-------------*/
   fprintf (my.file_main, "int\n");
   fprintf (my.file_main, "main (int a_argc, char *a_argv[])\n");
   fprintf (my.file_main, "{\n");
   fprintf (my.file_main, "   /*---(locals)-----------+-----+-----+-*/\n");
   fprintf (my.file_main, "   int         rc          =    0;     /* generic return code     */\n");
   fprintf (my.file_main, "   /*---(prepare)------------------------*/\n");
   fprintf (my.file_main, "   rc = UNIT_args (a_argc, a_argv);\n");
   fprintf (my.file_main, "   if (rc < 0)  return -1;\n");
   fprintf (my.file_main, "   my_unit = yUNIT_unit(\"MyTest\", g_noisy, eterm);\n");
   fprintf (my.file_main, "   /*---(scripts)------------------------*/\n");
   return 0;
}

char
CODE_main          (void)
{
   /*---(locals)-----------+-----+-----+-*/
   if (my.driver == 'y')  return 0;
   fprintf (my.file_code, "\n\n");
   fprintf (my.file_code, "char\n");
   fprintf (my.file_code, "UNIT_usage (void)\n");
   fprintf (my.file_code, "{\n");
   fprintf (my.file_code, "   printf(\"yUNIT -- heatherly unit testing framework\\n\");\n");
   fprintf (my.file_code, "   printf(\"   #---(scope)--------------------#\\n\");\n");
   fprintf (my.file_code, "   printf(\"   --all         = run all scripts and conditions\\n\");\n");
   fprintf (my.file_code, "   printf(\"   <nn>          = only run script <nn>\\n\");\n");
   fprintf (my.file_code, "   printf(\"   <nn>.<nnn>    = only show detail on condition <nnn>\\n\");\n");
   fprintf (my.file_code, "   printf(\"   #---(verbosity)----------------#\\n\");\n");
   fprintf (my.file_code, "   printf(\"   --quiet       = just returns a rc\\n\");\n");
   fprintf (my.file_code, "   printf(\"   --show-none   = just returns a rc\\n\");\n");
   fprintf (my.file_code, "   printf(\"   --show-test   = one line of summary statistics\\n\");\n");
   fprintf (my.file_code, "   printf(\"   --show-scrp   = script level statistics only\\n\");\n");
   fprintf (my.file_code, "   printf(\"   --show-cond   = condition level statistics only\\n\");\n");
   fprintf (my.file_code, "   printf(\"   --show-step   = step header level statistics only\\n\");\n");
   fprintf (my.file_code, "   printf(\"   --show-full   = full detail\\n\");\n");
   fprintf (my.file_code, "   printf(\"   --loud        = full detail\\n\");\n");
   fprintf (my.file_code, "   printf(\"   #---(information)--------------#\\n\");\n");
   fprintf (my.file_code, "   printf(\"   --list-scrp   = script level statistics only\\n\");\n");
   fprintf (my.file_code, "   printf(\"   --list-cond   = condition level statistics only\\n\");\n");
   fprintf (my.file_code, "   printf(\"   --list-step   = step header level statistics only\\n\");\n");
   fprintf (my.file_code, "   printf(\"   --list-stats  = display conversion statistics\\n\");\n");
   fprintf (my.file_code, "   printf(\"   #---(color)--------------------#\\n\");\n");
   fprintf (my.file_code, "   printf(\"   --console     = no terminal color codes\\n\");\n");
   fprintf (my.file_code, "   printf(\"   --eterm       = add terminal color codes\\n\");\n");
   fprintf (my.file_code, "   printf(\"   #---(other)--------------------#\\n\");\n");
   fprintf (my.file_code, "   printf(\"   --help        = usage information\\n\");\n");
   fprintf (my.file_code, "   exit(0);\n");
   fprintf (my.file_code, "}\n");
   fprintf (my.file_code, "\n");
   fprintf (my.file_code, "char\n");
   fprintf (my.file_code, "UNIT_args (int argc, char *argv[])\n");
   fprintf (my.file_code, "{\n");
   fprintf (my.file_code, "   /*---(locals)-----------+-----+-----+-*/\n");
   fprintf (my.file_code, "   int         i           =    0;     /* loop iterator -- args   */\n");
   fprintf (my.file_code, "   char       *a           = NULL;     /* cli argument holder     */\n");
   fprintf (my.file_code, "   int         v           =    5;     /* verbosity level         */\n");
   fprintf (my.file_code, "   int         l           =    0;     /* length of argument      */\n");
   fprintf (my.file_code, "   int         x_bad       =    0;     /* number of bad arguments */\n");
   fprintf (my.file_code, "   char        x_temp      [10] = \"\";  /* temp string             */\n");
   fprintf (my.file_code, "   /*---(process args)-------------------*/\n");
   fprintf (my.file_code, "   for (i = 1; i < argc; ++i) {\n");
   fprintf (my.file_code, "      a = argv[i];\n");
   fprintf (my.file_code, "      l = strlen(a);\n");
   fprintf (my.file_code, "      /*---(verbosity)--------------------*/\n");
   fprintf (my.file_code, "      if      (strcmp (a, \"--quiet\"     )  == 0)      v = 0;\n");
   fprintf (my.file_code, "      else if (strcmp (a, \"--show-none\" )  == 0)      v = 0;\n");
   fprintf (my.file_code, "      else if (strcmp (a, \"--show-test\" )  == 0)      v = 1;\n");
   fprintf (my.file_code, "      else if (strcmp (a, \"--show-scrp\" )  == 0)      v = 2;\n");
   fprintf (my.file_code, "      else if (strcmp (a, \"--show-cond\" )  == 0)      v = 3;\n");
   fprintf (my.file_code, "      else if (strcmp (a, \"--show-step\" )  == 0)      v = 4;\n");
   fprintf (my.file_code, "      else if (strcmp (a, \"--show-full\" )  == 0)      v = 5;\n");
   fprintf (my.file_code, "      else if (strcmp (a, \"--loud\"      )  == 0)      v = 5;\n");
   fprintf (my.file_code, "      /*---(information)------------------*/\n");
   fprintf (my.file_code, "      else if (strcmp (a, \"--list-scrp\" )  == 0)    { g_exec = 0; v = 2; }\n");
   fprintf (my.file_code, "      else if (strcmp (a, \"--list-cond\" )  == 0)    { g_exec = 0; v = 3; }\n");
   fprintf (my.file_code, "      else if (strcmp (a, \"--list-step\" )  == 0)    { g_exec = 0; v = 4; }\n");
   fprintf (my.file_code, "      else if (strcmp (a, \"--list-stats\")  == 0)      UNIT_stats ();\n");
   fprintf (my.file_code, "      /*---(help)-------------------------*/\n");
   fprintf (my.file_code, "      else if (strcmp (a, \"--help\"      )  == 0)      UNIT_usage ();\n");
   fprintf (my.file_code, "      /*---(fomatting)--------------------*/\n");
   fprintf (my.file_code, "      else if (strcmp (a, \"--console\"   )  == 0)      eterm = '-';\n");
   fprintf (my.file_code, "      else if (strcmp (a, \"--eterm\"     )  == 0)      eterm = 'y';\n");
   fprintf (my.file_code, "      /*---(scope)------------------------*/\n");
   fprintf (my.file_code, "      else if (strcmp (a, \"--all\"       )  == 0)      { g_scrp = g_cond = 0; }\n");
   fprintf (my.file_code, "      else if (l == 2) {\n");
   fprintf (my.file_code, "          g_scrp = atoi(a);\n");
   fprintf (my.file_code, "      }\n");
   fprintf (my.file_code, "      else if (l == 6 && (a[2] == '.' || a[2] == '-'))    {\n");
   fprintf (my.file_code, "          sprintf (x_temp, \"%%c%%c\", a[0], a[1]);\n");
   fprintf (my.file_code, "          g_scrp = atoi (x_temp);\n");
   fprintf (my.file_code, "          sprintf (x_temp, \"%%c%%c%%c\", a[3], a[4], a[5]);\n");
   fprintf (my.file_code, "          g_cond = atoi (x_temp);\n");
   fprintf (my.file_code, "          v = 3;\n");
   fprintf (my.file_code, "      }\n");
   fprintf (my.file_code, "      else {\n");
   fprintf (my.file_code, "         printf(\"option not understood <<%%s>>\\n\", a);\n");
   fprintf (my.file_code, "         ++x_bad;\n");
   fprintf (my.file_code, "      }\n");
   fprintf (my.file_code, "      /*---(done)-------------------------*/\n");
   fprintf (my.file_code, "   }\n");
   fprintf (my.file_code, "   /*---(check results)------------------*/\n");
   fprintf (my.file_code, "   if (x_bad > 0) {\n");
   fprintf (my.file_code, "         printf(\"FATAL, exiting\\n\");\n");
   fprintf (my.file_code, "         exit (-1);\n");
   fprintf (my.file_code, "   }\n");
   fprintf (my.file_code, "   g_noisy = v;\n");
   fprintf (my.file_code, "   /*---(complete)-----------------------*/\n");
   fprintf (my.file_code, "   return 0;\n");
   fprintf (my.file_code, "}\n");
   fprintf (my.file_code, "\n");
   my.driver = 'y';
   return 0;
}

char
CODE_prep          (void)
{
   fprintf (my.file_code, "/*---(program headers)----------------*/\n");
   return 0;
}

char
CODE_incl          (void)
{
   fprintf (my.file_code, "#include    \"%s\"   /* %4i, %s */\n",
         my.meth, my.n_line, my.desc);
   fprintf (my.file_code, "\n");
   return 0;
}



/*====================------------------------------------====================*/
/*===----                      script level verbs                      ----===*/
/*====================------------------------------------====================*/
static void  o___SCRP____________o () { return; }

char
CODE_scrp_end        (void)
{
   /*---(close final condition)----------*/
   if (s_shared != '-' || my.cscrp >  0) {
      CODE_cond_end ();
   }
   /*---(end share)----------------------*/
   if (s_shared != '-') {
      s_share_cnt [s_shared] = my.ccond;
   }
   /*---(close script/share)-------------*/
   if (s_shared != '-' || my.cscrp >  0) {
      if (s_shared == '-') {
         fprintf (my.file_code, "   /*---(script done)---------------------*/\n");
         fprintf (my.file_code, "   if (g_exec == 1)  yUNIT_prcs    (my_unit);\n");
      }
      fprintf (my.file_code, "   /*---(complete)-----------------------*/\n");
      fprintf (my.file_code, "   return 0;\n");
      fprintf (my.file_code, "}\n");
      fprintf (my.file_code, "\n");
   }
   /*---(initialize vars)----------------*/
   s_shared = '-';
   my.ccond  = 0;
   my.cstep  = 0;
   /*---(complete)-----------------------*/
   return 0;
}

char
CODE_scrp          (void)
{
   /*---(end last script)----------------*/
   CODE_scrp_end ();
   /*---(counters)-----------------------*/
   ++(my.nscrp);
   ++(my.cscrp);
   /*---(open script function)-----------*/
   fprintf (my.file_code, "char\n");
   fprintf (my.file_code, "UNIT_script%02d (void)\n", my.cscrp);
   fprintf (my.file_code, "{\n");
   fprintf (my.file_code, "   g_offset = 0;\n");
   fprintf (my.file_code, "   yUNIT_scrp    (my_unit, %4i, %3i, \"%s\", \"%s\");\n", my.n_line, my.cscrp, my.meth, my.desc);
   fprintf (my.file_code, "\n");
   /*---(function call to main)----------*/
   fprintf (my.file_main, "   if (g_scrp ==  0 || g_scrp == %2i)  UNIT_script%02d ();\n", my.cscrp, my.cscrp);
   /*---(complete)-----------------------*/
   return 0;
}

char         /*-> common shared code between scripts ---[ ------ [----------]-*/
CODE_shared          (void)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   /*---(end last script)----------------*/
   CODE_scrp_end ();
   /*---(defense)------------------------*/
   --rce;  if (my.desc [0] != '(')  return rce;
   --rce;  if (my.desc [2] != ')')  return rce;
   --rce;  if (strchr ("ABCDEFGHIJZLMNOPQRSTUVWXYZ", my.desc [1]) == NULL)  return rce;
   /*---(counters)-----------------------*/
   s_shared = my.desc [1];
   s_share_cnt [s_shared] = 0;
   /*---(open script function)-----------*/
   fprintf (my.file_code, "char\n");
   fprintf (my.file_code, "UNIT_shared_%c (void)\n", my.desc [1]);
   fprintf (my.file_code, "{\n");
   /*---(complete)-----------------------*/
   return 0;
}

char
CODE_sect          (void)
{
   /*---(add section)--------------------*/
   fprintf (my.file_main, "   if (g_scrp ==  0)  yUNIT_sect    (my_unit, \"%s\");\n", my.desc);
   /*---(complete)-----------------------*/
   return 0;
}

char
CODE_group         (void)
{
   CODE_cond_end ();
   fprintf (my.file_code, "   /*---(group)---------------------------*/\n");
   fprintf (my.file_code, "   yUNIT_group   (my_unit, \"%s\");\n", my.desc);
   fprintf (my.file_code, "\n");
   return 0;
}



/*====================------------------------------------====================*/
/*===----                       condition level                        ----===*/
/*====================------------------------------------====================*/
static void  o___COND____________o () { return; }

char
CODE_cond_end      (void)
{
   if (strcmp (my.last, "GROUP") != 0 && strcmp (my.last, "USE_SHARE") != 0) {
      if (my.ccond > 0) {
         fprintf (my.file_code, "   if (g_exec == 1)  yUNIT_dnoc    (my_unit);\n");
         fprintf (my.file_code, "   yUNIT_noisy  (my_unit, g_noisy);\n");
      }
   }
   fprintf (my.file_code, "\n");
}

char
CODE_cond          (void)
{
   CODE_cond_end ();
   ++(my.ncond);
   ++(my.ccond);
   fprintf (my.file_code, "   /*---(cond #%03d)-----------------------*/\n", my.ccond);
   fprintf (my.file_code, "   if (g_cond == g_offset + %i) yUNIT_noisy  (my_unit, 5);\n", my.ccond);
   fprintf (my.file_code, "   %sUG_TOPS    %sOG_unitcond (%d, g_offset + %d, %d, \"%s\");\n", "DEB", "yL", my.cscrp, my.ccond, my.n_line, my.desc);
   fprintf (my.file_code, "   yUNIT_cond    (my_unit, %4i, g_offset + %3i, \"%s\");\n", my.n_line, my.ccond, my.desc);
   my.cstep = 0;
   return 0;
}

char
CODE_use           (void)
{
   char        rce         =  -10;
   CODE_cond_end ();
   --rce;  if (strchr ("ABCDEFGHIJZLMNOPQRSTUVWXYZ", my.desc [0]) == NULL)  return rce;
   fprintf (my.file_code, "   g_offset = %d;\n", my.ccond);
   fprintf (my.file_code, "   UNIT_shared_%c ();\n", my.desc [0]);
   fprintf (my.file_code, "   g_offset = 0;\n");
   my.ncond += s_share_cnt [my.desc [0]];
   my.ccond += s_share_cnt [my.desc [0]];
   return 0;
}



/*====================------------------------------------====================*/
/*===----                       step level verbs                       ----===*/
/*====================------------------------------------====================*/
static void  o___STEP____________o () { return; }

char
CODE_mode          (void)
{
   ++(my.nstep);
   ++(my.cstep);
   fprintf (my.file_code, "      /*---(mode)-------------------------*/\n");
   fprintf (my.file_code, "      if (g_exec == 1)  yUNIT_mode    (my_unit, %4i, %3i, %s);\n", my.n_line, my.cstep, my.args);
   return 0;
}

char
CODE_display       (void)
{
   /*---(locals)-----------+-----------+-*/
   int         i           = 0;
   int         x_len       = 0;
   char        t           [10]        = "";
   /*---(fix delimiters)-----------------*/
   printf ("CODE_display ------------------------------\n");
   printf ("my.code <<%s>>\n", my.code);
   x_len = strlen (my.code);
   printf ("length  %d\n", x_len);
   /*---(prepare)------------------------*/
   x_len = strlen (my.code);
   printf ("length  %d\n", x_len);
   strlcpy (my.disp, my.code , LEN_RECD);
   strlcpy (my.syst, ""     , LEN_RECD);
   strlcpy (my.load, ""     , LEN_RECD);
   /*---(cleanse)------------------------*/
   for (i = 0; i < x_len; ++i) {
      switch ((unsigned char) my.code [i]) {
      case  G_KEY_GROUP   :
         my.disp [i]  = G_KEY_PIPE;
         sprintf (t, "%c", G_KEY_FIELD);
         strlcat (my.syst, t, 2000);
         strlcat (my.load, t, 2000);
         break;
      case  G_KEY_DQUOTE  :
         my.disp [i]  = G_KEY_TILDA;
         sprintf (t, "%c", G_KEY_DQUOTE);
         strlcat (my.syst, t, 2000);
         sprintf (t, "%c", G_KEY_TILDA);
         strlcat (my.load, t, 2000);
         break;
      case  G_CHAR_RETURN :
         sprintf (t, "\\n");
         strlcat (my.syst, t, 2000);
         strlcat (my.load, t, 2000);
         break;
      case  G_CHAR_ESCAPE :
         sprintf (t, "\\e");
         strlcat (my.syst, t, 2000);
         strlcat (my.load, t, 2000);
         break;
      default  :
         my.disp [i]  = my.code [i];
         sprintf (t, "%c", my.code [i]);
         strlcat (my.syst, t, 2000);
         strlcat (my.load, t, 2000);
         break;
      }
   }
   /*---(display)------------------------*/
   printf ("my.disp <<%s>>\n", my.disp);
   printf ("my.syst <<%s>>\n", my.syst);
   printf ("my.load <<%s>>\n", my.load);
   /*---(complete)-----------------------*/
   return 0;
}

char
CODE_code          (void)
{
   /*---(counters)-----------------------*/
   ++(my.nstep);
   ++(my.cstep);
   /*---(fix strings)--------------------*/
   CODE_display ();
   /*---(write)--------------------------*/
   fprintf (my.file_code, "      /*---(code)------------------------*/\n");
   fprintf (my.file_code, "      %s\n",  my.syst);
   fprintf (my.file_code, "      if (g_exec == 1)  yUNIT_code    (my_unit, %4i, %3i, \"%s\", \"%s\");\n", my.n_line, my.cstep, my.desc, my.disp);
   /*---(complete)-----------------------*/
   return 0;
}

char
CODE_load          (void)
{
   /*---(locals)-----------+-----------+-*/
   int         x_len       = 0;
   char       *p           = NULL;
   char       *q           = " ";
   char       *r           = NULL;
   char        x_temp      [LEN_STR ];
   char       *x_var       = NULL;
   /*---(counters)-----------------------*/
   ++(my.nstep);
   ++(my.cstep);
   /*---(fix strings)--------------------*/
   CODE_display ();
   fprintf (my.file_code, "      /*---(load)------------------------*/\n");
   fprintf (my.file_code, "      if (g_exec == 1)  yUNIT_load    (my_unit, %4i, %3i, \"%s\", \"%s\", ", my.n_line, my.cstep, my.desc, my.meth);
   /*---(check for var)------------------*/
   x_len = strlen (my.load);
   if        (x_len <= 7) {
      fprintf (my.file_code, "\"%s\"", my.load);
   } else if (strncmp (my.code, "[[ ", 3) != 0) {
      fprintf (my.file_code, "\"%s\"", my.load);
   } else {
      strlcpy (x_temp, my.load + 3, LEN_STR);
      x_var = x_temp;
      p = strtok_r (x_temp, q, &r);
      if (p == NULL) fprintf (my.file_code, "\"%s\"" , "unknown");
      else           fprintf (my.file_code, "%s" , x_var);
   }
   /*---(write)--------------------------*/
   /*> fprintf (my.file_code, "         if (g_exec == 1)  yUNIT_load    (my_unit, %4i, %3i, \"%s\", \"%s\", \"%s\");\n", my.n_line, my.cstep, my.desc, my.meth, my.load);   <*/
   fprintf (my.file_code, ");\n");
   /*---(complete)-----------------------*/
   return 0;
}

char
CODE_sys           (void)
{
   /*---(counters)-----------------------*/
   ++(my.nstep);
   ++(my.cstep);
   /*---(fix strings)--------------------*/
   CODE_display ();
   /*---(write)--------------------------*/
   fprintf (my.file_code, "      /*---(sys)-------------------------*/\n");
   fprintf (my.file_code, "      if (g_exec == 1)  yUNIT_sys     (my_unit, %4i, %3i, \"%s\", \"%s\");\n", my.n_line, my.cstep, my.desc, my.disp);
   /*---(complete)-----------------------*/
   return 0;
}

void
VOID_void          (char *a_one, int a_two)
{
   return;
}

char
CODE_prefix        (char a_test)
{
   /*---(locals)-----------+-----------+-*/
   char        x_func      [LEN_STR]   = "";
   /*---(pre-work for void)--------------*/
   if (a_test == 'v') {
      fprintf (my.file_code, "      if (g_exec == 1)  ");
      fprintf (my.file_code, "%-13s (%s);\n"     , my.meth , my.args);
   }
   /*---(determine function)-------------*/
   switch (a_test) {
   case 'v'  : strlcpy (x_func, "yUNIT_void"     , LEN_STR);    break;
   case 's'  : strlcpy (x_func, "yUNIT_string"   , LEN_STR);    break;
   case 'u'  : strlcpy (x_func, "yUNIT_round"    , LEN_STR);    break;
   case 'i'  : strlcpy (x_func, "yUNIT_int"      , LEN_STR);    break;
   case 'r'  : strlcpy (x_func, "yUNIT_real"     , LEN_STR);    break;
   case 'p'  : strlcpy (x_func, "yUNIT_point"    , LEN_STR);    break;
   case '-'  : strlcpy (x_func, "yUNIT_unknown"  , LEN_STR);    break;
   default   : strlcpy (x_func, "yUNIT_removed"  , LEN_STR);    break;
   }
   /*---(write prefix)-------------------*/
   fprintf (my.file_code, "      if (g_exec == 1)  ");
   fprintf (my.file_code, "%-13s (my_unit, "     , x_func);
   fprintf (my.file_code, "%4i, %3i, "           , my.n_line, my.cstep);
   fprintf (my.file_code, "\"%s\", "             , my.desc);
   fprintf (my.file_code, "\"%s\", \"%s\", "     , my.meth  , my.disp);
   /*---(write test)---------------------*/
   switch (a_test) {
   case 'v' :    /* pure void        */
      fprintf (my.file_code, "\"%s\");\n"        , my.test);
      break;
   default  :    /* all others       */
      fprintf (my.file_code, "\"%s\", "          , my.test);
      break;
      return 0;
   }
   /*---(complete)-----------------------*/
   return 0;
}

char
CODE_unknown       (void)
{
   CODE_prefix  ('-');
   fprintf (my.file_code, "\"%s\", "           , my.expe);
   fprintf (my.file_code, "\"\");\n"           );
   fprintf (my.file_code, "\n");
   return 0;
}

char
CODE_expe_var      (char a_test)
{
   /*---(locals)-----------+-----------+-*/
   char       *p           = NULL;
   char       *q           = " ";
   char       *r           = NULL;
   char        x_var       [LEN_STR ];
   char       *x_expe      = NULL;
   /*---(defense)------------------------*/
   if (a_test == 'v')    return 0;
   /*---(normal)-------------------------*/
   if (strncmp (my.expe, "[[ ", 3) != 0) {
      switch (a_test) {
      case 's' : case 'u' :                 /* stringish   */
         fprintf (my.file_code, "\"%s\", " , my.expe);
         break;
      case 'i' : case 'p' : case 'r' :      /* numberish   */
         fprintf (my.file_code, "%s, "     , my.expe);
         break;
      default  :
         fprintf (my.file_code, "\"%s\");\n"         , my.expe);
         break;
      }
      return 0;
   }
   /*---(check for var)------------------*/
   else {
      strlcpy (x_var, my.expe + 3, LEN_STR);
      x_expe = x_var;
      p = strtok_r (x_var, q, &r);
      if (p == NULL) fprintf (my.file_code, "\"%s\", " , "unknown");
      else           fprintf (my.file_code, "%s, "     , x_expe);
   }
   /*---(complete)-----------------------*/
   return 0;
}

char
CODE_suffix        (char a_test)
{
   /*---(defense)------------------------*/
   if (a_test == 'v')    return 0;
   /*---(handle echos)-------------------*/
   if (strcmp (my.meth, "echo") == 0) {
      fprintf (my.file_code, "%s);\n"      , my.syst);
   }
   /*---(check for simple end)-----------*/
   else if (strcmp (my.retn, "") == 0) {
      fprintf (my.file_code, "%s (%s));\n" , my.meth, my.syst);
   }
   /*---(handle return variables)--------*/
   else {
      switch (my.type) {
      case 'i' : case 'p' : case 'r' :
         fprintf (my.file_code, "%s = %s (%s));\n", my.retn, my.meth, my.syst);
         break;
      case 's' : case 'u' :
         fprintf (my.file_code, "%s (%s));\n"     , my.meth, my.syst);
         fprintf (my.file_code, "         if (g_exec == 1)  strcpy (%s, %s);\n", my.retn, yUNIT_s_rc);
         break;
      default  :
         fprintf (my.file_code, "%s (%s));\n"     , my.meth, my.syst);
         break;
      }
   }
   /*---(complete)-----------------------*/
   return 0;
}

char
CODE_echo          (void)
{
   char        x_test      = '-';
   /*---(counters)-----------------------*/
   ++(my.nstep);
   ++(my.cstep);
   /*---(fix strings)--------------------*/
   CODE_display ();
   /*---(handle return values)-----------*/
   strlcpy (my.meth, "echo", LEN_STR);
   x_test = my.test [0];
   CODE_prefix    (x_test);
   CODE_expe_var  (x_test);
   CODE_suffix    (x_test);
   /*---(finish)-------------------------*/
   fprintf (my.file_code, "\n");
   /*---(complete)-----------------------*/
   return 0;
}

char
CODE_exec          (void)
{
   /*---(design notes)-------------------*/
   /*
    * maintained/kept
    *   v_   = void
    *   s_   = string
    *   i_   = integer
    *   r_   = real
    *   p_   = pointer
    *
    * rejected/removed
    *   e_   = echo variable contents (use getter)
    *   c_   = custom (better to make expect field indicate this)
    *   m_   = macro to show complier macro values (NO)
    *
    *
    */
   char        x_test      = '-';
   /*---(counters)-----------------------*/
   ++(my.nstep);
   ++(my.cstep);
   /*---(fix strings)--------------------*/
   CODE_display ();
   /*---(debugging)----------------------*/
   /*> if (strcmp (my.verb, "exec"   ) == 0) {                                                                                                                     <* 
    *>    fprintf (my.file_code, "      %sUG_TOPS    %sOG_unitstep (%d, %d, %d, %d, \"%s\");\n", "DEB", "yL", my.cscrp, my.ccond, my.cstep, my.n_line, my.desc);   <* 
    *> }                                                                                                                                                           <*/
   fprintf (my.file_code, "      /*---(step)------------------------*/\n");
   fprintf (my.file_code, "      %sUG_TOPS    %sOG_unitstep (%d, g_offset + %d, %d, %d, \"%s\");\n", "DEB", "yL", my.cscrp, my.ccond, my.cstep, my.n_line, my.desc);
   /*---(handle return values)-----------*/
   x_test = my.test [0];
   CODE_prefix    (x_test);
   CODE_expe_var  (x_test);
   CODE_suffix    (x_test);
   /*---(finish)-------------------------*/
   /*> fprintf (my.file_code, "\n");                                                  <*/
   /*---(complete)-----------------------*/
   return 0;
}

char
CODE_end           (void)
{
   char        x_recd      [LEN_RECD];
   int         x_len       = 0;             /* input record length            */
   CODE_scrp_end ();
   fprintf (my.file_code, "\n");
   SCRP_verbcode ();
   fprintf (my.file_main, "   /*---(complete)-----------------------*/\n");
   fprintf (my.file_main, "   if (g_exec ==  1)  return yUNIT_tinu (my_unit);\n");
   fprintf (my.file_main, "   return 0;\n");
   fprintf (my.file_main, "}\n");
   fprintf (my.file_main, "\n\n\n");
   fprintf (my.file_main, "/*============================== end-of-file =================================*/\n");
   /*---(open main file)-----------------*/
   fprintf (my.file_code, "\n");
   fclose (my.file_main);
   my.file_main = fopen (my.name_main, "r");
   while (1) {
      fgets (x_recd, LEN_RECD, my.file_main);
      if (feof (my.file_main)) break;
      fprintf  (my.file_code, x_recd);
   }
   fclose (my.file_main);
   return 0;
}

char
CODE_write         (void)
{
   switch (my.verb [0]) {
   case 'P'  :  if      (strcmp (my.verb, "PREP"     ) == 0) {
                   CODE_prep   ();
                }
                break;
   case 'i'  :  if      (strcmp (my.verb, "incl"     ) == 0) {
                   CODE_incl   ();
                }
                break;
   case 'S'  :  if      (strcmp (my.verb, "SCRP"     ) == 0) {
                   CODE_main   ();
                   CODE_scrp   ();
                }
                else if (strcmp (my.verb, "SECT"     ) == 0) {
                   CODE_main   ();
                   CODE_sect   ();
                }
                else if (strcmp (my.verb, "SHARED"   ) == 0) {
                   CODE_main   ();
                   CODE_shared ();
                }
                break;
   case 'G'  :  if      (strcmp (my.verb, "GROUP"    ) == 0) {
                   CODE_group  ();
                }
                break;
   case 'C'  :  if      (strcmp (my.verb, "COND"     ) == 0) {
                   CODE_cond   ();
                }
                break;
   case 'U'  :  if      (strcmp (my.verb, "USE_SHARE") == 0) {
                   CODE_use    ();
                }
                break;
   case 'm'  :  if      (strcmp (my.verb, "mode"     ) == 0) {
                   CODE_mode   ();
                }
                break;
   case 'c'  :  if      (strcmp (my.verb, "code"     ) == 0) {
                   CODE_code   ();
                }
                break;
   case 'l'  :  if      (strcmp (my.verb, "load"     ) == 0) {
                   CODE_load   ();
                }
                break;
   case 'e'  :  if      (strcmp (my.verb, "exec"     ) == 0) {
                   CODE_exec   ();
                }
                else if (strcmp (my.verb, "echo"     ) == 0) {
                   CODE_echo   ();
                }
                break;
   case 'g'  :  if      (strcmp (my.verb, "get"      ) == 0) {
                   CODE_exec   ();
                }
                break;
   case 's'  :  if      (strcmp (my.verb, "set"      ) == 0) {
                   CODE_exec   ();
                }
                break;
   case '#'  :  break;
   default   :  CODE_unknown ();
                break;
   }
   return 0;
}


/*===============================[[ end code ]]===============================*/
