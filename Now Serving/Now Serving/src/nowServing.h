/***********************************************************************
 * Header:
 *    NOW SERVING
 * Summary:
 *    This will contain just the prototype for nowServing(). You may
 *    want to put other class definitions here as well.
 * Author
 *    <your names here>
 ************************************************************************/

#ifndef NOW_SERVING_H
#define NOW_SERVING_H

//#include <deque>

#include "deque.h"     // for DEQUE
#include <iostream>    // for ISTREAM and COUT
#include <string>      // for STRING
#include <cassert>     // for ASSERT
using namespace custom;
using namespace std;

// the interactive nowServing program
void nowServing();

class Student
{
public:
   Student() : myClass(""), name(""), minutes(0), emergency(0) {}
   Student(string myClass, string name, int minutes, int emergency)
   {
      this->myClass = myClass;
      this->name = name;
      this->minutes = minutes;
      this->emergency = emergency;
   }

   void setMinutes (int minutes)
   {
      this->minutes = minutes;
   }

   string getMyClass() { return myClass; }
   string getName()    { return name;    }
   int getMinutes()    { return minutes; }
   int getEmergency()  { return emergency; }   

private:
   string myClass;
   string name;
   int minutes;
   int emergency;
};

class Lab
{
public:
   Lab() {}
   
   void setServed(Student served)
   {
      this->served = served;
   }

   Student getServed() { return served; }

   void display();
   void getRequest(Student s1);
   void setBeingServed();
  
private:
   deque <Student> qLab;
   Student served;
};

#endif // NOW_SERVING_H

