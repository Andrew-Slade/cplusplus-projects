/**************************************
*Student: Andrew Slade
*Program: prog1
*Due Date: Thursday, September 7, 2017
*ZID: Z1818810
*Section: 340-0003
*Header File
*Purpose: Contains declaration for VectorSort structure
*which is used to maintain and sort the vector
**************************************/
#ifndef PROG1_H
#define PROG1_H

//Preprocessors
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using std::vector;
//-------------

//Prototypes
void genRndNums(vector<int>&);//generate random numbers
void sortVector(vector<int>&); //sort vector's values
void printVec(const vector<int>&); //print vector in a organized way
//----------

#endif
