//figure out a program to calculate the 
//shipping cost of a package
#include <iostream>
#include <iomanip>
using namespace std;

//function to do the processing
void calcShipping(){
	
	double weight, total;
	int zone;
	const double z1 = .88,
				z2 = 1.53,
				 z3 = 1.83, 
				 z4 = 2.03;
				 
	cout << setprecision(2) << fixed;
	
	cout << "Please enter your package weight: ";
	cin >> weight;
	//weight < 150 or weight > 3000 error
	//weigth >= 150 and weight <= 3000 are valid
	if(weight >= 150 && weight <= 3000){
	
	
		cout << "Please enter your zone (1, 2, 3, or 4): ";
		cin >> zone;
		
		if(zone < 1 || zone > 4){
			cout << "We don't ship to that zone\n";
		}
		else if(zone == 1){
			total = weight * z1;
			cout << left << setw(15) << "Weight: " << right
					<< setw(15) << weight << endl;
			cout << left << setw(15) << "Cost: " << right
			      << setw(15) << z1 << endl;
			cout << left << setw(15) << "Total: " << right
					<< setw(15) << total << endl;		
		}
		else if(zone == 2){
			total = weight * z2;
			cout << left << setw(15) << "Weight: " << right
					<< setw(15) << weight << endl;
			cout << left << setw(15) << "Cost: " << right
			      << setw(15) << z2 << endl;
			cout << left << setw(15) << "Total: " << right
					<< setw(15) << total << endl;
		}
		else if(zone == 3){
			total = weight * z3;
			cout << left << setw(15) << "Weight: " << right
					<< setw(15) << weight << endl;
			cout << left << setw(15) << "Cost: " << right
			      << setw(15) << z3 << endl;
			cout << left << setw(15) << "Total: " << right
					<< setw(15) << total << endl;
		}
		else if(zone == 4){
			total = weight * z4;
			cout << left << setw(15) << "Weight: " << right
					<< setw(15) << weight << endl;
			cout << left << setw(15) << "Cost: " << right
			      << setw(15) << z4 << endl;
			cout << left << setw(15) << "Total: " << right
					<< setw(15) << total << endl;
		}
		
	}
	else {
		cout << "Your weight is out of range\n";
	}				
}

void calcShipping2(){
	
	double weight, total;
	int zone;
	const double z1 = .88,
				z2 = 1.53,
				 z3 = 1.83, 
				 z4 = 2.03;
				 
	cout << setprecision(2) << fixed;
	
	cout << "Please enter your package weight: ";
	cin >> weight;
	//weight < 150 or weight > 3000 error
	//weigth >= 150 and weight <= 3000 are valid
	if(weight < 150){
		cout << "Your package is too light\n";
	}
	else if(weight > 3000){
		cout << "Your package is too heavy\n";
	}
	else{	
	
		cout << "Please enter your zone (1, 2, 3, or 4): ";
		cin >> zone;
		
		if(zone < 1 || zone > 4){
			cout << "We don't ship to that zone\n";
		}
		else if(zone == 1){
			total = weight * z1;
			cout << left << setw(15) << "Weight: " << right
					<< setw(15) << weight << endl;
			cout << left << setw(15) << "Cost: " << right
			      << setw(15) << z1 << endl;
			cout << left << setw(15) << "Total: " << right
					<< setw(15) << total << endl;		
		}
		else if(zone == 2){
			total = weight * z2;
			cout << left << setw(15) << "Weight: " << right
					<< setw(15) << weight << endl;
			cout << left << setw(15) << "Cost: " << right
			      << setw(15) << z2 << endl;
			cout << left << setw(15) << "Total: " << right
					<< setw(15) << total << endl;
		}
		else if(zone == 3){
			total = weight * z3;
			cout << left << setw(15) << "Weight: " << right
					<< setw(15) << weight << endl;
			cout << left << setw(15) << "Cost: " << right
			      << setw(15) << z3 << endl;
			cout << left << setw(15) << "Total: " << right
					<< setw(15) << total << endl;
		}
		else if(zone == 4){
			total = weight * z4;
			cout << left << setw(15) << "Weight: " << right
					<< setw(15) << weight << endl;
			cout << left << setw(15) << "Cost: " << right
			      << setw(15) << z4 << endl;
			cout << left << setw(15) << "Total: " << right
					<< setw(15) << total << endl;
		}
		
	}
				
}

void calcShipping3(){
	
	double weight, total;
	int zone;
	const double z1 = .88,
				z2 = 1.53,
				 z3 = 1.83, 
				 z4 = 2.03;
				 
	cout << setprecision(2) << fixed;
	
	cout << "Please enter your package weight: ";
	cin >> weight;
	//weight < 150 or weight > 3000 error

	if(weight < 150 || weight > 3000){
		cout << "Your package weight is invalid\n";
	}
	else{	
	
		cout << "Please enter your zone (1, 2, 3, or 4): ";
		cin >> zone;
		
		switch(zone){
			case 1:
				total = weight * z1;
				cout << left << setw(15) << "Weight: " << right
						<< setw(15) << weight << endl;
				cout << left << setw(15) << "Cost: " << right
				      << setw(15) << z1 << endl;
				cout << left << setw(15) << "Total: " << right
						<< setw(15) << total << endl;		
				break;
		case 2:
				total = weight * z2;
				cout << left << setw(15) << "Weight: " << right
						<< setw(15) << weight << endl;
				cout << left << setw(15) << "Cost: " << right
				      << setw(15) << z2 << endl;
				cout << left << setw(15) << "Total: " << right
						<< setw(15) << total << endl;
				break;
		case 3:
			total = weight * z3;
			cout << left << setw(15) << "Weight: " << right
					<< setw(15) << weight << endl;
			cout << left << setw(15) << "Cost: " << right
			      << setw(15) << z3 << endl;
			cout << left << setw(15) << "Total: " << right
					<< setw(15) << total << endl;
			break;
		case 4:
			total = weight * z4;
			cout << left << setw(15) << "Weight: " << right
					<< setw(15) << weight << endl;
			cout << left << setw(15) << "Cost: " << right
			      << setw(15) << z4 << endl;
			cout << left << setw(15) << "Total: " << right
					<< setw(15) << total << endl;
			break;		
			default: cout << "We don't ship to that zone\n";		
		} //end switch zone
		
	} //end if for weight
				
}



int main(){
	
	int option;
	
	//call my function
	cout << "Enter your selection to run  a function.\n";
	cout << "1. calcShipping v1 with valid weight first.\n"
		<<"2. calcShipping v2 with invalid weight first.\n"
		<< "3. calcShipping v3 with switch.\n";
	cin >> option;
	
	switch(option){
		case 1: calcShipping();
				break;
		case 2: calcShipping2();
				break;
		case 3: calcShipping3();
				break;
	}
	return 0; 
}