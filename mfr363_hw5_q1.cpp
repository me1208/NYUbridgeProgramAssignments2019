#include <iostream>
using namespace std;

int main() {
	int input;

	cout<<"Please enter a positive integer:"<<endl;
	cin>>input;

	// print out a nxn multiplication table
	for (int multiplier = 1; multiplier <= input; ++multiplier) {
		string tableLine = "";

		for (int colIteration = 1; colIteration <= input; ++colIteration) {
			// perform multiplication at index
			int multiplicationRes = multiplier*colIteration;
			cout<<multiplicationRes;

			// adjust spacing based on # of digits up to 10s place
			if(multiplicationRes < 10){
				cout<<"    ";
			}
			else if(multiplicationRes >= 100){
				cout<<"  ";
			} else{
				cout<<"   ";
			}
			// end line if last in column iteration
			if(colIteration == input){
				cout<<endl;
			}
		}
	}

	return 0;
}

