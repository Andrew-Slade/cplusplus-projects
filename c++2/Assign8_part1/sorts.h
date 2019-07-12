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
using std::fstream;
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

template <class T>
void quickSort(vector<T>& , bool (*compare)(const T&, const T&));

template <class T>
void quickSort(vector<T>&, int, int, bool (*compare)(const T&, constT&));

template <class T>
int partition(vector<T>&, int, int, bool (*compare)(const T&, const T&));
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
   fstream inFile(fileName, ios::in);

   if(inFile.is_open())
     {
       while(!inFile.eof())
         {
           inFile >> item;
           set.push_back(item);    
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
   for(size_t c = 0; c < set.size() - 1 ; c++)
     {
       if((c) % numPerLine == 0)
         {
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
bool lessThan(const T&, const T&)
 {
  return tempBool;
 }

//template <class T>
//bool greaterThan(const T&, const T&)

//template <class T>
//void quickSort(vector<T>& , bool (*compare)(const T&, const T&))

//template <class T>
//void quickSort(vector<T>&, int, int, bool (*compare)(const T&, constT&))

//template <class T>
//int partition(vector<T>&, int, int, bool (*compare)(const T&, const T&))

#endif
