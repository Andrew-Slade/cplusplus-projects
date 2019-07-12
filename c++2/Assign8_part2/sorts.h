/*************************************************
CSCI-241 -Assignment 8- Spring 2017

Programmer: Andrew Slade
Z-ID: z1818810
Section: 4
TA: Dinesh Sandadi
Date Due: 4/25/2017

Purpose: Contains template functions that read and
manipulate data.
*************************************************/
#ifndef SORTS_H
#define SORTS_H

#include <cassert>
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>
using std::setw;
using std::cout;
using std::endl;
using std::vector;
using std::ifstream;
using std::ios;
using std::left;

//*****************Prototypes ************************
template <class T>
void buildList(vector<T>&, const char*);

template <class T>
void printList(const vector<T>&, int, int);

template <class T>
bool lessThan(const T&, const T&);

template <class T>
bool greaterThan(const T&, const T&);
//****************************************************

/**************************************************
buildList

Use: Reads data from file to vector.

Parameters: a vector<T>& and a const char*.

Returns: nothing.
**************************************************/
template <class T>
void buildList(vector<T>& set, const char* fileName)
 {
   T item;
   ifstream inFile;
   inFile.open(fileName);

       inFile>>item;
   if(inFile.is_open())
     {
       while(inFile)
         {
           //if is open, read data till end of file
           set.push_back(item);
           inFile>>item;
         }
       
       inFile.close();
     }

   else
     {
       cout << "File read error " << fileName << " could not open" << endl;
       assert(inFile);
     }
  return;
 }

/**************************************************
printList

Use: Prints out items in vector.

Parameters: a vector<T>&, an int, and an int.

Returns: nothing.
**************************************************/
template <class T>
void printList(const vector<T>& set, int itemWidth, int numPerLine)
 {
   for(size_t c = 0; c < set.size() ; c++)
     {
       if((c) % numPerLine == 0)
         {
           //print out list
           cout << endl;
         }
       cout << setw(itemWidth) << left << set[c] << " "; 
     }
  
  return;
 }

/**************************************************
lessThan

Use: Compares two T objects looking for the one that is less than.

Parameters: Two references to two T objects.

Returns: A bool.
**************************************************/
template <class T>
bool lessThan(const T& item1, const T& item2)
 {
   bool tempBool;
   if(item1 < item2)
     {  
       tempBool = true;
     } 
   else
     { 
       tempBool = false;
     }
  return tempBool;
 }

/**************************************************
greaterThan

Use: Compares two T objects looking for the one that is greater than.

Parameters: Two references to two T objects.

Returns: A bool.
**************************************************/
template <class T>
bool greaterThan(const T& item1a, const T& item2a)
 {
   bool tempBool2;
   if(item1a > item2a)
     {  
       tempBool2 = true;
     } 
   else
     { 
       tempBool2 = false;
     }
  return tempBool2;
 }

#endif
