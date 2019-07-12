/**************************************
*Student: Andrew Slade
*Program: prog1
*Due Date: Thursday, September 7, 2017
*ZID: Z1818810
*Section: 340-0003
*source file
*Purpose: fills vector with random values
*and then sorts them
**************************************/
//Preprocessors
#include "prog1.h"

using std::cout;
using std::sort;
using std::setw;
using std::endl;
using std::srand;
using std::rand;
using std::left;

#define VEC_SIZE  250//vector size
#define NUM2LINE  12 //number of items printed on a line
#define ITEM_W  5 //width for setw
#define LOW  1//lowest value for random numbers
#define HIGH  10000//highest value for random numbers
//-------------


//main routine
int main(){
  vector<int> myVector(VEC_SIZE);//the vector

  genRndNums(myVector); //generate random numbers
  sortVector(myVector); //sort vector's values
  printVec(myVector); //print vector in a organized way
 return 0;
}

//fills vector with random numbers
void genRndNums(vector<int> &vector){
  const int SEED = 1;

  srand(SEED); //seed rand()

  for(size_t c = 0; c < VEC_SIZE; c++){
    //fill vector
    vector.at(c) = rand () % (HIGH - LOW +1) + LOW;
  }

 return; 
}

//sorts vector
void sortVector(vector<int> &vector2sort){
  sort(vector2sort.begin(), vector2sort.end()); //call to algorithm library
 return;
}

//prints vector
void printVec(const vector<int> &v){
 cout << endl; //readability

 for(size_t i = 0; i < VEC_SIZE; i++){

  cout << setw(ITEM_W) << v.at(i); //print vector

  if((i + 2) % NUM2LINE == 1){
    cout << endl; //insert newline every 12 values
  }
 }
 cout << endl;//readability

 return;
}

