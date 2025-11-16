/*===============================[[ beg-code ]]===============================*/
#include    "koios.h"        /* LOCAL  : main header                          */


/*> head -n -1 unit_head.unit | cksum -a sha1   --untagged                               <*/
/*> ec4d94a02fc5f3fbfb33e22928aed70dc0f790ef  -                                       <*/

/*> # end-of-file.  done, finito, completare, whimper [Ï´···                          <* 
 *> # SHA1 quick check åec4d94a02fc5f3fbfb33e22928aed70dc0f790efæ                     <*/

static char *s_suffix = "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ";
static char *s_hund   = "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ";



static int  s_cunit  = 0;
static int  s_cscrp  = 0;
static int  s_ccond  = 0;
static int  s_cstep  = 0;



/*====================------------------------------------====================*/
/*===----                       general functions                      ----===*/
/*====================------------------------------------====================*/
static void  o___OVERALL_________o () { return; }

char
CONV__defense           (FILE *a_conv, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_major, char a_minor, char *b_share, char *b_select)
{
   char        rce         =  -10;
   --rce;  if (a_conv   == NULL)  return rce;
   --rce;  if (a_verb   == NULL)  return rce;
   --rce;  if (a_desc   == NULL)  return rce;
   --rce;  if (a_method == NULL)  return rce;
   --rce;  if (a_args   == NULL)  return rce;
   --rce;  if (a_test   == NULL)  return rce;
   --rce;  if (a_expect == NULL)  return rce;
   --rce;  if (a_return == NULL)  return rce;
   --rce;  if (a_stage  == NULL)  return rce;
   --rce;  if (a_which  == NULL)  return rce;
   --rce;  if (a_ditto  == 0)     return rce;
   --rce;  if (a_major  == 0)     return rce;
   --rce;  if (a_minor  == 0)     return rce;
   --rce;  if (b_share  == NULL)  return rce;
   --rce;  if (b_select == NULL)  return rce;
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
   yUNIT_stats_purge (YUNIT_CONVERT, &s_cunit, &s_cscrp, &s_ccond, &s_cstep);
   return 0;
}



/*====================------------------------------------====================*/
/*===----                         preparations                         ----===*/
/*====================------------------------------------====================*/
static void  o___PREP____________o () { return; }

char
CONV_header             (char a_name [LEN_PATH], FILE **r_conv, char *r_share, char *r_select)
{
   char        rce         =  -10;
   char        rc          =    0;
   FILE       *x_conv      = NULL;
   /*---(default)------------------------*/
   if (r_share  != NULL)  *r_share  = '-';
   if (r_select != NULL)  *r_select = '-';
   if (r_conv   != NULL)  *r_conv   = NULL;
   /*---(open file)----------------------*/
   rc = READ_open       (__FILE__, __FUNCTION__, __LINE__, my.cwd, a_name, 'w', &x_conv, NULL);
   if (rc < 0 || x_conv == NULL)  return rce;
   /*---(write header)-------------------*/
   CONV_printf (x_conv, "#!/usr/local/bin/koios\n");
   CONV_printf (x_conv, "#   %s\n", P_ONELINE);
   /*---(default globals)----------------*/
   CONV_init ();
   yUNIT_stats_purge (YUNIT_CONVERT, &s_cunit, &s_cscrp, &s_ccond, &s_cstep);
   /*---(save-back)----------------------*/
   if (r_conv   != NULL)  *r_conv   = x_conv;
   /*---(complete)-----------------------*/
   return 0;
}

char
CONV__break             (FILE *a_conv)
{
   /*---(output)-------------------------*/
   CONV_printf (a_conv, "\n\n\n");
   CONV_printf (a_conv, "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-123456789- \n");
   CONV_printf (a_conv, "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  ========(var)======= \n");
   return 0;
}

char
CONV__prep              (FILE *a_conv, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_major, char a_minor, char *b_share, char *b_select)
{
   char        rc          =    0;
   /*> rc = CONV__defense (a_conv, a_verb, a_desc, a_method, a_args, a_test, a_expect, a_return, a_stage, a_which, a_ditto, a_major, a_minor, b_share, b_select);   <* 
    *> if (rc < 0)  return rc;                                                                                                                                      <*/
   CONV__break    (a_conv);
   return CONV_printf (a_conv, "%-6.6s        %-65.65s  %s\n", a_verb, a_desc, s_suffix);
}

char
CONV__incl              (FILE *a_conv, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_major, char a_minor, char *b_share, char *b_select)
{
   char        rc          =    0;
   /*> rc = CONV__defense (a_conv, a_verb, a_desc, a_method, a_args, a_test, a_expect, a_return, a_stage, a_which, a_ditto, a_major, a_minor, b_share, b_select);   <* 
    *> if (rc < 0)  return rc;                                                                                                                                      <*/
   return CONV_printf (a_conv, "   incl       %-35.35s  %-26.26s  %s\n", a_desc, a_method, s_suffix);
}

char
CONV__comment           (FILE *a_conv, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_major, char a_minor, char *b_share, char *b_select)
{
   char        rc          =    0;
   /*> rc = CONV__defense (a_conv, a_verb, a_desc, a_method, a_args, a_test, a_expect, a_return, a_stage, a_which, a_ditto, a_major, a_minor, b_share, b_select);   <* 
    *> if (rc < 0)  return rc;                                                                                                                                      <*/
   return CONV_printf (a_conv, "%s\n", a_expect);
}

char
CONV_footer             (char a_good, FILE **b_conv, char a_nscrp [LEN_TITLE], char a_nconv [LEN_TITLE])
{
   char        rce         =  -10;
   char        rc          =    0;
   char        t           [LEN_HUND]  = "";
   /*---(defense)------------------------*/
   --rce;  if (b_conv   == NULL)   return rce;
   --rce;  if (*b_conv  == NULL)   return rce;
   /*---(finish stattistics)-------------*/
   yUNIT_stats_unit  (YUNIT_CONVERT, *b_conv, a_nscrp, 'U', "UNIT", '-', &s_cunit, &s_cscrp, &s_ccond, &s_cstep);
   CONV_printf (*b_conv, "\n\n\n");
   /*---(normal end-of-file)-------------*/
   CONV_printf (*b_conv, "# end-of-file.  done, finito, completare, whimper [Ï´···\n");
   READ_close (__FILE__, __FUNCTION__, __LINE__, a_nconv, b_conv);
   /*---(export globals)-----------------*/
   if (a_good == 'y') {
      IF_HEAD  REUSE_export ("unit.globals");
   }
   /*---(clean-up)-----------------------*/
   if (a_good != 'y') {
      sprintf (t, "rm -f %s", a_nconv); system  (t);
   }
   /*---(complete)-----------------------*/
   return 1;
}



/*====================------------------------------------====================*/
/*===----                        script level                          ----===*/
/*====================------------------------------------====================*/
static void  o___SCRIPT__________o () { return; }

char
CONV__scrp_add          (char a_scrp, char a_verb [LEN_LABEL], char a_major, char a_stage [LEN_SHORT], char r_suffix [LEN_TERSE], char r_count [LEN_LABEL], char *b_share)
{
   if (r_suffix != NULL)  strcpy (r_suffix, "");
   if (r_count  != NULL)  strcpy (r_count , "");
   *b_share = a_major;
   if (a_scrp == 'y') {
      switch (strlen (a_stage))  {
      case  0  :   sprintf (r_suffix, "[··/·]"    );           break;
      case  2  :   sprintf (r_suffix, "[%-2.2s/·]", a_stage);  break;
      case  4  :   sprintf (r_suffix, "[%-4.4s]"  , a_stage);  break;
      }
   } else {
      if (a_major  != '-')   sprintf (r_suffix, "-%c-", a_major);
   }
   if      (a_scrp  == '-')  sprintf (r_count , "((%c%c.---))", a_major, a_major);
   else if (a_scrp  == ',')  sprintf (r_count , "((--.---))");
   else                      sprintf (r_count , "((%02d.---))", s_cscrp);
   return 0;
}

char
CONV__scrp              (FILE *a_conv, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_major, char a_minor, char *b_share, char *b_select)
{
   char        rc          =    0;
   char        x_suf       [LEN_TERSE] = "";
   char        x_cnt       [LEN_LABEL] = "";
   /*> rc = CONV__defense (a_conv, a_verb, a_desc, a_method, a_args, a_test, a_expect, a_return, a_stage, a_which, a_ditto, a_major, a_minor, b_share, b_select);   <* 
    *> if (rc < 0)  return rc;                                                                                                                                      <*/
   yUNIT_stats_scrp  (YUNIT_CONVERT, a_conv, "", YUNIT_IS_SCRP, a_verb, a_major, &s_cunit, &s_cscrp, &s_ccond, &s_cstep);
   CONV__scrp_add ('y', a_verb, a_major, a_stage, x_suf, x_cnt, b_share);
   CONV__break    (a_conv);
   return CONV_printf (a_conv, "%-6.6s%-6.6s  %-65.65s  %3.3s  %-14.14s  %-75.75s  %-10.10s  %s \n", a_verb, x_suf, a_desc, a_test, a_return, a_method, x_cnt, s_hund);
}

char
CONV__shared            (FILE *a_conv, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_major, char a_minor, char *b_share, char *b_select)
{
   char        rc          =    0;
   char        x_suf       [LEN_TERSE] = "";
   char        x_cnt       [LEN_LABEL] = "";
   /*> rc = CONV__defense (a_conv, a_verb, a_desc, a_method, a_args, a_test, a_expect, a_return, a_stage, a_which, a_ditto, a_major, a_minor, b_share, b_select);   <* 
    *> if (rc < 0)  return rc;                                                                                                                                      <*/
   yUNIT_stats_scrp  (YUNIT_CONVERT, a_conv, "", YUNIT_IS_SHAR, a_verb, a_major, &s_cunit, &s_cscrp, &s_ccond, &s_cstep);
   CONV__scrp_add ('-', a_verb, a_major, a_stage, x_suf, x_cnt, b_share);
   CONV__break    (a_conv);
   return CONV_printf (a_conv, "%-6.6s   %-3.3s  %-65.65s  %3.3s  %-14.14s  %-75.75s  %-10.10s  %s \n", a_verb, x_suf, a_desc, a_test, a_return, a_method, x_cnt, s_hund);
}

char
CONV__sect              (FILE *a_conv, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_major, char a_minor, char *b_share, char *b_select)
{
   char        rc          =    0;
   char        x_suf       [LEN_TERSE] = "";
   char        x_cnt       [LEN_LABEL] = "";
   /*> rc = CONV__defense (a_conv, a_verb, a_desc, a_method, a_args, a_test, a_expect, a_return, a_stage, a_which, a_ditto, a_major, a_minor, b_share, b_select);   <* 
    *> if (rc < 0)  return rc;                                                                                                                                      <*/
   yUNIT_stats_scrp  (YUNIT_CONVERT, a_conv, "", YUNIT_IS_SECT, a_verb, a_major, &s_cunit, &s_cscrp, &s_ccond, &s_cstep);
   CONV__scrp_add (',', a_verb, a_major, a_stage, x_suf, x_cnt, b_share);
   CONV__break    (a_conv);
   return CONV_printf (a_conv, "%-6.6s        %-65.65s  %s\n", a_verb, a_desc, s_suffix);
}



/*====================------------------------------------====================*/
/*===----                      condition level                         ----===*/
/*====================------------------------------------====================*/
static void  o___CONDITION_______o () { return; }

char
CONV__cond_add          (char a_ditto, char a_major, char a_minor, char a_share, char r_suffix [LEN_TERSE], char r_count [LEN_LABEL])
{
   /*---(defaults)-----------------------*/
   /*> printf ("COND_cond   %c mark   %c share  %c cshare\n", a_ditto, a_share, a_share);   <*/
   if (r_suffix != NULL) strcpy (r_suffix, "");
   if (r_count  != NULL) strcpy (r_count , "");
   /*---(verb suffixes)------------------*/
   if      (a_ditto  != '-')  sprintf (r_suffix, "(%c)" , a_ditto);
   else if (a_minor  != '-')  sprintf (r_suffix, "%c/%c", a_major, a_minor);
   else if (a_major  != '-')  sprintf (r_suffix, "%c/*" , a_major);
   /*---(line numbering)-----------------*/
   if (a_share  == '-')       sprintf (r_count , "((%02d.%03d))", s_cscrp, s_ccond);
   else                       sprintf (r_count , "((%c%c.%03d))", a_share, a_share, s_ccond);
   /*---(complete)-----------------------*/
   return 0;
}

char
CONV__cond              (FILE *a_conv, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_major, char a_minor, char *b_share, char *b_select)
{
   char        rc          =    0;
   char        x_suf       [LEN_TERSE] = "";
   char        x_cnt       [LEN_LABEL] = "";
   /*> rc = CONV__defense (a_conv, a_verb, a_desc, a_method, a_args, a_test, a_expect, a_return, a_stage, a_which, a_ditto, a_major, a_minor, b_share, b_select);   <* 
    *> if (rc < 0)  return rc;                                                                                                                                      <*/
   yUNIT_stats_cond  (YUNIT_CONVERT, a_conv, "", YUNIT_IS_COND, a_verb, a_desc, '-', a_ditto, a_major, *b_share, &s_cunit, &s_cscrp, &s_ccond, &s_cstep);
   CONV__cond_add (a_ditto, a_major, a_minor, *b_share, x_suf, x_cnt);
   return CONV_printf (a_conv, "\n   %-5.5s %-3.3s  %-65.65s  %s  %-10.10s  %s \n", a_verb, x_suf, a_desc, s_hund, x_cnt, s_hund);
}

char
CONV__ditto             (FILE *a_conv, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_major, char a_minor, char *b_share, char *b_select)
{
   char        rc          =    0;
   char        x_suf       [LEN_TERSE] = "";
   char        x_cnt       [LEN_LABEL] = "   ";
   /*> rc = CONV__defense (a_conv, a_verb, a_desc, a_method, a_args, a_test, a_expect, a_return, a_stage, a_which, a_ditto, a_major, a_minor, b_share, b_select);   <* 
    *> if (rc < 0)  return rc;                                                                                                                                      <*/
   yUNIT_stats_cond  (YUNIT_CONVERT, a_conv, "", YUNIT_IS_DITT, a_verb, a_desc, '-', a_ditto, a_major, *b_share, &s_cunit, &s_cscrp, &s_ccond, &s_cstep);
   DITTO_called (a_ditto);
   CONV__cond_add (a_ditto, a_major, a_minor, *b_share, x_suf, x_cnt);
   return CONV_printf (a_conv, "\n   %-5.5s %-3.3s  %-65.65s  %s  %-10.10s  %s \n", a_verb, x_suf, a_desc, s_hund, x_cnt, s_hund);
}

char
CONV__reuse             (FILE *a_conv, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_major, char a_minor, char *b_share, char *b_select)
{
   char        rc          =    0;
   char        x_suf       [LEN_TERSE] = "";
   char        x_cnt       [LEN_LABEL] = "   ";
   char        t           [LEN_SHORT] = "";
   /*> rc = CONV__defense (a_conv, a_verb, a_desc, a_method, a_args, a_test, a_expect, a_return, a_stage, a_which, a_ditto, a_major, a_minor, b_share, b_select);   <* 
    *> if (rc < 0)  return rc;                                                                                                                                      <*/
   yUNIT_reuse_called (a_major);
   sprintf (t, "%c", a_major);
   yUNIT_stats_cond  (YUNIT_CONVERT, a_conv, "", YUNIT_IS_REUS, a_verb, a_desc, '-', a_ditto, a_major, *b_share, &s_cunit, &s_cscrp, &s_ccond, &s_cstep);
   CONV__cond_add (a_ditto, a_major, a_minor, *b_share, x_suf, x_cnt);
   return CONV_printf (a_conv, "\n   %-5.5s %-3.3s  %-65.65s  %s  %-10.10s  %s \n", a_verb, x_suf, a_desc, s_hund, x_cnt, s_hund);
}

char
CONV__group             (FILE *a_conv, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_major, char a_minor, char *b_share, char *b_select)
{
   char        rc          =    0;
   char        x_desc      [LEN_LONG]  = "";
   /*> rc = CONV__defense (a_conv, a_verb, a_desc, a_method, a_args, a_test, a_expect, a_return, a_stage, a_which, a_ditto, a_major, a_minor, b_share, b_select);   <* 
    *> if (rc < 0)  return rc;                                                                                                                                      <*/
   DITTO_parse__group (a_desc, x_desc);
   return CONV_printf (a_conv, "\n   %-5.5s      %-65.65s  %s\n", a_verb, x_desc, s_suffix);
}



/*====================------------------------------------====================*/
/*===----                         step level                           ----===*/
/*====================------------------------------------====================*/
static void  o___STEPS___________o () { return; }

char
CONV__exec              (FILE *a_conv, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_major, char a_minor, char *b_share, char *b_select)
{
   char        rc          =    0;
   char        t           [LEN_RECD ] = "";
   /*> rc = CONV__defense (a_conv, a_verb, a_desc, a_method, a_args, a_test, a_expect, a_return, a_stage, a_which, a_ditto, a_major, a_minor, b_share, b_select);   <* 
    *> if (rc < 0)  return rc;                                                                                                                                      <*/
   yUNIT_stats_step  (YUNIT_CONVERT, a_conv, "", YUNIT_IS_EXEC, a_verb, a_desc, '-', a_ditto, a_major, *b_share, &s_cunit, &s_cscrp, &s_ccond, &s_cstep);
   if (strcmp (a_return, "") != 0)    sprintf (t, " %-20s ", a_return); 
   return CONV_printf (a_conv, "     %-6.6s   %-35.35s  %-26.26s  %-100s  %-10.10s  %-100s %s\n", a_verb, a_desc, a_method, a_args, a_test, a_expect, t);
}

char
CONV__load              (FILE *a_conv, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_major, char a_minor, char *b_share, char *b_select)
{
   char        rc          =    0;
   /*> rc = CONV__defense (a_conv, a_verb, a_desc, a_method, a_args, a_test, a_expect, a_return, a_stage, a_which, a_ditto, a_major, a_minor, b_share, b_select);   <* 
    *> if (rc < 0)  return rc;                                                                                                                                      <*/
   yUNIT_stats_step  (YUNIT_CONVERT, a_conv, "", YUNIT_IS_VOID, a_verb, a_desc, '-', a_ditto, a_major, *b_share, &s_cunit, &s_cscrp, &s_ccond, &s_cstep);
   return CONV_printf (a_conv, "     %-6.6s   %-35.35s  %-26.26s  %-218s \n", a_verb, a_desc, a_method, a_expect);
}

char
CONV__file              (FILE *a_conv, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_major, char a_minor, char *b_share, char *b_select)
{
   char        rc          =    0;
   /*> rc = CONV__defense (a_conv, a_verb, a_desc, a_method, a_args, a_test, a_expect, a_return, a_stage, a_which, a_ditto, a_major, a_minor, b_share, b_select);   <* 
    *> if (rc < 0)  return rc;                                                                                                                                      <*/
   yUNIT_stats_step  (YUNIT_CONVERT, a_conv, "", YUNIT_IS_EXEC, a_verb, a_desc, '-', a_ditto, a_major, *b_share, &s_cunit, &s_cscrp, &s_ccond, &s_cstep);
   return CONV_printf (a_conv, "     %-6.6s   %-35.35s  - - - - - - - - - - - - -   %-218s \n", a_verb, a_desc, a_expect);
}

char
CONV__append            (FILE *a_conv, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_major, char a_minor, char *b_share, char *b_select)
{
   char        rc          =    0;
   /*> rc = CONV__defense (a_conv, a_verb, a_desc, a_method, a_args, a_test, a_expect, a_return, a_stage, a_which, a_ditto, a_major, a_minor, b_share, b_select);   <* 
    *> if (rc < 0)  return rc;                                                                                                                                      <*/
   yUNIT_stats_step  (YUNIT_CONVERT, a_conv, "", YUNIT_IS_EXEC, a_verb, a_desc, '-', a_ditto, a_major, *b_share, &s_cunit, &s_cscrp, &s_ccond, &s_cstep);
   return CONV_printf (a_conv, "     %-6.6s   %-35.35s  - - - - - - - - - - - - -   %-218s \n", a_verb, a_desc, a_expect);
}

char
CONV__mode              (FILE *a_conv, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_major, char a_minor, char *b_share, char *b_select)
{
   char        rc          =    0;
   /*> rc = CONV__defense (a_conv, a_verb, a_desc, a_method, a_args, a_test, a_expect, a_return, a_stage, a_which, a_ditto, a_major, a_minor, b_share, b_select);   <* 
    *> if (rc < 0)  return rc;                                                                                                                                      <*/
   yUNIT_stats_step  (YUNIT_CONVERT, a_conv, "", YUNIT_IS_VOID, a_verb, a_desc, '-', a_ditto, a_major, *b_share, &s_cunit, &s_cscrp, &s_ccond, &s_cstep);
   return CONV_printf (a_conv, "     %-6.6s   %-35.35s  %-26.26s  %s\n", a_verb, a_desc, a_method, s_suffix);
}

char
CONV__code              (FILE *a_conv, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_major, char a_minor, char *b_share, char *b_select)
{
   char        rc          =    0;
   char        x_type      =  '-';
   /*> rc = CONV__defense (a_conv, a_verb, a_desc, a_method, a_args, a_test, a_expect, a_return, a_stage, a_which, a_ditto, a_major, a_minor, b_share, b_select);   <* 
    *> if (rc < 0)  return rc;                                                                                                                                      <*/
   if (strcmp (a_verb, "system") == 0)  x_type = YUNIT_IS_EXEC;
   else                                 x_type = YUNIT_IS_VOID;
   yUNIT_stats_step  (YUNIT_CONVERT, a_conv, "", x_type       , a_verb, a_desc, '-', a_ditto, a_major, *b_share, &s_cunit, &s_cscrp, &s_ccond, &s_cstep);
   return CONV_printf (a_conv, "     %-6.6s   %-35.35s  - - - - - - - - - - - - -   %-218s \n", a_verb, a_desc, a_expect);
}

char
CONV__gvar              (FILE *a_conv, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_major, char a_minor, char *b_share, char *b_select)
{
   char        rc          =    0;
   /*> rc = CONV__defense (a_conv, a_verb, a_desc, a_method, a_args, a_test, a_expect, a_return, a_stage, a_which, a_ditto, a_major, a_minor, b_share, b_select);   <* 
    *> if (rc < 0)  return rc;                                                                                                                                      <*/
   if (strcmp (a_verb, "local") == 0) yUNIT_stats_step  (YUNIT_CONVERT, a_conv, "", YUNIT_IS_VARS, a_verb, a_desc, '-', a_ditto, a_major, *b_share, &s_cunit, &s_cscrp, &s_ccond, &s_cstep);
   return CONV_printf (a_conv, "   %-6.6s     %-35.35s  - - - - - - - - - - - - -   %-218s \n", a_verb, a_desc, a_expect);
}

char
CONV__echo              (FILE *a_conv, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_major, char a_minor, char *b_share, char *b_select)
{
   char        rc          =    0;
   /*> rc = CONV__defense (a_conv, a_verb, a_desc, a_method, a_args, a_test, a_expect, a_return, a_stage, a_which, a_ditto, a_major, a_minor, b_share, b_select);   <* 
    *> if (rc < 0)  return rc;                                                                                                                                      <*/
   yUNIT_stats_step  (YUNIT_CONVERT, a_conv, "", YUNIT_IS_EXEC, a_verb, a_desc, '-', a_ditto, a_major, *b_share, &s_cunit, &s_cscrp, &s_ccond, &s_cstep);
   return CONV_printf (a_conv, "     %-6.6s   %-35.35s  - - - - - - - - - - - - -   %-100s  %-10.10s  %-100s \n", a_verb, a_desc, a_args, a_test, a_expect);
}



/*====================------------------------------------====================*/
/*===----                          main driver                         ----===*/
/*====================------------------------------------====================*/
static void  o___DRIVER__________o () { return; }

char
CONV_driver             (void f_call (), FILE *a_conv, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_major, char a_minor, char *b_share, char *b_select)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char      (*x_func) (FILE *a_conv, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_major, char a_minor, char *b_share, char *b_select);
   /*---(header)-------------------------*/
   debug_uver   ylog_uenter  (__FUNCTION__);
   /*---(defense)------------------------*/
   rc = CONV__defense (a_conv, a_verb, a_desc, a_method, a_args, a_test, a_expect, a_return, a_stage, a_which, a_ditto, a_major, a_minor, b_share, b_select);
   debug_uver   ylog_uvalue  ("defense"   , rc);
   if (rc < 0) {
      debug_uver   ylog_uexitr  (__FUNCTION__, rc);
      return rc;
   }
   /*---(preare)-------------------------*/
   debug_uver   ylog_upoint  ("f_call"    , f_call);
   if (f_call == NULL) {
      debug_uver   ylog_unote   ("nothing to do");
      debug_uver   ylog_uexit   (__FUNCTION__);
      return 0;
   }
   /*---(prepare)------------------------*/
   x_func = f_call;
   /*---(call function)------------------*/
   rc = x_func (a_conv, a_verb, a_desc, a_method, a_args, a_test, a_expect, a_return, a_stage, a_which, a_ditto, a_major, a_minor, b_share, b_select);
   debug_uver   ylog_uvalue  ("call"      , rc);
   --rce;  if (rc < 0) {
      debug_uver   ylog_uexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(complete)-----------------------*/
   debug_uver   ylog_uexit   (__FUNCTION__);
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
   s_cscrp = a_scrps;
   s_ccond = a_conds;
   return 0;
}



/*===============================[[ end code ]]===============================*/
