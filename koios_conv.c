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


static int  s_nscrp  = 0;
static int  s_ncond  = 0;




/*====================------------------------------------====================*/
/*===----                       general functions                      ----===*/
/*====================------------------------------------====================*/
static void  o___OVERALL_________o () { return; }

char
CONV__defense           (FILE *a_conv, cchar a_verb [LEN_LABEL], cchar a_desc [LEN_LONG], cchar a_meth [LEN_HUND], cchar a_args [LEN_FULL], cchar a_test [LEN_LABEL], cchar a_expe [LEN_RECD], cchar a_retn [LEN_FULL], char a_share, char a_mark, char a_stage [LEN_SHORT], char *r_cshare)
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

char
CONV_printf             (FILE *a_conv, char *a_format, ...)
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
CONV_init               (void)
{
   s_nscrp = s_ncond = 0;
   return 0;
}



/*====================------------------------------------====================*/
/*===----                         preparations                         ----===*/
/*====================------------------------------------====================*/
static void  o___PREP____________o () { return; }

char
CONV_header             (cchar a_name [LEN_PATH], FILE **r_conv, char *r_cshare)
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
   CONV_printf (x_conv, "#!/usr/local/bin/koios\n");
   CONV_printf (x_conv, "#   %s\n", P_ONELINE);
   /*---(default globals)----------------*/
   s_nscrp  = 0;
   s_ncond  = 0;
   /*---(save-back)----------------------*/
   if (r_conv   != NULL)  *r_conv   = x_conv;
   /*---(complete)-----------------------*/
   return 0;
}

char
CONV_break              (FILE *a_conv)
{
   /*---(output)-------------------------*/
   CONV_printf (a_conv, "\n\n\n");
   CONV_printf (a_conv, "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-123456789- \n");
   CONV_printf (a_conv, "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  ========(var)======= \n");
   return 0;
}

char
CONV_prep               (FILE *a_conv, cchar a_verb [LEN_LABEL], cchar a_desc [LEN_LONG], cchar a_meth [LEN_HUND], cchar a_args [LEN_FULL], cchar a_test [LEN_LABEL], cchar a_expe [LEN_RECD], cchar a_retn [LEN_FULL], char a_share, char a_mark, char a_stage [LEN_SHORT], char *r_cshare)
{
   char        rc          =    0;
   rc = CONV__defense (a_conv, a_verb, a_desc, a_meth, a_args, a_test, a_expe, a_retn, a_share, a_mark, a_stage, r_cshare);
   if (rc < 0)  return rc;
   CONV_break     (a_conv);
   return CONV_printf (a_conv, "%-6.6s        %-65.65s  %s\n", a_verb, a_desc, s_suffix);
}

char
CONV_incl               (FILE *a_conv, cchar a_verb [LEN_LABEL], cchar a_desc [LEN_LONG], cchar a_meth [LEN_HUND], cchar a_args [LEN_FULL], cchar a_test [LEN_LABEL], cchar a_expe [LEN_RECD], cchar a_retn [LEN_FULL], char a_share, char a_mark, char a_stage [LEN_SHORT], char *r_cshare)
{
   char        rc          =    0;
   rc = CONV__defense (a_conv, a_verb, a_desc, a_meth, a_args, a_test, a_expe, a_retn, a_share, a_mark, a_stage, r_cshare);
   if (rc < 0)  return rc;
   return CONV_printf (a_conv, "   incl       %-35.35s  %-26.26s  %s\n", a_desc, a_meth, s_suffix);
}

char
CONV_comment            (FILE *a_conv, cchar a_verb [LEN_LABEL], cchar a_desc [LEN_LONG], cchar a_meth [LEN_HUND], cchar a_args [LEN_FULL], cchar a_test [LEN_LABEL], cchar a_expe [LEN_RECD], cchar a_retn [LEN_FULL], char a_share, char a_mark, char a_stage [LEN_SHORT], char *r_cshare)
{
   char        rc          =    0;
   rc = CONV__defense (a_conv, a_verb, a_desc, a_meth, a_args, a_test, a_expe, a_retn, a_share, a_mark, a_stage, r_cshare);
   if (rc < 0)  return rc;
   return CONV_printf (a_conv, "%s\n", a_expe);
}

char
CONV_footer             (FILE **b_conv)
{
   char        rce         =  -10;
   char        rc          =    0;
   --rce;  if (b_conv   == NULL)   return rce;
   --rce;  if (*b_conv  == NULL)   return rce;
   CONV_printf (*b_conv, "\n\n\n");
   CONV_printf (*b_conv, "# end-of-file.  done, finito, completare, whimper [Ï´···\n");
   return READ_close  (b_conv);
   return 0;
}



/*====================------------------------------------====================*/
/*===----                        script level                          ----===*/
/*====================------------------------------------====================*/
static void  o___SCRIPT__________o () { return; }

char
CONV__scrp_add          (cchar a_scrp, cchar a_share, char a_stage [LEN_SHORT], char r_suffix [LEN_SHORT], char r_count [LEN_LABEL], char *r_cshare)
{
   /*> printf ("%4d nscrp, %4d ncond\n", s_nscrp, s_ncond);                           <*/
   if (r_suffix != NULL)  strcpy (r_suffix, "");
   if (r_count  != NULL)  strcpy (r_count , "");
   if (a_scrp == 'y')     ++(s_nscrp);
   s_ncond = 0;
   /*> printf ("%4d nscrp, %4d ncond\n", s_nscrp, s_ncond);                           <*/
   *r_cshare = a_share;
   if (a_share  != '-')                    sprintf (r_suffix, "-%c-", a_share);
   else if (strcmp (a_stage, "") != 0)     sprintf (r_suffix, "[%-2.2s]", a_stage);
   if (a_share  == '-')   sprintf (r_count , "((%02d.---))", s_nscrp);
   else                   sprintf (r_count , "((%c%c.---))", a_share, a_share);
   return 0;
}

char
CONV_scrp               (FILE *a_conv, cchar a_verb [LEN_LABEL], cchar a_desc [LEN_LONG], cchar a_meth [LEN_HUND], cchar a_args [LEN_FULL], cchar a_test [LEN_LABEL], cchar a_expe [LEN_RECD], cchar a_retn [LEN_FULL], char a_share, char a_mark, char a_stage [LEN_SHORT], char *r_cshare)
{
   char        rc          =    0;
   char        x_suf       [LEN_SHORT] = "";
   char        x_cnt       [LEN_LABEL] = "";
   rc = CONV__defense (a_conv, a_verb, a_desc, a_meth, a_args, a_test, a_expe, a_retn, a_share, a_mark, a_stage, r_cshare);
   if (rc < 0)  return rc;
   CONV__scrp_add ('y', a_share, a_stage, x_suf, x_cnt, r_cshare);
   CONV_break     (a_conv);
   return CONV_printf (a_conv, "%-6.6s  %-4.4s  %-65.65s  %-3.3s  %-14.14s  %-75.75s  %-10.10s  %s \n", a_verb, x_suf, a_desc, a_test, a_retn, a_meth, x_cnt, s_hund);
}

char
CONV_sect               (FILE *a_conv, cchar a_verb [LEN_LABEL], cchar a_desc [LEN_LONG], cchar a_meth [LEN_HUND], cchar a_args [LEN_FULL], cchar a_test [LEN_LABEL], cchar a_expe [LEN_RECD], cchar a_retn [LEN_FULL], char a_share, char a_mark, char a_stage [LEN_SHORT], char *r_cshare)
{
   char        rc          =    0;
   char        x_suf       [LEN_SHORT] = "";
   char        x_cnt       [LEN_LABEL] = "";
   rc = CONV__defense (a_conv, a_verb, a_desc, a_meth, a_args, a_test, a_expe, a_retn, a_share, a_mark, a_stage, r_cshare);
   if (rc < 0)  return rc;
   CONV__scrp_add ('y', a_share, a_stage, x_suf, x_cnt, r_cshare);
   CONV_break     (a_conv);
   return CONV_printf (a_conv, "%-6.6s        %-65.65s  %s\n", a_verb, a_desc, s_suffix);
}

char
CONV_shared             (FILE *a_conv, cchar a_verb [LEN_LABEL], cchar a_desc [LEN_LONG], cchar a_meth [LEN_HUND], cchar a_args [LEN_FULL], cchar a_test [LEN_LABEL], cchar a_expe [LEN_RECD], cchar a_retn [LEN_FULL], char a_share, char a_mark, char a_stage [LEN_SHORT], char *r_cshare)
{
   char        rc          =    0;
   char        x_suf       [LEN_SHORT] = "";
   char        x_cnt       [LEN_LABEL] = "";
   rc = CONV__defense (a_conv, a_verb, a_desc, a_meth, a_args, a_test, a_expe, a_retn, a_share, a_mark, a_stage, r_cshare);
   if (rc < 0)  return rc;
   CONV__scrp_add ('y', a_share, a_stage, x_suf, x_cnt, r_cshare);
   CONV_break     (a_conv);
   return CONV_printf (a_conv, "%-6.6s   %-3.3s  %-65.65s  %-3.3s  %-14.14s  %-75.75s  %-10.10s  %s \n", a_verb, x_suf, a_desc, a_test, a_retn, a_meth, x_cnt, s_hund);
}

char
CONV_global             (FILE *a_conv, cchar a_verb [LEN_LABEL], cchar a_desc [LEN_LONG], cchar a_meth [LEN_HUND], cchar a_args [LEN_FULL], cchar a_test [LEN_LABEL], cchar a_expe [LEN_RECD], cchar a_retn [LEN_FULL], char a_share, char a_mark, char a_stage [LEN_SHORT], char *r_cshare)
{
   char        rc          =    0;
   char        x_suf       [LEN_SHORT] = "";
   char        x_cnt       [LEN_LABEL] = "";
   rc = CONV__defense (a_conv, a_verb, a_desc, a_meth, a_args, a_test, a_expe, a_retn, a_share, a_mark, a_stage, r_cshare);
   if (rc < 0)  return rc;
   CONV__scrp_add ('y', a_share, a_stage, x_suf, x_cnt, r_cshare);
   CONV_break     (a_conv);
   return CONV_printf (a_conv, "%-6.6s   %-3.3s  %-65.65s  %-3.3s  %-14.14s  %-75.75s  %-10.10s  %s \n", a_verb, x_suf, a_desc, a_test, a_retn, a_meth, x_cnt, s_hund);
}



/*====================------------------------------------====================*/
/*===----                      condition level                         ----===*/
/*====================------------------------------------====================*/
static void  o___CONDITION_______o () { return; }

char
CONV__cond_add          (cchar a_mark, cchar a_share, char r_suffix [LEN_SHORT], char r_count [LEN_LABEL])
{
   /*---(defaults)-----------------------*/
   if (r_suffix != NULL) strcpy (r_suffix, "");
   if (r_count  != NULL) strcpy (r_count , "");
   /*---(update conds)-------------------*/
   ++(s_ncond);
   /*---(verb suffixes)------------------*/
   if      (a_mark   != '-')  sprintf (r_suffix, "(%c)", a_mark);
   else if (a_share  != '-')  sprintf (r_suffix, "-%c-", a_share);
   /*---(line numbering)-----------------*/
   if (a_share  == '-')       sprintf (r_count , "((%02d.%03d))", s_nscrp, s_ncond);
   else                       sprintf (r_count , "((%c%c.%03d))", a_share, a_share, s_ncond);
   /*---(complete)-----------------------*/
   return 0;
}

char
CONV_cond               (FILE *a_conv, cchar a_verb [LEN_LABEL], cchar a_desc [LEN_LONG], cchar a_meth [LEN_HUND], cchar a_args [LEN_FULL], cchar a_test [LEN_LABEL], cchar a_expe [LEN_RECD], cchar a_retn [LEN_FULL], char a_share, char a_mark, char a_stage [LEN_SHORT], char *r_cshare)
{
   char        rc          =    0;
   char        x_suf       [LEN_SHORT] = "";
   char        x_cnt       [LEN_LABEL] = "";
   rc = CONV__defense (a_conv, a_verb, a_desc, a_meth, a_args, a_test, a_expe, a_retn, a_share, a_mark, a_stage, r_cshare);
   if (rc < 0)  return rc;
   CONV__cond_add (a_mark, a_share, x_suf, x_cnt);
   return CONV_printf (a_conv, "\n   %-5.5s %-3.3s  %-65.65s  %s  %-10.10s  %s \n", a_verb, x_suf, a_desc, s_hund, x_cnt, s_hund);
}

char
CONV_ditto              (FILE *a_conv, cchar a_verb [LEN_LABEL], cchar a_desc [LEN_LONG], cchar a_meth [LEN_HUND], cchar a_args [LEN_FULL], cchar a_test [LEN_LABEL], cchar a_expe [LEN_RECD], cchar a_retn [LEN_FULL], char a_share, char a_mark, char a_stage [LEN_SHORT], char *r_cshare)
{
   char        rc          =    0;
   char        x_suf       [LEN_SHORT] = "";
   char        x_cnt       [LEN_LABEL] = "   ";
   rc = CONV__defense (a_conv, a_verb, a_desc, a_meth, a_args, a_test, a_expe, a_retn, a_share, a_mark, a_stage, r_cshare);
   if (rc < 0)  return rc;
   CONV__cond_add (a_mark, a_share, x_suf, x_cnt);
   return CONV_printf (a_conv, "\n   %-5.5s %-3.3s  %-65.65s  %s  %-10.10s  %s \n", a_verb, x_suf, a_desc, s_hund, x_cnt, s_hund);
}

char
CONV_reuse              (FILE *a_conv, cchar a_verb [LEN_LABEL], cchar a_desc [LEN_LONG], cchar a_meth [LEN_HUND], cchar a_args [LEN_FULL], cchar a_test [LEN_LABEL], cchar a_expe [LEN_RECD], cchar a_retn [LEN_FULL], char a_share, char a_mark, char a_stage [LEN_SHORT], char *r_cshare)
{
   char        rc          =    0;
   char        x_suf       [LEN_SHORT] = "";
   char        x_cnt       [LEN_LABEL] = "   ";
   rc = CONV__defense (a_conv, a_verb, a_desc, a_meth, a_args, a_test, a_expe, a_retn, a_share, a_mark, a_stage, r_cshare);
   if (rc < 0)  return rc;
   CONV__cond_add (a_mark, a_share, x_suf, x_cnt);
   return CONV_printf (a_conv, "\n   %-5.5s %-3.3s  %-65.65s  %s  %-10.10s  %s \n", a_verb, x_suf, a_desc, s_hund, x_cnt, s_hund);
}

char
CONV_group              (FILE *a_conv, cchar a_verb [LEN_LABEL], cchar a_desc [LEN_LONG], cchar a_meth [LEN_HUND], cchar a_args [LEN_FULL], cchar a_test [LEN_LABEL], cchar a_expe [LEN_RECD], cchar a_retn [LEN_FULL], char a_share, char a_mark, char a_stage [LEN_SHORT], char *r_cshare)
{
   char        rc          =    0;
   rc = CONV__defense (a_conv, a_verb, a_desc, a_meth, a_args, a_test, a_expe, a_retn, a_share, a_mark, a_stage, r_cshare);
   if (rc < 0)  return rc;
   return CONV_printf (a_conv, "\n   %-5.5s      %-65.65s  %s\n", a_verb, a_desc, s_suffix);
}



/*====================------------------------------------====================*/
/*===----                         step level                           ----===*/
/*====================------------------------------------====================*/
static void  o___STEPS___________o () { return; }

char
CONV_exec               (FILE *a_conv, cchar a_verb [LEN_LABEL], cchar a_desc [LEN_LONG], cchar a_meth [LEN_HUND], cchar a_args [LEN_FULL], cchar a_test [LEN_LABEL], cchar a_expe [LEN_RECD], cchar a_retn [LEN_FULL], char a_share, char a_mark, char a_stage [LEN_SHORT], char *r_cshare)
{
   char        rc          =    0;
   char        t           [LEN_RECD ] = "";
   rc = CONV__defense (a_conv, a_verb, a_desc, a_meth, a_args, a_test, a_expe, a_retn, a_share, a_mark, a_stage, r_cshare);
   if (rc < 0)  return rc;
   if (strcmp (a_retn, "") != 0)    sprintf (t, " %-20s ", a_retn); 
   return CONV_printf (a_conv, "     %-6.6s   %-35.35s  %-26.26s  %-100s  %-10.10s  %-100s %s\n", a_verb, a_desc, a_meth, a_args, a_test, a_expe, t);
}

char
CONV_load               (FILE *a_conv, cchar a_verb [LEN_LABEL], cchar a_desc [LEN_LONG], cchar a_meth [LEN_HUND], cchar a_args [LEN_FULL], cchar a_test [LEN_LABEL], cchar a_expe [LEN_RECD], cchar a_retn [LEN_FULL], char a_share, char a_mark, char a_stage [LEN_SHORT], char *r_cshare)
{
   char        rc          =    0;
   rc = CONV__defense (a_conv, a_verb, a_desc, a_meth, a_args, a_test, a_expe, a_retn, a_share, a_mark, a_stage, r_cshare);
   if (rc < 0)  return rc;
   return CONV_printf (a_conv, "     %-6.6s   %-35.35s  %-26.26s  %-218s \n", a_verb, a_desc, a_meth, a_expe);
}

char
CONV_file               (FILE *a_conv, cchar a_verb [LEN_LABEL], cchar a_desc [LEN_LONG], cchar a_meth [LEN_HUND], cchar a_args [LEN_FULL], cchar a_test [LEN_LABEL], cchar a_expe [LEN_RECD], cchar a_retn [LEN_FULL], char a_share, char a_mark, char a_stage [LEN_SHORT], char *r_cshare)
{
   char        rc          =    0;
   rc = CONV__defense (a_conv, a_verb, a_desc, a_meth, a_args, a_test, a_expe, a_retn, a_share, a_mark, a_stage, r_cshare);
   if (rc < 0)  return rc;
   return CONV_printf (a_conv, "     %-6.6s   %-35.35s  - - - - - - - - - - - - -   %-218s \n", a_verb, a_desc, a_expe);
}

char
CONV_append             (FILE *a_conv, cchar a_verb [LEN_LABEL], cchar a_desc [LEN_LONG], cchar a_meth [LEN_HUND], cchar a_args [LEN_FULL], cchar a_test [LEN_LABEL], cchar a_expe [LEN_RECD], cchar a_retn [LEN_FULL], char a_share, char a_mark, char a_stage [LEN_SHORT], char *r_cshare)
{
   char        rc          =    0;
   rc = CONV__defense (a_conv, a_verb, a_desc, a_meth, a_args, a_test, a_expe, a_retn, a_share, a_mark, a_stage, r_cshare);
   if (rc < 0)  return rc;
   return CONV_printf (a_conv, "     %-6.6s   %-35.35s  - - - - - - - - - - - - -   %-218s \n", a_verb, a_desc, a_expe);
}

char
CONV_mode               (FILE *a_conv, cchar a_verb [LEN_LABEL], cchar a_desc [LEN_LONG], cchar a_meth [LEN_HUND], cchar a_args [LEN_FULL], cchar a_test [LEN_LABEL], cchar a_expe [LEN_RECD], cchar a_retn [LEN_FULL], char a_share, char a_mark, char a_stage [LEN_SHORT], char *r_cshare)
{
   char        rc          =    0;
   rc = CONV__defense (a_conv, a_verb, a_desc, a_meth, a_args, a_test, a_expe, a_retn, a_share, a_mark, a_stage, r_cshare);
   if (rc < 0)  return rc;
   return CONV_printf (a_conv, "     %-6.6s   %-35.35s  - - - - - - - - - - - - -   %s\n", a_verb, a_desc, s_suffix);
}

char
CONV_code               (FILE *a_conv, cchar a_verb [LEN_LABEL], cchar a_desc [LEN_LONG], cchar a_meth [LEN_HUND], cchar a_args [LEN_FULL], cchar a_test [LEN_LABEL], cchar a_expe [LEN_RECD], cchar a_retn [LEN_FULL], char a_share, char a_mark, char a_stage [LEN_SHORT], char *r_cshare)
{
   char        rc          =    0;
   rc = CONV__defense (a_conv, a_verb, a_desc, a_meth, a_args, a_test, a_expe, a_retn, a_share, a_mark, a_stage, r_cshare);
   if (rc < 0)  return rc;
   return CONV_printf (a_conv, "     %-6.6s   %-35.35s  - - - - - - - - - - - - -   %-218s \n", a_verb, a_desc, a_expe);
}

char
CONV_gvar               (FILE *a_conv, cchar a_verb [LEN_LABEL], cchar a_desc [LEN_LONG], cchar a_meth [LEN_HUND], cchar a_args [LEN_FULL], cchar a_test [LEN_LABEL], cchar a_expe [LEN_RECD], cchar a_retn [LEN_FULL], char a_share, char a_mark, char a_stage [LEN_SHORT], char *r_cshare)
{
   char        rc          =    0;
   rc = CONV__defense (a_conv, a_verb, a_desc, a_meth, a_args, a_test, a_expe, a_retn, a_share, a_mark, a_stage, r_cshare);
   if (rc < 0)  return rc;
   return CONV_printf (a_conv, "   %-6.6s     %-35.35s  - - - - - - - - - - - - -   %-218s \n", a_verb, a_desc, a_expe);
}

char
CONV_echo               (FILE *a_conv, cchar a_verb [LEN_LABEL], cchar a_desc [LEN_LONG], cchar a_meth [LEN_HUND], cchar a_args [LEN_FULL], cchar a_test [LEN_LABEL], cchar a_expe [LEN_RECD], cchar a_retn [LEN_FULL], char a_share, char a_mark, char a_stage [LEN_SHORT], char *r_cshare)
{
   char        rc          =    0;
   rc = CONV__defense (a_conv, a_verb, a_desc, a_meth, a_args, a_test, a_expe, a_retn, a_share, a_mark, a_stage, r_cshare);
   if (rc < 0)  return rc;
   return CONV_printf (a_conv, "     %-6.6s   %-35.35s  - - - - - - - - - - - - -   %-100s  %-10.10s  %-100s \n", a_verb, a_desc, a_args, a_test, a_expe);
}



/*====================------------------------------------====================*/
/*===----                          main driver                         ----===*/
/*====================------------------------------------====================*/
static void  o___DRIVER__________o () { return; }

char
CONV_driver             (void f_call (), FILE *a_conv, cchar a_verb [LEN_LABEL], cchar a_desc [LEN_LONG], cchar a_meth [LEN_HUND], cchar a_args [LEN_FULL], cchar a_test [LEN_LABEL], cchar a_expe [LEN_RECD], cchar a_retn [LEN_FULL], char a_share, char a_mark, char a_stage [LEN_SHORT], char *r_cshare)
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
/*===----                    unit testing helpers                      ----===*/
/*====================------------------------------------====================*/
static void  o___UNITEST_________o () { return; }

char
CONV_force              (int a_scrps, int  a_conds)
{
   CONV_init ();
   s_nscrp = a_scrps;
   s_ncond = a_conds;
   /*> printf ("%4d nscrp, %4d ncond\n", s_nscrp, s_ncond);                           <*/
   return 0;
}



/*===============================[[ end code ]]===============================*/
