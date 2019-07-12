/*
Andrew Slade
Programming Project 6
*/
#ifndef HEADER_SLADEA
#define HEADER_SLADEA

//class definition
class Tank {
public:
	//constructors
	Tank() { id = 0; ammo = 0; speed = 0; }
	Tank(int idIn, int ammoIn, float speedIn);
	//mutators
	void setId(int idIn);
	void setSpeed(float speedIn);
	void setAmmo(int ammoIn);

	//increment and decrement
	void increaseSpeed();
	void decreaseSpeed();
	void fire();
	void reload();

	//accessors
	int getId() { return id; }
	float getSpeed() { return speed; }
	int getAmmo() { return ammo; }

private:
	int id, ammo;
	float speed;

};
//----------------
#endif // !HEADER_MAINPRGPRG6_SLADEA
