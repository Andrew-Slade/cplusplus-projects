#include <iostream>
#include <string>
using namespace std;

int main() {
	string simonPattern;
	string userPattern;
	int userScore = 0;
	int i = 0;

	userScore = 0;
	simonPattern = "RRGBRYYBGY";
	userPattern = "RRGBBRYBGY";

	for (; simonPattern[i] && userPattern[i]; i++){
		if (simonPattern[i] != userPattern[i]) {
		
		break;
	}
		userScore++;	
}
	cout << "userScore: " << userScore << endl;

	return 0;
}