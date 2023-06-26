/*===============================[[ beg-code ]]===============================*/
#include    "koios.h"        /* LOCAL  : main header                          */



/*>                                                                                   <* 
 *> a_share                                                                           <* 
 *> r_cshare                                                                          <* 
 *> a_mark                                                                            <* 
 *> a_stage                                                                           <* 
 *>                                                                                   <*/

static char *s_suffix = "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ";
static char *s_hund   = "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ";



char
CONV__defense      (FILE *a_conv, cchar a_verb [LEN_LABEL], cchar a_desc [LEN_LONG], cchar a_meth [LEN_HUND], cchar a_args [LEN_FULL], cchar a_test [LEN_LABEL], cchar a_expe [LEN_RECD], cchar a_retn [LEN_FULL], char a_share, char a_mark, char a_stage [LEN_SHORT], char *r_cshare)
{
   char        rce         =  -10;
   --rce;  if (a_conv   == NULL)  return rce;
   --rce;  if (a_verb   == NULL)  return rce;
   --rce;  if (a_desc   == NULL)  return rce;
   --rce;  if (a_meth   == NULL)  return rce;
   --rce;  if (a_args   == NULL)  return rce;
   --rce;  if (a_test   == NULL)  return rce;
   --rce;  if (a_expe   == NULL)  return rce;
   --rce;  if (a_retn   == NULL)  return rce;
   --rce;  if (a_stage  == NULL)  return rce;
   --rce;  if (r_cshare == NULL)  return rce;
   return 0;
}

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
   DEBUG_PROG   yLOG_enter   (__FUNCTION__);
   /*---(open configuration)-------------*/
   DEBUG_OUTP   yLOG_point   ("name"      , my.n_conv);
   my.f_conv = fopen (my.n_conv, "w");
   DEBUG_OUTP   yLOG_point   ("file*"     , my.f_conv);
   --rce;  if (my.f_conv == NULL) {
      DEBUG_PROG   yLOG_fatal   ("scrp file, can not open output script file");
      DEBUG_PROG   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   DEBUG_OUTP   yLOG_note    ("output script file open");
   /*---(complete)-----------------------*/
   DEBUG_PROG   yLOG_exit    (__FUNCTION__);
   return 0;
}

char         /*--> close output script file --------------[ ------ [ ------ ]-*/
CONV_close         (void)
{
   /*---(locals)-----------+-----------+-*/
   char        rc          = 0;
   char        rce         = -10;
   /*---(header)-------------------------*/
   DEBUG_PROG   yLOG_enter   (__FUNCTION__);
   /*---(close detail report)------------*/
   DEBUG_OUTP   yLOG_point   ("*f_conv", my.f_conv);
   --rce;  if (my.f_conv == NULL) {
      DEBUG_PROG   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   rc = fclose (my.f_conv);
   --rce;  if (rc != 0) {
      DEBUG_PROG   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   my.f_conv = NULL;
   /*---(complete)-----------------------*/
   DEBUG_PROG   yLOG_exit    (__FUNCTION__);
   return 0;
}

char
CONV_printf_new         (FILE *a_conv, char *a_format, ...)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   va_list     x_vlist;
   /*---(defense)------------------------*/
   --rce;  if (a_conv    == NULL)    return rce;
   --rce;  if (a_format  == NULL)    return rce;
   /*---(write)--------------------------*/
   va_start (x_vlist, a_format);
   vfprintf (a_conv, a_format, x_vlist);
   va_end   (x_vlist);
   fflush   (a_conv);
   /*---(complete)-------------------------*/
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
CONV_header_new    (cchar a_name [LEN_PATH], FILE **r_conv, char *r_cshare)
{
   char        rce         =  -10;
   char        rc          =    0;
   FILE       *x_conv      = NULL;
   /*---(default)------------------------*/
   if (r_cshare != NULL)  *r_cshare = '-';
   if (r_conv   != NULL)  *r_conv   = NULL;
   /*---(open file)----------------------*/
   rc = READ_open       (a_name, 'w', &x_conv, NULL);
   if (rc < 0 || x_conv == NULL)  return rce;
   /*---(write header)-------------------*/
   CONV_printf_new (x_conv, "#!/usr/local/bin/koios\n");
   CONV_printf_new (x_conv, "#   %s\n", P_ONELINE);
   /*---(default globals)----------------*/
   my.nscrp  = 0;
   my.ncond  = my.scond = 0;
   my.nstep  = my.sstep = my.cstep = 0;
   /*---(save-back)----------------------*/
   if (r_conv   != NULL)  *r_conv   = x_conv;
   /*---(complete)-----------------------*/
   return 0;
}

char
CONV_break_new     (FILE *a_conv)
{
   /*---(output)-------------------------*/
   CONV_printf_new (a_conv, "\n\n\n");
   CONV_printf_new (a_conv, "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-123456789- \n");
   CONV_printf_new (a_conv, "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  ========(var)======= \n");
   return 0;
}

char
CONV_prep_new      (FILE *a_conv, cchar a_verb [LEN_LABEL], cchar a_desc [LEN_LONG], cchar a_meth [LEN_HUND], cchar a_args [LEN_FULL], cchar a_test [LEN_LABEL], cchar a_expe [LEN_RECD], cchar a_retn [LEN_FULL], char a_share, char a_mark, char a_stage [LEN_SHORT], char *r_cshare)
{
   char        rc          =    0;
   rc = CONV__defense (a_conv, a_verb, a_desc, a_meth, a_args, a_test, a_expe, a_retn, a_share, a_mark, a_stage, r_cshare);
   if (rc < 0)  return rc;
   CONV_break_new (a_conv);
   return CONV_printf_new (a_conv, "%-6.6s        %-65.65s  %s\n", a_verb, a_desc, s_suffix);
}

char
CONV_incl_new      (FILE *a_conv, cchar a_verb [LEN_LABEL], cchar a_desc [LEN_LONG], cchar a_meth [LEN_HUND], cchar a_args [LEN_FULL], cchar a_test [LEN_LABEL], cchar a_expe [LEN_RECD], cchar a_retn [LEN_FULL], char a_share, char a_mark, char a_stage [LEN_SHORT], char *r_cshare)
{
   char        rc          =    0;
   rc = CONV__defense (a_conv, a_verb, a_desc, a_meth, a_args, a_test, a_expe, a_retn, a_share, a_mark, a_stage, r_cshare);
   if (rc < 0)  return rc;
   return CONV_printf_new (a_conv, "   incl       %-35.35s  %-26.26s  %s\n", a_desc, a_meth, s_suffix);
}

char
CONV_comment_new   (FILE *a_conv, cchar a_verb [LEN_LABEL], cchar a_desc [LEN_LONG], cchar a_meth [LEN_HUND], cchar a_args [LEN_FULL], cchar a_test [LEN_LABEL], cchar a_expe [LEN_RECD], cchar a_retn [LEN_FULL], char a_share, char a_mark, char a_stage [LEN_SHORT], char *r_cshare)
{
   char        rc          =    0;
   rc = CONV__defense (a_conv, a_verb, a_desc, a_meth, a_args, a_test, a_expe, a_retn, a_share, a_mark, a_stage, r_cshare);
   if (rc < 0)  return rc;
   return CONV_printf_new (a_conv, "%s\n", a_expe);
}

char
CONV_footer_new    (FILE **b_conv)
{
   char        rce         =  -10;
   char        rc          =    0;
   --rce;  if (b_conv   == NULL)   return rce;
   --rce;  if (*b_conv  == NULL)   return rce;
   CONV_printf_new (*b_conv, "\n\n\n");
   CONV_printf_new (*b_conv, "# end-of-file.  done, finito, completare, whimper [Ï´···\n");
   return READ_close  (b_conv);
   return 0;
}

char
CONV_header        (void)
{
   /*---(output)-------------------------*/
   CONV_printf ("\n\n\n");
   CONV_printf ("#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-123456789- \n");
   CONV_printf ("#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  ========(var)======= \n");
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

char
CONV_beg           (void)
{
   return 0;
}


char
CONV_end           (void)
{
   return 0;
}



/*====================------------------------------------====================*/
/*===----                        script level                          ----===*/
/*====================------------------------------------====================*/
static void  o___SCRIPT__________o () { return; }

char
CONV__scrp_add     (cchar a_scrp, cchar a_share, char a_stage [LEN_SHORT], char r_suffix [LEN_SHORT], char r_count [LEN_LABEL], char *r_cshare)
{
   if (r_suffix != NULL)  strcpy (r_suffix, "");
   if (r_count  != NULL)  strcpy (r_count , "");
   if (a_scrp == 'y')     ++(my.nscrp);
   my.ncond = 0;
   *r_cshare = a_share;
   if (a_share  != '-')                    sprintf (r_suffix, "-%c-", a_share);
   else if (strcmp (a_stage, "") != 0)     sprintf (r_suffix, "[%-2.2s]", a_stage);
   if (a_share  == '-')   sprintf (r_count , "((%02d.---))", my.nscrp);
   else                   sprintf (r_count , "((%c%c.---))", a_share, a_share);
   return 0;
}

char
CONV_scrp_new      (FILE *a_conv, cchar a_verb [LEN_LABEL], cchar a_desc [LEN_LONG], cchar a_meth [LEN_HUND], cchar a_args [LEN_FULL], cchar a_test [LEN_LABEL], cchar a_expe [LEN_RECD], cchar a_retn [LEN_FULL], char a_share, char a_mark, char a_stage [LEN_SHORT], char *r_cshare)
{
   char        rc          =    0;
   char        x_suf       [LEN_SHORT] = "";
   char        x_cnt       [LEN_LABEL] = "";
   rc = CONV__defense (a_conv, a_verb, a_desc, a_meth, a_args, a_test, a_expe, a_retn, a_share, a_mark, a_stage, r_cshare);
   if (rc < 0)  return rc;
   CONV__scrp_add ('y', a_share, a_stage, x_suf, x_cnt, r_cshare);
   CONV_break_new (a_conv);
   return CONV_printf_new (a_conv, "%-6.6s  %-4.4s  %-65.65s  %-3.3s  %-14.14s  %-75.75s  %-10.10s  %s \n", a_verb, x_suf, a_desc, a_test, a_retn, a_meth, x_cnt, s_hund);
}

char
CONV_sect_new      (FILE *a_conv, cchar a_verb [LEN_LABEL], cchar a_desc [LEN_LONG], cchar a_meth [LEN_HUND], cchar a_args [LEN_FULL], cchar a_test [LEN_LABEL], cchar a_expe [LEN_RECD], cchar a_retn [LEN_FULL], char a_share, char a_mark, char a_stage [LEN_SHORT], char *r_cshare)
{
   char        rc          =    0;
   char        x_suf       [LEN_SHORT] = "";
   char        x_cnt       [LEN_LABEL] = "";
   rc = CONV__defense (a_conv, a_verb, a_desc, a_meth, a_args, a_test, a_expe, a_retn, a_share, a_mark, a_stage, r_cshare);
   if (rc < 0)  return rc;
   CONV__scrp_add ('y', a_share, a_stage, x_suf, x_cnt, r_cshare);
   CONV_break_new (a_conv);
   return CONV_printf_new (a_conv, "%-6.6s        %-65.65s  %s\n", a_verb, a_desc, s_suffix);
}

char
CONV_shared_new    (FILE *a_conv, cchar a_verb [LEN_LABEL], cchar a_desc [LEN_LONG], cchar a_meth [LEN_HUND], cchar a_args [LEN_FULL], cchar a_test [LEN_LABEL], cchar a_expe [LEN_RECD], cchar a_retn [LEN_FULL], char a_share, char a_mark, char a_stage [LEN_SHORT], char *r_cshare)
{
   char        rc          =    0;
   char        x_suf       [LEN_SHORT] = "";
   char        x_cnt       [LEN_LABEL] = "";
   rc = CONV__defense (a_conv, a_verb, a_desc, a_meth, a_args, a_test, a_expe, a_retn, a_share, a_mark, a_stage, r_cshare);
   if (rc < 0)  return rc;
   CONV__scrp_add ('y', a_share, a_stage, x_suf, x_cnt, r_cshare);
   CONV_break_new (a_conv);
   return CONV_printf_new (a_conv, "%-6.6s   %-3.3s  %-65.65s  %-3.3s  %-14.14s  %-75.75s  %-10.10s  %s \n", a_verb, x_suf, a_desc, a_test, a_retn, a_meth, x_cnt, s_hund);
}

char
CONV_global_new    (FILE *a_conv, cchar a_verb [LEN_LABEL], cchar a_desc [LEN_LONG], cchar a_meth [LEN_HUND], cchar a_args [LEN_FULL], cchar a_test [LEN_LABEL], cchar a_expe [LEN_RECD], cchar a_retn [LEN_FULL], char a_share, char a_mark, char a_stage [LEN_SHORT], char *r_cshare)
{
   char        rc          =    0;
   char        x_suf       [LEN_SHORT] = "";
   char        x_cnt       [LEN_LABEL] = "";
   rc = CONV__defense (a_conv, a_verb, a_desc, a_meth, a_args, a_test, a_expe, a_retn, a_share, a_mark, a_stage, r_cshare);
   if (rc < 0)  return rc;
   CONV__scrp_add ('y', a_share, a_stage, x_suf, x_cnt, r_cshare);
   CONV_break_new (a_conv);
   return CONV_printf_new (a_conv, "%-6.6s   %-3.3s  %-65.65s  %-3.3s  %-14.14s  %-75.75s  %-10.10s  %s \n", a_verb, x_suf, a_desc, a_test, a_retn, a_meth, x_cnt, s_hund);
}

char         /*--> write a script entry ------------------[--------[--------]-*/
CONV_scrp          (void)
{
   char        t           [LEN_TERSE] = "";
   /*---(counters)-----------------------*/
   ++(my.nscrp);
   my.ncond  = 0;
   my.cshare = '-';
   if (strlen (my.stage) != 0)  sprintf (t, "[%s]", my.stage);
   if (strlen (my.test)  == 0)  strcpy (my.test, "0s");
   if (strlen (my.retn)  == 0)  strcpy (my.retn, "tbd");
   /*---(output)-------------------------*/
   CONV_header ();
   CONV_printf ("SCRP    %-4.4s  %-65.65s  %-3.3s  %-14.14s  %-75.75s  ((%02d.---))  %s \n", t, my.desc, my.test, my.retn, my.meth, my.nscrp, s_hund);
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
   if (strlen (my.test)  == 0)  strcpy  (my.test, "0s");
   if (strlen (my.retn)  == 0)  strcpy  (my.retn, "tbd");
   if (strlen (my.meth)  == 0)  sprintf (my.meth, "%-75.75s", s_hund);
   /*---(output)-------------------------*/
   CONV_header ();
   sprintf (t, "-%c-", my.cshare);
   sprintf (s, "((%c%c.---))", my.cshare, my.cshare);
   CONV_printf ("SHARED   %-3.3s  %-65.65s  %-3.3s  %-14.14s  %-75.75s  %-10.10s  %s \n", t, my.desc, my.test, my.retn, my.meth, s, s_hund);
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
   if (strlen (my.test)  == 0)  strcpy  (my.test, "0s");
   if (strlen (my.retn)  == 0)  strcpy  (my.retn, "tbd");
   if (strlen (my.meth)  == 0)  sprintf (my.meth, "%-75.75s", s_hund);
   /*---(output)-------------------------*/
   CONV_header ();
   sprintf (t, "-%c-", my.cshare);
   sprintf (s, "((%c%c.---))", my.cshare, my.cshare);
   CONV_printf ("GLOBAL   %-3.3s  %-65.65s  %-3.3s  %-14.14s  %-75.75s  %-10.10s  %s \n", t, my.desc, my.test, my.retn, my.meth, s, s_hund);
   /*---(complete)-----------------------*/
   return 0;
}



/*====================------------------------------------====================*/
/*===----                      condition level                         ----===*/
/*====================------------------------------------====================*/
static void  o___CONDITION_______o () { return; }

char
CONV__cond_add     (cchar a_mark, cchar a_share, char r_suffix [LEN_SHORT], char r_count [LEN_LABEL])
{
   if (r_suffix != NULL) strcpy (r_suffix, "");
   if (r_count  != NULL) strcpy (r_count , "");
   ++(my.ncond);
   if (a_mark   != '-')  sprintf (r_suffix, "(%c)", a_mark);
   if (a_share  == '-')  sprintf (r_count , "((%02d.%03d))", my.nscrp, my.ncond);
   else                  sprintf (r_count , "((%c%c.%03d))", a_share, a_share, my.ncond);
   return 0;
}

char
CONV_cond_new      (FILE *a_conv, cchar a_verb [LEN_LABEL], cchar a_desc [LEN_LONG], cchar a_meth [LEN_HUND], cchar a_args [LEN_FULL], cchar a_test [LEN_LABEL], cchar a_expe [LEN_RECD], cchar a_retn [LEN_FULL], char a_share, char a_mark, char a_stage [LEN_SHORT], char *r_cshare)
{
   char        rc          =    0;
   char        x_suf       [LEN_SHORT] = "";
   char        x_cnt       [LEN_LABEL] = "";
   rc = CONV__defense (a_conv, a_verb, a_desc, a_meth, a_args, a_test, a_expe, a_retn, a_share, a_mark, a_stage, r_cshare);
   if (rc < 0)  return rc;
   CONV__cond_add (a_mark, a_share, x_suf, x_cnt);
   return CONV_printf_new (a_conv, "\n   %-5.5s %-3.3s  %-65.65s  %s  %-10.10s  %s \n", a_verb, x_suf, a_desc, s_hund, x_cnt, s_hund);
}

char
CONV_ditto_new     (FILE *a_conv, cchar a_verb [LEN_LABEL], cchar a_desc [LEN_LONG], cchar a_meth [LEN_HUND], cchar a_args [LEN_FULL], cchar a_test [LEN_LABEL], cchar a_expe [LEN_RECD], cchar a_retn [LEN_FULL], char a_share, char a_mark, char a_stage [LEN_SHORT], char *r_cshare)
{
   char        rc          =    0;
   char        x_suf       [LEN_SHORT] = "";
   char        x_cnt       [LEN_LABEL] = "   ";
   rc = CONV__defense (a_conv, a_verb, a_desc, a_meth, a_args, a_test, a_expe, a_retn, a_share, a_mark, a_stage, r_cshare);
   if (rc < 0)  return rc;
   CONV__cond_add (a_mark, a_share, x_suf, x_cnt);
   return CONV_printf_new (a_conv, "\n   %-5.5s %-3.3s  %-65.65s  %s  %-10.10s  %s \n", a_verb, x_suf, a_desc, s_hund, x_cnt, s_hund);
}

char
CONV_reuse_new     (FILE *a_conv, cchar a_verb [LEN_LABEL], cchar a_desc [LEN_LONG], cchar a_meth [LEN_HUND], cchar a_args [LEN_FULL], cchar a_test [LEN_LABEL], cchar a_expe [LEN_RECD], cchar a_retn [LEN_FULL], char a_share, char a_mark, char a_stage [LEN_SHORT], char *r_cshare)
{
   char        rc          =    0;
   char        x_suf       [LEN_SHORT] = "";
   char        x_cnt       [LEN_LABEL] = "   ";
   rc = CONV__defense (a_conv, a_verb, a_desc, a_meth, a_args, a_test, a_expe, a_retn, a_share, a_mark, a_stage, r_cshare);
   if (rc < 0)  return rc;
   CONV__cond_add (a_mark, a_share, x_suf, x_cnt);
   return CONV_printf_new (a_conv, "\n   %-5.5s %-3.3s  %-65.65s  %s  %-10.10s  %s \n", a_verb, x_suf, a_desc, s_hund, x_cnt, s_hund);
}

char
CONV_group_new     (FILE *a_conv, cchar a_verb [LEN_LABEL], cchar a_desc [LEN_LONG], cchar a_meth [LEN_HUND], cchar a_args [LEN_FULL], cchar a_test [LEN_LABEL], cchar a_expe [LEN_RECD], cchar a_retn [LEN_FULL], char a_share, char a_mark, char a_stage [LEN_SHORT], char *r_cshare)
{
   char        rc          =    0;
   rc = CONV__defense (a_conv, a_verb, a_desc, a_meth, a_args, a_test, a_expe, a_retn, a_share, a_mark, a_stage, r_cshare);
   if (rc < 0)  return rc;
   return CONV_printf_new (a_conv, "\n   %-5.5s      %-65.65s  %s\n", a_verb, a_desc, s_suffix);
}

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
   /*---(locals)-----------+-----+-----+-*/
   char        s           [LEN_LABEL] = "";
   char        t           [LEN_HUND ] = "";
   /*---(output)-------------------------*/
   sprintf (s, "-%c-", my.share);
   if (strcmp (my.desc, "") == 0) strlcpy (t, "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -", LEN_HUND);
   else                           sprintf (t, my.desc, LEN_HUND);
   CONV_printf ("\n   REUSE %-3.3s  %-65.65s  %s\n", s, t, s_suffix);
   /*---(complete)-----------------------*/
   return 0;
}



/*====================------------------------------------====================*/
/*===----                         step level                           ----===*/
/*====================------------------------------------====================*/
static void  o___STEPS___________o () { return; }

char
CONV_exec_new      (FILE *a_conv, cchar a_verb [LEN_LABEL], cchar a_desc [LEN_LONG], cchar a_meth [LEN_HUND], cchar a_args [LEN_FULL], cchar a_test [LEN_LABEL], cchar a_expe [LEN_RECD], cchar a_retn [LEN_FULL], char a_share, char a_mark, char a_stage [LEN_SHORT], char *r_cshare)
{
   char        rc          =    0;
   char        t           [LEN_RECD ] = "";
   rc = CONV__defense (a_conv, a_verb, a_desc, a_meth, a_args, a_test, a_expe, a_retn, a_share, a_mark, a_stage, r_cshare);
   if (rc < 0)  return rc;
   if (strcmp (a_retn, "") != 0)    sprintf (t, " %-20s ", a_retn); 
   return CONV_printf_new (a_conv, "     %-6.6s   %-35.35s  %-26.26s  %-100s  %-10.10s  %-100s %s\n", a_verb, a_desc, a_meth, a_args, a_test, a_expe, t);
}

char
CONV_load_new      (FILE *a_conv, cchar a_verb [LEN_LABEL], cchar a_desc [LEN_LONG], cchar a_meth [LEN_HUND], cchar a_args [LEN_FULL], cchar a_test [LEN_LABEL], cchar a_expe [LEN_RECD], cchar a_retn [LEN_FULL], char a_share, char a_mark, char a_stage [LEN_SHORT], char *r_cshare)
{
   char        rc          =    0;
   rc = CONV__defense (a_conv, a_verb, a_desc, a_meth, a_args, a_test, a_expe, a_retn, a_share, a_mark, a_stage, r_cshare);
   if (rc < 0)  return rc;
   return CONV_printf_new (a_conv, "     %-6.6s   %-35.35s  %-26.26s  %-218s \n", a_verb, a_desc, a_meth, a_expe);
}

char
CONV_file_new      (FILE *a_conv, cchar a_verb [LEN_LABEL], cchar a_desc [LEN_LONG], cchar a_meth [LEN_HUND], cchar a_args [LEN_FULL], cchar a_test [LEN_LABEL], cchar a_expe [LEN_RECD], cchar a_retn [LEN_FULL], char a_share, char a_mark, char a_stage [LEN_SHORT], char *r_cshare)
{
   char        rc          =    0;
   rc = CONV__defense (a_conv, a_verb, a_desc, a_meth, a_args, a_test, a_expe, a_retn, a_share, a_mark, a_stage, r_cshare);
   if (rc < 0)  return rc;
   return CONV_printf_new (a_conv, "     %-6.6s   %-35.35s  - - - - - - - - - - - - -   %-218s \n", a_verb, a_desc, a_expe);
}

char
CONV_append_new    (FILE *a_conv, cchar a_verb [LEN_LABEL], cchar a_desc [LEN_LONG], cchar a_meth [LEN_HUND], cchar a_args [LEN_FULL], cchar a_test [LEN_LABEL], cchar a_expe [LEN_RECD], cchar a_retn [LEN_FULL], char a_share, char a_mark, char a_stage [LEN_SHORT], char *r_cshare)
{
   char        rc          =    0;
   rc = CONV__defense (a_conv, a_verb, a_desc, a_meth, a_args, a_test, a_expe, a_retn, a_share, a_mark, a_stage, r_cshare);
   if (rc < 0)  return rc;
   return CONV_printf_new (a_conv, "     %-6.6s   %-35.35s  - - - - - - - - - - - - -   %-218s \n", a_verb, a_desc, a_expe);
}

char
CONV_mode_new      (FILE *a_conv, cchar a_verb [LEN_LABEL], cchar a_desc [LEN_LONG], cchar a_meth [LEN_HUND], cchar a_args [LEN_FULL], cchar a_test [LEN_LABEL], cchar a_expe [LEN_RECD], cchar a_retn [LEN_FULL], char a_share, char a_mark, char a_stage [LEN_SHORT], char *r_cshare)
{
   char        rc          =    0;
   rc = CONV__defense (a_conv, a_verb, a_desc, a_meth, a_args, a_test, a_expe, a_retn, a_share, a_mark, a_stage, r_cshare);
   if (rc < 0)  return rc;
   return CONV_printf_new (a_conv, "     %-6.6s   %-35.35s  - - - - - - - - - - - - -   %s\n", a_verb, a_desc, s_suffix);
}

char
CONV_code_new      (FILE *a_conv, cchar a_verb [LEN_LABEL], cchar a_desc [LEN_LONG], cchar a_meth [LEN_HUND], cchar a_args [LEN_FULL], cchar a_test [LEN_LABEL], cchar a_expe [LEN_RECD], cchar a_retn [LEN_FULL], char a_share, char a_mark, char a_stage [LEN_SHORT], char *r_cshare)
{
   char        rc          =    0;
   rc = CONV__defense (a_conv, a_verb, a_desc, a_meth, a_args, a_test, a_expe, a_retn, a_share, a_mark, a_stage, r_cshare);
   if (rc < 0)  return rc;
   return CONV_printf_new (a_conv, "     %-6.6s   %-35.35s  - - - - - - - - - - - - -   %-218s \n", a_verb, a_desc, a_expe);
}

char
CONV_gvar_new      (FILE *a_conv, cchar a_verb [LEN_LABEL], cchar a_desc [LEN_LONG], cchar a_meth [LEN_HUND], cchar a_args [LEN_FULL], cchar a_test [LEN_LABEL], cchar a_expe [LEN_RECD], cchar a_retn [LEN_FULL], char a_share, char a_mark, char a_stage [LEN_SHORT], char *r_cshare)
{
   char        rc          =    0;
   rc = CONV__defense (a_conv, a_verb, a_desc, a_meth, a_args, a_test, a_expe, a_retn, a_share, a_mark, a_stage, r_cshare);
   if (rc < 0)  return rc;
   return CONV_printf_new (a_conv, "   %-6.6s     %-35.35s  - - - - - - - - - - - - -   %-218s \n", a_verb, a_desc, a_expe);
}

char
CONV_echo_new      (FILE *a_conv, cchar a_verb [LEN_LABEL], cchar a_desc [LEN_LONG], cchar a_meth [LEN_HUND], cchar a_args [LEN_FULL], cchar a_test [LEN_LABEL], cchar a_expe [LEN_RECD], cchar a_retn [LEN_FULL], char a_share, char a_mark, char a_stage [LEN_SHORT], char *r_cshare)
{
   char        rc          =    0;
   rc = CONV__defense (a_conv, a_verb, a_desc, a_meth, a_args, a_test, a_expe, a_retn, a_share, a_mark, a_stage, r_cshare);
   if (rc < 0)  return rc;
   return CONV_printf_new (a_conv, "     %-6.6s   %-35.35s  - - - - - - - - - - - - -   %-100s  %-10.10s  %-100s \n", a_verb, a_desc, a_args, a_test, a_expe);
}




char
CONV_exec          (void)
{
   char        t           [LEN_RECD ] = "";
   sprintf (my.updated  , "     %-6.6s   %-35.35s  %-26.26s  %-100s  %-10.10s  %-100s ", my.verb, my.desc, my.meth, my.args, my.test, my.expe);
   if (strcmp (my.retn, "") != 0) {
      sprintf (t           , " %-20s ", my.retn); 
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
CONV_file          (void)
{
   CONV_printf ("     %-6.6s   %-35.35s  - - - - - - - - - - - - -   %-218s \n", my.verb, my.desc, my.code);
   return 0;
}

char
CONV_append        (void)
{
   CONV_printf ("     %-6.6s   %-35.35s  - - - - - - - - - - - - -   %-218s \n", my.verb, my.desc, my.code);
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
CONV_gvar          (void)
{
   CONV_printf ("   global     %-35.35s  - - - - - - - - - - - - -   %-218s \n", my.desc, my.code);
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
CONV_driver        (void f_call (), FILE *a_conv, cchar a_verb [LEN_LABEL], cchar a_desc [LEN_LONG], cchar a_meth [LEN_HUND], cchar a_args [LEN_FULL], cchar a_test [LEN_LABEL], cchar a_expe [LEN_RECD], cchar a_retn [LEN_FULL], char a_share, char a_mark, char a_stage [LEN_SHORT], char *r_cshare)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char      (*x_func) (FILE *a_conv, cchar a_verb [LEN_LABEL], cchar a_desc [LEN_LONG], cchar a_meth [LEN_HUND], cchar a_args [LEN_FULL], cchar a_test [LEN_LABEL], cchar a_expe [LEN_RECD], cchar a_retn [LEN_FULL], char a_share, char a_mark, char a_stage [LEN_SHORT], char *r_cshare);
   /*---(header)-------------------------*/
   DEBUG_PROG   yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   DEBUG_PROG   yLOG_point   ("f_call"    , f_call);
   --rce;  if (f_call == NULL) {
      DEBUG_PROG   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(prepare)------------------------*/
   x_func = f_call;
   /*---(call function)------------------*/
   rc = x_func (a_conv, a_verb, a_desc, a_meth, a_args, a_test, a_expe, a_retn, a_share, a_mark, a_stage, r_cshare);
   DEBUG_PROG   yLOG_value   ("call"      , rc);
   --rce;  if (rc < 0) {
      DEBUG_PROG   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(complete)-----------------------*/
   DEBUG_PROG   yLOG_exit    (__FUNCTION__);
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
