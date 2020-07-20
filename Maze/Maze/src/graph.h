/***********************************************************************
 * Program:
 *    Assignment 13, Graph
 *    Brother Kirby, CS 235
 * Author: 
 *    Davi Neves, Jales Nunes
 * Summary:  
 *    A definition for Graph Class.  
 ************************************************************************/
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <string>
#include <cctype>
#include <cassert>
#include "vertex.h"      // for Vertex, LVertex, and CVertex
#include "set.h"
#include "list.h"
using namespace custom;

using std::string;

/********************************************************
 * Graph: Class definition
 *******************************************************/
class Graph
{
public:
   // constructors and destructors
   Graph(int numNodes);
   Graph(const Graph & rhs);
   Graph & operator = (const Graph & rhs);

   // standard container interfaces
   int size() const     { return numNodes;            }
   int capacity() const { return numNodes * numNodes; }
   bool empty() const   { return false;               }
   void clear();
   
   //methods for graph
   void add(const Vertex & v1, const Vertex & v2);
   void add(const Vertex & v1, set <Vertex> & s);
   bool isEdge(const Vertex & v1, const Vertex & v2) const;
   set <Vertex> findEdges(const Vertex & v);
   list <Vertex> findPath(const Vertex & v1, const Vertex & v2);

private:
   bool * grid;      //pointer to grid
   int numNodes;     //number of nodes

};


#endif // GRAPH_H
