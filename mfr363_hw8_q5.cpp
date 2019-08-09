#include <iostream>
#include <array>
#include <string>
using namespace std;

int main(){
	string lastName, firstName, middleInitial;

	cout << "Please enter your first, middle, and last name separated by a space " << endl;
	cin >> firstName >> middleInitial >> lastName;

	cout << lastName << ", " << firstName << " " << middleInitial[0] << "." << endl;
	return 0;
}
