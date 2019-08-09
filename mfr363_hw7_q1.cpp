#include <iostream>
using namespace std;

int printMonthCalender(int numOfDays, int startingDay);
bool leapYearChecker(int year);
void printYearCalender(int year, int startingDay);

int main() {
	int year, startingDay;

	cout << "Please chose a year for your calendar: " << endl;
	cin >> year;

	cout << "Please enter a number (1 - 7) corresponding to the starting day of your calendar"
		 " (1 for Monday, 2 for Tuesday, 3 for Wednesday, etc.): " << endl;
	cin >> startingDay;
	cout << endl;

	printYearCalender(year, startingDay);

	return 0;
}

int printMonthCalender(int numOfDays, int startingDay){
	int currentDay = startingDay;

	cout << "Mon    Tue    Wed    Thr    Fri    Sat    Sun" << endl;

	for (int printedTabNo = 1; printedTabNo < startingDay; ++printedTabNo) {
		cout <<  "       ";
	}

	for (int printedDayNo = 1; printedDayNo <= numOfDays; ++printedDayNo) {
		cout << printedDayNo;

		if(printedDayNo <= 9){
			cout << "      ";
		} else{
			cout << "     ";
		}

		if(currentDay / 7 == 1){
			cout << endl;
			currentDay = 1;
		} else{
			currentDay += 1;
		}
	}

	cout << endl;

	return currentDay;
}

bool leapYearChecker(int year){
	bool isLeapYear;

	if(year % 4 == 0 &&
		(year % 100 != 0
		|| year % 400)){
		isLeapYear = true;
	} else{
		isLeapYear = false;
	}

	return isLeapYear;
}

void printYearCalender(int year, int startingDay){
	int numOfDays = 0;
	string month = "";

	bool isLeapYear = leapYearChecker(year);

	for (int currentMonth = 1; currentMonth <= 12; ++currentMonth) {

		switch (currentMonth) {
			case 1:
				month = "January";
				numOfDays = 31;
				break;
			case 2:
				month = "February";
				if (isLeapYear) {
					numOfDays = 29;
				} else {
					numOfDays = 28;
				}
				break;
			case 3:
				month = "March";
				numOfDays = 31;
				break;
			case 4:
				month = "April";
				numOfDays = 30;
				break;
			case 5:
				month = "May";
				numOfDays = 31;
				break;
			case 6:
				month = "June";
				numOfDays = 30;
				break;
			case 7:
				month = "July";
				numOfDays = 31;
				break;
			case 8:
				month = "August";
				numOfDays = 31;
				break;
			case 9:
				month = "September";
				numOfDays = 30;
				break;
			case 10:
				month = "October";
				numOfDays = 31;
				break;
			case 11:
				month = "November";
				numOfDays = 30;
				break;
			case 12:
				month = "December";
				numOfDays = 31;
				break;

		}

		cout << month << " " << year << endl;
		int lastDay = printMonthCalender(numOfDays, startingDay);
		startingDay = lastDay;
		cout << endl;
	}
}