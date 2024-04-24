/*===============================[[ beg-code ]]===============================*/
#include    "koios.h"

/*> #include    <yURG.h>                                                              <*/
#include    <yUNIT_solo.h>
#include    <ySTR_solo.h>
#include    <yCOLOR_solo.h>


char  *s_wave     = "/tmp/master.wave";

char
unit_wave_parse          (void)
{
   /*---(locals)-----------+-----+-----+-*/
   char    x_stage [LEN_SHORT] = "";
   /*---(header)-------------------------*/
   yUNIT_minscrpy ("koios", "koios_wave", "(WAVE) parse wave information");
   /*> yURG_err_none  ();  /+ not to stderr/terminal +/                               <*/

   yUNIT_mincond  ("verify quick success");
   yUNIT_minval   ("parse wave"                         , WAVE_parse      ("koios_wave",  1,  "SCRP"  , "SCRP    [1a]", x_stage), 1   );
   yUNIT_minstr   ("... check result"                   , x_stage                             , "1a/·");
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("attempt with nulls");
   yUNIT_minval   ("parse wave"                         , WAVE_parse      (NULL        ,  1,  "SCRP"  , "SCRP    [1a]", x_stage), -999);
   yUNIT_minstr   ("... check result"                   , x_stage                             , "··/·");
   yUNIT_minval   ("parse wave"                         , WAVE_parse      ("koios_wave",  1,  NULL    , "SCRP    [1a]", x_stage), -999);
   yUNIT_minstr   ("... check result"                   , x_stage                             , "··/·");
   yUNIT_minval   ("parse wave"                         , WAVE_parse      ("koios_wave",  1,  "SCRP"  , NULL          , x_stage), -999);
   yUNIT_minstr   ("... check result"                   , x_stage                             , "··/·");
   yUNIT_minval   ("parse wave"                         , WAVE_parse      ("koios_wave",  1,  "SCRP"  , "SCRP    [1a]", NULL   ), 1   );
   yUNIT_minstr   ("... check result"                   , x_stage                             , "··/·");
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify ignoring non-SCRP verbs");
   yUNIT_minval   ("parse wave"                         , WAVE_parse      ("koios_wave",  2,  "COND"  , "COND  (0)"   , x_stage), 0   );
   yUNIT_minstr   ("... check result"                   , x_stage                             , "··/·");
   yUNIT_minval   ("parse wave"                         , WAVE_parse      ("koios_wave",  3,  "exec"  , "exec   "     , x_stage), 0   );
   yUNIT_minstr   ("... check result"                   , x_stage                             , "··/·");
   yUNIT_minval   ("parse wave"                         , WAVE_parse      ("koios_wave",  4,  "SHARE" , "SHARE   -a-" , x_stage), 0   );
   yUNIT_minstr   ("... check result"                   , x_stage                             , "··/·");
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("attempt with bad lengths");
   yUNIT_minval   ("parse wave"                         , WAVE_parse      ("koios_wave",  1,  "SCRP"  , "SCRP      []", x_stage), -999);
   yUNIT_minstr   ("... check result"                   , x_stage                             , "··/·");
   yUNIT_minval   ("parse wave"                         , WAVE_parse      ("koios_wave",  1,  "SCRP"  , "SCRP     [a]", x_stage), -999);
   yUNIT_minstr   ("... check result"                   , x_stage                             , "··/·");
   yUNIT_minval   ("parse wave"                         , WAVE_parse      ("koios_wave",  1,  "SCRP"  , "SCRP   [1aK]", x_stage), -999);
   yUNIT_minstr   ("... check result"                   , x_stage                             , "··/·");
   yUNIT_minval   ("parse wave"                         , WAVE_parse      ("koios_wave",  1,  "SCRP"  , "SCRP [1a/Ka]", x_stage), -999);
   yUNIT_minstr   ("... check result"                   , x_stage                             , "··/·");
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify a long-form success");
   yUNIT_minval   ("parse wave"                         , WAVE_parse      ("koios_wave",  1,  "SCRP"  , "SCRP  [2f/A]", x_stage), 1   );
   yUNIT_minstr   ("... check result"                   , x_stage                             , "2f/A");
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("attempt with no delimiters");
   yUNIT_minval   ("parse wave"                         , WAVE_parse      ("koios_wave",  1,  "SCRP"  , "SCRP      1a", x_stage), -999);
   yUNIT_minstr   ("... check result"                   , x_stage                             , "··/·");
   yUNIT_minval   ("parse wave"                         , WAVE_parse      ("koios_wave",  1,  "SCRP"  , "SCRP    1a/K", x_stage), -999);
   yUNIT_minstr   ("... check result"                   , x_stage                             , "··/·");

   yUNIT_mincond  ("attempt with bad delimiters");
   yUNIT_minval   ("parse wave"                         , WAVE_parse      ("koios_wave",  1,  "SCRP"  , "SCRP    -1a-", x_stage), -999);
   yUNIT_minstr   ("... check result"                   , x_stage                             , "··/·");
   yUNIT_minval   ("parse wave"                         , WAVE_parse      ("koios_wave",  1,  "SCRP"  , "SCRP    [1a-", x_stage), -999);
   yUNIT_minstr   ("... check result"                   , x_stage                             , "··/·");
   yUNIT_minval   ("parse wave"                         , WAVE_parse      ("koios_wave",  1,  "SCRP"  , "SCRP    -1a]", x_stage), -999);
   yUNIT_minstr   ("... check result"                   , x_stage                             , "··/·");
   yUNIT_minval   ("parse wave"                         , WAVE_parse      ("koios_wave",  1,  "SCRP"  , "SCRP    (1a)", x_stage), -999);
   yUNIT_minstr   ("... check result"                   , x_stage                             , "··/·");
   yUNIT_minval   ("parse wave"                         , WAVE_parse      ("koios_wave",  1,  "SCRP"  , "SCRP    [1a)", x_stage), -999);
   yUNIT_minstr   ("... check result"                   , x_stage                             , "··/·");
   yUNIT_minval   ("parse wave"                         , WAVE_parse      ("koios_wave",  1,  "SCRP"  , "SCRP    (1a]", x_stage), -999);
   yUNIT_minstr   ("... check result"                   , x_stage                             , "··/·");
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("attempt with single delimiters");
   yUNIT_minval   ("parse wave"                         , WAVE_parse      ("koios_wave",  1,  "SCRP"  , "SCRP     [1a", x_stage), -999);
   yUNIT_minstr   ("... check result"                   , x_stage                             , "··/·");
   yUNIT_minval   ("parse wave"                         , WAVE_parse      ("koios_wave",  1,  "SCRP"  , "SCRP     1a]", x_stage), -999);
   yUNIT_minstr   ("... check result"                   , x_stage                             , "··/·");
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify various legal wave ids");
   yUNIT_minval   ("parse wave"                         , WAVE_parse      ("koios_wave",  1,  "SCRP"  , "SCRP  [3a/A]", x_stage), 1   );
   yUNIT_minstr   ("... check result"                   , x_stage                             , "3a/A");
   yUNIT_minval   ("parse wave"                         , WAVE_parse      ("koios_wave",  1,  "SCRP"  , "SCRP  [6a/A]", x_stage), 1   );
   yUNIT_minstr   ("... check result"                   , x_stage                             , "6a/A");
   yUNIT_minval   ("parse wave"                         , WAVE_parse      ("koios_wave",  1,  "SCRP"  , "SCRP  [9a/A]", x_stage), 1   );
   yUNIT_minstr   ("... check result"                   , x_stage                             , "9a/A");
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("attempt bad wave ids");
   yUNIT_minval   ("parse wave"                         , WAVE_parse      ("koios_wave",  1,  "SCRP"  , "SCRP    [aa]", x_stage), -999);
   yUNIT_minstr   ("... check result"                   , x_stage                             , "··/·");
   yUNIT_minval   ("parse wave"                         , WAVE_parse      ("koios_wave",  1,  "SCRP"  , "SCRP    [Ma]", x_stage), -999);
   yUNIT_minstr   ("... check result"                   , x_stage                             , "··/·");
   yUNIT_minval   ("parse wave"                         , WAVE_parse      ("koios_wave",  1,  "SCRP"  , "SCRP    [?a]", x_stage), -999);
   yUNIT_minstr   ("... check result"                   , x_stage                             , "··/·");
   yUNIT_minval   ("parse wave"                         , WAVE_parse      ("koios_wave",  1,  "SCRP"  , "SCRP    [éa]", x_stage), -999);
   yUNIT_minstr   ("... check result"                   , x_stage                             , "··/·");
   yUNIT_minval   ("parse wave"                         , WAVE_parse      ("koios_wave",  1,  "SCRP"  , "SCRP    [.a]", x_stage), -999);
   yUNIT_minstr   ("... check result"                   , x_stage                             , "··/·");
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify various legal stage ids");
   yUNIT_minval   ("parse wave"                         , WAVE_parse      ("koios_wave",  1,  "SCRP"  , "SCRP  [4c/A]", x_stage), 1   );
   yUNIT_minstr   ("... check result"                   , x_stage                             , "4c/A");
   yUNIT_minval   ("parse wave"                         , WAVE_parse      ("koios_wave",  1,  "SCRP"  , "SCRP  [4q/A]", x_stage), 1   );
   yUNIT_minstr   ("... check result"                   , x_stage                             , "4q/A");
   yUNIT_minval   ("parse wave"                         , WAVE_parse      ("koios_wave",  1,  "SCRP"  , "SCRP  [4z/A]", x_stage), 1   );
   yUNIT_minstr   ("... check result"                   , x_stage                             , "4z/A");
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("attempt bad stage ids");
   yUNIT_minval   ("parse wave"                         , WAVE_parse      ("koios_wave",  1,  "SCRP"  , "SCRP    [11]", x_stage), -999);
   yUNIT_minstr   ("... check result"                   , x_stage                             , "··/·");
   yUNIT_minval   ("parse wave"                         , WAVE_parse      ("koios_wave",  1,  "SCRP"  , "SCRP    [1A]", x_stage), -999);
   yUNIT_minstr   ("... check result"                   , x_stage                             , "··/·");
   yUNIT_minval   ("parse wave"                         , WAVE_parse      ("koios_wave",  1,  "SCRP"  , "SCRP    [1ò]", x_stage), -999);
   yUNIT_minstr   ("... check result"                   , x_stage                             , "··/·");
   yUNIT_minval   ("parse wave"                         , WAVE_parse      ("koios_wave",  1,  "SCRP"  , "SCRP    [1?]", x_stage), -999);
   yUNIT_minstr   ("... check result"                   , x_stage                             , "··/·");
   yUNIT_minval   ("parse wave"                         , WAVE_parse      ("koios_wave",  1,  "SCRP"  , "SCRP    [1.]", x_stage), -999);
   yUNIT_minstr   ("... check result"                   , x_stage                             , "··/·");

   yUNIT_mincond  ("verify various legal rating ids");
   yUNIT_minval   ("parse wave"                         , WAVE_parse      ("koios_wave",  1,  "SCRP"  , "SCRP  [4m/C]", x_stage), 1   );
   yUNIT_minstr   ("... check result"                   , x_stage                             , "4m/C");
   yUNIT_minval   ("parse wave"                         , WAVE_parse      ("koios_wave",  1,  "SCRP"  , "SCRP  [4m/L]", x_stage), 1   );
   yUNIT_minstr   ("... check result"                   , x_stage                             , "4m/L");
   yUNIT_minval   ("parse wave"                         , WAVE_parse      ("koios_wave",  1,  "SCRP"  , "SCRP  [4m/Y]", x_stage), 1   );
   yUNIT_minstr   ("... check result"                   , x_stage                             , "4m/Y");
   yUNIT_minval   ("parse wave"                         , WAVE_parse      ("koios_wave",  1,  "SCRP"  , "SCRP  [1a/a]", x_stage), 1   );
   yUNIT_minstr   ("... check result"                   , x_stage                             , "1a/a");
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("attempt bad rating ids");
   yUNIT_minval   ("parse wave"                         , WAVE_parse      ("koios_wave",  1,  "SCRP"  , "SCRP  [1a/5]", x_stage), -999);
   yUNIT_minstr   ("... check result"                   , x_stage                             , "··/·");
   yUNIT_minval   ("parse wave"                         , WAVE_parse      ("koios_wave",  1,  "SCRP"  , "SCRP  [1a/?]", x_stage), -999);
   yUNIT_minstr   ("... check result"                   , x_stage                             , "··/·");
   yUNIT_minval   ("parse wave"                         , WAVE_parse      ("koios_wave",  1,  "SCRP"  , "SCRP  [1a/þ]", x_stage), -999);
   yUNIT_minstr   ("... check result"                   , x_stage                             , "··/·");
   yUNIT_minval   ("parse wave"                         , WAVE_parse      ("koios_wave",  1,  "SCRP"  , "SCRP  [1a/.]", x_stage), -999);
   yUNIT_minstr   ("... check result"                   , x_stage                             , "··/·");

   /*---(complete)-----------------------*/
   yUNIT_minprcs  ();
   return 0;
}

char
main                    (void)
{
   /*---(program wide)-------------------*/
   system ("rm -f koios_wave.wave");
   unit_wave_parse  ();

   yUNIT_mintinu    ();
   return 0;
}

