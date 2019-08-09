#include <iostream>
#include <string>
#include <array>
#include <vector>
using namespace std;

int* main1(int &outputArryPtrSize);
vector<int> main2(int &outputVectorSize);
void printThisArry(int arr[], int arrSize);
void printThisVector(vector<int> arr, int arrSize);

int main(){
	int *outputArryPtr;
	vector<int> outputVector;
	int outputArryPtrSize, outputVectorSize;

	cout << "Testing Part 1: No Vector" << endl;
	outputArryPtr = main1(outputArryPtrSize);
	printThisArry(outputArryPtr, outputArryPtrSize);

	cout << "Testing Part 2: Using Vectors" << endl;
	outputVector = main2(outputVectorSize);
	printThisVector(outputVector, outputVectorSize);


	return 0;
}

int* main1(int &outputArryPtrSize){
	int *inputArr, *outputArr;
	int inputVal = 0, searchFor, resArrSize = 0;
	inputArr = new int[0];
	outputArr = new int[0];
	outputArryPtrSize = 0;

	cout << "Please enter a sequence of positive integers, each in a separate line.\n "
	        "End you input by typing -1." << endl;

	while(inputVal != -1){
		cin >> inputVal;

		if(inputVal != -1){
			int* temp;
			inputArr[resArrSize] = inputVal;
			resArrSize++;
			temp = new int[resArrSize];

			for (int i = 0; i < resArrSize; ++i) {
				temp[i] = inputArr[i];
			}

			delete(inputArr);
			inputArr = temp;
		}
	}
	cout << "Please enter a number you want to search." << endl;
	cin >> searchFor;

	for (int i = 0; i < resArrSize; ++i) {
		if(inputArr[i] == searchFor){
			outputArr[outputArryPtrSize] = i + 1;

			int* temp;
			outputArryPtrSize++;
			temp = new int[outputArryPtrSize];

			for (int i = 0; i < resArrSize; ++i) {
				temp[i] = outputArr[i];
			}
			delete(outputArr);
			outputArr = temp;

		}
	}

	return outputArr;
}

vector<int> main2(int &outputVectorSize){
	vector<int> inputArr, outputArr;
	int inputVal, searchFor;

	cout << "Please enter a sequence of positive integers, each in a separate line.\n "
	        "End you input by typing -1." << endl;
	while(inputVal != -1){
		cin >> inputVal;
		if(inputVal != -1){
			inputArr.push_back(inputVal);
		}
	}
	cout << "Please enter a number you want to search." << endl;
	cin >> searchFor;

	for (int i = 0; i < (int)inputArr.size(); ++i) {
		if(inputArr[i] == searchFor){
			outputArr.push_back(i + 1);
		}
	}

	outputVectorSize = (int)outputArr.size();
	return outputArr;
}

void printThisArry(int arr[], int arrSize){
	cout << "( ";
	for (int i = 0; i < arrSize; i++) {
		cout << arr[i] << ' ';
	}
	cout << ")" << endl;
}

void printThisVector(vector<int> arr, int arrSize){
	cout << "( ";
	for (int i = 0; i < arrSize; i++) {
		cout << arr[i] << ' ';
	}
	cout << ")" << endl;
}