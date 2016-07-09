/*===============================[[ beg-code ]]===============================*/
#include    "koios.h"        /* LOCAL  : main header                          */


char
CONV_begin         (void)
{
   fprintf (my.file_conv, "#!/usr/local/bin/koios\n");
   fprintf (my.file_conv, "#   koios-polos (northern axis) -- c unit testing metaprogram and mini-language\n");
   fprintf (my.file_conv, "#   program under test  : %s\n", my.name_base);
   fprintf (my.file_conv, "#   auto-generated script file from a previous version\n");
   my.nscrp = my.cscrp = 0;
   my.ncond = my.ccond = 0;
   my.nstep = my.cstep = 0;
   return 0;
}

char
CONV_end           (void)
{
   fprintf (my.file_conv, "\n\n\n");
   fprintf (my.file_conv, "# end-of-file\n");
   return 0;
}

char         /*--> open output script file ---------------[ leaf   [ ------ ]-*/
CONV_open          (void)
{
   /*---(locals)-----------+-----------+-*/
   char        rce         = -10;           /* return code for errors         */
   /*---(header)-------------------------*/
   DEBUG_TOPS   yLOG_enter   (__FUNCTION__);
   /*---(open configuration)-------------*/
   DEBUG_OUTP   yLOG_point   ("name"      , my.name_conv);
   my.file_conv = fopen (my.name_conv, "w");
   DEBUG_OUTP   yLOG_point   ("file*"     , my.file_conv);
   --rce;  if (my.file_conv == NULL) {
      DEBUG_TOPS   yLOG_fatal   ("scrp file" , "can not open output script file");
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
   DEBUG_OUTP   yLOG_point   ("*file_conv", my.file_conv);
   rc = fclose (my.file_conv);
   --rce;  if (rc != 0) {
      return rce;
   }
   /*---(complete)-----------------------*/
   DEBUG_TOPS   yLOG_exit    (__FUNCTION__);
   return 0;
}

char         /*--> write a script entry ------------------[--------[--------]-*/
CONV_scrp          (void)
{
   /*---(counters)-----------------------*/
   ++(my.nscrp);
   ++(my.cscrp);
   my.ccond = 0;
   my.cstep = 0;
   /*---(output)-------------------------*/
   fprintf (my.file_conv, "\n\n\n");
   fprintf (my.file_conv, "#23456789-12  123  123456789-123456789-123456789-12345  123456789-123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-  -  123456789-123456789- \n");
   fprintf (my.file_conv, "#==(verb)===  ver  ===========(description)===========  =====(function)=====  ========================(arguments)===================================  ==(test)==  ==========================(results)===================================  t  ========(var)======= \n");
   fprintf (my.file_conv, "SCRP          %3s  %-59.59s  %-70.70s  %02d -------  ---------------------------------------------------------------------- \n", "v21", my.desc, my.meth, my.nscrp);
   /*---(complete)-----------------------*/
   return 0;
}

char
CONV_write         (void)
{
   DEBUG_TOPS   yLOG_enter   (__FUNCTION__);
   switch (my.verb [0]) {
   case 'S'  :  if      (strcmp (my.verb, "SCRP"   ) == 0) {
                   CONV_scrp   ();
                }
                break;
   }
   /*---(complete)-----------------------*/
   DEBUG_TOPS   yLOG_exit    (__FUNCTION__);
   return 0;
}


/*===============================[[ end code ]]===============================*/
