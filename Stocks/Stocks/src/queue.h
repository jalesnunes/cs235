/***********************************************************************
* Program:
*    Assignment 03, Queue
*    Brother Kirby, CS 235
* Author:
*    Jales Nunes, Davi Neves
* Summary: 
*    This program defines the Class Queue.  
************************************************************************/

#ifndef QUEUE_H
#define QUEUE_H
#include <assert.h>

namespace custom
{
   
/************************************************
* Queue - FIFO
* class that holds an array of any size and type
***********************************************/
template <class T>
class queue
{
public:
   // constructors and destructors
   queue() : data(NULL), numCapacity(0), numPop(0), numPush(0) {}
   queue(int numCapacity);
   queue(queue<T>& rhs);
   ~queue()
   {
      if (numCapacity != 0)
      {
         delete[] data;
         data = NULL;
      }
   }

   queue<T> & operator = (queue<T>& rhs);

   // standard container interfaces
   int size() { return numPush - numPop; }
   bool empty();

   void clear();
   void push(const T& element);
   void pop();

   T& front();
   T& back();

private:
   T* data;         // dynamically allocated array of T
   int numCapacity; // the capacity
   int numPush;
   int numPop;

   void resize(int newCapacity);
   int iHead() { return numPop % numCapacity; }
   int iTail() { return (numPush - 1) % numCapacity; }
};

/**********************************************
 * QUEUE : front access oldest data add
 **********************************************/
template <class T>
T& queue<T> :: front()
{
   if (empty() == true)
   {
      throw "ERROR: attempting to access an element in an empty queue";
   }
   else
   {
      return data[iHead()];
   }
}

/**********************************************
 * QUEUE : back access newest data add
 **********************************************/
template <class T>
T& queue<T> :: back()
{
   if (empty() == true)
   {
      throw "ERROR: attempting to access an element in an empty queue";
   }
   else
   {
      return data[iTail()];
   }
}

/**********************************************
 * QUEUE : Pop oldest data in the queue
 **********************************************/
template <class T>
void queue <T> :: pop()
{
   if (!empty())
   {
      numPop++;
   }  
}

/**********************************************
 * QUEUE : Push put data at the end of queue
 **********************************************/
template<class T>
void queue<T> :: push(const T& element)
{
   if (numCapacity == 0)
   {
      resize(1);
   }
   else if (numPush == numCapacity)
   {
      resize(numCapacity *= 2);
   }
   
   numPush++;
   data[iTail()] = element;
}

/**********************************************
 * QUEUE : Clear the whole queue
 **********************************************/
template <class T>
void queue <T> :: clear()
{
   numPush = 0;
   numPop = 0;
}

/**********************************************
 * QUEUE : Empty 
 **********************************************/
template<class T>
bool queue<T> :: empty()
{
   if (numPush == numPop)
   {
      return true;
   }
   else
   {
      return false;
   }
}

/**********************************************
 * QUEUE : Resize the queue capacity
 **********************************************/
template<class T>
void queue<T> :: resize(int newCapacity)
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

      for (int i = numPop; i < numPush; i++) 
      {
         dataNew[i] = data[i];
      }
		
      data = dataNew;
      numCapacity = newCapacity;
   }
   catch (std::bad_alloc) 
   {
      throw "ERROR: Unable to allocate new buffer for queue";
   }
}

/*******************************************
 * QUEUE :: Assignment =
 *******************************************/
template <class T>
queue<T>& queue <T> :: operator = (queue<T>& rhs)
{
   numPop = 0;
   numPush = 0;

   if (numCapacity < rhs.size())
   {
      resize(rhs.size());
   }
   numCapacity = rhs.size();

   for (int i = rhs.numPop; i < rhs.numPush; i++)
   {
      push(rhs.data[i % rhs.numCapacity]);
   }

   return *this;
}

/*******************************************
 * QUEUE :: COPY CONSTRUCTOR
 *******************************************/
template<class T>
queue<T> :: queue(queue<T>& rhs)
{
   numPush = 0;
   numPop = 0;
   
   if (numCapacity < rhs.size())
   {
      resize(rhs.size());
   }
   
   // attempt to allocate
   try
   {
      data = new T[rhs.numCapacity];
   }
   catch (std::bad_alloc) 
   {
      throw "ERROR: Unable to allocate a new buffer for queue";
   }
   
   // copy over the capacity
   numCapacity = rhs.numCapacity;

   // copy the items over one at a time using the assignment operator
   for (int i = rhs.numPop; i < rhs.numPush; i++)
   {
      push(rhs.data[i % rhs.numCapacity]);
   }
}

/********************************************
 * CONSTRUCTOR: NON-DEFAULT
 *******************************************/
template<class T>
queue<T>::queue(int numCapacity)
{
   numPush = 0;
   numPop = 0;
   this->numCapacity = numCapacity;
   data = NULL;
 
   // attempt to allocate
   try
   {
      data = new T[numCapacity];
   }
   catch (std::bad_alloc)
   {
      throw "ERROR: Unable to allocate a new buffer for queue";
   }
}

}
#endif /* QUEUE_H */
