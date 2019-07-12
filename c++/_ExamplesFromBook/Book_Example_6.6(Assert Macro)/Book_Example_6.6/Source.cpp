#include <iostream>
#include <cassert>
using namespace std;

double HrMinToMin(int origHours, int origMinutes) {
	int totMinutes = 0;  // Resulting minutes

	totMinutes = (origHours * 60) + origMinutes;

	return origMinutes; //*********************error is here, should be totMinutes ****************
}

int main() {

	cout << "Testing started" << endl;

	assert(HrMinToMin(0, 0) == 0); //assert statment
	assert(HrMinToMin(0, 1) == 1);
	assert(HrMinToMin(0, 99) == 99);
	assert(HrMinToMin(1, 0) == 60); //causes program to fail here or anywhere where hours are more than zero
	assert(HrMinToMin(5, 0) == 300);
	assert(HrMinToMin(2, 30) == 150);
	// Many more test vectors would be typical...

	cout << "Testing completed" << endl;

	return 0;
}