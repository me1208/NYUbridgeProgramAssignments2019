/*
Melissa Frendo-Rosso
Net ID: mfr363
*/

#include <iostream>
using namespace std;

int main() {
	char inLetter;
	const char LOWERCASEA = 'a';
	int rowsInTriangle;

	cout << "Please enter a lower-case letter:" << endl;
	cin >> inLetter;

	rowsInTriangle = (int)(inLetter - LOWERCASEA);
	int charsInLastRow = (rowsInTriangle*2) - 1;
	int numberOfCharsInRow = 1;

	for (char currentChar = LOWERCASEA; currentChar <= inLetter; ++currentChar)
	{
		for (int counter = 0; counter < charsInLastRow; ++counter) {
			cout << " ";
		}

		for (int counter = 0; counter < numberOfCharsInRow; ++counter) {
			cout << currentChar;
		}

		cout << endl;
		numberOfCharsInRow = numberOfCharsInRow + 2;
		charsInLastRow = charsInLastRow - 1;
	}

	return 0;
}