#include <iostream>
using namespace std;




int main() {

	bool t_f;
	int x = 0.0;

	cout << "Enter a number greater than ten please: ";
	cin >> x;

	if (x > 10){
		t_f = 1; //true
	}
	else {
		t_f = 0; //false
	}
	
	if (t_f) {  //checks to se if t_f is true
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}

	return 0;
}