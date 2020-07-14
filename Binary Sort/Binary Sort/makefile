###############################################################
# Program:
#     Assignment 09, Binary Search Tree
#     Brother Kirby, CS235
# Summary:
#     This program implements a binary search tree data structure 
#     and runs some tests to verify the application of it. It uses
#     the class BNode, and iterator as a nested classes. 
#     
# Coding Time:
#     Pair Programming: 3 hours
#     Jales: 9 hours
#     Davi:  12 hours
# The most difficult part: 
#     Jales: Certainly the most difficult part was trying to 
#            make the extra point, unfortunately we were 
#            unable to do that part. I also had difficulty 
#            with the insert function and ended up spending a 
#            few hours to be able to implement this function 
#            and make it work. In the Iterator class, I had 
#            problems with test 3 and 4 when giving a display 
#            of the data entered, the tests were falling in an 
#            infinite loop.
#
#     Davi: The iterator class was the hasdest part for me.
#	    I had a hard time with the syntax for the iterator
#           operators, and using friend methods for find and
#	    erase. The erase function was the most complicated
#	    to write, and the most time consuming also.
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

