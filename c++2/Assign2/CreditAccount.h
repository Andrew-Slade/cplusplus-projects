//********************************************
//File: CreditAccount.h
//Author: Andrew Slade
//Logon Id: z1818810
//Due Date: 02/16/2017
//TA: Dinesh Sandadi
//
//Purpose: Contains the declaration for the CreditAccount class.
//********************************************

#ifndef CREDIT_ACCOUNT_H
#define CREDIT_ACCOUNT_H

class CreditAccount
  {
    //Data members and method prototypes for the CreditAccount class go here

    private:
      //Private methods and data members

      char accountNum[20];//account number
      char accountName[21];//acount name
      double creditLimit;//credit limit
      double currBalance;//current balance

    public:
      //Public methods and data members(or, in  this case, only methods).

      CreditAccount(); //default constructor

      CreditAccount(char* ,char* ,double ,double); //Alternate constructor(Parameterized)
      //takes 2 char arrays and 2 doubles  

      char* getAccountNumber();//accessor
      char* getName();//accessor
      double getLimit();//accessor
      double getBalance();//accessor
      void processPayment(double);//takes double that represents payment
      bool processCharge(double);//takes double that represents charge
      void print();//print method

  };

//Header Guard
#endif
//------------
