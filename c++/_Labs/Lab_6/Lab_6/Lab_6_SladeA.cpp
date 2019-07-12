/*
Andrew Slade
Lab 6: Array Lab 
*/

#include<iostream>

using namespace std;
//Prototypes
void putOutValues(int[], const int);
//**********

int main() {
		//1.	Declare an array of type integer with 5 elements named iNumbers.
	int iNumbers[5];
		//2.	Declare an array of type float with 14 elements named flNumbers.
	float flNumbers[14];
		//3.	Declare an array of type integer with 5 elements named iValues 
		//and initialize it with the values 2, 4, 6, 8, 10.
	int iValues[5] = { 2, 4, 6, 8, 10 };
		//4.	Declare an array of type float with 3 elements named flValues
		//and initialize it with the values 1, 3, 5.
	float flValues[3] = { 1.0, 3.0, 5.0 };
		//5.	Write a statement to output the third element of array iValues.
	cout << iValues[2] << endl;
		//6.	Write a statement to output the first element of array flValues.
	cout << flValues[0] << endl;
		//7.	Write a statement to store the value 12 in the last
		//element of array iValues.
	iValues[4] = 12;
		//8.	Write a statement to store the value 7 in the 2nd 
		//element of flValues.
	flValues[1] = 7.0;

		//9.	Declare an integer variable named index. 
	int index;
		//for the following questions you will use index to subscript
		//the the array not a literal value as you have used before.

		//10.	Assign index the correct literal value to access the third element 
		//of an array. Using variable index as the subscript output the 
		// third value of the iValues.
	index = 2;
	cout << iValues[index] << endl;
		//11.	Assign index the correct value to access the second element of
		// an array. Using variable index as the subscript, output the second 
		// value of the flValues.
	index = 1;
	cout << flValues[index] << endl;

		/*14.	Initialize index to be used as a loop counter.
		Write a while loop that will output all the elements of iValues.*/
	index = 0;
	const int SIZE = 4;
	while (index <= SIZE) {
		cout << iValues[index] << endl;
		index++;
	}

		/*15.	Initialize index to be used as a loop counter.
		Write a while loop that will output all the elements of flValues.*/
	index = 0;
	
	const int SIZEF = 3;
	while (index < SIZEF) {
		cout << flValues[index] << endl;
		index++;
	}

		//16.	Write a for loop to output all the elements of iValues.
	int i;
	for (i = 0; i < SIZE; i++) {
		cout << iValues[i] << endl;
	}
		//17.	Write a for loop to output all the elements of flValues.
	for (i = 0; i < SIZEF; i++) {
		cout << flValues[i] << endl;
	}
		//18 and 19. copy the code from question 16 and write the header for the function
		//create the prototype before main


		//20. call the function you wrote for 18. Send the iValues array as the argument
	putOutValues(iValues, SIZE);

	cout << "Press enter to continue...";
	cin.ignore();
	cin.get();
	return 0;

	
}

void putOutValues(int iValuesF[], const int SIZEI){
	int k = 0;
	for (k = 0; k < SIZEI; k++) {
		cout << iValuesF[k] << endl;
	}
	return;
}
