/***********************************************************************
 * Module:
 *    Week 02, Stack
 *    Brother Kirby, CS 235
 * Author:
*    Davi Neves, Jales Nunes
 * Summary:
 *    This program will implement the testInfixToPostfix()
 *    and testInfixToAssembly() functions
 ************************************************************************/

#include <iostream>    // for ISTREAM and COUT
#include <string>      // for STRING
#include <cassert>     // for ASSERT
#include "stack.h"     // for STACK
#include <algorithm>   // reverse string
using namespace custom;
using namespace std;

/*****************************************************
 * SETS THE ORDER OF OPERATORS
 *****************************************************/
int operatorsOrder(const char operand)
{
    switch (operand)
    {
    case '+':
    case '-':
        return 1;
        break;
    case '/':
    case '*':
    case '%':
        return 2;
        break;
    case '^':
        return 3;
        break;
    default:
        return -1;
        break;
    }
}

/*****************************************************
 * CONVERT INFIX TO POSTFIX
 * Convert infix equation "5 + 2" into postifx "5 2 +"
 *****************************************************/
string convertInfixToPostfix(const string& infix)
{
   string postfix;
   stack<char> s;

   for(int iInfix = 0; iInfix < infix.size(); iInfix++)
   {
      switch (infix[iInfix])
      {
			   case '+':
			   case '-':
			   case '/':
			   case '*':
			   case '%':
			   case '^':
         {
            while (!s.empty() && operatorsOrder(infix[iInfix]) <= operatorsOrder(s.top()))
            {
               postfix += ' ';
               postfix += s.top();
               s.pop();
            }
            postfix += ' ';
            s.push(infix[iInfix]);
            break;
         }
         case '(':
         {
            s.push(infix[iInfix]);
            break;
         }           
         case ')':
         {
            while (s.top() != '(')
            {
               postfix += ' ';
               postfix += s.top();
               s.pop();            
            }
            s.pop();
            break;
         }
         case ' ':
            break;
         default:
         {
            postfix += infix[iInfix];
            break;
         }
      }
   }

   while (!s.empty())
   {
      postfix += ' ';
      postfix += s.top();
      s.pop(); 
   }
 
   return postfix;
}

/*****************************************************
 * TEST INFIX TO POSTFIX
 * Prompt the user for infix text and display the
 * equivalent postfix expression
 *****************************************************/
void testInfixToPostfix()
{
    string input;
    string postfix;
    
    cout << "Enter an infix equation.  Type \"quit\" when done.\n";

    do
    {
        // handle errors
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(256, '\n');
        }

        // prompt for infix
        cout << "infix > ";
        getline(cin, input);

        // generate postfix
        if (input != "quit")
        {
            postfix = convertInfixToPostfix(input);
            cout << "\tpostfix:  " << postfix << endl << endl;
        }
        
    } while (input != "quit");

}

/*****************************************************
 * ASSEMBLY OPERATOR
 * Converts infix operators to assembly
 *****************************************************/
string operatorAssembly(const char operand)
{
   string assemblyOp;

   switch (operand)
   {
      case '+':
         assemblyOp = "ADD ";
         break;
      case '-':
         assemblyOp = "SUB ";
         break;
      case '/':
         assemblyOp = "DIV ";
         break;
      case '*':
         assemblyOp = "MUL ";
         break;
      case '%':
         assemblyOp = "MOD ";
         break;
      case '^':
         assemblyOp = "EXP ";
         break;
    }
    
    return assemblyOp;
}

/**********************************************
 * CONVERT POSTFIX TO ASSEMBLY
 * Convert postfix "5 2 +" to assembly:
 *     LOAD 5
 *     ADD 2
 *     STORE VALUE1
 **********************************************/
string convertPostfixToAssembly(const string & postfix, int size)
{
   string assembly;  
   stack<char> s;
   string rhs;
   string lhs;
   char variable = 'A';

   for(int i = 0; i < size; i++)
   {
      if(postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '/' || postfix[i] == '*' || postfix[i] == '%' || postfix[i] == '^')
      {
         /*while(s.top()== ' ')
         {
         rhs += s.top();
         s.pop();
         }
         
         reverse(rhs.begin(), rhs.end());
         
         while(s.top() != ' ')
         {
         lhs += s.top();
         s.pop();
         }
         
         reverse(lhs.begin(), lhs.end());*/
         
         rhs += s.top();
         s.pop();
         lhs += s.top();
         s.pop();

         assembly += "\t";
         assembly += "SET ";
         assembly += lhs;
         assembly += "\n";
         assembly += "\t";
         assembly += operatorAssembly(postfix[i]);
         assembly += rhs;
         assembly += "\n";
         assembly += "\t";
         assembly += "SAV ";
         assembly += variable;
      }
      else if (postfix[i] != ' ')
      {
         s.push(postfix[i]);
      }  
   }

   return assembly;
}

/*****************************************************
 * TEST INFIX TO ASSEMBLY
 * Prompt the user for infix text and display the
 * resulting assembly instructions
 *****************************************************/
void testInfixToAssembly()
{
   string input;
   string postfix;
   
   cout << "Enter an infix equation.  Type \"quit\" when done.\n";

   do
   {
      // handle errors
      if (cin.fail())
      {
         cin.clear();
         cin.ignore(256, '\n');
      }
      
      // prompt for infix
      cout << "infix > ";
      getline(cin, input);
      
      // generate postfix
      if (input != "quit")
      {
         postfix = convertInfixToPostfix(input);
         cout << convertPostfixToAssembly(postfix, postfix.size()) << endl;
      }
   }
   while (input != "quit");
      
}
