
#include<iostream>
#include<iomanip>
using namespace std;


void calculate_shipping() {

	double weight = 0.0;
	int zone;
	double total;
	const double z1 = 0.88, // NEW way to declare variables
				z2 = 1.53,
				z3 = 1.83,
				z4 = 2.03;
	
	cout << setprecision(2) << fixed;
	cout << "Please enter your package weight: ";
	cin >> weight;
	cout << endl;
	if ((weight >= 150) && (weight <= 3000)) {
		cout << "Please enter the zone you wish to ship to (1, 2, 3, or 4): ";
		cin >> zone;
		cout << endl;

		switch (zone) {
		case 1:
			total = weight * z1;
			cout << left << setw(15) << "Weight: " << right << setw(15) << weight << endl;
			cout << left << setw(15) << "Cost: " << right << setw(15) << z1 << endl;
			cout << left << setw(15) << "Total: " << right << setw(15) << total << endl;
			break;
		case 2:
			total = weight * z2;
			cout << left << setw(15) << "Weight: " << right << setw(15) << weight << endl;
			cout << left << setw(15) << "Cost: " << right << setw(15) << z2 << endl;
			cout << left << setw(15) << "Total: " << right << setw(15) << total << endl;
			break;
		case 3:
			total = weight * z3;
			cout << left << setw(15) << "Weight: " << right << setw(15) << weight << endl;
			cout << left << setw(15) << "Cost: " << right << setw(15) << z3 << endl;
			cout << left << setw(15) << "Total: " << right << setw(15) << total << endl;
			break;
		case 4:
			total = weight * z4;
			cout << left << setw(15) << "Weight: " << right << setw(15) << weight << endl;
			cout << left << setw(15) << "Cost: " << right << setw(15) << z4 << endl;
			cout << left << setw(15) << "Total: " << right << setw(15) << total << endl;
			break;
		default:
			cout << "Invalid statement." << endl;
			break;
		}
	}
	else {
		cout << "Your Weight is invalid" << endl;
	}
	
}


void calculate_shipping_second_type() {

	double weight = 0.0;
	int zone;
	double total;
	const double z1 = 0.88, // NEW way to declare variables
		z2 = 1.53,
		z3 = 1.83,
		z4 = 2.03;

	cout << setprecision(2) << fixed;
	cout << "Please enter your package weight: ";
	cin >> weight;
	cout << endl;
	if ((weight >= 150) && (weight <= 3000)){
		cout << "Please enter the zone you wish to ship to (1, 2, 3, or 4): ";
		cin >> zone;
		cout << endl;

		if(zone == 1){
			total = weight * z1;
			cout << left << setw(15) << "Weight: " << right << setw(15) << weight << endl;
			cout << left << setw(15) << "Cost: " << right << setw(15) << z1 << endl;
			cout << left << setw(15) << "Total: " << right << setw(15) << total << endl;
			}
		else if(zone == 2){
			total = weight * z2;
			cout << left << setw(15) << "Weight: " << right << setw(15) << weight << endl;
			cout << left << setw(15) << "Cost: " << right << setw(15) << z2 << endl;
			cout << left << setw(15) << "Total: " << right << setw(15) << total << endl;
			}
		else if(zone == 3){
			total = weight * z3;
			cout << left << setw(15) << "Weight: " << right << setw(15) << weight << endl;
			cout << left << setw(15) << "Cost: " << right << setw(15) << z3 << endl;
			cout << left << setw(15) << "Total: " << right << setw(15) << total << endl;
			}
		else if(zone == 4){
			total = weight * z4;
			cout << left << setw(15) << "Weight: " << right << setw(15) << weight << endl;
			cout << left << setw(15) << "Cost: " << right << setw(15) << z4 << endl;
			cout << left << setw(15) << "Total: " << right << setw(15) << total << endl;
			}
		else {
			cout << "Invalid statement." << endl;
		}
	}
	else {
		cout << "Your weight is out of range\n" << endl;
	}
} 


int main() {

	calculate_shipping();
	calculate_shipping_second_type();

	return 0;
}