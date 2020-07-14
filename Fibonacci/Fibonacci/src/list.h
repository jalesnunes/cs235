/***********************************************************************
 * Header: Class List
 * 
 * Summary: This program implements the List data structure
 * 
 * Author: Jales Nunes, Davi Neves
 *   
 *************************************************************************/

#ifndef LIST_H
#define LIST_H

#include <cassert>  // because I am paranoid
#include <iostream>        // for CIN and COUT
using namespace std;


// a little helper macro to write debug code
#ifdef NDEBUG
#define Debug(statement)
#else
#define Debug(statement) statement
#endif // !NDEBUG

namespace custom
{

/************************************************
 * NODE
 * A class that holds stuff, and each element 
 * points to the next and previous elements.
 ***********************************************/
template <class T>
class Node
{
public:
   // constructors and destructors
   Node();
   Node(const T & t);

   T data;
   Node <T> * pNext;
   Node <T> * pPrev;
};
/**********************************************
 * NODE : DEFAULT CONSTRUCTOR
 **********************************************/
template <class T>
Node <T> :: Node() 
{
   this->pNext = NULL;
   this->pPrev = NULL;
}
/**********************************************
 * NODE : NON-DEFAULT CONSTRUCTOR
 * Preallocate the array to "capacity"
 **********************************************/
template <class T>
Node <T> :: Node(const T & t) 
{
   this->data = t;
   this->pNext = NULL;
   this->pPrev = NULL;
}


/************************************************
 * LIST : Class LIST
 * Class that holds a collection of Nodes
 ***********************************************/
template <class T>
class list
{
public:
   // constructors and destructors
   list();
   list(const list <T> & rhs);
  ~list()                         
   {
      Node <T> * pDelete;
   
      while(pHead)
      {
         pDelete = pHead;
         pHead = pHead->pNext;
         delete pDelete;
      }
   }
   
   list & operator = (const list & rhs); 
   
   bool empty()    const;
   int  size()     const { return numElements; }   
   void clear();
   
   void push_back(const T & t);
   void push_front(const T & t);
   void pop_back();
   void pop_front();   
      
   T & back()       { return pTail->data; }
   T & front()      { return pHead->data; }
   T back() const   { return pTail->data; }
   T front() const  { return pHead->data; }
   
   
   // the various iterator interfaces
   class iterator;
   iterator begin()      { return iterator (pHead); }
   iterator end()        { return iterator (NULL);   } 
   
   iterator insert(iterator it, const T & t);
   iterator erase(iterator it);
   iterator find(const T & t);

   // the reverse iterator 
   class reverse_iterator;
   reverse_iterator rbegin()      { return reverse_iterator (pTail); }
   reverse_iterator rend()        { return reverse_iterator (NULL);  }


   // the constant iterator 
   class const_iterator;
   const_iterator cbegin() const     { return const_iterator (pHead); }
   const_iterator cend() const       { return const_iterator (NULL);  } 

   // the constant reverse iterator 
   class const_reverse_iterator;
   const_reverse_iterator crbegin() const     { return const_reverse_iterator (pTail); }
   const_reverse_iterator crend() const       { return const_reverse_iterator (NULL);  }

 
private:
   Node <T> * pHead;
   Node <T> * pTail;
   int numElements;
};

/**************************************************
 * LIST ITERATOR
 * An iterator through list
 *************************************************/
template <class T>
class list <T> :: iterator
{
public:
   // constructors, destructors, and assignment operator
   iterator()      : p(NULL)      {              }
   iterator(Node <T> * p) : p(p)         {              }
   iterator(const iterator & rhs) { *this = rhs; }
   iterator & operator = (const iterator & rhs)
   {
      this->p = rhs.p;
      return *this;
   }

   // equals, not equals operator
   bool operator != (const iterator & rhs) const { return rhs.p != this->p; }
   bool operator == (const iterator & rhs) const { return rhs.p == this->p; }

   // dereference operator
         T & operator * ()       { return p->data; }
   const T & operator * () const { return p->data; }

   // prefix increment
   iterator & operator ++ ()
   {
      p = p->pNext;
      return *this;
   }

   // postfix increment
   iterator operator ++ (int postfix)
   {
      iterator tmp(*this);
      p = p->pNext;
      return tmp;
   }

   // prefix decrement
   iterator & operator -- ()
   {
      p = p->pPrev;
      return *this;
   }

   // postfix decrement
   iterator operator -- (int postfix)
   {
      iterator tmp(*this);
      p = p->pPrev;
      return tmp;
   }
   
   friend iterator list <T> :: insert(iterator it, const T & t);
   friend iterator list <T> :: erase(iterator it);
   friend iterator list <T> :: find(const T & t);
   
private:
   Node <T> * p;
};

/**************************************************
 * LIST reverse_iterator
 * A reverse iterator through list
 *************************************************/
template <class T>
class list <T> :: reverse_iterator
{
public:
   // constructors, destructors, and assignment operator
   reverse_iterator()      : p(NULL)      {              }
   reverse_iterator(Node <T> * p) : p(p)         {              }
   reverse_iterator(const reverse_iterator & rhs) { *this = rhs; }
   reverse_iterator & operator = (const reverse_iterator & rhs)
   {
      this->p = rhs.p;
      return *this;
   }

   // equals, not equals operator
   bool operator != (const reverse_iterator & rhs) const { return rhs.p != this->p; }
   bool operator == (const reverse_iterator & rhs) const { return rhs.p == this->p; }

   // dereference operator
         T & operator * ()       { return p->data; }
   const T & operator * () const { return p->data; }

   // prefix increment
   reverse_iterator & operator ++ ()
   {
      p = p->pPrev;
      return *this;
   }

   // postfix increment
   reverse_iterator operator ++ (int postfix)
   {
      reverse_iterator tmp(*this);
      p = p->pPrev;
      return tmp;
   }

   // prefix decrement
   reverse_iterator & operator -- ()
   {
      p = p->pNext;
      return *this;
   }

   // postfix decrement
   reverse_iterator operator -- (int postfix)
   {
      reverse_iterator tmp(*this);
      p = p->pNext;
      return tmp;
   }
   
private:
   Node <T> * p;
};


/**************************************************
 * LIST CONST ITERATOR
 * A constant iterator through list
 *************************************************/
template <class T>
class list <T> :: const_iterator
{
public:
   // constructors, destructors, and assignment operator
   const_iterator()      : p(NULL)      {              }
   const_iterator(Node <T> * p) : p(p)         {              }
   const_iterator(const const_iterator & rhs) { *this = rhs; }
   const_iterator & operator = (const const_iterator & rhs)
   {
      this->p = rhs.p;
      return *this;
   }

   // equals, not equals operator
   bool operator != (const const_iterator & rhs) const { return rhs.p != this->p; }
   bool operator == (const const_iterator & rhs) const { return rhs.p == this->p; }

   // dereference operator
         T & operator * ()       { return p->data; }
   const T & operator * () const { return p->data; }

   // prefix increment
   const_iterator & operator ++ ()
   {
      p = p->pNext;
      return *this;
   }

   // postfix increment
   const_iterator operator ++ (int postfix)
   {
      const_iterator tmp(*this);
      p = p->pNext;
      return tmp;
   }

   // prefix decrement
   const_iterator & operator -- ()
   {
      p = p->pPrev;
      return *this;
   }

   // postfix decrement
   const_iterator operator -- (int postfix)
   {
      const_iterator tmp(*this);
      p = p->pPrev;
      return tmp;
   }
   
private:
   Node <T> * p;
};

/**************************************************
 * LIST const_reverse_iterator
 * A reverse const iterator through list
 *************************************************/
template <class T>
class list <T> :: const_reverse_iterator
{
public:
   // constructors, destructors, and assignment operator
   const_reverse_iterator()      : p(NULL)      {              }
   const_reverse_iterator(Node <T> * p) : p(p)         {              }
   const_reverse_iterator(const const_reverse_iterator & rhs) { *this = rhs; }
   const_reverse_iterator & operator = (const const_reverse_iterator & rhs)
   {
      this->p = rhs.p;
      return *this;
   }

   // equals, not equals operator
   bool operator != (const const_reverse_iterator & rhs) const { return rhs.p != this->p; }
   bool operator == (const const_reverse_iterator & rhs) const { return rhs.p == this->p; }

   // dereference operator
         T & operator * ()       { return p->data; }
   const T & operator * () const { return p->data; }

   // prefix increment
   const_reverse_iterator & operator ++ ()
   {
      p = p->pPrev;
      return *this;
   }

   // postfix increment
   const_reverse_iterator operator ++ (int postfix)
   {
      const_reverse_iterator tmp(*this);
      p = p->pPrev;
      return tmp;
   }

   // prefix decrement
   const_reverse_iterator & operator -- ()
   {
      p = p->pNext;
      return *this;
   }

   // postfix decrement
   const_reverse_iterator operator -- (int postfix)
   {
      const_reverse_iterator tmp(*this);
      p = p->pNext;
      return tmp;
   }
   
private:
   Node <T> * p;
};

/**********************************************
 * LIST : Find  
 **********************************************/
template <class T>
typename list <T> :: iterator list <T> :: find(const T & t)
{
   list <T> :: iterator it;

   for (it = begin(); it != end(); ++it)
      if(it.p->data == t)
         return it;

   return NULL;

   return it;
}

/**********************************************
 * LIST : Erase 
 **********************************************/
template <class T>
typename list <T> :: iterator list <T> :: erase(list <T> :: iterator it)
{
   Node <T> * pRemove = it.p;

   if(it == NULL)
      return it;
      
   it++;
   
   if(pRemove->pPrev)
      pRemove->pPrev->pNext = pRemove->pNext;
   else
      pHead = pRemove->pNext;
   if(pRemove->pNext)
      pRemove->pNext->pPrev = pRemove->pPrev;
   else
      pTail = pRemove->pPrev;
      
   delete pRemove;
   numElements--;

   return it;
}

/**********************************************
 * LIST : Insert 
 **********************************************/
template <class T>
typename list <T> :: iterator list <T> :: insert(list <T> :: iterator it, const T & t)
{
   Node <T> * pNew = new Node <T> (t);
   
   if(it != NULL)
   {
      pNew->pNext = it.p;
      pNew->pPrev = it.p->pPrev;
      it.p->pPrev = pNew;
      if(pNew->pPrev)
         pNew->pPrev->pNext = pNew;
      if(it.p == pHead)
         pHead = pNew;
      it++;
   }
   else
   {
      pTail->pNext = pNew;
      pNew->pPrev = pTail;
      pNew->pNext = NULL;
      pTail = pNew;
   }

   numElements++;
   
   return it;
}

/**********************************************
 * LIST : Pop_back 
 **********************************************/
template <class T>
void list <T> :: pop_back()
{
   Node <T> * p = pTail;
   
   if(pTail == NULL)
      return;
   else if(pTail == pHead)
   {
      pTail = NULL;
      pHead = NULL;
      delete p;
   }
   else
   {
      pTail = pTail->pPrev;
      pTail->pNext = NULL;
      numElements--;
      delete p;
   }
}

/**********************************************
 * LIST : Pop_front
 **********************************************/
template <class T>
void list <T> :: pop_front()
{
   Node <T> * p = pHead;

   if(pHead == NULL)
      return;
   else if(pTail == pHead)
   {
      pTail = NULL;
      pHead = NULL;
      delete p;
   }
   else
   {   
      pHead = pHead->pNext;
      pHead->pPrev = NULL;
      numElements--;
      delete p;
   }
}
   
/**********************************************
 * LIST : Push_front
 **********************************************/
template <class T>
void list <T> :: push_front(const T & t)
{
   Node <T> * pNew = new Node <T> (t);
   
   pNew->pNext = pHead;   
   pNew->pPrev = NULL;
   if(pHead)
      pHead->pPrev = pNew;
   
   pHead = pNew;
   numElements++;
   
   if(pTail == NULL)
      pTail = pNew;
 
}

/**********************************************
 * LIST : Push_back
 **********************************************/
template <class T>
void list <T> :: push_back(const T & t)
{
   Node <T> * pNew = new Node <T> (t);
   
   pNew->pNext = NULL;   
   pNew->pPrev = pTail;
   if(pTail != NULL)
      pTail->pNext = pNew;
      
   pTail = pNew;
   numElements++;  
   
   if(pHead == NULL)
      pHead = pTail;
 
}

/**********************************************
 * LIST : Clear
 **********************************************/
template <class T>
void list <T> :: clear()
{
   Node <T> * pDelete;
   
   while(pHead)
   {
      pDelete = pHead;
      pHead = pHead->pNext;
      delete pDelete;
   }
   pTail = NULL;
   numElements = 0;
}

/**********************************************
 * LIST : Empty
 **********************************************/
template <class T>
bool list <T> :: empty() const
{
   if(this->numElements == 0) 
      return true;
   else
      return false;
}

/**********************************************
 * LIST : DEFAULT CONSTRUCTOR
 **********************************************/
template <class T>
list <T> :: list() 
{
   this->pHead = NULL;
   this->pTail = NULL;
   this->numElements = 0;
}

/*******************************************
 * LIST :: COPY CONSTRUCTOR
 *******************************************/
template <class T>
list <T> :: list(const list <T> & rhs) 
{
   assert(rhs.numElements >= 0);
      
   // do nothing if there is nothing to do
   if (rhs.numElements == 0)
   {
      this->pHead = NULL;
      this->pTail = NULL;
      this->numElements = 0;
      return;
   }
   
   this->pHead = new Node <T> (rhs.pHead->data);
   this->pTail = this->pHead;
   
   Node <T> * pCopy = rhs.pHead->pNext;
   while(pCopy)
   {
      push_back(pCopy->data);
      pCopy = pCopy->pNext;
   }
   this->numElements = rhs.numElements;
}

/*******************************************
 * LIST :: Assignment Operator
 *******************************************/
template <class T>
list <T> & list <T> :: operator = (const list <T> & rhs)
{

   this->clear();
   
   assert(rhs.numElements >= 0);
      
   // do nothing if there is nothing to do
   if (rhs.numElements == 0)
   {
      this->pHead = NULL;
      this->pTail = NULL;
      this->numElements = 0;
      return *this;
   }
   
   this->pHead = new Node <T> (rhs.pHead->data);
   this->pTail = this->pHead;
   
   Node <T> * pCopy = rhs.pHead->pNext;
   while(pCopy)
   {
      push_back(pCopy->data);
      pCopy = pCopy->pNext;
   }
   this->numElements = rhs.numElements;

   return *this;
}


}; // namespace custom

#endif // LIST_H



