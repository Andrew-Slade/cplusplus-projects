#include <iostream>
using namespace std;
//prototypes
int searchList(float list[], int numElems, float value);
//**********

int main() {
	float flValues[] = { 6.5, 89.2, 78.3, 1, 3 };
	int position;
	float searchVal;
	cout << "Please enter a number to search for: ";
	cin >> searchVal;

	position = searchList(flValues, 5, searchVal);
	if (position == -1) {
		cout << searchVal << " is not in the array." << endl;
	}
	else {
		cout << searchVal << " is at position " << position + 1 << " in the array." << endl;
	}

	return 0;
}

int searchList(float list[], int numElems, float value){
		int index = 0;  // Used as a subscript to search array 
		int position = -1; // To record position of search value 
		bool found = false; // Flag to indicate if the value was found
		while (index < numElems && !found) {
			if (list[index] == value)  // If the value is found 
			{	found = true;   // Set the flag 
				position = index; // Record the value's subscript 
			}
		index++; // Go to the next element
		} 
	return position;  // Return the position, or -1
}

void sortArray(int array[], int elems) {
	bool swap; int temp;
	do {
		swap = false; 
		for (int count = 0; count < (elems - 1); count++){
			if (array[count] > array[count + 1]) {
				temp = array[count];
				array[count] = array[count + 1];
				array[count + 1] = temp; swap = true;
			} 
		}
	} while (swap);
}