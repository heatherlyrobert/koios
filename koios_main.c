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
   /*---(open incomming script)----------*/
   /*> rc = READ_open      (my.n_scrp, 'r', &(my.f_scrp), &(my.n_line));              <* 
    *> DEBUG_PROG   yLOG_value   ("script"    , rc);                                  <* 
    *> --rce;  if (rc < 0) {                                                          <* 
    *>    PROG_shutdown ();                                                           <* 
    *>    DEBUG_PROG   yLOG_exitr   (__FUNCTION__, rce);                              <* 
    *>    return rce;                                                                 <* 
    *> }                                                                              <*/
   /*---(open output files)--------------*/
   /*> --rce;  switch (my.run_type) {                                                                                   <* 
    *> case G_RUN_CREATE : case G_RUN_DEBUG :                                                                           <* 
    *>    rc = CODE_header (my.n_main, &(my.f_main), my.n_code, &(my.f_code), my.n_wave, &(my.f_wave), &(my.cshare));   <* 
    *>    break;                                                                                                        <* 
    *> case G_RUN_UPDATE :                                                                                              <* 
    *>    rc = CONV_header  (my.n_conv, &(my.f_conv), &(my.cshare));                                                    <* 
    *>    break;                                                                                                        <* 
    *> default  :                                                                                                       <* 
    *>    READ_close (&(my.f_scrp));                                                                                    <* 
    *>    PROG_shutdown ();                                                                                             <* 
    *>    DEBUG_PROG   yLOG_exitr   (__FUNCTION__, rce);                                                                <* 
    *>    return rce;                                                                                                   <* 
    *>    break;                                                                                                        <* 
    *> }                                                                                                                <* 
    *> DEBUG_PROG   yLOG_value   ("output"    , rc);                                                                    <* 
    *> --rce;  if (rc <  0) {                                                                                           <* 
    *>    READ_close (&(my.f_scrp));                                                                                    <* 
    *>    PROG_shutdown ();                                                                                             <* 
    *>    return rc;                                                                                                    <* 
    *> }                                                                                                                <*/
   /*---(open output files)--------------*/
   /*> IF_NORMAL {                                                                    <* 
    *>    rc = REUSE_import  ("master.globals");                                      <* 
    *>    DEBUG_PROG   yLOG_value   ("globals"   , rc);                               <* 
    *>    --rce;  if (rc <  0) {                                                      <* 
    *>       READ_close (&(my.f_scrp));                                               <* 
    *>       READ_close (&(my.f_main));                                               <* 
    *>       READ_close (&(my.f_code));                                               <* 
    *>       READ_close (&(my.f_wave));                                               <* 
    *>       PROG_shutdown ();                                                        <* 
    *>       return rc;                                                               <* 
    *>    }                                                                           <* 
    *> }                                                                              <*/
   /*---(main)---------------------------*/
   while (1) {
      rc = PROG_driver (my.run_type, my.n_scrp, &(my.n_line), &(my.f_scrp), my.f_main, my.f_code, my.f_wave, my.f_conv, my.last, &(my.n_recd), &(my.dittoing), &(my.mark), &(my.dmark), &(my.ditto), &(my.dline), &(my.share), &(my.cshare));
      if (rc == 0)  break;  /* end-of-file */
      /*---(read and parse)--------------*/
      /*> rc = SCRP_read   (my.f_scrp, my.n_line, my.dittoing, my.ditto, &(my.dline), &(my.n_recd), &(my.len), my.recd);   <*/
      /*> rc = SCRP_read   (my.f_scrp, my.n_line, my.dittoing, my.ditto, &(my.dline), &(my.n_recd), &(my.len), my.recd);                                                                                                                                                  <* 
       *> DEBUG_PROG   yLOG_value   ("read"      , rc);                                                                                                                                                                                                                   <* 
       *> if (rc == 0) {                                                                                                                                                                                                                                                  <* 
       *>    DEBUG_PROG   yLOG_note    ("end of file");                                                                                                                                                                                                                   <* 
       *>    break;                                                                                                                                                                                                                                                       <* 
       *> }                                                                                                                                                                                                                                                               <* 
       *> if (rc < 0) {                                                                                                                                                                                                                                                   <* 
       *>    DEBUG_PROG   yLOG_value   ("X_FINAL R" , x_final);                                                                                                                                                                                                           <* 
       *>    --x_final;                                                                                                                                                                                                                                                   <* 
       *>    continue;                                                                                                                                                                                                                                                    <* 
       *> }                                                                                                                                                                                                                                                               <* 
       *> rc = SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers, my.desc, my.meth, my.args, my.test, my.expe, my.retn, my.code);                                                                <* 
       *> DEBUG_PROG   yLOG_value   ("parse"     , rc);                                                                                                                                                                                                                   <* 
       *> if (rc < 0) {                                                                                                                                                                                                                                                   <* 
       *>    DEBUG_PROG   yLOG_value   ("X_FINAL P" , x_final);                                                                                                                                                                                                           <* 
       *>    --x_final;                                                                                                                                                                                                                                                   <* 
       *>    continue;                                                                                                                                                                                                                                                    <* 
       *> }                                                                                                                                                                                                                                                               <* 
       *> DEBUG_PROG   yLOG_note    ("writing output");                                                                                                                                                                                                                   <* 
       *> /+---(write output)----------------+/                                                                                                                                                                                                                           <* 
       *> if      (my.run_type == G_RUN_CREATE)   rc = CODE_driver (my.p_code, my.f_main, my.f_code, my.f_wave, my.run_type, my.last, my.verb, my.desc, my.meth, my.args, my.test, my.expe, my.retn, my.stage, my.dittoing, my.mark, my.dmark, my.share, &(my.cshare));   <* 
       *> else if (my.run_type == G_RUN_DEBUG )   rc = CODE_driver (my.p_code, my.f_main, my.f_code, my.f_wave, my.run_type, my.last, my.verb, my.desc, my.meth, my.args, my.test, my.expe, my.retn, my.stage, my.dittoing, my.mark, my.dmark, my.share, &(my.cshare));   <* 
       *> else if (my.run_type == G_RUN_UPDATE)   rc = CONV_driver (my.p_conv, my.f_conv, my.verb, my.desc, my.meth, my.args, my.test, my.expe, my.retn, my.share, my.mark, my.stage, &(my.cshare));                                                                      <*/
      /*---(debugging output)------------*/
      ++x_lines;
   }
   DEBUG_PROG  yLOG_break   ();
   DEBUG_PROG  yLOG_note    ("exiting main processing loop");
   /*---(dusk)---------------------------*/
   rc = PROG_dusk  (my.run_type, my.replace, my.n_scrp, &(my.f_scrp), my.n_main, &(my.f_main), my.n_code, &(my.f_code), my.n_wave, &(my.f_wave), my.n_conv, &(my.f_conv), my.cshare);
   DEBUG_PROG   yLOG_value    ("dusk"      , rc);
   --rce;  if (rc <  0) {
      PROG_shutdown ();
      return rce;
   }
   /*---(close files)--------------------*/
   /*> rc = SCRP_close     (&(my.f_scrp));                                            <* 
    *> switch (my.run_type) {                                                         <* 
    *> case G_RUN_CREATE : case G_RUN_DEBUG :                                         <* 
    *>    rc = CODE_footer (my.n_main, &(my.f_main), &(my.f_code), &(my.f_wave));     <* 
    *>    break;                                                                      <* 
    *> case G_RUN_UPDATE :                                                            <* 
    *>    rc = CONV_footer  (&(my.f_conv));                                           <* 
    *>    break;                                                                      <* 
    *> }                                                                              <*/
   /*---(handle replace)-----------------*/
   /*> if (my.replace == G_RUN_REPLACE) {                                                 <* 
    *>    if (x_final == 0) {                                                             <* 
    *>       sprintf (t, "cp -f %s %s.old", my.n_scrp, my.n_scrp);                        <* 
    *>       system  (t);                                                                 <* 
    *>       printf  ("replacing script with update, saved original in .old\n");          <* 
    *>       sprintf (t, "mv -f %s %s"   , my.n_conv, my.n_scrp);                         <* 
    *>       system  (t);                                                                 <* 
    *>    } else {                                                                        <* 
    *>       printf  ("%d troubles found, script left in original status\n", -x_final);   <* 
    *>    }                                                                               <* 
    *> }                                                                                  <*/
   /*---(complete)-----------------------*/
   DEBUG_PROG   yLOG_exit    (__FUNCTION__);
   PROG_shutdown ();
   return x_final;
}



/*===============================[[ end code ]]===============================*/
