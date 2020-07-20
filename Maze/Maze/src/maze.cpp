/***********************************************************************
 * Component:
 *    Assignment 12, Maze
 *    Brother Kirby, CS 235
 * Author:
 *    Br. Helfrich
 *    Davi Neves, Jales Nunes
 * Summary:
 *    Draws and solves a maze
 ************************************************************************/


#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include "maze.h"
#include "vertex.h"
#include "graph.h"
//#include <set>
#include "set.h"
#include "vector.h"
#include "list.h"

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
//using std::set;
using custom::set;
using custom::vector;
using custom::list;

/**********************************************
 * DRAW MAZE ROW
 * Draw all the horizontal tunnels on a given row
 *  Author: Br. Helfrich
 *********************************************/
void drawMazeRow(const Graph & g, int row, set <CVertex> & s)
{
   const char * space = NULL;
   
   CVertex vFrom;
   CVertex vTo;
   assert(g.size() == vFrom.getMaxCol() * vFrom.getMaxRow());

   // they all start with a #
   cout << "|";

   // for every column in the row
   for (int col = 1; col < vFrom.getMaxCol(); col++)
   {
      // set the position
      vFrom.set(col, row);
      vTo.set(col - 1, row);
      space = (s.end() == s.find(vTo) ? "  " : "##");
      
      // draw
      if (g.isEdge(vFrom, vTo) || g.isEdge(vTo, vFrom))
         cout << space << ' ';
      else
         cout << space << '|';
   }

   // draw the end of row marker
   vTo.set( vFrom.getMaxCol() - 1, row);
   space = (s.end() == s.find(vTo) ? "  " : "##");
   cout << space << "|\n";
}

/**********************************************
 * DRAW MAZE COLUMN
 * Draw all the vertical tunnels on a given row
 *  Author: Br. Helfrich
 *********************************************/
void drawMazeColumn(const Graph & g, int row, const set <CVertex> & s)
{
   CVertex vFrom;
   CVertex vTo;
   assert(g.size() == vFrom.getMaxCol() * vFrom.getMaxRow());

   // they all start with a #
   cout << "+";

   // for every column in the row
   for (int col = 0; col < vFrom.getMaxCol(); col++)
   {
      // set the position
      vFrom.set(col, row);
      vTo.set(col, row + 1);

      // draw
      if (g.isEdge(vFrom, vTo) || g.isEdge(vTo, vFrom))
         cout << "  +";
      else
         cout << "--+";
   }

   // draw the end of row marker
   cout << endl;
}

/************************************************
 * DRAW MAZE
 * Draw a given mze represented by the graph 'g'
 * on the screen using ASCII-art. There are two parameters:
 *    g     - the graph containing the maze
 *    path  - the path from the upper left corner to the lower right
 * Author: Br. Helfrich
 ***********************************************/
void drawMaze(const Graph & g, const vector <Vertex> & path)
{
   CVertex v;

   // copy everything into a set
   set <CVertex> s;
   for (int i = 0; i < path.size(); i++)
      s.insert((CVertex)path[i]);

   // draw the top border
   cout << "+  ";
   for (int c = 1; c < v.getMaxCol(); c++)
      cout << "+--";
   cout << "+\n";

   // draw a horizontal row
   for (int row = 0; row < v.getMaxRow() - 1; row++)
   {
      drawMazeRow(g, row, s);
      drawMazeColumn(g, row, s);
   }

   // draw the last row
   drawMazeRow(g, v.getMaxRow() - 1, s);

   // draw the bottom border
   for (int c = 0; c < v.getMaxCol() - 1; c++)
      cout << "+--";
   cout << "+  +\n";
}

/*********************************************
 * READ MAZE
 * Read a maze from the file
 *  Author: Br. Helfrich
 ********************************************/
Graph readMaze(const char * fileName)
{
   // attempt to open the file
   ifstream fin (fileName);
   if (fin.fail())
   {
      cout << "ERROR: Unable to open file " << fileName << endl;
      return Graph(1);
   }

   
   // read the size from the beginning of the maze
   int numCol;
   int numRow;
   fin >> numCol >> numRow;
   CVertex vFrom;
   CVertex vTo;
   vFrom.setMax(numCol, numRow);

   // now read all the items and put them into the Graph
   Graph g(vFrom.getMax());
   while (fin >> vFrom >> vTo)
      g.add(vFrom, vTo);

   // all done!
   fin.close();
   return g;

}

/******************************************
 * SOLVE MAZE
 * Read a maze from the file, display it,
 * then solve it
 *****************************************/
void solveMaze()
{
   // your code goes here.
   char fileName[256];
   vector <Vertex> path;
   list <Vertex> l;

   //get the file name
   cout << "What is the filename? ";
   cin >> fileName;

   //reads and draws the maze
   Graph g(readMaze(fileName));
   drawMaze(g, path);
   
   //solves the maze
   cout << "Press any key to solve the maze." << endl;
   cin.ignore();
   cin.get();
   
   CVertex vFom(0, 0);
   CVertex vTo(4, 4);
/*
   l = g.findPath(vFom, vTo);

   int total = l.size();
   //cout << total << endl;
   for(int i = 0; i < total; i++)
   {
      path.push_back(l.back());
      l.pop_back();
   }
*/
   drawMaze(g, path);
}
