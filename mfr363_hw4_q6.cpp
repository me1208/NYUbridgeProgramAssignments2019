#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int input;
    int numberOfEvenDigits;
    int numberOfOddDigits;

    cout<<"Please enter a positive integer:";
    cin>> input;

    for(int counter = 1; counter <= input; counter++){
        // init values for the current loop
        int nextDecimalPlace = counter;
        numberOfEvenDigits = 0;
        numberOfOddDigits = 0;
        // find if number in the current decimal place has even > odd digits
        while(nextDecimalPlace > 0){
            // use mod 2 to find if a digit is even or odd
            int nMod2 = nextDecimalPlace % 2;

            if(nMod2 == 0){
                numberOfEvenDigits = 1 + numberOfEvenDigits;

            } else if(nMod2 == 1){
                numberOfOddDigits = 1 + numberOfOddDigits;
            }

            nextDecimalPlace = nextDecimalPlace / 10;

        }

        if(numberOfEvenDigits > numberOfOddDigits){
            cout<<counter<<endl;
        }
    }

    return 0;
}
