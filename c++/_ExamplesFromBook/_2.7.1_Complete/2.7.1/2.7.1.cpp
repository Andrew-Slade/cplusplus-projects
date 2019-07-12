#include <iostream>
using namespace std;

int main() {
	const double QUIZ_MAX = 20.0;
	const double HOMEWORK_MAX = 80.0;
	const double MIDTERM_MAX = 40.0;
	const double FINAL_MAX = 70.0;

	const double QUIZ_WEIGHT = 0.15;
	const double HOMEWORK_WEIGHT = 0.10; // 20%
	const double MIDTERM_WEIGHT = 0.30;
	const double FINAL_WEIGHT = 0.45;

	double quizScore = 0.0;
	double homeworkScore = 0.0;
	double midtermScore = 0.0;
	double finalScore = 0.0;

	double coursePercentage = 0.0;

	double quizPart = 0.0;
	double homeworkPart = 0.0;
	double midPart = 0.0;
	double finalPart = 0.0;

	cout << "Enter homework score:" << endl;
	cin >> homeworkScore;

	cout << "Enter midterm exam score:" << endl;
	cin >> midtermScore;

	cout << "Enter final exam score: " << endl;
	cin >> finalScore;

	cout << "Enter quiz score:" << endl;
	cin >> quizScore;

	quizPart = ((quizScore / QUIZ_MAX) * QUIZ_WEIGHT);
	homeworkPart = ((homeworkScore / HOMEWORK_MAX) * HOMEWORK_WEIGHT);
	midPart = ((midtermScore / MIDTERM_MAX) * MIDTERM_WEIGHT);
	finalPart = ((finalScore / FINAL_MAX) * FINAL_WEIGHT);
	coursePercentage = finalPart + midPart + homeworkPart + quizPart;
	coursePercentage = coursePercentage * 100; // Convert fraction to %
	
	cout << endl << "Your course percentage is: ";
	cout << coursePercentage << endl;

	return 0;
}
