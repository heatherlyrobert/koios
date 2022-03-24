/*===============================[[ beg code ]]===============================*/


/*===[[ HEADER ]]=============================================================*/
/*345678901-12345678901-123456789-123456789-123456789-123456789-123456789-123456789-123456789-*/

#define     P_FOCUS     "PS (programming support)"
#define     P_NICHE     "st (string testing)"
#define     P_SUBJECT   "unit testing meta-language"
#define     P_PURPOSE   "provide simple unit testing framework for writing scripts"

#define     P_NAMESAKE  "koios-polos (axis of heaven)"
#define     P_HERITAGE  "titan god of intelligence, farsight, and the inquisive mind"
#define     P_IMAGERY   "very tall, dark armor, with blue-white eyes, hair, and beard"
#define     P_REASON    "the inquisitive mind of koios pitted against unit testing"

#define     P_ONELINE   P_NAMESAKE " " P_SUBJECT

#define     P_BASENAME  ""
#define     P_FULLPATH  ""
#define     P_SUFFIX    "unit"
#define     P_CONTENT   "unit test script"

#define     P_SYSTEM    "gnu/linux   (powerful, ubiquitous, technical, and hackable)"
#define     P_LANGUAGE  "ansi-c      (wicked, limitless, universal, and everlasting)"
#define     P_CODESIZE  "small       (appoximately 1,000 slocl)"
#define     P_DEPENDS   "none"

#define     P_AUTHOR    "heatherlyrobert"
#define     P_CREATED   "2014-03"

#define     P_VERMAJOR  "1.-- production"
#define     P_VERMINOR  "1.3- switch to proactive issue reporting"
#define     P_VERNUM    "1.3o"
#define     P_VERTXT    "added <file> and <append> verbs to aid test data file loading"

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
#define     T_REUSES    'r'
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
   char        n_base      [LEN_PATH];      /* base name of files             */
   char        n_scrp      [LEN_PATH];      /* name of input script file      */
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
   int         n_comment;                   /* file   comment lines           */
   int         n_empty;                     /* file   empty lines             */
   int         n_short;                     /* file   short lines             */
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
   char        refn        [LEN_LABEL];     /* test reference number          */
   /*---(special marks)---------*/
   char        stage       [LEN_LABEL];     /* master sequence                */
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
};
extern      tVERB       g_verbs [MAX_VERB];






/*===[[ PROG ]]===============================================================*/
/*---(program)--------------*/
char*       PROG_version            (void);
char        PROG_init               (void);
char        PROG_file               (char *a_name);
char        PROG_args               (int  a_argc, char *a_argv[]);
char        PROG_begin              (void);
char        PROG_end                (void);
/*---(unittest)------------*/
char        PROG__unit_quiet        (void);
char        PROG__unit_loud         (void);
char        PROG__unit_end          (void);



/*===[[ SCRP ]]===============================================================*/
/*---(shared)--------------*/
char        SCRP__shared_clear      (cchar a_type);
char        SCRP__shared_purge      (void);
char        SCRP__shared_index      (cchar a_type, cchar a_mark);
char        SCRP__shared_set        (cchar a_type, cchar a_mark);
int         SCRP__shared_get        (cchar a_type, cchar a_mark);
char*       SCRP__shared_used       (void);
/*---(dittos)--------------*/
char        SCRP__ditto_clear       (void);
char        SCRP__reuses_check      (char *p);
char        SCRP__ditto_check       (char *p);
/*---(file)----------------*/
char        SCRP_open               (void);
char        SCRP_close              (void);
char        SCRP_clear              (void);
char        SCRP_read               (void);
/*---(parsing)-------------*/
char        SCRP_parse_verb         (char *p);
char        SCRP_parse_stage        (char *p);
char        SCRP_parse_comment      (void);
char        SCRP_parse              (void);
char        SCRP_vers21             (void);
char        SCRP_vers20             (void);
char        SCRP_vers19             (void);
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
char        WAVE_printf             (char *a_format, ...);
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





#endif
/*============================[[ end-of-code ]]===============================*/
