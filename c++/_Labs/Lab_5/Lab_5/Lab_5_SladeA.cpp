/*Name: Andrew Slade
Date: 3/2/2016

For this lab you will use the code in the file and
break it into functions. Code for functions has been marked
for you. To do this you will:

1. cut the code from main() and paste
it below the closing } for main.

2. In the comments before the function note what the function's job is.

3. In the comments before the function note any values that are passed into
the function or return from the function. Ask yourself:
do you need a value for the code to run correctly - that is a parameter
does the function get or calculate a new value - that is a return value
Use these to determine how to write the header.

4. Write the header for the function using your comment to help guide you.

5. Declare the local variables in the function.

6. Create the prototypes for the functions.

7. In main(), determine which variable declarations need to remain there.
A variable will need to stay in main if more than one of your function
uses the value stored in the function.

8. Call the functions, passing values as needed and using assignment
for any values returned from the function.

9. Run and debug your program.

10. When the program is running correctly upload the completed file to
D2L.
*/

#include <iostream>
#include <iomanip>
#include<string>
using namespace std;

/*******************************Prototypes******************************/
float getUsrMilesGallons(int, int, string);
float calculateMPG(float, float);
float calcTimeToDrive(float);
void finalOutput(float, float, float, float);
/*******************************main line*******************************/

//calls all functions and holds extra data
int main()
{
	cout << setprecision(2) << fixed;
	float miles, gallons, mpg, time;
	
	//function definition
	miles = getUsrMilesGallons(1, 600, "The program needs the miles driven.\n");
	gallons = getUsrMilesGallons(1, 50, "The program needs the Gallons used.\n");
	mpg = calculateMPG(miles, gallons);
	time = calcTimeToDrive(miles);
	finalOutput(miles, gallons, mpg, time);

	/*end main and hold the screen open*/
	cout << "Press enter to continue...";
	cin.ignore();
	cin.get();
	return 0;
}




/*the following two do while loops become one function to get and validate input
from the user. You will delete one loop and cut and past the other into the function
body. The literals 1, 600 and 1, 50 are parameters in the function. You may use a third
parameter for the prompt to the user in the function. In the function rewrite
the literals to use the parameters.
In the call send the literal values as given in the code. */

/*************************function definititions**************************/

//gets user values for miles and gallons
float getUsrMilesGallons(int min,int max, string prompt){
	float user_val;
	float x;

	cout << prompt;
	do {
		cout << "Enter your value: ";
		cin >> x;
		if (x < min || x > max)
			cout << "Error the value must be between " << min << " and " << max << " included\n";
	} while (x < min || x > max);
	user_val = x;

	return user_val;
}

//calculates mpg
float calculateMPG(float miles, float gallons){
	float mpgC;
	mpgC = miles / gallons;
	return mpgC;
}
//calculates the time (in hours) to drive the given miles going 60 miles per hour
float calcTimeToDrive(float miles){
	float timeC;
	timeC = miles / 60;
	return timeC;
}
//display the information on the milage to the user
void finalOutput(float miles, float gallons, float mpg, float time){
cout << "Your milage specs are\n";
cout << "Miles: " << miles << endl
<< "Gallons: " << gallons << endl
<< "MPG: " << mpg << endl
<< "Time: " << time << endl;
}



