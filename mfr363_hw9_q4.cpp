#include <iostream>
#include <array>
using namespace std;

void oddsKeepEvensFlip(int arr[], int arrSize);
void printArry(int arr[], int arrSize);

int main(){

	int arr[5] = {33, 6, 4, 1, 50};
	int arrSize = 5;

	cout << "Test case #1 array size 5, arr = {33, 6, 4, 1, 50}. oddsKeepEvensFlip result:" << endl;
	oddsKeepEvensFlip(*&arr, arrSize);
	printArry(arr, arrSize);

	int arr2[6] = {33, 6, 4, 1, 50, 20};
	int arrSize2 = 6;

	cout << "Test case #2 array size 6, arr = {33, 6, 4, 1, 50, 20}. oddsKeepEvensFlip result:" << endl;
	oddsKeepEvensFlip(*&arr2, arrSize2);
	printArry(arr2, arrSize2);
	return 0;
}

void oddsKeepEvensFlip(int arr[], int arrSize){
	int *tempArry = new int[arrSize];

	//This for loop adds the odd numbers dirst in their original order to the temp array
	int ind = 0;
	for (int i = 0; i < arrSize; i++) {
		if(arr[i] % 2 != 0){
			tempArry[ind++] = arr[i];
		}
	}
	// This loop will add even numbers in a reversed order to the array
	for (int i = arrSize - 1; i >= 0; i--) {
		if(arr[i] % 2 == 0){
			tempArry[ind++] = arr[i];
		}
	}
	//Final loop to add back all the values to the original array
	for (int i = 0; i <= arrSize; i++) {
		arr[i] = tempArry[i];
	}

	delete tempArry;
}

void printArry(int arr[], int arrSize){

	for (int i = 0; i < arrSize; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;
}