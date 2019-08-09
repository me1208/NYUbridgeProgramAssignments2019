#include <iostream>
using namespace std;

int main() {
    long int nDecimal;
    long int nDecimalRemainder;
    long int counter = 1;
    long int nMod2;
    string nBinary;

    cout<<"Enter decimal number:" <<endl;
    cin>> nDecimal;

    nDecimalRemainder = nDecimal;

    while(counter <= nDecimalRemainder){
        // find mod value of the decimal # for binary representation
        nMod2 = nDecimalRemainder % 2;
        // reduce current value for next iteration
        nDecimalRemainder = nDecimalRemainder / 2;

        if(nMod2 == 0){
            nBinary = "0" + nBinary;
        } else if(nMod2 == 1){
            nBinary = "1" + nBinary;
        }
    }

    cout<<"The binary representation of "<<nDecimal<<" is "<<nBinary<<endl;

    return 0;
}
