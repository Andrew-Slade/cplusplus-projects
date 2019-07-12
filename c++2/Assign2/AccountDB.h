//********************************************
//File: AccountDB.h
//Author: Andrew Slade
//Logon Id: z1818810
//Due Date: 02/16/2017
//TA: Dinesh Sandadi
//
//Purpose: Contains the declaration for the AccountDB class.
//********************************************

#ifndef ACCOUNTDB_H
#define ACCOUNTDB_H


//Extra preprocessors 
#include "CreditAccount.h"
#include <string>

using std::string;
//----------------

class AccountDB
  {
   private:
     //Data members

     CreditAccount objects[20];
     int numOfObjects; 
    
     //Methods

     void sortAccounts(); //sorts accounts
     int searchForAccount(const char*); //searches accounts 
      
   public:
     //Methods

     AccountDB(); //Default Constructor 
     AccountDB(string); //Alternate Constructor; takes string
     void print(); //Prints data
     void processTransaction(string); //procures process information 

  };

#endif
