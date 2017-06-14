/*===============================[[ beg code ]]===============================*/

/*===[[ HEADER ]]=============================================================*/

/*   focus         : (PS) programming support
 *   niche         : (st) software testing
 *   application   : koios       (titan-god of inquisitive, questioning mind)
 *   purpose       : provide consistent automated unit testing framework
 *
 *   base_system   : gnu/linux   (powerful, ubiquitous, technical, and hackable)
 *   lang_name     : ansi-c      (wicked, limitless, universal, and everlasting)
 *   dependencies  : none
 *   size goal     : toolish (less than 10,000 slocL)
 *
 *
 *   base_system   : gnu/linux   (powerful, ubiquitous, technical, and hackable)
 *   lang_name     : gnu/ansi-c  (right, just, best, standard, and everlasting)
 *   dependencies  : yVAR only (for var testing)
 *   size          : small       (less than 2,000 slocL)
 *
 *   author        : heatherly
 *   created       : 2014-mar
 *   priorities    : direct, simple, brief, vigorous, and lucid (h.w. fowler)
 *   end goal      : loosely coupled, strict interface, maintainable, portable
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



/*===[[ VERSIONING ]]=========================================================*/
/* rapidly evolving version number to aid with visual change confirmation     */
#define     KOIOS_VER_NUM    "0.9k"
#define     KOIOS_VER_TXT    "cleaned up man pages for sections 1 and 7"



/*===[[ STANDARD C LIBRARIES ]]===============================================*/
#include    <stdio.h>        /* C_ANSI : strcpy, strlen, strchr, strcmp, ...  */
#include    <string.h>       /* C_ANSI : printf, snprintf, fgets, fopen, ...  */

/*===[[ CUSTOM LIBRARIES ]]===================================================*/
#include    <yLOG.h>         /* CUSTOM : heatherly program logging            */
#include    <ySTR.h>         /* CUSTOM : heatherly safer string handling      */
#include    <yURG.h>         /* CUSTOM : heatherly urgent processing          */



#define     G_RUN_CREATE    'c'
#define     G_RUN_UPDATE    'u'




/*---(rational limits to strings)---------------*/
/*
 *   i do not beleive in unlimited strings.  i understand the reasoning for
 *   flexibility, future expansion, unknown usage patterns, etc.  but, i think
 *   they also provide hacker/cracker vectors and its just not worth it.  i
 *   have a use in mind for the string and it can only use so many characters
 *   anyway.  if something is too long, 99% probability the input is malformed,
 *   incorrect, or ill-intensioned.  just my perspective.
 *
 */
#define     LEN_STR      200   /* normal, generic string        */
#define     LEN_FILE     500   /* fully qualified file names    */
#define     LEN_RECD    2000   /* input script record length    */
#define     LEN_UNIT     200   /* unit test return string       */


typedef     struct cGLOBALS     tGLOBALS;
struct cGLOBALS
{
   /*---(general)---------------*/
   char        version     [LEN_STR ];      /* program version info           */
   char        run_type;                    /* unit test code or conversion   */
   /*---(file names)------------*/
   char        name_base   [LEN_FILE];      /* base name of files             */
   char        name_scrp   [LEN_FILE];      /* name of input script file      */
   char        name_code   [LEN_FILE];      /* name of output code file       */
   char        name_conv   [LEN_FILE];      /* name of output script file     */
   /*---(file handles)----------*/
   FILE       *file_scrp;                   /* pointer to input script file   */
   FILE       *file_code;                   /* pointer to output code file    */
   FILE       *file_conv;                   /* pointer to output script file  */
   /*---(counters)--------------*/
   int         n_line;                      /* file   all lines               */
   int         n_comment;                   /* file   comment lines           */
   int         n_empty;                     /* file   empty lines             */
   int         n_short;                     /* file   short lines             */
   int         n_recd;                      /* file   good records            */
   int         nscrp;                       /* total count of scripts         */
   int         ncond;                       /* total count of scripts         */
   int         nstep;                       /* total count of scripts         */
   int         cscrp;                       /* current script number          */
   int         ccond;                       /* current condition number       */
   int         cstep;                       /* current step number            */
   /*---(script)---------------*/
   char        recd        [LEN_RECD];      /* script record                  */
   int         len;                         /* record length                  */
   char        status;                      /* record processing status       */
   int         indx;                        /* verb index in tVERB structure  */
   char        verb        [LEN_STR ];      /* verb                           */
   char        last        [LEN_STR ];      /* last verb used                 */
   char        spec;                        /* specialty verb (y/n)           */
   char        vers        [LEN_STR ];      /* version number                 */
   char        desc        [LEN_STR ];      /* descriptive text               */
   char        meth        [LEN_STR ];      /* function/method name           */
   char        args        [LEN_STR ];      /* function/method args           */
   char        test        [LEN_STR ];      /* test type for yVAR             */
   char        expe        [LEN_STR ];      /* expected results               */
   char        type;
   char        retn        [LEN_STR ];      /* return variable                */
   char        code        [LEN_RECD];      /* code/load/sys string           */
   char        refn        [LEN_STR ];      /* test reference number          */
   /*---(working)---------------*/
   char        disp        [LEN_RECD];      /* display ver " = ~, 1D = |      */
   char        syst        [LEN_RECD];      /* system ver  " = ", 1D = 1F     */
   char        load        [LEN_RECD];      /* load ver    " = ~, 1D = 1F     */
   /*---(flag)------------------*/
   char        driver;                      /* has main/driver been written   */
   /*---(debug/test)------------*/
   char        answer      [LEN_UNIT];      /* unit testing answer string     */
   /*---(done)------------------*/
};
extern      tGLOBALS    my;


#define     MAX_VERB         20
typedef     struct cVERB    tVERB;
struct cVERB {
   char        name        [LEN_STR ];      /* verb                           */
   char        desc        [LEN_STR];       /* description                    */
   char        spec;                        /* specialty verb                 */
   int         count;                       /* number found in script         */
   int         total;                       /* number found in unit test      */
};
extern      tVERB       g_verbs [MAX_VERB];


#define     MAX_TEST         20
typedef     struct cTEST    tTEST;
struct cTEST {
   char        abbr;                        /* abbreviated type               */
   char        repl;                        /* test type relace               */
   char        name        [LEN_STR ];      /* verb                           */
   char        func        [LEN_STR ];      /* function call                  */
   char        desc        [LEN_STR];       /* description                    */
};
extern      tTEST       g_tests [MAX_TEST];




/*===[[ MAIN ]]===============================================================*/
int         main               (int a_argc, char *a_argv[]);

/*===[[ PROG ]]===============================================================*/
/*---(program)--------------*/
char*       PROG_version       (void);
char        PROG_logger        (int  a_argc, char *a_argv[]);
char        PROG_init          (void);
char        PROG_urgsmass      (char a_set , char  a_extra);
char        PROG_urgs          (int  a_argc, char *a_argv[]);
char        PROG_args          (int  a_argc, char *a_argv[]);
char        PROG_begin         (void);
char        PROG_end           (void);
/*---(unittest)------------*/
char        PROG_testfiles     (void);
char        PROG_testquiet     (void);
char        PROG_testloud      (void);
char        PROG_testend       (void);

/*===[[ SCRP ]]===============================================================*/
char        SCRP_open          (void);
char        SCRP_close         (void);
char        SCRP_clear         (void);
char        SCRP_read          (void);
char        SCRP_parse         (void);
char        SCRP_vers21        (void);
char        SCRP_vers20        (void);
char        SCRP_vers19        (void);
char        SCRP_verbs         (void);

/*===[[ CODE ]]===============================================================*/
char        CODE_open          (void);
char        CODE_close         (void);
char        CODE_write         (void);
char        CODE_begin         (void);
char        CODE_prep          (void);
char        CODE_incl          (void);
char        CODE_main          (void);
char        CODE_sect          (void);
char        CODE_scrp          (void);
char        CODE_group         (void);
char        CODE_cond          (void);
char        CODE_prefix        (char *a_func);
char        CODE_exec          (void);
char        CODE_unknown       (void);
char        CODE_suffix        (void);
char        CODE_end           (void);

/*===[[ CONV ]]===============================================================*/
char        CONV_open          (void);
char        CONV_close         (void);
char        CONV_write         (void);

void        VOID_void          (char *a_one, int a_two);





#endif
/*============================[[ end-of-code ]]===============================*/
