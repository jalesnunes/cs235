/***********************************************************************
 * Module:
 *    Assignment 12, Spell Check
 *    Brother Helfrich, CS 235
 * Author:
 *    Jales, Davi
 * Summary:
 *    This program will implement the spellCheck() function
 ************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include "spellCheck.h"
#include "hash.h"
using namespace std;
using namespace custom;

void upToLow(string & word)
{
   for(int i = 0; i <= word.size(); i++)
      word[i] = tolower(word[i]);
}

/*****************************************
 * SPELL CHECK
 * Prompt the user for a file to spell-check
 ****************************************/
void spellCheck()
{
   string fileName;
   string dic = "/home/cs235/week12/dictionary.txt";
   //string dic = "dictionary.txt";
   string word, wordLow;

   int numWordDic = 0;
   int numMisspelled = 0;

   //how many words are in the dictionary file?
   ifstream fin(dic.c_str());
   if(fin.fail())
      cout << "Error reading file!" << endl;
   else
      while(!fin.eof())
      {
         fin >> word;
         numWordDic++;
      }

   //The book says to use 1.5
   numWordDic = numWordDic / 1.5;
   SHash h(numWordDic);
   
   //reading dictionary
   ifstream fin1(dic.c_str());
   if(fin1.fail())
      cout << "Error reading file!" << endl;
   else
      while(!fin1.eof())
      {
         fin1 >> word;
         if(!fin1.eof())
            h.insert(word);
      }

   cout << "What file do you want to check? ";
   cin >> fileName;
   
   //reading file
   ifstream fin2(fileName.c_str());
   if(fin2.fail())
   {
      cout << "Error reading file!" << endl;
   }
   else
   {
      while(!fin2.eof())
      {
         fin2 >> word;
         if(!fin2.eof())
         {
            wordLow = word;
            upToLow(wordLow);

            if(h.find(wordLow) == false)
            {
               if(numMisspelled == 0)
               {
                  cout << "Misspelled: ";
                  cout << word;
               }
               else
                  cout << ", " << word ;
               numMisspelled++;
            }
         }       
      }
      if(numMisspelled == 0)
         cout << "File contains no spelling errors";
   }   
   cout << endl;
}
