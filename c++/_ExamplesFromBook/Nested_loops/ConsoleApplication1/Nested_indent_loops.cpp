#include <iostream>
using namespace std;

int main() {
	int userNum = 0;
	int i = 0;
	int j = 0;


	while (j <= userNum) {
		for (i = 0; i < j; i++) {
			cout << " ";
		}
		cout << j << endl;
		j++;
	}

	return 0;
} //nested indent loops