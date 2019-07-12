/*
*Andrew Slade
*MidTerm
*/

//preprocessors
#include<iostream>
#include<cmath>
#include<iomanip>
#include<string>
using namespace std;

int main() {
	string usrName = "Initialized";
	string prompt = "Please enter ";
	int afterDecimal;
	int count = 0;
	char usrContinue = 'y';
	double base, exponent, result;
	base = 0.0;
	exponent = 0.0;
	result = 0.0;
	
	cout << prompt << "your first and last name: ";
	getline(cin, usrName);
	//note for self: built here | status:sucessful

	do {
		cout << prompt << "the number you wish\n"
			<< "to use as the base for an exponent: ";
		cin >> base;
		if (base > 25 || base < 1) {
			cout << "Invalid input" << endl;
		}
	} while (base > 25 || base < 1);
	//note for self: built here | status:sucessful

	do {
		cout << prompt << "the number you wish\n"
			<< "to use as the exponent: ";
		cin >> exponent;
		if (exponent > 10 || exponent < 1) {
			cout << "Invalid input" << endl;
		}
	} while (exponent > 10 || exponent < 1);
	//note for self: built here | status: sucessful

	result = pow(base, exponent);

	if (result <= 1000) {
		afterDecimal = 3;
	}
	else if (result < 1000000) {
		afterDecimal = 2;
	}
	else if (result < 4000000) {
		afterDecimal = 1;
	}
	else {
		afterDecimal = 0;
	}
	cout << setprecision(afterDecimal) << fixed;
	//note for self: built here | status: 

	//output
	cout << setw(12) << left << "Name: "
		<< setw(15) << right << usrName << endl
		<< setw(12) << left << "Base: "
		<< setw(15) << right << base << endl
		<< setw(12) << left << "Exponent: "
		<< setw(15) << right << exponent << endl
		<< setw(12) << left << "Result: "
		<< setw(15) << right << result << endl;
	//note for self: built here | status: sucessful

	return 0; 
}