#================================[[ beg-code ]]================================#



#===(manditory)============================================#
# basename of executable, header, and all code files
NAME_BASE  = koios
# additional standard and outside libraries
LIB_STD    = 
# all heatherly libraries used, debug versions whenever available
LIB_MINE   = -lySTR_debug -lyURG_debug
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
install_post       :
	gcc -c unit.c
	gcc -o unit unit.o koios_code.o koios_conv.o koios_ditto.o koios_flow.o koios_prog.o koios_read.o koios_reuse.o koios_scrp.o koios_verb.o koios_wave.o -lyUNIT -lySTR -lyURG -lyLOG
#	gcc -c unit_wave.c
#	gcc -o unit_wave unit_wave.o koios_wave.o -lyUNIT -lySTR -lyURG -lyLOG

#remove_post        :



#================================[[ end-code ]]================================#
