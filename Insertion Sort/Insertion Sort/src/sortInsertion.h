/***********************************************************************
 * Header:
 *    INSERTION SORT
 * Summary:
 *    This will contain just the prototype for insertionSortTest(). You may
 *    want to put other class definitions here as well.
 * Author
 *    Davi Neves, Jales Nunes
 ************************************************************************/

#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include "node.h"
using namespace custom;


/***********************************************
 * FindNode: Find previous node
 * Finds where to insert the new node and returns
 * a pointer to the node right before the
 * new node which data equals to t. 
 **********************************************/
template <class T>
Node <T> * findNode (Node <T> * pHead, const T & t)
{
   Node <T> * p = pHead;
   
   //second element and t < first element
   if(p->pNext == NULL || t < p->data)
      return NULL;
   
         
   while(p->pNext != NULL)  // pNext exists
   {
      if(p->pNext->data > t)  //next node data > t
         return p;
      p = p->pNext;
   }
   
   return p;
}


/***********************************************
 * INSERTION SORT
 * Sort the items in the array
 **********************************************/
template <class T>
void sortInsertion(T array[], int num)
{
   Node <T> * pHead = new Node <T> (array[0]);  //creates the first node with data = the first element of the array
   Node <T> * p;
   int j = 0;

   //inserts the second node
   if(array[1] > array[0])
      insert(pHead, array[1], true);  //inserts as second node (back)
   else
      pHead = insert(pHead, array[1]);  //inserts as first node (new head)

   for(int i = 2; i < num; i++)
   {
      //find the place where element i of the array should go in the list
      p = findNode(pHead, array[i]); 
      if(p == NULL)
         pHead = insert(pHead, array[i]); // inserts as first node (new head)

      else
         insert(p, array[i], true); //inserts after the node which p points to
   }
   //copy ordered elements back in the array
   for(p = pHead; p != NULL; p = p->pNext)
   {
      array[j] = p->data; 
      j++;
   }
}

#endif // INSERTION_SORT_H

