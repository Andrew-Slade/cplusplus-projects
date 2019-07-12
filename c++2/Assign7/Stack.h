/*************************************************
CSCI-241 -Assignment 7- Spring 2017

Programmer: Andrew Slade
Z-ID: z1818810
Section: 4
TA: Dinesh Sandadi
Date Due: 4/18/2017

Purpose:Contains the declaration for Stack class and Node Struct which
manipulate data in the manner that a stack data 
structure does. Several methods come from the 
course notes.
*************************************************/
#ifndef STACK_H
#define STACK_H

//Preprocessors
#include <iostream>
using std::cout;
using std::ostream;
//------------

template <class T>
struct Node
   {
     public:
	  T datat;//holds data
	  Node<T>* nextt; //points to next node
	  Node(const T& = T(), Node<T>* nextt = nullptr);
   };

 
//Method Declaration for Node struct*******************
/************************************************
Node

Use: Constructs Node. 

Parameters: none.

Returns: nothing(constructor)
************************************************/
template <class T>
Node<T>::Node(const T& newDatat, Node<T>* newNextt)
 {
   datat = newDatat;
   nextt = newNextt;
 }

//****************************************************


// Forward declaration of the Stack template class
template <class T>
class Stack;

// Forward declaration of the operator<< template function
template <class T>
ostream& operator<<(std::ostream&, const Stack<T>&);


template <class T>
class Stack
 {
   // friend declaration for the template function and node struct
   friend ostream& operator<< <>(std::ostream&, const Stack<T>&);

  private:  
   Node<T>* stkTop;//top of stack
   size_t Size;//stack size
   void copyStack(const Stack<T>&);

  public:
   Stack(); //default constructor
   ~Stack();
   Stack(const Stack&); //copy constructor
   Stack& operator=(const Stack&);
   void clear();
   size_t size() const;
   bool empty() const;
   const T& top() const;
   void push(const T&);
   void pop();

 };


//Method definitions for the Stack class*********************

/************************************************
Stack(default constructor)

Use: Constructs Stack. 

Parameters: none.

Returns: nothing(constructor)
************************************************/
template <class T>
Stack<T>::Stack()
 {
   stkTop = nullptr;
   Size = 0;
 }

/************************************************
Stack(copy constructor)

Use: Constructs Stack with another Stack.

Parameters: a reference to a Stack object.

Returns: nothing(constructor)
************************************************/
template <class T>
Stack<T>::Stack(const Stack<T>& other)
 {
   stkTop = nullptr;   
   copyStack(other); 
   Size = other.Size;
 }

/************************************************
~Stack

Use: Destroys Stack class and clears values.

Parameters: none(destructor).

Returns: nothing(destructor).
************************************************/ 
template <class T>
Stack<T>::~Stack()
 {
   clear();
 }

/************************************************
operator=(overload = operator)

Use: Overloads = operator for assigning to a Stack object.

Parameters: a refernce to a const Stack object.

Returns: reference to an Stack object.
************************************************/ 
template <class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other)
 {
   if (this != &other)
      {
        //if no self assignment, copy stack over after clearing previous stack
        clear();
        copyStack(other);
        Size = other.Size;
      }

  return *this;
 }

/************************************************
clear

Use: sets Stack to empty state.

Parameters: none.

Returns: none.
************************************************/ 
template <class T>
void Stack<T>::clear()
 {
   //set all values to default state
    if(!empty())
      {
        //if not empty, pop stack
        pop();
      }

    stkTop = nullptr;
    Size = 0;

  return;
 }

/************************************************
pop

Use: pops Stack.

Parameters: none.

Returns: none.
************************************************/
template <class T> 
void Stack<T>::pop() 
 { 
  if(empty())
   {
     //if stack is empty, null ptr
     stkTop = nullptr; 
   }
  
   Node<T>* dNode = stkTop;
   stkTop = stkTop->nextt;//move stkTop to next value
   delete dNode;//get rid of previous stkTop
   Size--;//decrement size

  return;
 }

/************************************************
push

Use: pushes Stack.

Parameters: a reference to a const t object.

Returns: none.
************************************************/ 
template <class T>
void Stack<T>::push(const T& newItem)
 {
   Node<T>* newNode = new Node<T>(newItem, stkTop);
   stkTop = newNode;//assign stkTop a new value
   Size++;//increment size

  return;
 }

/************************************************
size

Use: returns Stack's size.

Parameters: none.

Returns: a size_t.
************************************************/ 
template <class T>
size_t Stack<T>::size() const
 {
  //return size
  return Size;
 }

/*********************************************
top

Use: Returns value of Top element.

Parameters: none.

Returns: a reference to a const T object.
************************************************/ 
template <class T>
const T& Stack<T>::top() const
 {
   //assumes not called if empty
   return stkTop->datat;
 }

/*********************************************
empty

Use: Checks if Stack is empty.

Parameters: none.

Returns: bool.
************************************************/
template <class T> 
bool Stack<T>::empty() const
  { 
    bool booled = true;//temp for bool

    if(Size != 0) 
      {
        //of size is empty, return false
        booled = false;
      }
    else
      {
        booled = true;
      }
   return booled;
  }

/*********************************************
copyList

Use: copies stack data.

Parameters:a reference to a constant Stack object.

Returns: none.
************************************************/ 
template <class T>
void Stack<T>::copyStack(const Stack<T>& othert)
 {
 
   /*
      temp node pointers for transfering data
      nptr - retrieves othert's data
      newNodePtr - temp object
      lastPtr- final object
   */
   Node<T> *nptr = nullptr,
          *newNodePtr = nullptr,
          *lastPtr = nullptr;

  for(nptr = othert.stkTop; nptr != nullptr; nptr = nptr->nextt)
    {
      //copies data from old list to new list
      newNodePtr = new Node<T>(nptr->datat);

       if(lastPtr == nullptr)
         {
           //for first instance sets stack top to value
           stkTop = newNodePtr;
         }

       else
         {
           //for later instances next recieves values
           lastPtr->nextt = newNodePtr;
         }
  
      lastPtr = newNodePtr; 
    }
 }

/*********************************************
operator<<(overload << operator)

Use: Overload stream operator.

Parameters:a reference to an ostream object and a reference
           to a constant Stack object.

Returns: a reference to an ostream object.
************************************************/ 
template <class T>
std::ostream& operator<<(std::ostream& lhs, const Stack<T>& rhs)
 {
   Node<T>* nodePtr2;

   for(nodePtr2 = rhs.stkTop; nodePtr2 != nullptr; nodePtr2 = nodePtr2->nextt)
      {
        lhs << nodePtr2->datat << " "; //couts stack
      } 

   return lhs;
 }

//End of Stack Methods******************************************
#endif



