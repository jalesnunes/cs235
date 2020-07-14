/***********************************************************************
 * Header:
 *    FIBONACCI
 * Summary:
 *    This will contain just the prototype for fibonacci(). You may
 *    want to put other class definitions here as well.
 * Author
 *     Jales Nunes, Davi Neves
 ************************************************************************/

#ifndef WHOLENUMBER_H
#define WHOLENUMBER_H

#include <iostream>     // for CIN and COUT
#include <cassert>      // for ASSERT
#include "list.h"       // your List class should be in list.h

#include <math.h> 
using namespace custom;

// a little helper macro to write debug code
#ifdef NDEBUG
#define Debug(statement)
#else
#define Debug(statement) statement
#endif // !NDEBUG


/************************************************
 * WHOLE NUMBER 
 * A class that holds whole numbers of any size
 ***********************************************/
class WholeNumber
{
public:
   // constructors
   WholeNumber() {  }
   WholeNumber(const WholeNumber & rhs) { this->digits = rhs.digits;  }
   WholeNumber(const int num);

   //Operators
   WholeNumber & operator = (const WholeNumber & rhs)
   {
      this->digits = rhs.digits;
      return *this;
   }

   WholeNumber & operator += (WholeNumber & rhs)
   {
      typename list <int> :: reverse_iterator itThis;
      typename list <int> :: reverse_iterator itRhs;
      itThis = digits.rbegin();
      itRhs = rhs.digits.rbegin();
      int s, s1, s2 = 0;
      WholeNumber sum;
      
      while(itThis != digits.rend() && itRhs != digits.rend())
      {
         s = *itThis + *itRhs + s2;
         s1 = s % 1000;
         s2 = s / 1000;
         sum.digits.push_front(s1);
         ++itThis;
         ++itRhs;
      }
      
      if(itThis == digits.rend())
      {
         while(itRhs != digits.rend())
         {
            s = *itRhs + s2;
            s1 = s % 1000;
            s2 = s / 1000;
            sum.digits.push_front(s1);
            ++itRhs;
         }
      }
      else if(itRhs == digits.rend())
      {
         while(itThis != digits.rend())
         {
            s = *itThis + s2;
            s1 = s % 1000;
            s2 = s / 1000;
            sum.digits.push_front(s1);
            ++itThis;
         }
      }
      if(s2 != 0)
         sum.digits.push_front(s2);
         
      *this = sum;
      return *this;  
   }

   friend ostream & operator << (ostream & out, WholeNumber & rhs);


private:
   list <int> digits;
};

#endif // WHOLENUMBER_H

