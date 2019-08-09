#include <iostream>
using namespace std;

int fib(int n);

int main() {
	long int fibNumber = 0;
	int input;

	cout << "Please enter a positive integer: ";
	cin >> input;

	fibNumber = fib(input);

	cout << fibNumber << endl;
	return 0;
}

int fib(int n){
	double f1 = 0;
	double f2 = 1;
	double fn = 0;

	for (int sequence = 1; sequence < n; ++sequence) {

		fn = f1 + f2;
		f1 = f2;
		f2 = fn;
	}

	return fn;
}