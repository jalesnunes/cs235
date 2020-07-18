#include <iostream>
#include <string>
#include <cctype>
#include <cassert>
#include "vertex.h"      // for Vertex, LVertex, and CVertex
#include "set.h"
using namespace custom;

using std::string;

#include "graph.h"

vector<Vertex> Graph::findPath(const Vertex& v1, const Vertex& v2)
{
    vector<Vertex> path;


    return path;
}

set <Vertex> Graph :: findEdges(const Vertex & v)
{
   Vertex v2;
   v2.setMax(numNodes*numNodes);
   set <Vertex> s;
   for(int i = 0; i < numNodes; i++)
      if(grid[(v.index() * numNodes) + i] == true)
      {         
         v2.set(i);
         s.insert(v2);
      }
    
   return s;
}

bool Graph :: isEdge(const Vertex & v1, const Vertex & v2) const
{
   return grid[(v1.index() * numNodes) + v2.index()];
}

void Graph :: add(const Vertex & v1, set <Vertex> & s)
{
   typename set <Vertex> :: iterator it;
   for (it = s.begin(); it != s.end(); ++it);
      grid[(v1.index() * numNodes) + (*it).index()] = true;
}

void Graph :: add(const Vertex & v1, const Vertex & v2)
{
   grid[(v1.index() * numNodes) + v2.index()] = true;
}


Graph & Graph :: operator = (const Graph & rhs)
{
   this->numNodes = rhs.numNodes;
   grid = new bool[numNodes * numNodes];
   for(int i = 0; i < numNodes * numNodes; i++)
      grid[i] = rhs.grid[i];
   return *this;
}

Graph :: Graph(const Graph & rhs)
{
   this->numNodes = rhs.numNodes;
   grid = new bool[numNodes * numNodes];
   for(int i = 0; i < numNodes * numNodes; i++)
      grid[i] = rhs.grid[i];
}

Graph :: Graph(int numNodes)
{
   grid = new bool[numNodes * numNodes];
   for(int i = 0; i < numNodes * numNodes; i++)
      grid[i] = false;
   this->numNodes = numNodes;
}

void Graph :: clear()
{
   for(int i = 0; i < numNodes * numNodes; i++)
      grid[i] = false;
}
