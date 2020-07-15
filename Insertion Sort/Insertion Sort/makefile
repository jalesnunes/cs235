###############################################################
# Program:
#     Assignment 06, NODE
#     Brother Kirby, CS235
# Author:
#     Jales Nunes, Davi Neves
# Summary:
#     This program implements the deque data structure and
#     run some tests to verify the application of it.
# Coding Time:
#     Pair Programming: 2 hours
#     Jales: 6 hours
#     Davi:  7 hours
# The most difficult part: 
#     Jales: This week the hardest part for me was to 
#            understand why our code was giving an error 
#            storing a char type into a list, so after some
#            time trying to fix the problem we figured it out
#            the problem was our insert function and we forgot
#            to put some this in our default and non-default
#            constructors.   
#
#     Davi: The hardest part of this assignment for me was 
#           understanding how a linked list works and using 
#           the pointers correctly. The sortInsertion was 
#           hard because we needed to find the node with
#           data lesser than the one we are looking at. So we 
#           created a new method which returns a pointer to 
#           such node. Using this method all it was left to 
#           do was to compare the elements in the array and 
#           organize them into an ordered list, and copy them 
#           back in order into the array.
###############################################################

##############################################################
# The main rule
##############################################################
a.out: node.h assignment06.o 
	g++ -o a.out assignment06.o -g
	tar -cf assignment06.tar *.h *.cpp makefile

##############################################################
# The individual components
#      assignment06.o      : the driver program
#      <anything else?>
##############################################################
assignment06.o: node.h assignment06.cpp sortInsertion.h
	g++ -c assignment06.cpp -g 
