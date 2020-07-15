###############################################################
# Program:
#     Assignment 05, SET
#     Brother Kirby, CS235
# Authors:
#     Jales Nunes, Davi Neves
# Summary:
#     This program implements the deque data structure and
#     run some tests to verify the application of it.
# Coding Time:
#     Pair Programming: 2 hours
#     Jales: 5 hours
#     Davi:  9 hours
# The most difficult part: 
#     Jales: This week the hardest part for me was test 4 
#            because at first i didn't understad that I
#            could not return *this to my && and || funtions
#            I just figured it out when I wrote my problem 
#            on discussion board and one of the students 
#            helped me outm my partner helped me out too   
#
#     Davi: The hardest part of this assignment for me was 
#           writing the methods for the set operators. Once 
#           I understand to logic for the Union operator, and
#           the four different conditions we can test to 
#           compare the elements of the two sets, it became 
#           easier to write the intersection and difference 
#           operators. For the goFish game it seemed harder 
#           when we first read, but once we played the game 
#           and understood what the program was supposed to 
#           do it wasn’t too difficult. We created an object
#           of type card to store each card we read from the 
#           file, and an object of the class hand to hold a 
#           hand of cards. Then we broke down the code into 
#           3 functions, to read the file, to check for 
#           matches, and to display the remaining cards 
#           on hand.
###############################################################

##############################################################
# The main rule
##############################################################
a.out: assignment05.o goFish.o card.o
	g++ -o a.out assignment05.o goFish.o card.o
	tar -cf assignment05.tar *.h *.cpp makefile

##############################################################
# The individual components
#      assignment05.o : the driver program
#      goFish.o       : the logic for the goFish game
#      card.o         : a single playing card
##############################################################
assignment05.o: set.h goFish.h assignment05.cpp
	g++ -c assignment05.cpp

goFish.o: set.h goFish.h goFish.cpp card.h
	g++ -c goFish.cpp

card.o: card.h card.cpp
	g++ -c card.cpp
