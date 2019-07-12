/****************************************
*Programmer: Andrew Slade
*Due: 09/21/17
*TA: Bhaskara Reddy Devarapalli
*ZID: Z1818810
*Section: 340-0003
*source file
*Purpose: Uses the sieve of Eratosthenes
*to remove composite numbers from a set
****************************************/

//Preprocessors
#include "prog3.h"

using std::cin;
using std::cout;
using std::setw;
using std::endl;
//*************


//main
int main(){
 set<int> mySet;
 int myLim = 0;

 cout << "Please enter the upper limit > ";
 cin >> myLim;
 cout << "upper limit for the set of primes: " << myLim;
 sieve(mySet, myLim);
 print_primes(mySet);

 return 0;
}


//implements the sieve algorithm
void sieve(set<int> &s, int n){
  for(int c = 2; c < n; c++){
   s.insert(c); //fill the array
  } 

  for(int m = 2; m < n; m++){
   for(int k = 2; k < n; k++){
     s.erase(k*m); //the sieve of Eratosthenes
   } 
  }
 return;
}


//prints out relevant information
void print_primes(const set<int> &s){
  int i = 0;
  cout << endl;
  for(int elem : s){
    cout << setw(ITEM_W) << elem; //outputs set
    i++;
    if(i % NO_ITEMS == 0){
      cout << endl; //ouputs line end if number of items is 16
    }
  }
 cout << endl;
 return;
}
