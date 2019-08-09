#include <iostream>
#include <array>
using namespace std;

int minInArray(int arr[], int arrSize);


int main(){
	int inputArray[20] = {0};

	cout << "Please enter 20 integers separated by a space:" << endl;
	for (int inputIteration = 0; inputIteration < 20; ++inputIteration) {
		 cin >> inputArray[inputIteration];
	}

	int minValue = minInArray(inputArray, 20);
	cout << "The minimum value is " << minValue << ", and it is located in the following indices: ";
	for (int i = 0; i <= 20; ++i) {
		if(inputArray[i] == minValue){
			cout<< i << " ";
		}
	}

	return 0;
}

// returns the minimum value in the array
int minInArray(int arr[], int arrSize){
	int currentMin = arr[0];

	for (int i = 0; i < arrSize; ++i) {
		if(currentMin > arr[i]){
			currentMin = (double)arr[i];
		}
	}

	return currentMin;
}