/***********************************************************************
 * Module:
 *    PAIR
 * Author:
 *    Br. Helfrich
 * Summary:
 *    This program will implement a pair: two values
 ************************************************************************/

#ifndef MAP_H
#define MAP_H

#include <iostream>  // for ISTREAM and OSTREAM
#include "bst.h"
#include "pair.h"
using::custom::pair;

namespace custom
{

/**********************************************
 * MAP
 ***********************************************/
template <class K, class V>
class map
{
public:
   // constructors
   map(){}
   map(const BST <pair <K, V> > & rhs) { bst = rhs.bst; }
   ~map() { clear(); }
   
   map & operator = (const BST <pair <K, V> > & rhs) { bst = rhs.bst; }
   
   int size()   { return bst.size();  }
   bool empty() { return bst.empty(); }
   void clear() { bst.clear(); }
   
   void insert(const pair <K, V> & input);
   void insert(const K & k, const V & v);

   V & operator [] (const K & k);
   V operator [] (const K & k) const;   
   
   class iterator;
   iterator begin() { return iterator(bst.begin()); }
   iterator end()   { return iterator(bst.end());   }

   iterator find(const K & k);

   
private:
   BST <pair <K, V> > bst;

};
/**************************************************
 * MAP ITERATOR
 * An iterator through map
 *************************************************/
template <class K, class V>
class map <K, V> :: iterator
{
public:
   // constructors, destructors, and assignment operator
   iterator()                                                    { }
   iterator(const typename BST < pair<K, V> > :: iterator & rhs) { this->it = rhs; }
   iterator(const iterator & rhs)                                { *this = rhs;    }

   iterator & operator = (const iterator & rhs)
   {
      this->it = rhs.it;
      return *this;
   }

   // equals, not equals operator
   bool operator != (const iterator & rhs) const { return this->it != rhs.it; }
   bool operator == (const iterator & rhs) const { return this->it == rhs.it; }

   // prefix increment
   iterator & operator ++ () { ++it; return *this; }

   // postfix increment
   iterator operator ++ (int postfix) { it++; return *this;}
   
   // prefix decrement
   iterator & operator -- () { --it; return *this;}

   // postfix decrement
   iterator operator -- (int postfix) { it--; return *this;}

   // dereference operator
         pair<K, V> & operator * ()       { return *it; }
   const pair<K, V> & operator * () const { return *it; }


private:
   typename BST < pair<K, V> > :: iterator it;
};

/**************************************************
 * MAP - find
 * value to be found and the return value is 
 * an iterator
 *************************************************/
template <class K, class V>
typename map <K, V> :: iterator map <K, V> :: find(const K & k)
{
   typename map < K, V > :: iterator it;
   for (it = begin(); it != end(); ++it)
      if((*it).getFirst() == k)
         return it;

   return it;
}

/**************************************************
 * MAP - insert
 * Insert elements
 *************************************************/
template <class K, class V>
void map <K, V> :: insert(const pair <K, V> & input)
{
   typename map < K, V > :: iterator it;
   it = find(input.first);
   if(it != end())
      *it = input;
   else
      bst.insert(input);
}

/**************************************************
 * MAP - insert
 * Insert elements
 *************************************************/
template <class K, class V>
void map <K, V> :: insert(const K & k, const V & v)
{  
   pair <K, V> p(k, v);
   insert(p);
}

/**************************************************
 * MAP - operator []
 * insert a new data value into the map
 *************************************************/
template <class K, class V>
V & map <K, V> :: operator [] (const K & k)
{  
   typename map < K, V > :: iterator it;
   it = find(k);
   
   V(v);   
   pair <K, V> p(k, v);
 
   if(it != end())
      return (*it).second;
   else
   {
      insert(p);
      return (*(find(p.first))).second;
   }
}

/**************************************************
 * MAP - operator [] 
 * retrieve a given data value from the map
 *************************************************/
template <class K, class V>
V map <K, V> :: operator [] (const K & k) const
{
   cout << "teste [] const" << endl;
   typename map < K, V > :: iterator it;
   it = find(k);
 
   if(it != end())
      return (*it).second;
   else
      return end();
}


}

#endif // MAP_H
