#include <string>
#include <iostream>
using namespace std;

bool tryParse(char strNum[], int &num);

int main(){

	//ch9_2_2();
	int num;
	char strNum[15];
	bool isOK;
	cout << "enter an integer: ";
	cin >> strNum;

	isOK = tryParse(strNum, num);
	while(! isOK){
		cout << "enter an integer: ";
		cin >> strNum;
		isOK = tryParse(strNum, num);
	}

	//now that num has a value output a message to the user
	//tell them what their number is and then output the number 
	//squared and then cubed.

	cin.ignore();
	cin.get();

	return 0;
}

//put definition of tryParse() here

bool tryParse(char strNum[], int &num){



}

