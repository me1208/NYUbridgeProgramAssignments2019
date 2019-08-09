#include <iostream>
#include <cmath>
using namespace std;

// global vars/function declarations
int outCountDivs = 0, outSumDivs = 0;
void analyzeDividors(int num, int& outCountDivs, int& outSumDivs);
bool isPerfect(int num);
bool isAmicable(int zNum, int zSumDivs);

int main() {
	int m;

	
	cout << "Please chose a positive integer greater than or equal to 2: " << endl;
	cin >> m;
	cout << endl;

	for (int i = 2; i < m; ++i) {

		//print perfect numbers that are between 2 and M
		if(isPerfect(i)){
			cout << i << " is a perfect number in range of [2, " << m << "]" << endl;
		}

		// print amicable numbers between 2 and M
		if(i < outSumDivs) {
			int inSumDivs =  outSumDivs;
			if(isAmicable(i, inSumDivs)){
			cout << "(" << i << ", " << inSumDivs << ") is an amicable pair in range of [2, " << m << "]" << endl;
			}
		}

		// clear out global variable for next iteration
		outSumDivs = 0;
	}

	return 0;
}

bool isPerfect(int num){
	bool isNumPerfect;

	analyzeDividors(num, outCountDivs, outSumDivs);

	if(outSumDivs == num){
		isNumPerfect = true;
	} else{
		isNumPerfect = false;
	}

	return isNumPerfect;
}

bool isAmicable(int zNum, int zSumDivs){
	bool isAmicable;

	analyzeDividors(zSumDivs, outCountDivs, outSumDivs);

	if(zNum == outSumDivs){
		isAmicable = true;
	} else {
		isAmicable = false;
	}
	return isAmicable;
}


void analyzeDividors(int num, int& outCountDivs, int& outSumDivs){
	int i;
	outSumDivs = 0;
	outCountDivs = 0;
	
	for (i = 1; i <= sqrt(num); ++i) {
		if(num % i == 0){
			outSumDivs += i;
			outCountDivs += 1;
			if((num/i) != num){
				outSumDivs += (num/i);
				outCountDivs += 1;
			}
		}
	}

}