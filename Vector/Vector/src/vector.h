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
 *       vector             : similar to std::array
 *       vector :: iterator : an iterator through the array
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
 * ARRAY
 * A class that holds stuff
 ***********************************************/
template <class T>
class vector
{
private:
   T* data;              // dynamically allocated vector of T
   int numElements;      // both the capacity and the number of elements
   int numCapacity;      // vector capacity

public:
   // constructors and destructors
   vector() : data(NULL), numElements(0), numCapacity(0) {}
   vector(int numElements) throw(const char*);
   vector(const vector& rhs) throw(const char*);

   //Destructor
   ~vector() { delete [] data; }
   vector& operator = (const vector& rhs) throw (const char*);
   
   // standard container interfaces
   // array treats size and max_size the same
   int  size()     const { return numElements;                 }

   //vector functions 
   bool empty() const { return numElements == 0; }

   int capacity() { return numCapacity; }

   void push_back(const T t) throw (const char*);

   void clear(){ numElements = 0; }
   
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
   
   // the various iterator interfaces
   class iterator;
   iterator begin() { return iterator (data); }
   iterator end() { return iterator(data + numElements); }
};

/**********************************************
 * Vector : NON-DEFAULT CONSTRUCTOR
 * Preallocate the array to "capacity"
 **********************************************/
template <class T>
vector <T>::vector(int numElements) throw(const char*)
{
   assert(numElements >= 0);

   // do nothing if there is nothing to do.
   // since we can't grow an array, this is kinda pointless
   if (numElements == 0)
   {
      this->numElements = 0;
      this->data = NULL;
      return;
   }

   numCapacity = 1;

   do
   {
      numCapacity *= 2;

   } while (numCapacity < numElements);

   // attempt to allocate
   try
   {
      data = new T[numElements];
   }
   catch (std::bad_alloc)
   {
      throw "ERROR: Unable to allocate a new buffer for vector";
   }

   // copy over the stuff
   this->numElements = numElements;

}

/*******************************************
 * Vector :: COPY CONSTRUCTOR
 *******************************************/
template <class T>
vector <T> ::vector(const vector <T>& rhs) throw(const char*)
{
   assert(rhs.numElements >= 0);

   // do nothing if there is nothing to do
   if (rhs.numElements == 0)
   {
      numElements = 0;
      data = NULL;
      return;
   }

   // attempt to allocate
   try
   {
      data = new T[rhs.numElements];
   }
   catch (std::bad_alloc)
   {
      throw "ERROR: Unable to allocate a new buffer for vector";
   }

   // copy over the capacity
   numElements = rhs.numElements;
   numCapacity = rhs.numCapacity;
   
   // copy the items over one at a time using the assignment operator
   for (int i = 0; i < numElements; i++)
   {
        data[i] = rhs.data[i];
   }
}

/*******************************************
 * push_back aplication
 *******************************************/
template <class T>
void vector<T> :: push_back(const T t) throw (const char*)
{
   int addCapacity;
   T* addData;

   if (numElements == numCapacity)
   {
      int addCapacity = numCapacity == 0 ? 1 : numCapacity * 2;
      if (numCapacity == 0)
      {
         addCapacity = numCapacity = 1;
      }
      else
      {
         addCapacity = numCapacity *= 2;
      }
      try
      {
         addData = new T[addCapacity];
         if (data == NULL)
         {
            data = addData;
         }
         else
         {
            for (int i = 0; i < numElements; i++)
            {
               addData[i] = data[i];
            }

            delete[] data;
            data = addData;
         }

         numCapacity = addCapacity;
      }
      catch (std::bad_alloc)
      {
         std::cout << "ERROR: Unable to allocate a new buffer for vector";
      }
    }

   data[numElements++] = t;

}

/**************************************************
 * ARRAY ITERATOR
 * An iterator through array
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
   
private:
   T * p;
};



/*******************************************
 * ARRAY :: Assignment
 *******************************************/
template <class T>
vector <T> & vector <T> :: operator = (const vector <T> & rhs) throw (const char*)
{
    assert(rhs.numElements >= 0);

    if (rhs.numElements == 0)
    {
        numCapacity = 0;
        data = NULL;
    }

    try
    {
        data = new T[rhs.numCapacity];
    }
    catch (const std::bad_alloc)
    {
        std::cout << "ERROR: Unable to allocate a new buffer for vector";
    }

    numCapacity = rhs.numCapacity;
    numElements = rhs.numElements;

   for (int i = 0; i < numElements; i++)
      data[i] = rhs.data[i];

   return *this;
}

}; // namespace custom

#endif // VECTOR_H

