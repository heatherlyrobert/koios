#================================[[ beg-code ]]================================#



#===(manditory)============================================#
# basename of executable, header, and all code files
NAME_BASE  = koios
# additional standard and outside libraries
LIB_STD    = 
# all heatherly libraries used, debug versions whenever available
LIB_MINE   = -lyUNIT_debug
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
include /usr/local/sbin/zeno_make

# LIB_HERE := $<  $(filter-out %_main.os,$(OBJ_NORM)) $(LIB_STD)  $(LIB_MINE)



#===(post-processing)======================================#
# create a rule for...
#remove_post        :
install_post       :
#	gcc -c unit_conv.c
#	gcc -o unit_conv  unit_conv.o  $(LIB_HERE)
#	gcc -c unit_ditto.c
#	gcc -o unit_ditto unit_ditto.o $(LIB_HERE)
#	gcc -c unit_reuse.c
#	gcc -o unit_reuse unit_reuse.o $(LIB_HERE)
#	gcc -c unit_verb.c
#	gcc -o unit_verb  unit_verb.o  $(LIB_HERE)
#	gcc -c unit_wave.c
#	gcc -o unit_wave  unit_wave.o  $(LIB_HERE)



#================================[[ end-code ]]================================#
