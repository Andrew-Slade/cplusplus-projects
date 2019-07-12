/*************************************************
CSCI-241 -Assignment 6- Spring 2017

Programmer: Andrew Slade
Z-ID: z1818810
Section: 4
TA: Dinesh Sandadi
Date Due: 04/11/2017

Purpose:Contains the declaration for Queue class which
manipulates data in the manner that a queue data 
structure does.
*************************************************/
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include<stdexcept>
using std::underflow_error;
using std::ostream;

class queue
 {
  friend ostream& operator<<(ostream &, const queue&);

  private:  
   int* firstE; //pointer to first element
   size_t qCap; //queue capacity
   size_t qSize; //queue size
   size_t fSub; //subscript for front
   size_t bSub; //subscript for back
   int* qArray; // queue

  public:
   queue(); //default constructor
   ~queue();
   queue(const queue&); //copy constructor
   queue& operator=(const queue&);
   void clear();
   size_t size() const;
   size_t capacity() const;
   bool empty() const;
   int front() const throw(underflow_error);
   int back() const throw(underflow_error);
   void push(int);
   void pop() throw(underflow_error);
   void reserve(size_t);
   const int& operator[](size_t) const;

 };

#endif
