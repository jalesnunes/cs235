###############################################################
# Program:
#     Assignment 04, DEQUE
#     Brother Kirby, CS235
# Authors:
#     Jales Nunes, Davi Neves
# Summary:
#     This program implements the deque data structure and
#     run some tests to verify the application of it.
# Coding Time:
#     Pair Programming: 2 hours
#     Jales: 8 hours
#     Davi:  9 hours
# The most difficult part: 
#     Jales: I had a hard time doing the deque class, first
#     I didn't understand how the iFront and iBack worked and
#     how to wrap the array and then I finally understood I
#     took some time to understand how the modulus operator
#     should work in this project and we had a problem in our
#     test 3 because we were loosing data when a realocation 
#     was done and we took some time to figrure out what the 
#     problem was. 
#
#     Davi: The hardest part of this assignment for me was 
#     understanding the logic of the normalize method. 
#     It was easy to understand for small size deques. 
#     But when iFront and iBack are large numbers it was hard 
#     to follow what should happen with the indexes. The 
#     method resize, was another problem I had, I was updating 
#     the capacity before copying over the original deque. The 
#     class Student was hard to implement at first, but once 
#     we created another class for Lab it solved the problems 
#     we were having adding emergency requests to the front 
#     of the deque.
###############################################################

##############################################################
# The main rule
##############################################################
a.out: deque.h assignment04.o nowServing.o
	g++ -o a.out assignment04.o nowServing.o 
	tar -cf assignment04.tar *.h *.cpp makefile

##############################################################
# The individual components
#      assignment04.o : the driver program
#      nowServing.o   : the logic for the now serving program
##############################################################
assignment04.o: deque.h assignment04.cpp
	g++ -c assignment04.cpp

nowServing.o: nowServing.h nowServing.cpp deque.h
	g++ -c nowServing.cpp
