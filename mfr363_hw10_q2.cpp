#include <iostream>
#include <string>
#include <array>
#include <vector>
using namespace std;

int* findMissing(int arr[], int n, int& resArrSize);
void printMissingNumArry(int arr[], int arrSize);

int main(){

	int arr[6]={3, 1, 3, 0, 6, 4};
	int n = 6;
	int resArrSize = 0;
	
	int *missingNums = findMissing(arr, n, resArrSize);
	printMissingNumArry(missingNums, resArrSize);

	return 0;
}

int* findMissing(int arr[], int n, int& resArrSize){
	int *missingNumArry = new int[n];
	resArrSize = 0;
	int *tempArry= new int[n] {0};

	//Look to see if value exists in array and estblsh 0 false, 1 true
	for (int i = 0; i < n; ++i) {
		tempArry[arr[i]] = 1;
	}

	for (int j = 0; j < n; ++j) {
		if(tempArry[j] == 0){
			missingNumArry[resArrSize++] = j;
		}
	}

	return missingNumArry;
}

void printMissingNumArry(int arr[], int arrSize){
	cout << "( ";
	for (int i = 0; i < arrSize; i++) {
		cout << arr[i] << ' ';
	}
	cout << ")";
}