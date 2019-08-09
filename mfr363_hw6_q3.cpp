#include <iostream>
using namespace std;

double eApprox(int n);

int main() {
	double outPut = 0;
	int input;

	cout << "Please enter a positive integer: ";
	cin >> input;

	outPut = eApprox(input);
	cout << outPut << endl;

	return 0;
}

double eApprox(int n){
	double e = 1;
	double factorial = 1;

	for (int i = 1; i <= n; ++i) {
		factorial *= i;
		e += (1 / factorial);
	}

	return e;
}