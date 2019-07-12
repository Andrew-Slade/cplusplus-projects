/*
Andrew Slade
Lab_8
*/

#include <iostream>
#include <stdlib.h>
#include <ctype.h>
#include <cmath>
#include <iomanip>
using namespace std;

//Prototypes
bool tryParse(char strNum[], int &num);
//**********

int main() {
	int num;
	char strNum[15];
	bool isOK;

	do{
		cout << "enter a positive integer: ";
		cin >> strNum;
		isOK = tryParse(strNum, num);
		if (!isOK) {
			cout << "Input error: not a number" << endl; //explains input error to user
		}
	}while(!isOK); 

	//fixes output and separates to cells
	cout << fixed << setprecision(0);
	cout << setw(28) << left << "Your number is: " << setw(15) << right << num << endl
		 << setw(28) << left << "Your number squared is: " << setw(15) << right << pow(num, 2) << endl
		 << setw(28) << left << "Your number cubed is: " << setw(15) << right << pow(num, 3) << endl;

	cin.ignore();
	cin.get();

	return 0;
}

bool tryParse(char strNum[], int &num) {
	int index, length;
	bool allDigits;
	char stop = 'n';
	
	length = strlen(strNum); //grabs length
	allDigits = true; //initializes boolean

	while(stop == 'n'){
		for (index = 0; index <= length; index++) {
			if (isdigit(strNum[index])){
				stop = 'n';
				allDigits = true;
			}
			else if (strNum[index] == '\0') {
				/*
				Keeps computer from 
				reading null character
				as part of input
				*/
				stop = 'y';
			}
			else {
				allDigits = false;
				stop = 'y';
			}
		}	
	}
	if (allDigits == true) {
		num = atoi(strNum);
		/*
		converts all characters
		that are numbers
		into usable numbers
		*/
	}
	else {
		num = 0;
	}

	return allDigits;
}

