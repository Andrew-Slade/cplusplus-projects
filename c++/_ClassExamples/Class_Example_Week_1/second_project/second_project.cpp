// second_project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h" // all preprocessors
#include <iostream>
#include <string>
using namespace std; //reserves namespace

int main()
{
int num = 1.5, first_people = 21;
double net_salary = 0; //holds fractions
string word = "Monday"; //holds series of characters
char letter = 'M';

//example in class
int people, tables, remainder;

cout << "This application calculates how many tables are necessary"
     << " for the party. \n";
cout << "Enter the number of people, please: ";
cin >> people;
//calculations
tables = people / 6;
remainder = people % 6;

//output
cout << "You need " << tables << " and have "
     << remainder << " People left over." << endl;

//order of precidence ***important***
cout << 3 + 5 / 2 - 1 * 4 << endl;


    return 0;
}

