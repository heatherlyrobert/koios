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



char         /*--> open code file ------------------------[ leaf   [ ------ ]-*/
CODE_open          (void)
{
   /*---(locals)-----------+-----------+-*/
   char        rce         = -10;           /* return code for errors         */
   /*---(header)-------------------------*/
   DEBUG_TOPS   yLOG_enter   (__FUNCTION__);
   /*---(open configuration)-------------*/
   DEBUG_OUTP   yLOG_point   ("name"      , my.name_code);
   my.file_code = fopen (my.name_code, "w");
   DEBUG_OUTP   yLOG_point   ("file*"     , my.file_code);
   --rce;  if (my.file_code == NULL) {
      DEBUG_TOPS   yLOG_fatal   ("scrp file" , "can not open script file");
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
   fprintf (my.file_code, "/*============================================================================*/\n");
   fprintf (my.file_code, "/*=========================== beginning-of-file ==============================*/\n");
   fprintf (my.file_code, "/*============================================================================*/\n");
   fprintf (my.file_code, "\n");
   fprintf (my.file_code, "\n");
   fprintf (my.file_code, "\n");
   fprintf (my.file_code, "/*==========================---------------------=============================*/\n");
   fprintf (my.file_code, "/*===----                  unit testing preparation                    ----===*/\n");
   fprintf (my.file_code, "/*==========================---------------------=============================*/\n");
   fprintf (my.file_code, "\n");
   fprintf (my.file_code, "#include <stdio.h>\n");
   fprintf (my.file_code, "#include <string.h>\n");
   fprintf (my.file_code, "#include <stdlib.h>               /* exit,atoi                                */\n");
   fprintf (my.file_code, "#include <unistd.h>               /* sleep                                    */\n");
   fprintf (my.file_code, "\n");
   fprintf (my.file_code, "#include <yUNIT.h>                /* unit testing functions                   */\n");
   fprintf (my.file_code, "#include <yVAR.h>                 /* complex comparison functions             */\n");
   fprintf (my.file_code, "\n");
   fprintf (my.file_code, "void  *my_unit = NULL;            /* set up for the unit test                 */\n");
   fprintf (my.file_code, "char   eterm   = 'y';             /* handle console vs eterm                  */\n");
   fprintf (my.file_code, "int    g_noisy = 0;               /* how loud things should be                */\n");
   fprintf (my.file_code, "char   g_debug [100];             /* display debugging info                   */\n");
   fprintf (my.file_code, "char   CUSTOM  [2000];            /* holder for custom expect strings         */\n");
   fprintf (my.file_code, "\n\n\n");
   my.nscrp = my.cscrp = 0;
   my.ncond = my.ccond = 0;
   my.nstep = my.cstep = 0;
   return 0;
}

char
CODE_main          (void)
{
   if (my.driver == 'y')  return 0;
   fprintf (my.file_code, "\n\n\n");
   fprintf (my.file_code, "char stats  (void);\n");
   fprintf (my.file_code, "\n\n\n");
   fprintf (my.file_code, "char\n");
   fprintf (my.file_code, "usage (void)\n");
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
   fprintf (my.file_code, "int\n");
   fprintf (my.file_code, "main (int argc, char *argv[])\n");
   fprintf (my.file_code, "{\n");
   fprintf (my.file_code, "   char     *a         = NULL;    /* cli argument holder     */\n");
   fprintf (my.file_code, "   int       i         = 0;       /* loop iterator -- args   */\n");
   fprintf (my.file_code, "   int       v         = 5;       /* verbosity level         */\n");
   fprintf (my.file_code, "   int       l         = 0;       /* length of argument      */\n");
   fprintf (my.file_code, "   int       x_bad     = 0;       /* number of bad arguments */\n");
   fprintf (my.file_code, "   int       x_exec    = 1;       /* run                     */\n");
   fprintf (my.file_code, "   int       x_scrp    = 0;       /* script                  */\n");
   fprintf (my.file_code, "   int       x_cond    = 0;       /* condition               */\n");
   fprintf (my.file_code, "   char      x_temp    [10];      /* temp string             */\n");
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
   fprintf (my.file_code, "      else if (strcmp (a, \"--list-scrp\" )  == 0)    { x_exec = 0; v = 2; }\n");
   fprintf (my.file_code, "      else if (strcmp (a, \"--list-cond\" )  == 0)    { x_exec = 0; v = 3; }\n");
   fprintf (my.file_code, "      else if (strcmp (a, \"--list-step\" )  == 0)    { x_exec = 0; v = 4; }\n");
   fprintf (my.file_code, "      else if (strcmp (a, \"--list-stats\")  == 0)      stats();\n");
   fprintf (my.file_code, "      /*---(help)-------------------------*/\n");
   fprintf (my.file_code, "      else if (strcmp (a, \"--help\"      )  == 0)      usage();\n");
   fprintf (my.file_code, "      /*---(fomatting)--------------------*/\n");
   fprintf (my.file_code, "      else if (strcmp (a, \"--console\"   )  == 0)      eterm = '-';\n");
   fprintf (my.file_code, "      else if (strcmp (a, \"--eterm\"     )  == 0)      eterm = 'y';\n");
   fprintf (my.file_code, "      /*---(scope)------------------------*/\n");
   fprintf (my.file_code, "      else if (strcmp (a, \"--all\"       )  == 0)      { x_scrp = x_cond = 0; }\n");
   fprintf (my.file_code, "      else if (l == 2) {\n");
   fprintf (my.file_code, "          x_scrp = atoi(a);\n");
   fprintf (my.file_code, "      }\n");
   fprintf (my.file_code, "      else if (l == 6 && (a[2] == '.' || a[2] == '-'))    {\n");
   fprintf (my.file_code, "          sprintf (x_temp, \"%%c%%c\", a[0], a[1]);\n");
   fprintf (my.file_code, "          x_scrp = atoi (x_temp);\n");
   fprintf (my.file_code, "          sprintf (x_temp, \"%%c%%c%%c\", a[3], a[4], a[5]);\n");
   fprintf (my.file_code, "          x_cond = atoi (x_temp);\n");
   fprintf (my.file_code, "          v = 3;\n");
   fprintf (my.file_code, "      }\n");
   fprintf (my.file_code, "      else {\n");
   fprintf (my.file_code, "         printf(\"option not understood <<%%s>>\\n\", a);\n");
   fprintf (my.file_code, "         ++x_bad;\n");
   fprintf (my.file_code, "      }\n");
   fprintf (my.file_code, "      /*---(done)-------------------------*/\n");
   fprintf (my.file_code, "   }\n");
   fprintf (my.file_code, "   if (x_bad > 0) {\n");
   fprintf (my.file_code, "         printf(\"FATAL, exiting\\n\");\n");
   fprintf (my.file_code, "         exit (-1);\n");
   fprintf (my.file_code, "   }\n");
   fprintf (my.file_code, "   my_unit = yUNIT_unit(\"MyTest\", v, eterm);\n");
   fprintf (my.file_code, "   g_noisy = v;\n");
   fprintf (my.file_code, "   \n");
   my.driver = 'y';
   return 0;
}

char
CODE_prep          (void)
{
   fprintf (my.file_code, "/*==========================---------------------=============================*/\n");
   fprintf (my.file_code, "/*===----                program specific preparation                  ----===*/\n");
   fprintf (my.file_code, "/*==========================---------------------=============================*/\n");
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

char
CODE_scrp          (void)
{
   /*---(close last script)--------------*/
   if (my.cscrp >  0) {
      if (my.ccond > 0) {
         fprintf (my.file_code, "      if (x_exec == 1)  yUNIT_dnoc     (my_unit);\n");
         fprintf (my.file_code, "      yUNIT_noisy  (my_unit, g_noisy);\n");
         fprintf (my.file_code, "\n");
      }
      fprintf (my.file_code, "      /*---(script done)---------------------*/\n");
      fprintf (my.file_code, "      if (x_exec == 1)  yUNIT_prcs    (my_unit);\n");
      fprintf (my.file_code, "   }\n");
      fprintf (my.file_code, "\n");
   }
   /*---(counters)-----------------------*/
   ++(my.nscrp);
   ++(my.cscrp);
   my.ccond = 0;
   my.cstep = 0;
   /*---(beginning)----------------------*/
   fprintf (my.file_code, "\n\n\n");
   fprintf (my.file_code, "   /*========================---------------------============================*/\n");
   fprintf (my.file_code, "   /*===----                         SCRIPT                            ----===*/\n");
   fprintf (my.file_code, "   /*========================---------------------============================*/\n");
   fprintf (my.file_code, "   if (x_scrp == 0 || x_scrp == %i) {\n", my.cscrp);
   fprintf (my.file_code, "      yUNIT_scrp    (my_unit, %4i, %3i, \"%s\", \"%s\");\n", my.n_line, my.cscrp, my.meth, my.desc);
   fprintf (my.file_code, "\n");
   /*---(complete)-----------------------*/
   return 0;
}

char
CODE_sect          (void)
{
   fprintf (my.file_code, "   yUNIT_sect    (my_unit, \"%s\");\n", my.desc);
   fprintf (my.file_code, "\n");
   return 0;
}

char
CODE_group         (void)
{
   if (my.ccond > 0) {
      fprintf (my.file_code, "      if (x_exec == 1)  yUNIT_dnoc    (my_unit);\n");
      fprintf (my.file_code, "      yUNIT_noisy  (my_unit, g_noisy);\n");
      fprintf (my.file_code, "\n");
   }
   fprintf (my.file_code, "      /*---(group)---------------------------*/\n");
   fprintf (my.file_code, "      yUNIT_group   (my_unit, \"%s\");\n", my.desc);
   fprintf (my.file_code, "\n");
   return 0;
}

char
CODE_cond          (void)
{
   if (my.ccond > 0 && strcmp (my.last, "GROUP") != 0) {
      fprintf (my.file_code, "      if (x_exec == 1)  yUNIT_dnoc    (my_unit);\n");
      fprintf (my.file_code, "      yUNIT_noisy  (my_unit, g_noisy);\n");
      fprintf (my.file_code, "\n");
   }
   ++(my.ncond);
   ++(my.ccond);
   fprintf (my.file_code, "      /*---(condition)-----------------------*/\n");
   fprintf (my.file_code, "      if (x_scrp == %i && x_cond == %i) yUNIT_noisy  (my_unit, 5);\n", my.cscrp, my.ccond);
   fprintf (my.file_code, "      %sUG_TOPS    %sOG_unitcond (%d, %d, %d, \"%s\");\n", "DEB", "yL", my.cscrp, my.ccond, my.n_line, my.desc);
   fprintf (my.file_code, "      yUNIT_cond    (my_unit, %4i, %3i, \"%s\");\n", my.n_line, my.ccond, my.desc);
   fprintf (my.file_code, "\n");
   my.cstep = 0;
   return 0;
}

char
CODE_mode          (void)
{
   ++(my.nstep);
   ++(my.cstep);
   fprintf (my.file_code, "         if (x_exec == 1)  yUNIT_mode    (my_unit, %4i, %3i, %s);\n", my.n_line, my.cstep, my.args);
   fprintf (my.file_code, "\n");
   return 0;
}

char
CODE_display       (void)
{
   /*---(locals)-----------+-----------+-*/
   int         i           = 0;
   int         x_len       = 0;
   /*---(fix delimiters)-----------------*/
   x_len = strlen (my.code);
   strlcpy (my.disp, my.code, LEN_RECD);
   strlcpy (my.syst, my.code, LEN_RECD);
   strlcpy (my.load, my.code, LEN_RECD);
   for (i = 0; i < x_len; ++i) {
      if (my.code [i] == 29) {
         my.disp [i]  = '|';
         my.syst [i]  = 31;
         my.load [i]  = 31;
      }
      if (my.code [i] == '"') {
         my.disp [i]  = '~';
         my.load [i]  = '~';
      }
   }
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
   fprintf (my.file_code, "         %s\n",  my.syst);
   fprintf (my.file_code, "         if (x_exec == 1)  yUNIT_code    (my_unit, %4i, %3i, \"%s\", \"%s\");\n", my.n_line, my.cstep, my.desc, my.disp);
   fprintf (my.file_code, "\n");
   /*---(complete)-----------------------*/
   return 0;
}

char
CODE_load          (void)
{
   /*---(counters)-----------------------*/
   ++(my.nstep);
   ++(my.cstep);
   /*---(fix strings)--------------------*/
   CODE_display ();
   /*---(write)--------------------------*/
   fprintf (my.file_code, "         if (x_exec == 1)  yUNIT_load    (my_unit, %4i, %3i, \"%s\", \"%s\");\n", my.n_line, my.cstep, my.desc, my.load);
   fprintf (my.file_code, "\n");
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
   fprintf (my.file_code, "         if (x_exec == 1)  yUNIT_sys     (my_unit, %4i, %3i, \"%s\", \"%s\");\n", my.n_line, my.cstep, my.desc, my.disp);
   fprintf (my.file_code, "\n");
   /*---(complete)-----------------------*/
   return 0;
}

void
VOID_void          (char *a_one, int a_two)
{
   return;
}

char
CODE_unknown       (void)
{
   CODE_prefix  ("yUNIT_unknown");
   fprintf (my.file_code, "\"%s\", "           , my.test);
   fprintf (my.file_code, "\"%s\", "           , my.expe);
   fprintf (my.file_code, "\"\");\n"           );
   fprintf (my.file_code, "\n");
   return 0;
}

char
CODE_prefix        (char *a_func)
{
   fprintf (my.file_code, "         ");
   fprintf (my.file_code, "%-13s (my_unit, "   , a_func);
   fprintf (my.file_code, "%4i, %3i, \"%s\", "  , my.n_line , my.cstep, my.desc);
   fprintf (my.file_code, "\"%s\", \"%s\", "    , my.meth , my.disp);
   return 0;
}

char
CODE_suffix        (void)
{
   /*---(locals)-----------+-----------+-*/
   char       *p;
   char       *q           = " ";
   char        x_var       [LEN_STR ];
   /*---(prepare)------------------------*/
   fprintf (my.file_code, "\"%s\", "           , my.test);
   /*---(look for custom var)------------*/
   if (strcmp (my.expe, "[[ CUSTOM ]]") == 0) {
      fprintf (my.file_code, "CUSTOM, ");
   }
   /*---(look for other var)-------------*/
   else if (strncmp (my.expe, "[[ ", 3) == 0) {
      strlcpy (x_var, my.expe, LEN_STR);
      p = strtok (x_var, q);
      if (p == NULL) {
         fprintf (my.file_code, "\"%s\", "           , my.expe);
      } else {
         p = strtok (NULL , q);
         if (p == NULL) {
            fprintf (my.file_code, "\"%s\", "           , my.expe);
         } else {
            fprintf (my.file_code, "%s, "               , p);
         }
      }
   }
   /*---(default is literal string)------*/
   else {
      fprintf (my.file_code, "\"%s\", "           , my.expe);
   }
   /*---(wrap-up)------------------------*/
   fprintf (my.file_code, "%s (%s));\n"        , my.meth, my.syst);
   /*---(complet)------------------------*/
   return 0;
}

char
CODE_echo          (void)
{
   /*---(counters)-----------------------*/
   ++(my.nstep);
   ++(my.cstep);
   /*---(fix strings)--------------------*/
   CODE_display ();
   /*---(actual)-------------------------*/
   fprintf (my.file_code, "         ");
   fprintf (my.file_code, "yUNIT_string  (my_unit, ");
   fprintf (my.file_code, "%4i, %3i, \"%s\", "  , my.n_line , my.cstep, my.desc);
   fprintf (my.file_code, "\"%s\", \"%s\", "    , "echo"  , my.disp);
   fprintf (my.file_code, "\"%s\", "           , my.test);
   fprintf (my.file_code, "\"%s\", "           , my.expe);
   fprintf (my.file_code, "%s);"               , my.code);
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
   /*---(counters)-----------------------*/
   ++(my.nstep);
   ++(my.cstep);
   /*---(fix strings)--------------------*/
   CODE_display ();
   /*---(debugging)----------------------*/
   if (strcmp (my.verb, "exec"   ) == 0) {
      fprintf (my.file_code, "         %sUG_TOPS    %sOG_unitstep (%d, %d, %d, %d, \"%s\");\n", "DEB", "yL", my.cscrp, my.ccond, my.cstep, my.n_line, my.desc);
   }
   /*---(handle return values)-----------*/
   switch (my.test [0]) {
   case 'v' :      /* pure voids         */
      fprintf (my.file_code, "         ");
      fprintf (my.file_code, "%-13s (%s);\n"      , my.meth , my.args);
      CODE_prefix  ("yUNIT_void"    );
      fprintf (my.file_code, "\"%s\");\n"         , my.test);
      break;
   case 's' :      /* pure strings       */
      CODE_prefix  ("yUNIT_string"  );
      CODE_suffix  ();
      break;
   case 'i' :      /* pure integers      */
      CODE_prefix  ("yUNIT_int"     );
      CODE_suffix  ();
      break;
   case 'p' :      /* numerics in string */
      CODE_prefix  ("yUNIT_point"   );
      fprintf (my.file_code, "\"%s\", "           , my.test);
      fprintf (my.file_code, "%s, "               , my.expe);
      fprintf (my.file_code, "%s (%s));\n"        , my.meth, my.syst);
      /*> CODE_suffix  ();                                                            <*/
      break;
   case 'u' :      /* numerics in string */
      CODE_prefix  ("yUNIT_round"   );
      CODE_suffix  ();
      break;
   case 'e' :      /* echo   (REMOVED)     */
   case 'c' :      /* custom (REMOVED)     */
   default  :
      CODE_prefix  ("yUNIT_removed" );
      fprintf (my.file_code, "\"%s\", \"%s\");"   , my.test, my.expe);
      fprintf (my.file_code, "\n");
      break; 
   }
   /*---(finish)-------------------------*/
   fprintf (my.file_code, "\n");
   /*---(complete)-----------------------*/
   return 0;
}

char
CODE_end           (void)
{
   if (my.ccond > 0) {
      fprintf (my.file_code, "      if (x_exec == 1)  yUNIT_dnoc   (my_unit);\n");
      fprintf (my.file_code, "      yUNIT_noisy  (my_unit, g_noisy);\n");
      fprintf (my.file_code, "\n");
   }
   if (my.cscrp > 0) {
      fprintf (my.file_code, "      /*---(script done)---------------------*/\n");
      fprintf (my.file_code, "      if (x_exec == 1)  yUNIT_prcs   (my_unit);\n");
      fprintf (my.file_code, "   }\n");
   }
   fprintf (my.file_code, "\n\n\n");
   fprintf (my.file_code, "   /*========================---------------------============================*/\n");
   fprintf (my.file_code, "   /*===----                        WRAP-UP                            ----===*/\n");
   fprintf (my.file_code, "   /*========================---------------------============================*/\n");
   fprintf (my.file_code, "   if (x_exec == 1)  return yUNIT_tinu (my_unit);\n");
   fprintf (my.file_code, "   else              return 0;\n");
   fprintf (my.file_code, "}\n");
   fprintf (my.file_code, "\n\n\n");
   SCRP_verbcode ();
   fprintf (my.file_code, "\n\n\n");
   fprintf (my.file_code, "/*============================== end-of-file =================================*/\n");
   return 0;
}

char
CODE_write         (void)
{
   switch (my.verb [0]) {
   case 'P'  :  if      (strcmp (my.verb, "PREP"   ) == 0) {
                   CODE_prep   ();
                }
                break;
   case 'i'  :  if      (strcmp (my.verb, "incl"   ) == 0) {
                   CODE_incl   ();
                }
                break;
   case 'S'  :  if      (strcmp (my.verb, "SCRP"   ) == 0) {
                   CODE_main   ();
                   CODE_scrp   ();
                }
                else if (strcmp (my.verb, "SECT"   ) == 0) {
                   CODE_main   ();
                   CODE_sect   ();
                }
                break;
   case 'G'  :  if      (strcmp (my.verb, "GROUP"  ) == 0) {
                   CODE_group  ();
                }
                break;
   case 'C'  :  if      (strcmp (my.verb, "COND"   ) == 0) {
                   CODE_cond   ();
                }
                break;
   case 'm'  :  if      (strcmp (my.verb, "mode"   ) == 0) {
                   CODE_mode   ();
                }
                break;
   case 'c'  :  if      (strcmp (my.verb, "code"   ) == 0) {
                   CODE_code   ();
                }
                break;
   case 'l'  :  if      (strcmp (my.verb, "load"   ) == 0) {
                   CODE_load   ();
                }
                break;
   case 'e'  :  if      (strcmp (my.verb, "exec"   ) == 0) {
                   CODE_exec   ();
                }
                else if (strcmp (my.verb, "echo"   ) == 0) {
                   CODE_echo   ();
                }
                break;
   case 'g'  :  if      (strcmp (my.verb, "get"    ) == 0) {
                   CODE_exec   ();
                }
                break;
   case 's'  :  if      (strcmp (my.verb, "set"    ) == 0) {
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
