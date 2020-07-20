/***********************************************************************
* Program:
*    Assignment 02, Stack
*    Brother Kirby, CS 235
* Author:
*    Jales Nunes, Davi Neves
* Summary: 
*    This is a program to difine the Stack class.  
************************************************************************/


#ifndef STACK_H
#define STACK_H

#include <cassert>  // because I am paranoid


namespace custom
{

/************************************************
 * STACK
 * A class that holds an array of any size and type
 ***********************************************/
template <class T>
class stack
{
public:
   // constructors and destructors
   stack();
   stack(int numCapacity);
   stack(const stack <T> & rhs);
  ~stack()
   {
      if(capacity() != 0)
      { 
         delete [] data;
         data = NULL;
      }
   }

   stack & operator = (const stack & rhs); 
   
   // standard container interfaces
   // array treats size and max_size the same

   int  size()     const { return numElements;          }
   int  capacity() const { return numCapacity;	 	}
   bool empty()    const;

   void clear();
   void push(const T t);

   void pop();
   T top();


private:
   T * data;              // dynamically allocated array of T
   int numElements;       // number of elements
   int numCapacity;       // the capacity

   void resize (int numCapacity);

};                     

/**********************************************
 * STACK : Top
 **********************************************/
template <class T>
T stack <T> :: top()
{
   if (empty())
      throw "ERROR: Unable to reference the element from an empty Stack";
   else
      return data[size() -1];
}

/**********************************************
 * STACK : Pop   Not sure!
 **********************************************/
template <class T>
void stack <T> :: pop()
{
   if(empty() == false)
      --numElements;
}

/**********************************************
 * STACK : Push
 **********************************************/
template <class T>
void stack <T> :: push(const T t)
{
   if(capacity() == 0)
      resize(1);
   else if(capacity() == size())
      resize(capacity() * 2);

   data[numElements++] = t;
}


/**********************************************
 * STACK : Clear
 **********************************************/
template <class T>
void stack <T> :: clear()
{
   for (int i = 0; i < size(); i++)
      data[i] = 0;

   this->numElements = 0; 
}

/**********************************************
 * STACK : Empty
 **********************************************/
template <class T>
bool stack <T> :: empty() const
{
   if(this->numElements == 0) 
      return true;
   else
      return false;
}

/**********************************************
 * STACK : Resize
 **********************************************/
template <class T>
void stack <T> :: resize (int numCapacity)
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
 * STACK :: Assignment =
 *******************************************/
template <class T>
stack <T> & stack <T> :: operator = (const stack <T> & rhs)
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
 * STACK :: COPY CONSTRUCTOR
 *******************************************/
template <class T>
stack <T> :: stack(const stack <T> & rhs) 
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
 * STACK : NON-DEFAULT CONSTRUCTOR
 * Preallocate the array to "capacity"
 **********************************************/
template <class T>
stack <T> :: stack(int numCapacity) 
{
   assert(numCapacity >= 0);

if (numCapacity == 0)
   {
      this->data = NULL;
      this->numElements = 0;
      this->numCapacity = 0;
      return;
   }

   // attempt to allocate
   try
   {
      data = new T[numCapacity];
   }
   catch (std::bad_alloc)
   {
      throw "ERROR: Unable to allocate buffer";
   }

   // copy over the stuff
   this->numElements = 0;
   this->numCapacity = numCapacity;

}
   
/**********************************************
 * STACK : DEFAULT CONSTRUCTOR
 **********************************************/
template <class T>
stack <T> :: stack() 
{
   this->data = NULL;
   this->numElements = 0;
   this->numCapacity = 0;
}


}; // namespace custom

#endif // STACK_H

