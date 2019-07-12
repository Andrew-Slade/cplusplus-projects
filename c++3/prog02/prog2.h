/****************************************
*Programmer: Andrew Slade
*Due: 09/14/17
*TA: Bhaskara Reddy Devarapalli
*ZID: Z1818810
*Section: 340-0003
*source file
*Purpose: searches for randomly generated
*value in the vector
****************************************/

//Preprocessors
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using std::vector;
//*************

//Prototypes
void Vectors(vector<int>&, vector<int>&, int, int);
bool linearSearch(const vector<int>&, int);
bool binarySearch(const vector<int>&, int);
int search(const vector<int>&, const vector<int>&, bool (*p) (const vector<int>&, int));
void sortVector(vector<int>&);
void printVector(const vector<int>&);
void printStat(int, int);
//**********

//defined variables
#define ARR_SIZE 200
#define TEST_ARR_SIZE 100
#define HIGH 1000
#define LOW 1
#define NO_ITEMS 16
#define ITEM_W 4
#define SEED1 1
#define SEED2 3
//*********************

