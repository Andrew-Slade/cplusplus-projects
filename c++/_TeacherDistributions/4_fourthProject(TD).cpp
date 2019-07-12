#include <iostream>
#include <string>
using namespace std;

int main() {

	/* Your solution goes here  
	char letterStart;

	//prompt the user
	cout << "Enter a character: ";
	cin >> letterStart;

	cout << letterStart;*/
	//output the next
	/*letterStart += 1;
	cout << letterStart;

	cout << static_cast<char>(letterStart + 1);*/

	//A user types a word and a number.
	//Read them into the provided variables.
	//Then print : word_number.End with newline.
	//Example output if user entered : Amy 5

	//Amy_5
	/*
	string userWord, str1, str2, str3;
	int userNum = 0;

	cin >> userWord >> userNum;
	cin >> userNum;

	cout << userWord << "_" << userNum << endl;*/

	string str1, str2, str3;
	cout << "Enter a word: ";
	cin >> str1;
	cout << "Enter a sentence: ";
	//use getline() inplace of >>
	cin.ignore(5, '\n');
	getline(cin, str2);

	cout << str1 << endl;
	cout << str2 << endl;

	string fullName;
	cout << "Enter your full name: ";
	getline(cin, fullName);
	cout << fullName << endl;

	cout << "Enter a word again: ";
	cin >> str3;

	cout << "str3 is " << str3 << endl;
	cout << "enter your full name again: ";
	cin.ignore();
	getline(cin, fullName);
	cout << "It worked " << fullName << endl;



	return 0;
}