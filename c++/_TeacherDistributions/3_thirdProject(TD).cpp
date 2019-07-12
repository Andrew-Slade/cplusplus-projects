//susan grever comment for human

#include <iostream>
#include <string>
using namespace std;

int main(){
	
	//define, declare
	int num = 1.5, firstPeople = 21;
	double netSalary = 0;  //holds faction or decimal
	string word = "Monday";  //holds series of characters
	char letter = 'M';
	
	cout << "Hello World" << endl;
	//order of precidence
	cout << 3+5/2-1*4 << endl;
	
	//example in class
	int people, tables, remainder;
	//get input from user
	cout << "This app calculates how many tables "
	     << "are needed for the party\n";
	cout << "Enter the number of people: ";
	cin >> people;
	
	//do processing, calculations, decisions
	tables = people / 6;
	remainder = people % 6;
	
	//report the information 
	//the number of tables and people left over
	cout << "You need " << tables << " tables and have "
		<< remainder << " people left over.\n";
	
	
	
	return 0;
	
}