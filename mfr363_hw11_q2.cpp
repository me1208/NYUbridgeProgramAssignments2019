#include <iostream>
#include <cmath>

using namespace std;

int sumOfSquares(int arr[], int arrSize);
bool isSorted(int arr[], int arrSize);

int main(){

	int arry [4] = { 2, -1, 3, 10};
	cout << "Question 2a. sumOfSquares() for { 2, -1, 3, 10}" << endl;
	int result = sumOfSquares(arry, 4);
	cout << result << endl;

	cout << "Question 2b. isSorted() for { 2, -1, 3, 10}" << endl;
	bool sortResult = isSorted(arry, 4);
	if(sortResult){
		cout << "The array is sorted in ascending order." << endl;
	} else{
		cout << "The array is not sorted in ascending order." << endl;
	}

	return 0;
}

int sumOfSquares(int arr[], int arrSize){
	if(arrSize == 1){
		return pow(arr[arrSize - 1], 2);
	} else{
		return pow(arr[arrSize - 1], 2) + sumOfSquares(arr, arrSize - 1);
	}
}

bool isSorted(int arr[], int arrSize){
	if(arrSize == 0){
		if(arr[arrSize + 1] >= arr[arrSize]){
			return true;
		} else{
			return false;
		}
	} else{

		if(arr[arrSize - 1] >= arr[arrSize - 2]){
			if(isSorted(arr, arrSize - 1)){
				return true;
			}
		} else{
			return false;
		}
	}
}