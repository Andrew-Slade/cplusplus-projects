/****************************************
*Programmer: Andrew Slade
*Due: 09/21/17
*TA: Bhaskara Reddy Devarapalli
*ZID: Z1818810
*Section: 340-0003
*header file
*Purpose: Uses the sieve of Eratosthenes
*to remove composite numbers from a set
****************************************/
#ifndef PROG3_H
#define PROG3_H

//Preprocessors
#include <set>
#include <iostream>
#include <iomanip>

using std::set;
//*************


#define ITEM_W 4
#define NO_ITEMS 16

//Prototypes
void sieve(set<int>&, int); 
void print_primes(const set<int>&);

//**********

#endif
