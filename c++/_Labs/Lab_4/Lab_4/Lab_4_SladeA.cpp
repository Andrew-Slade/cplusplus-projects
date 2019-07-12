/*
Andrew Slade
2/24/2016
*/

/*
1. Place you name and the date above this comment.
2. Read the instructions and write the code into this file.
If a questions requires an answer other than code, use a comment


Remember to declare variables if necessary.
You do not need to get input or produce output unless specified, use
only enough output or input to help you understand the processing done
by the computer.

Use literal values for your variables instead of input.

All code must run!  */

#include <iostream>
#include <cmath>
#include<iomanip>
using namespace std;

int main()
{
	float x = 0.0;
	float output = 0.0;
	int userInput_1 = 0;
	int z = 0;
	int a = 0;
	int modz = 0;
	int l = 0;
	int modl = 0;

	/*
	1. Write a while loop that will output the square roots for the numbers
	from 10 to 20, each on it's own line.
	*/
	x = 10;
	while(x <= 20) {
		output = sqrt(x);
		cout << output << endl;
		x++;
	}
	cout << endl;
	x = 10;//resets variable

	/*	2. Rewrite  the loop from question 1  as a do while (bottom test) loop */
	do {
		output = sqrt(x);
		cout << output << endl;
		x++;
	} while (x <= 20);
	cout << endl;

	/*3.  Rewrite  the loop from question 1 as a for loop.*/
	for (x = 10; x <= 20; x++) {
		output = sqrt(x);
		cout << output << endl;
	}
	cout << endl;
	
	/*4.  Write a while loop that will validate that an integer value entered
	by the user must be greater than 0 and less than 100. */
	cout << "Please enter a value: ";
	cin >> userInput_1;
	while ((userInput_1 <= 0) || (userInput_1 >= 100)) {
		cout << "The input is not between 0 and 100, please retry" << endl;
		cin >> userInput_1;
	}

	/*5. Write a do while loop that will validate that an integer value entered by the user must be
	greater than 0 and less than 100..*/
	
	do {
		cout << "Please enter a value: ";
		cin >> userInput_1;
	} while ((userInput_1 <= 0) || (userInput_1 >= 100));
	
	/*6. Using ONE while or for loop, output the numbers from 1 to 100. Each number should be in a
	field and 10 on a line.
	Step one is to print out the numbers from 1 to 100 on line using a while loop. Your number will
	wrap around when they hit the edge of the screen.
	Once you have the 100 numbers on one line you will need to count to 10 and then output
	a newline.  There are several different ways to count!
	a. Create a counter variable. Add one to it each time you output an number.
	Using a decision structure, if you reach 10 output a newline and start your count over.
	or
	b. In a decision structure use modulus to see if you have reached a number evenly divisible by 10
	Your output should look similar to this

	1   2   3   4   5   6   7   8   9  10
	11  12  13  14  15  16  17  18  19  20
	21  22  23  24  25  26  27  28  29  30
	31  32  33  34  35  36  37  38  39  40
	41  42  43  44  45  46  47  48  49  50
	51  52  53  54  55  56  57  58  59  60
	61  62  63  64  65  66  67  68  69  70
	71  72  73  74  75  76  77  78  79  80
	81  82  83  84  85  86  87  88  89  90
	91  92  93  94  95  96  97  98  99 100
	*/
	
	for(l = 1; l <= 100; l++){
		cout << setw(5) ;
		modl = l % 10;
		cout << l << " ";
		if(modl == 0) {
			cout << endl;
		}
	}
	cout << endl;

	/*7. For practice writing a nested loop. Using nested loops and fields
	write two nested loops that will output a number from 1 to 5, 5 times.
	The inner loop outputs numbers from 1 to 5 on one line
	The outer loop repeats the inner loop 5 times and adds the newline. cout << endl;

	1   2   3   4   5
	1   2   3   4   5
	1   2   3   4   5
	1   2   3   4   5
	1   2   3   4   5

	*/
	for(a = 1; a <= 5; a++){
		for(z = 1; z <= 5; z++){
			cout << setw(5);
			modz = z % 5;
			cout << z << " ";
			if(modz == 0){
				cout << endl;
			}
		}
	}
	cout << endl;
	cout << "Press enter to continue...";
	cin.get();

	return 0;
}




