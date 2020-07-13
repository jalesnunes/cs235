/***********************************************************************
 * Module:
 *    Week 10, WORD COUNT
 *    Brother Helfrich, CS 235
 * Author:
 *    Jales, Davi
 * Summary:
 *    This program will implement the wordCount() function
 ************************************************************************/

#include <iostream>        // for CIN and COUT
#include <fstream>         // for IFSTREAM
#include <cassert>         // for ASSERT
#include <string>          // for STRING: binary representation of codes
#include "map.h"       // for MAP
#include "wordCount.h" // for wordCount() prototype
using namespace std;
using namespace custom;


//void readFile(map <string, Count> & counts, const string & fileName);

/*****************************************************
 * WORD COUNT
 * Prompt the user for a file to read, then prompt the
 * user for words to get the count from
 *****************************************************/
void wordCount()
{
   string fileName;
   string word;
   map <string, int> m;

   cout << "What is the filename to be counted? ";
   cin >> fileName;

   //reading file
   ifstream fin(fileName.c_str());
   if(fin.fail())
   {
      cout << "Error reading file!" << endl;
   }
   else
   {
      while(!fin.eof())
      {
         fin >> word;
         if(!fin.eof())
         {
            if(m.find(word) != m.end())
               m[word] = m[word] + 1;
            else
               m[word]  = 1;
         }


      }
   }
   
   cout << "What word whose frequency is to be found. Type ! when done" << endl;

   typename map <string, int> :: iterator it;
   string findWord = "";

   while (findWord != "!")
   {
      cout << "> ";
      cin >> findWord;   
      if(findWord != "!")
      {
         it = m.find(findWord);
         if(it != m.end())
            cout << "\t" << findWord << " : " << (*it).second << endl;
         else
            cout << "\t" << findWord << " : 0" << endl;
      }
   }
   
}




