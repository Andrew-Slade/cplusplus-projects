//still working with sequential
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

void fillArray(int nums[], const int SIZE);
void writeSequential(const int nums[], const int SIZE);
void outputArray(int nums[], const int SIZE);
void readSequential();
void readBinary(int nums[], const int SIZE);
void writeBinary(int nums[], const int SIZE);

int main() {

	const int SIZE = 20;
	int numbers[SIZE];
	int numbers2[SIZE];
	cout << numbers << endl;
	fillArray(numbers, SIZE);
	writeBinary(numbers, SIZE);
	readBinary(numbers2, SIZE);
	//writeSequential(numbers, SIZE);
	outputArray(numbers2, SIZE);
	//readSequential();

	return 0;
}

void writeBinary(int nums[], const int SIZE) {
	//open the file to write binary
	fstream outBinary("numbers.ran", ios::out | ios::binary);
	//caluclate the bytes in the array
	int numBytes = sizeof(int)* SIZE;

	char* ptr = reinterpret_cast<char*>(nums);
	//write
	outBinary.write(ptr, numBytes);

	outBinary.close();
}

void readBinary(int nums[], const int SIZE) {
	//open to read binary
	fstream inBinary("numbers.ran", ios::in | ios::binary);
	if (inBinary) {
		//open file the array
		inBinary.read(reinterpret_cast<char*>(nums),
			sizeof(int)* SIZE);
		inBinary.close();
	}
	else
		cout << "File failed to open\n";
}

void fillArray(int nums[], const int SIZE) {
	srand(time(0));
	for (int i = 0; i < SIZE; i++) {
		nums[i] = rand() % 101;
	}
}

//write out to file
//sequencial access file
void writeSequential(const int nums[], const int SIZE) {
	//one number per line
	//open the file
	//fstream outfile("numbers.txt", ios::out | ios::app);
	fstream outfile("numbers.txt", ios::out);

	//loop through array to write to file
	for (int i = 0; i < SIZE; i++) {
		outfile << nums[i] << endl;
	}

	outfile.close();
}

void readSequential() {
	int x;
	//open the file to read
	fstream infile("numbers.txt", ios::in);
	//check if the file opened
	if (infile) {
		//the file exists and is open
		//read a number, output and then read
		int counter = 0;
		infile >> x;
		while (!infile.eof()) {
			cout << setw(5) << x;
			counter++;
			if (counter == 5) {
				cout << endl;
				counter = 0;
			}
			//read the next number from the file
			infile >> x;
		}

		infile.close();

	}
	else
		cout << "File failed to open\n";

}

void outputArray(int nums[], const int SIZE) {
	//do 4 row 5 columns
	//modulus solution
	for (int i = 0; i < SIZE; i++) {
		cout << setw(5) << nums[i];
		if ((i + 1) % 5 == 0) {
			cout << endl;
		}
	}

}