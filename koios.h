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
#define     P_VERMAJOR  "2.-- production on stress test datasets"
#define     P_VERMINOR  "2.0- supporting unit_head, unit_share, unit_data"
#define     P_VERNUM    "2.0g"
#define     P_VERTXT    "updated for better shared verbs, all unit testing passes ;)"
/*········· ··········· ´·····························´········································*/

/*
 *  apate-panourgos (the crafty one)
 *     greek daemon of deceit, lying, guile, fraud, and perjury
 *     born of nyx (night) and erebus (darkness)
 *
 *  nyx children
 *     moros (doom)
 *     ker (violent death)
 *     thanatos (death)
 *     hypnos (sleep)
 *     oneiroi (dreams)
 *     momos (blame)
 *     oizys (misery)
 *     hesperides
 *     moirai (fates)
 *     keres (death-fates)
 *     nemesis (envy)
 *     apate (deceit)
 *     philotes (freindship)
 *     geras (old age)
 *     eris (strife)
 *
 *
 */
/*
 * [··/·]  stage marker for koios, more importantly ouroboros
 *  ŒŒ  Œ         
 *  ŒŒ  „········· focus  
 *  Œ„············ stage  a-z  dependencies inside file
 *  „············· wave   0-9  dependencies outside file
 *
 * waves...
 *    0  =  no dependency outside of file/unit
 *    1  =  functions dependent on another file's 0s
 *    2  =  functions dependent on another file's 1s
 *    3  =  functions dependent on another file's 2s
 *    4  =  functions dependent on another file's 3s
 *    etc, etc, etc
 *
 * stages...
 *    a  = dependent on nothing not already tested
 *    b  = dependent on function(s) in 'a'
 *    c  = dependent on function(s) in 'b'
 *    d  = dependent on function(s) in 'c'
 *    e  = dependent on function(s) in 'd'
 *    etc, etc, etc
 *
 * sequence...
 * [0a/·] [0b/·] [0c/·] [0d/·] [0e/·] ...
 * [1a/·] [1b/·] [1c/·] [1d/·] [1e/·] ...
 * [2a/·] [2b/·] [2c/·] [2d/·] [2e/·] ...
 * [3a/·] [3b/·] [3c/·] [3d/·] [3e/·] ...
 * [4a/·] [4b/·] [4c/·] [4d/·] [4e/·] ...
 * [5a/·] [5b/·] [5c/·] [5d/·] [5e/·] ...
 * ...
 *
 *
 *
 *
 *
 *
 */



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
#include    <yLOG_solo.h>    /* CUSTOM : heatherly program logging            */
#include    <ySTR_solo.h>
#include    <yENV_solo.h>
#include    <yCOLOR_solo.h>
#include    <yUNIT_solo.h>
#include    <yDLST_solo.h>
#include    <yEXEC_solo.h>

#include    <yUNIT.h>


#define     KOIOS_GLOBALS      "unit.globals"

#define     G_RUN_DEFAULT   '-'
#define     G_RUN_CREATE    'c'
#define     G_RUN_DEBUG     'd'
#define     G_RUN_UPDATE    'u'
#define     G_AND_REPLACE   'r'


#define     T_MASTER    'm'
#define     T_SHARES    'r'
#define     T_CONFIG    'c'
#define     T_DITTOS    'd'

#define     IF_MASTER     if (strcmp (my_loc.l_base, "unit_head") == 0)
#define     IF_NORMAL     if (strcmp (my_loc.l_base, "unit_head") != 0)
#define     IF_SHARED     if (strcmp (my_loc.l_base, "unit_head") == 0 || strcmp (my_loc.l_base, "unit_wide") == 0 || strcmp (my_loc.l_base, "unit_data") == 0)

#define     IF_HEAD       if (strcmp (a_nscrp, "unit_head.unit") == 0)
#define     IF_NOT_HEAD   if (strcmp (a_nscrp, "unit_head.unit") != 0)

#define     IF_GLOBAL_A   if (strcmp (a_nscrp, "unit_head.unit") == 0 || strcmp (a_nscrp, "unit_wide.unit") == 0 || strcmp (a_nscrp, "unit_data.unit") == 0)
#define     IF_LOCAL_A    if (strcmp (a_nscrp, "unit_head.unit") != 0 && strcmp (a_nscrp, "unit_wide.unit") != 0 && strcmp (a_nscrp, "unit_data.unit") != 0)

#define     IF_GLOBAL     if (strcmp (my_loc.l_base, "unit_head") == 0 || strcmp (my_loc.l_base, "unit_wide") == 0 || strcmp (my_loc.l_base, "unit_data") == 0)
#define     IF_LOCAL      if (strcmp (my_loc.l_base, "unit_head") != 0 && strcmp (my_loc.l_base, "unit_wide") != 0 && strcmp (my_loc.l_base, "unit_data") != 0)

#define     IF_CONFIRM    if (my.noise == 'c') 
#define     IF_VERBOSE    if (my.noise == 'v') 


#define     UDEBUG_KOIOS  if (my.debug == 'y')


/*===[[ VERBS ]]==============================================================*/
/*---(overall)--------------*/
#define     PREP          'P'
#define     INCL          'i'
#define     DOCM          '#'
/*---(scripts)--------------*/
#define     SCRP          'S'
#define     SHAR          'H'
#define     GLOB          'G'
#define     CONF          'F'
#define     SECT          'E'
/*---(conditions)-----------*/
#define     COND          'C'
#define     DITT          'D'
#define     RUSE          'R'
#define     GROP          'O'
/*---(variables)------------*/
#define     GVAR          'V'
#define     LVAR          'v'
/*---(steps)----------------*/
#define     EXEC          'x'
#define     GETT          'g'
#define     EKOH          'e'
/*---(specialty)------------*/
#define     CODE          'c'
#define     SYST          's'
#define     LOAD          'l'
#define     MODE          'm'
/*---(specialty)------------*/
#define     FDEF          'f'
#define     APPD          'a'
#define     APPV          'b'
/*---(statistics)-----------*/
#define     PRCS          '1'
#define     RAHS          '2'
#define     BOLG          '3'
#define     FNOC          '4'
#define     TINU          '5'
#define     AUDT          '6'
#define     ENDG          '7'
/*---(ouroboros)------------*/
#define     WAVE          'W'
#define     STAG          'o'
/*---(other)----------------*/
#define     ANYT          '*'
#define     NONE          '-'
/*---(done)-----------------*/


/*===[[ LOCATION ]]===========================================================*/
#define     NORM          'n'
#define     UNIT          'm'
/*---(done)-----------------*/


/*===[[ VERB SPEC TYPES ]]====================================================*/
#define     KOIOS_SSCRP   'S'
#define     KOIOS_SSHAR   'G'
#define     KOIOS_SEXEC   'f'
#define     KOIOS_SEKOH   'e'
#define     KOIOS_SONE    '1'
#define     KOIOS_STWO    '2'
#define     KOIOS_STHR    '3'
#define     KOIOS_SDOC    'c'
#define     KOIOS_SCODE   'p'
#define     KOIOS_SLOAD   'P'
#define     KOIOS_SAUDT   'A'
/*---(combos)---------------*/
#define     KOIOS_SFUNCS  "3fP"
/*---(done)-----------------*/


/*===[[ FIELDS ]]=============================================================*/
#define     KOIOS_FDESC   'd'
#define     KOIOS_FFUNC   'f'
#define     KOIOS_FARGS   'a'
#define     KOIOS_FTEST   't'
#define     KOIOS_FEXPE   'e'
#define     KOIOS_FRETN   'r'


/*===[[ SHARED TYPES ]]=======================================================*/
#define     KOIOS_GLOBAL  'g'
#define     KOIOS_CONFIG  'c'
#define     KOIOS_SHARED  's'
#define     KOIOS_REUSE   'r'
/*---(done)-----------------*/

/*===[[ RETURN TYPES ]]=======================================================*/
/*---(string types)---------*/
#define     KOIOS_STRING  's'
#define     KOIOS_ROUND   'u'
#define     KOIOS_WRAP    'w'
/*---(number types)---------*/
#define     KOIOS_CHAR    'c'
#define     KOIOS_INT     'i'
#define     KOIOS_NUM     'z'
#define     KOIOS_REAL    'r'
/*---(other types)----------*/
#define     KOIOS_POINT   'p'
#define     KOIOS_VOID    'v'
/*---(done)-----------------*/


typedef struct stat      tSTAT;
typedef struct tm        tTIME;
typedef unsigned char    uchar;


typedef     struct cGLOBALS     tGLOBALS;
struct cGLOBALS
{
   /*---(general)---------------*/
   char        version     [LEN_FULL ];     /* program version info           */
   char        noise;                       /* how loud of feedback           */
   char        run_type;                    /* unit test code or conversion   */
   char        replace;                     /* convert and replace file       */
   char        cwd         [LEN_PATH ];     /* true working directory         */
   char        debug;                       /* turn on limited debugging      */
   /*---(debug/test)------------*/
   char        answer      [LEN_RECD ];     /* unit testing answer string     */
   /*---(done)------------------*/
};
extern      tGLOBALS    my;

typedef     struct cLOC   tLOC;
struct cLOC {
   /*---(location data)---------*/
   char        l_dir       [LEN_PATH];      /* full current path              */
   char        l_file      [LEN_FULL];      /* full file name                 */
   char        l_full      [LEN_PATH];      /* absolute file name             */
   char        l_proj      [LEN_LABEL];     /* base project name              */
   char        l_base      [LEN_TITLE];     /* base name of files             */
   char        l_extn      [LEN_TERSE];     /* .unit vs .sunit                */
   char        l_quality;                   /* name quality                   */
   /*---(file names)------------*/
   char        l_scrp      [LEN_TITLE];     /* name of input script file      */
   char        l_main      [LEN_TITLE];     /* name of output main file       */
   char        l_head      [LEN_TITLE];     /* name of header file            */
   char        l_code      [LEN_TITLE];     /* name of output code file       */
   char        l_wave      [LEN_TITLE];     /* name of master code file       */
   char        l_conv      [LEN_TITLE];     /* name of output script file     */
   /*---(file handles)----------*/
   FILE       *l_SCRP;                      /* pointer to input script file   */
   FILE       *l_MAIN;                      /* pointer to output main file    */
   FILE       *l_HEAD;                      /* pointer to output header file  */
   FILE       *l_CODE;                      /* pointer to output code file    */
   FILE       *l_WAVE;                      /* pointer to output wave file    */
   FILE       *l_CONV;                      /* pointer to output script file  */
   /*---(done)------------------*/
};
extern      tLOC        my_loc;

typedef     struct cCUR    tCUR;
struct cCUR {
   /*---(current record)-------*/
   char        c_recd      [LEN_RECD ];     /* script record                  */
   char        c_verb      [LEN_LABEL];     /* verb                           */
   char      (*c_conv) (void);;             /* pointer to code function       */
   char      (*c_code) (void);;             /* pointer to conversion function */
   char        c_spec;                      /* specialty verb (y/n)           */
   char        c_vers;                      /* version number                 */
   char        c_desc      [LEN_LONG ];     /* descriptive text               */
   char        c_method    [LEN_HUND ];     /* function/method name           */
   char        c_args      [LEN_FULL ];     /* function/method args           */
   char        c_test      [LEN_LABEL];     /* test type for yVAR             */
   char        c_expect    [LEN_RECD ];     /* expected results               */
   char        c_return    [LEN_FULL ];     /* return variable                */
   /*---(extracted)------------*/
   char        c_stage     [LEN_SHORT];     /* master sequencing              */
   char        c_ditto;                     /* parsed ditto mark              */
   char        c_major;                     /* parsed share -- major          */
   char        c_minor;                     /* parsed share -- minor          */
   char        c_which     [LEN_TITLE];     /* minors to run                  */
   /*---(working)---------------*/
   char        c_disp      [LEN_RECD ];     /* display ver " = ~, 1D = |      */
   char        c_syst      [LEN_RECD ];     /* system ver  " = ", 1D = 1F     */
   char        c_load      [LEN_RECD ];     /* load ver    " = ~, 1D = 1F     */
   /*---(done)------------------*/
};
extern      tCUR    my_cur;

typedef     struct cRUN    tRUN;
struct cRUN {
   /*---(counters)--------------*/
   int         r_nline;                     /* file   all lines               */
   int         r_nrecd;                     /* file   good records            */
   /*---(verb)------------------*/
   char        r_last      [LEN_LABEL];     /* last verb used                 */
   char        r_under;                     /* next higher structure          */
   /*---(ditto)-----------------*/
   char        r_dittoing;                  /* currently dittoing             */
   char        r_dtarget;                   /* target ditto mark              */
   int         r_dstart;                    /* target ditto start             */
   int         r_dline;                     /* target dittoing source line    */
   /*---(reuse)-----------------*/
   char        r_share;                     /* run-time active share          */
   char        r_select;                    /* run-time active exec select    */
   /*---(done)------------------*/
};
extern      tRUN    my_run;


extern char g_print     [LEN_RECD];





/*===[[ koios_prog.c ]]=======================================================*/
/*········· ´······················ ´·········································*/
/*---(support)--------------*/
char*       PROG_version            (void);
/*---(pre-init)-------------*/
char        PROG__header            (void);
char        PROG_urgents            (int a_argc, char *a_argv []);
/*---(start-up)-------------*/
char        PROG__init              (void);
/*> char        PROG__file              (char a_name [LEN_TITLE], char r_base [LEN_TITLE], char r_proj [LEN_LABEL], char r_ext [LEN_TERSE]);   <*/
char        PROG__args              (int a_argc, char *a_argv []);
char        PROG__begin             (void);
char        PROG_startup            (int a_argc, char *a_argv []);
/*---(execution)------------*/
char        PROG_dawn               (char a_runtype, char a_nscrp [LEN_TITLE], FILE **r_scrp, int *r_line, char a_nmain [LEN_TITLE], FILE **r_main, char a_nhead [LEN_TITLE], FILE **r_head, char a_ncode [LEN_TITLE], FILE **r_code, char a_nwave [LEN_TITLE], FILE **r_wave, char a_nconv [LEN_TITLE], FILE **r_conv, char *b_share, char *b_select);
char        PROG_terminate          (FILE **r_scrp, FILE **r_main, FILE **r_code, FILE **r_wave, FILE **r_conv);
char        PROG_driver             (char a_good, char a_runtype, char a_nscrp [LEN_TITLE], int *r_nline, FILE **b_scrp, FILE *a_main, FILE *a_head, FILE *a_code, FILE *a_wave, FILE *a_conv, char b_last [LEN_LABEL], int *r_nrecd, char *r_under, char *r_ditto, char *r_dittoing, char *r_dtarget, int *r_dstart, int *r_dline, char *r_major, char *r_minor, char *r_share, char *r_select);
char        PROG_pseudo             (int a_argc, char *a_argv []);
char        PROG_dusk               (char a_good, char a_runtype, char a_replace, char a_nscrp [LEN_TITLE], FILE **r_scrp, int a_nline, char a_nmain [LEN_TITLE], FILE **r_main, char a_nhead [LEN_TITLE], FILE **r_head, char a_ncode [LEN_TITLE], FILE **r_code, char a_nwave [LEN_TITLE], FILE **r_wave, char a_nconv [LEN_TITLE], FILE **r_conv, char a_share, char a_select);
/*---(shut-down)------------*/
char        PROG__end               (void);
char        PROG_shutdown           (void);
/*---(strings)-------------*/
char        PROG__args_string       (char a_string [LEN_FULL]);
char        PROG_startup_string     (char a_string [LEN_FULL]);
char        PROG_pseudo_string      (char a_string [LEN_FULL]);
/*---(unittest)------------*/
char        PROG__unit_bigclean     (void);
char        PROG__unit_quiet        (void);
char        PROG__unit_loud         (void);
char        PROG__unit_end          (void);
/*---(done)----------------*/





/*===[[ koios_wave.c ]]=======================================================*/
/*········· ´······················ ´·········································*/
/*---(program)--------------*/
char        WAVE_parse              (char a_nscrp [LEN_TITLE], int a_line, char a_verb [LEN_LABEL], char a_field [LEN_LABEL], char r_stage [LEN_SHORT]);
/*---(done)-----------------*/



/*===[[ koios_ditto.c ]]======================================================*/
/*········· ´······················ ´·········································*/
/*---(program)--------------*/
char        DITTO_purge             (void);
char        DITTO_init              (void);
char        DITTO_wrap              (void);
/*---(usage)----------------*/
char        DITTO__index            (cchar a_mark);
char        DITTO__set              (cchar a_mark, int a_line, char a_desc [LEN_LONG]);
char        DITTO__set_recd         (cchar a_mark, int a_line, char a_vers, char a_recd [LEN_RECD]);
int         DITTO__get              (cchar a_mark, char r_desc [LEN_LONG]);
char        DITTO_called            (char a_mark);
/*---(toggle)---------------*/
char        DITTO_beg               (FILE **b_scrp, cchar a_nscrp [LEN_TITLE], int a_line, char a_runtype, char a_mark, int a_ditto, char *r_mark, char *r_dittoing, char *r_dtarget, int *r_dstart, int *r_dline);
char        DITTO_end               (FILE **b_scrp, char *r_dittoing, char *r_dtarget, int *r_dstart, int *r_dline);
/*---(reading)--------------*/
char        DITTO_read_numbering    (char a_dittoing, int a_ditto, int *r_nline, int *r_dline);
/*---(parsing)--------------*/
char        DITTO_parse__desc       (char a_prev [LEN_LONG], char r_desc [LEN_LONG]);
char        DITTO_parse__group      (char a_prev [LEN_LONG], char r_desc [LEN_LONG]);
char        DITTO_parse_handler     (FILE **b_scrp, cchar a_nscrp [LEN_TITLE], int a_line, char a_runtype, char a_verb [LEN_LABEL], char a_vers, char a_recd [LEN_RECD], char *a_field, char r_desc [LEN_LONG], char *r_ditto, char *r_dittoing, char *r_dtarget, int *r_dstart, int *r_dline);
/*---(debugging)------------*/
char*       DITTO__actuals          (void);
char*       DITTO__used             (void);
/*---(done)-----------------*/



/*===[[ koios_verb.c ]]=======================================================*/
/*········´ ´················spec·´ ´·········································*/
char        VERB_limits             (char a_spec, char *r_min, char *r_max, char r_desc [LEN_DESC]);
/*········´ ´·············program·´ ´·········································*/
char        VERB_init               (void);
char        VERB__by_name           (char a_verb [LEN_LABEL], char *r_indent, char r_desc [LEN_DESC], char *r_spec, char *r_locn, char *r_is, char *r_under, int *r_count, int *r_total, void **r_conv, void **r_code, char *r_ditto, char *r_select);
char        VERB__by_cursor         (char a_scope, char a_dir, char r_verb [LEN_LABEL], char *r_indent, char r_desc [LEN_DESC], char *r_spec, char *r_locn, char *r_is, char *r_under, int *r_count, int *r_total, void **r_conv, void **r_code, char *r_ditto, char *r_select);
char        VERB__by_index          (char n, char r_verb [LEN_LABEL], char *r_indent, char r_desc [LEN_DESC], char *r_spec, char *r_locn, char *r_is, char *r_under, int *r_count, int *r_total, void **r_conv, void **r_code, char *r_ditto, char *r_select);
char        VERB__index             (char a_verb [LEN_LABEL]);
char        VERB__count             (void);
char*       VERB__detail            (char n, char a_verb [LEN_LABEL]);
char        VERB_script_reset       (void);
char        VERB_dittoable          (char a_verb [LEN_LABEL]);
char        VERB_selectable         (char a_verb [LEN_LABEL]);
char        VERB__parse_under       (char a_nscrp [LEN_TITLE], int a_line, char a_verb [LEN_LABEL], char a_is, char a_under, char *b_under);
char        VERB_parse              (char a_nscrp [LEN_TITLE], int a_line, char a_field [LEN_LABEL], char *b_under, char r_verb [LEN_LABEL], char *r_indx, char *r_spec, char *r_locn, char **r_conv, char **r_code);
char        VERB_inventory          (FILE *a_main);
/*········´ ´················DONE·´ ´·········································*/


/*===[[ koios_read.c ]]=======================================================*/
/*········· ´······················ ´·········································*/
/*---(file)-----------------*/
/*> char        READ_open               (char a_sfile [LEN_TITLE], char a_sfunc [LEN_TITLE], int a_sline, char a_dir [LEN_PATH], char a_name [LEN_TITLE], char a_mode, FILE **r_file, int *r_line);   <*/
/*> char        READ_close              (char a_sfile [LEN_TITLE], char a_sfunc [LEN_TITLE], int a_sline, char a_name [LEN_TITLE], FILE **b_file);   <*/
/*---(record)---------------*/
char        READ__defense           (FILE **a_file, int *r_nline, char *r_dittoing, char *r_dmark, int *r_ditto, int *r_dline, int *r_nrecd, char r_recd [LEN_RECD]);
char        READ__clear             (void);
char        READ__single            (FILE **b_file, int *r_nline, char *r_dittoing, char *r_dmark, int *r_ditto, int *r_dline, int *r_nrecd, char r_recd [LEN_RECD]);
char        READ_next               (FILE **b_file, int *r_nline, char *r_dittoing, char *r_dmark, int *r_ditto, int *r_dline, int *r_nrecd, char r_recd [LEN_RECD]);
/*---(done)-----------------*/



/*===[[ koios_reuse.c ]]======================================================*/
/*········· ´······················ ´·········································*/
/*---(program)--------------*/
char        REUSE_init              (void);
char        REUSE_wrap              (void);
/*---(usage)----------------*/
char        REUSE_scope             (char a_verb [LEN_LABEL], char r_example [LEN_SHORT]);
char        REUSE_populate          (char a_verb [LEN_LABEL], char a_major, int a_line, char a_desc [LEN_LONG], char a_which [LEN_LABEL], char a_titles [LEN_PATH]);
/*---(parsing)--------------*/
char        REUSE__parse_delimit    (char a_func [LEN_LABEL], char a_nscrp [LEN_TITLE], int a_line, char a_verb [LEN_LABEL], char a_prefix [LEN_RECD], char a_label [LEN_SHORT], char a_pos, char a_char, char a_example [LEN_SHORT]);
char        REUSE__parse_global     (char a_nscrp [LEN_TITLE], int a_line, char a_verb [LEN_LABEL], char a_prefix [LEN_LABEL], char a_label [LEN_LABEL], char a_example [LEN_SHORT], char a_share, char *r_major, char *r_minor);
char        REUSE__parse_shared     (char a_nscrp [LEN_TITLE], int a_line, char a_verb [LEN_LABEL], char a_prefix [LEN_LABEL], char a_label [LEN_LABEL], char a_example [LEN_SHORT], char a_share, char *r_major, char *r_minor);
char        REUSE__parse_reuse_old  (char a_nscrp [LEN_TITLE], int a_line, char a_prefix [LEN_RECD], char a_label [LEN_LABEL], char *r_major, char *r_minor);
char        REUSE__parse_reuse_new  (char a_nscrp [LEN_TITLE], int a_line, char a_prefix [LEN_RECD], char a_label [LEN_LABEL], char *r_major, char *r_minor);
char        REUSE__parse_reuse      (char a_nscrp [LEN_TITLE], int a_line, char a_verb [LEN_LABEL], char a_prefix [LEN_LABEL], char a_label [LEN_LABEL], char a_example [LEN_SHORT], char a_share, char *r_major, char *r_minor);
char        REUSE_parse             (char a_nscrp [LEN_TITLE], int a_line, char a_verb [LEN_LABEL], char a_prefix [LEN_LABEL], char a_share, char *r_major, char *r_minor);
/*---(debugging)------------*/
char*       REUSE__actuals          (void);
char*       REUSE__used             (void);
/*---(exim)-----------------*/
/*> char        REUSE_export            (char a_good, char a_nscrp [LEN_TITLE]);      <*/
/*> char        REUSE_import            (char a_nscrp [LEN_TITLE]);                   <*/
/*---(totals)---------------*/
char        REUSE_totals            (char a_verb [LEN_LABEL], char a_recd [LEN_RECD]);
/*---(done)-----------------*/



/*===[[ koios_conv.c ]]=======================================================*/
/*········· ´······················ ´·········································*/
/*---(support)--------------*/
char        CONV_init               (void);
char        CONV__defense           (FILE *a_conv, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_major, char a_minor, char *r_share, char *b_select);
char        CONV_printf             (FILE *a_conv, char *a_format, ...);
/*---(overall)--------------*/
char        CONV_header             (char a_name [LEN_PATH], FILE **r_conv, char *r_share, char *r_select);
char        CONV__break             (FILE *a_conv);
char        CONV__prep              (FILE *a_conv, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_major, char a_minor, char *b_share, char *b_select);
char        CONV__incl              (FILE *a_conv, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_major, char a_minor, char *b_share, char *b_select);
char        CONV__comment           (FILE *a_conv, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_major, char a_minor, char *b_share, char *b_select);
char        CONV_footer             (char a_good, FILE **b_conv, char a_nscrp [LEN_TITLE], char a_nconv [LEN_TITLE]);
/*---(scrps)----------------*/
char        CONV__scrp_add          (char a_scrp, char a_verb [LEN_LABEL], char a_major, char a_stage [LEN_SHORT], char r_suffix [LEN_TERSE], char r_count [LEN_LABEL], char *b_share);
char        CONV__scrp              (FILE *a_conv, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_major, char a_minor, char *b_share, char *b_select);
char        CONV__shared            (FILE *a_conv, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_major, char a_minor, char *b_share, char *b_select);
char        CONV__sect              (FILE *a_conv, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_major, char a_minor, char *b_share, char *b_select);
/*---(conds)----------------*/
char        CONV__cond_add          (char a_ditto, char a_major, char a_minor, char a_share, char r_suffix [LEN_TERSE], char r_count [LEN_LABEL]);
char        CONV__cond              (FILE *a_conv, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_major, char a_minor, char *b_share, char *b_select);
char        CONV__ditto             (FILE *a_conv, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_major, char a_minor, char *b_share, char *b_select);
char        CONV__reuse             (FILE *a_conv, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_major, char a_minor, char *b_share, char *b_select);
char        CONV__group             (FILE *a_conv, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_major, char a_minor, char *b_share, char *b_select);
/*---(steps)----------------*/
char        CONV__gvar              (FILE *a_conv, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_major, char a_minor, char *b_share, char *b_select);
char        CONV__exec              (FILE *a_conv, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_major, char a_minor, char *b_share, char *b_select);
char        CONV__code              (FILE *a_conv, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_major, char a_minor, char *b_share, char *b_select);
char        CONV__echo              (FILE *a_conv, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_major, char a_minor, char *b_share, char *b_select);
char        CONV__load              (FILE *a_conv, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_major, char a_minor, char *b_share, char *b_select);
char        CONV__mode              (FILE *a_conv, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_major, char a_minor, char *b_share, char *b_select);
char        CONV__file              (FILE *a_conv, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_major, char a_minor, char *b_share, char *b_select);
char        CONV__append            (FILE *a_conv, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_major, char a_minor, char *b_share, char *b_select);
/*---(driver)---------------*/
char        CONV_driver             (void f_call (), FILE *a_conv, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_major, char a_minor, char *r_share, char *b_select);
/*---(unitest)--------------*/
char        CONV_force              (int a_scrps, int  a_conds);
/*---(done)-----------------*/



/*===[[ koios_code.c ]]=======================================================*/
/*········· ´······················ ´·········································*/
/*---(support)--------------*/
char        CODE_init               (void);
char        CODE__defense           (char a_nscrp [LEN_TITLE], FILE *a_main, FILE *a_head, FILE *a_code, FILE *a_wave, char a_runtype, char a_last [LEN_LABEL], char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_meth [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expe [LEN_RECD], char a_retn [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_major, char a_minor, char *b_share, char *b_select);
int         CODE__line              (char a_dittoing, int a_nline, int a_dline);
/*---(prep)-----------------*/
char        CODE__code_beg          (char a_nscrp [LEN_TITLE], FILE *a_code);
char        CODE__code_stats        (FILE *a_code);
char        CODE__code_end          (char a_nscrp [LEN_TITLE], FILE *a_code);
char        CODE__main_beg          (FILE *a_main, char a_nscrp [LEN_TITLE]);
char        CODE__main_end          (FILE *a_main, char a_nscrp [LEN_TITLE]);
char        CODE_header             (char a_nscrp [LEN_TITLE], char a_nmain [LEN_TITLE], FILE **r_main, char a_nhead [LEN_TITLE], FILE **r_head, char a_ncode [LEN_TITLE], FILE **r_code, char a_nwave [LEN_TITLE], FILE **r_wave, char *b_share, char *b_select);
char        CODE_footer             (char a_good, char a_nscrp [LEN_TITLE], char a_nmain [LEN_TITLE], FILE **r_main, char a_nhead [LEN_TITLE], FILE **r_head, char a_ncode [LEN_TITLE], FILE **r_code, char a_nwave [LEN_TITLE], FILE **r_wave, int a_nline, char a_share, char a_select, char a_unit);
char        CODE__incl              (char a_nscrp [LEN_TITLE], FILE *a_main, FILE *a_head, FILE *a_code, FILE *a_wave, char a_runtype, char a_last [LEN_LABEL], int a_nline, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_dittoing, char a_dtarget, int a_dline, char a_major, char a_minor, char *r_share, char *b_select);
/*---(select)---------------*/
char        CODE__select_beg        (FILE* a_code, char a_verb [LEN_TERSE], char a_which [LEN_TITLE], char a_share, char r_pre [LEN_TERSE]);
char        CODE__select_end        (FILE* a_code, char a_verb [LEN_TERSE], char a_which [LEN_TITLE], char a_share);
/*---(scrp)-----------------*/
char        CODE__scrp_end          (FILE *a_code, char a_last [LEN_LABEL], char a_nline, char a_verb [LEN_LABEL], char a_share);
char        CODE__scrp              (char a_nscrp [LEN_TITLE], FILE *a_main, FILE *a_head, FILE *a_code, FILE *a_wave, char a_runtype, char a_last [LEN_LABEL], int a_nline, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_dittoing, char a_dtarget, int a_dline, char a_major, char a_minor, char *r_share, char *b_select);
char        CODE__shared            (char a_nscrp [LEN_TITLE], FILE *a_main, FILE *a_head, FILE *a_code, FILE *a_wave, char a_runtype, char a_last [LEN_LABEL], int a_nline, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_dittoing, char a_dtarget, int a_dline, char a_major, char a_minor, char *r_share, char *b_select);
char        CODE__sect              (char a_nscrp [LEN_TITLE], FILE *a_main, FILE *a_head, FILE *a_code, FILE *a_wave, char a_runtype, char a_last [LEN_LABEL], int a_nline, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_dittoing, char a_dtarget, int a_dline, char a_major, char a_minor, char *r_share, char *b_select);
/*---(cond)-----------------*/
char        CODE__cond_end          (FILE *a_code, char a_last [LEN_LABEL], char a_verb [LEN_LABEL], char a_nline, char a_share);
char        CODE__cond              (char a_nscrp [LEN_TITLE], FILE *a_main, FILE *a_head, FILE *a_code, FILE *a_wave, char a_runtype, char a_last [LEN_LABEL], int a_nline, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_dittoing, char a_dtarget, int a_dline, char a_major, char a_minor, char *r_share, char *b_select);
char        CODE__group             (char a_nscrp [LEN_TITLE], FILE *a_main, FILE *a_head, FILE *a_code, FILE *a_wave, char a_runtype, char a_last [LEN_LABEL], int a_nline, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_dittoing, char a_dtarget, int a_dline, char a_major, char a_minor, char *r_share, char *b_select);
char        CODE__reuse             (char a_nscrp [LEN_TITLE], FILE *a_main, FILE *a_head, FILE *a_code, FILE *a_wave, char a_runtype, char a_last [LEN_LABEL], int a_nline, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_dittoing, char a_dtarget, int a_dline, char a_major, char a_minor, char *r_share, char *b_select);
/*---(step-support)---------*/
char        CODE__display           (char a_code [LEN_RECD], char r_display [LEN_RECD], char r_system [LEN_RECD], char r_load [LEN_RECD]);
char        CODE__prefix            (FILE *a_code, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_test [LEN_LABEL], char a_display [LEN_RECD], char a_system [LEN_RECD], char a_dittoing, int a_nline, int a_dline, char a_pre [LEN_TERSE], char a_share);
char        CODE__expect            (FILE *a_conv, char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_dittoing);
char        CODE__suffix            (FILE *a_code, char a_verb [LEN_LABEL], char a_test [LEN_LABEL], char a_system [LEN_RECD], char a_return [LEN_FULL], char a_pre [LEN_TERSE], char a_dittoing, char a_share);
char        CODE__specialty         (FILE *a_code, char a_load [LEN_RECD], char a_dittoing, char a_share);
/*---(step)-----------------*/
char        CODE__step_add          (FILE *a_code, char a_runtype, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_dittoing, int a_nline, int a_dline);
char        CODE__exec              (char a_nscrp [LEN_TITLE], FILE *a_main, FILE *a_head, FILE *a_code, FILE *a_wave, char a_runtype, char a_last [LEN_LABEL], int a_nline, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_dittoing, char a_dtarget, int a_dline, char a_major, char a_minor, char *r_share, char *b_select);
char        CODE__load              (char a_nscrp [LEN_TITLE], FILE *a_main, FILE *a_head, FILE *a_code, FILE *a_wave, char a_runtype, char a_last [LEN_LABEL], int a_nline, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_dittoing, char a_dtarget, int a_dline, char a_major, char a_minor, char *r_share, char *b_select);
char        CODE__file              (char a_nscrp [LEN_TITLE], FILE *a_main, FILE *a_head, FILE *a_code, FILE *a_wave, char a_runtype, char a_last [LEN_LABEL], int a_nline, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_dittoing, char a_dtarget, int a_dline, char a_major, char a_minor, char *r_share, char *b_select);
char        CODE__append            (char a_nscrp [LEN_TITLE], FILE *a_main, FILE *a_head, FILE *a_code, FILE *a_wave, char a_runtype, char a_last [LEN_LABEL], int a_nline, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_dittoing, char a_dtarget, int a_dline, char a_major, char a_minor, char *r_share, char *b_select);
char        CODE__mode              (char a_nscrp [LEN_TITLE], FILE *a_main, FILE *a_head, FILE *a_code, FILE *a_wave, char a_runtype, char a_last [LEN_LABEL], int a_nline, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_dittoing, char a_dtarget, int a_dline, char a_major, char a_minor, char *r_share, char *b_select);
char        CODE__code              (char a_nscrp [LEN_TITLE], FILE *a_main, FILE *a_head, FILE *a_code, FILE *a_wave, char a_runtype, char a_last [LEN_LABEL], int a_nline, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_dittoing, char a_dtarget, int a_dline, char a_major, char a_minor, char *r_share, char *b_select);
char        CODE__gvar              (char a_nscrp [LEN_TITLE], FILE *a_main, FILE *a_head, FILE *a_code, FILE *a_wave, char a_runtype, char a_last [LEN_LABEL], int a_nline, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_dittoing, char a_dtarget, int a_dline, char a_major, char a_minor, char *r_share, char *b_select);
char        CODE__lvar              (char a_nscrp [LEN_TITLE], FILE *a_main, FILE *a_head, FILE *a_code, FILE *a_wave, char a_runtype, char a_last [LEN_LABEL], int a_nline, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_dittoing, char a_dtarget, int a_dline, char a_major, char a_minor, char *r_share, char *b_select);
char        CODE__system            (char a_nscrp [LEN_TITLE], FILE *a_main, FILE *a_head, FILE *a_code, FILE *a_wave, char a_runtype, char a_last [LEN_LABEL], int a_nline, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_dittoing, char a_dtarget, int a_dline, char a_major, char a_minor, char *r_share, char *b_select);
/*---(driver)---------------*/
char        CODE_driver             (void f_call (), char a_nscrp [LEN_TITLE], FILE *a_main, FILE *a_head, FILE *a_code, FILE *a_wave, char a_runtype, char a_last [LEN_LABEL], int a_nline, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char a_method [LEN_HUND], char a_args [LEN_FULL], char a_test [LEN_LABEL], char a_expect [LEN_RECD], char a_return [LEN_FULL], char a_stage [LEN_SHORT], char a_which [LEN_TITLE], char a_ditto, char a_dittoing, char a_dtarget, int a_dline, char a_major, char a_minor, char *b_share, char *b_select);
/*---(unitest)--------------*/
char        CODE_force              (int a_scrps, int  a_conds);
/*---(done)-----------------*/



/*===[[ koios_parse.c ]]======================================================*/
/*········´ ´···············trees·´ ´·········································*/
char        PARSE_default           (char r_verb [LEN_LABEL], char *r_spec, char **r_conv, char **r_code, char r_stage [LEN_SHORT], char *r_vers, char r_desc [LEN_LONG], char r_meth [LEN_HUND], char r_args [LEN_FULL], char r_test [LEN_LABEL], char r_expe [LEN_RECD], char r_retn [LEN_FULL], char *r_ditto, char *r_major, char *r_minor, char r_which [LEN_TITLE]);
char        PARSE__comment          (char a_nscrp [LEN_TITLE], int a_line, char a_recd [LEN_RECD], char r_verb [LEN_LABEL], char *r_under, char *r_spec, char **r_conv, char **r_code, char r_expe [LEN_RECD]);
char        PARSE__default          (char r_desc [LEN_LONG], char r_meth [LEN_HUND], char r_args [LEN_FULL], char r_test [LEN_LABEL], char r_expe [LEN_RECD], char r_retn [LEN_FULL]);
char        PARSE__version          (char *a_field, char *r_vers);
char        PARSE__allowed_chars    (char a_nscrp [LEN_TITLE], int a_line, char a_verb [LEN_LABEL], char a_label [LEN_TERSE], char a_allowed [LEN_FULL], char a_field [LEN_RECD]);
char        PARSE__which            (char a_nscrp [LEN_TITLE], int a_line, char a_verb [LEN_LABEL], char a_desc [LEN_LONG], char r_which [LEN_TITLE]);
char        PARSE__desc             (char a_nscrp [LEN_TITLE], int a_line, char a_verb [LEN_LABEL], char a_spec, char a_max, char a_field [LEN_RECD], char r_desc [LEN_LONG], char r_which [LEN_TITLE]);
char        PARSE__function         (char a_nscrp [LEN_TITLE], int a_line, char a_verb [LEN_LABEL], char a_spec, char a_max, char a_field [LEN_RECD], char r_meth [LEN_HUND], char r_test [LEN_LABEL], char r_retn [LEN_FULL]);
char        PARSE__select           (char a_nscrp [LEN_TITLE], int a_line, char a_verb [LEN_LABEL], char a_field [LEN_RECD], char r_field [LEN_LABEL]);
char        PARSE__subtitles        (char a_nscrp [LEN_TITLE], int a_line, char a_verb [LEN_LABEL], char a_select [LEN_LABEL], char a_field [LEN_RECD], char r_field [LEN_RECD]);
char        PARSE__field            (char a_nscrp [LEN_TITLE], int a_line, char a_verb [LEN_LABEL], char a_spec, char a_col, char a_field [LEN_RECD], char r_desc [LEN_LONG], char r_meth [LEN_HUND], char r_args [LEN_FULL], char r_test [LEN_LABEL], char r_expe [LEN_RECD], char r_retn [LEN_FULL], char r_which [LEN_TITLE]);
char        PARSE__current          (char n, char *p, char a_spec, char *r_max, char r_desc [LEN_LONG], char r_meth [LEN_HUND], char r_args [LEN_FULL], char r_test [LEN_LABEL], char r_expe [LEN_RECD], char r_retn [LEN_FULL]);
char        PARSE_prep              (FILE **b_scrp, char a_nscrp [LEN_TITLE], int a_line, char a_runtype, char a_recd [LEN_RECD], char r_verb [LEN_LABEL], char *r_under, char *r_spec, char **r_conv, char **r_code, char r_stage [LEN_SHORT], char *r_vers, char r_desc [LEN_LONG], char r_expe [LEN_RECD], char *r_ditto, char *r_dittoing, char *r_dtarget, int *r_dstart, int *r_dline, char *r_major, char *r_minor, char *r_share, char *r_select);
char        PARSE_driver            (char a_nscrp [LEN_TITLE], int a_line, char a_vers, char a_verb [LEN_LABEL], char a_spec, char a_recd [LEN_RECD], char r_desc [LEN_LONG], char r_meth [LEN_HUND], char r_args [LEN_FULL], char r_test [LEN_LABEL], char r_expe [LEN_RECD], char r_retn [LEN_FULL], char r_which [LEN_TITLE]);
/*········´ ´················DONE·´ ´·········································*/



/*===[[ koios_flow.c ]]=======================================================*/
/*········· ´······················ ´·········································*/
/*> char        FLOW__defense           (cchar a_nscrp [LEN_TITLE], int a_line, cchar a_recd [LEN_RECD], char r_verb [LEN_LABEL], char *r_indx, char *r_spec, char **r_conv, char **r_code, char r_stage [LEN_SHORT], char *r_vers, char r_desc [LEN_LONG], char r_meth [LEN_HUND], char r_args [LEN_FULL], char r_test [LEN_LABEL], char r_expe [LEN_RECD], char r_retn [LEN_FULL]);   <*/
/*> char        FLOW_driver             (cchar a_nscrp [LEN_TITLE], int a_line, cchar a_recd [LEN_RECD], char r_verb [LEN_LABEL], char *r_indx, char *r_spec, char **r_conv, char **r_code, char r_stage [LEN_SHORT], char *r_vers, char r_desc [LEN_LONG], char r_meth [LEN_HUND], char r_args [LEN_FULL], char r_test [LEN_LABEL], char r_expe [LEN_RECD], char r_retn [LEN_FULL]);   <*/



#endif
/*============================[[ end-of-code ]]===============================*/
