/*
Melissa Frendo-Rosso
Net ID: mfr363
*/

#include <iostream>
using namespace std;

int main() {

	int courseNumber = 1;
	string letterGrade = "";
	double totalGPA = 0;
	double totalRawGradePoints = 0;
	double numberOfCourses = 0;
	double gpaGrade = 0;
	double totalCredits = 0;

	//INPUTS:
	double numberOfCredits = 1;
	double pointGrade;

	while (numberOfCredits != 0) {
		gpaGrade = 0;

		cout << "Enter number of credits (or 0 when done): ";
		cin >> numberOfCredits;

		if(numberOfCredits != 0) {
			cout << "Enter your point grade: ";
			cin >> pointGrade;

			if (pointGrade >= 90) {
				letterGrade = "A";
				gpaGrade = 4.0;
			} else if (pointGrade < 90 && pointGrade >= 80) {
				letterGrade = "B";
				gpaGrade = 3.0;
			} else if (pointGrade < 80 && pointGrade >= 70) {
				letterGrade = "C";
				gpaGrade = 2.0;
			} else if (pointGrade < 70 && pointGrade >= 60) {
				letterGrade = "D";
				gpaGrade = 1.0;
			} else {
				letterGrade = "F";
				gpaGrade = 0.0;
			}

			cout << "Your letter grade for course #" << courseNumber << " is " << letterGrade << endl << endl;

			double courseGrade = gpaGrade * numberOfCredits;
			totalRawGradePoints = totalRawGradePoints + courseGrade;
			numberOfCourses = numberOfCourses + 1;
			totalCredits = totalCredits + numberOfCredits;
			courseNumber = courseNumber + 1;
		}
	}

	totalGPA = totalRawGradePoints/totalCredits;
	cout << "Your GPA is " << totalGPA << endl;

	return 0;
}