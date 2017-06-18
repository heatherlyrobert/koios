/*===============================[[ beg-code ]]===============================*/
#include    "koios.h"        /* LOCAL  : main header                          */



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
      DEBUG_TOPS   yLOG_fatal   ("scrp file" , "can not open output script file");
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
   fprintf (my.file_conv, "#   updated to the most recent version (v21)\n");
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
   rc = fclose (my.file_conv);
   --rce;  if (rc != 0) {
      return rce;
   }
   /*---(complete)-----------------------*/
   DEBUG_TOPS   yLOG_exit    (__FUNCTION__);
   return 0;
}

char
CONV_header        (void)
{
   /*---(output)-------------------------*/
   fprintf (my.file_conv, "\n\n\n");
   fprintf (my.file_conv, "#23456789-12  123  123456789-123456789-123456789-12345  123456789-123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  -  123456789-123456789- \n");
   fprintf (my.file_conv, "#==(verb)===  ver  ===========(description)===========  =====(function)=====  ========================(arguments)===================================  ==(test)==  ==========================(results)=================================================================  t  ========(var)======= \n");
   return 0;
}

char
CONV_prep          (void)
{
   CONV_header ();
   fprintf (my.file_conv, "PREP          %3s  %-59.59s  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  \n", "v21", my.desc);
   return 0;
}

char
CONV_incl          (void)
{
   fprintf (my.file_conv, "   incl       %3s  %-35.35s  %-20.20s  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  \n", "v21", my.desc, my.meth);
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
   /*---(output)-------------------------*/
   CONV_header ();
   fprintf (my.file_conv, "SCRP          %3s  %-59.59s  %-70.70s  ((%02d.---))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  \n", "v21", my.desc, my.meth, my.nscrp);
   /*---(complete)-----------------------*/
   return 0;
}

char         /*--> write a section entry -----------------[--------[--------]-*/
CONV_sect          (void)
{
   /*---(output)-------------------------*/
   CONV_header ();
   fprintf (my.file_conv, "SECT          %3s  %-59.59s  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  \n", "v21", my.desc);
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
   fprintf (my.file_conv, "   GROUP      %3s  %-59.59s  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  \n", "v21", my.desc);
   /*---(complete)-----------------------*/
   return 0;
}

char         /*--> write a condition entry ---------------[--------[--------]-*/
CONV_cond          (void)
{
   /*---(counters)-----------------------*/
   ++(my.ncond);
   /*---(output)-------------------------*/
   fprintf (my.file_conv, "\n");
   fprintf (my.file_conv, "   COND       %3s  %-59.59s  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((%02d.%03d))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  \n", "v21", my.desc, my.nscrp, my.ncond);
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
   fprintf (my.file_conv, "     %-4.4s     %3s  %-35.35s  %-20.20s  %-70s  %-10.10s  %-100s \n", my.verb, "v21", my.desc, my.meth, my.args, my.test, my.expe);
   return 0;
}

char
CONV_code          (void)
{
   fprintf (my.file_conv, "     %-4.4s     %3s  %-35.35s  - - - - - - - - - -   %-188s \n", my.verb, "v21", my.desc, my.code);
   return 0;
}

char
CONV_echo          (void)
{
   fprintf (my.file_conv, "     %-4.4s     %3s  %-35.35s  - - - - - - - - - -   %-70s  %-10.10s  %-100s \n", my.verb, "v21", my.desc, my.args, my.test, my.expe);
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
   case 'P'  :  if      (strcmp (my.verb, "PREP"   ) == 0) {
                   CONV_prep   ();
                }
                break;
   case 'i'  :  if      (strcmp (my.verb, "incl"   ) == 0) {
                   CONV_incl   ();
                }
                break;
   case 'S'  :  if      (strcmp (my.verb, "SCRP"   ) == 0) {
                   CONV_scrp   ();
                }
                else if (strcmp (my.verb, "SECT"   ) == 0) {
                   CONV_sect   ();
                }
                break;
   case 'G'  :  if      (strcmp (my.verb, "GROUP"  ) == 0) {
                   CONV_group  ();
                }
                break;
   case 'C'  :  if      (strcmp (my.verb, "COND"   ) == 0) {
                   CONV_cond   ();
                }
                break;
   case 'e'  :  if      (strcmp (my.verb, "exec"   ) == 0) {
                   CONV_exec   ();
                }
                else if (strcmp (my.verb, "echo"   ) == 0) {
                   CONV_echo   ();
                }
                break;
   case 'g'  :  if      (strcmp (my.verb, "get"    ) == 0) {
                   CONV_exec   ();
                }
                break;
   case 's'  :  if      (strcmp (my.verb, "set"    ) == 0) {
                   CONV_exec   ();
                }
                break;
   case 'c'  :  if      (strcmp (my.verb, "code"   ) == 0) {
                   CONV_code   ();
                }
                break;
   case 'l'  :  if      (strcmp (my.verb, "load"   ) == 0) {
                   CONV_code   ();
                }
                break;
   case 'm'  :  if      (strcmp (my.verb, "mode"   ) == 0) {
                   CONV_code   ();
                }
                break;
   }
   /*---(complete)-----------------------*/
   DEBUG_TOPS   yLOG_exit    (__FUNCTION__);
   return 0;
}


/*===============================[[ end code ]]===============================*/
