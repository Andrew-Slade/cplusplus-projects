/*************************************************
CSCI-241 -Assignment 8- Spring 2017

Programmer: Andrew Slade
Z-ID: z1818810
Section: 4
TA: Dinesh Sandadi
Date Due: 4/25/2017

Purpose: Contains template functions that do a merge
sort.
*************************************************/
#ifndef MERGESORT_H
#define MERGESORT_H

//Prototypes***************************************
template <class T>
 void mergeSort(vector<T>&, bool (*compare)(const T&, const T&));

template <class T>
void mergeSort(vector<T>&, int, int, bool (*compare) (const T&, const T&));

template <class T>
void merge(vector<T>&, int, int, int, bool (*compare) (const T&, const T&));
//*************************************************

/**************************************************
mergeSort

Use: Starts the mergesort using recursion.

Parameters: a vector<T>& and a pointer to a function.

Returns: nothing.
**************************************************/
template <class T>
void mergeSort(vector<T>& set, bool (*compare) (const T&, const T&))
 {
   mergeSort(set, 0, set.size() - 1, compare);
  return;
 }

/**************************************************
mergeSort

Use: Does mergesort.

Parameters: a vector<T>&, two ints, and a pointer to a function.

Returns: nothing.
**************************************************/
template <class T>
void mergeSort(vector<T>& set, int low, int high, bool (*compare) (const T&, const T&))
 {
   int mid;//temp for mid
   
   if(low < high)
     {
       mid = (low + high) / 2;
       
       mergeSort(set, low, mid, compare);//divide elements
       mergeSort(set, mid + 1, high, compare);//divide elements
       merge(set, low, mid, high, compare);//combine elements
     }
  return;
 }

/**************************************************
merge

Use: Does merge.

Parameters: a vector<T>&, three ints, and a pointer to a function.

Returns: nothing.
**************************************************/
template <class T>
void merge(vector<T>& set, int low, int mid, int high, bool (*compare) (const T&, const T&))
 {
   vector<T> temp(high - low + 1); //temp vector
   int a = low; //sub for start of left vector
   int b = mid + 1; //sub for start of right vector
   int c = 0; //sub for start of merged vector
   
   while(a <= mid && b <= high)
     { 
       //while not at the end of either vector, copy elements to temp
       if(compare(set.at(b),set.at(a)))
         {
           temp.at(c) = set.at(b);
           b++;
           c++;  
         }
       else
         {
           temp.at(c) = set.at(a);
           a++;
           c++;
         }
     }

  while(a <= mid)
    {
      // any remaining elements from left vector merged
      temp.at(c) = set.at(a);
      a++;
      c++;
    }

  while(b <= high)
    {
      //any elements from right vector merged
      temp.at(c) = set.at(b);
      b++;
      c++;
    }

  for(a = 0, b = low; b <= high; a++, b++)
    {
      //merged elements back to original vector
      set.at(b) = temp.at(a);
    }

  return;
 }

#endif
