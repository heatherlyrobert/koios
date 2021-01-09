/*===============================[[ beg-code ]]===============================*/
#include    "koios.h"        /* LOCAL  : main header                          */


int
main               (int argc, char *argv[])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rc          =    0;
   char        t           [LEN_RECD];
   int         x_lines     =    0;
   char        x_final     =    0;
   /*---(initialize)---------------------*/
   if (rc >= 0)  rc = yURG_logger  (argc, argv);
   if (rc >= 0)  rc = PROG_init    ();
   if (rc >= 0)  rc = yURG_urgs    (argc, argv);
   if (rc >= 0)  rc = PROG_args    (argc, argv);
   if (rc >= 0)  rc = PROG_begin   ();
   if (rc <  0)  {
      PROG_end     ();
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
   if (rc == 0)  rc = SCRP_open      ();
   if (my.run_type == G_RUN_CREATE || my.run_type == G_RUN_DEBUG) {
      if (rc == 0)  rc = CODE_open      ();
      if (rc == 0)  rc = CODE_beg       ();
      if (rc == 0)  rc = MAIN_beg       ();
   } else if (my.run_type == G_RUN_UPDATE) {
      if (rc == 0)  rc = CONV_open      ();
      if (rc == 0)  rc = CONV_beg       ();
   }
   if (rc != 0) {
      PROG_end     ();
      return rc;
   }
   /*---(main-loop)----------------------*/
   DEBUG_TOPS   yLOG_enter   (__FUNCTION__);
   DEBUG_TOPS   yLOG_note    ("entering main processing loop");
   DEBUG_TOPS   yLOG_break   ();
   while (1) {
      /*---(read and parse)--------------*/
      rc = SCRP_read   ();
      if (rc == 0) {
         DEBUG_TOPS   yLOG_note    ("end of file");
         break;
      }
      if (rc < 0) {
         DEBUG_TOPS   yLOG_value   ("X_FINAL R" , x_final);
         --x_final;
         continue;
      }
      rc = SCRP_parse  ();
      if (rc < 0) {
         DEBUG_TOPS   yLOG_value   ("X_FINAL P" , x_final);
         --x_final;
         continue;
      }
      DEBUG_TOPS   yLOG_note    ("writing output");
      /*---(write code)------------------*/
      if      (my.run_type == G_RUN_CREATE)   rc = CODE_write  ();
      else if (my.run_type == G_RUN_DEBUG )   rc = CODE_write  ();
      else if (my.run_type == G_RUN_UPDATE)   rc = CONV_driver ();
      /*---(debugging output)------------*/
      ++x_lines;
   }
   DEBUG_TOPS  yLOG_break   ();
   DEBUG_TOPS  yLOG_note    ("exiting main processing loop");
   /*---(close files)--------------------*/
   rc = SCRP_close     ();
   if (my.run_type == G_RUN_CREATE || my.run_type == G_RUN_DEBUG) { 
      rc = MAIN_end       ();
      rc = CODE_end       ();
      rc = MAIN_append    ();
      rc = CODE_close     (my.f_code);
      rc = CODE_close     (my.f_wave);
   } else if (my.run_type == G_RUN_UPDATE) {
      rc = CONV_end       ();
      rc = CONV_close     ();
   }
   if (my.replace == G_RUN_REPLACE) {
      sprintf (t, "cp -f %s %s.old", my.n_scrp, my.n_scrp);
      system  (t);
      printf  ("replacing script with update, saved original in .old\n");
      sprintf (t, "mv -f %s %s"   , my.n_conv, my.n_scrp);
      system  (t);
   }
   /*---(summary)------------------------*/
   /*> printf ("\n");                                                                                                      <* 
    *> printf ("reading script...\n");                                                                                     <* 
    *> printf ("   %-4d total lines\n"                , my.n_line);                                                        <* 
    *> printf ("   %-4d comments\n"                   , my.n_comment);                                                     <* 
    *> printf ("   %-4d empty lines\n"                , my.n_empty);                                                       <* 
    *> printf ("   %-4d short lines ( <10 chars)\n"   , my.n_short);                                                       <* 
    *> printf ("   %-4d useable records\n"            , my.n_recd);                                                        <* 
    *> printf ("   %-4d CONCERNS\n"                   , my.n_line - my.n_comment - my.n_empty - my.n_short - my.n_recd);   <* 
    *> printf ("\n");                                                                                                      <*/
   /*> SCRP_verbs ();                                                                 <*/
   /*> printf ("\n");                                                                 <*/
   /*---(complete)-----------------------*/
   PROG_end     ();
   /*> printf ("complete\n");                                                         <*/
   return x_final;
}



/*===============================[[ end code ]]===============================*/
