#include <iostream>
#include <array>
#include <string>
using namespace std;

void pinCompare(int enteredPin[], int randomNums[], const int actualPin[]);
void printArry(int arr[], int arrSize);
int charToIntArry(char inputChar);

int main(){
	int enteredPinToInt[5] = {};
	string enteredPinStrng = {};
	const int PIN[5] = {1, 2, 3, 4, 5};
	int randomNums[10] = {};

	// Generate random array of 1-3 for matching # 0-9
	srand (time(NULL));
	for (int i = 0; i < 10; ++i) {
		randomNums[i] = (rand() % 3) + 1;
	}

	// interact w/ user to retrieve entered pin as string
	cout << "Please enter your PIN according to the following mapping: \n PIN: \t0 1 2 3 4 5 6 7 8 9 \n NUM: \t";
	printArry(randomNums, 10);
	cin >> enteredPinStrng;

	// convert string to array
	for (int j = 0; j < 5; ++j) {
		enteredPinToInt[j] = charToIntArry(enteredPinStrng[j]);
	}

	// see if pin was accurately entered
	pinCompare(enteredPinToInt, randomNums, PIN);

	return 0;
}

void printArry(int arr[], int arrSize){

	for (int i = 0; i < arrSize; i++) {
		cout<<arr[i]<<' ';
	}
	cout<<endl;
}

void pinCompare(int enteredPin[], int randomNums[], const int actualPin[]){
	bool pinsMatch = true;

	for (int i = 0; i < 5; ++i) {
		int compare = enteredPin[i];
		int iEnteredPin = randomNums[actualPin[i]];
		if(compare != iEnteredPin){
			pinsMatch = false;
		}
	}

	if(pinsMatch){
		cout << "Your PIN is correct" << endl;
	} else{
		cout << "Your PIN is not correct" << endl;
	}
}

int charToIntArry(char inputChar){

		switch(inputChar){
			case '1':
				return 1;
			case '2':
				return 2;
			case '3':
				return 3;
			case '4':
				return 4;
			case '5':
				return 5;
			case '6':
				return 6;
			case '7':
				return 7;
			case '8':
				return 8;
			case '9':
				return 9;
			case '0':
				return 0;
			default:
				// if entry doesn't match 0-9 the pin isn't correct,
				// throw a value that will reflect incorrect PIN
				return 20;
		}
}