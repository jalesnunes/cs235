/***********************************************************************
 * Implementation:
 *    FIBONACCI
 * Summary:
 *    This will contain the implementation for fibonacci() as well as any
 *    other function or class implementations you may need
 * Author
 *     Jales Nunes, Davi Neves
 **********************************************************************/


#include "wholeNumber.h"  // your fibonacci() function


/*******************************************
 * WholeNumber :: Non-Default Constructor
 *******************************************/
WholeNumber :: WholeNumber(const int num)
{
   digits.push_back(num);
}

/*******************************************
 * WholeNumber :: Friend Insertion Operator
 *******************************************/
ostream & operator << (ostream & out, WholeNumber & rhs)
{
   typename list <int> :: iterator it;
   it = rhs.digits.begin();
   out << *it;
   ++it;

   //Display digits separeted by ','   
   for (it; it != rhs.digits.end(); ++it)
   {
      if(*it < 10)
         out << ",00" << *it;
      else if(*it < 100)
         out << ",0" << *it;
      else
         out << "," << *it;
   }
   out << endl;
      
   return out;  
}



