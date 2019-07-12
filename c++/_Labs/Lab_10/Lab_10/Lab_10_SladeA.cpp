/*
Andrew Slade
Lab 10
*/

//Directives
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//----------

//Structures
struct myDate {
	int month, day, year;
};
//----------

//Prototypes
void initialize(string fileName);
void writeDates(fstream &f);
int getNum(string prompt, int low, int high);
void outputDate(myDate d);
void readDate(fstream &f);
myDate getDate();
//----------

//main
int main() {
	string fileName = "dates.ran";
	fstream f(fileName, ios::in);
	int option = 0;
	f.open(fileName, ios::in);
	if (f) {
		f.close();
	}
	else {
		initialize(fileName);
	}

	f.close();

	//menue
	f.open(fileName, ios::in | ios::out | ios::binary);

	if (f) {
		do {
			cout << "1. Write dates\n 2. read dates\n 3.quit" << endl;
			cin >> option;
			if (option == 1) {
				writeDates(f);
			}
			else if (option == 2) {
				readDate(f);
			}

		} while (option != 3);
	}
	else cout << "not open in main\n";
	f.close();

	cout << "press enter to exit: ";
	cin.ignore();
	cin.get();
	return 0;
}

//initializes file to contain default dates
void initialize(string fileName) {
	myDate md = { 0,0,0 };

	// default dates assigned above
	fstream ranFile(fileName, ios::out | ios::binary); // if file open for in and out, file not created
	//open file for  binary access
	for (int i = 0; i < 20; i++) {
		// write out to file
		ranFile.write(reinterpret_cast<char*>(&md), sizeof(md));
	}
	ranFile.close();

	return;
}

//writes to a file
void writeDates(fstream &f){
	int recordNum;
	myDate md;

	cout << "Please enter a number between 1 and 20: ";
	cin >> recordNum;
	
	while (recordNum >= 1 && recordNum <= 20) {
		md = getDate();

		f.seekp(sizeof(myDate) * (recordNum - 1), ios::beg);
		//g = get, p = put seekp = seek to put(how many to move, from where)
		f.write(reinterpret_cast<char*>(&md), sizeof(md));
		cout << "Please enter next record num, 1 - 20, 0 to quit: ";
		cin >> recordNum;
	}

	return;
}

//recieves usr input
int getNum(string prompt, int low, int high)
{
	int x;
	cout << prompt;
	cin >> x;

	while (x < low || x > high)
	{
		cout << "Error, invalid, must be between " << low << " and " << high << ": ";
		cin >> x;
	}
	return x;
}

//output date
void outputDate(myDate d){
	cout << d.month << "/" << d.day << "/" << d.year << endl;
	return;
}

//reads file
void readDate(fstream &f){
	int recordNum;
	myDate md;

	cout << "Please enter a number between 1 and 20: ";
	cin >> recordNum;

	if (f) {
		while (recordNum >= 1 && recordNum <= 20) {

			f.seekg(sizeof(myDate) * (recordNum - 1), ios::beg);
			//g = get, p = put seekp = seek to put(how many to move, from where)
			f.read(reinterpret_cast<char*>(&md), sizeof(md));

			outputDate(md);

			cout << "Please enter next record num, 1 - 20, 0 to quit: ";
			cin >> recordNum;
		}
	}
	else
		cout << "not open" << endl;
	 
	return;
}

//modify myDate structure
myDate getDate(){
	myDate d;
	d.month = getNum("Enter the month: ", 1, 12);
	d.day = getNum("Enter the day: ", 1, 30);
	d.year = getNum("Enter the year: ", 1900, 2050);

	return myDate();
}
