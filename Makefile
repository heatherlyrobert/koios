#================================[[ beg-code ]]================================#



#===(manditory)============================================#
# basename of executable, header, and all code files
NAME_BASE  = koios
# additional standard and outside libraries
LIB_STD    = 
# all heatherly libraries used, debug versions whenever available
LIB_MINE   = -lySTR_debug
# directory for production code, no trailing slash
INST_DIR   = /usr/local/bin



#===(optional)=============================================#
# extra include directories required
INC_MINE   = 
# utilities generated, separate from main program
NAME_UTIL  = 
# libraries only for the utilities
LIB_UTIL   = 



#===(post-processing)======================================#
# create a rule for...
#install_prep       :
#remove_prep        :



#===(master template)======================================#
include /usr/local/sbin/make_program



#===(post-processing)======================================#
# create a rule for...
#install_post       :
#remove_post        :



#================================[[ end-code ]]================================#



#*============================----beg-of-source---============================*#


#===[[ VARABLES ]]======================================================================================================================================================#

#===(current variables)=================================================================================================================================================#
#BASE    = koios
#DEBUG   = ${BASE}_debug
#HDIR    = /home/system/koios.unit_test_generator
#IDIR    = /usr/local/bin
#MDIR    = /usr/share/man/man1

#===(compilier variables)===============================================================================================================================================#
# must have "-x c" on gcc line so stripped files work with alternate extensions
#COMP    = gcc -c -std=gnu89 -x c -g -pg -Wall -Wextra
#INCS    = -I/usr/local/include 

#===(linker options)========================================================================================================================================================================#
#------   (0)-------------- (1)-------------- (2)-------------- (3)-------------- (4)-------------- (5)-------------- (6)-------------- (7)-------------- (8)-------------- (9)--------------
#LINK    = gcc
#LIBDIR  = -L/usr/local/lib
#LIBS    = ${LIBDIR}         -lySTR            
#LIBS    = ${LIBDIR}         -lySTR_debug      -lyLOG
#LIBD    = ${LIBDIR}         -lySTR_debug      -lyLOG

#===(file lists)============================================================================================================================================================================#
#------   (0)-------------- (1)-------------- (2)-------------- (3)-------------- (4)-------------- (5)-------------- (6)-------------- (7)-------------- (8)-------------- (9)--------------
#HEADS   = ${BASE}.h
#OBJS    = ${BASE}_main.os   ${BASE}_prog.os   ${BASE}_scrp.os   ${BASE}_code.os   ${BASE}_conv.os   
#OBJS    = ${BASE}_main.o    ${BASE}_prog.o    ${BASE}_scrp.o    ${BASE}_code.o    ${BASE}_conv.o   
#OBJD    = ${BASE}_main.o    ${BASE}_prog.o    ${BASE}_scrp.o    ${BASE}_code.o    ${BASE}_conv.o   

#===(make variables)====================================================================================================================================================#
#COPY    = cp -f
#CLEAN   = rm -f
#PRINT   = @printf
#STRIP   = @grep -v -e " DEBUG_" -e " yLOG_" 



#===[[ EXECUTABLES ]]===================================================================================================================================================#

#all                : ${BASE} ${DEBUG}

#${BASE}            : ${OBJD}
#	${LINK}  -o ${BASE}        ${OBJS}   ${LIBS}

#${DEBUG}           : ${OBJD}
#	${LINK}  -o ${DEBUG}       ${OBJD}   ${LIBD}



#===[[ OBJECT FILES ]]==================================================================================================================================================#

#${BASE}_main.o     : ${HEADS}       ${BASE}_main.c
#	${COMP}    ${BASE}_main.c                           ${INC}
#	${STRIP}   ${BASE}_main.c      > ${BASE}_main.cs
#	${COMP}    ${BASE}_main.cs    -o ${BASE}_main.os    ${INC}
#
#${BASE}_prog.o     : ${HEADS}       ${BASE}_prog.c
#	${COMP}    ${BASE}_prog.c                           ${INC}
#	${STRIP}   ${BASE}_prog.c      > ${BASE}_prog.cs
#	${COMP}    ${BASE}_prog.cs    -o ${BASE}_prog.os    ${INC}
#
#${BASE}_scrp.o     : ${HEADS}       ${BASE}_scrp.c
#	${COMP}    ${BASE}_scrp.c                           ${INC}
#	${STRIP}   ${BASE}_scrp.c      > ${BASE}_scrp.cs
#	${COMP}    ${BASE}_scrp.cs    -o ${BASE}_scrp.os    ${INC}
#
#${BASE}_code.o     : ${HEADS}       ${BASE}_code.c
#	${COMP}    ${BASE}_code.c                           ${INC}
#	${STRIP}   ${BASE}_code.c      > ${BASE}_code.cs
#	${COMP}    ${BASE}_code.cs    -o ${BASE}_code.os    ${INC}
#
#${BASE}_conv.o     : ${HEADS}       ${BASE}_conv.c
#	${COMP}    ${BASE}_conv.c                           ${INC}
#	${STRIP}   ${BASE}_conv.c      > ${BASE}_conv.cs
#	${COMP}    ${BASE}_conv.cs    -o ${BASE}_conv.os    ${INC}
#
#
#
##===[[ SCRIPTS ]]=======================================================================================================================================================#
#
#clean              :
#	#---(all versions)--------------------#
#	${CLEAN} ${BASE}
#	${CLEAN} ${DEBUG}
#	#---(object and stripped files)-------#
#	${CLEAN} ${BASE}*.o
#	${CLEAN} ${BASE}*.cs
#	${CLEAN} ${BASE}*.os
#	${CLEAN} ${BASE}*.Sc
#	${CLEAN} ${BASE}*.So
#	#---(junk files)----------------------#
#	${CLEAN} *~
#	${CLEAN} temp*
#
#bigclean           :
#	${CLEAN} .*.swp
#
#install            : ${BASE}
#	#---(production version)--------------#
#	${COPY}   ${BASE}    ${IDIR}/
#	chown     root:root  ${IDIR}/${BASE}
#	chmod     0700       ${IDIR}/${BASE}
#	@sha1sum  ${BASE}
#	#---(debug version)-------------------#
#	${COPY}  ${DEBUG}    ${IDIR}/
#	chown     root:root  ${IDIR}/${DEBUG}
#	chmod     0700       ${IDIR}/${DEBUG}
#	@sha1sum  ${DEBUG}
#	#---(script version)------------------#
#	_inst --sbin yUNIT_gen
#	_inst --sbin uUNIT
#	#---(man page)------------------------#
#	rm -f       ${MDIR}/${BASE}.1.bz2
#	cp -f       ${BASE}.1  ${MDIR}/
#	bzip2       ${MDIR}/${BASE}.1
#	chmod 0644  ${MDIR}/${BASE}.1.bz2
#
#remove             :
#	#---(all versions)--------------------#
#	${CLEAN}  ${IDIR}/${BASE}
#	${CLEAN}  ${IDIR}/${DEBUG}
#	#---(script version)------------------#
#	${CLEAN} /usr/local/sbin/${BASE}_gen.awk
#	${CLEAN} /usr/local/sbin/uUNIT
#	#---(documentation)-------------------#
#	${CLEAN}  ${MDIR}/${BASE}.1.bz2


#*============================----end-of-source---============================*#
