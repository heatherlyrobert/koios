/*===============================[[ beg-code ]]===============================*/
#include    "koios.h"

/*> #include    <yURG.h>                                                              <*/
#include    <yUNIT_solo.h>
#include    <ySTR_solo.h>
#include    <yCOLOR_solo.h>


char  *s_wave     = "/tmp/master.wave";


char
unit_reuse_index  (void)
{
   /*---(header)-------------------------*/
   yUNIT_minscrpy ("koios", "koios_reuse", "(REUSE) retrieving reuse indexes");
   /*> yURG_err_none ();                                                              <*/
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

   PROG__unit_end    ();
   yUNIT_minprcs ();
   return 0;
}

char
unit_reuse_getset (void)
{

   char        x_desc      [LEN_LONG]  = "";
   /*---(header)-------------------------*/
   yUNIT_minscrpy ("koios", "koios_reuse", "(REUSE) setting and getting reuse values");
   /*> yURG_err_none ();                                                              <*/
   PROG__unit_quiet  ();

   yUNIT_mincond ("verify clean start");
   yUNIT_minval  ("... init"                           , REUSE_init ()       , 0);
   yUNIT_minstr  ("... review"                         , REUSE__used ()      , "�-----�-----�-----�-----�-   �-----�-----�-----�-----�-");
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
   yUNIT_minstr  ("... review"                         , REUSE__used ()      , "A-----�-----�-----�-----�-   �-----�-----�-----�-----�-");
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
   yUNIT_minstr  ("... review"                         , REUSE__used ()      , "A-----�-----�-----�-----�-   �-----�-----�-----�-----�-");
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
   yUNIT_minval  ("call set"                           , REUSE__set (T_MASTER, '�',   1, "verify something")    , -999);
   yUNIT_minstr  ("... review"                         , REUSE__used ()      , "A-----�-----�-----�-----�-   �-----�-----�-----�-----�-");
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
   yUNIT_minstr  ("... review"                         , REUSE__used ()      , "A-----�-----�-----�-----�-   �-----�-----�-----�-----�z");
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
   yUNIT_minstr  ("... review"                         , REUSE__used ()      , "A-----�-----M-----�-----�-   �----f�-----�-----�-----�z");
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
   yUNIT_minstr  ("... review"                         , REUSE__used ()      , "�-----�-----�-----�-----�-   �-----�-----�-----�-----�-");
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
   yUNIT_minstr  ("... review"                         , REUSE__used ()      , "�-----�-----�-----�-----�-   �----f�-----�-----�-----�-");
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
   yUNIT_minstr  ("... review"                         , REUSE__used ()      , "�-----�-----M-----�-----�-   �----f�-----�-----�-----�-");
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
   yUNIT_minprcs ();
   return 0;
}

char
unit_reuse_global (void)
{
   char        x_master    [LEN_TITLE] = "master.unit";
   char        x_name      [LEN_TITLE] = "apate.unit";
   char        x_desc      [LEN_LONG]  = "";
   char        x_share     =  '-';
   yUNIT_minscrpy ("koios", "koios_reuse", "(REUSE) parsing GLOBAL reuses");
   /*> yURG_err_none ();                                                              <*/
   PROG__unit_quiet  ();

   yUNIT_mincond ("set to defaults");
   yUNIT_minval  ("... run clear"                      , REUSE_init ()       , 0);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "�-----�-----�-----�-----�-   �-----�-----�-----�-----�-");
   yUNIT_mindnoc ();

   /*> yURG_err_clear ();                                                             <*/
   yUNIT_mincond ("verify ignoring other verbs");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_master,   0, "exec"     ,  0, "  exec      read a line          "   , x_desc, '-', &x_share),    0);
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_master,   0, "SCRP"     ,  0, "SCRP        test the reading     "   , x_desc, '-', &x_share),    0);
   yUNIT_mindnoc ();

   /*> yURG_err_clear ();                                                             <*/
   yUNIT_mincond ("attempt reusing a missing identifier");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_master,   1, "REUSE"    ,  0, "REUSE  -K-  - - - - - - - - - -  "   , x_desc, '-', &x_share), -999);
   yUNIT_minchr  ("... check mark"                     , x_share             , '-');
   /*> yUNIT_minstr  ("... check error message"            , yURG_err_last (), "master.unit:1:0: error: �REUSE  -K-� verb identifier �K� never set by GLOBAL");   <*/
   yUNIT_mindnoc ();

   /*> yURG_err_clear ();                                                             <*/
   yUNIT_mincond ("attempt reusing a illegal identifier");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_master,   3, "REUSE"    ,  0, "REUSE  -�-  - - - - - - - - - -  "   , x_desc, '-', &x_share), -999);
   yUNIT_minchr  ("... check mark"                     , x_share             , '-');
   /*> yUNIT_minstr  ("... check error message"            , yURG_err_last (), "master.unit:3:0: error: �REUSE  -�-� verb identifier �� not valid [a-zA-Z]");   <*/
   yUNIT_mindnoc ();

   /*> yURG_err_clear ();                                                             <*/
   yUNIT_mincond ("verify simple global identifier");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_master,   4, "GLOBAL"   ,  0, "GLOBAL -A-  generate test data   "   , x_desc, '-', &x_share), 1);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "A-----�-----�-----�-----�-   �-----�-----�-----�-----�-");
   yUNIT_minchr  ("... check mark"                     , x_share             , 'A');
   /*> yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");   <*/
   yUNIT_minval  ("call get mark"                      , REUSE__get (T_MASTER, x_share, x_desc, NULL, NULL)         ,    4);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "generate test data");
   yUNIT_mindnoc ();

   /*> yURG_err_clear ();                                                             <*/
   yUNIT_mincond ("verify reusing the identifier (in normal unit)");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_name  ,   5, "REUSE"    ,  0, "REUSE  -A-  - - - - - - - - - -  "   , x_desc, '-', &x_share), 1);
   yUNIT_minchr  ("... check mark"                     , x_share             , 'A');
   /*> yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");   <*/
   yUNIT_mindnoc ();

   /*> yURG_err_clear ();                                                             <*/
   yUNIT_mincond ("verify reusing the identifier (in master unit)");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_master,   5, "REUSE"    ,  0, "REUSE  -A-  - - - - - - - - - -  "   , x_desc, '-', &x_share), 1);
   yUNIT_minchr  ("... check mark"                     , x_share             , 'A');
   /*> yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");   <*/
   yUNIT_mindnoc ();

   /*> yURG_err_clear ();                                                             <*/
   yUNIT_mincond ("verify defenses");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_master,   0, NULL       ,  0, "REUSE  -A-  - - - - - - - - - -  "   , x_desc, '-', &x_share), -999);
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_master,   0, "REUSE"    ,  0, NULL                                      , x_desc, '-', &x_share), -999);
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_master,   0, "REUSE"    ,  0, "REUSE  -A-  - - - - - - - - - -  "   , x_desc, '-', NULL    ), -999);
   yUNIT_mindnoc ();

   /*> yURG_err_clear ();                                                             <*/
   yUNIT_mincond ("attempt without a identifier");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_master,   6, "GLOBAL"   ,  0, "GLOBAL      oops                 "   , x_desc, '-', &x_share), -999);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "A-----�-----�-----�-----�-   �-----�-----�-----�-----�-");
   yUNIT_minchr  ("... check mark"                     , x_share             , '-');
   /*> yUNIT_minstr  ("... check error message"            , yURG_err_last (), "master.unit:6:0: error: �GLOBAL� missing valid identifier string, e.g., -A-");   <*/
   yUNIT_minval  ("call get mark"                      , REUSE__get (T_MASTER, x_share, x_desc, NULL, NULL)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_mindnoc ();

   /*> yURG_err_clear ();                                                             <*/
   yUNIT_mincond ("attempt with weird delimiters");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_master,   7, "GLOBAL"   ,  0, "GLOBAL (M)  oops                 "   , x_desc, '-', &x_share), -999);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "A-----�-----�-----�-----�-   �-----�-----�-----�-----�-");
   yUNIT_minchr  ("... check mark"                     , x_share             , '-');
   /*> yUNIT_minstr  ("... check error message"            , yURG_err_last (), "master.unit:7:0: error: �GLOBAL (M)� missing valid identifier string, e.g., -A-");   <*/
   yUNIT_minval  ("call get mark"                      , REUSE__get (T_MASTER, x_share, x_desc, NULL, NULL)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_mindnoc ();

   /*> yURG_err_clear ();                                                             <*/
   yUNIT_mincond ("attempt with no suffix");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_master,   8, "GLOBAL"   ,  0, "GLOBAL -M   oops                 "   , x_desc, '-', &x_share), -999);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "A-----�-----�-----�-----�-   �-----�-----�-----�-----�-");
   yUNIT_minchr  ("... check mark"                     , x_share             , '-');
   /*> yUNIT_minstr  ("... check error message"            , yURG_err_last (), "master.unit:8:0: error: �GLOBAL -M� identifier �-M� does not end with -, e.g., -A-");   <*/
   yUNIT_minval  ("call get mark"                      , REUSE__get (T_MASTER, x_share, x_desc, NULL, NULL)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_mindnoc ();

   /*> yURG_err_clear ();                                                             <*/
   yUNIT_mincond ("attempt with just suffix");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_master,   9, "GLOBAL"   ,  0, "GLOBAL -M)  oops                 "   , x_desc, '-', &x_share), -999);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "A-----�-----�-----�-----�-   �-----�-----�-----�-----�-");
   yUNIT_minchr  ("... check mark"                     , x_share             , '-');
   /*> yUNIT_minstr  ("... check error message"            , yURG_err_last (), "master.unit:9:0: error: �GLOBAL -M)� identifier �-M)� does not end with -, e.g., -A-");   <*/
   yUNIT_minval  ("call get mark"                      , REUSE__get (T_MASTER, x_share, x_desc, NULL, NULL)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_mindnoc ();

   /*> yURG_err_clear ();                                                             <*/
   yUNIT_mincond ("verify another global identifier");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_master,  10, "GLOBAL"   ,  0, "GLOBAL -M-  some repeating stuff "   , x_desc, '-', &x_share), 1);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "A-----�-----M-----�-----�-   �-----�-----�-----�-----�-");
   yUNIT_minchr  ("... check mark"                     , x_share             , 'M');
   /*> yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");   <*/
   yUNIT_minval  ("call get mark"                      , REUSE__get (T_MASTER, x_share, x_desc, NULL, NULL)         ,   10);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "some repeating stuff");
   yUNIT_mindnoc ();

   /*> yURG_err_clear ();                                                             <*/
   yUNIT_mincond ("attempt with just suffix");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_master,  15, "GLOBAL"   ,  0, "GLOBAL -c-  wrong case           "   , x_desc, '-', &x_share), -999);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "A-----�-----M-----�-----�-   �-----�-----�-----�-----�-");
   yUNIT_minchr  ("... check mark"                     , x_share             , '-');
   /*> yUNIT_minstr  ("... check error message"            , yURG_err_last (), "master.unit:15:0: error: �GLOBAL -c-� identifier �c� not valid �ABCDEFGHIJKLMNOPQRSTUVWXYZ�");   <*/
   yUNIT_minval  ("call get mark"                      , REUSE__get (T_MASTER, x_share, x_desc, NULL, NULL)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_mindnoc ();

   /*> yURG_err_clear ();                                                             <*/
   yUNIT_mincond ("attempt to redefine idenfitier");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_master,  15, "GLOBAL"   ,  0, "GLOBAL -M-  re-defining          "   , x_desc, '-', &x_share), -999);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "A-----�-----M-----�-----�-   �-----�-----�-----�-----�-");
   yUNIT_minchr  ("... check mark"                     , x_share             , '-');
   /*> yUNIT_minstr  ("... check error message"            , yURG_err_last (), "master.unit:15:0: error: �GLOBAL -M-� identifier �M� already in use");   <*/
   yUNIT_minval  ("call get mark"                      , REUSE__get (T_MASTER, x_share, x_desc, NULL, NULL)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_mindnoc ();

   /*> yURG_err_clear ();                                                             <*/
   yUNIT_mincond ("attempt to define outside master.unit");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_name  ,  20, "GLOBAL"   ,  0, "GLOBAL -M-  re-defining          "   , x_desc, '-', &x_share), -999);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "A-----�-----M-----�-----�-   �-----�-----�-----�-----�-");
   yUNIT_minchr  ("... check mark"                     , x_share             , '-');
   /*> yUNIT_minstr  ("... check error message"            , yURG_err_last (), "apate.unit:20:0: error: GLOBAL verb not allowed outside master.unit");   <*/
   yUNIT_minval  ("call get mark"                      , REUSE__get (T_MASTER, x_share, x_desc, NULL, NULL)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_mindnoc ();

   /*> yURG_err_clear ();                                                             <*/
   yUNIT_mincond ("verify another global identifier");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_master,  30, "GLOBAL"   ,  0, "GLOBAL -Y-  final check          "   , x_desc, '-', &x_share), 1);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "A-----�-----M-----�-----Y-   �-----�-----�-----�-----�-");
   yUNIT_minchr  ("... check mark"                     , x_share             , 'Y');
   /*> yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");   <*/
   yUNIT_minval  ("call get mark"                      , REUSE__get (T_MASTER, x_share, x_desc, NULL, NULL)         ,   30);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "final check");
   yUNIT_mindnoc ();

   /*> yURG_err_clear ();                                                             <*/
   yUNIT_mincond ("attempt reusing inside itself");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_master,  35, "REUSE"    ,  0, "REUSE  -A-  - - - - - - - - - -  "   , x_desc, 'A', &x_share), -999);
   yUNIT_minchr  ("... check mark"                     , x_share             , '-');
   /*> yUNIT_minstr  ("... check error message"            , yURG_err_last (), "master.unit:35:0: error: �REUSE  -A-� verb identifier �A� called inside itself, recursive");   <*/
   yUNIT_mindnoc ();

   PROG__unit_end    ();
   yUNIT_minprcs ();
   return 0;
}

char
unit_reuse_shared (void)
{
   char        x_master    [LEN_TITLE] = "master.unit";
   char        x_name      [LEN_TITLE] = "apate.unit";
   char        x_desc      [LEN_LONG]  = "";
   char        x_share     =  '-';

   yUNIT_minscrpy ("koios", "koios_reuse", "(REUSE) parsing local SHARED reuses");
   /*> yURG_err_none ();                                                              <*/
   PROG__unit_quiet  ();

   yUNIT_mincond ("set to defaults");
   yUNIT_minval  ("... run clear"                      , REUSE_init ()       , 0);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "�-----�-----�-----�-----�-   �-----�-----�-----�-----�-");
   yUNIT_mindnoc ();

   /*> yURG_err_clear ();                                                             <*/
   yUNIT_mincond ("verify ignoring other verbs");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_name  ,   0, "exec"     ,  0, "  exec      read a line          "   , x_desc, '-', &x_share),    0);
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_name  ,   0, "SCRP"     ,  0, "SCRP        test the reading     "   , x_desc, '-', &x_share),    0);
   yUNIT_mindnoc ();

   /*> yURG_err_clear ();                                                             <*/
   yUNIT_mincond ("attempt reusing a missing identifier");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_name  ,   1, "REUSE"    ,  0, "REUSE  -k-  - - - - - - - - - -  "   , x_desc, '-', &x_share), -999);
   yUNIT_minchr  ("... check mark"                     , x_share             , '-');
   /*> yUNIT_minstr  ("... check error message"            , yURG_err_last (), "apate.unit:1:0: error: �REUSE  -k-� verb identifier �k� never set by SHARED");   <*/
   yUNIT_mindnoc ();

   /*> yURG_err_clear ();                                                             <*/
   yUNIT_mincond ("attempt reusing a illegal identifier");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_name  ,   3, "REUSE"    ,  0, "REUSE  -�-  - - - - - - - - - -  "   , x_desc, '-', &x_share), -999);
   yUNIT_minchr  ("... check mark"                     , x_share             , '-');
   /*> yUNIT_minstr  ("... check error message"            , yURG_err_last (), "apate.unit:3:0: error: �REUSE  -�-� verb identifier �� not valid [a-zA-Z]");   <*/
   yUNIT_mindnoc ();

   /*> yURG_err_clear ();                                                             <*/
   yUNIT_mincond ("verify simple share identifier");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_name  ,   5, "SHARED"   ,  0, "SHARED -a-  generate test data   "   , x_desc, '-', &x_share), 1);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "�-----�-----�-----�-----�-   a-----�-----�-----�-----�-");
   yUNIT_minchr  ("... check mark"                     , x_share             , 'a');
   /*> yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");   <*/
   yUNIT_minval  ("call get mark"                      , REUSE__get (T_SHARES, x_share, x_desc, NULL, NULL)         ,    5);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "generate test data");
   yUNIT_mindnoc ();

   /*> yURG_err_clear ();                                                             <*/
   yUNIT_mincond ("verify reusing the identifier (in normal unit)");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_name  ,   5, "REUSE"    ,  0, "REUSE  -a-  - - - - - - - - - -  "   , x_desc, '-', &x_share), 1);
   yUNIT_minchr  ("... check mark"                     , x_share             , 'a');
   /*> yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");   <*/
   yUNIT_mindnoc ();

   /*> yURG_err_clear ();                                                             <*/
   yUNIT_mincond ("attempt reusing the identifier (in master unit)");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_master,   5, "REUSE"    ,  0, "REUSE  -a-  - - - - - - - - - -  "   , x_desc, '-', &x_share), -999);
   yUNIT_minchr  ("... check mark"                     , x_share             , '-');
   /*> yUNIT_minstr  ("... check error message"            , yURG_err_last (), "master.unit:5:0: error: REUSE verb on �a� SHARED identifier not allowed inside master.unit");   <*/
   yUNIT_mindnoc ();

   /*> yURG_err_clear ();                                                             <*/
   yUNIT_mincond ("verify defenses");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_name  ,   0, NULL       ,  0, "REUSE  -a-  - - - - - - - - - -  "   , x_desc, '-', &x_share), -999);
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_name  ,   0, "REUSE"    ,  0, NULL                                      , x_desc, '-', &x_share), -999);
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_name  ,   0, "REUSE"    ,  0, "REUSE  -a-  - - - - - - - - - -  "   , x_desc, '-', NULL    ), -999);
   yUNIT_mindnoc ();

   /*> yURG_err_clear ();                                                             <*/
   yUNIT_mincond ("attempt without a identifier");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_name  ,   6, "SHARED"   ,  0, "SHARED      oops                 "   , x_desc, '-', &x_share), -999);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "�-----�-----�-----�-----�-   a-----�-----�-----�-----�-");
   yUNIT_minchr  ("... check mark"                     , x_share             , '-');
   /*> yUNIT_minstr  ("... check error message"            , yURG_err_last (), "apate.unit:6:0: error: �SHARED� missing valid identifier string, e.g., -a-");   <*/
   yUNIT_minval  ("call get mark"                      , REUSE__get (T_SHARES, x_share, x_desc, NULL, NULL)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_mindnoc ();

   /*> yURG_err_clear ();                                                             <*/
   yUNIT_mincond ("attempt with weird delimiters");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_name  ,   7, "SHARED"   ,  0, "SHARED (r)  oops                 "   , x_desc, '-', &x_share), -999);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "�-----�-----�-----�-----�-   a-----�-----�-----�-----�-");
   yUNIT_minchr  ("... check mark"                     , x_share             , '-');
   /*> yUNIT_minstr  ("... check error message"            , yURG_err_last (), "apate.unit:7:0: error: �SHARED (r)� missing valid identifier string, e.g., -a-");   <*/
   yUNIT_minval  ("call get mark"                      , REUSE__get (T_SHARES, x_share, x_desc, NULL, NULL)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_mindnoc ();

   /*> yURG_err_clear ();                                                             <*/
   yUNIT_mincond ("attempt with no suffix");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_name  ,   8, "SHARED"   ,  0, "SHARED -r   oops                 "   , x_desc, '-', &x_share), -999);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "�-----�-----�-----�-----�-   a-----�-----�-----�-----�-");
   yUNIT_minchr  ("... check mark"                     , x_share             , '-');
   /*> yUNIT_minstr  ("... check error message"            , yURG_err_last (), "apate.unit:8:0: error: �SHARED -r� identifier �-r� does not end with -, e.g., -a-");   <*/
   yUNIT_minval  ("call get mark"                      , REUSE__get (T_SHARES, x_share, x_desc, NULL, NULL)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_mindnoc ();

   /*> yURG_err_clear ();                                                             <*/
   yUNIT_mincond ("attempt with just suffix");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_name  ,   9, "SHARED"   ,  0, "SHARED -r)  oops                 "   , x_desc, '-', &x_share), -999);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "�-----�-----�-----�-----�-   a-----�-----�-----�-----�-");
   yUNIT_minchr  ("... check mark"                     , x_share             , '-');
   /*> yUNIT_minstr  ("... check error message"            , yURG_err_last (), "apate.unit:9:0: error: �SHARED -r)� identifier �-r)� does not end with -, e.g., -a-");   <*/
   yUNIT_minval  ("call get mark"                      , REUSE__get (T_SHARES, x_share, x_desc, NULL, NULL)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_mindnoc ();

   /*> yURG_err_clear ();                                                             <*/
   yUNIT_mincond ("verify another global identifier");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_name  ,  10, "SHARED"   ,  0, "SHARED -r-  some repeating stuff "   , x_desc, '-', &x_share), 1);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "�-----�-----�-----�-----�-   a-----�-----�----r�-----�-");
   yUNIT_minchr  ("... check mark"                     , x_share             , 'r');
   /*> yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");   <*/
   yUNIT_minval  ("call get mark"                      , REUSE__get (T_SHARES, x_share, x_desc, NULL, NULL)         ,   10);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "some repeating stuff");
   yUNIT_mindnoc ();

   /*> yURG_err_clear ();                                                             <*/
   yUNIT_mincond ("attempt with just suffix");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_name  ,  15, "SHARED"   ,  0, "SHARED -C-  wrong case           "   , x_desc, '-', &x_share), -999);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "�-----�-----�-----�-----�-   a-----�-----�----r�-----�-");
   yUNIT_minchr  ("... check mark"                     , x_share             , '-');
   /*> yUNIT_minstr  ("... check error message"            , yURG_err_last (), "apate.unit:15:0: error: �SHARED -C-� identifier �C� not valid �abcdefghijklmnopqrstuvwxyz�");   <*/
   yUNIT_minval  ("call get mark"                      , REUSE__get (T_SHARES, x_share, x_desc, NULL, NULL)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_mindnoc ();

   /*> yURG_err_clear ();                                                             <*/
   yUNIT_mincond ("attempt to redefine idenfitier");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_name  ,  15, "SHARED"   ,  0, "SHARED -r-  re-defining          "   , x_desc, '-', &x_share), -999);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "�-----�-----�-----�-----�-   a-----�-----�----r�-----�-");
   yUNIT_minchr  ("... check mark"                     , x_share             , '-');
   /*> yUNIT_minstr  ("... check error message"            , yURG_err_last (), "apate.unit:15:0: error: �SHARED -r-� identifier �r� already in use");   <*/
   yUNIT_minval  ("call get mark"                      , REUSE__get (T_SHARES, x_share, x_desc, NULL, NULL)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_mindnoc ();

   /*> yURG_err_clear ();                                                             <*/
   yUNIT_mincond ("attempt to define inside master.unit");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_master,  20, "SHARED"   ,  0, "SHARED -r-  re-defining          "   , x_desc, '-', &x_share), -999);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "�-----�-----�-----�-----�-   a-----�-----�----r�-----�-");
   yUNIT_minchr  ("... check mark"                     , x_share             , '-');
   /*> yUNIT_minstr  ("... check error message"            , yURG_err_last (), "master.unit:20:0: error: SHARED verb not allowed inside master.unit");   <*/
   yUNIT_minval  ("call get mark"                      , REUSE__get (T_SHARES, x_share, x_desc, NULL, NULL)         , -999);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "");
   yUNIT_mindnoc ();

   /*> yURG_err_clear ();                                                             <*/
   yUNIT_mincond ("verify another global identifier");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_name  ,  30, "SHARED"   ,  0, "SHARED -z-  final check          "   , x_desc, '-', &x_share), 1);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "�-----�-----�-----�-----�-   a-----�-----�----r�-----�z");
   yUNIT_minchr  ("... check mark"                     , x_share             , 'z');
   /*> yUNIT_minstr  ("... check error message"            , yURG_err_last (), "");   <*/
   yUNIT_minval  ("call get mark"                      , REUSE__get (T_SHARES, x_share, x_desc, NULL, NULL)         ,   30);
   yUNIT_minstr  ("... show desc"                      , x_desc                           , "final check");
   yUNIT_mindnoc ();

   /*> yURG_err_clear ();                                                             <*/
   yUNIT_mincond ("attempt reusing inside itself");
   yUNIT_minval  ("check reuses"                       , REUSE_parse (x_name  ,  35, "REUSE"    ,  0, "REUSE  -a-  - - - - - - - - - -  "   , x_desc, 'a', &x_share), -999);
   yUNIT_minchr  ("... check mark"                     , x_share             , '-');
   /*> yUNIT_minstr  ("... check error message"            , yURG_err_last (), "apate.unit:35:0: error: �REUSE  -a-� verb identifier �a� called inside itself, recursive");   <*/
   yUNIT_mindnoc ();

   PROG__unit_end    ();
   yUNIT_minprcs ();
   return 0;
}

char
unit_reuse_update (void)
{
   char        x_master    [LEN_TITLE] = "master.globals";
   char        x_name      [LEN_TITLE] = "apate.unit";
   char        x_desc      [LEN_LONG]  = "";
   int         x_conds     =    0;
   int         x_steps     =    0;
   char        x_share     =  '-';

   yUNIT_minscrpy ("koios", "koios_reuse", "(REUSE) importing and exporting reuse data");
   /*> yURG_err_none ();                                                              <*/
   PROG__unit_quiet  ();

   yUNIT_mincond ("set to defaults");
   yUNIT_minval  ("... run clear"                      , REUSE_init ()       , 0);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "�-----�-----�-----�-----�-   �-----�-----�-----�-----�-");
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify updating a mark with stats");
   yUNIT_minval  ("call set"                           , REUSE__set   (T_MASTER, 'A', 123, "verify something")         , 0);
   yUNIT_minval  ("call update"                        , REUSE_update ('A',   5,  15)                                  , 0);
   yUNIT_minstr  ("... review"                         , REUSE__used  ()      , "A-----�-----�-----�-----�-   �-----�-----�-----�-----�-");
   yUNIT_minval  ("call get mark"                      , REUSE__get   (T_MASTER, 'A', x_desc, &x_conds, &x_steps)      , 123);
   yUNIT_minstr  ("... show desc"                      , x_desc       , "verify something");
   yUNIT_minval  ("... show conds"                     , x_conds      , 5);
   yUNIT_minval  ("... show steps"                     , x_steps      , 15);
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify updating a second mark with stats");
   yUNIT_minval  ("call set"                           , REUSE__set   (T_MASTER, 'J', 678, "big shared global")        , 0);
   yUNIT_minval  ("call update"                        , REUSE_update ('J',  21,  62)                                  , 0);
   yUNIT_minstr  ("... review"                         , REUSE__used  ()      , "A-----�--J--�-----�-----�-   �-----�-----�-----�-----�-");
   yUNIT_minval  ("call get mark"                      , REUSE__get   (T_MASTER, 'J', x_desc, &x_conds, &x_steps)      , 678);
   yUNIT_minstr  ("... show desc"                      , x_desc       , "big shared global");
   yUNIT_minval  ("... show conds"                     , x_conds      , 21);
   yUNIT_minval  ("... show steps"                     , x_steps      , 62);
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify exporting");
   yUNIT_minval  ("call export"                        , REUSE_export (x_master)                                       , 0);
   /*> yUNIT_minstr  ("... check lines"                    , yURG_peek (x_master,   0), "A  123 verify�something                                                               5   15");   <*/
   /*> yUNIT_minstr  ("... check lines"                    , yURG_peek (x_master, '�'), "B   -1                                                                                0    0");   <*/
   /*> yUNIT_minstr  ("... check lines"                    , yURG_peek (x_master, '�'), "C   -1                                                                                0    0");   <*/
   /*> yUNIT_minstr  ("... check lines"                    , yURG_peek (x_master, '�'), "D   -1                                                                                0    0");   <*/
   /*> yUNIT_minstr  ("... check lines"                    , yURG_peek (x_master, '�'), "E   -1                                                                                0    0");   <*/
   /*> yUNIT_minstr  ("... check lines"                    , yURG_peek (x_master, '�'), "F   -1                                                                                0    0");   <*/
   /*> yUNIT_minstr  ("... check lines"                    , yURG_peek (x_master, '�'), "G   -1                                                                                0    0");   <*/
   /*> yUNIT_minstr  ("... check lines"                    , yURG_peek (x_master, '�'), "H   -1                                                                                0    0");   <* 
    *> yUNIT_minstr  ("... check lines"                    , yURG_peek (x_master, '�'), "I   -1                                                                                0    0");   <* 
    *> yUNIT_minstr  ("... check lines"                    , yURG_peek (x_master, '�'), "J  678 big�shared�global                                                             21   62");   <* 
    *> yUNIT_minstr  ("... check lines"                    , yURG_peek (x_master, '�'), "K   -1                                                                                0    0");   <* 
    *> yUNIT_minstr  ("... check lines"                    , yURG_peek (x_master, '�'), "L   -1                                                                                0    0");   <* 
    *> yUNIT_minstr  ("... check lines"                    , yURG_peek (x_master, '�'), "M   -1                                                                                0    0");   <* 
    *> yUNIT_minstr  ("... check lines"                    , yURG_peek (x_master, '�'), "N   -1                                                                                0    0");   <* 
    *> yUNIT_minstr  ("... check lines"                    , yURG_peek (x_master, '�'), "O   -1                                                                                0    0");   <* 
    *> yUNIT_minstr  ("... check lines"                    , yURG_peek (x_master, '�'), "P   -1                                                                                0    0");   <* 
    *> yUNIT_minstr  ("... check lines"                    , yURG_peek (x_master, '�'), "Q   -1                                                                                0    0");   <* 
    *> yUNIT_minstr  ("... check lines"                    , yURG_peek (x_master, '�'), "R   -1                                                                                0    0");   <* 
    *> yUNIT_minstr  ("... check lines"                    , yURG_peek (x_master, '�'), "S   -1                                                                                0    0");   <* 
    *> yUNIT_minstr  ("... check lines"                    , yURG_peek (x_master, '�'), "T   -1                                                                                0    0");   <* 
    *> yUNIT_minstr  ("... check lines"                    , yURG_peek (x_master, '�'), "U   -1                                                                                0    0");   <* 
    *> yUNIT_minstr  ("... check lines"                    , yURG_peek (x_master, '�'), "V   -1                                                                                0    0");   <* 
    *> yUNIT_minstr  ("... check lines"                    , yURG_peek (x_master, '�'), "W   -1                                                                                0    0");   <* 
    *> yUNIT_minstr  ("... check lines"                    , yURG_peek (x_master, '�'), "X   -1                                                                                0    0");   <* 
    *> yUNIT_minstr  ("... check lines"                    , yURG_peek (x_master, '�'), "Y   -1                                                                                0    0");   <* 
    *> yUNIT_minstr  ("... check lines"                    , yURG_peek (x_master, '�'), "Z   -1                                                                                0    0");   <* 
    *> yUNIT_minstr  ("... check lines"                    , yURG_peek (x_master, '�'), ""                                                                                            );   <*/
   yUNIT_mindnoc ();

   yUNIT_mincond ("set to defaults");
   yUNIT_minval  ("... run clear"                      , REUSE_init ()       , 0);
   yUNIT_minstr  ("... review marks"                   , REUSE__used ()      , "�-----�-----�-----�-----�-   �-----�-----�-----�-----�-");
   yUNIT_mindnoc ();

   yUNIT_mincond ("verify importing");
   yUNIT_minval  ("call import"                        , REUSE_import (x_master)                                       , 0);
   yUNIT_minstr  ("... review"                         , REUSE__used  ()      , "A-----�--J--�-----�-----�-   �-----�-----�-----�-----�-");
   yUNIT_minval  ("call get mark"                      , REUSE__get   (T_MASTER, 'A', x_desc, &x_conds, &x_steps)      , 123);

   x_conds =  25;  x_steps = 100;
   yUNIT_mincond ("verify adding to counters");
   yUNIT_minval  ("call add"                           , REUSE_add    ('J', &x_conds, &x_steps)              , 0);
   yUNIT_minstr  ("... show desc"                      , x_desc       , "verify something");
   yUNIT_minval  ("... show conds"                     , x_conds      , 46);
   yUNIT_minval  ("... show steps"                     , x_steps      , 162);
   yUNIT_mindnoc ();

   PROG__unit_end    ();
   yUNIT_minprcs ();
   return 0;
}

char
main                    (void)
{
   /*---(program wide)-------------------*/
   system ("rm -f koios_wave.wave");
   unit_reuse_index  ();
   unit_reuse_getset ();
   unit_reuse_global ();
   unit_reuse_shared ();
   unit_reuse_update ();
   yUNIT_mintinu     ();
   system ("rm    -f apate.unit        > /dev/null   2>&1");
   return 0;
}

