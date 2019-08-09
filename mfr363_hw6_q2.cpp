#include <iostream>
using namespace std;

void printShiftedTriangle(int n, int m, char symbol);
void printPineTree(int n, char symbol);

int main() {
	int triangleNum;
	int shiftNum;
	char treeChar;

	cout << "Question #2 Part a" << endl;
	cout << "Please pick a character to fill the tree: ";
	cin >> treeChar;

	cout << "Please pick the number of triangles: ";
	cin >> triangleNum;

	cout << "Please pick a number to shift the triangles: ";
	cin >> shiftNum;

	printShiftedTriangle(triangleNum, shiftNum,  treeChar);

	cout << "Question #2 Part b" << endl;
	cout << "Please pick a character to fill the tree: ";
	cin >> treeChar;

	cout << "Please pick the number of triangles: ";
	cin >> triangleNum;

	printPineTree(triangleNum, treeChar);


	return 0;
}

void printShiftedTriangle(int n, int m, char symbol){
	int numberOfSymbols;
	int numberOfSpaces;

	for (int triangleNumber = 1; triangleNumber <= n; ++triangleNumber) {

		// creating a single triangle
		for (int lineNumber = 0; lineNumber < (triangleNumber + 1); ++lineNumber) {

			if(lineNumber == 0){
				numberOfSymbols = 1;
				numberOfSpaces = n + m;
			} else{
				numberOfSymbols = numberOfSymbols + 2;
				numberOfSpaces = numberOfSpaces - 1;
			}

			for (int spaceNumber = 0; spaceNumber < numberOfSpaces; ++spaceNumber) {
				cout << " ";
			}

			// printing a single symbol
			for (int symbolNumber = 0; symbolNumber < numberOfSymbols; ++symbolNumber) {
				cout << symbol;
			}

			cout << endl;
		}
	}
}

void printPineTree(int n, char symbol) {
	int numberOfSymbols;
	int numberOfSpaces;

	for (int triangleNumber = 1; triangleNumber <= n; ++triangleNumber) {

		// creating a single triangle
		for (int lineNumber = 0; lineNumber < (triangleNumber + 1); ++lineNumber) {

			if(lineNumber == 0){
				numberOfSymbols = 1;
				numberOfSpaces = n;
			} else{
				numberOfSymbols = numberOfSymbols + 2;
				numberOfSpaces = numberOfSpaces - 1;
			}

			for (int spaceNumber = 0; spaceNumber < numberOfSpaces; ++spaceNumber) {
				cout << " ";
			}

			// printing a single symbol
			for (int symbolNumber = 0; symbolNumber < numberOfSymbols; ++symbolNumber) {
				cout << symbol;
			}

			cout << endl;
		}
	}
}