###############################################################
# Program:
#     Assignment 07, LIST
#     Brother Kirby, CS235
# Author:
#     Jales Nunes, Davi Neves
# Summary:
#     This program implements a list data structure and run some
#     tests to verify the application of it. It uses the class
#     to compute a Fibonacci sequence, using a custom class
#		for whole numbers.
# Coding Time:
#     Pair Programming: 2 hours
#     Jales: 7 hours
#     Davi:  10 hours
# The most difficult part: 
#     Jales: For sure the hardest part of this week was doing
#            the fibonacci test. Displaying a small number was
#            not so hard, but as the number grew we had 
#            difficulty putting together a logic for the bigger 
#            numbers, and certainly working with pointers for 
#            me is a big headache     
#
#     Davi: It was very difficult for me to complete the class
#	    List. We started with the node class, and some of
#	    the methods were similar. But completing the
#	    operators assign, add-onto, and insertion was a 
#	    little confusing. All the iterators looked very 
#           scary due to working with pointers, but afterall
#	    it wasn't much different from the vector's iterator.
###############################################################

##############################################################
# The main rule
##############################################################
a.out: list.h assignment07.o fibonacci.o wholeNumber.o
	g++ -o a.out assignment07.o fibonacci.o wholeNumber.o -g
	tar -cf assignment07.tar *.h *.cpp makefile

##############################################################
# The individual components
#      assignment07.o : the driver program
#      fibonacci.o    : the logic for the fibonacci-generating function
#      <anything else?>
##############################################################
assignment07.o: list.h assignment07.cpp
	g++ -c assignment07.cpp -g

fibonacci.o: fibonacci.h fibonacci.cpp list.h
	g++ -c fibonacci.cpp -g

wholeNumber.o: wholeNumber.h wholeNumber.cpp list.h
	g++ -c wholeNumber.cpp -g

