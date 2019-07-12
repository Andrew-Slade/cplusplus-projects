//program with functions
//play with rectangles

#include <iostream>
#include <string>
using namespace std;


/*******************prototypes**********************/
//declaring that the definition follows and what to look
//for
float getSide(string prompt);
float calcArea(float w, float height);
void doReport(float width, float height, float area);

int main(){

	float width, height, area;

	//first function gets a value for width
	//call the function
	width = getSide("Enter the width: ");
	//second call function get a value for height
	height = getSide("Enter the height, 1 to 100: ");
	//third call to calculate area
	area = calcArea(width, height);
	//forth function outputs all the values and
	//returns nothing
	doReport(width, height, area);

	cout << "Press enter to continue...";
	cin.ignore();
	cin.get();

	return 0;
}

/******************function definitions**********************/
//get a floating point value between 1 and 100 inclusive
//validate with a loop and return the value
//gets a prompt as a string as a parameter
float getSide(string prompt){
	//do while loop
	float side; //generic
	do{
		cout << prompt;
		cin >> side;
		//output an error message
		if (side < 1 || side > 100){
			cout << "Error, between 1 and 100 only.\n";
		}
	} while (side < 1 || side > 100);
	//return the value in side
	return side; 
}

float calcArea(float w, float height){

	//with times heights
	float a;
	a = w * height;
	return a;

	//return w * height;
}

//doReport gets three values, one for width, one for height
//one for area. Outputs all three values to the screen.
//returns nothing

void doReport(float width, float height, float area){
	cout << "width = " << width << endl;
	cout << "height = " << height << endl
		<< "area = " << area << endl;
	return;
}