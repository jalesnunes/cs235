/***********************************************************************
* Program:
*    Assignment 06, Linked List
*    Brother Kirby, CS 235
* Author:
*    Jales Nunes, Davi Neves
* Summary:
*    This program defines the Class Node.
************************************************************************/

#ifndef NODE_H
#define NODE_H
#include <cassert>  // because I am paranoid
#include <iostream>        // for CIN and COUT
using namespace std;

namespace custom
{

/************************************************
 * NODE
 * A class that holds stuff
 ***********************************************/
template <class T>
class Node
{
public:
   T data;
   Node <T> * pNext;
   Node <T> * pPrev;

   // constructors
    Node();
    Node(const T& t);
};

/*******************************************
* NODE - insert
* This is how elements are added to a 
* linked list.
*******************************************/
template <class T>
Node <T>* insert(Node <T>* pCurrent, const T& t, bool after = false)
{
   Node <T>* pNew = new Node <T>(t); //new node

   if (pCurrent != NULL && after == false)
   {
      //Changing pointer in order to keep a list
      pNew->pNext = pCurrent;
	    pNew->pPrev = pCurrent->pPrev;
	    pCurrent->pPrev = pNew;
       if (pNew->pPrev)
       {
          pNew->pPrev->pNext = pNew;
       }
   }
   else if (pCurrent != NULL && after == true)
   {
      //Changing pointer in order to keep a list
      pNew->pNext = pCurrent->pNext;
      pNew->pPrev = pCurrent;

      if (pCurrent->pNext)
      {
         pCurrent->pNext->pPrev = pNew;
      }
  	   pCurrent->pNext = pNew;

   }
   
   return pNew; //returning a new node
}

/*******************************************
* NODE - find
* This is how elements are found to a
* linked list.
*******************************************/
template <class T> 
Node <T>* find(Node <T>* pHead, const T& t)
{
   Node <T>* p;
   //Going through a list
   for (p = pHead; p != NULL; p = p->pNext)
   {
      //condition if data equal to element 
      if (p->data == t)
      {
         return p;
      }
   }
    return NULL; 
}

/*******************************************
* NODE - clear
* Delete an entire list..
*******************************************/
template <class T> 
void freeData(Node <T>*& pHead)
{
   Node <T>* pDelete;

   while (pHead != NULL)
   {
      pDelete = pHead;
      pHead = pHead->pNext;
      delete pDelete;
   }
}

/*******************************************
* NODE - copy
* makes a copy of each and every node in 
* the source linked list into a new 
* linked list.
*******************************************/
template <class T> 
Node <T>* copy(const Node <T>* pSource)
{
   Node <T>* pDestination = new Node <T>(pSource->data); // creating new node
   const Node <T>* pSrc;
   Node <T>* pDes = pDestination;

   for (pSrc = pSource->pNext; pSrc != NULL; pSrc = pSrc->pNext)
   {
      pDes = insert(pDes, pSrc->data, true);
   }

   return pDestination;
}

/*******************************************
* NODE - remove
* Delete a single node from a linked list
*******************************************/
template <class T> 
Node <T>* remove(const Node <T>* pRemove)
{
   Node <T>* pReturn = NULL;
   if (pRemove == NULL)
   {
      return pReturn;
   }

   if (pRemove->pPrev)
   {
      pRemove->pPrev->pNext = pRemove->pNext;
   }

   if (pRemove->pNext)
   {
      pRemove->pNext->pPrev = pRemove->pPrev;
   }

   if (pRemove->pPrev)
   {
      pReturn = pRemove->pPrev;
   }
   else
   {
      pReturn = pRemove->pNext;
   }

   delete pRemove;

   return pReturn;
}

/*****************************************
 * DISPLAY
 ****************************************/
template <class T>
ostream & operator << (ostream & out, const Node <T> * pSource)
{  
   const Node <T> * p = pSource;
   
   if(p != NULL)
   {
      out << p->data;
   
      for(p = pSource->pNext; p; p = p->pNext)
         out << ", " << p->data;
   }

   return out;
}

/********************************************
* CONSTRUCTOR
*******************************************/
template <class T>
Node <T> ::Node()
{
   this->pNext = NULL;
   this->pPrev = NULL;
}

/********************************************
* CONSTRUCTOR: NON-DEFAULT
*******************************************/
template <class T>
Node <T> ::Node(const T& t)
{
   this->data = t;
   this->pNext = NULL;
   this->pPrev = NULL;
}

}; // namespace custom

#endif /* NODE_H */
