/*===============================[[ beg-code ]]===============================*/
#include    "koios.h"

#include    <yUNIT_solo.h>
#include    <ySTR_solo.h>
#include    <yCOLOR_solo.h>


char  *s_wave     = "/tmp/master.wave";

char
unit_ditto_index  (void)
{
   /*---(header)-------------------------*/
   yUNIT_minscrpy ("koios", "koios_ditto", "(DITTO) retrieving ditto indexes");
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
   yUNIT_minval  ("... run �"                          , DITTO__index ('�'), -999);
   yUNIT_mindnoc ();

   yUNIT_mincond ("attempt invalid indexes");
   yUNIT_minval  ("... run a"                          , DITTO__index ('a'), -999);
   yUNIT_minval  ("... run D"                          , DITTO__index ('D'), -999);
   yUNIT_minval  ("... run +"                          , DITTO__index ('+'), -999);
   yUNIT_minval  ("... run �"                          , DITTO__index ('�'), -999);
   yUNIT_minval  ("... run �"                          , DITTO__index ('�'), -999);
   yUNIT_mindnoc ();

   /*---(complete)-----------------------*/
   PROG__unit_end    ();
   yUNIT_minprcs ();
   return 0;
}

char
unit_ditto_getset (void)
{

   char        x_desc      [LEN_LONG]  = "";
   /*---(header)-------------------------*/
   yUNIT_minscrpy ("koios", "koios_ditto", "(DITTO) setting and setting ditto marks");
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
   yUNIT_minprcs ();
   return 0;
}

char
unit_ditto_toggle (void)
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
   /*---(header)-------------------------*/
   yUNIT_minscrpy ("koios", "koios_ditto", "(DITTO) in-line marking of begin and end points");
   PROG__unit_quiet  ();

   yUNIT_mincond  ("prepare clean start");
   system ("touch apate.unit           2> /dev/null");
   x_main = fopen (x_name, "rt");
   x_scrp = x_main;
   yUNIT_mindnoc  ();

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
   /*> yUNIT_minstr   ("... check error message"            , yURG_err_last (), "");   <*/
   yUNIT_mindnoc  ();

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
   /*> yUNIT_minstr   ("... check error message"            , yURG_err_last (), "apate.unit:100:0: error: DITTO '0' can not start as dittoing already active");   <*/
   yUNIT_mindnoc  ();

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
   /*> yUNIT_minstr   ("... check error message"            , yURG_err_last (), "");   <*/
   yUNIT_mindnoc  ();

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
   /*> yUNIT_minstr   ("... check error message"            , yURG_err_last (), "apate.unit:100:0: error: DITTO '5' not set by previous COND");   <*/

   /*> yURG_err_clear ();                                                             <*/
   yUNIT_mincond ("wrap up");
   fclose (x_main);
   yUNIT_mindnoc  ();

   PROG__unit_quiet  ();
   system ("rm    -f apate.unit        > /dev/null   2>&1");
   yUNIT_minprcs  ();
   return 0;
}

char
unit_ditto_read   (void)
{
   int         x_ditto  =    0;
   int         x_line   =    0;
   int         x_dline  =    0;
   /*---(header)-------------------------*/
   yUNIT_minscrpy ("koios", "koios_ditto", "(DITTO) read numbering of ditto lines");
   /*> yURG_err_none ();                                                              <*/
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
   yUNIT_minprcs ();
   return 0;
}

char
unit_ditto_parse  (void)
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
   /*---(header)-------------------------*/
   yUNIT_minscrpy ("koios", "koios_ditto", "(DITTO) ditto  parsing");
   /*> yURG_err_none  ();                                                             <*/
   PROG__unit_quiet  ();
   system ("rm    -f apate.unit        > /dev/null   2>&1");

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
   system ("rm    -f apate.unit        > /dev/null   2>&1");
   yUNIT_minprcs  ();
   return 0;
}


char
main                    (void)
{
   /*---(program wide)-------------------*/
   system ("rm -f koios_ditto.wave");
   unit_ditto_index  ();
   unit_ditto_getset ();
   unit_ditto_toggle ();
   unit_ditto_read   ();
   unit_ditto_parse  ();
   yUNIT_mintinu     ();
   return 0;
}

