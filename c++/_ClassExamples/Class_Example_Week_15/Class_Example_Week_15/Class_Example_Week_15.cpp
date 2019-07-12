//Classes practice
#include <iostream>

using namespace std;

//classes and structures

/*
struct Gas {
	//public by default
	int id;
	float pricePerGal, gallons;
};
*/


class Gas {
public:
	//methods only
	//mutators
	void setId(int idIn);
	void setPricePerGallon(float ppg);
	void setGallons(float g);

	//accessors
	int getId() { return id; } 
	float getPricePerGal() { return pricePerGal; } 
	float getGallons() { return gallons; }
	
private:
	//variables
	int id;
	float pricePerGal, gallons;
};
//----------------------

//prototypes
void outputReceipt(Gas g);
//----------

int main() {
	Gas g; //object
	int ids;
	float pricepg, gal;

	do{
		cout << "Enter the id: ";
		cin >> ids;
	} while (ids <= 0);
	g.setId(ids);

	do {
		cout << "Enter the price per gallon: ";
		cin >> pricepg;
	} while (pricepg <= 0);
	g.setPricePerGallon(pricepg);

	do {
		cout << "Enter the amount of gallons: ";
		cin >> gal;
	} while (gal <= 0);
	g.setGallons(gal);

	//output
	outputReceipt(g);

	return 0;
}
//functions
void outputReceipt(Gas g) {
	cout << "ID:" << g.getId() << endl
		<< "Price Per Gallon: " << g.getPricePerGal() << endl
		<< "Gallons: " << g.getGallons() << endl
		<< "Total Sale: " << g.getPricePerGal() * g.getGallons() << endl;
	return;
}
//methods


void Gas::setId(int idIn){
	//validation > 0
	(idIn > 0) ? id = idIn : id = 0;// member variable = parameter ELSE throws exception
	
	return;
}

void Gas::setPricePerGallon(float ppg){
	(ppg > 0.01 && ppg <= 5) ? pricePerGal = ppg : pricePerGal = 0.0f;

	return;
}

void Gas::setGallons(float g){
	(g > 0.01 && g <= 80) ? gallons = g : gallons = 0.0f;

	return;
}
