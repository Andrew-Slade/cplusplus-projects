#include <iostream>
#include <cmath>
#include <iomanip>
#include <ios>
using namespace std;

int main() {
	const double piVal = 3.14159;
	double sphereVolume = 0.0; //solution needed
	double sphereRadius = 0.0;
	int y = 4; // not for main program
	int x = 10; //not for main program


	double temp = 12310111111.2105; // slip example

	cout << temp << endl; //sci. not. example

	sphereRadius = 100.0;
	// need to use both fixed and setprecision()

	cout << setprecision(3) << fixed; // fixes output after decimal to three places

	sphereVolume = (4.0 / 3.0)* piVal * pow(sphereRadius, 3); // solution with cmath example

	cout << "Sphere volume: " << sphereVolume << endl; //output
	cout << temp << endl; // fixed examp for float temp

	cout << x / y;
	cout << static_cast<float>(x) / y << endl; // example of static_cast to turn an integer into a float

	char ch = 65;
	cout << "My character is: " << ch << endl; //character manipulation
    //shows character instead of number w/o stat_cast shows 66 below
	cout << "The next character is: " << static_cast<char>(ch + 1) << endl;
	ch += 1; //changes char A (65) into B (66)
	cout << "Next output is: " << ch << endl;
	cout << endl;

	cout << "The number of bytes used by each type \n: ";
	cout << "Integer " << sizeof(int) << endl;
	cout << "Float: " << sizeof(float) << endl;
	cout << "Character " << sizeof(char) << endl;
	cout << "Double :" << sizeof(double) << endl;
	cout << "Short: " << sizeof(short) << endl;
	cout << "100 doubles need " << sizeof(double) * 100 << endl; // calculates necessary drive size to store 100 doubles

	return 0;
}