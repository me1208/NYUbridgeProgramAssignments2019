#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& v){
	for (int i = 0; i < v.size(); i++){
		int indexOfLowest = i;
		for (int j = i + 1; j < v.size(); j++)
			if (v[j] < v[indexOfLowest])
				indexOfLowest = j;
		int temp = v[i];
		v[i] = v[indexOfLowest];
		v[indexOfLowest] = temp;
	}
}

void quickSort(vector<int>& v, int left, int right){
	if(left + 10 > right){
		selectionSort(v);
		return;
	}

	int middle = (left + right)/2; // find the middle index

	// Median of three partition so our pivot value isn't skewed one way
	if(v[middle] < v[left]){
		swap(v[middle], v[left]);
	}
	if(v[right] < v[left]){
		swap(v[right], v[left]);
	}
	if(v[right] < v[middle]){
		swap(v[middle], v[right]);
	}

	int pivot = v[middle];
	swap(v[middle], v[right - 1]);

	int i = left;
	int j = right - 1;

	for(;;){
		while(v[++i] < pivot){} // find value on the left that belongs to the right
		while(pivot < v[--j]) {} // find a value on the right that belongs to the left

		if(i < j){
			swap(v[i], v[j]); // swap the values to the right side
		} else{
			break;
		}
	}
	swap(v[i], v[right - 1]);

	quickSort(v, left, i - 1);
	quickSort(v, i + 1, right);

}

vector<int> quickSort(vector<int>& v) { // driver func
	vector<int> vMinMax;
	vMinMax.resize(2);

	if(v.size() < 3){ // base case - not many items and quick to determine result
		if(v[0] <= v[1]){
			vMinMax[0] = v[0];
			vMinMax[1] = v[1];
		} else if(v[1] < v[0]){
			vMinMax[0] = v[1];
			vMinMax[1] = v[0];
		}
	} else{
		quickSort(v, v[0], v[(v.size() - 1)]);
		vMinMax[0] = v[0];
		vMinMax[1] = v[v.size() - 1];
	}

	return vMinMax;
}

int main() {
	cout << "Please enter your vector by typing a number and clicking enter; once finished enter the word done and press enter." << endl;
	int input;
	vector<int> inputVect;
	while (cin >> input){
		inputVect.push_back(input);
	}

	vector <int> outputVect = quickSort(inputVect);
	cout << "Minimum value of the given vector is: " << outputVect[0]  << endl;
	cout << "Maximum value of the given vector is: " << outputVect[1]  << endl;
	return 0;
}