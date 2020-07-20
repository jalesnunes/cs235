/***************************************
 * This is a code fragment meant to help
 * you debug your deque code. I hope
 * this helps
 *                    - Br. Helfrich
 ***************************************/



// this code should be copy-pasted into deque.h immediately after
// the class definition. Also, put the following inside the class
// definition itself:
//     void display() const;
// Please remove this comment when you have done that.
//
// To "turn this on", you need to add -DDEBUG to the makefile
// in all the g++ statements. Please make sure you remove
// these when you submit your assignment.
//
// Finally, to display the contents of the deque at a givem
// point in the program (hopefully where the bugs are), then
// you should add:
//     d.display();

#ifdef DEBUG

using std::cerr;
/****************************************************
 * DISPLAY DEQUE
 * display the contents of a deque for debug purposes
 ****************************************************/
template <class T>
void deque <T> :: display() const
{
   // display the header info
   cerr << "\ndeque<T>::display()\n";
   cerr << "\tnumCapacity = " << numCapacity << "\n";

   // display the contents of the array
   cerr << "\tdata = ";
   if (numCapacity == 0)
      cerr << "NULL";
   else
   {
      cerr << "{ ";
      for (int i = 0; i < numCapacity; i++)
      {
         if (i != 0)
            cerr << ", ";

         // not wrapped
         //      0   1   2   3   4   5   6
         //    +---+---+---+---+---+---+---+
         //    |   |   | A | B | C |   |   |
         //    +---+---+---+---+---+---+---+
         // iFront = 9     iFrontNormalize() = 2
         // iBack  = 11    iBackNormalize()  = 4
         if (iFrontNormalize() <= iBackNormalize() &&  // not wrapped
             iFrontNormalize() <= i &&
             i <= iBackNormalize())                        // in range
            cerr << data[i];

         // wrapped
         //      0   1   2   3   4   5   6
         //    +---+---+---+---+---+---+---+
         //    | B | C |   |   |   |   | A |
         //    +---+---+---+---+---+---+---+
         // iFront = -8    iFrontNormalize() = 6
         // iBack  = -6    iBackNormalize()  = 1
         else if (iFrontNormalize() > iBackNormalize() && // wrapped
                  size() != 0 &&                              // not empty
                  (i <= iBackNormalize() ||
                   i >= iFrontNormalize()))                   // in range
            cerr << data[i];
      }
      cerr << " }";
   }
   cerr << "\n";

   // display the front and back with the normalized values in ()s
   if (numCapacity)
   {
      cerr << "\tiFront = " << iFront
           << " ("          << iFrontNormalize() << ")\n";
      cerr << "\tiBack  = " << iBack
           << " ("          << iBackNormalize()  << ")\n";
   }
}
#else
template <class T>
void deque <T> :: display() const
{
}
#endif // DEBUG
