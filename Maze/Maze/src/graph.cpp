/***********************************************************************
 * Program:
 *    Assignment 13, Graph
 *    Brother Kirby, CS 235
 * Author: 
 *    Davi Neves
 * Summary:  
 *    A class definition and methods for the Class Graph.  
 ************************************************************************/

#include <iostream>
#include <string>
#include <cctype>
#include <cassert>
#include "vertex.h"      // for Vertex, LVertex, and CVertex
#include "set.h"
#include "list.h"
using namespace custom;
using std::string;

#include "graph.h"

/**********************************************
* Graph : Find Path from a vertex starting point
*         to another vertex.
**********************************************/
list <Vertex> Graph :: findPath(const Vertex & v1, const Vertex & v2)
{
   //variables for path and distance
   list <Vertex> path;
   int distance = 0;
   int distances[numNodes * numNodes];
   Vertex predecessor[numNodes];
   
   //list of vertices to visit
   list <Vertex> toVisit;
   toVisit.push_back(v1);

   //set distances to -1
   for(int i = 0; i < numNodes * numNodes; i++)
      distances[i] = -1;
      
   distances[v1.index()] = 0;      
      
   while(!toVisit.empty() && distances[v2.index()] == -1)
   {
      //set vertex vFrom to first to visit
      Vertex vFrom = toVisit.front();
      toVisit.pop_front();
      //vertex vFrom: vFrom.index(), distances: distances[vFrom.index()]
      
      //if distances[vFrom.index()] < distance And distance != -1

      set <Vertex> s = findEdges(vFrom);
      set <Vertex> :: const_iterator it;
         
      for (it = s.cbegin(); it != s.cend(); ++it)
      {
         Vertex vTo = *it;
         //Adds vertex vTo to list to visit
         if(distances[vTo.index()] == -1)
         {
            distances[vTo.index()] = distances[vFrom.index()] + 1;
            predecessor[vTo.index()] = vFrom;
            toVisit.push_back(vTo);
         }
         
      }
      distance = distances[vFrom.index()] + 1;
   }
   //add vertex v2 to the path
   path.push_back(v2);
  
   for(int i = 0; i < distance; i++)
      path.push_back(predecessor[(path.back()).index()]);

  
   return path;
}

/**********************************************
* Graph : Find Edges 
*         Finds the edges of the graph.
**********************************************/
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

/**********************************************
* Graph : is Edge
*         Checks if a vertex is an edge.
**********************************************/
bool Graph :: isEdge(const Vertex & v1, const Vertex & v2) const
{
   return grid[(v1.index() * numNodes) + v2.index()];
}

/**********************************************
* Graph : ADD
*        Adds a vertex to a set of vertices.
**********************************************/
void Graph :: add(const Vertex & v1, set <Vertex> & s)
{
   typename set <Vertex> :: iterator it;
   for (it = s.begin(); it != s.end(); ++it);
      grid[(v1.index() * numNodes) + (*it).index()] = true;
}

/**********************************************
* Graph : ADD 
*         Adds two vertices.
**********************************************/
void Graph :: add(const Vertex & v1, const Vertex & v2)
{
   grid[(v1.index() * numNodes) + v2.index()] = true;
}

/**********************************************
* Graph : =  Assignment Operator
* 
**********************************************/
Graph & Graph :: operator = (const Graph & rhs)
{
   this->numNodes = rhs.numNodes;
   grid = new bool[numNodes * numNodes];
   for(int i = 0; i < numNodes * numNodes; i++)
      grid[i] = rhs.grid[i];
   return *this;
}

/**********************************************
* Graph : Clear Graph
**********************************************/
void Graph :: clear()
{
   for(int i = 0; i < numNodes * numNodes; i++)
      grid[i] = false;
}

/**********************************************
* Graph : COPY CONSTRUCTOR
* 
**********************************************/
Graph :: Graph(const Graph & rhs)
{
   this->numNodes = rhs.numNodes;
   grid = new bool[numNodes * numNodes];
   for(int i = 0; i < numNodes * numNodes; i++)
      grid[i] = rhs.grid[i];
}

/**********************************************
* Graph : NON-DEFAULT CONSTRUCTOR 
*         
**********************************************/
Graph :: Graph(int numNodes)
{
   grid = new bool[numNodes * numNodes];
   for(int i = 0; i < numNodes * numNodes; i++)
      grid[i] = false;
   this->numNodes = numNodes;
}

