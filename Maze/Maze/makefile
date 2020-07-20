###############################################################
# Program:
#     Assignment 13, Graph
#     Brother Kirby, CS235
# Author:
#     Davi Neves, Jales Nunes
# Summary:
#     This program implements the Class Graph and
#     runs some tests to verify the application of it. It uses
#     the classes Graph, to implement the class Maze that draws,
#     and solves a maze problem. 
# Coding Time:
#     Pair Programming: 1 hour
#     Jales: 3 hours
#     Davi:  5 hours
# The most difficult part:
#     Jales: For me the hardest part this week was the Maze.
#    	     I tried to help Davi but I couldn't understand what
#	     I am missing. Unfortunately, I only had an hour free
#	     on Saturday to work on that with him.
#     Davi:  The hardest part for me this week was the Graph
#	     Class. First it was hard to understand how to use
#	     properly my Set and List classes in it. Then the 
#	     method Find Path was the hardest for me to 
#	     implement. I kept getting stuck in the while loop
#	     that computes the vertices to visit.
###############################################################

##############################################################
# The main rule
##############################################################
a.out: assignment13.o graph.o maze.o
	g++ -o a.out assignment13.o graph.o maze.o -g -std=c++11
	tar -cf assignment13.tar *.h *.cpp makefile

##############################################################
# The individual components
#      assignment13.o     : the driver program
#      graph.o            : the graph code
#      maze.o             : the maze reading and solving code
##############################################################
assignment13.o: graph.h vertex.h assignment13.cpp
	g++ -c assignment13.cpp -g -std=c++11

graph.o: graph.h set.h vertex.h graph.cpp
	g++ -c graph.cpp -g -std=c++11

maze.o: maze.cpp maze.h vertex.h graph.h
	g++ -c maze.cpp -g -std=c++11
