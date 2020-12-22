/*===============================[[ beg-code ]]===============================*/
#include    "koios.h"        /* LOCAL  : main header                          */

#include    "ySTR_solo.h"
#include    "yCOLOR_solo.h"
#include    "yUNIT_solo.h"



char
koios__unit_scrp_files   (void)
{
   yUNIT_minscrp ("koios_scrp file open and close");

   yUNIT_mincond ("prepare clean start");
   system ("rm -f /tmp/koios.unit 2> /dev/null");
   yUNIT_mindnoc ();

   yUNIT_mincond ("attempt to open with no name");
   strcpy (my.n_scrp, "");
   yUNIT_minstr ("... check script name"              , my.n_scrp     , "");
   yUNIT_minval ("... check script pointer"           , my.f_scrp     , 0);
   yUNIT_minval ("open the script file"               , SCRP_open   (), -999);
   yUNIT_minstr ("... check script name"              , my.n_scrp     , "");
   yUNIT_minval ("... check script pointer"           , my.f_scrp     , 0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("attempt to close when not open");
   strcpy (my.n_scrp, "");
   yUNIT_minstr ("... check script name"              , my.n_scrp     , "");
   yUNIT_minval ("... check script pointer"           , my.f_scrp     , 0);
   yUNIT_minval ("close the script file"              , SCRP_close  (), -999);
   yUNIT_minstr ("... check script name"              , my.n_scrp     , "");
   yUNIT_minval ("... check script pointer"           , my.f_scrp     , 0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("attempt a non-existant name");
   strcpy (my.n_scrp, "/tmp/koios.unit");
   yUNIT_minstr ("... check script name"              , my.n_scrp     , "/tmp/koios.unit");
   yUNIT_minval ("... check script pointer"           , my.f_scrp     , 0);
   yUNIT_minval ("open the script file"               , SCRP_open   (), -999);
   yUNIT_minstr ("... check script name"              , my.n_scrp     , "/tmp/koios.unit");
   yUNIT_minval ("... check script pointer"           , my.f_scrp     , 0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("open a new file name");
   strcpy (my.n_scrp, "/tmp/koios.unit");
   system ("touch /tmp/koios.unit");
   yUNIT_minstr ("... check script name"              , my.n_scrp     , "/tmp/koios.unit");
   yUNIT_minval ("... check script pointer"           , my.f_scrp     , 0);
   yUNIT_minval ("open the script file"               , SCRP_open   (), 0);
   yUNIT_minstr ("... check script name"              , my.n_scrp     , "/tmp/koios.unit");
   yUNIT_minval ("... check script pointer"           , my.f_scrp     , my.f_scrp);
   yUNIT_mindnoc ();

   yUNIT_mincond ("close the new name");
   yUNIT_minstr ("... check script name"              , my.n_scrp     , "/tmp/koios.unit");
   yUNIT_minval ("... check script pointer"           , my.f_scrp     , my.f_scrp);
   yUNIT_minval ("close the script file"              , SCRP_close  (), 0);
   yUNIT_minstr ("... check script name"              , my.n_scrp     , "/tmp/koios.unit");
   yUNIT_minval ("... check script pointer"           , my.f_scrp     , 0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("attempt to close twice");
   yUNIT_minstr ("... check script name"              , my.n_scrp     , "/tmp/koios.unit");
   yUNIT_minval ("... check script pointer"           , my.f_scrp     , 0);
   yUNIT_minval ("close the script file"              , SCRP_close  (), -999);
   yUNIT_minstr ("... check script name"              , my.n_scrp     , "/tmp/koios.unit");
   yUNIT_minval ("... check script pointer"           , my.f_scrp     , 0);
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

   yUNIT_mincond ("prepare clean start");
   system ("rm -f /tmp/koios.unit 2> /dev/null");
   yUNIT_mindnoc ();

   yUNIT_mincond ("attempt to read an empty file");
   strcpy (my.n_scrp, "/tmp/koios.unit");
   system ("touch /tmp/koios.unit");
   yUNIT_minstr ("... check script name"              , my.n_scrp     , "/tmp/koios.unit");
   yUNIT_minval ("open the script file"               , SCRP_open   (), 0);
   yUNIT_minval ("... check script pointer"           , my.f_scrp     , my.f_scrp);
   yUNIT_minval ("read a line"                        , SCRP_read   (), -999);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , ""               );
   yUNIT_minval ("close the script file"              , SCRP_close  (), 0);
   yUNIT_minval ("... check script pointer"           , my.f_scrp     , 0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify reading a single record");
   strcpy (my.n_scrp, "/tmp/koios.unit");
   system ("echo \"exec    § read a line     § SCRP_read   §   § i_lesser   § 0      §\"                                             > /tmp/koios.unit");
   yUNIT_minstr ("... check script name"              , my.n_scrp     , "/tmp/koios.unit");
   yUNIT_minval ("open the script file"               , SCRP_open   (), 0);
   yUNIT_minval ("... check script pointer"           , my.f_scrp     , my.f_scrp);
   yUNIT_minval ("read a line"                        , SCRP_read   (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "exec    § read a line     § SCRP_read   §   § i_lesser   § 0      §");
   yUNIT_minval ("close the script file"              , SCRP_close  (), 0);
   yUNIT_minval ("... check script pointer"           , my.f_scrp     , 0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify skipping non-records");
   strcpy (my.n_scrp, "/tmp/koios.unit");
   system ("echo \"\"                                                                         > /tmp/koios.unit");
   system ("echo \"## just a comment\"                                                       >> /tmp/koios.unit");
   system ("echo \"exec    § read a line     § SCRP_read   §   § i_lesser   § 0      §\"     >> /tmp/koios.unit");
   yUNIT_minstr ("... check script name"              , my.n_scrp     , "/tmp/koios.unit");
   yUNIT_minval ("open the script file"               , SCRP_open   (), 0);
   yUNIT_minval ("... check script pointer"           , my.f_scrp     , my.f_scrp);
   yUNIT_minval ("read a line"                        , SCRP_read   (), 0);
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
   yUNIT_minval  ("parse SCRP"                         , SCRP_parse_verb ("SCRPER"), 0);
   yUNIT_minstr ("... check verb"                      , my.verb       , "SCRP");
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

   yUNIT_mincond ("parse good stages");
   yUNIT_minval  ("parse SCRP"                         , SCRP_parse_verb ("SCRP    [è0]"), 0);
   yUNIT_minstr ("... check verb"                      , my.verb       , "SCRP");
   yUNIT_minval  ("parse [è0]"                         , SCRP_parse_stage("SCRP    [è0]"), 0);
   yUNIT_minstr ("... check stage"                     , my.stage      , "è0");
   yUNIT_minval  ("parse SCRP"                         , SCRP_parse_verb ("SCRP    [ì4]"), 0);
   yUNIT_minstr ("... check verb"                      , my.verb       , "SCRP");
   yUNIT_minval  ("parse [è0]"                         , SCRP_parse_stage("SCRP    [ì4]"), 0);
   yUNIT_minstr ("... check stage"                     , my.stage      , "ì4");
   yUNIT_mindnoc ();

   yUNIT_mincond ("parse illegal stages");
   yUNIT_minval  ("parse SCRP"                         , SCRP_parse_verb ("SCRP    [kz]"), 0);
   yUNIT_minstr ("... check verb"                      , my.verb       , "SCRP");
   yUNIT_minval  ("parse [kz]"                         , SCRP_parse_stage("SCRP    [kz]"), -999);
   yUNIT_minstr ("... check stage"                     , my.stage      , "");
   yUNIT_minval  ("parse SCRP"                         , SCRP_parse_verb ("SCRP    (è0)"), 0);
   yUNIT_minstr ("... check verb"                      , my.verb       , "SCRP");
   yUNIT_minval  ("parse (è0)"                         , SCRP_parse_stage("SCRP    (è0)"), -999);
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
   yUNIT_minval  ("parse stage"                        , SCRP_parse_stage("COND   [ë3]"), -999);
   yUNIT_minstr ("... check stage"                     , my.stage      , "");

   yUNIT_minprcs ();
   return 0;
}

char
koios__unit_scrp_comment (void)
{
   yUNIT_minscrp ("koios_scrp identifying comments");

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

   yUNIT_mincond ("prepare clean start");
   system ("rm -f /tmp/koios.unit 2> /dev/null");
   yUNIT_mindnoc ();

   yUNIT_mincond ("attempt to parse an empty file");
   strcpy (my.n_scrp, "/tmp/koios.unit");
   system ("touch /tmp/koios.unit");
   yUNIT_minstr ("... check script name"              , my.n_scrp     , "/tmp/koios.unit");
   yUNIT_minval ("open the script file"               , SCRP_open   (), 0);
   yUNIT_minval ("... check script pointer"           , my.f_scrp     , my.f_scrp);
   yUNIT_minval ("read a line"                        , SCRP_read   (), -999);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), -999);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , ""               );
   yUNIT_minval ("close the script file"              , SCRP_close  (), 0);
   yUNIT_minval ("... check script pointer"           , my.f_scrp     , 0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify reading a single record");
   strcpy (my.n_scrp, "/tmp/koios.unit");
   system ("echo \"exec    § read a line     § SCRP_read   §   § i_lesser   § 0      §\"                                             > /tmp/koios.unit");
   yUNIT_minstr ("... check script name"              , my.n_scrp     , "/tmp/koios.unit");
   yUNIT_minval ("open the script file"               , SCRP_open   (), 0);
   yUNIT_minval ("... check script pointer"           , my.f_scrp     , my.f_scrp);
   yUNIT_minval ("read a line"                        , SCRP_read   (), 0);
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
   yUNIT_minval ("read a line"                        , SCRP_read   (), -999);
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
   system ("echo \"exec    §\"                                             > /tmp/koios.unit");
   yUNIT_minstr ("... check script name"              , my.n_scrp     , "/tmp/koios.unit");
   yUNIT_minval ("open the script file"               , SCRP_open   (), 0);
   yUNIT_minval ("... check script pointer"           , my.f_scrp     , my.f_scrp);
   yUNIT_minval ("read a line"                        , SCRP_read   (), -999);
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

   yUNIT_mincond ("attempt verb and desc");
   strcpy (my.n_scrp, "/tmp/koios.unit");
   system ("echo \"exec    § read a line     §\"                                             > /tmp/koios.unit");
   yUNIT_minstr ("... check script name"              , my.n_scrp     , "/tmp/koios.unit");
   yUNIT_minval ("open the script file"               , SCRP_open   (), 0);
   yUNIT_minval ("... check script pointer"           , my.f_scrp     , my.f_scrp);
   yUNIT_minval ("read a line"                        , SCRP_read   (), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), -999);
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
   system ("echo \"exec    § read a line     § SCRP_read   §\"                                             > /tmp/koios.unit");
   yUNIT_minstr ("... check script name"              , my.n_scrp     , "/tmp/koios.unit");
   yUNIT_minval ("open the script file"               , SCRP_open   (), 0);
   yUNIT_minval ("... check script pointer"           , my.f_scrp     , my.f_scrp);
   yUNIT_minval ("read a line"                        , SCRP_read   (), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), -999);
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
   system ("echo \"exec    § read a line     § SCRP_read   §   § i_lesser   §\"                                             > /tmp/koios.unit");
   yUNIT_minstr ("... check script name"              , my.n_scrp     , "/tmp/koios.unit");
   yUNIT_minval ("open the script file"               , SCRP_open   (), 0);
   yUNIT_minval ("... check script pointer"           , my.f_scrp     , my.f_scrp);
   yUNIT_minval ("read a line"                        , SCRP_read   (), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), -999);
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
   system ("echo \"  COND (B)  § original cond   § - - - - - - § - § - - - - -  § - - -  §\"  >> /tmp/koios.unit");
   system ("echo \"    exec    § line one        § - - - - - - § - § - - - - -  § - - -  §\"  >> /tmp/koios.unit");
   system ("echo \"    exec    § line two        § - - - - - - § - § - - - - -  § - - -  §\"  >> /tmp/koios.unit");
   system ("echo \"\"                                                                         >> /tmp/koios.unit");
   system ("echo \"  DITTO (B) § new cond        § - - - - - - § - § - - - - -  § - - -  §\"  >> /tmp/koios.unit");
   system ("echo \"\"                                                                         >> /tmp/koios.unit");
   system ("echo \"  COND      § after others    § - - - - - - § - § - - - - -  § - - -  §\"  >> /tmp/koios.unit");
   yUNIT_minstr ("... check script name"              , my.n_scrp     , "/tmp/koios.unit");
   yUNIT_minval ("open the script file"               , SCRP_open   (), 0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("read ditto condition");
   yUNIT_minval ("read a line"                        , SCRP_read   (), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "  COND (B)  § original cond   § - - - - - - § - § - - - - -  § - - -  §");
   yUNIT_minstr ("... check dittos"                    , SCRP_ditto_used ()  , "-B------------------------");
   yUNIT_mindnoc ();

   yUNIT_mincond ("read detailed line");
   yUNIT_minval ("read a line"                        , SCRP_read   (), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "    exec    § line one        § - - - - - - § - § - - - - -  § - - -  §");
   yUNIT_minstr ("... check dittos"                    , SCRP_ditto_used ()  , "-B------------------------");
   yUNIT_mindnoc ();

   yUNIT_mincond ("read detailed line");
   yUNIT_minval ("read a line"                        , SCRP_read   (), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "    exec    § line two        § - - - - - - § - § - - - - -  § - - -  §");
   yUNIT_minstr ("... check dittos"                    , SCRP_ditto_used ()  , "-B------------------------");
   yUNIT_mindnoc ();

   yUNIT_mincond ("read ditto call");
   yUNIT_minval ("read a line"                        , SCRP_read   (), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "  DITTO (B) § new cond        § - - - - - - § - § - - - - -  § - - -  §");
   yUNIT_minstr ("... check dittos"                    , SCRP_ditto_used ()  , "-B------------------------");
   yUNIT_mindnoc ();

   yUNIT_mincond ("read ditto condition");
   yUNIT_minval ("read a line"                        , SCRP_read   (), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "  COND (B)  § original cond   § - - - - - - § - § - - - - -  § - - -  §");
   yUNIT_minstr ("... check dittos"                    , SCRP_ditto_used ()  , "-B------------------------");
   yUNIT_mindnoc ();

   yUNIT_mincond ("read detailed line");
   yUNIT_minval ("read a line"                        , SCRP_read   (), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "    exec    § line one        § - - - - - - § - § - - - - -  § - - -  §");
   yUNIT_minstr ("... check dittos"                    , SCRP_ditto_used ()  , "-B------------------------");
   yUNIT_mindnoc ();

   yUNIT_mincond ("read detailed line");
   yUNIT_minval ("read a line"                        , SCRP_read   (), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "    exec    § line two        § - - - - - - § - § - - - - -  § - - -  §");
   yUNIT_minstr ("... check dittos"                    , SCRP_ditto_used ()  , "-B------------------------");
   yUNIT_mindnoc ();

   yUNIT_mincond ("read after condition");
   yUNIT_minval ("read a line"                        , SCRP_read   (), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "  COND      § after others    § - - - - - - § - § - - - - -  § - - -  §");
   yUNIT_minstr ("... check dittos"                    , SCRP_ditto_used ()  , "-B------------------------");
   yUNIT_mindnoc ();

   yUNIT_mincond ("read end-of-file");
   yUNIT_minval ("read a line"                        , SCRP_read   (), -999);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), -999);
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

   yUNIT_mincond ("prepare clean start");
   system ("rm -f /tmp/koios.unit 2> /dev/null");
   system ("echo \"\"                                                                                                                                                      > /tmp/koios.unit");
   system ("echo \"## this is a comment\"                                                                                                                                 >> /tmp/koios.unit");
   system ("echo \"exec         § read a line     § SCRP_read   §   § i_lesser   § 0      § p § my_var   §\"                                                              >> /tmp/koios.unit");
   system ("echo \"#> this is a saved comment\"                                                                                                                           >> /tmp/koios.unit");
   system ("echo \"     get     § ... check on script § SCRP__unit  § file , -1 § s_equal § SCRP file      : /tmp/koios.unit §\"                                          >> /tmp/koios.unit");
   system ("echo \"   code      § add lines                           § - - - - - - - - - - - - -  § system ();        §\"                                                >> /tmp/koios.unit");
   system ("echo \"\"                                                                                                                                                     >> /tmp/koios.unit");
   system ("echo \"  COND       § parse a code record  § - - - - - - - - - - - - -  § ((01.001)) § - - - - - - - - - §\"                                                  >> /tmp/koios.unit");
   system ("echo \"PREP         § include the prototype headers                           § - - - - - - - - - -  § - - - - -  § - - - - - - - - - -  §>>\"                >> /tmp/koios.unit");
   system ("echo \"   incl      § include public header               § koios.h          § - - - - - - - - - -  § - - - - -  § - - - - - - - - - -  §\"                   >> /tmp/koios.unit");
   system ("echo \"#23456789-12 § 123456789-123456789-123456789-12345 § 123456789-123456 § 123456789-123456789- § 123456789- § 123456789-123456789- § - § 123456789- §\"  >> /tmp/koios.unit");
   system ("echo \"#==(verb)=== § ===========(description)=========== § =====(function)= § ====(arguments)===== § ==(test)== § ====(results)======= § t § =(var)==== §\"  >> /tmp/koios.unit");
   system ("echo \"SCRP    [ê3] § (SCRP  ) verify openning and closin §                                         § ((01.---)) § - - - - - - - - - -  §\"                   >> /tmp/koios.unit");
   system ("echo \"\"                                                                                                                                                     >> /tmp/koios.unit");
   system ("echo \"  load       § add a line to stdin   § stdin § * * * * *                      : basic line                  : - - - - -  :  /bin/true > /dev/null§\"   >> /tmp/koios.unit");
   system ("echo \"  toad       § add a line to stdin 2 § stdin § * * * * *                      : basic line                  : - - - - -  :  /bin/true > /dev/null§\"   >> /tmp/koios.unit");
   system ("echo \"             § (SCRP  ) verify openning and closin §                                         § ((01.---)) § - - - - - - - - - -  §\"                   >> /tmp/koios.unit");
   system ("echo \"\"                                                                                                                                                     >> /tmp/koios.unit");
   system ("echo \"GROUP        § complete              § - - - - - - - - - - - - - - -  § - - - - -  § - - - - - - - - - - - - - - - - - - - - - - - - -  §\"            >> /tmp/koios.unit");
   system ("echo \"SECT         § internal testing      § - - - - - - - - - - - - - - -  § - - - - -  § - - - - - - - - - - - - - - - - - - - - - - - - -  §\"            >> /tmp/koios.unit");
   system ("echo \"    echo     § ...check y location   § - - - - - - - - - - - - -  § y       § r_norm93   § -125.381                                     §\"            >> /tmp/koios.unit");
   system ("echo \"    sys      § remove a file                       § - - - - - - - - - - - - -  § rm -fv test.txt   §\"                                                >> /tmp/koios.unit");
   system ("echo \"\"                                                                                                                                                     >> /tmp/koios.unit");
   system ("echo \"#==(verb)=== § ===========(description)=========== § =====(function)= § ====(arguments)===== § ==(test)== § ====(results)======= § t § =(var)==== §\"  >> /tmp/koios.unit");
   system ("echo \"SHARED   -A- § setup cron files and lines          § - - - - - - - -  § ((CC.---)) § - - - - - - - - - - - - - - - - - - - - - - - - -  §\"            >> /tmp/koios.unit");
   system ("echo \"\"                                                                                                                                                     >> /tmp/koios.unit");
   system ("echo \" REUSE -A-   § - - - - - - - - - - - -  § - - - - - - - - - - - - - - -  § ((03.---)) § - - - - - - - - - - - - - - - - - - - -  §\"                   >> /tmp/koios.unit");
   my.run_type = G_RUN_CREATE;
   strcpy (my.n_scrp, "/tmp/koios.unit");
   yUNIT_minstr ("... check script name"              , my.n_scrp     , "/tmp/koios.unit");
   yUNIT_minval ("open the script file"               , SCRP_open   (), 0);
   yUNIT_mindnoc ();

   yUNIT_mincond ("read very detailed exec line");
   yUNIT_minval ("read a line"                        , SCRP_read   (), 0);
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
   yUNIT_minval ("read a line"                        , SCRP_read   (), 0);
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
   yUNIT_minval ("read a line"                        , SCRP_read   (), 0);
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
   yUNIT_minval ("read a line"                        , SCRP_read   (), 0);
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
   yUNIT_minval ("read a line"                        , SCRP_read   (), 0);
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
   yUNIT_minval ("read a line"                        , SCRP_read   (), 0);
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
   yUNIT_minval ("read a line"                        , SCRP_read   (), 0);
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
   yUNIT_minval ("read a line"                        , SCRP_read   (), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "SCRP    [ê3] § (SCRP  ) verify openning and closin §                                         § ((01.---)) § - - - - - - - - - -  §");
   yUNIT_minstr ("... check verb"                     , my.verb       , "SCRP");
   yUNIT_minstr ("... check stage"                    , my.stage      , "ê3");
   yUNIT_minchr ("... check share"                    , my.share      , '-');
   yUNIT_minchr ("... check mark"                     , my.mark       , '-');
   yUNIT_minstr ("... check version"                  , my.vers       , "");
   yUNIT_minstr ("... check description"              , my.desc       , "(SCRP  ) verify openning and closin");
   yUNIT_minstr ("... check method"                   , my.meth       , "");
   yUNIT_minstr ("... check arguments"                , my.args       , "");
   yUNIT_minstr ("... check test"                     , my.test       , "");
   yUNIT_minstr ("... check expect"                   , my.expe       , "");
   yUNIT_minchr ("... check type"                     , my.type       , '-');
   yUNIT_minstr ("... check return"                   , my.retn       , "");
   yUNIT_minstr ("... check code"                     , my.code       , "");
   yUNIT_mindnoc ();

   yUNIT_mincond ("read stdin load line");
   yUNIT_minval ("read a line"                        , SCRP_read   (), 0);
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
   yUNIT_minval ("read a line"                        , SCRP_read   (), 0);
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
   yUNIT_minval ("read a line"                        , SCRP_read   (), 0);
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
   yUNIT_minval ("read a line"                        , SCRP_read   (), 0);
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
   yUNIT_minval ("read a line"                        , SCRP_read   (), 0);
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
   yUNIT_minval ("read a line"                        , SCRP_read   (), 0);
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
   yUNIT_minval ("read a line"                        , SCRP_read   (), 0);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), 0);
   strlencode (my.recd, ySTR_NONE, LEN_RECD);
   yUNIT_minstr ("... check the record"               , my.recd       , "    sys      § remove a file                       § - - - - - - - - - - - - -  § rm -fv test.txt   §");
   yUNIT_minstr ("... check verb"                     , my.verb       , "sys");
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
   yUNIT_minval ("read a line"                        , SCRP_read   (), 0);
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
   yUNIT_minval ("read a line"                        , SCRP_read   (), 0);
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
   yUNIT_minval ("read a line"                        , SCRP_read   (), -999);
   yUNIT_minval ("parse a line"                       , SCRP_parse  (), -999);
   yUNIT_mindnoc ();

   yUNIT_mincond ("clean up after");
   system ("rm -f /tmp/koios.unit 2> /dev/null");
   yUNIT_mindnoc ();

   yUNIT_minprcs ();
   return 0;
}

char
koios__unit_conv_files   (void)
{
   yUNIT_minscrp ("koios_conv file open and close");

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

   yUNIT_mincond ("prepare and open a new file");
   strcpy (my.n_conv, "/tmp/koios.unit");
   yUNIT_minval ("open the script file"               , CONV_open   (), 0);
   yUNIT_minstr ("... check script name"              , my.n_conv     , "/tmp/koios.unit");
   yUNIT_minval ("... check script pointer"           , my.f_conv     , my.f_conv);
   yUNIT_mindnoc ();

   yUNIT_mincond ("write the beginning");
   CONV_cycle ();
   yUNIT_minval ("call beg"                           , CONV_beg    (), 0);
   yUNIT_minstr ("... check (0) shebang"              , yUNIT_read (my.n_conv, 0, &c), "#!/usr/local/bin/koios");
   yUNIT_minstr ("... check (1) title"                , yUNIT_read (my.n_conv, 1, &c), "#   koios-polos (north star) -- customized c unit testing meta-program and mini-language");
   yUNIT_minval ("... check line count"               , c , 2);
   yUNIT_mindnoc ();

   yUNIT_mincond ("write a standard header");
   CONV_cycle ();
   yUNIT_minval ("call header"                        , CONV_header (), 0);
   yUNIT_minstr ("... check (0) empty"                , yUNIT_read (my.n_conv, 0, &c), "");
   yUNIT_minstr ("... check (1) empty"                , yUNIT_read (my.n_conv, 1, &c), "");
   yUNIT_minstr ("... check (2) empty"                , yUNIT_read (my.n_conv, 2, &c), "");
   yUNIT_minstr ("... check (3) number ruler"         , yUNIT_read (my.n_conv, 3, &c), "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  -  123456789-123456789- ");
   yUNIT_minstr ("... check (4) title"                , yUNIT_read (my.n_conv, 4, &c), "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  t  ========(var)======= ");
   yUNIT_minval ("... check line count"               , c , 5);
   yUNIT_mindnoc ();

   yUNIT_mincond ("write the ending");
   CONV_cycle ();
   yUNIT_minval ("call end"                           , CONV_end    (), 0);
   yUNIT_minstr ("... check (0) empty"                , yUNIT_read (my.n_conv, 0, &c), "");
   yUNIT_minstr ("... check (1) empty"                , yUNIT_read (my.n_conv, 1, &c), "");
   yUNIT_minstr ("... check (2) empty"                , yUNIT_read (my.n_conv, 2, &c), "");
   yUNIT_minstr ("... check (3) finish"               , yUNIT_read (my.n_conv, 3, &c), "# end-of-file.  done, finito, completare, whimper.");
   yUNIT_minval ("... check line count"               , c , 4);
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

   yUNIT_mincond ("prepare and open a new file");
   strcpy (my.n_conv, "/tmp/koios.unit");
   yUNIT_minval ("open the script file"               , CONV_open   (), 0);
   yUNIT_minstr ("... check script name"              , my.n_conv     , "/tmp/koios.unit");
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
   yUNIT_minstr ("... check (0) empty"                , yUNIT_read (my.n_conv, 0, &c), "");
   yUNIT_minstr ("... check (1) empty"                , yUNIT_read (my.n_conv, 1, &c), "");
   yUNIT_minstr ("... check (2) empty"                , yUNIT_read (my.n_conv, 2, &c), "");
   yUNIT_minstr ("... check (3) number ruler"         , yUNIT_read (my.n_conv, 3, &c), "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  -  123456789-123456789- ");
   yUNIT_minstr ("... check (4) title"                , yUNIT_read (my.n_conv, 4, &c), "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  t  ========(var)======= ");
   yUNIT_minstr ("... check (5) prep line"            , yUNIT_read (my.n_conv, 5, &c), "PREP          include the prototype headers                                      - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minval ("... check line count"               , c , 6);
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
   yUNIT_minstr ("... check (0) prep line"            , yUNIT_read (my.n_conv, 0, &c), "   incl       public header                        stdio.h                     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minval ("... check line count"               , c , 1);
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
   yUNIT_minstr ("... check (0) prep line"            , yUNIT_read (my.n_conv, 0, &c), "#> the following macro resets exec lines");
   yUNIT_minval ("... check line count"               , c , 1);
   yUNIT_mindnoc ();

   yUNIT_mincond ("clean up after");
   system ("rm -f /tmp/koios.unit 2> /dev/null");
   yUNIT_mindnoc ();

   yUNIT_minprcs ();
   return 0;
}

char
koios__unit_conv_scrp    (void)
{
   int         c           =    0;

   yUNIT_minscrp ("CONV_scrp, CONV_sect, CONV_shared");

   yUNIT_mincond ("prepare and open a new file");
   strcpy (my.n_conv, "/tmp/koios.unit");
   yUNIT_minval ("open the script file"               , CONV_open   (), 0);
   yUNIT_minstr ("... check script name"              , my.n_conv     , "/tmp/koios.unit");
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
   yUNIT_minstr ("... check (0) empty"                , yUNIT_read (my.n_conv, 0, &c), "");
   yUNIT_minstr ("... check (1) empty"                , yUNIT_read (my.n_conv, 1, &c), "");
   yUNIT_minstr ("... check (2) empty"                , yUNIT_read (my.n_conv, 2, &c), "");
   yUNIT_minstr ("... check (3) number ruler"         , yUNIT_read (my.n_conv, 3, &c), "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  -  123456789-123456789- ");
   yUNIT_minstr ("... check (4) title"                , yUNIT_read (my.n_conv, 4, &c), "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  t  ========(var)======= ");
   yUNIT_minstr ("... check (5) script line"          , yUNIT_read (my.n_conv, 5, &c), "SCRP    [ì4]  (FILE) biggest script                                              core_function                                                                                         ((01.---))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minval ("... check line count"               , c , 6);
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
   yUNIT_minstr ("... check (0) empty"                , yUNIT_read (my.n_conv, 0, &c), "");
   yUNIT_minstr ("... check (1) empty"                , yUNIT_read (my.n_conv, 1, &c), "");
   yUNIT_minstr ("... check (2) empty"                , yUNIT_read (my.n_conv, 2, &c), "");
   yUNIT_minstr ("... check (3) number ruler"         , yUNIT_read (my.n_conv, 3, &c), "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  -  123456789-123456789- ");
   yUNIT_minstr ("... check (4) title"                , yUNIT_read (my.n_conv, 4, &c), "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  t  ========(var)======= ");
   yUNIT_minstr ("... check (5) section line"         , yUNIT_read (my.n_conv, 5, &c), "SECT          file oriented                                                      - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minval ("... check line count"               , c , 6);
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
   yUNIT_minstr ("... check (0) empty"                , yUNIT_read (my.n_conv, 0, &c), "");
   yUNIT_minstr ("... check (1) empty"                , yUNIT_read (my.n_conv, 1, &c), "");
   yUNIT_minstr ("... check (2) empty"                , yUNIT_read (my.n_conv, 2, &c), "");
   yUNIT_minstr ("... check (3) number ruler"         , yUNIT_read (my.n_conv, 3, &c), "#23456789-12  123456789-123456789-123456789-12345  123456789-123456789-123456  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  123456789-  123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-  -  123456789-123456789- ");
   yUNIT_minstr ("... check (4) title"                , yUNIT_read (my.n_conv, 4, &c), "#==(verb)===  ===========(description)===========  =====(function)===========  ========================(arguments)=================================================================  ==(test)==  ==========================(results)=================================================================  t  ========(var)======= ");
   yUNIT_minstr ("... check (5) shared line"          , yUNIT_read (my.n_conv, 5, &c), "SHARED   -a-  remove temporary files                                             - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((aa.---))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minval ("... check line count"               , c , 6);
   yUNIT_mindnoc ();

   yUNIT_mincond ("clean up after");
   system ("rm -f /tmp/koios.unit 2> /dev/null");
   yUNIT_mindnoc ();

   yUNIT_minprcs ();
   return 0;
}

char
koios__unit_conv_cond    (void)
{
   int         c           =    0;

   yUNIT_minscrp ("CONV_cond, CONV_group, CONV_ditto, CONV_reuse");
   my.run_type = G_RUN_UPDATE;

   yUNIT_mincond ("prepare and open a new file");
   strcpy (my.n_conv, "/tmp/koios.unit");
   yUNIT_minval ("open the script file"               , CONV_open   (), 0);
   yUNIT_minstr ("... check script name"              , my.n_conv     , "/tmp/koios.unit");
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
   yUNIT_minstr ("... check (0) empty"                , yUNIT_read (my.n_conv, 0, &c), "");
   yUNIT_minstr ("... check (1) script line"          , yUNIT_read (my.n_conv, 1, &c), "   COND (B)   verify successful value                                            - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((aa.001))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minval ("... check line count"               , c , 2);
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
   yUNIT_minstr ("... check (0) empty"                , yUNIT_read (my.n_conv, 0, &c), "");
   yUNIT_minstr ("... check (1) script line"          , yUNIT_read (my.n_conv, 1, &c), "   DITTO (B)  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   ((aa.002))  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minval ("... check line count"               , c , 2);
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
   yUNIT_minstr ("... check (0) empty"                , yUNIT_read (my.n_conv, 0, &c), "");
   yUNIT_minstr ("... check (1) script line"          , yUNIT_read (my.n_conv, 1, &c), "   GROUP      check major defenses                                               - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minval ("... check line count"               , c , 2);
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
   yUNIT_minstr ("... check (0) empty"                , yUNIT_read (my.n_conv, 0, &c), "");
   yUNIT_minstr ("... check (1) script line"          , yUNIT_read (my.n_conv, 1, &c), "   REUSE -d-  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minval ("... check line count"               , c , 2);
   yUNIT_mindnoc ();

   yUNIT_mincond ("clean up after");
   system ("rm -f /tmp/koios.unit 2> /dev/null");
   yUNIT_mindnoc ();

   yUNIT_minprcs ();
   return 0;
}

char
koios__unit_conv_recd    (void)
{
   int         c           =    0;

   yUNIT_minscrp ("CONV_exec, CONV_load, CONV_code, CONV_echo");
   my.run_type = G_RUN_UPDATE;

   yUNIT_mincond ("prepare and open a new file");
   strcpy (my.n_conv, "/tmp/koios.unit");
   yUNIT_minval ("open the script file"               , CONV_open   (), 0);
   yUNIT_minstr ("... check script name"              , my.n_conv     , "/tmp/koios.unit");
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
   yUNIT_minstr ("... check (0) detail"               , yUNIT_read (my.n_conv, 0, &c), "     exec     read a line                          SCRP_read                   test, 5                                                                                               i_lesser    0                                                                                                     p  my_var               ");
   yUNIT_minval ("... check line count"               , c , 1);
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
   yUNIT_minstr ("... check (0) detail"               , yUNIT_read (my.n_conv, 0, &c), "     get      ...check count                       UNIT_answer                 \"ans\"                                                                                                 s_equal     count = 15.2                                                                                         ");
   yUNIT_minval ("... check line count"               , c , 1);
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
   yUNIT_minstr ("... check (0) detail"               , yUNIT_read (my.n_conv, 0, &c), "     mode     FORCED_FAIL                          - - - - - - - - - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   - - - - -   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  ");
   yUNIT_minval ("... check line count"               , c , 1);
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
   yUNIT_minstr ("... check (0) detail"               , yUNIT_read (my.n_conv, 0, &c), "     load     keyboard input                       ncurses                     abcdefghijklmnopqrstuvwxyz                                                                                                                                                                                                 ");
   yUNIT_minval ("... check line count"               , c , 1);
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
   yUNIT_minstr ("... check (0) detail"               , yUNIT_read (my.n_conv, 0, &c), "     code     working variable                     - - - - - - - - - - - - -   int l = 15;                                                                                                                                                                                                                ");
   yUNIT_minval ("... check line count"               , c , 1);
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
   yUNIT_minstr ("... check (0) detail"               , yUNIT_read (my.n_conv, 0, &c), "     echo     check length                         - - - - - - - - - - - - -   l                                                                                                     r_equal     15.2                                                                                                 ");
   yUNIT_minval ("... check line count"               , c , 1);
   yUNIT_mindnoc ();

   yUNIT_mincond ("clean up after");
   system ("rm -f /tmp/koios.unit 2> /dev/null");
   yUNIT_mindnoc ();

   yUNIT_minprcs ();
   return 0;
}

char
main                    (void)
{
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
   koios__unit_conv_recd    ();
   /*---(done)---------------------------*/
   yUNIT_mintinu ();
   return 0;
}


