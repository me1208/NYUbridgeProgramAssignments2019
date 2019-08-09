#include <iostream>

using namespace std;

int jumpIt(int arr[], int arrSize, int start);

int main() {

	int arry [6] = { 0, 3, 80, 6, 57, 10};
	int start = 0;
	int result = jumpIt(arry, 6, start);
	cout << "The lowest cost to jump is " << result;

	return 0;
}

int jumpIt(int arr[], int arrSize, int start){

	if(arrSize - 1 == start){
		return arr[start];
	}

	int n = jumpIt(arr, arrSize, start + 1);

	if(start == arrSize - 2){
		return arr[0] + arr[arrSize - 1];
	} else if(n < jumpIt(arr, arrSize, start + 2)) {
		return n + arr[start];
	} else {
		return jumpIt(arr, arrSize, start + 2) + arr[start];
	}
}

