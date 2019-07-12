#include <iostream>
#include <ios>
#include <iomanip>
using namespace std;

int main() {
   cout << "Dog age in human years (dogyears.com)" << endl << endl;
   
   // set num char for each column, set alignment
   cout << setw(10) << left  << "Dog age" << "|";
   cout << setw(12) << right << "Human age" << endl;
   cout << "------------------------------" << endl;
   cout << setw(10) << left  << "2 months" << "|";
   cout << setw(12) << right << "14 months" << endl;
   cout << setw(10) << left  << "6 months" << "|";
   cout << setw(12) << right << "5 years" << endl;
   
   // set fill character, num char for each column, set alignment
   cout << setfill('-');
   cout << setw(10) << left  << "8 months" << "|";
   cout << setw(12) << right << "9 years" << endl;
   cout << setw(10) << left  << "1 year" << "|";
   
   // change fill character, num char for each column, set alignment
   cout << setfill('.');
   cout << setw(12) << right << "15 years" << endl;

   // change fill character, num char for each column
   cout << setfill('*') << setw(30) << "" << endl;
   
   return 0;
}