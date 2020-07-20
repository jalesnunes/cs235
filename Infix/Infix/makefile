###############################################################
# Program:
#     Assignment 02, STACK
#     Brother Kirby, CS235
# Author:
#     Jales Nunes & Davi Neves
# Summary:
#     This program will implement the stack data structure and
#     make some tests to verify the application of it. It converts
#     an expression from infix notation to postfix and assembly
#     notation.
# Coding Time:
#     Pair Programming: 3 hours
#     Jales: 7 hours
#     Davi:  5 hours
# The most difficult part: 
#     Jales: The hardest part for me was the 
#     convertInfixToPostfix() method because I was not able 
#     to put the spaces in the right places during the loop
#     interactions, so most of my time coding I was trying 
#     to get this part to work.
#
#     Davi: ConvertPostfixtoAssembly() method was the hardest
#     part for me. I could not find a way to parse the whole 
#     string of chararcters, from a variable or decimal number, 
#     from the stack into the string assembly. Only the last 
#     character of the stack is passing to the assembly string.
#
###############################################################

##############################################################
# The main rule
##############################################################
a.out: stack.h assignment02.o infix.o 
	g++ -o a.out assignment02.o infix.o 
	tar -cf assignment02.tar *.h *.cpp makefile

##############################################################
# The individual components
#      assignment02.o : the driver program
#      infix.o        : the logic for the infix --> postfix program
##############################################################
assignment02.o: stack.h infix.h assignment02.cpp
	g++ -c assignment02.cpp  

infix.o: stack.h infix.h infix.cpp
	g++ -c infix.cpp 

