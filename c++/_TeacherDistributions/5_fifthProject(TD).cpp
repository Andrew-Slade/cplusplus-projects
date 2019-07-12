//doing decisions

#include <iostream>
using namespace std;
//prototype, declares to the compiler that there
//is a function definition later in the file
void playWithBool();

//function definition without prototype
void playWithSwitch(){
	//switch works with integrals
	char ch;
	int option;
	
	cout << "Enter a, b, c or d: ";
	cin >> ch;
	
	//start the decision structure
	switch(ch){
		//notice the character is in single quotes
		// compares value in ch with the cases ch == 'a'
		case 'a': cout << "You selected a\n";
			break;
		case 'b': cout << "You selected b\n";
			break;
		case 'c': cout << "You selected c\n";
			break;
		case 'd': cout << "You selected d\n";
			break;
		default: cout << "Please enter a, b, c or d";
	}
	
	//twelve days of chistmas 
	cout << "Which day are you buying: ";
	cin >> option;
	
	switch(option){
		case 5: cout << "five golden rings\n";
				//mens or womens
				int size;
				cout << "do you want large(3) or small rings(2): ";
				cin >> size;
				//3 large
				//2 is smaller 
				if(size == 3)
					cout << "   That is a large size\n";
				else
					cout << "   That is a small size\n";
		case 4: cout <<"four mocking birds" << endl;
		case 3:	cout << "three French hens" << endl;
		case 2: cout << "two turtle doves" << endl;
		case 1: cout << "a partridge in a pear tree\n" << endl;
			break;
		default: cout << "I haven't programmed that yet\n";
	}
}


int main()
{
	//starts processing
	//call on the function(s)
	//playWithBool(); //notice no void
	
	playWithSwitch();
	
	return 0;
}

//new data type void - no return
//function header, void return nothing, () get nothing
void playWithBool(){ 
	bool good = false;
	int x = 5;
	cout << "output boolean good: " << good << endl;
	
	if(x != 0){
		good = true;
	}
	
	cout << "output after if: " << good << endl;
	
	cout << "enter 1 for true , 0 for false: ";
	cin >> x;
	
	good = ( x != 0 );
	
	if(good)
		cout << "good holds true\n";
	else
		cout << "good holds false\n";

}  //end the function 








