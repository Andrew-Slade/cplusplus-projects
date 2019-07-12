#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
	const double piVal = 3.14159;
	double sphereVolume = 0.0;
	double sphereRadius = 0.0;

	const double taxRate = .0625;

	float temp = 5;
	cout << temp << endl;
	//set the precision set to 5 to the right of . by default
	cout << setprecision(3) << fixed;

	cout << temp << endl;

	sphereRadius = 10.0;
	//you need to use both fixed and setprecision()

	cout << setprecision(2);
	/* Your solution goes here  */
	sphereVolume = (4.0 / 3.0)* piVal * pow(sphereRadius, 3);

	int x = 4, y = 10, z;

	z = pow(x, y);
	cout << "Example of integers: " << z << endl;

	cout << y / x << endl;
	cout << static_cast<float>(x) / y << endl;

	char ch = 65;
	cout << "my character is : " << ch << endl;
	cout << "the next character is: " 
		<< static_cast<char>(ch + 1) << endl;
	ch += 1; //same as ch = ch + 1;
	cout << "Next output is: " << ch << endl;

	cout << "Sphere volume: " << sphereVolume << endl;

	double total = 546.89;
	cout << "The tax is " << total * taxRate << endl;

	//used to calculate storage or memory needs.
	//and when working with files
	cout << "The number of bytes used by each data type\n";
	cout << "Integer: " << sizeof(int) << endl;
	cout << "Float: " << sizeof(temp) << endl;
	cout << "Character " << sizeof(ch) << endl;
	cout << "Double" << sizeof(double) << endl;
	cout << "short " << sizeof(short) << endl;
	cout << "100 doubles need " << sizeof(double) * 100 << endl;

	return 0;
}