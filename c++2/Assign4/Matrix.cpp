/*************************************************
CSCI-241 -Assignment 4- Spring 2017

Programmer: Andrew Slade
Z-ID: z1818810
Section: 4
TA: Dinesh Sandadi
Date Due: 03/09/2017

Purpose:Contains declarations for matrix class methods
which manipulate matrix data. 
*************************************************/


#include "Matrix.h"


/************************************************
Matrix(default constructor)

Use: Constructs an Identity Matrix.

Parameters: none(default constructor)

Returns: nothing(default constructor)
************************************************/
Matrix::Matrix()
  {
    for(int c = 0; c < row; c++)
      {
        for(int i = 0; i < column; i++)
           if(i == c)
             {
               /*
                 this loop fills the matrix with
                 id matrix values
               */
               theMatrix[c][i] = 1;
             }
           else
             {
               theMatrix[c][i] = 0;
             }
      }
  }

/************************************************
Matrix(Parameterized constructor)

Use: Constructs an matrix with read in data.

Parameters: a 2 dimensional array.

Returns: nothing(default constructor)
************************************************/
Matrix::Matrix(int array[2][2])
  {
    for(int q = 0; q < row; q++)
      { 
        for(int s = 0; s < column; s++)
           {
            //this loop fills the matrix with passed in values
             theMatrix[q][s] = array[q][s];
           }
      }
  }

/************************************************
determinant

Use: Calculates the determinant.

Parameters: none.

Returns: the determinant(an integer)
************************************************/
int Matrix::determinant() const 
  {
    int determin = 0;

    //calculate determinant
    determin = theMatrix[0][0]*theMatrix[1][1] - theMatrix[0][1]* theMatrix[1][0];

   return determin;
  }

/************************************************
operator+(overload)

Use: Overloads + operator for Matrix class.

Parameters: a reference to a const Matrix object.

Returns: the result of the matrix addition(an object).
************************************************/
Matrix Matrix::operator+(const Matrix& rhs) const
  {
    Matrix result = *this;

    for(int ta = 0; ta < row; ta++)
      {
        for(int tp = 0; tp < column; tp++)
          {
            //does matrix addition

            result.theMatrix[ta][tp] += rhs.theMatrix[ta][tp]; 
          }
      }

   return result;
  }

/************************************************
operator*(overload)

Use: Overloads * operator for Matrix class
     specifically for scalar multiplication
     where the scalar is second.

Parameters: a constant integer.

Returns: the result of the scalar(an object).
************************************************/
Matrix Matrix::operator*(const int rhs) const
  {
    Matrix product = *this;
    
    for(int tv = 0; tv < row; tv++)
      {
        for(int tb = 0; tb < column; tb++)
          {
            //does scalar multiplication

            product.theMatrix[tv][tb] *= rhs;
          }
      }
   return product; 
  }

/************************************************
operator*(overload)

Use: Overloads * operator for Matrix class
     specifically for matrix multiplication.

Parameters: a reference to a matrix object.

Returns: the result of the matrix multiplication(an object).
************************************************/
Matrix Matrix::operator*(const Matrix& rhs) const 
  {
    Matrix lhs = *this;
    int temp[2][2]; //holds first multiplication values
    int temp2[2][2]; //holds second multiplication values
    Matrix neww;/*temp object to pass back, avoids altering const
     basically, an extra layer of security*/

    for(int rv = 0; rv < row; rv++)
      {
        for(int ab = 0; ab < column; ab++)
          {
            //fills temp arrays with new values produced by multiplication
            temp[rv][ab] =
                    lhs.theMatrix[rv][0] * rhs.theMatrix[0][ab];

            temp2[rv][ab] =
                    lhs.theMatrix[rv][1] * rhs.theMatrix[1][ab];

          }
      }

    for(int iv = 0; iv < row; iv++)
      {
        for(int ib = 0; ib < column; ib++)
          {
            //fills temp array with added values to pass back

            neww.theMatrix[iv][ib] = temp[iv][ib] + temp2[iv][ib];
          }
      }
   
   return neww; 
  }

/************************************************
operator==(overload)

Use: Overloads == operator for Matrix class
     specifically for matrix comparison.

Parameters: a reference to a matrix object.

Returns: the result of the matrix comparison(bool).
************************************************/
bool Matrix::operator==(const Matrix& rhs) const
  { 
    Matrix lhs = *this;
    bool booled;//temp holder used to return bool

    for(int xx = 0; xx < row; xx++)
      {
        for(int zz = 0; zz < column; zz++)
          {
            //compares values in the matrix searching for similar values

            if(rhs.theMatrix[xx][zz] == lhs.theMatrix[xx][zz])
              {
                booled = true;
              }
            else
              {
                booled = false;
              }
          }
      }
   return booled;
  }

/************************************************
operator!=(overload)

Use: Overloads != operator for Matrix class
     specifically for matrix comparison.

Parameters: a reference to a matrix object.

Returns: the result of the matrix comparison(bool).
************************************************/
bool Matrix::operator!=(const Matrix& rhs) const
  { 
    Matrix lhs = *this;
    bool boold;//temp holder used to return bool

    for(int xx = 0; xx < row; xx++)
      {
        for(int zz = 0; zz < column; zz++)
          {
            //compares values in the matrix looking for dissenting values

            if(rhs.theMatrix[xx][zz] != lhs.theMatrix[xx][zz])
              {
                boold = true;
              }
            else
              {
                boold = false;
              }
          }
      }
   return boold;
  }


//END OF METHODS
//--------------------------------------------------------------------
//START OF FUNCTION DEFINITIONS

/************************************************
operator<< (Overload)

Use: Overloads stream insertion operator to output matricies.

Parameters: Reference to ostream object and class object.

Returns: a ostream object.
************************************************/
ostream& operator<<(ostream& lhs, const Matrix& rhs)
  {
    lhs << "[" << "[" << rhs.theMatrix[0][0] << ", " << rhs.theMatrix[0][1] << "]"
        << ", " << "[" << rhs.theMatrix[1][0] << ", " << rhs.theMatrix[1][1] 
        << "]" << "]";  

   return lhs;
  }

/************************************************
operator* (Overload)

Use: Overloads multiplication operator for
     scalar multiplication of a matrix
     where the scalar is first.

Parameters: a constant integer and a reference
            to a object.

Returns: a matrix object.
************************************************/
Matrix operator*(const int lhs, const Matrix& rhs) 
  {
    Matrix produced = rhs;
    
    for(int tl = 0; tl < produced.row; tl++)
      {
        for(int tc = 0; tc < produced.column; tc++)
          {
            //does scalar multiplication

            produced.theMatrix[tl][tc] *= lhs;
          }
      }
    
   return produced; 
  }
