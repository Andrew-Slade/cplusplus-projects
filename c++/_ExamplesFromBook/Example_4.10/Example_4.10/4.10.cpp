#include <iostream>
#include <string>
using namespace std;

int main() {
	string origTweet;
	string origTweet2;
	string origTweet3;
	string origTweet4;
	string LOL = "LOL";
	string BFN = "BFN";
	string FTW = "FTW";
	string IRL = "IRL";
	

	cout << "Enter abbreviation from tweet: " << endl;
	getline(cin, origTweet);

	size_t found = origTweet.find(LOL);
	if (found != string::npos){
		cout << "LOL = laughing out loud" << endl;
	}
	size_t found2 = origTweet2.find(BFN);
	if (found2 != string::npos) {
		cout << "BFN = bye for now" << endl;
	}
	/*
	size_t found = origTweet3.find(FTW);
	if (found != string::npos) {
		cout << "FTW = for the win" << endl;
	}
	size_t found = origTweet4.find(IRL);
	if (found != string::npos) {
		cout << "IRL = in real life" << endl;
	}
	else {
		cout << "Sorry, don't know that one." << endl;
	}*/

	return 0;
}
