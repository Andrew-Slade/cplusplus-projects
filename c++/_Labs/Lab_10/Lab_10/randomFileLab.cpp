//Add your name in comments
//Random File IO Lab
//this lab allows the user to save dates to a random access file. 
//the steps involve initializing a new file.
//opening the file to read or write
//reading or writing to the file 
//and finally closing the file
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/**************************struct definition************************************/
struct MyDate
{
	int m, d, y;
};

/*************************function prototypes**********************************/


int getNum(string prompt, int low, int high);
void outputDate(MyDate d);
void readDate(fstream &f);
void outputDate(MyDate d);
MyDate getDate();
int getNum(string prompt, int low, int high);

/**************************main line*******************************************/

int main()
{
	string fileName = "dates.ran";
	fstream f(fileName, ios::in);
	if(f)
		f.close();
	else
		initialize(fileName); //only run initialize once.

	//open fstream object f or binary access that is both in and out
	

	//write a menu that will ask the user if they want to write to the file, read to the file or quit.
	//call the appropriate function for there choice and send it f as an argument.
	

	f.close();


	cout << "Press enter to continue...";
	cin.ignore();
	cin.get();
	return 0;
}


/*************************function definitions*********************************/

//this function initializes a binary file so that it contains default dates

	//create a default date and initialize it to 0, 0, 0
	
	//open the file to write out and for binary access 
	

	//start a for loop to write out the default date and initialize the file
	//you will do this sequentially, there is not reason to move the file position pointer
	

	//close the file
	
}

//write a function to write out dates to the file
//the function returns nothing and has a fstream object as the parameter
//the fstream object must using a reference varaible, think address operator

	//create an integer variable for the record number

	//create a MyDate variable to hold the date that is read from the file

	//prompt the user to enter a record number between 1 and 20 and store their input in the 
	//variable that for the record number

	//while the record number is valid

		//call function getDate() to get the values for your MyDate variable
	
		//use seekp() to move to the correct position in the file

		//use write() to read the current record

		//prompt the user to enter a record number between 1 and 20 and store their input in the 
		//variable that for the record number
	
	//end the loop
//end the function


//write a function to read dates from the file
//the function returns nothing and has a fstream object as the parameter
//the fstream object must using a reference varaible, think address operator

	//create an integer variable for the record number

	//create a MyDate variable to hold the date that is read from the file

	//prompt the user to enter a record number between 1 and 20 and store their input in the 
	//variable that for the record number

	//while the record number is valid
	
		//use seekg() to move to the correct position in the file

		//use read() to read the current record

		//call function outputDate() to output the date that was read to the screen

		////prompt the user to enter a record number between 1 and 20 and store their input in the 
		//variable that for the record number

	//end the loop
//end the function

void outputDate(MyDate d)
{
	cout << d.m << "/" << d.d << "/" << d.y << endl;
}

MyDate getDate()
{
	MyDate d;
	d.m = getNum("Enter the month: ", 1, 12);
	d.d = getNum("Enter the day: ", 1, 30);
	d.y = getNum("Enter the year: ", 1900, 2050);

	return d;
}

int getNum(string prompt, int low, int high)
{
	int x;
	cout << prompt;
	cin >> x;

	while(x < low || x > high)
	{
		cout << "Error, invalid, must be between " << low << " and " << high << ": ";
		cin >> x;
	}
	return x;
}







