/*===============================[[ beg-code ]]===============================*/
#include    "koios.h"

#include    <yUNIT_solo.h>
#include    <ySTR_solo.h>
#include    <yCOLOR_solo.h>


char  *s_wave     = "/tmp/master.wave";

char
unit_conv_defense (void)
{
   char         x_cshare   =  '-';

   yUNIT_minscrpy ("koios", "koios_conv", "(CONV) verify data defense");
   PROG__unit_quiet  ();

   yUNIT_mincond  ("verify a quick success");
   yUNIT_minval   ("call defense"                       , CONV__defense (0xabcd    , "SHARED"  , "testing description" , "DITTO_parse"    , "x, y, 21"       , "i_lesser"  , "pretty expected", "rc"        , '-', '-', "10", &x_cshare  ),    0);
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("attempt with various nulls");
   yUNIT_minval   ("call defense"                       , CONV__defense (NULL      , "SHARED"  , "testing description" , "DITTO_parse"    , "x, y, 21"       , "i_lesser"  , "pretty expected", "rc"        , '-', '-', "10", &x_cshare  ), -999);
   yUNIT_minval   ("call defense"                       , CONV__defense (0xFFFF    , NULL      , "testing description" , "DITTO_parse"    , "x, y, 21"       , "i_lesser"  , "pretty expected", "rc"        , '-', '-', "10", &x_cshare  ), -999);
   yUNIT_minval   ("call defense"                       , CONV__defense (0xFFFF    , "SHARED"  , NULL                  , "DITTO_parse"    , "x, y, 21"       , "i_lesser"  , "pretty expected", "rc"        , '-', '-', "10", &x_cshare  ), -999);
   yUNIT_minval   ("call defense"                       , CONV__defense (0xFFFF    , "SHARED"  , "testing description" , NULL             , "x, y, 21"       , "i_lesser"  , "pretty expected", "rc"        , '-', '-', "10", &x_cshare  ), -999);
   yUNIT_minval   ("call defense"                       , CONV__defense (0xFFFF    , "SHARED"  , "testing description" , "DITTO_parse"    , NULL             , "i_lesser"  , "pretty expected", "rc"        , '-', '-', "10", &x_cshare  ), -999);
   yUNIT_minval   ("call defense"                       , CONV__defense (0xFFFF    , "SHARED"  , "testing description" , "DITTO_parse"    , "x, y, 21"       , NULL        , "pretty expected", "rc"        , '-', '-', "10", &x_cshare  ), -999);
   yUNIT_minval   ("call defense"                       , CONV__defense (0xFFFF    , "SHARED"  , "testing description" , "DITTO_parse"    , "x, y, 21"       , "i_lesser"  , NULL             , "rc"        , '-', '-', "10", &x_cshare  ), -999);
   yUNIT_minval   ("call defense"                       , CONV__defense (0xFFFF    , "SHARED"  , "testing description" , "DITTO_parse"    , "x, y, 21"       , "i_lesser"  , "pretty expected", NULL        , '-', '-', "10", &x_cshare  ), -999);
   yUNIT_minval   ("call defense"                       , CONV__defense (0xFFFF    , "SHARED"  , "testing description" , "DITTO_parse"    , "x, y, 21"       , "i_lesser"  , "pretty expected", "rc"        , '-', '-', NULL, &x_cshare  ), -999);
   yUNIT_minval   ("call defense"                       , CONV__defense (0xFFFF    , "SHARED"  , "testing description" , "DITTO_parse"    , "x, y, 21"       , "i_lesser"  , "pretty expected", "rc"        , '-', '-', "10", NULL       ), -999);
   yUNIT_mindnoc  ();

   PROG__unit_end    ();
   yUNIT_minprcs  ();
   return 0;
}

char
main                    (void)
{
   /*---(program wide)-------------------*/
   system ("rm -f koios_conv.wave");
   unit_conv_defense  ();

   yUNIT_mintinu    ();
   return 0;
}

