/************************************************
CSCI-241 -Assignment 5- Spring 2017

Programmer: Andrew Slade
Z-ID: z1818810
Section: 4
TA: Dinesh Sandadi
Date Due: 03/28/2017

Purpose:Contains methods for NIUString class and
standalone functions. These manipulate data in a 
method similar to the standard string class. 
*************************************************/

#include "NIUString.h"
#include <iostream>
#include <cstring>
using std::strlen;
using std::cout;
using std::ostream;

/************************************************
NIUString(default constructor)

Use: Constructs NIUString with default values.

Parameters: none(default constructor)

Returns: nothing(default constructor)
************************************************/
NIUString::NIUString()
  {
    sized = 0;//default values for size
    capacityd = 0;//default values for capacity
    stringPointer = nullptr; //default value for pointer to string
  }

/************************************************
NIUString(parameter constructor)

Use: Constructs NIUString with input values.

Parameters: a const char*.

Returns: nothing(constructor)
************************************************/
NIUString::NIUString(const char* other)
  {
    sized = strlen(other);//size from read in string
    capacityd = sized;//capacity from size
 
    if(capacityd == 0)
      {
        //null pointer if capacity is zero
        stringPointer = nullptr; 
      }
    else
      {
        //else new dynamic memory and assign values
        stringPointer = new char[capacityd];  
        for(size_t c = 0; c < capacityd; c++)
          {
            //assign values to stringPointer from other
            stringPointer[c] = other[c];
          }
      }
  }

/************************************************
NIUString(copy constructor)

Use: Constructs NIUString with input values.

Parameters: a reference to a NIUString object.

Returns: nothing(constructor)
************************************************/
NIUString::NIUString(const NIUString& other)
  {  
    capacityd = other.capacityd;//capacity assigned from other's capacity
    sized = other.sized;//size from other's size
    if(capacityd == 0)
      {
        //if there is no capacity, assign nullpointer
        stringPointer = nullptr;
      }
    else
      {
        //if there is a capacity, allocate memory and write to it
        stringPointer = new char[capacityd];
        for(size_t t = 0; t < capacityd; t++)
          {
            //assigns values to stringPointer from parameter other
            stringPointer[t] = other[t];
          }
      }
  }

/************************************************
~NIUString

Use: Destroys NIUString class and clears values.

Parameters: none(destructor).

Returns: nothing(destructor).
************************************************/ 
NIUString::~NIUString()
  {
    //call clear method
    clear();
  }

/************************************************
reserve

Use: makes string capacity higher.

Parameters: a size_t.

Returns: none(void).
************************************************/ 
void NIUString::reserve(size_t n)
  {
    if(n < sized || n == capacityd)
      {
        /*
          if user input value is less than size or
          equal to current capacity, ignore
        */

        return;
      }
    else
      {
       
        //otherwise set new capacity 
        capacityd = n;
        char* temp;//temp holder for an array pointer
        if(capacityd == 0)
          {
            //if capacity is zero, nullpointer
            stringPointer = nullptr;
          }
        else
          {
            /*
              otherwise create new memory and copy contents into
              the temporary array then delete string and set pointer to
              temporary pointer
            */
            temp = new char[capacityd];
            for(size_t l = 0; l < capacityd; l++)
              {
                temp[l] = stringPointer[l];  
              }
            delete[] stringPointer;
            stringPointer = temp;
          }
      } 
   return;
  }

/************************************************
operator==(overload == operator)

Use: Overloads == operator for comparing two NIUString
     objects.

Parameters: a reference to a constant NIUString object.

Returns: bool.
************************************************/ 
bool NIUString::operator==(const NIUString& rhs) const 
  {
    bool booly;//temporary holder for a bool
    int county = 0;//temp variable

    if(sized == rhs.sized)
      {
        //if the size of the current object is equal to the right hand side
        for(size_t q = 0; q < rhs.capacityd; q++)
          {
            if(stringPointer[q] == rhs.stringPointer[q])
              {
                //search through the array and if values are similar mark true
                booly = true;
              }
            else
              {
               //otherwise tally up values that are not similar
                county++;
              }
          
          }
       if(county > 0)
         {
           //if the tally is higher than zero, the strings are not similar
           booly = false;
         }
      }
    else
      {
        //if the strings are not the same size, they are not similar
        booly = false;
      }
   return booly;
  }

/************************************************
operator==(overload == operator)

Use: Overloads == operator for comparing a NIUString
     object and char array.

Parameters: a const char*.

Returns: bool.
************************************************/ 
bool NIUString::operator==(const char* rhs) const
  { 
    bool bools;//temp holder for the returned bool
    int counter = 0;//temp variable

   for(size_t d = 0; d < strlen(rhs); d++)
      { 
         if(stringPointer[d] == rhs[d])
           {
             //search through the array and register values that are the same
             bools = true;
             /*
               overwrites bools each time,
               however, works for values that are all true
             */
           }
         else
           {
             //otherwise tally up values that are not similar
             counter++;
           }
        if(counter > 0)
          {
            //if the tally is higher than zero, the strings are not similar
            bools = false;
          }
      }     
   
   return bools; 
  }

/************************************************
operator=(overload = operator)

Use: Overloads = operator for assigning to a NIUString object.

Parameters: a refernce to a const NIUString object.

Returns: reference to an NIUString object.
************************************************/ 
NIUString& NIUString::operator=(const NIUString& other)
  { 
   bool boolo = false;//temp holder for bool

   if(this == &other)
     {
       //if self assignment, skip to end
       boolo = true;
     }
   else if(boolo == false)
     {
       //if no self assignment
       delete[] stringPointer;//delete dynamic memory
       sized = other.sized;//set size to the other object's size
       capacityd = other.capacityd;//set capacity to other's capacity
       if(other.capacityd == 0)
         {
           //if other's capacity is zero, pointer to string is nullpointer
           stringPointer = nullptr;
         }    
       else
         {
           //otherwise allocate new dynamic memory and assign values
           stringPointer = new char[capacityd];
           for(size_t zz = 0; zz < capacityd; zz++)
             {
               //assigns string's values from other's strings values
               stringPointer[zz] = other.stringPointer[zz];
             }
         }
     }
   return *this;
  }
 
/************************************************
operator=(overload = operator)

Use: Overloads = operator for assigning to a NIUString object.

Parameters: a const char*.

Returns: reference to an NIUString object.
************************************************/ 
NIUString& NIUString::operator=(const char* other)
  { 
  
     delete[] stringPointer;//delete dynamic memory
     sized = strlen(other);//set size to length of character array
     capacityd = sized;//set capacity equal to size
     if(strlen(other)== 0)
       {
         //if the length of the string is zero, nullpointer
         stringPointer = nullptr;
       }    
     else
       {
         //otherwise, new dynamic memory and assign
         stringPointer = new char[capacityd];
         for(size_t zz = 0; zz < capacityd; zz++)
            {
              //assign values to string from other string 
              stringPointer[zz] = other[zz];
            }
       }
   return *this;
  }

/************************************************
capacity

Use: Returns value for capacity(accessor).

Parameters: none.

Returns: size_t.
************************************************/ 
size_t NIUString::capacity() const
  {
    //return capacity value
    return capacityd;
  }

/*********************************************
size

Use: Returns value for size(accessor).

Parameters: none.

Returns: size_t.
************************************************/ 
size_t NIUString::size() const
  {
    //return size value
    return sized;
  }

/*********************************************
empty

Use: Checks if string is empty.

Parameters: none.

Returns: bool.
************************************************/ 
bool NIUString::empty() const
  { 
    bool booled;//temp for bool

    if(sized == 0)
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
clear

Use: Defaults all variables and releases dynamic memory.

Parameters: none.

Returns: none(void).
************************************************/ 
void NIUString::clear()
  { 
    sized = 0;//default
    capacityd = 0;//default
    delete[] stringPointer;//deallocate dynamic memory 
    stringPointer = nullptr;//default

   return;
  }

/*********************************************
operator[](overload [] opeartor)

Use: overloads [] operator.

Parameters: a size_t.

Returns: reference to a const char&.
************************************************/ 
const char& NIUString::operator[](size_t pos) const
  {
    //returns value at that position  
    return stringPointer[pos];
  }

/*********************************************
operator[] (overload [] operator)

Use: Allows for writing to a specific value in the array.

Parameters:a size_t.

Returns: reference to a character.
************************************************/ 
char& NIUString::operator[](size_t pos)
  {
   //return value at position
   return stringPointer[pos];
  }

/*********************************************
operator<<(overload << operator)

Use: Overload stream operator.

Parameters:a reference to an ostream object and a reference
           to a constant NIUString object.

Returns: a reference to an ostream object.
************************************************/ 
ostream& operator<<(ostream& lhs, const NIUString& rhs)
  {
    for(size_t i = 0; i < rhs.sized; i++)
      {
        cout << rhs.stringPointer[i];
      }
   return lhs;
  }

/*********************************************
operator==(overload == operator)

Use: Overload relational operator.

Parameters:a const char* and a reference
           to a constant NIUString object.

Returns: a bool.
************************************************/ 
bool operator==(const char* lhs, const NIUString& rhs)
  {
    bool boold;//temp bool
    int count = 0;//temp count
 
    for(size_t a = 0; a < strlen(lhs); a++)
      { 
         if(rhs.stringPointer[a] == lhs[a])
           {
             //iterate through stringPointer and compare values
             //true if values are the same
             boold = true;
             //overwrites, but works for values that are all the same
           }
         else
           {
             //tallys up dissenting values
             count++;
           }
        if(count > 0)
          {
            //if there are more than zero dissenting values, sets bool to false
            boold = false;
          }
      }    
   return boold; 
  }
