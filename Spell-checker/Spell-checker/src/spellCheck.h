/***********************************************************************
 * Module:
 *    Assignment 12, Spell Check
 *    Brother Helfrich, CS 235
 * Author:
 *    Br. Helfrich
 * Summary:
 *    This program will implement the spellCheck() function
 ************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include "hash.h"
using namespace std;
using namespace custom;

#ifndef SPELL_CHECK_H
#define SPELL_CHECK_H

/****************************************
 * SHASH
 * A hash of string
 ****************************************/
class SHash : public Hash <string>
{
public:
   SHash(int numBuckets)    : Hash <string> (numBuckets) {}
   SHash(const SHash & rhs) : Hash <string> (rhs)        {}

   // hash function for integers is simply to take the modulous
   virtual int hash(const string & word) const
   {
      int sum = 0;
      for(int i = 0; i <= word.size(); i++)
         sum += word[i];
      return sum % capacity();
   }
};

void upToLow(string & word);
void spellCheck();

#endif // SPELL_CHECK_H
