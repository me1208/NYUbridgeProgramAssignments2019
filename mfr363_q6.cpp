//
// Created by Melissa Frendo-Rosso on 2019-06-20. MFR363
//

#include <iostream>
using namespace std;

// add 2 then times 2
bool is_sum_prod_sequence(int* seq, int n){
	//base case
	if(n == 1){
		return true;
	}

	if(n%2 == 0){
		if(seq[n - 1]*2 == seq[n]){
			return is_sum_prod_sequence(seq, n - 1);
		} else{
			return false;
		}
	} else{
        // needs to be added 2
        if(seq[n - 1] + 2 == seq[n]){
	       return is_sum_prod_sequence(seq, n - 1);
        } else{
        	return false;
        }
	}

}



int main(){
	int seq[6] = {4, 6, 12, 14, 28, 30};
	bool isTrue = is_sum_prod_sequence(seq, 6);
	cout << isTrue;
	return 0;
}