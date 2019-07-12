#include <iostream>
#include <fstream>
using namespace std;

//a structure written in structure style
struct StructStyle {
	char firstN[15], lastN[15];
	double gpa;
};
//NOT USED JUST AN EXAMPLE
/*
//a structure written in class style
struct ClassStyle {
public:

private:

};
//a class written in class style
class Classed {
public:

private:

};
*/

//_________________________________
//prototypes
StructStyle getStudentData();
void outputStArray(const StructStyle students[], const int SIZE);
void writeFile(const StructStyle students[], const int SIZE);
//----------

//main
int main() {
	//StructStyle david, james;
	const int SIZE = 2;
	
	StructStyle students[SIZE];
	// get sutdent data
	//david = getStudentData();
	//james = getStudentData();
	//use a loop to get data
	for (int i = 0; i < SIZE; i++) {
		students[i] = getStudentData();
	}
	//output
	//cout << david.firstN << endl << david.lastN << endl << david.gpa << endl;
	//james = david; // assignment example(value type)
	//cout << james.firstN << endl << james.lastN << endl << james.gpa << endl;
	outputStArray(students, SIZE);
	writeFile(students, SIZE);

	return 0;
}

//function definition
/*
structure is a value type
objects are a reference type
this means that you can assign with structures
*/
StructStyle getStudentData() {
	StructStyle student;
	cout << "Enter first name: ";
	cin >> student.firstN;
	cout << "Enter last name: ";
	cin >> student.lastN;
	cout << "Enter the GPA achieved: ";
	cin >> student.gpa;

	return student;
}
//does output
void outputStArray(const StructStyle students[], const int SIZE){

	for (int i = 0; i < SIZE; i++) {
		cout << "First name: " << students[i].firstN << endl
			<< "Last name: " << students[i].lastN << endl
			<< "GPA: " << students[i].gpa << endl;
	}

		return;
}
//writes to file
void writeFile(const StructStyle students[], const int SIZE){
	StructStyle student;

	//ofstream object
	ofstream outfile("students.txt");//defines and opens
	//dont check if open
	for (int i = 0; i < SIZE; i++) {
		outfile << "First name: " << students[i].firstN << endl
			<< "Last name: " << students[i].lastN << endl
			<< "GPA: " << students[i].gpa << endl;
	}
	outfile.close();

	return;
}
