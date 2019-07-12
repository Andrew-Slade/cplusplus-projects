/*
Andrew Slade
Lab 2 
*/

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	//part 1
	//variable initialization
	static float GRAVITY = 9.80665; // NEEDS TO BE const float
	float time_init = 0.0;
	float height_init = 0.0;
	float velocity_init = 0.0;
	float velocity_termin = 0.0;
	float miles_driven = 0.0;
	float gallons_of_gas = 0.0;
	float miles_p_gallon = 0.0;
	string part_1 = "Part 1";
	string part_2 = "Part 2";
	string part_3 = "Part 3";
	string user_input_p2 = "";

	cout << part_1 << endl;
	cout << "Please enter the amount of miles that were driven: ";
	cin >> miles_driven;
	cout << "Now please enter the gallons of gas used: ";
	cin >> gallons_of_gas;
	miles_p_gallon = miles_driven / gallons_of_gas;
	cout << setprecision(1) << fixed;
	cout << "Here is the amount of miles per gallon that the car uses: " << miles_p_gallon << endl;
	cin.ignore();
	cout << endl;

	//part 2
	cout << part_2 << endl;
	cout << "Please enter a sentance: ";
	getline(cin, user_input_p2);
	cout << user_input_p2 << endl;
	cout << endl;
	
	//part 3
	cout << part_3 << endl;
	cout << "Please enter the height that the helicopter is at: ";
	cin >> height_init;
	time_init = sqrt((2 * height_init) / GRAVITY);
	velocity_termin = GRAVITY * time_init;
	cout << setprecision(4) << fixed;
	cout << setw(28) << left << "Helicopter height (meters): " << setw(10) << right << height_init << endl;
	cout << setw(28) << left << "Time(seconds): " << setw(10) << right << time_init << endl;
	cout << setw (28) << left << "Terminal velocity(m/s): " << setw(10) << right << velocity_termin << endl;

	return 0;
}

