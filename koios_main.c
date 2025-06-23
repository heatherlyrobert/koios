/*===============================[[ beg-code ]]===============================*/
#include    "koios.h"        /* LOCAL  : main header                          */


int
main               (int a_argc, char *a_argv [])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        t           [LEN_RECD];
   char        x_good      =  'y';
   int         x_error     =    0;
   /*---(debugging)----------------------*/
   rc = PROG_urgents (a_argc, a_argv);
   debug_uver   ylog_uvalue   ("urgents"   , rc);
   --rce;  if (rc <  0) { 
      PROG_shutdown ();
      return rce;
   }
   /*---(initialization)-----------------*/
   rc = PROG_startup (a_argc, a_argv);
   debug_uver   ylog_uvalue   ("startup"   , rc);
   --rce;  if (rc <  0) {
      PROG_shutdown ();
      return rce;
   }
   /*---(main-loop)----------------------*/
   rc = PROG_dawn  (my.run_type, my_loc.l_scrp, &(my_loc.l_SCRP), &(my_run.r_nline), my_loc.l_main, &(my_loc.l_MAIN), my_loc.l_code, &(my_loc.l_CODE), my_loc.l_wave, &(my_loc.l_WAVE), my_loc.l_conv, &(my_loc.l_CONV), &(my_run.r_share), &(my_run.r_select));
   debug_uver   ylog_uvalue   ("dawn"      , rc);
   --rce;  if (rc <  0) {
      PROG_shutdown ();
      return rce;
   }
   /*---(main-loop)----------------------*/
   debug_uver   ylog_uenter  (__FUNCTION__);
   debug_uver   ylog_unote   ("entering main processing loop");
   /*---(main)---------------------------*/
   while (1) {
      debug_uver   ylog_uchar   ("x_good"    , x_good);
      rc = PROG_driver (x_good, my.run_type, my_loc.l_scrp, &(my_run.r_nline), &(my_loc.l_SCRP), my_loc.l_MAIN, my_loc.l_CODE, my_loc.l_WAVE, my_loc.l_CONV, my_run.r_last, &(my_run.r_nrecd), &(my_run.r_under), &(my_cur.c_ditto), &(my_run.r_dittoing), &(my_run.r_dtarget), &(my_run.r_dstart), &(my_run.r_dline), &(my_cur.c_major), &(my_cur.c_minor), &(my_run.r_share), &(my_run.r_select));
      debug_uver   ylog_uvalue  ("driver"    , rc);
      if (rc == 0)  break;  /* end-of-file */
      if (rc <  0) {
         x_good = '-';
         ++x_error;
      }
   }
   debug_uver   ylog_unote   ("exiting main processing loop");
   debug_uver   ylog_uexit   (__FUNCTION__);
   /*---(dusk)---------------------------*/
   rc = PROG_dusk  (x_good, my.run_type, my.replace, my_loc.l_scrp, &(my_loc.l_SCRP), my_run.r_nline, my_loc.l_main, &(my_loc.l_MAIN), my_loc.l_code, &(my_loc.l_CODE), my_loc.l_wave, &(my_loc.l_WAVE), my_loc.l_conv, &(my_loc.l_CONV), my_run.r_share, my_run.r_select);
   debug_uver   ylog_uvalue   ("dusk"      , rc);
   --rce;  if (rc <  0) {
      PROG_shutdown ();
      return rce;
   }
   /*---(complete)-----------------------*/
   PROG_shutdown ();
   return -x_error;
}



/*===============================[[ end code ]]===============================*/
