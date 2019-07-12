#include <string>
#include <iostream>
using namespace std;
void ch9_2_2();

int main(){

	//ch9_2_2();
	int num;
	char strNum[15];
	cout << "enter an integer: ";
	cin >> strNum;

	cout << "You entered " << strNum << endl;

	cin.ignore();
	cin.get();

	return 0;
}

void ch9_2_2(){
	/*Modify secondVerse to play "The Name Game" 
	(a.k.a. "The Banana Song", see Wikipedia.org), 
	by replacing "(Name)" with userName but without 
	the first letter. Ex: if userName = "Katie", 
	the program prints:

	Banana-fana fo-fatie!
	*/
	string secondVerse = "Banana-fana fo-f(Name)!";
	string userName = "Katie";

	userName.erase(userName.begin()); // Removes first char from userName

	/* Your solution goes here  */
	//index is 16 , replace 6, substring is userName
	secondVerse.replace(16, 6, userName);

	cout << secondVerse << endl;
}