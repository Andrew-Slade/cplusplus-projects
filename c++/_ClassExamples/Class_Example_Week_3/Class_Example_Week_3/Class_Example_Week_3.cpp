//preprocessors
#include <iostream>
#include <string>
using namespace std;

//main function
int main()
{ 
	// variable initialization
	char letterStart = 'a';

	//output section
	cout << "Enter a character" << endl; //Prompt User
	cin >> letterStart; //their character
	cout << "Here is your character: " << letterStart << endl; //outputs their character
	cout << "Here is the Next character: " << static_cast<char>(letterStart += 1) << endl; //outputs next character
	cout << "Here is the number that corresponds with your character: " << static_cast<int>(letterStart -= 1) << endl; //resets number value of letter start
	cout << "Here is the number that corresponds with your character: " << static_cast<int>(letterStart += 1) << endl; //outputs next number value
	
	 //var
	string str1, str2, str3;
	string fullName;
	
	cout << "Enter a word: ";
	cin >> str1;
	cout << "Enter a sentance: ";
	cin.ignore(5, '\n'); //clears buffer and ignores 5 characters and enter
	getline(cin, str2); //gets entire string

	cout << str1 << endl;
	cout << str2 << endl;
	
	cout << "Enter a word again: "; //if prompt for sentance, only first word goes to buffer ********
	cin >> str3;// Does Not Remove Enter Key if cin is used ******* to fix, use ignore
	cin.ignore(); // fixes above line to allow for getline() below
	cout << "Str3 is: " << str3 << endl; 
	
	cout << "Enter your full name: ";
	getline(cin, fullName);
	cout << "It works, " << fullName << "!" << endl;

	//program end
	return 0;
}