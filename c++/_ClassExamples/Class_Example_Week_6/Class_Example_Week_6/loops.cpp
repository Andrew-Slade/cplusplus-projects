/*
Given numRows and numCols, print a list of all seats 
in a theater. Rows are numbered, columns lettered, as 
in 1A or 3E. Print a space after each seat, including 
after the last. Ex: numRows = 2 and numCols = 3 prints:

1A 1B 1C 2A 2B 2C
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

int main() {
	int numRows = 2;
	int numCols = 3;

	// Note: You'll need to define more variables
	cout << "Enter the number of rows: ";
	cin >> numRows;
	while (numRows < 1 || numRows > 26){
		//for input from 1 to 26 to get out of here
		cout << "Error, 1 to 26 please: ";
		cin >> numRows;
	}
	cout << "Enter the number of columns: ";
	cin >> numCols;
	while (numCols < 1 || numCols > 26){
		//for input from 1 to 26 to get out of here
		cout << "Error, 1 to 26 please: ";
		cin >> numCols;
	}

	/* Your solution goes here  */
	for (int i = 1; i <= numRows; i++){
		for (int j = 65; j < (numCols + 65); j++){
			cout << i << static_cast<char>(j) << " ";
		}
		cout << endl;
	}

	cout << endl << endl;

	//get random numbers and display them
	int count = 0;
	for (int i = 0; i < 100; i++){
		cout << setw(4) << rand() % 20 + 1;
		count++;
		if (count == 10){
			cout << endl;
			count = 0;
		}
	}

	return 0;
}