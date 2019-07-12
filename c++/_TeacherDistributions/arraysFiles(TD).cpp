//arrays with maybe some file work
#include <iostream>
#include <fstream>
using namespace std;

float getValue();
void writeFile(const float numbers[], const int SIZE);

int main(){
	//most arrays will be defined in main
	float numbers[10]; //simple function definition
	//stores 10 number so size is 10

	//enter a value from the keyboard
	//have a variable count from 0 to 9
	for (int count = 0; count < 10; count++){
		cout << "Enter a float: ";
		cin >> numbers[count];
		while (numbers[count] < 0){
			cout << "Error: re-enter > 0 ";
			cin >> numbers[count];
		}
	}
	//go to a function to write the values to a file
	writeFile(numbers, 10);
	//replace code above with function call
	/*for (int count = 0; count < 10; count++){
		numbers[count] = getValue();
	}*/

	

	return 0;
}

void outToScreen(const float numbers[]){
	int count;
	for (count = 0; count <= 9; count++){
		cout << count + 1 << "  " << numbers[count] << endl;
	}
}
void writeFile(const float numbers[], const int SIZE){
	//output the values to file, change all elements
	//to 0
	ofstream fout("C:\\Users\\sgrever\\Documents\\flNumbers2.txt");

	for (int count = 0; count < SIZE; count++){
		fout << numbers[count] << endl;
	}

	fout.close();
}

float getValue(){
	float num;
	cout << "Enter a float: ";
	cin >> num;
	while (num < 0){
		cout << "Error: re-enter > 0 ";
		cin >> num;
	}
	return num;
}