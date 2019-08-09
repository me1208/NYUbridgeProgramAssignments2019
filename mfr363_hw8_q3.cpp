#include <iostream>
#include <array>
#include <string>
using namespace std;

void reverseArray(int arr[], int arrSize);
void removeOdd(int arr[], int& arrSize);
void splitParity(int arr[], int arrSize);

// use the following to test code:
void printArray(int arr[], int arrSize);
int main() {
	int arr1[10] = {9, 2, 14, 12, -3};
	int arr1Size = 5;

	int arr2[10] = {21, 12, 6, 7, 14};
	int arr2Size = 5;

	int arr3[10] = {3, 6, 4, 1, 12};
	int arr3Size = 5;

	reverseArray(arr1, arr1Size);
	printArray(arr1, arr1Size);

	removeOdd(arr2, arr2Size);
	printArray(arr2, arr2Size);

	splitParity(arr3, arr3Size);
	printArray(arr3, arr3Size);

	return 0;
}
void printArray(int arr[], int arrSize){

	for (int i = 0; i < arrSize; i++) {
		cout<<arr[i]<<' ';
	}
	cout<<endl;
}

void reverseArray(int arr[], int arrSize){
	int ind = arrSize - 1;
	for (int i = 0; i < ind / 2; i++) {
		int switchWithVal = arr[ind - i];
		arr[ind - i] = arr[i];
		arr[i] = switchWithVal;
	}
}

void removeOdd(int arr[], int& arrSize){
	int ind = arrSize - 1;
	arrSize = 0;
	for (int i = 0; i <= ind; i++) {
		if(arr[i] % 2 == 0){
			arr[arrSize] = arr[i];
			arrSize += 1;
		}
	}
}

// odd nums first even last
void splitParity(int arr[], int arrSize){
	int ind = arrSize - 1;
	for (int i = 0; i <= ind; i++) {
		if(arr[i] % 2 != 0){
			int switchWithVal = arr[ind - i];
			arr[ind - i] = arr[i];
			arr[i] = switchWithVal;
		}
	}
}