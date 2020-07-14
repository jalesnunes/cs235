###############################################################
# Program:
#     Assignment 08, Binary Tree
#     Brother Kirby, CS235
# Summary:
#     This program implements a binary tree data structure and runs some
#     tests to verify the application of it. It uses the class BNode, and
#     Pair to create a Huffman Tree using those custom classes.
# Coding Time:
#     Pair Programming: 3 hours
#     Jales: 11 hours
#     Davi:  12 hours
# The most difficult part: 
#     Jales: First I spent a lot of time to understand how 
#            the huffman code works so I read a lot on the 
#            internet and watched some videos to understand.
#            Once I understood the theory, I had a hard time 
#            getting the data from a file and throwing that 
#            data into a binary tree and then displaying the 
#            result. So far I think this assignment was the
#            most difficult and the one I understood the least 
#            the implementation, and it is getting more 
#            difficult to work with pointers as well.
#
#     Davi: The Huffman code was by far the hardest part to understand
#     	and to implement. We started by reading the data 
#	from the file and inserting the data into a vector 
#	by pairs of frequence and token. We wanted to use this 
#	vector to construct the complete Huffman Tree. But we
#	struggled to find  a way to add all the Bnodes together. 
#	We created a method to help us in the process of finding the 
#	two lowest frequences, findLowerFreq(). We saved
#	the indexes of two lowest frequences in a temporary array,
#	and a new BNode with the sum of the two frequences, and pointers 
#	to the left and right BNode. Then the new tree went into 
#	the left-most of the two slots, and the second lowest in the right.
#	We created a encode method to help us in the traversal 
#	of the Huffman Tree to write the huffman code. And
#	the display method. 
#	
###############################################################

##############################################################
# The main rule
##############################################################
a.out: assignment08.o huffman.o 
	g++ -o a.out assignment08.o huffman.o -g
	tar -cf assignment08.tar *.h *.cpp makefile

##############################################################
# The individual components
#      assignment08.o : the driver program
#      huffman.o      : the logic for the huffman code program
##############################################################
assignment08.o: bnode.h huffman.h assignment08.cpp
	g++ -c assignment08.cpp -g

huffman.o: bnode.h huffman.h huffman.cpp
	g++ -c huffman.cpp -g

