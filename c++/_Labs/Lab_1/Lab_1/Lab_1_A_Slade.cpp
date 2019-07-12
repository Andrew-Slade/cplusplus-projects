/*
Andrew Slade
Lab_1_Chapter_2
*/

#include <iostream>
#include<iomanip>
#include<string>
using namespace std;

int main() {
	//output strings initialized
	string myname = "Andrew Slade";
	string labnum = "Programming Lab 1";
	string date = "2/1/2016";

	//Part 1
	cout << "Part I" << endl;
	cout << endl; 
	cout << myname << endl << labnum << endl << date;
	cout << endl;
	cout << endl;
	//end part 1


	// Part 2 :

	cout << "Part II" << endl;
	cout << endl;

	//second part variables
	//integers
	int fir_intval = 7;
	int sec_intval = 1;
	//floats 
	float fir_float = 78.25;
	float sec_float = 34.3;
	float thi_float = 0.00;

	cout << fir_intval << " * " << sec_intval
	<< " = " << fir_intval * sec_intval << endl; //int math
	thi_float = sec_float / fir_float; // defines thi_float
	cout << sec_float << " / " << fir_float << " = " << thi_float << endl; // float math
	cout << endl;
	//end part 2

	//Part 3
	cout << "Part III" << endl;
	
	//variable initialization
	//by chronological order
	int sizevar_string1 = 0.00;
	int sizevar_string2 = 0.00;
	int sizevar_string3 = 0.00;
	int sizevar_total = 0.00;
	int byte_total = 0.00;
	int int_total = 0.00;
	int float_total = 0.00;

	// declaration
	sizevar_string1 = sizeof(myname);
	sizevar_string2 = sizeof(labnum); //strings are all the same size (REDUNDANT)
	sizevar_string3 = sizeof(date);
	int_total = sizeof(fir_intval) * 2;
	float_total = sizeof(fir_float) * 3;
	sizevar_total = sizevar_string1 + sizevar_string2 + sizevar_string3 + int_total + float_total;
	byte_total = sizevar_total / 8; // divide by 8 is wrong. Already in bytes *******************************
	
	//console out
	cout << endl;
	cout << endl;
	cout << "The total amount of bytes used by the integer values and floating point values is: " << endl
	<< byte_total << endl;
	cout << endl;
	cout << "Where the amount of integer dedicated bytes is: " << endl;
	cout << int_total / 8<< endl; // divide by 8 is wrong. Already in bytes**********************************
	cout << "And the amount of floating point value dedicated bytes is :" << endl;
	cout << float_total / 8 << endl; // divide by 8 is wrong. Is already in bytes***********************
	

	// end part 3

	return 0;
}