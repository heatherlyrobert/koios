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
   DEBUG_PROG   yLOG_value    ("urgents"   , rc);
   --rce;  if (rc <  0) { 
      PROG_shutdown ();
      return rce;
   }
   /*---(initialization)-----------------*/
   rc = PROG_startup (a_argc, a_argv);
   DEBUG_PROG   yLOG_value    ("startup"   , rc);
   --rce;  if (rc <  0) {
      PROG_shutdown ();
      return rce;
   }
   /*---(main-loop)----------------------*/
   rc = PROG_dawn  (my.run_type, my.n_scrp, &(my.f_scrp), &(my.n_line), my.n_main, &(my.f_main), my.n_code, &(my.f_code), my.n_wave, &(my.f_wave), my.n_conv, &(my.f_conv), &(my.cshare));
   DEBUG_PROG   yLOG_value    ("dawn"      , rc);
   --rce;  if (rc <  0) {
      PROG_shutdown ();
      return rce;
   }
   /*---(main-loop)----------------------*/
   DEBUG_PROG   yLOG_break   ();
   DEBUG_PROG   yLOG_enter   (__FUNCTION__);
   DEBUG_PROG   yLOG_note    ("entering main processing loop");
   /*---(main)---------------------------*/
   while (1) {
      DEBUG_OUTP   yLOG_char    ("x_good"    , x_good);
      rc = PROG_driver (x_good, my.run_type, my.n_scrp, &(my.n_line), &(my.f_scrp), my.f_main, my.f_code, my.f_wave, my.f_conv, my.last, &(my.n_recd), &(my.dittoing), &(my.mark), &(my.dmark), &(my.ditto), &(my.dline), &(my.share), &(my.cshare));
      DEBUG_OUTP   yLOG_value   ("driver"    , rc);
      if (rc == 0)  break;  /* end-of-file */
      if (rc <  0) {
         x_good = '-';
         ++x_error;
      }
   }
   DEBUG_PROG  yLOG_break   ();
   DEBUG_PROG  yLOG_note    ("exiting main processing loop");
   /*---(dusk)---------------------------*/
   rc = PROG_dusk  (x_good, my.run_type, my.replace, my.n_scrp, &(my.f_scrp), my.n_main, &(my.f_main), my.n_code, &(my.f_code), my.n_wave, &(my.f_wave), my.n_conv, &(my.f_conv), my.cshare);
   DEBUG_PROG   yLOG_value    ("dusk"      , rc);
   --rce;  if (rc <  0) {
      PROG_shutdown ();
      return rce;
   }
   /*---(complete)-----------------------*/
   DEBUG_PROG   yLOG_exit    (__FUNCTION__);
   PROG_shutdown ();
   return -x_error;
}



/*===============================[[ end code ]]===============================*/
