/*********************************************************
CSCI 241 - Assignment 2 -Spring 2017

Programmer: Andrew Slade
Z-ID: z1818810
Section: 4
TA: Dinesh Sandadi
Date Due: 02/16/2017

Function: This is a class to a program that takes account information
and manipulates it. For example, If the account balance is negative,
then it flips the value accross the zero pivot
(this is known as negating in the math world). The end method prints out
relevant data.
**********************************************************/

//preprocessors
#include "CreditAccount.h"
#include <cstring>
#include <iostream>
#include <iomanip>

using std::fixed;
using std::setprecision;
using std::strcpy;
using std::cout;
using std::endl;
//-------------


/*********************************************************
CreditAccount::CreditAccount(Credit account default constructor)

Use: constructs CreditAccount with default values predecided.

Parameters:nothing(default constructor).

Returns: nothing(constructor)
***********************************************************/
CreditAccount::CreditAccount()
  {
    strcpy(accountNum, ""); 
    strcpy(accountName, "");
    creditLimit = 0.0;
    currBalance = 0.0;

  } 

/*********************************************************
CreditAccount::CreditAccount(Credit account parameterized constructor)

Use: constructs CreditAccount with default values passed in
using parameters.

Parameters: 1.accountNumed: a pointer to a character array
                             holding the account number.
            2.accountNamed: a pointer to a character array
                             holding a account name.
            3.creditLimit: a double that is the credit limit to an account.
            4.curredBalance: a double that holds a current balance for the account
                              can be negative or positive.
Returns: nothing(constructor)
***********************************************************/
CreditAccount::CreditAccount(char* accountNumed, char* accountNamed, double creditedLimit, double curredBalance)
  {
     strcpy(accountNum, accountNumed); 
     strcpy(accountName, accountNamed );
     creditLimit = creditedLimit;
     currBalance = curredBalance;
   
  }

/*********************************************************
CreditAccount::getAccountNumber

Use: Accessor method for the data member accountNumber.

Parameters: none(accesses only private data members). 

Returns: The value of the data member accountNumber.
***********************************************************/
char* CreditAccount::getAccountNumber()
  { 
   return accountNum;
  }

/*********************************************************
CreditAccount::getName

Use: Accessor method for the data member accountName.

Parameters: none(accesses only private data members). 

Returns: The value of the data member accountName.
***********************************************************/
char* CreditAccount::getName()
  { 
   return accountName;
  }

/*********************************************************
CreditAccount::getLimit

Use: Accessor method for the data member creditLimit.

Parameters: none(accesses only private data members). 

Returns: The value of the data member creditLimit.
***********************************************************/
double CreditAccount::getLimit()
  { 
   return creditLimit;
  }

/*********************************************************
CreditAccount::getBalance

Use: Accessor method for the data member currBalance.

Parameters: none(accesses only private data members). 

Returns: The value of the data member currBalance.
***********************************************************/
double CreditAccount::getBalance()
  { 
   return currBalance;
  }

/*********************************************************
CreditAccount::processPayment

Use: Processess payments made to account.

Parameters: a double representing a payment. 

Returns: Nothing(void).
***********************************************************/
void CreditAccount::processPayment(double payment)
  {
    currBalance -= payment;
   return;
  }

/*********************************************************
CreditAccount::processCharge

Use: Processess payments made to account.

Parameters: a double representing the charge. 

Returns: bool that represents whether or not the account has 
required credit limit.
***********************************************************/
bool CreditAccount::processCharge(double charge)
  {
    bool processedCharge;//bool
    
    if(charge + currBalance > creditLimit)
      {
        //sets bool to false if charge + balance > limit
        processedCharge = false;
      }
    else
      {
        /*
          adds charge to current balance and
          sets bool to true 
        */
     
        currBalance += charge;
        processedCharge = true;
      }
    
   return processedCharge;
  }

/*********************************************************
CreditAccount::print

Use: Method that prints out relevant private data members.

Parameters: none(accesses only private data members). 

Returns: nothing(void)
***********************************************************/
void CreditAccount::print()
  { 
        //output here---------------------------
    cout << fixed << setprecision(2);
    cout << "Account Number: " << accountNum
         << endl << "Name: " << accountName
         << endl << "Credit Limit: $" << creditLimit << endl;
    //---------------------------------------
   if(currBalance < 0)
      {
        currBalance = currBalance * -1;
        cout <<"Current Balance: $" << currBalance << " CR" << endl;
        // if current balance is < 1, then negates value and appends CR
      }
   else
     {
       //else cout currBalance normal
       cout <<"Current Balance: $" << currBalance << endl;
     }
 
   return;
  }
