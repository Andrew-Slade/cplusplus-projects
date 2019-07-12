//preprocessor
#include <iostream>
#include <iomanip>
#include <string>
#include <iomanip>
using namespace std;

//prototypes
void doSeq(int);
int doPrompt(string);
void doPause(string);

int main() {
	int count;
	count = doPrompt("Please enter a number to do\n the Fibonacci sequence to(<94): ");
	doSeq(count);
	doPause("Please press enter to exit: ");
	return 0;
}

int doPrompt(string prompt) {
	int count;

	do{
	cout << prompt;
	cin >> count;
	} while (count > 94); //the computer doesn't like any place value larger than 94

	return count;
}

void doSeq(int userCounter) {
	int counter = 1;
	unsigned long long n1 = 0ULL;
	unsigned long long n2 = 0ULL;
	unsigned long long no = 0ULL;

	while (counter < userCounter){
		no = n1 + n2; //fibonacci equation
		cout << no << " ";
		counter++; //counter addition
		n2 = n1;
		n1 = no;
		if (n1 == 0 && counter == 2) {
			n1 = 1; //allows for a second one
			cout << n1 << " ";
		}

		int modCounter = counter % 10; //inserts end line after ten characters

		if (modCounter == 0) {
			cout << endl;

		}
	}
	return;
}
void doPause(string stopline){
	cin.ignore();
	cout << endl;
	cout << stopline;
	cin.get();

	return;
	}
