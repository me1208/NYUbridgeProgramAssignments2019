#include <iostream>
#include <cmath>
using namespace std;

void printDivisors(int num);

int main() {
	int input;

	cout << "Please enter a positive integer >= 2: ";
	cin >> input;
	printDivisors(input);

	return 0;
}

void printDivisors(int num){
	int i;

	for (i = 1; i < sqrt(num); ++i) {
		if(num % i == 0){
			cout << i << " ";
		}
	}

	while (i > 1){
		if (num % i == 0){
			cout << num/i << " ";
		}

		i = i - 1;
	}
}