/*===============================[[ beg-code ]]===============================*/
#include    "koios.h"        /* LOCAL  : main header                          */

#include    "ySTR_solo.h"
#include    "yCOLOR_solo.h"
#include    "yUNIT_solo.h"



/*
 *  apate is the greek minor goddess of fraud/deceit
 *
 */

char
rm_working_files        (void)
{
   yUNIT_mincond ("prepare clean start");
   /*---(unit related)-------------------*/
   system ("rm    -f apate.unit        2> /dev/null");
   system ("rm    -f apate.sunit       2> /dev/null");
   system ("rm    -f apatey.sunit      2> /dev/null");
   system ("rm    -f linked.unit       2> /dev/null");
   system ("rm    -f linked.sunit      2> /dev/null");
   system ("rm    -f apate-a.unit      2> /dev/null");
   system ("rm    -f apate_a.unit      2> /dev/null");
   system ("rmdir -f apate_dir.unit    2> /dev/null");
   system ("rm    -f khaos.unit        2> /dev/null");
   system ("rm    -f gyges.unit        2> /dev/null");
   system ("rm    -f hestia.unit       2> /dev/null");
   /*---(code related)-------------------*/
   system ("rm    -f apate.c           2> /dev/null");
   system ("rm    -f apate_unit.tmp    2> /dev/null");
   system ("rm    -f apate.unit.old    2> /dev/null");
   system ("rm    -f apate_unit.cs     2> /dev/null");
   system ("rm    -f apate.wave        2> /dev/null");
   /*---(master related)-----------------*/
   system ("rm    -f master.h          2> /dev/null");
   system ("rm    -f master.unit       2> /dev/null");
   system ("rm    -f master.unit.old   2> /dev/null");
   system ("rm    -f master.globals    2> /dev/null");
   /*---(output)-------------------------*/
   system ("rm    -f apate.urun        2> /dev/null");
   /*---(done)---------------------------*/
   yUNIT_mindnoc ();
   return 0;
}

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
   rm_working_files ();
   PROG__unit_quiet  ();

   yURG_err_clear ();
   system ("rm -f apate.unit        2> /dev/null");
   yUNIT_mincond ("attempt with a missing file");
   yUNIT_minval  ("... run file check"                 , PROG__file ("apate"     , x_base, x_ext)           , -999);
   yUNIT_minstr  ("... check base"                     , x_base          , "");
   yUNIT_minstr  ("... check ext"                      , x_ext           , "");
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "script name ∂apate∂ can not be found as .unit or .sunit");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   system ("touch apate.unit        2> /dev/null");
   yUNIT_mincond ("quick success once file added");
   yUNIT_minval  ("... run file check"                 , PROG__file ("apate"     , x_base, x_ext)           , 0);
   yUNIT_minstr  ("... check base"                     , x_base          , "apate");
   yUNIT_minstr  ("... check ext"                      , x_ext           , ".unit");
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   system ("touch apate.unit        2> /dev/null");
   yUNIT_mincond ("verify no path allowed");
   yUNIT_minval  ("... run file check"                 , PROG__file ("/tmp/apate", x_base, x_ext)           , -999);
   yUNIT_minstr  ("... check base"                     , x_base          , "");
   yUNIT_minstr  ("... check ext"                      , x_ext           , "");
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "script name ∂/tmp/apate∂ can not include a path (abs or rel)");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   system ("touch apate.unit        2> /dev/null");
   yUNIT_mincond ("verify no hidden files");
   yUNIT_minval  ("... run file check"                 , PROG__file (".apate"    , x_base, x_ext)           , -999);
   yUNIT_minstr  ("... check base"                     , x_base          , "");
   yUNIT_minstr  ("... check ext"                      , x_ext           , "");
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "script name ∂.apate∂ can not be hidden file (.)");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   system ("rm -f apate.unit        2> /dev/null");
   system ("touch linked.unit       2> /dev/null");
   system ("cp -s linked.unit  apate.unit  2> /dev/null");
   yUNIT_mincond ("attempt a symlink to regular e (.unit file)");
   yUNIT_minval  ("... run file check"                 , PROG__file ("apate"     , x_base, x_ext)           , -999);
   yUNIT_minstr  ("... check base"                     , x_base          , "");
   yUNIT_minstr  ("... check ext"                      , x_ext           , "");
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "script name ∂apate∂ is a symlink to ∂linked.unit∂, only .sunit is legal");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   system ("rm -f apate.unit        2> /dev/null");
   system ("touch linked.sunit      2> /dev/null");
   system ("cp -s linked.sunit apate.unit  2> /dev/null");
   yUNIT_mincond ("verify can symlink to .sunit");
   yUNIT_minval  ("... run file check"                 , PROG__file ("apate"     , x_base, x_ext)           , 0);
   yUNIT_minstr  ("... check base"                     , x_base          , "apate");
   yUNIT_minstr  ("... check ext"                      , x_ext           , ".unit");
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   system ("mkdir apate_dir.unit    2> /dev/null");
   yUNIT_mincond ("attempt to use a directory");
   yUNIT_minval  ("... run file check"                 , PROG__file ("apate_dir", x_base, x_ext)       , -999);
   yUNIT_minstr  ("... check base"                     , x_base          , "");
   yUNIT_minstr  ("... check ext"                      , x_ext           , "");
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "script name ∂apate_dir∂ refers to a directory, illegal");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   system ("touch apate-a.unit      2> /dev/null");
   yUNIT_mincond ("badly named unit test");
   yUNIT_minval  ("... run file check"                 , PROG__file ("apate-a", x_base, x_ext)         , -999);
   yUNIT_minstr  ("... check base"                     , x_base          , "");
   yUNIT_minstr  ("... check ext"                      , x_ext           , "");
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "script name ∂apate-a∂ can not have a '-' as character 5");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   system ("touch apate_a.unit      2> /dev/null");
   yUNIT_mincond ("named with underscore");
   yUNIT_minval  ("... run file check"                 , PROG__file ("apate_a", x_base, x_ext)         , 0);
   yUNIT_minstr  ("... check base"                     , x_base          , "apate_a");
   yUNIT_minstr  ("... check ext"                      , x_ext           , ".unit");
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("called with extention");
   yUNIT_minval  ("... run file check"                 , PROG__file ("apate_a.unit", x_base, x_ext)    , 0);
   yUNIT_minstr  ("... check base"                     , x_base          , "apate_a");
   yUNIT_minstr  ("... check ext"                      , x_ext           , ".unit");
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc ();

   PROG__unit_end    ();
   rm_working_files ();
   yUNIT_minprcs ();
   return 0;
}

char
koios__unit_prog_args    (char a_list)
{
   char        x_base      [LEN_PATH]  = "";
   char        x_ext       [LEN_TERSE] = "";
   char        x_runtype   = '∑';
   char        x_noise     = '-';
   char        x_replace   = '∑';
   yUNIT_minscrp ("PROG__args");
   if (a_list == 'y')  return 0;
   yURG_err_none ();  /* not to stderr/terminal */
   rm_working_files ();
   PROG__unit_quiet  ();

   yUNIT_mincond ("prepare clean start");
   char  *x_argA [3]  = { "apate_unit" , "--debug"       , "khaos.unit"          };
   char  *x_argB [3]  = { "apate_unit" , "--compile"     , "gyges.unit"          };
   char  *x_argC [3]  = { "apate_unit" , "--debuggery"   , "hestia.unit"         };
   char  *x_argD [3]  = { "apate_unit" , "--create"      , "hestia"              };
   char  *x_argE [3]  = { "apate_unit" , "--convert"     , "apatey.sunit"        };
   char  *x_argF [1]  = { "apate_unit" };
   char  *x_argG [3]  = { "apate_unit" , "--update"      , "apate"               };
   char  *x_argH [3]  = { "apate_unit" , "--compile"     , "apatey.sunit"        };
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("attempt with no arguments (defaulting)");
   yUNIT_minval  ("... run args"                       , PROG__args (1, x_argF, &x_runtype, &x_noise, &x_replace, x_base, x_ext) , -999);
   yUNIT_minchr  ("... check run type"                 , x_runtype   , '∑');
   yUNIT_minchr  ("... check run replace"              , x_replace   , '∑');
   yUNIT_minstr  ("... check base"                     , x_base      , "");
   yUNIT_minstr  ("... check ext"                      , x_ext       , "");
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "script name/base was not provided on command line");
   yUNIT_mindnoc ();

   system ("touch khaos.unit  2> /dev/null");
   yURG_err_clear ();
   yUNIT_mincond ("run with debug");
   yUNIT_minval  ("... run args"                       , PROG__args (3, x_argA, &x_runtype, &x_noise, &x_replace, x_base, x_ext) , 0);
   yUNIT_minchr  ("... check run type"                 , x_runtype   , G_RUN_DEBUG);
   yUNIT_minchr  ("... check run replace"              , x_replace   , G_RUN_DEFAULT);
   yUNIT_minstr  ("... check base"                     , x_base          , "khaos");
   yUNIT_minstr  ("... check ext"                      , x_ext           , ".unit");
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc ();

   system ("touch gyges.unit          2> /dev/null");
   yURG_err_clear ();
   yUNIT_mincond ("run with compile");
   yUNIT_minval  ("... run args"                       , PROG__args (3, x_argB, &x_runtype, &x_noise, &x_replace, x_base, x_ext) , 0);
   yUNIT_minchr  ("... check run type"                 , x_runtype   , G_RUN_CREATE);
   yUNIT_minchr  ("... check run replace"              , x_replace   , G_RUN_DEFAULT);
   yUNIT_minstr  ("... check base"                     , x_base          , "gyges");
   yUNIT_minstr  ("... check ext"                      , x_ext           , ".unit");
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc ();

   system ("touch hestia.unit         2> /dev/null");
   yURG_err_clear ();
   yUNIT_mincond ("run with bad argument");
   yUNIT_minval  ("... run args"                       , PROG__args (3, x_argC, &x_runtype, &x_noise, &x_replace, x_base, x_ext) , -999);
   yUNIT_minchr  ("... check run type"                 , x_runtype   , '∑');
   yUNIT_minchr  ("... check run replace"              , x_replace   , '∑');
   yUNIT_minstr  ("... check base"                     , x_base          , "");
   yUNIT_minstr  ("... check ext"                      , x_ext           , "");
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "argument ∂--debuggery∂ is not recognized");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("run with create");
   yUNIT_minval  ("... run args"                       , PROG__args (3, x_argD, &x_runtype, &x_noise, &x_replace, x_base, x_ext) , 0);
   yUNIT_minchr  ("... check run type"                 , x_runtype   , G_RUN_CREATE);
   yUNIT_minchr  ("... check run replace"              , x_replace   , G_RUN_DEFAULT);
   yUNIT_minstr  ("... check base"                     , x_base          , "hestia");
   yUNIT_minstr  ("... check ext"                      , x_ext           , ".unit");
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc ();

   system ("touch apatey.sunit        2> /dev/null");
   yURG_err_clear ();
   yUNIT_mincond ("run sunit with convert");
   yUNIT_minval  ("... run args"                       , PROG__args (3, x_argE, &x_runtype, &x_noise, &x_replace, x_base, x_ext) , 0);
   yUNIT_minchr  ("... check run type"                 , x_runtype   , G_RUN_UPDATE);
   yUNIT_minchr  ("... check run replace"              , x_replace   , G_RUN_DEFAULT);
   yUNIT_minstr  ("... check base"                     , x_base          , "apatey");
   yUNIT_minstr  ("... check ext"                      , x_ext           , ".sunit");
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("run sunit with compile");
   yUNIT_minval  ("... run args"                       , PROG__args (3, x_argH, &x_runtype, &x_noise, &x_replace, x_base, x_ext) , -999);
   yUNIT_minchr  ("... check run type"                 , x_runtype   , '∑');
   yUNIT_minchr  ("... check run replace"              , x_replace   , '∑');
   yUNIT_minstr  ("... check base"                     , x_base      , "");
   yUNIT_minstr  ("... check ext"                      , x_ext       , "");
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "can not compile ∂apatey∂ as .sunit, must compile in linked .unit location");
   yUNIT_mindnoc ();

   system ("touch apate.unit          2> /dev/null");
   yURG_err_clear ();
   yUNIT_mincond ("run with update");
   yUNIT_minval  ("... run args"                       , PROG__args (3, x_argG, &x_runtype, &x_noise, &x_replace, x_base, x_ext) , 0);
   yUNIT_minchr  ("... check run type"                 , x_runtype   , G_RUN_UPDATE);
   yUNIT_minchr  ("... check run replace"              , x_replace   , G_RUN_REPLACE);
   yUNIT_minstr  ("... check base"                     , x_base          , "apate");
   yUNIT_minstr  ("... check ext"                      , x_ext           , ".unit");
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc ();

   PROG__unit_end    ();
   rm_working_files ();
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
   char        x_name      [LEN_LABEL] = "apate.unit";
   char        x_mast      [LEN_LABEL] = "master.unit";
   char        x_verb      [LEN_LABEL] = "";
   char        x_indx      = -1;
   char        x_spec      = '-';
   char        x_locn      = '-';
   void       *x_conv      = NULL;
   void       *x_code      = NULL;

   yUNIT_minscrp ("VERB_parse");
   if (a_list == 'y')  return 0;
   yURG_err_none ();
   rm_working_files ();
   PROG__unit_quiet  ();

   yURG_err_clear ();
   yUNIT_mincond  ("parse SCRP verb");
   yUNIT_minval   ("parse SCRP"                          , VERB_parse (x_name ,  5, "SCRP"       , x_verb, &x_indx, &x_spec, &x_locn, &x_conv, &x_code), 0);
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
   yUNIT_minval   ("parse trouble"                       , VERB_parse (x_name , 25, "handler"    , x_verb, &x_indx, &x_spec, &x_locn, &x_conv, &x_code), -999);
   yUNIT_minstr   ("... check verb"                      , x_verb        , "");
   yUNIT_minval   ("... check index"                     , x_indx        , -999);
   yUNIT_minchr   ("... check spec"                      , x_spec        , '-');
   yUNIT_minchr   ("... check location"                  , x_locn        , '-');
   yUNIT_minpoint ("... check conv pointer"              , x_conv        , NULL);
   yUNIT_minpoint ("... check code pointer"              , x_code        , NULL);
   yUNIT_minstr   ("... check error message"             , yURG_err_last (), "apate.unit:25:0: error: verb ∂handler∂ not recognized/found");
   yUNIT_mindnoc  ();

   yURG_err_clear ();
   yUNIT_mincond  ("verify parsing a COND verb");
   yUNIT_minval   ("parse COND"                          , VERB_parse (x_name , 10, " COND"      , x_verb, &x_indx, &x_spec, &x_locn, &x_conv, &x_code), 0);
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
   yUNIT_minval   ("parse COND"                          , VERB_parse (x_name , 40, " COND (1)"  , x_verb, &x_indx, &x_spec, &x_locn, &x_conv, &x_code), 0);
   yUNIT_minstr   ("... check verb"                      , x_verb        , "COND");
   yUNIT_minval   ("... check index"                     , x_indx        , 999);
   yUNIT_minchr   ("... check spec"                      , x_spec        , '2');
   yUNIT_minchr   ("... check location"                  , x_locn        , '-');
   yUNIT_minpoint ("... check conv pointer"              , x_conv        , CONV_cond);
   yUNIT_minpoint ("... check code pointer"              , x_code        , CODE_cond);
   yUNIT_minstr   ("... check error message"             , yURG_err_last (), "");

   yURG_err_clear ();
   yUNIT_mincond  ("attempt a null input");
   yUNIT_minval   ("parse NULL"                          , VERB_parse (x_name , 50, NULL         , x_verb, &x_indx, &x_spec, &x_locn, &x_conv, &x_code), -999);
   yUNIT_minstr   ("... check verb"                      , x_verb        , "");
   yUNIT_minval   ("... check index"                     , x_indx        , -999);
   yUNIT_minchr   ("... check spec"                      , x_spec        , '-');
   yUNIT_minchr   ("... check location"                  , x_locn        , '-');
   yUNIT_minpoint ("... check conv pointer"              , x_conv        , NULL);
   yUNIT_minpoint ("... check code pointer"              , x_code        , NULL);
   yUNIT_minstr   ("... check error message"             , yURG_err_last (), "apate.unit:50:0: error: no verb found (empty or null)");
   yUNIT_mindnoc  ();

   yURG_err_clear ();
   yUNIT_mincond  ("verify parsing an EXEC verb");
   yUNIT_minval   ("parse exec"                          , VERB_parse (x_name , 15, "  exec"     , x_verb, &x_indx, &x_spec, &x_locn, &x_conv, &x_code), 0);
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
   yUNIT_minval   ("parse SHARED (in normal)"            , VERB_parse (x_name , 35, "SHARED -a-" , x_verb, &x_indx, &x_spec, &x_locn, &x_conv, &x_code), 0);
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
   yUNIT_minval   ("parse GLOBAL (in normal)"            , VERB_parse (x_name , 75, "GLOBAL -a-" , x_verb, &x_indx, &x_spec, &x_locn, &x_conv, &x_code), -999);
   yUNIT_minstr   ("... check verb"                      , x_verb        , "");
   yUNIT_minval   ("... check index"                     , x_indx        , -999);
   yUNIT_minchr   ("... check spec"                      , x_spec        , '-');
   yUNIT_minchr   ("... check location"                  , x_locn        , '-');
   yUNIT_minpoint ("... check conv pointer"              , x_conv        , NULL);
   yUNIT_minpoint ("... check code pointer"              , x_code        , NULL);
   yUNIT_minstr   ("... check error message"             , yURG_err_last (), "apate.unit:75:0: error: verb ∂GLOBAL∂ good, but not allowed outside master.unit");
   yUNIT_mindnoc  ();

   yURG_err_clear ();
   yUNIT_mincond  ("verify parsing a GLOBAL (master only) verb with suffix");
   yURG_err_clear ();
   yUNIT_minval   ("parse GLOBAL (in master)"            , VERB_parse (x_mast , 85, "GLOBAL -a-" , x_verb, &x_indx, &x_spec, &x_locn, &x_conv, &x_code), 0);
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
   yUNIT_minval   ("parse SHARED (in master)"            , VERB_parse (x_mast , 95, "SHARED -a-" , x_verb, &x_indx, &x_spec, &x_locn, &x_conv, &x_code), -999);
   yUNIT_minstr   ("... check verb"                      , x_verb        , "");
   yUNIT_minval   ("... check index"                     , x_indx        , -999);
   yUNIT_minchr   ("... check spec"                      , x_spec        , '-');
   yUNIT_minchr   ("... check location"                  , x_locn        , '-');
   yUNIT_minpoint ("... check conv pointer"              , x_conv        , NULL);
   yUNIT_minpoint ("... check code pointer"              , x_code        , NULL);
   yUNIT_minstr   ("... check error message"             , yURG_err_last (), "master.unit:95:0: error: verb ∂SHARED∂ good, but not allowed inside master.unit");
   yUNIT_mindnoc  ();

   PROG__unit_end    ();
   rm_working_files ();
   yUNIT_minprcs ();
   return 0;
}

char
koios__unit_verb_ditto   (char a_list)
{
   yUNIT_minscrp ("VERB_dittoable");
   if (a_list == 'y')  return 0;
   yURG_err_none ();
   rm_working_files ();
   PROG__unit_quiet  ();

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

   PROG__unit_end    ();
   rm_working_files ();
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
   char         x_name     [LEN_HUND] = "apate.unit";
   FILE        *x_file     = NULL;
   int          x_line     =    0;
   char         t          [LEN_HUND] = "";

   yUNIT_minscrp ("READ_open, READ_close");
   if (a_list == 'y')  return 0;
   yURG_err_none ();  /* not to stderr/terminal */
   rm_working_files ();
   PROG__unit_quiet  ();
   system ("rm -f apate.unit        2> /dev/null");

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
   yUNIT_minstr   ("... check error message"            , yURG_err_last (), "file ∂apate.unit∂ could not be openned");
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

   PROG__unit_end    ();
   rm_working_files ();
   yUNIT_minprcs ();
   return 0;
}

char
koios__unit_read_defense (char a_list)
{
   char         x_name     [LEN_HUND] = "apate.unit";
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
   char         x_name     [LEN_HUND] = "apate.unit";
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
   rm_working_files ();
   PROG__unit_quiet  ();

   yUNIT_mincond  ("verify reading a single record");
   system ("echo \"exec     read a line      SCRP_read       i_lesser    0      \"                                             > apate.unit");
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
   yUNIT_minstr   ("... check the record"               , x_recd        , "exec    ß read a line     ß SCRP_read   ß   ß i_lesser   ß 0      ß");
   yUNIT_minstr   ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify an empty line");
   system ("echo \"\"                                                                                                                       > apate.unit");
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
   system ("echo \"SCRP     testing          0s    tbd    - - - - -  \"                                                       > apate.unit");
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
   yUNIT_minstr   ("... check the record"               , x_recd        , "SCRP    ß testing         ß 0s  ß  tbd   ß - - - - -  ß");
   yUNIT_minstr   ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify a comment");
   system ("echo \"## the descripion of something else\"                                                                              > apate.unit");
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
   system ("echo \"SCRP\"                                                                                                             > apate.unit");
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
   system ("rm -f apate.unit 2> /dev/null");
   system ("touch apate.unit");
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

   PROG__unit_end    ();
   rm_working_files ();
   yUNIT_minprcs ();
   return 0;
}

char
koios__unit_read_end_ditto  (char a_list)
{
   char         x_name     [LEN_HUND] = "apate.unit";
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
   rm_working_files ();
   PROG__unit_quiet  ();

   yUNIT_mincond  ("create a test script");
   system ("echo \"\"                                                                                                                        > apate.unit");
   system ("echo \"COND  (0)  ditto stuff     \"                                                                                        >> apate.unit");
   system ("echo \"  exec     read a line      SCRP_read       i_lesser    0      \"                                            >> apate.unit");
   system ("echo \"\"                                                                                                                       >> apate.unit");
   system ("echo \"DITTO (0)  - - - - - - - - \"                                                                                        >> apate.unit");
   system ("echo \"\"                                                                                                                       >> apate.unit");
   system ("echo \"  get      next step        SCRP_read       i_lesser    0      \"                                            >> apate.unit");
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
   yUNIT_minval   ("call ditto begin"                   , DITTO_beg    (&x_file, x_name, x_line, G_RUN_CREATE , '0',    2, &x_dittoing, &x_mark, &x_dmark, &x_ditto, &x_dline)    , 1);
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
   yUNIT_minval   ("read the line"                      , READ__single  (&x_file, &x_line, &x_dittoing, &x_dmark, &x_ditto, &x_dline, &x_nrecd, x_recd), 1);
   yUNIT_minpoint ("... file"                           , x_file                   , x_save);
   yUNIT_minval   ("... line"                           , x_line                   ,    5);
   yUNIT_minchr   ("... dittoing"                       , x_dittoing               ,  'y');
   yUNIT_minchr   ("... dmark"                          , x_dmark                  ,  '0');
   yUNIT_minval   ("... ditto"                          , x_ditto                  ,    2);
   yUNIT_minval   ("... dline"                          , x_dline                  ,    2);
   yUNIT_minval   ("... nrecd"                          , x_nrecd                  ,    1);
   strlencode (x_recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr   ("... check the record"               , x_recd                   , "COND  (0) ß ditto stuff     ß");
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
   yUNIT_minval   ("... nrecd"                          , x_nrecd                  ,    2);
   strlencode (x_recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr   ("... check the record"               , x_recd        , "  exec    ß read a line     ß SCRP_read   ß   ß i_lesser   ß 0      ß");
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
   yUNIT_minval   ("... nrecd"                          , x_nrecd                  ,    2);
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
   yUNIT_minval   ("... nrecd"                          , x_nrecd                  ,    2);
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
   yUNIT_minval   ("... nrecd"                          , x_nrecd                  ,    3);
   strlencode (x_recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr   ("... check the record"               , x_recd        , "  get     ß next step       ß SCRP_read   ß   ß i_lesser   ß 0      ß");
   yUNIT_minstr   ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("close out the script");
   yUNIT_minval   ("close the script file"              , READ_close  (&x_file), 0);
   yUNIT_mindnoc ();

   PROG__unit_end    ();
   rm_working_files ();
   yUNIT_minprcs ();
   return 0;
}

char
koios__unit_read_driver  (char a_list)
{
   char         x_name     [LEN_HUND] = "apate.unit";
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
   rm_working_files ();
   PROG__unit_quiet  ();

   yUNIT_mincond  ("create an input file");
   system ("echo \"##\"                                                                                                                                                                                                                                                                                                                                  > apate.unit");
   system ("echo \"\"                                                                                                                                                                                                                                                                                                                                   >> apate.unit");
   system ("echo \"SCRP          (CATS) verify preparation and defaulting                           0s   prepare         CATS__prepare                                                                ((01.---))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  \"                 >> apate.unit");
   system ("echo \"\"                                                                                                                                                                                                                                                                                                                                   >> apate.unit");
   system ("echo \"   COND  (0)  verify the defaults                                                - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((01.001))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  \"                 >> apate.unit");
   system ("echo \"     exec     call prepare                         CATS__prepare               \\\"∑ ∑  ∑ ∑ ∑   ∑ ∑\\\"   , &x_len , &x_part, &x_sub , &x_src , &x_cat , &x_page, &x_grp , &x_freq         i_equal     0                                                                                                    \"           >> apate.unit");
   system ("echo \"\"                                                                                                                                                                                                                                                                                                                                   >> apate.unit");
   system ("echo \"   COND       make global changes                                                - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((01.001))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  \"                 >> apate.unit");
   system ("echo \"     code     ... change part                      - - - - - - - - - - - - -   x_part      = 'v';                                                                                                                                                                                                         \"                 >> apate.unit");
   system ("echo \"\"                                                                                                                                                                                                                                                                                                                                   >> apate.unit");
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
   yUNIT_minstr   ("... check the record"               , x_recd        , "SCRP         ß (CATS) verify preparation and defaulting                          ß 0s  ß prepare        ß CATS__prepare                                                               ß ((01.---)) ß - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ß");
   yUNIT_minstr   ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc  ();

   yURG_err_clear ();
   yUNIT_mincond  ("verify next good line");
   yUNIT_minval   ("read the line"                      , READ_next    (&x_file, &x_line, &x_dittoing, &x_dmark, &x_ditto, &x_dline, &x_nrecd, x_recd),    1);
   yUNIT_minval   ("... line"                           , x_line                   ,    5);
   yUNIT_minval   ("... nrecd"                          , x_nrecd                  ,    2);
   strlencode (x_recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr   ("... check the record"               , x_recd        , "   COND  (0) ß verify the defaults                                               ß - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ß ((01.001)) ß - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ß");
   yUNIT_minstr   ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc  ();

   yURG_err_clear ();
   yUNIT_mincond  ("verify next good line");
   yUNIT_minval   ("read the line"                      , READ_next    (&x_file, &x_line, &x_dittoing, &x_dmark, &x_ditto, &x_dline, &x_nrecd, x_recd),    1);
   yUNIT_minval   ("... line"                           , x_line                   ,    6);
   yUNIT_minval   ("... nrecd"                          , x_nrecd                  ,    3);
   strlencode (x_recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr   ("... check the record"               , x_recd        , "     exec    ß call prepare                        ß CATS__prepare              ß \"∑ ∑  ∑ ∑ ∑   ∑ ∑\"   , &x_len , &x_part, &x_sub , &x_src , &x_cat , &x_page, &x_grp , &x_freq        ß i_equal    ß 0                                                                                                    ß");
   yUNIT_minstr   ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc  ();

   yURG_err_clear ();
   yUNIT_mincond  ("verify next good line");
   yUNIT_minval   ("read the line"                      , READ_next    (&x_file, &x_line, &x_dittoing, &x_dmark, &x_ditto, &x_dline, &x_nrecd, x_recd),    1);
   yUNIT_minval   ("... line"                           , x_line                   ,    8);
   yUNIT_minval   ("... nrecd"                          , x_nrecd                  ,    4);
   strlencode (x_recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr   ("... check the record"               , x_recd        , "   COND      ß make global changes                                               ß - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ß ((01.001)) ß - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ß");
   yUNIT_minstr   ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc  ();

   yURG_err_clear ();
   yUNIT_mincond  ("verify next good line");
   yUNIT_minval   ("read the line"                      , READ_next    (&x_file, &x_line, &x_dittoing, &x_dmark, &x_ditto, &x_dline, &x_nrecd, x_recd),    1);
   yUNIT_minval   ("... line"                           , x_line                   ,    9);
   yUNIT_minval   ("... nrecd"                          , x_nrecd                  ,    5);
   strlencode (x_recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr   ("... check the record"               , x_recd        , "     code    ß ... change part                     ß - - - - - - - - - - - - -  ß x_part      = 'v';                                                                                                                                                                                                         ß");
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
   yUNIT_mindnoc ();

   PROG__unit_end    ();
   rm_working_files ();
   yUNIT_minprcs ();
   return 0;
}



/*====================------------------------------------====================*/
/*===----                        record parsing                        ----===*/
/*====================------------------------------------====================*/
static void      o___PARSE___________________o (void) {;}

char
koios__unit_parse_default   (char a_list)
{
   char        x_verb      [LEN_LABEL] = "";
   char        x_indx      =    0;
   char        x_spec      =  '-';
   void       *x_conv      = NULL;
   void       *x_code      = NULL;
   char        x_vers      =   -1;
   char        x_stage     [LEN_SHORT] = "";
   char        x_desc      [LEN_LONG]  = "";
   char        x_meth      [LEN_HUND]  = "";
   char        x_args      [LEN_FULL]  = "";
   char        x_test      [LEN_LABEL] = "";
   char        x_expe      [LEN_RECD]  = "";
   char        x_retn      [LEN_FULL]  = "";
   char        x_mark      =  '-';
   char        x_share     =  '-';

   yUNIT_minscrp ("PARSE_default");
   if (a_list == 'y')  return 0;
   yURG_err_none ();
   rm_working_files ();
   PROG__unit_quiet  ();

   yUNIT_mincond  ("verify a quick success");
   yUNIT_minval   ("call default"                       , PARSE_default   (x_verb, &x_spec, &x_conv, &x_code, x_stage, &x_vers, x_desc, x_meth, x_args, x_test, x_expe, x_retn, &x_mark, &x_share),    0);
   yUNIT_minstr   ("... check verb"                     , x_verb        , "");
   yUNIT_minchr   ("... check spec"                     , x_spec        , '-');
   yUNIT_minpoint ("... check conv"                     , x_conv        , NULL);
   yUNIT_minpoint ("... check code"                     , x_code        , NULL);
   yUNIT_minstr   ("... check stage"                    , x_stage       , "");
   yUNIT_minval   ("... check vers"                     , x_vers        , -1);
   yUNIT_minstr   ("... check desc"                     , x_desc        , "");
   yUNIT_minstr   ("... check meth"                     , x_meth        , "");
   yUNIT_minstr   ("... check args"                     , x_args        , "");
   yUNIT_minstr   ("... check test"                     , x_test        , "");
   yUNIT_minstr   ("... check expe"                     , x_expe        , "");
   yUNIT_minstr   ("... check retn"                     , x_retn        , "");
   yUNIT_minchr   ("... check mark"                     , x_mark        , '-');
   yUNIT_minchr   ("... check share"                    , x_share       , '-');
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify nulling elements");
   yUNIT_minval   ("call default"                       , PARSE_default   (NULL  , &x_spec, &x_conv, &x_code, x_stage, &x_vers, x_desc, x_meth, x_args, x_test, x_expe, x_retn, &x_mark, &x_share),    0);
   yUNIT_minval   ("call default"                       , PARSE_default   (x_verb, NULL   , &x_conv, &x_code, x_stage, &x_vers, x_desc, x_meth, x_args, x_test, x_expe, x_retn, &x_mark, &x_share),    0);
   yUNIT_minval   ("call default"                       , PARSE_default   (x_verb, &x_spec, NULL   , &x_code, x_stage, &x_vers, x_desc, x_meth, x_args, x_test, x_expe, x_retn, &x_mark, &x_share),    0);
   yUNIT_minval   ("call default"                       , PARSE_default   (x_verb, &x_spec, &x_conv, NULL   , x_stage, &x_vers, x_desc, x_meth, x_args, x_test, x_expe, x_retn, &x_mark, &x_share),    0);
   yUNIT_minval   ("call default"                       , PARSE_default   (x_verb, &x_spec, &x_conv, &x_code, NULL   , &x_vers, x_desc, x_meth, x_args, x_test, x_expe, x_retn, &x_mark, &x_share),    0);
   yUNIT_minval   ("call default"                       , PARSE_default   (x_verb, &x_spec, &x_conv, &x_code, x_stage, NULL   , x_desc, x_meth, x_args, x_test, x_expe, x_retn, &x_mark, &x_share),    0);
   yUNIT_minval   ("call default"                       , PARSE_default   (x_verb, &x_spec, &x_conv, &x_code, x_stage, &x_vers, NULL  , x_meth, x_args, x_test, x_expe, x_retn, &x_mark, &x_share),    0);
   yUNIT_minval   ("call default"                       , PARSE_default   (x_verb, &x_spec, &x_conv, &x_code, x_stage, &x_vers, x_desc, NULL  , x_args, x_test, x_expe, x_retn, &x_mark, &x_share),    0);
   yUNIT_minval   ("call default"                       , PARSE_default   (x_verb, &x_spec, &x_conv, &x_code, x_stage, &x_vers, x_desc, x_meth, NULL  , x_test, x_expe, x_retn, &x_mark, &x_share),    0);
   yUNIT_minval   ("call default"                       , PARSE_default   (x_verb, &x_spec, &x_conv, &x_code, x_stage, &x_vers, x_desc, x_meth, x_args, NULL  , x_expe, x_retn, &x_mark, &x_share),    0);
   yUNIT_minval   ("call default"                       , PARSE_default   (x_verb, &x_spec, &x_conv, &x_code, x_stage, &x_vers, x_desc, x_meth, x_args, x_test, NULL  , x_retn, &x_mark, &x_share),    0);
   yUNIT_minval   ("call default"                       , PARSE_default   (x_verb, &x_spec, &x_conv, &x_code, x_stage, &x_vers, x_desc, x_meth, x_args, x_test, x_expe, NULL  , &x_mark, &x_share),    0);
   yUNIT_minval   ("call default"                       , PARSE_default   (x_verb, &x_spec, &x_conv, &x_code, x_stage, &x_vers, x_desc, x_meth, x_args, x_test, x_expe, x_retn, NULL   , &x_share),    0);
   yUNIT_minval   ("call default"                       , PARSE_default   (x_verb, &x_spec, &x_conv, &x_code, x_stage, &x_vers, x_desc, x_meth, x_args, x_test, x_expe, x_retn, &x_mark, NULL    ),    0);
   yUNIT_mindnoc  ();

   strcpy (x_verb   , "test");
   x_spec    = 's';
   x_conv    = CONV_scrp;
   x_code    = CODE_scrp;
   strcpy (x_stage  , "2b"  );
   x_vers    = '1';
   x_mark    = '5';
   x_share   = 'f';
   yUNIT_mincond  ("verify prep-related defaulting");
   yUNIT_minval   ("call default"                       , PARSE_default   (x_verb, &x_spec, &x_conv, &x_code, x_stage, &x_vers, x_desc, x_meth, x_args, x_test, x_expe, x_retn, &x_mark, &x_share),    0);
   yUNIT_minstr   ("... check verb"                     , x_verb        , "");
   yUNIT_minchr   ("... check spec"                     , x_spec        , '-');
   yUNIT_minpoint ("... check conv"                     , x_conv        , NULL);
   yUNIT_minpoint ("... check code"                     , x_code        , NULL);
   yUNIT_minstr   ("... check stage"                    , x_stage       , "");
   yUNIT_minval   ("... check vers"                     , x_vers        , -1);
   yUNIT_minstr   ("... check desc"                     , x_desc        , "");
   yUNIT_minstr   ("... check meth"                     , x_meth        , "");
   yUNIT_minstr   ("... check args"                     , x_args        , "");
   yUNIT_minstr   ("... check test"                     , x_test        , "");
   yUNIT_minstr   ("... check expe"                     , x_expe        , "");
   yUNIT_minstr   ("... check retn"                     , x_retn        , "");
   yUNIT_minchr   ("... check mark"                     , x_mark        , '-');
   yUNIT_minchr   ("... check share"                    , x_share       , '-');
   yUNIT_mindnoc  ();

   strcpy (x_desc   , "description");
   strcpy (x_meth   , "method");
   strcpy (x_args   , "arguments");
   strcpy (x_test   , "test");
   strcpy (x_expe   , "expected");
   strcpy (x_retn   , "return");
   yUNIT_mincond  ("verify field-related defaulting");
   yUNIT_minval   ("call default"                       , PARSE_default   (x_verb, &x_spec, &x_conv, &x_code, x_stage, &x_vers, x_desc, x_meth, x_args, x_test, x_expe, x_retn, &x_mark, &x_share),    0);
   yUNIT_minstr   ("... check verb"                     , x_verb        , "");
   yUNIT_minchr   ("... check spec"                     , x_spec        , '-');
   yUNIT_minpoint ("... check conv"                     , x_conv        , NULL);
   yUNIT_minpoint ("... check code"                     , x_code        , NULL);
   yUNIT_minstr   ("... check stage"                    , x_stage       , "");
   yUNIT_minval   ("... check vers"                     , x_vers        , -1);
   yUNIT_minstr   ("... check desc"                     , x_desc        , "");
   yUNIT_minstr   ("... check meth"                     , x_meth        , "");
   yUNIT_minstr   ("... check args"                     , x_args        , "");
   yUNIT_minstr   ("... check test"                     , x_test        , "");
   yUNIT_minstr   ("... check expe"                     , x_expe        , "");
   yUNIT_minstr   ("... check retn"                     , x_retn        , "");
   yUNIT_minchr   ("... check mark"                     , x_mark        , '-');
   yUNIT_minchr   ("... check share"                    , x_share       , '-');
   yUNIT_mindnoc  ();

   PROG__unit_end    ();
   rm_working_files ();
   yUNIT_minprcs ();
   return 0;
}

char
koios__unit_parse_limits  (char a_list)
{
   char        x_min       =    0;
   char        x_max       =    0;

   PROG__unit_quiet  ();
   yUNIT_minscrp ("PARSE__limits");
   if (a_list == 'y')  return 0;
   yURG_err_none ();  /* not to stderr/terminal */
   rm_working_files ();
   PROG__unit_quiet  ();

   yUNIT_mincond  ("verify quick success");
   yUNIT_minval   ("get limits for SCRP"                , PARSE__limits ('s', &x_min, &x_max), 0);
   yUNIT_minval   ("... check min"                      , x_min         , 3);
   yUNIT_minval   ("... check max"                      , x_max         , 5);
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("attempt with missing min");
   yUNIT_minval   ("get limits with a null"             , PARSE__limits ('s', NULL  , &x_max), -999);
   yUNIT_minval   ("... check max"                      , x_max         , 0);
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("attempt with missing max");
   yUNIT_minval   ("get limits with a null"             , PARSE__limits ('s', &x_min, NULL  ), -999);
   yUNIT_minval   ("... check min"                      , x_min         , 0);
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify quick success");
   yUNIT_minval   ("get limits for COND"                , PARSE__limits ('2', &x_min, &x_max), 0);
   yUNIT_minval   ("... check min"                      , x_min         , 2);
   yUNIT_minval   ("... check max"                      , x_max         , 2);
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("attempt with an illegal spec");
   yUNIT_minval   ("get limits for '*'"                 , PARSE__limits ('*', &x_min, &x_max), -999);
   yUNIT_minval   ("... check min"                      , x_min         , 0);
   yUNIT_minval   ("... check max"                      , x_max         , 0);
   yUNIT_mindnoc  ();

   PROG__unit_end    ();
   rm_working_files ();
   yUNIT_minprcs ();
   PROG__unit_end  ();
   return 0;
}

char
koios__unit_parse_current (char a_list)
{
   char        x_spec      =  '-';
   char        x_max       =    0;
   char        x_desc      [LEN_LONG]  = "";
   char        x_meth      [LEN_HUND]  = "";
   char        x_args      [LEN_FULL]  = "";
   char        x_test      [LEN_LABEL] = "";
   char        x_expe      [LEN_RECD]  = "";
   char        x_retn      [LEN_FULL]  = "";

   yUNIT_minscrp ("PARSE__current");
   if (a_list == 'y')  return 0;
   yURG_err_none ();
   rm_working_files ();
   PROG__unit_quiet  ();

   x_spec = 's';  x_max = 2;
   yUNIT_mincond  ("verify script success");
   yUNIT_minval   ("set defaults"                       , PARSE__default  (x_desc, x_meth, x_args, x_test, x_expe, x_retn)                                ,    0);
   yUNIT_minval   ("call parse field"                   , PARSE__current  (1, "SCRP"                     , x_spec, &x_max, x_desc, x_meth, x_args, x_test, x_expe, x_retn), -999);
   yUNIT_minval   ("call parse field"                   , PARSE__current  (2, "check variable"           , x_spec, &x_max, x_desc, x_meth, x_args, x_test, x_expe, x_retn),    0);
   yUNIT_minval   ("call parse field"                   , PARSE__current  (3, "extra"                    , x_spec, &x_max, x_desc, x_meth, x_args, x_test, x_expe, x_retn), -999);
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
   yUNIT_minval   ("call parse field"                   , PARSE__current  (2, "call function"            , x_spec, &x_max, x_desc, x_meth, x_args, x_test, x_expe, x_retn),    0);
   yUNIT_minval   ("call parse field"                   , PARSE__current  (3, "BIG_function"             , x_spec, &x_max, x_desc, x_meth, x_args, x_test, x_expe, x_retn),    0);
   yUNIT_minval   ("call parse field"                   , PARSE__current  (4, "27, 86, 't'"              , x_spec, &x_max, x_desc, x_meth, x_args, x_test, x_expe, x_retn),    0);
   yUNIT_minval   ("call parse field"                   , PARSE__current  (5, "i_equal"                  , x_spec, &x_max, x_desc, x_meth, x_args, x_test, x_expe, x_retn),    0);
   yUNIT_minval   ("call parse field"                   , PARSE__current  (6, "42"                       , x_spec, &x_max, x_desc, x_meth, x_args, x_test, x_expe, x_retn),    0);
   yUNIT_minval   ("call parse field"                   , PARSE__current  (7, "n"                        , x_spec, &x_max, x_desc, x_meth, x_args, x_test, x_expe, x_retn),    0);
   yUNIT_minval   ("call parse field"                   , PARSE__current  (8, "junk at end"              , x_spec, &x_max, x_desc, x_meth, x_args, x_test, x_expe, x_retn), -999);
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
   yUNIT_minval   ("call parse field"                   , PARSE__current  (2, "update global"            , x_spec, &x_max, x_desc, x_meth, x_args, x_test, x_expe, x_retn),    0);
   yUNIT_minval   ("call parse field"                   , PARSE__current  (3, "- - - - - - -"            , x_spec, &x_max, x_desc, x_meth, x_args, x_test, x_expe, x_retn),    0);
   yUNIT_minval   ("call parse field"                   , PARSE__current  (4, "my.val = 978;"            , x_spec, &x_max, x_desc, x_meth, x_args, x_test, x_expe, x_retn),    0);
   yUNIT_minval   ("call parse field"                   , PARSE__current  (5, "more stuff"               , x_spec, &x_max, x_desc, x_meth, x_args, x_test, x_expe, x_retn), -999);
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
   yUNIT_minval   ("call parse field"                   , PARSE__current  (2, "update global"            , x_spec, &x_max, x_desc, x_meth, x_args, x_test, x_expe, x_retn), -999);
   yUNIT_minval   ("... check max"                      , x_max         , 1);
   yUNIT_minstr   ("... check desc"                     , x_desc        , "");
   yUNIT_minstr   ("... check meth"                     , x_meth        , "");
   yUNIT_minstr   ("... check args"                     , x_args        , "");
   yUNIT_minstr   ("... check test"                     , x_test        , "");
   yUNIT_minstr   ("... check expe"                     , x_expe        , "");
   yUNIT_minstr   ("... check retn"                     , x_retn        , "");
   yUNIT_mindnoc  ();

   PROG__unit_end    ();
   rm_working_files ();
   yUNIT_minprcs ();
   return 0;
}

char
koios__unit_parse_prep      (char a_list)
{
   FILE       *x_scrp      = NULL;
   char        x_nscrp     [LEN_HUND]  = "apate.unit";
   char        x_recd      [LEN_RECD]  = "";
   char        x_verb      [LEN_LABEL] = "";
   char        x_spec      =  '-';
   void       *x_conv      = NULL;
   void       *x_code      = NULL;
   char        x_stage     [LEN_SHORT] = "";
   char        x_vers      =   -1;
   char        x_desc      [LEN_LONG]  = "";
   char        x_expe      [LEN_RECD]  = "";
   char        x_dittoing  =  '-';
   char        x_mark      =  '-';
   char        x_dmark     =  '-';
   int         x_ditto     =    0;
   int         x_dline     =    0;
   char        x_share     =  '-';
   char        x_cshare    =  '-';

   yUNIT_minscrp ("PARSE_prep");
   if (a_list == 'y')  return 0;
   yURG_err_none ();
   rm_working_files ();
   PROG__unit_quiet  ();

   strcpy (x_recd, "SCRP    [¡Ï]  (CATS) verify preparation and defaulting                           0s   prepare         CATS__prepare                                                                ((01.---))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_mincond  ("verify scrp in update");
   yUNIT_minval   ("call defaults"                      , PARSE_default   (x_verb, &x_spec, &x_conv, &x_code, x_stage, &x_vers, x_desc, NULL, NULL, NULL, x_expe, NULL, &x_mark, &x_share),    0);
   yUNIT_minval   ("call parse prep"                    , PARSE_prep      (&x_scrp, x_nscrp,  5, G_RUN_UPDATE , x_recd, x_verb, &x_spec, &x_conv, &x_code, x_stage, &x_vers, x_desc, x_expe, &x_dittoing, &x_mark, &x_dmark, &x_ditto, &x_dline, &x_share, &x_cshare),    0);
   yUNIT_minstr   ("... reuses"                         , REUSE__used (), "¥-----¥-----¥-----¥-----¥-   ¥-----¥-----¥-----¥-----¥-");
   yUNIT_minstr   ("... dittos"                         , DITTO__used (), "----------");
   yUNIT_minstr   ("... check verb"                     , x_verb        , "SCRP");
   yUNIT_minchr   ("... check spec"                     , x_spec        , 's');
   yUNIT_minpoint ("... check conv"                     , x_conv        , CONV_scrp);
   yUNIT_minpoint ("... check code"                     , x_code        , CODE_scrp);
   yUNIT_minstr   ("... check stage"                    , x_stage       , "¡Ï");
   yUNIT_minval   ("... check vers"                     , x_vers        , 0);
   yUNIT_minstr   ("... check desc"                     , x_desc        , "");
   yUNIT_minstr   ("... check expe"                     , x_expe        , "");
   yUNIT_minchr   ("... check dittoing"                 , x_dittoing    ,  '-');
   yUNIT_minchr   ("... check mark"                     , x_mark        ,  '-');
   yUNIT_minchr   ("... check dmark"                    , x_dmark       ,  '-');
   yUNIT_minval   ("... check ditto"                    , x_ditto       ,    0);
   yUNIT_minval   ("... check dline"                    , x_dline       ,    0);
   yUNIT_minchr   ("... check share"                    , x_share       ,  '-');
   yUNIT_minchr   ("... check cshare"                   , x_cshare      ,  '-');
   yUNIT_mindnoc  ();

   strcpy (x_recd, "   COND  (0)  check initial environment                                          - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((01.001))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_mincond  ("verify cond in update");
   yUNIT_minval   ("call defaults"                      , PARSE_default   (x_verb, &x_spec, &x_conv, &x_code, x_stage, &x_vers, x_desc, NULL, NULL, NULL, x_expe, NULL, &x_mark, &x_share),    0);
   yUNIT_minval   ("call parse prep"                    , PARSE_prep      (&x_scrp, x_nscrp, 10, G_RUN_UPDATE , x_recd, x_verb, &x_spec, &x_conv, &x_code, x_stage, &x_vers, x_desc, x_expe, &x_dittoing, &x_mark, &x_dmark, &x_ditto, &x_dline, &x_share, &x_cshare),    0);
   yUNIT_minstr   ("... reuses"                         , REUSE__used (), "¥-----¥-----¥-----¥-----¥-   ¥-----¥-----¥-----¥-----¥-");
   yUNIT_minstr   ("... dittos"                         , DITTO__used (), "0---------");
   yUNIT_minstr   ("... check verb"                     , x_verb        , "COND");
   yUNIT_minchr   ("... check spec"                     , x_spec        , '2');
   yUNIT_minpoint ("... check conv"                     , x_conv        , CONV_cond);
   yUNIT_minpoint ("... check code"                     , x_code        , CODE_cond);
   yUNIT_minstr   ("... check stage"                    , x_stage       , "");
   yUNIT_minval   ("... check vers"                     , x_vers        , 0);
   yUNIT_minstr   ("... check desc"                     , x_desc        , "");
   yUNIT_minstr   ("... check expe"                     , x_expe        , "");
   yUNIT_minchr   ("... check dittoing"                 , x_dittoing    ,  '-');
   yUNIT_minchr   ("... check mark"                     , x_mark        ,  '0');
   yUNIT_minchr   ("... check dmark"                    , x_dmark       ,  '-');
   yUNIT_minval   ("... check ditto"                    , x_ditto       ,    0);
   yUNIT_minval   ("... check dline"                    , x_dline       ,    0);
   yUNIT_minchr   ("... check share"                    , x_share       ,  '-');
   yUNIT_minchr   ("... check cshare"                   , x_cshare      ,  '-');
   yUNIT_mindnoc  ();

   strcpy (x_recd, "   DITTO (0)  repeat the condition                                               - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((01.001))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_mincond  ("verify ditto in update");
   yUNIT_minval   ("call defaults"                      , PARSE_default   (x_verb, &x_spec, &x_conv, &x_code, x_stage, &x_vers, x_desc, NULL, NULL, NULL, x_expe, NULL, &x_mark, &x_share),    0);
   yUNIT_minval   ("call parse prep"                    , PARSE_prep      (&x_scrp, x_nscrp, 15, G_RUN_UPDATE , x_recd, x_verb, &x_spec, &x_conv, &x_code, x_stage, &x_vers, x_desc, x_expe, &x_dittoing, &x_mark, &x_dmark, &x_ditto, &x_dline, &x_share, &x_cshare),    1);
   yUNIT_minstr   ("... reuses"                         , REUSE__used (), "¥-----¥-----¥-----¥-----¥-   ¥-----¥-----¥-----¥-----¥-");
   yUNIT_minstr   ("... dittos"                         , DITTO__used (), "0---------");
   yUNIT_minstr   ("... check verb"                     , x_verb        , "DITTO");
   yUNIT_minchr   ("... check spec"                     , x_spec        , '1');
   yUNIT_minpoint ("... check conv"                     , x_conv        , CONV_ditto);
   yUNIT_minpoint ("... check code"                     , x_code        , NULL);
   yUNIT_minstr   ("... check stage"                    , x_stage       , "");
   yUNIT_minval   ("... check vers"                     , x_vers        , 0);
   yUNIT_minstr   ("... check desc"                     , x_desc        , "[ check initial environment ]");
   yUNIT_minstr   ("... check expe"                     , x_expe        , "");
   yUNIT_minchr   ("... check dittoing"                 , x_dittoing    ,  '-');
   yUNIT_minchr   ("... check mark"                     , x_mark        ,  '0');
   yUNIT_minchr   ("... check dmark"                    , x_dmark       ,  '-');
   yUNIT_minval   ("... check ditto"                    , x_ditto       ,    0);
   yUNIT_minval   ("... check dline"                    , x_dline       ,    0);
   yUNIT_minchr   ("... check share"                    , x_share       ,  '-');
   yUNIT_minchr   ("... check cshare"                   , x_cshare      ,  '-');
   yUNIT_mindnoc  ();

   x_ditto = 0; /* simple reset */

   strcpy (x_recd, "   DITTO (0)  repeat the condition                                               - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((01.001))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_mincond  ("verify ditto in creation");
   system ("touch apate.unit           2> /dev/null");
   yUNIT_minval   ("open the script file"               , READ_open   (x_nscrp, 'r', &x_scrp, NULL), 0);
   yUNIT_minval   ("call defaults"                      , PARSE_default   (x_verb, &x_spec, &x_conv, &x_code, x_stage, &x_vers, x_desc, NULL, NULL, NULL, x_expe, NULL, &x_mark, &x_share),    0);
   yUNIT_minval   ("call parse prep"                    , PARSE_prep      (&x_scrp, x_nscrp, 20, G_RUN_CREATE , x_recd, x_verb, &x_spec, &x_conv, &x_code, x_stage, &x_vers, x_desc, x_expe, &x_dittoing, &x_mark, &x_dmark, &x_ditto, &x_dline, &x_share, &x_cshare),    1);
   yUNIT_minstr   ("... reuses"                         , REUSE__used (), "¥-----¥-----¥-----¥-----¥-   ¥-----¥-----¥-----¥-----¥-");
   yUNIT_minstr   ("... dittos"                         , DITTO__used (), "0---------");
   yUNIT_minstr   ("... check verb"                     , x_verb        , "DITTO");
   yUNIT_minchr   ("... check spec"                     , x_spec        , '1');
   yUNIT_minpoint ("... check conv"                     , x_conv        , CONV_ditto);
   yUNIT_minpoint ("... check code"                     , x_code        , NULL);
   yUNIT_minstr   ("... check stage"                    , x_stage       , "");
   yUNIT_minval   ("... check vers"                     , x_vers        , 0);
   yUNIT_minstr   ("... check desc"                     , x_desc        , "[ check initial environment ]");
   yUNIT_minstr   ("... check expe"                     , x_expe        , "");
   yUNIT_minchr   ("... check dittoing"                 , x_dittoing    ,  'y');
   yUNIT_minchr   ("... check mark"                     , x_mark        ,  '0');
   yUNIT_minchr   ("... check dmark"                    , x_dmark       ,  '0');
   yUNIT_minval   ("... check ditto"                    , x_ditto       ,   10);
   yUNIT_minval   ("... check dline"                    , x_dline       ,    0);
   yUNIT_minchr   ("... check share"                    , x_share       ,  '-');
   yUNIT_minchr   ("... check cshare"                   , x_cshare      ,  '-');
   yUNIT_minval   ("close the script file"              , READ_close  (&x_scrp),   0);
   yUNIT_mindnoc  ();

   x_ditto = 0; /* simple reset */
   x_dmark = '-';

   strcpy (x_recd, "SHARED   -g-  reusable code                                                      - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((01.001))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_mincond  ("verify shared in update");
   yUNIT_minval   ("call defaults"                      , PARSE_default   (x_verb, &x_spec, &x_conv, &x_code, x_stage, &x_vers, x_desc, NULL, NULL, NULL, x_expe, NULL, &x_mark, &x_share),    0);
   yUNIT_minval   ("call parse prep"                    , PARSE_prep      (&x_scrp, x_nscrp, 25, G_RUN_UPDATE , x_recd, x_verb, &x_spec, &x_conv, &x_code, x_stage, &x_vers, x_desc, x_expe, &x_dittoing, &x_mark, &x_dmark, &x_ditto, &x_dline, &x_share, &x_cshare),    0);
   yUNIT_minstr   ("... reuses"                         , REUSE__used (), "¥-----¥-----¥-----¥-----¥-   ¥-----g-----¥-----¥-----¥-");
   yUNIT_minstr   ("... dittos (cleared)"               , DITTO__used (), "----------");
   yUNIT_minstr   ("... check verb"                     , x_verb        , "SHARED");
   yUNIT_minchr   ("... check spec"                     , x_spec        , 's');
   yUNIT_minpoint ("... check conv"                     , x_conv        , CONV_shared);
   yUNIT_minpoint ("... check code"                     , x_code        , CODE_shared);
   yUNIT_minstr   ("... check stage"                    , x_stage       , "");
   yUNIT_minval   ("... check vers"                     , x_vers        , 0);
   yUNIT_minstr   ("... check desc"                     , x_desc        , "");
   yUNIT_minstr   ("... check expe"                     , x_expe        , "");
   yUNIT_minchr   ("... check dittoing"                 , x_dittoing    ,  'y');
   yUNIT_minchr   ("... check mark"                     , x_mark        ,  '-');
   yUNIT_minchr   ("... check dmark"                    , x_dmark       ,  '-');
   yUNIT_minval   ("... check ditto"                    , x_ditto       ,    0);
   yUNIT_minval   ("... check dline"                    , x_dline       ,    0);
   yUNIT_minchr   ("... check share"                    , x_share       ,  'g');
   yUNIT_minchr   ("... check cshare"                   , x_cshare      ,  '-');
   yUNIT_mindnoc  ();

   PROG__unit_end    ();
   rm_working_files ();
   yUNIT_minprcs ();
   return 0;
}

char
koios__unit_parse_driver    (char a_list)
{
   char        x_name      [LEN_HUND]  = "apate.unit";
   char        x_recd      [LEN_RECD]  = "";
   char        x_desc      [LEN_LONG]  = "";
   char        x_meth      [LEN_HUND]  = "";
   char        x_args      [LEN_FULL]  = "";
   char        x_test      [LEN_LABEL] = "";
   char        x_expe      [LEN_RECD]  = "";
   char        x_retn      [LEN_FULL]  = "";

   yUNIT_minscrp ("PARSE_driver");
   if (a_list == 'y')  return 0;
   yURG_err_none ();
   rm_working_files ();
   PROG__unit_quiet  ();

   strcpy (x_recd, "SCRP          (CATS) verify preparation and defaulting                           0s   prepare         CATS__prepare                                                                ((01.---))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_mincond  ("verify script success");
   yUNIT_minval   ("call parse"                         , PARSE_driver    (x_name,  5,  0, "SCRP", 's', x_recd, x_desc, x_meth, x_args, x_test, x_expe, x_retn),    0);
   yUNIT_minstr   ("... check desc"                     , x_desc        , "(CATS) verify preparation and defaulting");
   yUNIT_minstr   ("... check meth"                     , x_meth        , "CATS__prepare");
   yUNIT_minstr   ("... check args"                     , x_args        , "");
   yUNIT_minstr   ("... check test"                     , x_test        , "0s");
   yUNIT_minstr   ("... check expe"                     , x_expe        , "");
   yUNIT_minstr   ("... check retn"                     , x_retn        , "prepare");
   yUNIT_mindnoc  ();

   strcpy (x_recd, "   COND  (0)  verify the defaults                                                - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((01.001))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_mincond  ("verify condition success");
   yUNIT_minval   ("call parse"                         , PARSE_driver    (x_name, 10,  0, "COND", '2', x_recd, x_desc, x_meth, x_args, x_test, x_expe, x_retn),    0);
   yUNIT_minstr   ("... check desc"                     , x_desc        , "verify the defaults");
   yUNIT_minstr   ("... check meth"                     , x_meth        , "");
   yUNIT_minstr   ("... check args"                     , x_args        , "");
   yUNIT_minstr   ("... check test"                     , x_test        , "");
   yUNIT_minstr   ("... check expe"                     , x_expe        , "");
   yUNIT_minstr   ("... check retn"                     , x_retn        , "");
   yUNIT_mindnoc  ();

   strcpy (x_recd, "   COND  (0) ");
   yUNIT_mincond  ("attempt with verb only");
   yUNIT_minval   ("call parse"                         , PARSE_driver    (x_name, 10,  0, "COND", '2', x_recd, x_desc, x_meth, x_args, x_test, x_expe, x_retn), -999);
   yUNIT_minstr   ("... check desc"                     , x_desc        , "");
   yUNIT_minstr   ("... check meth"                     , x_meth        , "");
   yUNIT_minstr   ("... check args"                     , x_args        , "");
   yUNIT_minstr   ("... check test"                     , x_test        , "");
   yUNIT_minstr   ("... check expe"                     , x_expe        , "");
   yUNIT_minstr   ("... check retn"                     , x_retn        , "");
   yUNIT_mindnoc  ();

   strcpy (x_recd, "     exec     call prepare                         CATS__prepare               \"∑ ∑  ∑ ∑ ∑   ∑ ∑\"   , &x_len , &x_part, &x_sub , &x_src , &x_cat , &x_page, &x_grp , &x_freq         i_equal     0                                                                                                    ");
   yUNIT_mincond  ("verify exec/get success");
   yUNIT_minval   ("call parse"                         , PARSE_driver    (x_name, 15,  0, "exec", 'f', x_recd, x_desc, x_meth, x_args, x_test, x_expe, x_retn),    0);
   yUNIT_minstr   ("... check desc"                     , x_desc        , "call prepare");
   yUNIT_minstr   ("... check meth"                     , x_meth        , "CATS__prepare");
   yUNIT_minstr   ("... check args"                     , x_args        , "\"∑ ∑  ∑ ∑ ∑   ∑ ∑\"   , &x_len , &x_part, &x_sub , &x_src , &x_cat , &x_page, &x_grp , &x_freq");
   yUNIT_minstr   ("... check test"                     , x_test        , "i_equal");
   yUNIT_minstr   ("... check expe"                     , x_expe        , "0");
   yUNIT_minstr   ("... check retn"                     , x_retn        , "");
   yUNIT_mindnoc  ();

   strcpy (x_recd, "     exec     call prepare                         CATS__prepare              ");
   yUNIT_mincond  ("attempt with not enough fields");
   yUNIT_minval   ("call parse"                         , PARSE_driver    (x_name, 15,  0, "exec", 'f', x_recd, x_desc, x_meth, x_args, x_test, x_expe, x_retn), -999);
   yUNIT_minstr   ("... check desc"                     , x_desc        , "");
   yUNIT_minstr   ("... check meth"                     , x_meth        , "");
   yUNIT_minstr   ("... check args"                     , x_args        , "");
   yUNIT_minstr   ("... check test"                     , x_test        , "");
   yUNIT_minstr   ("... check expe"                     , x_expe        , "");
   yUNIT_minstr   ("... check retn"                     , x_retn        , "");
   yUNIT_mindnoc  ();

   strcpy (x_recd, "     code     ... change part                      - - - - - - - - - - - - -   x_part      = 'v';                                                                                                                                                                                                           ");
   yUNIT_mincond  ("verify code success");
   yUNIT_minval   ("call parse"                         , PARSE_driver    (x_name, 20,  0, "code", 'p', x_recd, x_desc, x_meth, x_args, x_test, x_expe, x_retn),    0);
   yUNIT_minstr   ("... check desc"                     , x_desc        , "... change part");
   yUNIT_minstr   ("... check meth"                     , x_meth        , "");
   yUNIT_minstr   ("... check args"                     , x_args        , "");
   yUNIT_minstr   ("... check test"                     , x_test        , "");
   yUNIT_minstr   ("... check expe"                     , x_expe        , "x_part      = 'v';");
   yUNIT_minstr   ("... check retn"                     , x_retn        , "");
   yUNIT_mindnoc  ();

   strcpy (x_recd, "code         different attempt                       v = 1;  ");
   yUNIT_mincond  ("verify code with wrong indentation");
   yUNIT_minval   ("call parse"                         , PARSE_driver    (x_name, 25,  0, "code", 'p', x_recd, x_desc, x_meth, x_args, x_test, x_expe, x_retn),    0);
   yUNIT_minstr   ("... check desc"                     , x_desc        , "different attempt");
   yUNIT_minstr   ("... check meth"                     , x_meth        , "");
   yUNIT_minstr   ("... check args"                     , x_args        , "");
   yUNIT_minstr   ("... check test"                     , x_test        , "");
   yUNIT_minstr   ("... check expe"                     , x_expe        , "v = 1;");
   yUNIT_minstr   ("... check retn"                     , x_retn        , "");
   yUNIT_mindnoc  ();

   PROG__unit_end    ();
   rm_working_files ();
   yUNIT_minprcs ();
   return 0;
}

char
koios__unit_parse_comment   (char a_list)
{
   char        x_name      [LEN_HUND]  = "apate.unit";
   char        x_recd      [LEN_RECD]  = "";
   char        x_verb      [LEN_LABEL] = "";
   char        x_indx      =    0;
   char        x_spec      =  '-';
   void       *x_conv      = NULL;
   void       *x_code      = NULL;
   char        x_vers      =   -1;
   char        x_stage     [LEN_SHORT] = "";
   char        x_desc      [LEN_LONG]  = "";
   char        x_meth      [LEN_HUND]  = "";
   char        x_args      [LEN_FULL]  = "";
   char        x_test      [LEN_LABEL] = "";
   char        x_expe      [LEN_RECD]  = "";
   char        x_retn      [LEN_FULL]  = "";
   char        x_mark      =  '-';
   char        x_share     =  '-';

   yUNIT_minscrp ("PARSE__comment");
   if (a_list == 'y')  return 0;
   yURG_err_none ();
   rm_working_files ();
   PROG__unit_quiet  ();

   strcpy (x_recd, "#> macro a jklh");
   yUNIT_mincond  ("verify a quick success");
   yUNIT_minval   ("call default"                       , PARSE_default   (x_verb, &x_spec, &x_conv, &x_code, x_stage, &x_vers, x_desc, x_meth, x_args, x_test, x_expe, x_retn, &x_mark, &x_share),    0);
   yUNIT_minval   ("call comment"                       , PARSE__comment  (x_name,  5, x_recd, x_verb, &x_spec, &x_conv, &x_code, x_expe),    1);
   yUNIT_minstr   ("... check verb"                     , x_verb        , "#>");
   yUNIT_minchr   ("... check spec"                     , x_spec        , 'c');
   yUNIT_minpoint ("... check conv"                     , x_conv        , CONV_comment);
   yUNIT_minpoint ("... check code"                     , x_code        , NULL);
   yUNIT_minstr   ("... check stage"                    , x_stage       , "");
   yUNIT_minval   ("... check vers"                     , x_vers        , -1);
   yUNIT_minstr   ("... check meth"                     , x_meth        , "");
   yUNIT_minstr   ("... check args"                     , x_args        , "");
   yUNIT_minstr   ("... check test"                     , x_test        , "");
   yUNIT_minstr   ("... check expe"                     , x_expe        , "#> macro a jklh");
   yUNIT_minstr   ("... check retn"                     , x_retn        , "");
   yUNIT_mindnoc  ();

   strcpy (x_recd, "     code     ... change part                      - - - - - - - - - - - - -   x_part      = 'v';                                                                                                                                                                                                           ");
   yUNIT_mincond  ("attempt on a normal line");
   yUNIT_minval   ("call default"                       , PARSE_default   (x_verb, &x_spec, &x_conv, &x_code, x_stage, &x_vers, x_desc, x_meth, x_args, x_test, x_expe, x_retn, &x_mark, &x_share),    0);
   yUNIT_minval   ("call comment"                       , PARSE__comment  (x_name,  5, x_recd, x_verb, &x_spec, &x_conv, &x_code, x_expe),    0);
   yUNIT_minstr   ("... check verb"                     , x_verb        , "");
   yUNIT_minchr   ("... check spec"                     , x_spec        , '-');
   yUNIT_minpoint ("... check conv"                     , x_conv        , NULL);
   yUNIT_minpoint ("... check code"                     , x_code        , NULL);
   yUNIT_minstr   ("... check stage"                    , x_stage       , "");
   yUNIT_minval   ("... check vers"                     , x_vers        , -1);
   yUNIT_minstr   ("... check meth"                     , x_meth        , "");
   yUNIT_minstr   ("... check args"                     , x_args        , "");
   yUNIT_minstr   ("... check test"                     , x_test        , "");
   yUNIT_minstr   ("... check expe"                     , x_expe        , "");
   yUNIT_minstr   ("... check retn"                     , x_retn        , "");
   yUNIT_mindnoc  ();

   strcpy (x_recd, "     #> insert more code here");
   yUNIT_mincond  ("verify an indented saved comment");
   yUNIT_minval   ("call default"                       , PARSE_default   (x_verb, &x_spec, &x_conv, &x_code, x_stage, &x_vers, x_desc, x_meth, x_args, x_test, x_expe, x_retn, &x_mark, &x_share),    0);
   yUNIT_minval   ("call comment"                       , PARSE__comment  (x_name,  5, x_recd, x_verb, &x_spec, &x_conv, &x_code, x_expe),    1);
   yUNIT_minstr   ("... check verb"                     , x_verb        , "#>");
   yUNIT_minchr   ("... check spec"                     , x_spec        , 'c');
   yUNIT_minpoint ("... check conv"                     , x_conv        , CONV_comment);
   yUNIT_minpoint ("... check code"                     , x_code        , NULL);
   yUNIT_minstr   ("... check stage"                    , x_stage       , "");
   yUNIT_minval   ("... check vers"                     , x_vers        , -1);
   yUNIT_minstr   ("... check meth"                     , x_meth        , "");
   yUNIT_minstr   ("... check args"                     , x_args        , "");
   yUNIT_minstr   ("... check test"                     , x_test        , "");
   yUNIT_minstr   ("... check expe"                     , x_expe        , "     #> insert more code here");
   yUNIT_minstr   ("... check retn"                     , x_retn        , "");
   yUNIT_mindnoc  ();

   strcpy (x_recd, "######> insert more code here");
   yUNIT_mincond  ("attempt on correct comment but without spaces first");
   yUNIT_minval   ("call default"                       , PARSE_default   (x_verb, &x_spec, &x_conv, &x_code, x_stage, &x_vers, x_desc, x_meth, x_args, x_test, x_expe, x_retn, &x_mark, &x_share),    0);
   yUNIT_minval   ("call comment"                       , PARSE__comment  (x_name,  5, x_recd, x_verb, &x_spec, &x_conv, &x_code, x_expe),    0);
   yUNIT_minstr   ("... check verb"                     , x_verb        , "");
   yUNIT_minchr   ("... check spec"                     , x_spec        , '-');
   yUNIT_minpoint ("... check conv"                     , x_conv        , NULL);
   yUNIT_minpoint ("... check code"                     , x_code        , NULL);
   yUNIT_minstr   ("... check stage"                    , x_stage       , "");
   yUNIT_minval   ("... check vers"                     , x_vers        , -1);
   yUNIT_minstr   ("... check meth"                     , x_meth        , "");
   yUNIT_minstr   ("... check args"                     , x_args        , "");
   yUNIT_minstr   ("... check test"                     , x_test        , "");
   yUNIT_minstr   ("... check expe"                     , x_expe        , "");
   yUNIT_minstr   ("... check retn"                     , x_retn        , "");
   yUNIT_mindnoc  ();

   strcpy (x_recd, "## throw away comment ");
   yUNIT_mincond  ("attempt on a normal line");
   yUNIT_minval   ("call default"                       , PARSE_default   (x_verb, &x_spec, &x_conv, &x_code, x_stage, &x_vers, x_desc, x_meth, x_args, x_test, x_expe, x_retn, &x_mark, &x_share),    0);
   yUNIT_minval   ("call comment"                       , PARSE__comment  (x_name,  5, x_recd, x_verb, &x_spec, &x_conv, &x_code, x_expe),    0);
   yUNIT_minstr   ("... check verb"                     , x_verb        , "");
   yUNIT_minchr   ("... check spec"                     , x_spec        , '-');
   yUNIT_minpoint ("... check conv"                     , x_conv        , NULL);
   yUNIT_minpoint ("... check code"                     , x_code        , NULL);
   yUNIT_minstr   ("... check stage"                    , x_stage       , "");
   yUNIT_minval   ("... check vers"                     , x_vers        , -1);
   yUNIT_minstr   ("... check meth"                     , x_meth        , "");
   yUNIT_minstr   ("... check args"                     , x_args        , "");
   yUNIT_minstr   ("... check test"                     , x_test        , "");
   yUNIT_minstr   ("... check expe"                     , x_expe        , "");
   yUNIT_minstr   ("... check retn"                     , x_retn        , "");
   yUNIT_mindnoc  ();

   strcpy (x_recd, ">> wrong prefix");
   yUNIT_mincond  ("attempt on a normal line");
   yUNIT_minval   ("call default"                       , PARSE_default   (x_verb, &x_spec, &x_conv, &x_code, x_stage, &x_vers, x_desc, x_meth, x_args, x_test, x_expe, x_retn, &x_mark, &x_share),    0);
   yUNIT_minval   ("call comment"                       , PARSE__comment  (x_name,  5, x_recd, x_verb, &x_spec, &x_conv, &x_code, x_expe),    0);
   yUNIT_minstr   ("... check verb"                     , x_verb        , "");
   yUNIT_minchr   ("... check spec"                     , x_spec        , '-');
   yUNIT_minpoint ("... check conv"                     , x_conv        , NULL);
   yUNIT_minpoint ("... check code"                     , x_code        , NULL);
   yUNIT_minstr   ("... check stage"                    , x_stage       , "");
   yUNIT_minval   ("... check vers"                     , x_vers        , -1);
   yUNIT_minstr   ("... check meth"                     , x_meth        , "");
   yUNIT_minstr   ("... check args"                     , x_args        , "");
   yUNIT_minstr   ("... check test"                     , x_test        , "");
   yUNIT_minstr   ("... check expe"                     , x_expe        , "");
   yUNIT_minstr   ("... check retn"                     , x_retn        , "");
   yUNIT_mindnoc  ();

   strcpy (x_recd, "   #> script level comment");
   yUNIT_mincond  ("verify an indented saved comment");
   yUNIT_minval   ("call default"                       , PARSE_default   (x_verb, &x_spec, &x_conv, &x_code, x_stage, &x_vers, x_desc, x_meth, x_args, x_test, x_expe, x_retn, &x_mark, &x_share),    0);
   yUNIT_minval   ("call comment"                       , PARSE__comment  (x_name,  5, x_recd, x_verb, &x_spec, &x_conv, &x_code, x_expe),    1);
   yUNIT_minstr   ("... check verb"                     , x_verb        , "#>");
   yUNIT_minchr   ("... check spec"                     , x_spec        , 'c');
   yUNIT_minpoint ("... check conv"                     , x_conv        , CONV_comment);
   yUNIT_minpoint ("... check code"                     , x_code        , NULL);
   yUNIT_minstr   ("... check stage"                    , x_stage       , "");
   yUNIT_minval   ("... check vers"                     , x_vers        , -1);
   yUNIT_minstr   ("... check meth"                     , x_meth        , "");
   yUNIT_minstr   ("... check args"                     , x_args        , "");
   yUNIT_minstr   ("... check test"                     , x_test        , "");
   yUNIT_minstr   ("... check expe"                     , x_expe        , "   #> script level comment");
   yUNIT_minstr   ("... check retn"                     , x_retn        , "");
   yUNIT_mindnoc  ();

   strcpy (x_recd, "#> ");
   yUNIT_mincond  ("verify comment with just the initial space");
   yUNIT_minval   ("call default"                       , PARSE_default   (x_verb, &x_spec, &x_conv, &x_code, x_stage, &x_vers, x_desc, x_meth, x_args, x_test, x_expe, x_retn, &x_mark, &x_share),    0);
   yUNIT_minval   ("call comment"                       , PARSE__comment  (x_name,  5, x_recd, x_verb, &x_spec, &x_conv, &x_code, x_expe),    1);
   yUNIT_minstr   ("... check verb"                     , x_verb        , "#>");
   yUNIT_minchr   ("... check spec"                     , x_spec        , 'c');
   yUNIT_minpoint ("... check conv"                     , x_conv        , CONV_comment);
   yUNIT_minpoint ("... check code"                     , x_code        , NULL);
   yUNIT_minstr   ("... check stage"                    , x_stage       , "");
   yUNIT_minval   ("... check vers"                     , x_vers        , -1);
   yUNIT_minstr   ("... check meth"                     , x_meth        , "");
   yUNIT_minstr   ("... check args"                     , x_args        , "");
   yUNIT_minstr   ("... check test"                     , x_test        , "");
   yUNIT_minstr   ("... check expe"                     , x_expe        , "#> ");
   yUNIT_minstr   ("... check retn"                     , x_retn        , "");
   yUNIT_mindnoc  ();

   PROG__unit_end    ();
   rm_working_files ();
   yUNIT_minprcs ();
   return 0;
}

char
koios__unit_parse_version   (char a_list)
{
   char        x_vers      =  '-';

   yUNIT_minscrp ("PARSE__version");
   if (a_list == 'y')  return 0;
   yURG_err_none ();
   rm_working_files ();
   PROG__unit_quiet  ();

   yUNIT_mincond  ("verify a quick success");
   yUNIT_minval   ("call version"                       , PARSE__version  ("v21"              , &x_vers),    0);
   yUNIT_minval   ("... check version"                  , x_vers        ,  21);
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("attempt a bad version");
   yUNIT_minval   ("call version"                       , PARSE__version  ("v01"              , &x_vers), -999);
   yUNIT_minval   ("... check version"                  , x_vers        ,  -1);
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify current");
   yUNIT_minval   ("call version"                       , PARSE__version  ("check descripion" , &x_vers),    0);
   yUNIT_minval   ("... check version"                  , x_vers        ,   0);
   yUNIT_mindnoc  ();

   PROG__unit_end    ();
   rm_working_files ();
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
   rm_working_files ();
   PROG__unit_quiet  ();

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
   yUNIT_minval  ("... run ∑"                          , DITTO__index ('∑'), -999);
   yUNIT_mindnoc ();

   yUNIT_mincond ("attempt invalid indexes");
   yUNIT_minval  ("... run a"                          , DITTO__index ('a'), -999);
   yUNIT_minval  ("... run D"                          , DITTO__index ('D'), -999);
   yUNIT_minval  ("... run +"                          , DITTO__index ('+'), -999);
   yUNIT_minval  ("... run Í"                          , DITTO__index ('Í'), -999);
   yUNIT_minval  ("... run ¥"                          , DITTO__index ('¥'), -999);
   yUNIT_mindnoc ();

   PROG__unit_end    ();
   rm_working_files ();
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
   rm_working_files ();
   PROG__unit_quiet  ();

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
   yUNIT_minval  ("call set"                           , DITTO__set ('Ú',   1, "verify something")    , -999);
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
   yUNIT_minval  ("call set"                           , DITTO__set_recd ('1', 987,  0, "COND (1)  description field " )    , 0);
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
   yUNIT_minval  ("call set"                           , DITTO__set_recd ('6', 789,  0, "COND (6)        indented        " )    , 0);
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

   PROG__unit_end    ();
   rm_working_files ();
   yUNIT_minprcs ();
   return 0;
}

char
koios__unit_ditto_toggle (char a_list)
{
   char        x_nscrp    [LEN_TITLE] = "apate.unit";
   char        x_name     [LEN_PATH]  = "apate.unit";
   int         x_line     =    1;
   FILE       *x_main     = NULL;
   FILE       *x_scrp     = NULL;
   char        x_dittoing =  '-';
   char        x_mark     =  '-';
   char        x_dmark    =  '-';
   int         x_ditto    =    0;
   int         x_dline    =    0;

   yUNIT_minscrp  ("DITTO_beg, DITTO_end");
   if (a_list == 'y')  return 0;
   yURG_err_none  ();
   rm_working_files ();
   PROG__unit_quiet  ();

   yURG_err_clear ();
   yUNIT_mincond  ("prepare clean start");
   system ("touch apate.unit           2> /dev/null");
   x_main = fopen (x_name, "rt");
   x_scrp = x_main;
   yUNIT_mindnoc  ();

   yURG_err_clear ();
   yUNIT_mincond  ("verify beginning a ditto");
   x_line =  100;  x_dittoing = '-';  x_dmark = '-';  x_mark = '-';  x_ditto =   -1;  x_dline =   -1;
   yUNIT_minval   ("... line"                           , x_line                   ,  100);
   yUNIT_minpoint ("... file"                           , x_scrp                   , x_main);
   yUNIT_minchr   ("... dittoing"                       , x_dittoing               ,  '-');
   yUNIT_minchr   ("... dmark"                          , x_dmark                  ,  '-');
   yUNIT_minchr   ("... mark"                           , x_mark                   ,  '-');
   yUNIT_minval   ("... ditto"                          , x_ditto                  ,   -1);
   yUNIT_minval   ("... dline"                          , x_dline                  ,   -1);
   yUNIT_minval   ("call ditto begin"                   , DITTO_beg   (&x_scrp, x_nscrp, x_line, G_RUN_CREATE , '0',   20, &x_dittoing, &x_mark, &x_dmark, &x_ditto, &x_dline)    , 1);
   yUNIT_minpoint ("... file"                           , x_scrp                   ,    1);
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
   yUNIT_minpoint ("... file"                           , x_scrp                   ,    1);
   yUNIT_minchr   ("... dittoing"                       , x_dittoing               ,  'y');
   yUNIT_minchr   ("... dmark"                          , x_dmark                  ,  '0');
   yUNIT_minchr   ("... mark"                           , x_mark                   ,  '0');
   yUNIT_minval   ("... ditto"                          , x_ditto                  ,   20);
   yUNIT_minval   ("... dline"                          , x_dline                  ,    0);
   yUNIT_minval   ("call ditto begin"                   , DITTO_beg   (&x_scrp, x_nscrp, x_line, G_RUN_CREATE , '0',   20, &x_dittoing, &x_mark, &x_dmark, &x_ditto, &x_dline)    , -999);
   yUNIT_minpoint ("... file"                           , x_scrp                   ,    1);
   yUNIT_minchr   ("... dittoing"                       , x_dittoing               ,  'y');
   yUNIT_minchr   ("... dmark"                          , x_dmark                  ,  '0');
   yUNIT_minchr   ("... mark"                           , x_mark                   ,  '0');
   yUNIT_minval   ("... ditto"                          , x_ditto                  ,   20);
   yUNIT_minval   ("... dline"                          , x_dline                  ,    0);
   yUNIT_minstr   ("... check error message"            , yURG_err_last (), "apate.unit:100:0: error: DITTO '0' can not start as dittoing already active");
   yUNIT_mindnoc  ();

   yURG_err_clear ();
   yUNIT_mincond  ("verify ending a ditto");
   yUNIT_minval   ("... line"                           , x_line                   ,  100);
   yUNIT_minpoint ("... file"                           , x_scrp                   ,    1);
   yUNIT_minchr   ("... dittoing"                       , x_dittoing               ,  'y');
   yUNIT_minchr   ("... dmark"                          , x_dmark                  ,  '0');
   yUNIT_minchr   ("... mark"                           , x_mark                   ,  '0');
   yUNIT_minval   ("... ditto"                          , x_ditto                  ,   20);
   yUNIT_minval   ("... dline"                          , x_dline                  ,    0);
   yUNIT_minval   ("call ditto end"                     , DITTO_end   (&x_scrp, &x_dittoing, &x_dmark, &x_ditto, &x_dline)    , 1);
   yUNIT_minval   ("... line"                           , x_line                   ,  100);
   yUNIT_minpoint ("... file"                           , x_scrp                   , x_main);
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
   yUNIT_minpoint ("... file"                           , x_scrp                   , x_main);
   yUNIT_minchr   ("... dittoing"                       , x_dittoing               ,  '-');
   yUNIT_minchr   ("... dmark"                          , x_dmark                  ,  '-');
   yUNIT_minchr   ("... mark"                           , x_mark                   ,  '0');
   yUNIT_minval   ("... ditto"                          , x_ditto                  ,   -1);
   yUNIT_minval   ("... dline"                          , x_dline                  ,   -1);
   yUNIT_minval   ("call ditto end"                     , DITTO_end   (&x_scrp, &x_dittoing, &x_dmark, &x_ditto, &x_dline)    , 0);
   yUNIT_minval   ("... line"                           , x_line                   ,  100);
   yUNIT_minpoint ("... file"                           , x_scrp                   , x_main);
   yUNIT_minchr   ("... dittoing"                       , x_dittoing               ,  '-');
   yUNIT_minchr   ("... dmark"                          , x_dmark                  ,  '-');
   yUNIT_minchr   ("... mark"                           , x_mark                   ,  '0');
   yUNIT_minval   ("... ditto"                          , x_ditto                  ,   -1);
   yUNIT_minval   ("... dline"                          , x_dline                  ,   -1);
   yUNIT_mindnoc  ();

   yURG_err_clear ();
   yUNIT_mincond  ("attempt to start ditto on bad identifier");
   yUNIT_minval   ("... line"                           , x_line                   ,  100);
   yUNIT_minpoint ("... file"                           , x_scrp                   , x_main);
   yUNIT_minchr   ("... dittoing"                       , x_dittoing               ,  '-');
   yUNIT_minchr   ("... dmark"                          , x_dmark                  ,  '-');
   yUNIT_minchr   ("... mark"                           , x_mark                   ,  '0');
   yUNIT_minval   ("... ditto"                          , x_ditto                  ,   -1);
   yUNIT_minval   ("... dline"                          , x_dline                  ,   -1);
   yUNIT_minval   ("call ditto begin"                   , DITTO_beg   (&x_scrp, x_nscrp, x_line, G_RUN_CREATE , '5',   -1, &x_dittoing, &x_mark, &x_dmark, &x_ditto, &x_dline)    , -999);
   yUNIT_minval   ("... line"                           , x_line                   ,  100);
   yUNIT_minpoint ("... file"                           , x_scrp                   , x_main);
   yUNIT_minchr   ("... dittoing"                       , x_dittoing               ,  '-');
   yUNIT_minchr   ("... dmark"                          , x_dmark                  ,  '-');
   yUNIT_minchr   ("... mark"                           , x_mark                   ,  '0');
   yUNIT_minval   ("... ditto"                          , x_ditto                  ,   -1);
   yUNIT_minval   ("... dline"                          , x_dline                  ,   -1);
   yUNIT_minstr   ("... check error message"            , yURG_err_last (), "apate.unit:100:0: error: DITTO '5' not set by previous COND");

   yURG_err_clear ();
   yUNIT_mincond ("wrap up");
   fclose (x_main);
   yUNIT_mindnoc  ();

   PROG__unit_quiet  ();
   rm_working_files ();
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
   rm_working_files ();
   PROG__unit_quiet  ();

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

   PROG__unit_end    ();
   rm_working_files ();
   yUNIT_minprcs ();
   return 0;
}

char
koios__unit_ditto_parse  (char a_list)
{
   char         x_nscrp    [LEN_LABEL] = "apate.unit";
   FILE        *x_scrp     = NULL;
   int          x_nline    =    0;
   char         x_dittoing =  '-';
   char         x_mark     =  '-';
   char         x_dmark    =  '-';
   int          x_ditto    =   -1;
   int          x_dline    =   -1;
   int          x_nrecd    =    0;
   char         x_recd     [LEN_RECD] = "";
   char         x_back     [LEN_RECD] = "";
   char        *p          = NULL;
   char         x_desc     [LEN_LONG] = "";

   yUNIT_minscrp ("DITTO_parse_handler");
   if (a_list == 'y')  return 0;
   yURG_err_none  ();
   rm_working_files ();
   PROG__unit_quiet  ();

   yUNIT_mincond  ("create a test script");
   system ("echo \"\"                                                                                                                        > apate.unit");
   system ("echo \"COND  (3)  ditto stuff     \"                                                                                        >> apate.unit");
   system ("echo \"  exec     read a line      SCRP_read       i_lesser    0      \"                                            >> apate.unit");
   system ("echo \"\"                                                                                                                       >> apate.unit");
   system ("echo \"DITTO (3)  junk text       \"                                                                                        >> apate.unit");
   system ("echo \"\"                                                                                                                       >> apate.unit");
   system ("echo \"  get      next step        SCRP_read       i_lesser    0      \"                                            >> apate.unit");
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("prepare for conversion run");
   yUNIT_minval   ("open the script file"               , READ_open   (x_nscrp, 'r', &x_scrp, &x_nline), 0);
   yUNIT_minval   ("... init"                           , DITTO_init ()       , 0);
   yUNIT_minstr   ("... review"                         , DITTO__used ()      , "----------");
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify a new ditto mark");
   yUNIT_minval   ("call default"                       , PARSE_default   (NULL  , NULL   , NULL   , NULL   , NULL   , NULL   , x_desc, NULL  , NULL  , NULL  , NULL  , NULL  , NULL   , NULL    ),    0);
   yUNIT_minval   ("read a line"                        , READ_next           (&x_scrp, &x_nline, &x_dittoing, &x_dmark, &x_ditto, &x_dline, &x_nrecd, x_recd),    1);
   strcpy (x_back, x_recd);
   p = strtok (x_back, "");
   yUNIT_minval   ("call parse"                         , DITTO_parse_handler (&x_scrp, x_nscrp, x_nline, G_RUN_UPDATE, "COND"  ,  0, x_recd, p, x_desc, &x_dittoing, &x_mark, &x_dmark, &x_ditto, &x_dline),    0);
   yUNIT_minstr   ("... review"                         , DITTO__used ()      , "---3------");
   yUNIT_minval   ("... nline"                          , x_nline                  ,    2);
   yUNIT_minstr   ("... desc"                           , x_desc                   ,   "");
   yUNIT_minchr   ("... dittoing"                       , x_dittoing               ,  '-');
   yUNIT_minchr   ("... mark"                           , x_mark                   ,  '3');
   yUNIT_minchr   ("... dmark"                          , x_dmark                  ,  '-');
   yUNIT_minval   ("... ditto"                          , x_ditto                  ,   -1);
   yUNIT_minval   ("... dline"                          , x_dline                  ,   -1);
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify passing over exec line");
   yUNIT_minval   ("call default"                       , PARSE_default   (NULL  , NULL   , NULL   , NULL   , NULL   , NULL   , x_desc, NULL  , NULL  , NULL  , NULL  , NULL  , NULL   , NULL    ),    0);
   yUNIT_minval   ("read a line"                        , READ_next           (&x_scrp, &x_nline, &x_dittoing, &x_dmark, &x_ditto, &x_dline, &x_nrecd, x_recd),    1);
   strcpy (x_back, x_recd);
   p = strtok (x_back, "");
   yUNIT_minval   ("call parse"                         , DITTO_parse_handler (&x_scrp, x_nscrp, x_nline, G_RUN_UPDATE, "exec"  ,  0, x_recd, p, x_desc, &x_dittoing, &x_mark, &x_dmark, &x_ditto, &x_dline),    0);
   yUNIT_minstr   ("... review"                         , DITTO__used ()      , "---3------");
   yUNIT_minval   ("... nline"                          , x_nline                  ,    3);
   yUNIT_minstr   ("... desc"                           , x_desc                   ,   "");
   yUNIT_minchr   ("... dittoing"                       , x_dittoing               ,  '-');
   yUNIT_minchr   ("... mark"                           , x_mark                   ,  '-');
   yUNIT_minchr   ("... dmark"                          , x_dmark                  ,  '-');
   yUNIT_minval   ("... ditto"                          , x_ditto                  ,   -1);
   yUNIT_minval   ("... dline"                          , x_dline                  ,   -1);
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify using the ditto mark");
   yUNIT_minval   ("call default"                       , PARSE_default   (NULL  , NULL   , NULL   , NULL   , NULL   , NULL   , x_desc, NULL  , NULL  , NULL  , NULL  , NULL  , NULL   , NULL    ),    0);
   yUNIT_minval   ("read a line"                        , READ_next           (&x_scrp, &x_nline, &x_dittoing, &x_dmark, &x_ditto, &x_dline, &x_nrecd, x_recd),    1);
   strcpy (x_back, x_recd);
   p = strtok (x_back, "");
   yUNIT_minval   ("call parse"                         , DITTO_parse_handler (&x_scrp, x_nscrp, x_nline, G_RUN_UPDATE, "DITTO" ,  0, x_recd, p, x_desc, &x_dittoing, &x_mark, &x_dmark, &x_ditto, &x_dline),    1);
   yUNIT_minstr   ("... review"                         , DITTO__used ()      , "---3------");
   yUNIT_minval   ("... nline"                          , x_nline                  ,    5);
   yUNIT_minstr   ("... desc"                           , x_desc                   ,   "[ ditto stuff ]");
   yUNIT_minchr   ("... dittoing"                       , x_dittoing               ,  '-');
   yUNIT_minchr   ("... mark"                           , x_mark                   ,  '3');
   yUNIT_minchr   ("... dmark"                          , x_dmark                  ,  '-');
   yUNIT_minval   ("... ditto"                          , x_ditto                  ,   -1);
   yUNIT_minval   ("... dline"                          , x_dline                  ,   -1);
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify continuing on in UPDATE mode");
   yUNIT_minval   ("call default"                       , PARSE_default   (NULL  , NULL   , NULL   , NULL   , NULL   , NULL   , x_desc, NULL  , NULL  , NULL  , NULL  , NULL  , NULL   , NULL    ),    0);
   yUNIT_minval   ("read a line"                        , READ_next           (&x_scrp, &x_nline, &x_dittoing, &x_dmark, &x_ditto, &x_dline, &x_nrecd, x_recd),    1);
   strcpy (x_back, x_recd);
   p = strtok (x_back, "");
   yUNIT_minval   ("call parse"                         , DITTO_parse_handler (&x_scrp, x_nscrp, x_nline, G_RUN_UPDATE, "get"   ,  0, x_recd, p, x_desc, &x_dittoing, &x_mark, &x_dmark, &x_ditto, &x_dline),    0);
   yUNIT_minstr   ("... review"                         , DITTO__used ()      , "---3------");
   yUNIT_minval   ("... nline"                          , x_nline                  ,    7);
   yUNIT_minstr   ("... desc"                           , x_desc                   ,   "");
   yUNIT_minchr   ("... dittoing"                       , x_dittoing               ,  '-');
   yUNIT_minchr   ("... mark"                           , x_mark                   ,  '-');
   yUNIT_minchr   ("... dmark"                          , x_dmark                  ,  '-');
   yUNIT_minval   ("... ditto"                          , x_ditto                  ,   -1);
   yUNIT_minval   ("... dline"                          , x_dline                  ,   -1);
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("close conversion run");
   yUNIT_minval   ("close the script file"              , READ_close  (&x_scrp)    ,    0);
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("prepare for code run");
   yUNIT_minval   ("open the script file"               , READ_open   (x_nscrp, 'r', &x_scrp, &x_nline), 0);
   yUNIT_minval   ("... init"                           , DITTO_init ()       , 0);
   yUNIT_minstr   ("... review"                         , DITTO__used ()      , "----------");
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify a new ditto mark");
   yUNIT_minval   ("call default"                       , PARSE_default   (NULL  , NULL   , NULL   , NULL   , NULL   , NULL   , x_desc, NULL  , NULL  , NULL  , NULL  , NULL  , NULL   , NULL    ),    0);
   yUNIT_minval   ("read a line"                        , READ_next           (&x_scrp, &x_nline, &x_dittoing, &x_dmark, &x_ditto, &x_dline, &x_nrecd, x_recd),    1);
   strcpy (x_back, x_recd);
   p = strtok (x_back, "");
   yUNIT_minval   ("call parse"                         , DITTO_parse_handler (&x_scrp, x_nscrp, x_nline, G_RUN_CREATE, "COND"  ,  0, x_recd, p, x_desc, &x_dittoing, &x_mark, &x_dmark, &x_ditto, &x_dline),    0);
   yUNIT_minstr   ("... review"                         , DITTO__used ()      , "---3------");
   yUNIT_minval   ("... nline"                          , x_nline                  ,    2);
   yUNIT_minstr   ("... desc"                           , x_desc                   ,   "");
   yUNIT_minchr   ("... dittoing"                       , x_dittoing               ,  '-');
   yUNIT_minchr   ("... mark"                           , x_mark                   ,  '3');
   yUNIT_minchr   ("... dmark"                          , x_dmark                  ,  '-');
   yUNIT_minval   ("... ditto"                          , x_ditto                  ,   -1);
   yUNIT_minval   ("... dline"                          , x_dline                  ,   -1);
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify passing over exec line");
   yUNIT_minval   ("call default"                       , PARSE_default   (NULL  , NULL   , NULL   , NULL   , NULL   , NULL   , x_desc, NULL  , NULL  , NULL  , NULL  , NULL  , NULL   , NULL    ),    0);
   yUNIT_minval   ("read a line"                        , READ_next           (&x_scrp, &x_nline, &x_dittoing, &x_dmark, &x_ditto, &x_dline, &x_nrecd, x_recd),    1);
   strcpy (x_back, x_recd);
   p = strtok (x_back, "");
   yUNIT_minval   ("call parse"                         , DITTO_parse_handler (&x_scrp, x_nscrp, x_nline, G_RUN_CREATE, "exec"  ,  0, x_recd, p, x_desc, &x_dittoing, &x_mark, &x_dmark, &x_ditto, &x_dline),    0);
   yUNIT_minstr   ("... review"                         , DITTO__used ()      , "---3------");
   yUNIT_minval   ("... nline"                          , x_nline                  ,    3);
   yUNIT_minstr   ("... desc"                           , x_desc                   ,   "");
   yUNIT_minchr   ("... dittoing"                       , x_dittoing               ,  '-');
   yUNIT_minchr   ("... mark"                           , x_mark                   ,  '-');
   yUNIT_minchr   ("... dmark"                          , x_dmark                  ,  '-');
   yUNIT_minval   ("... ditto"                          , x_ditto                  ,   -1);
   yUNIT_minval   ("... dline"                          , x_dline                  ,   -1);
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify using the ditto mark");
   yUNIT_minval   ("call default"                       , PARSE_default   (NULL  , NULL   , NULL   , NULL   , NULL   , NULL   , x_desc, NULL  , NULL  , NULL  , NULL  , NULL  , NULL   , NULL    ),    0);
   yUNIT_minval   ("read a line"                        , READ_next           (&x_scrp, &x_nline, &x_dittoing, &x_dmark, &x_ditto, &x_dline, &x_nrecd, x_recd),    1);
   strcpy (x_back, x_recd);
   p = strtok (x_back, "");
   yUNIT_minval   ("call parse"                         , DITTO_parse_handler (&x_scrp, x_nscrp, x_nline, G_RUN_CREATE, "DITTO" ,  0, x_recd, p, x_desc, &x_dittoing, &x_mark, &x_dmark, &x_ditto, &x_dline),    1);
   yUNIT_minstr   ("... review"                         , DITTO__used ()      , "---3------");
   yUNIT_minval   ("... nline"                          , x_nline                  ,    5);
   yUNIT_minstr   ("... desc"                           , x_desc                   ,   "[ ditto stuff ]");
   yUNIT_minchr   ("... dittoing"                       , x_dittoing               ,  'y');
   yUNIT_minchr   ("... mark"                           , x_mark                   ,  '3');
   yUNIT_minchr   ("... dmark"                          , x_dmark                  ,  '3');
   yUNIT_minval   ("... ditto"                          , x_ditto                  ,    2);
   yUNIT_minval   ("... dline"                          , x_dline                  ,    0);
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify pushing to the first line");
   yUNIT_minval   ("call default"                       , PARSE_default   (NULL  , NULL   , NULL   , NULL   , NULL   , NULL   , x_desc, NULL  , NULL  , NULL  , NULL  , NULL  , NULL   , NULL    ),    0);
   yUNIT_minval   ("read a line"                        , READ_next           (&x_scrp, &x_nline, &x_dittoing, &x_dmark, &x_ditto, &x_dline, &x_nrecd, x_recd),    1);
   strcpy (x_back, x_recd);
   p = strtok (x_back, "");
   yUNIT_minval   ("call parse"                         , DITTO_parse_handler (&x_scrp, x_nscrp, x_nline, G_RUN_CREATE, "COND"  ,  0, x_recd, p, x_desc, &x_dittoing, &x_mark, &x_dmark, &x_ditto, &x_dline),    0);
   yUNIT_minstr   ("... review"                         , DITTO__used ()      , "---3------");
   yUNIT_minval   ("... nline"                          , x_nline                  ,    5);
   yUNIT_minstr   ("... desc"                           , x_desc                   ,   "");
   yUNIT_minchr   ("... dittoing"                       , x_dittoing               ,  'y');
   yUNIT_minchr   ("... mark"                           , x_mark                   ,  '-');
   yUNIT_minchr   ("... dmark"                          , x_dmark                  ,  '3');
   yUNIT_minval   ("... ditto"                          , x_ditto                  ,    2);
   yUNIT_minval   ("... dline"                          , x_dline                  ,    2);
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify passing over exec line");
   yUNIT_minval   ("call default"                       , PARSE_default   (NULL  , NULL   , NULL   , NULL   , NULL   , NULL   , x_desc, NULL  , NULL  , NULL  , NULL  , NULL  , NULL   , NULL    ),    0);
   yUNIT_minval   ("read a line"                        , READ_next           (&x_scrp, &x_nline, &x_dittoing, &x_dmark, &x_ditto, &x_dline, &x_nrecd, x_recd),    1);
   strcpy (x_back, x_recd);
   p = strtok (x_back, "");
   yUNIT_minval   ("call parse"                         , DITTO_parse_handler (&x_scrp, x_nscrp, x_nline, G_RUN_CREATE, "exec"  ,  0, x_recd, p, x_desc, &x_dittoing, &x_mark, &x_dmark, &x_ditto, &x_dline),    0);
   yUNIT_minstr   ("... review"                         , DITTO__used ()      , "---3------");
   yUNIT_minval   ("... nline"                          , x_nline                  ,    5);
   yUNIT_minstr   ("... desc"                           , x_desc                   ,   "");
   yUNIT_minchr   ("... dittoing"                       , x_dittoing               ,  'y');
   yUNIT_minchr   ("... mark"                           , x_mark                   ,  '-');
   yUNIT_minchr   ("... dmark"                          , x_dmark                  ,  '3');
   yUNIT_minval   ("... ditto"                          , x_ditto                  ,    2);
   yUNIT_minval   ("... dline"                          , x_dline                  ,    3);
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify returning after DITTO line");
   yUNIT_minval   ("call default"                       , PARSE_default   (NULL  , NULL   , NULL   , NULL   , NULL   , NULL   , x_desc, NULL  , NULL  , NULL  , NULL  , NULL  , NULL   , NULL    ),    0);
   yUNIT_minval   ("read a line"                        , READ_next           (&x_scrp, &x_nline, &x_dittoing, &x_dmark, &x_ditto, &x_dline, &x_nrecd, x_recd),    1);
   strcpy (x_back, x_recd);
   p = strtok (x_back, "");
   yUNIT_minval   ("call parse"                         , DITTO_parse_handler (&x_scrp, x_nscrp, x_nline, G_RUN_CREATE, "get"   ,  0, x_recd, p, x_desc, &x_dittoing, &x_mark, &x_dmark, &x_ditto, &x_dline),    0);
   yUNIT_minstr   ("... review"                         , DITTO__used ()      , "---3------");
   yUNIT_minval   ("... nline"                          , x_nline                  ,    7);
   yUNIT_minstr   ("... desc"                           , x_desc                   ,   "");
   yUNIT_minchr   ("... dittoing"                       , x_dittoing               ,  '-');
   yUNIT_minchr   ("... mark"                           , x_mark                   ,  '-');
   yUNIT_minchr   ("... dmark"                          , x_dmark                  ,  '-');
   yUNIT_minval   ("... ditto"                          , x_ditto                  ,   -1);
   yUNIT_minval   ("... dline"                          , x_dline                  ,   -1);
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("close update run");
   yUNIT_minval   ("close the script file"              , READ_close  (&x_scrp)    ,    0);
   yUNIT_mindnoc  ();

   PROG__unit_end    ();
   rm_working_files ();
   yUNIT_minprcs  ();
   return 0;
}



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
   rm_working_files ();
   PROG__unit_quiet  ();

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
   yUNIT_minval  ("... run ∑"                          , REUSE__index (T_MASTER, '∑'), -999);
   yUNIT_mindnoc ();

   yUNIT_mincond ("attempt invalid indexes");
   yUNIT_minval  ("... run a"                          , REUSE__index (T_MASTER, 'a'), -999);
   yUNIT_minval  ("... run ?"                          , REUSE__index (T_MASTER, '5'), -999);
   yUNIT_minval  ("... run +"                          , REUSE__index (T_MASTER, '+'), -999);
   yUNIT_minval  ("... run Í"                          , REUSE__index (T_MASTER, 'Í'), -999);
   yUNIT_minval  ("... run ¥"                          , REUSE__index (T_MASTER, '¥'), -999);
   yUNIT_minval  ("... run a"                          , REUSE__index (T_SHARES, 'A'), -999);
   yUNIT_minval  ("... run ?"                          , REUSE__index (T_SHARES, '5'), -999);
   yUNIT_minval  ("... run +"                          , REUSE__index (T_SHARES, '+'), -999);
   yUNIT_minval  ("... run Í"                          , REUSE__index (T_SHARES, 'Í'), -999);
   yUNIT_minval  ("... run ¥"                          , REUSE__index (T_SHARES, '¥'), -999);
   yUNIT_mindnoc ();

   PROG__unit_end    ();
   rm_working_files ();
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
   rm_working_files ();
   PROG__unit_quiet  ();

   yUNIT_mincond ("verify clean start");
   yUNIT_minval  ("... init"                           , REUSE_init ()       , 0);
   yUNIT_minstr  ("... review"                         , REUSE__used ()      , "¥-----¥-----¥-----¥-----¥-   ¥-----¥-----¥-----¥-----¥-");
   yUNIT_minval  ("call get NULL"                      , REUSE__get (T_MASTER,  0 , x_desc, NULL, NULL)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get ?"                         , REUSE__get (T_SHARES, '?', x_desc, NULL, NULL)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get A"                         , REUSE__get (T_MASTER, 'A', x_desc, NULL, NULL)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get f"                         , REUSE__get (T_SHARES, 'f', x_desc, NULL, NULL)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get K"                         , REUSE__get (T_MASTER, 'K', x_desc, NULL, NULL)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get z"                         , REUSE__get (T_SHARES, 'z', x_desc, NULL, NULL)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get M"                         , REUSE__get (T_MASTER, 'M', x_desc, NULL, NULL)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get -"                         , REUSE__get (T_SHARES, '-', x_desc, NULL, NULL)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get a"                         , REUSE__get (T_MASTER, 'a', x_desc, NULL, NULL)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get 5"                         , REUSE__get (T_MASTER, '5', x_desc, NULL, NULL)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify setting a reuse mark");
   yUNIT_minval  ("call set"                           , REUSE__set (T_MASTER, 'A', 123, "verify something")    , 0);
   yUNIT_minstr  ("... review"                         , REUSE__used ()      , "A-----¥-----¥-----¥-----¥-   ¥-----¥-----¥-----¥-----¥-");
   yUNIT_minval  ("call get A"                         , REUSE__get (T_MASTER, 'A', x_desc, NULL, NULL)         ,  123);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "verify something");
   yUNIT_minval  ("call get f"                         , REUSE__get (T_SHARES, 'f', x_desc, NULL, NULL)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get K"                         , REUSE__get (T_MASTER, 'K', x_desc, NULL, NULL)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get z"                         , REUSE__get (T_SHARES, 'z', x_desc, NULL, NULL)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get M"                         , REUSE__get (T_MASTER, 'M', x_desc, NULL, NULL)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get p"                         , REUSE__get (T_SHARES, 'p', x_desc, NULL, NULL)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify re-setting a reuse mark");
   yUNIT_minval  ("call set"                           , REUSE__set (T_MASTER, 'A',  52, "check other"     )    , 0);
   yUNIT_minstr  ("... review"                         , REUSE__used ()      , "A-----¥-----¥-----¥-----¥-   ¥-----¥-----¥-----¥-----¥-");
   yUNIT_minval  ("call get A"                         , REUSE__get (T_MASTER, 'A', x_desc, NULL, NULL)         ,   52);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "check other");
   yUNIT_minval  ("call get f"                         , REUSE__get (T_SHARES, 'f', x_desc, NULL, NULL)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get K"                         , REUSE__get (T_MASTER, 'K', x_desc, NULL, NULL)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get z"                         , REUSE__get (T_SHARES, 'z', x_desc, NULL, NULL)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get M"                         , REUSE__get (T_MASTER, 'M', x_desc, NULL, NULL)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get p"                         , REUSE__get (T_SHARES, 'p', x_desc, NULL, NULL)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("attempt to set illegal marks");
   yUNIT_minval  ("call set"                           , REUSE__set (T_MASTER, '/',   1, "verify something")    , -999);
   yUNIT_minval  ("call set"                           , REUSE__set (T_MASTER, 'a',   1, "verify something")    , -999);
   yUNIT_minval  ("call set"                           , REUSE__set (T_MASTER, '5',   1, "verify something")    , -999);
   yUNIT_minval  ("call set"                           , REUSE__set (T_MASTER, 'Ú',   1, "verify something")    , -999);
   yUNIT_minstr  ("... review"                         , REUSE__used ()      , "A-----¥-----¥-----¥-----¥-   ¥-----¥-----¥-----¥-----¥-");
   yUNIT_minval  ("call get A"                         , REUSE__get (T_MASTER, 'A', x_desc, NULL, NULL)         ,   52);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "check other");
   yUNIT_minval  ("call get f"                         , REUSE__get (T_SHARES, 'f', x_desc, NULL, NULL)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get K"                         , REUSE__get (T_MASTER, 'K', x_desc, NULL, NULL)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get z"                         , REUSE__get (T_SHARES, 'z', x_desc, NULL, NULL)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get M"                         , REUSE__get (T_MASTER, 'M', x_desc, NULL, NULL)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get p"                         , REUSE__get (T_SHARES, 'p', x_desc, NULL, NULL)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify setting another reuse mark");
   yUNIT_minval  ("call set"                           , REUSE__set (T_SHARES, 'z',  22, "monster trouble" )    , 0);
   yUNIT_minstr  ("... review"                         , REUSE__used ()      , "A-----¥-----¥-----¥-----¥-   ¥-----¥-----¥-----¥-----¥z");
   yUNIT_minval  ("call get A"                         , REUSE__get (T_MASTER, 'A', x_desc, NULL, NULL)         ,   52);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "check other");
   yUNIT_minval  ("call get f"                         , REUSE__get (T_SHARES, 'f', x_desc, NULL, NULL)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get K"                         , REUSE__get (T_MASTER, 'K', x_desc, NULL, NULL)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get z"                         , REUSE__get (T_SHARES, 'z', x_desc, NULL, NULL)         ,   22);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "monster trouble");
   yUNIT_minval  ("call get M"                         , REUSE__get (T_MASTER, 'M', x_desc, NULL, NULL)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get p"                         , REUSE__get (T_SHARES, 'p', x_desc, NULL, NULL)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify setting two more");
   yUNIT_minval  ("call set"                           , REUSE__set (T_SHARES, 'f',   8, NULL              )    , 0);
   yUNIT_minval  ("call set"                           , REUSE__set (T_MASTER, 'M',1000, "!"               )    , 0);
   yUNIT_minstr  ("... review"                         , REUSE__used ()      , "A-----¥-----M-----¥-----¥-   ¥----f¥-----¥-----¥-----¥z");
   yUNIT_minval  ("call get A"                         , REUSE__get (T_MASTER, 'A', x_desc, NULL, NULL)         ,   52);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "check other");
   yUNIT_minval  ("call get f"                         , REUSE__get (T_SHARES, 'f', x_desc, NULL, NULL)         ,    8);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get K"                         , REUSE__get (T_MASTER, 'K', x_desc, NULL, NULL)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get z"                         , REUSE__get (T_SHARES, 'z', x_desc, NULL, NULL)         ,   22);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "monster trouble");
   yUNIT_minval  ("call get M"                         , REUSE__get (T_MASTER, 'M', x_desc, NULL, NULL)         , 1000);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "!");
   yUNIT_minval  ("call get p"                         , REUSE__get (T_SHARES, 'p', x_desc, NULL, NULL)         ,-999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify purging marks");
   yUNIT_minval  ("... purge"                          , REUSE_init  ()      , 0);
   yUNIT_minstr  ("... review"                         , REUSE__used ()      , "¥-----¥-----¥-----¥-----¥-   ¥-----¥-----¥-----¥-----¥-");
   yUNIT_minval  ("call get A"                         , REUSE__get (T_MASTER, 'A', x_desc, NULL, NULL)         ,-999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get f"                         , REUSE__get (T_SHARES, 'f', x_desc, NULL, NULL)         ,-999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get K"                         , REUSE__get (T_MASTER, 'K', x_desc, NULL, NULL)         ,-999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get z"                         , REUSE__get (T_SHARES, 'z', x_desc, NULL, NULL)         ,-999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get M"                         , REUSE__get (T_MASTER, 'M', x_desc, NULL, NULL)         ,-999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get p"                         , REUSE__get (T_SHARES, 'p', x_desc, NULL, NULL)         ,-999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify setting by record");
   yUNIT_minval  ("call set"                           , REUSE__set_recd (T_SHARES, 'f', 987,  0, "SHARE -f-  description field " )    , 0);
   yUNIT_minstr  ("... review"                         , REUSE__used ()      , "¥-----¥-----¥-----¥-----¥-   ¥----f¥-----¥-----¥-----¥-");
   yUNIT_minval  ("call get A"                         , REUSE__get (T_MASTER, 'A', x_desc, NULL, NULL)         ,-999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get f"                         , REUSE__get (T_SHARES, 'f', x_desc, NULL, NULL)         , 987);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "description field");
   yUNIT_minval  ("call get K"                         , REUSE__get (T_MASTER, 'K', x_desc, NULL, NULL)         ,-999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get z"                         , REUSE__get (T_SHARES, 'z', x_desc, NULL, NULL)         ,-999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get M"                         , REUSE__get (T_MASTER, 'M', x_desc, NULL, NULL)         ,-999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get p"                         , REUSE__get (T_SHARES, 'p', x_desc, NULL, NULL)         ,-999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify setting by record (with spaces)");
   yUNIT_minval  ("call set"                           , REUSE__set_recd (T_MASTER, 'M', 789,  0, "GLOBAL -M-        indented        " )    , 0);
   yUNIT_minstr  ("... review"                         , REUSE__used ()      , "¥-----¥-----M-----¥-----¥-   ¥----f¥-----¥-----¥-----¥-");
   yUNIT_minval  ("call get A"                         , REUSE__get (T_MASTER, 'A', x_desc, NULL, NULL)         ,-999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get f"                         , REUSE__get (T_SHARES, 'f', x_desc, NULL, NULL)         , 987);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "description field");
   yUNIT_minval  ("call get K"                         , REUSE__get (T_MASTER, 'K', x_desc, NULL, NULL)         ,-999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get z"                         , REUSE__get (T_SHARES, 'z', x_desc, NULL, NULL)         ,-999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_minval  ("call get M"                         , REUSE__get (T_MASTER, 'M', x_desc, NULL, NULL)         , 789);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "indented");
   yUNIT_minval  ("call get p"                         , REUSE__get (T_SHARES, 'p', x_desc, NULL, NULL)         ,-999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_mindnoc ();

   PROG__unit_end    ();
   rm_working_files ();
   yUNIT_minprcs ();
   return 0;
}

char
koios__unit_reuse_global (char a_list)
{
   char        x_master    [LEN_TITLE] = "master.unit";
   char        x_name      [LEN_TITLE] = "apate.unit";
   char        x_desc      [LEN_LONG]  = "";
   char        x_share     =  '-';

   yUNIT_minscrp ("REUSE_parse (GLOBAL)");
   if (a_list == 'y')  return 0;
   yURG_err_none ();
   rm_working_files ();
   PROG__unit_quiet  ();

   yUNIT_mincond ("set to defaults");
   yUNIT_minval  ("... run clear"                      , REUSE_init ()       , 0);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "¥-----¥-----¥-----¥-----¥-   ¥-----¥-----¥-----¥-----¥-");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("verify ignoring other verbs");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_master,   0, "exec"     ,  0, "  exec      read a line          "   , x_desc, '-', &x_share),    0);
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_master,   0, "SCRP"     ,  0, "SCRP        test the reading     "   , x_desc, '-', &x_share),    0);
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("attempt reusing a missing identifier");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_master,   1, "REUSE"    ,  0, "REUSE  -K-  - - - - - - - - - -  "   , x_desc, '-', &x_share), -999);
   yUNIT_minchr  ("... check mark"                     , x_share             , '-');
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "master.unit:1:0: error: ∂REUSE  -K-∂ verb identifier ∂K∂ never set by GLOBAL");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("attempt reusing a illegal identifier");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_master,   3, "REUSE"    ,  0, "REUSE  -Ú-  - - - - - - - - - -  "   , x_desc, '-', &x_share), -999);
   yUNIT_minchr  ("... check mark"                     , x_share             , '-');
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "master.unit:3:0: error: ∂REUSE  -Ú-∂ verb identifier ∂Ú∂ not valid [a-zA-Z]");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("verify simple global identifier");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_master,   4, "GLOBAL"   ,  0, "GLOBAL -A-  generate test data   "   , x_desc, '-', &x_share), 1);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "A-----¥-----¥-----¥-----¥-   ¥-----¥-----¥-----¥-----¥-");
   yUNIT_minchr  ("... check mark"                     , x_share             , 'A');
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_minval  ("call get mark"                      , REUSE__get (T_MASTER, x_share, x_desc, NULL, NULL)         ,    4);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "generate test data");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("verify reusing the identifier (in normal unit)");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_name  ,   5, "REUSE"    ,  0, "REUSE  -A-  - - - - - - - - - -  "   , x_desc, '-', &x_share), 1);
   yUNIT_minchr  ("... check mark"                     , x_share             , 'A');
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("verify reusing the identifier (in master unit)");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_master,   5, "REUSE"    ,  0, "REUSE  -A-  - - - - - - - - - -  "   , x_desc, '-', &x_share), 1);
   yUNIT_minchr  ("... check mark"                     , x_share             , 'A');
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("verify defenses");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_master,   0, NULL       ,  0, "REUSE  -A-  - - - - - - - - - -  "   , x_desc, '-', &x_share), -999);
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_master,   0, "REUSE"    ,  0, NULL                                      , x_desc, '-', &x_share), -999);
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_master,   0, "REUSE"    ,  0, "REUSE  -A-  - - - - - - - - - -  "   , x_desc, '-', NULL    ), -999);
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("attempt without a identifier");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_master,   6, "GLOBAL"   ,  0, "GLOBAL      oops                 "   , x_desc, '-', &x_share), -999);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "A-----¥-----¥-----¥-----¥-   ¥-----¥-----¥-----¥-----¥-");
   yUNIT_minchr  ("... check mark"                     , x_share             , '-');
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "master.unit:6:0: error: ∂GLOBAL∂ missing valid identifier string, e.g., -A-");
   yUNIT_minval  ("call get mark"                      , REUSE__get (T_MASTER, x_share, x_desc, NULL, NULL)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("attempt with weird delimiters");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_master,   7, "GLOBAL"   ,  0, "GLOBAL (M)  oops                 "   , x_desc, '-', &x_share), -999);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "A-----¥-----¥-----¥-----¥-   ¥-----¥-----¥-----¥-----¥-");
   yUNIT_minchr  ("... check mark"                     , x_share             , '-');
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "master.unit:7:0: error: ∂GLOBAL (M)∂ missing valid identifier string, e.g., -A-");
   yUNIT_minval  ("call get mark"                      , REUSE__get (T_MASTER, x_share, x_desc, NULL, NULL)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("attempt with no suffix");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_master,   8, "GLOBAL"   ,  0, "GLOBAL -M   oops                 "   , x_desc, '-', &x_share), -999);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "A-----¥-----¥-----¥-----¥-   ¥-----¥-----¥-----¥-----¥-");
   yUNIT_minchr  ("... check mark"                     , x_share             , '-');
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "master.unit:8:0: error: ∂GLOBAL -M∂ identifier ∂-M∂ does not end with -, e.g., -A-");
   yUNIT_minval  ("call get mark"                      , REUSE__get (T_MASTER, x_share, x_desc, NULL, NULL)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("attempt with just suffix");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_master,   9, "GLOBAL"   ,  0, "GLOBAL -M)  oops                 "   , x_desc, '-', &x_share), -999);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "A-----¥-----¥-----¥-----¥-   ¥-----¥-----¥-----¥-----¥-");
   yUNIT_minchr  ("... check mark"                     , x_share             , '-');
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "master.unit:9:0: error: ∂GLOBAL -M)∂ identifier ∂-M)∂ does not end with -, e.g., -A-");
   yUNIT_minval  ("call get mark"                      , REUSE__get (T_MASTER, x_share, x_desc, NULL, NULL)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("verify another global identifier");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_master,  10, "GLOBAL"   ,  0, "GLOBAL -M-  some repeating stuff "   , x_desc, '-', &x_share), 1);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "A-----¥-----M-----¥-----¥-   ¥-----¥-----¥-----¥-----¥-");
   yUNIT_minchr  ("... check mark"                     , x_share             , 'M');
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_minval  ("call get mark"                      , REUSE__get (T_MASTER, x_share, x_desc, NULL, NULL)         ,   10);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "some repeating stuff");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("attempt with just suffix");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_master,  15, "GLOBAL"   ,  0, "GLOBAL -c-  wrong case           "   , x_desc, '-', &x_share), -999);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "A-----¥-----M-----¥-----¥-   ¥-----¥-----¥-----¥-----¥-");
   yUNIT_minchr  ("... check mark"                     , x_share             , '-');
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "master.unit:15:0: error: ∂GLOBAL -c-∂ identifier ∂c∂ not valid ÂABCDEFGHIJKLMNOPQRSTUVWXYZÊ");
   yUNIT_minval  ("call get mark"                      , REUSE__get (T_MASTER, x_share, x_desc, NULL, NULL)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("attempt to redefine idenfitier");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_master,  15, "GLOBAL"   ,  0, "GLOBAL -M-  re-defining          "   , x_desc, '-', &x_share), -999);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "A-----¥-----M-----¥-----¥-   ¥-----¥-----¥-----¥-----¥-");
   yUNIT_minchr  ("... check mark"                     , x_share             , '-');
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "master.unit:15:0: error: ∂GLOBAL -M-∂ identifier ∂M∂ already in use");
   yUNIT_minval  ("call get mark"                      , REUSE__get (T_MASTER, x_share, x_desc, NULL, NULL)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("attempt to define outside master.unit");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_name  ,  20, "GLOBAL"   ,  0, "GLOBAL -M-  re-defining          "   , x_desc, '-', &x_share), -999);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "A-----¥-----M-----¥-----¥-   ¥-----¥-----¥-----¥-----¥-");
   yUNIT_minchr  ("... check mark"                     , x_share             , '-');
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "apate.unit:20:0: error: GLOBAL verb not allowed outside master.unit");
   yUNIT_minval  ("call get mark"                      , REUSE__get (T_MASTER, x_share, x_desc, NULL, NULL)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("verify another global identifier");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_master,  30, "GLOBAL"   ,  0, "GLOBAL -Y-  final check          "   , x_desc, '-', &x_share), 1);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "A-----¥-----M-----¥-----Y-   ¥-----¥-----¥-----¥-----¥-");
   yUNIT_minchr  ("... check mark"                     , x_share             , 'Y');
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_minval  ("call get mark"                      , REUSE__get (T_MASTER, x_share, x_desc, NULL, NULL)         ,   30);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "final check");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("attempt reusing inside itself");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_master,  35, "REUSE"    ,  0, "REUSE  -A-  - - - - - - - - - -  "   , x_desc, 'A', &x_share), -999);
   yUNIT_minchr  ("... check mark"                     , x_share             , '-');
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "master.unit:35:0: error: ∂REUSE  -A-∂ verb identifier ∂A∂ called inside itself, recursive");
   yUNIT_mindnoc ();

   PROG__unit_end    ();
   rm_working_files ();
   yUNIT_minprcs ();
   return 0;
}

char
koios__unit_reuse_shares (char a_list)
{
   char        x_master    [LEN_TITLE] = "master.unit";
   char        x_name      [LEN_TITLE] = "apate.unit";
   char        x_desc      [LEN_LONG]  = "";
   char        x_share     =  '-';

   yUNIT_minscrp ("REUSE_parse (SHARE)");
   if (a_list == 'y')  return 0;
   yURG_err_none ();
   rm_working_files ();
   PROG__unit_quiet  ();

   yUNIT_mincond ("set to defaults");
   yUNIT_minval  ("... run clear"                      , REUSE_init ()       , 0);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "¥-----¥-----¥-----¥-----¥-   ¥-----¥-----¥-----¥-----¥-");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("verify ignoring other verbs");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_name  ,   0, "exec"     ,  0, "  exec      read a line          "   , x_desc, '-', &x_share),    0);
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_name  ,   0, "SCRP"     ,  0, "SCRP        test the reading     "   , x_desc, '-', &x_share),    0);
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("attempt reusing a missing identifier");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_name  ,   1, "REUSE"    ,  0, "REUSE  -k-  - - - - - - - - - -  "   , x_desc, '-', &x_share), -999);
   yUNIT_minchr  ("... check mark"                     , x_share             , '-');
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "apate.unit:1:0: error: ∂REUSE  -k-∂ verb identifier ∂k∂ never set by SHARED");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("attempt reusing a illegal identifier");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_name  ,   3, "REUSE"    ,  0, "REUSE  -Ú-  - - - - - - - - - -  "   , x_desc, '-', &x_share), -999);
   yUNIT_minchr  ("... check mark"                     , x_share             , '-');
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "apate.unit:3:0: error: ∂REUSE  -Ú-∂ verb identifier ∂Ú∂ not valid [a-zA-Z]");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("verify simple share identifier");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_name  ,   5, "SHARED"   ,  0, "SHARED -a-  generate test data   "   , x_desc, '-', &x_share), 1);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "¥-----¥-----¥-----¥-----¥-   a-----¥-----¥-----¥-----¥-");
   yUNIT_minchr  ("... check mark"                     , x_share             , 'a');
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_minval  ("call get mark"                      , REUSE__get (T_SHARES, x_share, x_desc, NULL, NULL)         ,    5);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "generate test data");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("verify reusing the identifier (in normal unit)");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_name  ,   5, "REUSE"    ,  0, "REUSE  -a-  - - - - - - - - - -  "   , x_desc, '-', &x_share), 1);
   yUNIT_minchr  ("... check mark"                     , x_share             , 'a');
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("attempt reusing the identifier (in master unit)");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_master,   5, "REUSE"    ,  0, "REUSE  -a-  - - - - - - - - - -  "   , x_desc, '-', &x_share), -999);
   yUNIT_minchr  ("... check mark"                     , x_share             , '-');
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "master.unit:5:0: error: REUSE verb on ∂a∂ SHARED identifier not allowed inside master.unit");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("verify defenses");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_name  ,   0, NULL       ,  0, "REUSE  -a-  - - - - - - - - - -  "   , x_desc, '-', &x_share), -999);
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_name  ,   0, "REUSE"    ,  0, NULL                                      , x_desc, '-', &x_share), -999);
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_name  ,   0, "REUSE"    ,  0, "REUSE  -a-  - - - - - - - - - -  "   , x_desc, '-', NULL    ), -999);
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("attempt without a identifier");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_name  ,   6, "SHARED"   ,  0, "SHARED      oops                 "   , x_desc, '-', &x_share), -999);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "¥-----¥-----¥-----¥-----¥-   a-----¥-----¥-----¥-----¥-");
   yUNIT_minchr  ("... check mark"                     , x_share             , '-');
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "apate.unit:6:0: error: ∂SHARED∂ missing valid identifier string, e.g., -a-");
   yUNIT_minval  ("call get mark"                      , REUSE__get (T_SHARES, x_share, x_desc, NULL, NULL)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("attempt with weird delimiters");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_name  ,   7, "SHARED"   ,  0, "SHARED (r)  oops                 "   , x_desc, '-', &x_share), -999);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "¥-----¥-----¥-----¥-----¥-   a-----¥-----¥-----¥-----¥-");
   yUNIT_minchr  ("... check mark"                     , x_share             , '-');
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "apate.unit:7:0: error: ∂SHARED (r)∂ missing valid identifier string, e.g., -a-");
   yUNIT_minval  ("call get mark"                      , REUSE__get (T_SHARES, x_share, x_desc, NULL, NULL)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("attempt with no suffix");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_name  ,   8, "SHARED"   ,  0, "SHARED -r   oops                 "   , x_desc, '-', &x_share), -999);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "¥-----¥-----¥-----¥-----¥-   a-----¥-----¥-----¥-----¥-");
   yUNIT_minchr  ("... check mark"                     , x_share             , '-');
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "apate.unit:8:0: error: ∂SHARED -r∂ identifier ∂-r∂ does not end with -, e.g., -a-");
   yUNIT_minval  ("call get mark"                      , REUSE__get (T_SHARES, x_share, x_desc, NULL, NULL)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("attempt with just suffix");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_name  ,   9, "SHARED"   ,  0, "SHARED -r)  oops                 "   , x_desc, '-', &x_share), -999);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "¥-----¥-----¥-----¥-----¥-   a-----¥-----¥-----¥-----¥-");
   yUNIT_minchr  ("... check mark"                     , x_share             , '-');
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "apate.unit:9:0: error: ∂SHARED -r)∂ identifier ∂-r)∂ does not end with -, e.g., -a-");
   yUNIT_minval  ("call get mark"                      , REUSE__get (T_SHARES, x_share, x_desc, NULL, NULL)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("verify another global identifier");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_name  ,  10, "SHARED"   ,  0, "SHARED -r-  some repeating stuff "   , x_desc, '-', &x_share), 1);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "¥-----¥-----¥-----¥-----¥-   a-----¥-----¥----r¥-----¥-");
   yUNIT_minchr  ("... check mark"                     , x_share             , 'r');
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_minval  ("call get mark"                      , REUSE__get (T_SHARES, x_share, x_desc, NULL, NULL)         ,   10);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "some repeating stuff");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("attempt with just suffix");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_name  ,  15, "SHARED"   ,  0, "SHARED -C-  wrong case           "   , x_desc, '-', &x_share), -999);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "¥-----¥-----¥-----¥-----¥-   a-----¥-----¥----r¥-----¥-");
   yUNIT_minchr  ("... check mark"                     , x_share             , '-');
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "apate.unit:15:0: error: ∂SHARED -C-∂ identifier ∂C∂ not valid ÂabcdefghijklmnopqrstuvwxyzÊ");
   yUNIT_minval  ("call get mark"                      , REUSE__get (T_SHARES, x_share, x_desc, NULL, NULL)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("attempt to redefine idenfitier");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_name  ,  15, "SHARED"   ,  0, "SHARED -r-  re-defining          "   , x_desc, '-', &x_share), -999);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "¥-----¥-----¥-----¥-----¥-   a-----¥-----¥----r¥-----¥-");
   yUNIT_minchr  ("... check mark"                     , x_share             , '-');
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "apate.unit:15:0: error: ∂SHARED -r-∂ identifier ∂r∂ already in use");
   yUNIT_minval  ("call get mark"                      , REUSE__get (T_SHARES, x_share, x_desc, NULL, NULL)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("attempt to define inside master.unit");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_master,  20, "SHARED"   ,  0, "SHARED -r-  re-defining          "   , x_desc, '-', &x_share), -999);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "¥-----¥-----¥-----¥-----¥-   a-----¥-----¥----r¥-----¥-");
   yUNIT_minchr  ("... check mark"                     , x_share             , '-');
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "master.unit:20:0: error: SHARED verb not allowed inside master.unit");
   yUNIT_minval  ("call get mark"                      , REUSE__get (T_SHARES, x_share, x_desc, NULL, NULL)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("verify another global identifier");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_name  ,  30, "SHARED"   ,  0, "SHARED -z-  final check          "   , x_desc, '-', &x_share), 1);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "¥-----¥-----¥-----¥-----¥-   a-----¥-----¥----r¥-----¥z");
   yUNIT_minchr  ("... check mark"                     , x_share             , 'z');
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_minval  ("call get mark"                      , REUSE__get (T_SHARES, x_share, x_desc, NULL, NULL)         ,   30);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "final check");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("attempt reusing inside itself");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_name  ,  35, "REUSE"    ,  0, "REUSE  -a-  - - - - - - - - - -  "   , x_desc, 'a', &x_share), -999);
   yUNIT_minchr  ("... check mark"                     , x_share             , '-');
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "apate.unit:35:0: error: ∂REUSE  -a-∂ verb identifier ∂a∂ called inside itself, recursive");
   yUNIT_mindnoc ();

   PROG__unit_end    ();
   rm_working_files ();
   yUNIT_minprcs ();
   return 0;
}

char
koios__unit_reuse_update (char a_list)
{
   char        x_master    [LEN_TITLE] = "master.globals";
   char        x_name      [LEN_TITLE] = "apate.unit";
   char        x_desc      [LEN_LONG]  = "";
   int         x_conds     =    0;
   int         x_steps     =    0;
   char        x_share     =  '-';

   yUNIT_minscrp ("REUSE_update, REUSE_export, REUSE_import, REUSE_add");
   if (a_list == 'y')  return 0;
   yURG_err_none ();
   rm_working_files ();
   PROG__unit_quiet  ();

   yUNIT_mincond ("set to defaults");
   yUNIT_minval  ("... run clear"                      , REUSE_init ()       , 0);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "¥-----¥-----¥-----¥-----¥-   ¥-----¥-----¥-----¥-----¥-");
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify updating a mark with stats");
   yUNIT_minval  ("call set"                           , REUSE__set   (T_MASTER, 'A', 123, "verify something")         , 0);
   yUNIT_minval  ("call update"                        , REUSE_update ('A',   5,  15)                                  , 0);
   yUNIT_minstr  ("... review"                         , REUSE__used  ()      , "A-----¥-----¥-----¥-----¥-   ¥-----¥-----¥-----¥-----¥-");
   yUNIT_minval  ("call get mark"                      , REUSE__get   (T_MASTER, 'A', x_desc, &x_conds, &x_steps)      , 123);
   yUNIT_minstr  ("... show desc"                      , x_desc       , "verify something");
   yUNIT_minval  ("... show conds"                     , x_conds      , 5);
   yUNIT_minval  ("... show steps"                     , x_steps      , 15);
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify updating a second mark with stats");
   yUNIT_minval  ("call set"                           , REUSE__set   (T_MASTER, 'J', 678, "big shared global")        , 0);
   yUNIT_minval  ("call update"                        , REUSE_update ('J',  21,  62)                                  , 0);
   yUNIT_minstr  ("... review"                         , REUSE__used  ()      , "A-----¥--J--¥-----¥-----¥-   ¥-----¥-----¥-----¥-----¥-");
   yUNIT_minval  ("call get mark"                      , REUSE__get   (T_MASTER, 'J', x_desc, &x_conds, &x_steps)      , 678);
   yUNIT_minstr  ("... show desc"                      , x_desc       , "big shared global");
   yUNIT_minval  ("... show conds"                     , x_conds      , 21);
   yUNIT_minval  ("... show steps"                     , x_steps      , 62);
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify exporting");
   yUNIT_minval  ("call export"                        , REUSE_export (x_master)                                       , 0);
   yUNIT_minstr  ("... check lines"                    , yURG_peek (x_master,   0), "A  123 verify∑something                                                               5   15");
   yUNIT_minstr  ("... check lines"                    , yURG_peek (x_master, '÷'), "B   -1                                                                                0    0");
   yUNIT_minstr  ("... check lines"                    , yURG_peek (x_master, '÷'), "C   -1                                                                                0    0");
   yUNIT_minstr  ("... check lines"                    , yURG_peek (x_master, '÷'), "D   -1                                                                                0    0");
   yUNIT_minstr  ("... check lines"                    , yURG_peek (x_master, '÷'), "E   -1                                                                                0    0");
   yUNIT_minstr  ("... check lines"                    , yURG_peek (x_master, '÷'), "F   -1                                                                                0    0");
   yUNIT_minstr  ("... check lines"                    , yURG_peek (x_master, '÷'), "G   -1                                                                                0    0");
   yUNIT_minstr  ("... check lines"                    , yURG_peek (x_master, '÷'), "H   -1                                                                                0    0");
   yUNIT_minstr  ("... check lines"                    , yURG_peek (x_master, '÷'), "I   -1                                                                                0    0");
   yUNIT_minstr  ("... check lines"                    , yURG_peek (x_master, '÷'), "J  678 big∑shared∑global                                                             21   62");
   yUNIT_minstr  ("... check lines"                    , yURG_peek (x_master, '÷'), "K   -1                                                                                0    0");
   yUNIT_minstr  ("... check lines"                    , yURG_peek (x_master, '÷'), "L   -1                                                                                0    0");
   yUNIT_minstr  ("... check lines"                    , yURG_peek (x_master, '÷'), "M   -1                                                                                0    0");
   yUNIT_minstr  ("... check lines"                    , yURG_peek (x_master, '÷'), "N   -1                                                                                0    0");
   yUNIT_minstr  ("... check lines"                    , yURG_peek (x_master, '÷'), "O   -1                                                                                0    0");
   yUNIT_minstr  ("... check lines"                    , yURG_peek (x_master, '÷'), "P   -1                                                                                0    0");
   yUNIT_minstr  ("... check lines"                    , yURG_peek (x_master, '÷'), "Q   -1                                                                                0    0");
   yUNIT_minstr  ("... check lines"                    , yURG_peek (x_master, '÷'), "R   -1                                                                                0    0");
   yUNIT_minstr  ("... check lines"                    , yURG_peek (x_master, '÷'), "S   -1                                                                                0    0");
   yUNIT_minstr  ("... check lines"                    , yURG_peek (x_master, '÷'), "T   -1                                                                                0    0");
   yUNIT_minstr  ("... check lines"                    , yURG_peek (x_master, '÷'), "U   -1                                                                                0    0");
   yUNIT_minstr  ("... check lines"                    , yURG_peek (x_master, '÷'), "V   -1                                                                                0    0");
   yUNIT_minstr  ("... check lines"                    , yURG_peek (x_master, '÷'), "W   -1                                                                                0    0");
   yUNIT_minstr  ("... check lines"                    , yURG_peek (x_master, '÷'), "X   -1                                                                                0    0");
   yUNIT_minstr  ("... check lines"                    , yURG_peek (x_master, '÷'), "Y   -1                                                                                0    0");
   yUNIT_minstr  ("... check lines"                    , yURG_peek (x_master, '÷'), "Z   -1                                                                                0    0");
   yUNIT_minstr  ("... check lines"                    , yURG_peek (x_master, '÷'), ""                                                                                            );
   yUNIT_mindnoc ();

   yUNIT_mincond ("set to defaults");
   yUNIT_minval  ("... run clear"                      , REUSE_init ()       , 0);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "¥-----¥-----¥-----¥-----¥-   ¥-----¥-----¥-----¥-----¥-");
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify importing");
   yUNIT_minval  ("call import"                        , REUSE_import (x_master)                                       , 0);
   yUNIT_minstr  ("... review"                         , REUSE__used  ()      , "A-----¥--J--¥-----¥-----¥-   ¥-----¥-----¥-----¥-----¥-");
   yUNIT_minval  ("call get mark"                      , REUSE__get   (T_MASTER, 'A', x_desc, &x_conds, &x_steps)      , 123);

   x_conds =  25;  x_steps = 100;
   yUNIT_mincond ("verify adding to counters");
   yUNIT_minval  ("call add"                           , REUSE_add    ('J', &x_conds, &x_steps)              , 0);
   yUNIT_minstr  ("... show desc"                      , x_desc       , "verify something");
   yUNIT_minval  ("... show conds"                     , x_conds      , 46);
   yUNIT_minval  ("... show steps"                     , x_steps      , 162);
   yUNIT_mindnoc ();

   PROG__unit_end    ();
   rm_working_files ();
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
   rm_working_files ();
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
   rm_working_files ();
   yUNIT_minprcs  ();
   return 0;
}

char
koios__unit_conv_printf  (char a_list)
{
   char         x_name     [LEN_HUND] = "apate.unit";
   char         t          [LEN_HUND] = "";
   FILE        *x_file     = NULL;

   yUNIT_minscrp  ("CONV_printf");
   if (a_list == 'y')  return 0;
   yURG_err_none  ();
   rm_working_files ();
   PROG__unit_quiet  ();

   sprintf (t, "touch %s", x_name);  system (t);
   yUNIT_mincond  ("open the conversion file");
   yUNIT_minval   ("open file"                          , READ_open   (x_name, 'w', &x_file, NULL), 0);
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify printing a format only");
   yUNIT_minval   ("write line"                         , CONV_printf    (x_file    , "format only\n"                  ),    0);
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   0)      , "format only"                              );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   1)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("attempt with null file");
   yUNIT_minval   ("write line"                         , CONV_printf    (NULL      , "a mistake\n"                    ), -999);
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   0)      , "format only"                              );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   1)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify printing a single variable");
   yUNIT_minval   ("write line"                         , CONV_printf    (x_file    , "%s\n"                  , "testing"                  ),    0);
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   0)      , "format only"                              );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   1)      , "testing"                                  );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   2)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("attempt with null format");
   yUNIT_minval   ("write line"                         , CONV_printf    (x_file    , NULL                    , "testing"                  ), -999);
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   0)      , "format only"                              );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   1)      , "testing"                                  );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   2)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify printing a multiple variables");
   yUNIT_minval   ("write line"                         , CONV_printf    (x_file    , "%s (%d) %s\n"          , "whos"  , 52 , "heading"   ),    0);
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   0)      , "format only"                              );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   1)      , "testing"                                  );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   2)      , "whos (52) heading"                        );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   3)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("close the conversion file");
   yUNIT_minval   ("close file"                         , READ_close  (&x_file), 0);
   yUNIT_mindnoc  ();

   PROG__unit_end    ();
   rm_working_files ();
   yUNIT_minprcs  ();
   return 0;
}

char
koios__unit_conv_preps   (char a_list)
{
   char         x_name     [LEN_HUND]  = "apate.unit";
   FILE        *x_file     = NULL;
   char         t          [LEN_HUND]  = "";
   char         x_cshare   =  '-';

   yUNIT_minscrp  ("CONV_header, CONV_prep, CONV_incl, CONV_footer");
   if (a_list == 'y')  return 0;
   yURG_err_none  ();
   rm_working_files ();
   PROG__unit_quiet  ();

   yUNIT_mincond  ("open the files");
   yUNIT_minval   ("open file"                          , READ_open       (x_name , 'w', &x_file, NULL), 0);
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing a BREAK");
   yUNIT_minval   ("write conv line"                    , CONV_break      (x_file    ),    0);
   yUNIT_minval   ("... check count"                    , yURG_peek_count (x_name)               , 5);
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   0)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   1)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   2)      , ""                                         );
   yUNIT_minstr   ("... ruler"                          , yURG_peek       (x_name    ,   3)      , "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-123456789- ");
   yUNIT_minstr   ("... title"                          , yURG_peek       (x_name    ,   4)      , "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  ========(var)======= ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   5)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing a PREP");
   yUNIT_minval   ("write conv line"                    , CONV_prep       (x_file    , "PREP"    , "prototype headers"   , ""               , ""               , ""          , ""               , ""          , '-', '-', ""  , &x_cshare  ),    0);
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
   yUNIT_minval   ("write conv line"                    , CONV_incl       (x_file    , "incl"    , "public header"       , "apate.h"        , ""               , ""          , ""               , ""          , '-', '-', ""  , &x_cshare  ),    0);
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
   yUNIT_minstr   ("... check resuls"                   , yURG_peek       (x_name    ,  11)      , "   incl       public header                        apate.h                     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  12)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing a COMMENT");
   yUNIT_minval   ("write conv line"                    , CONV_comment    (x_file    , "#>"      , ""                    , ""               , ""               , ""          , "#> comment"     , ""          , '-', '-', ""  , &x_cshare  ),    0);
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
   yUNIT_minstr   ("... check resuls"                   , yURG_peek       (x_name    ,  11)      , "   incl       public header                        apate.h                     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check resuls"                   , yURG_peek       (x_name    ,  12)      , "#> comment");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  13)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("close the files");
   yUNIT_minval   ("close conv"                         , READ_close  (&x_file), 0);
   yUNIT_mindnoc  ();

   PROG__unit_end    ();
   rm_working_files ();
   yUNIT_minprcs  ();
   return 0;
}

char
koios__unit_conv_scrps   (char a_list)
{
   char         x_suf      [LEN_SHORT] = "";
   char         x_cnt      [LEN_LABEL] = "";
   char         x_name     [LEN_HUND]  = "apate.unit";
   char         t          [LEN_HUND]  = "";
   FILE        *x_file     = NULL;
   char         x_cshare   =  '-';

   yUNIT_minscrp  ("CONV_scrp, CONV_sect, CONV_shared, CONV_global");
   if (a_list == 'y')  return 0;
   yURG_err_none  ();
   rm_working_files ();
   PROG__unit_quiet  ();

   CONV_force ( 5, 32);
   yUNIT_mincond  ("verify common outputs");
   yUNIT_minval   ("call for SCRP without stage"        , CONV__scrp_add  ('y' , '-'  , ""    , x_suf, x_cnt, &x_cshare),    0);
   yUNIT_minstr   ("... check suffix"                   , x_suf            , "");
   yUNIT_minstr   ("... check count"                    , x_cnt            , "((06.---))");
   yUNIT_minchr   ("... check x_cshare"                 , x_cshare         , '-');
   yUNIT_minval   ("call for SECT"                      , CONV__scrp_add  ('-' , '-'  , ""    , x_suf, x_cnt, &x_cshare),    0);
   yUNIT_minstr   ("... check suffix"                   , x_suf            , "");
   yUNIT_minstr   ("... check count"                    , x_cnt            , "((06.---))");
   yUNIT_minchr   ("... check x_cshare"                 , x_cshare         , '-');
   yUNIT_minval   ("call for SHARED"                    , CONV__scrp_add  ('y' , 'd'  , ""    , x_suf, x_cnt, &x_cshare),    0);
   yUNIT_minstr   ("... check suffix"                   , x_suf            , "-d-");
   yUNIT_minstr   ("... check count"                    , x_cnt            , "((dd.---))");
   yUNIT_minchr   ("... check x_cshare"                 , x_cshare         , 'd');
   yUNIT_minval   ("call for SCRP with stage"           , CONV__scrp_add  ('y' , '-'  , "¬Ú"  , x_suf, x_cnt, &x_cshare),    0);
   yUNIT_minstr   ("... check suffix"                   , x_suf            , "[¬Ú]");
   yUNIT_minstr   ("... check count"                    , x_cnt            , "((08.---))");
   yUNIT_minchr   ("... check x_cshare"                 , x_cshare         , '-');
   yUNIT_minval   ("call for GLOBAL"                    , CONV__scrp_add  ('y' , 'V'  , ""    , x_suf, x_cnt, &x_cshare),    0);
   yUNIT_minstr   ("... check suffix"                   , x_suf            , "-V-");
   yUNIT_minstr   ("... check count"                    , x_cnt            , "((VV.---))");
   yUNIT_minchr   ("... check x_cshare"                 , x_cshare         , 'V');
   yUNIT_mindnoc  ();

   sprintf (t, "touch %s", x_name);  system (t);
   yUNIT_mincond  ("open the conversion file");
   yUNIT_minval   ("open file"                          , READ_open       (x_name, 'w', &x_file, NULL), 0);
   yUNIT_minval   ("... check count"                    , yURG_peek_count (x_name)               , 0);
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing a SCRP without stage");
   yUNIT_minval   ("write conv line"                    , CONV_scrp       (x_file    , "SCRP"    , "test funky thing"    , "func1, func2"   , ""               , "5m"        , ""               , "funky"     , '-', '-', ""  , &x_cshare  ),    0);
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
   yUNIT_minval   ("write conv line"                    , CONV_scrp       (x_file    , "SCRP"    , "critical test"       , "yURG_huge"      , ""               , "3s"        , ""               , "BOOMy"     , '-', '-', "¿Ë", &x_cshare  ),    0);
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
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  11)      , "SCRP    [¿Ë]  critical test                                                      3s   BOOMy           yURG_huge                                                                    ((11.---))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  12)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing a SECT");
   yUNIT_minval   ("write conv line"                    , CONV_sect       (x_file    , "SECT"    , "big stuff here"      , ""               , ""               , ""          , ""               , ""          , '-', '-', ""  , &x_cshare  ),    0);
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
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  11)      , "SCRP    [¿Ë]  critical test                                                      3s   BOOMy           yURG_huge                                                                    ((11.---))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  12)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  13)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  14)      , ""                                         );
   yUNIT_minstr   ("... ruler"                          , yURG_peek       (x_name    ,  15)      , "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-123456789- ");
   yUNIT_minstr   ("... title"                          , yURG_peek       (x_name    ,  16)      , "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  ========(var)======= ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  17)      , "SECT          big stuff here                                                     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  18)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing a SHARED");
   yUNIT_minval   ("write conv line"                    , CONV_shared     (x_file    , "SHARED"  , "in the same file"    , ""               , ""               , "0s"        , ""               , "simple"    , 'a', '-', ""  , &x_cshare  ),    0);
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
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  11)      , "SCRP    [¿Ë]  critical test                                                      3s   BOOMy           yURG_huge                                                                    ((11.---))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
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
   yUNIT_minval   ("write conv line"                    , CONV_global     (x_file    , "GLOBAL"  , "in the master file"  , ""               , ""               , "5s"        , ""               , "central"   , 'Z', '-', ""  , &x_cshare  ),    0);
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
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  11)      , "SCRP    [¿Ë]  critical test                                                      3s   BOOMy           yURG_huge                                                                    ((11.---))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
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
   yUNIT_mindnoc  ();

   PROG__unit_end    ();
   rm_working_files ();
   yUNIT_minprcs  ();
   return 0;
}

char
koios__unit_conv_conds   (char a_list)
{
   char         x_suf      [LEN_SHORT] = "";
   char         x_cnt      [LEN_LABEL] = "";
   char         x_name     [LEN_HUND]  = "apate.unit";
   char         t          [LEN_HUND]  = "";
   FILE        *x_file     = NULL;
   char         x_cshare   =  '-';

   yUNIT_minscrp  ("CONV_cond, CONV_ditto, CONV_group, COND_reuse");
   if (a_list == 'y')  return 0;
   yURG_err_none  ();
   rm_working_files ();
   PROG__unit_quiet  ();

   CONV_force ( 2, 32);
   yUNIT_mincond  ("verify common outputs");
   yUNIT_minval   ("call common"                        , CONV__cond_add  ('-'  , '-'  , '-'  , x_suf, x_cnt),    0);
   yUNIT_minstr   ("... check suffix"                   , x_suf            , "");
   yUNIT_minstr   ("... check count"                    , x_cnt            , "((02.033))");
   yUNIT_minval   ("call marked"                        , CONV__cond_add  ('2'  , '-'  , '-'  , x_suf, x_cnt),    0);
   yUNIT_minstr   ("... check suffix"                   , x_suf            , "(2)");
   yUNIT_minstr   ("... check count"                    , x_cnt            , "((02.034))");
   yUNIT_minval   ("call inside shared"                 , CONV__cond_add  ('-'  , 'b'  , '-'  , x_suf, x_cnt),    0);
   yUNIT_minstr   ("... check suffix"                   , x_suf            , "-b-");
   yUNIT_minstr   ("... check count"                    , x_cnt            , "((02.035))");
   yUNIT_minval   ("call shared"                        , CONV__cond_add  ('-'  , '-'  , 'c'  , x_suf, x_cnt),    0);
   yUNIT_minstr   ("... check suffix"                   , x_suf            , "");
   yUNIT_minstr   ("... check count"                    , x_cnt            , "((cc.036))");
   yUNIT_mindnoc  ();

   sprintf (t, "touch %s", x_name);  system (t);
   yUNIT_mincond  ("open the conversion file");
   yUNIT_minval   ("open file"                          , READ_open       (x_name, 'w', &x_file, NULL), 0);
   yUNIT_minval   ("... check count"                    , yURG_peek_count (x_name)               , 0);
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing a COND not marked");
   yUNIT_minval   ("write conv line"                    , CONV_cond       (x_file    , "COND"    , "initialize"          , ""               , ""               , ""          , ""               , ""          , '-', '-', ""  , &x_cshare  ),    0);
   yUNIT_minval   ("... check count"                    , yURG_peek_count (x_name)               , 2);
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   0)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   1)      , "   COND       initialize                                                         - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((02.037))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   2)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing a COND with mark");
   yUNIT_minval   ("write conv line"                    , CONV_cond       (x_file    , "COND"    , "setting a mark"      , ""               , ""               , ""          , ""               , ""          , '-', '2', ""  , &x_cshare  ),    0);
   yUNIT_minval   ("... check count"                    , yURG_peek_count (x_name)               , 4);
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   0)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   1)      , "   COND       initialize                                                         - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((02.037))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   2)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   3)      , "   COND  (2)  setting a mark                                                     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((02.038))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   4)      , ""                                         );
   yUNIT_mindnoc  ();

   x_cshare = 'b';
   yUNIT_mincond  ("verify writing a COND in a share");
   yUNIT_minval   ("write conv line"                    , CONV_cond       (x_file    , "COND"    , "within a share"      , ""               , ""               , ""          , ""               , ""          , '-', '-', ""  , &x_cshare  ),    0);
   yUNIT_minval   ("... check count"                    , yURG_peek_count (x_name)               , 6);
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   0)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   1)      , "   COND       initialize                                                         - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((02.037))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   2)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   3)      , "   COND  (2)  setting a mark                                                     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((02.038))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   4)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   5)      , "   COND       within a share                                                     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((bb.039))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   6)      , ""                                         );
   yUNIT_mindnoc  ();
   x_cshare = '-';

   yUNIT_mincond  ("verify writing a DITTO");
   yUNIT_minval   ("write conv line"                    , CONV_ditto      (x_file    , "DITTO"   , "call back desc"      , ""               , ""               , ""          , ""               , ""          , '-', '5', ""  , &x_cshare  ),    0);
   yUNIT_minval   ("... check count"                    , yURG_peek_count (x_name)               , 8);
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   0)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   1)      , "   COND       initialize                                                         - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((02.037))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   2)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   3)      , "   COND  (2)  setting a mark                                                     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((02.038))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   4)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   5)      , "   COND       within a share                                                     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((bb.039))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   6)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   7)      , "   DITTO (5)  call back desc                                                     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((02.040))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   8)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing a REUSE");
   yUNIT_minval   ("write conv line"                    , CONV_reuse      (x_file    , "REUSE"   , "call share"          , ""               , ""               , ""          , ""               , ""          , '-', 's', ""  , &x_cshare  ),    0);
   yUNIT_minval   ("... check count"                    , yURG_peek_count (x_name)               , 10);
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   0)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   1)      , "   COND       initialize                                                         - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((02.037))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   2)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   3)      , "   COND  (2)  setting a mark                                                     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((02.038))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   4)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   5)      , "   COND       within a share                                                     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((bb.039))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   6)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   7)      , "   DITTO (5)  call back desc                                                     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((02.040))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   8)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   9)      , "   REUSE (s)  call share                                                         - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((02.041))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  10)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing a GROUP");
   yUNIT_minval   ("write conv line"                    , CONV_group      (x_file    , "GROUP"   , "connected stuff"     , ""               , ""               , ""          , ""               , ""          , '-', '-', ""  , &x_cshare  ),    0);
   yUNIT_minval   ("... check count"                    , yURG_peek_count (x_name)               , 12);
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   0)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   1)      , "   COND       initialize                                                         - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((02.037))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   2)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   3)      , "   COND  (2)  setting a mark                                                     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((02.038))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   4)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   5)      , "   COND       within a share                                                     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((bb.039))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   6)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   7)      , "   DITTO (5)  call back desc                                                     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((02.040))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   8)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   9)      , "   REUSE (s)  call share                                                         - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((02.041))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  10)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  11)      , "   GROUP      connected stuff                                                    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  12)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("close the conversion file");
   yUNIT_minval   ("close file"                         , READ_close  (&x_file), 0);
   yUNIT_mindnoc  ();

   PROG__unit_end    ();
   rm_working_files ();
   yUNIT_minprcs  ();
   return 0;
}

char
koios__unit_conv_steps   (char a_list)
{
   char         x_name     [LEN_HUND] = "apate.unit";
   char         t          [LEN_HUND] = "";
   FILE        *x_file     = NULL;
   char         x_cshare   =  '-';

   yUNIT_minscrp  ("CONV_exec, CONV_load, CONV_file, CONV_append, CONV_mode, CONV_code, CONV_gvar, CONV_echo");
   if (a_list == 'y')  return 0;
   yURG_err_none  ();
   rm_working_files ();
   PROG__unit_quiet  ();

   sprintf (t, "touch %s", x_name);  system (t);
   yUNIT_mincond  ("open the conversion file");
   yUNIT_minval   ("open file"                          , READ_open   (x_name, 'w', &x_file, NULL), 0);
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing an EXEC");
   yUNIT_minval   ("write conv line"                    , CONV_exec      (x_file    , "exec"    , "call the function"   , "DITTO_parse"    , "x, y, 21"       , "s_equal"   , "pretty expected", "x_str"     , '-', '-', ""  , &x_cshare  ),    0);
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   0)      , "     exec     call the function                    DITTO_parse                 x, y, 21                                                                                              s_equal     pretty expected                                                                                       x_str                ");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   1)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing a LOAD");
   yUNIT_minval   ("write conv line"                    , CONV_load      (x_file    , "load"    , "prepare input"       , "stdin"          , ""               , ""          , "test ß 15 ß a"  , ""          , '-', '-', ""  , &x_cshare  ),    0);
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   0)      , "     exec     call the function                    DITTO_parse                 x, y, 21                                                                                              s_equal     pretty expected                                                                                       x_str                ");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   1)      , "     load     prepare input                        stdin                       test ß 15 ß a                                                                                                                                                                                                              ");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   2)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing a FILE");
   yUNIT_minval   ("write conv line"                    , CONV_file      (x_file    , "file"    , "read for writing"    , ""               , ""               , ""          , "[[ my.file ]]"  , ""          , '-', '-', ""  , &x_cshare  ),    0);
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   0)      , "     exec     call the function                    DITTO_parse                 x, y, 21                                                                                              s_equal     pretty expected                                                                                       x_str                ");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   1)      , "     load     prepare input                        stdin                       test ß 15 ß a                                                                                                                                                                                                              ");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   2)      , "     file     read for writing                     - - - - - - - - - - - - -   [[ my.file ]]                                                                                                                                                                                                              ");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   3)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing an APPEND");
   yUNIT_minval   ("write conv line"                    , CONV_append    (x_file    , "append"  , "... add a record"    , ""               , ""               , ""          , "nice data"      , ""          , '-', '-', ""  , &x_cshare  ),    0);
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   0)      , "     exec     call the function                    DITTO_parse                 x, y, 21                                                                                              s_equal     pretty expected                                                                                       x_str                ");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   1)      , "     load     prepare input                        stdin                       test ß 15 ß a                                                                                                                                                                                                              ");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   2)      , "     file     read for writing                     - - - - - - - - - - - - -   [[ my.file ]]                                                                                                                                                                                                              ");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   3)      , "     append   ... add a record                     - - - - - - - - - - - - -   nice data                                                                                                                                                                                                                  "); 
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   4)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing a CODE");
   yUNIT_minval   ("write conv line"                    , CONV_code      (x_file    , "code"    , "update prefix"       , ""               , ""               , ""          , "x_one = 13;"    , ""          , '-', '-', ""  , &x_cshare  ),    0);
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   0)      , "     exec     call the function                    DITTO_parse                 x, y, 21                                                                                              s_equal     pretty expected                                                                                       x_str                ");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   1)      , "     load     prepare input                        stdin                       test ß 15 ß a                                                                                                                                                                                                              ");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   2)      , "     file     read for writing                     - - - - - - - - - - - - -   [[ my.file ]]                                                                                                                                                                                                              ");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   3)      , "     append   ... add a record                     - - - - - - - - - - - - -   nice data                                                                                                                                                                                                                  "); 
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   4)      , "     code     update prefix                        - - - - - - - - - - - - -   x_one = 13;                                                                                                                                                                                                                ");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   5)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing a global variable");
   yUNIT_minval   ("write conv line"                    , CONV_gvar      (x_file    , "global"  , "global variable"     , ""               , ""               , ""          , "short a = 5;"   , ""          , '-', '-', ""  , &x_cshare  ),    0);
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   0)      , "     exec     call the function                    DITTO_parse                 x, y, 21                                                                                              s_equal     pretty expected                                                                                       x_str                ");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   1)      , "     load     prepare input                        stdin                       test ß 15 ß a                                                                                                                                                                                                              ");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   2)      , "     file     read for writing                     - - - - - - - - - - - - -   [[ my.file ]]                                                                                                                                                                                                              ");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   3)      , "     append   ... add a record                     - - - - - - - - - - - - -   nice data                                                                                                                                                                                                                  "); 
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   4)      , "     code     update prefix                        - - - - - - - - - - - - -   x_one = 13;                                                                                                                                                                                                                ");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   5)      , "   global     global variable                      - - - - - - - - - - - - -   short a = 5;                                                                                                                                                                                                               ");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   6)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing a local variable");
   yUNIT_minval   ("write conv line"                    , CONV_code      (x_file    , "local"   , "local variable"      , ""               , ""               , ""          , "char rc = 0;"   , ""          , '-', '-', ""  , &x_cshare  ),    0);
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   0)      , "     exec     call the function                    DITTO_parse                 x, y, 21                                                                                              s_equal     pretty expected                                                                                       x_str                ");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   1)      , "     load     prepare input                        stdin                       test ß 15 ß a                                                                                                                                                                                                              ");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   2)      , "     file     read for writing                     - - - - - - - - - - - - -   [[ my.file ]]                                                                                                                                                                                                              ");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   3)      , "     append   ... add a record                     - - - - - - - - - - - - -   nice data                                                                                                                                                                                                                  "); 
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   4)      , "     code     update prefix                        - - - - - - - - - - - - -   x_one = 13;                                                                                                                                                                                                                ");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   5)      , "   global     global variable                      - - - - - - - - - - - - -   short a = 5;                                                                                                                                                                                                               ");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   6)      , "     local    local variable                       - - - - - - - - - - - - -   char rc = 0;                                                                                                                                                                                                               ");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   7)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing an ECHO");
   yUNIT_minval   ("write conv line"                    , CONV_echo      (x_file    , "echo"    , "... check value"     , ""               , "x_act"          , "s_equal"   , "[[ x_exp ]]"    , ""          , '-', '-', ""  , &x_cshare  ),    0);
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   0)      , "     exec     call the function                    DITTO_parse                 x, y, 21                                                                                              s_equal     pretty expected                                                                                       x_str                ");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   1)      , "     load     prepare input                        stdin                       test ß 15 ß a                                                                                                                                                                                                              ");
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
   yUNIT_mindnoc  ();

   PROG__unit_end    ();
   rm_working_files ();
   yUNIT_minprcs  ();
   return 0;
}

char
koios__unit_conv_driver  (char a_list)
{
   char         x_name     [LEN_HUND]  = "apate.unit";
   char         t          [LEN_HUND]  = "";
   FILE        *x_file     = NULL;
   char         x_cshare   =  '-';

   yUNIT_minscrp  ("CONV_driver");
   if (a_list == 'y')  return 0;
   yURG_err_none  ();
   rm_working_files ();
   PROG__unit_quiet  ();

   yUNIT_mincond  ("verify creating and writing the opening");
   yUNIT_minval   ("write conv line"                    , CONV_header     (x_name, &x_file, &x_cshare),    0);
   yUNIT_minval   ("write conv line"                    , CONV_prep       (x_file    , "PREP"    , "prototype headers"   , ""               , ""               , ""          , ""               , ""          , '-', '-', ""  , &x_cshare  ),    0);
   yUNIT_minval   ("write conv line"                    , CONV_incl       (x_file    , "incl"    , "public header"       , "apate.h"        , ""               , ""          , ""               , ""          , '-', '-', ""  , &x_cshare  ),    0);
   yUNIT_minval   ("... check count"                    , yURG_peek_count (x_name)               , 9);
   yUNIT_minstr   ("... header"                         , yURG_peek       (x_name    ,   0)      , "#!/usr/local/bin/koios"                   );
   yUNIT_minstr   ("... header"                         , yURG_peek       (x_name    ,   1)      , "#   koios-polos (axis of heaven) unit testing meta-language" );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   2)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   3)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   4)      , ""                                         );
   yUNIT_minstr   ("... ruler"                          , yURG_peek       (x_name    ,   5)      , "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-123456789- ");
   yUNIT_minstr   ("... title"                          , yURG_peek       (x_name    ,   6)      , "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  ========(var)======= ");
   yUNIT_minstr   ("... check resuls"                   , yURG_peek       (x_name    ,   7)      , "PREP          prototype headers                                                  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check resuls"                   , yURG_peek       (x_name    ,   8)      , "   incl       public header                        apate.h                     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   9)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing a SCRP");
   yUNIT_minval   ("write conv line"                    , CONV_driver     (CONV_scrp             , x_file    , "SCRP"    , "sample testing"      , "CONV_scrp"      , ""               , "5s"        , ""               , "test"      , '-', '-', "¬Ú", &x_cshare  ),    0);
   yUNIT_minval   ("... check count"                    , yURG_peek_count (x_name)               , 15);
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   9)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  10)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  11)      , ""                                         );
   yUNIT_minstr   ("... ruler"                          , yURG_peek       (x_name    ,  12)      , "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-123456789- ");
   yUNIT_minstr   ("... title"                          , yURG_peek       (x_name    ,  13)      , "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  ========(var)======= ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  14)      , "SCRP    [¬Ú]  sample testing                                                     5s   test            CONV_scrp                                                                    ((01.---))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  15)      , ""                                         );

   yUNIT_mincond  ("verify writing a COND");               
   yUNIT_minval   ("write conv line"                    , CONV_driver     (CONV_cond             , x_file    , "COND"    , "repeating condition" , ""               , ""               , ""          , ""               , ""          , '-', '2', ""  , &x_cshare  ),    0);
   yUNIT_minval   ("write conv line"                    , CONV_driver     (CONV_exec             , x_file    , "exec"    , "call the function"   , "DITTO_parse"    , "x, y, 21"       , "s_equal"   , "pretty expected", "x_str"     , '-', '-', ""  , &x_cshare  ),    0);
   yUNIT_minval   ("write conv line"                    , CONV_driver     (CONV_code             , x_file    , "code"    , "update prefix"       , ""               , ""               , ""          , "x_one = 13;"    , ""          , '-', '-', ""  , &x_cshare  ),    0);
   yUNIT_minval   ("... check count"                    , yURG_peek_count (x_name)               , 19);
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  15)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  16)      , "   COND  (2)  repeating condition                                                - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((01.001))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  17)      , "     exec     call the function                    DITTO_parse                 x, y, 21                                                                                              s_equal     pretty expected                                                                                       x_str                ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  18)      , "     code     update prefix                        - - - - - - - - - - - - -   x_one = 13;                                                                                                                                                                                                                ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  19)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing another COND");               
   yUNIT_minval   ("write conv line"                    , CONV_driver     (CONV_cond             , x_file    , "COND"    , "another condition"   , ""               , ""               , ""          , ""               , ""          , '-', '-', ""  , &x_cshare  ),    0);
   yUNIT_minval   ("write conv line"                    , CONV_driver     (CONV_echo             , x_file    , "echo"    , "... check value"     , ""               , "x_act"          , "s_equal"   , "[[ x_exp ]]"    , ""          , '-', '-', ""  , &x_cshare  ),    0);
   yUNIT_minval   ("... check count"                    , yURG_peek_count (x_name)               , 22);
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  19)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  20)      , "   COND       another condition                                                  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((01.002))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  21)      , "     echo     ... check value                      - - - - - - - - - - - - -   x_act                                                                                                 s_equal     [[ x_exp ]]                                                                                          ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  22)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing another SCRP");
   yUNIT_minval   ("write conv line"                    , CONV_driver     (CONV_scrp             , x_file    , "SCRP"    , "check numbering"     , "CONV_cond"      , ""               , "10m"       , ""               , "another"   , '-', '-', "√˘", &x_cshare  ),    0);
   yUNIT_minval   ("... check count"                    , yURG_peek_count (x_name)               , 28);
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  22)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  23)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  24)      , ""                                         );
   yUNIT_minstr   ("... ruler"                          , yURG_peek       (x_name    ,  25)      , "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-123456789- ");
   yUNIT_minstr   ("... title"                          , yURG_peek       (x_name    ,  26)      , "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  ========(var)======= ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  27)      , "SCRP    [√˘]  check numbering                                                    10m  another         CONV_cond                                                                    ((02.---))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  28)      , ""                                         );

   yUNIT_mincond  ("verify writing COND in second SCRP");               
   yUNIT_minval   ("write conv line"                    , CONV_driver     (CONV_cond             , x_file    , "COND"    , "checking"            , ""               , ""               , ""          , ""               , ""          , '-', '-', ""  , &x_cshare  ),    0);
   yUNIT_minval   ("write conv line"                    , CONV_driver     (CONV_code             , x_file    , "local"   , "local variable"      , ""               , ""               , ""          , "char rc = 0;"   , ""          , '-', '-', ""  , &x_cshare  ),    0);
   yUNIT_minval   ("... check count"                    , yURG_peek_count (x_name)               , 31);
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  28)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  29)      , "   COND       checking                                                           - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((02.001))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  30)      , "     local    local variable                       - - - - - - - - - - - - -   char rc = 0;                                                                                                                                                                                                               ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  31)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing FOOTER and closing file");
   yUNIT_minval   ("write conv line"                    , CONV_footer     ('y', &x_file, x_name, "")       ,    0);
   yUNIT_minval   ("... check count"                    , yURG_peek_count (x_name)               , 35);
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  31)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  32)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  33)      , ""                                         );
   yUNIT_minstr   ("... footer"                         , yURG_peek       (x_name    ,  34)      , "# end-of-file.  done, finito, completare, whimper [œ¥∑∑∑");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  35)      , ""                                         );
   yUNIT_mindnoc  ();

   PROG__unit_end    ();
   rm_working_files ();
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
   rm_working_files ();
   PROG__unit_quiet  ();

   yUNIT_mincond  ("verify quick success");
   yUNIT_minval   ("convert code"                       , CODE__display    ("a = 5;"                                                             , x_display, x_system , x_load   ),    0);
   yUNIT_minstr   ("... check display"                  , x_display     , "a = 5;");
   yUNIT_minstr   ("... check system"                   , x_system      , "a = 5;");
   yUNIT_minstr   ("... check load"                     , x_load        , "a = 5;");
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify field and group markers");
   yUNIT_minval   ("convert code"                       , CODE__display    ("verb ß field ® 123 ß"                                               , x_display, x_system , x_load   ),    0);
   yUNIT_minstr   ("... check display"                  , x_display     , "verb ß field ® 123 ß");
   yUNIT_minstr   ("... check system"                   , x_system      , "verb  field  123 ");
   yUNIT_minstr   ("... check load"                     , x_load        , "verb  field  123 ");
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify extended characters");
   yUNIT_minval   ("convert code"                       , CODE__display    ("¥ ∑ ≥ Æ † È € ä"                                                    , x_display, x_system , x_load   ),    0);
   yUNIT_minstr   ("... check display"                  , x_display     , "¥ ∑ ≥ Æ † È € ä");
   yUNIT_minstr   ("... check system"                   , x_system      , "¥ ∑ ≥ Æ † È € ä");
   yUNIT_minstr   ("... check load"                     , x_load        , "¥ ∑ ≥ Æ † È € ä");
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify quotes");
   yUNIT_minval   ("convert code"                       , CODE__display    ("the \"quoted\" text"                                                , x_display, x_system , x_load   ),    0);
   yUNIT_minstr   ("... check display"                  , x_display     , "the ∂quoted∂ text");
   yUNIT_minstr   ("... check system"                   , x_system      , "the \"quoted\" text");
   yUNIT_minstr   ("... check load"                     , x_load        , "the ~quoted~ text");
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify returns and escapes");
   yUNIT_minval   ("convert code"                       , CODE__display    (":macro\n or ¶ and \e end or •"                                      , x_display, x_system , x_load   ),    0);
   yUNIT_minstr   ("... check display"                  , x_display     , ":macro¶ or ¶ and • end or •");
   yUNIT_minstr   ("... check system"                   , x_system      , ":macro\\n or ¶ and \\e end or •");
   yUNIT_minstr   ("... check load"                     , x_load        , ":macro\\n or ¶ and \\e end or •");
   yUNIT_mindnoc  ();

   PROG__unit_end    ();
   rm_working_files ();
   yUNIT_minprcs  ();
   return 0;
}

char
koios__unit_code_prefix  (char a_list)
{
   char         x_name     [LEN_HUND] = "apate.c";
   FILE        *x_file     = NULL;
   char         x_display  [LEN_RECD]  = "";
   char         x_system   [LEN_RECD]  = "";
   char         x_load     [LEN_RECD]  = "";
   char         t          [LEN_HUND] = "";

   yUNIT_minscrp  ("CODE__prefix");
   if (a_list == 'y')  return 0;
   yURG_err_none  ();
   rm_working_files ();
   PROG__unit_quiet  ();

   sprintf (t, "rm -f %s 2> /dev/null", x_name);
   system (t);
   yUNIT_mincond ("prepare clean start");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond  ("open code file");
   yUNIT_minval   ("open the code file"                 , READ_open   (x_name, 'w', &x_file, NULL   ),    0);
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify quick success (string)");
   yUNIT_minval   ("convert code"                       , CODE__display    ("\"arguments\""                                                    , x_display, x_system , x_load   ),    0);
   yUNIT_minval   ("write prefix code"                  , CODE__prefix     (x_file    , "exec"    , "call the function"   , "DITTO_parse"    , "s_equal"   , x_display, x_system , '-',   0,   0),    0);
   CONV_printf   (x_file, "\n");
   fflush (x_file);
   yUNIT_minval   ("... check count"                    , yURG_peek_count  (x_name)               , 3);
   yUNIT_minstr   ("... header"                         , yURG_peek        (x_name    ,   0)      , "      yUNIT_reset_rc ();"                 );
   yUNIT_minstr   ("... header"                         , yURG_peek        (x_name    ,   1)      , "      if (cyUNIT.exec)  cyUNIT.s_rc = DITTO_parse (\"arguments\");");
   yUNIT_minstr   ("... header"                         , yURG_peek        (x_name    ,   2)      , "      yUNIT_string  (   0,   0, \"call the function\", \"DITTO_parse\", \"∂arguments∂\", \"s_equal\", ");
   yUNIT_minstr   ("... header"                         , yURG_peek        (x_name    ,   3)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify a void");
   yUNIT_minval   ("convert code"                       , CODE__display    ("15, 67"                                                           , x_display, x_system , x_load   ),    0);
   yUNIT_minval   ("write prefix code"                  , CODE__prefix     (x_file    , "exec"    , "deal with a void"    , "MAIN_driver"    , "v_void"    , x_display, x_system , '-',   0,   0),    0);
   fflush (x_file);
   yUNIT_minval   ("... check count"                    , yURG_peek_count  (x_name)               , 6);
   yUNIT_minstr   ("... header"                         , yURG_peek        (x_name    ,   3)      , "      yUNIT_reset_rc ();"                 );
   yUNIT_minstr   ("... header"                         , yURG_peek        (x_name    ,   4)      , "      if (cyUNIT.exec)  MAIN_driver (15, 67);");
   yUNIT_minstr   ("... header"                         , yURG_peek        (x_name    ,   5)      , "      yUNIT_void    (   0,   0, \"deal with a void\", \"MAIN_driver\", \"15, 67\", \"v_void\", cyUNIT.exec);");
   yUNIT_minstr   ("... header"                         , yURG_peek        (x_name    ,   6)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify an integer");
   yUNIT_minval   ("convert code"                       , CODE__display    ("3"                                                                , x_display, x_system , x_load   ),    0);
   yUNIT_minval   ("write prefix code"                  , CODE__prefix     (x_file    , "exec"    , "cube a number"       , "cube"           , "i_equal"   , x_display, x_system , '-',   0,   0),    0);
   CONV_printf   (x_file, "\n");
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
   yUNIT_mindnoc  ();

   PROG__unit_end    ();
   rm_working_files ();
   yUNIT_minprcs  ();
   return 0;
}

char
koios__unit_code_expect  (char a_list)
{
   char         x_name     [LEN_HUND] = "apate.c";
   FILE        *x_file     = NULL;
   char         x_display  [LEN_RECD]  = "";
   char         x_system   [LEN_RECD]  = "";
   char         x_load     [LEN_RECD]  = "";
   char         t          [LEN_HUND]  = "";

   yUNIT_minscrp  ("CODE__expect");
   if (a_list == 'y')  return 0;
   yURG_err_none  ();
   rm_working_files ();
   PROG__unit_quiet  ();

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
   CONV_printf   (x_file, "\n");
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
   CONV_printf   (x_file, "\n");
   fflush (x_file);
   yUNIT_minval   ("... check count"                    , yURG_peek_count  (x_name)               , 2);
   yUNIT_minstr   ("... header"                         , yURG_peek        (x_name    ,   1)      , "0x123456, "                               );
   yUNIT_minstr   ("... header"                         , yURG_peek        (x_name    ,   2)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify matching variable");
   yUNIT_minval   ("write expect code"                  , CODE__expect     (x_file    , "any"       , "[[ x_var ]]"             ),    2);
   CONV_printf   (x_file, "\n");
   fflush (x_file);
   yUNIT_minval   ("... check count"                    , yURG_peek_count  (x_name)               , 3);
   yUNIT_minstr   ("... header"                         , yURG_peek        (x_name    ,   2)      , "x_var, "                                  );
   yUNIT_minstr   ("... header"                         , yURG_peek        (x_name    ,   3)      , ""                                         );
   yUNIT_mindnoc  ();

   yURG_err_clear ();
   yUNIT_mincond  ("open code file");
   yUNIT_minval   ("close the script file"              , READ_close  (&x_file)                 , 0);
   yUNIT_mindnoc  ();

   PROG__unit_end    ();
   rm_working_files ();
   yUNIT_minprcs  ();
   return 0;
}

char
koios__unit_code_suffix  (char a_list)
{
   char         x_name     [LEN_HUND] = "apate.c";
   FILE        *x_file     = NULL;
   char         x_display  [LEN_RECD]  = "";
   char         x_system   [LEN_RECD]  = "";
   char         x_load     [LEN_RECD]  = "";
   char         t          [LEN_HUND]  = "";

   yUNIT_minscrp  ("CODE__suffix");
   if (a_list == 'y')  return 0;
   yURG_err_none  ();
   rm_working_files ();
   PROG__unit_quiet  ();

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
   yUNIT_minstr   ("... check line"                     , yURG_peek        (x_name    ,   2)      , "      if (cyUNIT.exec) { if (cyUNIT.s_rc != NULL)  strcpy (x_str, cyUNIT.s_rc); else strcpy (x_str, \"\"); }");
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
   yUNIT_minstr   ("... check line"                     , yURG_peek        (x_name    ,   4)      , "      if (cyUNIT.exec)  n = cyUNIT.i_rc;" );
   yUNIT_minstr   ("... check line"                     , yURG_peek        (x_name    ,   5)      , ""                                         );
   yUNIT_mindnoc  ();

   yURG_err_clear ();
   yUNIT_mincond  ("open code file");
   yUNIT_minval   ("close the script file"              , READ_close  (&x_file)                 , 0);
   yUNIT_mindnoc  ();

   PROG__unit_end    ();
   rm_working_files ();
   yUNIT_minprcs  ();
   return 0;
}

char
koios__unit_code_steps   (char a_list)
{
   char         x_name     [LEN_HUND] = "apate.c";
   FILE        *x_main     = NULL;
   FILE        *x_file     = NULL;
   FILE        *x_wave     = NULL;
   char         x_cshare   =  '-';
   char         t          [LEN_HUND]  = "";

   yUNIT_minscrp  ("CODE_exec, CODE_echo, CODE_get");
   if (a_list == 'y')  return 0;
   yURG_err_none  ();
   rm_working_files ();
   PROG__unit_quiet  ();

   sprintf (t, "rm -f %s 2> /dev/null", x_name);
   system (t);
   yUNIT_mincond ("prepare clean start");
   yUNIT_minval   ("clear statistics"                   , CODE_init   (),    0);
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond  ("open files");
   yUNIT_minval   ("open the main file"                 , READ_open   ("other"     , 'w', &x_main, NULL   ),    0);
   yUNIT_minval   ("open the code file"                 , READ_open   (x_name      , 'w', &x_file, NULL   ),    0);
   yUNIT_minval   ("open the wave file"                 , READ_open   ("wave"      , 'w', &x_wave, NULL   ),    0);
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing an EXEC");
   yUNIT_minval   ("write code line"                    , CODE_exec      (x_name    , x_main    , x_file    , x_wave    , G_RUN_CREATE, "----", "exec"  , "call the function"   , "DITTO_parse"    , "x, y, 21"       , "s_equal"   , "pretty expected", "x_str"     , ""   , '-', '-', '-',   0,   0, '-', &x_cshare),    0);
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   0)      , "      /*---(run step)--------------------*/"               );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "      yUNIT_reset_rc ();"                                  );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "      if (cyUNIT.exec)  cyUNIT.s_rc = DITTO_parse (x, y, 21);" );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "      yUNIT_string  (   0,   1, \"call the function\", \"DITTO_parse\", \"x, y, 21\", \"s_equal\", \"pretty expected\", cyUNIT.s_rc, cyUNIT.exec);");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "      if (cyUNIT.exec) { if (cyUNIT.s_rc != NULL)  strcpy (x_str, cyUNIT.s_rc); else strcpy (x_str, \"\"); }" );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing an EXEC (in debug)");
   yUNIT_minval   ("write code line"                    , CODE_exec      (x_name    , x_main    , x_file    , x_wave    , G_RUN_DEBUG , "----", "exec"  , "call the function"   , "DITTO_parse"    , "x, y, 21"       , "s_equal"   , "pretty expected", "x_str"     , ""   , '-', '-', '-',   0,   0, '-', &x_cshare),    0);
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '¥')      , "      /*---(run step)--------------------*/"               );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "      DEBUG_PROG    yLOG_unitstep (cyUNIT.origin, cyUNIT.offset +   0,   2,    0, \"call the function\");" );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "      yUNIT_reset_rc ();"                                  );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "      if (cyUNIT.exec)  cyUNIT.s_rc = DITTO_parse (x, y, 21);" );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "      yUNIT_string  (   0,   2, \"call the function\", \"DITTO_parse\", \"x, y, 21\", \"s_equal\", \"pretty expected\", cyUNIT.s_rc, cyUNIT.exec);");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "      if (cyUNIT.exec) { if (cyUNIT.s_rc != NULL)  strcpy (x_str, cyUNIT.s_rc); else strcpy (x_str, \"\"); }" );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing an ECHO");
   yUNIT_minval   ("write code line"                    , CODE_exec      (x_name    , x_main    , x_file    , x_wave    , G_RUN_CREATE, "----", "echo"  , "check key variable"  , ""               , "x_var"          , "i_equal"   , "27"             , ""          , ""   , '-', '-', '-',   0,   0, '-', &x_cshare),    0);
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '¥')      , "      /*---(echo to verify)--------------*/"               );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "      yUNIT_int     (   0,   3, \"check key variable\", \"\", \"x_var\", \"i_equal\", 27, x_var, cyUNIT.exec);");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing a GET");
   yUNIT_minval   ("write code line"                    , CODE_exec      (x_name    , x_main    , x_file    , x_wave    , G_RUN_CREATE, "----", "get"   , "verify result"       , "DITTO__unit"    , "15"             , "s_equal"   , "test string"    , ""          , ""   , '-', '-', '-',   0,   0, '-', &x_cshare),    0);
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '¥')      , "      /*---(check result)----------------*/"               );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "      yUNIT_reset_rc ();"                                  );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "      if (cyUNIT.exec)  cyUNIT.s_rc = DITTO__unit (15);" );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "      yUNIT_string  (   0,   4, \"verify result\", \"DITTO__unit\", \"15\", \"s_equal\", \"test string\", cyUNIT.s_rc, cyUNIT.exec);");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , ""                                         );
   yUNIT_mindnoc  ();

   yURG_err_clear ();
   yUNIT_mincond  ("open code file");
   yUNIT_minval   ("close the wave file"                , READ_close  (&x_wave)                 , 0);
   yUNIT_minval   ("close the code file"                , READ_close  (&x_file)                 , 0);
   yUNIT_minval   ("close the main file"                , READ_close  (&x_main)                 , 0);
   yUNIT_mindnoc  ();

   PROG__unit_end    ();
   rm_working_files ();
   yUNIT_minprcs  ();
   return 0;
}

char
koios__unit_code_vars    (char a_list)
{
   char         x_name     [LEN_HUND] = "apate.c";
   FILE        *x_main     = NULL;
   FILE        *x_file     = NULL;
   FILE        *x_wave     = NULL;
   char         x_cshare   =  '-';
   char         t          [LEN_HUND]  = "";

   yUNIT_minscrp  ("CODE_gvar, CODE_lvar, CODE_code");
   if (a_list == 'y')  return 0;
   yURG_err_none  ();
   rm_working_files ();
   PROG__unit_quiet  ();

   sprintf (t, "rm -f %s 2> /dev/null", x_name);
   system (t);
   yUNIT_mincond ("prepare clean start");
   yUNIT_minval   ("clear statistics"                   , CODE_init   (),    0);
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond  ("open files");
   yUNIT_minval   ("open the main file"                 , READ_open   ("other"     , 'w', &x_main, NULL   ),    0);
   yUNIT_minval   ("open the code file"                 , READ_open   (x_name      , 'w', &x_file, NULL   ),    0);
   yUNIT_minval   ("open the wave file"                 , READ_open   ("wave"      , 'w', &x_wave, NULL   ),    0);
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing an global variable");
   yUNIT_minval   ("write code line"                    , CODE_gvar      (x_name    , x_main    , x_file    , x_wave    , G_RUN_CREATE, "----", "global", "working variable"    , ""               , ""               , ""          , "int g_var = 42;", ""          , ""   , '-', '-', '-',   0,   0, '-', &x_cshare),    0);
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   0)      , "/*---(global variable)-------------*/"                     );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "int g_var = 42;"                                           );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing a local variable");
   yUNIT_minval   ("write code line"                    , CODE_lvar      (x_name    , x_main    , x_file    , x_wave    , G_RUN_CREATE, "----", "local" , "return variable"     , ""               , ""               , ""          , "char x_var = 0;", ""          , ""   , '-', '-', '-',   0,   0, '-', &x_cshare),    0);
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   2)      , "      /*---(local variable)--------------*/"               );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "      yUNIT_local   (   0,   2, \"return variable\", \"char x_var = 0;\", cyUNIT.exec);");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "      char x_var = 0;"                                     );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing a CODE");
   yUNIT_minval   ("write code line"                    , CODE_code      (x_name    , x_main    , x_file    , x_wave    , G_RUN_CREATE, "----", "code"  , "add variables"       , ""               , ""               , ""          , "a = x∆ + y∆;"   , ""          , ""   , '-', '-', '-',   0,   0, '-', &x_cshare),    0);
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   5)      , "      /*---(inject code)-----------------*/"               );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "      yUNIT_code    (   0,   3, \"add variables\", \"a = x∆ + y∆;\", cyUNIT.exec);");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "      if (cyUNIT.exec) { a = x∆ + y∆; }"                                        );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , ""                                         );
   yUNIT_mindnoc  ();

   yURG_err_clear ();
   yUNIT_mincond  ("open code file");
   yUNIT_minval   ("close the script file"              , READ_close  (&x_file)                 , 0);
   yUNIT_mindnoc  ();

   PROG__unit_end    ();
   rm_working_files ();
   yUNIT_minprcs  ();
   return 0;
}

char
koios__unit_code_spec    (char a_list)
{
   char         x_name     [LEN_HUND] = "apate.c";
   FILE        *x_main     = NULL;
   FILE        *x_file     = NULL;
   FILE        *x_wave     = NULL;
   char         x_cshare   =  '-';
   char         t          [LEN_HUND]  = "";

   yUNIT_minscrp  ("CODE_load, CODE_mode, CODE_system, CODE_file, CODE_append");
   if (a_list == 'y')  return 0;
   yURG_err_none  ();
   rm_working_files ();
   PROG__unit_quiet  ();

   sprintf (t, "rm -f %s 2> /dev/null", x_name);
   system (t);
   yUNIT_mincond ("prepare clean start");
   yUNIT_minval   ("clear statistics"                   , CODE_init   (),    0);
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond  ("open files");
   yUNIT_minval   ("open the main file"                 , READ_open   ("other"     , 'w', &x_main, NULL   ),    0);
   yUNIT_minval   ("open the code file"                 , READ_open   (x_name      , 'w', &x_file, NULL   ),    0);
   yUNIT_minval   ("open the wave file"                 , READ_open   ("wave"      , 'w', &x_wave, NULL   ),    0);
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing a LOAD");
   yUNIT_minval   ("write code line"                    , CODE_load      (x_name    , x_main    , x_file    , x_wave    , G_RUN_CREATE, "----", "load"  , "prepare stdin"       , "stdin"          , ""               , ""          , "shove this"     , ""          , ""   , '-', '-', '-',   0,   0, '-', &x_cshare),    0);
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   0)      , "      /*---(load input)------------------*/"               );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "      yUNIT_load    (   0,   1, \"prepare stdin\", \"stdin\", \"shove this\", cyUNIT.exec);");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing a MODE");
   yUNIT_minval   ("write code line"                    , CODE_mode      (x_name    , x_main    , x_file    , x_wave    , G_RUN_CREATE, "----", "mode"  , "FORCED_FAIL"         , ""               , ""               , ""          , ""               , ""          , ""   , '-', '-', '-',   0,   0, '-', &x_cshare),    0);
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '¥')      , "      /*---(unit test mode)--------------*/"               );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "      yUNIT_mode    (   0,   2, \"FORCED_FAIL\", cyUNIT.exec);");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing a SYSTEM");
   yUNIT_minval   ("write code line"                    , CODE_system    (x_name    , x_main    , x_file    , x_wave    , G_RUN_CREATE, "----", "system", "check directory"     , ""               , ""               , ""          , "ls -l"          , ""          , ""   , '-', '-', '-',   0,   0, '-', &x_cshare),    0);
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '¥')      , "      /*---(system command)--------------*/"               );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "      yUNIT_system  (   0,   3, \"check directory\", \"ls -l\", \"ls -l\", cyUNIT.exec);");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing a FILE");
   yUNIT_minval   ("write code line"                    , CODE_file      (x_name    , x_main    , x_file    , x_wave    , G_RUN_CREATE, "----", "file"  , "testing file"        , ""               , ""               , ""          , "test.txt"       , ""          , ""   , '-', '-', '-',   0,   0, '-', &x_cshare),    0);
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '¥')      , "      /*---(create test file)------------*/"               );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "      yUNIT_file    (   0,   4, \"testing file\", \"test.txt\", cyUNIT.exec);");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing an APPEND");
   yUNIT_minval   ("write code line"                    , CODE_append    (x_name    , x_main    , x_file    , x_wave    , G_RUN_CREATE, "----", "append", "add a line"          , ""               , ""               , ""          , "hello world"    , ""          , ""   , '-', '-', '-',   0,   0, '-', &x_cshare),    0);
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '¥')      , "      /*---(append test file)------------*/"               );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "      yUNIT_append  (   0,   5, \"add a line\", \"hello world\", cyUNIT.exec);");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , ""                                         );
   yUNIT_mindnoc  ();

   yURG_err_clear ();
   yUNIT_mincond  ("open code file");
   yUNIT_minval   ("close the wave file"                , READ_close  (&x_wave)                 , 0);
   yUNIT_minval   ("close the code file"                , READ_close  (&x_file)                 , 0);
   yUNIT_minval   ("close the main file"                , READ_close  (&x_main)                 , 0);
   yUNIT_mindnoc  ();

   PROG__unit_end    ();
   rm_working_files ();
   yUNIT_minprcs  ();
   return 0;
}

char
koios__unit_code_cond    (char a_list)
{
   char         x_name     [LEN_HUND] = "apate.c";
   FILE        *x_main     = NULL;
   FILE        *x_file     = NULL;
   FILE        *x_wave     = NULL;
   char         x_cshare   =  '-';
   char         t          [LEN_HUND]  = "";

   yUNIT_minscrp  ("CODE_cond, CODE_group, CODE_reuse");
   if (a_list == 'y')  return 0;
   yURG_err_none  ();
   rm_working_files ();
   PROG__unit_quiet  ();

   sprintf (t, "rm -f %s 2> /dev/null", x_name);
   system (t);
   yUNIT_mincond ("prepare clean start");
   yUNIT_minval   ("clear statistics"                   , CODE_init   (),    0);
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond  ("open files");
   yUNIT_minval   ("open the main file"                 , READ_open   ("other"      , 'w', &x_main, NULL   ),    0);
   yUNIT_minval   ("open the code file"                 , READ_open   (x_name      , 'w', &x_file, NULL   ),    0);
   yUNIT_minval   ("open the wave file"                 , READ_open   ("wave"       , 'w', &x_wave, NULL   ),    0);
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing a GROUP (before first COND)");
   yUNIT_minval   ("write code line"                    , CODE_group     (x_name    , x_main    , x_file    , x_wave    , G_RUN_CREATE, "----", "GROUP" , "up front"            , ""               , ""               , ""          , ""               , ""          , ""   , '-', '-', '-',   0,   0, '-', &x_cshare),    0);
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   0)      , "   /*---(group)--------------------------*/");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "   yUNIT_group   (\"up front\");"           );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , ""                                           );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing an COND");
   yUNIT_minval   ("write code line"                    , CODE_cond      (x_name    , x_main    , x_file    , x_wave    , G_RUN_CREATE, "----" , "COND"  , "preparation"         , ""               , ""               , ""          , ""               , ""          , ""   , '-', '-', '-',   0,   0, '-', &x_cshare),    0);
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '¥')      , "   /*===[[ COND #001 ]]============================*/");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "   yUNIT_cond    (   0, cyUNIT.offset +   1, '-', \"preparation\");");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , ""                                           );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing a GROUP");
   yUNIT_minval   ("write code line"                    , CODE_group     (x_name    , x_main    , x_file    , x_wave    , G_RUN_CREATE, "----" , "GROUP" , "little stuff"        , ""               , ""               , ""          , ""               , ""          , ""   , '-', '-', '-',   0,   0, '-', &x_cshare),    0);
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '¥')      , "      /*---(summary)---------------------*/");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "      yUNIT_dnoc    (cyUNIT.exec);"         );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "      /*---(done)------------------------*/");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "   /*---(group)--------------------------*/");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "   yUNIT_group   (\"little stuff\");");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , ""                                           );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing a REUSE");
   yUNIT_minval   ("write code line"                    , CODE_reuse     (x_name    , x_main    , x_file    , x_wave    , G_RUN_CREATE, "GROUP", "REUSE" , "little stuff"        , ""               , ""               , ""          , ""               , ""          , ""   , '-', '-', '-',   0,   0, 'd', &x_cshare),    0);
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '¥')      , "   /*---(shared code)--------------------*/");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "   cyUNIT.offset = 1;"                      );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "   yUNIT_shared_d ();"                      );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "   cyUNIT.offset = 0;"                      );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , ""                                           );
   yUNIT_mindnoc  ();

   yURG_err_clear ();
   yUNIT_mincond  ("open code file");
   yUNIT_minval   ("close the wave file"                , READ_close  (&x_wave)                 , 0);
   yUNIT_minval   ("close the code file"                , READ_close  (&x_file)                 , 0);
   yUNIT_minval   ("close the main file"                , READ_close  (&x_main)                 , 0);
   yUNIT_mindnoc  ();

   PROG__unit_end    ();
   rm_working_files ();
   yUNIT_minprcs  ();
   return 0;
}

char
koios__unit_code_scrp    (char a_list)
{
   char         x_name     [LEN_HUND] = "apate.unit";
   FILE        *x_main     = NULL;
   FILE        *x_file     = NULL;
   FILE        *x_wave     = NULL;
   char         x_cshare   =  '-';
   char         t          [LEN_HUND]  = "";

   yUNIT_minscrp  ("CODE_scrp, CODE_sect, CODE_shared, CODE_global");
   if (a_list == 'y')  return 0;
   yURG_err_none  ();
   PROG__unit_quiet  ();
   rm_working_files ();
   PROG__unit_quiet  ();


   sprintf (t, "rm -f %s 2> /dev/null", x_name);
   system (t);
   yUNIT_mincond ("prepare clean start");
   yUNIT_minval   ("clear statistics"                   , CODE_init   (),    0);
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond  ("open files");
   yUNIT_minval   ("open the main file"                 , READ_open   ("other"     , 'w', &x_main, NULL   ),    0);
   yUNIT_minval   ("open the code file"                 , READ_open   (x_name      , 'w', &x_file, NULL   ),    0);
   yUNIT_minval   ("open the wave file"                 , READ_open   ("wave"      , 'w', &x_wave, NULL   ),    0);
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing a SCRP (before anything else)");
   yUNIT_minval   ("write code line"                    , CODE_scrp      (x_name    , x_main    , x_file    , x_wave    , G_RUN_CREATE, "----", "SCRP"  , "first testing"       , ""               , ""               , ""          , ""               , ""          , "¬Ú" , '-', '-', '-',   0,   0, '-', &x_cshare),    0);
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   0)      , ""                                           );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "char"                                       );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "yUNIT_script_01          (void)"            );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "{"                                          );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "   /*===[[ script header ]]========================*/");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "   cyUNIT.offset  = 0;"                     );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "   cyUNIT.origin  = 1;"                     );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "   yUNIT_mode_reset ();"                    );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "   yUNIT_scrp    (   0,   1, \"¬Ú\", \"first testing\", \"\", \"\", \"\");");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , ""                                           );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing to MAIN file)");
   yUNIT_minstr   ("... check MAIN"                     , yURG_peek      ("other"   ,   0)   , "   if (yUNIT_run_scrp ( 1) == 1)  yUNIT_script_01 ();");
   yUNIT_minstr   ("... check MAIN"                     , yURG_peek      ("other"   , '÷')   , ""                                           );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing to WAVE file)");
   yUNIT_minstr   ("... check WAVE"                     , yURG_peek      ("wave"    ,   0)   , "¬  Ú  apate.unit                       1  first testing                                                     ");
   yUNIT_minstr   ("... check WAVE"                     , yURG_peek      ("wave"    , '÷')   , ""                                           );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing an COND");
   yUNIT_minval   ("write code line"                    , CODE_cond      (x_name    , x_main    , x_file    , x_wave    , G_RUN_CREATE, "----" , "COND"  , "preparation"         , ""               , ""               , ""          , ""               , ""          , ""   , '-', '-', '-',   0,   0, '-', &x_cshare),    0);
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,   9)      , "   /*===[[ COND #001 ]]============================*/");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "   yUNIT_cond    (   0, cyUNIT.offset +   1, '-', \"preparation\");");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , ""                                           );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing an EXEC");
   yUNIT_minval   ("write code line"                    , CODE_exec      (x_name    , x_main    , x_file    , x_wave    , G_RUN_CREATE, "----", "exec"  , "call the function"   , "DITTO_parse"    , "x, y, 21"       , "s_equal"   , "pretty expected", "x_str"     , ""   , '-', '-', '-',   0,   0, '-', &x_cshare),    0);
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '¥')      , "      /*---(run step)--------------------*/"               );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "      yUNIT_reset_rc ();"                                  );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "      if (cyUNIT.exec)  cyUNIT.s_rc = DITTO_parse (x, y, 21);" );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "      yUNIT_string  (   0,   1, \"call the function\", \"DITTO_parse\", \"x, y, 21\", \"s_equal\", \"pretty expected\", cyUNIT.s_rc, cyUNIT.exec);");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "      if (cyUNIT.exec) { if (cyUNIT.s_rc != NULL)  strcpy (x_str, cyUNIT.s_rc); else strcpy (x_str, \"\"); }" );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing another SCRP");
   yUNIT_minval   ("write code line"                    , CODE_scrp      (x_name    , x_main    , x_file    , x_wave    , G_RUN_CREATE, "----", "SCRP"  , "second layer"        , ""               , ""               , ""          , ""               , ""          , ""   , '-', '-', '-',   0,   0, '-', &x_cshare),    0);
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,  16)      , "      /*---(summary)---------------------*/");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "      yUNIT_dnoc    (cyUNIT.exec);"         );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "      /*---(done)------------------------*/");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "   /*===[[ script done ]]==========================*/");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "   yUNIT_prcs    (cyUNIT.exec);"            );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "   /*---(complete)-----------------------*/");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "   return 0;"                               );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "}"                                          );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , ""                                           );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "char"                                       );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "yUNIT_script_02          (void)"            );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "{"                                          );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "   /*===[[ script header ]]========================*/");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "   cyUNIT.offset  = 0;"                     );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "   cyUNIT.origin  = 2;"                     );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "   yUNIT_mode_reset ();"                    );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "   yUNIT_scrp    (   0,   2, \"\", \"second layer\", \"\", \"\", \"\");");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , ""                                           );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing to MAIN file)");
   yUNIT_minstr   ("... check MAIN"                     , yURG_peek      ("other"   ,   0)   , "   if (yUNIT_run_scrp ( 1) == 1)  yUNIT_script_01 ();");
   yUNIT_minstr   ("... check MAIN"                     , yURG_peek      ("other"   , '÷')   , "   if (yUNIT_run_scrp ( 2) == 1)  yUNIT_script_02 ();");
   yUNIT_minstr   ("... check MAIN"                     , yURG_peek      ("other"   , '÷')   , ""                                           );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing to WAVE file)");
   yUNIT_minstr   ("... check WAVE"                     , yURG_peek      ("wave"    ,   0)   , "¬  Ú  apate.unit                       1  first testing                                                     ");
   yUNIT_minstr   ("... check WAVE"                     , yURG_peek      ("wave"    , '÷')   , "-  -  apate.unit                       2  second layer                                                      ");
   yUNIT_minstr   ("... check WAVE"                     , yURG_peek      ("wave"    , '÷')   , ""                                           );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing SHARED");
   yUNIT_minval   ("write code line"                    , CODE_shared    (x_name    , x_main    , x_file    , x_wave    , G_RUN_CREATE, "----", "SHARED", "some common data"    , ""               , ""               , ""          , ""               , ""          , ""   , '-', '-', '-',   0,   0, 'o', &x_cshare),    0);
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,  33)      , "   /*===[[ script done ]]==========================*/");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "   yUNIT_prcs    (cyUNIT.exec);"            );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "   /*---(complete)-----------------------*/");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "   return 0;"                               );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "}"                                          );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , ""                                           );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "char"                                       );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "yUNIT_shared_o           (void)"            );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "{"                                          );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "   /*===[[ shared header ]]========================*/");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "   yUNIT_share ('o', \"some common data\");");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , ""                                           );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing GLOBAL");
   yUNIT_minval   ("write code line"                    , CODE_global    (x_name    , x_main    , x_file    , x_wave    , G_RUN_CREATE, "----", "GLOBAL", "critical repeat"     , ""               , ""               , ""          , ""               , ""          , ""   , '-', '-', '-',   0,   0, 'J', &x_cshare),    0);
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,  44)      , "   /*===[[ shared done ]]==========================*/");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "   yUNIT_erahs ('o');"                      );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "   /*---(complete)-----------------------*/");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "   return 0;"                               );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "}"                                          );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , ""                                           );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "char"                                       );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "yUNIT_shared_J           (void)"            );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "{"                                          );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "   /*===[[ global header ]]========================*/");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "   yUNIT_global ('J', \"critical repeat\");");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , ""                                           );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing SECT");
   yUNIT_minval   ("write code line"                    , CODE_sect      (x_name    , x_main    , x_file    , x_wave    , G_RUN_CREATE, "----", "SECT"  , "later stuff"         , ""               , ""               , ""          , ""               , ""          , ""   , '-', '-', '-',   0,   0, '-', &x_cshare),    0);
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    ,  55)      , "   /*===[[ global done ]]==========================*/");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "   yUNIT_labolg ('J');"                     );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "   /*---(complete)-----------------------*/");
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "   return 0;"                               );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , "}"                                          );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , ""                                           );
   yUNIT_minstr   ("... check result"                   , yURG_peek      (x_name    , '÷')      , ""                                           );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing to MAIN file)");
   yUNIT_minstr   ("... check MAIN"                     , yURG_peek      ("other"   ,   0)   , "   if (yUNIT_run_scrp ( 1) == 1)  yUNIT_script_01 ();");
   yUNIT_minstr   ("... check MAIN"                     , yURG_peek      ("other"   , '÷')   , "   if (yUNIT_run_scrp ( 2) == 1)  yUNIT_script_02 ();");
   yUNIT_minstr   ("... check MAIN"                     , yURG_peek      ("other"   , '÷')   , "   if (cyUNIT.all          == 1)  yUNIT_sect      (\"later stuff\");");
   yUNIT_minstr   ("... check MAIN"                     , yURG_peek      ("other"   , '÷')   , ""                                           );
   yUNIT_mindnoc  ();

   yURG_err_clear ();
   yUNIT_mincond  ("open code file");
   yUNIT_minval   ("close the wave file"                , READ_close  (&x_wave)                 , 0);
   yUNIT_minval   ("close the code file"                , READ_close  (&x_file)                 , 0);
   yUNIT_minval   ("close the main file"                , READ_close  (&x_main)                 , 0);
   yUNIT_mindnoc  ();

   PROG__unit_end    ();
   rm_working_files ();
   PROG__unit_end    ();
   yUNIT_minprcs  ();
   return 0;
}

char
koios__unit_code_preps   (char a_list)
{
   char         x_nscrp    [LEN_HUND]  = "apate.unit";
   char         x_nmain    [LEN_HUND]  = "apate_unit.tmp";
   FILE        *x_main     = NULL;
   char         x_ncode    [LEN_HUND]  = "apate.c";
   FILE        *x_code     = NULL;
   char         x_nwave    [LEN_HUND]  = "apate.wave";
   FILE        *x_wave     = NULL;
   char         t          [LEN_HUND]  = "";
   char         x_cshare   =  '-';

   yUNIT_minscrp  ("CODE_header, CODE_footer, ....");
   if (a_list == 'y')  return 0;
   yURG_err_none  ();
   rm_working_files ();
   PROG__unit_quiet  ();

   yUNIT_mincond  ("open the files");
   yUNIT_minval   ("open main"                          , READ_open       (x_nmain, 'w', &x_main, NULL), 0);
   yUNIT_minval   ("open code"                          , READ_open       (x_ncode, 'w', &x_code, NULL), 0);
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing a code beg");
   yUNIT_minval   ("write code beg"                     , CODE__code_beg  (x_nscrp, x_code)   ,    0);
   yUNIT_minval   ("... check count"                    , yURG_peek_count (x_ncode)              , 9);
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   ,   0)      , "/*================================= beg-code =================================*/");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "/* /usr/local/bin/koios                                                       */");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "/*   autogen by koios-polos (axis of heaven) unit testing meta-language       */");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , ""                                                                                );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "/*---(standard support functions)----*/"                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "#include    <yUNIT_unit.h>"                                                      );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "#include    \"master.h\""                                                        );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , ""                                                                                );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "/*================================ beg-script ================================*/");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , ""                                                                                );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing a code stats");
   yUNIT_minval   ("write code stats"                   , CODE__code_stats  (x_code) ,    0);
   yUNIT_minval   ("... check count"                    , yURG_peek_count (x_ncode)              , 17);
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   ,   9)      , ""                                                                                );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "char"                                                                            );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "yUNIT_stats     (void)"                                                          );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "{"                                                                               );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "   yUNIT_unique (0, 0, 0, 0, 0, 0);"                                             );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "   return 0;"                                                                    );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "}"                                                                               );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , ""                                                                                );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , ""                                                                                );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing a code end");
   yUNIT_minval   ("write code end"                     , CODE__code_end  (x_nscrp, x_code)   ,    0);
   yUNIT_minval   ("... check count"                    , yURG_peek_count (x_ncode)              , 19);
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   ,  17)      , ""                                                                                );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "/*================================ end-script ================================*/");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , ""                                                                                );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing a main beg");
   yUNIT_minval   ("write main beg"                     , CODE__main_beg  (x_main, x_nscrp)  ,    0);
   yUNIT_minval   ("... check count"                    , yURG_peek_count (x_nmain)              , 14);
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_nmain   ,   0)      , ""                                                                                );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_nmain   , '÷')      , ""                                                                                );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_nmain   , '÷')      , ""                                                                                );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_nmain   , '÷')      , "int"                                                                             );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_nmain   , '÷')      , "main                    (int a_argc, char *a_argv[])"                            );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_nmain   , '÷')      , "{"                                                                               );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_nmain   , '÷')      , "   /*---(locals)-----------+-----+-----+-*/"                                     );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_nmain   , '÷')      , "   int         rc          =    0;"                                              );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_nmain   , '÷')      , "   /*---(prepare)------------------------*/"                                     );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_nmain   , '÷')      , "   rc = yUNIT_init ();"                                                          );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_nmain   , '÷')      , "   rc = yUNIT_args (a_argc, a_argv);"                                            );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_nmain   , '÷')      , "   if (rc < 0)  return -1;"                                                      );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_nmain   , '÷')      , "   yUNIT_unit (\"apate\", cyUNIT.level, cyUNIT.eterm, cyUNIT.exec);"             );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_nmain   , '÷')      , "   /*---(beg scripts)--------------------*/"                                     );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_nmain   , '÷')      , ""                                                                                );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing a main end");
   yUNIT_minval   ("write main end"                     , CODE__main_end  (x_main)   ,    0);
   yUNIT_minval   ("... check count"                    , yURG_peek_count (x_nmain)              , 24);
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_nmain   ,  14)      , "   /*---(end scripts)--------------------*/"                                     );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_nmain   , '÷')      , "   rc = yUNIT_tinu (cyUNIT.exec);"                                               );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_nmain   , '÷')      , "   /*---(complete)-----------------------*/"                                     );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_nmain   , '÷')      , "   return rc;"                                                                   );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_nmain   , '÷')      , "}"                                                                               );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_nmain   , '÷')      , ""                                                                                );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_nmain   , '÷')      , ""                                                                                );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_nmain   , '÷')      , ""                                                                                );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_nmain   , '÷')      , "/* end-of-file.  done, finito, completare, whimper [œ¥∑∑∑                     */");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_nmain   , '÷')      , "/*================================= end-code =================================*/");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_nmain   , '÷')      , ""                                                                                );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("close the files");
   yUNIT_minval   ("close main"                         , READ_close  (&x_main), 0);
   sprintf (t, "rm -f %s   2> /dev/null", x_nmain);  system (t);
   yUNIT_minval   ("close code"                         , READ_close  (&x_code), 0);
   sprintf (t, "rm -f %s   2> /dev/null", x_ncode);  system (t);
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify calling the header");
   yUNIT_minpoint ("... check main pointer"              , x_main        , 0x0);
   yUNIT_minpoint ("... check code pointer"              , x_code        , 0x0);
   yUNIT_minpoint ("... check wave pointer"              , x_wave        , 0x0);
   yUNIT_minval   ("call header"                        , CODE_header     (x_nscrp, x_nmain, &x_main, x_ncode, &x_code, x_nwave, &x_wave, &x_cshare),    0);
   yUNIT_minpoint ("... check main pointer"              , x_main        , 0x1);
   yUNIT_minpoint ("... check code pointer"              , x_code        , 0x1);
   yUNIT_minpoint ("... check wave pointer"              , x_wave        , 0x1);
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify the CODE output");
   yUNIT_minval   ("... check count"                    , yURG_peek_count (x_ncode)              , 9);
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   ,   0)      , "/*================================= beg-code =================================*/");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "/* /usr/local/bin/koios                                                       */");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "/*   autogen by koios-polos (axis of heaven) unit testing meta-language       */");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , ""                                                                                );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "/*---(standard support functions)----*/"                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "#include    <yUNIT_unit.h>"                                                      );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "#include    \"master.h\""                                                        );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , ""                                                                                );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "/*================================ beg-script ================================*/");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , ""                                                                                );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify the MAIN output");
   yUNIT_minval   ("... check count"                    , yURG_peek_count (x_nmain)              , 14);
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_nmain   ,   0)      , ""                                                                                );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_nmain   , '÷')      , ""                                                                                );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_nmain   , '÷')      , ""                                                                                );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_nmain   , '÷')      , "int"                                                                             );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_nmain   , '÷')      , "main                    (int a_argc, char *a_argv[])"                            );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_nmain   , '÷')      , "{"                                                                               );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_nmain   , '÷')      , "   /*---(locals)-----------+-----+-----+-*/"                                     );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_nmain   , '÷')      , "   int         rc          =    0;"                                              );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_nmain   , '÷')      , "   /*---(prepare)------------------------*/"                                     );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_nmain   , '÷')      , "   rc = yUNIT_init ();"                                                          );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_nmain   , '÷')      , "   rc = yUNIT_args (a_argc, a_argv);"                                            );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_nmain   , '÷')      , "   if (rc < 0)  return -1;"                                                      );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_nmain   , '÷')      , "   yUNIT_unit (\"apate\", cyUNIT.level, cyUNIT.eterm, cyUNIT.exec);"             );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_nmain   , '÷')      , "   /*---(beg scripts)--------------------*/"                                     );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_nmain   , '÷')      , ""                                                                                );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify calling the footer");
   yUNIT_minval   ("call footer"                        , CODE_footer     ('y', x_nscrp, x_nmain, &x_main, x_ncode, &x_code, x_nwave, &x_wave, '-'),    0);
   yUNIT_minpoint ("... check main pointer"              , x_main        , 0x0);
   yUNIT_minpoint ("... check code pointer"              , x_code        , 0x0);
   yUNIT_minpoint ("... check wave pointer"              , x_wave        , 0x0);

   yUNIT_mincond  ("verify writing a code stats");
   yUNIT_minval   ("write code stats"                   , CODE__code_stats  (x_code) ,    0);
   yUNIT_minval   ("... check count"                    , yURG_peek_count (x_ncode)              , 86);
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   ,   9)      , ""                                                                                );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "/*================================ end-script ================================*/");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , ""                                                                                );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "char"                                                                            );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "yUNIT_stats     (void)"                                                          );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "{"                                                                               );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "   yUNIT_unique (0, 0, 0, 0, 0, 0);"                                             );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "   return 0;"                                                                    );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "}"                                                                               );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , ""                                                                                );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , ""                                                                                );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "char"                                                                            );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "yUNIT_verbs (void)"                                                              );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "{"                                                                               );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "   printf (\"koios, record type summary\\n\");"                                  );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "   printf (\"\\noverall...\\n\");"                                               );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "   printf (\"  PREP       =     0   preparation before testing\\n\");"           );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "   printf (\"  incl       =     0   c header inclusion\\n\");"                   );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "   printf (\"  #>         =     0   script internal comments\\n\");"             );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "   printf (\"\\nscripts...\\n\");"                                               );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "   printf (\"  SCRP       =     0   test script header\\n\");"                   );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "   printf (\"  SHARED     =     0   shared code between scripts\\n\");"          );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "   printf (\"  GLOBAL     =     0   shared code between units\\n\");"            );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "   printf (\"  SECT       =     0   grouping of scripts\\n\");"                  );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "   printf (\"\\nconditions...\\n\");"                                            );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "   printf (\"  COND       =     0   test condition\\n\");"                       );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "   printf (\"  DITTO      =     0   repeated test condition\\n\");"              );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "   printf (\"  REUSE      =     0   inclusion of shared code\\n\");"             );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "   printf (\"  GROUP      =     0   grouping of conditions\\n\");"               );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "   printf (\"\\nvariables...\\n\");"                                             );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "   printf (\"  global     =     0   global/unit variable definition\\n\");"      );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "   printf (\"  local      =     0   local/script variable definition\\n\");"     );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "   printf (\"\\nsteps...\\n\");"                                                 );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "   printf (\"  exec       =     0   function execution\\n\");"                   );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "   printf (\"  get        =     0   unit test accessor retrieval\\n\");"         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "   printf (\"  echo       =     0   test a variable directly\\n\");"             );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "   printf (\"\\nspecialty...\\n\");"                                             );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "   printf (\"  code       =     0   insert c code\\n\");"                        );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "   printf (\"  system     =     0   execute shell code\\n\");"                   );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "   printf (\"  load       =     0   place data into input\\n\");"                );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "   printf (\"  mode       =     0   set pass or forced_fail mode\\n\");"         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "   printf (\"\\nsupport...\\n\");"                                               );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "   printf (\"  file       =     0   create a temporary file\\n\");"              );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "   printf (\"  append     =     0   append data to temporary file\\n\");"        );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "   printf (\"\\noroboros...\\n\");"                                              );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "   printf (\"  WAVE       =     0   testing wave definition\\n\");"              );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "   printf (\"  stage      =     0   testing stage definition\\n\");"             );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "   printf (\"\\nend-of-entries...\\n\");"                                        );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "   printf (\"TOTAL        =     0   count of all verb use\\n\");"                );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "   printf (\"concerns     =     0   records with troubles\\n\");"                );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "   return 0;"                                                                    );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "}"                                                                               );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , ""                                                                                );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , ""                                                                                );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , ""                                                                                );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , ""                                                                                );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "int"                                                                             );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "main                    (int a_argc, char *a_argv[])"                            );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "{"                                                                               );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "   /*---(locals)-----------+-----+-----+-*/"                                     );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "   int         rc          =    0;"                                              );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "   /*---(prepare)------------------------*/"                                     );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "   rc = yUNIT_init ();"                                                          );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "   rc = yUNIT_args (a_argc, a_argv);"                                            );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "   if (rc < 0)  return -1;"                                                      );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "   yUNIT_unit (\"apate\", cyUNIT.level, cyUNIT.eterm, cyUNIT.exec);"             );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "   /*---(beg scripts)--------------------*/"                                     );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "   /*---(end scripts)--------------------*/"                                     );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "   rc = yUNIT_tinu (cyUNIT.exec);"                                               );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "   /*---(complete)-----------------------*/"                                     );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "   return rc;"                                                                   );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "}"                                                                               );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , ""                                                                                );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , ""                                                                                );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , ""                                                                                );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "/* end-of-file.  done, finito, completare, whimper [œ¥∑∑∑                     */");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , "/*================================= end-code =================================*/");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_ncode   , '÷')      , ""                                                                                );
   yUNIT_mindnoc  ();

   PROG__unit_end    ();
   rm_working_files ();
   PROG__unit_end    ();
   yUNIT_minprcs  ();
   return 0;
}


char
koios__unit_code_driver  (char a_list)
{
   char         x_name     [LEN_HUND]  = "apate.unit";
   char         t          [LEN_HUND]  = "";
   FILE        *x_file     = NULL;
   char         x_cshare   =  '-';

   yUNIT_minscrp  ("CODE_driver");
   if (a_list == 'y')  return 0;
   yURG_err_none  ();
   rm_working_files ();
   PROG__unit_quiet  ();

   yUNIT_mincond  ("verify creating and writing the opening");
   yUNIT_minval   ("write conv line"                    , CONV_header     (x_name, &x_file, &x_cshare),    0);
   yUNIT_minval   ("write conv line"                    , CONV_prep       (x_file    , "PREP"    , "prototype headers"   , ""               , ""               , ""          , ""               , ""          , '-', '-', ""  , &x_cshare  ),    0);
   yUNIT_minval   ("write conv line"                    , CONV_incl       (x_file    , "incl"    , "public header"       , "apate.h"        , ""               , ""          , ""               , ""          , '-', '-', ""  , &x_cshare  ),    0);
   yUNIT_minval   ("... check count"                    , yURG_peek_count (x_name)               , 9);
   yUNIT_minstr   ("... header"                         , yURG_peek       (x_name    ,   0)      , "#!/usr/local/bin/koios"                   );
   yUNIT_minstr   ("... header"                         , yURG_peek       (x_name    ,   1)      , "#   koios-polos (axis of heaven) unit testing meta-language" );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   2)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   3)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   4)      , ""                                         );
   yUNIT_minstr   ("... ruler"                          , yURG_peek       (x_name    ,   5)      , "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-123456789- ");
   yUNIT_minstr   ("... title"                          , yURG_peek       (x_name    ,   6)      , "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  ========(var)======= ");
   yUNIT_minstr   ("... check resuls"                   , yURG_peek       (x_name    ,   7)      , "PREP          prototype headers                                                  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check resuls"                   , yURG_peek       (x_name    ,   8)      , "   incl       public header                        apate.h                     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   9)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing a SCRP");
   yUNIT_minval   ("write conv line"                    , CONV_driver     (CONV_scrp             , x_file    , "SCRP"    , "sample testing"      , "CONV_scrp"      , ""               , "5s"        , ""               , "test"      , '-', '-', "¬Ú", &x_cshare  ),    0);
   yUNIT_minval   ("... check count"                    , yURG_peek_count (x_name)               , 15);
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,   9)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  10)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  11)      , ""                                         );
   yUNIT_minstr   ("... ruler"                          , yURG_peek       (x_name    ,  12)      , "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-123456789- ");
   yUNIT_minstr   ("... title"                          , yURG_peek       (x_name    ,  13)      , "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  ========(var)======= ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  14)      , "SCRP    [¬Ú]  sample testing                                                     5s   test            CONV_scrp                                                                    ((01.---))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  15)      , ""                                         );

   yUNIT_mincond  ("verify writing a COND");               
   yUNIT_minval   ("write conv line"                    , CONV_driver     (CONV_cond             , x_file    , "COND"    , "repeating condition" , ""               , ""               , ""          , ""               , ""          , '-', '2', ""  , &x_cshare  ),    0);
   yUNIT_minval   ("write conv line"                    , CONV_driver     (CONV_exec             , x_file    , "exec"    , "call the function"   , "DITTO_parse"    , "x, y, 21"       , "s_equal"   , "pretty expected", "x_str"     , '-', '-', ""  , &x_cshare  ),    0);
   yUNIT_minval   ("write conv line"                    , CONV_driver     (CONV_code             , x_file    , "code"    , "update prefix"       , ""               , ""               , ""          , "x_one = 13;"    , ""          , '-', '-', ""  , &x_cshare  ),    0);
   yUNIT_minval   ("... check count"                    , yURG_peek_count (x_name)               , 19);
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  15)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  16)      , "   COND  (2)  repeating condition                                                - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((01.001))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  17)      , "     exec     call the function                    DITTO_parse                 x, y, 21                                                                                              s_equal     pretty expected                                                                                       x_str                ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  18)      , "     code     update prefix                        - - - - - - - - - - - - -   x_one = 13;                                                                                                                                                                                                                ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  19)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing another COND");               
   yUNIT_minval   ("write conv line"                    , CONV_driver     (CONV_cond             , x_file    , "COND"    , "another condition"   , ""               , ""               , ""          , ""               , ""          , '-', '-', ""  , &x_cshare  ),    0);
   yUNIT_minval   ("write conv line"                    , CONV_driver     (CONV_echo             , x_file    , "echo"    , "... check value"     , ""               , "x_act"          , "s_equal"   , "[[ x_exp ]]"    , ""          , '-', '-', ""  , &x_cshare  ),    0);
   yUNIT_minval   ("... check count"                    , yURG_peek_count (x_name)               , 22);
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  19)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  20)      , "   COND       another condition                                                  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((01.002))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  21)      , "     echo     ... check value                      - - - - - - - - - - - - -   x_act                                                                                                 s_equal     [[ x_exp ]]                                                                                          ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  22)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing another SCRP");
   yUNIT_minval   ("write conv line"                    , CONV_driver     (CONV_scrp             , x_file    , "SCRP"    , "check numbering"     , "CONV_cond"      , ""               , "10m"       , ""               , "another"   , '-', '-', "√˘", &x_cshare  ),    0);
   yUNIT_minval   ("... check count"                    , yURG_peek_count (x_name)               , 28);
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  22)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  23)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  24)      , ""                                         );
   yUNIT_minstr   ("... ruler"                          , yURG_peek       (x_name    ,  25)      , "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-123456789- ");
   yUNIT_minstr   ("... title"                          , yURG_peek       (x_name    ,  26)      , "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  ========(var)======= ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  27)      , "SCRP    [√˘]  check numbering                                                    10m  another         CONV_cond                                                                    ((02.---))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  28)      , ""                                         );

   yUNIT_mincond  ("verify writing COND in second SCRP");               
   yUNIT_minval   ("write conv line"                    , CONV_driver     (CONV_cond             , x_file    , "COND"    , "checking"            , ""               , ""               , ""          , ""               , ""          , '-', '-', ""  , &x_cshare  ),    0);
   yUNIT_minval   ("write conv line"                    , CONV_driver     (CONV_code             , x_file    , "local"   , "local variable"      , ""               , ""               , ""          , "char rc = 0;"   , ""          , '-', '-', ""  , &x_cshare  ),    0);
   yUNIT_minval   ("... check count"                    , yURG_peek_count (x_name)               , 31);
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  28)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  29)      , "   COND       checking                                                           - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((02.001))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  30)      , "     local    local variable                       - - - - - - - - - - - - -   char rc = 0;                                                                                                                                                                                                               ");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  31)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify writing FOOTER and closing file");
   yUNIT_minval   ("write conv line"                    , CONV_footer     ('y', &x_file, x_name, "")       ,    0);
   yUNIT_minval   ("... check count"                    , yURG_peek_count (x_name)               , 35);
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  31)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  32)      , ""                                         );
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  33)      , ""                                         );
   yUNIT_minstr   ("... footer"                         , yURG_peek       (x_name    ,  34)      , "# end-of-file.  done, finito, completare, whimper [œ¥∑∑∑");
   yUNIT_minstr   ("... check result"                   , yURG_peek       (x_name    ,  35)      , ""                                         );
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("close the conversion file");
   sprintf (t, "rm -f %s   2> /dev/null", x_name);  system (t);
   yUNIT_mindnoc  ();

   PROG__unit_end    ();
   rm_working_files ();
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
   rm_working_files ();
   PROG__unit_quiet  ();

   yURG_err_clear ();
   yUNIT_mincond ("verify without stage");
   yUNIT_minval  ("parse"                              , WAVE_parse      ("apate.unit", 25, "SCRP", "SCRP"        , x_stage), 0);
   yUNIT_minstr  ("... check stage"                    , x_stage       , "");
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("verify parse good stage 0 (first)");
   yUNIT_minval  ("parse [¿Ë]"                         , WAVE_parse      ("apate.unit", 25, "SCRP", "SCRP    [¿Ë]", x_stage), 0);
   yUNIT_minstr  ("... check stage"                    , x_stage       , "¿Ë");
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("attempt with an illegal wave");
   yUNIT_minval  ("parse [aË]"                         , WAVE_parse      ("apate.unit", 26, "SCRP", "SCRP    [aË]", x_stage), -999);
   yUNIT_minstr  ("... check stage"                    , x_stage       , "");
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "apate.unit:26:9: error: SCRP identifier, wave (a) not a subscript (¿¡¬√ƒ≈), e.g., [¡Ï]");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("attempt with an illegal stage");
   yUNIT_minval  ("parse [¿A]"                         , WAVE_parse      ("apate.unit", 27, "SCRP", "SCRP    [¿A]", x_stage), -999);
   yUNIT_minstr  ("... check stage"                    , x_stage       , "");
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "apate.unit:27:10: error: SCRP identifier, stage (A) not a greek letter (ËÈÍÎÏÌÓÔÒÚÛÙıˆ˜¯˘˙˚¸˝˛ˇ), e.g., [¡Ï]");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("verify parse good stage 1");
   yUNIT_minval  ("parse [¡Ì]"                         , WAVE_parse      ("apate.unit", 28, "SCRP", "SCRP    [¡Ì]", x_stage), 0);
   yUNIT_minstr  ("... check stage"                    , x_stage       , "¡Ì");
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("attempt with mismatched stage");
   yUNIT_minval  ("parse [¬Ì]"                         , WAVE_parse      ("apate.unit", 29, "SCRP", "SCRP    [¬Ì]", x_stage), -999);
   yUNIT_minstr  ("... check stage"                    , x_stage       , "");
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "apate.unit:29:9: error: SCRP identifier, wave (¬) and stage (Ì) mismatched, e.g., [¡Ï]");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("verify parse good stage 2");
   yUNIT_minval  ("parse [¬Ú]"                         , WAVE_parse      ("apate.unit", 30, "SCRP", "SCRP    [¬Ú]", x_stage), 0);
   yUNIT_minstr  ("... check stage"                    , x_stage       , "¬Ú");
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("attempt with wrong start");        
   yUNIT_minval  ("parse (¬Ú]"                         , WAVE_parse      ("apate.unit", 22, "SCRP", "SCRP    (¬Ú]", x_stage), -999);
   yUNIT_minstr  ("... check stage"                    , x_stage       , "");
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "apate.unit:22:0: error: SCRP identifier, illegal char '(' after verb, maybe stage, e.g., [¡Ï]");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("attempt with wrong parens");        
   yUNIT_minval  ("parse [¬Ú)"                         , WAVE_parse      ("apate.unit", 31, "SCRP", "SCRP    [¬Ú)", x_stage), -999);
   yUNIT_minstr  ("... check stage"                    , x_stage       , "");
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "apate.unit:31:11: error: SCRP identifier, stage uses wrong end bracket ')' vs ']', e.g., [¡Ï]");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("verify parse good stage 3");
   yUNIT_minval  ("parse [√˜]"                         , WAVE_parse      ("apate.unit", 32, "SCRP", "SCRP    [√˜]", x_stage), 0);
   yUNIT_minstr  ("... check stage"                    , x_stage       , "√˜");
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("attempt with no close paren");      
   yUNIT_minval  ("parse [√˜"                          , WAVE_parse      ("apate.unit", 33, "SCRP", "SCRP    [√˜", x_stage ), -999);
   yUNIT_minstr  ("... check stage"                    , x_stage       , "");
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "apate.unit:33:8: error: SCRP identifier, stage ∂[√˜∂ must be exactly 4 characters, e.g., [¡Ï]");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("verify parse good stage 4");
   yUNIT_minval  ("parse [ƒ˘]"                         , WAVE_parse      ("apate.unit", 34, "SCRP", "SCRP    [ƒ˘]", x_stage), 0);
   yUNIT_minstr  ("... check stage"                    , x_stage       , "ƒ˘");
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("attempt on an empty");                
   yUNIT_minval  ("parse "                             , WAVE_parse      ("apate.unit", 35, "SCRP", ""            , x_stage), -999);
   yUNIT_minstr  ("... check stage"                    , x_stage       , "");
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("verify parse good stage 5 (last)");
   yUNIT_minval  ("parse [≈ˇ]"                         , WAVE_parse      ("apate.unit", 36, "SCRP", "SCRP    [≈ˇ]", x_stage), 0);
   yUNIT_minstr  ("... check stage"                    , x_stage       , "≈ˇ");
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc ();

   yURG_err_clear ();
   yUNIT_mincond ("attempt on a null");                
   yUNIT_minval  ("parse "                             , WAVE_parse      ("apate.unit", 37, "SCRP", NULL          , x_stage), -999);
   yUNIT_minstr  ("... check stage"                    , x_stage       , "");
   yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");
   yUNIT_mindnoc ();

   PROG__unit_end    ();
   rm_working_files ();
   yUNIT_minprcs ();
   return 0;
}

char
koios__unit_scrp_variety (void)
{
   yUNIT_minscrp ("koios_scrp read/parse a variety of records");
   yURG_err_none ();  /* not to stderr/terminal */
   rm_working_files ();
   PROG__unit_quiet  ();

   /*> yUNIT_mincond ("prepare clean start");                                                                                                                                                              <* 
    *> system ("rm -f apate.unit 2> /dev/null");                                                                                                                                                           <* 
    *> system ("echo \"\"                                                                                                                                                                > apate.unit");   <* 
    *> system ("echo \"## this is a comment\"                                                                                                                                           >> apate.unit");   <* 
    *> system ("echo \"exec          read a line      SCRP_read       i_lesser    0       my_var   \"                                                                     >> apate.unit");          <* 
    *> system ("echo \"#> this is a saved comment\"                                                                                                                                     >> apate.unit");   <* 
    *> system ("echo \"     get      ... check on script  SCRP__unit   file , -1  s_equal  SCRP file      : apate.unit \"                                                   >> apate.unit");         <* 
    *> system ("echo \"   code       add lines                            - - - - - - - - - - - - -   system ();        \"                                                      >> apate.unit");       <* 
    *> system ("echo \"\"                                                                                                                                                               >> apate.unit");   <* 
    *> system ("echo \"  COND        parse a code record   - - - - - - - - - - - - -   ((01.001))  - - - - - - - - - \"                                                       >> apate.unit");        <* 
    *> system ("echo \"PREP          include the prototype headers                            - - - - - - - - - -   - - - - -   - - - - - - - - - -  >>\"                     >> apate.unit");        <* 
    *> system ("echo \"   incl       include public header                apate.h           - - - - - - - - - -   - - - - -   - - - - - - - - - -  \"                       >> apate.unit");         <* 
    *> system ("echo \"#23456789-12  123456789-123456789-123456789-12345  123456789-123456  123456789-123456789-  123456789-  123456789-123456789-  -  123456789- \"    >> apate.unit");           <* 
    *> system ("echo \"#==(verb)===  ===========(description)===========  =====(function)=  ====(arguments)=====  ==(test)==  ====(results)=======  t  =(var)==== \"    >> apate.unit");           <* 
    *> system ("echo \"SCRP    [¡Ï]  (SCRP  ) verify openning and closin                                           ((01.---))  - - - - - - - - - -  \"                        >> apate.unit");        <* 
    *> system ("echo \"\"                                                                                                                                                               >> apate.unit");   <* 
    *> system ("echo \"  load        add a line to stdin    stdin  * * * * *                      : basic line                  : - - - - -  :  /bin/true > /dev/null\"         >> apate.unit");       <* 
    *> system ("echo \"  toad        add a line to stdin 2  stdin  * * * * *                      : basic line                  : - - - - -  :  /bin/true > /dev/null\"         >> apate.unit");       <* 
    *> system ("echo \"              (SCRP  ) verify openning and closin                                           ((01.---))  - - - - - - - - - -  \"                        >> apate.unit");        <* 
    *> system ("echo \"\"                                                                                                                                                               >> apate.unit");   <* 
    *> system ("echo \"GROUP         complete               - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - -  \"                 >> apate.unit");        <* 
    *> system ("echo \"SECT          internal testing       - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - -  \"                 >> apate.unit");        <* 
    *> system ("echo \"    echo      ...check y location    - - - - - - - - - - - - -   y        r_norm93    -125.381                                     \"                >> apate.unit");         <* 
    *> system ("echo \"    system    remove a file                        - - - - - - - - - - - - -   rm -fv test.txt   \"                                                      >> apate.unit");       <* 
    *> system ("echo \"\"                                                                                                                                                               >> apate.unit");   <* 
    *> system ("echo \"#==(verb)===  ===========(description)===========  =====(function)=  ====(arguments)=====  ==(test)==  ====(results)=======  t  =(var)==== \"    >> apate.unit");           <* 
    *> system ("echo \"SHARED   -a-  setup cron files and lines           - - - - - - - -   ((CC.---))  - - - - - - - - - - - - - - - - - - - - - - - - -  \"                 >> apate.unit");        <* 
    *> system ("echo \"\"                                                                                                                                                               >> apate.unit");   <* 
    *> system ("echo \" REUSE -a-    - - - - - - - - - - - -   - - - - - - - - - - - - - - -   ((03.---))  - - - - - - - - - - - - - - - - - - - -  \"                        >> apate.unit");        <* 
    *> my.run_type = G_RUN_CREATE;                                                                                                                                                                         <* 
    *> strcpy (my.n_scrp, "apate.unit");                                                                                                                                                                   <* 
    *> strcpy (my.n_wave, "apate.wave");                                                                                                                                                                   <* 
    *> yUNIT_minstr ("... check script name"              , my.n_scrp     , "apate.unit");                                                                                                                 <* 
    *> yUNIT_minval ("open the script file"               , SCRP_open   (my.n_scrp, &(my.f_scrp), &(my.n_line)), 0);                                                                                       <* 
    *> yUNIT_mindnoc ();                                                                                                                                                                                   <*/

   /*> yUNIT_mincond ("read very detailed exec line");                                                                                                                                                                                                                   <* 
    *> yUNIT_minval ("read a line"                        , SCRP_read   (my.f_scrp, &(my.n_line), my.dittoing, my.ditto, &(my.dline), &(my.n_recd), &(my.len), my.recd), 1);                                                                                             <* 
    *> /+> yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);   <+/   <* 
    *> strlencode (my.recd, ySTR_NONE, LEN_RECD);                                                                                                                                                                                                                        <* 
    *> yUNIT_minstr ("... check the record"               , my.recd       , "exec         ß read a line     ß SCRP_read   ß   ß i_lesser   ß 0      ß my_var   ß");                                                                                                      <* 
    *> yUNIT_minstr ("... check verb"                     , my.verb       , "exec");                                                                                                                                                                                     <* 
    *> yUNIT_minstr ("... check stage"                    , my.stage      , "");                                                                                                                                                                                         <* 
    *> yUNIT_minchr ("... check share"                    , my.share      , '-');                                                                                                                                                                                        <* 
    *> yUNIT_minchr ("... check mark"                     , my.mark       , '-');                                                                                                                                                                                        <* 
    *> yUNIT_minstr ("... check version"                  , my.vers       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check description"              , my.desc       , "read a line");                                                                                                                                                                              <* 
    *> yUNIT_minstr ("... check method"                   , my.meth       , "SCRP_read");                                                                                                                                                                                <* 
    *> yUNIT_minstr ("... check arguments"                , my.args       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check test"                     , my.test       , "i_lesser");                                                                                                                                                                                 <* 
    *> yUNIT_minstr ("... check expect"                   , my.expe       , "0");                                                                                                                                                                                        <* 
    *> yUNIT_minstr ("... check return"                   , my.retn       , "my_var");                                                                                                                                                                                   <* 
    *> yUNIT_minstr ("... check code"                     , my.code       , "");                                                                                                                                                                                         <* 
    *> yUNIT_mindnoc ();                                                                                                                                                                                                                                                 <*/

   /*> yUNIT_mincond ("read saved comment line");                                                                                                                                                                                                                        <* 
    *> yUNIT_minval ("read a line"                        , SCRP_read   (my.f_scrp, &(my.n_line), my.dittoing, my.ditto, &(my.dline), &(my.n_recd), &(my.len), my.recd), 1);                                                                                             <* 
    *> /+> yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);   <+/   <* 
    *> strlencode (my.recd, ySTR_NONE, LEN_RECD);                                                                                                                                                                                                                        <* 
    *> yUNIT_minstr ("... check the record"               , my.recd       , "#> this is a saved comment");                                                                                                                                                               <* 
    *> yUNIT_minstr ("... check verb"                     , my.verb       , "#>");                                                                                                                                                                                       <* 
    *> yUNIT_minstr ("... check stage"                    , my.stage      , "");                                                                                                                                                                                         <* 
    *> yUNIT_minchr ("... check share"                    , my.share      , '-');                                                                                                                                                                                        <* 
    *> yUNIT_minchr ("... check mark"                     , my.mark       , '-');                                                                                                                                                                                        <* 
    *> yUNIT_minstr ("... check version"                  , my.vers       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check description"              , my.desc       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check method"                   , my.meth       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check arguments"                , my.args       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check test"                     , my.test       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check expect"                   , my.expe       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check return"                   , my.retn       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check code"                     , my.code       , "");                                                                                                                                                                                         <* 
    *> yUNIT_mindnoc ();                                                                                                                                                                                                                                                 <*/

   /*> yUNIT_mincond ("read get/accessor line");                                                                                                                                                                                                                         <* 
    *> yUNIT_minval ("read a line"                        , SCRP_read   (my.f_scrp, &(my.n_line), my.dittoing, my.ditto, &(my.dline), &(my.n_recd), &(my.len), my.recd), 1);                                                                                             <* 
    *> /+> yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);   <+/   <* 
    *> strlencode (my.recd, ySTR_NONE, LEN_RECD);                                                                                                                                                                                                                        <* 
    *> yUNIT_minstr ("... check the record"               , my.recd       , "     get     ß ... check on script ß SCRP__unit  ß file , -1 ß s_equal ß SCRP file      : apate.unit ß");                                                                                   <* 
    *> yUNIT_minstr ("... check verb"                     , my.verb       , "get");                                                                                                                                                                                      <* 
    *> yUNIT_minstr ("... check stage"                    , my.stage      , "");                                                                                                                                                                                         <* 
    *> yUNIT_minchr ("... check share"                    , my.share      , '-');                                                                                                                                                                                        <* 
    *> yUNIT_minchr ("... check mark"                     , my.mark       , '-');                                                                                                                                                                                        <* 
    *> yUNIT_minstr ("... check version"                  , my.vers       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check description"              , my.desc       , "... check on script");                                                                                                                                                                      <* 
    *> yUNIT_minstr ("... check method"                   , my.meth       , "SCRP__unit");                                                                                                                                                                               <* 
    *> yUNIT_minstr ("... check arguments"                , my.args       , "file , -1");                                                                                                                                                                                <* 
    *> yUNIT_minstr ("... check test"                     , my.test       , "s_equal");                                                                                                                                                                                  <* 
    *> yUNIT_minstr ("... check expect"                   , my.expe       , "SCRP file      : apate.unit");                                                                                                                                                              <* 
    *> yUNIT_minstr ("... check return"                   , my.retn       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check code"                     , my.code       , "file , -1");                                                                                                                                                                                <* 
    *> yUNIT_mindnoc ();                                                                                                                                                                                                                                                 <*/

   /*> yUNIT_mincond ("read code line");                                                                                                                                                                                                                                 <* 
    *> yUNIT_minval ("read a line"                        , SCRP_read   (my.f_scrp, &(my.n_line), my.dittoing, my.ditto, &(my.dline), &(my.n_recd), &(my.len), my.recd), 1);                                                                                             <* 
    *> /+> yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);   <+/   <* 
    *> strlencode (my.recd, ySTR_NONE, LEN_RECD);                                                                                                                                                                                                                        <* 
    *> yUNIT_minstr ("... check the record"               , my.recd       , "   code      ß add lines                           ß - - - - - - - - - - - - -  ß system ();        ß");                                                                                    <* 
    *> yUNIT_minstr ("... check verb"                     , my.verb       , "code");                                                                                                                                                                                     <* 
    *> yUNIT_minstr ("... check stage"                    , my.stage      , "");                                                                                                                                                                                         <* 
    *> yUNIT_minchr ("... check share"                    , my.share      , '-');                                                                                                                                                                                        <* 
    *> yUNIT_minchr ("... check mark"                     , my.mark       , '-');                                                                                                                                                                                        <* 
    *> yUNIT_minstr ("... check version"                  , my.vers       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check description"              , my.desc       , "add lines");                                                                                                                                                                                <* 
    *> yUNIT_minstr ("... check method"                   , my.meth       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check arguments"                , my.args       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check test"                     , my.test       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check expect"                   , my.expe       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check return"                   , my.retn       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check code"                     , my.code       , "system ();");                                                                                                                                                                               <* 
    *> yUNIT_mindnoc ();                                                                                                                                                                                                                                                 <*/

   /*> yUNIT_mincond ("read condition line");                                                                                                                                                                                                                            <* 
    *> yUNIT_minval ("read a line"                        , SCRP_read   (my.f_scrp, &(my.n_line), my.dittoing, my.ditto, &(my.dline), &(my.n_recd), &(my.len), my.recd), 1);                                                                                             <* 
    *> /+> yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);   <+/   <* 
    *> strlencode (my.recd, ySTR_NONE, LEN_RECD);                                                                                                                                                                                                                        <* 
    *> yUNIT_minstr ("... check the record"               , my.recd       , "  COND       ß parse a code record  ß - - - - - - - - - - - - -  ß ((01.001)) ß - - - - - - - - - ß");                                                                                      <* 
    *> yUNIT_minstr ("... check verb"                     , my.verb       , "COND");                                                                                                                                                                                     <* 
    *> yUNIT_minstr ("... check stage"                    , my.stage      , "");                                                                                                                                                                                         <* 
    *> yUNIT_minchr ("... check share"                    , my.share      , '-');                                                                                                                                                                                        <* 
    *> yUNIT_minchr ("... check mark"                     , my.mark       , '-');                                                                                                                                                                                        <* 
    *> yUNIT_minstr ("... check version"                  , my.vers       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check description"              , my.desc       , "parse a code record");                                                                                                                                                                      <* 
    *> yUNIT_minstr ("... check method"                   , my.meth       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check arguments"                , my.args       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check test"                     , my.test       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check expect"                   , my.expe       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check return"                   , my.retn       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check code"                     , my.code       , "");                                                                                                                                                                                         <* 
    *> yUNIT_mindnoc ();                                                                                                                                                                                                                                                 <*/

   /*> yUNIT_mincond ("read prep line");                                                                                                                                                                                                                                 <* 
    *> yUNIT_minval ("read a line"                        , SCRP_read   (my.f_scrp, &(my.n_line), my.dittoing, my.ditto, &(my.dline), &(my.n_recd), &(my.len), my.recd), 1);                                                                                             <* 
    *> /+> yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);   <+/   <* 
    *> strlencode (my.recd, ySTR_NONE, LEN_RECD);                                                                                                                                                                                                                        <* 
    *> yUNIT_minstr ("... check the record"               , my.recd       , "PREP         ß include the prototype headers                           ß - - - - - - - - - -  ß - - - - -  ß - - - - - - - - - -  ß>>");                                                    <* 
    *> yUNIT_minstr ("... check verb"                     , my.verb       , "PREP");                                                                                                                                                                                     <* 
    *> yUNIT_minstr ("... check stage"                    , my.stage      , "");                                                                                                                                                                                         <* 
    *> yUNIT_minchr ("... check share"                    , my.share      , '-');                                                                                                                                                                                        <* 
    *> yUNIT_minchr ("... check mark"                     , my.mark       , '-');                                                                                                                                                                                        <* 
    *> yUNIT_minstr ("... check version"                  , my.vers       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check description"              , my.desc       , "include the prototype headers");                                                                                                                                                            <* 
    *> yUNIT_minstr ("... check method"                   , my.meth       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check arguments"                , my.args       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check test"                     , my.test       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check expect"                   , my.expe       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check return"                   , my.retn       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check code"                     , my.code       , "");                                                                                                                                                                                         <* 
    *> yUNIT_mindnoc ();                                                                                                                                                                                                                                                 <*/

   /*> yUNIT_mincond ("read include line");                                                                                                                                                                                                                              <* 
    *> yUNIT_minval ("read a line"                        , SCRP_read   (my.f_scrp, &(my.n_line), my.dittoing, my.ditto, &(my.dline), &(my.n_recd), &(my.len), my.recd), 1);                                                                                             <* 
    *> /+> yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);   <+/   <* 
    *> strlencode (my.recd, ySTR_NONE, LEN_RECD);                                                                                                                                                                                                                        <* 
    *> yUNIT_minstr ("... check the record"               , my.recd       , "   incl      ß include public header               ß apate.h          ß - - - - - - - - - -  ß - - - - -  ß - - - - - - - - - -  ß");                                                       <* 
    *> yUNIT_minstr ("... check verb"                     , my.verb       , "incl");                                                                                                                                                                                     <* 
    *> yUNIT_minstr ("... check stage"                    , my.stage      , "");                                                                                                                                                                                         <* 
    *> yUNIT_minchr ("... check share"                    , my.share      , '-');                                                                                                                                                                                        <* 
    *> yUNIT_minchr ("... check mark"                     , my.mark       , '-');                                                                                                                                                                                        <* 
    *> yUNIT_minstr ("... check version"                  , my.vers       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check description"              , my.desc       , "include public header");                                                                                                                                                                    <* 
    *> yUNIT_minstr ("... check method"                   , my.meth       , "apate.h");                                                                                                                                                                                  <* 
    *> yUNIT_minstr ("... check arguments"                , my.args       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check test"                     , my.test       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check expect"                   , my.expe       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check return"                   , my.retn       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check code"                     , my.code       , "");                                                                                                                                                                                         <* 
    *> yUNIT_mindnoc ();                                                                                                                                                                                                                                                 <*/

   /*> yUNIT_mincond ("read script header line");                                                                                                                                                                                                                        <* 
    *> yUNIT_minval ("read a line"                        , SCRP_read   (my.f_scrp, &(my.n_line), my.dittoing, my.ditto, &(my.dline), &(my.n_recd), &(my.len), my.recd), 1);                                                                                             <* 
    *> /+> yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);   <+/   <* 
    *> strlencode (my.recd, ySTR_NONE, LEN_RECD);                                                                                                                                                                                                                        <* 
    *> yUNIT_minstr ("... check the record"               , my.recd       , "SCRP    [¡Ï] ß (SCRP  ) verify openning and closin ß                                         ß ((01.---)) ß - - - - - - - - - -  ß");                                                       <* 
    *> yUNIT_minstr ("... check verb"                     , my.verb       , "SCRP");                                                                                                                                                                                     <* 
    *> yUNIT_minstr ("... check stage"                    , my.stage      , "¡Ï");                                                                                                                                                                                       <* 
    *> yUNIT_minchr ("... check share"                    , my.share      , '-');                                                                                                                                                                                        <* 
    *> yUNIT_minchr ("... check mark"                     , my.mark       , '-');                                                                                                                                                                                        <* 
    *> yUNIT_minstr ("... check version"                  , my.vers       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check description"              , my.desc       , "(SCRP  ) verify openning and closin");                                                                                                                                                      <* 
    *> yUNIT_minstr ("... check method"                   , my.meth       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check arguments"                , my.args       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check test"                     , my.test       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check expect"                   , my.expe       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check return"                   , my.retn       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check code"                     , my.code       , "");                                                                                                                                                                                         <* 
    *> yUNIT_mindnoc ();                                                                                                                                                                                                                                                 <*/

   /*> yUNIT_mincond ("read stdin load line");                                                                                                                                                                                                                           <* 
    *> yUNIT_minval ("read a line"                        , SCRP_read   (my.f_scrp, &(my.n_line), my.dittoing, my.ditto, &(my.dline), &(my.n_recd), &(my.len), my.recd), 1);                                                                                             <* 
    *> /+> yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);   <+/   <* 
    *> strlencode (my.recd, ySTR_NONE, LEN_RECD);                                                                                                                                                                                                                        <* 
    *> yUNIT_minstr ("... check the record"               , my.recd       , "  load       ß add a line to stdin   ß stdin ß * * * * *                      : basic line                  : - - - - -  :  /bin/true > /dev/nullß");                                       <* 
    *> yUNIT_minstr ("... check verb"                     , my.verb       , "load");                                                                                                                                                                                     <* 
    *> yUNIT_minstr ("... check stage"                    , my.stage      , "");                                                                                                                                                                                         <* 
    *> yUNIT_minchr ("... check share"                    , my.share      , '-');                                                                                                                                                                                        <* 
    *> yUNIT_minchr ("... check mark"                     , my.mark       , '-');                                                                                                                                                                                        <* 
    *> yUNIT_minstr ("... check version"                  , my.vers       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check description"              , my.desc       , "add a line to stdin");                                                                                                                                                                      <* 
    *> yUNIT_minstr ("... check method"                   , my.meth       , "stdin");                                                                                                                                                                                    <* 
    *> yUNIT_minstr ("... check arguments"                , my.args       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check test"                     , my.test       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check expect"                   , my.expe       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check return"                   , my.retn       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check code"                     , my.code       , "* * * * *                      : basic line                  : - - - - -  :  /bin/true > /dev/null");                                                                                       <* 
    *> yUNIT_mindnoc ();                                                                                                                                                                                                                                                 <*/

   /*> yUNIT_mincond ("read stdin load line");                                                                                                                                                                                                                              <* 
    *> yUNIT_minval ("read a line"                        , SCRP_read   (my.f_scrp, &(my.n_line), my.dittoing, my.ditto, &(my.dline), &(my.n_recd), &(my.len), my.recd), 1);                                                                                                <* 
    *> /+> yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), -999);   <+/   <* 
    *> strlencode (my.recd, ySTR_NONE, LEN_RECD);                                                                                                                                                                                                                           <* 
    *> yUNIT_minstr ("... check the record"               , my.recd       , "  toad       ß add a line to stdin 2 ß stdin ß * * * * *                      : basic line                  : - - - - -  :  /bin/true > /dev/nullß");                                          <* 
    *> yUNIT_minstr ("... check verb"                     , my.verb       , "");                                                                                                                                                                                            <* 
    *> yUNIT_minstr ("... check stage"                    , my.stage      , "");                                                                                                                                                                                            <* 
    *> yUNIT_minchr ("... check share"                    , my.share      , '-');                                                                                                                                                                                           <* 
    *> yUNIT_minchr ("... check mark"                     , my.mark       , '-');                                                                                                                                                                                           <* 
    *> yUNIT_minstr ("... check version"                  , my.vers       , "");                                                                                                                                                                                            <* 
    *> yUNIT_minstr ("... check description"              , my.desc       , "");                                                                                                                                                                                            <* 
    *> yUNIT_minstr ("... check method"                   , my.meth       , "");                                                                                                                                                                                            <* 
    *> yUNIT_minstr ("... check arguments"                , my.args       , "");                                                                                                                                                                                            <* 
    *> yUNIT_minstr ("... check test"                     , my.test       , "");                                                                                                                                                                                            <* 
    *> yUNIT_minstr ("... check expect"                   , my.expe       , "");                                                                                                                                                                                            <* 
    *> yUNIT_minstr ("... check return"                   , my.retn       , "");                                                                                                                                                                                            <* 
    *> yUNIT_minstr ("... check code"                     , my.code       , "");                                                                                                                                                                                            <* 
    *> yUNIT_mindnoc ();                                                                                                                                                                                                                                                    <*/

   /*> yUNIT_mincond ("read verbless line");                                                                                                                                                                                                                                <* 
    *> yUNIT_minval ("read a line"                        , SCRP_read   (my.f_scrp, &(my.n_line), my.dittoing, my.ditto, &(my.dline), &(my.n_recd), &(my.len), my.recd), 1);                                                                                                <* 
    *> /+> yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), -999);   <+/   <* 
    *> strlencode (my.recd, ySTR_NONE, LEN_RECD);                                                                                                                                                                                                                           <* 
    *> yUNIT_minstr ("... check the record"               , my.recd       , "             ß (SCRP  ) verify openning and closin ß                                         ß ((01.---)) ß - - - - - - - - - -  ß");                                                          <* 
    *> yUNIT_minstr ("... check verb"                     , my.verb       , "");                                                                                                                                                                                            <* 
    *> yUNIT_minstr ("... check stage"                    , my.stage      , "");                                                                                                                                                                                            <* 
    *> yUNIT_minchr ("... check share"                    , my.share      , '-');                                                                                                                                                                                           <* 
    *> yUNIT_minchr ("... check mark"                     , my.mark       , '-');                                                                                                                                                                                           <* 
    *> yUNIT_minstr ("... check version"                  , my.vers       , "");                                                                                                                                                                                            <* 
    *> yUNIT_minstr ("... check description"              , my.desc       , "");                                                                                                                                                                                            <* 
    *> yUNIT_minstr ("... check method"                   , my.meth       , "");                                                                                                                                                                                            <* 
    *> yUNIT_minstr ("... check arguments"                , my.args       , "");                                                                                                                                                                                            <* 
    *> yUNIT_minstr ("... check test"                     , my.test       , "");                                                                                                                                                                                            <* 
    *> yUNIT_minstr ("... check expect"                   , my.expe       , "");                                                                                                                                                                                            <* 
    *> yUNIT_minstr ("... check return"                   , my.retn       , "");                                                                                                                                                                                            <* 
    *> yUNIT_minstr ("... check code"                     , my.code       , "");                                                                                                                                                                                            <* 
    *> yUNIT_mindnoc ();                                                                                                                                                                                                                                                    <*/

   /*> yUNIT_mincond ("read group divider line");                                                                                                                                                                                                                        <* 
    *> yUNIT_minval ("read a line"                        , SCRP_read   (my.f_scrp, &(my.n_line), my.dittoing, my.ditto, &(my.dline), &(my.n_recd), &(my.len), my.recd), 1);                                                                                             <* 
    *> /+> yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);   <+/   <* 
    *> strlencode (my.recd, ySTR_NONE, LEN_RECD);                                                                                                                                                                                                                        <* 
    *> yUNIT_minstr ("... check the record"               , my.recd       , "GROUP        ß complete              ß - - - - - - - - - - - - - - -  ß - - - - -  ß - - - - - - - - - - - - - - - - - - - - - - - - -  ß");                                                <* 
    *> yUNIT_minstr ("... check verb"                     , my.verb       , "GROUP");                                                                                                                                                                                    <* 
    *> yUNIT_minstr ("... check stage"                    , my.stage      , "");                                                                                                                                                                                         <* 
    *> yUNIT_minchr ("... check share"                    , my.share      , '-');                                                                                                                                                                                        <* 
    *> yUNIT_minchr ("... check mark"                     , my.mark       , '-');                                                                                                                                                                                        <* 
    *> yUNIT_minstr ("... check version"                  , my.vers       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check description"              , my.desc       , "complete");                                                                                                                                                                                 <* 
    *> yUNIT_minstr ("... check method"                   , my.meth       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check arguments"                , my.args       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check test"                     , my.test       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check expect"                   , my.expe       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check return"                   , my.retn       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check code"                     , my.code       , "");                                                                                                                                                                                         <* 
    *> yUNIT_mindnoc ();                                                                                                                                                                                                                                                 <*/

   /*> yUNIT_mincond ("read section header line");                                                                                                                                                                                                                       <* 
    *> yUNIT_minval ("read a line"                        , SCRP_read   (my.f_scrp, &(my.n_line), my.dittoing, my.ditto, &(my.dline), &(my.n_recd), &(my.len), my.recd), 1);                                                                                             <* 
    *> /+> yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);   <+/   <* 
    *> strlencode (my.recd, ySTR_NONE, LEN_RECD);                                                                                                                                                                                                                        <* 
    *> yUNIT_minstr ("... check the record"               , my.recd       , "SECT         ß internal testing      ß - - - - - - - - - - - - - - -  ß - - - - -  ß - - - - - - - - - - - - - - - - - - - - - - - - -  ß");                                                <* 
    *> yUNIT_minstr ("... check verb"                     , my.verb       , "SECT");                                                                                                                                                                                     <* 
    *> yUNIT_minstr ("... check stage"                    , my.stage      , "");                                                                                                                                                                                         <* 
    *> yUNIT_minchr ("... check share"                    , my.share      , '-');                                                                                                                                                                                        <* 
    *> yUNIT_minchr ("... check mark"                     , my.mark       , '-');                                                                                                                                                                                        <* 
    *> yUNIT_minstr ("... check version"                  , my.vers       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check description"              , my.desc       , "internal testing");                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check method"                   , my.meth       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check arguments"                , my.args       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check test"                     , my.test       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check expect"                   , my.expe       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check return"                   , my.retn       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check code"                     , my.code       , "");                                                                                                                                                                                         <* 
    *> yUNIT_mindnoc ();                                                                                                                                                                                                                                                 <*/

   /*> yUNIT_mincond ("read echo line");                                                                                                                                                                                                                                 <* 
    *> yUNIT_minval ("read a line"                        , SCRP_read   (my.f_scrp, &(my.n_line), my.dittoing, my.ditto, &(my.dline), &(my.n_recd), &(my.len), my.recd), 1);                                                                                             <* 
    *> /+> yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);   <+/   <* 
    *> strlencode (my.recd, ySTR_NONE, LEN_RECD);                                                                                                                                                                                                                        <* 
    *> yUNIT_minstr ("... check the record"               , my.recd       , "    echo     ß ...check y location   ß - - - - - - - - - - - - -  ß y       ß r_norm93   ß -125.381                                     ß");                                                <* 
    *> yUNIT_minstr ("... check verb"                     , my.verb       , "echo");                                                                                                                                                                                     <* 
    *> yUNIT_minstr ("... check stage"                    , my.stage      , "");                                                                                                                                                                                         <* 
    *> yUNIT_minchr ("... check share"                    , my.share      , '-');                                                                                                                                                                                        <* 
    *> yUNIT_minchr ("... check mark"                     , my.mark       , '-');                                                                                                                                                                                        <* 
    *> yUNIT_minstr ("... check version"                  , my.vers       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check description"              , my.desc       , "...check y location");                                                                                                                                                                      <* 
    *> yUNIT_minstr ("... check method"                   , my.meth       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check arguments"                , my.args       , "y");                                                                                                                                                                                        <* 
    *> yUNIT_minstr ("... check test"                     , my.test       , "r_norm93");                                                                                                                                                                                 <* 
    *> yUNIT_minstr ("... check expect"                   , my.expe       , "-125.381");                                                                                                                                                                                 <* 
    *> yUNIT_minstr ("... check return"                   , my.retn       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check code"                     , my.code       , "y");                                                                                                                                                                                        <* 
    *> yUNIT_mindnoc ();                                                                                                                                                                                                                                                 <*/

   /*> yUNIT_mincond ("read system line");                                                                                                                                                                                                                               <* 
    *> yUNIT_minval ("read a line"                        , SCRP_read   (my.f_scrp, &(my.n_line), my.dittoing, my.ditto, &(my.dline), &(my.n_recd), &(my.len), my.recd), 1);                                                                                             <* 
    *> /+> yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);   <+/   <* 
    *> strlencode (my.recd, ySTR_NONE, LEN_RECD);                                                                                                                                                                                                                        <* 
    *> yUNIT_minstr ("... check the record"               , my.recd       , "    system   ß remove a file                       ß - - - - - - - - - - - - -  ß rm -fv test.txt   ß");                                                                                    <* 
    *> yUNIT_minstr ("... check verb"                     , my.verb       , "system");                                                                                                                                                                                   <* 
    *> yUNIT_minstr ("... check stage"                    , my.stage      , "");                                                                                                                                                                                         <* 
    *> yUNIT_minchr ("... check share"                    , my.share      , '-');                                                                                                                                                                                        <* 
    *> yUNIT_minchr ("... check mark"                     , my.mark       , '-');                                                                                                                                                                                        <* 
    *> yUNIT_minstr ("... check version"                  , my.vers       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check description"              , my.desc       , "remove a file");                                                                                                                                                                            <* 
    *> yUNIT_minstr ("... check method"                   , my.meth       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check arguments"                , my.args       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check test"                     , my.test       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check expect"                   , my.expe       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check return"                   , my.retn       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check code"                     , my.code       , "rm -fv test.txt");                                                                                                                                                                          <* 
    *> yUNIT_mindnoc ();                                                                                                                                                                                                                                                 <*/

   /*> yUNIT_mincond ("read shared section line");                                                                                                                                                                                                                       <* 
    *> yUNIT_minval ("read a line"                        , SCRP_read   (my.f_scrp, &(my.n_line), my.dittoing, my.ditto, &(my.dline), &(my.n_recd), &(my.len), my.recd), 1);                                                                                             <* 
    *> /+> yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);   <+/   <* 
    *> strlencode (my.recd, ySTR_NONE, LEN_RECD);                                                                                                                                                                                                                        <* 
    *> yUNIT_minstr ("... check the record"               , my.recd       , "SHARED   -a- ß setup cron files and lines          ß - - - - - - - -  ß ((CC.---)) ß - - - - - - - - - - - - - - - - - - - - - - - - -  ß");                                                <* 
    *> yUNIT_minstr ("... check verb"                     , my.verb       , "SHARED");                                                                                                                                                                                   <* 
    *> yUNIT_minstr ("... check stage"                    , my.stage      , "");                                                                                                                                                                                         <* 
    *> yUNIT_minchr ("... check share"                    , my.share      , 'a');                                                                                                                                                                                        <* 
    *> yUNIT_minchr ("... check mark"                     , my.mark       , '-');                                                                                                                                                                                        <* 
    *> yUNIT_minstr ("... check version"                  , my.vers       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check description"              , my.desc       , "setup cron files and lines");                                                                                                                                                               <* 
    *> yUNIT_minstr ("... check method"                   , my.meth       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check arguments"                , my.args       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check test"                     , my.test       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check expect"                   , my.expe       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check return"                   , my.retn       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check code"                     , my.code       , "");                                                                                                                                                                                         <* 
    *> yUNIT_mindnoc ();                                                                                                                                                                                                                                                 <*/

   /*> yUNIT_mincond ("read use shared line");                                                                                                                                                                                                                           <* 
    *> yUNIT_minval ("read a line"                        , SCRP_read   (my.f_scrp, &(my.n_line), my.dittoing, my.ditto, &(my.dline), &(my.n_recd), &(my.len), my.recd), 1);                                                                                             <* 
    *> /+> yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), 0);   <+/   <* 
    *> strlencode (my.recd, ySTR_NONE, LEN_RECD);                                                                                                                                                                                                                        <* 
    *> yUNIT_minstr ("... check the record"               , my.recd       , " REUSE -a-   ß - - - - - - - - - - - -  ß - - - - - - - - - - - - - - -  ß ((03.---)) ß - - - - - - - - - - - - - - - - - - - -  ß");                                                       <* 
    *> yUNIT_minstr ("... check verb"                     , my.verb       , "REUSE");                                                                                                                                                                                    <* 
    *> yUNIT_minstr ("... check stage"                    , my.stage      , "");                                                                                                                                                                                         <* 
    *> yUNIT_minchr ("... check share"                    , my.share      , 'a');                                                                                                                                                                                        <* 
    *> yUNIT_minchr ("... check mark"                     , my.mark       , '-');                                                                                                                                                                                        <* 
    *> yUNIT_minstr ("... check version"                  , my.vers       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check description"              , my.desc       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check method"                   , my.meth       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check arguments"                , my.args       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check test"                     , my.test       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check expect"                   , my.expe       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check return"                   , my.retn       , "");                                                                                                                                                                                         <* 
    *> yUNIT_minstr ("... check code"                     , my.code       , "");                                                                                                                                                                                         <* 
    *> yUNIT_mindnoc ();                                                                                                                                                                                                                                                 <*/

   /*> yUNIT_mincond ("read end-of-file");                                                                                                                                                                                                                                  <* 
    *> yUNIT_minval ("read a line"                        , SCRP_read   (my.f_scrp, &(my.n_line), my.dittoing, my.ditto, &(my.dline), &(my.n_recd), &(my.len), my.recd), 0);                                                                                                <* 
    *> /+> yUNIT_minval ("parse a line"                       , SCRP_parse  (my.n_scrp, my.n_line, my.recd, my.verb, &(my.indx), &(my.spec), &(my.p_conv), &(my.p_code), my.stage, my.vers , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   , NULL   ), -999);   <+/   <* 
    *> yUNIT_minval ("close the script file"              , SCRP_close  (&(my.f_scrp)), 0);                                                                                                                                                                                 <* 
    *> yUNIT_mindnoc ();                                                                                                                                                                                                                                                    <*/

   PROG__unit_end    ();
   rm_working_files ();
   yUNIT_minprcs ();
   return 0;
}



/*====================------------------------------------====================*/
/*===----                    actual runtime testing                    ----===*/
/*====================------------------------------------====================*/
static void      o___LIVE____________________o (void) {;}

char
koios__unit_shared_data  (char a_compile)
{
   char        x_wave      [LEN_HUND]  = "apate.wave";
   char        x_global    [LEN_HUND]  = "master.globals";

   yUNIT_minscrp ("run-time testing");
   yURG_err_none ();  /* not to stderr/terminal */

   yUNIT_mincond ("prepare a master example");
   system ("rm -f apate.unit 2> /dev/null");
   system ("echo \"#23456789-12  123456789-123456789-123456789-12345  123456789-123456  123456789-123456789-  123456789-  123456789-123456789-  123456789- \"        > master.unit");
   system ("echo \"#==(verb)===  ===========(description)===========  =====(function)=  ====(arguments)=====  ==(test)==  ====(results)=======  =(var)==== \"       >> master.unit");
   system ("echo \"PREP          global function headers             \"                                                                                                       >> master.unit");
   system ("echo \"  incl        fake header                          apate.h           \"                                                                                    >> master.unit");
   system ("echo \"  global      global variable                      - - - - - - - -   int h = 0;                                                        \"              >> master.unit");
   system ("echo \"GLOBAL   -D-  globally shared steps                0s  tbd        \"                                                                                   >> master.unit");
   system ("echo \"  COND        prepare variables                   \"                                                                                                       >> master.unit");
   system ("echo \"    code      ... set new value                    - - - - - - - -   h = 32 * 64;                                                    \"                >> master.unit");
   system ("echo \"  COND        generate a summary                  \"                                                                                                       >> master.unit");
   system ("echo \"    exec      ... check string                     yUNIT_teststring  0                         s_equal     hello                 \"                >> master.unit");
   system ("echo \"    exec      ... check number                     yUNIT_testreal    5                         r_greater   15.0                  \"                >> master.unit");
   system ("echo \"    exec      ... check integer                    yUNIT_testint     32                        i_equal     2                     \"                >> master.unit");
   yUNIT_mindnoc ();

   if (a_compile == 'y') {
      yUNIT_mincond ("turn into a master header");
      yUNIT_minval  ("... run koios"                      , system ("koios --create master"), 999);
      yUNIT_mindnoc ();
   } else {
      yUNIT_mincond ("turn into a master header");
      yUNIT_minval  ("... run koios"                      , system ("koios --update master"), 999);
      yUNIT_mindnoc ();
   }

   yUNIT_mincond ("verify exporting globals");
   yUNIT_minstr  ("... check lines"                    , yURG_peek (x_global,   0), "A   -1                                                                                0    0");
   yUNIT_minstr  ("... check lines"                    , yURG_peek (x_global, '÷'), "B   -1                                                                                0    0");
   yUNIT_minstr  ("... check lines"                    , yURG_peek (x_global, '÷'), "C   -1                                                                                0    0");
   if (a_compile == 'y')   yUNIT_minstr  ("... check lines"                    , yURG_peek (x_global, '÷'), "D    6 globally∑shared∑steps                                                          2    4");
   else                    yUNIT_minstr  ("... check lines"                    , yURG_peek (x_global, '÷'), "D    6 globally∑shared∑steps                                                          0    0");
   yUNIT_minstr  ("... check lines"                    , yURG_peek (x_global, '÷'), "E   -1                                                                                0    0");
   yUNIT_minstr  ("... check lines"                    , yURG_peek (x_global, '÷'), "F   -1                                                                                0    0");
   yUNIT_minstr  ("... check lines"                    , yURG_peek (x_global, '÷'), "G   -1                                                                                0    0");
   yUNIT_minstr  ("... check lines"                    , yURG_peek (x_global, '÷'), "H   -1                                                                                0    0");
   yUNIT_minstr  ("... check lines"                    , yURG_peek (x_global, '÷'), "I   -1                                                                                0    0");
   yUNIT_minstr  ("... check lines"                    , yURG_peek (x_global, '÷'), "J   -1                                                                                0    0");
   yUNIT_minstr  ("... check lines"                    , yURG_peek (x_global, '÷'), "K   -1                                                                                0    0");
   yUNIT_minstr  ("... check lines"                    , yURG_peek (x_global, '÷'), "L   -1                                                                                0    0");
   yUNIT_minstr  ("... check lines"                    , yURG_peek (x_global, '÷'), "M   -1                                                                                0    0");
   yUNIT_minstr  ("... check lines"                    , yURG_peek (x_global, '÷'), "N   -1                                                                                0    0");
   yUNIT_minstr  ("... check lines"                    , yURG_peek (x_global, '÷'), "O   -1                                                                                0    0");
   yUNIT_minstr  ("... check lines"                    , yURG_peek (x_global, '÷'), "P   -1                                                                                0    0");
   yUNIT_minstr  ("... check lines"                    , yURG_peek (x_global, '÷'), "Q   -1                                                                                0    0");
   yUNIT_minstr  ("... check lines"                    , yURG_peek (x_global, '÷'), "R   -1                                                                                0    0");
   yUNIT_minstr  ("... check lines"                    , yURG_peek (x_global, '÷'), "S   -1                                                                                0    0");
   yUNIT_minstr  ("... check lines"                    , yURG_peek (x_global, '÷'), "T   -1                                                                                0    0");
   yUNIT_minstr  ("... check lines"                    , yURG_peek (x_global, '÷'), "U   -1                                                                                0    0");
   yUNIT_minstr  ("... check lines"                    , yURG_peek (x_global, '÷'), "V   -1                                                                                0    0");
   yUNIT_minstr  ("... check lines"                    , yURG_peek (x_global, '÷'), "W   -1                                                                                0    0");
   yUNIT_minstr  ("... check lines"                    , yURG_peek (x_global, '÷'), "X   -1                                                                                0    0");
   yUNIT_minstr  ("... check lines"                    , yURG_peek (x_global, '÷'), "Y   -1                                                                                0    0");
   yUNIT_minstr  ("... check lines"                    , yURG_peek (x_global, '÷'), "Z   -1                                                                                0    0");
   yUNIT_minstr  ("... check lines"                    , yURG_peek (x_global, '÷'), ""                                                                                            );
   yUNIT_mindnoc ();

   yUNIT_mincond ("prepare a header example");
   system ("rm -f apate.h    2> /dev/null");
   system ("echo \"#define WEIRD_BIT \"booga\"\"                                                                                                                                   > apate.h");
   yUNIT_mindnoc ();

   yUNIT_mincond ("prepare a interesting example");
   system ("rm -f apate.unit 2> /dev/null");
   system ("echo \"#23456789-12  123456789-123456789-123456789-12345  123456789-123456  123456789-123456789-  123456789-  123456789-123456789-  123456789- \"        > apate.unit");
   system ("echo \"#==(verb)===  ===========(description)===========  =====(function)=  ====(arguments)=====  ==(test)==  ====(results)=======  =(var)==== \"       >> apate.unit");
   system ("echo \"PREP          global function headers             \"                                                                                                       >> apate.unit");
   system ("echo \"  incl        fake header                          apate.h           \"                                                                                    >> apate.unit");
   system ("echo \"SECT          simple testing                      \"                                                                                                       >> apate.unit");
   system ("echo \"SCRP    [¿Í]  (SCRP) verify openning and closing   0s  tbd        \"                                                                                   >> apate.unit");
   system ("echo \"  COND        simple openning                     \"                                                                                                       >> apate.unit");
   system ("echo \"    exec      ... check string                     yUNIT_teststring  0                         s_equal     hello                 \"                >> apate.unit");
   system ("echo \"    exec      ... check number                     yUNIT_testreal    5                         r_greater   15.0                  \"                >> apate.unit");
   system ("echo \"    exec      ... check integer                    yUNIT_testint     32                        i_equal     2                     \"                >> apate.unit");
   system ("echo \"    exec      ... check character                  yUNIT_testchar    65                        i_equal     'A'                   \"                >> apate.unit");
   system ("echo \"  COND   (1)  defensive checks                    \"                                                                                                       >> apate.unit");
   system ("echo \"    load      ... prep data for read               stdin             one two three                                                   \"                >> apate.unit");
   system ("echo \"    get       ... check number                     yUNIT_testreal    5                         r_greater   15.0                  \"                >> apate.unit");
   system ("echo \"    exec      ... check integer                    yUNIT_testint     32                        i_equal     2                     \"                >> apate.unit");
   system ("echo \"    exec      ... check character                  yUNIT_testchar    65                        i_equal     'A'                   \"                >> apate.unit");
   system ("echo \"  DITTO  (1)  - - - - - - - - - - - - - - - - - - \"                                                                                                       >> apate.unit");
   system ("echo \"  COND        small condition                     \"                                                                                                       >> apate.unit");
   system ("echo \"    exec      ... check string                     yUNIT_teststring  0                         s_equal     hello                 \"                >> apate.unit");
   system ("echo \"  DITTO  (1)  - - - - - - - - - - - - - - - - - - \"                                                                                                       >> apate.unit");
   system ("echo \"  COND        duplicate opens and closes          \"                                                                                                       >> apate.unit");
   system ("echo \"    local     ... working variables                - - - - - - - -   int c = 0;                                                      \"                >> apate.unit");
   system ("echo \"    echo      ... check working variable           - - - - - - - -   c                         i_equal     0                     \"                >> apate.unit");
   system ("echo \"    load      ... prep data for read               stdin             one two three                                                   \"                >> apate.unit");
   system ("echo \"    mode      FORCED_FAIL                         \"                                                                                                       >> apate.unit");
   system ("echo \"    system    ... run little                       - - - - - - - -   /bin/false                                                      \"                >> apate.unit");
   system ("echo \"SECT          more complex testing                \"                                                                                                       >> apate.unit");
   system ("echo \"SHARED   -a-  prepare files for use                0s  tbd         \"                                                                                  >> apate.unit");
   system ("echo \"  COND        script input file                   \"                                                                                                       >> apate.unit");
   system ("echo \"    exec      ... check string                     yUNIT_teststring  0                         s_equal     hello                 \"                >> apate.unit");
   system ("echo \"    exec      ... check number                     yUNIT_testreal    5                         r_greater   15.0                  \"                >> apate.unit");
   system ("echo \"    exec      ... check integer                    yUNIT_testint     32                        i_equal     2                     \"                >> apate.unit");
   system ("echo \"    mode      normal                              \"                                                                                                       >> apate.unit");
   system ("echo \"  COND        code output file                    \"                                                                                                       >> apate.unit");
   system ("echo \"    exec      ... check string                     yUNIT_teststring  0                         s_equal     hello                 \"                >> apate.unit");
   system ("echo \"    exec      ... check number                     yUNIT_testreal    5                         r_greater   15.0                  \"                >> apate.unit");
   system ("echo \"    exec      ... check integer                    yUNIT_testint     32                        i_equal     2                     \"                >> apate.unit");
   system ("echo \"    exec      ... check character                  yUNIT_testchar    65                        i_equal     'A'                   \"                >> apate.unit");
   system ("echo \"SHARED   -b-  remove files after use               0s  tbd         \"                                                                                  >> apate.unit");
   system ("echo \"  COND        code output file                    \"                                                                                                       >> apate.unit");
   system ("echo \"    exec      ... check string                     yUNIT_teststring  0                         s_equal     hello                 \"                >> apate.unit");
   system ("echo \"    exec      ... check number                     yUNIT_testreal    5                         r_greater   15.0                  \"                >> apate.unit");
   system ("echo \"    exec      ... check integer                    yUNIT_testint     32                        i_equal     2                     \"                >> apate.unit");
   system ("echo \"    exec      ... check character                  yUNIT_testchar    65                        i_equal     'A'                   \"                >> apate.unit");
   system ("echo \"  COND        close and delete code file          \"                                                                                                       >> apate.unit");
   system ("echo \"    exec      ... check string                     yUNIT_teststring  0                         s_equal     hello                 \"                >> apate.unit");
   system ("echo \"    exec      ... check number                     yUNIT_testreal    5                         r_greater   15.0                  \"                >> apate.unit");
   system ("echo \"    exec      ... check integer                    yUNIT_testint     32                        i_equal     2                     \"                >> apate.unit");
   system ("echo \"    exec      ... check character                  yUNIT_testchar    65                        i_equal     'A'                   \"                >> apate.unit");
   system ("echo \"SCRP    [¿Î]  (SCRP) verify system startup          0s  tbd                          \"                                                              >> apate.unit");
   system ("echo \"  COND        run initialization                  \"                                                                                                       >> apate.unit");
   system ("echo \"    exec      ... check string                     yUNIT_teststring  0                         s_equal     hello                 \"                >> apate.unit");
   system ("echo \"    mode      FORCED_FAIL                         \"                                                                                                       >> apate.unit");
   system ("echo \"    exec      ... check integer                    yUNIT_testint     32                        i_equal     2                     \"                >> apate.unit");
   system ("echo \"    exec      ... check character                  yUNIT_testchar    65                        i_equal     'A'                   \"                >> apate.unit");
   system ("echo \"  REUSE  -a-  - - - - - - - - - - - - - - - - -   \"                                                                                                       >> apate.unit");
   system ("echo \"  COND        parse a code record                 \"                                                                                                       >> apate.unit");
   system ("echo \"    local     ... create string                    - - - - - - - -   char  x_str [100];                                              \"                >> apate.unit");
   system ("echo \"    exec      ... check string                     yUNIT_teststring  0                         s_equal     hello                  x_str  \"        >> apate.unit");
   system ("echo \"    echo      ... verify string                    - - - - - - - -   x_str                     s_equal     hello                 \"                >> apate.unit");
   system ("echo \"    local     ... create number                    - - - - - - - -   float x_real = 0.0;                                             \"                >> apate.unit");
   system ("echo \"    exec      ... check number                     yUNIT_testreal    5                         r_greater   15.0                   x_real \"        >> apate.unit");
   system ("echo \"    echo      ... verify number                    - - - - - - - -   x_real                    r_lesser    16.0                  \"                >> apate.unit");
   system ("echo \"    local     ... create integer                   - - - - - - - -   int   x_int  = 0;                                               \"                >> apate.unit");
   system ("echo \"    exec      ... check integer                    yUNIT_testint     32                        i_equal     2                      x_int  \"        >> apate.unit");
   system ("echo \"    echo      ... verify integer                   - - - - - - - -   x_int                     i_equal     2                     \"                >> apate.unit");
   system ("echo \"    local     ... create character                 - - - - - - - -   char  x_char = 0;                                               \"                >> apate.unit");
   system ("echo \"    exec      ... check character                  yUNIT_testchar    65                        i_equal     'A'                    x_char \"        >> apate.unit");
   system ("echo \"    echo      ... verify character                 - - - - - - - -   x_char                    i_equal     'A'                   \"                >> apate.unit");
   system ("echo \"    local     ... create pointer                   - - - - - - - -   int  *x_ptr  = NULL;                                            \"                >> apate.unit");
   system ("echo \"    exec      ... check pointer                    yUNIT_testptr                               p_exists    0                      x_ptr  \"        >> apate.unit");
   system ("echo \"    echo      ... verify pointer                   - - - - - - - -   x_ptr                     p_exists    0                     \"                >> apate.unit");
   system ("echo \"    echo      ... verify value at pointer          - - - - - - - -   (x_ptr) ? *x_ptr : 0      i_equal     42                    \"                >> apate.unit");
   system ("echo \"SCRP    [¡Ï]  (SCRP) verify normal processing       0s  tbd                          \"                                                              >> apate.unit");
   system ("echo \"  GROUP       round one                           \"                                                                                                       >> apate.unit");
   system ("echo \"  COND   (1)  process arguments                   \"                                                                                                       >> apate.unit");
   system ("echo \"    exec      ... check string                     yUNIT_teststring  0                         s_equal     hello                 \"                >> apate.unit");
   system ("echo \"    exec      ... check number                     yUNIT_testreal    5                         r_greater   15.0                  \"                >> apate.unit");
   system ("echo \"    exec      ... check integer                    yUNIT_testint     32                        i_equal     2                     \"                >> apate.unit");
   system ("echo \"    exec      ... check character                  yUNIT_testchar    65                        i_equal     'A'                   \"                >> apate.unit");
   system ("echo \"  REUSE  -a-  - - - - - - - - - - - - - - - - -   \"                                                                                                       >> apate.unit");
   system ("echo \"  COND   (2)  read one record                     \"                                                                                                       >> apate.unit");
   system ("echo \"    exec      ... check string                     yUNIT_teststring  1                         s_equal     hello                 \"                >> apate.unit");
   system ("echo \"    exec      ... check number                     yUNIT_testreal    2                         r_greater   15.0                  \"                >> apate.unit");
   system ("echo \"    exec      ... check integer                    yUNIT_testint     64                        i_equal     2                     \"                >> apate.unit");
   system ("echo \"    exec      ... check character                  yUNIT_testchar    87                        i_equal     'A'                   \"                >> apate.unit");
   system ("echo \"  GROUP       round two                           \"                                                                                                       >> apate.unit");
   system ("echo \"  DITTO  (1)  - - - - - - - - - - - - - - - - -   \"                                                                                                       >> apate.unit");
   system ("echo \"  REUSE  -b-  - - - - - - - - - - - - - - - - -   \"                                                                                                       >> apate.unit");
   system ("echo \"  GROUP       final round                         \"                                                                                                       >> apate.unit");
   system ("echo \"  DITTO  (2)  - - - - - - - - - - - - - - - - -   \"                                                                                                       >> apate.unit");
   system ("echo \"  REUSE  -D-  - - - - - - - - - - - - - - - - -   \"                                                                                                       >> apate.unit");
   system ("echo \"  DITTO  (1)  - - - - - - - - - - - - - - - - -   \"                                                                                                       >> apate.unit");
   system ("echo \"SCRP    [¬Ú]  (SCRP) empty script                   0s  tbd                          \"                                                              >> apate.unit");
   yUNIT_mindnoc ();

   if (a_compile == 'y') {
      yUNIT_mincond ("turn into a unit test");
      yUNIT_minval  ("... run koios"                      , system ("koios --create apate"), 999);
      yUNIT_minval  ("... copy to c"                      , system ("cp  -f apate_unit.{cs,c}"), 0);
      yUNIT_minval  ("... compile"                        , system ("gcc -c apate_unit.c"), 0);
      yUNIT_minval  ("... link"                           , system ("gcc -o apate_unit apate_unit.o -lyUNIT"), 0);
      yUNIT_minval  ("... permissions"                    , system ("chmod +x apate_unit"), 0);
      yUNIT_mindnoc ();
   }

   if (a_compile == 'y') {
      yUNIT_mincond ("verify waves");
      yUNIT_minstr  ("check wave entry"                   , yURG_peek (x_wave, '∫'), "¿  Í  apate.unit                       1  (SCRP) verify openning and closing                                ");
      yUNIT_minstr  ("check wave entry"                   , yURG_peek (x_wave, '÷'), "¿  Î  apate.unit                       2  (SCRP) verify system startup                                      ");
      yUNIT_minstr  ("check wave entry"                   , yURG_peek (x_wave, '÷'), "¡  Ï  apate.unit                       3  (SCRP) verify normal processing                                   ");
      yUNIT_minstr  ("check wave entry"                   , yURG_peek (x_wave, '÷'), "¬  Ú  apate.unit                       4  (SCRP) empty script                                               ");
      yUNIT_minval  ("... check line count"               , yURG_peek_count (x_wave) ,  4);
      yUNIT_minprcs ();
   }

   return 0;
}

char
koios__unit_live_conv    (char a_list)
{
   int         c           =    0;
   char        x_master    [LEN_HUND]  = "master.unit";
   char        x_global    [LEN_HUND]  = "master.globals";
   char        x_unit      [LEN_HUND]  = "apate.unit";
   char        x_wave      [LEN_HUND]  = "apate.wave";

   yUNIT_minscrp ("live testing for conversion");
   if (a_list == 'y')  return 0;
   yURG_err_none ();  /* not to stderr/terminal */
   rm_working_files ();
   PROG__unit_quiet  ();

   koios__unit_shared_data ('-');

   /*> PROG__unit_loud   ();                                                          <*/

   /*> yUNIT_mincond ("call master conversion");                                                                        <* 
    *> yUNIT_minval  ("... run master"                     , system ("koios --update master > /dev/null 2>&1"),   0);   <* 
    *> yUNIT_minval  ("... check line count"               , yURG_peek_count (x_master) ,  28);                         <* 
    *> yUNIT_mindnoc ();                                                                                                <*/

   yUNIT_mincond ("check updated master");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_master,   0), "#!/usr/local/bin/koios");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_master, '÷'), "#   koios-polos (axis of heaven) unit testing meta-language");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_master, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_master, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_master, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_master, '÷'), "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-123456789- ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_master, '÷'), "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  ========(var)======= ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_master, '÷'), "PREP          global function headers                                            - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_master, '÷'), "   incl       fake header                          apate.h                     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_master, '÷'), "   global     global variable                      - - - - - - - - - - - - -   int h = 0;                                                                                                                                                                                                                 ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_master, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_master, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_master, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_master, '÷'), "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-123456789- ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_master, '÷'), "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  ========(var)======= ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_master, '÷'), "GLOBAL   -D-  globally shared steps                                              0s   tbd                                                                                          ((DD.---))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_master, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_master, '÷'), "   COND       prepare variables                                                  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((DD.001))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_master, '÷'), "     code     ... set new value                    - - - - - - - - - - - - -   h = 32 * 64;                                                                                                                                                                                                               ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_master, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_master, '÷'), "   COND       generate a summary                                                 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((DD.002))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_master, '÷'), "     exec     ... check string                     yUNIT_teststring            0                                                                                                     s_equal     hello                                                                                                ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_master, '÷'), "     exec     ... check number                     yUNIT_testreal              5                                                                                                     r_greater   15.0                                                                                                 ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_master, '÷'), "     exec     ... check integer                    yUNIT_testint               32                                                                                                    i_equal     2                                                                                                    ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_master, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_master, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_master, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_master, '÷'), "# end-of-file.  done, finito, completare, whimper [œ¥∑∑∑");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_master, '÷'), "");
   yUNIT_mindnoc ();

   /*> PROG__unit_end    ();                                                          <*/

   yUNIT_mincond ("call conversion");
   yUNIT_minval  ("... run koios"                      , system ("koios --update apate > /dev/null 2>&1"),   0);
   yUNIT_minval  ("... check line count"               , yURG_peek_count (x_unit) , 167);
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify header");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit,   0), "#!/usr/local/bin/koios");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "#   koios-polos (axis of heaven) unit testing meta-language");
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify prep/incl");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-123456789- ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  ========(var)======= ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "PREP          global function headers                                            - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "   incl       fake header                          apate.h                     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify sect");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-123456789- ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  ========(var)======= ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "SECT          simple testing                                                     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify script with dittoing");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-123456789- ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  ========(var)======= ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "SCRP    [¿Í]  (SCRP) verify openning and closing                                 0s   tbd                                                                                          ((01.---))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "   COND       simple openning                                                    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((01.001))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "     exec     ... check string                     yUNIT_teststring            0                                                                                                     s_equal     hello                                                                                                ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "     exec     ... check number                     yUNIT_testreal              5                                                                                                     r_greater   15.0                                                                                                 ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "     exec     ... check integer                    yUNIT_testint               32                                                                                                    i_equal     2                                                                                                    ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "     exec     ... check character                  yUNIT_testchar              65                                                                                                    i_equal     'A'                                                                                                  ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "   COND  (1)  defensive checks                                                   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((01.002))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "     load     ... prep data for read               stdin                       one two three                                                                                                                                                                                                              ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "     get      ... check number                     yUNIT_testreal              5                                                                                                     r_greater   15.0                                                                                                 ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "     exec     ... check integer                    yUNIT_testint               32                                                                                                    i_equal     2                                                                                                    ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "     exec     ... check character                  yUNIT_testchar              65                                                                                                    i_equal     'A'                                                                                                  ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "   DITTO (1)  [ defensive checks ]                                               - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((01.003))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "   COND       small condition                                                    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((01.004))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "     exec     ... check string                     yUNIT_teststring            0                                                                                                     s_equal     hello                                                                                                ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "   DITTO (1)  [ defensive checks ]                                               - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((01.005))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "   COND       duplicate opens and closes                                         - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((01.006))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "     local    ... working variables                - - - - - - - - - - - - -   int c = 0;                                                                                                                                                                                                                 ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "     echo     ... check working variable           - - - - - - - - - - - - -   c                                                                                                     i_equal     0                                                                                                    ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "     load     ... prep data for read               stdin                       one two three                                                                                                                                                                                                              ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "     mode     FORCED_FAIL                          - - - - - - - - - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "     system   ... run little                       - - - - - - - - - - - - -   /bin/false                                                                                                                                                                                                                 ");
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify sect");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-123456789- ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  ========(var)======= ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "SECT          more complex testing                                               - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify shared a");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-123456789- ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  ========(var)======= ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "SHARED   -a-  prepare files for use                                              0s   tbd                                                                                          ((aa.---))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "   COND       script input file                                                  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((aa.001))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "     exec     ... check string                     yUNIT_teststring            0                                                                                                     s_equal     hello                                                                                                ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "     exec     ... check number                     yUNIT_testreal              5                                                                                                     r_greater   15.0                                                                                                 ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "     exec     ... check integer                    yUNIT_testint               32                                                                                                    i_equal     2                                                                                                    ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "     mode     normal                               - - - - - - - - - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "   COND       code output file                                                   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((aa.002))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "     exec     ... check string                     yUNIT_teststring            0                                                                                                     s_equal     hello                                                                                                ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "     exec     ... check number                     yUNIT_testreal              5                                                                                                     r_greater   15.0                                                                                                 ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "     exec     ... check integer                    yUNIT_testint               32                                                                                                    i_equal     2                                                                                                    ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "     exec     ... check character                  yUNIT_testchar              65                                                                                                    i_equal     'A'                                                                                                  ");
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify shared b");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-123456789- ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  ========(var)======= ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "SHARED   -b-  remove files after use                                             0s   tbd                                                                                          ((bb.---))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "   COND       code output file                                                   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((bb.001))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "     exec     ... check string                     yUNIT_teststring            0                                                                                                     s_equal     hello                                                                                                ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "     exec     ... check number                     yUNIT_testreal              5                                                                                                     r_greater   15.0                                                                                                 ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "     exec     ... check integer                    yUNIT_testint               32                                                                                                    i_equal     2                                                                                                    ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "     exec     ... check character                  yUNIT_testchar              65                                                                                                    i_equal     'A'                                                                                                  ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "   COND       close and delete code file                                         - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((bb.002))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "     exec     ... check string                     yUNIT_teststring            0                                                                                                     s_equal     hello                                                                                                ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "     exec     ... check number                     yUNIT_testreal              5                                                                                                     r_greater   15.0                                                                                                 ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "     exec     ... check integer                    yUNIT_testint               32                                                                                                    i_equal     2                                                                                                    ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "     exec     ... check character                  yUNIT_testchar              65                                                                                                    i_equal     'A'                                                                                                  ");
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify script with a reuse");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-123456789- ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  ========(var)======= ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "SCRP    [¿Î]  (SCRP) verify system startup                                       0s   tbd                                                                                          ((02.---))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "   COND       run initialization                                                 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((02.001))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "     exec     ... check string                     yUNIT_teststring            0                                                                                                     s_equal     hello                                                                                                ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "     mode     FORCED_FAIL                          - - - - - - - - - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "     exec     ... check integer                    yUNIT_testint               32                                                                                                    i_equal     2                                                                                                    ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "     exec     ... check character                  yUNIT_testchar              65                                                                                                    i_equal     'A'                                                                                                  ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "   REUSE -a-  [ prepare files for use ]                                          - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((02.002))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "   COND       parse a code record                                                - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((02.003))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "     local    ... create string                    - - - - - - - - - - - - -   char  x_str [100];                                                                                                                                                                                                         ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "     exec     ... check string                     yUNIT_teststring            0                                                                                                     s_equal     hello                                                                                                 x_str                ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "     echo     ... verify string                    - - - - - - - - - - - - -   x_str                                                                                                 s_equal     hello                                                                                                ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "     local    ... create number                    - - - - - - - - - - - - -   float x_real = 0.0;                                                                                                                                                                                                        ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "     exec     ... check number                     yUNIT_testreal              5                                                                                                     r_greater   15.0                                                                                                  x_real               ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "     echo     ... verify number                    - - - - - - - - - - - - -   x_real                                                                                                r_lesser    16.0                                                                                                 ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "     local    ... create integer                   - - - - - - - - - - - - -   int   x_int  = 0;                                                                                                                                                                                                          ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "     exec     ... check integer                    yUNIT_testint               32                                                                                                    i_equal     2                                                                                                     x_int                ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "     echo     ... verify integer                   - - - - - - - - - - - - -   x_int                                                                                                 i_equal     2                                                                                                    ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "     local    ... create character                 - - - - - - - - - - - - -   char  x_char = 0;                                                                                                                                                                                                          ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "     exec     ... check character                  yUNIT_testchar              65                                                                                                    i_equal     'A'                                                                                                   x_char               ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "     echo     ... verify character                 - - - - - - - - - - - - -   x_char                                                                                                i_equal     'A'                                                                                                  ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "     local    ... create pointer                   - - - - - - - - - - - - -   int  *x_ptr  = NULL;                                                                                                                                                                                                       ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "     exec     ... check pointer                    yUNIT_testptr                                                                                                                     p_exists    0                                                                                                     x_ptr                ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "     echo     ... verify pointer                   - - - - - - - - - - - - -   x_ptr                                                                                                 p_exists    0                                                                                                    ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "     echo     ... verify value at pointer          - - - - - - - - - - - - -   (x_ptr) ? *x_ptr : 0                                                                                  i_equal     42                                                                                                   ");
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify script with multiple reuses and dittos");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-123456789- ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  ========(var)======= ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "SCRP    [¡Ï]  (SCRP) verify normal processing                                    0s   tbd                                                                                          ((03.---))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "   GROUP      round one                                                          - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "   COND  (1)  process arguments                                                  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((03.001))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "     exec     ... check string                     yUNIT_teststring            0                                                                                                     s_equal     hello                                                                                                ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "     exec     ... check number                     yUNIT_testreal              5                                                                                                     r_greater   15.0                                                                                                 ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "     exec     ... check integer                    yUNIT_testint               32                                                                                                    i_equal     2                                                                                                    ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "     exec     ... check character                  yUNIT_testchar              65                                                                                                    i_equal     'A'                                                                                                  ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "   REUSE -a-  [ prepare files for use ]                                          - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((03.002))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "   COND  (2)  read one record                                                    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((03.003))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "     exec     ... check string                     yUNIT_teststring            1                                                                                                     s_equal     hello                                                                                                ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "     exec     ... check number                     yUNIT_testreal              2                                                                                                     r_greater   15.0                                                                                                 ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "     exec     ... check integer                    yUNIT_testint               64                                                                                                    i_equal     2                                                                                                    ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "     exec     ... check character                  yUNIT_testchar              87                                                                                                    i_equal     'A'                                                                                                  ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "   GROUP      round two                                                          - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "   DITTO (1)  [ process arguments ]                                              - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((03.004))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "   REUSE -b-  [ remove files after use ]                                         - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((03.005))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "   GROUP      final round                                                        - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "   DITTO (2)  [ read one record ]                                                - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((03.006))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "   REUSE -D-  [ globally shared steps ]                                          - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((03.007))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "   DITTO (1)  [ process arguments ]                                              - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((03.008))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify empty script");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-123456789- ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  ========(var)======= ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "SCRP    [¬Ú]  (SCRP) empty script                                                0s   tbd                                                                                          ((04.---))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify footer");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "# end-of-file.  done, finito, completare, whimper [œ¥∑∑∑");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_mindnoc ();

   /*> yUNIT_mincond  ("verify the WAVE file)");                                                                                                                                                                           <* 
    *> yUNIT_minstr   ("... check WAVE"                     , yURG_peek      (x_wave    ,   0)   , "¿  Í  apate.unit                       1  (SCRP) verify openning and closing                                ");   <* 
    *> yUNIT_minstr   ("... check WAVE"                     , yURG_peek      (x_wave    , '÷')   , "¿  Î  apate.unit                       2  (SCRP) verify system startup                                      ");   <* 
    *> yUNIT_minstr   ("... check WAVE"                     , yURG_peek      (x_wave    , '÷')   , "¡  Ï  apate.unit                       3  (SCRP) verify normal processing                                   ");   <* 
    *> yUNIT_minstr   ("... check WAVE"                     , yURG_peek      (x_wave    , '÷')   , "¬  Ú  apate.unit                       4  (SCRP) empty script                                               ");   <* 
    *> yUNIT_minstr   ("... check WAVE"                     , yURG_peek      (x_wave    , '÷')   , ""                                           );                                                                         <* 
    *> yUNIT_mindnoc  ();                                                                                                                                                                                                  <*/

   PROG__unit_end    ();
   rm_working_files ();
   yUNIT_minprcs ();
   return 0;
}

char
koios__unit_live_ditto   (char a_list)
{
   int         c           =    0;
   char        x_master    [LEN_HUND]  = "master_unit.cs";
   char        x_global    [LEN_HUND]  = "master.globals";
   char        x_ncode     [LEN_HUND]  = "apate_unit.cs";
   char        x_wave      [LEN_HUND]  = "apate.wave";

   yUNIT_minscrp ("live testing for ditto");
   if (a_list == 'y')  return 0;
   yURG_err_none ();  /* not to stderr/terminal */
   rm_working_files ();
   PROG__unit_quiet  ();

   yUNIT_mincond  ("create a sample unit with ditto");
   system ("echo \"SCRP          verify ditto                         0s  tbd        \"                                                                                   >  apate.unit");
   system ("echo \"  COND   (1)  repeat code                         \"                                                                                                       >> apate.unit");
   system ("echo \"    exec      ... check integer                    yUNIT_testint     32                        i_equal     2                     \"                >> apate.unit");
   system ("echo \"    exec      ... check character                  yUNIT_testchar    65                        i_equal     'A'                   \"                >> apate.unit");
   system ("echo \"  COND        non-repeat code before ditto        \"                                                                                                       >> apate.unit");
   system ("echo \"    exec      ... check integer                    yUNIT_testint     32                        i_equal     2                     \"                >> apate.unit");
   system ("echo \"  DITTO  (1)  - - - - - - - - - - - - - - - - - - \"                                                                                                       >> apate.unit");
   system ("echo \"  COND        non-repeat code after ditto         \"                                                                                                       >> apate.unit");
   system ("echo \"    exec      ... check integer                    yUNIT_testint     32                        i_equal     2                     \"                >> apate.unit");
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("call live code creation");
   yUNIT_minval   ("... run koios"                      , system ("koios --create apate  > /dev/null 2>&1"),   0);
   yUNIT_minval   ("... copy to c"                      , system ("cp  -f apate_unit.{cs,c}"), 0);
   yUNIT_minval   ("... compile"                        , system ("gcc -c apate_unit.c"), 0);
   yUNIT_minval   ("... link"                           , system ("gcc -o apate_unit apate_unit.o -lyUNIT"), 0);
   yUNIT_minval   ("... permissions"                    , system ("chmod +x apate_unit"), 0);
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify code header");
   yUNIT_minstr   ("... check line"                     , yURG_peek (x_ncode,   0), "/*================================= beg-code =================================*/");
   yUNIT_minstr   ("... check line"                     , yURG_peek (x_ncode, '÷'), "/* /usr/local/bin/koios                                                       */");
   yUNIT_minstr   ("... check line"                     , yURG_peek (x_ncode, '÷'), "/*   autogen by koios-polos (axis of heaven) unit testing meta-language       */");
   yUNIT_minstr   ("... check line"                     , yURG_peek (x_ncode, '÷'), "");
   yUNIT_minstr   ("... check line"                     , yURG_peek (x_ncode, '÷'), "/*---(standard support functions)----*/");
   yUNIT_minstr   ("... check line"                     , yURG_peek (x_ncode, '÷'), "#include    <yUNIT_unit.h>");
   yUNIT_minstr   ("... check line"                     , yURG_peek (x_ncode, '÷'), "#include    \"master.h\"");
   yUNIT_minstr   ("... check line"                     , yURG_peek (x_ncode, '÷'), "");
   yUNIT_minstr   ("... check line"                     , yURG_peek (x_ncode, '÷'), "/*================================ beg-script ================================*/");
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify script");
   yUNIT_minstr   ("... check line"                     , yURG_peek (x_ncode, '÷'), "");
   yUNIT_minstr   ("... check line"                     , yURG_peek (x_ncode, '÷'), "char");
   yUNIT_minstr   ("... check line"                     , yURG_peek (x_ncode, '÷'), "yUNIT_script_01          (void)");
   yUNIT_minstr   ("... check line"                     , yURG_peek (x_ncode, '÷'), "{");
   yUNIT_minstr   ("... check line"                     , yURG_peek (x_ncode, '÷'), "   /*===[[ script header ]]========================*/");
   yUNIT_minstr   ("... check line"                     , yURG_peek (x_ncode, '÷'), "   cyUNIT.offset  = 0;");
   yUNIT_minstr   ("... check line"                     , yURG_peek (x_ncode, '÷'), "   cyUNIT.origin  = 1;");
   yUNIT_minstr   ("... check line"                     , yURG_peek (x_ncode, '÷'), "   yUNIT_mode_reset ();");
   yUNIT_minstr   ("... check line"                     , yURG_peek (x_ncode, '÷'), "   yUNIT_scrp    (   1,   1, \"\", \"verify ditto\", \"0s\", \"tbd\", \"\");");
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify repeatable condition");
   yUNIT_minstr   ("... check line"                     , yURG_peek (x_ncode, '÷'), "   /*===[[ COND #001 ]]============================*/");
   yUNIT_minstr   ("... check line"                     , yURG_peek (x_ncode, '÷'), "   yUNIT_cond    (   2, cyUNIT.offset +   1, '!', \"repeat code\");");
   yUNIT_minstr   ("... check line"                     , yURG_peek (x_ncode, '÷'), "      /*---(run step)--------------------*/");
   yUNIT_minstr   ("... check line"                     , yURG_peek (x_ncode, '÷'), "      yUNIT_reset_rc ();");
   yUNIT_minstr   ("... check line"                     , yURG_peek (x_ncode, '÷'), "      if (cyUNIT.exec)  cyUNIT.i_rc = yUNIT_testint (32);");
   yUNIT_minstr   ("... check line"                     , yURG_peek (x_ncode, '÷'), "      yUNIT_int     (   3,   1, \"... check integer\", \"yUNIT_testint\", \"32\", \"i_equal\", 2, cyUNIT.i_rc, cyUNIT.exec);");
   yUNIT_minstr   ("... check line"                     , yURG_peek (x_ncode, '÷'), "      /*---(run step)--------------------*/");
   yUNIT_minstr   ("... check line"                     , yURG_peek (x_ncode, '÷'), "      yUNIT_reset_rc ();");
   yUNIT_minstr   ("... check line"                     , yURG_peek (x_ncode, '÷'), "      if (cyUNIT.exec)  cyUNIT.i_rc = yUNIT_testchar (65);");
   yUNIT_minstr   ("... check line"                     , yURG_peek (x_ncode, '÷'), "      yUNIT_int     (   4,   2, \"... check character\", \"yUNIT_testchar\", \"65\", \"i_equal\", 'A', cyUNIT.i_rc, cyUNIT.exec);");
   yUNIT_minstr   ("... check line"                     , yURG_peek (x_ncode, '÷'), "      /*---(summary)---------------------*/");
   yUNIT_minstr   ("... check line"                     , yURG_peek (x_ncode, '÷'), "      yUNIT_dnoc    (cyUNIT.exec);"         );
   yUNIT_minstr   ("... check line"                     , yURG_peek (x_ncode, '÷'), "      /*---(done)------------------------*/");
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify non-repeatable condition");
   yUNIT_minstr   ("... check line"                     , yURG_peek (x_ncode, '÷'), "   /*===[[ COND #002 ]]============================*/");
   yUNIT_minstr   ("... check line"                     , yURG_peek (x_ncode, '÷'), "   yUNIT_cond    (   5, cyUNIT.offset +   2, '-', \"non-repeat code before ditto\");");
   yUNIT_minstr   ("... check line"                     , yURG_peek (x_ncode, '÷'), "      /*---(run step)--------------------*/");
   yUNIT_minstr   ("... check line"                     , yURG_peek (x_ncode, '÷'), "      yUNIT_reset_rc ();");
   yUNIT_minstr   ("... check line"                     , yURG_peek (x_ncode, '÷'), "      if (cyUNIT.exec)  cyUNIT.i_rc = yUNIT_testint (32);");
   yUNIT_minstr   ("... check line"                     , yURG_peek (x_ncode, '÷'), "      yUNIT_int     (   6,   1, \"... check integer\", \"yUNIT_testint\", \"32\", \"i_equal\", 2, cyUNIT.i_rc, cyUNIT.exec);");
   yUNIT_minstr   ("... check line"                     , yURG_peek (x_ncode, '÷'), "      /*---(summary)---------------------*/");
   yUNIT_minstr   ("... check line"                     , yURG_peek (x_ncode, '÷'), "      yUNIT_dnoc    (cyUNIT.exec);"         );
   yUNIT_minstr   ("... check line"                     , yURG_peek (x_ncode, '÷'), "      /*---(done)------------------------*/");
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify ditto on repeatable condition");
   yUNIT_minstr   ("... check line"                     , yURG_peek (x_ncode, '÷'), "   /*===[[ COND #003 ]]============================*/");
   yUNIT_minstr   ("... check line"                     , yURG_peek (x_ncode, '÷'), "   yUNIT_cond    (   7, cyUNIT.offset +   3, '1', \"[ repeat code ]\");");
   yUNIT_minstr   ("... check line"                     , yURG_peek (x_ncode, '÷'), "      /*---(run step)--------------------*/");
   yUNIT_minstr   ("... check line"                     , yURG_peek (x_ncode, '÷'), "      yUNIT_reset_rc ();");
   yUNIT_minstr   ("... check line"                     , yURG_peek (x_ncode, '÷'), "      if (cyUNIT.exec)  cyUNIT.i_rc = yUNIT_testint (32);");
   yUNIT_minstr   ("... check line"                     , yURG_peek (x_ncode, '÷'), "      yUNIT_int     (   3,   1, \"... check integer\", \"yUNIT_testint\", \"32\", \"i_equal\", 2, cyUNIT.i_rc, cyUNIT.exec);");
   yUNIT_minstr   ("... check line"                     , yURG_peek (x_ncode, '÷'), "      /*---(run step)--------------------*/");
   yUNIT_minstr   ("... check line"                     , yURG_peek (x_ncode, '÷'), "      yUNIT_reset_rc ();");
   yUNIT_minstr   ("... check line"                     , yURG_peek (x_ncode, '÷'), "      if (cyUNIT.exec)  cyUNIT.i_rc = yUNIT_testchar (65);");
   yUNIT_minstr   ("... check line"                     , yURG_peek (x_ncode, '÷'), "      yUNIT_int     (   4,   2, \"... check character\", \"yUNIT_testchar\", \"65\", \"i_equal\", 'A', cyUNIT.i_rc, cyUNIT.exec);");
   yUNIT_minstr   ("... check line"                     , yURG_peek (x_ncode, '÷'), "      /*---(summary)---------------------*/");
   yUNIT_minstr   ("... check line"                     , yURG_peek (x_ncode, '÷'), "      yUNIT_dnoc    (cyUNIT.exec);"         );
   yUNIT_minstr   ("... check line"                     , yURG_peek (x_ncode, '÷'), "      /*---(done)------------------------*/");
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify non-repeatable condition");
   yUNIT_minstr   ("... check line"                     , yURG_peek (x_ncode, '÷'), "   /*===[[ COND #004 ]]============================*/");
   yUNIT_minstr   ("... check line"                     , yURG_peek (x_ncode, '÷'), "   yUNIT_cond    (   8, cyUNIT.offset +   4, '-', \"non-repeat code after ditto\");");
   yUNIT_minstr   ("... check line"                     , yURG_peek (x_ncode, '÷'), "      /*---(run step)--------------------*/");
   yUNIT_minstr   ("... check line"                     , yURG_peek (x_ncode, '÷'), "      yUNIT_reset_rc ();");
   yUNIT_minstr   ("... check line"                     , yURG_peek (x_ncode, '÷'), "      if (cyUNIT.exec)  cyUNIT.i_rc = yUNIT_testint (32);");
   yUNIT_minstr   ("... check line"                     , yURG_peek (x_ncode, '÷'), "      yUNIT_int     (   9,   1, \"... check integer\", \"yUNIT_testint\", \"32\", \"i_equal\", 2, cyUNIT.i_rc, cyUNIT.exec);");
   yUNIT_minstr   ("... check line"                     , yURG_peek (x_ncode, '÷'), "      /*---(summary)---------------------*/");
   yUNIT_minstr   ("... check line"                     , yURG_peek (x_ncode, '÷'), "      yUNIT_dnoc    (cyUNIT.exec);"         );
   yUNIT_minstr   ("... check line"                     , yURG_peek (x_ncode, '÷'), "      /*---(done)------------------------*/");
   yUNIT_mindnoc  ();

   yUNIT_mincond  ("verify end of script");
   yUNIT_minstr   ("... check result"                   , yURG_peek (x_ncode, '÷'), "   /*===[[ script done ]]==========================*/");
   yUNIT_minstr   ("... check result"                   , yURG_peek (x_ncode, '÷'), "   yUNIT_prcs    (cyUNIT.exec);"            );
   yUNIT_minstr   ("... check result"                   , yURG_peek (x_ncode, '÷'), "   /*---(complete)-----------------------*/");
   yUNIT_minstr   ("... check result"                   , yURG_peek (x_ncode, '÷'), "   return 0;"                               );
   yUNIT_minstr   ("... check result"                   , yURG_peek (x_ncode, '÷'), "}"                                          );
   yUNIT_minstr   ("... check line"                     , yURG_peek (x_ncode, '÷'), "");
   yUNIT_minstr   ("... check line"                     , yURG_peek (x_ncode, '÷'), "/*================================ end-script ================================*/");
   yUNIT_minstr   ("... check line"                     , yURG_peek (x_ncode, '÷'), "");
   yUNIT_mindnoc  ();

   PROG__unit_end    ();
   rm_working_files ();
   yUNIT_minprcs ();
   return 0;
}

char
koios__unit_live_scrp    (char a_list)
{
   int         c           =    0;
   char        x_urun      [LEN_HUND]  = "apate.urun";
   char        x_wave      [LEN_HUND]  = "apate.wave";

   yUNIT_minscrp ("live SCRP level testing on unit test result");
   if (a_list == 'y')  return 0;
   yURG_err_none ();  /* not to stderr/terminal */
   rm_working_files ();
   PROG__unit_quiet  ();

   koios__unit_shared_data ('y');

   yUNIT_mincond ("check inventory of scripts");
   yUNIT_minval  ("... run unit test"                  , system ("./apate_unit --scrps"), 0);
   yUNIT_minval  ("... check line count"               , yURG_peek_count (x_urun) , 17);
   yUNIT_mindnoc ();

   yUNIT_mincond ("check urun output");
   yUNIT_minstr  ("... check unit header"              , yURG_peek (x_urun, '∫'), "yUNIT - heatherly unit testing framework ---------------------------------------(beg)");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check section"                  , yURG_peek (x_urun, '÷'), "SECT ===-------------------------- simple testing ---------------------------=== TCES");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check script"                   , yURG_peek (x_urun, '÷'), "SCRP [01] (SCRP) verify openning and closing ============================[¿Í]=[00006]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check section"                  , yURG_peek (x_urun, '÷'), "SECT ===----------------------- more complex testing ------------------------=== TCES");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check script"                   , yURG_peek (x_urun, '÷'), "SCRP [02] (SCRP) verify system startup ==================================[¿Î]=[00050]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check script"                   , yURG_peek (x_urun, '÷'), "SCRP [03] (SCRP) verify normal processing ===============================[¡Ï]=[00074]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check script"                   , yURG_peek (x_urun, '÷'), "SCRP [04] (SCRP) empty script ===========================================[¬Ú]=[00094]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check unit footer"              , yURG_peek (x_urun, '÷'), "TINU  scrp=4    cond=21    test=90    [ ------------------------------------------- ]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check unit footer"              , yURG_peek (x_urun, '÷'), "yUNIT - heatherly unit testing framework ---------------------------------------(end)");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check inventory of one script only");
   yUNIT_minval  ("... run unit test"                  , system ("./apate_unit --scrps 03"), 0);
   yUNIT_minval  ("... check line count"               , yURG_peek_count (x_urun) , 7);
   yUNIT_mindnoc ();

   yUNIT_mincond ("check urun output");
   yUNIT_minstr  ("... check unit header"              , yURG_peek (x_urun, '∫'), "yUNIT - heatherly unit testing framework ---------------------------------------(beg)");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check script"                   , yURG_peek (x_urun, '÷'), "SCRP [03] (SCRP) verify normal processing ===============================[¡Ï]=[00074]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check unit footer"              , yURG_peek (x_urun, '÷'), "TINU  scrp=1    cond=11    test=40    [ ------------------------------------------- ]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check unit footer"              , yURG_peek (x_urun, '÷'), "yUNIT - heatherly unit testing framework ---------------------------------------(end)");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check running and showing script-level only only");
   yUNIT_minval  ("... run unit test"                  , system ("./apate_unit --scrp"), 999);
   yUNIT_minval  ("... check line count"               , yURG_peek_count (x_urun) , 21);
   yUNIT_mindnoc ();

   yUNIT_mincond ("check urun output");
   yUNIT_minstr  ("... check unit header"              , yURG_peek (x_urun, '∫'), "yUNIT - heatherly unit testing framework ---------------------------------------(beg)");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check section"                  , yURG_peek (x_urun, '÷'), "SECT ===-------------------------- simple testing ---------------------------=== TCES");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check script"                   , yURG_peek (x_urun, '÷'), "SCRP [01] (SCRP) verify openning and closing ============================[¿Í]=[00006]");
   yUNIT_minstr  ("... check script footer"            , yURG_peek (x_urun, '÷'), "  " BACK_RED "PRCS -------- cond=6     test=22    [ pass=15    fail=1     badd=0     void=6     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check section"                  , yURG_peek (x_urun, '÷'), "SECT ===----------------------- more complex testing ------------------------=== TCES");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check script"                   , yURG_peek (x_urun, '÷'), "SCRP [02] (SCRP) verify system startup ==================================[¿Î]=[00050]");
   yUNIT_minstr  ("... check script footer"            , yURG_peek (x_urun, '÷'), "  " BACK_RED "PRCS -------- cond=4     test=28    [ pass=16    fail=5     badd=0     void=7     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check script"                   , yURG_peek (x_urun, '÷'), "SCRP [03] (SCRP) verify normal processing ===============================[¡Ï]=[00074]");
   yUNIT_minstr  ("... check script footer"            , yURG_peek (x_urun, '÷'), "  " BACK_RED "PRCS -------- cond=11    test=40    [ pass=30    fail=8     badd=0     void=2     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check script"                   , yURG_peek (x_urun, '÷'), "SCRP [04] (SCRP) empty script ===========================================[¬Ú]=[00094]");
   yUNIT_minstr  ("... check script footer"            , yURG_peek (x_urun, '÷'), "  " BACK_YEL "PRCS -------- cond=0     test=0     [ pass=0     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check unit footer"              , yURG_peek (x_urun, '÷'), BACK_RED "TINU  scrp=4    cond=21    test=90    [ pass=61    fail=14    badd=0     void=15    ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check unit footer"              , yURG_peek (x_urun, '÷'), "yUNIT - heatherly unit testing framework ---------------------------------------(end)");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check running single script and showing script-level only only");
   yUNIT_minval  ("... run unit test"                  , system ("./apate_unit --scrp 02"), 999);
   yUNIT_minval  ("... check line count"               , yURG_peek_count (x_urun) , 8);
   yUNIT_mindnoc ();

   yUNIT_mincond ("check urun output");
   yUNIT_minstr  ("... check unit header"              , yURG_peek (x_urun, '∫'), "yUNIT - heatherly unit testing framework ---------------------------------------(beg)");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check script"                   , yURG_peek (x_urun, '÷'), "SCRP [02] (SCRP) verify system startup ==================================[¿Î]=[00050]");
   yUNIT_minstr  ("... check script footer"            , yURG_peek (x_urun, '÷'), "  " BACK_RED "PRCS -------- cond=4     test=28    [ pass=16    fail=5     badd=0     void=7     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check unit footer"              , yURG_peek (x_urun, '÷'), BACK_RED "TINU  scrp=1    cond=4     test=28    [ pass=16    fail=5     badd=0     void=7     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check unit footer"              , yURG_peek (x_urun, '÷'), "yUNIT - heatherly unit testing framework ---------------------------------------(end)");
   yUNIT_mindnoc ();

   PROG__unit_end    ();
   rm_working_files ();
   yUNIT_minprcs ();
   return 0;
}

char
koios__unit_live_cond    (char a_list)
{
   int         c           =    0;
   char        x_urun      [LEN_HUND]  = "apate.urun";

   yUNIT_minscrp ("live COND level testing on unit test result");
   if (a_list == 'y')  return 0;
   yURG_err_none ();  /* not to stderr/terminal */
   rm_working_files ();
   PROG__unit_quiet  ();

   koios__unit_shared_data ('y');

   /*> system ("cp apate.unit  apate_back.unit");                                     <*/
   /*> system ("cp master.unit master_back.unit");                                    <*/

   yUNIT_mincond ("check inventory of conditions");
   yUNIT_minval  ("... run unit test"                  , system ("./apate_unit --conds"), 0);
   yUNIT_minval  ("... check line count"               , yURG_peek_count (x_urun) , 87);
   yUNIT_mindnoc ();

   yUNIT_mincond ("check header");
   yUNIT_minstr  ("... check unit header"              , yURG_peek (x_urun, '∫'), "yUNIT - heatherly unit testing framework --------------------------- - actu once ndit");
   yUNIT_minstr  ("... ... patron"                     , yURG_peek (x_urun, '÷'), "   patron : daktyloi-aeonius (forefinger) automated unit testing     s ∑∑∑4 ∑∑∑4 ∑∑∑4");
   yUNIT_minstr  ("... ... level"                      , yURG_peek (x_urun, '÷'), "   assign output level to (3) YUNIT_COND                             c ∑∑21 ∑∑17 ∑∑12");
   yUNIT_minstr  ("... ... eterm"                      , yURG_peek (x_urun, '÷'), "   assign format/color to (y) ETERM                                  x ∑∑90 ∑∑78 ∑∑58");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check section");
   yUNIT_minstr  ("... check section"                  , yURG_peek (x_urun, '÷'), "=========================------------------------------------========================");
   yUNIT_minstr  ("... check section"                  , yURG_peek (x_urun, '÷'), "SECT ===-------------------------- simple testing ---------------------------=== TCES");
   yUNIT_minstr  ("... check section"                  , yURG_peek (x_urun, '÷'), "=========================------------------------------------========================");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check script one");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check script"                   , yURG_peek (x_urun, '÷'), "SCRP [01] (SCRP) verify openning and closing ============================[¿Í]=[00006]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '÷'), "  COND [001] simple openning -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00007]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '÷'), "  " BACK_CYN "CCND [002] (1)" BACK_OFF " defensive checks - -- -- -- -- -- -- -- -- -- -- -- -- -- -- [00012]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '÷'), "  " BACK_CYN "DOND [003] (1) [ defensive checks ]  -- -- -- -- -- -- -- -- -- -- -- -- -- [00017]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '÷'), "  COND [004] small condition -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00018]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '÷'), "  " BACK_CYN "DOND [005] (1) [ defensive checks ]  -- -- -- -- -- -- -- -- -- -- -- -- -- [00020]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '÷'), "  COND [006] duplicate opens and closes  -- -- -- -- -- -- -- -- -- -- -- -- -[00021]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check script footer"            , yURG_peek (x_urun, '÷'), "  PRCS -------- cond=6     test=22    [ ------------------------------------------- ]");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check section");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check section"                  , yURG_peek (x_urun, '÷'), "=========================------------------------------------========================");
   yUNIT_minstr  ("... check section"                  , yURG_peek (x_urun, '÷'), "SECT ===----------------------- more complex testing ------------------------=== TCES");
   yUNIT_minstr  ("... check section"                  , yURG_peek (x_urun, '÷'), "=========================------------------------------------========================");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check script two");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check script"                   , yURG_peek (x_urun, '÷'), "SCRP [02] (SCRP) verify system startup ==================================[¿Î]=[00050]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '÷'), "  COND [001] run initialization -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00051]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '÷'), "  " BACK_MAG "SOND [002]" BACK_OFF " script input file  -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00029]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '÷'), "  " BACK_MAG "SOND [003]" BACK_OFF " code output file - -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00034]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '÷'), "  COND [004] parse a code record - -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00057]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check script footer"            , yURG_peek (x_urun, '÷'), "  PRCS -------- cond=4     test=28    [ ------------------------------------------- ]");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check script three");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check script"                   , yURG_peek (x_urun, '÷'), "SCRP [03] (SCRP) verify normal processing ===============================[¡Ï]=[00074]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check group"                    , yURG_peek (x_urun, '÷'), "  GROUP ===----------------------------   round one   ----------------------------===");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '÷'), "  " BACK_CYN "CCND [001] (1)" BACK_OFF " process arguments  -- -- -- -- -- -- -- -- -- -- -- -- -- -- [00076]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '÷'), "  " BACK_MAG "SOND [002]" BACK_OFF " script input file  -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00029]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '÷'), "  " BACK_MAG "SOND [003]" BACK_OFF " code output file - -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00034]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '÷'), "  " BACK_CYN "CCND [004] (2)" BACK_OFF " read one record -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- [00082]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check group"                    , yURG_peek (x_urun, '÷'), "  GROUP ===----------------------------   round two   ----------------------------===");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '÷'), "  " BACK_CYN "DOND [005] (1) [ process arguments ] -- -- -- -- -- -- -- -- -- -- -- -- -- [00088]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '÷'), "  " BACK_MAG "SOND [006]" BACK_OFF " code output file - -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00040]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '÷'), "  " BACK_MAG "SOND [007]" BACK_OFF " close and delete code file  -- -- -- -- -- -- -- -- -- -- -- -- -[00045]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check group"                    , yURG_peek (x_urun, '÷'), "  GROUP ===---------------------------   final round   ---------------------------===");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '÷'), "  " BACK_CYN "DOND [008] (2) [ read one record ] - -- -- -- -- -- -- -- -- -- -- -- -- -- [00091]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check (70) global cond"         , yURG_peek (x_urun, '÷'), "  " BACK_BLU "GOND [009]" BACK_OFF " prepare variables  -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00007]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check (72) global cond"         , yURG_peek (x_urun, '÷'), "  " BACK_BLU "GOND [010]" BACK_OFF " generate a summary -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00009]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '÷'), "  " BACK_CYN "DOND [011] (1) [ process arguments ] -- -- -- -- -- -- -- -- -- -- -- -- -- [00093]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check script footer"            , yURG_peek (x_urun, '÷'), "  PRCS -------- cond=11    test=40    [ ------------------------------------------- ]");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check script four");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check script"                   , yURG_peek (x_urun, '÷'), "SCRP [04] (SCRP) empty script ===========================================[¬Ú]=[00094]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check script footer"            , yURG_peek (x_urun, '÷'), "  PRCS -------- cond=0     test=0     [ ------------------------------------------- ]");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check footer");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check unit footer"              , yURG_peek (x_urun, '÷'), "TINU  scrp=4    cond=21    test=90    [ ------------------------------------------- ]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check unit footer"              , yURG_peek (x_urun, '÷'), "yUNIT - heatherly unit testing framework ---------------------------------------(end)");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check inventory of conditions for single script");
   yUNIT_minval  ("... run unit test"                  , system ("./apate_unit --conds 02"), 0);
   yUNIT_minval  ("... check line count"               , yURG_peek_count (x_urun) , 22);
   yUNIT_mindnoc ();

   yUNIT_mincond ("check urun output");
   yUNIT_minstr  ("... check unit header"              , yURG_peek (x_urun, '∫'), "yUNIT - heatherly unit testing framework --------------------------- - actu once ndit");
   yUNIT_minstr  ("... ... patron"                     , yURG_peek (x_urun, '÷'), "   patron : daktyloi-aeonius (forefinger) automated unit testing     s ∑∑∑1 ∑∑∑4 ∑∑∑4");
   yUNIT_minstr  ("... ... level"                      , yURG_peek (x_urun, '÷'), "   assign output level to (3) YUNIT_COND                             c ∑∑∑4 ∑∑17 ∑∑12");
   yUNIT_minstr  ("... ... eterm"                      , yURG_peek (x_urun, '÷'), "   assign format/color to (y) ETERM                                  x ∑∑28 ∑∑78 ∑∑58");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check script"                   , yURG_peek (x_urun, '÷'), "SCRP [02] (SCRP) verify system startup ==================================[¿Î]=[00050]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '÷'), "  COND [001] run initialization -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00051]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '÷'), "  " BACK_MAG "SOND [002]" BACK_OFF " script input file  -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00029]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '÷'), "  " BACK_MAG "SOND [003]" BACK_OFF " code output file - -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00034]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '÷'), "  COND [004] parse a code record - -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00057]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check script footer"            , yURG_peek (x_urun, '÷'), "  PRCS -------- cond=4     test=28    [ ------------------------------------------- ]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check unit footer"              , yURG_peek (x_urun, '÷'), "TINU  scrp=1    cond=4     test=28    [ ------------------------------------------- ]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check unit footer"              , yURG_peek (x_urun, '÷'), "yUNIT - heatherly unit testing framework ---------------------------------------(end)");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check executing and presenting only conditions");
   yUNIT_minval  ("... run unit test"                  , system ("./apate_unit --cond"), 999);
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify header");
   yUNIT_minstr  ("... check unit header"              , yURG_peek (x_urun, '∫'), "yUNIT - heatherly unit testing framework --------------------------- - actu once ndit");
   yUNIT_minstr  ("... ... patron"                     , yURG_peek (x_urun, '÷'), "   patron : daktyloi-aeonius (forefinger) automated unit testing     s ∑∑∑4 ∑∑∑4 ∑∑∑4");
   yUNIT_minstr  ("... ... level"                      , yURG_peek (x_urun, '÷'), "   assign output level to (3) YUNIT_COND                             c ∑∑21 ∑∑17 ∑∑12");
   yUNIT_minstr  ("... ... eterm"                      , yURG_peek (x_urun, '÷'), "   assign format/color to (y) ETERM                                  x ∑∑90 ∑∑78 ∑∑58");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check section"                  , yURG_peek (x_urun, '÷'), "=========================------------------------------------========================");
   yUNIT_minstr  ("... check section"                  , yURG_peek (x_urun, '÷'), "SECT ===-------------------------- simple testing ---------------------------=== TCES");
   yUNIT_minstr  ("... check section"                  , yURG_peek (x_urun, '÷'), "=========================------------------------------------========================");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify first script");
   yUNIT_minstr  ("... check script"                   , yURG_peek (x_urun, '÷'), "SCRP [01] (SCRP) verify openning and closing ============================[¿Í]=[00006]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '÷'), "  COND [001] simple openning -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00007]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, '÷'), "      " BACK_GRN "DNOC --------------- test=4     [ pass=4     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '÷'), "  " BACK_CYN "CCND [002] (1)" BACK_OFF " defensive checks - -- -- -- -- -- -- -- -- -- -- -- -- -- -- [00012]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, '÷'), "      " BACK_GRN "DNOC --------------- test=4     [ pass=3     fail=0     badd=0     void=1     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '÷'), "  " BACK_CYN "DOND [003] (1) [ defensive checks ]  -- -- -- -- -- -- -- -- -- -- -- -- -- [00017]" BACK_OFF);
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, '÷'), "      " BACK_GRN "DNOC --------------- test=4     [ pass=3     fail=0     badd=0     void=1     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '÷'), "  COND [004] small condition -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00018]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, '÷'), "      " BACK_GRN "DNOC --------------- test=1     [ pass=1     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '÷'), "  " BACK_CYN "DOND [005] (1) [ defensive checks ]  -- -- -- -- -- -- -- -- -- -- -- -- -- [00020]" BACK_OFF);
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, '÷'), "      " BACK_GRN "DNOC --------------- test=4     [ pass=3     fail=0     badd=0     void=1     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '÷'), "  COND [006] duplicate opens and closes  -- -- -- -- -- -- -- -- -- -- -- -- -[00021]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, '÷'), "      " BACK_RED "DNOC --------------- test=5     [ pass=1     fail=1     badd=0     void=3     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check script footer"            , yURG_peek (x_urun, '÷'), "  " BACK_RED "PRCS -------- cond=6     test=22    [ pass=15    fail=1     badd=0     void=6     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check section"                  , yURG_peek (x_urun, '÷'), "=========================------------------------------------========================");
   yUNIT_minstr  ("... check section"                  , yURG_peek (x_urun, '÷'), "SECT ===----------------------- more complex testing ------------------------=== TCES");
   yUNIT_minstr  ("... check section"                  , yURG_peek (x_urun, '÷'), "=========================------------------------------------========================");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify second script");
   yUNIT_minstr  ("... check script"                   , yURG_peek (x_urun, '÷'), "SCRP [02] (SCRP) verify system startup ==================================[¿Î]=[00050]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '÷'), "  COND [001] run initialization -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00051]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, '÷'), "      " BACK_RED "DNOC --------------- test=4     [ pass=1     fail=2     badd=0     void=1     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '÷'), "  " BACK_MAG "SOND [002]" BACK_OFF " script input file  -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00029]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, '÷'), "      " BACK_RED "DNOC --------------- test=4     [ pass=0     fail=3     badd=0     void=1     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '÷'), "  " BACK_MAG "SOND [003]" BACK_OFF " code output file - -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00034]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, '÷'), "      " BACK_GRN "DNOC --------------- test=4     [ pass=4     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '÷'), "  COND [004] parse a code record - -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00057]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, '÷'), "      " BACK_GRN "DNOC --------------- test=16    [ pass=11    fail=0     badd=0     void=5     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check script footer"            , yURG_peek (x_urun, '÷'), "  " BACK_RED "PRCS -------- cond=4     test=28    [ pass=16    fail=5     badd=0     void=7     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify third script");
   yUNIT_minstr  ("... check script"                   , yURG_peek (x_urun, '÷'), "SCRP [03] (SCRP) verify normal processing ===============================[¡Ï]=[00074]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check group"                    , yURG_peek (x_urun, '÷'), "  GROUP ===----------------------------   round one   ----------------------------===");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '÷'), "  " BACK_CYN "CCND [001] (1)" BACK_OFF " process arguments  -- -- -- -- -- -- -- -- -- -- -- -- -- -- [00076]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, '÷'), "      " BACK_GRN "DNOC --------------- test=4     [ pass=4     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '÷'), "  " BACK_MAG "SOND [002]" BACK_OFF " script input file  -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00029]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, '÷'), "      " BACK_GRN "DNOC --------------- test=4     [ pass=3     fail=0     badd=0     void=1     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '÷'), "  " BACK_MAG "SOND [003]" BACK_OFF " code output file - -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00034]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, '÷'), "      " BACK_GRN "DNOC --------------- test=4     [ pass=4     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '÷'), "  " BACK_CYN "CCND [004] (2)" BACK_OFF " read one record -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- [00082]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, '÷'), "      " BACK_RED "DNOC --------------- test=4     [ pass=0     fail=4     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check group"                    , yURG_peek (x_urun, '÷'), "  GROUP ===----------------------------   round two   ----------------------------===");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '÷'), "  " BACK_CYN "DOND [005] (1) [ process arguments ] -- -- -- -- -- -- -- -- -- -- -- -- -- [00088]" BACK_OFF);
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, '÷'), "      " BACK_GRN "DNOC --------------- test=4     [ pass=4     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '÷'), "  " BACK_MAG "SOND [006]" BACK_OFF " code output file - -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00040]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, '÷'), "      " BACK_GRN "DNOC --------------- test=4     [ pass=4     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '÷'), "  " BACK_MAG "SOND [007]" BACK_OFF " close and delete code file  -- -- -- -- -- -- -- -- -- -- -- -- -[00045]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, '÷'), "      " BACK_GRN "DNOC --------------- test=4     [ pass=4     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check group"                    , yURG_peek (x_urun, '÷'), "  GROUP ===---------------------------   final round   ---------------------------===");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '÷'), "  " BACK_CYN "DOND [008] (2) [ read one record ] - -- -- -- -- -- -- -- -- -- -- -- -- -- [00091]" BACK_OFF);
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, '÷'), "      " BACK_RED "DNOC --------------- test=4     [ pass=0     fail=4     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check global condition"         , yURG_peek (x_urun, '÷'), "  " BACK_BLU "GOND [009]" BACK_OFF " prepare variables  -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00007]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, '÷'), "      " BACK_GRN "DNOC --------------- test=1     [ pass=0     fail=0     badd=0     void=1     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check global condition"         , yURG_peek (x_urun, '÷'), "  " BACK_BLU "GOND [010]" BACK_OFF " generate a summary -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00009]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, '÷'), "      " BACK_GRN "DNOC --------------- test=3     [ pass=3     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '÷'), "  " BACK_CYN "DOND [011] (1) [ process arguments ] -- -- -- -- -- -- -- -- -- -- -- -- -- [00093]" BACK_OFF);
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, '÷'), "      " BACK_GRN "DNOC --------------- test=4     [ pass=4     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check script footer"            , yURG_peek (x_urun, '÷'), "  " BACK_RED "PRCS -------- cond=11    test=40    [ pass=30    fail=8     badd=0     void=2     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify fourth script and footer");
   yUNIT_minstr  ("... check script"                   , yURG_peek (x_urun, '÷'), "SCRP [04] (SCRP) empty script ===========================================[¬Ú]=[00094]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check script footer"            , yURG_peek (x_urun, '÷'), "  " BACK_YEL "PRCS -------- cond=0     test=0     [ pass=0     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check unit footer"              , yURG_peek (x_urun, '÷'), BACK_RED "TINU  scrp=4    cond=21    test=90    [ pass=61    fail=14    badd=0     void=15    ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check unit footer"              , yURG_peek (x_urun, '÷'), "yUNIT - heatherly unit testing framework ---------------------------------------(end)");
   yUNIT_minval  ("... check line count"               , yURG_peek_count (x_urun) , 108);
   yUNIT_mindnoc ();

   yUNIT_mincond ("check executing and presenting but show only one script");
   yUNIT_minval  ("... run unit test"                  , system ("./apate_unit --cond 03"), 999);
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify header");
   yUNIT_minstr  ("... check unit header"              , yURG_peek (x_urun, '∫'), "yUNIT - heatherly unit testing framework --------------------------- - actu once ndit");
   yUNIT_minstr  ("... ... patron"                     , yURG_peek (x_urun, '÷'), "   patron : daktyloi-aeonius (forefinger) automated unit testing     s ∑∑∑1 ∑∑∑4 ∑∑∑4");
   yUNIT_minstr  ("... ... level"                      , yURG_peek (x_urun, '÷'), "   assign output level to (3) YUNIT_COND                             c ∑∑11 ∑∑17 ∑∑12");
   yUNIT_minstr  ("... ... eterm"                      , yURG_peek (x_urun, '÷'), "   assign format/color to (y) ETERM                                  x ∑∑40 ∑∑78 ∑∑58");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify third script");
   yUNIT_minstr  ("... check script"                   , yURG_peek (x_urun, '÷'), "SCRP [03] (SCRP) verify normal processing ===============================[¡Ï]=[00074]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check group"                    , yURG_peek (x_urun, '÷'), "  GROUP ===----------------------------   round one   ----------------------------===");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '÷'), "  " BACK_CYN "CCND [001] (1)" BACK_OFF " process arguments  -- -- -- -- -- -- -- -- -- -- -- -- -- -- [00076]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, '÷'), "      " BACK_GRN "DNOC --------------- test=4     [ pass=4     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '÷'), "  " BACK_MAG "SOND [002]" BACK_OFF " script input file  -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00029]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, '÷'), "      " BACK_GRN "DNOC --------------- test=4     [ pass=3     fail=0     badd=0     void=1     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '÷'), "  " BACK_MAG "SOND [003]" BACK_OFF " code output file - -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00034]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, '÷'), "      " BACK_GRN "DNOC --------------- test=4     [ pass=4     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '÷'), "  " BACK_CYN "CCND [004] (2)" BACK_OFF " read one record -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- [00082]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, '÷'), "      " BACK_RED "DNOC --------------- test=4     [ pass=0     fail=4     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check group"                    , yURG_peek (x_urun, '÷'), "  GROUP ===----------------------------   round two   ----------------------------===");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '÷'), "  " BACK_CYN "DOND [005] (1) [ process arguments ] -- -- -- -- -- -- -- -- -- -- -- -- -- [00088]" BACK_OFF);
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, '÷'), "      " BACK_GRN "DNOC --------------- test=4     [ pass=4     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '÷'), "  " BACK_MAG "SOND [006]" BACK_OFF " code output file - -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00040]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, '÷'), "      " BACK_GRN "DNOC --------------- test=4     [ pass=4     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '÷'), "  " BACK_MAG "SOND [007]" BACK_OFF " close and delete code file  -- -- -- -- -- -- -- -- -- -- -- -- -[00045]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, '÷'), "      " BACK_GRN "DNOC --------------- test=4     [ pass=4     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check group"                    , yURG_peek (x_urun, '÷'), "  GROUP ===---------------------------   final round   ---------------------------===");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '÷'), "  " BACK_CYN "DOND [008] (2) [ read one record ] - -- -- -- -- -- -- -- -- -- -- -- -- -- [00091]" BACK_OFF);
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, '÷'), "      " BACK_RED "DNOC --------------- test=4     [ pass=0     fail=4     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check global condition"         , yURG_peek (x_urun, '÷'), "  " BACK_BLU "GOND [009]" BACK_OFF " prepare variables  -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00007]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, '÷'), "      " BACK_GRN "DNOC --------------- test=1     [ pass=0     fail=0     badd=0     void=1     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check global condition"         , yURG_peek (x_urun, '÷'), "  " BACK_BLU "GOND [010]" BACK_OFF " generate a summary -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00009]");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, '÷'), "      " BACK_GRN "DNOC --------------- test=3     [ pass=3     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '÷'), "  " BACK_CYN "DOND [011] (1) [ process arguments ] -- -- -- -- -- -- -- -- -- -- -- -- -- [00093]" BACK_OFF);
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, '÷'), "      " BACK_GRN "DNOC --------------- test=4     [ pass=4     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check script footer"            , yURG_peek (x_urun, '÷'), "  " BACK_RED "PRCS -------- cond=11    test=40    [ pass=30    fail=8     badd=0     void=2     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify fourth script and footer");
   yUNIT_minstr  ("... check unit footer"              , yURG_peek (x_urun, '÷'), BACK_RED "TINU  scrp=1    cond=11    test=40    [ pass=30    fail=8     badd=0     void=2     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check unit footer"              , yURG_peek (x_urun, '÷'), "yUNIT - heatherly unit testing framework ---------------------------------------(end)");
   yUNIT_minval  ("... check line count"               , yURG_peek_count (x_urun) , 53);
   yUNIT_mindnoc ();

   PROG__unit_end    ();
   rm_working_files ();
   yUNIT_minprcs ();
   return 0;
}

char
koios__unit_live_step    (char a_list)
{
   int         c           =    0;
   char        x_urun      [LEN_HUND]  = "apate.urun";

   yUNIT_minscrp ("live STEP level testing on unit test result");
   if (a_list == 'y')  return 0;
   yURG_err_none ();  /* not to stderr/terminal */
   rm_working_files ();
   PROG__unit_quiet  ();

   koios__unit_shared_data ('y');

   yUNIT_mincond ("check displaying steps");
   yUNIT_minval  ("... run unit test"                  , system ("./apate_unit --steps"), 0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("check step level header");
   yUNIT_minstr  ("... check unit header"              , yURG_peek (x_urun, '∫'), "yUNIT - heatherly unit testing framework --------------------------- - actu once ndit");
   yUNIT_minstr  ("... ... patron"                     , yURG_peek (x_urun, '÷'), "   patron : daktyloi-aeonius (forefinger) automated unit testing     s ∑∑∑4 ∑∑∑4 ∑∑∑4");
   yUNIT_minstr  ("... ... level"                      , yURG_peek (x_urun, '÷'), "   assign output level to (4) YUNIT_STEP                             c ∑∑21 ∑∑17 ∑∑12");
   yUNIT_minstr  ("... ... eterm"                      , yURG_peek (x_urun, '÷'), "   assign format/color to (y) ETERM                                  x ∑∑90 ∑∑78 ∑∑58");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check step level section format");
   yUNIT_minstr  ("... check section"                  , yURG_peek (x_urun, '÷'), "=========================------------------------------------========================");
   yUNIT_minstr  ("... check section"                  , yURG_peek (x_urun, '÷'), "SECT ===-------------------------- simple testing ---------------------------=== TCES");
   yUNIT_minstr  ("... check section"                  , yURG_peek (x_urun, '÷'), "=========================------------------------------------========================");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check step level script format");
   yUNIT_minstr  ("... check (11) separator"           , yURG_peek (x_urun, '÷'), "===[[ NEW SCRIPT ]]==================================================================");
   yUNIT_minstr  ("... check script"                   , yURG_peek (x_urun, '÷'), "SCRP [01] (SCRP) verify openning and closing ============================[¿Í]=[00006]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check step level condition and normal steps");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '÷'), "  COND [001] simple openning -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00007]");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, '÷'), "     aa) str   : check string ∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑[00008]");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, '÷'), "     ab) real  : check number ∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑[00009]");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, '÷'), "     ac) int   : check integer  ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑[00010]");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, '÷'), "     ad) int   : check character ∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑[00011]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '÷'), "  " BACK_CYN "CCND [002] (1)" BACK_OFF " defensive checks - -- -- -- -- -- -- -- -- -- -- -- -- -- -- [00012]");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check alternative step level entries");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun,  41), "  COND [006] duplicate opens and closes  -- -- -- -- -- -- -- -- -- -- -- -- -[00021]");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, '÷'), "     aa) LOCAL : working variables ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑[00022]");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, '÷'), "     ab) int   : check working variable  ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑[00023]");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, '÷'), "     ac) LOAD  : prep data for read ∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑[00024]");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, '÷'), "     ad) MODE  : FORCED_FAIL ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑[00025]");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, '÷'), "     ae) SYS   : run little  ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑[00026]");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check inclusion of shared");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun,  64), "");
   yUNIT_minstr  ("... check shared header"            , yURG_peek (x_urun, '÷'), "  " BACK_MAG "SHARE (a) ===--------------------   prepare files for use   --------------------===" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '÷'), "  " BACK_MAG "SOND [002]" BACK_OFF " script input file  -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00029]");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, '÷'), "     aa) str   : check string ∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑[00030]");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, '÷'), "     ab) real  : check number ∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑[00031]");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, '÷'), "     ac) int   : check integer  ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑[00032]");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, '÷'), "     ad) MODE  : normal ∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑[00033]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '÷'), "  " BACK_MAG "SOND [003]" BACK_OFF " code output file - -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00034]");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, '÷'), "     aa) str   : check string ∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑[00035]");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, '÷'), "     ab) real  : check number ∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑[00036]");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, '÷'), "     ac) int   : check integer  ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑[00037]");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, '÷'), "     ad) int   : check character ∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑[00038]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check shared footer"            , yURG_peek (x_urun, '÷'), "  " BACK_MAG "ERAHS (a) ===--------------------   prepare files for use   --------------------===" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minval  ("... check line count"               , yURG_peek_count (x_urun) , 197);
   yUNIT_mindnoc ();

   yUNIT_mincond ("check inclusion of global");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, 166), "");
   yUNIT_minstr  ("... check global header"            , yURG_peek (x_urun, '÷'), "  " BACK_BLU "GLOBAL (D) ===-------------------   globally shared steps   --------------------===" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '÷'), "  " BACK_BLU "GOND [009]" BACK_OFF " prepare variables  -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00007]");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, '÷'), "     aa) CODE  : set new value  ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑[00008]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '÷'), "  " BACK_BLU "GOND [010]" BACK_OFF " generate a summary -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00009]");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, '÷'), "     aa) str   : check string ∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑[00010]");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, '÷'), "     ab) real  : check number ∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑[00011]");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, '÷'), "     ac) int   : check integer  ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑[00012]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check global footer"            , yURG_peek (x_urun, '÷'), "  " BACK_BLU "LABOLG (D) ===-------------------   globally shared steps   --------------------===" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minval  ("... check line count"               , yURG_peek_count (x_urun) , 197);
   yUNIT_mindnoc ();

   yUNIT_mincond ("check executing and presenting down to steps");
   yUNIT_minval  ("... run unit test"                  , system ("./apate_unit --step"), 999);
   yUNIT_mindnoc ();

   yUNIT_mincond ("check step level condition and normal steps");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun,  14), "  COND [001] simple openning -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00007]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, '÷'), "  " BACK_GRN "aa) PASS  " BACK_OFF " : check string ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑[00008]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, '÷'), "  " BACK_GRN "ab) PASS  " BACK_OFF " : check number ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑[00009]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, '÷'), "  " BACK_GRN "ac) PASS  " BACK_OFF " : check integer ∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑[00010]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, '÷'), "  " BACK_GRN "ad) PASS  " BACK_OFF " : check character ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑[00011]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, '÷'), "      " BACK_GRN "DNOC --------------- test=4     [ pass=4     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun, '÷'), "  " BACK_CYN "CCND [002] (1)" BACK_OFF " defensive checks - -- -- -- -- -- -- -- -- -- -- -- -- -- -- [00012]");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check alternative step level entries");
   yUNIT_minstr  ("... check condition header"         , yURG_peek (x_urun,  68), "  COND [006] duplicate opens and closes  -- -- -- -- -- -- -- -- -- -- -- -- -[00021]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, '÷'), "  " BACK_CYN "aa) " BACK_GRN "LOCAL " BACK_OFF " : working variables  ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑[00022]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, '÷'), "  " BACK_GRN "ab) PASS  " BACK_OFF " : check working variable ∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑[00023]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, '÷'), "  " BACK_CYN "ac) " BACK_GRN "LOAD  " BACK_OFF " : prep data for read ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑[00024]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, '÷'), "  " BACK_CYN "ad) " BACK_GRN "MODE  " BACK_OFF " : ENABLE FORCED FAILURE (pass=fail, fail=pass)  ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑[00025]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, '÷'), "  " BACK_CYN "ae) " BACK_RED "!SYS  " BACK_OFF " : run little ∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑[00026]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, '÷'), "      " BACK_RED "DNOC --------------- test=5     [ pass=1     fail=1     badd=0     void=3     ]" BACK_OFF);
   yUNIT_mindnoc ();

   PROG__unit_end    ();
   rm_working_files ();
   yUNIT_minprcs ();
   return 0;
}

char
koios__unit_live_full    (char a_list)
{
   int         c           =    0;
   char        x_urun      [LEN_HUND]  = "apate.urun";

   yUNIT_minscrp ("live FULL testing on unit test result");
   if (a_list == 'y')  return 0;
   yURG_err_none ();  /* not to stderr/terminal */
   rm_working_files ();
   PROG__unit_quiet  ();

   koios__unit_shared_data ('y');

   yUNIT_mincond ("check executing and presenting full");
   yUNIT_minval  ("... run unit test"                  , system ("./apate_unit"), 999);
   yUNIT_mindnoc ();

   /*> system ("cp -fv apate.unit apate_back.unit");                                  <*/
   /*> system ("cp -fv apate.urun apate_back.urun");                                  <*/

   yUNIT_mincond ("check passing string step");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun,  16), "  " BACK_GRN "aa) PASS  " BACK_OFF " : check string ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑[00008]");
   yUNIT_minstr  ("... ... method"                     , yURG_peek (x_urun, '÷'), "      method : yUNIT_teststring (0)");
   yUNIT_minstr  ("... ... test"                       , yURG_peek (x_urun, '÷'), "      test   : s_equal    (rc =  101, test abbr = e)");
   yUNIT_minstr  ("... ... expect"                     , yURG_peek (x_urun, '÷'), "      expect :  5[hello]");
   yUNIT_minstr  ("... ... actual"                     , yURG_peek (x_urun, '÷'), "      actual :  5[hello]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check failing string step (nearly same)");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, 418), "  " BACK_RED "aa) FAIL  " BACK_OFF " : check string ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑[00083]");
   yUNIT_minstr  ("... ... method"                     , yURG_peek (x_urun, '÷'), "      method : yUNIT_teststring (1)");
   yUNIT_minstr  ("... ... test"                       , yURG_peek (x_urun, '÷'), "      test   : s_equal    (rc = -101, test abbr = e)");
   yUNIT_minstr  ("... ... expect"                     , yURG_peek (x_urun, '÷'), "      expect :  7[" BOLD_RED "hello££" BOLD_OFF "]");
   yUNIT_minstr  ("... ... actual"                     , yURG_peek (x_urun, '÷'), "      actual :  7[" BOLD_RED "goodbye" BOLD_OFF "]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check forced fail string step (same)");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, 187), "  " BACK_GRN "aa) " BACK_RED "!FAIL " BACK_OFF " : check string ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑[00030]");
   yUNIT_minstr  ("... ... method"                     , yURG_peek (x_urun, '÷'), "      method : yUNIT_teststring (0)");
   yUNIT_minstr  ("... ... test"                       , yURG_peek (x_urun, '÷'), "      test   : s_equal    (rc =  101, test abbr = e)");
   yUNIT_minstr  ("... ... expect"                     , yURG_peek (x_urun, '÷'), "      expect :  5[hello]");                              
   yUNIT_minstr  ("... ... actual"                     , yURG_peek (x_urun, '÷'), "      actual :  5[hello]");                              
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check passing float step");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun,  22), "  " BACK_GRN "ab) PASS  " BACK_OFF " : check number ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑[00009]");
   yUNIT_minstr  ("... ... method"                     , yURG_peek (x_urun, '÷'), "      method : yUNIT_testreal (5)");
   yUNIT_minstr  ("... ... test"                       , yURG_peek (x_urun, '÷'), "      test   : r_greater  (rc =  103, test abbr = g)");
   yUNIT_minstr  ("... ... expect"                     , yURG_peek (x_urun, '÷'), "      expect :  9[15.000000]");
   yUNIT_minstr  ("... ... actual"                     , yURG_peek (x_urun, '÷'), "      actual :  9[15.707964]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check failing float step");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, 424), "  " BACK_RED "ab) FAIL  " BACK_OFF " : check number ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑[00084]");
   yUNIT_minstr  ("... ... method"                     , yURG_peek (x_urun, '÷'), "      method : yUNIT_testreal (2)");
   yUNIT_minstr  ("... ... test"                       , yURG_peek (x_urun, '÷'), "      test   : r_greater  (rc = -103, test abbr = g)");
   yUNIT_minstr  ("... ... expect"                     , yURG_peek (x_urun, '÷'), "      expect :  9[15.000000]");
   yUNIT_minstr  ("... ... actual"                     , yURG_peek (x_urun, '÷'), "      actual :  8[6.283185]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check passing integer step");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun,  28), "  " BACK_GRN "ac) PASS  " BACK_OFF " : check integer ∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑[00010]");
   yUNIT_minstr  ("... ... method"                     , yURG_peek (x_urun, '÷'), "      method : yUNIT_testint (32)");
   yUNIT_minstr  ("... ... test"                       , yURG_peek (x_urun, '÷'), "      test   : i_equal    (rc =  101, test abbr = e)");
   yUNIT_minstr  ("... ... expect"                     , yURG_peek (x_urun, '÷'), "      expect :  1[2]");
   yUNIT_minstr  ("... ... actual"                     , yURG_peek (x_urun, '÷'), "      actual :  1[2]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check failing integer step");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, 430), "  " BACK_RED "ac) FAIL  " BACK_OFF " : check integer ∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑[00085]");
   yUNIT_minstr  ("... ... method"                     , yURG_peek (x_urun, '÷'), "      method : yUNIT_testint (64)");
   yUNIT_minstr  ("... ... test"                       , yURG_peek (x_urun, '÷'), "      test   : i_equal    (rc = -101, test abbr = e)");
   yUNIT_minstr  ("... ... expect"                     , yURG_peek (x_urun, '÷'), "      expect :  1[2]");
   yUNIT_minstr  ("... ... actual"                     , yURG_peek (x_urun, '÷'), "      actual :  1[4]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check mode step");                                   
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, 141), "  " BACK_CYN "ad) " BACK_GRN "MODE  " BACK_OFF " : ENABLE FORCED FAILURE (pass=fail, fail=pass)  ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑[00025]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check code step");                                   
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, 568), "  " BACK_CYN "aa) " BACK_GRN "CODE  " BACK_OFF " : set new value ∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑[00008]");
   yUNIT_minstr  ("... ... contents"                   , yURG_peek (x_urun, '÷'), "      code   : 12[h = 32 * 64;]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check load step");                                   
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun,  44), "  " BACK_CYN "aa) " BACK_GRN "LOAD  " BACK_OFF " : prep data for read ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑[00013]");
   yUNIT_minstr  ("... ... contents"                   , yURG_peek (x_urun, '÷'), "      stdin  : 13[one two three]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check sys step");                                   
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, 143), "  " BACK_CYN "ae) " BACK_RED "!SYS  " BACK_OFF " : run little ∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑[00026]");
   yUNIT_minstr  ("... ... contents"                   , yURG_peek (x_urun, '÷'), "      system : 10[/bin/false]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check local step");                                   
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, 129), "  " BACK_CYN "aa) " BACK_GRN "LOCAL " BACK_OFF " : working variables  ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑[00022]");
   yUNIT_minstr  ("... ... contents"                   , yURG_peek (x_urun, '÷'), "      local  : 10[int c = 0;]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_mindnoc ();

   PROG__unit_end    ();
   rm_working_files ();
   yUNIT_minprcs ();
   return 0;
}

char
koios__unit_live_stop    (char a_list)
{
   int         c           =    0;
   char        x_unit      [LEN_HUND]  = "apate.unit";
   char        x_conv      [LEN_HUND]  = "apate.unit.unit";

   yUNIT_minscrp ("live testing on unit test result (STOPPING)");
   if (a_list == 'y')  return 0;
   yURG_err_none ();  /* not to stderr/terminal */
   rm_working_files ();
   PROG__unit_quiet  ();

   yUNIT_mincond  ("verify a simple success");
   system ("echo \"SCRP          verify ditto                         0s  tbd        \"                                                                                   >  apate.unit");
   system ("echo \"  COND   (1)  repeat code                         \"                                                                                                       >> apate.unit");
   system ("echo \"    exec      ... check integer                    yUNIT_testint     32                        i_equal     2                     \"                >> apate.unit");
   system ("echo \"    exec      ... check character                  yUNIT_testchar    65                        i_equal     'A'                   \"                >> apate.unit");
   system ("echo \"  DITTO  (1)  - - - - - - - - - - - - - - - - - - \"                                                                                                       >> apate.unit");
   yUNIT_mindnoc  ();

   yUNIT_mincond ("call conversion");
   yUNIT_minval  ("... check unit lines"               , yURG_peek_count (x_unit)  ,   5);
   yUNIT_minval  ("... run koios"                      , system ("koios --Econv apate > /dev/null 2>&1"),   0);
   yUNIT_minval  ("... check result lines"             , yURG_peek_count (x_unit)  ,  18);
   yUNIT_minval  ("... count errors"                   , yURG_peek_count (YURG_ERR),   0);
   yUNIT_mindnoc ();

   yUNIT_mincond  ("attempt with a bad verb");
   system ("echo \"SCRP          verify ditto                         0s  tbd        \"                                                                                   >  apate.unit");
   system ("echo \"  CONDY  (1)  repeat code                         \"                                                                                                       >> apate.unit");
   system ("echo \"    exec      ... check integer                    yUNIT_testint     32                        i_equal     2                     \"                >> apate.unit");
   system ("echo \"    exec      ... check character                  yUNIT_testchar    65                        i_equal     'A'                   \"                >> apate.unit");
   system ("echo \"  DITTO  (1)  - - - - - - - - - - - - - - - - - - \"                                                                                                       >> apate.unit");
   yUNIT_mindnoc  ();

   yUNIT_mincond ("call conversion");
   yUNIT_minval  ("... check unit lines"               , yURG_peek_count (x_unit) ,   5);
   yUNIT_minval  ("... run koios"                      , system ("koios --Econv apate"), 999);
   yUNIT_minval  ("... check unit lines"               , yURG_peek_count (x_unit)  ,   5);
   yUNIT_minval  ("... count errors"                   , yURG_peek_count (YURG_ERR),   2);
   yUNIT_minstr  ("... check error line"               , yURG_peek (YURG_ERR,   0), BOLD_ERR "FATAL, apate.unit:2:0: error: verb ∂CONDY∂ not recognized/found"               BACK_OFF  );
   yUNIT_minstr  ("... check error line"               , yURG_peek (YURG_ERR, '÷'), BOLD_ERR "FATAL, apate.unit:5:1: error: DITTO identifier Â1Ê not set by previous COND"   BACK_OFF  );
   yUNIT_minstr  ("... check error line"               , yURG_peek (YURG_ERR, '÷'), ""                                                    );
   yUNIT_mindnoc ();

   yUNIT_mincond ("call execution");
   yUNIT_minval  ("... run koios"                      , system ("koios --Ecode apate"), 999);
   yUNIT_minval  ("... count errors"                   , yURG_peek_count (YURG_ERR),   2);
   yUNIT_minstr  ("... check error line"               , yURG_peek (YURG_ERR,   0), BOLD_ERR "FATAL, apate.unit:2:0: error: verb ∂CONDY∂ not recognized/found"               BACK_OFF  );
   yUNIT_minstr  ("... check error line"               , yURG_peek (YURG_ERR, '÷'), BOLD_ERR "FATAL, apate.unit:5:1: error: DITTO identifier Â1Ê not set by previous COND"   BACK_OFF  );
   yUNIT_minstr  ("... check error line"               , yURG_peek (YURG_ERR, '÷'), ""                                                    );
   yUNIT_mindnoc ();

   PROG__unit_end    ();
   rm_working_files ();
   yUNIT_minprcs ();
   return 0;
}

char
koios__unit_live_vers    (char a_list)
{
   int         c           =    0;
   char        x_unit      [LEN_HUND]  = "apate.unit";
   char        x_conv      [LEN_HUND]  = "apate.unit.unit";

   yUNIT_minscrp ("live testing with various versions");
   if (a_list == 'y')  return 0;
   yURG_err_none ();  /* not to stderr/terminal */
   rm_working_files ();
   PROG__unit_quiet  ();

   yUNIT_mincond  ("verify a simple success");
   system ("echo \"SCRP          v21  verify ditto                  0s  tbd        \"                                                                                   >  apate.unit");
   system ("echo \"  COND   (1)  v20  repeat code                  \"                                                                                                       >> apate.unit");
   system ("echo \"    exec      ... check integer                    yUNIT_testint     32                        i_equal     2                     \"                >> apate.unit");
   system ("echo \"    exec      ... check character                  yUNIT_testchar    65                        i_equal     'A'                   \"                >> apate.unit");
   system ("echo \"  DITTO  (1)  - - - - - - - - - - - - - - - - - - \"                                                                                                       >> apate.unit");
   yUNIT_mindnoc  ();

   yUNIT_mincond ("call conversion");
   yUNIT_minval  ("... check unit lines"               , yURG_peek_count (x_unit)  ,   5);
   yUNIT_minval  ("... run koios"                      , system ("koios --Econv apate > /dev/null 2>&1"),   0);
   yUNIT_minval  ("... check result lines"             , yURG_peek_count (x_unit)  ,  18);
   yUNIT_minval  ("... count errors"                   , yURG_peek_count (YURG_ERR),   0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify header");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit,   0), "#!/usr/local/bin/koios");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "#   koios-polos (axis of heaven) unit testing meta-language");
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify script with dittoing");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-123456789- ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  ========(var)======= ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "SCRP          verify ditto                                                       0s   tbd                                                                                          ((01.---))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "   COND  (1)  repeat code                                                        - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((01.001))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "     exec     ... check integer                    yUNIT_testint               32                                                                                                    i_equal     2                                                                                                    ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "     exec     ... check character                  yUNIT_testchar              65                                                                                                    i_equal     'A'                                                                                                  ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "   DITTO (1)  [ repeat code ]                                                    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((01.002))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify footer");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "# end-of-file.  done, finito, completare, whimper [œ¥∑∑∑");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");

   PROG__unit_end    ();
   rm_working_files ();
   yUNIT_minprcs ();
   return 0;
}

char
koios__unit_live_comment (char a_list)
{
   int         c           =    0;
   char        x_unit      [LEN_HUND]  = "apate.unit";
   char        x_conv      [LEN_HUND]  = "apate.unit.unit";

   yUNIT_minscrp ("live testing with comments");
   if (a_list == 'y')  return 0;
   yURG_err_none ();  /* not to stderr/terminal */
   rm_working_files ();
   PROG__unit_quiet  ();

   yUNIT_mincond  ("unit with variety of comments, and issue");
   system ("echo \"\"                                                                                                                                                                > apate.unit");
   system ("echo \"## this is a comment\"                                                                                                                                           >> apate.unit");
   system ("echo \"\"                                                                                                                                                               >> apate.unit");
   system ("echo \"#> this is a saved comment\"                                                                                                                                     >> apate.unit");
   system ("echo \"#>this needed a space\"                                                                                                                                          >> apate.unit");
   system ("echo \"\"                                                                                                                                                               >> apate.unit");
   system ("echo \"PREP          include the prototype headers                            - - - - - - - - - -   - - - - -   - - - - - - - - - -  >>\"                     >> apate.unit");
   system ("echo \"   #> this is second level comment\"                                                                                                                             >> apate.unit");
   system ("echo \"   incl       include public header                apate.h           - - - - - - - - - -   - - - - -   - - - - - - - - - -  \"                       >> apate.unit");
   system ("echo \"#23456789-12  123456789-123456789-123456789-12345  123456789-123456  123456789-123456789-  123456789-  123456789-123456789-  -  123456789- \"    >> apate.unit");
   system ("echo \"#==(verb)===  ===========(description)===========  =====(function)=  ====(arguments)=====  ==(test)==  ====(results)=======  t  =(var)==== \"    >> apate.unit");
   system ("echo \"SCRP    [¡Ï]  (SCRP  ) verify openning and closin                                           ((01.---))  - - - - - - - - - -  \"                        >> apate.unit");
   system ("echo \"# random comment\"                                                                                                                                               >> apate.unit");
   system ("echo \"\"                                                                                                                                                               >> apate.unit");
   system ("echo \"   COND       parse a code record   - - - - - - - - - - - - -   ((01.001))  - - - - - - - - - \"                                                       >> apate.unit");
   system ("echo \"     #> this is third level comment\"                                                                                                                            >> apate.unit");
   system ("echo \"     load     add a line to stdin    stdin  * * * * *                      : basic line                  : - - - - -  :  /bin/true > /dev/null\"         >> apate.unit");
   system ("echo \"\"                                                                                                                                                               >> apate.unit");
   system ("echo \"# > random comment\"                                                                                                                                               >> apate.unit");
   yUNIT_mindnoc  ();

   yUNIT_mincond ("call conversion");
   yUNIT_minval  ("... check unit lines"               , yURG_peek_count (x_unit)  ,  19);
   yUNIT_minval  ("... run koios"                      , system ("koios --Econv apate > /dev/null 2>&1"),  999);
   yUNIT_minval  ("... check result lines"             , yURG_peek_count (x_unit)  ,  19);
   yUNIT_minval  ("... count errors"                   , yURG_peek_count (YURG_ERR),   1);
   yUNIT_minstr  ("... check error line"               , yURG_peek (YURG_ERR,   0), BOLD_ERR "FATAL, apate.unit:5:0: error: verb ∂#>this∂ not recognized/found"               BACK_OFF  );
   yUNIT_minstr  ("... check error line"               , yURG_peek (YURG_ERR, '÷'), ""                                                    );
   yUNIT_mindnoc ();

   yUNIT_mincond  ("unit with variety of comments, and issue");
   system ("echo \"\"                                                                                                                                                                > apate.unit");
   system ("echo \"## this is a comment\"                                                                                                                                           >> apate.unit");
   system ("echo \"\"                                                                                                                                                               >> apate.unit");
   system ("echo \"#> this is a saved comment\"                                                                                                                                     >> apate.unit");
   system ("echo \"\"                                                                                                                                                               >> apate.unit");
   system ("echo \"PREP          include the prototype headers                            - - - - - - - - - -   - - - - -   - - - - - - - - - -  >>\"                     >> apate.unit");
   system ("echo \"   #> this is second level comment\"                                                                                                                             >> apate.unit");
   system ("echo \"   incl       include public header                apate.h           - - - - - - - - - -   - - - - -   - - - - - - - - - -  \"                       >> apate.unit");
   system ("echo \"#23456789-12  123456789-123456789-123456789-12345  123456789-123456  123456789-123456789-  123456789-  123456789-123456789-  -  123456789- \"    >> apate.unit");
   system ("echo \"#==(verb)===  ===========(description)===========  =====(function)=  ====(arguments)=====  ==(test)==  ====(results)=======  t  =(var)==== \"    >> apate.unit");
   system ("echo \"SCRP    [¡Ï]  (SCRP  ) verify openning and closin                                           ((01.---))  - - - - - - - - - -  \"                        >> apate.unit");
   system ("echo \"# random comment\"                                                                                                                                               >> apate.unit");
   system ("echo \"\"                                                                                                                                                               >> apate.unit");
   system ("echo \"   COND       parse a code record   - - - - - - - - - - - - -   ((01.001))  - - - - - - - - - \"                                                       >> apate.unit");
   system ("echo \"     #> this is third level comment\"                                                                                                                            >> apate.unit");
   system ("echo \"     load     add a line to stdin    stdin  * * * * *                      : basic line                  : - - - - -  :  /bin/true > /dev/null\"         >> apate.unit");
   system ("echo \"\"                                                                                                                                                               >> apate.unit");
   system ("echo \"# > random comment\"                                                                                                                                               >> apate.unit");
   yUNIT_mindnoc  ();

   yUNIT_mincond ("call conversion");
   yUNIT_minval  ("... check unit lines"               , yURG_peek_count (x_unit)  ,  18);
   yUNIT_minval  ("... run koios"                      , system ("koios --Econv apate > /dev/null 2>&1"),    0);
   yUNIT_minval  ("... check result lines"             , yURG_peek_count (x_unit)  ,  25);
   yUNIT_minval  ("... count errors"                   , yURG_peek_count (YURG_ERR),   0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify header");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit,   0), "#!/usr/local/bin/koios");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "#   koios-polos (axis of heaven) unit testing meta-language");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "#> this is a saved comment");
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify prep area");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-123456789- ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  ========(var)======= ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "PREP          include the prototype headers                                      - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "   #> this is second level comment");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "   incl       include public header                apate.h                     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");

   yUNIT_mincond ("verify script");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-123456789- ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  ========(var)======= ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "SCRP    [¡Ï]  (SCRP  ) verify openning and closin                                                                                                                                  ((01.---))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "   COND       parse a code record                                                - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((01.001))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "     #> this is third level comment");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "     load     add a line to stdin                  stdin                       * * * * *                      : basic line                  : - - - - -  :  /bin/true > /dev/null                                                                                                                         ");
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify footer");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "# end-of-file.  done, finito, completare, whimper [œ¥∑∑∑");
   yUNIT_minstr  ("... check line"                     , yURG_peek (x_unit, '÷'), "");

   PROG__unit_end    ();
   rm_working_files ();
   yUNIT_minprcs ();
   return 0;
}

char
koios__unit_live_variety (char a_list)
{
   int         c           =    0;
   char        x_unit      [LEN_HUND]  = "apate.unit";
   char        x_conv      [LEN_HUND]  = "apate.unit.unit";

   yUNIT_minscrp ("live testing with various versions");
   if (a_list == 'y')  return 0;
   yURG_err_none ();  /* not to stderr/terminal */
   rm_working_files ();
   PROG__unit_quiet  ();


   yUNIT_mincond  ("verify a simple success");
   system ("echo \"\"                                                                                                                                                                > apate.unit");
   system ("echo \"## this is a comment\"                                                                                                                                           >> apate.unit");
   system ("echo \"exec          read a line      SCRP_read       i_lesser    0       my_var   \"                                                                     >> apate.unit");
   system ("echo \"#> this is a saved comment\"                                                                                                                                     >> apate.unit");
   system ("echo \"     get      ... check on script  SCRP__unit   file , -1  s_equal  SCRP file      : apate.unit \"                                                   >> apate.unit");
   system ("echo \"   code       add lines                            - - - - - - - - - - - - -   system ();        \"                                                      >> apate.unit");
   system ("echo \"\"                                                                                                                                                               >> apate.unit");
   system ("echo \"  COND        parse a code record   - - - - - - - - - - - - -   ((01.001))  - - - - - - - - - \"                                                       >> apate.unit");
   system ("echo \"PREP          include the prototype headers                            - - - - - - - - - -   - - - - -   - - - - - - - - - -  >>\"                     >> apate.unit");
   system ("echo \"   incl       include public header                apate.h           - - - - - - - - - -   - - - - -   - - - - - - - - - -  \"                       >> apate.unit");
   system ("echo \"#23456789-12  123456789-123456789-123456789-12345  123456789-123456  123456789-123456789-  123456789-  123456789-123456789-  -  123456789- \"    >> apate.unit");
   system ("echo \"#==(verb)===  ===========(description)===========  =====(function)=  ====(arguments)=====  ==(test)==  ====(results)=======  t  =(var)==== \"    >> apate.unit");
   system ("echo \"SCRP    [¡Ï]  (SCRP  ) verify openning and closin                                           ((01.---))  - - - - - - - - - -  \"                        >> apate.unit");
   system ("echo \"\"                                                                                                                                                               >> apate.unit");
   system ("echo \"  load        add a line to stdin    stdin  * * * * *                      : basic line                  : - - - - -  :  /bin/true > /dev/null\"         >> apate.unit");
   system ("echo \"  toad        add a line to stdin 2  stdin  * * * * *                      : basic line                  : - - - - -  :  /bin/true > /dev/null\"         >> apate.unit");
   system ("echo \"              (SCRP  ) verify openning and closin                                           ((01.---))  - - - - - - - - - -  \"                        >> apate.unit");
   system ("echo \"\"                                                                                                                                                               >> apate.unit");
   system ("echo \"GROUP         complete               - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - -  \"                 >> apate.unit");
   system ("echo \"SECT          internal testing       - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - -  \"                 >> apate.unit");
   system ("echo \"    echo      ...check y location    - - - - - - - - - - - - -   y        r_norm93    -125.381                                     \"                >> apate.unit");
   system ("echo \"    system    remove a file                        - - - - - - - - - - - - -   rm -fv test.txt   \"                                                      >> apate.unit");
   system ("echo \"\"                                                                                                                                                               >> apate.unit");
   system ("echo \"#==(verb)===  ===========(description)===========  =====(function)=  ====(arguments)=====  ==(test)==  ====(results)=======  t  =(var)==== \"    >> apate.unit");
   system ("echo \"SHARED   -a-  setup cron files and lines           - - - - - - - -   ((CC.---))  - - - - - - - - - - - - - - - - - - - - - - - - -  \"                 >> apate.unit");
   system ("echo \"\"                                                                                                                                                               >> apate.unit");
   system ("echo \" REUSE -a-    - - - - - - - - - - - -   - - - - - - - - - - - - - - -   ((03.---))  - - - - - - - - - - - - - - - - - - - -  \"                        >> apate.unit");
   yUNIT_mindnoc  ();

   yUNIT_mincond ("call conversion");
   yUNIT_minval  ("... check unit lines"               , yURG_peek_count (x_unit)  ,   5);
   yUNIT_minval  ("... run koios"                      , system ("koios --Econv apate > /dev/null 2>&1"),   0);
   yUNIT_minval  ("... check result lines"             , yURG_peek_count (x_unit)  ,  18);
   yUNIT_minval  ("... count errors"                   , yURG_peek_count (YURG_ERR),   0);
   yUNIT_mindnoc ();

   PROG__unit_end    ();
   rm_working_files ();
   yUNIT_minprcs ();
   return 0;
}

char
koios__unit_live_code    (char a_list)
{
   int         c           =    0;
   char        x_unit      [LEN_HUND]  = "apate.unit";
   char        x_conv      [LEN_HUND]  = "apate.unit.unit";
   char        x_urun      [LEN_HUND]  = "apate.urun";

   yUNIT_minscrp ("live testing with various versions");
   if (a_list == 'y')  return 0;
   yURG_err_none ();  /* not to stderr/terminal */
   rm_working_files ();
   PROG__unit_quiet  ();


   yUNIT_mincond  ("verify a simple success");
   system ("echo \"PREP          include headers                     \"                                                                                                                > apate.unit");
   system ("echo \"   incl       right libraries                      koios.h                     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  \"   >> apate.unit");
   system ("echo \"SCRP          quick test                                                       - - - - - - - - - - - - - - - - -    -((01.---))  - - - - - - - - - -  \"   >> apate.unit");
   system ("echo \"   COND       verify code                          - - - - - - - - - - - - -   ((01.001))  - - - - - - - - - -  \"                                           >> apate.unit");
   system ("echo \"     local    path directory                       - - - - - - - - - - - - -   char  x_name [LEN_HUND] = \\\"\\\";                                        \"   >> apate.unit");
   system ("echo \"     code     update directory                     - - - - - - - - - - - - -   strcpy (x_name, \\\"/home/member\\\");                                     \"   >> apate.unit");
   system ("echo \"     code     change directory                     - - - - - - - - - - - - -   chdir (x_name);                                                            \"   >> apate.unit");
   system ("echo \"     exec     get current directory                getcwd                      NULL, 0                             s_equal       /home/member         \"   >> apate.unit");
   yUNIT_mindnoc  ();

   yUNIT_mincond ("call conversion");
   yUNIT_minval  ("... check unit lines"               , yURG_peek_count (x_unit)  ,   4);
   yUNIT_minval  ("... count errors"                   , yURG_peek_count (YURG_ERR),   0);
   yUNIT_minval  ("... run koios"                      , system ("koios --Ecode apate > /dev/null 2>&1"),   0);
   yUNIT_minval  ("... copy to c"                      , system ("cp  -f apate_unit.{cs,c}"), 0);
   yUNIT_minval  ("... compile"                        , system ("gcc -c apate_unit.c"), 0);
   yUNIT_minval  ("... link"                           , system ("gcc -o apate_unit apate_unit.o -lyUNIT"), 0);
   yUNIT_minval  ("... permissions"                    , system ("chmod +x apate_unit"), 0);
   yUNIT_mindnoc  ();

   yUNIT_mincond ("check results");
   yUNIT_minval  ("... run unit test"                  , system ("./apate_unit")  , 0);
   yUNIT_minval  ("... check line count"               , yURG_peek_count (x_urun) , 28);
   yUNIT_mindnoc ();

   yUNIT_mincond ("check header");
   yUNIT_minstr  ("... check unit header"              , yURG_peek (x_urun, '∫'), "yUNIT - heatherly unit testing framework --------------------------- - actu once ndit");
   yUNIT_minstr  ("... ... patron"                     , yURG_peek (x_urun, '÷'), "   patron : daktyloi-aeonius (forefinger) automated unit testing     s ∑∑∑1 ∑∑∑1 ∑∑∑1");
   yUNIT_minstr  ("... ... level"                      , yURG_peek (x_urun, '÷'), "   assign output level to (5) YUNIT_FULL                             c ∑∑∑1 ∑∑∑1 ∑∑∑1");
   yUNIT_minstr  ("... ... eterm"                      , yURG_peek (x_urun, '÷'), "   assign format/color to (y) ETERM                                  x ∑∑∑2 ∑∑∑2 ∑∑∑2");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");

   yUNIT_mincond ("check script entry");                
   yUNIT_minstr  ("... check (11) separator"           , yURG_peek (x_urun, '÷'), "===[[ NEW SCRIPT ]]==================================================================");
   yUNIT_minstr  ("... check script"                   , yURG_peek (x_urun, '÷'), "SCRP [01] quick test ====================================================[  ]=[00001]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check condition entry");                
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "  COND [001] verify code  -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00002]");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");

   yUNIT_mincond ("check passing string step");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, '÷'), "  " BACK_CYN "aa) " BACK_GRN "CODE  " BACK_OFF " : change directory ∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑[00003]");
   yUNIT_minstr  ("... ... actual"                     , yURG_peek (x_urun, '÷'), "      code   : 23Âchdir (∂/home/member∂);Ê");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check passing string step");
   yUNIT_minstr  ("... check step header"              , yURG_peek (x_urun, '÷'), "  " BACK_GRN "ab) PASS  " BACK_OFF " : get current directory ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑ ∑∑[00004]");
   yUNIT_minstr  ("... ... method"                     , yURG_peek (x_urun, '÷'), "      method : getcwd (NULL, 0)");
   yUNIT_minstr  ("... ... test"                       , yURG_peek (x_urun, '÷'), "      test   : s_equal    (rc =  101, test abbr = e)");
   yUNIT_minstr  ("... ... expect"                     , yURG_peek (x_urun, '÷'), "      expect : 12Â/home/memberÊ");
   yUNIT_minstr  ("... ... actual"                     , yURG_peek (x_urun, '÷'), "      actual : 12Â/home/memberÊ");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check urun output");
   yUNIT_minstr  ("... check condition footer"         , yURG_peek (x_urun, '÷'), "      " BACK_GRN "DNOC --------------- test=2     [ pass=1     fail=0     badd=0     void=1     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check script footer"            , yURG_peek (x_urun, '÷'), "  " BACK_GRN "PRCS -------- cond=1     test=2     [ pass=1     fail=0     badd=0     void=1     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check unit footer"              , yURG_peek (x_urun, '÷'), BACK_GRN "TINU  scrp=1    cond=1     test=2     [ pass=1     fail=0     badd=0     void=1     ]" BACK_OFF);
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_minstr  ("... check unit footer"              , yURG_peek (x_urun, '÷'), "yUNIT - heatherly unit testing framework ---------------------------------------(end)");
   yUNIT_minstr  ("... empty"                          , yURG_peek (x_urun, '÷'), "");
   yUNIT_mindnoc ();

   PROG__unit_end    ();
   /*> rm_working_files ();                                                           <*/
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
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_reuse_update   (x_list);
   /*---(koios_conv.c)-------------------*/
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_conv_defense   (x_list);
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_conv_printf    (x_list);
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_conv_preps     (x_list);
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_conv_scrps     (x_list);
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_conv_conds     (x_list);
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_conv_steps     (x_list);
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_conv_driver    (x_list);
   /*---(koios_code.c)-------------------*/
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_code_preps     (x_list);
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_code_scrp      (x_list);
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_code_cond      (x_list);
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_code_display   (x_list);
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_code_prefix    (x_list);
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_code_expect    (x_list);
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_code_suffix    (x_list);
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_code_steps     (x_list);
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_code_vars      (x_list);
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_code_spec      (x_list);
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_code_driver    (x_list);
   /*---(koios_read.c)-------------------*/
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_read_defense   (x_list);
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_read_single    (x_list);
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_read_end_ditto (x_list);
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_read_driver    (x_list);
   /*---(koios_ditto.c MORE)-------------*/
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_ditto_parse    (x_list);
   /*---(koios_parse.c)------------------*/
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_parse_default  (x_list);
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_parse_comment  (x_list);
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_parse_version  (x_list);
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_parse_limits   (x_list);
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_parse_current  (x_list);
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_parse_prep     (x_list);
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_parse_driver   (x_list);
   /*---(script input)-------------------*/
   /*> ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_scrp_variety ();            <*/
   /*---(conversion live)----------------*/
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_live_conv      (x_list);
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_live_ditto     (x_list);
   /*---(code live)----------------------*/
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_live_scrp      (x_list);
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_live_cond      (x_list);
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_live_step      (x_list);
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_live_full      (x_list);
   /*---(specific concerns)--------------*/
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_live_stop      (x_list);
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_live_vers      (x_list);
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_live_comment   (x_list);
   ++n;  if (x_unit == 0 || x_unit == n)  koios__unit_live_code      (x_list);
   /*---(done)---------------------------*/
   yUNIT_mintinu ();
   return 0;
}


