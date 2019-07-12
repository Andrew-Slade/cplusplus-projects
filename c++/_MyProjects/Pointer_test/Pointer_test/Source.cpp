#include <iostream>
using namespace std;
//prototype
int First(int, int);
int notTheFirst(int, int);
int doesSomething(int, int, int (*function)(int, int));
//

int main() {
	int notPointer = 100;
	int first, second;
	int* pointer = 0;
	int finishedFunctionCall;
	pointer = &notPointer;
	first = 20;
	second = 10;
	finishedFunctionCall = doesSomething(first, second, notTheFirst);
	struct myStruct {
		int item = 0;
		int item2 = 10;
		int item3 = 15;
	};
	myStruct strct;
	myStruct *pstrct;
	pstrct = &strct;
	pstrct->item = 500;

	/*
	pointer is equal to the value of the adress of notPointer
	the values of pointer is now linked to notPointer
	*pointer adresses notPointer's values of 100
	*pointer changes notPointer to 5
	*/

	cout << notPointer << endl;
	cout << &notPointer << endl;
	*pointer = 5;
	cout << *pointer << endl;
	cout << notPointer << endl;
	cout << pointer << endl;
	cout << finishedFunctionCall << endl;
	cout << endl;
	cout << pstrct->item << endl << pstrct->item2 << endl << pstrct->item3;
	return 0;
}

int First(int a, int b){
	cout << "Hits here at first." << endl;

	return (a + b);
}
int notTheFirst(int a, int b){
	cout << "Hits here at notTheFirst." << endl;

	return (a / b);
}
int doesSomething(int a, int b, int (*functionHit)(int, int)){
	int functionCall;
	cout << "Hits here at doesSomething, too" << endl;
	functionCall = (*functionHit)(a, b);

	return (functionCall);
}