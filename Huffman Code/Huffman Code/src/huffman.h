/***********************************************************************
 * Module:
 *    Week 08, Huffman
 *    Brother Kirby, CS 235
 * Author:
 *    Davi Neves, Jales Nunes
 * Summary:
 *    This program will implement the huffman() function
 ************************************************************************/

#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <iostream>        // for CIN and COUT
#include <fstream>         // for IFSTREAM
#include <cassert>         // for ASSERT
#include <string>          // for STRING: binary representation of codes
#include "bnode.h"         // for BINARY_NODE class definition
#include "pair.h"          // for PAIR container

using std::cout;
using std::cin;
using std::ifstream;
using std::endl;
using std::string;
using std::bad_alloc;
using namespace custom;


#include <string>
void huffman(const std::string & fileName);

/************************************************
 * HuffmanTree
 * A class that defines a Huffman Tree
 ***********************************************/
class HuffmanTree
{
public:
   HuffmanTree() {}
   HuffmanTree(BNode <custom::pair <double, string> > & tree) { this->tree = tree; }

   BNode <custom::pair <double, string> >  & getTree() { return tree; }
   void setTree(BNode <custom::pair <double, string> > & tree) { this->tree = tree; }

private:
   BNode <custom::pair <double, string> > tree;
};


#endif // HUFFMAN_h
