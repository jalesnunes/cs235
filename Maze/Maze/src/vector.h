/***********************************************************************
 * Header:
 *    Vector
 * Summary:
 *    This class contains the notion of an array: a bucket to hold
 *    data for the user. This is just a starting-point for more advanced
 *    constainers such as the vector, set, stack, queue, deque, and map
 *    which we will build later this semester.
 *
 *    This will contain the class definition of:
 *       array             : similar to std::array
 *       array :: iterator : an iterator through the array
 * Author
 *    Br. Helfrich
 ************************************************************************/

#ifndef VECTOR_H
#define VECTOR_H

#include <cassert>  // because I am paranoid

// a little helper macro to write debug code
#ifdef NDEBUG
#define Debug(statement)
#else
#define Debug(statement) statement
#endif // !NDEBUG

namespace custom
{

/************************************************
 * VECTOR
 * A class that holds stuff
 ***********************************************/
template <class T>
class vector
{
public:
   // constructors and destructors
   vector();
   vector(int num);
   vector(const vector <T> & rhs);
  ~vector()                         
   {
      if(capacity() != 0)
      { 
         delete [] data;
         data = NULL;
      }
   }

   vector & operator = (const vector & rhs); 
   
   // standard container interfaces
   // array treats size and max_size the same
   bool empty()    const;
   int  size()     const { return numElements;                 }
   int  capacity() const { return numCapacity;                 }   
   
   // array-specific interfaces
   // what would happen if I passed -1 or something greater than num?
   T & operator [] (int index)
   {
      return data[index];
   }
   const T & operator [] (int index) const 
   {
      return data[index];
   }   

   // push back
   void push_back(const T t);
   void clear();
   
   // the various iterator interfaces
   class iterator;
   iterator begin()      { return iterator (data); }
   iterator end();


   // the various iterator interfaces
   class const_iterator;
   const_iterator cbegin() const     { return const_iterator (data); }
   const_iterator cend() const;


private:
   T * data;              // dynamically allocated array of T
   int numElements;       // number of elements
   int numCapacity;       // the capacity

   void resize (int numCapacity);
};

/**************************************************
 * VECTOR ITERATOR
 * An iterator through vector
 *************************************************/
template <class T>
class vector <T> :: iterator
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
 * VECTOR CONST ITERATOR
 * An const iterator through vector
 *************************************************/
template <class T>
class vector <T> :: const_iterator
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

/********************************************
 * VECTOR :: END
 * Note that you have to use "typename" before
 * the return value type
 ********************************************/
template <class T>
typename vector <T> :: const_iterator vector <T> :: cend() const
{
   return const_iterator (data + numElements);
}

/********************************************
 * VECTOR :: END
 * Note that you have to use "typename" before
 * the return value type
 ********************************************/
template <class T>
typename vector <T> :: iterator vector <T> :: end ()
{
   return iterator (data + numElements);
}

/**********************************************
 * VECTOR : 
 **********************************************/
template <class T>
void vector <T> :: clear()
{
   for (int i = 0; i < size(); i++)
      data[i] = 0;

   this->numElements = 0; 
}

/**********************************************
 * VECTOR : 
 **********************************************/
template <class T>
void vector <T> :: push_back(const T t)
{
   if(capacity() == 0)
      resize(1);
   else if(capacity() == size())
      resize(capacity() * 2);

   data[numElements++] = t;
}

/**********************************************
 * VECTOR : 
 **********************************************/
template <class T>
bool vector <T> :: empty() const
{
   if(this->numElements == 0) 
      return true;
   else
      return false;
}

/**********************************************
 * VECTOR : 
 **********************************************/
template <class T>
void vector <T> :: resize (int numCapacity)
{
   T * newData;

   // attempt to allocate
   try
   {
      newData = new T[numCapacity];
   }
   catch (std::bad_alloc)
   {
      throw "ERROR: Unable to allocate buffer";
   }

   for (int i = 0; i < numElements; i++)
      newData[i] = data[i];

   delete [] data;
   data = newData;
   this->numCapacity = numCapacity;

}

/*******************************************
 * VECTOR :: Assignment
 *******************************************/
template <class T>
vector <T> & vector <T> :: operator = (const vector <T> & rhs)
{
   if (rhs.size() > this->capacity())
      resize(rhs.size());

   this->numElements = rhs.size();
   this->numCapacity = rhs.capacity();

   for (int i = 0; i < this->size(); i++)
      this->data[i] = rhs.data[i];

   return *this;
}

/*******************************************
 * VECTOR :: COPY CONSTRUCTOR
 *******************************************/
template <class T>
vector <T> :: vector(const vector <T> & rhs) 
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
      throw "ERROR: Unable to allocate buffer";
   }
   
   // copy over the capacity
   this->numElements = rhs.numElements;
   this->numCapacity = rhs.numCapacity;

   // copy the items over one at a time using the assignment operator
   for (int i = 0; i < numElements; i++)
      this->data[i] = rhs.data[i];
}

/**********************************************
 * VECTOR : NON-DEFAULT CONSTRUCTOR
 * Preallocate the array to "capacity"
 **********************************************/
template <class T>
vector <T> :: vector(int num) 
{
   assert(num >= 0);
   
   // do nothing if there is nothing to do.
   // since we can't grow an array, this is kinda pointless
   if (num == 0)
   {
      this->data = NULL;
      this->numElements = 0;
      this->numCapacity = 0;
      return;
   }

   // attempt to allocate
   try
   {
      data = new T[num];
   }
   catch (std::bad_alloc)
   {
      throw "ERROR: Unable to allocate buffer";
   }

   // copy over the stuff
   this->numElements = num;
   this->numCapacity = num;
}


/**********************************************
 * VECTOR : DEFAULT CONSTRUCTOR
 **********************************************/
template <class T>
vector <T> :: vector() 
{
   this->data = NULL;
   this->numElements = 0;
   this->numCapacity = 0;
}








}; // namespace custom

#endif // VECTOR_H



