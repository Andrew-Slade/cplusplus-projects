
#include <iostream>
using namespace std;

//& allows for direct argument modification (timeval calculations that affect hrval)

void ConvHrMin (int timeVal, int& hrVal, 
                int& minVal) {
   hrVal  = timeVal / 60;
   minVal = timeVal % 60;
   return;
}

int main() {
   int totTime = 0; //timeval
   int usrHr = 0; //modified by int& hourval
   int usrMin = 0; //modified by  int& minval
   
   cout << "Enter tot minutes: ";
   cin >> totTime;
   ConvHrMin(totTime, usrHr, usrMin);
   cout << "Equals: ";
   cout << usrHr << " hrs ";
   cout << usrMin << " mins" << endl;

   return 0;
}