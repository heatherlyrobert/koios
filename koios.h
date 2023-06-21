/*===============================[[ beg code ]]===============================*/


/*===[[ HEADER ]]=============================================================*/

/*--------- 12345678901 ´123456789-123456789-123456789-123456789-123456789-123456789-123456789-*/
/*········· ··········· ´·····························´········································*/
#define     P_FOCUS     "PS (programming support)"
#define     P_NICHE     "st (string testing)"
#define     P_SUBJECT   "unit testing meta-language"
#define     P_PURPOSE   "provide simple unit testing framework for writing scripts"
/*········· ··········· ´·····························´········································*/
#define     P_NAMESAKE  "koios-polos (axis of heaven)"
#define     P_PRONOUNCE "kee·ohs poh·lohs"
#define     P_HERITAGE  "titan god of intelligence, farsight, and the inquisitive mind"
#define     P_BRIEFLY   "quick, inquisitive mind"
#define     P_IMAGERY   "very tall, dark armor, with blue-white eyes, hair, and beard"
#define     P_REASON    "the inquisitive mind of koios pitted against unit testing"
/*········· ··········· ´·····························´········································*/
#define     P_ONELINE   P_NAMESAKE " " P_SUBJECT
/*········· ··········· ´·····························´········································*/
#define     P_HOMEDIR   "/home/system/koios.unit_test_generator"
#define     P_BASENAME  "koios"
#define     P_FULLPATH  "/usr/local/bin/koios"
#define     P_SUFFIX    "unit"
#define     P_CONTENT   "unit test script"
/*········· ··········· ´·····························´········································*/
#define     P_SYSTEM    "gnu/linux   (powerful, ubiquitous, technical, and hackable)"
#define     P_LANGUAGE  "ansi-c      (wicked, limitless, universal, and everlasting)"
#define     P_COMPILER  "gcc 5.3.0"
#define     P_CODESIZE  "small       (appoximately 1,000 slocl)"
/*········· ··········· ´·····························´········································*/
#define     P_DEPENDS   "none"
/*········· ··········· ´·····························´········································*/
#define     P_AUTHOR    "heatherlyrobert"
#define     P_CREATED   "2014-03"
/*········· ··········· ´·····························´········································*/
#define     P_VERMAJOR  "1.-- production"
#define     P_VERMINOR  "1.4- start removing globals from functions (into parameters)"
#define     P_VERNUM    "1.4c"
#define     P_VERTXT    "GLOBAL and SHARED parsing updated, need to finish REUSE testing"
/*········· ··········· ´·····························´········································*/

/*>                                                                                   <* 
 *> 24 testing phases in 6 loose blocks to help sequence (like visual look)           <* 
 *>                                                                                   <* 
 *> basics, functionality, safety, and string                                         <* 
 *> SCRP  [Àè] [Àé] [Àê] [Àë]      simple dependencies, only to · in its own file     <* 
 *> SCRP  [Áì] [Áí] [Áî] [Áï]      dependent on À or less, or Á in its own file       <* 
 *> SCRP  [Âð] [Âñ] [Âò] [Âó]      dependent on Á or less, or Â in its own file       <* 
 *>                                                                                   <* 
 *> integration testing                                                               <* 
 *> SCRP  [Ãô] [Ãõ] [Ãö] [Ã÷]      dependent on Â or less, or Ã in its own file       <* 
 *> SCRP  [Äø] [Äù] [Äú] [Äû]      dependent on Ã or less, or Ä in its own file       <* 
 *>                                                                                   <* 
 *> testing library in a host application (e.g., gyges testing yMACRO)                <* 
 *> SCRP  [Åü] [Åý] [Åþ] [Åÿ]      dependent on Ä or less, or Å in its own file       <* 
 *>                                                                                   <* 
 *> its not perfect, but i don't want more than solid guidance (80:20 solution)       <* 
 *>   second character is unique/enough, but the first one helps w/quick inspection   <* 
 *>                                                                                   <*/

/*>                                                                                   <* 
 *> ORIGINAL WITH WAVES                                                               <* 
 *>                                                                                   <* 
 *> SCRP  [·è] [·é] [·ê] [·ë]      simple dependencies, only to · in its own file     <* 
 *> SCRP  [´ì] [´í] [´î] [´ï]      dependent on · or less, or ´ in its own file       <* 
 *> SCRP  [ ð] [ ñ] [ ò] [ ó]      dependent on ´ or less, or   in its own file       <* 
 *> SCRP  [Ïô] [Ïõ] [Ïö] [Ï÷]      dependent on   or less, or Ï in its own file       <* 
 *> SCRP  [¬ø] [¬ù] [¬ú] [¬û]      dependent on Ï or less, or ¬ in its own file       <* 
 *> SCRP  [°ü] [°ý] [°þ] [°ÿ]      integration/string tests                           <* 
 *>                                                                                   <*/

/*>                                                                                   <* 
 *> POTENTIAL SYMBOL UPDATE                                                           <* 
 *>                                                                                   <* 
 *> basics, functionality, and safety                                                 <* 
 *> SCRP  [áè] [áé] [áê] [áë]      simple dependencies, only to · in its own file     <* 
 *> SCRP  [ ì] [ í] [ î] [ ï]      dependent on · or less, or   in its own file       <* 
 *> SCRP  [¬ð] [¬ñ] [¬ò] [¬ó]      dependent on   or less, or ¬ in its own file       <* 
 *>                                                                                   <* 
 *> strings, integration, and debugging                                               <* 
 *> SCRP  [´ô] [´õ] [´ö] [´÷]      dependent on ¬ or less, or ´ in its own file       <* 
 *> SCRP  [Ïø] [Ïù] [Ïú] [Ïû]      dependent on ´ or less, or Ï in its own file       <* 
 *> SCRP  [°ü] [°ý] [°þ] [°ÿ]      dependent on Ï or less, or ° in its own file       <* 
 *>                                                                                   <* 
 *>                                                                                   <*/

/*>                                                                                   <* 
 *> ATTEMPT AT MORE ALPHA                                                             <* 
 *>                                                                                   <* 
 *> basics, functionality, and safety                                                 <* 
 *> SCRP  [aè] [aé] [aê] [aë]      simple dependencies, only to · in its own file     <* 
 *> SCRP  [bì] [bí] [bî] [bï]      dependent on · or less, or   in its own file       <* 
 *> SCRP  [cð] [cñ] [cò] [có]      dependent on   or less, or ¬ in its own file       <* 
 *>                                                                                   <* 
 *> strings, integration, and debugging                                               <* 
 *> SCRP  [dô] [dõ] [dö] [d÷]      dependent on ¬ or less, or ´ in its own file       <* 
 *> SCRP  [eø] [eù] [eú] [eû]      dependent on ´ or less, or Ï in its own file       <* 
 *> SCRP  [fü] [fý] [fþ] [fÿ]      dependent on Ï or less, or ° in its own file       <* 
 *>                                                                                   <* 
 *>                                                                                   <*/

/*>                                                                                   <* 
 *> ATTEMPT AT FULLY ALPHA                                                            <* 
 *>                                                                                   <* 
 *> SCRP  [1è] [1é] [1ê] [1ë]      simple dependencies, only to · in its own file     <* 
 *> SCRP  [2è] [2é] [2ê] [2ë]      dependent on · or less, or ´ in its own file       <* 
 *> SCRP  [3è] [3é] [3ê] [3ë]      dependent on ´ or less, or   in its own file       <* 
 *> SCRP  [4è] [4é] [4ê] [4ë]      dependent on   or less, or Ï in its own file       <* 
 *> SCRP  [5è] [5é] [5ê] [5ë]      dependent on Ï or less, or ¬ in its own file       <* 
 *> SCRP  [6è] [6é] [6ê] [6ë]      integration/string tests                           <* 
 *>                                                                                   <*/

/*>                                                                                   <* 
 *> FIRST RUN (4 waves of 10 stages each)                                             <* 
 *>                                                                                   <* 
 *> SCRP  [è0] [è1] [è2] [è3] [è4] [è5] [è6] [è7] [è8] [è9]                           <* 
 *> SCRP  [é0] [é1] [é2] [é3] [é4] [é5] [é6] [èé] [é8] [é9]                           <* 
 *> SCRP  [ê0] [ê1] [ê2] [ê3] [ê4] [ê5] [ê6] [ê7] [ê8] [ê9]                           <* 
 *> SCRP  [ë0] [ë1] [ë2] [ë3] [ë4] [ë5] [ë6] [ë7] [ë8] [ë9]                           <* 
 *>                                                                                   <* 
 *> just didn't play out right                                                        <* 
 *>                                                                                   <*/


/*===[[ SUMMARY ]]=============================================================#

 *   koios is a light, clean, simple, and fast metaprogram that reads a custom
 *   unit testing mini-language and either executes that unit test intepretively
 *   or compiles it into an executable to run at a later time.
 *
 */
/*===[[ PURPOSE ]]============================================================*/

/*   unit testing is a software verification and assurance method in which a
 *   programmer tests if individual units (functions) of source code are fit for
 *   use and remain so.  this form of testing is integral to build automation,
 *   refactoring, and regression testing.
 *
 *   unit testing is a critical topic and one that most people preach while
 *   hating to do themselves.  there are many unit testing frameworks,
 *   libraries, and full suites available.  even so, this is a neglected area.
 *   many libraries attach through raw code and can be very intrusive and
 *   dangerous.
 *
 *   koios focuses on providing a unit testing mini-language that can...
 *      -- break tests into scripts, conditions, and steps
 *      -- only touch programs under test through function calls
 *      -- conduct grey box testing through accessor and setter functions
 *      -- provides a wide variety of expect/actual results comparisons (yVAR)
 *
 *   as always, there are many existing libraries and utilities have been built
 *   by better programmers which are likely superior in speed, size, capability,
 *   and reliability; BUT, i would not have learned nearly as much using them,
 *   so follow the adage..
 *
 *   TO TRULY LEARN> do not seek to follow in the footsteps of the men of old;
 *   seek what they sought ~ Matsuo Basho
 *
 *   the basic idea is to take all the great ideas from existing frameworks
 *   without taking all the unneeded complexity that comes from backwards
 *   compatiblilty and traditional views.  in this case, if i can get the same
 *   result with less fuss and mess, even better
 *
 *
 *
 *
 *
 *   koios was the elder titan-god of intelligence, inquisitive mind, and
 *   foresight derived from knowledge and intellect.
 *
 *   in our context, koios will be the keeper of our testing framework which
 *   uses a deep understanding of programs in order to determine how they will
 *   perform in a production environment.
 *
 *   koios will focus on...
 *      -- interpreting the unit-text meta-language
 *      -- creating unit testing programs
 *
 */



/*===[[ HEADER GUARD ]]=======================================================*/
#ifndef YKOIOS
#define YKOIOS  loaded



/*===[[ STANDARD C LIBRARIES ]]===============================================*/
#include    <stdio.h>        /* C_ANSI : strcpy, strlen, strchr, strcmp, ...  */
#include    <string.h>       /* C_ANSI : printf, snprintf, fgets, fopen, ...  */
#include    <stdarg.h>       /* C_ANSI : variable argument handling           */
#include    <stdlib.h>       /* C_ANSI : system                               */
#include    <unistd.h>       /* stat(),crpyt()                                */
#include    <sys/stat.h>     /* stat, lstat                                   */
#include    <sys/types.h>    /* stat, lstat                                   */

/*===[[ CUSTOM LIBRARIES ]]===================================================*/
#include    <yUNIT.h>        /* CUSTOM : heatherly unit testing               */
#include    <yLOG.h>         /* CUSTOM : heatherly program logging            */
#include    <ySTR.h>         /* CUSTOM : heatherly safer string handling      */
#include    <yURG.h>         /* CUSTOM : heatherly urgent processing          */



#define     G_RUN_DEFAULT   '-'
#define     G_RUN_CREATE    'c'
#define     G_RUN_DEBUG     'd'
#define     G_RUN_UPDATE    'u'
#define     G_RUN_REPLACE   'r'


#define     T_MASTER    'm'
#define     T_SHARES    'r'
#define     T_DITTOS    'd'

#define     IF_MASTER     if (strcmp (my.n_base, "master") == 0)
#define     IF_NORMAL     if (strcmp (my.n_base, "master") != 0)

typedef struct stat      tSTAT;


typedef     struct cGLOBALS     tGLOBALS;
struct cGLOBALS
{
   /*---(general)---------------*/
   char        version     [LEN_FULL];      /* program version info           */
   char        run_type;                    /* unit test code or conversion   */
   char        replace;                     /* convert and replace file       */
   /*---(file names)------------*/
   char        n_ext       [LEN_TERSE];     /* .unit vs .sunit                */
   char        n_base      [LEN_PATH];      /* base name of files             */
   char        n_scrp      [LEN_TITLE];     /* name of input script file      */
   char        n_code      [LEN_PATH];      /* name of output code file       */
   char        n_main      [LEN_PATH];      /* name of output main file       */
   char        n_wave      [LEN_PATH];      /* name of master code file       */
   char        n_conv      [LEN_PATH];      /* name of output script file     */
   /*---(file handles)----------*/
   FILE       *f_scrp;                      /* pointer to input script file   */
   FILE       *f_code;                      /* pointer to output code file    */
   FILE       *f_main;                      /* pointer to output main file    */
   FILE       *f_wave;                      /* pointer to output wave file    */
   FILE       *f_conv;                      /* pointer to output script file  */
   /*---(counters)--------------*/
   int         n_line;                      /* file   all lines               */
   int         n_recd;                      /* file   good records            */
   int         nscrp;                       /* total count of scripts         */
   int         ncond;                       /* total count of conditions      */
   int         nstep;                       /* total count of steps           */
   int         scond;                       /* curr scrp count of conditions  */
   int         sstep;                       /* curr scrp count of steps       */
   int         cstep;                       /* current step number            */
   /*---(script)---------------*/
   char        recd        [LEN_RECD ];     /* script record                  */
   int         len;                         /* record length                  */
   char        status;                      /* record processing status       */
   int         indx;                        /* verb index in tVERB structure  */
   char        verb        [LEN_LABEL];     /* verb                           */
   char      (*p_conv) (void);;
   char      (*p_code) (void);;
   char        last        [LEN_LABEL];     /* last verb used                 */
   char        spec;                        /* specialty verb (y/n)           */
   char        vers        [LEN_LABEL];     /* version number                 */
   char        desc        [LEN_LONG ];     /* descriptive text               */
   char        meth        [LEN_HUND ];     /* function/method name           */
   char        args        [LEN_FULL];      /* function/method args           */
   char        test        [LEN_LABEL];     /* test type for yVAR             */
   char        expe        [LEN_RECD];      /* expected results               */
   char        retn        [LEN_FULL];      /* return variable                */
   char        code        [LEN_RECD ];     /* code/load/sys string           */
   /*---(special marks)---------*/
   char        stage       [LEN_SHORT];     /* master sequence                */
   char        cshare;                      /* current share                  */
   char        share;                       /* share marking                  */
   char        dittoing;                    /* currently dittoing             */
   char        dmark;                       /* current ditto mark             */
   int         ditto;                       /* current ditto position         */
   int         dline;                       /* current dittoing source line   */
   char        mark;                        /* ditto marking                  */
   char        d_used      [LEN_HUND];      /* ditto markes used              */
   /*---(working)---------------*/
   char        disp        [LEN_RECD ];     /* display ver " = ~, 1D = |      */
   char        syst        [LEN_RECD ];     /* system ver  " = ", 1D = 1F     */
   char        load        [LEN_RECD ];     /* load ver    " = ~, 1D = 1F     */
   /*---(flag)------------------*/
   char        driver;                      /* has main/driver been written   */
   /*---(debug/test)------------*/
   char        answer      [LEN_RECD ];     /* unit testing answer string     */
   char        updated     [LEN_RECD ];     /* converted record               */
   char        compiled    [LEN_RECD ];     /* converted record               */
   /*---(done)------------------*/
};
extern      tGLOBALS    my;


#define     MAX_VERB         30
typedef     struct cVERB    tVERB;
struct cVERB {
   char        name        [LEN_FULL];      /* verb                           */
   char        desc        [LEN_FULL];      /* description                    */
   char        spec;                        /* verb type for parsing          */
   char        files;                       /* master vs normal vs both       */
   int         count;                       /* number found in script         */
   int         total;                       /* number found in unit test      */
   char      (*conv) (void);                /* conversion function            */ 
   char      (*code) (void);                /* code function                  */ 
   char        ditto;                       /* can be within a DITTO          */
};
extern      tVERB       g_verbs [MAX_VERB];


extern char g_print     [LEN_LABEL];





/*===[[ PROG ]]===============================================================*/
/*---(support)--------------*/
char*       PROG_version            (void);
/*---(pre-init)-------------*/
char        PROG__header            (void);
char        PROG_urgents            (int a_argc, char *a_argv []);
/*---(start-up)-------------*/
char        PROG__init              (void);
char        PROG__file              (char a_name [LEN_PATH], char r_base [LEN_PATH], char r_ext [LEN_TERSE]);
char        PROG__args              (int a_argc, char *a_argv [], char *r_runtype, char *r_replace, char r_base [LEN_PATH], char r_ext [LEN_SHORT]);
char        PROG__begin             (void);
char        PROG_startup            (int a_argc, char *a_argv []);
/*---(shut-down)------------*/
char        PROG__end               (void);
char        PROG_shutdown           (void);
/*---(unittest)------------*/
char        PROG__unit_quiet        (void);
char        PROG__unit_loud         (void);
char        PROG__unit_end          (void);



/*===[[ SCRP ]]===============================================================*/
/*---(shared)--------------*/
char        SCRP__shared_clear      (cchar a_type);
char        SCRP__shared_purge      (void);
char        SCRP__shared_index      (cchar a_type, cchar a_mark);
char        SCRP__shared_set        (cchar a_type, cchar a_mark, int a_line);
int         SCRP__shared_get        (cchar a_type, cchar a_mark);
char*       SCRP__shared_used       (void);
/*---(dittos)--------------*/
char        SCRP__ditto_clear       (void);
char        SCRP__reuses_check      (cchar a_scrp [LEN_TITLE], int a_line, char a_indx, char *p, char a_cshare, char *r_share, char *r_dittoing, char *r_dmark, char *r_mark, int *r_ditto, int *r_dline);
char        SCRP__ditto_check       (cchar a_scrp [LEN_TITLE], int a_line, char a_indx, char *p);
char        SCRP_ditto__handler     (char a_dittoing, int a_ditto, int *r_nline, int *r_dline);
/*---(file)----------------*/
char        SCRP_open               (cchar a_name [LEN_RECD], FILE **r_file, int *r_line);
char        SCRP_close              (FILE **b_file);
char        SCRP_clear              (void);
char        SCRP_read               (FILE *a_file, int *r_nline, char a_dittoing, int a_ditto, int *r_dline, int *r_nrecd, int *r_len, char r_recd [LEN_RECD]);
/*---(parsing)-------------*/
char        SCRP__parse_defense     (cchar a_scrp [LEN_TITLE], int a_line, cchar a_recd [LEN_RECD], char r_verb [LEN_LABEL], char *r_indx, char *r_spec, char **r_conv, char **r_code, char r_stage [LEN_TERSE], char r_vers [LEN_TERSE], char r_desc [LEN_LONG], char r_meth [LEN_HUND], char r_args [LEN_FULL], char r_test [LEN_LABEL], char r_expe [LEN_RECD], char r_retn [LEN_FULL], char r_coding [LEN_RECD]);
char        SCRP__parse_comment     (cchar a_recd [LEN_RECD], char r_verb [LEN_LABEL], char *r_indx, char *r_spec, char **r_conv, char **r_code);
char        SCRP__parse_verb        (char a_scrp [LEN_TITLE], int a_line, char a_field [LEN_LABEL], char r_verb [LEN_LABEL], char *r_indx, char *r_spec, char **r_conv, char **r_code);
char        SCRP__parse_save        (char a_verb [LEN_LABEL], char a_indx, char a_spec, char *a_conv, char *a_code, char a_stage [LEN_TERSE], char a_vers [LEN_TERSE]);
char        SCRP__limits            (char a_spec, char *r_min, char *r_max);
char        SCRP__current           (cchar a_scrp [LEN_TITLE], int a_line, cchar a_verb [LEN_LABEL], char a_spec, char *a_first, char r_desc [LEN_LONG], char r_meth [LEN_HUND], char r_args [LEN_FULL], char r_test [LEN_LABEL], char r_expe [LEN_RECD], char r_retn [LEN_FULL], char r_coding [LEN_RECD]);
char        SCRP_vers21             (void);
char        SCRP_vers20             (void);
char        SCRP_vers19             (void);
char        SCRP_parse              (cchar a_scrp [LEN_TITLE], int a_line, cchar a_recd [LEN_RECD], char r_verb [LEN_LABEL], char *r_indx, char *r_spec, char **r_conv, char **r_code, char r_stage [LEN_TERSE], char r_vers [LEN_TERSE], char r_desc [LEN_LONG], char r_meth [LEN_HUND], char r_args [LEN_FULL], char r_test [LEN_LABEL], char r_expe [LEN_RECD], char r_retn [LEN_FULL], char r_coding [LEN_RECD]);
/*---(verbs)---------------*/
char        SCRP_verbs              (void);
char        SCRP_verbcode           (void);
/*---(unittest)------------*/
char*       SCRP__unit              (char *a_question, int a_num);



/*===[[ CODE ]]===============================================================*/
/*345678901-12345678901-12345678901-12345678901-12345678901-12345678901-123456*/
/*---(counts)--------------*/
char        CODE__shared_clear      (cchar a_type);
char        CODE__shared_purge      (void);
char        CODE__shared_index      (cchar a_type, cchar a_mark);
char        CODE__shared_set        (cchar a_type, cchar a_mark, int a_cond, int a_step);
char        CODE__shared_add        (cchar a_type, cchar a_mark, int *a_cond, int *a_step);
char*       CODE__shared_used       (void);
char        CODE_shared_out         (void);
char        CODE_shared_in          (void);
/*---(file)----------------*/
char        CODE_open               (void);
char        CODE_printf             (char *a_format, ...);
char        MAIN_printf             (char *a_format, ...);
char        CODE_close              (FILE *a_file);
char        CODE_cycle              (void);
char        CODE_write         (void);
char        CODE_beg           (void);
char        CODE_end           (void);
char        MAIN_beg           (void);
char        MAIN_end           (void);
char        MAIN_append        (void);
char        CODE_comment       (void);
char        CODE_prep          (void);
char        CODE_incl          (void);
char        CODE_scrp          (void);
char        CODE_scrp_end        (void);
char        CODE_sect          (void);
char        CODE_shared        (void);
char        CODE_global        (void);
char        CODE_group         (void);
char        CODE_cond          (void);
char        CODE_reuse         (void);
char        CODE_prefix        (char a_type);
char        CODE_expe_var      (char a_type);
char        CODE_suffix        (char a_type);
char        CODE_exec          (void);
char        CODE_echo          (void);
char        CODE_mode          (void);
char        CODE_gvar          (void);
char        CODE_lvar          (void);
char        CODE_code          (void);
char        CODE_load          (void);
char        CODE_file          (void);
char        CODE_append        (void);
char        CODE_system        (void);
char        CODE_unknown       (void);

/*===[[ CONV ]]===============================================================*/
/*345678901-12345678901-12345678901-12345678901-12345678901-12345678901-123456*/
/*---(file)--------------------*/
char        CONV_open               (void);
char        CONV_printf             (char *a_format, ...);
char        CONV_close              (void);
/*---(standards)---------------*/
char        CONV_beg                (void);
char        CONV_header             (void);
char        CONV_end                (void);
char        CONV_comment            (void);
char        CONV_prep               (void);
char        CONV_incl               (void);
char        CONV_scrp               (void);
char        CONV_sect               (void);
char        CONV_shared             (void);
char        CONV_global             (void);
char        CONV_group              (void);
char        CONV_cond               (void);
char        CONV_ditto              (void);
char        CONV_reuse              (void);
char        CONV_exec               (void);
char        CONV_echo               (void);
char        CONV_mode               (void);
char        CONV_code               (void);
char        CONV_gvar               (void);
char        CONV_load               (void);
char        CONV_file               (void);
char        CONV_append             (void);
char        CONV_driver             (void);
char*       CONV__unit              (char *a_question, int a_num);

void        VOID_void          (char *a_one, int a_two);



/*345678901-12345678901-12345678901-12345678901-12345678901-12345678901-123456*/
char        WAVE_parse              (char a_scrp [LEN_TITLE], int a_line, int a_indx, char a_verb [LEN_LABEL], char a_field [LEN_LABEL], char r_stage [LEN_SHORT]);
char        WAVE_open               (char a_base [LEN_HUND]);
char        WAVE_scrp               (char a_stage, char a_wave, char *a_base, char a_scrp, char *a_desc);
char        WAVE_close              (void);


/*===[[ koios_ditto.c ]]======================================================*/
/*········· ´······················ ´·········································*/
/*---(program)--------------*/
char        DITTO_purge             (void);
char        DITTO_init              (void);
char        DITTO_wrap              (void);
/*---(usage)----------------*/
char        DITTO__index            (cchar a_mark);
char        DITTO__set              (cchar a_mark, int a_line, char a_desc [LEN_LONG]);
char        DITTO__set_recd         (cchar a_mark, int a_line, char a_recd [LEN_RECD]);
int         DITTO__get              (cchar a_mark, char r_desc [LEN_LONG]);
/*---(toggle)---------------*/
char        DITTO_beg               (cchar a_scrp [LEN_TITLE], int a_line, cchar a_name [LEN_PATH], char a_runtype, char a_ditto, char a_mark, FILE **r_file, char *r_dittoing, char *r_dmark, char *r_mark, int *r_ditto, int *r_dline);
char        DITTO_end               (FILE **r_file, char *r_dittoing, char *r_dmark, int *r_ditto, int *r_dline);
/*---(reading)--------------*/
char        DITTO_read_numbering    (char a_dittoing, int a_ditto, int *r_nline, int *r_dline);
char        DITTO_read_prep         (char a_dittoing, int a_ditto, int *r_nline, int *r_dline);
char        DITTO_read_post         (cchar a_recd [LEN_RECD], FILE **r_file, char *r_dittoing, char *r_dmark, int *r_ditto, int *r_dline);
/*---(parsing)--------------*/
char        DITTO_parse_handler     (cchar a_scrp [LEN_TITLE], int a_line, char a_runtype, char a_verb [LEN_LABEL], char *a_field, char a_cshare, char *r_share, char *r_dittoing, char *r_dmark, char *r_mark, int *r_ditto, int *r_dline);
/*---(debugging)------------*/
char*       DITTO__used             (void);
/*---(done)-----------------*/


char        VERB_dittoable          (char a_verb [LEN_LABEL]);
char        VERB_parse              (char a_scrp [LEN_TITLE], int a_line, char a_field [LEN_LABEL], char r_verb [LEN_LABEL], char *r_indx, char *r_spec, char *r_locn, char **r_conv, char **r_code);


/*===[[ koios_read.c ]]=======================================================*/
/*········· ´······················ ´·········································*/
/*---(file)-----------------*/
char        READ_open               (cchar a_name [LEN_RECD], FILE **r_file, int *r_line);
char        READ_close              (FILE **b_file);
/*---(record)---------------*/
char        READ__defense           (FILE **r_file, int *r_nline, char *r_dittoing, char *r_dmark, int *r_ditto, int *r_dline, int *r_nrecd, char r_recd [LEN_RECD]);
char        READ__clear             (void);
char        READ__single            (FILE **r_file, int *r_nline, char *r_dittoing, char *r_dmark, int *r_ditto, int *r_dline, int *r_nrecd, char r_recd [LEN_RECD]);
char        READ_next               (FILE **r_file, int *r_nline, char *r_dittoing, char *r_dmark, int *r_ditto, int *r_dline, int *r_nrecd, char r_recd [LEN_RECD]);
/*---(done)-----------------*/



/*===[[ koios_reuse.c ]]======================================================*/
/*········· ´······················ ´·········································*/
/*---(program)--------------*/
char        REUSE_purge             (cchar a_type);
char        REUSE_init              (void);
char        REUSE_wrap              (void);
/*---(usage)----------------*/
char        REUSE__index            (cchar a_type, cchar a_mark);
char        REUSE__set              (cchar a_type, cchar a_mark, int a_line, char a_desc [LEN_LONG]);
char        REUSE__set_recd         (cchar a_type, cchar a_mark, int a_line, char a_recd [LEN_RECD]);
int         REUSE__get              (cchar a_type, cchar a_mark, char r_desc [LEN_LONG]);
/*---(parsing)--------------*/
char        REUSE_parse             (cchar a_scrp [LEN_TITLE], int a_line, char a_verb [LEN_LABEL], char a_recd [LEN_RECD], char a_cshare, char *r_share);
/*---(debugging)------------*/
char*       REUSE__used             (void);
/*---(done)-----------------*/


#endif
/*============================[[ end-of-code ]]===============================*/
