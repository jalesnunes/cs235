###############################################################
# Program:
#     Assignment 03, QUEUE
#     Brother Kirby, CS235
# Authors:
#     Jales Nunes, Davi Neves
# Summary:
#     This program implements the queue data structure and
#     run some tests to verify the application of it. 
#     It handles the buy and sell of stocks according 
#     to the FIFO rule concept.
# Coding Time:
#     Pair Programming: 2 hours
#     Jales: 7 hours
#     Davi:  9 hours
# The most difficult part: 
#     Jales: I had a hard time writing the methods for the
#     	queue class. Both the clear methods and the assignment 
#     	operator had were destroying and deleting my array,  it 
#     	was hard for me to find the problem I think the 
#     	lack of experience in coding is a factor, 
#       most of the time I can't think in a simple way to
#       problems.
#
#     Davi: Writting the Classes Portfolio and Transaction
#	was the hardest part of this assignment for me. 
#       It was really hard for me to picture all the data  
#       structures necessary to book stocks transactions. It
#	seem much simpler than it was at first, until we get 
#	to the sell history, then we noticed thay another
#	queue would be required to store each sale transaction.
###############################################################

##############################################################
# The main rule
##############################################################
a.out: queue.h assignment03.o dollars.o stock.o
	g++ -o a.out assignment03.o dollars.o stock.o
	tar -cf assignment03.tar *.h *.cpp makefile

dollarsTest: dollars.o dollarsTest.cpp
	g++ -o dollarsTest dollars.o dollarsTest.cpp

##############################################################
# The individual components
#      assignment03.o : the driver program
#      dollars.o      : the Dollars class
#      stock.o        : the logic for the stock program
##############################################################
assignment03.o: queue.h assignment03.cpp
	g++ -c assignment03.cpp

dollars.o: dollars.h dollars.cpp
	g++ -c dollars.cpp

stock.o: stock.h stock.cpp queue.h
	g++ -c stock.cpp
