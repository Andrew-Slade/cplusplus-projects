/****************************************
*Programmer: Andrew Slade
*Due: 10/02/2017
*TA: Bhaskara Reddy Devarapalli
*ZID: Z1818810
*Section: 340-0003
*header file
*Purpose: scans and processes a stream of
*words into plaintext
****************************************/
#ifndef PROG4_H
#define PROG4_H

//Preprocessors
#include <map>
#include <algorithm>
#include <string>
#include <iostream>
#include <iomanip>

using std::string;
using std::map;
//***************

//definitions
#define ITEM_W 16
#define NO_ITEMS 3
//**********

//Prototypes
void get_words(map<string, int>&);
void print_words(const map<string,int>&);
void clean_entry(const string&, string&);
//**********

#endif

