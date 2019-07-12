/*
Andrew Slade
Programming Project 5
*/

//preprocessors
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
//-------------

//structure
struct Database {
	char elName[22];
	char symbol[4];
	char elNum[4];
	char meltPoint[12];
	char boilPoint[8];
};
//---------

//prototypes
void readInto(Database Element[], const int aSIZE);
int writeMenue();
void outputChart(Database Element[], const int aSize);
void writeBin(Database Element[], const int aSIZE, bool &wrote);
void readBin(Database Element[], const int aSIZE);
//----------

//main
int main() {
	const int SIZE = 118;
	Database elemData[SIZE];
	int usrInput = 0;
	bool written = false;

	//function calls
	readInto(elemData, SIZE);

	do {
		usrInput = writeMenue();
		//decision structure
		if (usrInput == 1) {
			outputChart(elemData, SIZE);
		}
		else if (usrInput == 2) {
			writeBin(elemData, SIZE, written);
		}
		else if (usrInput == 3){
			if(written){
				readBin(elemData, SIZE);
			}
			else {
				cout << "Please select 2 before 3." << endl;
			}
		}
	} while (usrInput != 4);
	
	//--------------
	
	cout << "Press enter to exit: ";
	cin.ignore();
	cin.get();

	
	return 0;
}

//reads in data
void readInto(Database Element[], const int aSIZE) {
	fstream inFile("elementsAssign.txt", ios::in);
	
	if (inFile) {
		for (int i = 0; i < aSIZE; i++) {
			inFile.getline(Element[i].elName, 22);
			inFile.getline(Element[i].symbol, 4);
			inFile.getline(Element[i].elNum, 4);
			inFile.getline(Element[i].meltPoint, 12);
			inFile.getline(Element[i].boilPoint, 8);
		}
		inFile.close();
	}
	else {
		cout << "File could not be read." << endl;
	}
	return;
}

//writes menue
int writeMenue() {
	int usrChoice;
	cout << "1. Output element chart" << endl
		<< "2. Write random file" << endl
		<< "3. Read random file" << endl
		<< "4. End program" << endl;
	cin >> usrChoice;
	cin.ignore();
	return usrChoice;
}

//outputs regular array
void outputChart(Database Element[], const int aSize) {
	int sizes[5] = { 22,4,4,12,8 };

	//Header
	cout << setw(sizes[0]) << left << "Name" 
		<< setw(6) << left << "Smbl"
		<< setw(6) << left << "Num"
		<< setw(sizes[3]) << left << "Melt Pnt"
		<< setw(sizes[4]) << left << "Boil Pnt" << endl;
	//------

	//info
	for (int i = 0; i < 118; i++) {
		cout << setw(sizes[0]) << left << Element[i].elName 
			<< setw(sizes[1]) << left << Element[i].symbol
			<< setw(sizes[2]) << right << Element[i].elNum 
			<< setw(sizes[3]) << right << Element[i].meltPoint
			<< setw(sizes[4]) << right << Element[i].boilPoint << endl;
	}
	cout << endl << "----------------" << endl;
	//----

	return;
}

//writes binary file
void writeBin(Database Element[], const int aSIZE, bool &wrote){
	fstream binFile("Elements.ran", ios::out | ios::binary);

	if (binFile) {
		binFile.seekp(sizeof(Element), ios::beg);
		binFile.write(reinterpret_cast<char*>(Element), sizeof(Database) * 118);
		binFile.close();
		wrote = true;
	}
	else {
		cout << "File could not be read." << endl;
	}
	return;
}

//reads binary file
void readBin(Database Element[], const int aSIZE) {
	fstream binFile("Elements.ran", ios::in | ios::binary);
	Database temp[118];
	
	if (binFile) {
		binFile.seekg(sizeof(Element), ios::beg);
		binFile.read(reinterpret_cast<char*>(temp), sizeof(Database) * 118);

		outputChart(temp, aSIZE);
		
		binFile.close();
	}
	else {
		cout << "File could not be read." << endl;
	}
	return;
}
