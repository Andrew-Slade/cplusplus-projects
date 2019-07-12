/*CIS 150
Andrew Slade
struct Lab*/

#include <iostream>
#include <string>
using namespace std;

/*1.	Define a structure that has 3 members and the tag Employee.
The three members are:
a string that hold a full name (first and last)
an integer that holds hours worked
a float that hold the pay rate */
struct Employee {
	string fullName = "Default";
	int workHours = 0;
	float ratePay = 0.0f;
};
//Prototypes
float calcPay(Employee variable);
//----------

int main()
{

	/*2.	Declare an Employee variable named emp and initialize it
	with the values "John Doe", 34, 9.00 */
	Employee emp;

	emp.fullName = "John Doe";
	emp.workHours = 34;
	emp.ratePay = 9.00f;

	/*3.	Declare an array of type Employee name empList with 3 elements.*/
	const int SIZE = 3;
	Employee empList[SIZE];

	/*4.	Write a statement that will output the name member of
	the Employee variable emp.*/
	cout << emp.fullName << endl;

	/*5.	Define a float variable grossPay and use it to store
	the calculated gross pay of the emp variable (pay is hours times rate).*/
	float grossPay = 0.0f;


	

	
	

	/*9.  Write a for loop, move 6, 7 and 8 into the for loop
	and change the literal value you used to subscript the array
	to the control variable for the for loop. Remember that you will
	need to revisit chapter 3 since the first statement #6, receives a
	string with spaces and 7 and 8 get numbers. */
	for (int i = 0; i < SIZE; i++) {
		/*6.	Write a statement that will allow the user to enter
		both first and last names in the name member of the first element
		of empList. */
		cout << "Please enter the full name of the employee: ";
		getline(cin, empList[i].fullName);
		cout << endl;
		/*7.	Write a statement that will allow the user to enter
		the hours worked member of the first element of empList.*/
		cout << "Please enter the hours that the employee worked: ";
		cin >> empList[i].workHours;
		cout << endl;
		/*8.	Write a statement that will allow the user to enter
		the pay rate member of the first element of empList.*/
		cout << "Please enter their rate of pay: ";
		cin >> empList[i].ratePay;
		cout << endl;
		cin.ignore();
	}


	/*11.	Write a for loop that will output all the values in
	the empList array. */
	for (int c = 0; c < SIZE; c++) {
		cout << "Employee Name: " << empList[c].fullName << endl
			<< "The Hours Worked: " << empList[c].workHours << endl
			<< "The Rate of Pay: " << empList[c].ratePay << endl;
		grossPay = calcPay(empList[c]);
		cout << "The Total Pay: " << grossPay << endl << endl;
	}

	/*12. In the for loop but after the statements to
	output the members, write a call to the calcPay function you created
	in 10 and output the returned value.*/

	cout << "Press enter to continue...";
	cin.ignore();
	cin.get();
	return 0;
}



/*10. Write a function calcPay().  calcPay() returns a float value
and has one parameter of type Employee, (one element of an array
at a time!) Copy your statement from #5 into the function and
return the calculated pay.*/
float calcPay(Employee variable) {
	float grossPay = 0.0f;
	grossPay = variable.workHours * variable.ratePay;
	return grossPay;
}

