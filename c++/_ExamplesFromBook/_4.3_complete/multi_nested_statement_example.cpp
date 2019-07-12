#include <iostream>
using namespace std;

int main() {
   int givenYear = 0;

   givenYear = 1776;

   if (givenYear >= 2100){
      cout << "Distant future";
   }
   else{
      if (givenYear >= 2000) { 
         cout << "21st century";
      }
      else{
         if (givenYear >= 1900){
            cout << "20th century";
         }
         else{
            cout << "Long ago";
         }
      }
   }

   return 0;
}