/*
Andrew Slade
Programming Project 1
*/

#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

void make_menu() {
	//displays start menu
	cout << "Display the entered length in: " << endl
		<< "1. Feet" << endl
		<< "2. Yards" << endl
		<< "3. Centimeters" << endl
		<< "4. Meters" << endl;
	cout << "Please enter your choice (1, 2, 3, or 4): ";
}

void convert_measurements() {
	int choice_user_one; //used for switch
	int start_length = 0; //value used to convert
	double enter_length = 0.0; // enter value
	double truncated_value = 0.0; //check value
	double conversion_value = 0.0; // allows for division
	bool stop_point = 0; // bool for default to skip calculations if necessary
	const string choice1 = "You chose Feet.";
	const string choice2 = "You chose Yards.";
	const string choice3 = "You chose Centimeters.";
	const string choice4 = "you chose Meters.";
	 
	//enter choice here
	cin >> choice_user_one;
	switch(choice_user_one){ //checks entry and prompts user
	case 1:
		cout << endl;
		cout << choice1 << endl;
		break;
	case 2:
		cout << endl;
		cout << choice2 << endl;
		break;
	case 3:
		cout << endl;
		cout << choice3 << endl;
		break;
	case 4:
		cout << endl;
		cout << choice4 << endl;
		break;
	default:
		cout << endl;
		cout << "Invalid entry" << endl;
		stop_point = 1; //sets bool to true
		break;
	}
	
	if(!stop_point){
		cout << endl;
		cout << "Any decimal values above .5 will be rounded up" << endl;
		cout << endl;
		cout << "Please enter the lenght, a positive, whole number, in inches: ";
		cin >> enter_length;
		cout << endl;
		
		//truncates enter length to force into an integer
		start_length = static_cast<int>(enter_length);
		truncated_value = start_length + 0.5; //checks for round up
		if (truncated_value < enter_length) { 
			start_length += 1; 
			conversion_value = start_length; //allows for division
		}
		else {
			conversion_value = start_length; //allows for division
		}

		//conversions here
		if(conversion_value >= 0){
			if (choice_user_one == 1) {
				cout << "Here is the value of inches: " << start_length << endl;
				cout << "Here is the value of inches in feet: " << conversion_value / 12 << endl;
			}
			else if (choice_user_one == 2) {
				cout << "Here is the value of inches: " << start_length << endl;
				cout << "Here is the value of inches in yards: " << conversion_value / 36 << endl;
			}
			else if (choice_user_one == 3) {
				cout << "Here is the value of inches: " << start_length << endl;
				cout << "Here is the value of inches in centimeters: " << conversion_value / .39370 << endl;
			}
			else{
				cout << "Here is the value of inches: " << start_length << endl;
				cout << "Here is the value of inches in meters: " << conversion_value / 39.370 << endl;
			}
		}
		else {
			cout << "Input not valid" << endl;
		}
	}
	else {
		cout << "Input error" << endl;
	}

}

int main() {

	make_menu();
	convert_measurements();

	return 0;
}