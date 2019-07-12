/*
Andrew Slade
Programming Project 6
*/

//preprocessors
#pragma message ("Definitely not playing with the code") //REMOVE
#include "Header_SladeA.h"
#include <iomanip>
#include <iostream>
#include <stdexcept>
using namespace std;
//-------------

//Prototypes
void outputData(Tank object);
//----------

//main
int main() {
	int tempId, tempAmmo;
	float tempSpeed = 0.0f;;
	tempId = 0;
	tempAmmo = 0;

	//first object******************
	Tank obj;
	try {
		cout << "Please enter the ID: ";
		cin >> tempId;
		obj.setId(tempId);

		cout << "Please enter the ammo count: ";
		cin >> tempAmmo;
		obj.setAmmo(tempAmmo);

		cout << "Please enter the speed: ";
		cin >> tempSpeed;
		obj.setSpeed(tempSpeed);



		//*****************************

		//second object********
		cout << "Please enter the ID: ";
		cin >> tempId;

		cout << "Please enter the ammo count: ";
		cin >> tempAmmo;

		cout << "Please enter the speed: ";
		cin >> tempSpeed;
		Tank objS(tempId, tempAmmo, tempSpeed);
		
		//*********************

		//object 1 manipulation
		cout << "First Object" << endl;
		outputData(obj);
		obj.increaseSpeed();
		outputData(obj);
		obj.decreaseSpeed();
		outputData(obj);
		obj.fire();
		outputData(obj);
		obj.reload();
		outputData(obj);
		//----------------------

		//second object manipulation
		cout << "Second Object" << endl;
		outputData(objS);
		objS.increaseSpeed();
		outputData(objS);
		objS.decreaseSpeed();
		outputData(objS);
		objS.fire();
		outputData(objS);
		objS.reload();
		outputData(objS);
		//--------------------------
	}
	catch (runtime_error& excpt) {
		// Prints the error message passed by throw statement
		cout << excpt.what() << endl;
		cout << "Cannot continue tank process." << endl;
	}

	return 0;
}
//----

//definition-----------------------------------

//output data
void outputData(Tank object) {
	cout << endl << setw(10) << left << "ID:"
		<< setw(5) << right << object.getId() << endl
		<< setw(10) << left << "Speed:"
		<< setw(5) << right << object.getSpeed() << endl
		<< setw(10) << left << "Ammo:"
		<< setw(5) << right << object.getAmmo() << endl;

	return;
}

//----------------------------------------------
