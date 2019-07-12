//pointer fun

#include <iostream>
#include <fstream>
using namespace std;

void fillArray(float *array, const int SIZE);
void outputArray(float array[], const int SIZE);
int countNumbers();
void readfile(float *array, const int SIZE);

int main(){
	
	int x = 5;
	float y = 10;
	int *iptr;
	float *flptr;
	
	//assign an address to a pointer
	iptr = &x;
	cout << "The address of x is " << iptr << endl;
	cout << "The value stored at that address is " << *iptr << endl;
	cout << "5 squared is " << *iptr *  *iptr << endl;
	// pointers and arrays
	
	const int SIZE = 25;
	float array[SIZE];
	
	cout << "output just array " << array << endl;
	flptr = array; //memory address to memory address
	
	//call functions to fill and output array
	fillArray(array, SIZE);
	outputArray(flptr, SIZE);
	
	int count = countNumbers();
	
	cout << "You have " << count << " numbers in your file\n";
	//use new to create an array using flptr as the array name
	flptr = new float[count];
	readfile(flptr, count);
	
	outputArray(flptr, count);
	
	
	//release the memory back
	delete [] flptr;
	
		
	
	return 0;
}

void readfile(float *array, const int SIZE){
	ifstream infile("numbers.txt");
	int index = 0;
	if(infile.good()){
		infile >> array[index];
		index++;
		while( !infile.eof() && index < SIZE){
			infile >> array[index];
			index++;
		}
		
		infile.close();	
	}
	else
	   cout << "No file opened\n";
}

               //pointer notation
void fillArray(float *array, const int SIZE){
	
	for(int i= 0; i<SIZE; i++){
		array[i] = (i + 1) * 2;
	}
}

                //array notation
void outputArray(float array[], const int SIZE){
	for(int i = 0; i<SIZE; i++){
		cout << array[i] << "  ";
	}
	
}

int countNumbers(){
	//include fstream
	ifstream infile("numbers.txt");
	//count the numbers in the file
	int counter = 0;
	float x;
	
	if(infile.good()){
		//loop through the number by read one by one
		//add 1 to counter for each read
		infile >> x;
		while(! infile.eof()){
			counter++;
			infile >> x;
		}
		
		infile.close();
	}
	else
	   cout << "file not found\n";
	   
	return counter;
	
}







