/********************************************************
 * TEST NORMALIZE
 * This program is designed to test the iNormalize() funciton
 * which turns a relative index (which could be negative) into
 * a positive one where 0 <= iNormalize(i) < capacity()
 ********************************************************

#include <iostream>
#include <iomanip>
using namespace std;

/*****************************************************
 * CAPACITY
 * This is meant to simulate the capacity() private method
 * returning the size of the deque array.
 ****************************************************
int capacity()
{
   return 4;
}

/*****************************************************
 * I NORMALIZE
 * The function we will need for deque to convert a
 * potentially negative index into one between 0 and size()
 *****************************************************
int iNormalize(int iRelative)
{
   return iRelative; // this is not sufficient
}


/*****************************************
 * MAIN
 * A simple driver program to test our
 * iNormalize() function
 ****************************************
int main()
{
   // display the instructions
   cout << "The following is the conversion for capacity set to "
        << capacity()
        << endl;

   // column header
   cout << setw(8) << "Relative"
        << setw(12) << "Normalized"
        << endl;

   // main loop to test the values
   for (int iRelative = -(capacity() * 3), iExpect = 0;
        iRelative <= capacity() * 3;
        iRelative++, iExpect++)
   {
      // compute the normalized value
      int iNormal = iNormalize(iRelative);

      // display data
      cout << setw(6)  << iRelative
           << setw(10) << iNormal;

      // display error message as appropriate
      if (iNormal != iExpect % capacity())
         cout << "   ERROR";

      cout << endl;
   }

   return 0;
   
}*/
