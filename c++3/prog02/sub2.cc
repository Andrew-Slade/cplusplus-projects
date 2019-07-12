/**********************************************
*Student: Andrew Slade
*Program: prog1
*Due Date: Thursday, September 7, 2017
*ZID: Z1818810
*Section: 340-0003
*source file
*Purpose: fills vector with random values
*and then sorts them
********************************************/

//Prepocessors
#include "prog2.h"

using std::vector;
using std::binary_search;
using std::find;
using std::cout;
using std::srand;
using std::rand;
using std::setw;
using std::endl;
using std::setw;
using std::right;
//************



//fill vectors with random values
void Vectors(vector<int>& vector1, vector<int>& vector2, int s1, int s2){
  //generates random numbers and fills vectors
  
  srand(s1); //seed rand

  for(size_t c = 0; c < ARR_SIZE ; c++){
    //fill vector
    vector1.at(c) = rand () % (HIGH - LOW + 1) + LOW;
  }
  
  srand(s2); //seed second round of generation

  for(size_t i = 0; i < TEST_ARR_SIZE; i++){
    vector2.at(i) = rand () % (HIGH - LOW + 1) + LOW; 
  }

 return;
}


//use linear search to find a value in the vector
bool linearSearch(const vector<int>& v, int desired){
  bool found;
  std::vector<int>::const_iterator temp;//temporary constant iterator  

  //search for value in vector
  temp = find(v.begin(), v.end(), desired);
  if(temp != v.end()){
    found = true;
  } 
  else{
    found = false;
  }
 
 return found;
}


//print vectors
void printVector(const vector<int>& v){
  for(size_t l = 0; l < v.size(); l++){
    //prints out vector
    cout << setw(ITEM_W) << v.at(l);

    if(((l + 1) % NO_ITEMS) == 0){
      cout << endl; //inserts new line every 16 numbers
    }
  }
 
 return;
}


//sorts vectors via stl implementation
void sortVector(vector<int>& v){
  sort(v.begin(), v.end()); //sorts vector 
 return;
}


//searches using pointers to functions
int search(const vector<int>& vec1, const vector<int>& vec2, bool (*p) (const vector<int>&, int))
{
  int success = 0;

  for(size_t z = 0; z < vec2.size(); z++){
    if(p(vec1, vec2.at(z)) == true){
      success += 1;
    }
  }
 return success;
}


//prints statistics gathered by searches
void printStat(int totalSucCnt, int vectorSz){
  float percentSuccessful;
  percentSuccessful = static_cast<float>(totalSucCnt) / static_cast<float>(vectorSz);
  percentSuccessful *= 100.00;

  cout << "\tPercent of Successful Searches = " << right << std::setprecision(2)
       << std::fixed << percentSuccessful << "%" << endl;

 return;
}

bool binarySearch(const vector<int>& v, int x){
  bool foundd;

  if(binary_search(v.begin(), v.end(), x)){
    //search for value
    foundd = true;
  } 
  else{
    foundd = false;
  }

 return foundd; 
}

