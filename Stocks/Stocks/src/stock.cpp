/***********************************************************************
 * Implementation:
 *    STOCK
 * Summary:
 *    This will contain the implementation for stocksBuySell() as well
 *    as any other function or class implementation you need
 * Author
*    Jales Nunes, Davi Neves
 **********************************************************************/

#include <iostream>  // for ISTREAM, OSTREAM, CIN, and COUT
#include <string>    // for STRING
#include <cassert>   // for ASSERT
#include "dollars.h" // for Dollars defined in StockTransaction
#include "queue.h"   // for QUEUE
#include "stock.h"   // for STOCK_TRANSACTION

using namespace custom;
using namespace std;

/************************************************
 * STOCKS BUY SELL
 * The interactive function allowing the user to
 * buy and sell stocks
 ***********************************************/
void stocksBuySell()
{
   Portfolio myPort;
   string action;
   int shares;
   Dollars value;

   // instructions
   cout << "This program will allow you to buy and sell stocks. "
        << "The actions are:\n";
   cout << "  buy 200 $1.57   - Buy 200 shares at $1.57\n";
   cout << "  sell 150 $2.15  - Sell 150 shares at $2.15\n";
   cout << "  display         - Display your current stock portfolio\n";
   cout << "  quit            - Display a final report and quit the program\n";
   
   //Ignores 'enter key' input
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
      cout << "> ";
      cin >> action;

      if (action == "buy" || action == "sell")
      {
         cin >> shares;
         cin >> value;
         if (action == "buy")
         {
            myPort.stockBuy(shares, value);
         }
         else
         {
            myPort.stockSell(shares, value);
         }
      }
      else if (action == "display")
      {
         myPort.display();
      }
      else if (action == "quit")
         return;
      else
         cout << "Unrecognized command, exiting...\n";
   } while (action != "quit");
}

/************************************************
 * Portfolio: STOCK BUY
 * Records in Portfolio a single stock purchase
************************************************/
void Portfolio::stockBuy(int numShares, Dollars value)
{
   Stock s1(numShares, value);
   qPort.push(s1);
}

/************************************************
 * Portfolio: DISPLAY
 * Displays contents in Portfolio
************************************************/
void Portfolio::display()
{
   queue<Stock> qS(qPort);
   queue<Transaction> qT(qSale);

   if (!qS.empty())
      cout << "Currently held:" << endl;
   while (!qS.empty())
   {
      cout << "\tBought " << (qS.front()).getShares()
           << " shares at " << (qS.front()).getValue()
           << endl;
      qS.pop();
   }

   if (!qT.empty())
      cout << "Sell History:" << endl;
   while (!qT.empty())
   {
      cout << "\tSold " << (qT.front()).getShares()
           << " shares at " << (qT.front()).getValue()
           << " for a profit of " << (qT.front()).getProfit()
           << endl;
      qT.pop();
   }

   cout << "Proceeds: " << profit << endl;
}

/************************************************
 * Portfolio: STOCK SELL
 * Records in Portfolio stock sales
************************************************/
void Portfolio::stockSell(int numSell, Dollars value)
{
   Dollars pTemp;

   if (qPort.empty())
   {
      cout << " erro" << endl;
      throw "queue empty";
   }
   else
   {
      while (numSell > (qPort.front()).getShares())
      {
         //Computes profit of the sale transaction
         pTemp = (value - (qPort.front()).getValue()) * (qPort.front()).getShares();
         
         //Updates the number of shares after the first element if popped 
         numSell = numSell - (qPort.front()).getShares();
         
         //Records the sale transaction
         Transaction t1((qPort.front()).getShares(), value, pTemp);
         
         //Updates the queues Portfolio and Transaction 'sale'
         qSale.push(t1);
         qPort.pop();

         profit = profit + pTemp;
      }

      if (numSell == (qPort.front()).getShares())
      {
         //Computes profit of the sale transaction
         pTemp = (value - (qPort.front()).getValue()) * (qPort.front()).getShares();
         
         //Records the sale transaction in queue Sale
         Transaction t1((qPort.front()).getShares(), value, pTemp);
         
         //Updates the queues Portfolio and Transaction 'sale'
         qSale.push(t1);
         qPort.pop();

         profit = profit + pTemp;
      }

      else if (numSell < (qPort.front()).getShares())
      {
         //Computes profit of the sale transaction
         pTemp = (value - (qPort.front()).getValue()) * numSell;
         
         //Records the sale transaction in queue Sale
         Transaction t1(numSell, value, pTemp);
         
         //Updates the queues Portfolio and Transaction 'sale'
         qSale.push(t1);
         (qPort.front()).setShares((qPort.front()).getShares() - numSell);

         profit = profit + pTemp;
      }
   }
}
