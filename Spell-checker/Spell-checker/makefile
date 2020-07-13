###############################################################
# Program:
#     Assignment 12, Hash
#     Brother Kirby, CS235
# Author:
#     Jales Nunes, Davi Neves
# Summary:
#     This program implements a Hash table data structure and 
#     run some tests to verify the application of it. This 
#     class will store a collection of elements and be able to 
#     perform constant-time insertion and lookup. Additionally,
#     this class will need to support any data type. It uses 
#     the class to run a spell checker also.
# Coding Time:
#     Pair Programming: 2 hours
#     Jales: 8 hours
#     Davi:  7 hours
# The most difficult part: 
#     Jales: The class hash was relatively easy to do, without 
#     too many difficulties. The hardest part was the A test
#     in general so much that I was unable to return much 
#     and Davi helped me to do this part of the assignment    
#
#     Davi: This week the hardest part of the assignment for
#     me was the SpellChecker hash function. We decided to 
#     build our hash class using the BST class, but we 
#     couldn't figure out a problem in the non-default & copy 
#     constructors, and the assignment operator. So we decided
#     to include our class List to build the Hash Class. With 
#     that we were able to create a table, of type list, to 
#     hold the number of buckets of the hash being copied, and
#     thus iterate through the whole hash one element at a 
#     time copying them to the new hash. That worked better.
###############################################################

##############################################################
# The main rule
##############################################################
a.out: assignment12.o spellCheck.o
	g++ -o a.out assignment12.o spellCheck.o -g 
	tar -cf assignment12.tar *.h *.cpp makefile

##############################################################
# The individual components
#      assignment12.o     : the driver program
#      spellCheck.o       : the spell-check program and driver
##############################################################
assignment12.o: hash.h assignment12.cpp list.h
	g++ -c assignment12.cpp

spellCheck.o: hash.h spellCheck.h spellCheck.cpp
	g++ -c spellCheck.cpp -g

