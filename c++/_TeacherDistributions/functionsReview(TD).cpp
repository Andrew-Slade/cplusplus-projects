#include <iostream>
using namespace std;


void CoordTransform(int xVal, int yVal, int &xValNew, int& yValNew);

//a function that will add
int doAdd(int a, int b ){
	//int s = a + b;
	return a + b; // s;
}

float useStatic(float a, float b){

	static int count = 0; //this line only runs once
	//structure, one way in one way out
	float result;
	if (b != 0)
		result =  a / b;
	else
		result = 0;
	count++;
	cout << "You've called the function " << count << " times\n";

	return result;
}







int main(){

	int x , y, sum;
	x = 25; y = 30; sum = 0;


	/*sum = x + y;*/
	sum = doAdd(x, y);
	cout << x << " + " << y << " = " << doAdd(x, y) << endl;

	float f1, f2, f3;
	f1 = 10; f2 = 2;
	char again = 'n';
	do{
		f3 = useStatic(f1, f2);
		cout << f3 << endl;
		f1 += 3;
		f2 += 1;
		cout << "Again? ";
		cin >> again;
	} while (again == 'y');
	
	int xValNew = 0;
	int yValNew = 0;

	cout << "xValNew's address in main is " 
		<< &xValNew << endl;

	CoordTransform(3, 4, xValNew, yValNew);
	cout << "(3, 4) becomes " << "(" << xValNew 
		<< ", " << yValNew << ")" << endl;

	cout << "Press enter to continue...";
	cin.get();
	return 0;

}

//pass by reference
//Define a function CoordTransform() that transforms 
//its first two input parameters xVal and yVal 
//into two output parameters xValNew and yValNew.
//The function returns void.The transformation 
//is new = (old + 1) * 2. 
//Ex: If xVal = 3 and yVal = 4, 
//	then xValNew is 8 and yValNew is 10.

void CoordTransform(int xVal, int yVal, int &xValNew, int& yValNew ){
/* Your solution goes here  */
	cout << "xValNew's address in CoordTransform is " << &xValNew << endl;
	xValNew = (xVal + 1) * 2;
	yValNew = (yVal + 1) * 2;
	
}