/*
Andrew Slade
Programming Project 4
*/

#include <iostream> //cin, cout, endl, etc
#include <stdlib.h> //rand() , srand()
#include <iomanip> //setw(), setprecision, etc
#include <time.h> // used in srand() to create better psuedo random values
using namespace std;

//Prototypes
void seedArray(int array[], const int SIZEA);
int addArrayValues(const int INTARRAY[], const int ASIZE);
double getAverage(const int ARRSIZE, int arrTotal);
void doOutput(const int ARRAY[], int total, double average);
//**********

int main() {
	const int SIZE = 20; //total elements
	int initArray[SIZE]{ 0 }; //initial array initialized to 0
	int totalValue;
	double avrg;
	//default value initialization
	avrg = 0.0;
	totalValue = 0;
	//****************************

	//function calls
	seedArray(initArray, SIZE); //seeds array
	totalValue = addArrayValues(initArray, SIZE); //gets total of arrays's values
	avrg = getAverage(SIZE, totalValue); //gets average of array's values
	doOutput(initArray, totalValue, avrg); //does output
	//**************

	return 0;
}

//seeds array with random integers
void seedArray(int array[], const int SIZEA){
	int c;
	srand(time(NULL)); //initializes rand()

	for (c = 0; c < SIZEA; c++) {
		array[c] = rand() % 101;
	}

	return;
}

//adds all array values together then returns total value
int addArrayValues(const int INTARRAY[], const int ASIZE){
	int total, i;
	i = 0;
	total = 0;

	while (i < ASIZE) {
		total += INTARRAY[i];
		i++;
	}

	return total;
}

//gets average and returns double to retain decimal portion
double getAverage(const int ARRSIZE, int arrTotal){
	double dbTotal;
	dbTotal = static_cast<double>(arrTotal);
	
	return (dbTotal / ARRSIZE);
}

//does output
void doOutput(const int ARRAY[], int total, double average){
	int v, modRow;
	v = 0;
	modRow = 0;

	cout << setprecision(3) << fixed; //allows average to be output in full

	cout <<"Here is the array of values: " << endl;
	//does output of array
	while (v < 20) {
		cout << setw(4) << ARRAY[v] << " ";
		modRow = (v + 1) % 5; 
		if (modRow == 0) {
			cout << endl;
		}
		v++;
	}

	//outputs average and total values well organized
	cout << endl;
	cout << setw(22) << left << "Here is the average: "
		 << setw(7) << right <<average << endl;
	cout << setw(22) << left << "Here is the total: "
		 << setw(7) << right << total << endl;

	return;
}
