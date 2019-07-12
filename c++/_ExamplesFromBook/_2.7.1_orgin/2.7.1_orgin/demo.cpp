#include <iostream>
using namespace std;

int main() {
	const double HOMEWORK_MAX = 80.0;
	const double MIDTERM_MAX = 40.0;
	const double FINAL_MAX = 70.0;
	const double HOMEWORK_WEIGHT = 0.20; // 20%
	const double MIDTERM_WEIGHT = 0.30;
	const double FINAL_WEIGHT = 0.50;

	double homeworkScore = 0.0;
	double midtermScore = 0.0;
	double finalScore = 0.0;
	double coursePercentage = 0.0;

	cout << "Enter homework score:" << endl;
	cin >> homeworkScore;

	cout << "Enter midterm exam score:" << endl;
	cin >> midtermScore;

	cout << "Enter final exam score: " << endl;
	cin >> finalScore;

	coursePercentage = ((homeworkScore / HOMEWORK_MAX) * HOMEWORK_WEIGHT)
		+ 0.0  // FIXME for midterm
		+ 0.0; // FIXME for final 
	coursePercentage = coursePercentage * 100; // Convert fraction to %

	cout << endl << "Your course percentage (FIXME): ";
	cout << coursePercentage << endl;

	return 0;
}
