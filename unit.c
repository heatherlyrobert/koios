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
koios__unit_prog_file    (char a_list)
{
   char        x_base      [LEN_PATH]  = "";
   char        x_ext       [LEN_TERSE] = "";
   yUNIT_minscrp ("PROG__file");
   if (a_list == 'y')  return 0;
   yURG_err_none ();  /* not to stderr/terminal */

   yURG_err_clear ();
   yUNIT_mincond ("prepare clean start");
   system ("rm    -f /tmp/koios.unit        2> /dev/null");
   system ("rm    -f /tmp/koios.sunit       2> /dev/null");
   system ("rm    -f /tmp/linked.unit       2> /dev/null");
   system ("rm    -f /tmp/linked.sunit      2> /dev/null");
   system ("rm    -f /tmp/koios-a.unit      2> /dev/null");
   system ("rm    -f /tmp/koios_a.unit      2> /dev/null");
   system ("rmdir -f /tmp/koios_dir.unit    2> /dev/null");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("attempt with a missing file");
   yUNIT_minval  ("... run file check"                 , PROG__file ("/tmp/koios", x_base, x_ext)           , -999);
   yUNIT_minstr  ("... check base"                     , x_base          , "");
   yUNIT_minstr  ("... check ext"                      , x_ext           , "");
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "script name �/tmp/koios� can not be found as .unit or .sunit");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   system ("touch /tmp/koios.unit        2> /dev/null");
   yUNIT_mincond ("quick success once file added");
   yUNIT_minval  ("... run file check"                 , PROG__file ("/tmp/koios", x_base, x_ext)           , 0);
   yUNIT_minstr  ("... check base"                     , x_base          , "/tmp/koios");
   yUNIT_minstr  ("... check ext"                      , x_ext           , ".unit");
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   system ("rm -f /tmp/koios.unit        2> /dev/null");
   system ("touch /tmp/linked.unit       2> /dev/null");
   system ("cp -s /tmp/linked.unit  /tmp/koios.unit  2> /dev/null");
   yUNIT_mincond ("attempt a symlink to regular e (.unit file)");
   yUNIT_minval  ("... run file check"                 , PROG__file ("/tmp/koios", x_base, x_ext)           , -999);
   yUNIT_minstr  ("... check base"                     , x_base          , "");
   yUNIT_minstr  ("... check ext"                      , x_ext           , "");
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "script name �/tmp/koios� is a symlink to �/tmp/linked.unit�, only .sunit is legal");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   system ("rm -f /tmp/koios.unit        2> /dev/null");
   system ("touch /tmp/linked.sunit      2> /dev/null");
   system ("cp -s /tmp/linked.sunit /tmp/koios.unit  2> /dev/null");
   yUNIT_mincond ("verify can symlink to .sunit");
   yUNIT_minval  ("... run file check"                 , PROG__file ("/tmp/koios", x_base, x_ext)           , 0);
   yUNIT_minstr  ("... check base"                     , x_base          , "/tmp/koios");
   yUNIT_minstr  ("... check ext"                      , x_ext           , ".unit");
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   system ("mkdir /tmp/koios_dir.unit    2> /dev/null");
   yUNIT_mincond ("attempt to use a directory");
   yUNIT_minval  ("... run file check"                 , PROG__file ("/tmp/koios_dir", x_base, x_ext)       , -999);
   yUNIT_minstr  ("... check base"                     , x_base          , "");
   yUNIT_minstr  ("... check ext"                      , x_ext           , "");
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "script name �/tmp/koios_dir� refers to a directory, illegal");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   system ("touch /tmp/koios-a.unit      2> /dev/null");
   yUNIT_mincond ("badly named unit test");
   yUNIT_minval  ("... run file check"                 , PROG__file ("/tmp/koios-a", x_base, x_ext)         , -999);
   yUNIT_minstr  ("... check base"                     , x_base          , "");
   yUNIT_minstr  ("... check ext"                      , x_ext           , "");
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "script name �/tmp/koios-a� can not have a '-' as character 10");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   system ("touch /tmp/koios_a.unit      2> /dev/null");
   yUNIT_mincond ("named with underscore");
   yUNIT_minval  ("... run file check"                 , PROG__file ("/tmp/koios_a", x_base, x_ext)         , 0);
   yUNIT_minstr  ("... check base"                     , x_base          , "/tmp/koios_a");
   yUNIT_minstr  ("... check ext"                      , x_ext           , ".unit");
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("called with extention");
   yUNIT_minval  ("... run file check"                 , PROG__file ("/tmp/koios_a.unit", x_base, x_ext)    , 0);
   yUNIT_minstr  ("... check base"                     , x_base          , "/tmp/koios_a");
   yUNIT_minstr  ("... check ext"                      , x_ext           , ".unit");
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("clean up at end");
   system ("rm    -f /tmp/koios.unit        2> /dev/null");
   system ("rm    -f /tmp/koios.sunit       2> /dev/null");
   system ("rm    -f /tmp/linked.unit       2> /dev/null");
   system ("rm    -f /tmp/linkeds.unit      2> /dev/null");
   system ("rm    -f /tmp/koios-a.unit      2> /dev/null");
   system ("rm    -f /tmp/koios_a.unit      2> /dev/null");
   system ("rmdir -f /tmp/koios_dir.unit    2> /dev/null");
   yUNIT_mindnoc ();

   yUNIT_minprcs ();
   return 0;
}

char
koios__unit_prog_args    (char a_list)
{
   char        x_base      [LEN_PATH]  = "";
   char        x_ext       [LEN_TERSE] = "";
   char        x_runtype   = '�';
   char        x_replace   = '�';
   yUNIT_minscrp ("PROG__args");
   if (a_list == 'y')  return 0;
   yURG_err_none ();  /* not to stderr/terminal */

   yUNIT_mincond ("prepare clean start");
   char  *x_argA [3]  = { "koios_unit" , "--debug"       , "/home/member/khaos.unit"  };
   char  *x_argB [3]  = { "koios_unit" , "--compile"     , "/tmp/gyges.unit"          };
   char  *x_argC [3]  = { "koios_unit" , "--debuggery"   , "/tmp/hestia.unit"         };
   char  *x_argD [3]  = { "koios_unit" , "--create"      , "/tmp/hestia"              };
   char  *x_argE [3]  = { "koios_unit" , "--convert"     , "/tmp/koios.sunit"         };
   char  *x_argF [1]  = { "koios_unit" };
   char  *x_argG [3]  = { "koios_unit" , "--update"      , "/tmp/koios"               };
   char  *x_argH [3]  = { "koios_unit" , "--compile"     , "/tmp/koios.sunit"         };
   system ("rm    -f /home/member/khaos.unit    2> /dev/null");
   system ("rm    -f /tmp/gyges.unit            2> /dev/null");
   system ("rm    -f /tmp/hestia.unit           2> /dev/null");
   system ("rm    -f /tmp/koios.sunit           2> /dev/null");
   system ("rm    -f /tmp/hoios.unit            2> /dev/null");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("attempt with no arguments (defaulting)");
   yUNIT_minval  ("... run args"                       , PROG__args (1, x_argF, &x_runtype, &x_replace, x_base, x_ext) , -999);
   yUNIT_minchr  ("... check run type"                 , x_runtype   , '�');
   yUNIT_minchr  ("... check run replace"              , x_replace   , '�');
   yUNIT_minstr  ("... check base"                     , x_base      , "");
   yUNIT_minstr  ("... check ext"                      , x_ext       , "");
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "script name/base was not provided on command line");
   yUNIT_mindnoc ();

   system ("touch /home/member/khaos.unit  2> /dev/null");
   yURG_err_clear ();
   yUNIT_mincond ("run with debug");
   yUNIT_minval  ("... run args"                       , PROG__args (3, x_argA, &x_runtype, &x_replace, x_base, x_ext) , 0);
   yUNIT_minchr  ("... check run type"                 , x_runtype   , G_RUN_DEBUG);
   yUNIT_minchr  ("... check run replace"              , x_replace   , G_RUN_DEFAULT);
   yUNIT_minstr  ("... check base"                     , x_base          , "/home/member/khaos");
   yUNIT_minstr  ("... check ext"                      , x_ext           , ".unit");
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc ();

   system ("touch /tmp/gyges.unit          2> /dev/null");
   yURG_err_clear ();
   yUNIT_mincond ("run with compile");
   yUNIT_minval  ("... run args"                       , PROG__args (3, x_argB, &x_runtype, &x_replace, x_base, x_ext) , 0);
   yUNIT_minchr  ("... check run type"                 , x_runtype   , G_RUN_CREATE);
   yUNIT_minchr  ("... check run replace"              , x_replace   , G_RUN_DEFAULT);
   yUNIT_minstr  ("... check base"                     , x_base          , "/tmp/gyges");
   yUNIT_minstr  ("... check ext"                      , x_ext           , ".unit");
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc ();

   system ("touch /tmp/hestia.unit         2> /dev/null");
   yURG_err_clear ();
   yUNIT_mincond ("run with bad argument");
   yUNIT_minval  ("... run args"                       , PROG__args (3, x_argC, &x_runtype, &x_replace, x_base, x_ext) , -999);
   yUNIT_minchr  ("... check run type"                 , x_runtype   , '�');
   yUNIT_minchr  ("... check run replace"              , x_replace   , '�');
   yUNIT_minstr  ("... check base"                     , x_base          , "");
   yUNIT_minstr  ("... check ext"                      , x_ext           , "");
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "argument �--debuggery� is not recognized");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("run with create");
   yUNIT_minval  ("... run args"                       , PROG__args (3, x_argD, &x_runtype, &x_replace, x_base, x_ext) , 0);
   yUNIT_minchr  ("... check run type"                 , x_runtype   , G_RUN_CREATE);
   yUNIT_minchr  ("... check run replace"              , x_replace   , G_RUN_DEFAULT);
   yUNIT_minstr  ("... check base"                     , x_base          , "/tmp/hestia");
   yUNIT_minstr  ("... check ext"                      , x_ext           , ".unit");
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc ();

   system ("touch /tmp/koios.sunit         2> /dev/null");
   yURG_err_clear ();
   yUNIT_mincond ("run sunit with convert");
   yUNIT_minval  ("... run args"                       , PROG__args (3, x_argE, &x_runtype, &x_replace, x_base, x_ext) , 0);
   yUNIT_minchr  ("... check run type"                 , x_runtype   , G_RUN_UPDATE);
   yUNIT_minchr  ("... check run replace"              , x_replace   , G_RUN_DEFAULT);
   yUNIT_minstr  ("... check base"                     , x_base          , "/tmp/koios");
   yUNIT_minstr  ("... check ext"                      , x_ext           , ".sunit");
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("run sunit with compile");
   yUNIT_minval  ("... run args"                       , PROG__args (3, x_argH, &x_runtype, &x_replace, x_base, x_ext) , -999);
   yUNIT_minchr  ("... check run type"                 , x_runtype   , '�');
   yUNIT_minchr  ("... check run replace"              , x_replace   , '�');
   yUNIT_minstr  ("... check base"                     , x_base      , "");
   yUNIT_minstr  ("... check ext"                      , x_ext       , "");
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "can not compile �/tmp/koios� as .sunit, must compile in linked .unit location");
   yUNIT_mindnoc ();

   system ("touch /tmp/koios.unit          2> /dev/null");
   yURG_err_clear ();
   yUNIT_mincond ("run with update");
   yUNIT_minval  ("... run args"                       , PROG__args (3, x_argG, &x_runtype, &x_replace, x_base, x_ext) , 0);
   yUNIT_minchr  ("... check run type"                 , x_runtype   , G_RUN_UPDATE);
   yUNIT_minchr  ("... check run replace"              , x_replace   , G_RUN_REPLACE);
   yUNIT_minstr  ("... check base"                     , x_base          , "/tmp/koios");
   yUNIT_minstr  ("... check ext"                      , x_ext           , ".unit");
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("clean up after");
   system ("rm    -f /home/member/khaos.unit    2> /dev/null");
   system ("rm    -f /tmp/gyges.unit            2> /dev/null");
   system ("rm    -f /tmp/hestia.unit           2> /dev/null");
   system ("rm    -f /tmp/hoios.sunit           2> /dev/null");
   system ("rm    -f /tmp/hoios.unit            2> /dev/null");
   yUNIT_mindnoc ();

   yUNIT_minprcs ();
   return 0;
}



/*====================------------------------------------====================*/
/*===----                        verb processing                       ----===*/
/*====================------------------------------------====================*/
static void      o___VERBS___________________o (void) {;}

char
koios__unit_verb_parse   (char a_list)
{
   char        x_verb      [LEN_LABEL] = "";
   char        x_indx      = -1;
   char        x_spec      = '-';
   char        x_locn      = '-';
   void       *x_conv      = NULL;
   void       *x_code      = NULL;

   yUNIT_minscrp ("VERB_parse");
   if (a_list == 'y')  return 0;
   yURG_err_none ();
   strcpy (my.n_base, "koios");

   yURG_err_clear ();
   yUNIT_mincond  ("parse SCRP verb");
   yUNIT_minval   ("parse SCRP"                          , VERB_parse ("koios",  5, "SCRP"       , x_verb, &x_indx, &x_spec, &x_locn, &x_conv, &x_code), 0);
   yUNIT_minstr   ("... check verb"                      , x_verb        , "SCRP");
   yUNIT_minval   ("... check index"                     , x_indx        , 999);
   yUNIT_minchr   ("... check spec"                      , x_spec        , 's');
   yUNIT_minchr   ("... check location"                  , x_locn        , 'n');
   yUNIT_minpoint ("... check conv pointer"              , x_conv        , CONV_scrp);
   yUNIT_minpoint ("... check code pointer"              , x_code        , CODE_scrp);
   yUNIT_minstr   ("... check error message"             , yURG_err_last (), "");
   yUNIT_mindnoc  () ;

   yURG_err_clear ();
   yUNIT_mincond  ("attempt to parse a non-existant verb");
   yUNIT_minval   ("parse trouble"                       , VERB_parse ("koios", 25, "handler"    , x_verb, &x_indx, &x_spec, &x_locn, &x_conv, &x_code), -999);
   yUNIT_minstr   ("... check verb"                      , x_verb        , "");
   yUNIT_minval   ("... check index"                     , x_indx        , -999);
   yUNIT_minchr   ("... check spec"                      , x_spec        , '-');
   yUNIT_minchr   ("... check location"                  , x_locn        , '-');
   yUNIT_minpoint ("... check conv pointer"              , x_conv        , NULL);
   yUNIT_minpoint ("... check code pointer"              , x_code        , NULL);
   yUNIT_minstr   ("... check error message"             , yURG_err_last (), "koios:25:0: error: verb �handler� not recognized/found");
   yUNIT_mindnoc  ();

   yURG_err_clear ();
   yUNIT_mincond  ("verify parsing a COND verb");
   yUNIT_minval   ("parse COND"                          , VERB_parse ("koios", 10, " COND"      , x_verb, &x_indx, &x_spec, &x_locn, &x_conv, &x_code), 0);
   yUNIT_minstr   ("... check verb"                      , x_verb        , "COND");
   yUNIT_minval   ("... check index"                     , x_indx        , 999);
   yUNIT_minchr   ("... check spec"                      , x_spec        , '2');
   yUNIT_minchr   ("... check location"                  , x_locn        , '-');
   yUNIT_minpoint ("... check conv pointer"              , x_conv        , CONV_cond);
   yUNIT_minpoint ("... check code pointer"              , x_code        , CODE_cond);
   yUNIT_minstr   ("... check error message"             , yURG_err_last (), "");
   yUNIT_mindnoc  ();

   yURG_err_clear ();
   yUNIT_mincond  ("verify parsing a COND again with ditto number");
   yUNIT_minval   ("parse COND"                          , VERB_parse ("koios", 40, " COND (1)"  , x_verb, &x_indx, &x_spec, &x_locn, &x_conv, &x_code), 0);
   yUNIT_minstr   ("... check verb"                      , x_verb        , "COND");
   yUNIT_minval   ("... check index"                     , x_indx        , 999);
   yUNIT_minchr   ("... check spec"                      , x_spec        , '2');
   yUNIT_minchr   ("... check location"                  , x_locn        , '-');
   yUNIT_minpoint ("... check conv pointer"              , x_conv        , CONV_cond);
   yUNIT_minpoint ("... check code pointer"              , x_code        , CODE_cond);
   yUNIT_minstr   ("... check error message"             , yURG_err_last (), "");

   yURG_err_clear ();
   yUNIT_mincond  ("attempt a null input");
   yUNIT_minval   ("parse NULL"                          , VERB_parse ("koios", 50, NULL         , x_verb, &x_indx, &x_spec, &x_locn, &x_conv, &x_code), -999);
   yUNIT_minstr   ("... check verb"                      , x_verb        , "");
   yUNIT_minval   ("... check index"                     , x_indx        , -999);
   yUNIT_minchr   ("... check spec"                      , x_spec        , '-');
   yUNIT_minchr   ("... check location"                  , x_locn        , '-');
   yUNIT_minpoint ("... check conv pointer"              , x_conv        , NULL);
   yUNIT_minpoint ("... check code pointer"              , x_code        , NULL);
   yUNIT_minstr   ("... check error message"             , yURG_err_last (), "koios:50:0: error: no verb found (empty or null)");
   yUNIT_mindnoc  ();

   yURG_err_clear ();
   yUNIT_mincond  ("verify parsing an EXEC verb");
   yUNIT_minval   ("parse exec"                          , VERB_parse ("koios", 15, "  exec"     , x_verb, &x_indx, &x_spec, &x_locn, &x_conv, &x_code), 0);
   yUNIT_minstr   ("... check verb"                      , x_verb        , "exec");
   yUNIT_minval   ("... check index"                     , x_indx        , 999);
   yUNIT_minchr   ("... check spec"                      , x_spec        , 'f');
   yUNIT_minchr   ("... check location"                  , x_locn        , '-');
   yUNIT_minpoint ("... check conv pointer"              , x_conv        , CONV_exec);
   yUNIT_minpoint ("... check code pointer"              , x_code        , CODE_exec);
   yUNIT_minstr   ("... check error message"             , yURG_err_last (), "");
   yUNIT_mindnoc  ();

   yURG_err_clear ();
   yUNIT_mincond  ("verify parsing a SHARED (normal only) verb with suffix");
   yURG_err_clear ();
   yUNIT_minval   ("parse SHARED (in normal)"            , VERB_parse ("koios", 35, "SHARED -a-" , x_verb, &x_indx, &x_spec, &x_locn, &x_conv, &x_code), 0);
   yUNIT_minstr   ("... check verb"                      , x_verb        , "SHARED");
   yUNIT_minval   ("... check index"                     , x_indx        , 999);
   yUNIT_minchr   ("... check spec"                      , x_spec        , 's');
   yUNIT_minchr   ("... check location"                  , x_locn        , 'n');
   yUNIT_minpoint ("... check conv pointer"              , x_conv        , CONV_shared);
   yUNIT_minpoint ("... check code pointer"              , x_code        , CODE_shared);
   yUNIT_minstr   ("... check error message"             , yURG_err_last (), "");
   yUNIT_mindnoc  ();

   yURG_err_clear ();
   yUNIT_mincond  ("attempt parsing a GLOBAL (master only) verb with suffix");
   yURG_err_clear ();
   yUNIT_minval   ("parse GLOBAL (in normal)"            , VERB_parse ("koios", 75, "GLOBAL -a-" , x_verb, &x_indx, &x_spec, &x_locn, &x_conv, &x_code), -999);
   yUNIT_minstr   ("... check verb"                      , x_verb        , "");
   yUNIT_minval   ("... check index"                     , x_indx        , -999);
   yUNIT_minchr   ("... check spec"                      , x_spec        , '-');
   yUNIT_minchr   ("... check location"                  , x_locn        , '-');
   yUNIT_minpoint ("... check conv pointer"              , x_conv        , NULL);
   yUNIT_minpoint ("... check code pointer"              , x_code        , NULL);
   yUNIT_minstr   ("... check error message"             , yURG_err_last (), "koios:75:0: error: verb �GLOBAL� good, but not allowed outside master.unit");
   yUNIT_mindnoc  ();

   strcpy (my.n_base, "master");
   yURG_err_clear ();
   yUNIT_mincond  ("verify parsing a GLOBAL (master only) verb with suffix");
   yURG_err_clear ();
   yUNIT_minval   ("parse GLOBAL (in master)"            , VERB_parse ("koios", 85, "GLOBAL -a-" , x_verb, &x_indx, &x_spec, &x_locn, &x_conv, &x_code), 0);
   yUNIT_minstr   ("... check verb"                      , x_verb        , "GLOBAL");
   yUNIT_minval   ("... check index"                     , x_indx        , 999);
   yUNIT_minchr   ("... check spec"                      , x_spec        , 's');
   yUNIT_minchr   ("... check location"                  , x_locn        , 'm');
   yUNIT_minpoint ("... check conv pointer"              , x_conv        , CONV_global);
   yUNIT_minpoint ("... check code pointer"              , x_code        , CODE_global);
   yUNIT_minstr   ("... check error message"             , yURG_err_last (), "");
   yUNIT_mindnoc  ();

   yURG_err_clear ();
   yUNIT_mincond  ("attempt parsing a SHARED (normal only) verb with suffix");
   yURG_err_clear ();
   yUNIT_minval   ("parse SHARED (in master)"            , VERB_parse ("koios", 95, "SHARED -a-" , x_verb, &x_indx, &x_spec, &x_locn, &x_conv, &x_code), -999);
   yUNIT_minstr   ("... check verb"                      , x_verb        , "");
   yUNIT_minval   ("... check index"                     , x_indx        , -999);
   yUNIT_minchr   ("... check spec"                      , x_spec        , '-');
   yUNIT_minchr   ("... check location"                  , x_locn        , '-');
   yUNIT_minpoint ("... check conv pointer"              , x_conv        , NULL);
   yUNIT_minpoint ("... check code pointer"              , x_code        , NULL);
   yUNIT_minstr   ("... check error message"             , yURG_err_last (), "koios:95:0: error: verb �SHARED� good, but not allowed inside master.unit");
   yUNIT_mindnoc  ();

   yUNIT_minprcs ();
   return 0;
}

char
koios__unit_verb_ditto   (char a_list)
{
   yUNIT_minscrp ("VERB_dittoable");
   if (a_list == 'y')  return 0;
   yURG_err_none ();

   yURG_err_clear ();
   yUNIT_mincond  ("verify non-dittoable verbs");
   yUNIT_minval   ("call for SCRP"                       , VERB_dittoable ("SCRP"       ), 0);
   yUNIT_minval   ("call for COND"                       , VERB_dittoable ("COND"       ), 0);
   yUNIT_minval   ("call for local"                      , VERB_dittoable ("local"      ), 0);
   yUNIT_mindnoc  () ;

   yURG_err_clear ();
   yUNIT_mincond  ("verify dittoable verbs");
   yUNIT_minval   ("call for exec"                       , VERB_dittoable ("exec"       ), 1);
   yUNIT_minval   ("call for system"                     , VERB_dittoable ("system"     ), 1);
   yUNIT_minval   ("call for echo"                       , VERB_dittoable ("echo"       ), 1);
   yUNIT_minval   ("call for file"                       , VERB_dittoable ("file"       ), 1);
   yUNIT_mindnoc  () ;

   yURG_err_clear ();
   yUNIT_mincond  ("attempt non-existant verbs");
   yUNIT_minval   ("call for trouble"                    , VERB_dittoable ("trouble"    ), 0);
   yUNIT_minval   ("call for hazmat"                     , VERB_dittoable ("hazmat"     ), 0);
   yUNIT_minval   ("call for comment"                    , VERB_dittoable ("#huh"       ), 0);
   yUNIT_mindnoc  () ;

   yURG_err_clear ();
   yUNIT_mincond  ("attempt empty and null");
   yUNIT_minval   ("call for null"                       , VERB_dittoable (NULL         ), 0);
   yUNIT_minval   ("call for empty"                      , VERB_dittoable (""           ), 0);
   yUNIT_mindnoc  () ;

   yUNIT_minprcs ();
   return 0;
}



/*====================------------------------------------====================*/
/*===----                      script reading                          ----===*/
/*====================------------------------------------====================*/
static void      o___READ____________________o (void) {;}

char
koios__unit_read_open    (char a_list)
{
   char         x_name     [LEN_HUND] = "/tmp/koios.unit";
   FILE        *x_file     = NULL;
   int          x_line     =    0;
   char         t          [LEN_HUND] = "";

   yUNIT_minscrp ("READ_open, READ_close");
   if (a_list == 'y')  return 0;
   yURG_err_none ();  /* not to stderr/terminal */

   sprintf (t, "rm -f %s 2> /dev/null", x_name);
   system (t);
   yUNIT_mincond ("prepare clean start");
   yUNIT_mindnoc ();

   x_line = 25;
   yURG_err_clear ();
   yUNIT_mincond  ("attempt to open a null name");
   yUNIT_minpoint ("... check script pointer"           , x_file        , 0);
   yUNIT_minval   ("... check line number"              , x_line        , 25);
   yUNIT_minval   ("open the script file"               , READ_open   (NULL  , 'r', &x_file, &x_line), -999);
   yUNIT_minpoint ("... check script pointer"           , x_file        , 0);
   yUNIT_minval   ("... check line number"              , x_line        , 0);
   yUNIT_minstr   ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc  ();

   x_line = 35;
   yURG_err_clear ();
   yUNIT_mincond  ("attempt to open with no name");
   yUNIT_minpoint ("... check script pointer"           , x_file        , 0);
   yUNIT_minval   ("... check line number"              , x_line        , 35);
   yUNIT_minval   ("open the script file"               , READ_open   (""    , 'r', &x_file, &x_line), -999);
   yUNIT_minpoint ("... check script pointer"           , x_file        , 0);
   yUNIT_minval   ("... check line number"              , x_line        , 0);
   yUNIT_minstr   ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc  ();

   x_line = 45;
   yURG_err_clear ();
   yUNIT_mincond  ("attempt to open with a non-existant file");
   yUNIT_minpoint ("... check script pointer"           , x_file        , 0);
   yUNIT_minval   ("... check line number"              , x_line        , 45);
   yUNIT_minval   ("open the script file"               , READ_open   (x_name, 'r', &x_file, &x_line), -999);
   yUNIT_minpoint ("... check script pointer"           , x_file        , 0);
   yUNIT_minval   ("... check line number"              , x_line        , 0);
   yUNIT_minstr   ("... check error message"            , yURG_err_last (), "file �/tmp/koios.unit� could not be openned");
   yUNIT_mindnoc  ();

   sprintf (t, "touch %s", x_name);
   system (t);
   x_line = 55;
   yURG_err_clear ();
   yUNIT_mincond  ("verify openning a valid file");
   yUNIT_minpoint ("... check script pointer"           , x_file        , 0);
   yUNIT_minval   ("... check line number"              , x_line        , 55);
   yUNIT_minval   ("open the script file"               , READ_open   (x_name, 'r', &x_file, &x_line), 0);
   yUNIT_minpoint ("... check script pointer"           , x_file        , 1);
   yUNIT_minval   ("... check line number"              , x_line        , 0);
   yUNIT_minstr   ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc  ();

   x_line = 65;
   yURG_err_clear ();
   yUNIT_mincond  ("attempt to re-open an open file");
   yUNIT_minpoint ("... check script pointer"           , x_file        , 1);
   yUNIT_minval   ("... check line number"              , x_line        , 65);
   yUNIT_minval   ("open the script file"               , READ_open   (x_name, 'r', &x_file, &x_line), -999);
   yUNIT_minpoint ("... check script pointer"           , x_file        , 1);
   yUNIT_minval   ("... check line number"              , x_line        , 0);
   yUNIT_minstr   ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc  ();

   yURG_err_clear ();
   yUNIT_mincond  ("verify closing an open file");
   yUNIT_minpoint ("... check script pointer"           , x_file        , 1);
   yUNIT_minval   ("... check line number"              , x_line        , 0);
   yUNIT_minval   ("close the script file"              , READ_close  (&x_file)                 , 0);
   yUNIT_minpoint ("... check script pointer"           , x_file        , 0);
   yUNIT_minval   ("... check line number"              , x_line        , 0);
   yUNIT_minstr   ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc  ();

   yURG_err_clear ();
   yUNIT_mincond  ("attempt to re-close a closed file");
   yUNIT_minpoint ("... check script pointer"           , x_file        , 0);
   yUNIT_minval   ("... check line number"              , x_line        , 0);
   yUNIT_minval   ("open the script file"               , READ_close  (&x_file)                 , -999);
   yUNIT_minpoint ("... check script pointer"           , x_file        , 0);
   yUNIT_minval   ("... check line number"              , x_line        , 0);
   yUNIT_minstr   ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc  ();

   sprintf (t, "rm -f %s 2> /dev/null", x_name);
   system (t);
   yUNIT_mincond ("clean up after");
   yUNIT_mindnoc ();

   yUNIT_minprcs ();
   return 0;
}

char
koios__unit_read_defense (char a_list)
{
   char         x_name     [LEN_HUND] = "/tmp/koios.unit";
   FILE        *x_file     = 0xFF;
   int          x_line     =    0;
   char         x_dittoing =  '-';
   char         x_dmark    =  '-';
   int          x_ditto    =    0;
   int          x_dline    =    0;
   int          x_nrecd    =    0;
   int          x_len      =    0;
   char         x_recd     [LEN_RECD] = "";

   yUNIT_minscrp  ("READ__defense");
   if (a_list == 'y')  return 0;
   yURG_err_none  ();  /* not to stderr/terminal */

   yUNIT_mincond  ("attempt with various nulls");
   yUNIT_minval   ("call defense"                       , READ__defense (NULL   , &x_line, &x_dittoing, &x_dmark, &x_ditto, &x_dline, &x_nrecd, x_recd), -999);
   yUNIT_minval   ("call defense"                       , READ__defense (&x_file, NULL   , &x_dittoing, &x_dmark, &x_ditto, &x_dline, &x_nrecd, x_recd), -999);
   yUNIT_minval   ("call defense"                       , READ__defense (&x_file, &x_line, NULL       , &x_dmark, &x_ditto, &x_dline, &x_nrecd, x_recd), -999);
   yUNIT_minval   ("call defense"                       , READ__defense (&x_file, &x_line, &x_dittoing, NULL    , &x_ditto, &x_dline, &x_nrecd, x_recd), -999);
   yUNIT_minval   ("call defense"                       , READ__defense (&x_file, &x_line, &x_dittoing, &x_dmark, NULL    , &x_dline, &x_nrecd, x_recd), -999);
   yUNIT_minval   ("call defense"                       , READ__defense (&x_file, &x_line, &x_dittoing, &x_dmark, &x_ditto, NULL    , &x_nrecd, x_recd), -999);
   yUNIT_minval   ("call defense"                       , READ__defense (&x_file, &x_line, &x_dittoing, &x_dmark, &x_ditto, &x_dline, NULL    , x_recd), -999);
   yUNIT_minval   ("call defense"                       , READ__defense (&x_file, &x_line, &x_dittoing, &x_dmark, &x_ditto, &x_dline, &x_nrecd, NULL  ), -999);
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify a quick success");
   yUNIT_minval   ("call defense"                       , READ__defense (&x_file, &x_line, &x_dittoing, &x_dmark, &x_ditto, &x_dline, &x_nrecd, x_recd), 0);
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("attempt to call with un-open file");
   x_file = NULL;
   yUNIT_minval   ("call defense"                       , READ__defense (&x_file, &x_line, &x_dittoing, &x_dmark, &x_ditto, &x_dline, &x_nrecd, x_recd), -999);
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("attempt to read an empty file");
   yUNIT_mindnoc  ();

   yUNIT_minprcs  ();
   return 0;
}

char
koios__unit_read_single  (char a_list)
{
   char         x_name     [LEN_HUND] = "/tmp/koios.unit";
   FILE        *x_file     = NULL;
   int          x_line     =    0;
   char         x_dittoing =  '-';
   char         x_dmark    =  '-';
   int          x_ditto    =    0;
   int          x_dline    =    0;
   int          x_nrecd    =    0;
   int          x_len      =    0;
   char         x_recd     [LEN_RECD] = "";

   yUNIT_minscrp ("READ_single");
   if (a_list == 'y')  return 0;
   yURG_err_none ();  /* not to stderr/terminal */
   system ("rm -f /tmp/koios.unit 2> /dev/null");

   yUNIT_mincond  ("verify reading a single record");
   system ("echo \"exec     read a line      SCRP_read       i_lesser    0      \"                                             > /tmp/koios.unit");
   yUNIT_minval   ("open the script file"               , READ_open    (x_name, 'r', &x_file, &x_line), 0);
   yUNIT_minval   ("... line"                           , x_line                   ,    0);
   yUNIT_minchr   ("... dittoing"                       , x_dittoing               ,  '-');
   yUNIT_minchr   ("... dmark"                          , x_dmark                  ,  '-');
   yUNIT_minval   ("... ditto"                          , x_ditto                  ,    0);
   yUNIT_minval   ("... dline"                          , x_dline                  ,    0);
   yUNIT_minval   ("... nrecd"                          , x_nrecd                  ,    0);
   yUNIT_minval   ("read the line"                      , READ__single  (&x_file, &x_line, &x_dittoing, &x_dmark, &x_ditto, &x_dline, &x_nrecd, x_recd), 1);
   yUNIT_minval   ("close the script file"              , READ_close  (&x_file), 0);
   yUNIT_minval   ("... line"                           , x_line                   ,    1);
   yUNIT_minchr   ("... dittoing"                       , x_dittoing               ,  '-');
   yUNIT_minchr   ("... dmark"                          , x_dmark                  ,  '-');
   yUNIT_minval   ("... ditto"                          , x_ditto                  ,    0);
   yUNIT_minval   ("... dline"                          , x_dline                  ,    0);
   yUNIT_minval   ("... nrecd"                          , x_nrecd                  ,    1);
   strlencode (x_recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr   ("... check the record"               , x_recd        , "exec    � read a line     � SCRP_read   �   � i_lesser   � 0      �");
   yUNIT_minstr   ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify an empty line");
   system ("echo \"\"                                                                                                                       > /tmp/koios.unit");
   yUNIT_minval   ("open the script file"               , READ_open    (x_name, 'r', &x_file, &x_line), 0);
   yUNIT_minval   ("... line"                           , x_line                   ,    0);
   yUNIT_minchr   ("... dittoing"                       , x_dittoing               ,  '-');
   yUNIT_minchr   ("... dmark"                          , x_dmark                  ,  '-');
   yUNIT_minval   ("... ditto"                          , x_ditto                  ,    0);
   yUNIT_minval   ("... dline"                          , x_dline                  ,    0);
   yUNIT_minval   ("... nrecd"                          , x_nrecd                  ,    1);
   yUNIT_minval   ("read the line"                      , READ__single  (&x_file, &x_line, &x_dittoing, &x_dmark, &x_ditto, &x_dline, &x_nrecd, x_recd), 2);
   yUNIT_minval   ("close the script file"              , READ_close  (&x_file), 0);
   yUNIT_minval   ("... line"                           , x_line                   ,    1);
   yUNIT_minchr   ("... dittoing"                       , x_dittoing               ,  '-');
   yUNIT_minchr   ("... dmark"                          , x_dmark                  ,  '-');
   yUNIT_minval   ("... ditto"                          , x_ditto                  ,    0);
   yUNIT_minval   ("... dline"                          , x_dline                  ,    0);
   yUNIT_minval   ("... nrecd"                          , x_nrecd                  ,    1);
   strlencode (x_recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr   ("... check the record"               , x_recd        , "");
   yUNIT_minstr   ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify another good line");
   system ("echo \"SCRP     testing          0s    tbd    - - - - -  \"                                                       > /tmp/koios.unit");
   yUNIT_minval   ("open the script file"               , READ_open    (x_name, 'r', &x_file, &x_line), 0);
   yUNIT_minval   ("... line"                           , x_line                   ,    0);
   yUNIT_minchr   ("... dittoing"                       , x_dittoing               ,  '-');
   yUNIT_minchr   ("... dmark"                          , x_dmark                  ,  '-');
   yUNIT_minval   ("... ditto"                          , x_ditto                  ,    0);
   yUNIT_minval   ("... dline"                          , x_dline                  ,    0);
   yUNIT_minval   ("... nrecd"                          , x_nrecd                  ,    1);
   yUNIT_minval   ("read the line"                      , READ__single  (&x_file, &x_line, &x_dittoing, &x_dmark, &x_ditto, &x_dline, &x_nrecd, x_recd), 1);
   yUNIT_minval   ("close the script file"              , READ_close  (&x_file), 0);
   yUNIT_minval   ("... line"                           , x_line                   ,    1);
   yUNIT_minchr   ("... dittoing"                       , x_dittoing               ,  '-');
   yUNIT_minchr   ("... dmark"                          , x_dmark                  ,  '-');
   yUNIT_minval   ("... ditto"                          , x_ditto                  ,    0);
   yUNIT_minval   ("... dline"                          , x_dline                  ,    0);
   yUNIT_minval   ("... nrecd"                          , x_nrecd                  ,    2);
   strlencode (x_recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr   ("... check the record"               , x_recd        , "SCRP    � testing         � 0s  �  tbd   � - - - - -  �");
   yUNIT_minstr   ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify a comment");
   system ("echo \"## the descripion of something else\"                                                                              > /tmp/koios.unit");
   yUNIT_minval   ("open the script file"               , READ_open    (x_name, 'r', &x_file, &x_line), 0);
   yUNIT_minval   ("... line"                           , x_line                   ,    0);
   yUNIT_minchr   ("... dittoing"                       , x_dittoing               ,  '-');
   yUNIT_minchr   ("... dmark"                          , x_dmark                  ,  '-');
   yUNIT_minval   ("... ditto"                          , x_ditto                  ,    0);
   yUNIT_minval   ("... dline"                          , x_dline                  ,    0);
   yUNIT_minval   ("... nrecd"                          , x_nrecd                  ,    2);
   yUNIT_minval   ("read the line"                      , READ__single  (&x_file, &x_line, &x_dittoing, &x_dmark, &x_ditto, &x_dline, &x_nrecd, x_recd), 2);
   yUNIT_minval   ("close the script file"              , READ_close  (&x_file), 0);
   yUNIT_minval   ("... line"                           , x_line                   ,    1);
   yUNIT_minchr   ("... dittoing"                       , x_dittoing               ,  '-');
   yUNIT_minchr   ("... dmark"                          , x_dmark                  ,  '-');
   yUNIT_minval   ("... ditto"                          , x_ditto                  ,    0);
   yUNIT_minval   ("... dline"                          , x_dline                  ,    0);
   yUNIT_minval   ("... nrecd"                          , x_nrecd                  ,    2);
   strlencode (x_recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr   ("... check the record"               , x_recd        , "");
   yUNIT_minstr   ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify a short line");
   system ("echo \"SCRP\"                                                                                                             > /tmp/koios.unit");
   yUNIT_minval   ("open the script file"               , READ_open    (x_name, 'r', &x_file, &x_line), 0);
   yUNIT_minval   ("... line"                           , x_line                   ,    0);
   yUNIT_minchr   ("... dittoing"                       , x_dittoing               ,  '-');
   yUNIT_minchr   ("... dmark"                          , x_dmark                  ,  '-');
   yUNIT_minval   ("... ditto"                          , x_ditto                  ,    0);
   yUNIT_minval   ("... dline"                          , x_dline                  ,    0);
   yUNIT_minval   ("... nrecd"                          , x_nrecd                  ,    2);
   yUNIT_minval   ("read the line"                      , READ__single  (&x_file, &x_line, &x_dittoing, &x_dmark, &x_ditto, &x_dline, &x_nrecd, x_recd), 2);
   yUNIT_minval   ("close the script file"              , READ_close  (&x_file), 0);
   yUNIT_minval   ("... line"                           , x_line                   ,    1);
   yUNIT_minchr   ("... dittoing"                       , x_dittoing               ,  '-');
   yUNIT_minchr   ("... dmark"                          , x_dmark                  ,  '-');
   yUNIT_minval   ("... ditto"                          , x_ditto                  ,    0);
   yUNIT_minval   ("... dline"                          , x_dline                  ,    0);
   yUNIT_minval   ("... nrecd"                          , x_nrecd                  ,    2);
   strlencode (x_recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr   ("... check the record"               , x_recd        , "");
   yUNIT_minstr   ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify at end-of-file");
   system ("rm -f /tmp/koios.unit 2> /dev/null");
   system ("touch /tmp/koios.unit");
   yUNIT_minval   ("open the script file"               , READ_open    (x_name, 'r', &x_file, &x_line), 0);
   yUNIT_minval   ("... line"                           , x_line                   ,    0);
   yUNIT_minchr   ("... dittoing"                       , x_dittoing               ,  '-');
   yUNIT_minchr   ("... dmark"                          , x_dmark                  ,  '-');
   yUNIT_minval   ("... ditto"                          , x_ditto                  ,    0);
   yUNIT_minval   ("... dline"                          , x_dline                  ,    0);
   yUNIT_minval   ("... nrecd"                          , x_nrecd                  ,    2);
   yUNIT_minval   ("read the line"                      , READ__single  (&x_file, &x_line, &x_dittoing, &x_dmark, &x_ditto, &x_dline, &x_nrecd, x_recd), 0);
   yUNIT_minval   ("close the script file"              , READ_close  (&x_file), 0);
   yUNIT_minval   ("... line"                           , x_line                   ,    0);
   yUNIT_minchr   ("... dittoing"                       , x_dittoing               ,  '-');
   yUNIT_minchr   ("... dmark"                          , x_dmark                  ,  '-');
   yUNIT_minval   ("... ditto"                          , x_ditto                  ,    0);
   yUNIT_minval   ("... dline"                          , x_dline                  ,    0);
   yUNIT_minval   ("... nrecd"                          , x_nrecd                  ,    2);
   strlencode (x_recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr   ("... check the record"               , x_recd        , "");
   yUNIT_minstr   ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc  ();

   yUNIT_mincond ("clean up after");
   system ("rm -f /tmp/koios.unit 2> /dev/null");
   yUNIT_mindnoc ();

   yUNIT_minprcs ();
   return 0;
}

char
koios__unit_read_end_ditto  (char a_list)
{
   char         x_name     [LEN_HUND] = "/tmp/koios.unit";
   FILE        *x_file     = NULL;
   FILE        *x_main     = NULL;
   FILE        *x_save     = NULL;
   int          x_line     =    0;
   char         x_dittoing =  '-';
   char         x_dmark    =  '-';
   int          x_ditto    =    0;
   int          x_dline    =    0;
   int          x_nrecd    =    0;
   char         x_mark     =  '-';
   char         x_recd     [LEN_RECD] = "";

   yUNIT_minscrp ("READ__single, DITTO_end");
   if (a_list == 'y')  return 0;
   yURG_err_none ();  /* not to stderr/terminal */
   system ("rm -f /tmp/koios.unit 2> /dev/null");

   PROG__unit_quiet  ();

   yUNIT_mincond  ("create a test script");
   system ("echo \"\"                                                                                                                       >> /tmp/koios.unit");
   system ("echo \"COND  (0)  ditto stuff     \"                                                                                        >> /tmp/koios.unit");
   system ("echo \"  exec     read a line      SCRP_read       i_lesser    0      \"                                            >> /tmp/koios.unit");
   system ("echo \"\"                                                                                                                       >> /tmp/koios.unit");
   system ("echo \"DITTO (0)  - - - - - - - - \"                                                                                        >> /tmp/koios.unit");
   system ("echo \"\"                                                                                                                       >> /tmp/koios.unit");
   system ("echo \"  get      next step        SCRP_read       i_lesser    0      \"                                            >> /tmp/koios.unit");
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("open script, roll forward to DITTO, then start a ditto");
   yUNIT_minval   ("open the script file"               , READ_open    (x_name, 'r', &x_file, &x_line), 0);
   x_main     = x_file;
   fgets (x_recd, LEN_RECD, x_main);
   fgets (x_recd, LEN_RECD, x_main);
   fgets (x_recd, LEN_RECD, x_main);
   fgets (x_recd, LEN_RECD, x_main);
   fgets (x_recd, LEN_RECD, x_main);
   x_line     =    5;
   yUNIT_minval   ("call ditto begin"                   , DITTO_beg    (x_name, x_line, x_name, G_RUN_CREATE ,    2, '0', &x_file, &x_dittoing, &x_dmark, &x_mark, &x_ditto, &x_dline)    , 1);
   x_save     = x_file;
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify reading from the top again");
   yUNIT_minval   ("... line"                           , x_line                   ,    5);
   yUNIT_minchr   ("... dittoing"                       , x_dittoing               ,  'y');
   yUNIT_minchr   ("... dmark"                          , x_dmark                  ,  '0');
   yUNIT_minval   ("... ditto"                          , x_ditto                  ,    2);
   yUNIT_minval   ("... dline"                          , x_dline                  ,    0);
   yUNIT_minval   ("... nrecd"                          , x_nrecd                  ,    0);
   yUNIT_minval   ("read the line"                      , READ__single  (&x_file, &x_line, &x_dittoing, &x_dmark, &x_ditto, &x_dline, &x_nrecd, x_recd), 2);
   yUNIT_minpoint ("... file"                           , x_file                   , x_save);
   yUNIT_minval   ("... line"                           , x_line                   ,    5);
   yUNIT_minchr   ("... dittoing"                       , x_dittoing               ,  'y');
   yUNIT_minchr   ("... dmark"                          , x_dmark                  ,  '0');
   yUNIT_minval   ("... ditto"                          , x_ditto                  ,    2);
   yUNIT_minval   ("... dline"                          , x_dline                  ,    1);
   yUNIT_minval   ("... nrecd"                          , x_nrecd                  ,    0);
   strlencode (x_recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr   ("... check the record"               , x_recd        , "");
   yUNIT_minstr   ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify a record to continue ditto");
   yUNIT_minval   ("... line"                           , x_line                   ,    5);
   yUNIT_minchr   ("... dittoing"                       , x_dittoing               ,  'y');
   yUNIT_minchr   ("... dmark"                          , x_dmark                  ,  '0');
   yUNIT_minval   ("... ditto"                          , x_ditto                  ,    2);
   yUNIT_minval   ("... dline"                          , x_dline                  ,    1);
   yUNIT_minval   ("... nrecd"                          , x_nrecd                  ,    0);
   yUNIT_minval   ("read the line"                      , READ__single  (&x_file, &x_line, &x_dittoing, &x_dmark, &x_ditto, &x_dline, &x_nrecd, x_recd), 2);
   yUNIT_minpoint ("... file"                           , x_file                   , x_save);
   yUNIT_minval   ("... line"                           , x_line                   ,    5);
   yUNIT_minchr   ("... dittoing"                       , x_dittoing               ,  'y');
   yUNIT_minchr   ("... dmark"                          , x_dmark                  ,  '0');
   yUNIT_minval   ("... ditto"                          , x_ditto                  ,    2);
   yUNIT_minval   ("... dline"                          , x_dline                  ,    2);
   yUNIT_minval   ("... nrecd"                          , x_nrecd                  ,    0);
   strlencode (x_recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr   ("... check the record"               , x_recd        , "");
   yUNIT_minstr   ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify another continuation of ditto");
   yUNIT_minval   ("read the line"                      , READ__single  (&x_file, &x_line, &x_dittoing, &x_dmark, &x_ditto, &x_dline, &x_nrecd, x_recd), 1);
   yUNIT_minpoint ("... file"                           , x_file                   , x_save);
   yUNIT_minval   ("... line"                           , x_line                   ,    5);
   yUNIT_minchr   ("... dittoing"                       , x_dittoing               ,  'y');
   yUNIT_minchr   ("... dmark"                          , x_dmark                  ,  '0');
   yUNIT_minval   ("... ditto"                          , x_ditto                  ,    2);
   yUNIT_minval   ("... dline"                          , x_dline                  ,    3);
   yUNIT_minval   ("... nrecd"                          , x_nrecd                  ,    1);
   strlencode (x_recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr   ("... check the record"               , x_recd        , "  exec    � read a line     � SCRP_read   �   � i_lesser   � 0      �");
   yUNIT_minstr   ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify an empty line ends ditto");
   yUNIT_minval   ("read the line"                      , READ__single  (&x_file, &x_line, &x_dittoing, &x_dmark, &x_ditto, &x_dline, &x_nrecd, x_recd), 2);
   yUNIT_minpoint ("... file"                           , x_file                   , x_main);
   yUNIT_minval   ("... line"                           , x_line                   ,    5);
   yUNIT_minchr   ("... dittoing"                       , x_dittoing               ,  '-');
   yUNIT_minchr   ("... dmark"                          , x_dmark                  ,  '-');
   yUNIT_minval   ("... ditto"                          , x_ditto                  ,   -1);
   yUNIT_minval   ("... dline"                          , x_dline                  ,   -1);
   yUNIT_minval   ("... nrecd"                          , x_nrecd                  ,    1);
   strlencode (x_recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr   ("... check the record"               , x_recd        , "");
   yUNIT_minstr   ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify empty line after ditto");
   yUNIT_minval   ("read the line"                      , READ__single  (&x_file, &x_line, &x_dittoing, &x_dmark, &x_ditto, &x_dline, &x_nrecd, x_recd), 2);
   yUNIT_minpoint ("... file"                           , x_file                   , x_main);
   yUNIT_minval   ("... line"                           , x_line                   ,    6);
   yUNIT_minchr   ("... dittoing"                       , x_dittoing               ,  '-');
   yUNIT_minchr   ("... dmark"                          , x_dmark                  ,  '-');
   yUNIT_minval   ("... ditto"                          , x_ditto                  ,   -1);
   yUNIT_minval   ("... dline"                          , x_dline                  ,   -1);
   yUNIT_minval   ("... nrecd"                          , x_nrecd                  ,    1);
   strlencode (x_recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr   ("... check the record"               , x_recd        , "");
   yUNIT_minstr   ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify reading the next line");
   yUNIT_minval   ("read the line"                      , READ__single  (&x_file, &x_line, &x_dittoing, &x_dmark, &x_ditto, &x_dline, &x_nrecd, x_recd), 1);
   yUNIT_minpoint ("... file"                           , x_file                   , x_main);
   yUNIT_minval   ("... line"                           , x_line                   ,    7);
   yUNIT_minchr   ("... dittoing"                       , x_dittoing               ,  '-');
   yUNIT_minchr   ("... dmark"                          , x_dmark                  ,  '-');
   yUNIT_minval   ("... ditto"                          , x_ditto                  ,   -1);
   yUNIT_minval   ("... dline"                          , x_dline                  ,   -1);
   yUNIT_minval   ("... nrecd"                          , x_nrecd                  ,    2);
   strlencode (x_recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr   ("... check the record"               , x_recd        , "  get     � next step       � SCRP_read   �   � i_lesser   � 0      �");
   yUNIT_minstr   ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("close out the script");
   yUNIT_minval   ("close the script file"              , READ_close  (&x_file), 0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("clean up after");
   system ("rm -f /tmp/koios.unit 2> /dev/null");
   yUNIT_mindnoc ();

   PROG__unit_end    ();

   yUNIT_minprcs ();
   return 0;
}

char
koios__unit_read_driver  (char a_list)
{
   char         x_name     [LEN_HUND] = "/tmp/koios.unit";
   FILE        *x_file     = NULL;
   int          x_line     =    0;
   char         x_dittoing =  '-';
   char         x_dmark    =  '-';
   int          x_ditto    =    0;
   int          x_dline    =    0;
   int          x_nrecd    =    0;
   int          x_len      =    0;
   char         x_recd     [LEN_RECD] = "";

   yUNIT_minscrp ("READ_driver");
   if (a_list == 'y')  return 0;
   yURG_err_none ();  /* not to stderr/terminal */
   system ("rm -f /tmp/koios.unit 2> /dev/null");

   yUNIT_mincond  ("create an input file");
   system ("echo \"##\"                                                                                                                                                                                                                                                                                                                                  > /tmp/koios.unit");
   system ("echo \"\"                                                                                                                                                                                                                                                                                                                                   >> /tmp/koios.unit");
   system ("echo \"SCRP          (CATS) verify preparation and defaulting                           0s   prepare         CATS__prepare                                                                ((01.---))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  \"                 >> /tmp/koios.unit");
   system ("echo \"\"                                                                                                                                                                                                                                                                                                                                   >> /tmp/koios.unit");
   system ("echo \"   COND  (0)  verify the defaults                                                - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((01.001))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  \"                 >> /tmp/koios.unit");
   system ("echo \"     exec     call prepare                         CATS__prepare               \\\"� �  � � �   � �\\\"   , &x_len , &x_part, &x_sub , &x_src , &x_cat , &x_page, &x_grp , &x_freq         i_equal     0                                                                                                    \"           >> /tmp/koios.unit");
   system ("echo \"\"                                                                                                                                                                                                                                                                                                                                   >> /tmp/koios.unit");
   system ("echo \"   COND       make global changes                                                - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((01.001))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  \"                 >> /tmp/koios.unit");
   system ("echo \"     code     ... change part                      - - - - - - - - - - - - -   x_part      = 'v';                                                                                                                                                                                                         \"                 >> /tmp/koios.unit");
   system ("echo \"\"                                                                                                                                                                                                                                                                                                                                   >> /tmp/koios.unit");
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("open the script");
   yUNIT_minval   ("open the script file"               , READ_open    (x_name, 'r', &x_file, &x_line), 0);
   yUNIT_mindnoc  ();

   yURG_err_clear ();
   yUNIT_mincond  ("verify first good line");
   yUNIT_minval   ("... line"                           , x_line                   ,    0);
   yUNIT_minval   ("... nrecd"                          , x_nrecd                  ,    0);
   yUNIT_minval   ("read the line"                      , READ_next    (&x_file, &x_line, &x_dittoing, &x_dmark, &x_ditto, &x_dline, &x_nrecd, x_recd),    1);
   yUNIT_minval   ("... line"                           , x_line                   ,    3);
   yUNIT_minval   ("... nrecd"                          , x_nrecd                  ,    1);
   strlencode (x_recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr   ("... check the record"               , x_recd        , "SCRP         � (CATS) verify preparation and defaulting                          � 0s  � prepare        � CATS__prepare                                                               � ((01.---)) � - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  �");
   yUNIT_minstr   ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc  ();

   yURG_err_clear ();
   yUNIT_mincond  ("verify next good line");
   yUNIT_minval   ("read the line"                      , READ_next    (&x_file, &x_line, &x_dittoing, &x_dmark, &x_ditto, &x_dline, &x_nrecd, x_recd),    1);
   yUNIT_minval   ("... line"                           , x_line                   ,    5);
   yUNIT_minval   ("... nrecd"                          , x_nrecd                  ,    2);
   strlencode (x_recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr   ("... check the record"               , x_recd        , "   COND  (0) � verify the defaults                                               � - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  � ((01.001)) � - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  �");
   yUNIT_minstr   ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc  ();

   yURG_err_clear ();
   yUNIT_mincond  ("verify next good line");
   yUNIT_minval   ("read the line"                      , READ_next    (&x_file, &x_line, &x_dittoing, &x_dmark, &x_ditto, &x_dline, &x_nrecd, x_recd),    1);
   yUNIT_minval   ("... line"                           , x_line                   ,    6);
   yUNIT_minval   ("... nrecd"                          , x_nrecd                  ,    3);
   strlencode (x_recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr   ("... check the record"               , x_recd        , "     exec    � call prepare                        � CATS__prepare              � \"� �  � � �   � �\"   , &x_len , &x_part, &x_sub , &x_src , &x_cat , &x_page, &x_grp , &x_freq        � i_equal    � 0                                                                                                    �");
   yUNIT_minstr   ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc  ();

   yURG_err_clear ();
   yUNIT_mincond  ("verify next good line");
   yUNIT_minval   ("read the line"                      , READ_next    (&x_file, &x_line, &x_dittoing, &x_dmark, &x_ditto, &x_dline, &x_nrecd, x_recd),    1);
   yUNIT_minval   ("... line"                           , x_line                   ,    8);
   yUNIT_minval   ("... nrecd"                          , x_nrecd                  ,    4);
   strlencode (x_recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr   ("... check the record"               , x_recd        , "   COND      � make global changes                                               � - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  � ((01.001)) � - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  �");
   yUNIT_minstr   ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc  ();

   yURG_err_clear ();
   yUNIT_mincond  ("verify next good line");
   yUNIT_minval   ("read the line"                      , READ_next    (&x_file, &x_line, &x_dittoing, &x_dmark, &x_ditto, &x_dline, &x_nrecd, x_recd),    1);
   yUNIT_minval   ("... line"                           , x_line                   ,    9);
   yUNIT_minval   ("... nrecd"                          , x_nrecd                  ,    5);
   strlencode (x_recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr   ("... check the record"               , x_recd        , "     code    � ... change part                     � - - - - - - - - - - - - -  � x_part      = 'v';                                                                                                                                                                                                         �");
   yUNIT_minstr   ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc  ();

   yURG_err_clear ();
   yUNIT_mincond  ("verify hitting end-of-file");
   yUNIT_minval   ("read the line"                      , READ_next    (&x_file, &x_line, &x_dittoing, &x_dmark, &x_ditto, &x_dline, &x_nrecd, x_recd),    0);
   yUNIT_minval   ("... line"                           , x_line                   ,   10);
   yUNIT_minval   ("... nrecd"                          , x_nrecd                  ,    5);
   strlencode (x_recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr   ("... check the record"               , x_recd        , "");
   yUNIT_minstr   ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("close out the script");
   yUNIT_minval   ("close the script file"              , READ_close  (&x_file), 0);
   system ("rm -f /tmp/koios.unit 2> /dev/null");
   yUNIT_mindnoc ();

   yUNIT_minprcs ();
   return 0;
}



/*====================------------------------------------====================*/
/*===----                        record parsing                        ----===*/
/*====================------------------------------------====================*/
static void      o___PARSE___________________o (void) {;}

char
koios__unit_parse_field  (char a_list)
{
   char        x_spec      =  '-';
   char        x_max       =    0;
   char        x_desc      [LEN_LONG]  = "";
   char        x_meth      [LEN_HUND]  = "";
   char        x_args      [LEN_FULL]  = "";
   char        x_test      [LEN_LABEL] = "";
   char        x_expe      [LEN_RECD]  = "";
   char        x_retn      [LEN_FULL]  = "";

   yUNIT_minscrp ("PARSE__field");
   if (a_list == 'y')  return 0;
   yURG_err_none ();

   x_spec = 's';  x_max = 2;
   yUNIT_mincond  ("verify script success");
   yUNIT_minval   ("set defaults"                       , PARSE__default  (x_desc, x_meth, x_args, x_test, x_expe, x_retn)                                ,    0);
   yUNIT_minval   ("call parse field"                   , PARSE__field    (1, "SCRP"                     , x_spec, &x_max, x_desc, x_meth, x_args, x_test, x_expe, x_retn), -999);
   yUNIT_minval   ("call parse field"                   , PARSE__field    (2, "check variable"           , x_spec, &x_max, x_desc, x_meth, x_args, x_test, x_expe, x_retn),    0);
   yUNIT_minval   ("call parse field"                   , PARSE__field    (3, "extra"                    , x_spec, &x_max, x_desc, x_meth, x_args, x_test, x_expe, x_retn), -999);
   yUNIT_minval   ("... check max"                      , x_max         , 2);
   yUNIT_minstr   ("... check desc"                     , x_desc        , "check variable");
   yUNIT_minstr   ("... check meth"                     , x_meth        , "");
   yUNIT_minstr   ("... check args"                     , x_args        , "");
   yUNIT_minstr   ("... check test"                     , x_test        , "");
   yUNIT_minstr   ("... check expe"                     , x_expe        , "");
   yUNIT_minstr   ("... check retn"                     , x_retn        , "");
   yUNIT_mindnoc  ();

   x_spec = 'f';  x_max = 7;
   yUNIT_mincond  ("verify exec success");
   yUNIT_minval   ("set defaults"                       , PARSE__default  (x_desc, x_meth, x_args, x_test, x_expe, x_retn)                                ,    0);
   yUNIT_minval   ("call parse field"                   , PARSE__field    (2, "call function"            , x_spec, &x_max, x_desc, x_meth, x_args, x_test, x_expe, x_retn),    0);
   yUNIT_minval   ("call parse field"                   , PARSE__field    (3, "BIG_function"             , x_spec, &x_max, x_desc, x_meth, x_args, x_test, x_expe, x_retn),    0);
   yUNIT_minval   ("call parse field"                   , PARSE__field    (4, "27, 86, 't'"              , x_spec, &x_max, x_desc, x_meth, x_args, x_test, x_expe, x_retn),    0);
   yUNIT_minval   ("call parse field"                   , PARSE__field    (5, "i_equal"                  , x_spec, &x_max, x_desc, x_meth, x_args, x_test, x_expe, x_retn),    0);
   yUNIT_minval   ("call parse field"                   , PARSE__field    (6, "42"                       , x_spec, &x_max, x_desc, x_meth, x_args, x_test, x_expe, x_retn),    0);
   yUNIT_minval   ("call parse field"                   , PARSE__field    (7, "n"                        , x_spec, &x_max, x_desc, x_meth, x_args, x_test, x_expe, x_retn),    0);
   yUNIT_minval   ("call parse field"                   , PARSE__field    (8, "junk at end"              , x_spec, &x_max, x_desc, x_meth, x_args, x_test, x_expe, x_retn), -999);
   yUNIT_minval   ("... check max"                      , x_max         , 7);
   yUNIT_minstr   ("... check desc"                     , x_desc        , "call function");
   yUNIT_minstr   ("... check meth"                     , x_meth        , "BIG_function");
   yUNIT_minstr   ("... check args"                     , x_args        , "27, 86, 't'");
   yUNIT_minstr   ("... check test"                     , x_test        , "i_equal");
   yUNIT_minstr   ("... check expe"                     , x_expe        , "42");
   yUNIT_minstr   ("... check retn"                     , x_retn        , "n");
   yUNIT_mindnoc  ();

   x_spec = 'p';  x_max = 4;
   yUNIT_mincond  ("verify code success");
   yUNIT_minval   ("set defaults"                       , PARSE__default  (x_desc, x_meth, x_args, x_test, x_expe, x_retn)                                ,    0);
   yUNIT_minval   ("call parse field"                   , PARSE__field    (2, "update global"            , x_spec, &x_max, x_desc, x_meth, x_args, x_test, x_expe, x_retn),    0);
   yUNIT_minval   ("call parse field"                   , PARSE__field    (3, "- - - - - - -"            , x_spec, &x_max, x_desc, x_meth, x_args, x_test, x_expe, x_retn),    0);
   yUNIT_minval   ("call parse field"                   , PARSE__field    (4, "my.val = 978;"            , x_spec, &x_max, x_desc, x_meth, x_args, x_test, x_expe, x_retn),    0);
   yUNIT_minval   ("call parse field"                   , PARSE__field    (5, "more stuff"               , x_spec, &x_max, x_desc, x_meth, x_args, x_test, x_expe, x_retn), -999);
   yUNIT_minval   ("... check max"                      , x_max         , 4);
   yUNIT_minstr   ("... check desc"                     , x_desc        , "update global");
   yUNIT_minstr   ("... check meth"                     , x_meth        , "");
   yUNIT_minstr   ("... check args"                     , x_args        , "");
   yUNIT_minstr   ("... check test"                     , x_test        , "");
   yUNIT_minstr   ("... check expe"                     , x_expe        , "my.val = 978;");
   yUNIT_minstr   ("... check retn"                     , x_retn        , "");
   yUNIT_mindnoc  ();

   x_spec = '1';  x_max = 1;
   yUNIT_mincond  ("verify ditto success");
   yUNIT_minval   ("set defaults"                       , PARSE__default  (x_desc, x_meth, x_args, x_test, x_expe, x_retn)                                ,    0);
   yUNIT_minval   ("call parse field"                   , PARSE__field    (2, "update global"            , x_spec, &x_max, x_desc, x_meth, x_args, x_test, x_expe, x_retn), -999);
   yUNIT_minval   ("... check max"                      , x_max         , 1);
   yUNIT_minstr   ("... check desc"                     , x_desc        , "");
   yUNIT_minstr   ("... check meth"                     , x_meth        , "");
   yUNIT_minstr   ("... check args"                     , x_args        , "");
   yUNIT_minstr   ("... check test"                     , x_test        , "");
   yUNIT_minstr   ("... check expe"                     , x_expe        , "");
   yUNIT_minstr   ("... check retn"                     , x_retn        , "");
   yUNIT_mindnoc  ();

   yUNIT_minprcs ();
   return 0;
}

char
koios__unit_parse_current   (char a_list)
{
   char        x_name      [LEN_HUND]  = "/tmp/koios.unit";
   char        x_recd      [LEN_RECD]  = "";
   char        x_desc      [LEN_LONG]  = "";
   char        x_meth      [LEN_HUND]  = "";
   char        x_args      [LEN_FULL]  = "";
   char        x_test      [LEN_LABEL] = "";
   char        x_expe      [LEN_RECD]  = "";
   char        x_retn      [LEN_FULL]  = "";

   yUNIT_minscrp ("PARSE_current");
   if (a_list == 'y')  return 0;
   yURG_err_none ();

   strcpy (x_recd, "SCRP          (CATS) verify preparation and defaulting                           0s   prepare         CATS__prepare                                                                ((01.---))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_mincond  ("verify script success");
   yUNIT_minval   ("call parse"                         , PARSE_current   (x_name,  5, "SCRP", 's', x_recd, x_desc, x_meth, x_args, x_test, x_expe, x_retn),    0);
   yUNIT_minstr   ("... check desc"                     , x_desc        , "(CATS) verify preparation and defaulting");
   yUNIT_minstr   ("... check meth"                     , x_meth        , "CATS__prepare");
   yUNIT_minstr   ("... check args"                     , x_args        , "");
   yUNIT_minstr   ("... check test"                     , x_test        , "0s");
   yUNIT_minstr   ("... check expe"                     , x_expe        , "");
   yUNIT_minstr   ("... check retn"                     , x_retn        , "prepare");
   yUNIT_mindnoc  ();

   strcpy (x_recd, "   COND  (0)  verify the defaults                                                - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((01.001))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_mincond  ("verify condition success");
   yUNIT_minval   ("call parse"                         , PARSE_current   (x_name, 10, "COND", '2', x_recd, x_desc, x_meth, x_args, x_test, x_expe, x_retn),    0);
   yUNIT_minstr   ("... check desc"                     , x_desc        , "verify the defaults");
   yUNIT_minstr   ("... check meth"                     , x_meth        , "");
   yUNIT_minstr   ("... check args"                     , x_args        , "");
   yUNIT_minstr   ("... check test"                     , x_test        , "");
   yUNIT_minstr   ("... check expe"                     , x_expe        , "");
   yUNIT_minstr   ("... check retn"                     , x_retn        , "");
   yUNIT_mindnoc  ();

   strcpy (x_recd, "     exec     call prepare                         CATS__prepare               \"� �  � � �   � �\"   , &x_len , &x_part, &x_sub , &x_src , &x_cat , &x_page, &x_grp , &x_freq         i_equal     0                                                                                                    ");
   yUNIT_mincond  ("verify exec/get success");
   yUNIT_minval   ("call parse"                         , PARSE_current   (x_name, 15, "exec", 'f', x_recd, x_desc, x_meth, x_args, x_test, x_expe, x_retn),    0);
   yUNIT_minstr   ("... check desc"                     , x_desc        , "call prepare");
   yUNIT_minstr   ("... check meth"                     , x_meth        , "CATS__prepare");
   yUNIT_minstr   ("... check args"                     , x_args        , "\"� �  � � �   � �\"   , &x_len , &x_part, &x_sub , &x_src , &x_cat , &x_page, &x_grp , &x_freq");
   yUNIT_minstr   ("... check test"                     , x_test        , "i_equal");
   yUNIT_minstr   ("... check expe"                     , x_expe        , "0");
   yUNIT_minstr   ("... check retn"                     , x_retn        , "");
   yUNIT_mindnoc  ();

   strcpy (x_recd, "     code     ... change part                      - - - - - - - - - - - - -   x_part      = 'v';                                                                                                                                                                                                           ");
   yUNIT_mincond  ("verify code success");
   yUNIT_minval   ("call parse"                         , PARSE_current   (x_name, 20, "code", 'p', x_recd, x_desc, x_meth, x_args, x_test, x_expe, x_retn),    0);
   yUNIT_minstr   ("... check desc"                     , x_desc        , "... change part");
   yUNIT_minstr   ("... check meth"                     , x_meth        , "");
   yUNIT_minstr   ("... check args"                     , x_args        , "");
   yUNIT_minstr   ("... check test"                     , x_test        , "");
   yUNIT_minstr   ("... check expe"                     , x_expe        , "x_part      = 'v';");
   yUNIT_minstr   ("... check retn"                     , x_retn        , "");
   yUNIT_mindnoc  ();

   yUNIT_minprcs ();
   return 0;
}



/*====================------------------------------------====================*/
/*===----                       ditto processing                       ----===*/
/*====================------------------------------------====================*/
static void      o___DITTO___________________o (void) {;}

char
koios__unit_ditto_index  (char a_list)
{
   yUNIT_minscrp ("DITTO__index");
   if (a_list == 'y')  return 0;
   yURG_err_none ();

   yUNIT_mincond ("verify on valid indexes");
   yUNIT_minval  ("... run 0"                          , DITTO__index ('0'), 0);
   yUNIT_minval  ("... run 1"                          , DITTO__index ('1'), 1);
   yUNIT_minval  ("... run 4"                          , DITTO__index ('4'), 4);
   yUNIT_minval  ("... run 8"                          , DITTO__index ('8'), 8);
   yUNIT_minval  ("... run 9"                          , DITTO__index ('9'), 9);
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify null handling");
   yUNIT_minval  ("... run NULL"                       , DITTO__index ( 0 ), -999);
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify defaultish");
   yUNIT_minval  ("... run space"                      , DITTO__index (' '), -999);
   yUNIT_minval  ("... run -"                          , DITTO__index ('-'), -999);
   yUNIT_minval  ("... run �"                          , DITTO__index ('�'), -999);
   yUNIT_mindnoc ();

   yUNIT_mincond ("attempt invalid indexes");
   yUNIT_minval  ("... run a"                          , DITTO__index ('a'), -999);
   yUNIT_minval  ("... run D"                          , DITTO__index ('D'), -999);
   yUNIT_minval  ("... run +"                          , DITTO__index ('+'), -999);
   yUNIT_minval  ("... run �"                          , DITTO__index ('�'), -999);
   yUNIT_minval  ("... run �"                          , DITTO__index ('�'), -999);
   yUNIT_mindnoc ();

   yUNIT_minprcs ();
   return 0;
}

char
koios__unit_ditto_getset (char a_list)
{

   char        x_desc      [LEN_LONG]  = "";

   yUNIT_minscrp ("DITTO__set, DITTO__get, DITTO__used");
   if (a_list == 'y')  return 0;
   yURG_err_none ();

   yUNIT_mincond ("verify clean start");
   yUNIT_minval  ("... init"                           , DITTO_init ()       , 0);
   yUNIT_minstr  ("... review"                         , DITTO__used ()      , "----------");
   yUNIT_minval  ("call get NULL"                      , DITTO__get ( 0 , x_desc)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get ?"                         , DITTO__get ('?', x_desc)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get 0"                         , DITTO__get ('0', x_desc)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get 1"                         , DITTO__get ('1', x_desc)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get 2"                         , DITTO__get ('2', x_desc)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get 6"                         , DITTO__get ('6', x_desc)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get 9"                         , DITTO__get ('9', x_desc)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get -"                         , DITTO__get ('-', x_desc)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get a"                         , DITTO__get ('a', x_desc)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify setting a ditto mark");
   yUNIT_minval  ("call set"                           , DITTO__set ('0', 123, "verify something")    , 0);
   yUNIT_minstr  ("... review"                         , DITTO__used ()      , "0---------");
   yUNIT_minval  ("call get 0"                         , DITTO__get ('0', x_desc)         ,  123);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "verify something");
   yUNIT_minval  ("call get 1"                         , DITTO__get ('1', x_desc)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get 2"                         , DITTO__get ('2', x_desc)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get 6"                         , DITTO__get ('6', x_desc)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get 9"                         , DITTO__get ('9', x_desc)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify re-setting a ditto mark");
   yUNIT_minval  ("call set"                           , DITTO__set ('0',  52, "check other"     )    , 0);
   yUNIT_minstr  ("... review"                         , DITTO__used ()      , "0---------");
   yUNIT_minval  ("call get 0"                         , DITTO__get ('0', x_desc)         ,   52);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "check other");
   yUNIT_minval  ("call get 1"                         , DITTO__get ('1', x_desc)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get 2"                         , DITTO__get ('2', x_desc)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get 6"                         , DITTO__get ('6', x_desc)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get 9"                         , DITTO__get ('9', x_desc)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("attempt to set illegal marks");
   yUNIT_minval  ("call set"                           , DITTO__set ('/',   1, "verify something")    , -999);
   yUNIT_minval  ("call set"                           , DITTO__set ('a',   1, "verify something")    , -999);
   yUNIT_minval  ("call set"                           , DITTO__set ('K',   1, "verify something")    , -999);
   yUNIT_minval  ("call set"                           , DITTO__set ('�',   1, "verify something")    , -999);
   yUNIT_minstr  ("... review"                         , DITTO__used ()      , "0---------");
   yUNIT_minval  ("call get 0"                         , DITTO__get ('0', x_desc)         ,   52);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "check other");
   yUNIT_minval  ("call get 1"                         , DITTO__get ('1', x_desc)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get 2"                         , DITTO__get ('2', x_desc)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get 6"                         , DITTO__get ('6', x_desc)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get 9"                         , DITTO__get ('9', x_desc)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify setting another ditto mark");
   yUNIT_minval  ("call set"                           , DITTO__set ('6',  22, "monster trouble" )    , 0);
   yUNIT_minstr  ("... review"                         , DITTO__used ()      , "0-----6---");
   yUNIT_minval  ("call get 0"                         , DITTO__get ('0', x_desc)         ,   52);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "check other");
   yUNIT_minval  ("call get 1"                         , DITTO__get ('1', x_desc)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get 2"                         , DITTO__get ('2', x_desc)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get 6"                         , DITTO__get ('6', x_desc)         ,   22);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "monster trouble");
   yUNIT_minval  ("call get 9"                         , DITTO__get ('9', x_desc)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify setting two more");
   yUNIT_minval  ("call set"                           , DITTO__set ('1',   8, NULL              )    , 0);
   yUNIT_minval  ("call set"                           , DITTO__set ('9',1000, "!"               )    , 0);
   yUNIT_minstr  ("... review"                         , DITTO__used ()      , "01----6--9");
   yUNIT_minval  ("call get 0"                         , DITTO__get ('0', x_desc)         ,   52);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "check other");
   yUNIT_minval  ("call get 1"                         , DITTO__get ('1', x_desc)         ,    8);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get 2"                         , DITTO__get ('2', x_desc)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get 6"                         , DITTO__get ('6', x_desc)         ,   22);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "monster trouble");
   yUNIT_minval  ("call get 9"                         , DITTO__get ('9', x_desc)         , 1000);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "!");
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify purging marks");
   yUNIT_minval  ("... purge"                          , DITTO_init ()       , 0);
   yUNIT_minstr  ("... review"                         , DITTO__used ()      , "----------");
   yUNIT_minval  ("call get 0"                         , DITTO__get ('0', x_desc)         ,-999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get 1"                         , DITTO__get ('1', x_desc)         ,-999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get 2"                         , DITTO__get ('2', x_desc)         ,-999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get 6"                         , DITTO__get ('6', x_desc)         ,-999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get 9"                         , DITTO__get ('9', x_desc)         ,-999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify setting by record");
   yUNIT_minval  ("call set"                           , DITTO__set_recd ('1', 987, "COND (1)  description field " )    , 0);
   yUNIT_minstr  ("... review"                         , DITTO__used ()      , "-1--------");
   yUNIT_minval  ("call get 0"                         , DITTO__get ('0', x_desc)         ,-999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get 1"                         , DITTO__get ('1', x_desc)         , 987);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "description field");
   yUNIT_minval  ("call get 2"                         , DITTO__get ('2', x_desc)         ,-999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get 6"                         , DITTO__get ('6', x_desc)         ,-999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get 9"                         , DITTO__get ('9', x_desc)         ,-999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify setting by record (with spaces)");
   yUNIT_minval  ("call set"                           , DITTO__set_recd ('6', 789, "COND (6)        indented        " )    , 0);
   yUNIT_minstr  ("... review"                         , DITTO__used ()      , "-1----6---");
   yUNIT_minval  ("call get 0"                         , DITTO__get ('0', x_desc)         ,-999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get 1"                         , DITTO__get ('1', x_desc)         , 987);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "description field");
   yUNIT_minval  ("call get 2"                         , DITTO__get ('2', x_desc)         ,-999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get 6"                         , DITTO__get ('6', x_desc)         , 789);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "indented");
   yUNIT_minval  ("call get 9"                         , DITTO__get ('9', x_desc)         ,-999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_mindnoc ();

   yUNIT_minprcs ();
   return 0;
}

char
koios__unit_ditto_toggle (char a_list)
{
   char        x_scrp     [LEN_TITLE] = "koios";
   char        x_name     [LEN_PATH]  = "/tmp/koios.unit";
   int         x_line     =    1;
   FILE       *x_main     = NULL;
   FILE       *x_file     = NULL;
   char        x_dittoing =  '-';
   char        x_mark     =  '-';
   char        x_dmark    =  '-';
   int         x_ditto    =    0;
   int         x_dline    =    0;

   yUNIT_minscrp  ("DITTO_beg, DITTO_end");
   if (a_list == 'y')  return 0;
   yURG_err_none  ();

   yURG_err_clear ();
   yUNIT_mincond  ("prepare clean start");
   system ("rm    -f /tmp/koios.unit        2> /dev/null");
   system ("touch /tmp/koios.unit           2> /dev/null");
   x_main = fopen (x_name, "rt");
   x_file = x_main;
   yUNIT_mindnoc  ();

   yURG_err_clear ();
   yUNIT_mincond  ("verify beginning a ditto");
   x_line =  100;  x_dittoing = '-';  x_dmark = '-';  x_mark = '-';  x_ditto =   -1;  x_dline =   -1;
   yUNIT_minval   ("... line"                           , x_line                   ,  100);
   yUNIT_minpoint ("... file"                           , x_file                   , x_main);
   yUNIT_minchr   ("... dittoing"                       , x_dittoing               ,  '-');
   yUNIT_minchr   ("... dmark"                          , x_dmark                  ,  '-');
   yUNIT_minchr   ("... mark"                           , x_mark                   ,  '-');
   yUNIT_minval   ("... ditto"                          , x_ditto                  ,   -1);
   yUNIT_minval   ("... dline"                          , x_dline                  ,   -1);
   yUNIT_minval   ("call ditto begin"                   , DITTO_beg   (x_scrp, x_line, x_name, G_RUN_CREATE ,   20, '0', &x_file, &x_dittoing, &x_dmark, &x_mark, &x_ditto, &x_dline)    , 1);
   yUNIT_minpoint ("... file"                           , x_file                   ,    1);
   yUNIT_minchr   ("... dittoing"                       , x_dittoing               ,  'y');
   yUNIT_minchr   ("... dmark"                          , x_dmark                  ,  '0');
   yUNIT_minchr   ("... mark"                           , x_mark                   ,  '0');
   yUNIT_minval   ("... ditto"                          , x_ditto                  ,   20);
   yUNIT_minval   ("... dline"                          , x_dline                  ,    0);
   yUNIT_minstr   ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc  ();

   yURG_err_clear ();
   yUNIT_mincond  ("attempt to begin a ditto (when already begun");
   yUNIT_minval   ("... line"                           , x_line                   ,  100);
   yUNIT_minpoint ("... file"                           , x_file                   ,    1);
   yUNIT_minchr   ("... dittoing"                       , x_dittoing               ,  'y');
   yUNIT_minchr   ("... dmark"                          , x_dmark                  ,  '0');
   yUNIT_minchr   ("... mark"                           , x_mark                   ,  '0');
   yUNIT_minval   ("... ditto"                          , x_ditto                  ,   20);
   yUNIT_minval   ("... dline"                          , x_dline                  ,    0);
   yUNIT_minval   ("call ditto begin"                   , DITTO_beg   (x_scrp, x_line, x_name, G_RUN_CREATE ,   20, '0', &x_file, &x_dittoing, &x_dmark, &x_mark, &x_ditto, &x_dline)    , -999);
   yUNIT_minpoint ("... file"                           , x_file                   ,    1);
   yUNIT_minchr   ("... dittoing"                       , x_dittoing               ,  'y');
   yUNIT_minchr   ("... dmark"                          , x_dmark                  ,  '0');
   yUNIT_minchr   ("... mark"                           , x_mark                   ,  '0');
   yUNIT_minval   ("... ditto"                          , x_ditto                  ,   20);
   yUNIT_minval   ("... dline"                          , x_dline                  ,    0);
   yUNIT_minstr   ("... check error message"            , yURG_err_last (), "koios:100:0: error: DITTO '0' can not start as dittoing already active");
   yUNIT_mindnoc  ();

   yURG_err_clear ();
   yUNIT_mincond  ("verify ending a ditto");
   yUNIT_minval   ("... line"                           , x_line                   ,  100);
   yUNIT_minpoint ("... file"                           , x_file                   ,    1);
   yUNIT_minchr   ("... dittoing"                       , x_dittoing               ,  'y');
   yUNIT_minchr   ("... dmark"                          , x_dmark                  ,  '0');
   yUNIT_minchr   ("... mark"                           , x_mark                   ,  '0');
   yUNIT_minval   ("... ditto"                          , x_ditto                  ,   20);
   yUNIT_minval   ("... dline"                          , x_dline                  ,    0);
   yUNIT_minval   ("call ditto end"                     , DITTO_end   (&x_file, &x_dittoing, &x_dmark, &x_ditto, &x_dline)    , 1);
   yUNIT_minval   ("... line"                           , x_line                   ,  100);
   yUNIT_minpoint ("... file"                           , x_file                   , x_main);
   yUNIT_minchr   ("... dittoing"                       , x_dittoing               ,  '-');
   yUNIT_minchr   ("... dmark"                          , x_dmark                  ,  '-');
   yUNIT_minchr   ("... mark"                           , x_mark                   ,  '0');
   yUNIT_minval   ("... ditto"                          , x_ditto                  ,   -1);
   yUNIT_minval   ("... dline"                          , x_dline                  ,   -1);
   yUNIT_minstr   ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc  ();

   yURG_err_clear ();
   yUNIT_mincond  ("attempt to end a ditto (when not begun");
   yUNIT_minval   ("... line"                           , x_line                   ,  100);
   yUNIT_minpoint ("... file"                           , x_file                   , x_main);
   yUNIT_minchr   ("... dittoing"                       , x_dittoing               ,  '-');
   yUNIT_minchr   ("... dmark"                          , x_dmark                  ,  '-');
   yUNIT_minchr   ("... mark"                           , x_mark                   ,  '0');
   yUNIT_minval   ("... ditto"                          , x_ditto                  ,   -1);
   yUNIT_minval   ("... dline"                          , x_dline                  ,   -1);
   yUNIT_minval   ("call ditto end"                     , DITTO_end   (&x_file, &x_dittoing, &x_dmark, &x_ditto, &x_dline)    , 0);
   yUNIT_minval   ("... line"                           , x_line                   ,  100);
   yUNIT_minpoint ("... file"                           , x_file                   , x_main);
   yUNIT_minchr   ("... dittoing"                       , x_dittoing               ,  '-');
   yUNIT_minchr   ("... dmark"                          , x_dmark                  ,  '-');
   yUNIT_minchr   ("... mark"                           , x_mark                   ,  '0');
   yUNIT_minval   ("... ditto"                          , x_ditto                  ,   -1);
   yUNIT_minval   ("... dline"                          , x_dline                  ,   -1);
   yUNIT_mindnoc  ();

   yURG_err_clear ();
   yUNIT_mincond  ("attempt to start ditto on bad identifier");
   yUNIT_minval   ("... line"                           , x_line                   ,  100);
   yUNIT_minpoint ("... file"                           , x_file                   , x_main);
   yUNIT_minchr   ("... dittoing"                       , x_dittoing               ,  '-');
   yUNIT_minchr   ("... dmark"                          , x_dmark                  ,  '-');
   yUNIT_minchr   ("... mark"                           , x_mark                   ,  '0');
   yUNIT_minval   ("... ditto"                          , x_ditto                  ,   -1);
   yUNIT_minval   ("... dline"                          , x_dline                  ,   -1);
   yUNIT_minval   ("call ditto begin"                   , DITTO_beg   (x_scrp, x_line, x_name, G_RUN_CREATE ,   -1, '5', &x_file, &x_dittoing, &x_dmark, &x_mark, &x_ditto, &x_dline)    , -999);
   yUNIT_minval   ("... line"                           , x_line                   ,  100);
   yUNIT_minpoint ("... file"                           , x_file                   , x_main);
   yUNIT_minchr   ("... dittoing"                       , x_dittoing               ,  '-');
   yUNIT_minchr   ("... dmark"                          , x_dmark                  ,  '-');
   yUNIT_minchr   ("... mark"                           , x_mark                   ,  '0');
   yUNIT_minval   ("... ditto"                          , x_ditto                  ,   -1);
   yUNIT_minval   ("... dline"                          , x_dline                  ,   -1);
   yUNIT_minstr   ("... check error message"            , yURG_err_last (), "koios:100:0: error: DITTO '5' not set by previous COND");

   yURG_err_clear ();
   yUNIT_mincond ("wrap up");
   fclose (x_main);
   system ("rm    -f /tmp/koios.unit        2> /dev/null");
   yUNIT_mindnoc  ();

   yUNIT_minprcs  ();
   return 0;
}

char
koios__unit_ditto_read   (char a_list)
{
   int         x_ditto  =    0;
   int         x_line   =    0;
   int         x_dline  =    0;

   yUNIT_minscrp ("DITTO_read_numbering");
   if (a_list == 'y')  return 0;
   yURG_err_none ();

   yUNIT_mincond ("verify normal, non-ditto action");
   x_ditto =    0;  x_line =    1; x_dline =    0;
   yUNIT_minval  ("... ditto"                          , x_ditto                  ,   0);
   yUNIT_minval  ("... line"                           , x_line                   ,   1);
   yUNIT_minval  ("... dline"                          , x_dline                  ,   0);
   yUNIT_minval  ("call read handler"                  , DITTO_read_numbering ('-', x_ditto, &x_line , &x_dline)    , 0);
   yUNIT_minval  ("... line"                           , x_line                   ,   2);
   yUNIT_minval  ("... dline"                          , x_dline                  ,   0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify again, non-ditto action");
   x_ditto =    0;  x_line =  321; x_dline =    0;
   yUNIT_minval  ("... ditto"                          , x_ditto                  ,   0);
   yUNIT_minval  ("... line"                           , x_line                   , 321);
   yUNIT_minval  ("... dline"                          , x_dline                  ,   0);
   yUNIT_minval  ("call read handler"                  , DITTO_read_numbering ('-', x_ditto, &x_line , &x_dline)    , 0);
   yUNIT_minval  ("... line"                           , x_line                   , 322);
   yUNIT_minval  ("... dline"                          , x_dline                  ,   0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("attempt with nulls");
   x_ditto =    0;  x_line =  321; x_dline =    0;
   yUNIT_minval  ("call with null line"                , DITTO_read_numbering ('-', x_ditto, NULL    , &x_dline)    , -999);
   yUNIT_minval  ("call read null dline"               , DITTO_read_numbering ('-', x_ditto, &x_line , NULL    )    , -999);
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify in ditto");
   x_ditto =   40;  x_line =  100; x_dline =   45;
   yUNIT_minval  ("... ditto"                          , x_ditto                  ,  40);
   yUNIT_minval  ("... line"                           , x_line                   , 100);
   yUNIT_minval  ("... dline"                          , x_dline                  ,  45);
   yUNIT_minval  ("call read handler"                  , DITTO_read_numbering ('y', x_ditto, &x_line , &x_dline)    , 1);
   yUNIT_minval  ("... line"                           , x_line                   , 100);
   yUNIT_minval  ("... dline"                          , x_dline                  ,  46);
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify in ditto");
   x_ditto =   40;  x_line =  100; x_dline =   45;
   yUNIT_minval  ("... ditto"                          , x_ditto                  ,  40);
   yUNIT_minval  ("... line"                           , x_line                   , 100);
   yUNIT_minval  ("... dline"                          , x_dline                  ,  45);
   yUNIT_minval  ("call read handler"                  , DITTO_read_numbering ('y', x_ditto, &x_line , &x_dline)    , 1);
   yUNIT_minval  ("... line"                           , x_line                   , 100);
   yUNIT_minval  ("... dline"                          , x_dline                  ,  46);
   yUNIT_mindnoc ();


   yUNIT_minprcs ();
   return 0;
}


/*    yUNIT_minscrp ("SCRP__shared");
 *    yURG_err_none ();
 * 
 *    yUNIT_mincond ("prepare clean start");
 *    system ("rm -f /tmp/koios.unit 2> /dev/null");
 *    yUNIT_mindnoc ();
 * 
 *    yUNIT_mincond ("check defaults");
 *    yUNIT_minval ("... run clear"                      , SCRP__shared_purge ()         , 0);
 *    yUNIT_minstr ("... check all marks"                , SCRP__shared_used  ()         , "--------------------------   --------------------------   ----------");
 *    yUNIT_mindnoc ();
 * 
 *    yUNIT_mincond ("check master indexing");
 *    yUNIT_minval ("... master min"                     , SCRP__shared_index ('m', 'A') ,    0);
 *    yUNIT_minval ("... master middle"                  , SCRP__shared_index ('m', 'J') ,    9);
 *    yUNIT_minval ("... master max"                     , SCRP__shared_index ('m', 'Z') ,   25);
 *    yUNIT_minval ("... master too small"               , SCRP__shared_index ('m',  0 ) , -999);
 *    yUNIT_minval ("... master using reuses"            , SCRP__shared_index ('m', 'b') , -999);
 *    yUNIT_minval ("... master using dittos"            , SCRP__shared_index ('m', '4') , -999);
 *    yUNIT_minval ("... master using greek"             , SCRP__shared_index ('m', '�') , -999);
 *    yUNIT_mindnoc ();
 * 
 *    yUNIT_mincond ("check reuses indexing");
 *    yUNIT_minval ("... reuses min"                     , SCRP__shared_index ('r', 'a') ,    0);
 *    yUNIT_minval ("... reuses middle"                  , SCRP__shared_index ('r', 'm') ,   12);
 *    yUNIT_minval ("... reuses max"                     , SCRP__shared_index ('r', 'z') ,   25);
 *    yUNIT_minval ("... reuses too small"               , SCRP__shared_index ('r',  0 ) , -999);
 *    yUNIT_minval ("... reuses using master"            , SCRP__shared_index ('r', 'B') , -999);
 *    yUNIT_minval ("... reuses using dittos"            , SCRP__shared_index ('r', '4') , -999);
 *    yUNIT_minval ("... reuses using greek"             , SCRP__shared_index ('r', '�') , -999);
 *    yUNIT_mindnoc ();
 * 
 *    yUNIT_mincond ("check dittos indexing");
 *    yUNIT_minval ("... dittos min"                     , SCRP__shared_index ('d', '0') ,    0);
 *    yUNIT_minval ("... dittos middle"                  , SCRP__shared_index ('d', '4') ,    4);
 *    yUNIT_minval ("... dittos max"                     , SCRP__shared_index ('d', '9') ,    9);
 *    yUNIT_minval ("... dittos too small"               , SCRP__shared_index ('d',  0 ) , -999);
 *    yUNIT_minval ("... dittos using master"            , SCRP__shared_index ('d', 'B') , -999);
 *    yUNIT_minval ("... dittos using reuses"            , SCRP__shared_index ('d', 'j') , -999);
 *    yUNIT_minval ("... dittos using greek"             , SCRP__shared_index ('d', '�') , -999);
 *    yUNIT_mindnoc ();
 * 
 *    yUNIT_mincond ("check indexing with bad types");
 *    yUNIT_minval ("... check null"                     , SCRP__shared_index ( 0 , '0') , -999);
 *    yUNIT_minval ("... check symbol"                   , SCRP__shared_index ('#', '0') , -999);
 *    yUNIT_minval ("... check greek"                    , SCRP__shared_index ('�', '0') , -999);
 *    yUNIT_mindnoc ();
 * 
 *    yUNIT_mincond ("get masters before setting");
 *    yUNIT_minstr ("... check all marks"                , SCRP__shared_used  ()         , "--------------------------   --------------------------   ----------");
 *    yUNIT_minval ("... get master min"                 , SCRP__shared_get   ('m', 'A') , -999);
 *    yUNIT_minval ("... get master middle"              , SCRP__shared_get   ('m', 'J') , -999);
 *    yUNIT_minval ("... get master max"                 , SCRP__shared_get   ('m', 'Z') , -999);
 *    yUNIT_minval ("... get master null"                , SCRP__shared_get   ('m',  0 ) , -999);
 *    yUNIT_minval ("... get master reuses"              , SCRP__shared_get   ('m', 'b') , -999);
 *    yUNIT_minval ("... get master dittos"              , SCRP__shared_get   ('m', '4') , -999);
 *    yUNIT_minval ("... get master greek"               , SCRP__shared_get   ('m', '�') , -999);
 *    yUNIT_minval ("... get master symbol"              , SCRP__shared_get   ('m', '-') , -999);
 * 
 *    yUNIT_mincond ("set masters");
 *    yUNIT_minstr ("... check all marks"                , SCRP__shared_used  ()         , "--------------------------   --------------------------   ----------");
 *    my.n_line = 15;
 *    yUNIT_minval ("... set master min"                 , SCRP__shared_set   ('m', 'A') ,    0);
 *    yUNIT_minstr ("... check all marks"                , SCRP__shared_used  ()         , "A-------------------------   --------------------------   ----------");
 *    my.n_line = 30;
 *    yUNIT_minval ("... set master middle"              , SCRP__shared_set   ('m', 'J') ,    0);
 *    yUNIT_minstr ("... check all marks"                , SCRP__shared_used  ()         , "A--------J----------------   --------------------------   ----------");
 *    my.n_line = 45;
 *    yUNIT_minval ("... set master max"                 , SCRP__shared_set   ('m', 'Z') ,    0);
 *    yUNIT_minstr ("... check all marks"                , SCRP__shared_used  ()         , "A--------J---------------Z   --------------------------   ----------");
 *    yUNIT_mindnoc ();
* 
*    yUNIT_mincond ("get masters after setting");
*    yUNIT_minstr ("... check all marks"                , SCRP__shared_used  ()         , "A--------J---------------Z   --------------------------   ----------");
*    yUNIT_minval ("... get master min"                 , SCRP__shared_get   ('m', 'A') ,   15);
*    yUNIT_minval ("... get master middle"              , SCRP__shared_get   ('m', 'J') ,   30);
*    yUNIT_minval ("... get master max"                 , SCRP__shared_get   ('m', 'Z') ,   45);
*    yUNIT_minval ("... get master null"                , SCRP__shared_get   ('m',  0 ) , -999);
*    yUNIT_minval ("... get master reuses"              , SCRP__shared_get   ('m', 'b') , -999);
*    yUNIT_minval ("... get master dittos"              , SCRP__shared_get   ('m', '4') , -999);
*    yUNIT_minval ("... get master greek"               , SCRP__shared_get   ('m', '�') , -999);
*    yUNIT_minval ("... get master symbol"              , SCRP__shared_get   ('m', '-') , -999);
* 
*    yUNIT_mincond ("get reuses before setting");
*    yUNIT_minstr ("... check all marks"                , SCRP__shared_used  ()         , "A--------J---------------Z   --------------------------   ----------");
*    yUNIT_minval ("... get reuses min"                 , SCRP__shared_get   ('r', 'a') , -999);
*    yUNIT_minval ("... get reuses middle"              , SCRP__shared_get   ('r', 'm') , -999);
*    yUNIT_minval ("... get reuses max"                 , SCRP__shared_get   ('r', 'z') , -999);
*    yUNIT_minval ("... get reuses null"                , SCRP__shared_get   ('r',  0 ) , -999);
*    yUNIT_minval ("... get reuses master"              , SCRP__shared_get   ('r', 'B') , -999);
*    yUNIT_minval ("... get reuses dittos"              , SCRP__shared_get   ('r', '4') , -999);
*    yUNIT_minval ("... get reuses greek"               , SCRP__shared_get   ('r', '�') , -999);
*    yUNIT_minval ("... get reuses symbol"              , SCRP__shared_get   ('r', '-') , -999);
* 
*    yUNIT_mincond ("set reuses");
*    yUNIT_minstr ("... check all marks"                , SCRP__shared_used  ()         , "A--------J---------------Z   --------------------------   ----------");
*    my.n_line = 60;
*    yUNIT_minval ("... set reuses min"                 , SCRP__shared_set   ('r', 'a') ,    0);
*    yUNIT_minstr ("... check all marks"                , SCRP__shared_used  ()         , "A--------J---------------Z   a-------------------------   ----------");
*    my.n_line = 75;
*    yUNIT_minval ("... set reuses middle"              , SCRP__shared_set   ('r', 'm') ,    0);
*    yUNIT_minstr ("... check all marks"                , SCRP__shared_used  ()         , "A--------J---------------Z   a-----------m-------------   ----------");
*    my.n_line = 90;
*    yUNIT_minval ("... set reuses max"                 , SCRP__shared_set   ('r', 'z') ,    0);
*    yUNIT_minstr ("... check all marks"                , SCRP__shared_used  ()         , "A--------J---------------Z   a-----------m------------z   ----------");
*    yUNIT_mindnoc ();
* 
*    yUNIT_mincond ("get reuses after setting");
*    yUNIT_minstr ("... check all marks"                , SCRP__shared_used  ()         , "A--------J---------------Z   a-----------m------------z   ----------");
*    yUNIT_minval ("... get reuses min"                 , SCRP__shared_get   ('r', 'a') ,   60);
*    yUNIT_minval ("... get reuses middle"              , SCRP__shared_get   ('r', 'm') ,   75);
*    yUNIT_minval ("... get reuses max"                 , SCRP__shared_get   ('r', 'z') ,   90);
*    yUNIT_minval ("... get reuses null"                , SCRP__shared_get   ('r',  0 ) , -999);
*    yUNIT_minval ("... get reuses master"              , SCRP__shared_get   ('r', 'B') , -999);
*    yUNIT_minval ("... get reuses dittos"              , SCRP__shared_get   ('r', '4') , -999);
*    yUNIT_minval ("... get reuses greek"               , SCRP__shared_get   ('r', '�') , -999);
*    yUNIT_minval ("... get reuses symbol"              , SCRP__shared_get   ('r', '-') , -999);
* 
*    yUNIT_mincond ("get dittos before setting");
*    yUNIT_minstr ("... check all marks"                , SCRP__shared_used  ()         , "A--------J---------------Z   a-----------m------------z   ----------");
*    yUNIT_minval ("... get dittos min"                 , SCRP__shared_get   ('d', 'a') , -999);
*    yUNIT_minval ("... get dittos middle"              , SCRP__shared_get   ('d', 'm') , -999);
*    yUNIT_minval ("... get dittos max"                 , SCRP__shared_get   ('d', 'z') , -999);
*    yUNIT_minval ("... get dittos null"                , SCRP__shared_get   ('d',  0 ) , -999);
*    yUNIT_minval ("... get dittos master"              , SCRP__shared_get   ('d', 'B') , -999);
*    yUNIT_minval ("... get dittos reuses"              , SCRP__shared_get   ('d', 'j') , -999);
*    yUNIT_minval ("... get dittos greek"               , SCRP__shared_get   ('d', '�') , -999);
*    yUNIT_minval ("... get dittos symbol"              , SCRP__shared_get   ('d', '-') , -999);
* 
*    yUNIT_mincond ("set dittos");
*    yUNIT_minstr ("... check all marks"                , SCRP__shared_used  ()         , "A--------J---------------Z   a-----------m------------z   ----------");
*    my.n_line = 92;
*    yUNIT_minval ("... set dittos min"                 , SCRP__shared_set   ('d', '0') ,    0);
*    yUNIT_minstr ("... check all marks"                , SCRP__shared_used  ()         , "A--------J---------------Z   a-----------m------------z   0---------");
*    my.n_line = 94;
*    yUNIT_minval ("... set dittos middle"              , SCRP__shared_set   ('d', '4') ,    0);
*    yUNIT_minstr ("... check all marks"                , SCRP__shared_used  ()         , "A--------J---------------Z   a-----------m------------z   0---4-----");
*    my.n_line = 98;
*    yUNIT_minval ("... set dittos max"                 , SCRP__shared_set   ('d', '9') ,    0);
*    yUNIT_minstr ("... check all marks"                , SCRP__shared_used  ()         , "A--------J---------------Z   a-----------m------------z   0---4----9");
*    yUNIT_mindnoc ();
* 
*    yUNIT_mincond ("get dittos after setting");
*    yUNIT_minstr ("... check all marks"                , SCRP__shared_used  ()         , "A--------J---------------Z   a-----------m------------z   0---4----9");
*    yUNIT_minval ("... get dittos min"                 , SCRP__shared_get   ('d', '0') ,   92);
*    yUNIT_minval ("... get dittos middle"              , SCRP__shared_get   ('d', '4') ,   94);
*    yUNIT_minval ("... get dittos max"                 , SCRP__shared_get   ('d', '9') ,   98);
*    yUNIT_minval ("... get dittos null"                , SCRP__shared_get   ('d',  0 ) , -999);
*    yUNIT_minval ("... get dittos master"              , SCRP__shared_get   ('d', 'B') , -999);
*    yUNIT_minval ("... get dittos reuses"              , SCRP__shared_get   ('d', 'j') , -999);
*    yUNIT_minval ("... get dittos greek"               , SCRP__shared_get   ('d', '�') , -999);
*    yUNIT_minval ("... get dittos symbol"              , SCRP__shared_get   ('d', '-') , -999);
* 
*    yUNIT_mincond ("check defaults");
*    yUNIT_minval ("... run clear"                      , SCRP__shared_purge ()         , 0);
*    yUNIT_minstr ("... check all marks"                , SCRP__shared_used  ()         , "--------------------------   --------------------------   ----------");
*    yUNIT_mindnoc ();
* 
*    yUNIT_minprcs ();
*    return 0;
*/



/*====================------------------------------------====================*/
/*===----                       reuse processing                       ----===*/
/*====================------------------------------------====================*/
static void      o___REUSE___________________o (void) {;}

char
koios__unit_reuse_index  (char a_list)
{
   yUNIT_minscrp ("REUSE__index");
   if (a_list == 'y')  return 0;
   yURG_err_none ();

   yUNIT_mincond ("verify on valid indexes");
   yUNIT_minval  ("... run A"                          , REUSE__index (T_MASTER, 'A'),  0);
   yUNIT_minval  ("... run E"                          , REUSE__index (T_SHARES, 'e'),  4);
   yUNIT_minval  ("... run L"                          , REUSE__index (T_MASTER, 'L'), 11);
   yUNIT_minval  ("... run Q"                          , REUSE__index (T_SHARES, 'q'), 16);
   yUNIT_minval  ("... run L"                          , REUSE__index (T_MASTER, 'M'), 12);
   yUNIT_minval  ("... run Z"                          , REUSE__index (T_SHARES, 'z'), 25);
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify null handling");
   yUNIT_minval  ("... run NULL"                       , REUSE__index (T_MASTER,  0 ), -999);
   yUNIT_minval  ("... run NULL"                       , REUSE__index (T_SHARES,  0 ), -999);
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify defaultish");
   yUNIT_minval  ("... run space"                      , REUSE__index (T_MASTER, ' '), -999);
   yUNIT_minval  ("... run -"                          , REUSE__index (T_SHARES, '-'), -999);
   yUNIT_minval  ("... run �"                          , REUSE__index (T_MASTER, '�'), -999);
   yUNIT_mindnoc ();

   yUNIT_mincond ("attempt invalid indexes");
   yUNIT_minval  ("... run a"                          , REUSE__index (T_MASTER, 'a'), -999);
   yUNIT_minval  ("... run ?"                          , REUSE__index (T_MASTER, '5'), -999);
   yUNIT_minval  ("... run +"                          , REUSE__index (T_MASTER, '+'), -999);
   yUNIT_minval  ("... run �"                          , REUSE__index (T_MASTER, '�'), -999);
   yUNIT_minval  ("... run �"                          , REUSE__index (T_MASTER, '�'), -999);
   yUNIT_minval  ("... run a"                          , REUSE__index (T_SHARES, 'A'), -999);
   yUNIT_minval  ("... run ?"                          , REUSE__index (T_SHARES, '5'), -999);
   yUNIT_minval  ("... run +"                          , REUSE__index (T_SHARES, '+'), -999);
   yUNIT_minval  ("... run �"                          , REUSE__index (T_SHARES, '�'), -999);
   yUNIT_minval  ("... run �"                          , REUSE__index (T_SHARES, '�'), -999);
   yUNIT_mindnoc ();

   yUNIT_minprcs ();
   return 0;
}

char
koios__unit_reuse_getset (char a_list)
{

   char        x_desc      [LEN_LONG]  = "";

   yUNIT_minscrp ("REUSE__set, REUSE__get, REUSE__used");
   if (a_list == 'y')  return 0;
   yURG_err_none ();

   yUNIT_mincond ("verify clean start");
   yUNIT_minval  ("... init"                           , REUSE_init ()       , 0);
   yUNIT_minstr  ("... review"                         , REUSE__used ()      , "�-----�-----�-----�-----�-   �-----�-----�-----�-----�-");
   yUNIT_minval  ("call get NULL"                      , REUSE__get (T_MASTER,  0 , x_desc)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get ?"                         , REUSE__get (T_SHARES, '?', x_desc)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get A"                         , REUSE__get (T_MASTER, 'A', x_desc)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get f"                         , REUSE__get (T_SHARES, 'f', x_desc)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get K"                         , REUSE__get (T_MASTER, 'K', x_desc)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get z"                         , REUSE__get (T_SHARES, 'z', x_desc)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get M"                         , REUSE__get (T_MASTER, 'M', x_desc)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get -"                         , REUSE__get (T_SHARES, '-', x_desc)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get a"                         , REUSE__get (T_MASTER, 'a', x_desc)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get 5"                         , REUSE__get (T_MASTER, '5', x_desc)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify setting a reuse mark");
   yUNIT_minval  ("call set"                           , REUSE__set (T_MASTER, 'A', 123, "verify something")    , 0);
   yUNIT_minstr  ("... review"                         , REUSE__used ()      , "A-----�-----�-----�-----�-   �-----�-----�-----�-----�-");
   yUNIT_minval  ("call get A"                         , REUSE__get (T_MASTER, 'A', x_desc)         ,  123);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "verify something");
   yUNIT_minval  ("call get f"                         , REUSE__get (T_SHARES, 'f', x_desc)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get K"                         , REUSE__get (T_MASTER, 'K', x_desc)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get z"                         , REUSE__get (T_SHARES, 'z', x_desc)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get M"                         , REUSE__get (T_MASTER, 'M', x_desc)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get p"                         , REUSE__get (T_SHARES, 'p', x_desc)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify re-setting a reuse mark");
   yUNIT_minval  ("call set"                           , REUSE__set (T_MASTER, 'A',  52, "check other"     )    , 0);
   yUNIT_minstr  ("... review"                         , REUSE__used ()      , "A-----�-----�-----�-----�-   �-----�-----�-----�-----�-");
   yUNIT_minval  ("call get A"                         , REUSE__get (T_MASTER, 'A', x_desc)         ,   52);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "check other");
   yUNIT_minval  ("call get f"                         , REUSE__get (T_SHARES, 'f', x_desc)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get K"                         , REUSE__get (T_MASTER, 'K', x_desc)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get z"                         , REUSE__get (T_SHARES, 'z', x_desc)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get M"                         , REUSE__get (T_MASTER, 'M', x_desc)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get p"                         , REUSE__get (T_SHARES, 'p', x_desc)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("attempt to set illegal marks");
   yUNIT_minval  ("call set"                           , REUSE__set (T_MASTER, '/',   1, "verify something")    , -999);
   yUNIT_minval  ("call set"                           , REUSE__set (T_MASTER, 'a',   1, "verify something")    , -999);
   yUNIT_minval  ("call set"                           , REUSE__set (T_MASTER, '5',   1, "verify something")    , -999);
   yUNIT_minval  ("call set"                           , REUSE__set (T_MASTER, '�',   1, "verify something")    , -999);
   yUNIT_minstr  ("... review"                         , REUSE__used ()      , "A-----�-----�-----�-----�-   �-----�-----�-----�-----�-");
   yUNIT_minval  ("call get A"                         , REUSE__get (T_MASTER, 'A', x_desc)         ,   52);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "check other");
   yUNIT_minval  ("call get f"                         , REUSE__get (T_SHARES, 'f', x_desc)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get K"                         , REUSE__get (T_MASTER, 'K', x_desc)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get z"                         , REUSE__get (T_SHARES, 'z', x_desc)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get M"                         , REUSE__get (T_MASTER, 'M', x_desc)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get p"                         , REUSE__get (T_SHARES, 'p', x_desc)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify setting another reuse mark");
   yUNIT_minval  ("call set"                           , REUSE__set (T_SHARES, 'z',  22, "monster trouble" )    , 0);
   yUNIT_minstr  ("... review"                         , REUSE__used ()      , "A-----�-----�-----�-----�-   �-----�-----�-----�-----�z");
   yUNIT_minval  ("call get A"                         , REUSE__get (T_MASTER, 'A', x_desc)         ,   52);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "check other");
   yUNIT_minval  ("call get f"                         , REUSE__get (T_SHARES, 'f', x_desc)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get K"                         , REUSE__get (T_MASTER, 'K', x_desc)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get z"                         , REUSE__get (T_SHARES, 'z', x_desc)         ,   22);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "monster trouble");
   yUNIT_minval  ("call get M"                         , REUSE__get (T_MASTER, 'M', x_desc)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get p"                         , REUSE__get (T_SHARES, 'p', x_desc)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify setting two more");
   yUNIT_minval  ("call set"                           , REUSE__set (T_SHARES, 'f',   8, NULL              )    , 0);
   yUNIT_minval  ("call set"                           , REUSE__set (T_MASTER, 'M',1000, "!"               )    , 0);
   yUNIT_minstr  ("... review"                         , REUSE__used ()      , "A-----�-----M-----�-----�-   �----f�-----�-----�-----�z");
   yUNIT_minval  ("call get A"                         , REUSE__get (T_MASTER, 'A', x_desc)         ,   52);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "check other");
   yUNIT_minval  ("call get f"                         , REUSE__get (T_SHARES, 'f', x_desc)         ,    8);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get K"                         , REUSE__get (T_MASTER, 'K', x_desc)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get z"                         , REUSE__get (T_SHARES, 'z', x_desc)         ,   22);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "monster trouble");
   yUNIT_minval  ("call get M"                         , REUSE__get (T_MASTER, 'M', x_desc)         , 1000);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "!");
   yUNIT_minval  ("call get p"                         , REUSE__get (T_SHARES, 'p', x_desc)         ,-999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify purging marks");
   yUNIT_minval  ("... purge"                          , REUSE_init  ()      , 0);
   yUNIT_minstr  ("... review"                         , REUSE__used ()      , "�-----�-----�-----�-----�-   �-----�-----�-----�-----�-");
   yUNIT_minval  ("call get A"                         , REUSE__get (T_MASTER, 'A', x_desc)         ,-999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get f"                         , REUSE__get (T_SHARES, 'f', x_desc)         ,-999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get K"                         , REUSE__get (T_MASTER, 'K', x_desc)         ,-999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get z"                         , REUSE__get (T_SHARES, 'z', x_desc)         ,-999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get M"                         , REUSE__get (T_MASTER, 'M', x_desc)         ,-999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get p"                         , REUSE__get (T_SHARES, 'p', x_desc)         ,-999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify setting by record");
   yUNIT_minval  ("call set"                           , REUSE__set_recd (T_SHARES, 'f', 987, "SHARE -f-  description field " )    , 0);
   yUNIT_minstr  ("... review"                         , REUSE__used ()      , "�-----�-----�-----�-----�-   �----f�-----�-----�-----�-");
   yUNIT_minval  ("call get A"                         , REUSE__get (T_MASTER, 'A', x_desc)         ,-999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get f"                         , REUSE__get (T_SHARES, 'f', x_desc)         , 987);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "description field");
   yUNIT_minval  ("call get K"                         , REUSE__get (T_MASTER, 'K', x_desc)         ,-999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get z"                         , REUSE__get (T_SHARES, 'z', x_desc)         ,-999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get M"                         , REUSE__get (T_MASTER, 'M', x_desc)         ,-999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get p"                         , REUSE__get (T_SHARES, 'p', x_desc)         ,-999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify setting by record (with spaces)");
   yUNIT_minval  ("call set"                           , REUSE__set_recd (T_MASTER, 'M', 789, "GLOBAL -M-        indented        " )    , 0);
   yUNIT_minstr  ("... review"                         , REUSE__used ()      , "�-----�-----M-----�-----�-   �----f�-----�-----�-----�-");
   yUNIT_minval  ("call get A"                         , REUSE__get (T_MASTER, 'A', x_desc)         ,-999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get f"                         , REUSE__get (T_SHARES, 'f', x_desc)         , 987);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "description field");
   yUNIT_minval  ("call get K"                         , REUSE__get (T_MASTER, 'K', x_desc)         ,-999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get z"                         , REUSE__get (T_SHARES, 'z', x_desc)         ,-999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get M"                         , REUSE__get (T_MASTER, 'M', x_desc)         , 789);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "indented");
   yUNIT_minval  ("call get p"                         , REUSE__get (T_SHARES, 'p', x_desc)         ,-999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_mindnoc ();

   yUNIT_minprcs ();
   return 0;
}

char
koios__unit_reuse_global (char a_list)
{
   char        x_master    [LEN_TITLE] = "/tmp/master.unit";
   char        x_name      [LEN_TITLE] = "/tmp/koios.unit";
   char        x_desc      [LEN_LONG]  = "";
   char        x_share     =  '-';

   yUNIT_minscrp ("REUSE_parse (GLOBAL)");
   if (a_list == 'y')  return 0;
   yURG_err_none ();

   yUNIT_mincond ("set to defaults");
   yUNIT_minval  ("... run clear"                      , REUSE_init ()       , 0);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "�-----�-----�-----�-----�-   �-----�-----�-----�-----�-");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("verify ignoring other verbs");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_master,   0, "exec"     , "  exec      read a line          "   , '-', &x_share),    0);
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_master,   0, "SCRP"     , "SCRP        test the reading     "   , '-', &x_share),    0);
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("attempt reusing a missing identifier");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_master,   1, "REUSE"    , "REUSE  -K-  - - - - - - - - - -  "   , '-', &x_share), -999);
   yUNIT_minchr  ("... check mark"                     , x_share             , '-');
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/master.unit:1:0: error: �REUSE  -K-� verb identifier �K� never set by GLOBAL");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("attempt reusing a illegal identifier");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_master,   3, "REUSE"    , "REUSE  -�-  - - - - - - - - - -  "   , '-', &x_share), -999);
   yUNIT_minchr  ("... check mark"                     , x_share             , '-');
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/master.unit:3:0: error: �REUSE  -�-� verb identifier �� not valid [a-zA-Z]");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("verify simple global identifier");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_master,   4, "GLOBAL"   , "GLOBAL -A-  generate test data   "   , '-', &x_share), 1);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "A-----�-----�-----�-----�-   �-----�-----�-----�-----�-");
   yUNIT_minchr  ("... check mark"                     , x_share             , 'A');
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_minval  ("call get mark"                      , REUSE__get (T_MASTER, x_share, x_desc)         ,    4);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "generate test data");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("verify reusing the identifier (in normal unit)");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_name  ,   5, "REUSE"    , "REUSE  -A-  - - - - - - - - - -  "   , '-', &x_share), 1);
   yUNIT_minchr  ("... check mark"                     , x_share             , 'A');
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("verify reusing the identifier (in master unit)");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_master,   5, "REUSE"    , "REUSE  -A-  - - - - - - - - - -  "   , '-', &x_share), 1);
   yUNIT_minchr  ("... check mark"                     , x_share             , 'A');
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("verify defenses");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_master,   0, NULL       , "REUSE  -A-  - - - - - - - - - -  "   , '-', &x_share), -999);
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_master,   0, "REUSE"    , NULL                                      , '-', &x_share), -999);
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_master,   0, "REUSE"    , "REUSE  -A-  - - - - - - - - - -  "   , '-', NULL    ), -999);
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("attempt without a identifier");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_master,   6, "GLOBAL"   , "GLOBAL      oops                 "   , '-', &x_share), -999);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "A-----�-----�-----�-----�-   �-----�-----�-----�-----�-");
   yUNIT_minchr  ("... check mark"                     , x_share             , '-');
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/master.unit:6:0: error: �GLOBAL� missing valid identifier string, e.g., -A-");
   yUNIT_minval  ("call get mark"                      , REUSE__get (T_MASTER, x_share, x_desc)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("attempt with weird delimiters");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_master,   7, "GLOBAL"   , "GLOBAL (M)  oops                 "   , '-', &x_share), -999);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "A-----�-----�-----�-----�-   �-----�-----�-----�-----�-");
   yUNIT_minchr  ("... check mark"                     , x_share             , '-');
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/master.unit:7:0: error: �GLOBAL (M)� missing valid identifier string, e.g., -A-");
   yUNIT_minval  ("call get mark"                      , REUSE__get (T_MASTER, x_share, x_desc)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("attempt with no suffix");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_master,   8, "GLOBAL"   , "GLOBAL -M   oops                 "   , '-', &x_share), -999);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "A-----�-----�-----�-----�-   �-----�-----�-----�-----�-");
   yUNIT_minchr  ("... check mark"                     , x_share             , '-');
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/master.unit:8:0: error: �GLOBAL -M� identifier �-M� does not end with -, e.g., -A-");
   yUNIT_minval  ("call get mark"                      , REUSE__get (T_MASTER, x_share, x_desc)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("attempt with just suffix");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_master,   9, "GLOBAL"   , "GLOBAL -M)  oops                 "   , '-', &x_share), -999);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "A-----�-----�-----�-----�-   �-----�-----�-----�-----�-");
   yUNIT_minchr  ("... check mark"                     , x_share             , '-');
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/master.unit:9:0: error: �GLOBAL -M)� identifier �-M)� does not end with -, e.g., -A-");
   yUNIT_minval  ("call get mark"                      , REUSE__get (T_MASTER, x_share, x_desc)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("verify another global identifier");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_master,  10, "GLOBAL"   , "GLOBAL -M-  some repeating stuff "   , '-', &x_share), 1);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "A-----�-----M-----�-----�-   �-----�-----�-----�-----�-");
   yUNIT_minchr  ("... check mark"                     , x_share             , 'M');
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_minval  ("call get mark"                      , REUSE__get (T_MASTER, x_share, x_desc)         ,   10);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "some repeating stuff");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("attempt with just suffix");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_master,  15, "GLOBAL"   , "GLOBAL -c-  wrong case           "   , '-', &x_share), -999);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "A-----�-----M-----�-----�-   �-----�-----�-----�-----�-");
   yUNIT_minchr  ("... check mark"                     , x_share             , '-');
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/master.unit:15:0: error: �GLOBAL -c-� identifier �c� not valid �ABCDEFGHIJKLMNOPQRSTUVWXYZ�");
   yUNIT_minval  ("call get mark"                      , REUSE__get (T_MASTER, x_share, x_desc)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("attempt to redefine idenfitier");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_master,  15, "GLOBAL"   , "GLOBAL -M-  re-defining          "   , '-', &x_share), -999);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "A-----�-----M-----�-----�-   �-----�-----�-----�-----�-");
   yUNIT_minchr  ("... check mark"                     , x_share             , '-');
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/master.unit:15:0: error: �GLOBAL -M-� identifier �M� already in use");
   yUNIT_minval  ("call get mark"                      , REUSE__get (T_MASTER, x_share, x_desc)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("attempt to define outside master.unit");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_name  ,  20, "GLOBAL"   , "GLOBAL -M-  re-defining          "   , '-', &x_share), -999);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "A-----�-----M-----�-----�-   �-----�-----�-----�-----�-");
   yUNIT_minchr  ("... check mark"                     , x_share             , '-');
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:20:0: error: GLOBAL verb not allowed outside master.unit");
   yUNIT_minval  ("call get mark"                      , REUSE__get (T_MASTER, x_share, x_desc)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("verify another global identifier");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_master,  30, "GLOBAL"   , "GLOBAL -Y-  final check          "   , '-', &x_share), 1);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "A-----�-----M-----�-----Y-   �-----�-----�-----�-----�-");
   yUNIT_minchr  ("... check mark"                     , x_share             , 'Y');
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_minval  ("call get mark"                      , REUSE__get (T_MASTER, x_share, x_desc)         ,   30);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "final check");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("attempt reusing inside itself");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_master,  35, "REUSE"    , "REUSE  -A-  - - - - - - - - - -  "   , 'A', &x_share), -999);
   yUNIT_minchr  ("... check mark"                     , x_share             , '-');
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/master.unit:35:0: error: �REUSE  -A-� verb identifier �A� called inside itself, recursive");
   yUNIT_mindnoc ();

   yUNIT_minprcs ();
   return 0;
}

char
koios__unit_reuse_shares (char a_list)
{
   char        x_master    [LEN_TITLE] = "/tmp/master.unit";
   char        x_name      [LEN_TITLE] = "/tmp/koios.unit";
   char        x_desc      [LEN_LONG]  = "";
   char        x_share     =  '-';

   yUNIT_minscrp ("REUSE_parse (SHARE)");
   if (a_list == 'y')  return 0;
   yURG_err_none ();

   yUNIT_mincond ("set to defaults");
   yUNIT_minval  ("... run clear"                      , REUSE_init ()       , 0);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "�-----�-----�-----�-----�-   �-----�-----�-----�-----�-");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("verify ignoring other verbs");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_name  ,   0, "exec"     , "  exec      read a line          "   , '-', &x_share),    0);
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_name  ,   0, "SCRP"     , "SCRP        test the reading     "   , '-', &x_share),    0);
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("attempt reusing a missing identifier");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_name  ,   1, "REUSE"    , "REUSE  -k-  - - - - - - - - - -  "   , '-', &x_share), -999);
   yUNIT_minchr  ("... check mark"                     , x_share             , '-');
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:0: error: �REUSE  -k-� verb identifier �k� never set by SHARED");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("attempt reusing a illegal identifier");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_name  ,   3, "REUSE"    , "REUSE  -�-  - - - - - - - - - -  "   , '-', &x_share), -999);
   yUNIT_minchr  ("... check mark"                     , x_share             , '-');
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:3:0: error: �REUSE  -�-� verb identifier �� not valid [a-zA-Z]");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("verify simple share identifier");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_name  ,   5, "SHARED"   , "SHARED -a-  generate test data   "   , '-', &x_share), 1);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "�-----�-----�-----�-----�-   a-----�-----�-----�-----�-");
   yUNIT_minchr  ("... check mark"                     , x_share             , 'a');
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_minval  ("call get mark"                      , REUSE__get (T_SHARES, x_share, x_desc)         ,    5);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "generate test data");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("verify reusing the identifier (in normal unit)");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_name  ,   5, "REUSE"    , "REUSE  -a-  - - - - - - - - - -  "   , '-', &x_share), 1);
   yUNIT_minchr  ("... check mark"                     , x_share             , 'a');
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("attempt reusing the identifier (in master unit)");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_master,   5, "REUSE"    , "REUSE  -a-  - - - - - - - - - -  "   , '-', &x_share), -999);
   yUNIT_minchr  ("... check mark"                     , x_share             , '-');
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/master.unit:5:0: error: REUSE verb on �a� SHARED identifier not allowed inside master.unit");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("verify defenses");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_name  ,   0, NULL       , "REUSE  -a-  - - - - - - - - - -  "   , '-', &x_share), -999);
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_name  ,   0, "REUSE"    , NULL                                      , '-', &x_share), -999);
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_name  ,   0, "REUSE"    , "REUSE  -a-  - - - - - - - - - -  "   , '-', NULL    ), -999);
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("attempt without a identifier");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_name  ,   6, "SHARED"   , "SHARED      oops                 "   , '-', &x_share), -999);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "�-----�-----�-----�-----�-   a-----�-----�-----�-----�-");
   yUNIT_minchr  ("... check mark"                     , x_share             , '-');
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:6:0: error: �SHARED� missing valid identifier string, e.g., -a-");
   yUNIT_minval  ("call get mark"                      , REUSE__get (T_SHARES, x_share, x_desc)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("attempt with weird delimiters");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_name  ,   7, "SHARED"   , "SHARED (r)  oops                 "   , '-', &x_share), -999);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "�-----�-----�-----�-----�-   a-----�-----�-----�-----�-");
   yUNIT_minchr  ("... check mark"                     , x_share             , '-');
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:7:0: error: �SHARED (r)� missing valid identifier string, e.g., -a-");
   yUNIT_minval  ("call get mark"                      , REUSE__get (T_SHARES, x_share, x_desc)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("attempt with no suffix");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_name  ,   8, "SHARED"   , "SHARED -r   oops                 "   , '-', &x_share), -999);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "�-----�-----�-----�-----�-   a-----�-----�-----�-----�-");
   yUNIT_minchr  ("... check mark"                     , x_share             , '-');
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:8:0: error: �SHARED -r� identifier �-r� does not end with -, e.g., -a-");
   yUNIT_minval  ("call get mark"                      , REUSE__get (T_SHARES, x_share, x_desc)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("attempt with just suffix");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_name  ,   9, "SHARED"   , "SHARED -r)  oops                 "   , '-', &x_share), -999);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "�-----�-----�-----�-----�-   a-----�-----�-----�-----�-");
   yUNIT_minchr  ("... check mark"                     , x_share             , '-');
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:9:0: error: �SHARED -r)� identifier �-r)� does not end with -, e.g., -a-");
   yUNIT_minval  ("call get mark"                      , REUSE__get (T_SHARES, x_share, x_desc)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("verify another global identifier");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_name  ,  10, "SHARED"   , "SHARED -r-  some repeating stuff "   , '-', &x_share), 1);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "�-----�-----�-----�-----�-   a-----�-----�----r�-----�-");
   yUNIT_minchr  ("... check mark"                     , x_share             , 'r');
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_minval  ("call get mark"                      , REUSE__get (T_SHARES, x_share, x_desc)         ,   10);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "some repeating stuff");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("attempt with just suffix");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_name  ,  15, "SHARED"   , "SHARED -C-  wrong case           "   , '-', &x_share), -999);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "�-----�-----�-----�-----�-   a-----�-----�----r�-----�-");
   yUNIT_minchr  ("... check mark"                     , x_share             , '-');
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:15:0: error: �SHARED -C-� identifier �C� not valid �abcdefghijklmnopqrstuvwxyz�");
   yUNIT_minval  ("call get mark"                      , REUSE__get (T_SHARES, x_share, x_desc)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("attempt to redefine idenfitier");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_name  ,  15, "SHARED"   , "SHARED -r-  re-defining          "   , '-', &x_share), -999);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "�-----�-----�-----�-----�-   a-----�-----�----r�-----�-");
   yUNIT_minchr  ("... check mark"                     , x_share             , '-');
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:15:0: error: �SHARED -r-� identifier �r� already in use");
   yUNIT_minval  ("call get mark"                      , REUSE__get (T_SHARES, x_share, x_desc)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("attempt to define inside master.unit");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_master,  20, "SHARED"   , "SHARED -r-  re-defining          "   , '-', &x_share), -999);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "�-----�-----�-----�-----�-   a-----�-----�----r�-----�-");
   yUNIT_minchr  ("... check mark"                     , x_share             , '-');
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/master.unit:20:0: error: SHARED verb not allowed inside master.unit");
   yUNIT_minval  ("call get mark"                      , REUSE__get (T_SHARES, x_share, x_desc)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("verify another global identifier");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_name  ,  30, "SHARED"   , "SHARED -z-  final check          "   , '-', &x_share), 1);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "�-----�-----�-----�-----�-   a-----�-----�----r�-----�z");
   yUNIT_minchr  ("... check mark"                     , x_share             , 'z');
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_minval  ("call get mark"                      , REUSE__get (T_SHARES, x_share, x_desc)         ,   30);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "final check");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("attempt reusing inside itself");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_name  ,  35, "REUSE"    , "REUSE  -a-  - - - - - - - - - -  "   , 'a', &x_share), -999);
   yUNIT_minchr  ("... check mark"                     , x_share             , '-');
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:35:0: error: �REUSE  -a-� verb identifier �a� called inside itself, recursive");
   yUNIT_mindnoc ();

   yUNIT_minprcs ();
   return 0;
}

char
koios__unit_reuse_parse  (char a_list)
{

   yUNIT_minscrp ("REUSE_parse");
   if (a_list == 'y')  return 0;
   yURG_err_none ();

   yUNIT_mincond ("prepare clean start");
   system ("rm -f /tmp/koios.unit 2> /dev/null");
   yUNIT_mindnoc ();

   yUNIT_mincond ("set to conversion mode");
   my.run_type = G_RUN_UPDATE;
   yUNIT_mindnoc ();

   yUNIT_mincond ("set to defaults");
   yUNIT_minval  ("... run clear"                      , SCRP__shared_purge ()         , 0);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "�-----�-----�-----�-----�-   �-----�-----�-----�-----�-");
   yUNIT_mindnoc ();

   strcpy (my.n_base, "master");

   /*> yUNIT_mincond ("check a min global identifier");                                                                                                                                   <* 
    *> yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);                                                                                                       <* 
    *> yUNIT_minval  ("parse GLOBAL"                       , SCRP__parse_verb    (my.n_scrp, my.n_line, "GLOBAL -A-", my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code)), 0);   <* 
    *> yUNIT_minstr  ("... check verb"                     , my.verb           , "GLOBAL");                                                                                               <* 
    *> yUNIT_minval  ("check reuses"                       , SCRP__reuses_check ("GLOBAL -A-"), 0);                                                                                       <* 
    *> yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");                                                                                                       <* 
    *> yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "A-----�-----�-----�-----�-   �-----�-----�-----�-----�-");                                            <* 
    *> yUNIT_minchr  ("... check mark"                     , my.share          , 'A');                                                                                                    <* 
    *> yUNIT_mindnoc ();                                                                                                                                                                  <*/

   /*> yUNIT_mincond ("check a middle global identifier");                                                                                                                                <* 
    *> yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);                                                                                                       <* 
    *> yUNIT_minval  ("parse GLOBAL"                       , SCRP__parse_verb    (my.n_scrp, my.n_line, "GLOBAL -M-", my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code)), 0);   <* 
    *> yUNIT_minstr  ("... check verb"                     , my.verb           , "GLOBAL");                                                                                               <* 
    *> yUNIT_minval  ("check reuses"                       , SCRP__reuses_check ("GLOBAL -M-"), 0);                                                                                       <* 
    *> yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");                                                                                                       <* 
    *> yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "A-----�-----M-----�-----�-   �-----�-----�-----�-----�-");                                            <* 
    *> yUNIT_minchr  ("... check mark"                     , my.share          , 'M');                                                                                                    <* 
    *> yUNIT_mindnoc ();                                                                                                                                                                  <*/

   /*> yUNIT_mincond ("check with no identifier string");                                                                                                                                 <* 
    *> yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);                                                                                                       <* 
    *> yUNIT_minval  ("parse GLOBAL"                       , SCRP__parse_verb    (my.n_scrp, my.n_line, "GLOBAL"    , my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code)), 0);   <* 
    *> yUNIT_minstr  ("... check verb"                     , my.verb           , "GLOBAL");                                                                                               <* 
    *> yUNIT_minval  ("check reuses"                       , SCRP__reuses_check ("GLOBAL"    ), -999);                                                                                    <* 
    *> yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: GLOBAL missing a valid identifier string -?-");                               <* 
    *> yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "A-----�-----M-----�-----�-   �-----�-----�-----�-----�-");                                            <* 
    *> yUNIT_minchr  ("... check mark"                     , my.share          , '-');                                                                                                    <* 
    *> yUNIT_mindnoc ();                                                                                                                                                                  <*/

   /*> yUNIT_mincond ("check with only identifier beginning");                                                                                                                            <* 
    *> yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);                                                                                                       <* 
    *> yUNIT_minval  ("parse GLOBAL"                       , SCRP__parse_verb    (my.n_scrp, my.n_line, "GLOBAL -"  , my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code)), 0);   <* 
    *> yUNIT_minstr  ("... check verb"                     , my.verb           , "GLOBAL");                                                                                               <* 
    *> yUNIT_minval  ("check reuses"                       , SCRP__reuses_check ("GLOBAL -"  ), -999);                                                                                    <* 
    *> yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: GLOBAL identifier did not follow - marker");                                  <* 
    *> yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "A-----�-----M-----�-----�-   �-----�-----�-----�-----�-");                                            <* 
    *> yUNIT_minchr  ("... check mark"                     , my.share          , '-');                                                                                                    <* 
    *> yUNIT_mindnoc ();                                                                                                                                                                  <*/

   /*> yUNIT_mincond ("check with no identifier within");                                                                                                                                 <* 
    *> yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);                                                                                                       <* 
    *> yUNIT_minval  ("parse GLOBAL"                       , SCRP__parse_verb    (my.n_scrp, my.n_line, "GLOBAL --" , my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code)), 0);   <* 
    *> yUNIT_minstr  ("... check verb"                     , my.verb           , "GLOBAL");                                                                                               <* 
    *> yUNIT_minval  ("check reuses"                       , SCRP__reuses_check ("GLOBAL --" ), -999);                                                                                    <* 
    *> yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: GLOBAL no identifier within -- markers");                                     <* 
    *> yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "A-----�-----M-----�-----�-   �-----�-----�-----�-----�-");                                            <* 
    *> yUNIT_minchr  ("... check mark"                     , my.share          , '-');                                                                                                    <* 
    *> yUNIT_mindnoc ();                                                                                                                                                                  <*/

   /*> yUNIT_mincond ("check with no identifier ending");                                                                                                                                 <* 
    *> yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);                                                                                                       <* 
    *> yUNIT_minval  ("parse GLOBAL"                       , SCRP__parse_verb    (my.n_scrp, my.n_line, "GLOBAL -C" , my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code)), 0);   <* 
    *> yUNIT_minstr  ("... check verb"                     , my.verb           , "GLOBAL");                                                                                               <* 
    *> yUNIT_minval  ("check reuses"                       , SCRP__reuses_check ("GLOBAL -C" ), -999);                                                                                    <* 
    *> yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: GLOBAL identifier �C� not followed by - marker");                             <* 
    *> yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "A-----�-----M-----�-----�-   �-----�-----�-----�-----�-");                                            <* 
    *> yUNIT_minchr  ("... check mark"                     , my.share          , '-');                                                                                                    <* 
    *> yUNIT_mindnoc ();                                                                                                                                                                  <*/

   /*> yUNIT_mincond ("check with a non-valid identifier");                                                                                                                               <* 
    *> yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);                                                                                                       <* 
    *> yUNIT_minval  ("parse GLOBAL"                       , SCRP__parse_verb    (my.n_scrp, my.n_line, "GLOBAL -d-", my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code)), 0);   <* 
    *> yUNIT_minstr  ("... check verb"                     , my.verb           , "GLOBAL");                                                                                               <* 
    *> yUNIT_minval  ("check reuses"                       , SCRP__reuses_check ("GLOBAL -d-"), -999);                                                                                    <* 
    *> yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: GLOBAL identifier �d� not valid [A-Z]");                                      <* 
    *> yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "A-----�-----M-----�-----�-   �-----�-----�-----�-----�-");                                            <* 
    *> yUNIT_minchr  ("... check mark"                     , my.share          , '-');                                                                                                    <* 
    *> yUNIT_mindnoc ();                                                                                                                                                                  <*/

   /*> yUNIT_mincond ("check another good identifier");                                                                                                                                   <* 
    *> yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);                                                                                                       <* 
    *> yUNIT_minval  ("parse GLOBAL"                       , SCRP__parse_verb    (my.n_scrp, my.n_line, "GLOBAL -Y-", my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code)), 0);   <* 
    *> yUNIT_minstr  ("... check verb"                     , my.verb           , "GLOBAL");                                                                                               <* 
    *> yUNIT_minval  ("check reuses"                       , SCRP__reuses_check ("GLOBAL -Y-"), 0);                                                                                       <* 
    *> yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");                                                                                                       <* 
    *> yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "A-----�-----M-----�-----Y-   �-----�-----�-----�-----�-");                                            <* 
    *> yUNIT_minchr  ("... check mark"                     , my.share          , 'Y');                                                                                                    <* 
    *> yUNIT_mindnoc ();                                                                                                                                                                  <*/

   strcpy (my.n_base, "koios" );

   /*> yUNIT_mincond ("attempt to use GLOBAL in normal unit");                                                                                                                               <* 
    *> yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);                                                                                                          <* 
    *> yUNIT_minval  ("parse GLOBAL"                       , SCRP__parse_verb    (my.n_scrp, my.n_line, "GLOBAL -K-", my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code)), -999);   <* 
    *> yUNIT_minstr  ("... check verb"                     , my.verb           , "GLOBAL");                                                                                                  <* 
    *> yUNIT_minval  ("check reuses"                       , SCRP__reuses_check ("GLOBAL -K-"), -999);                                                                                       <* 
    *> yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: GLOBAL not allowed outside master.unit");                                        <* 
    *> yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "A-----------M-----------Y-   --------------------------   ----------");                        <* 
    *> yUNIT_minchr  ("... check mark"                     , my.share          , '-');                                                                                                       <* 
    *> yUNIT_mindnoc ();                                                                                                                                                                     <*/

   strcpy (my.n_base, "master");

   /*> yUNIT_mincond ("attempt to reuse a identifier");                                                                                                                                   <* 
    *> yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);                                                                                                       <* 
    *> yUNIT_minval  ("parse GLOBAL"                       , SCRP__parse_verb    (my.n_scrp, my.n_line, "GLOBAL -M-", my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code)), 0);   <* 
    *> yUNIT_minstr  ("... check verb"                     , my.verb           , "GLOBAL");                                                                                               <* 
    *> yUNIT_minval  ("check reuses"                       , SCRP__reuses_check ("GLOBAL -M-"), -999);                                                                                    <* 
    *> yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: GLOBAL identifier �M� already in use");                                       <* 
    *> yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "A-----------M-----------Y-   --------------------------   ----------");                     <* 
    *> yUNIT_minchr  ("... check mark"                     , my.share          , '-');                                                                                                    <* 
    *> yUNIT_mindnoc ();                                                                                                                                                                  <*/

   strcpy (my.n_base, "koios" );

   /*> yUNIT_mincond ("check good reuse of identifier");                                                                                                                                  <* 
    *> yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);                                                                                                       <* 
    *> yUNIT_minval  ("parse REUSE"                        , SCRP__parse_verb    (my.n_scrp, my.n_line, "REUSE  -M-", my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code)), 0);   <* 
    *> yUNIT_minstr  ("... check verb"                     , my.verb           , "REUSE");                                                                                                <* 
    *> yUNIT_minval  ("check reuses"                       , SCRP__reuses_check ("REUSE  -M-"), 0);                                                                                       <* 
    *> yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");                                                                                                       <* 
    *> yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "A-----------M-----------Y-   --------------------------   ----------");                     <* 
    *> yUNIT_minchr  ("... check mark"                     , my.share          , 'M');                                                                                                    <* 
    *> yUNIT_mindnoc ();                                                                                                                                                                  <*/

   /*> yUNIT_mincond ("check with no identifier string");                                                                                                                                 <* 
    *> yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);                                                                                                       <* 
    *> yUNIT_minval  ("parse REUSE"                        , SCRP__parse_verb    (my.n_scrp, my.n_line, "REUSE"     , my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code)), 0);   <* 
    *> yUNIT_minstr  ("... check verb"                     , my.verb           , "REUSE" );                                                                                               <* 
    *> yUNIT_minval  ("check reuses"                       , SCRP__reuses_check ("REUSE"     ), -999);                                                                                    <* 
    *> yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: REUSE missing a valid identifier string -?-");                                <* 
    *> yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "A-----------M-----------Y-   --------------------------   ----------");                     <* 
    *> yUNIT_minchr  ("... check mark"                     , my.share          , '-');                                                                                                    <* 
    *> yUNIT_mindnoc ();                                                                                                                                                                  <*/

   /*> yUNIT_mincond ("check with only identifier beginning");                                                                                                                            <* 
    *> yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);                                                                                                       <* 
    *> yUNIT_minval  ("parse REUSE"                        , SCRP__parse_verb    (my.n_scrp, my.n_line, "REUSE  -"  , my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code)), 0);   <* 
    *> yUNIT_minstr  ("... check verb"                     , my.verb           , "REUSE");                                                                                                <* 
    *> yUNIT_minval  ("check reuses"                       , SCRP__reuses_check ("REUSE  -"  ), -999);                                                                                    <* 
    *> yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: REUSE identifier did not follow - marker");                                   <* 
    *> yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "A-----------M-----------Y-   --------------------------   ----------");                     <* 
    *> yUNIT_minchr  ("... check mark"                     , my.share          , '-');                                                                                                    <* 
    *> yUNIT_mindnoc ();                                                                                                                                                                  <*/

   /*> yUNIT_mincond ("check with no identifier within");                                                                                                                                 <* 
    *> yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);                                                                                                       <* 
    *> yUNIT_minval  ("parse REUSE"                        , SCRP__parse_verb    (my.n_scrp, my.n_line, "REUSE  --" , my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code)), 0);   <* 
    *> yUNIT_minstr  ("... check verb"                     , my.verb           , "REUSE");                                                                                                <* 
    *> yUNIT_minval  ("check reuses"                       , SCRP__reuses_check ("REUSE  --" ), -999);                                                                                    <* 
    *> yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: REUSE no identifier within -- markers");                                      <* 
    *> yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "A-----------M-----------Y-   --------------------------   ----------");                     <* 
    *> yUNIT_minchr  ("... check mark"                     , my.share          , '-');                                                                                                    <* 
    *> yUNIT_mindnoc ();                                                                                                                                                                  <*/

   /*> yUNIT_mincond ("check with no identifier ending");                                                                                                                                 <* 
    *> yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);                                                                                                       <* 
    *> yUNIT_minval  ("parse REUSE"                        , SCRP__parse_verb    (my.n_scrp, my.n_line, "REUSE  -C" , my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code)), 0);   <* 
    *> yUNIT_minstr  ("... check verb"                     , my.verb           , "REUSE");                                                                                                <* 
    *> yUNIT_minval  ("check reuses"                       , SCRP__reuses_check ("REUSE  -C" ), -999);                                                                                    <* 
    *> yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: REUSE identifier �C� not followed by - marker");                              <* 
    *> yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "A-----------M-----------Y-   --------------------------   ----------");                     <* 
    *> yUNIT_minchr  ("... check mark"                     , my.share          , '-');                                                                                                    <* 
    *> yUNIT_mindnoc ();                                                                                                                                                                  <*/

   /*> yUNIT_mincond ("check with a non-valid identifier");                                                                                                                               <* 
    *> yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);                                                                                                       <* 
    *> yUNIT_minval  ("parse REUSE"                        , SCRP__parse_verb    (my.n_scrp, my.n_line, "REUSE  -2-", my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code)), 0);   <* 
    *> yUNIT_minstr  ("... check verb"                     , my.verb           , "REUSE");                                                                                                <* 
    *> yUNIT_minval  ("check reuses"                       , SCRP__reuses_check ("REUSE  -2-"), -999);                                                                                    <* 
    *> yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: REUSE identifier �2� not valid [a-zA-Z]");                                    <* 
    *> yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "A-----------M-----------Y-   --------------------------   ----------");                     <* 
    *> yUNIT_minchr  ("... check mark"                     , my.share          , '-');                                                                                                    <* 
    *> yUNIT_mindnoc ();                                                                                                                                                                  <*/

   /*> yUNIT_mincond ("check another good reuse of identifier");                                                                                                                          <* 
    *> yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);                                                                                                       <* 
    *> yUNIT_minval  ("parse REUSE"                        , SCRP__parse_verb    (my.n_scrp, my.n_line, "REUSE  -A-", my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code)), 0);   <* 
    *> yUNIT_minstr  ("... check verb"                     , my.verb           , "REUSE");                                                                                                <* 
    *> yUNIT_minval  ("check reuses"                       , SCRP__reuses_check ("REUSE  -A-"), 0);                                                                                       <* 
    *> yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");                                                                                                       <* 
    *> yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "A-----------M-----------Y-   --------------------------   ----------");                     <* 
    *> yUNIT_minchr  ("... check mark"                     , my.share          , 'A');                                                                                                    <* 
    *> yUNIT_mindnoc ();                                                                                                                                                                  <*/

   strcpy (my.n_base, "master");

   /*> yUNIT_mincond ("verify reuse inside master.unit");                                                                                                                                 <* 
    *> yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);                                                                                                       <* 
    *> yUNIT_minval  ("parse REUSE"                        , SCRP__parse_verb    (my.n_scrp, my.n_line, "REUSE  -A-", my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code)), 0);   <* 
    *> yUNIT_minstr  ("... check verb"                     , my.verb           , "REUSE");                                                                                                <* 
    *> yUNIT_minval  ("check reuses"                       , SCRP__reuses_check ("REUSE  -A-"), 0);                                                                                       <* 
    *> yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "A-----------M-----------Y-   --------------------------   ----------");                     <* 
    *> yUNIT_minchr  ("... check mark"                     , my.share          , 'A');                                                                                                    <* 
    *> yUNIT_mindnoc ();                                                                                                                                                                  <*/

   strcpy (my.n_base, "koios" );

   /*> yUNIT_mincond ("attempt to reuse a non-set identifier");                                                                                                                           <* 
    *> yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);                                                                                                       <* 
    *> yUNIT_minval  ("parse REUSE"                        , SCRP__parse_verb    (my.n_scrp, my.n_line, "REUSE  -K-", my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code)), 0);   <* 
    *> yUNIT_minstr  ("... check verb"                     , my.verb           , "REUSE");                                                                                                <* 
    *> yUNIT_minval  ("check reuses"                       , SCRP__reuses_check ("REUSE  -K-"), -999);                                                                                    <* 
    *> yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: REUSE identifier �K� never set by GLOBAL");                                   <* 
    *> yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "A-----------M-----------Y-   --------------------------   ----------");                     <* 
    *> yUNIT_minchr  ("... check mark"                     , my.share          , '-');                                                                                                    <* 
    *> yUNIT_mindnoc ();                                                                                                                                                                  <*/

   strcpy (my.n_base, "koios" );

   /*> yUNIT_mincond ("check a min shared identifier");                                                                                                                                   <* 
    *> yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);                                                                                                       <* 
    *> yUNIT_minval  ("parse SHARED"                       , SCRP__parse_verb    (my.n_scrp, my.n_line, "SHARED -b-", my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code)), 0);   <* 
    *> yUNIT_minstr  ("... check verb"                     , my.verb           , "SHARED");                                                                                               <* 
    *> yUNIT_minval  ("check reuses"                       , SCRP__reuses_check ("SHARED -b-"), 0);                                                                                       <* 
    *> yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");                                                                                                       <* 
    *> yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "A-----------M-----------Y-   -b------------------------   ----------");                     <* 
    *> yUNIT_minchr  ("... check mark"                     , my.share          , 'b');                                                                                                    <* 
    *> yUNIT_mindnoc ();                                                                                                                                                                  <*/

   /*> yUNIT_mincond ("check a middle shared identifier");                                                                                                                                <* 
    *> yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);                                                                                                       <* 
    *> yUNIT_minval  ("parse SHARED"                       , SCRP__parse_verb    (my.n_scrp, my.n_line, "SHARED -j-", my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code)), 0);   <* 
    *> yUNIT_minstr  ("... check verb"                     , my.verb           , "SHARED");                                                                                               <* 
    *> yUNIT_minval  ("check reuses"                       , SCRP__reuses_check ("SHARED -j-"), 0);                                                                                       <* 
    *> yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");                                                                                                       <* 
    *> yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "A-----------M-----------Y-   -b-------j----------------   ----------");                     <* 
    *> yUNIT_minchr  ("... check mark"                     , my.share          , 'j');                                                                                                    <* 
    *> yUNIT_mindnoc ();                                                                                                                                                                  <*/

   /*> yUNIT_mincond ("check with no identifier string");                                                                                                                                 <* 
    *> yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);                                                                                                       <* 
    *> yUNIT_minval  ("parse SHARED"                       , SCRP__parse_verb    (my.n_scrp, my.n_line, "SHARED"    , my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code)), 0);   <* 
    *> yUNIT_minstr  ("... check verb"                     , my.verb           , "SHARED");                                                                                               <* 
    *> yUNIT_minval  ("check reuses"                       , SCRP__reuses_check ("SHARED"    ), -999);                                                                                    <* 
    *> yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: SHARED missing a valid identifier string -?-");                               <* 
    *> yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "A-----------M-----------Y-   -b-------j----------------   ----------");                     <* 
    *> yUNIT_minchr  ("... check mark"                     , my.share          , '-');                                                                                                    <* 
    *> yUNIT_mindnoc ();                                                                                                                                                                  <*/

   /*> yUNIT_mincond ("check with only identifier beginning");                                                                                                                            <* 
    *> yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);                                                                                                       <* 
    *> yUNIT_minval  ("parse SHARED"                       , SCRP__parse_verb    (my.n_scrp, my.n_line, "SHARED -"  , my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code)), 0);   <* 
    *> yUNIT_minstr  ("... check verb"                     , my.verb           , "SHARED");                                                                                               <* 
    *> yUNIT_minval  ("check reuses"                       , SCRP__reuses_check ("SHARED -"  ), -999);                                                                                    <* 
    *> yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: SHARED identifier did not follow - marker");                                  <* 
    *> yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "A-----------M-----------Y-   -b-------j----------------   ----------");                     <* 
    *> yUNIT_minchr  ("... check mark"                     , my.share          , '-');                                                                                                    <* 
    *> yUNIT_mindnoc ();                                                                                                                                                                  <*/

   /*> yUNIT_mincond ("check with no identifier within");                                                                                                                                 <* 
    *> yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);                                                                                                       <* 
    *> yUNIT_minval  ("parse SHARED"                       , SCRP__parse_verb    (my.n_scrp, my.n_line, "SHARED --" , my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code)), 0);   <* 
    *> yUNIT_minstr  ("... check verb"                     , my.verb           , "SHARED");                                                                                               <* 
    *> yUNIT_minval  ("check reuses"                       , SCRP__reuses_check ("SHARED --" ), -999);                                                                                    <* 
    *> yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: SHARED no identifier within -- markers");                                     <* 
    *> yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "A-----------M-----------Y-   -b-------j----------------   ----------");                     <* 
    *> yUNIT_minchr  ("... check mark"                     , my.share          , '-');                                                                                                    <* 
    *> yUNIT_mindnoc ();                                                                                                                                                                  <*/

   /*> yUNIT_mincond ("check with no identifier ending");                                                                                                                                 <* 
    *> yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);                                                                                                       <* 
    *> yUNIT_minval  ("parse SHARED"                       , SCRP__parse_verb    (my.n_scrp, my.n_line, "SHARED -c" , my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code)), 0);   <* 
    *> yUNIT_minstr  ("... check verb"                     , my.verb           , "SHARED");                                                                                               <* 
    *> yUNIT_minval  ("check reuses"                       , SCRP__reuses_check ("SHARED -c" ), -999);                                                                                    <* 
    *> yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: SHARED identifier �c� not followed by - marker");                             <* 
    *> yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "A-----------M-----------Y-   -b-------j----------------   ----------");                     <* 
    *> yUNIT_minchr  ("... check mark"                     , my.share          , '-');                                                                                                    <* 
    *> yUNIT_mindnoc ();                                                                                                                                                                  <*/

   /*> yUNIT_mincond ("check with a non-valid identifier");                                                                                                                               <* 
    *> yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);                                                                                                       <* 
    *> yUNIT_minval  ("parse SHARED"                       , SCRP__parse_verb    (my.n_scrp, my.n_line, "SHARED -D-", my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code)), 0);   <* 
    *> yUNIT_minstr  ("... check verb"                     , my.verb           , "SHARED");                                                                                               <* 
    *> yUNIT_minval  ("check reuses"                       , SCRP__reuses_check ("SHARED -D-"), -999);                                                                                    <* 
    *> yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: SHARED identifier �D� not valid [a-z]");                                      <* 
    *> yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "A-----------M-----------Y-   -b-------j----------------   ----------");                     <* 
    *> yUNIT_minchr  ("... check mark"                     , my.share          , '-');                                                                                                    <* 
    *> yUNIT_mindnoc ();                                                                                                                                                                  <*/

   /*> yUNIT_mincond ("check another good identifier");                                                                                                                                   <* 
    *> yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);                                                                                                       <* 
    *> yUNIT_minval  ("parse SHARED"                       , SCRP__parse_verb    (my.n_scrp, my.n_line, "SHARED -w-", my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code)), 0);   <* 
    *> yUNIT_minstr  ("... check verb"                     , my.verb           , "SHARED");                                                                                               <* 
    *> yUNIT_minval  ("check reuses"                       , SCRP__reuses_check ("SHARED -w-"), 0);                                                                                       <* 
    *> yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");                                                                                                       <* 
    *> yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "A-----------M-----------Y-   -b-------j------------w---   ----------");                     <* 
    *> yUNIT_minchr  ("... check mark"                     , my.share          , 'w');                                                                                                    <* 
    *> yUNIT_mindnoc ();                                                                                                                                                                  <*/

   strcpy (my.n_base, "master");

   /*> yUNIT_mincond ("attempt shared inside master.unit");                                                                                                                                  <* 
    *> yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);                                                                                                          <* 
    *> yUNIT_minval  ("parse SHARED"                       , SCRP__parse_verb    (my.n_scrp, my.n_line, "SHARED -k-", my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code)), -999);   <* 
    *> yUNIT_minstr  ("... check verb"                     , my.verb           , "SHARED");                                                                                                  <* 
    *> yUNIT_minval  ("check reuses"                       , SCRP__reuses_check ("SHARED -k-"), -999);                                                                                       <* 
    *> yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: SHARED verb not allowed in master.unit");                                        <* 
    *> yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "A-----------M-----------Y-   -b-------j------------w---   ----------");                        <* 
    *> yUNIT_minchr  ("... check mark"                     , my.share          , '-');                                                                                                       <* 
    *> yUNIT_mindnoc ();                                                                                                                                                                     <*/

   strcpy (my.n_base, "koios" );

   /*> yUNIT_mincond ("check an attempt to reuse a identifier");                                                                                                                          <* 
    *> yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);                                                                                                       <* 
    *> yUNIT_minval  ("parse SHARED"                       , SCRP__parse_verb    (my.n_scrp, my.n_line, "SHARED -j-", my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code)), 0);   <* 
    *> yUNIT_minstr  ("... check verb"                     , my.verb           , "SHARED");                                                                                               <* 
    *> yUNIT_minval  ("check reuses"                       , SCRP__reuses_check ("SHARED -j-"), -999);                                                                                    <* 
    *> yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: SHARED identifier �j� already in use");                                       <* 
    *> yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "A-----------M-----------Y-   -b-------j------------w---   ----------");                     <* 
    *> yUNIT_minchr  ("... check mark"                     , my.share          , '-');                                                                                                    <* 
    *> yUNIT_mindnoc ();                                                                                                                                                                  <*/

   /*> yUNIT_mincond ("check good reuse of identifier");                                                                                                                                  <* 
    *> yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);                                                                                                       <* 
    *> yUNIT_minval  ("parse REUSE"                        , SCRP__parse_verb    (my.n_scrp, my.n_line, "REUSE  -j-", my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code)), 0);   <* 
    *> yUNIT_minstr  ("... check verb"                     , my.verb           , "REUSE");                                                                                                <* 
    *> yUNIT_minval  ("check reuses"                       , SCRP__reuses_check ("REUSE  -j-"), 0);                                                                                       <* 
    *> yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");                                                                                                       <* 
    *> yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "A-----------M-----------Y-   -b-------j------------w---   ----------");                     <* 
    *> yUNIT_minchr  ("... check mark"                     , my.share          , 'j');                                                                                                    <* 
    *> yUNIT_mindnoc ();                                                                                                                                                                  <*/

   /*> yUNIT_mincond ("attempt to reuse a non-set identifier");                                                                                                                           <* 
    *> yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);                                                                                                       <* 
    *> yUNIT_minval  ("parse REUSE"                        , SCRP__parse_verb    (my.n_scrp, my.n_line, "REUSE  -k-", my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code)), 0);   <* 
    *> yUNIT_minstr  ("... check verb"                     , my.verb           , "REUSE");                                                                                                <* 
    *> yUNIT_minval  ("check reuses"                       , SCRP__reuses_check ("REUSE  -k-"), -999);                                                                                    <* 
    *> yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: REUSE identifier �k� never set by SHARED");                                   <* 
    *> yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "A-----------M-----------Y-   -b-------j------------w---   ----------");                     <* 
    *> yUNIT_minchr  ("... check mark"                     , my.share          , '-');                                                                                                    <* 
    *> yUNIT_mindnoc ();                                                                                                                                                                  <*/

   /*> yUNIT_mincond ("check another good use of identifier");                                                                                                                            <* 
    *> yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);                                                                                                       <* 
    *> yUNIT_minval  ("parse REUSE"                        , SCRP__parse_verb    (my.n_scrp, my.n_line, "REUSE  -b-", my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code)), 0);   <* 
    *> yUNIT_minstr  ("... check verb"                     , my.verb           , "REUSE");                                                                                                <* 
    *> yUNIT_minval  ("check reuses"                       , SCRP__reuses_check ("REUSE  -b-"), 0);                                                                                       <* 
    *> yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");                                                                                                       <* 
    *> yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "A-----------M-----------Y-   -b-------j------------w---   ----------");                     <* 
    *> yUNIT_minchr  ("... check mark"                     , my.share          , 'b');                                                                                                    <* 
    *> yUNIT_mindnoc ();                                                                                                                                                                  <*/

   /*> yUNIT_mincond ("set a shared reuse point");                                                                                                                                        <* 
    *> yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);                                                                                                       <* 
    *> yUNIT_minval  ("parse SHARED"                       , SCRP__parse_verb    (my.n_scrp, my.n_line, "SHARED -s-", my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code)), 0);   <* 
    *> yUNIT_minstr  ("... check verb"                     , my.verb           , "SHARED");                                                                                               <* 
    *> yUNIT_minval  ("check reuses"                       , SCRP__reuses_check ("SHARED -s-"), 0);                                                                                       <* 
    *> yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");                                                                                                       <* 
    *> yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "A-----------M-----------Y-   -b-------j--------s---w---   ----------");                     <* 
    *> yUNIT_minchr  ("... check mark"                     , my.share          , 's');                                                                                                    <* 
    *> my.cshare = 's';                                                                                                                                                                   <* 
    *> yUNIT_minchr  ("... check current share"            , my.cshare         , 's');                                                                                                    <* 
    *> yUNIT_mindnoc ();                                                                                                                                                                  <*/

   /*> yUNIT_mincond ("attempt to reuse the current share");                                                                                                                              <* 
    *> yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);                                                                                                       <* 
    *> yUNIT_minval  ("parse REUSE"                        , SCRP__parse_verb    (my.n_scrp, my.n_line, "REUSE  -s-", my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code)), 0);   <* 
    *> yUNIT_minstr  ("... check verb"                     , my.verb           , "REUSE");                                                                                                <* 
    *> yUNIT_minval  ("check reuses"                       , SCRP__reuses_check ("REUSE  -s-"), -999);                                                                                    <* 
    *> yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: REUSE identifier �s� called inside itself, recursive");                       <* 
    *> yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "A-----------M-----------Y-   -b-------j--------s---w---   ----------");                     <* 
    *> yUNIT_minchr  ("... check mark"                     , my.share          , '-');                                                                                                    <* 
    *> yUNIT_minchr  ("... check current share"            , my.cshare         , 's');                                                                                                    <* 
    *> yUNIT_mindnoc ();                                                                                                                                                                  <*/

   /*> yUNIT_mincond ("check defaults");                                                                                                                               <* 
    *> yUNIT_minval ("... run clear"                      , SCRP__shared_purge ()         , 0);                                                                        <* 
    *> yUNIT_minstr ("... check all marks"                , SCRP__shared_used  ()         , "--------------------------   --------------------------   ----------");   <* 
    *> yUNIT_mindnoc ();                                                                                                                                               <*/

   yUNIT_mincond ("clean up after");
   system ("rm -f /tmp/koios.unit 2> /dev/null");
   yUNIT_mindnoc ();

   yUNIT_minprcs ();

   return 0;
}



/*====================------------------------------------====================*/
/*===----                         conversion                           ----===*/
/*====================------------------------------------====================*/
static void      o___CONV_NEW________________o (void) {;}

char
koios__unit_conv_defense (char a_list)
{
   char         x_cshare   =  '-';

   yUNIT_minscrp  ("CONV__defense");
   if (a_list == 'y')  return 0;
   yURG_err_none  ();

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


   yUNIT_minprcs  ();
   return 0;
}

char
koios__unit_conv_printf  (char a_list)
{
   char         x_name     [LEN_HUND] = "/tmp/koios.unit";
   char         t          [LEN_HUND] = "";
   FILE        *x_file     = NULL;

   yUNIT_minscrp  ("CONV_printf");
   if (a_list == 'y')  return 0;
   yURG_err_none  ();

   sprintf (t, "touch %s", x_name);  system (t);
   yUNIT_mincond  ("open the conversion file");
   yUNIT_minval   ("open file"                          , READ_open   (x_name, 'w', &x_file, NULL), 0);
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify printing a format only");
   yUNIT_minval   ("write line"                         , CONV_printf_new  (x_file    , "format only\n"                  ),    0);
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   0)      , "format only"                              );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   1)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("attempt with null file");
   yUNIT_minval   ("write line"                         , CONV_printf_new  (NULL      , "a mistake\n"                    ), -999);
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   0)      , "format only"                              );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   1)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify printing a single variable");
   yUNIT_minval   ("write line"                         , CONV_printf_new  (x_file    , "%s\n"                  , "testing"                  ),    0);
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   0)      , "format only"                              );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   1)      , "testing"                                  );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   2)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("attempt with null format");
   yUNIT_minval   ("write line"                         , CONV_printf_new  (x_file    , NULL                    , "testing"                  ), -999);
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   0)      , "format only"                              );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   1)      , "testing"                                  );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   2)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify printing a multiple variables");
   yUNIT_minval   ("write line"                         , CONV_printf_new  (x_file    , "%s (%d) %s\n"          , "whos"  , 52 , "heading"   ),    0);
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   0)      , "format only"                              );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   1)      , "testing"                                  );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   2)      , "whos (52) heading"                        );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   3)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("close the conversion file");
   yUNIT_minval   ("close file"                         , READ_close  (&x_file), 0);
   sprintf (t, "rm -f %s   2> /dev/null", x_name);  system (t);
   yUNIT_mindnoc  ();

   yUNIT_minprcs  ();
   return 0;
}

char
koios__unit_conv_preps   (char a_list)
{
   char         x_name     [LEN_HUND]  = "/tmp/koios.unit";
   char         t          [LEN_HUND]  = "";
   FILE        *x_file     = NULL;
   char         x_cshare   =  '-';

   yUNIT_minscrp  ("CONV_header, CONV_prep, CONV_incl, CONV_footer");
   if (a_list == 'y')  return 0;
   yURG_err_none  ();

   yUNIT_mincond  ("open the conversion file");
   yUNIT_minval   ("open file"                          , READ_open       (x_name, 'w', &x_file, NULL), 0);
   yUNIT_minval   ("... check count"                    , yURG_peek_count (x_name)               , 0);
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing a HEADER");
   yUNIT_minval   ("write conv line"                    , CONV_break_new  (x_file    ),    0);
   yUNIT_minval   ("... check count"                    , yURG_peek_count (x_name)               , 5);
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   0)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   1)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   2)      , ""                                         );
   yUNIT_minstr   ("... ruler"                          , yURG_peek       (x_name    ,   3)      , "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-123456789- ");
   yUNIT_minstr   ("... title"                          , yURG_peek       (x_name    ,   4)      , "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  ========(var)======= ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   5)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing a PREP");
   yUNIT_minval   ("write conv line"                    , CONV_prep_new   (x_file    , "PREP"    , "prototype headers"   , ""               , ""               , ""          , ""               , ""          , '-', '-', ""  , &x_cshare  ),    0);
   yUNIT_minval   ("... check count"                    , yURG_peek_count (x_name)               , 11);
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   0)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   1)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   2)      , ""                                         );
   yUNIT_minstr   ("... ruler"                          , yURG_peek       (x_name    ,   3)      , "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-123456789- ");
   yUNIT_minstr   ("... title"                          , yURG_peek       (x_name    ,   4)      , "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  ========(var)======= ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   5)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   6)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   7)      , ""                                         );
   yUNIT_minstr   ("... ruler"                          , yURG_peek       (x_name    ,   8)      , "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-123456789- ");
   yUNIT_minstr   ("... title"                          , yURG_peek       (x_name    ,   9)      , "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  ========(var)======= ");
   yUNIT_minstr   ("... check resuls"                   , yURG_peek       (x_name    ,  10)      , "PREP          prototype headers                                                  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  11)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing an INCL");
   yUNIT_minval   ("write conv line"                    , CONV_incl_new   (x_file    , "incl"    , "public header"       , "koios.h"        , ""               , ""          , ""               , ""          , '-', '-', ""  , &x_cshare  ),    0);
   yUNIT_minval   ("... check count"                    , yURG_peek_count (x_name)               , 12);
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   0)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   1)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   2)      , ""                                         );
   yUNIT_minstr   ("... ruler"                          , yURG_peek       (x_name    ,   3)      , "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-123456789- ");
   yUNIT_minstr   ("... title"                          , yURG_peek       (x_name    ,   4)      , "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  ========(var)======= ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   5)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   6)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   7)      , ""                                         );
   yUNIT_minstr   ("... ruler"                          , yURG_peek       (x_name    ,   8)      , "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-123456789- ");
   yUNIT_minstr   ("... title"                          , yURG_peek       (x_name    ,   9)      , "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  ========(var)======= ");
   yUNIT_minstr   ("... check resuls"                   , yURG_peek       (x_name    ,  10)      , "PREP          prototype headers                                                  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check resuls"                   , yURG_peek       (x_name    ,  11)      , "   incl       public header                        koios.h                     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  12)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing a COMMENT");
   yUNIT_minval   ("write conv line"                    , CONV_comment_new(x_file    , "#>"      , ""                    , ""               , ""               , ""          , "#> comment"     , ""          , '-', '-', ""  , &x_cshare  ),    0);
   yUNIT_minval   ("... check count"                    , yURG_peek_count (x_name)               , 13);
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   0)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   1)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   2)      , ""                                         );
   yUNIT_minstr   ("... ruler"                          , yURG_peek       (x_name    ,   3)      , "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-123456789- ");
   yUNIT_minstr   ("... title"                          , yURG_peek       (x_name    ,   4)      , "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  ========(var)======= ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   5)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   6)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   7)      , ""                                         );
   yUNIT_minstr   ("... ruler"                          , yURG_peek       (x_name    ,   8)      , "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-123456789- ");
   yUNIT_minstr   ("... title"                          , yURG_peek       (x_name    ,   9)      , "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  ========(var)======= ");
   yUNIT_minstr   ("... check resuls"                   , yURG_peek       (x_name    ,  10)      , "PREP          prototype headers                                                  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check resuls"                   , yURG_peek       (x_name    ,  11)      , "   incl       public header                        koios.h                     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check resuls"                   , yURG_peek       (x_name    ,  12)      , "#> comment");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  13)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("close the conversion file");
   yUNIT_minval   ("close file"                         , READ_close  (&x_file), 0);
   sprintf (t, "rm -f %s   2> /dev/null", x_name);  system (t);
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify opening file and writing a HEADER");
   yUNIT_minpoint ("... check file pointer"             , x_file                     ,  0);
   yUNIT_minval   ("write conv line"                    , CONV_header_new (x_name, &x_file, &x_cshare),    0);
   yUNIT_minpoint ("... check file pointer"             , x_file                     ,  1);
   yUNIT_minval   ("... check count"                    , yURG_peek_count (x_name)               , 2);
   yUNIT_minstr   ("... header"                         , yURG_peek       (x_name    ,   0)      , "#!/usr/local/bin/koios"                   );
   yUNIT_minstr   ("... header"                         , yURG_peek       (x_name    ,   1)      , "#   koios-polos (axis of heaven) unit testing meta-language" );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   2)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing FOOTER and closing file");
   yUNIT_minpoint ("... check file pointer"             , x_file                     ,  1);
   yUNIT_minval   ("write conv line"                    , CONV_footer_new (&x_file)                   ,    0);
   yUNIT_minpoint ("... check file pointer"             , x_file                     ,  0);
   yUNIT_minval   ("... check count"                    , yURG_peek_count (x_name)               , 6);
   yUNIT_minstr   ("... header"                         , yURG_peek       (x_name    ,   0)      , "#!/usr/local/bin/koios"                   );
   yUNIT_minstr   ("... header"                         , yURG_peek       (x_name    ,   1)      , "#   koios-polos (axis of heaven) unit testing meta-language" );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   2)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   3)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   4)      , ""                                         );
   yUNIT_minstr   ("... footer"                         , yURG_peek       (x_name    ,   5)      , "# end-of-file.  done, finito, completare, whimper [ϴ���");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   6)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("close the conversion file");
   sprintf (t, "rm -f %s   2> /dev/null", x_name);  system (t);
   yUNIT_mindnoc  ();

   yUNIT_minprcs  ();
   return 0;
}

char
koios__unit_conv_scrps   (char a_list)
{
   char         x_suf      [LEN_SHORT] = "";
   char         x_cnt      [LEN_LABEL] = "";
   char         x_name     [LEN_HUND]  = "/tmp/koios.unit";
   char         t          [LEN_HUND]  = "";
   FILE        *x_file     = NULL;
   char         x_cshare   =  '-';

   yUNIT_minscrp  ("CONV_cond, CONV_ditto, CONV_group, COND_reuse");
   if (a_list == 'y')  return 0;
   yURG_err_none  ();

   my.nscrp =  5;  my.ncond =  32;  x_cshare = '-';
   yUNIT_mincond  ("verify common outputs");
   yUNIT_minval   ("call for SCRP without stage"        , CONV__scrp_add  ('y' , '-'  , ""    , x_suf, x_cnt, &x_cshare),    0);
   yUNIT_minstr   ("... check suffix"                   , x_suf            , "");
   yUNIT_minstr   ("... check count"                    , x_cnt            , "((06.---))");
   yUNIT_minval   ("... check my.nscrp"                 , my.nscrp         ,   6);
   yUNIT_minval   ("... check my.ncond"                 , my.ncond         ,   0);
   yUNIT_minchr   ("... check x_cshare"                 , x_cshare         , '-');
   yUNIT_minval   ("call for SECT"                      , CONV__scrp_add  ('-' , '-'  , ""    , x_suf, x_cnt, &x_cshare),    0);
   yUNIT_minstr   ("... check suffix"                   , x_suf            , "");
   yUNIT_minstr   ("... check count"                    , x_cnt            , "((06.---))");
   yUNIT_minval   ("... check my.nscrp"                 , my.nscrp         ,   6);
   yUNIT_minval   ("... check my.ncond"                 , my.ncond         ,   0);
   yUNIT_minchr   ("... check x_cshare"                 , x_cshare         , '-');
   yUNIT_minval   ("call for SHARED"                    , CONV__scrp_add  ('y' , 'd'  , ""    , x_suf, x_cnt, &x_cshare),    0);
   yUNIT_minstr   ("... check suffix"                   , x_suf            , "-d-");
   yUNIT_minstr   ("... check count"                    , x_cnt            , "((dd.---))");
   yUNIT_minval   ("... check my.nscrp"                 , my.nscrp         ,   7);
   yUNIT_minval   ("... check my.ncond"                 , my.ncond         ,   0);
   yUNIT_minchr   ("... check x_cshare"                 , x_cshare         , 'd');
   yUNIT_minval   ("call for SCRP with stage"           , CONV__scrp_add  ('y' , '-'  , "��"  , x_suf, x_cnt, &x_cshare),    0);
   yUNIT_minstr   ("... check suffix"                   , x_suf            , "[��]");
   yUNIT_minstr   ("... check count"                    , x_cnt            , "((08.---))");
   yUNIT_minval   ("... check my.nscrp"                 , my.nscrp         ,   8);
   yUNIT_minval   ("... check my.ncond"                 , my.ncond         ,   0);
   yUNIT_minchr   ("... check x_cshare"                 , x_cshare         , '-');
   yUNIT_minval   ("call for GLOBAL"                    , CONV__scrp_add  ('y' , 'V'  , ""    , x_suf, x_cnt, &x_cshare),    0);
   yUNIT_minstr   ("... check suffix"                   , x_suf            , "-V-");
   yUNIT_minstr   ("... check count"                    , x_cnt            , "((VV.---))");
   yUNIT_minval   ("... check my.nscrp"                 , my.nscrp         ,   9);
   yUNIT_minval   ("... check my.ncond"                 , my.ncond         ,   0);
   yUNIT_minchr   ("... check x_cshare"                 , x_cshare         , 'V');
   yUNIT_mindnoc  ();

   sprintf (t, "touch %s", x_name);  system (t);
   yUNIT_mincond  ("open the conversion file");
   yUNIT_minval   ("open file"                          , READ_open       (x_name, 'w', &x_file, NULL), 0);
   yUNIT_minval   ("... check count"                    , yURG_peek_count (x_name)               , 0);
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing a SCRP without stage");
   yUNIT_minval   ("write conv line"                    , CONV_scrp_new   (x_file    , "SCRP"    , "test funky thing"    , "func1, func2"   , ""               , "5m"        , ""               , "funky"     , '-', '-', ""  , &x_cshare  ),    0);
   yUNIT_minval   ("... check count"                    , yURG_peek_count (x_name)               , 6);
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   0)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   1)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   2)      , ""                                         );
   yUNIT_minstr   ("... ruler"                          , yURG_peek       (x_name    ,   3)      , "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-123456789- ");
   yUNIT_minstr   ("... title"                          , yURG_peek       (x_name    ,   4)      , "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  ========(var)======= ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   5)      , "SCRP          test funky thing                                                   5m   funky           func1, func2                                                                 ((10.---))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   6)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing a SCRP with stage");
   yUNIT_minval   ("write conv line"                    , CONV_scrp_new   (x_file    , "SCRP"    , "critical test"       , "yURG_huge"      , ""               , "3s"        , ""               , "BOOMy"     , '-', '-', "��", &x_cshare  ),    0);
   yUNIT_minval   ("... check count"                    , yURG_peek_count (x_name)               , 12);
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   0)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   1)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   2)      , ""                                         );
   yUNIT_minstr   ("... ruler"                          , yURG_peek       (x_name    ,   3)      , "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-123456789- ");
   yUNIT_minstr   ("... title"                          , yURG_peek       (x_name    ,   4)      , "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  ========(var)======= ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   5)      , "SCRP          test funky thing                                                   5m   funky           func1, func2                                                                 ((10.---))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   6)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   7)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   8)      , ""                                         );
   yUNIT_minstr   ("... ruler"                          , yURG_peek       (x_name    ,   9)      , "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-123456789- ");
   yUNIT_minstr   ("... title"                          , yURG_peek       (x_name    ,  10)      , "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  ========(var)======= ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  11)      , "SCRP    [��]  critical test                                                      3s   BOOMy           yURG_huge                                                                    ((11.---))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  12)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing a SECT");
   yUNIT_minval   ("write conv line"                    , CONV_sect_new   (x_file    , "SECT"    , "big stuff here"      , ""               , ""               , ""          , ""               , ""          , '-', '-', ""  , &x_cshare  ),    0);
   yUNIT_minval   ("... check count"                    , yURG_peek_count (x_name)               , 18);
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   0)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   1)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   2)      , ""                                         );
   yUNIT_minstr   ("... ruler"                          , yURG_peek       (x_name    ,   3)      , "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-123456789- ");
   yUNIT_minstr   ("... title"                          , yURG_peek       (x_name    ,   4)      , "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  ========(var)======= ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   5)      , "SCRP          test funky thing                                                   5m   funky           func1, func2                                                                 ((10.---))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   6)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   7)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   8)      , ""                                         );
   yUNIT_minstr   ("... ruler"                          , yURG_peek       (x_name    ,   9)      , "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-123456789- ");
   yUNIT_minstr   ("... title"                          , yURG_peek       (x_name    ,  10)      , "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  ========(var)======= ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  11)      , "SCRP    [��]  critical test                                                      3s   BOOMy           yURG_huge                                                                    ((11.---))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  12)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  13)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  14)      , ""                                         );
   yUNIT_minstr   ("... ruler"                          , yURG_peek       (x_name    ,  15)      , "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-123456789- ");
   yUNIT_minstr   ("... title"                          , yURG_peek       (x_name    ,  16)      , "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  ========(var)======= ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  17)      , "SECT          big stuff here                                                     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  18)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing a SHARED");
   yUNIT_minval   ("write conv line"                    , CONV_shared_new (x_file    , "SHARED"  , "in the same file"    , ""               , ""               , "0s"        , ""               , "simple"    , 'a', '-', ""  , &x_cshare  ),    0);
   yUNIT_minval   ("... check count"                    , yURG_peek_count (x_name)               , 24);
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   0)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   1)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   2)      , ""                                         );
   yUNIT_minstr   ("... ruler"                          , yURG_peek       (x_name    ,   3)      , "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-123456789- ");
   yUNIT_minstr   ("... title"                          , yURG_peek       (x_name    ,   4)      , "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  ========(var)======= ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   5)      , "SCRP          test funky thing                                                   5m   funky           func1, func2                                                                 ((10.---))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   6)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   7)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   8)      , ""                                         );
   yUNIT_minstr   ("... ruler"                          , yURG_peek       (x_name    ,   9)      , "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-123456789- ");
   yUNIT_minstr   ("... title"                          , yURG_peek       (x_name    ,  10)      , "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  ========(var)======= ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  11)      , "SCRP    [��]  critical test                                                      3s   BOOMy           yURG_huge                                                                    ((11.---))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  12)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  13)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  14)      , ""                                         );
   yUNIT_minstr   ("... ruler"                          , yURG_peek       (x_name    ,  15)      , "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-123456789- ");
   yUNIT_minstr   ("... title"                          , yURG_peek       (x_name    ,  16)      , "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  ========(var)======= ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  17)      , "SECT          big stuff here                                                     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  18)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  19)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  20)      , ""                                         );
   yUNIT_minstr   ("... ruler"                          , yURG_peek       (x_name    ,  21)      , "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-123456789- ");
   yUNIT_minstr   ("... title"                          , yURG_peek       (x_name    ,  22)      , "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  ========(var)======= ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  23)      , "SHARED   -a-  in the same file                                                   0s   simple                                                                                       ((aa.---))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  24)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing a GLOBAL");
   yUNIT_minval   ("write conv line"                    , CONV_global_new (x_file    , "GLOBAL"  , "in the master file"  , ""               , ""               , "5s"        , ""               , "central"   , 'Z', '-', ""  , &x_cshare  ),    0);
   yUNIT_minval   ("... check count"                    , yURG_peek_count (x_name)               , 30);
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   0)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   1)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   2)      , ""                                         );
   yUNIT_minstr   ("... ruler"                          , yURG_peek       (x_name    ,   3)      , "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-123456789- ");
   yUNIT_minstr   ("... title"                          , yURG_peek       (x_name    ,   4)      , "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  ========(var)======= ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   5)      , "SCRP          test funky thing                                                   5m   funky           func1, func2                                                                 ((10.---))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   6)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   7)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   8)      , ""                                         );
   yUNIT_minstr   ("... ruler"                          , yURG_peek       (x_name    ,   9)      , "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-123456789- ");
   yUNIT_minstr   ("... title"                          , yURG_peek       (x_name    ,  10)      , "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  ========(var)======= ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  11)      , "SCRP    [��]  critical test                                                      3s   BOOMy           yURG_huge                                                                    ((11.---))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  12)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  13)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  14)      , ""                                         );
   yUNIT_minstr   ("... ruler"                          , yURG_peek       (x_name    ,  15)      , "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-123456789- ");
   yUNIT_minstr   ("... title"                          , yURG_peek       (x_name    ,  16)      , "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  ========(var)======= ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  17)      , "SECT          big stuff here                                                     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  18)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  19)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  20)      , ""                                         );
   yUNIT_minstr   ("... ruler"                          , yURG_peek       (x_name    ,  21)      , "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-123456789- ");
   yUNIT_minstr   ("... title"                          , yURG_peek       (x_name    ,  22)      , "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  ========(var)======= ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  23)      , "SHARED   -a-  in the same file                                                   0s   simple                                                                                       ((aa.---))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  24)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  25)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  26)      , ""                                         );
   yUNIT_minstr   ("... ruler"                          , yURG_peek       (x_name    ,  27)      , "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-123456789- ");
   yUNIT_minstr   ("... title"                          , yURG_peek       (x_name    ,  28)      , "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  ========(var)======= ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  29)      , "GLOBAL   -Z-  in the master file                                                 5s   central                                                                                      ((ZZ.---))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  30)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("close the conversion file");
   yUNIT_minval   ("close file"                         , READ_close  (&x_file), 0);
   sprintf (t, "rm -f %s   2> /dev/null", x_name);  system (t);
   yUNIT_mindnoc  ();

   yUNIT_minprcs  ();
   return 0;
}

char
koios__unit_conv_conds   (char a_list)
{
   char         x_suf      [LEN_SHORT] = "";
   char         x_cnt      [LEN_LABEL] = "";
   char         x_name     [LEN_HUND]  = "/tmp/koios.unit";
   char         t          [LEN_HUND]  = "";
   FILE        *x_file     = NULL;
   char         x_cshare   =  '-';

   yUNIT_minscrp  ("CONV_cond, CONV_ditto, CONV_group, COND_reuse");
   if (a_list == 'y')  return 0;
   yURG_err_none  ();

   my.nscrp =  2;  my.ncond =  32;
   yUNIT_mincond  ("verify common outputs");
   yUNIT_minval   ("call common"                        , CONV__cond_add  ('-'  , '-'  , x_suf, x_cnt),    0);
   yUNIT_minstr   ("... check suffix"                   , x_suf            , "");
   yUNIT_minstr   ("... check count"                    , x_cnt            , "((02.033))");
   yUNIT_minval   ("call marked"                        , CONV__cond_add  ('2'  , '-'  , x_suf, x_cnt),    0);
   yUNIT_minstr   ("... check suffix"                   , x_suf            , "(2)");
   yUNIT_minstr   ("... check count"                    , x_cnt            , "((02.034))");
   yUNIT_minval   ("call shared"                        , CONV__cond_add  ('-'  , 'b'  , x_suf, x_cnt),    0);
   yUNIT_minstr   ("... check suffix"                   , x_suf            , "");
   yUNIT_minstr   ("... check count"                    , x_cnt            , "((bb.035))");
   yUNIT_mindnoc  ();

   sprintf (t, "touch %s", x_name);  system (t);
   yUNIT_mincond  ("open the conversion file");
   yUNIT_minval   ("open file"                          , READ_open       (x_name, 'w', &x_file, NULL), 0);
   yUNIT_minval   ("... check count"                    , yURG_peek_count (x_name)               , 0);
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing a COND not marked");
   yUNIT_minval   ("write conv line"                    , CONV_cond_new   (x_file    , "COND"    , "initialize"          , ""               , ""               , ""          , ""               , ""          , '-', '-', ""  , &x_cshare  ),    0);
   yUNIT_minval   ("... check count"                    , yURG_peek_count (x_name)               , 2);
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   0)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   1)      , "   COND       initialize                                                         - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((02.036))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   2)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing a COND with mark");
   yUNIT_minval   ("write conv line"                    , CONV_cond_new   (x_file    , "COND"    , "setting a mark"      , ""               , ""               , ""          , ""               , ""          , '-', '2', ""  , &x_cshare  ),    0);
   yUNIT_minval   ("... check count"                    , yURG_peek_count (x_name)               , 4);
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   0)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   1)      , "   COND       initialize                                                         - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((02.036))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   2)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   3)      , "   COND  (2)  setting a mark                                                     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((02.037))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   4)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing a COND in a share");
   yUNIT_minval   ("write conv line"                    , CONV_cond_new   (x_file    , "COND"    , "within a share"      , ""               , ""               , ""          , ""               , ""          , 'b', '-', ""  , &x_cshare  ),    0);
   yUNIT_minval   ("... check count"                    , yURG_peek_count (x_name)               , 6);
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   0)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   1)      , "   COND       initialize                                                         - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((02.036))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   2)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   3)      , "   COND  (2)  setting a mark                                                     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((02.037))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   4)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   5)      , "   COND       within a share                                                     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((bb.038))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   6)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing a DITTO");
   yUNIT_minval   ("write conv line"                    , CONV_ditto_new  (x_file    , "DITTO"   , "call back desc"      , ""               , ""               , ""          , ""               , ""          , '-', '5', ""  , &x_cshare  ),    0);
   yUNIT_minval   ("... check count"                    , yURG_peek_count (x_name)               , 8);
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   0)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   1)      , "   COND       initialize                                                         - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((02.036))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   2)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   3)      , "   COND  (2)  setting a mark                                                     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((02.037))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   4)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   5)      , "   COND       within a share                                                     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((bb.038))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   6)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   7)      , "   DITTO (5)  call back desc                                                     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((02.039))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   8)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing a REUSE");
   yUNIT_minval   ("write conv line"                    , CONV_reuse_new  (x_file    , "REUSE"   , "call share"          , ""               , ""               , ""          , ""               , ""          , '-', 's', ""  , &x_cshare  ),    0);
   yUNIT_minval   ("... check count"                    , yURG_peek_count (x_name)               , 10);
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   0)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   1)      , "   COND       initialize                                                         - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((02.036))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   2)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   3)      , "   COND  (2)  setting a mark                                                     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((02.037))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   4)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   5)      , "   COND       within a share                                                     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((bb.038))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   6)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   7)      , "   DITTO (5)  call back desc                                                     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((02.039))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   8)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   9)      , "   REUSE (s)  call share                                                         - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((02.040))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  10)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing a GROUP");
   yUNIT_minval   ("write conv line"                    , CONV_group_new  (x_file    , "GROUP"   , "connected stuff"     , ""               , ""               , ""          , ""               , ""          , '-', '-', ""  , &x_cshare  ),    0);
   yUNIT_minval   ("... check count"                    , yURG_peek_count (x_name)               , 12);
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   0)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   1)      , "   COND       initialize                                                         - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((02.036))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   2)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   3)      , "   COND  (2)  setting a mark                                                     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((02.037))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   4)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   5)      , "   COND       within a share                                                     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((bb.038))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   6)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   7)      , "   DITTO (5)  call back desc                                                     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((02.039))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   8)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   9)      , "   REUSE (s)  call share                                                         - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((02.040))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  10)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  11)      , "   GROUP      connected stuff                                                    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  12)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("close the conversion file");
   yUNIT_minval   ("close file"                         , READ_close  (&x_file), 0);
   sprintf (t, "rm -f %s   2> /dev/null", x_name);  system (t);
   yUNIT_mindnoc  ();

   yUNIT_minprcs  ();
   return 0;
}

char
koios__unit_conv_steps   (char a_list)
{
   char         x_name     [LEN_HUND] = "/tmp/koios.unit";
   char         t          [LEN_HUND] = "";
   FILE        *x_file     = NULL;
   char         x_cshare   =  '-';

   yUNIT_minscrp  ("CONV_exec, CONV_load, CONV_file, CONV_appe, CONV_mode, CONV_code, CONV_gvar, CONV_echo");
   if (a_list == 'y')  return 0;
   yURG_err_none  ();

   sprintf (t, "touch %s", x_name);  system (t);
   yUNIT_mincond  ("open the conversion file");
   yUNIT_minval   ("open file"                          , READ_open   (x_name, 'w', &x_file, NULL), 0);
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing an EXEC");
   yUNIT_minval   ("write conv line"                    , CONV_exec_new  (x_file    , "exec"    , "call the function"   , "DITTO_parse"    , "x, y, 21"       , "s_equal"   , "pretty expected", "x_str"     , '-', '-', ""  , &x_cshare  ),    0);
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   0)      , "     exec     call the function                    DITTO_parse                 x, y, 21                                                                                              s_equal     pretty expected                                                                                       x_str                ");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   1)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing a LOAD");
   yUNIT_minval   ("write conv line"                    , CONV_load_new  (x_file    , "load"    , "prepare input"       , "stdin"          , ""               , ""          , "test � 15 � a"  , ""          , '-', '-', ""  , &x_cshare  ),    0);
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   0)      , "     exec     call the function                    DITTO_parse                 x, y, 21                                                                                              s_equal     pretty expected                                                                                       x_str                ");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   1)      , "     load     prepare input                        stdin                       test � 15 � a                                                                                                                                                                                                              ");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   2)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing a FILE");
   yUNIT_minval   ("write conv line"                    , CONV_file_new  (x_file    , "file"    , "read for writing"    , ""               , ""               , ""          , "[[ my.file ]]"  , ""          , '-', '-', ""  , &x_cshare  ),    0);
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   0)      , "     exec     call the function                    DITTO_parse                 x, y, 21                                                                                              s_equal     pretty expected                                                                                       x_str                ");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   1)      , "     load     prepare input                        stdin                       test � 15 � a                                                                                                                                                                                                              ");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   2)      , "     file     read for writing                     - - - - - - - - - - - - -   [[ my.file ]]                                                                                                                                                                                                              ");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   3)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing an APPEND");
   yUNIT_minval   ("write conv line"                    , CONV_append_new  (x_file    , "append"  , "... add a record"    , ""               , ""               , ""          , "nice data"      , ""          , '-', '-', ""  , &x_cshare  ),    0);
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   0)      , "     exec     call the function                    DITTO_parse                 x, y, 21                                                                                              s_equal     pretty expected                                                                                       x_str                ");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   1)      , "     load     prepare input                        stdin                       test � 15 � a                                                                                                                                                                                                              ");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   2)      , "     file     read for writing                     - - - - - - - - - - - - -   [[ my.file ]]                                                                                                                                                                                                              ");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   3)      , "     append   ... add a record                     - - - - - - - - - - - - -   nice data                                                                                                                                                                                                                  "); 
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   4)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing a CODE");
   yUNIT_minval   ("write conv line"                    , CONV_code_new  (x_file    , "code"    , "update prefix"       , ""               , ""               , ""          , "x_one = 13;"    , ""          , '-', '-', ""  , &x_cshare  ),    0);
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   0)      , "     exec     call the function                    DITTO_parse                 x, y, 21                                                                                              s_equal     pretty expected                                                                                       x_str                ");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   1)      , "     load     prepare input                        stdin                       test � 15 � a                                                                                                                                                                                                              ");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   2)      , "     file     read for writing                     - - - - - - - - - - - - -   [[ my.file ]]                                                                                                                                                                                                              ");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   3)      , "     append   ... add a record                     - - - - - - - - - - - - -   nice data                                                                                                                                                                                                                  "); 
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   4)      , "     code     update prefix                        - - - - - - - - - - - - -   x_one = 13;                                                                                                                                                                                                                ");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   5)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing a global variable");
   yUNIT_minval   ("write conv line"                    , CONV_gvar_new  (x_file    , "global"  , "global variable"     , ""               , ""               , ""          , "short a = 5;"   , ""          , '-', '-', ""  , &x_cshare  ),    0);
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   0)      , "     exec     call the function                    DITTO_parse                 x, y, 21                                                                                              s_equal     pretty expected                                                                                       x_str                ");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   1)      , "     load     prepare input                        stdin                       test � 15 � a                                                                                                                                                                                                              ");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   2)      , "     file     read for writing                     - - - - - - - - - - - - -   [[ my.file ]]                                                                                                                                                                                                              ");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   3)      , "     append   ... add a record                     - - - - - - - - - - - - -   nice data                                                                                                                                                                                                                  "); 
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   4)      , "     code     update prefix                        - - - - - - - - - - - - -   x_one = 13;                                                                                                                                                                                                                ");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   5)      , "   global     global variable                      - - - - - - - - - - - - -   short a = 5;                                                                                                                                                                                                               ");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   6)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing a local variable");
   yUNIT_minval   ("write conv line"                    , CONV_code_new  (x_file    , "local"   , "local variable"      , ""               , ""               , ""          , "char rc = 0;"   , ""          , '-', '-', ""  , &x_cshare  ),    0);
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   0)      , "     exec     call the function                    DITTO_parse                 x, y, 21                                                                                              s_equal     pretty expected                                                                                       x_str                ");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   1)      , "     load     prepare input                        stdin                       test � 15 � a                                                                                                                                                                                                              ");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   2)      , "     file     read for writing                     - - - - - - - - - - - - -   [[ my.file ]]                                                                                                                                                                                                              ");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   3)      , "     append   ... add a record                     - - - - - - - - - - - - -   nice data                                                                                                                                                                                                                  "); 
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   4)      , "     code     update prefix                        - - - - - - - - - - - - -   x_one = 13;                                                                                                                                                                                                                ");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   5)      , "   global     global variable                      - - - - - - - - - - - - -   short a = 5;                                                                                                                                                                                                               ");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   6)      , "     local    local variable                       - - - - - - - - - - - - -   char rc = 0;                                                                                                                                                                                                               ");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   7)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing an ECHO");
   yUNIT_minval   ("write conv line"                    , CONV_echo_new  (x_file    , "echo"    , "... check value"     , ""               , "x_act"          , "s_equal"   , "[[ x_exp ]]"    , ""          , '-', '-', ""  , &x_cshare  ),    0);
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   0)      , "     exec     call the function                    DITTO_parse                 x, y, 21                                                                                              s_equal     pretty expected                                                                                       x_str                ");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   1)      , "     load     prepare input                        stdin                       test � 15 � a                                                                                                                                                                                                              ");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   2)      , "     file     read for writing                     - - - - - - - - - - - - -   [[ my.file ]]                                                                                                                                                                                                              ");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   3)      , "     append   ... add a record                     - - - - - - - - - - - - -   nice data                                                                                                                                                                                                                  "); 
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   4)      , "     code     update prefix                        - - - - - - - - - - - - -   x_one = 13;                                                                                                                                                                                                                ");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   5)      , "   global     global variable                      - - - - - - - - - - - - -   short a = 5;                                                                                                                                                                                                               ");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   6)      , "     local    local variable                       - - - - - - - - - - - - -   char rc = 0;                                                                                                                                                                                                               ");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   7)      , "     echo     ... check value                      - - - - - - - - - - - - -   x_act                                                                                                 s_equal     [[ x_exp ]]                                                                                          ");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   8)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("close the conversion file");
   yUNIT_minval   ("close file"                         , READ_close  (&x_file), 0);
   sprintf (t, "rm -f %s   2> /dev/null", x_name);  system (t);
   yUNIT_mindnoc  ();

   yUNIT_minprcs  ();
   return 0;
}

char
koios__unit_conv_driver  (char a_list)
{
   char         x_name     [LEN_HUND]  = "/tmp/koios.unit";
   char         t          [LEN_HUND]  = "";
   FILE        *x_file     = NULL;
   char         x_cshare   =  '-';

   yUNIT_minscrp  ("CONV_driver");
   if (a_list == 'y')  return 0;
   yURG_err_none  ();

   yUNIT_mincond  ("verify creating and writing the opening");
   yUNIT_minval   ("write conv line"                    , CONV_header_new (x_name, &x_file, &x_cshare),    0);
   yUNIT_minval   ("write conv line"                    , CONV_prep_new   (x_file    , "PREP"    , "prototype headers"   , ""               , ""               , ""          , ""               , ""          , '-', '-', ""  , &x_cshare  ),    0);
   yUNIT_minval   ("write conv line"                    , CONV_incl_new   (x_file    , "incl"    , "public header"       , "koios.h"        , ""               , ""          , ""               , ""          , '-', '-', ""  , &x_cshare  ),    0);
   yUNIT_minval   ("... check count"                    , yURG_peek_count (x_name)               , 9);
   yUNIT_minstr   ("... header"                         , yURG_peek       (x_name    ,   0)      , "#!/usr/local/bin/koios"                   );
   yUNIT_minstr   ("... header"                         , yURG_peek       (x_name    ,   1)      , "#   koios-polos (axis of heaven) unit testing meta-language" );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   2)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   3)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   4)      , ""                                         );
   yUNIT_minstr   ("... ruler"                          , yURG_peek       (x_name    ,   5)      , "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-123456789- ");
   yUNIT_minstr   ("... title"                          , yURG_peek       (x_name    ,   6)      , "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  ========(var)======= ");
   yUNIT_minstr   ("... check resuls"                   , yURG_peek       (x_name    ,   7)      , "PREP          prototype headers                                                  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check resuls"                   , yURG_peek       (x_name    ,   8)      , "   incl       public header                        koios.h                     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   9)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing a SCRP");
   yUNIT_minval   ("write conv line"                    , CONV_driver     (CONV_scrp_new         , x_file    , "SCRP"    , "sample testing"      , "CONV_scrp"      , ""               , "5s"        , ""               , "test"      , '-', '-', "��", &x_cshare  ),    0);
   yUNIT_minval   ("... check count"                    , yURG_peek_count (x_name)               , 15);
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   9)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  10)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  11)      , ""                                         );
   yUNIT_minstr   ("... ruler"                          , yURG_peek       (x_name    ,  12)      , "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-123456789- ");
   yUNIT_minstr   ("... title"                          , yURG_peek       (x_name    ,  13)      , "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  ========(var)======= ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  14)      , "SCRP    [��]  sample testing                                                     5s   test            CONV_scrp                                                                    ((01.---))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  15)      , ""                                         );

   yUNIT_mincond  ("verify writing a COND");               
   yUNIT_minval   ("write conv line"                    , CONV_driver     (CONV_cond_new         , x_file    , "COND"    , "repeating condition" , ""               , ""               , ""          , ""               , ""          , '-', '2', ""  , &x_cshare  ),    0);
   yUNIT_minval   ("write conv line"                    , CONV_driver     (CONV_exec_new         , x_file    , "exec"    , "call the function"   , "DITTO_parse"    , "x, y, 21"       , "s_equal"   , "pretty expected", "x_str"     , '-', '-', ""  , &x_cshare  ),    0);
   yUNIT_minval   ("write conv line"                    , CONV_driver     (CONV_code_new         , x_file    , "code"    , "update prefix"       , ""               , ""               , ""          , "x_one = 13;"    , ""          , '-', '-', ""  , &x_cshare  ),    0);
   yUNIT_minval   ("... check count"                    , yURG_peek_count (x_name)               , 19);
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  15)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  16)      , "   COND  (2)  repeating condition                                                - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((01.001))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  17)      , "     exec     call the function                    DITTO_parse                 x, y, 21                                                                                              s_equal     pretty expected                                                                                       x_str                ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  18)      , "     code     update prefix                        - - - - - - - - - - - - -   x_one = 13;                                                                                                                                                                                                                ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  19)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing another COND");               
   yUNIT_minval   ("write conv line"                    , CONV_driver     (CONV_cond_new         , x_file    , "COND"    , "another condition"   , ""               , ""               , ""          , ""               , ""          , '-', '-', ""  , &x_cshare  ),    0);
   yUNIT_minval   ("write conv line"                    , CONV_driver     (CONV_echo_new         , x_file    , "echo"    , "... check value"     , ""               , "x_act"          , "s_equal"   , "[[ x_exp ]]"    , ""          , '-', '-', ""  , &x_cshare  ),    0);
   yUNIT_minval   ("... check count"                    , yURG_peek_count (x_name)               , 22);
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  19)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  20)      , "   COND       another condition                                                  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((01.002))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  21)      , "     echo     ... check value                      - - - - - - - - - - - - -   x_act                                                                                                 s_equal     [[ x_exp ]]                                                                                          ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  22)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing another SCRP");
   yUNIT_minval   ("write conv line"                    , CONV_driver     (CONV_scrp_new         , x_file    , "SCRP"    , "check numbering"     , "CONV_cond"      , ""               , "10m"       , ""               , "another"   , '-', '-', "��", &x_cshare  ),    0);
   yUNIT_minval   ("... check count"                    , yURG_peek_count (x_name)               , 28);
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  22)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  23)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  24)      , ""                                         );
   yUNIT_minstr   ("... ruler"                          , yURG_peek       (x_name    ,  25)      , "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-123456789- ");
   yUNIT_minstr   ("... title"                          , yURG_peek       (x_name    ,  26)      , "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  ========(var)======= ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  27)      , "SCRP    [��]  check numbering                                                    10m  another         CONV_cond                                                                    ((02.---))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  28)      , ""                                         );

   yUNIT_mincond  ("verify writing COND in second SCRP");               
   yUNIT_minval   ("write conv line"                    , CONV_driver     (CONV_cond_new         , x_file    , "COND"    , "checking"            , ""               , ""               , ""          , ""               , ""          , '-', '-', ""  , &x_cshare  ),    0);
   yUNIT_minval   ("write conv line"                    , CONV_driver     (CONV_code_new         , x_file    , "local"   , "local variable"      , ""               , ""               , ""          , "char rc = 0;"   , ""          , '-', '-', ""  , &x_cshare  ),    0);
   yUNIT_minval   ("... check count"                    , yURG_peek_count (x_name)               , 31);
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  28)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  29)      , "   COND       checking                                                           - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((02.001))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  30)      , "     local    local variable                       - - - - - - - - - - - - -   char rc = 0;                                                                                                                                                                                                               ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  31)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing FOOTER and closing file");
   yUNIT_minval   ("write conv line"                    , CONV_footer_new (&x_file)                   ,    0);
   yUNIT_minval   ("... check count"                    , yURG_peek_count (x_name)               , 35);
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  31)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  32)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  33)      , ""                                         );
   yUNIT_minstr   ("... footer"                         , yURG_peek       (x_name    ,  34)      , "# end-of-file.  done, finito, completare, whimper [ϴ���");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  35)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("close the conversion file");
   sprintf (t, "rm -f %s   2> /dev/null", x_name);  system (t);
   yUNIT_mindnoc  ();

   yUNIT_minprcs  ();
   return 0;
}


/*====================------------------------------------====================*/
/*===----                     script reading                           ----===*/
/*====================------------------------------------====================*/
static void      o___CODE____________________o (void) {;}

char
koios__unit_code_display (char a_list)
{
   char         x_display  [LEN_RECD]  = "";
   char         x_system   [LEN_RECD]  = "";
   char         x_load     [LEN_RECD]  = "";

   yUNIT_minscrp  ("CODE__display");
   if (a_list == 'y')  return 0;
   yURG_err_none  ();

   yUNIT_mincond  ("verify quick success");
   yUNIT_minval   ("convert code"                       , CODE__display    ("a = 5;"                                                             , x_display, x_system , x_load   ),    0);
   yUNIT_minstr   ("... check display"                  , x_display     , "a = 5;");
   yUNIT_minstr   ("... check system"                   , x_system      , "a = 5;");
   yUNIT_minstr   ("... check load"                     , x_load        , "a = 5;");
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify field and group markers");
   yUNIT_minval   ("convert code"                       , CODE__display    ("verb � field � 123 �"                                               , x_display, x_system , x_load   ),    0);
   yUNIT_minstr   ("... check display"                  , x_display     , "verb � field � 123 �");
   yUNIT_minstr   ("... check system"                   , x_system      , "verb  field  123 ");
   yUNIT_minstr   ("... check load"                     , x_load        , "verb  field  123 ");
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify extended characters");
   yUNIT_minval   ("convert code"                       , CODE__display    ("� � � � � � � �"                                                    , x_display, x_system , x_load   ),    0);
   yUNIT_minstr   ("... check display"                  , x_display     , "� � � � � � � �");
   yUNIT_minstr   ("... check system"                   , x_system      , "� � � � � � � �");
   yUNIT_minstr   ("... check load"                     , x_load        , "� � � � � � � �");
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify quotes");
   yUNIT_minval   ("convert code"                       , CODE__display    ("the \"quoted\" text"                                                , x_display, x_system , x_load   ),    0);
   yUNIT_minstr   ("... check display"                  , x_display     , "the �quoted� text");
   yUNIT_minstr   ("... check system"                   , x_system      , "the \"quoted\" text");
   yUNIT_minstr   ("... check load"                     , x_load        , "the ~quoted~ text");
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify returns and escapes");
   yUNIT_minval   ("convert code"                       , CODE__display    (":macro\n or � and \e end or �"                                      , x_display, x_system , x_load   ),    0);
   yUNIT_minstr   ("... check display"                  , x_display     , ":macro� or � and � end or �");
   yUNIT_minstr   ("... check system"                   , x_system      , ":macro\\n or � and \\e end or �");
   yUNIT_minstr   ("... check load"                     , x_load        , ":macro\\n or � and \\e end or �");
   yUNIT_mindnoc  ();

   yUNIT_minprcs  ();
   return 0;
}

char
koios__unit_code_prefix  (char a_list)
{
   char         x_name     [LEN_HUND] = "/tmp/koios.c";
   FILE        *x_file     = NULL;
   char         x_display  [LEN_RECD]  = "";
   char         x_system   [LEN_RECD]  = "";
   char         x_load     [LEN_RECD]  = "";
   char         t          [LEN_HUND] = "";

   yUNIT_minscrp  ("CODE__prefix");
   if (a_list == 'y')  return 0;
   yURG_err_none  ();

   sprintf (t, "rm -f %s 2> /dev/null", x_name);
   system (t);
   yUNIT_mincond ("prepare clean start");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond  ("open code file");
   yUNIT_minval   ("open the code file"                 , READ_open   (x_name, 'w', &x_file, NULL   ),    0);
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify quick success (string)");
   yUNIT_minval   ("convert code"                       , CODE__display    ("\"pretty expected\""                                              , x_display, x_system , x_load   ),    0);
   yUNIT_minval   ("write prefix code"                  , CODE__prefix     (x_file    , "exec"    , "call the function"   , "DITTO_parse"    , "s_equal"   , x_display, x_system ),    0);
   CONV_printf_new (x_file, "\n");
   fflush (x_file);
   yUNIT_minval   ("... check count"                    , yURG_peek_count  (x_name)               , 3);
   yUNIT_minstr   ("... header"                         , yURG_peek        (x_name    ,   0)      , "      yUNIT_reset_rc ();"                 );
   yUNIT_minstr   ("... header"                         , yURG_peek        (x_name    ,   1)      , "      if (cyUNIT.exec)  cyUNIT.s_rc = DITTO_parse (\"pretty expected\");");
   yUNIT_minstr   ("... header"                         , yURG_peek        (x_name    ,   2)      , "      yUNIT_string  (   0,   0, \"call the function\", \"DITTO_parse\", \"�pretty expected�\", \"s_equal\", ");
   yUNIT_minstr   ("... header"                         , yURG_peek        (x_name    ,   3)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify a void");
   yUNIT_minval   ("convert code"                       , CODE__display    ("15, 67"                                                           , x_display, x_system , x_load   ),    0);
   yUNIT_minval   ("write prefix code"                  , CODE__prefix     (x_file    , "exec"    , "deal with a void"    , "MAIN_driver"    , "v_void"    , x_display, x_system ),    0);
   fflush (x_file);
   yUNIT_minval   ("... check count"                    , yURG_peek_count  (x_name)               , 6);
   yUNIT_minstr   ("... header"                         , yURG_peek        (x_name    ,   3)      , "      yUNIT_reset_rc ();"                 );
   yUNIT_minstr   ("... header"                         , yURG_peek        (x_name    ,   4)      , "      if (cyUNIT.exec)  MAIN_driver (15, 67);");
   yUNIT_minstr   ("... header"                         , yURG_peek        (x_name    ,   5)      , "      yUNIT_void    (   0,   0, \"deal with a void\", \"MAIN_driver\", \"15, 67\", \"v_void\", cyUNIT.exec);");
   yUNIT_minstr   ("... header"                         , yURG_peek        (x_name    ,   6)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify an integer");
   yUNIT_minval   ("convert code"                       , CODE__display    ("3"                                                                , x_display, x_system , x_load   ),    0);
   yUNIT_minval   ("write prefix code"                  , CODE__prefix     (x_file    , "exec"    , "cube a number"       , "cube"           , "i_equal"   , x_display, x_system ),    0);
   CONV_printf_new (x_file, "\n");
   fflush (x_file);
   yUNIT_minval   ("... check count"                    , yURG_peek_count  (x_name)               , 9);
   yUNIT_minstr   ("... header"                         , yURG_peek        (x_name    ,   6)      , "      yUNIT_reset_rc ();"                 );
   yUNIT_minstr   ("... header"                         , yURG_peek        (x_name    ,   7)      , "      if (cyUNIT.exec)  cyUNIT.i_rc = cube (3);");
   yUNIT_minstr   ("... header"                         , yURG_peek        (x_name    ,   8)      , "      yUNIT_int     (   0,   0, \"cube a number\", \"cube\", \"3\", \"i_equal\", ");
   yUNIT_minstr   ("... header"                         , yURG_peek        (x_name    ,   9)      , ""                                         );
   yUNIT_mindnoc  ();

   yURG_err_clear ();
   yUNIT_mincond  ("open code file");
   yUNIT_minval   ("close the script file"              , READ_close  (&x_file)                 , 0);
   sprintf (t, "rm -f %s 2> /dev/null", x_name);
   system (t);
   yUNIT_mindnoc  ();

   yUNIT_minprcs  ();
   return 0;
}

char
koios__unit_code_expect  (char a_list)
{
   char         x_name     [LEN_HUND] = "/tmp/koios.c";
   FILE        *x_file     = NULL;
   char         x_display  [LEN_RECD]  = "";
   char         x_system   [LEN_RECD]  = "";
   char         x_load     [LEN_RECD]  = "";
   char         t          [LEN_HUND]  = "";

   yUNIT_minscrp  ("CODE__expect");
   if (a_list == 'y')  return 0;
   yURG_err_none  ();

   sprintf (t, "rm -f %s 2> /dev/null", x_name);
   system (t);
   yUNIT_mincond ("prepare clean start");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond  ("open code file");
   yUNIT_minval   ("open the code file"                 , READ_open   (x_name, 'w', &x_file, NULL   ),    0);
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify quick success (string)");
   yUNIT_minval   ("write expect code"                  , CODE__expect     (x_file    , "s_equal"   , "expected result"         ),    1);
   CONV_printf_new (x_file, "\n");
   fflush (x_file);
   yUNIT_minval   ("... check count"                    , yURG_peek_count  (x_name)               , 1);
   yUNIT_minstr   ("... header"                         , yURG_peek        (x_name    ,   0)      , "\"expected result\", "                    );
   yUNIT_minstr   ("... header"                         , yURG_peek        (x_name    ,   1)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify void does nothing");
   yUNIT_minval   ("write expect code"                  , CODE__expect     (x_file    , "v_void"    , ""                        ),    0);
   fflush (x_file);
   yUNIT_minval   ("... check count"                    , yURG_peek_count  (x_name)               , 1);
   yUNIT_minstr   ("... header"                         , yURG_peek        (x_name    ,   1)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify pointer");
   yUNIT_minval   ("write expect code"                  , CODE__expect     (x_file    , "p_exists"  , "0x123456"                ),    1);
   CONV_printf_new (x_file, "\n");
   fflush (x_file);
   yUNIT_minval   ("... check count"                    , yURG_peek_count  (x_name)               , 2);
   yUNIT_minstr   ("... header"                         , yURG_peek        (x_name    ,   1)      , "0x123456, "                               );
   yUNIT_minstr   ("... header"                         , yURG_peek        (x_name    ,   2)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify matching variable");
   yUNIT_minval   ("write expect code"                  , CODE__expect     (x_file    , "any"       , "[[ x_var ]]"             ),    2);
   CONV_printf_new (x_file, "\n");
   fflush (x_file);
   yUNIT_minval   ("... check count"                    , yURG_peek_count  (x_name)               , 3);
   yUNIT_minstr   ("... header"                         , yURG_peek        (x_name    ,   2)      , "x_var, "                                  );
   yUNIT_minstr   ("... header"                         , yURG_peek        (x_name    ,   3)      , ""                                         );
   yUNIT_mindnoc  ();

   yURG_err_clear ();
   yUNIT_mincond  ("open code file");
   yUNIT_minval   ("close the script file"              , READ_close  (&x_file)                 , 0);
   sprintf (t, "rm -f %s 2> /dev/null", x_name);
   system (t);
   yUNIT_mindnoc  ();

   yUNIT_minprcs  ();
   return 0;
}

char
koios__unit_code_suffix  (char a_list)
{
   char         x_name     [LEN_HUND] = "/tmp/koios.c";
   FILE        *x_file     = NULL;
   char         x_display  [LEN_RECD]  = "";
   char         x_system   [LEN_RECD]  = "";
   char         x_load     [LEN_RECD]  = "";
   char         t          [LEN_HUND]  = "";

   yUNIT_minscrp  ("CODE__suffix");
   if (a_list == 'y')  return 0;
   yURG_err_none  ();

   sprintf (t, "rm -f %s 2> /dev/null", x_name);
   system (t);
   yUNIT_mincond ("prepare clean start");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond  ("open code file");
   yUNIT_minval   ("open the code file"                 , READ_open   (x_name, 'w', &x_file, NULL   ),    0);
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify quick success (string)");
   yUNIT_minval   ("write suffix code"                  , CODE__suffix     (x_file    , "exec"    , "s_equal"   , ""                        , ""          ),    1);
   fflush (x_file);
   yUNIT_minval   ("... check count"                    , yURG_peek_count  (x_name)               , 1);
   yUNIT_minstr   ("... check line"                     , yURG_peek        (x_name    ,   0)      , "cyUNIT.s_rc, cyUNIT.exec);"               );
   yUNIT_minstr   ("... check line"                     , yURG_peek        (x_name    ,   1)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify string with return");
   yUNIT_minval   ("write suffix code"                  , CODE__suffix     (x_file    , "exec"    , "s_equal"   , ""                        , "x_str"     ),    1);
   fflush (x_file);
   yUNIT_minval   ("... check count"                    , yURG_peek_count  (x_name)               , 3);
   yUNIT_minstr   ("... check line"                     , yURG_peek        (x_name    ,   1)      , "cyUNIT.s_rc, cyUNIT.exec);"               );
   yUNIT_minstr   ("... check line"                     , yURG_peek        (x_name    ,   2)      , "         if (cyUNIT.exec) { if (cyUNIT.s_rc != NULL)  strcpy (x_str, cyUNIT.s_rc); else strcpy (x_str, ""); }");
   yUNIT_minstr   ("... check line"                     , yURG_peek        (x_name    ,   3)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify void does nothing");
   yUNIT_minval   ("write suffix code"                  , CODE__suffix     (x_file    , "exec"    , "v_void"    , ""                        , ""          ),    0);
   fflush (x_file);
   yUNIT_minval   ("... check count"                    , yURG_peek_count  (x_name)               , 3);
   yUNIT_minstr   ("... check line"                     , yURG_peek        (x_name    ,   3)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify integer with return");
   yUNIT_minval   ("write suffix code"                  , CODE__suffix     (x_file    , "exec"    , "i_equal"   , ""                        , "n"         ),    1);
   fflush (x_file);
   yUNIT_minval   ("... check count"                    , yURG_peek_count  (x_name)               , 5);
   yUNIT_minstr   ("... check line"                     , yURG_peek        (x_name    ,   3)      , "cyUNIT.i_rc, cyUNIT.exec);"               );
   yUNIT_minstr   ("... check line"                     , yURG_peek        (x_name    ,   4)      , "         if (cyUNIT.exec)  n = cyUNIT.i_rc;");
   yUNIT_minstr   ("... check line"                     , yURG_peek        (x_name    ,   5)      , ""                                         );
   yUNIT_mindnoc  ();

   yURG_err_clear ();
   yUNIT_mincond  ("open code file");
   yUNIT_minval   ("close the script file"              , READ_close  (&x_file)                 , 0);
   sprintf (t, "rm -f %s 2> /dev/null", x_name);
   system (t);
   yUNIT_mindnoc  ();

   yUNIT_minprcs  ();
   return 0;
}

char
koios__unit_code_exec    (char a_list)
{
   char         x_name     [LEN_HUND] = "/tmp/koios.c";
   FILE        *x_file     = NULL;
   char         x_display  [LEN_RECD]  = "";
   char         x_system   [LEN_RECD]  = "";
   char         x_load     [LEN_RECD]  = "";
   char         t          [LEN_HUND]  = "";
   char         x_cshare   =  '-';

   yUNIT_minscrp  ("CODE_exec");
   if (a_list == 'y')  return 0;
   yURG_err_none  ();

   sprintf (t, "rm -f %s 2> /dev/null", x_name);
   system (t);
   yUNIT_mincond ("prepare clean start");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond  ("open code file");
   yUNIT_minval   ("open the code file"                 , READ_open   (x_name, 'w', &x_file, NULL   ),    0);
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing an EXEC");
   yUNIT_minval   ("write conv line"                    , CONV_exec_new  (x_file    , "exec"    , "call the function"   , "DITTO_parse"    , "x, y, 21"       , "s_equal"   , "pretty expected", "x_str"     , '-', '-', ""  , &x_cshare  ),    0);
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   0)      , "     exec     call the function                    DITTO_parse                 x, y, 21                                                                                              s_equal     pretty expected                                                                                       x_str                ");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   1)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify quick success (string)");
   yUNIT_minval   ("write suffix code"                  , CODE_exec_new    (x_file    , "exec"    , "s_equal"   , ""                        , ""          ),    1);
   fflush (x_file);
   yUNIT_minval   ("... check count"                    , yURG_peek_count  (x_name)               , 1);
   yUNIT_minstr   ("... check line"                     , yURG_peek        (x_name    ,   0)      , "cyUNIT.s_rc, cyUNIT.exec);"               );
   yUNIT_minstr   ("... check line"                     , yURG_peek        (x_name    ,   1)      , ""                                         );
   yUNIT_mindnoc  ();

   yURG_err_clear ();
   yUNIT_mincond  ("open code file");
   yUNIT_minval   ("close the script file"              , READ_close  (&x_file)                 , 0);
   sprintf (t, "rm -f %s 2> /dev/null", x_name);
   system (t);
   yUNIT_mindnoc  ();

   yUNIT_minprcs  ();
   return 0;
}



/*====================------------------------------------====================*/
/*===----                     script reading                           ----===*/
/*====================------------------------------------====================*/
static void      o___SCRP____________________o (void) {;}

char
koios__unit_wave_stage   (char a_list)
{
   char        x_stage     [LEN_SHORT] = "";
   yUNIT_minscrp ("WAVE_parse");
   if (a_list == 'y')  return 0;
   yURG_err_none ();  /* not to stderr/terminal */

   yURG_err_clear ();
   yUNIT_mincond ("verify without stage");
   yUNIT_minval  ("parse"                              , WAVE_parse      ("test.unit", 25, 4, "SCRP", "SCRP"        , x_stage), 0);
   yUNIT_minstr  ("... check stage"                    , x_stage       , "");
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("verify parse good stage 0 (first)");
   yUNIT_minval  ("parse [��]"                         , WAVE_parse      ("test.unit", 25, 4, "SCRP", "SCRP    [��]", x_stage), 0);
   yUNIT_minstr  ("... check stage"                    , x_stage       , "��");
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("attempt with an illegal wave");
   yUNIT_minval  ("parse [a�]"                         , WAVE_parse      ("test.unit", 26, 4, "SCRP", "SCRP    [a�]", x_stage), -999);
   yUNIT_minstr  ("... check stage"                    , x_stage       , "");
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "test.unit:26:9: error: SCRP identifier, wave (a) not a subscript (������), e.g., [��]");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("attempt with an illegal stage");
   yUNIT_minval  ("parse [�A]"                         , WAVE_parse      ("test.unit", 27, 4, "SCRP", "SCRP    [�A]", x_stage), -999);
   yUNIT_minstr  ("... check stage"                    , x_stage       , "");
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "test.unit:27:10: error: SCRP identifier, stage (A) not a greek letter (������������������������), e.g., [��]");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("verify parse good stage 1");
   yUNIT_minval  ("parse [��]"                         , WAVE_parse      ("test.unit", 28, 4, "SCRP", "SCRP    [��]", x_stage), 0);
   yUNIT_minstr  ("... check stage"                    , x_stage       , "��");
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("attempt with mismatched stage");
   yUNIT_minval  ("parse [��]"                         , WAVE_parse      ("test.unit", 29, 4, "SCRP", "SCRP    [��]", x_stage), -999);
   yUNIT_minstr  ("... check stage"                    , x_stage       , "");
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "test.unit:29:9: error: SCRP identifier, wave (�) and stage (�) mismatched, e.g., [��]");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("verify parse good stage 2");
   yUNIT_minval  ("parse [��]"                         , WAVE_parse      ("test.unit", 30, 4, "SCRP", "SCRP    [��]", x_stage), 0);
   yUNIT_minstr  ("... check stage"                    , x_stage       , "��");
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("attempt with wrong start");        
   yUNIT_minval  ("parse (��]"                         , WAVE_parse      ("test.unit", 22, 4, "SCRP", "SCRP    (��]", x_stage), -999);
   yUNIT_minstr  ("... check stage"                    , x_stage       , "");
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "test.unit:22:0: error: SCRP identifier, illegal char '(' after verb, maybe stage, e.g., [��]");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("attempt with wrong parens");        
   yUNIT_minval  ("parse [��)"                         , WAVE_parse      ("test.unit", 31, 4, "SCRP", "SCRP    [��)", x_stage), -999);
   yUNIT_minstr  ("... check stage"                    , x_stage       , "");
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "test.unit:31:11: error: SCRP identifier, stage uses wrong end bracket ')' vs ']', e.g., [��]");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("verify parse good stage 3");
   yUNIT_minval  ("parse [��]"                         , WAVE_parse      ("test.unit", 32, 4, "SCRP", "SCRP    [��]", x_stage), 0);
   yUNIT_minstr  ("... check stage"                    , x_stage       , "��");
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("attempt with no close paren");      
   yUNIT_minval  ("parse [��"                          , WAVE_parse      ("test.unit", 33, 4, "SCRP", "SCRP    [��", x_stage ), -999);
   yUNIT_minstr  ("... check stage"                    , x_stage       , "");
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "test.unit:33:8: error: SCRP identifier, stage �[��� must be exactly 4 characters, e.g., [��]");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("verify parse good stage 4");
   yUNIT_minval  ("parse [��]"                         , WAVE_parse      ("test.unit", 34, 4, "SCRP", "SCRP    [��]", x_stage), 0);
   yUNIT_minstr  ("... check stage"                    , x_stage       , "��");
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("attempt on an empty");                
   yUNIT_minval  ("parse "                             , WAVE_parse      ("test.unit", 35, 4, "SCRP", ""            , x_stage), -999);
   yUNIT_minstr  ("... check stage"                    , x_stage       , "");
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("verify parse good stage 5 (last)");
   yUNIT_minval  ("parse [��]"                         , WAVE_parse      ("test.unit", 36, 4, "SCRP", "SCRP    [��]", x_stage), 0);
   yUNIT_minstr  ("... check stage"                    , x_stage       , "��");
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("attempt on a null");                
   yUNIT_minval  ("parse "                             , WAVE_parse      ("test.unit", 37, 4, "SCRP", NULL          , x_stage), -999);
   yUNIT_minstr  ("... check stage"                    , x_stage       , "");
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc ();

   yUNIT_minprcs ();
   return 0;
}

char
koios__unit_scrp_comment (void)
{
   char        x_verb      [LEN_LABEL] = "";
   char        x_indx      = -1;
   char        x_spec      = '-';
   void       *x_conv      = NULL;
   void       *x_code      = NULL;

   yUNIT_minscrp ("koios_scrp identifying comments");
   yURG_err_none ();  /* not to stderr/terminal */

   yUNIT_mincond ("parse good comments");
   yUNIT_minval   ("parse a normal comment"              , SCRP__parse_comment ("#> a comment"                      , x_verb, &x_indx, &x_spec, &x_conv, &x_code), 1);
   yUNIT_minstr   ("... check verb"                      , x_verb        , "#>");
   yUNIT_minval   ("... check index"                     , x_indx        , 999);
   yUNIT_minchr   ("... check spec"                      , x_spec        , 'c');
   yUNIT_minpoint ("... check conv pointer"              , x_conv        , CONV_comment);
   yUNIT_minpoint ("... check code pointer"              , x_code        , NULL);
   yUNIT_minstr   ("... check error message"             , yURG_err_last (), "");
   yUNIT_minval   ("parse with a space"                  , SCRP__parse_comment ("#>comment"                         , x_verb, &x_indx, &x_spec, &x_conv, &x_code), 1);
   yUNIT_minstr   ("... check verb"                      , x_verb        , "#>");
   yUNIT_minval   ("... check index"                     , x_indx        , 999);
   yUNIT_minchr   ("... check spec"                      , x_spec        , 'c');
   yUNIT_minpoint ("... check conv pointer"              , x_conv        , CONV_comment);
   yUNIT_minpoint ("... check code pointer"              , x_code        , NULL);
   yUNIT_minstr   ("... check error message"             , yURG_err_last (), "");
   yUNIT_minval   ("parse without actual comment"        , SCRP__parse_comment ("#>"                                , x_verb, &x_indx, &x_spec, &x_conv, &x_code), 1);
   yUNIT_minstr   ("... check verb"                      , x_verb        , "#>");
   yUNIT_minval   ("... check index"                     , x_indx        , 999);
   yUNIT_minchr   ("... check spec"                      , x_spec        , 'c');
   yUNIT_minpoint ("... check conv pointer"              , x_conv        , CONV_comment);
   yUNIT_minpoint ("... check code pointer"              , x_code        , NULL);
   yUNIT_minstr   ("... check error message"             , yURG_err_last (), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("parse not comments");
   yUNIT_minval   ("parse with wrong prefix"             , SCRP__parse_comment ("## a comment"                      , x_verb, &x_indx, &x_spec, &x_conv, &x_code), 0);
   yUNIT_minstr   ("... check verb"                      , x_verb        , "");
   yUNIT_minval   ("... check index"                     , x_indx        , -999);
   yUNIT_minchr   ("... check spec"                      , x_spec        , '-');
   yUNIT_minpoint ("... check conv pointer"              , x_conv        , NULL);
   yUNIT_minpoint ("... check code pointer"              , x_code        , NULL);
   yUNIT_minstr   ("... check error message"             , yURG_err_last (), "");
   yUNIT_minval   ("parse with wrong prefix"             , SCRP__parse_comment ("#comment"                          , x_verb, &x_indx, &x_spec, &x_conv, &x_code), 0);
   yUNIT_minstr   ("... check verb"                      , x_verb        , "");
   yUNIT_minval   ("... check index"                     , x_indx        , -999);
   yUNIT_minchr   ("... check spec"                      , x_spec        , '-');
   yUNIT_minpoint ("... check conv pointer"              , x_conv        , NULL);
   yUNIT_minpoint ("... check code pointer"              , x_code        , NULL);
   yUNIT_minstr   ("... check error message"             , yURG_err_last (), "");
   yUNIT_minval   ("parse with other verb"               , SCRP__parse_comment ("exec"                              , x_verb, &x_indx, &x_spec, &x_conv, &x_code), 0);
   yUNIT_minstr   ("... check verb"                      , x_verb        , "");
   yUNIT_minval   ("... check index"                     , x_indx        , -999);
   yUNIT_minchr   ("... check spec"                      , x_spec        , '-');
   yUNIT_minpoint ("... check conv pointer"              , x_conv        , NULL);
   yUNIT_minpoint ("... check code pointer"              , x_code        , NULL);
   yUNIT_minstr   ("... check error message"             , yURG_err_last (), "");
   yUNIT_minval   ("parse with c-style comment"          , SCRP__parse_comment ("/* programming comment */"         , x_verb, &x_indx, &x_spec, &x_conv, &x_code), 0);
   yUNIT_minstr   ("... check verb"                      , x_verb        , "");
   yUNIT_minval   ("... check index"                     , x_indx        , -999);
   yUNIT_minchr   ("... check spec"                      , x_spec        , '-');
   yUNIT_minpoint ("... check conv pointer"              , x_conv        , NULL);
   yUNIT_minpoint ("... check code pointer"              , x_code        , NULL);
   yUNIT_minstr   ("... check error message"             , yURG_err_last (), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("parse illegal lines");
   yUNIT_minval   ("parse with empty"                    , SCRP__parse_comment (""                                  , x_verb, &x_indx, &x_spec, &x_conv, &x_code), 0);
   yUNIT_minstr   ("... check verb"                      , x_verb        , "");
   yUNIT_minval   ("... check index"                     , x_indx        , -999);
   yUNIT_minchr   ("... check spec"                      , x_spec        , '-');
   yUNIT_minpoint ("... check conv pointer"              , x_conv        , NULL);
   yUNIT_minpoint ("... check code pointer"              , x_code        , NULL);
   yUNIT_minstr   ("... check error message"             , yURG_err_last (), "");
   yUNIT_minval   ("parse with null"                     , SCRP__parse_comment (NULL                                , x_verb, &x_indx, &x_spec, &x_conv, &x_code), -999);
   yUNIT_minstr   ("... check verb"                      , x_verb        , "");
   yUNIT_minval   ("... check index"                     , x_indx        , -999);
   yUNIT_minchr   ("... check spec"                      , x_spec        , '-');
   yUNIT_minpoint ("... check conv pointer"              , x_conv        , NULL);
   yUNIT_minpoint ("... check code pointer"              , x_code        , NULL);
   yUNIT_minstr   ("... check error message"             , yURG_err_last (), "");
   yUNIT_mindnoc ();

   yUNIT_minprcs ();
   return 0;
}

char
koios__unit_scrp_limits  (void)
{
   char        x_min       =    0;
   char        x_max       =    0;

   PROG__unit_quiet  ();
   yUNIT_minscrp ("koios_scrp parsing records");
   yURG_err_none ();  /* not to stderr/terminal */

   yUNIT_mincond  ("verify quick success");
   yUNIT_minval   ("get limits for SCRP"                , SCRP__limits ('s', &x_min, &x_max), 0);
   yUNIT_minval   ("... check min"                      , x_min         , 3);
   yUNIT_minval   ("... check max"                      , x_max         , 5);
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("attempt with missing min");
   yUNIT_minval   ("get limits with a null"             , SCRP__limits ('s', NULL  , &x_max), -999);
   yUNIT_minval   ("... check max"                      , x_max         , 0);
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("attempt with missing max");
   yUNIT_minval   ("get limits with a null"             , SCRP__limits ('s', &x_min, NULL  ), -999);
   yUNIT_minval   ("... check min"                      , x_min         , 0);
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify quick success");
   yUNIT_minval   ("get limits for COND"                , SCRP__limits ('2', &x_min, &x_max), 0);
   yUNIT_minval   ("... check min"                      , x_min         , 2);
   yUNIT_minval   ("... check max"                      , x_max         , 2);
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("attempt with an illegal spec");
   yUNIT_minval   ("get limits for '*'"                 , SCRP__limits ('*', &x_min, &x_max), -999);
   yUNIT_minval   ("... check min"                      , x_min         , 0);
   yUNIT_minval   ("... check max"                      , x_max         , 0);
   yUNIT_mindnoc  ();

   yUNIT_minprcs ();
   PROG__unit_end  ();
   return 0;
}

char
koios__unit_scrp__current      (void)
{
   char        x_scrp      [LEN_TITLE] = "/tmp/koios.unit";
   int         x_line      =  13;
   char        x_recd      [LEN_RECD]  = "";
   char        x_desc      [LEN_LONG]  = "";
   char        x_meth      [LEN_HUND]  = "";
   char        x_args      [LEN_FULL]  = "";
   char        x_test      [LEN_LABEL] = "";
   char        x_expe      [LEN_RECD]  = "";
   char        x_retn      [LEN_FULL]  = "";
   char        x_code      [LEN_RECD]  = "";
   char       *p           = NULL;

   PROG__unit_quiet  ();
   yUNIT_minscrp ("koios_scrp parsing current version records");
   yURG_err_none ();  /* not to stderr/terminal */

   yURG_err_clear ();
   strcpy (x_recd, "SCRP          (DB) verify writing and reading database in parts                  0s   parts           DB_readite, DICT_read                                                        ((02.---))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   p = strtok (x_recd, "");
   p = strtok (NULL  , "");
   yUNIT_mincond  ("verify SCRP success");
   yUNIT_minval   ("call current"                       , SCRP__current (x_scrp, x_line, "SCRP"   , 's', p, x_desc, x_meth, x_args, x_test, x_expe, x_retn, x_code), 0);
   yUNIT_minstr   ("... check desc"                     , x_desc        , "(DB) verify writing and reading database in parts");
   yUNIT_minstr   ("... check meth"                     , x_meth        , "DB_readite, DICT_read");
   yUNIT_minstr   ("... check args"                     , x_args        , "");
   yUNIT_minstr   ("... check test"                     , x_test        , "0s");
   yUNIT_minstr   ("... check expe"                     , x_expe        , "");
   yUNIT_minstr   ("... check retn"                     , x_retn        , "parts");
   yUNIT_minstr   ("... check code"                     , x_code        , "");
   yUNIT_minstr   ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   strcpy (x_recd, "COND       initialize the testing environment                                 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((02.001))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   p = strtok (x_recd, "");
   p = strtok (NULL  , "");
   yUNIT_mincond  ("attempt with a bad spec");
   yUNIT_minval   ("call current"                       , SCRP__current (x_scrp, x_line, "COND"   , '�', p, x_desc, x_meth, x_args, x_test, x_expe, x_retn, x_code), -999);
   yUNIT_minstr   ("... check desc"                     , x_desc        , "");
   yUNIT_minstr   ("... check meth"                     , x_meth        , "");
   yUNIT_minstr   ("... check args"                     , x_args        , "");
   yUNIT_minstr   ("... check test"                     , x_test        , "");
   yUNIT_minstr   ("... check expe"                     , x_expe        , "");
   yUNIT_minstr   ("... check retn"                     , x_retn        , "");
   yUNIT_minstr   ("... check code"                     , x_code        , "");
   yUNIT_minstr   ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:13:0: error: can not identify verb �COND� with '�' spec limits");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   strcpy (x_recd, "COND       initialize the testing environment                                 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((02.001))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   p = strtok (x_recd, "");
   p = strtok (NULL  , "");
   yUNIT_mincond  ("verify COND success");
   yUNIT_minval   ("call current"                       , SCRP__current (x_scrp, x_line, "COND"   , 'c', p, x_desc, x_meth, x_args, x_test, x_expe, x_retn, x_code), 0);
   yUNIT_minstr   ("... check desc"                     , x_desc        , "initialize the testing environment");
   yUNIT_minstr   ("... check meth"                     , x_meth        , "");
   yUNIT_minstr   ("... check args"                     , x_args        , "");
   yUNIT_minstr   ("... check test"                     , x_test        , "");
   yUNIT_minstr   ("... check expe"                     , x_expe        , "");
   yUNIT_minstr   ("... check retn"                     , x_retn        , "");
   yUNIT_minstr   ("... check code"                     , x_code        , "");
   yUNIT_minstr   ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   strcpy (x_recd, "  local    create working variable              - - - - - - - - - - - - -   char      x_prog   [LEN_LABEL] = "";                                                                                                                                                                            ");
   p = strtok (x_recd, "");
   p = strtok (NULL  , "");
   yUNIT_mincond  ("verify LOCAL success");
   yUNIT_minval   ("call current"                       , SCRP__current (x_scrp, x_line, "local"  , 'p', p, x_desc, x_meth, x_args, x_test, x_expe, x_retn, x_code), 0);
   yUNIT_minstr   ("... check desc"                     , x_desc        , "create working variable");
   yUNIT_minstr   ("... check meth"                     , x_meth        , "");
   yUNIT_minstr   ("... check args"                     , x_args        , "");
   yUNIT_minstr   ("... check test"                     , x_test        , "");
   yUNIT_minstr   ("... check expe"                     , x_expe        , "");
   yUNIT_minstr   ("... check retn"                     , x_retn        , "");
   yUNIT_minstr   ("... check code"                     , x_code        , "char      x_prog   [LEN_LABEL] = "";");
   yUNIT_minstr   ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   strcpy (x_recd, "  exec     call open                            SHARED_open                 x_name         , 'W'            , &x_db                                                              ");
   p = strtok (x_recd, "");
   p = strtok (NULL  , "");
   yUNIT_mincond  ("attempt with not enough fields");
   yUNIT_minval   ("call current"                       , SCRP__current (x_scrp, x_line, "exec"   , 'f', p, x_desc, x_meth, x_args, x_test, x_expe, x_retn, x_code), -999);
   yUNIT_minstr   ("... check desc"                     , x_desc        , "");
   yUNIT_minstr   ("... check meth"                     , x_meth        , "");
   yUNIT_minstr   ("... check args"                     , x_args        , "");
   yUNIT_minstr   ("... check test"                     , x_test        , "");
   yUNIT_minstr   ("... check expe"                     , x_expe        , "");
   yUNIT_minstr   ("... check retn"                     , x_retn        , "");
   yUNIT_minstr   ("... check code"                     , x_code        , "");
   yUNIT_minstr   ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:13:0: error: verb �exec� included 4 fields, requires at least 6");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   strcpy (x_recd, "  exec     call open                            SHARED_open                 x_name         , 'W'            , &x_db                                                               i_equal     0                                                                                                    ");
   p = strtok (x_recd, "");
   p = strtok (NULL  , "");
   yUNIT_mincond  ("verify EXEC success");
   yUNIT_minval   ("call current"                       , SCRP__current (x_scrp, x_line, "exec"   , 'f', p, x_desc, x_meth, x_args, x_test, x_expe, x_retn, x_code), 0);
   yUNIT_minstr   ("... check desc"                     , x_desc        , "call open");
   yUNIT_minstr   ("... check meth"                     , x_meth        , "SHARED_open");
   yUNIT_minstr   ("... check args"                     , x_args        , "x_name         , 'W'            , &x_db");
   yUNIT_minstr   ("... check test"                     , x_test        , "i_equal");
   yUNIT_minstr   ("... check expe"                     , x_expe        , "0");
   yUNIT_minstr   ("... check retn"                     , x_retn        , "");
   yUNIT_minstr   ("... check code"                     , x_code        , "x_name         , 'W'            , &x_db");
   yUNIT_minstr   ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc ();

   yUNIT_minprcs ();
   PROG__unit_end  ();
   return 0;
}

/*> char                                                                                                                                                                                <* 
 *> koios__unit_scrp_save    (void)                                                                                                                                                     <* 
 *> {                                                                                                                                                                                   <* 
 *>    PROG__unit_quiet  ();                                                                                                                                                            <* 
 *>    yUNIT_minscrp ("koios_scrp saving details");                                                                                                                                     <* 
 *>    yURG_err_none ();  /+ not to stderr/terminal +/                                                                                                                                  <* 
 *>                                                                                                                                                                                     <* 
 *>    yUNIT_mincond  ("verify quick success");                                                                                                                                         <* 
 *>    yUNIT_minval   ("call save"                          , SCRP__save    ("description", "method", "arguments", "test", "expected results", "return var", "programming code"), 0);   <* 
 *>    yUNIT_minstr   ("... check desc"                     , my.desc       , "description");                                                                                           <* 
 *>    yUNIT_minstr   ("... check meth"                     , my.meth       , "method");                                                                                                <* 
 *>    yUNIT_minstr   ("... check args"                     , my.args       , "arguments");                                                                                             <* 
 *>    yUNIT_minstr   ("... check test"                     , my.test       , "test");                                                                                                  <* 
 *>    yUNIT_minstr   ("... check expe"                     , my.expe       , "expected results");                                                                                      <* 
 *>    yUNIT_minstr   ("... check retn"                     , my.retn       , "return var");                                                                                            <* 
 *>    yUNIT_minstr   ("... check code"                     , my.code       , "programming code");                                                                                      <* 
 *>    yUNIT_mindnoc  ();                                                                                                                                                               <* 
 *>                                                                                                                                                                                     <* 
 *>    yUNIT_mincond  ("verify clearing data");                                                                                                                                         <* 
 *>    yUNIT_minval   ("call clear"                         , SCRP_clear    (), 0);                                                                                                     <* 
 *>    yUNIT_minstr   ("... check desc"                     , my.desc       , "");                                                                                                      <* 
 *>    yUNIT_minstr   ("... check meth"                     , my.meth       , "");                                                                                                      <* 
 *>    yUNIT_minstr   ("... check args"                     , my.args       , "");                                                                                                      <* 
 *>    yUNIT_minstr   ("... check test"                     , my.test       , "");                                                                                                      <* 
 *>    yUNIT_minstr   ("... check expe"                     , my.expe       , "");                                                                                                      <* 
 *>    yUNIT_minstr   ("... check retn"                     , my.retn       , "");                                                                                                      <* 
 *>    yUNIT_minstr   ("... check code"                     , my.code       , "");                                                                                                      <* 
 *>    yUNIT_mindnoc  ();                                                                                                                                                               <* 
 *>                                                                                                                                                                                     <* 
 *>    yUNIT_mincond  ("verify partial save");                                                                                                                                          <* 
 *>    yUNIT_minval   ("call save"                          , SCRP__save    ("description", NULL    , "arguments", NULL  , "expected results", NULL        , "programming code"), 0);   <* 
 *>    yUNIT_minstr   ("... check desc"                     , my.desc       , "description");                                                                                           <* 
 *>    yUNIT_minstr   ("... check meth"                     , my.meth       , "");                                                                                                      <* 
 *>    yUNIT_minstr   ("... check args"                     , my.args       , "arguments");                                                                                             <* 
 *>    yUNIT_minstr   ("... check test"                     , my.test       , "");                                                                                                      <* 
 *>    yUNIT_minstr   ("... check expe"                     , my.expe       , "expected results");                                                                                      <* 
 *>    yUNIT_minstr   ("... check retn"                     , my.retn       , "");                                                                                                      <* 
 *>    yUNIT_minstr   ("... check code"                     , my.code       , "programming code");                                                                                      <* 
 *>    yUNIT_mindnoc  ();                                                                                                                                                               <* 
 *>                                                                                                                                                                                     <* 
 *>    yUNIT_mincond  ("verify clearing data");                                                                                                                                         <* 
 *>    yUNIT_minval   ("call clear"                         , SCRP_clear    (), 0);                                                                                                     <* 
 *>    yUNIT_minstr   ("... check desc"                     , my.desc       , "");                                                                                                      <* 
 *>    yUNIT_minstr   ("... check meth"                     , my.meth       , "");                                                                                                      <* 
 *>    yUNIT_minstr   ("... check args"                     , my.args       , "");                                                                                                      <* 
 *>    yUNIT_minstr   ("... check test"                     , my.test       , "");                                                                                                      <* 
 *>    yUNIT_minstr   ("... check expe"                     , my.expe       , "");                                                                                                      <* 
 *>    yUNIT_minstr   ("... check retn"                     , my.retn       , "");                                                                                                      <* 
 *>    yUNIT_minstr   ("... check code"                     , my.code       , "");                                                                                                      <* 
 *>    yUNIT_mindnoc  ();                                                                                                                                                               <* 
 *>                                                                                                                                                                                     <* 
 *>    yUNIT_mincond  ("verify other partials");                                                                                                                                        <* 
 *>    yUNIT_minval   ("call save"                          , SCRP__save    (NULL         , "method", NULL       , "test", NULL              , "return var", NULL              ), 0);   <* 
 *>    yUNIT_minstr   ("... check desc"                     , my.desc       , "");                                                                                                      <* 
 *>    yUNIT_minstr   ("... check meth"                     , my.meth       , "method");                                                                                                <* 
 *>    yUNIT_minstr   ("... check args"                     , my.args       , "");                                                                                                      <* 
 *>    yUNIT_minstr   ("... check test"                     , my.test       , "test");                                                                                                  <* 
 *>    yUNIT_minstr   ("... check expe"                     , my.expe       , "");                                                                                                      <* 
 *>    yUNIT_minstr   ("... check retn"                     , my.retn       , "return var");                                                                                            <* 
 *>    yUNIT_minstr   ("... check code"                     , my.code       , "");                                                                                                      <* 
 *>    yUNIT_mindnoc  ();                                                                                                                                                               <* 
 *>                                                                                                                                                                                     <* 
 *>    yUNIT_mincond  ("verify updating values, leaving old ones");                                                                                                                     <* 
 *>    yUNIT_minval   ("call save"                          , SCRP__save    ("NEW"        , NULL    , NULL       , NULL  , NULL              , "UPDATE"    , NULL              ), 0);   <* 
 *>    yUNIT_minstr   ("... check desc"                     , my.desc       , "NEW");                                                                                                   <* 
 *>    yUNIT_minstr   ("... check meth"                     , my.meth       , "method");                                                                                                <* 
 *>    yUNIT_minstr   ("... check args"                     , my.args       , "");                                                                                                      <* 
 *>    yUNIT_minstr   ("... check test"                     , my.test       , "test");                                                                                                  <* 
 *>    yUNIT_minstr   ("... check expe"                     , my.expe       , "");                                                                                                      <* 
 *>    yUNIT_minstr   ("... check retn"                     , my.retn       , "UPDATE");                                                                                                <* 
 *>    yUNIT_minstr   ("... check code"                     , my.code       , "");                                                                                                      <* 
*>    yUNIT_mindnoc  ();                                                                                                                                                               <* 
*>                                                                                                                                                                                     <* 
*>    yUNIT_minprcs ();                                                                                                                                                                <* 
*>    PROG__unit_end  ();                                                                                                                                                              <* 
*>    return 0;                                                                                                                                                                        <* 
*> }                                                                                                                                                                                   <*/

char
koios__unit_scrp_parse   (void)
{
   char        x_scrp      [LEN_TITLE] = "/tmp/koios.unit";
   int         x_line      =   0;
   char        x_recd      [LEN_RECD]  = "";
   char        x_verb      [LEN_LABEL] = "";
   char        x_indx      = -1;
   char        x_spec      = '-';
   void       *x_conv      = NULL;
   void       *x_code      = NULL;
   char        x_stage     [LEN_TERSE] = "";
   char        x_vers      [LEN_TERSE] = "";

   PROG__unit_quiet ();
   yUNIT_minscrp ("koios_scrp parsing records");
   yURG_err_none ();  /* not to stderr/terminal */

   yURG_err_clear ();
   strcpy (x_recd, "exec     read a line      SCRP_read       i_lesser    0      ");
   yUNIT_mincond  ("verify reading a simple record");
   yUNIT_minval   ("parse a line"                       , SCRP_parse  (x_scrp, x_line, x_recd, x_verb, &x_indx, &x_spec, &x_conv, &x_code, x_stage, x_vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);
   yUNIT_minstr   ("... check verb"                     , x_verb        , "exec");
   yUNIT_minval   ("... check index"                    , x_indx        , -999);
   yUNIT_minchr   ("... check spec"                     , x_spec        , '-');
   yUNIT_minpoint ("... check conv pointer"             , x_conv        , NULL);
   yUNIT_minpoint ("... check code pointer"             , x_code        , NULL);
   yUNIT_minstr   ("... check stage"                    , x_stage       , "");
   yUNIT_minstr   ("... check version"                  , x_vers        , "");
   yUNIT_minstr   ("... check error message"            , yURG_err_last (), "");
   yUNIT_minchr   ("... check share"                    , my.share      , '-');
   yUNIT_minchr   ("... check mark"                     , my.mark       , '-');
   yUNIT_minstr   ("... check description"              , my.desc       , "read a line");
   yUNIT_minstr   ("... check method"                   , my.meth       , "SCRP_read");
   yUNIT_minstr   ("... check arguments"                , my.args       , "");
   yUNIT_minstr   ("... check test"                     , my.test       , "i_lesser");
   yUNIT_minstr   ("... check expect"                   , my.expe       , "0");
   yUNIT_mindnoc  ();

   /*> yUNIT_mincond ("attempt to parse an empty recd");                                                                                                                   <* 
    *> strcpy (x_recd, "");                                                                                                                                                <* 
    *> yUNIT_minval   ("parse a line"                       , SCRP_parse  (x_scrp, x_line, x_recd, x_verb, &x_indx, &x_spec, &x_conv, &x_code, x_stage, x_vers ), -999);   <* 
    *> yUNIT_minstr   ("... check the record"               , x_recd        , "");                                                                                         <* 
    *> yUNIT_minstr   ("... check verb"                     , x_verb        , "");                                                                                         <* 
    *> yUNIT_minstr   ("... check stage"                    , x_stage       , "");                                                                                         <* 
    *> yUNIT_minstr   ("... check version"                  , x_vers        , "");                                                                                         <* 
    *> yUNIT_minval   ("close the script file"              , SCRP_close  (&(x_file)), 0);                                                                                 <* 
    *> yUNIT_minval   ("... check script pointer"           , x_file     , 0);                                                                                             <* 
    *> yUNIT_mindnoc  ();                                                                                                                                                  <*/

   /*> yUNIT_mincond ("attempt empty");                                                                                                                                 <* 
    *> strcpy (x_scrp, "/tmp/koios.unit");                                                                                                                              <* 
    *> system ("echo \"\"                                             > /tmp/koios.unit");                                                                              <* 
    *> yUNIT_minstr ("... check script name"              , x_scrp     , "/tmp/koios.unit");                                                                            <* 
    *> yUNIT_minval ("open the script file"               , SCRP_open   (x_scrp, &(x_file), &(x_line)), 0);                                                             <* 
    *> yUNIT_minval ("... check script pointer"           , x_file     , x_file);                                                                                       <* 
    *> yUNIT_minval ("read a line"                        , SCRP_read   (x_file, &(x_line), my.dittoing, my.ditto, &(my.dline), &(my.n_recd), &(my.len), x_recd), 0);   <* 
    *> yUNIT_minval ("parse a line"                       , SCRP_parse  (), -999);                                                                                      <* 
    *> strlencode (x_recd, ySTR_NONE, LEN_RECD);                                                                                                                        <* 
    *> yUNIT_minstr ("... check the record"               , x_recd       , "");                                                                                         <* 
    *> yUNIT_minstr ("... check verb"                     , x_verb        , "");                                                                                        <* 
    *> yUNIT_minstr ("... check stage"                    , x_stage       , "");                                                                                        <* 
    *> yUNIT_minchr ("... check share"                    , my.share      , '-');                                                                                       <* 
    *> yUNIT_minchr ("... check mark"                     , my.mark       , '-');                                                                                       <* 
    *> yUNIT_minstr ("... check version"                  , x_vers        , "");                                                                                        <* 
    *> yUNIT_minstr ("... check description"              , my.desc       , "");                                                                                        <* 
    *> yUNIT_minstr ("... check method"                   , my.meth       , "");                                                                                        <* 
    *> yUNIT_minstr ("... check arguments"                , my.args       , "");                                                                                        <* 
    *> yUNIT_minstr ("... check test"                     , my.test       , "");                                                                                        <* 
    *> yUNIT_minstr ("... check expect"                   , my.expe       , "");                                                                                        <* 
    *> yUNIT_minval ("close the script file"              , SCRP_close  (&(x_file)), 0);                                                                                <* 
    *> yUNIT_minval ("... check script pointer"           , x_file     , 0);                                                                                            <* 
    *> yUNIT_mindnoc ();                                                                                                                                                <*/

   /*> yUNIT_mincond ("attempt verb only");                                                                                                                             <* 
    *> strcpy (x_scrp, "/tmp/koios.unit");                                                                                                                              <* 
    *> system ("echo \"exec    \"                                             > /tmp/koios.unit");                                                                     <* 
    *> yUNIT_minstr ("... check script name"              , x_scrp     , "/tmp/koios.unit");                                                                            <* 
    *> yUNIT_minval ("open the script file"               , SCRP_open   (x_scrp, &(x_file), &(x_line)), 0);                                                             <* 
    *> yUNIT_minval ("... check script pointer"           , x_file     , x_file);                                                                                       <* 
    *> yUNIT_minval ("read a line"                        , SCRP_read   (x_file, &(x_line), my.dittoing, my.ditto, &(my.dline), &(my.n_recd), &(my.len), x_recd), 1);   <* 
    *> yUNIT_minval ("parse a line"                       , SCRP_parse  (), -999);                                                                                      <* 
    *> yUNIT_minstr ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: verb only, exec requires more fields");                      <* 
    *> strlencode (x_recd, ySTR_NONE, LEN_RECD);                                                                                                                        <* 
    *> yUNIT_minstr ("... check the record"               , x_recd       , "exec    �");                                                                                <* 
    *> yUNIT_minstr ("... check verb"                     , x_verb        , "exec");                                                                                    <* 
    *> yUNIT_minstr ("... check stage"                    , x_stage       , "");                                                                                        <* 
    *> yUNIT_minchr ("... check share"                    , my.share      , '-');                                                                                       <* 
    *> yUNIT_minchr ("... check mark"                     , my.mark       , '-');                                                                                       <* 
    *> yUNIT_minstr ("... check version"                  , x_vers        , "");                                                                                        <* 
    *> yUNIT_minstr ("... check description"              , my.desc       , "");                                                                                        <* 
    *> yUNIT_minstr ("... check method"                   , my.meth       , "");                                                                                        <* 
    *> yUNIT_minstr ("... check arguments"                , my.args       , "");                                                                                        <* 
    *> yUNIT_minstr ("... check test"                     , my.test       , "");                                                                                        <* 
    *> yUNIT_minstr ("... check expect"                   , my.expe       , "");                                                                                        <* 
    *> yUNIT_minval ("close the script file"              , SCRP_close  (&(x_file)), 0);                                                                                <* 
    *> yUNIT_minval ("... check script pointer"           , x_file     , 0);                                                                                            <* 
    *> yUNIT_mindnoc ();                                                                                                                                                <*/

   /*> yUNIT_mincond ("attempt verb and desc");                                                                                                                         <* 
    *> strcpy (x_scrp, "/tmp/koios.unit");                                                                                                                              <* 
    *> system ("echo \"exec     read a line     \"                                             > /tmp/koios.unit");                                                   <* 
    *> yUNIT_minstr ("... check script name"              , x_scrp     , "/tmp/koios.unit");                                                                            <* 
    *> yUNIT_minval ("open the script file"               , SCRP_open   (x_scrp, &(x_file), &(x_line)), 0);                                                             <* 
    *> yUNIT_minval ("... check script pointer"           , x_file     , x_file);                                                                                       <* 
    *> yUNIT_minval ("read a line"                        , SCRP_read   (x_file, &(x_line), my.dittoing, my.ditto, &(my.dline), &(my.n_recd), &(my.len), x_recd), 1);   <* 
    *> yUNIT_minval ("parse a line"                       , SCRP_parse  (), -999);                                                                                      <* 
    *> yUNIT_minstr ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: too few fields (2) for exec, requires 6");                   <* 
    *> strlencode (x_recd, ySTR_NONE, LEN_RECD);                                                                                                                        <* 
    *> yUNIT_minstr ("... check the record"               , x_recd       , "exec    � read a line     �");                                                              <* 
    *> yUNIT_minstr ("... check verb"                     , x_verb        , "exec");                                                                                    <* 
    *> yUNIT_minstr ("... check stage"                    , x_stage       , "");                                                                                        <* 
    *> yUNIT_minchr ("... check share"                    , my.share      , '-');                                                                                       <* 
    *> yUNIT_minchr ("... check mark"                     , my.mark       , '-');                                                                                       <* 
    *> yUNIT_minstr ("... check version"                  , x_vers        , "");                                                                                        <* 
    *> yUNIT_minstr ("... check description"              , my.desc       , "read a line");                                                                             <* 
    *> yUNIT_minstr ("... check method"                   , my.meth       , "");                                                                                        <* 
    *> yUNIT_minstr ("... check arguments"                , my.args       , "");                                                                                        <* 
    *> yUNIT_minstr ("... check test"                     , my.test       , "");                                                                                        <* 
    *> yUNIT_minstr ("... check expect"                   , my.expe       , "");                                                                                        <* 
    *> yUNIT_minval ("close the script file"              , SCRP_close  (&(x_file)), 0);                                                                                <* 
    *> yUNIT_minval ("... check script pointer"           , x_file     , 0);                                                                                            <* 
    *> yUNIT_mindnoc ();                                                                                                                                                <*/

   /*> yUNIT_mincond ("attempt verb, desc, and method");                                                                                                                <* 
    *> strcpy (x_scrp, "/tmp/koios.unit");                                                                                                                              <* 
    *> system ("echo \"exec     read a line      SCRP_read   \"                                             > /tmp/koios.unit");                                     <* 
    *> yUNIT_minstr ("... check script name"              , x_scrp     , "/tmp/koios.unit");                                                                            <* 
    *> yUNIT_minval ("open the script file"               , SCRP_open   (x_scrp, &(x_file), &(x_line)), 0);                                                             <* 
    *> yUNIT_minval ("... check script pointer"           , x_file     , x_file);                                                                                       <* 
    *> yUNIT_minval ("read a line"                        , SCRP_read   (x_file, &(x_line), my.dittoing, my.ditto, &(my.dline), &(my.n_recd), &(my.len), x_recd), 1);   <* 
    *> yUNIT_minval ("parse a line"                       , SCRP_parse  (), -999);                                                                                      <* 
    *> yUNIT_minstr ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: too few fields (3) for exec, requires 6");                   <* 
    *> strlencode (x_recd, ySTR_NONE, LEN_RECD);                                                                                                                        <* 
    *> yUNIT_minstr ("... check the record"               , x_recd       , "exec    � read a line     � SCRP_read   �");                                                <* 
    *> yUNIT_minstr ("... check verb"                     , x_verb        , "exec");                                                                                    <* 
    *> yUNIT_minstr ("... check stage"                    , x_stage       , "");                                                                                        <* 
    *> yUNIT_minchr ("... check share"                    , my.share      , '-');                                                                                       <* 
    *> yUNIT_minchr ("... check mark"                     , my.mark       , '-');                                                                                       <* 
    *> yUNIT_minstr ("... check version"                  , x_vers        , "");                                                                                        <* 
    *> yUNIT_minstr ("... check description"              , my.desc       , "read a line");                                                                             <* 
    *> yUNIT_minstr ("... check method"                   , my.meth       , "SCRP_read");                                                                               <* 
    *> yUNIT_minstr ("... check arguments"                , my.args       , "");                                                                                        <* 
    *> yUNIT_minstr ("... check test"                     , my.test       , "");                                                                                        <* 
    *> yUNIT_minstr ("... check expect"                   , my.expe       , "");                                                                                        <* 
    *> yUNIT_minval ("close the script file"              , SCRP_close  (&(x_file)), 0);                                                                                <* 
    *> yUNIT_minval ("... check script pointer"           , x_file     , 0);                                                                                            <* 
    *> yUNIT_mindnoc ();                                                                                                                                                <*/

   /*> yUNIT_mincond ("attempt verb through test");                                                                                                                     <* 
    *> strcpy (x_scrp, "/tmp/koios.unit");                                                                                                                              <* 
    *> system ("echo \"exec     read a line      SCRP_read       i_lesser   \"                                             > /tmp/koios.unit");                    <* 
    *> yUNIT_minstr ("... check script name"              , x_scrp     , "/tmp/koios.unit");                                                                            <* 
    *> yUNIT_minval ("open the script file"               , SCRP_open   (, &(x_file), &(x_line)), 0);                                                                   <* 
    *> yUNIT_minval ("... check script pointer"           , x_file     , x_file);                                                                                       <* 
    *> yUNIT_minval ("read a line"                        , SCRP_read   (x_file, &(x_line), my.dittoing, my.ditto, &(my.dline), &(my.n_recd), &(my.len), x_recd), 1);   <* 
    *> yUNIT_minval ("parse a line"                       , SCRP_parse  (), -999);                                                                                      <* 
    *> yUNIT_minstr ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: too few fields (5) for exec, requires 6");                   <* 
    *> strlencode (x_recd, ySTR_NONE, LEN_RECD);                                                                                                                        <* 
    *> yUNIT_minstr ("... check the record"               , x_recd       , "exec    � read a line     � SCRP_read   �   � i_lesser   �");                               <* 
    *> yUNIT_minstr ("... check verb"                     , x_verb        , "exec");                                                                                    <* 
    *> yUNIT_minstr ("... check stage"                    , x_stage       , "");                                                                                        <* 
    *> yUNIT_minchr ("... check share"                    , my.share      , '-');                                                                                       <* 
    *> yUNIT_minchr ("... check mark"                     , my.mark       , '-');                                                                                       <* 
    *> yUNIT_minstr ("... check version"                  , x_vers        , "");                                                                                        <* 
    *> yUNIT_minstr ("... check description"              , my.desc       , "read a line");                                                                             <* 
    *> yUNIT_minstr ("... check method"                   , my.meth       , "SCRP_read");                                                                               <* 
    *> yUNIT_minstr ("... check arguments"                , my.args       , "");                                                                                        <* 
    *> yUNIT_minstr ("... check test"                     , my.test       , "i_lesser");                                                                                <* 
    *> yUNIT_minstr ("... check expect"                   , my.expe       , "");                                                                                        <* 
    *> yUNIT_minval ("close the script file"              , SCRP_close  (&(x_file)), 0);                                                                                <* 
    *> yUNIT_minval ("... check script pointer"           , x_file     , 0);                                                                                            <* 
    *> yUNIT_mindnoc ();                                                                                                                                                <*/


   yUNIT_minprcs ();
   PROG__unit_end  ();
   return 0;
}
char
koios__unit_ditto_setget (void)
{
}

char
koios__unit_scrp_ditto   (void)
{
   /*  yUNIT_minscrp ("koios_scrp identifying ditto marks");
    *    yURG_err_none ();
    * 
    *    yUNIT_mincond ("prepare clean start");
    *    system ("rm -f /tmp/koios.unit 2> /dev/null");
    *    yUNIT_mindnoc ();
    * 
    *    yUNIT_mincond ("set to conversion mode");
    *    my.run_type = G_RUN_UPDATE;
    *    yUNIT_mindnoc ();
    * 
    *    yUNIT_mincond ("set to defaults");
    *    yUNIT_minval  ("... run clear"                      , SCRP__shared_purge ()         , 0);
    *    yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "--------------------------   --------------------------   ----------");
    *    yUNIT_mindnoc ();
    * 
    *    yUNIT_mincond ("check a min cond identifier");
    *    yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
    *    yUNIT_minval  ("parse COND"                         , SCRP__parse_verb   (my.n_scrp, my.n_line, "COND (0)", my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code)), 0);
    *    yUNIT_minstr  ("... check verb"                     , my.verb          , "COND");
    *    yUNIT_minval  ("check ditto"                        , SCRP__ditto_check ("COND (0)"), 0);
    *    yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
    *    yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "--------------------------   --------------------------   0---------");
    *    yUNIT_minchr  ("... check mark"                     , my.mark          , '0');
    *    yUNIT_mindnoc ();
    * 
    *    yUNIT_mincond ("check a middle cond identifier");
    *    yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
    *    yUNIT_minval  ("parse COND"                         , SCRP__parse_verb   (my.n_scrp, my.n_line, "COND (3)", my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code)), 0);
    *    yUNIT_minstr  ("... check verb"                     , my.verb          , "COND");
    *    yUNIT_minval  ("check ditto"                        , SCRP__ditto_check ("COND (3)"), 0);
    *    yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
    *    yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "--------------------------   --------------------------   0--3------");
    *    yUNIT_minchr  ("... check mark"                     , my.mark          , '3');
    *    yUNIT_mindnoc ();
    * 
    *    yUNIT_mincond ("check a missing cond identifier, trunctated");
    *    yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
    *    yUNIT_minval  ("parse COND"                         , SCRP__parse_verb   (my.n_scrp, my.n_line, "COND ("  , my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code)), 0);
    *    yUNIT_minstr  ("... check verb"                     , my.verb          , "COND");
    *    yUNIT_minval  ("check ditto"                        , SCRP__ditto_check ("COND ("  ), -999);
    *    yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: COND identifier did not follow ( marker");
    *    yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "--------------------------   --------------------------   0--3------");
    *    yUNIT_minchr  ("... check mark"                     , my.mark          , '-');
    *    yUNIT_mindnoc ();
    * 
    *    yUNIT_mincond ("check a missing cond identifier");
    *    yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
    *    yUNIT_minval  ("parse COND"                         , SCRP__parse_verb   (my.n_scrp, my.n_line, "COND ()" , my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code)), 0);
    *    yUNIT_minstr  ("... check verb"                     , my.verb          , "COND");
    *    yUNIT_minval  ("check ditto"                        , SCRP__ditto_check ("COND ()" ), -999);
    *    yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: COND no identifier within () markers");
    *    yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "--------------------------   --------------------------   0--3------");
    *    yUNIT_minchr  ("... check mark"                     , my.mark          , '-');
    *    yUNIT_mindnoc ();
    * 
    *    yUNIT_mincond ("check a missing cond close marker");
    *    yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
    *    yUNIT_minval  ("parse COND"                         , SCRP__parse_verb   (my.n_scrp, my.n_line, "COND (5" , my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code)), 0);
    *    yUNIT_minstr  ("... check verb"                     , my.verb          , "COND");
    *    yUNIT_minval  ("check ditto"                        , SCRP__ditto_check ("COND (5" ), -999);
    *    yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: COND identifier �5� not followed by ) marker");
    *    yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "--------------------------   --------------------------   0--3------");
    *    yUNIT_minchr  ("... check mark"                     , my.mark          , '-');
    *    yUNIT_mindnoc ();
    * 
    *    yUNIT_mincond ("check cond with an invalid identifier");
    *    yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
    *    yUNIT_minval  ("parse COND"                         , SCRP__parse_verb   (my.n_scrp, my.n_line, "COND (B)" , my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code)), 0);
    *    yUNIT_minstr  ("... check verb"                     , my.verb          , "COND");
    *    yUNIT_minval  ("check ditto"                        , SCRP__ditto_check ("COND (B)" ), -999);
   *    yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: COND identifier �B� not valid [0-9]");
   *    yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "--------------------------   --------------------------   0--3------");
   *    yUNIT_minchr  ("... check mark"                     , my.mark          , '-');
   *    yUNIT_mindnoc ();
   * 
      *    yUNIT_mincond ("check a valid cond again (extra spaces)");
   *    yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   *    yUNIT_minval  ("parse COND"                         , SCRP__parse_verb   (my.n_scrp, my.n_line, "COND     (8)" , my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code)), 0);
   *    yUNIT_minstr  ("... check verb"                     , my.verb          , "COND");
   *    yUNIT_minval  ("check ditto"                        , SCRP__ditto_check ("COND     (8)"), 0);
   *    yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   *    yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "--------------------------   --------------------------   0--3----8-");
   *    yUNIT_minchr  ("... check mark"                     , my.mark          , '8');
   *    yUNIT_mindnoc ();
   * 
      *    yUNIT_mincond ("check a cond masking another");
   *    yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   *    yUNIT_minval  ("parse COND"                         , SCRP__parse_verb   (my.n_scrp, my.n_line, "COND     (8)" , my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code)), 0);
   *    yUNIT_minstr  ("... check verb"                     , my.verb          , "COND");
   *    yUNIT_minval  ("check ditto"                        , SCRP__ditto_check ("COND     (8)"), 0);
   *    yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: warning: COND identifier �8� already set, now overwritten");
   *    yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "--------------------------   --------------------------   0--3----8-");
   *    yUNIT_minchr  ("... check mark"                     , my.mark          , '8');
   *    yUNIT_mindnoc ();
   * 
      *    yUNIT_mincond ("check a valid ditto");
   *    yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   *    yUNIT_minval  ("parse COND"                         , SCRP__parse_verb   (my.n_scrp, my.n_line, "DITTO    (3)" , my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code)), 0);
   *    yUNIT_minstr  ("... check verb"                     , my.verb          , "DITTO");
   *    yUNIT_minval  ("check ditto"                        , SCRP__ditto_check ("DITTO    (3)"), 0);
   *    yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   *    yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "--------------------------   --------------------------   0--3----8-");
   *    yUNIT_minchr  ("... check mark"                     , my.mark          , '3');
   *    yUNIT_mindnoc ();
   * 
      *    yUNIT_mincond ("check a ditto with no lead marker");
   *    yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   *    yUNIT_minval  ("parse COND"                         , SCRP__parse_verb   (my.n_scrp, my.n_line, "DITTO" , my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code)), 0);
   *    yUNIT_minstr  ("... check verb"                     , my.verb          , "DITTO");
   *    yUNIT_minval  ("check ditto"                        , SCRP__ditto_check ("DITTO"), -999);
   *    yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: DITTO missing a valid identifier string (?)");
   *    yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "--------------------------   --------------------------   0--3----8-");
   *    yUNIT_minchr  ("... check mark"                     , my.mark          , '-');
   *    yUNIT_mindnoc ();
   * 
      *    yUNIT_mincond ("check a ditto with no identifier (truncated)");
   *    yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   *    yUNIT_minval  ("parse COND"                         , SCRP__parse_verb   (my.n_scrp, my.n_line, "DITTO (" , my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code)), 0);
   *    yUNIT_minstr  ("... check verb"                     , my.verb          , "DITTO");
   *    yUNIT_minval  ("check ditto"                        , SCRP__ditto_check ("DITTO ("), -999);
   *    yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: DITTO identifier did not follow ( marker");
   *    yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "--------------------------   --------------------------   0--3----8-");
   *    yUNIT_minchr  ("... check mark"                     , my.mark          , '-');
   *    yUNIT_mindnoc ();
   * 
      *    yUNIT_mincond ("check a ditto with no identifier inside markers");
   *    yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   *    yUNIT_minval  ("parse COND"                         , SCRP__parse_verb   (my.n_scrp, my.n_line, "DITTO ()" , my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code)), 0);
   *    yUNIT_minstr  ("... check verb"                     , my.verb          , "DITTO");
   *    yUNIT_minval  ("check ditto"                        , SCRP__ditto_check ("DITTO ()"), -999);
   *    yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: DITTO no identifier within () markers");
   *    yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "--------------------------   --------------------------   0--3----8-");
   *    yUNIT_minchr  ("... check mark"                     , my.mark          , '-');
   *    yUNIT_mindnoc ();
   * 
      *    yUNIT_mincond ("check a ditto with illegal identifier");
   *    yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   *    yUNIT_minval  ("parse COND"                         , SCRP__parse_verb   (my.n_scrp, my.n_line, "DITTO (a)" , my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code)), 0);
   *    yUNIT_minstr  ("... check verb"                     , my.verb          , "DITTO");
   *    yUNIT_minval  ("check ditto"                        , SCRP__ditto_check ("DITTO (a)"), -999);
   *    yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: DITTO identifier �a� not valid [0-9]");
   *    yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "--------------------------   --------------------------   0--3----8-");
   *    yUNIT_minchr  ("... check mark"                     , my.mark          , '-');
   *    yUNIT_mindnoc ();
   * 
      *    yUNIT_mincond ("check a ditto with an unset identifier");
   *    yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   *    yUNIT_minval  ("parse COND"                         , SCRP__parse_verb   (my.n_scrp, my.n_line, "DITTO (5)" , my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code)), 0);
   *    yUNIT_minstr  ("... check verb"                     , my.verb          , "DITTO");
   *    yUNIT_minval  ("check ditto"                        , SCRP__ditto_check ("DITTO (5)"), -999);
   *    yUNIT_minstr  ("... check error message"            , yURG_err_last (), "/tmp/koios.unit:1:1: error: DITTO identifier �5� not set by previous COND");
   *    yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "--------------------------   --------------------------   0--3----8-");
   *    yUNIT_minchr  ("... check mark"                     , my.mark          , '-');
   *    yUNIT_mindnoc ();
   * 
      *    yUNIT_mincond ("check another valid ditto");
   *    yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   *    yUNIT_minval  ("parse COND"                         , SCRP__parse_verb   (my.n_scrp, my.n_line, "DITTO    (8)" , my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code)), 0);
   *    yUNIT_minstr  ("... check verb"                     , my.verb          , "DITTO");
   *    yUNIT_minval  ("check ditto"                        , SCRP__ditto_check ("DITTO    (8)"), 0);
   *    yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   *    yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "--------------------------   --------------------------   0--3----8-");
   *    yUNIT_minchr  ("... check mark"                     , my.mark          , '8');
   *    yUNIT_mindnoc ();
   * 
      *    yUNIT_mincond ("set to defaults");
   *    yUNIT_minval  ("... run clear"                      , SCRP__shared_purge ()         , 0);
   *    yUNIT_minstr  ("... check all marks"                , SCRP__shared_used  ()         , "--------------------------   --------------------------   ----------");
   *    yUNIT_mindnoc ();
   * 
      *    yUNIT_mincond ("set to create/code mode");
   *    my.run_type = G_RUN_CREATE;
   *    yUNIT_mindnoc ();
   * 
      *    yUNIT_mincond ("verify handling dittos");
   *    strcpy (my.n_scrp, "/tmp/koios.unit");
   *    system ("echo \"\"                                                                         >  /tmp/koios.unit");
   *    system ("echo \"  COND (2)   original cond    - - - - - -  -  - - - - -   - - -  \"  >> /tmp/koios.unit");
   *    system ("echo \"    exec     line one         - - - - - -  -  - - - - -   - - -  \"  >> /tmp/koios.unit");
   *    system ("echo \"    exec     line two         - - - - - -  -  - - - - -   - - -  \"  >> /tmp/koios.unit");
   *    system ("echo \"\"                                                                         >> /tmp/koios.unit");
   *    system ("echo \"  DITTO (2)  new cond         - - - - - -  -  - - - - -   - - -  \"  >> /tmp/koios.unit");
   *    system ("echo \"\"                                                                         >> /tmp/koios.unit");
   *    system ("echo \"  COND       after others     - - - - - -  -  - - - - -   - - -  \"  >> /tmp/koios.unit");
   *    yUNIT_minstr ("... check script name"              , my.n_scrp     , "/tmp/koios.unit");
   *    yUNIT_minval ("open the script file"               , SCRP_open   (my.n_scrp, &(my.f_scrp), &(my.n_line)), 0);
   *    yUNIT_mindnoc ();
   * 
      *    yUNIT_mincond ("read ditto condition");
   *    yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   *    yUNIT_minval ("read a line"                        , SCRP_read   (my.f_scrp, &(my.n_line), my.dittoing, my.ditto, &(my.dline), &(my.n_recd), &(my.len), my.recd), 1);
   *    yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);
   *    yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   *    strlencode (my.recd, ySTR_NONE, LEN_RECD);
   *    yUNIT_minstr ("... check the record"               , my.recd       , "  COND (2)  � original cond   � - - - - - - � - � - - - - -  � - - -  �");
   *    yUNIT_minstr ("... check all marks"                 , SCRP__shared_used  ()         , "--------------------------   --------------------------   --2-------");
   *    yUNIT_mindnoc ();
   * 
      *    yUNIT_mincond ("read detailed line");
   *    yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   *    yUNIT_minval ("read a line"                        , SCRP_read   (my.f_scrp, &(my.n_line), my.dittoing, my.ditto, &(my.dline), &(my.n_recd), &(my.len), my.recd), 1);
   *    yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);
   *    yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   *    strlencode (my.recd, ySTR_NONE, LEN_RECD);
   *    yUNIT_minstr ("... check the record"               , my.recd       , "    exec    � line one        � - - - - - - � - � - - - - -  � - - -  �");
   *    yUNIT_minstr ("... check all marks"                 , SCRP__shared_used  ()         , "--------------------------   --------------------------   --2-------");
   *    yUNIT_mindnoc ();
   * 
      *    yUNIT_mincond ("read detailed line");
   *    yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   *    yUNIT_minval ("read a line"                        , SCRP_read   (my.f_scrp, &(my.n_line), my.dittoing, my.ditto, &(my.dline), &(my.n_recd), &(my.len), my.recd), 1);
   *    yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);
   *    yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   *    strlencode (my.recd, ySTR_NONE, LEN_RECD);
   *    yUNIT_minstr ("... check the record"               , my.recd       , "    exec    � line two        � - - - - - - � - � - - - - -  � - - -  �");
   *    yUNIT_minstr ("... check all marks"                 , SCRP__shared_used  ()         , "--------------------------   --------------------------   --2-------");
   *    yUNIT_mindnoc ();
   * 
      *    yUNIT_mincond ("read ditto call");
   *    yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   *    yUNIT_minval ("read a line"                        , SCRP_read   (my.f_scrp, &(my.n_line), my.dittoing, my.ditto, &(my.dline), &(my.n_recd), &(my.len), my.recd), 1);
   *    yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);
   *    yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   *    strlencode (my.recd, ySTR_NONE, LEN_RECD);
   *    yUNIT_minstr ("... check the record"               , my.recd       , "  DITTO (2) � new cond        � - - - - - - � - � - - - - -  � - - -  �");
   *    yUNIT_minstr ("... check all marks"                 , SCRP__shared_used  ()         , "--------------------------   --------------------------   --2-------");
   *    yUNIT_mindnoc ();
   * 
      *    yUNIT_mincond ("read ditto condition");
   *    yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   *    yUNIT_minval ("read a line"                        , SCRP_read   (my.f_scrp, &(my.n_line), my.dittoing, my.ditto, &(my.dline), &(my.n_recd), &(my.len), my.recd), 1);
   *    yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);
   *    yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   *    strlencode (my.recd, ySTR_NONE, LEN_RECD);
   *    yUNIT_minstr ("... check the record"               , my.recd       , "  COND (2)  � original cond   � - - - - - - � - � - - - - -  � - - -  �");
   *    yUNIT_minstr ("... check all marks"                 , SCRP__shared_used  ()         , "--------------------------   --------------------------   --2-------");
   *    yUNIT_mindnoc ();
   * 
      *    yUNIT_mincond ("read detailed line");
   *    yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   *    yUNIT_minval ("read a line"                        , SCRP_read   (my.f_scrp, &(my.n_line), my.dittoing, my.ditto, &(my.dline), &(my.n_recd), &(my.len), my.recd), 1);
   *    yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);
   *    yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   *    strlencode (my.recd, ySTR_NONE, LEN_RECD);
   *    yUNIT_minstr ("... check the record"               , my.recd       , "    exec    � line one        � - - - - - - � - � - - - - -  � - - -  �");
   *    yUNIT_minstr ("... check all marks"                 , SCRP__shared_used  ()         , "--------------------------   --------------------------   --2-------");
   *    yUNIT_mindnoc ();
   * 
      *    yUNIT_mincond ("read detailed line");
   *    yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   *    yUNIT_minval ("read a line"                        , SCRP_read   (my.f_scrp, &(my.n_line), my.dittoing, my.ditto, &(my.dline), &(my.n_recd), &(my.len), my.recd), 1);
   *    yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);
   *    yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   *    strlencode (my.recd, ySTR_NONE, LEN_RECD);
   *    yUNIT_minstr ("... check the record"               , my.recd       , "    exec    � line two        � - - - - - - � - � - - - - -  � - - -  �");
   *    yUNIT_minstr ("... check all marks"                 , SCRP__shared_used  ()         , "--------------------------   --------------------------   --2-------");
   *    yUNIT_mindnoc ();
   * 
      *    yUNIT_mincond ("read after condition");
   *    yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   *    yUNIT_minval ("read a line"                        , SCRP_read   (my.f_scrp, &(my.n_line), my.dittoing, my.ditto, &(my.dline), &(my.n_recd), &(my.len), my.recd), 1);
   *    yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);
   *    yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   *    strlencode (my.recd, ySTR_NONE, LEN_RECD);
   *    yUNIT_minstr ("... check the record"               , my.recd       , "  COND      � after others    � - - - - - - � - � - - - - -  � - - -  �");
   *    yUNIT_minstr ("... check all marks"                 , SCRP__shared_used  ()         , "--------------------------   --------------------------   --2-------");
   *    yUNIT_mindnoc ();
   * 
      *    yUNIT_mincond ("read end-of-file");
   *    yUNIT_minval  ("clear errors"                       , yURG_err_clear (), 0);
   *    yUNIT_minval ("read a line"                        , SCRP_read   (my.f_scrp, &(my.n_line), my.dittoing, my.ditto, &(my.dline), &(my.n_recd), &(my.len), my.recd), 0);
   *    yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), -999);
   *    yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   *    yUNIT_minval ("close the script file"              , SCRP_close  (&(my.f_scrp)), 0);
   *    yUNIT_mindnoc ();
   * 
      *    yUNIT_mincond ("clean up after");
   *    system ("rm -f /tmp/koios.unit 2> /dev/null");
   *    yUNIT_mindnoc ();
   * 
      *    yUNIT_minprcs ();
   */
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
   system ("echo \"SCRP    [��]  (SCRP  ) verify openning and closin                                           ((01.---))  - - - - - - - - - -  \"                   >> /tmp/koios.unit");
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
   yUNIT_minval ("open the script file"               , SCRP_open   (my.n_scrp, &(my.f_scrp), &(my.n_line)), 0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("read very detailed exec line");
   yUNIT_minval ("read a line"                        , SCRP_read   (my.f_scrp, &(my.n_line), my.dittoing, my.ditto, &(my.dline), &(my.n_recd), &(my.len), my.recd), 1);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "exec         � read a line     � SCRP_read   �   � i_lesser   � 0      � my_var   �");
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
   yUNIT_minval ("read a line"                        , SCRP_read   (my.f_scrp, &(my.n_line), my.dittoing, my.ditto, &(my.dline), &(my.n_recd), &(my.len), my.recd), 1);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);
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
   yUNIT_minval ("read a line"                        , SCRP_read   (my.f_scrp, &(my.n_line), my.dittoing, my.ditto, &(my.dline), &(my.n_recd), &(my.len), my.recd), 1);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "     get     � ... check on script � SCRP__unit  � file , -1 � s_equal � SCRP file      : /tmp/koios.unit �");
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
   yUNIT_minval ("read a line"                        , SCRP_read   (my.f_scrp, &(my.n_line), my.dittoing, my.ditto, &(my.dline), &(my.n_recd), &(my.len), my.recd), 1);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "   code      � add lines                           � - - - - - - - - - - - - -  � system ();        �");
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
   yUNIT_minval ("read a line"                        , SCRP_read   (my.f_scrp, &(my.n_line), my.dittoing, my.ditto, &(my.dline), &(my.n_recd), &(my.len), my.recd), 1);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "  COND       � parse a code record  � - - - - - - - - - - - - -  � ((01.001)) � - - - - - - - - - �");
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
   yUNIT_minval ("read a line"                        , SCRP_read   (my.f_scrp, &(my.n_line), my.dittoing, my.ditto, &(my.dline), &(my.n_recd), &(my.len), my.recd), 1);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "PREP         � include the prototype headers                           � - - - - - - - - - -  � - - - - -  � - - - - - - - - - -  �>>");
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
   yUNIT_minval ("read a line"                        , SCRP_read   (my.f_scrp, &(my.n_line), my.dittoing, my.ditto, &(my.dline), &(my.n_recd), &(my.len), my.recd), 1);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "   incl      � include public header               � koios.h          � - - - - - - - - - -  � - - - - -  � - - - - - - - - - -  �");
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
   yUNIT_minval ("read a line"                        , SCRP_read   (my.f_scrp, &(my.n_line), my.dittoing, my.ditto, &(my.dline), &(my.n_recd), &(my.len), my.recd), 1);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "SCRP    [��] � (SCRP  ) verify openning and closin �                                         � ((01.---)) � - - - - - - - - - -  �");
   yUNIT_minstr ("... check verb"                     , my.verb       , "SCRP");
   yUNIT_minstr ("... check stage"                    , my.stage      , "��");
   yUNIT_minchr ("... check share"                    , my.share      , '-');
   yUNIT_minchr ("... check mark"                     , my.mark       , '-');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "(SCRP  ) verify openning and closin");
   yUNIT_minstr ("... check method"                   , my.meth       , "");
   yUNIT_minstr ("... check arguments"                , my.args       , "");
   yUNIT_minstr ("... check test"                     , my.test       , "");
   yUNIT_minstr ("... check expect"                   , my.expe       , "");
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("read stdin load line");
   yUNIT_minval ("read a line"                        , SCRP_read   (my.f_scrp, &(my.n_line), my.dittoing, my.ditto, &(my.dline), &(my.n_recd), &(my.len), my.recd), 1);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "  load       � add a line to stdin   � stdin � * * * * *                      : basic line                  : - - - - -  :  /bin/true > /dev/null�");
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
   yUNIT_minval ("read a line"                        , SCRP_read   (my.f_scrp, &(my.n_line), my.dittoing, my.ditto, &(my.dline), &(my.n_recd), &(my.len), my.recd), 1);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), -999);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "  toad       � add a line to stdin 2 � stdin � * * * * *                      : basic line                  : - - - - -  :  /bin/true > /dev/null�");
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
   yUNIT_minval ("read a line"                        , SCRP_read   (my.f_scrp, &(my.n_line), my.dittoing, my.ditto, &(my.dline), &(my.n_recd), &(my.len), my.recd), 1);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), -999);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "             � (SCRP  ) verify openning and closin �                                         � ((01.---)) � - - - - - - - - - -  �");
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
   yUNIT_minval ("read a line"                        , SCRP_read   (my.f_scrp, &(my.n_line), my.dittoing, my.ditto, &(my.dline), &(my.n_recd), &(my.len), my.recd), 1);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "GROUP        � complete              � - - - - - - - - - - - - - - -  � - - - - -  � - - - - - - - - - - - - - - - - - - - - - - - - -  �");
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
   yUNIT_minval ("read a line"                        , SCRP_read   (my.f_scrp, &(my.n_line), my.dittoing, my.ditto, &(my.dline), &(my.n_recd), &(my.len), my.recd), 1);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "SECT         � internal testing      � - - - - - - - - - - - - - - -  � - - - - -  � - - - - - - - - - - - - - - - - - - - - - - - - -  �");
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
   yUNIT_minval ("read a line"                        , SCRP_read   (my.f_scrp, &(my.n_line), my.dittoing, my.ditto, &(my.dline), &(my.n_recd), &(my.len), my.recd), 1);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "    echo     � ...check y location   � - - - - - - - - - - - - -  � y       � r_norm93   � -125.381                                     �");
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
   yUNIT_minval ("read a line"                        , SCRP_read   (my.f_scrp, &(my.n_line), my.dittoing, my.ditto, &(my.dline), &(my.n_recd), &(my.len), my.recd), 1);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "    system   � remove a file                       � - - - - - - - - - - - - -  � rm -fv test.txt   �");
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
   yUNIT_minval ("read a line"                        , SCRP_read   (my.f_scrp, &(my.n_line), my.dittoing, my.ditto, &(my.dline), &(my.n_recd), &(my.len), my.recd), 1);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "SHARED   -a- � setup cron files and lines          � - - - - - - - -  � ((CC.---)) � - - - - - - - - - - - - - - - - - - - - - - - - -  �");
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
   yUNIT_minval ("read a line"                        , SCRP_read   (my.f_scrp, &(my.n_line), my.dittoing, my.ditto, &(my.dline), &(my.n_recd), &(my.len), my.recd), 1);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , " REUSE -a-   � - - - - - - - - - - - -  � - - - - - - - - - - - - - - -  � ((03.---)) � - - - - - - - - - - - - - - - - - - - -  �");
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
   yUNIT_minval ("read a line"                        , SCRP_read   (my.f_scrp, &(my.n_line), my.dittoing, my.ditto, &(my.dline), &(my.n_recd), &(my.len), my.recd), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), -999);
   yUNIT_minval ("close the script file"              , SCRP_close  (&(my.f_scrp)), 0);
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
   yUNIT_minstr ("... ... shebang"                    , yURG_peek (my.n_conv, '�'), "#!/usr/local/bin/koios");
   yUNIT_minstr ("... ... title"                      , yURG_peek (my.n_conv, '�'), "#   koios-polos (axis of heaven) unit testing meta-language");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_conv) , 2);
   yUNIT_mindnoc ();

   yUNIT_mincond ("write a standard header");
   CONV_cycle ();
   yUNIT_minval ("call header"                        , CONV_header (), 0);
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_conv, '�'), "");
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_conv, '�'), "");
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_conv, '�'), "");
   yUNIT_minstr ("... ... ruler"                      , yURG_peek (my.n_conv, '�'), "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-123456789- ");
   yUNIT_minstr ("... ... title"                      , yURG_peek (my.n_conv, '�'), "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  ========(var)======= ");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_conv) , 5);
   yUNIT_mindnoc ();

   yUNIT_mincond ("write the ending");
   CONV_cycle ();
   yUNIT_minval ("call end"                           , CONV_end    (), 0);
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_conv, '�'), "");
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_conv, '�'), "");
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_conv, '�'), "");
   yUNIT_minstr ("... check unit finish"              , yURG_peek (my.n_conv, '�'), "# end-of-file.  done, finito, completare, whimper [ϴ���");
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
   yUNIT_minval ("open the script file"               , SCRP_open   (my.n_scrp, &(my.f_scrp), &(my.n_line)), 0);
   strcpy (my.n_conv, "/tmp/koios.unit.new");
   yUNIT_minval ("open the script file"               , CONV_open   (), 0);
   yUNIT_minstr ("... check script name"              , my.n_conv     , "/tmp/koios.unit.new");
   yUNIT_minval ("... check script pointer"           , my.f_conv     , my.f_conv);
   yUNIT_mindnoc ();

   yUNIT_mincond ("write the prep");
   strcpy (my.recd, "PREP   include the prototype headers          ");
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse the prep line"                , SCRP_parse (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "PREP  � include the prototype headers  �  �  �  �  �");
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
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_conv, '�'), "");
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_conv, '�'), "");
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_conv, '�'), "");
   yUNIT_minstr ("... ... ruler"                      , yURG_peek (my.n_conv, '�'), "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-123456789- ");
   yUNIT_minstr ("... ... title"                      , yURG_peek (my.n_conv, '�'), "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  ========(var)======= ");
   yUNIT_minstr ("... check unit prep"                , yURG_peek (my.n_conv, '�'), "PREP          include the prototype headers                                      - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_conv) , 6);
   yUNIT_mindnoc ();

   yUNIT_mincond ("write an include");
   strcpy (my.recd, "incl   public header  stdio.h         ");
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse the line"                     , SCRP_parse (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "incl  � public header � stdio.h �  �  �  �  �");
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
   yUNIT_minstr ("... check include line"             , yURG_peek (my.n_conv, '�'), "   incl       public header                        stdio.h                     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_conv) , 1);
   yUNIT_mindnoc ();

   yUNIT_mincond ("write a comment");
   strcpy (my.recd, "#> the following macro resets exec lines");
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse the line"                     , SCRP_parse (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);
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
   yUNIT_minstr ("... check unit comment"             , yURG_peek (my.n_conv, '�'), "#> the following macro resets exec lines");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_conv) , 1);
   yUNIT_mindnoc ();

   yUNIT_mincond ("clean up after");
   yUNIT_minval ("close script"                       , SCRP_close  (&(my.f_scrp)), 0);
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
   yUNIT_minval ("open the script file"               , SCRP_open   (my.n_scrp, &(my.f_scrp), &(my.n_line)), 0);
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
   strcpy (my.recd, "SCRP [��]   (FILE) biggest script  core_function       ");
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse the line"                     , SCRP_parse (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "SCRP [��]  � (FILE) biggest script � core_function �  �  �  �");
   yUNIT_minstr ("... check verb"                     , my.verb       , "SCRP");
   yUNIT_minstr ("... check stage"                    , my.stage      , "��");
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
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_conv, '�'), "");
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_conv, '�'), "");
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_conv, '�'), "");
   yUNIT_minstr ("... ... ruler"                      , yURG_peek (my.n_conv, '�'), "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-123456789- ");
   yUNIT_minstr ("... ... title"                      , yURG_peek (my.n_conv, '�'), "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  ========(var)======= ");
   yUNIT_minstr ("... check script"                   , yURG_peek (my.n_conv, '�'), "SCRP    [��]  (FILE) biggest script                                              0s   tbd             core_function                                                                ((01.---))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_conv) , 6);
   yUNIT_mindnoc ();

   yUNIT_mincond ("write a section break");
   strcpy (my.recd, "SECT  file oriented         ");
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse the line"                     , SCRP_parse (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "SECT � file oriented �  �  �  �  �");
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
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_conv, '�'), "");
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_conv, '�'), "");
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_conv, '�'), "");
   yUNIT_minstr ("... ... ruler"                      , yURG_peek (my.n_conv, '�'), "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-123456789- ");
   yUNIT_minstr ("... ... title"                      , yURG_peek (my.n_conv, '�'), "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  ========(var)======= ");
   yUNIT_minstr ("... check section"                  , yURG_peek (my.n_conv, '�'), "SECT          file oriented                                                      - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_conv) , 6);
   yUNIT_mindnoc ();

   yUNIT_mincond ("write a shared line");
   strcpy (my.recd, "SHARED -a-  remove temporary files         ");
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse the line"                     , SCRP_parse (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "SHARED -a- � remove temporary files �  �  �  �  �");
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
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_conv, '�'), "");
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_conv, '�'), "");
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_conv, '�'), "");
   yUNIT_minstr ("... ... ruler"                      , yURG_peek (my.n_conv, '�'), "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-123456789- ");
   yUNIT_minstr ("... ... title"                      , yURG_peek (my.n_conv, '�'), "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  ========(var)======= ");
   yUNIT_minstr ("... check shared header"            , yURG_peek (my.n_conv, '�'), "SHARED   -a-  remove temporary files                                             0s   tbd             - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ((aa.---))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_conv) , 6);
   yUNIT_mindnoc ();

   strcpy (my.n_base, "master");  /* prepare for SHARED defense testing */

   yUNIT_mincond ("write a global line");
   strcpy (my.recd, "GLOBAL -D-  setup base test objects         ");
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse the line"                     , SCRP_parse (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "GLOBAL -D- � setup base test objects �  �  �  �  �");
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
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_conv, '�'), "");
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_conv, '�'), "");
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_conv, '�'), "");
   yUNIT_minstr ("... ... ruler"                      , yURG_peek (my.n_conv, '�'), "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-123456789- ");
   yUNIT_minstr ("... ... title"                      , yURG_peek (my.n_conv, '�'), "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  ========(var)======= ");
   yUNIT_minstr ("... check global header"            , yURG_peek (my.n_conv, '�'), "GLOBAL   -D-  setup base test objects                                            0s   tbd             - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ((DD.---))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_conv) , 6);
   yUNIT_mindnoc ();

   strcpy (my.n_base, "koios" );  /* prepare for SHARED testing */

   yUNIT_mincond ("clean up after");
   yUNIT_minval ("close script"                       , SCRP_close  (&(my.f_scrp)), 0);
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
   yUNIT_minval ("open the script file"               , SCRP_open   (my.n_scrp, &(my.f_scrp), &(my.n_line)), 0);
   strcpy (my.n_conv, "/tmp/koios.unit.new");
   yUNIT_minval ("open the script file"               , CONV_open   (), 0);
   yUNIT_minstr ("... check script name"              , my.n_conv     , "/tmp/koios.unit.new");
   yUNIT_minval ("... check script pointer"           , my.f_conv     , my.f_conv);
   yUNIT_mindnoc ();

   yUNIT_mincond ("write a condition");
   strcpy (my.recd, "COND (2)  verify successful value         ");
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse the line"                     , SCRP_parse (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "COND (2) � verify successful value �  �  �  �  �");
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
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_conv, '�'), "");
   yUNIT_minstr ("... check condition header"         , yURG_peek (my.n_conv, '�'), "   COND  (2)  verify successful value                                            - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((DD.001))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_conv) , 2);
   yUNIT_mindnoc ();

   yUNIT_mincond ("write a ditto");
   strcpy (my.recd, "DITTO (2)           ");
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse the line"                     , SCRP_parse (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "DITTO (2) �  �  �  �  �  �");
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
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_conv, '�'), "");
   yUNIT_minstr ("... check ditto"                    , yURG_peek (my.n_conv, '�'), "   DITTO (2)  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((DD.002))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_conv) , 2);
   yUNIT_mindnoc ();

   yUNIT_mincond ("write a group");
   strcpy (my.recd, "GROUP  check major defenses         ");
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse the line"                     , SCRP_parse (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "GROUP � check major defenses �  �  �  �  �");
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
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_conv, '�'), "");
   yUNIT_minstr ("... check group"                    , yURG_peek (my.n_conv, '�'), "   GROUP      check major defenses                                               - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_conv) , 2);
   yUNIT_mindnoc ();

   yUNIT_mincond ("write a use for shares");
   /*> yUNIT_minval ("... set shared to reuse"            , SCRP__shared_set   ('r', 'd') ,    0);   <*/
   strcpy (my.recd, "REUSE -d-           ");
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse the line"                     , SCRP_parse (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "REUSE -d- �  �  �  �  �  �");
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
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_conv, '�'), "");
   yUNIT_minstr ("... check reuse"                    , yURG_peek (my.n_conv, '�'), "   REUSE -d-  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_conv) , 2);
   yUNIT_mindnoc ();

   yUNIT_mincond ("clean up after");
   yUNIT_minval ("close script"                       , SCRP_close  (&(my.f_scrp)), 0);
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
   yUNIT_minval ("open the script file"               , SCRP_open   (my.n_scrp, &(my.f_scrp), &(my.n_line)), 0);
   strcpy (my.n_conv, "/tmp/koios.unit.new");
   yUNIT_minval ("open the script file"               , CONV_open   (), 0);
   yUNIT_minstr ("... check script name"              , my.n_conv     , "/tmp/koios.unit.new");
   yUNIT_minval ("... check script pointer"           , my.f_conv     , my.f_conv);
   yUNIT_mindnoc ();

   yUNIT_mincond ("write a exec");
   strcpy (my.recd, "exec          read a line      SCRP_read    test, 5   i_lesser    0       my_var   ");
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse the line"                     , SCRP_parse (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "exec         � read a line     � SCRP_read   � test, 5  � i_lesser   � 0      � my_var   �");
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
   yUNIT_minstr ("... check exec"                     , yURG_peek (my.n_conv, '�'), "     exec     read a line                          SCRP_read                   test, 5                                                                                               i_lesser    0                                                                                                     my_var               ");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_conv) , 1);
   yUNIT_mindnoc ();

   yUNIT_mincond ("write a get");
   strcpy (my.recd, "get  ...check count  UNIT_answer  \"ans\"  s_equal  count = 15.2 ");
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse the line"                     , SCRP_parse (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "get � ...check count � UNIT_answer � \"ans\" � s_equal � count = 15.2 �");
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
   yUNIT_minstr ("... check get"                      , yURG_peek (my.n_conv, '�'), "     get      ...check count                       UNIT_answer                 \"ans\"                                                                                                 s_equal     count = 15.2                                                                                         ");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_conv) , 1);
   yUNIT_mindnoc ();

   yUNIT_mincond ("write a mode");
   strcpy (my.recd, "mode  FORCED_FAIL         ");
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse the line"                     , SCRP_parse (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "mode � FORCED_FAIL �  �  �  �  �");
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
   yUNIT_minstr ("... check mode"                     , yURG_peek (my.n_conv, '�'), "     mode     FORCED_FAIL                          - - - - - - - - - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_conv) , 1);
   yUNIT_mindnoc ();

   yUNIT_mincond ("write a load");
   strcpy (my.recd, "load  keyboard input  ncurses  abcdefghijklmnopqrstuvwxyz ");
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse the line"                     , SCRP_parse (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "load � keyboard input � ncurses � abcdefghijklmnopqrstuvwxyz �");
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
   yUNIT_minstr ("... check load"                     , yURG_peek (my.n_conv, '�'), "     load     keyboard input                       ncurses                     abcdefghijklmnopqrstuvwxyz                                                                                                                                                                                                 ");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_conv) , 1);
   yUNIT_mindnoc ();

   yUNIT_mincond ("write a code");
   strcpy (my.recd, "code  working variable   int l = 15; ");
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse the line"                     , SCRP_parse (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "code � working variable � � int l = 15; �");
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
   yUNIT_minstr ("... check code"                     , yURG_peek (my.n_conv, '�'), "     code     working variable                     - - - - - - - - - - - - -   int l = 15;                                                                                                                                                                                                                ");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_conv) , 1);
   yUNIT_mindnoc ();

   yUNIT_mincond ("write an echo");
   strcpy (my.recd, "echo  check length   l  r_equal  15.2 ");
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse the line"                     , SCRP_parse (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "echo � check length � � l � r_equal � 15.2 �");
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
   yUNIT_minstr ("... check echo"                     , yURG_peek (my.n_conv, '�'), "     echo     check length                         - - - - - - - - - - - - -   l                                                                                                     r_equal     15.2                                                                                                 ");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_conv) , 1);
   yUNIT_mindnoc ();

   yUNIT_mincond ("clean up after");
   yUNIT_minval ("close script"                       , SCRP_close  (&(my.f_scrp)), 0);
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
/*> static void      o___CODE____________________o (void) {;}                         <*/

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
   yUNIT_minval ("... master using greek"             , CODE__shared_index ('m', '�') , -999);
   yUNIT_mindnoc ();

   yUNIT_mincond ("check reuses indexing");
   yUNIT_minval ("... reuses min"                     , CODE__shared_index ('r', 'a') ,    0);
   yUNIT_minval ("... reuses middle"                  , CODE__shared_index ('r', 'm') ,   12);
   yUNIT_minval ("... reuses max"                     , CODE__shared_index ('r', 'z') ,   25);
   yUNIT_minval ("... reuses too small"               , CODE__shared_index ('r',  0 ) , -999);
   yUNIT_minval ("... reuses using master"            , CODE__shared_index ('r', 'B') , -999);
   yUNIT_minval ("... reuses using dittos"            , CODE__shared_index ('r', '4') , -999);
   yUNIT_minval ("... reuses using greek"             , CODE__shared_index ('r', '�') , -999);
   yUNIT_mindnoc ();

   yUNIT_mincond ("check indexing with bad types");
   yUNIT_minval ("... check null"                     , CODE__shared_index ( 0 , '0') , -999);
   yUNIT_minval ("... check dittos"                   , CODE__shared_index ('d', '0') , -999);
   yUNIT_minval ("... check symbol"                   , CODE__shared_index ('#', '0') , -999);
   yUNIT_minval ("... check greek"                    , CODE__shared_index ('�', '0') , -999);
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
   yUNIT_minval ("... get master greek"               , CODE__shared_add   ('m', '�', &x_cond, &x_step) , -999);
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
   yUNIT_minval ("... get master greek"               , CODE__shared_add   ('m', '�', &x_cond, &x_step) , -999);
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
   yUNIT_minval ("... get reuses greek"               , CODE__shared_add   ('r', '�', &x_cond, &x_step) , -999);
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
   yUNIT_minval ("... get reuses greek"               , CODE__shared_add   ('r', '�', &x_cond, &x_step) , -999);
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
   yUNIT_minstr ("... check code beginning"           , yURG_peek (my.n_code, '�'), "/*================================= beg-code =================================*/");
   yUNIT_minstr ("... ... shebang"                    , yURG_peek (my.n_code, '�'), "/* /usr/local/bin/koios                                                       */");
   yUNIT_minstr ("... ... title"                      , yURG_peek (my.n_code, '�'), "/*   autogen by koios-polos (axis of heaven) unit testing meta-language       */");
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_code, '�'), "");
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_code, '�'), "/*---(standard support functions)----*/");
   yUNIT_minstr ("... check include header"           , yURG_peek (my.n_code, '�'), "#include    <yUNIT_unit.h>");
   yUNIT_minstr ("... check include header"           , yURG_peek (my.n_code, '�'), "#include    \"master.h\"");
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_code, '�'), "");
   yUNIT_minstr ("... check script comment"           , yURG_peek (my.n_code, '�'), "/*================================ beg-script ================================*/");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) , 9);
   yUNIT_mindnoc ();

   yUNIT_mincond ("write the ending of code");
   CODE_cycle ();
   yUNIT_minval ("call end"                           , CODE_end    (), 0);
   yUNIT_minstr ("... check script comment"           , yURG_peek (my.n_code, '�'), "/*================================ end-script ================================*/");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) , 1);
   yUNIT_mindnoc ();

   yUNIT_mincond ("write the beginning of main");
   CODE_cycle ();
   yUNIT_minval ("call beg"                           , MAIN_beg    (), 0);
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_main, '�'), "");
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_main, '�'), "");
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_main, '�'), "");
   yUNIT_minstr ("... check return type"              , yURG_peek (my.n_main, '�'), "int");
   yUNIT_minstr ("... check definition"               , yURG_peek (my.n_main, '�'), "main                    (int a_argc, char *a_argv[])");
   yUNIT_minstr ("... check open brace"               , yURG_peek (my.n_main, '�'), "{");
   yUNIT_minstr ("... check comment"                  , yURG_peek (my.n_main, '�'), "   /*---(locals)-----------+-----+-----+-*/");
   yUNIT_minstr ("... check local"                    , yURG_peek (my.n_main, '�'), "   int         rc          =    0;");
   yUNIT_minstr ("... check comment"                  , yURG_peek (my.n_main, '�'), "   /*---(prepare)------------------------*/");
   yUNIT_minstr ("... check check arguments"          , yURG_peek (my.n_main, '�'), "   rc = yUNIT_init ();");
   yUNIT_minstr ("... check check arguments"          , yURG_peek (my.n_main, '�'), "   rc = yUNIT_args (a_argc, a_argv);");
   yUNIT_minstr ("... check error checking"           , yURG_peek (my.n_main, '�'), "   if (rc < 0)  return -1;");
   yUNIT_minstr ("... check start unit test"          , yURG_peek (my.n_main, '�'), "   yUNIT_unit (\"/tmp/koios_scrp\", cyUNIT.level, cyUNIT.eterm, cyUNIT.exec);");
   yUNIT_minstr ("... check comment"                  , yURG_peek (my.n_main, '�'), "   /*---(beg scripts)--------------------*/");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_main) , 14);
   yUNIT_mindnoc ();

   yUNIT_mincond ("write the ending");
   CODE_cycle ();
   yUNIT_minval ("call end"                           , MAIN_end    (), 0);
   yUNIT_minstr ("... check comment"                  , yURG_peek (my.n_main, '�'), "   /*---(end scripts)--------------------*/");
   yUNIT_minstr ("... check tinu"                     , yURG_peek (my.n_main, '�'), "   rc = yUNIT_tinu (cyUNIT.exec);");
   yUNIT_minstr ("... check comment"                  , yURG_peek (my.n_main, '�'), "   /*---(complete)-----------------------*/");
   yUNIT_minstr ("... check return"                   , yURG_peek (my.n_main, '�'), "   return rc;");
   yUNIT_minstr ("... check end brace"                , yURG_peek (my.n_main, '�'), "}");
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_main, '�'), "");
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_main, '�'), "");
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_main, '�'), "");
   yUNIT_minstr ("... check (8) whimper"              , yURG_peek (my.n_main, '�'), "/* end-of-file.  done, finito, completare, whimper [ϴ���                     */");
   yUNIT_minstr ("... check (9) final line"           , yURG_peek (my.n_main, '�'), "/*================================= end-code =================================*/");
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
   yUNIT_minval ("open the script file"               , SCRP_open   (my.n_scrp, &(my.f_scrp), &(my.n_line)), 0);
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
   yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "PREP � include the prototype headers �  �  �  �  �");
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
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_code, '�'), "");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) , 0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("handle an include line");
   strcpy (my.recd, "   incl  include public header  koios.h       ");
   my.n_line = 15;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "   incl � include public header � koios.h �  �  �  �");
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
   yUNIT_minstr ("... check include"                  , yURG_peek (my.n_code, '�'), "#include    \"koios.h\"               /*   15, include public header            */");
   CODE_printf ("#include    �%s�   /* %4i, %s */\n", my.meth, my.n_line, my.desc);
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) , 2);
   yUNIT_mindnoc ();

   yUNIT_mincond ("clean up after");
   yUNIT_minval ("close script"                       , SCRP_close  (&(my.f_scrp)), 0);
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
   yUNIT_minval ("open the script file"               , SCRP_open   (my.n_scrp, &(my.f_scrp), &(my.n_line)), 0);
   strcpy (my.n_code, "/tmp/koios_scrp_unit.cs");
   strcpy (my.n_main, "/tmp/koios_scrp_unit.h");
   strcpy (my.n_base, "/tmp/koios_scrp");
   yUNIT_minval ("open the script file"               , CODE_open   (), 0);
   yUNIT_minval ("... check code pointer"             , my.f_code     , my.f_code);
   yUNIT_minval ("... check main pointer"             , my.f_main     , my.f_main);
   yUNIT_mindnoc ();

   yUNIT_mincond ("first script beginning");
   strcpy (my.recd, "SCRP    [��]  (SCRP) verify openning and closing  SCRP_parse     ");
   my.n_line = 23;
   my.nscrp  =  0;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "SCRP    [��] � (SCRP) verify openning and closing � SCRP_parse �  �  �");
   yUNIT_minstr ("... check verb"                     , my.verb       , "SCRP");
   yUNIT_minstr ("... check stage"                    , my.stage      , "��");
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
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_code, '�'), "");
   yUNIT_minstr ("... check return type"              , yURG_peek (my.n_code, '�'), "char");
   yUNIT_minstr ("... check declaration"              , yURG_peek (my.n_code, '�'), "yUNIT_script_01          (void)");
   yUNIT_minstr ("... check open brace"               , yURG_peek (my.n_code, '�'), "{");
   yUNIT_minstr ("... check comment"                  , yURG_peek (my.n_code, '�'), "   /*===[[ script header ]]========================*/");
   yUNIT_minstr ("... check local"                    , yURG_peek (my.n_code, '�'), "   cyUNIT.offset  = 0;");
   yUNIT_minstr ("... check local"                    , yURG_peek (my.n_code, '�'), "   cyUNIT.origin  = 1;");
   yUNIT_minstr ("... check reset"                    , yURG_peek (my.n_code, '�'), "   yUNIT_mode_reset ();");
   yUNIT_minstr ("... check script header"            , yURG_peek (my.n_code, '�'), "   yUNIT_scrp    (  23,   1, \"��\", \"(SCRP) verify openning and closing\", \"0s\", \"tbd\", \"SCRP_parse\");");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) ,  9);
   yUNIT_minstr ("check main entry"                   , yURG_peek (my.n_main, '�'), "   if (yUNIT_run_scrp ( 1) == 1)  yUNIT_script_01 ();");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_main) ,  1);
   yUNIT_mindnoc ();

   yUNIT_mincond ("second script beginning");
   strcpy (my.recd, "SCRP    [��]  (SCRP) whatever comes next       ");
   my.n_line = 52;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "SCRP    [��] � (SCRP) whatever comes next �  �  �  �");
   yUNIT_minstr ("... check verb"                     , my.verb       , "SCRP");
   yUNIT_minstr ("... check stage"                    , my.stage      , "��");
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
   yUNIT_minstr ("... check comment"                  , yURG_peek (my.n_code, '�'), "   /*===[[ script done ]]==========================*/");
   yUNIT_minstr ("... check prcs footer"              , yURG_peek (my.n_code, '�'), "   yUNIT_prcs    (cyUNIT.exec);");
   yUNIT_minstr ("... check comment"                  , yURG_peek (my.n_code, '�'), "   /*---(complete)-----------------------*/");
   yUNIT_minstr ("... check return"                   , yURG_peek (my.n_code, '�'), "   return 0;");
   yUNIT_minstr ("... check closing brace"            , yURG_peek (my.n_code, '�'), "}");
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_code, '�'), "");
   yUNIT_minstr ("... check return type"              , yURG_peek (my.n_code, '�'), "char");
   yUNIT_minstr ("... check declaration"              , yURG_peek (my.n_code, '�'), "yUNIT_script_02          (void)");
   yUNIT_minstr ("... check open brace"               , yURG_peek (my.n_code, '�'), "{");
   yUNIT_minstr ("... check comment"                  , yURG_peek (my.n_code, '�'), "   /*===[[ script header ]]========================*/");
   yUNIT_minstr ("... check local"                    , yURG_peek (my.n_code, '�'), "   cyUNIT.offset  = 0;");
   yUNIT_minstr ("... check local"                    , yURG_peek (my.n_code, '�'), "   cyUNIT.origin  = 2;");
   yUNIT_minstr ("... check reset"                    , yURG_peek (my.n_code, '�'), "   yUNIT_mode_reset ();");
   yUNIT_minstr ("... check script header"            , yURG_peek (my.n_code, '�'), "   yUNIT_scrp    (  52,   2, \"��\", \"(SCRP) whatever comes next\", \"0s\", \"tbd\", \"\");");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) , 14);
   yUNIT_minstr ("check main entry"                   , yURG_peek (my.n_main, '�'), "   if (yUNIT_run_scrp ( 2) == 1)  yUNIT_script_02 ();");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_main) ,  1);
   yUNIT_mindnoc ();

   yUNIT_mincond ("second script beginning");
   strcpy (my.recd, "SHARED   -b-  remove temporary files       ");
   my.n_line = 300;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse the line"                     , SCRP_parse (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "SHARED   -b- � remove temporary files �  �  �  �");
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
   yUNIT_minstr ("... check comment"                  , yURG_peek (my.n_code, '�'), "   /*===[[ script done ]]==========================*/");
   yUNIT_minstr ("... check prcs footer"              , yURG_peek (my.n_code, '�'), "   yUNIT_prcs    (cyUNIT.exec);");
   yUNIT_minstr ("... check comment"                  , yURG_peek (my.n_code, '�'), "   /*---(complete)-----------------------*/");
   yUNIT_minstr ("... check return"                   , yURG_peek (my.n_code, '�'), "   return 0;");
   yUNIT_minstr ("... check closing brace"            , yURG_peek (my.n_code, '�'), "}");
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_code, '�'), "");
   yUNIT_minstr ("... check return type"              , yURG_peek (my.n_code, '�'), "char");
   yUNIT_minstr ("... check definition"               , yURG_peek (my.n_code, '�'), "yUNIT_shared_b           (void)");
   yUNIT_minstr ("... check openning brace"           , yURG_peek (my.n_code, '�'), "{");
   yUNIT_minstr ("... check comment"                  , yURG_peek (my.n_code, '�'), "   /*===[[ shared header ]]========================*/");
   yUNIT_minstr ("... check call shared"              , yURG_peek (my.n_code, '�'), "   yUNIT_share ('b', \"remove temporary files\");");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) , 11);
   yUNIT_minstr ("check main entry"                   , yURG_peek (my.n_main, '�'), "");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_main) ,  0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("script after shared");
   strcpy (my.recd, "SCRP    [��]  (SCRP) last test       ");
   my.n_line = 99;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "SCRP    [��] � (SCRP) last test �  �  �  �");
   yUNIT_minstr ("... check verb"                     , my.verb       , "SCRP");
   yUNIT_minstr ("... check stage"                    , my.stage      , "��");
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
   yUNIT_minstr ("... check comment"                  , yURG_peek (my.n_code, '�'), "   /*===[[ shared done ]]==========================*/");
   yUNIT_minstr ("... check prcs footer"              , yURG_peek (my.n_code, '�'), "   yUNIT_erahs ('b');");
   yUNIT_minstr ("... check comment"                  , yURG_peek (my.n_code, '�'), "   /*---(complete)-----------------------*/");
   yUNIT_minstr ("... check return"                   , yURG_peek (my.n_code, '�'), "   return 0;");
   yUNIT_minstr ("... check closing brace"            , yURG_peek (my.n_code, '�'), "}");
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_code, '�'), "");
   yUNIT_minstr ("... check return type"              , yURG_peek (my.n_code, '�'), "char");
   yUNIT_minstr ("... check declaration"              , yURG_peek (my.n_code, '�'), "yUNIT_script_03          (void)");
   yUNIT_minstr ("... check open brace"               , yURG_peek (my.n_code, '�'), "{");
   yUNIT_minstr ("... check comment"                  , yURG_peek (my.n_code, '�'), "   /*===[[ script header ]]========================*/");
   yUNIT_minstr ("... check local"                    , yURG_peek (my.n_code, '�'), "   cyUNIT.offset  = 0;");
   yUNIT_minstr ("... check local"                    , yURG_peek (my.n_code, '�'), "   cyUNIT.origin  = 3;");
   yUNIT_minstr ("... check reset"                    , yURG_peek (my.n_code, '�'), "   yUNIT_mode_reset ();");
   yUNIT_minstr ("... check script header"            , yURG_peek (my.n_code, '�'), "   yUNIT_scrp    (  99,   3, \"��\", \"(SCRP) last test\", \"0s\", \"tbd\", \"\");");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) , 14);
   yUNIT_minstr ("check main entry"                   , yURG_peek (my.n_main, '�'), "   if (yUNIT_run_scrp ( 3) == 1)  yUNIT_script_03 ();");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_main) ,  1);
   yUNIT_mindnoc ();

   yUNIT_mincond ("write a section break");
   strcpy (my.recd, "SECT  file oriented         ");
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse the line"                     , SCRP_parse (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "SECT � file oriented �  �  �  �  �");
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
   yUNIT_minstr ("... check comment"                  , yURG_peek (my.n_code, '�'), "   /*===[[ script done ]]==========================*/");
   yUNIT_minstr ("... check prcs footer"              , yURG_peek (my.n_code, '�'), "   yUNIT_prcs    (cyUNIT.exec);");
   yUNIT_minstr ("... check comment"                  , yURG_peek (my.n_code, '�'), "   /*---(complete)-----------------------*/");
   yUNIT_minstr ("... check return"                   , yURG_peek (my.n_code, '�'), "   return 0;");
   yUNIT_minstr ("... check closing brace"            , yURG_peek (my.n_code, '�'), "}");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) ,  5);
   yUNIT_minstr ("... check comment"                  , yURG_peek (my.n_main, '�'), "   if (cyUNIT.all  ==  1)                  yUNIT_sect      (\"file oriented\");");
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
   yUNIT_minval ("parse the line"                     , SCRP_parse (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), -999);
   yUNIT_minstr ("... check error message"            , yURG_err_last (), "/tmp/koios_scrp.unit:300:1: error: SHARED missing a valid identifier string -?-");
   strcpy (my.recd, "SHARED -b  testing        ");
   my.len = strlen (my.recd);
   my.n_line = 300;
   my.run_type = G_RUN_CREATE;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a SHARED"                     , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), -999);
   yUNIT_minstr ("... check error message"            , yURG_err_last (), "/tmp/koios_scrp.unit:300:1: error: SHARED identifier �b� not followed by - marker");
   strcpy (my.recd, "SHARED -�-  testing       ");
   my.len = strlen (my.recd);
   my.n_line = 300;
   my.run_type = G_RUN_CREATE;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a SHARED"                     , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), -999);
   yUNIT_minstr ("... check error message"            , yURG_err_last (), "/tmp/koios_scrp.unit:300:1: error: SHARED identifier ��� not valid [a-z]");
   strcpy (my.recd, "SHARE -b-  testing       ");
   my.len = strlen (my.recd);
   my.n_line = 300;
   my.run_type = G_RUN_CREATE;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a SHARED"                     , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), -999);
   yUNIT_minstr ("... check error message"            , yURG_err_last (), "/tmp/koios_scrp.unit:300:1: error: verb <SHARE> not recognized/found");
   strcpy (my.recd, "SHAREY -b-  testing       ");
   my.len = strlen (my.recd);
   my.n_line = 300;
   my.run_type = G_RUN_CREATE;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a SHARED"                     , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), -999);
   yUNIT_minstr ("... check error message"            , yURG_err_last (), "/tmp/koios_scrp.unit:300:1: error: verb <SHAREY> not recognized/found");
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify some valid variations");
   strcpy (my.recd, "SHARED   -b-  remove temporary files       ");
   my.len = strlen (my.recd);
   my.n_line = 300;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a SHARED"                     , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);
   yUNIT_minstr ("... check all marks"                , SCRP__shared_used  ()         , "--------------------------   -b------------------------   ----------");
   yUNIT_minstr ("... check verb"                     , my.verb          , "SHARED");
   strcpy (my.recd, "SHARED -y-  testing       ");
   my.len = strlen (my.recd);
   my.n_line = 300;
   my.run_type = G_RUN_CREATE;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a SHARED"                     , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);
   yUNIT_minstr ("... check all marks"                , SCRP__shared_used  ()         , "--------------------------   -b----------------------y-   ----------");
   strcpy (my.recd, "SHARED -a-  testing       ");
   my.n_line = 300;
   my.run_type = G_RUN_CREATE;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a SHARED"                     , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);
   yUNIT_minstr ("... check all marks"                , SCRP__shared_used  ()         , "--------------------------   ab----------------------y-   ----------");

   yUNIT_mincond ("attempt some bad scrp verbs");

   strcpy (my.recd, "SCRI          (SCRP) last test       ");
   my.len = strlen (my.recd);
   my.n_line = 99;
   my.run_type = G_RUN_CREATE;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), -999);
   yUNIT_minstr ("... check error message"            , yURG_err_last (), "/tmp/koios_scrp.unit:99:1: error: verb <SCRI> not recognized/found");

   strcpy (my.recd, "SCRIPT  [��]  (SCRP) last test       ");
   my.n_line = 99;
   my.run_type = G_RUN_CREATE;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), -999);
   yUNIT_minstr ("... check error message"            , yURG_err_last (), "/tmp/koios_scrp.unit:99:1: error: verb <SCRIPT> not recognized/found");

   strcpy (my.recd, "SCRP    [a�]  (SCRP) last test       ");
   my.n_line = 99;
   my.run_type = G_RUN_CREATE;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), -999);
   yUNIT_minstr ("... check error message"            , yURG_err_last (), "/tmp/koios_scrp.unit:99:9: error: SCRP identifier, wave not a subscript (������), e.g., [��]");

   strcpy (my.recd, "SCRP    [�L]  (SCRP) last test       ");
   my.n_line = 99;
   my.run_type = G_RUN_CREATE;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), -999);
   yUNIT_minstr ("... check error message"            , yURG_err_last (), "/tmp/koios_scrp.unit:99:10: error: SCRP identifier, stage not a greek letter (������������������������), e.g., [��]");

   strcpy (my.recd, "SCRP    [��)  (SCRP) last test       ");
   my.n_line = 99;
   my.run_type = G_RUN_CREATE;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), -999);
   yUNIT_minstr ("... check error message"            , yURG_err_last (), "/tmp/koios_scrp.unit:99:11: error: SCRP identifier, stage uses wrong end bracket, e.g., [��]");

   strcpy (my.recd, "SCRP    -��   (SCRP) last test       ");
   my.n_line = 99;
   my.run_type = G_RUN_CREATE;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), -999);
   yUNIT_minstr ("... check error message"            , yURG_err_last (), "/tmp/koios_scrp.unit:99:0: error: SCRP identifier, illegal chars after verb, maybe stage, e.g., [��]");
   yUNIT_mindnoc ();

   strcpy (my.n_base, "master");  /* prepare for SHARED defense testing */

   yUNIT_mincond ("global after script");
   strcpy (my.recd, "GLOBAL   -D-  common setup       ");
   my.n_line = 99;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "GLOBAL   -D- � common setup �  �  �  �");
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
   yUNIT_minstr ("... check comment"                  , yURG_peek (my.n_code, '�'), "   /*===[[ script done ]]==========================*/");
   yUNIT_minstr ("... check prcs footer"              , yURG_peek (my.n_code, '�'), "   yUNIT_prcs    (cyUNIT.exec);");
   yUNIT_minstr ("... check comment"                  , yURG_peek (my.n_code, '�'), "   /*---(complete)-----------------------*/");
   yUNIT_minstr ("... check return"                   , yURG_peek (my.n_code, '�'), "   return 0;");
   yUNIT_minstr ("... check closing brace"            , yURG_peek (my.n_code, '�'), "}");
   yUNIT_minstr ("... empty"                          , yURG_peek (my.n_code, '�'), "");
   yUNIT_minstr ("... check return type"              , yURG_peek (my.n_code, '�'), "char");
   yUNIT_minstr ("... check declaration"              , yURG_peek (my.n_code, '�'), "yUNIT_shared_D           (void)");
   yUNIT_minstr ("... check open brace"               , yURG_peek (my.n_code, '�'), "{");
   yUNIT_minstr ("... check comment"                  , yURG_peek (my.n_code, '�'), "   /*===[[ global header ]]========================*/");
   yUNIT_minstr ("... check  open shared"             , yURG_peek (my.n_code, '�'), "   yUNIT_global ('D', \"common setup\");");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) , 11);
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_main) ,  0);
   yUNIT_mindnoc ();

   strcpy (my.n_base, "koios" );  /* prepare for SHARED testing */
   my.cshare = '-';

   yUNIT_mincond ("clean up after");
   yUNIT_minval ("close script"                       , SCRP_close  (&(my.f_scrp)), 0);
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
   yUNIT_minval ("open the script file"               , SCRP_open   (my.n_scrp, &(my.f_scrp), &(my.n_line)), 0);
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
   yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "COND (6) � verify defenses �  �  �  �");
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
   yUNIT_minstr ("... check code beginning"           , yURG_peek (my.n_code, '�'), "   /*===[[ COND #001 ]]============================*/");
   yUNIT_minstr ("... check debugging"                , yURG_peek (my.n_code, '�'), "   DEBUG_PROG    yLOG_unitcond (cyUNIT.origin, cyUNIT.offset +   1,   32, \"verify defenses\");");
   yUNIT_minstr ("... check condition notice"         , yURG_peek (my.n_code, '�'), "   yUNIT_cond    (  32, cyUNIT.offset +   1, '&', \"verify defenses\");");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) ,  3);
   yUNIT_minstr ("check main entry"                   , yURG_peek (my.n_main, '�'), "");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_main) ,  0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("second condition beginning");
   strcpy (my.recd, "COND  verify null handling       ");
   my.n_line   = 34;
   my.run_type = G_RUN_CREATE;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "COND � verify null handling �  �  �  �");
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
   yUNIT_minstr ("... check final comment"            , yURG_peek (my.n_code, '�'), "      /*---(summary)---------------------*/");
   yUNIT_minstr ("... check dnoc reporting"           , yURG_peek (my.n_code, '�'), "      yUNIT_dnoc    (cyUNIT.exec);");
   yUNIT_minstr ("... check final comment"            , yURG_peek (my.n_code, '�'), "      /*---(done)------------------------*/");
   yUNIT_minstr ("... check code beginning"           , yURG_peek (my.n_code, '�'), "   /*===[[ COND #002 ]]============================*/");
   yUNIT_minstr ("... check condition notice"         , yURG_peek (my.n_code, '�'), "   yUNIT_cond    (  34, cyUNIT.offset +   2, '-', \"verify null handling\");");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) ,  5);
   yUNIT_minstr ("check main entry"                   , yURG_peek (my.n_main, '�'), "");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_main) ,  0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("condition group");
   strcpy (my.recd, "GROUP  more complex defenses       ");
   my.n_line   = 36;
   my.run_type = G_RUN_CREATE;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "GROUP � more complex defenses �  �  �  �");
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
   yUNIT_minstr ("... check final comment"            , yURG_peek (my.n_code, '�'), "      /*---(summary)---------------------*/");
   yUNIT_minstr ("... check dnoc reporting"           , yURG_peek (my.n_code, '�'), "      yUNIT_dnoc    (cyUNIT.exec);");
   yUNIT_minstr ("... check final comment"            , yURG_peek (my.n_code, '�'), "      /*---(done)------------------------*/");
   yUNIT_minstr ("... check comment"                  , yURG_peek (my.n_code, '�'), "   /*---(group)--------------------------*/");
   yUNIT_minstr ("... check group reporting"          , yURG_peek (my.n_code, '�'), "   yUNIT_group   (\"more complex defenses\");");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) ,  5);
   yUNIT_minstr ("check main entry"                   , yURG_peek (my.n_main, '�'), "");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_main) ,  0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("condition reuse");
   strcpy (my.recd, "REUSE -b-         ");
   my.n_line   = 38;
   my.run_type = G_RUN_CREATE;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "REUSE -b- �  �  �  �  �");
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
   yUNIT_minstr ("... check comment"                  , yURG_peek (my.n_code, '�'), "   /*---(shared code)-----------------------*/");
   yUNIT_minstr ("... check prepare offset"           , yURG_peek (my.n_code, '�'), "   cyUNIT.offset =   2;");
   yUNIT_minstr ("... check call share"               , yURG_peek (my.n_code, '�'), "   yUNIT_shared_b ();");
   yUNIT_minstr ("... check reset offset"             , yURG_peek (my.n_code, '�'), "   cyUNIT.offset = 0;");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) ,  4);
   yUNIT_minstr ("check main entry"                   , yURG_peek (my.n_main, '�'), "");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_main) ,  0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("attempt some bad reuse conditions");
   strcpy (my.recd, "REUSE             ");
   my.n_line   = 38;
   my.run_type = G_RUN_CREATE;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a REUSE"                      , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), -999);
   yUNIT_minstr ("... check error message"            , yURG_err_last (), "/tmp/koios_scrp.unit:38:1: error: REUSE missing a valid identifier string -?-");
   strcpy (my.recd, "REUSE -b          ");
   my.n_line   = 38;
   my.run_type = G_RUN_CREATE;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a REUSE"                      , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), -999);
   yUNIT_minstr ("... check error message"            , yURG_err_last (), "/tmp/koios_scrp.unit:38:1: error: REUSE identifier �b� not followed by - marker");
   strcpy (my.recd, "REUSE -�-         ");
   my.n_line   = 38;
   my.run_type = G_RUN_CREATE;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a REUSE"                      , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), -999);
   yUNIT_minstr ("... check error message"            , yURG_err_last (), "/tmp/koios_scrp.unit:38:1: error: REUSE identifier ��� not valid [a-zA-Z]");
   strcpy (my.recd, "REUSED -b-         ");
   my.n_line   = 38;
   my.run_type = G_RUN_CREATE;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a REUSE"                      , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), -999);
   yUNIT_minstr ("... check error message"            , yURG_err_last (), "/tmp/koios_scrp.unit:38:1: error: verb <REUSED> not recognized/found");
   strcpy (my.recd, "REUS   -b-         ");
   my.n_line   = 38;
   my.run_type = G_RUN_CREATE;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a REUSE"                      , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), -999);
   yUNIT_minstr ("... check error message"            , yURG_err_last (), "/tmp/koios_scrp.unit:38:1: error: verb <REUS> not recognized/found");
   yUNIT_mindnoc ();

   yUNIT_mincond ("clean up after");
   yUNIT_minval ("close script"                       , SCRP_close  (&(my.f_scrp)), 0);
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
   yUNIT_minval ("open the script file"               , SCRP_open   (my.n_scrp, &(my.f_scrp), &(my.n_line)), 0);
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
   yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "mode � FORCED_FAIL �  �  �  �");
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
   yUNIT_minstr ("... check code beginning"           , yURG_peek (my.n_code, '�'), "      /*---(mode)------------------------*/");
   yUNIT_minstr ("... check set mode"                 , yURG_peek (my.n_code, '�'), "      yUNIT_mode    (  40,   3, \"FORCED_FAIL\", cyUNIT.exec);");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) ,  2);
   yUNIT_minstr ("check main entry"                   , yURG_peek (my.n_main, '�'), "");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_main) ,  0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("code step");
   strcpy (my.recd, "local  working variables    int a = 37;  ");
   my.n_line   = 40;
   my.cstep    =  2;
   my.run_type = G_RUN_DEBUG;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "local � working variables �  � int a = 37;  �");
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
   yUNIT_minstr ("... check code beginning"           , yURG_peek (my.n_code, '�'), "      /*---(setup local)-----------------*/");
   yUNIT_minstr ("... check show command"             , yURG_peek (my.n_code, '�'), "      int a = 37;");
   yUNIT_minstr ("... check execute code"             , yURG_peek (my.n_code, '�'), "      yUNIT_local   (  40,   3, \"working variables\", \"int a = 37;\", cyUNIT.exec);");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) ,  3);
   yUNIT_minstr ("check main entry"                   , yURG_peek (my.n_main, '�'), "");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_main) ,  0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("load step");
   strcpy (my.recd, "load  fill out screen  stdin  hello;  15.6 ");
   my.n_line   = 40;
   my.cstep    =  2;
   my.run_type = G_RUN_DEBUG;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "load � fill out screen � stdin � hello;  15.6 �");
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
   yUNIT_minstr ("... check code beginning"           , yURG_peek (my.n_code, '�'), "      /*---(load input)------------------*/");
   yUNIT_minstr ("... check report and execute"       , yURG_peek (my.n_code, '�'), "      yUNIT_load    (  40,   3, \"fill out screen\", \"stdin\", \"hello;  15.6\", cyUNIT.exec);");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) ,  2);
   yUNIT_minstr ("check main entry"                   , yURG_peek (my.n_main, '�'), "");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_main) ,  0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("system step");
   strcpy (my.recd, "system  delete temporary file    rm -f /tmp/koios_unit.cs ");
   my.n_line   = 40;
   my.cstep    =  2;
   my.run_type = G_RUN_DEBUG;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "system � delete temporary file �  � rm -f /tmp/koios_unit.cs �");
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
   yUNIT_minstr ("... check code beginning"           , yURG_peek (my.n_code, '�'), "      /*---(system/execute)--------------*/");
   yUNIT_minstr ("... check execute and report"       , yURG_peek (my.n_code, '�'), "      yUNIT_system  (  40,   3, \"delete temporary file\", \"rm -f /tmp/koios_unit.cs\", \"rm -f /tmp/koios_unit.cs\", cyUNIT.exec);");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) ,  2);
   yUNIT_minstr ("check main entry"                   , yURG_peek (my.n_main, '�'), "");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_main) ,  0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("echo step (real)");
   strcpy (my.recd, "echo  check length    l  r_equal  13.6 ");
   my.n_line   = 40;
   my.cstep    =  2;
   my.run_type = G_RUN_DEBUG;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "echo � check length �  � l � r_equal � 13.6 �");
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
   yUNIT_minstr ("... check code beginning"           , yURG_peek (my.n_code, '�'), "      /*---(echo/verify)-----------------*/");
   yUNIT_minstr ("... check report"                   , yURG_peek (my.n_code, '�'), "      yUNIT_real    (  40,   3, \"check length\", \"echo\", \"l\", \"r_equal\", 13.6, l  , cyUNIT.exec);");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) ,  2);
   yUNIT_minstr ("check main entry"                   , yURG_peek (my.n_main, '�'), "");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_main) ,  0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("echo step (int)");
   strcpy (my.recd, "echo  check length    l  i_lesser  13.6 ");
   my.n_line   = 40;
   my.cstep    =  2;
   my.run_type = G_RUN_DEBUG;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "echo � check length �  � l � i_lesser � 13.6 �");
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
   yUNIT_minstr ("... check code beginning"           , yURG_peek (my.n_code, '�'), "      /*---(echo/verify)-----------------*/");
   yUNIT_minstr ("... check execute and report"       , yURG_peek (my.n_code, '�'), "      yUNIT_int     (  40,   3, \"check length\", \"echo\", \"l\", \"i_lesser\", 13.6, l  , cyUNIT.exec);");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) ,  2);
   yUNIT_minstr ("check main entry"                   , yURG_peek (my.n_main, '�'), "");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_main) ,  0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("echo step (string)");
   strcpy (my.recd, "echo  check length    l  s_not  13.6 ");
   my.n_line   = 40;
   my.cstep    =  2;
   my.run_type = G_RUN_DEBUG;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "echo � check length �  � l � s_not � 13.6 �");
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
   yUNIT_minstr ("... check code beginning"           , yURG_peek (my.n_code, '�'), "      /*---(echo/verify)-----------------*/");
   yUNIT_minstr ("... check execute and report"       , yURG_peek (my.n_code, '�'), "      yUNIT_string  (  40,   3, \"check length\", \"echo\", \"l\", \"s_not\", \"13.6\", l  , cyUNIT.exec);");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) ,  2);
   yUNIT_minstr ("check main entry"                   , yURG_peek (my.n_main, '�'), "");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_main) ,  0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("echo step (pointer)");
   strcpy (my.recd, "echo  check length    l  p_null  13.6 ");
   my.n_line   = 40;
   my.cstep    =  2;
   my.run_type = G_RUN_DEBUG;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "echo � check length �  � l � p_null � 13.6 �");
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
   yUNIT_minstr ("... check code beginning"           , yURG_peek (my.n_code, '�'), "      /*---(echo/verify)-----------------*/");
   yUNIT_minstr ("... check execute and report"       , yURG_peek (my.n_code, '�'), "      yUNIT_point   (  40,   3, \"check length\", \"echo\", \"l\", \"p_null\", 13.6, l  , cyUNIT.exec);");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) ,  2);
   yUNIT_minstr ("check main entry"                   , yURG_peek (my.n_main, '�'), "");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_main) ,  0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("echo step (round)");
   strcpy (my.recd, "echo  check length    l  u_round/3  13.6 ");
   my.n_line   = 40;
   my.cstep    =  2;
   my.run_type = G_RUN_DEBUG;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "echo � check length �  � l � u_round/3 � 13.6 �");
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
   yUNIT_minstr ("... check code beginning"           , yURG_peek (my.n_code, '�'), "      /*---(echo/verify)-----------------*/");
   yUNIT_minstr ("... check execute and report"       , yURG_peek (my.n_code, '�'), "      yUNIT_round   (  40,   3, \"check length\", \"echo\", \"l\", \"u_round/3\", \"13.6\", l  , cyUNIT.exec);");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) ,  2);
   yUNIT_minstr ("check main entry"                   , yURG_peek (my.n_main, '�'), "");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_main) ,  0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("exec step");
   strcpy (my.recd, "exec  check length  test_func  27, 36  s_equal  13.6 ");
   my.n_line   = 40;
   my.cstep    =  2;
   my.run_type = G_RUN_DEBUG;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "exec � check length � test_func � 27, 36 � s_equal � 13.6 �");
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
   yUNIT_minstr ("... check code beginning"           , yURG_peek (my.n_code, '�'), "      /*---(run step)--------------------*/");
   yUNIT_minstr ("... check debugging"                , yURG_peek (my.n_code, '�'), "      DEBUG_PROG    yLOG_unitstep (cyUNIT.origin, cyUNIT.offset +   2,   3,   40, \"check length\");");
   yUNIT_minstr ("... check reset rcs"                , yURG_peek (my.n_code, '�'), "      yUNIT_reset_rc ();");
   yUNIT_minstr ("... check execute"                  , yURG_peek (my.n_code, '�'), "      if (cyUNIT.exec)  cyUNIT.s_rc = test_func (27, 36);");
   yUNIT_minstr ("... check report"                   , yURG_peek (my.n_code, '�'), "      yUNIT_string  (  40,   3, \"check length\", \"test_func\", \"27, 36\", \"s_equal\", \"13.6\", cyUNIT.s_rc, cyUNIT.exec);");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) ,  5);
   yUNIT_minstr ("check main entry"                   , yURG_peek (my.n_main, '�'), "");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_main) ,  0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("get step");
   strcpy (my.recd, "get  ... verify length  test_unit  27, 36  i_equal  13.6 ");
   my.n_line   = 40;
   my.cstep    =  2;
   my.run_type = G_RUN_DEBUG;
   yUNIT_minval ("clear the fields"                   , SCRP_clear (), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "get � ... verify length � test_unit � 27, 36 � i_equal � 13.6 �");
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
   yUNIT_minstr ("... check code beginning"           , yURG_peek (my.n_code, '�'), "      /*---(run step)--------------------*/");
   yUNIT_minstr ("... check debugging"                , yURG_peek (my.n_code, '�'), "      DEBUG_PROG    yLOG_unitstep (cyUNIT.origin, cyUNIT.offset +   2,   3,   40, \"... verify length\");");
   yUNIT_minstr ("... check reset"                    , yURG_peek (my.n_code, '�'), "      yUNIT_reset_rc ();");
   yUNIT_minstr ("... check execute"                  , yURG_peek (my.n_code, '�'), "      if (cyUNIT.exec)  cyUNIT.i_rc = test_unit (27, 36);");
   yUNIT_minstr ("... check results"                  , yURG_peek (my.n_code, '�'), "      yUNIT_int     (  40,   3, \"... verify length\", \"test_unit\", \"27, 36\", \"i_equal\", 13.6, cyUNIT.i_rc, cyUNIT.exec);");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) ,  5);
   yUNIT_minstr ("check main entry"                   , yURG_peek (my.n_main, '�'), "");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_main) ,  0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("clean up after");
   yUNIT_minval ("close script"                       , SCRP_close  (&(my.f_scrp)), 0);
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
   system ("echo \"GLOBAL   -D-  globally shared steps                0s  tbd        \"                                                                                   >> master.unit");
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
   system ("echo \"SCRP    [��]  (SCRP) verify openning and closing   0s  tbd        \"                                                                                   >> koios.unit");
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
   system ("echo \"SHARED   -a-  prepare files for use                0s  tbd         \"                                                                                                       >> koios.unit");
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
   system ("echo \"SHARED   -b-  remove files after use               0s  tbd         \"                                                                                                       >> koios.unit");
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
   system ("echo \"SCRP    [��]  (SCRP) verify system startup          0s  tbd                          \"                                                                                   >> koios.unit");
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
   system ("echo \"SCRP    [��]  (SCRP) verify normal processing       0s  tbd                          \"                                                                                   >> koios.unit");
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
   system ("echo \"SCRP    [��]  (SCRP) empty script                   0s  tbd                          \"                                                                                   >> koios.unit");
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
   yUNIT_minstr  ("... check unit header"              , yURG_peek (x_urun, '�'), "yUNIT - heatherly unit testing framework ---------------------------------------(beg)");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check section"                  , yURG_peek (x_urun, '�'), "SECT ===-------------------------- simple testing ---------------------------=== TCES");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check script"                   , yURG_peek (x_urun, '�'), "SCRP [01] (SCRP) verify openning and closing ============================[��]=[00006]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check section"                  , yURG_peek (x_urun, '�'), "SECT ===----------------------- more complex testing ------------------------=== TCES");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check script"                   , yURG_peek (x_urun, '�'), "SCRP [02] (SCRP) verify system startup ==================================[��]=[00050]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check script"                   , yURG_peek (x_urun, '�'), "SCRP [03] (SCRP) verify normal processing ===============================[��]=[00074]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check script"                   , yURG_peek (x_urun, '�'), "SCRP [04] (SCRP) empty script ===========================================[��]=[00094]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check unit footer"              , yURG_peek (x_urun, '�'), "TINU  scrp=4    cond=21    test=90    [ ------------------------------------------- ]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check unit footer"              , yURG_peek (x_urun, '�'), "yUNIT - heatherly unit testing framework ---------------------------------------(end)");
   yUNIT_minval  ("... check line count"               , yURG_peek_count (x_urun) , 17);
   yUNIT_minstr  ("check wave entry"                   , yURG_peek (x_wave, '�'), "�  �  koios                       1  (SCRP) verify openning and closing                                ");
   yUNIT_minstr  ("check wave entry"                   , yURG_peek (x_wave, '�'), "�  �  koios                       2  (SCRP) verify system startup                                      ");
   yUNIT_minstr  ("check wave entry"                   , yURG_peek (x_wave, '�'), "�  �  koios                       3  (SCRP) verify normal processing                                   ");
   yUNIT_minstr  ("check wave entry"                   , yURG_peek (x_wave, '�'), "�  �  koios                       4  (SCRP) empty script                                               ");
   yUNIT_minval  ("... check line count"               , yURG_peek_count (x_wave) ,  4);
   yUNIT_mindnoc ();

   yUNIT_mincond ("check inventory of one script only");
   yUNIT_minval  ("... run unit test"                  , system ("./koios_unit --scrps 03"), 0);
   yUNIT_minstr  ("... check unit header"              , yURG_peek (x_urun, '�'), "yUNIT - heatherly unit testing framework ---------------------------------------(beg)");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check script"                   , yURG_peek (x_urun, '�'), "SCRP [03] (SCRP) verify normal processing ===============================[��]=[00074]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check unit footer"              , yURG_peek (x_urun, '�'), "TINU  scrp=1    cond=11    test=40    [ ------------------------------------------- ]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check unit footer"              , yURG_peek (x_urun, '�'), "yUNIT - heatherly unit testing framework ---------------------------------------(end)");
   yUNIT_minval  ("... check line count"               , yURG_peek_count (x_urun) ,  7);
   yUNIT_mindnoc ();

   yUNIT_mincond ("check running and presenting scripts only");
   yUNIT_minval  ("... run unit test"                  , system ("./koios_unit --scrp"), 999);
   yUNIT_minstr  ("... check unit header"              , yURG_peek (x_urun, '�'), "yUNIT - heatherly unit testing framework ---------------------------------------(beg)");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check section"                  , yURG_peek (x_urun, '�'), "SECT ===-------------------------- simple testing ---------------------------=== TCES");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check script"                   , yURG_peek (x_urun, '�'), "SCRP [01] (SCRP) verify openning and closing ============================[��]=[00006]");
   yUNIT_minstr  ("... check script footer"            , yURG_peek (x_urun, '�'), "  " BACK_RED "PRCS -------- cond=6     test=22    [ pass=15    fail=1     badd=0     void=6     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check section"                  , yURG_peek (x_urun, '�'), "SECT ===----------------------- more complex testing ------------------------=== TCES");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check script"                   , yURG_peek (x_urun, '�'), "SCRP [02] (SCRP) verify system startup ==================================[��]=[00050]");
   yUNIT_minstr  ("... check script footer"            , yURG_peek (x_urun, '�'), "  " BACK_RED "PRCS -------- cond=4     test=28    [ pass=16    fail=5     badd=0     void=7     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check script"                   , yURG_peek (x_urun, '�'), "SCRP [03] (SCRP) verify normal processing ===============================[��]=[00074]");
   yUNIT_minstr  ("... check script footer"            , yURG_peek (x_urun, '�'), "  " BACK_RED "PRCS -------- cond=11    test=40    [ pass=30    fail=8     badd=0     void=2     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check script"                   , yURG_peek (x_urun, '�'), "SCRP [04] (SCRP) empty script ===========================================[��]=[00094]");
   yUNIT_minstr  ("... check script footer"            , yURG_peek (x_urun, '�'), "  " BACK_YEL "PRCS -------- cond=0     test=0     [ pass=0     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check unit footer"              , yURG_peek (x_urun, '�'), BACK_RED "TINU  scrp=4    cond=21    test=90    [ pass=61    fail=14    badd=0     void=15    ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check unit footer"              , yURG_peek (x_urun, '�'), "yUNIT - heatherly unit testing framework ---------------------------------------(end)");
   yUNIT_minval  ("... check line count"               , yURG_peek_count (x_urun) , 21);
   yUNIT_mindnoc ();

   yUNIT_mincond ("check running and presenting only one script");
   yUNIT_minval  ("... run unit test"                  , system ("./koios_unit --scrp 02"),  999);
   yUNIT_minstr  ("... check unit header"              , yURG_peek (x_urun, '�'), "yUNIT - heatherly unit testing framework ---------------------------------------(beg)");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check script"                   , yURG_peek (x_urun, '�'), "SCRP [02] (SCRP) verify system startup ==================================[��]=[00050]");
   yUNIT_minstr  ("... check script footer"            , yURG_peek (x_urun, '�'), "  " BACK_RED "PRCS -------- cond=4     test=28    [ pass=16    fail=5     badd=0     void=7     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check unit footer"              , yURG_peek (x_urun, '�'), BACK_RED "TINU  scrp=1    cond=4     test=28    [ pass=16    fail=5     badd=0     void=7     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check unit footer"              , yURG_peek (x_urun, '�'), "yUNIT - heatherly unit testing framework ---------------------------------------(end)");
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
   yUNIT_minstr  ("... check unit header"              , yURG_peek (x_urun, '�'), "yUNIT - heatherly unit testing framework ---------------------------------------(beg)");
   yUNIT_minstr  ("... ... patron"                     , yURG_peek (x_urun, '�'), "   patron : daktyloi-aeonius (forefinger) automated unit testing                   4s");
   yUNIT_minstr  ("... ... level"                      , yURG_peek (x_urun, '�'), "   assign output level to (3) YUNIT_COND                                          21c");
   yUNIT_minstr  ("... ... eterm"                      , yURG_peek (x_urun, '�'), "   assign format/color to (y) ETERM                                               90x");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check section");
   yUNIT_minstr  ("... check section"                  , yURG_peek (x_urun, '�'), "=========================------------------------------------========================");
   yUNIT_minstr  ("... check section"                  , yURG_peek (x_urun, '�'), "SECT ===-------------------------- simple testing ---------------------------=== TCES");
   yUNIT_minstr  ("... check section"                  , yURG_peek (x_urun, '�'), "=========================------------------------------------========================");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check script one");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check script"                   , yURG_peek (x_urun, '�'), "SCRP [01] (SCRP) verify openning and closing ============================[��]=[00006]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '�'), "  COND [001] simple openning -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00007]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '�'), "  " BACK_CYN "CCND [002] (1)" BACK_OFF " defensive checks - -- -- -- -- -- -- -- -- -- -- -- -- -- -- [00012]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '�'), "  " BACK_CYN "DOND [003] (1) defensive checks - -- -- -- -- -- -- -- -- -- -- -- -- -- -- [00017]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '�'), "  COND [004] small condition -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00018]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '�'), "  " BACK_CYN "DOND [005] (1) defensive checks - -- -- -- -- -- -- -- -- -- -- -- -- -- -- [00020]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '�'), "  COND [006] duplicate opens and closes  -- -- -- -- -- -- -- -- -- -- -- -- -[00021]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check script footer"            , yURG_peek (x_urun, '�'), "  PRCS -------- cond=6     test=22    [ ------------------------------------------- ]");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check section");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check section"                  , yURG_peek (x_urun, '�'), "=========================------------------------------------========================");
   yUNIT_minstr  ("... check section"                  , yURG_peek (x_urun, '�'), "SECT ===----------------------- more complex testing ------------------------=== TCES");
   yUNIT_minstr  ("... check section"                  , yURG_peek (x_urun, '�'), "=========================------------------------------------========================");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check script two");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check script"                   , yURG_peek (x_urun, '�'), "SCRP [02] (SCRP) verify system startup ==================================[��]=[00050]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '�'), "  COND [001] run initialization -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00051]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '�'), "  " BACK_MAG "SOND [002]" BACK_OFF " script input file  -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00029]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '�'), "  " BACK_MAG "SOND [003]" BACK_OFF " code output file - -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00034]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '�'), "  COND [004] parse a code record - -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00057]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check script footer"            , yURG_peek (x_urun, '�'), "  PRCS -------- cond=4     test=28    [ ------------------------------------------- ]");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check script three");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check script"                   , yURG_peek (x_urun, '�'), "SCRP [03] (SCRP) verify normal processing ===============================[��]=[00074]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check group"                    , yURG_peek (x_urun, '�'), "  GROUP ===----------------------------   round one   ----------------------------===");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '�'), "  " BACK_CYN "CCND [001] (1)" BACK_OFF " process arguments  -- -- -- -- -- -- -- -- -- -- -- -- -- -- [00076]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '�'), "  " BACK_MAG "SOND [002]" BACK_OFF " script input file  -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00029]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '�'), "  " BACK_MAG "SOND [003]" BACK_OFF " code output file - -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00034]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '�'), "  " BACK_CYN "CCND [004] (2)" BACK_OFF " read one record -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- [00082]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check group"                    , yURG_peek (x_urun, '�'), "  GROUP ===----------------------------   round two   ----------------------------===");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '�'), "  " BACK_CYN "DOND [005] (1) process arguments  -- -- -- -- -- -- -- -- -- -- -- -- -- -- [00088]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '�'), "  " BACK_MAG "SOND [006]" BACK_OFF " code output file - -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00040]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '�'), "  " BACK_MAG "SOND [007]" BACK_OFF " close and delete code file  -- -- -- -- -- -- -- -- -- -- -- -- -[00045]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check group"                    , yURG_peek (x_urun, '�'), "  GROUP ===---------------------------   final round   ---------------------------===");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '�'), "  " BACK_CYN "DOND [008] (2) read one record -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- [00091]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check (70) global cond"         , yURG_peek (x_urun, '�'), "  " BACK_BLU "GOND [009]" BACK_OFF " prepare variables  -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00007]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check (72) global cond"         , yURG_peek (x_urun, '�'), "  " BACK_BLU "GOND [010]" BACK_OFF " generate a summary -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00009]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '�'), "  " BACK_CYN "DOND [011] (1) process arguments  -- -- -- -- -- -- -- -- -- -- -- -- -- -- [00093]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check script footer"            , yURG_peek (x_urun, '�'), "  PRCS -------- cond=11    test=40    [ ------------------------------------------- ]");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check script four");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check script"                   , yURG_peek (x_urun, '�'), "SCRP [04] (SCRP) empty script ===========================================[��]=[00094]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check script footer"            , yURG_peek (x_urun, '�'), "  PRCS -------- cond=0     test=0     [ ------------------------------------------- ]");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check footer");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check unit footer"              , yURG_peek (x_urun, '�'), "TINU  scrp=4    cond=21    test=90    [ ------------------------------------------- ]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check unit footer"              , yURG_peek (x_urun, '�'), "yUNIT - heatherly unit testing framework ---------------------------------------(end)");
   yUNIT_minval  ("... check line count"               , yURG_peek_count (x_urun) , 87);
   yUNIT_mindnoc ();

   yUNIT_mincond ("check displaying conditions for one script");
   yUNIT_minval  ("... run unit test"                  , system ("./koios_unit --conds 02"), 0);
   yUNIT_minstr  ("... check unit header"              , yURG_peek (x_urun, '�'), "yUNIT - heatherly unit testing framework ---------------------------------------(beg)");
   yUNIT_minstr  ("... ... patron"                     , yURG_peek (x_urun, '�'), "   patron : daktyloi-aeonius (forefinger) automated unit testing                   4s");
   yUNIT_minstr  ("... ... level"                      , yURG_peek (x_urun, '�'), "   assign output level to (3) YUNIT_COND                                          21c");
   yUNIT_minstr  ("... ... eterm"                      , yURG_peek (x_urun, '�'), "   assign format/color to (y) ETERM                                               90x");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check script"                   , yURG_peek (x_urun, '�'), "SCRP [02] (SCRP) verify system startup ==================================[��]=[00050]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '�'), "  COND [001] run initialization -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00051]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '�'), "  " BACK_MAG "SOND [002]" BACK_OFF " script input file  -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00029]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '�'), "  " BACK_MAG "SOND [003]" BACK_OFF " code output file - -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00034]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '�'), "  COND [004] parse a code record - -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00057]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check script footer"            , yURG_peek (x_urun, '�'), "  PRCS -------- cond=4     test=28    [ ------------------------------------------- ]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check unit footer"              , yURG_peek (x_urun, '�'), "TINU  scrp=1    cond=4     test=28    [ ------------------------------------------- ]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check unit footer"              , yURG_peek (x_urun, '�'), "yUNIT - heatherly unit testing framework ---------------------------------------(end)");
   yUNIT_minval  ("... check line count"               , yURG_peek_count (x_urun) , 22);
   yUNIT_mindnoc ();

   yUNIT_mincond ("check executing and presenting only conditions");
   yUNIT_minval  ("... run unit test"                  , system ("./koios_unit --cond"), 999);
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify header");
   yUNIT_minstr  ("... check unit header"              , yURG_peek (x_urun, '�'), "yUNIT - heatherly unit testing framework ---------------------------------------(beg)");
   yUNIT_minstr  ("... ... patron"                     , yURG_peek (x_urun, '�'), "   patron : daktyloi-aeonius (forefinger) automated unit testing                   4s");
   yUNIT_minstr  ("... ... level"                      , yURG_peek (x_urun, '�'), "   assign output level to (3) YUNIT_COND                                          21c");
   yUNIT_minstr  ("... ... eterm"                      , yURG_peek (x_urun, '�'), "   assign format/color to (y) ETERM                                               90x");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check section"                  , yURG_peek (x_urun, '�'), "=========================------------------------------------========================");
   yUNIT_minstr  ("... check section"                  , yURG_peek (x_urun, '�'), "SECT ===-------------------------- simple testing ---------------------------=== TCES");
   yUNIT_minstr  ("... check section"                  , yURG_peek (x_urun, '�'), "=========================------------------------------------========================");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify first script");
   yUNIT_minstr  ("... check script"                   , yURG_peek (x_urun, '�'), "SCRP [01] (SCRP) verify openning and closing ============================[��]=[00006]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '�'), "  COND [001] simple openning -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00007]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, '�'), "      " BACK_GRN "DNOC --------------- test=4     [ pass=4     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '�'), "  " BACK_CYN "CCND [002] (1)" BACK_OFF " defensive checks - -- -- -- -- -- -- -- -- -- -- -- -- -- -- [00012]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, '�'), "      " BACK_GRN "DNOC --------------- test=4     [ pass=3     fail=0     badd=0     void=1     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '�'), "  " BACK_CYN "DOND [003] (1) defensive checks - -- -- -- -- -- -- -- -- -- -- -- -- -- -- [00017]" BACK_OFF);
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, '�'), "      " BACK_GRN "DNOC --------------- test=4     [ pass=3     fail=0     badd=0     void=1     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '�'), "  COND [004] small condition -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00018]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, '�'), "      " BACK_GRN "DNOC --------------- test=1     [ pass=1     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '�'), "  " BACK_CYN "DOND [005] (1) defensive checks - -- -- -- -- -- -- -- -- -- -- -- -- -- -- [00020]" BACK_OFF);
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, '�'), "      " BACK_GRN "DNOC --------------- test=4     [ pass=3     fail=0     badd=0     void=1     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '�'), "  COND [006] duplicate opens and closes  -- -- -- -- -- -- -- -- -- -- -- -- -[00021]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, '�'), "      " BACK_RED "DNOC --------------- test=5     [ pass=1     fail=1     badd=0     void=3     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check script footer"            , yURG_peek (x_urun, '�'), "  " BACK_RED "PRCS -------- cond=6     test=22    [ pass=15    fail=1     badd=0     void=6     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check section"                  , yURG_peek (x_urun, '�'), "=========================------------------------------------========================");
   yUNIT_minstr  ("... check section"                  , yURG_peek (x_urun, '�'), "SECT ===----------------------- more complex testing ------------------------=== TCES");
   yUNIT_minstr  ("... check section"                  , yURG_peek (x_urun, '�'), "=========================------------------------------------========================");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify second script");
   yUNIT_minstr  ("... check script"                   , yURG_peek (x_urun, '�'), "SCRP [02] (SCRP) verify system startup ==================================[��]=[00050]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '�'), "  COND [001] run initialization -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00051]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, '�'), "      " BACK_RED "DNOC --------------- test=4     [ pass=1     fail=2     badd=0     void=1     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '�'), "  " BACK_MAG "SOND [002]" BACK_OFF " script input file  -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00029]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, '�'), "      " BACK_RED "DNOC --------------- test=4     [ pass=0     fail=3     badd=0     void=1     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '�'), "  " BACK_MAG "SOND [003]" BACK_OFF " code output file - -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00034]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, '�'), "      " BACK_GRN "DNOC --------------- test=4     [ pass=4     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '�'), "  COND [004] parse a code record - -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00057]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, '�'), "      " BACK_GRN "DNOC --------------- test=16    [ pass=11    fail=0     badd=0     void=5     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check script footer"            , yURG_peek (x_urun, '�'), "  " BACK_RED "PRCS -------- cond=4     test=28    [ pass=16    fail=5     badd=0     void=7     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify third script");
   yUNIT_minstr  ("... check script"                   , yURG_peek (x_urun, '�'), "SCRP [03] (SCRP) verify normal processing ===============================[��]=[00074]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check group"                    , yURG_peek (x_urun, '�'), "  GROUP ===----------------------------   round one   ----------------------------===");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '�'), "  " BACK_CYN "CCND [001] (1)" BACK_OFF " process arguments  -- -- -- -- -- -- -- -- -- -- -- -- -- -- [00076]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, '�'), "      " BACK_GRN "DNOC --------------- test=4     [ pass=4     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '�'), "  " BACK_MAG "SOND [002]" BACK_OFF " script input file  -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00029]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, '�'), "      " BACK_GRN "DNOC --------------- test=4     [ pass=3     fail=0     badd=0     void=1     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '�'), "  " BACK_MAG "SOND [003]" BACK_OFF " code output file - -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00034]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, '�'), "      " BACK_GRN "DNOC --------------- test=4     [ pass=4     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '�'), "  " BACK_CYN "CCND [004] (2)" BACK_OFF " read one record -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- [00082]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, '�'), "      " BACK_RED "DNOC --------------- test=4     [ pass=0     fail=4     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check group"                    , yURG_peek (x_urun, '�'), "  GROUP ===----------------------------   round two   ----------------------------===");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '�'), "  " BACK_CYN "DOND [005] (1) process arguments  -- -- -- -- -- -- -- -- -- -- -- -- -- -- [00088]" BACK_OFF);
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, '�'), "      " BACK_GRN "DNOC --------------- test=4     [ pass=4     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '�'), "  " BACK_MAG "SOND [006]" BACK_OFF " code output file - -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00040]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, '�'), "      " BACK_GRN "DNOC --------------- test=4     [ pass=4     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '�'), "  " BACK_MAG "SOND [007]" BACK_OFF " close and delete code file  -- -- -- -- -- -- -- -- -- -- -- -- -[00045]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, '�'), "      " BACK_GRN "DNOC --------------- test=4     [ pass=4     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check group"                    , yURG_peek (x_urun, '�'), "  GROUP ===---------------------------   final round   ---------------------------===");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '�'), "  " BACK_CYN "DOND [008] (2) read one record -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- [00091]" BACK_OFF);
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, '�'), "      " BACK_RED "DNOC --------------- test=4     [ pass=0     fail=4     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check global condition"         , yURG_peek (x_urun, '�'), "  " BACK_BLU "GOND [009]" BACK_OFF " prepare variables  -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00007]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, '�'), "      " BACK_GRN "DNOC --------------- test=1     [ pass=0     fail=0     badd=0     void=1     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check global condition"         , yURG_peek (x_urun, '�'), "  " BACK_BLU "GOND [010]" BACK_OFF " generate a summary -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00009]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, '�'), "      " BACK_GRN "DNOC --------------- test=3     [ pass=3     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '�'), "  " BACK_CYN "DOND [011] (1) process arguments  -- -- -- -- -- -- -- -- -- -- -- -- -- -- [00093]" BACK_OFF);
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, '�'), "      " BACK_GRN "DNOC --------------- test=4     [ pass=4     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check script footer"            , yURG_peek (x_urun, '�'), "  " BACK_RED "PRCS -------- cond=11    test=40    [ pass=30    fail=8     badd=0     void=2     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify fourth script and footer");
   yUNIT_minstr  ("... check script"                   , yURG_peek (x_urun, '�'), "SCRP [04] (SCRP) empty script ===========================================[��]=[00094]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check script footer"            , yURG_peek (x_urun, '�'), "  " BACK_YEL "PRCS -------- cond=0     test=0     [ pass=0     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check unit footer"              , yURG_peek (x_urun, '�'), BACK_RED "TINU  scrp=4    cond=21    test=90    [ pass=61    fail=14    badd=0     void=15    ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check unit footer"              , yURG_peek (x_urun, '�'), "yUNIT - heatherly unit testing framework ---------------------------------------(end)");
   yUNIT_minval  ("... check line count"               , yURG_peek_count (x_urun) , 108);
   yUNIT_mindnoc ();

   yUNIT_mincond ("check executing and presenting but show only one script");
   yUNIT_minval  ("... run unit test"                  , system ("./koios_unit --cond 03"), 999);
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify header");
   yUNIT_minstr  ("... check unit header"              , yURG_peek (x_urun, '�'), "yUNIT - heatherly unit testing framework ---------------------------------------(beg)");
   yUNIT_minstr  ("... ... patron"                     , yURG_peek (x_urun, '�'), "   patron : daktyloi-aeonius (forefinger) automated unit testing                   4s");
   yUNIT_minstr  ("... ... level"                      , yURG_peek (x_urun, '�'), "   assign output level to (3) YUNIT_COND                                          21c");
   yUNIT_minstr  ("... ... eterm"                      , yURG_peek (x_urun, '�'), "   assign format/color to (y) ETERM                                               90x");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify third script");
   yUNIT_minstr  ("... check script"                   , yURG_peek (x_urun, '�'), "SCRP [03] (SCRP) verify normal processing ===============================[��]=[00074]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check group"                    , yURG_peek (x_urun, '�'), "  GROUP ===----------------------------   round one   ----------------------------===");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '�'), "  " BACK_CYN "CCND [001] (1)" BACK_OFF " process arguments  -- -- -- -- -- -- -- -- -- -- -- -- -- -- [00076]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, '�'), "      " BACK_GRN "DNOC --------------- test=4     [ pass=4     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '�'), "  " BACK_MAG "SOND [002]" BACK_OFF " script input file  -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00029]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, '�'), "      " BACK_GRN "DNOC --------------- test=4     [ pass=3     fail=0     badd=0     void=1     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '�'), "  " BACK_MAG "SOND [003]" BACK_OFF " code output file - -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00034]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, '�'), "      " BACK_GRN "DNOC --------------- test=4     [ pass=4     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '�'), "  " BACK_CYN "CCND [004] (2)" BACK_OFF " read one record -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- [00082]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, '�'), "      " BACK_RED "DNOC --------------- test=4     [ pass=0     fail=4     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check group"                    , yURG_peek (x_urun, '�'), "  GROUP ===----------------------------   round two   ----------------------------===");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '�'), "  " BACK_CYN "DOND [005] (1) process arguments  -- -- -- -- -- -- -- -- -- -- -- -- -- -- [00088]" BACK_OFF);
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, '�'), "      " BACK_GRN "DNOC --------------- test=4     [ pass=4     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '�'), "  " BACK_MAG "SOND [006]" BACK_OFF " code output file - -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00040]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, '�'), "      " BACK_GRN "DNOC --------------- test=4     [ pass=4     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '�'), "  " BACK_MAG "SOND [007]" BACK_OFF " close and delete code file  -- -- -- -- -- -- -- -- -- -- -- -- -[00045]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, '�'), "      " BACK_GRN "DNOC --------------- test=4     [ pass=4     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check group"                    , yURG_peek (x_urun, '�'), "  GROUP ===---------------------------   final round   ---------------------------===");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '�'), "  " BACK_CYN "DOND [008] (2) read one record -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- [00091]" BACK_OFF);
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, '�'), "      " BACK_RED "DNOC --------------- test=4     [ pass=0     fail=4     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check global condition"         , yURG_peek (x_urun, '�'), "  " BACK_BLU "GOND [009]" BACK_OFF " prepare variables  -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00007]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, '�'), "      " BACK_GRN "DNOC --------------- test=1     [ pass=0     fail=0     badd=0     void=1     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check global condition"         , yURG_peek (x_urun, '�'), "  " BACK_BLU "GOND [010]" BACK_OFF " generate a summary -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00009]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, '�'), "      " BACK_GRN "DNOC --------------- test=3     [ pass=3     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '�'), "  " BACK_CYN "DOND [011] (1) process arguments  -- -- -- -- -- -- -- -- -- -- -- -- -- -- [00093]" BACK_OFF);
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, '�'), "      " BACK_GRN "DNOC --------------- test=4     [ pass=4     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check script footer"            , yURG_peek (x_urun, '�'), "  " BACK_RED "PRCS -------- cond=11    test=40    [ pass=30    fail=8     badd=0     void=2     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify fourth script and footer");
   yUNIT_minstr  ("... check unit footer"              , yURG_peek (x_urun, '�'), BACK_RED "TINU  scrp=1    cond=11    test=40    [ pass=30    fail=8     badd=0     void=2     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check unit footer"              , yURG_peek (x_urun, '�'), "yUNIT - heatherly unit testing framework ---------------------------------------(end)");
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
   yUNIT_minstr  ("... check unit header"              , yURG_peek (x_urun, '�'), "yUNIT - heatherly unit testing framework ---------------------------------------(beg)");
   yUNIT_minstr  ("... ... patron"                     , yURG_peek (x_urun, '�'), "   patron : daktyloi-aeonius (forefinger) automated unit testing                   4s");
   yUNIT_minstr  ("... ... level"                      , yURG_peek (x_urun, '�'), "   assign output level to (4) YUNIT_STEP                                          21c");
   yUNIT_minstr  ("... ... eterm"                      , yURG_peek (x_urun, '�'), "   assign format/color to (y) ETERM                                               90x");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check step level section format");
   yUNIT_minstr  ("... check section"                  , yURG_peek (x_urun, '�'), "=========================------------------------------------========================");
   yUNIT_minstr  ("... check section"                  , yURG_peek (x_urun, '�'), "SECT ===-------------------------- simple testing ---------------------------=== TCES");
   yUNIT_minstr  ("... check section"                  , yURG_peek (x_urun, '�'), "=========================------------------------------------========================");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check step level script format");
   yUNIT_minstr  ("... check (11) separator"           , yURG_peek (x_urun, '�'), "===[[ NEW SCRIPT ]]==================================================================");
   yUNIT_minstr  ("... check script"                   , yURG_peek (x_urun, '�'), "SCRP [01] (SCRP) verify openning and closing ============================[��]=[00006]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check step level condition and normal steps");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '�'), "  COND [001] simple openning -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00007]");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, '�'), "     aa) str   : check string � �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �[00008]");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, '�'), "     ab) real  : check number � �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �[00009]");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, '�'), "     ac) int   : check integer  �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �[00010]");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, '�'), "     ad) int   : check character � �� �� �� �� �� �� �� �� �� �� �� �� �� �� �[00011]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '�'), "  " BACK_CYN "CCND [002] (1)" BACK_OFF " defensive checks - -- -- -- -- -- -- -- -- -- -- -- -- -- -- [00012]");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check alternative step level entries");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun,  41), "  COND [006] duplicate opens and closes  -- -- -- -- -- -- -- -- -- -- -- -- -[00021]");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, '�'), "     aa) LOCAL : working variables �� �� �� �� �� �� �� �� �� �� �� �� �� �� �[00022]");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, '�'), "     ab) int   : check working variable  �� �� �� �� �� �� �� �� �� �� �� �� �[00023]");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, '�'), "     ac) LOAD  : prep data for read � �� �� �� �� �� �� �� �� �� �� �� �� �� �[00024]");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, '�'), "     ad) MODE  : FORCED_FAIL �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �[00025]");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, '�'), "     ae) SYS   : run little  �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �[00026]");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check inclusion of shared");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun,  64), "");
   yUNIT_minstr  ("... check shared header"            , yURG_peek (x_urun, '�'), "  " BACK_MAG "SHARE (a) ===--------------------   prepare files for use   --------------------===" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '�'), "  " BACK_MAG "SOND [002]" BACK_OFF " script input file  -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00029]");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, '�'), "     aa) str   : check string � �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �[00030]");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, '�'), "     ab) real  : check number � �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �[00031]");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, '�'), "     ac) int   : check integer  �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �[00032]");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, '�'), "     ad) MODE  : normal � �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �[00033]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '�'), "  " BACK_MAG "SOND [003]" BACK_OFF " code output file - -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00034]");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, '�'), "     aa) str   : check string � �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �[00035]");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, '�'), "     ab) real  : check number � �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �[00036]");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, '�'), "     ac) int   : check integer  �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �[00037]");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, '�'), "     ad) int   : check character � �� �� �� �� �� �� �� �� �� �� �� �� �� �� �[00038]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check shared footer"            , yURG_peek (x_urun, '�'), "  " BACK_MAG "ERAHS (a) ===--------------------   prepare files for use   --------------------===" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minval  ("... check line count"               , yURG_peek_count (x_urun) , 197);
   yUNIT_mindnoc ();

   yUNIT_mincond ("check inclusion of global");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 166), "");
   yUNIT_minstr  ("... check global header"            , yURG_peek (x_urun, '�'), "  " BACK_BLU "GLOBAL (D) ===-------------------   globally shared steps   --------------------===" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '�'), "  " BACK_BLU "GOND [009]" BACK_OFF " prepare variables  -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00007]");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, '�'), "     aa) CODE  : set new value  �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �[00008]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '�'), "  " BACK_BLU "GOND [010]" BACK_OFF " generate a summary -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00009]");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, '�'), "     aa) str   : check string � �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �[00010]");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, '�'), "     ab) real  : check number � �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �[00011]");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, '�'), "     ac) int   : check integer  �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �[00012]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check global footer"            , yURG_peek (x_urun, '�'), "  " BACK_BLU "LABOLG (D) ===-------------------   globally shared steps   --------------------===" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minval  ("... check line count"               , yURG_peek_count (x_urun) , 197);
   yUNIT_mindnoc ();

   yUNIT_mincond ("check executing and presenting down to steps");
   yUNIT_minval  ("... run unit test"                  , system ("./koios_unit --step"), 999);
   yUNIT_mindnoc ();

   yUNIT_mincond ("check step level condition and normal steps");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun,  14), "  COND [001] simple openning -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00007]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, '�'), "  " BACK_GRN "aa) PASS  " BACK_OFF " : check string �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��[00008]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, '�'), "  " BACK_GRN "ab) PASS  " BACK_OFF " : check number �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��[00009]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, '�'), "  " BACK_GRN "ac) PASS  " BACK_OFF " : check integer � �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��[00010]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, '�'), "  " BACK_GRN "ad) PASS  " BACK_OFF " : check character �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��[00011]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, '�'), "      " BACK_GRN "DNOC --------------- test=4     [ pass=4     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '�'), "  " BACK_CYN "CCND [002] (1)" BACK_OFF " defensive checks - -- -- -- -- -- -- -- -- -- -- -- -- -- -- [00012]");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check alternative step level entries");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun,  68), "  COND [006] duplicate opens and closes  -- -- -- -- -- -- -- -- -- -- -- -- -[00021]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, '�'), "  " BACK_CYN "aa) " BACK_GRN "LOCAL " BACK_OFF " : working variables  �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��[00022]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, '�'), "  " BACK_GRN "ab) PASS  " BACK_OFF " : check working variable � �� �� �� �� �� �� �� �� �� �� �� �� ��[00023]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, '�'), "  " BACK_CYN "ac) " BACK_GRN "LOAD  " BACK_OFF " : prep data for read �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��[00024]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, '�'), "  " BACK_CYN "ad) " BACK_GRN "MODE  " BACK_OFF " : ENABLE FORCED FAILURE (pass=fail, fail=pass)  �� �� �� �� �� ��[00025]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, '�'), "  " BACK_CYN "ae) " BACK_RED "!SYS  " BACK_OFF " : run little � �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��[00026]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, '�'), "      " BACK_RED "DNOC --------------- test=5     [ pass=1     fail=1     badd=0     void=3     ]" BACK_OFF);
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
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun,  16), "  " BACK_GRN "aa) PASS  " BACK_OFF " : check string �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��[00008]");
   yUNIT_minstr  ("... ... method"                     , yURG_peek (x_urun, '�'), "      method : yUNIT_teststring (0)");
   yUNIT_minstr  ("... ... test"                       , yURG_peek (x_urun, '�'), "      test   : s_equal    (rc =  101, test abbr = e)");
   yUNIT_minstr  ("... ... expect"                     , yURG_peek (x_urun, '�'), "      expect :  5[hello]");
   yUNIT_minstr  ("... ... actual"                     , yURG_peek (x_urun, '�'), "      actual :  5[hello]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check failing string step (nearly same)");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, 418), "  " BACK_RED "aa) FAIL  " BACK_OFF " : check string �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��[00083]");
   yUNIT_minstr  ("... ... method"                     , yURG_peek (x_urun, '�'), "      method : yUNIT_teststring (1)");
   yUNIT_minstr  ("... ... test"                       , yURG_peek (x_urun, '�'), "      test   : s_equal    (rc = -101, test abbr = e)");
   yUNIT_minstr  ("... ... expect"                     , yURG_peek (x_urun, '�'), "      expect :  7[" BOLD_RED "hello��" BOLD_OFF "]");
   yUNIT_minstr  ("... ... actual"                     , yURG_peek (x_urun, '�'), "      actual :  7[" BOLD_RED "goodbye" BOLD_OFF "]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check forced fail string step (same)");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, 187), "  " BACK_GRN "aa) " BACK_RED "!FAIL " BACK_OFF " : check string �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��[00030]");
   yUNIT_minstr  ("... ... method"                     , yURG_peek (x_urun, '�'), "      method : yUNIT_teststring (0)");
   yUNIT_minstr  ("... ... test"                       , yURG_peek (x_urun, '�'), "      test   : s_equal    (rc =  101, test abbr = e)");
   yUNIT_minstr  ("... ... expect"                     , yURG_peek (x_urun, '�'), "      expect :  5[hello]");                              
   yUNIT_minstr  ("... ... actual"                     , yURG_peek (x_urun, '�'), "      actual :  5[hello]");                              
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check passing float step");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun,  22), "  " BACK_GRN "ab) PASS  " BACK_OFF " : check number �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��[00009]");
   yUNIT_minstr  ("... ... method"                     , yURG_peek (x_urun, '�'), "      method : yUNIT_testreal (5)");
   yUNIT_minstr  ("... ... test"                       , yURG_peek (x_urun, '�'), "      test   : r_greater  (rc =  103, test abbr = g)");
   yUNIT_minstr  ("... ... expect"                     , yURG_peek (x_urun, '�'), "      expect :  9[15.000000]");
   yUNIT_minstr  ("... ... actual"                     , yURG_peek (x_urun, '�'), "      actual :  9[15.707964]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check failing float step");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, 424), "  " BACK_RED "ab) FAIL  " BACK_OFF " : check number �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��[00084]");
   yUNIT_minstr  ("... ... method"                     , yURG_peek (x_urun, '�'), "      method : yUNIT_testreal (2)");
   yUNIT_minstr  ("... ... test"                       , yURG_peek (x_urun, '�'), "      test   : r_greater  (rc = -103, test abbr = g)");
   yUNIT_minstr  ("... ... expect"                     , yURG_peek (x_urun, '�'), "      expect :  9[15.000000]");
   yUNIT_minstr  ("... ... actual"                     , yURG_peek (x_urun, '�'), "      actual :  8[6.283185]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check passing integer step");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun,  28), "  " BACK_GRN "ac) PASS  " BACK_OFF " : check integer � �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��[00010]");
   yUNIT_minstr  ("... ... method"                     , yURG_peek (x_urun, '�'), "      method : yUNIT_testint (32)");
   yUNIT_minstr  ("... ... test"                       , yURG_peek (x_urun, '�'), "      test   : i_equal    (rc =  101, test abbr = e)");
   yUNIT_minstr  ("... ... expect"                     , yURG_peek (x_urun, '�'), "      expect :  1[2]");
   yUNIT_minstr  ("... ... actual"                     , yURG_peek (x_urun, '�'), "      actual :  1[2]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check failing integer step");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, 430), "  " BACK_RED "ac) FAIL  " BACK_OFF " : check integer � �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��[00085]");
   yUNIT_minstr  ("... ... method"                     , yURG_peek (x_urun, '�'), "      method : yUNIT_testint (64)");
   yUNIT_minstr  ("... ... test"                       , yURG_peek (x_urun, '�'), "      test   : i_equal    (rc = -101, test abbr = e)");
   yUNIT_minstr  ("... ... expect"                     , yURG_peek (x_urun, '�'), "      expect :  1[2]");
   yUNIT_minstr  ("... ... actual"                     , yURG_peek (x_urun, '�'), "      actual :  1[4]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check mode step");                                   
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, 141), "  " BACK_CYN "ad) " BACK_GRN "MODE  " BACK_OFF " : ENABLE FORCED FAILURE (pass=fail, fail=pass)  �� �� �� �� �� ��[00025]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check code step");                                   
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, 568), "  " BACK_CYN "aa) " BACK_GRN "CODE  " BACK_OFF " : set new value � �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��[00008]");
   yUNIT_minstr  ("... ... contents"                   , yURG_peek (x_urun, '�'), "      code   : 12[h = 32 * 64;]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check load step");                                   
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun,  44), "  " BACK_CYN "aa) " BACK_GRN "LOAD  " BACK_OFF " : prep data for read �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��[00013]");
   yUNIT_minstr  ("... ... contents"                   , yURG_peek (x_urun, '�'), "      stdin  : 13[one two three]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check sys step");                                   
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, 143), "  " BACK_CYN "ae) " BACK_RED "!SYS  " BACK_OFF " : run little � �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��[00026]");
   yUNIT_minstr  ("... ... contents"                   , yURG_peek (x_urun, '�'), "      system : 10[/bin/false]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check local step");                                   
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, 129), "  " BACK_CYN "aa) " BACK_GRN "LOCAL " BACK_OFF " : working variables  �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��[00022]");
   yUNIT_minstr  ("... ... contents"                   , yURG_peek (x_urun, '�'), "      local  : 10[int c = 0;]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '�'), "");
   yUNIT_mindnoc ();

   yUNIT_minprcs ();
   return 0;
}



/*====================------------------------------------====================*/
/*===----                      main driver                             ----===*/
/*====================------------------------------------====================*/
static void      o___DRIVER__________________o (void) {;}

char
main                    (int a_argc, char *a_argv [])
{
   int         x_unit      =    0;
   int         n           =    0;
   char        x_list      =    0;
   /*---(args)---------------------------*/
   printf ("testing : %s\n\n", a_argv [0]);
   if (a_argc >= 2) {
      if (strcmp (a_argv [1], "--list") == 0)  x_list = 'y';
      else                                     x_unit = atoi (a_argv [1]);
   }
   /*---(program wide)-------------------*/
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_prog_file      (x_list);
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_prog_args      (x_list);
   /*---(koios_verb.c)-------------------*/
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_verb_parse     (x_list);
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_verb_ditto     (x_list);
   /*---(koios_wave.c)-------------------*/
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_wave_stage     (x_list);
   /*---(koios_read.c)-------------------*/
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_read_open      (x_list);
   /*---(koios_ditto.c)------------------*/
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_ditto_index    (x_list);
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_ditto_getset   (x_list);
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_ditto_toggle   (x_list);
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_ditto_read     (x_list);
   /*---(koios_reuse.c)------------------*/
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_reuse_index    (x_list);
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_reuse_getset   (x_list);
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_reuse_global   (x_list);
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_reuse_shares   (x_list);
   /*---(koios_conv.c)-------------------*/
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_conv_defense   (x_list);
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_conv_printf    (x_list);
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_conv_preps     (x_list);
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_conv_scrps     (x_list);
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_conv_conds     (x_list);
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_conv_steps     (x_list);
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_conv_driver    (x_list);
   /*---(koios_code.c)-------------------*/
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_code_display   (x_list);
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_code_prefix    (x_list);
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_code_expect    (x_list);
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_code_suffix    (x_list);
   /*---(koios_read.c)-------------------*/
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_read_defense   (x_list);
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_read_single    (x_list);
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_read_end_ditto (x_list);
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_read_driver    (x_list);
   /*---(koios_parse.c)------------------*/
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_parse_field    (x_list);
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_parse_current  (x_list);
   /*---(script input)-------------------*/
   /*> ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_scrp_comment ();            <* 
    *> ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_scrp_limits  ();            <* 
    *> ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_scrp__current();            <* 
    *> ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_scrp_parse   ();            <* 
    *> ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_scrp_share   ();            <* 
    *> ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_scrp_ditto   ();            <* 
    *> ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_scrp_variety ();            <*/
   /*---(conversion output)--------------*/
   /*> ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_conv_files   ();            <* 
    *> ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_conv_ends    ();            <* 
    *> ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_conv_prep    ();            <* 
    *> ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_conv_scrp    ();            <* 
    *> ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_conv_cond    ();            <* 
    *> ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_conv_step    ();            <*/
   /*---(code generation)----------------*/
   /*> ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_code_counts  ();            <* 
    *> ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_code_files   ();            <* 
    *> ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_code_ends    ();            <* 
    *> ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_code_prep    ();            <* 
    *> ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_code_scrp    ();            <* 
    *> ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_code_cond    ();            <* 
    *> ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_code_step    ();            <*/
   /*---(live testing)-------------------*/
   /*> ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_live_scrp    ();            <* 
    *> ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_live_cond    ();            <* 
    *> ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_live_step    ();            <* 
    *> ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_live_full    ();            <*/
   /*---(done)---------------------------*/
   yUNIT_mintinu ();
   return 0;
}


