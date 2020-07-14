/***********************************************************************
 * Header:
 *    BNode
 * Summary:
 *    This program will implement the Binary Tree Class
 * Author:
 *    Davi Neves, Jales Nunes
 *
 ************************************************************************/

#ifndef BNODE_H
#define BNODE_H

#include <cassert>  // because I am paranoid
#include <iostream> // for CIN and COUT
using namespace std;


// a little helper macro to write debug code
#ifdef NDEBUG
#define Debug(statement)
#else
#define Debug(statement) statement
#endif // !NDEBUG

/************************************************
 * BNODE
 * Class Binary Node Tree
 ***********************************************/
template <class T>
class BNode
{
public:
   // constructors and destructors
   BNode();
   BNode(const T & t);

   T data;
   BNode <T> * pLeft;
   BNode <T> * pRight;
   BNode <T> * pParent;
};

/**********************************************
 * BNode : DEFAULT CONSTRUCTOR
 **********************************************/
template <class T>
BNode <T> :: BNode() 
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
BNode <T> :: BNode(const T & t) 
{
   this->data = t;
   this->pLeft = NULL;
   this->pRight = NULL;
   this->pParent = NULL;
}

/**********************************************
 * BNode : DeleteBTree
 **********************************************/
template <class T>
void deleteBTree (BNode <T> * & pNode)
{
   if(pNode == NULL)
      return;
   deleteBTree(pNode->pLeft);
   deleteBTree(pNode->pRight);
   delete pNode;
   pNode = NULL;
}

/**********************************************
 * BNode : AddLeft
 **********************************************/
template <class T>
void addLeft (BNode <T> * pNode, BNode <T> * pAdd)
{
   if(pAdd != NULL)
      pAdd->pParent = pNode;
   pNode->pLeft = pAdd;
}

/**********************************************
 * BNode : addRight
 **********************************************/
template <class T>
void addRight (BNode <T> * pNode, BNode <T> * pAdd)
{
   if(pAdd != NULL)
      pAdd->pParent = pNode;
   pNode->pRight = pAdd;
}

/**********************************************
 * BNode : addLeft
 **********************************************/
template <class T>
void addLeft (BNode <T> * pNode, const T & t)
{
   BNode <T> * pAdd = new BNode <T> (t);
   
   pAdd->pParent = pNode;
   pNode->pLeft = pAdd;
}

/**********************************************
 * BNode : addRight
 **********************************************/
template <class T>
void addRight (BNode <T> * pNode, const T & t)
{
   BNode <T> * pAdd = new BNode <T> (t);
   
   pAdd->pParent = pNode;
   pNode->pRight = pAdd;
}

/**********************************************
 * BNode : sizeBTree 
 * Size of Binary Tree
 **********************************************/
template <class T>
int sizeBTree (const BNode <T> * pRoot)
{
   if(pRoot == NULL)
      return 0;
   else
      return sizeBTree(pRoot->pLeft) + 1 + sizeBTree(pRoot->pRight);
}

/**********************************************
 * BNode : CopyTree
 **********************************************/
template <class T>
BNode <T> * copyBTree (const BNode <T> * pSrc)
{
   if(pSrc == NULL)
      return 0;
   
   BNode <T> * pDest = new BNode <T> (pSrc->data);
   
   pDest->pLeft = copyBTree(pSrc->pLeft);
   if(pDest->pLeft != NULL)
      pDest->pLeft->pParent = pDest;
      
   pDest->pRight = copyBTree(pSrc->pRight);
   if(pDest->pRight != NULL)
      pDest->pRight->pParent = pDest;   
   
   return pDest;
}

/*****************************************
 * BTree :: DISPLAY
 * Display the contents of the list forwards
 ****************************************/
template <class T>
ostream & operator << (ostream & out, const BNode <T> * pHead)
{
   if(pHead == NULL)
      return out;

   out << pHead->pLeft;
   out << pHead->data << " ";
   out << pHead->pRight;

   return out;   
}


#endif // BNODE_H


