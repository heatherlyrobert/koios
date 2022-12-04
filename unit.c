/*===============================[[ beg-code ]]===============================*/
#include    "koios.h"        /* LOCAL  : main header                          */

#include    "ySTR_solo.h"
#include    "yCOLOR_solo.h"
#include    "yUNIT_solo.h"



/*====================------------------------------------====================*/
/*===----                      general functions                       ----===*/
/*====================------------------------------------====================*/
static void      o___GENERAL_________________o (void) {;}

char
koios__unit_prog_file    (void)
{
   yUNIT_minscrp ("PROG_file");
   yURG_err_none ();  /* not to stderr/terminal */

   yUNIT_mincond ("prepare clean start");
   system ("rm -f /tmp/linked.unit       2> /dev/null");
   system ("rm -f /tmp/koios.unit        2> /dev/null");
   system ("rm -f /tmp/koios-a.unit      2> /dev/null");
   system ("rm -f /tmp/koios_a.unit      2> /dev/null");
   yUNIT_mindnoc ();

   yUNIT_mincond ("quick success");
   system ("touch /tmp/koios.unit        2> /dev/null");
   yUNIT_minval ("... run file check"                 , PROG_file ("/tmp/koios")           , 0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("attempt a symlink to same file");
   system ("cp -s /tmp/koios.unit /tmp/linked.unit  2> /dev/null");
   yUNIT_minval ("... run file check"                 , PROG_file ("/tmp/linked")          , -999);
   yUNIT_mindnoc ();

   yUNIT_mincond ("same file after deletion");
   system ("rm -f /tmp/koios.unit        2> /dev/null");
   yUNIT_minval ("... run file check"                 , PROG_file ("/tmp/koios")           , -999);
   yUNIT_mindnoc ();

   yUNIT_mincond ("badly named unit test");
   system ("touch /tmp/koios-a.unit      2> /dev/null");
   yUNIT_minval ("... run file check"                 , PROG_file ("/tmp/koios-a")         , -999);
   yUNIT_mindnoc ();

   yUNIT_mincond ("named with underscore");
   system ("touch /tmp/koios_a.unit      2> /dev/null");
   yUNIT_minval ("... run file check"                 , PROG_file ("/tmp/koios_a")         , 0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("called with extention");
   yUNIT_minval ("... run file check"                 , PROG_file ("/tmp/koios_a.unit")    , 0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("clean up at end");
   system ("rm -f /tmp/linked.unit       2> /dev/null");
   system ("rm -f /tmp/koios.unit        2> /dev/null");
   system ("rm -f /tmp/koios-a.unit      2> /dev/null");
   system ("rm -f /tmp/koios_a.unit      2> /dev/null");
   yUNIT_mindnoc ();

   yUNIT_minprcs ();
   return 0;
}

char
koios__unit_prog_args    (void)
{
   yUNIT_minscrp ("PROG_args");
   yURG_err_none ();  /* not to stderr/terminal */

   yUNIT_mincond ("prepare clean start");
   system ("rm -f /tmp/koios.unit 2> /dev/null");
   char  *x_argA [2]  = { "koios_unit" , "--debug"       };
   char  *x_argB [2]  = { "koios_unit" , "--compile"     };
   char  *x_argC [2]  = { "koios_unit" , "--debugery"    };
   char  *x_argD [2]  = { "koios_unit" , "--create"      };
   char  *x_argE [2]  = { "koios_unit" , "--convert"     };
   char  *x_argF [1]  = { "koios_unit" };
   char  *x_argG [2]  = { "koios_unit" , "--update"      };
   yUNIT_mindnoc ();

   yUNIT_mincond ("check defaults");
   yUNIT_minval ("... run init"                       , PROG_init ()          , 0);
   yUNIT_minchr ("... check run type"                 , my.run_type , G_RUN_CREATE);
   yUNIT_minchr ("... check run replace"              , my.replace  , G_RUN_DEFAULT);
   yUNIT_mindnoc ();

   yUNIT_mincond ("run with debug");
   yUNIT_minval ("... run init"                       , PROG_init ()          , 0);
   yUNIT_minval ("... run args"                       , PROG_args (2, x_argA) , 0);
   yUNIT_minchr ("... check run type"                 , my.run_type , G_RUN_DEBUG);
   yUNIT_minchr ("... check run replace"              , my.replace  , G_RUN_DEFAULT);
   yUNIT_mindnoc ();

   yUNIT_mincond ("run with compile");
   yUNIT_minval ("... run init"                       , PROG_init ()          , 0);
   yUNIT_minval ("... run args"                       , PROG_args (2, x_argB) , 0);
   yUNIT_minchr ("... check run type"                 , my.run_type , G_RUN_CREATE);
   yUNIT_minchr ("... check run replace"              , my.replace  , G_RUN_DEFAULT);
   yUNIT_mindnoc ();

   yUNIT_mincond ("run with bad argument");
   yUNIT_minval ("... run init"                       , PROG_init ()          , 0);
   yUNIT_minval ("... run args"                       , PROG_args (2, x_argC) , -999);
   yUNIT_minchr ("... check run type"                 , my.run_type , G_RUN_CREATE);
   yUNIT_minchr ("... check run replace"              , my.replace  , G_RUN_DEFAULT);
   yUNIT_mindnoc ();

   yUNIT_mincond ("run with create");
   yUNIT_minval ("... run init"                       , PROG_init ()          , 0);
   yUNIT_minval ("... run args"                       , PROG_args (2, x_argD) , 0);
   yUNIT_minchr ("... check run type"                 , my.run_type , G_RUN_CREATE);
   yUNIT_minchr ("... check run replace"              , my.replace  , G_RUN_DEFAULT);
   yUNIT_mindnoc ();

   yUNIT_mincond ("run with convert");
   yUNIT_minval ("... run init"                       , PROG_init ()          , 0);
   yUNIT_minval ("... run args"                       , PROG_args (2, x_argE) , 0);
   yUNIT_minchr ("... check run type"                 , my.run_type , G_RUN_UPDATE);
   yUNIT_minchr ("... check run replace"              , my.replace  , G_RUN_DEFAULT);
   yUNIT_mindnoc ();

   yUNIT_mincond ("run with no arguments");
   yUNIT_minval ("... run init"                       , PROG_init ()          , 0);
   yUNIT_minval ("... run args"                       , PROG_args (1, x_argF) , 0);
   yUNIT_minchr ("... check run type"                 , my.run_type , G_RUN_CREATE);
   yUNIT_minchr ("... check run replace"              , my.replace  , G_RUN_DEFAULT);
   yUNIT_mindnoc ();

   yUNIT_mincond ("run with update");
   yUNIT_minval ("... run init"                       , PROG_init ()          , 0);
   yUNIT_minval ("... run args"                       , PROG_args (2, x_argG) , 0);
   yUNIT_minchr ("... check run type"                 , my.run_type , G_RUN_UPDATE);
   yUNIT_minchr ("... check run replace"              , my.replace  , G_RUN_REPLACE);
   yUNIT_mindnoc ();

   yUNIT_minprcs ();
   return 0;
}

char
koios__unit_prog_shared  (void)
{
   yUNIT_minscrp ("SCRP__shared");
   yURG_err_none ();  /* not to stderr/terminal */

   yUNIT_mincond ("prepare clean start");
   system ("rm -f /tmp/koios.unit 2> /dev/null");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check defaults");
   yUNIT_minval ("... run clear"                      , SCRP__shared_purge ()         , 0);
   yUNIT_minstr ("... check all marks"                , SCRP__shared_used  ()         , "--------------------------   --------------------------   ----------");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check master indexing");
   yUNIT_minval ("... master min"                     , SCRP__shared_index ('m', 'A') ,    0);
   yUNIT_minval ("... master middle"                  , SCRP__shared_index ('m', 'J') ,    9);
   yUNIT_minval ("... master max"                     , SCRP__shared_index ('m', 'Z') ,   25);
   yUNIT_minval ("... master too small"               , SCRP__shared_index ('m',  0 ) , -999);
   yUNIT_minval ("... master using reuses"            , SCRP__shared_index ('m', 'b') , -999);
   yUNIT_minval ("... master using dittos"            , SCRP__shared_index ('m', '4') , -999);
   yUNIT_minval ("... master using greek"             , SCRP__shared_index ('m', 'ë') , -999);
   yUNIT_mindnoc ();

   yUNIT_mincond ("check reuses indexing");
   yUNIT_minval ("... reuses min"                     , SCRP__shared_index ('r', 'a') ,    0);
   yUNIT_minval ("... reuses middle"                  , SCRP__shared_index ('r', 'm') ,   12);
   yUNIT_minval ("... reuses max"                     , SCRP__shared_index ('r', 'z') ,   25);
   yUNIT_minval ("... reuses too small"               , SCRP__shared_index ('r',  0 ) , -999);
   yUNIT_minval ("... reuses using master"            , SCRP__shared_index ('r', 'B') , -999);
   yUNIT_minval ("... reuses using dittos"            , SCRP__shared_index ('r', '4') , -999);
   yUNIT_minval ("... reuses using greek"             , SCRP__shared_index ('r', 'ë') , -999);
   yUNIT_mindnoc ();

   yUNIT_mincond ("check dittos indexing");
   yUNIT_minval ("... dittos min"                     , SCRP__shared_index ('d', '0') ,    0);
   yUNIT_minval ("... dittos middle"                  , SCRP__shared_index ('d', '4') ,    4);
   yUNIT_minval ("... dittos max"                     , SCRP__shared_index ('d', '9') ,    9);
   yUNIT_minval ("... dittos too small"               , SCRP__shared_index ('d',  0 ) , -999);
   yUNIT_minval ("... dittos using master"            , SCRP__shared_index ('d', 'B') , -999);
   yUNIT_minval ("... dittos using reuses"            , SCRP__shared_index ('d', 'j') , -999);
   yUNIT_minval ("... dittos using greek"             , SCRP__shared_index ('d', 'ë') , -999);
   yUNIT_mindnoc ();

   yUNIT_mincond ("check indexing with bad types");
   yUNIT_minval ("... check null"                     , SCRP__shared_index ( 0 , '0') , -999);
   yUNIT_minval ("... check symbol"                   , SCRP__shared_index ('#', '0') , -999);
   yUNIT_minval ("... check greek"                    , SCRP__shared_index ('è', '0') , -999);
   yUNIT_mindnoc ();

   yUNIT_mincond ("get masters before setting");
   yUNIT_minstr ("... check all marks"                , SCRP__shared_used  ()         , "--------------------------   --------------------------   ----------");
   yUNIT_minval ("... get master min"                 , SCRP__shared_get   ('m', 'A') , -999);
   yUNIT_minval ("... get master middle"              , SCRP__shared_get   ('m', 'J') , -999);
   yUNIT_minval ("... get master max"                 , SCRP__shared_get   ('m', 'Z') , -999);
   yUNIT_minval ("... get master null"                , SCRP__shared_get   ('m',  0 ) , -999);
   yUNIT_minval ("... get master reuses"              , SCRP__shared_get   ('m', 'b') , -999);
   yUNIT_minval ("... get master dittos"              , SCRP__shared_get   ('m', '4') , -999);
   yUNIT_minval ("... get master greek"               , SCRP__shared_get   ('m', 'ë') , -999);
   yUNIT_minval ("... get master symbol"              , SCRP__shared_get   ('m', '-') , -999);

   yUNIT_mincond ("set masters");
   yUNIT_minstr ("... check all marks"                , SCRP__shared_used  ()         , "--------------------------   --------------------------   ----------");
   my.n_line = 15;
   yUNIT_minval ("... set master min"                 , SCRP__shared_set   ('m', 'A') ,    0);
   yUNIT_minstr ("... check all marks"                , SCRP__shared_used  ()         , "A-------------------------   --------------------------   ----------");
   my.n_line = 30;
   yUNIT_minval ("... set master middle"              , SCRP__shared_set   ('m', 'J') ,    0);
   yUNIT_minstr ("... check all marks"                , SCRP__shared_used  ()         , "A--------J----------------   --------------------------   ----------");
   my.n_line = 45;
   yUNIT_minval ("... set master max"                 , SCRP__shared_set   ('m', 'Z') ,    0);
   yUNIT_minstr ("... check all marks"                , SCRP__shared_used  ()         , "A--------J---------------Z   --------------------------   ----------");
   yUNIT_mindnoc ();

   yUNIT_mincond ("get masters after setting");
   yUNIT_minstr ("... check all marks"                , SCRP__shared_used  ()         , "A--------J---------------Z   --------------------------   ----------");
   yUNIT_minval ("... get master min"                 , SCRP__shared_get   ('m', 'A') ,   15);
   yUNIT_minval ("... get master middle"              , SCRP__shared_get   ('m', 'J') ,   30);
   yUNIT_minval ("... get master max"                 , SCRP__shared_get   ('m', 'Z') ,   45);
   yUNIT_minval ("... get master null"                , SCRP__shared_get   ('m',  0 ) , -999);
   yUNIT_minval ("... get master reuses"              , SCRP__shared_get   ('m', 'b') , -999);
   yUNIT_minval ("... get master dittos"              , SCRP__shared_get   ('m', '4') , -999);
   yUNIT_minval ("... get master greek"               , SCRP__shared_get   ('m', 'ë') , -999);
   yUNIT_minval ("... get master symbol"              , SCRP__shared_get   ('m', '-') , -999);

   yUNIT_mincond ("get reuses before setting");
   yUNIT_minstr ("... check all marks"                , SCRP__shared_used  ()         , "A--------J---------------Z   --------------------------   ----------");
   yUNIT_minval ("... get reuses min"                 , SCRP__shared_get   ('r', 'a') , -999);
   yUNIT_minval ("... get reuses middle"              , SCRP__shared_get   ('r', 'm') , -999);
   yUNIT_minval ("... get reuses max"                 , SCRP__shared_get   ('r', 'z') , -999);
   yUNIT_minval ("... get reuses null"                , SCRP__shared_get   ('r',  0 ) , -999);
   yUNIT_minval ("... get reuses master"              , SCRP__shared_get   ('r', 'B') , -999);
   yUNIT_minval ("... get reuses dittos"              , SCRP__shared_get   ('r', '4') , -999);
   yUNIT_minval ("... get reuses greek"               , SCRP__shared_get   ('r', 'ë') , -999);
   yUNIT_minval ("... get reuses symbol"              , SCRP__shared_get   ('r', '-') , -999);

   yUNIT_mincond ("set reuses");
   yUNIT_minstr ("... check all marks"                , SCRP__shared_used  ()         , "A--------J---------------Z   --------------------------   ----------");
   my.n_line = 60;
   yUNIT_minval ("... set reuses min"                 , SCRP__shared_set   ('r', 'a') ,    0);
   yUNIT_minstr ("... check all marks"                , SCRP__shared_used  ()         , "A--------J---------------Z   a-------------------------   ----------");
   my.n_line = 75;
   yUNIT_minval ("... set reuses middle"              , SCRP__shared_set   ('r', 'm') ,    0);
   yUNIT_minstr ("... check all marks"                , SCRP__shared_used  ()         , "A--------J---------------Z   a-----------m-------------   ----------");
   my.n_line = 90;
   yUNIT_minval ("... set reuses max"                 , SCRP__shared_set   ('r', 'z') ,    0);
   yUNIT_minstr ("... check all marks"                , SCRP__shared_used  ()         , "A--------J---------------Z   a-----------m------------z   ----------");
   yUNIT_mindnoc ();

   yUNIT_mincond ("get reuses after setting");
   yUNIT_minstr ("... check all marks"                , SCRP__shared_used  ()         , "A--------J---------------Z   a-----------m------------z   ----------");
   yUNIT_minval ("... get reuses min"                 , SCRP__shared_get   ('r', 'a') ,   60);
   yUNIT_minval ("... get reuses middle"              , SCRP__shared_get   ('r', 'm') ,   75);
   yUNIT_minval ("... get reuses max"                 , SCRP__shared_get   ('r', 'z') ,   90);
   yUNIT_minval ("... get reuses null"                , SCRP__shared_get   ('r',  0 ) , -999);
   yUNIT_minval ("... get reuses master"              , SCRP__shared_get   ('r', 'B') , -999);
   yUNIT_minval ("... get reuses dittos"              , SCRP__shared_get   ('r', '4') , -999);
   yUNIT_minval ("... get reuses greek"               , SCRP__shared_get   ('r', 'ë') , -999);
   yUNIT_minval ("... get reuses symbol"              , SCRP__shared_get   ('r', '-') , -999);

   yUNIT_mincond ("get dittos before setting");
   yUNIT_minstr ("... check all marks"                , SCRP__shared_used  ()         , "A--------J---------------Z   a-----------m------------z   ----------");
   yUNIT_minval ("... get dittos min"                 , SCRP__shared_get   ('d', 'a') , -999);
   yUNIT_minval ("... get dittos middle"              , SCRP__shared_get   ('d', 'm') , -999);
   yUNIT_minval ("... get dittos max"                 , SCRP__shared_get   ('d', 'z') , -999);
   yUNIT_minval ("... get dittos null"                , SCRP__shared_get   ('d',  0 ) , -999);
   yUNIT_minval ("... get dittos master"              , SCRP__shared_get   ('d', 'B') , -999);
   yUNIT_minval ("... get dittos reuses"              , SCRP__shared_get   ('d', 'j') , -999);
   yUNIT_minval ("... get dittos greek"               , SCRP__shared_get   ('d', 'ë') , -999);
   yUNIT_minval ("... get dittos symbol"              , SCRP__shared_get   ('d', '-') , -999);

   yUNIT_mincond ("set dittos");
   yUNIT_minstr ("... check all marks"                , SCRP__shared_used  ()         , "A--------J---------------Z   a-----------m------------z   ----------");
   my.n_line = 92;
   yUNIT_minval ("... set dittos min"                 , SCRP__shared_set   ('d', '0') ,    0);
   yUNIT_minstr ("... check all marks"                , SCRP__shared_used  ()         , "A--------J---------------Z   a-----------m------------z   0---------");
   my.n_line = 94;
   yUNIT_minval ("... set dittos middle"              , SCRP__shared_set   ('d', '4') ,    0);
   yUNIT_minstr ("... check all marks"                , SCRP__shared_used  ()         , "A--------J---------------Z   a-----------m------------z   0---4-----");
   my.n_line = 98;
   yUNIT_minval ("... set dittos max"                 , SCRP__shared_set   ('d', '9') ,    0);
   yUNIT_minstr ("... check all marks"                , SCRP__shared_used  ()         , "A--------J---------------Z   a-----------m------------z   0---4----9");
   yUNIT_mindnoc ();

   yUNIT_mincond ("get dittos after setting");
   yUNIT_minstr ("... check all marks"                , SCRP__shared_used  ()         , "A--------J---------------Z   a-----------m------------z   0---4----9");
   yUNIT_minval ("... get dittos min"                 , SCRP__shared_get   ('d', '0') ,   92);
   yUNIT_minval ("... get dittos middle"              , SCRP__shared_get   ('d', '4') ,   94);
   yUNIT_minval ("... get dittos max"                 , SCRP__shared_get   ('d', '9') ,   98);
   yUNIT_minval ("... get dittos null"                , SCRP__shared_get   ('d',  0 ) , -999);
   yUNIT_minval ("... get dittos master"              , SCRP__shared_get   ('d', 'B') , -999);
   yUNIT_minval ("... get dittos reuses"              , SCRP__shared_get   ('d', 'j') , -999);
   yUNIT_minval ("... get dittos greek"               , SCRP__shared_get   ('d', 'ë') , -999);
   yUNIT_minval ("... get dittos symbol"              , SCRP__shared_get   ('d', '-') , -999);

   yUNIT_mincond ("check defaults");
   yUNIT_minval ("... run clear"                      , SCRP__shared_purge ()         , 0);
   yUNIT_minstr ("... check all marks"                , SCRP__shared_used  ()         , "--------------------------   --------------------------   ----------");
   yUNIT_mindnoc ();

   yUNIT_minprcs ();
   return 0;
}



/*====================------------------------------------====================*/
/*===----                     script reading                           ----===*/
/*====================------------------------------------====================*/
static void      o___SCRP____________________o (void) {;}

char
koios__unit_scrp_files   (void)
{
   yUNIT_minscrp ("koios_scrp file open and close");
   yURG_err_none ();  /* not to stderr/terminal */

   yUNIT_mincond ("prepare clean start");
   system ("rm -f /tmp/koios.unit 2> /dev/null");
   yUNIT_mindnoc ();

   yUNIT_mincond ("attempt to open with no name");
   strcpy (my.n_scrp, "");
   strcpy (my.n_wave, "");
   yUNIT_minstr ("... check script name"              , my.n_scrp     , "");
   yUNIT_minval ("... check script pointer"           , my.f_scrp     , 0);
   yUNIT_minstr ("... check wave name"                , my.n_wave     , "");
   yUNIT_minval ("... check wave pointer"             , my.f_wave     , 0);
   yUNIT_minval ("open the script file"               , SCRP_open   (), -999);
   yUNIT_minstr ("... check script name"              , my.n_scrp     , "");
   yUNIT_minval ("... check script pointer"           , my.f_scrp     , 0);
   yUNIT_minstr ("... check wave name"                , my.n_wave     , "");
   yUNIT_minval ("... check wave pointer"             , my.f_wave     , 0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("attempt to close when not open");
   strcpy (my.n_scrp, "");
   strcpy (my.n_wave, "");
   yUNIT_minstr ("... check script name"              , my.n_scrp     , "");
   yUNIT_minval ("... check script pointer"           , my.f_scrp     , 0);
   yUNIT_minstr ("... check wave name"                , my.n_wave     , "");
   yUNIT_minval ("... check wave pointer"             , my.f_wave     , 0);
   yUNIT_minval ("close the script file"              , SCRP_close  (), -999);
   yUNIT_minstr ("... check script name"              , my.n_scrp     , "");
   yUNIT_minval ("... check script pointer"           , my.f_scrp     , 0);
   yUNIT_minstr ("... check wave name"                , my.n_wave     , "");
   yUNIT_minval ("... check wave pointer"             , my.f_wave     , 0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("attempt a non-existant name");
   strcpy (my.n_scrp, "/tmp/koios.unit");
   strcpy (my.n_wave, "");
   yUNIT_minstr ("... check script name"              , my.n_scrp     , "/tmp/koios.unit");
   yUNIT_minval ("... check script pointer"           , my.f_scrp     , 0);
   yUNIT_minstr ("... check wave name"                , my.n_wave     , "");
   yUNIT_minval ("... check wave pointer"             , my.f_wave     , 0);
   yUNIT_minval ("open the script file"               , SCRP_open   (), -999);
   yUNIT_minstr ("... check script name"              , my.n_scrp     , "/tmp/koios.unit");
   yUNIT_minval ("... check script pointer"           , my.f_scrp     , 0);
   yUNIT_minstr ("... check wave name"                , my.n_wave     , "");
   yUNIT_minval ("... check wave pointer"             , my.f_wave     , 0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("attempt with real file, but no wave");
   strcpy (my.n_scrp, "/tmp/koios.unit");
   system ("touch /tmp/koios.unit");
   strcpy (my.n_wave, "");
   yUNIT_minstr ("... check script name"              , my.n_scrp     , "/tmp/koios.unit");
   yUNIT_minval ("... check script pointer"           , my.f_scrp     , 0);
   yUNIT_minstr ("... check wave name"                , my.n_wave     , "");
   yUNIT_minval ("... check wave pointer"             , my.f_wave     , 0);
   yUNIT_minval ("open the script file"               , SCRP_open   (), -999);
   yUNIT_minstr ("... check script name"              , my.n_scrp     , "/tmp/koios.unit");
   yUNIT_minval ("... check script pointer"           , my.f_scrp     , 0);
   yUNIT_minstr ("... check wave name"                , my.n_wave     , "");
   yUNIT_minval ("... check wave pointer"             , my.f_wave     , 0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("open with real file and valid wave");
   strcpy (my.n_scrp, "/tmp/koios.unit");
   system ("touch /tmp/koios.unit");
   strcpy (my.n_wave, "/tmp/koios.wave");
   yUNIT_minstr ("... check script name"              , my.n_scrp     , "/tmp/koios.unit");
   yUNIT_minval ("... check script pointer"           , my.f_scrp     , 0);
   yUNIT_minstr ("... check wave name"                , my.n_wave     , "/tmp/koios.wave");
   yUNIT_minval ("... check wave pointer"             , my.f_wave     , 0);
   yUNIT_minval ("open the script file"               , SCRP_open   (), 0);
   yUNIT_minstr ("... check script name"              , my.n_scrp     , "/tmp/koios.unit");
   yUNIT_minval ("... check script pointer"           , my.f_scrp     , my.f_scrp);
   yUNIT_minstr ("... check wave name"                , my.n_wave     , "/tmp/koios.wave");
   yUNIT_minval ("... check wave pointer"             , my.f_wave     , my.f_wave);
   yUNIT_mindnoc ();

   yUNIT_mincond ("close the new name");
   yUNIT_minstr ("... check script name"              , my.n_scrp     , "/tmp/koios.unit");
   yUNIT_minval ("... check script pointer"           , my.f_scrp     , my.f_scrp);
   yUNIT_minval ("close the script file"              , SCRP_close  (), 0);
   yUNIT_minstr ("... check script name"              , my.n_scrp     , "/tmp/koios.unit");
   yUNIT_minval ("... check script pointer"           , my.f_scrp     , 0);
   yUNIT_minstr ("... check wave name"                , my.n_wave     , "/tmp/koios.wave");
   yUNIT_minval ("... check wave pointer"             , my.f_wave     , 0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("attempt to close twice");
   yUNIT_minstr ("... check script name"              , my.n_scrp     , "/tmp/koios.unit");
   yUNIT_minval ("... check script pointer"           , my.f_scrp     , 0);
   yUNIT_minval ("close the script file"              , SCRP_close  (), -999);
   yUNIT_minstr ("... check script name"              , my.n_scrp     , "/tmp/koios.unit");
   yUNIT_minval ("... check script pointer"           , my.f_scrp     , 0);
   yUNIT_minstr ("... check wave name"                , my.n_wave     , "/tmp/koios.wave");
   yUNIT_minval ("... check wave pointer"             , my.f_wave     , 0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("clean up after");
   system ("rm -f /tmp/koios.unit 2> /dev/null");
   yUNIT_mindnoc ();

   yUNIT_minprcs ();
   return 0;
}

char
koios__unit_scrp_read    (void)
{
   yUNIT_minscrp ("koios_scrp reading records");
   yURG_err_none ();  /* not to stderr/terminal */

   yUNIT_mincond ("prepare clean start");
   system ("rm -f /tmp/koios.unit 2> /dev/null");
   yUNIT_mindnoc ();

   yUNIT_mincond ("attempt to read an empty file");
   strcpy (my.n_scrp, "/tmp/koios.unit");
   system ("touch /tmp/koios.unit");
   yUNIT_minstr ("... check script name"              , my.n_scrp     , "/tmp/koios.unit");
   yUNIT_minval ("open the script file"               , SCRP_open   (), 0);
   yUNIT_minval ("... check script pointer"           , my.f_scrp     , my.f_scrp);
   yUNIT_minval ("read a line"                        , SCRP_read   (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , ""               );
   yUNIT_minval ("close the script file"              , SCRP_close  (), 0);
   yUNIT_minval ("... check script pointer"           , my.f_scrp     , 0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify reading a single record");
   strcpy (my.n_scrp, "/tmp/koios.unit");
   system ("echo \"exec     read a line      SCRP_read       i_lesser    0      \"                                             > /tmp/koios.unit");
   yUNIT_minstr ("... check script name"              , my.n_scrp     , "/tmp/koios.unit");
   yUNIT_minval ("open the script file"               , SCRP_open   (), 0);
   yUNIT_minval ("... check script pointer"           , my.f_scrp     , my.f_scrp);
   yUNIT_minval ("read a line"                        , SCRP_read   (), 1);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "exec    § read a line     § SCRP_read   §   § i_lesser   § 0      §");
   yUNIT_minval ("close the script file"              , SCRP_close  (), 0);
   yUNIT_minval ("... check script pointer"           , my.f_scrp     , 0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify skipping non-records");
   strcpy (my.n_scrp, "/tmp/koios.unit");
   system ("echo \"\"                                                                         > /tmp/koios.unit");
   system ("echo \"## just a comment\"                                                       >> /tmp/koios.unit");
   system ("echo \"exec     read a line      SCRP_read       i_lesser    0      \"     >> /tmp/koios.unit");
   yUNIT_minstr ("... check script name"              , my.n_scrp     , "/tmp/koios.unit");
   yUNIT_minval ("open the script file"               , SCRP_open   (), 0);
   yUNIT_minval ("... check script pointer"           , my.f_scrp     , my.f_scrp);
   yUNIT_minval ("read a line"                        , SCRP_read   (), 1);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "exec    § read a line     § SCRP_read   §   § i_lesser   § 0      §");
   yUNIT_minval ("close the script file"              , SCRP_close  (), 0);
   yUNIT_minval ("... check script pointer"           , my.f_scrp     , 0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("clean up after");
   system ("rm -f /tmp/koios.unit 2> /dev/null");
   yUNIT_mindnoc ();

   yUNIT_minprcs ();
   return 0;
}

char
koios__unit_scrp_verb    (void)
{
   yUNIT_minscrp ("koios_scrp identifying verbs");
   yURG_err_none ();  /* not to stderr/terminal */

   yUNIT_mincond ("parse good verbs");
   yUNIT_minval  ("parse SCRP"                         , SCRP_parse_verb ("SCRP"), 0);
   yUNIT_minstr ("... check verb"                      , my.verb       , "SCRP");
   yUNIT_minval ("... check index"                     , my.indx       , 999);
   yUNIT_minval  ("parse COND"                         , SCRP_parse_verb (" COND"), 0);
   yUNIT_minstr ("... check verb"                      , my.verb       , "COND");
   yUNIT_minval ("... check index"                     , my.indx       , 999);
   yUNIT_minval  ("parse exec"                         , SCRP_parse_verb ("  exec"), 0);
   yUNIT_minstr ("... check verb"                      , my.verb       , "exec");
   yUNIT_minval ("... check index"                     , my.indx       , 999);
   yUNIT_mindnoc ();

   yUNIT_mincond ("parse non-existant verbs");
   yUNIT_minval  ("parse trouble"                      , SCRP_parse_verb ("handler") , -999);
   yUNIT_minstr ("... check verb"                      , my.verb       , "");
   yUNIT_minval ("... check index"                     , my.indx       , -999);
   yUNIT_minval  ("parse trouble"                      , SCRP_parse_verb (" and")    , -999);
   yUNIT_minstr ("... check verb"                      , my.verb       , "");
   yUNIT_minval ("... check index"                     , my.indx       , -999);
   yUNIT_minval  ("parse trouble"                      , SCRP_parse_verb (" testing"), -999);
   yUNIT_minstr ("... check verb"                      , my.verb       , "");
   yUNIT_minval ("... check index"                     , my.indx       , -999);
   yUNIT_mindnoc ();

   yUNIT_mincond ("parse prefix of verbs");
   yUNIT_minval  ("parse SHARED"                       , SCRP_parse_verb ("SHARED -a-"), 0);
   yUNIT_minstr ("... check verb"                      , my.verb       , "SHARED");
   yUNIT_minval ("... check index"                     , my.indx       , 999);
   yUNIT_minval  ("parse COND"                         , SCRP_parse_verb (" COND (1)"), 0);
   yUNIT_minstr ("... check verb"                      , my.verb       , "COND");
   yUNIT_minval ("... check index"                     , my.indx       , 999);
   yUNIT_minval  ("parse exec"                         , SCRP_parse_verb ("  exec &"), 0);
   yUNIT_minstr ("... check verb"                      , my.verb       , "exec");
   yUNIT_minval ("... check index"                     , my.indx       , 999);
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify defenses");           
   yUNIT_minval  ("parse NULL"                         , SCRP_parse_verb (NULL)    , -999);
   yUNIT_minstr ("... check verb"                      , my.verb       , "");
   yUNIT_minval ("... check index"                     , my.indx       , -999);
   yUNIT_minval  ("parse empty"                        , SCRP_parse_verb ("")         , -999);
   yUNIT_minstr ("... check verb"                      , my.verb       , "");
   yUNIT_minval ("... check index"                     , my.indx       , -999);
   yUNIT_mindnoc ();

   yUNIT_minprcs ();
   return 0;
}

char
koios__unit_scrp_stage   (void)
{
   yUNIT_minscrp ("koios_scrp identifying stages");
   yURG_err_none ();  /* not to stderr/terminal */

   yUNIT_mincond ("parse good stages");
   yUNIT_minval  ("parse SCRP"                         , SCRP_parse_verb ("SCRP    [è1]"), 0);
   yUNIT_minstr ("... check verb"                      , my.verb       , "SCRP");
   yUNIT_minval  ("parse [è1]"                         , SCRP_parse_stage("SCRP    [è1]"), 0);
   yUNIT_minstr ("... check stage"                     , my.stage      , "è1");
   yUNIT_minval  ("parse SCRP"                         , SCRP_parse_verb ("SCRP    [ì4]"), 0);
   yUNIT_minstr ("... check verb"                      , my.verb       , "SCRP");
   yUNIT_minval  ("parse [ì4]"                         , SCRP_parse_stage("SCRP    [ì4]"), 0);
   yUNIT_minstr ("... check stage"                     , my.stage      , "ì4");
   yUNIT_mindnoc ();

   yUNIT_mincond ("parse illegal stages");
   yUNIT_minval  ("parse SCRP"                         , SCRP_parse_verb ("SCRP    [kz]"), 0);
   yUNIT_minstr ("... check verb"                      , my.verb       , "SCRP");
   yUNIT_minval  ("parse [kz]"                         , SCRP_parse_stage("SCRP    [kz]"), -999);
   yUNIT_minstr ("... check stage"                     , my.stage      , "");
   yUNIT_minval  ("parse SCRP"                         , SCRP_parse_verb ("SCRP    [è0["), 0);
   yUNIT_minstr ("... check verb"                      , my.verb       , "SCRP");
   yUNIT_minval  ("parse [è0]"                         , SCRP_parse_stage("SCRP    [è0]"), -999);
   yUNIT_minstr ("... check stage"                     , my.stage      , "");

   yUNIT_mincond ("parse good stages with different spacing");
   yUNIT_minval  ("parse SCRP"                         , SCRP_parse_verb ("SCRP   [ë3]"), 0);
   yUNIT_minstr ("... check verb"                      , my.verb       , "SCRP");
   yUNIT_minval  ("parse (è0)"                         , SCRP_parse_stage("SCRP   [ë3]"), 0);
   yUNIT_minstr ("... check stage"                     , my.stage      , "ë3");
   yUNIT_minval  ("parse SCRP"                         , SCRP_parse_verb ("SCRP     [ê9]"), 0);
   yUNIT_minstr ("... check verb"                      , my.verb       , "SCRP");
   yUNIT_minval  ("parse (è0)"                         , SCRP_parse_stage("SCRP     [ê9]"), 0);
   yUNIT_minstr ("... check stage"                     , my.stage      , "ê9");
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify defenses");           
   yUNIT_minval  ("parse COND"                         , SCRP_parse_verb ("COND   [ë3]"), 0);
   yUNIT_minstr ("... check verb"                      , my.verb       , "COND");
   yUNIT_minval  ("parse stage"                        , SCRP_parse_stage("COND   [ë3]"), 0);
   yUNIT_minstr ("... check stage"                     , my.stage      , "");

   yUNIT_minprcs ();
   return 0;
}

char
koios__unit_scrp_comment (void)
{
   yUNIT_minscrp ("koios_scrp identifying comments");
   yURG_err_none ();  /* not to stderr/terminal */

   yUNIT_mincond ("parse good comments");
   strcpy (my.recd, "#> a comment");
   my.len = strlen (my.recd);
   yUNIT_minval  ("parse comment"                      , SCRP_parse_comment (), 1);
   strcpy (my.recd, "#>comment");
   my.len = strlen (my.recd);
   yUNIT_minval  ("parse comment"                      , SCRP_parse_comment (), 1);
   strcpy (my.recd, "#>");
   my.len = strlen (my.recd);
   yUNIT_minval  ("parse comment"                      , SCRP_parse_comment (), 1);
   yUNIT_mindnoc ();

   yUNIT_mincond ("parse not comments");
   strcpy (my.recd, "## a comment");
   my.len = strlen (my.recd);
   yUNIT_minval  ("parse comment"                      , SCRP_parse_comment (), 0);
   strcpy (my.recd, "#comment");
   my.len = strlen (my.recd);
   yUNIT_minval  ("parse comment"                      , SCRP_parse_comment (), 0);
   strcpy (my.recd, "exec");
   my.len = strlen (my.recd);
   yUNIT_minval  ("parse comment"                      , SCRP_parse_comment (), 0);
   strcpy (my.recd, "/* c-style comment */");
   my.len = strlen (my.recd);
   yUNIT_minval  ("parse comment"                      , SCRP_parse_comment (), 0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("parse illegal lines");
   strcpy (my.recd, "");
   my.len = strlen (my.recd);
   yUNIT_minval  ("parse comment"                      , SCRP_parse_comment (), 0);
   yUNIT_mindnoc ();

   yUNIT_minprcs ();
   return 0;
}

char
koios__unit_scrp_parse   (void)
{
   yUNIT_minscrp ("koios_scrp parsing records");
   yURG_err_none ();  /* not to stderr/terminal */

   yUNIT_mincond ("prepare clean start");
   system ("rm -f /tmp/koios.unit 2> /dev/null");
   yUNIT_mindnoc ();

   yUNIT_mincond ("attempt to parse an empty file");
   strcpy (my.n_scrp, "/tmp/koios.unit");
   system ("touch /tmp/koios.unit");
   yUNIT_minstr ("... check script name"              , my.n_scrp     , "/tmp/koios.unit");
   yUNIT_minval ("open the script file"               , SCRP_open   (), 0);
   yUNIT_minval ("... check script pointer"           , my.f_scrp     , my.f_scrp);
   yUNIT_minval ("read a line"                        , SCRP_read   (), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), -999);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , ""               );
   yUNIT_minval ("close the script file"              , SCRP_close  (), 0);
   yUNIT_minval ("... check script pointer"           , my.f_scrp     , 0);
   yUNIT_mindnoc ();

   strcpy (my.n_base, "koios" );  /* prepare for SHARED testing */

   yUNIT_mincond ("verify reading a single record");
   strcpy (my.n_scrp, "/tmp/koios.unit");
   system ("echo \"exec     read a line      SCRP_read       i_lesser    0      \"                                             > /tmp/koios.unit");
   yUNIT_minstr ("... check script name"              , my.n_scrp     , "/tmp/koios.unit");
   yUNIT_minval ("open the script file"               , SCRP_open   (), 0);
   yUNIT_minval ("... check script pointer"           , my.f_scrp     , my.f_scrp);
   yUNIT_minval ("read a line"                        , SCRP_read   (), 1);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "exec    § read a line     § SCRP_read   §   § i_lesser   § 0      §");
   yUNIT_minstr ("... check verb"                     , my.verb       , "exec");
   yUNIT_minstr ("... check stage"                    , my.stage      , "");
   yUNIT_minchr ("... check share"                    , my.share      , '-');
   yUNIT_minchr ("... check mark"                     , my.mark       , '-');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "read a line");
   yUNIT_minstr ("... check method"                   , my.meth       , "SCRP_read");
   yUNIT_minstr ("... check arguments"                , my.args       , "");
   yUNIT_minstr ("... check test"                     , my.test       , "i_lesser");
   yUNIT_minstr ("... check expect"                   , my.expe       , "0");
   yUNIT_minval ("close the script file"              , SCRP_close  (), 0);
   yUNIT_minval ("... check script pointer"           , my.f_scrp     , 0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("attempt empty");
   strcpy (my.n_scrp, "/tmp/koios.unit");
   system ("echo \"\"                                             > /tmp/koios.unit");
   yUNIT_minstr ("... check script name"              , my.n_scrp     , "/tmp/koios.unit");
   yUNIT_minval ("open the script file"               , SCRP_open   (), 0);
   yUNIT_minval ("... check script pointer"           , my.f_scrp     , my.f_scrp);
   yUNIT_minval ("read a line"                        , SCRP_read   (), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), -999);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "");
   yUNIT_minstr ("... check verb"                     , my.verb       , "");
   yUNIT_minstr ("... check stage"                    , my.stage      , "");
   yUNIT_minchr ("... check share"                    , my.share      , '-');
   yUNIT_minchr ("... check mark"                     , my.mark       , '-');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "");
   yUNIT_minstr ("... check method"                   , my.meth       , "");
   yUNIT_minstr ("... check arguments"                , my.args       , "");
   yUNIT_minstr ("... check test"                     , my.test       , "");
   yUNIT_minstr ("... check expect"                   , my.expe       , "");
   yUNIT_minval ("close the script file"              , SCRP_close  (), 0);
   yUNIT_minval ("... check script pointer"           , my.f_scrp     , 0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("attempt verb only");
   strcpy (my.n_scrp, "/tmp/koios.unit");
   system ("echo \"exec    \"                                             > /tmp/koios.unit");
   yUNIT_minstr ("... check script name"              , my.n_scrp     , "/tmp/koios.unit");
   yUNIT_minval ("open the script file"               , SCRP_open   (), 0);
   yUNIT_minval ("... check script pointer"           , my.f_scrp     , my.f_scrp);
   yUNIT_minval ("read a line"                        , SCRP_read   (), 1);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), -999);
   yUNIT_minstr ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: verb only, exec requires more fields");
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "exec    §");
   yUNIT_minstr ("... check verb"                     , my.verb       , "exec");
   yUNIT_minstr ("... check stage"                    , my.stage      , "");
   yUNIT_minchr ("... check share"                    , my.share      , '-');
   yUNIT_minchr ("... check mark"                     , my.mark       , '-');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "");
   yUNIT_minstr ("... check method"                   , my.meth       , "");
   yUNIT_minstr ("... check arguments"                , my.args       , "");
   yUNIT_minstr ("... check test"                     , my.test       , "");
   yUNIT_minstr ("... check expect"                   , my.expe       , "");
   yUNIT_minval ("close the script file"              , SCRP_close  (), 0);
   yUNIT_minval ("... check script pointer"           , my.f_scrp     , 0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("attempt verb and desc");
   strcpy (my.n_scrp, "/tmp/koios.unit");
   system ("echo \"exec     read a line     \"                                             > /tmp/koios.unit");
   yUNIT_minstr ("... check script name"              , my.n_scrp     , "/tmp/koios.unit");
   yUNIT_minval ("open the script file"               , SCRP_open   (), 0);
   yUNIT_minval ("... check script pointer"           , my.f_scrp     , my.f_scrp);
   yUNIT_minval ("read a line"                        , SCRP_read   (), 1);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), -999);
   yUNIT_minstr ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: too few fields (2) for exec, requires 6");
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "exec    § read a line     §");
   yUNIT_minstr ("... check verb"                     , my.verb       , "exec");
   yUNIT_minstr ("... check stage"                    , my.stage      , "");
   yUNIT_minchr ("... check share"                    , my.share      , '-');
   yUNIT_minchr ("... check mark"                     , my.mark       , '-');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "read a line");
   yUNIT_minstr ("... check method"                   , my.meth       , "");
   yUNIT_minstr ("... check arguments"                , my.args       , "");
   yUNIT_minstr ("... check test"                     , my.test       , "");
   yUNIT_minstr ("... check expect"                   , my.expe       , "");
   yUNIT_minval ("close the script file"              , SCRP_close  (), 0);
   yUNIT_minval ("... check script pointer"           , my.f_scrp     , 0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("attempt verb, desc, and method");
   strcpy (my.n_scrp, "/tmp/koios.unit");
   system ("echo \"exec     read a line      SCRP_read   \"                                             > /tmp/koios.unit");
   yUNIT_minstr ("... check script name"              , my.n_scrp     , "/tmp/koios.unit");
   yUNIT_minval ("open the script file"               , SCRP_open   (), 0);
   yUNIT_minval ("... check script pointer"           , my.f_scrp     , my.f_scrp);
   yUNIT_minval ("read a line"                        , SCRP_read   (), 1);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), -999);
   yUNIT_minstr ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: too few fields (3) for exec, requires 6");
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "exec    § read a line     § SCRP_read   §");
   yUNIT_minstr ("... check verb"                     , my.verb       , "exec");
   yUNIT_minstr ("... check stage"                    , my.stage      , "");
   yUNIT_minchr ("... check share"                    , my.share      , '-');
   yUNIT_minchr ("... check mark"                     , my.mark       , '-');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "read a line");
   yUNIT_minstr ("... check method"                   , my.meth       , "SCRP_read");
   yUNIT_minstr ("... check arguments"                , my.args       , "");
   yUNIT_minstr ("... check test"                     , my.test       , "");
   yUNIT_minstr ("... check expect"                   , my.expe       , "");
   yUNIT_minval ("close the script file"              , SCRP_close  (), 0);
   yUNIT_minval ("... check script pointer"           , my.f_scrp     , 0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("attempt verb through test");
   strcpy (my.n_scrp, "/tmp/koios.unit");
   system ("echo \"exec     read a line      SCRP_read       i_lesser   \"                                             > /tmp/koios.unit");
   yUNIT_minstr ("... check script name"              , my.n_scrp     , "/tmp/koios.unit");
   yUNIT_minval ("open the script file"               , SCRP_open   (), 0);
   yUNIT_minval ("... check script pointer"           , my.f_scrp     , my.f_scrp);
   yUNIT_minval ("read a line"                        , SCRP_read   (), 1);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), -999);
   yUNIT_minstr ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: too few fields (5) for exec, requires 6");
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "exec    § read a line     § SCRP_read   §   § i_lesser   §");
   yUNIT_minstr ("... check verb"                     , my.verb       , "exec");
   yUNIT_minstr ("... check stage"                    , my.stage      , "");
   yUNIT_minchr ("... check share"                    , my.share      , '-');
   yUNIT_minchr ("... check mark"                     , my.mark       , '-');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "read a line");
   yUNIT_minstr ("... check method"                   , my.meth       , "SCRP_read");
   yUNIT_minstr ("... check arguments"                , my.args       , "");
   yUNIT_minstr ("... check test"                     , my.test       , "i_lesser");
   yUNIT_minstr ("... check expect"                   , my.expe       , "");
   yUNIT_minval ("close the script file"              , SCRP_close  (), 0);
   yUNIT_minval ("... check script pointer"           , my.f_scrp     , 0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("clean up after");
   system ("rm -f /tmp/koios.unit 2> /dev/null");
   yUNIT_mindnoc ();

   yUNIT_minprcs ();
   return 0;
}

char
koios__unit_scrp_share   (void)
{
   yUNIT_minscrp ("koios_scrp identifying global/shared/reuse marks");
   yURG_err_none ();  /* not to stderr/terminal */

   yUNIT_mincond ("prepare clean start");
   system ("rm -f /tmp/koios.unit 2> /dev/null");
   yUNIT_mindnoc ();

   yUNIT_mincond ("set to conversion mode");
   my.run_type = G_RUN_UPDATE;
   yUNIT_mindnoc ();

   yUNIT_mincond ("set to defaults");
   yUNIT_minval  ("... run clear"                      , SCRP__shared_purge ()         , 0);
   yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "--------------------------   --------------------------   ----------");
   yUNIT_mindnoc ();

   strcpy (my.n_base, "master");  /* prepare for GLOBAL testing */

   yUNIT_mincond ("check a min global identifier");
   yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   yUNIT_minval  ("parse GLOBAL"                       , SCRP_parse_verb    ("GLOBAL -A-"), 0);
   yUNIT_minstr  ("... check verb"                     , my.verb           , "GLOBAL");
   yUNIT_minval  ("check reuses"                       , SCRP__reuses_check ("GLOBAL -A-"), 0);
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "A-------------------------   --------------------------   ----------");
   yUNIT_minchr  ("... check mark"                     , my.share          , 'A');
   yUNIT_mindnoc ();

   yUNIT_mincond ("check a middle global identifier");
   yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   yUNIT_minval  ("parse GLOBAL"                       , SCRP_parse_verb    ("GLOBAL -M-"), 0);
   yUNIT_minstr  ("... check verb"                     , my.verb           , "GLOBAL");
   yUNIT_minval  ("check reuses"                       , SCRP__reuses_check ("GLOBAL -M-"), 0);
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "A-----------M-------------   --------------------------   ----------");
   yUNIT_minchr  ("... check mark"                     , my.share          , 'M');
   yUNIT_mindnoc ();

   yUNIT_mincond ("check with no identifier string");
   yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   yUNIT_minval  ("parse GLOBAL"                       , SCRP_parse_verb    ("GLOBAL"    ), 0);
   yUNIT_minstr  ("... check verb"                     , my.verb           , "GLOBAL");
   yUNIT_minval  ("check reuses"                       , SCRP__reuses_check ("GLOBAL"    ), -999);
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: GLOBAL missing a valid identifier string -?-");
   yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "A-----------M-------------   --------------------------   ----------");
   yUNIT_minchr  ("... check mark"                     , my.share          , '-');
   yUNIT_mindnoc ();

   yUNIT_mincond ("check with only identifier beginning");
   yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   yUNIT_minval  ("parse GLOBAL"                       , SCRP_parse_verb    ("GLOBAL -"  ), 0);
   yUNIT_minstr  ("... check verb"                     , my.verb           , "GLOBAL");
   yUNIT_minval  ("check reuses"                       , SCRP__reuses_check ("GLOBAL -"  ), -999);
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: GLOBAL identifier did not follow - marker");
   yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "A-----------M-------------   --------------------------   ----------");
   yUNIT_minchr  ("... check mark"                     , my.share          , '-');
   yUNIT_mindnoc ();

   yUNIT_mincond ("check with no identifier within");
   yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   yUNIT_minval  ("parse GLOBAL"                       , SCRP_parse_verb    ("GLOBAL --" ), 0);
   yUNIT_minstr  ("... check verb"                     , my.verb           , "GLOBAL");
   yUNIT_minval  ("check reuses"                       , SCRP__reuses_check ("GLOBAL --" ), -999);
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: GLOBAL no identifier within -- markers");
   yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "A-----------M-------------   --------------------------   ----------");
   yUNIT_minchr  ("... check mark"                     , my.share          , '-');
   yUNIT_mindnoc ();

   yUNIT_mincond ("check with no identifier ending");
   yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   yUNIT_minval  ("parse GLOBAL"                       , SCRP_parse_verb    ("GLOBAL -C" ), 0);
   yUNIT_minstr  ("... check verb"                     , my.verb           , "GLOBAL");
   yUNIT_minval  ("check reuses"                       , SCRP__reuses_check ("GLOBAL -C" ), -999);
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: GLOBAL identifier åCæ not followed by - marker");
   yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "A-----------M-------------   --------------------------   ----------");
   yUNIT_minchr  ("... check mark"                     , my.share          , '-');
   yUNIT_mindnoc ();

   yUNIT_mincond ("check with a non-valid identifier");
   yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   yUNIT_minval  ("parse GLOBAL"                       , SCRP_parse_verb    ("GLOBAL -d-"), 0);
   yUNIT_minstr  ("... check verb"                     , my.verb           , "GLOBAL");
   yUNIT_minval  ("check reuses"                       , SCRP__reuses_check ("GLOBAL -d-"), -999);
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: GLOBAL identifier ådæ not valid [A-Z]");
   yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "A-----------M-------------   --------------------------   ----------");
   yUNIT_minchr  ("... check mark"                     , my.share          , '-');
   yUNIT_mindnoc ();

   yUNIT_mincond ("check another good identifier");
   yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   yUNIT_minval  ("parse GLOBAL"                       , SCRP_parse_verb    ("GLOBAL -Y-"), 0);
   yUNIT_minstr  ("... check verb"                     , my.verb           , "GLOBAL");
   yUNIT_minval  ("check reuses"                       , SCRP__reuses_check ("GLOBAL -Y-"), 0);
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "A-----------M-----------Y-   --------------------------   ----------");
   yUNIT_minchr  ("... check mark"                     , my.share          , 'Y');
   yUNIT_mindnoc ();

   strcpy (my.n_base, "koios" );  /* prepare for GLOBAL defense testing */

   yUNIT_mincond ("attempt to use GLOBAL in normal unit");
   yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   yUNIT_minval  ("parse GLOBAL"                       , SCRP_parse_verb    ("GLOBAL -K-"), -999);
   yUNIT_minstr  ("... check verb"                     , my.verb           , "GLOBAL");
   yUNIT_minval  ("check reuses"                       , SCRP__reuses_check ("GLOBAL -K-"), -999);
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: GLOBAL not allowed outside master.unit");
   yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "A-----------M-----------Y-   --------------------------   ----------");
   yUNIT_minchr  ("... check mark"                     , my.share          , '-');
   yUNIT_mindnoc ();

   strcpy (my.n_base, "master");  /* prepare for GLOBAL testing */

   yUNIT_mincond ("attempt to reuse a identifier");
   yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   yUNIT_minval  ("parse GLOBAL"                       , SCRP_parse_verb    ("GLOBAL -M-"), 0);
   yUNIT_minstr  ("... check verb"                     , my.verb           , "GLOBAL");
   yUNIT_minval  ("check reuses"                       , SCRP__reuses_check ("GLOBAL -M-"), -999);
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: GLOBAL identifier åMæ already in use");
   yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "A-----------M-----------Y-   --------------------------   ----------");
   yUNIT_minchr  ("... check mark"                     , my.share          , '-');
   yUNIT_mindnoc ();

   strcpy (my.n_base, "koios" );  /* prepare for REUSE testing */

   yUNIT_mincond ("check good reuse of identifier");
   yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   yUNIT_minval  ("parse REUSE"                        , SCRP_parse_verb    ("REUSE  -M-"), 0);
   yUNIT_minstr  ("... check verb"                     , my.verb           , "REUSE");
   yUNIT_minval  ("check reuses"                       , SCRP__reuses_check ("REUSE  -M-"), 0);
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "A-----------M-----------Y-   --------------------------   ----------");
   yUNIT_minchr  ("... check mark"                     , my.share          , 'M');
   yUNIT_mindnoc ();

   yUNIT_mincond ("check with no identifier string");
   yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   yUNIT_minval  ("parse REUSE"                        , SCRP_parse_verb    ("REUSE"     ), 0);
   yUNIT_minstr  ("... check verb"                     , my.verb           , "REUSE" );
   yUNIT_minval  ("check reuses"                       , SCRP__reuses_check ("REUSE"     ), -999);
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: REUSE missing a valid identifier string -?-");
   yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "A-----------M-----------Y-   --------------------------   ----------");
   yUNIT_minchr  ("... check mark"                     , my.share          , '-');
   yUNIT_mindnoc ();

   yUNIT_mincond ("check with only identifier beginning");
   yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   yUNIT_minval  ("parse REUSE"                        , SCRP_parse_verb    ("REUSE  -"  ), 0);
   yUNIT_minstr  ("... check verb"                     , my.verb           , "REUSE");
   yUNIT_minval  ("check reuses"                       , SCRP__reuses_check ("REUSE  -"  ), -999);
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: REUSE identifier did not follow - marker");
   yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "A-----------M-----------Y-   --------------------------   ----------");
   yUNIT_minchr  ("... check mark"                     , my.share          , '-');
   yUNIT_mindnoc ();

   yUNIT_mincond ("check with no identifier within");
   yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   yUNIT_minval  ("parse REUSE"                        , SCRP_parse_verb    ("REUSE  --" ), 0);
   yUNIT_minstr  ("... check verb"                     , my.verb           , "REUSE");
   yUNIT_minval  ("check reuses"                       , SCRP__reuses_check ("REUSE  --" ), -999);
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: REUSE no identifier within -- markers");
   yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "A-----------M-----------Y-   --------------------------   ----------");
   yUNIT_minchr  ("... check mark"                     , my.share          , '-');
   yUNIT_mindnoc ();

   yUNIT_mincond ("check with no identifier ending");
   yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   yUNIT_minval  ("parse REUSE"                        , SCRP_parse_verb    ("REUSE  -C" ), 0);
   yUNIT_minstr  ("... check verb"                     , my.verb           , "REUSE");
   yUNIT_minval  ("check reuses"                       , SCRP__reuses_check ("REUSE  -C" ), -999);
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: REUSE identifier åCæ not followed by - marker");
   yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "A-----------M-----------Y-   --------------------------   ----------");
   yUNIT_minchr  ("... check mark"                     , my.share          , '-');
   yUNIT_mindnoc ();

   yUNIT_mincond ("check with a non-valid identifier");
   yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   yUNIT_minval  ("parse REUSE"                        , SCRP_parse_verb    ("REUSE  -2-"), 0);
   yUNIT_minstr  ("... check verb"                     , my.verb           , "REUSE");
   yUNIT_minval  ("check reuses"                       , SCRP__reuses_check ("REUSE  -2-"), -999);
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: REUSE identifier å2æ not valid [a-zA-Z]");
   yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "A-----------M-----------Y-   --------------------------   ----------");
   yUNIT_minchr  ("... check mark"                     , my.share          , '-');
   yUNIT_mindnoc ();

   yUNIT_mincond ("check another good reuse of identifier");
   yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   yUNIT_minval  ("parse REUSE"                        , SCRP_parse_verb    ("REUSE  -A-"), 0);
   yUNIT_minstr  ("... check verb"                     , my.verb           , "REUSE");
   yUNIT_minval  ("check reuses"                       , SCRP__reuses_check ("REUSE  -A-"), 0);
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "A-----------M-----------Y-   --------------------------   ----------");
   yUNIT_minchr  ("... check mark"                     , my.share          , 'A');
   yUNIT_mindnoc ();

   strcpy (my.n_base, "master");  /* prepare for REUSE defense testing */

   yUNIT_mincond ("attempt to reuse inside master.unit");
   yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   yUNIT_minval  ("parse REUSE"                        , SCRP_parse_verb    ("REUSE  -A-"), 0);
   yUNIT_minstr  ("... check verb"                     , my.verb           , "REUSE");
   yUNIT_minval  ("check reuses"                       , SCRP__reuses_check ("REUSE  -A-"), -999);
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: REUSE verb not allowed in master.unit");
   yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "A-----------M-----------Y-   --------------------------   ----------");
   yUNIT_minchr  ("... check mark"                     , my.share          , '-');
   yUNIT_mindnoc ();

   strcpy (my.n_base, "koios" );  /* prepare for REUSE testing */

   yUNIT_mincond ("attempt to reuse a non-set identifier");
   yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   yUNIT_minval  ("parse REUSE"                        , SCRP_parse_verb    ("REUSE  -K-"), 0);
   yUNIT_minstr  ("... check verb"                     , my.verb           , "REUSE");
   yUNIT_minval  ("check reuses"                       , SCRP__reuses_check ("REUSE  -K-"), -999);
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: REUSE identifier åKæ never set by GLOBAL");
   yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "A-----------M-----------Y-   --------------------------   ----------");
   yUNIT_minchr  ("... check mark"                     , my.share          , '-');
   yUNIT_mindnoc ();

   strcpy (my.n_base, "koios" );  /* prepare for SHARED testing */

   yUNIT_mincond ("check a min shared identifier");
   yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   yUNIT_minval  ("parse SHARED"                       , SCRP_parse_verb    ("SHARED -b-"), 0);
   yUNIT_minstr  ("... check verb"                     , my.verb           , "SHARED");
   yUNIT_minval  ("check reuses"                       , SCRP__reuses_check ("SHARED -b-"), 0);
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "A-----------M-----------Y-   -b------------------------   ----------");
   yUNIT_minchr  ("... check mark"                     , my.share          , 'b');
   yUNIT_mindnoc ();

   yUNIT_mincond ("check a middle shared identifier");
   yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   yUNIT_minval  ("parse SHARED"                       , SCRP_parse_verb    ("SHARED -j-"), 0);
   yUNIT_minstr  ("... check verb"                     , my.verb           , "SHARED");
   yUNIT_minval  ("check reuses"                       , SCRP__reuses_check ("SHARED -j-"), 0);
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "A-----------M-----------Y-   -b-------j----------------   ----------");
   yUNIT_minchr  ("... check mark"                     , my.share          , 'j');
   yUNIT_mindnoc ();

   yUNIT_mincond ("check with no identifier string");
   yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   yUNIT_minval  ("parse SHARED"                       , SCRP_parse_verb    ("SHARED"    ), 0);
   yUNIT_minstr  ("... check verb"                     , my.verb           , "SHARED");
   yUNIT_minval  ("check reuses"                       , SCRP__reuses_check ("SHARED"    ), -999);
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: SHARED missing a valid identifier string -?-");
   yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "A-----------M-----------Y-   -b-------j----------------   ----------");
   yUNIT_minchr  ("... check mark"                     , my.share          , '-');
   yUNIT_mindnoc ();

   yUNIT_mincond ("check with only identifier beginning");
   yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   yUNIT_minval  ("parse SHARED"                       , SCRP_parse_verb    ("SHARED -"  ), 0);
   yUNIT_minstr  ("... check verb"                     , my.verb           , "SHARED");
   yUNIT_minval  ("check reuses"                       , SCRP__reuses_check ("SHARED -"  ), -999);
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: SHARED identifier did not follow - marker");
   yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "A-----------M-----------Y-   -b-------j----------------   ----------");
   yUNIT_minchr  ("... check mark"                     , my.share          , '-');
   yUNIT_mindnoc ();

   yUNIT_mincond ("check with no identifier within");
   yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   yUNIT_minval  ("parse SHARED"                       , SCRP_parse_verb    ("SHARED --" ), 0);
   yUNIT_minstr  ("... check verb"                     , my.verb           , "SHARED");
   yUNIT_minval  ("check reuses"                       , SCRP__reuses_check ("SHARED --" ), -999);
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: SHARED no identifier within -- markers");
   yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "A-----------M-----------Y-   -b-------j----------------   ----------");
   yUNIT_minchr  ("... check mark"                     , my.share          , '-');
   yUNIT_mindnoc ();

   yUNIT_mincond ("check with no identifier ending");
   yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   yUNIT_minval  ("parse SHARED"                       , SCRP_parse_verb    ("SHARED -c" ), 0);
   yUNIT_minstr  ("... check verb"                     , my.verb           , "SHARED");
   yUNIT_minval  ("check reuses"                       , SCRP__reuses_check ("SHARED -c" ), -999);
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: SHARED identifier åcæ not followed by - marker");
   yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "A-----------M-----------Y-   -b-------j----------------   ----------");
   yUNIT_minchr  ("... check mark"                     , my.share          , '-');
   yUNIT_mindnoc ();

   yUNIT_mincond ("check with a non-valid identifier");
   yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   yUNIT_minval  ("parse SHARED"                       , SCRP_parse_verb    ("SHARED -D-"), 0);
   yUNIT_minstr  ("... check verb"                     , my.verb           , "SHARED");
   yUNIT_minval  ("check reuses"                       , SCRP__reuses_check ("SHARED -D-"), -999);
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: SHARED identifier åDæ not valid [a-z]");
   yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "A-----------M-----------Y-   -b-------j----------------   ----------");
   yUNIT_minchr  ("... check mark"                     , my.share          , '-');
   yUNIT_mindnoc ();

   yUNIT_mincond ("check another good identifier");
   yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   yUNIT_minval  ("parse SHARED"                       , SCRP_parse_verb    ("SHARED -w-"), 0);
   yUNIT_minstr  ("... check verb"                     , my.verb           , "SHARED");
   yUNIT_minval  ("check reuses"                       , SCRP__reuses_check ("SHARED -w-"), 0);
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "A-----------M-----------Y-   -b-------j------------w---   ----------");
   yUNIT_minchr  ("... check mark"                     , my.share          , 'w');
   yUNIT_mindnoc ();

   strcpy (my.n_base, "master");  /* prepare for SHARED defense testing */

   yUNIT_mincond ("attempt shared inside master.unit");
   yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   yUNIT_minval  ("parse SHARED"                       , SCRP_parse_verb    ("SHARED -k-"), -999);
   yUNIT_minstr  ("... check verb"                     , my.verb           , "SHARED");
   yUNIT_minval  ("check reuses"                       , SCRP__reuses_check ("SHARED -k-"), -999);
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: SHARED verb not allowed in master.unit");
   yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "A-----------M-----------Y-   -b-------j------------w---   ----------");
   yUNIT_minchr  ("... check mark"                     , my.share          , '-');
   yUNIT_mindnoc ();

   strcpy (my.n_base, "koios" );  /* prepare for SHARED testing */

   yUNIT_mincond ("check an attempt to reuse a identifier");
   yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   yUNIT_minval  ("parse SHARED"                       , SCRP_parse_verb    ("SHARED -j-"), 0);
   yUNIT_minstr  ("... check verb"                     , my.verb           , "SHARED");
   yUNIT_minval  ("check reuses"                       , SCRP__reuses_check ("SHARED -j-"), -999);
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: SHARED identifier åjæ already in use");
   yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "A-----------M-----------Y-   -b-------j------------w---   ----------");
   yUNIT_minchr  ("... check mark"                     , my.share          , '-');
   yUNIT_mindnoc ();

   yUNIT_mincond ("check good reuse of identifier");
   yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   yUNIT_minval  ("parse REUSE"                        , SCRP_parse_verb    ("REUSE  -j-"), 0);
   yUNIT_minstr  ("... check verb"                     , my.verb           , "REUSE");
   yUNIT_minval  ("check reuses"                       , SCRP__reuses_check ("REUSE  -j-"), 0);
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "A-----------M-----------Y-   -b-------j------------w---   ----------");
   yUNIT_minchr  ("... check mark"                     , my.share          , 'j');
   yUNIT_mindnoc ();

   yUNIT_mincond ("attempt to reuse a non-set identifier");
   yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   yUNIT_minval  ("parse REUSE"                        , SCRP_parse_verb    ("REUSE  -k-"), 0);
   yUNIT_minstr  ("... check verb"                     , my.verb           , "REUSE");
   yUNIT_minval  ("check reuses"                       , SCRP__reuses_check ("REUSE  -k-"), -999);
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: REUSE identifier åkæ never set by SHARED");
   yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "A-----------M-----------Y-   -b-------j------------w---   ----------");
   yUNIT_minchr  ("... check mark"                     , my.share          , '-');
   yUNIT_mindnoc ();

   yUNIT_mincond ("check another good use of identifier");
   yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   yUNIT_minval  ("parse REUSE"                        , SCRP_parse_verb    ("REUSE  -b-"), 0);
   yUNIT_minstr  ("... check verb"                     , my.verb           , "REUSE");
   yUNIT_minval  ("check reuses"                       , SCRP__reuses_check ("REUSE  -b-"), 0);
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "A-----------M-----------Y-   -b-------j------------w---   ----------");
   yUNIT_minchr  ("... check mark"                     , my.share          , 'b');
   yUNIT_mindnoc ();

   yUNIT_mincond ("set a shared reuse point");
   yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   yUNIT_minval  ("parse SHARED"                       , SCRP_parse_verb    ("SHARED -s-"), 0);
   yUNIT_minstr  ("... check verb"                     , my.verb           , "SHARED");
   yUNIT_minval  ("check reuses"                       , SCRP__reuses_check ("SHARED -s-"), 0);
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "A-----------M-----------Y-   -b-------j--------s---w---   ----------");
   yUNIT_minchr  ("... check mark"                     , my.share          , 's');
   my.cshare = 's';
   yUNIT_minchr  ("... check current share"            , my.cshare         , 's');
   yUNIT_mindnoc ();

   yUNIT_mincond ("attempt to reuse the current share");
   yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   yUNIT_minval  ("parse REUSE"                        , SCRP_parse_verb    ("REUSE  -s-"), 0);
   yUNIT_minstr  ("... check verb"                     , my.verb           , "REUSE");
   yUNIT_minval  ("check reuses"                       , SCRP__reuses_check ("REUSE  -s-"), -999);
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: REUSE identifier åsæ called inside itself, recursive");
   yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "A-----------M-----------Y-   -b-------j--------s---w---   ----------");
   yUNIT_minchr  ("... check mark"                     , my.share          , '-');
   yUNIT_minchr  ("... check current share"            , my.cshare         , 's');
   yUNIT_mindnoc ();

   yUNIT_mincond ("check defaults");
   yUNIT_minval ("... run clear"                      , SCRP__shared_purge ()         , 0);
   yUNIT_minstr ("... check all marks"                , SCRP__shared_used  ()         , "--------------------------   --------------------------   ----------");
   yUNIT_mindnoc ();

   yUNIT_mincond ("clean up after");
   system ("rm -f /tmp/koios.unit 2> /dev/null");
   yUNIT_mindnoc ();

   yUNIT_minprcs ();
   return 0;
}

char
koios__unit_scrp_ditto   (void)
{
   yUNIT_minscrp ("koios_scrp identifying ditto marks");
   yURG_err_none ();  /* not to stderr/terminal */

   yUNIT_mincond ("prepare clean start");
   system ("rm -f /tmp/koios.unit 2> /dev/null");
   yUNIT_mindnoc ();

   yUNIT_mincond ("set to conversion mode");
   my.run_type = G_RUN_UPDATE;
   yUNIT_mindnoc ();

   yUNIT_mincond ("set to defaults");
   yUNIT_minval  ("... run clear"                      , SCRP__shared_purge ()         , 0);
   yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "--------------------------   --------------------------   ----------");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check a min cond identifier");
   yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   yUNIT_minval  ("parse COND"                         , SCRP_parse_verb   ("COND (0)"), 0);
   yUNIT_minstr  ("... check verb"                     , my.verb          , "COND");
   yUNIT_minval  ("check ditto"                        , SCRP__ditto_check ("COND (0)"), 0);
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "--------------------------   --------------------------   0---------");
   yUNIT_minchr  ("... check mark"                     , my.mark          , '0');
   yUNIT_mindnoc ();

   yUNIT_mincond ("check a middle cond identifier");
   yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   yUNIT_minval  ("parse COND"                         , SCRP_parse_verb   ("COND (3)"), 0);
   yUNIT_minstr  ("... check verb"                     , my.verb          , "COND");
   yUNIT_minval  ("check ditto"                        , SCRP__ditto_check ("COND (3)"), 0);
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "--------------------------   --------------------------   0--3------");
   yUNIT_minchr  ("... check mark"                     , my.mark          , '3');
   yUNIT_mindnoc ();

   yUNIT_mincond ("check a missing cond identifier, trunctated");
   yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   yUNIT_minval  ("parse COND"                         , SCRP_parse_verb   ("COND ("  ), 0);
   yUNIT_minstr  ("... check verb"                     , my.verb          , "COND");
   yUNIT_minval  ("check ditto"                        , SCRP__ditto_check ("COND ("  ), -999);
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: COND identifier did not follow ( marker");
   yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "--------------------------   --------------------------   0--3------");
   yUNIT_minchr  ("... check mark"                     , my.mark          , '-');
   yUNIT_mindnoc ();

   yUNIT_mincond ("check a missing cond identifier");
   yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   yUNIT_minval  ("parse COND"                         , SCRP_parse_verb   ("COND ()" ), 0);
   yUNIT_minstr  ("... check verb"                     , my.verb          , "COND");
   yUNIT_minval  ("check ditto"                        , SCRP__ditto_check ("COND ()" ), -999);
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: COND no identifier within () markers");
   yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "--------------------------   --------------------------   0--3------");
   yUNIT_minchr  ("... check mark"                     , my.mark          , '-');
   yUNIT_mindnoc ();

   yUNIT_mincond ("check a missing cond close marker");
   yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   yUNIT_minval  ("parse COND"                         , SCRP_parse_verb   ("COND (5" ), 0);
   yUNIT_minstr  ("... check verb"                     , my.verb          , "COND");
   yUNIT_minval  ("check ditto"                        , SCRP__ditto_check ("COND (5" ), -999);
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: COND identifier å5æ not followed by ) marker");
   yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "--------------------------   --------------------------   0--3------");
   yUNIT_minchr  ("... check mark"                     , my.mark          , '-');
   yUNIT_mindnoc ();

   yUNIT_mincond ("check cond with an invalid identifier");
   yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   yUNIT_minval  ("parse COND"                         , SCRP_parse_verb   ("COND (B)" ), 0);
   yUNIT_minstr  ("... check verb"                     , my.verb          , "COND");
   yUNIT_minval  ("check ditto"                        , SCRP__ditto_check ("COND (B)" ), -999);
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: COND identifier åBæ not valid [0-9]");
   yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "--------------------------   --------------------------   0--3------");
   yUNIT_minchr  ("... check mark"                     , my.mark          , '-');
   yUNIT_mindnoc ();

   yUNIT_mincond ("check a valid cond again (extra spaces)");
   yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   yUNIT_minval  ("parse COND"                         , SCRP_parse_verb   ("COND     (8)" ), 0);
   yUNIT_minstr  ("... check verb"                     , my.verb          , "COND");
   yUNIT_minval  ("check ditto"                        , SCRP__ditto_check ("COND     (8)"), 0);
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "--------------------------   --------------------------   0--3----8-");
   yUNIT_minchr  ("... check mark"                     , my.mark          , '8');
   yUNIT_mindnoc ();

   yUNIT_mincond ("check a cond masking another");
   yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   yUNIT_minval  ("parse COND"                         , SCRP_parse_verb   ("COND     (8)" ), 0);
   yUNIT_minstr  ("... check verb"                     , my.verb          , "COND");
   yUNIT_minval  ("check ditto"                        , SCRP__ditto_check ("COND     (8)"), 0);
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: warning: COND identifier å8æ already set, now overwritten");
   yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "--------------------------   --------------------------   0--3----8-");
   yUNIT_minchr  ("... check mark"                     , my.mark          , '8');
   yUNIT_mindnoc ();

   yUNIT_mincond ("check a valid ditto");
   yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   yUNIT_minval  ("parse COND"                         , SCRP_parse_verb   ("DITTO    (3)" ), 0);
   yUNIT_minstr  ("... check verb"                     , my.verb          , "DITTO");
   yUNIT_minval  ("check ditto"                        , SCRP__ditto_check ("DITTO    (3)"), 0);
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "--------------------------   --------------------------   0--3----8-");
   yUNIT_minchr  ("... check mark"                     , my.mark          , '3');
   yUNIT_mindnoc ();

   yUNIT_mincond ("check a ditto with no lead marker");
   yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   yUNIT_minval  ("parse COND"                         , SCRP_parse_verb   ("DITTO" ), 0);
   yUNIT_minstr  ("... check verb"                     , my.verb          , "DITTO");
   yUNIT_minval  ("check ditto"                        , SCRP__ditto_check ("DITTO"), -999);
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: DITTO missing a valid identifier string (?)");
   yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "--------------------------   --------------------------   0--3----8-");
   yUNIT_minchr  ("... check mark"                     , my.mark          , '-');
   yUNIT_mindnoc ();

   yUNIT_mincond ("check a ditto with no identifier (truncated)");
   yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   yUNIT_minval  ("parse COND"                         , SCRP_parse_verb   ("DITTO (" ), 0);
   yUNIT_minstr  ("... check verb"                     , my.verb          , "DITTO");
   yUNIT_minval  ("check ditto"                        , SCRP__ditto_check ("DITTO ("), -999);
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: DITTO identifier did not follow ( marker");
   yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "--------------------------   --------------------------   0--3----8-");
   yUNIT_minchr  ("... check mark"                     , my.mark          , '-');
   yUNIT_mindnoc ();

   yUNIT_mincond ("check a ditto with no identifier inside markers");
   yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   yUNIT_minval  ("parse COND"                         , SCRP_parse_verb   ("DITTO ()" ), 0);
   yUNIT_minstr  ("... check verb"                     , my.verb          , "DITTO");
   yUNIT_minval  ("check ditto"                        , SCRP__ditto_check ("DITTO ()"), -999);
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: DITTO no identifier within () markers");
   yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "--------------------------   --------------------------   0--3----8-");
   yUNIT_minchr  ("... check mark"                     , my.mark          , '-');
   yUNIT_mindnoc ();

   yUNIT_mincond ("check a ditto with illegal identifier");
   yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   yUNIT_minval  ("parse COND"                         , SCRP_parse_verb   ("DITTO (a)" ), 0);
   yUNIT_minstr  ("... check verb"                     , my.verb          , "DITTO");
   yUNIT_minval  ("check ditto"                        , SCRP__ditto_check ("DITTO (a)"), -999);
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: DITTO identifier åaæ not valid [0-9]");
   yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "--------------------------   --------------------------   0--3----8-");
   yUNIT_minchr  ("... check mark"                     , my.mark          , '-');
   yUNIT_mindnoc ();

   yUNIT_mincond ("check a ditto with an unset identifier");
   yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   yUNIT_minval  ("parse COND"                         , SCRP_parse_verb   ("DITTO (5)" ), 0);
   yUNIT_minstr  ("... check verb"                     , my.verb          , "DITTO");
   yUNIT_minval  ("check ditto"                        , SCRP__ditto_check ("DITTO (5)"), -999);
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: DITTO identifier å5æ not set by previous COND");
   yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "--------------------------   --------------------------   0--3----8-");
   yUNIT_minchr  ("... check mark"                     , my.mark          , '-');
   yUNIT_mindnoc ();

   yUNIT_mincond ("check another valid ditto");
   yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   yUNIT_minval  ("parse COND"                         , SCRP_parse_verb   ("DITTO    (8)" ), 0);
   yUNIT_minstr  ("... check verb"                     , my.verb          , "DITTO");
   yUNIT_minval  ("check ditto"                        , SCRP__ditto_check ("DITTO    (8)"), 0);
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "--------------------------   --------------------------   0--3----8-");
   yUNIT_minchr  ("... check mark"                     , my.mark          , '8');
   yUNIT_mindnoc ();

   yUNIT_mincond ("set to defaults");
   yUNIT_minval  ("... run clear"                      , SCRP__shared_purge ()         , 0);
   yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "--------------------------   --------------------------   ----------");
   yUNIT_mindnoc ();

   yUNIT_mincond ("set to create/code mode");
   my.run_type = G_RUN_CREATE;
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify handling dittos");
   strcpy (my.n_scrp, "/tmp/koios.unit");
   system ("echo \"\"                                                                         >  /tmp/koios.unit");
   system ("echo \"  COND (2)   original cond    - - - - - -  -  - - - - -   - - -  \"  >> /tmp/koios.unit");
   system ("echo \"    exec     line one         - - - - - -  -  - - - - -   - - -  \"  >> /tmp/koios.unit");
   system ("echo \"    exec     line two         - - - - - -  -  - - - - -   - - -  \"  >> /tmp/koios.unit");
   system ("echo \"\"                                                                         >> /tmp/koios.unit");
   system ("echo \"  DITTO (2)  new cond         - - - - - -  -  - - - - -   - - -  \"  >> /tmp/koios.unit");
   system ("echo \"\"                                                                         >> /tmp/koios.unit");
   system ("echo \"  COND       after others     - - - - - -  -  - - - - -   - - -  \"  >> /tmp/koios.unit");
   yUNIT_minstr ("... check script name"              , my.n_scrp     , "/tmp/koios.unit");
   yUNIT_minval ("open the script file"               , SCRP_open   (), 0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("read ditto condition");
   yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   yUNIT_minval ("read a line"                        , SCRP_read   (), 1);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), 0);
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "  COND (2)  § original cond   § - - - - - - § - § - - - - -  § - - -  §");
   yUNIT_minstr ("... check all marks"                 , SCRP__shared_used  ()         , "--------------------------   --------------------------   --2-------");
   yUNIT_mindnoc ();

   yUNIT_mincond ("read detailed line");
   yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   yUNIT_minval ("read a line"                        , SCRP_read   (), 1);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), 0);
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "    exec    § line one        § - - - - - - § - § - - - - -  § - - -  §");
   yUNIT_minstr ("... check all marks"                 , SCRP__shared_used  ()         , "--------------------------   --------------------------   --2-------");
   yUNIT_mindnoc ();

   yUNIT_mincond ("read detailed line");
   yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   yUNIT_minval ("read a line"                        , SCRP_read   (), 1);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), 0);
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "    exec    § line two        § - - - - - - § - § - - - - -  § - - -  §");
   yUNIT_minstr ("... check all marks"                 , SCRP__shared_used  ()         , "--------------------------   --------------------------   --2-------");
   yUNIT_mindnoc ();

   yUNIT_mincond ("read ditto call");
   yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   yUNIT_minval ("read a line"                        , SCRP_read   (), 1);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), 0);
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "  DITTO (2) § new cond        § - - - - - - § - § - - - - -  § - - -  §");
   yUNIT_minstr ("... check all marks"                 , SCRP__shared_used  ()         , "--------------------------   --------------------------   --2-------");
   yUNIT_mindnoc ();

   yUNIT_mincond ("read ditto condition");
   yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   yUNIT_minval ("read a line"                        , SCRP_read   (), 1);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), 0);
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "  COND (2)  § original cond   § - - - - - - § - § - - - - -  § - - -  §");
   yUNIT_minstr ("... check all marks"                 , SCRP__shared_used  ()         , "--------------------------   --------------------------   --2-------");
   yUNIT_mindnoc ();

   yUNIT_mincond ("read detailed line");
   yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   yUNIT_minval ("read a line"                        , SCRP_read   (), 1);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), 0);
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "    exec    § line one        § - - - - - - § - § - - - - -  § - - -  §");
   yUNIT_minstr ("... check all marks"                 , SCRP__shared_used  ()         , "--------------------------   --------------------------   --2-------");
   yUNIT_mindnoc ();

   yUNIT_mincond ("read detailed line");
   yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   yUNIT_minval ("read a line"                        , SCRP_read   (), 1);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), 0);
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "    exec    § line two        § - - - - - - § - § - - - - -  § - - -  §");
   yUNIT_minstr ("... check all marks"                 , SCRP__shared_used  ()         , "--------------------------   --------------------------   --2-------");
   yUNIT_mindnoc ();

   yUNIT_mincond ("read after condition");
   yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   yUNIT_minval ("read a line"                        , SCRP_read   (), 1);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), 0);
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "  COND      § after others    § - - - - - - § - § - - - - -  § - - -  §");
   yUNIT_minstr ("... check all marks"                 , SCRP__shared_used  ()         , "--------------------------   --------------------------   --2-------");
   yUNIT_mindnoc ();

   yUNIT_mincond ("read end-of-file");
   yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   yUNIT_minval ("read a line"                        , SCRP_read   (), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), -999);
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_minval ("close the script file"              , SCRP_close  (), 0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("clean up after");
   system ("rm -f /tmp/koios.unit 2> /dev/null");
   yUNIT_mindnoc ();

   yUNIT_minprcs ();
   return 0;
}

char
koios__unit_scrp_variety (void)
{
   yUNIT_minscrp ("koios_scrp read/parse a variety of records");
   yURG_err_none ();  /* not to stderr/terminal */

   yUNIT_mincond ("prepare clean start");
   system ("rm -f /tmp/koios.unit 2> /dev/null");
   system ("echo \"\"                                                                                                                                                      > /tmp/koios.unit");
   system ("echo \"## this is a comment\"                                                                                                                                 >> /tmp/koios.unit");
   system ("echo \"exec          read a line      SCRP_read       i_lesser    0       my_var   \"                                                              >> /tmp/koios.unit");
   system ("echo \"#> this is a saved comment\"                                                                                                                           >> /tmp/koios.unit");
   system ("echo \"     get      ... check on script  SCRP__unit   file , -1  s_equal  SCRP file      : /tmp/koios.unit \"                                          >> /tmp/koios.unit");
   system ("echo \"   code       add lines                            - - - - - - - - - - - - -   system ();        \"                                                >> /tmp/koios.unit");
   system ("echo \"\"                                                                                                                                                     >> /tmp/koios.unit");
   system ("echo \"  COND        parse a code record   - - - - - - - - - - - - -   ((01.001))  - - - - - - - - - \"                                                  >> /tmp/koios.unit");
   system ("echo \"PREP          include the prototype headers                            - - - - - - - - - -   - - - - -   - - - - - - - - - -  >>\"                >> /tmp/koios.unit");
   system ("echo \"   incl       include public header                koios.h           - - - - - - - - - -   - - - - -   - - - - - - - - - -  \"                   >> /tmp/koios.unit");
   system ("echo \"#23456789-12  123456789-123456789-123456789-12345  123456789-123456  123456789-123456789-  123456789-  123456789-123456789-  -  123456789- \"  >> /tmp/koios.unit");
   system ("echo \"#==(verb)===  ===========(description)===========  =====(function)=  ====(arguments)=====  ==(test)==  ====(results)=======  t  =(var)==== \"  >> /tmp/koios.unit");
   system ("echo \"SCRP    [ê3]  (SCRP  ) verify openning and closin                                           ((01.---))  - - - - - - - - - -  \"                   >> /tmp/koios.unit");
   system ("echo \"\"                                                                                                                                                     >> /tmp/koios.unit");
   system ("echo \"  load        add a line to stdin    stdin  * * * * *                      : basic line                  : - - - - -  :  /bin/true > /dev/null\"   >> /tmp/koios.unit");
   system ("echo \"  toad        add a line to stdin 2  stdin  * * * * *                      : basic line                  : - - - - -  :  /bin/true > /dev/null\"   >> /tmp/koios.unit");
   system ("echo \"              (SCRP  ) verify openning and closin                                           ((01.---))  - - - - - - - - - -  \"                   >> /tmp/koios.unit");
   system ("echo \"\"                                                                                                                                                     >> /tmp/koios.unit");
   system ("echo \"GROUP         complete               - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - -  \"            >> /tmp/koios.unit");
   system ("echo \"SECT          internal testing       - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - -  \"            >> /tmp/koios.unit");
   system ("echo \"    echo      ...check y location    - - - - - - - - - - - - -   y        r_norm93    -125.381                                     \"            >> /tmp/koios.unit");
   system ("echo \"    system    remove a file                        - - - - - - - - - - - - -   rm -fv test.txt   \"                                                >> /tmp/koios.unit");
   system ("echo \"\"                                                                                                                                                     >> /tmp/koios.unit");
   system ("echo \"#==(verb)===  ===========(description)===========  =====(function)=  ====(arguments)=====  ==(test)==  ====(results)=======  t  =(var)==== \"  >> /tmp/koios.unit");
   system ("echo \"SHARED   -a-  setup cron files and lines           - - - - - - - -   ((CC.---))  - - - - - - - - - - - - - - - - - - - - - - - - -  \"            >> /tmp/koios.unit");
   system ("echo \"\"                                                                                                                                                     >> /tmp/koios.unit");
   system ("echo \" REUSE -a-    - - - - - - - - - - - -   - - - - - - - - - - - - - - -   ((03.---))  - - - - - - - - - - - - - - - - - - - -  \"                   >> /tmp/koios.unit");
   my.run_type = G_RUN_CREATE;
   strcpy (my.n_scrp, "/tmp/koios.unit");
   strcpy (my.n_wave, "/tmp/koios.wave");
   yUNIT_minstr ("... check script name"              , my.n_scrp     , "/tmp/koios.unit");
   yUNIT_minval ("open the script file"               , SCRP_open   (), 0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("read very detailed exec line");
   yUNIT_minval ("read a line"                        , SCRP_read   (), 1);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "exec         § read a line     § SCRP_read   §   § i_lesser   § 0      § my_var   §");
   yUNIT_minstr ("... check verb"                     , my.verb       , "exec");
   yUNIT_minstr ("... check stage"                    , my.stage      , "");
   yUNIT_minchr ("... check share"                    , my.share      , '-');
   yUNIT_minchr ("... check mark"                     , my.mark       , '-');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "read a line");
   yUNIT_minstr ("... check method"                   , my.meth       , "SCRP_read");
   yUNIT_minstr ("... check arguments"                , my.args       , "");
   yUNIT_minstr ("... check test"                     , my.test       , "i_lesser");
   yUNIT_minstr ("... check expect"                   , my.expe       , "0");
   yUNIT_minstr ("... check return"                   , my.retn       , "my_var");
   yUNIT_minstr ("... check code"                     , my.code       , "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("read saved comment line");
   yUNIT_minval ("read a line"                        , SCRP_read   (), 1);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "#> this is a saved comment");
   yUNIT_minstr ("... check verb"                     , my.verb       , "#>");
   yUNIT_minstr ("... check stage"                    , my.stage      , "");
   yUNIT_minchr ("... check share"                    , my.share      , '-');
   yUNIT_minchr ("... check mark"                     , my.mark       , '-');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "");
   yUNIT_minstr ("... check method"                   , my.meth       , "");
   yUNIT_minstr ("... check arguments"                , my.args       , "");
   yUNIT_minstr ("... check test"                     , my.test       , "");
   yUNIT_minstr ("... check expect"                   , my.expe       , "");
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("read get/accessor line");
   yUNIT_minval ("read a line"                        , SCRP_read   (), 1);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "     get     § ... check on script § SCRP__unit  § file , -1 § s_equal § SCRP file      : /tmp/koios.unit §");
   yUNIT_minstr ("... check verb"                     , my.verb       , "get");
   yUNIT_minstr ("... check stage"                    , my.stage      , "");
   yUNIT_minchr ("... check share"                    , my.share      , '-');
   yUNIT_minchr ("... check mark"                     , my.mark       , '-');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "... check on script");
   yUNIT_minstr ("... check method"                   , my.meth       , "SCRP__unit");
   yUNIT_minstr ("... check arguments"                , my.args       , "file , -1");
   yUNIT_minstr ("... check test"                     , my.test       , "s_equal");
   yUNIT_minstr ("... check expect"                   , my.expe       , "SCRP file      : /tmp/koios.unit");
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "file , -1");
   yUNIT_mindnoc ();

   yUNIT_mincond ("read code line");
   yUNIT_minval ("read a line"                        , SCRP_read   (), 1);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "   code      § add lines                           § - - - - - - - - - - - - -  § system ();        §");
   yUNIT_minstr ("... check verb"                     , my.verb       , "code");
   yUNIT_minstr ("... check stage"                    , my.stage      , "");
   yUNIT_minchr ("... check share"                    , my.share      , '-');
   yUNIT_minchr ("... check mark"                     , my.mark       , '-');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "add lines");
   yUNIT_minstr ("... check method"                   , my.meth       , "");
   yUNIT_minstr ("... check arguments"                , my.args       , "");
   yUNIT_minstr ("... check test"                     , my.test       , "");
   yUNIT_minstr ("... check expect"                   , my.expe       , "");
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "system ();");
   yUNIT_mindnoc ();

   yUNIT_mincond ("read condition line");
   yUNIT_minval ("read a line"                        , SCRP_read   (), 1);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "  COND       § parse a code record  § - - - - - - - - - - - - -  § ((01.001)) § - - - - - - - - - §");
   yUNIT_minstr ("... check verb"                     , my.verb       , "COND");
   yUNIT_minstr ("... check stage"                    , my.stage      , "");
   yUNIT_minchr ("... check share"                    , my.share      , '-');
   yUNIT_minchr ("... check mark"                     , my.mark       , '-');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "parse a code record");
   yUNIT_minstr ("... check method"                   , my.meth       , "");
   yUNIT_minstr ("... check arguments"                , my.args       , "");
   yUNIT_minstr ("... check test"                     , my.test       , "");
   yUNIT_minstr ("... check expect"                   , my.expe       , "");
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("read prep line");
   yUNIT_minval ("read a line"                        , SCRP_read   (), 1);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "PREP         § include the prototype headers                           § - - - - - - - - - -  § - - - - -  § - - - - - - - - - -  §>>");
   yUNIT_minstr ("... check verb"                     , my.verb       , "PREP");
   yUNIT_minstr ("... check stage"                    , my.stage      , "");
   yUNIT_minchr ("... check share"                    , my.share      , '-');
   yUNIT_minchr ("... check mark"                     , my.mark       , '-');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "include the prototype headers");
   yUNIT_minstr ("... check method"                   , my.meth       , "");
   yUNIT_minstr ("... check arguments"                , my.args       , "");
   yUNIT_minstr ("... check test"                     , my.test       , "");
   yUNIT_minstr ("... check expect"                   , my.expe       , "");
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("read include line");
   yUNIT_minval ("read a line"                        , SCRP_read   (), 1);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "   incl      § include public header               § koios.h          § - - - - - - - - - -  § - - - - -  § - - - - - - - - - -  §");
   yUNIT_minstr ("... check verb"                     , my.verb       , "incl");
   yUNIT_minstr ("... check stage"                    , my.stage      , "");
   yUNIT_minchr ("... check share"                    , my.share      , '-');
   yUNIT_minchr ("... check mark"                     , my.mark       , '-');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "include public header");
   yUNIT_minstr ("... check method"                   , my.meth       , "koios.h");
   yUNIT_minstr ("... check arguments"                , my.args       , "");
   yUNIT_minstr ("... check test"                     , my.test       , "");
   yUNIT_minstr ("... check expect"                   , my.expe       , "");
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("read script header line");
   yUNIT_minval ("read a line"                        , SCRP_read   (), 1);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "SCRP    [ê3] § (SCRP  ) verify openning and closin §                                         § ((01.---)) § - - - - - - - - - -  §");
   yUNIT_minstr ("... check verb"                     , my.verb       , "SCRP");
   yUNIT_minstr ("... check stage"                    , my.stage      , "ê3");
   yUNIT_minchr ("... check share"                    , my.share      , '-');
   yUNIT_minchr ("... check mark"                     , my.mark       , '-');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "(SCRP ) verify openning and closin");
   yUNIT_minstr ("... check method"                   , my.meth       , "");
   yUNIT_minstr ("... check arguments"                , my.args       , "");
   yUNIT_minstr ("... check test"                     , my.test       , "");
   yUNIT_minstr ("... check expect"                   , my.expe       , "");
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("read stdin load line");
   yUNIT_minval ("read a line"                        , SCRP_read   (), 1);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "  load       § add a line to stdin   § stdin § * * * * *                      : basic line                  : - - - - -  :  /bin/true > /dev/null§");
   yUNIT_minstr ("... check verb"                     , my.verb       , "load");
   yUNIT_minstr ("... check stage"                    , my.stage      , "");
   yUNIT_minchr ("... check share"                    , my.share      , '-');
   yUNIT_minchr ("... check mark"                     , my.mark       , '-');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "add a line to stdin");
   yUNIT_minstr ("... check method"                   , my.meth       , "stdin");
   yUNIT_minstr ("... check arguments"                , my.args       , "");
   yUNIT_minstr ("... check test"                     , my.test       , "");
   yUNIT_minstr ("... check expect"                   , my.expe       , "");
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "* * * * *                      : basic line                  : - - - - -  :  /bin/true > /dev/null");
   yUNIT_mindnoc ();

   yUNIT_mincond ("read stdin load line");
   yUNIT_minval ("read a line"                        , SCRP_read   (), 1);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), -999);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "  toad       § add a line to stdin 2 § stdin § * * * * *                      : basic line                  : - - - - -  :  /bin/true > /dev/null§");
   yUNIT_minstr ("... check verb"                     , my.verb       , "");
   yUNIT_minstr ("... check stage"                    , my.stage      , "");
   yUNIT_minchr ("... check share"                    , my.share      , '-');
   yUNIT_minchr ("... check mark"                     , my.mark       , '-');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "");
   yUNIT_minstr ("... check method"                   , my.meth       , "");
   yUNIT_minstr ("... check arguments"                , my.args       , "");
   yUNIT_minstr ("... check test"                     , my.test       , "");
   yUNIT_minstr ("... check expect"                   , my.expe       , "");
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("read verbless line");
   yUNIT_minval ("read a line"                        , SCRP_read   (), 1);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), -999);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "             § (SCRP  ) verify openning and closin §                                         § ((01.---)) § - - - - - - - - - -  §");
   yUNIT_minstr ("... check verb"                     , my.verb       , "");
   yUNIT_minstr ("... check stage"                    , my.stage      , "");
   yUNIT_minchr ("... check share"                    , my.share      , '-');
   yUNIT_minchr ("... check mark"                     , my.mark       , '-');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "");
   yUNIT_minstr ("... check method"                   , my.meth       , "");
   yUNIT_minstr ("... check arguments"                , my.args       , "");
   yUNIT_minstr ("... check test"                     , my.test       , "");
   yUNIT_minstr ("... check expect"                   , my.expe       , "");
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("read group divider line");
   yUNIT_minval ("read a line"                        , SCRP_read   (), 1);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "GROUP        § complete              § - - - - - - - - - - - - - - -  § - - - - -  § - - - - - - - - - - - - - - - - - - - - - - - - -  §");
   yUNIT_minstr ("... check verb"                     , my.verb       , "GROUP");
   yUNIT_minstr ("... check stage"                    , my.stage      , "");
   yUNIT_minchr ("... check share"                    , my.share      , '-');
   yUNIT_minchr ("... check mark"                     , my.mark       , '-');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "complete");
   yUNIT_minstr ("... check method"                   , my.meth       , "");
   yUNIT_minstr ("... check arguments"                , my.args       , "");
   yUNIT_minstr ("... check test"                     , my.test       , "");
   yUNIT_minstr ("... check expect"                   , my.expe       , "");
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("read section header line");
   yUNIT_minval ("read a line"                        , SCRP_read   (), 1);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "SECT         § internal testing      § - - - - - - - - - - - - - - -  § - - - - -  § - - - - - - - - - - - - - - - - - - - - - - - - -  §");
   yUNIT_minstr ("... check verb"                     , my.verb       , "SECT");
   yUNIT_minstr ("... check stage"                    , my.stage      , "");
   yUNIT_minchr ("... check share"                    , my.share      , '-');
   yUNIT_minchr ("... check mark"                     , my.mark       , '-');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "internal testing");
   yUNIT_minstr ("... check method"                   , my.meth       , "");
   yUNIT_minstr ("... check arguments"                , my.args       , "");
   yUNIT_minstr ("... check test"                     , my.test       , "");
   yUNIT_minstr ("... check expect"                   , my.expe       , "");
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("read echo line");
   yUNIT_minval ("read a line"                        , SCRP_read   (), 1);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "    echo     § ...check y location   § - - - - - - - - - - - - -  § y       § r_norm93   § -125.381                                     §");
   yUNIT_minstr ("... check verb"                     , my.verb       , "echo");
   yUNIT_minstr ("... check stage"                    , my.stage      , "");
   yUNIT_minchr ("... check share"                    , my.share      , '-');
   yUNIT_minchr ("... check mark"                     , my.mark       , '-');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "...check y location");
   yUNIT_minstr ("... check method"                   , my.meth       , "");
   yUNIT_minstr ("... check arguments"                , my.args       , "y");
   yUNIT_minstr ("... check test"                     , my.test       , "r_norm93");
   yUNIT_minstr ("... check expect"                   , my.expe       , "-125.381");
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "y");
   yUNIT_mindnoc ();

   yUNIT_mincond ("read system line");
   yUNIT_minval ("read a line"                        , SCRP_read   (), 1);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "    system   § remove a file                       § - - - - - - - - - - - - -  § rm -fv test.txt   §");
   yUNIT_minstr ("... check verb"                     , my.verb       , "system");
   yUNIT_minstr ("... check stage"                    , my.stage      , "");
   yUNIT_minchr ("... check share"                    , my.share      , '-');
   yUNIT_minchr ("... check mark"                     , my.mark       , '-');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "remove a file");
   yUNIT_minstr ("... check method"                   , my.meth       , "");
   yUNIT_minstr ("... check arguments"                , my.args       , "");
   yUNIT_minstr ("... check test"                     , my.test       , "");
   yUNIT_minstr ("... check expect"                   , my.expe       , "");
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "rm -fv test.txt");
   yUNIT_mindnoc ();

   yUNIT_mincond ("read shared section line");
   yUNIT_minval ("read a line"                        , SCRP_read   (), 1);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "SHARED   -a- § setup cron files and lines          § - - - - - - - -  § ((CC.---)) § - - - - - - - - - - - - - - - - - - - - - - - - -  §");
   yUNIT_minstr ("... check verb"                     , my.verb       , "SHARED");
   yUNIT_minstr ("... check stage"                    , my.stage      , "");
   yUNIT_minchr ("... check share"                    , my.share      , 'a');
   yUNIT_minchr ("... check mark"                     , my.mark       , '-');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "setup cron files and lines");
   yUNIT_minstr ("... check method"                   , my.meth       , "");
   yUNIT_minstr ("... check arguments"                , my.args       , "");
   yUNIT_minstr ("... check test"                     , my.test       , "");
   yUNIT_minstr ("... check expect"                   , my.expe       , "");
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("read use shared line");
   yUNIT_minval ("read a line"                        , SCRP_read   (), 1);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , " REUSE -a-   § - - - - - - - - - - - -  § - - - - - - - - - - - - - - -  § ((03.---)) § - - - - - - - - - - - - - - - - - - - -  §");
   yUNIT_minstr ("... check verb"                     , my.verb       , "REUSE");
   yUNIT_minstr ("... check stage"                    , my.stage      , "");
   yUNIT_minchr ("... check share"                    , my.share      , 'a');
   yUNIT_minchr ("... check mark"                     , my.mark       , '-');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "");
   yUNIT_minstr ("... check method"                   , my.meth       , "");
   yUNIT_minstr ("... check arguments"                , my.args       , "");
   yUNIT_minstr ("... check test"                     , my.test       , "");
   yUNIT_minstr ("... check expect"                   , my.expe       , "");
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("read end-of-file");
   yUNIT_minval ("read a line"                        , SCRP_read   (), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), -999);
   yUNIT_minval ("close the script file"              , SCRP_close  (), 0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("clean up after");
   system ("rm -f /tmp/koios.unit 2> /dev/null");
   yUNIT_mindnoc ();

   yUNIT_minprcs ();
   return 0;
}



/*====================------------------------------------====================*/
/*===----                     script writing                           ----===*/
/*====================------------------------------------====================*/
static void      o___CONV____________________o (void) {;}

char
koios__unit_conv_files   (void)
{
   yUNIT_minscrp ("koios_conv file open and close");
   yURG_err_none ();  /* not to stderr/terminal */

   yUNIT_mincond ("prepare clean start");
   system ("rm -f /tmp/koios.unit 2> /dev/null");
   yUNIT_mindnoc ();

   yUNIT_mincond ("attempt to open with no name");
   strcpy (my.n_conv, "");
   yUNIT_minstr ("... check script name"              , my.n_conv     , "");
   yUNIT_minval ("... check script pointer"           , my.f_conv     , 0);
   yUNIT_minval ("open the script file"               , CONV_open   (), -999);
   yUNIT_minstr ("... check script name"              , my.n_conv     , "");
   yUNIT_minval ("... check script pointer"           , my.f_conv     , 0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("attempt to close when not open");
   strcpy (my.n_conv, "");
   yUNIT_minstr ("... check script name"              , my.n_conv     , "");
   yUNIT_minval ("... check script pointer"           , my.f_conv     , 0);
   yUNIT_minval ("close the script file"              , CONV_close  (), -999);
   yUNIT_minstr ("... check script name"              , my.n_conv     , "");
   yUNIT_minval ("... check script pointer"           , my.f_conv     , 0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("open a new file name");
   strcpy (my.n_conv, "/tmp/koios.unit");
   system ("touch /tmp/koios.unit");
   yUNIT_minstr ("... check script name"              , my.n_conv     , "/tmp/koios.unit");
   yUNIT_minval ("... check script pointer"           , my.f_conv     , 0);
   yUNIT_minval ("open the script file"               , CONV_open   (), 0);
   yUNIT_minstr ("... check script name"              , my.n_conv     , "/tmp/koios.unit");
   yUNIT_minval ("... check script pointer"           , my.f_conv     , my.f_conv);
   yUNIT_mindnoc ();

   yUNIT_mincond ("close the new name");
   yUNIT_minstr ("... check script name"              , my.n_conv     , "/tmp/koios.unit");
   yUNIT_minval ("... check script pointer"           , my.f_conv     , my.f_conv);
   yUNIT_minval ("close the script file"              , CONV_close  (), 0);
   yUNIT_minstr ("... check script name"              , my.n_conv     , "/tmp/koios.unit");
   yUNIT_minval ("... check script pointer"           , my.f_conv     , 0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("attempt to close twice");
   yUNIT_minstr ("... check script name"              , my.n_conv     , "/tmp/koios.unit");
   yUNIT_minval ("... check script pointer"           , my.f_conv     , 0);
   yUNIT_minval ("close the script file"              , CONV_close  (), -999);
   yUNIT_minstr ("... check script name"              , my.n_conv     , "/tmp/koios.unit");
   yUNIT_minval ("... check script pointer"           , my.f_conv     , 0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("clean up after");
   system ("rm -f /tmp/koios.unit 2> /dev/null");
   yUNIT_mindnoc ();

   yUNIT_minprcs ();
   return 0;
}

char
koios__unit_conv_ends    (void)
{
   int         c           =    0;

   yUNIT_minscrp ("CONV_beg, CONV_end, CONV_header");
   yURG_err_none ();  /* not to stderr/terminal */

   yUNIT_mincond ("prepare and open a new file");
   strcpy (my.n_conv, "/tmp/koios.unit");
   yUNIT_minval ("open the script file"               , CONV_open   (), 0);
   yUNIT_minstr ("... check script name"              , my.n_conv     , "/tmp/koios.unit");
   yUNIT_minval ("... check script pointer"           , my.f_conv     , my.f_conv);
   yUNIT_mindnoc ();

   yUNIT_mincond ("write the beginning");
   CONV_cycle ();
   yUNIT_minval ("call beg"                           , CONV_beg    (), 0);
   yUNIT_minstr ("... ... shebang"                    , yURG_peek (my.n_conv, 'º'), "#!/usr/local/bin/koios");
   yUNIT_minstr ("... ... title"                      , yURG_peek (my.n_conv, 'Ö'), "#   koios-polos (axis of heaven) unit testing meta-language");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_conv) , 2);
   yUNIT_mindnoc ();

   yUNIT_mincond ("write a standard header");
   CONV_cycle ();
   yUNIT_minval ("call header"                        , CONV_header (), 0);
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_conv, 'º'), "");
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_conv, 'Ö'), "");
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_conv, 'Ö'), "");
   yUNIT_minstr ("... ... ruler"                      , yURG_peek (my.n_conv, 'Ö'), "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-123456789- ");
   yUNIT_minstr ("... ... title"                      , yURG_peek (my.n_conv, 'Ö'), "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  ========(var)======= ");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_conv) , 5);
   yUNIT_mindnoc ();

   yUNIT_mincond ("write the ending");
   CONV_cycle ();
   yUNIT_minval ("call end"                           , CONV_end    (), 0);
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_conv, 'º'), "");
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_conv, 'Ö'), "");
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_conv, 'Ö'), "");
   yUNIT_minstr ("... check unit finish"              , yURG_peek (my.n_conv, 'Ö'), "# end-of-file.  done, finito, completare, whimper [Ï´···");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_conv) , 4);
   yUNIT_mindnoc ();

   yUNIT_mincond ("clean up after");
   system ("rm -f /tmp/koios.unit 2> /dev/null");
   yUNIT_mindnoc ();

   yUNIT_minprcs ();
   return 0;
}

char
koios__unit_conv_prep    (void)
{
   int         c           =    0;

   yUNIT_minscrp ("CONV_prep, CONV_incl, CONV_comment");
   yURG_err_none ();  /* not to stderr/terminal */

   yUNIT_mincond ("prepare and open a new file");
   strcpy (my.n_scrp, "/tmp/koios.unit");
   system ("touch /tmp/koios.unit");
   strcpy (my.n_wave, "/tmp/koios.wave");
   yUNIT_minval ("open the script file"               , SCRP_open   (), 0);
   strcpy (my.n_conv, "/tmp/koios.unit.new");
   yUNIT_minval ("open the script file"               , CONV_open   (), 0);
   yUNIT_minstr ("... check script name"              , my.n_conv     , "/tmp/koios.unit.new");
   yUNIT_minval ("... check script pointer"           , my.f_conv     , my.f_conv);
   yUNIT_mindnoc ();

   yUNIT_mincond ("write the prep");
   strcpy (my.recd, "PREP   include the prototype headers          ");
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse the prep line"                , SCRP_parse (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "PREP  § include the prototype headers  §  §  §  §  §");
   yUNIT_minstr ("... check verb"                     , my.verb       , "PREP");
   yUNIT_minstr ("... check stage"                    , my.stage      , "");
   yUNIT_minchr ("... check share"                    , my.share      , '-');
   yUNIT_minchr ("... check mark"                     , my.mark       , '-');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "include the prototype headers");
   yUNIT_minstr ("... check method"                   , my.meth       , "");
   yUNIT_minstr ("... check arguments"                , my.args       , "");
   yUNIT_minstr ("... check test"                     , my.test       , "");
   yUNIT_minstr ("... check expect"                   , my.expe       , "");
   CONV_cycle ();
   yUNIT_minval ("call prep"                          , CONV_prep   (), 0);
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_conv, 'º'), "");
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_conv, 'Ö'), "");
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_conv, 'Ö'), "");
   yUNIT_minstr ("... ... ruler"                      , yURG_peek (my.n_conv, 'Ö'), "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-123456789- ");
   yUNIT_minstr ("... ... title"                      , yURG_peek (my.n_conv, 'Ö'), "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  ========(var)======= ");
   yUNIT_minstr ("... check unit prep"                , yURG_peek (my.n_conv, 'Ö'), "PREP          include the prototype headers                                      - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_conv) , 6);
   yUNIT_mindnoc ();

   yUNIT_mincond ("write an include");
   strcpy (my.recd, "incl   public header  stdio.h         ");
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse the line"                     , SCRP_parse (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "incl  § public header § stdio.h §  §  §  §  §");
   yUNIT_minstr ("... check verb"                     , my.verb       , "incl");
   yUNIT_minstr ("... check stage"                    , my.stage      , "");
   yUNIT_minchr ("... check share"                    , my.share      , '-');
   yUNIT_minchr ("... check mark"                     , my.mark       , '-');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "public header");
   yUNIT_minstr ("... check method"                   , my.meth       , "stdio.h");
   yUNIT_minstr ("... check arguments"                , my.args       , "");
   yUNIT_minstr ("... check test"                     , my.test       , "");
   yUNIT_minstr ("... check expect"                   , my.expe       , "");
   CONV_cycle ();
   yUNIT_minval ("call include"                       , CONV_incl   (), 0);
   yUNIT_minstr ("... check include line"             , yURG_peek (my.n_conv, 'º'), "   incl       public header                        stdio.h                     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_conv) , 1);
   yUNIT_mindnoc ();

   yUNIT_mincond ("write a comment");
   strcpy (my.recd, "#> the following macro resets exec lines");
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse the line"                     , SCRP_parse (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "#> the following macro resets exec lines");
   yUNIT_minstr ("... check verb"                     , my.verb       , "#>");
   yUNIT_minstr ("... check stage"                    , my.stage      , "");
   yUNIT_minchr ("... check share"                    , my.share      , '-');
   yUNIT_minchr ("... check mark"                     , my.mark       , '-');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "");
   yUNIT_minstr ("... check method"                   , my.meth       , "");
   yUNIT_minstr ("... check arguments"                , my.args       , "");
   yUNIT_minstr ("... check test"                     , my.test       , "");
   yUNIT_minstr ("... check expect"                   , my.expe       , "");
   CONV_cycle ();
   yUNIT_minval ("call include"                       , CONV_comment(), 0);
   yUNIT_minstr ("... check unit comment"             , yURG_peek (my.n_conv, 'º'), "#> the following macro resets exec lines");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_conv) , 1);
   yUNIT_mindnoc ();

   yUNIT_mincond ("clean up after");
   yUNIT_minval ("close script"                       , SCRP_close  (), 0);
   yUNIT_minval ("close converted"                    , CONV_close  (), 0);
   system ("rm -f /tmp/koios.unit     2> /dev/null");
   system ("rm -f /tmp/koios.wave     2> /dev/null");
   system ("rm -f /tmp/koios.unit.new 2> /dev/null");
   yUNIT_mindnoc ();

   yUNIT_minprcs ();
   return 0;
}

char
koios__unit_conv_scrp    (void)
{
   int         c           =    0;

   yUNIT_minscrp ("CONV_scrp, CONV_sect, CONV_shared, CONV_global");
   yURG_err_none ();  /* not to stderr/terminal */

   yUNIT_mincond ("prepare and open a new file");
   strcpy (my.n_scrp, "/tmp/koios.unit");
   system ("touch /tmp/koios.unit");
   strcpy (my.n_wave, "/tmp/koios.wave");
   yUNIT_minval ("open the script file"               , SCRP_open   (), 0);
   strcpy (my.n_conv, "/tmp/koios.unit.new");
   yUNIT_minval ("open the script file"               , CONV_open   (), 0);
   yUNIT_minstr ("... check script name"              , my.n_conv     , "/tmp/koios.unit.new");
   yUNIT_minval ("... check script pointer"           , my.f_conv     , my.f_conv);
   yUNIT_mindnoc ();

   yUNIT_mincond ("check defaults");
   yUNIT_minval ("... run clear"                      , SCRP__shared_purge ()         , 0);
   yUNIT_minstr ("... check all marks"                , SCRP__shared_used  ()         , "--------------------------   --------------------------   ----------");
   yUNIT_mindnoc ();

   yUNIT_mincond ("write a script");
   strcpy (my.recd, "SCRP [ì4]   (FILE) biggest script  core_function       ");
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse the line"                     , SCRP_parse (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "SCRP [ì4]  § (FILE) biggest script § core_function §  §  §  §");
   yUNIT_minstr ("... check verb"                     , my.verb       , "SCRP");
   yUNIT_minstr ("... check stage"                    , my.stage      , "ì4");
   yUNIT_minchr ("... check share"                    , my.share      , '-');
   yUNIT_minchr ("... check mark"                     , my.mark       , '-');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "(FILE) biggest script");
   yUNIT_minstr ("... check method"                   , my.meth       , "core_function");
   yUNIT_minstr ("... check arguments"                , my.args       , "");
   yUNIT_minstr ("... check test"                     , my.test       , "");
   yUNIT_minstr ("... check expect"                   , my.expe       , "");
   CONV_cycle ();
   yUNIT_minval ("call script"                        , CONV_scrp   (), 0);
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_conv, 'º'), "");
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_conv, 'Ö'), "");
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_conv, 'Ö'), "");
   yUNIT_minstr ("... ... ruler"                      , yURG_peek (my.n_conv, 'Ö'), "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-123456789- ");
   yUNIT_minstr ("... ... title"                      , yURG_peek (my.n_conv, 'Ö'), "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  ========(var)======= ");
   yUNIT_minstr ("... check script"                   , yURG_peek (my.n_conv, 'Ö'), "SCRP    [ì4]  (FILE) biggest script                                              core_function                                                                                         ((01.---))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_conv) , 6);
   yUNIT_mindnoc ();

   yUNIT_mincond ("write a section break");
   strcpy (my.recd, "SECT  file oriented         ");
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse the line"                     , SCRP_parse (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "SECT § file oriented §  §  §  §  §");
   yUNIT_minstr ("... check verb"                     , my.verb       , "SECT");
   yUNIT_minstr ("... check stage"                    , my.stage      , "");
   yUNIT_minchr ("... check share"                    , my.share      , '-');
   yUNIT_minchr ("... check mark"                     , my.mark       , '-');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "file oriented");
   yUNIT_minstr ("... check method"                   , my.meth       , "");
   yUNIT_minstr ("... check arguments"                , my.args       , "");
   yUNIT_minstr ("... check test"                     , my.test       , "");
   yUNIT_minstr ("... check expect"                   , my.expe       , "");
   CONV_cycle ();
   yUNIT_minval ("call section"                       , CONV_sect   (), 0);
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_conv, 'º'), "");
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_conv, 'Ö'), "");
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_conv, 'Ö'), "");
   yUNIT_minstr ("... ... ruler"                      , yURG_peek (my.n_conv, 'Ö'), "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-123456789- ");
   yUNIT_minstr ("... ... title"                      , yURG_peek (my.n_conv, 'Ö'), "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  ========(var)======= ");
   yUNIT_minstr ("... check section"                  , yURG_peek (my.n_conv, 'Ö'), "SECT          file oriented                                                      - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_conv) , 6);
   yUNIT_mindnoc ();

   yUNIT_mincond ("write a shared line");
   strcpy (my.recd, "SHARED -a-  remove temporary files         ");
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse the line"                     , SCRP_parse (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "SHARED -a- § remove temporary files §  §  §  §  §");
   yUNIT_minstr ("... check verb"                     , my.verb       , "SHARED");
   yUNIT_minstr ("... check stage"                    , my.stage      , "");
   yUNIT_minchr ("... check share"                    , my.share      , 'a');
   yUNIT_minchr ("... check mark"                     , my.mark       , '-');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "remove temporary files");
   yUNIT_minstr ("... check method"                   , my.meth       , "");
   yUNIT_minstr ("... check arguments"                , my.args       , "");
   yUNIT_minstr ("... check test"                     , my.test       , "");
   yUNIT_minstr ("... check expect"                   , my.expe       , "");
   CONV_cycle ();
   yUNIT_minval ("call shared"                        , CONV_shared (), 0);
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_conv, 'º'), "");
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_conv, 'Ö'), "");
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_conv, 'Ö'), "");
   yUNIT_minstr ("... ... ruler"                      , yURG_peek (my.n_conv, 'Ö'), "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-123456789- ");
   yUNIT_minstr ("... ... title"                      , yURG_peek (my.n_conv, 'Ö'), "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  ========(var)======= ");
   yUNIT_minstr ("... check shared header"            , yURG_peek (my.n_conv, 'Ö'), "SHARED   -a-  remove temporary files                                             - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((aa.---))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_conv) , 6);
   yUNIT_mindnoc ();

   strcpy (my.n_base, "master");  /* prepare for SHARED defense testing */

   yUNIT_mincond ("write a global line");
   strcpy (my.recd, "GLOBAL -D-  setup base test objects         ");
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse the line"                     , SCRP_parse (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "GLOBAL -D- § setup base test objects §  §  §  §  §");
   yUNIT_minstr ("... check verb"                     , my.verb       , "GLOBAL");
   yUNIT_minstr ("... check stage"                    , my.stage      , "");
   yUNIT_minchr ("... check share"                    , my.share      , 'D');
   yUNIT_minchr ("... check mark"                     , my.mark       , '-');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "setup base test objects");
   yUNIT_minstr ("... check method"                   , my.meth       , "");
   yUNIT_minstr ("... check arguments"                , my.args       , "");
   yUNIT_minstr ("... check test"                     , my.test       , "");
   yUNIT_minstr ("... check expect"                   , my.expe       , "");
   CONV_cycle ();
   yUNIT_minval ("call shared"                        , CONV_global (), 0);
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_conv, 'º'), "");
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_conv, 'Ö'), "");
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_conv, 'Ö'), "");
   yUNIT_minstr ("... ... ruler"                      , yURG_peek (my.n_conv, 'Ö'), "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-123456789- ");
   yUNIT_minstr ("... ... title"                      , yURG_peek (my.n_conv, 'Ö'), "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  ========(var)======= ");
   yUNIT_minstr ("... check global header"            , yURG_peek (my.n_conv, 'Ö'), "GLOBAL   -D-  setup base test objects                                            - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((DD.---))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_conv) , 6);
   yUNIT_mindnoc ();

   strcpy (my.n_base, "koios" );  /* prepare for SHARED testing */

   yUNIT_mincond ("clean up after");
   yUNIT_minval ("close script"                       , SCRP_close  (), 0);
   yUNIT_minval ("close converted"                    , CONV_close  (), 0);
   system ("rm -f /tmp/koios.unit     2> /dev/null");
   system ("rm -f /tmp/koios.wave     2> /dev/null");
   system ("rm -f /tmp/koios.unit.new 2> /dev/null");
   yUNIT_mindnoc ();

   yUNIT_minprcs ();
   return 0;
}

char
koios__unit_conv_cond    (void)
{
   int         c           =    0;

   yUNIT_minscrp ("CONV_cond, CONV_group, CONV_ditto, CONV_reuse");
   yURG_err_none ();  /* not to stderr/terminal */
   my.run_type = G_RUN_UPDATE;

   yUNIT_mincond ("prepare and open a new file");
   strcpy (my.n_scrp, "/tmp/koios.unit");
   system ("touch /tmp/koios.unit");
   strcpy (my.n_wave, "/tmp/koios.wave");
   yUNIT_minval ("open the script file"               , SCRP_open   (), 0);
   strcpy (my.n_conv, "/tmp/koios.unit.new");
   yUNIT_minval ("open the script file"               , CONV_open   (), 0);
   yUNIT_minstr ("... check script name"              , my.n_conv     , "/tmp/koios.unit.new");
   yUNIT_minval ("... check script pointer"           , my.f_conv     , my.f_conv);
   yUNIT_mindnoc ();

   yUNIT_mincond ("write a condition");
   strcpy (my.recd, "COND (2)  verify successful value         ");
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse the line"                     , SCRP_parse (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "COND (2) § verify successful value §  §  §  §  §");
   yUNIT_minstr ("... check verb"                     , my.verb       , "COND");
   yUNIT_minstr ("... check stage"                    , my.stage      , "");
   yUNIT_minchr ("... check share"                    , my.share      , '-');
   yUNIT_minchr ("... check mark"                     , my.mark       , '2');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "verify successful value");
   yUNIT_minstr ("... check method"                   , my.meth       , "");
   yUNIT_minstr ("... check arguments"                , my.args       , "");
   yUNIT_minstr ("... check test"                     , my.test       , "");
   yUNIT_minstr ("... check expect"                   , my.expe       , "");
   CONV_cycle ();
   yUNIT_minval ("call condition"                     , CONV_cond   (), 0);
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_conv, 'º'), "");
   yUNIT_minstr ("... check condition header"         , yURG_peek (my.n_conv, 'Ö'), "   COND  (2)  verify successful value                                            - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((DD.001))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_conv) , 2);
   yUNIT_mindnoc ();

   yUNIT_mincond ("write a ditto");
   strcpy (my.recd, "DITTO (2)           ");
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse the line"                     , SCRP_parse (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "DITTO (2) §  §  §  §  §  §");
   yUNIT_minstr ("... check verb"                     , my.verb       , "DITTO");
   yUNIT_minstr ("... check stage"                    , my.stage      , "");
   yUNIT_minchr ("... check share"                    , my.share      , '-');
   yUNIT_minchr ("... check mark"                     , my.mark       , '2');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "");
   yUNIT_minstr ("... check method"                   , my.meth       , "");
   yUNIT_minstr ("... check arguments"                , my.args       , "");
   yUNIT_minstr ("... check test"                     , my.test       , "");
   yUNIT_minstr ("... check expect"                   , my.expe       , "");
   CONV_cycle ();
   yUNIT_minval ("call ditto"                         , CONV_ditto  (), 0);
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_conv, 'º'), "");
   yUNIT_minstr ("... check ditto"                    , yURG_peek (my.n_conv, 'Ö'), "   DITTO (2)  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((DD.002))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_conv) , 2);
   yUNIT_mindnoc ();

   yUNIT_mincond ("write a group");
   strcpy (my.recd, "GROUP  check major defenses         ");
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse the line"                     , SCRP_parse (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "GROUP § check major defenses §  §  §  §  §");
   yUNIT_minstr ("... check verb"                     , my.verb       , "GROUP");
   yUNIT_minstr ("... check stage"                    , my.stage      , "");
   yUNIT_minchr ("... check share"                    , my.share      , '-');
   yUNIT_minchr ("... check mark"                     , my.mark       , '-');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "check major defenses");
   yUNIT_minstr ("... check method"                   , my.meth       , "");
   yUNIT_minstr ("... check arguments"                , my.args       , "");
   yUNIT_minstr ("... check test"                     , my.test       , "");
   yUNIT_minstr ("... check expect"                   , my.expe       , "");
   CONV_cycle ();
   yUNIT_minval ("call group"                         , CONV_group  (), 0);
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_conv, 'º'), "");
   yUNIT_minstr ("... check group"                    , yURG_peek (my.n_conv, 'Ö'), "   GROUP      check major defenses                                               - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_conv) , 2);
   yUNIT_mindnoc ();

   yUNIT_mincond ("write a use for shares");
   yUNIT_minval ("... set shared to reuse"            , SCRP__shared_set   ('r', 'd') ,    0);
   strcpy (my.recd, "REUSE -d-           ");
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse the line"                     , SCRP_parse (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "REUSE -d- §  §  §  §  §  §");
   yUNIT_minstr ("... check verb"                     , my.verb       , "REUSE");
   yUNIT_minstr ("... check stage"                    , my.stage      , "");
   yUNIT_minchr ("... check share"                    , my.share      , 'd');
   yUNIT_minchr ("... check mark"                     , my.mark       , '-');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "");
   yUNIT_minstr ("... check method"                   , my.meth       , "");
   yUNIT_minstr ("... check arguments"                , my.args       , "");
   yUNIT_minstr ("... check test"                     , my.test       , "");
   yUNIT_minstr ("... check expect"                   , my.expe       , "");
   CONV_cycle ();
   yUNIT_minval ("call group"                         , CONV_reuse  (), 0);
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_conv, 'º'), "");
   yUNIT_minstr ("... check reuse"                    , yURG_peek (my.n_conv, 'Ö'), "   REUSE -d-  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_conv) , 2);
   yUNIT_mindnoc ();

   yUNIT_mincond ("clean up after");
   yUNIT_minval ("close script"                       , SCRP_close  (), 0);
   yUNIT_minval ("close converted"                    , CONV_close  (), 0);
   system ("rm -f /tmp/koios.unit     2> /dev/null");
   system ("rm -f /tmp/koios.wave     2> /dev/null");
   system ("rm -f /tmp/koios.unit.new 2> /dev/null");
   yUNIT_mindnoc ();

   yUNIT_minprcs ();
   return 0;
}

char
koios__unit_conv_step    (void)
{
   int         c           =    0;

   yUNIT_minscrp ("CONV_exec, CONV_load, CONV_code, CONV_echo");
   yURG_err_none ();  /* not to stderr/terminal */
   my.run_type = G_RUN_UPDATE;

   yUNIT_mincond ("prepare and open a new file");
   strcpy (my.n_scrp, "/tmp/koios.unit");
   system ("touch /tmp/koios.unit");
   strcpy (my.n_wave, "/tmp/koios.wave");
   yUNIT_minval ("open the script file"               , SCRP_open   (), 0);
   strcpy (my.n_conv, "/tmp/koios.unit.new");
   yUNIT_minval ("open the script file"               , CONV_open   (), 0);
   yUNIT_minstr ("... check script name"              , my.n_conv     , "/tmp/koios.unit.new");
   yUNIT_minval ("... check script pointer"           , my.f_conv     , my.f_conv);
   yUNIT_mindnoc ();

   yUNIT_mincond ("write a exec");
   strcpy (my.recd, "exec          read a line      SCRP_read    test, 5   i_lesser    0       my_var   ");
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse the line"                     , SCRP_parse (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "exec         § read a line     § SCRP_read   § test, 5  § i_lesser   § 0      § my_var   §");
   yUNIT_minstr ("... check verb"                     , my.verb       , "exec");
   yUNIT_minstr ("... check stage"                    , my.stage      , "");
   yUNIT_minchr ("... check share"                    , my.share      , '-');
   yUNIT_minchr ("... check mark"                     , my.mark       , '-');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "read a line");
   yUNIT_minstr ("... check method"                   , my.meth       , "SCRP_read");
   yUNIT_minstr ("... check arguments"                , my.args       , "test, 5");
   yUNIT_minstr ("... check test"                     , my.test       , "i_lesser");
   yUNIT_minstr ("... check expect"                   , my.expe       , "0");
   yUNIT_minstr ("... check return"                   , my.retn       , "my_var");
   yUNIT_minstr ("... check code"                     , my.code       , "test, 5");
   CONV_cycle ();
   yUNIT_minval ("call exec"                          , CONV_exec   (), 0);
   yUNIT_minstr ("... check exec"                     , yURG_peek (my.n_conv, 'º'), "     exec     read a line                          SCRP_read                   test, 5                                                                                               i_lesser    0                                                                                                     my_var               ");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_conv) , 1);
   yUNIT_mindnoc ();

   yUNIT_mincond ("write a get");
   strcpy (my.recd, "get  ...check count  UNIT_answer  \"ans\"  s_equal  count = 15.2 ");
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse the line"                     , SCRP_parse (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "get § ...check count § UNIT_answer § \"ans\" § s_equal § count = 15.2 §");
   yUNIT_minstr ("... check verb"                     , my.verb       , "get");
   yUNIT_minstr ("... check stage"                    , my.stage      , "");
   yUNIT_minchr ("... check share"                    , my.share      , '-');
   yUNIT_minchr ("... check mark"                     , my.mark       , '-');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "...check count");
   yUNIT_minstr ("... check method"                   , my.meth       , "UNIT_answer");
   yUNIT_minstr ("... check arguments"                , my.args       , "\"ans\"");
   yUNIT_minstr ("... check test"                     , my.test       , "s_equal");
   yUNIT_minstr ("... check expect"                   , my.expe       , "count = 15.2");
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "\"ans\"");
   CONV_cycle ();
   yUNIT_minval ("call exec"                          , CONV_exec   (), 0);
   yUNIT_minstr ("... check get"                      , yURG_peek (my.n_conv, 'º'), "     get      ...check count                       UNIT_answer                 \"ans\"                                                                                                 s_equal     count = 15.2                                                                                         ");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_conv) , 1);
   yUNIT_mindnoc ();

   yUNIT_mincond ("write a mode");
   strcpy (my.recd, "mode  FORCED_FAIL         ");
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse the line"                     , SCRP_parse (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "mode § FORCED_FAIL §  §  §  §  §");
   yUNIT_minstr ("... check verb"                     , my.verb       , "mode");
   yUNIT_minstr ("... check stage"                    , my.stage      , "");
   yUNIT_minchr ("... check share"                    , my.share      , '-');
   yUNIT_minchr ("... check mark"                     , my.mark       , '-');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "FORCED_FAIL");
   yUNIT_minstr ("... check method"                   , my.meth       , "");
   yUNIT_minstr ("... check arguments"                , my.args       , "");
   yUNIT_minstr ("... check test"                     , my.test       , "");
   yUNIT_minstr ("... check expect"                   , my.expe       , "");
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "");
   CONV_cycle ();
   yUNIT_minval ("call code"                          , CONV_mode   (), 0);
   yUNIT_minstr ("... check mode"                     , yURG_peek (my.n_conv, 'º'), "     mode     FORCED_FAIL                          - - - - - - - - - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_conv) , 1);
   yUNIT_mindnoc ();

   yUNIT_mincond ("write a load");
   strcpy (my.recd, "load  keyboard input  ncurses  abcdefghijklmnopqrstuvwxyz ");
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse the line"                     , SCRP_parse (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "load § keyboard input § ncurses § abcdefghijklmnopqrstuvwxyz §");
   yUNIT_minstr ("... check verb"                     , my.verb       , "load");
   yUNIT_minstr ("... check stage"                    , my.stage      , "");
   yUNIT_minchr ("... check share"                    , my.share      , '-');
   yUNIT_minchr ("... check mark"                     , my.mark       , '-');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "keyboard input");
   yUNIT_minstr ("... check method"                   , my.meth       , "ncurses");
   yUNIT_minstr ("... check arguments"                , my.args       , "");
   yUNIT_minstr ("... check test"                     , my.test       , "");
   yUNIT_minstr ("... check expect"                   , my.expe       , "");
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "abcdefghijklmnopqrstuvwxyz");
   CONV_cycle ();
   yUNIT_minval ("call code"                          , CONV_load   (), 0);
   yUNIT_minstr ("... check load"                     , yURG_peek (my.n_conv, 'º'), "     load     keyboard input                       ncurses                     abcdefghijklmnopqrstuvwxyz                                                                                                                                                                                                 ");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_conv) , 1);
   yUNIT_mindnoc ();

   yUNIT_mincond ("write a code");
   strcpy (my.recd, "code  working variable   int l = 15; ");
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse the line"                     , SCRP_parse (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "code § working variable § § int l = 15; §");
   yUNIT_minstr ("... check verb"                     , my.verb       , "code");
   yUNIT_minstr ("... check stage"                    , my.stage      , "");
   yUNIT_minchr ("... check share"                    , my.share      , '-');
   yUNIT_minchr ("... check mark"                     , my.mark       , '-');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "working variable");
   yUNIT_minstr ("... check method"                   , my.meth       , "");
   yUNIT_minstr ("... check arguments"                , my.args       , "");
   yUNIT_minstr ("... check test"                     , my.test       , "");
   yUNIT_minstr ("... check expect"                   , my.expe       , "");
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "int l = 15;");
   CONV_cycle ();
   yUNIT_minval ("call code"                          , CONV_code   (), 0);
   yUNIT_minstr ("... check code"                     , yURG_peek (my.n_conv, 'º'), "     code     working variable                     - - - - - - - - - - - - -   int l = 15;                                                                                                                                                                                                                ");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_conv) , 1);
   yUNIT_mindnoc ();

   yUNIT_mincond ("write an echo");
   strcpy (my.recd, "echo  check length   l  r_equal  15.2 ");
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse the line"                     , SCRP_parse (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "echo § check length § § l § r_equal § 15.2 §");
   yUNIT_minstr ("... check verb"                     , my.verb       , "echo");
   yUNIT_minstr ("... check stage"                    , my.stage      , "");
   yUNIT_minchr ("... check share"                    , my.share      , '-');
   yUNIT_minchr ("... check mark"                     , my.mark       , '-');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "check length");
   yUNIT_minstr ("... check method"                   , my.meth       , "");
   yUNIT_minstr ("... check arguments"                , my.args       , "l");
   yUNIT_minstr ("... check test"                     , my.test       , "r_equal");
   yUNIT_minstr ("... check expect"                   , my.expe       , "15.2");
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "l");
   CONV_cycle ();
   yUNIT_minval ("call code"                          , CONV_echo   (), 0);
   yUNIT_minstr ("... check echo"                     , yURG_peek (my.n_conv, 'º'), "     echo     check length                         - - - - - - - - - - - - -   l                                                                                                     r_equal     15.2                                                                                                 ");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_conv) , 1);
   yUNIT_mindnoc ();

   yUNIT_mincond ("clean up after");
   yUNIT_minval ("close script"                       , SCRP_close  (), 0);
   yUNIT_minval ("close converted"                    , CONV_close  (), 0);
   system ("rm -f /tmp/koios.unit     2> /dev/null");
   system ("rm -f /tmp/koios.wave     2> /dev/null");
   system ("rm -f /tmp/koios.unit.new 2> /dev/null");
   yUNIT_mindnoc ();

   yUNIT_minprcs ();
   return 0;
}



/*====================------------------------------------====================*/
/*===----                      code writing                            ----===*/
/*====================------------------------------------====================*/
static void      o___CODE____________________o (void) {;}

char
koios__unit_code_counts  (void)
{
   int            x_cond = 0;
   int            x_step = 0;

   yUNIT_minscrp ("CODE__shared");
   yURG_err_none ();  /* not to stderr/terminal */

   yUNIT_mincond ("prepare clean start");
   system ("rm -f /tmp/koios.unit 2> /dev/null");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check defaults");
   yUNIT_minval ("... run clear"                      , CODE__shared_purge ()         , 0);
   yUNIT_minstr ("... check all marks"                , CODE__shared_used  ()         , "--------------------------   --------------------------");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check master indexing");
   yUNIT_minval ("... master min"                     , CODE__shared_index ('m', 'A') ,    0);
   yUNIT_minval ("... master middle"                  , CODE__shared_index ('m', 'J') ,    9);
   yUNIT_minval ("... master max"                     , CODE__shared_index ('m', 'Z') ,   25);
   yUNIT_minval ("... master too small"               , CODE__shared_index ('m',  0 ) , -999);
   yUNIT_minval ("... master using reuses"            , CODE__shared_index ('m', 'b') , -999);
   yUNIT_minval ("... master using dittos"            , CODE__shared_index ('m', '4') , -999);
   yUNIT_minval ("... master using greek"             , CODE__shared_index ('m', 'ë') , -999);
   yUNIT_mindnoc ();

   yUNIT_mincond ("check reuses indexing");
   yUNIT_minval ("... reuses min"                     , CODE__shared_index ('r', 'a') ,    0);
   yUNIT_minval ("... reuses middle"                  , CODE__shared_index ('r', 'm') ,   12);
   yUNIT_minval ("... reuses max"                     , CODE__shared_index ('r', 'z') ,   25);
   yUNIT_minval ("... reuses too small"               , CODE__shared_index ('r',  0 ) , -999);
   yUNIT_minval ("... reuses using master"            , CODE__shared_index ('r', 'B') , -999);
   yUNIT_minval ("... reuses using dittos"            , CODE__shared_index ('r', '4') , -999);
   yUNIT_minval ("... reuses using greek"             , CODE__shared_index ('r', 'ë') , -999);
   yUNIT_mindnoc ();

   yUNIT_mincond ("check indexing with bad types");
   yUNIT_minval ("... check null"                     , CODE__shared_index ( 0 , '0') , -999);
   yUNIT_minval ("... check dittos"                   , CODE__shared_index ('d', '0') , -999);
   yUNIT_minval ("... check symbol"                   , CODE__shared_index ('#', '0') , -999);
   yUNIT_minval ("... check greek"                    , CODE__shared_index ('è', '0') , -999);
   yUNIT_mindnoc ();

   yUNIT_mincond ("get masters before setting");
   yUNIT_minstr ("... check all marks"                , CODE__shared_used  ()         , "--------------------------   --------------------------");
   x_cond = x_step = 0;
   yUNIT_minval ("... get master min"                 , CODE__shared_add   ('m', 'A', &x_cond, &x_step) ,    0);
   yUNIT_minval ("... ... check cond"                 , x_cond,    0);
   yUNIT_minval ("... ... check step"                 , x_step,    0);
   yUNIT_minval ("... get master middle"              , CODE__shared_add   ('m', 'J', &x_cond, &x_step) ,    0);
   yUNIT_minval ("... ... check cond"                 , x_cond,    0);
   yUNIT_minval ("... ... check step"                 , x_step,    0);
   yUNIT_minval ("... get master max"                 , CODE__shared_add   ('m', 'Z', &x_cond, &x_step) ,    0);
   yUNIT_minval ("... ... check cond"                 , x_cond,    0);
   yUNIT_minval ("... ... check step"                 , x_step,    0);
   yUNIT_minval ("... get master null"                , CODE__shared_add   ('m',  0 , &x_cond, &x_step) , -999);
   yUNIT_minval ("... ... check cond"                 , x_cond,    0);
   yUNIT_minval ("... ... check step"                 , x_step,    0);
   yUNIT_minval ("... get master reuses"              , CODE__shared_add   ('m', 'b', &x_cond, &x_step) , -999);
   yUNIT_minval ("... ... check cond"                 , x_cond,    0);
   yUNIT_minval ("... ... check step"                 , x_step,    0);
   yUNIT_minval ("... get master dittos"              , CODE__shared_add   ('m', '4', &x_cond, &x_step) , -999);
   yUNIT_minval ("... ... check cond"                 , x_cond,    0);
   yUNIT_minval ("... ... check step"                 , x_step,    0);
   yUNIT_minval ("... get master greek"               , CODE__shared_add   ('m', 'ë', &x_cond, &x_step) , -999);
   yUNIT_minval ("... ... check cond"                 , x_cond,    0);
   yUNIT_minval ("... ... check step"                 , x_step,    0);
   yUNIT_minval ("... get master symbol"              , CODE__shared_add   ('m', '-', &x_cond, &x_step) , -999);
   yUNIT_minval ("... ... check cond"                 , x_cond,    0);
   yUNIT_minval ("... ... check step"                 , x_step,    0);

   yUNIT_mincond ("set masters");
   yUNIT_minstr ("... check all marks"                , CODE__shared_used  ()         , "--------------------------   --------------------------");
   yUNIT_minval ("... set master min"                 , CODE__shared_set   ('m', 'A',  1,  5) ,    0);
   yUNIT_minstr ("... check all marks"                , CODE__shared_used  ()         , "5-------------------------   --------------------------");
   yUNIT_minval ("... set master middle"              , CODE__shared_set   ('m', 'J',  2, 12) ,    0);
   yUNIT_minstr ("... check all marks"                , CODE__shared_used  ()         , "5--------c----------------   --------------------------");
   yUNIT_minval ("... set master max"                 , CODE__shared_set   ('m', 'Z',  4, 29) ,    0);
   yUNIT_minstr ("... check all marks"                , CODE__shared_used  ()         , "5--------c---------------t   --------------------------");
   yUNIT_mindnoc ();

   yUNIT_mincond ("get masters after setting");
   x_cond = x_step = 0;
   yUNIT_minstr ("... check all marks"                , CODE__shared_used  ()         , "5--------c---------------t   --------------------------");
   yUNIT_minval ("... get master min"                 , CODE__shared_add   ('m', 'A', &x_cond, &x_step) ,    0);
   yUNIT_minval ("... ... check cond"                 , x_cond,    1);
   yUNIT_minval ("... ... check step"                 , x_step,    5);
   yUNIT_minval ("... get master middle"              , CODE__shared_add   ('m', 'J', &x_cond, &x_step) ,    0);
   yUNIT_minval ("... ... check cond"                 , x_cond,    3);
   yUNIT_minval ("... ... check step"                 , x_step,   17);
   yUNIT_minval ("... get master max"                 , CODE__shared_add   ('m', 'Z', &x_cond, &x_step) ,    0);
   yUNIT_minval ("... ... check cond"                 , x_cond,    7);
   yUNIT_minval ("... ... check step"                 , x_step,   46);
   yUNIT_minval ("... get master null"                , CODE__shared_add   ('m',  0 , &x_cond, &x_step) , -999);
   yUNIT_minval ("... ... check cond"                 , x_cond,    7);
   yUNIT_minval ("... ... check step"                 , x_step,   46);
   yUNIT_minval ("... get master reuses"              , CODE__shared_add   ('m', 'b', &x_cond, &x_step) , -999);
   yUNIT_minval ("... ... check cond"                 , x_cond,    7);
   yUNIT_minval ("... ... check step"                 , x_step,   46);
   yUNIT_minval ("... get master dittos"              , CODE__shared_add   ('m', '4', &x_cond, &x_step) , -999);
   yUNIT_minval ("... ... check cond"                 , x_cond,    7);
   yUNIT_minval ("... ... check step"                 , x_step,   46);
   yUNIT_minval ("... get master greek"               , CODE__shared_add   ('m', 'ë', &x_cond, &x_step) , -999);
   yUNIT_minval ("... ... check cond"                 , x_cond,    7);
   yUNIT_minval ("... ... check step"                 , x_step,   46);
   yUNIT_minval ("... get master symbol"              , CODE__shared_add   ('m', '-', &x_cond, &x_step) , -999);
   yUNIT_minval ("... ... check cond"                 , x_cond,    7);
   yUNIT_minval ("... ... check step"                 , x_step,   46);

   yUNIT_mincond ("get reuses before setting");
   x_cond = x_step = 0;
   yUNIT_minstr ("... check all marks"                , CODE__shared_used  ()         , "5--------c---------------t   --------------------------");
   yUNIT_minval ("... get reuses min"                 , CODE__shared_add   ('r', 'b', &x_cond, &x_step) ,    0);
   yUNIT_minval ("... ... check cond"                 , x_cond,    0);
   yUNIT_minval ("... ... check step"                 , x_step,    0);
   yUNIT_minval ("... get reuses middle"              , CODE__shared_add   ('r', 's', &x_cond, &x_step) ,    0);
   yUNIT_minval ("... ... check cond"                 , x_cond,    0);
   yUNIT_minval ("... ... check step"                 , x_step,    0);
   yUNIT_minval ("... get reuses max"                 , CODE__shared_add   ('r', 'y', &x_cond, &x_step) ,    0);
   yUNIT_minval ("... ... check cond"                 , x_cond,    0);
   yUNIT_minval ("... ... check step"                 , x_step,    0);
   yUNIT_minval ("... get reuses null"                , CODE__shared_add   ('r',  0 , &x_cond, &x_step) , -999);
   yUNIT_minval ("... ... check cond"                 , x_cond,    0);
   yUNIT_minval ("... ... check step"                 , x_step,    0);
   yUNIT_minval ("... get reuses reuses"              , CODE__shared_add   ('r', 'B', &x_cond, &x_step) , -999);
   yUNIT_minval ("... ... check cond"                 , x_cond,    0);
   yUNIT_minval ("... ... check step"                 , x_step,    0);
   yUNIT_minval ("... get reuses dittos"              , CODE__shared_add   ('r', '4', &x_cond, &x_step) , -999);
   yUNIT_minval ("... ... check cond"                 , x_cond,    0);
   yUNIT_minval ("... ... check step"                 , x_step,    0);
   yUNIT_minval ("... get reuses greek"               , CODE__shared_add   ('r', 'ë', &x_cond, &x_step) , -999);
   yUNIT_minval ("... ... check cond"                 , x_cond,    0);
   yUNIT_minval ("... ... check step"                 , x_step,    0);
   yUNIT_minval ("... get reuses symbol"              , CODE__shared_add   ('r', '-', &x_cond, &x_step) , -999);
   yUNIT_minval ("... ... check cond"                 , x_cond,    0);
   yUNIT_minval ("... ... check step"                 , x_step,    0);

   yUNIT_mincond ("set reuses");
   yUNIT_minstr ("... check all marks"                , CODE__shared_used  ()         , "5--------c---------------t   --------------------------");
   yUNIT_minval ("... set reuses min"                 , CODE__shared_set   ('r', 'b',  2,  8) ,    0);
   yUNIT_minstr ("... check all marks"                , CODE__shared_used  ()         , "5--------c---------------t   -8------------------------");
   yUNIT_minval ("... set reuses middle"              , CODE__shared_set   ('r', 's',  3, 22) ,    0);
   yUNIT_minstr ("... check all marks"                , CODE__shared_used  ()         , "5--------c---------------t   -8----------------m-------");
   yUNIT_minval ("... set reuses max"                 , CODE__shared_set   ('r', 'y',  5, 52) ,    0);
   yUNIT_minstr ("... check all marks"                , CODE__shared_used  ()         , "5--------c---------------t   -8----------------m-----Q-");
   yUNIT_mindnoc ();

   yUNIT_mincond ("get reuses after setting");
   x_cond = x_step = 0;
   yUNIT_minstr ("... check all marks"                , CODE__shared_used  ()         , "5--------c---------------t   -8----------------m-----Q-");
   yUNIT_minval ("... get reuses min"                 , CODE__shared_add   ('r', 'b', &x_cond, &x_step) ,    0);
   yUNIT_minval ("... ... check cond"                 , x_cond,    2);
   yUNIT_minval ("... ... check step"                 , x_step,    8);
   yUNIT_minval ("... get reuses middle"              , CODE__shared_add   ('r', 's', &x_cond, &x_step) ,    0);
   yUNIT_minval ("... ... check cond"                 , x_cond,    5);
   yUNIT_minval ("... ... check step"                 , x_step,   30);
   yUNIT_minval ("... get reuses max"                 , CODE__shared_add   ('r', 'y', &x_cond, &x_step) ,    0);
   yUNIT_minval ("... ... check cond"                 , x_cond,   10);
   yUNIT_minval ("... ... check step"                 , x_step,   82);
   yUNIT_minval ("... get reuses null"                , CODE__shared_add   ('r',  0 , &x_cond, &x_step) , -999);
   yUNIT_minval ("... ... check cond"                 , x_cond,   10);
   yUNIT_minval ("... ... check step"                 , x_step,   82);
   yUNIT_minval ("... get reuses reuses"              , CODE__shared_add   ('r', 'B', &x_cond, &x_step) , -999);
   yUNIT_minval ("... ... check cond"                 , x_cond,   10);
   yUNIT_minval ("... ... check step"                 , x_step,   82);
   yUNIT_minval ("... get reuses dittos"              , CODE__shared_add   ('r', '4', &x_cond, &x_step) , -999);
   yUNIT_minval ("... ... check cond"                 , x_cond,   10);
   yUNIT_minval ("... ... check step"                 , x_step,   82);
   yUNIT_minval ("... get reuses greek"               , CODE__shared_add   ('r', 'ë', &x_cond, &x_step) , -999);
   yUNIT_minval ("... ... check cond"                 , x_cond,   10);
   yUNIT_minval ("... ... check step"                 , x_step,   82);
   yUNIT_minval ("... get reuses symbol"              , CODE__shared_add   ('r', '-', &x_cond, &x_step) , -999);
   yUNIT_minval ("... ... check cond"                 , x_cond,   10);
   yUNIT_minval ("... ... check step"                 , x_step,   82);

   yUNIT_minprcs ();
   return 0;
}

char
koios__unit_code_files   (void)
{
   yUNIT_minscrp ("koios_code file open and close");
   yURG_err_none ();  /* not to stderr/terminal */

   yUNIT_mincond ("prepare clean start");
   system ("rm -f /tmp/koios_scrp_unit.cs   2> /dev/null");
   system ("rm -f /tmp/koios_scrp_unit.h    2> /dev/null");
   system ("rm -f /tmp/koios_scrp.wave      2> /dev/null");
   yUNIT_mindnoc ();

   yUNIT_mincond ("attempt to open with no code name");
   strcpy (my.n_code, "");
   strcpy (my.n_main, "");
   yUNIT_minstr ("... check code name"                , my.n_code     , "");
   yUNIT_minval ("... check code pointer"             , my.f_code     , 0);
   yUNIT_minstr ("... check main name"                , my.n_main     , "");
   yUNIT_minval ("... check main pointer"             , my.f_main     , 0);
   yUNIT_minval ("open the code/main file"            , CODE_open   (), -999);
   yUNIT_minstr ("... check code name"                , my.n_code     , "");
   yUNIT_minval ("... check code pointer"             , my.f_code     , 0);
   yUNIT_minstr ("... check main name"                , my.n_main     , "");
   yUNIT_minval ("... check main pointer"             , my.f_main     , 0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("attempt to close code when not open");
   strcpy (my.n_code, "");
   strcpy (my.n_main, "");
   yUNIT_minstr ("... check code name"                , my.n_code     , "");
   yUNIT_minval ("... check code pointer"             , my.f_code     , 0);
   yUNIT_minstr ("... check main name"                , my.n_main     , "");
   yUNIT_minval ("... check main pointer"             , my.f_main     , 0);
   yUNIT_minval ("close the code file"                , CODE_close  (my.f_code), -999);
   yUNIT_minstr ("... check code name"                , my.n_code     , "");
   yUNIT_minval ("... check code pointer"             , my.f_code     , 0);
   yUNIT_minstr ("... check main name"                , my.n_main     , "");
   yUNIT_minval ("... check main pointer"             , my.f_main     , 0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("attempt to close main when not open");
   strcpy (my.n_code, "");
   strcpy (my.n_main, "");
   yUNIT_minstr ("... check code name"                , my.n_code     , "");
   yUNIT_minval ("... check code pointer"             , my.f_code     , 0);
   yUNIT_minstr ("... check main name"                , my.n_main     , "");
   yUNIT_minval ("... check main pointer"             , my.f_main     , 0);
   yUNIT_minval ("close the code file"                , CODE_close  (my.f_main), -999);
   yUNIT_minstr ("... check code name"                , my.n_code     , "");
   yUNIT_minval ("... check code pointer"             , my.f_code     , 0);
   yUNIT_minstr ("... check main name"                , my.n_main     , "");
   yUNIT_minval ("... check main pointer"             , my.f_main     , 0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("attempt with only code name");
   strcpy (my.n_code, "/tmp/koios_scrp_unit.cs");
   strcpy (my.n_main, "");
   yUNIT_minstr ("... check code name"                , my.n_code     , "/tmp/koios_scrp_unit.cs");
   yUNIT_minval ("... check code pointer"             , my.f_code     , 0);
   yUNIT_minstr ("... check main name"                , my.n_main     , "");
   yUNIT_minval ("... check main pointer"             , my.f_main     , 0);
   yUNIT_minval ("open the script file"               , CODE_open   (), -999);
   yUNIT_minstr ("... check code name"                , my.n_code     , "/tmp/koios_scrp_unit.cs");
   yUNIT_minval ("... check code pointer"             , my.f_code     , 0);
   yUNIT_minstr ("... check main name"                , my.n_main     , "");
   yUNIT_minval ("... check main pointer"             , my.f_main     , 0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("attempt with only main name");
   strcpy (my.n_code, "");
   strcpy (my.n_main, "/tmp/koios_scrp_unit.h");
   yUNIT_minstr ("... check code name"                , my.n_code     , "");
   yUNIT_minval ("... check code pointer"             , my.f_code     , 0);
   yUNIT_minstr ("... check main name"                , my.n_main     , "/tmp/koios_scrp_unit.h");
   yUNIT_minval ("... check main pointer"             , my.f_main     , 0);
   yUNIT_minval ("open the script file"               , CODE_open   (), -999);
   yUNIT_minstr ("... check code name"                , my.n_code     , "");
   yUNIT_minval ("... check code pointer"             , my.f_code     , 0);
   yUNIT_minstr ("... check main name"                , my.n_main     , "/tmp/koios_scrp_unit.h");
   yUNIT_minval ("... check main pointer"             , my.f_main     , 0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("open normally");
   strcpy (my.n_code, "/tmp/koios_scrp_unit.cs");
   strcpy (my.n_main, "/tmp/koios_scrp_unit.h");
   yUNIT_minstr ("... check code name"                , my.n_code     , "/tmp/koios_scrp_unit.cs");
   yUNIT_minval ("... check code pointer"             , my.f_code     , 0);
   yUNIT_minstr ("... check main name"                , my.n_main     , "/tmp/koios_scrp_unit.h");
   yUNIT_minval ("... check main pointer"             , my.f_main     , 0);
   yUNIT_minval ("open the script file"               , CODE_open   (), 0);
   yUNIT_minstr ("... check code name"                , my.n_code     , "/tmp/koios_scrp_unit.cs");
   yUNIT_minval ("... check code pointer"             , my.f_code     , my.f_code);
   yUNIT_minstr ("... check main name"                , my.n_main     , "/tmp/koios_scrp_unit.h");
   yUNIT_minval ("... check main pointer"             , my.f_main     , my.f_main);
   yUNIT_mindnoc ();

   yUNIT_mincond ("close the code name");
   yUNIT_minstr ("... check code name"                , my.n_code     , "/tmp/koios_scrp_unit.cs");
   yUNIT_minval ("... check code pointer"             , my.f_code     , my.f_code);
   yUNIT_minstr ("... check main name"                , my.n_main     , "/tmp/koios_scrp_unit.h");
   yUNIT_minval ("... check main pointer"             , my.f_main     , my.f_main);
   yUNIT_minval ("close the script file"              , CODE_close  (my.f_code), 0);
   yUNIT_minstr ("... check code name"                , my.n_code     , "/tmp/koios_scrp_unit.cs");
   yUNIT_minval ("... check code pointer"             , my.f_code     , 0);
   yUNIT_minstr ("... check main name"                , my.n_main     , "/tmp/koios_scrp_unit.h");
   yUNIT_minval ("... check main pointer"             , my.f_main     , my.f_main);
   yUNIT_mindnoc ();

   yUNIT_mincond ("attempt to close twice");
   yUNIT_minstr ("... check code name"                , my.n_code     , "/tmp/koios_scrp_unit.cs");
   yUNIT_minval ("... check code pointer"             , my.f_code     , my.f_code);
   yUNIT_minstr ("... check main name"                , my.n_main     , "/tmp/koios_scrp_unit.h");
   yUNIT_minval ("... check main pointer"             , my.f_main     , my.f_main);
   yUNIT_minval ("close the script file"              , CODE_close  (my.f_code), -999);
   yUNIT_minstr ("... check code name"                , my.n_code     , "/tmp/koios_scrp_unit.cs");
   yUNIT_minval ("... check code pointer"             , my.f_code     , 0);
   yUNIT_minstr ("... check main name"                , my.n_main     , "/tmp/koios_scrp_unit.h");
   yUNIT_minval ("... check main pointer"             , my.f_main     , my.f_main);
   yUNIT_mindnoc ();

   yUNIT_mincond ("close the main name");
   yUNIT_minstr ("... check code name"                , my.n_code     , "/tmp/koios_scrp_unit.cs");
   yUNIT_minval ("... check code pointer"             , my.f_code     , my.f_code);
   yUNIT_minstr ("... check main name"                , my.n_main     , "/tmp/koios_scrp_unit.h");
   yUNIT_minval ("... check main pointer"             , my.f_main     , my.f_main);
   yUNIT_minval ("close the script file"              , CODE_close  (my.f_main), 0);
   yUNIT_minstr ("... check code name"                , my.n_code     , "/tmp/koios_scrp_unit.cs");
   yUNIT_minval ("... check code pointer"             , my.f_code     , 0);
   yUNIT_minstr ("... check main name"                , my.n_main     , "/tmp/koios_scrp_unit.h");
   yUNIT_minval ("... check main pointer"             , my.f_main     , 0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("clean up after");
   system ("rm -f /tmp/koios_scrp_unit.cs   2> /dev/null");
   system ("rm -f /tmp/koios_scrp_unit.h    2> /dev/null");
   system ("rm -f /tmp/koios_scrp.wave      2> /dev/null");
   yUNIT_mindnoc ();

   yUNIT_minprcs ();
   return 0;
}

char
koios__unit_code_ends    (void)
{
   int         c           =    0;

   yUNIT_minscrp ("CODE_beg, CODE_end");
   yURG_err_none ();  /* not to stderr/terminal */

   yUNIT_mincond ("open normally");
   system ("rm -f /tmp/koios.unit         2> /dev/null");
   system ("rm -f /tmp/koios_scrp_unit.cs 2> /dev/null");
   system ("rm -f /tmp/koios_scrp_unit.h  2> /dev/null");
   system ("rm -f /tmp/koios_scrp.wave      2> /dev/null");
   strcpy (my.n_code, "/tmp/koios_scrp_unit.cs");
   strcpy (my.n_main, "/tmp/koios_scrp_unit.h");
   strcpy (my.n_wave, "/tmp/koios_scrp.wave");
   strcpy (my.n_base, "/tmp/koios_scrp");
   yUNIT_minval ("open the script file"               , CODE_open   (), 0);
   yUNIT_minval ("... check code pointer"             , my.f_code     , my.f_code);
   yUNIT_minval ("... check main pointer"             , my.f_main     , my.f_main);
   yUNIT_mindnoc ();

   yUNIT_mincond ("write the beginning of code");
   CODE_cycle ();
   yUNIT_minval ("call beg"                           , CODE_beg    (), 0);
   yUNIT_minstr ("... check code beginning"           , yURG_peek (my.n_code, 'º'), "/*================================= beg-code =================================*/");
   yUNIT_minstr ("... ... shebang"                    , yURG_peek (my.n_code, 'Ö'), "/* /usr/local/bin/koios                                                       */");
   yUNIT_minstr ("... ... title"                      , yURG_peek (my.n_code, 'Ö'), "/*   autogen by koios-polos (axis of heaven) unit testing meta-language       */");
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_code, 'Ö'), "");
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_code, 'Ö'), "/*---(standard support functions)----*/");
   yUNIT_minstr ("... check include header"           , yURG_peek (my.n_code, 'Ö'), "#include    <yUNIT_unit.h>");
   yUNIT_minstr ("... check include header"           , yURG_peek (my.n_code, 'Ö'), "#include    \"master.h\"");
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_code, 'Ö'), "");
   yUNIT_minstr ("... check script comment"           , yURG_peek (my.n_code, 'Ö'), "/*================================ beg-script ================================*/");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) , 9);
   yUNIT_mindnoc ();

   yUNIT_mincond ("write the ending of code");
   CODE_cycle ();
   yUNIT_minval ("call end"                           , CODE_end    (), 0);
   yUNIT_minstr ("... check script comment"           , yURG_peek (my.n_code, 'º'), "/*================================ end-script ================================*/");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) , 1);
   yUNIT_mindnoc ();

   yUNIT_mincond ("write the beginning of main");
   CODE_cycle ();
   yUNIT_minval ("call beg"                           , MAIN_beg    (), 0);
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_main, 'º'), "");
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_main, 'Ö'), "");
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_main, 'Ö'), "");
   yUNIT_minstr ("... check return type"              , yURG_peek (my.n_main, 'Ö'), "int");
   yUNIT_minstr ("... check definition"               , yURG_peek (my.n_main, 'Ö'), "main                    (int a_argc, char *a_argv[])");
   yUNIT_minstr ("... check open brace"               , yURG_peek (my.n_main, 'Ö'), "{");
   yUNIT_minstr ("... check comment"                  , yURG_peek (my.n_main, 'Ö'), "   /*---(locals)-----------+-----+-----+-*/");
   yUNIT_minstr ("... check local"                    , yURG_peek (my.n_main, 'Ö'), "   int         rc          =    0;");
   yUNIT_minstr ("... check comment"                  , yURG_peek (my.n_main, 'Ö'), "   /*---(prepare)------------------------*/");
   yUNIT_minstr ("... check check arguments"          , yURG_peek (my.n_main, 'Ö'), "   rc = yUNIT_init ();");
   yUNIT_minstr ("... check check arguments"          , yURG_peek (my.n_main, 'Ö'), "   rc = yUNIT_args (a_argc, a_argv);");
   yUNIT_minstr ("... check error checking"           , yURG_peek (my.n_main, 'Ö'), "   if (rc < 0)  return -1;");
   yUNIT_minstr ("... check start unit test"          , yURG_peek (my.n_main, 'Ö'), "   yUNIT_unit (\"/tmp/koios_scrp\", cyUNIT.level, cyUNIT.eterm, cyUNIT.exec);");
   yUNIT_minstr ("... check comment"                  , yURG_peek (my.n_main, 'Ö'), "   /*---(beg scripts)--------------------*/");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_main) , 14);
   yUNIT_mindnoc ();

   yUNIT_mincond ("write the ending");
   CODE_cycle ();
   yUNIT_minval ("call end"                           , MAIN_end    (), 0);
   yUNIT_minstr ("... check comment"                  , yURG_peek (my.n_main, 'º'), "   /*---(end scripts)--------------------*/");
   yUNIT_minstr ("... check tinu"                     , yURG_peek (my.n_main, 'Ö'), "   rc = yUNIT_tinu (cyUNIT.exec);");
   yUNIT_minstr ("... check comment"                  , yURG_peek (my.n_main, 'Ö'), "   /*---(complete)-----------------------*/");
   yUNIT_minstr ("... check return"                   , yURG_peek (my.n_main, 'Ö'), "   return rc;");
   yUNIT_minstr ("... check end brace"                , yURG_peek (my.n_main, 'Ö'), "}");
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_main, 'Ö'), "");
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_main, 'Ö'), "");
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_main, 'Ö'), "");
   yUNIT_minstr ("... check (8) whimper"              , yURG_peek (my.n_main, 'Ö'), "/* end-of-file.  done, finito, completare, whimper [Ï´···                     */");
   yUNIT_minstr ("... check (9) final line"           , yURG_peek (my.n_main, 'Ö'), "/*================================= end-code =================================*/");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_main) , 10);
   yUNIT_mindnoc ();

   yUNIT_mincond ("clean up after");
   yUNIT_minval ("close all files"                    , CODE_close  (my.f_code), 0);
   yUNIT_minval ("close all files"                    , CODE_close  (my.f_main), 0);
   system ("rm -f /tmp/koios.unit         2> /dev/null");
   system ("rm -f /tmp/koios_scrp_unit.cs 2> /dev/null");
   system ("rm -f /tmp/koios_scrp_unit.h  2> /dev/null");
   system ("rm -f /tmp/koios_scrp.wave    2> /dev/null");
   yUNIT_mindnoc ();

   yUNIT_minprcs ();
   return 0;
}

char
koios__unit_code_prep    (void)
{
   int         c           =    0;

   yUNIT_minscrp ("CODE_prep, CODE_incl");
   yURG_err_none ();  /* not to stderr/terminal */

   yUNIT_mincond ("open normally");
   system ("rm -f /tmp/koios_scrp.unit    2> /dev/null");
   system ("rm -f /tmp/koios_scrp_unit.cs 2> /dev/null");
   system ("rm -f /tmp/koios_scrp_unit.h  2> /dev/null");
   system ("rm -f /tmp/koios_scrp.wave      2> /dev/null");
   strcpy (my.n_scrp, "/tmp/koios_scrp.unit");
   system ("touch /tmp/koios_scrp.unit");
   strcpy (my.n_wave, "/tmp/koios_scrp.wave");
   yUNIT_minval ("open the script file"               , SCRP_open   (), 0);
   strcpy (my.n_code, "/tmp/koios_scrp_unit.cs");
   strcpy (my.n_main, "/tmp/koios_scrp_unit.h");
   strcpy (my.n_base, "/tmp/koios_scrp");
   yUNIT_minval ("open the script file"               , CODE_open   (), 0);
   yUNIT_minval ("... check code pointer"             , my.f_code     , my.f_code);
   yUNIT_minval ("... check main pointer"             , my.f_main     , my.f_main);
   yUNIT_mindnoc ();

   yUNIT_mincond ("handle the prep");
   strcpy (my.recd, "PREP  include the prototype headers         ");
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "PREP § include the prototype headers §  §  §  §  §");
   yUNIT_minstr ("... check verb"                     , my.verb       , "PREP");
   yUNIT_minstr ("... check stage"                    , my.stage      , "");
   yUNIT_minchr ("... check share"                    , my.share      , '-');
   yUNIT_minchr ("... check mark"                     , my.mark       , '-');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "include the prototype headers");
   yUNIT_minstr ("... check method"                   , my.meth       , "");
   yUNIT_minstr ("... check arguments"                , my.args       , "");
   yUNIT_minstr ("... check test"                     , my.test       , "");
   yUNIT_minstr ("... check expect"                   , my.expe       , "");
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "");
   CODE_cycle ();
   yUNIT_minval ("call prep"                          , CODE_prep   (), 0);
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_code, 'º'), "");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) , 0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("handle an include line");
   strcpy (my.recd, "   incl  include public header  koios.h       ");
   my.n_line = 15;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "   incl § include public header § koios.h §  §  §  §");
   yUNIT_minstr ("... check verb"                     , my.verb       , "incl");
   yUNIT_minstr ("... check stage"                    , my.stage      , "");
   yUNIT_minchr ("... check share"                    , my.share      , '-');
   yUNIT_minchr ("... check mark"                     , my.mark       , '-');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "include public header");
   yUNIT_minstr ("... check method"                   , my.meth       , "koios.h");
   yUNIT_minstr ("... check arguments"                , my.args       , "");
   yUNIT_minstr ("... check test"                     , my.test       , "");
   yUNIT_minstr ("... check expect"                   , my.expe       , "");
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "");
   CODE_cycle ();
   yUNIT_minval ("call incl"                          , CODE_incl   (), 0);
   yUNIT_minstr ("... check include"                  , yURG_peek (my.n_code, 'º'), "#include    \"koios.h\"               /*   15, include public header            */");
   CODE_printf ("#include    ¶%s¶   /* %4i, %s */\n", my.meth, my.n_line, my.desc);
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) , 2);
   yUNIT_mindnoc ();

   yUNIT_mincond ("clean up after");
   yUNIT_minval ("close script"                       , SCRP_close  (), 0);
   yUNIT_minval ("close all files"                    , CODE_close  (my.f_code), 0);
   yUNIT_minval ("close all files"                    , CODE_close  (my.f_main), 0);
   system ("rm -f /tmp/koios.unit         2> /dev/null");
   system ("rm -f /tmp/koios_scrp_unit.cs 2> /dev/null");
   system ("rm -f /tmp/koios_scrp_unit.h  2> /dev/null");
   system ("rm -f /tmp/koios_scrp.wave      2> /dev/null");
   yUNIT_mindnoc ();

   yUNIT_minprcs ();
   return 0;
}

char
koios__unit_code_scrp    (void)
{
   int         c           =    0;

   yUNIT_minscrp ("CODE_scrp, CODE_shared, CODE_sect");
   yURG_err_none ();  /* not to stderr/terminal */

   yUNIT_mincond ("open normally");
   system ("rm -f /tmp/koios_scrp.unit    2> /dev/null");
   system ("rm -f /tmp/koios_scrp_unit.cs 2> /dev/null");
   system ("rm -f /tmp/koios_scrp_unit.h  2> /dev/null");
   strcpy (my.n_scrp, "/tmp/koios_scrp.unit");
   system ("touch /tmp/koios_scrp.unit");
   strcpy (my.n_wave, "/tmp/koios_scrp.wave");
   yUNIT_minval ("open the script file"               , SCRP_open   (), 0);
   strcpy (my.n_code, "/tmp/koios_scrp_unit.cs");
   strcpy (my.n_main, "/tmp/koios_scrp_unit.h");
   strcpy (my.n_base, "/tmp/koios_scrp");
   yUNIT_minval ("open the script file"               , CODE_open   (), 0);
   yUNIT_minval ("... check code pointer"             , my.f_code     , my.f_code);
   yUNIT_minval ("... check main pointer"             , my.f_main     , my.f_main);
   yUNIT_mindnoc ();

   yUNIT_mincond ("first script beginning");
   strcpy (my.recd, "SCRP    [ê3]  (SCRP) verify openning and closing  SCRP_parse     ");
   my.n_line = 23;
   my.nscrp  =  0;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "SCRP    [ê3] § (SCRP) verify openning and closing § SCRP_parse §  §  §");
   yUNIT_minstr ("... check verb"                     , my.verb       , "SCRP");
   yUNIT_minstr ("... check stage"                    , my.stage      , "ê3");
   yUNIT_minchr ("... check share"                    , my.share      , '-');
   yUNIT_minchr ("... check mark"                     , my.mark       , '-');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "(SCRP) verify openning and closing");
   yUNIT_minstr ("... check method"                   , my.meth       , "SCRP_parse");
   yUNIT_minstr ("... check arguments"                , my.args       , "");
   yUNIT_minstr ("... check test"                     , my.test       , "");
   yUNIT_minstr ("... check expect"                   , my.expe       , "");
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "");
   CODE_cycle ();
   yUNIT_minval ("call scrp"                          , CODE_scrp   (), 0);
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_code, 'º'), "");
   yUNIT_minstr ("... check return type"              , yURG_peek (my.n_code, 'Ö'), "char");
   yUNIT_minstr ("... check declaration"              , yURG_peek (my.n_code, 'Ö'), "yUNIT_script_01          (void)");
   yUNIT_minstr ("... check open brace"               , yURG_peek (my.n_code, 'Ö'), "{");
   yUNIT_minstr ("... check comment"                  , yURG_peek (my.n_code, 'Ö'), "   /*===[[ script header ]]========================*/");
   yUNIT_minstr ("... check local"                    , yURG_peek (my.n_code, 'Ö'), "   cyUNIT.offset  = 0;");
   yUNIT_minstr ("... check local"                    , yURG_peek (my.n_code, 'Ö'), "   cyUNIT.origin  = 1;");
   yUNIT_minstr ("... check reset"                    , yURG_peek (my.n_code, 'Ö'), "   yUNIT_mode_reset ();");
   yUNIT_minstr ("... check script header"            , yURG_peek (my.n_code, 'Ö'), "   yUNIT_scrp    (  23,   1, \"ê3\", \"(SCRP) verify openning and closing\", \"SCRP_parse\");");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) ,  9);
   yUNIT_minstr ("check main entry"                   , yURG_peek (my.n_main, 'º'), "   if (cyUNIT.scrp == YUNIT_ALL  || cyUNIT.scrp ==  1)  yUNIT_script_01 ();");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_main) ,  1);
   yUNIT_mindnoc ();

   yUNIT_mincond ("second script beginning");
   strcpy (my.recd, "SCRP    [è5]  (SCRP) whatever comes next       ");
   my.n_line = 52;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "SCRP    [è5] § (SCRP) whatever comes next §  §  §  §");
   yUNIT_minstr ("... check verb"                     , my.verb       , "SCRP");
   yUNIT_minstr ("... check stage"                    , my.stage      , "è5");
   yUNIT_minchr ("... check share"                    , my.share      , '-');
   yUNIT_minchr ("... check mark"                     , my.mark       , '-');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "(SCRP) whatever comes next");
   yUNIT_minstr ("... check method"                   , my.meth       , "");
   yUNIT_minstr ("... check arguments"                , my.args       , "");
   yUNIT_minstr ("... check test"                     , my.test       , "");
   yUNIT_minstr ("... check expect"                   , my.expe       , "");
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "");
   CODE_cycle ();
   yUNIT_minval ("call scrp"                          , CODE_scrp   (), 0);
   yUNIT_minstr ("... check comment"                  , yURG_peek (my.n_code, 'º'), "   /*===[[ script done ]]==========================*/");
   yUNIT_minstr ("... check prcs footer"              , yURG_peek (my.n_code, 'Ö'), "   yUNIT_prcs    (cyUNIT.exec);");
   yUNIT_minstr ("... check comment"                  , yURG_peek (my.n_code, 'Ö'), "   /*---(complete)-----------------------*/");
   yUNIT_minstr ("... check return"                   , yURG_peek (my.n_code, 'Ö'), "   return 0;");
   yUNIT_minstr ("... check closing brace"            , yURG_peek (my.n_code, 'Ö'), "}");
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_code, 'Ö'), "");
   yUNIT_minstr ("... check return type"              , yURG_peek (my.n_code, 'Ö'), "char");
   yUNIT_minstr ("... check declaration"              , yURG_peek (my.n_code, 'Ö'), "yUNIT_script_02          (void)");
   yUNIT_minstr ("... check open brace"               , yURG_peek (my.n_code, 'Ö'), "{");
   yUNIT_minstr ("... check comment"                  , yURG_peek (my.n_code, 'Ö'), "   /*===[[ script header ]]========================*/");
   yUNIT_minstr ("... check local"                    , yURG_peek (my.n_code, 'Ö'), "   cyUNIT.offset  = 0;");
   yUNIT_minstr ("... check local"                    , yURG_peek (my.n_code, 'Ö'), "   cyUNIT.origin  = 2;");
   yUNIT_minstr ("... check reset"                    , yURG_peek (my.n_code, 'Ö'), "   yUNIT_mode_reset ();");
   yUNIT_minstr ("... check script header"            , yURG_peek (my.n_code, 'Ö'), "   yUNIT_scrp    (  52,   2, \"è5\", \"(SCRP) whatever comes next\", \"\");");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) , 14);
   yUNIT_minstr ("check main entry"                   , yURG_peek (my.n_main, 'º'), "   if (cyUNIT.scrp == YUNIT_ALL  || cyUNIT.scrp ==  2)  yUNIT_script_02 ();");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_main) ,  1);
   yUNIT_mindnoc ();

   yUNIT_mincond ("second script beginning");
   strcpy (my.recd, "SHARED   -b-  remove temporary files       ");
   my.n_line = 300;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse the line"                     , SCRP_parse (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "SHARED   -b- § remove temporary files §  §  §  §");
   yUNIT_minstr ("... check verb"                     , my.verb       , "SHARED");
   yUNIT_minstr ("... check stage"                    , my.stage      , "");
   yUNIT_minchr ("... check share"                    , my.share      , 'b');
   yUNIT_minchr ("... check mark"                     , my.mark       , '-');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "remove temporary files");
   yUNIT_minstr ("... check method"                   , my.meth       , "");
   yUNIT_minstr ("... check arguments"                , my.args       , "");
   yUNIT_minstr ("... check test"                     , my.test       , "");
   yUNIT_minstr ("... check expect"                   , my.expe       , "");
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "");
   CODE_cycle ();
   yUNIT_minval ("call shared"                        , CODE_shared (), 0);
   yUNIT_minstr ("... check comment"                  , yURG_peek (my.n_code, 'º'), "   /*===[[ script done ]]==========================*/");
   yUNIT_minstr ("... check prcs footer"              , yURG_peek (my.n_code, 'Ö'), "   yUNIT_prcs    (cyUNIT.exec);");
   yUNIT_minstr ("... check comment"                  , yURG_peek (my.n_code, 'Ö'), "   /*---(complete)-----------------------*/");
   yUNIT_minstr ("... check return"                   , yURG_peek (my.n_code, 'Ö'), "   return 0;");
   yUNIT_minstr ("... check closing brace"            , yURG_peek (my.n_code, 'Ö'), "}");
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_code, 'Ö'), "");
   yUNIT_minstr ("... check return type"              , yURG_peek (my.n_code, 'Ö'), "char");
   yUNIT_minstr ("... check definition"               , yURG_peek (my.n_code, 'Ö'), "yUNIT_shared_b           (void)");
   yUNIT_minstr ("... check openning brace"           , yURG_peek (my.n_code, 'Ö'), "{");
   yUNIT_minstr ("... check comment"                  , yURG_peek (my.n_code, 'Ö'), "   /*===[[ shared header ]]========================*/");
   yUNIT_minstr ("... check call shared"              , yURG_peek (my.n_code, 'Ö'), "   yUNIT_share ('b', \"remove temporary files\");");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) , 11);
   yUNIT_minstr ("check main entry"                   , yURG_peek (my.n_main, 'º'), "");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_main) ,  0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("script after shared");
   strcpy (my.recd, "SCRP    [ÿ2]  (SCRP) last test       ");
   my.n_line = 99;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "SCRP    [ÿ2] § (SCRP) last test §  §  §  §");
   yUNIT_minstr ("... check verb"                     , my.verb       , "SCRP");
   yUNIT_minstr ("... check stage"                    , my.stage      , "ÿ2");
   yUNIT_minchr ("... check share"                    , my.share      , '-');
   yUNIT_minchr ("... check mark"                     , my.mark       , '-');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "(SCRP) last test");
   yUNIT_minstr ("... check method"                   , my.meth       , "");
   yUNIT_minstr ("... check arguments"                , my.args       , "");
   yUNIT_minstr ("... check test"                     , my.test       , "");
   yUNIT_minstr ("... check expect"                   , my.expe       , "");
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "");
   CODE_cycle ();
   yUNIT_minval ("call scrp"                          , CODE_scrp   (), 0);
   yUNIT_minstr ("... check comment"                  , yURG_peek (my.n_code, 'º'), "   /*===[[ shared done ]]==========================*/");
   yUNIT_minstr ("... check prcs footer"              , yURG_peek (my.n_code, 'Ö'), "   yUNIT_erahs ('b');");
   yUNIT_minstr ("... check comment"                  , yURG_peek (my.n_code, 'Ö'), "   /*---(complete)-----------------------*/");
   yUNIT_minstr ("... check return"                   , yURG_peek (my.n_code, 'Ö'), "   return 0;");
   yUNIT_minstr ("... check closing brace"            , yURG_peek (my.n_code, 'Ö'), "}");
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_code, 'Ö'), "");
   yUNIT_minstr ("... check return type"              , yURG_peek (my.n_code, 'Ö'), "char");
   yUNIT_minstr ("... check declaration"              , yURG_peek (my.n_code, 'Ö'), "yUNIT_script_03          (void)");
   yUNIT_minstr ("... check open brace"               , yURG_peek (my.n_code, 'Ö'), "{");
   yUNIT_minstr ("... check comment"                  , yURG_peek (my.n_code, 'Ö'), "   /*===[[ script header ]]========================*/");
   yUNIT_minstr ("... check local"                    , yURG_peek (my.n_code, 'Ö'), "   cyUNIT.offset  = 0;");
   yUNIT_minstr ("... check local"                    , yURG_peek (my.n_code, 'Ö'), "   cyUNIT.origin  = 3;");
   yUNIT_minstr ("... check reset"                    , yURG_peek (my.n_code, 'Ö'), "   yUNIT_mode_reset ();");
   yUNIT_minstr ("... check script header"            , yURG_peek (my.n_code, 'Ö'), "   yUNIT_scrp    (  99,   3, \"ÿ2\", \"(SCRP) last test\", \"\");");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) , 14);
   yUNIT_minstr ("check main entry"                   , yURG_peek (my.n_main, 'º'), "   if (cyUNIT.scrp == YUNIT_ALL  || cyUNIT.scrp ==  3)  yUNIT_script_03 ();");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_main) ,  1);
   yUNIT_mindnoc ();

   yUNIT_mincond ("write a section break");
   strcpy (my.recd, "SECT  file oriented         ");
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse the line"                     , SCRP_parse (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "SECT § file oriented §  §  §  §  §");
   yUNIT_minstr ("... check verb"                     , my.verb       , "SECT");
   yUNIT_minstr ("... check stage"                    , my.stage      , "");
   yUNIT_minchr ("... check share"                    , my.share      , '-');
   yUNIT_minchr ("... check mark"                     , my.mark       , '-');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "file oriented");
   yUNIT_minstr ("... check method"                   , my.meth       , "");
   yUNIT_minstr ("... check arguments"                , my.args       , "");
   yUNIT_minstr ("... check test"                     , my.test       , "");
   yUNIT_minstr ("... check expect"                   , my.expe       , "");
   CODE_cycle ();
   yUNIT_minval ("call section"                       , CODE_sect   (), 0);
   yUNIT_minstr ("... check comment"                  , yURG_peek (my.n_code, 'º'), "   /*===[[ script done ]]==========================*/");
   yUNIT_minstr ("... check prcs footer"              , yURG_peek (my.n_code, 'Ö'), "   yUNIT_prcs    (cyUNIT.exec);");
   yUNIT_minstr ("... check comment"                  , yURG_peek (my.n_code, 'Ö'), "   /*---(complete)-----------------------*/");
   yUNIT_minstr ("... check return"                   , yURG_peek (my.n_code, 'Ö'), "   return 0;");
   yUNIT_minstr ("... check closing brace"            , yURG_peek (my.n_code, 'Ö'), "}");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) ,  5);
   yUNIT_minstr ("... check comment"                  , yURG_peek (my.n_main, 'º'), "   if (cyUNIT.scrp ==  0)                  yUNIT_sect      (\"file oriented\");");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_main) ,  1);

   yUNIT_mincond ("check defaults");
   yUNIT_minval ("... run clear"                      , SCRP__shared_purge ()         , 0);
   yUNIT_minstr ("... check all marks"                , SCRP__shared_used  ()         , "--------------------------   --------------------------   ----------");
   yUNIT_mindnoc ();

   yUNIT_mincond ("attempt some bad shared conditions");
   strcpy (my.recd, "SHARED        remove temporary files       ");
   my.len = strlen (my.recd);
   my.n_line = 300;
   my.run_type = G_RUN_CREATE;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse the line"                     , SCRP_parse (), -999);
   yUNIT_minstr ("... check error message"            , yURG_err_last (), "/tmp/koios_scrp.unit:300:1: error: SHARED missing a valid identifier string -?-");
   strcpy (my.recd, "SHARED -b  testing        ");
   my.len = strlen (my.recd);
   my.n_line = 300;
   my.run_type = G_RUN_CREATE;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a SHARED"                     , SCRP_parse  (), -999);
   yUNIT_minstr ("... check error message"            , yURG_err_last (), "/tmp/koios_scrp.unit:300:1: error: SHARED identifier åbæ not followed by - marker");
   strcpy (my.recd, "SHARED -è-  testing       ");
   my.len = strlen (my.recd);
   my.n_line = 300;
   my.run_type = G_RUN_CREATE;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a SHARED"                     , SCRP_parse  (), -999);
   yUNIT_minstr ("... check error message"            , yURG_err_last (), "/tmp/koios_scrp.unit:300:1: error: SHARED identifier åèæ not valid [a-z]");
   strcpy (my.recd, "SHARE -b-  testing       ");
   my.len = strlen (my.recd);
   my.n_line = 300;
   my.run_type = G_RUN_CREATE;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a SHARED"                     , SCRP_parse  (), -999);
   yUNIT_minstr ("... check error message"            , yURG_err_last (), "/tmp/koios_scrp.unit:300:1: error: verb <SHARE> not recognized/found");
   strcpy (my.recd, "SHAREY -b-  testing       ");
   my.len = strlen (my.recd);
   my.n_line = 300;
   my.run_type = G_RUN_CREATE;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a SHARED"                     , SCRP_parse  (), -999);
   yUNIT_minstr ("... check error message"            , yURG_err_last (), "/tmp/koios_scrp.unit:300:1: error: verb <SHAREY> not recognized/found");
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify some valid variations");
   strcpy (my.recd, "SHARED   -b-  remove temporary files       ");
   my.len = strlen (my.recd);
   my.n_line = 300;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a SHARED"                     , SCRP_parse  (), 0);
   yUNIT_minstr ("... check all marks"                , SCRP__shared_used  ()         , "--------------------------   -b------------------------   ----------");
   yUNIT_minstr ("... check verb"                     , my.verb          , "SHARED");
   strcpy (my.recd, "SHARED -y-  testing       ");
   my.len = strlen (my.recd);
   my.n_line = 300;
   my.run_type = G_RUN_CREATE;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a SHARED"                     , SCRP_parse  (), 0);
   yUNIT_minstr ("... check all marks"                , SCRP__shared_used  ()         , "--------------------------   -b----------------------y-   ----------");
   strcpy (my.recd, "SHARED -a-  testing       ");
   my.n_line = 300;
   my.run_type = G_RUN_CREATE;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a SHARED"                     , SCRP_parse  (), 0);
   yUNIT_minstr ("... check all marks"                , SCRP__shared_used  ()         , "--------------------------   ab----------------------y-   ----------");

   yUNIT_mincond ("attempt some bad scrp verbs");
   strcpy (my.recd, "SCRI          (SCRP) last test       ");
   my.len = strlen (my.recd);
   my.n_line = 99;
   my.run_type = G_RUN_CREATE;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), -999);
   yUNIT_minstr ("... check error message"            , yURG_err_last (), "/tmp/koios_scrp.unit:99:1: error: verb <SCRI> not recognized/found");
   strcpy (my.recd, "SCRIPT  [ÿ2]  (SCRP) last test       ");
   my.n_line = 99;
   my.run_type = G_RUN_CREATE;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), -999);
   yUNIT_minstr ("... check error message"            , yURG_err_last (), "/tmp/koios_scrp.unit:99:1: error: verb <SCRIPT> not recognized/found");
   strcpy (my.recd, "SCRP    [aa]  (SCRP) last test       ");
   my.n_line = 99;
   my.run_type = G_RUN_CREATE;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), -999);
   yUNIT_minstr ("... check error message"            , yURG_err_last (), "/tmp/koios_scrp.unit:99:1: error: SCRP identifier, not greek letter for wave, e.g., [ì4]");
   strcpy (my.recd, "SCRP    [ég]  (SCRP) last test       ");
   my.n_line = 99;
   my.run_type = G_RUN_CREATE;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), -999);
   yUNIT_minstr ("... check error message"            , yURG_err_last (), "/tmp/koios_scrp.unit:99:1: error: SCRP identifier, not number for stage, e.g., [ì4]");
   strcpy (my.recd, "SCRP    (é2)  (SCRP) last test       ");
   my.n_line = 99;
   my.run_type = G_RUN_CREATE;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), -999);
   yUNIT_minstr ("... check error message"            , yURG_err_last (), "/tmp/koios_scrp.unit:99:1: error: SCRP identifier, uses wrong brackets, e.g., [ì4]");
   strcpy (my.recd, "SCRP    -é2   (SCRP) last test       ");
   my.n_line = 99;
   my.run_type = G_RUN_CREATE;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), -999);
   yUNIT_minstr ("... check error message"            , yURG_err_last (), "/tmp/koios_scrp.unit:99:1: error: SCRP identifier, uses wrong brackets, e.g., [ì4]");
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify some valid variations");
   strcpy (my.recd, "SCRP    [--]  (SCRP) last test       ");
   my.n_line = 99;
   my.run_type = G_RUN_CREATE;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), 0);
   yUNIT_mindnoc ();

   strcpy (my.n_base, "master");  /* prepare for SHARED defense testing */

   yUNIT_mincond ("global after script");
   strcpy (my.recd, "GLOBAL   -D-  common setup       ");
   my.n_line = 99;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "GLOBAL   -D- § common setup §  §  §  §");
   yUNIT_minstr ("... check verb"                     , my.verb       , "GLOBAL");
   yUNIT_minstr ("... check stage"                    , my.stage      , "");
   yUNIT_minchr ("... check share"                    , my.share      , 'D');
   yUNIT_minchr ("... check mark"                     , my.mark       , '-');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "common setup");
   yUNIT_minstr ("... check method"                   , my.meth       , "");
   yUNIT_minstr ("... check arguments"                , my.args       , "");
   yUNIT_minstr ("... check test"                     , my.test       , "");
   yUNIT_minstr ("... check expect"                   , my.expe       , "");
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "");
   CODE_cycle ();
   yUNIT_minval ("call global"                        , CODE_global (), 0);
   yUNIT_minstr ("... check comment"                  , yURG_peek (my.n_code, 'º'), "   /*===[[ script done ]]==========================*/");
   yUNIT_minstr ("... check prcs footer"              , yURG_peek (my.n_code, 'Ö'), "   yUNIT_prcs    (cyUNIT.exec);");
   yUNIT_minstr ("... check comment"                  , yURG_peek (my.n_code, 'Ö'), "   /*---(complete)-----------------------*/");
   yUNIT_minstr ("... check return"                   , yURG_peek (my.n_code, 'Ö'), "   return 0;");
   yUNIT_minstr ("... check closing brace"            , yURG_peek (my.n_code, 'Ö'), "}");
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_code, 'Ö'), "");
   yUNIT_minstr ("... check return type"              , yURG_peek (my.n_code, 'Ö'), "char");
   yUNIT_minstr ("... check declaration"              , yURG_peek (my.n_code, 'Ö'), "yUNIT_shared_D           (void)");
   yUNIT_minstr ("... check open brace"               , yURG_peek (my.n_code, 'Ö'), "{");
   yUNIT_minstr ("... check comment"                  , yURG_peek (my.n_code, 'Ö'), "   /*===[[ global header ]]========================*/");
   yUNIT_minstr ("... check  open shared"             , yURG_peek (my.n_code, 'Ö'), "   yUNIT_global ('D', \"common setup\");");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) , 11);
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_main) ,  0);
   yUNIT_mindnoc ();

   strcpy (my.n_base, "koios" );  /* prepare for SHARED testing */
   my.cshare = '-';

   yUNIT_mincond ("clean up after");
   yUNIT_minval ("close script"                       , SCRP_close  (), 0);
   yUNIT_minval ("close all files"                    , CODE_close  (my.f_code), 0);
   yUNIT_minval ("close all files"                    , CODE_close  (my.f_main), 0);
   system ("rm -f /tmp/koios.unit         2> /dev/null");
   system ("rm -f /tmp/koios_scrp_unit.cs 2> /dev/null");
   system ("rm -f /tmp/koios_scrp_unit.h  2> /dev/null");
   system ("rm -f /tmp/koios_scrp.wave      2> /dev/null");
   yUNIT_mindnoc ();

   yUNIT_minprcs ();
   return 0;
}

char
koios__unit_code_cond    (void)
{
   int         c           =    0;

   yUNIT_minscrp ("CODE_cond, CODE_group, CODE_reuse");
   yURG_err_none ();  /* not to stderr/terminal */

   yUNIT_mincond ("open normally");
   system ("rm -f /tmp/koios_scrp.unit    2> /dev/null");
   system ("rm -f /tmp/koios_scrp_unit.cs 2> /dev/null");
   system ("rm -f /tmp/koios_scrp_unit.h  2> /dev/null");
   strcpy (my.n_scrp, "/tmp/koios_scrp.unit");
   system ("touch /tmp/koios_scrp.unit");
   strcpy (my.n_wave, "/tmp/koios_scrp.wave");
   yUNIT_minval ("open the script file"               , SCRP_open   (), 0);
   strcpy (my.n_code, "/tmp/koios_scrp_unit.cs");
   strcpy (my.n_main, "/tmp/koios_scrp_unit.h");
   strcpy (my.n_base, "/tmp/koios_scrp");
   yUNIT_minval ("open the script file"               , CODE_open   (), 0);
   yUNIT_minval ("... check code pointer"             , my.f_code     , my.f_code);
   yUNIT_minval ("... check main pointer"             , my.f_main     , my.f_main);
   yUNIT_mindnoc ();

   yUNIT_mincond ("first condition beginning");
   strcpy (my.recd, "COND (6)  verify defenses       ");
   my.n_line   = 32;
   my.scond    =  0;
   my.run_type = G_RUN_DEBUG;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "COND (6) § verify defenses §  §  §  §");
   yUNIT_minstr ("... check verb"                     , my.verb       , "COND");
   yUNIT_minstr ("... check stage"                    , my.stage      , "");
   yUNIT_minchr ("... check share"                    , my.share      , '-');
   yUNIT_minchr ("... check mark"                     , my.mark       , '6');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "verify defenses");
   yUNIT_minstr ("... check method"                   , my.meth       , "");
   yUNIT_minstr ("... check arguments"                , my.args       , "");
   yUNIT_minstr ("... check test"                     , my.test       , "");
   yUNIT_minstr ("... check expect"                   , my.expe       , "");
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "");
   CODE_cycle ();
   yUNIT_minval ("call cond"                          , CODE_cond   (), 0);
   yUNIT_minstr ("... check code beginning"           , yURG_peek (my.n_code, 'º'), "   /*===[[ COND #001 ]]============================*/");
   yUNIT_minstr ("... check set noise level"          , yURG_peek (my.n_code, 'Ö'), "   if (cyUNIT.cond == cyUNIT.offset +   1)  yUNIT_level (YUNIT_FULL, 'y'); else yUNIT_level (cyUNIT.level, 'y');");
   yUNIT_minstr ("... check debugging"                , yURG_peek (my.n_code, 'Ö'), "   DEBUG_PROG    yLOG_unitcond (cyUNIT.origin, cyUNIT.offset +   1,   32, ¶verify defenses¶);");
   yUNIT_minstr ("... check condition notice"         , yURG_peek (my.n_code, 'Ö'), "   yUNIT_cond    (  32, cyUNIT.offset +   1, '&', \"verify defenses\");");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) ,  4);
   yUNIT_minstr ("check main entry"                   , yURG_peek (my.n_main, 'º'), "");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_main) ,  0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("second condition beginning");
   strcpy (my.recd, "COND  verify null handling       ");
   my.n_line   = 34;
   my.run_type = G_RUN_CREATE;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "COND § verify null handling §  §  §  §");
   yUNIT_minstr ("... check verb"                     , my.verb       , "COND");
   yUNIT_minstr ("... check stage"                    , my.stage      , "");
   yUNIT_minchr ("... check share"                    , my.share      , '-');
   yUNIT_minchr ("... check mark"                     , my.mark       , '-');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "verify null handling");
   yUNIT_minstr ("... check method"                   , my.meth       , "");
   yUNIT_minstr ("... check arguments"                , my.args       , "");
   yUNIT_minstr ("... check test"                     , my.test       , "");
   yUNIT_minstr ("... check expect"                   , my.expe       , "");
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "");
   CODE_cycle ();
   yUNIT_minval ("call cond"                          , CODE_cond   (), 0);
   yUNIT_minstr ("... check final comment"            , yURG_peek (my.n_code, 'º'), "      /*---(summary)---------------------*/");
   yUNIT_minstr ("... check dnoc reporting"           , yURG_peek (my.n_code, 'Ö'), "      yUNIT_dnoc    (cyUNIT.exec);");
   yUNIT_minstr ("... check final comment"            , yURG_peek (my.n_code, 'Ö'), "      /*---(done)------------------------*/");
   yUNIT_minstr ("... check code beginning"           , yURG_peek (my.n_code, 'Ö'), "   /*===[[ COND #002 ]]============================*/");
   yUNIT_minstr ("... check set noise level"          , yURG_peek (my.n_code, 'Ö'), "   if (cyUNIT.cond == cyUNIT.offset +   2)  yUNIT_level (YUNIT_FULL, 'y'); else yUNIT_level (cyUNIT.level, 'y');");
   yUNIT_minstr ("... check condition notice"         , yURG_peek (my.n_code, 'Ö'), "   yUNIT_cond    (  34, cyUNIT.offset +   2, '-', \"verify null handling\");");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) ,  6);
   yUNIT_minstr ("check main entry"                   , yURG_peek (my.n_main, 'º'), "");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_main) ,  0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("condition group");
   strcpy (my.recd, "GROUP  more complex defenses       ");
   my.n_line   = 36;
   my.run_type = G_RUN_CREATE;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "GROUP § more complex defenses §  §  §  §");
   yUNIT_minstr ("... check verb"                     , my.verb       , "GROUP");
   yUNIT_minstr ("... check stage"                    , my.stage      , "");
   yUNIT_minchr ("... check share"                    , my.share      , '-');
   yUNIT_minchr ("... check mark"                     , my.mark       , '-');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "more complex defenses");
   yUNIT_minstr ("... check method"                   , my.meth       , "");
   yUNIT_minstr ("... check arguments"                , my.args       , "");
   yUNIT_minstr ("... check test"                     , my.test       , "");
   yUNIT_minstr ("... check expect"                   , my.expe       , "");
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "");
   CODE_cycle ();
   yUNIT_minval ("call group"                         , CODE_group  (), 0);
   yUNIT_minstr ("... check final comment"            , yURG_peek (my.n_code, 'º'), "      /*---(summary)---------------------*/");
   yUNIT_minstr ("... check dnoc reporting"           , yURG_peek (my.n_code, 'Ö'), "      yUNIT_dnoc    (cyUNIT.exec);");
   yUNIT_minstr ("... check final comment"            , yURG_peek (my.n_code, 'Ö'), "      /*---(done)------------------------*/");
   yUNIT_minstr ("... check comment"                  , yURG_peek (my.n_code, 'Ö'), "   /*---(group)--------------------------*/");
   yUNIT_minstr ("... check group reporting"          , yURG_peek (my.n_code, 'Ö'), "   yUNIT_group   (\"more complex defenses\");");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) ,  5);
   yUNIT_minstr ("check main entry"                   , yURG_peek (my.n_main, 'º'), "");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_main) ,  0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("condition reuse");
   strcpy (my.recd, "REUSE -b-         ");
   my.n_line   = 38;
   my.run_type = G_RUN_CREATE;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "REUSE -b- §  §  §  §  §");
   yUNIT_minstr ("... check verb"                     , my.verb       , "REUSE");
   yUNIT_minstr ("... check stage"                    , my.stage      , "");
   yUNIT_minchr ("... check share"                    , my.share      , 'b');
   yUNIT_minchr ("... check mark"                     , my.mark       , '-');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "");
   yUNIT_minstr ("... check method"                   , my.meth       , "");
   yUNIT_minstr ("... check arguments"                , my.args       , "");
   yUNIT_minstr ("... check test"                     , my.test       , "");
   yUNIT_minstr ("... check expect"                   , my.expe       , "");
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "");
   CODE_cycle ();
   yUNIT_minval ("call reuse"                         , CODE_reuse  (), 0);
   yUNIT_minstr ("... check comment"                  , yURG_peek (my.n_code, 'º'), "   /*---(shared code)-----------------------*/");
   yUNIT_minstr ("... check prepare offset"           , yURG_peek (my.n_code, 'Ö'), "   cyUNIT.offset =   2;");
   yUNIT_minstr ("... check call share"               , yURG_peek (my.n_code, 'Ö'), "   yUNIT_shared_b ();");
   yUNIT_minstr ("... check reset offset"             , yURG_peek (my.n_code, 'Ö'), "   cyUNIT.offset = 0;");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) ,  4);
   yUNIT_minstr ("check main entry"                   , yURG_peek (my.n_main, 'º'), "");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_main) ,  0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("attempt some bad reuse conditions");
   strcpy (my.recd, "REUSE             ");
   my.n_line   = 38;
   my.run_type = G_RUN_CREATE;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a REUSE"                      , SCRP_parse  (), -999);
   yUNIT_minstr ("... check error message"            , yURG_err_last (), "/tmp/koios_scrp.unit:38:1: error: REUSE missing a valid identifier string -?-");
   strcpy (my.recd, "REUSE -b          ");
   my.n_line   = 38;
   my.run_type = G_RUN_CREATE;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a REUSE"                      , SCRP_parse  (), -999);
   yUNIT_minstr ("... check error message"            , yURG_err_last (), "/tmp/koios_scrp.unit:38:1: error: REUSE identifier åbæ not followed by - marker");
   strcpy (my.recd, "REUSE -è-         ");
   my.n_line   = 38;
   my.run_type = G_RUN_CREATE;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a REUSE"                      , SCRP_parse  (), -999);
   yUNIT_minstr ("... check error message"            , yURG_err_last (), "/tmp/koios_scrp.unit:38:1: error: REUSE identifier åèæ not valid [a-zA-Z]");
   strcpy (my.recd, "REUSED -b-         ");
   my.n_line   = 38;
   my.run_type = G_RUN_CREATE;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a REUSE"                      , SCRP_parse  (), -999);
   yUNIT_minstr ("... check error message"            , yURG_err_last (), "/tmp/koios_scrp.unit:38:1: error: verb <REUSED> not recognized/found");
   strcpy (my.recd, "REUS   -b-         ");
   my.n_line   = 38;
   my.run_type = G_RUN_CREATE;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a REUSE"                      , SCRP_parse  (), -999);
   yUNIT_minstr ("... check error message"            , yURG_err_last (), "/tmp/koios_scrp.unit:38:1: error: verb <REUS> not recognized/found");
   yUNIT_mindnoc ();

   yUNIT_mincond ("clean up after");
   yUNIT_minval ("close script"                       , SCRP_close  (), 0);
   yUNIT_minval ("close all files"                    , CODE_close  (my.f_code), 0);
   yUNIT_minval ("close all files"                    , CODE_close  (my.f_main), 0);
   system ("rm -f /tmp/koios.unit         2> /dev/null");
   system ("rm -f /tmp/koios_scrp_unit.cs 2> /dev/null");
   system ("rm -f /tmp/koios_scrp_unit.h  2> /dev/null");
   system ("rm -f /tmp/koios_scrp.wave      2> /dev/null");
   yUNIT_mindnoc ();

   yUNIT_minprcs ();
   return 0;
}

char
koios__unit_code_step    (void)
{
   int         c           =    0;

   yUNIT_minscrp ("CODE_mode, CODE_load, CODE_system, CODE_echo, CODE_exec");
   yURG_err_none ();  /* not to stderr/terminal */

   yUNIT_mincond ("open normally");
   system ("rm -f /tmp/koios_scrp.unit    2> /dev/null");
   system ("rm -f /tmp/koios_scrp_unit.cs 2> /dev/null");
   system ("rm -f /tmp/koios_scrp_unit.h  2> /dev/null");
   strcpy (my.n_scrp, "/tmp/koios_scrp.unit");
   system ("touch /tmp/koios_scrp.unit");
   strcpy (my.n_wave, "/tmp/koios_scrp.wave");
   yUNIT_minval ("open the script file"               , SCRP_open   (), 0);
   strcpy (my.n_code, "/tmp/koios_scrp_unit.cs");
   strcpy (my.n_main, "/tmp/koios_scrp_unit.h");
   strcpy (my.n_base, "/tmp/koios_scrp");
   yUNIT_minval ("open the script file"               , CODE_open   (), 0);
   yUNIT_minval ("... check code pointer"             , my.f_code     , my.f_code);
   yUNIT_minval ("... check main pointer"             , my.f_main     , my.f_main);
   yUNIT_mindnoc ();

   yUNIT_mincond ("mode step");
   strcpy (my.recd, "mode  FORCED_FAIL       ");
   my.n_line   = 40;
   my.cstep    =  2;
   my.run_type = G_RUN_DEBUG;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "mode § FORCED_FAIL §  §  §  §");
   yUNIT_minstr ("... check verb"                     , my.verb       , "mode");
   yUNIT_minstr ("... check stage"                    , my.stage      , "");
   yUNIT_minchr ("... check share"                    , my.share      , '-');
   yUNIT_minchr ("... check mark"                     , my.mark       , '-');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "FORCED_FAIL");
   yUNIT_minstr ("... check method"                   , my.meth       , "");
   yUNIT_minstr ("... check arguments"                , my.args       , "");
   yUNIT_minstr ("... check test"                     , my.test       , "");
   yUNIT_minstr ("... check expect"                   , my.expe       , "");
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "");
   CODE_cycle ();
   yUNIT_minval ("call cond"                          , CODE_mode   (), 0);
   yUNIT_minstr ("... check code beginning"           , yURG_peek (my.n_code, 'º'), "      /*---(mode)------------------------*/");
   yUNIT_minstr ("... check set mode"                 , yURG_peek (my.n_code, 'Ö'), "      yUNIT_mode    (  40,   3, \"FORCED_FAIL\", cyUNIT.exec);");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) ,  2);
   yUNIT_minstr ("check main entry"                   , yURG_peek (my.n_main, 'º'), "");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_main) ,  0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("code step");
   strcpy (my.recd, "local  working variables    int a = 37;  ");
   my.n_line   = 40;
   my.cstep    =  2;
   my.run_type = G_RUN_DEBUG;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "local § working variables §  § int a = 37;  §");
   yUNIT_minstr ("... check verb"                     , my.verb       , "local");
   yUNIT_minstr ("... check stage"                    , my.stage      , "");
   yUNIT_minchr ("... check share"                    , my.share      , '-');
   yUNIT_minchr ("... check mark"                     , my.mark       , '-');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "working variables");
   yUNIT_minstr ("... check method"                   , my.meth       , "");
   yUNIT_minstr ("... check arguments"                , my.args       , "");
   yUNIT_minstr ("... check test"                     , my.test       , "");
   yUNIT_minstr ("... check expect"                   , my.expe       , "");
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "int a = 37;");
   CODE_cycle ();
   yUNIT_minval ("call cond"                          , CODE_lvar   (), 0);
   yUNIT_minstr ("... check code beginning"           , yURG_peek (my.n_code, 'º'), "      /*---(setup local)-----------------*/");
   yUNIT_minstr ("... check show command"             , yURG_peek (my.n_code, 'Ö'), "      int a = 37;");
   yUNIT_minstr ("... check execute code"             , yURG_peek (my.n_code, 'Ö'), "      yUNIT_local   (  40,   3, \"working variables\", \"int a = 37;\", cyUNIT.exec);");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) ,  3);
   yUNIT_minstr ("check main entry"                   , yURG_peek (my.n_main, 'º'), "");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_main) ,  0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("load step");
   strcpy (my.recd, "load  fill out screen  stdin  hello;  15.6 ");
   my.n_line   = 40;
   my.cstep    =  2;
   my.run_type = G_RUN_DEBUG;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "load § fill out screen § stdin § hello;  15.6 §");
   yUNIT_minstr ("... check verb"                     , my.verb       , "load");
   yUNIT_minstr ("... check stage"                    , my.stage      , "");
   yUNIT_minchr ("... check share"                    , my.share      , '-');
   yUNIT_minchr ("... check mark"                     , my.mark       , '-');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "fill out screen");
   yUNIT_minstr ("... check method"                   , my.meth       , "stdin");
   yUNIT_minstr ("... check arguments"                , my.args       , "");
   yUNIT_minstr ("... check test"                     , my.test       , "");
   yUNIT_minstr ("... check expect"                   , my.expe       , "");
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "hello;  15.6");
   CODE_cycle ();
   yUNIT_minval ("call cond"                          , CODE_load   (), 0);
   yUNIT_minstr ("... check code beginning"           , yURG_peek (my.n_code, 'º'), "      /*---(load input)------------------*/");
   yUNIT_minstr ("... check report and execute"       , yURG_peek (my.n_code, 'Ö'), "      yUNIT_load    (  40,   3, \"fill out screen\", \"stdin\", \"hello;  15.6\", cyUNIT.exec);");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) ,  2);
   yUNIT_minstr ("check main entry"                   , yURG_peek (my.n_main, 'º'), "");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_main) ,  0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("system step");
   strcpy (my.recd, "system  delete temporary file    rm -f /tmp/koios_unit.cs ");
   my.n_line   = 40;
   my.cstep    =  2;
   my.run_type = G_RUN_DEBUG;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "system § delete temporary file §  § rm -f /tmp/koios_unit.cs §");
   yUNIT_minstr ("... check verb"                     , my.verb       , "system");
   yUNIT_minstr ("... check stage"                    , my.stage      , "");
   yUNIT_minchr ("... check share"                    , my.share      , '-');
   yUNIT_minchr ("... check mark"                     , my.mark       , '-');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "delete temporary file");
   yUNIT_minstr ("... check method"                   , my.meth       , "");
   yUNIT_minstr ("... check arguments"                , my.args       , "");
   yUNIT_minstr ("... check test"                     , my.test       , "");
   yUNIT_minstr ("... check expect"                   , my.expe       , "");
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "rm -f /tmp/koios_unit.cs");
   CODE_cycle ();
   yUNIT_minval ("call cond"                          , CODE_system (), 0);
   yUNIT_minstr ("... check code beginning"           , yURG_peek (my.n_code, 'º'), "      /*---(system/execute)--------------*/");
   yUNIT_minstr ("... check execute and report"       , yURG_peek (my.n_code, 'Ö'), "      yUNIT_system  (  40,   3, \"delete temporary file\", \"rm -f /tmp/koios_unit.cs\", \"rm -f /tmp/koios_unit.cs\", cyUNIT.exec);");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) ,  2);
   yUNIT_minstr ("check main entry"                   , yURG_peek (my.n_main, 'º'), "");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_main) ,  0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("echo step (real)");
   strcpy (my.recd, "echo  check length    l  r_equal  13.6 ");
   my.n_line   = 40;
   my.cstep    =  2;
   my.run_type = G_RUN_DEBUG;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "echo § check length §  § l § r_equal § 13.6 §");
   yUNIT_minstr ("... check verb"                     , my.verb       , "echo");
   yUNIT_minstr ("... check stage"                    , my.stage      , "");
   yUNIT_minchr ("... check share"                    , my.share      , '-');
   yUNIT_minchr ("... check mark"                     , my.mark       , '-');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "check length");
   yUNIT_minstr ("... check method"                   , my.meth       , "");
   yUNIT_minstr ("... check arguments"                , my.args       , "l");
   yUNIT_minstr ("... check test"                     , my.test       , "r_equal");
   yUNIT_minstr ("... check expect"                   , my.expe       , "13.6");
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "l");
   CODE_cycle ();
   yUNIT_minval ("call cond"                          , CODE_echo   (), 0);
   yUNIT_minstr ("... check code beginning"           , yURG_peek (my.n_code, 'º'), "      /*---(echo/verify)-----------------*/");
   yUNIT_minstr ("... check report"                   , yURG_peek (my.n_code, 'Ö'), "      yUNIT_real    (  40,   3, \"check length\", \"echo\", \"l\", \"r_equal\", 13.6, l, cyUNIT.exec);");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) ,  2);
   yUNIT_minstr ("check main entry"                   , yURG_peek (my.n_main, 'º'), "");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_main) ,  0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("echo step (int)");
   strcpy (my.recd, "echo  check length    l  i_lesser  13.6 ");
   my.n_line   = 40;
   my.cstep    =  2;
   my.run_type = G_RUN_DEBUG;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "echo § check length §  § l § i_lesser § 13.6 §");
   yUNIT_minstr ("... check verb"                     , my.verb       , "echo");
   yUNIT_minstr ("... check stage"                    , my.stage      , "");
   yUNIT_minchr ("... check share"                    , my.share      , '-');
   yUNIT_minchr ("... check mark"                     , my.mark       , '-');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "check length");
   yUNIT_minstr ("... check method"                   , my.meth       , "");
   yUNIT_minstr ("... check arguments"                , my.args       , "l");
   yUNIT_minstr ("... check test"                     , my.test       , "i_lesser");
   yUNIT_minstr ("... check expect"                   , my.expe       , "13.6");
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "l");
   CODE_cycle ();
   yUNIT_minval ("call cond"                          , CODE_echo   (), 0);
   yUNIT_minstr ("... check code beginning"           , yURG_peek (my.n_code, 'º'), "      /*---(echo/verify)-----------------*/");
   yUNIT_minstr ("... check execute and report"       , yURG_peek (my.n_code, 'Ö'), "      yUNIT_int     (  40,   3, \"check length\", \"echo\", \"l\", \"i_lesser\", 13.6, l, cyUNIT.exec);");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) ,  2);
   yUNIT_minstr ("check main entry"                   , yURG_peek (my.n_main, 'º'), "");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_main) ,  0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("echo step (string)");
   strcpy (my.recd, "echo  check length    l  s_not  13.6 ");
   my.n_line   = 40;
   my.cstep    =  2;
   my.run_type = G_RUN_DEBUG;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "echo § check length §  § l § s_not § 13.6 §");
   yUNIT_minstr ("... check verb"                     , my.verb       , "echo");
   yUNIT_minstr ("... check stage"                    , my.stage      , "");
   yUNIT_minchr ("... check share"                    , my.share      , '-');
   yUNIT_minchr ("... check mark"                     , my.mark       , '-');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "check length");
   yUNIT_minstr ("... check method"                   , my.meth       , "");
   yUNIT_minstr ("... check arguments"                , my.args       , "l");
   yUNIT_minstr ("... check test"                     , my.test       , "s_not");
   yUNIT_minstr ("... check expect"                   , my.expe       , "13.6");
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "l");
   CODE_cycle ();
   yUNIT_minval ("call cond"                          , CODE_echo   (), 0);
   yUNIT_minstr ("... check code beginning"           , yURG_peek (my.n_code, 'º'), "      /*---(echo/verify)-----------------*/");
   yUNIT_minstr ("... check execute and report"       , yURG_peek (my.n_code, 'Ö'), "      yUNIT_string  (  40,   3, \"check length\", \"echo\", \"l\", \"s_not\", \"13.6\", l, cyUNIT.exec);");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) ,  2);
   yUNIT_minstr ("check main entry"                   , yURG_peek (my.n_main, 'º'), "");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_main) ,  0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("echo step (pointer)");
   strcpy (my.recd, "echo  check length    l  p_null  13.6 ");
   my.n_line   = 40;
   my.cstep    =  2;
   my.run_type = G_RUN_DEBUG;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "echo § check length §  § l § p_null § 13.6 §");
   yUNIT_minstr ("... check verb"                     , my.verb       , "echo");
   yUNIT_minstr ("... check stage"                    , my.stage      , "");
   yUNIT_minchr ("... check share"                    , my.share      , '-');
   yUNIT_minchr ("... check mark"                     , my.mark       , '-');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "check length");
   yUNIT_minstr ("... check method"                   , my.meth       , "");
   yUNIT_minstr ("... check arguments"                , my.args       , "l");
   yUNIT_minstr ("... check test"                     , my.test       , "p_null");
   yUNIT_minstr ("... check expect"                   , my.expe       , "13.6");
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "l");
   CODE_cycle ();
   yUNIT_minval ("call cond"                          , CODE_echo   (), 0);
   yUNIT_minstr ("... check code beginning"           , yURG_peek (my.n_code, 'º'), "      /*---(echo/verify)-----------------*/");
   yUNIT_minstr ("... check execute and report"       , yURG_peek (my.n_code, 'Ö'), "      yUNIT_point   (  40,   3, \"check length\", \"echo\", \"l\", \"p_null\", 13.6, l, cyUNIT.exec);");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) ,  2);
   yUNIT_minstr ("check main entry"                   , yURG_peek (my.n_main, 'º'), "");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_main) ,  0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("echo step (round)");
   strcpy (my.recd, "echo  check length    l  u_round/3  13.6 ");
   my.n_line   = 40;
   my.cstep    =  2;
   my.run_type = G_RUN_DEBUG;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "echo § check length §  § l § u_round/3 § 13.6 §");
   yUNIT_minstr ("... check verb"                     , my.verb       , "echo");
   yUNIT_minstr ("... check stage"                    , my.stage      , "");
   yUNIT_minchr ("... check share"                    , my.share      , '-');
   yUNIT_minchr ("... check mark"                     , my.mark       , '-');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "check length");
   yUNIT_minstr ("... check method"                   , my.meth       , "");
   yUNIT_minstr ("... check arguments"                , my.args       , "l");
   yUNIT_minstr ("... check test"                     , my.test       , "u_round/3");
   yUNIT_minstr ("... check expect"                   , my.expe       , "13.6");
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "l");
   CODE_cycle ();
   yUNIT_minval ("call cond"                          , CODE_echo   (), 0);
   yUNIT_minstr ("... check code beginning"           , yURG_peek (my.n_code, 'º'), "      /*---(echo/verify)-----------------*/");
   yUNIT_minstr ("... check execute and report"       , yURG_peek (my.n_code, 'Ö'), "      yUNIT_round   (  40,   3, \"check length\", \"echo\", \"l\", \"u_round/3\", \"13.6\", l, cyUNIT.exec);");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) ,  2);
   yUNIT_minstr ("check main entry"                   , yURG_peek (my.n_main, 'º'), "");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_main) ,  0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("exec step");
   strcpy (my.recd, "exec  check length  test_func  27, 36  s_equal  13.6 ");
   my.n_line   = 40;
   my.cstep    =  2;
   my.run_type = G_RUN_DEBUG;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "exec § check length § test_func § 27, 36 § s_equal § 13.6 §");
   yUNIT_minstr ("... check verb"                     , my.verb       , "exec");
   yUNIT_minstr ("... check stage"                    , my.stage      , "");
   yUNIT_minchr ("... check share"                    , my.share      , '-');
   yUNIT_minchr ("... check mark"                     , my.mark       , '-');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "check length");
   yUNIT_minstr ("... check method"                   , my.meth       , "test_func");
   yUNIT_minstr ("... check arguments"                , my.args       , "27, 36");
   yUNIT_minstr ("... check test"                     , my.test       , "s_equal");
   yUNIT_minstr ("... check expect"                   , my.expe       , "13.6");
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "27, 36");
   CODE_cycle ();
   yUNIT_minval ("call cond"                          , CODE_exec   (), 0);
   yUNIT_minstr ("... check code beginning"           , yURG_peek (my.n_code, 'º'), "      /*---(run step)--------------------*/");
   yUNIT_minstr ("... check debugging"                , yURG_peek (my.n_code, 'Ö'), "      DEBUG_PROG    yLOG_unitstep (cyUNIT.origin, cyUNIT.offset +   2,   3,   40, ¶check length¶);");
   yUNIT_minstr ("... check reset rcs"                , yURG_peek (my.n_code, 'Ö'), "      yUNIT_reset_rc ();");
   yUNIT_minstr ("... check execute"                  , yURG_peek (my.n_code, 'Ö'), "      if (cyUNIT.exec)  cyUNIT.s_rc = test_func (27, 36);");
   yUNIT_minstr ("... check report"                   , yURG_peek (my.n_code, 'Ö'), "      yUNIT_string  (  40,   3, \"check length\", \"test_func\", \"27, 36\", \"s_equal\", \"13.6\", cyUNIT.s_rc, cyUNIT.exec);");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) ,  5);
   yUNIT_minstr ("check main entry"                   , yURG_peek (my.n_main, 'º'), "");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_main) ,  0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("get step");
   strcpy (my.recd, "get  ... verify length  test_unit  27, 36  i_equal  13.6 ");
   my.n_line   = 40;
   my.cstep    =  2;
   my.run_type = G_RUN_DEBUG;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "get § ... verify length § test_unit § 27, 36 § i_equal § 13.6 §");
   yUNIT_minstr ("... check verb"                     , my.verb       , "get");
   yUNIT_minstr ("... check stage"                    , my.stage      , "");
   yUNIT_minchr ("... check share"                    , my.share      , '-');
   yUNIT_minchr ("... check mark"                     , my.mark       , '-');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "... verify length");
   yUNIT_minstr ("... check method"                   , my.meth       , "test_unit");
   yUNIT_minstr ("... check arguments"                , my.args       , "27, 36");
   yUNIT_minstr ("... check test"                     , my.test       , "i_equal");
   yUNIT_minstr ("... check expect"                   , my.expe       , "13.6");
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "27, 36");
   CODE_cycle ();
   yUNIT_minval ("call cond"                          , CODE_exec   (), 0);
   yUNIT_minstr ("... check code beginning"           , yURG_peek (my.n_code, 'º'), "      /*---(run step)--------------------*/");
   yUNIT_minstr ("... check debugging"                , yURG_peek (my.n_code, 'Ö'), "      DEBUG_PROG    yLOG_unitstep (cyUNIT.origin, cyUNIT.offset +   2,   3,   40, ¶... verify length¶);");
   yUNIT_minstr ("... check reset"                    , yURG_peek (my.n_code, 'Ö'), "      yUNIT_reset_rc ();");
   yUNIT_minstr ("... check execute"                  , yURG_peek (my.n_code, 'Ö'), "      if (cyUNIT.exec)  cyUNIT.i_rc = test_unit (27, 36);");
   yUNIT_minstr ("... check results"                  , yURG_peek (my.n_code, 'Ö'), "      yUNIT_int     (  40,   3, \"... verify length\", \"test_unit\", \"27, 36\", \"i_equal\", 13.6, cyUNIT.i_rc, cyUNIT.exec);");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) ,  5);
   yUNIT_minstr ("check main entry"                   , yURG_peek (my.n_main, 'º'), "");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_main) ,  0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("clean up after");
   yUNIT_minval ("close script"                       , SCRP_close  (), 0);
   yUNIT_minval ("close all files"                    , CODE_close  (my.f_code), 0);
   yUNIT_minval ("close all files"                    , CODE_close  (my.f_main), 0);
   system ("rm -f /tmp/koios.unit         2> /dev/null");
   system ("rm -f /tmp/koios_scrp_unit.cs 2> /dev/null");
   system ("rm -f /tmp/koios_scrp_unit.h  2> /dev/null");
   system ("rm -f /tmp/koios_scrp.wave      2> /dev/null");
   yUNIT_mindnoc ();

   yUNIT_minprcs ();
   return 0;
}



/*====================------------------------------------====================*/
/*===----                    actual runtime testing                    ----===*/
/*====================------------------------------------====================*/
static void      o___LIVE____________________o (void) {;}

char
koios__unit_shared_data  (void)
{

   yUNIT_minscrp ("run-time testing");
   yURG_err_none ();  /* not to stderr/terminal */

   yUNIT_mincond ("check defaults");
   yUNIT_minval ("... run clear"                      , SCRP__shared_purge ()         , 0);
   yUNIT_minstr ("... check all marks"                , SCRP__shared_used  ()         , "--------------------------   --------------------------   ----------");
   yUNIT_mindnoc ();

   yUNIT_mincond ("prepare a master example");
   system ("rm -f koios.unit 2> /dev/null");
   system ("echo \"#23456789-12  123456789-123456789-123456789-12345  123456789-123456  123456789-123456789-  123456789-  123456789-123456789-  123456789- \"   > master.unit");
   system ("echo \"#==(verb)===  ===========(description)===========  =====(function)=  ====(arguments)=====  ==(test)==  ====(results)=======  =(var)==== \"  >> master.unit");
   system ("echo \"PREP          global function headers             \"                                                                                                       >> master.unit");
   system ("echo \"  incl        fake header                          koios.h           \"                                                                                    >> master.unit");
   system ("echo \"  global      global variable                      - - - - - - - -   int h = 0;                                                        \"              >> master.unit");
   system ("echo \"GLOBAL   -D-  globally shared steps               \"                                                                                                       >> master.unit");
   system ("echo \"  COND        prepare variables                   \"                                                                                                       >> master.unit");
   system ("echo \"    code      ... set new value                    - - - - - - - -   h = 32 * 64;                                                    \"                >> master.unit");
   system ("echo \"  COND        generate a summary                  \"                                                                                                       >> master.unit");
   system ("echo \"    exec      ... check string                     yUNIT_teststring  0                         s_equal     hello                 \"                >> master.unit");
   system ("echo \"    exec      ... check number                     yUNIT_testreal    5                         r_greater   15.0                  \"                >> master.unit");
   system ("echo \"    exec      ... check integer                    yUNIT_testint     32                        i_equal     2                     \"                >> master.unit");
   yUNIT_mindnoc ();

   yUNIT_mincond ("turn into a master header");
   yUNIT_minval  ("... run koios"                      , system ("koios --create master"), 999);
   yUNIT_mindnoc ();

   yUNIT_mincond ("prepare a interesting example");
   system ("rm -f koios.unit 2> /dev/null");
   system ("echo \"#23456789-12  123456789-123456789-123456789-12345  123456789-123456  123456789-123456789-  123456789-  123456789-123456789-  123456789- \"   > koios.unit");
   system ("echo \"#==(verb)===  ===========(description)===========  =====(function)=  ====(arguments)=====  ==(test)==  ====(results)=======  =(var)==== \"  >> koios.unit");
   system ("echo \"PREP          global function headers             \"                                                                                                       >> koios.unit");
   system ("echo \"  incl        fake header                          koios.h           \"                                                                                    >> koios.unit");
   system ("echo \"SECT          simple testing                      \"                                                                                                       >> koios.unit");
   system ("echo \"SCRP    [ê1]  (SCRP) verify openning and closing                    \"                                                                                   >> koios.unit");
   system ("echo \"  COND        simple openning                     \"                                                                                                       >> koios.unit");
   system ("echo \"    exec      ... check string                     yUNIT_teststring  0                         s_equal     hello                 \"                >> koios.unit");
   system ("echo \"    exec      ... check number                     yUNIT_testreal    5                         r_greater   15.0                  \"                >> koios.unit");
   system ("echo \"    exec      ... check integer                    yUNIT_testint     32                        i_equal     2                     \"                >> koios.unit");
   system ("echo \"    exec      ... check character                  yUNIT_testchar    65                        i_equal     'A'                   \"                >> koios.unit");
   system ("echo \"  COND   (1)  defensive checks                    \"                                                                                                       >> koios.unit");
   system ("echo \"    load      ... prep data for read               stdin             one two three                                                   \"                >> koios.unit");
   system ("echo \"    get       ... check number                     yUNIT_testreal    5                         r_greater   15.0                  \"                >> koios.unit");
   system ("echo \"    exec      ... check integer                    yUNIT_testint     32                        i_equal     2                     \"                >> koios.unit");
   system ("echo \"    exec      ... check character                  yUNIT_testchar    65                        i_equal     'A'                   \"                >> koios.unit");
   system ("echo \"  DITTO  (1)  - - - - - - - - - - - - - - - - - - \"                                                                                                       >> koios.unit");
   system ("echo \"  COND        small condition                     \"                                                                                                       >> koios.unit");
   system ("echo \"    exec      ... check string                     yUNIT_teststring  0                         s_equal     hello                 \"                >> koios.unit");
   system ("echo \"  DITTO  (1)  - - - - - - - - - - - - - - - - - - \"                                                                                                       >> koios.unit");
   system ("echo \"  COND        duplicate opens and closes          \"                                                                                                       >> koios.unit");
   system ("echo \"    local     ... working variables                - - - - - - - -   int c = 0;                                                      \"                >> koios.unit");
   system ("echo \"    echo      ... check working variable           - - - - - - - -   c                         i_equal     0                     \"                >> koios.unit");
   system ("echo \"    load      ... prep data for read               stdin             one two three                                                   \"                >> koios.unit");
   system ("echo \"    mode      FORCED_FAIL                         \"                                                                                                       >> koios.unit");
   system ("echo \"    system    ... run little                       - - - - - - - -   /bin/false                                                      \"                >> koios.unit");
   system ("echo \"SECT          more complex testing                \"                                                                                                       >> koios.unit");
   system ("echo \"SHARED   -a-  prepare files for use               \"                                                                                                       >> koios.unit");
   system ("echo \"  COND        script input file                   \"                                                                                                       >> koios.unit");
   system ("echo \"    exec      ... check string                     yUNIT_teststring  0                         s_equal     hello                 \"                >> koios.unit");
   system ("echo \"    exec      ... check number                     yUNIT_testreal    5                         r_greater   15.0                  \"                >> koios.unit");
   system ("echo \"    exec      ... check integer                    yUNIT_testint     32                        i_equal     2                     \"                >> koios.unit");
   system ("echo \"    mode      normal                              \"                                                                                                       >> koios.unit");
   system ("echo \"  COND        code output file                    \"                                                                                                       >> koios.unit");
   system ("echo \"    exec      ... check string                     yUNIT_teststring  0                         s_equal     hello                 \"                >> koios.unit");
   system ("echo \"    exec      ... check number                     yUNIT_testreal    5                         r_greater   15.0                  \"                >> koios.unit");
   system ("echo \"    exec      ... check integer                    yUNIT_testint     32                        i_equal     2                     \"                >> koios.unit");
   system ("echo \"    exec      ... check character                  yUNIT_testchar    65                        i_equal     'A'                   \"                >> koios.unit");
   system ("echo \"SHARED   -b-  remove files after use              \"                                                                                                       >> koios.unit");
   system ("echo \"  COND        code output file                    \"                                                                                                       >> koios.unit");
   system ("echo \"    exec      ... check string                     yUNIT_teststring  0                         s_equal     hello                 \"                >> koios.unit");
   system ("echo \"    exec      ... check number                     yUNIT_testreal    5                         r_greater   15.0                  \"                >> koios.unit");
   system ("echo \"    exec      ... check integer                    yUNIT_testint     32                        i_equal     2                     \"                >> koios.unit");
   system ("echo \"    exec      ... check character                  yUNIT_testchar    65                        i_equal     'A'                   \"                >> koios.unit");
   system ("echo \"  COND        close and delete code file          \"                                                                                                       >> koios.unit");
   system ("echo \"    exec      ... check string                     yUNIT_teststring  0                         s_equal     hello                 \"                >> koios.unit");
   system ("echo \"    exec      ... check number                     yUNIT_testreal    5                         r_greater   15.0                  \"                >> koios.unit");
   system ("echo \"    exec      ... check integer                    yUNIT_testint     32                        i_equal     2                     \"                >> koios.unit");
   system ("echo \"    exec      ... check character                  yUNIT_testchar    65                        i_equal     'A'                   \"                >> koios.unit");
   system ("echo \"SCRP    [ê2]  (SCRP) verify system startup                          \"                                                                                   >> koios.unit");
   system ("echo \"  COND        run initialization                  \"                                                                                                       >> koios.unit");
   system ("echo \"    exec      ... check string                     yUNIT_teststring  0                         s_equal     hello                 \"                >> koios.unit");
   system ("echo \"    mode      FORCED_FAIL                         \"                                                                                                       >> koios.unit");
   system ("echo \"    exec      ... check integer                    yUNIT_testint     32                        i_equal     2                     \"                >> koios.unit");
   system ("echo \"    exec      ... check character                  yUNIT_testchar    65                        i_equal     'A'                   \"                >> koios.unit");
   system ("echo \"  REUSE  -a-  - - - - - - - - - - - - - - - - -   \"                                                                                                       >> koios.unit");
   system ("echo \"  COND        parse a code record                 \"                                                                                                       >> koios.unit");
   system ("echo \"    local     ... create string                    - - - - - - - -   char  x_str [100];                                              \"                >> koios.unit");
   system ("echo \"    exec      ... check string                     yUNIT_teststring  0                         s_equal     hello                  x_str  \"        >> koios.unit");
   system ("echo \"    echo      ... verify string                    - - - - - - - -   x_str                     s_equal     hello                 \"                >> koios.unit");
   system ("echo \"    local     ... create number                    - - - - - - - -   float x_real = 0.0;                                             \"                >> koios.unit");
   system ("echo \"    exec      ... check number                     yUNIT_testreal    5                         r_greater   15.0                   x_real \"        >> koios.unit");
   system ("echo \"    echo      ... verify number                    - - - - - - - -   x_real                    r_lesser    16.0                  \"                >> koios.unit");
   system ("echo \"    local     ... create integer                   - - - - - - - -   int   x_int  = 0;                                               \"                >> koios.unit");
   system ("echo \"    exec      ... check integer                    yUNIT_testint     32                        i_equal     2                      x_int  \"        >> koios.unit");
   system ("echo \"    echo      ... verify integer                   - - - - - - - -   x_int                     i_equal     2                     \"                >> koios.unit");
   system ("echo \"    local     ... create character                 - - - - - - - -   char  x_char = 0;                                               \"                >> koios.unit");
   system ("echo \"    exec      ... check character                  yUNIT_testchar    65                        i_equal     'A'                    x_char \"        >> koios.unit");
   system ("echo \"    echo      ... verify character                 - - - - - - - -   x_char                    i_equal     'A'                   \"                >> koios.unit");
   system ("echo \"    local     ... create pointer                   - - - - - - - -   int  *x_ptr  = NULL;                                            \"                >> koios.unit");
   system ("echo \"    exec      ... check pointer                    yUNIT_testptr                               p_exists    0                      x_ptr  \"        >> koios.unit");
   system ("echo \"    echo      ... verify pointer                   - - - - - - - -   x_ptr                     p_exists    0                     \"                >> koios.unit");
   system ("echo \"    echo      ... verify value at pointer          - - - - - - - -   (x_ptr) ? *x_ptr : 0      i_equal     42                    \"                >> koios.unit");
   system ("echo \"SCRP    [ì2]  (SCRP) verify normal processing                       \"                                                                                   >> koios.unit");
   system ("echo \"  GROUP       round one                           \"                                                                                                       >> koios.unit");
   system ("echo \"  COND   (1)  process arguments                   \"                                                                                                       >> koios.unit");
   system ("echo \"    exec      ... check string                     yUNIT_teststring  0                         s_equal     hello                 \"                >> koios.unit");
   system ("echo \"    exec      ... check number                     yUNIT_testreal    5                         r_greater   15.0                  \"                >> koios.unit");
   system ("echo \"    exec      ... check integer                    yUNIT_testint     32                        i_equal     2                     \"                >> koios.unit");
   system ("echo \"    exec      ... check character                  yUNIT_testchar    65                        i_equal     'A'                   \"                >> koios.unit");
   system ("echo \"  REUSE  -a-  - - - - - - - - - - - - - - - - -   \"                                                                                                       >> koios.unit");
   system ("echo \"  COND   (2)  read one record                     \"                                                                                                       >> koios.unit");
   system ("echo \"    exec      ... check string                     yUNIT_teststring  1                         s_equal     hello                 \"                >> koios.unit");
   system ("echo \"    exec      ... check number                     yUNIT_testreal    2                         r_greater   15.0                  \"                >> koios.unit");
   system ("echo \"    exec      ... check integer                    yUNIT_testint     64                        i_equal     2                     \"                >> koios.unit");
   system ("echo \"    exec      ... check character                  yUNIT_testchar    87                        i_equal     'A'                   \"                >> koios.unit");
   system ("echo \"  GROUP       round two                           \"                                                                                                       >> koios.unit");
   system ("echo \"  DITTO  (1)  - - - - - - - - - - - - - - - - -   \"                                                                                                       >> koios.unit");
   system ("echo \"  REUSE  -b-  - - - - - - - - - - - - - - - - -   \"                                                                                                       >> koios.unit");
   system ("echo \"  GROUP       final round                         \"                                                                                                       >> koios.unit");
   system ("echo \"  DITTO  (2)  - - - - - - - - - - - - - - - - -   \"                                                                                                       >> koios.unit");
   system ("echo \"  REUSE  -D-  - - - - - - - - - - - - - - - - -   \"                                                                                                       >> koios.unit");
   system ("echo \"  DITTO  (1)  - - - - - - - - - - - - - - - - -   \"                                                                                                       >> koios.unit");
   system ("echo \"SCRP    [è9]  (SCRP) empty script                                   \"                                                                                   >> koios.unit");
   yUNIT_mindnoc ();

   yUNIT_mincond ("turn into a unit test");
   yUNIT_minval  ("... run koios"                      , system ("koios --create koios"), 999);
   yUNIT_minval  ("... copy to c"                      , system ("cp  -f koios_unit.{cs,c}"), 0);
   yUNIT_minval  ("... compile"                        , system ("gcc -c koios_unit.c"), 0);
   yUNIT_minval  ("... link"                           , system ("gcc -o koios_unit koios_unit.o -lyUNIT"), 0);
   yUNIT_mindnoc ();

   yUNIT_minprcs ();

   return 0;
}

char
koios__unit_live_scrp    (void)
{
   int         c           =    0;
   char        x_urun      [LEN_HUND]  = "koios.urun";
   char        x_wave      [LEN_HUND]  = "koios.wave";

   yUNIT_minscrp ("live script-level testing on unit test result");
   yURG_err_none ();  /* not to stderr/terminal */

   koios__unit_shared_data ();

   yUNIT_mincond ("check inventory of scripts");
   yUNIT_minval  ("... run unit test"                  , system ("./koios_unit --scrps"), 0);
   yUNIT_minstr  ("... check unit header"              , yURG_peek (x_urun, 'º'), "yUNIT - heatherly unit testing framework ---------------------------------------(beg)");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check section"                  , yURG_peek (x_urun, 'Ö'), "SECT ===-------------------------- simple testing ---------------------------=== TCES");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check script"                   , yURG_peek (x_urun, 'Ö'), "SCRP [01] (SCRP) verify openning and closing ============================[ê1]=[00006]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check section"                  , yURG_peek (x_urun, 'Ö'), "SECT ===----------------------- more complex testing ------------------------=== TCES");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check script"                   , yURG_peek (x_urun, 'Ö'), "SCRP [02] (SCRP) verify system startup ==================================[ê2]=[00050]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check script"                   , yURG_peek (x_urun, 'Ö'), "SCRP [03] (SCRP) verify normal processing ===============================[ì2]=[00074]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check script"                   , yURG_peek (x_urun, 'Ö'), "SCRP [04] (SCRP) empty script ===========================================[è9]=[00094]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check unit footer"              , yURG_peek (x_urun, 'Ö'), "TINU  scrp=4    cond=21    test=90    [ ------------------------------------------- ]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check unit footer"              , yURG_peek (x_urun, 'Ö'), "yUNIT - heatherly unit testing framework ---------------------------------------(end)");
   yUNIT_minval  ("... check line count"               , yURG_peek_count (x_urun) , 17);
   yUNIT_minstr  ("check wave entry"                   , yURG_peek (x_wave, 'º'), "ê  1  koios                       1  (SCRP) verify openning and closing                                ");
   yUNIT_minstr  ("check wave entry"                   , yURG_peek (x_wave, 'Ö'), "ê  2  koios                       2  (SCRP) verify system startup                                      ");
   yUNIT_minstr  ("check wave entry"                   , yURG_peek (x_wave, 'Ö'), "ì  2  koios                       3  (SCRP) verify normal processing                                   ");
   yUNIT_minstr  ("check wave entry"                   , yURG_peek (x_wave, 'Ö'), "è  9  koios                       4  (SCRP) empty script                                               ");
   yUNIT_minval  ("... check line count"               , yURG_peek_count (x_wave) ,  4);
   yUNIT_mindnoc ();

   yUNIT_mincond ("check inventory of one script only");
   yUNIT_minval  ("... run unit test"                  , system ("./koios_unit --scrps 03"), 0);
   yUNIT_minstr  ("... check unit header"              , yURG_peek (x_urun, 'º'), "yUNIT - heatherly unit testing framework ---------------------------------------(beg)");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check script"                   , yURG_peek (x_urun, 'Ö'), "SCRP [03] (SCRP) verify normal processing ===============================[ì2]=[00074]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check unit footer"              , yURG_peek (x_urun, 'Ö'), "TINU  scrp=1    cond=11    test=40    [ ------------------------------------------- ]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check unit footer"              , yURG_peek (x_urun, 'Ö'), "yUNIT - heatherly unit testing framework ---------------------------------------(end)");
   yUNIT_minval  ("... check line count"               , yURG_peek_count (x_urun) ,  7);
   yUNIT_mindnoc ();

   yUNIT_mincond ("check running and presenting scripts only");
   yUNIT_minval  ("... run unit test"                  , system ("./koios_unit --scrp"), 999);
   yUNIT_minstr  ("... check unit header"              , yURG_peek (x_urun, 'º'), "yUNIT - heatherly unit testing framework ---------------------------------------(beg)");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check section"                  , yURG_peek (x_urun, 'Ö'), "SECT ===-------------------------- simple testing ---------------------------=== TCES");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check script"                   , yURG_peek (x_urun, 'Ö'), "SCRP [01] (SCRP) verify openning and closing ============================[ê1]=[00006]");
   yUNIT_minstr  ("... check script footer"            , yURG_peek (x_urun, 'Ö'), "  " BACK_RED "PRCS -------- cond=6     test=22    [ pass=15    fail=1     badd=0     void=6     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check section"                  , yURG_peek (x_urun, 'Ö'), "SECT ===----------------------- more complex testing ------------------------=== TCES");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check script"                   , yURG_peek (x_urun, 'Ö'), "SCRP [02] (SCRP) verify system startup ==================================[ê2]=[00050]");
   yUNIT_minstr  ("... check script footer"            , yURG_peek (x_urun, 'Ö'), "  " BACK_RED "PRCS -------- cond=4     test=28    [ pass=16    fail=5     badd=0     void=7     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check script"                   , yURG_peek (x_urun, 'Ö'), "SCRP [03] (SCRP) verify normal processing ===============================[ì2]=[00074]");
   yUNIT_minstr  ("... check script footer"            , yURG_peek (x_urun, 'Ö'), "  " BACK_RED "PRCS -------- cond=11    test=40    [ pass=30    fail=8     badd=0     void=2     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check script"                   , yURG_peek (x_urun, 'Ö'), "SCRP [04] (SCRP) empty script ===========================================[è9]=[00094]");
   yUNIT_minstr  ("... check script footer"            , yURG_peek (x_urun, 'Ö'), "  " BACK_YEL "PRCS -------- cond=0     test=0     [ pass=0     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check unit footer"              , yURG_peek (x_urun, 'Ö'), BACK_RED "TINU  scrp=4    cond=21    test=90    [ pass=61    fail=14    badd=0     void=15    ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check unit footer"              , yURG_peek (x_urun, 'Ö'), "yUNIT - heatherly unit testing framework ---------------------------------------(end)");
   yUNIT_minval  ("... check line count"               , yURG_peek_count (x_urun) , 21);
   yUNIT_mindnoc ();

   yUNIT_mincond ("check running and presenting only one script");
   yUNIT_minval  ("... run unit test"                  , system ("./koios_unit --scrp 02"),  999);
   yUNIT_minstr  ("... check unit header"              , yURG_peek (x_urun, 'º'), "yUNIT - heatherly unit testing framework ---------------------------------------(beg)");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check script"                   , yURG_peek (x_urun, 'Ö'), "SCRP [02] (SCRP) verify system startup ==================================[ê2]=[00050]");
   yUNIT_minstr  ("... check script footer"            , yURG_peek (x_urun, 'Ö'), "  " BACK_RED "PRCS -------- cond=4     test=28    [ pass=16    fail=5     badd=0     void=7     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check unit footer"              , yURG_peek (x_urun, 'Ö'), BACK_RED "TINU  scrp=1    cond=4     test=28    [ pass=16    fail=5     badd=0     void=7     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check unit footer"              , yURG_peek (x_urun, 'Ö'), "yUNIT - heatherly unit testing framework ---------------------------------------(end)");
   yUNIT_minval  ("... check line count"               , yURG_peek_count (x_urun) ,  8);
   yUNIT_mindnoc ();

   yUNIT_minprcs ();
   return 0;
}

char
koios__unit_live_cond    (void)
{
   int         c           =    0;
   char        x_urun      [LEN_HUND]  = "koios.urun";

   yUNIT_minscrp ("live cond-level testing on unit test result");
   yURG_err_none ();  /* not to stderr/terminal */

   koios__unit_shared_data ();

   yUNIT_mincond ("check header");
   yUNIT_minval  ("... run unit test"                  , system ("./koios_unit --conds"), 0);
   yUNIT_minstr  ("... check unit header"              , yURG_peek (x_urun, 'º'), "yUNIT - heatherly unit testing framework ---------------------------------------(beg)");
   yUNIT_minstr  ("... ... patron"                     , yURG_peek (x_urun, 'Ö'), "   patron : daktyloi-aeonius (forefinger) automated unit testing                   4s");
   yUNIT_minstr  ("... ... level"                      , yURG_peek (x_urun, 'Ö'), "   assign output level to (3) YUNIT_COND                                          21c");
   yUNIT_minstr  ("... ... eterm"                      , yURG_peek (x_urun, 'Ö'), "   assign format/color to (y) ETERM                                               90x");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check section");
   yUNIT_minstr  ("... check section"                  , yURG_peek (x_urun, 'Ö'), "=========================------------------------------------========================");
   yUNIT_minstr  ("... check section"                  , yURG_peek (x_urun, 'Ö'), "SECT ===-------------------------- simple testing ---------------------------=== TCES");
   yUNIT_minstr  ("... check section"                  , yURG_peek (x_urun, 'Ö'), "=========================------------------------------------========================");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check script one");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check script"                   , yURG_peek (x_urun, 'Ö'), "SCRP [01] (SCRP) verify openning and closing ============================[ê1]=[00006]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, 'Ö'), "  COND [001] simple openning -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00007]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, 'Ö'), "  " BACK_CYN "CCND [002] (1)" BACK_OFF " defensive checks - -- -- -- -- -- -- -- -- -- -- -- -- -- -- [00012]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, 'Ö'), "  " BACK_CYN "DOND [003] (1) defensive checks - -- -- -- -- -- -- -- -- -- -- -- -- -- -- [00017]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, 'Ö'), "  COND [004] small condition -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00018]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, 'Ö'), "  " BACK_CYN "DOND [005] (1) defensive checks - -- -- -- -- -- -- -- -- -- -- -- -- -- -- [00020]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, 'Ö'), "  COND [006] duplicate opens and closes  -- -- -- -- -- -- -- -- -- -- -- -- -[00021]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check script footer"            , yURG_peek (x_urun, 'Ö'), "  PRCS -------- cond=6     test=22    [ ------------------------------------------- ]");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check section");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check section"                  , yURG_peek (x_urun, 'Ö'), "=========================------------------------------------========================");
   yUNIT_minstr  ("... check section"                  , yURG_peek (x_urun, 'Ö'), "SECT ===----------------------- more complex testing ------------------------=== TCES");
   yUNIT_minstr  ("... check section"                  , yURG_peek (x_urun, 'Ö'), "=========================------------------------------------========================");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check script two");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check script"                   , yURG_peek (x_urun, 'Ö'), "SCRP [02] (SCRP) verify system startup ==================================[ê2]=[00050]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, 'Ö'), "  COND [001] run initialization -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00051]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, 'Ö'), "  " BACK_MAG "SOND [002]" BACK_OFF " script input file  -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00029]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, 'Ö'), "  " BACK_MAG "SOND [003]" BACK_OFF " code output file - -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00034]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, 'Ö'), "  COND [004] parse a code record - -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00057]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check script footer"            , yURG_peek (x_urun, 'Ö'), "  PRCS -------- cond=4     test=28    [ ------------------------------------------- ]");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check script three");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check script"                   , yURG_peek (x_urun, 'Ö'), "SCRP [03] (SCRP) verify normal processing ===============================[ì2]=[00074]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check group"                    , yURG_peek (x_urun, 'Ö'), "  GROUP ===----------------------------   round one   ----------------------------===");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, 'Ö'), "  " BACK_CYN "CCND [001] (1)" BACK_OFF " process arguments  -- -- -- -- -- -- -- -- -- -- -- -- -- -- [00076]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, 'Ö'), "  " BACK_MAG "SOND [002]" BACK_OFF " script input file  -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00029]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, 'Ö'), "  " BACK_MAG "SOND [003]" BACK_OFF " code output file - -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00034]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, 'Ö'), "  " BACK_CYN "CCND [004] (2)" BACK_OFF " read one record -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- [00082]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check group"                    , yURG_peek (x_urun, 'Ö'), "  GROUP ===----------------------------   round two   ----------------------------===");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, 'Ö'), "  " BACK_CYN "DOND [005] (1) process arguments  -- -- -- -- -- -- -- -- -- -- -- -- -- -- [00088]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, 'Ö'), "  " BACK_MAG "SOND [006]" BACK_OFF " code output file - -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00040]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, 'Ö'), "  " BACK_MAG "SOND [007]" BACK_OFF " close and delete code file  -- -- -- -- -- -- -- -- -- -- -- -- -[00045]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check group"                    , yURG_peek (x_urun, 'Ö'), "  GROUP ===---------------------------   final round   ---------------------------===");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, 'Ö'), "  " BACK_CYN "DOND [008] (2) read one record -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- [00091]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check (70) global cond"         , yURG_peek (x_urun, 'Ö'), "  " BACK_BLU "GOND [009]" BACK_OFF " prepare variables  -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00007]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check (72) global cond"         , yURG_peek (x_urun, 'Ö'), "  " BACK_BLU "GOND [010]" BACK_OFF " generate a summary -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00009]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, 'Ö'), "  " BACK_CYN "DOND [011] (1) process arguments  -- -- -- -- -- -- -- -- -- -- -- -- -- -- [00093]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check script footer"            , yURG_peek (x_urun, 'Ö'), "  PRCS -------- cond=11    test=40    [ ------------------------------------------- ]");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check script four");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check script"                   , yURG_peek (x_urun, 'Ö'), "SCRP [04] (SCRP) empty script ===========================================[è9]=[00094]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check script footer"            , yURG_peek (x_urun, 'Ö'), "  PRCS -------- cond=0     test=0     [ ------------------------------------------- ]");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check footer");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check unit footer"              , yURG_peek (x_urun, 'Ö'), "TINU  scrp=4    cond=21    test=90    [ ------------------------------------------- ]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check unit footer"              , yURG_peek (x_urun, 'Ö'), "yUNIT - heatherly unit testing framework ---------------------------------------(end)");
   yUNIT_minval  ("... check line count"               , yURG_peek_count (x_urun) , 87);
   yUNIT_mindnoc ();

   yUNIT_mincond ("check displaying conditions for one script");
   yUNIT_minval  ("... run unit test"                  , system ("./koios_unit --conds 02"), 0);
   yUNIT_minstr  ("... check unit header"              , yURG_peek (x_urun, 'º'), "yUNIT - heatherly unit testing framework ---------------------------------------(beg)");
   yUNIT_minstr  ("... ... patron"                     , yURG_peek (x_urun, 'Ö'), "   patron : daktyloi-aeonius (forefinger) automated unit testing                   4s");
   yUNIT_minstr  ("... ... level"                      , yURG_peek (x_urun, 'Ö'), "   assign output level to (3) YUNIT_COND                                          21c");
   yUNIT_minstr  ("... ... eterm"                      , yURG_peek (x_urun, 'Ö'), "   assign format/color to (y) ETERM                                               90x");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check script"                   , yURG_peek (x_urun, 'Ö'), "SCRP [02] (SCRP) verify system startup ==================================[ê2]=[00050]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, 'Ö'), "  COND [001] run initialization -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00051]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, 'Ö'), "  " BACK_MAG "SOND [002]" BACK_OFF " script input file  -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00029]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, 'Ö'), "  " BACK_MAG "SOND [003]" BACK_OFF " code output file - -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00034]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, 'Ö'), "  COND [004] parse a code record - -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00057]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check script footer"            , yURG_peek (x_urun, 'Ö'), "  PRCS -------- cond=4     test=28    [ ------------------------------------------- ]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check unit footer"              , yURG_peek (x_urun, 'Ö'), "TINU  scrp=1    cond=4     test=28    [ ------------------------------------------- ]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check unit footer"              , yURG_peek (x_urun, 'Ö'), "yUNIT - heatherly unit testing framework ---------------------------------------(end)");
   yUNIT_minval  ("... check line count"               , yURG_peek_count (x_urun) , 22);
   yUNIT_mindnoc ();

   yUNIT_mincond ("check executing and presenting only conditions");
   yUNIT_minval  ("... run unit test"                  , system ("./koios_unit --cond"), 999);
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify header");
   yUNIT_minstr  ("... check unit header"              , yURG_peek (x_urun, 'º'), "yUNIT - heatherly unit testing framework ---------------------------------------(beg)");
   yUNIT_minstr  ("... ... patron"                     , yURG_peek (x_urun, 'Ö'), "   patron : daktyloi-aeonius (forefinger) automated unit testing                   4s");
   yUNIT_minstr  ("... ... level"                      , yURG_peek (x_urun, 'Ö'), "   assign output level to (3) YUNIT_COND                                          21c");
   yUNIT_minstr  ("... ... eterm"                      , yURG_peek (x_urun, 'Ö'), "   assign format/color to (y) ETERM                                               90x");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check section"                  , yURG_peek (x_urun, 'Ö'), "=========================------------------------------------========================");
   yUNIT_minstr  ("... check section"                  , yURG_peek (x_urun, 'Ö'), "SECT ===-------------------------- simple testing ---------------------------=== TCES");
   yUNIT_minstr  ("... check section"                  , yURG_peek (x_urun, 'Ö'), "=========================------------------------------------========================");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify first script");
   yUNIT_minstr  ("... check script"                   , yURG_peek (x_urun, 'Ö'), "SCRP [01] (SCRP) verify openning and closing ============================[ê1]=[00006]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, 'Ö'), "  COND [001] simple openning -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00007]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, 'Ö'), "      " BACK_GRN "DNOC --------------- test=4     [ pass=4     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, 'Ö'), "  " BACK_CYN "CCND [002] (1)" BACK_OFF " defensive checks - -- -- -- -- -- -- -- -- -- -- -- -- -- -- [00012]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, 'Ö'), "      " BACK_GRN "DNOC --------------- test=4     [ pass=3     fail=0     badd=0     void=1     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, 'Ö'), "  " BACK_CYN "DOND [003] (1) defensive checks - -- -- -- -- -- -- -- -- -- -- -- -- -- -- [00017]" BACK_OFF);
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, 'Ö'), "      " BACK_GRN "DNOC --------------- test=4     [ pass=3     fail=0     badd=0     void=1     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, 'Ö'), "  COND [004] small condition -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00018]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, 'Ö'), "      " BACK_GRN "DNOC --------------- test=1     [ pass=1     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, 'Ö'), "  " BACK_CYN "DOND [005] (1) defensive checks - -- -- -- -- -- -- -- -- -- -- -- -- -- -- [00020]" BACK_OFF);
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, 'Ö'), "      " BACK_GRN "DNOC --------------- test=4     [ pass=3     fail=0     badd=0     void=1     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, 'Ö'), "  COND [006] duplicate opens and closes  -- -- -- -- -- -- -- -- -- -- -- -- -[00021]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, 'Ö'), "      " BACK_RED "DNOC --------------- test=5     [ pass=1     fail=1     badd=0     void=3     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check script footer"            , yURG_peek (x_urun, 'Ö'), "  " BACK_RED "PRCS -------- cond=6     test=22    [ pass=15    fail=1     badd=0     void=6     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check section"                  , yURG_peek (x_urun, 'Ö'), "=========================------------------------------------========================");
   yUNIT_minstr  ("... check section"                  , yURG_peek (x_urun, 'Ö'), "SECT ===----------------------- more complex testing ------------------------=== TCES");
   yUNIT_minstr  ("... check section"                  , yURG_peek (x_urun, 'Ö'), "=========================------------------------------------========================");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify second script");
   yUNIT_minstr  ("... check script"                   , yURG_peek (x_urun, 'Ö'), "SCRP [02] (SCRP) verify system startup ==================================[ê2]=[00050]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, 'Ö'), "  COND [001] run initialization -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00051]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, 'Ö'), "      " BACK_RED "DNOC --------------- test=4     [ pass=1     fail=2     badd=0     void=1     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, 'Ö'), "  " BACK_MAG "SOND [002]" BACK_OFF " script input file  -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00029]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, 'Ö'), "      " BACK_RED "DNOC --------------- test=4     [ pass=0     fail=3     badd=0     void=1     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, 'Ö'), "  " BACK_MAG "SOND [003]" BACK_OFF " code output file - -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00034]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, 'Ö'), "      " BACK_GRN "DNOC --------------- test=4     [ pass=4     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, 'Ö'), "  COND [004] parse a code record - -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00057]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, 'Ö'), "      " BACK_GRN "DNOC --------------- test=16    [ pass=11    fail=0     badd=0     void=5     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check script footer"            , yURG_peek (x_urun, 'Ö'), "  " BACK_RED "PRCS -------- cond=4     test=28    [ pass=16    fail=5     badd=0     void=7     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify third script");
   yUNIT_minstr  ("... check script"                   , yURG_peek (x_urun, 'Ö'), "SCRP [03] (SCRP) verify normal processing ===============================[ì2]=[00074]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check group"                    , yURG_peek (x_urun, 'Ö'), "  GROUP ===----------------------------   round one   ----------------------------===");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, 'Ö'), "  " BACK_CYN "CCND [001] (1)" BACK_OFF " process arguments  -- -- -- -- -- -- -- -- -- -- -- -- -- -- [00076]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, 'Ö'), "      " BACK_GRN "DNOC --------------- test=4     [ pass=4     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, 'Ö'), "  " BACK_MAG "SOND [002]" BACK_OFF " script input file  -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00029]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, 'Ö'), "      " BACK_GRN "DNOC --------------- test=4     [ pass=3     fail=0     badd=0     void=1     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, 'Ö'), "  " BACK_MAG "SOND [003]" BACK_OFF " code output file - -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00034]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, 'Ö'), "      " BACK_GRN "DNOC --------------- test=4     [ pass=4     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, 'Ö'), "  " BACK_CYN "CCND [004] (2)" BACK_OFF " read one record -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- [00082]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, 'Ö'), "      " BACK_RED "DNOC --------------- test=4     [ pass=0     fail=4     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check group"                    , yURG_peek (x_urun, 'Ö'), "  GROUP ===----------------------------   round two   ----------------------------===");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, 'Ö'), "  " BACK_CYN "DOND [005] (1) process arguments  -- -- -- -- -- -- -- -- -- -- -- -- -- -- [00088]" BACK_OFF);
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, 'Ö'), "      " BACK_GRN "DNOC --------------- test=4     [ pass=4     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, 'Ö'), "  " BACK_MAG "SOND [006]" BACK_OFF " code output file - -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00040]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, 'Ö'), "      " BACK_GRN "DNOC --------------- test=4     [ pass=4     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, 'Ö'), "  " BACK_MAG "SOND [007]" BACK_OFF " close and delete code file  -- -- -- -- -- -- -- -- -- -- -- -- -[00045]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, 'Ö'), "      " BACK_GRN "DNOC --------------- test=4     [ pass=4     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check group"                    , yURG_peek (x_urun, 'Ö'), "  GROUP ===---------------------------   final round   ---------------------------===");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, 'Ö'), "  " BACK_CYN "DOND [008] (2) read one record -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- [00091]" BACK_OFF);
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, 'Ö'), "      " BACK_RED "DNOC --------------- test=4     [ pass=0     fail=4     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check global condition"         , yURG_peek (x_urun, 'Ö'), "  " BACK_BLU "GOND [009]" BACK_OFF " prepare variables  -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00007]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, 'Ö'), "      " BACK_GRN "DNOC --------------- test=1     [ pass=0     fail=0     badd=0     void=1     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check global condition"         , yURG_peek (x_urun, 'Ö'), "  " BACK_BLU "GOND [010]" BACK_OFF " generate a summary -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00009]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, 'Ö'), "      " BACK_GRN "DNOC --------------- test=3     [ pass=3     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, 'Ö'), "  " BACK_CYN "DOND [011] (1) process arguments  -- -- -- -- -- -- -- -- -- -- -- -- -- -- [00093]" BACK_OFF);
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, 'Ö'), "      " BACK_GRN "DNOC --------------- test=4     [ pass=4     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check script footer"            , yURG_peek (x_urun, 'Ö'), "  " BACK_RED "PRCS -------- cond=11    test=40    [ pass=30    fail=8     badd=0     void=2     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify fourth script and footer");
   yUNIT_minstr  ("... check script"                   , yURG_peek (x_urun, 'Ö'), "SCRP [04] (SCRP) empty script ===========================================[è9]=[00094]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check script footer"            , yURG_peek (x_urun, 'Ö'), "  " BACK_YEL "PRCS -------- cond=0     test=0     [ pass=0     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check unit footer"              , yURG_peek (x_urun, 'Ö'), BACK_RED "TINU  scrp=4    cond=21    test=90    [ pass=61    fail=14    badd=0     void=15    ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check unit footer"              , yURG_peek (x_urun, 'Ö'), "yUNIT - heatherly unit testing framework ---------------------------------------(end)");
   yUNIT_minval  ("... check line count"               , yURG_peek_count (x_urun) , 108);
   yUNIT_mindnoc ();

   yUNIT_mincond ("check executing and presenting but show only one script");
   yUNIT_minval  ("... run unit test"                  , system ("./koios_unit --cond 03"), 999);
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify header");
   yUNIT_minstr  ("... check unit header"              , yURG_peek (x_urun, 'º'), "yUNIT - heatherly unit testing framework ---------------------------------------(beg)");
   yUNIT_minstr  ("... ... patron"                     , yURG_peek (x_urun, 'Ö'), "   patron : daktyloi-aeonius (forefinger) automated unit testing                   4s");
   yUNIT_minstr  ("... ... level"                      , yURG_peek (x_urun, 'Ö'), "   assign output level to (3) YUNIT_COND                                          21c");
   yUNIT_minstr  ("... ... eterm"                      , yURG_peek (x_urun, 'Ö'), "   assign format/color to (y) ETERM                                               90x");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify third script");
   yUNIT_minstr  ("... check script"                   , yURG_peek (x_urun, 'Ö'), "SCRP [03] (SCRP) verify normal processing ===============================[ì2]=[00074]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check group"                    , yURG_peek (x_urun, 'Ö'), "  GROUP ===----------------------------   round one   ----------------------------===");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, 'Ö'), "  " BACK_CYN "CCND [001] (1)" BACK_OFF " process arguments  -- -- -- -- -- -- -- -- -- -- -- -- -- -- [00076]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, 'Ö'), "      " BACK_GRN "DNOC --------------- test=4     [ pass=4     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, 'Ö'), "  " BACK_MAG "SOND [002]" BACK_OFF " script input file  -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00029]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, 'Ö'), "      " BACK_GRN "DNOC --------------- test=4     [ pass=3     fail=0     badd=0     void=1     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, 'Ö'), "  " BACK_MAG "SOND [003]" BACK_OFF " code output file - -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00034]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, 'Ö'), "      " BACK_GRN "DNOC --------------- test=4     [ pass=4     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, 'Ö'), "  " BACK_CYN "CCND [004] (2)" BACK_OFF " read one record -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- [00082]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, 'Ö'), "      " BACK_RED "DNOC --------------- test=4     [ pass=0     fail=4     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check group"                    , yURG_peek (x_urun, 'Ö'), "  GROUP ===----------------------------   round two   ----------------------------===");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, 'Ö'), "  " BACK_CYN "DOND [005] (1) process arguments  -- -- -- -- -- -- -- -- -- -- -- -- -- -- [00088]" BACK_OFF);
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, 'Ö'), "      " BACK_GRN "DNOC --------------- test=4     [ pass=4     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, 'Ö'), "  " BACK_MAG "SOND [006]" BACK_OFF " code output file - -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00040]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, 'Ö'), "      " BACK_GRN "DNOC --------------- test=4     [ pass=4     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, 'Ö'), "  " BACK_MAG "SOND [007]" BACK_OFF " close and delete code file  -- -- -- -- -- -- -- -- -- -- -- -- -[00045]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, 'Ö'), "      " BACK_GRN "DNOC --------------- test=4     [ pass=4     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check group"                    , yURG_peek (x_urun, 'Ö'), "  GROUP ===---------------------------   final round   ---------------------------===");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, 'Ö'), "  " BACK_CYN "DOND [008] (2) read one record -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- [00091]" BACK_OFF);
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, 'Ö'), "      " BACK_RED "DNOC --------------- test=4     [ pass=0     fail=4     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check global condition"         , yURG_peek (x_urun, 'Ö'), "  " BACK_BLU "GOND [009]" BACK_OFF " prepare variables  -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00007]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, 'Ö'), "      " BACK_GRN "DNOC --------------- test=1     [ pass=0     fail=0     badd=0     void=1     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check global condition"         , yURG_peek (x_urun, 'Ö'), "  " BACK_BLU "GOND [010]" BACK_OFF " generate a summary -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00009]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, 'Ö'), "      " BACK_GRN "DNOC --------------- test=3     [ pass=3     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, 'Ö'), "  " BACK_CYN "DOND [011] (1) process arguments  -- -- -- -- -- -- -- -- -- -- -- -- -- -- [00093]" BACK_OFF);
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, 'Ö'), "      " BACK_GRN "DNOC --------------- test=4     [ pass=4     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check script footer"            , yURG_peek (x_urun, 'Ö'), "  " BACK_RED "PRCS -------- cond=11    test=40    [ pass=30    fail=8     badd=0     void=2     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify fourth script and footer");
   yUNIT_minstr  ("... check unit footer"              , yURG_peek (x_urun, 'Ö'), BACK_RED "TINU  scrp=1    cond=11    test=40    [ pass=30    fail=8     badd=0     void=2     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check unit footer"              , yURG_peek (x_urun, 'Ö'), "yUNIT - heatherly unit testing framework ---------------------------------------(end)");
   yUNIT_minval  ("... check line count"               , yURG_peek_count (x_urun) , 53);
   yUNIT_mindnoc ();

   yUNIT_minprcs ();
   return 0;
}

char
koios__unit_live_step    (void)
{
   int         c           =    0;
   char        x_urun      [LEN_HUND]  = "koios.urun";

   yUNIT_minscrp ("live testing on unit test result");
   yURG_err_none ();  /* not to stderr/terminal */

   koios__unit_shared_data ();

   yUNIT_mincond ("check displaying steps");
   yUNIT_minval  ("... run unit test"                  , system ("./koios_unit --steps"), 0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("check step level header");
   yUNIT_minstr  ("... check unit header"              , yURG_peek (x_urun, 'º'), "yUNIT - heatherly unit testing framework ---------------------------------------(beg)");
   yUNIT_minstr  ("... ... patron"                     , yURG_peek (x_urun, 'Ö'), "   patron : daktyloi-aeonius (forefinger) automated unit testing                   4s");
   yUNIT_minstr  ("... ... level"                      , yURG_peek (x_urun, 'Ö'), "   assign output level to (4) YUNIT_STEP                                          21c");
   yUNIT_minstr  ("... ... eterm"                      , yURG_peek (x_urun, 'Ö'), "   assign format/color to (y) ETERM                                               90x");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check step level section format");
   yUNIT_minstr  ("... check section"                  , yURG_peek (x_urun, 'Ö'), "=========================------------------------------------========================");
   yUNIT_minstr  ("... check section"                  , yURG_peek (x_urun, 'Ö'), "SECT ===-------------------------- simple testing ---------------------------=== TCES");
   yUNIT_minstr  ("... check section"                  , yURG_peek (x_urun, 'Ö'), "=========================------------------------------------========================");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check step level script format");
   yUNIT_minstr  ("... check (11) separator"           , yURG_peek (x_urun, 'Ö'), "===[[ NEW SCRIPT ]]==================================================================");
   yUNIT_minstr  ("... check script"                   , yURG_peek (x_urun, 'Ö'), "SCRP [01] (SCRP) verify openning and closing ============================[ê1]=[00006]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check step level condition and normal steps");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, 'Ö'), "  COND [001] simple openning -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00007]");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, 'Ö'), "     aa) str   : check string · ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·[00008]");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, 'Ö'), "     ab) real  : check number · ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·[00009]");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, 'Ö'), "     ac) int   : check integer  ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·[00010]");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, 'Ö'), "     ad) int   : check character · ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·[00011]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, 'Ö'), "  " BACK_CYN "CCND [002] (1)" BACK_OFF " defensive checks - -- -- -- -- -- -- -- -- -- -- -- -- -- -- [00012]");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check alternative step level entries");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun,  41), "  COND [006] duplicate opens and closes  -- -- -- -- -- -- -- -- -- -- -- -- -[00021]");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, 'Ö'), "     aa) LOCAL : working variables ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·[00022]");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, 'Ö'), "     ab) int   : check working variable  ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·[00023]");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, 'Ö'), "     ac) LOAD  : prep data for read · ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·[00024]");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, 'Ö'), "     ad) MODE  : FORCED_FAIL ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·[00025]");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, 'Ö'), "     ae) SYS   : run little  ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·[00026]");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check inclusion of shared");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun,  64), "");
   yUNIT_minstr  ("... check shared header"            , yURG_peek (x_urun, 'Ö'), "  " BACK_MAG "SHARE (a) ===--------------------   prepare files for use   --------------------===" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, 'Ö'), "  " BACK_MAG "SOND [002]" BACK_OFF " script input file  -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00029]");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, 'Ö'), "     aa) str   : check string · ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·[00030]");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, 'Ö'), "     ab) real  : check number · ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·[00031]");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, 'Ö'), "     ac) int   : check integer  ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·[00032]");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, 'Ö'), "     ad) MODE  : normal · ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·[00033]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, 'Ö'), "  " BACK_MAG "SOND [003]" BACK_OFF " code output file - -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00034]");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, 'Ö'), "     aa) str   : check string · ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·[00035]");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, 'Ö'), "     ab) real  : check number · ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·[00036]");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, 'Ö'), "     ac) int   : check integer  ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·[00037]");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, 'Ö'), "     ad) int   : check character · ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·[00038]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check shared footer"            , yURG_peek (x_urun, 'Ö'), "  " BACK_MAG "ERAHS (a) ===--------------------   prepare files for use   --------------------===" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minval  ("... check line count"               , yURG_peek_count (x_urun) , 197);
   yUNIT_mindnoc ();

   yUNIT_mincond ("check inclusion of global");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 166), "");
   yUNIT_minstr  ("... check global header"            , yURG_peek (x_urun, 'Ö'), "  " BACK_BLU "GLOBAL (D) ===-------------------   globally shared steps   --------------------===" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, 'Ö'), "  " BACK_BLU "GOND [009]" BACK_OFF " prepare variables  -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00007]");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, 'Ö'), "     aa) CODE  : set new value  ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·[00008]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, 'Ö'), "  " BACK_BLU "GOND [010]" BACK_OFF " generate a summary -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00009]");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, 'Ö'), "     aa) str   : check string · ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·[00010]");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, 'Ö'), "     ab) real  : check number · ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·[00011]");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, 'Ö'), "     ac) int   : check integer  ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·[00012]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check global footer"            , yURG_peek (x_urun, 'Ö'), "  " BACK_BLU "LABOLG (D) ===-------------------   globally shared steps   --------------------===" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minval  ("... check line count"               , yURG_peek_count (x_urun) , 197);
   yUNIT_mindnoc ();

   yUNIT_mincond ("check executing and presenting down to steps");
   yUNIT_minval  ("... run unit test"                  , system ("./koios_unit --step"), 999);
   yUNIT_mindnoc ();

   yUNIT_mincond ("check step level condition and normal steps");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun,  14), "  COND [001] simple openning -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00007]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, 'Ö'), "  " BACK_GRN "aa) PASS  " BACK_OFF " : check string ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ··[00008]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, 'Ö'), "  " BACK_GRN "ab) PASS  " BACK_OFF " : check number ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ··[00009]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, 'Ö'), "  " BACK_GRN "ac) PASS  " BACK_OFF " : check integer · ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ··[00010]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, 'Ö'), "  " BACK_GRN "ad) PASS  " BACK_OFF " : check character ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ··[00011]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, 'Ö'), "      " BACK_GRN "DNOC --------------- test=4     [ pass=4     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, 'Ö'), "  " BACK_CYN "CCND [002] (1)" BACK_OFF " defensive checks - -- -- -- -- -- -- -- -- -- -- -- -- -- -- [00012]");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check alternative step level entries");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun,  68), "  COND [006] duplicate opens and closes  -- -- -- -- -- -- -- -- -- -- -- -- -[00021]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, 'Ö'), "  " BACK_CYN "aa) " BACK_GRN "LOCAL " BACK_OFF " : working variables  ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ··[00022]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, 'Ö'), "  " BACK_GRN "ab) PASS  " BACK_OFF " : check working variable · ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ··[00023]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, 'Ö'), "  " BACK_CYN "ac) " BACK_GRN "LOAD  " BACK_OFF " : prep data for read ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ··[00024]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, 'Ö'), "  " BACK_CYN "ad) " BACK_GRN "MODE  " BACK_OFF " : ENABLE FORCED FAILURE (pass=fail, fail=pass)  ·· ·· ·· ·· ·· ··[00025]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, 'Ö'), "  " BACK_CYN "ae) " BACK_RED "!SYS  " BACK_OFF " : run little · ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ··[00026]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, 'Ö'), "      " BACK_RED "DNOC --------------- test=5     [ pass=1     fail=1     badd=0     void=3     ]" BACK_OFF);
   yUNIT_mindnoc ();

   yUNIT_minprcs ();
   return 0;
}

char
koios__unit_live_full    (void)
{
   int         c           =    0;
   char        x_urun      [LEN_HUND]  = "koios.urun";

   yUNIT_minscrp ("live testing on unit test result");
   yURG_err_none ();  /* not to stderr/terminal */

   koios__unit_shared_data ();


   yUNIT_mincond ("check executing and presenting full");
   yUNIT_minval  ("... run unit test"                  , system ("./koios_unit"), 999);
   yUNIT_mindnoc ();

   yUNIT_mincond ("check passing string step");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun,  16), "  " BACK_GRN "aa) PASS  " BACK_OFF " : check string ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ··[00008]");
   yUNIT_minstr  ("... ... method"                     , yURG_peek (x_urun, 'Ö'), "      method : yUNIT_teststring (0)");
   yUNIT_minstr  ("... ... test"                       , yURG_peek (x_urun, 'Ö'), "      test   : s_equal    (rc =  101, test abbr = e)");
   yUNIT_minstr  ("... ... expect"                     , yURG_peek (x_urun, 'Ö'), "      expect :  5[hello]");
   yUNIT_minstr  ("... ... actual"                     , yURG_peek (x_urun, 'Ö'), "      actual :  5[hello]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check failing string step (nearly same)");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, 418), "  " BACK_RED "aa) FAIL  " BACK_OFF " : check string ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ··[00083]");
   yUNIT_minstr  ("... ... method"                     , yURG_peek (x_urun, 'Ö'), "      method : yUNIT_teststring (1)");
   yUNIT_minstr  ("... ... test"                       , yURG_peek (x_urun, 'Ö'), "      test   : s_equal    (rc = -101, test abbr = e)");
   yUNIT_minstr  ("... ... expect"                     , yURG_peek (x_urun, 'Ö'), "      expect :  7[" BOLD_RED "hello££" BOLD_OFF "]");
   yUNIT_minstr  ("... ... actual"                     , yURG_peek (x_urun, 'Ö'), "      actual :  7[" BOLD_RED "goodbye" BOLD_OFF "]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check forced fail string step (same)");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, 187), "  " BACK_GRN "aa) " BACK_RED "!FAIL " BACK_OFF " : check string ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ··[00030]");
   yUNIT_minstr  ("... ... method"                     , yURG_peek (x_urun, 'Ö'), "      method : yUNIT_teststring (0)");
   yUNIT_minstr  ("... ... test"                       , yURG_peek (x_urun, 'Ö'), "      test   : s_equal    (rc =  101, test abbr = e)");
   yUNIT_minstr  ("... ... expect"                     , yURG_peek (x_urun, 'Ö'), "      expect :  5[hello]");                              
   yUNIT_minstr  ("... ... actual"                     , yURG_peek (x_urun, 'Ö'), "      actual :  5[hello]");                              
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check passing float step");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun,  22), "  " BACK_GRN "ab) PASS  " BACK_OFF " : check number ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ··[00009]");
   yUNIT_minstr  ("... ... method"                     , yURG_peek (x_urun, 'Ö'), "      method : yUNIT_testreal (5)");
   yUNIT_minstr  ("... ... test"                       , yURG_peek (x_urun, 'Ö'), "      test   : r_greater  (rc =  103, test abbr = g)");
   yUNIT_minstr  ("... ... expect"                     , yURG_peek (x_urun, 'Ö'), "      expect :  9[15.000000]");
   yUNIT_minstr  ("... ... actual"                     , yURG_peek (x_urun, 'Ö'), "      actual :  9[15.707964]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check failing float step");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, 424), "  " BACK_RED "ab) FAIL  " BACK_OFF " : check number ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ··[00084]");
   yUNIT_minstr  ("... ... method"                     , yURG_peek (x_urun, 'Ö'), "      method : yUNIT_testreal (2)");
   yUNIT_minstr  ("... ... test"                       , yURG_peek (x_urun, 'Ö'), "      test   : r_greater  (rc = -103, test abbr = g)");
   yUNIT_minstr  ("... ... expect"                     , yURG_peek (x_urun, 'Ö'), "      expect :  9[15.000000]");
   yUNIT_minstr  ("... ... actual"                     , yURG_peek (x_urun, 'Ö'), "      actual :  8[6.283185]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check passing integer step");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun,  28), "  " BACK_GRN "ac) PASS  " BACK_OFF " : check integer · ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ··[00010]");
   yUNIT_minstr  ("... ... method"                     , yURG_peek (x_urun, 'Ö'), "      method : yUNIT_testint (32)");
   yUNIT_minstr  ("... ... test"                       , yURG_peek (x_urun, 'Ö'), "      test   : i_equal    (rc =  101, test abbr = e)");
   yUNIT_minstr  ("... ... expect"                     , yURG_peek (x_urun, 'Ö'), "      expect :  1[2]");
   yUNIT_minstr  ("... ... actual"                     , yURG_peek (x_urun, 'Ö'), "      actual :  1[2]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check failing integer step");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, 430), "  " BACK_RED "ac) FAIL  " BACK_OFF " : check integer · ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ··[00085]");
   yUNIT_minstr  ("... ... method"                     , yURG_peek (x_urun, 'Ö'), "      method : yUNIT_testint (64)");
   yUNIT_minstr  ("... ... test"                       , yURG_peek (x_urun, 'Ö'), "      test   : i_equal    (rc = -101, test abbr = e)");
   yUNIT_minstr  ("... ... expect"                     , yURG_peek (x_urun, 'Ö'), "      expect :  1[2]");
   yUNIT_minstr  ("... ... actual"                     , yURG_peek (x_urun, 'Ö'), "      actual :  1[4]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check mode step");                                   
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, 141), "  " BACK_CYN "ad) " BACK_GRN "MODE  " BACK_OFF " : ENABLE FORCED FAILURE (pass=fail, fail=pass)  ·· ·· ·· ·· ·· ··[00025]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check code step");                                   
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, 568), "  " BACK_CYN "aa) " BACK_GRN "CODE  " BACK_OFF " : set new value · ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ··[00008]");
   yUNIT_minstr  ("... ... contents"                   , yURG_peek (x_urun, 'Ö'), "      code   : 12[h = 32 * 64;]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check load step");                                   
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun,  44), "  " BACK_CYN "aa) " BACK_GRN "LOAD  " BACK_OFF " : prep data for read ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ··[00013]");
   yUNIT_minstr  ("... ... contents"                   , yURG_peek (x_urun, 'Ö'), "      stdin  : 13[one two three]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check sys step");                                   
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, 143), "  " BACK_CYN "ae) " BACK_RED "!SYS  " BACK_OFF " : run little · ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ··[00026]");
   yUNIT_minstr  ("... ... contents"                   , yURG_peek (x_urun, 'Ö'), "      system : 10[/bin/false]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check local step");                                   
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, 129), "  " BACK_CYN "aa) " BACK_GRN "LOCAL " BACK_OFF " : working variables  ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ··[00022]");
   yUNIT_minstr  ("... ... contents"                   , yURG_peek (x_urun, 'Ö'), "      local  : 10[int c = 0;]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 'Ö'), "");
   yUNIT_mindnoc ();

   yUNIT_minprcs ();
   return 0;
}



/*====================------------------------------------====================*/
/*===----                      main driver                             ----===*/
/*====================------------------------------------====================*/
static void      o___DRIVER__________________o (void) {;}

char
main                    (void)
{
   /*---(program wide)-------------------*/
   koios__unit_prog_file    ();
   koios__unit_prog_args    ();
   koios__unit_prog_shared  ();
   /*---(script input)-------------------*/
   koios__unit_scrp_files   ();
   koios__unit_scrp_read    ();
   koios__unit_scrp_verb    ();
   koios__unit_scrp_stage   ();
   koios__unit_scrp_comment ();
   koios__unit_scrp_parse   ();
   koios__unit_scrp_share   ();
   koios__unit_scrp_ditto   ();
   koios__unit_scrp_variety ();
   /*---(conversion output)--------------*/
   koios__unit_conv_files   ();
   koios__unit_conv_ends    ();
   koios__unit_conv_prep    ();
   koios__unit_conv_scrp    ();
   koios__unit_conv_cond    ();
   koios__unit_conv_step    ();
   /*---(code generation)----------------*/
   koios__unit_code_counts  ();
   koios__unit_code_files   ();
   koios__unit_code_ends    ();
   koios__unit_code_prep    ();
   koios__unit_code_scrp    ();
   koios__unit_code_cond    ();
   koios__unit_code_step    ();
   /*---(live testing)-------------------*/
   koios__unit_live_scrp    ();
   koios__unit_live_cond    ();
   koios__unit_live_step    ();
   koios__unit_live_full    ();
   /*---(done)---------------------------*/
   system ("rm -f /tmp/koios.unit 2> /dev/null");
   yUNIT_mintinu ();
   return 0;
}


