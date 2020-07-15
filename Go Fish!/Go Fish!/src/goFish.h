/***********************************************************************
* Header:
*    Go Fish
* Summary:
*    This will contain just the prototype for the goFish() function
* Author
*    <your names here>
************************************************************************/

#ifndef GO_FISH_H
#define GO_FISH_H

#include <iostream>     // for ISTREAM, OSTREAM, CIN, and COUT
#include <string>       // for STRING
#include <cassert>      // for ASSERT
#include <fstream>     // to read a file

#include "set.h"      // for class Set
#include "card.h"     // for class Card

using namespace custom;    // for custom class set
using namespace std;       //for std library

/**************************************************
 * GO FISH
 * Play the game of "Go Fish"
 *************************************************/
void goFish();
set<Card> readFile();
void displayRemaining(int matches, set<Card> hand);
void checkCards(int& r, int& matches, set<Card>& hand, Card& card);



#endif // GO_FISH_H

