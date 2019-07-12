/*
Andrew Slade
Programming Project 6
*/

#include "Header_SladeA.h"
#include <stdexcept>
using namespace std;

//Method definitions ---------------------------

//constructor with parameters
Tank::Tank(int idIn, int ammoIn, float speedIn) {
	setId(idIn);
	setSpeed(speedIn);
	setAmmo(ammoIn);
}

//sets id
void Tank::setId(int idIn) {
	(idIn <= 50 && idIn >= 0) ? id = idIn : throw runtime_error("Invalid ID");
	
	return;
}

//sets speed
void Tank::setSpeed(float speedIn) {
	(speedIn >= 0 && speedIn <= 60) ? speed = speedIn : throw runtime_error("Invalid Speed");
}

//sets ammo
void Tank::setAmmo(int ammoIn) {
	(ammoIn >= 0 && ammoIn <= 40) ? ammo = ammoIn : throw runtime_error("Invalid Ammo count");
	
}

//increments speed by 5
void Tank::increaseSpeed() {
	((speed + 5) < 60) ? speed += 5 : speed = speed;
	return;
}

//decrements speed by 5
void Tank::decreaseSpeed() {
	((speed - 5) > 0) ? speed -= 5 : speed = speed;
	return;
}

//decrements ammo by 1
void Tank::fire() {
	((ammo - 1) > 0) ? ammo-- : ammo = ammo;
	return;
}

//increments ammo by 5
void Tank::reload() {
	((ammo + 5) < 40) ? ammo += 5 : ammo = ammo;
	return;
}

//----------------------------------------------
