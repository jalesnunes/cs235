/***********************************************************************
* Program:
*    Assignment 05, Set
*    Brother Kirby, CS 235
* Author:
*    Jales Nunes, Davi Neves
* Summary:
*    This program defines the Class Set.
************************************************************************/

#ifndef SET_H
#define SET_H
#include <assert.h>

using std::cout;
using std::endl;

namespace custom
{

/************************************************
* Set
* class that holds an array of any size and type
***********************************************/
template <class T>
class set
{
public:
   // constructors and destructors
   set() : data(NULL), numCapacity(0), numElements(0) {}
   set(int numCapacity);
   set(const set<T>& rhs);
   ~set()
   {
      if (numCapacity != 0)
      {
         delete[] data;
         data = NULL;
      }
   }

   set<T> & operator = (const set<T>& rhs);
   set<T> operator || (const set<T>& rhs) const;
   set<T> operator && (const set<T>& rhs) const;
   set<T> operator -  (const set<T>& rhs) const;


   // standard container interfaces
   int size()     const { return numElements; }
   int capacity() const { return numCapacity; }
   bool empty() const ;
   void clear();
   void insert(const T & t);

   // the various iterator interfaces
   class iterator;
   iterator begin()      { return iterator (data); }
   iterator end();

   // the various iterator interfaces
   class const_iterator;
   const_iterator cbegin() const     { return const_iterator (data); }
   const_iterator cend() const;


   iterator find(const T & t);
   iterator erase(set<T> :: iterator & it);

private:
   T* data;         // dynamically allocated array of T
   int numCapacity; // the capacity
   int numElements; // the elements

   void resize(int newCapacity);
   int findIndex(const T & element);
};

/**************************************************
 * SET ITERATOR
 * An iterator through set
 *************************************************/
template <class T>
class set<T>::iterator
{
public:
   // constructors, destructors, and assignment operator
   iterator()      : p(NULL)      {              }
   iterator(T * p) : p(p)         {              }
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
         T & operator * ()       { return *p; }
   const T & operator * () const { return *p; }

   // prefix increment
   iterator & operator ++ ()
   {
      p++;
      return *this;
   }

   // postfix increment
   iterator operator ++ (int postfix)
   {
      iterator tmp(*this);
      p++;
      return tmp;
   }

   // prefix decrement
   iterator & operator -- ()
   {
      p--;
      return *this;
   }

   // postfix decrement
   iterator operator -- (int postfix)
   {
      iterator tmp(*this);
      p--;
      return tmp;
   }
   
private:
   T * p;
};

/**************************************************
 * SET CONST ITERATOR
 * An const iterator through set
 *************************************************/
template <class T>
class set <T> :: const_iterator
{
public:
   // constructors, destructors, and assignment operator
   const_iterator()      : p(NULL)      {              }
   const_iterator(T * p) : p(p)         {              }
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
         T & operator * ()       { return *p; }
   const T & operator * () const { return *p; }

   // prefix increment
   const_iterator & operator ++ ()
   {
      p++;
      return *this;
   }

   // postfix increment
   const_iterator operator ++ (int postfix)
   {
      const_iterator tmp(*this);
      p++;
      return tmp;
   }

   // prefix decrement
   const_iterator & operator -- ()
   {
      p--;
      return *this;
   }

   // postfix decrement
   const_iterator operator -- (int postfix)
   {
      const_iterator tmp(*this);
      p--;
      return tmp;
   }
   
private:
   T * p;
};

/*******************************************
* SET :: -
*******************************************/
template <class T>
set<T> set<T> :: operator - (const set<T> & rhs) const
{   
   int iLhs = 0;
   int iRhs = 0;
   set<T> setReturn;
   
   while(iLhs < this->numElements or iRhs < rhs.numElements)
   {
      if(iLhs == this->numElements)
      {
         iRhs++;
      }
      else if(iRhs == rhs.numElements)
      {
         setReturn.insert(this->data[iLhs]);
         iLhs++;
      }
      else if(this->data[iLhs] == rhs.data[iRhs])
      {
         iLhs++;
         iRhs++;
      }
      else if(this->data[iLhs] < rhs.data[iRhs])
      {
         setReturn.insert(this->data[iLhs]);
         iLhs++;
      }
      else
      {
         iRhs++;
      }
   }
   
   return setReturn;
}

/*******************************************
* SET :: &&
*******************************************/
template <class T>
set<T> set<T> :: operator && (const set<T> & rhs) const
{   
   int iLhs = 0;
   int iRhs = 0;
   set<T> setReturn;
   
   while(iLhs < this->numElements or iRhs < rhs.numElements)
   {
      if(iLhs == this->numElements)
         return setReturn;
      else if(iRhs == rhs.numElements)
         return setReturn;
      else if(this->data[iLhs] == rhs.data[iRhs])
      {
         setReturn.insert(this->data[iLhs]);
         iLhs++;
         iRhs++;
      }
      else if(this->data[iLhs] < rhs.data[iRhs])
         iLhs++;
      else
         iRhs++;
   }
   
   return setReturn;
}

/*******************************************
* SET :: Union ||
*******************************************/
template <class T>
set<T> set<T> :: operator || (const set<T> & rhs) const
{   
   int iLhs = 0;
   int iRhs = 0;
   set<T> setReturn;
   
   while(iLhs < this->numElements or iRhs < rhs.numElements)
   {
      if(iLhs == this->numElements)
      {
         setReturn.insert(rhs.data[iRhs]);
         iRhs++;
      }
      else if(iRhs == rhs.numElements)
      {
         setReturn.insert(this->data[iLhs]);
         iLhs++;
      }
      else if(this->data[iLhs] == rhs.data[iRhs])
      {
         setReturn.insert(this->data[iLhs]);
         iLhs++;
         iRhs++;
      }
      else if(this->data[iLhs] < rhs.data[iRhs])
      {
         setReturn.insert(this->data[iLhs]);
         iLhs++;
      }
      else
      {
         setReturn.insert(rhs.data[iRhs]);
         iRhs++;
      }
   }
   
   return setReturn;
}

/********************************************
 * SET :: erase
 ********************************************/
template <class T>
typename set <T> :: iterator set <T> :: erase (set<T> :: iterator & it)
{
   int iErase = findIndex(*it);

   if(data[iErase] == *it)
   {
      for(int i = iErase; i < numElements - 1;i++)
      {

         data[i] = data[i + 1];
      }
      numElements--;
   }
   
   return it;
}

/********************************************
 * SET :: Find
 ********************************************/
template <class T>
typename set <T> :: iterator set <T> :: find (const T & t)
{
   int iInsert = findIndex(t);
   
   if(size() == 0)
      return end();
   else
   {
      if(data[iInsert] == t)
         return iterator(data + iInsert);
      else
         return end();
   }
}

/********************************************
 * SET :: END
 * Note that you have to use "typename" before
 * the return value type
 ********************************************/
template <class T>
typename set <T> :: const_iterator set <T> :: cend() const
{
   return const_iterator (data + numElements);
}

/********************************************
 * SET :: END
 * Note that you have to use "typename" before
 * the return value type
 ********************************************/
template <class T>
typename set <T> :: iterator set <T> :: end ()
{
   return iterator (data + numElements);
}

/**********************************************
* SET : Clear
**********************************************/
template <class T>
void set<T>::clear()
{
   numElements = 0;
}

/**********************************************
* SET : Empty
**********************************************/
template <class T>
bool set<T>::empty() const
{
   if (size() == 0)
   {
      return true;
   }
   else
   {
      return false;
   }
}

/**********************************************
* SET : Resize the deque capacity
**********************************************/
template <class T>
void set<T>::resize(int newCapacity)
{
   // do nothing if there is nothing to do
   if (newCapacity < numCapacity)
   {
      return;
   }
   
   // attempt to allocate
   try
   {
      T* dataNew = new T[newCapacity];

		 // copy the items over one at a time
		 for (int i = 0; i < size();  i++)
		    dataNew[i] = data[i];

      data = dataNew;
      numCapacity = newCapacity;
   }
   catch (std::bad_alloc) 
   {
      throw "ERROR: Unable to allocate new buffer for queue";
   }
}

/**********************************************
* SET : Find index of the element or where the
*       element should go
**********************************************/
template <class T>
int set<T>::findIndex(const T & element)
{
   int iBegin = 0;
   int iEnd = numElements - 1;
   int iMiddle;
   
   while(iBegin <= iEnd)
   {
      iMiddle = (iBegin + iEnd) / 2;
      if(element == data[iMiddle])
         return iMiddle;
      if(element < data[iMiddle])
         iEnd = iMiddle - 1;
      else
         iBegin = iMiddle + 1;
   }
   
   return iBegin;
}

/**********************************************
* SET : Insert t in the right place (ordered 
*       array)
**********************************************/
template <class T>
void set<T>::insert(const T & t)
{  
   int iInsert;

   if (capacity() == 0)
   {
      resize(1);
   }
   else if (size() == capacity())
   {
      resize(capacity() * 2);
   }
   
   if(size() == 0)
   {
      data[0] = t;
      numElements = numElements + 1;
   }   
   else
   {
      iInsert = findIndex(t);
      if(data[iInsert] != t)
      {
         for(int i = size()-1; i >= iInsert; --i)
            data[i + 1] = data[i];
         data[iInsert] = t;
         numElements = numElements + 1;
      }
   }
}

/*******************************************
* SET :: Assignment =
*******************************************/
template <class T>
set<T>& set<T>::operator=(const set<T>& rhs)
{

   if (capacity() < rhs.size())
   {
       resize(rhs.size());
   }

   // copy over the capacity
   numCapacity = rhs.size();
   numElements = rhs.size();

   // copy the items over one at a time
   for (int i = 0; i < rhs.size();  i++)
      data[i] = rhs.data[i];

   return *this;
}

/*******************************************
* SET :: COPY CONSTRUCTOR
*******************************************/
template <class T>
set<T>::set(const set<T>& rhs)
{
   assert(rhs.numElements >= 0);
   
   // do nothing if there is nothing to do
   if (rhs.numElements == 0)
   {
      this->data = NULL;
      this->numElements = 0;
      this->numCapacity = 0;
      return;
   }

   // attempt to allocate
   try
   {
      data = new T[rhs.numCapacity];
   }
   catch (std::bad_alloc)
   {
      throw "ERROR: Unable to allocate a new buffer for set";
   }

   // copy over the capacity
   this->numCapacity = rhs.numCapacity;
   this->numElements = rhs.numElements;

   // copy the items over one at a time using the assignment operator
   for (int i = 0; i < numElements;  i++)
      this->data[i] = rhs.data[i];      
}

/********************************************
* CONSTRUCTOR: NON-DEFAULT
*******************************************/
template <class T>
set<T>::set(int numCapacity)
{
   this->numCapacity = numCapacity;
   this->numElements = 0;
   this->data = NULL;

   // attempt to allocate
   try
   {
      data = new T[numCapacity];
   }
   catch (std::bad_alloc)
   {
      throw "ERROR: Unable to allocate a new buffer for set";
   }
}

}; // namespace custom
#endif /* SET_H */



