//function test

#include <iostream>
using namespace std;
void play_with_bool(); //declares that there is a function later in the file (known as a prototype)

//function definition without prototype
void play_with_switch() {

	//swtich works with integrals
	char ch;
	int option;
	int size;
	
	cout << "Enter a, b, c, or d: ";
	cin >> ch;
	//start the logic structure
	switch (ch) {
		case 'a': //single quotes needed for case w/ character
			cout << "You selected a\n";
			break;

		case 'b': //single quotes needed for case w/ character
			cout << "You selected b\n";
			break;

		case 'c': //single quotes needed for case w/ character
			cout << "You selected c\n";
			break;

		case 'd': //single quotes needed for case w/ character
			cout << "You selected d\n";
			break;
		
		default: 
			cout << "Please enter a, b, c, or d.";
			break;
	}
	//twelve days of christmas
	cout << "Which day are you buying? ";
	cin >> option;
	switch (option) {
	//partridge in a pear tree
	case 5: 
		cout << "five golden rings\n";
		cout << "Size 1, 2, or 3? ";
		cin >> size;
		if (size == 3) {
			cout << "That is a man's size" << endl;
		}
		else if (size == 2) {
			cout << "That is a woman's size" << endl;
		}
		else if (size == 1) {
			cout << "That is a child's size" << endl;
		}
		else {
			cout << "Try again later" << endl;
		}
		break;
	//two turtle doves
	case 4:
		cout << "four mocking birds\n";
		break;
	//three french hens
	case 3:
		cout << "three French hens";
		break;
	//four mocking birds
	case 2:
		cout << "two turtle doves\n";
		break;
	//five golden rings
		case 1:
		cout << "patridge in a pear tree";
		break;
	default:
		cout << "I havent programmed that yet. \n";
		break;
	}

	
}

int main() {
	//starts processing
	//call function(s)
	play_with_switch(); // void not present in calling function
	play_with_bool(); // calls function play with bool

	return 0;
}

void play_with_bool() { //function header,void returns nothing, () gets nothing
	bool t_f;
	int x = 0.0;

	cout << "Enter a number greater than ten please: ";
	cin >> x;

	if (x > 10) {
		t_f = 1; //true
	}
	else {
		t_f = 0; //false
	}

	if (t_f) {  //checks to se if t_f is true
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}
}