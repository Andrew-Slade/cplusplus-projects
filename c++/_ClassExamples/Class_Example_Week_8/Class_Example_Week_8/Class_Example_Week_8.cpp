#include<iostream>
using namespace std;

//prototypes
int doAdd(int, int);
float useStatic(float, float);
void CoordTransform(int, int, int&, int&);
//----------

//pass by reference and value example
//& = adress operator
int main() {
	int x, y, sum;
	float f1, f2, f3;
	char again = 'n';
	int xValNew = 0; //used for pass by reference
	int yValNew = 0; //used for pass by reference
	f1 = 10;
	f2 = 2;
	x = 25;
	y = 30;
	sum = 0;

	//local scope: variables x, y, sum are only known in main
	sum = doAdd(x, y); //Arguments: x, y
	cout << x << " + " << y << " = " << sum << endl;

	do {
		f3 = useStatic(f1, f2); //function
		f1 += 3;
		f2 += 1;
		cout << f3 << endl;
		cout << "Again? (y/n) ";
		cin >> again;
	} while (again == 'y');

	cout << "xValNew's address in main is " << &xValNew << endl;
	CoordTransform(3, 4, xValNew, yValNew);
	cout << "(3, 4) becomes " << "(" << xValNew << ", " << yValNew << ")" << endl;
	cout << "Press enter to exit: ";
	cin.get();

	return 0;
}

//Meta-function: pass by value example
int doAdd(int addX, int addY) {
	int sum;
	//scope : 27, 33, 35
	/*
	Pass by value copies arguments value 
	into parameter's memory space to use
	*/
	sum = addX + addY;

	return sum;
}

float useStatic(float a, float b) {
	//float a and b only exist from line 39 to closing brackets
	static int count = 0;
	float result;

	/*
	static variables do not erase when function ends
	will not reinitialize the variable "count"
	*/

	//do not use two returns; unstructured programming
	if (b != 0) {
		result = a / b;
	}
	else {
		result = 0;
	}
	count++;
	cout << "You've called this function " << count << " times" << endl;

	return result;
}

void CoordTransform(int xVal, int yVal, int& xValNew, int &yValNew) {
	cout << "xValNew's address in main is " << &xValNew << endl;
	xValNew = (xVal + 1) * 2;// modifies XValNew and uses & in parameters to pass xValNew back
	yValNew = (yVal + 1) * 2; //modifies yValNew and uses & in parameters to pass yValNew back
}