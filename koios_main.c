/*===============================[[ beg-code ]]===============================*/
#include    "koios.h"        /* LOCAL  : main header                          */


int
main               (int argc, char *argv[])
{
   /*---(locals)-----------+-----------+-*/
   FILE       *f_in        = NULL;
   FILE       *f_out       = NULL;
   char        rc          = 0;

   /*---(locals)-----------+-----------+-*/
   FILE       *f           = NULL;
   char        x_recd      [LEN_RECD];
   char        x_temp      [LEN_RECD];
   char        x_verb      [20];
   int         x_len;
   char       *p;
   char       *q           = ";";
   char       *r;
   char        rce         = -10;
   int         x_lines     = 0;

   /*---(initialize)---------------------*/
   if (rc == 0)  rc = PROG_logger (argc, argv);
   if (rc == 0)  rc = PROG_init   ();
   if (rc == 0)  rc = PROG_urgs   (argc, argv);
   if (rc == 0)  rc = PROG_args   (argc, argv);
   if (rc == 0)  rc = PROG_begin  ();
   if (rc != 0) {
      PROG_end     ();
      return rc;
   }
   DEBUG_TOPS   yLOG_enter   (__FUNCTION__);


   printf ("base name = %s\n", my.name_base);
   printf ("scrp name = %s\n", my.name_scrp);
   printf ("code name = %s\n", my.name_code);
   /*> return 0;                                                                      <*/


   /*---(open files)---------------------*/
   if (rc == 0)  rc = SCRP_open      ();
   if (rc == 0)  rc = CODE_open      ();
   if (rc == 0)  rc = CODE_begin     ();
   if (rc != 0) {
      PROG_end     ();
      return rc;
   }
   /*---(main-loop)----------------------*/
   DEBUG_TOPS  yLOG_note    ("entering main processing loop");
   DEBUG_TOPS  yLOG_break   ();
   while (1) {
      /*---(read and parse)--------------*/
      rc = SCRP_read   ();
      if (rc < 0) break;
      rc = SCRP_parse  ();
      /*> if (rc < 0) continue;                                                       <*/
      /*---(write code)------------------*/
      rc = CODE_write  ();
      /*---(debugging output)------------*/
      ++x_lines;
      /*> printf (".");                                                               <*/
      /*> printf ("\n");                                                              <* 
       *> printf ("recd = %s\n", my.recd);                                            <* 
       *> printf ("   line = %d\n", my.n_line);                                       <* 
       *> printf ("   last = %s\n", my.last);                                         <* 
       *> printf ("   verb = %s\n", my.verb);                                         <* 
       *> printf ("   spec = %c\n", my.spec);                                         <* 
       *> printf ("   vers = %s\n", my.vers);                                         <* 
       *> printf ("   desc = %s\n", my.desc);                                         <* 
       *> printf ("   meth = %s\n", my.meth);                                         <* 
       *> printf ("   args = %s\n", my.args);                                         <* 
       *> printf ("   test = %s\n", my.test);                                         <* 
       *> printf ("   expe = %s\n", my.expe);                                         <* 
       *> printf ("   type = %c\n", my.type);                                         <* 
       *> printf ("   retn = %s\n", my.retn);                                         <* 
       *> printf ("   code = %s\n", my.code);                                         <* 
       *> printf ("   disp = %s\n", my.disp);                                         <* 
       *> printf ("   syst = %s\n", my.syst);                                         <* 
       *> printf ("   load = %s\n", my.load);                                         <*/
   }
   /*> printf ("\ndone\n");                                                           <*/
   DEBUG_TOPS  yLOG_break   ();
   DEBUG_TOPS  yLOG_note    ("exiting main processing loop");
   /*---(close files)--------------------*/
   rc = SCRP_close     ();
   rc = CODE_end       ();
   rc = CODE_close     ();
   /*---(summary)------------------------*/
   printf ("\n");
   printf ("reading script...\n");
   printf ("   %-4d total lines\n"                , my.n_line);
   printf ("   %-4d comments\n"                   , my.n_comment);
   printf ("   %-4d empty lines\n"                , my.n_empty);
   printf ("   %-4d short lines ( <10 chars)\n"   , my.n_short);
   printf ("   %-4d useable records\n"            , my.n_recd);
   printf ("   %-4d CONCERNS\n"                   , my.n_line - my.n_comment - my.n_empty - my.n_short - my.n_recd);
   printf ("\n");
   SCRP_verbs ();
   printf ("\n");
   /*---(complete)-----------------------*/
   PROG_end     ();
   printf ("complete\n");
   return 0;
}



/*===============================[[ end code ]]===============================*/
