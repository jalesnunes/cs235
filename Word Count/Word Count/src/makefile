###############################################################
# Program:
#     Assignment 10, Map
#     Brother Kirby, CS 235
# Summary:
#     This program implements a binary search tree data structure 
#     and runs some tests to verify the application of it. It uses
#     the class BNode, and iterator as a nested classes. 
#     
# Coding Time:
#     Pair Programming: 3 hours
#     Jales: 7 hours
#     Davi:  12 hours
# The most difficult part: 
#     Jales: 
#
#     Davi: 
###############################################################

##############################################################
# The main rule
##############################################################
a.out: assignment09.o
	g++ -o a.out assignment09.o -g
	tar -cf assignment09.tar *.h *.cpp makefile

##############################################################
# The individual components
#      assignment09.o     : the driver program
##############################################################
assignment09.o: bst.h assignment09.cpp
	g++ -c assignment09.cpp -g


##############################################################
# The main rule
##############################################################
a.out: assignment10.o wordCount.o
	g++ -o a.out assignment10.o wordCount.o -g
	tar -cf assignment10.tar *.h *.cpp makefile

##############################################################
# The individual components
#      assignment10.o : the driver program
#      wordCount.o    : the wordCount() function
##############################################################
assignment10.o: pair.h map.h bst.h assignment10.cpp
	g++ -c assignment10.cpp -g

wordCount.o: map.h bst.h wordCount.h wordCount.cpp 
	g++ -c wordCount.cpp -g
