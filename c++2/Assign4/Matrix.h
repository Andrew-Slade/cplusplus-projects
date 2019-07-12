/*************************************************
CSCI-241 -Assignment 4- Spring 2017

Programmer: Andrew Slade
Z-ID: z1818810
Section: 4
TA: Dinesh Sandadi
Date Due: 03/09/2017

Purpose:Contains declaration for matrix class which
manipulates matrix data sets 
*************************************************/
#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
using std::ostream;

//Prototypes
class Matrix;
ostream& operator<<(ostream& rhs, const Matrix& lhs);
Matrix operator*(const int lhs, const Matrix& rhs);
//----------

class Matrix
  {
   friend ostream& operator<<(ostream&, const Matrix&);
   friend Matrix operator*(const int lhs, const Matrix& rhs);

   public:
    Matrix(); //default constructor
    Matrix(int array[][2]); //parameterized constructor
    int determinant()const;
    Matrix operator+(const Matrix&) const;
    Matrix operator*(const int) const;
    Matrix operator*(const Matrix&) const;
    bool operator==(const Matrix&) const;
    bool operator!=(const Matrix&) const;


   private:
    int theMatrix[2][2];
    int row = 2,
        column = 2; //holder variables for column number and row;

  };


#endif
