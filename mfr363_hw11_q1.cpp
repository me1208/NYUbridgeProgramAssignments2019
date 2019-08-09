#include <iostream>

using namespace std;

void printTriangle(int n);
void printOpositeTriangles(int n);
void printRuler(int n);

int main() {

	cout << "Question 1. Part 1: printTriangle()" << endl;
	printTriangle(4);

	cout << "\nQuestion 1. Part 2: printOpositeTriangles()" << endl;
	printOpositeTriangles(4);

	cout << "\nQuestion 1. Part 3: printRuler()" << endl;
	printRuler(4);

	return 0;
}

void printTriangle(int n){

	if(n == 1){
		cout << "*" << endl;
	} else if (n > 0){

		printTriangle(n - 1);

		// recursive behavior for triangle
		for (int i = 0; i < n; ++i) {
			cout << "*";
		}
		cout << endl;
	}
}

void printOpositeTriangles(int n){

	if(n == 1){
		cout << "*" << endl;
		cout << "*" << endl;
	} else if (n > 0){
		// recursive behavior for 1st triagnle
		for (int i = 0; i < n; ++i) {
			cout << "*";
		}
		cout << endl;

		printOpositeTriangles(n - 1);

		// recursive behavior for 2nd triangle
		for (int i = 0; i < n; ++i) {
				cout << "*";
		}
		cout << endl;
	}
}

void printRuler(int n){

	if(n == 1){
		for (int i = 0; i < n; ++i) {
			cout << "-";
		}
		cout << endl;
	} else{

		printRuler(n - 1);

		for (int i = 0; i < n; ++i) {
			cout << "-";
		}

		cout << endl;

		printRuler(n - 1);

	}

}
