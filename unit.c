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
   yUNIT_minval  ("parse SHARED"                       , SCRP_parse_verb ("SHARED -A-"), 0);
   yUNIT_minstr ("... check verb"                      , my.verb       , "SHARED");
   yUNIT_minval ("... check index"                     , my.indx       , 999);
   yUNIT_minval  ("parse COND"                         , SCRP_parse_verb (" COND [a]"), 0);
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
koios__unit_scrp_ditto   (void)
{
   yUNIT_minscrp ("koios_scrp identifying ditto marks");
   yURG_err_none ();  /* not to stderr/terminal */

   yUNIT_mincond ("prepare clean start");
   system ("rm -f /tmp/koios.unit 2> /dev/null");
   my.run_type = G_RUN_CREATE;
   yUNIT_mindnoc ();

   yUNIT_mincond ("directly set ditto marks");
   yUNIT_minstr ("... check dittos"                    , SCRP_ditto_used ()  , "--------------------------");
   yUNIT_minval  ("set ditto"                          , SCRP_ditto__set ('A'), 0);
   yUNIT_minstr ("... check dittos"                    , SCRP_ditto_used ()  , "A-------------------------");
   yUNIT_minval  ("set ditto"                          , SCRP_ditto__set ('M'), 0);
   yUNIT_minstr ("... check dittos"                    , SCRP_ditto_used ()  , "A-----------M-------------");
   yUNIT_minval  ("set ditto"                          , SCRP_ditto__set ('W'), 0);
   yUNIT_minstr ("... check dittos"                    , SCRP_ditto_used ()  , "A-----------M---------W---");
   yUNIT_minval  ("set ditto"                          , SCRP_ditto__set (' '), -999);
   yUNIT_minstr ("... check dittos"                    , SCRP_ditto_used ()  , "A-----------M---------W---");
   yUNIT_minval  ("set ditto"                          , SCRP_ditto__set ('b'), -999);
   yUNIT_minstr ("... check dittos"                    , SCRP_ditto_used ()  , "A-----------M---------W---");
   yUNIT_minval  ("set ditto"                          , SCRP_ditto__set ('è'), -999);
   yUNIT_minstr ("... check dittos"                    , SCRP_ditto_used ()  , "A-----------M---------W---");
   yUNIT_minval  ("clear all dittos"                   , SCRP_ditto__clear () , 0);
   yUNIT_minstr ("... check dittos"                    , SCRP_ditto_used ()  , "--------------------------");
   yUNIT_mindnoc ();

   yUNIT_mincond ("use ditto check");
   yUNIT_minstr ("... check dittos"                    , SCRP_ditto_used ()  , "--------------------------");
   yUNIT_minval  ("parse COND"                         , SCRP_parse_verb ("COND (A)"), 0);
   yUNIT_minstr ("... check verb"                      , my.verb       , "COND");
   yUNIT_minval  ("check ditto"                        , SCRP_ditto__check ("COND (A)", 'y'), 0);
   yUNIT_minstr ("... check dittos"                    , SCRP_ditto_used ()  , "A-------------------------");
   yUNIT_minchr ("... check mark"                      , my.mark       , 'A');
   yUNIT_minval  ("parse COND"                         , SCRP_parse_verb ("COND (M)"), 0);
   yUNIT_minstr ("... check verb"                      , my.verb       , "COND");
   yUNIT_minval  ("check ditto"                        , SCRP_ditto__check ("COND (M)", 'y'), 0);
   yUNIT_minstr ("... check dittos"                    , SCRP_ditto_used ()  , "A-----------M-------------");
   yUNIT_minchr ("... check mark"                      , my.mark       , 'M');
   yUNIT_minval  ("parse COND"                         , SCRP_parse_verb ("COND ("  ), 0);
   yUNIT_minstr ("... check verb"                      , my.verb       , "COND");
   yUNIT_minval  ("check ditto"                        , SCRP_ditto__check ("COND ("  , 'y'), -999);
   yUNIT_minstr ("... check dittos"                    , SCRP_ditto_used ()  , "A-----------M-------------");
   yUNIT_minchr ("... check mark"                      , my.mark       , '-');
   yUNIT_minval  ("parse COND"                         , SCRP_parse_verb ("COND ()" ), 0);
   yUNIT_minstr ("... check verb"                      , my.verb       , "COND");
   yUNIT_minval  ("check ditto"                        , SCRP_ditto__check ("COND ()" , 'y'), -999);
   yUNIT_minstr ("... check dittos"                    , SCRP_ditto_used ()  , "A-----------M-------------");
   yUNIT_minchr ("... check mark"                      , my.mark       , '-');
   yUNIT_minval  ("parse COND"                         , SCRP_parse_verb ("COND     (W)" ), 0);
   yUNIT_minstr ("... check verb"                      , my.verb       , "COND");
   yUNIT_minval  ("check ditto"                        , SCRP_ditto__check ("COND     (W)", 'y'), 0);
   yUNIT_minstr ("... check dittos"                    , SCRP_ditto_used ()  , "A-----------M---------W---");
   yUNIT_minchr ("... check mark"                      , my.mark       , 'W');
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify handling dittos");
   strcpy (my.n_scrp, "/tmp/koios.unit");
   system ("echo \"\"                                                                         >  /tmp/koios.unit");
   system ("echo \"  COND (B)   original cond    - - - - - -  -  - - - - -   - - -  \"  >> /tmp/koios.unit");
   system ("echo \"    exec     line one         - - - - - -  -  - - - - -   - - -  \"  >> /tmp/koios.unit");
   system ("echo \"    exec     line two         - - - - - -  -  - - - - -   - - -  \"  >> /tmp/koios.unit");
   system ("echo \"\"                                                                         >> /tmp/koios.unit");
   system ("echo \"  DITTO (B)  new cond         - - - - - -  -  - - - - -   - - -  \"  >> /tmp/koios.unit");
   system ("echo \"\"                                                                         >> /tmp/koios.unit");
   system ("echo \"  COND       after others     - - - - - -  -  - - - - -   - - -  \"  >> /tmp/koios.unit");
   yUNIT_minstr ("... check script name"              , my.n_scrp     , "/tmp/koios.unit");
   yUNIT_minval ("open the script file"               , SCRP_open   (), 0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("read ditto condition");
   yUNIT_minval ("read a line"                        , SCRP_read   (), 1);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "  COND (B)  § original cond   § - - - - - - § - § - - - - -  § - - -  §");
   yUNIT_minstr ("... check dittos"                    , SCRP_ditto_used ()  , "-B------------------------");
   yUNIT_mindnoc ();

   yUNIT_mincond ("read detailed line");
   yUNIT_minval ("read a line"                        , SCRP_read   (), 1);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "    exec    § line one        § - - - - - - § - § - - - - -  § - - -  §");
   yUNIT_minstr ("... check dittos"                    , SCRP_ditto_used ()  , "-B------------------------");
   yUNIT_mindnoc ();

   yUNIT_mincond ("read detailed line");
   yUNIT_minval ("read a line"                        , SCRP_read   (), 1);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "    exec    § line two        § - - - - - - § - § - - - - -  § - - -  §");
   yUNIT_minstr ("... check dittos"                    , SCRP_ditto_used ()  , "-B------------------------");
   yUNIT_mindnoc ();

   yUNIT_mincond ("read ditto call");
   yUNIT_minval ("read a line"                        , SCRP_read   (), 1);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "  DITTO (B) § new cond        § - - - - - - § - § - - - - -  § - - -  §");
   yUNIT_minstr ("... check dittos"                    , SCRP_ditto_used ()  , "-B------------------------");
   yUNIT_mindnoc ();

   yUNIT_mincond ("read ditto condition");
   yUNIT_minval ("read a line"                        , SCRP_read   (), 1);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "  COND (B)  § original cond   § - - - - - - § - § - - - - -  § - - -  §");
   yUNIT_minstr ("... check dittos"                    , SCRP_ditto_used ()  , "-B------------------------");
   yUNIT_mindnoc ();

   yUNIT_mincond ("read detailed line");
   yUNIT_minval ("read a line"                        , SCRP_read   (), 1);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "    exec    § line one        § - - - - - - § - § - - - - -  § - - -  §");
   yUNIT_minstr ("... check dittos"                    , SCRP_ditto_used ()  , "-B------------------------");
   yUNIT_mindnoc ();

   yUNIT_mincond ("read detailed line");
   yUNIT_minval ("read a line"                        , SCRP_read   (), 1);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "    exec    § line two        § - - - - - - § - § - - - - -  § - - -  §");
   yUNIT_minstr ("... check dittos"                    , SCRP_ditto_used ()  , "-B------------------------");
   yUNIT_mindnoc ();

   yUNIT_mincond ("read after condition");
   yUNIT_minval ("read a line"                        , SCRP_read   (), 1);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "  COND      § after others    § - - - - - - § - § - - - - -  § - - -  §");
   yUNIT_minstr ("... check dittos"                    , SCRP_ditto_used ()  , "-B------------------------");
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

char
koios__unit_scrp_variety (void)
{
   yUNIT_minscrp ("koios_scrp read/parse a variety of records");
   yURG_err_none ();  /* not to stderr/terminal */

   yUNIT_mincond ("prepare clean start");
   system ("rm -f /tmp/koios.unit 2> /dev/null");
   system ("echo \"\"                                                                                                                                                      > /tmp/koios.unit");
   system ("echo \"## this is a comment\"                                                                                                                                 >> /tmp/koios.unit");
   system ("echo \"exec          read a line      SCRP_read       i_lesser    0       p  my_var   \"                                                              >> /tmp/koios.unit");
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
   system ("echo \"SHARED   -A-  setup cron files and lines           - - - - - - - -   ((CC.---))  - - - - - - - - - - - - - - - - - - - - - - - - -  \"            >> /tmp/koios.unit");
   system ("echo \"\"                                                                                                                                                     >> /tmp/koios.unit");
   system ("echo \" REUSE -A-    - - - - - - - - - - - -   - - - - - - - - - - - - - - -   ((03.---))  - - - - - - - - - - - - - - - - - - - -  \"                   >> /tmp/koios.unit");
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
   yUNIT_minstr ("... check the record"               , my.recd       , "exec         § read a line     § SCRP_read   §   § i_lesser   § 0      § p § my_var   §");
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
   yUNIT_minchr ("... check type"                     , my.type       , 'p');
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
   yUNIT_minchr ("... check type"                     , my.type       , '-');
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
   yUNIT_minchr ("... check type"                     , my.type       , '-');
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
   yUNIT_minchr ("... check type"                     , my.type       , '-');
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
   yUNIT_minchr ("... check type"                     , my.type       , '-');
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
   yUNIT_minchr ("... check type"                     , my.type       , '-');
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
   yUNIT_minchr ("... check type"                     , my.type       , '-');
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
   yUNIT_minchr ("... check type"                     , my.type       , '-');
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
   yUNIT_minchr ("... check type"                     , my.type       , '-');
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
   yUNIT_minchr ("... check type"                     , my.type       , '-');
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
   yUNIT_minchr ("... check type"                     , my.type       , '-');
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
   yUNIT_minchr ("... check type"                     , my.type       , '-');
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
   yUNIT_minchr ("... check type"                     , my.type       , '-');
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
   yUNIT_minchr ("... check type"                     , my.type       , '-');
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
   yUNIT_minchr ("... check type"                     , my.type       , '-');
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "rm -fv test.txt");
   yUNIT_mindnoc ();

   yUNIT_mincond ("read shared section line");
   yUNIT_minval ("read a line"                        , SCRP_read   (), 1);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "SHARED   -A- § setup cron files and lines          § - - - - - - - -  § ((CC.---)) § - - - - - - - - - - - - - - - - - - - - - - - - -  §");
   yUNIT_minstr ("... check verb"                     , my.verb       , "SHARED");
   yUNIT_minstr ("... check stage"                    , my.stage      , "");
   yUNIT_minchr ("... check share"                    , my.share      , 'A');
   yUNIT_minchr ("... check mark"                     , my.mark       , '-');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "setup cron files and lines");
   yUNIT_minstr ("... check method"                   , my.meth       , "");
   yUNIT_minstr ("... check arguments"                , my.args       , "");
   yUNIT_minstr ("... check test"                     , my.test       , "");
   yUNIT_minstr ("... check expect"                   , my.expe       , "");
   yUNIT_minchr ("... check type"                     , my.type       , '-');
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("read use shared line");
   yUNIT_minval ("read a line"                        , SCRP_read   (), 1);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , " REUSE -A-   § - - - - - - - - - - - -  § - - - - - - - - - - - - - - -  § ((03.---)) § - - - - - - - - - - - - - - - - - - - -  §");
   yUNIT_minstr ("... check verb"                     , my.verb       , "REUSE");
   yUNIT_minstr ("... check stage"                    , my.stage      , "");
   yUNIT_minchr ("... check share"                    , my.share      , 'A');
   yUNIT_minchr ("... check mark"                     , my.mark       , '-');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "");
   yUNIT_minstr ("... check method"                   , my.meth       , "");
   yUNIT_minstr ("... check arguments"                , my.args       , "");
   yUNIT_minstr ("... check test"                     , my.test       , "");
   yUNIT_minstr ("... check expect"                   , my.expe       , "");
   yUNIT_minchr ("... check type"                     , my.type       , '-');
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
   yUNIT_minstr ("... check (0) shebang"              , yURG_peek (my.n_conv, 0), "#!/usr/local/bin/koios");
   yUNIT_minstr ("... check (1) title"                , yURG_peek (my.n_conv, 1), "#   koios-polos (axis of heaven) unit testing meta-language");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_conv) , 2);
   yUNIT_mindnoc ();

   yUNIT_mincond ("write a standard header");
   CONV_cycle ();
   yUNIT_minval ("call header"                        , CONV_header (), 0);
   yUNIT_minstr ("... check (0) empty"                , yURG_peek (my.n_conv, 0), "");
   yUNIT_minstr ("... check (1) empty"                , yURG_peek (my.n_conv, 1), "");
   yUNIT_minstr ("... check (2) empty"                , yURG_peek (my.n_conv, 2), "");
   yUNIT_minstr ("... check (3) number ruler"         , yURG_peek (my.n_conv, 3), "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  -  123456789-123456789- ");
   yUNIT_minstr ("... check (4) title"                , yURG_peek (my.n_conv, 4), "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  t  ========(var)======= ");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_conv) , 5);
   yUNIT_mindnoc ();

   yUNIT_mincond ("write the ending");
   CONV_cycle ();
   yUNIT_minval ("call end"                           , CONV_end    (), 0);
   yUNIT_minstr ("... check (0) empty"                , yURG_peek (my.n_conv, 0), "");
   yUNIT_minstr ("... check (1) empty"                , yURG_peek (my.n_conv, 1), "");
   yUNIT_minstr ("... check (2) empty"                , yURG_peek (my.n_conv, 2), "");
   yUNIT_minstr ("... check (3) finish"               , yURG_peek (my.n_conv, 3), "# end-of-file.  done, finito, completare, whimper [Ï´···");
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
   yUNIT_minstr ("... check (0) empty"                , yURG_peek (my.n_conv, 0), "");
   yUNIT_minstr ("... check (1) empty"                , yURG_peek (my.n_conv, 1), "");
   yUNIT_minstr ("... check (2) empty"                , yURG_peek (my.n_conv, 2), "");
   yUNIT_minstr ("... check (3) number ruler"         , yURG_peek (my.n_conv, 3), "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  -  123456789-123456789- ");
   yUNIT_minstr ("... check (4) title"                , yURG_peek (my.n_conv, 4), "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  t  ========(var)======= ");
   yUNIT_minstr ("... check (5) prep line"            , yURG_peek (my.n_conv, 5), "PREP          include the prototype headers                                      - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_conv) , 6);
   yUNIT_mindnoc ();

   yUNIT_mincond ("write an include");
   strcpy (my.recd, "incl   public header  stdio.h         ");
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
   yUNIT_minstr ("... check (0) prep line"            , yURG_peek (my.n_conv, 0), "   incl       public header                        stdio.h                     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_conv) , 1);
   yUNIT_mindnoc ();

   yUNIT_mincond ("write a comment");
   strcpy (my.recd, "#> the following macro resets exec lines");
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
   yUNIT_minstr ("... check (0) prep line"            , yURG_peek (my.n_conv, 0), "#> the following macro resets exec lines");
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

   yUNIT_minscrp ("CONV_scrp, CONV_sect, CONV_shared");
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

   yUNIT_mincond ("write a script");
   strcpy (my.recd, "SCRP [ì4]   (FILE) biggest script  core_function       ");
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
   yUNIT_minstr ("... check (0) empty"                , yURG_peek (my.n_conv, 0), "");
   yUNIT_minstr ("... check (1) empty"                , yURG_peek (my.n_conv, 1), "");
   yUNIT_minstr ("... check (2) empty"                , yURG_peek (my.n_conv, 2), "");
   yUNIT_minstr ("... check (3) number ruler"         , yURG_peek (my.n_conv, 3), "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  -  123456789-123456789- ");
   yUNIT_minstr ("... check (4) title"                , yURG_peek (my.n_conv, 4), "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  t  ========(var)======= ");
   yUNIT_minstr ("... check (5) script line"          , yURG_peek (my.n_conv, 5), "SCRP    [ì4]  (FILE) biggest script                                              core_function                                                                                         ((01.---))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_conv) , 6);
   yUNIT_mindnoc ();

   yUNIT_mincond ("write a section break");
   strcpy (my.recd, "SECT  file oriented         ");
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
   yUNIT_minstr ("... check (0) empty"                , yURG_peek (my.n_conv, 0), "");
   yUNIT_minstr ("... check (1) empty"                , yURG_peek (my.n_conv, 1), "");
   yUNIT_minstr ("... check (2) empty"                , yURG_peek (my.n_conv, 2), "");
   yUNIT_minstr ("... check (3) number ruler"         , yURG_peek (my.n_conv, 3), "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  -  123456789-123456789- ");
   yUNIT_minstr ("... check (4) title"                , yURG_peek (my.n_conv, 4), "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  t  ========(var)======= ");
   yUNIT_minstr ("... check (5) section line"         , yURG_peek (my.n_conv, 5), "SECT          file oriented                                                      - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_conv) , 6);
   yUNIT_mindnoc ();

   yUNIT_mincond ("write a shared line");
   strcpy (my.recd, "SHARED -a-  remove temporary files         ");
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
   yUNIT_minstr ("... check (0) empty"                , yURG_peek (my.n_conv, 0), "");
   yUNIT_minstr ("... check (1) empty"                , yURG_peek (my.n_conv, 1), "");
   yUNIT_minstr ("... check (2) empty"                , yURG_peek (my.n_conv, 2), "");
   yUNIT_minstr ("... check (3) number ruler"         , yURG_peek (my.n_conv, 3), "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  -  123456789-123456789- ");
   yUNIT_minstr ("... check (4) title"                , yURG_peek (my.n_conv, 4), "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  t  ========(var)======= ");
   yUNIT_minstr ("... check (5) shared line"          , yURG_peek (my.n_conv, 5), "SHARED   -a-  remove temporary files                                             - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((aa.---))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_conv) , 6);
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
   strcpy (my.recd, "COND (B)  verify successful value         ");
   yUNIT_minval ("parse the line"                     , SCRP_parse (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "COND (B) § verify successful value §  §  §  §  §");
   yUNIT_minstr ("... check verb"                     , my.verb       , "COND");
   yUNIT_minstr ("... check stage"                    , my.stage      , "");
   yUNIT_minchr ("... check share"                    , my.share      , '-');
   yUNIT_minchr ("... check mark"                     , my.mark       , 'B');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "verify successful value");
   yUNIT_minstr ("... check method"                   , my.meth       , "");
   yUNIT_minstr ("... check arguments"                , my.args       , "");
   yUNIT_minstr ("... check test"                     , my.test       , "");
   yUNIT_minstr ("... check expect"                   , my.expe       , "");
   CONV_cycle ();
   yUNIT_minval ("call condition"                     , CONV_cond   (), 0);
   yUNIT_minstr ("... check (0) empty"                , yURG_peek (my.n_conv, 0), "");
   yUNIT_minstr ("... check (1) script line"          , yURG_peek (my.n_conv, 1), "   COND (B)   verify successful value                                            - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((aa.001))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_conv) , 2);
   yUNIT_mindnoc ();

   yUNIT_mincond ("write a ditto");
   strcpy (my.recd, "DITTO (B)           ");
   yUNIT_minval ("parse the line"                     , SCRP_parse (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "DITTO (B) §  §  §  §  §  §");
   yUNIT_minstr ("... check verb"                     , my.verb       , "DITTO");
   yUNIT_minstr ("... check stage"                    , my.stage      , "");
   yUNIT_minchr ("... check share"                    , my.share      , '-');
   yUNIT_minchr ("... check mark"                     , my.mark       , 'B');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "");
   yUNIT_minstr ("... check method"                   , my.meth       , "");
   yUNIT_minstr ("... check arguments"                , my.args       , "");
   yUNIT_minstr ("... check test"                     , my.test       , "");
   yUNIT_minstr ("... check expect"                   , my.expe       , "");
   CONV_cycle ();
   yUNIT_minval ("call ditto"                         , CONV_ditto  (), 0);
   yUNIT_minstr ("... check (0) empty"                , yURG_peek (my.n_conv, 0), "");
   yUNIT_minstr ("... check (1) script line"          , yURG_peek (my.n_conv, 1), "   DITTO (B)  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((aa.002))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_conv) , 2);
   yUNIT_mindnoc ();

   yUNIT_mincond ("write a group");
   strcpy (my.recd, "GROUP  check major defenses         ");
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
   yUNIT_minstr ("... check (0) empty"                , yURG_peek (my.n_conv, 0), "");
   yUNIT_minstr ("... check (1) script line"          , yURG_peek (my.n_conv, 1), "   GROUP      check major defenses                                               - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_conv) , 2);
   yUNIT_mindnoc ();

   yUNIT_mincond ("write a use for shares");
   strcpy (my.recd, "REUSE -d-           ");
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
   yUNIT_minstr ("... check (0) empty"                , yURG_peek (my.n_conv, 0), "");
   yUNIT_minstr ("... check (1) script line"          , yURG_peek (my.n_conv, 1), "   REUSE -d-  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
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
   strcpy (my.recd, "exec          read a line      SCRP_read    test, 5   i_lesser    0       p  my_var   ");
   yUNIT_minval ("parse the line"                     , SCRP_parse (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "exec         § read a line     § SCRP_read   § test, 5  § i_lesser   § 0      § p § my_var   §");
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
   yUNIT_minchr ("... check type"                     , my.type       , 'p');
   yUNIT_minstr ("... check return"                   , my.retn       , "my_var");
   yUNIT_minstr ("... check code"                     , my.code       , "test, 5");
   CONV_cycle ();
   yUNIT_minval ("call exec"                          , CONV_exec   (), 0);
   yUNIT_minstr ("... check (0) detail"               , yURG_peek (my.n_conv, 0), "     exec     read a line                          SCRP_read                   test, 5                                                                                               i_lesser    0                                                                                                     p  my_var               ");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_conv) , 1);
   yUNIT_mindnoc ();

   yUNIT_mincond ("write a get");
   strcpy (my.recd, "get  ...check count  UNIT_answer  \"ans\"  s_equal  count = 15.2 ");
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
   yUNIT_minchr ("... check type"                     , my.type       , '-');
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "\"ans\"");
   CONV_cycle ();
   yUNIT_minval ("call exec"                          , CONV_exec   (), 0);
   yUNIT_minstr ("... check (0) detail"               , yURG_peek (my.n_conv, 0), "     get      ...check count                       UNIT_answer                 \"ans\"                                                                                                 s_equal     count = 15.2                                                                                         ");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_conv) , 1);
   yUNIT_mindnoc ();

   yUNIT_mincond ("write a mode");
   strcpy (my.recd, "mode  FORCED_FAIL         ");
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
   yUNIT_minchr ("... check type"                     , my.type       , '-');
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "");
   CONV_cycle ();
   yUNIT_minval ("call code"                          , CONV_mode   (), 0);
   yUNIT_minstr ("... check (0) detail"               , yURG_peek (my.n_conv, 0), "     mode     FORCED_FAIL                          - - - - - - - - - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_conv) , 1);
   yUNIT_mindnoc ();

   yUNIT_mincond ("write a load");
   strcpy (my.recd, "load  keyboard input  ncurses  abcdefghijklmnopqrstuvwxyz ");
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
   yUNIT_minchr ("... check type"                     , my.type       , '-');
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "abcdefghijklmnopqrstuvwxyz");
   CONV_cycle ();
   yUNIT_minval ("call code"                          , CONV_load   (), 0);
   yUNIT_minstr ("... check (0) detail"               , yURG_peek (my.n_conv, 0), "     load     keyboard input                       ncurses                     abcdefghijklmnopqrstuvwxyz                                                                                                                                                                                                 ");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_conv) , 1);
   yUNIT_mindnoc ();

   yUNIT_mincond ("write a code");
   strcpy (my.recd, "code  working variable   int l = 15; ");
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
   yUNIT_minchr ("... check type"                     , my.type       , '-');
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "int l = 15;");
   CONV_cycle ();
   yUNIT_minval ("call code"                          , CONV_code   (), 0);
   yUNIT_minstr ("... check (0) detail"               , yURG_peek (my.n_conv, 0), "     code     working variable                     - - - - - - - - - - - - -   int l = 15;                                                                                                                                                                                                                ");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_conv) , 1);
   yUNIT_mindnoc ();

   yUNIT_mincond ("write an echo");
   strcpy (my.recd, "echo  check length   l  r_equal  15.2 ");
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
   yUNIT_minchr ("... check type"                     , my.type       , '-');
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "l");
   CONV_cycle ();
   yUNIT_minval ("call code"                          , CONV_echo   (), 0);
   yUNIT_minstr ("... check (0) detail"               , yURG_peek (my.n_conv, 0), "     echo     check length                         - - - - - - - - - - - - -   l                                                                                                     r_equal     15.2                                                                                                 ");
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
   yUNIT_minstr ("... check (0) lead comment"         , yURG_peek (my.n_code, 0), "/*================================= beg-code =================================*/");
   yUNIT_minstr ("... check (1) shebang"              , yURG_peek (my.n_code, 1), "/* /usr/local/bin/koios                                                       */");
   yUNIT_minstr ("... check (2) title"                , yURG_peek (my.n_code, 2), "/*   autogen by koios-polos (axis of heaven) unit testing meta-language       */");
   yUNIT_minstr ("... check (3) empty"                , yURG_peek (my.n_code, 3), "");
   yUNIT_minstr ("... check (4) empty"                , yURG_peek (my.n_code, 4), "/*---(standard support functions)----*/");
   yUNIT_minstr ("... check (5) empty"                , yURG_peek (my.n_code, 5), "#include    <yUNIT_unit.h>");
   yUNIT_minstr ("... check (6) empty"                , yURG_peek (my.n_code, 6), "");
   yUNIT_minstr ("... check (7) lead comment"         , yURG_peek (my.n_code, 7), "/*================================ beg-script ================================*/");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) , 8);
   yUNIT_mindnoc ();

   yUNIT_mincond ("write the ending of code");
   CODE_cycle ();
   yUNIT_minval ("call end"                           , CODE_end    (), 0);
   yUNIT_minstr ("... check (0) lead comment"         , yURG_peek (my.n_code, 0), "/*================================ end-script ================================*/");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) , 1);
   yUNIT_mindnoc ();

   yUNIT_mincond ("write the beginning of main");
   CODE_cycle ();
   yUNIT_minval ("call beg"                           , MAIN_beg    (), 0);
   yUNIT_minstr ("... check (0) empty"                , yURG_peek (my.n_main, 0), "");
   yUNIT_minstr ("... check (1) empty"                , yURG_peek (my.n_main, 1), "");
   yUNIT_minstr ("... check (2) empty"                , yURG_peek (my.n_main, 2), "");
   yUNIT_minstr ("... check (3) return type"          , yURG_peek (my.n_main, 3), "int");
   yUNIT_minstr ("... check (4) definition"           , yURG_peek (my.n_main, 4), "main                    (int a_argc, char *a_argv[])");
   yUNIT_minstr ("... check (5) open brace"           , yURG_peek (my.n_main, 5), "{");
   yUNIT_minstr ("... check (6) comment"              , yURG_peek (my.n_main, 6), "   /*---(locals)-----------+-----+-----+-*/");
   yUNIT_minstr ("... check (7) local"                , yURG_peek (my.n_main, 7), "   int         rc          =    0;");
   yUNIT_minstr ("... check (8) comment"              , yURG_peek (my.n_main, 8), "   /*---(prepare)------------------------*/");
   yUNIT_minstr ("... check (9) check arguments"      , yURG_peek (my.n_main, 9), "   rc = yUNIT_init ();");
   yUNIT_minstr ("... check (10) check arguments"     , yURG_peek (my.n_main,10), "   rc = yUNIT_args (a_argc, a_argv);");
   yUNIT_minstr ("... check (11) error checking"      , yURG_peek (my.n_main,11), "   if (rc < 0)  return -1;");
   yUNIT_minstr ("... check (12) start unit test"     , yURG_peek (my.n_main,12), "   yUNIT_unit (\"/tmp/koios_scrp\", g.level, g.eterm, g.exec);");
   yUNIT_minstr ("... check (13) comment"             , yURG_peek (my.n_main,13), "   /*---(beg scripts)--------------------*/");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_main) , 14);
   yUNIT_mindnoc ();

   yUNIT_mincond ("write the ending");
   CODE_cycle ();
   yUNIT_minval ("call end"                           , MAIN_end    (), 0);
   yUNIT_minstr ("... check (0) comment"              , yURG_peek (my.n_main, 0), "   /*---(end scripts)--------------------*/");
   yUNIT_minstr ("... check (1) tinu"                 , yURG_peek (my.n_main, 1), "   rc = yUNIT_tinu (g.exec);");
   yUNIT_minstr ("... check (2) comment"              , yURG_peek (my.n_main, 2), "   /*---(complete)-----------------------*/");
   yUNIT_minstr ("... check (3) return"               , yURG_peek (my.n_main, 3), "   return rc;");
   yUNIT_minstr ("... check (4) end brace"            , yURG_peek (my.n_main, 4), "}");
   yUNIT_minstr ("... check (5) empty"                , yURG_peek (my.n_main, 5), "");
   yUNIT_minstr ("... check (6) empty"                , yURG_peek (my.n_main, 6), "");
   yUNIT_minstr ("... check (7) empty"                , yURG_peek (my.n_main, 7), "");
   yUNIT_minstr ("... check (8) whimper"              , yURG_peek (my.n_main, 8), "/* end-of-file.  done, finito, completare, whimper [Ï´···                     */");
   yUNIT_minstr ("... check (9) final line"           , yURG_peek (my.n_main, 9), "/*================================= end-code =================================*/");
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
   yUNIT_minchr ("... check type"                     , my.type       , '-');
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "");
   CODE_cycle ();
   yUNIT_minval ("call prep"                          , CODE_prep   (), 0);
   yUNIT_minstr ("... check (0) empty"                , yURG_peek (my.n_code, 0), "");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) , 0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("handle an include line");
   strcpy (my.recd, "   incl  include public header  koios.h       ");
   my.n_line = 15;
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
   yUNIT_minchr ("... check type"                     , my.type       , '-');
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "");
   CODE_cycle ();
   yUNIT_minval ("call incl"                          , CODE_incl   (), 0);
   yUNIT_minstr ("... check (0) header marker"        , yURG_peek (my.n_code, 0), "#include    \"koios.h\"               /*   15, include public header            */");
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
   my.cscrp  =  0;
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
   yUNIT_minchr ("... check type"                     , my.type       , '-');
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "");
   CODE_cycle ();
   yUNIT_minval ("call scrp"                          , CODE_scrp   (), 0);
   yUNIT_minstr ("... check (0) empty"                , yURG_peek (my.n_code, 0), "");
   yUNIT_minstr ("... check (1) return type"          , yURG_peek (my.n_code, 1), "char");
   yUNIT_minstr ("... check (2) declaration"          , yURG_peek (my.n_code, 2), "yUNIT_script_01          (void)");
   yUNIT_minstr ("... check (3) open brace"           , yURG_peek (my.n_code, 3), "{");
   yUNIT_minstr ("... check (4) comment"              , yURG_peek (my.n_code, 4), "   /*===[[ script header ]]========================*/");
   yUNIT_minstr ("... check (5) local"                , yURG_peek (my.n_code, 5), "   g.offset  = 0;");
   yUNIT_minstr ("... check (6) local"                , yURG_peek (my.n_code, 6), "   g.origin  = 1;");
   yUNIT_minstr ("... check (7) script header"        , yURG_peek (my.n_code, 7), "   yUNIT_scrp    (  23,   1, \"ê3\", \"(SCRP) verify openning and closing\", \"SCRP_parse\");");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) ,  8);
   yUNIT_minstr ("check main entry"                   , yURG_peek (my.n_main, 0), "   if (g.scrp ==  0 || g.scrp ==  1)  yUNIT_script_01 ();");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_main) ,  1);
   yUNIT_mindnoc ();

   yUNIT_mincond ("second script beginning");
   strcpy (my.recd, "SCRP    [è5]  (SCRP) whatever comes next       ");
   my.n_line = 52;
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
   yUNIT_minchr ("... check type"                     , my.type       , '-');
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "");
   CODE_cycle ();
   yUNIT_minval ("call scrp"                          , CODE_scrp   (), 0);
   yUNIT_minstr ("... check (0) comment"              , yURG_peek (my.n_code, 0), "   /*===[[ script done ]]==========================*/");
   yUNIT_minstr ("... check (1) prcs footer"          , yURG_peek (my.n_code, 1), "   yUNIT_prcs    (g.exec);");
   yUNIT_minstr ("... check (2) comment"              , yURG_peek (my.n_code, 2), "   /*---(complete)-----------------------*/");
   yUNIT_minstr ("... check (3) return"               , yURG_peek (my.n_code, 3), "   return 0;");
   yUNIT_minstr ("... check (4) closing brace"        , yURG_peek (my.n_code, 4), "}");
   yUNIT_minstr ("... check (5) empty"                , yURG_peek (my.n_code, 5), "");
   yUNIT_minstr ("... check (6) return type"          , yURG_peek (my.n_code, 6), "char");
   yUNIT_minstr ("... check (7) declaration"          , yURG_peek (my.n_code, 7), "yUNIT_script_02          (void)");
   yUNIT_minstr ("... check (8) open brace"           , yURG_peek (my.n_code, 8), "{");
   yUNIT_minstr ("... check (9) comment"              , yURG_peek (my.n_code, 9), "   /*===[[ script header ]]========================*/");
   yUNIT_minstr ("... check (10) local"               , yURG_peek (my.n_code,10), "   g.offset  = 0;");
   yUNIT_minstr ("... check (11) local"               , yURG_peek (my.n_code,11), "   g.origin  = 2;");
   yUNIT_minstr ("... check (12) script header"       , yURG_peek (my.n_code,12), "   yUNIT_scrp    (  52,   2, \"è5\", \"(SCRP) whatever comes next\", \"\");");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) , 13);
   yUNIT_minstr ("check main entry"                   , yURG_peek (my.n_main, 0), "   if (g.scrp ==  0 || g.scrp ==  2)  yUNIT_script_02 ();");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_main) ,  1);
   yUNIT_mindnoc ();

   yUNIT_mincond ("second script beginning");
   strcpy (my.recd, "SHARED   -b-  remove temporary files       ");
   my.n_line = 300;
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
   yUNIT_minchr ("... check type"                     , my.type       , '-');
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "");
   CODE_cycle ();
   yUNIT_minval ("call shared"                        , CODE_shared (), 0);
   yUNIT_minstr ("... check (0) comment"              , yURG_peek (my.n_code, 0), "   /*===[[ script done ]]==========================*/");
   yUNIT_minstr ("... check (1) prcs footer"          , yURG_peek (my.n_code, 1), "   yUNIT_prcs    (g.exec);");
   yUNIT_minstr ("... check (2) comment"              , yURG_peek (my.n_code, 2), "   /*---(complete)-----------------------*/");
   yUNIT_minstr ("... check (3) return"               , yURG_peek (my.n_code, 3), "   return 0;");
   yUNIT_minstr ("... check (4) closing brace"        , yURG_peek (my.n_code, 4), "}");
   yUNIT_minstr ("... check (5) empty"                , yURG_peek (my.n_code, 5), "");
   yUNIT_minstr ("... check (6) return type"          , yURG_peek (my.n_code, 6), "char");
   yUNIT_minstr ("... check (7) definition"           , yURG_peek (my.n_code, 7), "yUNIT_shared_b           (void)");
   yUNIT_minstr ("... check (8) openning brace"       , yURG_peek (my.n_code, 8), "{");
   yUNIT_minstr ("... check (9) comment"              , yURG_peek (my.n_code, 9), "   /*===[[ shared header ]]========================*/");
   yUNIT_minstr ("... check (10) call shared"         , yURG_peek (my.n_code,10), "   yUNIT_share ('b', \"remove temporary files\");");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) , 11);
   yUNIT_minstr ("check main entry"                   , yURG_peek (my.n_main, 0), "");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_main) ,  0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("script after shared");
   strcpy (my.recd, "SCRP    [ÿ2]  (SCRP) last test       ");
   my.n_line = 99;
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
   yUNIT_minchr ("... check type"                     , my.type       , '-');
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "");
   CODE_cycle ();
   yUNIT_minval ("call scrp"                          , CODE_scrp   (), 0);
   yUNIT_minstr ("... check (0) comment"              , yURG_peek (my.n_code, 0), "   /*===[[ shared done ]]==========================*/");
   yUNIT_minstr ("... check (1) prcs footer"          , yURG_peek (my.n_code, 1), "   yUNIT_erahs ('b');");
   yUNIT_minstr ("... check (2) comment"              , yURG_peek (my.n_code, 2), "   /*---(complete)-----------------------*/");
   yUNIT_minstr ("... check (3) return"               , yURG_peek (my.n_code, 3), "   return 0;");
   yUNIT_minstr ("... check (4) closing brace"        , yURG_peek (my.n_code, 4), "}");
   yUNIT_minstr ("... check (5) empty"                , yURG_peek (my.n_code, 5), "");
   yUNIT_minstr ("... check (6) return type"          , yURG_peek (my.n_code, 6), "char");
   yUNIT_minstr ("... check (7) declaration"          , yURG_peek (my.n_code, 7), "yUNIT_script_03          (void)");
   yUNIT_minstr ("... check (8) open brace"           , yURG_peek (my.n_code, 8), "{");
   yUNIT_minstr ("... check (9) comment"              , yURG_peek (my.n_code, 9), "   /*===[[ script header ]]========================*/");
   yUNIT_minstr ("... check (10) local"               , yURG_peek (my.n_code,10), "   g.offset  = 0;");
   yUNIT_minstr ("... check (11) local"               , yURG_peek (my.n_code,11), "   g.origin  = 3;");
   yUNIT_minstr ("... check (12) script header"       , yURG_peek (my.n_code,12), "   yUNIT_scrp    (  99,   3, \"ÿ2\", \"(SCRP) last test\", \"\");");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) , 13);
   yUNIT_minstr ("check main entry"                   , yURG_peek (my.n_main, 0), "   if (g.scrp ==  0 || g.scrp ==  3)  yUNIT_script_03 ();");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_main) ,  1);
   yUNIT_mindnoc ();

   yUNIT_mincond ("write a section break");
   strcpy (my.recd, "SECT  file oriented         ");
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
   yUNIT_minstr ("... check (0) comment"              , yURG_peek (my.n_code, 0), "   /*===[[ script done ]]==========================*/");
   yUNIT_minstr ("... check (1) prcs footer"          , yURG_peek (my.n_code, 1), "   yUNIT_prcs    (g.exec);");
   yUNIT_minstr ("... check (2) comment"              , yURG_peek (my.n_code, 2), "   /*---(complete)-----------------------*/");
   yUNIT_minstr ("... check (3) return"               , yURG_peek (my.n_code, 3), "   return 0;");
   yUNIT_minstr ("... check (4) closing brace"        , yURG_peek (my.n_code, 4), "}");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) ,  5);
   yUNIT_minstr ("... check (0) comment"              , yURG_peek (my.n_main, 0), "   if (g.scrp ==  0)                  yUNIT_sect      (\"file oriented\");");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_main) ,  1);

   yUNIT_mincond ("attempt some bad shared conditions");
   strcpy (my.recd, "SHARED        remove temporary files       ");
   my.len = strlen (my.recd);
   my.n_line = 300;
   my.run_type = G_RUN_CREATE;
   yUNIT_minval ("parse the line"                     , SCRP_parse (), -999);
   yUNIT_minstr ("... check error message"            , yURG_err_last (), "/tmp/koios_scrp.unit:300:1: error: SHARED identifier not properly formatted -?-");
   strcpy (my.recd, "SHARED -b  testing        ");
   my.len = strlen (my.recd);
   my.n_line = 300;
   my.run_type = G_RUN_CREATE;
   yUNIT_minval ("parse a SHARED"                     , SCRP_parse  (), -999);
   yUNIT_minstr ("... check error message"            , yURG_err_last (), "/tmp/koios_scrp.unit:300:1: error: SHARED identifier not properly formatted -?-");
   strcpy (my.recd, "SHARED -è-  testing       ");
   my.len = strlen (my.recd);
   my.n_line = 300;
   my.run_type = G_RUN_CREATE;
   yUNIT_minval ("parse a SHARED"                     , SCRP_parse  (), -999);
   yUNIT_minstr ("... check error message"            , yURG_err_last (), "/tmp/koios_scrp.unit:300:1: error: SHARED identifier (è) not legal");
   strcpy (my.recd, "SHARE -b-  testing       ");
   my.len = strlen (my.recd);
   my.n_line = 300;
   my.run_type = G_RUN_CREATE;
   yUNIT_minval ("parse a SHARED"                     , SCRP_parse  (), -999);
   yUNIT_minstr ("... check error message"            , yURG_err_last (), "/tmp/koios_scrp.unit:300:1: error: verb <SHARE> not recognized/found");
   strcpy (my.recd, "SHAREY -b-  testing       ");
   my.len = strlen (my.recd);
   my.n_line = 300;
   my.run_type = G_RUN_CREATE;
   yUNIT_minval ("parse a SHARED"                     , SCRP_parse  (), -999);
   yUNIT_minstr ("... check error message"            , yURG_err_last (), "/tmp/koios_scrp.unit:300:1: error: verb <SHAREY> not recognized/found");
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify some valid variations");
   strcpy (my.recd, "SHARED   -b-  remove temporary files       ");
   my.len = strlen (my.recd);
   my.n_line = 300;
   yUNIT_minval ("parse a SHARED"                     , SCRP_parse  (), 0);
   yUNIT_minstr ("... check verb"                     , my.verb          , "SHARED");
   strcpy (my.recd, "SHARED -2-  testing       ");
   my.len = strlen (my.recd);
   my.n_line = 300;
   my.run_type = G_RUN_CREATE;
   yUNIT_minval ("parse a SHARED"                     , SCRP_parse  (), 0);
   strcpy (my.recd, "SHARED -A-  testing       ");
   my.n_line = 300;
   my.run_type = G_RUN_CREATE;
   yUNIT_minval ("parse a SHARED"                     , SCRP_parse  (), 0);

   yUNIT_mincond ("attempt some bad scrp verbs");
   strcpy (my.recd, "SCRI          (SCRP) last test       ");
   my.len = strlen (my.recd);
   my.n_line = 99;
   my.run_type = G_RUN_CREATE;
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), -999);
   yUNIT_minstr ("... check error message"            , yURG_err_last (), "/tmp/koios_scrp.unit:99:1: error: verb <SCRI> not recognized/found");
   strcpy (my.recd, "SCRIPT  [ÿ2]  (SCRP) last test       ");
   my.n_line = 99;
   my.run_type = G_RUN_CREATE;
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), -999);
   yUNIT_minstr ("... check error message"            , yURG_err_last (), "/tmp/koios_scrp.unit:99:1: error: verb <SCRIPT> not recognized/found");
   strcpy (my.recd, "SCRP    [aa]  (SCRP) last test       ");
   my.n_line = 99;
   my.run_type = G_RUN_CREATE;
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), -999);
   yUNIT_minstr ("... check error message"            , yURG_err_last (), "/tmp/koios_scrp.unit:99:1: error: SCRP identifier, not greek letter for wave, e.g., [ì4]");
   strcpy (my.recd, "SCRP    [ég]  (SCRP) last test       ");
   my.n_line = 99;
   my.run_type = G_RUN_CREATE;
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), -999);
   yUNIT_minstr ("... check error message"            , yURG_err_last (), "/tmp/koios_scrp.unit:99:1: error: SCRP identifier, not number for stage, e.g., [ì4]");
   strcpy (my.recd, "SCRP    (é2)  (SCRP) last test       ");
   my.n_line = 99;
   my.run_type = G_RUN_CREATE;
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), -999);
   yUNIT_minstr ("... check error message"            , yURG_err_last (), "/tmp/koios_scrp.unit:99:1: error: SCRP identifier, uses wrong brackets, e.g., [ì4]");
   strcpy (my.recd, "SCRP    -é2   (SCRP) last test       ");
   my.n_line = 99;
   my.run_type = G_RUN_CREATE;
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), -999);
   yUNIT_minstr ("... check error message"            , yURG_err_last (), "/tmp/koios_scrp.unit:99:1: error: SCRP identifier, uses wrong brackets, e.g., [ì4]");
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify some valid variations");
   strcpy (my.recd, "SCRP    [--]  (SCRP) last test       ");
   my.n_line = 99;
   my.run_type = G_RUN_CREATE;
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), 0);
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
   strcpy (my.recd, "COND (A)  verify defenses       ");
   my.n_line   = 32;
   my.ccond    =  0;
   my.run_type = G_RUN_DEBUG;
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "COND (A) § verify defenses §  §  §  §");
   yUNIT_minstr ("... check verb"                     , my.verb       , "COND");
   yUNIT_minstr ("... check stage"                    , my.stage      , "");
   yUNIT_minchr ("... check share"                    , my.share      , '-');
   yUNIT_minchr ("... check mark"                     , my.mark       , 'A');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "verify defenses");
   yUNIT_minstr ("... check method"                   , my.meth       , "");
   yUNIT_minstr ("... check arguments"                , my.args       , "");
   yUNIT_minstr ("... check test"                     , my.test       , "");
   yUNIT_minstr ("... check expect"                   , my.expe       , "");
   yUNIT_minchr ("... check type"                     , my.type       , '-');
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "");
   CODE_cycle ();
   yUNIT_minval ("call cond"                          , CODE_cond   (), 0);
   yUNIT_minstr ("... check (0) lead comment"         , yURG_peek (my.n_code, 0), "   /*===[[ COND #001 ]]============================*/");
   yUNIT_minstr ("... check (1) set noise level"      , yURG_peek (my.n_code, 1), "   if (g.cond == g.offset +   1)  yUNIT_level (YUNIT_FULL, 'y'); else yUNIT_level (g.level, 'y');");
   yUNIT_minstr ("... check (2) debugging"            , yURG_peek (my.n_code, 2), "   DEBUG_TOPS    yLOG_unitcond (g.origin, g.offset +   1,   32, \"verify defenses\");");
   yUNIT_minstr ("... check (3) condition notice"     , yURG_peek (my.n_code, 3), "   yUNIT_cond    (  32, g.offset +   1, '-', \"verify defenses\");");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) ,  4);
   yUNIT_minstr ("check main entry"                   , yURG_peek (my.n_main, 0), "");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_main) ,  0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("second condition beginning");
   strcpy (my.recd, "COND  verify null handling       ");
   my.n_line   = 34;
   my.run_type = G_RUN_CREATE;
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
   yUNIT_minchr ("... check type"                     , my.type       , '-');
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "");
   CODE_cycle ();
   yUNIT_minval ("call cond"                          , CODE_cond   (), 0);
   yUNIT_minstr ("... check (0) final comment"        , yURG_peek (my.n_code, 0), "      /*---(summary)---------------------*/");
   yUNIT_minstr ("... check (1) dnoc reporting"       , yURG_peek (my.n_code, 1), "      yUNIT_dnoc    (g.exec);");
   yUNIT_minstr ("... check (2) final comment"        , yURG_peek (my.n_code, 2), "      /*---(done)------------------------*/");
   yUNIT_minstr ("... check (3) lead comment"         , yURG_peek (my.n_code, 3), "   /*===[[ COND #002 ]]============================*/");
   yUNIT_minstr ("... check (4) set noise level"      , yURG_peek (my.n_code, 4), "   if (g.cond == g.offset +   2)  yUNIT_level (YUNIT_FULL, 'y'); else yUNIT_level (g.level, 'y');");
   yUNIT_minstr ("... check (5) condition notice"     , yURG_peek (my.n_code, 5), "   yUNIT_cond    (  34, g.offset +   2, '-', \"verify null handling\");");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) ,  6);
   yUNIT_minstr ("check main entry"                   , yURG_peek (my.n_main, 0), "");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_main) ,  0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("condition group");
   strcpy (my.recd, "GROUP  more complex defenses       ");
   my.n_line   = 36;
   my.run_type = G_RUN_CREATE;
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
   yUNIT_minchr ("... check type"                     , my.type       , '-');
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "");
   CODE_cycle ();
   yUNIT_minval ("call group"                         , CODE_group  (), 0);
   yUNIT_minstr ("... check (0) final comment"        , yURG_peek (my.n_code, 0), "      /*---(summary)---------------------*/");
   yUNIT_minstr ("... check (1) dnoc reporting"       , yURG_peek (my.n_code, 1), "      yUNIT_dnoc    (g.exec);");
   yUNIT_minstr ("... check (2) final comment"        , yURG_peek (my.n_code, 2), "      /*---(done)------------------------*/");
   yUNIT_minstr ("... check (3) comment"              , yURG_peek (my.n_code, 3), "   /*---(group)--------------------------*/");
   yUNIT_minstr ("... check (4) group reporting"      , yURG_peek (my.n_code, 4), "   yUNIT_group   (\"more complex defenses\");");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) ,  5);
   yUNIT_minstr ("check main entry"                   , yURG_peek (my.n_main, 0), "");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_main) ,  0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("condition reuse");
   strcpy (my.recd, "REUSE -b-         ");
   my.n_line   = 38;
   my.run_type = G_RUN_CREATE;
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
   yUNIT_minchr ("... check type"                     , my.type       , '-');
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "");
   CODE_cycle ();
   yUNIT_minval ("call reuse"                         , CODE_reuse  (), 0);
   yUNIT_minstr ("... check (0) comment"              , yURG_peek (my.n_code, 0), "   /*---(shared code)-----------------------*/");
   yUNIT_minstr ("... check (1) prepare offset"       , yURG_peek (my.n_code, 1), "   g.offset =   2;");
   yUNIT_minstr ("... check (2) call share"           , yURG_peek (my.n_code, 2), "   yUNIT_shared_b ();");
   yUNIT_minstr ("... check (3) reset offset"         , yURG_peek (my.n_code, 3), "   g.offset = 0;");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) ,  4);
   yUNIT_minstr ("check main entry"                   , yURG_peek (my.n_main, 0), "");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_main) ,  0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("attempt some bad reuse conditions");
   strcpy (my.recd, "REUSE             ");
   my.n_line   = 38;
   my.run_type = G_RUN_CREATE;
   yUNIT_minval ("parse a REUSE"                      , SCRP_parse  (), -999);
   yUNIT_minstr ("... check error message"            , yURG_err_last (), "/tmp/koios_scrp.unit:38:1: error: REUSE identifier not properly formatted -?-");
   strcpy (my.recd, "REUSE -b          ");
   my.n_line   = 38;
   my.run_type = G_RUN_CREATE;
   yUNIT_minval ("parse a REUSE"                      , SCRP_parse  (), -999);
   yUNIT_minstr ("... check error message"            , yURG_err_last (), "/tmp/koios_scrp.unit:38:1: error: REUSE identifier not properly formatted -?-");
   strcpy (my.recd, "REUSE -è-         ");
   my.n_line   = 38;
   my.run_type = G_RUN_CREATE;
   yUNIT_minval ("parse a REUSE"                      , SCRP_parse  (), -999);
   yUNIT_minstr ("... check error message"            , yURG_err_last (), "/tmp/koios_scrp.unit:38:1: error: REUSE identifier (è) not legal");
   strcpy (my.recd, "REUSED -b-         ");
   my.n_line   = 38;
   my.run_type = G_RUN_CREATE;
   yUNIT_minval ("parse a REUSE"                      , SCRP_parse  (), -999);
   yUNIT_minstr ("... check error message"            , yURG_err_last (), "/tmp/koios_scrp.unit:38:1: error: verb <REUSED> not recognized/found");
   strcpy (my.recd, "REUS   -b-         ");
   my.n_line   = 38;
   my.run_type = G_RUN_CREATE;
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
   yUNIT_minchr ("... check type"                     , my.type       , '-');
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "");
   CODE_cycle ();
   yUNIT_minval ("call cond"                          , CODE_mode   (), 0);
   yUNIT_minstr ("... check (0) lead comment"         , yURG_peek (my.n_code, 0), "      /*---(mode)------------------------*/");
   yUNIT_minstr ("... check (1) set mode"             , yURG_peek (my.n_code, 1), "      yUNIT_mode    (  40,   3, \"FORCED_FAIL\", g.exec);");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) ,  2);
   yUNIT_minstr ("check main entry"                   , yURG_peek (my.n_main, 0), "");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_main) ,  0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("code step");
   strcpy (my.recd, "code  working variables    int a = 37;  ");
   my.n_line   = 40;
   my.cstep    =  2;
   my.run_type = G_RUN_DEBUG;
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "code § working variables §  § int a = 37;  §");
   yUNIT_minstr ("... check verb"                     , my.verb       , "code");
   yUNIT_minstr ("... check stage"                    , my.stage      , "");
   yUNIT_minchr ("... check share"                    , my.share      , '-');
   yUNIT_minchr ("... check mark"                     , my.mark       , '-');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "working variables");
   yUNIT_minstr ("... check method"                   , my.meth       , "");
   yUNIT_minstr ("... check arguments"                , my.args       , "");
   yUNIT_minstr ("... check test"                     , my.test       , "");
   yUNIT_minstr ("... check expect"                   , my.expe       , "");
   yUNIT_minchr ("... check type"                     , my.type       , '-');
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "int a = 37;");
   CODE_cycle ();
   yUNIT_minval ("call cond"                          , CODE_code   (), 0);
   yUNIT_minstr ("... check (0) lead comment"         , yURG_peek (my.n_code, 0), "      /*---(inject code)-----------------*/");
   yUNIT_minstr ("... check (1) show command"         , yURG_peek (my.n_code, 1), "      int a = 37;");
   yUNIT_minstr ("... check (2) execute code"         , yURG_peek (my.n_code, 2), "      yUNIT_code    (  40,   3, \"working variables\", \"int a = 37;\", g.exec);");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) ,  3);
   yUNIT_minstr ("check main entry"                   , yURG_peek (my.n_main, 0), "");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_main) ,  0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("load step");
   strcpy (my.recd, "load  fill out screen  stdin  hello;  15.6 ");
   my.n_line   = 40;
   my.cstep    =  2;
   my.run_type = G_RUN_DEBUG;
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
   yUNIT_minchr ("... check type"                     , my.type       , '-');
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "hello;  15.6");
   CODE_cycle ();
   yUNIT_minval ("call cond"                          , CODE_load   (), 0);
   yUNIT_minstr ("... check (0) lead comment"         , yURG_peek (my.n_code, 0), "      /*---(load input)------------------*/");
   yUNIT_minstr ("... check (1) report and execute"   , yURG_peek (my.n_code, 1), "      yUNIT_load    (  40,   3, \"fill out screen\", \"stdin\", \"hello;  15.6\", g.exec);");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) ,  2);
   yUNIT_minstr ("check main entry"                   , yURG_peek (my.n_main, 0), "");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_main) ,  0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("system step");
   strcpy (my.recd, "system  delete temporary file    rm -f /tmp/koios_unit.cs ");
   my.n_line   = 40;
   my.cstep    =  2;
   my.run_type = G_RUN_DEBUG;
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
   yUNIT_minchr ("... check type"                     , my.type       , '-');
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "rm -f /tmp/koios_unit.cs");
   CODE_cycle ();
   yUNIT_minval ("call cond"                          , CODE_system (), 0);
   yUNIT_minstr ("... check (0) lead comment"         , yURG_peek (my.n_code, 0), "      /*---(system/execute)--------------*/");
   yUNIT_minstr ("... check (1) execute and report"   , yURG_peek (my.n_code, 1), "      yUNIT_system  (  40,   3, \"delete temporary file\", \"rm -f /tmp/koios_unit.cs\", \"rm -f /tmp/koios_unit.cs\", g.exec);");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) ,  2);
   yUNIT_minstr ("check main entry"                   , yURG_peek (my.n_main, 0), "");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_main) ,  0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("echo step (real)");
   strcpy (my.recd, "echo  check length    l  r_equal  13.6 ");
   my.n_line   = 40;
   my.cstep    =  2;
   my.run_type = G_RUN_DEBUG;
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
   yUNIT_minchr ("... check type"                     , my.type       , '-');
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "l");
   CODE_cycle ();
   yUNIT_minval ("call cond"                          , CODE_echo   (), 0);
   yUNIT_minstr ("... check (0) lead comment"         , yURG_peek (my.n_code, 0), "      /*---(echo/verify)-----------------*/");
   yUNIT_minstr ("... check (1) execute and report"   , yURG_peek (my.n_code, 1), "      yUNIT_real    (  40,   3, \"check length\", \"echo\", \"l\", \"r_equal\", 13.6, l, g.exec);");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) ,  2);
   yUNIT_minstr ("check main entry"                   , yURG_peek (my.n_main, 0), "");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_main) ,  0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("echo step (int)");
   strcpy (my.recd, "echo  check length    l  i_lesser  13.6 ");
   my.n_line   = 40;
   my.cstep    =  2;
   my.run_type = G_RUN_DEBUG;
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
   yUNIT_minchr ("... check type"                     , my.type       , '-');
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "l");
   CODE_cycle ();
   yUNIT_minval ("call cond"                          , CODE_echo   (), 0);
   yUNIT_minstr ("... check (0) lead comment"         , yURG_peek (my.n_code, 0), "      /*---(echo/verify)-----------------*/");
   yUNIT_minstr ("... check (1) execute and report"   , yURG_peek (my.n_code, 1), "      yUNIT_int     (  40,   3, \"check length\", \"echo\", \"l\", \"i_lesser\", 13.6, l, g.exec);");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) ,  2);
   yUNIT_minstr ("check main entry"                   , yURG_peek (my.n_main, 0), "");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_main) ,  0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("echo step (string)");
   strcpy (my.recd, "echo  check length    l  s_not  13.6 ");
   my.n_line   = 40;
   my.cstep    =  2;
   my.run_type = G_RUN_DEBUG;
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
   yUNIT_minchr ("... check type"                     , my.type       , '-');
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "l");
   CODE_cycle ();
   yUNIT_minval ("call cond"                          , CODE_echo   (), 0);
   yUNIT_minstr ("... check (0) lead comment"         , yURG_peek (my.n_code, 0), "      /*---(echo/verify)-----------------*/");
   yUNIT_minstr ("... check (1) execute and report"   , yURG_peek (my.n_code, 1), "      yUNIT_string  (  40,   3, \"check length\", \"echo\", \"l\", \"s_not\", \"13.6\", l, g.exec);");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) ,  2);
   yUNIT_minstr ("check main entry"                   , yURG_peek (my.n_main, 0), "");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_main) ,  0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("echo step (pointer)");
   strcpy (my.recd, "echo  check length    l  p_null  13.6 ");
   my.n_line   = 40;
   my.cstep    =  2;
   my.run_type = G_RUN_DEBUG;
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
   yUNIT_minchr ("... check type"                     , my.type       , '-');
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "l");
   CODE_cycle ();
   yUNIT_minval ("call cond"                          , CODE_echo   (), 0);
   yUNIT_minstr ("... check (0) lead comment"         , yURG_peek (my.n_code, 0), "      /*---(echo/verify)-----------------*/");
   yUNIT_minstr ("... check (1) execute and report"   , yURG_peek (my.n_code, 1), "      yUNIT_point   (  40,   3, \"check length\", \"echo\", \"l\", \"p_null\", 13.6, l, g.exec);");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) ,  2);
   yUNIT_minstr ("check main entry"                   , yURG_peek (my.n_main, 0), "");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_main) ,  0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("echo step (round)");
   strcpy (my.recd, "echo  check length    l  u_round/3  13.6 ");
   my.n_line   = 40;
   my.cstep    =  2;
   my.run_type = G_RUN_DEBUG;
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
   yUNIT_minchr ("... check type"                     , my.type       , '-');
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "l");
   CODE_cycle ();
   yUNIT_minval ("call cond"                          , CODE_echo   (), 0);
   yUNIT_minstr ("... check (0) lead comment"         , yURG_peek (my.n_code, 0), "      /*---(echo/verify)-----------------*/");
   yUNIT_minstr ("... check (1) execute and report"   , yURG_peek (my.n_code, 1), "      yUNIT_round   (  40,   3, \"check length\", \"echo\", \"l\", \"u_round/3\", \"13.6\", l, g.exec);");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) ,  2);
   yUNIT_minstr ("check main entry"                   , yURG_peek (my.n_main, 0), "");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_main) ,  0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("exec step");
   strcpy (my.recd, "exec  check length  test_func  27, 36  s_equal  13.6 ");
   my.n_line   = 40;
   my.cstep    =  2;
   my.run_type = G_RUN_DEBUG;
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
   yUNIT_minchr ("... check type"                     , my.type       , '-');
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "27, 36");
   CODE_cycle ();
   yUNIT_minval ("call cond"                          , CODE_exec   (), 0);
   yUNIT_minstr ("... check (0) lead comment"         , yURG_peek (my.n_code, 0), "      /*---(run step)--------------------*/");
   yUNIT_minstr ("... check (1) debugging"            , yURG_peek (my.n_code, 1), "      DEBUG_TOPS    yLOG_unitstep (g.origin, g.offset +   2,   3,   40, \"check length\");");
   yUNIT_minstr ("... check (2) execute"              , yURG_peek (my.n_code, 2), "      yUNIT_string  (  40,   3, \"check length\", \"test_func\", \"27, 36\", \"s_equal\", \"13.6\", test_func (27, 36), g.exec);");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) ,  3);
   yUNIT_minstr ("check main entry"                   , yURG_peek (my.n_main, 0), "");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_main) ,  0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("get step");
   strcpy (my.recd, "get  ... verify length  test_unit  27, 36  i_equal  13.6 ");
   my.n_line   = 40;
   my.cstep    =  2;
   my.run_type = G_RUN_DEBUG;
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
   yUNIT_minchr ("... check type"                     , my.type       , '-');
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "27, 36");
   CODE_cycle ();
   yUNIT_minval ("call cond"                          , CODE_exec   (), 0);
   yUNIT_minstr ("... check (0) lead comment"         , yURG_peek (my.n_code, 0), "      /*---(run step)--------------------*/");
   yUNIT_minstr ("... check (1) debugging"            , yURG_peek (my.n_code, 1), "      DEBUG_TOPS    yLOG_unitstep (g.origin, g.offset +   2,   3,   40, \"... verify length\");");
   yUNIT_minstr ("... check (2) execute"              , yURG_peek (my.n_code, 2), "      yUNIT_int     (  40,   3, \"... verify length\", \"test_unit\", \"27, 36\", \"i_equal\", 13.6, test_unit (27, 36), g.exec);");
   yUNIT_minval ("... check line count"               , yURG_peek_count (my.n_code) ,  3);
   yUNIT_minstr ("check main entry"                   , yURG_peek (my.n_main, 0), "");
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
   yUNIT_mincond ("prepare a interesting example");
   system ("rm -f koios.unit 2> /dev/null");
   system ("echo \"#23456789-12  123456789-123456789-123456789-12345  123456789-123456  123456789-123456789-  123456789-  123456789-123456789-  -  123456789- \"   > koios.unit");
   system ("echo \"#==(verb)===  ===========(description)===========  =====(function)=  ====(arguments)=====  ==(test)==  ====(results)=======  t  =(var)==== \"  >> koios.unit");
   system ("echo \"SECT          simple testing                      \"                                                                                                       >> koios.unit");
   system ("echo \"SCRP    [ê1]  (SCRP) verify openning and closing                    \"                                                                                   >> koios.unit");
   system ("echo \"  COND        simple openning                     \"                                                                                                       >> koios.unit");
   system ("echo \"    exec      ... check string                     yUNIT_teststring  0                         s_equal     hello                 \"                >> koios.unit");
   system ("echo \"    exec      ... check number                     yUNIT_testreal    5                         r_greater   15.0                  \"                >> koios.unit");
   system ("echo \"    exec      ... check integer                    yUNIT_testint     32                        i_equal     2                     \"                >> koios.unit");
   system ("echo \"    exec      ... check character                  yUNIT_testchar    65                        i_equal     'A'                   \"                >> koios.unit");
   system ("echo \"  COND        defensive checks                    \"                                                                                                       >> koios.unit");
   system ("echo \"    load      ... prep data for read               stdin             one two three                                                   \"                >> koios.unit");
   system ("echo \"    get       ... check number                     yUNIT_testreal    5                         r_greater   15.0                  \"                >> koios.unit");
   system ("echo \"    exec      ... check integer                    yUNIT_testint     32                        i_equal     2                     \"                >> koios.unit");
   system ("echo \"    exec      ... check character                  yUNIT_testchar    65                        i_equal     'A'                   \"                >> koios.unit");
   system ("echo \"  COND        duplicate opens and closes          \"                                                                                                       >> koios.unit");
   system ("echo \"    code      ... working variables                - - - - - - - -   int c = 0;                                                      \"                >> koios.unit");
   system ("echo \"    echo      ... check working variable           - - - - - - - -   c                         i_equal     0                     \"                >> koios.unit");
   system ("echo \"    load      ... prep data for read               stdin             one two three                                                   \"                >> koios.unit");
   system ("echo \"    mode      FORCED_FAIL                         \"                                                                                                       >> koios.unit");
   system ("echo \"    system    ... run little                       - - - - - - - -   /bin/false                                                      \"                >> koios.unit");
   system ("echo \"SECT          more complex testing                \"                                                                                                       >> koios.unit");
   system ("echo \"SHARED   -A-  prepare files for use               \"                                                                                                       >> koios.unit");
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
   system ("echo \"SHARED   -B-  remove files after use              \"                                                                                                       >> koios.unit");
   system ("echo \"  COND        close and delete script file        \"                                                                                                       >> koios.unit");
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
   system ("echo \"  REUSE  -A-  - - - - - - - - - - - - - - - - -   \"                                                                                                       >> koios.unit");
   system ("echo \"  COND        parse a code record                 \"                                                                                                       >> koios.unit");
   system ("echo \"    exec      ... check string                     yUNIT_teststring  0                         s_equal     hello                 \"                >> koios.unit");
   system ("echo \"    exec      ... check number                     yUNIT_testreal    5                         r_greater   15.0                  \"                >> koios.unit");
   system ("echo \"    exec      ... check integer                    yUNIT_testint     32                        i_equal     2                     \"                >> koios.unit");
   system ("echo \"    exec      ... check character                  yUNIT_testchar    65                        i_equal     'A'                   \"                >> koios.unit");
   system ("echo \"SCRP    [ì2]  (SCRP) verify normal processing                       \"                                                                                   >> koios.unit");
   system ("echo \"  GROUP       round one                           \"                                                                                                       >> koios.unit");
   system ("echo \"  COND        process arguments                   \"                                                                                                       >> koios.unit");
   system ("echo \"    exec      ... check string                     yUNIT_teststring  0                         s_equal     hello                 \"                >> koios.unit");
   system ("echo \"    exec      ... check number                     yUNIT_testreal    5                         r_greater   15.0                  \"                >> koios.unit");
   system ("echo \"    exec      ... check integer                    yUNIT_testint     32                        i_equal     2                     \"                >> koios.unit");
   system ("echo \"    exec      ... check character                  yUNIT_testchar    65                        i_equal     'A'                   \"                >> koios.unit");
   system ("echo \"  REUSE  -A-  - - - - - - - - - - - - - - - - -   \"                                                                                                       >> koios.unit");
   system ("echo \"  COND        read one record                     \"                                                                                                       >> koios.unit");
   system ("echo \"    exec      ... check string                     yUNIT_teststring  1                         s_equal     hello                 \"                >> koios.unit");
   system ("echo \"    exec      ... check number                     yUNIT_testreal    2                         r_greater   15.0                  \"                >> koios.unit");
   system ("echo \"    exec      ... check integer                    yUNIT_testint     64                        i_equal     2                     \"                >> koios.unit");
   system ("echo \"    exec      ... check character                  yUNIT_testchar    87                        i_equal     'A'                   \"                >> koios.unit");
   system ("echo \"  GROUP       round two                           \"                                                                                                       >> koios.unit");
   system ("echo \"  COND        read a second record                \"                                                                                                       >> koios.unit");
   system ("echo \"    exec      ... check string                     yUNIT_teststring  0                         s_equal     hello                 \"                >> koios.unit");
   system ("echo \"    exec      ... check number                     yUNIT_testreal    5                         r_greater   15.0                  \"                >> koios.unit");
   system ("echo \"    exec      ... check integer                    yUNIT_testint     32                        i_equal     2                     \"                >> koios.unit");
   system ("echo \"    exec      ... check character                  yUNIT_testchar    65                        i_equal     'A'                   \"                >> koios.unit");
   system ("echo \"  REUSE  -B-  - - - - - - - - - - - - - - - - -   \"                                                                                                       >> koios.unit");
   system ("echo \"  GROUP       final round                         \"                                                                                                       >> koios.unit");
   system ("echo \"  COND        generate a summary                  \"                                                                                                       >> koios.unit");
   system ("echo \"    exec      ... check string                     yUNIT_teststring  0                         s_equal     hello                 \"                >> koios.unit");
   system ("echo \"    exec      ... check number                     yUNIT_testreal    5                         r_greater   15.0                  \"                >> koios.unit");
   system ("echo \"    exec      ... check integer                    yUNIT_testint     32                        i_equal     2                     \"                >> koios.unit");
   system ("echo \"    exec      ... check character                  yUNIT_testchar    65                        i_equal     'A'                   \"                >> koios.unit");
   system ("echo \"SCRP    [è9]  (SCRP) empty script                                   \"                                                                                   >> koios.unit");
   yUNIT_mindnoc ();

   yUNIT_mincond ("turn into a unit test");
   yUNIT_minval  ("... run koios"                      , system ("koios --create koios"), 999);
   yUNIT_minval  ("... copy to c"                      , system ("cp -f koios_unit.{cs,c}"), 0);
   yUNIT_minval  ("... compile"                        , system ("gcc -c koios_unit.c"), 0);
   yUNIT_minval  ("... link"                           , system ("gcc -o koios_unit koios_unit.o -lyUNIT"), 0);
   yUNIT_mindnoc ();

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
   yUNIT_minstr  ("... check (0) header line"          , yURG_peek (x_urun, 0), "yUNIT - heatherly unit testing framework ---------------------------------------(beg)");
   yUNIT_minstr  ("... check (1) empty line"           , yURG_peek (x_urun, 1), "");
   yUNIT_minstr  ("... check (2) section"              , yURG_peek (x_urun, 2), "SECT ===-------------------------- simple testing ---------------------------=== TCES");
   yUNIT_minstr  ("... check (3) empty line"           , yURG_peek (x_urun, 3), "");
   yUNIT_minstr  ("... check (4) script"               , yURG_peek (x_urun, 4), "SCRP [01] (SCRP) verify openning and closing ============================[ê1]=[00004]");
   yUNIT_minstr  ("... check (5) empty line"           , yURG_peek (x_urun, 5), "");
   yUNIT_minstr  ("... check (6) section"              , yURG_peek (x_urun, 6), "SECT ===----------------------- more complex testing ------------------------=== TCES");
   yUNIT_minstr  ("... check (7) empty line"           , yURG_peek (x_urun, 7), "");
   yUNIT_minstr  ("... check (8) script"               , yURG_peek (x_urun, 8), "SCRP [02] (SCRP) verify system startup ==================================[ê2]=[00044]");
   yUNIT_minstr  ("... check (9) empty line"           , yURG_peek (x_urun, 9), "");
   yUNIT_minstr  ("... check (10) script"              , yURG_peek (x_urun,10), "SCRP [03] (SCRP) verify normal processing ===============================[ì2]=[00052]");
   yUNIT_minstr  ("... check (11) empty line"          , yURG_peek (x_urun,11), "");
   yUNIT_minstr  ("... check (12) script"              , yURG_peek (x_urun,12), "SCRP [04] (SCRP) empty script ===========================================[è9]=[00078]");
   yUNIT_minstr  ("... check (13) empty line"          , yURG_peek (x_urun,13), "");
   yUNIT_minstr  ("... check (14) test footer"         , yURG_peek (x_urun,14), "TINU  scrp=4    cond=15    test=57    [ ------------------------------------------- ]");
   yUNIT_minstr  ("... check (15) empty line"          , yURG_peek (x_urun,15), "");
   yUNIT_minstr  ("... check (16) footer line"         , yURG_peek (x_urun,16), "yUNIT - heatherly unit testing framework ---------------------------------------(end)");
   yUNIT_minval  ("... check line count"               , yURG_peek_count (x_urun) , 17);
   yUNIT_minstr  ("check wave entry"                   , yURG_peek (x_wave, 0), "ê  1  koios                       1  (SCRP) verify openning and closing                                ");
   yUNIT_minstr  ("check wave entry"                   , yURG_peek (x_wave, 1), "ê  2  koios                       2  (SCRP) verify system startup                                      ");
   yUNIT_minstr  ("check wave entry"                   , yURG_peek (x_wave, 2), "ì  2  koios                       3  (SCRP) verify normal processing                                   ");
   yUNIT_minstr  ("check wave entry"                   , yURG_peek (x_wave, 3), "è  9  koios                       4  (SCRP) empty script                                               ");
   yUNIT_minval  ("... check line count"               , yURG_peek_count (x_wave) ,  4);
   yUNIT_mindnoc ();

   yUNIT_mincond ("check inventory of one script only");
   yUNIT_minval  ("... run unit test"                  , system ("./koios_unit --scrps 03"), 0);
   yUNIT_minstr  ("... check (  0) header line"        , yURG_peek (x_urun,  0), "yUNIT - heatherly unit testing framework ---------------------------------------(beg)");
   yUNIT_minstr  ("... check (  1) empty line"         , yURG_peek (x_urun,  1), "");
   yUNIT_minstr  ("... check (  2) script"             , yURG_peek (x_urun,  2), "SCRP [03] (SCRP) verify normal processing ===============================[ì2]=[00052]");
   yUNIT_minstr  ("... check (  3) empty line"         , yURG_peek (x_urun,  3), "");
   yUNIT_minstr  ("... check (  4) test footer"        , yURG_peek (x_urun,  4), "TINU  scrp=1    cond=8     test=32    [ ------------------------------------------- ]");
   yUNIT_minstr  ("... check (  5) empty line"         , yURG_peek (x_urun,  5), "");
   yUNIT_minstr  ("... check (  6) footer line"        , yURG_peek (x_urun,  6), "yUNIT - heatherly unit testing framework ---------------------------------------(end)");
   yUNIT_minval  ("... check line count"               , yURG_peek_count (x_urun) ,  7);
   yUNIT_mindnoc ();

   yUNIT_mincond ("check running and presenting scripts only");
   yUNIT_minval  ("... run unit test"                  , system ("./koios_unit --scrp"), 999);
   yUNIT_minstr  ("... check ( 0) header line"         , yURG_peek (x_urun, 0), "yUNIT - heatherly unit testing framework ---------------------------------------(beg)");
   yUNIT_minstr  ("... check ( 1) empty line"          , yURG_peek (x_urun, 1), "");
   yUNIT_minstr  ("... check ( 2) section"             , yURG_peek (x_urun, 2), "SECT ===-------------------------- simple testing ---------------------------=== TCES");
   yUNIT_minstr  ("... check ( 3) empty line"          , yURG_peek (x_urun, 3), "");
   yUNIT_minstr  ("... check ( 4) script"              , yURG_peek (x_urun, 4), "SCRP [01] (SCRP) verify openning and closing ============================[ê1]=[00004]");
   yUNIT_minstr  ("... check ( 5) script footer"       , yURG_peek (x_urun, 5), "  " BACK_RED "PRCS -------- cond=3     test=13    [ pass=12    fail=1     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... check ( 6) empty line"          , yURG_peek (x_urun, 6), "");
   yUNIT_minstr  ("... check ( 7) section"             , yURG_peek (x_urun, 7), "SECT ===----------------------- more complex testing ------------------------=== TCES");
   yUNIT_minstr  ("... check ( 8) empty line"          , yURG_peek (x_urun, 8), "");
   yUNIT_minstr  ("... check ( 9) script"              , yURG_peek (x_urun, 9), "SCRP [02] (SCRP) verify system startup ==================================[ê2]=[00044]");
   yUNIT_minstr  ("... check (10) script footer"       , yURG_peek (x_urun,10), "  " BACK_RED "PRCS -------- cond=4     test=12    [ pass=9     fail=3     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... check (11) empty line"          , yURG_peek (x_urun,11), "");
   yUNIT_minstr  ("... check (12) script"              , yURG_peek (x_urun,12), "SCRP [03] (SCRP) verify normal processing ===============================[ì2]=[00052]");
   yUNIT_minstr  ("... check (13) script footer"       , yURG_peek (x_urun,13), "  " BACK_RED "PRCS -------- cond=8     test=32    [ pass=28    fail=4     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... check (14) empty line"          , yURG_peek (x_urun,14), "");
   yUNIT_minstr  ("... check (15) script"              , yURG_peek (x_urun,15), "SCRP [04] (SCRP) empty script ===========================================[è9]=[00078]");
   yUNIT_minstr  ("... check (16) script footer"       , yURG_peek (x_urun,16), "  " BACK_YEL "PRCS -------- cond=0     test=0     [ pass=0     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... check (17) empty line"          , yURG_peek (x_urun,17), "");
   yUNIT_minstr  ("... check (18) test footer"         , yURG_peek (x_urun,18), BACK_RED "TINU  scrp=4    cond=15    test=57    [ pass=49    fail=8     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... check (19) empty line"          , yURG_peek (x_urun,19), "");
   yUNIT_minstr  ("... check (20) footer line"         , yURG_peek (x_urun,20), "yUNIT - heatherly unit testing framework ---------------------------------------(end)");
   yUNIT_minval  ("... check line count"               , yURG_peek_count (x_urun) , 21);
   yUNIT_mindnoc ();

   yUNIT_mincond ("check running and presenting only one script");
   yUNIT_minval  ("... run unit test"                  , system ("./koios_unit --scrp 02"), 0);
   yUNIT_minstr  ("... check (  0) header line"        , yURG_peek (x_urun,  0), "yUNIT - heatherly unit testing framework ---------------------------------------(beg)");
   yUNIT_minstr  ("... check (  1) empty line"         , yURG_peek (x_urun,  1), "");
   yUNIT_minstr  ("... check (  2) script"             , yURG_peek (x_urun,  2), "SCRP [02] (SCRP) verify system startup ==================================[ê2]=[00044]");
   yUNIT_minstr  ("... check (  3) script footer"      , yURG_peek (x_urun,  3), "  " BACK_GRN "PRCS -------- cond=4     test=12    [ pass=12    fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... check (  4) empty line"         , yURG_peek (x_urun,  4), "");
   yUNIT_minstr  ("... check (  5) test footer"        , yURG_peek (x_urun,  5), BACK_GRN "TINU  scrp=1    cond=4     test=12    [ pass=12    fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... check (  6) empty line"         , yURG_peek (x_urun,  6), "");
   yUNIT_minstr  ("... check (  7) footer line"        , yURG_peek (x_urun,  7), "yUNIT - heatherly unit testing framework ---------------------------------------(end)");
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

   yUNIT_mincond ("check displaying conditions");
   yUNIT_minval  ("... run unit test"                  , system ("./koios_unit --conds"), 0);
   yUNIT_minstr  ("... check (0) header line"          , yURG_peek (x_urun, 0), "yUNIT - heatherly unit testing framework ---------------------------------------(beg)");
   yUNIT_minstr  ("... check (1) patron"               , yURG_peek (x_urun, 1), "   patron : daktyloi-aeonius (forefinger) automated unit testing                   4s");
   yUNIT_minstr  ("... check (2) level line"           , yURG_peek (x_urun, 2), "   assign output level to (3) YUNIT_COND                                          19c");
   yUNIT_minstr  ("... check (3) eterm line"           , yURG_peek (x_urun, 3), "   assign format/color to (y) ETERM                                               49x");
   yUNIT_minstr  ("... check (4) empty line"           , yURG_peek (x_urun, 4), "");
   yUNIT_minstr  ("... check (5) empty line"           , yURG_peek (x_urun, 5), "");
   yUNIT_minstr  ("... check (6) section"              , yURG_peek (x_urun, 6), "=========================------------------------------------========================");
   yUNIT_minstr  ("... check (7) section"              , yURG_peek (x_urun, 7), "SECT ===-------------------------- simple testing ---------------------------=== TCES");
   yUNIT_minstr  ("... check (8) section"              , yURG_peek (x_urun, 8), "=========================------------------------------------========================");
   yUNIT_minstr  ("... check (9) empty line"           , yURG_peek (x_urun, 9), "");
   yUNIT_minstr  ("... check (10) empty line"          , yURG_peek (x_urun,10), "");
   yUNIT_minstr  ("... check (11) script"              , yURG_peek (x_urun,11), "SCRP [01] (SCRP) verify openning and closing ============================[ê1]=[00004]");
   yUNIT_minstr  ("... check (12) empty line"          , yURG_peek (x_urun,12), "");
   yUNIT_minstr  ("... check (13) condition"           , yURG_peek (x_urun,13), "  COND [001] simple openning -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00005]");
   yUNIT_minstr  ("... check (14) empty line"          , yURG_peek (x_urun,14), "");
   yUNIT_minstr  ("... check (15) condition"           , yURG_peek (x_urun,15), "  COND [002] defensive checks - -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00010]");
   yUNIT_minstr  ("... check (16) empty line"          , yURG_peek (x_urun,16), "");
   yUNIT_minstr  ("... check (17) condition"           , yURG_peek (x_urun,17), "  COND [003] duplicate opens and closes  -- -- -- -- -- -- -- -- -- -- -- -- -[00015]");
   yUNIT_minstr  ("... check (18) empty line"          , yURG_peek (x_urun,18), "");
   yUNIT_minstr  ("... check (19) script footer"       , yURG_peek (x_urun,19), "  PRCS -------- cond=3     test=13    [ ------------------------------------------- ]");
   yUNIT_minstr  ("... check (20) empty line"          , yURG_peek (x_urun,20), "");
   yUNIT_minstr  ("... check (21) empty line"          , yURG_peek (x_urun,21), "");
   yUNIT_minstr  ("... check (22) section"             , yURG_peek (x_urun,22), "=========================------------------------------------========================");
   yUNIT_minstr  ("... check (23) section"             , yURG_peek (x_urun,23), "SECT ===----------------------- more complex testing ------------------------=== TCES");
   yUNIT_minstr  ("... check (24) section"             , yURG_peek (x_urun,24), "=========================------------------------------------========================");
   yUNIT_minstr  ("... check (25) empty line"          , yURG_peek (x_urun,25), "");
   yUNIT_minstr  ("... check (26) empty line"          , yURG_peek (x_urun,26), "");
   yUNIT_minstr  ("... check (27) script"              , yURG_peek (x_urun,27), "SCRP [02] (SCRP) verify system startup ==================================[ê2]=[00044]");
   yUNIT_minstr  ("... check (28) empty line"          , yURG_peek (x_urun,28), "");
   yUNIT_minstr  ("... check (29) condition"           , yURG_peek (x_urun,29), "  COND [001] run initialization -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00045]");
   yUNIT_minstr  ("... check (30) empty line"          , yURG_peek (x_urun,30), "");
   yUNIT_minstr  ("... check (31) condition"           , yURG_peek (x_urun,31), "  " BACK_MAG "SOND [002]" BACK_OFF " script input file  -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00023]");
   yUNIT_minstr  ("... check (32) empty line"          , yURG_peek (x_urun,32), "");
   yUNIT_minstr  ("... check (33) condition"           , yURG_peek (x_urun,33), "  " BACK_MAG "SOND [003]" BACK_OFF " code output file - -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00028]");
   yUNIT_minstr  ("... check (34) empty line"          , yURG_peek (x_urun,34), "");
   yUNIT_minstr  ("... check (35) condition"           , yURG_peek (x_urun,35), "  COND [004] parse a code record - -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00047]");
   yUNIT_minstr  ("... check (36) empty line"          , yURG_peek (x_urun,36), "");
   yUNIT_minstr  ("... check (37) script footer"       , yURG_peek (x_urun,37), "  PRCS -------- cond=4     test=12    [ ------------------------------------------- ]");
   yUNIT_minstr  ("... check (38) empty line"          , yURG_peek (x_urun,38), "");
   yUNIT_minstr  ("... check (39) empty line"          , yURG_peek (x_urun,39), "");
   yUNIT_minstr  ("... check (40) script"              , yURG_peek (x_urun,40), "SCRP [03] (SCRP) verify normal processing ===============================[ì2]=[00052]");
   yUNIT_minstr  ("... check (41) empty line"          , yURG_peek (x_urun,41), "");
   yUNIT_minstr  ("... check (42) group break"         , yURG_peek (x_urun,42), "  GROUP ===----------------------------   round one   ----------------------------===");
   yUNIT_minstr  ("... check (43) empty line"          , yURG_peek (x_urun,43), "");
   yUNIT_minstr  ("... check (44) condition"           , yURG_peek (x_urun,44), "  COND [001] process arguments  -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00054]");
   yUNIT_minstr  ("... check (45) empty line"          , yURG_peek (x_urun,45), "");
   yUNIT_minstr  ("... check (46) condition"           , yURG_peek (x_urun,46), "  " BACK_MAG "SOND [002]" BACK_OFF " script input file  -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00023]");
   yUNIT_minstr  ("... check (47) empty line"          , yURG_peek (x_urun,47), "");
   yUNIT_minstr  ("... check (48) condition"           , yURG_peek (x_urun,48), "  " BACK_MAG "SOND [003]" BACK_OFF " code output file - -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00028]");
   yUNIT_minstr  ("... check (49) empty line"          , yURG_peek (x_urun,49), "");
   yUNIT_minstr  ("... check (50) condition"           , yURG_peek (x_urun,50), "  COND [004] read one record -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00060]");
   yUNIT_minstr  ("... check (51) empty line"          , yURG_peek (x_urun,51), "");
   yUNIT_minstr  ("... check (52) group break"         , yURG_peek (x_urun,52), "  GROUP ===----------------------------   round two   ----------------------------===");
   yUNIT_minstr  ("... check (53) empty line"          , yURG_peek (x_urun,53), "");
   yUNIT_minstr  ("... check (54) condition"           , yURG_peek (x_urun,54), "  COND [005] read a second record  -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00066]");
   yUNIT_minstr  ("... check (55) empty line"          , yURG_peek (x_urun,55), "");
   yUNIT_minstr  ("... check (56) condition"           , yURG_peek (x_urun,56), "  " BACK_MAG "SOND [006]" BACK_OFF " close and delete script file - -- -- -- -- -- -- -- -- -- -- -- -[00034]");
   yUNIT_minstr  ("... check (57) empty line"          , yURG_peek (x_urun,57), "");
   yUNIT_minstr  ("... check (58) condition"           , yURG_peek (x_urun,58), "  " BACK_MAG "SOND [007]" BACK_OFF " close and delete code file  -- -- -- -- -- -- -- -- -- -- -- -- -[00039]");
   yUNIT_minstr  ("... check (59) empty line"          , yURG_peek (x_urun,59), "");
   yUNIT_minstr  ("... check (60) group break"         , yURG_peek (x_urun,60), "  GROUP ===---------------------------   final round   ---------------------------===");
   yUNIT_minstr  ("... check (61) empty line"          , yURG_peek (x_urun,61), "");
   yUNIT_minstr  ("... check (62) condition"           , yURG_peek (x_urun,62), "  COND [008] generate a summary -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00073]");
   yUNIT_minstr  ("... check (63) empty line"          , yURG_peek (x_urun,63), "");
   yUNIT_minstr  ("... check (64) script footer"       , yURG_peek (x_urun,64), "  PRCS -------- cond=8     test=32    [ ------------------------------------------- ]");
   yUNIT_minstr  ("... check (65) empty line"          , yURG_peek (x_urun,65), "");
   yUNIT_minstr  ("... check (66) empty line"          , yURG_peek (x_urun,66), "");
   yUNIT_minstr  ("... check (67) script"              , yURG_peek (x_urun,67), "SCRP [04] (SCRP) empty script ===========================================[è9]=[00078]");
   yUNIT_minstr  ("... check (68) empty line"          , yURG_peek (x_urun,68), "");
   yUNIT_minstr  ("... check (69) script footer"       , yURG_peek (x_urun,69), "  PRCS -------- cond=0     test=0     [ ------------------------------------------- ]");
   yUNIT_minstr  ("... check (70) empty line"          , yURG_peek (x_urun,70), "");
   yUNIT_minstr  ("... check (71) test footer"         , yURG_peek (x_urun,71), "TINU  scrp=4    cond=15    test=57    [ ------------------------------------------- ]");
   yUNIT_minstr  ("... check (72) empty line"          , yURG_peek (x_urun,72), "");
   yUNIT_minstr  ("... check (73) empty line"          , yURG_peek (x_urun,73), "");
   yUNIT_minstr  ("... check (74) footer line"         , yURG_peek (x_urun,74), "yUNIT - heatherly unit testing framework ---------------------------------------(end)");
   yUNIT_minval  ("... check line count"               , yURG_peek_count (x_urun) , 75);
   yUNIT_mindnoc ();

   yUNIT_mincond ("check displaying conditions for one script");
   yUNIT_minval  ("... run unit test"                  , system ("./koios_unit --conds 02"), 0);
   yUNIT_minstr  ("... check (  0) header line"        , yURG_peek (x_urun,  0), "yUNIT - heatherly unit testing framework ---------------------------------------(beg)");
   yUNIT_minstr  ("... check (  1) patron"             , yURG_peek (x_urun,  1), "   patron : daktyloi-aeonius (forefinger) automated unit testing                   4s");
   yUNIT_minstr  ("... check (  2) level line"         , yURG_peek (x_urun,  2), "   assign output level to (3) YUNIT_COND                                          19c");
   yUNIT_minstr  ("... check (  3) eterm line"         , yURG_peek (x_urun,  3), "   assign format/color to (y) ETERM                                               49x");
   yUNIT_minstr  ("... check (  4) empty line"         , yURG_peek (x_urun,  4), "");
   yUNIT_minstr  ("... check (  5) empty line"         , yURG_peek (x_urun,  5), "");
   yUNIT_minstr  ("... check (  6) script"             , yURG_peek (x_urun,  6), "SCRP [02] (SCRP) verify system startup ==================================[ê2]=[00044]");
   yUNIT_minstr  ("... check (  7) empty line"         , yURG_peek (x_urun,  7), "");
   yUNIT_minstr  ("... check (  8) condition"          , yURG_peek (x_urun,  8), "  COND [001] run initialization -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00045]");
   yUNIT_minstr  ("... check (  9) empty line"         , yURG_peek (x_urun,  9), "");
   yUNIT_minstr  ("... check ( 10) condition"          , yURG_peek (x_urun, 10), "  " BACK_MAG "SOND [002]" BACK_OFF " script input file  -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00023]");
   yUNIT_minstr  ("... check ( 11) empty line"         , yURG_peek (x_urun, 11), "");
   yUNIT_minstr  ("... check ( 12) condition"          , yURG_peek (x_urun, 12), "  " BACK_MAG "SOND [003]" BACK_OFF " code output file - -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00028]");
   yUNIT_minstr  ("... check ( 13) empty line"         , yURG_peek (x_urun, 13), "");
   yUNIT_minstr  ("... check ( 14) condition"          , yURG_peek (x_urun, 14), "  COND [004] parse a code record - -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00047]");
   yUNIT_minstr  ("... check ( 15) empty line"         , yURG_peek (x_urun, 15), "");
   yUNIT_minstr  ("... check ( 16) script footer"      , yURG_peek (x_urun, 16), "  PRCS -------- cond=4     test=12    [ ------------------------------------------- ]");
   yUNIT_minstr  ("... check ( 17) empty line"         , yURG_peek (x_urun, 17), "");
   yUNIT_minstr  ("... check ( 18) test footer"        , yURG_peek (x_urun, 18), "TINU  scrp=1    cond=4     test=12    [ ------------------------------------------- ]");
   yUNIT_minstr  ("... check ( 19) empty line"         , yURG_peek (x_urun, 19), "");
   yUNIT_minstr  ("... check ( 20) empty line"         , yURG_peek (x_urun, 20), "");
   yUNIT_minstr  ("... check ( 21) footer line"        , yURG_peek (x_urun, 21), "yUNIT - heatherly unit testing framework ---------------------------------------(end)");
   yUNIT_minval  ("... check line count"               , yURG_peek_count (x_urun) , 22);
   yUNIT_mindnoc ();

   yUNIT_mincond ("check executing and presenting only conditions");
   yUNIT_minval  ("... run unit test"                  , system ("./koios_unit --cond"), 999);
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify header");
   yUNIT_minstr  ("... check ( 0) header line"         , yURG_peek (x_urun, 0), "yUNIT - heatherly unit testing framework ---------------------------------------(beg)");
   yUNIT_minstr  ("... check ( 1) patron"              , yURG_peek (x_urun, 1), "   patron : daktyloi-aeonius (forefinger) automated unit testing                   4s");
   yUNIT_minstr  ("... check ( 2) level line"          , yURG_peek (x_urun, 2), "   assign output level to (3) YUNIT_COND                                          19c");
   yUNIT_minstr  ("... check ( 3) eterm line"          , yURG_peek (x_urun, 3), "   assign format/color to (y) ETERM                                               49x");
   yUNIT_minstr  ("... check ( 4) empty line"          , yURG_peek (x_urun, 4), "");
   yUNIT_minstr  ("... check ( 5) empty line"          , yURG_peek (x_urun, 5), "");
   yUNIT_minstr  ("... check ( 6) section"             , yURG_peek (x_urun, 6), "=========================------------------------------------========================");
   yUNIT_minstr  ("... check ( 7) section"             , yURG_peek (x_urun, 7), "SECT ===-------------------------- simple testing ---------------------------=== TCES");
   yUNIT_minstr  ("... check ( 8) section"             , yURG_peek (x_urun, 8), "=========================------------------------------------========================");
   yUNIT_minstr  ("... check ( 9) empty line"          , yURG_peek (x_urun, 9), "");
   yUNIT_minstr  ("... check (10) empty line"          , yURG_peek (x_urun,10), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify first script");
   yUNIT_minstr  ("... check (11) script"              , yURG_peek (x_urun,11), "SCRP [01] (SCRP) verify openning and closing ============================[ê1]=[00004]");
   yUNIT_minstr  ("... check (12) empty line"          , yURG_peek (x_urun,12), "");
   yUNIT_minstr  ("... check (13) condition"           , yURG_peek (x_urun,13), "  COND [001] simple openning -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00005]");
   yUNIT_minstr  ("... check (14) condition footer"    , yURG_peek (x_urun,14), "      " BACK_GRN "DNOC --------------- test=4     [ pass=4     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... check (15) empty line"          , yURG_peek (x_urun,15), "");
   yUNIT_minstr  ("... check (16) condition"           , yURG_peek (x_urun,16), "  COND [002] defensive checks - -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00010]");
   yUNIT_minstr  ("... check (17) condition footer"    , yURG_peek (x_urun,17), "      " BACK_GRN "DNOC --------------- test=4     [ pass=4     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... check (18) empty line"          , yURG_peek (x_urun,18), "");
   yUNIT_minstr  ("... check (19) condition"           , yURG_peek (x_urun,19), "  COND [003] duplicate opens and closes  -- -- -- -- -- -- -- -- -- -- -- -- -[00015]");
   yUNIT_minstr  ("... check (20) condition footer"    , yURG_peek (x_urun,20), "      " BACK_RED "DNOC --------------- test=5     [ pass=4     fail=1     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... check (21) empty line"          , yURG_peek (x_urun,21), "");
   yUNIT_minstr  ("... check (22) script footer"       , yURG_peek (x_urun,22), "  " BACK_RED "PRCS -------- cond=3     test=13    [ pass=12    fail=1     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... check (23) empty line"          , yURG_peek (x_urun,23), "");
   yUNIT_minstr  ("... check (24) empty line"          , yURG_peek (x_urun,24), "");
   yUNIT_minstr  ("... check (25) section"             , yURG_peek (x_urun,25), "=========================------------------------------------========================");
   yUNIT_minstr  ("... check (26) section"             , yURG_peek (x_urun,26), "SECT ===----------------------- more complex testing ------------------------=== TCES");
   yUNIT_minstr  ("... check (27) section"             , yURG_peek (x_urun,27), "=========================------------------------------------========================");
   yUNIT_minstr  ("... check (28) empty line"          , yURG_peek (x_urun,28), "");
   yUNIT_minstr  ("... check (29) empty line"          , yURG_peek (x_urun,29), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify second script");
   yUNIT_minstr  ("... check (30) script"              , yURG_peek (x_urun,30), "SCRP [02] (SCRP) verify system startup ==================================[ê2]=[00044]");
   yUNIT_minstr  ("... check (31) empty line"          , yURG_peek (x_urun,31), "");
   yUNIT_minstr  ("... check (32) condition"           , yURG_peek (x_urun,32), "  COND [001] run initialization -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00045]");
   yUNIT_minstr  ("... check (33) condition footer"    , yURG_peek (x_urun,33), "      " BACK_YEL "DNOC --------------- test=0     [ pass=0     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... check (34) empty line"          , yURG_peek (x_urun,34), "");
   yUNIT_minstr  ("... check (35) condition"           , yURG_peek (x_urun,35), "  " BACK_MAG "SOND [002]" BACK_OFF " script input file  -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00023]");
   yUNIT_minstr  ("... check (36) condition footer"    , yURG_peek (x_urun,36), "      " BACK_RED "DNOC --------------- test=4     [ pass=1     fail=3     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... check (37) empty line"          , yURG_peek (x_urun,37), "");
   yUNIT_minstr  ("... check (38) condition"           , yURG_peek (x_urun,38), "  " BACK_MAG "SOND [003]" BACK_OFF " code output file - -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00028]");
   yUNIT_minstr  ("... check (39) condition footer"    , yURG_peek (x_urun,39), "      " BACK_GRN "DNOC --------------- test=4     [ pass=4     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... check (40) empty line"          , yURG_peek (x_urun,40), "");
   yUNIT_minstr  ("... check (41) condition"           , yURG_peek (x_urun,41), "  COND [004] parse a code record - -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00047]");
   yUNIT_minstr  ("... check (42) condition footer"    , yURG_peek (x_urun,42), "      " BACK_GRN "DNOC --------------- test=4     [ pass=4     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... check (43) empty line"          , yURG_peek (x_urun,43), "");
   yUNIT_minstr  ("... check (44) script footer"       , yURG_peek (x_urun,44), "  " BACK_RED "PRCS -------- cond=4     test=12    [ pass=9     fail=3     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... check (45) empty line"          , yURG_peek (x_urun,45), "");
   yUNIT_minstr  ("... check (46) empty line"          , yURG_peek (x_urun,46), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify third script");
   yUNIT_minstr  ("... check (47) script"              , yURG_peek (x_urun,47), "SCRP [03] (SCRP) verify normal processing ===============================[ì2]=[00052]");
   yUNIT_minstr  ("... check (48) empty line"          , yURG_peek (x_urun,48), "");
   yUNIT_minstr  ("... check (49) group break"         , yURG_peek (x_urun,49), "  GROUP ===----------------------------   round one   ----------------------------===");
   yUNIT_minstr  ("... check (50) empty line"          , yURG_peek (x_urun,50), "");
   yUNIT_minstr  ("... check (51) condition"           , yURG_peek (x_urun,51), "  COND [001] process arguments  -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00054]");
   yUNIT_minstr  ("... check (52) condition footer"    , yURG_peek (x_urun,52), "      " BACK_GRN "DNOC --------------- test=4     [ pass=4     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... check (53) empty line"          , yURG_peek (x_urun,53), "");
   yUNIT_minstr  ("... check (54) condition"           , yURG_peek (x_urun,54), "  " BACK_MAG "SOND [002]" BACK_OFF " script input file  -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00023]");
   yUNIT_minstr  ("... check (55) condition footer"    , yURG_peek (x_urun,55), "      " BACK_GRN "DNOC --------------- test=4     [ pass=4     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... check (56) empty line"          , yURG_peek (x_urun,56), "");
   yUNIT_minstr  ("... check (57) condition"           , yURG_peek (x_urun,57), "  " BACK_MAG "SOND [003]" BACK_OFF " code output file - -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00028]");
   yUNIT_minstr  ("... check (58) condition footer"    , yURG_peek (x_urun,58), "      " BACK_GRN "DNOC --------------- test=4     [ pass=4     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... check (59) empty line"          , yURG_peek (x_urun,59), "");
   yUNIT_minstr  ("... check (60) condition"           , yURG_peek (x_urun,60), "  COND [004] read one record -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00060]");
   yUNIT_minstr  ("... check (61) condition footer"    , yURG_peek (x_urun,61), "      " BACK_RED "DNOC --------------- test=4     [ pass=0     fail=4     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... check (62) empty line"          , yURG_peek (x_urun,62), "");
   yUNIT_minstr  ("... check (63) group break"         , yURG_peek (x_urun,63), "  GROUP ===----------------------------   round two   ----------------------------===");
   yUNIT_minstr  ("... check (64) empty line"          , yURG_peek (x_urun,64), "");
   yUNIT_minstr  ("... check (65) condition"           , yURG_peek (x_urun,65), "  COND [005] read a second record  -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00066]");
   yUNIT_minstr  ("... check (66) condition footer"    , yURG_peek (x_urun,66), "      " BACK_GRN "DNOC --------------- test=4     [ pass=4     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... check (67) empty line"          , yURG_peek (x_urun,67), "");
   yUNIT_minstr  ("... check (68) condition"           , yURG_peek (x_urun,68), "  " BACK_MAG "SOND [006]" BACK_OFF " close and delete script file - -- -- -- -- -- -- -- -- -- -- -- -[00034]");
   yUNIT_minstr  ("... check (69) condition footer"    , yURG_peek (x_urun,69), "      " BACK_GRN "DNOC --------------- test=4     [ pass=4     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... check (70) empty line"          , yURG_peek (x_urun,70), "");
   yUNIT_minstr  ("... check (71) condition"           , yURG_peek (x_urun,71), "  " BACK_MAG "SOND [007]" BACK_OFF " close and delete code file  -- -- -- -- -- -- -- -- -- -- -- -- -[00039]");
   yUNIT_minstr  ("... check (72) condition footer"    , yURG_peek (x_urun,72), "      " BACK_GRN "DNOC --------------- test=4     [ pass=4     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... check (73) empty line"          , yURG_peek (x_urun,73), "");
   yUNIT_minstr  ("... check (74) group break"         , yURG_peek (x_urun,74), "  GROUP ===---------------------------   final round   ---------------------------===");
   yUNIT_minstr  ("... check (75) empty line"          , yURG_peek (x_urun,75), "");
   yUNIT_minstr  ("... check (76) condition"           , yURG_peek (x_urun,76), "  COND [008] generate a summary -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00073]");
   yUNIT_minstr  ("... check (77) condition footer"    , yURG_peek (x_urun,77), "      " BACK_GRN "DNOC --------------- test=4     [ pass=4     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... check (78) empty line"          , yURG_peek (x_urun,78), "");
   yUNIT_minstr  ("... check (79) script footer"       , yURG_peek (x_urun,79), "  " BACK_RED "PRCS -------- cond=8     test=32    [ pass=28    fail=4     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... check (80) empty line"          , yURG_peek (x_urun,80), "");
   yUNIT_minstr  ("... check (81) empty line"          , yURG_peek (x_urun,81), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify fourth script and footer");
   yUNIT_minstr  ("... check (82) script"              , yURG_peek (x_urun,82), "SCRP [04] (SCRP) empty script ===========================================[è9]=[00078]");
   yUNIT_minstr  ("... check (83) empty line"          , yURG_peek (x_urun,83), "");
   yUNIT_minstr  ("... check (84) script footer"       , yURG_peek (x_urun,84), "  " BACK_YEL "PRCS -------- cond=0     test=0     [ pass=0     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... check (85) empty line"          , yURG_peek (x_urun,85), "");
   yUNIT_minstr  ("... check (86) test footer"         , yURG_peek (x_urun,86), BACK_RED "TINU  scrp=4    cond=15    test=57    [ pass=49    fail=8     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... check (87) empty line"          , yURG_peek (x_urun,87), "");
   yUNIT_minstr  ("... check (88) empty line"          , yURG_peek (x_urun,88), "");
   yUNIT_minstr  ("... check (89) footer line"         , yURG_peek (x_urun,89), "yUNIT - heatherly unit testing framework ---------------------------------------(end)");
   yUNIT_minval  ("... check line count"               , yURG_peek_count (x_urun) , 90);
   yUNIT_mindnoc ();

   yUNIT_mincond ("check executing and presenting but show only one script");
   yUNIT_minval  ("... run unit test"                  , system ("./koios_unit --cond 03"), 999);
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify header");
   yUNIT_minstr  ("... check ( 0) header line"         , yURG_peek (x_urun, 0), "yUNIT - heatherly unit testing framework ---------------------------------------(beg)");
   yUNIT_minstr  ("... check ( 1) patron"              , yURG_peek (x_urun, 1), "   patron : daktyloi-aeonius (forefinger) automated unit testing                   4s");
   yUNIT_minstr  ("... check ( 2) level line"          , yURG_peek (x_urun, 2), "   assign output level to (3) YUNIT_COND                                          19c");
   yUNIT_minstr  ("... check ( 3) eterm line"          , yURG_peek (x_urun, 3), "   assign format/color to (y) ETERM                                               49x");
   yUNIT_minstr  ("... check ( 4) empty line"          , yURG_peek (x_urun, 4), "");
   yUNIT_minstr  ("... check ( 5) empty line"          , yURG_peek (x_urun, 5), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify third script");
   yUNIT_minstr  ("... check ( 6) script"              , yURG_peek (x_urun, 6), "SCRP [03] (SCRP) verify normal processing ===============================[ì2]=[00052]");
   yUNIT_minstr  ("... check ( 7) empty line"          , yURG_peek (x_urun, 7), "");
   yUNIT_minstr  ("... check ( 8) group break"         , yURG_peek (x_urun, 8), "  GROUP ===----------------------------   round one   ----------------------------===");
   yUNIT_minstr  ("... check ( 9) empty line"          , yURG_peek (x_urun, 9), "");
   yUNIT_minstr  ("... check (10) condition"           , yURG_peek (x_urun,10), "  COND [001] process arguments  -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00054]");
   yUNIT_minstr  ("... check (11) condition footer"    , yURG_peek (x_urun,11), "      " BACK_GRN "DNOC --------------- test=4     [ pass=4     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... check (12) empty line"          , yURG_peek (x_urun,12), "");
   yUNIT_minstr  ("... check (13) condition"           , yURG_peek (x_urun,13), "  " BACK_MAG "SOND [002]" BACK_OFF " script input file  -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00023]");
   yUNIT_minstr  ("... check (14) condition footer"    , yURG_peek (x_urun,14), "      " BACK_GRN "DNOC --------------- test=4     [ pass=4     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... check (15) empty line"          , yURG_peek (x_urun,15), "");
   yUNIT_minstr  ("... check (16) condition"           , yURG_peek (x_urun,16), "  " BACK_MAG "SOND [003]" BACK_OFF " code output file - -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00028]");
   yUNIT_minstr  ("... check (17) condition footer"    , yURG_peek (x_urun,17), "      " BACK_GRN "DNOC --------------- test=4     [ pass=4     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... check (18) empty line"          , yURG_peek (x_urun,18), "");
   yUNIT_minstr  ("... check (19) condition"           , yURG_peek (x_urun,19), "  COND [004] read one record -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00060]");
   yUNIT_minstr  ("... check (20) condition footer"    , yURG_peek (x_urun,20), "      " BACK_RED "DNOC --------------- test=4     [ pass=0     fail=4     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... check (21) empty line"          , yURG_peek (x_urun,21), "");
   yUNIT_minstr  ("... check (22) group break"         , yURG_peek (x_urun,22), "  GROUP ===----------------------------   round two   ----------------------------===");
   yUNIT_minstr  ("... check (23) empty line"          , yURG_peek (x_urun,23), "");
   yUNIT_minstr  ("... check (24) condition"           , yURG_peek (x_urun,24), "  COND [005] read a second record  -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00066]");
   yUNIT_minstr  ("... check (25) condition footer"    , yURG_peek (x_urun,25), "      " BACK_GRN "DNOC --------------- test=4     [ pass=4     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... check (26) empty line"          , yURG_peek (x_urun,26), "");
   yUNIT_minstr  ("... check (27) condition"           , yURG_peek (x_urun,27), "  " BACK_MAG "SOND [006]" BACK_OFF " close and delete script file - -- -- -- -- -- -- -- -- -- -- -- -[00034]");
   yUNIT_minstr  ("... check (28) condition footer"    , yURG_peek (x_urun,28), "      " BACK_GRN "DNOC --------------- test=4     [ pass=4     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... check (29) empty line"          , yURG_peek (x_urun,29), "");
   yUNIT_minstr  ("... check (30) condition"           , yURG_peek (x_urun,30), "  " BACK_MAG "SOND [007]" BACK_OFF " close and delete code file  -- -- -- -- -- -- -- -- -- -- -- -- -[00039]");
   yUNIT_minstr  ("... check (31) condition footer"    , yURG_peek (x_urun,31), "      " BACK_GRN "DNOC --------------- test=4     [ pass=4     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... check (32) empty line"          , yURG_peek (x_urun,32), "");
   yUNIT_minstr  ("... check (33) group break"         , yURG_peek (x_urun,33), "  GROUP ===---------------------------   final round   ---------------------------===");
   yUNIT_minstr  ("... check (34) empty line"          , yURG_peek (x_urun,34), "");
   yUNIT_minstr  ("... check (35) condition"           , yURG_peek (x_urun,35), "  COND [008] generate a summary -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00073]");
   yUNIT_minstr  ("... check (36) condition footer"    , yURG_peek (x_urun,36), "      " BACK_GRN "DNOC --------------- test=4     [ pass=4     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... check (37) empty line"          , yURG_peek (x_urun,37), "");
   yUNIT_minstr  ("... check (38) script footer"       , yURG_peek (x_urun,38), "  " BACK_RED "PRCS -------- cond=8     test=32    [ pass=28    fail=4     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... check (39) empty line"          , yURG_peek (x_urun,39), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify fourth script and footer");
   yUNIT_minstr  ("... check (40) test footer"         , yURG_peek (x_urun,40), BACK_RED "TINU  scrp=1    cond=8     test=32    [ pass=28    fail=4     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... check (41) empty line"          , yURG_peek (x_urun,41), "");
   yUNIT_minstr  ("... check (42) empty line"          , yURG_peek (x_urun,42), "");
   yUNIT_minstr  ("... check (43) footer line"         , yURG_peek (x_urun,43), "yUNIT - heatherly unit testing framework ---------------------------------------(end)");
   yUNIT_minval  ("... check line count"               , yURG_peek_count (x_urun) , 44);
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
   yUNIT_minstr  ("... check (0) header line"          , yURG_peek (x_urun, 0), "yUNIT - heatherly unit testing framework ---------------------------------------(beg)");
   yUNIT_minstr  ("... check (1) patron"               , yURG_peek (x_urun, 1), "   patron : daktyloi-aeonius (forefinger) automated unit testing                   4s");
   yUNIT_minstr  ("... check (2) level line"           , yURG_peek (x_urun, 2), "   assign output level to (4) YUNIT_STEP                                          19c");
   yUNIT_minstr  ("... check (3) eterm line"           , yURG_peek (x_urun, 3), "   assign format/color to (y) ETERM                                               49x");
   yUNIT_minstr  ("... check (4) empty line"           , yURG_peek (x_urun, 4), "");
   yUNIT_minstr  ("... check (5) empty line"           , yURG_peek (x_urun, 5), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check step level section format");
   yUNIT_minstr  ("... check (6) section"              , yURG_peek (x_urun, 6), "=========================------------------------------------========================");
   yUNIT_minstr  ("... check (7) section"              , yURG_peek (x_urun, 7), "SECT ===-------------------------- simple testing ---------------------------=== TCES");
   yUNIT_minstr  ("... check (8) section"              , yURG_peek (x_urun, 8), "=========================------------------------------------========================");
   yUNIT_minstr  ("... check (9) empty line"           , yURG_peek (x_urun, 9), "");
   yUNIT_minstr  ("... check (10) empty line"          , yURG_peek (x_urun,10), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check step level script format");
   yUNIT_minstr  ("... check (11) separator"           , yURG_peek (x_urun,11), "===[[ NEW SCRIPT ]]==================================================================");
   yUNIT_minstr  ("... check (12) script"              , yURG_peek (x_urun,12), "SCRP [01] (SCRP) verify openning and closing ============================[ê1]=[00004]");
   yUNIT_minstr  ("... check (13) empty line"          , yURG_peek (x_urun,13), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check step level condition and normal steps");
   yUNIT_minstr  ("... check (14) condition"           , yURG_peek (x_urun,14), "  COND [001] simple openning -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00005]");
   yUNIT_minstr  ("... check (15) step"                , yURG_peek (x_urun,15), "     aa) str   : check string · ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·[00006]");
   yUNIT_minstr  ("... check (16) step"                , yURG_peek (x_urun,16), "     ab) real  : check number · ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·[00007]");
   yUNIT_minstr  ("... check (17) step"                , yURG_peek (x_urun,17), "     ac) int   : check integer  ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·[00008]");
   yUNIT_minstr  ("... check (18) step"                , yURG_peek (x_urun,18), "     ad) int   : check character · ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·[00009]");
   yUNIT_minstr  ("... check (19) empty line"          , yURG_peek (x_urun,19), "");
   yUNIT_minstr  ("... check (20) condition"           , yURG_peek (x_urun,20), "  COND [002] defensive checks - -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00010]");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check alternative step level entries");
   yUNIT_minstr  ("... check (25) empty line"          , yURG_peek (x_urun,25), "");
   yUNIT_minstr  ("... check (26) condition"           , yURG_peek (x_urun,26), "  COND [003] duplicate opens and closes  -- -- -- -- -- -- -- -- -- -- -- -- -[00015]");
   yUNIT_minstr  ("... check (27) step"                , yURG_peek (x_urun,27), "     aa) CODE  : working variables ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·[00016]");
   yUNIT_minstr  ("... check (28) step"                , yURG_peek (x_urun,28), "     ab) int   : check working variable  ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·[00017]");
   yUNIT_minstr  ("... check (29) step"                , yURG_peek (x_urun,29), "     ac) LOAD  : prep data for read · ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·[00018]");
   yUNIT_minstr  ("... check (30) step"                , yURG_peek (x_urun,30), "     ad) MODE  : FORCED_FAIL ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·[00019]");
   yUNIT_minstr  ("... check (31) step"                , yURG_peek (x_urun,31), "     ae) SYS   : run little  ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·[00020]");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check inclusion of shares");
   yUNIT_minstr  ("... check (43) empty line"          , yURG_peek (x_urun,43), "");
   yUNIT_minstr  ("... check (44) condition"           , yURG_peek (x_urun,44), "  COND [001] run initialization -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00045]");
   yUNIT_minstr  ("... check (45) empty line"          , yURG_peek (x_urun,45), "");
   yUNIT_minstr  ("... check (46) share marker"        , yURG_peek (x_urun,46), "  " BACK_MAG "SHARE (A) ===--------------------   prepare files for use   --------------------===" BACK_OFF);
   yUNIT_minstr  ("... check (47) empty line"          , yURG_peek (x_urun,47), "");
   yUNIT_minstr  ("... check (48) condition"           , yURG_peek (x_urun,48), "  " BACK_MAG "SOND [002]" BACK_OFF " script input file  -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00023]");
   yUNIT_minstr  ("... check (49) step"                , yURG_peek (x_urun,49), "     aa) str   : check string · ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·[00024]");
   yUNIT_minstr  ("... check (50) step"                , yURG_peek (x_urun,50), "     ab) real  : check number · ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·[00025]");
   yUNIT_minstr  ("... check (51) step"                , yURG_peek (x_urun,51), "     ac) int   : check integer  ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·[00026]");
   yUNIT_minstr  ("... check (52) step"                , yURG_peek (x_urun,52), "     ad) MODE  : normal · ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·[00027]");
   yUNIT_minstr  ("... check (53) empty line"          , yURG_peek (x_urun,53), "");
   yUNIT_minstr  ("... check (54) condition"           , yURG_peek (x_urun,54), "  " BACK_MAG "SOND [003]" BACK_OFF " code output file - -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00028]");
   yUNIT_minstr  ("... check (55) step"                , yURG_peek (x_urun,55), "     aa) str   : check string · ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·[00029]");
   yUNIT_minstr  ("... check (56) step"                , yURG_peek (x_urun,56), "     ab) real  : check number · ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·[00030]");
   yUNIT_minstr  ("... check (57) step"                , yURG_peek (x_urun,57), "     ac) int   : check integer  ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·[00031]");
   yUNIT_minstr  ("... check (58) step"                , yURG_peek (x_urun,58), "     ad) int   : check character · ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·[00032]");
   yUNIT_minstr  ("... check (59) empty line"          , yURG_peek (x_urun,59), "");
   yUNIT_minstr  ("... check (60) share marker"        , yURG_peek (x_urun,60), "  " BACK_MAG "ERAHS (A) ===--------------------   prepare files for use   --------------------===" BACK_OFF);
   yUNIT_minstr  ("... check (61) empty line"          , yURG_peek (x_urun,61), "");
   yUNIT_minval  ("... check line count"               , yURG_peek_count (x_urun) , 148);
   yUNIT_mindnoc ();

   yUNIT_mincond ("check executing and presenting down to steps");
   yUNIT_minval  ("... run unit test"                  , system ("./koios_unit --step"), 999);
   yUNIT_mindnoc ();

   yUNIT_mincond ("check step level condition and normal steps");
   yUNIT_minstr  ("... check (14) condition"           , yURG_peek (x_urun, 14), "  COND [001] simple openning -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00005]");
   yUNIT_minstr  ("... check (15) empty line"          , yURG_peek (x_urun, 15), "");
   yUNIT_minstr  ("... check (16) step"                , yURG_peek (x_urun, 16), "  " BACK_GRN "aa) PASS  " BACK_OFF " : check string ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ··[00006]");
   yUNIT_minstr  ("... check (17) empty line"          , yURG_peek (x_urun, 17), "");
   yUNIT_minstr  ("... check (18) step"                , yURG_peek (x_urun, 18), "  " BACK_GRN "ab) PASS  " BACK_OFF " : check number ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ··[00007]");
   yUNIT_minstr  ("... check (19) empty line"          , yURG_peek (x_urun, 19), "");
   yUNIT_minstr  ("... check (20) step"                , yURG_peek (x_urun, 20), "  " BACK_GRN "ac) PASS  " BACK_OFF " : check integer · ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ··[00008]");
   yUNIT_minstr  ("... check (21) empty line"          , yURG_peek (x_urun, 21), "");
   yUNIT_minstr  ("... check (22) step"                , yURG_peek (x_urun, 22), "  " BACK_GRN "ad) PASS  " BACK_OFF " : check character ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ··[00009]");
   yUNIT_minstr  ("... check (23) empty line"          , yURG_peek (x_urun, 23), "");
   yUNIT_minstr  ("... check (24) condition footer"    , yURG_peek (x_urun, 24), "      " BACK_GRN "DNOC --------------- test=4     [ pass=4     fail=0     badd=0     void=0     ]" BACK_OFF);
   yUNIT_minstr  ("... check (25) empty line"          , yURG_peek (x_urun, 25), "");
   yUNIT_minstr  ("... check (26) condition"           , yURG_peek (x_urun, 26), "  COND [002] defensive checks - -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -[00010]");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check alternative step level entries");
   yUNIT_minstr  ("... check (38) condition"           , yURG_peek (x_urun, 38), "  COND [003] duplicate opens and closes  -- -- -- -- -- -- -- -- -- -- -- -- -[00015]");
   yUNIT_minstr  ("... check (39) empty line"          , yURG_peek (x_urun, 39), "");
   yUNIT_minstr  ("... check (40) step"                , yURG_peek (x_urun, 40), "  " BACK_CYN "aa) " BACK_GRN "CODE  " BACK_OFF " : working variables  ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ··[00016]");
   yUNIT_minstr  ("... check (41) empty line"          , yURG_peek (x_urun, 41), "");
   yUNIT_minstr  ("... check (42) step"                , yURG_peek (x_urun, 42), "  " BACK_GRN "ab) PASS  " BACK_OFF " : check working variable · ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ··[00017]");
   yUNIT_minstr  ("... check (43) empty line"          , yURG_peek (x_urun, 43), "");
   yUNIT_minstr  ("... check (44) step"                , yURG_peek (x_urun, 44), "  " BACK_CYN "ac) " BACK_GRN "LOAD  " BACK_OFF " : prep data for read ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ··[00018]");
   yUNIT_minstr  ("... check (45) empty line"          , yURG_peek (x_urun, 45), "");
   yUNIT_minstr  ("... check (46) step"                , yURG_peek (x_urun, 46), "  " BACK_CYN "ad) " BACK_GRN "MODE  " BACK_OFF " : ENABLE FORCED FAILURE (pass=fail, fail=pass)  ·· ·· ·· ·· ·· ··[00019]");
   yUNIT_minstr  ("... check (47) empty line"          , yURG_peek (x_urun, 47), "");
   yUNIT_minstr  ("... check (48) step"                , yURG_peek (x_urun, 48), "  " BACK_CYN "ae) " BACK_RED "!SYS  " BACK_OFF " : run little · ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ··[00020]");
   yUNIT_minstr  ("... check (49) empty line"          , yURG_peek (x_urun, 49), "");
   yUNIT_minstr  ("... check (50) condition footer"    , yURG_peek (x_urun, 50), "      " BACK_RED "DNOC --------------- test=5     [ pass=4     fail=1     badd=0     void=0     ]" BACK_OFF);
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
   yUNIT_minstr  ("... check ( 16) step"               , yURG_peek (x_urun, 16), "  " BACK_GRN "aa) PASS  " BACK_OFF " : check string ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ··[00006]");
   yUNIT_minstr  ("... check ( 17) method"             , yURG_peek (x_urun, 17), "      method : yUNIT_teststring (0)");
   yUNIT_minstr  ("... check ( 18) test"               , yURG_peek (x_urun, 18), "      test   : s_equal    (rc =  101, test abbr = e)");
   yUNIT_minstr  ("... check ( 19) expect"             , yURG_peek (x_urun, 19), "      expect :  5[hello]");
   yUNIT_minstr  ("... check ( 20) actual"             , yURG_peek (x_urun, 20), "      actual :  5[hello]");
   yUNIT_minstr  ("... check ( 21) empty"              , yURG_peek (x_urun, 21), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check failing string step");
   yUNIT_minstr  ("... check (281) step"               , yURG_peek (x_urun,281), "  " BACK_RED "aa) FAIL  " BACK_OFF " : check string ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ··[00061]");
   yUNIT_minstr  ("... check (282) method"             , yURG_peek (x_urun,282), "      method : yUNIT_teststring (1)");
   yUNIT_minstr  ("... check (283) test"               , yURG_peek (x_urun,283), "      test   : s_equal    (rc = -101, test abbr = e)");
   yUNIT_minstr  ("... check (284) expect"             , yURG_peek (x_urun,284), "      expect :  7[" BOLD_RED "hello££" BOLD_OFF "]");
   yUNIT_minstr  ("... check (285) actual"             , yURG_peek (x_urun,285), "      actual :  7[" BOLD_RED "goodbye" BOLD_OFF "]");
   yUNIT_minstr  ("... check (286) empty"              , yURG_peek (x_urun,286), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check forced fail string step");
   yUNIT_minstr  ("... check (107) step"               , yURG_peek (x_urun,107), "  " BACK_GRN "aa) " BACK_RED "!FAIL " BACK_OFF " : check string ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ··[00024]");
   yUNIT_minstr  ("... check (108) method"             , yURG_peek (x_urun,108), "      method : yUNIT_teststring (0)");
   yUNIT_minstr  ("... check (109) test"               , yURG_peek (x_urun,109), "      test   : s_equal    (rc =  101, test abbr = e)");
   yUNIT_minstr  ("... check (110) expect"             , yURG_peek (x_urun,110), "      expect :  5[hello]");                              
   yUNIT_minstr  ("... check (111) actual"             , yURG_peek (x_urun,111), "      actual :  5[hello]");                              
   yUNIT_minstr  ("... check (112) empty"              , yURG_peek (x_urun,112), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check passing float step");
   yUNIT_minstr  ("... check ( 22) step"               , yURG_peek (x_urun, 22), "  " BACK_GRN "ab) PASS  " BACK_OFF " : check number ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ··[00007]");
   yUNIT_minstr  ("... check ( 23) method"             , yURG_peek (x_urun, 23), "      method : yUNIT_testreal (5)");
   yUNIT_minstr  ("... check ( 24) test"               , yURG_peek (x_urun, 24), "      test   : r_greater  (rc =  103, test abbr = g)");
   yUNIT_minstr  ("... check ( 25) expect"             , yURG_peek (x_urun, 25), "      expect :  9[15.000000]");
   yUNIT_minstr  ("... check ( 26) actual"             , yURG_peek (x_urun, 26), "      actual :  9[15.707964]");
   yUNIT_minstr  ("... check ( 27) empty"              , yURG_peek (x_urun, 27), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check failing float step");
   yUNIT_minstr  ("... check (287) step"               , yURG_peek (x_urun,287), "  " BACK_RED "ab) FAIL  " BACK_OFF " : check number ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ··[00062]");
   yUNIT_minstr  ("... check (288) method"             , yURG_peek (x_urun,288), "      method : yUNIT_testreal (2)");
   yUNIT_minstr  ("... check (289) test"               , yURG_peek (x_urun,289), "      test   : r_greater  (rc = -103, test abbr = g)");
   yUNIT_minstr  ("... check (290) expect"             , yURG_peek (x_urun,290), "      expect :  9[15.000000]");
   yUNIT_minstr  ("... check (291) actual"             , yURG_peek (x_urun,291), "      actual :  8[6.283185]");
   yUNIT_minstr  ("... check (292) empty"              , yURG_peek (x_urun,292), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check passing integer step");
   yUNIT_minstr  ("... check ( 28) step"               , yURG_peek (x_urun, 28), "  " BACK_GRN "ac) PASS  " BACK_OFF " : check integer · ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ··[00008]");
   yUNIT_minstr  ("... check ( 29) method"             , yURG_peek (x_urun, 29), "      method : yUNIT_testint (32)");
   yUNIT_minstr  ("... check ( 30) test"               , yURG_peek (x_urun, 30), "      test   : i_equal    (rc =  101, test abbr = e)");
   yUNIT_minstr  ("... check ( 31) expect"             , yURG_peek (x_urun, 31), "      expect :  1[2]");
   yUNIT_minstr  ("... check ( 32) actual"             , yURG_peek (x_urun, 32), "      actual :  1[2]");
   yUNIT_minstr  ("... check ( 33) empty"              , yURG_peek (x_urun, 33), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check failing integer step");
   yUNIT_minstr  ("... check (293) step"               , yURG_peek (x_urun,293), "  " BACK_RED "ac) FAIL  " BACK_OFF " : check integer · ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ··[00063]");
   yUNIT_minstr  ("... check (294) method"             , yURG_peek (x_urun,294), "      method : yUNIT_testint (64)");
   yUNIT_minstr  ("... check (295) test"               , yURG_peek (x_urun,295), "      test   : i_equal    (rc = -101, test abbr = e)");
   yUNIT_minstr  ("... check (296) expect"             , yURG_peek (x_urun,296), "      expect :  1[2]");
   yUNIT_minstr  ("... check (297) actual"             , yURG_peek (x_urun,297), "      actual :  1[4]");
   yUNIT_minstr  ("... check (298) empty"              , yURG_peek (x_urun,298), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check mode step");                                   
   yUNIT_minstr  ("... check ( 81) step"               , yURG_peek (x_urun, 81), "  " BACK_CYN "ad) " BACK_GRN "MODE  " BACK_OFF " : ENABLE FORCED FAILURE (pass=fail, fail=pass)  ·· ·· ·· ·· ·· ··[00019]");
   yUNIT_minstr  ("... check ( 82) empty"              , yURG_peek (x_urun, 82), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check code step");                                   
   yUNIT_minstr  ("... check ( 69) step"               , yURG_peek (x_urun, 69), "  " BACK_CYN "aa) " BACK_GRN "CODE  " BACK_OFF " : working variables  ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ··[00016]");
   yUNIT_minstr  ("... check ( 70) contents"           , yURG_peek (x_urun, 70), "      code   : 10[int c = 0;]");
   yUNIT_minstr  ("... check ( 71) empty"              , yURG_peek (x_urun, 71), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check load step");                                   
   yUNIT_minstr  ("... check ( 78) step"               , yURG_peek (x_urun, 78), "  " BACK_CYN "ac) " BACK_GRN "LOAD  " BACK_OFF " : prep data for read ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ··[00018]");
   yUNIT_minstr  ("... check ( 79) contents"           , yURG_peek (x_urun, 79), "      stdin  : 13[one two three]");
   yUNIT_minstr  ("... check ( 80) empty"              , yURG_peek (x_urun, 80), "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("check sys step");                                   
   yUNIT_minstr  ("... check ( 83) step"               , yURG_peek (x_urun, 83), "  " BACK_CYN "ae) " BACK_RED "!SYS  " BACK_OFF " : run little · ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ·· ··[00020]");
   yUNIT_minstr  ("... check ( 84) contents"           , yURG_peek (x_urun, 84), "      system : 10[/bin/false]");
   yUNIT_minstr  ("... check ( 85) empty"              , yURG_peek (x_urun, 85), "");
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
   /*---(script input)-------------------*/
   koios__unit_scrp_files   ();
   koios__unit_scrp_read    ();
   koios__unit_scrp_verb    ();
   koios__unit_scrp_stage   ();
   koios__unit_scrp_comment ();
   koios__unit_scrp_parse   ();
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
   yUNIT_mintinu ();
   return 0;
}


