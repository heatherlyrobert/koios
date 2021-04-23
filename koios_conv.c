/*===============================[[ beg-code ]]===============================*/
#include    "koios.h"        /* LOCAL  : main header                          */





static char *s_suffix = "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ";
static char *s_hund   = "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ";



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
   DEBUG_OUTP   yLOG_point   ("name"      , my.n_conv);
   my.f_conv = fopen (my.n_conv, "w");
   DEBUG_OUTP   yLOG_point   ("file*"     , my.f_conv);
   --rce;  if (my.f_conv == NULL) {
      DEBUG_TOPS   yLOG_fatal   ("scrp file, can not open output script file");
      DEBUG_TOPS   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   DEBUG_OUTP   yLOG_note    ("output script file open");
   /*---(complete)-----------------------*/
   DEBUG_TOPS   yLOG_exit    (__FUNCTION__);
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
   DEBUG_OUTP   yLOG_point   ("*f_conv", my.f_conv);
   --rce;  if (my.f_conv == NULL) {
      DEBUG_TOPS   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   rc = fclose (my.f_conv);
   --rce;  if (rc != 0) {
      DEBUG_TOPS   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   my.f_conv = NULL;
   /*---(complete)-----------------------*/
   DEBUG_TOPS   yLOG_exit    (__FUNCTION__);
   return 0;
}

char
CONV_printf             (char *a_format, ...)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   va_list     x_vlist;
   /*---(defense)------------------------*/
   --rce;  if (my.f_conv == NULL)    return rce;
   --rce;  if (a_format  == NULL)    return rce;
   /*---(write)--------------------------*/
   va_start (x_vlist, a_format);
   vfprintf (my.f_conv, a_format, x_vlist);
   va_end   (x_vlist);
   fflush   (my.f_conv);
   /*---(complete)-------------------------*/
   return 0;
}

char
CONV_cycle              (void)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        t           [LEN_RECD]  = "";
   /*---(defense)------------------------*/
   --rce;  if (my.f_conv == NULL)    return rce;
   /*---(write)--------------------------*/
   CONV_close  ();
   sprintf (t, "rm -f %s 2> /dev/null", my.n_conv);
   system  (t);
   CONV_open   ();
   /*---(complete)-------------------------*/
   return 0;
}

char
CONV_beg           (void)
{
   CONV_printf ("#!/usr/local/bin/koios\n");
   CONV_printf ("#   %s\n", P_ONELINE);
   my.nscrp  = my.cscrp = 0;
   my.ncond  = my.ccond = 0;
   my.nstep  = my.cstep = 0;
   my.cshare = '-';
   return 0;
}

char
CONV_end           (void)
{
   CONV_printf ("\n\n\n");
   CONV_printf ("# end-of-file.  done, finito, completare, whimper [Ï´···\n");
   return 0;
}

char
CONV_header        (void)
{
   /*---(output)-------------------------*/
   CONV_printf ("\n\n\n");
   CONV_printf ("#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  -  123456789-123456789- \n");
   CONV_printf ("#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  t  ========(var)======= \n");
   return 0;
}

char
CONV_prep          (void)
{
   CONV_header ();
   CONV_printf ("PREP          %-65.65s  %s\n", my.desc, s_suffix);
   return 0;
}

char
CONV_incl          (void)
{
   CONV_printf ("   incl       %-35.35s  %-26.26s  %s\n", my.desc, my.meth, s_suffix);
   return 0;
}

char
CONV_comment       (void)
{
   CONV_printf ("%s\n", my.recd);
   return 0;
}



/*====================------------------------------------====================*/
/*===----                        script level                          ----===*/
/*====================------------------------------------====================*/
static void  o___SCRIPT__________o () { return; }

char         /*--> write a script entry ------------------[--------[--------]-*/
CONV_scrp          (void)
{
   char        t           [LEN_TERSE] = "";
   /*---(counters)-----------------------*/
   ++(my.nscrp);
   my.ncond  = 0;
   my.cshare = '-';
   if (strlen (my.stage) != 0)  sprintf (t, "[%s]", my.stage);
   /*---(output)-------------------------*/
   CONV_header ();
   CONV_printf ("SCRP    %-4.4s  %-65.65s  %-100.100s  ((%02d.---))  %s \n", t, my.desc, my.meth, my.nscrp, s_hund);
   /*---(complete)-----------------------*/
   return 0;
}

char         /*--> write a section entry -----------------[--------[--------]-*/
CONV_sect          (void)
{
   /*---(counters)-----------------------*/
   my.ncond  = 0;
   my.cshare = '-';
   /*---(output)-------------------------*/
   CONV_header ();
   sprintf (my.updated  , "SECT          %-65.65s  %s", my.desc, s_suffix);
   CONV_printf ("%s\n", my.updated);
   /*---(complete)-----------------------*/
   return 0;
}

char         /*-> write a shared entry -----------------[ ------ [----------]-*/
CONV_shared        (void)
{
   char        s           [LEN_LABEL] = "";
   char        t           [LEN_RECD ] = "";
   /*---(counters)-----------------------*/
   my.ncond  = 0;
   my.cshare = my.share;
   /*---(output)-------------------------*/
   CONV_header ();
   sprintf (t, "-%c-", my.cshare);
   sprintf (s, "((%c%c.---))", my.cshare, my.cshare);
   CONV_printf ("SHARED   %-3.3s  %-65.65s  %s  %-10.10s  %s \n", t, my.desc, s_hund, s, s_hund);
   /*---(complete)-----------------------*/
   return 0;
}

char         /*-> write a global entry -----------------[ ------ [----------]-*/
CONV_global        (void)
{
   char        s           [LEN_LABEL] = "";
   char        t           [LEN_RECD ] = "";
   /*---(counters)-----------------------*/
   my.ncond  = 0;
   my.cshare = my.share;
   /*---(output)-------------------------*/
   CONV_header ();
   sprintf (t, "-%c-", my.cshare);
   sprintf (s, "((%c%c.---))", my.cshare, my.cshare);
   CONV_printf ("GLOBAL   %-3.3s  %-65.65s  %s  %-10.10s  %s \n", t, my.desc, s_hund, s, s_hund);
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
   CONV_printf ("\n   GROUP      %-65.65s  %s\n", my.desc, s_suffix);
   return 0;
}

char         /*--> write a condition entry ---------------[--------[--------]-*/
CONV_cond          (void)
{
   char        s           [LEN_LABEL] = "";
   char        t           [LEN_RECD ] = "   ";
   ++(my.ncond);
   if (my.mark   != '-')  sprintf (t, "(%c)", my.mark);
   if (my.cshare == '-')  sprintf (s, "((%02d.%03d))", my.nscrp, my.ncond);
   else                   sprintf (s, "((%c%c.%03d))", my.cshare, my.cshare, my.ncond);
   CONV_printf ("\n   COND  %-3.3s  %-65.65s  %s  %-10.10s  %s \n", t, my.desc, s_hund, s, s_hund);
   return 0;
}

char         /*--> write a ditto entry -------------------[--------[--------]-*/
CONV_ditto         (void)
{
   char        s           [LEN_LABEL] = "";
   char        t           [LEN_TERSE] = "";
   ++(my.ncond);
   if (my.mark   != '-')  sprintf (t, "(%c)", my.mark);
   if (my.cshare == '-')  sprintf (s, "((%02d.%03d))", my.nscrp, my.ncond);
   else                   sprintf (s, "((%c%c.%03d))", my.cshare, my.cshare, my.ncond);
   CONV_printf ("\n   DITTO %3.3s  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -    %s  %-10.10s  %s \n", t, s_hund, s, s_hund);
   return 0;
}

char         /*--> write a condition entry ---------------[--------[--------]-*/
CONV_reuse         (void)
{
   char        t           [LEN_RECD ] = "";
   /*---(output)-------------------------*/
   sprintf (t, "-%c-", my.share);
   CONV_printf ("\n   REUSE %-3.3s  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  %s\n", t, s_suffix);
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
   sprintf (my.updated  , "     %-6.6s   %-35.35s  %-26.26s  %-100s  %-10.10s  %-100s ", my.verb, my.desc, my.meth, my.args, my.test, my.expe);
   if (strcmp (my.retn, "") != 0) {
      sprintf (t           , " %c  %-20s ", my.type, my.retn); 
      strlcat (my.updated, t, LEN_RECD);
   }
   CONV_printf ("%s\n", my.updated);
   return 0;
}

char
CONV_load          (void)
{
   CONV_printf ("     %-6.6s   %-35.35s  %-26.26s  %-218s \n", my.verb, my.desc, my.meth, my.code);
   return 0;
}

char
CONV_mode          (void)
{
   CONV_printf ("     %-6.6s   %-35.35s  - - - - - - - - - - - - -   %s\n", my.verb, my.desc, s_suffix);
   return 0;
}

char
CONV_code          (void)
{
   CONV_printf ("     %-6.6s   %-35.35s  - - - - - - - - - - - - -   %-218s \n", my.verb, my.desc, my.code);
   return 0;
}

char
CONV_echo          (void)
{
   CONV_printf ("     %-6.6s   %-35.35s  - - - - - - - - - - - - -   %-100s  %-10.10s  %-100s \n", my.verb, my.desc, my.args, my.test, my.expe);
   return 0;
}



/*====================------------------------------------====================*/
/*===----                          main driver                         ----===*/
/*====================------------------------------------====================*/
static void  o___DRIVER__________o () { return; }

char
CONV_driver        (void)
{
   char        rc          =    0;
   DEBUG_TOPS   yLOG_enter   (__FUNCTION__);
   if (my.p_conv == NULL)  return;
   rc = my.p_conv ();
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
   strlcpy  (my.answer, "CONV unit      : question not understood", LEN_FULL);
   if      (strcmp (a_question, "file"      ) == 0) {
      sprintf (my.answer, "CONV file      : %-35.35s %p", my.n_conv, my.f_conv);
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
