/*************************************************
CSCI-241 -Assignment 5- Spring 2017

Programmer: Andrew Slade
Z-ID: z1818810
Section: 4
TA: Dinesh Sandadi
Date Due: 03/28/2017

Purpose:Contains the declaration for NIUString class which
manipulates an array in a manner similar to the string 
standard class 
*************************************************/
#ifndef NIUSTRING_H
#define NIUSTRING_H

#include <iostream>
using std::ostream;

class NIUString
  {
    friend ostream& operator<<(ostream& lhs, const NIUString& rhs);
    friend bool operator==(const char* lhs, const NIUString& rhs);

    private:
     char* stringPointer;//pointer to allocate array
     size_t capacityd;//capacity of array
     size_t sized;//current array size
    
    public:
     NIUString();
     NIUString(const char*);
     NIUString(const NIUString&);
     ~NIUString();
     void clear();
     void reserve(size_t);
     NIUString& operator=(const NIUString&);
     NIUString& operator=(const char*);
     size_t capacity() const;
     size_t size() const;
     bool empty() const;
     bool operator==(const NIUString&) const;
     bool operator==(const char*) const;
     const char& operator[](size_t) const;
     char& operator[](size_t);

     
  };

#endif
