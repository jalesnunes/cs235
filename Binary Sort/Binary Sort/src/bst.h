/***********************************************************************
 * Component:
 *    Assignment 09, Binary Search Tree (BST)
 *    Brother Kirby, CS 235
 * Author:
 *    Jales Nunes, Davi Neves
 * Summary:
 *    Create a binary search tree
 ************************************************************************/

#ifndef BST_H
#define BST_H

#include <iostream> // for CIN and COUT
#include <cassert>  // for ASSERTS
using namespace std;

namespace custom
{
/************************************************
 * BST : Binary Search Tree Class
***********************************************/
template <class T>
class BST
{
public:
   // constructors and destructors
   BST() : root(NULL), numElements(0) {}
   BST(const BST<T> &rhs);
   ~BST();

   BST &operator=(const BST<T> &rhs);

   int size() const;
   bool empty() const;
   void clear();
   void insert(const T &t);

   // the BNode class
   class BNode;

   // the various iterator interfaces
   class iterator;
   iterator find(const T &t);
   void erase(iterator &it);

   iterator begin();
   iterator end();

   // the various reverse iterator interfaces
   class reverse_iterator;
   reverse_iterator rbegin();
   reverse_iterator rend();

private:
   BNode *root;
   int numElements;
   void deleteNode(BNode *pNode, bool right) {}
   void deleteBinaryTree(BNode *&pNode);
   void copyBinaryTree(const BNode *pSrc, BNode *&pDest);
};

/**************************************************
 * BST ITERATOR
 * An iterator through BST
 *************************************************/
template <class T>
class BST<T>::iterator
{
public:
   // constructors, destructors, and assignment operator
   iterator()      : p(NULL)      {}
   iterator(BNode * p) : p(p)         {}
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
   iterator & operator ++ ();   

   // postfix increment
   iterator operator ++ (int postfix);
   
   // prefix decrement
   iterator & operator -- ();

   // postfix decrement
   iterator operator -- (int postfix);

   
   friend iterator BST <T> :: find(const T & t);
   friend void BST <T> :: erase(BST <T> :: iterator & it);
   
private:
   BNode * p;
};

/**************************************************
 * BST ITERATOR
 * An iterator through BST
 *************************************************/
template <class T>
class BST<T>::reverse_iterator
{
public:
   // constructors, destructors, and assignment operator
   reverse_iterator()      : p(NULL)      {              }
   reverse_iterator(BNode * p) : p(p)         {              }
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
   reverse_iterator & operator ++ ();   

   // postfix increment
   reverse_iterator operator ++ (int postfix);
   
   // prefix decrement
   reverse_iterator & operator -- ();

   // postfix decrement
   reverse_iterator operator -- (int postfix);
   
private:
   BNode * p;
};

/**************************************************
 * BST reverse_iterator :: INCREMENT PREFIX
 *************************************************/
template <class T>
typename BST<T>::reverse_iterator &BST<T>::reverse_iterator::operator ++ ()
{
   // do nothing if we have nothing
   if (NULL == p)
      return *this;

   // if there is a right node, take it
   if (NULL != p->pRight)
   {
      // go right
      p = p->pRight;

      // jig left - there might be more left-most children
      while (p->pLeft)
         p = p->pLeft;
      return *this;
   }

   // there are no right children, the left are done
   assert(NULL == p->pRight);
   BNode * pSave = p;

   // go up
   p = p->pParent;

   // if the parent is the NULL, we are done!
   if (NULL == p)
      return *this;

   // if we are the left-child, got to the parent.
   if (pSave == p->pLeft)
      return *this;

   // we are the right-child, go up as long as we are the right child!
   while (NULL != p && pSave == p->pRight)
   {
      pSave = p;
      p = p->pParent;
   }

   return *this;
}

/**************************************************
 * BST reverse_iterator :: INCREMENT postfix
 *************************************************/
template <class T>
typename BST <T>::reverse_iterator BST<T>::reverse_iterator :: operator ++ (int postfix)
{
   reverse_iterator tmp(*this);

   // do nothing if we have nothing
   if (NULL == p)
      return tmp;

   // if there is a right node, take it
   if (NULL != p->pRight)
   {
      // go right
      p = p->pRight;

      // jig left - there might be more left-most children
      while (p->pLeft)
         p = p->pLeft;
      return tmp;
   }

   // there are no right children, the left are done
   assert(NULL == p->pRight);
   BNode * pSave = p;

   // go up
   p = p->pParent;

   // if the parent is the NULL, we are done!
   if (NULL == p)
      return tmp;

   // if we are the left-child, got to the parent.
   if (pSave == p->pLeft)
      return tmp;

   // we are the right-child, go up as long as we are the right child!
   while (NULL != p && pSave == p->pRight)
   {
      pSave = p;
      p = p->pParent;
   }

   return tmp;
}
/**************************************************
 * BST reverse_iterator :: DECREMENT PREFIX
 *************************************************/
template <class T>
typename BST <T> :: reverse_iterator & BST <T> :: reverse_iterator :: operator -- ()
{
   // do nothing if we have nothing
   if (NULL == p)
      return *this;

   // if there is a left node, take it
   if (NULL != p->pLeft)
   {
      // go left
      p = p->pLeft;

      // jig right - there might be more right-most children
      while (p->pRight)
         p = p->pRight;
      return *this;
   }

   // there are no left children, the right are done
   assert(NULL == p->pLeft);
   BNode * pSave = p;

   // go up
   p = p->pParent;

   // if the parent is the NULL, we are done!
   if (NULL == p)
      return *this;

   // if we are the right-child, got to the parent.
   if (pSave == p->pRight)
      return *this;

   // we are the left-child, go up as long as we are the left child!
   while (NULL != p && pSave == p->pLeft)
   {
      pSave = p;
      p = p->pParent;
   }

   return *this;
}

/**************************************************
 * BST reverse_iterator :: DECREMENT postfix
 *************************************************/
template <class T>
typename BST <T> :: reverse_iterator BST <T> :: reverse_iterator :: operator -- (int postfix)
{
   reverse_iterator tmp(*this);

   // do nothing if we have nothing
   if (NULL == p)
      return tmp;

   // if there is a left node, take it
   if (NULL != p->pLeft)
   {
      // go left
      p = p->pLeft;

      // jig right - there might be more right-most children
      while (p->pRight)
         p = p->pRight;
      return tmp;
   }

   // there are no left children, the right are done
   assert(NULL == p->pLeft);
   BNode * pSave = p;

   // go up
   p = p->pParent;

   // if the parent is the NULL, we are done!
   if (NULL == p)
      return tmp;

   // if we are the right-child, got to the parent.
   if (pSave == p->pRight)
      return tmp;

   // we are the left-child, go up as long as we are the left child!
   while (NULL != p && pSave == p->pLeft)
   {
      pSave = p;
      p = p->pParent;
   }

   return tmp;
}


/**************************************************
 * BST ITERATOR :: INCREMENT PREFIX
 *************************************************/
template <class T>
typename BST <T> :: iterator & BST <T> :: iterator :: operator ++ ()
{
   // do nothing if we have nothing
   if (NULL == p)
      return *this;

   // if there is a right node, take it
   if (NULL != p->pRight)
   {
      // go right
      p = p->pRight;

      // jig left - there might be more left-most children
      while (p->pLeft)
         p = p->pLeft;
      return *this;
   }

   // there are no right children, the left are done
   assert(NULL == p->pRight);
   BNode * pSave = p;

   // go up
   p = p->pParent;

   // if the parent is the NULL, we are done!
   if (NULL == p)
      return *this;

   // if we are the left-child, got to the parent.
   if (pSave == p->pLeft)
      return *this;

   // we are the right-child, go up as long as we are the right child!
   while (NULL != p && pSave == p->pRight)
   {
      pSave = p;
      p = p->pParent;
   }

   return *this;
}
/**************************************************
 * BST ITERATOR :: INCREMENT PREFIX
 *************************************************/
template <class T>
typename BST <T> :: iterator BST <T> :: iterator :: operator ++ (int postfix)
{
   iterator tmp(*this);

   // do nothing if we have nothing
   if (NULL == p)
      return tmp;

   // if there is a right node, take it
   if (NULL != p->pRight)
   {
      // go right
      p = p->pRight;

      // jig left - there might be more left-most children
      while (p->pLeft)
         p = p->pLeft;
      return tmp;
   }

   // there are no right children, the left are done
   assert(NULL == p->pRight);
   BNode * pSave = p;

   // go up
   p = p->pParent;

   // if the parent is the NULL, we are done!
   if (NULL == p)
      return tmp;

   // if we are the left-child, got to the parent.
   if (pSave == p->pLeft)
      return tmp;

   // we are the right-child, go up as long as we are the right child!
   while (NULL != p && pSave == p->pRight)
   {
      pSave = p;
      p = p->pParent;
   }

   return tmp;
}
/**************************************************
 * BST ITERATOR :: DECREMENT PREFIX
 *     advance by one. 
 * Author:      Br. Helfrich
 * Performance: O(log n) though O(1) in the common case
 *************************************************/
template <class T>
typename BST <T> :: iterator & BST <T> :: iterator :: operator -- ()
{
   // do nothing if we have nothing
   if (NULL == p)
      return *this;

   // if there is a left node, take it
   if (NULL != p->pLeft)
   {
      // go left
      p = p->pLeft;

      // jig right - there might be more right-most children
      while (p->pRight)
         p = p->pRight;
      return *this;
   }

   // there are no left children, the right are done
   assert(NULL == p->pLeft);
   BNode * pSave = p;

   // go up
   p = p->pParent;

   // if the parent is the NULL, we are done!
   if (NULL == p)
      return *this;

   // if we are the right-child, got to the parent.
   if (pSave == p->pRight)
      return *this;

   // we are the left-child, go up as long as we are the left child!
   while (NULL != p && pSave == p->pLeft)
   {
      pSave = p;
      p = p->pParent;
   }

   return *this;
}
/**************************************************
 * BST ITERATOR :: DECREMENT postfix
 *************************************************/
template <class T>
typename BST <T> :: iterator BST <T> :: iterator :: operator -- (int postfix)
{
   iterator tmp(*this);

   // do nothing if we have nothing
   if (NULL == p)
      return tmp;

   // if there is a left node, take it
   if (NULL != p->pLeft)
   {
      // go left
      p = p->pLeft;

      // jig right - there might be more right-most children
      while (p->pRight)
         p = p->pRight;
      return tmp;
   }

   // there are no left children, the right are done
   assert(NULL == p->pLeft);
   BNode * pSave = p;

   // go up
   p = p->pParent;

   // if the parent is the NULL, we are done!
   if (NULL == p)
      return tmp;

   // if we are the right-child, got to the parent.
   if (pSave == p->pRight)
      return tmp;

   // we are the left-child, go up as long as we are the left child!
   while (NULL != p && pSave == p->pLeft)
   {
      pSave = p;
      p = p->pParent;
   }

   return tmp;
}

/**********************************************
 * BST : erase
 **********************************************/
template <class T>
void BST <T> :: erase(BST <T> :: iterator & it)
{
   //no children
   if (it.p->pRight == NULL && it.p->pLeft == NULL)
   {
      if(it.p->pParent != NULL && it.p->pParent->pRight == it.p)
         it.p->pParent->pRight = NULL;
      if(it.p->pParent != NULL && it.p->pParent->pLeft == it.p)
         it.p->pParent->pLeft = NULL;
   }
   
   //one child
   else if(it.p->pRight == NULL && it.p->pLeft != NULL)
   {
      it.p->pLeft->pParent = it.p->pParent;
      if(it.p->pParent != NULL && it.p->pParent->pRight == it.p)
         it.p->pParent->pRight = it.p->pLeft;
      if(it.p->pParent != NULL && it.p->pParent->pLeft == it.p)
         it.p->pParent->pLeft = it.p->pLeft;
   }
   else if(it.p->pLeft == NULL && it.p->pRight != NULL)
   {
      it.p->pRight->pParent = it.p->pParent;
      if(it.p->pParent != NULL && it.p->pParent->pRight == it.p)
         it.p->pParent->pRight = it.p->pRight;
      if(it.p->pParent != NULL && it.p->pParent->pLeft == it.p)
         it.p->pParent->pLeft = it.p->pRight;
   }

   //two children
   else if(it.p->pLeft != NULL && it.p->pRight != NULL)
   {
      if(it.p->pRight->pLeft)
      {
         BNode * p = it.p->pRight;
         BNode * pNew = it.p->pRight->pLeft;  

         for(; pNew->pLeft; p = pNew, pNew = pNew->pLeft);
      
         p->pLeft = pNew->pRight;
         if(p->pLeft)
            p->pLeft->pParent = p;
         pNew->pParent = it.p->pParent;
         if(it.p->pParent != NULL && it.p->pParent->pRight == it.p)
            it.p->pParent->pRight = pNew;
         if(it.p->pParent != NULL && it.p->pParent->pLeft == it.p)
            it.p->pParent->pLeft = pNew;
      
         it.p->pParent = NULL;
   
         pNew->pLeft = it.p->pLeft;
         it.p->pLeft->pParent = pNew;

         pNew->pRight = it.p->pRight;
         it.p->pRight->pParent = pNew;
         if(root == it.p)
            root = pNew;
      }
      else
      {
         it.p->pRight->pLeft = it.p->pLeft;
         
         if(it.p->pParent != NULL && it.p->pParent->pRight == it.p)
            it.p->pParent->pRight = it.p->pRight;
         if(it.p->pParent != NULL && it.p->pParent->pLeft == it.p)
            it.p->pParent->pLeft = it.p->pRight;

         if(root == it.p)
            root = it.p->pRight;
            
         it.p->pRight = NULL;
      }
   }
     
   delete it.p;
   
   numElements--;
}

/*******************************************
* BST - iterator find
* element to be found from the binary 
* search tree
*******************************************/
template <class T>
typename BST<T>:: iterator BST<T> :: find(const T &t)
{
   BST <T> :: iterator it;

   for (it = begin(); it != end(); ++it)
      if(it.p->data == t)
         return it;

   return it;
}

/*******************************************
* BST - insert
* element to be inserted into the binary 
* search tree
*******************************************/
template <class T>
void BST <T> :: insert(const T & t)
{
   BNode * pNew;
   BNode * p;
   bool left = true;
   bool right = true;

   try
   {
      pNew = new BNode (t);
   }
   catch (std::bad_alloc)
   {
      throw "ERROR: Unable to allocate a node";
   }

   pNew->pLeft = NULL;
   pNew->pRight = NULL;
   
   if(root == NULL)
   {
      pNew->pParent = NULL;
      root = pNew;
   }
   else
   {
      p = root;
      while(left && right)
      {
         if(t < p->data)
         {
            if(p->pLeft != NULL)
               p = p->pLeft;
            else
               left = false;
         }
         else
         {
            if(p->pRight != NULL)
               p = p->pRight;
            else
               right = false;
         }
      }
      if(left == false)
         p->pLeft = pNew;
      else
         p->pRight = pNew;

      pNew->pParent = p;
   }

   this->numElements = this->numElements + 1;
}

/*******************************************
* BST - iterator begin
* return the leftmost element in the BST
*******************************************/
template <class T>
typename BST<T>::iterator BST<T>::begin()
{
   BNode *pBNode = root;

   if (root == NULL)
      return iterator(root);
   else
   {
      while (pBNode->pLeft)
         pBNode = pBNode->pLeft;
   }

   return iterator(pBNode);
}

/*******************************************
* BST - iterator end
* return value is an iterator referring to
* no element in the BST. 
*******************************************/
template <class T>
typename BST<T>::iterator BST<T>::end()
{
   return iterator(NULL);
}

/*******************************************
* BST - iterator rbegin
* return value is an iterator referring to
* the rightmost element in the BST
*******************************************/
template <class T>
typename BST<T>::reverse_iterator BST<T>::rbegin()
{
   BNode *pBNode = root;

   if (root == NULL)
      return reverse_iterator(root);
   else
   {
      while (pBNode->pRight)
         pBNode = pBNode->pRight;
   }

   return reverse_iterator(pBNode);
}

/*******************************************
* BST - iterator rend
* return value is an iterator referring to
* no element in the BST
*******************************************/
template <class T>
typename BST<T>::reverse_iterator BST<T>::rend()
{
   return reverse_iterator(NULL);
}

/*******************************************
* BST - copyBinaryTree
* copy a whole tree
*******************************************/
template <class T>
void BST <T> :: copyBinaryTree (const BNode * pSrc, BNode * & pDest)
{
   if(pSrc == NULL)
      return;
      
   // attempt to allocate
   try
   {
      pDest = new BNode (pSrc->data);
   }
   catch (std::bad_alloc)
   {
      throw "ERROR: Unable to allocate a node";
   }

   copyBinaryTree(pSrc->pLeft, pDest->pLeft);
   if(pDest->pLeft != NULL)
      pDest->pLeft->pParent = pDest;
 
   copyBinaryTree(pSrc->pRight, pDest->pRight);
   if(pDest->pRight != NULL)
      pDest->pRight->pParent = pDest;
}

/*******************************************
* BST - assignment operator
* Copy one binary search tree onto another
*******************************************/
template <class T>
BST<T> &BST<T>::operator = (const BST<T> &rhs)
{
   this->clear();
   
   assert(rhs.numElements >= 0);
      
   // do nothing if there is nothing to do
   if (rhs.numElements == 0)
   {
      this->root = NULL;
      this->numElements = 0;
      return *this;
   }

   copyBinaryTree(rhs.root, root);
   
   this->numElements = rhs.numElements;

   return *this;
}

/*******************************************
* BST - BST (copy constructor)
* 
*******************************************/
template <class T>
BST<T>:: BST(const BST<T> &rhs)
{
   assert(rhs.numElements >= 0);
   
   // do nothing if there is nothing to do
   if (rhs.numElements == 0)
   {
      this->root = NULL;
      this->numElements = 0;
      return;
   }
   
   copyBinaryTree(rhs.root, root);
   
   this->numElements = rhs.numElements;
}

/*******************************************
* BST - ~BST(desconstructor)
* Delete all the elements in the binary tree
*******************************************/
template <class T>
BST<T>::~BST()
{
   clear();
}


/*******************************************
* BST - size
* Return the number of nodes in the binary 
* search tree
*******************************************/
template <class T>
int BST<T>::size() const
{
   return numElements;
}

/*******************************************
* BST - empty
*
*******************************************/
template <class T>
bool BST<T>::empty() const
{
   if(this->numElements == 0) 
      return true;
   else
      return false;
}

/*******************************************
* BST - clear
* Delete all the elements in the binary 
* search tree
*******************************************/
template <class T>
void BST<T>::clear()
{
   deleteBinaryTree(root);
}

/*******************************************
* BST - deleteBinaryTree
* delete whole tree
*******************************************/
template <class T>
void BST<T>::deleteBinaryTree(BNode * & pNode)
{
   if (pNode == NULL)
      return;
   deleteBinaryTree(pNode->pLeft);
   deleteBinaryTree(pNode->pRight);
   delete pNode;
   pNode = NULL;
   numElements = 0;
}


/************************************************
 * NODE
 * A class that holds stuff
 ***********************************************/
template <class T>
class BST <T> :: BNode
{
public:
   // constructors and destructors
   BNode();
   BNode(const T & t);

   T data;
   BNode * pLeft;
   BNode * pRight;
   BNode * pParent;   
};

/**********************************************
 * BNode : DEFAULT CONSTRUCTOR
 **********************************************/
template <class T>
BST <T> :: BNode :: BNode() 
{
   this->pLeft = NULL;
   this->pRight = NULL;
   this->pParent = NULL;
}
/**********************************************
 * BNode : NON-DEFAULT CONSTRUCTOR
 * Preallocate the array to "capacity"
 **********************************************/
template <class T>
BST <T> :: BNode :: BNode(const T & t) 
{
   this->data = t;
   this->pLeft = NULL;
   this->pRight = NULL;
   this->pParent = NULL;
}

}; // namespace custom

#endif // BST_H
