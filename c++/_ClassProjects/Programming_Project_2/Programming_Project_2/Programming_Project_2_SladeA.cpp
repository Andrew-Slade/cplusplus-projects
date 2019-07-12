/*
Andrew Slade
Programming Project 2
*/
#include <iostream>
#include<cmath>
#include<iomanip>
using namespace std;
//prototypes
void displayPowers();
void findTotalAndAverage();

int main() {

	//function call
	displayPowers();
	findTotalAndAverage();

	return 0;
}

//Meta-function: recieves user input and prints out power list
void displayPowers() {
	int usrLowerBound;
	int usrHighBound;
	int i; //function: for loop counter
	
	//user input 
	do{
		cout << "Please input a low boundary integer that is\n greater than 0 and less than 51: ";
		cin >> usrLowerBound;
		cout << endl;
		if (usrLowerBound < 1 || usrLowerBound > 50) {
			cout << "Invalid input,number higher than 50 or lower than 1." << endl;
		}
	} while (usrLowerBound < 1 || usrLowerBound > 50);

	do {
		cout << "Please input a high boundary integer that is\n"
			 <<"greater than " << usrLowerBound << " and less than 101: ";
		cin >> usrHighBound;
		cout << endl;
		if (usrHighBound < usrLowerBound + 1 || usrHighBound > 100) {
			cout << "Invalid input, integer lower than " << usrLowerBound
				 << " or higher than 100." << endl;
		}
	} while (usrHighBound < usrLowerBound + 1 || usrHighBound > 100);

	//math and output
	cout << fixed << setprecision(0);
	cout << setw(20) << left << "Number" << left << setw(20) 
		 << "Squared" << setw(20) << left << "cubed" << endl;

	for (i = usrLowerBound; i <= usrHighBound; i++) {
		cout << setw(6) << right << i << setw(21) << right << pow(i, 2) 
			 << setw(18) << right << pow(i, 3) << endl;
	}
	cout << endl;

	return;
}

//Meta-function: uses math to find total and average
void findTotalAndAverage(){
	float usrAmount = 0.0;
	float total = 0.0;
	int itemAmount = 0;
	float averageCost = 0.0;
	float taxDue = 0.0;
	float finalTotal = 0.0;
	const float TAX = .0625;

	//user enters amounts here
	while(usrAmount != -99){
		cout << "Please input a quantity: ";
		cin >> usrAmount;
		if (usrAmount > 0.0) {
			total += usrAmount;//adds to total if positive
			itemAmount++; //adds to user amount if positive
		}
	}
	cout << endl;
	cout << setprecision(2) << fixed; //sets fields
	//does math
	taxDue = total * TAX;
	averageCost = total / itemAmount;
	finalTotal = total + taxDue;
	
	cout << setw(20) << left << "Item Amount: " << setw(10) << right << itemAmount << endl
		<< setw(20) << left << "Average cost: " << setw(10) << right << averageCost << endl
		<< setw(20) << left << "Tax due: " << setw(10) << right << taxDue << endl
		<< setw(20) << left << "Final total: " << setw(10) << right << finalTotal << endl;
	return;
}
