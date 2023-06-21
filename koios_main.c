/*===============================[[ beg-code ]]===============================*/
#include    "koios.h"        /* LOCAL  : main header                          */


int
main               (int a_argc, char *a_argv [])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        t           [LEN_RECD];
   int         x_lines     =    0;
   char        x_final     =    0;
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
   /*> yURG_startup (a_argc, a_argv);                                                 <* 
    *> --rce;  if (rc < 0) {                                                          <* 
    *> }                                                                              <*/
   if (rc >= 0)  rc = yURG_logger  (a_argc, a_argv);
   if (rc >= 0)  rc = PROG__init    ();
   if (rc >= 0)  rc = yURG_urgs    (a_argc, a_argv);
   if (rc >= 0)  rc = PROG__args    (a_argc, a_argv, &(my.run_type), &(my.replace), my.n_base, my.n_ext);
   if (rc >= 0)  rc = PROG__begin   ();
   if (rc <  0)  {
      PROG_shutdown ();
      return rc;
   }
   /*---(open files)---------------------*/
   /*> printf ("base name = %s\n", my.n_base);                                        <* 
    *> printf ("scrp name = %s\n", my.n_scrp);                                        <* 
    *> if (my.run_type == G_RUN_CREATE || my.run_type == G_RUN_DEBUG) {               <* 
    *>    printf ("code name = %s\n", my.n_code);                                     <* 
    *>    printf ("main name = %s¦", my.n_main);                                      <* 
    *> } else {                                                                       <* 
    *>    printf ("conv name = %s¦", my.n_conv);                                      <* 
    *> }                                                                              <*/
   /*---(open files)---------------------*/
   if (rc == 0)  {
      rc = SCRP_open      (my.n_scrp, &(my.f_scrp), &(my.n_line));
      DITTO_purge ();
      rc = WAVE_open      (my.n_wave);
   }
   if (my.run_type == G_RUN_CREATE || my.run_type == G_RUN_DEBUG) {
      if (rc == 0)  rc = CODE_open      ();
      if (rc == 0)  rc = CODE_beg       ();
      if (rc == 0)  rc = MAIN_beg       ();
   } else if (my.run_type == G_RUN_UPDATE) {
      if (rc == 0)  rc = CONV_open      ();
      if (rc == 0)  rc = CONV_beg       ();
   }
   if (rc != 0) {
      PROG_shutdown ();
      return rc;
   }
   IF_NORMAL  CODE_shared_in  ();
   /*---(main-loop)----------------------*/
   DEBUG_PROG   yLOG_enter   (__FUNCTION__);
   DEBUG_PROG   yLOG_note    ("entering main processing loop");
   DEBUG_PROG   yLOG_break   ();
   while (1) {
      /*---(read and parse)--------------*/
      rc = SCRP_read   (my.f_scrp, my.n_line, my.dittoing, my.ditto, &(my.dline), &(my.n_recd), &(my.len), my.recd);
      DEBUG_PROG   yLOG_value   ("read"      , rc);
      if (rc == 0) {
         DEBUG_PROG   yLOG_note    ("end of file");
         break;
      }
      if (rc < 0) {
         DEBUG_PROG   yLOG_value   ("X_FINAL R" , x_final);
         --x_final;
         continue;
      }
      rc = SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers, my.desc, my.meth, my.args, my.test, my.expe, my.retn, my.code);
      DEBUG_PROG   yLOG_value   ("parse"     , rc);
      if (rc < 0) {
         DEBUG_PROG   yLOG_value   ("X_FINAL P" , x_final);
         --x_final;
         continue;
      }
      DEBUG_PROG   yLOG_note    ("writing output");
      /*---(write code)------------------*/
      if      (my.run_type == G_RUN_CREATE)   rc = CODE_write  ();
      else if (my.run_type == G_RUN_DEBUG )   rc = CODE_write  ();
      else if (my.run_type == G_RUN_UPDATE)   rc = CONV_driver ();
      /*---(debugging output)------------*/
      ++x_lines;
   }
   DEBUG_PROG  yLOG_break   ();
   DEBUG_PROG  yLOG_note    ("exiting main processing loop");
   /*---(close files)--------------------*/
   rc = SCRP_close     (&(my.f_scrp));
   rc = WAVE_close     ();
   if (my.run_type == G_RUN_CREATE || my.run_type == G_RUN_DEBUG) { 
      rc = MAIN_end       ();
      rc = CODE_end       ();
      IF_NORMAL  rc = MAIN_append    ();
      IF_MASTER  CODE_shared_out ();
      rc = CODE_close     (my.f_code);
      /*> rc = CODE_close     (my.f_wave);                                            <*/
      IF_MASTER  system  ("mv -f master_unit.cs master.h");
   } else if (my.run_type == G_RUN_UPDATE) {
      rc = CONV_end       ();
      rc = CONV_close     ();
   }
   if (my.replace == G_RUN_REPLACE) {
      if (x_final == 0) {
         sprintf (t, "cp -f %s %s.old", my.n_scrp, my.n_scrp);
         system  (t);
         printf  ("replacing script with update, saved original in .old\n");
         sprintf (t, "mv -f %s %s"   , my.n_conv, my.n_scrp);
         system  (t);
      } else {
         printf  ("%d troubles found, script left in original status\n", -x_final);
      }
   }
   DEBUG_PROG   yLOG_exit    (__FUNCTION__);
   /*---(summary)------------------------*/
   /*> SCRP_verbs ();                                                                 <*/
   /*> printf ("\n");                                                                 <*/
   /*---(complete)-----------------------*/
   PROG_shutdown ();
   /*> printf ("complete\n");                                                         <*/
   return x_final;
}



/*===============================[[ end code ]]===============================*/
