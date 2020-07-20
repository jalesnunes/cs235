/***********************************************************************
 * Implementation:
 *    NOW SERVING
 * Summary:
 *    This will contain the implementation for nowServing() as well as any
 *    other function or class implementations you may need
 * Author
 *    <your names here>
 **********************************************************************/

//#include <deque>


#include <iostream>     // for ISTREAM, OSTREAM, CIN, and COUT
#include <string>       // for STRING
#include <cassert>      // for ASSERT
#include "nowServing.h" // for nowServing() prototype
#include "deque.h"      // for DEQUE
using namespace std;

/************************************************
 * NOW SERVING
 * The interactive function allowing the user to
 * handle help requests in the Linux lab
 ***********************************************/
void nowServing()
{
   Lab myLab;
   string action;
   string myClass;
   string name;
   int minutes;
   int iTime = 0;

   // instructions
   cout << "Every prompt is one minute.  The following input is accepted:\n";
   cout << "\t<class> <name> <#minutes>    : a normal help request\n";
   cout << "\t!! <class> <name> <#minutes> : an emergency help request\n";
   cout << "\tnone                         : no new request this minute\n";
   cout << "\tfinished                     : end simulation\n";

   // your code here
   cin.ignore();

   do
   {
      // handle errors
      if (cin.fail())
      {
         cin.clear();
         cin.ignore(256, '\n');
      }

      // prompt for action
      cout << "<" << iTime << "> ";
      cin >> action;

      if (action == "!!")
      {
         cin >> myClass;
         cin >> name;
         cin >> minutes;
         Student s1(myClass, name, minutes, 1);
         myLab.getRequest(s1);
      }
      else if(action == "none"){} 
      else if(action == "finished")  
      {
         cout << "End of simulation\n";
         return;
      }
      else
      {
         myClass = action;
         cin >> name;
         cin >> minutes;
         Student s1(myClass, name, minutes, 0);
         myLab.getRequest(s1);       
      }
      iTime++;
      myLab.setBeingServed();
      myLab.display();  
      
   }while (action != "finished");
}


void Lab::setBeingServed()
{
   int minutes = served.getMinutes();
   served.setMinutes(--minutes);
   
   if(qLab.empty() == true && served.getMinutes() < 1)
   {
      served.setMinutes(0);
   }
   else if(served.getMinutes() < 1)
   {
      setServed(qLab.front());
      qLab.pop_front();
   }
}

void Lab::getRequest(Student s1)
{
   if(s1.getEmergency() == 1)
      qLab.push_front(s1);
   else
      qLab.push_back(s1);
}

void Lab::display()
{
   if(getServed().getMinutes() != 0)
   {
      if(getServed().getEmergency() == 1)
      {
         cout << "\tEmergency for " << getServed().getName()
              << " for class " << getServed().getMyClass()
              << ". Time left: " << getServed().getMinutes()
              << endl;
      }
      else
      {
         cout << "\tCurrently serving " << getServed().getName()
              << " for class " << getServed().getMyClass()
              << ". Time left: " << getServed().getMinutes()
              << endl;   
      }
   }
}


