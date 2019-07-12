/*************************************************
CSCI-241 -Assignment 8- Spring 2017

Programmer: Andrew Slade
Z-ID: z1818810
Section: 4
TA: Dinesh Sandadi
Date Due: 4/25/2017

Purpose: Contains template functions for quicksort that read and
manipulate data.
*************************************************/
#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>
using std::vector;

//Prototypes***************************************************
template <class T>
void quickSort(vector<T>& , bool (*compare)(const T&, const T&));

template <class T>
void quickSort(vector<T>&, int, int, bool (*compare)(const T&, const T&));

template <class T>
int partition(vector<T>&, int, int, bool (*compare)(const T&, const T&));
//**************************************************************



/**************************************************
quickSort

Use: Starts the quicksort using recursion.

Parameters: a vector<T>& and a pointer to a function.

Returns: nothing.
**************************************************/
template <class T>
void quickSort(vector<T>& set, bool (*compare)(const T&, const T&))
 {
   quickSort(set, 0, set.size() - 1, compare);
  return;
 }

/**************************************************
quickSort

Use: Performs recursive call to implement quicksort .

Parameters: a vector<T>& , two ints, and a pointer to a function.

Returns: nothing.
**************************************************/
template <class T>
void quickSort(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))
 {
   int pivot;
   
   if(start < end)
     {
       //call recursive
       pivot = partition(set, start, end, compare);
       quickSort(set, start, pivot - 1, compare);
       quickSort(set, pivot + 1, end, compare);
     }
   

  return;
 }

/**************************************************
partition

Use: Selects a pivot then does partitioning.

Parameters: a vector<T>&, two ints, and a pointer to a function.

Returns: nothing.
**************************************************/
template <class T>
int partition(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))
 {
   int pIndex,
          mid; //pivot index and mid
   T pValue; //pivot value
   T temp, tempFor, tempLast; //temp T objects
 
   mid = (start + end) / 2;
  
   //swap values
   temp = set.at(start); 
   set.at(start) = set.at(mid);
   set.at(mid) = temp;
   
   pIndex = start;
   pValue = set[start];
   
   for(int scanner = start + 1; scanner <= end; scanner++)
     {
       if(compare(set[scanner], pValue)) 
         {
           pIndex++;
           //swap values
           tempFor = set.at(scanner);
           set.at(scanner) = set.at(pIndex);
           set.at(pIndex) = tempFor;                
         }
     }
   
   //swap values
   tempLast = set.at(pIndex);
   set.at(pIndex) = set.at(start);
   set.at(start) = tempLast;

  return pIndex;
 }

#endif
