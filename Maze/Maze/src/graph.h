/***********************************************************************
 * Component:
 * Author:
 * Summary:
 *    A graph class
 ************************************************************************/

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <string>
#include <cctype>
#include <cassert>
#include "vertex.h"      // for Vertex, LVertex, and CVertex
#include "set.h"
using namespace custom;

using std::string;

/********************************************************
 * Graph
 *******************************************************/
class Graph
{
public:
   Graph(int numNodes);
   Graph(const Graph & rhs);
   Graph & operator = (const Graph & rhs);

   int size() const     { return numNodes;            }
   int capacity() const { return numNodes * numNodes; }
   bool empty() const   { return false;               }
   void clear();
   
   void add(const Vertex & v1, const Vertex & v2);
   void add(const Vertex & v1, set <Vertex> & s);
   bool isEdge(const Vertex & v1, const Vertex & v2) const;
   set <Vertex> findEdges(const Vertex & v);

private:
   bool * grid;
   int numNodes;

};


#endif // GRAPH_H
