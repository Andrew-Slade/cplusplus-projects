#include <iostream>
using namespace std;
void fillArray(double* array, const int SIZE);
void outputArray(double array[], const int SIZE);

int main() {
	const int SIZE = 25;
	double array[SIZE];
	int x;
	double y;
	int* iptr;
	double* doubleptr;
	iptr = &x;
	doubleptr = &y;
	x = 5;
	y = 0;

	cout << "The address of x is " << iptr << endl;
	cout << "The value stored at that address is " << *iptr << endl;
	cout << *iptr << " squared is " << *iptr * *iptr << endl;

	array[SIZE] = 0;
	doubleptr = array;
	cout << "output just array " << doubleptr << endl; //can also use array

	doubleptr = array; //mem address to mem address

	fillArray(array, SIZE);
	outputArray(doubleptr, SIZE);

	return 0;
}
//pointer notation
void fillArray(double *array, const int SIZE) {
	for (int i = 0; i < SIZE; i++) {
		array[i] = (i + 1) * 2;
	}
	return;
}
//array notation
void outputArray(double array[], const int SIZE) {
	for (int i = 0; i < SIZE; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
	return;
}