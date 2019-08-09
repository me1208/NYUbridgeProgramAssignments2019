//
// Melissa Frendo-Rosso  MFR363
//

#include <iostream>
using namespace std;


// part a
void makeCommonsArray(int* srtArr1, int n1, int* srtArr2, int n2, int** outCommonsArr, int* outN){
	// show the amount that occur in both arrays
	*outN = 0;
	*outCommonsArr = new int[*outN];
	for (int i = 0; i < n1; ++i) {
		for (int j = 0; j < n2; ++j) {
			if(srtArr2[j] == srtArr1[i]){
				// IF I had time I would create a temp array and use it in palce of outCommonsArr and then equare
				// outCommonsArr to temp array and then delete the temp array so it would not create any errors.
				*outCommonsArr[*outN++] = srtArr1[i];
			}
		}
	}
}

void printArray(int arr[], int arrSize){
	for(int i = 0; i < arrSize; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}
// part b
int main(){
	int srtArr1[5] = {1, 2, 3, 5, 7};
	int srtArr2[5] = {2, 5, 6, 7, 9};
	int* commonsArr;
	int commonsArrSize;
	makeCommonsArray(srtArr1, 5, srtArr2, 5, &commonsArr, &commonsArrSize);

	cout<<"srtArr1: ";
	 printArray(srtArr1, 5);

	 cout<<"srtArr2: ";
	printArray(srtArr2, 5);

	cout<<"commonsArr: ";
	printArray(commonsArr, commonsArrSize);

	delete []commonsArr;
	return 0;
}

