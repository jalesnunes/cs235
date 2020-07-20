/***********************************************************************
 * Header:
 *    STOCK, PORTFOLIO, TRANSACTION
 * Summary:
 *    This will contain just the prototype for stocksBuySell(). You may
 *    want to put other class definitions here as well.
 * Author
 *    Jales Nunes & Davi Neves
 ************************************************************************/

#ifndef STOCK_H
#define STOCK_H

#include <iostream>    // for ISTREAM and COUT
#include <string>      // for STRING
#include <cassert>     // for ASSERT
#include "dollars.h"   // for Dollars defined in StockTransaction
#include "queue.h"     // for QUEUE

using namespace custom;
using namespace std;

// the interactive stock buy/sell function
void stocksBuySell();

/************************************************
* STOCK : defines a Stock
***********************************************/
class Stock
{
public:
   Stock() : numShares(0), value(0) {}
   Stock(int numShares, Dollars value)
   {
      this->numShares = numShares;
      this->value = value;
   }
   
   int getShares() {return numShares;}
   Dollars getValue() {return value;}
   
   void setShares(int numShares)
   {
      this->numShares = numShares;
   }

   void setValue(Dollars value)
   {
      this->value = value;
   }
  
private:
   int numShares;
   Dollars value;
};

/************************************************
* Transaction Class
* defines a Single Transaction
***********************************************/
class Transaction
{
public:
   Transaction() : numShares(0), value(0), profit(0) {}
   Transaction(int numShares, Dollars value, Dollars profit)
   {
      this->numShares = numShares;
      this->value = value;
      this->profit = profit;
   }
   
   int getShares() {return numShares;}
   Dollars getValue() {return value;}
   Dollars getProfit() {return profit;}
   
   void setShares(int numShares)
   {
      this->numShares = numShares;
   }

   void setValue(Dollars value)
   {
      this->value = value;
   }
   
   void setProfit(Dollars profit)
   {
      this->profit = profit;
   }   
  
private:
   int numShares;
   Dollars value;
   Dollars profit;
};

/************************************************
* PORTFOLIO : defines the Portfolio Class
***********************************************/
class Portfolio
{
public:
   Portfolio() : profit(0) {}
    
   void stockBuy(int numShares, Dollars value);
   void display();
   void stockSell(int numSell, Dollars value);

private:
   Dollars profit;
   queue <Stock> qPort;
   queue <Transaction> qSale;
};


#endif // STOCK_H
