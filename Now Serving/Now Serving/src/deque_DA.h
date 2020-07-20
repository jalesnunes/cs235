/***********************************************************************
* Program:
*    Assignment 04, Deque
*    Brother Kirby, CS 235
* Author:
*    Jales Nunes, Davi Neves
* Summary:
*    This program defines the Class Deque.
************************************************************************/

#ifndef DEQUE_H
#define DEQUE_H
#include <assert.h>


using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostream;
using std::ios;

namespace custom
{

/************************************************
* Queue - FIFO
* class that holds an array of any size and type
***********************************************/
template <class T>
class deque
{
public:
   // constructors and destructors
   deque() : data(NULL), numCapacity(0), iFront(0), iBack(-1) {}
   deque(int numCapacity);
   deque(deque<T>& rhs);
   ~deque()
   {
      if (numCapacity != 0)
      {
         delete[] data;
         data = NULL;
      }
   }

   deque<T>& operator=(deque<T>& rhs);

   // standard container interfaces
   int size() { return iBack - iFront + 1; }
   bool empty();

   void clear();
   void push_front(const T& element);
   void push_back(const T& element);
   void pop_front();
   void pop_back();

   T& front();
   T& back();

private:
   T* data;         // dynamically allocated array of T
   int numCapacity; // the capacity
   int iFront;
   int iBack;

   void resize(int newCapacity);
   int iFrontNormalize() { return iNormalize(iFront);    }
   int iBackNormalize()  { return iNormalize(iBack);     }
   int capacity()        { return numCapacity;           }
   int iNormalize(int i);
};


template <class T>
int deque<T>::iNormalize(int i)
{
   while(i < 0)
      i = i + capacity();

   return i % capacity();
}

/**********************************************
* DEQUE : front access oldest data add
**********************************************/
template <class T>
T& deque<T>::front()
{
   if (empty() == true)
   {
      throw "ERROR: unable to access data from an empty deque";
   }
   else
   {
      return data[iFrontNormalize()];
   }
}

/**********************************************
* DEQUE : back access newest data add
**********************************************/
template <class T>
T& deque<T>::back()
{
   if (empty() == true)
   {
      throw "ERROR: unable to access data from an empty deque";
   }
   else
   {
      return data[iBackNormalize()];
   }
}

/**********************************************
* DEQUE : Pop oldest data in the deque
**********************************************/
template <class T>
void deque<T>::pop_front()
{
   if (!empty())
   {
      iFront++;
   }
}

/**********************************************
* DEQUE : Pop oldest data in the deque
**********************************************/
template <class T>
void deque<T>::pop_back()
{
   if (!empty())
   {
      iBack--;
   }
}

/**********************************************
* DEQUE : Push_front put data at the front
*         of deque
**********************************************/
template <class T>
void deque<T>::push_front(const T& element)
{
   if (capacity() == 0)
   {
      resize(1);
   }
   else if (size() == capacity())
   {
      resize(capacity() * 2);
   }

   iFront--;
   data[iFrontNormalize()] = element;
}

/**********************************************
* DEQUE : Push_back put data at the end
*         of deque
**********************************************/
template <class T>
void deque<T>::push_back(const T& element)
{
   if (capacity() == 0)
   {
      resize(1);
   }
   else if (size() == capacity())
   {
      resize(capacity() * 2);
   }

   iBack++;
   data[iBackNormalize()] = element;
}

/**********************************************
* DEQUE : Clear the whole deque
**********************************************/
template <class T>
void deque<T>::clear()
{
   iFront = 0;
   iBack = -1;
}

/**********************************************
* DEQUE : Empty
**********************************************/
template <class T>
bool deque<T>::empty()
{
   if ((iBack + 1) == iFront)
   {
      return true;
   }
   else
   {
      return false;
   }
}

/**********************************************
* DEQUE : Resize the deque capacity
**********************************************/
template <class T>
void deque<T>::resize(int newCapacity)
{
   int iSize = size();
   int i = iFront;
   
   // do nothing if there is nothing to do
   if (newCapacity < numCapacity)
   {
      return;
   }

   // attempt to allocate
   try
   {
      T* dataNew = new T[newCapacity];

      for (int iNew = 0; iNew < iSize;  iNew++)
      {
         dataNew[iNew] = data[iNormalize(i)];
         i++;
      }

      data = dataNew;

      numCapacity = newCapacity;
      iFront = 0;
      iBack = iSize - 1;
   }

   catch (std::bad_alloc)
   {
      throw "ERROR: Unable to allocate new buffer for queue";
   }
}

/*******************************************
* DEQUE :: Assignment =
*******************************************/
template <class T>
deque<T>& deque<T>::operator=(deque<T>& rhs)
{
   clear();

   if (capacity() < rhs.size())
   {
       resize(rhs.size());
   }

   // copy over the capacity
   numCapacity = rhs.numCapacity;

   int i = rhs.iFront;
   for (int j = 0; j < rhs.size();  j++)
   {
      push_back(rhs.data[rhs.iNormalize(i)]);
      i++;
   }

   return *this;
}

/*******************************************
* DEQUE :: COPY CONSTRUCTOR
*******************************************/
template <class T>
deque<T>::deque(deque<T>& rhs)
{
   clear();

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
   numCapacity = rhs.size();

   // copy the items over one at a time using the assignment operator
   int i = rhs.iFront;
   for (int j = 0; j < rhs.size();  j++)
   {
      push_back(rhs.data[rhs.iNormalize(i)]);
      i++;
   }
}

/********************************************
* CONSTRUCTOR: NON-DEFAULT
*******************************************/
template <class T>
deque<T>::deque(int numCapacity)
{
   clear();

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





} // namespace custom
#endif /* DEQUE_H */




