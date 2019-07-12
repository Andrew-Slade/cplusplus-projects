/*********************************************************
CSCI 241 - Assignment 2 -Spring 2017

Programmer: Andrew Slade
Z-ID: z1818810
Section: 4
TA: Dinesh Sandadi
Date Due: 02/16/2017

Function: This file contains the declaration for main function
for assignment 2. Concisely, This is the main file. This calls the
program's class methods and constructs the objects with 
parameterized constructors. The program itself modifies 
accounts using predecided data read in from files.
**********************************************************/
#include "CreditAccount.h"
#include "AccountDB.h"

int main()
  {

    //string to pass as parameter -- allows for variations
    string ParamForPassing = "";
    string SecondParam = "";

    //Construct AccountDB
    AccountDB Default();
   
    //Construct AccountDB for use
    ParamForPassing = "accounts";
    SecondParam = "transactions.txt";

    //function calls
    AccountDB Main(ParamForPassing);
    Main.print();
    Main.processTransaction(SecondParam);
    Main.print();
    //-------------

   return 0;
  }
