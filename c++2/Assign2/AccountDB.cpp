/*********************************************************
CSCI 241 - Assignment 2 -Spring 2017

Programmer: Andrew Slade
Z-ID: z1818810
Section: 4
TA: Dinesh Sandadi
Date Due: 02/16/2017

Function: This file contains the declaration for class methods
of AccountDB. These methods mostly manipulate data in ways such
as sorting, searching, or grabbing. The end product is account
adjustments and altered display.
**********************************************************/

//Preprocessors
#include "AccountDB.h"
#include <fstream>
#include <iostream>
#include <cstring>
#include <cassert>
#include <string>
#include <iomanip>

using std::setprecision;
using std::setw;
using std::fixed;
using std::left;
using std::right;
using std::strcmp;
using std::cout;
using std::endl;
using std::ios;
using std::ifstream;
using std::string;
//-------------


/*********************************************************
AccountDB::AccountDB

Use: constructs AccountDB with default values predecided.

Parameters:nothing(default constructor).

Returns: nothing(constructor)
***********************************************************/
AccountDB::AccountDB()
  {

     numOfObjects = 0;

  }

/*********************************************************
AccountDB::AccountDB

Use: constructs AccountDB with data read in from a file.
     this data creates an array of CreditAccount constructors.

Parameters: c++ string for existing database name.

Returns: nothing(constructor)
***********************************************************/
AccountDB::AccountDB(string databaseName)
  {
     ifstream inFile;
     inFile.open(databaseName.c_str(), ios::binary); 
     
     if(inFile.is_open())
       {
         //checks if inFile is open, and if so reads in data

         inFile.read((char*) this, sizeof(AccountDB));
         inFile.close();
       }
     else if (!inFile.is_open())
       {
         //error catcher
         cout << databaseName << " does not exist" << endl;
         assert(inFile);
       }
     sortAccounts();
  }

/*********************************************************
void AccountDB::sortAccounts

Use: Sorts the accounts.

Parameters: none.

Returns: nothing(void)
***********************************************************/
void AccountDB::sortAccounts()
  {
     int c, v;
     CreditAccount accountHolder;
    
     for(c = 1; c < numOfObjects; c++)
       {

         //sorts account array

         accountHolder = objects[c]; 
      
         for(v = c; (v > 0) && (strcmp(objects[v -1].getAccountNumber(),
                               accountHolder.getAccountNumber()) > 0); v--)
           {
             objects[v] = objects[v-1];
           }
         objects[v] = accountHolder;
       }

   return;
  }

/*********************************************************
void AccountDB::searchForAccount

Use: Searches the object array and returns position flag.

Parameters: a character array that holds searched for entry. 

Returns: placement of the searched for value.
***********************************************************/
int AccountDB::searchForAccount(const char* searchNum)
  {
     int low ,mid ,high;
     low = 0;
     mid = 0;
     high = numOfObjects - 1;
      
    
     while(low <=high)
       {
        
         /*
          does binary search using parameter and comparing 
          to indexed value each fail changes range of search
         */

         mid = (low + high) / 2;
       
         if(strcmp(searchNum, objects[mid].getAccountNumber()) == 0)
           {
             return mid;  
           }  
         else if(strcmp(searchNum, objects[mid].getAccountNumber()) < 0)
           {
             high = mid - 1;
           }
         else
           {
             low = mid + 1;
           }
       }
   return -1;
  }

/*********************************************************
void AccountDB::processTransaction

Use: Processes transactions on the account and does output.

Parameters: a string that represents the file's location.

Returns: nothing(void)
***********************************************************/
void AccountDB::processTransaction(string transactionFile)
  {
     ifstream inputter;     
     inputter.open(transactionFile.c_str());
     string date[6],
            transactionNum[6],
            creditOrPay[6];
     double Transaction[6];

     /*
       Report header
       structured like this because of ease
       of modification
     */
     cout << fixed << setprecision(2);
     cout << setw(45) << "Transaction Report" << endl << endl;
     cout << setw(15) << left << "Date:"
          << setw(20) << "Account:" 
          << setw(10) << "Type:"
          << setw(10) << right << "Amount:"
          << setw(30) << right <<"Balance:" << endl << endl;
     //------------

     if(inputter.is_open())
       {
         for(int x = 0; x < 6; x++)
           {
             /*
               checks if ifstream inputter is open,
               and if so reads in data from specified file
            */

             inputter >> date[x];
           
             inputter >> transactionNum[x];

             inputter >> creditOrPay[x];

             inputter >> Transaction[x];
           
          

            auto npos= std::string::npos; //because I got sick of npos not working

            int tempForComparison = searchForAccount(transactionNum[x].c_str());

            if(tempForComparison >= 0)
              { 
                /*
                if the returned value exists then
                either process payment or credit
                else catch error
                */
 
                if(creditOrPay[x].find("P") != npos)
                  {
                    //if transaction type is payment
  
                    objects[tempForComparison].processPayment(Transaction[x]);
                   

                    if(objects[tempForComparison].getBalance() < 0)
                      {
                        /*
                          if balance is negative after payment
                          appends cr else usual
                        */
                       
                        double tempBalanceHolder = objects[tempForComparison].
                                                   getBalance() * -1;
                        //tempBalanceHolder holds balance negated
                       
                        /*
                          Report
                          Again, structured like this for ease of modification
                        */
                        cout << setw(10) << left << date[x]  
                             << setw(20) << transactionNum[x]
                             << setw(10) << right << creditOrPay[x]
                             << setw(15) << right << Transaction[x]
                             << setw(30) << right << tempBalanceHolder << setw(20) << left << " CR"
                             << endl;
                        //------
                      }
                    else
                      {
                        //Report
                        cout << setw(10) << left << date[x]
                             << setw(20) << transactionNum[x] 
                             << setw(10) << right << creditOrPay[x]
                             << setw(15) << right << Transaction[x]
                             << setw(30) << right << objects[tempForComparison].getBalance() 
                             << endl;
                        //-----
                      }
                  }
                else if(creditOrPay[x].find("C") != npos)
                  {
                    //if charge is the type of transaction

                    bool tempBool = objects[tempForComparison]
                                    .processCharge(Transaction[x]);
                    /*
                      tempBool holds bool
                      from processCharge function
                      for comparison
                    */

                    //report loop
                    if(tempBool == false)
                      {
                        /*
                          if processCharge returns false,
                          credit limit exceeded is
                          appended else usual
                        */

                       //report
                       cout << setw(10) << left << date[x]
                            << setw(20) << transactionNum[x] 
                            << setw(10) << right << creditOrPay[x] 
                            << setw(15) << right << Transaction[x] 
                            << setw(40) << " *Credit Limit Exceeded*" << endl; 
                       //-----
                     }
                   else
                     {
                       //report
                       cout << setw(10) << left << date[x]
                            << setw(20) << transactionNum[x] 
                            << setw(10) << right << creditOrPay[x] 
                            << setw(15) << right << Transaction[x] 
                            << setw(30) << right << objects[tempForComparison].getBalance() << endl; 
                       //-----
                     }
                  } 
              }
            else
              {
                //report           
                cout << setw(10) << left << date[x] 
                     << setw(20) << transactionNum[x] 
                     << setw(10) << right << creditOrPay[x] 
                     << setw(15) << right << Transaction[x] 
                     << setw(40) << " *Invalid Account Number*" << endl; 
                //------           
              }
           }
          inputter.close();
        }
      else if (!inputter.is_open())
        {
          //error catcher that closes program if infile fails
          cout << transactionFile << " does not exist" << endl;
          assert(inputter);
        }
                                 
   return;
  }
/*********************************************************
void AccountDB::print

Use: prints object array's information.

Parameters: none.

Returns: nothing(void)
***********************************************************/
void AccountDB::print()
  { 
    cout << endl << "Account Holder's Information: " << endl << endl;
    for(int i = 0; i < numOfObjects; i++)
      {
        //uses CreditAccount.print to print infiled data
        objects[i].print();
        cout << endl;
      }          
   
   return;
  }
