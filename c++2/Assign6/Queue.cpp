/************************************************
CSCI-241 -Assignment 6- Spring 2017

Programmer: Andrew Slade
Z-ID: z1818810
Section: 4
TA: Dinesh Sandadi
Date Due: 04/11/2017

Purpose:Contains methods for Queue class that manipulate
a structure similar to the data structure queue.  
Some of this code is from the course website, and
was modified to fit my purposes, other code
was fashioned from Assignment 5's code.
*************************************************/

#include "Queue.h"
#include <iostream>
#include <stdexcept>
using std::underflow_error;
using std::cout;
using std::ostream;

/************************************************
queue(default constructor)

Use: Constructs queue 

Parameters: none.

Returns: nothing(constructor)
************************************************/
queue::queue()
 {
   firstE = nullptr; //pointer to first element
   qCap = 0; //queue capacity
   qSize = 0; //queue size
   fSub = 0; //subscript for front
   bSub = qCap - 1; //subscript for back
   qArray = nullptr;// array that serves for queue
  
 }

/************************************************
queue(copy constructor)

Use: Constructs queue with another queue.

Parameters: a reference to a queue object.

Returns: nothing(constructor)
************************************************/
queue::queue(const queue& other)
  {  
    qCap =  other.qCap;//capacity assigned from other's capacity
    qSize = other.qSize;//size from other's size
    fSub = other.fSub;//subscript for front from other's front subscript
    bSub = other.bSub;//subscript for back from other's back subscript
    
    if(qCap == 0)
      {
        //if there is no capacity, assign nullpointer
        qArray = nullptr;
      }
    else
      {
        //if there is a capacity, allocate memory and write to it
        qArray = new int[qCap];
        for(size_t t = 0; t < qCap - 1; t++)
          {
            //assigns values to stringPointer from parameter other
            qArray[t] = other[t];
          }
      }
  }

/************************************************
~queue

Use: Destroys queue class and clears values.

Parameters: none(destructor).

Returns: nothing(destructor).
************************************************/ 
queue::~queue()
  {
    delete[] qArray; //delete dynamic memory
  }

/************************************************
operator=(overload = operator)

Use: Overloads = operator for assigning to a queue object.

Parameters: a refernce to a const queue object.

Returns: reference to an queue object.
************************************************/ 
queue& queue::operator=(const queue& other)
  { 
   bool boolo = false;//temp holder for bool

   if(this == &other)
     {
       //if self assignment, skip to end
       boolo = true;
     }
   else if(boolo == false)
     {
       //if no self assignment copy data over
       delete[] qArray;//delete dynamic memory
       qSize = other.qSize;//set size to the other object's size
       qCap = other.qCap;//set capacity to other's capacity
       fSub = other.fSub;//set front subscript to other's front subscript
       bSub = other.bSub;//set back subscript to other's back subscript

       if(other.qCap == 0)
         {
           //if other's capacity is zero, pointer to queue is nullpointer
           qArray = nullptr;
         }    
       else
         {
           //otherwise allocate new dynamic memory and assign values
           qArray = new int[qCap];

           for(size_t zz = 0; zz < qCap; zz++)
             {
               //assigns string's values from other's strings values
               qArray[zz] = other.qArray[zz];
             }
         }
     }
   return *this;
  }

/************************************************
clear

Use: sets queue to empty state.

Parameters: none.

Returns: none.
************************************************/ 
void queue::clear()
 {
   //set all values to default state
   qSize = 0;
   fSub = 0;
   bSub = qCap - 1;

  return;
 }

/************************************************
reserve

Use: reserves queue capacity.

Parameters: a size_t.

Returns: none.
************************************************/ 
void queue::reserve(size_t n)
 {
    if(n > qCap)
      {
        /*
          if user input value is greater than capacity
          reserve space, else, ignore
        */

        int* tArray = new int[n];
        size_t curre = fSub; //assigns qFront to temp value

        for(size_t e = 0; e < qSize; e++)
          { 
            //assign element at subscript curre
            tArray[e] = qArray[curre];
            //increment curre, wrapping to front of queue array if necessary
            curre = (curre + 1) % qCap;
          }

       qCap = n;
       fSub = 0;
       bSub = qSize - 1;
       delete[] qArray;
       qArray = tArray;
      } 
  return;
 }

/************************************************
pop

Use: pops queue.

Parameters: none.

Returns: none.
************************************************/ 
void queue::pop() throw(underflow_error)
 {
   if(empty())
     {
       //throw exception if empty
       throw underflow_error("queue underflow on pop()");
     }

   fSub = (fSub + 1) % qCap;//wraps around if at back
   qSize--;
  return;
 }

/************************************************
push

Use: pushes queue.

Parameters: an integer.

Returns: none.
************************************************/ 
void queue::push(int pushed)
 {
   if(qSize == qCap)
    {
     //reserve space for different cases
     if(qCap == 0)
       {
        reserve(1);
       }
 
     else
       {
        reserve(qCap * 2);
       }

    }
  
   bSub = (bSub + 1) % qCap;//wraps around if at back
   qArray[bSub] = pushed;
   ++qSize;

  return;
 }
/************************************************
capacity

Use: returns queue's capacity.

Parameters: none.

Returns: a size_t.
************************************************/ 
size_t queue::capacity() const
 {
  //return capacity
  return qCap;
 }

/************************************************
size

Use: returns queue's size.

Parameters: none.

Returns: a size_t.
************************************************/ 
size_t queue::size() const
 {
  //return size
  return qSize;
 }

/*********************************************
front

Use: Returns value of front element.

Parameters: none.

Returns: an integer.
************************************************/ 
int queue::front() const throw(underflow_error) 
  {
    if(empty())
      {
        //throw exception if empty
        throw underflow_error("queue underflow on front()");
      }
   return qArray[fSub];
  }

/*********************************************
back

Use: Returns value of back element.

Parameters: none.

Returns: an integer.
************************************************/ 
int queue::back() const throw(underflow_error)
  {
    if(empty())
      {
        //throw exception if empty
        throw underflow_error("queue underflow on back()");
      }
   return qArray[bSub];
  }

/*********************************************
empty

Use: Checks if queue is empty.

Parameters: none.

Returns: bool.
************************************************/ 
bool queue::empty() const
  { 
    bool booled;//temp for bool

    if(qSize == 0)
      { 
        //if empty, set to true
        booled = true;
      }
    else
      {
        //otherwise set to false
        booled = false;
      }

   return booled;
  }

/*********************************************
operator<<(overload << operator)

Use: Overload stream operator.

Parameters:a reference to an ostream object and a reference
           to a constant queue object.

Returns: a reference to an ostream object.
************************************************/ 
ostream& operator<<(ostream& lhs, const queue& rhs)
  {
    size_t curr = rhs.fSub;
                           
    for(size_t i = 0;  i < rhs.qSize; i++)
      {
        //print element at subscript curr
        lhs << rhs.qArray[curr] << " ";
        //increment curr, wrapping around to front of queue array if necessary
        curr = (curr + 1) % rhs.qCap;
      }
   return lhs;
  }

/*********************************************
operator[](overload [] opeartor)

Use: overloads [] operator.

Parameters: a size_t.

Returns: reference to a const int&.
************************************************/ 
const int& queue::operator[](size_t pos) const
  {
    //returns value at that position  
    return qArray[pos];
  }

