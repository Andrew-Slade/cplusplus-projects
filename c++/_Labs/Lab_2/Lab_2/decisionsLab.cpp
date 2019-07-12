//Andrew Slade
//Lab2
/*CIS 150 Chapter 4 Decisiob Lab

Place you name and section at the top in comments.
Read the instructions for each question and give your answer in comments or write the code into the 
program.

Comment out sections as you work. Just move the closing multi-line comment up or down.
Remember to declare variables if necessary.  
You do not need to get input from the user; use literals to provide values for your variables instead.
Unless output is specified you may do as little or as much as you need 
to help you understand what decision in the code is doing.  
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
//1

	float age = 0.0; 
	double admission = 0.0; 
	//assign age a value 

	cout << "Please enter your age: "; 
	cin >> age; 

	if (age >= 65){ 
		cout << "Age greater than or equal to 65" << endl;
		admission = 10.0;
}
	else { 
		cout << "Age is less than 65" << endl;
		admission = 15.0;
	}
//2
		int x = 0;
		bool flag = false; 

		cout << "Please enter a value larger than 5: ";
		cin >> x;

		flag = (x > 5)? true : false; 

		if (!flag) { 
			cout << "it's false" << endl;
		}
		else {
			cout << "it's true" << endl;
		}


	//3
		int count = 0;
		if (count = 10) { //needs ==
			cout << count << endl;
		} 
		/*
		  this does not work becuase = is an initializer and == 
		  is a logic operand that compares a value to a already stated value.
		 */
		

 //4
	

		double score = 0.0;
		cout << "Enter a score: ";
		cin >> score;
		cout << endl;
		 if ((score > 100) || (score < 0)) {
			 cout << "Greater than 100 or less than 0" << endl;
		 }
		 else {
			 cout << "between 100 and 0" << endl;
		 }

//5
		 int nage = 0;
		 bool license = false;
		 string licensed = "Has license.";
		 string nonlicensed = "Does not have license.";
		
		 cout << "Please enter age: ";
		 cin >> nage;
		 cout << endl;

		 license = (nage > 15) ? true : false;
		 if (license) {
			 cout << licensed << endl;
		 }
		 else {
			 cout << nonlicensed << endl;
		 }
		 
		 


	//6

		 bool aged;
		

		 if (license) {
			 aged = (nage >= 16) ? true : false;
			 if (aged) {
				 cout << "has license and is over than or is 16" << endl;
			 }
			 else {
				 cout << "has license but is not 16? Report to police" << endl;
			 }
		 }
		 else {
			 cout << "does not have license or is not over or 16." << endl;
		 }

	
	//7

	int input;
	cout << "1. Enter data and save to file\n"
		<< "2. Read data in and display report\n"
		<< "3. Quit the program\n";
	cin >> input;
	switch (input) {
	case 1:
		cout << "will enter data and save to file" << endl;
		break;
	case 2:
		cout << "Read data and display in report" << endl;
		break;
	case 3:
		cout << "Closing program, please wait" << endl;
		break;
	default:
		cout << "Invalid input" << endl;
		break;
	}
		
	/*8.  Write the decision structure set the rate to calculate the commision.
	Start your structure with 0 or less.
	
	No commision is paid for sales 0 or less.
	A sales commision of 2% is paid for sales of 10,000 or less.
	A sales commision of 3% is paid for sales of 15,000 or less.
	A sales commision of 4% is paid for sales of 20,000 or less
	A sales commision of 5% is paid for sales over 20,000.
	
	uncomment the following code*/

	float rate, commision, sales;
	cout << "Enter the sales amount: ";
	cin >> sales;

	if (sales <= 0) {
		cout << "No commision is paid for sales 0 or less." << endl;
		rate = 0;
		commision = 0;
	}
	else if (sales <= 10000) {
		cout << "A sales commision of 2% is paid for sales of 10,000 or less." << endl;
		rate = 0.02;
		commision = sales * rate;
		cout << "here is the commision: " << commision << endl;
	}
	else if (sales <= 15000) {
		cout << "A sales commision of 3% is paid for sales of 15,000 or less." << endl;
		rate = 0.03;
		commision = sales * 0.03;
		cout << "here is the commision: " << commision << endl;
	}
	else if (sales <= 20000) {
		cout << "A sales commision of 4% is paid for sales of 20,000 or less." << endl;
		rate = 0.04;
		commision = sales * 0.04;
		cout << "here is the commision: " << commision << endl;
	}
	else if (sales > 20000) {
		cout << "A sales commision of 5% is paid for sales over 20,000." << endl;
		rate = 0.05;
		commision = sales * 0.05;
		cout << "here is the commision: " << commision << endl;
	}
	else {
		cout << "invalid input" << endl;
	}




	system("pause");
	return 0;
}
