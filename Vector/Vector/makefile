###############################################################
# Program:
#     Assignment 01, Vector
#     Brother Kirby, CS235
# Author:
#     Jales Nunes
# Summary:
#     This program will implement the vector data structure and
#     make some tests to verify the application
# Time:
#     Jales: 7 hours
# The most difficult part: 
#       Jales: the most difficult part was to build the 
#       push_back function and the non-default constructor
#       because there is some thing wrong in my first test
#       when create a double vector using the non-default 
#       constructor the capacity needs to return 10 but in my
#       is returning 16 I spent a couple of hours to find the
#       error in my code but I couldn't find it
###############################################################

##############################################################
# The main rule
##############################################################
a.out: vector.h assignment01.o
	g++ -o a.out assignment01.o
	tar -cf assignment01.tar vector.h assignment01.cpp makefile

##############################################################
# The individual components
#      assignment01.o     : the driver program
##############################################################
assignment01.o: vector.h assignment01.cpp
	g++ -c assignment01.cpp


