/***********************************************************************
 * Header:
 *    Node
 * Summary:
 *
 * Author
 *   Jales, Davi
 ************************************************************************/

#ifndef HASH_H
#define HASH_H

#include <cassert>  // because I am paranoid
#include <iostream>        // for CIN and COUT
using namespace std;
#include "list.h" // List is being used because it's the easiest way to store elements
using namespace custom;

// a little helper macro to write debug code
#ifdef NDEBUG
#define Debug(statement)
#else
#define Debug(statement) statement
#endif // !NDEBUG

namespace custom
{
/************************************************
 * HASH
 ***********************************************/
template <class T>
class Hash
{
public:
   // constructors and destructors
   Hash();
   Hash(const Hash <T> & rhs);
   Hash(const int numBuckets);
  ~Hash() { clear(); }
   
   Hash & operator = (const Hash & rhs); 
   
   bool empty()    const;
   int  size()     const { return numElements; }
   int capacity()  const { return numBuckets;  }
   void clear();
   
   virtual int hash(const T & value) const = 0;
   
   bool find(const T & t) const;
   void insert(const T & t);
 
private:
   list <T> * table;
   int numElements;
   int numBuckets;
};

/****************************************
 * HASH - clear
 * Clear the contents. All the elements 
 * added through the insert() are removed
 ****************************************/
template <class T>
void Hash <T> :: clear()
{
   for(int i = 0; i < numBuckets; i++)
      table[i].clear();
   //delete table;   
}

/****************************************
 * HASH - find
 * value to be found
 ****************************************/
template <class T>
bool Hash <T> :: find(const T & t) const
{
   int index = hash(t);
   if(table[index].find(t) != NULL)
      return true;
   else
      return false;
}

/****************************************
 * HASH - insert
 * Places a new instance of a value in 
 * the Hash
 ****************************************/
template <class T>
void Hash <T> :: insert(const T & t)
{
   int index = hash(t);

   table[index].push_back(t);
   numElements++;
}

/****************************************
 * HASH - Hash
 * just initialized the variables
 ****************************************/
template <class T>
Hash <T> :: Hash()
{
   this->numElements = 0;
   this->numBuckets = 0;
}

/****************************************
 * HASH - Hash
 * takes the number of buckets as a 
 * parameter
 ****************************************/
template <class T>
Hash <T> :: Hash(const Hash <T> & rhs)
{
   this->numElements = rhs.numElements;
   this->numBuckets = rhs.numBuckets;
   this->table = new list <T> [numBuckets];
   for(int i = 0; i < numBuckets; i++)
      this->table[i] = rhs.table[i];
}

/****************************************
 * HASH - Hash
 * takes the number of buckets as a
 * parameter
 ****************************************/
template <class T>
Hash <T> :: Hash(const int numBuckets)
{
   this->numElements = 0;
   this->numBuckets = numBuckets;
   this->table = new list <T> [numBuckets];
}

/****************************************
 * HASH - empty
 * Determines whether the current Hash 
 * is empty
 ****************************************/
template <class T>
bool Hash <T> :: empty() const
{
   if(numElements == 0)
      return true;
   else
      return false;
}

/****************************************
 * HASH - operator = 
 * Copy one Hash into another
 ****************************************/
template <class T>
Hash <T> & Hash <T> :: operator = (const Hash <T> & rhs)
{
   this->numElements = rhs.numElements;
   this->numBuckets = rhs.numBuckets;
   this->table = new list <T> [numBuckets];
   for(int i = 0; i < numBuckets; i++)
      this->table[i] = rhs.table[i];

   return *this;
}

}; // namespace custom

#endif // HASH_H



