/*
Andrew Slade
Class Example Week 9
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//Prototypes
void playWithFileOutput();
//**********


int main() {
	playWithFileOutput();
	return 0;
}

void playWithFileOutput() {
	string recieved = " ";
	string numbers = " ";
	string temp, temp2;

	ofstream newFile("testforfileoutput.txt");
	newFile << "Hello, World!" << endl << "     5    7   8    9" << endl;
	newFile.close();
	//output above, input under
	ifstream inFile("testforfileoutput.txt"); //initializes
	if (inFile.is_open()) {
		//all processing here
		getline(inFile, recieved);
		getline(inFile, numbers);
		temp = recieved;
		temp2 = numbers;
		cout << temp << temp2 << endl;
	}
	else {
		cout << "the file failed to open." << endl;
	}
	return;
}
