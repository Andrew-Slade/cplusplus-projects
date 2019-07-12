/*
Andrew Slade
Programming Project 3
*/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

//prototypes
double inputting();
double calculatingTime(const double, double);
double calculatingVelocity(const double, double);
void outputting(double, double, double);
//**********

int main() {
	/*
	Note to self:
	use of float value causes warning
	*/
	const double GRAVITY = 9.80665; 
	double height_recipient, velocity_recipient, time_recipient;
	height_recipient = 0.0; 
	velocity_recipient = 0.0;
	time_recipient = 0.0; 
	
	
	height_recipient = inputting();
	time_recipient = calculatingTime(GRAVITY, height_recipient);
	velocity_recipient = calculatingVelocity(GRAVITY, time_recipient);
	outputting(height_recipient, velocity_recipient, time_recipient);

	return 0;
}

double inputting(){
	double height_initial;
	string prompt = "Please enter the height that the helicopter is at: ";
	
	cout << prompt;
	cin >> height_initial;

	return height_initial;
}
double calculatingTime(const double GRAVITY, double height) {
	double time;

	time = sqrt((2 * height) / GRAVITY);

	return time;
}

double calculatingVelocity(const double GRAVITY, double time){
	double velocity_terminal;	

	velocity_terminal = GRAVITY * time;

	return velocity_terminal;
}

void outputting(double final_height, double final_veloc, double final_time){

	cout << setprecision(4) << fixed;
	cout << setw(28) << left << "Helicopter height (meters): " << setw(10) << right << final_height << endl; 
	cout << setw(28) << left << "Time(seconds): " << setw(10) << right << final_time << endl;
	cout << setw(28) << left << "Terminal velocity(m/s): " << setw(10) << right << final_veloc << endl;

	return;
}
