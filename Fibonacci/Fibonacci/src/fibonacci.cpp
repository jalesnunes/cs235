/***********************************************************************
 * Implementation:
 *    FIBONACCI
 * Summary:
 *    This will contain the implementation for fibonacci() as well as any
 *    other function or class implementations you may need
 * Author
 *     Jales Nunes, Davi Neves
 **********************************************************************/

#include "fibonacci.h"  // your fibonacci() function

/************************************************
 * FIBONACCI
 * The interactive function allowing the user to
 * display Fibonacci numbers
 ***********************************************/
void fibonacci()
{
   int number;

   // show the first serveral Fibonacci numbers
   cout << "How many Fibonacci numbers would you like to see? ";
   cin  >> number;

   // your code to display the first <number> Fibonacci numbers

   //initiate three whole number objects
   WholeNumber w1(1);
   WholeNumber w2(2);
   WholeNumber w3(2);
   
   if(number == 0)
      cout << endl;
   else
   {
      if(number >= 1)
      {
         cout << "\t" << w1;
      }
      if(number >= 2)
      {
         cout << "\t" << w1;
      }      
      if(number >= 3)
      {
         cout << "\t" << w2;
      }
      //computes Fibonacci sequence recursively
      for(int i = 4; i <= number; i++)  
      {
         w3 += w1;
         w1 = w2;
         w2 = w3;
            
         cout << "\t" << w3;
      }
   }
   
   // prompt for a single large Fibonacci
   cout << "Which Fibonacci number would you like to display? ";
   cin  >> number;

   // your code to display the <number>th Fibonacci number

   //initiate three whole number objects
   WholeNumber f1(1);
   WholeNumber f2(2);
   WholeNumber f3(2);
   
   if(number == 0)
      cout << endl;
   else
   {
      if(number == 1 || number == 2)
      {
         cout << "\t" << f1;
      }
      else if(number == 3)
      {
         cout << "\t" << f2;
      }
      else
      {
         //computes sequence and returns the last number
         for(int i = 4; i <= number; i++) 
         {
            f3 += f1;
            f1 = f2;
            f2 = f3;
         }
         cout << "\t" << f3;
      }
   }
}


