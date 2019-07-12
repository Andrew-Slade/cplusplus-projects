/****************************************
*Programmer: Andrew Slade
*Due: 10/02/2017
*TA: Bhaskara Reddy Devarapalli
*ZID: Z1818810
*Section: 340-0003
*source file
*Purpose: scans and processes a stream of
*words into plaintext
****************************************/

//Preprocessors
#include "prog4.h"

using std::setw;
using std::cout;
using std::endl;
using std::cin;
using std::left;
using std::isalnum;
//************

int main(){

 map<string, int> myMap;
 get_words(myMap); 
 print_words(myMap);

 return 0;
}


//gets word from input stream
void get_words(map <string, int>& m){
  string temp = ""; //temp var for input
  string entry = ""; //temp var for entry

  while(cin >> temp){
  
    clean_entry(temp,entry);

    if(entry.size() != 0){ 
       //pushes any non empty strings onto the map
       m[entry]++;
    }
  }

 return;
}


//prints words with frequencies and various other stats
void print_words(const map<string, int>& mapp){
  int count = 0; //temp variable
  int frequency = 0;
  cout << endl; //because of cleanliness

  for(auto elem: mapp){
  
  	  //prints out map's contents
     cout << setw(ITEM_W) << left << elem.first
          << ": " <<  elem.second << "  ";
   
     frequency += elem.second; //adds up frequencies
     count++; //iterates

     //prints elements and frequency
     if(count % NO_ITEMS == 0){
       cout << endl;
     }
  }

  cout << endl << "no of words in input stream : " << frequency << endl 
       << "no of words in output stream : " <<  mapp.size() << endl;
  //prints total elements preceded and succeeded by a new line

 return;
}


//removes punctuation marks
void clean_entry(const string& cStr, string& str){
 size_t first = 0, last = 0; //temp variables;
 string tempstr;
 bool nofirst; 
 //temp bool flag used in for loop to indicate lack of alph/numer

 nofirst = true;
 for(size_t c = 0; c < cStr.size(); c++){ 
   //checks input for first and last alpha numeric characters
     if(nofirst && isalnum(cStr.at(c))){ 
       first = c;
       nofirst = false;
     }

     else if( !nofirst && !isalnum(cStr.at(c))){ 
        last = c - 1;
        break; //the if and else were added after
     }

     else if(!nofirst){ 
       last = c;
     }
 }
 
 if(nofirst){
  str = ""; 
  //in the case such that there are no special characters in the word
 }

 else if(first == last && last > 0){
 /*
  in the special case such that the word is very small
  really only exists to get rid of the c double quotes 
 */
   tempstr = cStr.substr(first, last);
 
   for(size_t l = 0;l < tempstr.size(); l++){
     //converts word to lowercase
     tempstr.at(l) = tolower(tempstr.at(l));
   }
 
   str = tempstr; //assigns str the value of modified word  
 }

 else{
   tempstr = cStr.substr(first, last + 1);

   for(size_t l = 0;l < tempstr.size(); l++){
     //converts word to lowercase
     tempstr.at(l) = tolower(tempstr.at(l));
   }

   str = tempstr; //assigns str the value of modified word
 }

 return;
}

