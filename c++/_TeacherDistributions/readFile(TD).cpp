//read in from existing file

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void readMidfile();

int main(){

	readMidfile();
	return 0;
}

void readMidfile(){
	//open the file
	//to read
	string name, temp;
	string base, exp, result;
	double b, e, r;
	ifstream inFile("midterm.txt");
	//when you read check that the file opened
	if (inFile.is_open()){
		//all processing goes here
		getline(inFile, name);
		getline(inFile, base);
		getline(inFile, exp);
		getline(inFile, result);

		inFile.close();
		cout << name << endl
			<< base << endl
			<< exp << endl
			<< result << endl;

		inFile.open("midterm.txt");
		getline(inFile, name);
		inFile >> temp;
		inFile >> b;
		inFile >> temp;
		inFile >> e;
		inFile >> temp;
		inFile >> r;

		cout << name << endl;
		cout << b << endl
			<< e << endl
			<< r << endl;
		inFile.close();

	}
	else {
		cout << "The file failed to open\n";
	}
}