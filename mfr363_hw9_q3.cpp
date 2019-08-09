#include <iostream>
#include <array>
#include <string>
using namespace std;

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);
void getPosNums2(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);
int* getPosNums3(int* arr, int arrSize, int* outPosArrSizePtr);
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);

void print(int array[], int size);
int resizeArray(int currentArry[], int currentSize);

int main(){
	int testerarry[6] = {3, -1, -3, 0, 6, 4};
	int outPosArrSize = 0;
	int * outPosArrSizePtr = new int;
	int * outPosArr = new int;
	int * outPosArrPtr = new int;


	cout << "Testing: getPosNums1 with  arr=[3, -1, -3, 0, 6, 4]" << endl;
	int* newOutPutArry1 = getPosNums1(testerarry, 6, outPosArrSize);
	print(newOutPutArry1, outPosArrSize);

	// outpostarray address, outpostarray side, return array address
	cout << "Testing: getPosNums2 with  arr=[3, -1, -3, 0, 6, 4]" << endl;
	getPosNums2(testerarry, 6, outPosArr, outPosArrSize);
	print(outPosArr, outPosArrSize);

	// outpostarray address, outpostarray side, return array address
	cout << "Testing: getPosNums3 with  arr=[3, -1, -3, 0, 6, 4]" << endl;
	int* newOutPutArry3 = getPosNums3(testerarry, 6, &outPosArrSize);
	print(newOutPutArry3, outPosArrSize);

	delete newOutPutArry3;
	delete outPosArrSizePtr;

	cout << "Testing: getPosNums4 with  arr=[3, -1, -3, 0, 6, 4]" << endl;
	getPosNums4(testerarry, 6, &outPosArrPtr, *&outPosArrSizePtr);
	print(outPosArrPtr, *outPosArrSizePtr);

	return 0;
}

void print(int *array, int size){
	cout << "New output array address: " << array << ". New output array: (";
	for (int i = 0; i < size; ++i) {

		cout<< array[i] << " ";
	}
	cout << "). New array size: " << size << endl;
}

// returns the base address of the array (containing the positive numbers), and updates
//the output parameter outPosArrSize with the array’s logical size.
int* getPosNums1(int* arr, int arrSize, int& outPosArrSize){
	outPosArrSize = resizeArray(arr, arrSize);
	int *temp = new int[outPosArrSize];

	int iTemp = 0;
	for (int i = 0; i < sizeof(temp); ++i) {
		if(arr[i] > 0){
			temp[iTemp] = arr[i];
			iTemp += 1;
		}
	}

	arr = temp;
	return arr;
}

void getPosNums2(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize){
	outPosArr = new int[arrSize];
	outPosArr =	getPosNums1(arr, arrSize, outPosArrSize);
}

//returns the base address of the array (containing the positive numbers), and uses
//the pointer outPosArrSizePtr to update the array’s logical size.
int* getPosNums3(int* arr, int arrSize, int* outPosArrSizePtr){

	outPosArrSizePtr = new int;
	*outPosArrSizePtr = 0;
	for (int i = 0; i < arrSize; ++i) {
		if(arr[i] > 0){
			(*outPosArrSizePtr)++;
		}
	}

	int *temp3 = new int[(*outPosArrSizePtr)];

	int iTemp = 0;
	for (int i = 0; i < sizeof(temp3); ++i) {
		if(arr[i] > 0){
			temp3[iTemp] = arr[i];
			iTemp += 1;
		}
	}

	delete outPosArrSizePtr;
	return temp3;
}

//uses the pointer outPosArrPtr to update the base address of the array (containing
//the positive numbers), and the pointer outPosArrSizePtr to update the array’s logical size.
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr){

	outPosArrSizePtr = new int;
	*outPosArrSizePtr = 0;
	for (int i = 0; i < arrSize; ++i) {
		if(arr[i] > 0){
			(*outPosArrSizePtr)++;
		}
	}

	(*outPosArrPtr) = new int[(*outPosArrSizePtr)];


	int iTemp = 0;
	for (int i = 0; i < sizeof(*outPosArrPtr); ++i) {
		if(arr[i] > 0){
			(*outPosArrPtr)[iTemp] = arr[i];
			iTemp += 1;
		}
	}
}


int resizeArray(int currentArry[], int currentSize){

	int newSize = 0;
	for (int i = 0; i < currentSize; ++i) {
		if(currentArry[i] > 0){
			newSize += 1;
		}
	}

	return newSize;
}