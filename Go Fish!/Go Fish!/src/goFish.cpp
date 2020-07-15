/***********************************************************************
* Program:
*    Assignment 01, Go Fish
*    Brother Kirby, CS 235
* Author:
*    Jales Nunes, Davi Neves
*
* Summary:
*    This is all the functions necessary to play Go Fish!
*
*    Estimated:  0.0 hrs
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>     // for ISTREAM, OSTREAM, CIN, and COUT
#include <string>       // for STRING
#include <cassert>      // for ASSERT
#include <fstream>     // to read a file
#include "set.h"
#include "card.h"
#include "goFish.h"
using namespace std;       //for std library
using namespace custom;    // for custom class set


/**********************************************************************
 * GO FISH
 * The function which starts it all
 ***********************************************************************/
void goFish()
{
   //Set up initial conditions for the game
   int matches = 0;
   int r = 5;

   Card card;                   // create an object of type card
   set<Card> hand = readFile(); // create a set for a hand of cards

   //Start game and ask for user input
   cout << "We will play " << r
        << " rounds of Go Fish.  Guess the card in the hand"
        << endl;

   checkCards(r, matches, hand, card);

   displayRemaining(matches, hand);
    
}

/**********************************************************************
 * readFile
 * Function to read data from a file
 ***********************************************************************/
set<Card> readFile()
{
   Card card;              // create an object of type card
   set<Card> hand;         // create a set for a hand of cards
   //const char * filename = "hand.txt";
   const char* filename = "/home/cs235/week05/hand.txt";

   //Open file
   ifstream fin(filename);
   //chech for errors opening file
   if (fin.fail())
   {
        cout << "Error" << endl;
   }
   else
   {
      while (!fin.eof())
      {
         // Copy over the data from the file
         fin >> card;
         if (!fin.eof())
         {
            hand.insert(card);  // insert cards into the set hand
         }
      }
   }
   fin.close();  //close the file

   return hand;
}

/**********************************************************************
 * checkCards
 * checks cards in a hand
 ***********************************************************************/
void checkCards(int& r, int& matches, set<Card>& hand, Card& card)
{
   //Loop thru the cards in one's hand
   for (int i = 0; i < r; i++)
   {
      //We will check one card in each round
      cout << "round " << i + 1 << ": ";
      cin >> card; //Card that we will look for in hand
      set<Card>::iterator it = hand.find(card);    //Iterator thru set hand
      if (it == hand.end())
         cout << "\tGo Fish!" << endl; //If iterator reaches the end of the 
                                       //set, then no matches were found
      else
      {
         cout << "\tYou got a match!" << endl;   //If we get a match
         hand.erase(it);   //Erase the matching card from set hand
         matches++;   //Add one to counter of matches
      }
   }
}

/**********************************************************************
 * displayRemaining
 * Function to display the remaining cards in a set
 ***********************************************************************/
void displayRemaining(int matches, set<Card> hand)
{
   //Displays the number of matches found
   cout << "You have " << matches << " matches!" << endl;

   //Displays the cards left in hand
   cout << "The remaining cards: ";
   set<Card>::iterator it = hand.begin(); //Use iterator to loop thru the set hand
   cout << *it;                           //Displays the first card
   it++;                                  //Advances iterator to the next card
   while (it != hand.end())               //Iterator goes thru the set until it reaches the end
   {
      cout << ", " << *it;  //Displays cards in hand
      it++;                 //Advances the iterator to the next card in the set
   }
   cout << endl;
}
