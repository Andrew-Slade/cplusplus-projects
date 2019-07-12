#include <iostream>
#include <string>
using namespace std;
void printOutParameterVals(int f, float g, double h, string i);

int main() {
	int a = 42;
	float b = 6.1728;
	double c = 3.14159;
	string d = "hello";
	printOutParameterVals(a, b, c, d);

	return 0;
}

void printOutParameterVals(int k, float l, double m, string n){
	cout << k << l << m << n;
}
